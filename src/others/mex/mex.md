# Minimum Excludant

**Technique:** mex (smallest missing non-negative integer)

Time limit: 1 s
Memory limit: 256 MB

## Problem

The mex of a list is the smallest missing non-negative integer. Hash the present values and scan $0, 1, 2, \ldots$ until a gap.

## Input

The first line contains one integer $n$ ($0 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_i$ ($0 \le a_i \le 10^9$). If $n = 0$ the second line is empty.

## Output

Print the mex.

## Sample 1

Input:

```
3
0 1 3
```

Output:

```
2
```

## Run

From the repository root, after writing `mex.student.cpp`:

```sh
./scripts/check.sh src/others/mex
```

To run the reference solution instead:

```sh
./scripts/check.sh src/others/mex --solution
```
