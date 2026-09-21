# Static Range Minimum

**Technique:** sqrt-tree (block prefix/suffix minima + sparse table on blocks)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a static array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. Each query asks for the minimum value on an inclusive range $[l, r]$. There are no updates.

Split the array into blocks of length about $\sqrt{n}$. Inside each block store prefix and suffix minima. On the sequence of block minima build a sparse table. A query that stays inside one block may scan that block; a query that spans several blocks combines the left suffix, the right prefix, and an $O(1)$ sparse-table lookup of the whole blocks in between.

Indices are 1-based.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains two integers $l$ and $r$ ($1 \le l \le r \le n$).

## Output

For every query, print the range minimum on its own line.

## Sample 1

Input:

```
7 3
4 1 3 2 5 0 8
1 4
4 6
7 7
```

Output:

```
1
0
8
```

## Run

From the repository root, after writing `sqrt_tree-classic.student.cpp`:

```sh
./scripts/check.sh src/data_structures/sqrt_tree/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/sqrt_tree/classic --solution
```
