# s29 w1-timers-goto: report (wave 1, diagnosis + measured prototypes)

**NEW files (all under `session29-fanout-reports/`):**
- `w1-timers-goto-report.md` (this file)
- `w1-timers-goto-prototype.patch` (`git diff origin/master -- SWFModernRuntime SWFRecomp`; sources reverted). It holds
  all 3 prototypes, and each has its own runtime kill switch (below).
- `w1-timers-goto-prototype-goto-only.patch`: item 3 alone (the tag-order goto hook).
- `w1-timers-goto-fixtures/`: `avm1asm.py` (shared, a copy of `regression/avm1_timer_clock_model/avm1asm.py`) and
  5 fixture dirs, each with `create_test_swf.py`, a built SWF, `test.toml` and `output.ours-before*.txt` /
  `output.ours-proto*.txt`:
  `avm1_timer_clock_model/` (bound-check rewrite, with a proposed `output.txt`), `avm1_timer_after_enterframe/`,
  `avm1_goto_target_child_order/` (3 SWFs: `test_normal.swf`, `test_gotoscript.swf`, `test_interval.swf`),
  `avm1_enterframe_root_nextframe/`, `avm1_enterframe_sprite_nextframe/`.
  Only the clock-model fixture has an `output.txt`. The others wait for Flash goldens.

Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn). The before leg is `origin/master` `aa36d43a` (code = `bfa47037b`).
Corpus is `download_tests.sh avm1 from_gnash`. Upstream Ruffle master was **`b7ff32d93`** (`git ls-remote`, and the
blobless clone at `/root/ruffle`), with flash_fixes applied (26). All runs are graphics unless marked NG.

## Verdicts and priced flips

| # | Item | Verdict | Flips (measured on this box) |
|---|---|---|---|
| 3 | gnash `gotoFrameFromInterval{,2}`: goto target frame runs children's frame-1 scripts in TAG order | **GO** (S, prototype measured; FLASH golden already on master) | **+2: `from_gnash/misc-swfc.all/gotoFrameFromInterval` rm→pass, `gotoFrameFromInterval2` rm→pass**, graphics AND no-graphics. 0 losses in a 150-row gate. |
| 1 | `regression/avm1_timer_clock_model` | **GO: replace it with the bound-check form** (fixture + proposed golden in this report) **plus a small refit** (callback-time clock) | Replacing the fixture is neutral. The refit's only corpus move is the OLD analytic row (pass→fail, `n f3`→`n f2`, which is the FP32 3/3 behaviour), and that row is the one being replaced. |
| 2 | AVM1 timer check after enterFrame | **HOLD on FLASH** (fixture + prototype ready) | 0 corpus moves in a 24-row timer gate. The fixture moves `TB`/`TC` from after the frame's DoAction to right after the handler. |
| 4 | `actionNextFrame` / `actionPrevFrame` inside root onEnterFrame | **Arm is stale (partly): HOLD on FLASH.** Prototype ready, 0 corpus moves | No corpus row reaches the arm (static scan: only 3 corpus SWFs use the NextFrame opcode at all, none inside onEnterFrame). The fixture shows 2 real gaps. |

Kill switches in the prototype (default ON; `=0` gives the exact before leg):
`SWF_GOTO_TAGORDER` (item 3), `SWF_TIMER_CB_CLOCK` (item 1 refit), `SWF_TIMER_AFTER_EF` (item 2), `SWF_EF_NAV_INLINE` (item 4).
`SWF_GOTO_TAGORDER_LOG=<file>` logs every firing of the item-3 hook (the gate tool; wave 2 can drop it).

Functions touched by the prototype:
- `tag.c`: `tagPlaceObject2` (its `g_tag_skip_mode` early return now calls the hook first); new extern
  `ng_goto_inline_place_hook` plus 2 globals `g_goto_inline_tagorder` / `g_goto_inline_target`; one forward declaration.
