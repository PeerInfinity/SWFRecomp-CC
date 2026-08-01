# wave-1 "gfx-triage" — regenerated graphics/pixel board + wave-2 ranking

Session 10, wave 1, READ-ONLY. Nothing in the repo was modified.

**Provenance.** `origin/ruffle-image-results` @ `d7b5f40e6`, extracted read-only via
`git archive` to `<scratch>/image-results` (770 PNGs). Board built from that extract +
the merged per-suite `_results/image_results_graphics.json` on `master`.
Both sides are **run 30701749687 at `feb8882b0`** (session-9 closeout) — the board is
current, not stale.

```
python3 scripts/image_triage.py --images-dir <scratch>/image-results --jobs 4 \
    --out <scratch>/board.json --markdown <scratch>/board.md --top 40   # 42 s
```

Artifacts left in the scratchpad: `board.json` (390 rows), `board.md`, `board.txt`,
`members.txt` (per-slice membership dumps), `statusdiff.txt`.

Headline: **172 / 566 unique comparisons pass (30.4 %), 390 fail, 4 skip.**
Of the 390 failing, **356 are live** on the board (34 excluded: 6 hard-dispositioned,
23 Ruffle `known_failure`, 5 `no_render`), across 272 test×cluster rows.
94 comparisons carry the **soft** `[trace-ign]` flag (avm2 82, from_shumway 12) and stay
rankable — a trace-axis ignore is not a pixel disposition (playbook §3).

---

## (a) Cluster table + delta vs playbook §8

§8's table is the **session-9 start** state (run 30680942974 @ `375373786`, 403 failing).
Delta below = the measured effect of the session-9 focus-rect rider.

| cluster | now (cmps / tests / near) | §8 | Δ cmps |
|---|---|---|---|
| hairline_edge_drift | 70 / 43 / 35 | 70 / 43 / 35 | 0 |
| same_geometry_wrong_fill | 67 / 50 / 2 | 79 / 54 / 2 | **−12** |
| blank_render | 65 / 60 / 0 | 67 / 62 / 0 | **−2** |
| missing_element | 33 / 22 / 1 | 32 / 21 / 1 | **+1** |
| diffuse_mixed | 30 / 28 / 2 | 30 / 28 / 2 | 0 |
| content_displaced | 30 / 24 / 1 | 30 / 24 / 1 | 0 |
| extra_element | 29 / 24 / 1 | 29 / 24 / 1 | 0 |
| unrelated_content | 19 / 9 / 0 | 19 / 9 | 0 |
| halo_penumbra | 16 / 15 / 0 | 16 / 15 | 0 |
| row_banded | 13 / 13 / 2 | 13 / 13 / 2 | 0 |
| global_color_shift | 6 / 4 / 0 | 6 / 4 | 0 |
| no_render | 5 / 3 / 0 | 5 / 3 | 0 |
| offset_translation | 4 / 4 / 0 | 4 / 4 | 0 |
| whole_frame_wrong | 2 / 2 / 0 | 2 / 2 | 0 |
| localized_region | 1 / 1 / 0 | 1 / 1 | 0 |
| **total** | **390** | **403** | **−13** |

**Which slices moved: exactly one.** `same_geometry_wrong_fill` lost 12 (the 11-comparison
focus-highlight slice + one rider), `blank_render` lost 2 (one rider + one migration), and
`missing_element` gained the migrant (`focus_highlight_avm2_button_bounds`, now
`missing_element` at 632 excess, was 800). **Everything else on the board is untouched
since session 9** — no drift, no regressions (`image_status_diff.py ec5078371 b7317667d`:
13 gains, 0 pass→fail, 17 band improvements, 0 worsened).

Band histogram moved only where the fix landed: c_small −2, d_moderate −10, e_large −1.
`same_geometry_wrong_fill`'s d_moderate cell went 32 → 22.

Cluster×band (current):

```
cluster                    a_eps b_tiny c_small d_mod e_large f_cat no_render
hairline_edge_drift           22     13      26      9       0      0
same_geometry_wrong_fill       0      2      27     22      16      0
blank_render                   0      0       1      9      28     27
missing_element                0      1       4      8      18      2
diffuse_mixed                  0      2       6     19       3      0
content_displaced              0      1       2     19       6      2
extra_element                  0      1       3     10      15      0
unrelated_content              0      0       0      1       9      9
halo_penumbra                  0      0       0      7       8      1
row_banded                     0      2       5      6       0      0
global_color_shift             0      0       0      0       2      4
no_render                                                                  5
offset_translation             0      0       1      2       1      0
whole_frame_wrong              0      0       0      0       2      0
localized_region               0      0       1      0       0      0
```

