# s27 w2-timers-land: timers + robustness prototype landed, root-goto-from-timer fixed (both modes)

**Slot:** `w2-timers-land` (wave 2, implementation). Branch `fanout/w2-timers-land`. Base `origin/master` `53540ff02`.
**Box:** cloud, `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Corpus: `download_tests.sh from_gnash avm1 from_shumway
timeline swf mixed_avm` at 2026-11-24 (~02:00 UTC; script prints no SHA; Ruffle source read at upstream `1e604fa87` via a
sparse clone of `core/src`).

> **THIS PATCH TOUCHES NO-GRAPHICS-ONLY CODE (`swf_core.c`, `tag_stubs.c`) AND THE RECOMPILER (`SWFRecomp/src/swf.cpp`).**
> Every headline was run in BOTH modes with `--recompile`. The coordinator should run the no-graphics CI leg as well
> (and `categories=all` is enough: no AVM2 emission change). Every SWF with a DoInitAction regenerates.

## NEW FILES

- `SWFRecompDocs/plans/session27-fanout-reports/w2-timers-land-report.md` (this report)
- `SWFRecompDocs/plans/session27-fanout-reports/w2-timers-land.patch` (`git diff --binary origin/master -- SWFRecomp SWFModernRuntime
  ruffle-tests/tests/swfs/regression/<the 11 new dirs>`; `ruffle-tests/verify_output.py` and `render_canary_tests.txt`
  are untouched)
- `SWFRecompDocs/plans/session27-fanout-reports/w2-timers-land-fixtures/goto_skipped_init_call.py` (+ `avm1asm.py` copy):
  Flash-oracle probe for the goto-init flush point (LOCAL ORACLE REQUEST 1; not a committed fixture)
- 11 regression fixtures, each `test.swf`, `test.toml`, `output.txt`, `create_test_swf.py` (docstring = what it pins,
  owner, golden provenance), `avm1asm.py`:
  - Flash-golden (coordinator's Flash Player 32 captures in `w1-local-oracles/w1-timers-robustness/`):
    `regression/avm1_goto_skipped_init_script`, `avm1_goto_skipped_init_timer`, `avm1_timer_method_form`,
    `avm1_timer_native_method_play`, `avm1_timer_root_goto_stopped_gs`, `avm1_timer_root_goto_stopped_nf`,
    `avm1_timer_overflow` (stable-prefix variant, see §3), `avm1_clone_depth_overflow`, `avm1_watch_overflow`
  - ANALYTIC golden, Flash capture requested (LOCAL ORACLE REQUESTS 2–3): `regression/avm1_watch_long_name`,
    `regression/avm1_clone_depth_removed_reuse`

## VERDICTS

| # | Item | Verdict | Flips (measured) |
|---|---|---|---|
| 1 | Land the w1 prototype (DoInitAction emission, goto-init queue, catch-up hooks, timer.c method form / ToInt32 / growth, watch + clone growth, dead `tagSetFilter*` removal) | **GO, landed.** Fixtures match Flash in both modes. | `from_gnash/misc-ming.all/init_action/InitActionTest2` **ruffle_matched → PASS** (both modes) |
| 1a | w1 rule 2 "inits run after the issuing script, before the target frame's DoAction" | **CONFIRMED by Flash**: `goto_skipped_init_script` Flash = `f1 / f1 after f3 / init2 f3 / init3 f3 / f3` (Ruffle runs them at preload: `init2 f0 / init3 f0 / f1 …`). Timer arm identical after `cb / cb after f3`. | — |
| 1b | `action_execution_order_test12` line 19 (`0+1+2+4+3+` vs Flash `0+1+2+3+4+`) | **Not decided by the Flash captures**: neither goto_skipped fixture calls a function after the goto, so they cannot distinguish "after the issuing script" from w1's "flush at a call return". HOLD → LOCAL ORACLE REQUEST 1 (probe SWF shipped). Row stays ruffle_matched. | — |
| 2 | **Lead 2: root `gotoAndStop`/`nextFrame` from a timer never runs the target DoAction** | **GO, fixed (both modes).** Owner was not the `action.c` goto arms but the frame loop: see §2. | `avm1_timer_root_goto_stopped_{gs,nf}`, `avm1_timer_method_form` (`f2 reached via timer nextFrame`) → pass |
| 3 | **Lead 3: no-graphics twin** | **GO, fixed** by the same mechanism in `swf_core.c`. Graphics vs no-graphics now byte-identical on all 43 swept rows, incl. `gotoFrameFromInterval` (it diverged before). | `avm1_goto_skipped_init_timer` NG → pass |
| 4a | `actionEI_addCallback` true at the cap (lead 4) | **GO (XS)**: returns `false` when the 33rd distinct name is dropped. No fixture (needs an external call handler; the trace harness has none). | 0 |
| 4b | Clone-depth table never forgets removed clones (lead 5) | **GO (S)** — and it is a real bug, not just growth: a stale entry makes a later clone at the removed clone's depth "evict" by name a LIVE clip that reused the name elsewhere. New `ng_clone_forget`. | `avm1_clone_depth_removed_reuse` MISMATCH → pass |
| 4c | Watch names ≥ 64 chars (lead 7) | **GO (XS)**: buffers 64 → `WATCH_NAME_MAX` 512 (= addProperty's buffer) at all 5 sites. | `avm1_watch_long_name` MISMATCH → pass |
| 4d | Load-queue caps (lead 6) | **GO for the two game-reachable queues**: MCL (`MAX_PENDING_MCL_LOADS` 16, all three buckets) and direct `loadMovie`/`loadMovieNum` (`MAX_PENDING_DIRECT_LOADS` 16) now grow; their stack snapshot arrays are heap copies. **HOLD** for `MAX_DEFERRED_FAILED_LOADS` 16, `MAX_PENDING_LV_LOADS` 32, `MAX_DEFERRED_UNLOADS` 32 (same pattern, S each; see HOLDs). No fixture past 16 loads (needs ≥ 17 child SWFs; not built). | 0 (loader rows byte-identical) |
| 5 | **NEW — Flash refutes the Ruffle `MAX_TICKS = 10` timer cap** | **Lead, not changed here.** Flash fired 70 one-shot 10 ms timers before frame 2 (`n=70` on every frame, `caps_timers` Flash capture); our clock (Ruffle `Timers::update_timers` port) fires at most 10 per update (`n=10,20,…`). See §3 and New leads 1. | — |

## 1. What landed from the prototype (unchanged semantics; re-measured)

`w1-timers-robustness-prototype.patch` applied verbatim (it still applied cleanly to `53540ff02`), PROTOTYPE markers renamed
to "landed w2-timers-land". Mechanism and Flash rules: `w1-timers-robustness-report.md` §1–§5. Functions:
`SWFRecomp/src/swf.cpp` (`SWF::interpretTag` DoInitAction + DefineSprite cases, `SWF::parseAllTags` out.h tail);
`tag.c` `tagDoInitActionFrame`, `tagDoInitActionFrameLate`, `tagDrainGotoInitActions`, `tagGotoInitCapture`,
`tagGotoInitTimerPass`, `tagShowFrame` (top block), removal of `getOrCreateExtFilter` / `tagSetFilterColorMatrix` /
`…Convolution` / `…Gradient` / `ng_getExtFilterDataByDepth`; `tag.h` decls; `swf.c`/`swf_core.c`
`ng_executeGotoCatchUp`, `ng_executeGotoTagsOnly`, the tick retry loop; `timer.c` (table growth `timerFreeSlot`,
`timerIsObject`, `fireTimerCallback` CallMethod fallback, `actionTimerClearInterval` ToInt32, `processTimers` batches);
`tag_stubs.c` `clone_depth_register`; `action.c` watch table (`watch_table_room`), `actionGetMemberImpl` dead `efd` branch.

## 2. Lead 2 / lead 3: root goto from a timer callback (new in w2)

**Premise correction.** The owner is not the `action.c` root goto arms. `_root.gotoAndStop(3)` from a callback goes through
`actionCallMethod`'s root arm → `ng_executeGotoTagsOnly`, which (by design, for frame scripts) runs only the skipped frames'
tags and leaves `goto_from_action = manual_next_frame = 1` for the **tick's goto retry loop** to run the target frame. But
the retry loop runs *before* `processTimers` in the tick. When the callback fired after it, the request survived only as
`next_frame`; the end of the tick cleared `manual_next_frame`, and with `is_playing = 0` (gotoAndStop, nextFrame on a stopped
root) the next tick never ran `frame_funcs[target]` at all — the interval meant to be cleared in frame 3 repeated forever.
`gotoAndPlay` "worked" only because the next tick plays the frame (one tick late). Instrumented trace (graphics, clean
master + prototype): `tagsonly gfa=1 mnf=1 cf=0 nf=2` × 10 per update (10 ms interval, MAX_TICKS), `retry` only at the next
tick with `playing=0`.

**Flash** (captures): `f1 / after cf=3 / f3 cf=3` — the target frame's DoAction runs right after the callback, before the
interval fires again.

**Fix** (both frame loops):
- `swf.c`: the retry loop is factored verbatim out of `tagMain` into `static ng_runPendingRootGoto` (called at its old place)
  plus exported `ng_runPendingRootGotoFromEvent`; called again after the event pumps (timers, LoadVars, sound, NetStream,
  NetConnection, LocalConnection) in the OFFSCREEN block.
- `swf_core.c`: same — the inner `while (goto_from_action && manual_next_frame)` catch-up loop of `swfStart` factored into
  `static ng_runPendingRootGoto(app, funcs)` + `ng_runPendingRootGotoFromEvent`, also called after the pumps.
- `timer.c` `processTimers`: `ng_runPendingRootGotoFromEvent` at each **batch boundary** (after the prototype's
  `tagDrainGotoInitActions(…, 1)`, so goto-skipped inits still run before the target's DoAction — Flash order) and at the
  end of the pass. A no-op unless a callback left a root goto pending. Browser-WASM: no-op (its root arms never set
  `goto_from_action`), but the call sites compile there (`swf.c` is in every WASM build).

## 3. Fixtures vs Flash; the timer-overflow stable prefix

All 9 Flash-oracle fixtures use `flash.wrapped.txt` verbatim as `output.txt`, except `avm1_timer_overflow`:
the w1 SWF traced `n=` on frames 2–9 and Flash shows `n=70` from frame 2 on, while our Ruffle-model clock caps at 10 fires per
update (`n=10 … 60, 64→70`). Per the brief ("design the fixture so a stable prefix decides it") the committed SWF keeps
frames 2–9 empty and traces only on frame 10 (both models are at 70 by frame 8); golden = Flash's first and last lines
(`id0=1 id63=64 id64=65 id69=70` / `end n=70`). Removing trace-only actions from frames 2–9 cannot change Flash's timer
behaviour; a confirming capture is LOCAL ORACLE REQUEST 4.

## 4. Per-test before → after (same box, `--recompile`; before = clean `origin/master` `53540ff02`)

Fixtures (before ran on the same fixture SWFs):

| Row | graphics before → after | no-graphics before → after |
|---|---|---|
| `regression/avm1_goto_skipped_init_script` | MISMATCH (no `init2`) → **PASS** | MISMATCH → **PASS** |
| `regression/avm1_goto_skipped_init_timer` | MISMATCH (no `init2`; NG also no `f3`) → **PASS** | MISMATCH → **PASS** |
| `regression/avm1_timer_method_form` | MISMATCH (`ia=undefined`, t2 never cleared, no nextFrame) → **PASS** | MISMATCH → **PASS** |
| `regression/avm1_timer_native_method_play` | MISMATCH → **PASS** | MISMATCH → **PASS** |
| `regression/avm1_timer_root_goto_stopped_gs` | MISMATCH (`after cf=3` ×∞, no `f3`) → **PASS** | MISMATCH → **PASS** |
| `regression/avm1_timer_root_goto_stopped_nf` | MISMATCH → **PASS** | MISMATCH → **PASS** |
| `regression/avm1_timer_overflow` | MISMATCH (`id64=undefined`, `end n=64`) → **PASS** | MISMATCH → **PASS** |
| `regression/avm1_clone_depth_overflow` | MISMATCH (`typeof c135 = movieclip`) → **PASS** | MISMATCH → **PASS** |
| `regression/avm1_clone_depth_removed_reuse` | MISMATCH (live `a` evicted) → **PASS** | MISMATCH → **PASS** |
| `regression/avm1_watch_overflow` | MISMATCH (`r64=false`, `wc=64`) → **PASS** | MISMATCH → **PASS** |
| `regression/avm1_watch_long_name` | MISMATCH (70-char watcher never fires) → **PASS** | MISMATCH → **PASS** |

Corpus rows whose bytes move (identical in both modes after the patch):

| Row | before | after | change |
|---|---|---|---|
| `from_gnash/misc-ming.all/init_action/InitActionTest2` | ruffle_matched | **PASS** | 21/21 |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval` | ruffle_matched | ruffle_matched | +`PASSED: _root.asOrder == x0xx1x234`, `Total tests run: 3`; only case 1 (exec-order NO-GO) left |
| `from_gnash/misc-swfc.all/movieclip_destruction_test1` | ruffle_matched | ruffle_matched | +`initaction mc3 in root frame4` + 2 PASSED, `initActionExecuted` now PASSED; 8 fails left (w1 lead 1) |
| `from_gnash/misc-swfc.all/action_execution_order_test12` | ruffle_matched | ruffle_matched | line 19 `0+1+2+4+` → `0+1+2+4+3+` (same line still wrong; §VERDICTS 1b) |

