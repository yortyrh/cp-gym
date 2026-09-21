# Token Corridors

**Technique:** 0-1 BFS (deque shortest paths)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A vault has $n$ rooms and $m$ one-way corridors. Each corridor costs either $0$ tokens (unlocked) or $1$ token (a gated door). Starting from room $s$, compute the fewest tokens needed to reach every room.

0-1 BFS uses a deque: after relaxing a corridor of weight $0$, push the neighbour to the front; after weight $1$, push to the back. This is Dijkstra on a $0/1$ metric in linear time.

Unreachable rooms should be reported as `INF`. Rooms are numbered $1 \ldots n$.

## Input

The first line contains three integers $n$, $m$, and $s$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$, $1 \le s \le n$).

Each of the next $m$ lines contains three integers $u$, $v$, and $w$ ($1 \le u, v \le n$, $w \in \{0, 1\}$).

## Output

Print $n$ tokens on one line: the shortest token cost from $s$ to rooms $1, 2, \ldots, n$. Print `INF` for a room that cannot be reached.

## Sample 1

Input:

```
4 4 1
1 2 0
1 3 1
2 4 1
3 4 0
```

Output:

```
0 0 1 1
```

## Run

From the repository root, after writing `zero_one_bfs.student.cpp`:

```sh
./scripts/check.sh src/graphs/zero_one_bfs
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/zero_one_bfs --solution
```
