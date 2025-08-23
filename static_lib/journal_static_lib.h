#include <string>

#ifndef JOURNAL_STATIC_LIB_H
#define JOURNAL_STATIC_LIB_H

namespace journal_static
{
    void init(std::string filename, int defaultLevel);
    void change_access_level(int chosenAccessLevel);
    void write_to_file(std::string entry, int chosenAccessLevel);
}


#endif