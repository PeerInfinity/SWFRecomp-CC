# s28 wave-2 `w3-new-timer-rows`: report

**NEW files:** `SWFRecompDocs/plans/session28-fanout-reports/w3-new-timer-rows-report.md` (this),
`SWFRecompDocs/plans/session28-fanout-reports/w3-new-timer-rows.patch`. No new source files, no new fixture dirs,
no `verify_output.py` / harness change, no `render_canary_tests.txt` change.

## Verdict: GO, 4 priced flips (all 4 goldens Flash 32, byte-identical to upstream `output.txt`)

| row | origin/master (graphics, this box) | patched | owner |
|---|---|---|---|
| `avm1/timer_tie_order` | output_mismatch (from line 21: `setInterval 1` → `undefined`, then a runaway interval floods `undefined repeat NaN` to 615 lines) | **pass** | (1) `timer.c` `fireTimerCallback`: type-1 closure scope; (2) `timer.c` `processTimersImpl`: overdue-batch order after busy code |
| `avm2/timer_tie_order` | timeout (30 s) | **pass** | `avm2_display.c` `utils_get_timer`: a busy loop never ends; then seq order (as AVM1) |
| `avm2/timer_checks_per_frame` (upstream `known_failure = true`) | timeout (30 s) | **pass** | same busy loop; plus a timer check after the enterFrame broadcast |
| `avm2/timer_timeout_ids` | output_mismatch (`start` / `start again` / `start after reset`: `+2`, want `+1`) | **pass** | `avm2_display.c` `timer_list_add`: `flash.utils.Timer` used up a setTimeout id |

`timer_checks_per_frame` is `known_failure` upstream: Ruffle fails it, we now match Flash. That is a `pass`, not
`ruffle_matched` (it has no `output.ruffle.txt`, so nothing can move to `ruffle_matched`).

No harness change was needed. `tick_rate = 10.0` is Ruffle's runner tick length in ms (Ruffle `tests/framework/src/runner.rs`
`frame_time_millis = tick_rate`). Ruffle needs it to poll timers between frames. We emulate Flash's idle polling
inside the runtime, so `num_ticks` = frames is fine here: the row prints `Done` at frame 6 of 200.

## Root cause per row

### `avm1/timer_tie_order`: two separate owners

1. **Type-1 closures lost their scope in timer callbacks** (`timer.c` `fireTimerCallback`, function form). The Rascal
   compiler emits plain `DefineFunction` (type 1) for `intervalOnce` / `startInterval` / the `cleared` closure. The
   function-form arm passed `INV_CAPTURED_SCOPE` for type 2 only. Its own comment called this "a type-1 closure loses its
   defining chain here — a normalization candidate". So inside `setInterval(function(){ log(name); clearInterval(id); })`
   both `name` and `id` were `undefined`. The interval never cleared, and every later case drowned in
   `undefined repeat NaN`. Fix: type 1 also gets `INV_CAPTURED_SCOPE`, with captured `is_with` copied as-is. That is the
   flag set the LC / receiver type-1 arms already use (`action.c` ~4030). It fixes lines 21–49 (mixed kinds, intervals,
   cleared, recreated, created in callbacks).
2. **Overdue timers ran by due time, not creation order** (`timer.c` `processTimersImpl`). Two cases are affected:
   - "overdue together": `setTimeout(30)` then `setTimeout(10)`, then a 50 ms `getTimer()` busy loop.
   - "overdue intervals": the same with two `setInterval`s.

   Flash runs every overdue timer once, in creation order (FP32 prints `30ms` then `10ms`; Ruffle `72d054edd` made the
   same change). Our clock never saw the busy time: AVM1 `getTimer` is a wall clock, the timer clock is per frame. So the
   next update fired them earliest-due first.

### `avm2/timer_tie_order` and `avm2/timer_checks_per_frame`: a hang, not the harness

`flash.utils.getTimer` (`avm2_display.c` `utils_get_timer`) returned the frame-quantized timer clock. It never moves
inside a frame, so `while (getTimer() - start < 50) {}` (tie_order `overdueTogether` / `overdueIntervals`) and
`busyWait()` (checks_per_frame, 30 ms in each of 4 handlers per frame) spun until the 30 s timeout. Neither
`num_ticks` nor `tick_rate` was involved. Once the loop ends:
- tie_order needs the same once-each, creation-order rule for overdue timers. It also needs `seq` re-keying when a
  running `Timer`'s `delay` changes ("delay changed": `Timer B, Timer C, Timer A`). Restart and reset already worked,
  because `start()` makes a new entry.
