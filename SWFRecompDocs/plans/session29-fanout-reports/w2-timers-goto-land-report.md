# s29 w2-timers-goto-land: report (wave 2, implementation)

**NEW files:**
- `SWFRecompDocs/plans/session29-fanout-reports/w2-timers-goto-land-report.md` (this file)
- `SWFRecompDocs/plans/session29-fanout-reports/w2-timers-goto-land.patch` = `git diff --binary origin/master --
  SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <the 7 fixture dirs>
  ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` (binary: it carries the `test.swf`s and
  the clock-model deletions; the RvF doc is included so one `git apply` lands everything). Proven with
  `git apply --check -R` on this branch AND `git apply --check` on a clean `origin/master` worktree. Source files in
  it: `action.c`, `timer.c`, `swf.c`, `swf_core.c`, `tag.c` (no recompiler change, no new `.c`/`.h`).
- `ruffle-tests/tests/swfs/regression/avm1_goto_target_child_order_normal/` (`create_test_swf.py`, `avm1asm.py`, `test.swf`, `test.toml`, `output.txt`)
- `ruffle-tests/tests/swfs/regression/avm1_goto_target_child_order_gotoscript/` (same 5 files)
- `ruffle-tests/tests/swfs/regression/avm1_goto_target_child_order_interval/` (same 5 files)
- `ruffle-tests/tests/swfs/regression/avm1_enterframe_root_nextframe/` (same 5 files)
- `ruffle-tests/tests/swfs/regression/avm1_enterframe_sprite_nextframe/` (same 5 files)
- `ruffle-tests/tests/swfs/regression/avm1_timer_late_frame_check/` (same 5 files; = w1's `avm1_timer_after_enterframe`, renamed because its "after enterFrame" premise is refuted)

**Replaced:** `regression/avm1_timer_clock_model/` → the w1 bound-check form (`create_test_swf.py`, `test.swf`,
`output.txt`; `test.toml` unchanged). **Deleted:** its `golden_scenario.py` and `ruffle_timer_sim.py` (they derived the
old analytic golden, which FP32 refutes). Its `avm1asm.py` is unchanged.

**Edited docs:** `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`: the stale "Unbounded
Runaway" caveat ("our runtime ... times out") rewritten in place (brief item 1), and one new entry appended at EOF
("goto target frame runs its children in TAG order").

Every golden is the coordinator's FP32 capture `w1-local-oracles/w1-timers-goto/<fixture>.r1.txt` (byte-identical
copies; r1 == r2 (== r3) for every fixture with more than one run). Every `test.swf` regenerates byte-identically
from its `create_test_swf.py`.

Box: `SETUP_STATUS` all OK. Before leg = `origin/master` `3647bfc9` (code = `bfa47037b`). Corpus downloaded
2026-11-26/27: `avm1 from_gnash from_shumway timeline swf mixed_avm avm2 visual text fonts`; upstream Ruffle master
**`952362ecf`** (`git ls-remote`), flash_fixes applied.

## Verdicts and priced flips

| # | Item | Verdict | Flips |
|---|---|---|---|
| 3 | goto target frame: children's frame-1 scripts in TAG order | **LANDED** | **+2 trace: `from_gnash/misc-swfc.all/gotoFrameFromInterval` rm→pass, `gotoFrameFromInterval2` rm→pass**, graphics AND no-graphics. New rows `avm1_goto_target_child_order_{normal,gotoscript,interval}` pass. |
| 1 | `avm1_timer_clock_model` bound-check form + callback-time clock | **LANDED** | The replaced row passes (before: fails on `F3 ... n=undefined`). 0 corpus moves. |
| 4 | root onEnterFrame NextFrame/PrevFrame inline (w1 proto) + sprite NextFrame/PrevFrame opcode inline (new) | **LANDED** | New rows `avm1_enterframe_root_nextframe`, `avm1_enterframe_sprite_nextframe` pass. 0 corpus moves. |
| 2 | "timer check after enterFrame" prototype | **DROPPED** (FP32 refutes it) | — |
| 2' | `_currentframe` inside a late timer callback (`TA cf=4`, `TC cf=10`) | **LANDED: rule found, deterministic** | New row `avm1_timer_late_frame_check` passes. 0 corpus moves. |

## EXPECTED-FLIP LEDGER (the coordinator checks CI against this)

Trace axis, **both modes** (I touch `swf_core.c`), `categories=full`:

