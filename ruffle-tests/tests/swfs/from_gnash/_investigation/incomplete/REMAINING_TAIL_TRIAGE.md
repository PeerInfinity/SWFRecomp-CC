# Remaining Tail Triage

<!-- TESTS: matrix_test, DefineEditTextVariableNameTest, EmbeddedFontTest, DrawingApiTest, NetStream-SquareTest, loop/loop_test10, masks_test, duplicate_movie_clip_test, soft_reference_test1, movieclip_destruction_test4, action_order/action_execution_order_test6 -->

<!-- Resolved 2026-05-02:
  - loop/loop_test → PASS (was 5/21; fixed in cluster work)
  - DefineTextTest → ruffle_matched (was 11/16; fixed in cluster work)
  - swf4opcode → ruffle_matched (Group B fixed via SWF4 MovieClip→0.0 coerce)
  - replace_sprites1test → PASS (resolved 2026-04-29)
  - sound → ignored_tests.txt (interactive timing accepted) -->

<!-- Re-baselined 2026-05-02:
  - movieclip_destruction_test2 → PASS 56/56 (was documented blocker
    at 52/56; picked up the 2026-04-30 fix in CURRENT_STATUS,
    `setGlobalVariableByName` for root SetMember). Removed from
    "Skip" list and Entries section.
  - matrix_test 912/1086 → 918/1086 (84.0% → 84.5%)
  - soft_reference_test1 14/45 → 23/45 (31.1% → 51.1%)
  - DrawingApiTest 43/93 → 66/93 (46.2% → 71.0%)
  - EmbeddedFontTest 50/87 → 51/87 (57.5% → 58.6%)
-->

<!-- Resolved 2026-05-04:
  - soft_reference_test1 → ruffle_matched 44/45. _name setter now
    syncs parent.dynamic_props and (root only) var_map on rename,
    matching Ruffle's MovieClip::set_name binding-replacement
    semantics. -->


<!-- Resolved 2026-05-06 (CI c8f6452a):
  - key_event_test → ruffle_matched 61/66 (was 33/66). Phase 2 of
    key-event work narrowed tagRemoveObject2's backward-catch-up
    early-return.
  - loop/loop_test6 → ruffle_matched 22/23 (was 11/23). Same root
    cause as key_event_test.

  Re-baselined open entries (CI c8f6452a):
  - matrix_test 918/1086 → 949/1086 (84.5% → 87.4%)
  - opcode_guard_test 10/18 → 11/18 (55.6% → 61.1%)
  - DefineEditTextVariableNameTest 49/72 unchanged (68.1%)
  - DrawingApiTest 66/93 unchanged (71.0%)
  - EmbeddedFontTest 51/87 unchanged (58.6%)
  - NetStream-SquareTest 86/216 unchanged (39.8%)
  - loop/loop_test10 3/28 unchanged (10.7%)
  - masks_test 28/175 unchanged (16.0%)
  - duplicate_movie_clip_test 3/33 unchanged (9.1%)
  - movieclip_destruction_test4 8/40 unchanged (20.0%)
-->

<!-- Resolved 2026-05-07 (CI a3912cf2):
  - opcode_guard_test → ignored. Bug 1 (spurious FAILED:false from mc2
    ENTERFRAME after gotoAndPlay) had been fixed at some point between
    2026-05-02 and 2026-05-07; current output passes all 11 assertions.
    Only remaining diff is a single Target not found warning line that
    Gnash's expected output omits but Flash and Ruffle both emit.
    Cannot promote to ruffle_matched because being more correct than
    Ruffle on the mc1 event handlers shifts our diff indices outside
    Ruffle's diff set. Cannot suppress the warning without regressing
    8+ AVM1 tests that assert it. See ACCEPTED_DIFFS.md Category 1.
-->


<!-- Investigated 2026-05-02 (no fix landed):
  - duplicate_movie_clip_test (3/33 → still 3/33). Confirmed primary
    bug: dups inherit clip events but ENTERFRAME/UNLOAD don't fire
    because ng_cloneSprite skips the display_list slot when
    target_swf_depth >= INITIAL_DISPLAYLIST_CAPACITY (1024). The test
    pushes biased depths (16385/16386 = AS depth 1/2 + 16384), so the
    dup never lands in display_list[]. Tried sharing clip_actions
    pointer in the small-depth branch — verified no regressions across
    a 24-test battery (10 avm1 clone/attach tests, 7 misc-ming
    loop/depth tests, 5 misc-swfc clone-related tests, 2 misc-ming
    duplicate_movie_clip_* siblings) but no test improvement either,
    since the test under investigation doesn't hit that branch.
    Reverted. Real fix requires the depth-bias unification work
    documented in `incomplete/CLONESPRITE_DEPTH_BIAS_PLAN.md` (Phase 2). -->


