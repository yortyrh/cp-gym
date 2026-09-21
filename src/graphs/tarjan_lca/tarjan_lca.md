# Offline Lowest Common Ancestor

**Technique:** Tarjan offline LCA

Time limit: 1 s
Memory limit: 256 MB

## Problem

A tree has $n$ vertices labeled $1, 2, \ldots, n$, rooted at $1$. All $q$ queries are known in advance: for each pair $u, v$ print their lowest common ancestor.

Tarjan's offline algorithm DFS-es the tree once and uses a disjoint-set union. After both endpoints of a query are visited, the DSU ancestor of the earlier vertex is the LCA. Keep the DSU inline in your program (find with path compression, unite by size). Do not lift ancestors online.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n \le 200$, $1 \le q \le 200$).

Each of the next $n-1$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$), an edge of the tree.

Each of the next $q$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$).

## Output

For each query, print the 1-based lowest common ancestor on its own line.

## Sample 1

Input:

```
5 3
1 2
1 3
2 4
2 5
4 5
4 3
5 5
```

Output:

```
2
1
5
```

## Run

From the repository root, after writing `tarjan_lca.student.cpp`:

```sh
./scripts/check.sh src/graphs/tarjan_lca
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/tarjan_lca --solution
```
