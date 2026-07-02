# Backlog

Known issues, deferred work, and bugs noted but not yet exercised by a
failing test. Add an entry when you find something worth coming back
to but not worth fixing right now. Remove it when fixed (or when it
turns out to be irrelevant).

**One line per item.** Subsystem heading + bullet with short title,
file:line if applicable, 1-2 sentences body. Date of entry in
parentheses at the end. Sort within each section by date (newest
first).

## What does NOT belong here

- **Parity gaps between graphics-native and NO_GRAPHICS.** CI already
  produces `_results/results_graphics_diff.md` per suite, which lists
  every test that flipped status. Use those during a session; don't
  mirror them here. (This is why the envisioned
  `_investigation/swf_c_parity_backlog.md` never got built.)
- **Test-output divergences with a documented explanation.** Those go
  in `ACCEPTED_DIFFS.md` / `RUFFLE_VS_FLASH_DIFFERENCES.md` /
  `RUFFLE_COMPAT_TWEAKS.md` / `FLASH_BUGS_REPLICATED.md`.
- **In-flight work.** Use a plan doc under `SWFRecompDocs/plans/` for
  anything you're actively designing/executing on.

## Runtime — frame loop / exit gates

- **`swf_core.c` root-stopped exit gate ignores long-lived
  subsystems.** `swf_core.c:1433-1454` breaks the loop when
  `is_playing=0` and no playing sprites/timers/enter-frame handlers/
  events/pending-MCL, but does *not* consult `hasActiveNetStreams()`,
  `hasPlayingSounds()`, or `hasClipEnterFrameHandlers()` the way the
  quit-swf gate at `swf_core.c:1056-1065` does. Currently masks bugs
  (early exit silently terminates the subsystem before it can
  produce wrong output) rather than breaking tests; uncovered while
  diagnosing `avm1/netstream_seek_flv` (2026-05-11) — see playbook
  gotcha #15 for the symptom signature.

## Browser-WASM — rendering

- **Attached-clip morph shapes can't ratio-interpolate per-instance.**
  Morph interpolation is a per-CHARACTER pre-pass into a SHARED vertex
  buffer run over the ROOT display_list only (`tag.c` ~5802);
  `render_display_list` / `render_single_object` draw attached/nested
  morph shapes at `morph_start_offset` (ratio 0). So a morph clip
  reached via `render_attached_child` (attachMovie'd) can't show its
  animated in-between frames, and two on-screen instances of the same
  morph character would collide on the shared buffer. Surfaced by
  Metanet "N"'s particles (DefineMorphShapes animated by per-frame
  ratio): the current N fix (`c9d729168`) sidesteps it —
  `natural_oneshot` "pfx*" particles keep their frame-0 appearance and
  just self-remove on lifetime end (no animation, but no corruption +
  the fps/leftover-line wins). **Proper fix:** per-instance morph
  interpolation — interpolate verts at each instance's `obj->ratio` into
  a dynamic vertex region per draw (like the drawing-API
  `dyn_vtx_staging` path) instead of the shared per-character buffer.
  USER-CONFIRMED current behavior is "good enough for N"; do the proper
  fix when a game needs faithful nested/attached morph animation.
  (2026-06-27)

## Deferred test failures

- ~~**`from_gnash/actionscript.all/case-v6` CI-only flake.**~~ FIXED
  2026-05-30. Was never CI-environment-specific — it was a real
  heap bug masked by heap layout. `case-v5` reproduced the same
  SIGABRT-after-correct-output locally in `--mode=graphics`; ASAN
  pinned three distinct OOBs (all fixed): (1) `compose_children`
  read CPU `transform_data[]` at a runtime-allocated dynamic GPU
  transform slot (no CPU backing) for the gnash `_xtrace_win` trace
  overlay; (2) `textfield_glyph_render_cb` indexed the `glyph_data`
  global for a metrics-only/built-in font with no outlines; (3) the
  load-bearing one — a heap-use-after-free in the variable map:
  `actionSetVariable`/`actionDefineLocal` freed an `old_hash`
  `ActionVar` still owned by `var_array` (SWF≤6 case-folded
  `_LEVEL0`/`_level0` collide to one hashmap key but get distinct
  `var_array` slots), leaving a dangling slot that `freeMap` reads.
  Guarded the free with `variableIsArrayOwned`. case-v5 + case-v6
  now 10/10 in graphics, both still pass NO_GRAPHICS, ASAN clean
  (only pre-existing `u16_concat` Dejagnu leaks). (2026-05-30)
- **`from_gnash/misc-ming.all/place_and_remove_object_insane_test`
  17/22 in graphics-native vs 22/22 NO_GRAPHICS** (was 15/19 vs 19/19;
  upstream line totals grew, gap persists — re-checked against merged
  CI of 2026-06-30, SHA `56970ac27`). Same diff appears in
  `--mode=graphics-headless-legacy`, so the bug is in shared code
  (tag.c or `#ifdef NO_GRAPHICS`-gated tag handling), not swf.c.
  Defer to a tag.c-focused session. (2026-05-11, updated 2026-07-02)
