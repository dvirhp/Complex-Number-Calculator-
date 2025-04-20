# Complex Number Calculator 🧮🔢
**C Implementation of Complex Number Operations**

---

## 🔍 Project Overview
This project implements a complex number calculator in ANSI C that allows users to perform various operations on complex numbers through a text-based command interface. It handles user interaction, parses commands, and executes mathematical operations on complex numbers, displaying both the input commands and their results.

---

## 🚦 Architecture Overview
### ✅ Project Structure
- **`mycomp.c`:** Main program containing the `main` function and handling user interaction
- **`complex.c`:** Implementation of complex number operations 
- **`complex.h`:** Type definitions and function declarations for complex number operations

### 🌀 Core Functionality
- **Variable Management:** Uses six predefined complex variables (A-F)
- **Input Processing:** Accepts commands from stdin or input files via redirection
- **Command Echo:** Displays each command exactly as read before showing results
- **Error Handling:** Provides clear error messages for invalid commands or parameters

---

## ⚙️ Supported Operations
The calculator provides various commands to manipulate complex numbers:
- **`read_comp <var>, <real>, <imaginary>`:** Define a complex number
- **`Add_Comp <var1>, <var2>`:** Add two complex numbers
- Additional operations for complex number manipulation

---

## ⚠️ Error Handling
The system handles various error scenarios:
- Undefined complex variables
- Unknown command names
- Invalid parameters (non-numeric values)
- Syntax errors in command format

---

## 💻 Usage Examples
```
read_comp G, 3.1, 6.5
Undefined complex variable

read_comp a, 3.6, 5.1
Undefined complex variable

read_comp A, 3.5
```

---

## 🛠️ Compilation & Execution
The program can be compiled using standard ANSI C compilers:
```bash
gcc -ansi -Wall -pedantic mycomp.c complex.c -o complex_calculator
```

Execute the program in different ways:
```bash
# Interactive mode
./complex_calculator

# With input redirection
./complex_calculator < commands.txt

# With input and output redirection
./complex_calculator < commands.txt > results.txt
```

---

## 📝 Input Format
Each line in the input should contain a single command with its parameters. The program processes these commands sequentially, displaying both the original command and its result or error message.

---

## 📚 Design Philosophy
The calculator is designed with modularity in mind, separating the user interface logic from the mathematical operations, allowing for easy maintenance and potential extensions.
