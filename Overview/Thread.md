# 1. Tổng quan về Đa luồng 

<p align = "center">
<img src = "https://github.com/user-attachments/assets/22120bf9-ce18-4bfb-b219-d6dc239bee1a" width = "500" height = "300">

Thông thường đa số các chương trình khi chạy sẽ theo dạng tuần tự từ trên xuống, có nghĩa là các tác vụ hiện tại phải hoàn thành xong mới đến những cái tiếp theo. Trong những chương trình nhỏ thì điều này có vẻ không chịu ảnh hưởng gì nhiều tuy nhiên đối với những chương trình lớn chạy theo thời gian thực với những yêu cầu khắt khe và chính xác về thời gian để xử lý dữ liệu chính xác thì cách lập trình tuần tự không còn hiệu quả nữa

=> Chính vì vậy đa luồng được sinh ra để giải quyết vấn để trên
## 1.1 Khái niệm

<p align = "center">
<img src = "https://github.com/user-attachments/assets/09832edf-c7a3-4dd1-a895-1edee33e34db" width = "500" height = "200">

+ Luồng được hiểu là 1 đơn vị thực thi nhỏ nhất của 1 tiến trình. Mỗi tiến trình chứa nhiều thread và cho phép chúng chạy song song.
+ Các task sẽ chia sẻ chung 1 tài nguyên chương trình, nhưng có stack và bộ đếm riêng
+ Về bản chất đa luồng vẫn là tuần tự nhưng nó phân chia thời gian thực hiện giữa các tác vụ.

__Ưu điểm của đa luồng__

+ Xử lý đa nhiệm
+ tăng tốc độ xử lý và tối ưu hóa chương trình
+ Thích hợp với các hệ thống real-time như embedded system 

# 2. Thư viện pthread trong C
Trong c có hỗ trợ lập trình qua thư viện __#include<pthreah.h> cung cấp các APIs để thực hiện các chức năng như

## 2.1  Synchronization 
+ Cho phép các thread chia sẻ tài nguyên chung và xử lý 1 cách an toàn

## 2.2 Thread control
+ Cho phép tạo, quản lý và phối hợp với các thread khác

## 2.3 Các API cơ bản 

### a) Tạo 1 luồng 
```bash
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
```


# Dự Án C++: Sử Dụng Functor với Thread

## Mô Tả
Dự án này minh họa cách sử dụng các đối tượng **callable** (có thể gọi được), cụ thể là **functor** trong C++, với `std::thread`. Functor là những đối tượng mà bạn có thể gọi giống như một hàm, giúp bạn có thể sử dụng chúng trong các tình huống yêu cầu truyền vào một hàm (hoặc đối tượng callable) như `std::thread`.

## Functor là gì?
**Functor** là một đối tượng của một lớp có cài đặt toán tử `()` (toán tử gọi hàm). Khi toán tử này được nạp chồng, đối tượng có thể được sử dụng như một hàm.

Ví dụ:

```cpp
class HelloFunctor {
public:
    void operator()() {
        std::cout << "Hello from thread!" << std::endl;
    }
};
Cách Sử Dụng Functor với std::thread
1. Tạo một lớp Functor
Đầu tiên, bạn cần tạo một lớp có nạp chồng toán tử (). Đây chính là functor của bạn.
int main() {
    HelloFunctor functor;  // Tạo đối tượng functor
    std::thread t(functor); // Truyền đối tượng vào thread
    t.join();  // Chờ luồng kết thúc
    return 0;
}
Khi std::thread được tạo ra, toán tử () của đối tượng functor sẽ được gọi, và đoạn mã trong hàm operator() sẽ được thực thi trong một luồng mới.

```
Giải Thích
std::thread là một thư viện trong C++ cho phép bạn chạy mã trong một luồng (thread) riêng biệt.

Khi bạn truyền một đối tượng functor vào std::thread, đối tượng đó sẽ được gọi trong một luồng mới. Toán tử operator() của đối tượng functor chính là hàm sẽ được chạy khi luồng bắt đầu.


# Dự Án C++: Sử Dụng Lambda Expression với Thread

## Mô Tả
Dự án này minh họa cách sử dụng **lambda expression** trong C++ làm điểm vào (entry point) cho một luồng (`std::thread`). Lambda expression là một cách viết ngắn gọn và linh hoạt để định nghĩa các hàm vô danh mà có thể được sử dụng trực tiếp trong các tình huống như truyền vào một luồng.

## Lambda Expression là gì?
**Lambda expression** trong C++ cho phép bạn định nghĩa một hàm ngay tại chỗ, mà không cần phải khai báo trước. Bạn có thể sử dụng lambda để truyền vào các hàm, bao gồm cả `std::thread`.

### Ví dụ về Lambda Expression:
Lambda expression có thể có cú pháp sau:

```cpp
[ capture_list ] ( parameters ) -> return_type { body }
```
capture_list: Xác định các biến bên ngoài lambda được sử dụng bên trong lambda, có thể là "capture by reference" hoặc "capture by value".
parameters: Các tham số của hàm.
return_type: Kiểu trả về (tùy chọn nếu compiler có thể suy luận được).
body: Thân hàm

Cách Sử Dụng Lambda Expression với std::thread
1. Tạo một Lambda Expression và Truyền vào std::thread
cpp
```cpp
#include <iostream>
#include <thread>

int main() {
    // Sử dụng capture by reference
    std::thread thr([]() {
        std::cout << "Hello, Lambda Thread!\n";
    });

    thr.join();  // Chờ luồng kết thúc
    return 0;
}
```
Giải Thích:
Trong ví dụ này, một lambda expression được tạo ra và truyền trực tiếp vào std::thread. Khi luồng này bắt đầu chạy, lambda sẽ thực thi và in ra dòng thông báo "Hello, Lambda Thread!".
Capture by reference ([] không có gì bên trong dấu ngoặc vuông) cho phép lambda sử dụng các biến ngoài phạm vi mà không sao chép chúng, nhưng lưu ý rằng lambda sẽ sử dụng chúng theo kiểu tham chiếu.
Cách Capture Biến:
Capture by reference: [] (sử dụng tham chiếu vào các biến ngoài lambda)
Capture by value: [=] (sao chép các biến ngoài lambda vào trong lambda)

