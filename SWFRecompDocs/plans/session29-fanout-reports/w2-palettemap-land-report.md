# s29 w2-palettemap-land: land AVM2 `BitmapData.paletteMap` (from w1-drift)

**New files:**
- `SWFRecompDocs/plans/session29-fanout-reports/w2-palettemap-land-report.md` (this file)
- `SWFRecompDocs/plans/session29-fanout-reports/w2-palettemap-land.patch` (source + fixture; `git apply --check -R` OK on the branch)
- `ruffle-tests/tests/swfs/regression/avm2_bitmapdata_palettemap_index/{Test.as,build.sh,test.swf,test.toml,output.txt}`

**Edited (on the branch, not in the patch; docs):** `ruffle-tests/tests/swfs/regression/README.md` (one row appended),
`ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` (one entry appended at EOF),
`ruffle-tests/tests/swfs/avm1/_investigation/CURRENT_STATUS.md` (stale paletteMap lines ~214 / ~360).

**Patch scope:** `SWFModernRuntime/src/avm2/avm2_bitmap.c` only (= `w1-drift-prototype.patch`, applied unchanged) plus the
new fixture dir. Functions touched: `bd_palette_map` (new, `static`, placed after `bd_copy_channel`), the `BD_MUTATOR`
list (`BD_MUTATOR(bd_palette_map)`), and the `paletteMap` line in `avm2_register_bitmap` (`bd_noop__mut` →
`bd_palette_map__mut`). No file the sibling ladders touch (`tag.c` / `action.c` / `ng_shared.c` / `swf.c` /
`render_webgpu.c`) is edited, and there is no recompiler change.

**Box:** `SETUP_STATUS` all OK (apt, Pillow, Dawn on lavapipe). Code at `origin/master` (`git checkout -B
fanout/w2-palettemap-land origin/master`). Downloaded `avm1 avm2` from upstream Ruffle master **`b7ff32d93`**
(flash-fixes applied as `download_tests.sh` does).

## Verdict: GO, +2 trace rows (both new rows), 0 other movement

## Per-test before / after (same box, clean origin/master vs patch)

| test | mode | before | after |
|---|---|---|---|
| `avm2/bitmapdata_palettemap_opaque` | graphics | MISMATCH (7/9 lines differ: every case reads `0xFF000000`) | **PASS** |
| `avm2/bitmapdata_palettemap_opaque` | no-graphics | (same no-op code path) | **PASS** |
| `regression/avm2_bitmapdata_palettemap_index` (new) | graphics | MISMATCH (4/5 lines: all `0xFF000000`) | **PASS** |
| `regression/avm2_bitmapdata_palettemap_index` (new) | no-graphics | (same no-op code path) | **PASS** |
| `avm1/bitmapdata_palettemap_values` | graphics | PASS | PASS (AVM1 arm untouched) |
| `avm1/bitmap_data_thorough/paletteMap` | graphics | PASS | PASS |
| `avm1/bitmap_data` | graphics | – | PASS |
| `avm2/all_classes/display/swf9` | graphics | – | PASS |
| `regression/avm2_bitmapdata_draw_filtered` | graphics | – | PASS |
| `regression/avm2_bitmapdata_draw_edittext_box` | graphics | – | PASS |

The "before" A/B leg was checked to be genuine: with the patch reversed, the headline row re-MISMATCHes (the build is
ccache content-keyed, so the second leg's speed was cache hits, not a stale binary).

## Regression suite and canary

- **Render canary, A/B, md5:** every `avm2/*` and `regression/*` member of `render_canary_tests.txt` (94 tests, 94
  PNGs): **IDENTICAL 94, DIFFERS 0**, no trace or image status changes. The AVM1 / visual / shumway / gnash / fonts /
  text members were not run. The change is an AVM2-only native method body, and no SWF calls it outside the two
  headline rows: I string-scanned the decompressed `avm2` + `regression` SWFs for `paletteMap` and found only
  `avm2/bitmapdata_palettemap_opaque` and the new fixture. w1-drift's scan of `avm1 avm2 from_gnash visual
  from_shumway mixed_avm` found only AVM1 callers on the untouched arm. No canary member is appended: no pixel row
  calls the method.
- **Regression suite:** the 59 canary `regression/*` members (trace status unchanged), the two
  `avm2_bitmapdata_draw_*` rows, and the new fixture (PASS, both modes).

## EXPECTED-FLIP LEDGER (coordinator: check CI against this)

| test | axis | expected |
|---|---|---|
| `avm2/bitmapdata_palettemap_opaque` | trace | new row → **pass** (before the patch it is new → output_mismatch) |
| `regression/avm2_bitmapdata_palettemap_index` | trace | new row → **pass** |
| (any) | pixels | **no movement** (no image row calls paletteMap) |
| everything else | both | no movement |

`avm1/bitmapdata_palettemap_values` (new upstream row) passes with and without the patch, so it is new → pass from
drift, not from this patch. Mode parity: both ledger rows pass under no-graphics. `categories=all` graphics is enough,
because there is no recompiler emission change.

## Oracle provenance

- `avm2/bitmapdata_palettemap_opaque` golden = FP32 byte-identical (coordinator, `w1-local-oracles/w1-drift/README.md`).
- Fixture golden = `w1-local-oracles/w1-drift/palettemap_avm2_index.fp32.txt` exactly (5 lines, LNX FP32 32,0,0,465).
  `test.swf` = the coordinator-built SWF from the same dir (`build.sh`: Flex mxmlc, `-target-player=11.1`). It is not
  rebuildable in the cloud.
- `test.toml` = `num_frames = 1` plus a comment header naming the Flash provenance (the
  `avm2_bitmapdata_draw_filtered` convention).

## Docs

- **RvF (EOF):** "AVM2 `BitmapData.paletteMap` reads `arr[i]`; Ruffle reads `arr[i-1]`". The entry cites Ruffle
  `array_object.rs` `get_enumerant_value` `checked_sub(1)` and quotes the FP32 capture lines with Ruffle's predicted
  values. The Ruffle source claim comes from w1-drift's reading (it was not re-read here: no Ruffle clone). The FP32
  values confirm `arr[i]` directly.
- **CURRENT_STATUS.md:** the 2026-04-18 "ruffle_matched … mask `& 0xFF`" bullet is annotated as superseded (mask
  dropped for FP32, row passes 951/951, upstream removed `known_failure`). In the bitmap_data_thorough table, paletteMap
  moves to PASS (16→17, rm 3→2).
- **regression/README.md:** row appended for the new fixture.

## Refutations / attacks on my own pricing

- "The fast before leg might be stale": refuted (above).
- "The canary subset is too narrow": the change cannot reach a non-caller. The method name was already registered (only
  the function pointer changed), so describeType / `all_classes` output is unchanged; `all_classes/display/swf9` passes.

## Not finished

Nothing. The AVM1 / non-AVM2 canary members were not run, by argument (above). If the coordinator wants them anyway,
the completion mechanism is `render_canary.py capture` over the full list, or the CI graphics run itself.

## New unclaimed leads

None beyond w1-drift's: `merge` / `perlinNoise` are still `bd_noop__mut` in AVM2.

## LOCAL ORACLE REQUESTS

none
