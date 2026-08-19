# Session 17 — wave 2 — `w2-gfx-edittext-bg` — EditText background/border, mechanism (A)

## VERDICT: **GO** — +5 image comparisons flip (4 briefed + 1 unpredicted rider), 2 band moves, 0 regressions on either axis.

**NEW FILES CREATED BY THIS PATCH: NONE.** Three existing files only —
`SWFModernRuntime/include/actionmodern/action.h`,
`SWFModernRuntime/src/actionmodern/action.c`,
`SWFModernRuntime/src/libswf/tag.c`. Nothing to add to `verify_output.py`'s
source list, CMakeLists, or the Emscripten build.

* Patch: `SWFRecompDocs/plans/session17-fanout-reports/w2-gfx-edittext-bg.patch`
  (180 insertions / 13 deletions; runtime-only, no `SWFRecomp/` change, so the
  main tree's `SWFRecomp/build` was copied per playbook §5).
* Base: worktree merged to `master` **`9d038c750`** — fast-forward, no conflicts.
  Master's `cab-mask-stencil` and `acid-shapes` patches touch `avm2_display.c`
  and `render_webgpu.c`; this patch goes near neither.
* All numbers below are local `--mode=graphics` A/B legs measured on
  `9d038c750` (patch applied vs `git apply -R`; never `git stash`).

---

## 1. Expected-flip ledger

### Flips (fail → pass), all `tolerance 0 / max_outliers 0`

| comparison | before | after | notes |
|---|---:|---:|---|
| `visual/edittext/edittext_background_basic [output]` | **1902** | **0** | briefed row; matches CI baseline `31877239992` exactly |
| `visual/edittext/edittext_background_basic_scale2 [output]` | **7741** | **0** | briefed row |
| `visual/edittext/edittext_border_basic [output]` | **1227** | **0** | briefed row |
| `visual/edittext/edittext_border_basic_scale2 [output]` | **6072** | **0** | briefed row |
| `visual/edittext/edittext_negative_bounds [output]` | **720** | **0** | **UNPREDICTED RIDER** — `tolerance 128`, max diff now 111, 0 outliers |

### Band moves (fail → fail, improved)

| comparison | before | after | Δ | why it does not flip |
|---|---:|---:|---:|---|
| `visual/edittext/edittext_bounds_vs_position [output]` | 1080 | **519** | −52 % | the top half of the fixture is now byte-exact; the residual is the *sprite-nested* copy of the same six fields (see §7) |
| `text/br_at_start [output]` | 14419 | **3691** | −74 % | `tolerance 128 / max_outliers 8`; residual is text layout, not the box |

### Everything else measured: byte-identical

| set | rows compared | changed |
|---|---:|---:|
| `visual/edittext/*` (20 tests) | 66 | 6 (all above) |
| `text/*` (8 real tests + 3 nested) | 15 | 1 (`br_at_start`) |
| `visual/fonts/*` + `visual/cache_as_bitmap/{edittext_*,text}` | 28 | 0 |
| `fonts/*` incl. `embed_matching/*` | 10 | 0 |
| `from_shumway/{captions,flash_text_TextField,flash_text_TextField2,hardwrap,stylesheet,acid/acid-text*,acid/acid-textfield*}` | 31 | 0 |
| `regression/` full suite (72 tests) | 72 pass / 0 fail with the patch | 0 |
| render canary (29 tests / 61 PNGs) | 61 | 0 |

Two rows flipped `recomp_fail` ⇄ `compile_fail` between legs — `text/auto_size`
and `fonts/embed_matching`. **Both are harness artefacts, not results**: those
two directories are *parents of nested tests* and carry no `test.swf`, so the
verdict is just "`--recompile` was/wasn't passed on that leg". Verified by
re-running `text/auto_size --recompile` with the patch applied: `RECOMP_FAIL —
SWF file 'test.swf' not found`. Their real nested children
(`auto_size/{height,return,width}`, `embed_matching/{fallback_preferences,
match_style,no_font_found}`) were graded separately: **0 changed rows**.

---

## 2. The board's framing is REFUTED — and the replacement is one sentence

s16's P6 and the s17 board both describe mechanism (A) as *"certain EditText
background/border configurations are **never emitted at all** — Ruffle draws a
wide black bar and two magenta squares we never draw"*.

**Every element is emitted.** Instrumenting `textfield_render_cb` on
`edittext_border_basic` shows all twelve fields arriving at the renderer with
`bg=1 bgcol=ffffff` and correct geometry; instrumenting `render_single_object`
shows all three "missing" magenta squares (`DefineShape` id 5 at depths 7/8/9)
being drawn. **The pixels are drawn and then painted over.**

> **Actual mechanism (A): the EditText box and glyph passes are a POST-PASS run
> after the entire root display list, in `child_mc_cache` CREATION order, so a
> field's background erases every sibling with a higher depth.**

`tag.c`'s `tagShowFrame` / `tagRerenderFrame` walk the root display list
(`for i = 1 .. max_depth`) and only afterwards call
`actionIterateTextFields(textfield_render_cb, …)` +
`actionIterateTextFieldGlyphs(…)`, both of which walk `child_mc_cache` by
creation index. Ruffle paints the box *and* the glyphs from
`EditText::render_self`
(`~/CC/ruffle/core/src/display_object/edit_text.rs:2698`), i.e. at the field's
own position in the display list.

Two independent consequences, both live in these fixtures:

* **a field's box outranks earlier-created siblings' boxes** — a field created
  4th but placed at depth 0 is painted *last*, over the three fields at
  depths 1–3;
* **a field's box outranks the whole display list** — the same depth-0 field is
  painted after every shape, including the three `DefineShape` squares at
  depths 7/8/9.

### Why a *white* background exists at all (the non-obvious half)

`DefineEditText` has **no background flag**. Ruffle mirrors it from the tag's
`BORDER` bit and fills it white:

```rust
// edit_text.rs:303-306, EditText::from_swf_tag
flags.set(EditTextFlag::HAS_BACKGROUND, flags.contains(EditTextFlag::BORDER));
// :331
background_color: Cell::new(Color::WHITE),
```

Our runtime already does exactly this, so `bg=1 bgcol=ffffff` on every bordered
field is **correct, not a bug**. On a white stage it is invisible — *until* it
is drawn out of z-order, at which point a full-stage bordered field becomes an
eraser. That is why the defect reads as "missing ink" on the board, and why it
survived four sessions of pixel work: it only manifests when a low-depth field
is created before higher-depth content.

### The fixtures, decoded

`visual/edittext/edittext_background_basic` (SWF 8, 100×100 px stage, 1 frame,
no text and no font anywhere): four `DefineEditText` characters (`Border=1`)
placed at depths **1, 2, 3, 0, 4, 5, 6**; then a `DefineShape` (id 5, ±100
twips, magenta) placed at depths **7, 8, 9**; then three more fields at depths
**10, 11, 12**. A `DoAction` sets `border=false`, `background=true`,
`backgroundColor=<colour>` on each named field — and the field named `text4` is
the **depth-0, full-stage (2000×2000 twips)** one, with
`backgroundColor = 0xFFFFFF`.

Before the patch our render was missing exactly the six elements `text4` covers:
the 1×1 red field (depth 1), the 10×10 yellow field (depth 2), the 50×10 black
bar (depth 3), and the three magenta squares (depths 7/8/9) — 901 px, and the
two images' white-pixel counts differed by exactly 901 (9304 vs 8403).

`edittext_border_basic` is the same movie with `border`/`borderColor` (the
`Border=1` tag bit alone supplies the white background there);
`*_scale2` are the same two SWFs at `viewport_dimensions = 200×200`
(`scale_factor = 2`).

---

## 3. The fix — three sub-mechanisms

### (A1) Paint each root-timeline field at its own display depth

`action.c` gains a **depth window** honoured by both text-field iterators —
`TF_WINDOW_ALL` (default, historical behaviour), `TF_WINDOW_AT_DEPTH`,
`TF_WINDOW_REST` — plus a per-frame presence table
(`actionBeginTextFieldDepthPass` / `actionHasTextFieldAtDepth`) so the render
loop can skip the iterator walk on depths that carry no field. Without that
table the interleave would be `O(max_depth × child_mc_count)` **per frame**,
which is a real cost on game-sized movies; with it the added work is one
`O(child_mc_count)` scan per frame plus one array probe per depth.

`tag.c` gains one 8-line `static` helper, `tf_draw_at_root_depth`, called from
both root render loops:

* once **before** the loop with `depth = 0` — `for (i = 1; i <= max_depth; ++i)`
  never visits depth 0, yet `PlaceObject2` at depth 0 is legal and is exactly
  what these fixtures use for the full-stage field;
* once per iteration, **before** the `obj->char_id == 0` skip, so a root field
  whose display-list slot is empty is still placed rather than silently dropped
  by both windows;
* the two existing post-pass call sites are wrapped in `TF_WINDOW_REST`, so they
  now cover only what the root walk cannot place — `createTextField` fields
  (AS-space depths), fields inside sprites, orphans. Their order among
  themselves is unchanged.

Scope discipline: the window keys on `mc->parent == &root_movieclip` **and**
`mc->depth ∈ [-16384, -16384 + max_depth]`. Sprite children and dynamic fields
match neither `AT_DEPTH` nor the `REST` exclusion, so they keep byte-identical
behaviour — which the 0-changed-row results for `from_shumway/*`,
`cache_as_bitmap/*` and `visual/fonts/*` confirm.

### (A2) The box origin is the `DefineEditText` bounds RECT, not the placement matrix

Ruffle passes `self.0.bounds` straight into `draw_device_text_box` /
`draw_text_box`. Our **glyph** pass already carried this
(`info.bounds_{x,y}min_twips`, `action.c`); the **box** pass dropped it, so the
two `bounds = [-40,160,-40,160]` fields of `edittext_border_basic` drew 2 px
down and right of Ruffle's. Fixed by folding `ng_getTextFieldBounds()`'s
`xmin`/`ymin` into `info.x` / `info.y`, for tag-defined fields only
(`ng_textfield_idx >= 0`); `createTextField` fields have no static RECT and keep
their `vis_off` origin. This is what flipped the rider
`edittext_negative_bounds`.

### (A3) Pixel snapping and the 1-px border are DEVICE pixels, not stage pixels

Ruffle's `transform_stack` is seeded with the **stage view matrix**, so
`draw_device_text_box`'s `round_to_pixel_ties_even` *and* the standing rule
*"line width of the border is always 1px regardless of zoom and transform"*
(edit_text.rs:2836) are both in device pixels. We snapped and stroked in stage
pixels, which at `scale_factor = 2` is a 2-device-pixel border on a
half-resolution grid — visible in the goldens as 79-pixel perimeters where we
drew 156. `textfield_render_cb` now derives `dscale = context->stage_scale` and
expresses the snapping grid, both branches' border thickness, and the
screen-edge pixel in `20/dscale` stage twips. `dscale == 1` for every test whose
viewport equals its stage, so this is a **no-op outside the `*_scale2` family** —
confirmed by the 61/61 identical canary and the 0-changed-row sweeps.

---

## 4. Sub-mechanism attribution (outliers on the four briefed rows)

| leg | background_basic | background_basic_scale2 | border_basic | border_basic_scale2 |
|---|---:|---:|---:|---:|
| baseline (= CI run `31877239992`) | 1902 | 7741 | 1227 | 6072 |
| + (A1) z-order only | **0** | 133 | 444 | 4854 |
| + (A1)+(A2) | 0 | 133 | **0** | 4854 |
| + (A1)+(A2)+(A3) | **0** | **0** | **0** | **0** |

All four checks are `tolerance 0 / max_outliers 0`, so these are exact matches
against the goldens, not near-passes. (A1) alone owns 100 % of
`background_basic`, (A2) owns the rest of `border_basic`, (A3) owns both
`_scale2` residuals.

---

## 5. Render canary — 29 tests / 61 PNGs, md5 table

`ruffle-tests/render_canary.py capture --label before/after --timeout 5400 -P 2`
then `compare before after`, on the merged `9d038c750` base, with the standing
`render_canary_tests.txt` (both tiers):

```
RENDER CANARY  before=before  after=after   29 tests / 61 comparisons
  IDENTICAL    61
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

| test | PNGs | md5 |
|---|---:|---|
| `avm1/bitmap_data_fillrect` | 1 | IDENTICAL |
| `avm1/bitmapdata_applyfilter_colormatrix` | 1 | IDENTICAL |
| `avm1/color` | 1 | IDENTICAL |
| `avm1/edittext_tag_indent` | 1 | IDENTICAL |
| `avm1/focusrect_swf5` | 12 | IDENTICAL |
| `avm1/mask_with_drawing` | 1 | IDENTICAL |
| `avm1/movieclip_setmask` | 1 | IDENTICAL |
| `avm2/blend_multiply_alpha` | 1 | IDENTICAL |
| `from_shumway/acid/acid-bitmap-fill` | 1 | IDENTICAL |
| `from_shumway/acid/acid-bitmap-fill-2` | 1 | IDENTICAL |
| `from_shumway/acid/acid-blend-2` | 5 | IDENTICAL |
| `from_shumway/acid/acid-gradient-0` | 1 | IDENTICAL |
| `from_shumway/timeline/timeline_as2_5` | 7 | IDENTICAL |
| `regression/avm2_morph` | 1 | IDENTICAL |
| `regression/avm2_timeline_gradients` | 1 | IDENTICAL |
| `regression/avm2_timeline_stroke_gradient` | 1 | IDENTICAL |
| `regression/mask_nested_intersect` | 1 | IDENTICAL |
| `regression/mask_sibling_union` | 1 | IDENTICAL |
| `visual/blend_modes/multiply` | 1 | IDENTICAL |
| `visual/cache_as_bitmap/masks` | 7 | IDENTICAL |
| `visual/cache_as_bitmap/shape_changed` | 1 | IDENTICAL |
| `visual/edittext/edittext_border_transform` | 6 | IDENTICAL |
| `visual/filters/color_matrix` | 1 | IDENTICAL |
| `visual/filters/displacement_map_through_applyFilter` | 1 | IDENTICAL |
| `visual/filters/drop_shadow` | 1 | IDENTICAL |
| `visual/filters/glow_pass_scaling` | 1 | IDENTICAL |
| `visual/simple_shapes/gradients/gradients` | 1 | IDENTICAL |
| `visual/simple_shapes/masks` | 1 | IDENTICAL |
| `visual/simple_shapes/winding_rule` | 1 | IDENTICAL |

**`visual/edittext/edittext_border_transform` — the tier-1 canary the s17
tooling-hygiene agent added for exactly this change class — is byte-identical on
all 6 comparisons** (`.01 .02 .03` pass at 0 outliers, `.05` passes 0/20, `.04`
fails 51/20, `.06` fails 44/20 — the same numbers the hygiene report recorded,
before and after).

### Canary blind spots this change class hits (s15 rule)

The standing set has **no member with an EditText at a low depth under other
content** — i.e. it cannot exercise the interleave itself, only prove the
interleave changed nothing elsewhere. It also has **no member with
`scale_factor != 1`**, so the (A3) device-scale arm is invisible to it. Both
gaps were covered by hand: the 20-test `visual/edittext` sweep (which contains
the only `_scale2` rows in the corpus outside `edittext_underline_scale2`, also
graded and unchanged), the 8-test `text` sweep, the 31-row `from_shumway` text
sweep, and the full 72-test `regression` suite.
**Recommended canary addition for future sessions:**
`visual/edittext/edittext_background_basic_scale2` (tier 1 once this lands) —
it is the only test in the corpus that pins BOTH the z-order interleave and the
device-pixel snapping grid, at `tolerance 0 / max_outliers 0`.

---

## 6. Trace axis

No trace change is expected or observed. The `tag.c` edits are entirely inside
the `#ifndef NO_GRAPHICS` render region (the new `tf_draw_at_root_depth` helper
was deliberately placed *inside* that guard — it references `textfield_render_cb`
/ `textfield_glyph_render_cb`, which do not exist in a `NO_GRAPHICS` build), and
the `action.c` additions are a filter that defaults to `TF_WINDOW_ALL` plus two
new functions no non-graphics caller invokes.

