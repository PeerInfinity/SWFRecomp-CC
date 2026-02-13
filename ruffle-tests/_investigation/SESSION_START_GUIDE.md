# Ruffle Test Session Start Guide

Read this document at the start of each session to get up to speed quickly.
For current test results, regressions, and recommended work order, see `CURRENT_STATUS.md` in this directory.

## How to Check Current Status

1. Read `ruffle-tests/_investigation/CURRENT_STATUS.md` — curated analysis of results, regressions, and priorities
2. Read `ruffle-tests/results.json` — full test results with per-test data
3. Read `ruffle-results-diff.md` — what changed in the last run
4. Read `ruffle-results-filtered.md` — comprehensive report (filtered = ignoring interactive/network/audio tests)
5. Read `ruffle-tests/results_filtered.json` — filtered results as JSON

## How to Run Tests

### Single test locally (fast iteration)

```bash
# 1. Build the recompiler
cd SWFRecomp/build && cmake .. && make -j$(nproc) && cd ../..

# 2. Download test SWFs (only needed once)
cd ruffle-tests && bash download_tests.sh && cd ..

# 3. Run a single test with diff output
python3 ruffle-tests/verify_output.py --test=TEST_NAME --diff --verbose

# 4. Run a few tests
python3 ruffle-tests/verify_output.py --test=test1 --test=test2 --diff --verbose
```

### Full test suite (use CI)

Do NOT run the full suite locally. Instead:
1. Commit your changes to master
2. User triggers the "Ruffle AVM1 Tests" GitHub Actions workflow (workflow_dispatch)
3. Results are committed to the `ruffle-test-results` branch
4. After the run, merge `ruffle-test-results` into master to update result files

## Architecture Overview

### Two-stage pipeline: Recompiler → Runtime

1. **SWFRecomp** (`SWFRecomp/src/action/action.cpp`, ~2000 lines) — Reads SWF bytecode, emits C code
   - Two-pass: first pass identifies jump targets, second pass emits C
   - Each ActionScript bytecode op → a C function call (e.g., `ActionAdd` → `actionAdd(app_context)`)
   - Stack-based: all operations use PUSH/POP macros on a byte buffer
   - Generates: `RecompiledScripts/script_N.c` and `RecompiledTags/tagMain.c`

2. **SWFModernRuntime** (`SWFModernRuntime/src/actionmodern/action.c`, ~10000 lines) — Executes the generated C
   - Implements all the `action*()` functions
   - Type system: `ActionVar` struct with 15 types (string, f32, f64, null, undefined, boolean, object, array, function, movieclip, etc.)
   - Object system: `ASObject` (property bags), `ASFunction` (with prototype), `ASArray`
   - Scope chain: `scope_chain[MAX_SCOPE_DEPTH]` array for WITH/function scoping
   - Variable resolution: WITH scope → global scope → undefined

### Key runtime files

| File | Purpose |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | Main runtime (~10K lines) |
| `SWFModernRuntime/include/actionmodern/action.h` | Function declarations |
| `SWFModernRuntime/include/actionmodern/variables.h` | ActionVar struct |
| `SWFModernRuntime/include/actionmodern/stackvalue.h` | Type enum |
| `SWFRecomp/src/action/action.cpp` | Bytecode → C translator |

### SWF specification

The SWF file format specification (version 19) is at `SWFRecompDocs/specs/swf-spec-19.txt`. Use this as the authoritative reference for tag formats, bytecode opcodes, and data structures.

## Test Infrastructure Reference

### Ruffle test files

| Path | Purpose |
|------|---------|
| `ruffle-tests/verify_output.py` | Main test runner (single or batch) |
| `ruffle-tests/run_tests.py` | Quick recompiler-only check (no runtime) |
| `ruffle-tests/filter_results.py` | Removes ignored tests from results |
| `ruffle-tests/ignored_tests.txt` | 125 tests to ignore (interactive, network, etc.) |
| `ruffle-tests/download_tests.sh` | Downloads Ruffle test SWFs via sparse git checkout |
| `scripts/diff_ruffle_results.py` | Compares two result JSON files, generates diff |
| `scripts/generate_ruffle_results_markdown.py` | Generates markdown reports from results |
| `.github/workflows/ruffle-tests.yml` | CI workflow (manual dispatch, 1 or 10 shards) |

### Result files

