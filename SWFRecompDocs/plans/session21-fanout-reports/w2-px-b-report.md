# s21 w2-px-b: exact `transform.matrix` + AVM1 transformed-border lines

**New files: none.** Both patches only modify tracked files:
- `w2-px-b-1-exact-matrix.patch`: `SWFModernRuntime/include/actionmodern/action.h`,
  `SWFModernRuntime/src/actionmodern/action.c`, `SWFModernRuntime/src/libswf/tag.c` (`apply_as_transform`
  only), and `ruffle-tests/render_canary_tests.txt` (3 members appended at EOF).
- `w2-px-b-2-line-as-rect.patch`: `SWFModernRuntime/src/libswf/tag.c` only (two new static helpers placed just
  above `textfield_render_cb`, plus one branch at its border draw). Stacks on patch 1; apply 1 then 2.

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a5b2168e1b262bfde` (branch has no commits;
the patches are `git diff` output against master `835d9f539`).

## Verdicts

| # | Verdict | Comparison | before → after (local Dawn, `--mode=graphics`) |
|---|---|---|---|
| 1 | **GO** | `visual/edittext/edittext_device_transform_small_shear` [output] | **88 → 49 of 50, PASS** (the w1 probe's 49, the same as Ruffle's exporter) |
| 2 | **GO** | `visual/edittext/edittext_border_transform` [output.04] | **50 → 16 of 20, PASS** (max diff 207 → 176) |
| 2 | **GO** | `visual/edittext/edittext_border_transform` [output.06] | **43 → 15 of 20, PASS** (max diff 207 → 144) |

**Priced flips: +3 comparisons** (small_shear ×1 from patch 1; border_transform .04 and .06 from patch 2).
Whether `edittext_border_transform` flips at the TEST level depends on how the board counts it. All 6 of its
comparisons now pass locally, and .01/.02/.03/.05 are byte-identical to before.

Patch 2 is **not a band move**. It removes 68 % of .04 (34 of 50) and 65 % of .06 (28 of 43), and it puts both
rows under the limit with 4–5 outliers of headroom. Patch 1's margin is **one outlier** (49/50), as the w1
report predicted.

## Canary A/B, the full standing set plus my 3 appended members plus 3 device_transform extras

`render_canary.py compare before after`: **55 tests, 91 comparisons. 88 IDENTICAL (md5), 3 DIFFERS, 0 appeared,
0 vanished, 0 trace status changes.** The 3 DIFFERS are exactly the 3 intended flips above (fail → pass). Before is master
`835d9f539`; after is patches 1+2.

Other checks:
- A per-patch A/B over the three headline tests with patch 1 alone: small_shear flips. small_rotation (11/11, zero headroom),
  every border_transform comparison and leading_device_font are md5-identical. So patch 1 does **not**
  touch the transform.matrix-sheared clips of border_transform (their `(1,0.5,0,1)` recomposes bit-exactly).
- `edittext_device_transform_{basic,metrics,negative}` (added to my run as extras because they also set
  `transform.matrix`) are md5-identical.
- `edittext_border_transform .01–.03`, the s20 corner-rule canary, are md5-identical under both patches. They are
  device-font rows, so they take the other branch.

## Trace sweep for patch 1 (`--mode=graphics`, after both patches)

All PASS: avm1 `transform`, `as_transformed_flag`, `matrix`, `local_to_global`, `mouse_pos`,
`mouse_pos_with_scale_factor`, `hitarea_sweep`, `movieclip_state_values`, `movieclip_default_state`,
`nan_scale`; gnash `Transform-v5/v6/v7`; regression `avm1_display_prop_coercion`,
`avm1_parent_child_text` (image 0/0 too), `avm1_parent_child_modify_place`. `local_to_global` and
`Transform-v7` also PASS in no-graphics mode, so the header helper compiles in both builds.

Also run:
- `from_gnash/.../MovieClip-v8` (KF, baseline 1020/1087): 1020/1087. Actual output is **byte-identical**
  to master (a direct A/B with both patches reverted).
- Not graded: `avm1/movieclip_library_state_values` is in `ignored_tests.txt` (0/0), and gnash `Transform-v8`
  has only fp9/fp10 subtests (the runner skips it, the same as the baseline).

Why the patch is trace-inert: the non-render twin `getLocalMatrixForMC` has used the exact matrix since the
Transform-v8 work. Patch 1 brings the render twin (`getLocalMatrixForMC_render`: localToGlobal, _xmouse, the text
world matrix) and the GPU slot builder (`apply_as_transform`) onto the same rule.

## Mechanism

### Patch 1: exact matrix (attacking the premise)

The brief said to add trailing fields `mtx_exact_valid, mtx_a..d`. **They already exist** (`has_exact_matrix`,
`exact_m_a..d`, plus a scale/rotation/skew snapshot, `action.h:88`). The `transform.matrix` setter already fills them,
and `getLocalMatrixForMC` (the trace/getter path) already prefers them while the snapshot still matches. Only the
two RENDER paths still recomposed a/b/c/d from f32 `xscale/rotation/skew`: `getLocalMatrixForMC_render` and
`tag.c::apply_as_transform`, which used `cosf`, a second, float-precision recomposition.

The patch hoists the existing validity test into `static inline mc_exact_matrix_live()` in `action.h` and uses it
in all three places. No new state is added, and the invalidation rule is unchanged: any `_xscale/_yscale/_rotation`
setter that changes the snapshot falls back to recomposition.

Known remaining imprecision (pre-existing, not introduced here): writing `_xscale` to its *current* value keeps
the exact matrix. Ruffle would recompose. This has no corpus signal.

### Patch 2: border lines (attacking the premise)

**The golden was not made by `emulate_line_as_rect`.** In Ruffle wgpu, `draw_line_rect` calls
`emulate_line_rect` only when `backend == Dx12` (`render/wgpu/src/surface/commands.rs:566`). Every other backend
draws a native `LineStrip [0,1,2,3,0]` after `+HALF_PX`. The golden's diagonal profile confirms this: each row
carries ~1.0 px of ink (16/192/48 → 1/16+3/4+3/16). A 1-px-perpendicular rect at 45° carries √2 ≈ 1.41, which is
what the literal port gives. So I measured both on the GPU:

| model (both with Ruffle's `EditTextPixelSnapping` + HALF_PX) | .04 | .06 |
|---|---|---|
| before (local rects through the field slot) | 50, max 207 | 43, max 207 |
| literal Dx12 `emulate_line_as_rect` (1 px perpendicular) | 18, max 207 | 17, max 208 |
| **non-strict line: parallelogram, 1 device px along the MINOR axis (shipped)** | **16, max 176** | **15, max 144** |

The shipped model is the non-strict line (Vulkan's default line rasterisation). The literal port would also pass, but with only 2–3
outliers of headroom.

The shipped code adds `tf_border_skewed_line_rect`, which builds Ruffle's `draw_text_box` geometry in DEVICE px:
`world * create_box(w, h, x_min, y_min)`, then `EditTextPixelSnapping::apply` (high-quality arm:
`trunc(tx + 2 twips)`, and the `-0.35` scale-rounding when c/d or a/b is ~0). It then emits four segments through
`tf_border_line_segment`. That draws the unit square through one dynamic transform slot per segment, with
columns = the segment and the 1-px minor-axis step, origin = corner + HALF_PX − step/2.

The new path is **gated to non-axis-aligned matrices** (b or c nonzero AND a or d nonzero), embedded fonts only
(the `device_box` branch is untouched) and positive-dimension fields (`edge_x && edge_y`). Axis-aligned boxes,
including the 90°/180° rows of the same test, keep the old path and its measured 3/4 BR-corner rule.
Background drawing is unchanged.

**Residual (the next step if anyone wants .04/.06 to 0):** all 16/15 remaining outliers lie on the diamond's
two "/" edges, the ones perpendicular to the (+½, +½) HALF_PX offset. The golden's top vertex is symmetric
about x = 47.0, not 47.5. A probe sweep of the HALF_PX size (env-var, since removed) gave **0 outliers on
both comparisons at offset 0 or ¼ px**, but that makes the sheared boxes' axis-aligned edges worse (sum |diff|
5.4k → 9.4k), which want ½. This is the classic diamond-exit tie on exactly-45° lines, and a quad cannot model it
exactly. I did not ship the ¼-px fit: it is curve-fitting to one rotated box.

## Corner rule: what I learned for `visual/fonts/leading_device_font` (lead D2, not chased)

- **The two goldens do not disagree. They come from two different Ruffle painters, chosen by `is_device_font()`,
  not by the transform.** leading_device_font's fields set `embedFonts = false`, so Ruffle calls `draw_device_text_box`:
  four independent `draw_line` calls, and the BR corner is empty (the golden is 255 there, and the whole golden is
  binary 0/255). `edittext_border_transform` .04/.06 and `avm2/edittext_autosize_height_dynamic` set
  `embedFonts = true`, so Ruffle calls `draw_text_box`: the closed LineStrip, and the BR corner is partial (95 / 111).
- The mismatch is in our AVM2 painter. `avm2_display.c` ~18759–18780 applies the partial `corner_dev = dtw/2`
  corner **inside the `draw_device_text_box` arm**, and its comment says it was calibrated on
  `autosize_height_dynamic` and `edittext_selection_leading`. **Both of those set `embedFonts = true`** (Test.as:71
  and :44), i.e. both are draw_text_box goldens.
- Completion mechanism: check `et->device_font` for those two tests' fields. If it is 0, the device arm's
  corner rule is uncalibrated, and making it EMPTY (Ruffle's four half-open draw_lines) should clear all 6 px / 18
  channels of leading_device_font. If it is 1, `avm2_text_is_device_font` is wrong for embedded fields, which is a
  bigger bug. Either way, `autosize_height_dynamic` (a canary member) must stay green.
- leading_device_font is in the canary now (tier 2): 18 outliers, md5 `8b078ae3`, unchanged by both patches.

## Tests run

- `render_canary.py capture` before/after over 55 tests (`--jobs 2 --recompile --timeout 5400`), compare above.
  Canary `before` = master, `after` = patches 1+2. Per-patch header A/Bs are labelled `p1head`, `p2rect`, `p2para`,
  and `sw_*` (sweep).
- The 19 trace tests listed above, sequential, `--mode=graphics --recompile`; 2 in no-graphics mode.
- The recompiler was built in the worktree (`SWFRecomp/build`). Both patches are runtime-only.

## Canary additions (patch 1, appended at EOF of `render_canary_tests.txt`)

- tier 1: `visual/edittext/edittext_device_transform_small_rotation` (11/11, zero headroom; reads the render
  matrix through `tf_world_matrix`).
- tier 2: `visual/edittext/edittext_device_transform_small_shear` (the patch-1 row, 49/50 after the patch).
- tier 2: `visual/fonts/leading_device_font` (D2 corner row).

## New unclaimed leads

1. **D2 corner rule (above):** `avm2_render_textbox`'s device arm carries a corner rule calibrated on
   embedded-font goldens. Priced at 6 px / 18 channels, the whole residual of `leading_device_font` (max_outliers 0).
2. **45° LineStrip tie**, the 16/15 residual of border_transform .04/.06. It is only worth it if a second rotated-box row
   appears; today both rows pass.
3. **Other render paths still recompose from xscale/rotation**, ignoring an exact matrix: mask geometry
   (`action.c` ~14549/14640), `_width/_height` (~31467/31529/31584), and the drawing-bounds walks (~73395,
   ~73534 macro). None has a corpus signal today. They are the same precision class as small_shear, and would be fixed by
   calling `mc_exact_matrix_live()` there.
4. `_xscale = <current value>` should drop the exact matrix (Ruffle recomposes on any scale/rotation set).
   Untested edge case, no corpus signal.
