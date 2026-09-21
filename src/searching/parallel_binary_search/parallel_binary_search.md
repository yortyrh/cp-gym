# First Contact

**Technique:** parallel binary search with DSU

Time limit: 1 s
Memory limit: 256 MB

## Problem

There are $n$ outposts. $m$ undirected cables are installed one by one in the given order. Cable $t$ appears at time $t$ ($1$-based). You are given $q$ pairs of outposts. For each pair, report the earliest time at which they lie in the same connected component. If they never connect, print $-1$.

Binary-search the answer of every query at once: group queries by their current midpoint, replay the prefix of cables with a DSU, then shrink each query's search range. $n$ is small, so even a linear scan per query fits the sample.

## Input

The first line contains three integers $n$, $m$, and $q$ ($1 \le n \le 40$, $0 \le m, q \le 40$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$), the cable added at the next time.

Each of the next $q$ lines contains two integers $a$ and $b$ ($1 \le a, b \le n$).

## Output

Print $q$ lines: the first connecting time of each pair, or `-1`.

## Sample 1

Input:

```
4 4 3
1 2
3 4
2 3
1 4
1 2
1 4
1 3
```

Output:

```
1
3
3
```

## Run

From the repository root, after writing `parallel_binary_search.student.cpp`:

```sh
./scripts/check.sh src/searching/parallel_binary_search
```

To run the reference solution instead:

```sh
./scripts/check.sh src/searching/parallel_binary_search --solution
```
