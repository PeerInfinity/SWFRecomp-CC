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
- **A morph shape's hitTest bounding box is its START bounds and does not
  follow the ratio.** `ng_computeBoundsFromDL_matrix` (and every other bounds
  walk) calls `ng_getCharBounds`, which returns what `tagDefineMorphShape`
  recorded — the START rectangle. `ng_getCharBoundsForRatio` exists and IS used
  by the shape-accurate morph hit test's own fallback, but the AABB fast reject
  in FRONT of that walk is not ratio-aware, so a morph placed at a high ratio
  can be rejected before its outline is ever compared. Surfaced while building
  `regression/avm1_parent_child_morph`, which works around it by giving the
  morph a START rectangle that contains its END one. Cheap fix: give the bounds
  walks the entry's `ratio` and route them through `ng_getCharBoundsForRatio`.
  (2026-09-04)

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
- ~~**A loaded child movie's timeline never advances past frame 0.**~~
  **DONE 2026-09-03**, and the entry's own framing was half wrong. The per-tick
  child-movie playhead already existed (`g_level_advance` /
  `actionAdvancePlayingLevels`), was already wired into both main loops, and
  `MovieClipLoader.loadClip` already registered clip targets with it. What was
  frozen was the DIRECT `loadMovie` path alone: its registration carried an
  extra `loads[i].is_level &&`. Dropping that gate is the core of the fix.
  Around it: the playhead's frame cursor AND play flag live on the advance-table
  entry (the only per-LOAD thing there is), routed to explicitly at four sites
  that all used to fall through to the ROOT's `is_playing` -- `actionStop` /
  `actionPlay` reached from the movie's own frame script, and the `stop`/`play`
  arms of `actionCallMethod` reached as `holder.stop()` from the parent (which
  stopped the ROOT); a load no longer runs two of the movie's frames on its load
  tick (direct clip loads only -- see the next entry); and two further defects
  fell out. The recompiler's end-of-movie wrap emission (`next_frame = 0;
  manual_next_frame = 1;`) is the MAIN movie's globals and a child reaching its
  last frame rewound the PARENT (guarded in the runtime at all three
  `MovieEntry` frame-call sites -- the harness strips the sibling
  `quit_swf = 1;` but never saw this one); and registering the playhead AFTER
  the movie's frame 1 overwrote a `stop()` in that frame (the preloader shape;
  hoisted ahead of `frame_funcs[0]` in both loader paths). Anchored by three
  new fixtures -- `regression/avm1_child_timeline_advance`,
  `avm1_child_timeline_holder_stop`, `avm1_child_timeline_frame1_stop` -- each
  asserting a per-tick SEQUENCE with negative controls in both directions.
  AVM1 only; AVM2 `Loader.load` was never frozen (its AVM1 children run on
  `g_avm1u2`, which already loops). **Looping is NOT part of this** -- see the
  next entry. Closeout:
  `SWFRecompDocs/status/child-timeline-advance.md`. (2026-09-03)
- ~~**A loaded movie does not LOOP, because it does not own its display
  children.**~~ **DONE 2026-09-03** -- and it did NOT need per-movie display
  lists. A loaded movie now wraps from its last frame to its frame 1 (Ruffle
  `determine_next_frame` -> `NextFrame::First`), clearing its own display
  children on the way. Ownership is one field on the display entry --
  `DisplayObject::placed_by_holder`, the HOLDER whose frame tag placed it,
  written at the two new-entry `PlaceObject2` sites from
  `actionCurrentChildMovieMC()` -- not a private `sprite_display_list`.
  **Deviation from the entry this replaces: the field records the holder, not
  `g_current_movie_id`.** The two disagree for the same file loaded into two
  different holders, which is one movie id but two independent playheads;
  looping is a per-LOAD question. Two defects fell out of the audit: the clear
  has to walk BOTH the active list and the global one, because the driver swaps
  to a timeline-clip holder's private sprite list but neither loader does (so
  such a movie's frame 1 is in one list and its frames 2..N in the other -- a
  pre-existing asymmetry); and the driver's copy-out **resurrected a playhead
  that `unloadMovie` had unregistered mid-frame**, the same class as the
  predecessor's `stop()` write-back bug, now fixed by re-reading the live slot.
  Anchored by `regression/avm1_child_timeline_loop` (two out-of-phase loaded
  movies, so every wrap is a live over-clearing control) plus the deliberate
  flips of `avm1_child_timeline_advance` and `avm1_child_timeline_holder_stop`,
  whose park rows the predecessor wrote as a lock to be broken. CI corpus-clean
  in BOTH modes at `82f27e5f9`, `categories=full`, `images=false` -- graphics
  run `33833019835` (4365 effective, +0, every bucket unmoved) and no-graphics
  run `33835560435` (4366, +0); `regression` 81/81 in both. Closeout:
  `SWFRecompDocs/status/per-movie-display-list-ownership.md`. (2026-09-03)
- **Per-movie display-list ownership (Route 1) is a SUB-ARC, and its shape is
  now measured.** The brief's decisive question -- what
  `avm1/movieclip_invalid_get_bounds_1..8` actually read from `display_obj` --
  has one answer: **the onEnterFrame eligibility gate** (`action.c:37058`),
  whose `enterframe_eligible` flag is armed by a display-list walk that a
  loaded movie's root is not in. The runtime already had the escape hatch for
  the identical `_levelN` case (`actionIsLoadedLevelRootMC`); widening that one
  predicate is two lines and recovers six of the eight. So the 48
  `display_obj != NULL` sites do NOT need a different predicate -- 47 were
  never the problem. Three work items remain, in order: (1) widen the
  predicate; (2) make the loaders swap for clip targets like the driver does,
  and fix the fallout (`getBounds`'s loaded-child fallback becomes dead code,
  `unloadMovie` must clear a list it now owns, the two-list clear collapses to
  one); (3) the hard one -- **the swap is call-scoped, not movie-scoped**.
  `avm1/swf{5_to_6,6_to_5}_cross_call` was bisected to the direct-`loadMovie`
  swap alone and then instrumented: the child calls back into `_root.onLoaded()`
  during its own frame 1, so the parent's whole test block runs INSIDE the swap
  and resolves names against the child's list. A single global `display_list`
  pointer cannot express ownership while two movies' code is on the stack, so
  either name resolution takes its list from the clip being resolved against,
  or the swap is pushed down to the placement/lookup sites. `_levelN` has
  carried the same hazard all along, ungraded. Detail:
  `SWFRecompDocs/status/per-movie-display-list-ownership.md` §1-2. (2026-09-03)
- **Our MovieClipLoader load completes a tick later than Flash's.** A loaded
  movie used to run TWO of its frames on its load tick (the loader calls
  `frame_funcs[0]`; the per-tick driver runs in the same tick right after it).
  Direct `loadMovie` clip targets now get one frame per tick; `_levelN` and MCL
  targets deliberately keep the double step, because removing it breaks
  `from_shumway/avm1/moviecliploader` -- `num_frames = 3`, and it only reaches
  its loadee's `loadee frame 2` because of the double step. So the double step
  is compensating for a load that lands a tick late. Fixing the load timing
  would let `armed` apply uniformly. Also open on the same paths:
  `holder.gotoAndStop(n)` does not target the loaded movie's frames (the
  `ng_goto*` entry points need a `CHAR_TYPE_SPRITE` dictionary character and a
  loaded holder has none), browser-WASM never advances a loaded movie at all
  (`swf.c`'s driver call is inside `#ifdef OFFSCREEN_RENDER`), and a second
  load into the same holder does not clear the first movie's children -- now
  CHEAP to fix, since `actionRegisterChildMovieAdvance` replacing an entry is
  the exact moment and `actionClearChildMoviePlacements` is the exact call;
  left undone deliberately in slice 6 (a behaviour change on the
  `mcl_replace_root_*` / `load_cancel_*` cluster with no fixture demanding it).
  (2026-09-03)
