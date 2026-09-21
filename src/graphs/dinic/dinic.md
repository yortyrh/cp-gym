# Maximum Flow (Dinic)

**Technique:** Dinic maximum flow

Time limit: 1 s
Memory limit: 256 MB

## Problem

A directed network has $n$ vertices labeled $1, 2, \ldots, n$ and $m$ edges. Edge $i$ goes from $u_i$ to $v_i$ with capacity $c_i$. Compute the maximum flow from source $s$ to sink $t$.

Dinic builds a level graph with BFS and then sends a blocking flow with DFS along admissible edges. The network is small, but still use Dinic (or an equivalent residual-graph method), not brute-force path listing.

## Input

The first line contains four integers $n$, $m$, $s$, and $t$ ($2 \le n \le 50$, $0 \le m \le 200$, $1 \le s, t \le n$).

Each of the next $m$ lines contains three integers $u$, $v$, and $c$ ($1 \le u, v \le n$, $0 \le c \le 1000$).

## Output

Print one integer: the maximum $s$-$t$ flow.

## Sample 1

Input:

```
6 10 1 6
1 2 16
1 3 13
2 3 10
3 2 4
2 4 12
4 3 9
3 5 14
5 4 7
4 6 20
5 6 4
```

Output:

```
23
```

## Run

From the repository root, after writing `dinic.student.cpp`:

```sh
./scripts/check.sh src/graphs/dinic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/dinic --solution
```
