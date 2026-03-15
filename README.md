# C++ Multi-File Project Refactoring Exercise

## Project Description

This project is designed to help you understand and practice organizing C++ code into separate header (`.h`) and implementation (`.cpp`) files. Currently, the `main.cpp` file contains two class definitions, `Page` and `Book`, declared and implemented directly within the main source file. The `Book` class demonstrates aggregation by containing an object of the `Page` class.

## The Problem

While defining classes directly in `main.cpp` might work for very small programs, it's not a scalable or maintainable practice for larger projects. It leads to:
*   **Poor Organization**: All code is in one place, making it hard to navigate.
*   **Lack of Reusability**: Classes cannot be easily reused in other parts of a larger project.
*   **Increased Compile Times**: Changes to a class implementation require recompiling `main.cpp` and any other files that include it, even if only the implementation changed.

Your task is to refactor these inline class definitions into their proper multi-file structure.

## Your Task: Refactor `Page` and `Book` Classes

You need to move the `Page` and `Book` class definitions and their implementations into separate header and implementation files.

### Steps to Solution:

1.  **Examine `main.cpp`**: Open `main.cpp` and carefully review the `Page` and `Book` class definitions, including their member variables, constructors, and member functions.

2.  **Move `Page` Class Definition**:
    *   Open `Page.h`.
    *   Cut the `Page` class *declaration* (the class definition without method bodies) from `main.cpp` and paste it into `Page.h`.
    *   Ensure `Page.h` has proper include guards (`#ifndef`, `#define`, `#endif`).
    *   Add any necessary `#include` directives to `Page.h` (e.g., for `std::string`).

3.  **Implement `Page` Class Methods**:
    *   Open `Page.cpp`.
    *   Cut the `Page` class *method implementations* (the code inside the `{}` of each function) from `main.cpp` and paste them into `Page.cpp`.
    *   Prefix each method name with `Page::` to indicate it belongs to the `Page` class (e.g., `void Page::setPageNumber(int num)`).
    *   Add `#include "Page.h"` at the top of `Page.cpp`.
    *   Add any other necessary `#include` directives to `Page.cpp` if methods use features not already included by `Page.h`.

4.  **Move `Book` Class Definition**:
    *   Open `Book.h`.
    *   Cut the `Book` class *declaration* from `main.cpp` and paste it into `Book.h`.
    *   Ensure `Book.h` has proper include guards.
    *   Add `#include "Page.h"` to `Book.h` because `Book` aggregates a `Page` object.
    *   Add any other necessary `#include` directives to `Book.h`.

5.  **Implement `Book` Class Methods**:
    *   Open `Book.cpp`.
    *   Cut the `Book` class *method implementations* from `main.cpp` and paste them into `Book.cpp`.
    *   Prefix each method name with `Book::`.
    *   Add `#include "Book.h"` at the top of `Book.cpp`.
    *   Add any other necessary `#include` directives to `Book.cpp`.

6.  **Update `main.cpp`**:
    *   Remove the now-moved `Page` and `Book` class definitions and implementations from `main.cpp`.
    *   Add `#include "Page.h"` and `#include "Book.h"` at the top of `main.cpp` so it can use the classes.
    *   The `main` function's logic should remain unchanged, as it will now use the classes defined in the new header files.

7.  **Compile and Run**:
    *   Compile your project. If you encounter errors, carefully read the error messages and debug your code. Common issues include missing `#include` directives, incorrect method signatures, or forgotten `::` scope resolution operators.
    *   Run the executable to ensure the program behaves as expected. The output should be identical to the original `main.cpp`'s output.

Good luck! This exercise is fundamental to writing well-structured C++ applications.