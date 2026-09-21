# Companion Sequence

**Technique:** linear recurrence via matrix exponentiation

Time limit: 1 s
Memory limit: 256 MB

## Problem

Define a sequence by $u_0 = 0$, $u_1 = 1$, and $u_i = a \cdot u_{i-1} + b \cdot u_{i-2}$ for $i \ge 2$. Compute $u_n$ modulo $10^9+7$.

Write one step as multiplication by the companion matrix $\begin{pmatrix} a & b \\ 1 & 0 \end{pmatrix}$. Raise that matrix to the power $n-1$ with binary exponentiation. Do not walk $n$ terms one by one.

## Input

The first line contains three integers $a$, $b$, and $n$ ($0 \le a, b < 10^9+7$, $0 \le n \le 10^{18}$).

## Output

Print one integer: $u_n$ modulo $10^9+7$.

## Sample 1

Input:

```
1 1 10
```

Output:

```
55
```

## Run

From the repository root, after writing `matrix_exponentiation.student.cpp`:

```sh
./scripts/check.sh src/mathematics/matrix_exponentiation
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/matrix_exponentiation --solution
```