- `swf.c` and `swf_core.c`: `ng_executeGotoCatchUp` only. The inline `funcs[target]` call is wrapped to set and restore
  the 2 globals.
- `timer.c`: `processTimersImpl` (it opens the callback's clock in the idle loop, and its busy sum now includes
  `g_timer_ef_busy_us`); new statics `timerCbClockOn` and `g_timer_ef_busy_us` / `g_timer_ef_depth`; new extern
  `timerCheckAfterEnterFrame`.
- `action.c`: `actionFireDeferredRootEnterFrame` (+2 lines: it calls `timerCheckAfterEnterFrame`), `actionNextFrame`
  (new inline arm ahead of the stopped-root deferred arm), `actionPrevFrame` (the same arm); new statics
  `actionEfNavInline` / `actionEfNavInlineCtx`.
- I did not touch `ng_gotoFrameByMC`, the same-frame branch, or the browser gotoAndStop(current) guard (those belong to
  the sibling browser ladder).

---

## Item 3: `gotoFrameFromInterval{,2}`: GO, +2

**The missing line.** Both rows differ from FLASH `output.txt` in one check only:
`PASSED: asOrder == 0+1+2+3+4+1+2+3+4+1+2+3+4+` (sc:67 / sc:74). We print
`FAILED: asOrder: expected "0+1+2+3+4+…", obtained "0+"`, and we print it *before* the 15 `_level0.clipN --> k`
lines instead of after them. In gotoFrameFromInterval, the rest of our output, including part 2's `x0xx1x234`, already
equals Flash. Our output is byte-identical to `output.ruffle.txt` for `…Interval2`. For `…Interval` it matches the
first line of Ruffle's file, but upstream's new file has the runaway tail (see `RUFFLE_VS_FLASH_DIFFERENCES.md`
"Unbounded Runaway"). That entry's line "our runtime ... times out" is **stale**: we terminate cleanly now.

**Mechanism.** I decompiled the scripts from our recompiled output; no `.sc` is shipped, and savannah returned
502/timeouts. Root frame 2 runs `stop(); intervalID = setInterval(fn, 0.0001)`. `fn` does `gotoAndPlay(6)` while
`_currentframe == 2`. Frame 6 is
`DoAction A { function init_me(obj){… asOrder += "1+".."4+"}; stop(); clearInterval(intervalID) }`, then
`PlaceObject2 clip1..clip3` (a sprite whose frame 1 calls `this._parent.init_me(this)`), then
`DoAction B { check_equals(asOrder, "0+1+2+3+4+…") }`. Flash runs A, clip1, clip2, clip3, B: **tag order, the same
as a natural advance.** Ours ran A, B, clip1..3. Ruffle does the same, and that is why the row is
`known_failure = true` upstream: Ruffle `movie_clip.rs` `run_goto` "Finally, run frames for children that are placed
on this frame".

Owner: `swf.c:427-431` / `swf_core.c:395-398` (`ng_executeGotoCatchUp`). It calls `ng_run_deferred_sprite_init_on_or_after(target)`
*after* the inline `funcs[target]` replay, so the init of every child placed on the target frame queues behind all of
the target frame's DoActions. During that replay, `tagPlaceObject2` (`tag.c:12798`) returns early under `g_tag_skip_mode`.

**Probe** (`w1-timers-goto-fixtures/avm1_goto_target_child_order`: DoAction A / place c1, c2 / DoAction B):

