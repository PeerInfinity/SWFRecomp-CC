# Zero-Output Tests Triage Plan

<!-- TESTS: BeginBitmapFill, Version4Loader, frame_label_test, replace_buttons1test, replace_shapes1test, action_order/action_execution_order_test6, loading/LoadVarsTest, submoviegetvar, opcode_guard_test2 -->

<!-- PLAN_META
id: ZERO_OUTPUT_TRIAGE
status: pending
phases:
  - id: 1
    name: "Verifier: empty data-file array generates invalid C (LoadVarsTest compile_fail)"
    status: completed
  - id: 2
    name: "Gate clip CONSTRUCT/LOAD events out of buttons (replace_buttons1test, replace_shapes1test)"
    status: completed
  - id: 3
    name: "Version4Loader: child SWF loadMovie of Version5Loaded.swf"
    status: pending
  - id: 4
    name: "frame_label_test: nested-sprite frame label resolution"
    status: pending
  - id: 5
    name: "BeginBitmapFill: _width=804 instead of 150 on a bitmap-filled MC"
    status: pending
  - id: 6
    name: "opcode_guard_test2: testvar off-by-one + getDepth on -32969 clone"
    status: pending
dependencies: []
blockers:
  - reason: "None — the legacy 'DoInitAction-for-unplaced-library-exports' blocker hypothesis (per complete/DEJAGNU_FRAMEWORK_PLAN.md) is wrong. None of the affected tests have DoInitAction tags; they fail for distinct, unrelated reasons. Each phase is independent."
-->

## Correction to legacy plan

`complete/DEJAGNU_FRAMEWORK_PLAN.md` and `MISC_MING_SWFC_PLAN.md` Phase 3
both list 7+ tests as blocked on **"DoInitAction-for-unplaced-library-exports"**
— the hypothesis being that the inlined Dejagnu functions are defined in
DoInitAction tags on library-export sprites that we never run because we
only run DoInitAction for placed sprites.

**That's wrong.** Direct SWF tag inspection of all the listed tests
(parsed with a 90-line Python tag scanner — see investigation log)
shows **zero DoInitAction tags** in any of them:

| Test | DefineSprite | DoAction | DoInitAction | ExportAssets | ImportAssets |
|------|-------------|----------|--------------|--------------|--------------|
| BeginBitmapFill | 1 | 7 | **0** | 0 | 0 |
| Version4Loader | 0 | 1 | **0** | 0 | 0 |
| frame_label_test | 3 | 18 | **0** | 0 | 0 |
| replace_buttons1test | 1 | 11 | **0** | 0 | 0 |
| replace_shapes1test | 1 | 13 | **0** | 0 | 0 |
| action_execution_order_test6 | 4 | 6 | **0** | 0 | 0 |
| (compare passing PlaceObject2Test) | 3 | 7 | 0 | 0 | 0 |

The Dejagnu check functions are defined inside ordinary `DoAction` tags,
not `DoInitAction`. The blocker hypothesis was based on a structural
inference that turned out not to match the actual SWF contents. The
DEJAGNU_FRAMEWORK_PLAN's "Remaining Blocker" section should be marked
inaccurate (the misc-ming/misc-swfc tests aren't blocked on that
mechanism).

## Current status of the "zero-output" tests (CI 205a9a77 → local 2026-05-02)

The CI snapshot's `matching_lines: 0` was misread as "zero output." Many
of these tests **do produce output** — just none of it matches expected.
Five of the nine listed tests now PASS or RM locally:

