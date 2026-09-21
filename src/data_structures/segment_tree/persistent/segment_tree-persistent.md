# Versioned Point Assign, Range Sum

**Technique:** persistent segment tree (point assign, range sum)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. Version $0$ is the initial array. There are two kinds of queries:

- `1 k i v` — create a new version by copying version $k$ and setting $a_i$ equal to $v$
- `2 k l r` — print the sum $a_l + \cdots + a_r$ on version $k$

Indices are 1-based and ranges are inclusive. Versions are numbered $0, 1, 2, \ldots$ in the order they are created. Each type-1 query appends the next unused version id (at most $q$ new versions, so ids lie in $0..q$). Every $k$ in the input refers to a version that already exists.

A persistent segment tree copies only the $O(\log n)$ nodes on the update path, so each query is $O(\log n)$ time.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains one query. For type 1, $k$ is an existing version, $1 \le i \le n$, and $|v| \le 10^9$. For type 2, $k$ is an existing version and $1 \le l \le r \le n$.

## Output

For every query of type 2, print the range sum on its own line.

## Sample 1

Input:

```
5 6
1 2 3 4 5
2 0 1 5
1 0 3 10
2 1 1 5
1 1 1 100
2 0 1 3
2 2 1 2
```

Output:

```
15
22
6
102
```

## Run

From the repository root, after writing `segment_tree-persistent.student.cpp`:

```sh
./scripts/check.sh src/data_structures/segment_tree/persistent
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/segment_tree/persistent --solution
```
