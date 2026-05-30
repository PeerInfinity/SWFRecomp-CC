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
| Snake | 9KB | Earlier result INVALID (tracer bug — see below). Re-run needed. |
| Tetris | 14KB | Placement fix LANDED + CI-green. Tracer fix LANDED → loader now advances 1→2 to the menu. **OPEN:** frame-2 divergence (`sofar`/`level` preloader-var leakage). |
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

1. **Re-check Snake** with the fixed tracer — its "tracer never fired" result was likely the same bug; may now be resolved (the dedicated-clip dispatch path differs).
2. **Re-run the local_batch corpus** with the fixed tracer; update RESULTS.md. Prior `_root.onEnterFrame`-game results are invalid.
3. **Investigate Tetris's frame-2 divergence** (`F2 _root level=1` (ruffle) vs `sofar=29642` (swfrecomp) — preloader temp-var leakage / property-set mismatch).
4. **Continue smallest-first:** Minesweeper (29KB) → Pacman (42KB) → … (skip QWOP).
5. Verify the non-injected docs2 browser demo actually advances (probe showed stuck, likely rAF throttling — confirm it's not a separate real issue).

## Session log

- **2026-05-29** — Stood up the effort: session-start guide, AVM1/AVM2 classifier, configurable harness limits, `local_batch` divergence baseline (RESULTS.md). Established per-corpus namespaces; QWOP/glaiel AVM2 exclusions.
- **2026-05-30** — Tetris: fixed `tagPlaceObject2` occupied-depth replace (`b8ced0c60`, CI-green). Added `compare/` image UX (`c202530a0`). Root-caused the Tetris "loader never advances" as a **tracer artifact** (tracer clobbered `_root.onEnterFrame`) and fixed it (`6a08f06aa`); Tetris now reaches the menu and a real post-loader divergence is visible. (`case-v5/v6` heap bugs fixed in parallel: `d905efdb1`.)
