# w2-bitmapdata: slice BD (copyPixels blend/self/alpha rules) + `bitmapdata_custom_rectangle` rider

Read `BRIEFS_COMMON.md` (wave-2 section included), then `w1-drift-report.md` slice BD and its
`bitmapdata_custom_rectangle` item. That report is your diagnosis of record and it is unusually
well evidenced (a replay of the test's own 1024 curated table lines through our `premul()` +
`FLASH_PREMUL_FACTOR` LUT scores 1024/1024 with the new formula vs 188/256 with the old). Re-verify
the ledger yourself anyway. Worktree agent: nothing commits, you deliver a patch.

## Scope (+4 effective, +1 more with the rider)
**Slice BD** (`SWFModernRuntime/src/actionmodern/avm2_bitmap.c` + `actionmodern/action.c`, ~100 LOC):
1. Ruffle's Flash-verified `blend_over`: `src + ((dst * (256 - sa)) >> 8)`, where we still use `/255`.
2. The self-copy direction rule: `reverse = dx >= 0 && dy >= 0`.
3. A 2-line alpha-rule fix.

Priced flips: `avm2/bitmapdata_copypixels_blend` 0/1029 → pass, `avm2/bitmapdata_copypixels_self`
571/612 → pass, `avm1/bitmapdata_copypixels_self` 600/612 → pass,
`avm2/bitmapdata_copypixels_alpha_merge` 5/9 → 9/9 pass. That last one is the test upstream moved
today (it is `output_mismatch` now, so an exact pass is the only target).

**Rider, take it only if BD is done and verified**: `avm1/bitmapdata_custom_rectangle` →
`ruffle_matched` (+1, medium). Built-in `getColorBoundsRect` must construct via the
dynamically-resolved `flash.geom.Rectangle`; an exact `pass` would also need `generateFilterRect`,
which is out of scope.

## Required checks — this is a shared-formula change, so the sweep IS the work
`blend_over` and the premultiply LUT are used far beyond these four tests. Before delivering:
- every `bitmapdata*` test in `avm1` and `avm2` (there are many; run them, sequentially);
- the filter tests that composite through the same path (`avm2/bitmapdata_applyfilter*`,
  `avm2/bitmapdata_draw*`);
- the `regression` suite members that touch bitmaps, including `regression/bitmap_pool_layer_cap`;
- the render canary (`render_canary.py`), because a blend-formula change is exactly the class of
  edit the pixel axis sees. Report every DIFFERS row with its channel stats, and say for each
  whether it is intended. A change that fixes trace rows while silently moving pixels is not done.

Report per-test before/after for everything you ran, not only the four headline rows.

Siblings and their files: **w2-loaders** (`avm2_display.c`, `swf_core.c`), **w2-avm2-json** (JSON
parse + AVM2 stack frames + integral-number conversion — it may also touch `action.c`),
**w2-avm2-smalls** (AVM2 class registration, ByteArray predicate). `action.c` is ~50K lines, so
textual overlap is unlikely, but say in your final message exactly which functions you touched there.
