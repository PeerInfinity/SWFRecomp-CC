# s26 w2-timer-semantics — AVM1 timer clock = Ruffle `core/src/timer.rs` model

**Slot:** `w2-timer-semantics` (wave 2, implementation). Branch `fanout/w2-timer-semantics`.
**Upstream corpus:** `download_tests.sh` at Ruffle master `3e98d9ba6`. Box: cloud, `SETUP_STATUS` all OK
(apt, Pillow, Dawn). Both modes run locally (graphics = Dawn/lavapipe).

## NEW FILES

- `SWFRecompDocs/plans/session26-fanout-reports/w2-timer-semantics-report.md` (this report)
- `SWFRecompDocs/plans/session26-fanout-reports/w2-timer-semantics.patch` (vs `origin/master`, includes robustness-land's `timerDelayToInt32` hunk verbatim)
- `SWFRecompDocs/plans/session26-fanout-reports/w2-timer-semantics-on-robustness.patch` (the same change as an increment on top of `w2-robustness-land`'s `timer.c`, see §0)
- `ruffle-tests/tests/swfs/regression/avm1_timer_clock_model/` — `test.swf`, `output.txt`, `test.toml`,
  `create_test_swf.py`, `avm1asm.py` (copy of the s26 assembler), `ruffle_timer_sim.py` + `golden_scenario.py`
  (the analytic golden generator)

Modified: `SWFModernRuntime/src/actionmodern/timer.c` (only file in the runtime), `ruffle-tests/tests/swfs/regression/README.md` (one row at EOF).

## VERDICT

**GO — land.** The AVM1 timer clock is replaced by a port of Ruffle's `Timers` (10 ms floor, `setInterval(f, 0)`
repeats, earliest-due-first, strict `tick < clock`, ≤ 10 fires per update with Ruffle's clock pull-back, timers created
in a callback wait for the next update). **Corpus yield: 0 graded flips** unless the coordinator lifts the CI exclude of
`from_gnash/misc-swfc.all/gotoFrameFromInterval`, which then adds **one `ruffle_matched` row** (it is
`runtime_error`/OOM on clean master). New fixture `regression/avm1_timer_clock_model` → PASS (new row).
Argued sweep: **42 rows × 2 modes, 0 off-ledger movers** (statuses AND actual-output bytes). Canary: the one
timer-using canary member md5-identical; every other member provably cannot move (§5).

## 0. Premise attack (read first)

1. **"landed: ToInt32 on the delay" — FALSE on `origin/master`.** `timerDelayToInt32` exists only on
   `origin/fanout/w2-robustness-land` (`9616002b0`); master's `timer.c` still stores the raw double, and clean master
   still OOMs on `gotoFrameFromInterval` (my BEFORE leg: RSS > 3 GB in seconds, killed by my watchdog, both modes).
   So `w2-timer-semantics.patch` **contains robustness-land's `timer.c` hunk verbatim** (same function, same call
   sites, one comment sentence updated). Landing order:
   - robustness-land NOT yet applied → apply `w2-timer-semantics.patch`; robustness-land's `timer.c` hunk then
     already applied (skip it / `git apply --exclude=SWFModernRuntime/src/actionmodern/timer.c`).
   - robustness-land already applied → apply `w2-timer-semantics-on-robustness.patch` with `patch -p1`
     (paths `a/SWFModernRuntime/...`), plus the fixture/README part of the main patch
     (`git apply --include='ruffle-tests/*' w2-timer-semantics.patch`).
2. **"The whole residual of `gotoFrameFromInterval` is timer semantics" — REFUTED.** With the int32 fix alone the
   case-2 line is `obtained: "x0xx1x"` (Flash: `x0xx1x234`): each interval fires once, correctly. The missing `234`
   is frame 8's three **DoInitAction blocks never running** when `_root.gotoAndPlay(9)` (issued from the timer
   callback on frame 7) jumps over frame 8. Those init actions are what call `clearInterval`, so under ANY repeating
   model the intervals then run forever. That is goto/init-action code (`action.c` `actionGotoFrame`, `tag.c`), not
   `timer.c`. Second, separate mechanism: a root goto issued from outside the frame loop is applied via
   `next_frame`/`manual_next_frame`, so `gotoAndPlay(9)` every update while already on 9 re-lands on 9 and the
   playhead **never advances to 10** (Ruffle: goto is immediate, next `run_frame` advances to 10 and the frame-10
   check prints each update — that is why `output.ruffle.txt` repeats the FAILED line). See Leads 1-2.
   Case 1's `FAILED: asOrder ... obtained "0+"` is a third, pre-existing init/placement-order issue (Ruffle shares it).