| row | before (s29 baseline) | after |
|---|---|---|
| `from_gnash/misc-swfc.all/gotoFrameFromInterval` | ruffle_matched (5/23) | **pass** (23/23) |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval2` | ruffle_matched (5/23) | **pass** (23/23) |
| `regression/avm1_timer_clock_model` | pass (old analytic golden) | **pass** (new FP32 bound-check golden) — row content replaced; on the old golden the code change alone would be pass→fail (`n f3`→`n f2`, FP32 behaviour) |
| `regression/avm1_goto_target_child_order_normal` | (new) | pass |
| `regression/avm1_goto_target_child_order_gotoscript` | (new) | pass |
| `regression/avm1_goto_target_child_order_interval` | (new) | pass |
| `regression/avm1_enterframe_root_nextframe` | (new) | pass |
| `regression/avm1_enterframe_sprite_nextframe` | (new) | pass |
| `regression/avm1_timer_late_frame_check` | (new) | pass |

**Every other trace row: no move, both modes.** Pixel axis: **no moves** (no render code touched; canary below). The
new regression rows have no `[image_comparisons]`, so they add no pixel rows.

## Per-test before/after (same box)

Before = clean `origin/master` sources (`git apply -R` of my runtime diff), after = this patch; same box, same
corpus download. `status matching/expected`.

| row | mode | before | after |
|---|---|---|---|
| `from_gnash/misc-swfc.all/gotoFrameFromInterval` | graphics | ruffle_matched 5/23 | **pass 23/23** |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval` | no-graphics | ruffle_matched 5/23 | **pass 23/23** |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval2` | graphics | ruffle_matched 5/23 | **pass 23/23** |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval2` | no-graphics | ruffle_matched 5/23 | **pass 23/23** |
| `regression/avm1_goto_target_child_order_normal` | both | pass 5/5 | pass 5/5 (control) |
| `regression/avm1_goto_target_child_order_gotoscript` | both | output_mismatch 3/6 | **pass 6/6** |
| `regression/avm1_goto_target_child_order_interval` | both | output_mismatch 4/7 | **pass 7/7** |
| `regression/avm1_enterframe_root_nextframe` | both | output_mismatch 9/22 | **pass 22/22** |
| `regression/avm1_enterframe_sprite_nextframe` | both | output_mismatch 6/16 | **pass 16/16** |
| `regression/avm1_timer_clock_model` (new FP32 golden) | both | output_mismatch 11/12 (`F3 ... n=undefined`) | **pass 12/12** |
| `regression/avm1_timer_late_frame_check` | both | output_mismatch 27/29 (`TA cf=3`, `TC cf=9`) | **pass 29/29** |

The before leg of the new rows is the expected "the fixture pins the change" failure (they are new rows, so CI has
no before for them).

## What changed (exact patch scope, every function named)

### Item 3: tag-order goto hook
- `swf.c` **and** `swf_core.c`: `ng_executeGotoCatchUp` only. The inline `funcs[target]` replay is wrapped to set (and
  restore) two globals, `g_goto_inline_tagorder` / `g_goto_inline_target`.
