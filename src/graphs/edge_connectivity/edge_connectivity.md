# Edge Connectivity

**Technique:** edge connectivity by repeated max-flow

Time limit: 1 s
Memory limit: 256 MB

## Problem

An undirected graph has $n$ vertices labeled $1, 2, \ldots, n$ and $m$ edges. The edge connectivity is the size of a smallest set of edges whose removal disconnects the graph (or $0$ when $n \le 1$).

Give every undirected edge residual capacity $1$ in both directions. Compute maximum flow from vertex $1$ to every other vertex; the minimum of those values is the answer. $n$ is small.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 40$, $0 \le m \le 80$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$, $u \ne v$). The graph has no parallel edges.

## Output

Print one integer: the edge connectivity.

## Sample 1

Input:

```
3 2
1 2
2 3
```

Output:

```
1
```

## Run

From the repository root, after writing `edge_connectivity.student.cpp`:

```sh
./scripts/check.sh src/graphs/edge_connectivity
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/edge_connectivity --solution
```
