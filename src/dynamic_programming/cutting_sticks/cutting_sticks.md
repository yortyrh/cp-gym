# Cutting Sticks

**Technique:** interval DP (minimum cost to cut a stick)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A stick occupies the interval $[0, L]$. You must cut it at $m$ given interior positions. Cutting a current piece costs its length. The order of cuts changes the total cost. Compute the minimum total cost of making every required cut.

Add the endpoints $0$ and $L$ to the cut list, sort, and remove duplicates. Let `cost[l][r]` be the minimum cost to finish all cuts strictly inside `points[l]..points[r]`. The last (or first remaining) cut of that piece costs `points[r] - points[l]`. Fill the table by increasing interval span. Arrays are 0-based.

## Input

The first line contains two integers $L$ and $m$ ($1 \le L \le 10^9$, $1 \le m \le 200$).

The second line contains $m$ integers, the cut positions ($1 \le c_i < L$).

## Output

Print one integer: the minimum total cutting cost.

## Sample 1

Input:

```
10 2
2 5
```

Output:

```
15
```

## Run

From the repository root, after writing `cutting_sticks.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/cutting_sticks
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/cutting_sticks --solution
```
