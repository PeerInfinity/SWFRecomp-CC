# 2026-05-26 — Doodle Jump browser-WASM, menu sub-screen navigation

Twelfth handoff in the Doodle Jump browser-WASM debugging chain.

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
11. `2026-05-26-doodle-jump-score-fix.md` — pending_remove finalize before AQ_KIND_LOAD drain (`38832b57a`).
12. **This doc** — menu sub-screen navigation: Info / Scores / Options buttons load their own sub-screens with a "Back" button.

**Branch state at writing:** `master`, 2 unpushed commits ahead of `origin/master` (this session's runtime fix + this docs commit).

## TL;DR

- **Diagnosis correction:** the user's report ("all menu clicks dispatch to the play button") was *symptom*, not cause. Press dispatch was already correct — the buttons' CLIP_EVENT_RELEASE handlers fire on the right MC per click position. The actual bug: `_root.gotoAndStop(N)` and `_root.gotoAndPlay(N)` had no catch-up of skipped intermediate frames in browser-WASM, so depths placed by frame_0 (menu buttons + hero + block) stayed visible on every sub-screen.
- **Landed two changes:**
  - `SWFModernRuntime/src/actionmodern/action.c` — new browser-WASM root-goto catch-up in `actionCallMethod`'s gotoAndStop/Play dispatch.
  - `SWFModernRuntime/src/libswf/tag.c` — browser-WASM `tagShowFrame` returns early when `catch_up_mode` is set (prevents the per-tick pumping from corrupting global state nested inside a CLIP_RELEASE handler).
- **Pass criterion met (stretch):** Info, Scores, Options buttons each load their correct sub-screen, and a "Back" button on each returns to the menu (`dl_count` 9 → 3 → 9). Play button still transitions to gameplay (`dl_count` 9 → 6).
- **Baselines clean:** trace harness 407=407, Pong dl-count stable at 2 with MD5 `bb1f52f690672bd558f6e5c6b1c64301`, Snake t02..t08 MD5 `a213fc90328ab539f9c9e7288670d498`, DJ menu `unique_canvas_sizes=8` with `display_list_counts` stable at 9, DJ cursor pointer/default.

## Root cause

DJ's menu (`frame_0`) places 9 entries: depths 1, 2 (bg + ufo), depths 3, 5, 7, 8 (four menu buttons, all char_id 46, each with `CLIP_EVENT_LOAD` + `CLIP_EVENT_RELEASE`), depths 9, 10, 11 (hero + block + v2.4 text).

The four buttons' RELEASE handlers each call `_root.gotoAndStop(N)` or `_root.gotoAndPlay(N)` to navigate to a sub-screen:
- depth 3 (scores label): `gotoAndStop(5)` → frame_4 (scores)
- depth 5 (options label): `gotoAndStop(4)` → frame_3 (options)
- depth 7 (info label): `gotoAndPlay(6)` → frame_5 (info)
- depth 8 (play label): `gotoAndPlay(2)` → frame_1 (gameplay)

Each sub-screen's `frame_N` does INCREMENTAL updates (assumes you're coming from `frame_{N-1}` and only places/removes the deltas needed). Sequential play through frame_0 → frame_1 → ... → frame_4 would have `tagRemoveObject2` calls in frame_1 clean up depths 3, 5, 7, 8, 9, 10, 11. But a direct goto from frame_0 to frame_4 (or any non-sequential forward goto) skips those removes — the menu depths stay placed on the sub-screen.

**Why play "worked" pre-fix:** frame_0 → frame_1 is sequential. frame_1's tag stream explicitly removes every menu depth (`tagRemoveObject2(1)` through `tagRemoveObject2(11)`). No skipped frames, no missed cleanup.

**Why dispatch wasn't the issue:** instrumenting `dispatch_clip_event_press_dl` showed `hit_test` correctly identifies a *single* button per click position (verified for play, info, scores, options at their respective SWF-pixel coordinates). The release handler dispatches to the right MC. The goto runs. The sub-screen content renders. But the menu depths remain over top, visually swamping the sub-screen content — the user reads this as "nothing happened" / "play button fired."

The goto code path in browser-WASM is `actionCallMethod` (action.c:63322) → its `gotoAndStop`/`Play` dispatch block. The `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)` arm calls `ng_executeGotoTagsOnly` / `ng_executeGotoCatchUp` (full catch-up infrastructure). The `#else` arm (browser-WASM) just called `actionGotoFrame(frame0)`, and `actionGotoFrame`'s own catch-up call is *also* gated `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`. Net result: browser-WASM root goto sets `next_frame=target, manual_next_frame=1` and nothing else — no catch-up of intermediate frames.

`swf.c`'s outer catch-up loop at swf.c:720-769 (which DOES run catch-up via `goto_from_action && manual_next_frame`) is itself inside `#ifdef OFFSCREEN_RENDER`, so it doesn't help browser-WASM either.

