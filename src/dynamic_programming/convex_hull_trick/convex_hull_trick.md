# Line Quotes

**Technique:** convex hull trick / Li Chao DP

Time limit: 1 s
Memory limit: 256 MB

## Problem

You process $n$ orders. Order $i$ has size $a_i$. After finishing the first $j$ orders you keep a leftover rate $b_j$ ($b_0$ is the initial rate). The cost of jumping from after order $j$ straight to finishing order $i$ is $b_j \cdot a_i$. You may start from $j = 0$ with cost $0$.

Formally, `dp[0] = 0` and
`dp[i] = min_{0 \le j < i} (dp[j] + b[j] * a[i])` for $i = 1, \ldots, n$.
Print `dp[n]`.

The array $a$ is strictly increasing and $b$ is strictly decreasing and nonnegative, so each previous $j$ is a line $y = b_j x + \mathrm{dp}[j]$ evaluated at $x = a_i$. Maintain the lower hull (convex hull trick or a Li Chao tree). $n$ is small, so a direct $O(n^2)$ loop also fits.

## Input

The first line contains one integer $n$ ($1 \le n \le 2000$).

The second line contains $n$ integers $a_1, \ldots, a_n$ ($1 \le a_1 < a_2 < \cdots < a_n \le 10^6$).

The third line contains $n$ integers $b_0, \ldots, b_{n-1}$ ($10^6 \ge b_0 > b_1 > \cdots > b_{n-1} \ge 0$).

## Output

Print one integer: `dp[n]`.

## Sample 1

Input:

```
3
2 5 7
10 4 1
```

Output:

```
47
```

## Run

From the repository root, after writing `convex_hull_trick.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/convex_hull_trick
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/convex_hull_trick --solution
```
