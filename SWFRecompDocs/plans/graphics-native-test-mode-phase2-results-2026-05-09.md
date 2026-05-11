# Graphics-Native Test Mode — Phase 2 Results (2026-05-09)

Phase 2 of `graphics-native-test-mode-plan.md` ran on 2026-05-09. The
goal: drive the smoke set's `--mode=graphics` pass rate as close to the
NO_GRAPHICS rate as possible, by porting/widening the frame-loop
machinery that `swf_core.c` provides but `swf.c` historically did not.

**Result: 2/9 → 7/9 on the smoke set.** The 5 tests that flipped to pass
all blocked on structural backports listed in the plan; the 2 remaining
failures are subtle semantic issues that need separate investigation.

## Smoke set progression

| Test | NO_GRAPHICS | `--mode=graphics-headless-legacy` | `--mode=graphics` Phase 1 | `--mode=graphics` Phase 2 |
|---|---|---|---|---|
| `add` | pass | pass | pass | pass |
| `tell_target_invalid` | pass | pass | fail | fail (5/6 lines match) |
| `clip_events` | pass | pass | fail | **pass** |
| `edittext_default_format` | pass | pass | fail | **pass** |
| `button_key_events` | pass | pass | fail | **pass** |
| `goto_rewind3` | pass | pass | fail | **pass** |
| `register_and_init_order` | pass | **FAIL** | fail | **pass** |
| `unload` | pass | pass | fail | fail (timing semantics) |
| `bitmap_data_colortransform` | pass | pass | pass | pass |

`register_and_init_order` is interesting: it fails in legacy headless
(known from the Phase 0 baseline) but now passes in `--mode=graphics`.
The Phase 2 work happened to fix the underlying shared-code issue at the
same time it fixed the graphics-native path.

`tell_target_invalid` improved substantially from Phase 1's "first
divergence on line 1" to Phase 2's "extra trace on line 6 out of 7" —
just not all the way to passing.

## Phase 2 commits (in order)

| SHA | Title | Smoke effect |
|---|---|---|
| `8f1b2635` | Phase 2 (partial): port exec_sprite_frame for graphics builds | None alone |
| `fcbcdc94` | Phase 2: backport sprite-init machinery via gate widening | +1 (`edittext_default_format`) |
| `6d054b53` | Phase 2: port ng_executeGotoCatchUp / ng_executeGotoTagsOnly to swf.c | +2 (`goto_rewind3`, `register_and_init_order`) |
| `76d4fbe2` | Phase 2: drive sprite advancement + enter_frame dispatch in swf.c main loop | +1 (`clip_events`) |
| `1995c557` | Phase 2: extract input event pump into shared input_events.c | +1 (`button_key_events`) |

## What changed

### Bulk gate widening (`fcbcdc94`)

The largest single change. All 59 `#ifdef NO_GRAPHICS` gates in `tag.c`
and 158 in `action.c` widened to `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`.
The premise: NO_GRAPHICS arms hold the real frame-loop machinery, and
graphics-native needs the same code paths.

Supporting work for graphics-native to link and run:

- `swf.c` got `MAX_FRAMES` drain-loop bound, `g_drag_*` definitions,
  stubs for goto-catch-up state vars and functions (proper port came in
  the next commit), and `g_current_sprite_obj` / `actionGetFocusRectInfo`
  gated on `#ifndef OFFSCREEN_RENDER` so the real impls win in the new
  mode.
- `graphics_stubs.c` reorganized into "always-active" (catch-up state,
  IME globals, etc.) and `#ifndef OFFSCREEN_RENDER` (no-op stubs that
  duplicate the now-widened tag.c / action.c arms — wasm browser
  graphics still needs these).
- `tag.c::tagShowFrame`: in the `#else` arm under `#ifdef OFFSCREEN_RENDER`,
  call `process_sprite_needs_init` BEFORE `advance_sprite_frames` so
  newly-placed sprites have MovieClip entries when their frame_funcs first
  run. Also fixed `CALL_FRAME` macro in the `!NO_GRAPHICS` arm to dispatch
  through `exec_sprite_frame` so sprite frame_funcs in graphics builds
  get the same MC context switching that NO_GRAPHICS gets.

### Goto-catch-up port (`6d054b53`)

`ng_executeGotoCatchUp` and `ng_executeGotoTagsOnly` ported from
`swf_core.c` to `swf.c` (replacing no-op stubs from `fcbcdc94`). The gate
widening made the supporting helpers (`ng_display_clear_after`,
`ng_swapToRootDL`, `ng_run_deferred_sprite_init_*`, `actionRewindCleanup`,
`actionDrainSuppressEnter|Leave`, `actionGotoCatchupEnter|Leave`)
available in graphics-native, so the catch-up dance ported cleanly.