### Ví dụ về Thread Function + Template:

#include <iostream>
#include <thread>

// Hàm template có thể nhận tham số của bất kỳ kiểu dữ liệu nào
```cpp
template <typename T>
void print_value(T value) {
    std::cout << "Value: " << value << std::endl;
}

int main() {
    // Tạo các đối tượng thread và truyền hàm template với các kiểu dữ liệu khác nhau
    int int_val = 42;
    double double_val = 3.14;

    // Tạo thread với kiểu int
    std::thread t1(print_value<int>, int_val);
    // Tạo thread với kiểu double
    std::thread t2(print_value<double>, double_val);

    // Đảm bảo các thread hoàn thành trước khi chương trình kết thúc
    t1.join();
    t2.join();

    return 0;
}
```
Value: 42
Value: 3.14

Giải Thích:
Hàm Template print_value: Đây là một hàm template có thể nhận bất kỳ kiểu dữ liệu nào (T) và in giá trị của tham số vào màn hình.

Sử Dụng std::thread:

Chúng ta tạo hai thread t1 và t2 trong hàm main.
Mỗi thread sẽ gọi hàm print_value với tham số có kiểu khác nhau (int và double).
Các tham số được truyền vào khi tạo thread thông qua cú pháp std::thread(print_value<int>, int_val) và std::thread(print_value<double>, double_val).
join(): Sử dụng join() để đảm bảo chương trình chính chờ đến khi các thread hoàn thành trước khi kết thúc.

##Truyền tham số vào thread bằng cách di chuyển (pass by move)
```cpp
#include <iostream>
#include <thread>
#include <string>

// Hàm yêu cầu tham số là rvalue reference
void func(std::string &&str) {
    std::cout << "Ownership of \"" << str << "\" transferred to thread" << std::endl;
}

int main() {
    std::string str = "moveable";
    std::cout << "Starting thread\n";

    // Di chuyển str vào thread
    std::thread thr(func, std::move(str)); 
    thr.join();  // Đảm bảo thread hoàn thành

    // Xác nhận str đã bị thay đổi
    std::cout << "Do I still have any data? " 
              << (str.empty() ? "No" : "Yes") << std::endl;

    return 0;
}

# README: C++ Threads, `std::move`, `std::ref`, and Lambda Expressions

## Mô Tả
Dự án này giải thích và minh họa cách sử dụng **`std::thread`**, **`std::move`**, **`std::ref`**, và **lambda expression** trong C++ để tạo và quản lý các luồng (threads) trong chương trình.

### 1. **`std::thread`**:
**`std::thread`** là một thư viện trong C++ giúp tạo và quản lý các luồng trong chương trình. Nó cho phép chạy mã trong các luồng (threads) riêng biệt và song song.

#### Ví dụ về `std::thread`:
```cpp
#include <iostream>
#include <thread>

void print_message() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t(print_message);  // Tạo thread và truyền hàm
    t.join();  // Chờ thread kết thúc trước khi kết thúc chương trình
    return 0;
}
```

### 2. **`std::move`**:
**`std::move`** trong C++ không phải là một hàm di chuyển thực sự mà chỉ đơn giản là một cách để thông báo cho trình biên dịch rằng bạn muốn đối tượng trở thành một rvalue (giá trị tạm). Điều này cho phép sử dụng **move semantics**, giúp di chuyển tài nguyên thay vì sao chép chúng.

#### Ví dụ về `std::move`:
```cpp
#include <iostream>
#include <string>
#include <utility>

void print_string(std::string&& str) {
    std::cout << "Moved string: " << str << std::endl;
}

int main() {
    std::string str = "Hello, World!";
    print_string(std::move(str));  // Di chuyển str vào hàm
    std::cout << "After move, str is: " << str << std::endl;  // str sẽ trống
    return 0;
}
```

### 3. **`std::ref`**:
**`std::ref`** được sử dụng khi bạn muốn truyền tham chiếu của một đối tượng vào một hàm, đặc biệt trong trường hợp truyền tham số vào `std::thread`. Nó tránh sao chép đối tượng và giữ nguyên tham chiếu đến đối tượng gốc.

#### Ví dụ về `std::ref`:
```cpp
#include <iostream>
#include <thread>

void increment(int& n) {
    n++;  // Tăng giá trị của biến n
}

int main() {
    int x = 5;
    std::cout << "Before thread: " << x << std::endl;
    std::thread t(increment, std::ref(x));  // Truyền tham chiếu của x vào thread
    t.join();  // Đợi thread hoàn thành
    std::cout << "After thread: " << x << std::endl;  // x sẽ tăng lên 6
    return 0;
}
```

### 4. **Lambda Expressions trong `std::thread`**:
Lambda expressions trong C++ là một cách viết hàm vô danh một cách ngắn gọn và có thể sử dụng trong các tình huống như truyền vào `std::thread`. Lambda expressions cũng có thể "bắt" các biến từ phạm vi bên ngoài, giúp bạn sử dụng các giá trị đó trong thread.

#### Ví dụ về sử dụng Lambda Expressions trong `std::thread`:
```cpp
#include <iostream>
#include <thread>

