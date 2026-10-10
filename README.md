# C++ Learning Path

A step-by-step collection of small, runnable C++ programs, one topic at a time, from the basics to the standard library. Each file is self-contained, commented, and compiles on its own.

## Topics

| Level | # | File | What you learn |
|-------|---|------|----------------|
| Beginner | 1 | [`01_beginner/01_variables.cpp`](01_beginner/01_variables.cpp) | Data types, printing values, arithmetic operators |
| Beginner | 2 | [`01_beginner/02_control_flow.cpp`](01_beginner/02_control_flow.cpp) | `if`/`else`, `switch`, `for`, `while`, range-based `for`, `break` and `continue` |
| Beginner | 3 | [`01_beginner/03_functions.cpp`](01_beginner/03_functions.cpp) | Overloading, default arguments, pass-by-reference |
| Intermediate | 4 | [`02_intermediate/04_stl_containers.cpp`](02_intermediate/04_stl_containers.cpp) | `std::vector`, `std::map`, `std::set` |

## Build and run

You need a C++17 compiler such as `g++` or `clang++`.

```bash
g++ -std=c++17 -Wall -Wextra -o variables 01_beginner/01_variables.cpp
./variables
```

Swap in any file from the table above. On Windows, run `variables.exe` instead.

## Repository layout

```
01_beginner/        Topics 1-3: fundamentals
02_intermediate/    Topic 4 onwards: the standard library
```

New topics are added as numbered files, so the numbers show the order to study them in.
