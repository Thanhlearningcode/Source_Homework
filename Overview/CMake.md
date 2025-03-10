# CMake Tutorial

## Giới Thiệu
CMake là một công cụ tự động hóa biên dịch giúp quản lý quá trình biên dịch trên nhiều nền tảng. Nó tạo ra các tệp cấu hình cho các trình biên dịch khác nhau như Makefile, Ninja, hoặc Visual Studio. CMake giúp dễ dàng quản lý thư viện, kiểm soát quá trình biên dịch, và hỗ trợ các hệ điều hành khác nhau.

## 1. Cấu Trúc Dự Án CMake
Một dự án CMake điển hình có cấu trúc thư mục như sau:

```
/MyProject
 ├── CMakeLists.txt    # Tệp cấu hình chính của CMake
 ├── src/              # Chứa mã nguồn
 │   ├── main.cpp
 │   ├── module1.cpp
 │   ├── module1.h
 │   ├── module2.cpp
 │   ├── module2.h
 ├── include/          # Chứa file header
 │   ├── module1.h
 │   ├── module2.h
 ├── build/            # Thư mục chứa file biên dịch và output
 ├── CMakeLists.txt    # CMake config chính
 ├── src/CMakeLists.txt # CMake config cho thư mục src
```

## 2. Tạo `CMakeLists.txt`
### **Tệp CMakeLists.txt Chính**
```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)  # Chỉ định chuẩn C++
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_executable(MyExecutable src/main.cpp src/module1.cpp src/module2.cpp)
```

### **Tệp CMakeLists.txt Trong `src/`**
```cmake
add_library(MyLibrary module1.cpp module2.cpp)
```

Trong `CMakeLists.txt` chính, bạn có thể gọi thư viện này:
```cmake
add_subdirectory(src)
target_link_libraries(MyExecutable PRIVATE MyLibrary)
```

## 3. Các Câu Lệnh Quan Trọng Trong CMake
### `project(<Tên dự án>)`
Khai báo tên dự án.

### `cmake_minimum_required(VERSION <phiên bản>)`
Xác định phiên bản tối thiểu của CMake cần thiết.

### `add_executable(<Tên output> <Danh sách file nguồn>)`
Dùng để tạo một file thực thi từ mã nguồn.

### `add_library(<Tên thư viện> <Danh sách file nguồn>)`
Tạo một thư viện từ các file nguồn.

### `target_link_libraries(<Target> <Thư viện>)`
Liên kết thư viện với một target cụ thể.

### `include_directories(<Thư mục>)`
Chỉ định thư mục chứa các file header.

## 4. Cách Build với CMake
Chạy các lệnh sau trong terminal:
```sh
mkdir build
cd build
cmake ..
make
./MyExecutable  # Chạy chương trình
```

## 5. Các Lệnh CMake Hữu Ích
- **Xóa cache CMake và rebuild**:
  ```sh
  rm -rf build/
  mkdir build && cd build
  cmake .. && make
  ```
- **Kiểm tra biến CMake**:
  ```sh
  cmake --help-variable CMAKE_CXX_COMPILER
  ```
- **Tạo tệp cấu hình để debug với Makefile**:
  ```sh
  cmake -G "Unix Makefiles" ..
  ```
- **Sử dụng Ninja thay vì Make**:
  ```sh
  cmake -G Ninja ..
  ninja
  ```

## 6. Biến Quan Trọng Trong CMake
- `CMAKE_SOURCE_DIR`: Đường dẫn thư mục gốc của dự án.
- `CMAKE_BINARY_DIR`: Đường dẫn thư mục build.
- `CMAKE_CXX_COMPILER`: Trình biên dịch C++ đang sử dụng.
- `CMAKE_BUILD_TYPE`: Chế độ build (`Debug`, `Release`, `RelWithDebInfo`, `MinSizeRel`).
- `CMAKE_INSTALL_PREFIX`: Đường dẫn cài đặt khi chạy `make install`.

## 7. Ví Dụ Chi Tiết
### 7.1. Ví Dụ Sử Dụng Thư Viện Tự Định Nghĩa
#### main.cpp
```cpp
#include <iostream>
#include "module1.h"

int main() {
    std::cout << "Kết quả: " << add(5, 3) << std::endl;
    return 0;
}
```
#### module1.h
```cpp
#ifndef MODULE1_H
#define MODULE1_H

int add(int a, int b);

#endif
```
#### module1.cpp
```cpp
#include "module1.h"

int add(int a, int b) {
    return a + b;
}
```
#### CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_library(MyLibrary src/module1.cpp)
add_executable(MyExecutable src/main.cpp)

target_link_libraries(MyExecutable PRIVATE MyLibrary)
```
### 7.2. Ví Dụ CMake Sử Dụng `find_package()`
CMake có thể tìm thư viện bên ngoài, ví dụ OpenCV:
```cmake
cmake_minimum_required(VERSION 3.10)
project(OpenCVExample)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(OpenCVApp main.cpp)
target_link_libraries(OpenCVApp ${OpenCV_LIBS})
```

## 8. Tổng Kết
- `CMakeLists.txt` chính để cấu hình tổng thể dự án.
- `add_executable()` dùng để tạo file thực thi.
- `add_library()` dùng để tạo thư viện.
- `target_link_libraries()` để liên kết thư viện.
- `include_directories()` để chỉ định thư mục header.
- `find_package()` dùng để tìm thư viện bên ngoài.
- Build bằng `cmake ..` và `make`.
- CMake hỗ trợ nhiều hệ thống build khác nhau như Make, Ninja, Visual Studio.

---
Đây là hướng dẫn chi tiết về CMake. Nếu bạn cần mở rộng với `install()`, `add_custom_command()`, hãy liên hệ để biết thêm chi tiết!
