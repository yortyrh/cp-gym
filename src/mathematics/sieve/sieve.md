# Sieve of Eratosthenes

**Technique:** Sieve of Eratosthenes

Time limit: 1 s
Memory limit: 256 MB

## Problem

Print every prime in $2..n$ in increasing order.

Mark multiples of each prime $p$ starting at $p^2$. Do not compute smallest prime factors; SPF belongs to factorization, not this sieve.

## Input

The first line contains one integer $n$ ($2 \le n \le 10^6$).

## Output

Print all primes $\le n$ on one line, separated by spaces.

## Sample 1

Input:

```
10
```

Output:

```
2 3 5 7
```

## Run

From the repository root, after writing `sieve.student.cpp`:

```sh
./scripts/check.sh src/mathematics/sieve
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/sieve --solution
```
