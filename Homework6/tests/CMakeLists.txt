cmake_minimum_required(VERSION 3.10)
project(Homework6)

# Thêm đường dẫn thư mục chứa file header
include_directories(${CMAKE_SOURCE_DIR}/include)

# Tạo biến chứa danh sách file nguồn
set(SOURCES
    test_init.cpp
)

# Tạo file thực thi
add_executable(Project_test ${SOURCES})

# Liên kết thư viện nếu cần (ví dụ: pthread, OpenCV, GTest)
target_link_libraries(Project_test pthread gtest_main)
