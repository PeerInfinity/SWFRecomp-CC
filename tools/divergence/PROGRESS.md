# WASM Divergence Debugging — Progress

Living progress tracker for the effort to make flasharchive / glaiel games run
under SWFRecomp by finding and fixing where they diverge from Ruffle/Flash.

**Read at session start, in this order:**
1. `SWFRecompDocs/guides/wasm-game-debugging-session-guide.md` — how-to (tools, triage, build/deploy, constraints).
2. **This file** — what's done, what's next, hard-won gotchas.
3. `tools/divergence/RESULTS.md` — per-game divergence board (the raw "what's broken").

Last updated: 2026-05-30.

## Status board (per game)

| Game | Size | Status |
|---|---|---|
| Snake | 9KB | **DONE (logic). Trace IDENTICAL (31/31), reconfirmed on fresh HEAD rebuild 2026-05-30.** Tracer-not-dispatched was the pre-`6a08f06aa` artifact; logic matches Ruffle. **OPEN (cosmetic, root-caused → follow-up #6):** `www.neave.com/webgames` URL = `DefineEditText` char 5 → font 4 (0 embedded glyphs) → recompiler **device-font glyph synthesis** from NotoSans. Indices are CORRECT (`text_data[i]=glyph_base(40)+(code−32)`); font 2's real outlines render fine via the same path. Garble is in the **synthesized glyph SHAPES** — holeless letters OK (`w.nvcm/s`), counter letters malformed (`o`→`e`, `a`→`u`, `g`) ⇒ earcut hole-tessellation bug (`swf.cpp:2347–2502`). Shared/high-risk; cosmetic; deferred. |
| Tetris | 14KB | **preloader→menu transition FIXED 2026-05-30 (pending CI + commit).** Menu now materializes at F2: `level=1`/`score=0`/`Logo` (clip `_cf=2`) all match Ruffle; Dots removed. Root cause: the byte preloader's `_root.onEnterFrame` does `delete this.onEnterFrame; this.nextFrame()` exactly once when bytes load; on a **stopped** root that deferred `nextFrame` advance was dropped (swf.c frame_funcs gate needs `is_playing || manual_next_frame`, but `manual_next_frame` is cleared at end-of-tick before `current_frame` reaches the target → `frame_1` never ran). Fix in `actionNextFrame` (action.c): when `g_inside_enterframe_dispatch && !is_playing && g_current_context==&root_movieclip`, set the **deferred-goto** state (`goto_from_action=1`) so the main-loop catch-up block (swf.c:778 / swf_core.c:1219, both AFTER the enterFrame flush) runs `funcs[target]` with scripts drained normally. (Setting it via inline `ng_executeGotoCatchUp` instead lagged script_6 + clip-init by ~2 ticks because it ran while still inside enterFrame dispatch.) **Residual (separate, pre-existing):** swfrecomp prints `_root game_so=undefined` where Ruffle shows nothing — `SharedObject.getLocal("neaveTetris")` returns `undefined` in our runtime vs a SharedObject instance in Ruffle (the "spurious undefined global" pattern; SharedObject local-storage support is unimplemented). Image f1 `max_diff=27` is the PRELOADER frame, unrelated to the menu. |
| Minesweeper | 29KB | Not started (next smallest). |
| Pacman | 42KB | Not started. |
| Checkers, Doodle Jump, Bloons, Avalanche, … (local_batch) | — | Results in RESULTS.md are PRE-tracer-fix → INVALID for any `_root.onEnterFrame`-driven game. Re-run needed. |

AVM2 (exclude): flasharchive `QWOP`; glaiel `Aether, Closure, Pilgrimage, Spectrum, attractor, nutcracker, helenkellergame`. Classify with `tools/divergence/classify_avm.py`.

## Tooling / runtime fixes landed

| Commit | What |
|---|---|
| `b8ced0c60` | `tagPlaceObject2`: allow Move=1 PlaceObject **replace** at an occupied depth (Ruffle `PlaceObjectAction` semantics). Fixed Tetris's spurious "Failed to place object at depth 1". CI-green both modes. |
| `6a08f06aa` | **Tracer hooks a dedicated clip's `onEnterFrame`, not `_root`'s** — was silently clobbering games' root loop. |
| `c202530a0` | Divergence harness writes a `compare/` dir: co-located `f<NN>.ruffle.png` / `f<NN>.swfrecomp.png` / `f<NN>.swfrecomp.difference.png` for every frame. |
| `d905efdb1` | `case-v5`/`case-v6` graphics-mode SIGABRT (3 ASAN-pinned heap bugs — these were real heap bugs, NOT flakes). |
| `477c57975` | `classify_avm.py` (DoABC-based AVM1/AVM2 detection; version byte is NOT a discriminator) + guide exclusion list. |
| `ed198c7b7` | Made `MAX_CAPTURES` (→ `CAPTURE_MAX` env) and the 30s recompile timeout (→ `SWFRECOMP_RECOMPILE_TIMEOUT` env) configurable; defaults unchanged. |
| `c4401c83f` | `build_swf_batch.sh` timeout env-overridable; RESULTS.md; `run_local_batch.sh`. |
| `2aad9c0c6` | The session-start guide + CLAUDE.md pointer. |

## Key learnings / gotchas (don't relearn these)

- **The tracer must not clobber game handlers.** It now uses a dedicated `__tracer__` clip. Any divergence result produced *before* `6a08f06aa` for a game using `_root.onEnterFrame` ran with the game's root loop disabled → **invalid, re-run**.
- **The divergence harness compares SWFRecomp against Ruffle's headless *exporter*, not the live Ruffle browser player.** They can differ (preloader/streaming/timing). "Trace: identical" vs the exporter does NOT prove a match with real Flash — both headless tools can be equally stuck (e.g. a preloader that only advances under real wall-clock).
- **Image comparison only covers the first 16 frames** unless you set `CAPTURE_MAX=<n>` (the tick loop runs the full count; only PNG capture is capped).
- **Large SWFs (>~2MB) hit the recompile timeout** — set `SWFRECOMP_RECOMPILE_TIMEOUT=600`.
- **Graphics-mode SIGABRT *after* correct output = a real heap UAF/OOB, not a CI flake.** ASAN-pin it (`--asan`). See memory `graphics-sigabrt-real-heap-bugs`.
- **Browser-probe canvas capture** of a live WebGPU canvas fails (Playwright stability timeout); only the display-list JSON is reliable there. And automated headed Chrome may throttle rAF (demo runs slowly / looks stuck).
- Game `trace()` can contain non-UTF8 bytes → use `grep -a`.

## Open follow-ups (priority order)

1. ~~**Re-check Snake** with the fixed tracer~~ **DONE 2026-05-30** — trace identical (31/31); logic matches Ruffle. Cosmetic residual → #6.
2. ~~**Tetris preloader→menu transition (USER PRIORITY)**~~ **FIXED 2026-05-30** (see status board + session log; `actionNextFrame` deferred-goto fix). Pending CI both modes + commit. Regression gate (must stay green): `divergence_test.py "$HOME/CC/flasharchive/Tetris.swf" --frames 16 --skip-ruffle` → F2 has `_root level=1`/`score=0`/`Logo` (clip `_cf=2`), Dots removed. Only residual trace line is `game_so=undefined` (SharedObject, see #7).
3. **Continue smallest-first:** Minesweeper (29KB) → Pacman (42KB) → … (skip QWOP).
4. **Re-run the local_batch corpus** with the fixed tracer; update RESULTS.md. Prior `_root.onEnterFrame`-game results are invalid.
5. Verify the non-injected docs2 browser demo actually advances (probe showed stuck, likely rAF throttling — confirm it's not a separate real issue).
6. **Device-font synthesized-glyph hole tessellation** (cosmetic, found via Snake — root-caused 2026-05-30). NOT index mapping (indices verified correct). Bug is earcut hole/contour handling of NotoSans outlines synthesized for glyphless `DefineFont2`/`DefineFont3` device fonts (`swf.cpp:2347–2502`). **Better repro:** a minimal probe — glyphless `_sans` font + a text field showing holed glyphs ("ego boba") via MTASC `-version 8`, under `SWFRecomp/tests/wasm_probes/` or a verify_output graphics test — far easier than the 9KB game. **Shared/high-risk:** changes every synthesized device-font glyph in all games → CI both modes + visual regression. Cosmetic; deferred to a dedicated session with a healthy tool env.
7. **`SharedObject.getLocal` returns `undefined`** (surfaced via Tetris #2). Ruffle returns a SharedObject instance; our runtime has no local-storage backing, so `game_so = SharedObject.getLocal("neaveTetris")` becomes `undefined` and the tracer prints a spurious `_root game_so=undefined` line. Likely shared across many games (high-score persistence). Minimal fix to silence the divergence: have `getLocal` return an empty object with a `.data` bag (no real persistence needed for headless trace parity). Separate from the timeline work.

## Session log

- **2026-05-29** — Stood up the effort: session-start guide, AVM1/AVM2 classifier, configurable harness limits, `local_batch` divergence baseline (RESULTS.md). Established per-corpus namespaces; QWOP/glaiel AVM2 exclusions.
- **2026-05-30** — Tetris: fixed `tagPlaceObject2` occupied-depth replace (`b8ced0c60`, CI-green). Added `compare/` image UX (`c202530a0`). Root-caused the Tetris "loader never advances" as a **tracer artifact** (tracer clobbered `_root.onEnterFrame`) and fixed it (`6a08f06aa`); Tetris now reaches the menu and a real post-loader divergence is visible. (`case-v5/v6` heap bugs fixed in parallel: `d905efdb1`.)
- **2026-05-30 (cont.)** — **Snake** re-checked (follow-up #1): AVM1 confirmed; trace now IDENTICAL (31/31), logic matches Ruffle. Root-caused the residual URL garble end-to-end (DefineEditText char 5 → font 4 device-glyph synthesis; indices correct; bug is synthesized-glyph hole tessellation, `swf.cpp:2347–2502`). Reconfirmed on a fresh `cmake --build` from HEAD. Per user: documented as #6 (cosmetic, deferred; minimal probe suggested) rather than fixed now (shared/high-risk earcut change + flaky tool env).
- **2026-05-30 (cont. 2)** — **Tetris** retested from scratch (USER PRIORITY) now that it reaches the title screen (image max_diff 27, was full-frame). Re-characterized the divergence as a **real preloader→menu transition bug**, not tracer noise: at frame 2 SWFRecomp fails to remove `Dots`, place `_root.Logo`, and set `_root.level`/`score`; `Dots` keeps looping. Promoted to follow-up #2 (top item). Trace values that exist match — it's missing display-list ops + var sets, not wrong values.
- **2026-05-30 (tooling note)** — Bash/Read tool-result delivery dropped results intermittently all session (returned blank/stale ~half the time). Worked around by writing to /tmp and re-reading, and by `tr -d '\r'`. A clean shell env will materially speed the next session.
- **2026-05-30 (cont.)** — Re-checked **Snake** with the fixed tracer (follow-up #1). `classify_avm.py` confirms AVM1. Divergence harness now reports **Trace: identical (31/31)** — the prior "tracer dispatched 0×" was the pre-`6a08f06aa` artifact, now resolved; **no Snake runtime fix needed, logic matches Ruffle.** Residual is a frame-1 image diff (839 px, stable across all 16 frames): the bottom `www.neave.com/webgames` URL renders garbled.
- **2026-05-31** — **Tetris preloader→menu transition FIXED** (follow-up #2, USER PRIORITY). Decisive check confirmed `frame_1` never ran (menu children `play_btn`/`Logo` absent from swfrecomp trace, present in Ruffle from F2). Root cause: the byte preloader's `_root.onEnterFrame` fires `delete this.onEnterFrame; this.nextFrame()` ONCE on load; `actionNextFrame` on a **stopped** root only set `manual_next_frame` (no `goto_from_action`), and swf.c clears `manual_next_frame` at end-of-tick before `current_frame` reaches the target, so the frame_funcs gate `(is_playing || manual_next_frame)` skips `frame_1` forever. Fix (`action.c` `actionNextFrame`): new branch `g_inside_enterframe_dispatch && !is_playing && g_current_context==&root_movieclip && !ng_isInsideSprite()` sets the deferred-goto state (`goto_from_action=1; next_frame=target; manual_next_frame=1`) and returns — the main-loop catch-up block (swf.c:778 / swf_core.c:1219, both run AFTER the enterFrame flush, outside dispatch) executes `funcs[target]` with scripts drained normally. First tried inline `ng_executeGotoCatchUp` (mirroring the existing `g_inside_event_handler` button branch) but it lagged script_6 + Logo clip-init by ~2 ticks because it ran while `g_inside_enterframe_dispatch` was still set; the deferred-to-main-loop variant has zero lag. Result: F2 now matches Ruffle (`level=1`, `score=0`, `Logo` clip `_cf=2`, Dots gone). Only residual: `game_so=undefined` (SharedObject, new follow-up #7). Local regression trace tests PASS: goto_methods, goto_frame_number, goto_frame2 (issue_9885/default_names/create_empty_movie_clip running). Pending: CI both modes + user commit.
- **2026-05-30 (cont. 2)** — Root-caused the Snake URL garble end-to-end (follow-up #6). Chain: URL = `DefineEditText` char 5 → font 4 (0 embedded glyphs) → recompiler zero-glyph device-font synthesis seeds NotoSans 32–126. Baked glyph indices VERIFIED correct (`text_data[i]=glyph_base(40)+(code−32)`). Font 2 (real outlines) renders fine through the same path. Garble signature: holeless letters correct (`w.nvcm/s`), counter letters wrong (`o`→`e`, `a`→`u`, `g`) ⇒ bug is multi-contour/hole **earcut tessellation** of synthesized glyphs (`swf.cpp:2347–2502`), NOT index mapping. Reconfirmed on a fresh `cmake --build` from HEAD (incremental, 1.43s recompile). Documented as #6: fix is shared/high-risk (touches all device-font glyphs in all games), cosmetic (credit URL), deferred to a dedicated session with a healthy tool env. **Tool note:** this session's Bash/Read output channel dropped results intermittently — worked around by writing to /tmp files and re-reading; a clean env will speed the actual fix. Next per user pick: pursue #6 tessellation fix, OR pivot to #2 (re-run local_batch corpus).
