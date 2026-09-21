# Maximum Average Segment

**Technique:** binary search the average plus prefix check

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $n$ integers and a minimum length $k$. Find a contiguous segment of length at least $k$ whose average is maximum, and print that average.

Binary-search the candidate average $t$. A segment of length at least $k$ has average at least $t$ if and only if some segment of the sequence $(a_i - t)$ has nonnegative sum and length at least $k$. Check that with prefix sums in $O(n)$. Arrays are 0-based.

## Input

The first line contains two integers $n$ and $k$ ($1 \le k \le n \le 10^5$).

The second line contains $n$ integers $a_0, a_1, \ldots, a_{n-1}$ ($|a_i| \le 10^9$).

## Output

Print one real number: the maximum average, with exactly $10$ digits after the decimal point.

## Sample 1

Input:

```
3 2
1 2 3
```

Output:

```
2.5000000000
```

## Run

From the repository root, after writing `maximum_average_segment.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/maximum_average_segment
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/maximum_average_segment --solution
```
