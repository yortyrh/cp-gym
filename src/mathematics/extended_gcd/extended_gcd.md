# Extended Euclidean Coefficients

**Technique:** extended Euclidean algorithm

Time limit: 1 s
Memory limit: 256 MB

## Problem

For each pair $(a, b)$, find integers $g, x, y$ such that $ax + by = g$ and $g = \gcd(|a|, |b|)$ (with $g \ge 0$).

Run the extended Euclidean algorithm: keep remainders together with Bézout coefficients and back-substitute along the remainder sequence. If the recorded gcd is negative, flip the signs of $g, x, y$.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^5$).

Each of the next $q$ lines contains two integers $a$ and $b$ ($|a|, |b| \le 10^9$).

## Output

For each pair, print three integers $g$, $x$, and $y$ on one line.

## Sample 1

Input:

```
2
240 46
3 5
```

Output:

```
2 -9 47
1 2 -1
```

## Run

From the repository root, after writing `extended_gcd.student.cpp`:

```sh
./scripts/check.sh src/mathematics/extended_gcd
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/extended_gcd --solution
```
