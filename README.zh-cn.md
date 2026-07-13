# fucker_io
[English](./README.md)
- 头文件名称：`fucker_input.h`
- 开发者：sliperman
- 所属工作室：不刘名科创
- 当前版本：0.1.0
## 快速开始
将 `fucker_input.h` 放入你的项目目录，并在代码中引入：
```
#include "fucker_input.h"
using namespace fucker_io; // 引入命名空间以简化调用
```
## 核心 API 说明
### 1. 读取单个变量 input_nt<T>()
从标准输入读取一个基本数据类型并返回。
```
int num = input_nt<int>();
```
### 2.批量读取容器 ips(cont& c)
遍历传入的容器，依次从标准输入读取数据并赋值。
```
std::vector<int> vec(5);
ips(vec); // 自动读取5个整数填充到vec中
```
### 3. 迭代器范围读取 input_range(itera fs, itera ls)
在指定的迭代器范围内进行数据读取。
```
std::vector<int> vec(10);
input_range(vec.begin(), vec.begin() + 5); // 仅读取前5个元素
```
### 4. 仿函数读取 input_sequence<_Tp>
以函数对象的形式读取容器数据
```
std::vector<int> vec(5);
input_sequence<std::vector<int>>()(vec);
```
### 5. 自定义输入逻辑 input_cus<T>(F&& functor)
传入一个自定义的 Lambda 或函数对象，对读取的数据进行自定义处理或校验。
```
int positive_num = input_cus<int>([](int& val) {
    std::cin >> val;
    if (val <= 0) throw std::runtime_error("必须为正整数");
});
```
## 注意事项与异常处理
#### 1.异常抛出：当输入格式不匹配时，库函数会抛出 std::runtime_error。建议在外部使用 try-catch 块捕获。
#### 2.缓冲区清理：当前版本在抛出异常时，未自动清理 std::cin 的错误标志和缓冲区。捕获异常后，请务必手动清理，否则后续输入将直接失败：
```
try {
    int n = input_nt<int>();
} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    std::cin.clear();             // 清除错误标志
    std::cin.ignore(10000, '\n'); // 忽略缓冲区脏数据
}
```
## 问题反馈
如有任何问题或功能建议，请联系开发者：
- QQ：798500620