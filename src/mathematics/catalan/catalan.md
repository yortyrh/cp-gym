# Catalan Numbers

**Technique:** Catalan numbers C_n = C(2n, n) / (n+1)

Time limit: 1 s
Memory limit: 256 MB

## Problem

For each $n$, print the Catalan number $C_n = \binom{2n}{n} / (n+1)$, with $C_0 = 1$.

These count Dyck words, binary trees, and triangulations of a convex $(n+2)$-gon. Compute the binomial coefficient first, then divide by $n+1$.

## Input

The first line contains one integer $q$ ($1 \le q \le 30$).

Each of the next $q$ lines contains one integer $n$ ($0 \le n \le 30$).

## Output

For each $n$, print $C_n$.

## Sample 1

Input:

```
4
0
1
2
5
```

Output:

```
1
1
2
42
```

## Run

From the repository root, after writing `catalan.student.cpp`:

```sh
./scripts/check.sh src/mathematics/catalan
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/catalan --solution
```