| Path | Purpose |
|------|---------|
| `ruffle-tests/results.json` | Full raw results (616 tests) |
| `ruffle-tests/results_filtered.json` | After removing ignored tests (491 tests) |
| `ruffle-tests/results_diff.json` | JSON diff between previous and current |
| `ruffle-results.md` | Human-readable full report |
| `ruffle-results-filtered.md` | Human-readable filtered report |
| `ruffle-results-diff.md` | Human-readable diff report |

### Test data location

Each test lives in: `ruffle-tests/{test_name}/`
- `test.swf` — the SWF file
- `output.txt` — expected trace output
- `test.toml` — metadata (num_frames, etc.)
- `RecompiledScripts/` — generated C code (created by verify_output.py or run_tests.py)
- `RecompiledTags/` — generated tag code (created by verify_output.py or run_tests.py)

Example: `ruffle-tests/clip_constructors/output.txt`, `ruffle-tests/clip_constructors/RecompiledScripts/script_0.c`

### Running CI

The workflow is manual dispatch only (no auto-trigger). User must go to GitHub Actions → "Ruffle AVM1 Tests" → "Run workflow". Options:
- `parallel`: 1 (single runner) or 10 (parallel shards, faster)
- `limit`: 0 for all tests, or N to run only first N tests

## Old Test System (SWFRecomp/tests/)

**NOTE: Ignore the old test suite until we're finished getting all Ruffle tests passing.** Some old tests may have stale expected values that need updating, but that's lower priority than Ruffle test progress.

There is a separate, older test system in `SWFRecomp/tests/`. These are hand-written opcode-level unit tests (115 tests, ~79 currently passing).

### Key differences from Ruffle tests

| Aspect | Old Tests (`SWFRecomp/tests/`) | Ruffle Tests (`ruffle-tests/`) |
|--------|-------------------------------|-------------------------------|
| **Count** | 115 trace + ~61 graphics | 616 tests |
| **Source** | Hand-written, local SWF generation scripts | Downloaded from Ruffle project |
| **Validation** | Per-test `validate.py` with custom logic | Shared `verify_output.py`, line-by-line diff against `output.txt` |
| **Expected output** | Encoded in `validate.py` (sub-test assertions) | Explicit `output.txt` file |
| **Metadata** | `test_info.json` (opcodes, description) | `test.toml` (num_frames only) |
| **Runner** | `all_tests.sh` (bash, calls `build_test.sh`) | `verify_output.py` (Python, self-contained build) |
| **Build** | `build_test.sh` (supports native + WASM) | `verify_output.py` builds native only (gcc, temp dir) |
| **Results** | `test_results.json` (structured: sub-tests, opcodes, timing) | `results.json` (line-level stats, failure categories) |
| **CI** | None (run locally) | GitHub Actions workflow |

### Old test runner usage

```bash
cd SWFRecomp/tests

# Run all tests
./all_tests.sh

# Run specific test
./all_tests.sh add_swf_4

# Rebuild + run
./all_tests.sh --clean

# Re-run only previously failed
./all_tests.sh --retest

# Build SWFRecomp first if needed
./all_tests.sh --build
```

### Old test structure

Each test in `SWFRecomp/tests/{test_name}/`:
- `test_info.json` — metadata (opcodes tested, description, SWF version)
- `validate.py` — custom validator, reads stdin, outputs JSON with sub-test results
- `test.swf` — or a generation script (`create_test_swf.py`, `generate_swf.py`)
- `config.toml` — SWFRecomp config
- `main.c` — runtime wrapper (usually minimal)
- `RecompiledScripts/` / `RecompiledTags/` — generated C code

### Potential for unification

Both test systems share the same core pipeline: recompile SWF → compile C → run → compare output. The main differences are:

1. **Build mechanism**: Old uses `build_test.sh` (bash), new uses Python `compile_native()`. Both invoke gcc with the same runtime sources and flags.
2. **Output filtering**: Nearly identical boilerplate patterns in both.
3. **Validation**: Old has custom per-test `validate.py` scripts (sub-test granularity); new does simple line-by-line diff against `output.txt`.
4. **Results format**: Different JSON schemas but similar data.

To unify, the old tests would need:
- An `output.txt` file per test (could be generated from existing `validate.py` expected values)
- Or: `verify_output.py` would need to support per-test custom validators (more complex)
- The old `test_info.json` metadata (opcodes, description) has no Ruffle equivalent and would need to be preserved or dropped
