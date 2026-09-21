# Centroid Decomposition

**Technique:** centroid decomposition

Time limit: 1 s
Memory limit: 256 MB

## Problem

A tree has $n$ vertices labeled $1, 2, \ldots, n$. Build its centroid decomposition: a centroid is a vertex whose removal leaves components of size at most $n/2$. Recurse on each remaining component.

Print the parent of every vertex in the centroid tree. The top centroid has parent $0$. $n$ is small; compute subtree sizes and walk to the centroid rather than guessing.

## Input

The first line contains one integer $n$ ($1 \le n \le 200$).

Each of the next $n-1$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$), an edge of the tree.

## Output

Print $n$ integers: the centroid-tree parent of vertices $1, 2, \ldots, n$, using $0$ for the root centroid.

## Sample 1

Input:

```
5
1 2
1 3
2 4
2 5
```

Output:

```
2 0 1 2 2
```

## Run

From the repository root, after writing `centroid.student.cpp`:

```sh
./scripts/check.sh src/graphs/centroid
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/centroid --solution
```