| variant | before | prototype |
|---|---|---|
| `normal` (natural advance) | A, child c1, child c2, B | same |
| `gotoscript` (GotoFrame from F1's DoAction) | A, B, child c1, child c2 | **A, child c1, child c2, B** |
| `interval` (gotoAndPlay from setInterval) | A, B, child c1, child c2 | **A, child c1, child c2, B** |

So our natural advance already runs tag order; only the goto path disagreed.

**Prototype.** While the inline target replay runs, `tagPlaceObject2`'s skip arm calls `ng_goto_inline_place_hook(depth)`.
That runs the deferred init (same filter: `placed_at_frame == target`) for that one depth, so the child's frame-1
script lands in the SCRIPT FIFO between A and B. Whatever the hook does not handle still goes through the unchanged
`_on_or_after` call afterwards.

**Gate.**
- Static scan: 150 avm1 / from_gnash / regression rows whose root timeline places a sprite that has frame-1 actions or
  clip actions.
- After leg: all 150 rows with the firing log on. The hook fired in only 7 rows besides the 2 headline rows:
  `misc-ming.all/RollOverOutTest`, `action_order/action_execution_order_test7`, `…test8-v5`, `…test8-v6`, `…test9`,
  `displaylist_depths/displaylist_depths_test9`, `loop/loop_test9`.
- Before leg (`SWF_GOTO_TAGORDER=0`) on those 9 rows, both modes: the 7 are **byte-identical and pass** in graphics AND
  no-graphics. The 2 headline rows move to **pass** in both modes.
- In the other 141 rows the hook never ran a sprite init, so they cannot move.

**Wave-2 scope (S).** Keep the hook, but also call it from the three sibling skip arms:
`tagPlaceObject2WithClipActions` (`tag.c:13779`), `tagPlaceObject2Ratio` (`:13805`) and
`tagPlaceObject2RatioWithClipActions` (`:14340`). Also check the PlaceObject3 skip arm (`:15331`). The prototype
covers plain `tagPlaceObject2` only, which is what both gnash rows use. Then re-run the 7 fired rows plus the headline
rows in both modes, run the canary (not run here: trace-only change, no render path), and drop the log line. The
FLASH request below (`avm1_goto_target_child_order` `gotoscript`) confirms the frame-script goto case. The gnash
golden only pins the interval case, and the prototype changes both.

**RvF candidate** (coordinator to append): `gotoFrameFromInterval{,2}`: Ruffle runs the goto target frame's DoActions
before the children placed on that frame; Flash runs them in tag order (FLASH `output.txt`, upstream `known_failure`).
The existing "Unbounded Runaway" entry needs its "we time out" caveat removed.

## Item 1: `avm1_timer_clock_model`: bound-check form, plus one refit

**The 3 FP32 captures** (`session28-fanout-reports/w1-local-oracles/new-timer-rows/regression__avm1_timer_clock_model/`)
**vs the analytic golden:**
- **F1:** `z1..z3 f1` in all 3 runs. We match.
- **F2:** in all 3 runs `b`, `a1`, `n`, `a2` fire before `F3`; `a3` and `e` land on either side (jitter); `a4` lands
  between F3 and F4. Our golden has **`n f3` (after F3); Flash has `n f2` 3/3.**
- **F5–F7:** 10 or 12 fires per frame in every run, vs our 16/18/18.
- My refutation of the brief's framing: the count difference is not "Flash catches up less" alone. 10/12 is even in
  every run, with equal fire counts for a 10 ms and a 13 ms interval. That is the signature of a coarse idle poll
  (about 16–20 ms) in which each due timer fires once. A deterministic refit would have to choose one poll period
  (16.7 ms gives 12, 20 ms gives 10) and would still be wrong on half of the runs. So the counts become a range check.

**Bound-check fixture** (`w1-timers-goto-fixtures/avm1_timer_clock_model/`). It has the same scenario and timings, but
the callbacks set flags instead of tracing (the F1 traces stay). The proposed `output.txt` has 12 lines:
```
F1 / z1 f1 / z2 f1 / z3 f1 / F2 / F3 b=1 n=1 a2=true / F4 a=4 e=1 /
F5 lo=true hi=true / F6 … / F7 … / F8 cnt=0 / F9 end
```
`lo`/`hi` means 5 < cnt < 21. FP32 (10/12) and our 1 ms catch-up (16/18) pass that range. A once-per-update model
(cnt=2, Ruffle `72d054edd`) or a runaway fails it. I checked every line by hand against all 3 captures: all hold.

**Ours:** before = 11/12 lines. The one diff is `F3 … n=undefined` (the real Flash gap). Prototype = **12/12** (pass).

**Refit (the `n` gap).** Owner: `timer.c` `processTimersImpl`, idle loop (`:762`).
- The idle loop pins the clock to the frame's end before firing, so a timer created inside a callback is due 10 ms
  after the *frame's end* and can never fire in that update. Its own comment says so; that rule was Ruffle's
  whole-frame update.
- Flash polls continuously, so the callback runs at about its own due time.
- Prototype: the clock is set to the firing timer's `tick_us` for the duration of the callback (and restored after),
  so `setTimeout(fn, 0)` inside b@20 ms is due at 30 ms and fires in frame 2.
- The loop bound (the frame's end) and the busy handling are unchanged.

**Timer gate** (24 rows, A/B through `SWF_TIMER_CB_CLOCK=0 SWF_TIMER_AFTER_EF=0`; the item-3 hook was on in both legs):
- Rows: every avm1 / from_gnash / regression row with timer/interval/timeout in its name or setInterval/setTimeout in
  its source. The Dejagnu `actionscript.all` rows are excluded: they match only on the harness string.
- Also included: the enterframe/getTimer avm1 rows, `getTimer_test`, and the s28 enterframe-goto regression fixtures.
- **Only move: `regression/avm1_timer_clock_model` (old analytic form) pass→fail**, with exactly `n f3`→`n f2`. Every
  other row is unchanged. `avm1/timeout` and `avm1/string_paths_timer` produced no saved output in my harness, but
  pass under the prototype in a direct run.
- So wave 2 must land the refit **together with** the fixture replacement. Otherwise the old row regresses.

## Item 2: AVM1 timer check after enterFrame: HOLD on FLASH

**Fixture** `avm1_timer_after_enterframe` (SWF 8, 10 fps, 12 frames, the root plays).
- Every DoAction traces `F<n>`; `_root.onEnterFrame` traces `ef<k> cf=`.
- Each of 3 probes does `setTimeout(T?, 10)` followed by a getTimer busy-wait in the same handler:
  - A: frame-3 DoAction, busy 150 ms (longer than the frame);
  - B: onEnterFrame call 5, busy 40 ms;
  - C: onEnterFrame call 8, busy 150 ms.
- Each timer prints `T? cf=<cf> last=<last marker>`. Its position is fixed by the player's structure, not by
  wall-clock luck, because Flash never fires a timer re-entrantly.
- Ours (before): `ef5 cf=6 / TB armed / F6 / TB cf=6 last=F6`, i.e. after the frame's DoAction, at the tick-tail
  check. TC is the same. TA fires at once after F3 (`TA cf=3 last=F3`).

**Prediction (FP32).** TB/TC print right after their handler, before `F6`/`F9`. Evidence:
- AVM2 FP32 `timer_checks_per_frame` has exactly this check point (`8be319e93`).
- The clock-model captures print `e f3` *before* `F3` in 3/3 runs: a check after the advance and before the frame's
  DoAction.
- TA is open: it shows whether the overdue frame or the timer goes first.

**Prototype.**
- `timerCheckAfterEnterFrame` (`timer.c`) is called from `actionFireDeferredRootEnterFrame` after the root
  `onEnterFrame` fires. That point is right before the root DoAction pops.
- It is busy-only: a no-op unless the handler made 20 or more getTimer calls. So idle timing, and every Ruffle-golden
  tie at a frame boundary, is unchanged.
- The busy time is credited to the clock only for this pass, then handed to `processTimersImpl` through
  `g_timer_ef_busy_us`, so the frame's end bookkeeping is unchanged.
- Fixture with the prototype: `TB cf=6 last=ef5 cf=6` before `F6`, and the same for TC. Corpus: 0 moves (timer gate above).
- Not covered: child-clip onEnterFrame handlers (`tagFlushPendingEnterFrame` → `actionDispatchEnterFrameHandlers`,
  `tag.c:7608`). If Flash confirms the root case, wave 2 adds the same call after that dispatch; it is one line.
- Wave 2: if the Flash golden matches the prediction, land the prototype and promote the fixture to `regression/`
  with its golden. If TA shows the timer firing *after* the next advance (`TA cf=4 last=ef3`), the tick-start overdue
  pass in `processTimersImpl` also has to move after the next enterFrame. If the golden shows TB after `F6`, NO-GO
  and drop the prototype.

## Item 4: `actionNextFrame` / `actionPrevFrame` inside onEnterFrame

**Premise check.** The NextFrame arm (`action.c:39723`) is **not** the same kind of rule as the deleted GotoFrame one.
It never dropped the goto. It is the "deferred-goto form": it sets `goto_from_action` + `manual_next_frame` +
`currentframe` and lets the main loop's catch-up run the target frame this tick. On a stopped root it gives the
Flash-shaped output today. Fixture `avm1_enterframe_root_nextframe` shows `after next cf=2 / f2 cf=2` and
`after mnext cf=3 / f3 cf=3` (the method form goes through the CallMethod arm and is also fine).

**The stale parts, measured.**
1. **The PrevFrame opcode has no arm at all** (`actionPrevFrame`, `action.c:37994`). Inside the root onEnterFrame we
   print `after prev cf=3` (stale), the next tick shows `cf=2`, and **frame 2's DoAction never runs**. Predicted
   Flash: `after prev cf=2 / f2 cf=2`.
2. **The NextFrame opcode on a PLAYING root** falls through to the plain deferred form. We print `after pnext cf=3`,
   and the root keeps playing (`ef9 cf=5 / f5`). Predicted Flash: inline (`cf=4`), and nextFrame stops the root
   (`ef8 cf=4 / ef9 cf=4`).
3. Sprite variant (`avm1_enterframe_sprite_nextframe`): `this.nextFrame()` / `this.prevFrame()` are inline and correct.
   **The NextFrame opcode under `SetTarget("/s")` (what tellTarget compiles to) inside the sprite's onEnterFrame is
   dropped entirely**: `after next cf=2`, the sprite never reaches frame 3, and `s f3` never prints. This is a
   separate path (the SetTarget / in-sprite arms, not the enterframe arm), so the prototype does not touch it.
   It is a new lead (below).

**Prototype.**
- Inside the root onEnterFrame (`g_inside_enterframe_dispatch`, root context, not inside a sprite, not an
  event-handler or broadcaster dispatch), NextFrame / PrevFrame call `actionGotoFrame(cf±1)`, the s28 inline path.
- The stopped-root deferred arm stays below it and still serves the broadcaster case (`masks_test`).
- Fixture with the prototype: `after prev cf=2 / f2 cf=2`; playing root `after pnext cf=4 / f3 cf=4 / f4 cf=4`, then
  stopped (`ef8 cf=4 / ef9 cf=4`).
- `f3 cf=4` is the DoAction already queued for this tick running after the goto. Whether Flash runs it at all is
  exactly what the FLASH capture must show, so this ordering is unverified.
- The comment's claim that "inline here lags ~2 ticks" did not reproduce in the fixture. It was written for the
  pre-s28 code.

**Gate.**
- Static scan of all 1486 avm1 / from_gnash / regression SWFs (DoAction / DoInitAction / sprite DoAction bodies):
  only `avm1/removed_clip_halts_script`, `misc-ming.all/ButtonEventsTest` and `misc-ming.all/masks_test` use the
  NextFrame opcode, and none from onEnterFrame.
- A/B (`SWF_EF_NAV_INLINE=0`) on those 3 plus 9 enterframe / goto regression rows (`avm1_enterframe_root_goto_opcode`,
  `avm1_timer_root_goto_stopped_nf`, `avm1_clipevent_root_goto_stopped`, `avm1_attach_from_stopped_root_enterframe`,
  `avm1_attach_clipevent_enterframe`, `avm1_enterframe_removed_same_tick_noprobe`, `avm1_goto_backward_enterframe_once`,
  `enterframe_type1_args`, `root_enterframe_cross_swf_version`): **12/12 byte-identical.**
- ButtonEventsTest and masks_test are not `pass` locally in either leg, so the move is unrelated to the patch.
- Tetris (the game the arm was written for) is not runnable in the cloud. **Completion:** the FLASH capture, plus the
  coordinator's browser-ladder Tetris preloader probe.

**Canary:** not run (about 1 h on 4 CPU). All 3 prototypes are trace/timing-only and touch no render path; wave 2
runs it.

## Refutations / premise attacks (summary)
- Item 1: "Flash gives cnt 10–12" is right, but the fixture also hid a deterministic FP32-vs-ours difference in F2
  (`n`, 3/3). The bound form keeps that line, so it now fails on master, and the refit fixes it.
- Item 3: the fix is not the timer or the interval. Any root goto (frame script too) orders the target's children
  after its DoActions; the interval only exposes it. Previous reports booked the owner as "goto-from-interval init
  ordering"; it is `ng_executeGotoCatchUp`'s `_on_or_after` call.
- Item 4: the NextFrame arm is not a dropped-goto rule. The stale behaviour is on the paths *without* an arm
  (PrevFrame opcode, playing root), plus an unrelated SetTarget drop.

## New unclaimed leads
- **SetTarget/tellTarget + NextFrame/PrevFrame opcode inside a sprite's onEnterFrame is dropped**
  (`avm1_enterframe_sprite_nextframe` k=2). The owner is likely `actionNextFrame`'s fall-through
  `next_frame/manual_next_frame` (root globals) under a non-root `g_current_context`. Size S once Flash confirms.
- **The NextFrame / PrevFrame opcodes in a plain root frame script** also take the deferred fall-through (no inline
  `_currentframe`), unlike GotoFrame. This is untested here; a 1-frame FLASH fixture would settle it.
- `RUFFLE_VS_FLASH_DIFFERENCES.md` "gotoFrameFromInterval … Unbounded Runaway": remove the stale "we time out" caveat.

## LOCAL ORACLE REQUESTS
All are direct mode (pinned), with built SWFs in the fixture dirs; `create_test_swf.py` regenerates them (stdlib only,
`python3 create_test_swf.py [variant] test.swf`).
1. FLASH: `w1-timers-goto-fixtures/avm1_timer_clock_model/test.swf`, trace, 12 frames, **3 runs**. Expect all 3 to equal
   the proposed `output.txt`. If any line fails in any run, wave 2 loosens that line (or drops it).
2. FLASH: `w1-timers-goto-fixtures/avm1_timer_after_enterframe/test.swf`, trace, 14 frames, **3 runs**. Compare the
   position of `TA` / `TB` / `TC` against `output.ours-before.txt` / `output.ours-proto.txt`.
3. FLASH: `w1-timers-goto-fixtures/avm1_goto_target_child_order/test_{normal,gotoscript,interval}.swf`, trace, 6 frames,
   1 run each. Expect tag order (A, child c1, child c2, B) in all 3, i.e. `output.ours-proto.*.txt` for
   gotoscript/interval.
4. FLASH: `w1-timers-goto-fixtures/avm1_enterframe_root_nextframe/test.swf`, trace, 12 frames, 2 runs.
5. FLASH: `w1-timers-goto-fixtures/avm1_enterframe_sprite_nextframe/test.swf`, trace, 12 frames, 2 runs.

That is 10 captures in total. Requests 3–5 are deterministic (1–2 runs each).
