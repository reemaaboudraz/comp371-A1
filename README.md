# COMP 371 – Assignment 1

## Part 1: Dynamic Array and Memory Management

This project was created for **COMP 371 – Computer Graphics, Assignment 1**.

### Team Members

- **Aboudraz, Reema** — 40253549
- **Wissem Oumsalem** — 40291712
- **Omar El Akrae** — 40252799


---

## Project Overview

Part 1 demonstrates the use of dynamic memory management in C++.

The program allows the user to:

1. Enter the desired size of a dynamic integer array.
2. Dynamically allocate the array using `new[]`.
3. Initialize the array with values from `0` to `size - 1`.
4. Display the array elements.
5. Delete the array using `delete[]`.
6. Confirm that the pointer was reset to `nullptr`.
7. Choose whether to create another array or end the program.

---

## File Structure

```text
comp371-A1/
├── part1.cpp
└── README.md
```

- `part1.cpp` contains the complete implementation for Assignment 1, Part 1.
- `README.md` explains the program and how to compile and run it.

---


## Requirements

To compile and run the program, you need:

- A C++ compiler that supports C++17
- Visual Studio Code or another C++ editor
- `g++` installed and available in your system `PATH`

To verify that `g++` is installed, run:

```powershell
g++ --version
```

---

## How to Compile

Open the VS Code terminal in the folder containing `part1.cpp`.

On Windows PowerShell, compile the program with:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic part1.cpp -o part1
```
---

## How to Run

After compilation, run:

```powershell
.\part1.exe
```

---