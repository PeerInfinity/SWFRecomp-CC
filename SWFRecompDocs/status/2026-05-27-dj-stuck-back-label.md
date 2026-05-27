# 2026-05-27 — Doodle Jump options→back stuck "back" label

Follow-up to the Snake URL link handoff (`028149055` / `b62585d7e`).

**This handoff covers commit `e5b50f2bc`.**

## TL;DR

- **Bug:** click "options" → click "back" → return to main menu, but the "back" label persists at the options-screen back-button position. Menu buttons themselves are correct ("play"/"info"/"scores"/"options" all in place); just a leftover "back" stuck below "options".

- **Root cause:** `actionInvalidateCachedMovieClip` marks an MC dead (`depth=INT_MIN`, `avm1_removed=1`, `dynamic_props=NULL`) but does NOT cascade to descendants. When the backward-goto catch-up's survives_rewind=false branch in `tagPlaceObject2` invalidates the back-button MC (instance10), its child `button_txt` EditText MC stayed in `child_mc_cache` with `text="back"` and `mc->x/mc->y` still pointing at the options-screen position. `actionIterateTextFieldGlyphs`'s only "is this MC alive" filter is `depth != INT_MIN` on the MC itself — the orphaned child passed that check and kept rendering.

- **Fix:** after marking the parent dead in `actionInvalidateCachedMovieClip`, walk `child_mc_cache` once and mark any MC whose `mc->parent` chain leads back to the dead MC also dead (same four fields). 64-hop safety cap on the parent walk.

## How the diagnostic chain worked

1.  **Reproduce.** `/tmp/dj-options-back.py` clicks options → screenshot → clicks back → screenshot. The after-back screenshot shows the menu with "back" label persisting at world position (~133, 320 ish), which matches the back-button placement on the options screen.

2.  **Bisect against last session's changes.** Checked out `37d0e1bd3` (before my recent fixes), rebuilt DJ, repeated the click sequence. Pre-fix screenshot showed NO stuck "back" label. So the bug was introduced by one of the recent text/render fixes. Restored HEAD.

3.  **Probe child_mc_cache directly.** Added `[MCW_DBG]` print at the end of `actionIterateTextFieldGlyphs` dumping `mc`, `name`, `text`, `mc->x/y`, `world_x/y`, `parent_name` for any TF with text matching menu/back labels. Output after options→back:

    ```
    --- AFTER BACK ---
    mc=0x416607f8 text='back'    parent=instance10  world=(115.50, 335.50)
    mc=0x416704d0 text='scores'  parent=instance12  world=(132.65, 250.10)
    mc=0x41671200 text='options' parent=instance13  world=(103.75, 294.50)
    mc=0x41671f30 text='info'    parent=instance14  world=(46.70, 149.00)
    mc=0x41672c60 text='play'    parent=instance15  world=(20.35, 102.85)
    ```

    Five button_txt MCs being rendered. Four are the new menu placements (parents instance12-15, the auto-instance-name counter advanced past the old 2-5 because the rewind path treats this as fresh placement). The fifth is `instance10` — the OPTIONS-screen back button MC, still in the cache with `text="back"` and its old world position.

4.  **Trace the unload path.** Backward goto frame_3 → frame_0:
    - `ng_display_clear_after(0)` preserves display_list[3]'s entry because `sprite_display_list != NULL` (line 8365-8366 in tag.c).
    - Replay loops f=0..target, calls frame_0's funcs.
    - frame_0 calls `tagPlaceObject2WithClipActions(3, 46, 47, 32, 0, clip_actions_145, 2, 0)` for depth 3.
    - In `tagPlaceObject2`'s survives_rewind check (~line 5440): the existing entry has `ratio=3` (the back placement was via `tagPlaceObject2Ratio` with ratio=3). `survives = (ratio == 0) && ...` → false. Falls into the "different character or ratio at this depth during backward catch-up" branch (~line 5476).
    - `placed_at_frame=3 > catch_up_target=0` → enters the clear+replace path.
    - Back button has no UNLOAD handler (clip_actions_197 = {LOAD=0x1, RELEASE=0x800}) → `actionInvalidateCachedMovieClip(app_context, "instance10", 3)` is called (action.c:5581).
    - That function marks instance10's `depth=INT_MIN`, but its CHILD button_txt MC (the one named "button_txt" in the cache, parented to instance10) is not touched.
    - The replay then full-replaces depth 3 with the play button placement, allocating instance15 fresh.

5.  **Fix:** in `actionInvalidateCachedMovieClip`, after marking the target dead, second-pass walks `child_mc_cache` looking for any entry whose `parent` chain (followed up to root via `mc->parent->parent->...`) hits the dead MC. Mark those dead too. Keeps the existing logic (focus clearing, var_map clearing, TF binding drain) untouched — the cascade just adds descendant cleanup.

## Don't-touch list (cumulative)

(All entries from prior handoffs remain. Adding:)

- **`actionInvalidateCachedMovieClip` cascades to descendants** (`action.c:~21898-21927`). After marking the target MC dead, iterates `child_mc_cache` and marks any descendant (parent-chain hits the target) as `avm1_removed=1` / `dynamic_props=NULL` / `ng_textfield_idx=-1` / `depth=INT_MIN`. 64-hop safety cap. **Do NOT** revert — without it, EditText children inside an invalidated MC keep rendering their stale text at their old world position. The bug is specifically visible on backward gotos that hit `tagPlaceObject2`'s clear+replace path (survives_rewind=false with no UNLOAD handler).

## Why this didn't surface in earlier baselines

- The post-fix DJ "Info click" / "Scores click" / "Options click" tests in earlier handoffs only clicked one direction (menu → sub-screen) and screenshotted. They never round-tripped back. The bug only manifests on the BACKWARD goto.
- Pre-fix (before recent text fixes), the back-button label rendered at the wrong position (down-and-right of its bounds, due to `mc->x/y = 0` on nested EditTexts) — but on the OPTIONS screen still inside the canvas; on the menu after returning, the stale render landed at a position that may have been hard to spot, or other render bugs masked it. After the EditText init fix put the back label at its correct world position, the stale-after-return label became clearly visible at the options-screen back-button position.
- Other tests with sub-screen navigation pass because they don't exercise the same backward-goto + invalidate-with-children path AND don't have EditTexts inside the invalidated sprite.

## Baselines after fix

- Trace: 407=407.
- DJ menu (no click): dl=9 stable, 7 unique canvases, 0 errors. Button labels centered.
- DJ Info / Scores / Options → back round-trip: menu renders clean (no stuck labels).
- DJ play-click: hero bounces (unchanged).
- Snake: dl=16, 8 ok, 0 errors. URL still renders + clicks open new tab.
- Pong: dl=3 stable.

## Tools / state

- Status: 1 unpushed commit ahead of origin/master (`e5b50f2bc`).
- Probes added during diagnosis:
  - `/tmp/dj-options-back.py` — clicks options → back, dual screenshots.
  - `/tmp/dj-options-back-dbg.py` — same flow but headless with `[MCW_DBG]` console capture.
- Debug instrumentation (removed before commit): `[MCW_DBG]` at the end of `actionIterateTextFieldGlyphs` filtering for menu/back labels.

Push when ready.
