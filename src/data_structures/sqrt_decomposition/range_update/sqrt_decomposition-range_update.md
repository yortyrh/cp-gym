# Range Add, Range Sum

**Technique:** sqrt decomposition with lazy block adds

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. There are two kinds of queries:

- `1 l r v` — add $v$ to every element of the inclusive range $[l, r]$
- `2 l r` — print $a_l + \cdots + a_r$

Indices are 1-based.

Split the array into blocks of length about $\sqrt{n}$. Store each block's sum and a lazy add for that block. A range add that covers a whole block updates the lazy value and the stored block sum; a partial block is applied to the leftover elements. A range sum adds stored block sums in the middle and `a_i + lazy` on the two ends.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains one query. For type 1, $1 \le l \le r \le n$ and $|v| \le 10^9$. For type 2, $1 \le l \le r \le n$. Every answer fits in a signed 64-bit integer.

## Output

For every query of type 2, print the range sum on its own line.

## Sample 1

Input:

```
5 3
1 1 1 1 1
1 2 4 3
2 1 5
2 2 3
```

Output:

```
14
8
```

## Run

From the repository root, after writing `sqrt_decomposition-range_update.student.cpp`:

```sh
./scripts/check.sh src/data_structures/sqrt_decomposition/range_update
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/sqrt_decomposition/range_update --solution
```
