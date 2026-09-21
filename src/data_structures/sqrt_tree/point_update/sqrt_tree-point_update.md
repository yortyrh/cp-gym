# Point Update, Range Minimum

**Technique:** sqrt-tree / blocked minima with point rebuild

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. There are two kinds of queries:

- `1 i v` — set $a_i$ equal to $v$
- `2 l r` — print $\min(a_l, a_{l+1}, \ldots, a_r)$

Indices are 1-based and ranges are inclusive.

Keep the array in blocks of length about $\sqrt{n}$ and store the minimum of each block. A point update rebuilds only the affected block in $O(\sqrt{n})$ time. A range minimum walks $O(\sqrt{n})$ whole-block answers plus $O(\sqrt{n})$ elements on the two ends.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains one query. For type 1, $1 \le i \le n$ and $|v| \le 10^9$. For type 2, $1 \le l \le r \le n$.

## Output

For every query of type 2, print the range minimum on its own line.

## Sample 1

Input:

```
5 4
4 1 3 2 5
2 1 4
1 2 10
2 1 4
2 2 2
```

Output:

```
1
2
10
```

## Run

From the repository root, after writing `sqrt_tree-point_update.student.cpp`:

```sh
./scripts/check.sh src/data_structures/sqrt_tree/point_update
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/sqrt_tree/point_update --solution
```
