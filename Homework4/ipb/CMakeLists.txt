cmake_minimum_required(VERSION 3.10)
project(ipb_project)

set(CMAKE_CXX_STANDARD 17)

# Thêm thư mục chứa file header
include_directories(Inc)

# Thêm tất cả các file nguồn
file(GLOB SOURCES Src/*.cpp)

# Tạo executable
add_executable(ipb_exec ${SOURCES})
