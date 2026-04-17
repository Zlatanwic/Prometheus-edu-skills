add_executable(test_wordfreq test_wordfreq.cpp)
target_link_libraries(test_wordfreq PRIVATE wordfreq_lib Catch2::Catch2WithMain)
add_test(NAME wordfreq_tests COMMAND test_wordfreq)
