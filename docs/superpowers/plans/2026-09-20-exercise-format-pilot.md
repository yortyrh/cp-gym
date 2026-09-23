# Exercise-Format Pilot Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Replace Fenwick-tree and minimum-coin-change header practice with eight judge-style exercises under `src/`, checked by `scripts/check.sh` through CMake.

**Architecture:** Each exercise is a folder with statement, contest-style stub, reference solution, and sample `.in`/`.out`. Root CMake finds GNU g++ and `add_subdirectory(src)`. `src/CMakeLists.txt` builds `<stem>-student` and `<stem>-solution` into `build/dev/exercises/`. `scripts/check.sh` configures preset `dev` if needed, builds one target, runs it on the sample, and `diff -u`s the output.

**Tech Stack:** CMake 3.25, Ninja, GNU g++ / C++23, Catch2 (unchanged for unmigrated topics), bash `diff`.

## Global Constraints

- Spec: `docs/superpowers/specs/2026-09-20-exercise-format-pilot-design.md`
- Exercises live only under `src/`. Never at repo root. Never under `include/`.
- Every exercise `.cpp` (stub and solution) starts with exactly:
  ```cpp
  #include<bits/stdc++.h>
  using namespace std;
  #define int long long
  ```
- Entry point is `signed main()`. Never `int main()`.
- After the macro, use `int` for 64-bit values. Do not use `int64_t` or `long long` in exercise files.
- FastIO uses `cin`/`cout` only. Student writes FastIO. Reference uses the `FastIO` struct from the spec.
- Fenwick is 1-based. Fenwick ranges are inclusive `[l, r]`.
- Coin-change arrays are 0-based. Impossible answer is `-1`.
- English statements and stub comments. Original problems; do not copy CSES/Kattis/UVa text.
- Sample 1 in the `.md` is byte-for-byte the `.in`/`.out` pair (UTF-8, Unix newlines, trailing newline).
- Student command never sets `CXX=`. CMake finds `g++-15`, `g++-14`, `g++-13`, `g++-12`, then `g++` before `project()` if `CMAKE_CXX_COMPILER` and `ENV{CXX}` are unset.
- Exercise targets do not link `cprepo::cprepo`. Flags: `cxx_std_23`, `-O2`, `-Wall -Wextra -Wpedantic -Wconversion -Wshadow`, `-Werror` when `CPREPO_WARNINGS_AS_ERRORS`, sanitizers when `CPREPO_ENABLE_SANITIZERS`.
- Binaries go to `${CMAKE_BINARY_DIR}/exercises/`.
- Delete only Fenwick and `coin_change_min` headers/tests. Leave every other header and Catch2 test.
- Git: this repo currently has spec commits only; `include/`, `tests/`, and `CMakeLists.txt` may still be untracked. Never `git add include/` or `git add tests/` wholesale. Commit only files the current task creates or modifies.
- Do not use `bits/stdc++.h` or `#define int` in remaining `include/cprepo/` headers.

---

### Task 1: Checker script and CMake exercise harness

**Files:**
- Create: `scripts/check.sh`
- Create: `src/CMakeLists.txt`
- Modify: `CMakeLists.txt` (compiler discovery before `project()`, `add_subdirectory(src)`)

**Interfaces:**
- Consumes: existing root `CMakeLists.txt` options `CPREPO_WARNINGS_AS_ERRORS`, `CPREPO_ENABLE_SANITIZERS`, `CPREPO_WARNING_FLAGS`.
- Produces: `cprepo_add_exercise(<relative-dir-under-src> <stem>)`; `scripts/check.sh <src/...> [--solution]` exit 0/1/2 as spec.

- [ ] **Step 1: Write `scripts/check.sh`**

```bash
#!/usr/bin/env bash
set -euo pipefail

usage() {
    echo "usage: $0 <src/path/to/exercise> [--solution]" >&2
    exit 2
}

if [[ $# -lt 1 || $# -gt 2 ]]; then
    usage
fi

dir_arg=""
use_solution=0
for arg in "$@"; do
    case "$arg" in
        --solution)
            use_solution=1
            ;;
        -*)
            usage
            ;;
        *)
            if [[ -n "$dir_arg" ]]; then
                usage
            fi
            dir_arg="$arg"
            ;;
    esac
done

if [[ -z "$dir_arg" ]]; then
    usage
fi

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$root"

if [[ "$dir_arg" = /* ]]; then
    exercise_dir="$dir_arg"
else
    exercise_dir="$root/$dir_arg"
fi

if [[ ! -d "$exercise_dir" ]]; then
    echo "error: not a directory: $dir_arg" >&2
    exit 2
fi

exercise_dir="$(cd "$exercise_dir" && pwd)"
rel="${exercise_dir#"$root"/}"
if [[ "$rel" != src/* ]]; then
    echo "error: exercise path must be under src/" >&2
    exit 2
fi

shopt -s nullglob
in_files=("$exercise_dir"/*.in)
shopt -u nullglob
if [[ ${#in_files[@]} -ne 1 ]]; then
    echo "error: expected exactly one .in in $rel" >&2
    exit 2
fi

in_file="${in_files[0]}"
stem="$(basename "$in_file" .in)"
out_file="$exercise_dir/$stem.out"
if [[ "$use_solution" -eq 1 ]]; then
    src_file="$exercise_dir/$stem.cpp"
    target="$stem-solution"
    bin="$root/build/dev/exercises/$stem-solution"
else
    src_file="$exercise_dir/$stem.student.cpp"
    target="$stem-student"
    bin="$root/build/dev/exercises/$stem-student"
fi

if [[ ! -f "$src_file" ]]; then
    echo "error: missing source: $src_file" >&2
    exit 2
fi
if [[ ! -f "$out_file" ]]; then
    echo "error: missing output file: $out_file" >&2
    exit 2
fi

if [[ ! -d "$root/build/dev" ]]; then
    cmake --preset dev
fi

cmake --build --preset dev --target "$target"

got="$(mktemp)"
trap 'rm -f "$got"' EXIT

set +e
"$bin" < "$in_file" > "$got"
status=$?
set -e
if [[ "$status" -ne 0 ]]; then
    echo "error: program exited with status $status" >&2
    exit 1
fi

if ! diff -u "$out_file" "$got"; then
    exit 1
fi

echo "OK"
```

Make it executable: `chmod +x scripts/check.sh`

- [ ] **Step 2: Run path-outside-src check (must fail with exit 2)**

Run from repo root:

```sh
chmod +x scripts/check.sh
./scripts/check.sh include/cprepo/data_structures; echo "exit=$?"
```

Expected: `error: exercise path must be under src/` (or `not a directory`) and `exit=2`.

- [ ] **Step 3: Patch root `CMakeLists.txt`**

Replace the top of `CMakeLists.txt` so compiler discovery happens before `project()`, then add `add_subdirectory(src)` after the sanitizer block and before `if(BUILD_TESTING)`.

Full file:

