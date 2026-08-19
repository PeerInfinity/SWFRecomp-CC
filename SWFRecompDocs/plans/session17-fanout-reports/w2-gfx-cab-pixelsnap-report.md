# s17 w2-gfx-cab-pixelsnap — cacheAsBitmap `PixelSnapping::Always`

**NEW FILES CREATED BY THIS PATCH: none.** Every hunk edits a file that is
already tracked — `SWFRecomp/src/swf.cpp`, `SWFModernRuntime/include/libswf/swf.h`,
`SWFModernRuntime/include/libswf/tag.h`, `SWFModernRuntime/src/libswf/tag.c`.
`git add -u` stages the whole patch; nothing needs naming.

Patch: `SWFRecompDocs/plans/session17-fanout-reports/w2-gfx-cab-pixelsnap.patch`
(also copied to the main tree at the same path).

---

## Verdict — **GO. +3 pixel flips, 0 regressions, canary 52/52 identical.**

| Flip | before | after |
|---|---|---|
| `visual/cache_as_bitmap/avm1_color:output` | fail, 1192 outliers (limit 0) | **pass, 0** |
| `visual/opaque_background:output` | fail, 3856 outliers (limit 0) | **pass, 0** |
| `visual/cache_as_bitmap/text:output` | fail, 8910 @tol 128 (limit 1500) | **pass, 10233 @tol 0 (limit 12000)** |

Two of the three land **byte-exact** against the golden. `opaque_background`
closes s16 P2's named residual; `text` is a bonus the brief's own premise
argued against (see §1).

The board priced this **+1 to +4**; delivered **+3**. But the *owner list* was
almost entirely wrong: 4 of the 5 rows the brief named are refuted, and 2 of the
3 flips were not on it.

**Not flipped, but moved:** `visual/cache_as_bitmap/scroll_rect` 2056 → **2**
(−99.9 %, one pixel short of a flip; named completion mechanism in §8).
**Cost:** `visual/cache_as_bitmap/scroll_rect_scaled` 2301 → 2445 (still passes,
limit 2800, 355 of headroom left).

---

## 1. What the brief priced vs what the corpus contains

| Row the brief named | Uses cacheAsBitmap? | Diff a translation? | Verdict |
|---|---|---|---|
| `visual/cache_as_bitmap/text` | yes (2 PlaceObject3 flags) | **no** — best sub-region shift improves 1745 → 1678 (4 %) | Premise refuted, **row flips anyway** — see below |
| `visual/cache_as_bitmap/edittext_hscroll` | **no** — no PlaceObject3 BitmapCache flag, and the string `cacheAsBitmap` does not occur anywhere in the SWF | no (best shift is *worse*: 32 → 36 px) | REFUTED. It only *lives in* the upstream `cache_as_bitmap/` directory. |
| `text/br_at_start` | **no** — no flag, no string | no (4 diff regions, none shiftable) | REFUTED. Measured after the patch: 14419 → 14419, byte-identical. `offset_translation` cluster membership is a symptom label, not an owner. |
| `visual/cache_as_bitmap/cab_mask_alpha` | yes (AVM2 script) | **no** | REFUTED: expected is 2498/3200 px **white** (the mask crops to a sliver); we draw the full unmasked content. That is Ruffle's cacheAsBitmap-on-cacheAsBitmap *alpha* mask arm (`display_object.rs:1982`) — a different lead entirely. |
| `visual/cache_as_bitmap/cab_mask_transform` | yes (AVM2 script) | **no** | REFUTED, same mechanism (1170/1600 px disagree). |
| `visual/opaque_background` | yes (1 flag, on the left block) | **YES** — region-restricted `(+1,+1)` takes 3856 → 4 | CONFIRMED, **flips to 0**. |
| **`visual/cache_as_bitmap/avm1_color`** *(not named)* | yes (2 flags) | **YES** — whole-frame `(+1,+1)` takes 1192 → **0** | CONFIRMED, **flips to 0**. |
| `visual/cache_as_bitmap/scroll_rect` *(not named)* | yes (1 flag) | partly — whole-frame `(+1,+1)` takes 2056 → 570 | CONFIRMED mover; lands at **2**, no flip. |

