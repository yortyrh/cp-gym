# Range Frequency Queries

**Technique:** Fenwick tree as a frequency table on values $1..n$

Time limit: 1 s
Memory limit: 256 MB

## Problem

Start with an empty multiset. Values always lie in $1..n$ (no compression). Process $q$ operations:

- `1 x` — insert one occurrence of $x$
- `2 x` — erase one occurrence of $x$ (the input guarantees that $x$ is present)
- `3 l r` — print how many stored values lie in the inclusive range $[l, r]$

A 1-based Fenwick tree whose indices are the values themselves answers each update and range-frequency query in $O(\log n)$.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$). $n$ is the value universe.

Each of the next $q$ lines contains one query. All values $x$, $l$, and $r$ satisfy $1 \le x, l, r \le n$ and $l \le r$.

## Output

For every query of type 3, print the count on its own line.

## Sample 1

Input:

```
5 6
1 2
1 5
1 2
3 2 4
2 2
3 2 5
```

Output:

```
2
2
```

## Run

From the repository root, after writing `fenwick_tree-frequency_counting.student.cpp`:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/frequency_counting
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/frequency_counting --solution
```
