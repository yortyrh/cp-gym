# Fermat Modular Inverse

**Technique:** Fermat's little theorem inverse a^(p-2) mod p

Time limit: 1 s
Memory limit: 256 MB

## Problem

Let $p$ be prime. For a base $a$ not divisible by $p$, Fermat's little theorem says $a^{p-1} \equiv 1 \pmod{p}$, so the inverse of $a$ modulo $p$ is $a^{p-2} \bmod p$.

For each pair, print that inverse. The sample uses small primes only.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^4$).

Each of the next $q$ lines contains two integers $a$ and $p$ ($1 \le a < p \le 10^6$, and $p$ is prime).

## Output

For each pair, print $a^{p-2} \bmod p$.

## Sample 1

Input:

```
3
3 11
3 7
2 5
```

Output:

```
4
5
3
```

## Run

From the repository root, after writing `fermat.student.cpp`:

```sh
./scripts/check.sh src/mathematics/fermat
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/fermat --solution
```
