# Practice Catalog

Entries follow the chapter and section layout of
[cpbook-code](https://github.com/stevenhalim/cpbook-code) (Competitive Programming 4). Topics that
exist only in [cp-algorithms](https://github.com/cp-algorithms/cp-algorithms) are placed in the
nearest CP4 section rather than in the website's own category tree.

The **Source** column names the closest `cpbook-code` file and/or cp-algorithms page. Judge-only
`UVa*.cpp` programs are listed when they introduce a reusable technique; their I/O parsers stay out
of the library.

Topics are exercise folders under `src/`. Related techniques live as siblings in the same folder.

## Chapter 2 — Data Structures and Libraries

### `ch2/lineards`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Min-stack | `src/data_structures/min_stack/` | cp-algorithms `stack_queue_modification` |
| Implemented | Min-queue | `src/data_structures/min_queue/` | cp-algorithms `stack_queue_modification` |
| Implemented | Bit manipulation | `src/data_structures/bit_manipulation/` | `ch2/lineards/bit_manipulation.cpp` |
| Implemented | Next same popcount | `src/data_structures/next_same_popcount/` | Gosper's hack |
| Implemented | Subsets of a mask | `src/data_structures/bit_subsets/` | bitmask subset enumeration |
| Planned | Array algorithms / lists | | `ch2/lineards/array_algorithms.cpp`, `list.cpp` (STL wrappers; not a library API) |

### `ch2/nonlineards`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Quick select / k-th | `src/searching/quick_select/` | `ch2/nonlineards/QuickSelect.cpp`; cp-algorithms `sequences/k-th` |
| Implemented | AVL tree | `src/data_structures/avl_tree/` | `ch2/nonlineards/AVL.cpp` |
| Implemented | Implicit treap | `src/data_structures/implicit_treap/` (`classic`, `reverse`, `cut_paste`) | cp-algorithms `treap` |
| Implemented | Randomized heap | `src/data_structures/randomized_heap/` | cp-algorithms `randomized_heap` |
| Planned | Policy-based data / maps | | `ch2/nonlineards/pbds.cpp`, `map_set.cpp` (GCC-only / STL) |

### `ch2/ourown`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Disjoint-set union | `src/data_structures/disjoint_set/` (`classic`, `painting`, `bipartite`, `rollback`) | `ch2/ourown/unionfind_ds.cpp` |
| Implemented | Fenwick tree | `src/data_structures/fenwick_tree/` (`classic`, `2d`, `range_update_point_query`, `range_update_range_query`, `count_inversions`, `frequency_counting`, `dynamic`) | `ch2/ourown/fenwicktree_ds.cpp` |
| Implemented | Segment tree | `src/data_structures/segment_tree/` (`classic`, `lazy`, `persistent`, `2d`, `kth`) | `ch2/ourown/segmenttree_ds.cpp` |
| Implemented | Sparse table | `src/data_structures/sparse_table/` (`classic`, `range_sum`) | cp-algorithms `sparse-table` |
| Implemented | Trie | `src/data_structures/trie/` (`classic`, `xor`) | cp-algorithms `string-trie` |
| Implemented | Sqrt decomposition | `src/data_structures/sqrt_decomposition/` (`classic`, `range_update`, `mo`) | cp-algorithms `sqrt_decomposition` |
| Implemented | Sqrt tree (range min) | `src/data_structures/sqrt_tree/` (`classic`, `point_update`, `range_assign`) | cp-algorithms `sqrt-tree` |

## Chapter 3 — Problem Solving Paradigms

### `ch3/cs` (complete search)

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Generating combinations | `src/mathematics/combinations/` | cp-algorithms `generating_combinations`; `ch3/cs/UVa12455.cpp` |
| Implemented | N-queens | `src/mathematics/n_queens/` | `ch3/cs/UVa00750.cpp` (cpbook only) |
| Implemented | Meet in the middle | `src/searching/meet_in_the_middle/` | Laaksonen §5.5 |

### `ch3/dnc` (divide and conquer)

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Binary search | `src/searching/binary_search/` (`classic`, `on_answer`) | cp-algorithms `binary_search`; `ch3/dnc/` |
| Implemented | Ternary search | `src/searching/ternary_search/` | cp-algorithms `ternary_search` |
| Implemented | Two pointers | `src/searching/two_pointers/` | Laaksonen §4.2 |
| Implemented | Nearest smaller | `src/searching/nearest_smaller/` | Laaksonen §4.3 |
| Implemented | Parallel binary search | `src/searching/parallel_binary_search/` | Laaksonen §13.1 |

### Sorting (Laaksonen §4)

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Merge sort | `src/sorting/merge_sort/` | Laaksonen §4.1.2 |
| Implemented | Counting sort | `src/sorting/counting_sort/classic/` | Laaksonen §4.1.4 |
| Implemented | Counting sort for strings | `src/sorting/counting_sort/strings/` | Laaksonen §4.1.4 (LSD radix) |

### `ch3/greedy`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | One-machine scheduling (Smith) | `src/schedules/one_machine/` | cp-algorithms `schedule_one_machine` |
| Implemented | Two-machine scheduling (Johnson) | `src/schedules/two_machines/` | cp-algorithms `schedule_two_machines` |
| Implemented | Interval covering | `src/schedules/interval_cover/` | `ch3/greedy/grass_UVa10382.cpp` |
| Implemented | Smallest-fit assignment | `src/schedules/smallest_fit/` | `ch3/greedy/loowater_UVa11292.cpp` |
| Implemented | LPT load balancing | `src/schedules/lpt/` | greedy multiprocessor scheduling |
| Implemented | Completion-duration (SPT) | `src/schedules/completion_duration/` | cp-algorithms `schedule-with-completion-duration` |

### `ch3/dp`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Longest increasing subsequence | `src/dynamic_programming/longest_increasing_subsequence/` | `ch3/dp/LIS.cpp`; cp-algorithms `longest_increasing_subsequence` |
| Implemented | Maximum subarray (Kadane) | `src/dynamic_programming/max_subarray/` | `ch3/dp/Max1DRangeSum.cpp` |
| Implemented | Subset sum | `src/dynamic_programming/subset_sum/` | cp-algorithms `knapsack` |
| Implemented | 0-1 knapsack | `src/dynamic_programming/knapsack_zero_one/` (`classic`, `value_dp`, `bounded`) | `ch3/dp/UVa10130.cpp`; cp-algorithms `knapsack` |
| Implemented | Unbounded knapsack | `src/dynamic_programming/knapsack_unbounded/` | cp-algorithms `knapsack` |
| Implemented | Maximum average segment | `src/dynamic_programming/maximum_average_segment/` | cp-algorithms `maximum_average_segment` |
| Implemented | Coin change (min coins) | `src/dynamic_programming/coin_change_min/` | `ch3/dp/UVa00674.cpp` |
| Implemented | Coin change (ways) | `src/dynamic_programming/coin_change_ways/` | `ch3/dp/UVa00674.cpp` |
| Implemented | Cutting sticks | `src/dynamic_programming/cutting_sticks/` | `ch3/dp/UVa10003.cpp` |
| Implemented | Grid paths | `src/dynamic_programming/grid_paths/` | Laaksonen §6.1 |
| Implemented | Convex hull trick | `src/dynamic_programming/convex_hull_trick/` | Laaksonen §7.5 |
| Implemented | Divide-and-conquer DP | `src/dynamic_programming/divide_conquer_dp/` | Laaksonen §7.5 |
| Implemented | Knuth optimization | `src/dynamic_programming/knuth_optimization/` | Laaksonen §7.5 |
| Implemented | TSP (bitmask) | `src/dynamic_programming/bitmask/travelling_salesman/` | `ch3/dp/beepers_UVa10496.cpp` |
| Implemented | Bitmask assignment | `src/dynamic_programming/bitmask/assignment/` | AtCoder DP Matching; subset DP |
| Implemented | Elevator rides (bitmask) | `src/dynamic_programming/bitmask/elevator_rides/` | Laaksonen §6.2.4 |
| Implemented | Hamiltonian paths (bitmask) | `src/dynamic_programming/bitmask/hamiltonian_path/` | Laaksonen §12.2.2 |
| Implemented | Grid tilings (profile DP) | `src/dynamic_programming/bitmask/counting_tilings/` | Laaksonen §6.2.5 |
| Implemented | SOS DP | `src/dynamic_programming/bitmask/sos/` | Laaksonen §15.5.2 |

## Chapter 4 — Graph

### `ch4/traversal`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | DFS | `src/graphs/dfs/` | `ch4/traversal/dfs_cc.cpp`; cp-algorithms `depth-first-search` |
| Implemented | Connected components | `src/graphs/connected_components/` | cp-algorithms `search-for-connected-components` |
| Implemented | BFS distances | `src/graphs/bfs/` | `ch4/sssp/bfs.cpp`; cp-algorithms `breadth-first-search` |
| Implemented | Topological sort | `src/graphs/topological_sort/` | `ch4/traversal/toposort.cpp`; cp-algorithms `topological-sort` |
| Implemented | Bipartite check | `src/graphs/bipartite/` | `ch4/traversal/UVa10004.cpp`; cp-algorithms `bipartite-check` |
| Implemented | Cycle detection | `src/graphs/cycle/` | `ch4/traversal/cyclecheck.cpp`; cp-algorithms `finding-cycle` |
| Implemented | Bridges and cut points | `src/graphs/bridges/` (`classic`, `cut_points`) | `ch4/traversal/articulation.cpp`; cp-algorithms `bridge-searching`, `cutpoints` |
| Implemented | Strong orientation | `src/graphs/strong_orientation/` | cp-algorithms `strong-orientation` |
| Implemented | Strongly connected components | `src/graphs/scc/` | `ch4/traversal/UVa11838.cpp`; cp-algorithms `strongly-connected-components` |
| Implemented | Longest path in a DAG | `src/graphs/dag_longest_path/` | Laaksonen §6.3 |
| Implemented | k-th successor | `src/graphs/kth_successor/` | Laaksonen §14.2 |
| Implemented | DSU on tree | `src/graphs/dsu_on_tree/` | sack / DSU on tree |
| Planned | Online bridges | | cp-algorithms `bridge-searching-online` |

### `ch4/sssp`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Dijkstra | `src/graphs/dijkstra/` | `ch4/sssp/dijkstra.cpp`; cp-algorithms `dijkstra`, `dijkstra_sparse` |
| Implemented | Bellman-Ford / negative cycles | `src/graphs/bellman_ford/` (`classic`, `negative_cycle`) | `ch4/sssp/bellman_ford.cpp`; cp-algorithms `bellman_ford`, `finding-negative-cycle-in-graph` |
| Implemented | 0-1 BFS | `src/graphs/zero_one_bfs/` | cp-algorithms `01_bfs` |
| Implemented | D'Esopo-Pape | `src/graphs/desopo_pape/` | `ch4/sssp/bellman_ford_moore.cpp`; cp-algorithms `desopo_pape` |

### `ch4/mst`

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Kruskal | `src/graphs/kruskal/` | `ch4/mst/kruskal.cpp`; cp-algorithms `mst_kruskal`, `mst_kruskal_with_dsu` |
| Implemented | Prim | `src/graphs/prim/` | `ch4/mst/prim.cpp`; cp-algorithms `mst_prim` |
| Implemented | Second-best MST | `src/graphs/second_best_mst/` | cp-algorithms `second_best_mst` |
| Implemented | Kirchhoff spanning-tree count | `src/graphs/kirchhoff/` | cp-algorithms `kirchhoff-theorem` |
| Implemented | Prüfer code | `src/graphs/prufer/` | cp-algorithms `pruefer_code` |

### `ch4/mcbm` and other graph sections

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Kuhn bipartite matching | `src/graphs/kuhn/` | `ch4/mcbm.cpp`; cp-algorithms `kuhn_maximum_bipartite_matching` |
| Implemented | Hungarian assignment | `src/graphs/hungarian/` | cp-algorithms `hungarian-algorithm` |
| Implemented | Fixed-length walks | `src/graphs/walks/` | cp-algorithms `fixed_length_paths` |
| Implemented | Floyd-Warshall | `src/graphs/floyd_warshall/` | `ch4/floyd_warshall.cpp`; cp-algorithms `all-pair-shortest-path-floyd-warshall` |
| Implemented | Hierholzer / Euler path | `src/graphs/euler_path/` | `ch4/hierholzer.cpp`; cp-algorithms `euler_path` |
| Implemented | Disjoint paths | `src/graphs/disjoint_paths/` | Laaksonen §11.3 |
| Implemented | Minimum path cover | `src/graphs/path_cover/` | Laaksonen §11.3 |

## Chapter 5 — Mathematics

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | GCD, LCM | `src/mathematics/gcd/` | Euclidean algorithm |
| Implemented | Extended Euclid | `src/mathematics/extended_gcd/` | `ch5/modInverse.cpp` |
| Implemented | Linear Diophantine equation | `src/mathematics/linear_diophantine/` | `ch5/modInverse.cpp` |
| Implemented | Binary exponentiation | `src/mathematics/binary_exponentiation/` | cp-algorithms binary exponentiation |
| Implemented | Modular inverse | `src/mathematics/modular_inverse/` | `ch5/modInverse.cpp` |
| Implemented | Fermat | `src/mathematics/fermat/` | `ch5/UVa01230.cpp` |
| Implemented | Euler totient | `src/mathematics/euler_phi/` | Euler from number theory |
| Implemented | Euler theorem | `src/mathematics/euler_theorem/` | Euler from number theory |
| Implemented | Carmichael | `src/mathematics/carmichael/` | Carmichael from number theory |
| Implemented | Carmichael theorem | `src/mathematics/carmichael_theorem/` | Carmichael from number theory |
| Implemented | Sieve | `src/mathematics/sieve/` | `ch5/primes.cpp`; cp-algorithms primality |
| Implemented | Miller-Rabin | `src/mathematics/miller_rabin/` | `miller_rabin` |
| Implemented | Pollard Rho / factorization | `src/mathematics/factorize/` | `pollard_rho` |
| Implemented | Fibonacci via binary doubling | `src/mathematics/fibonacci/` | `ch5/UVa10229.cpp`; cp-algorithms Fibonacci numbers |
| Implemented | Factorial prime exponents | `src/mathematics/factorial_exponents/` | `ch5/factovisors_UVa10139.cpp`; cp-algorithms `factorial-divisors` |
| Implemented | Binomial coefficients | `src/mathematics/binomial/` | `ch5/combinatorics.cpp`; cp-algorithms `binomial-coefficients` |
| Implemented | Catalan numbers | `src/mathematics/catalan/` | cp-algorithms `catalan-numbers` |
| Implemented | Stars and bars | `src/mathematics/stars_and_bars/` | cp-algorithms `stars_and_bars` |
| Implemented | Inclusion-exclusion | `src/mathematics/inclusion_exclusion/` | cp-algorithms `inclusion-exclusion` |
| Implemented | Burnside | `src/mathematics/burnside/` | cp-algorithms `burnside` |
| Implemented | Stern-Brocot | `src/mathematics/stern_brocot/` | cp-algorithms `stern_brocot_tree_farey_sequences` |
| Implemented | Farey sequences | `src/mathematics/farey/` | cp-algorithms `stern_brocot_tree_farey_sequences` |
| Implemented | Nim | `src/mathematics/nim/` | Laaksonen §9.1 |
| Implemented | Sprague-Grundy | `src/mathematics/grundy/` | Laaksonen §9.2 |
| Implemented | Matrix exponentiation | `src/mathematics/matrix_exponentiation/` | Laaksonen §14.3 |
| Implemented | Expected value | `src/mathematics/expected_value/` | Laaksonen §8.2 |
| Implemented | Bit-parallel Hamming | `src/mathematics/bit_parallel/hamming/` | Laaksonen §15.4 |
| Implemented | Bit-parallel reachability | `src/mathematics/bit_parallel/reachability/` | Laaksonen §15.4 |

## Chapter 6 — String Processing

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Trie | `src/data_structures/trie/` (`classic`, `xor`) | `ch6/Trie.cpp` |
| Implemented | Prefix function | `src/strings/prefix_function/` (`classic`, `prefix_count`) | cp-algorithms `prefix-function` |
| Implemented | KMP | `src/strings/kmp/` | `ch6/string_matching.cpp` |
| Implemented | String hashing | `src/strings/string_hash/` | cp-algorithms `string-hashing` |
| Implemented | Rabin-Karp | `src/strings/rabin_karp/` | cp-algorithms `rabin-karp` |
| Implemented | Z-function | `src/strings/z_function/` | cp-algorithms `z-function` |
| Implemented | Suffix array | `src/strings/suffix_array/` | `ch6/sa_lcp.cpp`; cp-algorithms `suffix-array` |
| Implemented | LCP (Kasai) | `src/strings/lcp/` | cp-algorithms `suffix-array` |
| Implemented | Aho-Corasick | `src/strings/aho_corasick/` | cp-algorithms `aho_corasick` |
| Implemented | Edit distance / alignment | `src/strings/edit_distance/` | `ch6/string_alignment.cpp` (cpbook only) |
| Implemented | Lyndon factorization | `src/strings/lyndon/` | cp-algorithms `lyndon_factorization` |
| Implemented | Suffix automaton | `src/strings/suffix_automaton/` | cp-algorithms `suffix-automaton` |
| Implemented | Suffix tree (compressed trie) | `src/strings/suffix_tree/` | cp-algorithms `suffix-tree-ukkonen` (structure; O(n²) insert) |

## Chapter 7 — Computational Geometry

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Points, orientation, distance | `src/geometry/point/` | `ch7/points_lines.cpp` |
| Implemented | Polygon area | `src/geometry/polygon_area/` | `ch7/polygon.cpp` |
| Implemented | Triangle area / circumradius | `src/geometry/triangle/` | `ch7/triangles.cpp` |
| Implemented | Circle intersection area | `src/geometry/circle_intersection/` | `ch7/circles.cpp` |
| Implemented | Convex hull | `src/geometry/convex_hull/` | convex hull (Andrew monotone chain) |
| Implemented | Closest pair | `src/geometry/closest_pair/` | Laaksonen §13.2 |
| Implemented | Sweep line | `src/geometry/sweep_line/` | Laaksonen §13.2 |

## Chapter 8 — More Advanced Topics

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Maximum flow (Dinic) | `src/graphs/dinic/` | `ch8/maxflow.cpp`; cp-algorithms `dinic` |
| Implemented | Edmonds-Karp | `src/graphs/edmonds_karp/` | cp-algorithms `edmonds_karp` |
| Implemented | Push-relabel | `src/graphs/push_relabel/` | cp-algorithms `push-relabel` |
| Implemented | Min-cost max-flow | `src/graphs/min_cost_flow/` | `ch9/mcmf.cpp`; cp-algorithms `min_cost_flow`, `Assignment-problem-min-flow` |
| Implemented | Circulation with demands | `src/graphs/circulation/` | cp-algorithms `flow_with_demands` |
| Implemented | 2-SAT | `src/graphs/two_sat/` | cp-algorithms `2SAT` |
| Implemented | Stoer-Wagner min-cut | `src/graphs/stoer_wagner/` | cp-algorithms `stoer_wagner_mincut` |
| Implemented | Edge connectivity | `src/graphs/edge_connectivity/` | cp-algorithms `edge_vertex_connectivity` |
| Implemented | Tree distance reroot | `src/graphs/tree_distance/` | cp-algorithms `tree_painting` |
| Implemented | Tree coloring | `src/graphs/tree_coloring/` | cp-algorithms `tree_painting` |
| Planned | Push-relabel (HLPP), MPM | | cp-algorithms `push-relabel-faster`, `mpm` |

## Chapter 9 — Rare / Unused in Programming Contests

| Status | Topic | Header | Source |
|---|---|---|---|
| Implemented | Sparse table / RMQ | `src/data_structures/sparse_table/` (`classic`, `range_sum`) | `ch9/SparseTable.cpp`; cp-algorithms `sparse-table`, `sequences/rmq` |
| Implemented | LCA (binary lifting) | `src/graphs/lca/` | `ch9/LCA.cpp`; cp-algorithms `lca`, `lca_binary_lifting` |
| Implemented | LCA (Tarjan offline) | `src/graphs/tarjan_lca/` | cp-algorithms `lca_tarjan` |
| Implemented | Heavy-light decomposition | `src/graphs/hld/` | `ch9/HLD.cpp`; cp-algorithms `hld` |
| Implemented | Centroid decomposition | `src/graphs/centroid/` | cp-algorithms `centroid_decomposition` |
| Implemented | Gaussian elimination | `src/mathematics/gaussian_elimination/` | `ch9/GaussianElimination.cpp`; cp-algorithms `linear-system-gauss` |
| Implemented | Determinant (Gauss) | `src/mathematics/determinant/` | cp-algorithms `determinant-gauss` |
| Implemented | Matrix rank | `src/mathematics/matrix_rank/` | cp-algorithms `rank-matrix` |
| Implemented | Linear system | `src/mathematics/solve_linear_system/` | cp-algorithms `linear-system-gauss` |
| Implemented | Crout determinant | `src/mathematics/crout/` | cp-algorithms `determinant-kraut` |
| Implemented | Newton | `src/searching/newton/` | cp-algorithms `roots_newton` |
| Implemented | Simpson | `src/searching/simpson/` | cp-algorithms `simpson-integration` |
| Implemented | Simulated annealing | `src/searching/simulated_annealing/` | cp-algorithms `simulated_annealing` |
| Implemented | Mex | `src/others/mex/` | cp-algorithms `sequences/mex` |
| Implemented | Tortoise and hare | `src/others/floyd_cycle/` | cp-algorithms `tortoise_and_hare` |
| Implemented | Josephus | `src/others/josephus/` | cp-algorithms `josephus_problem` |
| Implemented | 15-puzzle solvability | `src/others/fifteen_puzzle/` | `ch9/UVa10181.cpp`; cp-algorithms `15-puzzle` |
| Planned | LCA Farach-Colton-Bender, RMQ linear | | cp-algorithms `lca_farachcoltonbender`, `rmq_linear` |

Every entry is an exercise folder under `src/` with a matching stub, sample I/O, and a
row in this catalog.
