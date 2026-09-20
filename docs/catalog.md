# Practice Catalog

Entries follow the chapter and section layout of
[cpbook-code](https://github.com/stevenhalim/cpbook-code) (Competitive Programming 4). Topics that
exist only in [cp-algorithms](https://github.com/cp-algorithms/cp-algorithms) are placed in the
nearest CP4 section rather than in the website's own category tree.

The **Source** column names the closest `cpbook-code` file and/or cp-algorithms page. Judge-only
`UVa*.cpp` programs are listed when they introduce a reusable technique; their I/O parsers stay out
of the library.

Migrated topics are exercise folders under `src/`. Unmigrated topics are still one header
each under `include/cprepo/`. Related topics live as siblings in the same folder.

## Chapter 2 — Data Structures and Libraries

### `ch2/lineards`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Min-stack | `data_structures/min_stack.hpp` | cp-algorithms `stack_queue_modification` |
| Implemented | Min-queue | `data_structures/min_queue.hpp` | cp-algorithms `stack_queue_modification` |
| Implemented | Bit manipulation | `data_structures/bit_manipulation.hpp` | `ch2/lineards/bit_manipulation.cpp` |
| Implemented | Next same popcount | `data_structures/next_same_popcount.hpp` | Gosper's hack |
| Implemented | Subsets of a mask | `data_structures/bit_subsets.hpp` | bitmask subset enumeration |
| Planned | Array algorithms / lists | | `ch2/lineards/array_algorithms.cpp`, `list.cpp` (STL wrappers; not a library API) |

### `ch2/nonlineards`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Quick select / k-th | `searching/quick_select.hpp` | `ch2/nonlineards/QuickSelect.cpp`; cp-algorithms `sequences/k-th` |
| Implemented | AVL tree | `data_structures/avl_tree.hpp` | `ch2/nonlineards/AVL.cpp` |
| Implemented | Implicit treap | `data_structures/implicit_treap.hpp` | cp-algorithms `treap` |
| Implemented | Randomized heap | `data_structures/randomized_heap.hpp` | cp-algorithms `randomized_heap` |
| Planned | Policy-based data / maps | | `ch2/nonlineards/pbds.cpp`, `map_set.cpp` (GCC-only / STL) |

### `ch2/ourown`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Disjoint-set union | `data_structures/disjoint_set.hpp` | `ch2/ourown/unionfind_ds.cpp` |
| Implemented | Fenwick tree | `src/data_structures/fenwick_tree/` (`classic`, `2d`, `range_update_point_query`, `range_update_range_query`, `count_inversions`, `frequency_counting`, `dynamic`) | `ch2/ourown/fenwicktree_ds.cpp` |
| Implemented | Segment tree | `data_structures/segment_tree.hpp` | `ch2/ourown/segmenttree_ds.cpp` |
| Implemented | Sqrt decomposition | `data_structures/sqrt_decomposition.hpp` | cp-algorithms `sqrt_decomposition` |
| Implemented | Sqrt tree (range min) | `data_structures/sqrt_tree.hpp` | cp-algorithms `sqrt-tree` |
| Implemented | Graph adjacency lists | `graphs/graph.hpp` | `ch2/ourown/graph_ds.cpp` |

## Chapter 3 — Problem Solving Paradigms

### `ch3/cs` (complete search)

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Generating combinations | `mathematics/combinations.hpp` | cp-algorithms `generating_combinations`; `ch3/cs/UVa12455.cpp` |
| Implemented | N-queens | `mathematics/n_queens.hpp` | `ch3/cs/UVa00750.cpp` (cpbook only) |

### `ch3/dnc` (divide and conquer)

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Binary search on a predicate | `searching/binary_search.hpp` | cp-algorithms `binary_search`; `ch3/dnc/` |
| Implemented | Ternary search | `searching/ternary_search.hpp` | cp-algorithms `ternary_search` |

### `ch3/greedy`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | One-machine scheduling (Smith) | `schedules/one_machine.hpp` | cp-algorithms `schedule_one_machine` |
| Implemented | Two-machine scheduling (Johnson) | `schedules/two_machines.hpp` | cp-algorithms `schedule_two_machines` |
| Implemented | Interval covering | `schedules/interval_cover.hpp` | `ch3/greedy/grass_UVa10382.cpp` |
| Implemented | Smallest-fit assignment | `schedules/smallest_fit.hpp` | `ch3/greedy/loowater_UVa11292.cpp` |
| Implemented | LPT load balancing | `schedules/lpt.hpp` | greedy multiprocessor scheduling |
| Implemented | Completion-duration (SPT) | `schedules/completion_duration.hpp` | cp-algorithms `schedule-with-completion-duration` |

### `ch3/dp`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Longest increasing subsequence | `dynamic_programming/longest_increasing_subsequence.hpp` | `ch3/dp/LIS.cpp`; cp-algorithms `longest_increasing_subsequence` |
| Implemented | Maximum subarray (Kadane) | `dynamic_programming/max_subarray.hpp` | `ch3/dp/Max1DRangeSum.cpp` |
| Implemented | Subset sum | `dynamic_programming/subset_sum.hpp` | cp-algorithms `knapsack` |
| Implemented | 0-1 knapsack | `dynamic_programming/knapsack_zero_one.hpp` | `ch3/dp/UVa10130.cpp`; cp-algorithms `knapsack` |
| Implemented | Unbounded knapsack | `dynamic_programming/knapsack_unbounded.hpp` | cp-algorithms `knapsack` |
| Implemented | Maximum average segment | `dynamic_programming/maximum_average_segment.hpp` | cp-algorithms `maximum_average_segment` |
| Implemented | Coin change (min coins) | `src/dynamic_programming/coin_change_min/` | `ch3/dp/UVa00674.cpp` |
| Implemented | Coin change (ways) | `dynamic_programming/coin_change_ways.hpp` | `ch3/dp/UVa00674.cpp` |
| Implemented | Cutting sticks | `dynamic_programming/cutting_sticks.hpp` | `ch3/dp/UVa10003.cpp` |
| Implemented | TSP (bitmask) | `dynamic_programming/travelling_salesman.hpp` | `ch3/dp/beepers_UVa10496.cpp` |

## Chapter 4 — Graph

### `ch4/traversal`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | DFS | `graphs/dfs.hpp` | `ch4/traversal/dfs_cc.cpp`; cp-algorithms `depth-first-search` |
| Implemented | Connected components | `graphs/connected_components.hpp` | cp-algorithms `search-for-connected-components` |
| Implemented | BFS distances | `graphs/bfs.hpp` | `ch4/sssp/bfs.cpp`; cp-algorithms `breadth-first-search` |
| Implemented | Topological sort | `graphs/topological_sort.hpp` | `ch4/traversal/toposort.cpp`; cp-algorithms `topological-sort` |
| Implemented | Bipartite check | `graphs/bipartite.hpp` | `ch4/traversal/UVa10004.cpp`; cp-algorithms `bipartite-check` |
| Implemented | Cycle detection | `graphs/cycle.hpp` | `ch4/traversal/cyclecheck.cpp`; cp-algorithms `finding-cycle` |
| Implemented | Bridges and cut points | `graphs/bridges.hpp` | `ch4/traversal/articulation.cpp`; cp-algorithms `bridge-searching`, `cutpoints` |
| Implemented | Strong orientation | `graphs/strong_orientation.hpp` | cp-algorithms `strong-orientation` |
| Implemented | Strongly connected components | `graphs/scc.hpp` | `ch4/traversal/UVa11838.cpp`; cp-algorithms `strongly-connected-components` |
| Planned | Online bridges | | cp-algorithms `bridge-searching-online` |

### `ch4/sssp`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Dijkstra | `graphs/dijkstra.hpp` | `ch4/sssp/dijkstra.cpp`; cp-algorithms `dijkstra`, `dijkstra_sparse` |
| Implemented | Bellman-Ford / negative cycles | `graphs/bellman_ford.hpp` | `ch4/sssp/bellman_ford.cpp`; cp-algorithms `bellman_ford`, `finding-negative-cycle-in-graph` |
| Implemented | 0-1 BFS | `graphs/zero_one_bfs.hpp` | cp-algorithms `01_bfs` |
| Implemented | D'Esopo-Pape | `graphs/desopo_pape.hpp` | `ch4/sssp/bellman_ford_moore.cpp`; cp-algorithms `desopo_pape` |

### `ch4/mst`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Kruskal | `graphs/kruskal.hpp` | `ch4/mst/kruskal.cpp`; cp-algorithms `mst_kruskal`, `mst_kruskal_with_dsu` |
| Implemented | Prim | `graphs/prim.hpp` | `ch4/mst/prim.cpp`; cp-algorithms `mst_prim` |
| Implemented | Second-best MST | `graphs/second_best_mst.hpp` | cp-algorithms `second_best_mst` |
| Implemented | Kirchhoff spanning-tree count | `graphs/kirchhoff.hpp` | cp-algorithms `kirchhoff-theorem` |
| Implemented | Prüfer code | `graphs/prufer.hpp` | cp-algorithms `pruefer_code` |

### `ch4/mcbm` and other graph sections

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Kuhn bipartite matching | `graphs/kuhn.hpp` | `ch4/mcbm.cpp`; cp-algorithms `kuhn_maximum_bipartite_matching` |
| Implemented | Hungarian assignment | `graphs/hungarian.hpp` | cp-algorithms `hungarian-algorithm` |
| Implemented | Fixed-length walks | `graphs/walks.hpp` | cp-algorithms `fixed_length_paths` |
| Implemented | Floyd-Warshall | `graphs/floyd_warshall.hpp` | `ch4/floyd_warshall.cpp`; cp-algorithms `all-pair-shortest-path-floyd-warshall` |
| Implemented | Hierholzer / Euler path | `graphs/euler_path.hpp` | `ch4/hierholzer.cpp`; cp-algorithms `euler_path` |

## Chapter 5 — Mathematics

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | GCD, LCM | `mathematics/gcd.hpp` | Euclidean algorithm |
| Implemented | Extended Euclid | `mathematics/extended_gcd.hpp` | `ch5/modInverse.cpp` |
| Implemented | Linear Diophantine equation | `mathematics/linear_diophantine.hpp` | `ch5/modInverse.cpp` |
| Implemented | Binary exponentiation | `mathematics/binary_exponentiation.hpp` | cp-algorithms binary exponentiation |
| Implemented | Modular inverse | `mathematics/modular_inverse.hpp` | `ch5/modInverse.cpp` |
| Implemented | Fermat | `mathematics/fermat.hpp` | `ch5/UVa01230.cpp` |
| Implemented | Euler totient / Euler theorem | `mathematics/euler_phi.hpp`, `mathematics/euler_theorem.hpp` | Euler from number theory |
| Implemented | Carmichael | `mathematics/carmichael.hpp`, `mathematics/carmichael_theorem.hpp` | Carmichael from number theory |
| Implemented | Sieve | `mathematics/sieve.hpp` | `ch5/primes.cpp`; cp-algorithms primality |
| Implemented | Miller-Rabin | `mathematics/miller_rabin.hpp` | `miller_rabin` |
| Implemented | Pollard Rho / factorization | `mathematics/factorize.hpp` | `pollard_rho` |
| Implemented | Fibonacci via binary doubling | `mathematics/fibonacci.hpp` | `ch5/UVa10229.cpp`; cp-algorithms Fibonacci numbers |
| Implemented | Factorial prime exponents | `mathematics/factorial_exponents.hpp` | `ch5/factovisors_UVa10139.cpp`; cp-algorithms `factorial-divisors` |
| Implemented | Binomial coefficients | `mathematics/binomial.hpp` | `ch5/combinatorics.cpp`; cp-algorithms `binomial-coefficients` |
| Implemented | Catalan numbers | `mathematics/catalan.hpp` | cp-algorithms `catalan-numbers` |
| Implemented | Stars and bars | `mathematics/stars_and_bars.hpp` | cp-algorithms `stars_and_bars` |
| Implemented | Inclusion-exclusion | `mathematics/inclusion_exclusion.hpp` | cp-algorithms `inclusion-exclusion` |
| Implemented | Burnside | `mathematics/burnside.hpp` | cp-algorithms `burnside` |
| Implemented | Stern-Brocot | `mathematics/stern_brocot.hpp` | cp-algorithms `stern_brocot_tree_farey_sequences` |
| Implemented | Farey sequences | `mathematics/farey.hpp` | cp-algorithms `stern_brocot_tree_farey_sequences` |

## Chapter 6 — String Processing

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Trie | `data_structures/trie.hpp` | `ch6/Trie.cpp` |
| Implemented | Prefix function | `strings/prefix_function.hpp` | cp-algorithms `prefix-function` |
| Implemented | KMP | `strings/kmp.hpp` | `ch6/string_matching.cpp` |
| Implemented | String hashing | `strings/string_hash.hpp` | cp-algorithms `string-hashing` |
| Implemented | Rabin-Karp | `strings/rabin_karp.hpp` | cp-algorithms `rabin-karp` |
| Implemented | Z-function | `strings/z_function.hpp` | cp-algorithms `z-function` |
| Implemented | Suffix array | `strings/suffix_array.hpp` | `ch6/sa_lcp.cpp`; cp-algorithms `suffix-array` |
| Implemented | LCP (Kasai) | `strings/lcp.hpp` | cp-algorithms `suffix-array` |
| Implemented | Aho-Corasick | `strings/aho_corasick.hpp` | cp-algorithms `aho_corasick` |
| Implemented | Edit distance / alignment | `strings/edit_distance.hpp` | `ch6/string_alignment.cpp` (cpbook only) |
| Implemented | Lyndon factorization | `strings/lyndon.hpp` | cp-algorithms `lyndon_factorization` |
| Implemented | Suffix automaton | `strings/suffix_automaton.hpp` | cp-algorithms `suffix-automaton` |
| Implemented | Suffix tree (compressed trie) | `strings/suffix_tree.hpp` | cp-algorithms `suffix-tree-ukkonen` (structure; O(n²) insert) |

## Chapter 7 — Computational Geometry

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Points, orientation, distance | `geometry/point.hpp` | `ch7/points_lines.cpp` |
| Implemented | Polygon area | `geometry/polygon_area.hpp` | `ch7/polygon.cpp` |
| Implemented | Triangle area / circumradius | `geometry/triangle.hpp` | `ch7/triangles.cpp` |
| Implemented | Circle intersection area | `geometry/circle_intersection.hpp` | `ch7/circles.cpp` |
| Implemented | Convex hull | `geometry/convex_hull.hpp` | convex hull (Andrew monotone chain) |

## Chapter 8 — More Advanced Topics

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Maximum flow (Dinic) | `graphs/dinic.hpp` | `ch8/maxflow.cpp`; cp-algorithms `dinic` |
| Implemented | Edmonds-Karp | `graphs/edmonds_karp.hpp` | cp-algorithms `edmonds_karp` |
| Implemented | Push-relabel | `graphs/push_relabel.hpp` | cp-algorithms `push-relabel` |
| Implemented | Min-cost max-flow | `graphs/min_cost_flow.hpp` | `ch9/mcmf.cpp`; cp-algorithms `min_cost_flow`, `Assignment-problem-min-flow` |
| Implemented | Circulation with demands | `graphs/circulation.hpp` | cp-algorithms `flow_with_demands` |
| Implemented | 2-SAT | `graphs/two_sat.hpp` | cp-algorithms `2SAT` |
| Implemented | Stoer-Wagner min-cut | `graphs/stoer_wagner.hpp` | cp-algorithms `stoer_wagner_mincut` |
| Implemented | Edge connectivity | `graphs/edge_connectivity.hpp` | cp-algorithms `edge_vertex_connectivity` |
| Implemented | Tree distance reroot | `graphs/tree_distance.hpp` | cp-algorithms `tree_painting` |
| Implemented | Tree coloring | `graphs/tree_coloring.hpp` | cp-algorithms `tree_painting` |
| Planned | Push-relabel (HLPP), MPM | | cp-algorithms `push-relabel-faster`, `mpm` |

## Chapter 9 — Rare / Unused in Programming Contests

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Sparse table / RMQ | `data_structures/sparse_table.hpp` | `ch9/SparseTable.cpp`; cp-algorithms `sparse-table`, `sequences/rmq` |
| Implemented | LCA (binary lifting) | `graphs/lca.hpp` | `ch9/LCA.cpp`; cp-algorithms `lca`, `lca_binary_lifting` |
| Implemented | LCA (Tarjan offline) | `graphs/tarjan_lca.hpp` | cp-algorithms `lca_tarjan` |
| Implemented | Heavy-light decomposition | `graphs/hld.hpp` | `ch9/HLD.cpp`; cp-algorithms `hld` |
| Implemented | Centroid decomposition | `graphs/centroid.hpp` | cp-algorithms `centroid_decomposition` |
| Implemented | Gaussian elimination | `mathematics/gaussian_elimination.hpp` | `ch9/GaussianElimination.cpp`; cp-algorithms `linear-system-gauss` |
| Implemented | Determinant (Gauss) | `mathematics/determinant.hpp` | cp-algorithms `determinant-gauss` |
| Implemented | Matrix rank | `mathematics/matrix_rank.hpp` | cp-algorithms `rank-matrix` |
| Implemented | Linear system | `mathematics/solve_linear_system.hpp` | cp-algorithms `linear-system-gauss` |
| Implemented | Crout determinant | `mathematics/crout.hpp` | cp-algorithms `determinant-kraut` |
| Implemented | Newton | `searching/newton.hpp` | cp-algorithms `roots_newton` |
| Implemented | Simpson | `searching/simpson.hpp` | cp-algorithms `simpson-integration` |
| Implemented | Simulated annealing | `searching/simulated_annealing.hpp` | cp-algorithms `simulated_annealing` |
| Implemented | Mex | `others/mex.hpp` | cp-algorithms `sequences/mex` |
| Implemented | Tortoise and hare | `others/floyd_cycle.hpp` | cp-algorithms `tortoise_and_hare` |
| Implemented | Josephus | `others/josephus.hpp` | cp-algorithms `josephus_problem` |
| Implemented | 15-puzzle solvability | `others/fifteen_puzzle.hpp` | `ch9/UVa10181.cpp`; cp-algorithms `15-puzzle` |
| Planned | LCA Farach-Colton-Bender, RMQ linear | | cp-algorithms `lca_farachcoltonbender`, `rmq_linear` |

Every new migrated entry should keep an exercise folder under `src/`, a matching stub, sample
I/O, and a row in this catalog. Unmigrated entries still keep a header, a matching `*_test.cpp`,
documented complexity in the file comment, and a row in this catalog.
