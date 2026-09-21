# Grid Tilings

**Technique:** profile bitmask DP

Time limit: 2 s
Memory limit: 256 MB

## Problem

Count the number of ways to tile an $n \times m$ grid using $1 \times 2$ and $2 \times 1$ tiles (rotations of a domino). Two tilings are different if some cell is covered by a different tile.

Go column by column. The mask of a column is the set of rows already covered by a horizontal tile that started in the previous column. Recurse inside a column to place a vertical domino or start a new horizontal domino. Do not backtrack over the whole grid.

Rotate the grid if needed so the mask size is $\min(n, m)$.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n, m \le 12$, $n \cdot m$ even).

## Output

Print one integer: the number of tilings.

## Sample 1

Input:

```
4 7
```

Output:

```
781
```

## Run

From the repository root, after writing `bitmask-counting_tilings.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/bitmask/counting_tilings
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/bitmask/counting_tilings --solution
```
