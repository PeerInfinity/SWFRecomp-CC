# s27 w2-loaded-shell-land: per-movie display lists phase 3, the deferred unload, and FLASH loader timing

**Slot:** wave 2 (implementation) · **Branch:** `fanout/w2-loaded-shell-land`
**Code base:** origin/master `53540ff02` (runtime = s27 baseline + `d70f2c0a`) · **Upstream Ruffle tests:** downloaded
2026-11-24 (`download_tests.sh avm1 from_gnash from_shumway mixed_avm avm2 visual text fonts`) · **Box:** SETUP_STATUS
all OK (apt, Pillow, Dawn/lavapipe). The gate baseline is the committed `_results/results_graphics.json` /
`results.json` on master.

## New files (all in the patch)

- `ruffle-tests/tests/swfs/regression/avm1_loaded_bare_goto_seq/` (`create_test_swf.py`, `test.toml`, `output.txt`,
  `test.swf`, `child.swf`, `child2.swf`, `child3.swf`)
- `ruffle-tests/tests/swfs/regression/avm1_loaded_shell_consumers_seq/` (… `test.swf`, `child.swf`)
- `ruffle-tests/tests/swfs/regression/avm1_loaded_shell_root_lookup/` (… `test.swf`, `child.swf`)
- `ruffle-tests/tests/swfs/regression/avm1_loaded_timeline_holder/` (… `test.swf`, `child.swf`)
- `ruffle-tests/tests/swfs/regression/avm1_loaded_unload_deferred/` (… `test.swf`, `child.swf`)
- this report, and `w2-loaded-shell-land.patch`.

Every `output.txt` of the five new fixtures is the **Flash Player 32 direct-mode trace** (prefix to `num_frames`) from
`w1-local-oracles/w1-per-movie-dl-phase3/<fixture>/flash.direct.txt`, byte for byte. `avm1_loaded_timeline_holder_xy`
is NOT landed (HOLD, §4).

**Modified, not new:** `action.c`, `tag.c`; `render_canary_tests.txt` (4 members appended at EOF); and the goldens +
a provenance comment in `test.toml` of five existing regression fixtures (§3: `avm1_child_timeline_advance`,
`_frame1_stop`, `_holder_stop`, `_loop`, `avm1_mcl_holder_totalframes`).

## Verdicts

| item | verdict | corpus flips | fixtures |
|---|---|---|---|
| **Phase 3 + root-list accessor + deferred unload** (the w1 prototype, unchanged) | **LANDED** | 0 | `_shell_root_lookup`, `_unload_deferred` fail → pass |
| **Flash delivery tick for direct `loadMovie`**: a load issued in tick N delivers in tick N+1's end-of-tick drain, after the root's tick-N+1 scripts (one tick later than Ruffle and than us) | **LANDED** | 0 status; gnash `misc-mtasc.all/levels` +4 lines | `_timeline_holder` fail → pass; held s26 `avm1_loaded_unload_shell` now equals Flash's whole stable prefix |
| **Loaded shell's clip `enterFrame` runs after the root's frame script, and not on its delivery tick** | **LANDED** | 0 | `_shell_consumers_seq` fail → pass; held s26 `avm1_loaded_shell_consumers` now equals Flash's whole stable prefix |
| Five regression fixtures with **Ruffle-derived** goldens shift by exactly that one tick | **RE-GOLDENED, PREDICTED** (Flash capture requested) | — | §3 |
| Child frame-1 order inside one delivery (`e1 d1 c1`) + goto target script inside a loaded movie deferred to the next tick | **HOLD, priced** (§4) | 0 | held `avm1_loaded_bare_goto` still differs on those 2 axes only |
| Label `GotoFrame2` in loaded movies; `_x`/`_y` identity by name; buttons over shells; text-field depth windows | **HOLD, priced as in w1** (§4) | 0 | `_xy` held |

**Net corpus yield: 0 status flips** (as priced). The gate is clean apart from one improvement (below).

## 1. The gate

