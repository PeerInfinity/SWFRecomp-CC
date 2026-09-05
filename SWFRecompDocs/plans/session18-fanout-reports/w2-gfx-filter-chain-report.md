# w2-gfx-filter-chain — session 18, wave 2 (worktree patch)

Agent `w2-gfx-filter-chain`. Worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ab1569948e5099125`, base HEAD
`8f68a5fea`. **No commits, no pushes, no edits in the main tree.**
Scratch: `<scratchpad>/w2-gfx-filter-chain/`.

Patch: `SWFRecompDocs/plans/session18-fanout-reports/w2-gfx-filter-chain.patch`
(worktree copy + main-tree copy).

## NEW FILES

**None.** The patch touches three existing files only:

| file | region |
|---|---|
| `SWFModernRuntime/include/libswf/swf.h` | ONE trailing field on `DisplayObject` (`const void* filter_chain`) |
| `SWFModernRuntime/src/libswf/tag.c` | `render_filtered_object` + two new statics above it (`build_filter_chain`, `filtered_object_cxform`, `cxform_apply_rgba`); `opaque_bg_local_bounds` (one condition); `tagBeginFilterList` (2 lines); the two placement arms that already clear `filter_type` |
| `SWFRecomp/src/swf.cpp` | the DefineSprite PlaceObject3 arm ONLY: BackgroundColor parse (`~:5999`) + `tagSetOpaqueBackground` emission (`~:6234`) |

No sibling overlap: no other wave-2 agent is listed against `tag.c`'s filter or
opaque-background regions, and `swf.cpp`'s sprite PlaceObject3 arm is mine alone.

---

## 0. Verdicts first

| # | change | comparison | before → after | verdict |
|---|---|---|---:|---|
| 1 | **filter CHAIN** (whole `SurfaceFilterList`, in order) | `visual/filters/blur_size_grows` | **86 708 → 6 383** (−92.6 %) | **GO — band move, 0 flips** (`max_outliers = 0`) |
| 2 | chain | `from_shumway/acid/acid-filter` (`[Blur, Blur]`) | 482 → 482 | **GO, inert** — its residual is edge drift, not the chain |
| 3 | chain | `from_shumway/acid/acid-filter-2` (`[Glow(compositeSource), Blur]`) | 16 764 → **HELD at 16 764** | **HOLD — the naive chain made it 64 921.** Gated; see §2.3 |
| 4 | **A3 cxform on the FILTER OUTPUT** | `from_shumway/acid/acid-filter-2` | **16 764 → 2 986** (−82.2 %) | **GO — band move. The brief's "+1 flip, highest confidence" is REFUTED**, see §3 |
| 5 | **B1 `tagSetOpaqueBackground` in the DefineSprite arm** (+ its runtime half) | `visual/cache_as_bitmap/avm2_button` | **4 432 → 6** (−99.86 %) | **GO — 3 pixels from a flip.** The remaining 3 px are the tessellator edge rule, i.e. another owner's row |

**Net: 0 flips landed, three large band moves (−92.6 %, −82.2 %, −99.86 %), one
row deliberately held, and two refutations of wave-1 pricing.** Every other
comparison measured is byte-identical before/after.

### Refutations (rule 1)

1. **`w1-gfx-fill-report.md` §1 A3's "100 % of the outliers obey
   `expected = (255, v, v)` while ours is `(v, v, v)` … residual after the fix
   should be ~0 … +1 flip, highest confidence" is WRONG on the ~0 and therefore
   on the flip.** Split by channel against the golden at the row's own
   tolerance 20:

   | | R | G | B | total |
   |---|---:|---:|---:|---:|
   | baseline | 13 778 | 1 493 | 1 493 | 16 764 |
   | after A3 | **0** (max diff 1) | 1 493 | 1 493 | **2 986** |

   The cxform half of the diagnosis is exactly right — A3 removes **100 %** of
   the R-channel error and touches nothing else (an A/B of the two *actual*
   PNGs moves only R: 19 474 px, mean ΔR +48.2, ΔG = ΔB = 0.00). But 17.8 % of
   the outlier channels were never a colour-transform problem: they are a
   **glow falloff** difference of up to 64 in G and B, which the report's
   vertical profile at `x = 105` happened to sample where it is zero. The row
   cannot flip on the cxform, and its completion mechanism is the glow kernel,
   not `render_filtered_object`.
2. **`w1-gfx-filters-report.md` §7's "fixing the chain takes this row from
   86 708 to roughly the crisp-circle floor (~100–200 channels)" is optimistic
   by ~30×.** Measured floor is **6 383**, and after the fix the residual is no
   longer "a missing filter": it is a ±2 LSB blue-glow profile drift
   (mean Δ = [−0.7, −2.3, −1.5], 4 840 px at tolerance 3). Direction and sign of
   the diagnosis: correct. Magnitude of the remainder: 30× the estimate.
3. **A chain is NOT "the same loop `avm2_render_filtered` already runs".** Porting
   that loop verbatim made `blur_size_grows` **86 708 → 74 142** — a −14 % move,
   not −99 %. The single-filter path's shortcut (draw the crisp source into the
   framebuffer instead of snapshotting it, and tell the shader
   `composite_source = 0`) is only valid when the filter's source *is* the
   object; for filter *k* > 0 the source is filter *k−1*'s output. Snapshotting
   the pre-final LAYER instead is what gets the −92.6 % (§2.2). **The AVM2
   `.filters` route has the same defect today** — see §7 lead 1.
4. **Porting that loop verbatim also REGRESSES a row.** `acid-filter-2` went
   16 764 → **64 921** because a non-final glow with `compositeSource` loses its
   source through the `colorize` shortcut. That is a live, unguarded defect on
   the AVM2 `.filters` route right now (§7 lead 1).
5. **`w1-gfx-fill-report.md` §2 B1's "~8 LOC, mirroring `:4805`" is only half
   the fix, and its "residual ~278 channels" is 46× pessimistic.** The 8 LOC
   emit the call correctly (verified: exactly one added line of generated C) —
   but the entry it lands on is a **BUTTON**, `ng_getCharBounds` never records a
   bound for a button character, and `opaque_bg_local_bounds` therefore returned
   0 and drew nothing. With the recompiler half alone the row does **not move at
   all** (4 432 → 4 432, measured). With the one-line runtime half it goes to
   **6** channels / 3 pixels.

---

## 1. Method

* Legs are full A/B rebuilds, never a partial one. `git diff` + `git apply -R`
  for the A leg (never `git stash` — `refs/stash` is shared).
  * **A** = HEAD `8f68a5fea`, untouched.
  * **B** = chain + B1 recompiler emission (chain-only ledger).
  * **C** (= the delivered patch) = B + the chain expressibility gate + the
    button-bounds half of B1 + A3.
* `--mode=graphics --images --image-out-dir`, `--recompile` on every copied dir
  (the recompiler changed), `SWFRECOMP_COMPILE_TIMEOUT=2400`, at most two
  verify batches at a time.
* All numbers below are `image_comparisons.<cmp>.stats.outliers` out of the
  comparison's own `max_outliers` budget, read from the run's `--json`.
* An interim leg between B and C measured `blur_size_grows` and `acid-filter-2`
  singly; those single-test numbers are quoted where they carry the argument.

---

## 2. The chain (`SWFRecomp` was already right; the RUNTIME was not)

### 2.1 The brief's premise is half wrong — the recompiler already emits the list

The brief (and `w1-gfx-filters-report.md` §7) prices this as a recompiler
change: "`if (parsed_filter_type == 0)` ×7 and a single `tagSetFilter`
emission". Those seven guards are real, but they only feed the *scalar*
`parsed_filter_*` set. `swf.cpp:4852-4943` **already emits the complete list**
as `tagBeginFilterList` / `tagAddSimpleFilter` / `tagAddColorMatrixFilter` /
`tagAddConvolutionFilter` / `tagAddGradientFilter` / `tagEndFilterList`, and
`tag.c:12240+` already stores it in `g_filter_lists[]` — for the `mc.filters`
*reflection* only. Verified on the generated C:

```
$ grep tag..*Filter ruffle-tests/.../from_shumway/acid/acid-filter-2/RecompiledTags/tagMain.c
  tagSetFilter(app_context, 1, 3, 50, 50, 1, 1, 0,0,0, 1, 1, 0, 0);
  tagBeginFilterList(app_context, 1, 2);
  tagAddSimpleFilter(app_context, 1, 3, 50, 50, 1, 1, 0,0,0, 1, 1, 0, 0);   // Glow
  tagAddSimpleFilter(app_context, 1, 1,  4,  4, 1, 0, 0,0,0, 0, 0, 0, 0);   // Blur
  tagEndFilterList(app_context, 1);
