# Session prompt — AVM2 Stage 12 (Seedling), session 2: embedded-image assets → first render

You are continuing **Stage 12** (Seedling bring-up) of the AVM2 Seedling plan
(`SWFRecompDocs/plans/avm2-seedling-plan.md` §2). Session 1 (2026-07-13) proved
the foundation: the real `Seedling.swf` recompiles + links + runs in BOTH build
modes, and the entire **Newgrounds API v3.1.3 preloader** startup error chain is
cleared (LoaderInfo/Security/flash.net/flash.events-net/flash.display-constants;
avm2 819 → 825, zero regressions, both modes). The game is NOT yet first-playable.

## Read first
- Memory `avm2-stage12-seedling` — the full session-1 writeup: how to recompile +
  build + run the game headless, the exact path to `Main` (from the game's own
  source), the divergence chain fixed, and the gotchas. **Start here.**
- `ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md` — the "State
  (Stage 12)" section (divergence log + known gaps).
- Memories `seedling-avm2-readiness`, `avm2-stage9-render` (render path),
  `avm2-stage7-bitmapdata` (BitmapData + embedded assets), `avm2-stage8-input`
  (input.json harness), `avm2-stage11-gc` (GC rooting rules for any new alloc).
- **The game's own AS3 source is at `~/CC/seedling/src/`** (Preloader.as,
  Main.as, Game.as, net/flashpunk/*). Read the relevant class before guessing.

## Where the game is stuck (the next unlock)
The path to FlashPunk `Main` is mapped (Preloader.as): on `file://` the NG
preloader shows a play button and waits for a MOUSE_UP click; on a **portal URL**
(armorgames.com etc.) it auto-starts (`flashAd` null → `onEnterFrame` →
`startup()` → `getDefinitionByName("Main")` → `new Main()`). Driving it with a
portal `SWF_URL` (patch verify's `-DSWF_URL` via a `GAME_SWF_URL` env override in
a scratch copy — see the memory) auto-starts past the play-button gate and hits:

> **`Error: Invalid source image`** — thrown by the game's OWN FlashPunk code
> (`net.flashpunk.graphics.Image`/`Spritemap`) when built from a null/invalid
> `BitmapData`. This is an **embedded-image-asset decode gap**: the NG-logo /
> FlashAd PNGs and every `[Embed]` image in `Game.as` are not decoding to valid
> BitmapData. **This is the primary target of this session** — it blocks every
> render path.

## Goal (this session)
1. **Embedded-image assets.** Find why `[Embed]` PNG/image assets resolve to
   null/invalid BitmapData (Stage 7 decoded DefineBitsLossless2; `[Embed]` images
   may arrive as a different tag/class binding — DefineBitsJPEG2/3, or a
   SymbolClass-bound image class the recompiler/runtime doesn't wire to
   BitmapData). Fix it so a FlashPunk `Image` constructs. **Back every fix with an
   upstream trace/image test** (bitmapdata_* / embedded-asset families) — the game
   is the INTEGRATION check, never the oracle.
2. **Reach `Main` and render the first frame.** Once images decode, drive the game
   (portal-URL auto-start for headless, then the natural `file://` path via an
   injected play-button click through the Stage-8 input.json harness) until the
   FlashPunk `Engine`/`Splash` produces a first rendered frame. Compare to Ruffle
   (image diff) — divergence-harness-first.
3. **Graphics-mode capture bug** (if it blocks image comparison):
   `render_webgpu_save_png: buffer map failed (status 4)` / lavapipe
   `VK_ERROR_OUT_OF_DEVICE_MEMORY` under WSL2. Render-infra, separate from game
   logic; the headless no-graphics divergence work does not need it.

## Safeguards (unchanged, carried from the whole plan)
1. The game is the INTEGRATION check, never the oracle — reproduce every fix as
   (or back it with) a trace/regression test; no "looks right in Seedling" merges.
2. Divergence-harness first: fix headless-reproducible divergences before
   browser-only paths.
3. GC: any new C-static `Avm2Object*` stash MUST be rooted the day it's added;
   any new `native_ext` type MUST set `native_ext_size` (conservative scan) and,
   for indirect edges, a precise tracer. Bisect misbehaviour with `AVM2_GC=0`.

## Verification & workflow
Per-test local runs only (`verify_output.py --test=NAME [--mode=graphics] --diff`);
never run the full suite locally. Full suite via CI both modes (`avm2_gc=1` stress
gate), pipeline per `.claude/pipeline-handoff.md` (autonomous commit/push/CI
authorized). Conflict boundary: own `src/avm2/`, `SWFRecomp/src/abc/`,
`RecompiledABC/`; never touch `action.c`. Keep the game out of the CI pass-rate
metric (it's an integration check, no trace oracle).

## End-of-session bookkeeping
Update the `avm2-stage12-seedling` memory + `CURRENT_STATUS.md` + plan §2 with the
new divergence baseline (first-render status, gaps found). If Seedling reaches
first-playable, note the phase-2 completion and the pivot to the Archipelago-
injected variant + the AVM2 `Rando` builtin (`archipelago-rando-integration`).
