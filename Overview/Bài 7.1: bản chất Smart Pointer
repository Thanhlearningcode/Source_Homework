# C++ Hiện Đại – Bài 7: Smart Pointers và Quản Lý Bộ Nhớ

## **1. Giới thiệu về Smart Pointers**
Smart Pointers trong C++ giúp quản lý bộ nhớ tự động, giảm nguy cơ rò rỉ bộ nhớ (memory leak) và lỗi truy cập bộ nhớ (dangling pointers).

C++ cung cấp 3 loại smart pointers chính trong thư viện `<memory>`:
- `std::unique_ptr` – Quản lý tài nguyên với quyền sở hữu duy nhất.
- `std::shared_ptr` – Quản lý tài nguyên với cơ chế đếm tham chiếu.
- `std::weak_ptr` – Tránh vòng lặp tham chiếu trong `shared_ptr`.

---

## **2. Unique Pointer (`std::unique_ptr`)**
### **2.1 Khái niệm**
`std::unique_ptr` đảm bảo mỗi tài nguyên chỉ có một đối tượng sở hữu duy nhất. Khi `unique_ptr` bị hủy, tài nguyên sẽ được giải phóng.

### **2.2 Ví dụ sử dụng**
```cpp
#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource Acquired\n"; }
    ~Resource() { std::cout << "Resource Released\n"; }
};

int main() {
    std::unique_ptr<Resource> res = std::make_unique<Resource>();
    return 0;
}
```

### **2.3 Chuyển quyền sở hữu**
```cpp
std::unique_ptr<Resource> res1 = std::make_unique<Resource>();
std::unique_ptr<Resource> res2 = std::move(res1); // res1 không còn sở hữu tài nguyên
```

---

## **3. Shared Pointer (`std::shared_ptr`)**
### **3.1 Khái niệm**
`std::shared_ptr` sử dụng bộ đếm tham chiếu để theo dõi số lượng con trỏ trỏ đến cùng một tài nguyên.

### **3.2 Ví dụ sử dụng**
```cpp
#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource Acquired\n"; }
    ~Resource() { std::cout << "Resource Released\n"; }
};

int main() {
    std::shared_ptr<Resource> res1 = std::make_shared<Resource>();
    std::shared_ptr<Resource> res2 = res1; // res2 cũng sở hữu cùng tài nguyên
    std::cout << "Use count: " << res1.use_count() << "\n";
    return 0;
}
```

---

## **4. Weak Pointer (`std::weak_ptr`)**
### **4.1 Khái niệm**
`std::weak_ptr` là một con trỏ "yếu", không làm tăng bộ đếm tham chiếu, giúp tránh vòng lặp tham chiếu trong `shared_ptr`.

### **4.2 Ví dụ sử dụng**
```cpp
#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource Acquired\n"; }
    ~Resource() { std::cout << "Resource Released\n"; }
};

int main() {
    std::shared_ptr<Resource> res1 = std::make_shared<Resource>();
    std::weak_ptr<Resource> weakRes = res1; // Không tăng reference count
    return 0;
}
```

---

## **5. Tự Cài Đặt Smart Pointers**
### **5.1 Implement `UniquePtr`**
```cpp
template<typename T>
class UniquePtr {
private:
    T* ptr;
public:
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}
    ~UniquePtr() { delete ptr; }
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
    UniquePtr(const UniquePtr&) = delete; // Không cho phép copy
    UniquePtr& operator=(const UniquePtr&) = delete;
    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) { other.ptr = nullptr; }
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
};
```

### **5.2 Implement `SharedPtr` & `WeakPtr`**
```cpp
#include <iostream>

class ControlBlock {
public:
    int ref_count;
    ControlBlock() : ref_count(1) {}
    void add_ref() { ++ref_count; }
    void release_ref() { --ref_count; }
};

template<typename T>
class SharedPtr {
private:
    T* ptr;
    ControlBlock* control;
public:
    explicit SharedPtr(T* p = nullptr) : ptr(p), control(new ControlBlock()) {}
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), control(other.control) { control->add_ref(); }
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            control->release_ref();
            if (control->ref_count == 0) {
                delete ptr;
                delete control;
            }
            ptr = other.ptr;
            control = other.control;
            control->add_ref();
        }
        return *this;
    }
    ~SharedPtr() {
        control->release_ref();
        if (control->ref_count == 0) {
            delete ptr;
            delete control;
        }
    }
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }
};
```
🚀 **Bài 7 giúp bạn hiểu sâu hơn về Smart Pointers và quản lý bộ nhớ hiệu quả trong C++!**
