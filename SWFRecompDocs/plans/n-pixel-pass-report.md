# N: play-game re-check, frame-locked pixel pass, enterFrame off-by-one, episode 0 levels 1–4 (2026-11-22)

This one-task session follows `n-level-complete` (`n-level-complete-report.md` §7). It was launched by the s26 fan-out coordinator. Baseline: master `912672370`. Landed: `8301fd233` and `495dbde90` (a browser-build fix-up for `8301fd233`), plus the docs/fixture commit that carries this report.

**Summary**
- **Coordinator request (goal 5): N's "play game" click now works natively AND in the browser.** The native re-check found a real **heap-use-after-free** in the attached-clip pump. It crashed native N about 15 ticks after the episode menu opened, and the browser shares the code. Fixed in `8301fd233`.
- **Browser enterFrame off-by-one: pinned, fixed and verified on N.** The probe was red, then green. N's injected clip now reaches `startgame` at frame 28, like native and both Ruffles.
- **Frame-locked pixel pass.**
  - Native can't draw N's level: OFFSCREEN draws root-attached clips only. This is the w2-attached-holder-render slot, not this session's.
  - So the pass ran in the browser. Browser telemetry is byte-identical to the exporter: 1048 ND/NF lines, including phase frame numbers.
  - Pixels: 1,000–1,700 of 475,200 differ per shot, in three classes (§3). The one real lead is browser EditText drawn 2 px up-left in attached buffers.
- **Levels 1–4** (§4).
  - All four load and play: cloud city, all about thwumps, the box the box!, lockness.
  - Player telemetry is tick-exact with Ruffle across five exploratory attempts each.
  - Found two of ours:
    1. A **collector heap-use-after-free** that crashes native on N's retry reset when AS enumerates clips. ASan-pinned, not yet fixed.
    2. Attached clips that remove themselves on their last frame vanish **one tick late**. This is an exec-order lead, not fixed.
- Landed: `8301fd233`, `495dbde90`, `5d34a4a30` (Key fixture + n_drive knobs), and this report's commit.
- **Goal 4:** ours already matches Ruffle's `Key.isDown` protection. Landed as the lock `regression/avm1_key_isdown_protected`.

## 1. Goal 5: "play game" after `876e66704` (coordinator request)

| mode | result |
|---|---|
| native, `run_native.py n_click.swf --input input_click.json` | mdown t=42, mup t=44, `menuMC` cf=6 (episode select) at t=45, which is correct. **Then SIGSEGV** (rc=139) a few ticks later. Crash sites varied between runs: `o1heapFree` from `swfGcMaybeCollect`, and `resolveSlashPathToMC` from `script_60`. |
| native ASan | heap-use-after-free READ in `resolveSlashPathToMC` (action.c). Freed by `ng_attached_run_tree` (tag.c), `free(tmp)`; allocated by the same function's `calloc(2, sizeof(DisplayObject))`. |
| native ASan after the fix | 400 frames: click, then the probe's tick-60 menu calls. Clean; only LeakSanitizer reports remain. |
| browser (WASM build of `flasharchive/N_click`) | A real Playwright click (`N_CLICK_SETTLE=3.0 … n_click_probe.py flasharchive/N_click "click@690,142;wait@3"`) gives mdown t=22, mup t=25, cf=6 at t=27. |

The same build without input ran clean. Before `876e66704`, native never dispatched the click, so this path was unreachable natively.

**Root cause.** `ng_attached_run_tree` is the attached-clip timeline pump, shared by every build since s24.
- It advances a playing nested child of an attachMovie'd clip inside a temporary 2-entry display list, `tmp`.
- Inside that advance, `exec_sprite_frame` resolves the child's instance name **globally** (`actionFindMovieClipByName`) and binds that clip's `display_obj` to `&tmp[1]`. The natural-advance `_currentframe` sync in `advance_sprite_frames` also resolves globally.
- Only `self_mc` was repointed after `free(tmp)`. When another clip with the same name exists, three things go wrong:
  1. That clip keeps a dangling `display_obj`; the UAF.
  2. The child's frame scripts run as that clip.
  3. That clip's `_currentframe` ticks instead.
