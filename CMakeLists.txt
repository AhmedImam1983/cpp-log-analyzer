cmake_minimum_required(VERSION 3.20)

project(cpp-log-analyzer
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(log_analyzer_lib
    src/log_analyzer.cpp
)

target_include_directories(log_analyzer_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(log_analyzer_lib PRIVATE
    -Wall -Wextra -Wpedantic
)

add_executable(log_analyzer main.cpp)

target_link_libraries(log_analyzer PRIVATE log_analyzer_lib)

target_compile_options(log_analyzer PRIVATE
    -Wall -Wextra -Wpedantic
)

enable_testing()

add_executable(test_log_analyzer
    tests/test_log_analyzer.cpp
)

target_link_libraries(test_log_analyzer
    PRIVATE log_analyzer_lib
)

target_compile_options(test_log_analyzer PRIVATE
    -Wall -Wextra -Wpedantic
)

add_test(
    NAME LogAnalyzerTests
    COMMAND test_log_analyzer
)