int main() {
    int i = 3;
    // Sử dụng lambda expression để thay đổi giá trị của i trong thread
    std::thread thr([&i] {
        i *= 2;  // Nhân đôi giá trị của i
    });

    thr.join();  // Đợi thread kết thúc

    std::cout << "Value of i is now " << i << std::endl;  // Giá trị của i sẽ là 6
    return 0;
}
```

### Kết luận:
- **`std::thread`** giúp bạn tạo các luồng để thực thi song song trong chương trình.
- **`std::move`** giúp di chuyển tài nguyên thay vì sao chép, tối ưu hóa hiệu suất.
- **`std::ref`** giúp truyền tham chiếu tới đối tượng mà không sao chép.
- **Lambda expressions** trong C++ giúp viết các hàm vô danh và có thể dễ dàng được sử dụng trong các thread để thao tác với các biến trong phạm vi ngoài thread.
# README: Using Lambda Expressions with `std::thread`

## Mô Tả
Dự án này giải thích cách sử dụng **lambda expressions** trong C++ làm **entry point** cho **`std::thread`**. Đây là một kỹ thuật giúp bạn thực thi các tác vụ song song trong các luồng riêng biệt mà không cần phải khai báo các hàm riêng biệt.

### 1. **Lambda Expressions trong `std::thread`**:
Lambda expression là một hàm vô danh được định nghĩa ngay tại chỗ. C++ cho phép bạn sử dụng lambda expressions làm các hàm gọi trong các thread, rất tiện lợi khi bạn muốn thực hiện một tác vụ nhỏ trong một luồng mà không cần phải tạo một hàm riêng biệt.

#### Ví dụ về sử dụng lambda expression trong `std::thread`:
```cpp
#include <iostream>
#include <thread>

int main() {
    // Tạo và sử dụng lambda expression làm entry point cho thread
    std::thread thr(
        // Lambda expression nhận hai tham số i1 và i2
        [](int i1, int i2) {
            std::cout << "The sum of " << i1 << " and " << i2 << " is " << i1 + i2 << '\n';
        },
        // Truyền các đối số vào lambda
        2, 3
    );

    // Đảm bảo thread hoàn thành trước khi chương trình kết thúc
    thr.join();
    
    return 0;
}
```
3. Kết quả:
Kết quả in ra màn hình sẽ là:

The sum of 2 and 3 is 5
2. Giải Thích:
Lambda Expression: Đây là một hàm vô danh được định nghĩa ngay trong tham số của std::thread. Lambda nhận các tham số int i1, int i2 và thực hiện phép cộng giữa chúng rồi in kết quả ra màn hình.
std::thread: std::thread được sử dụng để tạo một luồng mới. Lambda được truyền vào như là một đối số của thread, với các tham số 2 và 3 được truyền cho lambda.
thr.join(): Sau khi tạo thread, join() sẽ đảm bảo rằng chương trình chính đợi cho đến khi thread hoàn tất trước khi tiếp tục thực thi.
# README: System Thread Interface and `native_handle()` in C++

## System Thread Interface

### 1. **`std::thread` sử dụng triển khai thread của hệ thống**
- **C++ sử dụng `std::thread` để tạo các luồng**, nhưng thực chất, `std::thread` sẽ dựa vào các triển khai **thread của hệ điều hành** (OS). Điều này có nghĩa là các hoạt động của thread thực sự được **quản lý và thực thi bởi hệ điều hành**.
  
### 2. **Cần sử dụng trực tiếp triển khai thread của hệ thống**
- Một số tính năng của thread không có sẵn trong C++ chuẩn và yêu cầu bạn phải làm việc trực tiếp với **API của hệ điều hành** để truy cập và điều khiển thread với những tính năng đặc biệt hơn.

### 3. **Một số tính năng không có sẵn trong C++ chuẩn**
- C++ chuẩn cung cấp một số khả năng cơ bản để làm việc với thread nhưng không bao gồm tất cả các tính năng, ví dụ như **ưu tiên thread** hoặc **gắn kết thread** (thread affinity). Để sử dụng những tính năng này, bạn có thể cần phải sử dụng các API của hệ điều hành.

### 4. **Thread Priority (Ưu tiên của thread)**
- Đây là khả năng thay đổi **mức độ ưu tiên** của một thread. Bạn có thể tăng hoặc giảm mức độ ưu tiên của thread, giúp CPU phân phối **thời gian xử lý** cho các thread khác nhau. Một thread có thể được **ưu tiên cao hơn hoặc thấp hơn** trong việc chia sẻ thời gian xử lý của CPU.

### 5. **Thread Affinity (Gắn kết thread)**
- **Thread affinity** cho phép bạn "gắn" một thread vào một **lõi xử lý** cụ thể. Điều này có nghĩa là thread sẽ chỉ chạy trên **lõi xử lý** mà bạn chỉ định, thay vì hệ điều hành tự động phân phối nó giữa các lõi khác nhau của CPU. Việc này giúp **tối ưu hóa hiệu suất** trong một số trường hợp.

### Tóm tắt:
- **`std::thread`** sử dụng cơ chế của hệ điều hành để triển khai và quản lý các thread.
- Bạn có thể cần truy cập các **API hệ thống** để sử dụng các tính năng đặc biệt như **ưu tiên thread** và **gắn kết thread**.
- **Thread priority** và **thread affinity** là những tính năng nâng cao để điều khiển cách thức hoạt động của các thread trong chương trình.

---

## `native_handle()` in C++

### 1. **Handle của mỗi thread**
- Mỗi thread trong hệ thống sẽ có một **"handle"**. Handle này là một giá trị dùng để tham chiếu đến thread và được sử dụng nội bộ trong hệ thống để quản lý các thread.

### 2. **`native_handle()`**
- **`native_handle()`** là một **member function** của đối tượng `std::thread`. Nó trả về **native handle** của thread.
- **Native handle** là một giá trị được hệ điều hành sử dụng để **quản lý thread**. Trong một số trường hợp, bạn có thể cần sử dụng **handle này khi tương tác với các API của hệ điều hành** (OS).

### 3. **Ứng dụng**
- Hàm **`native_handle()`** rất hữu ích khi bạn cần gọi các **API hệ thống** trực tiếp, mà không phải thông qua `std::thread`. Ví dụ, trong các hệ điều hành như **POSIX**, handle này có thể là một chỉ mục đối tượng thread hoặc một giá trị tương ứng.

### 4. **Ví dụ sử dụng `native_handle()`**:
```cpp
#include <iostream>
#include <thread>

void task() {
    std::cout << "Task running in a thread!" << std::endl;
}

