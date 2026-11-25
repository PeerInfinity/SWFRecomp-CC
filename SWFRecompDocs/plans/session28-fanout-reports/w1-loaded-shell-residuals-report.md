# s28 w1-loaded-shell-residuals: newest-first loaded-movie order, next-tick goto scripts, MCL delivery tick, unloadMovie cancel

**Slot:** wave 1 (diagnosis + measured prototype) · **Branch:** `fanout/w1-loaded-shell-residuals`
**Code base:** origin/master `d5f9726d` (runtime = s28 baseline code `7c3cfdcb7`; no runtime diff between them) ·
**Upstream tests:** `download_tests.sh avm1 from_gnash from_shumway mixed_avm`, run 2026-11-25. The script does not
print an upstream SHA, so this is upstream master at run time (`c2f7d24b7` per BRIEFS_COMMON). ·
**Box:** SETUP_STATUS all OK (apt, Pillow, Dawn/lavapipe).

## New files

- this report
- `w1-loaded-shell-residuals-prototype.patch` (`git diff origin/master -- SWFModernRuntime`: `action.c`, `timer.c`)
- `w1-loaded-shell-residuals-fixtures/avm1_loaded_order_create_vs_load/` (`create_test_swf.py`, `test.toml`, SWFs,
  `ours.abcd.txt` = our prediction with the prototype). Flash request 1.
- `w1-loaded-shell-residuals-fixtures/avm1_loaded_goto_play_deferred/` (same layout). Flash request 2.
- To rebuild the SWFs, copy a fixture dir under `ruffle-tests/tests/swfs/regression/` and run its
  `create_test_swf.py`: it imports `../_lib/avm1asm.py`. The built SWFs are committed (force-added).

## Verdicts

The prototype has four separable parts, A to D. All are in one patch, and §2 names the hunks.

| item | verdict | corpus flips (graphics = no-graphics, 142-row gate) | regression / Flash fixtures |
|---|---|---|---|
| **A. Loaded movies run NEWEST LOAD FIRST.** Applies to both the frame 1s delivered by one drain and the per-tick advance. Flash: `e1 d1 c1`, `d1 c1` / `d2 c2` every tick. | **GO (S)** | 0 | `avm1_child_timeline_loop` == Flash prefix (was 10/32). Held s26 `avm1_loaded_bare_goto` == Flash, 17/17 (with B). |
| **B. A goto issued by a loaded movie's OWN code** runs its target frame's DoAction on the **next tick**, in that movie's advance slot. The playhead moves at once. | **GO (M)** | 0 | Held `avm1_loaded_bare_goto` == Flash (with A). `avm1_loaded_bare_goto_seq` (Flash golden) still passes. |
| **C′. Every frame-script `loadClip` is delivered on the NEXT tick.** One-frame loaders are included; timer-issued loads keep today's rule. The movie is registered armed when it is delivered after the tick's advance. | **GO (S), golden-dependent** | 0 | `avm1_mcl_holder_totalframes` == Flash (5/5). `avm1_mcl_load_tick` is Flash except one line, the 2nd `onLoadProgress` (item E). |
| **D. `mc.unloadMovie()` cancels a still-queued load of `mc`.** A direct load never runs. An MCL load fires `onLoadStart` only. | **GO (S)** | **+1: `avm1/load_cancel_via_unloadmovie` ruffle_matched → pass** (`known_failure`, Flash golden) | — |
| E. Flash fires `onLoadProgress` **twice** for a plain clip-target loadClip (mcl_load_tick capture). Corpus goldens show it once. | **HOLD**: needs a FLASH capture of a corpus MCL row (request 3) | — | `avm1_mcl_load_tick` −1 line |
| `avm1_loaded_bare_goto_seq` | **no residual**: Flash golden, passes before and after | — | — |

- **Net corpus yield: +1 effective trace flip** (`load_cancel_via_unloadmovie`).
- **Losses: 0** in both modes, on all 142 loader rows: 84 avm1, 16 gnash, 2 shumway, 2 mixed_avm and 38 regression.
- **Regression-suite moves.** 3 rows move, every one of them away from a non-Flash golden and onto the archived FLASH
  capture. Wave 2 must swap those goldens (§1). Those swaps are the real residual fixes.

## 1. Fixture provenance and the gap vs FLASH (status at `e1425f417`)

All of the brief's fixtures **pass at `e1425f417`** (regression `results_graphics.json`). Each one passes against the
golden on disk, and for three of them that golden is not Flash:

