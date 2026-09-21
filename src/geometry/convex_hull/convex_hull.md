# Monotone Chain Hull

**Technique:** monotone-chain convex hull

Time limit: 1 s
Memory limit: 256 MB

## Problem

Build the convex hull of $n$ 2D points. The hull is counterclockwise, starts at the lexicographically smallest point (smallest $x$, then smallest $y$), and contains no three consecutive collinear vertices. Duplicate points are ignored.

Sort by $x$ then $y$, build the lower chain left-to-right and the upper chain right-to-left, popping while the turn is not strictly left.

## Input

The first line contains one integer $n$ ($1 \le n \le 10^5$).

Each of the next $n$ lines contains two integers $x_i$ and $y_i$ ($|x_i|, |y_i| \le 10^6$).

## Output

Print $h$ — the number of hull vertices — then $h$ lines of hull coordinates in counterclockwise order.

## Sample 1

Input:

```
6
0 0
1 1
0 2
2 0
2 2
1 0
```

Output:

```
4
0 0
2 0
2 2
0 2
```

## Run

From the repository root, after writing `convex_hull.student.cpp`:

```sh
./scripts/check.sh src/geometry/convex_hull
```

To run the reference solution instead:

```sh
./scripts/check.sh src/geometry/convex_hull --solution
```
