# w2-loaders: implement the three GO items from `w1-loaders-report.md` (worktree agent)

Read `BRIEFS_COMMON.md` (including the wave-2 section) first, then
`SWFRecompDocs/plans/session19-fanout-reports/w1-loaders-report.md` in full. That report is your
diagnosis of record: it was written by a sibling agent today against this baseline, and its
fixtures, Ruffle oracles and actual outputs are in
`<scratchpad>/w1-loaders/` (`btnfix/`, `mclfix/`). Do not re-derive it — but DO re-verify each
before/after claim yourself, because an in-isolation ledger is only a lower bound.

You work in your own git worktree. Nothing commits; you deliver patches.

## Deliver THREE SEPARATE patches, so the coordinator can land them as separate commits
Name them `w2-loaders-1-loaderevents.patch`, `w2-loaders-2-simplebutton.patch`,
`w2-loaders-3-mcltick.patch`, each with its own before/after ledger in your report.

**1. `avm2/loader_events_2` → `ruffle_matched` (+1 effective, the only headline flip here).**
Exactly 4 missing lines, two mechanisms: (a) LoaderInfo `unload` dispatch in `loader_drop_content`;
(b) a parentless `added` fired at the loaded root's construction — Ruffle's `fire_added_events`,
where our `on_construction_complete` gates on `parent != NULL` and `loader_boot_child_swf` never
calls it. The report says only 4 corpus tests listen for `Event.ADDED` on a loaded child and only
this one can see it: **verify that blast-radius claim yourself** before relying on it, and run
those four tests both ways.

**2. Loaded child `SimpleButton` states (~6 lines, `button_data_for_char` in `avm2_display.c`).**
A `g_child_movies` fall-through. **0 corpus flips**, so the deliverable is the fix plus a new
`regression/avm2_child_simplebutton` test built from the fixture in `btnfix/`. The expected output
must come from the Ruffle exporter oracle, never from our own output. List every new file at the
top of your report (the coordinator stages by name), and remember the `regression` suite is
git-tracked, so the SWFs belong in the patch.

**3. MCL L1a: `onLoadInit` after `enterFrame`, and drop the child double step.** 0 corpus flips;
new fixture `regression/avm1_mcl_load_tick` from `mclfix/`. Phase 3 must drain immediately BEFORE
`actionAdvancePlayingLevels` (`swf_core.c:1462`), not at the existing end-of-tick MCL site.
**L1b is REFUTED and out of scope**: our one-tick-later delivery is Flash's order, it is what
`from_shumway/avm1/moviecliploader` grades, and moving to Ruffle's tick would be a rule-3
regression for 0 gain. Do not touch the two-bucket deferral. If item 3 threatens
`from_shumway/avm1/moviecliploader` or any `regression/avm1_mcl_*` test, stop at a HOLD and say so
— it is a 0-flip quality item and is not worth risk.

## Required checks before delivering
- Headline: `avm2/loader_events_2` (`--tests-dir=ruffle-tests/tests/swfs/avm2`), before and after.
- Loader/MCL neighbours: `from_shumway/avm1/moviecliploader`, `from_shumway/as3-loader/events/loader-events`,
  `avm2/loader_load`, `mixed_avm/avm2_loads_avm1_events`, plus the four `Event.ADDED` listeners you
  identify, and `avm2/loader_try_click_root` / `large_preload_from_bytes` (s18's loader flips).
- The whole `regression` suite is small: run the `avm1_mcl_*`, `avm2_parent_child_*` and any
  loader-named members (`--tests-dir=ruffle-tests/tests/swfs/regression`).
- Both patches 1 and 3 touch tick/event ORDER, so state explicitly whether patch 3 changes any
  result that patch 1 also touches (stack them and re-run the headline once).

Sibling wave-2 agents may be editing `avm2_display.c` (Stage3D/other AVM2 slices). Self-localize:
new static helpers, no reformatting, no drive-by edits. Tell the coordinator immediately (final
message) if you need a function a sibling is likely to own.
