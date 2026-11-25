# s27 browser-parked-frame: wasm-ld guard, a CI swapDepths bug, the parked root no longer re-runs its frame, and instant clicks

**Slot:** local one-task session (brief: `browser-parked-frame-prompt.md`). **Predecessor:**
`browser-advance-order-report.md` (code `eaa3e70f7` + `088d60351`).

**Landed (three commits, in this order):**
1. `c8ed0e679` **build: wasm-ld guard.** Every browser/Pages link fails on any wasm-ld warning (§1).
2. `8350ca120` **runtime (CI-visible): swapDepths from a sprite script is no longer undone.** This is the root display-list grow
   rebase. The parked-frame fixture found it (§3).
3. the browser-only commit after `8350ca120` (this report lands with it) **runtime (browser only):**
   - A parked root no longer re-runs its frame. The root frame func runs on `is_playing || manual_next_frame || the playhead
     ENTERED a frame not yet run`.
   - tagRemoveObject / tagRemoveObject2 take the CI arms (the `pending_remove` deferral is gone).
   - A press and release inside one tick now click a DefineButton (Pacman PLAY GAME, goal 3) (§2, §4).
   - CI preprocess is unchanged in all three CI define sets. swf.c's OFFSCREEN text differs only in line layout:
     whitespace-normalised md5 `0041d8d5` on both sides.

Fixture: `regression/avm1_browser_parked_frame` (golden = Flash 32 projector, direct mode).

## 1. Goal 1: the wasm-ld guard (`c8ed0e679`)

`-Wl,--fatal-warnings` (opt-out `SWF_WASM_LD_WARN_OK=1`) is now on every browser link recipe:

| Script | Who runs it | wasm-ld warnings before | Notes |
|---|---|---|---|
| `SWFRecomp/scripts/build_test.sh` `wasm` (graphics + no-graphics) | docs2 demos, CI `wasm` smoke job | 0 (`graphics/clip_actions`, `graphics/awful_shape_swf_4`, `trace_swf_4`) | |
| `SWFRecomp/wasm_wrappers/bundle/build.sh` | Pages `bundle_smoke.sh` + the downloadable bundle | 0 (AVM1 `avm1_browser_eager_init`, AVM2 `avm2/array_concat`) | |
| `SWFRecomp/scripts/build_graphics_host.sh` (both hosts) | `deploy_wasm_demo.sh` (Pages) | 0 | the only warning is emcc's `-Wexperimental` (JSPI); `-Wl,` does not touch it |
| `SWFRecomp/scripts/build_wasm_avm2.sh` | AVM2 game demos | 0 | **was broken at HEAD**: it never staged s27's `avm1_filter_kernels.c` (+ `avm2_bitmap_kernels.inc`) → `undefined symbol: avm1_filter_kernels_apply`. Fixed in the same commit |
| `build_wasm_runtime_lib.sh` | — | n/a | archive only (WASI `llvm-ar`), no link step |

**Negative proof:** the bundle with `eaa3e70f7` reverted (a scratch copy of the snapshot) now fails with
`wasm-ld: error: function signature mismatch: ng_rootDLLeave`. Before, it linked a trapping stub and the Pages dry run stayed green.
The guard does not see a DYNAMIC_HOST guest that is linked in the browser at run time (those resolve against the host's exports by
name).

## 2. Goal 2: the parked frame and the browser RemoveObject arm (browser only)

### 2.1 The fixture

`avm1_browser_parked_frame`: root f1 places `a` (depth 1, x=10) and `b` (depth 2). Root f2 removes `b`, places `c` (depth 3,
`onClipEvent(load)`) and a ticker sprite `t`, then `stop()`s. While the root is parked, the ticker runs one step per tick:
- `t1`: `a._x=50`, `c.swapDepths(100)`, `createEmptyMovieClip("e", -16382)` (the depth `b` vacated).
- `t2`: `a.swapDepths(200)`, `c.removeMovieClip()`.
- `t3`, `t4`: report.

Each row reports what sits at timeline depths 1–3, plus `a`/`b`/`c`/`e`.

```
Flash 32 (golden) = native after this slice (both CI modes) = browser after this slice
root f1 d1=movieclip d2=movieclip d3=undefined a=movieclip ax=10 b=movieclip c=undefined e=undefined
c load
t1 d1=movieclip d2=undefined d3=movieclip a=movieclip ax=10 b=undefined c=movieclip e=undefined
root f2 d1=movieclip d2=movieclip d3=undefined a=movieclip ax=50 b=undefined c=movieclip e=movieclip
t2 d1=movieclip d2=movieclip d3=undefined a=movieclip ax=50 b=undefined c=movieclip e=movieclip
t3 d1=undefined d2=movieclip d3=undefined a=movieclip ax=50 b=undefined c=undefined e=movieclip
t4 d1=undefined d2=movieclip d3=undefined a=movieclip ax=50 b=undefined c=undefined e=movieclip
```