<!-- Investigated 2026-05-07 (no fix landed):
  - action_order/action_execution_order_test5 (26/35 → PASS locally,
    reverted before commit). Symptom: at root frame_3 (which removes
    mc1) the natural advance of mc1's 2-frame timeline loops sprite_8
    back to frame 0; advance_sprite_frames's loop-back silent-clear
    drops the children, then frame_0 fresh-places mc11/mc12 firing a
    second wave of init/construct/load events before the RemoveObject
    fires. Tried the conservative half of SPRITE_REWIND_IDENTITY
    (Phase 1 metadata + survives_rewind preservation in
    advance_sprite_frames natural-wrap, no UNLOAD lifecycle for
    non-survivors). Test passed locally; avm1 sprite/loop battery
    (15/15) and gnash sprite-loop battery (7/7) unchanged. But
    RegisterClassTest4 regressed by ~9 lines (8/42 vs baseline
    17/42) — the documented STOP signal from
    blocked/SPRITE_REWIND_IDENTITY_PLAN.md. Reverted. Real fix is
    blocked on that plan's Phase 3 (pending_finalize MC isolation +
    correct UNLOAD ordering for the gotoAndPlay-driven case). -->


<!-- PLAN_META
id: REMAINING_TAIL_TRIAGE
status: pending
phases: []
dependencies: []
blockers:
  - reason: "Each entry is an independent single-test (or micro-cluster) issue without a shared root cause across the broader set. Tracked here as one-page triage so individual sessions can pick a target without rediscovery work. Entries graduate to standalone plans when active investigation begins (see 'Promotion convention' below)."
-->

## Purpose

This document collects all remaining `misc-ming.all` and `misc-swfc.all`
failing tests **not** covered by one of the seven cluster plans:

| Cluster plan | Status | Tests covered |
|--------------|--------|---------------|
| `complete/DEFERRED_CLIP_UNLOAD_PLAN.md` | complete | loop_test6/7/8, action_execution_order_test2/3/5/11, ActionOrderTest3/4/5 |
| `incomplete/CLONESPRITE_DEPTH_BIAS_PLAN.md` | incomplete (Phase 1 shipped; Phase 2 split into 2a-2d, multi-session) | displaylist_depths_test/2/3/8/9, DepthLimitsTest, duplicate_movie_clip_test/2 |
| `complete/BUTTON_INFRASTRUCTURE_PLAN.md` (+ `incomplete/BUTTON_RESIDUAL_PLAN.md`) | architectural phases complete; residual issues tracked in BUTTON_RESIDUAL_PLAN | parent: RollOverOutTest (PASS), ButtonPropertiesTest (PASS), mouse_drag_test (PASS); residual: ButtonEventsTest, key_event_test, DragDropTest, button_test1 |
| `complete/ZERO_OUTPUT_TRIAGE_PLAN.md` | incomplete | BeginBitmapFill, Version4Loader, frame_label_test, replace_buttons1test, replace_shapes1test, LoadVarsTest, opcode_guard_test2 |
| `incomplete/REGISTERCLASS_LIFECYCLE_PLAN.md` | incomplete | registerClassTest, registerClassTest2, RegisterClassTest3, RegisterClassTest4 |
| `superseded/GOTO_CATCHUP_HYGIENE_PLAN.md` | **superseded** (Phases 1–5 landed; Phase 6 → `complete/GOTO_FIFO_UNIFICATION_INCREMENTAL_PLAN.md`; Phase 7 → `incomplete/TRANSFORMED_BY_SCRIPT_WRAP_BACK_PLAN.md`) | goto_frame_test, consecutive_goto_frame_test, place_and_remove_object_insane_test |
| `complete/IMPORT_CHARACTER_PLAN.md` | complete | attachImported, attachMovieLoopingTest, loadMovieTest |

Everything else lives here. **Note 2026-05-03:** entries that were
originally deferred "pending GOTO_CATCHUP_HYGIENE / CLONESPRITE_DEPTH_BIAS"
no longer have a passive free-recovery path. GOTO_CATCHUP_HYGIENE is
superseded (its remaining work moved to other plans). CLONESPRITE_DEPTH_BIAS
is now `incomplete` again with a documented Phase 2 split (2a recompiler,
2b runtime branching audit, 2c slot cap raise, 2d verify) — pickable but
multi-session. The deferred entries (opcode_guard_test bug 1,
soft_reference_test1, duplicate_movie_clip_test, movieclip_destruction_test4)
either depend on Phase 2 landing or need their own root-cause investigation.

