# Sorting Algorithms & Complexity Visualizer

[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue?style=flat-square&logo=c%2B%2B)](https://en.wikipedia.org/wiki/C%2B%2B17)
[![Web Visualizer](https://img.shields.io/badge/Web-HTML5%20%2F%20Vanilla%20JS-orange?style=flat-square)](web/index.html)
[![Build: Make](https://img.shields.io/badge/Build-Makefile-brightgreen?style=flat-square)](cpp/Makefile)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow?style=flat-square)](LICENSE)

Fundamental sorting algorithms in two independent parts: a C++17 command-line benchmark that measures time, comparisons, and element moves, and a zero-dependency HTML/JavaScript visualizer with side-by-side races, sound, and a Big-O operation calculator. The web page does not use the C++ code; each part has its own implementation.

---

## Features

### Interactive Web Visualizer (`web/index.html`)

- **Dual Race (Side-by-Side):** Run any two algorithms at the same time on the same dataset, with live comparison and swap counters for each lane.
- **Solo Mode:** Hides the second lane and runs a single algorithm.
- **Controls:** Run / Pause / Resume, Reset, an array size slider (N = 15 to 80), and an animation speed slider.
- **Color Legend:** Unsorted, comparing, swap / overwrite, pivot / minimum, and in final position.
- **Input Case Presets:**
  - **Random:** Average-case behavior.
  - **Reversed:** Worst case for the quadratic algorithms ($O(n^2)$).
  - **Sorted:** Best case for Insertion Sort and Bubble Sort ($O(n)$); worst case for Lomuto Quick Sort.
  - **Few Unique:** Every element takes one of only 5 distinct values, to show how each algorithm handles many duplicates.
- **Complexity Calculator Tab:** Enter any $N$ (presets for 10k and 100k) to get an approximate worst-case operation count for each algorithm. The best, average, and worst-case Big-O labels, space, and stability columns are fixed reference values.
- **Synthesized Web Audio SFX:** Optional sound in which pitch follows bar height, generated with the Web Audio API and no external dependencies.

### C++17 Benchmark (`cpp/`)

- **Sorter Class:** Header-only `Sorter` class (`cpp/include/Sorter.hpp`) with static sorting functions over `int` arrays. Each function returns a `SortMetrics` record (comparisons, swaps/moves, elapsed microseconds).
- **CLI Driver:** `cpp/src/main.cpp` runs every algorithm on three inputs: random (fixed seed 42 for reproducibility), already sorted, and reversed, with N = 5,000.
- **Timing:** Each algorithm is timed in a single run using `std::chrono::high_resolution_clock`. There are no repetitions or warm-up, so the times are indicative; the comparison and move counts are exact for the given input.

---

## Algorithm Coverage

| Algorithm | C++ Benchmark | Web Visualizer | Complexity Calculator |
| :--- | :---: | :---: | :---: |
| **Selection Sort** | Yes | Yes | Yes |
| **Insertion Sort** | Yes | Yes | Yes |
| **Bubble Sort** | — | Yes | Yes |
| **Merge Sort** | Yes | Yes | Yes |
| **Heap Sort** | Yes | Yes | Yes |
| **Quick Sort (Lomuto)** | Yes | Yes | Yes |
| **Radix Sort (LSD, base 10)** | Yes | — | Yes |

---

## Complexity Matrix

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity | Stable? |
| :--- | :---: | :---: | :---: | :---: | :---: |
| **Insertion Sort** | $\mathcal{O}(n)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(1)$ | Yes |
| **Selection Sort** | $\mathcal{O}(n^2)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(1)$ | No |
| **Bubble Sort** | $\mathcal{O}(n)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(1)$ | Yes |
| **Merge Sort** | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n)$ | Yes |
| **Heap Sort** | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n \log n)$ | $\mathcal{O}(\log n)$ stack* | No |
| **Quick Sort (Lomuto)** | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n \log n)$ | $\mathcal{O}(n^2)$ | $\mathcal{O}(\log n)$ avg, $\mathcal{O}(n)$ worst** | No |
| **Radix Sort (LSD)** | $\mathcal{O}(d \cdot (n + k))$ | $\mathcal{O}(d \cdot (n + k))$ | $\mathcal{O}(d \cdot (n + k))$ | $\mathcal{O}(n + k)$ | Yes |

\* Heap Sort is in-place ($\mathcal{O}(1)$ extra memory for the data), but `maxHeapify` is implemented recursively, so this implementation uses $\mathcal{O}(\log n)$ call-stack space.

\*\* Both partitions are handled recursively, so stack depth reaches $\mathcal{O}(n)$ in the worst case. With the last element as pivot, already sorted or reversed input is the worst case for Lomuto Quick Sort, and the benchmark below shows it.

For Radix Sort, $d$ is the number of digits in the largest key and $k = 10$ (base 10). Because $k$ is constant, the web calculator labels Radix Sort $\mathcal{O}(d \cdot n)$ and estimates its operations as $4n$, which assumes $d = 4$.

---

## Benchmark Results

Sample run, N = 5,000, Ubuntu 22.04/WSL, g++ 11.4; times vary by machine. Comparison and move counts are deterministic for these inputs.

### Random Array (Seed 42)

| Algorithm | Time (µs) | Comparisons | Swaps/Moves |
| :--- | :---: | :---: | :---: |
| **Selection Sort** | 15,200.63 | 12,497,500 | 4,994 |
| **Insertion Sort** | 7,614.69 | 6,245,818 | 6,240,824 |
| **Merge Sort** | 1,348.04 | 55,290 | 61,808 |
| **Heap Sort** | 919.72 | 107,691 | 57,094 |
| **Quick Sort** | 531.24 | 71,750 | 42,343 |
| **Radix Sort** | 477.92 | 4,999 | 20,000 |

### Already Sorted Array

| Algorithm | Time (µs) | Comparisons | Swaps/Moves |
| :--- | :---: | :---: | :---: |
| **Selection Sort** | 16,930.29 | 12,497,500 | 0 |
| **Insertion Sort** | 22.20 | 4,999 | 0 |
| **Merge Sort** | 937.40 | 32,004 | 61,808 |
| **Heap Sort** | 835.62 | 112,126 | 60,932 |
| **Quick Sort** | 35,663.08 | 12,497,500 | 12,502,499 |
| **Radix Sort** | 388.24 | 4,999 | 20,000 |

### Reversed Array

| Algorithm | Time (µs) | Comparisons | Swaps/Moves |
| :--- | :---: | :---: | :---: |
| **Selection Sort** | 16,270.45 | 12,497,500 | 2,500 |
| **Insertion Sort** | 20,075.69 | 12,497,500 | 12,497,500 |
| **Merge Sort** | 704.81 | 29,804 | 61,808 |
| **Heap Sort** | 801.48 | 103,227 | 53,436 |
| **Quick Sort** | 26,702.30 | 12,497,500 | 6,252,499 |
| **Radix Sort** | 413.51 | 4,999 | 20,000 |

### Reading the Results

- Radix Sort does not compare elements while sorting. Its "comparisons" are the $n - 1$ checks used to find the largest value.
- Merge Sort's "moves" are writes back into the array during merging.
- On sorted input, Quick Sort makes $n(n-1)/2 = 12{,}497{,}500$ comparisons, which is the Lomuto worst case.

---

## Project Structure

```text
sorting-algorithms-visualizer/
├── cpp/
│   ├── include/
│   │   └── Sorter.hpp         # Header-only sorting implementations + SortMetrics
│   ├── src/
│   │   └── main.cpp           # CLI benchmark driver (3 inputs, N = 5000)
│   └── Makefile               # g++ -std=c++17 -Wall -Wextra -O3
├── docs/
│   ├── Complexity_Analysis.md # Complexity matrix and recurrence sketches
│   └── Algorithms_Guide.md    # Short reference with pseudocode
├── web/
│   └── index.html             # Self-contained visualizer & complexity calculator
├── .gitignore
├── LICENSE                    # MIT License
└── README.md                  # Project documentation
```

---

## Getting Started

### Prerequisites

- **Web Visualizer:** None. `web/index.html` is a single self-contained file with no build step or dependencies.
- **C++ Benchmark:** `g++` with C++17 support, and GNU `make` and a POSIX shell, because the Makefile uses `mkdir -p` and `rm -rf`. On Windows, use WSL or MinGW/MSYS2.

### Build

```bash
cd cpp

# Compile (g++ -std=c++17 -Wall -Wextra -O3) into bin/benchmark
make

# Remove build output
make clean
```

### Run

Open the web visualizer directly in any modern browser:

```bash
# Windows
start web/index.html

# macOS
open web/index.html

# Linux / WSL
xdg-open web/index.html
```

Build the C++ benchmark if needed, then run it:

```bash
cd cpp
make run
```

---

## Documentation

- [Complexity_Analysis.md](docs/Complexity_Analysis.md): the complexity matrix plus best- and worst-case reasoning and recurrence sketches for Insertion, Selection, Merge, Quick, and Heap Sort.
- [Algorithms_Guide.md](docs/Algorithms_Guide.md): a short description of each C++ algorithm, with pseudocode for all of them except Radix Sort, which is described in prose.

---

## License

This project is licensed under the [MIT License](LICENSE).

---

Created by **Josue Torres Sibaja** · [Portfolio](https://josuetorressibaja.com/) · [LinkedIn](https://www.linkedin.com/in/josue-torres-sibaja/) · [Email](mailto:dev.josue.torres@gmail.com)
