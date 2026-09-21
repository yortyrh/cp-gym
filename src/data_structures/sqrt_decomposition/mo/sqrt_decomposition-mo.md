# Distinct Values on a Range

**Technique:** Mo's algorithm (offline sqrt-ordered range queries)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. Each query asks how many distinct values appear in the inclusive range $[l, r]$.

All queries are known in advance. Sort them by the block of $l$ (blocks of length about $\sqrt{n}$) and then by $r$. Maintain a sliding window $[cl, cr]$ together with a frequency table of values in $1..10^6$. Expanding or shrinking the window by one index updates the distinct count in $O(1)$ time.

Indices are 1-based. Do not answer the queries online.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^6$).

Each of the next $q$ lines contains two integers $l$ and $r$ ($1 \le l \le r \le n$).

## Output

For every query, print the number of distinct values on $[l, r]$ on its own line. Print answers in the original input order.

## Sample 1

Input:

```
6 4
1 2 1 3 2 1
1 3
1 6
4 6
2 2
```

Output:

```
2
3
3
1
```

## Run

From the repository root, after writing `sqrt_decomposition-mo.student.cpp`:

```sh
./scripts/check.sh src/data_structures/sqrt_decomposition/mo
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/sqrt_decomposition/mo --solution
```