int main() {
    // Tạo một thread và gán cho nó một hàm task
    std::thread thr(task);
    
    // Lấy native handle của thread
    auto handle = thr.native_handle();
    std::cout << "The native handle of the thread: " << handle << std::endl;
    
    // Chờ thread hoàn thành
    thr.join();

    return 0;
}
```
# README: Thread ID in C++

## Mô Tả
Trong C++, mỗi thread khi được tạo ra sẽ có một **Thread ID** (ID của luồng) duy nhất. Thông qua các hàm và phương thức trong thư viện chuẩn, bạn có thể lấy được **Thread ID** của một thread, giúp quản lý và phân biệt các thread khi cần thiết.

### 1. **Thread ID**
- Mỗi **execution thread** có một **thread identifier (ID)**. ID này được **hệ điều hành** sử dụng để nhận dạng thread đó. Mỗi thread có một ID duy nhất trong hệ thống.
  
- **Thread ID** trong C++ được sử dụng nội bộ bởi hệ điều hành và có thể dùng để quản lý các thread hoặc lưu trữ chúng trong các container (ví dụ, associative containers).

### 2. **Lấy Thread ID của thread hiện tại**
Để lấy **Thread ID** của **thread hiện tại**, C++ cung cấp phương thức **`std::this_thread::get_id()`**. Phương thức này sẽ trả về ID của thread mà đoạn mã đang thực thi.

### 3. **Lấy Thread ID của đối tượng `std::thread`**
Nếu bạn muốn lấy **Thread ID** của một thread khác (một thread mà bạn đã tạo thông qua đối tượng `std::thread`), bạn có thể sử dụng phương thức **`get_id()`** của đối tượng `std::thread`.

### 4. **Ví dụ mã**:
Dưới đây là ví dụ sử dụng **`std::this_thread::get_id()`** và **`get_id()`** để lấy **Thread ID** của các thread.

```cpp
#include <iostream>
#include <thread>

// Hàm task sẽ hiển thị ID của thread
void hello() {
    std::cout << "Hello from thread with ID " << std::this_thread::get_id() << std::endl;
}

int main() {
    // Hiển thị ID của main thread
    std::cout << "Main thread has ID " << std::this_thread::get_id() << std::endl;

    // Tạo một đối tượng std::thread
    std::thread thr(hello);

    // Hiển thị ID của child thread
    std::cout << "Hello thread has ID " << thr.get_id() << std::endl;

    // Chờ thread hoàn thành
    thr.join();

    return 0;
}
```
5. Kết quả
Chương trình sẽ in ra Thread ID của main thread và child thread:

Main thread has ID 140315820563072
Hello thread has ID 140315819888896
Hello from thread with ID 140315819888896
Tóm tắt:
std::this_thread::get_id() giúp lấy ID của thread hiện tại.
get_id() của đối tượng std::thread giúp lấy ID của thread mà đối tượng đó đại diện.
# README: Pausing Threads in C++ using `std::this_thread::sleep_for()`

## Mô Tả
Trong C++, bạn có thể **tạm dừng một thread** hoặc khiến nó "ngủ" trong một khoảng thời gian nhất định bằng cách sử dụng hàm **`std::this_thread::sleep_for()`**. Điều này giúp kiểm soát tiến trình của các thread và đồng bộ hóa chúng trong chương trình.

### 1. **`std::this_thread::sleep_for()`**
- Hàm **`sleep_for()`** cho phép tạm dừng (sleep) một thread trong một khoảng thời gian nhất định. Thời gian này được xác định thông qua đối số kiểu **`std::chrono::duration`**, một lớp thời gian trong C++11 trở đi.

### 2. **C++14:**
- Trong C++14, bạn có thể sử dụng cú pháp ngắn gọn để chỉ định thời gian ngừng của thread, như:
```cpp
std::this_thread::sleep_for(2s);  // C++14 (sleep for 2 seconds)
# README: Handling Exceptions with `std::thread` Using Try/Catch in C++

## Mô Tả
Khi làm việc với **`std::thread`** trong C++, có thể xảy ra **exception** trong khi thread đang chạy. Để đảm bảo chương trình không gặp lỗi khi thread bị gián đoạn hoặc không được join đúng cách, chúng ta có thể sử dụng **`try/catch block`** để xử lý các exception và đảm bảo thread được xử lý đúng đắn.

### 1. **Cấu trúc Try/Catch với `std::thread`**
- Khi bạn tạo một đối tượng `std::thread`, nếu có khả năng gây ra **exception** trong khi thread đang chạy, bạn cần phải đảm bảo thread được **join** (hoặc **detach**) trong mọi tình huống.
- Sử dụng **`try/catch block`** để đảm bảo chương trình xử lý exception đúng cách và thread không bị bỏ lỡ.
```
### 2. **Cách sử dụng Try/Catch với `std::thread`**
Cấu trúc mã để xử lý exception với **`std::thread`**:
```cpp
std::thread thr(func);  // Tạo một thread
try {
    // Mã có thể gây ra exception
    thr.join();  // Đảm bảo thread được join
} catch (std::exception& e) {
    // Xử lý exception
    thr.join();  // Đảm bảo thread được join ngay cả khi có exception
}
```
# README: Using `thread_guard` to Safely Manage `std::thread` in C++

## Mô Tả
Khi làm việc với **`std::thread`** trong C++, việc đảm bảo rằng **thread** được **join** hoặc **detach** đúng cách là rất quan trọng. Nếu không, bạn có thể gặp phải lỗi hoặc hành vi không xác định khi đối tượng **`std::thread`** bị hủy mà không được xử lý đúng cách.

Một cách an toàn để quản lý đối tượng **`std::thread`** là sử dụng một lớp **`wrapper class`**, như **`thread_guard`**, để đảm bảo thread luôn được **join** khi đối tượng **`thread_guard`** bị hủy, ngay cả khi có exception xảy ra.

## 1. **Lớp `thread_guard`**
- **`thread_guard`** là một lớp bao bọc cho **`std::thread`**. Lớp này giúp đảm bảo rằng đối tượng **`std::thread`** sẽ luôn được **join** (hoặc **detach**) đúng cách khi đối tượng **`thread_guard`** bị hủy.
- Điều này giúp đảm bảo **quản lý thread an toàn** và **tránh lỗi khi không gọi `join()` hoặc `detach()`**.

## 2. **Cấu trúc của `thread_guard`**
Lớp **`thread_guard`** sử dụng một đối tượng **`std::thread`** và đảm bảo rằng **`join()`** luôn được gọi trong destructor của lớp này.

### 2.1 **Constructor**
- Constructor nhận vào một đối tượng **`std::thread`** và chuyển nó thành một **rvalue** bằng cách sử dụng **`std::move()`**.
```cpp
explicit thread_guard(std::thread&& thr) : thr(std::move(thr)) {}

