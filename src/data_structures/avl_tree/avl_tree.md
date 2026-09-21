# Ordered Insert, Erase, and k-th

**Technique:** AVL tree (height-balanced BST with subtree sizes)

Time limit: 1 s
Memory limit: 256 MB

## Problem

Start with an empty set of distinct integers. Process $q$ operations:

- `1 x` — insert $x$ (do nothing if $x$ is already present)
- `2 x` — erase $x$ (do nothing if $x$ is not present)
- `3 k` — print the $k$-th smallest value in the set (1-based), or `-1` if the set has fewer than $k$ elements

Maintain an AVL tree: after each insert or erase, rotations restore $|h(L) - h(R)| \le 1$. Store subtree sizes so the $k$-th order statistic is $O(\log n)$.

Do not rebuild a sorted array on every query.

## Input

The first line contains one integer $q$ ($1 \le q \le 2 \cdot 10^5$).

Each of the next $q$ lines contains one operation. All values $x$ satisfy $|x| \le 10^9$. For type 3, $k \ge 1$.

## Output

For every operation of type 3, print the answer on its own line.

## Sample 1

Input:

```
15
1 10
1 20
1 5
3 1
3 2
3 3
3 4
1 10
2 10
3 2
2 99
1 7
3 1
3 2
3 3
```

Output:

```
5
10
20
-1
20
5
7
20
```

## Run

From the repository root, after writing `avl_tree.student.cpp`:

```sh
./scripts/check.sh src/data_structures/avl_tree
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/avl_tree --solution
```
