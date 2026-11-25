# s28 w2-loaded-shell-land: loaded-shell residuals landed against Flash (A–E)

**Slot:** wave 2 (implementation) · **Branch:** `fanout/w2-loaded-shell-land` · **Base:** origin/master `775f512d`
(runtime = s28 baseline code `7c3cfdcb7`) · **Upstream tests:** `download_tests.sh avm1 from_gnash from_shumway
mixed_avm`, run 2026-11-25. The script prints no SHA; it is upstream master at run time (`c2f7d24b7` per
BRIEFS_COMMON). · **Box:** SETUP_STATUS all OK (apt, Pillow, Dawn/lavapipe).

## New / changed files

**New**
- `ruffle-tests/tests/swfs/regression/avm1_loaded_order_create_vs_load/`: `create_test_swf.py`, `test.toml`,
  `test.swf`, `childA.swf`, `childB.swf`, and `output.txt`. The golden is the FP32 capture cut after tick 12.
- `ruffle-tests/tests/swfs/regression/avm1_loaded_goto_play_deferred/`: same layout with `child.swf`, also an FP32
  golden cut after tick 12.
- `ruffle-tests/tests/swfs/regression/avm1_loaded_bare_goto/`: the held s26 fixture, landed. Its `output.txt` is the
  FP32 capture `flash-oracle-captures/avm1_loaded_bare_goto/output.flash.txt`. The SWFs were rebuilt with its
  `create_test_swf.py`; the stale `.ruffle-runner-diff.txt` was dropped.
- `session28-fanout-reports/w2-loaded-shell-land-report.md` (this file).
- `session28-fanout-reports/w2-loaded-shell-land.patch`: the full land, binary (`git diff --binary origin/master`).
  It covers `SWFModernRuntime`, `render_canary_tests.txt`, the 6 regression fixture dirs and the 2
  `avm1/_investigation` docs. Verified with `git apply --check` forward on origin/master and `-R` on the branch.
- `session28-fanout-reports/w2-loaded-shell-land-E-only.patch`: the E hunk on its own. `git apply -R` it on top of
  the full patch to land A–D without E.
- `session28-fanout-reports/w2-loaded-shell-land-predicted-goldens/avm1__<test>.output.txt` (7 files): our
  post-E output for the E rows, i.e. the predicted FP32 goldens for flash_fixes.

**Changed**
- `SWFModernRuntime/src/actionmodern/action.c` and `timer.c`.
- Three goldens swapped to Flash: `regression/avm1_child_timeline_loop/output.txt` (the first 32 lines of the FP32
  capture), `regression/avm1_mcl_holder_totalframes/output.txt` and `regression/avm1_mcl_load_tick/output.txt` (the
  full FP32 captures).
- `ruffle-tests/render_canary_tests.txt`: 2 covering members appended at EOF.
- RvF: one new section, appended at EOF. RUFFLE_COMPAT_TWEAKS: "Double onLoadProgress" is marked SUPERSEDED.

## Verdicts

| item | verdict | Flash evidence (all byte-exact after) | corpus effect (graphics = no-graphics) |
|---|---|---|---|
| **A** Loaded movies run **newest LOAD first** (delivery frame 1s and the per-tick advance) | **GO, landed** | `create_vs_load`, `child_timeline_loop` (`d1 c1`), `bare_goto` (`e1 d1 c1`) | 0 |
| **A′** (new) **Delivery tick**: a direct load issued in tick N ≥ 2, before the drain, is delivered in **tick N's** drain. Loads issued from the root's frame 1 still land next tick. | **GO, landed** | `create_vs_load` (`p3`, then `a1 b2`) | 0 |
| **B** A loaded movie's own goto runs its target script **next tick, in its advance slot, then takes its normal step** | **GO, landed, re-fit** | `goto_play_deferred` (`c2 c3` every tick), `bare_goto` | 0 |
| **C′** Every frame-script `loadClip` is delivered next tick; timer-issued loads keep the old rule | **GO, landed** | `mcl_holder_totalframes`, `mcl_load_tick` | 0 |
| **D** `mc.unloadMovie()` cancels a still-queued load of `mc` | **GO, landed** | `load_cancel_via_unloadmovie` (Flash golden) | **+1: `avm1/load_cancel_via_unloadmovie` rm → pass** |
| **E** MCL fires `onLoadProgress` **twice** per load, `loaded == total` | **GO, landed as a separable hunk** | Windows FP32: gnash MCL-v7/v8 (4 runs / 2 loads); `mcl_unloadclip` FP32 == ours; `mcl_load_tick` | **−7 vs Ruffle goldens**; all 7 are flash_fixes candidates (ledger) |

