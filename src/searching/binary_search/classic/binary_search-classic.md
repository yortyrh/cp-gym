# Lower Bound on a Sorted Array

**Technique:** binary search (first true index)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a nondecreasing array $a_0, a_1, \ldots, a_{n-1}$ and $q$ queries. For each query value $x$, find the smallest index $i$ such that $a_i \ge x$. If no such index exists, print $n$.

Binary-search the monotone predicate "$a_i \ge x$" on the half-open range $[0, n)$. The search returns the first true index, or $n$. Arrays are 0-based. Do not scan the array from the left on every query.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 10^5$).

The second line contains $n$ integers $a_0 \le a_1 \le \cdots \le a_{n-1}$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains one integer $x$ ($|x| \le 10^9$).

## Output

For every query, print the answer on its own line.

## Sample 1

Input:

```
5 4
1 3 3 7 9
7
3
4
10
```

Output:

```
3
1
3
5
```

## Run

From the repository root, after writing `binary_search-classic.student.cpp`:

```sh
./scripts/check.sh src/searching/binary_search/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/searching/binary_search/classic --solution
```
