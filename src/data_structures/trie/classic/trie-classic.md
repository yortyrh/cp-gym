# Prefix Counters

**Technique:** trie (prefix tree over lowercase letters)

Time limit: 1 s
Memory limit: 256 MB

## Problem

Insert $n$ words, then answer $q$ queries. Each query is a string $p$. Print how many inserted words have $p$ as a prefix.

Use a trie on the alphabet `a`–`z`. Each node stores how many words pass through it. Insert and query in time linear in the string length.

Do not compare $p$ against every stored word.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 10^5$).

The next $n$ lines contain the words to insert.

The next $q$ lines contain the query prefixes.

Every word and every query is non-empty, uses only lowercase English letters, and the total length of all $n + q$ strings is at most $10^6$. Duplicate words are allowed and each copy counts.

## Output

For every query, print the number of inserted words that have the given prefix, on its own line.

## Sample 1

Input:

```
5 4
apple
app
apricot
banana
apple
ap
app
ban
z
```

Output:

```
4
3
1
0
```

## Run

From the repository root, after writing `trie-classic.student.cpp`:

```sh
./scripts/check.sh src/data_structures/trie/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/trie/classic --solution
```