#include <iostream>
#include <thread>
class thread_guard {
private:
    std::thread thr;
public:
    explicit thread_guard(std::thread&& thr) : thr(std::move(thr)) {}
    ~thread_guard() {
        if (thr.joinable()) {
            thr.join();  // Đảm bảo thread được join khi đối tượng bị hủy
        }
    }
};

void func() {
    std::cout << "Task running in a thread!" << std::endl;
}

int main() {
    std::thread thr(func);
    thread_guard tg(std::move(thr));  // Sử dụng thread_guard để đảm bảo thread được join
    // Không cần gọi join() thủ công nữa
    return 0;
}
```
 Giải thích mã:
thread_guard sẽ tự động join thread khi đối tượng tg bị hủy trong hàm main(), ngay cả khi có exception xảy ra.
Việc này giúp giảm thiểu khả năng quên gọi join(), làm mã trở nên an toàn hơn và dễ bảo trì.
4. Lợi ích của thread_guard:
Giúp quản lý thread an toàn, tránh các vấn đề như vẫn có thread đang chạy khi chương trình kết thúc.
Đảm bảo join() luôn được gọi, tránh undefined behavior khi std::thread bị hủy mà không hoàn thành.
Làm mã trở nên gọn gàng và dễ bảo trì hơn khi không phải lo lắng về việc gọi join() ở nhiều nơi.
5. Tóm tắt:
thread_guard là một lớp bao bọc giúp đảm bảo rằng std::thread luôn được join khi không cần gọi thủ công.
Sử dụng std::move() để chuyển đối tượng std::thread vào trong thread_guard.
Cách này giúp làm giảm sự phức tạp và giúp mã trở nên an toàn và dễ bảo trì hơn.

Dưới đây là **README.md** bằng tiếng Việt, bao gồm giải thích về **chia sẻ dữ liệu giữa các luồng**, **data race** và **race condition** trong C++:

```markdown
# README: Hiểu về Đồng Bộ Hóa Luồng, Chia Sẻ Dữ Liệu và Các Vấn Đề Liên Quan trong C++

## 1. **Chia Sẻ Dữ Liệu Giữa Các Luồng**

Trong C++, các luồng trong một chương trình chia sẻ cùng một không gian bộ nhớ, điều này giúp việc chia sẻ dữ liệu giữa các luồng trở nên dễ dàng. Tuy nhiên, có một số điểm cần chú ý để đảm bảo việc chia sẻ dữ liệu hoạt động như mong muốn:

### Các Yêu Cầu Để Dữ Liệu Có Thể Chia Sẻ:
- **Biến toàn cục hoặc tĩnh:** Đối với các hàm luồng toàn cục.
- **Biến tĩnh của lớp:** Đối với các hàm luồng thành viên của lớp.
- **Biến cục bộ được nắm bắt bởi biểu thức lambda:** Nếu được nắm bắt theo tham chiếu, dữ liệu sẽ có thể truy cập từ các luồng khác.

### Ví Dụ: Chia Sẻ Dữ Liệu trong C++ sử dụng Luồng
```cpp
#include <iostream>
#include <thread>

int shared_data = 0;  // Biến toàn cục chia sẻ giữa các luồng

void increase_data() {
    ++shared_data;
    std::cout << "Dữ liệu tăng lên: " << shared_data << std::endl;
}

int main() {
    std::thread t1(increase_data);
    std::thread t2(increase_data);

    t1.join();
    t2.join();

    std::cout << "Giá trị cuối cùng của shared_data: " << shared_data << std::endl;
}
```
- **Lưu ý:** Các luồng chia sẻ quyền truy cập vào biến toàn cục `shared_data`, mà chúng sẽ thay đổi. Các cơ chế đồng bộ hóa phải được áp dụng để tránh tình trạng data race.

## 2. **Data Race**

**Data race** xảy ra khi hai hoặc nhiều luồng truy cập vào cùng một vị trí bộ nhớ đồng thời và ít nhất một trong số các luồng đó thực hiện việc thay đổi dữ liệu. Điều này có thể dẫn đến hành vi không xác định và làm cho chương trình trở nên không ổn định.

### Các Điều Kiện Xảy Ra Data Race:
- **Truy Cập:** Hai hoặc nhiều luồng truy cập vào cùng một vị trí bộ nhớ.
- **Thay Đổi Dữ Liệu:** Ít nhất một luồng thực hiện việc thay đổi dữ liệu.
- **Truy Cập Xung Đột:** Các truy cập này không đồng bộ, có thể gây ra tình trạng truy cập hoặc thay đổi dữ liệu một cách không nhất quán.

### Ví Dụ về Data Race:
```cpp
#include <iostream>
#include <thread>

int shared_counter = 0;

void increment() {
    for (int i = 0; i < 1000; ++i) {
        shared_counter++;  // Đây là một data race
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Giá trị cuối cùng của counter: " << shared_counter << std::endl;  // Không chính xác do data race
}
```
- **Giải pháp:** Để tránh data race, đồng bộ hóa các luồng bằng **mutex** hoặc các công cụ đồng bộ hóa khác.

## 3. **Race Condition**

**Race condition** xảy ra khi kết quả của một chương trình phụ thuộc vào thứ tự hoặc thời gian thực thi của các luồng. Kết quả cuối cùng không thể đoán trước được vì các luồng có thể được lên lịch theo thứ tự không xác định.

### Ví Dụ:
- **Ví dụ với bảng cơ sở dữ liệu:** Một client xóa một bảng trong cơ sở dữ liệu, trong khi một client khác chèn dữ liệu vào bảng đó. Tùy thuộc vào thời gian thực thi của các luồng, kết quả cuối cùng có thể không chính xác.

