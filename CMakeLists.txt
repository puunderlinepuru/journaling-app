cmake_minimum_required(VERSION 3.10.0)
project(Journal VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_TESTING)

add_subdirectory(static_lib)
add_subdirectory(dynamic_lib)
add_subdirectory(lib_tests)

add_executable(JournalApp journal_app.cpp)

target_link_libraries(JournalApp 
                        journal_static_lib
                        journal_dynamic_lib
                        )
                        
target_include_directories(JournalApp PRIVATE
                            ${PROJECT_BINARY_DIR}
                            ${PROJECT_BINARY_DIR}/static_lib
                            ${PROJECT_BINARY_DIR}/dynamic_lib
                            ${PROJECT_BINARY_DIR}/lib_tests
                            )

include(CTest)
enable_testing()
