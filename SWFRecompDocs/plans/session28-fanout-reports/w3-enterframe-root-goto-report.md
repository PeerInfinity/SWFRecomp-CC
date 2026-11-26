# s28 w3-enterframe-root-goto: report (wave 2, implementation)

**New files:**
- `ruffle-tests/tests/swfs/regression/avm1_enterframe_root_goto_opcode/` — `create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt` (= the first 7 lines of the coordinator's FP32 direct capture `flash32.trace.txt`).
- this report, and `w3-enterframe-root-goto.patch`.

No new source files, and no canary members (this is a trace-only change in a path the canary never reaches, see below).

## Verdict: GO, 1 trace flip (the new fixture), zero corpus movement in either mode

- **`regression/avm1_enterframe_root_goto_opcode`: output_mismatch → pass** (graphics and no-graphics).
- **Nothing else moves.** Every gnash `actionscript.all` / `misc-*` row, the 16 avm1 goto/enterframe rows and the whole
  `regression` suite: 654 rows per mode. The rule fired in 245 of them. Those 245 print **byte-identical** output
  before and after in both modes, apart from the fixture.
- The render canary (195 tests, 260 PNGs) is md5-identical before vs after (see "Canary").

Patch scope: **`action.c` `actionGotoFrame` only**. It deletes the `g_inside_enterframe_dispatch` early return (11 lines
out, a comment in). It touches no other function, file, `#ifdef` arm or the recompiler. The arm is shared by every build
(no-graphics, graphics-native and, since `dc6c75a64`, the browser), so all three get the fix.

## Why the rule existed, and why it is dead now

- The rule came in with `fc0f8e4fd5` (2026-03-16, "Skip GotoFrame entirely from enterFrame handlers", NO_GRAPHICS only
  back then). It was written for gnash Dejagnu `Boolean-v5`: "the enterFrame callback's gotoAndPlay(0) is silently
  ignored" so that the frame loop advances 0→1→2 by itself. Later the `#ifdef` was dropped, so all modes took it.
- **What it actually dropped, measured.** I logged (env-gated, now removed) every time the arm was reached, across all
  654 gate rows in both modes. It fired in 244 corpus rows: all 243 `actionscript.all` rows plus
  `misc-ming.all/gotoFrame2Test`. Every firing was the same event: **`goto frame 0` while the root is stopped on frame 0**
  (`goto=0 cur=0 playing=0`, exactly once per run, in both modes: 488 log lines = 244 rows × 2 modes). The only other
  firing was the new fixture (`goto=2 cur=0`).
- **The Flash-correct model is "a goto to the current frame is a no-op", and the runtime already has it.** Since the rule
  was written, `ng_executeGotoCatchUp` gained a self-goto guard (`swf_core.c` `ng_executeGotoCatchUp`,
  `if (target == original_frame)`, and its port in `swf.c`). It consumes the request without replaying tags or
  re-running `funcs[target]`. Without the rule, the Dejagnu goto falls through to `actionGotoFrame`'s normal path. That
  path sets `is_playing=0` (it was already 0) and `currentframe=1` (it was already 1), and then the guard returns. So
  removing the rule changes nothing for any row except a goto to a *different* frame. That is the case the fixture pins
  and that Flash runs inline.
- "Retries every tick" does not describe any row in the corpus. No row reached the arm more than once per run.

## Per-test before/after (same box; before = clean `origin/master` 7f4f4858)

| test | mode | before (origin/master) | after (patch) |
|---|---|---|---|
| `regression/avm1_enterframe_root_goto_opcode` | graphics | output_mismatch (`after cf=1`, root stays on 1; md5 20638690ce) | **pass** (md5 484193f5dc) |
| `regression/avm1_enterframe_root_goto_opcode` | no-graphics | output_mismatch (same) | **pass** |
| `from_gnash/actionscript.all/Boolean-v5` (the rule's original target) | both | pass (23399e3f62) | pass, identical |
| `from_gnash/misc-ming.all/gotoFrame2Test` (only `misc-*` row the rule fired in) | both | pass (fdb2956337) | pass, identical |
| `from_gnash/actionscript.all/argstest-v6` (baseline-failing, rule fires) | both | output_mismatch (401f06dd1d) | output_mismatch, identical |

Fixture after-output (5 ticks): `f1 / ef cf=1 / after cf=3 / f3 cf=3 / ef cf=3 ×3`. This is the FP32 order: the playhead
moves inside the handler, and frame 3's DoAction runs right after the handler returns. `onEnterFrame` first fires on
tick 2 (checked with num_frames 1/2/3: `f1`; `+ef cf=1, after cf=3, f3 cf=3`; `+ef cf=3`). So 5 ticks = 7 lines, and the
golden is the first 7 lines of `flash32.trace.txt`.

## Gate (both modes)

How it was run: the instrumented build took `EF_RULE_ON=1` to restore the early return (= origin/master behaviour) and
`EF_RULE_LOG` to record reach. "After" ran all 654 rows with logging. "Before" ran every row where the arm was reached.
A row where the arm is never reached runs the same code in both legs, so it cannot move. To prove the env-switch before
leg equals real origin/master, I also ran the headline rows on a truly clean tree: same md5s (table above).

| leg | rows | pass | ruffle_matched | output_mismatch | arm reached |
|---|---|---|---|---|---|
| graphics, after | 654 | 561 | 88 | 5 | 245 |
| no-graphics, after | 654 | 561 | 88 | 5 | 245 (same set) |
| graphics, before vs after on the 245 reached rows | 245 | — | — | — | **244 byte-identical, 1 moved (fixture)** |
| no-graphics, before vs after on the 245 reached rows | 245 | — | — | — | **244 byte-identical, 1 moved (fixture)** |

Rows: from_gnash `actionscript.all` 243, `misc-ming.all` 63, `misc-mtasc.all` 9, `misc-swfc.all` 21, `misc-swfmill.all`
15; avm1 `button_goto goto_advance1 goto_advance2 goto_both_ways1 goto_both_ways2 goto_execution_order
goto_execution_order2 goto_frame goto_frame2 goto_frame_number goto_label goto_methods goto_rewind1 goto_rewind2
goto_rewind3 goto_rewind_movieclip_replace` (16); `regression` 287 (all, including the new one).
The 5 mismatches are all on `s28-baseline-trace-failing.txt` already (`actionscript.all/argstest-v6/-v7/-v8`,
`misc-ming.all/GradientFillTest`, `misc-swfc.all/matrix_accuracy_test1`), and none of them moves. Results are identical
between modes, row by row.

Upstream corpus: `download_tests.sh avm1 from_gnash` (and later avm2/from_shumway/fonts/text/visual for the canary) on
2026-11-26, Ruffle master `6f0ac73ffb9e` (via `git ls-remote` at that time). flash_fixes applied (14 + 5).

## Canary

`render_canary.py capture` before (clean origin/master) and after (patch), 195 tests / 260 PNGs, `-P 2`,
`--timeout 5400`: **IDENTICAL 260 / DIFFERS 0 / APPEARED 0 / VANISHED 0 / NO_RENDER 0; trace status changes none; image status changes none.**

## EXPECTED-FLIP LEDGER (CI check)

| test | axis | expected move |
|---|---|---|
| `regression/avm1_enterframe_root_goto_opcode` | trace | NEW row → **pass** (graphics and no-graphics). Before the patch it would be output_mismatch. |
| — | pixel | **none** (the fixture has no `[image_comparisons]`; canary md5-identical) |

Any other trace or pixel move on CI is NOT predicted by this patch. On this box all 244 rule-reached corpus rows are
byte-identical in both modes.

## Browser

The browser compiles the same `actionGotoFrame` arm (`dc6c75a64`), so it gets the fix too. I did not run a browser
harness in the cloud. **Completion mechanism:** the coordinator's local browser ladder (`tools/browser-test/child_probe/`)
can run this fixture's `test.swf`. Expected: the same 7 lines.

## Refutations / premise checks

- Brief premise "the Dejagnu checker retries every tick": **refuted as a description of the corpus.** The rule is
  reached once per run, and only by a same-frame goto. Whether it is dropped or executed makes no difference now, because
  of the catch-up self-goto guard.
- Brief premise "gnash Dejagnu rows depend on the rule": **refuted** (244/244 byte-identical in both modes without it).
- Brief option "goto to the CURRENT frame is a no-op": that is the right model, and it is **already implemented** in
  `ng_executeGotoCatchUp` (both copies). No new guard is needed in `actionGotoFrame`.

## Not finished

- Browser run of the fixture (above).
- Nothing else.

## New unclaimed leads

- `actionNextFrame` still has its own `g_inside_enterframe_dispatch` arm (stopped-root deferred-goto form, Tetris /
  masks_test). It is a different mechanism (the deferred advance would otherwise be dropped) and was not touched. If a
  future fixture shows Flash running `nextFrame()` from onEnterFrame inline (as this one does for GotoFrame), that arm is
  the next candidate. Its comment says running inline there lags the target script by ~2 ticks. This fixture shows the
  GotoFrame inline path does NOT lag (`f3 cf=3` comes right after the handler), so that comment may be stale too.
  Worth a FLASH fixture: `onEnterFrame = function(){ nextFrame(); trace(_currentframe); }` on a stopped root.

## LOCAL ORACLE REQUESTS

none (the FP32 golden for the fixture was already captured: `browser-attached-goto-fixtures/avm1_enterframe_root_goto_opcode/flash32.trace.txt`).