### Sprite advancement + enter_frame dispatch (`76d4fbe2`)

`swf_core.c`'s main loop calls `advance_sprite_frames` + sets
`g_enterframe_flush_pending` + drains `AQ_KIND_SCRIPT` around each root
frame_func invocation. `swf.c` was missing all of this — sprite
frame_funcs past frame 0 never advanced (so recompiler-emitted sprite
scripts past frame 0 silently never fired), and clip-event ENTER_FRAME
never dispatched (`g_enterframe_flush_pending` stayed 0 so the
recompiler-emitted `tagFlushPendingEnterFrame` calls were no-ops).

Also added `actionFinalizePendingRemovals` at frame start so MCs marked
for pending removal in the previous frame transition to finalized state.

### Input event pump extraction (`1995c557`)

Created `src/libswf/input_events.c` with the file-driven event pump
(`input_events_load`, `input_events_pump_tick`, plus the event delivery
switch — ~400 lines from `swf_core.c`). Phase 3 will retire the duplicate
copies in `swf_core.c` and `swf_headless.c`; for Phase 2 the new file is
only linked in `--mode=graphics`. `main.c` widened to call
`input_events_load(argv[1])` in graphics-native too. `swf.c` calls
`input_events_pump_tick` AFTER `frame_func` + sprite advancement +
SCRIPT drain — initial placement before `frame_func` failed because key
listeners hadn't been set up yet.

## Remaining failures

### `tell_target_invalid` (5/6 lines match)

```
Expected:                                 Actual:
1: Target not found: ... Base="_level0.mc"  ✓
2: /tellTarget('dummy') { gotoAndPlay(n); } ✓
3: pass                                     ✓
4: /tellTarget(undefined) { gotoAndStop(5); } ✓
5: /tellTarget(undefined) { gotoAndPlay(n); } ✓
6: pass                                     "This should only be reached in SWF6 and below"
                                            "pass"
```

Diagnosis: `script_3` (sprite_3 frame 3) does
`SetTarget2(undefined); gotoAndPlay(n); SetTarget(""); Stop()`. After
`SetTarget("")` the targeted_sprite should reset to base_clip
(sprite_3), so `Stop()` should stop sprite_3, preventing frame 4
(`script_4` = "This should only be reached in SWF6 and below") from
running. In `--mode=graphics`, the sprite advances to frame 4 anyway —
likely a SetTarget/targeted_sprite interaction with the new
context-switching path in graphics-native.

### `unload` (timing semantics)

```
Expected at line 22: clip5 = _level0.clip5     (still alive)
Actual at line 22:   clip5 = undefined         (finalized too early)
```

Diagnosis: clips with AS-level `onUnload` handlers vs clip-event UNLOAD
have different finalization timing. The expected output shows clip5
(shifted depth, has clip-event UNLOAD) survives one full frame after
removal, then finalizes. But `actionFinalizePendingRemovals` in
graphics-native finalizes it at the start of the very next frame.
NO_GRAPHICS / legacy headless get this right via mechanisms not yet
clear — likely a generation counter or a timing condition that gates the
finalize against something other than `pending_removal == 1`.

## Lessons for Phase 2 strategy

1. **Bulk gate widening was the right call.** Trying to widen one gate
   at a time would have surfaced cascading symbol issues with no clear
   stopping point. Widening all `#ifdef NO_GRAPHICS` gates at once let
   the link errors guide the supporting fixes (graphics_stubs.c
   reorganization, swf.c globals).

2. **The OR-widening pattern (`#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`)
   is risk-free for existing modes.** OR adds an alternative; existing
   NO_GRAPHICS / HEADLESS builds already satisfy `defined(NO_GRAPHICS)`
   and take exactly the same code path as before. Verified across the
   smoke set after each commit.

3. **swf.c's main loop needed structural additions, not just symbol
   ports.** `advance_sprite_frames`, `g_enterframe_flush_pending`,
   `actionFinalizePendingRemovals`, `input_events_pump_tick` — none of
   these are called from anywhere in the recompiled output. They have to
   be invoked explicitly from the frame-loop body. Each is a one-line
   call but at the right point; misplacement (input pump before
   frame_func) silently breaks the test.

4. **The diagnostic value of `--mode=graphics-headless-legacy` was
   moderate.** It told us `register_and_init_order` was a shared-code
   bug (now incidentally fixed by Phase 2 work), but for the rest it
   confirmed what we already knew: the failures were specific to
   `swf.c`'s frame loop. Phase 3's retirement of the legacy mode
   shouldn't lose much diagnostic capability.

## Cumulative line-count change

