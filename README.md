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

## Technical Implementation

**File I/O & Parsing:**
- CSV file reading with `fopen`, `fgets`, `fscanf`
- Dynamic array allocation based on file line count
- Robust parsing (handles delimiters, newlines, EOF)

**Memory Management:**
- Stack-allocated arrays (fixed-size after file scan)
- No dynamic allocation (suitable for embedded systems)
- Efficient struct packing (date + 7 float fields)

**User Interface:**
- Interactive menu system (`menu.c`)
- Date input validation (YYYYMMDD format, range checking)
- Formatted output (temperature, chemical measurements)

**Code Organization:**
- Modular function design (swap, partition, heapify)
- Reusable CSV reader (`FileOpener`, `FileCounter`)
- Separation of concerns (I/O, sorting, searching)

---

## Performance Analysis

**Sorting Performance:**

| Algorithm | Time Complexity | Space | Stable | Use Case |
|-----------|-----------------|-------|--------|----------|
| **QuickSort** | O(n log n) avg | O(log n) | No | General-purpose |
| **HeapSort** | O(n log n) worst | O(1) | No | Guaranteed performance |
| **Counting Sort** | O(n + k) | O(k) | Yes | Integer keys, small range |
| **Insertion Sort** | O(n²) | O(1) | Yes | Small/nearly-sorted data |

**Search Performance:**

| Algorithm | Complexity | Prerequisite | Advantage |
|-----------|------------|--------------|-----------|
| **Binary Search** | O(log n) | Sorted array | Guaranteed logarithmic |
| **Interpolation** | O(log log n) avg | Sorted + uniform | Faster for uniform data |



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

## Usage

```bash
# Compile with GCC
gcc quicksort.c -o quicksort -lm
gcc heapsort.c -o heapsort -lm
gcc binarysearch.c -o binarysearch -lm
gcc InterpolationSearch.c -o interpolation -lm

# Run sorting
./quicksort   # Sorts by date, displays sorted records
./heapsort    # Heap-based sorting

# Run searching
./binarysearch
# Prompts: Enter date (MM/DD/YYYY)
# Output: Temperature for specified date

./interpolation
# Prompts: Enter date (YYYYMMDD)
# Output: Temperature with interpolation-based search
```

**Data Format (project.csv):**
```
MM/DD/YYYY, temp, phosphate, silicate, nitrite, nitrate, salinity, oxygen
1/15/2000, 18.5, 0.32, 5.2, 0.08, 2.1, 35.4, 6.8
...
```

---


## Institution

**University of Patras**  
**Department of Electrical and Computer Engineering**  
**Student ID:** 1084522  
**Course:** Data Structures  
**Project:** OCEAN - Oceanographic Data Analysis System (2021-2022)

---

*Demonstrating algorithm implementation and systems programming expertise for software engineering and embedded systems positions.*
