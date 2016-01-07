add_executable(test_garply test_garply.cc)
target_link_libraries(test_garply garply)
add_test(NAME test_garply COMMAND $<TARGET_FILE:test_garply>)
