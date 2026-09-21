# Fibre from the Capital

**Technique:** Prim MST (binary heap)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A fibre company will connect $n$ stations. There are $m$ undirected candidate links, each with a cost. The network must grow from station $1$: repeatedly add the cheapest link that leaves the set of already connected stations.

This is Prim's algorithm with a min-heap of candidate links. Duplicate heap entries that point into the connected set are skipped.

If station $1$ cannot reach every other station, print `-1`. Stations are numbered $1 \ldots n$. For $n = 1$ the cost is $0$.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains three integers $u$, $v$, and $w$ ($1 \le u, v \le n$, $|w| \le 10^9$).

## Output

Print one integer: the total cost of the spanning tree grown from station $1$, or `-1` if it is impossible.

## Sample 1

Input:

```
4 5
1 2 10
1 3 6
1 4 5
2 4 15
3 4 4
```

Output:

```
19
```

## Run

From the repository root, after writing `prim.student.cpp`:

```sh
./scripts/check.sh src/graphs/prim
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/prim --solution
```
