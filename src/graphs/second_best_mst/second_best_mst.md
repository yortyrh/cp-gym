# Backup Spanning Cables

**Technique:** second-best MST (swap a non-tree edge)

Time limit: 1 s
Memory limit: 256 MB

## Problem

There are $n$ junctions and $m$ undirected candidate cables. First build a minimum spanning tree. Then find a spanning tree whose total cost is strictly larger than that MST, and as small as possible among those stricter trees.

One way: build the MST (Kruskal with an inline DSU), then try replacing one tree edge by a non-tree cable. For each unused cable $u-v$, drop the heaviest MST edge on the unique tree path $u \ldots v$ and add the cable. Keep the cheapest replacement that strictly increases the total.

If no strictly heavier spanning tree exists, print `-1`. Junctions are numbered $1 \ldots n$.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains three integers $u$, $v$, and $w$ ($1 \le u, v \le n$, $|w| \le 10^9$).

## Output

Print one integer: the total weight of a second-best spanning tree, or `-1` if none exists.

## Sample 1

Input:

```
4 5
1 2 1
2 3 1
3 4 1
1 3 2
1 4 10
```

Output:

```
4
```

## Run

From the repository root, after writing `second_best_mst.student.cpp`:

```sh
./scripts/check.sh src/graphs/second_best_mst
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/second_best_mst --solution
```
