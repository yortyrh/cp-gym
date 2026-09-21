# Crate Gluing

**Technique:** Knuth optimization (adjacent merges)

Time limit: 1 s
Memory limit: 256 MB

## Problem

$n$ crates sit in a row. You repeatedly glue two adjacent blocks into one. Gluing two blocks of total weight $s$ costs $s$. Continue until a single block remains. Compute the minimum total cost.

Let `dp[l][r]` be the minimum cost to glue crates $l, \ldots, r$ together, and let `opt[l][r]` be an optimal split. Then
`dp[l][r] = min_mid (dp[l][mid] + dp[mid+1][r] + sum[l..r])`.
The cost satisfies Knuth's inequality, so `opt[l][r-1] \le opt[l][r] \le opt[l+1][r]`. Fill by increasing length and only scan that range of splits.

## Input

The first line contains one integer $n$ ($1 \le n \le 300$).

The second line contains $n$ integers $a_1, \ldots, a_n$ ($1 \le a_i \le 10^6$).

## Output

Print one integer: the minimum gluing cost. If $n = 1$, print $0$.

## Sample 1

Input:

```
4
1 3 2 4
```

Output:

```
20
```

## Run

From the repository root, after writing `knuth_optimization.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/knuth_optimization
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/knuth_optimization --solution
```
