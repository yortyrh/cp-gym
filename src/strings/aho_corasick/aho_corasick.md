# Multi-Pattern Search

**Technique:** Aho–Corasick automaton

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $k$ patterns and one text $t$. For each pattern, count how many times it occurs in $t$ as a contiguous substring. Occurrences may overlap. A pattern that is a suffix of another pattern must still be counted when the longer one matches.

Build a trie of the patterns on `a`–`z`, then failure links by BFS so each text character is processed once. When a node is visited, every pattern that ends there (including those copied from the failure link) is an occurrence ending at the current index. Do not search each pattern separately.

## Input

The first line contains one integer $k$ ($1 \le k \le 10^5$).

Each of the next $k$ lines contains one pattern. Patterns are non-empty, use only lowercase English letters, and their total length is at most $10^6$. Duplicate patterns are allowed; report each copy on its own line.

The last line contains the text $t$ ($1 \le |t| \le 10^6$), using only lowercase English letters.

## Output

Print $k$ integers, one per line: the number of occurrences of the $i$-th pattern in $t$.

## Sample 1

Input:

```
3
he
she
his
ushers
```

Output:

```
1
1
0
```

## Run

From the repository root, after writing `aho_corasick.student.cpp`:

```sh
./scripts/check.sh src/strings/aho_corasick
```

To run the reference solution instead:

```sh
./scripts/check.sh src/strings/aho_corasick --solution
```
