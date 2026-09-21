# Suffix Tree Membership

**Technique:** compressed suffix trie (suffix tree)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a string $s$ and $q$ patterns. For each pattern, decide whether it occurs in $s$ as a contiguous substring.

Build a compressed trie of every suffix of $s$. Edge labels are nonempty pieces of $s$; when a new suffix shares only a prefix of an edge, split that edge. Then walk each pattern down the tree. This construction is $O(n^2)$ in the worst case and is enough for the given limits. Do not scan $s$ for every pattern.

## Input

The first line contains the string $s$ ($1 \le |s| \le 2000$).

The second line contains one integer $q$ ($1 \le q \le 2000$).

Each of the next $q$ lines contains one nonempty pattern. All strings use only lowercase English letters, and the total length of the patterns is at most $2 \cdot 10^5$.

## Output

For every pattern, print `YES` if it occurs in $s$, otherwise `NO`.

## Sample 1

Input:

```
banana
3
ana
nan
ab
```

Output:

```
YES
YES
NO
```

## Run

From the repository root, after writing `suffix_tree.student.cpp`:

```sh
./scripts/check.sh src/strings/suffix_tree
```

To run the reference solution instead:

```sh
./scripts/check.sh src/strings/suffix_tree --solution
```