- ~~**A loaded child movie does not render at all — the renderer has no
  per-movie tables.**~~ **DONE 2026-09-04.** A loaded child's shapes reach the
  GPU with per-movie bases, and its solid, gradient and bitmap fills all sample
  the right rows. Three re-basing strategies, because the three kinds of index
  are known at three different moments: the vertex offset is baked into the
  CHARACTER at `tagDefineShape` (one site instead of the ~10
  `renderer_draw_shape` calls); the colour / gradient / bitmap indices are baked
  into the VERTEX at combine time, because a fill style's style word is written
  at recompile time and no draw-time argument can reach it; and `transform_id` /
  `cxform_id` are re-based at PLACEMENT time inside `ng_cache_transform`, which
  all 14 `tagPlaceObject*` sites already funnel through — that single write
  makes the id a combined-table index for all ~45 of its readers without
  touching one of them (keyed on `g_active_transform_data`, the only signal that
  tracks the placing movie through both the loaders and `exec_sprite_frame`).
  **The entry's own correction: the growable static slot table with a re-entrant
  finalize is NOT needed and would have been the wrong answer.** The set of
  movies a build can load is fixed at link time, so every child's bitmap count
  and sizes are static data: the recompiler now emits `bitmap_descs[][4]` beside
  the pixels and `ng_predeclareChildBitmaps()` fills the child slots between
  `renderer_init` and the root's `tagInit`, leaving `build_static_bitmap_pools`
  dimensioned exactly once with no growth and no texture freed under a recorded
  draw. And there IS a trace-visible assertion for the shape half, which slice
  4's ruling (correct for bitmaps) had been generalised too far: `path_data` is
  a second per-movie geometry array read by `shape_hit_test.c`, so
  `mc.hitTest(x, y, true)` on a child's shape tested the ROOT's outline. Anchored
  by `regression/avm1_parent_child_render` (5 hitTest rows, 2 of which flip, plus
  a 4-square tolerance-0 image comparison) and
  `regression/avm1_parent_child_bitmap_fill` (pixels only). CI corpus-clean in
  BOTH modes, `categories=full`, `images=false` — graphics `33849507561`
  (4367 effective, every bucket +0) and no-graphics `33854435965` (4368, +0);
  totals 4492 -> 4494 graded, the +2 being the two fixtures. One deliberate
  `images=true` run (`33857494837`) moved the pixel baseline **+1 beyond those
  fixtures, 0 regressions**: `import_assets/avm1_imports_avm1` flipped
  fail -> pass, attribution confirmed by a local revert A/B (17755 outliers
  reverted, 459 with the slice) while the run's two other movers measured
  IDENTICAL both ways and belong to the 16-day gap since the previous images
  run. That test is the correction to this entry's own framing: an
  `ImportAssets` character is DEFINED by the child, so it hits the same
  `tagDefineShape` re-base a `loadMovie`'d one does — the `import_assets` suite
  is a standing canary for this mechanism. Closeout:
  `SWFRecompDocs/status/per-movie-render-tables.md`; what it does NOT cover is
  §5 there and the next four entries here. (2026-09-04)
