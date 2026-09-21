# Maximum Flow (Edmonds-Karp)

**Technique:** Edmonds-Karp maximum flow

Time limit: 1 s
Memory limit: 256 MB

## Problem

A directed network has $n$ vertices labeled $1, 2, \ldots, n$ and $m$ capacity edges. Compute the maximum flow from source $s$ to sink $t$.

Edmonds-Karp is Ford-Fulkerson with BFS: every augmentation uses a shortest residual path. The instance is small enough that this $O(V E^2)$ method finishes. Do not search for augmenting paths with DFS.

## Input

The first line contains four integers $n$, $m$, $s$, and $t$ ($2 \le n \le 50$, $0 \le m \le 200$, $1 \le s, t \le n$).

Each of the next $m$ lines contains three integers $u$, $v$, and $c$ ($1 \le u, v \le n$, $0 \le c \le 1000$).

## Output

Print one integer: the maximum $s$-$t$ flow.

## Sample 1

Input:

```
4 5 1 4
1 2 3
1 3 2
2 3 1
2 4 2
3 4 3
```

Output:

```
5
```

## Run

From the repository root, after writing `edmonds_karp.student.cpp`:

```sh
./scripts/check.sh src/graphs/edmonds_karp
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/edmonds_karp --solution
```
