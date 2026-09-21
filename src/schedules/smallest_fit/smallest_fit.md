# Smallest Fit Assignment

**Technique:** greedy smallest-fit matching

Time limit: 1 s
Memory limit: 256 MB

## Problem

Each demand must be assigned a distinct supply that is at least as large as the demand. Always give a demand the smallest remaining supply that still fits. Print the sum of the chosen supplies, or `-1` if some demand cannot be served.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le m \le 10^5$).

The second line contains $n$ integers, the demands.

The third line contains $m$ integers, the supplies. All values are in $1..10^9$.

## Output

Print the total of chosen supplies, or `-1`.

## Sample 1

Input:

```
2 3
5 4
3 4 7
```

Output:

```
11
```

## Run

From the repository root, after writing `smallest_fit.student.cpp`:

```sh
./scripts/check.sh src/schedules/smallest_fit
```

To run the reference solution instead:

```sh
./scripts/check.sh src/schedules/smallest_fit --solution
```