| Test | Suite | actual / expected / match | Real status |
|------|-------|--------------------------|--------------|
| `BeginBitmapFill` | misc-ming | 1 / 1 / 0 | Single-line content mismatch — `mc9._width` returns 804, expected 150. Not zero-output. |
| `Version4Loader` | misc-ming | 0 / 11 / 0 | **TRUE zero output.** Child SWF `Version5Loaded.swf` doesn't run. |
| `frame_label_test` | misc-ming | 0 / 17 / 0 | **TRUE zero output.** Frame-label-driven `_root.x1` etc. variables never get set. |
| `replace_buttons1test` | misc-ming | (was 24 / 18 / 0) | **NOW `ruffle_matched` locally** (2026-05-02 verification). Will flip in next CI run. |
| `replace_shapes1test` | misc-ming | (was 32 / 23 / 0) | **NOW PASS locally** (2026-05-02 verification). Will flip in next CI run. |
| `action_execution_order_test6` | misc-ming | (was 0/24) | **NOW `ruffle_matched` locally.** Ordering progress since CI; will flip in next CI run. |
| `submoviegetvar` | misc-swfc | (was 0/4) | **NOW PASS locally.** Will flip in next CI run. |
| `loading/LoadVarsTest` | misc-ming | (was compile_fail) | **NOW PASS locally** (2026-05-02 verification). Phase 1 fix already in `verify_output.py:1280-1281` (verified). Will flip in next CI run. |
| `opcode_guard_test2` | misc-swfc | (was runtime_error) | Now `output_mismatch`, 11/20 passing. testvar off-by-one + dynamic-clone getDepth issue. |

**Phases 1, 2, and the two free flips have all landed locally.** Remaining
actionable phases:
- Phase 3 (Version4Loader child SWF loadMovie),
- Phase 4 (frame_label_test slash-colon GoToLabel arg parsing),
- Phase 5 (BeginBitmapFill `_width` getter on bitmap-fill MCs),
- Phase 6 (opcode_guard_test2 testvar off-by-one + getDepth).

## Phase 1 — Verifier: empty data-file array generates invalid C

**Bug.** `ruffle-tests/verify_output.py:1207` emits:

```python
hex_bytes = ", ".join(f"0x{b:02x}" for b in content)
lines.append(f"static const char {var_name}[] = {{ {hex_bytes}, 0x00 }};")
```

When `content` is empty (`empty.txt` for LoadVarsTest), `hex_bytes` is
`""` and the generated C is:

```c
static const char data_empty_txt[] = { , 0x00 };
```

— invalid (leading comma after `{`). gcc errors:
`data_registry.c:5:40: error: expected expression before ','`.

**Fix.** One-line: emit `{ 0x00 }` (no leading comma) when content is
empty:

```python
if not content:
    lines.append(f"static const char {var_name}[] = {{ 0x00 }};")
else:
    hex_bytes = ", ".join(f"0x{b:02x}" for b in content)
    lines.append(f"static const char {var_name}[] = {{ {hex_bytes}, 0x00 }};")
```

Or equivalently `f"{{ {hex_bytes}{',' if hex_bytes else ''} 0x00 }}"`.

**Risk.** None — strictly additive, only affects tests with empty
sidecar files. Verify by recompiling LoadVarsTest after the fix.

## Phase 2 — Gate clip CONSTRUCT events out of buttons

**Symptom.** `replace_buttons1test` and `replace_shapes1test` produce
extra trace lines that aren't in expected:

```
+ 1  _level0.static1 onClipConstruct       ← from a CONSTRUCT clip handler
+ 2  PASSED: movieclip == movieclip        ← assertion inside that handler
+ 3  _root.depth3Constructed set to 1      ← side effect of that handler
- 1  PASSED: typeof(static1) == 'object'   ← expected to start here
```

These extra lines come from the test's `onClipConstruct` clip-action
handler, which expected output skips. The expected behavior: Flash does
NOT dispatch `CLIP_EVENT_CONSTRUCT` (and likely `CLIP_EVENT_LOAD`) for
**Button** characters — only for sprites. Buttons have a different
event lifecycle (`onPress`/`onRelease`/etc., no construct/load).

**Investigation steps:**

1. Confirm the ordering of events. The test's CONSTRUCT handler is
   bundled into the static1 button's `clip_actions`. Our runtime fires
   them via `tagPlaceObject2WithClipActions`'s CONSTRUCT-dispatch path.
2. Locate the CONSTRUCT clip-event firing site. Likely in
   `SWFModernRuntime/src/libswf/tag.c` — search for
   `CLIP_EVENT_CONSTRUCT` (or `0x400` raw flag value). Multiple sites
   may dispatch.