Everything else in the sweep is **byte-identical** before/after (graphics 75 rows; no-graphics 43 rows; listed below).

## 5. Sweep, regression suite, canary

- **Graphics sweep (75 rows, A/B saved bytes):** the 11 fixtures; from_gnash `InitActionTest(2)`, `gotoFrameFromInterval(2)`,
  `movieclip_destruction_test1`, `action_execution_order_test10/12`, `registerClassTest2`, `registerclass_test3`,
  `tags_after_last_showframe`, `ActionOrderTest3/4/5` (baseline-failing, unchanged), `duplicate_movie_clip_test(2)`, and every
  corpus SWF combining a timer/event callback with a root goto string (scan of avm1/from_gnash/regression/from_shumway/
  timeline/swf/mixed_avm): `actionscript.all/Inheritance-v5..v8`, `MovieClip-v6..v8`, `case-v6..v8`,
  `misc-ming.all/NetStream-SquareTest`, `from_shumway/timeline/Timeline9`; avm1 `set_interval timeout timer_run_actions
  string_paths_timer watch watch_recursion_swf7 watch_textfield watch_virtual_property duplicate_movie_clip bitmap_filters
  do_init_action do_init_action_child register_and_init_order mcl_loadclip mcl_getprogress loadmovie loadmovienum
  loadmovie_var_persistence load_cancel_via_removemovieclip remove_movie_clip removed_clip_halts_script
  target_clip_removed`; regression `avm1_timer_clock_model avm1_timer_function_form_activation timer_cross_swf_version
  timer_type1_args watch_cross_swf_version watch_mc_reentrant_setmember watch_timeline_reentrant avm1_filter_list_overflow
  avm1_runtime_filters avm1_mcl_load_tick avm1_mcl_holder_totalframes avm1_remove_same_name_other_parent
  avm1_exec_order_attached_selfremove avm1_removed_clip_dprops_gc avm1_attached_clip_goto_play`.
  **Bytes moved: the 11 fixtures + the 4 gnash rows of §4. Status flips: InitActionTest2 → pass + 11 fixtures → pass.
  0 regressions.**