**The `text` correction (attack your own refutation too).** My shift analysis
was right that the diff is *not* a translation — it is device-font glyph
rasterisation, and Ruffle's own `test.toml` says so. What I got wrong was
concluding the snap could not help. The golden was rendered *with* the snap, so
moving the field by the sub-pixel remainder re-phases every glyph against the
pixel grid; the tolerance-0 outlier count drops under this row's own
`max_outliers = 12000` alternative check and the row passes. Ruffle's comment in
that `test.toml` — "the difference comes from the fact that we're rendering
device fonts differently. **Especially wrt. pixel snapping**" — was pointing at
this the whole time. **Standing lesson: a shift-signature test answers "is the
diff a rigid translation", not "will the snap help".** A sub-pixel re-phase is
not visible to an integer-shift probe.

### How the owner set was established (two instruments worth promoting)

1. **A PlaceObject3-flag census over the whole corpus.** ~60 lines of Python
   (inflate, walk tags, recurse into `DefineSprite`, test `flags2 & 0b100`) over
   all **4 493** `test.swf` gives the exact blast radius of the recompiler change
   in ~20 s: **25 tests**, listed in §4. This is the cheap cousin of s16's
   full-corpus recompiler A/B and answers the same question whenever the emission
   is gated on one tag flag.
2. **A whole-frame integer-shift sweep over every failing comparison.** For each
   of the 229 failing image comparisons, shift the published CI `actual.png` by
   each of the 8 neighbouring integer offsets and re-count channel outliers at
   that comparison's own tolerance. **Exactly two rows in the entire corpus**
   improve by ≥50 % — `cache_as_bitmap/avm1_color` and `cache_as_bitmap/scroll_rect`,
   both PlaceObject3-cacheAsBitmap rows. That is a hard upper bound on the
   *rigid-translation* yield of this lead, and it is what refutes "+4 from
   translation". (`opaque_background` needs the region-restricted variant — only
   half its frame is cached; the other block is a plain PlaceObject2.)

Scripts live in the scratchpad
(`.../scratchpad/w2cab/{scan_cab.py,sweep.py,regions.py,chanregion.py}`) and are
worth moving into `ruffle-tests/` alongside the s16 recompiler-A/B note.

---

## 2. Mechanism (verified against Ruffle source, not the brief's summary)

`~/CC/ruffle/core/src/display_object.rs::render_base`, cached arm:

```rust
let offset_x = cache_info.bounds.x_min - cache_info.base_transform.matrix.tx
             + Twips::from_pixels_i32(cache_info.draw_offset.x);
// offscreen pass draws with matrix { tx: -offset_x, ty: -offset_y, ..base }
context.commands.render_bitmap(handle,
    Transform { matrix: Matrix { tx: context.transform_stack.transform().matrix.tx + offset_x,
                                 ty: ...,
                                 ..Default::default() },   // <- IDENTITY 2x2
                ..},
    true, PixelSnapping::Always)          // "cacheAsBitmap forces pixel snapping"
```

and `~/CC/ruffle/render/src/bitmap.rs:87`:

```rust
PixelSnapping::Always => {
    matrix.tx = Twips::from_pixels(matrix.tx.to_pixels().round());
    matrix.ty = Twips::from_pixels(matrix.ty.to_pixels().round());
}
```

The three things the brief asked me to verify:

* **Rounding rule.** `f64::round()` is half **away from zero**: `35.5 → 36`,
  `-35.5 → -36`. C's `round()` is the same function, so the port is exact. It is
  *not* banker's rounding — and that matters, because twips-aligned placements
  land on `.5` px constantly.
* **Per object, not per ancestor chain.** `use_bitmap_cache` stays true inside an
  offscreen pass, so a nested cached child snaps again in its parent's cache
  space, but each object snaps **once**, against its own world bounds, and its
  whole subtree rides along because the blit carries the composed texture. Our
  port snaps at the object and lets `compose_children` propagate — the same scope.
