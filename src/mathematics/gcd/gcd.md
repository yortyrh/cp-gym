# Greatest Common Divisor

**Technique:** Euclidean algorithm (GCD and LCM)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $q$ pairs of integers. For each pair $(a, b)$, print $\gcd(|a|, |b|)$ and $\operatorname{lcm}(|a|, |b|)$.

Use Euclid's algorithm: replace $(a, b)$ by $(b, a \bmod b)$ until $b = 0$. Then $\operatorname{lcm}(a, b) = 0$ if $a = 0$ or $b = 0$, and $|a| / \gcd(a, b) \cdot |b|$ otherwise.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^5$).

Each of the next $q$ lines contains two integers $a$ and $b$ ($|a|, |b| \le 10^{12}$).

## Output

For each pair, print the GCD and the LCM on its own line.

## Sample 1

Input:

```
4
48 18
-48 18
4 6
0 6
```

Output:

```
6 144
6 144
2 12
6 0
```

## Run

From the repository root, after writing `gcd.student.cpp`:

```sh
./scripts/check.sh src/mathematics/gcd
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/gcd --solution
```
