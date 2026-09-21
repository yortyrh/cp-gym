# Prefix Function

**Technique:** Knuth–Morris–Pratt prefix (failure) function

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a string $s$ of length $n$. Compute its prefix function $\pi$, where $\pi_i$ is the length of the longest proper prefix of $s[0..i]$ that is also a suffix of $s[0..i]$. Equivalently, $\pi_i$ is the longest border of the prefix that ends at index $i$.

The array is 0-based: $\pi_0 = 0$. Compute it in $O(n)$ by walking the previous border and falling back along $\pi$. Do not compare every pair of prefixes.

## Input

The first line contains one integer $n$ ($1 \le n \le 10^6$).

The second line contains the string $s$ of length $n$. It uses only lowercase English letters.

## Output

Print $n$ integers $\pi_0, \pi_1, \ldots, \pi_{n-1}$ separated by spaces.

## Sample 1

Input:

```
9
ababcabab
```

Output:

```
0 0 1 2 0 1 2 3 4
```

## Run

From the repository root, after writing `prefix_function-classic.student.cpp`:

```sh
./scripts/check.sh src/strings/prefix_function/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/strings/prefix_function/classic --solution
```
