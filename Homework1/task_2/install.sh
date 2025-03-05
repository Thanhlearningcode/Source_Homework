#!/bin/bash

# Tạo thư mục cài đặt nếu chưa có
mkdir -p install

# Copy các file đã biên dịch vào thư mục install
cp -r build/lib install/
cp -r build/bin install/