Measured: the render canary reports `TRACE STATUS CHANGES: (none)` across its
29 tests; every per-test `status` in the five suite A/B legs is unchanged apart
from the two missing-`test.swf` parent directories explained in §1; and the
`regression` suite is 72/72 pass with the patch applied.

---

## 7. Residuals, with completion mechanisms

1. **`visual/edittext/edittext_bounds_vs_position` — 519 outliers (was 1080).**
   The fixture draws six fields at root **and the same six again inside a
   `DefineSprite` (char 4) placed at root depth 7**. The root half is now
   byte-exact; the entire sprite half is **not drawn at all** (rows 25–45 of the
   50×50 frame are blank in ours, populated in the golden). This is a *different*
   defect from mechanism (A): a sprite-nested `DefineEditText` never reaches the
   box/glyph passes.
   **Completion mechanism:** extend the same render_self treatment into
   `render_display_list`'s sprite walk with a *parent-scoped* window
   (`mc->parent == <that sprite's MC>` + sprite-local depth) instead of the
   root-scoped one, and confirm a wrapper MovieClip is created for
   sprite-nested fields that no script ever names. Roughly the same shape as
   this patch, one extra window mode. Priced: +1 flip
   (`tolerance 0 / max_outliers 0`, so it is all-or-nothing) plus whatever
   `from_shumway` text rows share the shape.