- `tag.c`: new `ng_goto_inline_place_hook` (+ the 2 globals, 1 forward declaration). While the inline replay runs,
  it runs the deferred sprite init of the child placed at that depth on the target frame
  (`process_sprite_init_at_depth`, same `placed_at_frame == target` filter as `ng_run_deferred_sprite_init_on_or_after`),
  so the child's frame-1 script lands in the SCRIPT FIFO between the frame's DoActions. Called from the
  `g_tag_skip_mode` early return of **`tagPlaceObject2`, `tagPlaceObject2WithClipActions`, `tagPlaceObject2Ratio`,
  `tagPlaceObject2RatioWithClipActions`** (w1 covered the first only; `tagPlaceObject3` delegates to `tagPlaceObject2`,
  w1's "PlaceObject3 skip arm `:15331`" is really `tagRemoveObject2`, which places nothing). Whatever the hook does not
  handle still goes through the unchanged `_on_or_after` call after the replay.
- w1's kill switch `SWF_GOTO_TAGORDER` and the `SWF_GOTO_TAGORDER_LOG` firing log are dropped.

### Item 1: callback-time clock
- `timer.c` `processTimersImpl`, idle loop: the clock is set to the firing timer's own due time for the duration of
  its callback (restored after), so a timer created inside a callback is due `delay` after the callback's time, not
  after the frame's end (FP32 3/3 `n=1` in F3). Loop bound and busy handling unchanged. Kill switch
  `SWF_TIMER_CB_CLOCK` dropped.

### Item 4: inline frame navigation inside onEnterFrame
- `action.c`: new statics `actionEfNavInlineCtx` (w1, kill switch `SWF_EF_NAV_INLINE` dropped) and
  `actionNavNonRootTarget` (new). `actionNextFrame` / `actionPrevFrame`:
  - **root** (w1 proto, FP32 r1 == r2 == proto): inside the root onEnterFrame (not an event-handler / broadcaster
    dispatch, root context, not inside a sprite) NextFrame / PrevFrame are `actionGotoFrame(cf ± 1)`, inline.
  - **sprite** (new; FP32 matched neither w1 leg): the NextFrame / PrevFrame **opcode** with a non-root
    `g_current_context` (SetTarget / tellTarget, or a base-clip context) outside that sprite's own tag execution
    (`!ng_isInsideSprite()`) is `ng_gotoFrameByMC(ctx, cf ± 1, stop)` on THAT clip — the same route
    `actionGotoFrame`'s `g_current_context` arm already takes. Before, it fell through to the ROOT's
    `next_frame`/`manual_next_frame`, so the sprite never moved (`after next cf=2`, `s f3` never ran). On frame 1
    (prev) / the last frame (next) it is a no-op, as Flash. The `this.nextFrame()` / `this.prevFrame()` CallMethod
    forms were already Flash-correct (FP32 `after mnext cf=2 / s f2`, `after mprev cf=2 / s f2`); the w1 sprite diff
    against FP32 was entirely the opcode arm (k=2) and its knock-on (k=3, k=4 started one frame low).
  - Static scan of every SWF in avm1 / from_gnash / from_shumway / regression / timeline / swf / mixed_avm
    (DoAction, DoInitAction, sprite bodies, PlaceObject2/3 clip actions, DefineButton2 actions): the NextFrame opcode
    appears only in `avm1/removed_clip_halts_script`, `misc-ming.all/ButtonEventsTest`, `misc-ming.all/masks_test`,
    `regression/avm1_loaded_bare_goto{,_seq}/child2.swf` (handled by `actionChildMovieBareGoto` first) and the 2 new
    fixtures; the PrevFrame opcode only in the 2 new fixtures. All gated below.
- I did not touch `ng_gotoFrameByMC`, its same-frame branch, or any browser gotoAndStop(current) guard (sibling
  browser ladder), nor any `action.c` builtin / tabIndex code (w2-disposition-land).

### Item 2': late-frame timer check (the rule)
**Rule (FP32 `avm1_timer_after_enterframe`, 3/3 identical):** when busy code (≥ 20 getTimer calls, our existing busy
detector) **overran the frame's end**, Flash has no idle time before the next frame, so the check for the timers it
made overdue runs **after the next playhead advance, before that tick's enterFrame and DoActions**: the callbacks read
the advanced `_root._currentframe` (`TA cf=4 last=F3` then `ef3 cf=4 / F4`; `TC cf=10 last=F9` then `ef9 cf=10`). A
busy stretch **inside** the frame period keeps its check in the same frame's idle time with the same `_currentframe`
(`TB`: busy 40 ms of 100 ms, `F6 / TB cf=6 last=F6` — already ours). This also explains the clock-model captures' `e f3`
before `F3`. The trace ORDER was already right on master for all three probes; only the frame the callback sees moved.

- `timer.c`: `processTimersImpl` — when its busy pass would run and the busy time pushed the clock past `frame_end`,
  it defers the pass (new static `g_timer_late_pass_pending`) and skips the idle loop for that update (with no idle
  time every due timer is overdue; firing them there would bypass the deferral). New extern `timerRunLatePass` runs
  the deferred pass: the same `timerRunOverduePass` (every timer due before the clock, once each, creation order,
  late intervals rescheduled from now) plus the same goto-init drains the in-tick pass ran. The set of timers fired
  is identical to before; only the point moves.
- `swf_core.c` `swfStart` main loop (before the "Frame-first" sprite advance) and `swf.c` `swfStart` main loop
  (before `actionSnapshotEnterFrameCandidates` / the sprite advance): one call to `timerRunLatePass`. At both points
  the root playhead advance has run (swf_core.c advances at the bottom of the previous tick, swf.c at the top of this
  one) and the sprite advance / enterFrame / DoActions have not. No-op unless a late pass is pending.
- Unpinned by the fixture (no FP32 evidence, so I kept the cheapest choice): whether the late check sees the SPRITES'
  advanced playheads (ours: no, it runs before the sprite advance), and a busy callback inside the idle loop that
  itself overruns the frame (unchanged: its overdue pass still runs in the same update).

### Dropped from w1
`timerCheckAfterEnterFrame`, `g_timer_ef_busy_us`, `g_timer_ef_depth`, the `SWF_TIMER_AFTER_EF` switch and the
`actionFireDeferredRootEnterFrame` call (item 2 prototype, refuted by FP32).

## Gates

1. **Corpus gate, 107 rows, both modes, after leg vs the CI s29 baseline JSON** (`_results/results_graphics.json` /
   `results.json` at `origin/master`, which is the before code `bfa47037b`). Rows: (a) a static scan of every root
   timeline that places a sprite through a PlaceObject2 variant with clip actions or a ratio AND has any goto
   (76 rows: the reach of the widened item-3 hook); (b) every avm1 / from_gnash / from_shumway / timeline / swf /
   mixed_avm row with `setInterval`/`setTimeout` in its (decompressed) SWF or timer/interval/timeout in its name,
   Dejagnu `actionscript.all` excluded (26 rows); (c) w1's 7 hook-fired rows (`RollOverOutTest`,
   `action_execution_order_test7`, `…test8-v5`, `…test8-v6`, `…test9`, `displaylist_depths_test9`, `loop_test9`) and
   the 3 NextFrame-opcode users (`removed_clip_halts_script`, `ButtonEventsTest`, `masks_test`); (d) every avm1 row
   named enterframe / gettimer / nextframe / prevframe. **Result, graphics: 107 rows, exactly 2 differ from baseline
   (`gotoFrameFromInterval{,2}` rm→pass). No-graphics: the same 2, nothing else.** Every other row equal in status
   AND matching-line count.
