# Tetris PLAYABLE — browser-WASM never pumped `processTimers`, so `setInterval` never fired

**Date:** 2026-06-15 (cont. 32)
**Status:** ✅ **FIXED** — Tetris is now playable on the SWFRecomp browser-WASM
side: the falling piece animates (drops on a timer), pieces stack on the board,
and the score increments. Verified with `tools/divergence/game_drive/tetris_compare.py`
(`compare_ok.png`: pieces fall + stack, `score=56`, all panels/logo correct).
**Bucket:** **browser-WASM only** — the one-line change is gated
`#if !defined(OFFSCREEN_RENDER) && defined(__EMSCRIPTEN__)`, so it is excluded
from both CI-tested modes (NO_GRAPHICS uses `swf_core.c`; graphics-native is
`OFFSCREEN_RENDER`). Not CI-observable → verified via the browser harness, no CI
dispatch (see `ci-only-when-observable`).

---

## Root cause

The cont. 31 handoff's open blocker was "per-frame game AS doesn't drive the
timeline in browser-WASM." Fresh instrumentation (a lean PMDIAG heartbeat +
dispatch counters, per the re-confirm-before-coding lesson) localized it
precisely, and it was **not** an `onEnterFrame` problem:

- **`onEnterFrame` already works.** Every `frame_func` calls
  `tagFlushPendingEnterFrame` at its `ShowFrame`, which dispatches AS2
  `onEnterFrame` (`actionDispatchEnterFrameHandlers` + the var-map variant). The
  heartbeat showed `flush == tick` every tick and `rootEF=1` — the root
  `onEnterFrame` (Tetris's `func_anonymous_0`) fired exactly once. That handler
  is just the **preloader** (`getBytesLoaded` vs `getBytesTotal` → `NextFrame`,
  then `delete this.onEnterFrame`), not the game loop. So `onEnterFrame` was a
  red herring.

- **The timeline parks correctly.** Heartbeat trace:
  `cf=1` (menu) → `cf=2` (level-select) → (OK) `cf=11 play=1` → **stable
  `cf=23 play=0`**. Frame 23 **is** the game frame; the game's `stop()` holds it
  there. It does not "free-play"; the cont. 31 wording was an over-read.

- **The real gap: `setInterval` never fires in browser-WASM.** Tetris's entire
  fall mechanic is `timeout = setInterval(down, speed)` (`func_anonymous_9`,
  `str_53="speed"`/`str_54="down"`). `setInterval`/`setTimeout` callbacks are
  driven by `processTimers`, and the **only** `processTimers` call site in
  `swf.c` (line ~1022) lives inside the `#ifdef OFFSCREEN_RENDER` per-tick block.
  Browser-WASM (`#ifndef OFFSCREEN_RENDER`) never called it. The heartbeat
  confirmed it: at `cf=23` the game registered the interval (`timers=0→1`), the
  pump fired it, the piece fell and stacked until it topped out (no lateral
  input in the harness) → `clearInterval` (`timers→0`), `score=56`.

`processTimers` is the same function the entire trace test suite relies on
(every `actionscript.all` test uses `setInterval(checkIt, …)`); it is well
exercised in NO_GRAPHICS/OFFSCREEN. Browser-WASM was simply missing the call.

## The fix

`SWFModernRuntime/src/libswf/swf.c` `tagMain` — add a per-tick timer pump to the
browser-WASM main `while(1)` loop, right after the `#ifdef OFFSCREEN_RENDER`
post-frame block and before frame advance, gated
`#if !defined(OFFSCREEN_RENDER) && defined(__EMSCRIPTEN__)`:

```c
extern void processTimers(SWFAppContext*, double);
extern void actionFlushPendingOnLoads(SWFAppContext*);
double timer_dur_ms = (app_context->fps > 0) ? (1000.0 / app_context->fps) : 83.33;
actionFlushPendingOnLoads(app_context);
processTimers(app_context, timer_dur_ms);
actionFlushPendingOnLoads(app_context);
```

Deliberately **minimal**: only the timer-side pumps that have no browser-WASM
equivalent. Sprite advance, `onEnterFrame`/clip-event dispatch, and `AQ_KIND_LOAD`
drains already run per tick inside `tagShowFrame` (called from each `frame_func`),
so the rest of the OFFSCREEN cluster is intentionally **not** duplicated (doing so
would double-pump those). The `actionFlushPendingOnLoads` brackets mirror the
OFFSCREEN cluster so an `onLoad` chain queued by a timer callback drains the same
tick.

Placed in the main loop (not the post-quit drain loop at the bottom) because
Tetris never quits — it parks at `cf=23` with `quit_swf` unset, so it stays in
the main loop forever. A game that ends its root timeline (`quit_swf`) and relies
on timers in the drain phase would still not get them; left as a known follow-up
(no current game needs it).

## Regression check (DJ / Snake / Pong / others)

`processTimers` is a strict no-op when `hasActiveTimers()==0`, so games without
`setInterval`/`setTimeout` are unaffected. Static scan of `RecompiledScripts`:

- **Snake, Pong (glaiel), Pacman, Bloons, Checkers, Minesweeper, N, Storm the
  House, Tron, Shopping Cart Hero(*):** 0 timer call sites → no-op, zero risk.
- **Doodle Jump:** 4 `setInterval` sites, but all in its **sponsor/analytics
  subsystem** (`checkStatusMovie` / `onLoadSpy` / `$mcSpy` / `_sendInfos` /
  `idIntervalCheckLoading`, registered by `script_15` methods), not gameplay
  (DJ's hero physics is clip-event driven). Rebuilt DJ wasm with the new runtime
  and smoke-tested in the browser (`tools/divergence/game_drive/dj_smoke.py`):
  menu renders identically, runs 12 s with the timers now live, **no
  error/abort/exception/hang** in the console. DJ gameplay (hero bounce) is
  unchanged. (Recommend a manual full play-test of DJ at some point, since DJ's
  deeper states need a human input loop — but no regression observed.)

(*) Shopping Cart Hero's hit was `setInterval` string presence; its core is a
1-frame root, separately tracked.

## Verification

- `tetris_compare.py` → `compare_ok.png`: SWFRecomp shows tetris pieces falling
  and stacking on the board, `score` incrementing (56 in the final run), next-piece
  preview + level/lines/score panel + quit/pause buttons + "tetris" logo all
  correct. Before this fix the board was static and the game unplayable.
- Final build verified diagnostic-free (`strings Tetris.wasm | grep -c PMDIAG` = 0).

## Process notes

- Re-confirming the handoff's root cause with fresh instrumentation (heartbeat +
  counters) before coding was decisive — the suspected `onEnterFrame` gap was a
  red herring; the actual gap was `processTimers`. (Same lesson as
  `browser-wasm-visible-and-nonroot-attach-render`.)
- The harness only logs console lines containing the literal `PMDIAG`; a marker
  without that substring is silently dropped (cost one rebuild — name diagnostic
  prints `PMDIAG …`).

## Still open (separate, unchanged)

- Italic-digit "1"→"/" glyph slant (deprioritized).
- DJ/Snake/Pong manual re-check for cont. 29 fix #3 (`gotoAndStop`→`ng_gotoFrameByMC`).
- Post-quit drain loop does not pump `processTimers` (no current game needs it).
