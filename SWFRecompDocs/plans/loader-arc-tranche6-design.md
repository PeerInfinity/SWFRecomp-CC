# Loader arc tranche 6 — AVM2 child-SWF execution: design

**Created**: 2026-07-27 (Fable planning pass; two very-thorough code scouts over
harness, recompiler, and runtime). **Parent plan**: `loader-arc.md` §2 gap 1,
§3 bucket F, §4 tranche 6. **Status**: DESIGN — nothing implemented.

Targets (unblocked bucket F): `loader_events`, `loader_loadbytes_events`,
`loader_reuse`, `loader_loaderurl`, `loader_error_in_root_ctor`,
`loader_loadbytes_url`, plus up to 9 `from_shumway/as3-loader/*` riders.
Staged as **6a / 6b / 6c** below; 6a is the recommended first session.

## 0. Two findings that reshape the estimate

**Scope reducer — child rendering is out of scope.** These are trace-graded
tests; image comparisons don't gate pass/fail. The AVM2 CPU raster reads the
*global* `shape_data`/`morph_end_shape_data` arrays by offset
(`avm2_cpu_raster.c:35-41` via `Avm2ShapeGeom.vert_offset`), which a child's
prefixed copies can't feed — and that's fine. Tranche 6 makes child *code and
timeline* run; child *geometry rendering* is explicitly deferred (file a
follow-up line in the tranche table when closing this out).

**Trap — `loader_error_in_root_ctor` intersects the reverted uncaught-error
tracing** (`d1c307c51`). Its expected output IS an uncaught-error printout
(`Error: …\n\tat Child()`). Don't resurrect the corpus-wide revert for it;
the child-root-constructor call site (`display_run_constructor`,
`avm2_display.c:1009`, already under a catch-all try frame) can print locally.
That's why it's staged last (6c) — it needs the error path, not the tracing
feature.

## 1. Current state (scout-verified, with anchors)

What already works:

- The harness recompiles every sibling `.swf` (`verify_output.py:898-942`)
  and registers a `MovieEntry` (`swf.h:385-397`) reachable via
  `findMovieEntry`. `loader_resolve_url` (`avm2_display.c:4502`) already
  recognizes a child SWF — but resolves to *size only*: no bytes, no entry
  point (`:4516-4523`).
- The whole Loader event/timing machine from tranches 1–5 is in place:
  `loader_deliver` (`:4307`) runs progress/loaded/url/app_domain; the
  `:4418` gate already defers a SWF's init/complete to the next
  `avm2_loader_drain` (after the child's first exitFrame — the §6 timing
  model). **No timing changes needed.**
- The reset half of `loader_reuse` is DONE: `loader_drop_content` (`:4107`)
  → `loaderinfo_reset_stream` (`:4085`), called from load/loadBytes/unload.
  Only the construction half is missing.
- The AGI.swf special case (`:4548-4573`) already fakes exactly the
  "SWF content" shape (class as content, stream marked loaded) — it's the
  degenerate form of what 6a builds, and must keep working.

The three build-side root causes:

1. `recompile_child_swf` copies back only `RecompiledScripts` +
   `RecompiledTags` — **`RecompiledABC/` is produced and thrown away with
   the tmpdir** (`verify_output.py:934`).
2. Even if copied, the ABC output **collides**: every AVM2 movie emits the
   same file names (`abc_registry.c`, `abc_timeline.c`, `abc0_tables.c`, …)
   and the same exported symbols — `abc<i>_data` / `abc<i>_methods`
   (`abc_emit.cpp:4376-4378`) plus the ~28 `avm2_generated_*` externs
   (`avm2_abc.h:186-513`, emitted `abc_emit.cpp:4384-4413` and
   `abc_timeline.cpp:1339-1813`). Internals are all `static` — the exported
   surface is small and enumerable.
3. Child SWF **bytes** aren't bundled (`find_data_files` skips `.swf`,
   `verify_output.py:1491`); `loader_events` needs `bytes.length == 1490`
   for an 893-byte child — the **decompressed** size.

