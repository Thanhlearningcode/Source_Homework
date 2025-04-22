# Copy/Move Constructors & Assignment Operators in Inheritance (C++)

This project demonstrates the correct usage and importance of copy constructors, move constructors, and assignment operators in class inheritance.

## 💡 Why is this important?

When using inheritance in C++, special attention must be paid to how objects are **copied** or **moved**, especially when:
- The base class manages dynamic resources (e.g., `new`, raw pointers, file handles).
- You need **deep copy** behavior instead of shallow copying.
- You want to optimize performance using **move semantics** (C++11+).

## 🧱 Structure

- `Base` class:
  - Contains a raw pointer to simulate resource management.
  - Implements: copy constructor, move constructor, copy assignment, and move assignment.
  
- `Derived` class:
  - Inherits from `Base`.
  - Adds an additional member (e.g., a `std::string`).
  - Explicitly implements the same special member functions to ensure proper behavior.

## 🛠️ Key Concepts Demonstrated

| Feature | Description |
|--------|-------------|
| `Base(const Base&)` | Deep copies the resource. |
| `Base(Base&&)` | Moves the pointer, avoids copy overhead. |
| `Base& operator=(const Base&)` | Deep copy assignment. |
| `Base& operator=(Base&&)` | Move assignment. |
| `Derived(...)` | Calls corresponding `Base` constructor, handles `Derived`-specific members. |

## 📌 Important Notes

- If you **don’t define** these special functions, the compiler may generate default ones that can **lead to shallow copies**, especially problematic with raw pointers.
- Always **call base class versions** of constructors/operators inside `Derived` to ensure the base portion is handled correctly.

## 📂 Files

- `main.cpp`: Contains all class definitions and test code.

## 🔧 How to Build

```bash
g++ -std=c++17 -o inheritance_example main.cpp
./inheritance_example
```

## 🧪 Example Code

```cpp
#include <iostream>
#include <string>
using namespace std;

class Base {
protected:
    int* data;
public:
    Base(int val = 0) : data(new int(val)) {
        cout << "Base constructor\n";
    }

    Base(const Base& other) : data(new int(*other.data)) {
        cout << "Base copy constructor\n";
    }

    Base(Base&& other) noexcept : data(other.data) {
        other.data = nullptr;
        cout << "Base move constructor\n";
    }

    Base& operator=(const Base& other) {
        cout << "Base copy assignment\n";
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    Base& operator=(Base&& other) noexcept {
        cout << "Base move assignment\n";
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    virtual ~Base() {
        cout << "Base destructor\n";
        delete data;
    }
};

class Derived : public Base {
    string name;
public:
    Derived(int val, const string& n) : Base(val), name(n) {
        cout << "Derived constructor\n";
    }

    Derived(const Derived& other) : Base(other), name(other.name) {
        cout << "Derived copy constructor\n";
    }

    Derived(Derived&& other) noexcept : Base(std::move(other)), name(std::move(other.name)) {
        cout << "Derived move constructor\n";
    }

    Derived& operator=(const Derived& other) {
        cout << "Derived copy assignment\n";
        if (this != &other) {
            Base::operator=(other);
            name = other.name;
        }
        return *this;
    }

    Derived& operator=(Derived&& other) noexcept {
        cout << "Derived move assignment\n";
        if (this != &other) {
            Base::operator=(std::move(other));
            name = std::move(other.name);
        }
        return *this;
    }

    ~Derived() {
        cout << "Derived destructor\n";
    }
};

int main() {
    Derived d1(42, "Object A");
    Derived d2 = d1; // Copy constructor
    Derived d3 = std::move(d1); // Move constructor

    d2 = d3; // Copy assignment
    d3 = std::move(d2); // Move assignment

    return 0;
}
```

## 📚 References

- [cppreference.com - Special Member Functions](https://en.cppreference.com/w/cpp/language/special_member_functions)
- [Rule of Five in C++](https://en.cppreference.com/w/cpp/language/rule_of_three)