```cmake
cmake_minimum_required(VERSION 3.25)

if(NOT CMAKE_CXX_COMPILER AND NOT DEFINED ENV{CXX})
  find_program(CPREPO_GNU_CXX NAMES g++-15 g++-14 g++-13 g++-12 g++)
  if(CPREPO_GNU_CXX)
    set(CMAKE_CXX_COMPILER "${CPREPO_GNU_CXX}" CACHE FILEPATH "GNU C++ compiler")
  endif()
endif()

project(
  cprepo_practice
  VERSION 0.1.0
  DESCRIPTION "Competitive-programming data structures and algorithms for deliberate practice"
  LANGUAGES CXX
)

set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

option(CPREPO_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
option(CPREPO_ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

add_library(cprepo INTERFACE)
add_library(cprepo::cprepo ALIAS cprepo)

target_include_directories(
  cprepo
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(cprepo INTERFACE cxx_std_23)

set(CPREPO_WARNING_FLAGS -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
if(CPREPO_WARNINGS_AS_ERRORS)
  list(APPEND CPREPO_WARNING_FLAGS -Werror)
endif()
target_compile_options(
  cprepo
  INTERFACE
    $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:${CPREPO_WARNING_FLAGS}>
)

if(CPREPO_ENABLE_SANITIZERS)
  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    target_compile_options(cprepo INTERFACE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(cprepo INTERFACE -fsanitize=address,undefined -fno-omit-frame-pointer)
  else()
    message(FATAL_ERROR "CPREPO_ENABLE_SANITIZERS requires GCC or Clang")
  endif()
endif()

add_subdirectory(src)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
```

- [ ] **Step 4: Write `src/CMakeLists.txt`**

```cmake
function(cprepo_apply_exercise_flags target)
  target_compile_features(${target} PRIVATE cxx_std_23)
  target_compile_options(
    ${target}
    PRIVATE
      $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:${CPREPO_WARNING_FLAGS} -O2>
  )
  if(CPREPO_ENABLE_SANITIZERS)
    target_compile_options(${target} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(${target} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
  endif()
  set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/exercises")
endfunction()

function(cprepo_add_exercise relative_dir stem)
  set(dir "${CMAKE_CURRENT_SOURCE_DIR}/${relative_dir}")
  add_executable(${stem}-student "${dir}/${stem}.student.cpp")
  add_executable(${stem}-solution "${dir}/${stem}.cpp")
  cprepo_apply_exercise_flags(${stem}-student)
  cprepo_apply_exercise_flags(${stem}-solution)
  if(BUILD_TESTING)
    add_test(
      NAME ${stem}-solution
      COMMAND "${CMAKE_SOURCE_DIR}/scripts/check.sh" "src/${relative_dir}" --solution
      WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    )
  endif()
endfunction()
```

Do not call `cprepo_add_exercise` yet. Configure must succeed with an empty exercise list.

- [ ] **Step 5: Configure to verify CMake accepts `src/`**

```sh
cmake --preset dev
```

Expected: configure succeeds. GNU g++ chosen if `CXX` unset and `g++-*` exists. No exercise targets yet.

- [ ] **Step 6: Commit**

```bash
git add scripts/check.sh src/CMakeLists.txt CMakeLists.txt CMakePresets.json
git commit -m "$(cat <<'EOF'
feat: add exercise checker and CMake harness

Let CMake pick GNU g++ and give students a src/-only script that will compile and diff contest exercises.
EOF
)"
```

`CMakePresets.json` is untracked and required to run `--preset dev`. Include it in this commit if it is not already tracked. Do not add `include/` or `tests/`.

---

### Task 2: Fenwick classic (PURQ)

**Files:**
- Create: `src/data_structures/fenwick_tree/classic/fenwick_tree-classic.md`
- Create: `src/data_structures/fenwick_tree/classic/fenwick_tree-classic.student.cpp`
- Create: `src/data_structures/fenwick_tree/classic/fenwick_tree-classic.cpp`
- Create: `src/data_structures/fenwick_tree/classic/fenwick_tree-classic.in`
- Create: `src/data_structures/fenwick_tree/classic/fenwick_tree-classic.out`
- Modify: `src/CMakeLists.txt` (one `cprepo_add_exercise` call)

**Interfaces:**
- Consumes: `cprepo_add_exercise`, `scripts/check.sh`
- Produces: targets `fenwick_tree-classic-student` and `fenwick_tree-classic-solution`

- [ ] **Step 1: Write sample I/O**

`src/data_structures/fenwick_tree/classic/fenwick_tree-classic.in`:

```
5 3
2 -1 3 5 4
2 2 4
1 2 5
2 1 2
```

`src/data_structures/fenwick_tree/classic/fenwick_tree-classic.out`:

```
7
7
```

Both files must end with a newline. Values: `a = [2,-1,3,5,4]`. Query `2 2 4` is `-1+3+5=7`. Set `a[2]=5`. Query `2 1 2` is `2+5=7`.

- [ ] **Step 2: Write the stub**

`src/data_structures/fenwick_tree/classic/fenwick_tree-classic.student.cpp`:

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Fenwick tree (point update, range query) ===
// Implement a 1-based Fenwick tree (binary indexed tree).
// Index 0 is unused. tree[1] stores information about a[1].
// Required operations:
//   add(i, delta)   — point update at 1-based index i
//   prefix_sum(i)   — sum of a[1] + ... + a[i]
//   range_sum(l, r) — sum of a[l] + ... + a[r] = prefix_sum(r) - prefix_sum(l - 1)
// Do not rebuild prefix sums on every query. Do not use a segment tree for this exercise.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n] from stdin.
    // Build the Fenwick tree from the array.
    // For each query:
    //   type 1 i v  → point-update index i to value v
    //   type 2 l r  → print range_sum(l, r) followed by a newline
    // Write answers to stdout.
    return 0;
}
```

- [ ] **Step 3: Write the reference solution**

`src/data_structures/fenwick_tree/classic/fenwick_tree-classic.cpp`:

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};
static FastIO fastio;

struct Fenwick {
    int n;
    vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    int prefix_sum(int i) {
        int result = 0;
        for (; i > 0; i -= i & -i) {
            result += bit[i];
        }
        return result;
    }

    int range_sum(int l, int r) { return prefix_sum(r) - prefix_sum(l - 1); }
};

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    Fenwick tree(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        tree.add(i, a[i]);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, v;
            cin >> i >> v;
            tree.add(i, v - a[i]);
            a[i] = v;
        } else {
            int l, r;
            cin >> l >> r;
            cout << tree.range_sum(l, r) << '\n';
        }
    }
    return 0;
}
```

- [ ] **Step 4: Write the statement**

`src/data_structures/fenwick_tree/classic/fenwick_tree-classic.md`:

````markdown
# Dynamic Range Sum Queries

**Technique:** Fenwick tree (point update, range query)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. There are two kinds of queries:

- `1 i v` — set $a_i$ equal to $v$
- `2 l r` — print the sum $a_l + a_{l+1} + \cdots + a_r$

Indices are 1-based and ranges are inclusive.

