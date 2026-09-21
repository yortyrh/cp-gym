# Carmichael Lambda

**Technique:** Carmichael lambda from prime powers

Time limit: 1 s
Memory limit: 256 MB

## Problem

For each $n$, print the Carmichael function $\lambda(n)$: the exponent of the multiplicative group modulo $n$.

Factor $n = \prod p_i^{k_i}$. Then $\lambda(p^k) = \varphi(p^k)$ except $\lambda(2^k) = 2^{k-2}$ for $k \ge 3$, and $\lambda(n)$ is the LCM of the $\lambda(p^k)$. By convention $\lambda(1) = 1$.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^4$).

Each of the next $q$ lines contains one integer $n$ ($1 \le n \le 10^{12}$).

## Output

For each $n$, print $\lambda(n)$.

## Sample 1

Input:

```
4
1
8
15
7
```

Output:

```
1
2
4
6
```

## Run

From the repository root, after writing `carmichael.student.cpp`:

```sh
./scripts/check.sh src/mathematics/carmichael
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/carmichael --solution
```
