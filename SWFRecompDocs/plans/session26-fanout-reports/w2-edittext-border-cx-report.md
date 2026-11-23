# s26 wave 2: `w2-edittext-border-cx` report

**New files** (all in this commit):
- `SWFRecompDocs/plans/session26-fanout-reports/w2-edittext-border-cx-report.md` (this report)
- `SWFRecompDocs/plans/session26-fanout-reports/w2-edittext-border-cx.patch` (the deliverable; `git apply --check -R` verified)
- `ruffle-tests/tests/swfs/regression/avm1_edittext_placed_cxform/{create_test_swf.py,test.swf,test.toml,output.txt,output.expected.png}`.
  This is the held fixture from `w2-held-fixtures/`. `output.expected.png` is the Ruffle exporter `0ddd12b6a` render
  (`output.ruffle-0ddd12b6a.png`, byte-copied). Its `test.toml` budget is `tolerance = 2, max_outliers = 19`; see §1.
  The `create_test_swf.py` docstring tail was updated. Regenerating the fixture reproduces `test.swf` and the twin
  `regression/avm1_edittext_placed_cxform_script/test.swf` byte-identically (twin md5 `59ba6aea…` before and after).

Source touched: **one function**, `SWFModernRuntime/src/libswf/tag.c::textfield_glyph_render_cb` (the
`par_x_offset` centring line). Nothing in `render_attached_child`, `action.c`, TextFieldGlyphInfo builders,
`render_webgpu.c`, `swf_core.c`, `tag_stubs.c` or `SWFRecomp/`.

