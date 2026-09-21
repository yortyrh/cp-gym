# Modular Inverse by Extended Euclid

**Technique:** modular inverse via extended Euclidean algorithm

Time limit: 1 s
Memory limit: 256 MB

## Problem

For each pair $(v, m)$ with $m > 1$, print the inverse of $v$ modulo $m$: an integer $x \in [0, m)$ with $v x \equiv 1 \pmod{m}$. If $\gcd(v, m) \ne 1$, no inverse exists and you must print `-1`.

The inverse is the Bézout coefficient of $v$ from extended Euclid, reduced into $[0, m)$.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^5$).

Each of the next $q$ lines contains two integers $v$ and $m$ ($|v| \le 10^9$, $2 \le m \le 10^9$).

## Output

For each pair, print the inverse in $[0, m)$, or `-1`.

## Sample 1

Input:

```
3
3 11
3 7
4 6
```

Output:

```
4
5
-1
```

## Run

From the repository root, after writing `modular_inverse.student.cpp`:

```sh
./scripts/check.sh src/mathematics/modular_inverse
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/modular_inverse --solution
```