Live family totals (the second useful slicing — mechanism × feature):

```
 66 / 35  Text: EditText / layout / HTML      18 / 18  Gradients
 40 / 21  Shumway acid render tests           16 / 12  (unclassified)
 31 / 31  Stage3D / AGAL / shaders   [BACKEND] 16 / 10  Masks / clipping
 30 / 30  Filters                             15 / 15  Text: embedded fonts / glyphs
 26 / 26  BitmapData / drawing API            11 /  5  Timeline / frames
 23 / 19  Blend modes                         11 /  6  Buttons
 19 / 10  Video / NetStream          [BACKEND]  8 /  4  Scale-9 / transforms
```

---

## (b) The §8 named leads — re-verified, with membership and corrected sizes

### L1. `same_geometry_wrong_fill` blend-mode slice — **still 19 + 4, confirmed**
19 `same_geometry_wrong_fill`: `visual/blend_modes/{add, alpha_no_layer, darken,
difference, erase_no_layer, hardlight, invert, layer_alpha, layer_erase, lighten,
multiply, overlay, overlay_onto_stage, screen, subtract}` (15) ·
`avm2/blend_transform` [trace-ign] · `avm2/displayobject_blendmode` [trace-ign] ·
`from_shumway/acid/acid-blend` · `from_shumway/acid/acid-blend-2 [output.10]`.
\+ 4 more on the same page in other clusters: `acid-blend-2 [output.15], [output.40]`
(diffuse_mixed), `[output.20], [output.26]` (halo_penumbra).
Also adjacent: `avm2/blend_shader_luma_lighten` (sgwf, c_small 1237),
`visual/blend_modes/shader_as_mask` (KNOWN_FAIL, excluded).
Whole Blend-modes family live = **23 cmps / 19 tests**. All bands d_moderate/e_large, all
excess ≥ 13 405 — none are near-passes, so a correct compositing fix flips rather than
band-moves.

### L2. Shumway-acid slice (19) — **stands numerically, but it is FOUR bugs, not one**
22 acid comparisons are `same_geometry_wrong_fill` (19 counted under the "Shumway acid"
family; `acid-bitmapData-copyPixels` and `acid-morph` fall in other families). 16 of the 22
are `from_shumway/acid/acid [output.01…16]`, all at excess **4333** (was 4761 — the
focus-rect fix shaved 428 px off every frame, one of the 17 band improvements).

I decomposed `acid [output.01]` directly from the PNGs. The diff is **not** one element:

| region | px | ours | expected |
|---|---|---|---|
| rows 0–95 (full width) | 2560 | (51,51,0) / (153,51,102) | (51,50,1) / (0,0,0) |
| rows 173–291, x 161–351 | 1755 | (51,51,0) | (255,255,0) |
| rows 454–514, x 0–75 | 1254 | mixed | mixed |
| rows 736–767 (full width) | 1426 | (153,153,0)/(51,51,0) | (242,242,0)/(63,63,0) |

Diff-mask IoU between frames 01/08/16 is 0.87–0.89 → the regions are essentially static
across the 16 frames. **Consequence for wave-2 planning:** the outlier budget is 360, and
each region alone is 1200–2600 px, so fixing one region moves the band but flips nothing.
`acid` is a "take the whole page or don't take it" slice. `image_triage.py` ranks it #1
(score 5.26) on fan-out; that rank is real for *pixels moved* and misleading for
*comparisons flipped*. Treat as **band-move slice**, not a +16 flip.

### L3. `missing_element` text slice — **18 live** (§8 said 18; TOP GROUPS prints 15 because
3 sit in the sibling "embedded fonts" family)
`visual/edittext/edittext_selection_leading [output.01…12]` (12) ·
`visual/edittext/edittext_selection_font_size` · `edittext_device_transform_basic` ·
`edittext_device_transform_negative` · `avm2/edittext_autosize_height_dynamic` [trace-ign] ·
`fonts/embed_matching/fallback_preferences` (121 914) · `visual/fonts/font_lookup_as3`.

`edittext_selection_leading`'s 12 comparisons share one bbox (2,2)–(98,186) with
first-vs-last diff-mask **IoU 0.94** → one mechanism, twelve comparisons, all e_large.
This is the single highest flips-per-fix slice on the whole board.