- **Net once the coordinator adds the 7 flash_fixes entries: +1 trace flip and 0 losses.**
- **Until those entries land:** +1 / −7 on the trace axis. Every −7 row prints exactly golden + 1 `onLoadProgress`
  per load. Without E, apply `-E-only.patch -R`: +1 / 0, and `regression/avm1_mcl_load_tick` keeps a 1-line residual.
- Pixel axis: 0 moves (canary md5-identical).

## EXPECTED-FLIP LEDGER (for the CI grading run)

**Trace axis, corpus** (identical in both modes):

| test | before (e1425f417 / 2e286cf2f) | after | why |
|---|---|---|---|
| `avm1/load_cancel_via_unloadmovie` | ruffle_matched | **pass** | D (Flash golden, `known_failure`) |
| `avm1/mcl_unloadclip` | pass | output_mismatch (2/5) | E; **FP32 capture == ours byte-exact** → flash_fixes → pass |
| `avm1/mcl_loadclip` | pass | output_mismatch (61/149) | E; 5 loads of a 68-byte target (Linux == Windows), 5 → 10 progress blocks |
| `avm1/mcl_target_png` | pass | output_mismatch (2/6) | E; 4534 B, so a Windows capture is needed (Linux prints 3) |
| `avm1/mcl_target_jpg` | pass | output_mismatch (2/6) | E; 8078 B, Windows capture needed |
| `avm1/mcl_target_gif87a` | pass | output_mismatch (2/6) | E; 6021 B, Windows capture needed |
| `avm1/mcl_target_gif89a` | pass | output_mismatch (2/6) | E; 6029 B, Windows capture needed |
| `avm1/mcl_mislabeled_target` | pass | output_mismatch (2/6) | E; same bytes as `target.png` |
| `avm1/loadmovie_replace_root` | pass (5 lines) | pass (6 lines) | **upstream drift** (golden gained a line), not yield |
| `avm1/root_onload_loaded_level` | absent | pass | **upstream drift** (new upstream row) |

**Trace axis, regression:**
- New rows, all pass: `avm1_loaded_bare_goto` 17/17, `avm1_loaded_goto_play_deferred` 31/31,
  `avm1_loaded_order_create_vs_load` 33/33.
- Still pass, now graded against Flash goldens: `avm1_child_timeline_loop`, `avm1_mcl_holder_totalframes`,
  `avm1_mcl_load_tick` (14 → 15 lines).

**Pixel axis: none.** The `mcl_target_*` image comparisons stay pass (image status is independent of trace).

## Per-test before/after (same box; before = clean origin/master with the same goldens)

| row | golden | before | after | mode |
|---|---|---|---|---|
| regression/`avm1_loaded_order_create_vs_load` | FP32 | MISMATCH | **pass** | G + NG |
| regression/`avm1_loaded_goto_play_deferred` | FP32 | MISMATCH | **pass** | G + NG |
| regression/`avm1_loaded_bare_goto` | FP32 | MISMATCH | **pass** | G + NG |
| regression/`avm1_child_timeline_loop` | FP32 (32 lines) | MISMATCH | **pass** | G + NG |
| regression/`avm1_mcl_holder_totalframes` | FP32 | MISMATCH | **pass** | G + NG |
| regression/`avm1_mcl_load_tick` | FP32 | MISMATCH | **pass** (A–D alone: 1 line short, the 2nd progress) | G + NG |
| regression/`avm1_loaded_bare_goto_seq` | FP32 | pass | pass | G |
| avm1/`load_cancel_via_unloadmovie` | Flash | RUFFLE_MATCHED | **pass** | G + NG |
| avm1/`mcl_unloadclip` | Ruffle (≠ FP32) | pass | output_mismatch, **== FP32 capture** | G + NG |
| avm1/`mcl_target_png` | Ruffle (≠ FP32) | pass | output_mismatch (+1 progress) | G + NG |

## Gate (the w1 142-row loader set + my 3 new rows = 145; both modes)