A 1-based Fenwick tree (binary indexed tree) with point updates and prefix sums processes all queries in $O((n + q)\log n)$ time.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains one query. For type 1, $1 \le i \le n$ and $|v| \le 10^9$. For type 2, $1 \le l \le r \le n$.

## Output

For every query of type 2, print the range sum on its own line.

## Sample 1

Input:

```
5 3
2 -1 3 5 4
2 2 4
1 2 5
2 1 2
```

Output:

```
7
7
```

## Run

From the repository root, after writing `fenwick_tree-classic.student.cpp`:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/classic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/classic --solution
```
````

- [ ] **Step 5: Register the exercise**

Append to `src/CMakeLists.txt`:

```cmake
cprepo_add_exercise(data_structures/fenwick_tree/classic fenwick_tree-classic)
```

- [ ] **Step 6: Stub must compile and fail the diff**

```sh
./scripts/check.sh src/data_structures/fenwick_tree/classic; echo "exit=$?"
```

Expected: build of `fenwick_tree-classic-student` succeeds; `diff` fails; exit 1.

- [ ] **Step 7: Solution must print OK**

```sh
./scripts/check.sh src/data_structures/fenwick_tree/classic --solution
```

Expected: `OK` and exit 0.

- [ ] **Step 8: Commit**

```bash
git add src/data_structures/fenwick_tree/classic src/CMakeLists.txt
git commit -m "$(cat <<'EOF'
feat: add Fenwick classic range-sum exercise

Give students a 1-based point-update / range-query Fenwick problem with a guided stub and sample I/O.
EOF
)"
```

---

### Task 3: Fenwick 2D

**Files:**
- Create: `src/data_structures/fenwick_tree/2d/fenwick_tree-2d.md`
- Create: `src/data_structures/fenwick_tree/2d/fenwick_tree-2d.student.cpp`
- Create: `src/data_structures/fenwick_tree/2d/fenwick_tree-2d.cpp`
- Create: `src/data_structures/fenwick_tree/2d/fenwick_tree-2d.in`
- Create: `src/data_structures/fenwick_tree/2d/fenwick_tree-2d.out`
- Modify: `src/CMakeLists.txt`

**Interfaces:**
- Consumes: `cprepo_add_exercise`, `scripts/check.sh`
- Produces: `fenwick_tree-2d-student`, `fenwick_tree-2d-solution`

- [ ] **Step 1: Write sample I/O**

`fenwick_tree-2d.in`:

```
2 3 3
1 2 3
4 5 6
2 1 1 2 3
1 1 2 10
2 1 1 1 2
```

`fenwick_tree-2d.out`:

```
21
11
```

Full matrix sum is 21. After setting `a[1][2]=10`, subrectangle `(1,1)-(1,2)` is `1+10=11`.

- [ ] **Step 2: Write the stub**

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: 2D Fenwick tree (point update, rectangle query) ===
// Implement a 1-based 2D Fenwick tree.
// Index 0 is unused in both dimensions.
// Required operations:
//   add(x, y, delta)              — point update at cell (x, y)
//   prefix(x, y)                  — sum of the rectangle (1,1)..(x,y)
//   range(x1, y1, x2, y2)         — inclusive subrectangle via inclusion-exclusion
// Do not recompute 2D prefix sums on every query. Do not use a 1D Fenwick per row for this exercise.

signed main() {
    // === I/O ===
    // Read n, m, q and the initial n by m matrix (1-based).
    // Build the 2D Fenwick tree from the matrix.
    // For each query:
    //   type 1 x y v        → set a[x][y] to v
    //   type 2 x1 y1 x2 y2  → print the inclusive subrectangle sum
    // Write answers to stdout.
    return 0;
}
```

- [ ] **Step 3: Write the reference solution**

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};
static FastIO fastio;

struct Fenwick2D {
    int n, m;
    vector<vector<int>> bit;
    Fenwick2D(int n, int m) : n(n), m(m), bit(n + 1, vector<int>(m + 1)) {}

    void add(int x, int y, int delta) {
        for (int i = x; i <= n; i += i & -i) {
            for (int j = y; j <= m; j += j & -j) {
                bit[i][j] += delta;
            }
        }
    }

    int prefix(int x, int y) {
        int result = 0;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                result += bit[i][j];
            }
        }
        return result;
    }

    int range(int x1, int y1, int x2, int y2) {
        return prefix(x2, y2) - prefix(x1 - 1, y2) - prefix(x2, y1 - 1) + prefix(x1 - 1, y1 - 1);
    }
};

signed main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    Fenwick2D tree(n, m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            tree.add(i, j, a[i][j]);
        }
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y, v;
            cin >> x >> y >> v;
            tree.add(x, y, v - a[x][y]);
            a[x][y] = v;
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << tree.range(x1, y1, x2, y2) << '\n';
        }
    }
    return 0;
}
```

- [ ] **Step 4: Write the statement**

`src/data_structures/fenwick_tree/2d/fenwick_tree-2d.md`:

````markdown
# Matrix Range Sum Queries

**Technique:** 2D Fenwick tree (point update, rectangle query)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an $n \times m$ matrix of integers and $q$ queries. There are two kinds of queries:

- `1 x y v` — set $a_{x,y}$ equal to $v$
- `2 x1 y1 x2 y2` — print the sum of the inclusive subrectangle with corners $(x_1, y_1)$ and $(x_2, y_2)$

All indices are 1-based.

A 1-based 2D Fenwick tree processes each update and rectangle sum in $O(\log n \log m)$ time.

## Input

The first line contains three integers $n$, $m$, and $q$ ($1 \le n, m \le 500$, $1 \le q \le 10^5$).

Each of the next $n$ lines contains $m$ integers, the initial matrix ($|a_{x,y}| \le 10^9$).

Each of the next $q$ lines contains one query. For type 1, $1 \le x \le n$, $1 \le y \le m$, and $|v| \le 10^9$. For type 2, $1 \le x_1 \le x_2 \le n$ and $1 \le y_1 \le y_2 \le m$.

## Output

For every query of type 2, print the subrectangle sum on its own line.

## Sample 1

Input:

```
2 3 3
1 2 3
4 5 6
2 1 1 2 3
1 1 2 10
2 1 1 1 2
```

Output:

```
21
11
```

## Run

From the repository root, after writing `fenwick_tree-2d.student.cpp`:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/2d
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/2d --solution
```
````

- [ ] **Step 5: Register and verify**

Append:

```cmake
cprepo_add_exercise(data_structures/fenwick_tree/2d fenwick_tree-2d)
```

```sh
./scripts/check.sh src/data_structures/fenwick_tree/2d; echo "exit=$?"
./scripts/check.sh src/data_structures/fenwick_tree/2d --solution
```

Expected: student exit 1; `--solution` prints `OK`.

- [ ] **Step 6: Commit**

```bash
git add src/data_structures/fenwick_tree/2d src/CMakeLists.txt
git commit -m "$(cat <<'EOF'
feat: add 2D Fenwick rectangle-sum exercise

Train point updates on a matrix and inclusive subrectangle queries with a 2D binary indexed tree.
EOF
)"
```

