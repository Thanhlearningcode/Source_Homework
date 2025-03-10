# Unit Testing C++ với Google Test

## Giới thiệu
`test` là một dự án C++ minh họa cách viết unit test bằng Google Test (GTest). Dự án giúp kiểm thử mã nguồn một cách hiệu quả, đảm bảo tính đúng đắn và ổn định của chương trình. Việc sử dụng unit test giúp phát hiện lỗi sớm, giảm chi phí bảo trì và cải thiện chất lượng phần mềm.

## Yêu cầu hệ thống
Để sử dụng `test` và chạy unit test với Google Test, bạn cần:
- **Trình biên dịch:** Hỗ trợ C++17 trở lên (GCC, Clang, MSVC)
- **CMake:** Phiên bản 3.10 trở lên
- **Google Test framework:** Có thể tải về hoặc sử dụng thông qua CMake FetchContent

## Cài đặt
1. **Clone repository:**
   ```sh
   git clone https://github.com/your-repo/test.git
   cd test
   ```
2. **Tạo thư mục build và cấu hình dự án:**
   ```sh
   mkdir build && cd build
   cmake ..
   ```
3. **Tiến hành biên dịch:**
   ```sh
   make
   ```
4. **Cài đặt Google Test (nếu chưa có):**
   Google Test có thể được thêm vào dự án bằng cách sử dụng `FetchContent` trong CMake:
   ```cmake
   include(FetchContent)
   FetchContent_Declare(
       googletest
       URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
   )
   FetchContent_MakeAvailable(googletest)
   ```

## Chạy kiểm thử (Unit Test)
Sau khi biên dịch, để chạy các bài test, sử dụng:
```sh
ctest --output-on-failure
```
Hoặc chạy trực tiếp file thực thi test:
```sh
./runTests
```

## Viết Unit Test với Google Test
Google Test cung cấp một cách dễ dàng để viết unit test. Dưới đây là một ví dụ đơn giản:
```cpp
#include <gtest/gtest.h>
#include "anyf.h"

TEST(AnyfTest, ExampleTest) {
    EXPECT_EQ(2 + 2, 4);  // Kiểm tra nếu 2 + 2 bằng 4
    ASSERT_TRUE(true);     // Đảm bảo điều kiện luôn đúng
}
```

### Cấu trúc bài test:
- `TEST(TênTestSuite, TênTestCase)` để khai báo một test case.
- Các macro kiểm tra:
  - `EXPECT_EQ(a, b)`, `ASSERT_EQ(a, b)`: Kiểm tra nếu `a == b`.
  - `EXPECT_NE(a, b)`, `ASSERT_NE(a, b)`: Kiểm tra nếu `a != b`.
  - `EXPECT_TRUE(condition)`, `ASSERT_TRUE(condition)`: Kiểm tra nếu điều kiện đúng.
  - `EXPECT_FALSE(condition)`, `ASSERT_FALSE(condition)`: Kiểm tra nếu điều kiện sai.
  - `EXPECT_THROW(statement, exceptionType)`: Kiểm tra nếu `statement` ném ngoại lệ mong muốn.

### Kiểm thử đa luồng (Multithreading Testing)
Google Test hỗ trợ kiểm thử các ứng dụng đa luồng bằng cách sử dụng các cơ chế đồng bộ hóa để kiểm tra tính nhất quán của dữ liệu.
Ví dụ kiểm thử đa luồng với `std::thread`:
```cpp
#include <gtest/gtest.h>
#include <thread>
#include <mutex>

std::mutex mtx;
int shared_resource = 0;

void increment() {
    std::lock_guard<std::mutex> lock(mtx);
    shared_resource++;
}

TEST(MultiThreadingTest, ThreadSafety) {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    EXPECT_EQ(shared_resource, 2);
}
```

### Kiểm thử hiệu năng (Performance Testing)
Google Test không có công cụ đo hiệu năng tích hợp nhưng có thể kết hợp với `std::chrono` để đo thời gian chạy của hàm:
```cpp
#include <gtest/gtest.h>
#include <chrono>

TEST(PerformanceTest, TimeExecution) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++); // Vòng lặp giả lập xử lý
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    EXPECT_LT(elapsed.count(), 0.5); // Thời gian chạy phải nhỏ hơn 0.5 giây
}
```

### Kiểm thử tích hợp (Integration Testing)
Kiểm thử tích hợp giúp kiểm tra sự tương tác giữa các thành phần của hệ thống.
Ví dụ kiểm thử tích hợp giữa hai lớp:
```cpp
#include <gtest/gtest.h>
class Service {
public:
    int process(int x) { return x * 2; }
};

class Controller {
    Service service;
public:
    int handle(int x) { return service.process(x) + 1; }
};

TEST(IntegrationTest, ServiceAndController) {
    Controller controller;
    EXPECT_EQ(controller.handle(3), 7);
}
```

## Cấu trúc dự án
```
anyf/
├── src/          # Mã nguồn chính
├── include/      # Các file header
├── tests/        # Unit test
│   ├── main.cpp  # Entry point của Google Test
│   ├── test1.cpp # Các bài test
│   ├── test2.cpp # Các bài test
├── CMakeLists.txt
└── README.md
```

## Tích hợp CI/CD
Bạn có thể tích hợp Google Test vào CI/CD với GitHub Actions:
```yaml
name: C++ CI
on: [push, pull_request]
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      - name: Cài đặt CMake
        run: sudo apt-get install cmake
      - name: Build & Test
        run: |
          mkdir build && cd build
          cmake ..
          make
          ctest --output-on-failure
```

## Đóng góp
Mọi người đều có thể đóng góp bằng cách tạo issue hoặc gửi pull request để cải thiện `anyf`.

## Giấy phép
Dự án này được cấp phép theo MIT License.

