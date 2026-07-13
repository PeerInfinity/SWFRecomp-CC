# Session prompt — AVM2 Stage 12 (Seedling), session 3: first validated frame + drive past Splash into Game

You are continuing **Stage 12** (Seedling bring-up) of the AVM2 Seedling plan
(`SWFRecompDocs/plans/avm2-seedling-plan.md` §2). Session 2 (2026-07-13) fixed the
embedded-image decode gap ("Invalid source image") and added 4 flash.* classes,
so **the recompiled Seedling now runs 30 frames headless with ZERO uncaught
errors in BOTH build modes — reaching the FlashPunk `Engine` game loop + the
`Splash` world.** CI: avm2 827/1204 (68.7%), both modes, zero pass→fail. The game
is NOT yet first-playable, and no frame has been *visually validated* yet.

## Read first
- Memory `avm2-stage12-seedling` — full session-1+2 writeup: how to recompile +
  build + drive Seedling headless, the `GAME_SWF_URL` portal auto-start lever, the
  divergence chain fixed, the gotchas. **Start here.**
- `ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md` — the "State
  (Stage 12 — session 2)" section (divergence log + known gaps + next-session list).
- Memories `avm2-stage9-render` (the Bitmap-blit render walk — it reads `bd->pixels`
  CPU-side before the GPU blit), `avm2-stage8-input` (input.json harness),
  `avm2-stage10-audio` (Sound/Timer), `avm2-stage11-gc` (rooting rules for any new
  alloc). Memory `avm2-no-browser-wasm-path` (the Ruffle exporter gives AVM2 oracle
  frames for free — verified).
