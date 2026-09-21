# Target Sum Rolls

**Technique:** expected value DP (dice)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You roll a fair $f$-sided die with faces $1, \ldots, f$. Starting from $0$, you add each roll to a running total and stop when the total is at least $n$. Compute the expected number of rolls.

Let `E[x]` be the expected extra rolls from current sum $x$. Then `E[x] = 0` for $x \ge n$, and for $x < n$
`E[x] = 1 + (1/f) * sum_{d=1}^{f} E[x+d]`
with `E[y] = 0` whenever $y \ge n$. Fill from $x = n-1$ down to $0$. Output `E[0]` as a modular fraction $P \cdot Q^{-1} \bmod (10^9+7)$.

## Input

The first line contains two integers $n$ and $f$ ($1 \le n \le 5000$, $1 \le f \le 100$).

## Output

Print one integer: the expected number of rolls modulo $10^9+7$.

## Sample 1

Input:

```
3 2
```

Output:

```
250000004
```

## Run

From the repository root, after writing `expected_value.student.cpp`:

```sh
./scripts/check.sh src/mathematics/expected_value
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/expected_value --solution
```
