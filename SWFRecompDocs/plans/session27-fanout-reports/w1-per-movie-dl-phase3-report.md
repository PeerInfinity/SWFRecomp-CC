# s27 w1-per-movie-dl-phase3: per-movie display lists phase 3, the loaded-shell remainder, the held fixtures

**Slot:** wave 1 (diagnosis + measured prototype) · **Branch:** `fanout/w1-per-movie-dl-phase3`
**Code base:** origin/master `ae7f50cb` (runtime = s27 baseline `005bea42a` + `d70f2c0a`) · **Upstream Ruffle tests and
source:** `1e604fa87` · **Box:** SETUP_STATUS all OK (apt, Pillow, Dawn/lavapipe). Baseline for the gate: the committed
`_results/results_graphics.json` / `results.json` on master (`df7729df2` / `81d32b9b2`).

## New files

- this report;
- `w1-per-movie-dl-phase3-prototype.patch`: `git diff origin/master -- SWFModernRuntime`, 2 files (`action.c`,
  `tag.c`), +191/−2. It applies cleanly to origin/master. Source is reverted on the branch.
- `w1-per-movie-dl-phase3-fixtures/`: six fixture dirs (generator, `test.toml`, PREDICTED `output.txt`; `*.swf` is gitignored, so run `python3 create_test_swf.py` in each after copying it under `regression/`). They
  are laid out for `ruffle-tests/tests/swfs/regression/` (the generators import `../_lib/avm1asm.py`):
  - `avm1_loaded_timeline_holder` (the parked s26 phase-3 fixture, unchanged);
  - `avm1_loaded_shell_root_lookup` (new: root-arm lookups from inside a loaded movie's frame);
  - `avm1_loaded_unload_deferred`, `avm1_loaded_bare_goto_seq`, `avm1_loaded_shell_consumers_seq` (delivery-tick
    insensitive rewrites of the three HELD s26 fixtures);
  - `avm1_loaded_timeline_holder_xy` (the `_x`/`_y` lead, which still fails after the patch).

## Verdicts

| item | verdict | corpus flips | fixture before → after (both modes) | price |
|---|---|---|---|---|
| **Phase 3 + root-list accessor** (`ng_rootDisplayList` and a scoped `ng_rootDLEnter/Leave`) | **GO**, prototype measured | 0 | `avm1_loaded_timeline_holder` fail → **pass**; `avm1_loaded_shell_root_lookup` fail → **pass**; `swf{5_to_6,6_to_5}_cross_call` **stay pass** | **M** (as priced) |
| **Deferred `unloadMovie` of a loaded movie** (new; it settles the held `_unload_shell`) | **GO**, prototype measured | 0 | `avm1_loaded_unload_deferred` fail → **pass** | S |
| **Held fixtures: runner or our model?** | **settled from source**: corrected goldens below | 0 | 3 rewrites pass in both modes, before and after | — |
| Buttons / hit-test over shells | HOLD: 0 rows | 0 | none (needs mouse input) | S–M |
| Text-field depth windows over shells | HOLD: 0 rows | 0 | none | S |
| Label `GotoFrame2` / `GoToLabel` inside a loaded movie | HOLD: 0 rows. **Repriced M** (the child's labels are deleted at link time) | 0 | none | **M** |
| Parent-issued `holder.gotoAndStop` suppresses the target DoAction | HOLD: 0 rows | 0 | none | S–M |
| `_x`/`_y` getters keyed by name | HOLD: **measured**. The real owner is MovieClip identity keyed by name | 0 | `avm1_loaded_timeline_holder_xy` still fails | M |

**Net corpus yield: 0 rows, as the s26 pricing predicted.** The prototype changes nothing outside loaded-movie frames.

**Gate (final patch):**

| set | mode | rows | result |
|---|---|---|---|
| every loaded-child row (byte scan, below) ∪ the whole `regression` suite | graphics (CI mode) | **268** | **268 identical** to the committed baseline (status + matching lines) |
| every loaded-child row | no-graphics | **112** | **112 identical** |

The loaded-child set is a byte scan of every SWF (zlib-inflated) in `avm1 from_gnash from_shumway regression mixed_avm`
for `loadMovie|loadClip|MovieClipLoader|unloadMovie|_level[1-9]`, plus every avm1 row that ships more than one SWF.
That gives 112 rows (81 avm1, 10 gnash, 2 shumway, 2 mixed_avm, 17 regression). Together with the 156 other regression
rows the union is 268. It includes `swf5_to_6_cross_call`, `swf6_to_5_cross_call`, `movieclip_invalid_get_bounds_1..8`,
`video_prototype_lazy_swf6_child`, every `mcl_*` / `loadmovie*` / `unloadmovie*` / `load_cancel_*` row,
`regression/*loaded*`, `avm1_child_timeline_*`, `avm1_parent_child_*`, `avm1_mcl_*`, and shumway `moviecliploader` and
`levels`.

Every intermediate patch was gated the same way:
- phase 3 + accessor alone: 268 graphics and 112 no-graphics, all identical;
- + deferred unload: 112 + 112, all identical;
- final, adding the getMember and slash-path accessor arms plus the live-max read: 268 + 112, all identical.

No `swf.c`, `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS`-only arm is touched. Every new code path sits in an
`NO_GRAPHICS || OFFSCREEN_RENDER` arm or in shared code, and both modes were measured.

## 1. Phase 3: the −2 reproduced, its cause pinned, the accessor fixes it

**Reproduced.** I applied the parked s26 loader hunks alone:
- `actionFirePendingDirectLoads`: swap into `mc->display_obj`'s sprite list for a non-level holder;
- `actionFirePendingLoadInits` Phase 2: the same.

Result: `swf5_to_6_cross_call` and `swf6_to_5_cross_call` pass → MISMATCH in graphics. The `clip.f():`, `_root f():` and
`root obj toString:` bodies vanish, exactly as s26 measured.

**Owner.** The `actionGetVariableImpl` global fallback, at its NG/OFFSCREEN display-list arm (`action.c` ~50891 on
master, `size_t child_depth = ng_findDisplayEntryByName(name_buf)`):
- It treats the active `display_list` as the ROOT's list. It binds `findOrCreateMovieClip(.., &root_movieclip)` and
  `child_mc->display_obj = &display_list[child_depth]`.
- The parent's `onLoaded` (DefineFunction2, `GetVariable "clip"` then `CallMethod "f"`) is called synchronously from the
  child's frame 1 while `clip`'s own list is active. So `"clip"` is not found and `clip.f` is undefined.

**Mechanism (the patch, `tag.c` block after `ng_unbumpSpriteInitDepth`, inside the existing NG/OFFSCREEN region):**
- **Root-list stash.** `g_rootdl_stash{,_max,_cap,_on}` is set by `ng_rootDLStashPush()` on the OUTERMOST swap away from
  the root list. When a sprite init is in flight it takes `g_root_dl_backup`, the same rule `ng_swapToRootDL` uses.
  `ng_rootDLStashPop()` releases it.
- **Accessors.** `ng_rootDisplayList(&max)` returns the root list whatever list is active. `ng_rootDLEnter` /
  `ng_rootDLLeave` are a scoped switch to the root list that commits back on leave.
- **Rebase.** `ng_spriteDLRealloc` rebases the stash like `g_root_dl_backup`.

**Engaged by** (`action.c`):
- `childDLSwapIn` / `childDLSwapOut` (a new `rootdl_tok` field in `ChildDLSwap`);
- `actionAdvancePlayingLevels`'s per-entry swap (non-level holders only: for a `_levelN` the swapped list IS that
  movie's `_root`);
- `actionFirePendingDirectLoads`' shell swap and the new phase-3 swap.

The `_levelN` swaps never engage it, so level movies are unchanged by construction.

**Read by** (root-arm lookups only):
1. `actionGetVariableImpl`'s display-list arm, when `g_current_context` is the root (or NULL). This alone turns both
   cross_call rows green.
2. `actionGetMember`: the wrapper, when the object is `&root_movieclip` (`_root.px` from inside the loaded frame).
3. `resolveSlashPathToMC`: the new wrapper over the renamed `resolveSlashPathToMCImpl`, when `start_mc` is the root
   (`/px`).

**Plus one stale-max fix.** In `actionGetMemberImpl`'s `display_obj` child arm, while a holder's sprite list IS the active
list, its stored `sprite_max_depth` is only written back at swap-out, so the arm reads the live `max_depth`. This is the
same rule as phase 1's shell arm. Without it, `this.q` (q placed in the movie's frame 1) is undefined during frame 1.

**Measured evidence:**

| state | cross_call ×2 | `avm1_loaded_timeline_holder` | `avm1_loaded_shell_root_lookup` |
|---|---|---|---|
| master | pass | fail: `Warning: Failed to place object at depth 1.`, `c1 10`, `tt:undefined` ×4 | fail: the warning, plus `q:`/`tq:` undefined on the timeline holder |
| s26 loader hunks only | **MISMATCH** (−2) | pass | — |
| + accessor in GetVariable | pass | pass | fail: `r:`/`s:` undefined in the timeline holder's frames (`_root.px`, `/px`); `tq:` undefined in its frame 1 |
| + getMember and slash-path arms + live max (final) | **pass** | **pass** | **pass** |

All rows were measured in both modes.

`avm1_loaded_shell_root_lookup` has two holders loading the same 2-frame child:
- a `createEmptyMovieClip` holder `h` (a phase-1 shell);
- a timeline sprite `th` (phase 3).

Each child frame traces `typeof _root.px`, `typeof eval("/px")`, `typeof q` and `typeof this.q`, where `px` is a root
timeline sprite at the same depth as the child's `q`. The shell rows already pass on master. s26 lead 1 (the same hazard
for phase-1 shells) does **not** reproduce through these four readers: the shell holder's `_root.px` resolves on master.
That lead stays real only for the GetVariable arm (the cross_call shape), and the accessor covers it for shells too,
because `childDLSwapIn` engages it.