### L4. `extra_element` masks (9) + filters (7) — **stands**
Masks 9: `avm2/displayobject_mask` [ti] · `avm2/mouse_pick_non_interactive_dobj_mask` [ti] ·
`from_shumway/MaskTest-2` (KF) · `from_shumway/acid/acid-mask [output.01/.05/.10]` (KF) ·
`visual/cache_as_bitmap/{cab_mask_alpha, cab_mask_filters, cab_mask_transform,
masks[output.07], scroll_rect}` · `visual/simple_shapes/{masks, masks_equal_clipdepth,
scroll_rect_mask}`.
Filters 7: `visual/filters/{blur_fractional, blur_quality, drop_shadow, glow,
glow_without_composite_source}` · `visual/cache_as_bitmap/cab_mask_filters` ·
`from_shumway/acid/acid-filter-2`.

### L5. AVM2 SimpleButton `render_list` — **§8 sized this at ~4; the board says 12 / 7 tests**
All seven confirmed AVM2 by `swf_is_avm2.py`, all with a **passing trace**:

*Blank — the button never enters the render list (ink_actual = 0.000):*
`from_shumway/button1 [output.1–.4]` (4 × e_large, 97k–146k) ·
`from_shumway/bitmapbuttons [output]` (f_catastrophic, 618k) ·
`visual/avm2_button_scroll_rect [output]` (e_large, 28 851) ·
`visual/focus_highlight/focus_highlight_avm2_button_bounds [output]` (79 % of expected ink
absent, 632).

*Rendered but wrong state / fill:*
`from_shumway/button2 [output.2/.3/.4]` (3 × e_large, 95 634 each, ink IoU 1.00 —
identical geometry, wrong state chosen) · `visual/cache_as_bitmap/avm2_button` (4692) ·
`visual/cache_as_bitmap/avm2_button_state` (10 353).

`from_shumway/button1` + `button2` + `bitmapbuttons` (8 comparisons) were **not** on §8's
list. Whoever owns the SimpleButton diagnosis should be re-briefed with this set — it
triples the slice.

### L6. Frame-phase suspects — both stand, plus a third the detector misses
- `from_gnash/misc-ming.all/loop/simple_loop_test`: 7 cmps, 5 live (frames 3–7:
  blank_render 21 600 · extra_element 7442 · extra_element 7683 · blank_render 14 400 ·
  missing_element 14 702); frames 1–2 stay hard-dispositioned by the scoped
  `<!-- image-axis: frames 1-2 only -->` marker. Five mechanisms on one test = phase bug.
- `visual/edittext/edittext_border_transform`: 6 cmps, 4 mechanisms (extra_element 375 /
  halo_penumbra 2034 / extra_element 1717 / diffuse_mixed 504 / content_displaced 2802 /
  diffuse_mixed 2524). Never dispositioned. Small excesses — plausible +6.
- **NEW: `from_shumway/timeline/timeline_loop`.** Six of its seven failing comparisons are
  `hairline_edge_drift` at **a_epsilon** (excess 13–18), and `[output.12]` alone is
  `unrelated_content` at 68 195 with ink IoU 0.00. One frame showing entirely different
  content while its neighbours are pixel-perfect is the loop-phase signature; the detector
  didn't flag the test because 6/7 frames agree on the mechanism. Same family as
  `simple_loop_test` — likely one fix for both.

---

## (c) Ranked wave-2 slices (mechanism first, per playbook §2)

"Yield" = comparisons expected to flip **fail → pass**, not pixels moved.