The runtime has **no movie dimension**: one `avm2_generated_*` table set,
consumed at ~97 sites; `g_symbol_map` keyed by bare char_id
(`avm2_display.c:2882-2901`); one boot path (`avm2_main.c:235-340`) reading
the globals directly; `avm2_abc_load` is static in `avm2_main.c:140`. The
AVM1 side already solved the analogous problem with Python-regex symbol
prefixing + `movie_id * 1000` char-id offsets (`verify_output.py:1036-1443`)
and per-movie export/char registries (`ng_shared.c:849-985`,
`tag.c:190-193`).

## 2. Architecture decision

### 2a. Prefixing: in the EMITTER, not Python regex

Add two optional keys to the recompiler config (`config.cpp:18-27` currently
parses exactly three): `symbol_prefix` (string, default empty) and
`char_id_base` (int, default 0). Thread them into `AbcEmitter`
(`abc_emit.hpp:38`, literals at `abc_emit.cpp:3990/4204/4376-4413`) and
`emitAvm2Timeline` (`abc_timeline.hpp:53-55`):

- Every exported symbol gains the prefix: `<p>abc0_data`,
  `<p>avm2_generated_timelines`, … Emitted **file names** gain it too
  (`<p>abc_registry.c`, …) so the flat copy into `build_dir` can't clobber.
- Every char id in the emitted tables (chars, timelines, symbol_classes,
  buttons, edittexts, …) is offset by `char_id_base` at emission — the
  child's tables are then globally unique by construction, same trick as
  AVM1's `movie_id * 1000`. The SymbolClass root binding keeps a
  distinguishable root marker: emit the root row's char_id as
  `char_id_base + 0` and record `char_id_base` in the aggregate struct
  (below) so the runtime can find "this movie's root class".
- **Main-movie emission is byte-identical when both keys are absent.** Do
  not touch the default path — that's the whole corpus.

