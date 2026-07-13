# fucker_io
[简体中文（zh-cn）](./README.zh-cn.md)
## Basic Information
- Header File: fucker_io.h
- Developer: sliperman
- Studio: buliuming
- Version: 0.1.0
## Quick Start
### Integration
Place fucker_input.h in your project directory and include it in your code:
```
#include "fucker_input.h"
using namespace fucker_io; // Import namespace for simplified usage
```
## Core API Reference
### 1. Read Single Variable input_nt<T>()
Reads a single primitive data type from standard input and returns it.
```
int num = input_nt<int>();
```
### 2. Batch Container Reading ips(cont& c)
Iterates through the provided container, sequentially reading data from standard input and assigning it to the elements.
```
std::vector<int> vec(5);
ips(vec); // Automatically reads 5 integers and fills the vector
```
### 3. Iterator Range Reading input_range(itera fs, itera ls)
Reads data within a specified iterator range.
```
std::vector<int> vec(10);
input_range(vec.begin(), vec.begin() + 5); // Reads only the first 5 elements
```
### 4. Functor Reading input_sequence<_Tp>
Reads container data in the form of a function object.
```
std::vector<int> vec(5);
input_sequence<std::vector<int>>()(vec);
```
### 5. Custom Input Logic input_cus<T>(F&& functor)
Passes a custom Lambda or function object to apply specific processing or validation to the read data.
```
int positive_num = input_cus<int>([](int& val) {
    std::cin >> val;
    if (val <= 0) throw std::runtime_error("Value must be a positive integer");
});
```
## Important Notes & Exception Handling
#### 1.Exception Throwing: When input format mismatches occur, the library functions will throw a std::runtime_error. It is highly recommended to wrap calls in try-catch blocks.
#### 2.Buffer Clearing: The current version does not automatically clear the std::cin error flags and buffer upon throwing an exception. After catching an exception, you must manually clear the buffer, otherwise subsequent inputs will fail immediately:
```
try {
    int n = input_nt<int>();
} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    std::cin.clear();             // Clear error flags
    std::cin.ignore(10000, '\n'); // Ignore remaining dirty data in buffer
}
```
## Support & Feedback
For any issues, bug reports, or feature requests, please contact the developer:
- QQ: 798500620