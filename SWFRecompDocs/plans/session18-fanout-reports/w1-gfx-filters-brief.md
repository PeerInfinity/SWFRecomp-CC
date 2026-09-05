# w1-gfx-filters — wave 1 diagnosis: pixel cluster filters (`diffuse_mixed` × Filters, halo, cab_mask_filters)

Read `BRIEFS_COMMON.md` first. Read-only: no source edits. Deliverable:
`SWFRecompDocs/plans/session18-fanout-reports/w1-gfx-filters-report.md`. Scratch dir: `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/w1-gfx-filters/`.

Board: `wave0-image-board.md` + `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/image_triage.json` (PNG paths under
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/image-results/`). Method: `graphics-fanout-playbook.md` §2–§7, §16. Prior
filters diagnosis of record — READ FIRST, do not re-derive: `session16-fanout-reports/w2-gfx-filters-report.md`
(cut 1), `session17-fanout-reports/w2-gfx-filters-cut2-report.md` (cut 2, displacement),
`w2-gfx-cab-mask-stencil-report.md` (cab_mask_filters = "cut 3(b)": filters on a masker).

## Your comparisons
- `visual/cache_as_bitmap/cab_mask_filters` 612 (80x40, max_out 0) — cut 3(b)
- `visual/filters/displacement_map` 20749 (max_out 160) — s17: residual is `TestImage` sub-pixel placement, NOT displacement (its no-map control tile is 2956 before/after) — verify
- `visual/filters/glow` 24992, `glow_without_composite_source` 24919
- `visual/filters/drop_shadow` 46032, `drop_shadow_angles` 55899
- `visual/filters/bevel_inner` 48134 (max_out 18), `bevel_full` 66782, `bevel` 69229 (max_out 6), `bevel_outer` 78376
- `visual/filters/blur_size_grows` 86708 (max_diff 213)
- `visual/filters/any_blur_scales_with_screen` 4884 (halo_penumbra, 160x160)
- `visual/filters/blur_scales_with_screen` 30810 is w1-gfx-fill's; `bitmapdata_applyfilter_*` are theirs too.
- `visual/edittext/edittext_border_filters` 827 (max_out 17) — shared with w1-gfx-text; you own the FILTER half

The glow/drop_shadow/bevel family is 8 comparisons that likely share ONE or TWO mechanisms
(kernel shape? colour/alpha premultiply? `strength` semantics? `knockout`/`inner` compositing?
blur pass count = `quality`?). Ruffle's reference: `~/CC/ruffle/render/wgpu/src/filters/`
and `render/src/filters.rs`; ours: `SWFModernRuntime/src/.../render_webgpu.c` filter shaders +
`avm2_filters.c`. Diff the two algorithms on paper before touching pixels.

## Method
Open expected/actual/diff PNGs, name the mechanism per test, cluster, price flips honestly
(outliers must reach <= max_out; the filters family has large canvases so many rows will only
move bands — say so), verdict GO/HOLD/NO-GO with files + LOC + canaries
(`render_canary_tests.txt` has filter members). Local A/B renders: one test at a time,
`--mode=graphics --images --image-out-dir`. Attack the brief. Siblings: w1-gfx-fill,
w1-gfx-text, w1-gfx-smalls.