- **No-graphics (43 rows):** the fixtures, all from_gnash rows above, Timeline9, `mcl_loadclip`, `loadmovie`,
  `avm1_mcl_load_tick`, `set_interval`, `timer_run_actions`. Same movers; **graphics == no-graphics byte-for-byte on all 43**.
- **Render canary** (`render_canary.py capture/compare`, `--recompile`, `-P 2`) over the 60 members present in the cloud
  corpus (avm1 / from_gnash / from_shumway / regression; the avm2/visual/… members were not downloaded — this patch touches
  no AVM2 or render path): **101/101 PNGs IDENTICAL, no trace or image status changes.** No canary member added: the change
  class is trace/timing, already covered by the new regression fixtures.
- Not done: WASM/emcc builds (no emsdk in the cloud). New runtime symbols live in existing TUs (`swf.c`, `swf_core.c`,
  `tag_stubs.c`, `tag.c`, `timer.c`); every WASM build script already compiles `swf.c` + `tag_stubs.c`.

## 6. EXPECTED-FLIP LEDGER (coordinator: check CI against this)

**Trace, graphics AND no-graphics:**
- `from_gnash/misc-ming.all/init_action/InitActionTest2` **ruffle_matched → pass**.
- New rows (absent from baseline results; not yield): `regression/avm1_goto_skipped_init_script`,
  `avm1_goto_skipped_init_timer`, `avm1_timer_method_form`, `avm1_timer_native_method_play`,
  `avm1_timer_root_goto_stopped_gs`, `avm1_timer_root_goto_stopped_nf`, `avm1_timer_overflow`, `avm1_clone_depth_overflow`,
  `avm1_clone_depth_removed_reuse`, `avm1_watch_overflow`, `avm1_watch_long_name` — all **pass**.