---

### Task 4: Range update, point query

**Files:**
- Create: `src/data_structures/fenwick_tree/range_update_point_query/fenwick_tree-range_update_point_query.md`
- Create: `src/data_structures/fenwick_tree/range_update_point_query/fenwick_tree-range_update_point_query.student.cpp`
- Create: `src/data_structures/fenwick_tree/range_update_point_query/fenwick_tree-range_update_point_query.cpp`
- Create: `src/data_structures/fenwick_tree/range_update_point_query/fenwick_tree-range_update_point_query.in`
- Create: `src/data_structures/fenwick_tree/range_update_point_query/fenwick_tree-range_update_point_query.out`
- Modify: `src/CMakeLists.txt`

**Interfaces:**
- Consumes: `cprepo_add_exercise`, `scripts/check.sh`
- Produces: `fenwick_tree-range_update_point_query-student`, `fenwick_tree-range_update_point_query-solution`

- [ ] **Step 1: Write sample I/O**

`.in`:

```
5 3
1 1 1 1 1
1 2 4 3
2 3
2 1
```

`.out`:

```
4
1
```

Add 3 to `[2,4]`. Then `a[3]=4`, `a[1]=1`.

- [ ] **Step 2: Write the stub**

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Fenwick tree as a difference array (range update, point query) ===
// Implement a 1-based Fenwick tree over a difference array.
// Range add [l, r] += v becomes add(l, v) and add(r + 1, -v).
// Point query a[i] is prefix_sum(i).
// Do not loop over the range on every update. Do not use a segment tree for this exercise.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n].
    // Build the difference Fenwick tree from the array.
    // For each query:
    //   type 1 l r v → add v to every element in [l, r]
    //   type 2 i     → print a[i]
    // Write answers to stdout.
    return 0;
}
```

- [ ] **Step 3: Write the reference solution**

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};
static FastIO fastio;

struct Fenwick {
    int n;
    vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    int prefix_sum(int i) {
        int result = 0;
        for (; i > 0; i -= i & -i) {
            result += bit[i];
        }
        return result;
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    Fenwick tree(n);
    int prev = 0;
    for (int i = 1; i <= n; ++i) {
        int value;
        cin >> value;
        tree.add(i, value - prev);
        prev = value;
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            tree.add(l, v);
            if (r + 1 <= n) {
                tree.add(r + 1, -v);
            }
        } else {
            int i;
            cin >> i;
            cout << tree.prefix_sum(i) << '\n';
        }
    }
    return 0;
}
```

- [ ] **Step 4: Write the statement**

`src/data_structures/fenwick_tree/range_update_point_query/fenwick_tree-range_update_point_query.md`:

````markdown
# Range Add, Point Query

**Technique:** Fenwick tree as a difference array (range update, point query)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. There are two kinds of queries:

- `1 l r v` — add $v$ to every element of the inclusive range $[l, r]$
- `2 i` — print $a_i$

Indices are 1-based.

Store the array as a difference sequence in a 1-based Fenwick tree: a range add becomes two point updates, and $a_i$ is a prefix sum.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains one query. For type 1, $1 \le l \le r \le n$ and $|v| \le 10^9$. For type 2, $1 \le i \le n$.

## Output

For every query of type 2, print $a_i$ on its own line.

## Sample 1

Input:

```
5 3
1 1 1 1 1
1 2 4 3
2 3
2 1
```

Output:

```
4
1
```

## Run

From the repository root, after writing `fenwick_tree-range_update_point_query.student.cpp`:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/range_update_point_query
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/range_update_point_query --solution
```
````

- [ ] **Step 5: Register and verify**

```cmake
cprepo_add_exercise(data_structures/fenwick_tree/range_update_point_query fenwick_tree-range_update_point_query)
```

Student check exits 1. `--solution` prints `OK`.

- [ ] **Step 6: Commit**

```bash
git add src/data_structures/fenwick_tree/range_update_point_query src/CMakeLists.txt
git commit -m "$(cat <<'EOF'
feat: add Fenwick range-update point-query exercise

Practice difference-array updates on a 1-based Fenwick tree instead of scanning the range.
EOF
)"
```

---

### Task 5: Range update, range query

**Files:**
- Create: `src/data_structures/fenwick_tree/range_update_range_query/fenwick_tree-range_update_range_query.md`
- Create: `src/data_structures/fenwick_tree/range_update_range_query/fenwick_tree-range_update_range_query.student.cpp`
- Create: `src/data_structures/fenwick_tree/range_update_range_query/fenwick_tree-range_update_range_query.cpp`
- Create: `src/data_structures/fenwick_tree/range_update_range_query/fenwick_tree-range_update_range_query.in`
- Create: `src/data_structures/fenwick_tree/range_update_range_query/fenwick_tree-range_update_range_query.out`
- Modify: `src/CMakeLists.txt`

**Interfaces:**
- Consumes: `cprepo_add_exercise`, `scripts/check.sh`
- Produces: `fenwick_tree-range_update_range_query-student`, `fenwick_tree-range_update_range_query-solution`

- [ ] **Step 1: Write sample I/O**

`.in`:

```
5 3
1 1 1 1 1
1 2 4 3
2 1 5
2 2 3
```

`.out`:

```
14
8
```

After adding 3 to `[2,4]`, total sum is 14 and `[2,3]` is 8.

- [ ] **Step 2: Write the stub**

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: two Fenwick trees (range update, range query) ===
// Maintain two 1-based Fenwick trees B1 and B2 so that
//   range_add(l, r, v) updates both trees
//   prefix(i) = B1.prefix(i) * i - B2.prefix(i)
//   range_sum(l, r) = prefix(r) - prefix(l - 1)
// Do not use a segment tree with lazy propagation for this exercise.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n].
    // Build the dual Fenwick structure from the array.
    // For each query:
    //   type 1 l r v → add v to every element in [l, r]
    //   type 2 l r   → print the sum of [l, r]
    // Write answers to stdout.
    return 0;
}
```

- [ ] **Step 3: Write the reference solution**

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};
static FastIO fastio;

struct Fenwick {
    int n;
    vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    int prefix_sum(int i) {
        int result = 0;
        for (; i > 0; i -= i & -i) {
            result += bit[i];
        }
        return result;
    }
};

struct RangeFenwick {
    int n;
    Fenwick b1, b2;
    explicit RangeFenwick(int n) : n(n), b1(n), b2(n) {}

    void range_add(int l, int r, int v) {
        b1.add(l, v);
        b2.add(l, v * (l - 1));
        if (r + 1 <= n) {
            b1.add(r + 1, -v);
            b2.add(r + 1, -v * r);
        }
    }

    int prefix(int i) { return b1.prefix_sum(i) * i - b2.prefix_sum(i); }

    int range_sum(int l, int r) { return prefix(r) - prefix(l - 1); }
};