**Loaded-child set.** I rebuilt it with the w1 byte scan: every SWF (zlib-inflated) in `avm1 from_gnash
from_shumway regression mixed_avm` matching `loadMovie|loadClip|MovieClipLoader|unloadMovie|_level[1-9]`, plus every
avm1 row that ships more than one SWF. That gives **126 rows**: 83 avm1, 16 gnash, 2 shumway, 2 mixed_avm and 23
regression, including the 6 new fixture dirs. My gnash count is higher than w1's 10 because I walk the nested
sub-suite dirs. The whole `regression` suite (**183 rows**) was then run on top.

**Final patch vs the committed baseline, both modes. Graphics and no-graphics are identical row for row:**

| set | rows | identical | moved |
|---|---|---|---|
| loaded-child corpus rows (non-regression) | 103 | **102** | gnash `misc-mtasc.all/levels`: ruffle_matched 49 → **53** matching lines (still ruffle_matched, `known_failure`) |
| whole `regression` suite | 183 | 170 same + 12 rows absent from the baseline (all pass) | **every row passes**; `avm1_child_timeline_loop` reads as "moved" only because its golden changed (§3) |

The rows identical in both modes include:
- `swf5_to_6_cross_call` and `swf6_to_5_cross_call`;
- every `mcl_*`, `loadmovie*`, `unloadmovie*` and `load_cancel_*` row;
- `movieclip_invalid_get_bounds_*`;
- shumway `moviecliploader` (the Flash-golden MCL row) and `levels`;
- every gnash `MovieClip*`, `MovieClipLoader*` and `TextField*` row;
- `mixed_avm` `avm1_loads_avm2_doaction` and `avm2_loads_avm1_loads_avm2_doabc`.

The delivery change alone (before the enterFrame change) gave the same table, minus the `_shell_consumers_seq` flip.

## 2. Mechanism (owner `file:function`)

### 2.1 Phase 3, root-list accessor, deferred unload

This is the w1 prototype, applied unchanged; its report §1 has the design. Functions:
- `tag.c`: new `ng_rootDLStashPush`, `ng_rootDLStashPop`, `ng_rootDisplayList`, `ng_rootDLEnter`, `ng_rootDLLeave`;
  edited `ng_spriteDLRealloc`.
- `action.c`: `ChildDLSwap` (new trailing field `rootdl_tok`), `childDLSwapIn`, `childDLSwapOut`,
  `actionClearChildMovieShell` (now queues), new `actionClearChildMovieShellNow` and `actionDrainDeferredShellClears`,
  `actionProcessDeferredFailedLoads`, `actionAdvancePlayingLevels`, `actionFirePendingDirectLoads`,
  `actionFirePendingLoadInits` (Phase 2 swap), `actionGetVariableImpl` (the display-list arm), `actionGetMember`,
  `actionGetMemberImpl` (live-max read), and `resolveSlashPathToMC` (now a wrapper over the new
  `resolveSlashPathToMCImpl`).

### 2.2 Flash delivery tick (new)

**Evidence.** Flash Player 32 captures, independent of each other:
- `avm1_loaded_timeline_holder`: `t2 tt:undefined tf:1` then `c1 30`. The load was issued in frame 1; the child's
  frame 1 runs after the root's frame-2 script.
- `avm1_loaded_shell_consumers_seq`: `t3 d:0`.
- s26 `avm1_loaded_bare_goto`: `p2 h0 g0 k0`, before any child frame.
- s26 `avm1_loaded_shell_consumers`: no `cx` before `t3`.

From frame 3 on, in every capture, the root's script precedes the loaded movie's frame in the same tick. **That part
of the order we already had.** `actionAdvancePlayingLevels` runs after the root's scripts. The only error was the
delivery tick.

**Mechanism (`action.c`, self-contained; no queue site touched, no tick loop touched):**
- **Epoch.** New `g_direct_load_epoch`, bumped once per tick at the top of `actionProcessDeferredFailedLoads`. Both
  tick loops (`swf.c` OFFSCREEN and browser arms, `swf_core.c`) call it exactly once, just before the direct-load
  drain.
