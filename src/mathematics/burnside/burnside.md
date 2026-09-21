# Necklaces under Rotation

**Technique:** Burnside lemma on the cyclic group

Time limit: 1 s
Memory limit: 256 MB

## Problem

Count distinct necklaces with $c$ colors and $b$ beads, where two necklaces that differ by a rotation are the same.

By Burnside, average the colourings fixed by each rotation $r = 0..b-1$. Rotation $r$ has $\gcd(r, b)$ cycles, so it contributes $c^{\gcd(r, b)}$. Divide the sum by $b$.

## Input

The first line contains one integer $q$ ($1 \le q \le 100$).

Each of the next $q$ lines contains two integers $c$ and $b$ ($1 \le c \le 10$, $1 \le b \le 12$).

## Output

For each pair, print the number of necklaces.

## Sample 1

Input:

```
3
2 4
1 5
3 1
```

Output:

```
6
1
3
```

## Run

From the repository root, after writing `burnside.student.cpp`:

```sh
./scripts/check.sh src/mathematics/burnside
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/burnside --solution
```
