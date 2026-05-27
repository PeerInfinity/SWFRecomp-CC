# 2026-05-27 — Doodle Jump browser-WASM, button label centering

Sixteenth handoff in the Doodle Jump browser-WASM debugging chain.

Prior handoffs (most recent first):
- `2026-05-27-doodle-jump-sustained-bouncing.md` (`11f66a345` + `37d0e1bd3`) — gotoAndStop non-root branch must not write root timeline fields; hero bounces continuously.
- `2026-05-27-doodle-jump-platforms-visible.md` (`f7c3b57d5` + `824e618ef`) — attachMovie children render at correct (mc->x, mc->y); hero starts bouncing.
- ...13 prior handoffs.

**This handoff covers commit `ac54a1679`.**

## TL;DR

- **Two root causes for menu button labels rendering down-and-to-the-right:**
  1. `actionFindOrCreateMovieClip`'s nested-text-field init branch (`action.c:~21008`, the path taken when `ng_findDisplayEntryByName` returns `SIZE_MAX` because the EditText is inside a sprite — not at root depth) set `mc->width`/`mc->height` from the EditText bounds but never assigned `mc->x`/`mc->y`. So nested EditTexts (e.g. labels inside button sprites) ended up with `mc->x = mc->y = 0`. Then `actionIterateTextFieldGlyphs`'s `world_x = mc->x + parent.x` dropped the placement transform's translation. Each button_txt was placed at transform 36 = (-58, -14) px inside sprite_46; that offset never made it onto the MC.
  2. `actionIterateTextFieldGlyphs`'s plain-text fallback path (`action.c:~25333` — text from props "text", no TFRunTable, no styleSheet) passed `runs=NULL` to the renderer. The renderer's paragraph layout (`tag.c:textfield_glyph_render_cb`) then defaulted `cur_align` to 0 (left) regardless of the DefineEditText tag's static `align` (which was 2/center for these button labels). Center alignment from the tag was silently lost for any field without dynamic runs.

- **Fix:**
  1. In the nested-text-field init branch, re-walk `parent->sprite_display_list` for a matching `instance_name`, read its `transform_id`, and assign `mc->x = transform_data[tid][12]/20`, `mc->y = transform_data[tid][13]/20`. Gated on `!(mc->as_set_flags & 1|2)` so script-set positions aren't clobbered. Mirrors what the root branch does via `ng_getTransformXY(depth)` for top-level placements.
  2. In the plain-text fallback, after setting up `text_utf8`, synthesize a single `TextFieldGlyphRun` carrying `ng_getTextFieldAlign(tf_idx)` (plus `color`, `font_height`). The renderer then reads `cur_align` from this run and applies center/right alignment correctly.

- **Visual after fix:** "play", "info", "scores", "options" labels centered inside their respective button ovals on the menu. "back" buttons on Info/Scores/Options sub-screens also centered. "doodle jump" title and "v2.4" sub-text positions unchanged. Hero bounces continuously after play-click (sustained bouncing fix from last session preserved). Score after 10s of play ≈ 515.

- **Baselines:** trace 407=407; DJ menu dl=9 stable; DJ cursor 'pointer' over play / 'default' off; DJ Info/Scores/Options sub-screens transition correctly; Snake dl=16 0 errors; Pong dl=3 0 errors.

## How the diagnostic chain worked

1.  **Reproduce.** Built DJ wasm + deployed; captured menu shot. Confirmed "play"/"info"/"scores"/"options" labels offset ~15-20 px down-and-right from their button ovals.
2.  **Doubt scope.** Could be `compose_children` + EditText interaction, text autoSize, LOAD-handler text writes, or build_attached_mc_local_xform leaking. Per-handoff suggestion: instrument the EditText render path.
3.  **Add `[BTN_TXT_DBG]` print** at `actionIterateTextFieldGlyphs` line ~25360 (right before the callback) dumping `mc->x, mc->y, world_x, world_y, w, h, bounds, parent_name, ng_textfield_idx`.
4.  **Result:** all four button_txt MCs reported `mc->x=0.00 mc->y=0.00`. But each was placed at transform 36 = `(td[12], td[13]) = (-1160, -280)` twips = `(-58, -14)` px inside sprite_46. So the placement offset was being silently dropped.
5.  **Trace the init path.** `actionFindOrCreateMovieClip` has two init branches at line ~20996:
    - Root path (line ~21210): `if (ng_getTransformXY(depth, &init_x, &init_y)) { mc->x = init_x; mc->y = init_y; }`
    - Nested path (line ~21008, triggered when `depth == SIZE_MAX` from `ng_findDisplayEntryByName` and `nested_char_id != 0` from `findDisplayEntryInParent`): sets `__proto__`, `text`, `mc->width`, `mc->height` … but NO `mc->x` / `mc->y`.