| fixture | golden on disk | FLASH capture | gap: Flash vs our base (= golden on disk) | after prototype |
|---|---|---|---|---|
| `avm1_child_timeline_loop` | s27 **PREDICTED** (our output; Ruffle-derived before that) | `session27-fanout-reports/w2-local-oracles/w2-loaded-shell-land/avm1_child_timeline_loop/flash.direct.txt` (prefix = 32 lines) | **tick structure identical; c/d order reversed in every tick**: Flash `d1 c1`, `d2 c2`, `d1 c3`… vs our `c1 d1`… (22 lines) | **== Flash** (A) |
| `avm1_mcl_holder_totalframes` | s27 **PREDICTED** (our output; exporter before that) | same dir, `/avm1_mcl_holder_totalframes/` | line 3: Flash `m [tf:1 fl:1 bt:0] [tf:4 fl:4 bt:35]`. Flash's t1 poll sees the EMPTY holder, so the MCL load lands after t1. | **== Flash** (C′) |
| `avm1_mcl_load_tick` | **Ruffle exporter** | same dir, `/avm1_mcl_load_tick/` | the whole MCL sequence is 1 tick later in Flash (`t1 h.cf=0` before `onLoadStart`), and Flash has 2× `onLoadProgress` | Flash except the 2nd `onLoadProgress` (C′; E open) |
| `avm1_loaded_bare_goto_seq` | **FLASH** (s27 w1 capture) | `session27-fanout-reports/w1-local-oracles/w1-per-movie-dl-phase3/…/flash.direct.txt` | none | pass (unchanged) |
| held s26 `avm1_loaded_bare_goto` (not landed) | s26 PREDICTED | `flash-oracle-captures/avm1_loaded_bare_goto/output.flash.txt` | delivery order (`c1 d1 e1` vs Flash `e1 d1 c1`), advance order (`c2 d2` vs `d2 c2`), and the goto scripts (`d2`, `c2`) run inline instead of next tick: 11/17 | **== Flash, 17/17** (A + B) |

**Wave-2 golden actions.** No new Flash capture is needed for these; the captures already exist.
- `avm1_child_timeline_loop`: set `output.txt` to the first 32 lines of the Flash capture.
- `avm1_mcl_holder_totalframes`: set `output.txt` to the Flash capture.
- `avm1_mcl_load_tick`: set `output.txt` to the Flash capture. The row then FAILS by one line until E is settled. The
  alternative is to keep the exporter golden and book it as known-wrong.
- Land s26 `avm1_loaded_bare_goto` as `regression/avm1_loaded_bare_goto`, with `output.flash.txt` as its golden.

Every one of these rows passes on the prototype, apart from the `mcl_load_tick` line.

**Premise attacks.**
- **"Child frame-1 order" is half the item.** The brief frames it as an order inside one delivery. The
  `child_timeline_loop` capture shows Flash runs loaded movies newest-first on **every** tick, not only on the delivery
  tick. Reversing only the delivery leaves 20 of the 22 lines wrong (measured: the first prototype reversed only the
  drain, and the advance order stayed issue order).
- **The two A halves interact.** The direct-load drain *registers* the advance entries, so reversing the drain alone
  makes the registration order newest-first. A newest-first advance walk would then run them oldest-first again;
  that was measured, and the fix is in §2.
- **The two MCL fixtures share one mechanism.** It is not two problems: `builtin_mcl_loadClip`'s `_this_tick` bucket
  serves one-frame loaders, and Flash defers those too. The brief's two-loader story ("our MCL load lands a tick later
  than Flash's", in the `_holder_totalframes` docstring) is **refuted** for one-frame loaders: ours lands a tick
  EARLIER than Flash's.

## 2. Mechanism and prototype (owners in `SWFModernRuntime/src/actionmodern/action.c`, plus one `timer.c` wrapper)

### A. Newest-load-first order

- **Advance.** `actionAdvancePlayingLevels` reverses `g_level_advance[0..n)` before its read/write compaction loop.
  It then reverses back the survivors of the original span, so the table keeps its issue order. Entries registered
  mid-pass are appended and are not reordered. Order of record: the table, i.e. load-delivery order.
- **Delivery.** In `actionFirePendingDirectLoadsImpl`, after the existing level sort, the clip-target subsequence of
  the due loads is reversed in place; `is_level` entries keep their slots.
  - The reversal is skipped when one target appears twice: issue order is what makes the later load win.
  - It is skipped for `fire_all`, the AVM1-under-AVM2 path, which is graded by `mixed_avm` and unchanged.
  - After the loop, the advance entries this drain appended are reversed back to issue order (`_adv_n0`), so the
    advance walk of later ticks is newest-first too.
