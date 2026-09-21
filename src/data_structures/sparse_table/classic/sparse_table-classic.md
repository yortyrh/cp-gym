# Static Range Minimum Queries

**Technique:** sparse table (idempotent RMQ, overlapping intervals)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a static array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. There are no updates. For each query $l\ r$, print $\min(a_l, a_{l+1}, \ldots, a_r)$. Indices are 1-based and ranges are inclusive.

Build a sparse table: `st[k][i]` is the minimum of $2^k$ consecutive elements starting at $i$. A query of length $L$ uses two overlapping blocks of size $2^{\lfloor \log_2 L \rfloor}$. Build in $O(n \log n)$ and answer each query in $O(1)$.

Do not scan the range on every query. Do not use a Fenwick tree or a segment tree for this exercise.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains two integers $l$ and $r$ ($1 \le l \le r \le n$).

## Output

For every query, print the range minimum on its own line.

## Sample 1

Input:

```
6 4
4 2 5 1 6 3
1 3
2 4
1 6
5 5
```

Output:

```
2
1
1
6
```

## Run

From the repository root, after writing `sparse_table-classic.student.cpp`:

```sh
./scripts/check.sh src/data_structures/sparse_table/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/sparse_table/classic --solution
```
