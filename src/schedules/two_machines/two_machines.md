# Johnson's Two-Machine Order

**Technique:** Johnson's rule for two-machine flow shop

Time limit: 1 s
Memory limit: 256 MB

## Problem

Each job must run on machine A then machine B, with times $A_i$ and $B_i$. Print a job order that minimises the makespan.

Johnson's rule: jobs with $A_i \le B_i$ go first, sorted by increasing $A_i$; the rest go last, sorted by decreasing $B_i$. Indices are $0$-based.

## Input

The first line contains one integer $n$ ($1 \le n \le 10^5$).

Each of the next $n$ lines contains two integers $A_i$ and $B_i$ ($1 \le A_i, B_i \le 10^9$).

## Output

Print $n$ $0$-based indices, the Johnson order.

## Sample 1

Input:

```
2
3 2
1 4
```

Output:

```
1 0
```

## Run

From the repository root, after writing `two_machines.student.cpp`:

```sh
./scripts/check.sh src/schedules/two_machines
```

To run the reference solution instead:

```sh
./scripts/check.sh src/schedules/two_machines --solution
```
