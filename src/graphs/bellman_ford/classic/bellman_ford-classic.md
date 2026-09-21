# Delayed Relays

**Technique:** Bellman-Ford (single-source shortest paths)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A directed communication network has $n$ relays and $m$ one-way links. Link $i$ goes from $u_i$ to $v_i$ and has delay $w_i$, which may be negative (a scheduled time bonus). There is no negative cycle. Compute the smallest total delay from relay $s$ to every relay.

Bellman-Ford relaxes every link $n-1$ times on an edge list, so negative weights are allowed. Dijkstra is not required to be correct here.

Unreachable relays should be reported as `INF`. Relays are numbered $1 \ldots n$.

## Input

The first line contains three integers $n$, $m$, and $s$ ($1 \le n \le 2500$, $0 \le m \le 5000$, $1 \le s \le n$).

Each of the next $m$ lines contains three integers $u$, $v$, and $w$ ($1 \le u, v \le n$, $|w| \le 10^9$).

It is guaranteed that no negative cycle is reachable from $s$.

## Output

Print $n$ tokens on one line: the shortest delay from $s$ to relays $1, 2, \ldots, n$. Print `INF` for a relay that cannot be reached.

## Sample 1

Input:

```
3 3 1
1 2 4
1 3 5
2 3 -2
```

Output:

```
0 4 2
```

## Run

From the repository root, after writing `bellman_ford-classic.student.cpp`:

```sh
./scripts/check.sh src/graphs/bellman_ford/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/bellman_ford/classic --solution
```
