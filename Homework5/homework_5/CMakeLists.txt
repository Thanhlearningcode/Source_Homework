cmake_minimum_required(VERSION 3.10)
project(ConvertDataset)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenCV with contrib modules
find_package(OpenCV REQUIRED core imgproc highgui features2d calib3d contrib)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)  # Adding the include directory

file(GLOB SOURCES "source/*.cpp")

add_executable(convert_dataset ${SOURCES})

# Link OpenCV libraries including contrib
target_link_libraries(convert_dataset ${OpenCV_LIBS})