Browser before (HEAD swf.c/tag.c, CI fix of §3 already in):
```
t1 d1=movieclip d2=movieclip ... b=movieclip ...            <- RemoveObject deferred (pending_remove)
t2 ... d3=movieclip ...                                     <- parked re-run re-placed `c` at depth 3
c load                                                      <- ...with a second onClipEvent(load)
t3 d1=undefined d2=movieclip d3=movieclip ... c=movieclip   <- the re-placed `c` survives removeMovieClip
```

### 2.2 The change (CI preprocess unchanged)

- **swf.c: the root frame func is gated in every build.** OFFSCREEN: `is_playing || manual_next_frame`, unchanged. Browser: the
  same, **or the playhead has entered a frame whose func has not run yet** (`s_browser_last_ran_frame`). That third term exists
  because several browser goto arms only move `current_frame` and relied on the per-tick re-run to execute the target. A sprite
  script's `_root.gotoAndStop(n)` on a stopped root is one: Pacman's preloader → menu. With the plain CI gate, Pacman stuck on
  "LOADING..." with `current_frame` already 1. OFFSCREEN runs those gotos through its inline catch-up, which the browser arms
  lack. When the browser is parked, it runs the frame func's per-tick tail instead: `tagFlushPendingEnterFrame`,
  `actionDrainAllInPriorityOrder`, `tagShowFrame` (Phase-2 init, attached pump, button states, render). The browser needs that
  tail every tick to keep drawing. The frame's tags and its root DoAction ran when the playhead entered the frame.
  `g_suppress_root_doaction` stays for a PLAYING root that re-enters its own frame (a 1-frame root looping onto itself).
