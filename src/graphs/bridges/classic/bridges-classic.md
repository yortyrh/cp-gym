# Critical Roads

**Technique:** Tarjan bridges (discovery time / low-link DFS)

Time limit: 1 s
Memory limit: 256 MB

## Problem

A town has $n$ junctions and $m$ two-way roads. A road is critical if removing it (and keeping every other road) splits the town into more than one connected piece.

Find every critical road. Report each road as a pair of junctions $(u, v)$ with $u < v$.

Run a DFS that records discovery times `tin[v]` and low-link values `low[v]`. A tree edge $u{-}v$ ($u$ parent of $v$) is a bridge if and only if `low[v] > tin[u]`. Skip the parent when scanning undirected adjacency lists. Do not use a max-flow edge-connectivity algorithm.

Vertices are 1-based in the input and output. Convert to 0-based at I/O if your arrays are 0-based.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 10^5$, $0 \le m \le 2 \cdot 10^5$).

Each of the next $m$ lines contains two integers $u$ and $v$ ($1 \le u, v \le n$, $u \neq v$), a two-way road. The graph may be disconnected. There are no self-loops.

## Output

On the first line print $k$, the number of bridges.

Then print $k$ lines, each with two integers $u$ and $v$ ($u < v$), the bridges in lexicographic order.

## Sample 1

Input:

```
4 4
1 2
2 3
2 4
3 4
```

Output:

```
1
1 2
```

## Run

From the repository root, after writing `bridges-classic.student.cpp`:

```sh
./scripts/check.sh src/graphs/bridges/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/bridges/classic --solution
```
