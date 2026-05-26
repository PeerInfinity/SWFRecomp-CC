# 2026-05-25 — Doodle Jump browser-WASM, bounce fix landed

Fifth handoff in today's chain:

1. `2026-05-25-doodle-jump-browser-investigation.md` — initial
   investigation + cycling-bug diagnosis.
2. `2026-05-25-doodle-jump-followup.md` — cycling fix landed
   (`98b388e46`).
3. `2026-05-25-doodle-jump-clip-events.md` — clip-event LOAD /
   ENTER_FRAME dispatch wired (`3ac27552e`).
4. `2026-05-25-doodle-jump-audit.md` — 22-gate audit landed
   (`c9b11cc99`). Bug A fixed, bug B partially fixed.
5. **This doc** — bug B root-caused and fixed.

## TL;DR

- **Bug B FIXED.** Doodle Jump hero now bounces visibly on the menu
  block in browser-WASM. Per-tick AS state byte-identical to
  graphics-native through t=30 (vy=4,8,12,15,−5,−10,−15,−16,−12,...
  matches exactly).
- **Root cause:** three more instances of the "browser-WASM was the
  afterthought" gate-asymmetry pattern in `tag.c` (cached transform
  caching, shape-bounds registration) and `action.c`
  (`mcGetOriginalBounds`, `mcGetEffectiveSize`, `hitTest`).
- **Diagnosis tool:** per-tick AS state dump comparing graphics-native
  vs browser-WASM identified `yradius=0` (browser) vs `yradius=22.5`
  (native) on t=2 as the first divergent value, then a follow-on
  hitTest dump showed degenerate (zero-extent) bounds caused by
  uncached `place_a/b/c/d`.
- **No regressions.** Trace harness 407=407. Pong + Snake browser
  demos byte-identical to baseline.

## What landed

Two files: `SWFModernRuntime/src/libswf/tag.c` and
`SWFModernRuntime/src/actionmodern/action.c`. Net +11 / −36.

### Group 1: `ng_cache_transform` (tag.c)
Function was gated `#if NO_GRAPHICS || HEADLESS || OFFSCREEN_RENDER`,
meaning browser-WASM never populated `display_list[*].place_a/b/c/d/
tx/ty`. Made the function unconditional (with `extern` declaration of
`g_active_transform_data` for browser-WASM — graphics_stubs.c
provides the storage). Dropped 4 `#if` gates around call sites in
`tagPlaceObject2` and `tagPlaceObject2Ratio`. Browser-WASM now caches
per-placement transform corners so `ng_computeBoundsFromDL_matrix`
produces correct AABBs instead of collapsing to a single point at
the placement translation.

### Group 2: shape-bounds recording (tag.c)
Three gates dropped on `ng_record_char_bounds` /
`ng_record_morph_end_bounds` calls in `tagDefineShape`,
`tagDefineMorphShape`, `tagDefineText`. Without these, browser-WASM's
char-bounds registry was empty and `ng_getCharBounds()` returned 0 for
every shape, so the bounds recursion in `ng_computeBoundsFromDL_matrix`
bottomed out at zero-extent.

### Group 3: AS-side bounds + hitTest (action.c)
Three gates dropped in `actionCallMethod` and the
`mcGetOriginalBounds` / `mcGetEffectiveSize` helpers:
- `mcGetOriginalBounds` body — was gated entirely, fell through to
  `0,0` for browser-WASM. Without it, `_width`/`_height` returned 0.
- `mcGetEffectiveSize` matrix-corner branch — the
  `if (!(mc->as_set_flags & (4|8|16)))` corner-AABB path was gated.
  Without it, browser-WASM's fall-through used `nat_w * mc->xscale /
  100.0` with `nat_w=0` (since `mcGetOriginalBounds` returned 0).
- `hitTest` body — the entire point-in-AABB + shape-flag-refine
  implementation was gated, with the `#endif` directly followed by
  `pushUndefined`. So in browser-WASM, *every* `mc.hitTest(x, y, sf)`
  call returned undefined, which evaluates as false. Doodle Jump's
  `_root.block.hitTest(...)` therefore never bounced even when the
  point was inside the block.

## How the diagnosis went

Per the audit handoff's suggestion: I added a per-tick state dump in
`actionDumpDJState()` (called from `tagFlushPendingEnterFrame` after
both CLIP_EVENT_ENTER_FRAME and onEnterFrame dispatch), gated on
`-DDJ_DEBUG_DUMP`. The dump prints `hero._y`, `vy`, `jump`, `yradius`
and `block._y`. Plumbing: env-var `VERIFY_EXTRA_DEFINES` for the
graphics-native build (via `tools/divergence/run_swfrecomp.py`) and
`EXTRA_BUILD_DEFINES` for browser-WASM (via `build_test.sh`).

