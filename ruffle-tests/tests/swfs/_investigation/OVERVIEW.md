# Test Suite Overview

Cross-suite summary of all Ruffle-derived test suites. Each suite has its own `_investigation/` directory with detailed status docs.

Last updated: 2026-04-21 (CI run at 7155a774, ruffle-test-results 41667cc4)

## Suite Summary

"Effective pass" = raw pass + `ruffle_matched` (diffs ⊆ Ruffle's diffs against Flash; auto-promoted when upstream has `known_failure=true` + `output.ruffle.txt`).

| Suite | Tests | Pass | RM | Effective | Effective Rate | Filtered Rate | Notes |
|-------|-------|------|----|-----------| ---------------|---------------|-------|
| [avm1](../avm1/_investigation/CURRENT_STATUS.md) | 641 | 597 | 9 | 606 | 94.5% | **100.0%** (600/600) | 41 ignored. **Zero filtered failures.** Unchanged vs 2026-04-18; one test reclassified pass→RM. |
| [from_gnash/actionscript.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 190 | 110 | 49 | 159 | **83.7%** | — | +26 effective since 2026-04-18. Mostly from String-vN ruffle-match, with-v6/v7/v8 fixes, and primitive auto-boxing. |
| [from_gnash/misc-mtasc.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 9 | 7 | 1 | 8 | **88.9%** | — | 1 remaining failure (`levels` — multi-level SWF loading). |
| [from_gnash/misc-swfmill.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 18 | 15 | 1 | 16 | **88.9%** | — | 2 remaining (`jump_to_prev_block`, `tags_after_last_showframe`). |
| [from_gnash/misc-ming.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 102 | 19 | 11 | 30 | 29.4% | — | Blocked: inlined Dejagnu DoInitAction. |
| [from_gnash/misc-swfc.all](../from_gnash/_investigation/CURRENT_STATUS.md) | 16 | 3 | 3 | 6 | 37.5% | — | Blocked: inlined Dejagnu DoInitAction. |
| [from_shumway](../from_shumway/_investigation/CURRENT_STATUS.md) (flat) | 92 | 61 | 1 | 62 | 67.4% | — | Grew 47→92 (now includes avm1/ + fuzz/ + timeline/ sub-trees). |
| [from_shumway/avm1](../from_shumway/_investigation/CURRENT_STATUS.md) | 47 | 45 | 1 | 46 | **97.9%** | **100.0%** (45/45) | 2 ignored. Only `moviecliploader` remains (MCL one-tick deferral). |
| **SWFRecomp/tests** (old suite) | 158+59 | all trace pass | — | — | **100%** | — | Hand-written opcode tests. CI only. |

## Progress Since 2026-04-18

- **ACTION_QUEUE_PLAN** — multi-phase architectural rework landing a Ruffle-style unified ActionQueue (Phases 0–8 all landed, plan marked complete at commit fe74d7aa). Motivated by `from_shumway/avm1/doactionorder` and timeline execution-order parity; enabled subsequent gnash and shumway fixes.
- **String wrapper dispatch + ruffle-match** (Gnash) — d05bbd56, f70ecdb0, 41f62c81. String-vN tests auto-promoted to `ruffle_matched` via stubbed call/apply, DontDelete, constructor, override, direct method dispatch, and enumerate fallback.
- **with-v6/v7/v8 → `ruffle_matched`** (Gnash) — 73983b0e + 7155a774 (latest CI delta). Two fixes: (a) `actionASSetPropFlags_func2` MOVIECLIP handling + WRITABLE check in WITH-scope assignment, (b) `resolveObjectPathToMC` walks dotted/colon paths via property lookup with `__proto__` fallback. Eliminated ~14 stray `Target not found`/`FAILED _target==` lines per test.
- **`depth_replacement_audio_unloading` PASS** (AVM1) — `verify_output.py` extracts all 14 raw-data arrays from a child SWF's `draws.c` and prefixes them; `actionFirePendingLoadInits` Phase 2 saves/restores `is_playing` so a child's `stop()` doesn't terminate the parent's frame loop.
- **`function_as_function` PASS** (AVM1) — `Function()` without `new` returns a bare object with no `__proto__`.
- **`bitmap_data_thorough/*` final cleanup** (AVM1) — suite now 16 PASS + 3 ruffle_matched + 1 accepted (pixelDissolve). All plan work complete.

## Progress Since 2026-03-19

### Shumway flat suite: Complete — 15/17 → 17/17 (100% AVM1)

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

### AVM1: Image test progress (2026-04-01)

- **Alpha blend fix** — Porter-Duff alpha blend factor corrected (SrcAlpha → One). Fixes `color` image test (30000 outlier channels → 0, max diff 48 → 1).
- **Stage.width/height init** — Was 0, now FRAME_WIDTH/FRAME_HEIGHT. Fixes Drawing API layout in `movieclip_setmask` (202K → 10K outliers).
- **Headless image test status**: 3 strict pass, 6 tolerance pass (was 12/31 strict + 10/31 tolerance before recompile; many tests had stale generated files).
- **RUNTIME_TRANSFORM_GPU and RUNTIME_CXFORM_GPU plans completed** (both already working, moved to complete/).
- **_global plain property resolution** — GetVariable now finds plain properties on _global in root context. Enables Gnash misc-mtasc AS2 class resolution.

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
- `from_shumway/_investigation/CURRENT_STATUS.md` — Flat suite complete (17/17 AVM1), avm1/ at 20/23 (87.0%)
- `from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md` — All actionable items done (9 tests fixed)

## Where to Focus

AVM1 filtered suite is at 100%; remaining actionable work is in the Gnash and Shumway suites.

1. **Gnash actionscript.all near-passing** — 22+ tests with <=18 line diffs. `global_proto_decls*` enumeration/ordering, `Number-v5..v8` float-to-string rounding, `Selection-v6/7/8`, `ExternalInterface-v8`. See `from_gnash/_investigation/incomplete/GNASH_NEAR_PASSING_PLAN.md`.
2. **Gnash `misc-mtasc/levels`** — only 1 failure in that sub-suite; needs multi-level SWF loading (`_level5`, `_level87`, `_level99`). See `LEVELS_PLAN.md`.
3. **Gnash `misc-swfmill`** — 2 remaining timeline-tag-order failures (`tags_after_last_showframe`, `jump_to_prev_block`). ActionQueue rework may have moved these; needs re-verification.
4. **Shumway `avm1/moviecliploader`** — sole remaining filtered failure. One-tick MCL deferral exposes latent getBounds / chained setInterval bugs. See `from_shumway/_investigation/incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md` Part B.
5. **Shumway `fuzz/*`** — 27 fuzzer-generated SWFs failing in the flat suite. Useful as an edge-case discovery source for runtime/recompiler.
6. **AVM1 image tests** — 14/31 strict pass, 10/31 tolerance. Remaining need Drawing API anti-aliasing, text layout, dynamic masks, or external media loading. Tracked in `IMAGE_COMPARISON_TESTS.md`.
7. **Gnash `misc-ming.all` / `misc-swfc.all`** — ~76 of ~83 failing tests are actionable via Phase 1 (near-passing) + Phase 2 (mid-rate cluster fixes); only ~7 zero-output tests are blocked on the inlined-Dejagnu DoInitAction architectural issue (Phase 3). See `incomplete/MISC_MING_SWFC_PLAN.md`.
