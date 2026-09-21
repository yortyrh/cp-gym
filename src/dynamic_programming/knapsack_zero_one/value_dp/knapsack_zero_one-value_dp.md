# Knapsack with Huge Capacity

**Technique:** 0-1 knapsack DP over value (minimize weight)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You have $n$ items. Item $i$ has weight $w_i$ and value $v_i$. Each item may be taken at most once. Compute the maximum total value of a subset whose weights sum to at most $W$.

Here $W$ may be as large as $10^9$, so an array indexed by capacity does not fit. The values are small: if $S$ is the sum of all $v_i$, then $S \le 10^5$. Let `dp[v]` be the minimum weight needed to obtain value exactly $v$. Process items with $v$ decreasing. The answer is the largest $v$ with `dp[v] \le W`.

## Input

The first line contains two integers $n$ and $W$ ($1 \le n \le 100$, $1 \le W \le 10^9$).

Each of the next $n$ lines contains two integers $w_i$ and $v_i$ ($1 \le w_i \le 10^9$, $1 \le v_i \le 1000$). The sum of all $v_i$ is at most $10^5$.

## Output

Print one integer: the maximum total value.

## Sample 1

Input:

```
3 7
4 5
3 6
5 8
```

Output:

```
11
```

## Run

From the repository root, after writing `knapsack_zero_one-value_dp.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/knapsack_zero_one/value_dp
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/knapsack_zero_one/value_dp --solution
```
