# Euler Totient

**Technique:** Euler's totient from prime factorization

Time limit: 1 s
Memory limit: 256 MB

## Problem

For each $n$, print $\varphi(n)$: the number of integers in $1..n$ coprime to $n$.

Factor $n$ and apply $\varphi(n) = n \prod_{p \mid n} (1 - 1/p)$, i.e. for each distinct prime $p$ set $\textit{result} \gets \textit{result} - \textit{result}/p$.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^4$).

Each of the next $q$ lines contains one integer $n$ ($1 \le n \le 10^{12}$).

## Output

For each $n$, print $\varphi(n)$.

## Sample 1

Input:

```
4
1
10
12
7
```

Output:

```
1
4
4
6
```

## Run

From the repository root, after writing `euler_phi.student.cpp`:

```sh
./scripts/check.sh src/mathematics/euler_phi
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/euler_phi --solution
```
