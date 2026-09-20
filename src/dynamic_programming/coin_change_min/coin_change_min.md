# Minimum Coins

**Technique:** unbounded knapsack DP (minimum coins)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You have $n$ coin denominations and an unlimited supply of each. Compute the fewest coins whose values sum to `amount`. If it is impossible, print `-1`.

Use 0-based DP: `dp[x]` is the fewest coins that sum to $x$. Greedy choice of the largest coin is not required to be correct, so do not use it.

## Input

The first line contains two integers $n$ and `amount` ($1 \le n \le 100$, $1 \le amount \le 10^4$).

The second line contains $n$ positive integers, the coin denominations (each at most $10^4$).

## Output

Print one integer: the minimum number of coins, or `-1` if `amount` cannot be formed.

## Sample 1

Input:

```
3 12
1 5 10
```

Output:

```
3
```

## Run

From the repository root, after writing `coin_change_min.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/coin_change_min
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/coin_change_min --solution
```
