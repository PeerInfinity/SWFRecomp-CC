# s27 browser-eager-init: eager placement init in the browser frame loop

**Slot:** local one-task session (brief: `browser-eager-init-prompt.md`). **Predecessor:**
`browser-arms-land-report.md` §3 (code `91418ebbe`). **Verified on:** `ac5918f92` + this patch (clean worktree),
re-verified on `bdcc0d551` + this patch (§5).

**Landed (runtime, browser-WASM only, CI-invisible: §4):**
- `tag.c`: the frame-helper machinery is now compiled in every build. The three `NO_GRAPHICS || OFFSCREEN_RENDER`
  blocks are ungated: `g_current_sprite_obj` / sprite-init state, `exec_sprite_frame` +
  `process_sprite_needs_init` / `process_sprite_init_at_depth` + the eager/goto accessors, and
  `process_sprite_needs_init_public` / `ng_set_script_only_mode`. So is the INIT/CONSTRUCT/REGISTER_CTOR queue block
  (`queue_clip_init_events` … `queue_register_ctor`).
- `tag.c` `tagPlaceObject2` and `tagPlaceObject2Ratio…` tails: the browser arm is gone (inline auto-name,
  `sprite_initialized = 1`, `AQ_KIND_LOAD` LOAD queue). The browser now runs the CI tail: `ng_on_place_object2`,
  the INIT/CONSTRUCT/REGISTER_CTOR/LOAD queue, the MC pre-create and the frame-0 eager build under
  `catch_up_mode = 1`.
- `tag.c` `tagShowFrame` browser arm: the Phase-2 half the CI arm runs (INIT/CONSTRUCT/CTOR drains,
  `process_sprite_needs_init`, late SCRIPT drain, `ng_fire_pending_loads`, `actionFlushPendingOnLoads`), placed
  before `advance_sprite_frames`.
- `tag.c` `advance_sprite_frames`: a browser-only skip, active only in `tagShowFrame`'s per-tick call
  (`g_browser_tick_advance`). It skips sprites placed this tick (`placed_at_tick`) that eager init already built, as
  `advance_nested_sprite_frames` already does. Without it the browser would run a sprite's frame 2 on its placement
  tick, because the browser advances after placements and CI advances before the frame func.
- `graphics_stubs.c`: Group 2 (browser-only stubs of all the above, including a reduced `exec_sprite_frame` that
  carried the Doodle Jump and Minesweeper registerClass special cases) deleted. `swf.c`: the browser-only dummy
  `g_current_sprite_obj` deleted.
- `action.c` `actionCloneSprite`: the browser-only `AQ_KIND_LOAD` drain deleted. Placement LOAD now rides
  `AQ_KIND_SCRIPT` in every build. `AQ_KIND_LOAD` only holds duplicateMovieClip onLoads, and draining it at the next
  clone call fired an earlier clone's onLoad there (the `load:` order row).
- Fixture `regression/avm1_browser_eager_init`: hand-assembled SWF 8, Flash 32 golden (= Ruffle exporter). Oracles are
  under `w2-local-oracles/browser-eager-init/`.

## 1. Rows, real browser build (`tools/browser-test/child_probe/`)

Both columns are real browser builds from a clean worktree (`ac5918f92` before, the same + this patch after). The
comparison drops blank lines and the WebGPU console warning, and the logs were read whole, never through `tail`.
The native column is the passing golden.

| Row | Browser before | Browser after | Note |
|---|---|---|---|
| avm1/`movieclip_getbounds` | 196 diff lines: every clip query is the 6710886 sentinel | **20 lines**: a 1-twip residual only | §3.2 |
| avm1/`transform` | 14 lines (`clip.clip.transform` read the outer clip) | **matches** | |
| avm1/`duplicate_movie_clip` | 4 lines (`load:` order) | **matches** | AQ_KIND_LOAD drain gone |
| avm1/`color`, avm1/`movieclip_create_text_field` | matched (arms-land run_c) | **match** | |
| regression `avm1_browser_gated_{textfield,depth,color}` | matched (arms-land run_c) | **match** | |
| regression `avm1_browser_eager_init` (new) | 6 of 9 lines wrong | **tick 1 exact**; `root f2`/`root f3` playheads one tick stale | §3.1 |

