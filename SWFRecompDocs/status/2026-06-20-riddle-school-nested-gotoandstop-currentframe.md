# Riddle School — nested-sprite `gotoAndStop` didn't sync AS `_currentframe`

**Date:** 2026-06-20
**Game:** flasharchive / Riddle School (612KB), AVM1 point-and-click adventure
**Status:** FIXED (runtime, `SWFModernRuntime/src/libswf/tag.c` `advance_sprite_frames`)
**Bucket:** headless-diagnosable (divergence harness, OFFSCREEN_RENDER)
**Follow-up:** #17(B) in `tools/divergence/PROGRESS.md`

## Symptom

Divergence harness first divergence (after #17(A) `instance68` was absorbed by the
`clip_transient` recognizer):

```
ruffle:    F1 _root.loadingthing.instance65 ... _cf=3
swfrecomp: F1 _root.loadingthing.instance65 ... _cf=1
```

`instance65` pinned at `_cf=1` (with child `bar`) across all 16 frames where Ruffle
holds `_cf=3` (with child `instance69`) — CONSTANT, not a 1-tick lag.

## Structure

- `loadingthing` = `DefineSprite_99`, a named clip placed at root depth 194; it has a
  frame-1 `stop()`, so it parks at frame 1 keeping its children placed.
- `instance65` = an (auto-named) instance of `DefineSprite_35`, placed at depth 1 of
  `loadingthing` — i.e. **nested 2 levels deep** (`_root → loadingthing → instance65`).
- `DefineSprite_35` is a **preloader**:
  - frame 1: `_root.stop(); PercentLoaded = getBytesLoaded/getBytesTotal*100;
    if (PercentLoaded != 100) setProperty(bar,_xscale,...) else gotoAndStop("loaded");`
  - frame 2: `gotoAndPlay(1);` (loop)
  - frame 3 (label `"loaded"`): removes `bar`, places `DefineSprite_34` (= `instance69`).

On a fully-loaded local SWF `PercentLoaded == 100` (both `getBytesLoaded` and
`getBytesTotal` return `root_movieclip.byte_size`), so the `gotoAndStop("loaded")`
branch runs — matching Ruffle's headless exporter.

## Root cause (runtime-instrumented, not guessed)

`gotoAndStop("loaded")` recompiles to `actionGoToLabel(app_context, "loaded")`. The
sprite-local label path resolved correctly (`g_current_sprite_obj` = instance65,
`ng_findSpriteLabelFrame(35,"loaded") = 2`) and `ng_gotoFrameCurrentSprite(2)` set
the deferred manual-nav state (`sprite_manual_next_frame=1`, `sprite_next_frame=2`,
`sprite_is_playing=0`).

The deferred top-of-loop manual-nav block in `advance_sprite_frames` then DID apply
the goto one tick later: instrumentation showed `sprite_current_frame` advance 1→2
and the sprite display list correctly rebuild to the "loaded" frame
(`depth 1 char 34 instance69`, `bar` removed), and `mc->display_obj == obj`.

**The bug:** the manual-nav branch sets `obj->sprite_current_frame = target` but
never syncs the **AS-visible** `MovieClip->currentframe`. The normal-advance path
does (`smc->currentframe = frame+1`, tag.c ~1283), but the manual-nav branch
`continue`s past it. For a `gotoAndStop` (`is_playing==0`) the omission is
**permanent**: once stopped, the sprite takes the `advance_sprite_children_only`
branch every later tick and never re-syncs `currentframe`. So the MovieClip
reported its pre-nav frame (1) forever even though the playhead + display list
navigated correctly.

`gotoAndPlay` masked this everywhere else (Avalanche `instance1`): a still-playing
clip's normal advance re-syncs `currentframe` the very next tick. Only a stopped
nested clip exposes it. The tracer reads `mc._currentframe` (→ `currentframe`) and
enumerates children via `mc->display_obj->sprite_display_list` — so the children
flipped to `instance69` correctly (DL was right) while `_cf` stayed stale.

## Fix

In `advance_sprite_frames`, after `obj->sprite_current_frame = target;` in the
manual-nav branch, mirror the normal-advance sync:

```c
if (obj->instance_name != NULL) {
    extern MovieClip* actionFindMovieClipByName(const char* instance_name);
    MovieClip* smc = actionFindMovieClipByName(obj->instance_name);
    if (smc) smc->currentframe = (int)target + 1;
}
```

Covers both the backward and forward manual-nav branches (both end at the shared
`sprite_current_frame = target`). Shared runtime code (`tag.c` `advance_sprite_frames`
compiles in NO_GRAPHICS / OFFSCREEN / graphics) → CI both modes.

## Result

`instance65` now reports `_cf=3` from F2 onward and is recognized as a
`clip_transient` self-healing clip (only F1 diverges, via the one-tick-late
gotoAndStop = deferred #10b class). Local sanity: `goto_label`, `goto_methods`,
`goto_execution_order`, `tell_target_invalid_swf6`, `goto_both_ways1` all PASS.

## Residuals (new follow-ups, NOT this fix)

1. **F1 one-tick-late** — at F1 swfrecomp still shows `bar` (frame 1); Ruffle applies
   the `gotoAndStop` same-tick (shows `instance69`). The documented deferred #10/#10b
   class (same as `instance68`). Now absorbed by the `clip_transient` recognizer for
   `instance65` itself, but its child appears as a `bar`↔`instance69` swap at F1.
2. **`instance65.instance69 _cf=2` vs Ruffle `_cf=1`** (constant F2–F15) — a SEPARATE
   timing bug surfaced by this fix: `instance69` (`DefineSprite_34`, frame-1 `stop()`,
   a hover button whose `onClipEvent(enterFrame)` does `hitTest(_xmouse,_ymouse) ?
   nextFrame() : prevFrame()`) auto-advances 1→2 after being placed during the goto
   catch-up, instead of being held at frame 1. Independent of the `currentframe`
   sync. Likely a freshly-placed-during-goto nested clip running past its frame-1
   `stop()` and/or its clip-action enterFrame not holding it. Left as a follow-up.
3. `$version` LNX/WIN — known accepted platform-string diff.

## Repro / regression gate

```bash
python3 tools/divergence/divergence_test.py "$HOME/CC/flasharchive/Riddle School.swf" \
    --frames 16 --skip-ruffle
# instance65 recognized as self-healing; first divergence = F1 instance69/bar swap.
```