## Promotion convention

Each entry has a fixed shape: **Match / Symptom / Hypothesis / Scope**.
When active investigation begins on a specific entry:

1. Read the entry, run the test locally, confirm or refute the
   hypothesis with a fresh diff.
2. If the work fits in one session, do it inline and update this
   doc with the outcome.
3. If the entry grows into multi-phase work, **graduate it to a
   standalone plan** (`incomplete/<TEST>_PLAN.md`) and replace the
   entry here with a one-line cross-link.

## Micro-clusters within this doc

A few entries share enough DNA to be worth attacking together:

- **Pending-removal MC visibility:** `opcode_guard_test`,
  partial-overlap with `movieclip_destruction_test4`. `typeof()`
  returns `'movieclip'` for MCs that should be `undefined`
  post-removal.
- **Text / EditText variable binding:** `DefineTextTest`,
  `DefineEditTextVariableNameTest`. Both touch text-field variable
  binding edges past what `DefineEditTextTest` /
  `DefineEditTextVariableNameTest2` (already passing) covered.
- **Graphics precision:** `DrawingApiTest`, `EmbeddedFontTest`.
  Both have float / coordinate residuals on rendered geometry.
- **Loop-cluster remnants:** `loop/loop_test` and
  `loop/loop_test10`. Both are loop tests that landed in this
  triage rather than `DEFERRED_CLIP_UNLOAD` or `CLONESPRITE` —
  distinct root causes.
- **Replace-cluster remnant:** `replace_sprites1test` is family
  with `replace_buttons1test` / `replace_shapes1test` (already in
  `ZERO_OUTPUT_TRIAGE` Phase 2) — same `onClipConstruct` extra
  trace pattern but for sprite replace specifically. Likely the
  Phase 2 fix should be expanded to include sprites.

---

## Entries — misc-ming.all

### matrix_test (87.4%, 949/1086) — promoted to `incomplete/MATRIX_TEST_SKEW_PLAN.md` (2026-05-07)

**Symptom.** Most failures cluster into two families with a shared root cause: (a)
`transform.matrix.toString()` returning the wrong sign for `c` after a direct
`mc.transform.matrix = ...` assignment, (b) `getBounds(_root)` axis-swapped or
under-sized after the same script-set matrix. A third sub-issue, `sin(90°)`
producing `6e-17`, is unrelated and tracked separately.

**Hypothesis.** Confirmed against Ruffle source: we lack a `skew` field on
`MovieClip`. Ruffle decomposes a directly-assigned matrix into `xscale`,
`yscale`, `rotation`, AND `skew = atan2(-c,d) - atan2(b,a)`, then recomposes
c/d via `cos(rot+skew)` / `sin(rot+skew)`. We round-trip through xscale/
yscale/rotation only, losing skew, so signs flip and downstream geometry
diverges.

**Scope.** Promoted to standalone plan
`incomplete/MATRIX_TEST_SKEW_PLAN.md` (2026-05-07) — 6 phases, 4-6 hour
single-session budget, expected raw match delta 949 → ≥1080.

### ~~DefineTextTest~~ — promoted to `ruffle_matched` (2026-05-02 result snapshot)

Status now `ruffle_matched` 12/16. Our remaining diff is a subset of
Ruffle's diff against expected, so the test counts toward effective
pass. Full PASS still requires the FP precision and mouse-click
issues described originally; deferred until those root causes have a
home.

### DefineEditTextVariableNameTest (68.1%, 49/72)

**Symptom.** Per `MISC_MING_SWFC_PLAN.md`: every check from
`mc4.uninitalized_text_var == 'string'` (line 340) onward is
duplicated in our output. Earlier checks fire once; later checks
fire twice. Looks like a frame loops back and re-runs a sub-range
of the timeline.

**Hypothesis.** v2 of this test (`DefineEditTextVariableNameTest2`)
already PASSES (39/39 — fixed 2026-04-23). v1 has more frames; the
extra frames presumably do something v2 doesn't (e.g., explicit
`gotoAndPlay` back to an earlier frame, or a different SWF
structure that hits a frame-replay bug). Likely overlaps
`GOTO_CATCHUP_HYGIENE_PLAN.md` Phase 4 (sprite double-fire on
nested goto).