- ~~**Static text and morph shapes in a loaded child still draw the root's
  glyphs.**~~ DONE 2026-09-04 (multi-SWF slice 8). `text_data`,
  `text_char_codes` and `glyph_data` are combined in EVERY build mode (the CPU
  glyph hit tester and TextSnapshot read them in NO_GRAPHICS too);
  `morph_end_shape_data` / `morph_end_color_data` in graphics builds only,
  matching `color_data`. `tagDefineText` re-bases `text_start`,
  `transform_start` and `cxform_id`; `tagDefineMorphShape` re-bases
  `morph_end_offset`, `morph_color_start` and `morph_end_color_start`;
  `tagDefineFontGlyphBase` re-bases the font's glyph base. Two arrays needed
  their CONTENTS re-written at combine time as well (a `text_data` row is a
  glyph index, a `glyph_data` row is a vertex offset), and the SOLID style
  word's high half — the morph END colour index — joined the style-word
  re-base. Three readers were the §2 trap again: `textfield_glyph_render_cb`
  bounded a raw-symbol read with the COMBINED length,
  `shape_hit_test.c`'s static-text branch read three raw symbols with
  re-based ids, and `textSnapshotCapture` read two. Both arms have
  trace-visible assertions and a fixture each
  (`regression/avm1_parent_child_text`, `..._morph`); the morph one exposed a
  defect the array grep could not see — `ng_record_morph_path` never recorded
  the defining movie's `path_data` table, so a child's morph hit-tested the
  ROOT's outline. CI corpus-clean in BOTH modes, `categories=full`,
  `images=false`: graphics `33864764556` (4369->4369, every bucket +0),
  no-graphics `33868110233` (4370->4370); totals 4494->4496 graded, the +2
  being the two fixtures, `regression` 84/84 -> 86/86. Local sweep of the 348
  tests that bundle a second SWF: 0 regressions, 0 gains. Closeout:
  `SWFRecompDocs/status/child-static-text-and-morphs.md`. (2026-09-04)
