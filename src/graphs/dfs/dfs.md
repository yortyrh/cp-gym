# Cave Walk Order

**Technique:** depth-first search from a source

Time limit: 1 s
Memory limit: 256 MB

## Problem

A cave system has $n$ chambers and $m$ two-way tunnels. You start in chamber $1$ and explore with depth-first search: mark a chamber when you first enter it, then recurse into unused tunnels in the order they appear in the adjacency list.

Print the sequence of chambers in the order they are first visited. Chambers that cannot be reached from $1$ must not appear.

Build the adjacency list by appending both directions of each input tunnel as it is read, then recurse from chamber $1$. Do not use BFS.

Vertices are 1-based in the input and output. Convert to 0-based at I/O if your arrays are 0-based.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$, $u \neq v$), a two-way tunnel. The graph may be disconnected.

## Output

Print the DFS discovery order of chambers reachable from $1$, as 1-based indices separated by spaces.

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
1 2 4 3
```

## Run

From the repository root, after writing `dfs.student.cpp`:

```sh
./scripts/check.sh src/graphs/dfs
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/dfs --solution
```