- Bytes move, status unchanged (ruffle_matched): `from_gnash/misc-swfc.all/gotoFrameFromInterval`,
  `movieclip_destruction_test1`, `action_execution_order_test12`.
- No-graphics only: `gotoFrameFromInterval` now equals graphics (it lacked the frame-10 line before).
- Anything else moving is unexpected. Highest-risk classes if something does: rows where a LoadVars/LocalConnection/
  NetStream/sound callback issues a method-form root goto (it now runs within the tick), and DoInitAction rows (every SWF
  with one is regenerated).

**Pixel:** none expected (canary 101/101 identical).

## HOLDs / NO-GOs and completion mechanisms

- `action_execution_order_test12` line 19: Flash capture of `w2-timers-land-fixtures/goto_skipped_init_call.py`
  (REQUEST 1). If Flash flushes queued inits at a function call, change `tagDrainGotoInitActions(…, 0)` from an
  `AQ_PRIORITY_INITIALIZE` queue entry to a flush on the first `CallFunction`/`CallMethod` after the goto; else the row's
  `3+` is a different mechanism.
- `gotoFrameFromInterval` → pass: case 1 is the exec-order NO-GO (instantiation-ordered exec list), not this slot.
- `movieclip_destruction_test1` remaining 8 lines: w1 lead 1 (same-frame init after placements) — sibling
  `w2-exec-order-land` owns same-frame DoInitAction order.