### Ví Dụ về Race Condition:
```cpp
#include <iostream>
#include <thread>

void process_data(int client_id) {
    // Mô phỏng tình huống race condition
    std::cout << "Client " << client_id << " đang xử lý dữ liệu." << std::endl;
    // Các vấn đề thời gian có thể dẫn đến kết quả không chính xác
}

int main() {
    std::thread t1(process_data, 1);
    std::thread t2(process_data, 2);

    t1.join();
    t2.join();
}
```
- **Giải pháp:** Để tránh race condition, đảm bảo rằng các luồng truy cập vào tài nguyên chia sẻ được đồng bộ hóa, ví dụ, sử dụng **mutex** hoặc **locks**.

## 4. **Vị Trí Bộ Nhớ và Đối Tượng Phức Hợp**

Trong C++, **vị trí bộ nhớ** là nơi lưu trữ của các đối tượng kiểu scalar, như biến hoặc đối tượng. Khi sử dụng **đối tượng phức hợp** (ví dụ, các container STL), cần phải đảm bảo rằng nhiều luồng không sửa đổi cùng một đối tượng mà không đồng bộ hóa.

### Ví Dụ:
```cpp
#include <vector>
#include <mutex>
#include <thread>

std::vector<int> shared_data;
std::mutex mtx;

void append_data(int value) {
    std::lock_guard<std::mutex> lock(mtx);
    shared_data.push_back(value);
}

int main() {
    std::thread t1(append_data, 1);
    std::thread t2(append_data, 2);

    t1.join();
    t2.join();

    // Dữ liệu được chia sẻ một cách an toàn giữa các luồng
}
```

### Các Điểm Cần Lưu Ý:
- **Data Race:** Tránh bằng cách đảm bảo đồng bộ hóa quyền truy cập vào dữ liệu chia sẻ.
- **Race Condition:** Đảm bảo rằng thứ tự thực thi hoặc thời gian của các luồng không ảnh hưởng đến kết quả, sử dụng các công cụ đồng bộ hóa như **mutex**.
- **Vị Trí Bộ Nhớ:** Cẩn thận khi các luồng sửa đổi dữ liệu chia sẻ, đặc biệt là trong các đối tượng phức hợp như container STL.

## 5. **Cách Tránh Data Races và Race Conditions:**

- **Mutexes và Locks:** Sử dụng mutexes hoặc các cơ chế khóa khác để đảm bảo quyền truy cập độc quyền vào tài nguyên chia sẻ.
- **Các Toán Tử Atomic:** Cân nhắc sử dụng các toán tử atomic cho các kiểu dữ liệu đơn giản, vốn đã an toàn với luồng.
- **Đồng Bộ Hóa Luồng:** Sử dụng các kỹ thuật đồng bộ hóa như barriers, condition variables hoặc futures để quản lý thứ tự thực thi của các luồng.

## 6. **Kết Luận:**
Hiểu và ngăn ngừa **data races** và **race conditions** là rất quan trọng để viết các chương trình C++ đa luồng an toàn. Các kỹ thuật đồng bộ hóa đúng đắn và quản lý bộ nhớ giúp đảm bảo tính ổn định và độ chính xác của chương trình khi làm việc với nhiều luồng.

Để có thêm thông tin, bạn có thể tham khảo tài liệu về **`std::thread`**, **`std::mutex`**, và **`std::atomic`** trong **Thư Viện Chuẩn C++** để tìm hiểu kỹ hơn về các công cụ đồng bộ hóa luồng.


# Hướng dẫn sử dụng Mutex trong C++

## 1. Giới thiệu về `std::mutex`

C++ cung cấp lớp `std::mutex` để sử dụng các mutex, giúp đồng bộ hóa các luồng (threads) trong chương trình. Mutex là công cụ giúp các luồng truy cập vào vùng nhớ dùng chung một cách an toàn.

- Lớp `std::mutex` được định nghĩa trong thư viện `<mutex>`.
- Một đối tượng mutex phải có khả năng nhìn thấy từ tất cả các hàm nhiệm vụ (task functions) sử dụng nó.
- Đối tượng mutex phải được định nghĩa ngoài các hàm nhiệm vụ.

## 2. Sử dụng `std::mutex`

### a. Cách định nghĩa và sử dụng `std::mutex`

- Đối tượng mutex có thể là biến toàn cục (global) hoặc tĩnh (static), với hàm nhiệm vụ toàn cục (global task function).
- Đối tượng mutex có thể là thành viên lớp (class member) nếu hàm nhiệm vụ là thành viên của lớp đó.
- Đối tượng mutex có thể được lambda function bắt giữ bằng tham chiếu (by reference).

### b. Giao diện của `std::mutex`

Mutex cung cấp ba phương thức chính:

- **lock()**: Cố gắng khóa mutex. Nếu không thành công, sẽ đợi cho đến khi mutex được khóa.
- **try_lock()**: Cố gắng khóa mutex và trả về ngay lập tức nếu không thể khóa mutex.
- **unlock()**: Giải phóng khóa mutex.

### c. Ví dụ sử dụng `std::mutex`

```cpp
#include <iostream>
#include <thread>
#include <mutex>

// Định nghĩa mutex toàn cục
std::mutex task_mutex;

void task(const std::string& str) {
    for (int i = 0; i < 5; ++i) {
        task_mutex.lock(); // Khóa mutex trước khi vào phần mã quan trọng
        std::cout << str[i]; // Phần mã quan trọng
        task_mutex.unlock(); // Giải phóng mutex sau khi hoàn thành phần mã quan trọng
    }
}

int main() {
    std::thread thr1(task, "abc");
    std::thread thr2(task, "def");
    std::thread thr3(task, "xyz");

    thr1.join();
    thr2.join();
    thr3.join();

    return 0;
}

It looks like you are asking for a README related to your code on thread synchronization with `std::mutex` and a vector class. Here's a basic example of what such a README might look like, in both English and Vietnamese:

---

## README: C++ Thread Synchronization Using `std::mutex` for `std::vector`

### Overview

This project demonstrates how to use a `std::mutex` to safely manage concurrent access to a `std::vector` in a multi-threaded environment. It wraps the `std::vector` in a class that synchronizes access to it using mutexes. The class ensures that only one thread can access the critical section (the vector) at a time.

### Key Concepts

1. **`std::mutex`**: 
   - A `std::mutex` is used to ensure exclusive access to shared resources (in this case, the `std::vector`).
   - Threads lock the mutex before accessing the vector and unlock it after the critical section is done.

2. **`std::thread`**: 
   - Threads are created to demonstrate concurrent access to the `std::vector`. Each thread will modify and print the vector.
   
3. **Critical Section**: 
   - The code inside `push_back()` and `print()` is the critical section, where only one thread is allowed to execute at a time.

### Code

```cpp
#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std::literals;

