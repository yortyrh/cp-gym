# Counting Sort

**Technique:** counting sort

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $n$ integers, each in the range $0 \ldots c$. Print them in non-decreasing order.

Use counting sort: build a frequency array of size $c + 1$, then write each value $v$ as many times as it occurs. Do not compare elements pairwise and do not call `std::sort`. Because $c$ is $O(n)$, the algorithm runs in $O(n + c)$ time.

## Input

The first line contains two integers $n$ and $c$ ($1 \le n \le 2 \cdot 10^5$, $0 \le c \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le c$).

## Output

Print $n$ integers in non-decreasing order, separated by spaces.

## Sample 1

Input:

```
6 4
4 1 3 4 1 2
```

Output:

```
1 1 2 3 4 4
```

## Run

From the repository root, after writing `counting_sort-classic.student.cpp`:

```sh
./scripts/check.sh src/sorting/counting_sort/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/sorting/counting_sort/classic --solution
```
