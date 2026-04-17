add_executable(test_parser test_parser.cpp)
target_link_libraries(test_parser PRIVATE csvstat_lib Catch2::Catch2WithMain)
add_test(NAME parser_tests COMMAND test_parser)

add_executable(test_stats test_stats.cpp)
target_link_libraries(test_stats PRIVATE csvstat_lib Catch2::Catch2WithMain)
add_test(NAME stats_tests COMMAND test_stats)