**Scope.** 2-3 hours of investigation; may resolve as a free
benefit of GOTO_CATCHUP_HYGIENE Phase 4 landing.

### EmbeddedFontTest (58.6%, 51/87) and DrawingApiTest (71.0%, 66/93)

**Symptom (combined cluster).** Both fail on rendered-geometry
assertions — text glyph widths, drawing-API curve coordinates,
font advance values. Specific lines vary.

**Hypothesis.** Float/double precision in geometry pipeline. Likely
overlaps the same `(float)` round-trip pattern as
`attachMovieLoopingTest`'s `15.0000001716614`. EmbeddedFontTest
specifically may also need DefineFont3 / DefineFontAlignZones
support (newer font tags) — confirm by running with verbose
stderr and looking for "unsupported tag" or geometry warnings.

**Scope.** 3-5 hours combined, after Phase 4 of
`IMPORT_CHARACTER_PLAN` lands (which will fix the canonical FP
pattern).

### NetStream-SquareTest (39.8%, 86/216)

**Symptom.** NetStream timing test that exercises video playback.
Expected output cycles through video frames with timing-dependent
assertions. We produce ~40% of the expected lines.

**Hypothesis.** Per `MISC_MING_SWFC_PLAN.md`: "netstream timing".
NetStream playback uses a timer-based callback; the timer interval
or sync-with-frame mechanism may diverge from Flash's. The 14
AVM1 NetStream tests pass, so the basic NetStream API works — this
test exercises specific timing semantics.

**Scope.** 4-6 hours of timing investigation. **Promote to standalone
plan when work begins.**

### ~~loop/loop_test~~ — RESOLVED to PASS (2026-05-02 result snapshot)

Now PASS 21/21. Cluster fixes recovered the depth-bias /
interleave behavior described in the original entry.

### loop/loop_test10 (10.7%, 3/28)

**Symptom (from earlier diff):**

```
- 2  _level0.mc2 initialized          ← expected MC lifecycle traces
+ 2  FAILED: expected: 2 obtained: 1  ← we run assertions instead
...
- 8  _level0.mc1 unloaded
+ 8  FAILED: expected: '0+1+2+3+4+5+1+2+3+5+' obtained: '0+1+'  ← asOrder severely truncated
- 9  _level0.mc2 unloaded
+ 9  FAILED: expected: /instance3 , obtained: /instance2  ← auto-naming off by one
- 12 PASSED: mc3Initialized == 1
+ 12 FAILED: expected: /instance3/instance5 , obtained: /instance2/instance4  ← auto-naming off by 1+2
```

Three distinct symptoms:
1. MC initialized/unloaded traces missing (sprite init events not
   firing).
2. `asOrder` truncated to `'0+1+'` (frame DoActions stop early
   after frame 1).
3. Auto-naming off by 1-2: expected `instance3/4/5`, got
   `instance2/3/4` — every auto-name is one less than expected.

