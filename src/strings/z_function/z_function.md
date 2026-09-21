# Z-Function

**Technique:** Z-function (rightmost Z-box)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a string $s$ of length $n$. Compute its Z-array: $z_i$ is the length of the longest prefix of $s$ that is also a prefix of the suffix starting at $i$. Set $z_0 = 0$.

Maintain the rightmost segment $[L, R)$ (a Z-box) that matches a prefix. For each $i$, copy $z_{i-L}$ when $i$ lies inside that box, then extend by character comparisons and update $[L, R)$ if the match ends further to the right. Do this in $O(n)$. Do not compare $s[0..]$ with every suffix from scratch.

## Input

The first line contains one integer $n$ ($1 \le n \le 10^6$).

The second line contains the string $s$ of length $n$. It uses only lowercase English letters.

## Output

Print $n$ integers $z_0, z_1, \ldots, z_{n-1}$ separated by spaces.

## Sample 1

Input:

```
7
aaabaab
```

Output:

```
0 2 1 0 2 1 0
```

## Run

From the repository root, after writing `z_function.student.cpp`:

```sh
./scripts/check.sh src/strings/z_function
```

To run the reference solution instead:

```sh
./scripts/check.sh src/strings/z_function --solution
```
