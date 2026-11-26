# w1-drift local oracle results (s29 coordinator, 2026-11-26, FP32 LNX 32,0,0,465, direct pinned)

| request | result |
|---|---|
| 1. `avm2/bitmapdata_palettemap_opaque` | BYTE-IDENTICAL to `output.txt` → golden = Flash |
| 2. `avm1/bitmapdata_palettemap_values` | BYTE-IDENTICAL to `output.txt` → golden = Flash |
| 3. `palettemap_avm2_index` fixture (built with `-target-player=11.1 -omit-trace-statements=false`) | `arr[i]` column: `0xFF102030`, `0xFFAA0000`, `0x80102030`, `0xFF102030`, `Done` → Flash reads `arr[i]`; Ruffle's AVM2 arm reads `arr[i-1]` (RvF) |

Fixture 3 golden: `palettemap_avm2_index.fp32.txt` (5 lines; note `transparent half` reads back `0x80102030`, an exact round trip).
