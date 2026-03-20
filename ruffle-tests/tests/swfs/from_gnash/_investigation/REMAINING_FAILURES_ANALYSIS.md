# Gnash Remaining Failures Analysis

Date: 2026-03-19
CI run: 043094ef (52/204 total = 25.5%)

152 tests still failing across actionscript.all (146) and misc-swfmill.all (6). This document groups them by actionability and estimated effort.

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

## Tier 1: Near-Passing (>95% match) — 8 tests

These tests are very close to passing and likely need small, targeted fixes.

### Math-v5/v6 (97.8%, 272/278) + Math-v7/v8 (97.6%, 280/287)

6-7 lines wrong. Known issues:
- `Math.round("")` — empty string argument handling
- `Math.pow(x)` with 1 arg — missing second arg semantics
- Minor constant precision issues

**Estimated fix**: 1-2 hours. Edge case fixes in Math method implementations.

### ops-v8 (95.8%, 251/262)

11 lines wrong. Equality operator string coercion:
- `Infinity == 'Infinity'` → should be true (string-to-number coercion)
- `-Infinity == '-Infinity'` → should be true
- NaN comparison edge cases

**Estimated fix**: 1 hour. Fix abstract equality algorithm for Infinity/NaN string representations.

### NetStream-v6/v7/v8 (95.0%, 76/80)

4 lines wrong each. `hasOwnProperty` checks on NetStream.prototype properties (`currentFps`, etc.).

**Estimated fix**: 30 minutes. Register missing properties on NetStream prototype.

---

## Tier 2: Close (80-95% match) — ~25 tests

### Color tests — Color-v5 (88.6%), Color-v6 (86.0%), Color-v7/v8 (87.6%)

16-24 diff lines. Color.getTransform() on invalid target, setTransform value storage, Color prototype property access. Recent Color prototype unification helped but gaps remain.

### TextFieldHTML — v6/v7/v8 (86.5%, 32/37)

5 diff lines each. HTML text getter edge cases. Same issues tracked in AVM1 suite's TEXTFIELD_PLAN.

### Selection — v5 (85.7%), v6 (86.4%), v7/v8 (87.2%)

3-17 diff lines. SWF5 typeof check (`typeof(Selection)` should be 'undefined'), `_listeners` own property, `instanceof` on MC.

### Inheritance — v5 (82.6%, 95/115), v6 (85.2%, 155/182)

20-27 diff lines. OOP prototype chain issues: constructor execution ordering, `instanceof`, `__constructor__` setup, `Function.prototype` visibility.

### Stage-v5 (86.8%, 33/38)

5 diff lines. Non-constructable global (typeof should be 'undefined' in SWF5), listener methods version-gated.

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
| Number v5-v8 | 4 | 76-79% | toString(radix), toFixed, toPrecision |
| Error v5-v8 | 4 | 75-77% | Constructor message coercion, toString |
| AsBroadcaster v5-v8 | 4 | 70-79% | Listener dispatch, broadcastMessage |
| TextSnapshot v6-v8 | 3 | 76.3% | getText, findText methods |
| toString_valueOf v5-v8 | 4 | 60-77% | valueOf/toString on arrays, ASArray cast bug |
| Global v6-v8 | 3 | 70-76% | Missing global properties/constructors |
| TextFormat v5-v7 | 3 | 64-78% | Constructor coercion, property getters |
| ContextMenu v7-v8 | 2 | 72.5% | customItems, builtInItems |
| Sound v5-v8 | 4 | 63-77% | attachSound, volume, Sound prototype |
| flash v5-v7 | 3 | 70.0% | flash.geom constructor stubs |
| ExternalInterface v6-v8 | 3 | 51-70% | addCallback, data marshalling |
| MovieClip-v5 | 1 | 65.0% | Many MC methods |
| delete v5-v8 | 4 | 62-67% | Scope deletion, DONT_DELETE |
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
| LocalConnection v5-v8 | 4 | 41-57% | Full IPC system |
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

## Crashes — 7 tests

| Test | Type | Root Cause |
|------|------|------------|
| Inheritance-v7 | Segfault | Prototype chain corruption — needs investigation |
| Inheritance-v8 | Segfault | Same as above |
| Try-v5 | Runtime error | OOM from try/finally goto bug |
| Try-v6 | Runtime error | Same |
| Try-v7 | Runtime error | Same |
| Try-v8 | Runtime error | Same |
| array-v5 | Runtime error | OOM/infinite loop in array ops |

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
