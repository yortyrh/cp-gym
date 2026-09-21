# Substring Equality

**Technique:** polynomial rolling hash

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a string $s$ of length $n$ and $q$ queries. Each query gives two inclusive 1-based segments $[l_1, r_1]$ and $[l_2, r_2]$. Print `YES` if the two substrings are equal and `NO` otherwise.

Build prefix hashes $H_i = s_0 B^{i-1} + \cdots + s_{i-1}$ modulo $M$, using $B = 911382323$, $M = 10^9+7$, and mapping each character $c$ to `(unsigned char)c + 1`. A substring $s[l..r)$ is $H_r - H_l \cdot B^{r-l} \pmod M$. Answer each query in $O(1)$ after an $O(n)$ build. Do not compare the two segments character by character on every query.

If two segments have different lengths they are not equal.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 10^5$).

The second line contains the string $s$ of length $n$. It uses only lowercase English letters.

Each of the next $q$ lines contains four integers $l_1, r_1, l_2, r_2$ ($1 \le l_i \le r_i \le n$).

## Output

For every query, print `YES` or `NO` on its own line.

## Sample 1

Input:

```
6 3
banana
2 3 4 5
1 3 4 6
2 4 4 6
```

Output:

```
YES
NO
YES
```

## Run

From the repository root, after writing `string_hash.student.cpp`:

```sh
./scripts/check.sh src/strings/string_hash
```

To run the reference solution instead:

```sh
./scripts/check.sh src/strings/string_hash --solution
```
