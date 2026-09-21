# Bounded Knapsack

**Technique:** bounded knapsack via binary splitting

Time limit: 1 s
Memory limit: 256 MB

## Problem

You have $n$ item types. Type $i$ has weight $w_i$, value $v_i$, and may be taken at most $k_i$ times. Compute the maximum total value whose weights sum to at most $W$.

Split each count $k_i$ into groups of sizes $1, 2, 4, \ldots$ plus a remainder. Each group becomes one 0-1 item. Then run 0-1 knapsack with capacity decreasing. Do not loop $k_i$ times on the original type.

## Input

The first line contains two integers $n$ and $W$ ($1 \le n \le 100$, $1 \le W \le 10^5$).

Each of the next $n$ lines contains three integers $w_i$, $v_i$, and $k_i$ ($1 \le w_i \le W$, $1 \le v_i \le 10^9$, $1 \le k_i \le 10^6$).

## Output

Print one integer: the maximum total value.

## Sample 1

Input:

```
2 10
3 4 3
4 5 2
```

Output:

```
13
```

## Run

From the repository root, after writing `knapsack_zero_one-bounded.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/knapsack_zero_one/bounded
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/knapsack_zero_one/bounded --solution
```
