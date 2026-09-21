# Feasible Circulation

**Technique:** feasible circulation with vertex demands

Time limit: 1 s
Memory limit: 256 MB

## Problem

A directed network has $n$ vertices labeled $1, 2, \ldots, n$. Vertex $v$ has an integer demand $d_v$: if $d_v > 0$ the vertex must receive $d_v$ more incoming flow than outgoing flow; if $d_v < 0$ it must send $|d_v|$ more outgoing flow than incoming flow; if $d_v = 0$ it is balanced. Edges have capacities and may carry any flow in $[0, c]$.

Decide whether a flow exists that meets every demand and respects every capacity.

Reduce the problem to a single max-flow: attach a super-source to supply vertices and a super-sink to demand vertices. The instance is small.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 40$, $0 \le m \le 120$).

The second line contains $n$ integers $d_1, \ldots, d_n$ ($|d_v| \le 1000$).

Each of the next $m$ lines contains three integers $u$, $v$, and $c$ ($1 \le u, v \le n$, $0 \le c \le 1000$).

## Output

Print `YES` if a feasible circulation exists, otherwise `NO`.

## Sample 1

Input:

```
2 1
-2 2
1 2 2
```

Output:

```
YES
```

## Run

From the repository root, after writing `circulation.student.cpp`:

```sh
./scripts/check.sh src/graphs/circulation
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/circulation --solution
```
