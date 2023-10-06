# 数值分析编程作业1报告

> 学号：3210101440；姓名：胡子豪

### Requirements

本次编程作业的主要目标如下：

- 利用`C++`构造抽象基类`EquationSolver`，并由此实现三个派生类，用于二分法、牛顿迭代法和割线法求解方程的根；
- 针对剩余的$B\; to\; F$题，利用上述实现的类进行相关的求解与分析。

### Problem-solving ideas

本次编程作业的实现主要分为两个方面：类及其成员函数的构建与相应题目的代码构建。具体来说是先实现类的构建，再将此应用于已撰写好的题目代码之上。

- 类的构建：
  1. 创建`Solve.h`与`Solve.cpp`，将类的声明与实现分开；
  2. 利用`virtual`关键字构造抽象基类的成员函数`solve()`，再对三个派生类的成员函数进行重构；
  3. 按照二分法、牛顿迭代法和割线法实现具体的函数代码。
- 解决具体问题：根据题目要求撰写代码，调用相关函数进行问题求解并输出有效信息。

### Code analysis

核心代码分析如下：

- 派生类的`solve()`函数（以二分法为例）：

  ```c++
  vector<double> solve(double left, double right, 
                  function<double(double)> func);
  ```

  1. 函数返回类型选用`vector<double>`是考虑到有多个返回值；
  2. 参数表中包括`function<double(double)> func`，这是将另一个函数`func()`传入`solve()`中；
  3. 具体实现按照相应方法的思路即可。

- `lambda`函数块：

  ```c++
  auto func1 = [](double x) { return 1.0/x - tan(x); };
  ```

  1. 这个`lambda`函数没有名称，而是将其赋值给变量 `func1`。`func1`接受一个参数 `x`。
  2. 此时`func1`可作为参数传入`solve()`函数。

### Test results and Analysis

- `B`题：

  <img src=".\res_pic\B.png" alt="B" style="zoom:40%;" />

- `C`题：

  <img src=".\res_pic\C.png" alt="C" style="zoom:70%;" />

- `D`题：

  <img src=".\res_pic\D.png" alt="D" style="zoom:45%;" />

- `E`题：

  <img src=".\res_pic\E.png" alt="E" style="zoom:40%;" />

- `F`题：
  （c）选取相距33°较近的点：<img src=".\res_pic\F1.png" alt="F1" style="zoom:40%;" />

  （c）选取相距33°较远的点：<img src=".\res_pic\F2.png" alt="F2" style="zoom:40%;" />

  可以看出，使用割线法时，当选取的另一个初始值与33°相差甚远时，得到的结果与理论结果相差较远。

  原因在于：如果初始取值远离理论根，割线法会产生发散，即算法不会收敛到根，而是在无限迭代中趋向无穷大或无穷小。这会导致计算失败或错误的根，本题即是产生错误的根。
