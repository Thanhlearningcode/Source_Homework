**➡️ Tiếp theo: Bài 3 - Lambda Expressions và Functor**  
Bạn muốn mình tiếp tục ngay với bài 3 hay có phần nào trong bài 2 bạn muốn làm rõ hơn? 🚀

# C++ Hiện Đại – Bài 3: Lambda Expressions và Functor

## **1. Lambda Expressions**
Lambda là một biểu thức hàm ẩn danh được khai báo trực tiếp trong code mà không cần tạo một hàm riêng biệt.

### **1.1 Cú pháp cơ bản**
```cpp
auto add = [](int a, int b) { return a + b; };
int result = add(3, 4); // 7
```

### **1.2 Capture List (Danh sách bắt biến)**
Capture list giúp lambda truy cập biến bên ngoài:
```cpp
int factor = 2;
auto multiply = [factor](int x) { return x * factor; };
int result = multiply(5); // 10
```

| Capture List | Ý nghĩa |
|-------------|---------|
| `[=]`       | Bắt tất cả biến bên ngoài theo giá trị |
| `[&]`       | Bắt tất cả biến bên ngoài theo tham chiếu |
| `[x]`       | Bắt biến `x` theo giá trị |
| `[&x]`      | Bắt biến `x` theo tham chiếu |

Ví dụ bắt biến theo tham chiếu:
```cpp
int count = 0;
auto increment = [&count]() { count++; };
increment();
std::cout << count; // 1
```

### **1.3 Lambda có tham số và kiểu trả về**
```cpp
auto power = [](double base, int exp) -> double {
    double result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
};
```

### **1.4 Lambda sử dụng trong STL**
Lambda thường được dùng trong các hàm của STL:
```cpp
std::vector<int> nums = {3, 1, 4, 1, 5};
std::sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
```

### **1.5 Lambda với trạng thái mutable**
Mặc định, lambda bắt biến theo giá trị là hằng số. Nếu muốn thay đổi giá trị đó, cần dùng từ khóa `mutable`:
```cpp
int counter = 0;
auto increment = [counter]() mutable { return ++counter; };
std::cout << increment(); // 1
std::cout << increment(); // 2
```

---

## **2. Functor – Xây dựng class functor thay thế lambda**

### **2.1 Functor là gì?**
Functor (Function Object) là một class có thể gọi như một hàm nhờ vào `operator()`. Functor có ưu điểm:
- Dễ dàng tái sử dụng.
- Có thể lưu trạng thái nội bộ.
- Hiệu suất tối ưu hơn trong một số trường hợp.

### **2.2 Cấu trúc Functor**
```cpp
class Multiply {
    int factor;
public:
    Multiply(int f) : factor(f) {}
    int operator()(int x) const { return x * factor; }
};
```

Dùng functor thay lambda:
```cpp
Multiply timesTwo(2);
int result = timesTwo(5); // 10
```

### **2.3 Functor trong STL**
Functor có thể dùng trong `std::sort`:
```cpp
class Compare {
public:
    bool operator()(int a, int b) {
        return a < b;
    }
};
std::vector<int> v = {5, 3, 1, 4, 2};
std::sort(v.begin(), v.end(), Compare());
```

### **2.4 Functor lưu trạng thái**
Functor có thể lưu trạng thái nội bộ, giúp xử lý những bài toán phức tạp hơn:
```cpp
class Counter {
    int count;
public:
    Counter() : count(0) {}
    int operator()() { return ++count; }
};
Counter counter;
std::cout << counter(); // 1
std::cout << counter(); // 2
```

### **2.5 So sánh Lambda và Functor**
| Đặc điểm | Lambda | Functor |
|----------|--------|---------|
| Ngắn gọn | ✅ | ❌ |
| Lưu trạng thái | ❌ (trừ khi mutable) | ✅ |
| Dùng trong template | ❌ | ✅ |
| Hiệu suất | Tốt với code nhỏ | Tốt với code lớn |

### **2.6 Khi nào nên dùng Functor thay Lambda?**
| Tình huống | Nên dùng |
|-----------|---------|
| Cần xử lý đơn giản, nhanh gọn | Lambda |
| Cần lưu trạng thái nội bộ | Functor |
| Cần truyền vào template | Functor |
| Tối ưu hiệu suất trong vòng lặp lớn | Functor |

---
