# Graphics Test Generation Plan

**Created:** February 6, 2026

**Status:** Ready to implement

---

## Purpose

Replace the pre-generated `test.swf` files in the 14 graphics tests with `create_test_swf.py`
scripts that produce the same SWF files from code, matching the pattern already used by the
non-graphics opcode tests.  This unblocks writing new graphics tests without external Flash
authoring tools, and makes the graphics test SWFs reviewable in source control.

---

## Current State

| Non-graphics tests (117) | Graphics tests (14) |
|--------------------------|---------------------|
| Each has `create_test_swf.py` | No generation script |
| `test.swf` is gitignored, generated on demand | `test.swf` is gitignored, only exists as deployed copies in `docs/examples/graphics/` |
| Has `validate.py` for automated verification | No `validate.py`; verification is visual only |
| Build system auto-runs `create_test_swf.py` when `test.swf` is missing (`build_test.sh:74-99`) | Same code path exists but no script to run |

The graphics tests cover these SWF tag types:

- **SetBackgroundColor** (tag 9) — all tests
- **DefineShape** (tag 2) — 12 tests
- **DefineShape2** (tag 22) — 2 tests (`new_styles`, `wild_shadow`)
- **PlaceObject2** (tag 26) — all tests
- **DefineBits** (tag 6) — 1 test (`mess`, bitmap fill with JPEG)
- **DoAction** (tag 12) — 3 tests have a trace action (`awful_shape_swf_4`, `ssquare`, `sssquare`)

Graphics features used across the 14 tests:

| Feature | Tests using it |
|---------|---------------|
| Solid fills | `two_squares`, `three_boxes`, `three_boxes_hole`, `three_boxes_holes`, `ssquare`, `sssquare`, `awful_shape_swf_4`, `new_styles`, `wild_shadow` |
| Linear gradients | `awful_gradient` |
| Radial gradients | `awful_radial_gradient` |
| Line styles | `three_boxes`, `three_boxes_hole`, `three_boxes_holes`, `thiccie`, `awful_gradient`, `awful_radial_gradient`, `new_styles` |
| Curved edges (CurveTo) | `coicle`, `wild_shadow` |
| Bitmap fills (JPEG) | `mess` |
| StateNewStyles (DefineShape2) | `new_styles`, `wild_shadow` |
| Multiple DefineShape tags | `three_boxes_holes` |

---

## Tool Choice: swfmill

**swfmill** (`apt install swfmill`) converts between SWF binary and an XML format that maps
1:1 to the SWF tag structure.  It is the right tool because:

1. **Already packaged** — `apt install swfmill`, no compilation needed.

2. **XML maps directly to SWF tags** — The XML element names (`DefineShape`, `PlaceObject2`,
   `LineTo`, `CurveTo`, `Solid`, `LinearGradient`, etc.) correspond exactly to what
   `SWFRecomp/src/swf.cpp` parses.  No translation layer needed.

3. **Round-trip verified** — Running `swf2xml` on all 14 existing test SWFs produces clean,
   readable XML.  Running `xml2swf` on that XML produces functionally equivalent SWFs (the
   only difference is ±1 byte in the file-length field due to bit-packing alignment, which
   does not affect parsing).

4. **Covers all needed features** — Solid fills, gradients, bitmap fills, line styles,
   straight edges, curved edges, DefineShape/DefineShape2, PlaceObject2 with transforms,
   DoAction tags.

5. **Scriptable from Python** — Each `create_test_swf.py` generates XML (using f-strings or
   `xml.etree.ElementTree`), writes it to a temp file, calls
   `subprocess.run(["swfmill", "xml2swf", ...])`, and cleans up.

### Alternative tools considered

| Tool | Why not chosen |
|------|---------------|
| Hand-written bit-packing (Python `struct`) | SWF shape records use variable-length bit fields; error-prone, large implementation effort |
| SWFTools (swfc) | Not in apt repos for modern Ubuntu; must build from source with patches |
| libming | Python 3 bindings are broken (SWIG uses Python 2 C API) |
| swf-rs (Rust crate) | Would add a Rust build step to the Python-based test pipeline |
| JPEXS FFDec | Java dependency; designed for editing existing SWFs, not generating from scratch |

---

## Implementation Plan

### Phase 1: Infrastructure

**1a. Install swfmill in build environment**

The build scripts (`build_test.sh`, `build_all_examples.sh`) already auto-run
`create_test_swf.py` when `test.swf` is missing, so no changes to the build pipeline
are needed.  The only requirement is that `swfmill` is installed.

Add a check at the top of each `create_test_swf.py`:

```python
if shutil.which("swfmill") is None:
    print("Error: swfmill not found. Install with: apt install swfmill")
    sys.exit(1)
```

**1b. Create shared helper module: `SWFRecomp/tests/graphics/swfmill_helpers.py`**

A small Python module providing convenience functions for generating swfmill XML.  This
avoids duplicating XML boilerplate across 14 scripts.

Proposed API:

```python
from swfmill_helpers import SWFMLBuilder, SolidFill, LinearGradientFill, RadialGradientFill, LineStyle

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

shape = swf.define_shape(object_id=1)
shape.add_fill(SolidFill(255, 0, 0))
shape.add_line_style(LineStyle(width=20, r=0, g=0, b=0))
shape.move_to(100, 200, fill_style1=1, line_style=1)
shape.line_to(300, 0)
shape.line_to(0, 200)
shape.line_to(-300, 0)
shape.line_to(0, -200)

swf.place_object(object_id=1, depth=1)
swf.show_frame()
swf.save("test.swf")  # writes XML, runs swfmill xml2swf, cleans up
```

