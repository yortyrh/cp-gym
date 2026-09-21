# Global Minimum Cut

**Technique:** Stoer-Wagner global minimum cut

Time limit: 1 s
Memory limit: 256 MB

## Problem

An undirected weighted graph on $n$ vertices is given as a symmetric $n \times n$ matrix $w$. The diagonal is zero. The global minimum cut is the smallest total weight of a set of edges whose removal splits the vertices into two non-empty parts.

Stoer-Wagner runs $n-1$ maximum-adjacency phases and contracts the last two vertices of each phase. $n$ is small; the cubic algorithm is intended.

## Input

The first line contains one integer $n$ ($2 \le n \le 30$).

Each of the next $n$ lines contains $n$ integers $w_{i,j}$ ($0 \le w_{i,j} \le 1000$, $w_{i,i} = 0$, $w_{i,j} = w_{j,i}$).

## Output

Print one integer: the weight of a global minimum cut.

## Sample 1

Input:

```
3
0 3 0
3 0 4
0 4 0
```

Output:

```
3
```

## Run

From the repository root, after writing `stoer_wagner.student.cpp`:

```sh
./scripts/check.sh src/graphs/stoer_wagner
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/stoer_wagner --solution
```
