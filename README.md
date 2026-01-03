# FLAMES - Ultimate Edition

[![Language](https://img.shields.io/badge/Language-C%20%7C%20HTML%2FJS-blue.svg)](/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Mac%20%7C%20Linux%20%7C%20Web-lightgrey.svg)](/)
[![Version](https://img.shields.io/badge/Version-3.0-green.svg)](/)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

The ultimate FLAMES relationship calculator with **colorful CLI** and **beautiful Web GUI**! Enter two names and discover the relationship status with style! 💕

---

## ✨ What's New in Version 3.0

| Feature | CLI Version | Web GUI |
|---------|:-----------:|:-------:|
| 🎨 Colorful UI | ✅ | ✅ |
| 📝 Names with spaces | ✅ | ✅ |
| 📜 History tracking | ✅ (50 records) | ✅ (50 records) |
| 💾 Save to file | ✅ | ✅ (LocalStorage) |
| 🔊 Sound effects | ✅ | ✅ |
| 📤 Export history | ✅ | ✅ (Share) |
| 🎉 Confetti animation | ❌ | ✅ |
| 📱 Mobile friendly | ❌ | ✅ |
| 🌐 No installation | ❌ | ✅ |

---

## 📁 Files Included

```
flames-ultimate/
│
├── Flames_Ultimate.c     # CLI version with all features (v3.0)
├── Flames_GUI.html       # Web-based GUI version
├── Flames_UI.c           # Previous CLI version (v2.0)
├── Flames.c              # Original version (v1.0)
└── README.md             # This file
```

---

## 🎮 Quick Start

### Option 1: Web GUI (Easiest - No Installation!)

Simply open `Flames_GUI.html` in any web browser!

```bash
# Mac
open Flames_GUI.html

# Windows
start Flames_GUI.html

# Linux
xdg-open Flames_GUI.html
```

### Option 2: CLI Version

```bash
# Compile
gcc Flames_Ultimate.c -o flames

# Run
./flames
```

---

## 🖼️ Screenshots

### Web GUI Version
```
╔══════════════════════════════════════╗
║         🔥 FLAMES                    ║
║     Relationship Calculator          ║
║                                      ║
║  [F] [L] [A] [M] [E] [S]             ║
║                                      ║
║  👤 First Name:  [John Smith    ]     ║
║  👤 Second Name: [Jane Doe      ]     ║
║                                       ║
║  [🔥 Calculate Relationship]          ║
║                                       ║
║  📜 Recent History                    ║
║  ├─ Romeo & Juliet → Marriage         ║
║  └─ Harry & Sally → Friends           ║
╚═══════════════════════════════════════╝
```

### CLI Version
```
  ███████╗██╗      █████╗ ███╗   ███╗███████╗███████╗
  ██╔════╝██║     ██╔══██╗████╗ ████║██╔════╝██╔════╝
  █████╗  ██║     ███████║██╔████╔██║█████╗  ███████╗
  ██╔══╝  ██║     ██╔══██║██║╚██╔╝██║██╔══╝  ╚════██║
  ██║     ███████╗██║  ██║██║ ╚═╝ ██║███████╗███████║
  ╚═╝     ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝
          🔥 Ultimate Relationship Calculator 🔥

  ┌───────────────────────────────────────────────────────┐
  │                     MAIN MENU                         │
  ├───────────────────────────────────────────────────────┤
  │   [1] 💕  Play FLAMES                                 │
  │   [2] 📜  View History (5 records)                    │
  │   [3] 📖  What is FLAMES?                             │
  │   [4] ⚙️   Settings                                   │
  │   [5] ℹ️   About / Credits                            │
  │   [6] 🚪  Exit                                        │
  └───────────────────────────────────────────────────────┘
```

---

## 🎯 Features Explained

### 📝 Names with Spaces
Now you can enter full names like "John Smith" and "Jane Doe"!

```
👤 Enter First Name:  Mary Jane Watson
👤 Enter Second Name: Peter Benjamin Parker
```

### 📜 History Tracking
All your FLAMES calculations are saved automatically!

```
  ╔════════════════════════════════════════════════════════╗
  ║                    📜 FLAMES HISTORY                   ║
  ╠════════════════════════════════════════════════════════╣
  ║  No.  Name 1                Name 2              Result ║
  ║──────────────────────────────────────────────────────║
  ║  1    Romeo                 Juliet              Marriage║
  ║  2    Harry                 Sally               Friends ║
  ║  3    Jack                  Rose                Love    ║
  ╚════════════════════════════════════════════════════════╝
```

### 💾 Auto-Save & Export
- **CLI**: Saves to `flames_history.txt` automatically
- **CLI**: Export to timestamped file via Settings menu
- **Web**: Saves to browser's LocalStorage
- **Web**: Share results via native share or clipboard

### 🔊 Sound Effects
- Different sounds for different results
- Special melody for Love 💕 and Marriage 💒
- Can be toggled on/off in Settings

### ⚙️ Settings Menu (CLI)
```
  ╔═══════════════════════════════════════════════════════╗
  ║                   ⚙️  SETTINGS                         ║
  ╠═══════════════════════════════════════════════════════╣
  ║   [1] 🔊  Sound Effects: ON                           ║
  ║   [2] 📤  Export History to File                      ║
  ║   [3] 🗑️   Clear All History                          ║
  ║   [4] ↩️   Back to Main Menu                          ║
  ╚═══════════════════════════════════════════════════════╝
```

---

## 🔥 What is FLAMES?

| Letter | Meaning | Emoji |
|:------:|---------|:-----:|
| **F** | Friends | 👫 |
| **L** | Love | 💕 |
| **A** | Affection | 💖 |
| **M** | Marriage | 💒 |
| **E** | Enemies | 😅 |
| **S** | Siblings | 👨‍👩‍👧‍👦 |

### How It Works

1. Enter two names
2. Remove common letters (count differences)
3. Use the count to eliminate letters from "FLAMES"
4. Last remaining letter = Your relationship!

---

## 🛠️ Technical Details

### CLI Version Requirements
- GCC compiler
- Terminal with ANSI color support
- Works on: Windows 10+, macOS, Linux

### Web Version Requirements
- Any modern web browser
- JavaScript enabled
- No server needed - runs locally!

### Compilation

```bash
# Standard compilation
gcc Flames_Ultimate.c -o flames

# With all warnings
gcc -Wall -Wextra Flames_Ultimate.c -o flames

# Optimized build
gcc -O2 Flames_Ultimate.c -o flames
```

---

## 📊 Sample Results

| Name 1 | Name 2 | Result |
|--------|--------|--------|
| Romeo | Juliet | 💒 Marriage |
| Harry | Hermione | 💖 Affection |
| Tom | Jerry | 😅 Enemies |
| Chandler | Monica | 💕 Love |
| Ross | Rachel | 👫 Friends |

---

## 🐛 Troubleshooting

| Issue | Solution |
|-------|----------|
| Colors not showing (Windows) | Use Windows Terminal or enable ANSI in CMD |
| Colors not showing (Mac/Linux) | Check terminal settings |
| Sound not working (CLI) | Sound uses system beep, may vary by system |
| Sound not working (Web) | Check browser audio permissions |
| History not saving (Web) | Enable cookies/localStorage |

---

## 🚀 Version History

| Version | Features |
|---------|----------|
| **3.0** | Spaces in names, History, File save, Sound effects, Export, Web GUI |
| **2.0** | Colorful UI, ASCII art, Menu system |
| **1.0** | Basic FLAMES calculation |

---

## 👩‍💻 Author

**Saicharitha Dathrika**

---

## 📄 License

MIT License - Feel free to use, modify, and share!

---

<p align="center">
  <b>Made with ❤️ for love seekers everywhere!</b>
  <br><br>
  🔥 May you find your true FLAMES result! 🔥
</p>
