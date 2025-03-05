#!/usr/bin/env bash

# Tạo thư mục build nếu chưa có
mkdir -p build

# Biên dịch các file .cpp thành các file .o
g++ -c -I./include src/sum.cpp -o build/sum.o
g++ -c -I./include src/subtract.cpp -o build/subtract.o
g++ -c -I./include src/main.cpp -o build/main.o

# Tạo thư viện tĩnh libipb_arithmetic.a
ar rcs build/libipb_arithmetic.a build/sum.o build/subtract.o

# Biên dịch chương trình chính và liên kết với thư viện
g++ build/main.o -Lbuild -lipb_arithmetic -o build/main_exec

# Tạo thư mục results nếu chưa có
mkdir -p results/bin results/lib

# Di chuyển thư viện và file thực thi vào results/
mv build/libipb_arithmetic.a results/lib/
mv build/main_exec results/bin/

echo "Build hoàn tất!"

