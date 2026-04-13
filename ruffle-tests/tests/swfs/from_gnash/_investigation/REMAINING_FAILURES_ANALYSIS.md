# Gnash Remaining Failures Analysis

Original: 2026-03-19 at 52/204 passing. **Partially refreshed 2026-04-12** — the
bulk of Tier 1 and several Tier 2/3 groups have been resolved since the
original analysis; current actionscript.all state is 95/190 (50.0%) and the
full suite totals 124/287 (43.2%). See `CURRENT_STATUS.md` for authoritative
per-group numbers and `incomplete/GNASH_FEATURE_PLAN.md` for live phase
tracking. Tier 2/3/4 entries below that have not been refreshed should be
treated as approximate — the overall *shape* of the remaining work (which
classes need attention) is still useful but individual match rates may be
off by 10-20 percentage points.

This document groups remaining failures by actionability and estimated effort.

## Summary by Tier

| Tier | Tests | Description |
|------|-------|-------------|
| Tier 1: Near-passing | 8 | >95% match — trivial fixes |
| Tier 2: Close | ~25 | 80-95% match — targeted fixes |
| Tier 3: Medium | ~60 | 50-80% match — feature work needed |
| Tier 4: Low / Hard | ~45 | <50% match — significant effort |
| Crashes | 7 | Segfaults and runtime errors |
| Misc-SWFMill | 6 | Independent edge cases |

---

## Tier 1: Near-Passing (>95% match) — mostly RESOLVED as of 2026-04-12

### ~~Math-v5/v6/v7/v8~~ — RESOLVED via ACCEPTED_DIFFS

Remaining diffs are Gnash bugs (`Math.pow(1)` returns NaN in Gnash, `SQRT2`
precision mismatch). All 4 tests are in `ignored_tests.txt` as fully
accepted diffs. See `ACCEPTED_DIFFS.md` → Category 1.

### ~~ops-v8~~ — RESOLVED via ACCEPTED_DIFFS

Remaining 5 NaN-comparison diffs are platform-dependent IEEE 754 NaN bit
patterns. Accepted. See `ACCEPTED_DIFFS.md` → Category 1.

### ~~NetStream-v6/v7/v8~~ — PASS (2026-04-09)

NetStream constructor now installs `currentFps` on prototype when
constructed with a connected NetConnection. See
`complete/NETSTREAM_NATIVE_PROPS_PLAN.md`.

### ~~Error-v5/v6/v7/v8~~ — PASS (2026-04-10)

Error constructor now stores raw argument value instead of coercing non-string
args to string. All 4 tests PASS.

### ~~delete-v5/v6/v7/v8~~ — PASS (2026-04-09..12)

Dot-path resolution in `actionDelete2` and `actionDelete`, plus global-object
fallback routing fixes. All 4 tests PASS.

### ~~LocalConnection-v6/v7/v8~~ — PASS (2026-04-12)

`lc_is_protected_method` now case-insensitive and includes `onStatus`.

### ~~ColorTransform-v8~~ — PASS (2026-04-12)

`rgb` getter drops `& 0xFF` masking; constructor defaults to identity and
coerces via `varToDoubleSWF`.

### ~~Color-v5/v6/v7/v8~~ — PASS except Color-v6 (97%)

Dynamic MC color transform, valueOf in setTransform, target property storage
fixes. Only Color-v6 remains (4 lines: `typeof(c) == 'undefined'` for SWF6+).

### ~~Stage-v5, Selection-v5, Boolean-v5/v6/v7/v8, Video-v6/v7/v8~~ — PASS (Phase 1)

Already passing since the early Phase 1 fixes.

---

## Tier 2: Close (80-95% match)

### ~~Color-v5/v7/v8~~ — PASS. Color-v6 ~97% (4 lines remain)

Only remaining failures: `typeof(c) == 'undefined'` for non-constructable
Color in SWF6+.

### TextFieldHTML — v6/v7/v8 (86.5%, 32/37)

5 diff lines each. HTML text getter edge cases. Same issues tracked in AVM1 suite's TEXTFIELD_PLAN.

### Selection — v6/v7/v8 (~86%)

Selection-v5 is PASS. v6-v8 remain: Selection non-constructable + `_listeners`
own property + `instanceof Array` on listener arrays.

### Inheritance — v5 (~82%), v6 (~85%), v7/v8 (output_mismatch, not segfault)

OOP prototype chain issues: constructor execution ordering, `instanceof`,
`__constructor__` setup, `Function.prototype` visibility. v7/v8 are now
`output_mismatch` with ~2 diff lines + 1 extra trailing line that the test
intentionally doesn't expect (Flash hangs on the last line; we don't).

### ~~Stage-v5~~ — PASS (Phase 1)

### Point-v8 (84.5%, 163/193)

30 diff lines. Point class method edge cases, likely `equals`, `distance`, `interpolate` with NaN/Infinity args.

### Matrix-v8 (82.7%, 139/168)

29 diff lines. Matrix class method edge cases.

### case-v5 (82.1%, 32/39)

7 diff lines. Switch/case comparison semantics — likely strict vs abstract equality.

### ColorTransform-v8 (81.8%, 45/55)

10 diff lines. ColorTransform method edge cases at SWF8.

### HitTest — v6 (79.5%), v7 (79.5%), v8 (80.7%)

17-18 diff lines. HitTest accuracy — overlaps with AVM1 suite's shape hitTest work.

### Rectangle-v8 (79.5%, 132/166)

34 diff lines. Rectangle class method edge cases.

---

## Tier 3: Medium (50-80% match) — ~60 tests

These tests require feature implementation work, not just edge case fixes.

