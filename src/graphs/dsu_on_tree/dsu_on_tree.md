# Subtree Palettes

**Technique:** DSU on tree (sack) for subtree color queries

Time limit: 1 s
Memory limit: 256 MB

## Problem

A tree of $n$ nodes is rooted at $1$. Node $i$ has a color $c_i$. For every node, print how many distinct colors appear in its subtree (the node itself included).

Compute subtree sizes and a heavy child. Recurse into light children and throw their color maps away, recurse into the heavy child and keep the map, then insert the light subtrees. This is sack / DSU on tree. Do not rebuild frequencies from scratch at each node.

## Input

The first line contains one integer $n$ ($1 \le n \le 10^5$).

The second line contains $n$ integers $c_1, \ldots, c_n$ ($1 \le c_i \le n$).

Each of the next $n-1$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$), a tree edge.

## Output

Print $n$ integers: the distinct-color counts for nodes $1, \ldots, n$, separated by spaces.

## Sample 1

Input:

```
5
1 2 1 3 2
1 2
1 3
3 4
3 5
```

Output:

```
3 1 3 1 1
```

## Run

From the repository root, after writing `dsu_on_tree.student.cpp`:

```sh
./scripts/check.sh src/graphs/dsu_on_tree
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/dsu_on_tree --solution
```
