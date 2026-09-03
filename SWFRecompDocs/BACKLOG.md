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

- ~~**The child-movie char-id offset list is hand-maintained and known
  incomplete.**~~ **DONE 2026-09-03.** The list is gone. The recompiler now
  wraps every character id it emits in `CHARID(...)` (identity macro in
  `SWFModernRuntime/include/libswf/tag.h`, emitted by `charId()` in
  `SWFRecomp/src/swf.cpp`), so `generate_child_movie_file` does **one**
  value-keyed substitution — reaching struct-initialiser fields
  (`FramePlacement.char_id`, `SpriteFrameScriptEntry.char_id`) that no
  call-name-keyed scheme could see. Completeness is now detected rather than
  hoped for: `scripts/check_charid_wrapping.py` derives the char-id argument
  positions and struct field indices from the runtime headers and hard-fails
  `generate_child_movie_file` on a bare integer literal in one. Anchored by
  `regression/avm1_parent_child_sprite_meta`. Two corrections to the entry
  this replaces: `tagSetSpriteLabels` was NOT broken (it takes no
  `app_context`, so no regex ever matched it, and its raw registration happened
  to be the only one with that key — it worked by accident, and two movies with
  sprites at the same raw id would have shadowed each other); and the old
  regexes **offset char id 0**, turning every Modify `PlaceObject2` in a loaded
  child into a place of character 1000 — 0 is the "no character" sentinel and
  is now excluded. Closeout:
  `SWFRecompDocs/status/child-movie-charid-wrapper.md`. (2026-09-03)
- ~~**The AVM1 and AVM2 child-character-id strides disagree.**~~
  **DONE 2026-09-03.** One stride, owned by the recompiler. `charId()`
  (`SWFRecomp/src/swf.cpp`) adds `Config::char_id_base` to every character id
  the TAG pipeline emits, alongside the ABC/AVM2 emissions that already had
  it, and the harness's `CHARID()` substitution is gone (the wrapper is still
  emitted — `scripts/check_charid_wrapping.py` keys on it). `char_id_base`
  now means what `config.hpp` always said it meant.
  **Stride ruling: 1000, unifying DOWNWARD**, because the AVM1 dictionary is
  `INITIAL_DICTIONARY_CAPACITY` = 8192 and a 10000 stride puts the FIRST
  child's characters past it. Anchored by
  `regression/avm2_parent_child_symbol_stride` (a lock — no trace-visible
  repro of the disagreement exists, since AVM2 never reads the AVM1
  dictionary) and `regression/avm1_parent_child_modify_place`. Closeout:
  `SWFRecompDocs/status/child-charid-stride-unify.md`. (2026-09-03)
- **The dictionary bound is checked against a CONSTANT in places, and against
  the growable variable in others.** `tag.c` grows `dictionary` with
  `ENSURE_SIZE(..., dictionary_capacity, ...)` and mostly bounds-checks
  against that variable — but `tag_stubs.c` (NO_GRAPHICS / HEADLESS, whose
  `swf_core.c` never grows the array at all) checks
  `char_id >= INITIAL_DICTIONARY_CAPACITY` at :414/:883/:1511 and indexes
  `dictionary[cid]` UNGUARDED at :1509, and `action.c`'s three button-MC
  probes (:54533, :55121, :55189 — every build mode, not just no-graphics)
  compare against the constant too. tag.c's own browser-WASM-only arms
  (:9628, :9647, :10190, :10204) do the same. So any character id at or above
  8192 reads back as "no such character" in code that looks bounds-safe, and
  in NO_GRAPHICS worse than that. Nothing trips it today — the stride is 1000
  and the corpus has at most two children — but it is what caps a child at
  999 characters, and it is the work item for whoever needs to raise the
  stride. (2026-09-03)
