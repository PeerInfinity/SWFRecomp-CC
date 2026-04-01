# Test Session Start Guide

Read this document at the start of each session to get up to speed quickly.

## How to Check Current Status

1. Read `ruffle-tests/tests/swfs/_investigation/OVERVIEW.md` — cross-suite summary (pass rates, key findings, where to focus)
2. Read the `CURRENT_STATUS.md` for whichever suite you're working on:
   - `ruffle-tests/tests/swfs/avm1/_investigation/CURRENT_STATUS.md` — AVM1 (Ruffle): plan status, remaining work
   - `ruffle-tests/tests/swfs/from_gnash/_investigation/CURRENT_STATUS.md` — Gnash: segfaults, compile failures, near-passing
   - `ruffle-tests/tests/swfs/from_shumway/_investigation/CURRENT_STATUS.md` — Shumway: AVM1 vs AVM2 classification
3. Read `ruffle-tests/tests/swfs/avm1/_investigation/SESSION_NOTES.md` — historical session-by-session notes

### Per-suite result files

Each suite stores results in its own `_results/` directory:

| Suite | Results Directory |
|-------|-------------------|
| AVM1 (Ruffle) | `ruffle-tests/tests/swfs/avm1/_results/` |
| Gnash actionscript.all | `ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/` |
| Gnash misc-swfmill.all | `ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/` |
| Shumway (flat) | `ruffle-tests/tests/swfs/from_shumway/_results/` |
| Shumway (avm1 subdir) | `ruffle-tests/tests/swfs/from_shumway/avm1/_results/` |

Each `_results/` directory contains: `results.json`, `results.md`, `results_filtered.json` (if ignore list exists), `results_filtered.md`, `results_diff.json`, `results_diff.md`.

### Cross-suite reference documents

| Document | Purpose |
|----------|---------|
| `_investigation/FEATURE_SCOPE.md` | Which features are implemented vs. not, and why |
| `_investigation/HEADLESS_SETUP.md` | How to set up Dawn, lavapipe, and Pillow for headless image tests |

### AVM1-specific reference documents

| Document | Purpose |
|----------|---------|
| `avm1/_investigation/ACCEPTED_DIFFS.md` | Tests with permanently unfixable diffs (Flash UB, platform UB, Ruffle test bugs) |
| `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` | Tests where Ruffle's expected output disagrees with Flash Player |
| `ruffle-tests/ignored_tests.txt` | ~56 AVM1 tests excluded from filtered results |

## How to Run Tests

### Build the recompiler (once per session, or after changes)

```bash
cd SWFRecomp/build && cmake .. && make -j$(nproc) && cd ../..
```

### Download test SWFs (once per machine)

```bash
cd ruffle-tests && bash download_tests.sh && cd ..
```

### Run a single test locally

```bash
# AVM1 (Ruffle) — default (trace-only)
python3 ruffle-tests/verify_output.py --test=TEST_NAME --diff --verbose

# Gnash actionscript.all
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_gnash/actionscript.all --test=TEST_NAME --diff --verbose

# Gnash misc-swfmill.all
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all --test=TEST_NAME --diff --verbose

# Shumway
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_shumway --test=TEST_NAME --diff --verbose
```

### Run multiple tests

```bash
python3 ruffle-tests/verify_output.py --test=test1 --test=test2 --diff --verbose
```

### Run headless image tests

Some tests have `[image_comparisons]` sections in their `test.toml` that compare
rendered frames against expected PNGs. These require the `--headless` flag and
additional dependencies (Dawn WebGPU library, lavapipe Vulkan driver, Pillow).

```bash
# Single image test
python3 ruffle-tests/verify_output.py --test=TEST_NAME --headless --diff --verbose

# Run all image tests via dedicated runner
python3 ruffle-tests/run_image_tests.py
```

See `HEADLESS_SETUP.md` for full setup instructions (Dawn build, lavapipe
install, Pillow). Without Dawn installed at `~/CC/dawn-install/`, the
`--headless` flag will error. Trace output is still checked in headless mode
alongside image comparisons.

### Full test suites (use CI only)

**IMPORTANT: Do NOT run full test suites locally.** Use CI workflows instead:

1. Commit your changes to master
2. Go to GitHub Actions → "Ruffle AVM1 Tests" → "Run workflow"
3. Choose a category:
   - `all` — run all suites
   - `avm1` — AVM1 (Ruffle) only
   - `no_gnash` — AVM1 + Shumway (skips slow Gnash suite)
   - `from_shumway` — Shumway only
   - `from_gnash` — Gnash only
4. Options: `parallel` (1 or 10 shards), `limit` (0 for all, or N for first N tests)
5. Results are committed to the `ruffle-test-results` branch
6. After the run, merge `ruffle-test-results` into master to update result files

Other CI workflows:
- **"SWFRecomp CI"** — runs the old hand-written test suite (+ WASM builds, opcode docs)
- **"Run All Tests"** — triggers both old and Ruffle/Gnash/Shumway suites together

## Architecture Overview

### Two-stage pipeline: Recompiler → Runtime

1. **SWFRecomp** (`SWFRecomp/src/action/action.cpp`, ~2000 lines) — Reads SWF bytecode, emits C code
   - Two-pass: first pass identifies jump targets, second pass emits C
   - Each ActionScript bytecode op → a C function call (e.g., `ActionAdd` → `actionAdd(app_context)`)
   - Stack-based: all operations use PUSH/POP macros on a byte buffer
   - Generates: `RecompiledScripts/script_N.c` and `RecompiledTags/tagMain.c`

