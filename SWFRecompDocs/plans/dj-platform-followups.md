# Doodle Jump platform rendering — remaining follow-ups

Status as of commit `be332528c` (2026-05-29). This doc captures the platform
architecture, the fix already landed, and the four remaining (pre-existing)
bugs with root-cause hypotheses and suggested approaches, so a fresh session
can continue without re-deriving everything.

Related memory: `dj-platform-rendering` (in the auto-memory index).

---

## 1. Background: what was wrong, what's fixed

**Original report:** every Doodle Jump platform rendered green; blue (moving)
and brown (breakable) never appeared.

**Architecture (verified):** platforms are the exported **"cloud" sprite
(charId 27)**, a **4-frame** clip attached with
`attachMovie("cloud","block_N",depth)` to the **levelcontainer (charId 25)**.
The level script (`RecompiledScripts/script_defs.c`, the levelcontainer
`onEnterFrame` / `attachBlocks`) calls `block.gotoAndStop(N)` **inline inside
the attach while-loop** to pick the type:

| frame | gotoAndStop | charId placed | what it is | bitmap layer / colour |
|---|---|---|---|---|
| 1 | (none) | 29 (shape) | **green** normal | layer 5 (greenish) |
| 2 | `gotoAndStop(2)` | 31 (shape) | **brown** breakable | layer 6 (reddish/brown) |
| 3 | `gotoAndStop(3)` | 32 (**sprite** → 33 + **35**) | **blue** moving | charId 35 = layer 7 (bluish) |
| 4 | `gotoAndStop(4)` | 37 (**sprite** → 39) | 4th type | charId 39 = layer 8 |

Platform colour lives in the **bitmap** (identity cxform); the platforms are
bitmap-textured doodle art, NOT solid fills. `BITMAP_COUNT=18`. `defineBitmap()`
in `tagMain.c` assigns layers by call order. `draws.c` bitmap pixels are
**hex-encoded** (`0xNN`) — parse as hex. shape_data `col2`=style_type
(`0x41`=clipped-bitmap), `col3`=style_id (low16=bitmap layer, high16=inv-matrix).
The render shader (`render_webgpu.c` inline WGSL, NOT the unused
`flashbang/shaders/*.wgsl`) masks `style_type & 0xFFu`.

**Root cause of all-green:** the browser-WASM MC-targeted `gotoAndStop` handler
(`action.c`, the `#else` of the `NO_GRAPHICS||OFFSCREEN_RENDER` branch in
`actionCallMethod`) only set sprite-local nav flags
(`sprite_manual_next_frame`/`sprite_next_frame`/`sprite_is_playing`) on the
attached clip's standalone `display_obj`. **Nothing consumed them** —
`advance_sprite_frames` / `advance_nested_sprite_frames` walk only the root
display list and timeline-placed sprites, never an attachMovie'd clip's
standalone `display_obj`. So every cloud stayed on frame 1 = green.

**Fix landed (`be332528c`), `tag.c` `advance_attached_clip_frames()`:** called
once/tick from `tagShowFrame` AFTER scripts/queues drain (deferred → NOT
reentrant; an earlier *synchronous* attempt via `ng_gotoFrameByMC` rebuilt the
clip mid-`attachBlocks` and caused game-overs — that was reverted in
`27f18be2d`). For each `child_mc_cache` attached clip with `sprite_manual_next_frame`
set, it rebuilds the clip's display list to the target frame (placement tags
only, `catch_up_mode=1`), then runs `advance_sprite_frames` over the clip's own
list so nested sprites (charId 32 → 33+35) get sub-lists built and are recursed
by `render_display_list`. Gated `!NO_GRAPHICS && !OFFSCREEN_RENDER &&
!HEADLESS_GRAPHICS` (browser-WASM only — **neither CI mode compiles it**).

**Verified:** blue renders, brown shows broken; no new in-game game-overs; DJ
divergence trace 407=407; Snake title+gameplay unchanged.

---

## 2. Remaining issues (all PRE-EXISTING — not regressions of the fix)

The user confirmed restart-after-game-over was already broken before any of
these changes. These were merely surfaced now that platforms render and the
game is fully playable.

