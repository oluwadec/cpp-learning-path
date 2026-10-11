# C++ Learning Path

A step-by-step collection of small, runnable C++ programs, one topic at a time, from the basics to more advanced ideas. There are 25 topics in 5 levels, 5 files per level. Each file is self-contained, commented, and compiles on its own. Even the advanced files are written in a simple, beginner-friendly style.

## Topics

| Level | # | File | What you learn |
|-------|---|------|----------------|
| Beginner | 1 | [`01_beginner/01_variables.cpp`](01_beginner/01_variables.cpp) | Data types, printing values, arithmetic operators |
| Beginner | 2 | [`01_beginner/02_control_flow.cpp`](01_beginner/02_control_flow.cpp) | `if`/`else`, `switch`, `for`, `while`, range-based `for`, `break` and `continue` |
| Beginner | 3 | [`01_beginner/03_functions.cpp`](01_beginner/03_functions.cpp) | Overloading, default arguments, pass-by-reference |
| Beginner | 4 | [`01_beginner/04_user_input.cpp`](01_beginner/04_user_input.cpp) | `std::cin`, `std::getline`, reading numbers and text |
| Beginner | 5 | [`01_beginner/05_arrays_and_strings.cpp`](01_beginner/05_arrays_and_strings.cpp) | Arrays, 2D arrays, common `std::string` operations |
| Low intermediate | 6 | [`02_low_intermediate/06_pointers_and_references.cpp`](02_low_intermediate/06_pointers_and_references.cpp) | Pointers, `nullptr`, references, pointers and arrays |
| Low intermediate | 7 | [`02_low_intermediate/07_structs.cpp`](02_low_intermediate/07_structs.cpp) | Grouping data with `struct`, vectors of structs |
| Low intermediate | 8 | [`02_low_intermediate/08_classes_basics.cpp`](02_low_intermediate/08_classes_basics.cpp) | Classes, constructors, private data, getters |
| Low intermediate | 9 | [`02_low_intermediate/09_file_io.cpp`](02_low_intermediate/09_file_io.cpp) | Reading and writing text files with `ifstream` and `ofstream` |
| Low intermediate | 10 | [`02_low_intermediate/10_recursion.cpp`](02_low_intermediate/10_recursion.cpp) | Base case, recursive case, factorial, Fibonacci |
| Intermediate | 11 | [`03_intermediate/11_stl_containers.cpp`](03_intermediate/11_stl_containers.cpp) | `std::vector`, `std::map`, `std::set` |
| Intermediate | 12 | [`03_intermediate/12_stl_algorithms.cpp`](03_intermediate/12_stl_algorithms.cpp) | `sort`, `find`, `count`, `accumulate`, removing duplicates |
| Intermediate | 13 | [`03_intermediate/13_inheritance_and_polymorphism.cpp`](03_intermediate/13_inheritance_and_polymorphism.cpp) | Base and child classes, `virtual`, `override` |
| Intermediate | 14 | [`03_intermediate/14_exceptions.cpp`](03_intermediate/14_exceptions.cpp) | `try`, `throw`, `catch`, custom exception types |
| Intermediate | 15 | [`03_intermediate/15_dynamic_memory.cpp`](03_intermediate/15_dynamic_memory.cpp) | `new`, `delete`, dynamic arrays, growing an array by hand |
| High intermediate | 16 | [`04_high_intermediate/16_templates.cpp`](04_high_intermediate/16_templates.cpp) | Function templates and class templates |
| High intermediate | 17 | [`04_high_intermediate/17_smart_pointers.cpp`](04_high_intermediate/17_smart_pointers.cpp) | `unique_ptr`, `shared_ptr`, automatic cleanup |
| High intermediate | 18 | [`04_high_intermediate/18_lambdas.cpp`](04_high_intermediate/18_lambdas.cpp) | Lambdas, captures, `std::function` |
| High intermediate | 19 | [`04_high_intermediate/19_operator_overloading.cpp`](04_high_intermediate/19_operator_overloading.cpp) | Overloading `+`, `-`, `==`, `<<` for your own class |
| High intermediate | 20 | [`04_high_intermediate/20_copy_and_raii.cpp`](04_high_intermediate/20_copy_and_raii.cpp) | Copy constructor, destructor, assignment, RAII |
| Advanced | 21 | [`05_advanced/21_move_semantics.cpp`](05_advanced/21_move_semantics.cpp) | `std::move`, move constructor, move assignment |
| Advanced | 22 | [`05_advanced/22_threads_basics.cpp`](05_advanced/22_threads_basics.cpp) | `std::thread`, `std::mutex`, sharing data safely |
| Advanced | 23 | [`05_advanced/23_linked_list.cpp`](05_advanced/23_linked_list.cpp) | Building a linked list by hand with pointers |
| Advanced | 24 | [`05_advanced/24_binary_search_tree.cpp`](05_advanced/24_binary_search_tree.cpp) | Binary search tree: insert, search, in-order printing |
| Advanced | 25 | [`05_advanced/25_mini_project_inventory.cpp`](05_advanced/25_mini_project_inventory.cpp) | Mini project combining classes, maps, exceptions and lambdas |

## Build and run

You need a C++17 compiler such as `g++` or `clang++`.

```bash
g++ -std=c++17 -Wall -Wextra -o variables 01_beginner/01_variables.cpp
./variables
```

Swap in any file from the table above. On Windows, run `variables.exe` instead.

Topic 22 uses threads, so add `-pthread` when compiling it:

```bash
g++ -std=c++17 -Wall -Wextra -pthread -o threads_basics 05_advanced/22_threads_basics.cpp
```

Topic 4 waits for keyboard input, so type your answers when the program asks.

## Repository layout

```
01_beginner/          Topics 1-5:   fundamentals
02_low_intermediate/  Topics 6-10:  pointers, structs, classes, files, recursion
03_intermediate/      Topics 11-15: the standard library, inheritance, exceptions, memory
04_high_intermediate/ Topics 16-20: templates, smart pointers, lambdas, operators, copying
05_advanced/          Topics 21-25: move semantics, threads, data structures, a mini project
```

The numbers show the order to study the topics in. New topics continue from 26.
