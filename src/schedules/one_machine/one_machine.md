# Smith's Rule

**Technique:** one-machine Smith's rule (duration/weight order)

Time limit: 1 s
Memory limit: 256 MB

## Problem

There is one machine and $n$ jobs. Job $i$ has processing time $d_i$ and weight $w_i$. Print an order that minimises the weighted sum of completion times.

Smith's rule: sort by increasing $d_i / w_i$, i.e. job $i$ before job $j$ when $d_i w_j < d_j w_i$. Jobs are $0$-based in input order.

## Input

The first line contains one integer $n$ ($1 \le n \le 10^5$).

Each of the next $n$ lines contains two integers $d_i$ and $w_i$ ($1 \le d_i, w_i \le 10^9$).

## Output

Print $n$ $0$-based indices, the job order.

## Sample 1

Input:

```
2
2 1
1 2
```

Output:

```
1 0
```

## Run

From the repository root, after writing `one_machine.student.cpp`:

```sh
./scripts/check.sh src/schedules/one_machine
```

To run the reference solution instead:

```sh
./scripts/check.sh src/schedules/one_machine --solution
```
