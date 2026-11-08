# Sorting Algorithms & Complexity Visualizer

[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg?logo=c%2B%2B)](https://en.wikipedia.org/wiki/C%2B%2B17)
[![Web Visualizer](https://img.shields.io/badge/Web-HTML5%20%2F%20Vanilla%20JS-orange.svg)](web/index.html)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Build: Make](https://img.shields.io/badge/Build-Makefile-brightgreen.svg)](cpp/Makefile)

An interactive visualizer, comparative benchmark suite, and theoretical complexity analyzer for fundamental sorting algorithms, implemented in **modern C++17** and **Vanilla JavaScript / HTML5**.

---

## Features

### 1. Interactive Web Visualizer (`web/index.html`)
* **Dual Arena (Side-by-Side Race):** Compare any two sorting algorithms running concurrently on the exact same dataset to observe trade-offs in real time.
* **Solo Mode:** Deep-dive into step-by-step executions with live comparison and swap highlights.
* **Input Case Presets:**
  * **Random:** Average-case behavior.
  * **Reversed:** Worst-case trigger for quadratic algorithms ($O(n^2)$).
  * **Already Sorted:** Best-case demonstration (illustrates Insertion Sort's linear $O(n)$ performance).
  * **Few Unique:** Demonstrates stability and handling of duplicates.
* **Dynamic Complexity Calculator:** Input any value of $N$ (e.g., $10$, $1\,000$, $100\,000$, $1\,000\,000$) to calculate exact theoretical operations, growth rates, and space complexity in real time.
* **Synthesized Web Audio SFX:** Audio feedback mapped to element values (pitch scales with bar height) using the Web Audio API with zero external dependencies.

### 2. High-Performance C++17 Benchmark Engine (`cpp/`)
* Reusable, standalone C++ header library (`cpp/include/Sorter.hpp`).
* Automated CLI benchmark driver (`cpp/src/main.cpp`) measuring microsecond timings, comparison counts, and memory movements across array distributions.

---

## Complexity Matrix

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity | Stable? |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **Insertion Sort** | $\mathcal{O}(n)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(1)$ | Yes |
| **Selection Sort** | $\mathcal{O}(n^2)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(1)$ | No |
| **Bubble Sort** | $\mathcal{O}(n)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(1)$ | Yes |
| **Merge Sort** | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n)$ | Yes |
| **Heap Sort** | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n \log n)$ | $\mathcal{O}(1)$ | No |
| **Quick Sort (Lomuto)** | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(\log n)$ | No |
| **Radix Sort (LSD)** | $\mathcal{O}(d \cdot (n + k))$ | $\mathcal{O}(d \cdot (n + k))$ | $\mathcal{O}(d \cdot (n + k))$ | $\mathcal{O}(n + k)$ | Yes |

---

## Project Structure

```text
sorting-algorithms-visualizer/
├── cpp/
│   ├── include/
│   │   └── Sorter.hpp            # Clean, reusable C++17 sorting engine
│   ├── src/
│   │   └── main.cpp              # Microsecond-accurate benchmark driver
│   └── Makefile                  # Build automation for C++ binaries
├── docs/
│   ├── Complexity_Analysis.md    # Detailed Big-O proofs and trade-offs
│   └── Algorithms_Guide.md       # Technical reference and pseudocode
├── web/
│   └── index.html                # Interactive web visualizer & calculator
├── .gitignore
├── LICENSE                       # MIT License
└── README.md                     # Project documentation
```

---

## Quick Start

### 1. Running the Interactive Web Visualizer
Simply open `web/index.html` in any modern web browser:
```bash
# On Windows
start web/index.html

# On Linux / WSL
xdg-open web/index.html
```
*(Or deploy it to GitHub Pages in 1-click by setting the branch source to the `web/` folder).*

### 2. Building & Running the C++ Benchmarks
```bash
cd cpp

# Compile with optimizations
make

# Execute benchmarks
make run
```

---

## Author

* **Josue Torres Sibaja**
  * GitHub: [@josuetorres27](https://github.com/josuetorres27)

---

## License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.
