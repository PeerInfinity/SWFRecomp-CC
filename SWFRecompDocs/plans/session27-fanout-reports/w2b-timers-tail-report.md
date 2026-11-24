# s27 w2b-timers-tail: Flash init flush at call return, no timer fire cap, 3 more growable queues

**Slot:** `w2b-timers-tail` (wave 2b, implementation). Branch `fanout/w2b-timers-tail`. Base `origin/master` `f35786c2`
(includes `cceb5133a` w2-timers-land). **Box:** cloud, `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe).
Corpus: `download_tests.sh from_gnash avm1` at 2026-11-24 ~06:00 UTC (script prints no SHA; 1188 tests). Ruffle source
read at upstream HEAD (blobless clone, `core/src/timer.rs`).

> **THIS PATCH TOUCHES SHARED RUNTIME CODE USED BY BOTH MODES** (`action.c` `invokeFunctionValue`, `tag.c`, `timer.c`);
> it touches no `swf_core.c` / `tag_stubs.c` / `#ifdef NO_GRAPHICS` arm and no recompiler code. Every headline row was
> nevertheless run in **BOTH modes** (graphics and no-graphics) with `--recompile`: graphics == no-graphics byte-for-byte on
> all 31 headline rows, before and after. `categories=all` is enough (no AVM2 change). A no-graphics CI leg is optional.

## NEW FILES

- `SWFRecompDocs/plans/session27-fanout-reports/w2b-timers-tail-report.md` (this report)
- `SWFRecompDocs/plans/session27-fanout-reports/w2b-timers-tail.patch` (`git diff --binary origin/master -- SWFRecomp
  SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt` + the fixture dirs below;
  `SWFRecomp/`, `verify_output.py` and `render_canary_tests.txt` are untouched)
- `ruffle-tests/tests/swfs/regression/avm1_goto_skipped_init_call/` — `test.swf`, `test.toml`, `output.txt`,
  `create_test_swf.py`, `avm1asm.py`. **Flash golden**: `w2-local-oracles/w2-timers-land/goto_skipped_init_call/
  flash.direct.txt` verbatim; `test.swf` is **byte-identical** to the SWF Flash ran (`cmp` vs the w2-timers-land probe output).
- `SWFRecompDocs/plans/session27-fanout-reports/w2b-timers-tail-fixtures/queue_overflow_probe.py` (+ `avm1asm.py` copy):
  Flash probe for the failed-load / unload queue growth (LOCAL ORACLE REQUEST 2; not a committed fixture).

Modified fixtures (in the patch): `regression/avm1_timer_overflow` (`create_test_swf.py`, `test.swf`, `output.txt`) and
`regression/avm1_timer_clock_model` (`create_test_swf.py` docstring, `output.txt` F5–F7).

## VERDICTS

