# Queue Minimum Queries

**Technique:** min-queue (two min-stacks)

Time limit: 1 s
Memory limit: 256 MB

## Problem

Start with an empty FIFO queue. Process $q$ operations:

- `1 x` — push $x$ to the back of the queue
- `2` — pop the front element
- `3` — print the minimum value currently in the queue

Simulate the queue with two min-stacks (front and back). Push goes to the back stack. When the front stack is empty, move the back stack onto the front (reversing it). The queue minimum is the min of the two stacks' minima.

Pop and get-min are only asked when the queue is non-empty. Do not scan the whole queue on every query.

## Input

The first line contains one integer $q$ ($1 \le q \le 2 \cdot 10^5$).

Each of the next $q$ lines contains one operation. All values $x$ satisfy $|x| \le 10^9$.

## Output

For every operation of type 3, print the current minimum on its own line.

## Sample 1

Input:

```
10
1 3
1 1
1 4
3
2
3
2
3
1 0
3
```

Output:

```
1
1
4
0
```

## Run

From the repository root, after writing `min_queue.student.cpp`:

```sh
./scripts/check.sh src/data_structures/min_queue
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/min_queue --solution
```