- **The set.** It was rebuilt with the w1 recipe: a zlib-inflated byte scan for
  `loadMovie|loadClip|MovieClipLoader|unloadMovie|_level[1-9]` over `avm1 from_gnash from_shumway regression
  mixed_avm`, plus avm1 rows with more than one SWF, plus `regression` dirs named `*load*|*mcl*|*child*`. That gives
  84 avm1, 16 gnash, 2 shumway, 2 mixed_avm and 41 regression rows.
- **How it was graded.** The after-leg ran locally. The before-leg is CI's committed results (graphics `e1425f417`,
  no-graphics `2e286cf2f`). Every moved row was also re-run on clean master locally (table above).

| leg | identical | moved |
|---|---|---|
| A + A′ + B + C′ + D (no E), graphics | 138 / 145 | `load_cancel_via_unloadmovie` → pass; the 2 drift rows; 3 new rows; `mcl_load_tick` 1 line short (E) |
| **final (A–E), graphics** | **131 / 145** | the ledger above, exactly |
| **final (A–E), no-graphics** | **131 / 145** | **the same 14 rows, row for row** |

**Must-stay rows, all identical in both modes:**
- `swf5_to_6_cross_call` and `swf6_to_5_cross_call`;
- every `loadmovie*` and `unloadmovie*` row (`loadmovie_var_persistence` included), and
  `load_cancel_via_removemovieclip`;
- `mcl_events_swf_version` and both `mcl_replace_root_*` rows (they already fired 2×);
- shumway `moviecliploader` and `levels`;
- every gnash `MovieClip*`, `MovieClipLoader*` (`ruffle_matched`, 47/165 unchanged) and `misc-mtasc.all/levels`, and
  `loading/loadMovieTest`;
- both `mixed_avm` rows;
- every `regression/avm1_loaded_*`, `avm1_parent_child_*` and `avm1_child_timeline_*` row.

**A′ moved nothing in the gate.** Same-tick delivery for frame-N ≥ 2 loads is what the runtime did before the s27
per-tick epoch. Every Flash capture that s27 fit "next tick" to loads from the root's frame 1, and that case is kept.

**Render canary** (`render_canary.py`, before = clean master, after = this patch). It ran over the 16
image-compared rows of the gate: the 7 standing canary members that load, plus 9 others, including the 2 new canary
members. Result: **16 / 16 PNG md5-identical**. The only trace-status changes are the 4 `mcl_target_*` E rows.

## Mechanism (owner functions; all `action.c` unless named)

### A. Newest-load-first (w1 prototype, unchanged)
- `actionAdvancePlayingLevels` walks `g_level_advance` reversed, then restores issue order.
- `actionFirePendingDirectLoadsImpl` reverses the clip-target subsequence of one drain's due loads. It skips this when
  a target repeats and for `fire_all`. It then re-reverses the advance entries that drain appended.
- **The re-fit question, answered.** The order key is **LOAD order, not holder creation**. In `create_vs_load`, h1
  is created first and loaded last, and `a` runs first (`a1 b2`, `a2 b1`). The newest-holder model predicts `b`
  first and is refuted.
- The capture's other difference ("`b` delivered a tick before `a`") is **not an order effect**. It is A′.

### A′. Delivery tick (new; this is what the create_vs_load capture actually differs on)
- **Flash.** `h2.loadMovie(B)` in root frame 1 prints `b1` after `p2`. `h1.loadMovie(A)` in root frame 3 prints
  `a1` **before `p4`**, in tick 3's drain: the same tick, after the root's script.
- **The model.** The root's frame 1 runs inside its own delivery (the stub's `_level0` load in direct mode, the
  player's root load standalone), i.e. after that tick's load pass, so frame-1 loads wait a tick. Every other
  frame-script load lands in the same tick's end-of-tick drain.
- **Our s27 rule**, "everything next tick", was fit only to frame-1 loads (`timeline_holder`, `shell_consumers_seq`,
  `bare_goto`, `child_timeline_loop`, `unload_deferred`: all load in frame 1), so it was right for every capture it
  saw.
