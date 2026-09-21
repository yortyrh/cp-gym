# Courier Times

**Technique:** Dijkstra (non-negative binary heap)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A city has $n$ depots and $m$ one-way courier roads. Road $i$ goes from $u_i$ to $v_i$ and takes $w_i$ minutes, with $w_i \ge 0$. Compute the fastest travel time from depot $s$ to every depot.

Use Dijkstra with a min-heap: pop the closest unsettled vertex and relax its outgoing roads. Duplicate heap entries are skipped when their stored distance is stale.

Unreachable depots should be reported as `INF`. Depots are numbered $1 \ldots n$.

## Input

The first line contains three integers $n$, $m$, and $s$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$, $1 \le s \le n$).

Each of the next $m$ lines contains three integers $u$, $v$, and $w$ ($1 \le u, v \le n$, $0 \le w \le 10^9$).

## Output

Print $n$ tokens on one line: the shortest time from $s$ to depots $1, 2, \ldots, n$. Print `INF` for a depot that cannot be reached.

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

From the repository root, after writing `dijkstra.student.cpp`:

```sh
./scripts/check.sh src/graphs/dijkstra
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/dijkstra --solution
```
