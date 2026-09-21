# Suffix Array

**Technique:** suffix array by doubling

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a string $s$ of length $n$. Print the starting indices of all suffixes of $s$ in lexicographic order.

Build the suffix array by doubling: rank suffixes by their first $2^k$ characters using the ranks of length $2^{k-1}$. Sort the $n$ cyclic pairs and reassign ranks until they are unique. Do not compare two suffixes character by character in $O(n)$ per pair.

## Input

The first line contains one integer $n$ ($1 \le n \le 10^5$).

The second line contains the string $s$ of length $n$. It uses only lowercase English letters.

## Output

Print $n$ integers: the 0-based starting indices of the suffixes in sorted order.

## Sample 1

Input:

```
6
banana
```

Output:

```
5 3 1 0 4 2
```

## Run

From the repository root, after writing `suffix_array.student.cpp`:

```sh
./scripts/check.sh src/strings/suffix_array
```

To run the reference solution instead:

```sh
./scripts/check.sh src/strings/suffix_array --solution
```
