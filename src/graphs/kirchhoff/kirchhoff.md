# Distinct Tree Wirings

**Technique:** Kirchhoff matrix-tree theorem

Time limit: 1 s
Memory limit: 256 MB

## Problem

An undirected graph has $n$ labeled sockets and $m$ wires (parallel wires are allowed; self-loops are ignored). Count the distinct spanning trees on those sockets.

By the matrix-tree theorem the count equals any cofactor of the Laplacian $L$, where $L_{ii}$ is the degree of socket $i$ and $L_{ij} = -1$ for each wire between $i$ and $j$ (and $0$ on the rest of the off-diagonal). Build $L$, drop the first row and first column, and take the determinant of that minor (Gaussian elimination). The count is a non-negative integer.

Sockets are numbered $1 \ldots n$. If $n = 1$ the answer is $1$. If the graph is disconnected the answer is $0$.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 20$, $0 \le m \le 200$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$).

The number of spanning trees fits in a signed 64-bit integer.

## Output

Print one integer: the number of spanning trees.

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
3
```

## Run

From the repository root, after writing `kirchhoff.student.cpp`:

```sh
./scripts/check.sh src/graphs/kirchhoff
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/kirchhoff --solution
```