* **Interaction with the object's own matrix.** The blit's 2×2 is
  `Default::default()` = identity; scale and rotation are already inside the
  texture. Composing the offscreen draw with the blit, the net effect on the
  rendered result is **purely a translation of the object's world matrix** by
  `(round(x_min_px) − x_min_px, round(y_min_px) − y_min_px)`: content sits at
  `world − bounds.min` inside the texture and the texture lands at
  `round(bounds.min)`. No offscreen pass is needed to reproduce the only
  observable consequence — which is what makes this ~40 lines instead of a
  renderer feature.

**Bonus finding — scrollRect ordering.** Ruffle pushes the scrollRect translate
*inside* `apply_standard_mask_and_scroll`, i.e. **before** the blit, so the blit
tx is `bounds.x_min − rect.x_min` and *that* is what gets snapped; the crop
quad's matrix is captured **before** the translate and is **not** snapped. Our
`compose_children` already captures the crop slot pre-translate, so putting the
snap immediately *after* the scroll translate and *before* the slot allocation
reproduces Ruffle's order exactly. Getting this backwards would have cost
`cache_as_bitmap/scroll_rect` its 2056 → 2.

**Why a +0.5 px snap moves the raster a whole pixel.** `avm1_color`'s shape
bounds start at local `x_min = 0` and its placement puts the world edge on
`n + 0.5` px — a pixel *centre*, at `quality = "low"` (1 sample). Unsnapped, the
span `[25.5, 100.5)` covers centres `25.5 … 99.5` → pixels 25–99. Snapped to
`[26.0, 101.0)` it covers `26.5 … 100.5` → pixels 26–100. Same width, one pixel
right — exactly the `(+1,+1)` the golden wanted, which is why the row lands
byte-exact rather than merely closer.

**The one place the port deliberately stops (measured, not assumed).**
Filtered cached entries are **excluded**. Ruffle snaps them too, but its blit
position is `bounds.x_min + draw_offset` where `draw_offset` is the filter's
dest-rect growth and the *blurred* pixels live in the cache texture. Our AVM1
filter path is stage-sized (s16 cut 1), so there is no cache texture to snap;
translating the source alone is a third thing, not an approximation of Ruffle,
and it measurably hurts — `visual/filters/blur_scales_with_screen`
30810 → 69375 and `visual/filters/blur_size_grows` 87854 → 88623 with the gate
off (neither can flip either way — both are `max_outliers = 0` at ≥30 k). The
gate is one line, carries the derivation in a comment, and its **completion
mechanism** is a real offscreen cache pass (or filters cut 2's object-sized
`FilterSource`), after which it comes out.

---

## 3. Patch scope

