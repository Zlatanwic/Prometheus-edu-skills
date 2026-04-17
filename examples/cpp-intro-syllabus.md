# 《高级语言程序设计（C++）》课程大纲

> **课程形态假设**：大学本科一年级第一门编程课，每周 1 次 × 75 分钟正课 + 1 次 × 2 小时实验，共 **15 教学周**（15 讲）。若学校为双周制或短学期，请按比例压缩模块 4 的专题讲座。
> **语言标准基线**：C++17 全面覆盖，C++20 关键特性（`concepts`、`ranges`、`<format>`、结构化绑定延伸、`std::span`）作为"现代写法"引入，C++23 作为前沿展望。
> **面向对象**：零编程基础或仅有极少数高中 OI/竞赛经验的计算机类/工科大一新生。

---

## 课程总览

本课程是学生进入计算学科的"第一门编程课"。它承担两个使命：一是让一个从未写过一行代码的大一新生在十五周内建立"用程序解决问题"的思维与工程素养；二是避免把学生塑造成一个只会写 C-with-classes 风格、对现代 C++ 语言演进毫无感知的"遗产程序员"。

过去十余年，国内高校 C++ 第一课普遍停留在 C++98/03 的教法——裸指针、`new/delete`、`char[]` 字符串、`iostream` 格式化，课程结束学生仍写着 1998 年的 C++。但自 C++11 以来，语言每三年一次大版本演进，到 C++20/23，资源管理、泛型、并发的默认写法已被彻底改写。Stroustrup 本人在 *Programming: Principles and Practice Using C++* 第三版（2024）中已把 `std::vector`、`range-for`、RAII、`concepts` 作为第一章就出现的基础概念。SIGCSE 2024 的论文 *Creation of a CS1 Course with Modern C++ Principles*（Hertz et al.）也明确指出："坏习惯在 CS1 固化后极难矫正，因此现代特性必须从第一天就教"。

本大纲采纳这一立场：**从第一讲起就用现代 C++ 的默认写法**——`std::string` 先于 `char*`、`std::vector` 先于原生数组、RAII 与智能指针先于 `new/delete`、范围 for 先于下标循环。传统的指针、手工内存管理仍然教，但被安置在"理解机器模型"而非"日常编程手段"的位置。

## 先修要求

- 高中数学（集合、函数、简单组合数学、对数与指数的直觉）。
- **不**要求任何编程经验；但要求学生能熟练使用个人电脑、命令行基础操作将在第 1、2 周实验课中补齐。

## 学习成果（Learning Outcomes）

完成本课程后，学生应当能够：

1. 将一个自然语言描述的小规模问题分解为数据表示 + 算法步骤，并用符合 C++ Core Guidelines 风格的现代 C++17/20 代码实现。
2. 阅读并正确推理含有引用、指针、值语义对象与标准库容器的中等规模（≤ 800 行）C++ 程序。
3. 解释 C++ 的编译模型、作用域、对象生命周期与 RAII，并能用 `unique_ptr` / `shared_ptr` 正确管理资源而不发生泄漏或悬垂。
4. 设计简单的类与类层次结构，理解构造/析构、拷贝/移动、虚函数与多态的代价与适用场景。
5. 熟练使用 `<vector>`、`<string>`、`<map>`、`<algorithm>`、`<ranges>` 解决日常数据处理问题，避免重造 STL 已提供的轮子。
6. 使用 g++/clang、CMake、GDB、AddressSanitizer/UBSan、Git、单元测试框架（Catch2 或 GoogleTest）完成一个从零到提交的小型项目。

## 模块结构

| 模块 | 周次 | 主题 | 讲数 |
|------|------|------|------|
| 模块一 基础：从表达式到控制流 | 1–4 | 程序与机器、变量与类型、表达式、控制结构 | 4 |
| 模块二 抽象：函数、容器与内存模型 | 5–8 | 函数、引用与指针、数组/vector/string、文件 I/O | 4 |
| 模块三 面向对象与资源管理 | 9–12 | 类、RAII、继承多态、模板与泛型初步 | 4 |
| 模块四 标准库、工具链与工程化 | 13–15 | STL 算法与 `ranges`、工程工具链、综合案例 | 3 |

---

## 逐讲教学大纲

### 模块一：基础——从表达式到控制流

#### 第 1 讲｜计算、程序、C++ 是什么（第 1 周）