- checks_per_frame needs Flash's check points. That is exactly one check between the enterFrame handlers and
  frameConstructed (`after enterFrame 1`), none between frameConstructed / exitFrame / render (`0`), and idle polling
  after render (`3 or more`).

### `avm2/timer_timeout_ids`

`Timer.start()` called `timer_list_add`, which pre-incremented the shared setTimeout/setInterval id counter. Flash
(and Ruffle `72d054edd` `add_timer_without_id`) gives `flash.utils.Timer` no id. Each `start` therefore cost one extra
id: `+2` instead of `+1`.

## The timer model after the patch (shared by both modes and the browser)

One model, implemented twice: AVM1 in `timer.c`, AVM2 in `avm2_display.c`, which already had separate clocks. Nothing
in `swf.c` / `swf_core.c` / `tag_stubs.c` changed, so the frame-loop pumps are untouched and the browser build runs the
same code.

- **Idle polling (unchanged):** in the tick-tail update, every timer due strictly before the frame's end fires,
  earliest due first, ties by creation order. A late interval catches up on its periods. Flash polls timers
  continuously while idle, and a 10 ms interval does fire ~10× per 100 ms frame (s27 w2b-timers-tail; Flash fired 70 due
  one-shots in one update, `regression/avm1_timer_overflow`). With no busy code the patch changes nothing. The idle
  loop's bound is now the frame's end as it stood on entry, not the moving clock.
- **Busy code (new):** a timer is only *overdue* together with another after code that blocked. Flash then runs
  every overdue timer **once, in creation order**, and reschedules a late interval from now (missed periods skipped).
  This is `timerRunOverduePass` / `timer_run_overdue_pass`.
  - AVM1 busy detection: `getTimer` stays a wall clock. `actionGetTime` (`action.c`, a 3-line hook) reports each
    value to `timerNoteGetTime`. Once a window (one timer check or one callback) has made 20 calls, the same threshold
    as Ruffle's AVM1 `time_offset` heuristic, the window's getTimer span becomes clock time. A normal frame makes
    fewer than 20 calls, so its timing is unchanged.
  - AVM1 check points: after a busy callback, and at the start of the next update after busy frame code.
  - AVM2 clock: past the first 20 `getTimer` calls in a tick, each call advances the AVM2 timer clock 1 ms. That makes
    the AVM2 clock deterministic: no wall clock, and both CI legs see the same values.
  - AVM2 check points: right after the enterFrame broadcast (new; a no-op without busy code, because everything due
    before the frame start already fired in the previous idle), at the start of the tick tail, and after a tail
    callback that moved the clock.
- **AVM2 `seq`:** every entry carries a never-reused sequence number. Ties and overdue batches use it, and
  `Timer.delay =` on a running Timer re-keys it. A Timer is found by `seq`; only setTimeout/setInterval entries carry
  an id (`timer_list_remove_id` ignores Timer entries).
- **AVM2 `MAX_TICKS = 10` cap dropped** (Ruffle dropped it too, in `72d054edd`; AVM1 had already dropped it in s27 from
  an FP32 capture). Its clock rewind would have broken the frame-end bookkeeping. `AVM2_TIMER_SANITY_TICKS` is a hang
  guard only.

Functions touched (sibling map: `w2-loaded-shell-land` lists `timer.c`; I did not touch
`g_in_process_timers` / `processTimers` itself):
- `timer.c`: `fireTimerCallback` (flag line only), `processTimersImpl` (restructured), new static
  `timerFireAndSettle` / `timerRunOverduePass` / `timerTakeBusyUs`, new extern `timerNoteGetTime`.
- `action.c`: `actionGetTime` only (+3 lines).
- `avm2_display.c` Timers section only: `Avm2TimerEntry` / `Avm2TimerObjExt` fields, `timer_list_add`,
  `timer_list_remove_id` / `_seq`, `timer_list_set_delay`, `timer_add`, `utils_clear_timer`, `utils_get_timer`,
  `timer_on_update`, `timer_ctor` / `start` / `stop` / `set_delay` / `get_running`, `timer_find_min`,
  `timer_find_by_seq`, `timer_fire_and_settle`, `timer_run_overdue_pass`, `run_due_timers`. In
  `avm2_display_run_tick`: one counter reset at the top, plus one `timer_run_overdue_pass` after the enterFrame
  broadcast.

