# Floyd Cycle Detection

**Technique:** Floyd tortoise-and-hare cycle detection

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a functional graph on nodes $0..n-1$: each node has out-degree one, encoded by the array $f$. Starting from $s$, find the first node of the cycle reachable from $s$ and the cycle length.

The tortoise moves one step, the hare two steps. When they meet, reset a pointer to $s$ and walk both one step at a time to the cycle entrance $\mu$. Then walk the cycle once to obtain its length $\lambda$.

## Input

The first line contains two integers $n$ and $s$ ($1 \le n \le 10^5$, $0 \le s < n$).

The second line contains $n$ integers $f_0, \ldots, f_{n-1}$ ($0 \le f_i < n$).

## Output

Print two integers $\mu$ and $\lambda$: the cycle entrance and the cycle length.

## Sample 1

Input:

```
5 0
1 2 3 4 2
```

Output:

```
2 3
```

## Run

From the repository root, after writing `floyd_cycle.student.cpp`:

```sh
./scripts/check.sh src/others/floyd_cycle
```

To run the reference solution instead:

```sh
./scripts/check.sh src/others/floyd_cycle --solution
```
