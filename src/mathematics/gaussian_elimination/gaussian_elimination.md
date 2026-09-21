# Gaussian Elimination

**Technique:** Gaussian elimination with partial pivoting

Time limit: 1 s
Memory limit: 256 MB

## Problem

Run Gaussian elimination with partial pivoting on an $n \times n$ real matrix.

For each column, swap in the row with the largest absolute value on or below the pivot, skip the column if that value is below $10^{-9}$, then eliminate below. The rank is the number of pivots used. The determinant is the product of the pivots, with a sign flip for every row swap (and $0$ if a column is skipped). The sample is $2 \times 2$.

## Input

The first line contains one integer $n$ ($1 \le n \le 6$).

Each of the next $n$ lines contains $n$ real numbers, the matrix entries (absolute value at most $1000$).

## Output

Print two lines: the rank, then the determinant with 10 digits after the decimal point.

## Sample 1

Input:

```
2
2 1
5 3
```

Output:

```
2
1.0000000000
```

## Run

From the repository root, after writing `gaussian_elimination.student.cpp`:

```sh
./scripts/check.sh src/mathematics/gaussian_elimination
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/gaussian_elimination --solution
```
