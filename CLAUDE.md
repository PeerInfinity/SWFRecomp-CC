# SWFRecomp-CC Project Instructions

## Git Workflow

This repo is trunk-based: commit directly to `master`. Do NOT create a branch
before committing, even when default Git guidance says to branch first when on
the default branch. Commit only when asked.

## Current Focus: Ruffle AVM1 Test Suite

We are improving the pass rate on the Ruffle AVM1 test suite (ActionScript 1/2 trace tests).

**Key docs to read at session start:**
- `ruffle-tests/tests/swfs/_investigation/SESSION_START_GUIDE.md` — architecture, how to run tests, infrastructure (all suites)
- `ruffle-tests/tests/swfs/_investigation/OVERVIEW.md` — cross-suite summary (avm1, gnash, shumway)
- Per-suite status: `ruffle-tests/tests/swfs/{suite}/_investigation/CURRENT_STATUS.md`

**Quick test commands:**
```bash
# Run a single Ruffle test locally (default: NO_GRAPHICS / swf_core.c)
python3 ruffle-tests/verify_output.py --test=TEST_NAME --diff --verbose

# Run against the --mode=graphics native build (swf.c + offscreen Dawn).
# Phase 2 in progress — 948/1125 pass (84.3%) as of 2026-05-11; only 2 strict parity gaps remain (case-v6 CI flake, place_and_remove_object_insane_test shared-code bug). See
# SWFRecompDocs/plans/graphics-native-test-mode-*.md for the plan,
# playbook, and full-suite baseline.
# Local Dawn install required at ~/CC/dawn-install (or set DAWN_INSTALL env var).
python3 ruffle-tests/verify_output.py --test=TEST_NAME --mode=graphics --diff

# CI dispatch (graphics modes auto-build Dawn on cache miss; ~30 min the
# first time, ~6 min on subsequent runs):
gh workflow run ruffle-tests.yml --ref master -f mode=graphics -f single_test=TEST_NAME
```

**IMPORTANT: Do NOT run full test suites.** Never run `all_tests.sh`, `verify_output.py` without `--test`, or any command that runs all tests. Both the Ruffle suite and the old test suite have CI workflows — commit your changes and the user will trigger them. Only run individual tests with `--test=TEST_NAME`.

## Project Structure

- `SWFRecomp/` — Recompiler: converts SWF bytecode to C (`src/action/action.cpp` is the main bytecode→C translator)
- `SWFModernRuntime/` — Runtime: executes the generated C (`src/actionmodern/action.c` is ~50K lines, the core runtime)
- `ruffle-tests/` — Ruffle test suites:
  - `tests/swfs/avm1/` — 641 AVM1 tests from Ruffle (100% filtered pass rate)
  - `tests/swfs/from_gnash/` — 335 tests from Gnash (147 effective pass across 5 sub-suites)
  - `tests/swfs/from_shumway/` — 92 flat + 47 avm1 tests from Shumway (61 + 45 effective)
- `SWFRecomp/tests/` — Old hand-written test suite (158 trace tests + 59 graphics tests, all passing)
- `SWFRecomp/scripts/` — Build scripts (build_test.sh, deploy_example.sh, etc.)
- `scripts/` — Test result processing scripts (diff, markdown generation)

## Two Test Systems

1. **Ruffle tests** (`ruffle-tests/tests/swfs/avm1/`): 641 tests from Ruffle project. Shared runner `verify_output.py`. Expected output in `output.txt` per test. Results in `results.json`. CI via GitHub Actions workflow (manual dispatch).

2. **Old tests** (`SWFRecomp/tests/`): 115 hand-written tests. Per-test `validate.py` validators. Runner is `all_tests.sh`. Results in `test_results.json`. Run locally only.

## Critical Runtime Architecture Notes

