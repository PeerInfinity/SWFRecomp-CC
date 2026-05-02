# Remaining Tail Triage

<!-- TESTS: matrix_test, DefineTextTest, DefineEditTextVariableNameTest, EmbeddedFontTest, DrawingApiTest, NetStream-SquareTest, loop/loop_test, loop/loop_test10, replace_sprites1test, opcode_guard_test, masks_test, duplicate_movie_clip_test, swf4opcode, soft_reference_test1, movieclip_destruction_test4 -->

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

| Cluster plan | Tests covered |
|--------------|---------------|
| `DEFERRED_CLIP_UNLOAD_PLAN.md` | loop_test6/7/8, action_execution_order_test2/3/5/11, ActionOrderTest3/4/5 |
| `CLONESPRITE_DEPTH_BIAS_PLAN.md` | displaylist_depths_test/2/3/8/9, DepthLimitsTest, duplicate_movie_clip_test/2 |
| `BUTTON_INFRASTRUCTURE_PLAN.md` | RollOverOutTest, ButtonEventsTest, ButtonPropertiesTest, key_event_test, DragDropTest, button_test1, mouse_drag_test |
| `ZERO_OUTPUT_TRIAGE_PLAN.md` | BeginBitmapFill, Version4Loader, frame_label_test, replace_buttons1test, replace_shapes1test, LoadVarsTest, opcode_guard_test2 |
| `REGISTERCLASS_LIFECYCLE_PLAN.md` | registerClassTest, registerClassTest2, RegisterClassTest3, RegisterClassTest4 |
| `GOTO_CATCHUP_HYGIENE_PLAN.md` | goto_frame_test, consecutive_goto_frame_test, place_and_remove_object_insane_test |
| `IMPORT_CHARACTER_PLAN.md` | attachImported, attachMovieLoopingTest, loadMovieTest |

Everything else lives here.

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

### matrix_test (84.0%, 912/1086) — multi-issue

**Symptom.** Three independent issues per `MISC_MING_SWFC_PLAN.md`:

- Negative `_yscale` matrix decomposition off (`d` field sign / value
  mismatch).
- `getBounds` after rotate-with-scale produces wrong bounds.
- `sin(90°)` produces `6e-17` precision residue instead of clean `1`.

**Hypothesis.** None are runtime bugs in shared infrastructure;
each is its own narrow geometry / FP edge.

**Scope.** Each issue is 1-3 hours independently. Three issues =
6-9 hours total. **Promote to standalone plan when work begins** —
it's already big enough to warrant its own document.

### DefineTextTest (68.8%, 11/16)

**Symptom.** Per `MISC_MING_SWFC_PLAN.md`: `288.05` expected,
`288.049987792969` obtained (FP precision residue, single→double
round-trip somewhere). Plus `_global.clicks == 2` got `15` —
mouse-click counter mismatch (input-driven assertion in a test
without `input.json`).

**Hypothesis.** FP residue is a `(float)` round-trip in text width
calculation — same family as `attachMovieLoopingTest`'s
`15.0000001716614` (see `IMPORT_CHARACTER_PLAN.md` Phase 4). The
`clicks == 2 vs 15` part is masks_test-style: test reads keyboard /
mouse without an `input.json`, so the counter ends up wrong.

**Scope.** 1-2 hours for the FP fix. The mouse part is wedged
unless we add an input.json synthesizer (out of scope for this
doc — would need its own plan).

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

### EmbeddedFontTest (57.5%, 50/87) and DrawingApiTest (46.2%, 43/93)

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

### loop/loop_test (23.8%, 5/21)

**Symptom (from earlier diff):**

```
- 3  PASSED: 47616 == 47616         ← interleave order
+ 3  PASSED: -16381 == -16381
- 4  PASSED: -16381 == -16381
+ 4  PASSED: 47616 == 47616
- 5  PASSED: -16381 == -16381
+ 5  FAILED: expected: -16381 , obtained: 47616
...
- 13  PASSED: 1 == 1
+ 13  FAILED: expected: 1 , obtained: 4
```

Test pushes both biased (`47616 = 31232 + 16384`) and unbiased
(`-16381 = -16384 + 3`) depths and tests interleaved frame
execution with two MCs at those depths.