**Not done (hardening, no row):**
- The other ~50 `ng_findDisplayEntryByName(mc->name)` sites that mean the root list; the GetVariable, getMember and
  slash-path arms are the three that resolve a name *from scratch*.
- `actionHolderShellList` reading a stale stored max when a root-arm path descends into a shell during that same shell's
  frame. The live max is in the `ng_rootDLEnter` save slot then.

## 2. The held fixtures: who is right (re-derived from Ruffle source `1e604fa87`)

**Correction to the brief.** The three fixtures are archived under
`session26-fanout-reports/w2-held-fixtures/`, not `w2-loaded-shell-phase2-parked/`. That directory holds only the phase-3
fixture.

**Refutation of the held README** ("the exporter cannot serve them: it never loads the child SWFs"). It can. This is the
`RUFFLE_LOCAL_FETCH_DIR` + `RUFFLE_MOVIE_URL=https://armorgames.com/test.swf` recipe that
`regression/avm1_mcl_load_tick` and `avm1_mcl_holder_totalframes` already used for their goldens. So every fixture here
can get an exporter golden; see the requests.

**The three mechanisms in current Ruffle source.** They are byte-for-byte the same in the Feb-2026 tree (`0f49392ef`,
checked with `git show`):
1. **Exec order.** `avm1/runtime.rs::run_frame` walks `clip_exec_list`, and `add_to_exec_list` PREPENDS. A holder created
   by root's frame 1 therefore runs BEFORE root every tick, newest first. Each clip's DoAction is queued, and
   `run_actions` drains the queue FIFO at the end of `update`.
