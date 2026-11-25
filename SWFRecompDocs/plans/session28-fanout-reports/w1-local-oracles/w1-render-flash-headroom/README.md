# w1-render-flash-headroom local Flash oracles (s28 coordinator, 2026-11-25; FP32 LNX)

Fixtures: built locally by the slot's `make_fixtures.py` / `make_gt_offsets.py` (header-byte / header-RECT patches of
corpus SWFs; not committed).

## #1 Occupied-depth rule vs SWF version (trace, direct pinned)

| fixture | Flash 32 |
|---|---|
| `place_object_test_v5` (corpus = v5) | `#passed: 7 #failed: 0` — Flash keeps both objects |
| `place_object_test_v6/v7/v8/v10` | `#passed: 3 #failed: 4` — Flash refuses the newcomer like us/Ruffle |
| `placeobject_occupied_depth_v6/v7/v8/v15` | 4 lines, `Instantiated ID 3` once (refusal) |
| `placeobject_occupied_depth_v5` | 0 lines (script doesn't run as SWF 5) — no verdict |

**Rule: keep-both (newcomer behind) is SWF 5 only.** Flash never prints `Warning: Failed to place object …` (that is a
Ruffle log line; it appears in the `output.ruffle.txt` files). `from_gnash/misc-ming.all/place_object_test2` (SWF 6):
FP32 == `output.txt` exactly. `path_format_test` (SWF 6): FP32 == `output.txt` + one extra line 22 (`Parameters of
primitive types are no longer coerced into the required type - Object.`). Both rows are `ruffle_matched` today only
because we print the Ruffle warning line; dropping it gives place_object_test2 a pass.

## #2 Edge snap at HIGH (image, quality high, 1 tick)

`gradientTransform_off{0,5,10,13,15}` (root RECT xmin = ymin = −off twips): **all five captures are pixel-identical**,
both in `draw()` wrapper mode (`*.high.png`) and direct pinned (`*.direct-pinned.high.png`; the pinned run is a
replaced `_level0`, whose RECT origin offset Flash may not apply at all). The rings are hard at every offset. The corpus
SWF at HIGH via `draw()` == the golden exactly (0 / 0). So Flash does not render a sub-pixel root-RECT offset
(rounded or ignored); the per-offset AA question is unanswerable with this harness (`--no-pin` would show-all-scale a
101 px stage). Direct-pinned is 1 px left of draw() at the right/bottom ring (372 px / max 39 vs the golden).