3. **"Flash over Ruffle" — no corpus row separates them on timers.** Every corpus row that fires a timer is consistent
   with Ruffle's model (Ruffle passes all of them except the known_failure above). The only Flash-only evidence is
   `gotoFrameFromInterval`'s `x0xx1x234`, which says (a) a 0.0001 ms interval created on frame 7 fires (once each, in
   creation order) before the next frame and (b) init actions queued by a goto inside a timer callback run after BOTH
   callbacks. (a) holds under the new model; (b) is the goto/init-action lead, not a clock property. I found no row
   where Flash and Ruffle's clock disagree, so the port is Ruffle's model with one deliberate deviation (tie order,
   §1).

## 1. The model (Ruffle source, line-for-line) and what the corpus pins

| Property | Ruffle source | New `timer.c` | Old `timer.c` | Corpus rows that encode it (Flash) |
|---|---|---|---|---|
| Delay coercion | `avm1/globals.rs create_timer`: `undefined` → return undefined; else `coerce_to_i32` | `timerDelayToInt32` (ECMA ToInt32); undefined still rejected | raw double, NaN→0 | `avm1/set_interval` (`setTimeout(tick, null)` fires; `setInterval(tick, undefined)` → undefined), shumway `avm1/setinterval` + `avm1/settimeout` ("non-numeric interval is treated as 0" → fires) |
| Minimum interval | `timer.rs add_timer`: `interval.max(MIN_INTERVAL=10) * 1000` µs | `timerIntervalUs` | none (0 → fire once, 1 ms → ~100 fires/frame at 10 fps) | none discriminating; `avm1/timer_run_actions` (`setInterval(fn, 1)`) consistent with both |
| 0 delay repeats | no special case: interval of 10 ms | repeats | fired once, then deactivated | none discriminating (every corpus 0-delay interval clears itself on its first fire) |
| Clock | `cur_time += (dt.as_millis()*1000) as u64` per `update_timers`; test runner: `run_frame()` then `update_timers(frame_time)` per tick (`tests/framework/src/runner.rs:238-241`) | `g_timer_cur_us += (u64)(frame_ms*1000)` per `processTimers` (already called right after the frame, same slot) | per-timer `elapsed_ms += frame_ms` | — |
| Due test | `while peek.tick_time < cur_time` (STRICT) | strict | `elapsed >= delay` | `avm1/set_interval` at 10 fps (all delays multiples of 100 ms → every boundary exact): passes under both because the shift is uniform |
| Order | `BinaryHeap` min-`tick_time` | min `(tick_us, id)` | lowest slot first, a timer's catch-up fires all before the next slot | `avm1/set_interval` (800 ms interval `TICK` before 800 ms timeout `G`: same tick, creation order) |
| Per-update cap | `MAX_TICKS = 10`; on the 11th: `cur_time = tick_time - 100`, break | same | 10 000 iterations | none |
| Created in callback | `tick = cur_time(already advanced) + interval` → next update | same | `elapsed 0 >= 0` fired a 0-delay one in the same pass | none |
| Removed-clip method timer | cancelled when due (`avm1_removed()`) | dropped at the top of each update (as before; keeps `hasActiveTimers()` exit honest) and re-checked at fire time | dropped each scan | — |
| Ties | heap-layout accident: two equal intervals alternate `1,2,2,1,1,2,...` (std `sift_down_range` keeps an equal child below) | creation (id) order — **deliberate deviation**; first fire identical to Ruffle | slot order | none observable |

## 2. Prototype = the patch

