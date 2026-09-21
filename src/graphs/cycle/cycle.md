# Feedback Loop

**Technique:** directed cycle detection (three-color DFS)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A project tracker stores $n$ tasks and $m$ directed "must-follow" links. Decide whether the directed graph contains a cycle (a feedback loop).

Use three-color DFS: white (unseen), gray (on the current path), black (finished). A back edge to a gray vertex proves a directed cycle. Scanning neighbours of a finished vertex is not a cycle. Recurse from every unvisited vertex so disconnected pieces are checked.

Do not convert the graph to undirected form. Vertices are 1-based in the input. Convert to 0-based at I/O if your arrays are 0-based.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$, $u \neq v$), a directed link $u \rightarrow v$.

## Output

Print `YES` if a directed cycle exists, otherwise print `NO`.

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
```

## Run

From the repository root, after writing `cycle.student.cpp`:

```sh
./scripts/check.sh src/graphs/cycle
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/cycle --solution
```
