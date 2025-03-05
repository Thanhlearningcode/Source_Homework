cmake_minimum_required(VERSION 3.10)
project(ImageBrowser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Thêm thư mục chứa file .hpp
include_directories(api)

# Tạo thư viện html_writer
add_library(html_writer api/html_writer.cpp)

# Tạo thư viện image_browser, cần link với html_writer
add_library(image_browser api/image_browser.cpp)
target_link_libraries(image_browser html_writer)

# Tạo chương trình chính
add_executable(main main.cpp)
target_link_libraries(main image_browser)

