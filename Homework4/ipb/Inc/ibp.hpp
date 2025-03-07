#ifndef IPB_ALGORITHM_HPP
#define IPB_ALGORITHM_HPP
#include "vector.hpp" //< Thư viện từ bên folder named_vector
#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>

namespace ipb {

/*Tính tổng các phần tử trong named_vector*/ 
int accmulate (const name_vector<int>& vec);

/*Đếm số lần xuất hiện của một phần tử*/ 
int count     (const name_vector<int>& vec, int value);

/*Kiểm tra tất cả phần tử có phải số chẵn không*/ 
bool all_even (const name_vector<int>& vec);

/*Giới hạn giá trị các phần tử trong khoảng [min, max]*/ 
void clamp    (name_vector<int>& vec, int min, int max);

/*Điền tất cả phần tử bằng một giá trị*/ 
void fill     (name_vector<int>& vec, int value);

/*Kiểm tra xem một giá trị có tồn tại không*/ 
bool find     (const name_vector<int>& vec, int value);

/*In nội dung container*/ 
void print    (const name_vector<int>& vec);

/*Chuyển tên container thành chữ in hoa/ Chuyển tên container thành chữ in hoa*/
void toupper  (name_vector<int>& vec);

/*Sắp xếp phần tử trong container*/ 
void sort     (name_vector<int>& vec);

/*Xoay phần tử trong container*/ 
void rotate   (name_vector<int>& vec, int positions);

/*Đảo ngược danh sách phần tử*/ 
void reverse  (name_vector<int>& vec);

    } 

#endif /*IPB_ALGORITHM_HPP*/
