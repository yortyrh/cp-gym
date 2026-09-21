# Walks of Fixed Length

**Technique:** walks of length $k$ by matrix exponentiation

Time limit: 1 s
Memory limit: 256 MB

## Problem

A directed graph on $n$ vertices is given as an $n \times n$ adjacency matrix $A$ of non-negative integers (entry $A_{i,j}$ is the number of edges from $i$ to $j$). Count the walks of length $k$ between every pair of vertices.

The matrix $A^k$ stores those counts. Raise $A$ to the $k$-th power by binary exponentiation. $n$ is small; do not enumerate walks one by one.

## Input

The first line contains two integers $n$ and $k$ ($1 \le n \le 20$, $0 \le k \le 10$).

Each of the next $n$ lines contains $n$ integers $A_{i,j}$ ($0 \le A_{i,j} \le 5$).

## Output

Print $n$ lines of $n$ integers: the number of walks of length $k$ from $i$ to $j$.

## Sample 1

Input:

```
3 3
0 1 0
0 0 1
1 0 0
```

Output:

```
1 0 0
0 1 0
0 0 1
```

## Run

From the repository root, after writing `walks.student.cpp`:

```sh
./scripts/check.sh src/graphs/walks
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/walks --solution
```
