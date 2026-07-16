# Session prompt — RWK-2: FlxText rasterization + Robot Wants Kitty gameplay parity

You are running **RWK-2** of `SWFRecompDocs/plans/avm2-robot-wants-kitty.md`.
RWK-1 (2026-07-16) reached the TitleState menu with zero uncaught errors and
left exactly ONE render gap plus the gameplay pass. Read first: the plan's
status header, memory `avm2-rwk1-robotkitty-bringup` (divergence list, the
pacing gotcha, and the **reusable recipes** — recompile scratch layout,
`verify_output_keep.py`, oracle exporter command), and the avm2 suite
`CURRENT_STATUS.md` RWK section.

## Lever 1 — `BitmapData.draw(TextField)` rasterization (a TWO-game fix)

Root cause is confirmed (RWK-1 memory): `avm2_bitmap.c bd_draw` early-outs
(src==NULL) for any non-Bitmap DisplayObject source, so FlxText's
`_framePixels.draw(_tf)` silently produces zero pixels — every RWK button
label, credit line, and splash text is invisible. **The same path breaks
Seedling**: FlashPunk `Text.as:56` does `_source.draw(_field)` (verified in
`~/CC/seedling/src/net/flashpunk/graphics/Text.as`), so any FlashPunk text is
currently invisible there too. Fixing this closes render items in both games.

Implementation direction: rasterize a TextField source through the Stage-6
EditText layout engine + embedded DefineFont3 glyphs into the destination
pixels (respecting the draw matrix/colorTransform/clipRect surface bd_draw
already has). Scope to **TextField sources** — full arbitrary
DisplayObject-tree draw is NOT this session; if the layout engine already
renders EditText elsewhere, this is plumbing, not new rasterization.

Fonts involved:
- RWK: DefineFont3 "Nokia Cellphone FC" bound via `mx.core.FontAsset` subclass
  `FlxGame_junk` — check how [Embed] font registration reaches the TextField's
  fontName lookup (Font.registerFont / FontAsset path).
- Probe recipe (from RWK-1, NOT yet committed because it would land red):
  mxmlc test embedding `/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf`
  ([Embed] fontName, embedAsCFF=false), `bd.draw(tf)`, count nonzero
  getPixel32 — Ruffle=true, ours=false. **Land fix + this regression test
  together** (`ruffle-tests/tests/swfs/regression/`). Also sweep upstream avm2
  `bitmapdata_draw*` / edittext-draw-adjacent tests for any that flip.

Verification beyond tests: RWK menu state-aligned MAD should collapse (RWK-1
baseline: 5.53, 3.11% px, all rows ≥240 = exactly the text rows); run a
Seedling smoke (recompile + a few hundred frames + CPU dump) to confirm text
appears where FlashPunk draws it and nothing else moved. `bd_draw` is
recently-touched shared code (null-matrix/cxform fixes, blends —
`avm2-optional-arg-null-vs-undefined-trap` memory): run the local bitmapdata
test family before CI, and BOTH CI modes after.

## Lever 2 — gameplay parity (headless keyboard)

PlayState via the Stage-8 input harness (input.json): start a game from the
menu, then on level 1 — move, jump, shoot, collect the kitty. Grade by
state-aligned oracle comparison during gameplay (tilemap/sprites/particles)
plus a scripted input run that demonstrably reaches the kitty. FlxTilemap is
pure copyPixels and expected to ride the existing path — if it doesn't,
that's a real finding to fix + grade. FlxSave persistence stays out of scope
(RWK-4).

**Pacing gotcha (do not rediscover):** Ruffle's AVM2 `getTimer` is wall-clock,
so Flixel's variable timestep drifts frame indices vs our deterministic
33.3 ms tick — ALWAYS state-align via an offset scan before computing MAD;
index-aligned comparisons are meaningless for Flixel games.

## Exit criteria

1. FlxText renders: menu text present, state-aligned menu MAD ≈ pixel-level
   (remaining diffs explained), regression test green in BOTH modes.
2. Seedling smoke clean: text now renders via FlashPunk Text; no other pixel
   or trace change (CI zero pass→fail is the formal gate).
3. Level-1 gameplay headless: scripted input reaches/collects the kitty;
   gameplay-frame oracle comparison recorded with divergence list for RWK-3.
4. BOTH CI modes zero pass→fail; wasm-link-smoke green.

## Boundaries

Same as RWK-1: injected SWF is the target; flash-ap-api + Archipelago-CC
artifacts read-only; no commits outside SWFRecomp-CC; `action.c` untouched;
AVM2 work in `src/avm2/` + `SWFRecomp/src/abc/`; game is never the oracle —
every fix lands with an upstream or `regression/` grade.

Finish per `.claude/pipeline-handoff.md` (both CI modes — bd_draw is shared
graphics-relevant runtime); update the plan's stage status + CURRENT_STATUS.md;
write a session memory with the RWK-3 (browser demo) checklist.