- **Already newest-first.** `ng_dispatch_loaded_shell_enterframe` (tag.c, s27) already walked holders newest-first.
  It was untouched, and it now agrees with the frame order.
- **Unpinned axis.** Is the order by LOAD or by HOLDER creation (the AVM1 execution-list model, where a newer
  instance runs first)? Every capture so far has holders created and loaded in the same order, so the two models
  agree on all of them. Fixture `avm1_loaded_order_create_vs_load` separates them: h2 is created later but loaded
  first. Our prediction (newest load) is `a1 b1`; the execution-list model predicts `b1 a1`. This is **Flash request 1**.
  If Flash says `b` first, the key becomes a per-holder creation sequence, a trailing `MovieClip` field. That is S.

### B. The goto target script on the next tick

- **New:**
  - `ChildDeferredScript` queue: 32 slots, keyed by holder; a second goto in the same tick replaces the first.
  - `childDeferredScriptPush`, `childDeferredScriptTake` and `childDeferredScriptsPrune`.
  - `childMovieRunDeferredScript`: the same context swap as `actionChildMovieGoto` (version, globals, movie id,
    context, shell list via `childDLSwapIn`, transform table, `g_child_movie_advance_mc`). It runs the frame with
    `g_tag_skip_mode = 1` inside `actionDrainSuppressEnter/Leave`.
- **`actionChildMovieGoto`:** the s26 inline `frame_funcs[frame0]` call for an own-code goto now runs only when the
  push fails. The push fails when the queue is full, or under AVM1-under-AVM2 (`childDeferredScriptsAllowed`), which
  has no per-tick epoch pass.
- **`actionAdvancePlayingLevels`:** at the head of each entry's slot, a due script runs, meaning one stamped with an
  earlier `g_direct_load_epoch` (the s27 per-tick epoch). Then the entry is re-read from the live slot, armed, and
  **not advanced this tick**: the deferred target frame IS that movie's frame for the tick.
- **Unpinned axis.** That last rule matters only for `gotoAndPlay`. **Flash request 2**
  (`avm1_loaded_goto_play_deferred`) pins it. Our prediction is `c3`, then `p5 h2`, `c2`, `p6 h2`, `c3`, … (a 2-frame
  loop). If Flash runs `c2 c3` in one tick, drop the `continue` after the deferred run. That is a one-line change.
- **Order inside the tick.** The deferred script runs in the movie's own slot of the newest-first walk. That is
  exactly the Flash `d2 c2` of the `bare_goto` capture: g's deferred d2, then h's advance to c2.

### C′. MCL delivery tick

- **`builtin_mcl_loadClip`:** `defer_to_next_tick = 1` unless the call is inside `processTimers`. In that case the old
  rule stays (`is_playing && current_frame + 1 < g_frame_count`).
- **`timer.c` `processTimers`:** now a wrapper that bumps the new `g_in_process_timers` around a `static
  processTimersImpl` (the old body).
- **Arming.** The next-tick bucket is promoted at the top of the tick. For a parked or one-frame root it fires at the
  end-of-tick MCL site, AFTER `actionAdvancePlayingLevels`, so an unarmed registration lost a frame: `c2` landed one
  tick late, which was measured. Now:
  - the new `g_level_advance_ran_this_tick` is set by `actionAdvancePlayingLevels` and cleared by
    `actionPromotePendingMCLLoads` at the top of the tick;
  - the MCL registration in `actionFirePendingLoadInits` (it was `actionRegisterLevelAdvance`) passes that flag as
    `start_armed`.
- **Why the timer carve-out.** Measured: deferring timer-issued loads too turns `avm1/loadmovie_var_persistence`
  **pass → fail**. Its chain is onLoadComplete → setTimeout → loadClip, and it runs out of `num_ticks = 6`. It also
  costs `load_cancel_via_unloadmovie` (see D).
  - Flash's timing for timer-issued loads is **unmeasured** (s27 lead 3). The carve-out is a horizon guard, not a
    Flash rule.
  - Completion: a Flash capture of `loadmovie_var_persistence` with no tick cap. If Flash also delays the second
    load, the row's golden is fine but its Ruffle `num_ticks` is too short. That would be a `test.toml` horizon fix
    (flash_fixes-style), not a code change.
- **Cost seen in the naive version (C without the carve-out):** `avm1/global_instance_decls` +1 matching line
  (17 → 18). It is gone with the carve-out; no status change either way.

### D. `unloadMovie` cancels a queued load