Fixture, browser before → after:
```
before                         after                          Flash 32 (= Ruffle, = native both modes)
root f1 undefined 1 undefined  load movieclip 1               load movieclip 1
load movieclip 1               inner f1                       inner f1
outer f1 undefined undefined   outer f1 movieclip 1           outer f1 movieclip 1
root f2 1 1                    root f1 movieclip 1 1          root f1 movieclip 1 1
outer f2                       root f2 1 1                    outer f2
inner f1                       outer f2                       root f2 2 2
root f3 2 1                    root f3 2 2                    outer f3
outer f3                       outer f3                       root f3 3 2
root f4                        root f4                        root f4
```
Native passes the fixture in both CI modes (local `verify_output.py`, graphics and no-graphics).

## 2. Game smoke (WSLg Chrome = SwiftShader; function only, never perf)

| Game | Check | Result |
|---|---|---|
| **N** (`N_drive`, seeded `MOCK_DATE_TIME`) | `n_drive_compare.py ours`, level-4 route: switch t=453, enemy death t=508, retry, … | **984/984 NF ticks byte-identical** to the Ruffle exporter on the same SWF, including every `ND phase … frame=` number |
| Doodle Jump | menu: buttons whose `onClipEvent(load)` sets `button_txt.text` (the case the AQ_KIND_LOAD deferral existed for) | play/info/scores/options labels correct, hero bouncing, 0 console errors |
| Doodle Jump | gameplay after Play | **not measurable here**: the page stops answering JS/capture after Play on the clean-HEAD build too (the known WSL software-WebGPU saturation, memory `wsl2-board-screenshot-hang-rootcause`) |
| Pacman | title → PLAY GAME, `getDisplayListJSON` at 5 points | root display list **identical before/after**, 0 console errors |
| Minesweeper | start screen (registerClass FRadioButtons, which the deleted `exec_sprite_frame` stub special-cased) | radios with "Easy (40 mines)" / "Medium" / "Tough" labels, name field, Start; 0 console errors |

Tooling for these runs: `djprobe.py` (liveness plus `dbgCapturePNG` plus `getDisplayListJSON` per phase). It uses
the GPU readback because a DOM screenshot hangs in-game on this machine. It lives only in the session scratchpad and
isn't committed. Its pattern is in the memory update.

## 3. What is left

### 3.1 Browser per-tick advance order (next slice)
The browser still advances timeline sprites inside `tagShowFrame`, **after** the root DoAction. `swf.c` says so:
"Timeline sprites still advance later, inside tagShowFrame, in this build". So from the second tick on, a root frame
script reads its sprites' previous playheads, and their frame scripts run after the root's. Flash, Ruffle and CI run
them before. The fixture's `root f2 1 1` / `root f3 2 2` rows (Flash `2 2` / `3 2`) measure it, and the browser
showed the same before this patch. The browser hides it on tick 1 only, which is what this slice fixed.
**Completion mechanism:** run `advance_sprite_frames` (deferred-nested) before the root frame func in the browser
`swf.c` loop, as `OFFSCREEN_RENDER` does, with Phase 3 (`advance_nested_sprite_frames` + SCRIPT drain) after it, and
drop the `tagShowFrame` call and this patch's `g_browser_tick_advance` skip. The delicate part is the browser's
parked-frame re-run (`frame_funcs[current_frame]` every tick with `g_suppress_root_doaction`; memory
`browser_wasm_frame_func_rerun`), which keeps `tagShowFrame` as the render pump. **Price M.** Oracle: the fixture's
two rows, plus the N route (byte-identical now, so any drift is attributable).

