# Triangle Metrics

**Technique:** triangle area, perimeter, and circumradius

Time limit: 1 s
Memory limit: 256 MB

## Problem

Three non-collinear points $A, B, C$ determine a triangle. Print its area, perimeter, and circumradius.

The area is $\frac12 |\overrightarrow{AB} \times \overrightarrow{AC}|$. The perimeter is the sum of the side lengths. The circumradius is $R = abc / (4\Delta)$.

## Input

Three lines, each with two integers, the coordinates of $A$, $B$, and $C$ (absolute value at most $1000$). The points are not collinear.

## Output

Print three numbers with 10 digits after the decimal point: area, perimeter, circumradius.

## Sample 1

Input:

```
0 0
4 0
0 3
```

Output:

```
6.0000000000 12.0000000000 2.5000000000
```

## Run

From the repository root, after writing `triangle.student.cpp`:

```sh
./scripts/check.sh src/geometry/triangle
```

To run the reference solution instead:

```sh
./scripts/check.sh src/geometry/triangle --solution
```
