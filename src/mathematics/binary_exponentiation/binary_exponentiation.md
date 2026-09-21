# Modular Fast Exponentiation

**Technique:** binary exponentiation with overflow-safe modular multiply

Time limit: 1 s
Memory limit: 256 MB

## Problem

For each triple $(b, e, m)$, compute $b^e \bmod m$.

Square the base and multiply into the result when the current exponent bit is set. Multiply two residues by doubling (Russian peasant multiplication) so the product never overflows a 64-bit word. Reduce a negative base into $[0, m)$.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^5$).

Each of the next $q$ lines contains three integers $b$, $e$, and $m$ ($|b| \le 10^{18}$, $0 \le e \le 10^{18}$, $1 \le m \le 10^9 + 7$).

## Output

For each triple, print $b^e \bmod m$ in $[0, m)$.

## Sample 1

Input:

```
3
2 10 1000
3 0 7
-2 3 5
```

Output:

```
24
1
2
```

## Run

From the repository root, after writing `binary_exponentiation.student.cpp`:

```sh
./scripts/check.sh src/mathematics/binary_exponentiation
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/binary_exponentiation --solution
```
