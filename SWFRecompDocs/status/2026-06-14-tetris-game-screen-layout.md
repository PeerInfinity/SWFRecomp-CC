# Tetris game screen: object placement is broken (board frame, score panel, buttons missing; ~2× stage inflation)

**Date:** 2026-06-14 (cont. 30 follow-up — investigation handoff)
**Status:** 🔴 **OPEN** — new investigation. The board cells now *colour* (cont. 30
`shape_array` fix + cont. 29 cell-resolution fixes), but the **game-frame layout is
wrong**: the board outline, the level/lines/score panel labels, and the quit/pause
buttons don't render, the "tetris" logo is mis-placed, blocks are scattered/wrong, and
the stage is inflated to ~2× by a stray element. **Browser-WASM only** — verify with
`tetris_compare.py`, not CI.

---

## What the visual comparison established (tetris_compare.py, cont. 30)

The renderer/text/scale engine is **proven good** — the divergence is specific to the
**game screen** ("ok" stage):

| Stage | Result |
|-------|--------|
| **menu** | ✅ near-perfect match — "tetris" logo, ■ play / ■ high scores, `www.neave.com/games`, same scale |
| **play** (level select) | ✅ match — *except* the digit **"1" renders as a slanted "/"** (known, deprioritized italic-glyph bug; "2" renders fine on the next stage) |
| **up** (level→2) | ✅ match |
| **ok** (game) | ❌ **broken layout — this is the bug** |

Compare images live in `tools/divergence/game_drive/compare_out/`:
`compare_{menu,play,up,ok}.png` (side-by-side), `ruffle_ok.png` (correct game screen),
`swfrecomp_ok.png` (our broken game screen).

### Ruffle's correct game screen (`ruffle_ok.png`)
- Tall board rectangle on the **left**, blue falling piece upper-left.
- Next-piece preview box **top-right** (blue piece).
- Right column: **level 2 / lines 0 / score 0** (label + value rows).
- **quit / pause** buttons.
- **"tetris" logo bottom-right.**
- Everything fits in a **382×380** box.

### SWFRecomp's broken game screen (`swfrecomp_ok.png`)
- **"tetris" logo at TOP-LEFT** (should be bottom-right) — mis-positioned.
- A stray **red** 2×2 block top-center (Ruffle has no red here).
- A blue piece top-right (plausibly the next-piece preview, roughly right position).
- A bare floating **"2"** mid-screen (the level *value*, but with **no `level`/`lines`/
  `score` labels** around it).
- A small stray cell at the **far bottom-right**.
- **No board outline, no panel labels, no quit/pause buttons.**
- Harness measured the SWFRecomp content box at **781×777 @ (52,0)** — ~**2×** Ruffle's
  382×380. The stray bottom-right cell is almost certainly what inflates the bbox; the
  harness then scales the capture by that box, cramming the real content into the
  top-left quadrant (so some of the "mis-position" is capture-scaling, but the logo
  being top-left and the missing frame/labels/buttons are real).

## Hypotheses / where to look (unverified — for the next session)

This is a **placement / frame-content** bug class, distinct from the cell-colouring one:

1. **Stray element at ~(781,777) inflating the stage to 2×.** Find which display entry
   / attached MC lands there. Could be a board cell placed at doubled coordinates, or
   an element whose transform is composed twice (`compute_mc_world_xform` from cont. 28
   double-applying a parent transform?). Fixing this likely also un-cramps the capture.
2. **Board outline (the tall rectangle) not rendering.** Is it a static DefineShape on
   the game frame, or part of `b_mc`? Check whether the game-frame's static/timeline
   content renders at all, or only the attached `block` cells do.
3. **Score panel labels (`level`/`lines`/`score`) + quit/pause buttons missing.** These
   are static text + buttons on the game frame. The bare "2" rendering (a bound dynamic
   textfield value) but not its label suggests the static/timeline content of the game
   frame is being skipped while only dynamic/attached content renders. Compare to how
   the menu frame (which renders fully) differs from the game frame.
4. **"tetris" logo mis-position.** Same static-content-placement question.

