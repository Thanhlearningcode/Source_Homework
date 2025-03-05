cmake_minimum_required(VERSION 3.10)
project(named_vector)

set(CMAKE_CXX_STANDARD 17)

# Thêm thư mục header và src
include_directories(Inc Src)

# Thêm tất cả file nguồn
file(GLOB SOURCES Src/*.cpp)

# Thêm target executable
add_executable(named_vector ${SOURCES})

# Đánh dấu vector.tpp là file header, không biên dịch trực tiếp
set_source_files_properties(Src/vector.tpp PROPERTIES HEADER_FILE_ONLY TRUE)

