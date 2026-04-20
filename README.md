# 🚀 Mini Language Interpreter in C++

A simple **mini language interpreter** built in C++ to demonstrate core concepts of **Compiler Design**, including lexical analysis, parsing, AST (Abstract Syntax Tree), and execution of control flow statements.

---

## 📌 Features

* ✅ Lexical Analysis (Tokenization)
* ✅ Parser with AST (Abstract Syntax Tree)
* ✅ Arithmetic Expression Evaluation with Operator Precedence
* ✅ Variable Declaration and Assignment (`int a = 10;`)
* ✅ `print()` function support
* ✅ Control Flow:

  * `if` statement
  * `while` loop
* ✅ Block execution using `{ }`
* ✅ Error Handling (invalid syntax, undeclared variables, division by zero)
* ✅ File-based input support

---

## 🛠️ Tech Stack

* C++
* Object-Oriented Programming (OOP)
* Compiler Design Concepts

---

## 📂 Project Structure

```
mini-language-interpreter-cpp/
│
├── ASTNode.h
├── Lexer.cpp
├── Lexer.h
├── Parser.cpp
├── Parser.h
├── Token.h
├── main.cpp
├── input.txt
└── README.md
```

---

## ▶️ How to Run

### 🔹 Step 1: Clone the repository

```
git clone https://github.com/rai8896/mini-language-interpreter-cpp.git
cd mini-language-interpreter-cpp
```

---

### 🔹 Step 2: Compile the code

```
g++ *.cpp -o main
```

---

### 🔹 Step 3: Add input

Edit the `input.txt` file and write your code:

```
int a = 1;
int b = 5;

while (a < b) {
    print(a);
    a = a + 1;
}
```

---

### 🔹 Step 4: Run the program

```
./main
```

(Windows users can use:)

```
main.exe
```

---

## 🧪 Sample Output

```
Output: 1
Output: 2
Output: 3
Output: 4
```

---

## 💡 Example Supported Syntax

```
int a = 10;
int b = 5;

if (a > b) {
    print(a);
}

while (a > 0) {
    print(a);
    a = a - 1;
}
```

---

## 🎯 Learning Outcomes

* Understanding of compiler phases (Lexer, Parser, Execution)
* Implementation of AST-based evaluation
* Handling control flow in custom language
* Hands-on experience with interpreters

---

## 📌 Future Improvements

* 🔄 Add `else` support
* 🔁 Add nested loops and conditions
* ⚡ Add function support
* 🔧 Convert to LLVM-based compiler

---

## 👨‍💻 Author

**Manish Rai**
<br/>
Delhi Technological University
---


