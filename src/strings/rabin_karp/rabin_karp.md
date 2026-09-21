# Rolling-Hash Search

**Technique:** Rabin–Karp (rolling hash plus exact compare)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a text $t$ and a pattern $p$. Find every starting position where $p$ occurs in $t$. Occurrences may overlap.

Hash $t$ and $p$ with the same polynomial rolling hash used for substring equality ($B = 911382323$, $M = 10^9+7$, character $c$ mapped to `(unsigned char)c + 1`). Every window of $t$ whose hash equals the hash of $p$ must still be compared character by character, so collisions cannot produce a false match. Do not use KMP for this exercise.

## Input

The first line contains the text $t$ ($1 \le |t| \le 2 \cdot 10^5$).

The second line contains the pattern $p$ ($1 \le |p| \le |t|$).

Both strings use only lowercase English letters.

## Output

Print one integer $k$: the number of occurrences.

If $k > 0$, print a second line with $k$ 0-based starting indices in increasing order.

## Sample 1

Input:

```
ababa
aba
```

Output:

```
2
0 2
```

## Run

From the repository root, after writing `rabin_karp.student.cpp`:

```sh
./scripts/check.sh src/strings/rabin_karp
```

To run the reference solution instead:

```sh
./scripts/check.sh src/strings/rabin_karp --solution
```
