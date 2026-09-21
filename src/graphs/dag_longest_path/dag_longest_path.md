# Longest Pipeline

**Technique:** longest path in a DAG (topological DP)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A factory has $n$ stations and $m$ directed conveyor belts. The graph is a DAG. A pipeline is a directed path, and its length is the number of belts it uses. Find the longest pipeline.

Let `dp[v]` be the maximum number of edges on a path ending at $v$. After a topological order, each edge $u \rightarrow v$ updates `dp[v]` with `dp[u] + 1`. The answer is the maximum `dp` value.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$), a directed edge $u \rightarrow v$. The graph has no cycles.

## Output

Print one integer: the maximum number of edges on any path.

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
3
```

## Run

From the repository root, after writing `dag_longest_path.student.cpp`:

```sh
./scripts/check.sh src/graphs/dag_longest_path
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/dag_longest_path --solution
```
