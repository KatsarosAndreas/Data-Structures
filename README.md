# Data Structures & Algorithms

Implementation of classical sorting and searching algorithms in C for oceanographic data analysis—demonstrating proficiency in algorithm design, complexity analysis, and systems programming.

## Overview

This project implements **sorting algorithms** (QuickSort, HeapSort, Counting Sort) and **search algorithms** (Binary Search, Interpolation Search) applied to real-world oceanographic datasets—foundational skills for systems programming, embedded software, and algorithm engineering roles.

**Key Focus Areas:**
- **Sorting Algorithms**: QuickSort, HeapSort, Counting Sort, Insertion Sort
- **Search Algorithms**: Binary Search, Interpolation Search
- **Data Structures**: Arrays, Heaps, Custom Structs
- **File I/O**: CSV parsing, dynamic memory management
- **Complexity Analysis**: O(n log n) vs. O(n) performance tradeoffs

---

## Project: OCEAN Data Analysis System

**Application:** Oceanographic sensor data processing and retrieval

**Dataset:** Marine measurements (temperature, phosphate, silicate, nitrite, nitrate, salinity, oxygen)  
**Date Range:** 2000-2019  
**Records:** ~1000+ time-series observations

**Data Structure:**
```c
typedef struct Okeanos {
    int mhnas, mera, xronos;  // Month, Day, Year
    float thermokrasia;        // Temperature
    float phosphate, silicate, nitrite, nitrate;
    float salinity, oxygen;
} Okeanos;
```

---

## Core Implementations

### Sorting Algorithms

**QuickSort** (`quicksort.c`)
- **Algorithm**: Partition-based divide-and-conquer
- **Complexity**: O(n log n) average, O(n²) worst case
- **Pivot Strategy**: Last element selection
- **Use Case**: General-purpose sorting for oceanographic records

**HeapSort** (`heapsort.c`)
- **Algorithm**: Max-heap construction + repeated extraction
- **Complexity**: O(n log n) guaranteed (worst-case optimal)
- **Heapify**: Bottom-up heap construction
- **Use Case**: Guaranteed performance for critical systems

**Counting Sort** (`counting_sort.c`)
- **Algorithm**: Integer-based frequency counting
- **Complexity**: O(n + k) where k = range
- **Application**: Sorting phosphate values (scaled to integers ×100)
- **Use Case**: Linear-time sorting for bounded ranges

**Insertion Sort** (`insertion_sort.c`)
- **Algorithm**: Incremental sorting via insertion
- **Complexity**: O(n²)
- **Use Case**: Small datasets, nearly-sorted data

---

### Search Algorithms

**Binary Search** (`binarysearch.c`)
- **Algorithm**: Divide-and-conquer on sorted arrays
- **Complexity**: O(log n)
- **Input**: User-specified date (MM/DD/YYYY format)
- **Output**: Temperature reading for exact date match
- **Prerequisite**: Sorted dataset (pre-sorted by date)

**Interpolation Search** (`InterpolationSearch.c`)
- **Algorithm**: Position-based estimation (assumes uniform distribution)
- **Complexity**: O(log log n) average for uniform data, O(n) worst case
- **Date Format**: YYYYMMDD (long integer representation)
- **Optimization**: Exploits temporal ordering of oceanographic data
- **Use Case**: Fast lookups in uniformly distributed time-series

---

## Code Files

**Sorting:**
- `quicksort.c` (147 lines): Partition-based sorting
- `heapsort.c` (139 lines): Max-heap sorting
- `counting_sort.c` (176 lines): Linear-time integer sorting
- `insertion_sort.c`: Incremental sorting

**Searching:**
- `binarysearch.c` (308 lines): Logarithmic search with user input
- `InterpolationSearch.c` (195 lines): Position-based search

**Utilities:**
- `menu.c` (197 lines): Interactive UI, data loading
- `bis.c`: Binary insertion sort variant

**Data:**
- `project.csv`: Oceanographic dataset (2000-2019)

---


## Institution

**University of Patras**  
**Department of Electrical and Computer Engineering**  
**Student ID:** 1084522  
**Course:** Data Structures  
**Project:** OCEAN - Oceanographic Data Analysis System (2021-2022)

---

*Demonstrating algorithm implementation and systems programming expertise for software engineering and embedded systems positions.*
