# Warehouse Walks

**Technique:** count paths in a grid with obstacles (DP modulo $10^9+7$)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A warehouse is an $n \times m$ grid. `.` is an open cell and `#` is a blocked crate. You start at the top-left cell and may move only right or down. Count the walks that reach the bottom-right cell.

Let `dp[i][j]` be the number of ways to reach cell $(i, j)$ modulo $10^9+7$. A blocked cell contributes $0$. Every open cell sums the ways from the cell above and the cell to the left. If the start is blocked, the answer is $0$.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n, m \le 1000$).

Each of the next $n$ lines contains a string of length $m$ consisting of `.` and `#`.

## Output

Print one integer: the number of paths modulo $10^9+7$.

## Sample 1

Input:

```
3 4
....
.#..
....
```

Output:

```
4
```

## Run

From the repository root, after writing `grid_paths.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/grid_paths
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/grid_paths --solution
```
