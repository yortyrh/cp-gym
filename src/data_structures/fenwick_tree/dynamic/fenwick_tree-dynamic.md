# Compressed Online Frequency Queries

**Technique:** Fenwick tree on a coordinate-compressed universe

Time limit: 1 s
Memory limit: 256 MB

## Problem

Start with an empty multiset. Values now lie in $[1, 10^9]$, so you cannot allocate a Fenwick tree of that size. Read every query first, compress the distinct integers onto ranks $1..k$, then run a Fenwick frequency tree on $k$.

Operations:

- `1 x` — insert one occurrence of $x$
- `2 x` — erase one occurrence of $x$ (the input guarantees that $x$ is present)
- `3 l r` — print how many stored values lie in the inclusive range $[l, r]$

## Input

The first line contains one integer $q$ ($1 \le q \le 2 \cdot 10^5$). There is no universe size $n$.

Each of the next $q$ lines contains one query. All integers $x$, $l$, and $r$ satisfy $1 \le x, l, r \le 10^9$ and, for type 3, $l \le r$.

## Output

For every query of type 3, print the count on its own line.

## Sample 1

Input:

```
6
1 1000000000
1 7
1 1000000000
3 7 1000000000
2 1000000000
3 1 10
```

Output:

```
3
1
```

## Run

From the repository root, after writing `fenwick_tree-dynamic.student.cpp`:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/dynamic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/dynamic --solution
```