- **Implementation:** lazy stamping, with the 4 queue sites untouched.
  - **Drain top.** In `actionFirePendingDirectLoadsImpl`, entries still unstamped were queued this tick, before the
    drain. They get `born = epoch − 1`, so they fire now. The exception is the first drain (epoch 2, the root's
    frame 1), where they get `born = epoch`.
  - **Tick start.** New `actionStampCarriedDirectLoads()`, called from `actionPromotePendingMCLLoads` (the first call
    of both tick loops), runs once per epoch. It stamps loads queued after the previous drain (loaded-movie advance,
    timers, MCL events) with `born = epoch + 1`. That is the old next-drain-but-one timing, unchanged.
  - **Why once per epoch.** `tag.c`'s mid-tick promote (when the root is stopped) must not re-stamp the tick's own
    frame-script loads.
  - **Drain end.** New `actionStampNestedDirectLoads()`, called at the end of the `actionFirePendingDirectLoads`
    wrapper, stamps loads queued by the frame 1s that drain ran with `born = epoch`, so they land next tick. Without
    it, the `dl_guard` re-drain loop would fire them in the same tick.

### B. Deferred goto script, re-fit to `goto_play_deferred`
- **Flash.** After `c3` (`gotoAndPlay(2)`), every tick prints `c2 c3`, and `h._currentframe` reads 2 at every root
  line. So the deferred target script runs, and then the movie takes its normal playing step (to frame 3, whose
  script re-issues the goto) in the same slot.
- **The change.** The w1 prototype's `continue` after `childMovieRunDeferredScript` in `actionAdvancePlayingLevels`
  is removed. The entry is re-read and armed, then falls through to the normal advance. A `gotoAndStop` target
  (`bare_goto`) is not playing, so it stays put; that is unchanged.
- Everything else is the w1 queue (`childDeferredScriptPush`, `Take`, `Prune`, `childMovieRunDeferredScript`, and
  the `actionChildMovieGoto` push).

### C′, D (w1 prototype, unchanged)
- **C′.** `builtin_mcl_loadClip` sets `defer_to_next_tick = 1` except inside `processTimers`.
  - `timer.c` `processTimers` is now a wrapper that sets `g_in_process_timers` around `static processTimersImpl`.
  - `g_level_advance_ran_this_tick` arms an MCL registration that is delivered after the tick's advance.
- **D.** New `actionCancelPendingLoadsFor` and `actionCancelPendingDirectLoadsFor`, plus a `cancelled` trailing byte
  on `PendingMCLLoad`. The `mc.unloadMovie()` arm of `actionCallMethod` calls them. A cancelled entry fires
  `onLoadStart` only.

### E. `onLoadProgress` × 2 (`actionFirePendingLoadInits` Phase 1)
- **What changed.** The second fire is no longer gated on `_phase1_switched` (root replacement).
- **Flash's rule**, from the archived oracles:
  - **Windows FP32**, the corpus golden platform per trace-provenance: **2 per load**. The gnash `MovieClipLoader-v8`
    `win1` capture shows `Number of onLoadProgress runs: 4` over 2 loads, `vars.txt` and the 4387-byte
    `green.jpg`. The `mcl_replace_root_*` Flash goldens also have 2, with `loaded = total`.
  - **Linux FP32**: one more per 4096-byte read. The same gnash rows give 5, `mcl_target_png` (4534 B) gives 3, and
    shumway `loader-events` gains 4096/8192 events. Every Linux capture below 4096 B shows 2.
  - So the brief's "per chunk?" reading is the Linux I/O artifact. We model Windows, as the rest of the corpus does.
- **Why it is a separable hunk.** Until flash_fixes lands, the 7 rows grade pass → fail against Ruffle goldens.
  The coordinator can drop E with `git apply -R w2-loaded-shell-land-E-only.patch`.

## Refutations / premise attacks

1. **"Re-fit A: newest load first? per-holder creation order?"** The answer is newest LOAD, already the prototype's
   order. The create_vs_load mismatch is entirely the delivery tick (A′), not order. Per-holder creation order is
   refuted (it predicts `b` first).
2. **"Flash fires progress per chunk / per tick until complete."** Neither, on the golden platform: it is a fixed 2.
   The chunk events are Linux-only. All of them land in one tick (no tick boundary between them in any capture).
3. **"`mcl_target_png` = 3 is the golden to adopt."** No. 3 is a Linux artifact; the flash_fixes golden should be
   the Windows count (2), which is our output. The coordinator must use a **Windows** capture for the > 4096-byte
   rows (flash_fixes rule 1: Linux == Windows).

## HOLD / not finished (each with its completion mechanism)

