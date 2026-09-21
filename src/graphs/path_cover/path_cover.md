# Delivery Routes

**Technique:** minimum path cover in a DAG (bipartite matching)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A DAG has $n$ tasks and $m$ precedence edges. A courier can complete a directed path of tasks. Each task must be completed by exactly one courier (vertex-disjoint paths). Find the fewest couriers needed.

Split every vertex into an out-copy (left) and an in-copy (right). Each DAG edge $u \rightarrow v$ becomes a bipartite edge from left-$u$ to right-$v$. A matching edge means two tasks share a courier. The minimum path cover size is $n$ minus the size of a maximum matching.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 200$, $0 \le m \le 1000$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$), a directed edge $u \rightarrow v$. The graph is a DAG.

## Output

Print one integer: the minimum number of vertex-disjoint paths that cover every vertex.

## Sample 1

Input:

```
4 3
1 2
2 4
3 4
```

Output:

```
2
```

## Run

From the repository root, after writing `path_cover.student.cpp`:

```sh
./scripts/check.sh src/graphs/path_cover
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/path_cover --solution
```
