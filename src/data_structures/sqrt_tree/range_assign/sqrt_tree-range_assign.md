# Range Assign, Range Minimum

**Technique:** sqrt-tree mass-update analogue (lazy assignment on blocks)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. There are two kinds of queries:

- `1 l r v` — set every element of the inclusive range $[l, r]$ equal to $v$
- `2 l r` — print $\min(a_l, a_{l+1}, \ldots, a_r)$

Indices are 1-based.

This is the mass-update analogue of a sqrt-tree: split the array into blocks of length about $\sqrt{n}$. Store each block's minimum. A range assignment that covers a whole block is stored as a lazy value on that block; a partial block is pushed, written element-wise, and rebuilt. A range minimum uses lazy values or stored block minima on whole blocks and scans $O(\sqrt{n})$ leftover elements. The constraints keep $O((n + q)\sqrt{n})$ acceptable.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 5 \cdot 10^4$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains one query. For type 1, $1 \le l \le r \le n$ and $|v| \le 10^9$. For type 2, $1 \le l \le r \le n$.

## Output

For every query of type 2, print the range minimum on its own line.

## Sample 1

Input:

```
5 5
5 4 3 2 1
1 2 4 9
2 1 5
1 5 5 0
2 2 5
2 1 4
```

Output:

```
1
0
5
```

## Run

From the repository root, after writing `sqrt_tree-range_assign.student.cpp`:

```sh
./scripts/check.sh src/data_structures/sqrt_tree/range_assign
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/sqrt_tree/range_assign --solution
```