signed main() {
    int n, q;
    cin >> n >> q;
    RangeFenwick tree(n);
    for (int i = 1; i <= n; ++i) {
        int value;
        cin >> value;
        tree.range_add(i, i, value);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            tree.range_add(l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << tree.range_sum(l, r) << '\n';
        }
    }
    return 0;
}
```

- [ ] **Step 4: Write the statement**

`src/data_structures/fenwick_tree/range_update_range_query/fenwick_tree-range_update_range_query.md`:

````markdown
# Range Add, Range Sum

**Technique:** two Fenwick trees (range update, range query)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and $q$ queries. There are two kinds of queries:

- `1 l r v` — add $v$ to every element of the inclusive range $[l, r]$
- `2 l r` — print $a_l + \cdots + a_r$

Indices are 1-based.

Maintain two 1-based Fenwick trees so that a range add updates both trees and a prefix sum is recovered in $O(\log n)$.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains one query. For type 1, $1 \le l \le r \le n$ and $|v| \le 10^9$. For type 2, $1 \le l \le r \le n$.

## Output

For every query of type 2, print the range sum on its own line.

## Sample 1

Input:

```
5 3
1 1 1 1 1
1 2 4 3
2 1 5
2 2 3
```

Output:

```
14
8
```

## Run

From the repository root, after writing `fenwick_tree-range_update_range_query.student.cpp`:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/range_update_range_query
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/range_update_range_query --solution
```
````

- [ ] **Step 5: Register and verify**

```cmake
cprepo_add_exercise(data_structures/fenwick_tree/range_update_range_query fenwick_tree-range_update_range_query)
```

Student exit 1. `--solution` prints `OK`.

- [ ] **Step 6: Commit**

```bash
git add src/data_structures/fenwick_tree/range_update_range_query src/CMakeLists.txt
git commit -m "$(cat <<'EOF'
feat: add Fenwick range-update range-query exercise

Practice the two-tree Fenwick identity for range adds and range sums.
EOF
)"
```

---

### Task 6: Count inversions

**Files:**
- Create: `src/data_structures/fenwick_tree/count_inversions/fenwick_tree-count_inversions.md`
- Create: `src/data_structures/fenwick_tree/count_inversions/fenwick_tree-count_inversions.student.cpp`
- Create: `src/data_structures/fenwick_tree/count_inversions/fenwick_tree-count_inversions.cpp`
- Create: `src/data_structures/fenwick_tree/count_inversions/fenwick_tree-count_inversions.in`
- Create: `src/data_structures/fenwick_tree/count_inversions/fenwick_tree-count_inversions.out`
- Modify: `src/CMakeLists.txt`

**Interfaces:**
- Consumes: `cprepo_add_exercise`, `scripts/check.sh`
- Produces: `fenwick_tree-count_inversions-student`, `fenwick_tree-count_inversions-solution`

- [ ] **Step 1: Write sample I/O**

`.in`:

```
5
2 4 1 3 5
```

`.out`:

```
3
```

Inversions: `(2,1)`, `(4,1)`, `(4,3)`.

- [ ] **Step 2: Write the stub**

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Fenwick frequency tree plus coordinate compression ===
// Compress values, then scan left to right.
// For each a[i], add prefix_sum(rank(a[i]) + 1 .. universe) to the answer
// (already-seen values strictly greater than a[i]), then add(rank(a[i]), 1).
// Do not use O(n^2) pair enumeration. Do not use a balanced BST for this exercise.

signed main() {
    // === I/O ===
    // Read n and the array a[1..n].
    // Print one integer: the number of pairs i < j with a[i] > a[j].
    return 0;
}
```

- [ ] **Step 3: Write the reference solution**

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};
static FastIO fastio;

struct Fenwick {
    int n;
    vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    int prefix_sum(int i) {
        int result = 0;
        for (; i > 0; i -= i & -i) {
            result += bit[i];
        }
        return result;
    }

    int range_sum(int l, int r) {
        if (l > r) {
            return 0;
        }
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

signed main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> values(a.begin() + 1, a.end());
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    auto rank_of = [&](int x) {
        return int(lower_bound(values.begin(), values.end(), x) - values.begin()) + 1;
    };
    Fenwick tree(int(values.size()));
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        int r = rank_of(a[i]);
        answer += tree.range_sum(r + 1, tree.n);
        tree.add(r, 1);
    }
    cout << answer << '\n';
    return 0;
}
```

- [ ] **Step 4: Write the statement**

`src/data_structures/fenwick_tree/count_inversions/fenwick_tree-count_inversions.md`:

````markdown
# Inversion Count

**Technique:** Fenwick frequency tree plus coordinate compression

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given an array of $n$ integers $a_1, a_2, \ldots, a_n$. Count the number of pairs of indices $(i, j)$ such that $i < j$ and $a_i > a_j$.

Values may be negative or as large as $10^9$ in absolute value, so compress them onto a Fenwick tree used as a frequency table. Scan from left to right: the query is the number of already-seen values strictly greater than $a_i$, then insert $a_i$.

## Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

## Output

Print one integer, the number of inversions.

## Sample 1

Input:

```
5
2 4 1 3 5
```

Output:

```
3
```

## Run

From the repository root, after writing `fenwick_tree-count_inversions.student.cpp`:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/count_inversions
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/count_inversions --solution
```
````

- [ ] **Step 5: Register and verify**

```cmake
cprepo_add_exercise(data_structures/fenwick_tree/count_inversions fenwick_tree-count_inversions)
```

Student exit 1. `--solution` prints `OK`.

- [ ] **Step 6: Commit**

```bash
git add src/data_structures/fenwick_tree/count_inversions src/CMakeLists.txt
git commit -m "$(cat <<'EOF'
feat: add Fenwick inversion-count exercise

Count inversions with coordinate compression and a Fenwick frequency tree.
EOF
)"
```

---

### Task 7: Frequency counting

**Files:**
- Create: `src/data_structures/fenwick_tree/frequency_counting/fenwick_tree-frequency_counting.md`
- Create: `src/data_structures/fenwick_tree/frequency_counting/fenwick_tree-frequency_counting.student.cpp`
- Create: `src/data_structures/fenwick_tree/frequency_counting/fenwick_tree-frequency_counting.cpp`
- Create: `src/data_structures/fenwick_tree/frequency_counting/fenwick_tree-frequency_counting.in`
- Create: `src/data_structures/fenwick_tree/frequency_counting/fenwick_tree-frequency_counting.out`
- Modify: `src/CMakeLists.txt`

**Interfaces:**
- Consumes: `cprepo_add_exercise`, `scripts/check.sh`
- Produces: `fenwick_tree-frequency_counting-student`, `fenwick_tree-frequency_counting-solution`

- [ ] **Step 1: Write sample I/O**

`.in`:

```
5 6
1 2
1 5
1 2
3 2 4
2 2
3 2 5
```

`.out`:

```
2
2
```

Universe is `1..5`. After inserting 2, 5, 2: count `[2,4]` is 2. Erase one 2. Count `[2,5]` is 2 (one 2 and one 5).

- [ ] **Step 2: Write the stub**

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Fenwick tree as a frequency table on values 1..n ===
// The Fenwick index is the value itself. No compression.
//   insert x → add(x, 1)
//   erase x  → add(x, -1)
//   count [l, r] → prefix_sum(r) - prefix_sum(l - 1)
// Start from an empty multiset. Do not store the multiset in a map for this exercise.

signed main() {
    // === I/O ===
    // Read n q. n is the value universe (values are in 1..n).
    // Then q queries:
    //   type 1 x   → insert one occurrence of x
    //   type 2 x   → erase one occurrence of x (x is present)
    //   type 3 l r → print how many stored values lie in [l, r]
    // Write answers to stdout.
    return 0;
}
```

