# C++ File I/O: Reading and Writing Files

## 1. Giới thiệu
C++ cung cấp thư viện `<fstream>` để làm việc với tệp. Có hai luồng chính:
- `ifstream` (input file stream) để đọc tệp.
- `ofstream` (output file stream) để ghi tệp.

## 2. Ghi vào tệp với `ofstream`
Dưới đây là một ví dụ ghi dữ liệu vào một tệp văn bản:

```cpp
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    string filename = "out.txt";
    ofstream outfile(filename); // Mở tệp để ghi

    if (!outfile.is_open()) {
        return EXIT_FAILURE;
    }

    double a = 1.123123123;
    outfile << "Just string" << endl;
    outfile << setprecision(20) << a << endl; // Ghi số thực với độ chính xác cao
    
    outfile.close(); // Đóng tệp sau khi ghi xong
    return 0;
}
```

### Giải thích:
- Mở tệp `out.txt` bằng `ofstream`.
- Ghi một chuỗi và một số thực vào tệp.
- Sử dụng `setprecision(20)` để đảm bảo độ chính xác của số thực.
- Gọi `outfile.close()` để đóng tệp sau khi ghi xong.

---

## 3. Đọc từ tệp với `ifstream`
Ví dụ đọc dữ liệu từ tệp:

```cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in("test_cols.txt", ios_base::in); // Mở tệp để đọc

    if (!in.is_open()) {
        return EXIT_FAILURE;
    }

    int i;
    double a, b;
    string s;
    
    while (in >> i >> a >> s >> b) { // Đọc dữ liệu theo định dạng
        cout << i << ", " << a << ", " << s << ", " << b << endl;
    }

    in.close(); // Đóng tệp sau khi đọc xong
    return 0;
}
```

### Giải thích:
- Mở tệp `test_cols.txt` bằng `ifstream`.
- Đọc dữ liệu theo định dạng: số nguyên, số thực, chuỗi, số thực.
- In dữ liệu ra màn hình.
- Gọi `in.close()` để đóng tệp.

## 4. Lưu ý quan trọng
- Kiểm tra `is_open()` trước khi đọc hoặc ghi để đảm bảo tệp được mở thành công.
- Luôn đóng tệp sau khi sử dụng để tránh lỗi.
- Đối với các tệp nhị phân, có thể sử dụng `ios::binary` để đọc/ghi ở chế độ nhị phân.

## 5. Kết luận
- `ofstream` dùng để ghi tệp.
- `ifstream` dùng để đọc tệp.
- Đảm bảo kiểm tra lỗi khi mở tệp để tránh sự cố khi đọc/ghi dữ liệu.

---
# Hướng dẫn Đọc/Ghi Tệp Nhị Phân trong C++

## 1. Giới thiệu
Tệp nhị phân (binary file) lưu trữ dữ liệu dưới dạng dãy byte, giúp việc đọc/ghi dữ liệu nhanh hơn và tiết kiệm dung lượng so với tệp văn bản. Tuy nhiên, tệp nhị phân không thể đọc trực tiếp bằng trình soạn thảo văn bản.

## 2. Cách ghi tệp nhị phân
### Ví dụ ghi dữ liệu vào tệp nhị phân:
```cpp
#include <fstream>  // Thư viện xử lý file
#include <vector>
using namespace std;

int main() {
    string file_name = "image.dat";
    ofstream file(file_name, ios_base::out | ios_base::binary);

    int rows = 2, cols = 3;
    vector<float> vec = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

    file.write(reinterpret_cast<char*>(&rows), sizeof(rows));
    file.write(reinterpret_cast<char*>(&cols), sizeof(cols));
    file.write(reinterpret_cast<char*>(&vec.front()), vec.size() * sizeof(float));

    return 0;
}
```

### Giải thích:
- Mở tệp ở chế độ `binary` bằng `ofstream`.
- Ghi số hàng (`rows`) và số cột (`cols`) trước.
- Ghi dữ liệu mảng `vector<float>` vào tệp bằng `reinterpret_cast<char*>`.

## 3. Cách đọc tệp nhị phân
### Ví dụ đọc dữ liệu từ tệp nhị phân:
```cpp
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string file_name = "image.dat";
    int r = 0, c = 0;
    ifstream in(file_name, ios_base::in | ios_base::binary);

    if (!in) { return EXIT_FAILURE; }

    in.read(reinterpret_cast<char*>(&r), sizeof(r));
    in.read(reinterpret_cast<char*>(&c), sizeof(c));

    cout << "Kích thước: " << r << " x " << c << endl;
    vector<float> data(r * c, 0);

    in.read(reinterpret_cast<char*>(&data.front()), data.size() * sizeof(float));

    for (float d : data) { cout << d << " "; }
    cout << endl;
    return 0;
}
```

