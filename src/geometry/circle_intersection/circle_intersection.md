# Disk Intersection Area

**Technique:** area of intersection of two disks

Time limit: 1 s
Memory limit: 256 MB

## Problem

Print the area of intersection of two disks (filled circles).

If one disk contains the other, the area is the smaller disk. If they are disjoint (or tangent from the outside), the area is $0$. Otherwise add the two circular segments cut by the radical axis.

## Input

Two lines. Each line contains three numbers $x$, $y$, and $r$: the center and radius of a disk ($|x|, |y| \le 1000$, $0 < r \le 1000$).

## Output

Print the intersection area with 10 digits after the decimal point.

## Sample 1

Input:

```
0 0 1
1 0 1
```

Output:

```
1.2283696986
```

## Run

From the repository root, after writing `circle_intersection.student.cpp`:

```sh
./scripts/check.sh src/geometry/circle_intersection
```

To run the reference solution instead:

```sh
./scripts/check.sh src/geometry/circle_intersection --solution
```