```

So **no recompiler change was needed for the chain at all.** What was missing is
a link from that record to the display entry and a renderer that walks it:

* `DisplayObject` gains ONE trailing field, `const void* filter_chain`
  (`void*` so `swf.h` does not pull in `tag.h`, the same trick `resolved_mc` and
  `placed_by_holder` use). It points into `tag.c`'s file-static
  `g_filter_lists[]`, which is never freed, so it cannot dangle.
* `tagBeginFilterList` sets it (`display_list[depth].filter_chain = fl`). The
  by-depth table stays the reflection path's key; the pointer is the render
  path's, and it survives a depth swap because a swap copies the struct.
* Both placement arms that already do `display_list[depth].filter_type = 0`
  now also clear `filter_chain`, so a re-placed depth cannot inherit the
  previous occupant's list.

`tagBeginFilterList` is emitted only from the ROOT arm, so no two entries can
share a `FilterListData` today; a filtered placement inside a `DefineSprite`
keeps its (single-filter) scalar path unchanged. Making the sprite arm emit
lists too would need the by-depth table to be re-keyed first — recorded as
lead 3 in §7.

### 2.2 `build_filter_chain` — which entry the scalars describe

The scalars are not "filter #0": they are the first entry whose kind is not
ColorMatrix (ColorMatrix folds into the placement cxform and never sets
`parsed_filter_type`; every other kind sets it when `parsed_filter_type == 0`).
That entry also carries the only APPROXIMATION the list does not have —
Convolution renders as a blur of `mx × my`, GradientGlow as a glow of the last
gradient stop, GradientBevel as a bevel, all with **remapped flag bits** the
`all_filters[]` entry deliberately does not share (`swf.cpp:4240` documents the
divergence). So:

* the scalar-owning entry renders **from the scalars** — byte-identical to the
  old behaviour;
* every other Blur / DropShadow / Glow / Bevel entry renders from the list;
* ColorMatrix / non-first Convolution / non-first gradient entries are dropped,
  exactly as before.

A list with one renderable filter therefore reproduces the previous output
exactly. Verified: 15 of the 17 visual comparisons and 61 of 61 canary PNGs are
byte-identical.

### 2.3 The composite source of filter *k* is filter *k−1*'s output

This is the finding that carries the whole change. The single-filter path never
snapshots the source when the shader's formula ends in `+ dest`: it re-draws the
object with a real draw call (`draw_source_after` / `draw_source_before`) and
passes `composite_source = 0`. For a chain that paints a **crisp** silhouette on
top of a blurred one. Measured on `blur_size_grows`:

| variant | outliers |
|---|---:|
| baseline (first filter only) | 86 708 |
| chain, AVM2's loop ported verbatim | 74 142 |
| chain + snapshot the pre-final LAYER | **6 383** |

So a chain (`chain_n > 1`) always sets `needs_source_tex = 1`, never draws the
source itself, passes the real `composite_source` to the shader, and takes
`renderer_snapshot_filter_source` **inside** the ping-pong loop, immediately
before the last filter's `run_blur`. That is Ruffle's model exactly: each filter
consumes the previous layer.

### 2.4 The expressibility gate (why `acid-filter-2` is HELD, not chained)

`filter_tex_a` is the ping-pong's own input *and* output. That expresses a
non-final filter exactly only when its output is "the blurred layer, optionally
recoloured" — a plain Blur, or a glow / drop-shadow with **no** compositeSource,
inner or knockout. Anything else must blend its own source back INTO the layer,
which needs the compose-into-offscreen pipeline this engine does not have; the
`colorize` shortcut silently DROPS that source.

`acid-filter-2` is `[Glow(black, 50/50, compositeSource), Blur(4,4)]`, and
chaining it through `colorize` takes the row from **16 764 to 64 921** — the
ellipse under the glow vanishes. So `build_filter_chain` refuses: if any
non-final entry fails the test, the chain collapses to the scalar entry and the
old single-filter render is kept byte-for-byte. Measured back at 16 764, then
−82 % from A3 on top.

That is an explicit **HOLD**, not a fix. Completion mechanism: a
compose-into-offscreen pipeline (the same one
`visual/cache_as_bitmap/cab_mask_filters` and the AVM2 `.filters` route wait
on — `w1-gfx-filters-report.md` §5).

---

## 3. A3 — the colour transform belongs on the filter OUTPUT

Ruffle renders a filtered object into its cache with an IDENTITY colour
transform, runs the filters, then draws the RESULT with the object's transform.
We render the source WITH the transform, so the transform never reaches the
filter's own colour.

**Implementation, and why it is not a shader change.** The composition shader
emits `filter_colour * f(blurred alpha)` — straight colour in `.rgb`, coverage
in `.a` (`compose_wgsl`, `render_webgpu.c:3968-3999`). Applying the colour
transform to the FILTER COLOUR is therefore *exactly* equivalent to applying it
to the output, for everything except an additive ALPHA term (which would have to
be scaled by the coverage; no corpus test uses one). So the patch adds two small
statics — `filtered_object_cxform` (reads the entry's baked slot, or
`build_cxform_from_obj` when `cx_overridden`) and `cxform_apply_rgba`
(`clamp(mult*c + add, 0, 1)`, the same formula `apply_cxform` runs in the
shader) — and transforms the colour at its two use sites: `renderer_run_blur`'s
colorize colour and `renderer_compose_filter`'s shadow + highlight colours.
Three shaders untouched, no new pipeline, no new uniform.

The composite SOURCE is drawn separately (`draw_source_{before,after}`, or
sampled from the snapshot) and already carries the object's own cxform, so it is
never transformed twice.

**Deliberate limitation**: only CPU-readable cxform slots are honoured — the
placement's baked slot and the AS-set runtime override. A slot minted by
`compose_children` for a nested COMPOSED cxform lives on the GPU with no CPU
mirror, so a filtered object deep inside a tinted container behaves exactly as
it did before. Noted as lead 4 in §7.

**Result**: `acid-filter-2` R-channel error 13 778 → 0 (max diff 122 → **1**),
row 16 764 → 2 986. No other comparison moved — in particular
`visual/filters/color_matrix` (237 → 237), `visual/filters/drop_shadow`
(46 032 → 46 032) and `avm1/color` (canary, md5-identical) are untouched.

**Not mirrored into `avm2_display.c::avm2_render_filtered`.** The brief asks for
it; I deliberately did not. No graded comparison in the corpus exercises it
(`acid-filter-2` is the AVM1 tag route), the AVM2 side reads its colour
transform out of `Avm2Cx`/`ext` rather than a `cxform_id` so it is a different
~40-line change, and it would land untested. Recorded as lead 2 in §7 with the
exact shape.

---

## 4. B1 — `opaqueBackground` inside a `DefineSprite`

Two halves, both required:

1. **Recompiler** (`swf.cpp`, the sprite PlaceObject3 arm): the arm parsed the
   BackgroundColor field only to `cur_pos += 4` past it. It now applies the same
   two Ruffle rules as the root arm (`version >= 11`; `alpha == 0` clears) and
   emits `tagSetOpaqueBackground`. Verified as the *only* change to the
   generated C, by byte diff of the recompiler A/B:

   ```
   68a69
   > 	tagSetOpaqueBackground(app_context, 1, 1, 65280u);   // 0x00FF00, the green
   ```

2. **Runtime** (`tag.c::opaque_bg_local_bounds`): with only half 1, the row does
   not move at all — the entry the call lands on places a **button**
   (`tagDefineButton CHARID(3)`), `ng_getCharBounds` records no bound for a
   button character, and the painter bailed. A button keeps its state contents
   in the same `sprite_display_list` a sprite does (`render_single_object`'s two
   arms are identical), so the fix is one condition:
   `ch->type == CHAR_TYPE_SPRITE || ch->type == CHAR_TYPE_BUTTON`.

`visual/cache_as_bitmap/avm2_button`: **4 432 → 6** outlier channels
(`max_outliers = 0`). The residual is 3 pixels, all of them green-vs-blue at the
circle edge:

```
(44,16) act (0,255,0)  exp (0,0,255)
(81,16) act (0,255,0)  exp (0,0,255)
(20,89) act (0,0,255)  exp (0,255,0)
```

That is the fill-edge inclusion rule at 1 sample — the row that
`w1-gfx-filters-report.md` §8 lead 1 and `w2-gfx-cab-pixelsnap-report.md` §8
already name, now with a **fourth** converging witness and the cheapest one yet
(3 pixels). **Whoever takes the tessellator edge rule gets this flip for free.**

`visual/opaque_background` (the standing canary for this path) stays at 0
outliers / max diff 0.

---

## 5. Per-comparison ledger

### 5.1 `visual` suite, A (`8f68a5fea`) → C (patch), `--mode=graphics --images`

| comparison | budget | A | C | |
|---|---:|---:|---:|---|
| `cache_as_bitmap/avm2_button` | 0 | 4 432 | **6** | **−99.86 %** |
| `filters/blur_size_grows` | 0 | 86 708 | **6 383** | **−92.6 %** |
| `cache_as_bitmap/contains_grown_filter` | 0 | 0 | 0 | = |
| `cache_as_bitmap/masks` .01–.07 | 3200 | 3103/3014/3010/3105/2985/2625/2520 | identical | = |
| `cache_as_bitmap/shape_changed` | 0 | 0 | 0 | = |
| `filters/any_blur_scales_with_screen` | 0 | 4 884 | 4 884 | = |
| `filters/bevel` | 6 | 69 229 | 69 229 | = |
| `filters/blur_fractional` | 0 | 0 | 0 | = |
| `filters/blur_pass_scaling` | 0 | 0 | 0 | = |
| `filters/blur_quality` | 0 | 0 | 0 | = |
| `filters/blur_scales_with_screen` | 0 | 30 810 | 30 810 | = |
| `filters/color_matrix` | 0 | 237 | 237 | = |
| `filters/drop_shadow` | 0 | 46 032 | 46 032 | = |
| `filters/drop_shadow_angles` | 0 | 55 899 | 55 899 | = |
| `filters/glow` | 0 | 24 992 | 24 992 | = |
| `filters/glow_pass_scaling` | 0 | 0 | 0 | = |
| `opaque_background` | 0 | 0 | 0 | = |

Exactly two rows moved, both down. No status changed (17/17 `pass` on both legs).

### 5.2 `from_shumway`, A → B (chain only) → C (patch)

| comparison | budget | A | B (naive chain) | C |
|---|---:|---:|---:|---:|
| `acid/acid-filter` (`[Blur, Blur]`) | 0 | 482 | 482 | 482 |
| `acid/acid-filter-2` (`[Glow, Blur]`) | 0 | 16 764 | **64 921** ← regression | **2 986** |
| `avm1/filters` (7-filter list, trace only) | — | pass, 149/149 lines | pass | pass, 149/149 |

`acid-filter`'s depth-5 placement really is a two-filter list
(`[Blur(0,50,q3), Blur(30,0,q3)]`, confirmed in its generated C) and it now
chains — the outlier count is unchanged because the row's residual is the
hairline edge drift `w1-gfx-filters-report.md` §8 lead 3 identified, not the
filter. Its render did change; the canary set has no member on this route to
say by how much (see §6).

### 5.3 `w1-gfx-filters-report.md` §7's multi-filter table, in full

| SWF | filter list | graded? | A → C |
|---|---|---|---|
| `visual/filters/blur_size_grows` | Blur, Glow | image | **86 708 → 6 383** |
| `from_shumway/acid/acid-filter-2` | Glow, Blur | image | **16 764 → 2 986** (chain HELD; move is A3's) |
| `from_shumway/acid/acid-filter` | Blur, Blur (depth 5) | image | 482 → 482 |
| `from_shumway/avm1/filters` | DropShadow, Blur, Glow, Bevel, GradientGlow, GradientBevel, ColorMatrix | trace only | pass → pass, 149/149 lines identical |
| `avm2/{bevel,glow,drop_shadow,blur,color_matrix,gradient_glow,gradient_bevel}_filter` | 2–3 of one kind | trace only | pass → pass (AVM2 `.filters` route — untouched by this patch) |

---

## 6. Canaries

### 6.1 Render canary — md5 ledger

`ruffle-tests/render_canary.py capture --label before` (at `8f68a5fea`) /
`--label after` (patch), `--recompile --jobs 2 --timeout 5400`, then `compare`:

```
RENDER CANARY  before=before  after=after   29 tests / 61 comparisons
  IDENTICAL    61
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

