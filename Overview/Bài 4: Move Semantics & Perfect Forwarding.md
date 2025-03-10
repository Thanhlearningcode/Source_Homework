# C++ Hiện Đại – Bài 4: Move Semantics & Perfect Forwarding

## **1. Move Constructor & Move Assignment**
Move Constructor và Move Assignment giúp tối ưu hiệu suất khi di chuyển tài nguyên thay vì sao chép. Điều này rất quan trọng trong C++ hiện đại để tránh sao chép dữ liệu không cần thiết, giúp cải thiện hiệu suất đáng kể.

### **1.1 Move Constructor**
Move Constructor được gọi khi một đối tượng được khởi tạo từ một rvalue, giúp tránh sao chép dữ liệu không cần thiết. Nó chiếm quyền sở hữu tài nguyên của đối tượng nguồn thay vì tạo bản sao.
```cpp
class MyClass {
    int* data;
public:
    MyClass(int value) : data(new int(value)) {}
    ~MyClass() { delete data; }
    
    // Move Constructor
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr; // Đảm bảo đối tượng nguồn không giải phóng tài nguyên
    }
};
```
Trong đoạn code trên:
- Move Constructor nhận một `rvalue reference` (`MyClass&& other`).
- Di chuyển con trỏ dữ liệu từ `other` sang đối tượng hiện tại.
- Đặt `other.data = nullptr` để tránh giải phóng tài nguyên hai lần.

### **1.2 Move Assignment Operator**
Move Assignment giúp di chuyển tài nguyên từ một rvalue sang một đối tượng hiện có.
```cpp
class MyClass {
    int* data;
public:
    MyClass(int value) : data(new int(value)) {}
    ~MyClass() { delete data; }
    
    // Move Assignment Operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) { // Tránh tự gán chính nó
            delete data; // Giải phóng tài nguyên cũ
            data = other.data; // Di chuyển tài nguyên
            other.data = nullptr;
        }
        return *this;
    }
};
```
Lưu ý:
- Kiểm tra `this != &other` để tránh tự gán chính nó.
- Giải phóng tài nguyên cũ trước khi di chuyển tài nguyên mới.

---

## **2. Implement std::move & std::forward**
### **2.1 std::move**
`std::move` giúp ép một đối tượng thành rvalue reference để sử dụng move constructor hoặc move assignment.
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = std::move(v1); // v1 mất quyền sở hữu dữ liệu
    std::cout << "Size of v1: " << v1.size() << "\n"; // 0
}
```
Sau khi sử dụng `std::move`, `v1` sẽ không còn sở hữu dữ liệu, giúp tránh sao chép không cần thiết.

### **2.2 std::forward**
`std::forward` giúp forward tham số mà không thay đổi tính chất lvalue/rvalue của chúng. Thường dùng trong các hàm template để giữ nguyên đặc tính của tham số truyền vào.
```cpp
template<typename T>
void wrapper(T&& arg) {
    function(std::forward<T>(arg));
}
```
---

## **3. Perfect Forwarding**
Perfect Forwarding giúp truyền tham số một cách tối ưu mà không làm mất tính chất lvalue/rvalue.

### **3.1 Cách hoạt động của Perfect Forwarding**
Perfect Forwarding sử dụng `std::forward` để đảm bảo rằng tham số được chuyển đúng trạng thái ban đầu.
```cpp
template<typename T, typename... Args>
std::unique_ptr<T> create(Args&&... args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}
```
Điểm quan trọng:
- `Args&&... args` sử dụng **universal reference**, có thể nhận cả lvalue và rvalue.
- `std::forward<Args>(args)...` giúp giữ nguyên tính chất lvalue/rvalue của tham số.

### **3.2 Ví dụ Perfect Forwarding trong thực tế**
```cpp
#include <iostream>
#include <utility>

void process(int& x) { std::cout << "Lvalue reference\n"; }
void process(int&& x) { std::cout << "Rvalue reference\n"; }

template<typename T>
void forwarder(T&& arg) {
    process(std::forward<T>(arg));
}

int main() {
    int a = 10;
    forwarder(a);       // Lvalue reference
    forwarder(20);      // Rvalue reference
}
```
Cách hoạt động:
- Nếu `arg` là lvalue, `std::forward<T>(arg)` giữ nguyên lvalue.
- Nếu `arg` là rvalue, `std::forward<T>(arg)` giữ nguyên rvalue.

🚀 **Bài 4 giúp tối ưu hiệu suất trong C++ bằng Move Semantics và Perfect Forwarding.**