6.  **First fix:** in the nested path, walk `parent->sprite_display_list` (which `findDisplayEntryInParent` already located), find the entry by `instance_name`, read its `transform_id`, and assign `mc->x`/`mc->y` from `transform_data[tid][12]/[13]`.
7.  **Rebuilt + reprobed:** `mc->x=-58.00 mc->y=-14.00` ✓; world_x for "play" shifted from 78.35 → 20.35. Visually, text moved into the button-oval region. But now appeared at the LEFT of each oval instead of CENTERED.
8.  **Inspect alignment.** Renderer reads `cur_align` from `info->runs[run_idx].align`. When `info->runs == NULL` (plain-text fallback for fields without TFRunTable / styleSheet), `cur_align` defaults to 0 (left). The DefineEditText tag's `align=2` (center) never propagates.
9.  **Second fix:** synthesize a single run in the plain-text fallback so the renderer sees `align = ng_getTextFieldAlign(tf_idx)`.
10. **Rebuilt + reprobed:** text now centered inside each button oval, matching original Flash. Verified Info/Scores/Options click + play-click flows still work.

## What this fix DOES NOT address

Same secondary issues as last handoff remain pending:

1.  **Too many platforms accumulate over time.** `container.maxblocks` keeps growing as hero bounces; old blocks aren't deleted (no scrolling).
2.  **Hero bounces onto invisible platforms.** Render/hitTest divergence for some attached MCs.
3.  **Game doesn't end when player falls off bottom.** Tied to (1)+(2): without scrolling, gameover trigger never fires.
4.  **Pong stuck preloader.** Pre-existing.

Item 1-3 are all tied to the per-tick `frame_func` re-run (memory `browser_wasm_frame_func_rerun.md`). Prior reverts of memory-option 1 regressed Pong + DJ; needs careful re-attempt.

## Don't-touch list (cumulative, adding to handoff #15)

(All entries from prior handoffs remain. Adding:)

- **`actionFindOrCreateMovieClip` nested-text-field init branch (`action.c:~21048`).** When `ng_findDisplayEntryByName` returns `SIZE_MAX` for the textfield's instance_name (because it's not on root's display_list) AND `findDisplayEntryInParent` located the entry inside parent's sprite_display_list, the inline block now re-walks parent's sprite_display_list to find the entry's `transform_id` and assigns `mc->x/y` from `transform_data[tid][12]/[13]/20.0`. **Do NOT** remove this walk or migrate it back to `ng_getTransformXY(depth)` — that function reads the GLOBAL `display_list`, which doesn't contain nested entries. The walk is gated on `!(mc->as_set_flags & 1|2)` so script-set positions aren't clobbered.

- **`actionIterateTextFieldGlyphs` plain-text fallback synthesized run (`action.c:~25343`).** When neither TFRunTable nor styleSheet provides runs, fall through to props "text" but ALSO populate `_tfg_runs[0]` with `byte_start=0`, `byte_length=utf8_len`, `color=text_color`, `font_height=font_height`, `align=ng_getTextFieldAlign(tf_idx)`. Without this synthesized run the renderer's paragraph layout defaults `cur_align=0` (left) regardless of what DefineEditText specified. **Do NOT** remove this — center/right-aligned button labels and any other plain-text fields with non-left alignment will revert to left-align. The synthesis is gated on `mc->ng_textfield_idx >= 0` (so dynamic createTextField fields without a tag idx fall back gracefully).

## Tools / state

- Status: 1 unpushed commit ahead of origin/master (`ac54a1679`).
- Probes used:
  - `/tmp/dj-menu-shot.py` — visible (headed) menu screenshot at 2s.
  - `/tmp/dj-btn-txt-dbg.py` — headless run capturing `[BTN_TXT_DBG]` stderr via console listener (renders black headlessly but stderr still flows).
  - `/tmp/dj-click-test.py` — click on a named button (`info|scores|options|play`) and capture sub-screen. Uses field-center coords: `(parent_x - 58 + 60, parent_y - 14 + 24)` (mc->x/y + half-bounds).
  - `/tmp/dj-cursor-test.py` — verify `cursor:pointer` over play button and `cursor:default` off canvas.
  - `/tmp/dj-play-probe.py` — click play and sample over 10s; visual via screenshot confirms hero airborne + platforms visible.
- Debug instrumentation (REMOVED before commit):
  - `[BTN_TXT_DBG]` at actionIterateTextFieldGlyphs line ~25360 (deleted along with the fix verification cycle).

Push when ready.