- **The game's own AS3 source is at `~/CC/seedling/src/`** (Preloader.as, Main.as,
  Game.as, Splash.as, net/flashpunk/*). Read the relevant class before guessing.
- NOT this session: `SWFRecompDocs/plans/avm2-seedling-ap-integration.md` +
  `avm2-stage13-browser.md` are the *downstream* endgame (Archipelago + browser
  demo). Leave them for later; keep them out of scope.

## Where the game is (the two fronts)
1. **No frame has been visually validated.** In graphics mode the render path
   *executes* (no crash) but the PNG capture hits a WSL2 lavapipe OOM
   (`VK_ERROR_OUT_OF_DEVICE_MEMORY` → `render_webgpu_save_png: buffer map failed
   (status 4)`). Root: the AVM2 render creates a **481×481×64-layer** RGBA
   bitmap-texture array (`MAX_DYNAMIC_BITMAPS=64`, render_webgpu.c:1137) + MSAA +
   offscreen under lavapipe's WSL2 memory ceiling. The readback buffer itself is
   tiny (~245 KB) and allocated once — this is a one-shot allocation ceiling, not
   a per-frame leak.
2. **The game stops at the 150-tick Splash.** It reaches `Engine`→`Splash` and
   loops cleanly, but nothing drives it past the splash timer into `Game`.

## Goal (this session)

### Primary A — a first VALIDATED Seedling frame (divergence-harness for render)
Get a real rendered frame and compare it to Ruffle. **The oracle is free:**
`~/CC/ruffle/target/release/exporter --frames N <swf> <outdir>` renders AVM2
Seedling correctly (verified). Two routes for OUR side — **strongly prefer the
first**:
- **(recommended) CPU-composite dump, bypassing the GPU/lavapipe entirely.**
  `avm2_render_frame` (avm2_display.c ~6998) already walks the render list
  computing each Bitmap's world matrix + concatenated alpha and reads its
  `bd->pixels` (premultiplied ARGB) — today it hands them to
  `renderer_draw_bitmap_quad_scaled` (GPU). Add a debug sink (env-gated, e.g.
  `AVM2_CPU_DUMP=<path>`) that instead blits those same `bd->pixels` into a CPU
  framebuffer (reuse the Stage-9 `copy_on_cpu`/`blend_over` from avm2_bitmap.c)
  and writes a PPM/PNG. This validates render *correctness* (does the game produce
  the right pixels) with no GPU — the meaningful question for a bitmap-based
  FlashPunk game. Works headless in no-graphics builds too.
- (alternative) Fix the GPU capture OOM: shrink the bitmap-texture array for the
  AVM2 path (`MAX_DYNAMIC_BITMAPS` and/or `dynamic_bitmap_max` — Seedling's
  on-stage bitmaps are ≤480²; 64 layers may be far more than a frame uses).
  **render_webgpu.c is shared with AVM1** — gate any change so AVM1 is untouched
  (e.g. an AVM2-only cap, or key it on `bitmap_count==0`). Higher risk; the CPU
  dump is cleaner for validation.

Caveats for the comparison:
- **Render is Bitmap-blit only** (Stage 9 — no shapes/gradients/text/masks). The
  NG **preloader** draws a progress bar (`graphics.drawRect`) + a TextField, so it
  will NOT render correctly. The **Splash** (NG-logo Bitmaps added via
  `FP.engine.addChild`) IS the first cleanly-renderable state. Target the Splash,
  not the preloader.
- **State-matching:** our headless run uses the `GAME_SWF_URL` portal lever to
  auto-start into Splash; Ruffle on `file://` shows the *preloader* (PLAY button).
  The exporter has no `--base-url` and `--force-play` won't skip Seedling's AS3
  `MOUSE_UP` gate. To diff matched states you must get Ruffle to the Splash too —
  options: patch the exporter's base URL, drive an input, or (simplest) compare a
  later tick where both are in a comparable state. Solve this deliberately; don't
  diff mismatched states.

### Primary B — drive past the Splash into `Game` (continue the bring-up)
Splash runs a 150-tick timer then switches `FP.world = new Game()`. Headless
wall-clock is instant, so bump `num_frames` to ~250 and run the divergence harness
(`GAME_SWF_URL` portal path). Fix each new `AVM2 uncaught error:` divergence.
**Expected next divergences** (verify, don't assume): `flash.ui.Keyboard`
(`capsLock`/`numLock` + key-code constants — Input.as onKeyDown), Music/Sound
paths (Stage 10 exists — confirm), FlashPunk `Draw` line/shape calls
(LineScaleMode now present; the Graphics surface may need more), Game.as level
loading (the `[Embed]` .oel `ByteArrayAsset` level data — confirm it decodes).
**Back every fix with an upstream trace/regression test** where a family exists
(all_classes/describeType for constant classes; bitmap/text/event families
otherwise) — the game is the INTEGRATION check, never the oracle.

### Secondary — natural file:// play-button path (optional)
Reach `Main` without the portal lever by injecting a play-button `MOUSE_UP` click
through the Stage-8 `input.json` harness (`onPlayClick` → `startup()` →
`new Main()`). Confirms the real user path, and exercises the input bridge on a
real game.

## Safeguards (unchanged, carried from the whole plan)
1. The game is the INTEGRATION check, never the oracle — reproduce/back every fix
   with a trace or regression test; no "looks right in Seedling" merges.
2. Divergence-harness first: fix headless-reproducible divergences before
   browser-only paths.
3. GC: any new C-static `Avm2Object*` stash MUST be rooted the day it's added; any
   new `native_ext` type MUST set `native_ext_size` (+ a precise tracer for
   indirect edges). Bisect misbehaviour with `AVM2_GC=0`. (Avm2String* statics are
   NOT GC-tracked — no rooting needed, as with session 2's `g_mouse_cursor`.)

## Verification & workflow
Per-test local runs only (`verify_output.py --test=NAME [--mode=graphics] --diff`);
never run the full suite locally. Full suite via CI both modes (`avm2_gc=1` stress
gate), pipeline per `.claude/pipeline-handoff.md` (autonomous commit/push/CI
authorized). Conflict boundary: own `src/avm2/`, `SWFRecomp/src/abc/`,
`RecompiledABC/`, and (for the CPU-dump sink) the AVM2-only render block; **never
touch `action.c`**; gate any `render_webgpu.c` change so AVM1 is unaffected. Keep
the game out of the CI pass-rate metric (integration check, no trace oracle).

## Reproduce the game headless (scratch is wiped between sessions — redo the recompile)
```bash
SCRATCH=<your scratch dir>
# 1) Recompile Seedling (~9s; ulimit -v 8388608):
mkdir -p $SCRATCH/recomp && cd $SCRATCH/recomp
cp /home/robert/CC/newgrounds/598977_Seedling.swf test.swf
cp ~/CC/SWFRecomp-CC/ruffle-tests/_shared/config.toml .
ulimit -v 8388608; ~/CC/SWFRecomp-CC/SWFRecomp/build/SWFRecomp config.toml
# 2) Scratch test dir: test.swf + Recompiled* + a test.toml (num_frames=250 +
#    a dummy [image_comparisons.seed]) + dummy output.txt.
# 3) Drive headless (portal auto-start). GAME_SWF_URL is an env override added to
#    verify_output.py in session 2:
export GAME_SWF_URL="http://games.armorgames.com/seedling/test.swf"
cd ~/CC/SWFRecomp-CC
python3 ruffle-tests/verify_output.py --test=seedling --tests-dir=$SCRATCH/tests \
    --mode=no-graphics --verbose 2>&1 | grep "uncaught"   # the divergence signal
```
verify's pass/fail is meaningless for the game (no trace oracle) — read the
binary's STDERR for `AVM2 uncaught error:`. The build is ~2–8 min (ccache helps);
run it as a background Bash task (the foreground tool caps at 2 min).

## End-of-session bookkeeping
Update the `avm2-stage12-seedling` memory + `CURRENT_STATUS.md` + plan §2 with the
new divergence baseline (first validated frame? how far past Splash? new gaps).
Run the CI pipeline (both modes) and report regressions by name. If Seedling
reaches first-playable, note it and the pivot to the AP-injected endgame
(`avm2-seedling-ap-integration.md`: adopt `games/seedling.json` + the `__swfBridge`
contract; source-mod + an AVM2 `Rando` builtin is the recommended first AP path).
```
