# Levenshtein Distance

**Technique:** edit distance DP (insert, delete, substitute)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given two strings $a$ and $b$. Compute the Levenshtein distance: the fewest insertions, deletions, and substitutions that turn $a$ into $b$. Each operation costs $1$. Substituting a character by itself costs $0$.

Use 0-based DP: $d[i][j]$ is the distance between the prefixes $a[0..i)$ and $b[0..j)$. The recurrence is the minimum of delete, insert, and substitute. Do not search the space of all edit scripts.

## Input

The first line contains the string $a$ ($1 \le |a| \le 2000$).

The second line contains the string $b$ ($1 \le |b| \le 2000$).

Both strings use only lowercase English letters.

## Output

Print one integer: the edit distance.

## Sample 1

Input:

```
kitten
sitting
```

Output:

```
3
```

## Run

From the repository root, after writing `edit_distance.student.cpp`:

```sh
./scripts/check.sh src/strings/edit_distance
```

To run the reference solution instead:

```sh
./scripts/check.sh src/strings/edit_distance --solution
```
