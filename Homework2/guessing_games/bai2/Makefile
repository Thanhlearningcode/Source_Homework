# Trình biên dịch (sử dụng g++ để liên kết được cả file C và C++)
CXX = g++

# Thư mục chứa file header
INCDIR = Inc

# Cờ biên dịch: -I chỉ định thư mục chứa header, -Wall, -Wextra cảnh báo đầy đủ
CXXFLAGS = -I$(INCDIR) -Wall -Wextra -std=c++11

# Thư mục chứa file nguồn
SRCDIR = Src

# Các file nguồn
SOURCES = $(SRCDIR)/main.cpp $(SRCDIR)/file.c

# Các file đối tượng (mỗi file .cpp và .c được biên dịch thành .o)
OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS := $(OBJECTS:.c=.o)

# Tên file thực thi
TARGET = task

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Quy tắc biên dịch cho file .cpp
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Quy tắc biên dịch cho file .c
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(SRCDIR)/*.o $(TARGET)

