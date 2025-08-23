include(CTest)
enable_testing()



add_test(NAME journal_exits_test
        COMMAND "${CMAKE_CURRENT_LIST_DIR}/script_test.sh" "../build/bin/journal.txt"
        WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}"
        )      

# file exists

# journal name test.txt with no access

# journal name test with no access

# journal name test with access 4

#journal name test with access 0

#journal name test with access 1

# too many arguments

#really long journal name with no access

#really long entry text

#no entry text
