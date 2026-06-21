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

**Date of latest run: 2026-06-13** (smallest-first re-sweep on HEAD; Duck Life 1
+ Avalanche re-run both sides fresh). Prior full sweep: **2026-06-12** (follow-up
#4, fixed tracer `6a08f06aa` + fixes through `c4630257e`). The 2026-05-29 board
predated the tracer fix and was INVALID for every `_root.onEnterFrame`-driven
game — superseded.

**Changes vs the 2026-06-12 board (2026-06-13 re-sweep):**
- **Duck Life 1 → CONVERGED.** The L26 `spinamount` divergence the board
  flagged as "smells like (A)" is **class (B)**, not a real bug. `spinamount` is
  a frame-1 `DefineEditText (vn:"spinamount")` whose binding seeds `_root.spinamount
  = "0"` (string); the preloader's `setInterval(Lbar,10)` then computes
  `getBytesLoaded()/getBytesTotal()*100` = `100` on a fully-loaded local SWF.
  SWFRecomp fires the interval (Flash-correct → `100`); Ruffle's headless exporter
  never fires it, so the binding's `"0"` persists every frame. The `web=_url` line
  is a file:// path artifact. With the new `file://*.swf` NOISE_PATTERN + the
  `accepted/Duck Life 1.txt` spinamount rule, **0 residual divergent lines** (482).
- **Avalanche → first divergence FIXED (L2→L3).** `instance1 _cf` was FROZEN at 2
  (Ruffle advances 4→18) — NOT the #10a 1-tick lag the board guessed, but a
  complete failure to escape a 2-frame preloader. Root cause: `actionGoToLabel`
  (GoToLabel / `gotoAndStop("loaded")`) was not sprite-aware — it resolved the
  label against the ROOT timeline only, so a sprite-local label silently no-op'd.
  Fixed in `action.c` (sprite-local label lookup via `ng_findSpriteLabelFrame` +
  `ng_gotoFrameCurrentSprite`). `instance1` now advances 4→18 matching Ruffle;
  new first divergence L3 = the **#13 auto-instance-counter** offset
  (`instance4` vs `instance2`, cosmetic/deferred).

## Investigation notes (read before interpreting results)

1. **Image comparison covers only the first 16 frames by default**
   (`CAPTURE_MAX`, env-overridable). The tick loop runs the full `--frames`
   count; only PNG capture is capped.
2. **Recompile timeout is 30s by default** (`SWFRECOMP_RECOMPILE_TIMEOUT`).
   **Art of War** (1.5MB) recompiles fine at the default. **Castle Hero** (14MB)
   needs `SWFRECOMP_RECOMPILE_TIMEOUT=900` for the SWF→C step (recompiled in
   ~49s with the bump) — but then hits a **SECOND, separate** limit: the
   hardcoded **300s per-file gcc compile timeout** in `verify_output.py`
   (`compile_native failed: compilation timed out`) on the resulting giant
   generated C. So Castle Hero is **still blocked** even with the recompile
   bump; bumping the gcc-compile cap (or sharding the generated C) is a separate
   change. Castle Hero's SWF→C recompile is NOT the desync symptom (it produces
   valid C, just a lot of it).
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
| Avalanche | 527KB | 76 / 76 | **L3** (was L2): `instance1.instance4` vs `instance2` | **L2 frozen-preloader FIXED 2026-06-13** (sprite-local GoToLabel); residual = #13 auto-instance counter |
| Achievement Unlocked | — | 289 / 303 | L11: `instance5 _cf=2` vs `100` | playhead/auto-name + attach pacing |
| Art of War | 1.3MB | 207 / 209 (re-run 2026-06-21) | F1: `PercentLoaded=100` vs `box="…wait until 50%"` (207 matched, 2 swf-only) | **accepted preloader pacing** — byte-counter, no net layer (confirmed #11) |
| Bloons TD | 531KB | 151 / 188 (re-run 2026-06-21) | F3: `prog=100` (ruffle-only); swf advances ahead | **accepted preloader pacing** — byte-counter drives the multi-frame root ahead, NOT a frame-ordering bug (confirmed #11) + Mochi |
| Bloons TD 2 | 787KB | ✗ **gcc-fail** (re-run 2026-06-21) | #14 desync: garbage ConstantPool strings (`char* str_…="<binary>"`) | **#14 obfuscated-AS recompiler parse desync** (confirmed recompiler-side via clean non-injected recompile; prior 173/233 was built on a desynced parse) |
| Bloxorz | 2.25MB | ✗ **gcc-fail** (re-run 2026-06-21) | #14 desync: garbage ConstantPool strings | **#14 obfuscated-AS recompiler parse desync** (prior 76/91 invalid — desynced parse) |
| Doodle Jump | — | 211 / 196 | L6: `hero _y=247.55` vs `251.55` | RNG-driven initial platform layout (guide gotcha #12) |
| Duck Life 1 | 1.28MB | 482 / 482 | **none (CONVERGED 2026-06-13)** | `spinamount` = (B) preloader byte-counter; `web` = `_url` path artifact; both absorbed (rule + noise) |
| Duck Life 2 | — | 271 / 286 | L4: `loadcheat` region | preloader/value mismatch |
| Castle Hero | 14MB | — | ⚠️ SWF→C recompiles (~49s w/ 900s timeout) but gcc compile times out (300s per-file cap) | big-SWF, blocked on gcc-compile cap |

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

### Bloons-family cluster re-run (#11 closed, 2026-06-21)

Re-ran the preloader-pacing cluster to settle #11's open question — *is any
multi-frame root advancing ahead of Ruffle for a real frame-ordering reason
(high-risk swf.c timing), rather than the byte-counter?* **Answer: no.**

- **All five roots are MULTI-frame** (Bloons 59, Bloons TD 11, Bloons TD 2 12,
  Bloxorz 99, Art of War 23) — so the single-frame `_currentframe` clamp
  (`6e7cf24ea`) never applied to them; #11's "maybe they're single-frame too"
  hypothesis is **false**.
- The two that compile (**Bloons TD**, **Art of War**) **do** advance ahead of
  Ruffle, but in both the harness auto-confirms it is the
  `getBytesLoaded/getBytesTotal` byte-counter (local SWF reads 100%-loaded
  immediately, so the preloader gate/loop exits while Ruffle's exporter streams
  bytes). Art of War: 207/209 lines match. This is the **accepted no-net-layer
  pacing class** (same mechanism as Duck Life 1 / Shopping Cart Hero), **not** an
  independent frame-ordering bug. No high-risk swf.c timing fix is warranted.
- The three that don't converge (**Bloons**, **Bloons TD 2**, **Bloxorz**) are
  all blocked by **#14** (obfuscated-AS recompiler parse desync), confirmed
  recompiler-side via a clean non-injected recompile. Bloons TD 2 + Bloxorz are
  NEW additions to #14's affected-games list; their prior 2026-06-12 traces were
  built on an already-desynced parse (the garbage has since shifted onto bytes
  that break a C string literal → gcc-fail). See PROGRESS.md #14.
  Accepted/expected until a network stub exists (`MochiServices Connecting…` is
  already harness-filterable).
- **RNG-layout image divergences** (Doodle Jump): the 4px `hero._y` delta traces
  to `Math.random`-seeded initial platform layout, not a renderer bug (guide
  gotcha #12) — confirm via the trace before chasing pixels.
- **Identical trace**: Age of War (logic matches; image-only divergence).