- **Lazy stamping.** `actionFirePendingDirectLoads` is now a wrapper over new
  `actionFirePendingDirectLoadsImpl(app, fire_all)`. It stamps each not-yet-seen queue entry with the current epoch,
  in a parallel `g_pending_direct_born[]` (`g_pending_direct_stamped` marks the stamped prefix). It fires only
  entries born at an EARLIER epoch, and keeps the rest queued in order. The drain loops'
  `while (count > 0 && guard < 32)` then spins on cheap no-op calls for the kept entries. That is bounded at 32 and
  identical in all three loops.
- **AVM1-under-AVM2 path.** `actionTickAvm1ChildrenUnderAvm2` has no end-of-tick epoch pass, so it calls the Impl
  with `fire_all = 1`. Its old same-drain delivery is preserved. The `mixed_avm` rows are identical.
- **Scope.** Not touched: MCL delivery (`actionFirePendingLoadInits`; shumway `moviecliploader`'s Flash golden still
  passes) and failed-load state (`DeferredFailedLoad`). `_levelN` loads go through the same queue, so they shift too.
  That is the gnash `levels` +4: the four lines that move are exactly the
  suite's own delivery-timing assertions, `_level0.frameno >= 1` (`level5.as:32`), `>= 2` (`level87.as:65`,
  `level99.as:49`) and `>= 3` (`level87.as:57`), all FAILED → PASSED. Gnash's harness asserts that the root has
  advanced one frame further than our old delivery allowed when each level's script runs. That is an independent
  (non-Ruffle) oracle agreeing with the Flash captures; `#passed` goes 45 → 49 and `#failed` 17 → 13.

### 2.3 Loaded shell enterFrame slot (new)

**Evidence.** The s26 Flash capture of `avm1_loaded_shell_consumers`, where the child clip `a` traces `cx` from
`onClipEvent(enterFrame)`:
- `t3 / in: / ev: / cx`, then `t4 … cx`, and so on;
- the loaded movie's clip enterFrame fires AFTER the root's frame script, every tick;
- it does not fire on the delivery tick.

Ours fired it inside the root broadcast, before the root's script, and once on the delivery tick.

**Mechanism.**
- **`tag.c` `dispatch_enterframe_clip_actions_impl`.** The root broadcast's `include_attached` gather now skips
  `(shell, holder)` pairs, where `collect_attached_standalone` yields `mc->display_obj == NULL &&
  mc->loaded_dl_shell == shell`. The overflow fallback (gather cap exceeded) is unchanged.
- **New `tag.c` `ng_dispatch_loaded_shell_enterframe`** (NG/OFFSCREEN only). It collects those pairs and dispatches
  each shell's list through the same `dispatch_enterframe_clip_actions_impl`, with `include_attached = 0` and the
  holder as parent. Holders run newest first, which is the Flash `e1 d1 c1` direction. It skips a holder whose load
  was delivered this tick.
- **New `action.c` `actionLoadedMovieDeliveredThisTick`.** A 16-slot ring of `(mc, epoch)`, written in
  `actionFirePendingDirectLoadsImpl` right after `entry->init_func`.
- **Call site.** `actionAdvancePlayingLevels` calls `ng_dispatch_loaded_shell_enterframe` first, before its
  `g_level_advance_count == 0` early return, because a one-frame loaded movie has no advance entry. So the slot is
  after the root's scripts and before the loaded movies' own frames.
- **Out of scope.** Timeline-holder (phase-3) children still get their clip enterFrame in the root broadcast. They
  are in the root tree, and no fixture or Flash capture grades them. Dynamic `onEnterFrame` handlers of a loaded
  movie's clips go through `actionDispatchEnterFrameHandlers`, the `w2-exec-order-land` slot, which I did not touch.

**Sibling overlap** (`action.c`):
- `w2-exec-order-land` owns `actionDispatchEnterFrameHandlers` / `dispatch_root_dprops_enterframe`. Untouched.
  `dispatch_enterframe_clip_actions_impl` (`tag.c`) is not in their named set, but it is the clip-event half of the
  same order. Flag it to them.
- `w2-timers-land` owns `actionGetMemberImpl`'s dead `efd` branch. My hunk there is the `display_obj` child arm's
  live-max read, a different arm.
- `w2-avm1-leftovers-land`: no overlap.
- `w2-allow-networking-subtests` (getURL arms): I deliberately did NOT edit the four `PendingDirectLoad` queue sites
  (lazy stamping), so their hunks cannot collide.

