# Debugging Unit Test

Debugging là một phần quan trọng trong quá trình phát triển phần mềm, giúp phát hiện và sửa lỗi trước khi phần mềm được triển khai. Trong bài viết này, chúng ta sẽ sử dụng **GDB**, **Valgrind**, và **AddressSanitizer** để debug unit test khi sử dụng Google Test.

---

## 1. Debug với GDB
GDB (GNU Debugger) là một công cụ mạnh mẽ giúp phân tích lỗi trong unit test, cho phép kiểm tra từng bước thực thi của chương trình.

### **1.1 Chạy test với GDB**
Nếu một test bị lỗi, bạn có thể sử dụng GDB để debug bằng cách chạy:
```sh
gdb ./runTests
```

Khi vào giao diện GDB, chạy một test cụ thể bằng cách sử dụng `--gtest_filter`:
```sh
run --gtest_filter=TestSuite.TestCase
```
Ví dụ:
```sh
run --gtest_filter=AnyfTest.ExampleTest
```
Điều này giúp thu hẹp phạm vi debug, chỉ chạy test bị lỗi.

### **1.2 Các lệnh GDB hữu ích**
- `break <function>`: Đặt breakpoint tại một hàm cụ thể.
- `break <filename>:<line>`: Đặt breakpoint tại một dòng cụ thể trong file.
- `run`: Chạy chương trình.
- `step`: Thực hiện từng lệnh và đi vào các hàm con.
- `next`: Thực hiện từng lệnh nhưng không đi vào hàm con.
- `continue`: Tiếp tục thực thi sau khi dừng tại breakpoint.
- `print <variable>`: In giá trị biến tại thời điểm hiện tại.
- `bt` (backtrace): Hiển thị stack trace khi chương trình bị lỗi.

### **1.3 Ví dụ Debug với GDB**
Giả sử bạn có một test bị lỗi do truy cập ngoài phạm vi:
```cpp
TEST(ExampleTest, OutOfBounds) {
    std::vector<int> vec = {1, 2, 3};
    EXPECT_EQ(vec.at(5), 10); // Lỗi do truy cập ngoài phạm vi
}
```
Bạn có thể debug như sau:
```sh
gdb ./runTests
(gdb) break ExampleTest_OutOfBounds_Test::TestBody
(gdb) run --gtest_filter=ExampleTest.OutOfBounds
(gdb) print vec
(gdb) bt
```
GDB sẽ dừng tại lỗi, hiển thị thông tin giúp bạn xác định nguyên nhân.

---

## 2. Debug với Valgrind (Phát hiện lỗi bộ nhớ)
Valgrind giúp phát hiện lỗi bộ nhớ như **memory leak, use-after-free, uninitialized memory**.

### **2.1 Chạy test với Valgrind**
```sh
valgrind --leak-check=full --show-leak-kinds=all ./runTests
```

### **2.2 Các lỗi phổ biến phát hiện bởi Valgrind**
- **Memory leaks**: Cấp phát bộ nhớ nhưng không giải phóng.
- **Use-after-free**: Truy cập bộ nhớ sau khi đã giải phóng.
- **Invalid read/write**: Truy cập vùng nhớ không hợp lệ.
- **Uninitialized memory**: Sử dụng biến chưa khởi tạo.

### **2.3 Ví dụ lỗi Valgrind**
Giả sử bạn có đoạn code sau:
```cpp
void memoryLeak() {
    int* ptr = new int[10]; // Cấp phát nhưng không giải phóng
}
```
Valgrind sẽ cảnh báo:
```
==12345== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==12345==    at 0x4C2A6A3: operator new[](unsigned long) (vg_replace_malloc.c:299)
==12345==    by 0x4006A2: memoryLeak() (test.cpp:10)
```
Cách sửa lỗi:
```cpp
void memoryLeak() {
    int* ptr = new int[10];
    delete[] ptr; // Giải phóng bộ nhớ
}
```
---

## 3. Debug với AddressSanitizer (ASan)
AddressSanitizer giúp phát hiện **lỗi truy cập bộ nhớ** như **buffer overflow, use-after-free, và dangling pointers** trong runtime.

### **3.1 Bật AddressSanitizer khi biên dịch**
Thêm flag `-fsanitize=address` khi biên dịch với CMake:
```sh
cmake -DCMAKE_CXX_FLAGS="-fsanitize=address -g" ..
make
```

### **3.2 Chạy test với AddressSanitizer**
```sh
ASAN_OPTIONS=detect_leaks=1 ./runTests
```

### **3.3 Các lỗi phổ biến phát hiện bởi AddressSanitizer**
- **Buffer overflow**: Truy cập ngoài phạm vi mảng.
- **Use-after-free**: Truy cập bộ nhớ đã bị giải phóng.
- **Dangling pointers**: Trỏ đến vùng nhớ không hợp lệ.
- **Memory leaks**: Phát hiện vùng nhớ không được giải phóng.

### **3.4 Ví dụ lỗi AddressSanitizer**
Nếu bạn có đoạn code gây lỗi:
```cpp
void bufferOverflow() {
    int arr[5] = {1, 2, 3, 4, 5};
    arr[10] = 100; // Lỗi: ghi ngoài phạm vi mảng
}
```
AddressSanitizer sẽ báo lỗi như sau:
```
==12345==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x6030000000f0 at pc 0x4006a2
```
Cách khắc phục là đảm bảo truy cập chỉ nằm trong phạm vi hợp lệ của mảng.

---

## 4. Tổng kết
### **So sánh giữa GDB, Valgrind, và AddressSanitizer**
| Công cụ          | Phát hiện lỗi gì?                         | Cách sử dụng |
|-----------------|---------------------------------|--------------|
| **GDB**         | Debug logic, crash, segmentation fault | `gdb ./runTests` |
| **Valgrind**    | Memory leaks, use-after-free, invalid read/write | `valgrind --leak-check=full ./runTests` |
| **AddressSanitizer** | Buffer overflow, use-after-free, memory corruption | `cmake -DCMAKE_CXX_FLAGS="-fsanitize=address"` |

Sử dụng **GDB** để debug logic chương trình, **Valgrind** để kiểm tra memory leak, và **AddressSanitizer** để phát hiện lỗi truy cập bộ nhớ trong runtime. Việc kết hợp cả ba công cụ này sẽ giúp bạn debug unit test hiệu quả hơn.

Nếu gặp lỗi khó xử lý, hãy sử dụng các công cụ này để phân tích và sửa lỗi nhanh chóng! 🚀

