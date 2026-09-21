# Separate Convoys

**Technique:** maximum edge-disjoint paths (unit-capacity flow)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A directed road network has $n$ junctions and $m$ one-way roads. Each road may be used by at most one convoy. Compute the maximum number of convoys that can travel from junction $1$ to junction $n$ without sharing a road.

Give every edge capacity $1$ (parallel edges increase capacity). The answer is the maximum flow from $1$ to $n$. Find augmenting paths in the residual graph (Ford-Fulkerson, Dinic, or equivalent).

## Input

The first line contains two integers $n$ and $m$ ($2 \le n \le 80$, $0 \le m \le 400$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$, $u \neq v$), a directed road $u \rightarrow v$.

## Output

Print one integer: the maximum number of edge-disjoint paths from $1$ to $n$.

## Sample 1

Input:

```
4 5
1 2
1 3
2 4
3 4
2 3
```

Output:

```
2
```

## Run

From the repository root, after writing `disjoint_paths.student.cpp`:

```sh
./scripts/check.sh src/graphs/disjoint_paths
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/disjoint_paths --solution
```
