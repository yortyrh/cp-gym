# Lowest Common Ancestor

**Technique:** binary lifting LCA

Time limit: 1 s
Memory limit: 256 MB

## Problem

A tree has $n$ vertices labeled $1, 2, \ldots, n$, rooted at $1$. Answer $q$ queries: for vertices $u$ and $v$, print their lowest common ancestor.

After a DFS, store `up[v][k]`, the $2^k$-th ancestor of $v$. Lift the deeper vertex to the same depth, then lift both together. Do not walk to the root with parent pointers on every query.

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

From the repository root, after writing `lca.student.cpp`:

```sh
./scripts/check.sh src/graphs/lca
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/lca --solution
```
