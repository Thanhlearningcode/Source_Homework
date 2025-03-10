cmake_minimum_required(VERSION 3.10)
project(ConvertDataset)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenCV with xfeatures2d module
find_package(OpenCV REQUIRED core imgproc highgui features2d calib3d xfeatures2d)

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)  # Include custom headers

# Source files
set(SOURCES
    source/convert_dataset.cpp
    source/serialize.cpp
)

# Create a static library (.a)
add_library(convert_dataset STATIC ${SOURCES})

# Link OpenCV libraries
target_link_libraries(convert_dataset ${OpenCV_LIBS})

# Link filesystem library if needed
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(convert_dataset stdc++fs)
endif()
