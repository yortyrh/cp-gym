# Binomial Coefficient

**Technique:** binomial coefficient product formula

Time limit: 1 s
Memory limit: 256 MB

## Problem

For each pair $(n, k)$, print $\binom{n}{k}$. If $k < 0$ or $k > n$, the value is $0$.

Build the product in $O(\min(k, n-k))$ steps, dividing at each factor so the running value stays an integer. The sample $n$ is small enough for a 64-bit answer.

## Input

The first line contains one integer $q$ ($1 \le q \le 100$).

Each of the next $q$ lines contains two integers $n$ and $k$ ($0 \le n \le 60$, $-1 \le k \le n + 1$).

## Output

For each pair, print $\binom{n}{k}$.

## Sample 1

Input:

```
4
5 2
5 0
5 6
10 3
```

Output:

```
10
1
0
120
```

## Run

From the repository root, after writing `binomial.student.cpp`:

```sh
./scripts/check.sh src/mathematics/binomial
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/binomial --solution
```