class Vector {
    std::mutex mut;
    std::vector<int> vec;
public:
    void push_back(const int& i) {
        mut.lock();
        vec.push_back(i);
        mut.unlock();
    }

    void print() {
        mut.lock();
        for (auto i : vec) {
            std::cout << i << ", ";
        }
        mut.unlock();
    }
};

void func(Vector& vec) {
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i);
        std::this_thread::sleep_for(50ms);
        vec.print();
    }
}

int main() {
    Vector vec;
    std::thread thr1(func, std::ref(vec));
    std::thread thr2(func, std::ref(vec));
    std::thread thr3(func, std::ref(vec));

    thr1.join(); thr2.join(); thr3.join();
}
```

### Explanation

- The `Vector` class has a private `std::mutex` that is used to lock and unlock access to the vector.
- The `push_back` function locks the mutex before modifying the vector and unlocks it after.
- The `print` function locks the mutex while printing the vector to avoid concurrent modifications.
- Three threads are created in `main()`, each running the `func()` function, which modifies and prints the vector.

### How to Compile

1. Save the code to a file, e.g., `thread_sync_vector.cpp`.
2. Compile the code with a C++11 or later compatible compiler:
   ```bash
   g++ -std=c++11 thread_sync_vector.cpp -o thread_sync_vector -pthread
   ```
3. Run the program:
   ```bash
   ./thread_sync_vector
   ```

---

## README: Đồng Bộ Luồng C++ Sử Dụng `std::mutex` cho `std::vector`

### Tổng Quan

Dự án này minh họa cách sử dụng `std::mutex` để quản lý truy cập đồng thời an toàn đến `std::vector` trong môi trường đa luồng. Nó bọc `std::vector` trong một lớp với cơ chế đồng bộ hóa sử dụng mutex. Lớp này đảm bảo rằng chỉ một luồng có thể truy cập vào phần chia sẻ (vector) tại một thời điểm.

### Các Khái Niệm Chính

1. **`std::mutex`**:
   - `std::mutex` được sử dụng để đảm bảo truy cập độc quyền vào tài nguyên chia sẻ (trong trường hợp này là `std::vector`).
   - Các luồng khóa mutex trước khi truy cập vector và mở khóa sau khi xong phần chia sẻ.

2. **`std::thread`**:
   - Các luồng được tạo ra để minh họa việc truy cập đồng thời đến `std::vector`. Mỗi luồng sẽ thay đổi và in ra vector.

3. **Phần Chia Sẻ (Critical Section)**:
   - Mã bên trong `push_back()` và `print()` là phần chia sẻ, nơi chỉ một luồng được phép thực thi tại một thời điểm.

### Mã Nguồn

```cpp
#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std::literals;

class Vector {
    std::mutex mut;
    std::vector<int> vec;
public:
    void push_back(const int& i) {
        mut.lock();
        vec.push_back(i);
        mut.unlock();
    }

    void print() {
        mut.lock();
        for (auto i : vec) {
            std::cout << i << ", ";
        }
        mut.unlock();
    }
};

void func(Vector& vec) {
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i);
        std::this_thread::sleep_for(50ms);
        vec.print();
    }
}

int main() {
    Vector vec;
    std::thread thr1(func, std::ref(vec));
    std::thread thr2(func, std::ref(vec));
    std::thread thr3(func, std::ref(vec));

    thr1.join(); thr2.join(); thr3.join();
}
```

### 

- Lớp `Vector` có một `std::mutex` riêng để khóa và mở khóa truy cập vào vector.
- Hàm `push_back` khóa mutex trước khi thay đổi vector và mở khóa sau khi xong.
- Hàm `print` khóa mutex trong khi in ra vector để tránh việc thay đổi đồng thời.
- Ba luồng được tạo trong `main()`, mỗi luồng thực thi hàm `func()`, thay đổi và in vector.

### Cách Biên Dịch

1. Lưu mã vào một tệp, ví dụ `thread_sync_vector.cpp`.
2. Biên dịch mã với trình biên dịch C++11 hoặc cao hơn:
   ```bash
   g++ -std=c++11 thread_sync_vector.cpp -o thread_sync_vector -pthread
   ```
3. Chạy chương trình:
   ```bash
   ./thread_sync_vector
   ```

---

Dưới đây là bản hướng dẫn về việc sử dụng các lớp mutex trong C++:

## Các lớp `std::mutex` và `std::lock_guard`

1. **Khi có ngoại lệ trong phần mã khóa**:
   - Nếu một ngoại lệ được ném trong phần mã khóa (critical section), `unlock` không bao giờ được gọi, khiến mutex không được giải phóng.
   - Các luồng khác đang chờ khóa mutex sẽ bị chặn và chương trình có thể bị "block" hoàn toàn.

2. **Sử dụng `std::lock_guard` để tránh xung đột**:
   - `std::lock_guard` là một lớp "wrapper" giúp tự động khóa và mở khóa mutex khi đối tượng `std::lock_guard` được tạo ra và hủy.
   - Khi một đối tượng `std::lock_guard` được tạo, mutex sẽ tự động được khóa, và khi đối tượng này bị hủy (ra khỏi phạm vi), mutex sẽ tự động được mở khóa.

3. **Ví dụ về sử dụng `std::lock_guard`**:
   - Khi sử dụng `std::lock_guard`, bạn không cần phải gọi thủ công `lock` và `unlock`. Điều này giúp giảm thiểu rủi ro do quên mở khóa mutex sau khi thực hiện thao tác.

**Ví dụ mã nguồn**:
```cpp
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <string>

