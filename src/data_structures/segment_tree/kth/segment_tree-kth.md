# K-th Smallest in a Subarray

**Technique:** segment tree on compressed values (range k-th smallest)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a static array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. Each query is:

- `l r k` — print the $k$-th smallest value among $a_l, a_{l+1}, \ldots, a_r$ (1-based $k$, so $k = 1$ is the minimum of the range)

Indices are 1-based and ranges are inclusive. The input guarantees $1 \le k \le r - l + 1$.

Compress the distinct values, then build a segment tree on the compressed value axis. Each node stores the sorted list of positions whose values lie in that value segment. Walking from the root, count how many stored positions of the left child fall in $[l, r]$ and branch left or right to recover the $k$-th smallest in $O(\log^2 n)$ time.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains three integers $l$, $r$, and $k$ ($1 \le l \le r \le n$, $1 \le k \le r - l + 1$).

## Output

For every query, print the $k$-th smallest value of the inclusive range on its own line.

## Sample 1

Input:

```
6 4
5 -2 5 1 5 0
1 6 4
2 4 2
3 5 1
1 3 2
```

Output:

```
5
1
1
5
```

## Run

From the repository root, after writing `segment_tree-kth.student.cpp`:

```sh
./scripts/check.sh src/data_structures/segment_tree/kth
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/segment_tree/kth --solution
```
