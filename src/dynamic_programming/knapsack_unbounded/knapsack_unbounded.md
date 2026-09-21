# Unbounded Knapsack

**Technique:** unbounded knapsack (iterate capacity increasing)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You have $n$ item types. Type $i$ has weight $w_i$ and value $v_i$. You may take each type any number of times. Compute the maximum total value whose weights sum to at most $W$.

Use a 0-based array `dp[w]`: the best value with capacity $w$. For each type, loop $w$ from $w_i$ up to $W$ so the type can be reused.

## Input

The first line contains two integers $n$ and $W$ ($1 \le n \le 100$, $1 \le W \le 10^5$).

Each of the next $n$ lines contains two integers $w_i$ and $v_i$ ($1 \le w_i \le W$, $1 \le v_i \le 10^9$).

## Output

Print one integer: the maximum total value.

## Sample 1

Input:

```
2 5
2 3
3 4
```

Output:

```
7
```

## Run

From the repository root, after writing `knapsack_unbounded.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/knapsack_unbounded
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/knapsack_unbounded --solution
```
