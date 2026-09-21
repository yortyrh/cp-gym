# Point Primitives

**Technique:** 2D point orientation, dot, and distance

Time limit: 1 s
Memory limit: 256 MB

## Problem

Answer $q$ queries on 2D points:

- `1 ax ay bx by` — print the dot product $(a_x, a_y) \cdot (b_x, b_y)$
- `2 ax ay bx by` — print the cross product $a_x b_y - a_y b_x$
- `3 ox oy ax ay bx by` — print the orientation $\overrightarrow{OA} \times \overrightarrow{OB}$ (positive means a left turn at $O$)
- `4 ax ay bx by` — print the Euclidean distance between the two points

## Input

The first line contains one integer $q$ ($1 \le q \le 10^5$).

Each of the next $q$ lines contains a query as described above. All coordinates are integers with absolute value at most $10^6$.

## Output

For each query, print one number. Distances use 10 digits after the decimal point; the other queries print an integer.

## Sample 1

Input:

```
4
1 1 0 0 1
2 1 0 0 1
3 0 0 1 0 0 1
4 0 0 3 4
```

Output:

```
0
1
1
5.0000000000
```

## Run

From the repository root, after writing `point.student.cpp`:

```sh
./scripts/check.sh src/geometry/point
```

To run the reference solution instead:

```sh
./scripts/check.sh src/geometry/point --solution
```
