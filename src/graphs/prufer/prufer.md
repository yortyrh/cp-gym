# Leaf-Deletion Code

**Technique:** Prüfer code of a labeled tree

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a tree on $n$ labeled vertices. Encode it as a Prüfer sequence of length $n-2$: $n-2$ times, delete the current leaf with the smallest label and append the label of its unique remaining neighbour.

Vertices are numbered $1 \ldots n$. The input is a connected tree.

## Input

The first line contains one integer $n$ ($2 \le n \le 2000$).

Each of the next $n-1$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$), an undirected tree edge.

## Output

Print $n-2$ integers: the Prüfer code. If $n = 2$ print an empty line.

## Sample 1

Input:

```
4
1 2
2 3
3 4
```

Output:

```
2 3
```

## Run

From the repository root, after writing `prufer.student.cpp`:

```sh
./scripts/check.sh src/graphs/prufer
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/prufer --solution
```
