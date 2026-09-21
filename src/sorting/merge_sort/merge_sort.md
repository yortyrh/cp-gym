# Merge Sort

**Technique:** merge sort

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $n$ integers. Print them in non-decreasing order.

Implement merge sort: split the array into two halves, sort each half recursively, then merge the two sorted halves in linear time. Do not call `std::sort` or any other library sort. The $O(n \log n)$ merge-sort bound is required; a quadratic sort is too slow.

## Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

## Output

Print $n$ integers in non-decreasing order, separated by spaces.

## Sample 1

Input:

```
5
5 1 4 2 3
```

Output:

```
1 2 3 4 5
```

## Run

From the repository root, after writing `merge_sort.student.cpp`:

```sh
./scripts/check.sh src/sorting/merge_sort
```

To run the reference solution instead:

```sh
./scripts/check.sh src/sorting/merge_sort --solution
```