2. **Delivery.** An AVM1 load completes in a future between ticks:
   - `loader.rs::movie_loader_data` → `replace_with_movie(.., is_root=true, ..)`;
   - `current_frame = 0`, `PLAYING`;
   - the movie's frame 1 runs in the NEXT `run_frame`, in the holder's exec-list slot.
3. **Goto target script.** It is queued at the END of the action queue (after root's already-queued frame script).

That fully explains the Feb runner's traces:
- `bare_goto`: `e1 d1 c1 p2 d2` (newest first; `d2` after `p2` because nextFrame's target script is appended), then
  `c3 p4 c2`;
- `shell_consumers`: no `cx` before `t2`;
- `unload_shell`: the trailing-`c2` difference.

Our model (`swf.c` ~1310–1340) differs in one way. It fires direct loads at the END of the issuing tick (after root's
script) and advances loaded movies AFTER root each tick. Every other difference is that one tick-phase offset.

**Is Ruffle the Flash order?** Not on delivery, and the corpus has a Flash oracle for exactly this.
`from_shumway/avm1/moviecliploader` (`known_failure = true`, Ruffle issue 12273) has a Flash `output.txt` that runs
root's `loader frame 2` BEFORE `onLoadStart … loadee frame 1` on the delivery tick, while its `output.ruffle.txt` runs
the loadee first. We pass it by following Flash (s19 `w1-loaders-report.md` §4.1). So Ruffle's runner is **not** an
authority on the root-vs-child order on the delivery tick. No Flash row pins the direct-`loadMovie` delivery tick
either, so neither model can be proven there.

**Ruling per fixture:**
- **`avm1_loaded_unload_shell`: the RUNNER is right on `b:`; our model (s26 phase 5) is wrong.**
  - `MovieClip::avm1_unload_movie` defers `avm1_unload` + `transform_to_unloaded_state` to a spawned future when
    `is_root()`.
  - A loaded movie IS a root clip in Ruffle: `replace_with_movie(.., true, ..)` sets `is_root`.
  - Ruffle's own comment there says Flash enters the unloaded state "one frame after the unloadMovie command … even if
    the MovieClip is not a root MovieClip" (`movieclip_library_state_values`).
  - So Flash and Ruffle agree: `typeof h.a` right after `h.unloadMovie()` is `movieclip`, and it is gone on the next
    tick. The s26 docstring's premise ("synchronous for a non-root clip") misread the `is_root` arm.

  **Corrected golden for the held fixture as written:** line 7 `b:undefined` → **`b:movieclip`**. The trailing `c2` is
  the delivery-tick artifact; use the rewrite.
- **`avm1_loaded_bare_goto` / `_shell_consumers`.** Every disputed line is delivery tick or intra-tick order, and no Flash
  oracle exists for either. Neither golden can be "corrected" to Flash from source. **Replace them with
  delivery-insensitive rewrites:**
  - `avm1_loaded_bare_goto_seq`: per-movie logs on `_root`, traced once on frame 10. The golden is
    `P:1,…,10,` / `h:c1,c2,c3,c2, cf:2` / `g:d1,d2, cf:2` / `k:e1, cf:1`. The Ruffle runner's trace yields the same
    per-movie sequences.
  - `avm1_loaded_shell_consumers_seq`: the child's enterFrame bumps a counter, and the parent traces the per-tick delta
    from t3. The golden is `d:1` per tick, plus the s26 `in:`/`ev:`/`sl:`/`sp:`/`tp:` rows, which the runner did not
    dispute.

  Both pass on master and with the patch, in both modes. They are oracle-gated landings, not discriminators of the
  patch. The rows they lock are s26's.

**Deferred unload prototype.**
- `actionClearChildMovieShell` (phase 5's four call sites, unchanged) now QUEUES the holder, deduplicated, with a
  64-slot cap that falls back to the synchronous clear.
- `actionProcessDeferredFailedLoads` drains the queue. Both tick loops already call it at end of tick, BEFORE
  `actionFirePendingDirectLoads`, so unload + reload in one script still clears first. A liveness check against
  `child_mc_cache` runs before the clear.
- The playhead unregister stays synchronous, so the movie runs no further frame.
- `avm1_loaded_unload_deferred` (golden `a:movieclip` / `b:movieclip g:movieclip` / `t4..t6 h:undefined g:movieclip`):
  fail (`b:undefined`) → pass, both modes. `unloadmovie*`, `load_cancel_*`, `movieclip_state_values` and
  `mcl_unloadclip` are identical (gate).

## 3. Loaded-shell remainder, priced

**Corpus exposure.** I tag-scanned every non-`test.swf` SWF in the 112 loaded-child rows (sprites recursed) for
DefineButton/2, DefineEditText, FrameLabel, ActionGoToLabel and ActionGotoFrame2:
- BTN: `avm1/globals_monkeypatch` (`assets.swf`, failing 49/306 on another mechanism) and
  `movieclip_invalid_get_bounds_6/7` (pass, trace-only, no input).
- EDIT: gnash `MovieClip-v5` and `MovieClipLoader-v5..v8` (`Dejagnu.swf`, the harness's own text field).
- LABEL: only `regression/avm1_parent_child_sprite_meta`, and that is a sprite label, not a root label.
- GoToLabel / GotoFrame2 in a child: **none**.

So every remainder item is **0 corpus rows**. Each item, with its completion mechanism:
- **Buttons/hit-test over shells (S–M).** Walk `collect_attached_standalone`'s shell pairs in
  `ng_update_button_states_attached` and `hit_test.c`'s attached pass (the s26 plan). It needs a fixture with mouse
  input (`input.json`), which only the Ruffle **test runner** serves, not the exporter.
- **Text-field depth windows (S).** `actionSetTextFieldDepthWindow` for a DefineEditText that a loaded movie placed. It
  needs a fixture: two overlapping fields in the child, the window order read via `getDepth`/`swapDepths`. Exporter
  oracle.
- **Label goto inside a loaded movie: repriced M (was "consult MovieEntry labels").** The child's root labels never
  reach the runtime. `verify_output.py` `generate_child_movie_file` (~line 2060) DELETES the child's
  `// Frame labels … frame_label_count = N;` block, and `MovieEntry` (`swf.h:525`) has no label field. The fix spans:
  - the generator (keep and rename the block instead);
  - a `MovieEntry` labels pair, plus its registration;
  - `findFrameByLabel` consulting it when `actionChildMovieBareGoto` would fire;
  - the browser bundle builder.
- **Parent-issued `holder.gotoAndStop` DoAction (S–M).**
  - Ruffle queues the target frame's script at the end of the action queue with the clip as its context. That is the
    same rule that produced the runner's `c3 p4 c2`.
  - The mechanism is a context-capturing pending entry (`PendingSpriteScript`-style: version, globals, list), drained
    after the current script, instead of `g_tag_skip_mode` suppression.
  - Fixture: `holder.gotoAndStop(2)` from a parent frame, with per-movie logs as in `_bare_goto_seq`.
- **`_x`/`_y` by name: measured, M.** `avm1_loaded_timeline_holder_xy` adds `tx:<t.x._x> rx:<_root.x._x>`; Flash/Ruffle
  logic gives 30 / 10.
  - With phase 3 it reads `tx:10 rx:10`. The getters in `actionGetMemberImpl` read
    `ng_findDisplayEntryByName(mc->name)` on the active (root) list.
  - I tried a guard that ignores a name hit when `mc->display_obj` is bound elsewhere (reverted, not in the patch).
    It gives `tx:10 rx:30`, `tx:10 rx:30`, `tx:30 rx:30`, `tx:30 rx:10`: the MovieClip objects themselves alias by name
    tick to tick.
  - The owner is **MovieClip identity keyed by NAME**: `findOrCreateMovieClip(name, parent)` plus the GetVariable root
    arm's `child_mc->display_obj = &display_list[child_depth]` rebind. The fix is to key a timeline child's MC by its
    display entry (or parent + depth), not by name, which is wide. Fixture-first: this one.

## 4. Refutations

1. **"The held fixtures' Feb runner may be stale against current Ruffle."** Refuted. All three mechanisms are identical
   at `0f49392ef` (Feb) and `1e604fa87`: `avm1_unload_movie`, exec-list prepend, and `replace_with_movie(..true..)`.
2. **"The runner is the arbiter."** It is not, for delivery and intra-tick order: shumway `moviecliploader`'s Flash
   golden contradicts Ruffle there. It *is* right, with Flash corroboration in Ruffle's own source comment, on the
   deferred unload.
3. **s26 `_unload_shell` docstring "synchronous for a non-root clip".** Refuted. A loaded movie is a root clip in Ruffle,
   so the deferred arm applies.
4. **s26 lead 1 for phase-1 shells via `_root.px` / `/px`.** Not reproduced: the shell rows pass on master. The hazard is
   real only through the GetVariable arm, which the accessor covers.
5. **Held README "the exporter never loads child SWFs".** Refuted: the local-fetch recipe exists and is in use.
6. **Label goto "S, consult MovieEntry labels".** Refuted pricing: there are no child labels to consult (M).

## 5. Wave-2 scope (if taken)

- Land `w1-per-movie-dl-phase3-prototype.patch` as is. Functions touched:
  - `action.c`: `ChildDLSwap`, `childDLSwapIn`, `childDLSwapOut`, `actionClearChildMovieShell` (now queues),
    **new** `actionClearChildMovieShellNow` and `actionDrainDeferredShellClears`, `actionProcessDeferredFailedLoads`,
    `actionAdvancePlayingLevels`, `actionFirePendingDirectLoads`, `actionFirePendingLoadInits`, `actionGetVariableImpl`,
    `actionGetMember`, `actionGetMemberImpl`, and `resolveSlashPathToMC` (now a wrapper over the new
    `resolveSlashPathToMCImpl`).
  - `tag.c`: **new** `ng_rootDLStashPush`, `ng_rootDLStashPop`, `ng_rootDisplayList`, `ng_rootDLEnter`,
    `ng_rootDLLeave`; and `ng_spriteDLRealloc`.

  The local N session may touch `tag.c`/`action.c`; none of these functions is in the N ladder's named set.
- Land these fixtures into `regression/` once the oracle confirms them:
  - `avm1_loaded_timeline_holder`;
  - `avm1_loaded_shell_root_lookup`;
  - `avm1_loaded_unload_deferred`;
  - `avm1_loaded_bare_goto_seq` and `avm1_loaded_shell_consumers_seq`, replacing the three held ones.

  Keep `_xy` out (HOLD).
- **Expected-flip ledger:** corpus none. New rows pass in both modes (if the oracle agrees). Must stay put: all 268
  gated rows, explicitly the cross_call pair.
- CI: `graphics/all` + `no-graphics/all`. This is shared runtime, not AVM2 emission.

## New unclaimed leads

1. **MovieClip identity keyed by name** (owner of the `_x`/`_y` item; §3). Any two same-named clips in different lists
   (root `x` and a loaded movie's `x`) share or swap one MovieClip. Fixture `avm1_loaded_timeline_holder_xy`. M.
2. **Direct-`loadMovie` delivery tick: no Flash oracle in the corpus.** We deliver in the issuing tick's end-of-tick
   drain, Ruffle on the next tick, and Flash (by analogy with the MCL golden) on the next tick after root's script. A
   Flash capture of a two-frame parent that `loadMovie`s a tracing child in frame 1 would settle whether our
   same-tick delivery is right. Do not move it on Ruffle's word (the shumway MCL row would regress if the pattern
   carries over).
3. **Other unload-state writes may also be synchronous.** For example `_currentframe`/`_totalframes`/`_url` reset on
   unload; Ruffle applies them one frame later via `transform_to_unloaded_state`. Extend `avm1_loaded_unload_deferred`
   with `b:` property rows. Unpriced.

## LOCAL ORACLE REQUESTS

Ruffle exporter `--trace-log` with the local-fetch navigator (no timers involved). For each fixture dir in
`w1-per-movie-dl-phase3-fixtures/`, copy every `*.swf` to `<dir>/armorgames.com/`, then run

    RUFFLE_LOCAL_FETCH_DIR=<dir> RUFFLE_MOVIE_URL=https://armorgames.com/test.swf \
      exporter test.swf out -s -f <N> --trace-log ruffle.txt

Replace or confirm `output.txt` with the trace.

1. `avm1_loaded_unload_deferred`, N=7. The key line is `b:movieclip g:movieclip` (the source says yes).
2. `avm1_loaded_bare_goto_seq`, N=12. Per-movie logs; predicted identical to the runner's sequences.
3. `avm1_loaded_shell_consumers_seq`, N=7. `d:1` per tick, and the `in:` order.
4. `avm1_loaded_timeline_holder`, N=6. Expect `c1 30` BEFORE `t2` in Ruffle as well (the holder precedes root in the
   exec list). If Ruffle shows `tf:` one lower on each row, the row is delivery-sensitive: drop `tf:` and keep `tt:`.
5. `avm1_loaded_shell_root_lookup`, N=6. Four `movieclip` rows. Row ORDER (h before th, or interleaved) is
   exec-list-dependent but the rows are identical, so order cannot fail it.
6. `avm1_loaded_timeline_holder_xy`, N=6. This confirms `tx:30 rx:10` for lead 1 (HOLD fixture, do not land).
7. *(optional, not blocking)* A Flash Player capture of lead 2's shape: parent frame 1 `loadMovie`s a child that traces
   `c1`, and parent frames 1–3 trace `p1..p3`.
