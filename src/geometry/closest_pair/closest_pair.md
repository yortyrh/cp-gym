# Nearby Beacons

**Technique:** closest pair of points (divide and conquer)

Time limit: 1 s
Memory limit: 256 MB

## Problem

There are $n$ beacons in the plane. Find two distinct beacons with minimum Euclidean distance, and print that distance squared (so the answer is an integer).

Sort by $x$-coordinate, solve the left and right halves, then inspect only the points that lie in a strip of width $\sqrt{d}$ around the midline, ordered by $y$. Each point needs only a constant number of $y$-neighbors. Do not compare every pair when $n$ is large.

## Input

The first line contains one integer $n$ ($2 \le n \le 5 \cdot 10^4$).

Each of the next $n$ lines contains two integers $x_i$ and $y_i$ ($|x_i|, |y_i| \le 10^9$).

## Output

Print one integer: the minimum squared Euclidean distance.

## Sample 1

Input:

```
3
0 0
3 4
1 1
```

Output:

```
2
```

## Run

From the repository root, after writing `closest_pair.student.cpp`:

```sh
./scripts/check.sh src/geometry/closest_pair
```

To run the reference solution instead:

```sh
./scripts/check.sh src/geometry/closest_pair --solution
```
