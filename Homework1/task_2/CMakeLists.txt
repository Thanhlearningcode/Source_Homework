cmake_minimum_required(VERSION 3.10)
project(ipb_arithmetic)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# ✅ Thêm thư mục include để trình biên dịch tìm thấy file header
include_directories(${CMAKE_SOURCE_DIR}/include)

# ✅ Thêm các file header vào target để đảm bảo chúng được sử dụng đúng
add_library(ipb_arithmetic STATIC 
    src/sum.cpp 
    src/subtract.cpp 
    include/ipb_arithmetic/sum.hpp 
    include/ipb_arithmetic/subtract.hpp
)

set_target_properties(ipb_arithmetic PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_executable(ipb_arithmetic_exec src/main.cpp)
target_link_libraries(ipb_arithmetic_exec PRIVATE ipb_arithmetic)
set_target_properties(ipb_arithmetic_exec PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)



