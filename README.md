# CS50 Repo.

This repository will contain all of my projects from the CS50 course offered by Harvard on edX.

## Current Uploads

- W01_P01.c
- W01_P02.c

Last updated 03/27/2025

## C on Windows

> Be patient. Do not rush. **Do not** search for solutions to programming

The following code/information is taken from the *C Programming for Everybody* course by Dr. Chuck.

Courses taught by Dr. Chuck:
- Internet History, Technology and Security - [URL](ihts.dr-chuck.com)
- Python for Everybody - [URL](www.py4e.com)
- Django for Everybody - [URL](www.dj4e.com)
- Web Applications for Everybody - [URL](www.wa4e.com)
- PostgreSQL for Everybody (SQL) - [URL](www.pg4e.com)
- C Programming for Everybody - [URL](www.cc4e.com)
- Computer Architecture for Everybody
- Java Enterprise Application Development for Everybody

### Installation

[FCC: How-To](https://www.freecodecamp.org/news/how-to-install-c-and-cpp-compiler-on-windows/)

1. Install [MSYS2](https://www.msys2.org/)
2. Run *MSYS2 MSYS* (the CLI)
3. Update the package-database and base-packages: `pacman -Syu`
4. Update all other packages: `pacman -Su` (running `pacman -Sy` may be necessary)
5. Install *GCC* and *G++* compilers by opening *MSYS2 MinGW x64* then running `pacman -S mingw-w64-x86_64-gcc`
6. Install the debugger `pacman -S mingw-w64-x86_64-gdb`
7. Add the 64-bit *MinGW* as an environment variable (*C:\msys64\mingw64\bin*)
8. Check installation (PowerShell): `gcc --version`, `g++ --version` and `gdb --version`

### Compiling with GCC

To compile, simply run `gcc -o [program_name].exe [program_name].c` from the working directory. Then, when done, simply run `[program_name].exe`.

## Learn C Programming and OOP with Dr. Chuck

- [Video](https://www.youtube.com/watch?v=PaPN51Mm5qQ)

### Historical Context

UNIX and LINUX were two separate operating systems. UNIX was created/advanced by AT&T, however they wanted to commercialize it. Linus T. created LINUX, which is UNIX-like and he wanted to ensure it remained open-source.

MacOS has UNIX in it, however Windows does not.

Python, Java, PHP and JavaScript are all based on the C-language.

- C is the most important programming language you will ever learn
- You might never write a "professional" line of C during your career
  - Learning C will help you to learn Java
  - Learning C is necessary to become a master programmer

#### Chapter 00

- C does not have a *garbage collector* or a *heap*
- A *memory leak* is when the programmer allocates memory and never deallocates it with `free()`
- After a series of calls to `malloc()` and `free()`, the *heap* space becomes fragmented and cleanup is necessary (i.e., *garbage collection*)
  - Using a language like Java, PHP or Python handles *garbage collection*
  - *Garbage collection* was intentionally left out of the C language due to its level of difficulty
- The language was intentionally designed as minimalistic to avoid massive revamps and to allow for low memory usage

### From Python to C

> Python is like a convenience layer built on top of C so users and code w/o concerns of complex details

- Unlike Python, with C...
  - White space is ignored
  - OOP is not applicable
  - Memory management is manual
  - There is no *list* or *dictionary*
    - These can be built using *structs* and *pointers*

- C has no `str`, `list` or `dict` whereas Python has no `struct` or `double`
- Both have `int`/`float` and `char`/`byte`
- C differences:
  - Boolean operators: `and`, `not` and `or`
  - There is no pre-defined `True` or `False`
  - For-loops are *indeterminant* (i.e., no `for...in`)
    - If not properly handled, then it becomes an *infinite* loop
  - `None` and `NULL` are similar yet different
  - Strings and character-arrays are similar yet different

#### First Program

```c
#include <stdio.h>

/* My first Hello World with C */

int main() {
    printf("Hello, world!\n");
    printf("Answer %d\n", 42);
    printf("Name %s\n", "Sarah");
    printf("x %.1f i %d\n", 3.5, 100);
}
```

**Important Notes:**
- `#include <studio.h>` will, likely, be in every program you code
- Single-quotes are used for characters whereas double-quotes are used for a *string* of characters

#### Number Input

```c
int main() {
    int usf, euf;
    printf("Enter US Floor: ");
    scanf("%d", &usf);
    euf = usf - 1;
    printf("EU Floor: %d\n", euf);
}
```

**Important Notes:**
- `scanf()` will look for the value it wants then disregards the rest
- The `&` allows for *call by reference* (i.e., the memory address) whereas, without the `&` is *call by value*
  - This is required to modify the value of an `int`

#### String Input

```c
int main() {
    char name[100];
    printf("Enter name: ");
    scanf("%100s", name);
    printf("Hello %s\n", name);
}
```

**Important Notes:**
- Note the `char name[100];` where we are making a variable with an array of a specified number of characters
  - C does not have resizable arrays... they are fixed-size
- `scanf("%100s", name)` will only scan up to `100` characters
- Note that there is no `&` and that is because `char name` is an array, which is handled differently

#### Line Input

```c
int main() {
    char line[1000];
    printf("Enter line: ");
    scanf("%[^\n]1000s", line);
    printf("Line: %s\n", line);
}
```

**Important Notes:**
- `[^\n]` - match any character that is **not** a new-line
  - `1000s` - stop at 1000 characters

#### Line Input (safe)

```c
int main() {
    char line[1000];
    printf("Enter line: ");
    fgets(line, 1000, stdin);
    printf("Line: %s\n", line);
}
```

#### Read A File

```c
int main() {
    char line[1000];
    FILE *hand;
    hand = fopen("romeo.txt", "r");
    while(fgets(line, 1000, hand) != NULL) {
        printf("%s", line);
    }
}
```

**Important Notes:**
- `FILE` is a type defined in the `stdio.h` library
- Again, the amount of input is fixed ahead of time (i.e., 1000 characters)

#### Counted Loop

```c
int main() {
    int i;
    for (i=0; i<5; i++) {
        printf("%d\n", i);
    }
}
```

#### Max / Min

**LEFT OFF AT 1HR AND 36MIN**
https://youtu.be/PaPN51Mm5qQ?si=JVvweagDyWCIL3QR&t=5763

### Introduction

### Types, Operators and Expressions

### Control Flow

### Functions and Program Structure

### Pointers and Arrays

### Structures

### Object Oriented Programming

### Encapsulation and Abstraction

### Tree Maps and Hash Maps

### Epilogue