- **Browser parity of A′ (S).** The browser tick (`swf.c` `__EMSCRIPTEN__ && !OFFSCREEN_RENDER` arm) never calls
  `actionPromotePendingMCLLoads`, so `actionStampCarriedDirectLoads` never runs there. In the browser, a load issued
  by a timer or by a loaded movie's frame is delivered one tick earlier than in CI modes.
  - **Completion:** one call, `actionStampCarriedDirectLoads()`, at the top of the browser tick. That belongs to the
    browser ladder (it owns that arm); I did not touch it.
- **Timer-issued load timing (M, oracle).** The C′ carve-out and A′'s carried-load timing are unmeasured in Flash.
  `loadmovie_var_persistence` is untestable on the pinned harness (empty capture).
  - **Completion:** a fixture that issues `loadMovie`/`loadClip` from a `setTimeout` callback, with no
    data-registry dependence, captured in Flash.
- **D for the other unload arms (S).** `unloadMovieNum`, `MovieClipLoader.unloadClip` and getURL-`""` are not wired.
  Each is a one-line call; each needs a fixture and a Flash capture.
- **Nested loads (a loaded movie's frame 1 issuing `loadMovie`).** These are kept next-tick by
  `actionStampNestedDirectLoads`. Flash is unmeasured; the model argues next tick, by the same reason as the root's
  frame 1.

## Sibling overlap / patch hygiene

- **Every function touched in `action.c`:**
  - edited: `actionChildMovieGoto`, `actionAdvancePlayingLevels`, `actionFirePendingDirectLoadsImpl` (stamping
    block at the top, reversal block, post-loop re-reverse), `actionFirePendingDirectLoads` (wrapper),
    `builtin_mcl_loadClip`, `actionPromotePendingMCLLoads`, `actionFirePendingLoadInits`, and the `unloadMovie` arm
    of `actionCallMethod`;
  - new: `childDeferredScriptsAllowed`, `childDeferredScriptPush`, `childDeferredScriptTake`,
    `childDeferredScriptsPrune`, `childMovieRunDeferredScript`, `actionStampCarriedDirectLoads`,
    `actionStampNestedDirectLoads`, `actionCancelPendingDirectLoadsFor` and `actionCancelPendingLoadsFor`.
- **`timer.c`:** `processTimers` now wraps the static `processTimersImpl`.
- **Overlap with w2-avm1-leads-land.** It also edits `actionFirePendingDirectLoadsImpl`; my hunks there are
  self-contained blocks. It also edits `actionNoteLoadedMovieDelivered`, which I did not touch.
- **Not touched:** `swf.c`, `swf_core.c`, `tag.c` and the recompiler. No `#ifdef NO_GRAPHICS` arm is touched, and the
  gate ran in both modes anyway.
- **Hygiene:** no `Recompiled*` dirs, no `output.actual.png` and no `_results/` edits are committed. The
  `regression` SWFs are force-tracked by `.gitignore`'s negation rule.

## New unclaimed leads

1. **flash_fixes for E.** There are 7 entries, and the predicted goldens are in
   `w2-loaded-shell-land-predicted-goldens/`. `mcl_unloadclip` is ready now (its LNX capture == ours, and the target
   is below one chunk). The other 6 need Windows captures (request 1).
2. **gnash `MovieClipLoader-v7/v8`** (ruffle_matched, 47/165) now fires the Windows count, but the row is blocked
   much earlier (the 404 `onLoadError` path). Unclaimed.
3. **Parent-issued `holder.gotoAndPlay(n)`** still suppresses the target script (the s26 phase-1 HOLD). Flash likely
   queues it for the next tick like B. It needs one fixture plus a Flash capture; the mechanism would be the B queue
   from the `_saved_child_mc != mc` arm.

## LOCAL ORACLE REQUESTS

1. **FLASH (WINDOWS FP32), trace, `num_ticks` from each row's test.toml**, on corpus `avm1/mcl_target_png`,
   `mcl_target_jpg`, `mcl_target_gif87a`, `mcl_target_gif89a`, `mcl_mislabeled_target` and `mcl_loadclip`. Compare
   each against `w2-loaded-shell-land-predicted-goldens/avm1__<test>.output.txt`.
   - Expected result: the predicted file, i.e. 2 `onLoadProgress` per load, with `loadedBytes == totalBytes == size`
     in `mcl_loadclip`.
   - If it matches, add a flash_fixes entry. `mcl_unloadclip` can be added from the existing LNX capture.
