# Stack Minimum Queries

**Technique:** min-stack (value plus prefix minimum)

Time limit: 1 s
Memory limit: 256 MB

## Problem

Start with an empty stack. Process $q$ operations:

- `1 x` — push $x$ onto the stack
- `2` — pop the top element
- `3` — print the minimum value currently on the stack

Store each entry as a pair `(value, min_of_the_stack_so_far)` so push, pop, and get-min are $O(1)$ and never scan the stack.

Pop and get-min are only asked when the stack is non-empty.

## Input

The first line contains one integer $q$ ($1 \le q \le 2 \cdot 10^5$).

Each of the next $q$ lines contains one operation. All values $x$ satisfy $|x| \le 10^9$.

## Output

For every operation of type 3, print the current minimum on its own line.

## Sample 1

Input:

```
8
1 3
1 1
1 4
3
2
3
2
3
```

Output:

```
1
1
3
```

## Run

From the repository root, after writing `min_stack.student.cpp`:

```sh
./scripts/check.sh src/data_structures/min_stack
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/min_stack --solution
```