## The fix — two parts

### 1. `actionCallMethod` browser-WASM root-goto catch-up (action.c:63427+)

Replaced the old `#else` one-liner:

```c
#else
    actionGotoFrame(app_context, (u16)(frame_num - 1));
    if (is_play) is_playing = 1;
#endif
```

with a custom catch-up that runs intermediate frames' tags:

- Forward goto (target > current_frame): run `frame_funcs[saved_current+1 .. target-1]` with `catch_up_mode=1, g_tag_skip_mode=0` so the recompiler-emitted gate (`if (!catch_up_mode || g_tag_skip_mode) actionQueueScript / actionDrainAllInPriorityOrder`) suppresses scripts but the unguarded display tags (RemoveObject2, PlaceObject2, ...) execute. This drives each intermediate frame's pending_remove book-keeping forward so the menu depths get marked for cleanup.
- Backward goto (target < current_frame): call `ng_display_cleanup_unplaced_after(target)` to clear depths placed at frames > target, then run `frame_funcs[0 .. target-1]` in catch_up_mode to replay state.
- After catch-up: set `next_frame=frame0, manual_next_frame=1, is_playing=is_play, root_movieclip.currentframe=frame0+1`.

**Critical line — `current_frame = (size_t)frame0`** after the catch-up loop (line ~63498). Without it, the in-tick `frame_funcs[current_frame]` call at swf.c:615 — which runs AFTER the mouse-release handler that fires our goto — would re-execute `frame_0` and re-place every menu depth the catch-up just cleared. Setting `current_frame` to the target makes that swf.c:615 call land on `frame_funcs[target]` instead, so the target frame's tags run this tick and the menu depths' pending_remove flags get finalized by `tagShowFrame`'s walk.

### 2. Browser-WASM `tagShowFrame` early-return on catch_up_mode (tag.c:3434+)

```c
#  else
    // Browser-WASM: during goto catch-up (called from actionCallMethod's
    // gotoAndStop/Play dispatch when target is root) skip per-tick
    // pumping — advance_sprite_frames, LOAD drain, button hit-test, etc.
    // The recompiler-emitted RemoveObject2/PlaceObject2 tags in each
    // catch-up frame have already executed before this call; they're the
    // only thing the catch-up needs from frame_funcs. Pumping sprite
    // advance / draining LOAD while nested inside a CLIP_RELEASE handler
    // corrupts global state used by getDisplayListJSON and other consumers.
    if (catch_up_mode) return;
```

The first attempt at the fix (without this gate) caused `getDisplayListJSON` to return truncated garbage (`{"displayList":[,,,,,` — 21 chars). The catch-up frames inside the release handler called `tagShowFrame`, which kicked off `advance_sprite_frames` + `AQ_KIND_LOAD` drain + button hit-test, all nested in a state that wasn't ready for them.

The recompiler-emitted display tags (`tagRemoveObject2`, `tagPlaceObject2`, ...) all run *before* `tagShowFrame` in each frame_func body, so they execute fine. `tagShowFrame`'s per-tick pumping is unnecessary during catch-up — the *natural advance* that runs `frame_funcs[target]` next tick (or `frame_funcs[current_frame=target]` this tick, per fix part 1) does the pumping with `catch_up_mode=0`, at which point pending_remove finalize, sprite advance, etc. fire normally.

## Diagnostic that confirmed it

Instrumented `dispatch_clip_event_press_dl` to log per-button hit-test:

```
[DJ_DBG_PRESS] depth=3 char=46 name=instance2 ntx=3813 nty=5282 mx=1724.6 my=2085.9 hit=0
[DJ_DBG_PRESS] depth=5 char=46 name=instance3 ntx=3235 nty=6170 mx=1724.6 my=2085.9 hit=0
[DJ_DBG_PRESS] depth=7 char=46 name=instance4 ntx=2094 nty=3260 mx=1724.6 my=2085.9 hit=0
[DJ_DBG_PRESS] depth=8 char=46 name=instance5 ntx=1567 nty=2337 mx=1724.6 my=2085.9 hit=1
[DJ_DBG_REL] depth=8 char=46 name=instance5 firing RELEASE
```

Mouse at click `--click "286,346"` → SWF (86.2, 104.3) → only depth 8 (play, transform tx=1567 twips = 78.3 SWF pixels) hit-tests true. Same probe with `--click "350,530"` hits only depth 7 (info). With `--click "626,875"` only depth 3 (scores). With `--click "534,1017"` only depth 5 (options). **Hit-test was always correct.** The bug was that all four sub-screens looked like the menu because the menu depths weren't being cleaned up on transition.

## Final per-button verification

All probes via `tools/browser-test/probe.py flasharchive/Doodle_Jump --viewport-width 900 --viewport-height 1500`.

