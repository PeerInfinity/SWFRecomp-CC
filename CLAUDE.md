# SWFRecomp-CC Project Instructions

## Current Focus: Ruffle AVM1 Test Suite

We are improving the pass rate on the Ruffle AVM1 test suite (ActionScript 1/2 trace tests).

**Key docs to read at session start:**
- `ruffle-tests/_investigation/SESSION_START_GUIDE.md` — stable reference (architecture, how to run tests, infrastructure)
- `ruffle-tests/_investigation/CURRENT_STATUS.md` — current results, regressions, near-passing tests, work priorities

**Quick test commands:**
```bash
# Run a single Ruffle test locally
python3 ruffle-tests/verify_output.py --test=TEST_NAME --diff --verbose

# Do NOT run full suite locally — commit changes, then user triggers CI
```

## Project Structure

- `SWFRecomp/` — Recompiler: converts SWF bytecode to C (`src/action/action.cpp` is the main bytecode→C translator)
- `SWFModernRuntime/` — Runtime: executes the generated C (`src/actionmodern/action.c` is ~10K lines, the core runtime)
- `ruffle-tests/` — Ruffle AVM1 test suite (616 tests, each in `ruffle-tests/{test_name}/`)
- `SWFRecomp/tests/` — Old hand-written test suite (115 trace tests + 61 graphics tests, all passing)
- `SWFRecomp/scripts/` — Build scripts (build_test.sh, deploy_example.sh, etc.)
- `scripts/` — Test result processing scripts (diff, markdown generation)

## Two Test Systems

1. **Ruffle tests** (`ruffle-tests/`): 616 tests from Ruffle project. Shared runner `verify_output.py`. Expected output in `output.txt` per test. Results in `results.json`. CI via GitHub Actions workflow (manual dispatch).

2. **Old tests** (`SWFRecomp/tests/`): 115 hand-written tests. Per-test `validate.py` validators. Runner is `all_tests.sh`. Results in `test_results.json`. Run locally only.

## Critical Runtime Architecture Notes

- `ASObject` and `ASFunction` are **different structs** — never cast one to the other. Functions have `prototype_obj` and `own_props` fields; objects have a `properties` array. Code that handles both types must check the ActionVar type tag first.
- Stack is a byte buffer with PUSH/POP macros. String values store a pointer (not inline data) at offset +16.
- Type system: `ActionVar` with type tag (`ACTION_STACK_VALUE_STRING=0, F32=1, NULL=2, UNDEFINED=3, BOOLEAN=5, F64=6, OBJECT=11, ARRAY=12, FUNCTION=13, MOVIECLIP=14`)
- Scope resolution: WITH scope chain → global variables → undefined
- `emsdk_env.sh` is at `SWFRecomp-CC/emsdk/emsdk_env.sh`
- Build scripts are under `SWFRecomp/scripts/`, NOT project root `scripts/`