**Read this with `w1-gfx-filters-report.md` §8 lead 6 in hand: the standing set
has NO member on the AVM1 PlaceObject3-tag filter route, and no member anywhere
that carries a multi-filter list.** Its three filter members
(`avm1/bitmapdata_applyfilter_colormatrix`, `visual/filters/glow_pass_scaling`,
`visual/filters/displacement_map_through_applyFilter`) are on the AVM2
`.filters` and CPU `applyFilter` routes. So 61/61 IDENTICAL is a real
no-collateral-damage result for everything the canary covers and **says nothing
about the rows this patch actually moves**; those are ledgered directly in §5.
Canary additions this exposes are §7 lead 5.

### 6.2 Trace canaries — all byte-identical

| set | tests | result |
|---|---:|---|
| `avm1/{bitmap_filters, bitmapdata_applyfilter_colormatrix, displacementmapfilter_mappoint_throw_error, color}` | 4 | **4/4 pass**, no diffs |
| `avm2/{bevel,blur,color_matrix,convolution,displacement_map,drop_shadow,glow,gradient_bevel,gradient_glow}_filter`, `displayobject_filters`, `filter_rewind`, `filters_array_holes`, `checkfilter` | 13 | **13/13 pass**, no diffs |
| `from_shumway/avm1/filters` (the 7-filter list) | 1 | pass, 149/149 lines |