- [ ] **Step 3: Write the reference solution**

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};
static FastIO fastio;

struct Fenwick {
    int n;
    vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    int prefix_sum(int i) {
        int result = 0;
        for (; i > 0; i -= i & -i) {
            result += bit[i];
        }
        return result;
    }

    int range_sum(int l, int r) { return prefix_sum(r) - prefix_sum(l - 1); }
};

signed main() {
    int n, q;
    cin >> n >> q;
    Fenwick tree(n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            tree.add(x, 1);
        } else if (type == 2) {
            int x;
            cin >> x;
            tree.add(x, -1);
        } else {
            int l, r;
            cin >> l >> r;
            cout << tree.range_sum(l, r) << '\n';
        }
    }
    return 0;
}
```

- [ ] **Step 4: Write the statement**

`src/data_structures/fenwick_tree/frequency_counting/fenwick_tree-frequency_counting.md`:

````markdown
# Range Frequency Queries

**Technique:** Fenwick tree as a frequency table on values $1..n$

Time limit: 1 s
Memory limit: 256 MB

## Problem

Start with an empty multiset. Values always lie in $1..n$ (no compression). Process $q$ operations:

- `1 x` — insert one occurrence of $x$
- `2 x` — erase one occurrence of $x$ (the input guarantees that $x$ is present)
- `3 l r` — print how many stored values lie in the inclusive range $[l, r]$

A 1-based Fenwick tree whose indices are the values themselves answers each update and range-frequency query in $O(\log n)$.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$). $n$ is the value universe.

Each of the next $q$ lines contains one query. All values $x$, $l$, and $r$ satisfy $1 \le x, l, r \le n$ and $l \le r$.

## Output

For every query of type 3, print the count on its own line.

## Sample 1

Input:

```
5 6
1 2
1 5
1 2
3 2 4
2 2
3 2 5
```

Output:

```
2
2
```

## Run

From the repository root, after writing `fenwick_tree-frequency_counting.student.cpp`:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/frequency_counting
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/frequency_counting --solution
```
````

- [ ] **Step 5: Register and verify**

```cmake
cprepo_add_exercise(data_structures/fenwick_tree/frequency_counting fenwick_tree-frequency_counting)
```

Student exit 1. `--solution` prints `OK`.

- [ ] **Step 6: Commit**

```bash
git add src/data_structures/fenwick_tree/frequency_counting src/CMakeLists.txt
git commit -m "$(cat <<'EOF'
feat: add Fenwick frequency-table exercise

Query how many stored values lie in a range using a Fenwick tree over 1..n.
EOF
)"
```

---

### Task 8: Dynamic compressed Fenwick

**Files:**
- Create: `src/data_structures/fenwick_tree/dynamic/fenwick_tree-dynamic.md`
- Create: `src/data_structures/fenwick_tree/dynamic/fenwick_tree-dynamic.student.cpp`
- Create: `src/data_structures/fenwick_tree/dynamic/fenwick_tree-dynamic.cpp`
- Create: `src/data_structures/fenwick_tree/dynamic/fenwick_tree-dynamic.in`
- Create: `src/data_structures/fenwick_tree/dynamic/fenwick_tree-dynamic.out`
- Modify: `src/CMakeLists.txt`

**Interfaces:**
- Consumes: `cprepo_add_exercise`, `scripts/check.sh`
- Produces: `fenwick_tree-dynamic-student`, `fenwick_tree-dynamic-solution`

- [ ] **Step 1: Write sample I/O**

`.in`:

```
6
1 1000000000
1 7
1 1000000000
3 7 1000000000
2 1000000000
3 1 10
```

`.out`:

```
3
1
```

No `n` on the first line: first integer is `q`. After three inserts, `[7, 10^9]` contains 3 values. Erase one `10^9`. `[1,10]` contains the remaining 7.

- [ ] **Step 2: Write the stub**

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Fenwick tree on a coordinate-compressed universe ===
// Values, query bounds, and updates are in [1, 10^9]. Read all queries first,
// collect every integer that appears, compress to ranks 1..k, then Fenwick on k.
// Same operations as frequency counting, but never allocate a tree of size 10^9.
// Do not use std::map as the Fenwick tree for this exercise.

signed main() {
    // === I/O ===
    // Read q, then q queries (no universe size n):
    //   type 1 x   → insert one occurrence of x
    //   type 2 x   → erase one occurrence of x (x is present)
    //   type 3 l r → print how many stored values lie in [l, r]
    // Write answers to stdout.
    return 0;
}
```

- [ ] **Step 3: Write the reference solution**

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};
static FastIO fastio;

struct Fenwick {
    int n;
    vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    int prefix_sum(int i) {
        int result = 0;
        for (; i > 0; i -= i & -i) {
            result += bit[i];
        }
        return result;
    }

    int range_sum(int l, int r) { return prefix_sum(r) - prefix_sum(l - 1); }
};

struct Query {
    int type, x, y;
};

signed main() {
    int q;
    cin >> q;
    vector<Query> queries(q);
    vector<int> coords;
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == 3) {
            cin >> queries[i].x >> queries[i].y;
            coords.push_back(queries[i].x);
            coords.push_back(queries[i].y);
        } else {
            cin >> queries[i].x;
            coords.push_back(queries[i].x);
        }
    }
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    auto rank_of = [&](int value) {
        return int(lower_bound(coords.begin(), coords.end(), value) - coords.begin()) + 1;
    };
    Fenwick tree(int(coords.size()));
    for (const auto& query : queries) {
        if (query.type == 1) {
            tree.add(rank_of(query.x), 1);
        } else if (query.type == 2) {
            tree.add(rank_of(query.x), -1);
        } else {
            cout << tree.range_sum(rank_of(query.x), rank_of(query.y)) << '\n';
        }
    }
    return 0;
}
```

- [ ] **Step 4: Write the statement**

`src/data_structures/fenwick_tree/dynamic/fenwick_tree-dynamic.md`:

````markdown
# Compressed Online Frequency Queries

**Technique:** Fenwick tree on a coordinate-compressed universe

Time limit: 1 s
Memory limit: 256 MB

## Problem

Start with an empty multiset. Values now lie in $[1, 10^9]$, so you cannot allocate a Fenwick tree of that size. Read every query first, compress the distinct integers onto ranks $1..k$, then run a Fenwick frequency tree on $k$.