Why emitter-side and not the AVM1-style Python rewriter: the exported
surface is ~30 known names + file names (vs AVM1's open-ended rename map),
the internals are already `static`, and regex over generated C has been the
fragile part of the AVM1 pipeline. Threading two strings through two
emitters is smaller and durable.

### 2b. Aggregation: `Avm2MovieTables` + one new `MovieEntry` field

New struct in `avm2_abc.h` bundling everything the runtime needs per movie:

```c
typedef struct Avm2MovieTables {
    const Avm2AbcFileData* const* abc_files;  uint32_t abc_file_count;
    const Avm2SymbolClass* symbol_classes;    uint32_t symbol_class_count;
    const Avm2Timeline* timelines;            uint32_t timeline_count;
    const Avm2CharInfo* chars;                uint32_t char_count;
    /* + the remaining avm2_generated_* families the child needs;
       start with what the 3 stage-6a tests exercise and grow */
    uint32_t char_id_base;
    uint16_t swf_version;
    const uint8_t* swf_bytes; uint32_t swf_bytes_len;  /* DECOMPRESSED */
} Avm2MovieTables;
```

- The child emitter (prefix mode) additionally emits
  `const Avm2MovieTables <p>avm2_movie_tables = {…}`.
- `MovieEntry` gains one field: `const void* avm2_tables;` (NULL for AVM1
  movies and images — zero-init keeps every existing initializer valid).
  `findMovieEntry` stays the single registry.
- The MAIN movie keeps booting from the legacy globals unchanged
  (`avm2_main.c` untouched except exporting the loader, §2c). Do NOT
  migrate the ~97 global-reading sites; only the *lookup scans* grow a
  second source (§2c).

### 2c. Runtime: register-on-first-load, extend the four scans

- Export the ABC loader: `avm2_abc_load` (`avm2_main.c:140`) becomes public
  as `avm2_abc_register_movie(ctx, const Avm2MovieTables*)` — per abc file:
  load (`ctx->files[]` grows), `avm2_domain_add` each script trait
  (`avm2_main.c:190-197` pattern), then eager-init each file's last script
  under catch-all (`:293-308` pattern). Lazy inits for the rest already
  work via `avm2_domain_find` (`avm2_globals.c:161`).
  **Idempotent per movie** (loader_reuse loads the same child twice; keyed
  by the tables pointer). Single global domain is fine for 6a/6b —
  first-match-wins means the parent wins on a name collision; true
  isolation is tranche 8, and none of the 6 targets collide.
- Extend the four char lookup scans — `timeline_for_char`
  (`avm2_display.c:260`), `char_info` (`:272`), `class_for_char` (`:1241`),
  `nondisplay_class_for_char` (`:1281`) — to also scan a small runtime list
  of registered child `Avm2MovieTables`. Char ids are globally unique
  (char_id_base), so no key change. Append the child's non-root
  SymbolClass rows to `g_symbol_map` at registration (`:2884-2901`
  pattern).

### 2d. Child boot inside `loader_deliver` (the SWF arm)

Insert next to the image arm (`:4359-4374`), following the boot sequence at
`avm2_main.c` / `avm2_display_build_stage:2942-2956` but scoped to the
Loader:

1. `avm2_abc_register_movie` (idempotent) from
   `MovieEntry->avm2_tables`.
2. Root class: the tables' SymbolClass row at `char_id_base + 0`, resolved
   via `class_for_dotted_name` (`:1217`), with the same
   `class_is_a(bound, sprite_class)` / `#2023` gate as `:2929-2939`;
   fallback `movieclip_class`.
3. `display_alloc_instance` under `g_timeline_instantiation = 1`; set
   `is_root = 1`, `char_id = char_id_base`, `timeline =
   timeline_for_char(char_id_base)`, `instantiated_by_timeline = 1`
   (mirror `:2942-2953`). **Do not run the constructor inline blindly** —
  the ctor must observe `stage == null` / `parent == null`
  (`LoadableMainTimeline.as` traces both). Derive the construct-vs-attach
  order from `loader_events`' `output.txt` interleaving (added /
  addedToStage vs ctor traces) and lean on the existing
  `construct_frame_obj` (`:1670`) / `on_construction_complete` (`:1776`)
  ordering rather than inventing a new path.
4. Attach: `lx->content = child_root; lext->content = child_root;
   insert_at_index(ctx, lx->loader, child_root, 0)` (`:895` — fires
   `added` + recursive `addedToStage`).
5. `loaderInfo` identity: `loader.contentLoaderInfo ===
   loader.content.loaderInfo`. Add a `loader_info` back-pointer for roots
   (field on `Avm2DisplayObjectExt`, `avm2_globals.h:326-472`, or a
   root→LoaderInfo side map) and make `do_get_loader_info` (`:3656`) walk
   `avm2_root_of` (`:788`) and consult it before falling back to
   `g_root_loader_info`.
6. Timeline: nothing extra — once attached (or orphaned via `orphan_add`,
   `:104/:131`, for the un-addChild'd Loader in `loader_events`' second
   half), the stage/orphan walks reach it; `addFrameScript` from the
   child's ctor populates `frame_scripts` as usual.
7. Timing: leave the `:4418` gate alone — the active list already defers
   init/complete correctly for SWFs.
8. GC: extend the loader block in `avm2_gc_mark_roots_display`
   (`:8464-8475`) for any new references (child root is reachable via
   `lx->content` already; verify).

### 2e. Harness changes (`verify_output.py`)

1. `recompile_child_swf`: write `symbol_prefix`/`char_id_base` into the
   temp config; copy back `RecompiledABC` (the prefixed file names land in
   `build_dir` alongside the parent's — the `glob("*.c")` compile set
   picks them up automatically, `:2078`).
2. Bundle **decompressed** child bytes: decompress CWS/ZWS in Python
   (zlib/lzma, rewrite header to FWS + real length) and emit the array +
   length into the child's movie file; wire into `Avm2MovieTables.swf_bytes`
   and the `MovieEntry`. (`li_get_bytes:3820` then serves the third state;
   `loader_resolve_url:4516-4523` gains `out->data = tables->swf_bytes`.)
