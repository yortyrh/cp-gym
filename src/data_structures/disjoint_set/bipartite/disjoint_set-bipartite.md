# Online Bipartiteness

**Technique:** DSU with parity (bipartite union-find)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You start with $n$ vertices and no edges. Edges are added one by one. After every addition, print `YES` if the undirected graph is still bipartite, otherwise print `NO`.

Once an odd cycle exists, the graph stays non-bipartite.

Maintain a DSU that stores, for each vertex, the XOR-parity of the path to its component root. An edge $u{-}v$ should put $u$ and $v$ in opposite colors. If they already share a component and already have the same parity, the new edge closes an odd cycle.

Do not recolor the graph with BFS or DFS after every edge.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n, m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$), an undirected edge. A self-loop is an odd cycle.

## Output

Print $m$ lines. After the $i$-th edge, print `YES` if the graph is bipartite, otherwise `NO`.

## Sample 1

Input:

```
4 5
1 2
2 3
3 4
4 1
1 3
```

Output:

```
YES
YES
YES
YES
NO
```

## Run

From the repository root, after writing `disjoint_set-bipartite.student.cpp`:

```sh
./scripts/check.sh src/data_structures/disjoint_set/bipartite
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/disjoint_set/bipartite --solution
```
