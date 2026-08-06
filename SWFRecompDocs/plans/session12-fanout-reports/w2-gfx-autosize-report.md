# w2-gfx-autosize — text/auto_size + AVM2 EditText glyph clip + AVM1 leading

Agent `w2-gfx-autosize`, session 12 wave 2. Base HEAD `f166e424e`, isolated
worktree. Deliverables: `w2-gfx-autosize.patch` (4 files, +121/-6, runtime only,
**no recompiler change**) and this report.

Predecessor: `wave1-gfx-text.md`. Its §2 mechanism pin was correct in every
detail, including the arithmetic — the patch lands the flip exactly where it
said it would.

---

## 0. Headline result

| | |
|---|---|
| **Comparison flips (fail → pass)** | **2** — `text/auto_size/width [output]`, `visual/fonts/leading_define_font [output]` |
| Regressions (pass → fail) | **0** |
| Byte-identical canary comparisons | **29 of 37** |
| Trace status / trace text moved | **0 of 24** tests (graphics mode), 0 of 10 (no-graphics spot check) |
| Large band moves (still failing, much closer) | 6 comparisons, biggest `avm2/edittext_get_char_index_at_point` 59137 → 22849 channels |

Both flips are **absolute local verdicts**, not A/B guesses: the pre-patch local
render of `text/auto_size/width` reproduced the CI board's 2520 px / 7560
channels *exactly*, and so did `avm2/edittext_get_char_index_at_point` (59137)
and `edittext_get_line_index_at_point` (22217). Local Dawn is byte-equal to the
CI-published actual on this whole family, so the after-numbers below are
CI-predictive.

---

## 1. Change 1 — quality-gated `EditTextPixelSnapping` (`avm2_display.c`)

`avm2_render_textbox`'s `draw_text_box` branch implemented only the
medium/high/best arm of Ruffle's `EditTextPixelSnapping::apply`
(`edit_text.rs:3603-3632`) and applied it unconditionally. At `quality = "low"`
that rounds the box **scale**, so an autosized field 77.75 px tall collapsed to
77 and the bottom border landed a row early.

```c
#if MSAA_SAMPLES == 1                       /* == StageQuality::Low, exactly */
    btx = tw_round_to_pixel_ties_even(btx);
    bty = tw_round_to_pixel_ties_even(bty);
#else
    ... existing trunc + nearbyint(x - 0.35) arm, unchanged ...
#endif
```

`MSAA_SAMPLES` is the harness's own quality signal (`verify_output.py:2483-2488`
emits `-DMSAA_SAMPLES=1` for `quality = "low"` on every gcc invocation, and only
then, because Ruffle maps Low → 1 sample and everything else → 4). The
`#ifndef MSAA_SAMPLES / #define 4` guard `render_webgpu.c:48-49` uses is
replicated at the top of the twips-helper block, so browser/wasm and
no-graphics builds keep the high arm. **No literal `4` was introduced in
`render_webgpu.c`** — the s11 MSAA invariant is untouched.

**Blast radius, measured not guessed:** the corpus has **16** `quality = "low"`
comparisons in total, and exactly **2** of them are AVM2 EditText
(`text/auto_size/width`, `text/auto_size/return`). Every other AVM2 EditText box
comparison runs at the default quality and takes the unchanged `#else` arm —
confirmed byte-identical in the canary (§5.2).

## 2. Change 2 — bottom-right corner of the border, fractional bottoms only

Ruffle's `draw_line_rect` closed strip inks all four corners **when the box
lands on whole pixels**, but not when the bottom edge is fractional. Measured
off both goldens rather than derived:

| golden | box | top row | bottom row | left col | right col |
|---|---|---|---|---|---|
| `avm2/edittext_autosize_height_dynamic` | 36 × 44 @ (0,0), integral | x 0..36 | x 0..**36** | y 0..44 | y 0..**44** |
| `text/auto_size/width` | 210 × 77.75 @ (30,30), low | x 30..240 | x 30..**239** | y 30..108 | y 30..**107** |

i.e. the shared corner `(240,108)` is white in the fractional case and inked in
the integral one. The fast path now drops that one pixel iff the bottom edge is
not on a whole-pixel boundary:

```c
int frac_bottom = fabs((by + bh) / 20.0 - nearbyint((by + bh) / 20.0)) > 1e-6;
```

**This can only fire under the Low arm**, because the high arm `nearbyint()`s
`bd` — so change 2 is self-scoping to the same 2 comparisons and cannot touch a
default-quality field. That resolves wave 1's open risk about the code comment
citing `edittext_autosize_height_dynamic` as a counter-example: it is not a
counter-example, it is the *integral* half of the rule, and it stays
byte-identical (§5.2).

**Refutation recorded:** I could not derive this asymmetry from the GL/Vulkan
diamond-exit rule — under both the "exit" and the "intersect, except p_b"
formulations `(240,108)` should be produced by the bottom segment's start.
Both goldens are reproduced by the empirical rule above; the *fractional-width*
case is unmeasured and deliberately left drawing the full corner (unchanged
from HEAD).

## 3. Change 3 — AVM2 EditText glyphs are now stencil-clipped

`avm2_edittext_collect_glyphs` (`avm2_text.c:3892`) computed the field clip and
the sole caller (`avm2_display.c`, `avm2_render_text`) discarded it. The AVM1
twin (`tag.c:4741-4746`) has always honoured it. Wired it the same way — mask
pushed after the box/border (which stay outside, matching Ruffle's order),
using the already-computed rect in field-local twips through the same transform
slot the glyphs use.

**Coordinator note — sibling interaction, read this before merging.** Your
mid-flight message landed after I had already shipped this. I did **not**
implement AVM2 clipDepth (that is `w2-gfx-bitmapmax`'s, and I read its patch).
But its clipDepth loop makes this EditText mask a *second* stencil user in the
AVM2 walk, which at HEAD it was not. Writing a field rect on top of a live mask
would punch that mask's stencil value out of the field region and the matching
`renderer_end_clip` would drop the outer clip — s11 mask defect B exactly. I
added a zero-coupling guard **inside my own function**:

```c
#if defined(USE_WEBGPU)
    if (has_clip && context != NULL && context->mask_ref != 0) has_clip = 0;
#endif
```

`mask_ref` is a public field of `WebGPURenderContext` (`render_webgpu.h:165`,
"stencil reference of the ACTIVE clip, 0 = none"), so this reads the renderer's
own state and touches **neither** `render_webgpu.c` nor `avm2_render_node`. An
EditText inside a live clip range falls back to pre-patch behaviour (unclipped
glyphs) instead of corrupting the range. Textually the two patches are
disjoint — my `avm2_display.c` hunks are at pre-patch 14752 / 14857 / 14890 /
15052 / 15067, theirs start at 15092 — so they apply in either order. Proper
nesting needs a stencil stack, which is a renderer change and out of scope.

## 4. Change 4 — AVM1 render line advance was missing `leading` (`tag.c`)

`textfield_glyph_render_cb`'s only line advance was
`y_pos += info->font_height`. Ruffle's line height is
`max_ascent + max_descent + line_leading_adjustment()`, where the adjustment is
the **span's** leading and font-provided leading is ignored outright
(`html/layout.rs:254` "Flash Player ignores font-provided leading"). So every
line after the first sat `leading` px too high.
`visual/fonts/leading_define_font`'s `leading = 2` fields put their second line
on row 22 against the golden's row 24 — in all four font blocks, while the
`leading = null` and `leading = 0` fields matched exactly.

Plumbed as `TextFieldGlyphInfo.leading_twips` (`action.h`), filled at both
constructors in `action.c`. Resolution mirrors the measurement path
(`action.c:51384-51392`) **minus its 40-twip createTextField default** — Ruffle
treats an unset `TextFormat.leading` as 0, which is what the two matching fields
prove.

**Risk, stated plainly:** this is the one hunk with corpus-wide reach — any AVM1
EditText whose `TextFormat`/`DefineEditText` layout carries a non-zero leading
now advances differently. It is Ruffle-aligned in direction, the AVM1 witness
`avm1/edittext_tag_indent` stayed byte-identical, and it *improved*
`avm1/define_font_glyph_table_order` (210 → 180 channels) rather than moving it
the wrong way. It is also cleanly separable: it is the `action.h` + `action.c` +
`tag.c` hunks, with zero overlap with changes 1–3, so drop those three files if
the coordinator wants the AVM2-only patch.

---

## 5. Per-comparison ledger

Canary: 24 tests / 37 comparisons, `render_canary.py` md5 A/B, graphics mode,
local Dawn. Absolute columns are tolerance-aware diffs against the repo golden.

### 5.1 Moved (8 comparisons) — every one toward the golden

| comparison | tol | before | after | verdict |
|---|---:|---:|---:|---|
| `text/auto_size/width [output]` | 0 | 7560 ch / 2520 px | **18 ch / 6 px** | **fail → PASS** (`18 outliers (limit 18)`) |
| `visual/fonts/leading_define_font [output]` | 128 | 1728 ch / 576 px | **0 ch** | **fail → PASS** (max diff 95 < 128) |
| `avm2/edittext_get_char_index_at_point [output]` | 0 | 59137 ch | 22849 ch | fail → fail (−61%) |
| `avm2/edittext_get_line_index_at_point [output]` | 0 | 22217 ch | 18403 ch | fail → fail (−17%) |
| `visual/edittext/edittext_gutter [output]` | 128 | 3576 ch / 1192 px | 1032 ch / 344 px | fail → fail (−71%) |
| `text/auto_size/return [output]` | 0 | 2544 ch / 848 px | 36 ch / 12 px | fail → fail, limit 18 (band c_small → a_epsilon) |
| `avm2/edittext_tag_indent [output]` | 128 | 8340 ch | 7884 ch | fail → fail (−5%) |
| `avm1/define_font_glyph_table_order [output]` | 5 | 210 ch / 70 px | 180 ch / 60 px | fail → fail, limit 4 |

`text/auto_size/return`'s residual is **12 isolated single pixels of mixed
polarity on glyph edges** — the Family-A 1-sample coverage-tie class wave 1
capped. Same for `width`'s remaining 6 px at `(117,46) (347,46) (117,146)
(347,146) (117,246) (347,246)`, all ours-missing, all 0↔255. Not fixable
without matching lyon's flattening.

### 5.2 Byte-identical (29 comparisons) — the no-move witnesses that matter

* **Mask family, all IDENTICAL:** `regression/mask_sibling_union` (repo golden,
  exact at tol 0), `avm1/mask_with_drawing`, `avm1/movieclip_setmask`,
  `visual/simple_shapes/masks`. The s11 defect-B risk on change 3 did not
  materialise at HEAD (and cannot, per the §3 guard).
* **AVM1 EditText witness:** `avm1/edittext_tag_indent` IDENTICAL — the leading
  change left the AVM1 side alone where leading is 0, and `tag.c`'s box painter
  applies no `EditTextPixelSnapping` at all, so changes 1–2 cannot reach it.
* **Default-quality AVM2 EditText box family, all IDENTICAL:**
  `edittext_background_basic`, `edittext_border_basic`,
  `edittext_border_basic_scale2`, `edittext_border_filters`,
  `edittext_autosize_height_dynamic`, `edittext_selection_leading` (12 cmps),
  `cache_as_bitmap/edittext_selection` (3 cmps). This is the direct evidence for
  the §1/§2 "cannot touch a high-quality field" claim.
* Unrelated sanity: `avm1/color`, `avm1/bitmap_data_fillrect`,
  `visual/cache_as_bitmap/shape_changed`, `visual/fonts/advance_u16`.

### 5.3 Trace axis

`trace_status` **and** the saved trace text are identical before/after on all 24
graphics-mode canary tests. No-graphics (default mode) spot check, all pass:
`avm1/edittext_leading`, `avm1/edittext_text_height_leading`,
`avm1/edittext_autosize`, `avm1/edittext_align`, `avm2/edittext_leading`,
`text/auto_size/width`, `text/auto_size/return`,
`visual/fonts/leading_define_font`, `visual/fonts/advance_u16`.
`avm2/edittext_tag_indent` fails its trace in both modes — it also failed at
HEAD (`output_mismatch` in the before capture), so it is not a regression.

---

## 6. Not shipped, with the mechanism pinned

Both remaining font singles turned out to be **recompiler-side** parse bugs.
Shipping them would change the generated-C ABI, forcing `--recompile` on every
cached test dir and invalidating the runtime-only canary above, so I kept them
out. Each is diagnosed to the line.

### 6.1 `visual/fonts/advance_u16` — SOLVED, ~20 min of mechanical work

Ruffle reads the DefineFont2/3 layout advance as **`read_u16`**
(`swf/src/read.rs:1079`, `Glyph::advance: u16`). We read `SWF_FIELD_SI16` and
store `s16` (`SWFRecomp/src/swf.cpp:2345`), so the test's 33000 becomes
**−32536** — visible in the generated table:

```c
/* RecompiledTags/tagMain.c:39 */
static const s16 font_1_advances[] = {-32536,102,819,102};
```

At size 10 px that advance is ~322 px, so the golden's second `a` sits at
x ≈ 324; ours goes to x ≈ −317 and is never drawn. That is exactly the reported
`72 missing px inside x[324,332] y[2,19]`.

Widen the chain (values < 32768 are bit-identical, so the blast radius is
literally this one font): `swf.hpp:251` `vector<s16>` → `vector<s32>`;
`swf.cpp:2338-2346` `SWF_FIELD_SI16` → `SWF_FIELD_UI16` + `(s32)` cast;
`swf.cpp:2383` and `:2641` (emitted `static const s16 font_N_advances[]` →
`s32`); `tag.h:196,506` `const s16* advance_table` → `const s32*`; `tag.h:513` +
`ng_shared.c:505` `ng_font_glyph_advance_by_idx` → `s32`; `ng_shared.c:376`
struct field, `:392` `builtin_noto_sans_advances`, `:463`, `:550`;
`tag.c:11465`; the four `s16 adv/a =` call sites in `tag.c:4861, 4952, 5009,
5143`. Requires cmake rebuild **and** `--recompile` (CI does both from a clean
checkout automatically).

### 6.2 `avm1/define_font_glyph_table_order` — partially pinned, needs an audit

Golden draws a narrow ~3 px glyph at the head of each line that we omit
entirely, and our trailing block is 1 px wider:

```
        line 1 (rows 12-21)          line 2 (rows 22-31)
ours    (16..32)                     (32..48)
golden  (12..14) (16..32)            (14..16) (32..47)
```

Our DefineFont parse already seeks absolutely per glyph
(`swf.cpp:2288` `cur_pos = offset_table + entry_offsets[i]`), so plain
out-of-order offsets are handled. The live suspect is one line up:
**`entry_offsets.push_back((u16) tag.fields[i].value)` truncates a `UI32` wide
offset to `u16`** (`swf.cpp:2246`), and the wide/narrow branches are otherwise
identical. Worth an hour with the tag bytes in hand; my leading fix already took
it 210 → 180 channels (limit 4).

### 6.3 Explicitly not touched

The four AA stair-step near-passes (`auto_size/height`, `match_style`,
`visual/fonts/glyph`, `duplicate_font`) — wave 1 capped them and I confirmed the
same class shows up as the irreducible residual on both `auto_size` tests. The
device-glyph-outline slice (5 comparisons, ~24.5k px) stays arc-sized.

---

## 7. Merge notes

* Runtime only. No `SWFRecomp/` change, no `render_webgpu.c` change, no
  `tag.c` mask-path change (my single `tag.c` hunk is the line advance in
  `textfield_glyph_render_cb`, ~line 5097 — nowhere near the mask loops
  `w2-gfx-masks` may touch).
* Sibling file map respected: my `avm2_display.c` hunks are at pre-patch
  14752 / 14857 / 14890 / 15052 / 15067, clear of `w2-errframes`,
  `w2-avclasses` (~5650), `w2-singles` (~11764-11825) and `w2-gfx-bitmapmax`
  (~15092+). `avm2_text.c` was **read only, not edited** — the clip rect it
  already computes needed no change.
* Suggested CI: `mode=graphics`, `categories=all`. The change is inert on the
  trace axis (§5.3), so an `images=true` baseline run is what would actually
  score the two flips.
* Disposition docs: nothing to add. None of the six touched comparisons appears
  in `ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`,
  `RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md` or
  `ignored_tests.txt` (re-verified this session).