2. **`text/br_at_start` — 3691 (was 14419, −74 %).** `tolerance 128 /
   max_outliers 8`; the remaining 6421 differing channels are glyph layout
   (line breaking after a leading `<br>`), not the box. Out of scope here.

3. **`visual/edittext/edittext_border_transform [output.04] / [output.06]`** —
   51 and 44 outliers against a 20 budget, unchanged by this patch and by
   design (they are the *embedded-font* `draw_text_box` corner/AA rows the s16
   work already characterised).

4. **`edittext_device_transform_{basic,negative}`, `visual/fonts/*`,
   `fonts/device_font_*`** — all unchanged, all owned by the s17 board's **P5**:
   device fonts have **no outline source** (`abc_devicefont.cpp` emits metrics
   only). Explicitly out of scope per the brief; nothing in this patch moves
   them and nothing in it blocks that arc.

5. **`edittext_border_filters` (827)**, **`edittext_gutter` (1032)**,
   **`edittext_underline` (1974)**, **`edittext_underline_scale2` (27672)** —
   unchanged; all glyph/underline geometry, not box geometry.

---

## 8. Risk notes for the merge

* The patch changes **when** text-field boxes and glyphs are emitted for
  root-timeline fields, which means it changes the stencil push/pop nesting
  context for those fields' glyph masks (they can now be pushed while a
  `clip_depth` range is active). That is what Ruffle does, and the three mask
  canaries (`cache_as_bitmap/masks` ×7, `simple_shapes/masks`,
  `regression/mask_{sibling_union,nested_intersect}`) are all byte-identical —
  but it is the one place a surprise could hide, so a `DIFFERS` on a mask row in
  the merged canary should be read as *this* patch first.
* Per-frame cost: one `O(child_mc_count)` scan (`actionBeginTextFieldDepthPass`)
  plus one byte probe per display depth. The `realloc`'d presence table is
  `max_depth + 1` bytes and is never freed (matching the file's other per-run
  caches).
* `actionSetTextFieldDepthWindow` must be restored to `TF_WINDOW_ALL` on every
  path that sets it — the patch does this in all three call sites
  (`tf_draw_at_root_depth` and the two `TF_WINDOW_REST` post-passes). Any future
  caller must too, or the browser-WASM / mask-capture paths will silently drop
  fields.