**Hypothesis.** The auto-name offset suggests a stray
`tagSetInstanceName(depth, "")` call or an explicit-named
placement that we treat as auto-named (consuming one counter
slot it shouldn't). The `asOrder` truncation suggests frame
DoActions stop firing after frame 1.

The plan note `MISC_MING_SWFC_PLAN.md` "loop_test10 at 3.6%
suggests a feature not implemented yet (probably for-in or
iterator-style)" was wrong — this isn't a missing feature, it's
multiple narrow bugs.

**Scope.** 3-5 hours; **may warrant standalone plan once symptoms
are confirmed**.

### ~~replace_sprites1test~~ — **RESOLVED 2026-04-29 (PASS)**

Cross-frame sprite-by-sprite REPLACE (PlaceObject2/3 with move=1 +
has_character=1) now preserves the existing sprite's identity in
`tagPlaceObject2` / `tagPlaceObject2Ratio` (matches Ruffle
`PlaceObjectAction::Replace` where `replace_with` is no-op for MovieClip
and `apply_place_object` excludes name/clip_depth/clip_actions).
`tagSetInstanceName` stashes as pending instead of renaming in-place when
the depth holds a sprite from a previous frame. See `CURRENT_STATUS.md`
"Latest fixes" for details.

### opcode_guard_test — RESOLVED via ignore list (2026-05-07)

**Status update 2026-05-07.** Bug 1 (the spurious `FAILED: false` after
`gotoAndPlay(8)` inside the mc2 ENTERFRAME clip event) was resolved
sometime between 2026-05-02 and 2026-05-07 — current output passes all
11 assertions cleanly (`#passed: 11 / #failed: 0 / #total tests run: 11`).
The only remaining diff is the single `Target not found: ...` warning
line at index 10, which causes the trailing 7 expected lines to all
appear at the wrong index (line shift).

**Why ruffle_matched promotion still fails.** Ruffle's
`output.ruffle.txt` also contains the `Target not found` warning, but
Ruffle additionally fails the mc1 Construct / Load / Unload event
handler assertions, so Ruffle's diff-set against Flash's `output.txt`
covers a *different* set of line indices (the early failures, not the
trailing shift). Our diffs at indices `{10, 11, 12, 14, 15, 16, 17, 18}`
are not a subset of Ruffle's `{2, 3, 4, 5, 6, 7, 8, 9, 15, 16}` — being
*more* correct than Ruffle on the event handlers prevents the alignment
needed for subset promotion.

**Resolution.** Added to
`from_gnash/misc-ming.all/ignored_tests.txt` so filtered effective
counts no longer flag this as a failure. Cannot suppress the
`Target not found` warning without regressing 8+ AVM1 tests
(`tell_target_invalid`, `path_string`, `tell_target`,
`removed_base_clip_tell_target`, `swf4_actions_coercion_order`,
`property_invalid_base_clip`, `call`, `tell_target_invalid_swf6`)
that assert it.

**Reference.** See `from_gnash/_investigation/ACCEPTED_DIFFS.md`
Category 1 entry "opcode_guard_test (misc-ming.all) — Gnash silently
swallows the failed-setTarget warning" for the full diff-index
analysis.

### masks_test (16.0%, 28/175)

**Symptom (from latest diff):** Output stops at:

```
Placed staticmc2 (red), ... DisplayObjects
Placed dynamicmc2 (blue), ... DisplayObjects
 - Press any key to continue -
<end of actual>
```

Test waits for a keyboard event before continuing the mask
assertions. **No `input.json` exists in the test directory** —
in Flash this would block forever waiting for the user.

**Hypothesis.** Different from `BUTTON_INFRASTRUCTURE_PLAN`
(those tests have input.json). masks_test needs *synthetic* input
to drive past the wait — the gnash test runners apparently
provide a default keypress automatically, or the test expects
`output.txt` to be the post-keypress run.

**Scope.** Requires verifier infrastructure: either auto-generate
an `input.json` for tests that detect a "Press any key" prompt,
or add a CLI flag that injects a default keypress at frame N.
**Promote to standalone plan when work begins** (verifier change
is its own concern).

### action_order/action_execution_order_test6 (0%, 0/24) — confirmed case (c) 2026-05-07

**Symptom.** Zero output produced (no common lines in CI). Predicted to flip
to `ruffle_matched` via subset-of-Ruffle promotion in the 2026-05-04 entry
of `ZERO_OUTPUT_TRIAGE_PLAN.md`, but the prediction did not pan out at CI
`c5994ec1` / `c8f6452a` / `035950cf` — still `output_mismatch`, still 0/24.

**Investigation (2026-05-07, local).** Test is `known_failure = true` in
test.toml and ships `output.ruffle.txt` (12 lines) so promotion path is
in place. Subset check fails because our diff includes line indices Ruffle
matches:

- Expected line 0: `mc1 Construct called` — Ruffle matches; we have `mc1 Load called`.
- Expected line 1: `mc2 Construct called` — Ruffle matches; we have `mc2 Load called`.

Real bug confirmed: our impl fires `CLIP_EVENT_LOAD` for mc1 + mc2 BEFORE
the `CLIP_EVENT_CONSTRUCT` of any of {mc1, mc2, mc3}. Expected order is
all three Constructs first, then the Loads. The delayed construct firing
also produces `mc3 Load/Unload` in the wrong section (lines 4-5 in our
output vs lines 7-8 in expected for the first cycle). This is independent
of Ruffle's bug (Ruffle's diff is missing `mc3 Construct` lines but has
the Construct-before-Load ordering correct on mc1/mc2).

**Hypothesis (case c).** Construct/Load ordering on initial frame placement
when multiple sprites are placed in the same frame — likely a tagPlaceObject2
eager-init / clip-event dispatch ordering issue. Construct should batch
across all same-frame placements before any Load fires; we may be firing
Load synchronously per-placement.

**Scope.** Not a 1-hour fix. Construct/Load batching is shared infrastructure
with broad regression risk. Compare Ruffle's `instantiate_child` →
`run_frame_avm1` ordering vs our `tagPlaceObject2` Phase 1/Phase 2 init.
Standalone plan worth writing if active work begins. Test cannot promote
to `ruffle_matched` until our ordering is at least as correct as Ruffle's
on lines 0-1.

