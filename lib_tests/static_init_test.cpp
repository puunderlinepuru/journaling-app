#include "../static_lib/journal_static_lib.h"
#include <iostream>


int main(int argc, char const *argv[])
{
    remove("test_static_journal_initialization.txt");
    journal_static::init("test_static_journal_initialization.txt", 2);

    int return_code = system("./script_test.sh ../lib_tests/test_static_journal_initialization.txt");
    return WEXITSTATUS(return_code);;
}
