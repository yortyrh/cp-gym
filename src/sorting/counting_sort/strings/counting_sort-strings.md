# Counting Sort for Strings

**Technique:** counting sort (LSD radix on equal-length strings)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $n$ strings of the same length $L$. Each string contains only lowercase English letters. Print the strings in lexicographical order.

Sort with counting sort on characters, one position at a time, from right to left (least-significant-digit radix sort). Each pass must be stable: strings that share the current character keep their previous relative order. Do not call `std::sort`. This is the same counting-sort idea used as a building block when sorting suffixes.

## Input

The first line contains two integers $n$ and $L$ ($1 \le n \le 10^5$, $1 \le L \le 20$, $n \cdot L \le 2 \cdot 10^5$).

Each of the next $n$ lines contains one string of length $L$.

## Output

Print the $n$ strings in lexicographical order, one per line.

## Sample 1

Input:

```
3 3
cab
abc
bac
```

Output:

```
abc
bac
cab
```

## Run

From the repository root, after writing `counting_sort-strings.student.cpp`:

```sh
./scripts/check.sh src/sorting/counting_sort/strings
```

To run the reference solution instead:

```sh
./scripts/check.sh src/sorting/counting_sort/strings --solution
```
