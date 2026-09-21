# Target Sum Pairs

**Technique:** two pointers on a sorted array

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $n$ integers and a target $x$. Count the number of unordered pairs of distinct indices whose values sum to $x$.

Sort the array, then place one pointer at each end. Move the left pointer right when the sum is too small and the right pointer left when the sum is too large. When the sum equals $x$, count all equal values at both ends. Do not enumerate every pair.

## Input

The first line contains two integers $n$ and $x$ ($1 \le n \le 2 \cdot 10^5$, $1 \le x \le 10^9$).

The second line contains $n$ integers $a_1, \ldots, a_n$ ($1 \le a_i \le 10^9$).

## Output

Print one integer: the number of pairs with sum $x$.

## Sample 1

Input:

```
6 7
6 1 5 2 4 3
```

Output:

```
3
```

## Run

From the repository root, after writing `two_pointers.student.cpp`:

```sh
./scripts/check.sh src/searching/two_pointers
```

To run the reference solution instead:

```sh
./scripts/check.sh src/searching/two_pointers --solution
```