| File | Change |
|---|---|
| `SWFModernRuntime/src/libswf/swf.c` | +250 lines (frame-loop integration + goto port + g_drag_*) |
| `SWFModernRuntime/src/libswf/tag.c` | +30 lines net (mostly gate widening) |
| `SWFModernRuntime/src/actionmodern/action.c` | +160 lines net (gate widening) |
| `SWFModernRuntime/src/libswf/graphics_stubs.c` | net ~zero (reorganization) |
| `SWFModernRuntime/src/libswf/input_events.c` | new, +382 lines (extracted from swf_core.c copy) |
| `ruffle-tests/verify_output.py` | +1 line |
| `SWFRecomp/wasm_wrappers/main.c` | +1 line |

Net: ~+800 lines of code changed, mostly mechanical gate-widening that
inverts to deletion in Phase 3 when `swf_headless.c` is retired.

---

## 2026-05-10 follow-up

Smoke set moved from 7/9 → 7/9 (unchanged — the two outstanding subtle
failures `tell_target_invalid` and `unload` are still open) but the
**full-suite numbers jumped by +224 tests** in one session via two
structural fixes. Details in the 2026-05-10 section of
`graphics-native-test-mode-fullsuite-baseline-2026-05-09.md`.

### Two commits, two clusters

**`fff977ec`** — `from_gnash/actionscript.all` was 0/190 because every
test uses Dejagnu, which calls `setInterval(checkIt, 200ms)` and
`Stop()` at frame 0, then waits for the interval to fire `checkIt` →
`gotoFrame(0); play()` to advance through frame 1's Dejagnu module
init. Three nested gaps in `swf.c` kept it stuck:

1. **No `is_playing || manual_next_frame` gate** on the per-tick
   `funcs[current_frame]` call (both `swf_core.c` and `swf_headless.c`
   have it). After `Stop()`, `swf.c` re-ran frame_0 every tick → re-
   queued `script_1` → re-called `setInterval(checkIt, 200ms)` →
   created a brand-new timer entry each tick with `elapsed_ms` reset
   to 0. The 200 ms threshold was never reached.
2. **No `processTimers` call** in the main loop. Even if the timer had
   accumulated, nothing would have fired it.
3. **No `ng_sync_root_display_obj` / `actionSetCurrentContext(&root_movieclip)`**
   before `tagMain`. `actionImportAssets("Dejagnu.swf")` then ran with
   `g_current_context = NULL`, so the imported SWF's `_root.*`
   assignments missed the root MC.

All three gated on `OFFSCREEN_RENDER` — wasm-browser graphics
unaffected. Net: actionscript.all jumped 0 → 125 (+125, NO_GRAPHICS
parity at 126).

**`ebaa7506`** — "SIGSEGV (output matches)" cluster (47 tests in avm1,
plus all of `misc-mtasc.all` and 7 in `misc-ming.all`) was caused by
`swf.c::swfStart` allocating `dictionary` and `display_list` with
system `malloc` while the shared `grow_ptr` helper (`utils.c`) uses
`HALLOC` for the new buffer and `FREE` (= `heap_free`) on the old
one. First display-list growth during execution handed a malloc'd
pointer to `heap_free` → invalid record in the heap pool →
`heap_shutdown`'s enumeration walked into the bad entry at exit.

Fix: mirror `swf_core.c` / `swf_headless.c` — switch to `HCALLOC`
(after `heap_init`) and drop the manual `free()` in shutdown
(heap_shutdown releases the pool). Net: avm1 segfaults 47 → 1;
misc-mtasc reached full NO_GRAPHICS parity (7/7 of those that pass
there).

### Smoke set unchanged

`tell_target_invalid` and `unload` still failing per the diagnoses
above. The structural fixes this session didn't touch the code paths
either depends on. Pick them up after the cluster mining stabilizes.

### Tooling commits (don't affect pass rate)

- `784bb3ae` — CI inherits `ruffle-test-results` instead of building
  from master, so trace/graphics runs don't clobber each other on the
  results branch.
- `b3f2cb8e` — Per-mode `.md` generators (results.md /
  results_graphics.md / results_headless.md per suite + matching
  top-level RUFFLE_RESULTS\*.md). Filter / diff / markdown / index
  generation moved into the commit step (after the branch switch) so
  outputs reflect the merged state.
- `ea65de7f` — Workflow auto-builds Dawn on cache miss in
  `setup-parallel` (~30 min the first time, cached after); ccache
  capped at 200M to prevent eviction of the smaller Dawn cache via
  the 10 GiB per-repo limit; old ccache entries pruned at end of run.
- `7767c265` — Commit step deletes untracked `*_previous.json` before
  the `git checkout -B ruffle-test-results` to avoid an add/add
  conflict on the branch switch.

### Where to start next session

