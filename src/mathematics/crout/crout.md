# Crout Determinant

**Technique:** determinant via Crout LU (unit diagonal on U)

Time limit: 1 s
Memory limit: 256 MB

## Problem

Compute $\det(A)$ by Crout factorization $A = LU$ with $U_{ii} = 1$. Then $\det(A)$ is the product of the diagonal of $L$. If some $L_{jj}$ is below $10^{-9}$ in absolute value, the determinant is $0$.

Crout does not pivot. The sample is a $2 \times 2$ matrix that needs no pivoting.

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

From the repository root, after writing `crout.student.cpp`:

```sh
./scripts/check.sh src/mathematics/crout
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/crout --solution
```
