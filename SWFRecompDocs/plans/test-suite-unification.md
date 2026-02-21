# Test Suite Unification

**Status: Deferred** — not worth doing while Ruffle test pass rate is the active focus.

## Context

There are two test systems:

1. **Old tests** (`SWFRecomp/tests/`): 115 trace + ~61 graphics hand-written opcode-level unit tests. Per-test `validate.py` with sub-test granularity. Runner: `all_tests.sh` + `build_test.sh`. All 115 trace tests pass (477/477 sub-tests).

2. **Ruffle tests** (`ruffle-tests/`): 616 integration tests from the Ruffle project. Line-by-line diff against `output.txt`. Runner: `verify_output.py`. CI via GitHub Actions.

Both share the same core pipeline: recompile SWF → compile C → run → compare output.

## Why not unify now

The systems serve different purposes and the overlap is smaller than it appears:

- **Old tests** are opcode-level unit tests with custom validators that check semantic correctness (sub-test granularity, float tolerance, set membership, regex matching). They exercise specific edge cases.
- **Ruffle tests** are integration tests with simple line diffs. They test real-world ActionScript behavior from an external project.

Merging would require either dumbing down old tests to line diffs (losing sub-test diagnostics) or adding validator support to `verify_output.py` (complexity for 616 tests that don't need it).

The build pipelines are already nearly identical — both compile the same runtime sources with gcc and `-DNO_GRAPHICS`. The differences (WASM/graphics support in old tests, MAX_FRAMES/MOCK_DATE_TIME in Ruffle tests) are features each system needs independently. Sharing a build function would save ~50 lines of code but add coupling.

Time spent on infrastructure unification is time not spent fixing Ruffle test failures.

## Key differences

| Aspect | Old Tests | Ruffle Tests |
|--------|-----------|--------------|
| Count | 115 trace + ~61 graphics | 616 |
| Source | Hand-written, local SWF generation | Downloaded from Ruffle project |
| Validation | Per-test `validate.py` (sub-test assertions) | Line-by-line diff against `output.txt` |
| Metadata | `test_info.json` (opcodes, description) | `test.toml` (num_frames, mock_date_time) |
| Runner | `all_tests.sh` (bash) | `verify_output.py` (Python) |
| Build | `build_test.sh` (native + WASM, graphics + no-graphics) | `compile_native()` (native only, no-graphics only) |
| CI | None (run locally) | GitHub Actions (manual dispatch) |

## If unification becomes worthwhile

The cheapest path would be a one-time migration:

1. Generate `output.txt` files from existing old test validators (run each test, capture output)
2. Add `test.toml` files to old tests (from existing `test_info.json` metadata)
3. Run old tests through `verify_output.py` alongside Ruffle tests
4. Keep `validate.py` scripts as optional secondary validation (sub-test diagnostics)

This avoids rewriting either runner and preserves both validation approaches.

### What would be lost

- Graphics test support (if unified on NO_GRAPHICS-only)
- Opcode coverage metadata from `test_info.json`
- SWF regeneration from `create_test_swf.py` scripts
- Sub-test diagnostics (unless validators are kept alongside `output.txt`)

### What would be gained

- Single CI workflow for both suites
- Unified result reporting
- ~50 fewer lines of duplicated build logic

## Trigger conditions

Revisit this plan if:
- Old tests need CI integration (currently local-only is fine since they all pass)
- A third test source is added (consolidation becomes more valuable)
- Major build pipeline changes are needed anyway (opportunistic unification)
