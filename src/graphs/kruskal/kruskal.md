# Cheapest Cables

**Technique:** Kruskal MST (sort edges, union-find)

Time limit: 1 s
Memory limit: 256 MB

## Problem

There are $n$ towns and $m$ candidate undirected cables. Cable $i$ joins towns $u_i$ and $v_i$ and costs $w_i$. Build a network that connects every town, using a subset of cables of minimum total cost.

Kruskal sorts cables by cost and adds a cable when its endpoints lie in different components. Maintain components with an inline disjoint-set union (union by size, path compression). Do not include a deleted DSU header.

If the towns cannot be connected, the answer is `-1`. Towns are numbered $1 \ldots n$. For $n = 1$ the cost is $0$.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains three integers $u$, $v$, and $w$ ($1 \le u, v \le n$, $|w| \le 10^9$).

## Output

Print one integer: the minimum total cable cost, or `-1` if no spanning tree exists.

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

From the repository root, after writing `kruskal.student.cpp`:

```sh
./scripts/check.sh src/graphs/kruskal
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/kruskal --solution
```