Operations:

- `1 x` — insert one occurrence of $x$
- `2 x` — erase one occurrence of $x$ (the input guarantees that $x$ is present)
- `3 l r` — print how many stored values lie in the inclusive range $[l, r]$

## Input

The first line contains one integer $q$ ($1 \le q \le 2 \cdot 10^5$). There is no universe size $n$.

Each of the next $q$ lines contains one query. All integers $x$, $l$, and $r$ satisfy $1 \le x, l, r \le 10^9$ and, for type 3, $l \le r$.

## Output

For every query of type 3, print the count on its own line.

## Sample 1

Input:

```
6
1 1000000000
1 7
1 1000000000
3 7 1000000000
2 1000000000
3 1 10
```

Output:

```
3
1
```

## Run

From the repository root, after writing `fenwick_tree-dynamic.student.cpp`:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/dynamic
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/dynamic --solution
```
````

- [ ] **Step 5: Register and verify**

```cmake
cprepo_add_exercise(data_structures/fenwick_tree/dynamic fenwick_tree-dynamic)
```

Student exit 1. `--solution` prints `OK`.

- [ ] **Step 6: Commit**

```bash
git add src/data_structures/fenwick_tree/dynamic src/CMakeLists.txt
git commit -m "$(cat <<'EOF'
feat: add compressed Fenwick frequency exercise

Handle 1e9-valued frequency queries by compressing coordinates before the Fenwick tree.
EOF
)"
```

---

### Task 9: Minimum coins

**Files:**
- Create: `src/dynamic_programming/coin_change_min/coin_change_min.md`
- Create: `src/dynamic_programming/coin_change_min/coin_change_min.student.cpp`
- Create: `src/dynamic_programming/coin_change_min/coin_change_min.cpp`
- Create: `src/dynamic_programming/coin_change_min/coin_change_min.in`
- Create: `src/dynamic_programming/coin_change_min/coin_change_min.out`
- Modify: `src/CMakeLists.txt`

**Interfaces:**
- Consumes: `cprepo_add_exercise`, `scripts/check.sh`
- Produces: `coin_change_min-student`, `coin_change_min-solution`

- [ ] **Step 1: Write sample I/O**

`.in`:

```
3 12
1 5 10
```

`.out`:

```
3
```

`12 = 10 + 1 + 1`, three coins. Greedy with `{1,5,10}` also works here; the statement still forbids relying on greedy.

- [ ] **Step 2: Write the stub**

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: unbounded knapsack DP (minimum coins) ===
// dp[x] = fewest coins that sum to x. dp[0] = 0. Each coin relaxes dp left to right.
// Print -1 if amount is impossible. Do not use greedy coin selection.
// Arrays for the coin list and dp are 0-based.

signed main() {
    // === I/O ===
    // Read n and amount, then n positive coin denominations.
    // Print the minimum number of coins that sum to amount, or -1.
    return 0;
}
```

- [ ] **Step 3: Write the reference solution**

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};
static FastIO fastio;

signed main() {
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    const int inf = 4e18;
    vector<int> dp(amount + 1, inf);
    dp[0] = 0;
    for (int coin : coins) {
        for (int value = coin; value <= amount; ++value) {
            if (dp[value - coin] != inf) {
                dp[value] = min(dp[value], dp[value - coin] + 1);
            }
        }
    }
    if (dp[amount] == inf) {
        cout << -1 << '\n';
    } else {
        cout << dp[amount] << '\n';
    }
    return 0;
}
```

- [ ] **Step 4: Write the statement**

`src/dynamic_programming/coin_change_min/coin_change_min.md`:

````markdown
# Minimum Coins

**Technique:** unbounded knapsack DP (minimum coins)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You have $n$ coin denominations and an unlimited supply of each. Compute the fewest coins whose values sum to `amount`. If it is impossible, print `-1`.

Use 0-based DP: `dp[x]` is the fewest coins that sum to $x$. Greedy choice of the largest coin is not required to be correct, so do not use it.

## Input

The first line contains two integers $n$ and `amount` ($1 \le n \le 100$, $1 \le amount \le 10^4$).

The second line contains $n$ positive integers, the coin denominations (each at most $10^4$).

## Output

Print one integer: the minimum number of coins, or `-1` if `amount` cannot be formed.

## Sample 1

Input:

```
3 12
1 5 10
```

Output:

```
3
```

## Run

From the repository root, after writing `coin_change_min.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/coin_change_min
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/coin_change_min --solution
```
````

- [ ] **Step 5: Register and verify**

```cmake
cprepo_add_exercise(dynamic_programming/coin_change_min coin_change_min)
```

Student exit 1. `--solution` prints `OK`.

- [ ] **Step 6: Commit**

```bash
git add src/dynamic_programming/coin_change_min src/CMakeLists.txt
git commit -m "$(cat <<'EOF'
feat: add minimum-coin-change DP exercise

Replace the header drill with a stdin/stdout unbounded-knapsack problem and a guided stub.
EOF
)"
```

---

### Task 10: Remove migrated library files

**Files:**
- Delete: `include/cprepo/data_structures/fenwick_tree.hpp`
- Delete: `include/cprepo/dynamic_programming/coin_change_min.hpp`
- Delete: `tests/data_structures/fenwick_tree_test.cpp`
- Delete: `tests/dynamic_programming/coin_change_min_test.cpp`

**Interfaces:**
- Consumes: Catch2 glob in `tests/CMakeLists.txt` (no edit required if files disappear)
- Produces: remaining Catch2 suite still builds

- [ ] **Step 1: Delete the four files**

```sh
rm include/cprepo/data_structures/fenwick_tree.hpp
rm include/cprepo/dynamic_programming/coin_change_min.hpp
rm tests/data_structures/fenwick_tree_test.cpp
rm tests/dynamic_programming/coin_change_min_test.cpp
```

- [ ] **Step 2: Rebuild Catch2 tests**

If `tests/` is still untracked, first add it only when you are ready to compile the remaining suite. Configure and build:

```sh
cmake --build --preset dev --target cprepo_tests
ctest --preset dev -R fenwick -R coin-change-min
```

Expected: no tests named fenwick / coin-change-min. Then:

```sh
ctest --preset dev
```

Expected: remaining Catch2 tests pass, plus the eight `*-solution` check.sh tests.

If `tests/` was never committed, still compile `cprepo_tests` from the live tree. Do not `git add tests/` except these deletions (no-op if untracked).

- [ ] **Step 3: Confirm all eight solutions**

```sh
./scripts/check.sh src/data_structures/fenwick_tree/classic --solution
./scripts/check.sh src/data_structures/fenwick_tree/2d --solution
./scripts/check.sh src/data_structures/fenwick_tree/range_update_point_query --solution
./scripts/check.sh src/data_structures/fenwick_tree/range_update_range_query --solution
./scripts/check.sh src/data_structures/fenwick_tree/count_inversions --solution
./scripts/check.sh src/data_structures/fenwick_tree/frequency_counting --solution
./scripts/check.sh src/data_structures/fenwick_tree/dynamic --solution
./scripts/check.sh src/dynamic_programming/coin_change_min --solution
```

Expected: eight lines of `OK`.

- [ ] **Step 4: Commit**

```bash
git add -u include/cprepo/data_structures/fenwick_tree.hpp include/cprepo/dynamic_programming/coin_change_min.hpp tests/data_structures/fenwick_tree_test.cpp tests/dynamic_programming/coin_change_min_test.cpp
git commit -m "$(cat <<'EOF'
chore: drop Fenwick and min-coin library tests

