# 2026-05-25 — Pong "Stuck at Preloader" Browser-WASM Diagnosis

**Status:** Phase 0 of the [browser-WASM testing plan](../plans/browser-wasm-testing-plan.md).
**Goal:** Characterize why the deployed Pong demo hangs at its preloader
in the browser even though the same SWF passes the headless-graphics
divergence harness cleanly.

## TL;DR

- **Diagnosis category:** "Loads but stuck" — Pong's preloader renders
  correctly (Glaiel Games logo + a filled "Loading" bar on notebook-paper
  background). Confirmed visually with the screenshot below. The root
  timeline never advances past frame 0.
- **Root cause:** `advance_sprite_frames` in `tag.c:992-997` skips
  1-frame parent sprites entirely after `just_allocated`, so the inline
  recursion at line 1090 that would otherwise advance the parent's
  nested children never runs. Pong nests a 3-frame loop sprite (sprite_9
  — the load-progress loop with `_root.play()` inside) inside a 1-frame
  container sprite (sprite_10, the preloader root). On tick 1, sprite_10
  is `just_allocated`, sprite_9 runs frame 0 (queues `_parent.stop()`)
  and bumps its `current_frame` to 1. On tick 2 onward, sprite_10 is
  skipped at line 997, the recursion at line 1090 never executes, and
  sprite_9 never runs frame 1 (the `_root.play()` script). Root stays
  on frame 0 forever.
- **Why it works in `--mode=graphics` (OFFSCREEN_RENDER):** that build
  uses a separate `advance_nested_sprite_frames` pass (`tag.c:1128`,
  called from `swf.c:659` only under `#ifdef OFFSCREEN_RENDER`) that
  iterates every sprite's display-list regardless of frame count, with
  a `placed_at_tick == g_tick_count` deferral guard (the Pong fix from
  commit `fd99759a0`). Browser-WASM never calls that function.
- **The `_root.play()` hypothesis from the plan is invalidated.** The
  preloader script doesn't reach the `_root.play()` call at all because
  the script itself never runs. The browser-arm `actionCallMethod` play
  arm is fine for this symptom (though it does still need the
  `mc == &root_movieclip` short-circuit eventually — see follow-up).
- **No runtime fix landed.** The fix touches the sprite advance
  pipeline (well-tested under OFFSCREEN_RENDER, untested for
  browser-WASM nested children), so it deserves a focused session with
  the Phase 1 harness in place. Three candidate fixes outlined below;
  spec'ing them is itself a non-trivial decision.

## How I got here

This diagnosis had a wrong turn that the user corrected — included
here so future-me doesn't repeat it.

### Wrong turn: "the canvas is blank, nothing rendered"

Initial probing under Playwright headless + swiftshader produced
byte-identical pure-white snapshots of the canvas for both Pong and
Snake. I wrote the first version of this doc concluding "loads but
renders nothing" and recommended chasing renderer bugs first. The
user pointed out that the demos actually render correctly when
opened in a real browser; only my screenshot path was broken.

### Why it was broken

Playwright headless on Linux uses Chromium's `headless_shell`, which
**does not have a real WebGPU compositor**. The WebGPU canvas's
surface texture is rendered into Dawn's internal target but never
composited into the visible viewport that the Page-level screenshot
API captures. Specific failure modes I confirmed across configs:

