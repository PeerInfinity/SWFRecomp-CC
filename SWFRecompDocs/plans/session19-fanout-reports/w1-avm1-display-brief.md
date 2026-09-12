# w1-avm1-display: wave-1 diagnosis of AVM1 display, event and timeline-order trace failures

Read `BRIEFS_COMMON.md` first. This is read-only work with no source edits. Deliverable:
`SWFRecompDocs/plans/session19-fanout-reports/w1-avm1-display-report.md`. Scratch dir: `<scratchpad>/w1-avm1-display/`.

## Your board (numbers from the wave-0 inventory; re-run each test before believing them)
**Head: hitArea second arc.** Both tests are undispositioned and not KF:
- `avm1/hitarea_sweep`: 3/33, we emit 37 lines.
- `avm1/hitarea_remove_owner_drag`: 5/10.

Session 18 shipped the first arc: `session18-fanout-reports/w2-avm1-hitarea-report.md`. It
named the rest as shape-based (not AABB) picking plus a single topmost pick: today every
AABB-containing button-mode clip fires, in creation order. Verify that claim, find where AVM1
picking happens (`action.c` / mouse dispatch), and price it as a wave-2 slice. Say which rows
each half (shape hit-test vs. topmost-only) flips.

**Timeline and action order (from_gnash/misc-ming.all/action_order, etc.):**
- `PlaceAndRemove`: 15/96, we emit 45. Not KF.
- `action_execution_order_test11`: 26/32, not KF. s17 `wave1-timeline-order.md` has M5/M6
  NO-GO; re-verify against HEAD and do not re-derive.
- KF family, pricing `ruffle_matched` reachability where RTXT exists: `ActionOrderTest3` 4/62,
  `ActionOrderTest4` 10/64, `ActionOrderTest5` 6/51, `action_execution_order_test6` 0/24,
  `action_execution_order_extend_test` 7/32 (no RTXT).
- `from_gnash/misc-swfc.all/movieclip_destruction_test3` 5/18 (KF), `_test4` 8/40 (KF, RTXT).
- `from_gnash/misc-ming.all/PrototypeEventListeners`: 1/32 (KF).
- `from_gnash/misc-ming.all/masks_test`: 28/175 (KF, RTXT), and we emit exactly 28, so check for an
  early stop.
- `timeline/missing_frame_scripts`: 12/22. Per arc §19.4, S3/S4 are main-timeline advance/removal,
  NOT orphan-phase.
- `text/links_in_scrolled_text`: 0/1 (the s16 patch still yields 0 flips).
- `avm1/edittext_onscroller`: 0/14 (KF, RTXT), and we emit 0 lines.

**Optional, only if time remains:** `from_gnash/misc-swfc.all/gotoFrameFromInterval`, which is
workflow-excluded on purpose. It uses 0.0001 ms setIntervals, and `timer.c` has no
minimum-interval floor. Price a 10 ms floor, and name the full-corpus both-modes A/B it would need.

Siblings: w1-avm1-builtins (gnash MovieClip/array/TextField/set_property_values/Drawing/Gradient),
w1-loaders (MCL + loaders + mixed_avm), w1-avm2, w1-drift, w1-gfx-geometry, w1-gfx-text-filters,
w1-gfx-stage3d.
