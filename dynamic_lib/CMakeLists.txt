add_library(journal_dynamic_lib SHARED journal_dynamic_lib.cpp)
set_target_properties(journal_dynamic_lib PROPERTIES LIBRARY_OUTPUT_DIRECTORY
                     ${CMAKE_BINARY_DIR}/bin)