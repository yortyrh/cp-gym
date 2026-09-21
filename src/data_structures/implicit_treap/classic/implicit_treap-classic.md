# Positional Insert, Erase, and Range Sum

**Technique:** implicit treap (Cartesian tree on positions)

Time limit: 1 s
Memory limit: 256 MB

## Problem

Start with an empty sequence. Process $q$ operations:

- `1 p x` — insert $x$ so that it becomes the element at 1-based position $p$ (elements at $p, p+1, \ldots$ shift one place to the right)
- `2 p` — erase the element at position $p$
- `3 l r` — print the sum of the inclusive range $[l, r]$

Positions are 1-based. Maintain an implicit treap: each node holds a value, a subtree size, a subtree sum, and a random heap priority. `split` and `merge` by size give expected $O(\log n)$ insert, erase, and range sum.

The sequence starts empty. Every operation is valid: an insert uses $1 \le p \le \mathrm{size}+1$, and erase/sum queries use existing positions.

## Input

The first line contains one integer $q$ ($1 \le q \le 2 \cdot 10^5$).

Each of the next $q$ lines contains one operation. All values $x$ satisfy $|x| \le 10^9$. Every answer fits in a signed 64-bit integer.

## Output

For every operation of type 3, print the range sum on its own line.

## Sample 1

Input:

```
6
1 1 4
1 2 5
1 2 1
3 1 3
2 2
3 1 2
```

Output:

```
10
9
```

## Run

From the repository root, after writing `implicit_treap-classic.student.cpp`:

```sh
./scripts/check.sh src/data_structures/implicit_treap/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/implicit_treap/classic --solution
```
