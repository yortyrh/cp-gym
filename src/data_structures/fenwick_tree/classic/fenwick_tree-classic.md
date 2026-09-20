# Dynamic Range Sum Queries

**Technique:** Fenwick tree (point update, range query)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. There are two kinds of queries:

- `1 i v` — set $a_i$ equal to $v$
- `2 l r` — print the sum $a_l + a_{l+1} + \cdots + a_r$

Indices are 1-based and ranges are inclusive.

A 1-based Fenwick tree (binary indexed tree) with point updates and prefix sums processes all queries in $O((n + q)\log n)$ time.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains one query. For type 1, $1 \le i \le n$ and $|v| \le 10^9$. For type 2, $1 \le l \le r \le n$.

## Output

For every query of type 2, print the range sum on its own line.

## Sample 1

Input:

```
5 3
2 -1 3 5 4
2 2 4
1 2 5
2 1 2
```

Output:

```
7
7
```

## Run

From the repository root, after writing `fenwick_tree-classic.student.cpp`:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/classic --solution
```
