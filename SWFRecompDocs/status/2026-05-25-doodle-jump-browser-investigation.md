# 2026-05-25 — Doodle Jump Browser-WASM Investigation

**Status:** Partial progress. Trace divergence harness clean (407=407). Three
real bugs landed in fixes today. The visually-obvious "hero with jetpack
rapidly flipping + block intact/broken cycling" bug remains unresolved
and is what this doc hands off to the next session.

**Branch state at writing:** `master`, ahead of `origin/master` by 4
commits (all from today). Working tree clean. Push when ready.

## TL;DR

- **What's fixed:** Trace harness (graphics-native, `OFFSCREEN_RENDER`)
  reports identical traces between SWFRecomp and Ruffle — 407=407 lines —
  with the extended `Tracer.as` that now also dumps
  `_xscale/_yscale/_rotation/_alpha`. AS-state divergences are zero.
- **What's broken in browser-WASM** (the deployed
  `docs2/examples/flasharchive/Doodle_Jump/` demo):
  - Hero sprite cycles through 4 internal frames (standing /
    jetpack-left / jetpack-down / antennas-up) despite a `stop()` in its
    frame-0 script that does take effect in graphics-native.
  - Block (platform) sprite cycles between intact and broken visuals
    in the same loop.
  - Button labels stay as the static "menu" placeholder rather than the
    script-set "play"/"info"/"scores"/"options".
  - This is **only** in browser-WASM. The exact same recompiled C code
    runs correctly under graphics-native (`OFFSCREEN_RENDER` defined).
- **Most likely root cause:** the recurring pattern that every other
  bug today fit — render/script code gated
  `#if defined(HEADLESS_GRAPHICS) || defined(OFFSCREEN_RENDER)` that
  silently excludes browser-WASM (`USE_WEBGPU` only). 5 such sites
  remain in `tag.c`; one of them is plausibly the sprite-advance gap.
  See "Best leads" below.

## Today's commits

```
0a7567a28  browser-WASM: register EditText props, dedup function_registry
faee65274  tag: skip static glyph render for EditTexts in browser-WASM too
57a2aa69e  tracer: dump _xscale/_yscale/_rotation/_alpha per MC
221a61afc  action: three fixes from Doodle Jump divergence trace
```

Each is independently useful; none of them is the fix for the
remaining sprite-cycle bug.

### What each commit fixed

- **`221a61afc`** — the three AS-state bugs the divergence harness
  surfaced:
  1. `actionGetMember` MOVIECLIP receiver didn't walk the prototype
     chain for `addProperty` getters (only checked own `dynamic_props`).
     SpyConnection1.prototype's `mcSpies` getter returned `undefined`
     instead of the actual MovieClip.
  2. `actionEnumerate2` MOVIECLIP branch skipped `createEmptyMovieClip`
     children that weren't on `sprite_display_list`. Added a
     `child_mc_cache` walk filtered by `parent == mc && display_obj == NULL`.
  3. `actionDeclareLocal`/`actionDefineLocal` colon-path resolution
     fell through to literal-name storage when resolution failed,
     leaking `var x:Boolean` as a property `"x:Boolean"` onto `_root`.
     Switched the gate from `g_call_depth == 0` to `scope_depth == 0`
     so scopeless type-1 callbacks also no-op silently.

- **`57a2aa69e`** — extended `Tracer.as` to also dump
  `_xscale/_yscale/_rotation/_alpha` per MC. Trace still 407=407 with
  the extra fields, which proves transforms aren't where the
  divergence is.

- **`faee65274`** — `tag.c:1631/1707` skip-static-glyph gates
  re-expressed as `!defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)`
  (was: `HEADLESS_GRAPHICS || OFFSCREEN_RENDER`). The new gate
  matches the `#if` around the `actionIterateTextFieldGlyphs` call
  site — wherever dynamic glyphs render, the static must skip.

- **`0a7567a28`** — two linked fixes:
  - `tag.c:tagDefineEditTextProps`/`tagCSMTextSettings`: removed the
    `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` gate that
    made these complete no-ops in browser-WASM. Browser-WASM had been
    seeing **zero** EditTexts registered, so `actionIterateTextFieldGlyphs`
    found nothing to render and the static-glyph skip from `faee65274`
    couldn't recognize any char as an EditText.
  - `actionDefineFunction`/`actionDefineFunction2`: dedup by name
    before appending to `function_registry`. Without this, the
    EditText fix above tripped 204 "Function registry full" errors
    in seconds — AS scripts re-define SpyConnection1 prototype methods
    every timeline loop, and the registry filled `MAX_FUNCTIONS=2048`
    fast. `lookupFunctionByName` already reverse-searches and returns
    the most recent match, so replacing in place preserves semantics.

## The remaining bug

### Visible symptom

Hero in the deployed browser demo cycles through ~4 visual states
once per ~200ms:

| State | Content |
|---|---|
| 1 | doodle standing |
| 2 | doodle with antennas up |
| 3 | doodle with rocket flame to left |
| 4 | doodle with rocket flame below |

