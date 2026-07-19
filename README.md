# COMP 371 – Assignment 1

This project was created for **COMP 371 – Computer Graphics, Assignment 1**.
It is divided into two parts: a dynamic array program (Part 1) and a
Point/Triangle class program (Part 2).

### Team Members

- **Aboudraz, Reema** — 40253549
- **Wissem Oumsalem** — 40291712


---

## Project Overview

### Part 1: Dynamic Array and Memory Management

Part 1 demonstrates the use of dynamic memory management in C++.

The program allows the user to:

1. Enter the desired size of a dynamic integer array.
2. Dynamically allocate the array using `new[]`.
3. Initialize the array with values from `0` to `size - 1`.
4. Display the array elements.
5. Delete the array using `delete[]`.
6. Confirm that the pointer was reset to `nullptr`.
7. Choose whether to create another array or end the program.

### Part 2: Point and Triangle Classes

Part 2 demonstrates object-oriented design and pointers in C++ through a
`Point` class and a `Triangle` class (whose three vertices are stored as
pointers to `Point`).

The program allows the user to:

1. Create a triangle by entering the coordinates of its three points.
2. Display the coordinates of the triangle's vertices.
3. Translate the triangle by a given distance along the `x`, `y`, or `z` axis.
4. Calculate the area of the triangle.
5. Exit the program.

---

## File Structure

```text
comp371-A1/
├── part1.cpp
├── part2.cpp
├── sample_run.txt
└── README.md
```

- `part1.cpp` contains the complete implementation for Assignment 1, Part 1.
- `part2.cpp` contains the complete implementation for Assignment 1, Part 2.
- `sample_run.txt` contains a sample run of both programs (submitted as a PDF).
- `README.md` explains the programs and how to compile and run them.

---


## Requirements

To compile and run the programs, you need:

- A C++ compiler that supports C++17
- Visual Studio Code or another C++ editor
- `g++` installed and available in your system `PATH`

To verify that `g++` is installed, run:

```powershell
g++ --version
```

---

## How to Compile

Open the VS Code terminal in the folder containing `part1.cpp` and `part2.cpp`.

On **Windows (PowerShell)**, compile the programs with:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic part1.cpp -o part1
g++ -std=c++17 -Wall -Wextra -pedantic part2.cpp -o part2
```

On **macOS / Linux (Terminal)**, the command is the same:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic part1.cpp -o part1
g++ -std=c++17 -Wall -Wextra -pedantic part2.cpp -o part2
```

> On macOS, `g++` is provided by the Xcode Command Line Tools. If it is not
> installed, run `xcode-select --install` first.

---

## How to Run

After compilation, run:

On **Windows (PowerShell)**:

```powershell
.\part1.exe
.\part2.exe
```

On **macOS / Linux (Terminal)**:

```bash
./part1
./part2
```

---
