# Point Assign, Rectangle Sum

**Technique:** 2D segment tree (point assign, rectangle sum)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an $n \times m$ matrix of integers and $q$ queries. There are two kinds of queries:

- `1 x y v` — set $a_{x,y}$ equal to $v$
- `2 x1 y1 x2 y2` — print the sum of the inclusive subrectangle with corners $(x_1, y_1)$ and $(x_2, y_2)$

All indices are 1-based.

A 2D segment tree (a segment tree of segment trees) processes each point assign and each rectangle sum in $O(\log n \log m)$ time.

## Input

The first line contains three integers $n$, $m$, and $q$ ($1 \le n, m \le 200$, $1 \le q \le 10^4$).

Each of the next $n$ lines contains $m$ integers, the initial matrix ($|a_{x,y}| \le 10^9$).

Each of the next $q$ lines contains one query. For type 1, $1 \le x \le n$, $1 \le y \le m$, and $|v| \le 10^9$. For type 2, $1 \le x_1 \le x_2 \le n$ and $1 \le y_1 \le y_2 \le m$.

## Output

For every query of type 2, print the subrectangle sum on its own line.

## Sample 1

Input:

```
3 3 4
1 2 3
4 5 6
7 8 9
2 1 1 3 3
2 2 2 3 3
1 2 2 0
2 1 1 2 2
```

Output:

```
45
28
7
```

## Run

From the repository root, after writing `segment_tree-2d.student.cpp`:

```sh
./scripts/check.sh src/data_structures/segment_tree/2d
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/segment_tree/2d --solution
```
