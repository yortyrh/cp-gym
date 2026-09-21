# Critical Junctions

**Technique:** Tarjan articulation points (discovery time / low-link DFS)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A town has $n$ junctions and $m$ two-way roads. A junction is critical if removing it (together with its incident roads) increases the number of connected pieces of the remaining graph.

Find every critical junction.

Run a DFS that records discovery times `tin[v]` and low-link values `low[v]`. For a non-root vertex $u$, if some child $v$ satisfies `low[v] >= tin[u]`, then $u$ is an articulation point. The DFS root is an articulation point if and only if it has at least two children in the DFS tree. Skip the parent when scanning undirected adjacency lists.

Vertices are 1-based in the input and output. Convert to 0-based at I/O if your arrays are 0-based.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$, $u \neq v$), a two-way road. The graph may be disconnected. There are no self-loops.

## Output

On the first line print $k$, the number of articulation points.

If $k > 0$, print one more line with the $k$ junctions in increasing order, 1-based.

## Sample 1

Input:

```
4 4
1 2
2 3
2 4
3 4
```

Output:

```
1
2
```

## Run

From the repository root, after writing `bridges-cut_points.student.cpp`:

```sh
./scripts/check.sh src/graphs/bridges/cut_points
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/bridges/cut_points --solution
```
