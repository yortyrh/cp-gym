# Lyndon Factorization

**Technique:** Duval Lyndon factorization

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a string $s$ of length $n$. Factor it into Lyndon words $w_1 w_2 \ldots w_m$ such that $w_1 \ge w_2 \ge \cdots \ge w_m$ lexicographically. This factorization is unique.

A Lyndon word is a nonempty string that is strictly smaller than all of its proper suffixes. Compute the factorization with Duval's three-pointer scan in $O(n)$. Do not enumerate every split.

## Input

The first line contains one integer $n$ ($1 \le n \le 10^6$).

The second line contains the string $s$ of length $n$. It uses only lowercase English letters.

## Output

Print the Lyndon factors on one line, separated by spaces.

## Sample 1

Input:

```
5
abcab
```

Output:

```
abc ab
```

## Run

From the repository root, after writing `lyndon.student.cpp`:

```sh
./scripts/check.sh src/strings/lyndon
```

To run the reference solution instead:

```sh
./scripts/check.sh src/strings/lyndon --solution
```
