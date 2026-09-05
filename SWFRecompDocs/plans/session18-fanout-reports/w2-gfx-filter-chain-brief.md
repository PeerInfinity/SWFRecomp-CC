# w2-gfx-filter-chain — wave 2: render the WHOLE PlaceObject3 filter list, not just the first filter (0 flips priced; −99.8% band on `blur_size_grows`, engine-wide bug)

Read `BRIEFS_COMMON.md` (incl. wave-2 + graphics canary rules) and `SIBLING_FILE_MAP.md`, then
the diagnosis of record: `w1-gfx-filters-report.md` §7 (the multi-filter chain, with the SWF
table of which corpus tests carry multi-filter lists), §3.3 (filter-implied pixel snap — context,
NOT in scope), §8 leads (`acid-filter-2` `[Glow, Blur]`, `acid-filter` `[Blur, Blur]`). Isolated
worktree; no commits. This patch is recompiler + runtime → rebuild `SWFRecomp/build` in your
worktree (cmake) and pass `--recompile` on every copied test dir.

## Scope
The recompiler keeps only the first filter of a PlaceObject3 `SurfaceFilterList`
(`SWFRecomp/src/swf.cpp`: `if (parsed_filter_type == 0)` ×7 and a single `tagSetFilter`
emission); the runtime stores/applies one filter per display entry on the AVM1 tag route. Make
the list a list: emit every filter in order, store the chain on the entry, and apply them in
order on the tag-filter render route (the AVM2 `.filters` path in `avm2_filters.c` already
applies an array — reuse its chain loop rather than writing a second one). Filter IDs in the
SWF are `0=DropShadow 1=Blur 2=Glow 3=Bevel 4=GradientGlow 5=Convolution 6=ColorMatrix
7=GradientBevel` (NOT AS3 class order — the report flags this trap).
Targets (band moves, not flips): `visual/filters/blur_size_grows` 86708 → ~50,
`from_shumway/acid/acid-filter-2` 16764 → ?, `from_shumway/acid/acid-filter` 482 → ?. Report
every multi-filter test the report's §7 table lists, before/after.

## Verification
`--mode=graphics --images --image-out-dir` on the targets + every test in the §7 table.
Render canary: `render_canary.py` capture/compare (`--timeout 5400`) — md5 identity except rows
that carry a multi-filter list (list them with before/after outliers). Trace canaries: `avm1/filter*`,
`avm1/*_filter*`, `avm2/filters*`/`avm2/*filter*` passing tests (`--diff`, byte-identical — the
`.filters` getter must still report the full list where it already did), plus the `regression`
suite's filter fixtures. The recompiler changed → also run `ruffle-tests/recompiler_ab_sweep.sh`
if it exists (read its header) or a 20-test recompile A/B (byte-identical generated C for tests
WITHOUT filter lists). `-P 2`, compile timeout 2400.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-gfx-filter-chain.patch` +
`w2-gfx-filter-chain-report.md` (NEW files first; per-comparison ledger; canary md5 ledger;
recompiler A/B result; refutations; unclaimed leads). Copy to the main tree if allowed.

## SCOPE EXTENSION (from `w1-gfx-fill-report.md` §1 A3 and §2 B1 — read them)
4. **A3 `from_shumway/acid/acid-filter-2` 16 764 → ~0 (+1 flip, highest confidence):** the
   object's colour transform must apply to the FILTER OUTPUT, not the source (`tag.c::render_filtered_object`
   and `avm2_display.c::avm2_render_filtered`). The SWF's glow is BLACK with a PlaceObject3 cxform
   `add=[+255,0,0,0]`; G/B falloff already byte-identical. Must run `from_shumway/acid/acid-filter`
   and every `visual/filters/*` as canaries (interacts with the chain change — do the chain
   first, then the cxform, and ledger each separately).
5. **B1 `visual/cache_as_bitmap/avm2_button` 4 432 → ~278 (band):** the recompiler emits
   `tagSetOpaqueBackground` at ONE site (`swf.cpp:4805`, root placements); the DefineSprite arm
   (`:6234`) has the `cacheAsBitmap` twin but not this one — ~8 LOC. Canary: `visual/opaque_background`
   (passes today) + any test with `opaqueBackground` in its source.
