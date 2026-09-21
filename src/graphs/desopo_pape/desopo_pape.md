# Sparse Couriers

**Technique:** D'Esopo-Pape (deque SPFA)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A courier graph has $n$ hubs and $m$ one-way legs. Leg weights may be negative, but there is no negative cycle. Compute the cheapest route from hub $s$ to every hub.

D'Esopo-Pape is a deque variant of SPFA. Each vertex has a state: never seen, currently in the deque, or already processed. A newly discovered vertex is pushed to the back; a vertex that is processed again after an improvement is pushed to the front.

The algorithm is fast on typical sparse graphs and is not required to match Dijkstra's heap. Unreachable hubs should be reported as `INF`. Hubs are numbered $1 \ldots n$.

## Input

The first line contains three integers $n$, $m$, and $s$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$, $1 \le s \le n$).

Each of the next $m$ lines contains three integers $u$, $v$, and $w$ ($1 \le u, v \le n$, $|w| \le 10^9$).

It is guaranteed that no negative cycle is reachable from $s$.

## Output

Print $n$ tokens on one line: the shortest cost from $s$ to hubs $1, 2, \ldots, n$. Print `INF` for a hub that cannot be reached.

## Sample 1

Input:

```
4 5 1
1 2 4
1 3 1
2 4 1
3 2 2
3 4 5
```

Output:

```
0 3 1 4
```

## Run

From the repository root, after writing `desopo_pape.student.cpp`:

```sh
./scripts/check.sh src/graphs/desopo_pape
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/desopo_pape --solution
```