- `ASObject` and `ASFunction` are **different structs** — never cast one to the other. Functions have `prototype_obj` and `own_props` fields; objects have a `properties` array. Code that handles both types must check the ActionVar type tag first.
- Stack is a byte buffer with PUSH/POP macros. String values store a pointer (not inline data) at offset +16.
- Type system: `ActionVar` with type tag (`ACTION_STACK_VALUE_STRING=0, F32=1, NULL=2, UNDEFINED=3, BOOLEAN=5, F64=6, OBJECT=11, ARRAY=12, FUNCTION=13, MOVIECLIP=14`)
- Scope resolution: WITH scope chain → global variables → undefined
- `emsdk_env.sh` is at `SWFRecomp-CC/emsdk/emsdk_env.sh`
- Build scripts are under `SWFRecomp/scripts/`, NOT project root `scripts/`
- If running locally, the Ruffle source repository is available at `~/CC/ruffle`
- **Test determinism**: `Math.random` and `Date.getTime()` are seeded per-test via the `MOCK_DATE_TIME` macro that `verify_output.py` defines on every gcc invocation (default `981152406000` ms = 2001-02-03 04:05:06 NPT, matching Ruffle's `--deterministic` mode; per-test override via `mock_date_time` in `test.toml`). `math.c::GenerateRandomNumber` uses `MOCK_DATE_TIME * 1000` µs as the avmplus RNG seed. Two CI runs at the same SHA produce byte-identical results across all suites — if results "fluctuate," look for an actual bug, not RNG variance.
- MTASC (ActionScript 2 compiler) is at `~/CC/mtasc/`. Binary: `~/CC/mtasc/bin/mtasc`. Requires `-cp ~/CC/mtasc/ocaml/mtasc/std` for the standard library. Example: `~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std -main -header 200:150:30 Test.as -swf test.swf -version 8`

## Documenting Accepted Diffs and Ruffle/Flash Differences

Three investigation docs track cases where test diffs are permanent or intentional:

- `ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md` — Tests where some output lines will **never match** due to platform UB, inconsistent expected output, Flash quirks we can't replicate, or Flash UB we intentionally don't replicate. Each entry documents the category, example diff, explanation, and decision.
- `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` — Tests where our implementation **matches Flash's actual behavior** but disagrees with Ruffle's expected output (i.e., the Ruffle test expectation reflects Ruffle's own behavior, not Flash's).
- `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_COMPAT_TWEAKS.md` — Pragmatic implementation choices made specifically to match Ruffle's expected test output, where the "correct" behavior is unclear or unspecified (e.g., +1 pixel on text field bounds).
- `ruffle-tests/tests/swfs/avm1/_investigation/FLASH_BUGS_REPLICATED.md` — Known Flash Player bugs that we deliberately replicate. Both Flash and Ruffle exhibit the same buggy behavior, and our implementation matches both (e.g., colorTransform aMult-only no-op).

**When to update these docs:**
- If you discover a test diff that cannot be fixed because it depends on C undefined behavior, platform-specific results, or internally inconsistent expected output → add it to `ACCEPTED_DIFFS.md` under the appropriate category.
- If you discover a test diff where our output matches Flash's documented/known behavior but Ruffle's expected output reflects Ruffle's own divergent implementation → add it to `RUFFLE_VS_FLASH_DIFFERENCES.md`.
- If you make an arbitrary implementation choice (not clearly documented in Flash specs) specifically to match Ruffle's expected output → add it to `RUFFLE_COMPAT_TWEAKS.md`.
- If you deliberately replicate a documented Flash Player bug to match both Flash and Ruffle behavior → add it to `FLASH_BUGS_REPLICATED.md`.
- Always include: test name, example diff, explanation of why it's unfixable/intentional, and the decision.
- Update the summary table in `ACCEPTED_DIFFS.md` when adding new entries.
- When adding a test to `ACCEPTED_DIFFS.md`, also add it to `ruffle-tests/ignored_tests.txt` so it is excluded from filtered results.