## 3. Five regression goldens re-derived (Ruffle-derived → Flash-model PREDICTED)

**Fixtures and old goldens.**
- `avm1_child_timeline_advance`, `_frame1_stop`, `_holder_stop` and `_loop`: analytic, from Ruffle source
  (`replace_with_movie` / `determine_next_frame`). See `SWFRecompDocs/status/child-timeline-advance.md` §5.
- `avm1_mcl_holder_totalframes`: the Ruffle exporter's trace.

**What changes.** All five sample from the root's `onEnterFrame`, and each moves by exactly the delivery tick:
- One extra leading pre-load row: `t1 cf:0 …`, or `d [tf:1 fl:1 bt:0]` in the MCL fixture's direct-load control row.
- Each later `tN` row then reads what the old `t(N-1)` row read.
- `_holder_stop`'s parent-issued `stop()` at t3 lands one child frame earlier, so cf freezes at 2 instead of 3.
- `_loop` ends one child frame earlier inside the 12-tick window.

No row they were written to discriminate changes meaning: per-tick advance, stop and resume, frame-count writes. In
`avm1_mcl_holder_totalframes` the MCL rows (`complete` / `init` / `m`) are unchanged; only the direct-load control row
gains its pre-load state.

**What I did.** The new `output.txt` is our post-patch output. It is identical in both modes. Each `test.toml` gets a
provenance comment. **These are PREDICTED goldens, and they are on the LOCAL ORACLE REQUESTS list for a Flash
capture.**

**If Flash disagrees with any of them,** the whole §2.2 model is wrong for that shape, and the coordinator should land
`w2-loaded-shell-land-no-delivery.patch` instead (see Delivery).

## 4. HOLD items, priced (each with its completion mechanism)

1. **Child frame-1 order within one delivery + goto target script inside a loaded movie (M).** The s26 Flash
   `bare_goto` capture shows two orders we do not follow:
   - **Delivery order.** One drain delivers c/d/e in issue order (h, g, k); Flash runs `e1 d1 c1`.
   - **Goto target script.** `d1` + `nextFrame` and `c3` + `gotoAndStop(2)`: Flash runs the target frame's script
     (`d2`, `c2`) on the NEXT tick, after the root's script. Ours runs it inline.

   After this patch, `hbg` (the held fixture) differs from Flash only on those two axes; the delivery tick rows now
   match (`p2 h0 g0 k0`).
   - Mechanism for the delivery order: reverse the clip-target leg of `actionFirePendingDirectLoadsImpl`'s order
     (newest holder first), as `ng_dispatch_loaded_shell_enterframe` already does. This is S.
   - Mechanism for the goto script: a per-movie pending-script slot (`PendingSpriteScript`-style: version, globals,
     list, context), drained by `actionAdvancePlayingLevels` at the head of that movie's next slot, instead of the
     inline `frame_funcs[target]` call in `actionChildMovieBareGoto`. This is M.

   Fixture: land `avm1_loaded_bare_goto` itself with `output.flash.txt` once both are in. 0 corpus rows today.
