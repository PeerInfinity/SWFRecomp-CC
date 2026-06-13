# Divergence Test Results — flasharchive games

Each game's `~/CC/flasharchive/` source SWF is run through the divergence harness
(`tools/divergence/divergence_test.py`), which compares SWFRecomp
(graphics-native, headless) against Ruffle on both `trace()` output and per-frame
rendered images.

- **Source SWFs:** `~/CC/flasharchive/`
- **Harness usage:** `SWFRecompDocs/guides/divergence-harness-usage.md`
- **Run command per game:** `python3 tools/divergence/divergence_test.py "<swf>" --frames 16`
- **Per-run outputs:** `tools/divergence/runs/<stem>/` (gitignored); co-located
  ruffle/swfrecomp/difference PNGs in `runs/<stem>/compare/`.

**Date of this run: 2026-06-12** (re-run of follow-up #4 with the fixed tracer
`6a08f06aa` + all fixes landed through `c4630257e` on HEAD; both sides fresh).
The prior board (2026-05-29) predated the tracer fix and was INVALID for every
`_root.onEnterFrame`-driven game — superseded by this run.

## Investigation notes (read before interpreting results)

1. **Image comparison covers only the first 16 frames by default**
   (`CAPTURE_MAX`, env-overridable). The tick loop runs the full `--frames`
   count; only PNG capture is capped.
2. **Recompile timeout is 30s by default** (`SWFRECOMP_RECOMPILE_TIMEOUT`).
   The two biggest games need it bumped: **Art of War** (1.5MB) recompiles fine
   at the default; **Castle Hero** (14MB) needs `SWFRECOMP_RECOMPILE_TIMEOUT=900`
   — its injected SWF (14MB) recompiled in ~49s with the bump.
3. **Trace numeric tolerance** (rel 1e-5 / abs 1e-4) absorbs f32-vs-f64
   precision noise by default; `--trace-exact` to see it.
4. Game `trace()` can contain non-UTF8 bytes — use `grep -a`.

## Summary (cross-suite re-run, smallest games covered by the status board)

The per-game **status board** (Snake, Tetris, Minesweeper, Pacman, Tron, Storm
the House, Shopping Cart Hero, N, Checkers, Bloons) lives in
`tools/divergence/PROGRESS.md` — those are the games worked end-to-end. This
file tracks the broader **flasharchive corpus** the harness was re-swept across.

| Game | Size | Trace (ruffle/swfrecomp) | First trace divergence | Bucket |
|---|---|---|---|---|
| Age of War | — | 61 / 61 | **identical** | image-only |
| Avalanche | 527KB | 76 / 76 | L2: `instance1 _cf=4` vs `2` | nested-sprite `_cf` lag (#10a) |
| Achievement Unlocked | — | 289 / 303 | L11: `instance5 _cf=2` vs `100` | playhead/auto-name + attach pacing |
| Art of War | 1.5MB | 224 / 226 | L2: `box="…wait until 50%"` vs `PercentLoaded=100` | preloader/network (no net layer) |
| Bloons TD | — | 151 / 188 | L12: `prog=100` vs `loadbar` placement | preloader pacing + Mochi |
| Bloons TD 2 | — | 173 / 233 | L6: `reserved` + `_cf` advance | preloader pacing + Mochi |
| Bloxorz | — | 76 / 91 | L2: `backser` vs `percentr="Preloading…"` | preloader pacing |
| Doodle Jump | — | 211 / 196 | L6: `hero _y=247.55` vs `251.55` | RNG-driven initial platform layout (guide gotcha #12) |
| Duck Life 1 | — | 482 / 482 | L26: `seed=5` / `skill=0` region | (line counts now MATCH; advanced from old L15) |
| Duck Life 2 | — | 271 / 286 | L4: `loadcheat` region | preloader/value mismatch |
| Castle Hero | 14MB | — | (recompile recovered w/ 900s timeout; see PROGRESS log) | big-SWF |

(Filtered trace-line counts. Every game's image diverges by frame 1–2 — mostly
full-frame `max_diff=255` = background/preloader rendering, a few sub-pixel.)

## Cross-cutting patterns (2026-06-12)

- **Improvements since 2026-05-29** (landed fixes cleared earlier divergences):
  - **Avalanche** old L2 `instance3=undefined` ghost → GONE (ghost-elimination
    `5d27de9a7`); now 76/76 line counts, first divergence is the nested-sprite
    `_cf` lag (#10a, `instance1 _cf=4` vs `2`).
  - **Duck Life 1** old 482/497 diverge L15 (`game=undefined` spurious global) →
    now **482/482**, divergence advanced to L26.
  - **Achievement Unlocked** old 250/278 L18 (`instance1=undefined`) → now
    289/303, first divergence advanced to L11 (a real `instance5` playhead bug).
- **Nested / attached clip `_currentframe` divergences** are the dominant
  remaining class across the corpus:
  - **Nested timeline sprites lag one tick** (#10a): Avalanche `instance1`,
    Pacman `Pac`/`CPac`, N `timeIndicator.bar`. swfrecomp advances nested
    auto-playing playheads one tick later than Ruffle relative to the tracer's
    `onEnterFrame` sample.
  - **attachMovie'd multi-frame clips don't auto-advance at all** (NEW, #15):
    a root/non-root attached clip's standalone `display_obj` is never walked by
    `advance_sprite_frames`, so its timeline is pinned at `_currentframe=1`.
    Minimal repro: `tools/divergence/gates/attached_clip_playhead.swf` (FAILS on
    HEAD). Surfaces (gated behind other bugs) in Achievement Unlocked's
    `ach80`/`shel`/`curAch` popups.
  - **Auto-name playhead** (Achievement `instance5 _cf=100`): an auto-named clip
    jumps to its last frame instead of advancing from 1 — distinct from the two
    above; first divergence for Achievement.
- **Preloader / network pacing** (Art of War, Bloons family, Bloxorz, Duck
  Life 2): SWFRecomp has no network/Mochi layer, so `PercentLoaded`/byte
  counters read 100/complete immediately while Ruffle's preloader holds.
  Accepted/expected until a network stub exists (`MochiServices Connecting…` is
  already harness-filterable).
- **RNG-layout image divergences** (Doodle Jump): the 4px `hero._y` delta traces
  to `Math.random`-seeded initial platform layout, not a renderer bug (guide
  gotcha #12) — confirm via the trace before chasing pixels.
- **Identical trace**: Age of War (logic matches; image-only divergence).
