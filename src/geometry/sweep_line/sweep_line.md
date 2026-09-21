# Painted Patches

**Technique:** sweep line (union area of axis-aligned rectangles)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You paint $n$ axis-aligned rectangles on the plane. Rectangles may overlap. Compute the area of their union.

Sweep along the $x$-axis. Between two consecutive distinct $x$-coordinates, take every rectangle that fully covers that vertical slab, merge the active $y$-intervals, and add $\mathrm{coverage} \times \mathrm{width}$. Do not rasterize a pixel grid.

## Input

The first line contains one integer $n$ ($1 \le n \le 200$).

Each of the next $n$ lines contains four integers $x_1, y_1, x_2, y_2$ ($0 \le x_1 < x_2 \le 10^9$, $0 \le y_1 < y_2 \le 10^9$), the corners of one rectangle.

## Output

Print one integer: the area of the union.

## Sample 1

Input:

```
2
0 0 2 2
1 1 3 3
```

Output:

```
7
```

## Run

From the repository root, after writing `sweep_line.student.cpp`:

```sh
./scripts/check.sh src/geometry/sweep_line
```

To run the reference solution instead:

```sh
./scripts/check.sh src/geometry/sweep_line --solution
```
