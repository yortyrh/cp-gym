# Minimum Interval Cover

**Technique:** greedy minimum interval cover

Time limit: 1 s
Memory limit: 256 MB

## Problem

Cover $[L, R]$ with as few given intervals as possible. Sort intervals by start time. While the covered prefix is still left of $R$, among intervals that start at or before the current coverage, pick the one that extends farthest. If none extends, covering is impossible.

## Input

The first line contains two integers $L$ and $R$ ($-10^9 \le L < R \le 10^9$).

The second line contains one integer $n$ ($1 \le n \le 10^5$).

Each of the next $n$ lines contains two integers $b_i$ and $e_i$ ($b_i \le e_i$).

## Output

Print the minimum number of intervals, or `-1` if covering is impossible.

## Sample 1

Input:

```
0 10
3
0 4
3 8
7 12
```

Output:

```
3
```

## Run

From the repository root, after writing `interval_cover.student.cpp`:

```sh
./scripts/check.sh src/schedules/interval_cover
```

To run the reference solution instead:

```sh
./scripts/check.sh src/schedules/interval_cover --solution
```
