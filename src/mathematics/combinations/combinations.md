# Enumerate Combinations

**Technique:** lexicographic k-subset generation

Time limit: 1 s
Memory limit: 256 MB

## Problem

Print every $k$-element subset of $\{0, 1, \ldots, n-1\}$ in lexicographic order.

Start from $\{0, 1, \ldots, k-1\}$. To advance, find the rightmost index that can increase, increment it, and fill the suffix with consecutive integers.

## Input

One line with two integers $n$ and $k$ ($1 \le k \le n \le 8$).

## Output

Print each subset on its own line as $k$ increasing indices separated by spaces.

## Sample 1

Input:

```
4 2
```

Output:

```
0 1
0 2
0 3
1 2
1 3
2 3
```

## Run

From the repository root, after writing `combinations.student.cpp`:

```sh
./scripts/check.sh src/mathematics/combinations
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/combinations --solution
```
