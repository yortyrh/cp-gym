# One-Way Conversion

**Technique:** strong orientation of a bridgeless undirected graph

Time limit: 1 s
Memory limit: 256 MB

## Problem

A city has $n$ plazas and $m$ two-way streets. You want to make every street one-way. If the undirected graph has a bridge, some plaza would become unreachable after the conversion — print `NO`.

Otherwise print `YES` and one orientation of every street. Direct each DFS tree edge away from the parent, and each back edge toward the ancestor (the endpoint discovered earlier). That makes every 2-edge-connected piece strongly connected.

First search for bridges with discovery times and low-link values. If any bridge exists, stop. Otherwise run a second DFS that records the directed pairs in the order they are assigned. Start DFS at the smallest unvisited vertex. Skip the parent on undirected adjacency lists.

Vertices are 1-based in the input and output. Convert to 0-based at I/O if your arrays are 0-based.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$, $u \neq v$), a two-way street. The graph may be disconnected. There are no self-loops.

## Output

If a bridge exists, print `NO`.

Otherwise print `YES` on the first line, then $m$ lines $u$ $v$ meaning a one-way street from $u$ to $v$, in the order the orientation DFS assigns them.

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
1 2
2 3
3 1
```

## Run

From the repository root, after writing `strong_orientation.student.cpp`:

```sh
./scripts/check.sh src/graphs/strong_orientation
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/strong_orientation --solution
```
