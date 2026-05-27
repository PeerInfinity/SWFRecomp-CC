# 2026-05-27 — Doodle Jump browser-WASM, sustained bouncing (gotoAndStop fix)

Fifteenth handoff in the Doodle Jump browser-WASM debugging chain.

Prior handoffs (most recent first):
- `2026-05-27-doodle-jump-platforms-visible.md` (`f7c3b57d5` + `824e618ef`) — attachMovie children render at correct (mc->x, mc->y); hero starts bouncing.
- `2026-05-26-doodle-jump-platforms.md` (`3ff709191` + `881b65cf0`) — attachMovie wired for non-root parents; container spawns 15 platforms.
- `2026-05-26-doodle-jump-menu-nav.md` (`bed8cd5fd` + `c14b36aef`) — menu sub-screen navigation.
- ...12 prior handoffs.

**This handoff covers commit `11f66a345` (and gitignore commit `d6bf79c04`).**

## TL;DR

- **Root cause:** `actionCallMethod`'s `gotoAndStop` / `gotoAndPlay` handler in browser-WASM (`action.c:~63531`) fell through to `actionGotoFrame()` for non-root MCs. But `actionGotoFrame()` in browser-WASM (`action.c:~30245`) only special-cases `targeted_sprite != NULL` (the global SetTarget receiver); everything else is treated as a ROOT goto, setting `next_frame` / `manual_next_frame` on the root timeline.
- **Impact on DJ:** hero `clip_action_29` calls `block.gotoAndStop(1)` per bounce (block animation reset), plus container/sprite gotoAndStops from various physics paths. Each was interpreted as `_root.gotoAndStop(N)`, advancing root from frame_1 (gameplay) to frame_0 or frame_2 (gameover) within the first few hits. Gameplay terminated in under a second.
- **Fix:** for the non-root branch in browser-WASM, write `sprite_next_frame / sprite_manual_next_frame / sprite_is_playing` directly on `mc->display_obj` (mirroring the targeted_sprite branch) and set `mc->currentframe`. Root timeline no longer touched. For attached MCs the goto is effectively a no-op (cloud platforms are single-frame); for timeline-placed sprites the display_obj is in display_list and `advance_sprite_frames` consumes the flags normally.
- **Gameplay state after fix:** hero bounces continuously across full 10s probe window — y oscillates 197-323, hero clearly hopping on platforms. Visible screenshots (`/tmp/dj-cmb-t00490.png`, `t00715.png`) show a normal DJ layout with hero centered, ~10-12 green platforms scattered around it. Score stays 0 because hero never crosses the `_y < 185` scroll threshold (bounce force ~126 px isn't strong enough to break above the starting altitude in a typical layout). That's expected normal-block physics — springs / jetpacks would push higher.
- **Baselines clean:** trace 407=407, DJ menu (no click) dl=9/8 unique canvases, DJ info-click dl=3, Snake dl=16, Pong dl=3, all 0 errors.

## How the diagnostic chain worked

1.  **Initial symptom:** hero falls from y=179 → 191 → gameover at dl_count=3, all within ~200ms (first probe).
2.  **Doubt:** could be scrolling, hitTest, or gameover trigger. User suggested scrolling.
3.  **Confirmed via debug print:** `actionGotoFrame()` was being called with frame=1, 2, 3 from `ctx_name=container` and `ctx_name=hero` — the cloud platforms and hero calling sprite-internal gotoAndStops. `targeted_sprite=0` (no SetTarget set), so the goto leaked to root.
4.  **Found the code path:** `actionCallMethod` for `gotoAndStop` in browser-WASM at line ~63531 hadn't been updated when the OFFSCREEN_RENDER path was given proper MC-targeted handling. The `} else { actionGotoFrame(...) }` branch was the leak.
5.  **Fix:** mirror the same fields the SetTarget'd branch writes (`sprite_next_frame`, `sprite_manual_next_frame`, `sprite_is_playing`) directly on `mc->display_obj`.

## What this fix DOES NOT address

User-reported issues still pending:

1.  **Too many platforms accumulate over time.** `container.onEnterFrame` increases `maxblocks` whenever hero hits a block (via `_root.container.maxblocks = lastblockhit + 9` at `script_29.c:1742-1760`), then the `attachBlocks` loop spawns blocks up to `maxblocks`. In our build, `lastblockhit` keeps rising as hero bounces, and old blocks never get deleted (no scrolling = no DeleteBlock loop trigger). The visible "extra" platforms in the user's browser are spawned ABOVE the screen but become visible when... they should NOT become visible (they're above the camera viewport, so the renderer should clip them). Likely tied to the per-tick `frame_func` re-run from memory `browser_wasm_frame_func_rerun.md`.
2.  **Hero bounces above visible platforms onto invisible ones.** Could be `compose_children` rendering some attached MCs but not others, or `hitTest` finding MCs whose render path drops them, OR the rendered region is being culled too aggressively. Worth correlating which block names hero hits (via `[DJ_DBG_HT]` instrumentation already used in this session) against which appear in the canvas.
3.  **Game doesn't end when player falls off bottom.** Probably tied to (1)+(2): the gameover trigger likely checks hero `_y > lastDeletedBlock_y + threshold` or similar, and without scrolling+DeleteBlock progression, hero stays in safe range forever.
4.  **Menu button text positioning.** Text labels ("play", "info", "score", "options") appear down-and-to-the-right of where they should appear; should be centered in the button circles. **Suggested as the next-session task** — isolated to the menu, no scrolling/per-tick involvement, browser-WASM-specific text/EditText rendering issue. Trace harness 407=407 means it's pure browser-WASM rendering, narrow diagnosis.

