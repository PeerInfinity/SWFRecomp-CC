# Riddle School #17(B2) — freshly-placed nested clip advanced past its frame-1 `stop()` on its placement tick

**Date:** 2026-06-21
**Game:** flasharchive / Riddle School (612KB), AVM1 point-and-click adventure
**Status:** FIXED (runtime, `SWFModernRuntime/src/libswf/tag.c` `advance_sprite_frames`)
**Bucket:** headless-diagnosable (divergence harness, OFFSCREEN_RENDER)
**Follow-up:** #17(B2) in `tools/divergence/PROGRESS.md` (surfaced by the #17(B) fix, `370dc2c7d`)

## Symptom

After #17(B) fixed `instance65`'s `_currentframe` sync, the next divergence was a
constant (F2–F15) mismatch on the doubly-nested hover button:

```
ruffle:    F2..F15 _root.loadingthing.instance65.instance69 ... _cf=1
swfrecomp: F2..F15 _root.loadingthing.instance65.instance69 ... _cf=2
```

`instance69` held at `_cf=2` where Ruffle holds `_cf=1`, constant across all frames.
(The only other F2+ diff is the accepted `$version` LNX/WIN string.)

## Structure

- `instance69` = an instance of `DefineSprite_34` — a **16-frame** hover-button
  animation (SWF tag header `22 00 10 00` = chid 34, 16 frames), frame 1 = `stop()`.
  Its `onClipEvent(enterFrame)` does
  `if (this.hitTest(_root._xmouse,_root._ymouse,true)) this.nextFrame(); else this.prevFrame();`
  (clip actions baked into its PlaceObject2: flag byte `0x96` has bit 7
  HasClipActions set).
- It is placed at depth 1 of `instance65`'s frame 3 ("loaded") — i.e. **3 levels
  deep** (`_root → loadingthing → instance65 → instance69`) — *during* `instance65`'s
  `gotoAndStop("loaded")` catch-up.
- Ruffle holds it at frame 1: headless mouse at origin → `hitTest` false →
  `prevFrame()` is a no-op at frame 1.

## Root cause (runtime-instrumented, not guessed)

Per-tick instrumentation on char 34 (gather / advance / exec / stop / process-init)
gave the full tick-2 sequence:

1. `[exec] scf=0 cm=1` — `instance65`'s `gotoAndStop("loaded")` catch-up places
   `instance69`; `tagPlaceObject2`'s eager-init runs its frame_0 with
   `catch_up_mode=1` (scripts **suppressed**), builds the DL, then sets
   `sprite_current_frame = 1 % 16 = 1` (the "frame_0 built, playhead at next frame"
   convention, `tag.c:7522`). The frame-1 `stop()` did **not** run (suppressed).
2. `[adv] scf=1 playing=1 cm=0` — `instance65`'s manual-nav (gotoAndStop) recursion
   (`tag.c:1207`, runs with `catch_up_mode=0`) reaches `instance69`.
3. `[adv-post] ADVANCED frame 1->2 playing=1` — it **advances** `sprite_current_frame`
   1→2 (and writes `mc->currentframe = frame+1 = 2`).
4. `[stop] scf=2` — the deferred frame-1 `stop()` finally drains, setting
   `is_playing=0` — but only **after** the advance already moved it to frame 2.

So `instance69` advanced past frame 1 **on its placement tick**, before its
(deferred) frame-1 `stop()` could hold it. Two corroborating facts:

- `sprite_initialized` stayed **0** for `instance69` the entire run — its
  clip-action `onClipEvent(enterFrame)` (the `hitTest→prevFrame` that would *also*
  hold it at frame 1) never fired (`gather_clip_ef_entries` skips `init < 2`). So
  there was no recovery path either.
- `advance_nested_sprite_frames` (the Phase-3 nested pass) and
  `presync_nested_cf_recurse` both already skip clips placed this tick
  (`obj->placed_at_tick == g_tick_count` — Ruffle's clip_exec_list "captures `next`
  before processing" semantics; the Pong `sprite_9` plan,
  `defer-newly-placed-sprite-advance-plan.md`). But the **recursive
  `advance_sprite_frames` path used by a parent's manual-nav catch-up had no such
  guard**, so the deeply-nested freshly-placed clip got advanced there.

## Fix

Add the established placed-this-tick skip to the recursive `advance_sprite_frames`
per-sprite loop, scoped to:
- **non-deferred contexts** (`!g_advance_defer_nested`) — the Phase-1 root pass runs
  with the defer flag set and defers nested advance to Phase 3 (which already
  guards); the manual-nav / `advance_sprite_children_only` / `advance_nested`
  per-root recursions run with it clear, and those are exactly where a deeply-nested
  clip placed this tick is reached.
- **already-built clips** (`!just_allocated`) — a genuinely new clip still builds its
  frame 0 normally; only a clip whose DL already exists (e.g. built by the catch-up
  eager-init) is prevented from advancing on its placement tick.

```c
if (!g_advance_defer_nested && !just_allocated)
{
    extern size_t g_tick_count;
    if (obj->placed_at_tick == g_tick_count)
        continue;
}
```

Shared runtime code (`tag.c` `advance_sprite_frames` compiles in
NO_GRAPHICS / OFFSCREEN / graphics) → CI both modes.

## Result

`instance69` now reports `_cf=1` from F2 onward (matches Ruffle on F2/F8/F15…) and
is recognized as a `clip_transient` self-healing clip. The harness reports
**`Trace: converged (modulo 3 self-healing / documented observer-artifact line(s))`**
for Riddle School — `instance68`, `instance65`, and `instance69` each diverge only on
F1 via the deferred #10b one-tick-late `gotoAndStop` artifact (residual #1, tooling
class, not chased).

Local gates (all PASS): `goto_label`, `goto_methods`, `goto_execution_order`,
`tell_target_invalid_swf6`, `goto_both_ways1`, plus `goto_advance1/2`,
`goto_both_ways2`, `goto_execution_order2`, `goto_rewind1`, `goto_frame`,
`clip_events`, `clip_event_propagation_order`, `placeobject_all_event_flags`,
`bad_placeobject_clipaction` (15/15).

## Residuals (NOT this fix)

1. **F1 one-tick-late** `gotoAndStop` (`instance65.bar`↔`instance65.instance69` swap
   at F1) — the documented deferred #10/#10b unified-exec-list class (same as
   `instance68`). Absorbed by the `clip_transient` recognizer. Do not chase.
2. `$version` LNX/WIN — known accepted platform-string diff.

## Repro / regression gate

```bash
python3 tools/divergence/divergence_test.py "$HOME/CC/flasharchive/Riddle School.swf" \
    --frames 16 --skip-ruffle
# Riddle School: Trace converged (3 self-healing clips, all F1-only).
# instance65 still self-healing (_cf=3 from F2); instance69 now _cf=1 constant.
```