**Hypothesis.** Likely the same `CLONESPRITE_DEPTH_BIAS` trade-off
("CloneSprite depth-bias trade-off (open)") manifesting through a
different execution path. Once `CLONESPRITE_DEPTH_BIAS_PLAN`
Phase 1 (recompiler bias-strip) lands, the `47616 / -16381`
arithmetic stops matching either expectation cleanly — but the
*ordering* might recover. The `1 == 1 / 1 vs 4` line suggests a
counter that increments more times than expected, separate from
depth.

**Scope.** Re-run after CLONESPRITE_DEPTH_BIAS lands; if still
failing, 2-3 hours of further investigation.

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

### opcode_guard_test (55.6%, 10/18 — re-baselined 2026-05-02)

**Symptom (current diff).** Output diverges starting at the post-`mc2 EnterFrame called`
block. After `setTarget('non-exist-target')` followed by AS that reads
`current_target = _target` and `_root.check_equals(current_target, undefined)`,
expected emits `PASSED: undefined == undefined` then `PASSED: / == /`.
Our actual emits an extra `FAILED: false` line first, then the runtime
warning `Target not found: Target="non-exist-target" Base="_level0"`,
then `PASSED: undefined == undefined`, then `FAILED: expected: / , obtained: undefined`.
We end with #passed: 10 / #failed: 3 / #total: 13 (vs expected 11/0/11).

**Cannot promote to `ruffle_matched`.** Our diff is **not a subset of
Ruffle's** `output.ruffle.txt` (which itself diverges from `output.txt`
on different lines — Ruffle emits `Target not found: …` then `PASSED: undefined == undefined`
without the leading `FAILED: false`, and reports #passed: 8 / #failed: 3).
Our extra `FAILED: false` and the `_target == /` line both fall outside
Ruffle's diff set, so the subset check rejects promotion. Stderr also
shows two `heap_alloc() called before heap_init()` / `Failed to allocate
property name` warnings during the run — likely a separate issue, but
worth checking whether they correlate with the missed-property cases.

**Hypothesis.** Two distinct bugs stacked:
1. The leading `FAILED: false` is from the asm block
   (`push 'current_target' ; push '' ; push 11 ; getproperty ; setvariable`)
   — `getproperty` of `_target` (index 11) on `''` is producing `false`
   and the result is being traced rather than just stored. Or the
   `actionSetTarget("non-exist-target")` failure path emits `FAILED: false`
   somewhere.
2. The `_target == '/'` check: after a failed SetTarget, reading `_target`
   should still return `'/'` (the root path) — Ruffle does this. We return
   `undefined` instead, which suggests our `g_settarget_invalid` /
   `g_settarget_none` flags also gate the `_target` getter, when they
   should only gate MC method calls and goto/play/stop dispatches.

