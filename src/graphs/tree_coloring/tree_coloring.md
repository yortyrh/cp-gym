# Proper Tree Colorings

**Technique:** tree DP for proper $k$-colorings

Time limit: 1 s
Memory limit: 256 MB

## Problem

A tree has $n$ vertices labeled $1, 2, \ldots, n$. Count the ways to assign each vertex one of $k$ colors so that every pair of adjacent vertices receives different colors.

Root the tree at vertex $1$. The root has $k$ choices; every other vertex has $k-1$ choices (it must differ from its parent). DFS and multiply. $n$ and $k$ are small; do not enumerate assignments.

## Input

The first line contains two integers $n$ and $k$ ($1 \le n \le 12$, $1 \le k \le 8$).

Each of the next $n-1$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$), an edge of the tree.

## Output

Print one integer: the number of proper $k$-colorings.

## Sample 1

Input:

```
3 2
1 2
2 3
```

Output:

```
2
```

## Run

From the repository root, after writing `tree_coloring.student.cpp`:

```sh
./scripts/check.sh src/graphs/tree_coloring
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/tree_coloring --solution
```
