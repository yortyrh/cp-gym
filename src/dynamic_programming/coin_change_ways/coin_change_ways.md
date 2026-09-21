# Coin Combinations

**Technique:** unbounded knapsack DP (number of combinations)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You have $n$ coin denominations and an unlimited supply of each. Count the number of unordered combinations whose values sum to `amount`. Order does not matter: $1+2$ and $2+1$ are the same combination. Print the answer modulo $10^9+7$.

Use a 0-based array `ways[x]`. Set `ways[0] = 1`. Loop coins in the outer loop and amounts from the coin upward so each combination is counted once.

## Input

The first line contains two integers $n$ and `amount` ($1 \le n \le 100$, $1 \le amount \le 10^4$).

The second line contains $n$ positive integers, the coin denominations (each at most $10^4$).

## Output

Print one integer: the number of unordered combinations modulo $10^9+7$.

## Sample 1

Input:

```
2 4
1 2
```

Output:

```
3
```

## Run

From the repository root, after writing `coin_change_ways.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/coin_change_ways
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/coin_change_ways --solution
```
