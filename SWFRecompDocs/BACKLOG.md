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

## Native windowed graphics (assessment: `reference/native-windowed-graphics-assessment.md`)

- **flashbang backend: delete or fold into render_webgpu.c.** Second
  SDL3-GPU renderer (`src/flashbang/`, 993 lines) with shaders frozen at
  Nov 2025, a Vulkan+glslc toolchain the primary path avoids, weaker
  input, no CI; render_webgpu.c already serves all three surface configs.
  Still the default CMake graphics branch — flip that when removing.
  (2026-07-23)
- **Playable native windowed AVM1 game ≈ Medium, 3 steps.** Build wiring
  (S — `build_test.sh --graphics native` omits sdl3webgpu.c + SDL3/Dawn
  link; SDL3 vendoring itself was repaired in `8d843cd8e`), keyboard
  events → AVM (S — native SDL pumps are ESC-only; mouse already works),
  SDL3 audio sink (S-M — native `audio_output_*` arm is an empty stub).
  Also: native pacing is vsync-only, SWF frameRate ignored. (2026-07-23)

## AVM2 — GC / memory

- **Reevaluate the two accepted GC leak residuals** when requirements
  change (e.g. truly indefinite/overnight browser sessions, or a game
  that churns listener-bearing orphans). (1) `fn_scope` over-retain,
  ~1.03 KB/tick in RWK gameplay: freeing at closure sweep is a PROVEN
  UAF (`avm2_op_newactivation` aliases the chain as `method_scope` in
  activation vtables — memory `avm2-raw-alloc-reclamation`); the real
  fix is refcounted or GC-traced scope chains, a dedicated project.
  (2) Orphan display objects WITH event listeners never die: the
  enterFrame broadcast registry (`avm2_events.c g_broadcast`) is
  deliberately STRONG (Ruffle's is weak) so listener-bearing orphans
  tick deterministically under `AVM2_GC_STRESS=1`; weakening it would
  regress orphan tests (memory `avm2-weak-orphan-registry`). Current
  burn rates (~1.85 MB/min RWK worst case, ≈1.85 GB headroom → 16+ h)
  make both harmless today; revisit if headroom shrinks or session
  lengths grow. (2026-07-18)

## Multi-SWF (loaded children)

- **The child-movie char-id offset list is hand-maintained and known
  incomplete.** `generate_child_movie_file` (`ruffle-tests/verify_output.py`)
  adds `movie_id * 1000` to a child SWF's character ids with **one `re.sub`
  per emitted call name**, so any call the list does not name keeps its RAW id
  and silently disagrees with every call that was offset (memory
  `child-movie-charid-offset-per-callsite`). Audited 2026-09-03 while fixing
  `defineBitmap`: **four regexes are dead** — `tagDefineEditText`,
  `tagDefineFont`, `tagDefineSoundMeta`, `tagDefineVideoMeta` name calls the
  recompiler no longer emits — and these LIVE char/font/sprite-id calls are
  unoffset while `tagDefineSprite` / `tagRegisterExport` / `tagPlaceObject2*`
  are: `tagSetSpritePlacements`, `tagSetSpriteFrameCounts`,
  `tagSetSpriteLabels`, `tagSetSpriteNoEndTag` (**half-applied today**, since
  the sprite they describe IS offset), `tagDoInitActionGuarded`,
  `tagPlaceObject3`, `tagReplaceObject2RatioWithClipActions` (the
  `tagPlaceObject2\w*` regex matches neither name), `tagDefineEditTextProps`,
  `tagDefineText`, `tagCSMTextSettings`, `tagDefineFontGlyphBase`/`Info`/
  `Metrics`, `tagDefineVideoStream`, `tagVideoFrame`, `tagImportCharacter`,
  and `tagDefineButton`'s 4th argument `hit_char_id`. No failing test covers
  any of them. **Take them a PAIR at a time with a failing test each** —
  moving a define without its consumers is exactly how the `tagDefineSound`
  pair broke; sprite metadata first, as the one that is provably inconsistent
  rather than merely uniformly raw. Full inventory and reasoning:
  `SWFRecompDocs/status/child-movie-bitmap-registry.md` §"Audit". The real fix
  is to stop it being a list of regexes at all — give the emitted calls a
  wrapper the harness can key on. (2026-09-03)
- **A loaded child's bitmaps never reach the renderer.** Two gates, both
  stated in the ROOT movie's terms: `finalizeBitmaps()` is emitted at the end
  of the root's `tagInit` so `render_webgpu_upload_bitmap` early-returns on
  `bitmap_static_built`, and the static slot table is sized by the root's
  `BITMAP_COUNT` (`ctx->current_bitmap >= ctx->bitmap_count`). So a child's
  `defineBitmap` calls are dropped and its bitmaps do not render — a missing
  feature, not a corrupt read. `BitmapData.loadBitmap`, the AS-visible path,
  was fixed 2026-09-03 and the renderer now stores per-bitmap pointers
  (`ctx->bitmap_ptrs`) rather than root-relative offsets, so lifting these
  gates cannot re-inherit the wrong-array bug; what is left is giving the
  renderer a per-movie static-bitmap range. No corpus test exercises it.
  (2026-09-03)
- **`flashbang_upload_bitmap`'s offset bug is fixed but untested.** The SDL3
  backend read `((u32*)context->bitmap_data)[bitmap_pixel]` — the start of the
  array — for every bitmap, so every bitmap after the first uploaded the first
  one's pixels. Fixed 2026-09-03 in passing when the call started taking a
  pointer. Nothing in CI grades flashbang (see "flashbang backend: delete or
  fold into render_webgpu.c" above), so the fix is unverified beyond
  inspection. (2026-09-03)

## Deferred test failures

- **`avm2/edittext_align` intermittent segfault after byte-correct output
  (60/60) in graphics CI.** Seen once (run 30053137733, 2026-07-23);
  passed the 5 prior CI runs and 4/4 locally. This is the exact
  SIGABRT/segfault-after-correct-output signature of case-v6 (entry
  below), which sat mislabeled as a "CI flake" for two months and was
  actually 3 heap bugs — and was DETERMINISTIC under ASAN where bare
  runs were ~50/50. If it recurs even once: do not triage-and-move-on;
  run `verify_output.py --test=edittext_align --mode=graphics --asan`
  first. (2026-07-23)

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