### duplicate_movie_clip_test (9.1%, 3/33) — **blocked by CLONESPRITE_DEPTH_BIAS**

**Symptom.** Multi-issue. Confirmed root cause for primary failure
(2026-05-02):

- `_root.x2 == 2` expected, got 1. Frame-2 `duplicateMovieClip('mc2',
  'dup2', 2)` should produce a dup that fires `onClipEnterFrame`. We
  fire `onClipLoad` (via `ng_queue_pending_load`) and `onClipUnload`
  (clip event with the source's array), but ENTERFRAME never fires
  for the dup. Direct cause: `ng_cloneSprite` skips the display_list
  slot when `target_swf_depth >= INITIAL_DISPLAYLIST_CAPACITY` (1024).
  The bytecode pushes `depth = 16385/16386` (AS depth 1/2 + 16384
  bias), so the dup never enters `display_list[]`. Without a slot,
  `dispatch_enterframe_clip_actions` (which iterates `display_list`)
  has nothing to dispatch.
- Also missing: button duplication (`button.dupl(...)` returns
  undefined) and downstream counter checks at lines 172-173.

**Hypothesis.** The depth-bias issue is exactly what
`incomplete/CLONESPRITE_DEPTH_BIAS_PLAN.md` Phase 2 was meant to fix.
Phase 2 is blocked because stripping the +16384 bias for *packed*
Pushes shifts AS depths into 1..16383, colliding with timeline-placed
slots. Until that conflict is resolved (e.g., by separating
display_list slot allocation from depth-keyed lookup), `dup2` cannot
land in `display_list[]` and ENTERFRAME cannot fire.

**Investigated 2026-05-02.** Tried sharing the source's
`clip_actions` pointer in the small-depth branch — verified it
wouldn't regress 24 related tests (avm1 clone/attach, misc-ming
loop/depth, misc-swfc clone-related). But no test improved either,
since `duplicate_movie_clip_test` doesn't hit the small-depth branch.
Reverted; documenting here so the next session doesn't re-run the
same investigation.

**Scope.** Defer until CLONESPRITE_DEPTH_BIAS Phase 2 unblocks.
Button-duplication issue is a separate sub-investigation.

---

## Entries — misc-swfc.all

### ~~sound~~ — RESOLVED via ignored_tests.txt (2026-05-02)

Added to `from_gnash/misc-swfc.all/ignored_tests.txt` (Path (b)).
Documented in `from_gnash/_investigation/ACCEPTED_DIFFS.md` under
"Category 2: Interactive / Wall-Clock Timing Tests" — the expected
output truncates mid-test where Flash's frame-6 loop kept running
gotoAndPlay(5) waiting for sound playback. Without an audio backend
that returns realistic position values over time, we exit the loop
on the first pass and emit trailing totals lines. No
output.ruffle.txt / known_failure flag, so ruffle_matched promotion
isn't possible.

### ~~movieclip_destruction_test2~~ — RESOLVED to PASS (re-baseline 2026-05-02)

Now PASS 56/56 (was 52/56 with 2 deferred lines). Likely picked up the
fix from `CURRENT_STATUS.md` 2026-04-30 entry (`actionSetMember` on
root now propagates writes to `var_map` via `setGlobalVariableByName`).
No further work needed; entry retained here only as a history marker.

### swf4opcode → **ruffle_matched (2026-05-02)**

Group B (lines 114 / 116: bare `mc1` and `/:mc1` compared with
`undefined`) is now PASSED. Test promoted from MISMATCH to
ruffle_matched: our 4-line residual diff (Group A: lines
74/82/90/98 — `/mc1:_xscale`/`/mc1:_yscale`/`/mc1:_alpha`/`/mc1:_visible`)
is a subset of Ruffle's 13-line diff against Flash, so no further
work is needed for ruffle_matched status. Full PASS still
requires fixing Group A (SWF4 `/path:varname` should look up
`varname` as a variable on the path scope, not as a special MC
property).

**Root cause of Group B.** Bytecode for line 363 is
`Push("mc1") + GetVariable`; for line 365 it is
`Push("/:mc1") + GetVariable`. Both correctly resolve to the
child MovieClip `mc1` via display-list lookup (matching Ruffle's
`has_display_object_property` → `child_by_name`). The test
"passes" in Ruffle not because GetVariable returns undefined,
but because **SWF4 `Equals` (action 0x0e) coerces both operands
to f64**, and Ruffle's `coerce_to_f64` for `Value::MovieClip`
goes through `Value::Object(...) → to_primitive_num → primitive_as_number`,
which returns 0.0 for Object-typed values when `swf_version < 5`
(see `core/src/avm1/value.rs::primitive_as_number`). Both MC and
undefined coerce to 0.0 → equal → PASSED.

