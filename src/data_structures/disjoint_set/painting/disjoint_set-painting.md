# Offline Subarray Painting

**Technique:** DSU jump-to-next-unpainted (offline, right to left)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You have an array of $n$ cells, all unpainted (color $0$). You apply $q$ operations in order. Operation $i$ paints every cell in the inclusive range $[l_i, r_i]$ with color $c_i$, overwriting earlier colors.

Later operations win, so process the operations from last to first. Keep a DSU where `parent[i]` is the next still-unpainted index greater than or equal to $i$. After painting cell $i$, jump by setting `parent[i] = find(i + 1)`. A sentinel at $n + 1$ stops the scan.

Do not walk every cell of $[l, r]$ when most of it is already painted.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

Each of the next $q$ lines contains three integers $l$, $r$, and $c$ ($1 \le l \le r \le n$, $1 \le c \le 10^9$).

## Output

Print $n$ integers: the final color of cells $1, 2, \ldots, n$. Print $0$ for a cell that was never painted.

## Sample 1

Input:

```
6 3
1 5 1
2 4 2
3 3 3
```

Output:

```
1 2 3 2 1 0
```

## Run

From the repository root, after writing `disjoint_set-painting.student.cpp`:

```sh
./scripts/check.sh src/data_structures/disjoint_set/painting
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/disjoint_set/painting --solution
```