The `mc.filters` / `.filters` getters still report the full list everywhere they
did: the patch adds a *reader* of `g_filter_lists[]`, it changes nothing about
how the table is written or reflected.

### 6.3 `regression` suite (`--tests-dir=ruffle-tests/tests/swfs/regression --mode=graphics --recompile`)

```
Total tests:     89
Pass:            89 (100.0%)
Fail:            0
Final diff vs previous results:  [diff] pass: 89/89  |  vs prev: no changes
```

**89/89 pass, zero transitions** against the suite's own tracked
`_results/results_previous.json`. (That tracked file, and the per-test
`output.actual.png` / `output.difference.png` a local run writes, were restored /
deleted afterwards; the worktree's status shows only the three source files plus
this report and the patch.) The suite's loaded-child render fixtures
(`avm1_parent_child_{render,bitmap_fill,morph,text}`, `avm2_parent_child_render`)
are the closest members to this change and are among the 89.

---

## 7. New unclaimed leads

1. **`avm2_display.c::avm2_render_filtered` has BOTH chain defects this report
   fixed on the AVM1 side, unguarded, today.** (a) It computes
   `draw_source_after` / `draw_source_before` from the LAST filter and draws the
   crisp object, so every AVM2 `.filters` array of length > 1 whose last filter
   composites its source paints a crisp silhouette over a filtered one —
   measured as −14 %-instead-of-−93 % on the AVM1 twin. (b) Its `colorize`
   shortcut silently drops a non-final composite-source filter's source —
   measured as a **4× regression** on the AVM1 twin. The fixes are the two
   `chained` blocks and the expressibility gate in this patch, transplanted.
   No graded image comparison covers it today (`w1-gfx-filters-report.md` §8
   lead 5's `avm2/bitmapdata_draw_filters` is the closest), so this is a
   correctness lead, not a priced one.
2. **A3's AVM2 mirror**, `avm2_render_filtered`: build the effective `Avm2Cx`
   the render walk already has (`g_avm2_cur_cx` / `parent_cx`) into a 20-float
   cxform and run the same `cxform_apply_rgba` over `f->color` / `last->color`
   / `last->color2`. ~40 LOC. Unpriced — no corpus comparison puts a colour
   transform on an AVM2 filtered object that I could find.
3. **A filtered placement inside a `DefineSprite` still renders only its FIRST
   filter.** `swf.cpp`'s sprite arm emits `tagSetFilter` but no
   `tagBeginFilterList`, and `g_filter_lists[]` is keyed on bare `depth`, so
   adding the emission would let a root depth and a sprite depth collide on one
   `FilterListData`. The fix is to key that table on the entry (or on
   `(display_list, depth)`) first, then add the emission — after which the
   reflection path (`action.c:55744`, which comments "filters only resolve at
   root level today") also becomes correct for nested clips.
4. **A filtered object inside a colour-transformed container does not get A3.**
   `compose_children` mints the composed cxform straight into a GPU slot with no
   CPU mirror, so `filtered_object_cxform` cannot read it. A CPU-side shadow of
   the dynamic cxform slots would close this *and* several other "the renderer
   knows, the CPU does not" gaps.
5. **Canary additions this patch's blind spot argues for** (`render_canary_tests.txt`):
   `from_shumway/acid/acid-filter` (the only AVM1-tag-route multi-filter list
   that renders, tier 2), `visual/cache_as_bitmap/avm2_button` (now 3 px from
   passing — it becomes a tier-1 member the moment the edge rule lands), and
   `visual/opaque_background` (tier 1, passing, and the only guard on the
   opaque-background painter).
6. **`ruffle-tests/recompiler_ab_sweep.sh --old <SHA>` is broken, and its
   `--old-bin` mode has a trap that produces 32-56 FALSE DIFFERS.** Three
   separate faults, each of which cost me a leg before I caught it:
   * its `git archive` list (`SWFRecomp SWFModernRuntime/third_party/libtess2`)
     omits `SWFModernRuntime/include`, and `swf.cpp` has since grown
     `#include "../../SWFModernRuntime/include/gradient_ramp.h"` - so
     `--old <SHA>` cannot build the old binary at all today
     (`fatal error: ../../SWFModernRuntime/include/gradient_ramp.h`).
   * it configures the old binary `-DCMAKE_BUILD_TYPE=Release`, while the
     documented way to build the new one (`cmake ..`, per `CLAUDE.md` and
     `BRIEFS_COMMON.md`) leaves `CMAKE_BUILD_TYPE` **empty**.
   * **the big one:** `SWFRecomp` finds its device font by trying
     `assets/NotoSans.ttf`, `../assets/...`, and `readlink("/proc/self/exe")`
     + `/../assets/...` (`swf.cpp:96-127`). A binary sitting in
     `SWFRecomp/build/` finds `SWFRecomp/assets/NotoSans.ttf`; a binary built
     into a temp dir - which is exactly what `--old <SHA>` always does, and
     what any out-of-tree `--old-bin` does - finds **nothing**, silently emits
     no device-font glyph geometry, and the sweep reports every test with a
     device-font TextField as DIFFERS. Measured: 32 corpus tests, including
     `avm1/typeof`, with `shape_data[90]` vs `shape_data[19269]`. Proven to be
     the cause by rebuilding the old binary from the IDENTICAL source and
     re-running with an `assets` symlink beside it: IDENTICAL.
   All three are small fixes in the script (add `SWFModernRuntime/include` to
   the archive; drop the `-DCMAKE_BUILD_TYPE=Release`; symlink or copy
   `SWFRecomp/assets` next to the old binary). Until they land, the only
   trustworthy mode is `--old-bin` with a binary built from the same configure
   line AND an `assets/` sibling — which is what §8 uses.
7. **SEVEN corpus SWFs recompile NON-DETERMINISTICALLY** — the same
   `SWFRecomp` binary, run twice on the same `test.swf` in two clean temp dirs,
   emits different generated C. `avm1/edittext_newline_stripping`,
   `avm2/edittext_newline_stripping`, `avm2/textfield_input_events`,
   `avm2/away3d_advanced_shallow_water_demo`, `from_shumway/3_joystick`,
   `from_shumway/bitmapbuttons`, `_swfbridge/livetest/n_loader/native_run`.
   Reproduced with the old binary too, so it is not this patch — and they are
   seven of the eight rows the corpus recompiler A/B flags (§8), i.e. **a
   permanent false positive on every future recompiler A/B until fixed.** The
   signature is uninitialised data, not a reordering: in
   `avm1/edittext_newline_stripping` the differing words are the FOURTH column
   of `shape_data` rows (`0x3A42B600` vs `0x97774600` on otherwise identical
   vertices); in `_swfbridge/.../native_run` the whole array length moves
   (`shape_data[123699]` vs `[162057]`). Valgrind or an ASan/MSan build of
   `SWFRecomp` on any one of those files should name it in minutes; it is
   emitting garbage into `draws.c` today.
8. **`visual/filters/blur_size_grows`'s new floor is a blue-glow profile drift,
   not geometry**: 4 840 px at tolerance 3, mean Δ = [−0.7, −2.3, −1.5], and the
   dominant signature is `('0','-','0')` (2 710 px). Same family as
   `acid-filter-2`'s surviving G/B error (max 64). Two rows now point at the
   glow falloff; that is the next filter-accuracy question, and it is the first
   one in this family that is NOT refuted by `w1-gfx-filters-report.md` §3.

---

## 8. Recompiler A/B

`ruffle-tests/recompiler_ab_sweep.sh --old-bin <baseline> -P 2` over the WHOLE
corpus (4 541 SWFs). Baseline = a binary built from **this worktree's own source
with only `swf.cpp` reverted**, into a build dir configured with the same line
(`cmake ..`, `CMAKE_BUILD_TYPE` empty) and with an `assets/` symlink beside it so
the device-font lookup succeeds. Without those two things the sweep reports 32-56
FALSE DIFFERS — see §7 lead 6.

```
=== recompiler A/B sweep: 4541 SWFs ===
  IDENTICAL     4533
  DIFFERS          8
```

**Exactly one of the eight is this patch:**

| test | verdict |
|---|---|
| `visual/cache_as_bitmap/avm2_button` | **REAL** — the one added line, below |
| `avm1/edittext_newline_stripping` | pre-existing NONDETERMINISM |
| `avm2/edittext_newline_stripping` | pre-existing NONDETERMINISM |
| `avm2/textfield_input_events` | pre-existing NONDETERMINISM |
| `avm2/away3d_advanced_shallow_water_demo` | pre-existing NONDETERMINISM |
| `from_shumway/3_joystick` | pre-existing NONDETERMINISM |
| `from_shumway/bitmapbuttons` | pre-existing NONDETERMINISM |
| `_swfbridge/livetest/n_loader/native_run` | pre-existing NONDETERMINISM |

Each of the seven was proved by running the **same** binary twice on the same
`test.swf` in two clean temp dirs: all seven differ from themselves.

The one real diff is a single added line of generated C:

```
$ diff old/RecompiledTags/tagMain.c new/RecompiledTags/tagMain.c
68a69
> 	tagSetOpaqueBackground(app_context, 1, 1, 65280u);
```

A targeted 6-SWF control confirms the negative side: `visual/filters/blur_size_grows`,
`visual/opaque_background`, `visual/cache_as_bitmap/contains_grown_filter`,
`from_shumway/acid/acid-filter` and `from_shumway/acid/acid-filter-2` are all
IDENTICAL - **the chain and A3 halves of this patch are pure runtime and cannot
move a single test through the recompiler.**

---

## 9. Patch scope (exact)

```
SWFModernRuntime/include/libswf/swf.h   +16   trailing `const void* filter_chain` on DisplayObject
SWFModernRuntime/src/libswf/tag.c      +...   build_filter_chain, filtered_object_cxform,
                                              cxform_apply_rgba, render_filtered_object chain loop,
                                              opaque_bg_local_bounds button arm,
                                              tagBeginFilterList link, 2 clear sites
SWFRecomp/src/swf.cpp                   +32   DefineSprite PlaceObject3 BackgroundColor parse + emit
```

Nothing else in the tree is touched. `ruffle-tests/tests/swfs/regression/_results/`
is dirtied by running the regression suite locally and is **not** part of the patch.
