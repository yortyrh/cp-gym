# Prime Exponent in Factorial

**Technique:** de Polignac / Legendre formula

Time limit: 1 s
Memory limit: 256 MB

## Problem

For each pair $(n, p)$ with $p$ prime, print the exponent of $p$ in $n!$:
$\lfloor n/p \rfloor + \lfloor n/p^2 \rfloor + \lfloor n/p^3 \rfloor + \cdots$.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^4$).

Each of the next $q$ lines contains two integers $n$ and $p$ ($1 \le n \le 10^{12}$, $2 \le p \le 10^{12}$, and $p$ is prime).

## Output

For each pair, print the exponent of $p$ in $n!$.

## Sample 1

Input:

```
3
10 2
5 2
5 3
```

Output:

```
8
3
1
```

## Run

From the repository root, after writing `factorial_exponents.student.cpp`:

```sh
./scripts/check.sh src/mathematics/factorial_exponents
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/factorial_exponents --solution
```
