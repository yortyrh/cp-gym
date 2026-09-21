# Prefix Occurrence Counts

**Technique:** prefix function (count each prefix as a substring)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a string $s$ of length $n$. For every length $k = 1, 2, \ldots, n$, count how many times the prefix $s[0..k-1]$ occurs in $s$ as a contiguous substring. Occurrences may overlap.

Every occurrence of a prefix of length $k$ is either the prefix itself or a border of some prefix $s[0..i]$. After computing $\pi$, count how often each border length appears, push those counts down the $\pi$-chain, then add one for the prefix itself. Do not slide a window for every $k$.

## Input

The first line contains one integer $n$ ($1 \le n \le 10^6$).

The second line contains the string $s$ of length $n$. It uses only lowercase English letters.

## Output

Print $n$ integers: the number of occurrences of the prefixes of lengths $1, 2, \ldots, n$.

## Sample 1

Input:

```
3
aaa
```

Output:

```
3 2 1
```

## Run

From the repository root, after writing `prefix_function-prefix_count.student.cpp`:

```sh
./scripts/check.sh src/strings/prefix_function/prefix_count
```

To run the reference solution instead:

```sh
./scripts/check.sh src/strings/prefix_function/prefix_count --solution
```
