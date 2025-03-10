

### **Bắt đầu với Bài 2: C++ Hiện Đại – Các Cú Pháp Mới**  


---

## **1. auto và decltype**  
### **1.1 auto – Tự động suy luận kiểu dữ liệu**  
Trước C++11, khi khai báo biến, ta phải chỉ định rõ kiểu dữ liệu:  
```cpp
int x = 42;
double y = 3.14;
```
Nhưng từ C++11, `auto` giúp trình biên dịch tự động suy luận kiểu của biến dựa vào giá trị gán:  
```cpp
auto x = 42;   // x có kiểu int
auto y = 3.14; // y có kiểu double
auto str = "Hello"; // str có kiểu const char*
```
**Ưu điểm của auto:**  
✅ Giảm code dư thừa khi khai báo biến  
✅ Giúp code dễ đọc hơn khi làm việc với kiểu dữ liệu phức tạp  
✅ Tránh lỗi khi viết lại code với kiểu dữ liệu khác  

Ví dụ với iterator trong STL:  
```cpp
std::vector<int> v = {1, 2, 3, 4};
auto it = v.begin();  // Thay vì std::vector<int>::iterator it = v.begin();
```
---

### **1.2 decltype – Lấy kiểu dữ liệu của biểu thức**  
`decltype` giúp lấy kiểu của một biến hoặc biểu thức mà không cần khởi tạo nó.  
Ví dụ:  
```cpp
int a = 10;
decltype(a) b = 20; // b cũng có kiểu int
```
Sử dụng `decltype` khi cần khai báo biến có kiểu giống một biến khác hoặc một biểu thức:  
```cpp
int x = 5;
decltype(x + 3.5) y;  // y sẽ có kiểu double vì x + 3.5 là double
```
Ứng dụng phổ biến khi viết template tổng quát:  
```cpp
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}
```
⏩ **Tóm lại:**  
- `auto` giúp **tự động suy luận kiểu từ giá trị gán**.  
- `decltype` giúp **lấy kiểu của một biểu thức mà không khởi tạo nó**.  

---

## **2. Uniform Initialization (Khởi tạo nhất quán)**  
Trước C++11, ta có nhiều cách để khởi tạo biến:  
```cpp
int x = 10;
int y(20);
int z = {30}; // (C++11) Uniform Initialization
```
C++11 giới thiệu **Uniform Initialization** (`{}`) để tạo cách khởi tạo nhất quán:  
```cpp
int a{10};   // a có giá trị 10
double b{3.14}; // b có giá trị 3.14
std::vector<int> v{1, 2, 3, 4}; // Khởi tạo vector
```
**Lợi ích:**  
✅ Giảm lỗi **narrowing conversion** (chuyển đổi mất dữ liệu)  
Ví dụ, code này sẽ bị lỗi:  
```cpp
int x{3.14}; // ❌ Lỗi vì mất phần thập phân
```
Nhưng nếu không dùng `{}`, trình biên dịch sẽ **không báo lỗi**:  
```cpp
int x = 3.14; // ✅ Hợp lệ nhưng mất phần thập phân (x = 3)
```
✅ Dùng cho mọi kiểu dữ liệu: **biến, mảng, struct, class**  
```cpp
struct Point {
    int x, y;
};
Point p{10, 20}; // Khởi tạo struct
```
⏩ **Tóm lại:**  
- `{}` giúp khởi tạo nhất quán cho mọi kiểu dữ liệu.  
- Tránh lỗi **chuyển đổi mất dữ liệu** khi khai báo biến số.  

---

## **3. constexpr – Biểu thức hằng số**  
Trước C++11, ta dùng `const` để khai báo hằng số:  
```cpp
const int x = 10; // Hằng số
```
Nhưng `const` **chỉ đảm bảo giá trị không thay đổi trong runtime**, chứ không bắt buộc tính toán tại compile-time.  

C++11 giới thiệu `constexpr`, đảm bảo giá trị có thể tính toán tại **thời gian biên dịch** (compile-time):  
```cpp
constexpr int square(int x) {
    return x * x;
}

constexpr int y = square(5); // Tính tại compile-time
```
**Lợi ích:**  
✅ Giúp chương trình nhanh hơn do không cần tính toán lại khi chạy.  
✅ Có thể dùng để khai báo kích thước mảng tĩnh:  
```cpp
constexpr int size = 10;
int arr[size]; // Hợp lệ vì size là constexpr
```
✅ Kết hợp với template để tối ưu code:  
```cpp
template<int N>
constexpr int factorial() {
    return (N <= 1) ? 1 : (N * factorial<N - 1>());
}

constexpr int fact5 = factorial<5>(); // Tính tại compile-time
```
⏩ **Tóm lại:**  
- `constexpr` giúp **tính toán tại thời gian biên dịch** để tối ưu hiệu năng.  
- Thích hợp cho **biểu thức toán học, kích thước mảng, giá trị không đổi**.  

---

## **Kết luận Bài 2**  
📌 `auto`: Giúp trình biên dịch tự suy luận kiểu dữ liệu.  
📌 `decltype`: Dùng để lấy kiểu của một biểu thức mà không cần khởi tạo nó.  
📌 `Uniform Initialization`: `{}` giúp khởi tạo nhất quán và tránh lỗi chuyển đổi.  
📌 `constexpr`: Giúp tối ưu hiệu năng bằng cách tính toán giá trị ngay tại **compile-time**.  

---  


📌 **Bài 3 giúp hiểu rõ cách sử dụng Lambda và Functor trong lập trình C++.** 🚀
