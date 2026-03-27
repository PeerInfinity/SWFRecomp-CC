# Test Suite Overview

Cross-suite summary of all Ruffle-derived test suites. Each suite has its own `_investigation/` directory with detailed status docs.

Last updated: 2026-03-23 (CI run on 15ce3f06)

## Suite Summary

| Suite | Tests | Passing | Rate | Filtered Rate | Notes |
|-------|-------|---------|------|---------------|-------|
| [avm1](../avm1/_investigation/CURRENT_STATUS.md) | 619 | 558 | 90.1% | **97.2%** (558/574) | Mature. Near-ceiling. |
| [from_gnash/actionscript.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 190 | ~61 | ~32.1% | **~33.7%** (~61/181) | 9 accepted-diff tests ignored. +3 from Color fixes. |
| [from_gnash/misc-swfmill.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 14 | 11 | **78.6%** | — | 3 blocked on architecture. |
| [from_shumway](../from_shumway/_investigation/CURRENT_STATUS.md) | 47 | 17 | 36.2% | **100.0%** (17/17) | **Complete.** All AVM1 tests pass. 30 AVM2 ignored. |
| **SWFRecomp/tests** (old suite) | 158+59 | all trace pass | **100%** | — | Hand-written opcode tests. CI only. |

## Progress Since 2026-03-19

### Shumway: Complete — 15/17 → 17/17 (100% AVM1)

Two fixes (commit 3b075cff):
1. **targetPath1** — MC `toString()` fallback to `MovieClip.prototype` → `Object.prototype` chain
2. **doubleAndRegister** — `registerClass` char_id-based lookup for multi-export sprites

Ignore list created for 30 AVM2/AS3 tests. Suite is complete.

### Gnash: Phase 1b complete, ignore list created

Phase 1b fixes (Math, ops, Error edge cases) applied. 9 tests with all-accepted diffs (Gnash bugs) added to ignore list. Line-level match improved from 65.0% → 69.1% (unfiltered) / 66.3% (filtered).

### Gnash: Phase 2 in progress (2026-03-23)

Phase 2 fixes applied (commit 15ce3f06):
- **Built-in prototype own toString/valueOf** — DONE. Number/String/Boolean prototypes now have own valueOf/toString distinct from Object.prototype. Line-level improvements across 15 tests: toString_valueOf +12 lines each, Number +2, String +1-3.
- **Function.prototype.apply/call** — DONE. Registered as own properties on Function.prototype.
- **Object.prototype.constructor** — DONE. Set constructor → Object on Object.prototype.

Note: Boolean-v5/v6/v7/v8, Video-v6/v7/v8, Selection-v5, Stage-v5 were already passing from Phase 1 fixes (CURRENT_STATUS.md was stale).

### Gnash: Phase 2 continued (2026-03-25)

- **Color valueOf + constructor target** — DONE. Color.setTransform/setRGB use `varToDoubleSWF` for valueOf on Number objects. Color constructor stores raw target argument as own property. Color-v5: 14→4 failures (-10), Color-v7/v8: 18→8 each (-10).
- **Stage/Selection non-constructable** — Stage-v5 already passes. Selection-v6/v7/v8 have deeper issues beyond non-constructable.

### AVM1: tab_ordering_properties_tab_index_edge_case (2026-03-25)

- **tabIndex string storage** — DONE. tabIndex setter now stores string values as-is (Flash behavior) instead of discarding non-numeric values. New PASS: tab_ordering_properties_tab_index_edge_case.

### AVM1 + Gnash fixes (2026-03-26)

- **Array.join HOLE→"undefined"** — DONE. Array.join/toString now correctly converts HOLE (unset) elements to "undefined" instead of empty string. Fixes 4 AVM1 tests: array_constructor, array_properties, external_interface_toxml_basic, global_array.
- **verify_output.py UTF-8 error handling** — DONE. Added `errors="replace"` to output.txt reads. Fixes string_relational_compare runtime_error → output_mismatch.
- **XMLSocket.connect returns false** — DONE. Fixes 4 Gnash tests: XMLSocket-v5/v6/v7/v8.

### Gnash: Color fixes (2026-03-27)

- **Color target toString() resolution** — DONE. Color methods now call toString() on object targets at each invocation. Fixes Color-v5.
- **Dynamic MC color transform** — DONE. Added cx_* fields to MovieClip struct for createEmptyMovieClip MCs. Fixes Color-v5/v7/v8.
- **_alpha / Color transform dual quantization** — DONE. _alpha getter uses roundf; cx_aa uses integer truncation (setTransform path). Fixes Color-v7/v8. Color-v6 improved to 97.6% (4 remaining: typeof(c)=='undefined').

## Per-Suite Docs

### avm1 (Ruffle)
- `avm1/_investigation/CURRENT_STATUS.md` — Current pass rates, plan status, remaining work
- `avm1/_investigation/SESSION_NOTES.md` — Historical session-by-session fix notes
- `avm1/_investigation/FAILING_TESTS_BY_FEATURE.md` — Failures by feature category
- `avm1/_investigation/REMAINING_FAILURES_ANALYSIS.md` — Detailed remaining failure analysis
- `avm1/_investigation/BLOCKER_SUMMARY.md` — Active and resolved blockers
- `avm1/_investigation/ACCEPTED_DIFFS.md` — Tests with permanently unfixable diffs
- `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` — Where we match Flash but not Ruffle

### from_gnash
- `from_gnash/_investigation/CURRENT_STATUS.md` — Pass rates, Phase 1/2/3 work order
- `from_gnash/_investigation/FAILING_TESTS_BY_FEATURE.md` — All 152 failures by root cause / feature
- `from_gnash/_investigation/REMAINING_FAILURES_ANALYSIS.md` — Tiered analysis with effort estimates
- `from_gnash/_investigation/BLOCKER_SUMMARY.md` — Active and resolved blockers

### from_shumway
- `from_shumway/_investigation/CURRENT_STATUS.md` — **Complete** (17/17 AVM1, 30 AVM2 ignored)

## Where to Focus

1. **Gnash Phase 2 fixes** (Color, Inheritance, toString_valueOf) — targeted fixes for near-passing tests at 80-95% match rate.
2. **AVM1 suite** is at 97.2% filtered and remaining failures are blocked or diminishing-returns.
3. **Shumway** is complete (100% AVM1).
