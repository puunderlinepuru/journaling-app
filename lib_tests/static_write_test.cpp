#include "../static_lib/journal_static_lib.h"

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string AccessLevels[3] = {"low", "medium", "high"};

    remove("test_static_journal_write.txt");

    journal_static::init("test_static_journal_write.txt", 2);

    journal_static::write_to_file("This is a test entry with access level 1\n", 1);
    journal_static::write_to_file("This is a test entry with access level 2\n", 2);
    journal_static::write_to_file("This is a test entry with access level 3\n", 3);

    std::ifstream journalFile("test_static_journal_write.txt");

    for (int i = 1; i <= 3; i++)
    {
        std::string entry;
        if (std::getline(journalFile, entry, '#'));
        if (std::getline(journalFile, entry, '#'));
        if (entry != "This is a test entry with access level " + std::to_string(i) + "\n") 
        {
            std::cout << "Entry mismatch: " << entry << std::endl;
            std::cout << "Expected: " << "This is a test entry with access level " + std::to_string(i) + "\n" << std::endl;
            return 1;
        }
        if (std::getline(journalFile, entry, '#'));
        if (entry != AccessLevels[i - 1] + '\n') 
        {
            std::cout << "Entry mismatch: " << entry << std::endl;
            std::cout << "Expected: " << AccessLevels[i - 1] <<std::endl;
            return 1;
        }
    }
    
    
    return 0;
}
