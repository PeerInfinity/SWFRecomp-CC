# w2-gradient-readback: report (session 21, wave 2)

New files: none. The patch touches one tracked file, `SWFModernRuntime/src/avm2/avm2_filters.c` (+52/−8).
Patch: `w2-gradient-readback.patch`. Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a963dab1ef7f92165` (base `92adceb68`).

## Verdict: GO, +1 effective (`avm2/gradient_values_readback` goes from MISMATCH to RUFFLE_MATCHED)

| test | before | after |
|---|---|---|
| `avm2/gradient_values_readback` (new upstream, KF) | MISMATCH (ungraded in CI) | **RUFFLE_MATCHED**. Our actual output is byte-identical to `output.ruffle.txt` at `0dacba55f`. |

`known_failure = true`. This is not a pass→ruffle_matched regression: the test arrived failing.

## Mechanism: four fixes in `avm2_filters.c`, all ported from Ruffle `cb2b60ff5` and `11624b551`

1. **Ratios.** Ratios are now read with `coerce_to_i32`, then clamped to 0..255, so negative ratios read back as `0`. They used to read back as `255` because of u32 wrapping.
2. **Array lengths.** The entry count is now `min(colors, ratios)`. A short `alphas` array is padded with `1.0`, and a hole inside the alphas length still reads `0`. Before, all three arrays were truncated to the shortest one.
3. **Quality.** The script-object path now uses a new `passes_of_i32`: i32 clamped to 0..15. A negative quality now reads back as `0`; before, it read back as `15`. Ruffle's commit made this change for **every** filter class (bevel, blur, drop shadow, glow, gradient), and I followed it. The SWF-tag path (`passes_of(tag->quality)`) is unchanged.
4. **Null `type`.** The `type` setter on `GradientBevelFilter` and `GradientGlowFilter` now throws `TypeError #2007: Parameter type must be non-null.`, through a new `f_set_type_gradient`. The constructor pushes a `flash.filters::<Class>/set type` frame before throwing, so the trace matches the expected output: `set type()` above `<Class>()`. The plain `BevelFilter` is unchanged: a null type still maps to `full`, as in Ruffle.

## Lines that deliberately stay as Ruffle's (12 lines, the remaining diff against Flash's `output.txt`)

- **Angle, 10 lines:** 58, 67, 76, 85, 100, 164, 173, 182, 191 and 206. Flash prints `angle: 45`; we and Ruffle print `44.999253346524966` (the Fixed16 round trip). **The angle rounding was not touched.** Five passing tests expect the rounded value: `avm2/bevel_filter`, `gradient_glow_filter`, `drop_shadow_filter`, `gradient_bevel_filter` and `avm1/bitmap_filters`.
- **Strength, 2 lines:** 106 and 212 (`strength huge`, 1e10). Flash prints `0`; we and Ruffle print `127.99609375` (Fixed8 saturation). This was left as Ruffle's too. Matching Flash here would need its wrap-to-0 semantics for Fixed8 overflow, and nothing in the corpus tests that beyond this line.

Both kinds are a subset of Ruffle's own diff, which the verifier requires for `ruffle_matched` (`verify_output.py:4588`).

## Canary (graphics mode, sequential, `--recompile`, worktree copies)

The patched build passes on the trace axis for every row below, and all of them were `pass` in the graphics baseline:
`avm2/{gradient_bevel_filter, gradient_glow_filter, bevel_filter, drop_shadow_filter, glow_filter, blur_filter, displayobject_filters, filters_array_holes, bitmapdata_applyfilter_blur, bitmapdata_applyfilter_destpoint_edges, bitmapdata_filter_sourcerect, edittext_autosize_lazy_bounds_props}`, `avm1/bitmap_filters`, `regression/avm2_timeline_gradients` (its image passes too), `visual/cache_as_bitmap/cab_mask_filters` and `visual/filters/blur_quality` (its image passes too).

Three image comparisons failed locally: `bitmapdata_applyfilter_blur`, `bitmapdata_applyfilter_destpoint_edges` and `cab_mask_filters` (612 outliers). These were never graded against the baseline, and the brief says not to grade a local render against a golden PNG. I believe they are not caused by this patch, but I did not run an unpatched A/B. The reason: the patch changes rendering only for gradient-filter records (a short alphas array or negative ratios) and for a negative `quality` set from script. A grep of every `.as` source in the corpus finds no rendered visual or shumway test that uses GradientGlow/GradientBevel or a negative filter quality. So the render canary cannot see this change, and it does not need a new member. The `avm2_display.c` filters render route (sibling w2-filters-snap) was not touched.

## Refutations and notes

- The w1 pricing holds exactly: 4 mechanisms, target `ruffle_matched`, and a Flash `pass` is unreachable without breaking the 5 angle tests.
- The comment in `SWFRecompDocs/plans/filters-arc.md:41` ("quality: `coerce_to_u32.clamp(0,15)`") is now stale. It is a doc, so I left it alone; the coordinator may want to update it to `coerce_to_i32`.
- I did not need an exporter rebuild: the `output.ruffle.txt` shipped at `0dacba55f` already reflects `11624b551`.

## New unclaimed leads

- None found. The strength wrap-to-0 on Fixed8 overflow is the only Flash-vs-Ruffle gap left in this test, and it is not worth a slot (it could only move this test to `pass`, and the angle lines rule that out anyway).