First diff appeared at t=2: graphics-native `yradius=22.5`,
browser-WASM `yradius=0`. The LOAD handler computes
`this.yradius = hero._height / 2`, so `_height` was broken.

Tracing `_height` → `mcGetEffectiveSize` → `mcGetOriginalBounds` →
both gated → fall-through to `mc->width` = 0. Widening those two
gates fixed `_height` but the bounce still didn't fire. Adding a
hitTest-side dump showed `block.hitTest(...)` was returning
degenerate bounds `g=(1047.0-1047.0,6182.0-6182.0 twips)` — a single
point at block's placement translation. That pointed at uncached
`place_a/b/c/d` (block's child shape was being transformed by
`na = ma*0 + mc*0 = 0`, so the 4 corners all collapsed to the
translation). Widening `ng_cache_transform` gates fixed that. Final
gate widened was hitTest itself — the entire body was gated, so even
with correct bounds the function still returned undefined.

After all six gates widened, browser-WASM's per-tick state dump
became byte-identical to graphics-native's through t=30. Bounce
visible at t=6: vy goes 15 → −5 (gravity − jumpspeed).

All instrumentation removed in the final commit. Cleanup is verified
clean: no `DJ_DEBUG_DUMP` / `actionDumpDJState` / debug printf /
env-var hooks remain.

## How to reproduce
```
source emsdk/emsdk_env.sh > /dev/null 2>&1
SWFRecomp/scripts/build_test.sh flasharchive/Doodle_Jump wasm --graphics
SWFRecomp/scripts/deploy_example.sh flasharchive/Doodle_Jump \
  "$(pwd)/docs2/examples" --no-index --graphics

source /tmp/pong-probe/venv/bin/activate
python3 tools/browser-test/probe.py flasharchive/Doodle_Jump \
  --wall-clock-seconds 8 --snapshot-interval-seconds 1 \
  --screenshot-timeout-ms 30000 --out /tmp/dj-bounce-check
```

Pass criteria:
- Menu screen shows "play" / "info" / "score" / "options" buttons.
- `unique_canvas_sizes` ≥ 5 (hero bouncing causes the canvas to
  change every tick).
- Hero `_y` from `display_list/tNN.json` (entry at depth=9) stays
  between ~180 and ~290 px across t01..t08 (cycle of bounce up and
  fall down between hero's peak around y=200 and the block at y=309).

## Don't-touch list (unchanged from audit)

The 9 gates listed in handoff #4 are still real `#else` forks (the
`_x`/`_y`/`_xmouse`/`_ymouse` readers, `_xscale`/`_yscale`/`_rotation`
sync calls, `scroll`/`hscroll` maxscroll caches). They were
intentionally kept.

## Pattern note (6th instance)

The audit handoff predicted "166 in action.c — many are legitimate
but more remain that may be hiding similar AS-leak bugs in other
functions." This session found three more in `action.c`
(`mcGetOriginalBounds`, `mcGetEffectiveSize`, `hitTest`) and three in
`tag.c` (bounds-recording in three Define* functions, plus the cached
transform caching) — the latter being the *first* gate-asymmetry
instance found in `tag.c`. The "59 in tag.c — almost all are
render-side and probably fine" claim was off: these six gates were
populating data structures consumed by AS-side getters and hitTest.

The diagnosis pattern (per-tick AS state dump → first divergent value
→ trace through the getter to gated body → widen gate) generalizes
well. The dump itself is a reusable diagnostic — kept the dump
instructions in this doc rather than committing the code.

The remaining `tag.c` gates are worth a similar systematic scan,
prioritizing functions that populate `display_list[*]` fields read by
AS-side code, in case other AS-visible properties (drag boxes,
filter outlines, color transform inheritance) silently return wrong
values in browser-WASM today.

## Tools / state

- Local Ruffle source: `~/CC/ruffle`
- MTASC: `~/CC/mtasc/bin/mtasc`
- Probe venv: `/tmp/pong-probe/venv`
- Latest known-good probes:
  - DJ (bounce fixed): `/tmp/dj-final/`
  - Pong (regression baseline): `/tmp/pong-after-fix/`
  - Snake (regression baseline): `/tmp/snake-after-fix/`
