# Minimum Assignment Cost

**Technique:** Hungarian (Kuhn-Munkres) min-cost assignment

Time limit: 1 s
Memory limit: 256 MB

## Problem

There are $n$ workers and $n$ jobs. Assigning worker $i$ to job $j$ has cost $c_{i,j}$. Each worker takes exactly one job and each job is taken by exactly one worker.

Compute the minimum total cost of such an assignment.

The Hungarian algorithm maintains dual potentials and grows a tight equality subgraph until a perfect matching exists. $n$ is small, but $n!$ permutations are still too many; do not enumerate them.

## Input

The first line contains one integer $n$ ($1 \le n \le 20$).

Each of the next $n$ lines contains $n$ integers $c_{i,j}$ ($0 \le c_{i,j} \le 10^6$).

## Output

Print one integer: the minimum assignment cost.

## Sample 1

Input:

```
2
1 2
3 1
```

Output:

```
2
```

## Run

From the repository root, after writing `hungarian.student.cpp`:

```sh
./scripts/check.sh src/graphs/hungarian
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/hungarian --solution
```