| Config | adapter | Snapshot of canvas |
|---|---|---|
| Playwright bundled `chromium_headless_shell` + swiftshader | yes (swiftshader) | **blank white** |
| System Chrome 138, `headless=False` (WSLg DISPLAY) | yes (swiftshader) | **renders correctly** (visually) |
| System Chrome 138, `--headless=new` + swiftshader | yes (swiftshader) | blank white |
| System Chrome 138, `headless=False` + `--use-angle=vulkan` | yes (still falls back to swiftshader because Vulkan isn't ready on this WSL2 install) | blank white |
| Xvfb-wrapped headed Chrome + swiftshader | yes (swiftshader) | blank white (no GPU) |

The only path that captures real canvas content is **headed Chrome
with a real display server attached (WSLg here)**, AND specifically
`page.locator("#canvas").screenshot()` — Playwright's
`page.screenshot()` and CDP `Page.captureScreenshot` (both
`fromSurface: true` and `false`) all return white for the canvas
region even when the canvas is visibly drawing on screen.

I confirmed this by capturing all four methods in parallel against
the same headed page (probe3.py). All four produced byte-identical
"blank" output for the canvas region in Pong's case except
`locator("#canvas").screenshot()`, which returned the actual canvas
pixels — see screenshot below.

### CI implication

Phase 5 cannot use the obvious "Playwright + headless Chromium"
recipe to capture per-frame canvas pixels. Options for the CI design:

- Run an **Xvfb + a real GPU**. GitHub `ubuntu-latest` runners don't
  have GPUs.
- Use **Lavapipe** (software Vulkan) inside Xvfb. Slow but it gives
  Chromium a real Vulkan backend, which `--use-angle=vulkan`
  WebGPU can present through. Worth trying. Documented mitigation
  in the plan's Risks table.
- Make the runtime export a **WebGPU readback path** — configure the
  canvas surface for `COPY_SRC` usage and add a `_captureCanvas`
  export that reads the surface texture back into a CPU buffer. This
  bypasses the headless compositor entirely. Phase 2-territory but
  the right long-term answer.
- For trace-only assertions (Phase 3), no canvas capture is needed,
  so headless works fine.

## What's actually broken in Pong

### The preloader rendering correctly

`locator("#canvas").screenshot()` of headed Chrome at t=1s and t=8s
are byte-identical: same notebook-paper background, "Loading" text,
fully-filled loading bar, "Glaiel Games.Com" caption. The preloader
graphics ARE on screen; the timeline just never advances. This is
exactly the symptom the user reported.

(Screenshot: `/tmp/pong-probe/pong_state/pong_t01s.png`.)

### What the runtime is actually doing

Instrumented build (`-DPONG_PROBE`, `fprintf(stderr,...)` at the top
of `actionCallMethod`, in `actionPlay`, in `actionStop`, and in the
MOVIECLIP-arm play/stop dispatchers). Eight seconds of running Pong
produced:

- **2183 `actionStop` calls**, all from `script_0` (the root
  frame-0 stop), with `targeted_sprite=NULL` and setting `is_playing=0`.
  The first stop saw `is_playing(before)=1`; all subsequent stops saw
  it already at 0. The root frame 0 re-executes every tick, calling
  `actionStop()` directly (not via CallMethod) → no progress.
- **0 `actionPlay` calls.** Never. Confirms `_root.play()` is never
  reached.
- **1 `actionCallMethod` entry**, in the entire 8 seconds, for
  method `"stop"`. That's the one-shot `_parent.stop()` from
  sprite_9 frame 0 (script_1) on tick 1.
- **0 calls** for `play`, `getBytesLoaded`, `getBytesTotal`, or
  `_width` set on `progbar` — none of the preloader-progress
  arithmetic happens. (This is also why the loading bar appears
  "fully filled" — it's actually unchanged at its asset-defined
  default width because `progbar._width = ...` never runs.)

So sprite_9's frame_funcs[1] (which queues `script_2`, which contains
`_root.play()`) is never called after tick 1.

### Why sprite_9 stops advancing

Pong's display hierarchy on root frame 0:

```
root frame 0
├── depth 1: shape (background notebook paper, charId 2)
├── depth 2: sprite_4 (Glaiel logo, 1 frame, charId 4)
└── depth 4: sprite_10 (preloader container, 1 frame, charId 10)
    ├── depth 1: shape (charId 5, "Loading" text)
    └── depth 2: sprite_9 (3 frames, charId 9 — the load-progress loop)
        ├── frame 0: places `progbar` + queues `script_1` (_parent.stop())
        ├── frame 1: queues `script_2` (check progress, _root.play() if 100%)
        └── frame 2: queues `script_3` (gotoAndPlay(1))
```

`script_0` on root frame 0 calls `actionStop()`. The preloader pattern
relies on sprite_9 cycling between its frames 1 and 2 until the load
completes, then calling `_root.play()` to advance the root past frame 0.

Trace through `advance_sprite_frames` (tag.c:768) in browser-WASM
**tick 1** (root display_list iteration):

- depth 2 (sprite_4, 1 frame): `just_allocated=1`, runs frame_0
  (calls placement function). Then 1-frame so doesn't advance. Recurses
  into sprite_4's display list (no nested sprites).
- depth 4 (sprite_10, 1 frame): `just_allocated=1`, runs
  sprite_10_frame_0 (places progbar shape + sprite_9 inside sprite_10's
  display list). Then 1-frame, doesn't advance. Recurses into
  sprite_10's display list:
  - depth 2 (sprite_9, 3 frames): `just_allocated=1`, runs
    sprite_9_frame_0 (queues script_1, places content). Advances:
    `sprite_current_frame = (0+1) % 3 = 1`.