| # | slice | cmps | predicted flip | owner |
|---|---|---|---|---|
| 1 | **Mask / clip not applied** (see below) | 15 core (+11 second tier) | **8–15** | **UNASSIGNED** |
| 2 | Blend-mode compositing | 23 | 15–19 | assigned (blend agent) |
| 3 | `edittext_selection_leading` (one test) | 12 (+1 rider) | 12–13 | assigned (text agent) — size it |
| 4 | AVM2 SimpleButton render/state | 12 | 5–10 | assigned — **re-brief to 12** |
| 5 | Timeline loop phase (gnash + shumway) | 6 | 4–6 | assigned (frame-phase agent) — add `timeline_loop` |
| 6 | `edittext_border_transform` | 6 | 3–6 | assigned (frame-phase agent) |
| 7 | Filters sub-mechanisms (bevel 4, displacement_map 4, blur 5, glow 4) | 17 | 4–8 | UNASSIGNED |
| 8 | Nested colorTransform (`global_color_shift`, prior 1.00) | 4 | 3–4 | UNASSIGNED |
| 9 | Pure translation offsets (`offset_translation`, prior 1.00) | 4 | 2–4 | UNASSIGNED |
| 10 | `visual/scale_rotation_cache [output.15/.25/.35]` | 3 | 3 | UNASSIGNED |
| 11 | `from_shumway/acid/acid` page (4 regions) | 16 | 0 unless all 4 land, then 16 | UNASSIGNED |
| 12 | `edittext_caret_empty` near-pass border snapping | 12 | 0–12 (low confidence) | UNASSIGNED |
| — | Stage3D 31 / Video 19 | 50 | arc-sized, not sweep-sized | — |

**#1 — Mask / clip not applied.** The board's clearest unclaimed mechanism, found by
cross-cutting the clusters on the feature vector rather than the cluster name: 15 live
comparisons have **`extra_ink ≥ 0.6` with `missing_ink ≤ 0.15`**, i.e. we paint content
that the mask should have clipped away, and we lose nothing. Members:

```
visual/simple_shapes/scroll_rect_mask   [output]   434721  extra .76 miss .07  (AVM1)
visual/simple_shapes/text_field_mask    [output]   432212  extra .96 miss .50  (AVM1)
visual/simple_shapes/masks              [output]   248261  extra .60 miss .06  (AVM1)
visual/simple_shapes/masks_equal_clipdepth[output] 248261  extra .60 miss .06  (AVM1)
from_shumway/acid/acid-clip-3           [frame3]    81307  extra .94 miss .00  (AVM2)
from_shumway/acid/acid-clip-3           [output]    78125  extra .97 miss .00  (AVM2)
visual/cache_as_bitmap/masks            [output.07] 39128  extra .95 miss .00  (AVM2)
visual/cache_as_bitmap/scroll_rect      [output]    18384  extra .77 miss .00  (AVM2)
avm2/mouse_pick_non_interactive_dobj_mask[output]   13285  extra .61 miss .00  [trace-ign]
avm2/displayobject_mask                 [output]    13090  extra .67 miss .00  [trace-ign]
avm2/mouse_pick_dobj_mask               [output]     5772  extra .37 miss .00  [trace-ign]
visual/cache_as_bitmap/cab_mask_triangle[output]     5080  extra .90 miss .12  (AVM2)
visual/cache_as_bitmap/cab_mask_filters [output]     4968  extra .78 miss .11  (AVM2)
visual/cache_as_bitmap/cab_mask_alpha   [output]     4644  extra .79 miss .11  (AVM2)
visual/cache_as_bitmap/cab_mask_transform[output]    2340  extra .78 miss .11  (AVM2)
```

`visual/simple_shapes/masks` and `masks_equal_clipdepth` are **byte-identical on both
sides** (`np.array_equal` on actual and on expected) — literally one bug, two comparisons.
Our render has 97.4 % ink where the golden has 28.6 %: the mask is not clipping *at all*
in those two AVM1 tests, even though stencil clipping exists in
`SWFModernRuntime/src/rendering/render_webgpu.c` (`stencil_write_pipeline` /
`stencil_test_pipeline`, lines ~1422–1455, driven from the `clipDepth` path). So the
mechanism is a *gating* bug, not a missing feature — good wave-2 shape.
Second tier (mask applied but to the wrong region — `extra` **and** `missing` both high):
`visual/cache_as_bitmap/masks [output.01–.06]` (6, ~40k each), `scroll_rect_scaled`,
`avm2/mask_reapply`, `avm2/displayobject_scrollrect`,
`visual/cache_as_bitmap/oversize/swf_9_masks` + `swf_10_masks` (blank_render, identical
119 943 → one bug, two comparisons), `avm2/bitmapdata_draw_masks`.

