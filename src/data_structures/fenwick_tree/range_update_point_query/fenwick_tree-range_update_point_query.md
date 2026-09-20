# Range Add, Point Query

**Technique:** Fenwick tree as a difference array (range update, point query)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. There are two kinds of queries:

- `1 l r v` — add $v$ to every element of the inclusive range $[l, r]$
- `2 i` — print $a_i$

Indices are 1-based.

Store the array as a difference sequence in a 1-based Fenwick tree: a range add becomes two point updates, and $a_i$ is a prefix sum.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains one query. For type 1, $1 \le l \le r \le n$ and $|v| \le 10^9$. For type 2, $1 \le i \le n$.

## Output

For every query of type 2, print $a_i$ on its own line.

## Sample 1

Input:

```
5 3
1 1 1 1 1
1 2 4 3
2 3
2 1
```

Output:

```
4
1
```

## Run

From the repository root, after writing `fenwick_tree-range_update_point_query.student.cpp`:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/range_update_point_query
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/range_update_point_query --solution
```