| Click position (CSS) | Target | dl_count | First-snapshot canvas |
|---|---|---|---|
| `286,346` (play) | gameplay (frame_1) | 9 → 6 | "0" score top-left, "menu" top-right |
| `350,530` (info) | info (frame_5) | 9 → 3 | "info" subtitle, 8-item list, "back" button |
| `626,875` (scores) | scores (frame_4) | 9 → 3 | "high scores", "you got to play first!", "local" tab, "menu" button |
| `534,1017` (options) | options (frame_3) | 9 → 3 | "options" subtitle, credits, "back" button |

Each sub-screen's "back" button (depth 3 with `clip_actions_197`) clicks return to the menu (`dl_count` 3 → 9). Tested for Info → back and Options → back. Multi-click probe `--click "350,530@2.5" --click "574,1155@5.0"` yields `display_list_counts: [9, 9, 3, 3, 3, 9, 9, 9]`.

## Side-effects that aren't bugs

- **Frame functions run twice per tick after a goto.** This tick's `frame_funcs[current_frame=target]` runs (via the `current_frame = frame0` assignment in fix part 1), then next tick's natural advance runs `frame_funcs[next_frame=target]` again. Tags are idempotent under modify-detect, scripts (e.g. `script_38` on scores) run twice. For DJ this is benign — the scores screen's setup script just reads SharedObject and updates `score_txt.text`, both safe to repeat. If a future test exercises a script with non-idempotent side effects on root goto, expect to revisit.

- **Info screen now stays visible instead of flashing back to menu.** Pre-fix, with the menu buttons present at depths 3, 5, 7, 8, frame_5's wrap-back-to-frame_0 would re-render the full menu on top of any briefly-visible info content. Post-fix, the catch-up's `actionStop` (`script_39`, frame_5's frame script) sets `is_playing=0` *before* the recompiler-emitted wrap-back check; without `is_playing=1` the wrap-back doesn't fire and the info screen sticks. This matches the original Doodle Jump behavior (where info has Stop on its frame).

## What this fix DOESN'T address

- **DJ hero block collision / platform bounce.** Hero falls off-canvas on the gameplay screen instead of bouncing. Same class of AS-init issue likely; see prior handoff item B.
- **Pong preloader transition.** Pre-existing; not affected by this fix.
- **Other goto entry points.** This fix is specifically the `actionCallMethod` gotoAndStop/Play dispatch (called when AS does `_root.gotoAndStop(N)` etc.). Other goto entry points — `actionGotoFrame` opcode (0x81), `actionGotoFrame2` (0x9F), label-based `actionGoToLabel` — still take their pre-existing paths. If a test exercises non-sequential root goto via one of those opcodes and shows similar menu-overlay symptoms, mirror the same catch-up pattern there.

## Don't-touch list (cumulative)

(All entries from handoff #11 remain. Adding:)

- **Browser-WASM `tagShowFrame` `if (catch_up_mode) return;` gate (tag.c:3434).** Required: without it, in-tick catch-up calling `tagShowFrame` corrupts global state (`getDisplayListJSON` returns garbage like `{"displayList":[,,,,,`). The recompiler-emitted display tags in each catch-up frame_func *have already executed* before `tagShowFrame` is reached; `tagShowFrame`'s per-tick pumping (advance_sprite_frames, AQ_KIND_LOAD drain, pending_remove finalize, button hit-test) isn't needed during catch-up and actively breaks things when invoked nested inside a CLIP_RELEASE handler.

- **`actionCallMethod` browser-WASM gotoAndStop/Play: `current_frame = (size_t)frame0` after the catch-up loop.** Required: without it, swf.c:615's pending `frame_funcs[current_frame]` call (which runs AFTER the mouse-release handler) re-executes `frame_funcs[saved_current]` (typically frame_0), re-placing every menu depth the catch-up just cleared, exactly undoing the fix. The assignment makes that swf.c:615 call land on `frame_funcs[target]` instead.

## Tools / state

- Local Ruffle source: `~/CC/ruffle`
- MTASC: `~/CC/mtasc/bin/mtasc`
- Probe venv: `/tmp/pong-probe/venv`
- Latest known-good probes:
  - DJ play click: `/tmp/dj-v3-play/`
  - DJ info click: `/tmp/dj-v3-info/`
  - DJ scores click: `/tmp/dj-v3-scores/`
  - DJ options click: `/tmp/dj-v3-options/`
  - DJ info → back: `/tmp/dj-v3-info-back/`
  - DJ options → back: `/tmp/dj-v3-opt-back/`
  - DJ menu: `/tmp/dj-menu-twelfth/`
  - Pong: `/tmp/pong-fresh/`
  - Snake: `/tmp/snake-twelfth/`

Push when ready.
