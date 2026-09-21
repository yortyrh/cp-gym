# Path Sums on a Tree

**Technique:** heavy-light decomposition path sums

Time limit: 1 s
Memory limit: 256 MB

## Problem

A tree has $n$ vertices labeled $1, 2, \ldots, n$, rooted at $1$. Vertex $v$ stores an integer value $a_v$. Process $q$ operations:

- `1 v x` — set $a_v$ equal to $x$
- `2 u v` — print the sum of values on the unique path between $u$ and $v$ (inclusive)

Heavy-light decomposition splits every path into $O(\log n)$ contiguous chains. $n$ is small, so you may scan a chain with a loop; do not walk parent pointers from scratch on every query.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 200$).

The second line contains $n$ integers $a_1, \ldots, a_n$ ($|a_i| \le 1000$).

Each of the next $n-1$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$), an edge of the tree.

Each of the next $q$ lines contains a query as described above ($1 \le v, u \le n$, $|x| \le 1000$).

## Output

For every query of type 2, print the path sum on its own line.

## Sample 1

Input:

```
5 2
1 2 0 0 4
1 2
1 3
2 4
2 5
2 5 1
2 4 3
```

Output:

```
7
3
```

## Run

From the repository root, after writing `hld.student.cpp`:

```sh
./scripts/check.sh src/graphs/hld
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/hld --solution
```
