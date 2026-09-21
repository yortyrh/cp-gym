# Message Clusters

**Technique:** Tarjan strongly connected components

Time limit: 1 s
Memory limit: 256 MB

## Problem

A network has $n$ servers and $m$ one-way links. Two servers belong to the same cluster if each can reach the other along directed links (a strongly connected component).

Find the clusters. Number them $1, 2, \ldots, k$ in increasing order of the smallest server in each cluster.

Use Tarjan's one-DFS algorithm: discovery times, low-link values, and a stack of the current path. When `low[v] == tin[v]`, $v$ is an SCC root; pop the stack until $v$ to form that component. Kosaraju (two DFS passes on the transpose) is also accepted if the component numbering rule above is respected.

Vertices are 1-based in the input. Convert to 0-based at I/O if your arrays are 0-based.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$, $u \neq v$), a directed link $u \rightarrow v$.

## Output

On the first line print $k$, the number of strongly connected components.

On the second line print $n$ integers: the cluster id of servers $1, 2, \ldots, n$.

## Sample 1

Input:

```
3 3
1 2
2 1
2 3
```

Output:

```
2
1 1 2
```

## Run

From the repository root, after writing `scc.student.cpp`:

```sh
./scripts/check.sh src/graphs/scc
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/scc --solution
```
