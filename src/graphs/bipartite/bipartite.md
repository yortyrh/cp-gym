# Two Clubs

**Technique:** bipartite check by 2-coloring (BFS)

Time limit: 1 s
Memory limit: 256 MB

## Problem

$n$ students form an undirected acquaintance graph with $m$ edges. You must split them into two clubs so that every acquaintance pair sits in different clubs.

If a split exists, print `YES` and a coloring of the students with labels $1$ and $2$. If any connected component has an odd cycle, print `NO`.

Color with BFS (or DFS): start each uncolored component with color $1$, and give every neighbour the opposite color. A conflict means the graph is not bipartite. Isolated students receive color $1$. Do not use maximum matching.

Vertices are 1-based in the input. Convert to 0-based at I/O if your arrays are 0-based. Print colors $1$ and $2$ (not $0$ and $1$).

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$, $u \neq v$), an undirected acquaintance. The graph may be disconnected.

## Output

If the graph is bipartite, print `YES` on the first line and $n$ colors ($1$ or $2$) on the second line — the club of students $1, 2, \ldots, n$.

Otherwise print `NO`.

## Sample 1

Input:

```
5 3
1 2
1 3
2 4
```

Output:

```
YES
1 2 2 1 1
```

## Run

From the repository root, after writing `bipartite.student.cpp`:

```sh
./scripts/check.sh src/graphs/bipartite
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/bipartite --solution
```