### Giải thích:
- Mở tệp ở chế độ `binary` bằng `ifstream`.
- Đọc số hàng (`r`) và số cột (`c`).
- Cấp phát bộ nhớ `vector<float>` dựa trên kích thước đọc được.
- Đọc dữ liệu vào mảng và hiển thị ra màn hình.

## 4. Lưu ý quan trọng
- Khi ghi dữ liệu, cần đảm bảo **ghi theo đúng thứ tự** để khi đọc lại không bị lỗi.
- Sử dụng `reinterpret_cast<char*>` để chuyển đổi kiểu dữ liệu.
- Kiểm tra lỗi khi mở tệp để tránh lỗi chương trình.

Sử dụng directory_iterator để duyệt thư mục

Ví dụ duyệt thư mục:

#include <filesystem>
#include <fstream>
#include <iostream>
using namespace std;
namespace fs = std::filesystem;

int main() {
    fs::create_directories("sandbox/a/b");
    ofstream("sandbox/file1.txt");
    ofstream("sandbox/file2.txt");

    for (auto& p : fs::directory_iterator("sandbox")) {
        cout << p.path() << '\n';
    }

    fs::remove_all("sandbox");
    return 0;
}

Giải thích:

fs::create_directories("sandbox/a/b"): Tạo thư mục lồng nhau.

Tạo hai tệp file1.txt và file2.txt trong thư mục sandbox.

Sử dụng fs::directory_iterator để lặp qua các phần tử trong thư mục sandbox và in đường dẫn của chúng.

fs::remove_all("sandbox"): Xóa toàn bộ thư mục sandbox sau khi thực thi.

5. Sử dụng path::filename() để lấy tên tệp từ đường dẫn

Ví dụ:

# README

## Mô tả đồng án

Chương trình minh họa cách lấy tên tệp tin từ các đường dẫn sử dụng thư viện `<filesystem>` trong C++17 trở lên.

## Mã nguồn

```cpp
#include <filesystem>
#include <iostream>
using namespace std;
namespace fs = std::filesystem;

int main() {
    cout << fs::path("/foo/bar.txt").filename() << '\n'
         << fs::path("/foo/.bar").filename() << '\n'
         << fs::path("/foo/bar/").filename() << '\n'
         << fs::path("/foo/.").filename() << '\n'
         << fs::path("/foo/..").filename() << '\n';
    return 0;
}
```

## Cách biên dịch và chạy chương trình

Yêu cầu:
- Trình biên dịch hỗ trợ C++17 trở lên (GCC 8+, Clang 7+, MSVC 2017+)

Biên dịch với g++:
```sh
 g++ -std=c++17 -o path_example path_example.cpp
```

Chạy chương trình:
```sh
 ./path_example
```

## Giải thích kết quả
Chương trình tạo các đối tượng `fs::path` từ các đường dẫn khác nhau và trích xuất tên tệp tin bằng hàm `.filename()`. Dưới đây là các trường hợp:

1. `fs::path("/foo/bar.txt").filename()` trả về `"bar.txt"` vì đây là tên tệp.
2. `fs::path("/foo/.bar").filename()` trả về `".bar"` vì đây là một tệp ẩn.
3. `fs::path("/foo/bar/").filename()` trả về chuỗi rỗng vì đường dẫn kết thúc bằng dấu `/`.
4. `fs::path("/foo/.").filename()` trả về `"."` đại diện cho thư mục hiện tại.
5. `fs::path("/foo/..").filename()` trả về `".."` đại diện cho thư mục cha.

## Tham khảo
- [std::filesystem::path](https://en.cppreference.com/w/cpp/filesystem/path)


Kết quả:

"bar.txt"
".bar"
""
"."
".."

6. Lưu ý quan trọng

Khi ghi dữ liệu, cần đảm bảo ghi theo đúng thứ tự để khi đọc lại không bị lỗi.

Sử dụng reinterpret_cast<char*> để chuyển đổi kiểu dữ liệu.

Kiểm tra lỗi khi mở tệp để tránh lỗi chương trình.
## 5. Kết luận
Việc sử dụng tệp nhị phân giúp lưu trữ dữ liệu hiệu quả hơn, đặc biệt khi làm việc với số liệu lớn hoặc dữ liệu không cần phải đọc dưới dạng văn bản.

---



## 6. Tham khảo
- [C++ Reference - `<fstream>`](https://cplusplus.com/reference/fstream/)

