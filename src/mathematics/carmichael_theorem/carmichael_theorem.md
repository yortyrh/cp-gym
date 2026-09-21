# Carmichael Congruence

**Technique:** Carmichael theorem a^lambda(n) ≡ 1 (mod n)

Time limit: 1 s
Memory limit: 256 MB

## Problem

Carmichael's theorem: if $\gcd(a, n) = 1$ and $n > 1$, then $a^{\lambda(n)} \equiv 1 \pmod n$. This is stronger than Euler when $\lambda(n) < \varphi(n)$ (for example powers of $2$).

For each pair, print $1$ if $\gcd(a, n) = 1$ and the congruence holds, otherwise $0$.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^4$).

Each of the next $q$ lines contains two integers $a$ and $n$ ($0 \le |a| \le 10^9$, $1 \le n \le 10^6$).

## Output

For each pair, print `1` or `0`.

## Sample 1

Input:

```
4
3 8
3 15
2 8
5 1
```

Output:

```
1
0
0
0
```

## Run

From the repository root, after writing `carmichael_theorem.student.cpp`:

```sh
./scripts/check.sh src/mathematics/carmichael_theorem
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/carmichael_theorem --solution
```
