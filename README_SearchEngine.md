# 🔍 Mini Desktop Search Engine

A lightweight **desktop file search engine** built in C++ that crawls a local folder, builds an inverted index from file contents, and lets you search across all indexed files using keyword queries — right from the terminal.

> ⚠️ **Note:** This project is still a work in progress. Some features are incomplete or being actively improved.

---

## 📌 Features

- 📁 **Recursive folder crawling** — scans all subfolders automatically
- 🗂️ **Inverted index** — fast keyword-to-file mapping with word frequency scoring
- 🔎 **Keyword search** — multi-word queries with ranked results by relevance score
- 🧹 **Query parsing** — cleans and normalises input (lowercase, strips punctuation)
- 📜 **Search history** — stack-based history with undo support
- 🤖 **AI Summary** *(in progress)* — previews the first few lines of a matched file
- 🪟 **Windows-native crawler** using `WIN32_FIND_DATA` API

---

## 🗂️ Project Structure

```
searchEngine/
│
├── main.cpp            # Entry point — folder input, crawl, index, search loop
├── search_engine.h     # Shared header — all declarations and includes
│
├── crawler1.cpp        # Recursively finds files using Windows API
├── indexer1.cpp        # Builds the inverted index from file contents
├── parser1.cpp         # Cleans words, parses queries, validates extensions
├── search1.cpp         # Scores and ranks files by keyword match
├── history1.cpp        # Stack-based search history (save, show, undo)
├── ai_summary1.cpp     # Previews first lines of a file (WIP)
│
└── file01.cpp          # Reserved / placeholder (WIP)
```

---

## ⚙️ Supported File Types

The crawler indexes these extensions:

| Extension | Type |
|-----------|------|
| `.txt`    | Plain text |
| `.cpp`    | C++ source |
| `.h`      | C++ header |
| `.py`     | Python script |
| `.json`   | JSON data |

---

## 🚀 Getting Started

### Requirements

- Windows OS (crawler uses WinAPI)
- C++17 or newer
- A compiler like `g++` (MinGW) or MSVC

### Compile

```bash
g++ main.cpp crawler1.cpp indexer1.cpp parser1.cpp search1.cpp ai_summary1.cpp history1.cpp -o searchEngine.exe -std=c++17
```

### Run

```bash
./searchEngine.exe
```

Then follow the prompts:

```
==============================
 MINI DESKTOP SEARCH ENGINE
==============================
Enter folder path: C:\Users\You\Documents

Crawling files...
Files found: 42

Building index...
Indexed files: 42

Search (or exit): hello world
```

---

## 🛠️ Work in Progress

These features are planned or partially implemented:

- [ ] Full AI-powered file summarisation (currently shows first 5 lines only)
- [ ] GUI or web-based front end
- [ ] Cross-platform support (Linux/macOS — replace WinAPI crawler)
- [ ] Stop-word filtering (ignore common words like "the", "and")
- [ ] Search history integrated into the main loop
- [ ] Support for more file types (`.md`, `.html`, `.csv`)
- [ ] Export search results to a file

---

## 📝 License

MIT — free to use and modify.