- ~~**An AVM2 (Loader-loaded AS3) child's shapes still do not render.**~~
  **DONE 2026-09-04** (multi-SWF slice 9). The reason was bigger than a missing
  base: `ng_buildMovieRenderTables` had exactly two call sites,
  `swf.c::swfStart` and `swf_core.c::runSWF`, both AVM1 entry points, so on the
  AVM2 boot no combined table was ever built. It is now called from
  `runSWF_avm2` at the earliest point that satisfies BOTH AVM1 orderings
  ("before any define tag re-bases an offset" = `resolve_shape_geom` at place
  time; "before the renderer reads app_context's tables" = `avm2_render_init`),
  with `ng_predeclareChildBitmaps()` one line after `avm2_render_init` as
  `swf.c:1719` does. `resolve_shape_geom` adds the defining movie's
  `shape_vert_base` / `morph_end_vert_base`, found by pointer-comparing the
  character's `Avm2MovieTables` against the generated registry; `shape_geom_for`,
  `statictext_for` and `avm2_display_char_is_defined` gained the
  `g_child_movies` fall-through; and the raw-symbol readers in
  `avm2_display.c` / `avm2_cpu_raster.c` went to the combined tables with the
  established NULL fallback. **Two corrections to the site list this entry
  carried.** (a) A FOURTH MAIN-only lookup was load-bearing and unlisted: the
  generic display allocator resolved a class to its character through
  `char_for_class`, whose `g_symbol_map` holds the MAIN movie's SymbolClass
  rows only — so a child's own `new Art()` of its embedded symbol produced an
  EMPTY sprite, and every geometry fix was invisible until that line moved to
  `avm2_display_child_char_for_class` (gated on `g_child_movie_count > 0`).
  (b) AVM2 static text needed **no base**: a child's `Avm2StaticGlyph` rows
  live in the CHILD's `static_glyphs` array and `glyph_start` is numbered from
  0 there, so it is a REGISTRY lookup keyed on the `Avm2StaticTextData*`
  pointer, not an index re-base. Also forced: `color_data`, `gradient_data`,
  `uninv_mat_data` and both morph END tables move to ALL build modes, because
  `avm2_cpu_raster.c` is reachable in NO_GRAPHICS via `BitmapData.draw` and
  would otherwise read the ROOT's arrays at a child's index (`cxform_data` and
  `bitmap_data` stay graphics-only — nothing outside the renderer indexes
  them). Anchored by `regression/avm2_parent_child_render`: `chd:in`
  false->true (`hitTestPoint`, the triangle walk) and `chd:px` ffffff->ff
  (`BitmapData.draw` + `getPixel`, the only trace-visible read of a fill
  COLOUR) in BOTH modes, plus a tolerance-0 image comparison that moves 22964
  outlier channels -> 96. CI corpus-clean in BOTH modes, serial,
  `categories=full`, `images=false`: graphics `33883489039` (4371->4371, every
  bucket +0), no-graphics `33879642365` (4372->4372); totals 4496 -> **4497
  graded**, `regression` 86/86 -> 87/87; local sweep 87/87 in both modes, zero
  upstream drift. **One caveat worth carrying:** the FIRST graphics run
  (`33875683111`) reported `from_shumway/as3-loader/bug1157243/empty` as
  pass -> output_mismatch with EMPTY output. It is not reproducible (200 serial
  + 240 parallel runs of the built binary, 24 `verify_output` runs with the
  slice, 32 on the reverted tree — zero failures) and the slice is provably
  inert on that test at runtime, so it is recorded as an intermittent in the
  closeout's §8, not as a regression. Also: a `-f single_test=empty` dispatch
  FAILS for an unrelated reason — that job resolves a bare name against `avm1/`
  only, and this test lives in `from_shumway/as3-loader/bug1157243/`. Closeout:
  `SWFRecompDocs/status/avm2-child-render-arm.md`; §7 there is what it does NOT
  cover (AVM2 static text is implemented but ungraded — its fixture needs the
  `avm2_static_text/build_statictext.py` splice run against `child.swf`).
  (2026-09-04)
