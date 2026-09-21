# District Labels

**Technique:** connected components by DFS

Time limit: 1 s
Memory limit: 256 MB

## Problem

A region has $n$ towns and $m$ two-way roads. Towns that can reach each other by roads belong to the same district. Isolated towns are districts of size one.

Count the districts and assign each town a district id. Scan towns $1, 2, \ldots, n$ in that order. Each time you find an unvisited town, start a new district (ids $1, 2, \ldots$) and DFS/BFS through all towns reachable from it.

Do not use disjoint-set union for this exercise. Vertices are 1-based in the input. Convert to 0-based at I/O if your arrays are 0-based.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$, $u \neq v$), a two-way road. The graph may be disconnected.

## Output

On the first line print $k$, the number of districts.

On the second line print $n$ integers: the district id of towns $1, 2, \ldots, n$.

## Sample 1

Input:

```
5 3
1 2
1 3
2 4
```

Output:

```
2
1 1 1 1 2
```

## Run

From the repository root, after writing `connected_components.student.cpp`:

```sh
./scripts/check.sh src/graphs/connected_components
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/connected_components --solution
```
