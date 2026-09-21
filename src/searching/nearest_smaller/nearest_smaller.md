# Nearest Smaller Left

**Technique:** nearest smaller to the left (monotonic stack)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers. For each position $i$, find the nearest index $j < i$ such that $a_j < a_i$. If several such indices exist, take the rightmost one. If none exists, the answer is $0$. Indices are 1-based.

Maintain a stack of candidates with increasing values. Scan from left to right and pop any index whose value is at least $a_i$. The remaining top is the nearest strictly smaller neighbor on the left.

## Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, \ldots, a_n$ ($1 \le a_i \le 10^9$).

## Output

Print $n$ integers, the answers for positions $1, \ldots, n$, separated by spaces.

## Sample 1

Input:

```
5
1 3 2 4 2
```

Output:

```
0 1 1 3 1
```

## Run

From the repository root, after writing `nearest_smaller.student.cpp`:

```sh
./scripts/check.sh src/searching/nearest_smaller
```

To run the reference solution instead:

```sh
./scripts/check.sh src/searching/nearest_smaller --solution
```
