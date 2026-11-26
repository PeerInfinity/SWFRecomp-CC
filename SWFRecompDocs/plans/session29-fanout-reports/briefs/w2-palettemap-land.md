**Land AVM2 `BitmapData.paletteMap` (from w1-drift; S).**

Read `session29-fanout-reports/w1-drift-report.md` and apply `w1-drift-prototype.patch` (`avm2_bitmap.c::bd_palette_map`).
FP32 results (coordinator, `session29-fanout-reports/w1-local-oracles/w1-drift/README.md`): both new corpus goldens
(`avm2/bitmapdata_palettemap_opaque`, `avm1/bitmapdata_palettemap_values`) are byte-identical to FP32, and **Flash reads
`arr[i]`** (your prototype), not Ruffle's `arr[i-1]`.
1. Apply the prototype; confirm `avm2/bitmapdata_palettemap_opaque` passes (graphics) and the w1-drift unchanged set stays.
2. Add fixture `ruffle-tests/tests/swfs/regression/avm2_bitmapdata_palettemap_index/` from
   `w1-local-oracles/w1-drift/palettemap_avm2_index/` (`Test.as`, `test.swf` as built, `test.toml` = regression-suite
   conventions — read `regression/README.md`), golden `output.txt` = `palettemap_avm2_index.fp32.txt` exactly. It must
   pass with the patch. Append its README row.
3. RvF entry (append at EOF): Ruffle's AVM2 paletteMap reads `arr[i-1]` (`array_object.rs` enumerant offset); FP32 reads
   `arr[i]`; evidence = the fixture capture.
4. Update `ruffle-tests/tests/swfs/avm1/_investigation/CURRENT_STATUS.md` lines ~214/~360 (stale "rm, mask `& 0xFF`"
   for `bitmap_data_thorough/paletteMap`: it passes; the mask was dropped for FP32).
Ledger: `avm2/bitmapdata_palettemap_opaque` new → pass; `regression/avm2_bitmapdata_palettemap_index` new → pass; nothing
else moves. No-graphics check on the two rows too (shared runtime code).
