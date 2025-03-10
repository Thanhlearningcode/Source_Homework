# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Directories
SRC_DIR = src
TESTS_DIR = tests
BUILD_DIR = build

# Source and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

TEST_FILES = $(wildcard $(TESTS_DIR)/*.cpp)
TEST_OBJ_FILES = $(patsubst $(TESTS_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(TEST_FILES))

# Output test executable
TEST_EXEC = $(BUILD_DIR)/tests

# Default rule: build tests
all: $(TEST_EXEC)

# Compile test program
$(TEST_EXEC): $(OBJ_FILES) $(TEST_OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lgtest -lgtest_main -pthread

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files
$(BUILD_DIR)/%.o: $(TESTS_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build directory
clean:
	rm -rf $(BUILD_DIR)

# Run tests
test: $(TEST_EXEC)
	@echo "Running tests..."
	./$(TEST_EXEC)

.PHONY: all clean test