Practice for those topics now lives in src/ exercises, so the headers and Catch2 files are unused.
EOF
)"
```

If `git add -u` stages nothing because the files were never tracked, skip the commit and keep the deletions on disk.

---

### Task 11: Docs and CI

**Files:**
- Modify: `README.md`
- Modify: `CONTRIBUTING.md`
- Modify: `docs/catalog.md`
- Modify: `.github/workflows/ci.yml`

**Interfaces:**
- Consumes: eight exercise paths and `scripts/check.sh`
- Produces: student workflow without `CXX=`; CI runs `ctest` then eight `--solution` checks

- [ ] **Step 1: Rewrite README practice workflow**

Replace the Requirements compiler note, Build and test, Project layout, and Practice workflow sections so they match this text (keep the opening CP4 paragraph, then continue):

Requirements: CMake 3.25, Ninja, GNU g++ (CMake searches `g++-15` … `g++` when `CXX` is unset), Git for Catch2.

Build remaining Catch2 tests:

```sh
cmake --preset dev
cmake --build --preset dev
ctest --preset dev
```

No `CXX=g++-15` in the student commands.

Project layout adds:

```text
src/
├── data_structures/fenwick_tree/   # one folder per Fenwick technique
└── dynamic_programming/coin_change_min/
scripts/check.sh
include/cprepo/                     # unmigrated headers
tests/                              # Catch2 for unmigrated headers
```

Practice for migrated topics:

1. Open the `.md` in the exercise folder.
2. Fill `*.student.cpp` (FastIO, named technique, I/O).
3. From the repo root run `./scripts/check.sh src/...` (command is in the statement).
4. Peek at `*.cpp` only after attempting the stub.

Keep Catch2 tags for topics still in `include/`. Remove the `[fenwick]` example. Use `[dijkstra]` only.

- [ ] **Step 2: Rewrite `CONTRIBUTING.md`**

```markdown
# Adding an Exercise

Migrated topics (Fenwick tree, minimum coin change, and later the rest of the catalog) use judge-style exercises under `src/`.

1. Put the exercise under `src/<domain>/<topic>/` or, when one topic has several techniques, `src/<domain>/<topic>/<technique>/`.
2. Add five files with a shared stem: `.md`, `.cpp` (reference), `.student.cpp` (stub), `.in`, `.out`.
3. Start both C++ files with:
   ```cpp
   #include<bits/stdc++.h>
   using namespace std;
   #define int long long
   ```
   Use `signed main()`. Fenwick implementations are 1-based.
4. The stub already contains the prelude. It must compile. Leave FastIO, the technique, and I/O as comments for the student.
5. Sample 1 in the markdown must match `.in` and `.out` byte-for-byte.
6. Register the exercise in `src/CMakeLists.txt`:
   `cprepo_add_exercise(<dir-relative-to-src> <stem>)`.
7. Do not add a Catch2 test for a migrated topic.
8. Update `docs/catalog.md`.
9. Run `./scripts/check.sh src/<path> --solution` and confirm the stub compile-and-diff fails.

Unmigrated topics still use a header under `include/cprepo/` plus `tests/<domain>/<name>_test.cpp` as before.
```

- [ ] **Step 3: Update catalog rows**

In `docs/catalog.md` change the Fenwick row to:

```
| Implemented | Fenwick tree | `src/data_structures/fenwick_tree/` (`classic`, `2d`, `range_update_point_query`, `range_update_range_query`, `count_inversions`, `frequency_counting`, `dynamic`) | `ch2/ourown/fenwicktree_ds.cpp` |
```

Change the coin-change-min row to:

```
| Implemented | Coin change (min coins) | `src/dynamic_programming/coin_change_min/` | `ch3/dp/UVa00674.cpp` |
```

Also change the catalog intro sentence "Each implemented topic is one header" so migrated topics are exercise folders.

- [ ] **Step 4: Extend CI**

Replace `.github/workflows/ci.yml` with:

```yaml
name: CI

on:
  push:
  pull_request:

jobs:
  build-and-test:
    runs-on: ubuntu-24.04
    steps:
      - uses: actions/checkout@v4
      - name: Configure
        env:
          CXX: g++
        run: cmake --preset dev
      - name: Build
        run: cmake --build --preset dev
      - name: Test
        run: ctest --preset dev
      - name: Exercise solutions
        run: |
          ./scripts/check.sh src/data_structures/fenwick_tree/classic --solution
          ./scripts/check.sh src/data_structures/fenwick_tree/2d --solution
          ./scripts/check.sh src/data_structures/fenwick_tree/range_update_point_query --solution
          ./scripts/check.sh src/data_structures/fenwick_tree/range_update_range_query --solution
          ./scripts/check.sh src/data_structures/fenwick_tree/count_inversions --solution
          ./scripts/check.sh src/data_structures/fenwick_tree/frequency_counting --solution
          ./scripts/check.sh src/data_structures/fenwick_tree/dynamic --solution
          ./scripts/check.sh src/dynamic_programming/coin_change_min --solution
```

- [ ] **Step 5: Commit**

```bash
git add README.md CONTRIBUTING.md docs/catalog.md .github/workflows/ci.yml
git commit -m "$(cat <<'EOF'
docs: document src/ contest exercises and CI checks

Point students at check.sh without CXX= and keep CI running every reference solution.
EOF
)"
```

---

## Self-review

**Spec coverage**

| Spec section | Task |
|---|---|
| Layout under `src/` | 2–9 |
| Five files per exercise | 2–9 |
| Contest prelude + `signed main` | 2–9 stubs and solutions |
| FastIO written by student; struct in solutions | 2–9 |
| 1-based Fenwick, inclusive ranges | 2–8 |
| Seven Fenwick techniques, no PURQ duplicate | 2–8 |
| `coin_change_min` at topic folder | 9 |
| `scripts/check.sh` behavior and exit codes | 1, verified in 2–9 |
| CMake compiler find + exercise targets + CTest on solutions | 1, 2–9 |
| Delete Fenwick and min-coin headers/tests only | 10 |
| README, CONTRIBUTING, catalog, CI | 11 |
| Remaining Catch2 intact | 10 |

**Placeholder scan:** no TBD. Each exercise includes stub, solution, I/O, and CMake call.

**Type consistency:** helper is always `cprepo_add_exercise(<dir-relative-to-src> <stem>)`. Checker always `./scripts/check.sh src/<path> [--solution]`. Binary always `build/dev/exercises/<stem>-student` or `<stem>-solution`.