1. Cluster-mine `avm1` (142-test gap pre-session, ~138 post-session).
   Run is at 510/651 with 128 output_mismatch + 1 segfault + 1
   timeout. No dominant cluster left — sort `results_graphics_diff.md`
   by diff size, look for shared first-line divergences.
2. `misc-ming.all` long tail (50+ output_mismatches after segfaults
   resolved).
3. Subtle smokes (`tell_target_invalid`, `unload`) — see diagnoses
   above.

---

## 2026-05-10 follow-up #2 — `quit_swf` premature-exit fix

`swf.c`'s `tagMain` exited as soon as the recompiler-emitted
`quit_swf = 1` fired at the end of the last root frame. That's
incorrect when multi-frame sprites placed by that frame still need to
advance through their own timelines — those sprites are silently
abandoned. Mirror `swf_core.c`'s exit condition (around line 1056):
keep ticking while any of `actionHasEnterFrameHandlers`,
`hasPlayingSprites`, `hasActiveTimers`, `hasPlayingSounds`,
`hasActiveNetStreams`, `hasPlayingLevels`, or
`hasClipEnterFrameHandlers` is true. Only break when `quit_swf` is set
**and** none of those have anything left to do.

Confirmed unlocks (local single-test):
- `avm1/tell_target` (was 0/37 → PASS) — script_3 lives on
  `sprite_6_frame_1`, so it never ran without continued ticking after
  the last root frame's `quit_swf = 1`.
- `avm1/mouse_pos` (was 8/665 → PASS) — 75-frame test with input
  events; loop was exiting after one root cycle.

Smoke set re-checked: unchanged (`tell_target_invalid` and `unload`
still match prior 5/6 and 47/52 status). No regressions in `add`,
`clip_events`, `edittext_default_format`, `button_key_events`,
`goto_rewind3`, `register_and_init_order`, `bitmap_data_colortransform`.

### `actionStop` parity follow-up — not landed

**RESOLVED 2026-05-10 in commits `e527f410` + `f8745996`.** Diagnosis
below is preserved as historical context; the post-resolution writeup
lives in `graphics-native-test-mode-plan.md` (Phase 2 §"2026-05-10
follow-up — `actionStop`/`Play`/`GotoFrame` widening"). Short version:
the infinite loop was in `actionGotoFrame`, not `actionStop` — naive
widening of all three (`actionStop` / `actionPlay` / `actionGotoFrame`)
worked once the `g_current_context != &root_movieclip` branch in
`actionGotoFrame` was reached (which routes through `ng_gotoFrameByMC`
instead of the root-goto fallback that was infinite-recursing through
`ng_executeGotoCatchUp`). A follow-up commit fixed an `issue_9885`
regression in the same path (deferred root-goto branch — see plan doc).

---

Original diagnosis follows:

`avm1/call`, `function_base_clip`, `swf{5,6}_to_{6,5}_cross_call`,
`register_class_swf6`, `cross_movie_root` and similar still fail with
empty (or near-empty) output even after the exit-condition fix. Root
cause for the cluster: when a SPRITE's frame-0 init script calls
`actionStop` (e.g. `function_base_clip`'s `f`-defining script_0),
graphics-native's path falls through to `is_playing = 0` because
`targeted_sprite` is `NULL`. That stops the ROOT — the next root
frame's DoAction (the actual test logic) never runs.

NO_GRAPHICS uses the modern `ng_isInsideSprite()` / `ng_stopCurrentSprite()`
path in the `#else` branch, which stops just the enclosing sprite and
leaves the root playing. Naive widening (OR-ing `OFFSCREEN_RENDER` with
`NO_GRAPHICS` on that branch) introduces an infinite-loop regression
in `function_base_clip`: after the change, `script_1`'s
`this.gotoAndStop(2)` triggers an unbounded sequence of
`actionStop` calls from root context (inside_sprite=0,
fallthrough → is_playing=0). The exact trigger isn't pinned down —
candidate is `ng_gotoFrameCurrentSprite` re-queueing
`actionQueuePendingSpriteScript`, which somehow re-enters
script_0 each tick. Worth a deeper look before re-attempting; the
infinite-loop debug dump from the abandoned attempt is captured in
session notes.

### Where to start next session

1. ~~Investigate the `actionStop` widening regression on
   `function_base_clip`~~ — **DONE 2026-05-10.** The cluster (`call`,
   `function_base_clip`, `slash_syntax`, `target_clip_swf{5,6}`,
   `tell_target_invalid`, …) unlocked. `swf{5,6}_to_{6,5}_cross_call`,
   `register_class_swf6`, `cross_movie_root`, `lock_root` are still
   failing with separate root causes.
2. Continue the `avm1` long-tail (~125 remaining output_mismatch tests
   after this session's commits).
3. Subtle smokes (`tell_target_invalid`, `unload`) — see prior diagnoses.
