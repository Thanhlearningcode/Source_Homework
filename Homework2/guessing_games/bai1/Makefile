# Tên trình biên dịch
CXX = g++

# Cờ biên dịch
CXXFLAGS = -Wall -Wextra -std=c++11

# Tệp nguồn và tệp đối tượng
SRC = main.cpp
OBJ = main.o

# Tên tệp thực thi
TARGET = main

# Quy tắc biên dịch tệp thực thi
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Quy tắc biên dịch tệp đối tượng
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Quy tắc dọn dẹp
clean:
	rm -f $(OBJ) $(TARGET)