## Before/after (same box, graphics mode; before = clean `origin/master` `5d0171816`, after = this patch)

Corpus: `download_tests.sh avm1 avm2 from_gnash from_shumway` (+ `fonts text visual` for the canary), upstream Ruffle
master at download time. The script prints no SHA. My blobless clone, taken minutes later, is at `6f0ac73ff` (2026-11-26,
"tests: Add avm2/timer_checks_per_frame test"), and it contains all 4 new rows.

| test | before | after |
|---|---|---|
| `avm1/timer_tie_order` | output_mismatch | **pass** |
| `avm2/timer_tie_order` | timeout | **pass** |
| `avm2/timer_checks_per_frame` | timeout | **pass** |
| `avm2/timer_timeout_ids` | output_mismatch | **pass** |

No-graphics, after only (I did not touch `swf_core.c` / `tag_stubs.c` / `NO_GRAPHICS` arms; this is a parity
sanity check): all 4 pass, and so does `avm2/timer_setdelay`. `avm1/timer_tie_order` passed 5 times out of 5 in a row,
because AVM1 busy detection reads the wall clock. The span is still deterministic: the loop exits exactly when
`getTimer() - start >= 50`, and `actionGetTime` already bumps 1 ms per call when the wall clock has not moved.

## Gate (graphics, before vs after, per row: trace status AND every image comparison's status/max_diff)

Scope, 337 rows:
- every avm1 / avm2 / from_gnash / from_shumway row whose name contains `timer`, `interval`, `timeout` or `settimeout`;
- all of `regression` (287 tests + the 2 non-test dirs `_lib` / `_results`);
- extra rows: every avm1/avm2 row whose `.as` source uses `getTimer` / `setInterval` / `setTimeout` / `new Timer`
  (`avm1/{edittext_ime_focus_lost, loadvariables2, movieclip_lockroot}`, 26 avm2 rows including `stage3d_fractal`,
  `stage3d_texture`, `stage3d_rotating_cube`, `key_input_*`, `url_loader`, `swf_9_goto_in_*`, `orphan_movie_*`).

| suite | before pass / ruffle_matched / fail | after |
|---|---|---|
| avm1 (8) | 7 / 0 / 1 | **8 / 0 / 0** |
| avm2 (34) | 29 / 2 / 3 | **32 / 2 / 0** |
| from_gnash (3) | 1 / 2 / 0 | 1 / 2 / 0 |
| from_shumway (3) | 3 / 0 / 0 | 3 / 0 / 0 |
| regression (289) | 287 / 0 / 2 (`_lib`, `_results`: not tests) | 287 / 0 / 2 (same) |

**The only moves are the 4 headline rows.** Every image comparison is identical before and after, including the
pre-existing image failures `avm2/stage3d_fractal`, `avm2/stage3d_texture`, `regression/avm2_layer_group_alpha` and
`regression/avm2_layer_group_erase`. Rows to note:
- `from_gnash/misc-swfc.all/gotoFrameFromInterval{,2}` stay `ruffle_matched`. Trace-provenance says the golden is Flash
  and the row is `rm`: unchanged, not mine.
- `regression/avm1_timer_clock_model` (analytic golden: catch-up, earliest-due-first idle) and
  `regression/avm1_timer_overflow` (FP32-backed) still pass. With no busy code the idle model is unchanged.
- `avm1/timer_run_actions`: upstream `72d054edd` raised its `num_ticks` 1→10. It passes in both legs.

## Render canary

`render_canary.py capture before` on clean master, then `capture after` with the patch, then `compare`.
**195 tests / 260 PNGs: IDENTICAL 260, DIFFERS 0, APPEARED / VANISHED / NO_RENDER 0, no trace or image status
changes.** The list's other members did not render on this box (suites not downloaded, or non-image rows). The change
class (timer clock / `getTimer`) has no canary member of its own, and none is needed: it changes no render path. The
risk would be a getTimer-driven animation, and the avm2 stage3d rows that use `getTimer` are in the gate above with
unchanged image status / max_diff.

