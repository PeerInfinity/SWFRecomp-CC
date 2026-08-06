# wave-1 `w1-gfx-masks` — defect-A re-verification, blast radius, go/no-go

Session 11, wave 1, READ-ONLY on the main tree. **Nothing in the main tree was
modified.** All diagnostic edits lived in a throwaway worktree
(`<scratch>/wt-masks`, deleted at the end); test dirs were COPIED into it at
their canonical suite paths, `SWFRecomp/build` was copied from the main tree
(runtime-only diff), and every run used `--recompile` on first use.

Baseline: HEAD `b4c983ea4`, CI run `30713776612` at `c4496a4c8`
(trace 4188/4424, pixels 217/566).

Prior art re-verified here: `session10-fanout-reports/wave1-gfx-masks.md`
(the four-defect plan). Two of its findings are CONFIRMED, two are CORRECTED.

---

## 0. Headline

| claim (s10) | verdict |
|---|---|
| A: stencil accumulates per pass, mask N tests the union of masks 1..N | **CONFIRMED** — code + byte-exact A/B (−95.6 % outliers on the slice's biggest comparison) |
| A is worth **2 comparison flips** | **REFUTED — 0 flips.** The two `simple_shapes/masks` twins are AA-blocked: their goldens were exported with `quality = "low"` (6 distinct colours) and we always render 4× MSAA (51 colours) at `tolerance = 0`. A perfect mask fix moves them 248261 → 11000 outliers and flips neither. |
| A carries **HIGH risk to the 66-comparison text family** | **REFUTED** — measured blast radius **zero**: all 22 text comparisons in the A/B byte-identical. EditText renders in a pass *after* the display list (`tag.c:5605`/`6642`), so masks pollute text and never the reverse, and on the passing surface the two sets are disjoint. |
| `avm2/mask_reapply` + `acid/acid-clip` belong to defect D | **REFUTED, twice over** — neither has a `RecompiledABC`, so both render through `tag.c`, not `avm2_render_node`; and neither is fixed by union removal (`mask_reapply` byte-identical, `acid-clip` −7 %). They are a **third, unowned mechanism** in the `tag.c` path. |
| B: `setMask` unread by the `tag.c` loops | CONFIRMED (unchanged from s10) |
| C: `scrollRect` is a stub | CONFIRMED (unchanged from s10) |
| D: the AVM2 render walk reads none of clip_depth/mask/scroll_rect | CONFIRMED, but 4 tests leave its ledger (§2) |
| the `regression/` suite has NO mask test | CONFIRMED (zero name matches, zero `clipDepth` placements in any regression SWF) |

**Go/no-go: CONDITIONAL GO** (§7). The patch is cheap and its blast radius is
*measured* at zero — but its measured flip yield is also zero. Take the slot
only for mechanism retirement + unblocking B/C/D; do not book it against
217/566.

---

## 1. Defect A at HEAD — file:line

Three facts in `SWFModernRuntime/src/rendering/render_webgpu.c` compose:

1. **`render_webgpu.c:1942-1944`** (inside `render_webgpu_open_pass`, 1863) —
   the stencil attachment is cleared **once per render pass**
   (`stencilLoadOp = Clear`, `stencilClearValue = 0`). One pass = one frame.
   There is no per-mask reset anywhere.
2. **`render_webgpu.c:1429-1447`** — `stencil_write_pipeline` is
   `compare = Always`, `passOp = Replace`, `stencilWriteMask = 0xFF`, colour
   `writeMask = None`. `Always` means a mask write **ignores any enclosing
   mask**, so nesting cannot intersect; `Replace` with a constant reference
   means a second mask cannot be distinguished from the first.
3. **`render_webgpu.c:2531-2552`** — `begin_clip_mask` and `end_clip_mask`
   both call `SetStencilReference(pass, 1)`; the reference is **hard-coded
   to 1**. `end_clip` is *just* `SetPipeline(render_pipeline)` — it neither
   restores an enclosing mask nor removes the mask it ends.

Consequence: after N masks in one frame the stencil holds `1` over
mask₁ ∪ … ∪ maskₙ, and every `stencil_test(ref == 1)` draw passes over that
whole union. **The first mask in a frame works; every later one is a no-op
and retroactively widens the earlier ones.**

Two corollaries that the fix must carry (both re-verified at HEAD):

- **`tag.c:5453-5459` (`tagRerenderFrame`) still has the ordering bug**: the
  `if (obj->char_id == 0) continue;` sits **before** the
  `i > active_clip_depth` end-of-range check, so an empty depth immediately
  after a clip range leaves the clip active for the next non-empty depth.
  `render_display_list` (`tag.c:3251-3259`) and `tagShowFrame`
  (`tag.c:6408-6416`) have the correct order.
- **Every pipeline clobber is mask-blind.** `SetPipeline(…, render_pipeline)`
  at `render_webgpu.c:2379` (`draw_bitmap_tris`), `2525` (`draw_bitmap_quad`),
  `3652` (`composite_blend`), `3698` (`resume_pass`), `3743`
  (`begin_offscreen_pass`), `3893` (`composite_filtered`), plus
  `set_blend_mode` (2554-2567) which binds a non-stencil pipeline outright.
  A bitmap, a blend-mode object or a filtered object drawn inside a mask
  silently loses its clip today and will keep doing so unless the fix routes
  all of them through one restore helper.

### Mask call sites at HEAD (all in `tag.c`, 5 sites, 26 calls)

```
tag.c:3242-3332   render_display_list()        nested-sprite clip loop  (+3255 end_clip, 3439 tail)
tag.c:4728-4732   EditText field clip push     (pop at 5130-5133)
tag.c:5207-5217   masked_drawing_render_cb()   AVM1 setMask, Drawing-API path
tag.c:5451-5484   tagRerenderFrame()           per-tick capture loop    (+5457 end_clip, 5565 tail)
tag.c:6406-6465   tagShowFrame()               main frame loop          (+6413 end_clip, 6604 tail)
```

### The A/B (byte-exact, local Dawn, throwaway worktree)

Diagnostic patch — the *minimum* change that removes the union and nothing
else (3 edits, `render_webgpu.c`): a monotonic per-mask stencil reference.

```c
static u32 g_diag_mask_ref = 0;                       /* reset in open_pass */
begin_clip_mask: g_diag_mask_ref = (g_diag_mask_ref % 254u) + 1u;
                 SetPipeline(stencil_write); SetStencilReference(g_diag_mask_ref);
end_clip_mask:   SetPipeline(stencil_test);  SetStencilReference(g_diag_mask_ref);
end_clip:        unchanged (SetPipeline(render_pipeline))
```

Because `end_clip` is unchanged, this patch removes *only* the union: it does
not add nesting-intersection, does not restore an enclosing mask, and cannot
change any single-mask frame. Anything that moves under it moved **because of
the union and nothing else**.

**Legs**: `before`/`before2` captured at HEAD (18 tests, 36 comparisons),
then the 3-edit patch, then `after`/`after2`. Byte-exact md5 comparison.

**Result: 3 of 36 comparisons moved. 33 IDENTICAL.**

| comparison | md5 | tolerance-0 outliers vs golden |
|---|---|---|
| `visual/simple_shapes/masks [output]` | `c5fe3f4e` → `5ace9a11` | **248261 → 11000** (−95.6%) |
| `visual/simple_shapes/masks_equal_clipdepth [output]` | `c5fe3f4e` → `5ace9a11` | same (byte-identical twin: identical actual *and* identical golden) |
| `from_shumway/acid/acid-clip [output]` | `0607ec5a` → `6605bb52` | 55362 → 51540 local (−7%) |
| everything else — 6 passing mask cmps, 22 text cmps, `avm2/mask_reapply`, `acid-clip-3` ×2, `text_field_mask`, `edittext_scroll` ×2 | unchanged | — |

Defect A is **CONFIRMED**: removing the union alone takes the largest mask
comparison in the corpus from 155 940 wrong pixels to 5 438, and the render
becomes visually indistinguishable from the golden (black ellipse + red /
yellow / blue squiggle strokes, exactly the golden's composition).

Three things the A/B **refutes**, all of which were predictions of mine or of
s10 before the measurement:

- **`avm2/mask_reapply` is byte-identical under union removal** (36156 → 36156
  outliers — and that is exactly CI's number, so this is CI's verdict, not a
  local artifact). Its two sibling masks do not share a frame; its mask is
  *completely* ineffective (we paint the full 125×150 blue rectangle where the
  golden has a small disc). **Not defect A. Not defect D either** (no ABC) —
  it is an unowned third mechanism in the `tag.c` path.
- **`from_shumway/acid/acid-clip` is only marginally defect A.** Union removal
  fixes its small striped bar and removes two stray stripes, but the dominant
  artifact — a large pink "Y" painted unclipped over the centre of the stage —
  survives untouched. Do not count it as a defect-A flip.
- **The text blast radius is zero, measured.** All 22 text comparisons
  (`edittext_selection_leading` ×12, `edittext_border_transform` ×6,
  `edittext_tag_indent`, `movieclip_create_text_field`, `edittext_scroll` ×2)
  are byte-identical, as are all 6 passing mask comparisons including the two
  traps (`acid-clip-2` at 2881/3000 and `invalidClipDepth`'s 257 masks).

### The finding that changes the go/no-go: the residual is MSAA, and it is structural

The 5 438 residual pixels on `visual/simple_shapes/masks` are **not** mask
error. Every one of them is an edge pixel whose value is a coverage blend
(`(0,115,191)`, `(0,38,64)`, `(128,0,0)`, `(128,128,128)`, `(191,191,191)`…);
there is not a single residual pixel with a delta ≤ 40.

The reason is in the test's own config:

```toml
# ruffle-tests/tests/swfs/visual/simple_shapes/masks/test.toml
[image_comparisons.output]
tolerance = 0
[player_options]
with_renderer = { optional = true, quality = "low" }
```

`quality = "low"` means Ruffle exported this golden with **anti-aliasing
off** — the golden contains exactly **6 distinct colours**; our render
contains **51**, because `render_webgpu.c:1422` hard-codes
`multisample.count = 4` for every pipeline. At `tolerance = 0` the two can
never agree on a curved edge no matter how correct the masking is.

**So a perfect defect-A fix moves `visual/simple_shapes/masks` and
`masks_equal_clipdepth` from the catastrophic band into the hairline band and
flips neither.** 256 tests in the corpus declare `quality = "low"`
(332 comparisons, 41.6 % passing — the passing ones are the axis-aligned
ones); honouring the flag is a separate, corpus-wide lead worth its own
board entry, and it is the actual gate on this slice's flip count.

---

## 2. Flip census and at-risk census

### The discriminator s10 got wrong

s10 classified the slice with `swf_is_avm2.py`. That tool answers *"is the
`HasActionScript3` FileAttributes bit set"*, **not** *"does this movie render
through `avm2_render_node`"*. Four mask tests are AS3-flagged but carry **no
ABC at all** — `verify_output.py` gates the whole AVM2 module tree on
`RecompiledABC/` existing (`verify_output.py:2053`), so they render through
the `tag.c` display loops, i.e. through defect A:

| test | `swf_is_avm2` | `RecompiledABC/` | real render path |
|---|---|---|---|
| `avm2/mask_reapply` | AVM2 | **absent** | `tag.c` → **defect A** |
| `from_shumway/acid/acid-clip` | AVM2 | **absent** | `tag.c` → **defect A** |
| `from_shumway/acid/acid-clip-3` | AVM2 | **absent** | `tag.c` (different mechanism, §3) |
| `from_shumway/clipping` | AVM2 | **absent** | `tag.c` (single mask, passes) |

### Timeline-`clipDepth` census over the whole graded corpus

Scanned every `test.swf` that carries `[image_comparisons]` (370 tests) for
`PlaceObject2/3` with `HasClipDepth`, recursing into `DefineSprite` bodies.
**Only 12 tests in the corpus use timeline clipDepth at all**:

| masks | in one frame | test | pixel status | owner |
|---|---|---|---|---|
| 3 | 1 root + 2 nested in sprite 7 | `visual/simple_shapes/masks` | fail 248261 | **A** |
| 3 | ditto (byte-identical twin) | `visual/simple_shapes/masks_equal_clipdepth` | fail 248261 | **A** |
| 6 | 6 sibling masks across 5 sprites | `from_shumway/acid/acid-clip` | fail 19356 | **A** |
| 2 | 2 sibling root masks (depths 1, 6) | `avm2/mask_reapply` | fail 36156 | **A** |
| 2 | 2 sibling root masks | `avm1/mask_reapply` | **pass** | A (regression surface) |
| 257 | **1 per frame**, all at depth 1 | `from_shumway/invalidClipDepth` | **pass** | A (regression surface) |
| 1 | — | `avm1/mask_with_drawing` | **pass** | A (regression surface) |
| 1 | — | `from_shumway/clipping` | **pass** | A (regression surface) |
| 1 | — | `from_shumway/acid/acid-clip-2` | **pass**, 2881/3000 | A (regression surface) |
| 1 | — | `from_shumway/acid/acid-clip-3` | fail ×2 | other (§3) |
| 1 | — | `from_shumway/3_joystick`, `from_shumway/acid/acid` | fail | other |

**Defect-A ledger, as measured (0 flips, 3 band moves):**

```
visual/simple_shapes/masks                 [output]  248261 -> 11000   band move, NO flip (MSAA/quality=low)
visual/simple_shapes/masks_equal_clipdepth [output]  248261 -> 11000   ditto (byte-identical twin)
from_shumway/acid/acid-clip                [output]   55362 -> 51540   marginal; dominated by another mechanism
avm2/mask_reapply                          [output]   36156 -> 36156   NOT defect A
```

Everything else in the mask slice keeps its s10 owner: `setMask` on
display-list content (B), `scrollRect` (C), and the AVM2 walk (D) — minus the
4 tests re-filed above, so **D is 10 → 8 comparisons**
(`avm2/{displayobject_mask, mouse_pick_dobj_mask,
mouse_pick_non_interactive_dobj_mask, mouse_pick_non_interactive_bitmap_mask,
bitmapdata_draw_masks}`, `from_shumway/MaskTest`,
`visual/cache_as_bitmap/masks [.01–.07]` as one block, `cab_mask_*`) — and
plus a **new unowned bucket** for `avm2/mask_reapply` +
`from_shumway/acid/acid-clip`'s residual: a `tag.c`-path mask that is
*completely* ineffective (both halves: masker painted as content, maskee
unclipped) even with one mask in the frame. That is the mask lead worth
diagnosing next, not defect A.

### At-risk census (the regression surface)

214 comparisons pass on the pixel axis today (111 tests). Exposure to a
defect-A patch:

- **Direct (timeline/Drawing-API mask path): 5 comparisons** —
  `avm1/mask_reapply`, `avm1/mask_with_drawing`, `avm1/movieclip_setmask`,
  `from_shumway/invalidClipDepth`, `from_shumway/clipping`,
  `from_shumway/acid/acid-clip-2`. Two traps:
  - `acid-clip-2` passes with **2881 of a 3000-outlier budget** — the single
    most fragile comparison in the corpus.
  - `invalidClipDepth` places **257 masks with deliberately invalid
    clip ranges** (one per frame at depth 1). It is the natural adversary for
    any push/pop-balanced fix: an unbalanced pop, or an increment that never
    decrements, shows up here first.
- **Indirect (EditText field clip): 31 comparisons / 17 tests** —
  `visual/edittext/edittext_selection_leading` (12),
  `visual/edittext/edittext_border_transform` (4), `avm1/edittext_tag_indent`,
  `avm1/movieclip_create_text_field`, `avm2/edittext_autosize_*` (3),
  `visual/edittext/{edittext_justify, edittext_selection_font_size,
  edittext_device_transform_small_rotation}`, `visual/fonts/leading_embedded_font`,
  `visual/layout/line_vertical_align`, `fonts/embed_matching/no_font_found`,
  `avm1/define_font_glyph_table_overlap`, `avm1/frame_size_translated_*` (2),
  `avm2/bitmapdata_draw_cpu_overwrite_gpu`.
- **Zero exposure**: `from_shumway/MaskTest-3`, `avm2/blend_scroll`,
  `visual/focus_highlight/focus_highlight_empty_clip` — all mask-named but
  they place no clipDepth and (MaskTest-3) render through the AVM2 walk, which
  has no mask code at all. Note MaskTest-3's **trace** is `ruffle_matched`;
  per `ruffle-matched-hides-regression`, read its trace status, not just
  pixels.

**Why the text family is far safer than s10 assumed.** EditText glyphs are
not drawn from the display-list loop: `actionIterateTextFieldGlyphs(
textfield_glyph_render_cb, …)` runs at `tag.c:5605` and `tag.c:6642`, i.e.
**after** the loop finishes. So the pollution is one-directional — timeline
masks pollute the text clip, text never pollutes display-list content. And on
the passing surface those two sets are **disjoint**: not one of the 6 passing
mask tests contains any text (`createTextField`/`TextField`/`htmlText`/
`setTextFormat` absent from all 6 SWFs), and not one of the 17 passing text
tests places a clipDepth. The only residual text risk is *field-to-field*: a
second field's overflowing glyphs currently paint into the first field's rect.

---

## 3. Refutations / corrections (yield)

1. **`avm2/mask_reapply` and `from_shumway/acid/acid-clip` are not defect D**
   (no ABC → they never reach `avm2_render_node`) **and not defect A either**
   (byte-identical / −7 % under union removal). They are a third mechanism:
   a `tag.c`-path mask that does nothing at all. −2 comparisons for the T7 arc,
   +2 for a new bucket.
2. **The "HIGH text-family risk" is not supported** (§2, §1 A/B). The
   defect-A patch cannot touch a text field that does not share a frame with a
   timeline mask, and no passing test does. Measured: 22/22 text comparisons
   byte-identical.
3. **Defect A's flip yield is 0, not 2** — the slice's headline comparisons are
   AA-blocked by `quality = "low"` goldens against our unconditional 4× MSAA
   (§1). This is the single most decision-relevant number in the report.
4. **`from_shumway/acid/acid-clip-3` is NOT defect A.** Its single mask is not
   the problem: our render paints a large solid green rectangle that is absent
   from the golden (golden = red "Hello" on white, 218704 white / 1296 red).
   That is a *mask-or-maskee painted as content* mechanism, and it does not
   move under the union-removal A/B. Do not put it in the defect-A ledger.
5. **`from_shumway/invalidClipDepth`'s 257 masks are one-per-frame**, not 257
   in a frame — so it is not evidence against defect A, but it *is* the best
   adversarial canary for a stack-based fix.
6. **Local Dawn is byte-identical to CI lavapipe for the flat-fill mask
   tests** — verified: our local `before` PNG for
   `visual/simple_shapes/{masks, masks_equal_clipdepth, text_field_mask}`
   md5-matches the CI-published `.actual.png` exactly, and both
   `acid-clip-2` (2881, max_diff 107) and `avm2/mask_reapply` (36156,
   max_diff 204) reproduce CI's outlier counts exactly. It is **not**
   identical for the anti-aliased ones (`from_shumway/clipping` shows 1984
   local outliers at max_diff 1 while passing 0/0 on CI; `avm1/mask_reapply`
   152 at max_diff 1; `acid-clip` 55362 local vs 19356 on CI). Practical rule
   for wave-2: **md5 A/B always; an absolute local grade is quotable only for
   the members checked against a published CI actual first.**
7. **New corpus-wide lead, found while explaining the residual:** 256 tests
   (332 comparisons, 41.6 % passing) declare
   `player_options.with_renderer.quality = "low"`, i.e. their goldens were
   exported with anti-aliasing OFF, while `render_webgpu.c:1422` hard-codes
   `multisample.count = 4` for every pipeline. Every one of those comparisons
   with a non-axis-aligned edge is unpassable at `tolerance = 0` regardless of
   feature correctness. Honouring the flag (a no-MSAA pipeline set, or an
   MSAA-off render path selected from `test.toml`) is a *separate* lead and,
   on the evidence here, a bigger flip source than the whole mask slice.

---

## 4. Canary set for the wave-2 patch

Standing set (`ruffle-tests/render_canary_tests.txt`) carries three of the
right tests (`avm1/mask_with_drawing`, `avm1/movieclip_setmask`,
`visual/simple_shapes/masks`) plus the 3 `regression/` entries. **Not
sufficient.** Use this slice-local list (a `--tests` file; 18 tests,
~30 comparisons, ≈12 min/leg at `-P 2` warm, ~20 min under session load):

```
# must-not-break — tier 1, all PASS on CI today
avm1/mask_with_drawing                    # Drawing-API mask path
avm1/movieclip_setmask                    # Drawing-API setMask (weak for A, strong for B)
avm1/mask_reapply                         # 2 timeline masks, PASSES — sharpest A regression risk
from_shumway/invalidClipDepth             # 257 invalid clip ranges — adversary for push/pop balance
from_shumway/clipping                     # single timeline mask
from_shumway/acid/acid-clip-2             # 2881/3000 outliers — most fragile comparison in the corpus
from_shumway/MaskTest-3                   # check TRACE stays `pass`, not `ruffle_matched`
avm1/edittext_tag_indent                  # text tier-1
visual/edittext/edittext_selection_leading # 12 passing cmps, runtime-created fields
visual/edittext/edittext_border_transform  # 4 passing cmps
avm1/movieclip_create_text_field          # runtime-created field

# expected-to-move ledger — tier 2  (measured, §1)
visual/simple_shapes/masks                # A: band move 248261 -> ~11000, NO flip
visual/simple_shapes/masks_equal_clipdepth # A: identical twin, same numbers
from_shumway/acid/acid-clip               # A: small band move ~-7%, NO flip
avm2/mask_reapply                         # NOT A — must stay IDENTICAL (control)
from_shumway/acid/acid-clip-3             # NOT A — must stay IDENTICAL (control)
visual/simple_shapes/text_field_mask      # B — must stay IDENTICAL under an A-only patch (control)
visual/cache_as_bitmap/edittext_scroll    # text, failing; band-move watch
```

Plus the standing `regression/` 3× (`avm2_timeline_stroke_gradient`,
`avm2_timeline_gradients`, `avm2_morph`) per policy — and, once §5 lands, the
new mask tests replace them as the meaningful regression-suite leg.

`render_canary.py capture --label before --tests <file> --jobs 2 --recompile`
before touching anything; `compare before after` at the end. Only the four
ledger entries may DIFFER.

---

## 5. Regression-suite mask tests to ADD (designs; do not create in wave 1)

The `regression/` suite has no mask, clip or scrollRect test — confirmed by
name match and by the clipDepth scan (zero placements in any regression SWF).
All three designs below are **hand-assembled SWF tags**, not MTASC:
`clipDepth` is a `PlaceObject2` field with no ActionScript equivalent, so
MTASC cannot author R1/R2 at all. Follow the suite README ("ship the SWF's
generator next to it, open its docstring with what the test pins down") and
model the generator on
`regression/mc_event_type1_args/create_test_swf.py` (bare `FWS` writer) plus
`regression/avm2_static_text/build_statictext.py` (bit-writer + shape/glyph
record emitter).

Goldens: **Ruffle exporter only** (`~/CC/ruffle/target/release/exporter`, built
and present). Never capture a golden from our own renderer (playbook §7). If a
golden cannot be produced, ship trace-only and accept
`skip/no_expected_image` — the md5 canary value survives either way.

**Every shape in all three designs is an axis-aligned rectangle on integer
pixel boundaries — deliberately.** §1 showed that the upstream mask tests are
unpassable at `tolerance = 0` because their goldens are un-anti-aliased and we
render 4× MSAA. Axis-aligned rectangles produce no partial coverage in either
renderer, so these tests are gradeable at tolerance 0 *today*, and they become
the only mask comparisons in the corpus that a mask fix can actually flip.
Do not draw a curve, a diagonal or a sub-pixel edge in any of them.

### R1 `mask_sibling_union` — the defect-A test (MUST)

200×200 stage, white background, one frame, no ActionScript.

```
depth 1: shape A = rect (0,0)-(100,100)        clipDepth = 2     -> masks depth 2
depth 2: shape B = rect (0,0)-(200,200) BLUE                     <- masked by A
depth 3: shape C = rect (100,100)-(200,200)    clipDepth = 4     -> masks depth 4
depth 4: shape D = rect (0,0)-(200,200) RED                      <- masked by C
```

- Correct: blue top-left quadrant + red bottom-right quadrant, white elsewhere.
- Today: the stencil holds A ∪ C when D draws, so **red paints over the blue
  quadrant too** — a 10 000-px, colour-exact, AA-free signature.
- This is the shape no existing test covers: two *sibling* top-level masks
  whose maskees overlap each other's mask region.

### R2 `mask_nested_intersect` — nesting semantics (SHOULD)

200×200 stage, white, one frame.

```
root   depth 1: shape M1 = rect (0,0)-(120,120)   clipDepth = 2
       depth 2: sprite S
sprite depth 1: shape M2 = rect (60,60)-(180,180) clipDepth = 2
       depth 2: shape G  = rect (0,0)-(200,200) GREEN
```

- Correct: green only in M1 ∩ M2 = (60,60)-(120,120), a 60×60 block.
- Today: green over the union region.
- **Discriminating value**: a cheap "distinct reference per mask" fix makes
  R1 pass but leaves R2 wrong (green over all of M2). Only the
  increment/decrement stack (§6) makes both pass. Land R2 with the fix and it
  permanently pins the intersection semantics.

### R3 `mask_edittext_stencil_scope` — the text-interaction lock (OPTIONAL)

200×200 stage, white, one frame. Uses an embedded `DefineFont3` with a
**single square glyph** (lift `build_statictext.py` verbatim) so glyph
rendering is a row of solid blocks — no device-font or metric dependency, and
Ruffle's export matches ours by construction.

```
depth 1: shape M = rect (100,100)-(200,140)  clipDepth = 2
depth 2: shape R = rect (0,0)-(200,200) RED             <- masked by M
depth 3: DefineEditText bounds (0,100)-(80,140), embedFonts, text "AAAAAA"
         sized so the glyph run would reach x ≈ 150 if unclipped
```

- Correct: red only in M's band; squares clipped at x ≈ 78 (80 − 2 px gutter).
- Today: the EditText pass runs after the display loop, finds M already in the
  stencil, and its field clip becomes M ∪ fieldRect → the overflowing squares
  paint across M's band as well.
- This is the only cheap way to lock the *ordering* half of defect A.
  Verify first that the glyph callback fires for the field (it early-returns
  at `tag.c:4704` when `ng_find_font_with_metrics` fails).

---

## 6. Fix sketch for one wave-2 agent (defect A only)

Ruffle's `MaskState` model, with one simplification that removes the geometry
replay Ruffle needs.

**`render_webgpu.c`**

1. `1429-1460` — replace the two mask pipelines with three. Read/write masks
   are pipeline-static in WebGPU (only the *reference* is dynamic state), so
   all three keep `stencilReadMask = stencilWriteMask = 0xFF`:
   - `mask_write`: `compare = Equal`, `passOp = IncrementClamp`, colour
     `writeMask = None`
   - `mask_test`: `compare = Equal`, `passOp = Keep`, colour on
     (today's `stencil_test_pipeline`, unchanged)
   - `mask_clear`: `compare = Equal`, `passOp = DecrementClamp`, colour
     `writeMask = None`
2. Add `u32 num_masks` to the context; reset it in `render_webgpu_open_pass`
   next to `stencilClearValue = 0` (`1942-1944`).
3. `2531-2552` — re-shape the three entry points:
   - `begin_clip_mask`: `num_masks++`; bind `mask_write`;
     `SetStencilReference(num_masks - 1)` (the `Equal` compare is what makes a
     nested mask intersect its parent instead of replacing it)
   - `end_clip_mask`: bind `mask_test`; `SetStencilReference(num_masks)`
   - `end_clip`: bind `mask_clear`; `SetStencilReference(num_masks)`; draw ONE
     screen-covering rect (a huge twips rect through the existing `draw_rect`
     path — colour writes are off); `num_masks--`; then restore
     (`num_masks > 0 ? mask_test @ num_masks : render_pipeline`).
     **The full-screen decrement is equivalent to Ruffle's mask-geometry
     replay** — the only pixels holding `num_masks` are exactly those inside
     the innermost mask — and it means `tag.c` does not have to keep the mask
     geometry around to redraw it.
4. One helper `render_webgpu_restore_draw_pipeline(ctx)` = the same
   `num_masks > 0 ? mask_test @ num_masks : render_pipeline` choice, and route
   **every** clobber site through it: `2379`, `2525`, `3652`, `3698`, `3743`,
   `3893`, and the `default:` arm of `set_blend_mode` (2554-2567).
   `composite_blend`'s `stencil_ref` parameter (`3598`, callers pass
   `active_clip_depth > 0 ? 1 : 0`) becomes `num_masks`.

**`tag.c`**

5. Keep a small explicit stack of active clip ranges per loop instead of the
   single `active_clip_depth` scalar, so nested + sibling ranges pop in order
   (`3242-3332`, `5451-5484`, `6406-6465`).
6. `5453-5459` — move the `char_id == 0` skip **after** the end-of-range
   check, matching the other two loops.
7. `4728-4732` / `5130-5133` (EditText) and `5207-5217`
   (`masked_drawing_render_cb`) become proper push/pop pairs — they already
   are structurally, they just inherit the new semantics.
8. A mask that is a SPRITE recurses into `render_display_list` under
   `g_clip_mask_capture` (`3318-3331`); a nested `clip_depth` entry inside
   that subtree must **not** open a second mask level — suppress
   `begin_clip_mask` while `g_clip_mask_capture > 0`, or the counter walks
   away.
9. Stencil is 8-bit: clamp the depth (Ruffle uses the same increment-clamp)
   and assert in debug when `num_masks` exceeds ~250.

**Effort** ~1 session, runtime-only (no `SWFRecomp/` change → no cmake
rebuild, and `--recompile` is not required for the `after` leg).
**Measured flips: 0; measured band moves: 3** (§1). **Risk: LOW** — the
diagnostic that carries the same semantic change moved nothing outside the
ledger. Fence in §7.

Do **not** bundle B, C or D. B (`setMask` on display-list content) depends on
this and is ~0.5 session on its own; D is the T7 arc.

---

## 7. Go / no-go, with the risk fence

**CONDITIONAL GO.**

- **GO** if the wave-2 slot is spent on *mechanism retirement*: defect A is
  real, the patch is ~1 session and runtime-only, its blast radius is
  **measured at zero** (33/36 comparisons byte-identical under the diagnostic,
  including both traps and all 22 text comparisons), and B, C and D all depend
  on it. It takes the corpus's largest mask comparison from 155 940 wrong
  pixels to 5 438.
- **NO-GO** if the slot must produce flips. Measured yield: **0 flips**, 3
  band moves. The two headline comparisons are AA-blocked by `quality = "low"`
  goldens (§1) and `avm2/mask_reapply` / `acid-clip` turn out not to be defect
  A at all. On a flips-graded session the same agent-session buys more on the
  blend extra-element lead or on the `quality = "low"` MSAA lead (§3.7), and
  defect A should ride along with B+C+D when the T7 arc opens.

If GO — the fence a wave-2 agent must satisfy before handing off:

1. **Canary**: `render_canary.py` `before`/`after` over the §4 list. Exactly
   **3** entries may DIFFER — `visual/simple_shapes/masks`,
   `masks_equal_clipdepth`, `from_shumway/acid/acid-clip` — and the first two
   must land at ≈11000 outliers, not lower and not higher (that is this
   report's measured value for a union-only removal; a *correct* stack should
   match it, since the residual is MSAA, not masking). `avm2/mask_reapply`,
   `from_shumway/acid/acid-clip-3` and `visual/simple_shapes/text_field_mask`
   are **controls** — a DIFFER there means the patch reached a mechanism it
   does not own.
2. **The two traps**: `from_shumway/acid/acid-clip-2` (2881/3000 budget) and
   `from_shumway/invalidClipDepth` (257 invalid ranges) must both be
   IDENTICAL, not "still passing".
3. **Text**: all 31 passing text comparisons must be IDENTICAL. The §4 list
   samples 17 of them (`edittext_selection_leading` 12 +
   `edittext_border_transform` 4 + `edittext_tag_indent`); if any of those
   moves, capture the remaining 14 before proceeding.
4. **Trace axis**: `MaskTest-3` must stay `trace=pass`; a move to
   `ruffle_matched` is a regression on a `known_failure`.
5. **Scope**: `render_webgpu.c` + `tag.c` only; no `SWFRecomp/` change (keeps
   the canary free of the stale-recompiler false-negative).
6. **Local grading**: md5 A/B is the bar. An absolute local outlier count is
   quotable only for `visual/simple_shapes/{masks, masks_equal_clipdepth,
   text_field_mask}`, `from_shumway/acid/acid-clip-2` and `avm2/mask_reapply`,
   where local Dawn was verified byte-identical to the CI actual at this SHA
   (§3.6) — **not** for `acid-clip` or `from_shumway/clipping`.
7. **Known-failure accounting**: `from_shumway/MaskTest-2` and
   `acid/acid-mask [.01/.05/.10]` are `known_failure` — movement there is not
   a flip in the graded count.
8. **Closeout honesty**: the CI closeout must report this as *3 band moves,
   0 flips*. Booking it as progress on 217/566 would be wrong.

Deferred, explicitly out of scope: defect B (~0.5 session), defect C
(~0.5–1 session), defect D / T7 (1–2 sessions, 8 comparisons after the
re-filing in §2), the new "mask does nothing at all in the `tag.c` path"
bucket (`avm2/mask_reapply`, `acid-clip`'s residual), and the corpus-wide
`quality = "low"` MSAA lead (§3.7). Flip estimates for all of these should be
re-derived the way this report derived defect A's — a diagnostic A/B plus a
check of whether the golden is even reachable at `tolerance = 0` — because
the s10-style "count the comparisons in the cluster" estimate was wrong by
100 % here.

---

## 8. Reproduction notes

- Worktree: `git worktree add <scratch>/wt-masks HEAD --detach`; test dirs
  copied to canonical suite paths; `SWFRecomp/build` copied from the main tree
  (runtime-only diff); `DAWN_INSTALL=~/CC/dawn-install`;
  `render_canary.py capture --jobs 2 --recompile`.
- Cost: ~60 s/test cold at `-P 2` under session load (7 sibling agents,
  load average ~16); the first test of a leg costs ~135 s, later ones hit
  ccache.
- `pgrep -fc "[r]ender_canary"` **self-matches** a wrapper shell whose command
  line contains the script path — the bracket trick does not help when the
  full command is in the same cmdline. Wait on the background job's own
  completion instead (this cost ~10 min here; it is the same trap as
  `tetris-compare-harness-pkill-selfmatch`).
