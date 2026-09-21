# Point Add, Range Sum

**Technique:** sqrt decomposition (blocks of length about $\sqrt{n}$)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. There are two kinds of queries:

- `1 i v` — add $v$ to $a_i$
- `2 l r` — print $a_l + a_{l+1} + \cdots + a_r$

Indices are 1-based and ranges are inclusive.

Split the array into consecutive blocks of length about $\sqrt{n}$ and store the sum of each block. A point add updates one element and its block sum in $O(1)$ time. A range sum walks $O(\sqrt{n})$ block sums plus leftover elements on the two ends.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains one query. For type 1, $1 \le i \le n$ and $|v| \le 10^9$. For type 2, $1 \le l \le r \le n$. Every answer fits in a signed 64-bit integer.

## Output

For every query of type 2, print the range sum on its own line.

## Sample 1

Input:

```
5 3
1 2 3 4 5
2 2 4
1 3 5
2 1 5
```

Output:

```
9
20
```

## Run

From the repository root, after writing `sqrt_decomposition-classic.student.cpp`:

```sh
./scripts/check.sh src/data_structures/sqrt_decomposition/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/sqrt_decomposition/classic --solution
```
