# Fifteen Puzzle Solvability

**Technique:** 15-puzzle inversion parity

Time limit: 1 s
Memory limit: 256 MB

## Problem

A $4 \times 4$ sliding puzzle holds tiles $1..15$ and a blank $0$. The position is solvable if and only if the number of inversions among the fifteen tiles plus the $0$-based row of the blank (from the top) is odd.

An inversion is a pair of tiles $(p, q)$ appearing in row-major order with $p > q$ and neither equal to $0$.

## Input

Four lines of four integers each: the board in row-major order. The sixteen values are a permutation of $0..15$.

## Output

Print `YES` if the position is solvable and `NO` otherwise.

## Sample 1

Input:

```
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 0
```

Output:

```
YES
```

## Run

From the repository root, after writing `fifteen_puzzle.student.cpp`:

```sh
./scripts/check.sh src/others/fifteen_puzzle
```

To run the reference solution instead:

```sh
./scripts/check.sh src/others/fifteen_puzzle --solution
```
