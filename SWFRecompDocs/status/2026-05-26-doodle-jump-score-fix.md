# 2026-05-26 — Doodle Jump browser-WASM, score "undefined" fix

Eleventh handoff in the Doodle Jump browser-WASM debugging chain.

Prior handoffs:
1. `2026-05-25-doodle-jump-browser-investigation.md` — initial investigation + cycling-bug diagnosis.
2. `2026-05-25-doodle-jump-followup.md` — cycling fix (`98b388e46`).
3. `2026-05-25-doodle-jump-clip-events.md` — clip-event LOAD / ENTER_FRAME dispatch (`3ac27552e`).
4. `2026-05-25-doodle-jump-audit.md` — 22-gate audit (`c9b11cc99`).
5. `2026-05-25-doodle-jump-bounce-fix.md` — 6 more gates for AS-side bounds/hitTest (`68889f5ed`).
6. `2026-05-26-doodle-jump-buttons-clickable.md` — buttons clickable (`92606558b` + cursor follow-up `7e9b53a6a`).
7. `2026-05-26-doodle-jump-orphan-text-cleanup.md` — descendant MC invalidation on sprite removal/replace (`c2147d58e`).
8. `2026-05-26-doodle-jump-info-label-cleanup.md` — invalidate descendants on `tagReplaceObject2RatioWithClipActions` (`bd9e830a9`).
9. `2026-05-26-doodle-jump-cache-leak-half-fix.md` — same-(char, ratio, depth) modify-detect (`a4eb48071`).
10. `2026-05-26-doodle-jump-cache-leak-full-fix.md` — deferred-invalidate via `pending_remove` (`78000f548`).
11. **This doc** — closes the score "undefined" regression introduced by the prior fix.

**Branch state at writing:** `master`, 4 unpushed commits ahead of `origin/master` (3 from prior sessions + 1 from this session, plus a docs commit to come).

## TL;DR

- **Landed (one-line change in tagShowFrame):** moved the browser-WASM `pending_remove` finalize walk to **before** the `AQ_KIND_LOAD` drain (was after). Mechanically equivalent for the orphan-text and rendering invariants the prior session set up, but fixes the LOAD-binds-stale-MC bug.
- **Pass criterion met:** `/tmp/dj-final/canvas/t04.png` shows score "0" in the top-left, "menu" button top-right, no leftover labels.
- **Baselines clean:** trace harness 407=407, Pong dl-count stable at 2 (MD5 `bb1f52f690672bd558f6e5c6b1c64301`), Snake dl-count stable at 16 (CHOOSE LEVEL screen rendered), DJ menu `unique_canvas_sizes=7`, `display_list_counts` stable at 9, DJ cursor pointer/default.

## Root cause

DJ's hero (char_id 40) has two `PlaceObject2WithClipActions` placements with the SAME `instance_name="hero"` but different depths:
- frame_0 line 51: `tagPlaceObject2WithClipActions(app_context, 9, 40, ..., clip_actions_149, ...)` — menu hero at depth 9.
- frame_1 line 73: `tagPlaceObject2RatioWithClipActions(app_context, 4, 40, ..., clip_actions_162, ...)` — gameplay hero at depth 4 (clip_actions_162 = LOAD `clip_action_28`, ENTER_FRAME `clip_action_29`).

`clip_action_28` does `var score = 0;` (`actionDefineLocal("score")`) at root scope — runtime stores it on `g_current_context->dynamic_props`, where `g_current_context` is the hero MC.

`clip_action_29` reads `score` via `actionGetVariable` and writes `_root.score_txt.text = "" + score`. Lookup finds `score` on `g_current_context->dynamic_props` first.

The MC for "hero" is looked up via `actionFindOrCreateMovieClip(instance_name, parent)`. The cache key is `(name, parent)` — depth is not part of the key, and `swf_name_match` is the same comparator for both depth 9 and depth 4 placements.

Pre-this-fix sequence on gotoAndStop from menu to gameplay (frame_1 first run):

1. Tag stream:
   - `tagPlaceObject2RatioWithClipActions(4, 40, hero@gameplay, ...)` queues LOAD on `AQ_KIND_LOAD`.
   - `tagRemoveObject2(9)` sets `display_list[9].pending_remove = 1` (menu hero — deferred-invalidate from the prior fix).
2. `actionDrainAllInPriorityOrder` runs root frame script.
3. `tagShowFrame`:
   - `advance_sprite_frames`, `upgrade_sprite_initialized`.
   - **`actionDrainActionQueueByKind(AQ_KIND_LOAD)`** — fires `aq_dispatch_clip_load` for the gameplay hero. The dispatcher calls `actionFindOrCreateMovieClip("hero", root)` — but depth 9's menu hero MC is still in `child_mc_cache` (its `display_list[9]` slot hasn't been finalized yet). Cache match returns the **menu hero MC**. `clip_action_28` runs with `g_current_context = menu_hero_mc`, stores `menu_hero_mc.dynamic_props.score = 0`.
   - **`pending_remove` finalize walk** runs *after* the LOAD drain — invalidates `display_list[9]` and removes the menu hero MC from cache.
4. Next tick: `tagFlushPendingEnterFrame` dispatches ENTER_FRAME for `display_list[4]` (gameplay hero). The dispatcher calls `actionFindOrCreateMovieClip("hero", root)` — menu hero is gone from cache, fresh gameplay hero MC is created with empty `dynamic_props`. `clip_action_29` reads `score` — undefined.

