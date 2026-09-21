# Linear Diophantine Equation

**Technique:** linear Diophantine equation via extended Euclid

Time limit: 1 s
Memory limit: 256 MB

## Problem

Solve $ax + by = c$ over the integers. A solution exists if and only if $g = \gcd(a, b)$ divides $c$ (treat $g = 0$ separately: only $c = 0$ is solvable, with $x = y = 0$).

From a Bézout identity $ax_0 + by_0 = g$, scale by $c / g$. The general solution then steps by $b / g$ in $x$ and $-a / g$ in $y$.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^5$).

Each of the next $q$ lines contains three integers $a$, $b$, and $c$ ($|a|, |b|, |c| \le 10^9$).

## Output

If there is no solution, print `-1`.

Otherwise print two lines:
- $x$ and $y$ — one particular solution
- $x_{\mathrm{step}}$ and $y_{\mathrm{step}}$ — the general-solution steps

## Sample 1

Input:

```
3
3 5 1
3 6 5
4 6 2
```

Output:

```
2 -1
5 -3
-1
-1 1
3 -2
```

## Run

From the repository root, after writing `linear_diophantine.student.cpp`:

```sh
./scripts/check.sh src/mathematics/linear_diophantine
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/linear_diophantine --solution
```
