/**
 * Sorting Algorithms Suite
 * File: Sorter.hpp
 *
 * High-performance, clean C++ implementation of fundamental sorting algorithms:
 * Selection Sort, Insertion Sort, Merge Sort, Heap Sort, Quick Sort, and Radix Sort.
 *
 * Author: Josue Torres Sibaja
 * Copyright (c) 2024-2025 Josue Torres Sibaja
 * Licensed under the MIT License.
 */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <chrono>

struct SortMetrics {
  unsigned long long comparisons = 0;
  unsigned long long swaps = 0;
  double elapsedMicroseconds = 0.0;
};

class Sorter {
 private:
  static inline void swapElements(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
  }

 public:
  // Sorting routines will be added incrementally
};
