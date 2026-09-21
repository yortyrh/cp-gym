# Teleporter Jumps

**Technique:** binary lifting successor on a functional graph

Time limit: 1 s
Memory limit: 256 MB

## Problem

There are $n$ planets, and planet $i$ has a single teleporter to planet $f_i$. You are given $q$ queries. Each query asks: starting at planet $x$, where do you land after using a teleporter exactly $k$ times?

The map is a functional graph. Precompute `up[b][i]`, the planet reached from $i$ after $2^b$ jumps. Answer each query by walking the bits of $k$. Do not simulate $k$ jumps one at a time.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 10^5$).

The second line contains $n$ integers $f_1, \ldots, f_n$ ($1 \le f_i \le n$).

Each of the next $q$ lines contains two integers $x$ and $k$ ($1 \le x \le n$, $1 \le k \le 10^{18}$).

## Output

For each query, print the destination planet on its own line.

## Sample 1

Input:

```
5 3
2 3 4 5 3
1 1
1 4
5 2
```

Output:

```
2
5
4
```

## Run

From the repository root, after writing `kth_successor.student.cpp`:

```sh
./scripts/check.sh src/graphs/kth_successor
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/kth_successor --solution
```
