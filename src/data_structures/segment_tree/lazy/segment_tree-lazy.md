# Lazy Range Add, Range Sum

**Technique:** lazy segment tree (range add, range sum)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. There are two kinds of queries:

- `1 l r v` — add $v$ to every element of the inclusive range $[l, r]$
- `2 l r` — print $a_l + \cdots + a_r$

Indices are 1-based and ranges are inclusive.

Maintain a segment tree with lazy propagation: a pending add on a node is pushed to its children only when that node is split. Each range add and range sum runs in $O(\log n)$ time.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains one query. For type 1, $1 \le l \le r \le n$ and $|v| \le 10^9$. For type 2, $1 \le l \le r \le n$. Every answer fits in a signed 64-bit integer.

## Output

For every query of type 2, print the range sum on its own line.

## Sample 1

Input:

```
5 4
1 2 3 4 5
2 1 5
1 2 4 10
2 1 5
2 3 3
```

Output:

```
15
45
13
```

## Run

From the repository root, after writing `segment_tree-lazy.student.cpp`:

```sh
./scripts/check.sh src/data_structures/segment_tree/lazy
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/segment_tree/lazy --solution
```