2. **`_x`/`_y` identity by name (M).** Unchanged from w1 §3: MovieClip identity is keyed by NAME
   (`findOrCreateMovieClip(name, parent)` plus the GetVariable root arm's `display_obj` rebind). The fix is to key a
   timeline child's MC by its display entry. The fixture `avm1_loaded_timeline_holder_xy` is not landed: on Flash's
   prefix it fails only the `tx:` column (`tx:10` where Flash says `tx:30`).
3. **Label `GotoFrame2` / `GoToLabel` in loaded movies (M).** Unchanged from w1: the child's labels are deleted at link
   time by `verify_output.py` `generate_child_movie_file`. Mechanism: keep the block, add a `MovieEntry` labels
   pair, and make `findFrameByLabel` consult it.
4. **Buttons / hit-test over shells (S–M).** Walk the shell pairs in `ng_update_button_states_attached` and
   `hit_test.c`'s attached pass. Needs a mouse-input fixture.
5. **Text-field depth windows over shells (S).** `actionSetTextFieldDepthWindow` for a DefineEditText that a loaded
   movie placed.
6. **Phase-3 (timeline holder) clip enterFrame slot (S).** The §2.3 rule for children of a movie loaded into a
   TIMELINE holder. Mechanism: the root gather skips a sprite whose MC has a live `g_level_advance` entry (it is a
   loaded movie), and `ng_dispatch_loaded_shell_enterframe` adds `display_obj` holders. Needs a Flash capture
   (a `_shell_consumers_seq` twin with a timeline holder).

## 5. Per-test before → after (clean origin/master vs this patch, same box, both modes identical)

All rows were run with `--save-actual` and graded against the golden on disk. The two modes are identical on every
row.

| test | before (origin/master) | after (this patch) |
|---|---|---|
| `regression/avm1_loaded_timeline_holder` (Flash golden) | fail, 1/7 lines (`Warning: Failed to place…`, `c1 10`) | **pass** |
| `regression/avm1_loaded_shell_consumers_seq` (Flash golden) | fail, 11/12 (`t3 d:1`) | **pass** |
| `regression/avm1_loaded_shell_root_lookup` (Flash golden) | fail, 2/4 | **pass** |
| `regression/avm1_loaded_unload_deferred` (Flash golden) | fail, 4/5 (`b:undefined`) | **pass** |
| `regression/avm1_loaded_bare_goto_seq` (Flash golden) | pass | pass |
| `regression/avm1_child_timeline_advance` | pass on the old golden / fail 15/23 on the new one | fail 15/23 on the old / **pass** on the new |
| `regression/avm1_child_timeline_frame1_stop` | pass old / fail 5/7 new | fail 5/7 old / **pass** new |
| `regression/avm1_child_timeline_holder_stop` | pass old / fail 4/26 new | fail 4/26 old / **pass** new |
| `regression/avm1_child_timeline_loop` | pass old / fail 4/32 new | fail 4/34 old / **pass** new |
| `regression/avm1_mcl_holder_totalframes` | pass old / fail 4/5 new | fail 4/5 old / **pass** new |
| `from_gnash/misc-mtasc.all/levels` (gnash golden, `known_failure`) | 49/68 lines | **53/68** |

The s26 held fixtures are graded against the prefix of their Flash capture. They live in my scratch dir, not landed:

| held fixture | before | after |
|---|---|---|
| s26 `avm1_loaded_unload_shell` vs Flash's stable prefix | fail, 4/14 | **pass (whole prefix)** |
| s26 `avm1_loaded_shell_consumers` vs Flash's stable prefix | fail, 1/21 | **pass (whole prefix)** |
| s26 `avm1_loaded_bare_goto` vs `output.flash.txt` | fail, 6/17 | fail, 11/17. Only HOLD 1's two axes remain |
| w1 `avm1_loaded_timeline_holder_xy` vs Flash | fail, 1/7 | fail, 4/7. Only the `tx:` column remains (HOLD 2) |

The held s26 `unload_shell` and `shell_consumers` could now land with their Flash stable prefixes as `output.txt`. I
did not land them: their `num_frames` runs past a looping child, so I would rather the coordinator take that call
than add rows. They are cheap follow-ups.

## 6. Canary

I ran `render_canary.py capture --label before` on clean origin/master source, then `--label after` with this patch.
The set is the standing list plus the 4 members appended at EOF: `regression/avm1_parent_child_{render,bitmap_fill,
morph,text}`. Before this, the set had no loaded-movie render row. That makes 156 tests and 221 comparisons.

**Result: `IDENTICAL 221 / DIFFERS 0 / APPEARED 0 / VANISHED 0 / NO_RENDER 0`; no trace or image status changes.**

The md5 bar holds across the whole set. No `render_webgpu.c` change and no new pipeline.

## 7. EXPECTED-FLIP LEDGER (for the coordinator's CI check)

**Trace axis, graphics AND no-graphics** (run `categories=all` in both modes; this is shared loader code):
- **New rows, expected pass:**
  - `regression/avm1_loaded_bare_goto_seq`
  - `regression/avm1_loaded_shell_consumers_seq`
  - `regression/avm1_loaded_shell_root_lookup`
  - `regression/avm1_loaded_timeline_holder`
  - `regression/avm1_loaded_unload_deferred`
- **Existing rows, golden changed in this patch, expected pass:**
  - `regression/avm1_child_timeline_advance`
  - `regression/avm1_child_timeline_frame1_stop`
  - `regression/avm1_child_timeline_holder_stop`
  - `regression/avm1_child_timeline_loop`
  - `regression/avm1_mcl_holder_totalframes`
- **Line-count move, no status flip:** `from_gnash/misc-mtasc.all/levels`, ruffle_matched, matching lines 49 → 53.
- **Must stay put:** every other row. Explicitly:
  - `avm1/swf5_to_6_cross_call` and `avm1/swf6_to_5_cross_call`;
  - every `avm1/mcl_*`, `loadmovie*`, `unloadmovie*`, `load_cancel_*` and `movieclip_invalid_get_bounds_*` row;
  - `from_shumway/avm1/moviecliploader` and `from_shumway/avm1/levels`;
  - gnash `actionscript.all/MovieClip*`, `MovieClipLoader*` and `TextField*`;
  - `from_gnash/misc-ming.all/loading/loadMovieTest`.

**Pixel axis:** no move expected. The canary is §6, with 4 loaded-child render members appended. A `images=true` run
is not needed for this patch.

## 8. Delivery

- `w2-loaded-shell-land.patch` = `git diff --binary origin/master -- SWFModernRuntime ruffle-tests/render_canary_tests.txt
  <the 5 new fixture dirs> <the 5 re-goldened fixture dirs>`. It is binary because the regression SWFs are tracked.
  Proven with `git apply --check -R` on the branch (index and worktree), and with `git apply --check` forward on a
  clean origin/master worktree.
- `w2-loaded-shell-land-no-delivery.patch`: the fallback if Flash refutes §3. It holds the w1 prototype plus the 3
  delivery-insensitive fixtures (`_bare_goto_seq`, `_shell_root_lookup`, `_unload_deferred`), and no goldens are
  changed. With it, `_timeline_holder` and `_shell_consumers_seq` would fail, so they are left out of it.
  It applies forward on a clean origin/master worktree (checked). Its pass verdicts come from w1's measurement of the
  same prototype; I did not re-run them here.

## New unclaimed leads

1. **MCL delivery vs Flash.** shumway `moviecliploader` (a Flash golden) passes on our current MCL timing, and the
   `avm1_mcl_holder_totalframes` docstring says "our MCL load lands a tick later than Flash's". Now that the direct
   path is Flash-timed, a Flash capture of `avm1_mcl_load_tick` would show whether the two loaders now agree. Unpriced.
2. **Loaded movie's dynamic `onEnterFrame`** (the `actionDispatchEnterFrameHandlers` half of §2.3). Same Flash slot is
   predicted. Needs a capture of the `_shell_consumers_seq` shape with `a.onEnterFrame = …` instead of a clip event.
   S, and it belongs to the `w2-exec-order-land` owner.
3. **Timer-issued `loadMovie`.** A load queued after the drain (from `processTimers`) is stamped one drain later, so it
   delivers 2 ticks after the issue tick instead of 1. Flash's timing for that is unmeasured, and no row grades it.

## LOCAL ORACLE REQUESTS

FLASH (`run_trace.py`, direct mode, compare the prefix to `num_frames`). Each is needed to confirm the §3 PREDICTED
goldens, using the patch's `regression/` dirs:
1. `regression/avm1_child_timeline_advance`, trace, 13 frames: rows `t1 cf:0 …`, then `c1`, then `t2 cf:1 …`.
2. `regression/avm1_child_timeline_frame1_stop`, trace.
3. `regression/avm1_child_timeline_holder_stop`, trace: cf freezes at 2.
4. `regression/avm1_child_timeline_loop`, trace.
5. `regression/avm1_mcl_holder_totalframes`, trace: `d [tf:1 fl:1 bt:0] [tf:4 fl:4 bt:35]`.
6. *(lead 1)* `regression/avm1_mcl_load_tick`, trace.

If 1–5 agree, nothing more is needed. If any disagree, land the `-no-delivery` patch, and put the disagreeing
capture next to this report.
