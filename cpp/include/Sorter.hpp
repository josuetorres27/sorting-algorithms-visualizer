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
  static SortMetrics selectionSort(int *A, int n) {
    SortMetrics metrics;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n - 1; ++i) {
      int minIndex = i;
      for (int j = i + 1; j < n; ++j) {
        metrics.comparisons++;
        if (A[j] < A[minIndex]) {
          minIndex = j;
        }
      }
      if (minIndex != i) {
        swapElements(A[i], A[minIndex]);
        metrics.swaps++;
      }
    }

    auto end = std::chrono::high_resolution_clock::now();
    metrics.elapsedMicroseconds = std::chrono::duration<double, std::micro>(end - start).count();
    return metrics;
  }

  static SortMetrics insertionSort(int *A, int n) {
    SortMetrics metrics;
    auto start = std::chrono::high_resolution_clock::now();

    for (int j = 1; j < n; ++j) {
      int key = A[j];
      int i = j - 1;

      while (i >= 0) {
        metrics.comparisons++;
        if (A[i] > key) {
          A[i + 1] = A[i];
          metrics.swaps++;
          --i;
        } else {
          break;
        }
      }
      A[i + 1] = key;
    }

    auto end = std::chrono::high_resolution_clock::now();
    metrics.elapsedMicroseconds = std::chrono::duration<double, std::micro>(end - start).count();
    return metrics;
  }
};