Diagnostic that proved it (from probe `/tmp/dj-eleventh-dbg/console.json`, before fix):

```
[DJ_DBG] clip_action_28 (LOAD) start, g_current_context=0x415c5f58 call_depth=0 scope_depth=0
[DJ_DBG] clip_action_28 after DefineLocal(score=0)
[DJ_DBG] clip_action_29 read score: type=3 double_val=0 g_current_context=0x41c3c390
[DJ_DBG] clip_action_29 read score: type=3 double_val=0 g_current_context=0x41c3c390
...
```

Two different `g_current_context` addresses (LOAD: `0x415c5f58`; ENTER_FRAME: `0x41c3c390`) prove LOAD and ENTER_FRAME bound to different MCs. Type 3 = `ACTION_STACK_VALUE_UNDEFINED` confirms the undefined read.

After the fix (`/tmp/dj-eleventh-v2/console.json`):

```
[DJ_DBG] clip_action_28 (LOAD) start, g_current_context=0x41ea5688 call_depth=0 scope_depth=0
[DJ_DBG] clip_action_28 after DefineLocal(score=0)
[DJ_DBG] clip_action_29 read score: type=6 double_val=0 g_current_context=0x41ea5688
```

Same address, type 6 (`ACTION_STACK_VALUE_F64`) with value 0.

## The fix

`SWFModernRuntime/src/libswf/tag.c` — `tagShowFrame`, browser-WASM branch.

Moved the `pending_remove` finalize walk (~12 lines) from **after** `actionDrainActionQueueByKind(app_context, AQ_KIND_LOAD)` to **before** it. Gating changed from `!defined(NO_GRAPHICS) && !defined(HEADLESS_GRAPHICS) && !defined(OFFSCREEN_RENDER)` to `!defined(HEADLESS_GRAPHICS)` (the surrounding `#  else` of `#  ifdef OFFSCREEN_RENDER` inside the outer `#else` of `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` already excludes NO_GRAPHICS and OFFSCREEN_RENDER).

No other logic changed. The walk's semantics are unchanged — same `display_list[_pr_d].pending_remove` check, same `invalidate_mc_for_dl_entry + clear_display_entry` action.

## Downstream consequence: hero physics now applies

Pre-fix, hero appeared visible-but-frozen in the centre of the canvas (handoff #10 item B noted "DJ hero physics frozen"). Post-fix, hero's `onEnterFrame` (`clip_action_29`) can now read `_root.x`, gravity vars, etc. via the same `score`-bound scope — so the physics loop runs. The hero now falls off the canvas (y reaches 15507 by t04 in my probe). This is a *forward step*: the AS-init issue that was blocking score also blocked the rest of `clip_action_28`'s `var` declarations (gravity, jumpFactor, etc.) — now those work too. The next gameplay bug to investigate is block collision / platform spawning, which keeps the hero from bouncing instead of falling. Outside the scope of this fix.

## What the fix DOESN'T address

- **DJ menu nav cycle:** all menu clicks dispatch to play. Unchanged. Investigate
  `ng_hit_test_buttons` / `actionDispatchMCPress` / clip_event_press dispatch.
- **DJ hero block collision / platform bounce:** hero now falls instead of bouncing.
  Same class of AS-init issue likely. Trace `clip_action_29`'s collision logic vs Ruffle.
- **Pong preloader transition:** pre-existing, unchanged by this fix.

## Baselines verified

- **Trace harness:** `python3 tools/divergence/divergence_test.py SWFRecomp/tests/flasharchive/Doodle_Jump/test.swf --frames 30 --skip-ruffle` → 407=407.
- **Pong probe:** dl_count stable at 2 across 6 snapshots, screenshots that captured all have `bb1f52f690672bd558f6e5c6b1c64301`.
- **Snake probe:** dl_count stable at 16 across 6 snapshots, t01 = CHOOSE LEVEL screen (correct).
- **DJ menu (no click, 8s):** `unique_canvas_sizes=7`, `display_list_counts=[9,9,9,9,9,9,9,9]`.
- **DJ cursor:** `python3 /tmp/cursor-check.py` → 'pointer' over play button, 'default' off — matches.
- **DJ play-click t04:** score "0", "menu" button top-right, no leftover labels.

## Don't-touch list (cumulative)

(All entries from handoff #10 remain. Adding to that list:)

- The new ordering in `tagShowFrame` (browser-WASM): `advance_sprite_frames` →
  `upgrade_sprite_initialized` → `pending_remove finalize walk` → `AQ_KIND_LOAD drain` →
  `g_root_enterframe_eligible = 1`. The finalize walk MUST run before the LOAD drain,
  not after — otherwise LOAD handlers bind to MCs that are about to be invalidated.
  See "Root cause" above.

## Tools / state

- Local Ruffle source: `~/CC/ruffle`
- MTASC: `~/CC/mtasc/bin/mtasc`
- Probe venv: `/tmp/pong-probe/venv`
- Latest known-good probes:
  - DJ post-fix gameplay click: `/tmp/dj-final/`
  - DJ post-fix diagnostic confirmation: `/tmp/dj-eleventh-v2/`
  - DJ menu bouncing: `/tmp/dj-menu-eleventh/`
  - Pong regression: `/tmp/pong-eleventh/`
  - Snake regression: `/tmp/snake-eleventh/`

Push when ready.