2. **SWFModernRuntime** (`SWFModernRuntime/src/actionmodern/action.c`, ~50000 lines) — Executes the generated C
   - Implements all the `action*()` functions
   - Type system: `ActionVar` struct with 15 types (string, f32, f64, null, undefined, boolean, object, array, function, movieclip, etc.)
   - Object system: `ASObject` (property bags), `ASFunction` (with prototype), `ASArray`
   - Scope chain: `scope_chain[MAX_SCOPE_DEPTH]` array for WITH/function scoping
   - Variable resolution: WITH scope → global scope → undefined

### Key runtime files

| File | Purpose |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | Main runtime (~50K lines) |
| `SWFModernRuntime/include/actionmodern/action.h` | Function declarations |
| `SWFModernRuntime/include/actionmodern/variables.h` | ActionVar struct |
| `SWFModernRuntime/include/actionmodern/stackvalue.h` | Type enum |
| `SWFRecomp/src/action/action.cpp` | Bytecode → C translator |

### SWF specification

The SWF file format specification (version 19) is at `SWFRecompDocs/specs/swf-spec-19.txt`. Use this as the authoritative reference for tag formats, bytecode opcodes, and data structures.

## Test Infrastructure Reference

### Shared test runner

All suites use the same runner: `ruffle-tests/verify_output.py`. The `--tests-dir` flag selects which suite to run against. Without it, the default is `ruffle-tests/tests/swfs/avm1/`.

| Path | Purpose |
|------|---------|
| `ruffle-tests/verify_output.py` | Main test runner (single or batch, all suites) |
| `ruffle-tests/run_tests.py` | Quick recompiler-only check (no runtime) |
| `ruffle-tests/filter_results.py` | Removes ignored tests from results |
| `ruffle-tests/download_tests.sh` | Downloads test SWFs via sparse git checkout |
| `scripts/diff_ruffle_results.py` | Compares two result JSON files, generates diff |
| `scripts/generate_ruffle_results_markdown.py` | Generates markdown reports from results |
| `.github/workflows/ruffle-tests.yml` | CI workflow (manual dispatch, supports all suites) |

### Test data layout

Each test lives in its suite's directory (e.g., `ruffle-tests/tests/swfs/avm1/{test_name}/`):
- `test.swf` — the SWF file
- `output.txt` — expected trace output
- `test.toml` — metadata (num_frames, etc.)
- `RecompiledScripts/` — generated C code (created by verify_output.py)
- `RecompiledTags/` — generated tag code (created by verify_output.py)

### Suite-specific notes

**Gnash tests** include `Dejagnu.swf` as a child movie (SWF5 test harness). This is automatically handled by verify_output.py as a child SWF. The Dejagnu harness provides `check()`, `xcheck()`, and `note()` functions that emit trace output in a standardized format.

**Shumway tests** are a mix of AVM1 and AVM2 SWFs. The 30 AVM2/AS3 tests cannot be executed by our AVM1 recompiler and should be ignored.

### Local Ruffle repository

If running locally, the Ruffle source repository is available at `~/CC/ruffle`. This can be useful for inspecting test source code, understanding expected behavior, or checking how Ruffle implements specific features.

## Old Test System (SWFRecomp/tests/)

There is a separate, older test system in `SWFRecomp/tests/`. These are hand-written opcode-level unit tests (~158 trace tests + ~59 graphics tests). All trace tests pass.

### Key differences from Ruffle-derived tests

| Aspect | Old Tests (`SWFRecomp/tests/`) | Ruffle-derived Tests (`ruffle-tests/`) |
|--------|-------------------------------|-------------------------------|
| **Count** | ~158 trace + ~59 graphics | ~870 tests across 4 suites |
| **Source** | Hand-written, local SWF generation scripts | Downloaded from Ruffle, Gnash, Shumway projects |
| **Validation** | Per-test `validate.py` with custom logic | Shared `verify_output.py`, line-by-line diff against `output.txt` |
| **Expected output** | Encoded in `validate.py` (sub-test assertions) | Explicit `output.txt` file |
| **Metadata** | `test_info.json` (opcodes, description) | `test.toml` (num_frames only) |
| **Runner** | `all_tests.sh` (bash, calls `build_test.sh`) | `verify_output.py` (Python, self-contained build) |
| **Build** | `build_test.sh` (supports native + WASM) | `verify_output.py` builds native only (gcc, temp dir) |
| **Results** | `test_results.json` (structured: sub-tests, opcodes, timing) | `results.json` per suite (line-level stats, failure categories) |
| **CI** | "SWFRecomp CI" workflow | "Ruffle AVM1 Tests" workflow (covers all suites) |

### Running old tests

Do NOT run the old test suite locally. Use CI workflows instead. If you must run a single old test locally for debugging:
```bash
cd SWFRecomp/tests
./all_tests.sh --build test_name_here
```

### Old test structure

Each test in `SWFRecomp/tests/{test_name}/`:
- `test_info.json` — metadata (opcodes tested, description, SWF version)
- `validate.py` — custom validator, reads stdin, outputs JSON with sub-test results
- `test.swf` — or a generation script (`create_test_swf.py`, `generate_swf.py`)
- `config.toml` — SWFRecomp config
- `main.c` — runtime wrapper (usually minimal)
- `RecompiledScripts/` / `RecompiledTags/` — generated C code