- **New `actionCancelPendingLoadsFor(mc)`:**
  - It marks the MCL entries for `mc` in both buckets `cancelled`. `cancelled` is a new trailing `u8` on
    `PendingMCLLoad`, zeroed at both queue sites.
  - It drops `mc`'s clip-target entries from the direct queue via the new `actionCancelPendingDirectLoadsFor`. That
    function keeps the `g_pending_direct_stamped` prefix count exact.
- **Call site:** the `mc.unloadMovie()` method arm (`"mc.unloadMovie() — unload content and fire onUnload"`).
- **`actionFirePendingLoadInits`:** a cancelled entry skips the pre-phase, fires `onLoadStart`, then skips
  Progress/Complete, Phase 2 (child init + frame 1) and the Phase-3 queue.
- **Evidence.** The Flash golden of `avm1/load_cancel_via_unloadmovie` is `known_failure`; its `output.ruffle.txt`
  prints both "should not trace" lines and `onLoadInit`. Flash prints `onLoadStart` and nothing more. We now match
  Flash exactly.
- **Not cancelled:**
  - `unloadMovieNum`, `MovieClipLoader.unloadClip`, and the getURL `""` unload arms are not wired. Each is a
    one-line call, but no row grades it.
  - **D is independent of C′ (measured).** A+B+D with C′ reverted gives `load_cancel_via_unloadmovie` **pass**,
    and `loadmovie_var_persistence` still passes. D can land as its own commit.

## 3. Gate (prototype = A+B+C′+D; both modes)

**The set.** I used the s27 byte scan: every SWF (zlib-inflated) in `avm1 from_gnash from_shumway regression
mixed_avm` that matches `loadMovie|loadClip|MovieClipLoader|unloadMovie|_level[1-9]`, plus every avm1 row with more
than one SWF. I added every `regression` dir whose name contains `load`, `mcl` or `child`. That is **142 rows**: 84
avm1, 16 gnash (`actionscript.all` 11, `misc-mtasc.all` 3, `misc-ming.all` 2), 2 shumway, 2 mixed_avm and 38
regression.

**How it was graded.** The after-leg ran on this box. The before-leg is the committed CI results: graphics
`e1425f417`, no-graphics `2e286cf2f`. On clean master, a local before-leg confirmed `global_instance_decls`
(17/758) and `root_onload_loaded_level` (pass). The `load_cancel_via_unloadmovie` before-state is CI's
`ruffle_matched`; the A+B-only leg reproduces it locally.

| mode | identical to baseline | moved |
|---|---|---|
| graphics | 137 | `avm1/load_cancel_via_unloadmovie` ruffle_matched → **pass**; `avm1/root_onload_loaded_level` absent from the baseline (new upstream row = **drift**; it passes on clean master too, measured); the 3 regression golden rows of §1 (all onto Flash) |
| no-graphics (vs `2e286cf2f`) | 137 | **the same 5 moves, row for row** (`load_cancel_via_unloadmovie` → pass; `root_onload_loaded_level` drift; the 3 §1 rows onto Flash) |

**Isolation measured on the way:**
- A+B alone: identical to baseline on every row that moved under C. That covers `load_cancel_via_unloadmovie`,
  `loadmovie_var_persistence`, `global_instance_decls` and `root_onload_loaded_level`.
- The first full gate ran A+B+naive C, and it showed 2 losses: `loadmovie_var_persistence` pass → fail, and
  `load_cancel_via_unloadmovie` ruffle_matched → fail. Both are gone in the final patch.
- `load_cancel_via_removemovieclip` still passes.

**Must-stay rows, all identical in both modes:**
- `swf5_to_6_cross_call` and `swf6_to_5_cross_call`;
- every `mcl_*`, `loadmovie*` and `unloadmovie*` row, and `load_cancel_via_removemovieclip`;
- `movieclip_invalid_get_bounds_*`;
- shumway `moviecliploader` (Flash golden, multi-frame loader: already on the deferred bucket) and `levels`;
- gnash `MovieClip*`, `MovieClipLoader*`, `TextField*`, `misc-mtasc.all/levels` (53/68, unchanged) and
  `loading/loadMovieTest`;
- both `mixed_avm` rows;
- every Flash-golden `regression/avm1_loaded_*`;
- `avm1_child_timeline_advance`, `_frame1_stop` and `_holder_stop`: one loaded movie, so order-insensitive.

## 4. HOLD / NO-GO, priced, each with its completion mechanism

