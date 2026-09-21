# Job Queue Order

**Technique:** Kahn topological sort (lexicographically smallest)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You have $n$ jobs and $m$ precedence constraints. A constraint $u \rightarrow v$ means job $u$ must finish before job $v$ starts. The precedence graph is directed.

Print the lexicographically smallest order of all $n$ jobs that respects every constraint. If some directed cycle makes that impossible, print `-1`.

Use Kahn's algorithm: keep a min-heap (priority queue) of jobs whose remaining indegree is $0$, repeatedly pop the smallest index, and reduce indegrees of its successors. If fewer than $n$ jobs are emitted, a cycle exists.

Vertices are 1-based in the input and output. Convert to 0-based at I/O if your arrays are 0-based.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$, $u \neq v$), a directed constraint $u \rightarrow v$.

## Output

If a valid order exists, print $n$ job indices in the lexicographically smallest topological order.

Otherwise print `-1`.

## Sample 1

Input:

```
5 5
1 2
1 3
2 4
3 4
4 5
```

Output:

```
1 2 3 4 5
```

## Run

From the repository root, after writing `topological_sort.student.cpp`:

```sh
./scripts/check.sh src/graphs/topological_sort
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/topological_sort --solution
```