**#8 — nested colorTransform.** `avm2/displayobject_colortransform_nested
[output.1/.2/.3]` all carry the *identical* uniform signed mean `[-51, +204, +204]` with
`signed_std 0` → a deterministic concatenation-order arithmetic bug, three comparisons for
one fix. `visual/cache_as_bitmap/color_transform` is the same cluster with a uniform
`[-38, -38, 0]` shift (169 500 px). `global_color_shift` carries the classifier's highest
fixability prior (1.00) and nobody has ever taken it.

**#9 — pure translations.** `text/br_at_start` (dy2 dx2 removes 67 % of the diff) ·
`from_shumway/acid/acid-text-x` (dy6, 82 %) · `visual/cache_as_bitmap/text` (dy8, 58 %) ·
`visual/cache_as_bitmap/edittext_hscroll [output.02]` (dy−8 dx8, 85 %). Prior 1.00.

**#12 caveat.** `edittext_caret_empty [output.01–12]` is 29 differing pixels per frame
(excess 21) with `max_diff 255` — hard on/off pixels scattered over the field border, not
an AA gradient, so it is probably a border pixel-snapping bug rather than the lavapipe AA
gap. Still `hairline_edge_drift` / a_epsilon, so it carries the playbook's near-pass
warning; only worth taking if an agent is already in EditText border geometry.

---

## (d) New / uncovered — things the board surfaces that nobody is on

1. **Mask/clip is the largest unassigned mechanism on the board** (#1 above). It never
   appears as a headline cluster because the classifier splits it four ways
   (extra_element 9, content_displaced 6, unrelated_content 3, blank_render 2).
2. **`cacheAsBitmap` is the largest cross-cutting *feature* on the board and is unowned:
   32 live comparisons / 22 tests spread over 10 clusters** (hairline 6, content_displaced 8,
   extra_element 5, sgwf 4, missing 2, offset 2, blank 2, unrelated 1, halo 1,
   global_color_shift 1). The runtime stores `cacheAsBitmap` only as a dont-enum dynamic
   property (`avm2_display.c:1653, 9982–9993, 13003`) with no bitmap-cache render path,
   so the flag is effectively a no-op. Whether that *causes* the 32 failures or merely
   carries them (many `cache_as_bitmap/*` tests also exercise masks, filters, scrollRect,
   which fail on their own) needs one scoping agent before anyone commits to it. Note the
   cheap tell inside it: `oversize/swf_9_masks` and `swf_10_masks` are identical failures.
3. **The SimpleButton slice is 3× §8's size** (12, not 4) — `from_shumway/button1`,
   `button2`, `bitmapbuttons` are the same AVM2 SimpleButton mechanism with much larger
   bands. Re-brief the owning agent.
4. **`from_shumway/acid/acid` is four independent wrong regions, not one** — the tool's
   #1 rank cannot flip on a single fix. Documented above with the region table; worth
   folding into the playbook's §8 note next closeout so the next session doesn't
   mis-plan it.
5. **A third frame-phase suspect: `from_shumway/timeline/timeline_loop [output.12]`** —
   6/7 frames at a_epsilon, one frame at ink IoU 0.00. The detector needs an
   "outlier frame among near-pass siblings" rule to catch this shape.
6. **The pixel axis is genuinely independent of the trace axis here**: 336 of the 356 live
   failing comparisons have a **passing** trace. The 20 that don't are the only dual-axis
   candidates: `avm2/{bitmapdata_draw_alpha_erase, blend_transform, displayobject_hittestpoint_boundary,
   displayobject_scrollrect, edittext_tag_indent, geom_transform, graphics_draw_path,
   netstream_seek_flv, stage_scale_factor}`, `fonts/device_font_kerning`,
   `from_gnash/misc-ming.all/GradientFillTest`,
   `from_shumway/{acid/acid-morph, acid/acid-shapes, acid/acid-text-2, acid/acid-text-x,
   flash_text_TextField2}`, `import_assets/avm1_imports_avm1`, `visual/definefont4`,
   `visual/edittext/edittext_device_transform_{basic,negative}`.
   (4 of these are `ruffle_matched` — remember the known-failure trap.)
7. **Local Dawn matched CI lavapipe byte-for-byte** on `visual/simple_shapes/masks`
   (`maxdiff 0` against the published `.actual.png`; trace passes locally). That is a
   datapoint, not a new rule — for total-mechanism failures with no AA in the diff, local
   repro is exact, which makes the mask slice unusually pleasant to iterate on. The
   standing rules still hold: md5 A/B via `render_canary.py`, never grade against a golden.
8. Housekeeping still open from session 9: `avm1/display_object_properties` remains in
   the "DISPOSITIONED BUT NOT FAILING" list (passes; entry already annotated stale), and
   `avm2/netstream_play_flv` is still the one disposition matched **by basename** —
   worth a five-minute verification some session.
