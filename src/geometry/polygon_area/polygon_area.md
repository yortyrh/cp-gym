# Polygon Signed Area

**Technique:** shoelace (surveyor) formula

Time limit: 1 s
Memory limit: 256 MB

## Problem

Given a simple polygon by its vertices in order (first vertex is not repeated at the end), print the signed area. Counterclockwise winding is positive.

The shoelace formula sums consecutive cross products $x_i y_{i+1} - y_i x_{i+1}$ around the closed chain and divides by $2$.

## Input

The first line contains one integer $n$ ($3 \le n \le 10^5$).

Each of the next $n$ lines contains two integers $x_i$ and $y_i$ ($|x_i|, |y_i| \le 10^6$).

## Output

Print the signed area with 10 digits after the decimal point.

## Sample 1

Input:

```
4
0 0
2 0
2 2
0 2
```

Output:

```
4.0000000000
```

## Run

From the repository root, after writing `polygon_area.student.cpp`:

```sh
./scripts/check.sh src/geometry/polygon_area
```

To run the reference solution instead:

```sh
./scripts/check.sh src/geometry/polygon_area --solution
```
