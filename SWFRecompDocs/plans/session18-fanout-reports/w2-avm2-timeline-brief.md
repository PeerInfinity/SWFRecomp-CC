# w2-avm2-timeline — wave 2: AVM2 timeline pair (+2 proven/priced)

Read `BRIEFS_COMMON.md` (incl. wave-2 rules) and `SIBLING_FILE_MAP.md`, then the diagnosis of
record: `w1-trace-display-report.md` §2 L1 and L2, plus §3's `missing_frame_scripts` entry and §5
(the `--save-actual` / `AVM2_NO_WALK_SKIP=1` method notes). Isolated worktree; no commits.

## Scope
1. **L1 `timeline/frame_script_cleanup_goto2` 12/34 → pass (PROVEN with `AVM2_NO_WALK_SKIP=1`):**
   the `addFrameScript` `PHASE_FRAME_SCRIPTS` arm (`avm2_display.c` ~:7921) pushes to the cleanup
   queue but never calls `avm2_display_mark_frame_work`, so descendants stay `walk_clean` and the
   `no_op_goto` stage walk skips them. Add the call. Sibling w2-avm2-new-smalls adds a `#2001`
   argc check at the ENTRY of the same function — put your one line inside the phase arm only.
2. **L2 `avm2/orphan_removeobject` 340/636 → pass (~10 lines):** port Ruffle's
   `cleanup_dead_orphans` rule (`~/CC/ruffle/core/src/display_object/.../orphan_manager.rs:65-92`
   — grep for it): orphans NOT `placed_by_avm2_script` (removed by a RemoveObject tag) leave the
   orphan list at end of frame. Our `orphan_cleanup` (~:181) keeps advancing them.
3. Rider: `timeline/missing_frame_scripts` 12/22 — §3 says S4 may be subsumed by L2. Grade
   before/after; report the delta; do not chase S3.

## Verification
Headline: the 3 tests. Canaries (byte-identical `--diff` before/after; use `--save-actual` and
positional compare where the display is offset by a leading blank): every PASSING test in suite
`timeline` (all 15), `avm2/orphan_*`, `avm2/movieclip_*` (sample 10 incl. goto/addframescript
ones), `avm2/goto_*`/`avm2/*rewind*`, `from_shumway/timeline/*`, `avm2/removeobject*`, and the
`regression` suite's AVM2 timeline tests (grep README for goto|frame|orphan). Run 3 in
`--mode=graphics`. `-P 2`, compile timeout 2400, `--recompile` on first use of copied dirs.
Free triage axis: run `AVM2_NO_WALK_SKIP=1` on any canary that changes, to separate walk-skip
effects from your edit.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-avm2-timeline.patch` + `w2-avm2-timeline-report.md`
(NEW files first; ledger; refutations; unclaimed leads). Copy to the main tree if allowed.
Runtime-only → copying `SWFRecomp/build` is valid.
