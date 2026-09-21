# Batch Shipping

**Technique:** divide-and-conquer DP optimization (layered cost)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You must split a row of $n$ positive weights into exactly $k$ nonempty contiguous batches. The cost of a batch is the square of its total weight. Minimize the sum of batch costs.

Let `dp[g][i]` be the minimum cost of the prefix of length $i$ using exactly $g$ batches:
`dp[g][i] = min_{j < i} dp[g-1][j] + (sum[j+1..i])^2`.
The optimal split point is monotone in $i$, so each layer can be filled with divide-and-conquer optimization instead of a full $O(n)$ scan for every $i$.

## Input

The first line contains two integers $n$ and $k$ ($1 \le k \le n \le 400$).

The second line contains $n$ integers $a_1, \ldots, a_n$ ($1 \le a_i \le 10^6$).

## Output

Print one integer: the minimum total cost.

## Sample 1

Input:

```
4 2
1 3 2 4
```

Output:

```
52
```

## Run

From the repository root, after writing `divide_conquer_dp.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/divide_conquer_dp
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/divide_conquer_dp --solution
```