- **tag.c: tagRemoveObject / tagRemoveObject2 are the CI functions in every build** (9 `NO_GRAPHICS || OFFSCREEN_RENDER` gates
  removed; the browser `#else` arms dropped). The `pending_remove` deferral existed only so the per-tick re-run's Remove+Place
  pairs could reclaim their MCs (Doodle Jump's `container`). With no re-run it only made removals one tick late, so a same-tick
  sprite script still saw the removed clip (row `t1`). The CI arms bring the catch-up protections, the onUnload/finalize split and
  `actionInvalidateMCAtASDepth` for a swapped clone.
- `ng_spriteDLRealloc` now rebases `g_root_dl_backup` / `g_rootdl_stash` in every build. Both have been compiled in every build
  since browser-eager-init.
- Left in place (now dead in the browser, harmless): the `pending_remove` consume blocks in tagPlaceObject2 /
  tagPlaceObject2Ratio, `finalize_pending_removes_recursive`, and the tag_stubs.c walk. Nothing sets the flag any more. Deleting
  them is a pure browser-arm cleanup for a later slice.

### 2.3 Browser rows (`tools/browser-test/child_probe/`, after = this slice)

| Row | Browser before | Browser after |
|---|---|---|
| regression `avm1_browser_parked_frame` | **9 diff lines** (§2.1) | **matches** |
| regression `avm1_attached_clip_goto_play` | match | match |
| regression `avm1_goto_backward_enterframe_once`, `avm1_timer_root_goto_stopped_{gs,nf}`, `avm1_root_identity_and_playhead` | diverge from native | **browser trace identical to before** on the common prefix (pre-existing, §5) |
| Pacman (`demo.html`) | preloader → menu; instant click ignored | preloader → menu; instant click → game (§4) |
| regression `avm1_browser_eager_init`, `avm1_browser_gated_{textfield,depth,color}`, `avm1_parent_child_render` | match | match |
| avm1 `transform`, `duplicate_movie_clip`, `color`, `movieclip_create_text_field` | match | match |
| avm1 `movieclip_getbounds` | the 6 known `[approximations]` value lines (72.45/469.55/521.85 ×2 + the negatives) | the same lines. They are byte-identical to native (browser-advance-order §3.2) |

**N (seeded browser builds `EMCC_CFLAGS=-DMOCK_DATE_TIME=981152406000`, `routes_ep0.txt`,
`START_LEVEL=<n> AUTOKILL=true OBJHASH=true FREEZE=""`, vs the Ruffle exporter `-f 1800`).** N's whole game runs on a stopped
root, so the parked tail IS N's frame loop.

| Level | NF ticks | ND (phase / `frame=`) |
|---|---|---|
| L2 thwumps | **1266/1266 identical** | **28/28 identical**, including every `frame=` |
| L4 lockness | run 1: 902/902 identical (cut short); run 2 (CPU loaded by the CI sweeps): 953/984, with 31 `h=`-only diffs at t=29…430 | run 1: 20/20 identical; run 2: `frame=` +1 after the death |
| L4, final build (with the entered-frame term) | **984/984 identical** | **23/23 identical** |
| L2, final build | **1266/1266 identical** | **28/28 identical** |

L4 run 2 differs in the object hash only: clip count ±1–2 for 1–2 ticks at a time, player fields and `o=` identical, and every
`frame=` one less after the death. That is the signature of FRAMELOCK's 1.5-tick wall-clock slack: under load one player frame
runs two game ticks, so frame-based particle clips shift against game ticks. Run 1 of the same build had zero diffs over the same
span, and browser-advance-order saw the same one-tick L4 `h=` flake on HEAD.

## 3. A CI-visible bug the fixture found: swapDepths from a sprite script was undone

In **both CI modes** the fixture failed from `root f2` on. `c.swapDepths(100)` called from the ticker sprite's frame script was
reverted when the script returned. A later `getInstanceAtDepth(-16381)` then wrote `c.depth = -16381` back
(action.c, `getInstanceAtDepth`'s display-list arm), and `c.removeMovieClip()` was a no-op (negative depth).

**Cause** (gdb watchpoints on `display_list` and `mc->depth`):
1. `ng_updateDisplayDepth` grows the root list for any AS depth ≥ 0 (SWF depth ≥ 16384 > the 1024 capacity). It used a raw
   `calloc` + `memcpy` and rebased nothing.
2. A sprite DoAction runs inside `ng_bumpSpriteInitDepth`, which saved `g_root_dl_backup` / `max_depth`. On return,
   `ng_unbumpSpriteInitDepth` restored the **pre-grow** buffer (leaked, still holding `c` at depth 3) and the pre-move `max_depth`.

From a root frame script (no bump) the move stuck. That is why the existing swapDepths rows passed.

**Fix** (`tag_stubs.c ng_updateDisplayDepth`, `tag.c`):
- Grow through `ng_spriteDLRealloc`'s aliased-pointer rebase, via a new `ng_displayListGrowKeepOld` that rebases every tracked
  holder (`g_root_dl_backup`, MC `display_obj`, queue payloads, the root sentinel's base) but **does not free** the old buffer.
  About 40 C-stack `saved` copies of `display_list` are restored after script calls. Freed, they would be use-after-free; leaked,
  they read the stale list, which is the pre-existing behaviour on those paths.
- Below `AVM_CLONE_SLOT_CAP` only. Above it (AS depth ≥ 16384, up to 2130690044) the custom heap would exit on a multi-GB request,
  so the old raw `calloc` (which just fails) is kept. This was caught by the sweep: `avm1/movieclip_depth_methods`
  `swapDepths(2130690044)` became a `runtime_error` before the cap.
- `MovieClip.display_obj` pointers follow the moved or swapped entry. Before, they pointed into the leaked pre-grow copy, which
  was right by accident for the mover and wrong for in-capacity moves.
- `ng_rootDLBackupNoteMax`: a move on the backed-up list updates `g_root_dl_max_backup`.
- The root sentinel is re-synced after the grow (its base was rebased but not its `sprite_max_depth`).
- `ng_updateDisplayDepth` takes `app_context` (3 call sites in action.c's swapDepths handler; `tag.h`).

**Reach:** the new code runs only from `ng_updateDisplayDepth`, whose only callers are the swapDepths handler's 3 sites. Every
other path is byte-identical, including `ng_spriteDLRealloc`'s free path. So the reach set is every corpus row whose SWF contains
`swapDepths` (case-insensitive, CWS inflated, all suites): **24 rows** (avm1 6, from_gnash 14, regression 4). The coordinator
accepted that scope; its final grading pair is the wide net.

**Sweep: actual output, HEAD worktree vs this tree, both modes** (the `--diff` text per row, not just the verdict):
- no-graphics: 23/24 byte-identical; `avm1_browser_parked_frame` fail → pass.
- graphics: 23/24 byte-identical; `avm1_browser_parked_frame` fail → pass.
- The exact commit state (HEAD + only the commit's hunks, in its own worktree): the fixture and `movieclip_depth_methods` pass in
  both modes.
- Already failing before and after, with unchanged output: `displaylist_depths_test{,2,3}`, `key_event_test`, `masks_test`.

**ASan** (`--asan`, both modes): the fixture, `movieclip_depth_methods`, `rewind_depth`, `removed_clip_function_scope`,
`remove_movie_clip`, `movieclip_destruction_test2`, `static_vs_dynamic2`, `loop_test3`, `displaylist_depths_test`,
`displaylist_depths_test7`, with `ASAN_OPTIONS=detect_leaks=0`: **zero ASan errors in 20 runs.**
- Verdicts match the plain runs (`displaylist_depths_test` was already failing).
- `movieclip_depth_methods` exits 1 under ASan **on HEAD too**: ASan aborts the ~920 GB `calloc` that a plain build fails
  softly. It passes 98/98 with `allocator_may_return_null=1`.
- Without `detect_leaks=0`, every ASan row ends `runtime_error` with "output matches". That is LeakSanitizer at exit, and the
  runtime leaks by design.

## 4. Goal 3: an instantaneous click on Pacman's PLAY GAME (fixed, browser only)

`ng_update_button_states` (DefineButton state machine, tag.c) is purely level-sampled: it reads
`mouse.button_down` when tagShowFrame runs. The browser's per-tick edge flags (`mouse.clicked` / `mouse.released`, set by
render_webgpu.c's DOM handlers) drive only the AS2 dispatch at the top of the tick, and swf.c clears them (~line 1024) **before**
the frame func / tagShowFrame. When a press and its release both land between two ticks, `button_down` is 0 at sample time.
The button never passes through state 2 (down), so `on(release)` never fires. The hover gate `_mouse_changed` also reads the
already-cleared edges. A 300 ms press spans ticks and works.

**Fix:** swf.c latches the tick's edges (`g_tick_mouse_clicked` / `_released`, `#ifndef OFFSCREEN_RENDER`) before clearing
them. tagShowFrame's button block (browser + native windowed) consumes them once. When `clicked && released && !button_down`, it
runs `ng_update_button_states` with `button_down` forced to 1 (the press), then the normal pass (the release). The latched edges
also feed the browser hover gate `_mouse_changed`.

**Measured** (`pacman_play_probe.py` variant: hover, wait, then `mouse.down(); mouse.up()` with no delay; root display list
before/after):

| Build | Root after the click |
|---|---|
| HEAD | stays `1:0` on the menu (button chid 30 present), 6 entries |
| this slice | root plays 1 → 2 → 3 → 4 (the game), **41 entries** (maze, "GET READY!"), the same as a held press |

A native fixture cannot show this: OFFSCREEN feeds events one at a time through `input_events_pump_tick`.

## 5. What is left (browser-only arms)

| Arm | Where | Completion mechanism |
|---|---|---|
| `advance_attached_clip_frames` in tagShowFrame | tag.c browser arm | An attachMovie'd clip's `gotoAndStop/Play` is deferred to a per-tick rebuild in the browser. CI applies it synchronously through `ng_gotoFrameByMC`. Port = route the browser's attached-clip goto through the CI goto path in action.c, then delete the deferred pass. Doodle Jump's `attachBlocks` loop (block.gotoAndStop inside a while loop) is the reentrancy case to re-check. Oracle: `regression/avm1_attached_clip_goto_play{,_nonroot}`, `avm1_attached_clip_selfgoto_child_parent` in child_probe, then DJ. M |
| `ng_apply_pending_sprite_self_gotos` | swf.c, OFFSCREEN-only call after the SCRIPT drain | Compiled in the browser (tag.c) and recorded there, but never applied, so a sprite's self `gotoAndPlay` takes the deferred one-tick-late path (period-6 instead of period-4 loop). Port = call it in the browser's post-frame-func block after the SCRIPT drain (the OFFSCREEN slot) and ungate its `catch_up_mode` guard. Oracle: a 5-frame self-loop sprite fixture in child_probe. S |
| dead `pending_remove` consume/finalize code | tag.c, tag_stubs.c | Delete (§2.2). S |
| Browser timer/stopped-root goto timing | `regression/avm1_timer_root_goto_stopped_{gs,nf}`, `avm1_goto_backward_enterframe_once`, `avm1_root_identity_and_playhead` in child_probe | These rows diverge from native in the browser **before and after this slice** (traces identical on the common prefix). In `_gs`, a timer's `gotoAndStop(3)` on a stopped root shows frame 3's script ~8 ticks late (the timer keeps firing in between). The rest is mostly the browser running past native's end. Completion: port OFFSCREEN's inline root-goto catch-up (`ng_executeGotoCatchUp` / `ng_runPendingRootGoto` from timer and event callbacks) to the browser loop. Once it lands, the entered-frame term of the gate (§2.2) can go. M |
| `graphics_stubs.c` Group 1 (`ng_queue_placement_clip_events`, `ng_queue_slot_unload_events`) | browser-eager-init §3.4 | still unmeasured |

## 6. Method notes

- The fixture was designed as a browser-only oracle and found a CI bug first. **Grade a new browser fixture natively in both
  modes before building it for the browser.**
- A worktree baseline for `verify_output.py` needs `SWFRecomp/build/SWFRecomp` symlinked in and `DAWN_INSTALL` set (it otherwise
  resolves `../dawn-install` next to the worktree, and every graphics row "fails" on the missing Dawn).
- `pkill -f` is hook-blocked here; record `$!` at launch and kill by PID.
