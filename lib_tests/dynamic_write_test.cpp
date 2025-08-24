#include "../dynamic_lib/journal_dynamic_lib.h"

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string AccessLevels[3] = {"low", "medium", "high"};

    remove("test_dynamic_journal_write.txt");

    journal_dynamic::init("test_dynamic_journal_write.txt", 2);

    journal_dynamic::write_to_file("This is a test entry with access level 1\n", 1);
    journal_dynamic::write_to_file("This is a test entry with access level 2\n", 2);
    journal_dynamic::write_to_file("This is a test entry with access level 3\n", 3);

    std::ifstream journalFile("test_dynamic_journal_write.txt");

    std::string entry;
    for (int i = 1; i <= 3; i++)
    {
        
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