End of tick 1: AQ has `script_1` pending. sprite_9.current_frame=1.

**Tick 2** (root re-runs frame_0 since `is_playing=0`):

- `actionDrainAllInPriorityOrder` drains script_0 (root actionStop)
  and script_1 (`_parent.stop()` → the one CallMethod we saw).
- frame_0 re-places, calls tagShowFrame, calls advance_sprite_frames.
- advance_sprite_frames on root display_list:
  - depth 4 (sprite_10): **`just_allocated=0`, `sprite_frame_count<=1`
    → line 997 `continue`**. Recursion at line 1090 is skipped.
- sprite_9 never runs.

This is the bug. Snake works because Snake's menu doesn't have a
similar 1-frame-wrap-around-multi-frame nesting.

### Why OFFSCREEN_RENDER doesn't hit this

`swf.c:570` calls `advance_sprite_frames(app_context)` with
`g_advance_defer_nested = 1`, so the inline recursion at line 1090
is skipped. Then `swf.c:659` calls `advance_nested_sprite_frames`
(`tag.c:1128`), which iterates **every** sprite in the root
display_list (regardless of `sprite_frame_count`), swaps into each
one's display_list, and recursively advances. Line 1185's
`placed_at_tick == g_tick_count` skip (the Pong fix from commit
`fd99759a0`) handles the "newly placed sprite shouldn't advance this
tick" case orthogonally. So under OFFSCREEN_RENDER, sprite_10's 1-frame
status doesn't block sprite_9 from being visited.

Browser-WASM has no `advance_nested_sprite_frames` call site at all.
The whole pipeline relies on the inline recursion in
`advance_sprite_frames`, and that path is gated by line 997.

### Memory note (mostly) correct after all

The MEMORY.md note on `placed_at_tick`:

> The Pong fix from this session (Option B, `placed_at_tick ==
> g_tick_count` skip) is therefore vacuously inert in the browser
> path — the field is stamped by `tagPlaceObject2` but never read.

That's correct as stated — the `placed_at_tick == g_tick_count` skip
lives at `tag.c:1185` inside `advance_nested_sprite_frames`, which
browser-WASM never calls. The corollary: browser-WASM doesn't have
the "Option B" Pong fix at all. But it ALSO doesn't have the
underlying nested-advance machinery that the Option B fix was
guarding — so just porting Option B over isn't a fix; the missing
machinery is the underlying problem.

## Recommended fix (deferred; outline only)

Three candidates, in order of how I'd rank them:

### Candidate A: Call `advance_nested_sprite_frames` from tagShowFrame's browser-WASM branch

Currently tagShowFrame's `#else` branch (`tag.c:3349-3373`) does:

```c
advance_sprite_frames(app_context);    // with g_advance_defer_nested = 0
```

Change to mirror swf.c's OFFSCREEN_RENDER pattern:

```c
g_advance_defer_nested = 1;
advance_sprite_frames(app_context);
g_advance_defer_nested = 0;
advance_nested_sprite_frames(app_context);
```

This is the smallest delta and matches the proven OFFSCREEN_RENDER
ordering. The `placed_at_tick == g_tick_count` deferral in
`advance_nested_sprite_frames` would then activate for browser-WASM
too, preventing the "Pong sprite_9 advances one tick early" bug the
fd99759a0 fix originally addressed.

Risks: `advance_nested_sprite_frames` was written under OFFSCREEN_RENDER
test coverage; it may call into helpers that misbehave under
browser-WASM (`g_current_context` handling, `actionFindOrCreateMovieClip`
vs `actionFindMovieClipByName` differences). Phase 1 harness should
land first so we can smoke-test 5+ demos after the change, not just
Pong.

### Candidate B: Move the inline recursion above the 1-frame skip

Cheaper local edit in `tag.c:992-997`:

```c
if (!obj->sprite_is_playing) continue;
// (recursion block from line 1086-1107, moved up here, run unconditionally)
if (ch->sprite_frame_count <= 1 && !just_allocated) continue;
```

Pro: tiny diff. Con: the recursion path also does `process_sprite_needs_init`
under `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` and uses
`g_advance_defer_nested` — calling it for 1-frame parents in browser-WASM
without working through the full state-machine implications could create
new bugs. And it still doesn't get the `placed_at_tick` deferral that
Candidate A inherits for free.

### Candidate C: Only recurse for 1-frame parents that have multi-frame children

