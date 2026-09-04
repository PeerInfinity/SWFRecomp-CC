# avm2_parent_child_render

Lock on **an AS3 (AVM2) root building the combined per-movie render tables at
all**, and on a Loader-loaded AS3 child's shapes reaching every reader of that
geometry: the exact hit test, the CPU raster, and the GPU render walk.

## Why it exists

`ng_buildMovieRenderTables()` concatenates every linked movie's geometry and
style arrays into one set and fills in each `MovieEntry`'s bases. Until
`SWFRecompDocs/status/avm2-child-render-arm.md` its only two call sites were
`swf.c::swfStart` and `swf_core.c::runSWF` — **both AVM1 entry points**. An AS3
root boots through `avm2_main.c::runSWF_avm2`, which called neither, so on the
AVM2 path no combined table was ever built: `ng_movieRenderTablesActive()` was
0 and every base on every `MovieEntry` stayed 0.

Three more MAIN-only lookups sat behind that: `shape_geom_for` and
`statictext_for` scanned only `avm2_generated_*`, and the generic display
allocator resolved a class to its character through `char_for_class`, whose
`g_symbol_map` is built once at stage build from the MAIN movie's SymbolClass
rows. The last one is why the child's own `new Art()` produced an EMPTY sprite
here — its embedded symbol resolved to no character, so no timeline, so no
children at all.

## The shape

    test.swf   AVM2 (mxmlc, Test.as), 400x400        [Embed] parent_art.svg
                 red circle  centre (100,200) r=60   <- CONTROL (main movie)
                 Loader.load("child.swf")
    child.swf  AVM2 (mxmlc, Child.as), 400x400       [Embed] child_art.svg
                 blue circle centre (300,200) r=60   <- DISCRIMINATOR

Each movie defines exactly ONE shape character, so both sit at vertex offset 0
and colour index 0 of their own arrays — the index-0 collision
`avm1_parent_child_render` uses, which makes a read against the ROOT's arrays
land on real, in-bounds, deterministic data (the parent's red circle) instead
of on garbage. The two circles occupy DISJOINT x ranges, so a wrong table gives
a wrong picture rather than a crash.

A **circle** rather than a rectangle is deliberate: its bounding box strictly
contains points that are outside the shape, which is what separates an exact
(triangle-walking) hit test from the bounding-box fallback a display object
with no resolved geometry falls back to.

## What each row reads

| row | reader |
|---|---|
| `ctl:in` / `ctl:cor` | `hitTestPoint(x, y, true)` on the parent's own circle — the control, unmoved by this slice |
| `chd:in` / `chd:cor` | the same on the child's, `avm2_display.c shape_contains_local` walking `shape_data[ext->shape_vert_offset + …]` |
| `ctl:px` / `ctl:px:cor` | `BitmapData.draw` + `getPixel`, i.e. `avm2_cpu_raster_shape` reading `shape_data` **and `color_data`** — the only trace-visible read of a fill COLOUR |
| `chd:px` / `chd:px:cor` | the same on the child's circle |
| `output.expected.png` | the GPU render walk (`renderer_draw_shape` over the combined vertex buffer), graphics mode only |

Both trace readers run in **both build modes**: `hitTestPoint` and
`BitmapData.draw` are ordinary ActionScript, and the CPU raster is compiled
unconditionally.

## What moves

Measured by reverting the whole slice as a patch (`git diff > p.patch;
git apply -R p.patch` — `git stash` is shared across this repo's worktrees) and
re-running both modes:

| row | master | fixed |
|---|---|---|
| `chd:in` | `false` | **`true`** |
| `chd:px` | `ffffff` | **`ff`** |
| image | 22964 outlier channels | 96 |

`chd:cor` is `false` on master too, and for the "right answer, wrong reason"
this arc keeps meeting: on master the child's art sprite instantiates with no
children at all, so its bounds are empty and BOTH probes miss. `chd:in` is what
discriminates; `chd:cor` is what proves the fixed answer is an exact shape test
and not the bounding box.

## Image tolerance

`max_outliers = 400` at `tolerance = 0`. The circles are curve-flattened at
recompile time, so a few dozen edge channels differ from Ruffle's own
tessellation + AA (96 on the reference run). That is two orders of magnitude
below what this comparison exists to catch: a missing child circle costs ~23000.

## Regenerate

    ./build_swf.sh
    # golden trace + pixels (the exporter's local navigator resolves relative
    # URLs against http://armorgames.com/, so child.swf must sit in an
    # armorgames.com/ subdirectory of RUFFLE_LOCAL_FETCH_DIR)
    mkdir -p /tmp/fetch/armorgames.com && cp child.swf /tmp/fetch/armorgames.com/
    RUFFLE_LOCAL_FETCH_DIR=/tmp/fetch ~/CC/ruffle/target/release/exporter \
        test.swf out.png -s -f 6 --trace-log output.txt
    RUFFLE_LOCAL_FETCH_DIR=/tmp/fetch ~/CC/ruffle/target/release/exporter \
        test.swf output.expected.png -s -f 1 --skipframes 5