- **A loaded child whose stage HEIGHT differs from the root's renders shifted.**
  The recompiler bakes the y-flip into every vertex as `FRAME_HEIGHT - y`, per
  movie, so a 200-high child loaded into a 400-high parent is 200 px off. Both
  render fixtures use equal stage sizes. Untested and unmeasured; the fix is
  either a per-movie flip applied at combine time or a per-movie stage matrix.
  (2026-09-04)
- **Browser-WASM does not re-base a loaded movie's placement ids.** Several
  `ng_cache_transform` call sites sit behind
  `#if defined(NO_GRAPHICS) || defined(OFFSCREEN_RENDER)`, so the placement
  re-base does not happen in the browser graphics build. Inert rather than wrong
  (an un-re-based id keeps indexing the root rows it indexed before), and moot
  until browser-WASM advances a loaded movie at all — see the MovieClipLoader
  timing entry above. (2026-09-04)
- **`flashbang_upload_bitmap`'s offset bug is fixed but untested.** The SDL3
  backend read `((u32*)context->bitmap_data)[bitmap_pixel]` — the start of the
  array — for every bitmap, so every bitmap after the first uploaded the first
  one's pixels. Fixed 2026-09-03 in passing when the call started taking a
  pointer. Nothing in CI grades flashbang (see "flashbang backend: delete or
  fold into render_webgpu.c" above), so the fix is unverified beyond
  inspection. (2026-09-03)

## Tooling — build scripts

- **Graphics and no-graphics disagree on exactly one test.**
  `from_gnash/misc-swfc.all/gotoFrameFromInterval2` is `output_mismatch` under
  graphics and `ruffle_matched` under no-graphics. Stable, not a flake:
  identical on both sides of five consecutive slice diffs, and named by
  differencing the two published result trees at `91c7c99f1` / `f735855ea`
  (4497-test intersection, exactly one disagreement). CLAUDE.md's parity claim
  was amended 2026-09-04 to say "1-test-short" rather than complete, so the
  instruction file is no longer false; what remains is to diagnose the
  divergence itself — a `gotoFrame`-from-`setInterval` test differing by render
  mode suggests a frame-loop timing difference between `swf.c` and
  `swf_core.c`, not a rendering one. (2026-09-04)
- **`verify_output_keep.py`'s native source list has drifted again.**
  `ruffle-tests/verify_output_keep.py` omits `src/amf_packet.c` and
  `src/actionmodern/avm1_amf.c`, so the KEEP_BUILD_DIR game-bring-up path does
  not link: 15 undefined references from `action.o`
  (`avm1AmfSerializeArg`, `avm1AmfGcMarkRoots`, ...) and `avm2_net.o`
  (`amf_packet_build`, `amf_buf_init`, ...). Both sources exist in the runtime;
  they are simply absent from the list. This is the SECOND instance of exactly
  this drift — the script's own comment at :1718 records the first
  (`avm2_net.c`), with the same root cause: the list is hand-maintained and
  **CI never exercises it**, since KEEP_BUILD_DIR is a game-bring-up path only.
  A fix that only adds the two files leaves the third instance to be found by
  hand; deriving the list, or having CI link this path once, is what ends it.
  Reported by the kittyengine arc from a throwaway worktree build at
  `21e98fcfd`, verified here 2026-09-03. (2026-09-03)
- **`SWFRecomp/build/run-SWFRecomp.sh` hardcodes the LIVE tree's binary.** The
  wrapper is untracked (`build/` is gitignored) and its only line is
  `exec /home/robert/CC/SWFRecomp-CC/SWFRecomp/build/SWFRecomp "$@"`, so any
  worktree-based build that goes through the wrapper silently runs the live
  tree's recompiler instead of its own. Harmless whenever the two binaries
  agree — which is how it has gone unnoticed — and silently wrong the moment a
  worktree carries a recompiler change, i.e. exactly when a worktree is being
  used to isolate one. (2026-09-03)
- **The recompiler treats `--help` as a config-file path** and aborts on a toml
  parse error rather than printing usage. (2026-09-03)

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
