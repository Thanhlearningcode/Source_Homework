# Tiện ích chung trong C++ (General-purpose Utilities)

## Program utilities (`std::abort`)
- Dừng chương trình ngay lập tức.

## Date and Time (`std::chrono::duration`)
- Hỗ trợ làm việc với thời gian, thời lượng, đồng hồ.

## Optional, Variant và Any (`std::variant`)
- `std::optional`: Đại diện cho một giá trị có thể có hoặc không.
- `std::variant`: Kiểu dữ liệu tổng hợp (union type an toàn).
- `std::any`: Lưu trữ bất kỳ kiểu dữ liệu nào mà không cần biết trước.

## Pairs và Tuples (`std::tuple`)
- `std::pair`: Lưu trữ một cặp giá trị.
- `std::tuple`: Lưu trữ nhiều giá trị có thể có kiểu khác nhau.

## Swap, Forward và Move (`std::move`)
- `std::swap`: Hoán đổi giá trị của hai biến.
- `std::forward`: Giữ nguyên kiểu tham chiếu khi truyền tham số.
- `std::move`: Chuyển đổi giá trị mà không cần sao chép dữ liệu.

## Hash support (`std::hash`)
- Hỗ trợ tạo giá trị băm cho các kiểu dữ liệu dùng trong unordered containers như `std::unordered_map`, `std::unordered_set`.

## Formatting library (C++20)
- Bổ sung thư viện định dạng chuỗi giống `printf`, nhưng an toàn hơn, mạnh hơn (`std::format` trong C++20).

## Much more...
Ngoài ra còn nhiều tiện ích khác trong thư viện chuẩn C++.

---

# README: C++ Standard Library Features

## 1. std::variant
`std::variant` cho phép lưu trữ một trong nhiều kiểu dữ liệu tại một thời điểm.

### Cách dùng:
- Dùng `std::get<T>(variant)` hoặc `std::get<index>(variant)` để truy cập giá trị.
- Có thể gán giá trị từ variant này sang variant khác nếu kiểu dữ liệu phù hợp.

### Ví dụ:
```cpp
#include <iostream>
#include <variant>

int main() {
    std::variant<int, float> v1;
    v1 = 12;  // v1 chứa giá trị kiểu int
    std::cout << std::get<int>(v1) << std::endl; // In ra 12
    
    std::variant<int, float> v2{3.14F}; // v2 chứa giá trị kiểu float
    std::cout << std::get<1>(v2) << std::endl; // In ra 3.14
    
    v2 = std::get<int>(v1);  // Lấy giá trị int từ v1 và gán vào v2
    v2 = std::get<0>(v1);    // Dòng này giống dòng trên, sử dụng index thay vì kiểu dữ liệu
    v2 = v1;                 // Cách gán trực tiếp từ v1 sang v2
    
    std::cout << std::get<int>(v2) << std::endl; // In ra 12
    
    return 0;
}
```

---

## 2. std::any
`std::any` cho phép lưu trữ bất kỳ kiểu dữ liệu nào.

### Cách dùng:
- Dùng `std::any_cast<T>(any_obj)` để lấy giá trị từ `std::any`.
- Có thể gán lại giá trị với kiểu dữ liệu khác.

### Ví dụ:
```cpp
#include <iostream>
#include <any>

int main() {
    std::any a;
    a = 1; // int
    std::cout << std::any_cast<int>(a) << std::endl;
    
    a = 3.14; // double
    std::cout << std::any_cast<double>(a) << std::endl;
    
    a = true; // bool
    std::cout << std::boolalpha << std::any_cast<bool>(a) << std::endl;
    
    return 0;
}
```

---

## 3. std::optional
`std::optional` giúp đại diện cho một giá trị có thể tồn tại hoặc không.

### Cách dùng:
- Dùng `.value()` để lấy giá trị (cần đảm bảo giá trị tồn tại).
- Dùng `.value_or(default_value)` để lấy giá trị mặc định nếu không có dữ liệu.

### Ví dụ:
```cpp
#include <iostream>
#include <optional>

std::optional<std::string> StringFactory(bool create) {
    if (create) {
        return "Modern C++ is Awesome";
    }
    return {};
}

int main() {
    std::cout << StringFactory(true).value() << '\n';
    std::cout << StringFactory(false).value_or(":(") << '\n';
    return 0;
}
```

---

## 4. std::tuple
`std::tuple` cho phép lưu trữ nhiều giá trị với các kiểu dữ liệu khác nhau trong một biến.

### Cách dùng:
- Dùng `std::get<T>(tuple)` hoặc `std::get<index>(tuple)` để truy xuất dữ liệu.
- Dùng structured binding để dễ dàng lấy dữ liệu từ tuple.

### Ví dụ:
```cpp
#include <iostream>
#include <tuple>

int main() {
    std::tuple<double, char, std::string> student{1.4, 'A', "Jose"};
    std::cout << std::get<2>(student) << std::endl; // In ra "Jose"
    
    auto [gpa, grade, name] = std::make_tuple(4.4, 'B', "");
    std::cout << "GPA: " << gpa << ", grade: " << grade << ", name: " << name << std::endl;
    
    return 0;
}
```

---

## 5. std::chrono
`std::chrono` giúp làm việc với thời gian và độ trễ một cách chính xác.

### Cách dùng:
- Dùng `std::chrono::high_resolution_clock` để đo thời gian thực thi.
- Dùng `std::this_thread::sleep_for` để tạo độ trễ.

### Ví dụ:
```cpp
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Chờ 2 giây
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
    
    return 0;
}
```
