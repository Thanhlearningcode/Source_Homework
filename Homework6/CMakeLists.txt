cmake_minimum_required(VERSION 3.8)
project(image_manager)

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -pthread")

# Tìm OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Tìm GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Thư mục chứa header và source
set(DIVISIBLE_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(DIVISION_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

# Tạo thư viện static
add_library(image STATIC src/image.cpp src/io_tools.cpp)

# Thêm include path vào thư viện
target_include_directories(image PUBLIC ${DIVISIBLE_INSTALL_INCLUDE_DIR})

# Liên kết OpenCV vào thư viện
target_link_libraries(image PUBLIC ${OpenCV_LIBS})

# Bật testing
enable_testing()

# Tạo file test
add_executable(Project_test tests/test_init.cpp)
target_link_libraries(Project_test GTest::GTest GTest::Main pthread image)

# Nếu tests có CMakeLists.txt riêng thì giữ add_subdirectory(tests)
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests/CMakeLists.txt)
    add_subdirectory(tests)
endif()
