# Union-Find with Undo

**Technique:** DSU with rollback (union by size, no path compression)

Time limit: 1 s
Memory limit: 256 MB

## Problem

There are $n$ elements labeled $1, 2, \ldots, n$. You process $q$ operations:

- `1 a b` — unite the components of $a$ and $b$. If they already share a component, this is not a merge.
- `2 a b` — print `YES` if $a$ and $b$ are in the same component, otherwise print `NO`
- `3` — undo the last successful merge. If there is nothing to undo, do nothing.

Path compression is incompatible with undo. Use union by size, walk to the root without compressing, and keep a stack of merges. Type 3 pops one merge and restores parent and size.

Do not copy the whole DSU to support undo.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

Each of the next $q$ lines is one operation. Type 1 and type 2 have the form `t a b` ($1 \le a, b \le n$). Type 3 is a single integer `3`.

## Output

For every operation of type 2, print `YES` or `NO` on its own line.

## Sample 1

Input:

```
4 9
1 1 2
1 1 2
2 1 2
1 3 4
2 3 4
3
2 3 4
3
2 1 2
```

Output:

```
YES
YES
NO
NO
```

## Run

From the repository root, after writing `disjoint_set-rollback.student.cpp`:

```sh
./scripts/check.sh src/data_structures/disjoint_set/rollback
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/disjoint_set/rollback --solution
```
