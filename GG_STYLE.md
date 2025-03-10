
# 🚀 README - Google C++ Style Tutorial

## 📌 Giới thiệu
Dự án này là một ví dụ đơn giản để minh họa cách viết mã theo chuẩn **Google C++ Style Guide**.
Nó bao gồm các ví dụ về:
✅ Định dạng code chuẩn Google.  
✅ Đặt tên biến, hàm, class theo CamelCase.  
✅ Cấu trúc thư mục và build code bằng `CMake`.  
✅ Xử lý tín hiệu và cấp phát bộ nhớ một cách an toàn.  

---

## 🛠️ Cấu trúc thư mục
```
project-root/
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   └── utils.cpp
├── include/
│   └── utils.h
├── test/
│   ├── test_main.cpp
│   └── test_utils.cpp
├── README.md
└── .gitignore
```

---

## 📥 Cài đặt
### ➡️ 1. Cài đặt các thư viện cần thiết
Trên Ubuntu:  
```bash
sudo apt update
sudo apt install -y build-essential cmake git
```

### ➡️ 2. Clone repo
```bash
git clone https://github.com/your-username/your-project.git
cd your-project
```

---

## 🏗️ Build dự án
### ➡️ 1. Tạo thư mục `build/` và chạy CMake
```bash
mkdir build
cd build
cmake ..
make
```

### ➡️ 2. Chạy chương trình
```bash
./your_project
```

---

## ✅ Hướng dẫn code theo Google Style
### 🔹 1. Đặt tên theo CamelCase
- **Tên hàm**: `FunctionName()`  
- **Tên biến**: `myVariable`  
- **Tên hằng số**: `kMyConstant`  

Ví dụ:
```cpp
int kMaxValue = 100;   // Hằng số bắt đầu bằng 'k'
void PrintValue(int value) {
  std::cout << "Value: " << value << std::endl;
}
```

---

### 🔹 2. Đặt thứ tự `#include`
- **Thư viện C++ tiêu chuẩn** → `#include <iostream>`  
- **Thư viện hệ thống** → `#include <unistd.h>`  
- **Header của chính dự án** → `#include "my_header.h"`  

Ví dụ:
```cpp
#include <iostream>
#include <vector>
#include "utils.h"
```

---

### 🔹 3. Dùng `const` và `constexpr` cho giá trị không thay đổi
✅ Dùng `const` cho biến thông thường:  
✅ Dùng `constexpr` cho giá trị bất biến ở compile-time:  

Ví dụ:
```cpp
constexpr int kMaxValue = 100;
const std::string kAppName = "GoogleStyleApp";
```

---

### 🔹 4. Xử lý lỗi trả về khi gọi hàm hệ thống
❌ **Không được bỏ qua lỗi** khi gọi các hàm hệ thống như `fork()` hoặc `signal()`  

Ví dụ:
```cpp
if (std::signal(SIGTERM, HandleSigTerm) == SIG_ERR) {
  std::cerr << "Failed to register signal handler" << std::endl;
}
```

---

### 🔹 5. Format và căn lề chuẩn
✅ Dùng **2 spaces** cho thụt lề.  
✅ Dùng `{}` cho mọi câu lệnh điều kiện (ngay cả khi chỉ có một lệnh).  

Ví dụ:
```cpp
if (value > 0) {
  std::cout << "Value is positive." << std::endl;
}
```

---

## 🔥 Ví dụ Code theo Google Style
```cpp
#include <iostream>

constexpr int kMaxValue = 100;

void PrintValue(int value) {
  if (value > 0) {
    std::cout << "Value: " << value << std::endl;
  } else {
    std::cerr << "Invalid value!" << std::endl;
  }
}

int main() {
  int value = kMaxValue;
  PrintValue(value);
  return 0;
}
```

---

## 🧪 Chạy Test
### ➡️ 1. Build test
```bash
cd build
make test
```

### ➡️ 2. Chạy test
```bash
ctest --verbose
```

---

## 📜 Quy Tắc Tuân Thủ Google Style
✅ Sử dụng `CamelCase` cho tên hàm và biến.  
✅ Dùng `k` làm tiền tố cho hằng số.  
✅ Sử dụng `const` và `constexpr` đúng mục đích.  
✅ Tránh sử dụng `#define` cho giá trị hằng số → dùng `constexpr` thay thế.  
✅ Xử lý đầy đủ lỗi từ hệ thống.  
✅ Không sử dụng `using namespace std;`.  

---

## 🌟 Liên hệ
📧 Email: your-email@gmail.com  
📌 GitHub: [your-username](https://github.com/your-username)  

---

### 🚀 **Code sạch hơn, đẹp hơn, chuẩn hơn!** 😎