- Remaining fixed queues: `MAX_DEFERRED_FAILED_LOADS` 16 (4 sites), `MAX_PENDING_LV_LOADS` 32 (queue + local snapshot +
  GC loops), `MAX_DEFERRED_UNLOADS` 32 — same `ng_table_grow` + heap-snapshot pattern as the MCL queue here, S each; also
  `MAX_EI_CALLBACKS` growth (browser hosts only). Note: `g_pending_load_inits` (MCL Phase-3 queue) is not a GC root
  (pre-existing; its `mcl` objects are only borrowed) — worth a look by the loader owner.
- `MAX_SCROLL_CROPS` / `MAX_TEXT_CULLED`: unchanged (w1 HOLD, needs a pixel fixture).

## New unclaimed leads

1. **Timer `MAX_TICKS` = 10 is Ruffle's, not Flash's.** Flash fired 70 one-shot `setTimeout(fn, 10)` in the first 100 ms
   update; `timer.c` caps every update at 10 fires (`TIMER_MAX_TICKS`, the s26 port of `Timers::update_timers`).
   `regression/avm1_timer_clock_model`'s F4 golden (16 due → 10 run) is Ruffle-analytic, not Flash. Completion: Flash
   capture of `avm1_timer_clock_model` (REQUEST 5) to learn Flash's actual rule (per-timer cap? none?), then change
   `processTimers` and that golden. Game-visible for many-timer games (each enemy on a setTimeout). M.
