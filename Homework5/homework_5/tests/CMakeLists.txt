cmake_minimum_required(VERSION 3.10)
project(ConvertDatasetTests)
find_package(OpenCV REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/homework_5)

include_directories(${OpenCV_INCLUDE_DIRS} /usr/include/opencv4)

# Find Catch2 testing framework
find_package(Catch2 REQUIRED)
include(CTest)
include(Catch)

# Include project source directory
# include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/source)

# Create internal shared library
add_library(sifts_internal SHARED sifts_internal.cpp)
target_link_libraries(sifts_internal ${OpenCV_LIBS})

# Define test binary
set(TEST_BINARY ${PROJECT_NAME}_test)
add_executable(${TEST_BINARY}
               test_serialize.cpp
               test_convert_dataset.cpp
               test_main.cpp)

# Link libraries
target_link_libraries(${TEST_BINARY}
                      convert_dataset
                      sifts_internal
                      Catch2::Catch2WithMain
                      stdc++fs)

# Discover tests
catch_discover_tests(${TEST_BINARY} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
