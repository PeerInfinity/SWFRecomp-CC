# Button Residual Plan

<!-- TESTS: ButtonEventsTest, key_event_test, DragDropTest, button_test1 -->

<!-- PLAN_META
id: BUTTON_RESIDUAL
status: pending
phases:
  - id: 1
    name: "ButtonEventsTest residual lines"
    status: partial
  - id: 2
    name: "key_event_test progression past frame 5"
    status: deferred
  - id: 3
    name: "DragDropTest _level50 droptarget"
    status: deferred
  - id: 4
    name: "button_test1 remaining mismatches"
    status: complete
dependencies: []
blockers: []
parent_plan: "complete/BUTTON_INFRASTRUCTURE_PLAN.md"
-->

## Session progress (2026-05-05)

- **Phase 4 — `button_test1` (misc-swfc.all) → PASS (+1, 20/31 → 31/31).** Two
  changes in `SWFModernRuntime/src/libswf/tag.c` `ng_update_button_states_in_dl`
  (the headless button hit-test/state machine):
  1. Recurse into sprites in the display list. Previously the loop only
     descended into nested *buttons*; nothing walked into a sprite to look for
     buttons inside it. button_test1's structure is `button3 → buttonContainer
     (sprite) → button1 + button2`, so the inner buttons never received
     hit-test or press dispatch even though `button3.instance1.button1` etc.
     resolved as movieclips. Mirrors Ruffle's `mouse_pick_avm1` which walks
     the render list for interactive children before falling back to the
     button's own `hit_area`.
  2. Replace `hit_test_shape` (triangle-mesh hit) with `ng_hitTestShapeChar`
     for resolved button hit shapes. In NO_GRAPHICS mode shapes carry only
     path data (`ng_record_char_path`) — `shape_offset/size = 0/0` — so the
     triangle-based test always returned 0. `ng_hitTestShapeChar` understands
     path-based hit testing and is what the rest of the runtime uses for
     `hitTest`. Made it non-static and added a public extern in
     `tag.c`. Also extended `resolve_hit_shape` to return the resolved char
     id (and accept morph shapes).
  3. The first inner-button hit consumes `*found_hover` so the outer button
     does not also press. Matches Ruffle's "first interactive child wins"
     semantics, and is exactly what button_test1's expected output requires
     (`green box`/`red box` only — never `button3` from the outer button's
     handler).

- **Phase 1 partial — `ButtonEventsTest` line 2 (`square1.button instanceOf
  Button`) fixed.** `instanceOfCoercing`'s MOVIECLIP arm fell back to
  `MovieClip.prototype` when a button MC had no `dynamic_props.__proto__`. In
  Flash/Ruffle, buttons are their own type with chain `Button.prototype →
  Object.prototype`, NOT a subclass of MovieClip — so the walk never hit
  `Button.prototype`. Fix: when the receiver is `is_button_mc`, fall back to
  `g_stub_ctors[1].prototype_obj` (lazy-init via `initButtonPrototype`) before
  the `MovieClip.prototype` fallback. Files:
  `SWFModernRuntime/src/actionmodern/action.c` `instanceOfCoercing`. Verified:
  9/9 prototype/instanceof regression suite (`as2_super_and_this_v6/v8`,
  `extends_chain`, `register_class_return_value`, `register_and_init_order`,
  `on_construct`, `function_as_function`, `add_property`, `watch`), 14/14
  AVM1 button + 4/4 drag tests, gnash `ButtonPropertiesTest` and
  `RollOverOutTest` still effective, `Inheritance-v5..v8` all
  ruffle_matched. `attachMovie`-installed button MCs were already correct via
  the `__proto__` setup at line 50855-50869 of `action.c`; this fix covers
  timeline-placed button MCs whose `dynamic_props` is created without an
  explicit `__proto__`.

  ButtonEventsTest is still `output_mismatch` overall. The remaining failures
  are deeper architectural issues outside the scope of "narrow residual fix":
  - Lines 43-51: `_root.buttonChild[10/12]` array entries undefined. The
    test's button-child sprites have frame-0 actions that populate
    `_root.buttonChild[getDepth()+16383] = {nam, exe, uld}`. Either the
    sprites' frame scripts aren't running, or `getDepth()` doesn't return
    the expected `-16373/-16371` for button-state child sprites.
  - Line 53: `_level0.square1.button.instance6.getDepth()` returns -16372
    expected -16371 (off-by-1 on button child sprite depth).
  - Lines 59+: long divergence — test progression flow forks into
    `PASSED: / == /` (likely OnLoad/onConstruct firing on the wrong clip)
    rather than the expected per-frame state-machine traces.

  These need a dedicated session and likely rope in the
  CONSTRUCT_PARAMETER_REPLAY_PLAN-style sprite-init lifecycle work for
  button-state child sprites.

- **Phase 2 deferred — `key_event_test`.** Past line 30, failures are listener
  ordering / `removeListener` semantics: dynamic_mc.onKeyDown is fired before
  `listenerClip2.onClipKeyDown` (we have it after), and the `'0+ls3+ls2+ls1+...'`
  vs `'0+ls3+ls1+ls2+ls3+ls1+ls2+...'` divergence at line 57/63 indicates we
  have duplicate listener firings. Multi-faceted Key.addListener / clip-event
  KEY_DOWN interleaving rework — defer.

- **Phase 3 deferred — `DragDropTest`.** Levels are loading correctly (the
  later `loadedTarget/*` cluster, lines 25-32, all pass). The failures are all
  `_level50/*` `_droptarget` lines: when the dragger is over a target inside
  `_level50`, `_droptarget` is empty rather than `_level50/target10`. The
  `find_drop_target_in_dl` walk in `tag.c` doesn't include level MCs in its
  iteration. This isn't blocked on level-loading itself (LEVELS_PLAN landed)
  but on extending `_droptarget` resolution to walk all levels. Defer.

## Background

`complete/BUTTON_INFRASTRUCTURE_PLAN.md` covered 7 button/drag/key tests
across 6 phases (Phases 1-6). Three fully landed: `ButtonPropertiesTest`,
`RollOverOutTest`, `mouse_drag_test`. Four still fail in CI at `c5994ec1`
(2026-05-05):

| Test | Suite | Pass-rate (CI `c5994ec1`) | Phase that improved it |
|------|-------|--------------------------|------------------------|
| `ButtonEventsTest` | misc-ming.all | unknown — listed `output_mismatch` | Phase 1 + 3 |
| `key_event_test` | misc-ming.all | ~33/66 (lines 1-30 match) | Phase 6 |
| `DragDropTest` | misc-ming.all | ~25/44 | Phase 4 |
| `button_test1` | misc-swfc.all | 18/31 | Phase 2 |

This plan is the residual: the BUTTON_INFRASTRUCTURE phases got each
test most of the way, but each has a distinct remaining issue not
covered by the original phase plan.

## Phase 1 — ButtonEventsTest residual

Per the parent plan's "Open questions" section: `obj instanceOf Button`
(line 2 of the test) still fails. The runtime has both a Button
*constructor* (registered via `g_ctors[i]`) and a per-MC `is_button_mc`
flag; verify they route correctly. May tie back into Phase 1 (typeof
fix) or Phase 3 (prototype enum).

**Investigation steps:**

1. Run `verify_output.py --test=ButtonEventsTest --diff --verbose` and
   inspect line 2's diff.
2. Trace `instanceOf` resolution for an `is_button_mc=1` MC: does it
   walk to `Button.prototype`?
3. Compare against Ruffle's
   `core/src/avm1/object/movie_clip.rs` for how Button MCs participate
   in `instance_of`.

## Phase 2 — key_event_test progression past frame 5

Phase 6 of the parent plan got us through tests 1-5 (lines 1-30). Tests
6-10 (lines 31-66) still fail. Per the parent plan's Phase 6 description,
the per-frame `stop()` calls were the blocker for tests 1-5; the
remaining tests likely have their own progression gates (different key
codes, different frames, listener add/remove ordering).

**Investigation steps:**

1. Run with `--diff --verbose`, identify the first failing line after
   line 30.
2. Inspect what the test expects between frames 5-10 (load the SWF in
   a disassembler, or read `key_event_test.sc` if present in
   gnash-master upstream).
3. Most likely: Key.removeListener / Key.addListener round-trip across
   key event boundaries.

## Phase 3 — DragDropTest `_level50` droptarget

Per the parent plan's Phase 4 description: lines 4-32 (target10/20/100
+ loadedTarget) PASS; remaining failures are `_level50/*` blocked on
loadMovie level support. So this phase depends on
`from_gnash/_investigation/complete/LEVELS_PLAN.md` (or its successor)
producing level-loaded MCs that participate in `_droptarget` static
walks.

**Investigation steps:**

1. Confirm whether LEVELS_PLAN landed level-loaded MC creation; if so,
   run DragDropTest and check whether `_droptarget == "/_level50/..."`
   resolves correctly.
2. If levels still don't land MCs: this phase is blocked on level
   loadMovie work (already on the `Where to Focus` list in
   `OVERVIEW.md`).

## Phase 4 — button_test1 remaining mismatches

Phase 2 of the parent plan brought button_test1 from 8/31 → 18/31. The
remaining 13/31 are likely button-internal sprite resolution edges that
weren't covered by the eager state-0 init. Possibilities:

- Multi-state button (state_funcs[1..3] not eagerly run).
- Button-inside-button child resolution.
- `button.instance1.instance2` deep-path resolution.

**Investigation steps:**

1. Run `verify_output.py --test=button_test1 --diff --verbose` (in
   misc-swfc.all dir).
2. Identify which assertions fail — Dejagnu format makes the
   condition text visible.
3. Compare to Ruffle's button child resolution.

## Verification battery

**Required-pass guardrail (must not regress):**

- AVM1: 14 button tests + 4 drag tests.
- Gnash misc-ming: `ButtonPropertiesTest`, `RollOverOutTest`,
  `mouse_drag_test` (already passing — Phases 3 / 5 / 4 of parent
  plan).
- Gnash misc-swfc: `mouse_drag_test`.

## Why this is the right shape

The parent plan's six phases addressed the *architectural* button
issues (typeof, prototype enum order, eager state init, _droptarget
infrastructure, mask hitTest, key listener phase progression). Each
remaining failing test has a *narrow* residual issue that doesn't fit
back into the architectural phases. Tracking these as a small
follow-up plan keeps the parent plan's "complete" status accurate
while not orphaning the residual work.

## Estimated session budget

- Phase 1: 1-2 hours.
- Phase 2: 2-4 hours (test progression issues are usually deeper).
- Phase 3: 30 min if levels works, else blocked.
- Phase 4: 1-2 hours.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `complete/BUTTON_INFRASTRUCTURE_PLAN.md` | Parent plan. This plan covers residual work after parent's 6 phases landed. |
| `complete/LEVELS_PLAN.md` | Phase 3 depends on level-loaded MC creation. |
| `incomplete/REMAINING_TAIL_TRIAGE.md` | These tests appeared in REMAINING_TAIL_TRIAGE's cluster table under BUTTON_INFRASTRUCTURE_PLAN; promoting them to a dedicated plan reflects that the parent plan didn't fully resolve them. |