**核心主题**
- 什么是"计算"：从算法到可执行程序的链路（源文件 → 预处理 → 编译 → 汇编 → 链接 → 可执行）。
- 第一个现代 C++ 程序：`#include <print>` 或 `<iostream>`、`main`、`return 0`、命令行编译运行。
- 工具链首秀：g++/clang、VS Code、CMake `add_executable` 最小例。
- "现代 C++" 是什么：C++98 → C++11 → C++17 → C++20 → C++23 的关键分界线。

**指定阅读**
- Stroustrup, *Programming: Principles and Practice Using C++*, 3rd ed. (Addison-Wesley, 2024), Ch. 1–2。
- ISO C++ 官方站 "A Tour of C++ (Intro)"：[https://isocpp.org/](https://isocpp.org/)。

**可选/前沿阅读**
- Hertz & Gee, "Creation of a CS1 Course with Modern C++ Principles," *SIGCSE TS 2024*（arXiv:2311.07807）——给学有余力者展示本课程的教学哲学来源。

**这一讲为什么存在**：不是讲语法，而是让学生建立"程序—机器—工具链"的心智三元组，为后续每一讲都能对应到"这是我在做链路上的哪一步"。

---

#### 第 2 讲｜变量、类型与表达式（第 2 周）

**核心主题**
- 基本类型：`int`、`double`、`bool`、`char`、`std::string`（作为第一等字符串，`char[]` 推后）。
- 声明 vs 初始化；**默认使用统一初始化 `T x{expr}`**（来自 Core Guidelines ES.23）。
- 表达式、运算符、类型提升、`auto` 的第一次出现。
- 常量：`const` 与 `constexpr` 的区别与建议默认。

**指定阅读**
- Stroustrup 3e, Ch. 3。
- C++ Core Guidelines：ES.5、ES.20、ES.23、Con.1、Con.4（在线：[https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)）。

**可选/前沿阅读**
- learncpp.com "Fundamental data types" 全章（[https://www.learncpp.com](https://www.learncpp.com)）。

**这一讲为什么存在**：承第 1 讲，把"数据在内存里的表示"落到可写的代码；为第 3 讲的控制流与第 7 讲的指针/对象模型做铺垫。

---

#### 第 3 讲｜条件、循环、范围 for（第 3 周）

**核心主题**
- `if/else`、`switch`（含 C++17 `if constexpr` 先睹为快）、三元运算符。
- `while`、`do-while`、经典 `for`。
- **范围 for `for (auto& x : container)` 作为默认循环**，下标 for 作为必要时的手段。
- 调试第一次：VS Code + GDB 断点、单步、观察变量。

**指定阅读**
- Stroustrup 3e, Ch. 4。
- Core Guidelines ES.71（range-for 优先于下标）。

**可选/前沿阅读**
- Kate Gregory, "Stop Teaching C" – CppCon 2015 视频（[https://www.youtube.com/watch?v=YnWhqhNdYyk](https://www.youtube.com/watch?v=YnWhqhNdYyk)）——经典教学宣言。

**这一讲为什么存在**：把流程控制与"第一等容器 `std::vector`"同时引入，避免学生先学一个月的 `int arr[100]` 再"切换"到现代写法。

---

#### 第 4 讲｜函数：抽象的第一把刀（第 4 周）

**核心主题**
- 函数声明、定义、参数传递（值/引用/`const&`），返回值。
- 函数重载、默认实参。
- 作用域、生命周期直觉（不涉及堆）。
- 递归入门：阶乘、斐波那契、二分查找的递归表达；**强调递归的栈模型，为第 7 讲内存布局埋伏笔**。

**指定阅读**
- Stroustrup 3e, Ch. 5。
- Core Guidelines F.15–F.21（参数传递约定）。

**可选/前沿阅读**
- Herb Sutter, "Back to the Basics! Essentials of Modern C++ Style" – CppCon 2014（[https://www.youtube.com/watch?v=xnqTKD8uD64](https://www.youtube.com/watch?v=xnqTKD8uD64)）。

**这一讲为什么存在**：完成"表达式 → 控制流 → 函数"的抽象三级跳，给学生第一次真正的"命名抽象"工具。

---

### 模块二：抽象——函数、容器与内存模型

#### 第 5 讲｜`std::vector` 与 `std::string` 深入（第 5 周）

**核心主题**
- `vector<T>` 的接口：`push_back`、`size`、`at` vs `operator[]`、`emplace_back`。
- `string` 的接口：`find`、`substr`、`+=`、`std::string_view`（只读视图，C++17）。
- 迭代器初识（作为"泛化的下标"）。
- 容器何时扩容、复杂度直觉（均摊 O(1)）。

**指定阅读**
- Stroustrup 3e, Ch. 6–7。
- cppreference `std::vector`、`std::string`（[https://en.cppreference.com](https://en.cppreference.com)）。

**可选/前沿阅读**
- Chandler Carruth, "High Performance Code 201: Hybrid Data Structures" – CppCon 2016（关于 `vector` 为何在现代机器上几乎永远是正确默认容器）。

**这一讲为什么存在**：在引入原生数组与指针**之前**，先让学生"只会用 vector"——这是本大纲相对传统教法最重要的顺序倒置。

---

#### 第 6 讲｜文件 I/O 与 `<format>` / `<print>`（第 6 周）

**核心主题**
- `std::ifstream`、`std::ofstream`、逐行读写。
- 格式化：从 `iostream` 的 `<<` 到 C++20 `std::format` 与 C++23 `std::print`。
- 异常初识：`try/catch`、`std::runtime_error` 在文件打开失败时的使用。

**指定阅读**
- Stroustrup 3e, Ch. 10。
- Victor Zverovich, "std::format in C++20" – [https://www.zverovich.net/2020/06/13/std-format-in-cpp20.html](https://www.zverovich.net/2020/06/13/std-format-in-cpp20.html)。

**可选/前沿阅读**
- *Programming with C++20* (Fertig, 2021), Ch. "Formatted Output"。

**前沿标记**：C++23 `std::print` 是**本课程引入的最新标准库特性**，它让初学者不再需要从第一天就面对 `iostream` 的 `<<` 链式语法。这是 2026 年 CS1 教学的应然默认。

**这一讲为什么存在**：学生在第 3 次作业就需要读写数据文件；一次性把 I/O 与异常打通。

---

#### 第 7 讲｜引用、指针与内存模型（第 7 周）

**核心主题**
- 栈 vs 堆；对象生命周期与作用域的严格关联。
- 引用 `T&`、`const T&`：作为"另一个名字"的心智模型。
- 原生指针 `T*`、`nullptr`、解引用、指针算术（只讲一次，作为理解工具而非日常手段）。
- 为什么 `new/delete` 在现代 C++ 里几乎不应在用户代码里出现——引出第 9 讲的 RAII。
- 工具：第一次用 AddressSanitizer（`-fsanitize=address,undefined`）看一个越界/悬垂例子。

**指定阅读**
- Stroustrup 3e, Ch. 8 + Ch. 17（节选）。
- Trail of Bits, "Understanding AddressSanitizer: Better memory safety for your code"（2024）：[https://blog.trailofbits.com/2024/05/16/understanding-addresssanitizer-better-memory-safety-for-your-code/](https://blog.trailofbits.com/2024/05/16/understanding-addresssanitizer-better-memory-safety-for-your-code/)。

**可选/前沿阅读**
- Google, *MSan/UBSan/ASan* 官方文档（[https://clang.llvm.org/docs/](https://clang.llvm.org/docs/)）。

**前沿标记**：把 Sanitizers **从教师演示工具纳入学生作业必开的编译选项**，是 2020 年后 CS1 教学最实用的一次升级。学生在 debug 时能直接看到"你在第 42 行写了已释放的内存"。

**这一讲为什么存在**：指针不是为了让学生"用指针来编程"，而是为了让他们**懂得值语义与引用语义的代价**，从而在第 9–10 讲理解为什么 RAII 和智能指针是正确答案。

---

#### 第 8 讲｜原生数组、C 字符串与"为什么不要用它们"（第 8 周 / 期中回顾）

**核心主题**
- `int a[N]`、`char s[N]`、`strlen`/`strcpy`——**作为历史遗产与互操作接口介绍**。
- 数组退化为指针；`sizeof` 陷阱。
- `std::array<T,N>`、`std::span<T>`（C++20）作为现代替代。
- 期中回顾 + 一次性作业讲评。

**指定阅读**
- Stroustrup 3e, Ch. 17 剩余部分。
- Core Guidelines SL.con.1、SL.con.2、F.24（`span` 用法）。

**可选/前沿阅读**
- Bjarne Stroustrup, "Type-and-resource safe coding with modern C++" – CppCon 2023 / 2024 keynote。

**这一讲为什么存在**：学生早晚要读到遗留 C/C++ 代码（包括系统调用、第三方库、面试题）。这一讲给他们"翻译"能力，同时让他们更坚定地选择现代写法。

---

### 模块三：面向对象与资源管理

#### 第 9 讲｜类：封装与 RAII（第 9 周）

**核心主题**
- 类的基本语法、成员函数、访问控制。
- 构造函数、析构函数、成员初始化列表。
- RAII 设计范式：一个 `FileHandle` 或 `Timer` 小例子贯穿始终。
- `= default`、`= delete`、`explicit`。

**指定阅读**
- Stroustrup 3e, Ch. 9。
- Core Guidelines C.1–C.9、R.1（RAII）。

**可选/前沿阅读**
- Herb Sutter, "Leak-Freedom in C++... By Default" – CppCon 2016。

**这一讲为什么存在**：本课程把类的讲授从"数据+函数绑定"上升为"资源的生命周期由类型系统强制保证"——这是 C++ 相较于 Java/Python 的本质差异。

---

#### 第 10 讲｜拷贝、移动与三/五法则（第 10 周）

**核心主题**
- 为什么 `vector<string>` 能直接正确工作：底层拷贝构造、拷贝赋值语义。
- 右值引用与移动语义（直觉层次，不深入 `std::forward`）。
- Rule of Zero、Rule of Five。
- 智能指针：`std::unique_ptr` 作为默认，`std::shared_ptr` 仅在共享所有权时。

**指定阅读**
- Stroustrup 3e, Ch. 16。
- Scott Meyers, *Effective Modern C++*, Items 17–22（节选）。

**可选/前沿阅读**
- Howard Hinnant, "Everything You Ever Wanted to Know About Move Semantics" – CppCon 2014。

**这一讲为什么存在**：不理解移动语义就无法理解现代 C++ 为什么"值语义可以高性能"。这是把学生从"怕值传递"的 C 习惯中解放出来的关键一讲。

---

#### 第 11 讲｜继承、虚函数、多态（第 11 周）

**核心主题**
- 公有继承的 "is-a" 语义；`protected`、`override`、`final`。
- 虚函数表心智模型；虚析构的必要性。
- 多态的代价：一次间接调用 + 禁止内联。
- **何时不该用继承**：组合优于继承的经典反例。

**指定阅读**
- Stroustrup 3e, Ch. 13。
- Core Guidelines C.120–C.133。

**可选/前沿阅读**
- Sean Parent, "Inheritance Is The Base Class of Evil" – GoingNative 2013（[https://channel9.msdn.com/Events/GoingNative/2013/Inheritance-Is-The-Base-Class-of-Evil](https://channel9.msdn.com/Events/GoingNative/2013/Inheritance-Is-The-Base-Class-of-Evil)）。

**这一讲为什么存在**：面向对象是大一学生的必修，但工业界近二十年的共识是"继承被滥用"。本讲明确教**有界的继承**，而不是无脑 class hierarchy。

---

#### 第 12 讲｜模板与泛型初步，`concepts` 先睹（第 12 周）

**核心主题**
- 函数模板：`template <class T> T max(T a, T b)`。
- 类模板直觉：`std::vector<T>` 到底是怎么做的。
- **C++20 `concepts`**：`template <std::integral T>` vs 传统 SFINAE——前者可读、错误信息人话。
- 为什么泛型让你写一遍、到处用。

**指定阅读**
- Stroustrup 3e, Ch. 18 + Ch. 19（节选）。
- Andreas Fertig, *Programming with C++20*, Ch. "Concepts"（[https://andreasfertig.com/books/programming-with-cpp20/](https://andreasfertig.com/books/programming-with-cpp20/)）。

**前沿标记**：`concepts` 是 C++20 四大特性之一。**在 2026 年把 `concepts` 纳入第一门课**已成为 Stroustrup 本人第三版教材的默认安排；把它推迟到"高级 C++"是过时的。

**这一讲为什么存在**：给学生一把钥匙去读懂 `<algorithm>`、`<ranges>` 的签名——为第 13 讲铺路。

---

### 模块四：标准库、工具链与工程化

#### 第 13 讲｜STL 算法、迭代器与 `<ranges>`（第 13 周）

**核心主题**
- `std::sort`、`std::find`、`std::accumulate`、`std::transform` 等常用算法。
- 迭代器类别：输入/前向/双向/随机访问。
- **C++20 `std::ranges`**：`views::filter`、`views::transform`、管道风格 `|`。
- `std::map`、`std::unordered_map` 的选择与复杂度。

**指定阅读**
- Stroustrup 3e, Ch. 11 + Ch. 12。
- Eric Niebler, "Ranges for the Standard Library"（[https://ericniebler.com/](https://ericniebler.com/)）。

**可选/前沿阅读**
- Tristan Brindle, "An Overview of Standard Ranges" – CppCon 2019（[https://www.youtube.com/watch?v=SMBkB4zqrFk](https://www.youtube.com/watch?v=SMBkB4zqrFk)）。

**前沿标记**：`ranges` 把函数式数据处理管道引入 STL。把它作为"CS1 展望"讲授，让学生之后读 Python/Rust/Kotlin 等语言的相似特性时有共同概念根基。

**这一讲为什么存在**：是整门课最高的"抽象台阶"——从造轮子转向用标准库的强大积木。

---

#### 第 14 讲｜工程化：CMake、Git、测试与调试（第 14 周）

**核心主题**
- CMake 的最小心智模型：`project`、`add_library`、`add_executable`、`target_link_libraries`、`target_compile_features(... cxx_std_20)`。
- Git 日常三连：`add`、`commit`、`push`；分支与 `merge/rebase` 的直觉。
- 单元测试：用 Catch2 或 GoogleTest 为前几次作业中的一个函数补测试。
- 调试工具全家福：GDB / LLDB、ASan/UBSan、`std::print` 日志、VS Code 调试器。

**指定阅读**
- Craig Scott, *Professional CMake: A Practical Guide* 第 2、4 章（节选）。
- Pro Git 第 1–3 章（[https://git-scm.com/book](https://git-scm.com/book)）。

**可选/前沿阅读**
- Google Testing Blog, "Testing on the Toilet" 系列（C++ 相关篇）。

**这一讲为什么存在**：不会用 Git、不会写 CMake、不会跑单元测试的 C++ 程序员在 2026 年的工业界是**不合格的**。这一讲把第一年学生从"作业提交者"升级为"项目开发者"。

---

#### 第 15 讲｜综合案例 + 展望：你下一步该学什么（第 15 周）

**核心主题**
- 案例实战：一个 300–500 行的小项目现场拆解（推荐：命令行版"简易 Markdown → HTML 转换器"或"小型键值存储"）。
- 展望：
  - **并发**（`std::thread`、`std::async`、C++20 `jthread` 与停止令牌）——下学期《并发与并行》的切入口。
  - **性能与汇编直觉**（Compiler Explorer godbolt.org 演示 `-O0` vs `-O2`）。
  - **C++ 在哪些领域仍是"唯一选择"**：游戏引擎、嵌入式、HFT、机器人、编译器、数据库内核、浏览器渲染引擎。
  - **前沿动态**：C++23 `std::expected`、`std::mdspan`，C++26 的 reflection 提案。
- 期末项目规范与答辩安排。

**指定阅读**
- Stroustrup 3e, Ch. 20 "Post Script"。
- ISO C++ Committee Papers Overview（[https://isocpp.org/std/status](https://isocpp.org/std/status)）。

**可选/前沿阅读**
- Vittorio Romeo, "Why Developers Should Pay Attention to C++23" – [https://vittorioromeo.info/c23-and-beyond-an-overview-of-new-features-worth-using-today/](https://vittorioromeo.info/c23-and-beyond-an-overview-of-new-features-worth-using-today/)。
- Herb Sutter, "Trip Report" 系列，最新一期。

**这一讲为什么存在**：给学生一张"从 CS1 出发的地图"——他们需要看到自己刚学会的这门语言在计算机科学版图中处于什么位置，以及 2026 年之后还会发生什么。

---

## 作业与项目

全学期 **4 次渐进式编程作业 + 1 个期末综合项目**。每次作业都强制要求 `-fsanitize=address,undefined` 编译通过、`clang-format` 格式化、Git 提交历史至少 3 个有意义的 commit。

| # | 布置周 | 主题 | 产出 | 覆盖的概念 |
|---|--------|------|------|-----------|
| HW1 | 第 3 周 | **统计与绘图**：读取文本，统计词频 Top-K，终端直方图 | ~80 行，单文件 | 变量、控制流、`vector`、`string`、`map` 基础 |
| HW2 | 第 6 周 | **CSV 日志分析器**：解析 CSV、按列聚合、异常处理 | ~200 行，多文件 | 函数抽象、文件 I/O、`std::format`、异常 |
| HW3 | 第 9 周 | **小型图书馆管理系统**：类设计、持久化到 JSON | ~300 行 | 类、RAII、`unique_ptr`、值/引用语义 |
| HW4 | 第 12 周 | **泛型容器或表达式求值器**（二选一） | ~400 行 | 模板、`concepts`、多态或运算符重载 |
| **期末项目** | 第 13 周布置 / 第 15 周答辩 | **自命题**：命令行工具 / 小游戏 / Markdown 转换器 / 简易 KV 存储，必须自带 README、CMake、单元测试、至少一次代码评审修订 | 500–800 行，Git 仓库 | 综合：标准库、工程工具链、协作与文档 |

**评分权重**：作业 40% + 期末项目 30% + 期中 15% + 期末笔试 10% + 实验课表现 5%。

## 与传统 C++ 第一课相比，本大纲做了哪些改变

本大纲对国内仍广泛使用的、以郑莉《C++ 语言程序设计》第 5 版（清华大学出版社）或谭浩强老教材为代表的传统 C++ 首课做出如下**有意为之的偏离**，供任课教师理解每一处选择：

1. **`std::vector`/`std::string` 先于原生数组与 C 字符串**（第 5 讲 vs 第 8 讲）——传统教法是反过来的，这让学生在前六周都在写 C 风格代码。SIGCSE 2024 的 CS1 研究直接反对这一顺序。
2. **从第 1 讲起用 `#include <print>` / `std::format`**，`iostream` `<<` 退居其次。理由是 C++23 已把这件事做完了，教学不应再绕远路。
3. **RAII 与智能指针作为资源管理的**默认**答案**（第 9–10 讲），`new`/`delete` 只作为"理解内存"的一次性演示出现（第 7 讲）。
4. **AddressSanitizer / UBSan 作为学生作业的必开编译选项**，而非教师演示道具。
5. **C++20 `concepts` 与 `ranges` 作为课程顶峰**（第 12、13 讲），而不是"高级选修"。Stroustrup 本人 2024 版教材已把它们作为入门内容。
6. **继承与多态只占一讲**（第 11 讲），并明确讲授其滥用风险（Sean Parent 的 "inheritance is the base class of evil"）——打破"OOP = 设计类层次"的经典误区。
7. **一整讲专门给工程工具链**（第 14 讲：CMake + Git + 测试 + 调试器）——传统课程几乎完全不教，导致学生学完仍然只会"在 Dev-C++ 里按 F9"。
8. **保留中文教材作为辅助**（郑莉第 5 版、钱能第 3 版）用于想用母语复习的学生，但主教材明确以 Stroustrup 第 3 版（2024）为准。

## 推荐主教材与辅助资源

**主教材**
- Bjarne Stroustrup. *Programming: Principles and Practice Using C++*, 3rd Edition. Addison-Wesley, 2024. ISBN 978-0138308681.

**辅助参考**
- Scott Meyers. *Effective Modern C++*. O'Reilly, 2014（移动语义与智能指针的经典）。
- Nicolai Josuttis. *The C++ Standard Library*, 2nd Edition. Addison-Wesley, 2012（STL 手册级别）。
- Andreas Fertig. *Programming with C++20: Concepts, Coroutines, Ranges, and more*. 2021。
- 郑莉等，《C++ 语言程序设计》第 5 版，清华大学出版社（中文辅助）。

**在线资源**
- cppreference.com — 唯一推荐的语言与标准库查阅来源。
- learncpp.com — 免费、完整、现代，适合学生课外补充。
- C++ Core Guidelines — [https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)。
- Compiler Explorer — [https://godbolt.org](https://godbolt.org)，在第 15 讲用。
- CppCon YouTube 频道 — 对学有余力的学生，推荐 Kate Gregory、Herb Sutter、Sean Parent、Chandler Carruth 的所有演讲。

---

*大纲版本：v1.0，撰写于 2026 年 4 月，课程标准基线为 C++17/20，预留 C++23 前沿章节。*