## Next-session suggested task: menu button text positioning

The menu hero bounce + buttons + sub-screen navigation all already work. The buttons themselves are clickable (cursor changes to pointer over them; click transitions correctly). Only the text *position* is wrong.

Likely culprit areas:
- `apply_dynamic_mc_transforms` / `compose_children` interaction with text glyph transforms (button text is rendered via DefineEditText, which has its own transform applied on top of the button's MC transform). The session-9-onward modify-detect changes could have affected how the button MC's child EditText positions compose.
- `actionTryBindTextFieldVariable` setting the text but using a stale or unrounded position.
- `tagSetInstanceName` + clip-event LOAD writing the text — the LOAD handler explicitly sets `this.button_txt.text = "play"` etc. The button_txt EditText's `_x/_y` is timeline-baked from the SWF; the LOAD writes only `text`. So position should come from the timeline.
- For comparison: the static "doodle jump v2.4" title text on the menu renders correctly (verified in screenshots). The menu hero animates correctly. Difference: title text is direct DefineEditText placed on root; button text is inside a sprite (the button MC).

Diagnostic approach:
1.  Probe the menu canvas at idle. Capture screenshot. Inspect a button's text position vs the button circle position.
2.  Add a `[BTN_TEXT_DBG]` print at the LOAD handler's `this.button_txt.text = ...` site (clip_action_25 / 26 / 27 / etc. — one per menu button) to log the button_txt MC's `_x`, `_y`, and the parent button MC's transform.
3.  Compare against trace harness output (which is rendering-independent) — likely identical, meaning the bug is in graphics path only.
4.  Check `compose_children` handling of EditText children: when the parent (button sprite) has a transform, the EditText's local transform composed with the parent should yield a centered position. If text appears down-and-right, the EditText's transform_id may be reading a stale slot or composing with the wrong parent matrix.

The session-14 `build_attached_mc_local_xform` is restricted to attachMovie-placed entries (entry pointer != mc->display_obj). Timeline-placed button text shouldn't go through it, but worth confirming by adding a temp print in that helper.

## Don't-touch list (cumulative, adding to handoff #14)

(All entries from prior handoffs remain. Adding:)

- **`actionCallMethod` gotoAndStop/gotoAndPlay handler, non-root MC branch in browser-WASM (`action.c:~63531`).** Sets sprite-local navigation fields directly on `mc->display_obj` (`sprite_next_frame`, `sprite_manual_next_frame`, `sprite_is_playing`) plus `mc->currentframe`. **Do NOT** revert to calling `actionGotoFrame(app_context, frame0)` — that path treats `targeted_sprite==NULL` as root goto and triggers DJ gameover within seconds via `block.gotoAndStop(1)` being interpreted as `_root.gotoAndStop(1)`. If a future test needs MC-targeted goto with frame label resolution (currently only handles numeric frames), extend this branch — don't redirect to actionGotoFrame.

## Tools / state

- Status: 3 unpushed commits ahead of origin/master (the gotoAndStop fix `11f66a345`, this doc, and gitignore `d6bf79c04`).
- Latest probes:
  - `/tmp/dj-combined.py` — 10s sampler with both root dl + container.children + canvas frame capture. Confirms hero bouncing.
  - `/tmp/dj-stderr.py` — captures `[DJ_DBG_*]` C-side stderr prints via Playwright console listener.
  - `/tmp/dj-long-trace.py` — 10s trace, prints unique block names + last known positions.
- Debug instrumentation (all REMOVED before commit):
  - `[DJ_DBG_HT]` at hitTest mc-AABB+test_pt+hit
  - `[DJ_DBG_FRAME]` at swf.c `current_frame = next_frame`
  - `[DJ_DBG_GF]` at actionGotoFrame entry (revealed the leak)
  - `[DJ_DBG_ADX]` at apply_dynamic_mc_transforms (showed mc.x/y for attached MCs)
- The `getSpriteChildrenJSON(depth)` probe function in display_bridge.c now reads `mc->x / mc->y` directly when an attached MC is found by name (previously reported (0,0) because compose_children builds the local in flight and never updates the slot).

Push when ready.
