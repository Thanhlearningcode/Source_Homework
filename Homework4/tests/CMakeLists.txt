cmake_minimum_required(VERSION 3.19)
project(Homework4)

find_package(Catch2 REQUIRED)
include_directories(${Catch2_INCLUDE_DIRS})  # Đảm bảo CMake thấy Catch2

include(CTest)
include(Catch)

set(TEST_BINARY ${PROJECT_NAME}_test)
add_executable(${TEST_BINARY}
               test_named_vector.cpp
               test_ipb_algorithm.cpp
               test_main.cpp)

target_link_libraries(${TEST_BINARY} ipb_algorithm Catch2::Catch2)
catch_discover_tests(${TEST_BINARY})
