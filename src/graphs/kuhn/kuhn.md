# Bipartite Matching

**Technique:** Kuhn bipartite matching (DFS augmenting paths)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A bipartite graph has $n$ left vertices labeled $1, 2, \ldots, n$ and $m$ right vertices labeled $1, 2, \ldots, m$. There are $e$ undirected edges, each joining one left vertex to one right vertex.

A matching is a set of edges that share no vertex. Compute the size of a maximum matching.

Kuhn's algorithm searches for augmenting paths with DFS from unmatched left vertices. Do not reduce the graph to a flow network.

## Input

The first line contains three integers $n$, $m$, and $e$ ($1 \le n, m \le 80$, $0 \le e \le n \cdot m$).

Each of the next $e$ lines contains two integers $u$ and $v$ ($1 \le u \le n$, $1 \le v \le m$), an edge from left vertex $u$ to right vertex $v$. Duplicate edges may appear.

## Output

Print one integer: the size of a maximum matching.

## Sample 1

Input:

```
3 3 5
1 1
1 2
2 2
3 2
3 3
```

Output:

```
3
```

## Run

From the repository root, after writing `kuhn.student.cpp`:

```sh
./scripts/check.sh src/graphs/kuhn
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/kuhn --solution
```