2. Event callbacks other than timers (LoadVars `onData`, LocalConnection, NetStream `onStatus`, `onSoundComplete`) now run a
   pending root goto at the end of the pump block, not per callback; if Flash runs the target frame between two such
   callbacks in one tick, a per-callback hook (as in `processTimers`) is the extension. Unmeasured; no corpus row.

## Functions touched (for siblings / the N session)

- `SWFRecomp/src/swf.cpp`: `SWF::interpretTag` (DoInitAction, DefineSprite), `SWF::parseAllTags` (out.h tail).
- `swf.c`: new `static ng_runPendingRootGoto`, new `ng_runPendingRootGotoFromEvent`; `tagMain` (retry loop → call; one call
  after the event-pump block); `ng_executeGotoCatchUp`, `ng_executeGotoTagsOnly` (prototype hooks). **Not** touched: the
  `tagMain` eligibility slot / enterFrame dispatch (`w2-exec-order-land`).
- `swf_core.c`: new `static ng_runPendingRootGoto`, `ng_runPendingRootGotoFromEvent`; `swfStart` (catch-up loop → call; one
  call after the pumps); `ng_executeGotoCatchUp`, `ng_executeGotoTagsOnly`.
- `timer.c`: `processTimers` (batch-boundary + end calls), plus the prototype's table/method-form/ToInt32 changes.
- `tag.c`: prototype functions listed in §1 (+ dead filter removal). `tag.h`: decls.
- `tag_stubs.c`: `clone_depth_register` (growth), new `ng_clone_forget`.
- `action.c`: `actionEI_addCallback` (return value); watch table (`WATCH_NAME_MAX`, `watch_table_room`),
  `builtin_object_watch`, `builtin_object_unwatch`, `actionCallMethod` MovieClip `watch`/`unwatch` arms (buffer size) and
  `removeMovieClip` arm (one `ng_clone_forget` call); `actionRemoveSprite` (one `ng_clone_forget` call); MCL queues
  (`mcl_queue_room`, `mcl_load_init_room`, the loadClip enqueue, `actionPromotePendingMCLLoads`,
  `actionFirePendingLoadInits`, `drain_pending_load_inits`, GC mark/clear loops); direct loads (`direct_load_room`, 4
  enqueue sites, `actionFirePendingDirectLoads`); `actionGetMemberImpl` (dead `efd` branch removed).

## LOCAL ORACLE REQUESTS

1. **FLASH**: `w2-timers-land-fixtures/goto_skipped_init_call.py` (`python3 goto_skipped_init_call.py out.swf`, run from that
   folder), trace, 6 frames. Question: do `init2`/`init3` print before `g f…` or after `f1 after g`?
2. **FLASH**: `regression/avm1_watch_long_name`, trace, 1 frame; compare to its analytic `output.txt`.
3. **FLASH**: `regression/avm1_clone_depth_removed_reuse`, trace, 1 frame; compare to its analytic `output.txt`.
4. **FLASH**: `regression/avm1_timer_overflow` (the committed stable-prefix SWF), trace, 30 frames; expect `output.txt`.
5. **FLASH**: `regression/avm1_timer_clock_model`, trace, 12 frames — the Ruffle-analytic golden (esp. F4 `cnt=10`) vs Flash
   (New lead 1).