`SWFModernRuntime/src/actionmodern/timer.c` only: `TimerEntry` `delay_ms`/`elapsed_ms` → `tick_us`/`interval_us`;
new statics `g_timer_cur_us`, `timerIntervalUs`, `TIMER_MIN_INTERVAL_MS`, `TIMER_MAX_TICKS`; `timerDelayToInt32`
(robustness-land's, kept); `actionTimerSetInterval` (both arms: int32 delay, schedule against the clock);
`processTimers` rewritten (earliest-due loop, strict test, cap + pull-back, reschedule only the entry that fired —
`t->active && t->id == expected_id`, so a callback that clears its own timer or frees and reuses the slot is safe).
`fireTimerCallback`, `hasActiveTimers`, clear/GC paths unchanged. No `#ifdef`; all three call sites (`swf_core.c`,
`swf.c` native + browser pumps, `action.c` AVM1-under-AVM2) keep their per-tick call. No sibling file touched.

## 3. Per-test before/after (same box; BEFORE = clean `origin/master` `73915f552`)

Headline rows (graphics and no-graphics identical in every row):

| Test | BEFORE | AFTER |
|---|---|---|
| `regression/avm1_timer_clock_model` (NEW) | output_mismatch (actual = my `ours_old` simulation line-for-line: `z1` only, `a1 a2 a3 b e n`, `cnt=17/18/18`) | **PASS** |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval` (CI-excluded) | **runtime_error** (OOM runaway) | **ruffle_matched** (< 1 s; the int32-only leg is also ruffle_matched, `x0xx1x`) |

## 4. ARGUED TIMER SWEEP (both modes)

Scope: decompressed every `.swf` under `avm1/ from_gnash/ from_shumway/ regression/` and grepped for
`setInterval|setTimeout|clearInterval|clearTimeout` → 268 SWFs. 248 of them are gnash `actionscript.all` rows whose
only timer is the shared Dejagnu harness poll `_dejagnu_checker_interval = setInterval(checker, 200)` at 12 fps
(argument: at 83.333 ms frames a 200 ms interval fires on updates 3, 5, 8, … under both models — 249 999 µs > 200 000,
416 665 > 400 000 …; the only difference is the strict-vs-`>=` boundary, which needs an exact multiple, impossible at
12 fps over the test lengths here). Sampled 16 of them; ran **every** other timer row.

All 34 + 8 rows: status AND (for the 6 `ruffle_matched` rows) `--save-actual` output **byte-identical** BEFORE vs AFTER,
except the two headline rows. `output_mismatch` rows' diffs identical.

| Suite | Rows (status, both legs, both modes unless noted) |
|---|---|
| avm1 | `edittext_ime_focus_lost`, `loadmovie_replace_root`, `loadmovie_var_persistence`, `loadvariables2`, `movieclip_invalid_get_bounds_6`, `movieclip_invalid_get_bounds_7`, `movieclip_lockroot`, `netstream_play_flv_screen` (+image pass), `set_interval`, `string_paths_eval2`, `string_paths_timer`, `timer_run_actions`, `timeout` — all PASS→PASS |
| from_gnash actionscript.all | `Global-v5/v7/v8` PASS→PASS; `Global-v6`, `Inheritance-v6`, `Inheritance-v8` ruffle_matched→ruffle_matched (bytes identical); `argstest-v6` output_mismatch→same (baseline-failing, not timer); graphics-only extra sample vs CI baseline `9277f3799`: `Function-v7`, `NetStream-v6`, `Selection-v5`, `Video-v8` PASS, `Date-v8`, `LoadVars-v6`, `MovieClip-v6`, `XML-v7` ruffle_matched (= baseline status) |
| from_gnash misc-ming | `action_order/PlaceAndRemove` output_mismatch→same (baseline-failing: registerClass "should never be constructed", not timer), `gotoFrame2Test` PASS→PASS |
| from_gnash misc-swfc | `gotoFrameFromInterval` runtime_error→**ruffle_matched**; `gotoFrameFromInterval2` ruffle_matched→same (bytes identical) |
| from_shumway | `ZeroClipboardTest`, `avm1/loadvariables/loadvariables`, `avm1/lookup`, `avm1/setinterval`, `avm1/settimeout`, `timeline/Timeline9` — PASS→PASS |
| regression | `avm1_timer_function_form_activation`, `timer_cross_swf_version`, `timer_type1_args` PASS→PASS; `avm1_timer_clock_model` new→PASS |

## 5. Canary

`render_canary.py capture/compare` on `avm1/netstream_play_flv_screen` — the ONLY member of
`render_canary_tests.txt` (282 entries) whose SWFs (incl. loaded children) reference a timer builtin: **IDENTICAL**
(md5 `b568619e…`, trace pass, image pass). Every other member never creates a timer, and with no active timer the new
`processTimers` only increments `g_timer_cur_us` (and a timer's due time is relative to the clock at creation), so
those members cannot move. Not run on all 282 for that reason. No canary member appended: the trace-axis fixture
covers the change class and no render depends on timer cadence except via trace-visible state.

## 6. EXPECTED-FLIP LEDGER (coordinator: check CI against this)

**Trace axis (both modes):**
- `regression/avm1_timer_clock_model`: NEW row → **pass**.
- `from_gnash/misc-swfc.all/gotoFrameFromInterval`: only if `.github/workflows/ruffle-tests.yml` (~line 880) drops
  `--exclude=gotoFrameFromInterval` → NEW row **ruffle_matched** (the exclude's comment — "hangs to the 30 s per-test
  timeout" — is stale once either this patch or robustness-land is in; it finishes in < 1 s). **Recommendation: lift
  it** in the same commit that lands this patch. It grades `ruffle_matched` (`known_failure = true`; the
  `pass → ruffle_matched` regression rule cannot trigger, it has never passed).
- Everything else: **no movement.**

**Pixel axis:** **no movement** (one timer-using canary member md5-identical; no other image row can see the clock).

## 7. Not finished / HOLDs (each with completion mechanism)

- **Ruffle test-runner confirmation of the fixture golden** — the golden is **analytic, Ruffle-source-derived**
  (`golden_scenario.py` simulates `timer.rs` including std `BinaryHeap` sift order; the BEFORE output matched my
  simulation of the OLD model line-for-line, which validates the simulator and the hand-assembled SWF). Completion:
  LOCAL ORACLE REQUEST 1. If the runner disagrees, the coordinator should HOLD the fixture (not the runtime change) and
  send me/a worker the runner trace.
- `gotoFrameFromInterval` → pass needs Leads 1+2 (goto/init-action), not timers.

## New unclaimed leads

1. **Init actions of goto-skipped frames from a timer callback** (`action.c` `actionGotoFrame` root path /
   `ng_executeGotoCatchUp`, `tag.c`): `_root.gotoAndPlay(9)` from a timer on frame 7 never runs frame 8's three
   DoInitAction blocks. Flash runs them, after the timer pass (`x0xx1x234`: both callbacks, then `2,3,4`). Owner of
   the whole residual of `gotoFrameFromInterval` case 2 (and of its endless intervals). M; shared file (n-pixel-pass).
   Price: 1 trace row (CI-excluded today) → pass only with Lead 2 and case 1's ordering also fixed — realistically a
   game-robustness fix, not a flip.
2. **Root goto from outside the frame loop is deferred, not immediate** (`actionGotoFrame` root arm sets
   `next_frame/manual_next_frame`): a timer that does `gotoAndPlay(N)` every update while on N pins the playhead on N
   forever (Ruffle: immediate goto, next frame advances). Game-visible for any "setInterval → gotoAndPlay(current)"
   loop. S-M, needs its own sweep (goto ordering is test-dense).
3. Method-form detection: Ruffle takes the method form for ANY non-function object `args[0]` (`create_timer`), ours
   needs `num_args >= 3`; and `clearInterval` coerces with `(int)double` vs Ruffle `coerce_to_i32`. No corpus row
   reaches either (shumway `setinterval` "object argument 0 and non-string argument 1" returns undefined under both).
   XS.

## LOCAL ORACLE REQUESTS

1. **Ruffle test runner (the coordinator's timer-firing binary)** on
   `ruffle-tests/tests/swfs/regression/avm1_timer_clock_model/test.swf`, 12 ticks, `run_frame()` +
   `update_timers(frame_time)` per tick (the default runner path; `num_frames = 12` in `test.toml`). Compare its trace
   to `output.txt` (19 lines, `F1 … F9 end`). Expected identical; archive the trace next to the other s26 oracles.
2. (Optional, informational) the same runner on `from_gnash/misc-swfc.all/gotoFrameFromInterval` to confirm the
   committed `output.ruffle.txt` is still current Ruffle (it grades our row).
