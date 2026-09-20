# Inversion Count

**Technique:** Fenwick frequency tree plus coordinate compression

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$. Count the number of pairs of indices $(i, j)$ such that $i < j$ and $a_i > a_j$.

Values may be negative or as large as $10^9$ in absolute value, so compress them onto a Fenwick tree used as a frequency table. Scan from left to right: the query is the number of already-seen values strictly greater than $a_i$, then insert $a_i$.

## Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

## Output

Print one integer, the number of inversions.

## Sample 1

Input:

```
5
2 4 1 3 5
```

Output:

```
3
```

## Run

From the repository root, after writing `fenwick_tree-count_inversions.student.cpp`:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/count_inversions
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/count_inversions --solution
```
