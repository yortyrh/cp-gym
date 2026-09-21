# Minimum-Cost Flow

**Technique:** successive shortest paths min-cost flow

Time limit: 1 s
Memory limit: 256 MB

## Problem

A directed network has $n$ vertices labeled $1, 2, \ldots, n$. Each edge has a capacity and a cost per unit of flow. Send as much flow as possible from $s$ to $t$, at most `flow_limit` units, and among such flows choose one of minimum total cost.

Use successive cheapest residual paths (potentials keep reduced costs non-negative for Dijkstra). The network is small.

## Input

The first line contains five integers $n$, $m$, $s$, $t$, and `flow_limit` ($2 \le n \le 40$, $0 \le m \le 120$, $1 \le s, t \le n$, $0 \le$ `flow_limit` $\le 1000$).

Each of the next $m$ lines contains four integers $u$, $v$, $c$, and $w$ ($1 \le u, v \le n$, $0 \le c \le 100$, $|w| \le 100$): a directed edge of capacity $c$ and cost $w$.

## Output

Print two integers: the amount of flow sent and its total cost.

## Sample 1

Input:

```
4 4 1 4 2
1 2 1 2
1 3 1 5
2 4 1 3
3 4 1 1
```

Output:

```
2 11
```

## Run

From the repository root, after writing `min_cost_flow.student.cpp`:

```sh
./scripts/check.sh src/graphs/min_cost_flow
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/min_cost_flow --solution
```