Local edit at `tag.c:997` to do a cheap check before `continue`:

```c
if (ch->sprite_frame_count <= 1 && !just_allocated) {
    /* Still need to advance nested multi-frame children. Check before skipping. */
    if (sprite_has_multi_frame_descendants(obj)) {
        /* fall through to recursion only */
    } else {
        continue;
    }
}
```

This is finer-grained but requires writing the predicate and proving
it doesn't miss cases. I would not start here.

## Other follow-ups (still real, not the immediate cause)

### Browser-arm `_root.play()` short-circuit

The `mc == &root_movieclip` short-circuit from commit `6fe6fb1a2`
is still missing from `actionCallMethod`'s browser arm at
`action.c:63462-63527`. It does not cause the current Pong-stuck
symptom (the script never reaches the play call), but once Candidate
A/B/C lands and script_2 actually runs, the existing browser-arm
`actionPlay` call path *should* work correctly for the
`targeted_sprite==NULL` case (which is what the preloader pattern
will hit). The 6fe6fb1a2 short-circuit becomes important again when
the preloader is *inside a SetTarget'd context*, which Pong isn't.
Still worth adding for correctness — three-line copy of the existing
NO_GRAPHICS/OFFSCREEN_RENDER short-circuit, with `!defined(NO_GRAPHICS)
&& !defined(OFFSCREEN_RENDER)` gating. Bundle into the same PR as the
fix above.

### `SWF_FILE_SIZE` is never defined

`getBytesLoaded()` and `getBytesTotal()` both read `mc->byte_size`
(`action.c:64962`, `64969`). For `root_movieclip`, that field is
populated by `swf.c:1098-1103` only when the macro `SWF_FILE_SIZE`
is defined — and a grep of the entire repository shows it's
referenced in three swf*.c files but never *defined* anywhere. So
when Pong's `script_2` eventually runs (after the fix above), it
will compute `bytesLoaded / bytesTotal = 0 / 0 = NaN`, set
`progbar._width = NaN`, and the `bytesLoaded < bytesTotal` check
will be `false` (NaN comparisons are false), so the play call still
fires — by accident. Worth fixing but downstream of the main bug;
the recompiler should emit `#define SWF_FILE_SIZE <N>` into
constants.h alongside the existing `SWF_FRAME_COUNT`, `SWF_VERSION`
defines.

## WebGPU/Chromium flags for this machine

For local probes (headed mode via WSLg `DISPLAY=:0`):

```
executable_path=/usr/bin/google-chrome
channel=None
headless=False
args=[
    "--enable-unsafe-webgpu",
    "--ignore-gpu-blocklist",
    "--no-sandbox",
]
```

Snapshot method that actually captures content:

```python
await page.locator("#canvas").screenshot(
    path=str(out_png),
    animations="allow",
    timeout=8000,
)
```

Read C strings from JS:

```js
const getJson = Module.cwrap("getDisplayListJSON", "string", []);
console.log(getJson());
```

`Module.HEAPU8` / `Module.UTF8ToString` are not exported by default
(only `ccall`, `cwrap`, `HEAPF32` are in the current
`-s EXPORTED_RUNTIME_METHODS`). Phase 2 may want to add `HEAPU8`,
`UTF8ToString`, `lengthBytesUTF8` for harness flexibility, but
`cwrap` with `return_type='string'` covers most cases.

## Probe artifacts (throwaway, not committed)

- `/tmp/pong-probe/probe.py` — initial broken-screenshot version.
- `/tmp/pong-probe/probe3.py` — multi-capture-method comparison.
- `/tmp/pong-probe/probe4_headless.py` — tested 3 headless configs;
  all produced blank canvas.
- `/tmp/pong-probe/probe5_pong_state.py` — the working probe.
  Headed Chrome via WSLg, `locator("#canvas").screenshot()`,
  display-list polling via `cwrap`.
- `/tmp/pong-probe/pong_state/pong_t01s.png` — Pong preloader
  rendered (visible Glaiel logo + filled Loading bar).
- `/tmp/pong-probe/run_capture_methods/t01_D_locator_canvas.png` —
  same content via the locator method.
- `/tmp/pong-probe/headless_tests/sys-chrome-headless-new_t05.png`
  — proof the headless path renders blank.

The Pong WASM in `docs2/examples/glaiel/Pong/` is rebuilt at HEAD
(no instrumentation). The instrumentation patch lived only in the
working tree during the session and has been reverted; `git status`
is clean apart from this doc.
