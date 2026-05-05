# Button Residual Plan

<!-- TESTS: ButtonEventsTest, key_event_test, DragDropTest, button_test1 -->

<!-- PLAN_META
id: BUTTON_RESIDUAL
status: pending
phases:
  - id: 1
    name: "ButtonEventsTest residual lines"
    status: pending
  - id: 2
    name: "key_event_test progression past frame 5"
    status: pending
  - id: 3
    name: "DragDropTest _level50 droptarget"
    status: pending
  - id: 4
    name: "button_test1 remaining mismatches"
    status: pending
dependencies: []
blockers: []
parent_plan: "complete/BUTTON_INFRASTRUCTURE_PLAN.md"
-->

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
