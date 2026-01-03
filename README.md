# 🔥 FLAMES Game in C

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey.svg)](/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

A classic FLAMES relationship calculator game implemented in C. Enter two names and discover the relationship status!

---

## 🎮 What is FLAMES?

**FLAMES** is a popular game among teenagers to find the relationship between two people. Each letter represents a relationship type:

| Letter | Relationship |
|:------:|--------------|
| **F** | Friends |
| **L** | Love |
| **A** | Affectionate |
| **M** | Marriage |
| **E** | Enemies |
| **S** | Siblings |

---

## 🧮 How It Works

### Algorithm

1. **Input** two names
2. **Convert** both names to lowercase
3. **Count** the frequency of each letter in both names
4. **Calculate** the absolute difference of letter frequencies
5. **Sum** all the differences to get the count
6. **Eliminate** letters from "FLAMES" using the count until one remains
7. **Display** the relationship result

### Example

```
Name 1: RAHUL
Name 2: PRIYA

Common letters removed, remaining count = 7
Counting through F-L-A-M-E-S repeatedly...
Result: LOVE ❤️
```

---

## 📁 File Structure

```
flames-game/
│
├── Flames.c          # Main source code
├── README.md         # Documentation
└── LICENSE           # MIT License
```

---

## 🚀 Getting Started

### Prerequisites

- GCC Compiler (or any C compiler)
- Terminal/Command Prompt

### Compilation & Execution

#### On Linux/Mac

```bash
# Compile
gcc Flames.c -o flames

# Run
./flames
```

#### On Windows (using GCC/MinGW)

```cmd
# Compile
gcc Flames.c -o flames.exe

# Run
flames.exe
```

#### On Windows (using Turbo C)

1. Open Turbo C IDE
2. Load `Flames.c`
3. Press `Ctrl + F9` to compile and run

---

## 💻 Usage

```
$ ./flames
enter name1: rahul
enter name2: priya
love
```

### Sample Runs

| Name 1 | Name 2 | Result |
|--------|--------|--------|
| John | Mary | Friends |
| Romeo | Juliet | Marriage |
| Harry | Hermione | Affectionate |
| Tom | Jerry | Enemies |

---

## 📝 Code Explanation

### Key Variables

```c
char a[20], d[20];    // Store input names
int b[26], e[26];     // Letter frequency for each name
int f[26];            // Absolute difference of frequencies
char c[] = "abcdefghijklmnopqrstuvwxyz";  // Alphabet reference
```

### Main Logic

1. **Letter Counting**
   ```c
   // Count occurrences of each letter in name1
   for(i=0; i<26; i++) {
       for(j=0; j<m; j++) {
           if(c[i] == a[j]) {
               ++b[i];
           }
       }
   }
   ```

2. **Calculate Difference**
   ```c
   for(i=0; i<26; i++) {
       f[i] = abs(b[i] - e[i]);
   }
   ```

3. **FLAMES Elimination**
   - Uses the sum to count through "FLAMES"
   - Removes the letter at count position
   - Repeats until one letter remains

---

## ⚠️ Notes & Limitations

- Maximum name length: **20 characters**
- Names should contain **only alphabets** (no spaces or special characters)
- `strlwr()` function may not work on all compilers (it's non-standard)

### Portability Fix

If `strlwr()` doesn't work, replace with:

```c
// Convert to lowercase manually
for(i = 0; a[i]; i++) {
    if(a[i] >= 'A' && a[i] <= 'Z') {
        a[i] = a[i] + 32;
    }
}
```

---

## 🔧 Possible Improvements

- [ ] Add input validation
- [ ] Handle names with spaces
- [ ] Add colorful output
- [ ] Create GUI version
- [ ] Add history of results
- [ ] Support longer names

---

## 🎯 Quick Reference - Results

| Sum mod 6 | Direct Result |
|-----------|---------------|
| 1 | Siblings |
| 2 | Enemies |
| 3 | Friends |
| 4 | Enemies |
| 5 | Friends |
| 6 | Marriage |

For sums > 6, the elimination algorithm determines the result.

---

## 👩‍💻 Author

**Saicharitha Dathrika**

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🙏 Acknowledgments

- Classic FLAMES game concept
- C Programming community

---

<p align="center">
  Made with ❤️ in C
  <br>
  <i>Find out your relationship status!</i> 🔥
</p>