| File | Change |
|---|---|
| `SWFRecomp/src/swf.cpp` | Root PlaceObject3 path (~:4313) and sprite PlaceObject3 path (~:5773): the `BitmapCache` UI8 is *read* instead of skipped and emitted as **its own call** `tagSetCacheAsBitmap(app_context, depth, on)` — the same shape s16 used for `tagSetOpaqueBackground`, so **no `tagPlaceObject*` signature changes arity**. |
| `SWFModernRuntime/include/libswf/swf.h` | Trailing `u8 cache_as_bitmap;` on `DisplayObject` (self-localized: last field, after s16's `opaque_bg_*`). |
| `SWFModernRuntime/include/libswf/tag.h` | Declaration of `tagSetCacheAsBitmap`. |
| `SWFModernRuntime/src/libswf/tag.c` | `tagSetCacheAsBitmap` (next to `tagSetOpaqueBackground`); five `static` helpers (`cab_world_bounds_min`, `cab_snap_delta`, `cab_snap_in_place`, `cab_snap_world`, `cab_snap_root_leaf`) placed immediately before `compose_children`; one call inside `compose_children` (nested entries) and, in **each** of `tagShowFrame` / `tagRerenderFrame`, one root-leaf call plus one line each in the sprite and button arms. |

All new symbols are `static` and prefixed `cab_`; the only non-static addition is
`tagSetCacheAsBitmap`. **No** `render_webgpu.c` change, no new pipeline, no
`render_stub.c` twin, no `avm2_display.c` change — so no textual overlap with any
sibling in `SIBLING_FILE_MAP.md` (w2-gfx-drawgraphicsdata and w2-gfx-filters-cut2
both live in `avm2_display.c`, which this patch does not touch at all).

Bounds come from the existing `opaque_bg_local_bounds` (s16), forward-declared
above `compose_children`; that is deliberate reuse — Ruffle uses the same
`render_bounds_with_transform` for the opaque-background rect and the cache
bounds.

### Two things the debugging turned up that are worth keeping

* **The container's own slot must move, not just the children's.** A first cut
  snapped only the matrix handed to `compose_children`. That renders a cached
  *sprite*'s contents at the snapped position while its `opaqueBackground` rect
  (drawn from `obj->transform_id` by `render_display_list`) stays one pixel back:
  `visual/opaque_background` went 3856 → **1504**, not → 0. In Ruffle the
  background is the cache texture's **clear colour**, so it rides the snapped
  blit with everything else. `cab_snap_world` now mints a dynamic slot for the
  entry itself as well. Measured both ways; the comment records it.
* **Root static text is skipped** — `renderer_compose_text_transforms` reads the
  CPU-side transform table, which has no entry at a dynamic slot. No corpus test
  puts cacheAsBitmap on a root `DefineText`, and `cache_as_bitmap/text` is a
  `DefineEditText` (leaf arm), which is snapped. Stated, not hidden.

### Arity / header sync note (and a correction to the s16 lesson)

s16's morph patch hand-synced `docs/recompiler/runtime_headers/include_libswf_tag.h`.
**That is not needed here, and on inspection it was never the right mechanism:**
`SWFRecomp/scripts/deploy_wasm_demo.sh:98-110` *copies* the live headers into
`docs/recompiler/runtime_headers/` at deploy time. The checked-in copy is already
stale by many sessions — it predates `is_replace` on all eight `tagPlaceObject*`
signatures, the current `tagSetFilter` signature, and `tagSetOpaqueBackground`
entirely. Hand-adding one line would not make the deployed WASM recompiler emit
the new call (that needs a rebuilt WASM binary) and would not fix the rest of the
drift.

**Action for the coordinator:** the in-browser demo recompiler needs a full
`deploy_wasm_demo.sh` redeploy before it emits `tagSetCacheAsBitmap` — the same
outstanding redeploy s16 flagged for `tagDefineMorphShape`. This patch adds one
more reason for it and does not make anything worse: an old deployed recompiler
simply omits the call, the runtime field stays 0, and behaviour is exactly
today's.

---

## 4. Blast radius — the 25 tests whose generated C changes

From the corpus census (`cab` = PlaceObject3 BitmapCache count, `opq` =
BackgroundColor count). **Eleven currently PASS**, six of them at exactly 0
outliers with `tolerance = 0` — that is the exposure, and §5 measures all of it.

```
  1 cab  0 opq  from_shumway/acid/acid-mask                      (fail 12051/10970/9486)
  1 cab  0 opq  from_shumway/timeline/nav/cacheAsBitmap          (trace-only, pass)
  2 cab  0 opq  visual/cache_as_bitmap/avm1_color                <- FLIPS
  2 cab  2 opq  visual/cache_as_bitmap/avm2_button               (fail 4432, AVM2 route)
  1 cab  0 opq  visual/cache_as_bitmap/avm2_button_state         (pass 536/900)
  1 cab  0 opq  visual/cache_as_bitmap/children_changed          (pass 0)
  1 cab  0 opq  visual/cache_as_bitmap/color_transform           (pass 0)
  1 cab  0 opq  visual/cache_as_bitmap/contains_grown_filter     (pass 0, tol 5)
  1 cab  0 opq  visual/cache_as_bitmap/drawing_api               (fail 2295)
  3 cab  0 opq  visual/cache_as_bitmap/masks                     (pass x7 — CANARY member)
  1 cab  0 opq  visual/cache_as_bitmap/morph                     (pass 0)
  1 cab  0 opq  visual/cache_as_bitmap/nested_color_transform    (pass 0)
  1 cab  0 opq  visual/cache_as_bitmap/nested_matrix             (pass 0)
  1 cab  0 opq  visual/cache_as_bitmap/nested_rotation           (fail 25665)
  2 cab  0 opq  visual/cache_as_bitmap/oversize/swf_10_masks     (fail 119943)
  2 cab  0 opq  visual/cache_as_bitmap/oversize/swf_10_too_big   (pass 0, known_failure)
  2 cab  0 opq  visual/cache_as_bitmap/oversize/swf_9_masks      (fail 119943)
  2 cab  0 opq  visual/cache_as_bitmap/oversize/swf_9_too_big    (pass 0, known_failure)
  1 cab  0 opq  visual/cache_as_bitmap/scroll_rect               (fail 2056 -> 2)
  1 cab  0 opq  visual/cache_as_bitmap/scroll_rect_scaled        (pass 2301 -> 2445)
  1 cab  0 opq  visual/cache_as_bitmap/shape_changed             (pass 0 — CANARY member)
  2 cab  0 opq  visual/cache_as_bitmap/text                      <- FLIPS
  1 cab  0 opq  visual/filters/blur_scales_with_screen           (fail 30810, GATED)
  2 cab  0 opq  visual/filters/blur_size_grows                   (fail 87854, GATED)
  1 cab  1 opq  visual/opaque_background                         <- FLIPS
```

AVM1 / AVM2 *script*-set `cacheAsBitmap` (the `cab_mask_*` family) is **not**
plumbed by this patch — see §8.

---

## 5. Per-comparison ledger

All numbers are local `--mode=graphics --images --verbose` runs in this worktree,
tolerance and `max_outliers` per each test's own `test.toml`.
**Every single "before" number equals the graded CI baseline from run
`31877239992` exactly** (1192, 3856, 2056, 2301, 8910, 30810, 87854, 4432, 2295,
25665, 119943, 12051/10970/9486, 14419, 536, 3103/3014/3010/3105/2985/2625/2520,
and all the zeros). That is the s13 "prove local grading is CI-grade" check, in
its strongest available form — an exact numeric match on 30 comparisons rather
than a PNG eyeball.

### Flips (3)

| comparison | before | after | note |
|---|---|---|---|
| `visual/cache_as_bitmap/avm1_color:output` | **fail** 1192 (tol 0, limit 0) | **pass 0** | byte-exact |
| `visual/opaque_background:output` | **fail** 3856 (tol 1, limit 0) | **pass 0** | byte-exact; closes s16 P2's residual |
| `visual/cache_as_bitmap/text:output` | **fail** 8910 @tol 128 (limit 1500) | **pass** 10233 @tol 0 (limit 12000) | passes on the row's *first* check |

### Moved, no status change (2)

| comparison | before | after | note |
|---|---|---|---|
| `visual/cache_as_bitmap/scroll_rect:output` | fail 2056 (limit 0) | fail **2** | −99.9 %; residual is ONE pixel, `(329,261)`, the crop rect's bottom-right corner: we paint white, Ruffle red. See §8. |
| `visual/cache_as_bitmap/scroll_rect_scaled:output` | pass 2301 (limit 2800) | pass **2445** | +144, 355 of headroom left. The cost side of the same crop-edge tie. |

### Unchanged — every number identical before and after (25 comparisons)

`cache_as_bitmap/masks` ×7 (3103 / 3014 / 3010 / 3105 / 2985 / 2625 / 2520,
limit 3200) · `shape_changed` 0 · `morph` 0 · `nested_matrix` 0 ·
`nested_color_transform` 0 · `children_changed` 0 · `color_transform` 0 ·
`contains_grown_filter` 0 · `avm2_button_state` 536/900 ·
`oversize/swf_9_too_big` 0 · `oversize/swf_10_too_big` 0 ·
`avm2_button` 4432 · `drawing_api` 2295 · `nested_rotation` 25665 ·
`oversize/swf_9_masks` 119943 · `oversize/swf_10_masks` 119943 ·
`acid-mask` 12051 / 10970 / 9486 · `text/br_at_start` 14419.

**The six 0-outlier rows staying at 0 is the load-bearing result**: our
world-bounds `x_min` agrees with Ruffle's `render_bounds_with_transform` closely
enough that the snap is a no-op wherever Ruffle's is.

### Gated (2) — would have worsened, do not

| comparison | before | ungated | shipped (gated) |
|---|---|---|---|
| `visual/filters/blur_scales_with_screen:output` | fail 30810 (limit 0) | fail 69375 (**+125 %**) | fail **30810** — exactly the baseline |
| `visual/filters/blur_size_grows:output` | fail 87854 (limit 0) | fail 88623 | fail **86708** (−1146, a small *improvement*) |

`blur_size_grows` carries **two** PlaceObject3 cab flags and only one of the two
entries has a filter, so the gate leaves one snap live — hence the improvement
rather than an exact restore. Neither row can flip either way
(`max_outliers = 0` at ≥30 k), so the gate costs nothing and removes the only
worsening in the patch.

---

## 6. Canary

`ruffle-tests/render_canary.py capture before` / `capture after` over the full
standing `render_canary_tests.txt` (25 tests, **52 comparisons**), `--recompile`
on both legs (mandatory: this patch touches `SWFRecomp/`, false-negative mode 1),
`-P 2`, `SWFRECOMP_COMPILE_TIMEOUT=2400`.

```
RENDER CANARY  before=before  after=after   25 tests / 52 comparisons

  IDENTICAL    52
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0

  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

**md5 identity on all 52. Nothing to explain.**

**cacheAsBitmap coverage of the standing set (as the brief asked).** Two members
carry PlaceObject3 `BitmapCache`: `visual/cache_as_bitmap/masks` (3 flags,
7 comparisons, tier 1) and `visual/cache_as_bitmap/shape_changed` (1 flag,
tier 1). Both are exercised by this change and both are byte-identical — because
their world bounds land on whole pixels, so Ruffle's snap is a no-op there too.

**Canary blind spot, stated (s15 rule).** The standing set therefore contains
**no member whose snap delta is non-zero** — a canary of 52 IDENTICAL cannot, by
itself, distinguish "the snap is correct" from "the snap never fired". The rows
that prove it fired are the three flips and `scroll_rect`, all graded by hand
above. **Recommended addition to `render_canary_tests.txt`:**
`visual/cache_as_bitmap/avm1_color` (tier 1 after this patch — byte-exact against
its golden at tolerance 0, 2 PlaceObject3 cab flags, and the only corpus test
whose entire content is a snapped cached object). `visual/opaque_background`
would be the tier-1 pick for the sprite+opaqueBackground arm.

**Gate verification.** The 52/52 above was captured *before* the filter gate was
added, so a targeted re-capture (`label=final`, `-P 1`) was run over the six
standing members that carry cacheAsBitmap or filters —
`cache_as_bitmap/masks`, `cache_as_bitmap/shape_changed`, `filters/drop_shadow`,
`filters/color_matrix`, `filters/glow_pass_scaling`,
`avm1/bitmapdata_applyfilter_colormatrix` (12 comparisons). Result:
**12/12 IDENTICAL against `before` AND against `after`** — the gate is a no-op
for the standing set, so the 52/52 result holds for the shipped patch.

---

## 7. Trace axis

The patch cannot move AS-visible geometry by construction: `cache_as_bitmap` is a
new field read **only** inside the render compose, the snapped matrix goes into a
*dynamic* slot, `xform_overrides_push` records the swap, and
`xform_overrides_restore` puts the baked id back at the end of the frame — so
every CPU-side reader outside the render pass (`getBounds`, `_x`/`_y`,
`localToGlobal`, hit tests, `ng_getDisplayEntryBounds`) sees the unsnapped
matrix, and every reader *inside* it already goes through
`ng_get_original_transform_id`. Measured anyway:

| test | baseline status | after |
|---|---|---|
| `avm1/movieclip_default_state` (reads `cacheAsBitmap` among the MC default props) | pass | **PASS** |
| `avm1/movieclip_library_state_values` | ruffle_matched | **RUFFLE_MATCHED** |
| `avm1/textfield_cache_as_bitmap` | pass | **PASS** |
| `avm1/global_instance_decls` | output_mismatch | **MISMATCH** (unchanged) |
| `avm2/stage_properties2` | pass | **PASS** |
| `from_shumway/timeline/nav/cacheAsBitmap` (PlaceObject3 cab, trace-only) | pass | **PASS** |
| `from_gnash/actionscript.all/MovieClip-v5` | ruffle_matched | **RUFFLE_MATCHED** |

Zero movement. On top of that, all 30 image-bearing tests above reported their
baseline trace verdict, and the canary's 25 tests carry their trace diffs along
for free (0 trace status changes).

---

## 8. Left on the board

* **`visual/cache_as_bitmap/scroll_rect` — one pixel from a flip.** Residual is
  exactly `(329, 261)`: we paint white, Ruffle paints red. It is the crop
  rectangle's bottom-right corner. Our crop quad matches Ruffle's construction
  exactly (captured pre-scroll-translate, **not** snapped — verified against
  `apply_standard_mask_and_scroll`), so this is a rasterisation tie on the crop
  stencil's own edge, the same half-open/closed question the fill edges have:
  `hairline_edge_drift` territory. **Completion mechanism:** grade the crop
  quad's edge rule against Ruffle's tessellator at `quality = "low"` (1 sample) —
  the same sub-pixel A/B §17.4 already names for
  `avm2/displayobject_opaque_background`'s 10 circle-edge pixels. Same fix
  probably reclaims `scroll_rect_scaled`'s +144.
* **The filter gate.** Removing it needs an actual offscreen cache pass (bounds-
  sized texture, `draw_offset` from the filter's dest rect, blit at the snapped
  origin) — i.e. the thing filters cut 2 is already circling for displacement.
  Until then the gate keeps `blur_scales_with_screen` / `blur_size_grows` at
  their baselines. Both are ≥30 k outliers at `max_outliers = 0`, so nothing is
  being deferred that could flip.
* **AVM1 / AVM2 *script*-set `cacheAsBitmap` is not plumbed.** Only the
  PlaceObject3 tag flag is. The AVM1 getter still hard-returns `false`
  (`action.c:54688`) and there is no setter; AVM2 keeps it in a `__cacheAsBitmap`
  dynamic prop (`avm2_display.c:10725`) that never reaches a display entry.
  **Deliberately out of scope**: no corpus row is blocked on it — the only
  script-cacheAsBitmap image rows are `cab_mask_alpha` / `cab_mask_transform` /
  `cab_mask_triangle` / `cab_mask_filters`, and all four fail for the
  cacheAsBitmap-on-cacheAsBitmap **mask** reason (§1), which the snap does not
  touch. Whoever takes that lead should plumb the property at the same time.
* **`cab_mask_*` (4 comparisons, 4644 + 2340 + 5280 + 4968) is a real, separate,
  named lead**: Ruffle's `display_object.rs:1982` picks an **alpha**-mask path
  (rather than the stencil path) when *both* maskee and masker are bitmap-cached,
  and composites the maskee's alpha against the masker's. We render the maskee
  unmasked. Expected images are ~78 % white; ours are fully painted. That is a
  bigger prize than anything left in this lead.
* **`text/br_at_start` and `cache_as_bitmap/edittext_hscroll` need re-clustering**
  on the board — neither has any cacheAsBitmap, and neither diff is a
  translation. `offset_translation`'s "cluster yield 1.00" is an artefact of the
  classifier grouping *symptoms*.