- **E. Double `onLoadProgress` (S, blocked on oracle).** The Flash 32 capture of `avm1_mcl_load_tick` has two, while
  every corpus MCL golden has one per clip-target load. That holds for `mcl_unloadclip`, `mcl_target_*` and
  `mcl_mislabeled_target`; `mcl_replace_root_*` has two, and that case is already RUFFLE_COMPAT_TWEAKS "Double
  onLoadProgress for Root Replacement Loads".
  - Two readings:
    - the corpus goldens are Ruffle-runner output, and Flash always fires 2 (a flash_fixes candidate across ~8 rows);
    - or Flash's count depends on streaming or file size (the fixture's child is 3 frames and <100 bytes).
  - **Completion:** FLASH request 3 (`avm1/mcl_unloadclip` trace). If it shows 2, the change is the second fire, no
    longer gated on `_phase1_switched` in `actionFirePendingLoadInits` Phase 1, plus flash_fixes swaps for every row
    whose Flash capture agrees. If it shows 1, `mcl_load_tick` keeps a 1-line residual. That would be an ACCEPTED or
    RvF entry for the fixture, or the coordinator re-captures with a larger child.
- **D for the other unload arms (S).** Call `actionCancelPendingLoadsFor` from `unloadMovieNum` / `unloadClip` /
  getURL-empty. That needs a fixture and a Flash capture first.
- **Timer-issued load timing (M, oracle).** Covered under C′ above. The completion mechanism is a Flash capture of
  `loadmovie_var_persistence` uncapped, or of a fixture with a setTimeout-issued loadClip.

## 5. Patch hygiene / sibling overlap

- **Every touched function**, all in `action.c` unless named otherwise:
  - edited: `actionChildMovieGoto`, `actionAdvancePlayingLevels`, `actionFirePendingDirectLoadsImpl`,
    `builtin_mcl_loadClip`, `actionPromotePendingMCLLoads`, `actionFirePendingLoadInits`, and the `unloadMovie`
    method arm (in the CallMethod MovieClip dispatcher);
  - new: the static helpers listed in §2, `actionCancelPendingLoadsFor` and `actionCancelPendingDirectLoadsFor`;
  - `timer.c`: `processTimers`, now a wrapper over `processTimersImpl`.
- **Not touched:** `swf.c`, `swf_core.c` and `tag.c`. The tick loops are unchanged.
- **Mode parity.** No `#ifdef NO_GRAPHICS` arm is touched. The shared arms are covered by the both-modes gate.
- **Overflow paths:**
  - deferred-script queue full: falls back to the old inline run;
  - a pending script whose movie is gone: pruned at the end of each advance pass.

## New unclaimed leads

1. **Order key: load vs holder creation** (request 1). If it is holder creation, the same key probably also orders a
   loaded movie against timeline children of the root. That case is unmeasured.
2. **`gotoAndPlay` from a parent** (`holder.gotoAndPlay(n)` in a parent frame) still suppresses the target script.
   That is the s26 phase-1 HOLD. Flash likely queues it the same way as B, for the next tick. One fixture plus a
   Flash capture would settle it; the mechanism would be the B queue from the `_saved_child_mc != mc` arm.
3. **flash_fixes candidates:** none proven yet. Request 3 could produce up to ~8 (`mcl_*` onLoadProgress count).

## LOCAL ORACLE REQUESTS

All are FLASH (`tools/flash-oracle/run_trace.py`), **direct** mode (not `--wrapped`), trace, prefix to `num_frames`.
1. **FLASH: `w1-loaded-shell-residuals-fixtures/avm1_loaded_order_create_vs_load`**, trace, 12 frames. Compare a/b
   order once both play, against `ours.abcd.txt`: `a1 b1` means newest load first (the prototype); `b1 a1` means
   newest holder first.
2. **FLASH: `w1-loaded-shell-residuals-fixtures/avm1_loaded_goto_play_deferred`**, trace, 12 frames. Questions: does
   the tick after `c3` run `c2` only (prototype), or `c2 c3`? And what does `p<N> h<cf>` read in between? Ours is in
   `ours.abcd.txt`.
3. **FLASH: corpus `avm1/mcl_unloadclip`** (Ruffle download), trace, `num_ticks = 11`. The question is how many
   `Event: onLoadProgress` lines it prints, 1 or 2 (§4 E). Optional twin: `avm1/mcl_target_png`.
4. *(optional)* **FLASH: corpus `avm1/loadmovie_var_persistence`**, trace, **uncapped** (≥ 12 ticks). This is the
   timer-issued loadClip timing (§2 C′ carve-out).

The captures for the three regression golden swaps already exist (s27 batch 4), so no request is needed for them.
