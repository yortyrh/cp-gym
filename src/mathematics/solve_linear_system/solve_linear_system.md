# Linear System

**Technique:** solve Ax = b by Gaussian elimination and back substitution

Time limit: 1 s
Memory limit: 256 MB

## Problem

Solve $Ax = b$ for a square real matrix $A$. If $A$ is singular (rank less than $n$), print `-1`.

Augment $A$ with $b$, run Gaussian elimination with partial pivoting, then back-substitute. The sample is a $2 \times 2$ system with a unique solution.

## Input

The first line contains one integer $n$ ($1 \le n \le 6$).

Each of the next $n$ lines contains $n$ real numbers, a row of $A$.

The last line contains $n$ real numbers, the vector $b$.

## Output

If there is a unique solution, print $n$ numbers with 10 digits after the decimal point. Otherwise print `-1`.

## Sample 1

Input:

```
2
1 1
2 1
5 8
```

Output:

```
3.0000000000 2.0000000000
```

## Run

From the repository root, after writing `solve_linear_system.student.cpp`:

```sh
./scripts/check.sh src/mathematics/solve_linear_system
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/solve_linear_system --solution
```
