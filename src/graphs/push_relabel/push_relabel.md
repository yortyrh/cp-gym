# Maximum Flow (Push-Relabel)

**Technique:** push-relabel maximum flow

Time limit: 1 s
Memory limit: 256 MB

## Problem

A directed network has $n$ vertices labeled $1, 2, \ldots, n$ and $m$ capacity edges. Compute the maximum flow from source $s$ to sink $t$.

Push-relabel keeps excess at vertices. Saturate the source's outgoing edges, then push along admissible residual edges and relabel when a vertex is stuck. The network is small; implement this preflow method rather than listing paths by hand.

## Input

The first line contains four integers $n$, $m$, $s$, and $t$ ($2 \le n \le 50$, $0 \le m \le 200$, $1 \le s, t \le n$).

Each of the next $m$ lines contains three integers $u$, $v$, and $c$ ($1 \le u, v \le n$, $0 \le c \le 1000$).

## Output

Print one integer: the maximum $s$-$t$ flow.

## Sample 1

Input:

```
4 4 1 4
1 2 2
1 3 2
2 4 2
3 4 2
```

Output:

```
4
```

## Run

From the repository root, after writing `push_relabel.student.cpp`:

```sh
./scripts/check.sh src/graphs/push_relabel
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/push_relabel --solution
```
