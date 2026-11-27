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
| `visual/simple_shapes/gradients/{gradients,reflect,repeat}`, `visual/opaque_background` | `output.expected.png` | 2026-11-25 | s28 lowq-corner-rule (same FP32 LOW captures; LNX == WIN exact) | **land with the lowq model** (`lowq-final.patch`). Ours vs Flash: master → model 5 874 → 3, 645 528 → 5 628, 649 083 → 5 628, 3 474 → 1 956 channels; all still fail (gradients by 3). Report: `SWFRecompDocs/plans/session28-fanout-reports/lowq-corner-rule-report.md` |
| `avm2/dependent_strings`, `avm2/loader_applicationDomain`, `avm2/swz` | `output.txt` | 2026-11-26 | s28 trace-provenance `avm2__{dependent_strings,loader_applicationDomain,swz}.r1.txt` (Linux == Windows) | **land with the s29 w2-disposition-land patch** (URLRequest.digest → securityError #2046). `dependent_strings` mm → pass (no code); `loader_applicationDomain` mm → pass (0/3 without the patch); `swz` stays mm (1/3: missing `[file:line]` stack suffixes) |
| `from_shumway/invalidClipDepth`, `from_shumway/acid/acid-filter` | `output.expected.png` | 2026-11-26 | s28 lowq-corner-rule LNX FP32 LOW + s29 coordinator WIN FP32 LOW (WIN == LNX exact) | invalidClipDepth expected fail → pass (ours == FP32); acid-filter stays fail (104 vs Flash) |
| `visual/simple_shapes/text_field_mask` | `output.expected.png` | 2026-11-26 | s29 coordinator FP32 LOW (LNX == WIN byte for byte; `session29-fanout-reports/w1-local-oracles/w1-pixel-flash-gaps/`) | **land with w2-pixel-gaps-land prototype A** (LOW glyph pen → whole device px). Golden (Ruffle) is 2 378 ch from Flash. Ours vs Flash: master 2 404 → A 1 336 ch; fails either way |
| `from_shumway/gradientTransform` | `output.expected.png` | 2026-11-26 | same dir: FP32 LOW (LNX == WIN byte for byte); FP32 HIGH == upstream golden exactly | golden was Flash HIGH on a quality=low row. Ours vs Flash LOW: 3 ch over tol 3 (max 21), was 6 over vs the HIGH golden; fails either way |
| 15 `from_avmplus/ecma3/Date/e15_9_5_*` (`4`, `10`, `10_1`, `10_10`, `10_11`, `11`, `12`, `12_1`, `13`, `15_1`, `17_1`, `22_1`, `28_1`, `29_1`, `35_1`) | `test.toml` (`kind: "toml"`) | 2026-11-26 | s28 trace-provenance (goldens are FP32, US-Pacific host) + s29 coordinator Linux FP32 of `35_1` under `TZ=PST8PDT,M3.2.0,M11.1.0` == golden | adds `mock_timezone` (+ `mock_date_time` = printed capture instant). With s29 per-timestamp DST: 15 × `ruffle_matched` → pass (6 of them pass on `mock_date_time` alone) |
| `avm2/try_catch_typed` | `output.txt` | 2026-11-26 | s29 coordinator FP32 (`w1-local-oracles/w1-rm-avm2/try_catch_typed.fp32.txt`) | `[file:line]` suffixes; stays pass with the s29 debug-line info (fails without it) |
| `avm2/slot_holes_fail`, `avm2/slot_id_exceeds_trait_count` | `output.txt` | 2026-11-26 | s28 trace-provenance `avm2__slot_*.r1.txt` | empty golden → FP32 VerifyError #1107 (+ #1065); stay `ruffle_matched` (O3 not implemented) |

**Graded** in run `45547012629` at `7c3cfdcb7` (results `e1425f417`) vs `cb14cd063`: 0 status moves in either axis.
Excess channels vs the new Flash goldens:
- `blend_scroll` 296 → 391
- `strokes/scale` 19 287 → 23 391
- `graphics_draw_path` 664 → 704
- `definefont4` 16 086 → 15 975 (closer)
- `bitmapdata_opaque` unchanged

That is the honest residual against Flash.
