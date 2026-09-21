# Matrix Determinant

**Technique:** determinant by Gaussian elimination

Time limit: 1 s
Memory limit: 256 MB

## Problem

Print $\det(A)$ for an $n \times n$ real matrix $A$.

Use Gaussian elimination with partial pivoting: the determinant is the product of the pivots, negated once per row swap, and $0$ if a column has no usable pivot. The sample is $2 \times 2$.

## Input

The first line contains one integer $n$ ($1 \le n \le 6$).

Each of the next $n$ lines contains $n$ real numbers.

## Output

Print the determinant with 10 digits after the decimal point.

## Sample 1

Input:

```
2
2 1
5 3
```

Output:

```
1.0000000000
```

## Run

From the repository root, after writing `determinant.student.cpp`:

```sh
./scripts/check.sh src/mathematics/determinant
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/determinant --solution
```
