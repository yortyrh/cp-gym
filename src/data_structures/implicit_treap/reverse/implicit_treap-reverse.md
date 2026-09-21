# Reversals and Range Sums

**Technique:** implicit treap with lazy reverse

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ operations:

- `1 l r` — reverse the inclusive subarray $[l, r]$
- `2 l r` — print $a_l + \cdots + a_r$

Indices are 1-based.

Build an implicit treap on the array. Store a lazy reverse flag on each node. Push the flag before `split`/`merge` look at a node's children: swap the child pointers and toggle the flag on both children. Reverse $[l, r]$ by splitting out the middle segment and toggling its flag. Subtree sums are unchanged by a reverse.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains one operation. For both types, $1 \le l \le r \le n$. Every answer fits in a signed 64-bit integer.

## Output

For every operation of type 2, print the range sum on its own line.

## Sample 1

Input:

```
5 5
1 2 3 4 5
1 2 4
2 1 5
1 1 5
2 1 3
2 4 5
```

Output:

```
15
10
5
```

## Run

From the repository root, after writing `implicit_treap-reverse.student.cpp`:

```sh
./scripts/check.sh src/data_structures/implicit_treap/reverse
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/implicit_treap/reverse --solution
```