- ~~**`embedded_bitmap_for_char` never consults child movies.**~~
  **DONE 2026-09-03**, and it was three defects with two layers each, not one
  six-line loop. The table fall-through the entry described is necessary and
  **not sufficient**: every embedded-asset constructor keys on
  `avm2_display_char_for_class`, whose `g_symbol_map` is built once at stage
  build from the MAIN movie's SymbolClass rows, so a child-defined asset class
  resolved to char **0** and never reached any payload table. Both layers are
  load-bearing (reverting either alone puts `child:pix` back to `0x0`). The
  same two-layer miss was then reproduced and fixed on the other two embedded
  tables — `[Embed(mimeType="application/octet-stream")]` -> `ByteArray`
  (`avm2_bytearray.c` `ba_native_init`, read `length 0`) and `[Embed]` MP3 ->
  `Sound` (`avm2_media.c` `sound_ctor` / `sound_data_for_char`, read
  `length 0`). Ruling: these key on the **defining** movie, the opposite of the
  transform-table case, because the thing looked up is a payload and both ends
  of the lookup are already the class's own movie. `import_assets` 3/3 and
  gnash `attachImported`/`attachExtImported` confirmed unmoved. Anchored by
  three new rows in `regression/avm2_parent_child_symbol_stride`. Closeout:
  `SWFRecompDocs/status/child-embedded-asset-lookup.md`. (2026-09-03)
- ~~**`_x` on a loaded child's TAG-PLACED clip reads uninitialized memory.**~~
  **DONE 2026-09-03.** It was an out-of-bounds read, not an unwritten field: a
  display entry's `transform_id` indexes the transform table of the movie whose
  TAG placed it, and every AVM1 reader indexed the MAIN movie's
  `transform_data` — `float transform_data[1][16]` for an MTASC parent with no
  timeline content, so a child's tid 1 read past the end. `ng_cache_transform`
  now records the placing movie's table on the entry
  (`DisplayObject::place_transform_data`) and the readers go through
  `ng_entryTransformData`. `regression/avm1_parent_child_modify_place` pins
  `_x`/`_y` and now DISCRIMINATES on the char-id-0 sentinel as well. Closeout:
  `SWFRecompDocs/status/child-placed-clip-uninit.md`. (2026-09-03)
- **A loaded child movie's timeline never advances past frame 0.**
  `actionFirePendingDirectLoads` runs the child's `child_frame_0` and nothing
  ever calls `child_frame_1`: verified by breaking on `tagPlaceObject2` for a
  2-frame child whose frame 2 carries a `PlaceObject2` — exactly one call, from
  `child_frame_0`. So every tag past a loaded child's first frame is dead, and
  a child SWF used as an animation plays only its first frame. Found while
  fixing the `_x` read above; it is the real reason the earlier
  `avm1_parent_child_modify_place` could not discriminate (its Modify sat in
  frame 2), and the current test places and modifies in ONE frame to sidestep
  it. No corpus test grades it — the multi-SWF children in the suite are all
  single-frame or read only metadata. (2026-09-03)
- **A loaded child movie does not render at all — the renderer has no
  per-movie tables.** Rewritten 2026-09-03 from "a loaded child's bitmaps never
  reach the renderer", which named one facet of it. The bitmap gates are real
  and measured (`avm1_parent_child_bitmap --mode=graphics`, instrumented: the
  root uploads then finalizes, then the child's `defineBitmap` arrives with
  **both** gates closed — `bitmap_static_built=1` **and**
  `current_bitmap >= bitmap_count` — and every movie's `tagInit` calls
  `finalizeBitmaps()`). But lifting them renders nothing, because a static
  bitmap is only sampled by a shape and a child's shapes are not on the GPU
  either: the vertex buffer is uploaded once from the ROOT's `shape_data`
  (`swf.c:1581` -> `create_buffers_and_upload`), while
  `renderer_draw_shape(ctx, ch->shape_offset, ..., obj->transform_id,
  obj->cxform_id)` passes movie-LOCAL indices, and a bitmap fill style bakes a
  movie-local bitmap index (`swf.cpp:7462`/`:7877`). `MovieEntry` carries
  exactly one render array (`transform_data_ptr`) and it is CPU-only. So the
  work item is: per-movie render tables on `MovieEntry` (shape/color/gradient/
  uninv + the bitmap range), per-movie bases applied at draw time, and a
  growable static slot table with a re-entrant finalize (the static pools are
  size-classed — read memory `bitmap-texture-pools` before sizing anything).
  There is also **no trace-visible assertion available**: every AS-visible read
  of a child bitmap goes through the metadata/table paths, both now fixed, so
  nothing in ActionScript can observe `ctx->bitmap_sizes`. Worth taking after
  the frame-0 timeline entry above — a child that renders only frame 1 is a
  thin prize. Detail: `SWFRecompDocs/status/child-embedded-asset-lookup.md`
  section 3. (2026-09-03)
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
