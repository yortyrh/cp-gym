# Same Component Queries

**Technique:** disjoint-set union (union by size, path compression)

Time limit: 1 s
Memory limit: 256 MB

## Problem

There are $n$ elements labeled $1, 2, \ldots, n$. Initially each element is its own component. You process $q$ operations:

- `1 a b` — unite the components of $a$ and $b$ (do nothing if they already share a component)
- `2 a b` — print `YES` if $a$ and $b$ are in the same component, otherwise print `NO`

A disjoint-set union with union by size and path compression handles all operations in almost $O(1)$ amortized time. Do not run a graph search from scratch on every query.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

Each of the next $q$ lines contains three integers $t$, $a$, and $b$ ($t \in \{1, 2\}$, $1 \le a, b \le n$).

## Output

For every operation of type 2, print `YES` or `NO` on its own line.

## Sample 1

Input:

```
5 7
2 1 2
1 1 2
2 1 2
1 3 4
1 2 3
2 1 4
2 1 5
```

Output:

```
NO
YES
YES
NO
```

## Run

From the repository root, after writing `disjoint_set-classic.student.cpp`:

```sh
./scripts/check.sh src/data_structures/disjoint_set/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/disjoint_set/classic --solution
```
