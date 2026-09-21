# Order Statistic

**Technique:** quickselect (3-way partition)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $n$ integers and a 0-based rank $k$. Print the $k$-th smallest value (so $k = 0$ is the minimum and $k = n-1$ is the maximum). Equal values are allowed.

Use quickselect: pick a pivot, 3-way-partition into less / equal / greater, and recurse on the one side that still contains rank $k$. Average $O(n)$. Do not fully sort the array. Do not call `std::nth_element`.

## Input

The first line contains two integers $n$ and $k$ ($1 \le n \le 10^5$, $0 \le k < n$).

The second line contains $n$ integers $a_i$ ($|a_i| \le 10^9$).

## Output

Print one integer: the $k$-th smallest value.

## Sample 1

Input:

```
6 2
9 1 7 3 3 8
```

Output:

```
3
```

## Run

From the repository root, after writing `quick_select.student.cpp`:

```sh
./scripts/check.sh src/searching/quick_select
```

To run the reference solution instead:

```sh
./scripts/check.sh src/searching/quick_select --solution
```
