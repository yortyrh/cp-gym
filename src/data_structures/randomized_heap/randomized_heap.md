# Meldable Heap Operations

**Technique:** randomized meldable min-heap

Time limit: 1 s
Memory limit: 256 MB

## Problem

You have $n$ min-heaps, initially empty, labeled $1, 2, \ldots, n$. Process $q$ operations:

- `1 i x` — insert $x$ into heap $i$
- `2 i` — print the minimum of heap $i$
- `3 i` — extract the minimum of heap $i$ and print it
- `4 i j` — meld heap $j$ into heap $i$ (heap $j$ becomes empty)

A randomized meldable heap merges two trees in expected $O(\log n)$: attach the larger root as a child of the smaller root, swap children with probability $1/2$, and recurse. Insert is meld with a single-node heap; extract-min is meld of the root's two children.

Type 2 and type 3 are only asked when heap $i$ is non-empty. For type 4, $i \neq j$.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

Each of the next $q$ lines contains one operation. All values $x$ satisfy $|x| \le 10^9$. Heap indices satisfy $1 \le i, j \le n$.

## Output

For every operation of type 2 or 3, print the answer on its own line.

## Sample 1

Input:

```
2 8
1 1 4
1 1 1
1 1 3
2 1
3 1
1 2 0
4 1 2
2 1
```

Output:

```
1
1
0
```

## Run

From the repository root, after writing `randomized_heap.student.cpp`:

```sh
./scripts/check.sh src/data_structures/randomized_heap
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/randomized_heap --solution
```
