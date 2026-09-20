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
