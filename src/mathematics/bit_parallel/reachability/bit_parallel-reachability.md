# Signal Spread

**Technique:** bitset Floyd / reachability

Time limit: 1 s
Memory limit: 256 MB

## Problem

A directed network has $n$ nodes and $m$ wires. You get $q$ questions of the form: can a signal travel from $u$ to $v$ along directed wires (a node always reaches itself)?

Store the reachable set of each node as a bitset. Then for $k = 1, \ldots, n$, every node that already reaches $k$ should or-in the reachable set of $k$. This is bit-parallel Floyd–Warshall for reachability. Do not start a fresh BFS for every query.

## Input

The first line contains three integers $n$, $m$, and $q$ ($1 \le n \le 400$, $0 \le m \le n(n-1)$, $1 \le q \le 10^5$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$), a directed wire $u \rightarrow v$.

Each of the next $q$ lines contains two integers $a$ and $b$ ($1 \le a, b \le n$).

## Output

For each query, print `1` if $a$ can reach $b$, otherwise `0`.

## Sample 1

Input:

```
4 4 3
1 2
2 3
4 1
3 3
1 3
3 1
4 3
```

Output:

```
1
0
1
```

## Run

From the repository root, after writing `bit_parallel-reachability.student.cpp`:

```sh
./scripts/check.sh src/mathematics/bit_parallel/reachability
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/bit_parallel/reachability --solution
```
