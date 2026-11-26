# Flash fixes: Ruffle goldens corrected to real Flash Player output

The upstream mirrors (`tests/swfs/avm1`, `avm2`, `from_*`, `visual`, …) are re-downloaded from Ruffle on every CI run
and are not git-tracked. Some of their goldens are not what Flash produces: Ruffle rendered them, or they come from a
host we can't reproduce. **The project matches Flash, not Ruffle** (user rulings 2026-09-29 and 2026-11-24). So when a
real Flash Player 32 capture proves a golden wrong, the corrected file is stored here and re-applied after every
download.

- **Where:** `flash_fixes/<suite>/<test>/<file>` + one manifest entry in `fixes.json`.
- **When:** `download_tests.sh` runs `apply_flash_fixes.py` at its end, for the categories it just downloaded. CI
  therefore applies the fixes on every run. Locally: `python3 ruffle-tests/apply_flash_fixes.py [--check]`.
- **What happens:** the downloaded original is kept next to the fixed file as `<file>.upstream`. `verify_output.py`
  never serves `.upstream` files as data.
- **Safety:** each entry records the sha256 of the upstream file it corrects. If upstream changes that file, the fix
  is NOT applied and the entry prints `STALE`; re-check the new golden against Flash. If upstream ships our fix byte
  for byte, it prints `UPSTREAMED`; delete the entry.

## Rules for adding an entry

1. **The evidence is a real Flash Player 32 capture** (`tools/flash-oracle/`), never a Ruffle render and never our own
   output.
   - It must be reproducible: Linux == Windows, or the capture mode documented (AVM1 direct pinned; `--screen` for
     non-LAYER blends; quality as the test runs).
   - Archive the capture under `SWFRecompDocs/plans/…` and name it in `evidence`.
2. **Write the RvF entry** in `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`, with test,
   evidence, pixel or line deltas, and the date. Every Ruffle≠Flash difference we find is documented there, whether or
   not it gets a fix here.
3. **Grade the move by name in the next CI run.** A swap changes what the row is graded against. A row can go
   pass → fail when it only ever matched Ruffle; that is the honest residual (Flash over Ruffle), not a regression.
4. **Fix only what Flash proves.** Platform- or host-dependent goldens (device fonts, ClearType text) stay as they
   are. Give them a disposition instead.

## Entries

| test | file | added | evidence | effect when added |
|---|---|---|---|---|
| `visual/simple_shapes/strokes/scale` | `output.expected.png` | 2026-11-24 | s27 golden-provenance r2 goal 4 (LNX == WIN == root) | fails either way; residual vs Flash 7797 px |
| `avm2/graphics_draw_path` | `output.expected.png` | 2026-11-24 | same (LNX == WIN; wrapper, AVM2 low quality) | fails either way; 387 px vs Flash |
| `avm2/bitmapdata_opaque` | `output.expected.png` | 2026-11-24 | same (LNX == WIN) | fails either way; 4 channels vs Flash at tol 0 |
| `avm2/blend_scroll` | `output.expected.png` | 2026-11-24 | same (LNX == WIN) | fails either way; 195 px vs Flash |
| `visual/definefont4` | `output.expected.png` | 2026-11-24 | same (LNX == WIN; embedded DefineFont4) | fails either way; we are closer to Flash (5325) than the old golden was (6331) |
| `avm1/goto_rewind_movieclip_replace` | `output.txt` | 2026-11-25 | s28 trace-provenance (LNX pinned ×2 == no-pin == WIN) | expected `ruffle_matched` → pass (ours == FP32) |
| `avm1/movieclip_hittest_shapeflag` | `output.txt` | 2026-11-25 | same | stays `output_mismatch`; 9 lines vs Flash |
| `from_gnash/misc-ming.all/loop/simple_loop_test` | `frame{1,2,3,5,6,7}.expected.png` | 2026-11-25 | s28 snap-pixel-audit (draw, quality low, LNX == WIN) | 6 × fail → pass (ours == FP32, 0 channels) |
| 33 quality=low image rows (28 tests: 6 avm2, `morph_test1` ×6, 14 `blend_modes`, `cache_as_bitmap/{drawing_api,nested_rotation}`, `gradient_focal_point`, `color_matrix`, `fonts/glyph`, `gradients/focal_radial`, `simple_shapes/layers`) | `*.expected.png` | 2026-11-25 | s28 lowq-recapture: FP32 `--quality low` (LNX ×2 deterministic, WIN == LNX in tol; 4 non-LAYER blends from `--screen`) | **land only together with the w2-lowq-sample-point model.** Without it every row fails vs Flash; with it all fail except `focal_radial` (PASS). Report: `SWFRecompDocs/plans/session28-fanout-reports/lowq-recapture-report.md` §6 |

**Graded** in run `45547012629` at `7c3cfdcb7` (results `e1425f417`) vs `cb14cd063`: 0 status moves in either axis.
Excess channels vs the new Flash goldens:
- `blend_scroll` 296 → 391
- `strokes/scale` 19 287 → 23 391
- `graphics_draw_path` 664 → 704
- `definefont4` 16 086 → 15 975 (closer)
- `bitmapdata_opaque` unchanged

That is the honest residual against Flash.
