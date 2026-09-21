# Courier Hops

**Technique:** breadth-first search distances on an unweighted graph

Time limit: 1 s
Memory limit: 256 MB

## Problem

A courier network has $n$ depots and $m$ one-way routes of equal length. From depot $1$, compute the fewest routes needed to reach every depot.

Unreachable depots should be reported as `-1`. Because every route has the same length, BFS from depot $1$ yields shortest distances: a queue expands vertices by increasing hop count, and each vertex is enqueued at most once.

Do not use Dijkstra or DFS for the distances. Vertices are 1-based in the input. Convert to 0-based at I/O if your arrays are 0-based.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$, $u \neq v$), a directed route from $u$ to $v$.

## Output

Print $n$ integers: the distance from depot $1$ to depots $1, 2, \ldots, n$, or `-1` if that depot is unreachable. Depot $1$ has distance $0$.

## Sample 1

Input:

```
6 5
1 2
1 3
2 4
3 4
4 5
```

Output:

```
0 1 1 2 3 -1
```

## Run

From the repository root, after writing `bfs.student.cpp`:

```sh
./scripts/check.sh src/graphs/bfs
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/bfs --solution
```
