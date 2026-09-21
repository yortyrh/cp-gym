# Matrix Rank

**Technique:** matrix rank by Gaussian elimination

Time limit: 1 s
Memory limit: 256 MB

## Problem

Print the rank of an $n \times m$ real matrix: the number of nonzero pivots after Gaussian elimination with partial pivoting. The sample is small.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n, m \le 6$).

Each of the next $n$ lines contains $m$ real numbers.

## Output

Print one integer: the rank.

## Sample 1

Input:

```
2 3
1 2 3
2 4 6
```

Output:

```
1
```

## Run

From the repository root, after writing `matrix_rank.student.cpp`:

```sh
./scripts/check.sh src/mathematics/matrix_rank
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/matrix_rank --solution
```
