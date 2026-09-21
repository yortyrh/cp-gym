# Kasai LCP Array

**Technique:** Kasai longest common prefix array

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a string $s$ of length $n$. Let $\mathrm{sa}$ be the suffix array of $s$ (0-based starting indices of suffixes in lexicographic order). Compute the Kasai LCP array: $\mathrm{lcp}_0 = 0$ and $\mathrm{lcp}_i$ is the length of the longest common prefix of the suffixes starting at $\mathrm{sa}_{i-1}$ and $\mathrm{sa}_i$.

Walk the suffixes in text order. If the previous LCP was $h > 0$, the next one is at least $h-1$, so reuse it. Build $\mathrm{sa}$ first (doubling is fine), then Kasai in $O(n)$. Do not recompute every adjacent LCP from scratch.

## Input

The first line contains one integer $n$ ($1 \le n \le 10^5$).

The second line contains the string $s$ of length $n$. It uses only lowercase English letters.

## Output

Print $n$ integers $\mathrm{lcp}_0, \mathrm{lcp}_1, \ldots, \mathrm{lcp}_{n-1}$ separated by spaces.

## Sample 1

Input:

```
6
banana
```

Output:

```
0 1 3 0 0 2
```

## Run

From the repository root, after writing `lcp.student.cpp`:

```sh
./scripts/check.sh src/strings/lcp
```

To run the reference solution instead:

```sh
./scripts/check.sh src/strings/lcp --solution
```
