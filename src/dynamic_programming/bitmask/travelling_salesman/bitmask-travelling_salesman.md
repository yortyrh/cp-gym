# Shortest Hamiltonian Circuit

**Technique:** Held–Karp bitmask DP (`dp[mask][v]`)

Time limit: 1 s
Memory limit: 256 MB

## Problem

There are $n$ cities numbered $1 \ldots n$. The cost of travelling from city $i$ to city $j$ is $d_{i,j}$ (the matrix need not be symmetric). Find the cheapest circuit that starts at city $1$, visits every city exactly once, and returns to city $1$.

Let `mask` be the set of visited cities and `v` the last city. `dp[mask][v]` is the cheapest path that starts at city $1$, visits exactly the cities in `mask`, and ends at `v`. Do not enumerate permutations.

## Input

The first line contains one integer $n$ ($2 \le n \le 16$).

Each of the next $n$ lines contains $n$ integers $d_{i,1}, \ldots, d_{i,n}$ ($0 \le d_{i,j} \le 10^9$, $d_{i,i} = 0$).

## Output

Print one integer: the minimum circuit cost.

## Sample 1

Input:

```
4
0 10 15 20
5 0 9 10
6 13 0 12
8 8 9 0
```

Output:

```
35
```

## Run

From the repository root, after writing `bitmask-travelling_salesman.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/bitmask/travelling_salesman
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/bitmask/travelling_salesman --solution
```
