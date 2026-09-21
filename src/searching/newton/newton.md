# Newton Square Root

**Technique:** Newton–Raphson root finding

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a positive integer $n$. Compute $\sqrt{n}$ as a real number with Newton–Raphson.

Solve $f(x) = x^2 - n = 0$ with derivative $f'(x) = 2x$. Start from the guess $1$. Iterate $x \leftarrow x - f(x)/f'(x)$ at most $40$ times, and stop early when the absolute change is less than $10^{-10}$. Do not call `sqrt`.

## Input

The first line contains one integer $n$ ($1 \le n \le 10^{12}$).

## Output

Print one real number: the square root, with exactly $10$ digits after the decimal point.

## Sample 1

Input:

```
2
```

Output:

```
1.4142135624
```

## Run

From the repository root, after writing `newton.student.cpp`:

```sh
./scripts/check.sh src/searching/newton
```

To run the reference solution instead:

```sh
./scripts/check.sh src/searching/newton --solution
```
