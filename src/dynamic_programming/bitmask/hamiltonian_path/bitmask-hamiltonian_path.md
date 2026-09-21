# Hamiltonian Paths

**Technique:** bitmask DP counting Hamiltonian paths

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a directed graph on $n$ vertices as an $n \times n$ 0/1 adjacency matrix ($a_{i,i} = 0$). Count the number of directed paths that visit every vertex exactly once (Hamiltonian paths). Two paths are different if their vertex sequences differ. Print the answer modulo $10^9 + 7$.

This is Held–Karp counting, not a closed tour: `dp[mask][v]` is the number of ways to visit exactly the vertices in `mask` and end at `v`. A path may start at any vertex. Do not search $n!$ orders.

## Input

The first line contains one integer $n$ ($1 \le n \le 16$).

Each of the next $n$ lines contains $n$ integers $a_{i,1}, \ldots, a_{i,n}$ ($a_{i,j} \in \{0, 1\}$, $a_{i,i} = 0$).

## Output

Print one integer: the number of Hamiltonian paths modulo $10^9 + 7$.

## Sample 1

Input:

```
3
0 1 1
0 0 1
0 0 0
```

Output:

```
1
```

## Run

From the repository root, after writing `bitmask-hamiltonian_path.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/bitmask/hamiltonian_path
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/bitmask/hamiltonian_path --solution
```
