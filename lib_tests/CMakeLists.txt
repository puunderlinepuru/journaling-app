include(CTest)
enable_testing()

# STATIC LIBRARY TESTS
add_executable(StaticInitTest static_init_test.cpp)
target_link_libraries(StaticInitTest
                        journal_static_lib
                        )
add_test(NAME StaticInitializationTest 
        COMMAND StaticInitTest
        WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}"
        )


add_executable(StaticAccessLevelTest static_access_level_test.cpp)
target_link_libraries(StaticAccessLevelTest 
                        journal_static_lib
                        )
add_test(NAME StaticAccessLevelChangeTest 
        COMMAND StaticAccessLevelTest
        WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}"
        )


add_executable(StaticWriteTest static_write_test.cpp)
target_link_libraries(StaticWriteTest 
                        journal_static_lib
                        )
add_test(NAME StaticWriteTest 
        COMMAND StaticWriteTest
        WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}"
        )

        

# DYNAMIC LIBRARY TESTS
add_executable(DynamicInitTest dynamic_init_test.cpp)
target_link_libraries(DynamicInitTest
                        journal_dynamic_lib
                        )
add_test(NAME DynamicInitializationTest 
        COMMAND DynamicInitTest
        WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}"
        )


add_executable(DynamicAccessLevelTest dynamic_access_level_test.cpp)
target_link_libraries(DynamicAccessLevelTest 
                        journal_dynamic_lib
                        )
add_test(NAME DynamicAccessLevelChangeTest 
        COMMAND DynamicAccessLevelTest
        WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}"
        )


add_executable(DynamicWriteTest dynamic_write_test.cpp)
target_link_libraries(DynamicWriteTest 
                        journal_dynamic_lib
                        )
add_test(NAME DynamicWriteTest 
        COMMAND DynamicWriteTest
        WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")