3. Check if the placement target is a Button character (via
   `dictionary[char_id].type == CHAR_TYPE_BUTTON` or the `is_button`
   variable already in scope at placement time).
4. Skip CONSTRUCT (and LOAD) dispatch when target is a Button.

**Fix sketch.**

```c
// Before dispatching CLIP_EVENT_CONSTRUCT clip actions on a freshly placed display object:
if (is_button_target) {
    // Buttons don't fire CONSTRUCT/LOAD clip events — Flash semantics.
    // (Buttons fire onPress/onRelease/onRollOver/etc. instead, but those
    // are handled separately by the input dispatch path.)
} else {
    // existing CONSTRUCT dispatch
}
```

Same for `CLIP_EVENT_LOAD` if it leaks the same way.

**Risk.** Low-medium. Need to verify the AVM1 button tests
(`button_children`, `bad_placeobject_clipaction`,
`movieclip_in_removed_button`) still pass — they may rely on some
button-on-load behavior. The `BUTTON_INFRASTRUCTURE_PLAN.md` has
related work; this phase is an early step in that direction.

## Phase 3 — Version4Loader: child SWF loadMovie

**Problem.** Version4Loader is a SWF that uses `loadMovie` to load
`Version5Loaded.swf` (a child SWF compiled at version 5). The expected
trace starts with the child SWF's debug header (`[ debug-22403-05c7ba106]`)
and 9 PASSED lines from the child's assertions about builtin functions
(`unescape`, `escape`, `isNaN`, etc.). We produce zero output — the
child SWF must not be running.

**Investigation steps:**

1. Confirm the test SWF actually attempts `loadMovie("Version5Loaded.swf",
   ...)`. The 1 DoAction tag is the only AS code; it must be the loadMovie
   call.
2. Check whether `Version5Loaded.swf` exists in the test directory:
   ```bash
   ls ruffle-tests/tests/swfs/from_gnash/misc-ming.all/Version4Loader/
   ```
3. Confirm `verify_output.py` includes child SWFs in the test build (it
   does for `Dejagnu.swf` — same pattern). If not, that's the bug. If
   yes, runtime `loadMovie` for SWF4-targeting-SWF5-child needs
   investigation.
4. Cross-reference with the AVM1 `loadmovie_*` tests and the Shumway
   `haxe/flocons1` test which exercises similar cross-version loading.

**Risk.** Medium. May require version-handshake work in the child SWF
loader, or just a verifier dependency-discovery fix.

## Phase 4 — frame_label_test: nested-sprite frame label resolution

**Problem.** Expected output:

```
PASSED: _root.x1 == 'mc11_frame4'
PASSED: _root.x2 == 'mc11_frame5'
PASSED: _root.x3 == 'mc11_frame6'
PASSED: _root.x7 == 'mc1_frame7'
...
```

We produce zero output. The test has 3 DefineSprites and 18 DoActions.
The pattern `mc11_frame4` suggests a frame label inside sprite `mc11` at
frame 4. The DoAction sets `_root.x1 = mc11._currentlabel` (or similar
frame-label introspection) at specific timeline points.

If frame label introspection on nested sprites is broken — or if the
sprites' `gotoAndPlay`/`gotoAndStop` calls don't navigate to the label
frames — `_root.x1` etc. would never get set, so `Dejagnu.check_equals`
on undefined values produces no PASSED/FAILED trace.

Wait, the expected output DOES include PASSED traces, so the assertions
DO run in expected. Our zero output means the **assertions never run**,
which suggests the inlined Dejagnu functions weren't defined when the
DoAction tried to call them. OR the script throws an error and bails.

**Investigation steps:**

1. Strip `--diff` to see actual stdout in full:
   ```bash
   python3 ruffle-tests/verify_output.py --tests-dir=... --test=frame_label_test 2>&1 | head -50
   ```
2. Check stderr for runtime errors (e.g., the heap_alloc warning from
   BeginBitmapFill).
3. If no errors, add a `printf` in `actionTrace` to confirm any traces
   are firing at all — script may be silently completing without
   reaching the assertion functions.