Box: cloud, `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Base `origin/master` = `73915f55`. Corpus downloaded
from upstream Ruffle master at session time. My blobless Ruffle clone is at **`3e98d9ba6`**.

## Verdicts

| item | verdict | flips |
|---|---|---|
| EditText border corners under a cx | **REFUTED: no runtime bug.** The 9 px are the oracle machine's line rasterizer, not the cx path. | 0 |
| Land `avm1_edittext_placed_cxform` with exporter golden | **GO, landed.** `max_outliers = 19` budgets exactly the 19 artifact channels. | new row, passes |
| acid-color-0 step 4 (integer-twip centring) | **GO, landed.** Swept clean. | 0 (band 314 → 308) |
| acid-color-0 step 3 (premultiplied timeline-bitmap sampling) | **NO-GO in this slot.** Priced, not built. | 0 (stand-in 314 → ~116; acid never flips) |

## 1. The border corner is not a cx bug (refutation of the brief's premise)

Our after-render compared with the exporter golden: every differing pixel is a border corner, and it is always the
**top-left, top-right or bottom-left** one:

| box | corner | ours | Ruffle exporter | reading |
|---|---|---|---|---|
| s1 (10,10)–(80,65) | TL (10,10) | (0,255,0) | (0,255,64) | 3/4 border over the (0,255,255) bg |
| | TR (80,10) | (0,255,0) | (64,255,64) | 3/4 border over the white stage |
| | BL (10,65) | (0,255,0) | (64,255,64) | 3/4 over white |
| | **BR (80,65)** | **(64,255,64)** | **(64,255,64)** | identical |
| f2 (90,10)–(160,65) | TL / TR / BL | (0,0,128) ×3 | (64,0,128) / (64,64,160) / (64,64,160) | 3/4 |
| | BR | (64,64,160) | (64,64,160) | identical |
| s3 (10,80)–(80,135) | TL / TR / BL | (0,128,0) ×3 | (64,128,0) / (64,160,64) / (64,160,64) | 3/4 |
| | BR | (64,160,64) | (64,160,64) | identical |

The partial pixels blend with the white stage or the field's own background. They do not blend with black, so the
brief's "blends with the black background through the cx" reading is wrong. **The exporter inks all four corners at
exactly 3/4.** That is the geometric signature of Ruffle's `emulate_line_rect` (`render/src/lines.rs`): four 1-px
rects from one corner pixel's centre to the next, so every corner gets one half from each adjoining side. wgpu takes
that path **only when `descriptors.backend == Backend::Dx12`** (`render/wgpu/src/surface/commands.rs:101,507`).
Every other backend draws one `LineStrip [0,1,2,3,0]`. The corpus goldens come from those backends, and they ink TL,
TR and BL solid and only BR partially (BR = 95, 63 %). `textfield_render_cb` was calibrated on that rule in s20 (11
rows at 0 outliers, `edittext_caret_empty` among them). s21's w2-px-b had already measured the literal Dx12
emulation as worse on `edittext_border_transform`.

- **The cx plays no part.** In Ruffle, `draw_line_rect` takes the same path for any colour transform; only
  `ColorTransform::multiply_from(color)` changes. Geometry is cx-independent in our renderer too (the cx only reaches
  the colour arguments). Our render matches the exporter on the BR corner and on every non-corner pixel at tolerance 2.
- **Decision:** I did not move our corner rule toward this oracle. Doing so would regress the 11 corpus rows that
  pass at 0 outliers. Instead I landed the golden as-is with `max_outliers = 19`, the exact count of artifact
  channels. Any colour regression moves thousands of channels, so the fixture still pins the cx colours. The
  `test.toml` comment records why.
- Confirming the backend is a LOCAL ORACLE REQUEST, and nothing here blocks on it.

## 2. Step 4: integer-twip centring (landed)

`tag.c::textfield_glyph_render_cb`: the centring term changed from `remaining * 0.5f` to
`(float)(((s32)lrintf(remaining)) / 2)`. This matches Ruffle's `misalignment / 2` on the `i32` Twips newtype
(`core/src/html/layout.rs:325-331`), which truncates toward zero. The existing `offset < 0 → 0` clamp still applies
afterwards, the same as Ruffle's `max(…, Twips::ZERO)`. It is the only centring site in the runtime (`grep "align == 2"`).

**Sweep.** I scanned every downloaded image row (visual, from_shumway, avm1, text, fonts, avm2, timeline, swf,
mixed_avm, import_assets, regression; 411 image rows). A row qualifies if a DefineEditText has HasLayout align = 2,
or if an AVM1 SWF or a SWF with DefineEditText contains the string "center" in any case (TextFormat / HTML align).
That found 8 rows; all 8 plus the new fixture were A/B'd with `render_canary.py` (same box, clean master vs patch):

| test | trace before → after | image before → after | outliers before → after | md5 |
|---|---|---|---|---|
| from_shumway/acid/acid-color-0 | pass → pass | fail → fail | **314 → 308** | DIFFERS (6 ch, bbox (822,155)-(867,221), the centred "Hello") |
| avm1/edittext_stylesheet | pass → pass | pass → pass | 0 → 0 | identical |
| from_shumway/acid/acid-text-5 | pass → pass | fail → fail | 422241 → 422241 | identical |
| from_shumway/acid/acid-text-x | ruffle_matched → same | pass → pass | 0 → 0 | identical |
| from_shumway/acid/acid-textfield | ruffle_matched → same | fail → fail | 15754 → 15754 | identical |
| from_shumway/acid/acid-textfield-scroll | pass → pass | pass → pass | 552 → 552 | identical |
| visual/edittext/edittext_caret_empty (12 cmps) | pass → pass | pass ×12 → pass ×12 | — | identical ×12 |
| visual/text/String_path_variable_button | pass → pass | pass → pass | 3 → 3 | identical |
| regression/avm1_edittext_placed_cxform | pass → pass | 19 ch (limit 0 at capture) | 19 → 19 | identical |

The new fixture passes under its landed `test.toml` (19 ≤ 19) with or without the step-4 hunk, because it has no
centred text.

**Regression suite** (`--mode=graphics`, all 150 tests, with the patch): **150/150 trace pass**. Every image row
passes except the fixture, which was at its old limit of 0 at capture time and passes once the landed `test.toml` is
in place. I did not run a full 694-line render canary: step 4 is only reachable when `align == 2`, and the sweep
above covers every image row that can reach it. Mode parity: graphics-only render code, no NO_GRAPHICS arm touched.

## 3. Step 3: premultiplied sampling for timeline bitmaps (priced NO-GO)

I accept the pricing in `w2-text-cx-jpeg3-report.md` §4: env-gated stand-in **314 → ~116**, and the floor with
3 + 4 is ≈ 110 against limit 3, so **acid-color-0 never flips**. The real fix is renderer-wide in `render_webgpu.c`:
upload premultiplied texels, then un-premultiply → cx → re-premultiply in the bitmap fragment path for every
`bitmap_pool*` texture sampled through `bitmap_samp_linear`. The landing bar is md5 identity over the full render
canary (694 lines; at the measured 5.9 s/test with `-P 2` that is about 70 min per leg here, more on a cold cache)
plus every bitmap row. The scan found **32 image rows with DefineBitsJPEG3/Lossless2/JPEG4** among the 411
downloaded. Every smoothed alpha-edged bitmap moves by construction, so the sweep is guaranteed to show diffs that
then each need adjudicating against goldens, and an images CI run must follow. That is a lot of spend for **0 flips**
in a slot whose headline was refuted. **Completion mechanism:** a dedicated bitmap-sampling arc, with the 32-row list
(reproducible with the scanner logic in §2: tag codes 35/36/90 in image-row SWFs) plus AVM2 BitmapData partial-alpha
rows as its sweep, and an images CI run. Fund it only together with another row that the premultiplied bilinear
fringe actually gates.

## Expected-flip ledger (coordinator: check CI against this)

| test | trace axis | pixel axis |
|---|---|---|
| regression/avm1_edittext_placed_cxform | **NEW row → pass** (empty trace, `output.txt` from the held fixture) | **NEW row → pass** (19 / 19 at tol 2) |
| from_shumway/acid/acid-color-0 | pass → pass | fail → fail, outliers **314 → 308** (band move) |
| everything else | no change | no change (md5-identical on the swept set) |

**Expected moves: 0 flips, 1 band move, 1 new passing row.** Anything else that moves is unexpected.

## Not finished

- Step 3 (above): NO-GO, completion mechanism stated.
- The held-fixture `README.md` in `w2-held-fixtures/` still lists `avm1_edittext_placed_cxform` as held. I left the
  coordinator's doc alone; the fixture is now in `regression/`.

## New unclaimed leads

- **Oracle-backend hygiene.** If the local exporter oracle runs on Dx12 (or any backend that wgpu marks for line
  emulation), every exporter golden with EditText borders or `draw_line` (carets, hairline hit boxes) carries this
  four-corner 3/4 signature. Future fixtures with borders should either avoid borders or budget them the way this one
  does. Running the exporter with `WGPU_BACKEND=vulkan` (or gl) would give LineStrip-backend goldens.

## LOCAL ORACLE REQUESTS

1. Run the exporter on `ruffle-tests/tests/swfs/visual/edittext/edittext_caret_empty/test.swf` (`-s -f 1`, the same
   invocation as for the fixture). Compare one box's TL / TR / BL border-corner pixels with the corpus
   `output.expected.png`. Expected if §1 is right: the exporter shows partial (≈ 3/4) TL/TR/BL corners and the golden
   shows solid ones. Also note which wgpu backend the exporter picked (`RUST_LOG=wgpu_core=info` prints it). If the
   exporter instead matches the golden there, §1's attribution is wrong. In that case re-open the fixture's 19-channel
   budget; the runtime is still correct for the corpus.
