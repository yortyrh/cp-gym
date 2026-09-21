# Remaining Exercises Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Migrate remaining catalog topics and add bitmask DP, Laaksonen book-gap techniques, and sorting (merge + counting, including strings) as judge-style exercises under `src/`.

**Architecture:** Copy the Fenwick/coin_change_min five-file layout. Register each stem with `cprepo_add_exercise` in `src/CMakeLists.txt`. Do not edit `src/CMakeLists.txt` from parallel agents; the coordinator appends registrations. Delete the matching `include/` header and Catch2 test after the solution checker is green.

**Tech Stack:** C++23, GNU g++, CMake presets, `scripts/check.sh`, contest prelude (`bits/stdc++.h`, `using namespace std`, `#define int long long`, `signed main()`).

## Global Constraints

- English statements and stub comments; original problems; no copied judge text
- Student writes FastIO; `cin`/`cout` only
- Sample 1 in `.md` is byte-for-byte `.in`/`.out` (Unix newlines, trailing newline)
- `int` after the macro is 64-bit; no `int64_t`/`long long` in exercise `.cpp`
- No `int main()`; no functional `int(expr)` casts
- Stub compiles and fails the sample diff until filled
- Do not commit unless the user asks
- Spec: `docs/superpowers/specs/2026-09-20-exercise-remaining-design.md`

## File layout reminder

Five files per folder. Stem examples: `merge_sort`, `counting_sort-classic`, `bitmask-assignment`.

---

### Task 1: Sorting

- [ ] `src/sorting/merge_sort/` — implement merge sort; forbid `std::sort`
- [ ] `src/sorting/counting_sort/classic/` — integers in `0..c`
- [ ] `src/sorting/counting_sort/strings/` — equal-length lowercase strings, stable counting / radix
- [ ] Register three stems in `src/CMakeLists.txt`
- [ ] `./scripts/check.sh … --solution` green; stub compiles and fails diff

### Task 2: Bitmask DP

- [ ] `assignment`, `elevator_rides`, `travelling_salesman`, `hamiltonian_path`, `counting_tilings`, `sos` under `src/dynamic_programming/bitmask/`
- [ ] Delete `include/cprepo/dynamic_programming/travelling_salesman.hpp` and `tests/dynamic_programming/travelling_salesman_test.cpp`
- [ ] Register stems; solution checker green

### Task 3+: Remaining DS splits, knapsack extras, book gaps, 1-classic headers

Follow the spec tables. One implementer batch at a time. Coordinator owns `src/CMakeLists.txt` and `docs/catalog.md`.