The block at bottom-left similarly toggles between intact-green and
broken-brown.

Confirmed with the Playwright probe:

```
python3 tools/browser-test/probe.py flasharchive/Doodle_Jump \
    --wall-clock-seconds 10 --snapshot-interval-seconds 1 \
    --screenshot-timeout-ms 30000 --out /tmp/dj-probe6
# unique_canvas_sizes: 4
# canvas_snapshots: 10 ok, 0 error
# display_list_counts: stable at 9 (root level identical to Ruffle)
# error count: 0
```

The display list at the root is identical to Ruffle; the divergence is
inside multi-frame sprites (hero = char 40, block = char 27 — both have
multiple frames defined in `RecompiledTags/tagMain.c`).

### What I've ruled out

- **Not compare=true / Ruffle interference.** I initially suspected
  this because the user said "I see flipping with compare=true"; my
  probe at compare=true reproduced it; my probe without compare did
  not. But the latter was under-sampling (only 1 successful canvas
  snapshot — Playwright's stability check timed out on the others).
  After raising `--screenshot-timeout-ms` the bug reproduces cleanly
  without compare. User confirmed: "same with or without compare=true."
- **Not the function-registry overflow.** Today's dedup fix took the
  symptom from 204 errors to 0, but the visible-frame cycling is
  unchanged. The overflow was a side effect of EditText scripts
  finally running.
- **Not anything visible at root display-list level.** Probe's
  `getDisplayListJSON` dump shows hero and block placed at correct
  positions with `_currentframe = 1` per the root entry. The
  divergence is at sprite-internal frame indexing or rendering.
- **Not AS state.** The graphics-native trace harness reports
  `_root.hero._cf=1` and `_root.block._cf=1` stable across 30 ticks,
  with `_xscale/_yscale/_rotation/_alpha` all matching Ruffle. The
  same recompiled C code runs in browser-WASM with a different
  `#ifdef` set.

### Best leads

1. **`swf.c:562-585` only calls `advance_sprite_frames` under
   `#ifdef OFFSCREEN_RENDER`.** Browser-WASM doesn't call it at all
   in that location. Yet the user observes sprite frames advancing
   in browser. Two possibilities:

   (a) Some other code path advances `sprite_current_frame` in
   browser-WASM that I haven't found. Searched `tag.c` and `swf.c`;
   only `ng_gotoFrameCurrentSprite` mutates it outside
   `advance_sprite_frames`, and that's gotoAndStop/Play-driven not
   tick-driven.

   (b) The sprite isn't advancing at all — the visible cycling is a
   render-side artifact. `tag.c:597` explicitly sets
   `obj->sprite_current_frame = 1` after frame-0 init runs inline. For
   the 4-frame hero, that points at frame index 1 (the second frame).
   If the render path picks up that index without `advance_sprite_frames`
   ever having syncing the sprite's display list, weird things could
   happen.

   The comment at `tag.c:583-595` explains why init sets `=1`: "Advance
   frame counter so `advance_sprite_frames` picks up at frame 1."
   That assumes `advance_sprite_frames` will run. In browser-WASM it
   doesn't. Possible fix: in browser-WASM, leave `sprite_current_frame=0`
   after init (since nobody's going to advance it), OR add the
   `advance_sprite_frames` call to browser-WASM's swf.c loop.

2. **Compare `swf.c` to `swf_core.c` for sprite logic.** `swf_core.c`
   is the NO_GRAPHICS / HEADLESS_GRAPHICS variant with the
   battle-tested loop. `swf.c` is the browser-WASM + OFFSCREEN_RENDER
   variant. Today's bugs have repeatedly been "swf.c was missing a
   block that swf_core.c has." `advance_sprite_frames` is called
   multiple times in `swf_core.c` (lines 995, 1094, …); only once in
   `swf.c` and only under `OFFSCREEN_RENDER`.

3. **The remaining 5 `HEADLESS_GRAPHICS || OFFSCREEN_RENDER` sites in
   `tag.c`** (lines 48, 1589, 1673, 2938; plus the inverse pattern at
   1364). Today I fixed the two `CHAR_TYPE_TEXT` skip gates. At least
   one of these others is plausibly hiding browser-WASM-specific
   behavior that's part of the sprite-frame bug.

### What I'd try first in a fresh session

Don't bother re-investigating "what's wrong." Just:

1. **Build with instrumentation:** Add `fprintf(stderr, …)` (or
   `console.log` via `EM_ASM`) to `tag.c` at every site that writes
   `sprite_current_frame`, dumping `obj->instance_name` /
   `obj->char_id` / new value / call-site. Rebuild WASM, re-probe.
   The output will show definitively whether sprite frames advance in
   browser-WASM and (if so) where.

2. **From there, two outcomes:**
   - If `sprite_current_frame` doesn't change but visuals do → it's a
     render-side bug. Look at how
     `obj->sprite_display_list` gets populated. The
     `tag.c:1009-1041` "frame 0 loop-back reset" block is gated
     `NO_GRAPHICS || OFFSCREEN_RENDER` — that might be the missing
     piece. Without it, browser-WASM may accumulate placements from
     multiple frames in one display list.
   - If `sprite_current_frame` IS advancing → find the advance call
     and check whether it should fire in browser-WASM. Most likely
     answer: `advance_sprite_frames` needs to be enabled in
     browser-WASM (drop the `#ifdef OFFSCREEN_RENDER` around the
     `swf.c:562-585` block).

3. **Don't chase the button-label "menu" issue separately yet.** It's
   probably the same root cause — the buttons are sprite instances
   too (`char_id=46` placed at depths 3/5/7/8), and the script that
   sets each button's text via SetVariable might require the same
   sprite display-list mechanism that's broken.

## How to verify a fix

Three checks:

1. **Trace harness still clean.** Must remain 407=407:
   ```
   python3 tools/divergence/divergence_test.py \
     SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf \
     --frames 30 --skip-ruffle
   ```

2. **Browser-WASM probe stable.** Hero stops cycling, button labels
   read play/info/scores/options:
   ```
   source emsdk/emsdk_env.sh > /dev/null 2>&1
   SWFRecomp/scripts/build_test.sh flasharchive/Doodle_Jump wasm --graphics --clean
   SWFRecomp/scripts/deploy_example.sh flasharchive/Doodle_Jump \
     "$(pwd)/docs2/examples" --no-index --graphics
   source /tmp/pong-probe/venv/bin/activate
   python3 tools/browser-test/probe.py flasharchive/Doodle_Jump \
     --wall-clock-seconds 10 --snapshot-interval-seconds 1 \
     --screenshot-timeout-ms 30000 --out /tmp/dj-probe-X
   ```
   Pass criterion: `unique_canvas_sizes: 1` once the menu has
   stabilized (allow t01 to differ as the initial frame). Check
   `canvas/tN.png` visually — hero should be standing, buttons
   labeled, block intact.

3. **Don't regress other browser-WASM demos.** Spot-check
   `glaiel/Pong` and `glaiel/Snake` (or a smaller one) with the
   probe. The function-registry dedup is the most likely thing to
   break unrelated code; the EditText fix is constrained to
   text-bearing demos.

## Pattern note for future browser-WASM bugs

Every bug landed today fit this template:

> A render-side or data-recording function in `tag.c` (or AS support
> in `action.c`) was gated `#if defined(HEADLESS_GRAPHICS) ||
> defined(OFFSCREEN_RENDER)`, with an `#else` no-op or sometimes
> just no `#else` at all. The two test modes (HEADLESS, OFFSCREEN)
> stayed correct because they were validated by the harness; the
> third runtime, browser-WASM (`USE_WEBGPU` only), was the
> afterthought. The fix is usually one of:
> - Drop the gate entirely (data recording is harmless).
> - Replace it with `!defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)`
>   to match the rendering path's existing gate.

If the next session hits a fourth instance of this pattern, that's
the cue to do a systematic audit of every
`HEADLESS_GRAPHICS || OFFSCREEN_RENDER` site rather than fix them
one at a time.

## Tools / commands quick reference

- **Trace divergence harness:**
  - `python3 tools/divergence/divergence_test.py <SWF> --frames N --skip-ruffle`
  - Re-runs the SWFRecomp graphics-native build and compares trace
    against Ruffle's. Compile step is ~25s.
  - Reads `tools/divergence/runs/<stem>/divergence.txt`.

- **Playwright browser probe:**
  - `python3 tools/browser-test/probe.py <demo-id> --screenshot-timeout-ms 30000`
  - Always use `--screenshot-timeout-ms 30000` (or higher) for
    continuously-redrawing demos. The default 8000 misses snapshots.
  - venv at `/tmp/pong-probe/venv` (activate with
    `source /tmp/pong-probe/venv/bin/activate`). Build fresh per the
    [browser-test-harness usage guide](../guides/browser-test-harness-usage.md)
    if that one's gone.
  - Outputs to `tools/browser-test/runs/<demo>/` by default; override
    with `--out`.

- **Extended Tracer.as fields:** dumps
  `_x _y _xs _ys _rot _a _cf _vis` per named MC at depth ≤3. Depth
  cap is intentional — increase `MAX_MC_DEPTH` in `Tracer.as` and
  re-run `tools/divergence/build_tracer.sh` if a future divergence
  is deeper.

- **Build WASM:**
  ```
  source emsdk/emsdk_env.sh > /dev/null 2>&1
  SWFRecomp/scripts/build_test.sh flasharchive/Doodle_Jump wasm --graphics --clean
  SWFRecomp/scripts/deploy_example.sh flasharchive/Doodle_Jump \
    "$(pwd)/docs2/examples" --no-index --graphics
  ```
  ~25-30s clean rebuild. The `docs2/examples/...` deploy is what the
  user-facing demo URL serves.

- **The deployed demo:** `<host>/docs2/demo.html?test=flasharchive/Doodle_Jump`
  - `compare=true` is harmless but adds a Ruffle player from CDN
    alongside ours; not needed for repro.
