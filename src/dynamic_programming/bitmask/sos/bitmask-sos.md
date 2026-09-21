# Sum Over Subsets

**Technique:** SOS DP (sum over subsets)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $n$ and an array $a_0, a_1, \ldots, a_{2^n-1}$. For every mask $x$ ($0 \le x < 2^n$) compute

$$
F(x) = \sum_{y \subseteq x} a_y
$$

where $y \subseteq x$ means every bit set in $y$ is also set in $x$.

A naive loop over all pairs $(x, y)$ is $O(4^n)$. Use SOS DP: for each bit $i$, add `dp[mask ^ (1 << i)]` into `dp[mask]` when bit $i$ of `mask` is set. The result is $O(n\,2^n)$.

## Input

The first line contains one integer $n$ ($1 \le n \le 20$).

The second line contains $2^n$ integers $a_0, \ldots, a_{2^n-1}$ ($|a_i| \le 10^9$).

## Output

Print $2^n$ integers $F(0), F(1), \ldots, F(2^n-1)$, separated by spaces.

## Sample 1

Input:

```
2
1 2 4 8
```

Output:

```
1 3 5 15
```

## Run

From the repository root, after writing `bitmask-sos.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/bitmask/sos
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/bitmask/sos --solution
```
