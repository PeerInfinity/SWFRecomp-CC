# Grading the AVM2 child static-text lookup — the render arc closes at 6/6

**Date:** 2026-09-04 · **Arc:** Multi-SWF (loaded children), slice 10
**Baseline:** `aecbd472f` · **Brief:** `SWFRecompDocs/prompts/avm2-child-static-text-fixture-prompt.md`
**Predecessor:** `SWFRecompDocs/status/avm2-child-render-arm.md` (its §7 row 5 is this slice's whole scope)

Slice 9 shipped `avm2_display_static_glyphs_for()` — the registry that answers
which movie's `static_glyphs` array a `Avm2StaticTextData.glyph_start` indexes —
and could not grade it, because mxmlc cannot emit a placed `DefineText`. It was
the one part of the AVM2 child-render arc with no test behind it.

It is graded now, by `regression/avm2_parent_child_static_text`, and **it was
correct as shipped**. This slice found no defect in slice 9's code. What it did
find is that the lookup is load-bearing for **three** separate arms, not one,
and that two independent readers reach it — recorded in §2 and §3.

**No runtime or recompiler source changed.** The slice is one new fixture and
its documentation, so it cannot move the corpus except by adding a test.

## 1. The fixture

The recipe in the predecessor's §7 survived contact and needed only one
addition. It said: run `avm2_static_text/build_statictext.py` against
`child.swf` with a different glyph code from the parent's, plus a matching
DefineFont3 + DefineText in the parent as the control. That is exactly what
`build_swf.sh` does, against a parameterised copy of that splicer
(`--code` / `--color` / `--penx`). The addition is the **colour and pen x**: a
differing glyph code alone grades `StaticText.text`, and the second reader —
`avm2_cpu_raster_statictext`, via `BitmapData.draw` + `getPixel` — needs a
differing *placement* and *colour* to say anything at all.

    test.swf   AVM2, 400x400   glyph 'A', RED,  pen x 200 twips  -> x[10,30] [50,70] px
                               Loader.load("child.swf")
    child.swf  AVM2, 400x400   glyph 'B', BLUE, pen x 4200 twips -> x[210,230] [250,270] px

Both movies define exactly ONE DefineText of exactly TWO glyphs, so both runs
sit at `glyph_start` 0, `glyph_count` 2, of their own array — the index-0
collision the two predecessor render fixtures use, which makes a read against
the ROOT's array land on real, in-bounds, deterministic data (the parent's run)
rather than on garbage. The emitted tables confirm it, and confirm the child's
ids are shifted by `char_id_base`:

```
avm2_generated_static_glyphs[]       = { 256, 0,  200, 400, …, 0xff0000 },
                                       { 256, 0, 1000, 400, …, 0xff0000 }
child_avm2_generated_static_glyphs[] = { 1256, 0, 4200, 400, …, 0xff },
                                       { 1256, 0, 5000, 400, …, 0xff }
```

### The predecessor's "use a circle" note, applied to text

`avm2_parent_child_render` insisted on a circle rather than a rectangle wherever
geometry is graded: a circle's bounding box strictly contains points outside the
shape, which is what separates an exact test from the bounding-box fallback. The
static-text form of that idea is the **advance between the two glyphs**: a
two-glyph run's bounding box covers the 20 px gap between them and the 10 px
band below the cell, and both must stay background. `chd:px:gap` and
`chd:px:below` are those points, and they are what proves the child's run was
drawn at its own pen positions rather than as a filled box.

## 2. What moves, measured per arm

Three child arms of slice 9 feed these rows. Each was reverted on its own —
edit, rebuild, re-run, tree restored byte-identical after each — rather than
reverting the slice wholesale, because a wholesale revert cannot say which arm
a row belongs to.

| reverted arm | `chd:txt` | `chd:px` / `chd:px:2` | `chd:kids` |
|---|---|---|---|
| `avm2_display_static_glyphs_for()` → raw `avm2_generated_static_glyphs` | `BB` → **`AA`** | `ff` → **`ffffff`** | `1` |
| `statictext_font_by_id` child fall-through | `BB` → **`null`** | `ff` (unmoved) | `1` |
| `statictext_for` child fall-through | `BB` → **`null`** | `ff` → **`ffffff`** | `1` |

Every control row (`ctl:txt`, `ctl:px`, `ctl:px:gap`) is unmoved by all three,
which is what makes the difference attributable to childness. Both graded rows
run in **both build modes** — `StaticText.text` and `BitmapData.draw` are
ordinary ActionScript and the CPU raster is compiled unconditionally — so no
image comparison was needed and none was added.

`chd:txt` reporting `AA` is the sharpest row here: the child's own `StaticText`
reports the PARENT's character code, which is only possible if its glyph run was
read out of the wrong array. That is the registry lookup, stated as a trace line.

## 3. Two findings the predecessor's §5 table did not carry

**(a) There are two font lookups on this path, not one.**
`statictext_font_by_id` (`avm2_display.c`) serves `StaticText.text`;
`avm2_text.c` has its own `font_by_id` serving the raster. Reverting the first
moves `chd:txt` alone and leaves `chd:px` at `ff` — so the two readers are
genuinely independent and neither can mask the other. The predecessor's §5 table
lists the two *glyph-array* readers as a pair and treats the font lookup as one
row ("`statictext_font_by_id` got the child fall-through its EditText twin
already had"); it is two, and only one of them was new in slice 9.

**(b) Reachability was already covered here, unlike the shape path.**
`chd:kids` is `1` under all three reverts: the child's `PlaceObject2` reaches
the display list and mints a `StaticText` object whatever the character lookup
says. That is the opposite of what slice 9 met on the shape path, where a
child's `new Art()` produced an empty sprite until `char_for_class` moved — and
it is because a timeline placement resolves through `timeline_for_char` on the
loaded root (`avm2_display.c:5911`), which was already child-aware, rather than
through the SymbolClass map. So for static text the arc's "fix REACHABILITY
before the INDEX" rule is satisfied for free, and all three probes land squarely
on the lookup layer. `chd:kids` is kept in the fixture as the diagnostic that
says so.

## 4. Checks

- `regression/avm2_parent_child_static_text` passes in **both** modes locally.
- `import_assets/avm1_imports_avm1`, the standing pixel canary for per-movie
  geometry, still passes (graphics).
- Generated C swept with `gcc -fsyntax-only -Werror=return-type -Wall` over
  every emitted TU of this test (`abc*_*.c`, `child_abc*_*.c`, `movie_child.c`,
  `movie_registry.c`, `root_swf_bytes.c`, `data_registry.c`) — `verify_output.py`
  compiles with `-w`, so this is the only place such a warning would show. The
  only output is pre-existing `-Wmissing-braces` on the emitter's flat
  initialisers for nested arrays, identical in the parent's and the child's TUs
  and present for every AVM2 test; nothing new, nothing `-Wreturn-type` or
  `-Wunused-*`.

## 5. CI

See §6 below.

## 6. What is left of the arc

The predecessor's §7 closes at **6/6** — row 5 was the last "implemented but not
graded" line, and it is graded. What remains of the multi-SWF arc is a
prioritisation call, not a queue: display-list Route 1, the MCL one-tick gap,
the child-stage-height y-flip, browser-WASM placement re-base, flashbang, and
the dictionary bound divergence. All are on `SWFRecompDocs/BACKLOG.md`.
