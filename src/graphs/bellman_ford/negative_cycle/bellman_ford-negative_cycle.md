# Bonus Loop

**Technique:** Bellman-Ford (negative-cycle reconstruction)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A directed network of $n$ billing nodes and $m$ one-way transfers is rooted at node $s$. A transfer $u \rightarrow v$ with weight $w$ may be negative. Decide whether a negative cycle is reachable from $s$.

Run Bellman-Ford from $s$ and keep a parent for every successful relaxation. After $n$ passes, if some distance still improves, walk $n$ parent steps to enter a cycle, then list that cycle.

If several listings of the same directed cycle are possible, rotate it so the printed sequence starts (and ends) at the smallest vertex id. Do not reverse a directed cycle.

## Input

The first line contains three integers $n$, $m$, and $s$ ($1 \le n \le 2500$, $0 \le m \le 5000$, $1 \le s \le n$).

Each of the next $m$ lines contains three integers $u$, $v$, and $w$ ($1 \le u, v \le n$, $|w| \le 10^9$).

## Output

If no negative cycle is reachable from $s$, print `NO`.

Otherwise print `YES` on the first line. On the second line print the vertices of one simple negative cycle reachable from $s$, starting and ending at the same vertex, rotated to begin at the smallest id on that cycle.

## Sample 1

Input:

```
3 3 1
1 2 1
2 3 1
3 1 -3
```

Output:

```
YES
1 2 3 1
```

## Run

From the repository root, after writing `bellman_ford-negative_cycle.student.cpp`:

```sh
./scripts/check.sh src/graphs/bellman_ford/negative_cycle
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/bellman_ford/negative_cycle --solution
```
