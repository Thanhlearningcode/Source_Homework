cmake_minimum_required(VERSION 3.10)
project(image_manager)

# Đặt chuẩn C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -pthread")

# Tìm OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Tìm GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Thư mục include và source
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

# Tạo thư viện tĩnh (image)
add_library(image STATIC
    ${SOURCE_DIR}/image.cpp
    ${SOURCE_DIR}/io_tools.cpp
)

target_include_directories(image PUBLIC ${INCLUDE_DIR})
target_link_libraries(image PUBLIC ${OpenCV_LIBS})

# Bật chế độ testing
enable_testing()

# Tạo executable cho các unit tests
add_executable(Project_test
    tests/test_init.cpp
    tests/test_resize.cpp
    tests/test_histogram.cpp
    tests/test_from_file.cpp
)

# Liên kết đầy đủ GoogleTest và thư viện image vào Project_test
target_link_libraries(Project_test
    PRIVATE
        ${GTEST_LIBRARIES}
        ${GTEST_MAIN_LIBRARIES}
        pthread
        image
)

# Tự động tìm và thêm các unit tests
include(GoogleTest)
gtest_discover_tests(Project_test)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tests/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/tests)