std::mutex print_mutex;

void task(std::string str)
{
    for (int i = 0; i < 5; ++i) {
        try {
            // Tạo đối tượng std::lock_guard
            std::lock_guard<std::mutex> lck_guard(print_mutex);

            // Bắt đầu phần mã khóa
            std::cout << str[0] << str[1] << str[2] << std::endl;

            // Phần mã khóa ném ra ngoại lệ
            throw std::exception();  // Ném ngoại lệ
        }
        catch (std::exception& e) {
            std::cout << "Ngoại lệ bắt được: " << e.what() << '\n';
        }
    }
}

int main()
{
    std::thread thr1(task, "abc");
    std::thread thr2(task, "def");
    std::thread thr3(task, "xyz");

    thr1.join(); thr2.join(); thr3.join();  // Đảm bảo các luồng hoàn thành
}
```

4. **Lợi ích của `std::lock_guard`**:
   - Tự động quản lý việc khóa và mở khóa mutex, giúp mã nguồn ngắn gọn và dễ bảo trì hơn.
   - Giảm thiểu khả năng xảy ra lỗi, như quên gọi `unlock` hoặc quên kiểm tra khi ngoại lệ được ném ra.
Dưới đây là nội dung file `README.md` bạn yêu cầu, với phần giải thích bằng tiếng Việt:

```markdown
# Hướng dẫn về Mutex và Đối tượng Lock trong C++

## Tổng quan về Mutex

Mutex (Mutual Exclusion) là một cơ chế đồng bộ giúp ngăn chặn truy cập đồng thời vào các tài nguyên chung, từ đó tránh được các vấn đề liên quan đến race condition khi nhiều luồng thực thi.

## std::mutex

`std::mutex` là lớp cung cấp cơ chế khóa (lock) trong thư viện chuẩn C++ để bảo vệ các tài nguyên chia sẻ khỏi sự truy cập đồng thời từ các luồng khác nhau. Để sử dụng `std::mutex`, ta phải đảm bảo rằng mỗi luồng sử dụng nó phải gọi `lock()` trước khi truy cập tài nguyên và gọi `unlock()` sau khi hoàn thành.

### Các vấn đề khi có ngoại lệ trong Critical Section

Khi một ngoại lệ được ném trong critical section (vùng mã cần được bảo vệ), mutex sẽ không được giải phóng nếu ta không gọi `unlock()` một cách rõ ràng. Điều này có thể dẫn đến tình trạng "deadlock", nơi các luồng khác không thể truy cập mutex và sẽ bị khóa vĩnh viễn.

## std::lock_guard và std::unique_lock

### std::lock_guard

`std::lock_guard` là một lớp quản lý tự động giúp khóa mutex trong một phạm vi nhất định và tự động giải phóng mutex khi đối tượng `lock_guard` ra khỏi phạm vi (scope). Điều này giúp tránh tình trạng quên giải phóng mutex khi có ngoại lệ xảy ra.

#### Ví dụ:

```cpp
std::mutex task_mutex;

void task() {
    std::lock_guard<std::mutex> lock(task_mutex);  // Mutex được khóa tự động
    // Phần mã quan trọng
    // Mutex được giải phóng khi lock_guard ra khỏi phạm vi
}
```

### std::unique_lock

`std::unique_lock` tương tự như `std::lock_guard`, nhưng linh hoạt hơn vì nó cho phép gọi `unlock()` thủ công, điều này hữu ích khi cần phải giải phóng mutex trước khi đối tượng `unique_lock` ra khỏi phạm vi.

#### Ví dụ:

```cpp
std::mutex task_mutex;

void task() {
    std::unique_lock<std::mutex> lock(task_mutex);  // Mutex được khóa tự động
    // Phần mã quan trọng
    lock.unlock();  // Mutex được giải phóng thủ công
    // Thực hiện thêm mã không quan trọng
}
```

### So sánh std::lock_guard và std::unique_lock

- `std::lock_guard` đơn giản và hiệu quả khi cần đảm bảo khóa mutex trong suốt phạm vi của một khối mã.
- `std::unique_lock` cung cấp nhiều tính năng linh hoạt hơn, nhưng tiêu tốn tài nguyên hơn một chút so với `std::lock_guard`.

## std::unique_lock với Move Semantics

- `std::unique_lock` không thể được sao chép, nhưng có thể di chuyển. Khi di chuyển, khóa mutex sẽ được chuyển sang đối tượng `unique_lock` mới mà không tạo thêm bản sao.

## Mutex Wrapper Class

Để đảm bảo thread safety cho các đối tượng phức tạp như `std::vector`, ta có thể tạo ra lớp bao bọc (wrapper) có sử dụng `std::mutex` bên trong. Lớp này giúp quản lý khóa mutex một cách tự động.

#### Ví dụ về lớp bao bọc `std::vector`:

```cpp
#include <mutex>
#include <vector>

class ThreadSafeVector {
    std::mutex mut;
    std::vector<int> vec;
    
public:
    void push_back(int value) {
        std::lock_guard<std::mutex> lock(mut);
        vec.push_back(value);
    }
    
    void print() {
        std::lock_guard<std::mutex> lock(mut);
        for (const auto& val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};
```

## Lớp Wrapper cho std::mutex

C++ cung cấp các lớp như `std::lock_guard`, `std::unique_lock` để giúp bảo vệ mutex mà không cần phải quản lý thủ công việc khóa và giải phóng mutex trong mã của bạn.

## Kết luận

- Sử dụng `std::lock_guard` khi bạn cần khóa mutex trong toàn bộ phạm vi của một hàm hoặc khối mã.
- Sử dụng `std::unique_lock` nếu bạn cần linh hoạt hơn với các thao tác khóa và giải phóng mutex trong phạm vi.

Nếu bạn cần thêm bất kỳ sự trợ giúp nào, đừng ngần ngại yêu cầu!
```