### A. Blue platform doesn't move horizontally
Blue's left-right motion is driven by charId 32's `onEnterFrame` clip-action
(`clip_action_8`, registered via `tagPlaceObject2RatioWithClipActions` in
`sprite_27_frame_2`). The fix builds charId 32's sub-display-list but nothing
**dispatches its per-tick enterFrame clip events** — `dispatch_clip_event_flag` /
the enterFrame dispatch walks the root/timeline lists, not nested sprites inside
attached clips. **Approach:** after/within `advance_attached_clip_frames`,
dispatch `CLIP_EVENT_ENTER_FRAME` for the attached clip's nested sprites (swap
context to the clip's display list, call the existing enterFrame dispatch).
Watch for: the clip action mutating `_x` each tick must persist (the fix only
rebuilds the clip list when the nav flag is set, so per-tick `_x` changes on
charId 32 won't be clobbered — verify this).

### B. Broken brown platform doesn't disappear
**Important:** DJ uses **no `removeMovieClip`** anywhere in its scripts —
platforms are **recycled** (re-`attachMovie` at the same `block_N` name + new
position when they scroll off). So "broken doesn't disappear" is NOT a
removeMovieClip-cleanup bug. The break shows (a frame change happens) but the
fall-away/recycle isn't completing. Likely the break is a sprite playing its
break+fall frames (nested sprite that needs to PLAY, not just gotoAndStop) and
the attached clip's nested sprite isn't being frame-ADVANCED each tick (the fix
builds the sub-list once but only re-runs when the nav flag is set). **Approach:**
investigate which charId the breakable actually is and whether it relies on a
playing nested sprite; may need per-tick advancement of playing nested sprites
in attached clips (extend `advance_attached_clip_frames` to also advance
*playing* nested sprites, not just consume nav flags).

### C. Stale game-over screen UI  +  D. Restart-after-game-over insta-kill
Likely a **shared root cause**: on the root game-over goto (and the restart
re-init), the `child_mc_cache` attached platform clips — and the parent
(levelcontainer) `sprite_display_list` entries that `ng_attachMovie` populated
by **copying the child's `sprite_display_list` pointer**
(`tag_stubs.c:553-583`) — are not torn down. So platforms render over the
game-over screen, and stale level state corrupts the restart enough to kill the
hero instantly. **Approach:** find the game-over/restart frame transition (root
gotoAndStop/Play to the game-over frame and back), and ensure the levelcontainer
+ its attached blocks (and the copied parent DL entries) are cleared on that
transition. Note the copied-pointer design in `ng_attachMovie` (parent entry
holds a copy of the child's `sprite_display_list` pointer + `sprite_max_depth`
snapshotted at attach) — stale copies are a recurring hazard.

---

## 3. Validation constraints & gotchas (read before iterating)

- **Game-over / restart states are NOT reliably reachable by Playwright.** The
  hero bounces in place on the start platform without precise mis-play input;
  forcing a fall by holding an arrow is flaky. **Blue platforms are rare** (RNG).
  → Verifying A/B/C/D realistically needs the **user's manual testing**. Plan for
  a collaborative loop: change → rebuild+deploy → user tests → reports.
- **Run probes DIRECTLY**, e.g. `/tmp/probe-venv/bin/python3 -u <probe>.py`.
  Do NOT wrap in `timeout … | tail` — the SIGPIPE/SIGTERM kills the probe and
  hides output. Kill stray Chrome between runs (`pkill -9 -f chrome`); many
  zombie Chrome instances starve new probes.
- **`build_test.sh` needs `--clean`** to pick up runtime (`.c`) changes — without
  it the wasm may not relink and you'll test stale code.
- **CI is blind to this code** (browser-WASM only, gated out of NO_GRAPHICS +
  OFFSCREEN_RENDER). The only validation that exercises the pass is the browser
  demos (DJ/Snake/Pong) + manual testing. Don't rely on CI to catch regressions
  in `advance_attached_clip_frames`.
- **Regression gates to hold:** DJ divergence `407=407`
  (`python3 tools/divergence/divergence_test.py SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf --frames 30 --skip-ruffle`),
  Snake/Pong browser probes (`tools/browser-test/baseline-probes/snake_*.py`,
  `pong_*.py`), full CI in both modes (`.claude/pipeline-handoff.md`).
- **DJ play button** = stage `(116, 130)`; **info** = `(143, 198)` (286×510 stage,
  scale to canvas px). Gameplay probe: `tools/browser-test/baseline-probes/dj_gameplay.py`.

## 4. Key files / symbols

- `SWFModernRuntime/src/libswf/tag.c` — `advance_attached_clip_frames` (the fix),
  `advance_sprite_frames`, `advance_nested_sprite_frames`, `render_display_list`,
  `tagShowFrame`.
- `SWFModernRuntime/src/libswf/tag_stubs.c` — `ng_attachMovie` (parent DL copy
  at 553-583), `ng_gotoFrameByMC`.
- `SWFModernRuntime/src/actionmodern/action.c` — `actionCallMethod` gotoAndStop
  handler (deferred flag-set in the browser-WASM `#else` branch ~63815).
- `SWFRecomp/tests/flasharchive/Doodle_Jump/RecompiledScripts/script_defs.c` —
  levelcontainer onEnterFrame / attachBlocks (gotoAndStop selection).
- `SWFRecomp/tests/flasharchive/Doodle_Jump/RecompiledTags/tagMain.c` —
  sprite_27 (cloud) frame funcs, sprite_32/37, defineBitmap order, DefineShapes.