3. `generate_child_movie_file`: set `.avm2_tables = &<p>avm2_movie_tables`
   when the child's `RecompiledABC` exists (extern it), else NULL.
4. `get_self_load` (`:1655-1673`): also scan `RecompiledABC/*.c` for the
   `"test.swf"` literal (AS3 self-loaders are invisible today) — needed by
   6b's `loader_loadbytes_url`, harmless in 6a.
5. Out of scope, note in code: the wasm path (`compile_wasm:2230` copies no
   `RecompiledABC` and has no AVM2 branch) and AVM1-parent/AVM2-child
   (`is_avm2` is test-dir-only, `:1722` — that's the dual-VM arc).

### 2f. Small runtime fixes riding along (all needed by `loader_events`)

- `loader_basename` (`:4036`): strip `?query` before registry lookup
  (`./loadable.swf?paramOne=…` currently misses `findMovieEntry`).
- `li_get_parameters` (`:3843`): parse the load URL's query string into
  the parameters object (currently always empty).
- `HTTPStatusEvent` between init-order events: `loader_deliver` never
  dispatches one; `avm2_http_status_event_new` exists (`avm2_globals.h:524`,
  URLLoader uses it at `:4739`). Match the expected position in
  `output.txt`.
- 6b only — `li_get_loader_url` (`:3780`) hardcodes the root SWF's URL;
  `loader_loaderurl`'s 3-deep chain needs "the URL of the movie that
  *issued* the load". Same for `loader_absolute_url` (`:4015`) resolving
  against `root_swf_url()` — a child issuing a load must resolve against
  its own URL. Route both through the issuing DisplayObject's root
  LoaderInfo.

## 3. Stages and predictions

| Stage | Scope | Tests | Predicted |
|---|---|---|---|
| **6a** | §2a-2f core: emitter prefix, tables struct, register+boot, identity, bytes, parameters, basename, HTTPStatus | `loader_events`, `loader_loadbytes_events`, `loader_reuse` | **+3 avm2**, plus riders: `from_shumway/as3-loader/*` (9 scoped; `loaded-content-properties` at 35/36 is the closest) and watch `delayed_symbolclass` / `large_preload_*` (same "Loader never fires" hole, per §5 line movement) |
| **6b** | per-issuer URL base (`loaderURL`, relative resolution), AS3 self-load, `/[[DYNAMIC]]/<id>` URL synthesis, per-load `new ApplicationDomain()` accepted as value-only | `loader_loaderurl`, `loader_loadbytes_url` | **+2** (loadbytes_url is the risky one — 4-deep self-load re-registration; its idempotency behavior must be derived from the test, may slip to tranche 8) |
| **6c** | uncaught-error print at the child-root-ctor call site (LOCAL, not the reverted corpus-wide tracing); abort init/complete on ctor throw (`errored = 1` drops it from the active list already, `:4446`) | `loader_error_in_root_ctor` | **+1** |

Regression surfaces: the 13 loader tests fixed in tranches 1–5 (esp. the
AGI.swf path — consider migrating it onto the real SWF arm only if free);
`instantiate_root_character` (has its own `loadable.swf` — its child now
gets ABC tables linked where before it got a shell; verify it); every
`avm2` test rebuilds with a recompiler change, so the emitter's
"byte-identical without the keys" property is THE safety invariant —
spot-check by diffing a regenerated `RecompiledABC/` before/after the C++
change on one existing test.

## 4. Definition of done (per stage)

Local: the stage's target tests pass `--diff`; regression spot-checks
clean (incl. one AVM1 child-movie test, e.g. any avm1 loadMovie test, to
confirm `MovieEntry` layout change is inert). CI graphics `categories=full`;
`corpus_status_diff` vs the pre-stage sha; histogram flat (zero
segfault/timeout/compile_fail stays zero — a recompiler change makes
`compile_fail` the bucket to watch). Postmortem into `loader-arc.md`
(§8+), tranche table updated, feature-priority-map DONE/NEXT updated.