| # | Item | Verdict | Flips (measured, both modes) |
|---|---|---|---|
| 1 | Init flush point = return of the next user-function call (Flash `f1 / g f3 / init2 f3 / init3 f3 / f1 after g / f3`) | **GO, landed.** | `regression/avm1_goto_skipped_init_call` (new) MISMATCH → **PASS**; `from_gnash/misc-swfc.all/action_execution_order_test12` line 19 now `PASSED: asOrder == 0+1+2+3+4+` — see §1.3: **status ruffle_matched → output_mismatch** under the harness's fp10 grading although our output now equals Flash's **fp9** golden byte-for-byte |
| 1a | Re-measure `gotoFrameFromInterval`, `movieclip_destruction_test1`, `InitActionTest2` | **Byte-identical** before/after (none issues a user call after a root goto outside a timer pass). | 0 |
| 2 | Ruffle `MAX_TICKS = 10` is not Flash | **GO, landed.** Flash's rule (from the one Flash capture we have): *every* timer due before the clock fires in the update — no total cap. Our synthetic clock then catches a repeating interval up (≈ Flash's real-time rate). Ruffle's own source calls the cap "for sanity". | `regression/avm1_timer_overflow` restored to the full w1 SWF + Flash trace: before (clean master, new fixture) MISMATCH (`n=10,20,…,60,70,70`) → **PASS** (`n=70` ×8). `regression/avm1_timer_clock_model` golden F5–F7 `cnt=10` → `16/18/18` (Ruffle-analytic → no-cap analytic; Flash capture requested). Every other timer row byte-identical. |
| 3 | `MAX_DEFERRED_FAILED_LOADS` 16, `MAX_PENDING_LV_LOADS` 32, `MAX_DEFERRED_UNLOADS` 32 → growable | **GO, landed** (same `ng_table_grow` pattern as w2-timers-land's MCL / direct queues). LoadVars drain snapshot is now a heap copy **and a GC root**. | 0 corpus rows (no row exceeds the old caps). Probe: the 17th+ failed `loadMovie` of a frame now gets the deferred failed state (`f16 tf=0 fl=-1`, was `tf=1 fl=1`) like the first 16. |
| 3a | Is `g_pending_load_inits` (MCL Phase-3 queue) a GC root? | **No — it was not; now it is.** Its `mcl` broadcaster was marked only while in the this-tick / next-tick queues; between promotion and `onLoadInit` a collected loader (e.g. a function-local `new MovieClipLoader()`) was a latent UAF. Marked + scrubbed now. | 0 (no corpus row drops its last MCL reference mid-load) |

## 1. Init flush at call return

### 1.1 Mechanism (owner)

- `tag.c` new `tagFlushGotoInitsAtCallReturn(app_context)`: if goto-queued init actions are pending, and we are **not**
  inside a root goto catch-up (`g_goto_init_capture > 0`), **not** inside a timer pass (`g_goto_init_timer_pass > 0`,
  `processTimers` keeps draining at its batch boundaries — gnash `gotoFrameFromInterval` `x0xx1x234` is Flash's order there)
  and not already draining, it drains them now (`tagDrainGotoInitActions(…, 1)`).
- `action.c` `invokeFunctionValue` (the unified invocation core; every user-function call from CallFunction / CallMethod /
  NewObject / event dispatch goes through it): at the end, **for user-defined callees only** (`func->swf_version != 0`:
  set by DefineFunction / DefineFunction2, natives are 0), it calls the hook. So `_root.gotoAndPlay(3)` itself (a native
  CallMethod) never flushes, and `g()`'s body runs before the inits — exactly Flash's `g f3 / init2 f3 / init3 f3`.
- `tag.c` `tagDrainGotoInitActions`: the force=1 path is now **non-re-entrant** (`g_goto_init_draining`): an init action's
  own function returns must not restart the drain loop (the outer loop already runs every queued entry in order, including
  any a nested goto appends). The force=0 path (AQ_PRIORITY_INITIALIZE entry after the issuing script) is unchanged: with
  no user call after the goto the inits still run after the script (`avm1_goto_skipped_init_script`, unchanged PASS).
  Body moved verbatim into `static tagDrainGotoInitActionsNow`.

### 1.2 Attack on the brief's premise

The brief said "flush on the first CallFunction/CallMethod return". Taken literally (any opcode return) that is refuted by
the same Flash trace: the goto itself is a CallMethod (`_root.gotoAndPlay`), and its return did NOT flush (else `init2`
would precede `g f3`). The rule implemented is "the return of a **user** function", the narrowest rule the capture supports.
Unmeasured corners (no Flash capture): a goto issued *inside* a function (flushes at that function's own return under this
rule), and a user call after a goto inside a timer callback (kept on the batch-boundary drain). Both are LOCAL ORACLE
REQUEST 3.

### 1.3 `action_execution_order_test12`: Flash-correct, but the harness grade drops

| | line 17 (`enterFrameOrder`) | line 19 (`asOrder`) | totals |
|---|---|---|---|
| Flash fp9 golden (`output.fp9.txt`) | PASSED | PASSED `0+1+2+3+4+` | 14 / 0 |
| Flash fp10 golden (`output.fp10.txt`, **the one the harness grades**: highest `player_options.version`) | FAILED `…4+3+…5+3+…` | PASSED `0+1+2+3+4+` | 13 / 1 |
| Ruffle (`output.fp10.ruffle.txt`) | PASSED | FAILED `0+1+2+4+` | 13 / 1 |
| ours before | PASSED | FAILED `0+1+2+4+3+` | 13 / 1 |
| **ours after** | PASSED | **PASSED** `0+1+2+3+4+` | 14 / 0 — **== `output.fp9.txt` byte-for-byte** |

Before, the row was `ruffle_matched` (the harness compared it to `output.fp10.ruffle.txt` line-for-line modulo the
"obtained" string). After, line 19 is the Flash line in BOTH Flash goldens, but line 17 still disagrees with the fp10
golden (an FP10-only onEnterFrame-of-unloaded-clip behaviour that is the exec-order sibling's territory, and that Ruffle
also does not match), so the row is graded `output_mismatch`: **−1 effective trace row, by the Flash-over-Ruffle rule a
correct move** (we stop matching Ruffle's wrong line 19 and match Flash's). `known_failure = true`, so this is not a
pass → ruffle_matched regression. Coordinator options: accept the −1; or record it in from_gnash dispositions as
"matches the Flash fp9 golden exactly; fp10 line 17 is player-version behaviour"; or a harness change to grade a
`[subtests]` row as pass when ANY Flash variant matches (not this slot; `verify_output.py` untouched).

## 2. No per-update timer cap

- Flash evidence: `w1-local-oracles/w1-timers-robustness/caps_timers/flash.{wrapped,direct}.txt` (identical): 70
  `setTimeout(fn, 10)` created in frame 1 at 10 fps → `n=70` on frame 2 and every frame after. Ruffle
  (`core/src/timer.rs`): `const MAX_TICKS: i32 = 10; /// The maximum timer ticks per call to update_ticks, for sanity.`
  The cap is Ruffle's own guard, not a Flash rule.
- Flash's rule: every due timer fires (all 70 in one update), i.e. no total per-update cap. For a repeating interval Flash
  runs on real time (a 10 ms interval fires ~10× per 100 ms frame); on our synthetic clock the existing catch-up loop
  (`tick_us += interval_us` while `tick_us < clock`) is the deterministic equivalent. "One fire per timer per frame"
  (gnash's model) is ruled out by the doc'd Flash semantics of short intervals and was not adopted.
- Change (`timer.c`): `TIMER_MAX_TICKS 10` → `TIMER_SANITY_TICKS 1000000` (a hang guard only, keeping Ruffle's clock
  pull-back if ever reached). The loop is finite without it: a timer created in a callback is due after the advanced
  clock, and every interval is ≥ 10 ms. Header comment rewritten with the Flash evidence.
- Fixtures: `avm1_timer_overflow` is now the **w1 SWF byte-for-byte** (traces `n=` on frames 2–9) with the Flash trace
  verbatim; the w2-timers-land stable-prefix variant is retired. `avm1_timer_clock_model` F4 block: c1 = 10 ms fires at
  10..90 (9) and c2 = 13 ms at 13..91 (7) in the first update → `F5 cnt=16`; then 10 + 8 → `F6 cnt=18`, `F7 cnt=18`
  (hand-derived, then confirmed by the run). Still an analytic golden (the old one was Ruffle-analytic): LOCAL ORACLE
  REQUEST 1; Flash's real-time clock may jitter F5–F7 by ±1, in which case the fixture should drop the cnt lines.

## 3. Queues

`action.c`: `g_deferred_unload_mcs` (+ `deferred_unload_room`), `g_deferred_failed_loads` (+ `deferred_failed_load_room`,
4 enqueue sites), `g_pending_lv_loads` (+ `lv_load_room`): static arrays → `ng_table_grow` tables (initial size = the old
cap). None of the unload / failed-load drains runs script, so a realloc can never happen mid-drain.
`processLoadVarsLoads`: the on-stack `local[MAX_PENDING_LV_LOADS]` snapshot is now a heap copy published as
`g_lv_inflight` (saved/restored around the drain), each entry's `lv` NULLed once fired, and both the collector mark loop and
the scrub loop walk it — before, the not-yet-fired snapshot entries were invisible to the collector while earlier entries'
`onData` ran script. Same loops now also mark/scrub `g_pending_load_inits[].mcl` (§VERDICTS 3a).

Probe (`w2b-timers-tail-fixtures/queue_overflow_probe.py`, graphics, same box): failed-load half moves
`f16 tf=1 fl=1 / f23 tf=1 fl=1` → `tf=0 fl=-1` (= `f0`, `f15`). The unload half does not discriminate (an empty
`createEmptyMovieClip` already reads `_totalframes` 0 in frame 1), so it pins nothing for the unload queue. No regression
fixture: the failed-load state values are ours/Ruffle's model, not a Flash oracle → LOCAL ORACLE REQUEST 2.

## 4. Per-test before → after (same box, `--recompile`; before = clean `origin/master` `f35786c2` in a worktree)

Graphics and no-graphics results are **identical** (status and actual-output md5) on every row, before and after.

| Row | before (G = NG) | after (G = NG) | bytes |
|---|---|---|---|
| `regression/avm1_goto_skipped_init_call` (new) | MISMATCH (`f1 after g` before `init2`) | **PASS** | moved |
| `regression/avm1_timer_overflow` (new w1-SWF fixture) | MISMATCH (`n=10 … n=60, n=70`) | **PASS** | moved |
| `regression/avm1_timer_clock_model` | PASS on the old golden (`cnt=10`×3) | **PASS** on the new golden (`16/18/18`) | moved (F5–F7 only) |
| `from_gnash/misc-swfc.all/action_execution_order_test12` | ruffle_matched | **output_mismatch** (== Flash fp9 golden; §1.3) | moved (line 19 + totals) |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval` | ruffle_matched | ruffle_matched | identical |
| `from_gnash/misc-swfc.all/movieclip_destruction_test1` | ruffle_matched | ruffle_matched | identical |
| `from_gnash/misc-ming.all/init_action/InitActionTest2` | pass | pass | identical |
| `regression/avm1_goto_skipped_init_script`, `…_timer` | pass | pass | identical |
| `regression/avm1_timer_{function_form_activation,method_form,native_method_play,root_goto_stopped_gs,root_goto_stopped_nf}`, `timer_cross_swf_version`, `timer_type1_args` | pass | pass | identical |
| from_gnash `action_execution_order_test10`, `gotoFrameFromInterval2`, `InitActionTest` | ruffle_matched | ruffle_matched | identical |
| from_gnash `movieclip_destruction_test2/3/4`, `initaction_in_definesprite`, `getTimer_test` | pass | pass | identical |
| avm1 `set_interval`, `timeout`, `timer_run_actions`, `string_paths_timer`, `do_init_action`, `do_init_action_child`, `register_and_init_order` | pass | pass | identical |

(`avm1/*interval*|*timeout*` = `set_interval`, `timeout`, `timer_run_actions`, `string_paths_timer`: all identical.)

## 5. Sweep, regression suite, canary

- **Sweep 2 (graphics, 42 rows, A/B md5): 42/42 byte-identical, 0 status changes.** Argued scope: every from_gnash SWF
  with a DoInitAction and a multi-frame timeline (`tags_after_last_showframe`, mtasc `levels`/`inheritance`,
  `registerClassTest2`, `RegisterClassTest3/4`, `ActionOrderTest3/4/5` (baseline-failing), `PlaceAndRemove` (init+timer),
  `registerclass_test3`), `gotoFrame2Test` (timer+goto), loader/LoadVars/unload rows for the queue change (gnash
  `loading/loadMovieTest`, `loading/LoadVarsTest`, `actionscript.all/LoadVars-v8`, `MovieClip-v6/v8`, `MovieClipLoader-v8`,
  `XML-v7`, `NetStream-v8`, `Inheritance-v6`, `case-v7`; avm1 `register_class_with_sound`, `loadmovie_registerclass`,
  `attach_movie_stop`, `init_object_order`, `clip_constructors`, `loadmovie_fail`, `load_vars`, `loadvars_tostring`,
  `load_cancel_via_unloadmovie`, `unloadmovie_method`, `unloadmovienum`, `loadvariables_method`, `mcl_loadclip`,
  `loadmovie`; regression `avm1_mcl_load_tick`, `avm1_mcl_holder_totalframes`, `lv_ondata_type1_args`,
  `lv_cross_swf_version`, `onunload_type1_args`, `avm1_child_timeline_advance`).
- **Regression suite near the change:** the 12 `regression/` rows of §4 (all timer + goto-init fixtures) + the 6 regression
  rows of sweep 2: all pass after (both modes for the §4 ones).
- **Render canary** (`render_canary.py capture/compare`, `--recompile`, `-P 2`, before = clean-master worktree) over the
  46 members present in the cloud corpus (avm1 / from_gnash / regression; the other suites were not downloaded — this
  patch touches no AVM2 or render path): **69/69 PNGs IDENTICAL, 0 trace or image status changes.** No canary member
  added: the change class is trace/timing, covered by the regression fixtures.
- Not done: WASM/emcc builds (no emsdk in the cloud). The one new cross-TU call (`action.c` → `tag.c`
  `tagFlushGotoInitsAtCallReturn`) follows `timer.c`'s existing `tagDrainGotoInitActions` dependency: every build that links
  `timer.c`/`action.c` links `tag.c` (`build_test.sh`, `build_wasm_runtime_lib.sh`, `build_wasm_avm2.sh`,
  `build_graphics_host.sh`, the bundle).

## 6. EXPECTED-FLIP LEDGER (coordinator: check CI against this)

**Trace (graphics AND no-graphics):**
- `from_gnash/misc-swfc.all/action_execution_order_test12`: **ruffle_matched → output_mismatch** (EXPECTED; −1 effective;
  Flash-correct, == `output.fp9.txt`; §1.3). Not a regression by rule 3, but it is a status loss the coordinator must accept
  or disposition.
- `regression/avm1_goto_skipped_init_call`: **new row, pass** (absent from baseline; not yield).
- `regression/avm1_timer_overflow`: stays **pass** (fixture content changed: 8 more lines; the old stable-prefix golden is
  replaced).
- `regression/avm1_timer_clock_model`: stays **pass** (golden F5–F7 changed with the code).
- Anything else moving is unexpected. Highest-risk classes if something does: (a) rows where a root goto skips frames with
  DoInitActions and a user function returns later in the same script (inits now run earlier); (b) rows with > 10 timer
  fires due in one update (many timers, or an interval ≪ the frame time) — they now all fire; (c) GC timing around
  LoadVars / MCL (two new mark roots).

**Pixel:** none expected (canary result in §5).

## HOLDs / NO-GOs and completion mechanisms

- `action_execution_order_test12` back to a graded pass: needs either FP10's line-17 enterFrame behaviour (exec-order
  owner; Ruffle fails it too) or a harness rule that accepts a match against any Flash `[subtests]` variant.
- `avm1_timer_clock_model` F5–F7 are analytic: Flash capture (REQUEST 1). If Flash jitters, trim the fixture to its
  stable lines.
- Failed-load / unload queue growth has no committed fixture: Flash capture of the probe (REQUEST 2) → land it as
  `regression/avm1_deferred_load_queue_overflow` with Flash's trace (the failed-load half discriminates; for the unload half
  the probe needs a clip with loaded content — a child SWF — to discriminate).
- `MAX_EI_CALLBACKS` growth (browser hosts only), `MAX_SCROLL_CROPS` / `MAX_TEXT_CULLED`: unchanged (prior HOLDs).

## New unclaimed leads

1. **AVM2 `Timer` has the same Ruffle cap**: `avm2_display.c:3390` `AVM2_TIMER_MAX_TICKS 10` (port of Ruffle
   `Timers::MAX_TICKS`). Whether Flash's AS3 `flash.utils.Timer` caps per frame is unmeasured (AS3 Timer docs say delays
   below ~16 ms are frame-limited); needs a Flash AS3 probe before changing. avm2 category, not this slot.
2. Unmeasured flush corners of §1.2 (goto inside a function; user call after a goto inside a timer callback) — REQUEST 3.
3. Event callbacks other than timers (LoadVars `onData`, LocalConnection, NetStream `onStatus`) run through
   `invokeFunctionValue` too, so a goto issued in one now flushes its inits at the callback's return (before: the AQ entry,
   which runs next anyway). No observable difference expected; unmeasured.

## Functions touched (for siblings / the N session)

- `tag.c`: `tagDrainGotoInitActions` (force path wrapper + re-entrancy guard; body moved verbatim to new
  `static tagDrainGotoInitActionsNow`), new `tagFlushGotoInitsAtCallReturn`. Nothing else in `tag.c`.
- `action.c`: `invokeFunctionValue` (3-line tail hook); deferred unload queue decl + new `deferred_unload_room` + 1 enqueue
  site (the `getURL`/`unloadMovie` arm, `if (deferred_unload_room())`); deferred failed-load decl + new
  `deferred_failed_load_room` + 4 enqueue sites; LoadVars queue decl + new `lv_load_room` + the `builtin_loadvars_load`
  enqueue + `processLoadVarsLoads` snapshot; the collector mark-roots loop and scrub loop (LoadVars + `g_pending_load_inits`).
  **Not** touched: `actionProcessDeferredUnloads` / `actionProcessDeferredFailedLoads` bodies (sibling
  `w2-loaded-shell-land` territory; their indexing syntax is unchanged).
- `timer.c`: header comment, `TIMER_MAX_TICKS` → `TIMER_SANITY_TICKS`, one comparison in `processTimers`.
- No `swf.c` / `swf_core.c` / `tag_stubs.c` / recompiler change (sibling `w2-exec-order-land` owns `swf.c tagMain`).

## LOCAL ORACLE REQUESTS

1. **FLASH**: `regression/avm1_timer_clock_model` (committed `test.swf`), trace, DIRECT, 12 frames: compare F5–F7 `cnt=`
   (ours 16/18/18; Ruffle model 10/10/10) and the F1–F3 order lines.
2. **FLASH**: `w2b-timers-tail-fixtures/queue_overflow_probe.py` (`python3 queue_overflow_probe.py out.swf` from that
   folder), trace, DIRECT, 3 frames. Ours after: `f1 u32 tf=0 f16 tf=1 / u0..u39 tf=0 fl=0 / f0,f15,f16,f23 tf=0 fl=-1`.
   Question: what are a failed-`loadMovie` clip's `_totalframes`/`_framesloaded` one frame later, and is the 17th+ the same
   as the 1st?
3. **FLASH** (optional, cheap): two variants of `regression/avm1_goto_skipped_init_call`'s generator — (a) the goto moved
   inside `g` (`g(){ _root.gotoAndPlay(3); trace("g") }; g(); trace("f1 after g")`), (b) the same frame-1 script run from a
   `setInterval` callback. Question: where do `init2/init3` print in each.
