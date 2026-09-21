# 0-1 Knapsack

**Technique:** 0-1 knapsack (iterate capacity decreasing)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You have $n$ items. Item $i$ has weight $w_i$ and value $v_i$. Each item may be taken at most once. Compute the maximum total value of a subset whose weights sum to at most $W$.

Use a 0-based array `dp[w]`: the best value with capacity $w$. After taking an item, loop $w$ from $W$ down to $w_i$ so that item is not reused.

## Input

The first line contains two integers $n$ and $W$ ($1 \le n \le 100$, $1 \le W \le 10^5$).

Each of the next $n$ lines contains two integers $w_i$ and $v_i$ ($1 \le w_i \le W$, $1 \le v_i \le 10^9$).

## Output

Print one integer: the maximum total value.

## Sample 1

Input:

```
3 5
2 3
3 4
4 5
```

Output:

```
7
```

## Run

From the repository root, after writing `knapsack_zero_one-classic.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/knapsack_zero_one/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/knapsack_zero_one/classic --solution
```