**Scope.** 1–3 hours independently of GOTO_CATCHUP_HYGIENE — the bugs
are in the SetTarget invalid-target handling for `_target` reads, not
post-removal name resolution. The earlier hypothesis ("pending-removal
MC visibility") was wrong: the test's failures are around an invalid
SetTarget, not around a removed MC.

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

### duplicate_movie_clip_test (9.1%, 3/33)

**Symptom.** Multi-issue per `MISC_MING_SWFC_PLAN.md`. Most failures
likely overlap `CLONESPRITE_DEPTH_BIAS` (negative AS depth handling)
but `_test2` is partially-fixable through that plan; `_test1` has
deeper issues including nested `duplicateMovieClip` paths.

**Hypothesis.** Re-baseline after `CLONESPRITE_DEPTH_BIAS` Phase 1
lands; expect significant recovery, then narrow remaining issues.

**Scope.** Defer until CLONESPRITE_DEPTH_BIAS lands. May resolve
fully or partially.

---

## Entries — misc-swfc.all

### sound (100% match-rate, 7/7) — output_mismatch via trailing extras

**Symptom.** Expected output ends at line 7 (`PASSED: snd.position
== 0`). Our actual continues for 5 more lines (`Total tests run:
1`, `FAILED: TOTAL tests run: 1, expected: 2`, `#passed: 1`,
`#failed: 1`, `__END_OF_TEST__`). The expected output literally
truncates mid-test — Flash never reaches `__END_OF_TEST__` because
it's waiting for sound playback.

**Hypothesis.** Sound timing divergence: our impl reaches `gotoAndPlay(8)`
too early (before sound finishes), then runs the totals. Flash's
sound-position tracking is keeping the test in a wait state.

**Scope.** Documented elsewhere as blocker. Two paths:
(a) Implement sound-position tracking that matches Flash's wall-clock
behavior. (b) Document as `ACCEPTED_DIFFS.md` since the expected
output is itself incomplete (Flash never finishes the test).

**Recommendation.** Path (b) — add to gnash ACCEPTED_DIFFS or to
`ignored_tests.txt`. The test's expected output is a partial
trace from an interactive Flash session; matching it fully would
require non-deterministic timing simulation.

### movieclip_destruction_test2 (92.9%, 52/56)

**Symptom.** 2 lines remain failing: explicit `mc2.onUnload()`
invocation produces no trace output. Documented blocker in
`CURRENT_STATUS.md` "movieclip_destruction_test2 — onUnload depth
shift + swapDepths gating" section.

**Hypothesis.** Documented: function is invoked (debug-confirmed)
but inner `_root.check_equals` calls produce no trace when invoked
from a user-method-dispatched function on a pending-removal MC.
Likely a deeper issue with stack/scope state during dispatch.

**Scope.** 3-5 hours of dispatch investigation. **Already in
CURRENT_STATUS.md — do not re-document.** Cross-reference here
for completeness.

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

### soft_reference_test1 (31.1%, 14/45)

**Symptom (from earlier diff).** Multiple `FAILED:` lines on
`xcheck`-style assertions plus `mcRef.getDepth()` returns empty
after createEmptyMovieClip + various property checks:

```
PASSED:                   ← expected (xcheck)
FAILED:                   ← actual (something passed when it shouldn't)
...
FAILED: mcRef.getDepth(): expected: "30" obtained: ""
```

**Hypothesis.** Tests "soft references" — MovieClip references
that should remain valid across various lifecycle events (rewind,
swapDepths, etc.). Our impl returns empty for `getDepth()` when
the MC is in a transitional state. Likely overlaps
`CLONESPRITE_DEPTH_BIAS` and `GOTO_CATCHUP_HYGIENE` Phase 1.

**Scope.** Re-baseline after both adjacent plans land; remaining
issues likely 2-3 hours.

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

1. **`replace_sprites1test`** (1-2 hours, bundles into ZERO_OUTPUT_TRIAGE Phase 2) — expand the CONSTRUCT gate from buttons-only to "any same-family replace."
2. **`sound`** (1 hour) — accept the divergence; add to `ignored_tests.txt` / `ACCEPTED_DIFFS.md`. The expected output is incomplete from an interactive Flash session; matching it fully would require timing simulation.
3. **`opcode_guard_test`, `movieclip_destruction_test4`, `soft_reference_test1`, `duplicate_movie_clip_test`, `loop/loop_test`** — re-baseline after the relevant cluster plans (`GOTO_CATCHUP_HYGIENE`, `CLONESPRITE_DEPTH_BIAS`) land. Each may recover for free.
4. **`swf4opcode`** (4-6 hours, standalone-worthy) — SWF4 path syntax. Self-contained; no overlap with other plans.
5. **`matrix_test`** (6-9 hours, standalone-worthy) — three independent geometry / FP issues; promote to its own plan when work begins.
6. **`NetStream-SquareTest`** (4-6 hours, standalone-worthy) — netstream timing.
7. **`masks_test`** (verifier change required) — needs synthetic keypress mechanism. Promote to standalone plan; this is verifier scope.

Then (after the cluster plans land and recovery is measured):

8. `loop/loop_test10`, `EmbeddedFontTest`, `DrawingApiTest`,
   `DefineTextTest`, `DefineEditTextVariableNameTest`, `levels` —
   triage individually.

Skip:

- `movieclip_destruction_test2` (already documented blocker —
  do not re-investigate without a new hypothesis).
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
