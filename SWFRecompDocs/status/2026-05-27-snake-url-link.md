# 2026-05-27 — Snake URL link rendering + click dispatch

Follow-up to the Snake title-text bit-swap handoff (`1fbbdb85d` / `7bb0ec869`).

**This handoff covers commit `028149055`.**

## TL;DR

Three orthogonal fixes wire up Snake's "www.neave.com/webgames" hyperlink at the bottom of the title screen. Pre-fix: nothing visible at the URL position; cursor changed to pointer when hovering (so the hit region was wired) but clicking did nothing. Post-fix: URL renders correctly, click opens a new browser tab.

1.  **Orphan textfield walk skipped CHAR_TYPE_BUTTON entries** (`action.c:otf_walk_dl`). The comment said "buttons … not represented as a persistent DL" — but `process_sprite_needs_init` runs `button_state_funcs[0]` (the UP state) at init time and persists the resulting display list in `obj->sprite_display_list`. So buttons DO have a persistent up-state DL, reachable the same way sprites are. Adding `CHAR_TYPE_BUTTON` to the recursion gate gets the URL EditText (placed at depth 1 inside button_7's UP state) into the dynamic glyph render path. Without this, render_display_list saw the EditText, skipped its static glyphs via the `ng_getCharTextfieldIdx` textfield check (DefineEditText is double-emitted as a DefineText for static layout but rendered dynamically), and `actionIterateTextFieldGlyphs` walked `child_mc_cache` where no AS-resolved wrapper exists.

2.  **Font registration was no-op in graphics mode** (`tag.c:tagDefineFontInfo / tagDefineFontMetrics / tagDefineFontGlyphBase`). All three were gated `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`, so in browser-WASM `ng_find_font_with_metrics(font_id)` always failed and fell back to the builtin Noto Sans entry whose `glyph_base` is 0. Coincidentally correct when a SWF has exactly one font at `glyph_base=0` (DJ's font 21), garbled whenever a SWF has multiple fonts (Snake: font 4 at `glyph_base=40` — `ng_font_find_glyph` used Noto Sans's code table to map character → local glyph index, and the renderer added `0 + glyph_idx` instead of `40 + glyph_idx`, reading shape rows from the wrong region of `glyph_data`). Removing the gate makes the renderer use each font's real `glyph_base` (e.g. font 2 → 0, font 4 → 40) and real ascent/descent/advance metrics.

    Side effect for DJ: Info sub-screen item list now uses font 21's real advance widths instead of Noto Sans's. Visible improvement — "mushroom: inverse control" fits in full where before it was truncated to "mushroom: inverse contr". No regression.

3.  **actionGetURL didn't open URLs in browser-WASM**. Two layered problems:
    - The named-clip loadMovie branch (`if (target != NULL && target[0] != '\0')`) caught `target="_blank"`/`_self`/`_parent`/`_top` and tried to load the URL into a clip named "_blank", returning before reaching browser navigation. Added an `is_browser_target` guard to skip those four reserved targets in the named-clip branch.
    - There was no browser-navigation code at all — the comment said "browser navigation targets … are not applicable in trace mode." Added a `#ifdef __EMSCRIPTEN__` block that calls `window.open(url, target)` via `EM_ASM`. Native / trace / headless builds still silent-ignore.

## How the diagnostic chain worked

1.  **Reproduce.** Baseline Snake screenshot showed title + level names but nothing at the URL position. Ruffle reference showed "www.neave.com/webgames" at the bottom. Cursor changed to pointer when hovering the empty spot (button hit zone working).
2.  **Find the URL placement.** Searched `tagPlaceObject2(app_context, depth, 5, ...)` for char 5 placements — found at `button_7_frame_up` line 556: `tagPlaceObject2(app_context, 1, 5, 37, 0, 0, 0);`. So the URL EditText is placed inside button_7's UP state. button_7 has hit shape char 6 (hit_transform 40) and action `{ 0x8, button_7_action_3 }`.
3.  **Check render path.** EditText is char 5 = both `tagDefineText(5, ...)` AND `tagDefineEditTextProps(5, ...)`. Static glyph rendering is skipped (`ng_getCharTextfieldIdx >= 0`) so it must go through `actionIterateTextFieldGlyphs` / `actionIterateOrphanTextFields`. MC walk: no AS-resolved wrapper. Orphan walk: comment in `otf_walk_dl` says "Buttons (CHAR_TYPE_BUTTON) intentionally skipped". Bug 1 found.
4.  **First fix:** allow `otf_walk_dl` to recurse into `CHAR_TYPE_BUTTON`. Rebuild → URL renders, but with garbled glyphs.
5.  **Diagnose garbled glyphs.** Added `[OTF_DBG]` print at `otf_emit_textfield`: `tf_idx=0 char_id=5 font_id=4 font_h=200 text='www.neave.com/webgames' world=(94.00, 279.30) bounds=(-210, 2850, -40, 306)` — correct dispatch.
6.  **Added `[TF_GLYPH_DBG]` print in `textfield_glyph_render_cb`**: revealed `font_idx=0 glyph_idx=87 glyph_base=0 global=87` for 'w'. Inspecting `glyph_data` rows 348-351 → that's font 4's glyph 47, not 87. `glyph_base` should be 40 for font 4.
7.  **Find why `glyph_base=0`**: searched `ng_record_font_glyph_base` callers. Only call site is `tagDefineFontGlyphBase` in tag.c, gated `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`. Browser-WASM never registers fonts. `ng_find_font_with_metrics` falls back to builtin Noto Sans (font_id=0, glyph_base=0). Bug 2 found.
8.  **Second fix:** remove the build-mode gates from all three font-registration wrappers. Rebuild → URL renders correctly, matches Ruffle.
9.  **Check click handling.** Added `[BTN_TRANS_DBG]` print in the button-state transition dispatch — confirmed `transition=0x0008 (down→over) actions=1` fires on mouse release. Added `[BTN_ACT_DBG]` print at the action loop — confirmed `cond=0x0008 trans=0x0008 match=1` (action pointer non-null, action invoked).
10. **Trace the action call.** `button_7_action_3` calls `actionGetURL("http://www.neave.com/webgames/", "_blank")`. Added `[GETURL_ENTRY]` at the top of `actionGetURL` — confirmed entry. Added `[GETURL_DBG]` just before the (already-written) `__EMSCRIPTEN__` `window.open` block — not reached. Inspected what's between: the "named clip target" branch at line 31228 catches `target != NULL && target[0] != '\0'`, which matches `_blank`, tries to find an MC named `_blank` (fails), then attempts a deferred `loadMovie` and returns. Bug 3 found.
11. **Third fix:** added `is_browser_target` precondition (matches `_blank`/`_self`/`_parent`/`_top`) and gated the named-clip branch on `!is_browser_target`. Browser-navigation block reachable.
12. **Verify click opens tab.** Playwright `wait_for_event('popup')` captured `https://neave.com/` opening on click (the URL redirected from `webgames`). Earlier `ctx.on('page', ...)` listener missed popups — a Playwright API distinction, not a code bug.

## Don't-touch list (cumulative)

(All entries from prior handoffs remain. Adding:)

- **`otf_walk_dl` recurses into `CHAR_TYPE_BUTTON`** (`action.c:~25691`). Uses the same `obj->sprite_display_list` that `process_sprite_needs_init` filled with the UP-state placements. **Do NOT** revert to "Buttons intentionally skipped" — that hides EditTexts and any other textfields placed inside button up-states from the orphan walk.

- **Font registration is unconditional** (`tag.c:tagDefineFontInfo / tagDefineFontMetrics / tagDefineFontGlyphBase`, ~line 8155-8175). All three wrappers call into `ng_record_*` regardless of build mode. **Do NOT** re-add the `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` guard — browser-WASM `actionIterateTextFieldGlyphs` would fall back to Noto Sans with `glyph_base=0` and garble any SWF that has multiple fonts.

- **`actionGetURL` browser-target precedence** (`action.c:~31223`). `is_browser_target` (matches `_blank`/`_self`/`_parent`/`_top`) takes precedence over the named-clip loadMovie branch. The `__EMSCRIPTEN__` block at the bottom dispatches to `window.open(url, target)`. **Do NOT** remove the `is_browser_target` guard — without it, the named-clip branch consumes `_blank` etc. and returns before reaching `window.open`.

## Baselines after fix

- Trace: 407=407.
- DJ menu (no click): dl=9 stable, 8 unique canvases, 0 errors. Button labels still centered.
- DJ Info click: sub-screen renders with item list. Improved: "mushroom: inverse control" no longer truncated (was "mushroom: inverse contr"). Other items also slightly re-laid-out to match real font 21 metrics.
- DJ play-click: hero bounces continuously (unchanged).
- Snake: dl=16 stable, 8 ok canvases, 0 errors. Title screen text positioned correctly. URL "www.neave.com/webgames" visible at the bottom (matches Ruffle).
- Snake URL click: opens `http://www.neave.com/webgames/` in a new tab (redirects to `https://neave.com/`).
- Pong: dl=3 stable. Preloader render unchanged.

## Tools / state

- Status: 1 unpushed commit ahead of origin/master (`028149055`).
- Probes added during diagnosis (debug prints all removed before commit):
  - `/tmp/snake-shot.py` — visible (headed) Snake screenshot at 2s.
  - `/tmp/parse_swf_text.py` (carried from prior handoff) — parse SWF DefineText records.
  - `/tmp/snake-click-url2.py` — click URL position, look for new page (via `ctx.on('page', ...)`). Doesn't catch popups in headless Chrome.
  - Inline Python with `page.wait_for_event('popup')` — correctly catches popup tabs from `window.open`.
- Debug instrumentation (removed before commit): `[OTF_DBG]` in `otf_emit_textfield`, `[TF_GLYPH_DBG]` in `textfield_glyph_render_cb`, `[BTN_TRANS_DBG]` / `[BTN_ACT_DBG]` at the button-action dispatch loop, `[GETURL_ENTRY]` / `[GETURL_DBG]` in `actionGetURL`.

Push when ready.