2. **`regression` suite, whole (299 rows), after leg: graphics 299/299 trace pass** (the 2 image FAILs,
   `avm2_layer_group_alpha` 2815 outliers / `avm2_layer_group_erase` 2702, are baseline pixel failures with identical
   counts in `s29-baseline-pixel-failing.txt`); **no-graphics 299/299 pass.** (The graphics run hit the 2 h background
   limit at row 262 and was resumed with `--start=261`; both halves are complete.)
3. **Render canary** (`render_canary.py capture before/after`, `--timeout 5400 -P 2`, the standing 195-row set):
   **260/260 PNGs IDENTICAL (md5), 0 DIFFERS / APPEARED / VANISHED / NO_RENDER, no trace or image status changes.**
   No render code is touched, so I added no canary member.
4. The 24-row timer gate the brief asks for is covered by (1)(b) + (1)(d) + the regression suite (every
   `regression/avm1_timer_*`, `timer_*`, `*enterframe*` fixture passes): w1's timer rows are a subset of mine.

## Refutations / premise attacks
- **Item 2's remaining diff is not "timer check after enterFrame" in a weaker form.** The FP32 order of TA/TB/TC is
  master's order; the difference is WHICH FRAME the callback runs in when the busy code overran the frame. TB (not late)
  and TA/TC (late) separate cleanly on that one bit, so the rule is deterministic, not wall-clock jitter.
- **Item 4 sprite**: the brief framed it as "Flash runs a sprite's nextFrame/prevFrame inline inside onEnterFrame".
  The method forms already did; the real gap was the opcode under SetTarget falling through to the ROOT playhead
  (the w1 "new unclaimed lead"). The fix is not onEnterFrame-specific: it is the opcode-target rule, matching what
  `actionGotoFrame` already did for a non-root `g_current_context`.
- w1's "PlaceObject3 skip arm" pointer is `tagRemoveObject2`; PlaceObject3 needs no arm of its own.

## Not finished / open (each with its completion mechanism)
- **Sprite-playhead visibility in the late timer check** and **a late busy callback inside the idle loop**: unpinned.
  Completion: a FLASH capture of a 2-variant fixture (late timer reads `_root.s._currentframe` of a playing sprite;
  an idle callback that busy-waits 150 ms and arms a 10 ms timeout). Not needed for any corpus row.
- Tetris preloader (the game the old stopped-root NextFrame arm was written for) is not runnable in the cloud; the
  root inline arm sits above that arm only inside the root onEnterFrame, and the browser-ladder probe remains its
  completion mechanism (unchanged from w1).

## New unclaimed leads
- The NextFrame / PrevFrame opcodes in a plain ROOT frame script still take the deferred fall-through (no inline
  `_currentframe`), unlike GotoFrame (w1 lead, still open; a 1-frame FLASH fixture settles it).

## LOCAL ORACLE REQUESTS
None required for this landing. Optional (completion of the open item above): FLASH trace, direct, 3 runs, of a
late-check variant fixture — not built here.
