# Subset Sum

**Technique:** subset-sum DP (boolean 0-1 knapsack)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $n$ positive integers and a target $S$. Decide whether some subset of the numbers sums to exactly $S$. Each number may be used at most once.

Use a 0-based boolean array `reachable[s]`. Start from `reachable[0] = true`. For each number, loop $s$ from $S$ down to that number.

## Input

The first line contains two integers $n$ and $S$ ($1 \le n \le 100$, $1 \le S \le 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^5$).

## Output

Print `YES` if a subset sums to $S$, otherwise print `NO`.

## Sample 1

Input:

```
3 5
2 3 5
```

Output:

```
YES
```

## Run

From the repository root, after writing `subset_sum.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/subset_sum
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/subset_sum --solution
```
