# Pattern Occurrences

**Technique:** Knuth–Morris–Pratt automaton

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a text $t$ and a pattern $p$. Find every starting position where $p$ occurs in $t$ as a contiguous substring. Occurrences may overlap.

Build the prefix function of $p$ only. Scan $t$ while maintaining the length of the current match; on a mismatch, fall back along $\pi$. When the match length equals $|p|$, record the start index and continue from $\pi_{|p|-1}$. Do not build $\pi$ of $p + \# + t$ if you can run the automaton online. Do not check every alignment in $O(|p|)$.

## Input

The first line contains the text $t$ ($1 \le |t| \le 10^6$).

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

From the repository root, after writing `kmp.student.cpp`:

```sh
./scripts/check.sh src/strings/kmp
```

To run the reference solution instead:

```sh
./scripts/check.sh src/strings/kmp --solution
```
