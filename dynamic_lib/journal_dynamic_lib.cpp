#include <tuple>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "journal_dynamic_lib.h"

std::string AccessLevels[3] = {"low", "medium", "high"};
int defaultAccessLevel = 1;

namespace journal_dynamic
{
    std::string directoryPath = "";
    std::string journalName;
    std::ofstream journalFile;
    
    
    /* Initialize journal file */
    void init(std::string fileName = "journal.txt", int defaultLevel=1) {
        journalName = fileName;
        defaultAccessLevel = defaultLevel;
        journalFile = std::ofstream(directoryPath + journalName, std::ios::app);
        if (!journalFile) {
            std::cerr << "Error opening journal file: " << journalName << std::endl;
            return;
        }
        journalFile.close();
    }

    /* Change default access level */
    void change_access_level(int chosenAccessLevel = defaultAccessLevel) {
        defaultAccessLevel = chosenAccessLevel;
    }

    /* Write entry to journal file */
    void write_to_file(std::string entry, int chosenAccessLevel = defaultAccessLevel) {
        time_t timeStamp = time(0);
        std::ofstream journalFile(directoryPath + journalName, std::ios::app);
        if (!journalFile) {
            std::cerr << "Error opening journal file: " << journalName << std::endl;
            return;
        }

        journalFile << '#' << entry;
        journalFile << '#' << AccessLevels[chosenAccessLevel - 1] << std::endl;
        journalFile << '#' << ctime(&timeStamp) << std::endl;

        journalFile.close();
    }
}