## EXPECTED-FLIP LEDGER (check CI against this)

Trace axis, `fail → pass` (graphics; no-graphics the same):
- `avm1/timer_tie_order` (output_mismatch → pass)
- `avm2/timer_tie_order` (timeout → pass)
- `avm2/timer_checks_per_frame` (timeout → pass; upstream `known_failure = true`, so this is a Flash-ward win over
  Ruffle, not a `ruffle_matched` concern)
- `avm2/timer_timeout_ids` (output_mismatch → pass)

Pixel axis: **none expected.** None of the 4 rows has an image comparison, and the canary and gate image sets are
identical.

Anything else that moves on CI is unexpected. The places it could come from, and their mechanism:
- An AVM1 row that calls `getTimer` 20 or more times inside one timer callback or one frame while timers are live:
  the busy window now moves the timer clock.
- An AVM2 row that calls `getTimer` more than 20 times in a tick: the clock now advances 1 ms per extra call. Before,
  such a loop either hung or returned a frozen value.
- An AVM2 row with more than 10 due fires of one interval in a frame: the `MAX_TICKS` cap is gone.
- An AVM2 `Timer` whose handler sets `delay`.

None of these moved in the gate. `categories=full` is the right CI leg, because `avm2_display.c` is AVM2 runtime code.

## Dispositions / flash_fixes / RvF

- All 4 goldens are FP32 (coordinator captures byte-identical to `output.txt`), so there is no flash_fixes candidate.
- No RvF entry. Here the golden is Flash and we now match it. Ruffle's own miss (`timer_checks_per_frame` is
  `known_failure`: Ruffle only checks timers once per runner tick, after the whole frame) is upstream's documented gap,
  not a case where our output disagrees with a Ruffle golden.
- No ignore-list entries touched.

## Not finished / caveats (with completion mechanism)

- **AVM1 busy detection is a heuristic.** It uses the call count (20) and the wall-clock span of the window; AVM1
  `getTimer` stays a wall clock on purpose, because games in the browser time their animation with it. It only
  triggers on 20 or more `getTimer` calls in a window. If CI shows an unexpected AVM1 move with heavy `getTimer`
  use, the completion mechanism is a Flash capture of that row and a tighter threshold. Size: S.
- **AVM1 has no check right after enterFrame.** The AVM2 side has one, pinned by FP32 `timer_checks_per_frame`. For
  AVM1 the busy-overdue pass runs at the next `processTimers` instead. No AVM1 corpus row distinguishes the two. An
  AVM1 port of `timer_checks_per_frame` (MTASC, `onEnterFrame` busy wait) captured on FP32 would settle it. Size: S
  fixture + one FLASH capture (below), then about 20 lines in `swf.c` / `swf_core.c` (both pumps, so it is a
  mode-parity change).
- **Idle catch-up vs Ruffle `72d054edd`'s once-per-update rule.** Ruffle now runs each due timer once per update with
  no catch-up, because its update is a whole frame. We keep the per-due-time catch-up while idle, because Flash polls
  continuously while idle (FP32 `timer_checks_per_frame` shows "3 or more" runs of a 10 ms interval in one idle
  stretch). So Ruffle-golden rows where a sub-frame interval fires several times per frame could disagree with Ruffle
  goldens re-baked after `72d054edd`. None were re-baked upstream except `gotoFrameFromInterval`'s
  `output.ruffle.txt`, and that row's golden is Flash. Completion: an FP32 capture of `regression/avm1_timer_clock_model`
  (requested in s27 and still open) would turn its analytic F4–F7 catch-up counts into a Flash golden.

## New unclaimed leads

- `from_gnash/misc-swfc.all/gotoFrameFromInterval{,2}` remain `ruffle_matched` against a Flash golden (trace-provenance
  rows 291–292). They are unchanged by this patch; their owner is the goto-from-interval init ordering, not timer
  order.

## LOCAL ORACLE REQUESTS

- FLASH: `ruffle-tests/tests/swfs/regression/avm1_timer_clock_model` (built `test.swf` is in git), trace, 12 frames,
  direct. Compare F1 (`setInterval(fz, 0)`: 3 fires in the first update?) and F5–F7 (`cnt=16/18/18` catch-up) against
  the analytic `output.txt`. This settles idle catch-up (ours) vs once-per-update (Ruffle `72d054edd`) for AVM1.