**Strong working theory:** on the game frame, only *dynamically-created / attached*
content (bound textfields, attached `block` cells) is rendering; the frame's *static /
timeline-placed* content (board frame shape, panel labels, buttons, logo) is being
skipped or mis-placed. The menu/level-select frames render their static content fine,
so contrast those frames' placement path against the game frame's. Start by
instrumenting the game-frame render to dump every display entry (static + attached):
char_id, instance name, world (x,y), and whether it rendered — then diff against the
expected Ruffle layout.

## Reproduce / verify (the loop)

```bash
source emsdk/emsdk_env.sh
SWFRecomp/scripts/build_test.sh flasharchive/Tetris wasm --graphics --clean
# confirm your diagnostic landed BEFORE deploying:
strings SWFRecomp/tests/flasharchive/Tetris/build/wasm/Tetris.wasm | grep -c <your-PMDIAG-marker>
SWFRecomp/scripts/deploy_example.sh flasharchive/Tetris "$(pwd)/docs2/examples" --no-index --graphics
# run the harness STANDALONE (see process gotchas):
/tmp/browser-test-venv/bin/python3 tools/divergence/game_drive/tetris_compare.py
# view compare_out/swfrecomp_ok.png vs ruffle_ok.png; diagnostics in compare_out/pmdiag.log
```

## Process gotchas (cost real time in cont. 30 — heed)

- **The handoff's cleanup `pkill -9 -f browser-test-venv` / `pkill -f chrome`
  SELF-MATCH the launching shell** (its command line literally contains
  `/tmp/browser-test-venv/bin/python3 …` and the word `chrome`), so pkill kills the bash
  command before it runs → exit 1, no output, stale `pmdiag.log` left behind. **Run
  cleanup in a SEPARATE bash call from the harness launch, and use the bracket trick:**
  `pkill -9 -f 'tetris_compar[e]'`, `pkill -9 -f 'chrom[e]'`, or name-based
  `pkill -9 chrome` / `pkill -9 chromium`. See memory
  `tetris-compare-harness-pkill-selfmatch.md`.
- The harness needs **Chrome + WebGPU + Ruffle CDN network + DISPLAY** → run it with the
  **Bash sandbox disabled** (`dangerouslyDisableSandbox: true`), `timeout 600`.
- After building, `strings <wasm> | grep <marker>` to confirm the diagnostic actually
  compiled in before deploying (a couple of builds raced on stale wasm in cont. 30).
- Gate temp diagnostics on `#ifdef __EMSCRIPTEN__`; `printf("PMDIAG …")` is captured to
  `compare_out/pmdiag.log` by the harness console hook. **Strip before committing.**
- The SWFRecomp side is slow; allow `timeout 600`.

## Constraints

- Browser-WASM-only behavior → verify with the harness, NOT CI
  (`ci-only-when-observable`). If a fix touches shared/OFFSCREEN-compiled code, also run
  CI both modes as a no-regression check (`.claude/pipeline-handoff.md`); autonomous
  commit/push/CI is authorized. Commit to master (trunk-based). Update PROGRESS.md
  (cont. 31) + a new status doc when something lands.
- Also still pending (deprioritized): the italic-digit "1"→"/" glyph slant; and a manual
  re-check of DJ/Snake/Pong for cont. 29's fix #3 (`gotoAndStop`→`ng_gotoFrameByMC`,
  not CI-observable).

## Read first (next session)

1. This doc.
2. `SWFRecompDocs/status/2026-06-14-tetris-shape-array-newobject.md` (cont. 30 — the
   colouring fix that got us here).
3. `SWFRecompDocs/status/2026-06-14-tetris-board-gotoandstop.md` (cont. 29 — cell
   resolution + gotoAndStop fixes #1–#3).
4. `tools/divergence/game_drive/README.md` (harness).
5. Memory: `browser-wasm-visible-and-nonroot-attach-render.md`,
   `child-mc-cache-cap-resolution.md`, `tetris-compare-harness-pkill-selfmatch.md`,
   `getbounds-as-created-clips.md`.
