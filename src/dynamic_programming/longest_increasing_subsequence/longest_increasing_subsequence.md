# Longest Increasing Subsequence

**Technique:** longest strictly increasing subsequence (patience sorting)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $n$ integers. Find one longest strictly increasing subsequence and print its values in order.

Maintain `tails[len]`, the index of the smallest tail of any increasing subsequence of length `len+1`. Binary search with `lower_bound` processes the array in $O(n \log n)$. Store predecessors so you can reconstruct the actual values, not only the length. Do not use $O(n^2)$ DP.

## Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_0, a_1, \ldots, a_{n-1}$ ($|a_i| \le 10^9$).

## Output

The first line contains $k$, the length of a longest strictly increasing subsequence.

The second line contains $k$ integers: the values of one such subsequence, in increasing order.

## Sample 1

Input:

```
7
3 4 -1 0 6 2 3
```

Output:

```
4
-1 0 2 3
```

## Run

From the repository root, after writing `longest_increasing_subsequence.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/longest_increasing_subsequence
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/longest_increasing_subsequence --solution
```
