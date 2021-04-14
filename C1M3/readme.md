# Solutions to Programming Assignment Quiz
I am copying and pasting from [this forum thread](https://www.coursera.org/learn/introduction-embedded-systems/discussions/weeks/3/threads/wgokwUgyEemuthIculYtRg) as this test was driving me nuts and I hope other weary students can utilize this information to **learn**.  If this information helped you out, please star my repo so I know people utilize it.  If I have anything wrong, please create an issue or a pull request.

Sometimes I don't specify it in the explination but think:

* RAM = Data Memory
* ROM = Code Memory

### 1st Digit
|   Segment  | 1st Digit |
|:----------:|-----------|
| Code       | 1         |
| Data       | 2         |
| Peripheral | 3         |
| Register   | 4         |
| None       | 5         |


### 2nd Digit
|    Sub-Segment   | 2nd Digit |
|:------------:|-----------|
| Stack        | 1         |
| Heap         | 2         |
| BSS          | 3         |
| Data         | 4         |
| const/rodata | 5         |
| None         | 6         |
| Text         | 7         |


### 3rd Digit
|   Permissions  | 3rd Digit |
|:----------:|-----------|
| Read       | 1         |
| Write      | 2         |
| Read-Write | 3         |
| None       | 4         |


### 4th Digit
|    Lifetime    | 4th Digit |
|:--------------:|-----------|
| Function/Block | 1         |
| Program        | 2         |
| Indefinite     | 3         |
| None           | 4         |

---
## g1 - 2332
**data bss RW program**

Global variables that are zero or unintialized are stored in .bss and as all variables have read/write permissions.  Since it is a global variable already, the `static` modifier doesn't have any effect where it is stored

---
## g2 - 1512
**code const R program**

Constant (*const*) variables are stored in ROM, or code memory, specifically in read only/ constant section (RO/const).  Since they cannot be modified, they are read only.

---
## g3 - 2432
**data data RW program**

Standard initialized global variable, stored in .data section of RAM (data memory).  Since RAM is volatile, only last as long as the program (power is reset, etc)

---
## g4 - 2332
**data bss RW program**

Zero initialized global variable means stored in the BSS section of RAM (data memory)

---
## g5 - 2432
**data data RW program**

Global variable that is declared in `main.c` but initialized to a non-zero value in `misc.c`.  Similar to `g3`, this is stored in the .data section of RAM.

---
## N - 5644
**none none none none**

The `#define` is a pre-processor macro that essentially copies and paste whatever is defined into where the macro is used **before compilation**.  N is never stored anywhere, the compiler saw line 38 in `main.c`

```c
l2 = (int *) malloc( N * g2 * sizeof(char) );
```

as:
```c
l2 = (int *) malloc( 6 * g2 * sizeof(char) );
```
---
## l1 - 4631
**register none RW function**

l1 has the specially `register` modifier, meaning it is *intended* to be stored in a register and therefore does not get stored in RAM/ROM.  Since it is a local variable, it only survives the scope of the function.

---
## l2 - 2131
**data stack RW function**

l2 is a local variable that just happens to be a pointer.  Without any special modifiers (`register`, `const`, `static`), local variables are saved to the stack of RAM.

---
## *l2 (dereferenced) - 2233
**data heap RW indefinite**

Dynamically allocated data resides on the heap of RAM.  I would argue the lifetime is that of the program since RAM gets wiped at power cycles, but this is the answer the test requires.

---
## l3 - 2131
**data stack RW function**

l3 is a local variable.  The `volatile` modifier is to tell the compiler that the value can change at any time and don't try to optimize it out.  See [l2](#l2-2131) for further explanation.

---
## SOME_VALUE - 5644
**none none none none**

The `#define` is a pre-processor macro that essentially copies and paste whatever is defined into where the macro is used **before compilation**.  `SOME_VALUE` is never stored anywhere.  See [N](#n-5644) above for further info

---
## f1 - 2131
**data stack RW function**

f1 is a local variable that is initialized with the value passed to it by the function call.  All **standard** local variables get saved to the stack and only survive the function.

---
## f2 - 2332
**data bss RW program**

f2 is a local variable, so initially one might think it is stored on the stack.  But since it has the `static` modifier, it is going to be stored either in `.data` or `.bss`.  Since it is uninitialized, it is stored in the `.bss` of RAM.  The `static` keyword *essentially* makes it a global variable, but only with a local scope.  Meaning it will survive past the function call, but cannot be modified from any function other than `func()`

---
## f3 - 2131
**data stack RW function**

f3 is a local variable so it gets stored on the stack (regardless if uninitialized or initialized to 0).  All **standard** local variables get saved to the stack and only survive the function.

---
## f4 - 2131
**data stack RW function**

f4 is a local variable that happens to also be a pointer.    All **standard** local variables get saved to the stack and only survive the function.

---
## Hello World! (The string) - 1513
**code rodata R Program**

The string is a constant initialized value.  All initialized constant values are stored in the read only data *(rodata)* of the ROM (code).  This applies to arrays, strings (which are just char arrays) and other constant initialization values.

---
## main() - 1712
**code text R Program**

All the code that is written is stored in the `.text` section of ROM.  Not sure why the lifetime isn't indefinite, but this is the solution.

---
## func() - 1712
**code text R Program**

All the code that is written is stored in the `.text` section of ROM.  Not sure why the lifetime isn't indefinite, but this is the solution.