The module handles:
- SWF header XML (with RECT in twips)
- `SetBackgroundColor`
- `DefineShape` / `DefineShape2` with bounds, fill styles, line styles, edge records
- Fill types: `Solid`, `LinearGradient`, `RadialGradient`, `ClippedBitmap`
- Edge types: `ShapeSetup` (with optional style changes), `LineTo`, `CurveTo`
- `PlaceObject2` with optional transform matrix
- `DoAction` with trace strings
- `DefineBits` for JPEG bitmap data
- `ShowFrame` / `End`
- XML serialization and swfmill invocation

This keeps each test's `create_test_swf.py` short and focused on describing the shapes,
rather than XML construction.

### Phase 2: Convert existing graphics tests

Convert all 14 tests, starting with the simplest and progressing to the most complex.
Each conversion consists of:

1. Run `swfmill swf2xml` on the deployed `docs/examples/graphics/<test>/test.swf` to get
   the reference XML.
2. Write `create_test_swf.py` using the helper module to produce equivalent XML.
3. Run `create_test_swf.py` to generate `test.swf`.
4. Verify the generated SWF by running it through `SWFRecomp` and comparing the recompiled
   output against the reference.

**Conversion order** (grouped by feature complexity):

**Group A — Solid fills, straight edges only (DefineShape):**

| Test | Fills | Lines | Edges | Notes |
|------|-------|-------|-------|-------|
| `two_squares` | 2 solid | 1 | 10 LineTo | Simplest |
| `ssquare` | 1 solid | 0 | 4 LineTo | + DoAction trace |
| `sssquare` | 1 solid | 0 | 4 LineTo | + DoAction trace |
| `three_boxes` | 3 solid | 1 | 12 LineTo | + DoAction trace |
| `three_boxes_hole` | 4 solid | 1 | 16 LineTo | |
| `awful_shape_swf_4` | 1 solid | 0 | 10 LineTo | + DoAction trace |

**Group B — Multiple shapes or holes:**

| Test | Fills | Lines | Edges | Notes |
|------|-------|-------|-------|-------|
| `three_boxes_holes` | 7 solid | 1 | 30 LineTo | 2 DefineShape tags |

**Group C — Line-only styles:**

| Test | Fills | Lines | Edges | Notes |
|------|-------|-------|-------|-------|
| `thiccie` | 0 | 3 | 2 LineTo | Lines only, no fills |

**Group D — Curved edges:**

| Test | Fills | Lines | Edges | Notes |
|------|-------|-------|-------|-------|
| `coicle` | 1 solid | 0 | 8 CurveTo | Circle approximation |

**Group E — Gradients:**

| Test | Fills | Lines | Edges | Notes |
|------|-------|-------|-------|-------|
| `awful_gradient` | 11 linear | 1 | 8 LineTo | Multiple gradient fills |
| `awful_radial_gradient` | 2 linear + 2 radial | 1 | 7 LineTo | Mixed gradient types |

**Group F — DefineShape2 (StateNewStyles):**

| Test | Fills | Lines | Edges | Notes |
|------|-------|-------|-------|-------|
| `new_styles` | 2 solid | 2 | 8 LineTo | ShapeSetup with inline new styles |

**Group G — Bitmap fills:**

| Test | Fills | Lines | Edges | Notes |
|------|-------|-------|-------|-------|
| `mess` | 2 bitmap | 0 | 4 LineTo | DefineBits + ClippedBitmap fill |

**Group H — Complex (many shapes and curves):**

| Test | Fills | Lines | Edges | Notes |
|------|-------|-------|-------|-------|
| `wild_shadow` | 21 solid | 0 | 397 LineTo + 594 CurveTo | DefineShape2, large shape |

### Phase 3: Validation approach

Graphics tests cannot be validated with text comparison like the opcode tests.  The
existing approach (visual comparison via the demo page with optional Ruffle side-by-side)
remains the primary verification method.

For the migration specifically, verification is:

1. **Binary comparison of SWFRecomp output** — Run `SWFRecomp` on both the original and
   generated SWFs and compare the generated C source files.  If the recompiled output is
   identical, the SWFs are functionally equivalent.

2. **Visual spot-check** — For any tests where the recompiled output differs (e.g., due to
   different bit-packing alignment producing different but semantically equivalent shape
   data), do a visual comparison in the demo page.

---

## File Changes Summary

**New files:**

| File | Purpose |
|------|---------|
| `SWFRecomp/tests/graphics/swfmill_helpers.py` | Shared SWF XML generation module |
| `SWFRecomp/tests/graphics/<test>/create_test_swf.py` (×14) | Per-test SWF generation script |

**No changes needed to:**
- `build_test.sh` — already auto-runs `create_test_swf.py` when `test.swf` is missing
- `deploy_example.sh` — already copies `test.swf` from the test source directory
- `all_tests.sh` — graphics tests are not run in the automated test suite (no `validate.py`)
- `.gitignore` — `*.swf` is already ignored; `create_test_swf.py` is the source of truth

---

## Risks and Mitigations

| Risk | Mitigation |
|------|-----------|
| swfmill produces slightly different binary than the originals | Validate via SWFRecomp output comparison, not byte-for-byte SWF comparison |
| swfmill not available in CI | Add `apt install swfmill` to CI setup; or commit generated SWFs as fallback |
| `wild_shadow` has ~1000 edge records; tedious to transcribe | Use `swf2xml` output directly, embed the edge data as a data structure rather than individual API calls |
| swfmill XML format may not support every SWF feature | All features used by the 14 tests are confirmed supported via round-trip testing |