4. If the inlined Dejagnu functions aren't being defined, look at the
   recompiler emission for the defining DoAction (likely `script_0` —
   it should `actionDefineFunction` for `check_equals`, etc.). Confirm
   that script runs at frame 0.

**Risk.** Medium-high. May surface a recompiler ordering bug or a
runtime function-table issue affecting only this test's structure.

## Phase 5 — BeginBitmapFill: _width returns 804 instead of 150

**Problem.** Single-line test. Expected:

```
PASSED: _root.mc9._width == 150
```

We get:

```
FAILED: expected: 150 obtained: 804 [BeginBitmapFill.c:222]
```

`mc9._width` should return 150 (the bitmap fill's logical width) and
returns 804 instead. 804 is 150 * 5.36 — close to 150 + some scaling, but
not a simple ratio. More likely 804 is the bitmap's **native pixel
size in twips/20** (a 4020-twip bitmap = 201px ≠ 150 either, so the
math isn't obvious without inspecting the SWF's BeginBitmapFill matrix).

**Investigation steps:**

1. Decompile or inspect the SWF's DefineShape with BeginBitmapFill —
   what's the bitmap, what's the bitmap matrix, what shape is mc9?
2. Compare with our `_width` getter for MCs containing bitmap fills.
   Does it walk the shape geometry (correct: 150) or take the bitmap's
   raw dimensions (incorrect: 804)?
3. Cross-reference: AVM1 has `bitmap_data_*` tests but no exact match
   for "MC width with bitmap fill." Test may expose a single edge case.

**Risk.** Low. Confined to `mcGetEffectiveSize` / `_width` getter and
its handling of `BeginBitmapFill` as a fill style.

There's also a stderr warning during this test:

```
ERROR: heap_alloc() called before heap_init()
ERROR: Failed to allocate property name
```

Triage that separately — it may be unrelated to the `_width` issue
or it may be the cause (a property name allocation failure could
corrupt state).

## Phase 6 — opcode_guard_test2: testvar off-by-one + getDepth on -32969

**Symptoms.** Local diff shows:

```
expected: testvar == 100  → got testvar == 101 (off by one)
expected: testvar == 200  → got testvar == 201 (off by one)
expected: ref200.getDepth() == -32969 → got 200 (no negative form)
```

The `-32969` value is `-(200) + (-32769) = -32969` — a clone-depth-zone
formula that may be specific to this test's swapDepths / removeMovieClip
sequence. The `200 / -32969` mismatch is consistent with our existing
"CloneSprite depth-bias trade-off" (see `CLONESPRITE_DEPTH_BIAS_PLAN.md`)
— though the 200 expected → 201 obtained off-by-one for `testvar` is
distinct.

**Investigation steps:**

1. Decompile or inspect the test source to see what `testvar` is
   incremented by. If it's `++` inside an event handler, our handler
   may fire one extra time (CONSTRUCT vs LOAD overlap, or initialize
   before the AS-set value is set).
2. Cross-reference the `getDepth() == -32969` expectation with the
   CloneSprite depth-bias plan. It may be the *same* fix — or it may
   be a different removed-clone-depth-zone arithmetic site.

**Risk.** Medium. The off-by-one might trace back to clip-event firing
order (related to Phase 2 or DEFERRED_CLIP_UNLOAD_PLAN). The getDepth
issue likely overlaps CloneSprite plan.

## Phases that no longer need work

- **`action_execution_order_test6`** — already `ruffle_matched` locally
  via subset-of-Ruffle promotion. Will flip in the next CI run. No
  code change needed.
- **`submoviegetvar`** — already `pass` locally. Will flip in the next
  CI run. No code change needed.

These should be removed from the "blocker" list in
`MISC_MING_SWFC_PLAN.md` once the next CI snapshot confirms.

## Verification battery

**Required-pass guardrail:**

- AVM1: `loadvariables_method`, `loadvariables`, `loadvars` (LoadVars
  tests with non-empty sidecars). Phase 1 must not regress these.
- AVM1: `button_children`, `bad_placeobject_clipaction`,
  `movieclip_in_removed_button`, `clip_events`, `on_construct`,
  `register_and_init_order`. Phase 2 must not regress these (CONSTRUCT
  gating risk).
- AVM1: `loadmovie`, `loadmovie_unloadmovie`, `loadmovie_*` (~30
  tests). Phase 3 must not regress these.

**Target tests:**

- Phase 1: `loading/LoadVarsTest` flips from compile_fail to
  output_mismatch (or pass, if the underlying loadVariables test logic
  also works).
- Phase 2: `replace_buttons1test`, `replace_shapes1test` partial
  improvement (ordering shifts from extra-leading to expected-leading).
- Phase 3: `Version4Loader` produces some output instead of none.
- Phase 4: `frame_label_test` produces some output instead of none.
- Phase 5: `BeginBitmapFill` PASS.
- Phase 6: `opcode_guard_test2` partial improvement.

## Open questions

1. **The `heap_alloc() called before heap_init()` stderr warning in
   BeginBitmapFill.** Does it also appear in other tests? Tracing back
   to the call site might reveal a runtime initialization-order bug that
   affects more than just BeginBitmapFill.
2. **Why are `submoviegetvar` and `action_execution_order_test6` now
   passing locally?** No matching commit message claims to fix them
   — they may have flipped via incidental changes in nearby
   commits. Worth confirming via `git log` since CI snapshot.
3. **Phase 2 overlap with `BUTTON_INFRASTRUCTURE_PLAN.md`.** That plan
   covers other Button issues (typeof, instance naming, prototype
   enumeration). Phase 2 here is "buttons don't fire
   CLIP_EVENT_CONSTRUCT/LOAD" — adjacent but distinct. Should land
   independently.

## Estimated session budget

- Phase 1: 15 min (1-line verifier fix + LoadVarsTest re-run).
- Phase 2: 1–2 hours (locate CONSTRUCT/LOAD dispatch sites, gate on
  is_button, run battery).
- Phase 3: 2–3 hours (loadMovie cross-version investigation).
- Phase 4: 2–3 hours (frame label resolution; may surface recompiler
  emission issue).
- Phase 5: 1–2 hours (decompile + _width getter audit).
- Phase 6: 1–2 hours (testvar off-by-one + depth math).

Phases 1 + 2 are the cheapest (~2 hours combined) for 3 test flips.

## Why this is the right shape

The legacy "DoInitAction-for-unplaced-library-exports" hypothesis was a
plausible-sounding inference that turned out not to match the actual
SWF contents. Like the prior "input drivers" misclassification (see
`BUTTON_INFRASTRUCTURE_PLAN.md`'s correction), running the actual tests
and inspecting their actual output reveals 6 distinct, unrelated
issues — none of which require an architectural DoInitAction change.
The plan replaces a single architectural blocker with 6 narrow,
independent fixes, most of which are 1–3 hour tasks.

Once landed, removes the "Phase 3 — Blocked zero-output tests"
section from `MISC_MING_SWFC_PLAN.md` and supersedes the legacy
`complete/DEJAGNU_FRAMEWORK_PLAN.md` "Remaining Blocker: misc-ming /
misc-swfc Inlined Dejagnu" claim.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `MISC_MING_SWFC_PLAN.md` "Phase 3 — Blocked zero-output tests" | This plan supersedes that section. The 9 tests listed there have 6 distinct causes, none architectural. |
| `complete/DEJAGNU_FRAMEWORK_PLAN.md` "Remaining Blocker" | Misframed. The misc-ming/misc-swfc tests aren't blocked on DoInitAction-for-library-exports. Mark that section inaccurate or update on the next pass. |
| `BUTTON_INFRASTRUCTURE_PLAN.md` | Phase 2 (button CONSTRUCT/LOAD gating) is adjacent. Both plans can land independently; pick whichever is cheaper to verify first. |
| `CLONESPRITE_DEPTH_BIAS_PLAN.md` | Phase 6 (opcode_guard_test2 getDepth) likely overlaps. Land that plan first if attempting Phase 6. |
| `DEFERRED_CLIP_UNLOAD_PLAN.md` | Independent. |