- N's episode-select menu has same-named clips under different parents.

**Fix (`tag.c`).**
- New `ng_mc_for_sprite_obj(obj)`: when the global name hit is bound to a different display object, it prefers a same-named clip already bound to this exact entry. The scan runs only on that mismatch.
- `exec_sprite_frame` and the `_currentframe` sync both use it.
- The pump pre-binds `self_mc->display_obj = &tmp[1]` for the advance. It repoints to `obj` after the copy-back, as before.
- With an unknown `self_mc`, the global hit is restored to `obj`, or to its previous `display_obj`.
- The first push (`8301fd233`) defined the helper inside the CI-only `#if NO_GRAPHICS || OFFSCREEN_RENDER` block, which broke emcc (implicit declaration). `495dbde90` moves it out, with no logic change, and was verified with a full browser build of N_drive.

**Fixture.** `regression/avm1_attached_clip_samename_child` (hand-built SWF, Ruffle exporter oracle).
- Setup: a timeline `_root.kid` with child `inner`, and an attached `h` whose 3-frame child is also `kid`.
- Red before the fix: `/kid f2` (h.kid's script ran as `_root.kid`); `kidcf=2,3,…` where Ruffle holds 1.
- Green after the fix in graphics and no-graphics.
- All 13 `regression/avm1_attach*` fixtures pass locally in graphics mode.

## 2. Browser enterFrame off-by-one (goal 2)

**Cause.** `swf.c` `tagMain` called `actionMarkDynamicMCsEnterFrameEligible()` after the root frame func only `#ifdef OFFSCREEN_RENDER`.
- The pre-DoAction `tagFlushPendingEnterFrame` already ran before root frame 1's DoAction created the clip.
- In the browser, nothing marked that clip eligible until the end of tick 2's dispatch.
- So its first `onEnterFrame` came one frame after the root's, a constant offset.

**Fix.** The mark now runs in every `swf.c` build. The OFFSCREEN statement order is unchanged.

**Probe.** `wasm_probes/enterframe_count_injected_clip`. A SWF6 one-frame root whose frame 1 creates a clip with `onEnterFrame` and sets `_root.onEnterFrame`; the expected trace is the Ruffle exporter's.
- Red before the fix: `EF: root 1 clip=0`.
- Green after.

**On N:** browser `ND startgame frame=28` (was 27). Every phase/shot frame now equals the exporter's: 185, 204, 486, 608, 765, …, 1775.

## 3. Frame-locked pixel pass (goal 1)

**Native vs exporter: telemetry identical, pixels not comparable.**
- `run_native.py n_drive.swf --frames 1800 --capture-ticks <shots±2>`: all NF/ND lines match the exporter exactly.
- But every native frame shows only text: no tiles, gold, ninja or HUD bar.
- OFFSCREEN's attached post-loop pass skips `mc->parent != &root_movieclip` (tag.c), and N attaches everything into `createEmptyMovieClip` buffers. This is known (`n-tile-color-hud-report.md` §2) and funded as cloud slot **w2-attached-holder-render** item 1. I did not touch it.

**Browser vs exporter (done instead).**
- Setup: `n_drive_compare.py ours`, now showing the canvas at 792×600 CSS px for 1:1 shots, against `exporter -f 1790` frames.
- Each shot is matched to the best exporter frame within the 30-frame freeze. The freeze keeps the game state static; frame animations still run.
- Telemetry is byte-identical, 1048 lines. Differing pixels (max channel delta > 24) per shot are 1,016–1,687 of 475,200.
- Every region falls into one of three classes:

| class | where | verdict |
|---|---|---|
| **EditText 2 px up-left** | HUD timer `85.449` (exactly dx=−2, dy=−2), level-name line (dy=−2), fps counter | **browser-only and ours.** Native draws the same fields **pixel-exact** with Ruffle (binarised glyph diff 0 at offset 0,0). A browser-side origin/gutter difference for EditTexts inside attached clips. Not fixed this session (§6). |
| thin-stroke hollow squares | N's square objects (e.g. at 576,216) | Our left/top 1-px stroke edges are half-coverage grey; Ruffle's are crisp. Sub-pixel stroke phase, the family of `vertex-quantization-not-aa` / `n-thin-strokes-no-min-width`. Cosmetic. |
| small AA noise | launchpad, ninja limbs, one-way platforms | sub-pixel AA, cosmetic |

The canvas sits at a 1-px horizontal offset in the page (best match ox=1); that is accounted for in the diff.

## 4. Episode 0 levels 1–4 (goal 3)

**Setup.** New `n_drive/build.sh` knobs: `START_LEVEL=k OBJHASH=true AUTOKILL=true FREEZE=""`.
- Script `400:-/300:R/300:L/200:RJ/200:LJ`: five attempts per level (stand, run right, run left, jump right, jump left), each force-killed at the end so N's retry flow starts the next.
- Oracle: `exporter -f 3400`. Ours: native graphics, `run_native.py --frames 3400`.

| level | loads | player telemetry (all attempts, `SWF_GC=0`) | default run | object hash |
|---|---|---|---|---|
| 1 cloud city | yes | identical | **SIGSEGV at attempt 1 start** | 2 ticks/spawn late (below) |
| 2 all about thwumps | yes | identical | same SIGSEGV | same |
| 3 the box, the box! | yes | identical | same SIGSEGV | same |
| 4 lockness | yes | identical | same SIGSEGV | same |

**Finding A: the collector frees a live clip's props (ours, real).**
- With the default collector (`SWF_GC` unset means real free), native crashes the tick after N's first retry reset (`App_ResetObjects`).
- ASan (`run_native.py --asan`, level 1, script `100:-/100:R`) reports a heap-use-after-free READ in `actionEnumerate2` (action.c), inside the probe's `for (b in _root[a])`.
  - Freed by `gcCollect` ← `swfGcMaybeCollect` ← `tagMain`.
  - Allocated by `allocDynamicProps` ← `actionCallMethod` (`createEmptyMovieClip`/`attachMovie`) ← N's `RagStick` ← `Ragdoll` constructors, during `AppLoadingObjects`.
- So after the reset, `_root` enumeration still yields the name of a ragdoll clip whose MovieClip is no longer in the collector's root set (`child_mc_cache`), and `_root[name]` resolves to it.
- N itself never for-ins clips, so players aren't hit. But it is a real dangling `dynamic_props` reachable from ordinary AS.
- `SWF_GC=0` removes the crash, and every attempt then matches Ruffle.
- A guessed minimal repro (create, store, remove, recreate same-named `_root` clips, enumerate; `SWF_GC_CADENCE=1`, ASan) does **not** trigger it. It does show our `for (a in _root)` order differs from Ruffle (ours `rag3..rag0 drv`, Ruffle `drv rag3..rag0`).
- Next: shrink from the N repro with `SWF_GC_VERBOSE=1` plus a trace of which name `_root[a]` resolves to.

**Finding B: attached clips that remove themselves on their last frame vanish one tick late (ours, cosmetic).**
- The `OBJHASH` + `CLIPDIFF=true` trace names them: N's spawn particles `spritebuffer1600.pfx0..3` (31/33 frames, attached at t=26).
- Ruffle: removed at t=56/58, never observed on their last frame. Ours: observed at cf=31/31 (33/33) at t=56/58, removed at t=57/59.
- Cause: Ruffle's AVM1 frame walks the exec list newest-first, and each clip queues its enterFrame and THEN its frame script, with `_root` last (`avm1/runtime.rs::run_frame`, `movie_clip.rs::run_frame_avm1`). So pfx's last-frame self-removal runs before root's `onEnterFrame` (N's `RunApp`).
- Ours runs `tagFlushPendingEnterFrame` (all enterFrames, root's included) before the drain of pump-queued sprite scripts. That holds both in the frame-func path (recompiler emits flush, then `actionDrainAllInPriorityOrder`) and in OFFSCREEN's stopped-root fallback (`swf.c`: flush, then `AQ_KIND_SCRIPT` drain).
- Effect in N: a particle lingers one frame.
- Not fixed: it reorders root `onEnterFrame` against child frame scripts for every movie (broad, CI-visible). It belongs with the exec-order work (memory `divergence-tracer-exec-order`).

**Limit of `OBJHASH`.** Its two-deep `_root` walk sees N's pooled GUI/effect clips (958 on every level), not the level objects (thwumps, drones). The exploratory scripts also never meet an enemy. So enemy behaviour is NOT yet compared. Next: hash N's object list (`r.objects` / `game.objUIDList`) and author routes that complete levels 1–4.

## 5. Goal 4: `Key.isDown` protection

`regression/avm1_key_isdown_protected` (MTASC SWF6; Ruffle exporter oracle):
- a plain `Key.isDown = f` is ignored;
- `isDown` and `getCode` are not enumerable;
- `delete Key.getCode` is false;
- after `ASSetPropFlags(Key,"isDown",0,7)` the assignment takes and can be restored;
- user props on `Key` work.

**Ours already passes.** It is landed as a lock, with no fix needed.

## 6. Leads / next blocker

0. **Collector UAF on N's retry reset (§4 A).** It's a native crash, the highest priority. ASan recipe in §4.
1. **Browser EditText origin in attached clips (−2,−2 px).** Measured on N's HUD timer and level name. Native is exact.
   - Both `TextFieldGlyphInfo` builders (action.c, the MC-backed path and `otf_walk_dl`) add `bounds_xmin/ymin` once. The difference must be in the field origin `info->x/y` that the browser computes for an EditText whose MovieClip lives under an attached clip.
   - A first synthetic probe (one-glyph DefineFont2 with layout, DefineEditText in an exported sprite, attached to `_root` and into a buffer) drew **no text at all** in our browser. Ruffle drew it at x=20, y=22/82. That is itself a lead (probably a font field our path requires), so I kept the probe out of the tree; generator in the session scratchpad, not landed.
   - Next: instrument `info->x/y/bounds` for N's `timeIndicator` field, browser vs native.
2. Native attached-buffer rendering: w2-attached-holder-render. After it lands, rerun the native pixel pass (`n_drive/native_px` recipe below) for a true native-vs-exporter 1:1.
3. Thin-stroke edge phase on N's squares (cosmetic).

## 7. Tooling

- `n_drive/NDrive.as` + `build.sh`: `START_LEVEL`, `OBJHASH`, `FREEZE` env knobs (README). Trap: N is SWF6, case-insensitive, so `objHash` and `OBJHASH` are ONE property.
- `n_click_probe.py`: `N_CLICK_SETTLE` (seconds before actions). Use 3.0 to click before `n_click.swf`'s tick-60 direct calls.
- `n_drive_compare.py`: `NDRIVE_STAGE_PX=1` (default) shows the canvas at stage size for 1:1 diffs.
- Native pixel recipe: `SWFRECOMP_COMPILE_TIMEOUT=2400 flock /tmp/swfrecomp-cpu.lock python3 ../dj_probe/run_native.py n_drive.swf native_px --frames 1800 --capture-ticks <list>`. Exporter: `exporter -s -f 1790 n_drive.swf <dir>`. Exporter frame k (0-based file `kkkk.png`) ≈ native `F(k+1)`.

## 8. CI / Pages

- `8301fd233` and `495dbde90` are CI-observable; handed to the s26 coordinator for its grading run. No own dispatch.
- Pages: the coordinator sequences the real deploy at s26 closeout, after its grading run, so it carries its own patches too. I did not deploy.

## 9. Next slice's line

0. Collector heap-use-after-free on N's retry reset (§4 A): minimize from the ASan N repro, fix, and lock in `regression/`.
1. Browser EditText −2,−2 in attached clips (§6.1).
2. After w2-attached-holder-render: the native 1:1 pixel pass.
3. The exec-order lead (§4 B).
4. Episode 0 levels 1–4 with routes that complete them (author on the exporter with `author.py` + `START_LEVEL`), so thwumps and drones interact with the player.