**Fix.** `convertFloat` for `ACTION_STACK_VALUE_MOVIECLIP` now
returns 0.0 in SWF<5 (was hardcoded NaN in all versions).
SWF>=5 still returns NaN, matching the Object case.

**Group A path to full PASS (deferred, ~1-3 hours).** In SWF4,
`/path:varname` looks up `varname` as a **variable** in the
path's scope, not as a special MC property — so `_xscale` /
`_yscale` / `_alpha` / `_visible` should return undefined,
not the MC's xscale/yscale/alpha/visible. Our
`actionGetVariable` slash-colon resolver finds `mc1` correctly,
then calls `actionGetMember` for `_xscale`, which dispatches to
the special-property handler and returns `mc->xscale` (100).
Note `_x`, `_y`, and `_rotation` already PASS — they likely
succeed via a different code path; investigate that path and
use it as the model for the remaining four properties (gate
the special-property dispatch on a flag indicating "this came
from a SWF4 `path:varname` lookup, not a regular GetMember").

**Bytecode trivia (worth knowing for related SWF4 tests).**
swfc emits asymmetric bytecode for slash-paths used as
expressions:
- `mc1` → `Push("mc1") + GetVariable`
- `/mc1` → `Push("/mc1")` only (no GetVariable — the literal
  slash-path is left on the stack as a string)
- `/:mc1` → `Push("/:mc1") + GetVariable`

This is why line 364 (`/mc1 == undefined`) "accidentally"
PASSED even before the convertFloat fix: the literal string
`/mc1` parses to 0.0 in SWF4 numeric coercion (no leading
digit), undefined parses to 0.0, 0 == 0 → true. Knowing this
prevents wasted time on `/mc1`-style cases that aren't actually
exercising GetVariable.

### ~~soft_reference_test1~~ — promoted to `ruffle_matched` (2026-05-04)

Now `ruffle_matched` 44/45 (97.8%). Root cause was NOT depth-bias /
goto-catchup-related as previously hypothesized — it was the `_name`
setter not propagating the rename to `parent.dynamic_props` and
`var_map`. After `mc._name = "newname"`, the stale `oldname` entry
still resolved to the MC and `_level0.newname` returned undefined,
breaking the test's "soft reference" semantics on the very first
assertion (`typeof(mc) == 'undefined'` after rename → expected PASS,
got FAIL because `mc` still resolved). Fix: in the `_name` setter
(`actionSetMember` MOVIECLIP path, `action.c:40711`), after updating
`mc->name`, sync `mc->parent->dynamic_props` (set new key → MC,
clear old key → undefined) and (only when `mc->parent ==
&root_movieclip`) `var_map` (with SWF<=6 lowercase folding). Only
fires when the existing entry is authoritative — references THIS MC
under a key matching the MC's old name — to avoid clobbering
case-collision entries (case-v6 path) or unrelated rebinds. Mirrors
Ruffle's `MovieClip::set_name`, which removes the old name binding
on the parent's stage-object scope and installs the new one. Final
remaining diff is line 164 (`mcRef == _level0.mc1` after
removeMovieClip + recreate at different depth) — same residual as
Ruffle's diff against expected, so the test promotes to
ruffle_matched. Verified: 24-test AVM1 lifecycle/clone/register
battery (24/24), 13-test gnash actionscript.all subset (13/13
effective), 4-test misc-swfc spot-check (4/4 effective),
`opcode_guard_test` and `DepthLimitsTest` unchanged.

### movieclip_destruction_test4 (20.0%, 8/40)

**Symptom (from latest diff).**

- Missing "Running frame2/frame3 actions of mc2[/brother2]" sprite
  frame DoAction traces — sprite frames don't fire during goto +
  removeMovieClip on dynamic clones.
- `typeof(brother1) == undefined` expected, got `movieclip` —
  removed brothers stay live.

**Hypothesis.** Composite of GOTO_CATCHUP_HYGIENE Phase 1 (stale
name resolution) and Phase 4 (sprite double-fire / no-fire). May
recover most lines after that plan lands.

**Scope.** Re-baseline after GOTO_CATCHUP_HYGIENE Phase 1 + Phase 4
land.

---

## Entries — other suites

### misc-mtasc.all/levels (63.2%, 43/68)

**Symptom.** Single failing misc-mtasc test (the other 8 pass,
including `function_test` 21/21). 23 FAILs in our output unchanged
from earlier (per CURRENT_STATUS earlier). Tests `_level0`,
`_level1` cross-level lookups.

**Hypothesis.** Level-based MC resolution edges. Not investigated
in depth.

**Scope.** 2-3 hours of triage. Single-test, not blocking anything.

### misc-swfmill.all/jump_to_prev_block

**Status updated 2026-05-01.** `tags_after_last_showframe` was
fixed in commit 9020f664 (recompiler END_TAG handler emits
`quit_swf=1` instead of looping the dangling frame). Only
`jump_to_prev_block` remains in this suite.

- `jump_to_prev_block`: bytecode `BranchAlways byteOffset=-56` jumps
  backward across DoAction tag boundaries. Recompiler emits a bare
  `return;` for the backward jump because each DoAction → its own
  C function. **Has a concrete fix plan now** — concatenate
  consecutive `DoAction` tags within a frame into a single
  bytecode buffer for recompilation, then the existing
  cross-buffer label/goto logic handles the back-jump naturally.
  See `incomplete/MISC_SWFMILL_PLAN.md` for the implementation
  steps and risks (estimated 30–60 lines in `swf.cpp`,
  low-to-medium effort).

---

## Suggested attack order

If picking work from this doc with no other context, the cheapest
wins:

1. ~~**`replace_sprites1test`**~~ — RESOLVED 2026-04-29 (PASS).
2. ~~**`sound`**~~ — RESOLVED 2026-05-02 via ignored_tests.txt (Path (b)).
3. **`opcode_guard_test`** (bug 2 fixed 2026-05-02; bug 1 deferred — needs ENTERFRAME-script-after-gotoAndPlay abort semantics, no longer waiting on cluster recovery).
4. ~~**`swf4opcode`**~~ — promoted to ruffle_matched 2026-05-02 (Group A defer).
5. **`matrix_test`** (6-9 hours, standalone-worthy) — three independent geometry / FP issues; promote to its own plan when work begins.
6. **`NetStream-SquareTest`** (4-6 hours, standalone-worthy) — netstream timing.
7. **`masks_test`** (verifier change required) — needs synthetic keypress mechanism. Promote to standalone plan; this is verifier scope.

Then (after the cluster plans land and recovery is measured):

8. `loop/loop_test10`, `EmbeddedFontTest`, `DrawingApiTest`,
   `DefineEditTextVariableNameTest`, `levels` —
   triage individually.

Blocked / skip (originally "re-baseline after cluster plans land",
but those plans are now blocked/superseded — see cluster table):

- `duplicate_movie_clip_test` — blocked by
  `incomplete/CLONESPRITE_DEPTH_BIAS_PLAN.md` Phase 2 (root cause
  confirmed 2026-05-02; see entry for details).
- `movieclip_destruction_test4`, `soft_reference_test1` — both depend
  on goto-catchup hygiene + display-list lifecycle work that no longer
  has a parent plan; treat as standalone if revisited.
- ~~`movieclip_destruction_test2`~~ — now PASS 56/56 (re-baselined 2026-05-02).
- `jump_to_prev_block`, `tags_after_last_showframe` (architectural
  blockers; move to `blocked/`).

## Why this is the right shape

The seven cluster plans have absorbed the major shared root causes;
what's left is a long tail of single-test issues. Writing seven
more standalone plans for these would create disproportionate
documentation overhead (each plan is mostly preamble). A combined
triage doc:

- Keeps the "what's left" question answerable in one read.
- Lets independent sessions pick a target without rediscovery.
- Naturally promotes entries to standalone plans as work
  warrants — the **Match / Symptom / Hypothesis / Scope** shape
  is enough for a session to pick up and run.

Once a cluster plan completes, re-baseline this doc — several
entries will resolve for free (per the "Suggested attack order"
step 3 above) and the long tail shrinks.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `MISC_MING_SWFC_PLAN.md` "Untackled / undocumented" + "misc-swfc.all" sections | This doc fleshes out those entries with concrete diff data and triage. |
| The 7 cluster plans listed at the top | Each absorbs a different shared root cause; this doc is the residual. |
| `complete/RUFFLE_KNOWN_FAILURE_HANDLING_PLAN.md` | Some entries here may auto-promote to `ruffle_matched` once filed-against-Ruffle behavior is detected. The sound entry is a candidate for `ACCEPTED_DIFFS.md` per its "Path (b)" recommendation. |