| Group | Tests | Match Range | Primary Issue |
|-------|-------|-------------|---------------|
| Number v5-v8 | 4 | ~85-96% (2026-04-09) | Wrapper valueOf override, float precision last-digit at e±308, toFixed/toPrecision |
| ~~Error v5-v8~~ | — | **PASS** (2026-04-10) | Error constructor raw message storage |
| AsBroadcaster v5-v8 | 4 | 70-79% | Listener dispatch, broadcastMessage |
| TextSnapshot v6-v8 | 3 | ~93% (2026-04-12) | ~10 lines accepted (Gnash expects string from empty native TS — see ACCEPTED_DIFFS); ~3 state-dependent `gh.getCount() == undefined` lines still investigable |
| toString_valueOf v5-v8 | 4 | 60-77% | valueOf/toString on arrays, ASArray cast bug |
| Global v6-v8 | 3 | 70-76% | Missing global properties/constructors |
| TextFormat v5-v7 | 3 | 64-78% | Constructor coercion, property getters |
| ContextMenu v7-v8 | 2 | 72.5% | customItems, builtInItems |
| Sound v5-v8 | 4 | 63-77% | attachSound, volume, Sound prototype |
| flash v5-v7 | 3 | 70.0% | flash.geom constructor stubs |
| ExternalInterface v6-v8 | 3 | 51-70% | addCallback, data marshalling |
| MovieClip-v5 | 1 | 65.0% | Many MC methods |
| ~~delete v5-v8~~ | — | **PASS** (2026-04-09..12) | Dot-path resolution, global-object fallback |
| TextField-v5 | 1 | 66.7% | TextField properties |
| Instance v5-v8 | 4 | 52-64% | instanceof, constructor, typeof |
| String v5-v8 | 4 | 59-61% | Missing methods (replace, match, search) |
| Mouse v5-v8 | 4 | 57-62% | Mouse listener methods |
| Microphone v6-v8 | 3 | 60.8% | Prototype properties |
| Accessibility v6-v8 | 3 | 47-53% | isActive, prototype properties |
| BitmapData-v8 | 1 | 52.5% | Advanced BitmapData methods |

---

## Tier 4: Low Match / Hard (<50% match) — ~45 tests

These tests require significant new feature implementation.

| Group | Tests | Match Range | Primary Issue |
|-------|-------|-------------|---------------|
| enumerate v6-v8 | 3 | 44.9% | for-in enumeration broken |
| LoadVars v6-v8 | 3 | 44.1% | Network loading (load/send/decode) |
| ~~LocalConnection v6-v8~~ | — | **PASS** (2026-04-12). v5 still failing | lc_is_protected_method case-insensitive fix |
| System v5-v8 | 4 | 38-40% | System.capabilities |
| Camera v6-v8 | 3 | 36.7% | Camera prototype |
| targetPath v6-v8 | 3 | 32.1% | targetPath for nested MCs |
| with v5-v8 | 4 | 18-30% | Auto-boxing primitives, scope chain |
| ASnative v5-v8 | 4 | 26-28% | Many missing ASnative classes |
| Key v5-v8 | 4 | 20-27% | Key object, keyboard input |
| case v6-v8 | 3 | 19-25% | Complex switch patterns |
| Matrix v6-v7 | 2 | 23-25% | Matrix class (SWF6/7 path) |
| MovieClipLoader v7-v8 | 2 | 27.9% | loadClip, events |

---

## Crashes — mostly RESOLVED (2026-04-12)

| Test | Type | Status |
|------|------|--------|
| ~~Inheritance-v7~~ | ~~Segfault~~ | **output_mismatch** now (2 lines + 1 extra) — segfault fixed |
| ~~Inheritance-v8~~ | ~~Segfault~~ | **output_mismatch** now — segfault fixed |
| ~~Try-v6/v7/v8~~ | ~~Runtime error~~ | **FIXED** — see `complete/TRY_FINALLY_PLAN.md`. Try-v5 does not exist |
| array-v5 | ~~Runtime error~~ | **output_mismatch** now — see `incomplete/ARRAY_V5_PLAN.md` |

---

## Misc-SWFMill Failures — 6 tests

| Test | Match | Issue | Fix |
|------|-------|-------|-----|
| dict_event | 60% (3/5) | Clip event not firing for all frames | Frame event dispatch |
| jump_after_end | 33% (1/3) | Jump past END_OF_ACTIONS | Recompiler bounds check |
| initaction_in_definesprite | 0% (0/2) | InitAction inside sprite not executing | Init action targeting |
| jump_to_prev_block | 0% (0/1) | Backward jump not re-executing | Recompiler control flow |
| tags_after_last_showframe | 0% (0/15) | Infinite frame loop | Frame loop termination |
| zeroframe_definesprite | 0% (0/3) | Zero-frame sprite timing | Sprite init edge case |

---

## Version Multiplier Opportunities

Many fixes apply across SWF versions (v5-v8), so the effective number of distinct bugs is much smaller than the 152 failing test count. Key multiplier opportunities:

| Fix | v5 | v6 | v7 | v8 | Effective tests |
|-----|----|----|----|----|-----------------|
| Math edge cases | pass→pass | pass→pass | fail→pass | fail→pass | 4 (already near-passing) |
| Error constructor | fail→improve | fail→improve | fail→improve | fail→improve | 4 |
| Color improvements | fail→improve | fail→improve | fail→improve | fail→improve | 4 |
| Number formatting | fail→improve | fail→improve | fail→improve | fail→improve | 4 |
| Delete operator | fail→improve | fail→improve | fail→improve | fail→improve | 4 |
| String methods | fail→improve | fail→improve | fail→improve | fail→improve | 4 |

A single fix to a class implementation typically improves 3-4 tests simultaneously.
