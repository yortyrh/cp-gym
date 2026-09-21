# Remaining Exercise Catalog Design

Date: 2026-09-20

Migrate every remaining catalog topic from `include/cprepo/**/*.hpp` + Catch2 into judge-style exercises under `src/`, using the locked pilot format. Add extra technique folders from search (Fenwick-style) and from *Guide to Competitive Programming* (Laaksonen) where the catalog had no header.

## Goal

A student can train each remaining technique the same way as Fenwick: English statement, Coddy-style stub, `./scripts/check.sh src/...`.

## Non-goals

- Do not copy CSES/Kattis/UVa/AtCoder statement text. Original problems.
- Do not add `graph.hpp` as an exercise (types only).
- Do not duplicate a sibling header (Kruskal vs DSU classic, KMP vs prefix-function search, LCA vs Tarjan, coin_change_min already migrated).
- Do not implement bubble sort (inversions already Fenwick). Do not reimplement `std::sort`.
- Do not commit PDFs (`guide-t-cp.pdf`, `cp4-*.pdf`, `handbook.pdf`).

## Locked format (same as pilot)

Contest prelude, `signed main()`, FastIO written by the student, `cin`/`cout` only, English `.md` and stub comments, five files per folder, `scripts/check.sh`, CMake `cprepo_add_exercise`. Delete the matching header and Catch2 test when a topic migrates.

Multi-technique topic: `src/<domain>/<topic>/<technique>/` with stem `<topic>-<technique>`.
Single algorithm: `src/<domain>/<topic>/` with stem `<topic>` (like `coin_change_min`).

## Already migrated (do not recreate)

Fenwick (7) + `coin_change_min`.

## Extra splits (search + book)

### Data structures

| Topic | Folders |
|---|---|
| `segment_tree` | `classic`, `lazy`, `persistent`, `2d`, `kth` |
| `disjoint_set` | `classic`, `painting`, `bipartite`, `rollback` |
| `sparse_table` | `classic`, `range_sum` |
| `trie` | `classic`, `xor` |
| `sqrt_tree` | `classic`, `point_update`, `range_assign` |
| `sqrt_decomposition` | `classic`, `range_update`, `mo` |
| `implicit_treap` | `classic`, `reverse`, `cut_paste` |
| 1 classic each | `avl_tree`, `min_stack`, `min_queue`, `randomized_heap`, `bit_manipulation`, `bit_subsets`, `next_same_popcount` |

### Algorithms already in catalog (extra folders)

| Topic | Folders |
|---|---|
| `knapsack_zero_one` | `classic`, `value_dp`, `bounded` |
| `binary_search` | `classic`, `on_answer` |
| `bellman_ford` | `classic`, `negative_cycle` |
| `bridges` | `classic`, `cut_points` |
| `prefix_function` | `classic`, `prefix_count` |
| `sieve` | `classic` only (SPF stays `factorize`) |

### Bitmask DP (new family)

`src/dynamic_programming/bitmask/`: `assignment`, `elevator_rides`, `travelling_salesman`, `hamiltonian_path`, `counting_tilings`, `sos`.

Migrate `travelling_salesman.hpp` into `bitmask/travelling_salesman`.

### Sorting (Laaksonen §4, no prior headers)

| Folder | Stem |
|---|---|
| `src/sorting/merge_sort/` | `merge_sort` |
| `src/sorting/counting_sort/classic/` | `counting_sort-classic` |
| `src/sorting/counting_sort/strings/` | `counting_sort-strings` |

### Book gaps (Laaksonen, no header)

`two_pointers`, `nearest_smaller`, `grid_paths`, `dag_longest_path`, `kth_successor`, `nim`, `grundy`, `matrix_exponentiation`, `meet_in_the_middle`, `convex_hull_trick`, `divide_conquer_dp`, `knuth_optimization`, `closest_pair`, `sweep_line`, `disjoint_paths`, `path_cover`, `parallel_binary_search`, `expected_value`, `bit_parallel/hamming`, `bit_parallel/reachability`, `dsu_on_tree`.

### Remaining headers

One classic exercise each (graphs, DP leftover, math, strings, geometry, searching leftover, schedules, others). Skip `graph.hpp`.

## Delete rule

When an exercise set for a header is registered and the solution checker is green, delete `include/cprepo/<path>.hpp` and `tests/<path>_test.cpp`.
