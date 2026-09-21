# All-Pairs Shortest Paths

**Technique:** Floyd-Warshall all-pairs shortest paths

Time limit: 1 s
Memory limit: 256 MB

## Problem

A directed graph has $n$ vertices labeled $1, 2, \ldots, n$ and $m$ weighted edges. There are no negative cycles. For every pair of vertices, compute the shortest-path distance, or decide that no path exists.

Floyd-Warshall fills an $n \times n$ matrix with the triple loop through every intermediate vertex. Do not run a separate single-source search from each vertex.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 80$, $0 \le m \le n^2$).

Each of the next $m$ lines contains three integers $u$, $v$, and $w$ ($1 \le u, v \le n$, $|w| \le 1000$). If several edges share the same pair, keep the cheapest.

## Output

Print $n$ lines of $n$ integers: the distance from $i$ to $j$ in row $i$, column $j$ (1-based vertices). Print `-1` if $j$ is unreachable from $i$. The distance from a vertex to itself is $0$.

## Sample 1

Input:

```
3 3
1 2 3
2 3 2
3 1 4
```

Output:

```
0 3 5
6 0 2
4 7 0
```

## Run

From the repository root, after writing `floyd_warshall.student.cpp`:

```sh
./scripts/check.sh src/graphs/floyd_warshall
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/floyd_warshall --solution
```
