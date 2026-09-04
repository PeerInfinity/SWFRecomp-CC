# avm2_parent_child_static_text

Lock on **a Loader-loaded AS3 child's static text (DefineText/2) resolving
against the CHILD's glyph run**, not the root's — the last unmeasured lookup of
the AVM2 child-render arm.

## Why it exists

`SWFRecompDocs/status/avm2-child-render-arm.md` §2 landed
`avm2_display_static_glyphs_for()`: a registry keyed on the
`Avm2StaticTextData*` pointer itself, which points into exactly one movie's
`statictexts` array and so answers *which* `static_glyphs` array this run's
`glyph_start` indexes. That refuted the expectation the slice inherited — AVM2
static text needs **no index base**, because a child's `Avm2StaticGlyph` rows
live in the child's own array and `glyph_start` is numbered from 0 there.

It shipped **ungraded**: mxmlc cannot emit a placed `DefineText`, so nothing in
the corpus exercised it. This fixture is that grade. (The arc has been bitten
repeatedly by exactly that shape — a fix that looked right and stayed invisible
until something exercised it.)

## The shape

    test.swf   AVM2 (mxmlc, Test.as), 400x400   + spliced DefineFont3/DefineText
                 glyph code 'A', RED,  pen x 200 twips  -> x[10,30] [50,70] px
                 Loader.load("child.swf")                  <- CONTROL (main movie)
    child.swf  AVM2 (mxmlc, Child.as), 400x400  + spliced DefineFont3/DefineText
                 glyph code 'B', BLUE, pen x 4200 twips -> x[210,230] [250,270] px
                                                           <- DISCRIMINATOR

`build_statictext.py` is the parameterised twin of `avm2_static_text`'s: one
DefineFont3 (id 256) holding ONE glyph — a full-EM filled square — plus a
DefineText (id 257) that places it twice at text height 400 twips with an
800-twip advance, then a PlaceObject2 at depth 1 on the root timeline. Glyph
code, colour and pen x come from the command line, which is what makes the two
runs distinguishable. The recompiler shifts the child's ids by its
`char_id_base` (1000), so the child's font is 1256 and its text 1257 — no
collision, and the font scan by bare id still finds each.

Both movies define exactly ONE DefineText of exactly TWO glyphs, so both runs
sit at **`glyph_start` 0 with `glyph_count` 2 of their own array**. That is the
index-0 collision `avm2_parent_child_render` and `avm1_parent_child_render`
use: a read against the ROOT's array lands on real, in-bounds, deterministic
data — the parent's run, reporting the parent's character code and drawing at
the parent's pen x in the parent's colour — rather than on garbage or a crash.

## The gap between the glyphs is this fixture's circle

`avm2_parent_child_render`'s design note says to use a **circle**, not a
rectangle, wherever geometry is graded: a circle's bounding box strictly
contains points outside the shape, which is what tells an exact test from the
bounding-box fallback a geometry-less object falls back to. A two-glyph run with
an 800-twip advance is the static-text form of the same idea — its bounding box
covers the 20 px GAP between the glyphs and the 10 px band below the cell, both
of which must stay background. `chd:px:gap` and `chd:px:below` are those points.

## What each row reads

| row | reader |
|---|---|
| `chd:kids` | the child's placement reaching the display list at all — the arc's "fix REACHABILITY before the INDEX" diagnostic. `1` in every probe below, so this fixture grades the LOOKUP layer, not reachability |
| `ctl:txt` | `StaticText.text` on the parent's own run — the control, unmoved by the slice |
| `chd:txt` | the same on the child's: `avm2_display.c statictext_get_text` -> `avm2_display_static_glyphs_for()` -> `statictext_font_by_id` |
| `ctl:px` / `ctl:px:gap` | `BitmapData.draw` + `getPixel`, i.e. `avm2_cpu_raster_statictext` -> `avm2_text.c avm2_statictext_collect_glyphs` — the only trace-visible read of the glyph run's COLOUR and pen x |
| `chd:px`, `chd:px:2`, `chd:px:gap`, `chd:px:below` | the same on the child's run |

Both readers are ordinary ActionScript and the CPU raster is compiled
unconditionally, so **every row runs in NO_GRAPHICS as well as graphics** — no
image comparison is needed to grade this one.

## What moves

Three separate child arms of the slice feed these rows. Each was reverted on
its own (edit, rebuild, re-run; the tree restored byte-identical after each):

| reverted arm | `chd:txt` | `chd:px` / `chd:px:2` | `chd:kids` |
|---|---|---|---|
| `avm2_display_static_glyphs_for()` -> raw `avm2_generated_static_glyphs` | `BB` -> **`AA`** | `ff` -> **`ffffff`** | `1` |
| `statictext_font_by_id` child fall-through | `BB` -> **`null`** | `ff` (unmoved) | `1` |
| `statictext_for` child fall-through | `BB` -> **`null`** | `ff` -> **`ffffff`** | `1` |

Every control row (`ctl:*`) is unmoved by all three, which is what makes the
difference attributable to childness.

Two things worth reading off that table:

- **The registry lookup is graded twice over, by two independent readers.**
  `chd:txt` reporting `AA` is the sharpest row in the fixture: the child's
  `StaticText` reports the PARENT's character code, which is only possible if
  its run was read out of the wrong array.
- **There are two font lookups, not one.** `statictext_font_by_id`
  (`avm2_display.c`) serves `StaticText.text`; `avm2_text.c`'s own `font_by_id`
  serves the raster. Reverting the first moves `chd:txt` alone — so the two
  readers are genuinely independent and one cannot mask the other.

## Regenerate

    ./build_swf.sh
    # golden trace (the exporter's local navigator resolves relative URLs
    # against http://armorgames.com/, so child.swf must sit in an
    # armorgames.com/ subdirectory of RUFFLE_LOCAL_FETCH_DIR)
    mkdir -p /tmp/fetch/armorgames.com && cp child.swf /tmp/fetch/armorgames.com/
    RUFFLE_LOCAL_FETCH_DIR=/tmp/fetch ~/CC/ruffle/target/release/exporter \
        test.swf /tmp/out.png -s -f 6 --trace-log output.txt
