# Unimodal Minimum

**Technique:** ternary search on a unimodal array

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a unimodal array $a_0, a_1, \ldots, a_{n-1}$: the values strictly decrease up to a unique minimum, then strictly increase (either side may be empty). Find that minimum value.

Ternary-search the index range. Compare the values at the two interior thirds; the third that cannot hold the minimum is discarded. When the remaining window has length at most $3$, scan it. Do not scan the whole array from the left.

## Input

The first line contains one integer $n$ ($1 \le n \le 10^5$).

The second line contains $n$ integers $a_i$ ($|a_i| \le 10^9$). The sequence is unimodal as described.

## Output

Print one integer: the minimum value.

## Sample 1

Input:

```
7
9 6 4 3 5 8 10
```

Output:

```
3
```

## Run

From the repository root, after writing `ternary_search.student.cpp`:

```sh
./scripts/check.sh src/searching/ternary_search
```

To run the reference solution instead:

```sh
./scripts/check.sh src/searching/ternary_search --solution
```
