# Simpson Integration

**Technique:** composite Simpson's rule

Time limit: 1 s
Memory limit: 256 MB

## Problem

Integrate the quadratic $f(x) = ax^2 + bx + c$ on the closed interval $[L, R]$ with composite Simpson's rule, using an even number of subintervals.

Let $h = (R-L)/m$. The weighted sum is $f(L) + f(R)$ plus $4f$ at odd nodes and $2f$ at even interior nodes. Multiply by $h/3$. Do not use a closed-form antiderivative.

## Input

The first line contains three integers $a$, $b$, and $c$ ($|a|, |b|, |c| \le 100$).

The second line contains two real numbers $L$ and $R$ ($-10^3 \le L < R \le 10^3$).

The third line contains one even integer $m$ ($2 \le m \le 1000$): the number of subintervals.

## Output

Print one real number: the approximate integral, with exactly $10$ digits after the decimal point.

## Sample 1

Input:

```
1 0 0
0 1
200
```

Output:

```
0.3333333333
```

## Run

From the repository root, after writing `simpson.student.cpp`:

```sh
./scripts/check.sh src/searching/simpson
```

To run the reference solution instead:

```sh
./scripts/check.sh src/searching/simpson --solution
```
