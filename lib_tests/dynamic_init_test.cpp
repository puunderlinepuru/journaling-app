#include "../dynamic_lib/journal_dynamic_lib.h"
#include <iostream>


int main(int argc, char const *argv[])
{
    remove("test_dynamic_journal_initialization.txt");

    journal_dynamic::init("test_dynamic_journal_initialization.txt", 2);

    int return_code = system("./script_test.sh ../lib_tests/test_dynamic_journal_initialization.txt");
    return WEXITSTATUS(return_code);;
}
