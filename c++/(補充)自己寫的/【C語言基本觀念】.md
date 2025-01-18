- C language was developed in 1972 by American computer scientists Dennis Ritchie (September 9, 1941 - October 12, 2011) and Ken Thompson (February 4, 1943 - present), during their work on the UNIX operating system. 
- C language combines low-level assembly features with high-level language capabilities, making it naturally suitable as a mainstream programming language in the early days of computer programming. 
	![upgit_20241005_1728107353.png](https://raw.githubusercontent.com/kcwc1029/obsidian-upgit-image/main/2024/10/upgit_20241005_1728107353.png)
(Dennis Ritchie)


## 程式語言基本區分
- 程式語言基本可以分為高階語言(high-level languages)與低階語言(low-level languages)
- High-level languages (such as **Basic**, **Fortran**, **Cobol**, and **Pascal**) have the advantages of being easy to learn and understand, and are less prone to errors. They are more closely related to human expression. However, a drawback is that they do not efficiently control the hardware at a low level, and their execution efficiency is also relatively poor.
- Low-level languages (such as **assembly language**) have good execution efficiency and provide strong control over hardware. However, they are difficult to learn and understand. Writing, reading, debugging, and maintenance are relatively challenging.

### 程式語言開發過程
- C語言從設計、到最後執行會依據下列步驟進行：
1. Create a source file.
2. Use an editor to write the original source code.
3. Compile and link the program. At this stage, the system will generate an executable module.
4. Execute the program.



**Steps in detail**:

1. Source Program: Write the source code.
2. Compiler: Use the compiler to translate the source code.
   - If a **header file** is referenced, it will be included during compilation.
3. **Object File (Obj)**: After compilation, an **object file** with the extension `.obj` is generated, which is an intermediate file without syntax errors.
4. **Linker**: The purpose of the linker is to link **libraries and functions** together to create an **executable file**.
5. **Executable File (.exe)**: The resulting **executable file** with the extension `.exe` is a standalone executable program for the operating system.
6. **Program Execution**: Execute the compiled program.

---

- Designing a C program often involves using functions like `printf()` for output. These functions are declared in **header files**, such as **stdio.h**. To compile successfully, C programs typically include the directive:
```c
#include <stdio.h>
```

