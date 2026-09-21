# Directed Eulerian Path

**Technique:** Hierholzer Eulerian path in a directed graph

Time limit: 1 s
Memory limit: 256 MB

## Problem

A directed graph has $n$ vertices labeled $1, 2, \ldots, n$ and $m$ edges. An Eulerian path visits every edge exactly once. Decide whether such a path exists and print one if it does.

Hierholzer walks unused outgoing edges with a stack and records a vertex after all of its edges are used. Degree conditions: all vertices balanced, or exactly one start with one extra outgoing edge and one end with one extra incoming edge.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 80$, $0 \le m \le 200$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$).

## Output

If no Eulerian path exists, print `NO`.

Otherwise print `YES` on the first line and $m+1$ vertices of a path on the second line. If $m = 0$, print the single vertex $1$.

## Sample 1

Input:

```
3 3
1 2
2 3
3 1
```

Output:

```
YES
1 2 3 1
```

## Run

From the repository root, after writing `euler_path.student.cpp`:

```sh
./scripts/check.sh src/graphs/euler_path
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/euler_path --solution
```
