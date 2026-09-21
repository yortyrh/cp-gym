# One-Dimensional Annealing

**Technique:** simulated annealing (1D minimization)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A lantern's wasted light at position $x$ is $(x - t)^2$. You start at position $s$ and must search for a better $x$ with simulated annealing.

Use `std::mt19937` with seed $1$, $2000$ steps, a uniform step in $[-1, 1]$ scaled by $0.1 + T$, and acceptance probability $\exp(-\Delta / T)$ with $T = 1 - i/2000$. Keep the best position seen. Do not jump directly to $t$.

## Input

The first line contains two real numbers $s$ and $t$ ($|s|, |t| \le 100$).

## Output

Print one real number: the best position found, with exactly $10$ digits after the decimal point.

## Sample 1

Input:

```
4 -1
```

Output:

```
-0.9998217285
```

## Run

From the repository root, after writing `simulated_annealing.student.cpp`:

```sh
./scripts/check.sh src/searching/simulated_annealing
```

To run the reference solution instead:

```sh
./scripts/check.sh src/searching/simulated_annealing --solution
```
