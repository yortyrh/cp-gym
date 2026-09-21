# Tree Distance Sums

**Technique:** rerooting DP for tree distance sums

Time limit: 1 s
Memory limit: 256 MB

## Problem

A tree has $n$ vertices labeled $1, 2, \ldots, n$. For every vertex $v$, compute the sum of distances from $v$ to all $n$ vertices (the distance from $v$ to itself is $0$).

Reroot: a downward DFS stores subtree sizes and downward distance sums; an upward DFS lifts the answer to every child in $O(1)$. Do not start a new search from each vertex.

## Input

The first line contains one integer $n$ ($1 \le n \le 200$).

Each of the next $n-1$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$), an edge of the tree.

## Output

Print $n$ integers: the distance sum for vertices $1, 2, \ldots, n$.

## Sample 1

Input:

```
3
1 2
2 3
```

Output:

```
3 2 3
```

## Run

From the repository root, after writing `tree_distance.student.cpp`:

```sh
./scripts/check.sh src/graphs/tree_distance
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/tree_distance --solution
```
