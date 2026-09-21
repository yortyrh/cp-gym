# Stern-Brocot Path

**Technique:** Stern-Brocot tree L/R path

Time limit: 1 s
Memory limit: 256 MB

## Problem

Every positive rational $a/b$ in lowest terms appears once in the Stern-Brocot tree. Starting from the ancestors $0/1$ and $1/0$, the mediant is $(L_n + R_n)/(L_d + R_d)$. Go `L` if $a/b$ is smaller than the mediant and `R` if it is larger, until the mediant equals $a/b$.

The fraction $1/1$ is the root and has an empty path.

## Input

The first line contains two integers $a$ and $b$ ($1 \le a, b \le 10^4$, $\gcd(a, b) = 1$).

## Output

Print the path as a string of `L` and `R` characters. Print an empty line for $1/1$.

## Sample 1

Input:

```
1 2
```

Output:

```
L
```

## Run

From the repository root, after writing `stern_brocot.student.cpp`:

```sh
./scripts/check.sh src/mathematics/stern_brocot
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/stern_brocot --solution
```
