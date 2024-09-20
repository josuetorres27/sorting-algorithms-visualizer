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
  // Helper swap
  static inline void swapElements(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
  }

  // Quick Sort Partition (Lomuto scheme)
  static int partition(int *A, int p, int r, SortMetrics &metrics) {
    int pivot = A[r];
    int i = p - 1;

    for (int j = p; j < r; ++j) {
      metrics.comparisons++;
      if (A[j] <= pivot) {
        ++i;
        swapElements(A[i], A[j]);
        metrics.swaps++;
      }
    }
    swapElements(A[i + 1], A[r]);
    metrics.swaps++;
    return i + 1;
  }

  // Quick Sort Recursive
  static void quickSortRec(int *A, int p, int r, SortMetrics &metrics) {
    if (p < r) {
      int q = partition(A, p, r, metrics);
      quickSortRec(A, p, q - 1, metrics);
      quickSortRec(A, q + 1, r, metrics);
    }
  }

  // Merge Sort Merge Subroutine
  static void merge(int *A, int p, int q, int r, SortMetrics &metrics) {
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i) L[i] = A[p + i];
    for (int j = 0; j < n2; ++j) R[j] = A[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
      metrics.comparisons++;
      if (L[i] <= R[j]) {
        A[k++] = L[i++];
      } else {
        A[k++] = R[j++];
      }
      metrics.swaps++;
    }

    while (i < n1) {
      A[k++] = L[i++];
      metrics.swaps++;
    }
    while (j < n2) {
      A[k++] = R[j++];
      metrics.swaps++;
    }
  }

  // Merge Sort Recursive
  static void mergeSortRec(int *A, int p, int r, SortMetrics &metrics) {
    if (p < r) {
      int q = p + (r - p) / 2;
      mergeSortRec(A, p, q, metrics);
      mergeSortRec(A, q + 1, r, metrics);
      merge(A, p, q, r, metrics);
    }
  }


};
