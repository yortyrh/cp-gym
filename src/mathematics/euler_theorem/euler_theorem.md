# Euler Inverse

**Technique:** Euler's theorem inverse a^(phi(n)-1) mod n

Time limit: 1 s
Memory limit: 256 MB

## Problem

If $\gcd(a, n) = 1$, Euler's theorem gives $a^{\varphi(n)} \equiv 1 \pmod n$, so the inverse of $a$ modulo $n$ is $a^{\varphi(n)-1} \bmod n$.

For each pair, print that inverse, or `-1` when $a$ is not coprime to $n$.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^4$).

Each of the next $q$ lines contains two integers $a$ and $n$ ($1 \le a \le 10^9$, $2 \le n \le 10^9$).

## Output

For each pair, print the inverse in $[0, n)$, or `-1`.

## Sample 1

Input:

```
3
3 10
3 11
4 6
```

Output:

```
7
4
-1
```

## Run

From the repository root, after writing `euler_theorem.student.cpp`:

```sh
./scripts/check.sh src/mathematics/euler_theorem
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/euler_theorem --solution
```
