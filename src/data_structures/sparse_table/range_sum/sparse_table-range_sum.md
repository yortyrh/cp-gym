# Static Range Sum Queries

**Technique:** sparse table (disjoint power-of-two covering)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a static array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. There are no updates. For each query $l\ r$, print $a_l + a_{l+1} + \cdots + a_r$. Indices are 1-based and ranges are inclusive.

Sum is not idempotent, so you cannot answer a query with two overlapping blocks the way range-minimum does. Build `st[k][i]` as the sum of $2^k$ consecutive elements starting at $i$, then cover $[l, r]$ with disjoint power-of-two segments from largest to smallest in $O(\log n)$ per query.

Do not scan the range on every query. Do not use prefix sums, a Fenwick tree, or overlapping intervals.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains two integers $l$ and $r$ ($1 \le l \le r \le n$).

## Output

For every query, print the range sum on its own line.

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
11
8
21
6
```

## Run

From the repository root, after writing `sparse_table-range_sum.student.cpp`:

```sh
./scripts/check.sh src/data_structures/sparse_table/range_sum
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/sparse_table/range_sum --solution
```
