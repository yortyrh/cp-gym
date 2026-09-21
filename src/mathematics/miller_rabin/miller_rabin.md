# Miller-Rabin Primality

**Technique:** deterministic Miller-Rabin for 64-bit integers

Time limit: 1 s
Memory limit: 256 MB

## Problem

Decide whether each $n$ is prime.

Write $n-1 = 2^s \cdot d$ with $d$ odd. For each witness $a$ from the 64-bit deterministic set $\{2, 325, 9375, 28178, 450775, 9780504, 1795265022\}$, compute $a^d \bmod n$ and the successive squares. $n$ is composite if a witness fails. Check the small primes $2,3,5,7,11,13,17,19,23,29,31,37$ first. The sample uses only tiny $n$.

## Input

The first line contains one integer $q$ ($1 \le q \le 20$).

Each of the next $q$ lines contains one integer $n$ ($0 \le n \le 200$).

## Output

For each $n$, print `YES` if $n$ is prime and `NO` otherwise.

## Sample 1

Input:

```
6
0
1
2
97
91
9
```

Output:

```
NO
NO
YES
YES
NO
NO
```

## Run

From the repository root, after writing `miller_rabin.student.cpp`:

```sh
./scripts/check.sh src/mathematics/miller_rabin
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/miller_rabin --solution
```
