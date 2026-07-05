# 2026-07-05 — docs2 demo redeploy (July 2026 runtime improvements)

Executed per `SWFRecompDocs/prompts/demo-redeploy-2026-07.md`: rebuild + redeploy
the browser demos so the deployed WASM picks up the accumulated runtime work
(default-on GC `bac8b31e8`+`427f0abb1`, dispatch Stage-0 fixes `d8abc5c0a`/
`9a8c6dce3`/`60070d96a`, sprite-DL realloc/free hardening `2f20b1c59`, loop-back
identity preservation `9030c61d9`, backward-goto survivorship `ae9a841a3`).

## Findings: BOTH WASM build modes were broken at HEAD (fixed)

Neither WASM mode has CI (ruffle CI compiles natively via `verify_output.py`'s
own source list), so these rotted silently until this redeploy tried to build:

1. **Browser-WASM (graphics) link failure** — every demo:
   `undefined symbol: ng_freeSpriteDL / ng_ensureDisplayListSize`.
   `2f20b1c59` added the sprite-DL realloc/free funnel inside the
   pending-finalize `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`
   block in `tag.c`, but the funnel call sites (tag.c / tag_stubs.c) are shared
   with the browser build. Both native CI modes define one of the macros, so CI
   compiled it fine. **Fix `367c9b1e5`**: funnel + pending-finalize state table
   compile in all modes (table stays empty in browser; the queue functions keep
   their guard + browser no-op stubs). Token-identical preprocessing for both
   native modes → no CI dispatch.
2. **Trace-WASM (NO_GRAPHICS) build failure** — rotted since ~mid-June:
   `ng_shared.c` used `ng_find_textfield` before its definition (fatal only in
   the trace emcc invocation, which lacks the graphics invocation's
   `-Wno-error=implicit-function-declaration`), and `build_test.sh`'s
   NO_GRAPHICS/HEADLESS copy lists were missing newer runtime sources
   (action_queue.c, sprite_frame_scripts.c, image_decode.c, video_codec.c,
   stb_image_impl.c + stb_image.h). **Fix `903b88c8a`** (forward decl + copy
   lists synced with verify_output.py's canonical list). Also noted:
   `build_test.sh <test> native` is separately broken (missing `-lz`) — not
   needed by any current workflow, left for a future fix.

Memory entry: `wasm-build-modes-rot-without-ci` (smoke-build one graphics + one
trace demo after runtime changes).

## Deployed from

- master `903b88c8a` (2026-07-05). Recompiler binary unchanged since
  `a049390fe` (2026-06-24), which predates the previous deploy → `--fast`
  runtime-only rebuilds used (recompiled C already current).
- Previous deploys: games 2026-06-29, local_batch 2026-05-29, probes 2026-05-28.

## What was rebuilt

- `docs2/examples/flasharchive/*` (11) + `docs2/examples/glaiel/*` (5) via
  `rebuild_docs2_demos.sh --fast` — 16/16 OK; catalogs regenerated with
  `type=<namespace>` (NOT `graphics`).
- `docs2/examples/local_batch/*` (14) via an equivalent per-demo loop — 14/14
  OK; `local_catalog.json` regenerated with `type=local_batch`. Spot checks:
  Snake renders/plays; Bloxorz canvas stays black — **pre-existing** (the
  2026-06-20 divergence run `tools/divergence/runs/Bloxorz/` already rendered
  blank frames on the pre-GC runtime; partial-support corpus, not a redeploy
  regression).
- `docs2/examples/wasm_probes/*` via `build_wasm_probes.sh --force` — 8 built.
- Trace demos `declare_local_comprehensive_swf_7` + `add2_swf_5` deployed to
  docs2 (no catalog entry) as trace-pipeline spot checks.
- **docs/ (public Pages, tracked wasm, last built Feb–Apr 2026) deliberately
  NOT refreshed**: its demos are one-shot trace/graphics tests that don't
  observably benefit from the July work (GC/sprite-DL fixes matter for
  long-running clip churn), and a refresh is a ~168-demo build plus a ~22 MB
  public binary commit — better done as its own deliberate session if wanted.
- `docs2/examples/graphics/` (2 sound_stream demos) not rebuilt (unrelated to
  the July work; rebuild on demand).

## Verification (headed Chrome, DISPLAY=:0, localhost HTTP)

All checks from the prompt pass:

1. **N `?perfhud=1`, 5 min**: live-objects **floor ~3.5–4 k flat** (bucket
   minima 3775 → … → 3529 across 300 s; no drift). The count sawtooths up to
   ~20–47 k between collections because SwiftShader runs ~11–14 fps and the
   collector cadence is 60 frames (~5–6 s) — a 5 s sampling grid aliases
   against it; judge the post-collection floor, not raw samples. FPS stable
   (frame-time mean 80–105 ms throughout, software rendering). No leftover
   laser/death lines across 10 snapshots spanning multiple demo episodes.
2. **Minesweeper**: difficulty screen renders; Tough radio exclusive-select
   works (board spawns with 100 bombs); name textfield accepts typing; Start
   works; cell click opens numbered cells; **spacebar flagging works** (bombs
   70→69, flag drawn); Restart resets board/timer. Only console noise is the
   benign `rando_bridge.js` HEAD 404.
3. **Doodle Jump**: menu → play; doodler jumps, platforms (incl. broken brown)
   scroll, score climbs (263→307 over 30 s), arrow keys effective, no crash.
   **Tetris**: menu (play → level up → ok) → in-game; arrow-key moves + rotate
   work, pieces stack, score accrues, ~30 s stable.
4. **Trace demo**: `add2_swf_5` browser output byte-identical to the native
   runtime (`8` / `Total: 42` / `5 items`). (First pick
   `declare_local_comprehensive_swf_7` printed `undefined/undefined` in BOTH
   browser and native — its hand-written generator pushes value-then-name
   before SET_VARIABLE, i.e. the test SWF itself never assigns `x`; not a
   runtime issue.) **Index page** renders all three game sections (11/5/14
   cards) — catalog `type` grouping correct; the `opcode-index.json` 404 is
   pre-existing (file never existed in docs2).
5. **wasm_probes**: 8/8 pass pixel-identical vs goldens
   (`tools/wasm_probe_runner.py`).

Probe artifacts (session-local): scratchpad `verify_out/` — series.json for the
N HUD runs, canvas snapshots per scenario.

## Close-out

- No CI dispatched: deploys aren't CI-observable; both runtime-side fixes are
  provably invisible to the native CI modes. `.pipeline-state` n/a.
- Memory updated: `upstream-comparison-doc-directory` (pending-redeploy line →
  done), new `wasm-build-modes-rot-without-ci`.
