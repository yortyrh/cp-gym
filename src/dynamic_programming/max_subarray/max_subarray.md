# Maximum Subarray

**Technique:** Kadane's algorithm (maximum subarray)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $n$ integers. Find a non-empty contiguous subarray whose sum is maximum, and print that sum.

Scan left to right: keep the best suffix ending at the current index (restart from $a_i$ when that is better) and the global best. This is $O(n)$. Do not enumerate all $O(n^2)$ ranges.

## Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_0, a_1, \ldots, a_{n-1}$ ($|a_i| \le 10^9$).

## Output

Print one integer: the maximum subarray sum.

## Sample 1

Input:

```
9
-2 1 -3 4 -1 2 1 -5 4
```

Output:

```
6
```

## Run

From the repository root, after writing `max_subarray.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/max_subarray
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/max_subarray --solution
```