### 3.2 `getBounds` 1-twip residual
20 lines: five values, each in `getBounds` and `getRect`. They appear only on cross-space queries whose target is the
parent or a sibling (`clip.clip.getBounds(clip)`, `…(clip2)`, `clip.getBounds('clip:clip')`). Self and `_root`
queries match. Every value is off by exactly one twip at the round-to-twip step (72.45 vs 72.5).
`getBounds` has no build gate (checked: no `#if` in its body), so the inputs differ. Candidates, none measured:
`MovieClip.xscale/rotation` synced differently at browser MC creation (the `as_set_flags & (4|8|16)` recompose arm),
or the transform row the walk reads. The open question is whether the browser's composed-transform slots ever reach
`ng_entryTransformData` for a script-time query. This is not a lazy-build symptom (before this patch every value was
the sentinel). **Price S–M**, oracle `movieclip_getbounds` in child_probe.

### 3.3 CI nested frame-script order (found by this fixture, CI-visible, not fixed)
With `inner` tracing on its frame 2, Flash and Ruffle print `inner f2, outer f2, root f2`. **Both CI modes print
`outer f2, root f2, inner f2`.** The nested child's script runs in the Phase-3 nested advance, after the root frame
func. The fixture leaves that trace out so it grades green. To reproduce, add `trace('inner f2')` back to `inner`'s
frame 2 in `create_test_swf.py`. This is a CI exec-order lead for the corpus side, not the browser. The child is
placed by its parent's frame 1 in the same tick; `execution_order4` deliberately advances a nested clip on the tick a
parent *script* placed it, so check that test before touching Phase 3.

### 3.4 Smaller leftovers
- `graphics_stubs.c` Group 1 still stubs `ng_queue_placement_clip_events` / `ng_queue_slot_unload_events` for the
  browser, so clones get no INIT/CONSTRUCT clip events there. No row measures it yet.
- `tagShowFrame`'s end-of-tick `AQ_KIND_LOAD` drain is kept. It now carries only duplicateMovieClip onLoads, and the
  new pre-advance `ng_fire_pending_loads` normally empties it first.

## 4. CI define sets (preprocess md5, `#include` lines stripped, blank lines dropped)

Clean worktree at `ac5918f92` → same + this patch:

| File | graphics | graphics + images | no-graphics | browser |
|---|---|---|---|---|
| `tag.c` | `ab3eeb7a` → same | `5373f2d8` → same | `f92c240e` → same | `db7f2738` → `ff7a6268` |
| `swf.c` | `8f8c1d4c` → same | `8f8c1d4c` → same | (empty) → same | `4092ac77` → `47ca8d07` |
| `action.c` | `bd042ffb` → same | `bd042ffb` → same | `58adde56` → same | `d5fdd499` → `5e4a3131` |
| `graphics_stubs.c` | `ec4161a8` → same | `ec4161a8` → same | (empty) → same | `8d2a1b76` → `7d0958bc` |

**CI-invisible in every CI define set.** Every removed gate is either true in all CI sets or browser-only. The only
CI-visible addition is the new fixture, which passes locally in both modes.

## 5. Re-verification on the newer base

The coordinator's wave (13 commits, about 1300 runtime lines, including `swf.cpp`) landed during the slice. I applied
the same patch to a clean worktree at `bdcc0d551`, rebuilt its recompiler, and re-ran:
- preprocess md5: graphics / images / no-graphics are unchanged for all 4 files (`tag.c` `22c988a1` / `61a0662d` /
  `9dbdeab9`, `swf.c` `7f32a7e7`, `action.c` `974320ae` / `54b35087`, `graphics_stubs.c` `ec4161a8`); only the
  browser set changes;
- child_probe: `movieclip_getbounds` shows the same 20-line residual, `transform` and `duplicate_movie_clip`
  **match**, and the fixture gives the same 9-line browser trace (tick 1 exact, the 2 stale-playhead rows).

The game smokes (§2) ran on the `ac5918f92` base only.

## 6. Why the native harness never saw this

`SWF_BROWSER_ARMS_TU=action.c` compiles only `action.c` with browser defines. `tag.c`, `swf.c` and
`graphics_stubs.c` stay CI-built, so the harness always ran CI's eager placement init and passed every row this
slice fixed. After this patch the eager-init machinery is the same code in both, so that part of the gap is closed.
What remains browser-only in `tag.c`/`swf.c` (§3.1's advance position, the `pending_remove` deferral, the parked
frame re-run) is still invisible to the harness. Confirm those in `child_probe` or with a game route.
