# Iterative Point Assign, Range Sum

**Technique:** iterative segment tree (point assign, range sum)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. There are two kinds of queries:

- `1 i v` — set $a_i$ equal to $v$
- `2 l r` — print the sum $a_l + a_{l+1} + \cdots + a_r$

Indices are 1-based and ranges are inclusive.

Store the array in an iterative segment tree whose leaves occupy `tree[n .. 2n)`. Each inner node is the sum of its two children. A point assign and an inclusive range sum both walk $O(\log n)$ nodes, so all queries run in $O((n + q)\log n)$ time.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains one query. For type 1, $1 \le i \le n$ and $|v| \le 10^9$. For type 2, $1 \le l \le r \le n$.

## Output

For every query of type 2, print the range sum on its own line.

## Sample 1

Input:

```
6 5
4 -2 5 1 3 9
2 1 6
2 2 2
1 2 8
2 1 3
2 4 6
```

Output:

```
20
-2
17
13
```

## Run

From the repository root, after writing `segment_tree-classic.student.cpp`:

```sh
./scripts/check.sh src/data_structures/segment_tree/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/segment_tree/classic --solution
```
