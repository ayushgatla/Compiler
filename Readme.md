<div align="center">

# 🔧 Mini C Compiler

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Lex](https://img.shields.io/badge/Lex-Flex-orange?style=for-the-badge)
![Yacc](https://img.shields.io/badge/Yacc-Bison-red?style=for-the-badge)
![Assembly](https://img.shields.io/badge/x86--64-Assembly-blue?style=for-the-badge)

**A simple educational compiler built from scratch using Lex & Yacc**

[Features](#-features) • [Installation](#-installation) • [Usage](#-usage) • [Examples](#-examples) • [Architecture](#-architecture)

</div>

---

## 📋 Overview

A **basic C compiler** that translates a simplified C subset into x86-64 assembly. Built to understand compiler design principles.

```
Simple C  →  Three-Address Code  →  x86-64 Assembly  →  Executable
```

**Example:**

```c
scanf a;
scanf b;
c = a + b;
print c;
```

---

## ✨ Features

- ✅ Arithmetic: `+`, `-`, `*`, `/`
- ✅ Variables: a-z (26 total)
- ✅ I/O: `scanf`, `print`
- ✅ Control: `while` loops
- ✅ TAC intermediate code
- ✅ x86-64 assembly output

---

## 🚀 Quick Start

```bash
# Install tools
sudo apt-get install flex bison gcc

# Clone & build
git clone https://github.com/ayushgatla/Compiler.git
cd Compiler
yacc -d grammar.y && flex lexer.l && gcc y.tab.c lex.yy.c -lfl -o compiler

# Test
echo "a=5; b=3; c=a+b; print c;" > test.c
./compiler < test.c
gcc out.s -o test && ./test
```

---
```bash
or just make run_tests.sh as exec and run it
chmod +x run_test.sh
./run_tests.sh
```

---
## 💡 Examples

### Factorial

```c
scanf n;
fact = 1;
i = 1;
while (i < n) {
    i = i + 1;
    fact = fact * i;
}
print fact;
```

Input: `5` → Output: `120`

### Sum of N Numbers

```c
scanf n;
sum = 0;
i = 0;
while (i < n) {
    sum = sum + i;
    i = i + 1;
}
print sum;
```

Input: `10` → Output: `45`

---

## 🏗️ Architecture

```
Source → Lexer → Parser → TAC → Assembly → Executable
         (Flex)  (Yacc)   (IR)   (x86-64)
```

---

## ⚠️ Limitations

**Not Supported:**

- Arrays, pointers
- Multi-character variables

**Supported:**

- Variables: a-z only
- Operators: `+`, `-`, `*`, `/`, `<`, `=`
- Control: `while` only
- I/O: `scanf`, `print`
- functions, while loops
- if else , if only

---

## 👨‍💻 Author

**Ayush Gatla** | [GitHub](https://github.com/ayushgatla) | [LinkedIn](https://linkedin.com/in/ayush-gatla)

---

<div align="center">

⭐ **Star this repo if you found it helpful!**

Made with ❤️ and ☕

</div>
