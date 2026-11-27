# s29 w3-interim3-residuals: report (wave 2, implementation)

**New files:**
- `SWFRecompDocs/plans/session29-fanout-reports/w3-interim3-residuals-report.md` (this file)
- `SWFRecompDocs/plans/session29-fanout-reports/w3-interim3-residuals.patch`
- `ruffle-tests/tests/swfs/regression/avm1_tabindex_child_null/{test.swf,test.toml,output.txt,README.txt}`
  (`test.swf`/`test.toml` = byte copies of `w2b-tabindex-oracle/t_child_numstr_null/`; `output.txt` = byte copy of the
  FP32 capture `w1-local-oracles/w2b-tabindex.t_child_numstr_null.txt`)

**Modified:** `SWFModernRuntime/include/actionmodern/action.h` (one trailing `DrawPath` field),
`SWFModernRuntime/src/actionmodern/action.c`, `SWFModernRuntime/src/avm2/avm2_display.c`,
`ruffle-tests/render_canary_tests.txt` (2 members appended at EOF), `ruffle-tests/tests/swfs/regression/README.md`
(1 table row, after the other tabindex rows).

The patch carries the fixture's binary SWF, so apply it with `git apply --binary`. It also carries the regression README
row, which is outside the brief's path list.

Base: `origin/master` `fcdae20f` (code = interim #3 `6ee6eded7` + TSNAP `1fcf2b1c1`). Categories downloaded: avm1,
avm2, visual, from_shumway, from_gnash, fonts, text (upstream master at download time; flash_fixes applied cleanly).
Box: `SETUP_STATUS` all OK (Dawn on lavapipe).

**Fidelity (item 1):** my clean-master renders of `avm1/movieclip_line_gradient_style` and
`avm1/movieclip_begin_gradient_fill` are **md5-identical** to CI's actual PNGs on `origin/ruffle-image-results`
(`4140ff98a`, interim #3): `2a8ee419…` and `b5b69978…`. Local grading is CI-grade on both rows. The before leg reproduces
the brief exactly: 773 outliers, and 15 468 / 15 541 channels over tol 6 vs FP32 LOW LNX / WIN.

## Verdicts (lead)

| item | verdict | priced moves (by name) |
|---|---|---|
| **1** `avm1/movieclip_line_gradient_style` LOW band | **FIXED (owner found, Flash-ward)** | Owner: **n-seam-caps' drawing-API builder arm** (`SWF_STROKE_SEAM_CAPS=0` alone restores 614 / 15 357; the other six kill switches leave it at 773 / 15 468). After the patch: **773 → 614 outliers vs golden; vs FP32 LOW 15 468 → 15 357 (LNX), 15 541 → 15 430 (WIN)**. The render is byte-identical to the `SEAM_CAPS=0` render. fail → fail |
| 1, family check: `avm1/movieclip_begin_gradient_fill` | **did not move** | 1445 outliers at s28 final, at interim #3 and after this patch. md5-identical before/after |
| 1, side move: `visual/drawing_api/fills_and_lines` (golden NOT Flash) | **priced, Flash-ward** | 5 channels at (298,98) and (301,98). vs FP32 LOW: LNX 5709 → **5704**, WIN 10 884 → **10 879** (tol 2), screen 5708 → **5703**. vs golden 38 424 → 38 429 (this is the n-seam-caps "on" gain, and it was AWAY from Flash). fail → fail |
| **2** rider `avm2/swz` | **FIXED** | `Test.as:16` → `Test.as:12`. **`swz` mm → pass**. `loader_applicationDomain`, `url_loader` and `urlstream_basic` stay pass. Both modes |
| **3** rider AVM1 `tabIndex = null` | **FIXED + fixture** | `regression/avm1_tabindex_child_null` (FP32 golden) **mm → pass**. The 4 other `avm1_tabindex_*` rows and all 18 `avm1/tab_ordering_*` (15) / `edittext_tab_*` (2) / `button_keypress_vs_tab` rows are unchanged (pass). Both modes |
| Gate: render canary (200 + 2 new members) | **md5-identical outside the ledger** | 263 identical, 2 DIFFERS (both ledger rows above). 0 trace-status and 0 image-status changes. The n-seam-caps evidence rows (`avm1_stroke_seam_caps`, `avm1_stroke_hinting_caps`, `avm1/avm2_drawapi_stroke_snap`, `avm1_stroke_pixel_snap`, `avm1_stroke_noscale_signed`, `avm1_stroke_join_cap_snap`, `avm1_stroke_pixel_snap_matrix`, `acid-stroke-0`, `strokes/scale`) are all md5-identical |

## EXPECTED-FLIP LEDGER (for the coordinator's CI grade)

**Trace axis (both modes; runtime is shared):**
- `avm2/swz`: output_mismatch → **pass**
- `regression/avm1_tabindex_child_null`: **new row, pass** (it is output_mismatch on master with the fixture present)
- Nothing else moves. The tab family, `loader_applicationDomain`, `url_loader` and `urlstream_basic` stay pass.

**Pixel axis (graphics; no status flips):**
- `avm1/movieclip_line_gradient_style` [output]: fail → fail, **773 → 614** outliers (= the s28-final value), max_diff 255
  unchanged.
- `visual/drawing_api/fills_and_lines` [output]: fail → fail, outliers **+5** vs its non-Flash golden (Flash-ward −5
  vs FP32 LOW, see above).
- Every other image row: unchanged (the canary is md5-identical outside these two rows).

## Item 1: mechanism and evidence

**Kill-switch sweep** on current master (one run each, outliers vs golden / channels > 6 vs FP32 LOW LNX):

| switch | outliers | vs FL LNX |
|---|---:|---:|
| none (master) | 773 | 15 468 |
| `SWF_STROKE_SEAM_CAPS=0` | **614** | **15 357** |
| `SWF_STROKE_CAP_OCTAGON=0`, `SWF_STROKE_HINT_ENDS=0`, `SWF_STROKE_CENTRE_QSNAP_ALL=1`, `SWF_TF_LOW_PEN_SNAP=0`, `SWF_CAB_HIGH_SNAP=1`, `SWF_LOWQ_TSNAP=0` | 773 | 15 468 |
| `SWF_STROKE_SEAM_CAPS=1` / `=9` (renderer cap threshold only) | 773 | 15 468 |

The renderer threshold has no effect, so the owner is not `render_webgpu.c` placement. It is the builder arm
`action.c` `drawingBuildStroke` (`seam_caps`), which emits two round caps at each closed seam in place of the join.

**Per-region (FP32 LOW LNX, channels > 6 inside each changed-pixel bbox ±2 px):** 70 pixels changed, in 7 cells. All 7
are translucent strokes (alpha < 100), and **all 7 moved away from Flash**: +20, +20, +30, +12, +10, +15, +4, which sums
to the whole +111. No region in the frame moved toward Flash. The changed pixels sit one per row on a diagonal from the
seam's outer corner (110,6) to (177,12): RGB 255,50,53 against FP32's and our old 255,138,140. That is the stroke
**blended twice**. The two cap fans' near-coincident vertices feed the translucent non-zero union (`drawingUnionTris`,
run as the renderer's `StrokeSnapSrc.post` after the restage), and it leaves a sliver overlap.

**Why the caps are wrong there in Flash's terms.** n-seam-caps' rule is that a seam is two caps only when snapping moves
the two seam ends apart. This test's `lineStyle(8)` is u = 32, so W = 0 and `render_webgpu_stroke_snap` never snaps it.
Flash draws its seam as a join. The caps add no geometry: for round/round the union is the same region. They only add
near-coincident triangles.

**Fix (`action.c`; functions touched: new `drawing_seam_join_wanted`, `drawingBuildStroke`, `drawingFinalizePath`, `fillDrawingInfos` (its stroke re-expansion rebuild)):**
- A stroke whose device width is too wide for any seam-splitting snap builds the old join (`DrawPath.stroke_seam_join`,
  a new trailing field in `action.h`). Wide means floor(lineWidth) × the clip's smaller axis scale ≥ 3.125 px, which is
  non-hinted u > 12 and so W = 0. For pixelHinting the bound is 3.875 px (W > 3).
- The choice is made at finalize (scale 1) and re-made at render time from the on-screen scale. A change of choice
  triggers a rebuild.
- The smaller axis is ≤ the renderer's rms scale, so the rule errs toward caps. noScale strokes keep the caps.
- Every stroke that can reach W 1..3 keeps n-seam-caps' geometry unchanged. That is why all its Flash fixtures are
  md5-identical.

**Not changed:** the AVM2 twin `avm2_display.c` `gfx_build_stroke` / `gfx_stroke_seam_caps_on` has the same
wide-stroke seam caps. It has no per-frame scale rebuild hook and no measured row, so it is left alone (lead below). The
timeline (`swf.cpp`) seam path is untouched.

## Item 2: `avm2/swz`

FP32 reports an unhandled ErrorEvent with the stack captured when the dispatcher was constructed. `avm2_display.c`:
- new trailing field `Avm2UrlLoaderExt.ctor_stack`;
- new `ul_script_stack_tail`: the existing "drop our native `flash.net::URLLoader…` frame" code, factored out;
- `url_loader_init` (the URLLoader ctor) snapshots the stack;
- `ul_start_load`'s signed-RSL (`digest`) arm uses the ctor stack, and falls back to the load-time stack;
- `ul_deliver` itself is unchanged: it prints `pl->stack_tail`.

The ext is conservatively GC-scanned (`avm2_gc.c` native_ext word scan), so the stored string is kept alive. The cost is
one stack snapshot per `new URLLoader()`.

## Item 3: `tabIndex = null`

`action.c` `actionSetMember`, tabIndex block: a `null` on a clip or button becomes `undefined` before the coercion. It is
stored as undefined (FP32: `undefined`, where we printed `0`; Ruffle agrees). Text fields keep the coercion, because no
capture covers them (lead below). The root raw-property arm (`ab56ff360`) runs before this line and is unaffected.

## Per-test before/after (clean origin/master vs this patch, same box, `--mode=graphics` unless noted)

| test | before | after |
|---|---|---|
| avm1/movieclip_line_gradient_style (img) | fail 773; FL 15 468 / 15 541 | fail **614**; FL **15 357 / 15 430** |
| avm1/movieclip_begin_gradient_fill (img) | fail 1445; FL 34 216 / 34 345 | identical (md5) |
| visual/drawing_api/fills_and_lines (img) | fail 38 424; FL 5709 | fail 38 429; FL **5704** |
| avm2/swz | output_mismatch | **pass** (also no-graphics) |
| avm2/loader_applicationDomain | pass | pass (also no-graphics) |
| avm2/url_loader, avm2/urlstream_basic | pass | pass |
| regression/avm1_tabindex_child_null | output_mismatch | **pass** (also no-graphics) |
| regression/avm1_tabindex_{fn2_root_raw,fresh_child_coerce,mtasc_class_main,read_first_coerce} | pass | pass |
| avm1/tab_ordering_* (15), edittext_tab_focus, edittext_tab_stops, button_keypress_vs_tab | pass | pass |

**Regression suite:** the 5 tabindex rows, plus the 7 stroke rows (`avm1_stroke_seam_caps`, `avm1_stroke_hinting_caps`,
`avm1_drawapi_stroke_snap`, `avm2_drawapi_stroke_snap`, `avm1_stroke_pixel_snap`, `avm1_stroke_noscale_signed`,
`avm1_stroke_join_cap_snap`) are trace pass and md5-identical before/after.

**Canary:** `render_canary.py` before/after over `render_canary_tests.txt` (200 tests) plus an extra 8-test capture.
263/265 PNGs are identical, and the 2 DIFFERS are ledger rows. I appended `regression/avm1_stroke_seam_caps` and
`regression/avm1_stroke_hinting_caps` at EOF: the set had no n-seam-caps FP32 fixture, and they guard the "narrow strokes
keep caps" half of the rule.

## Could not finish / not done

- Nothing outstanding on the three items.

## New unclaimed leads

- **AVM2 twin of item 1:** `avm2_display.c` `gfx_build_stroke` emits seam caps for wide translucent strokes too.
  Completion: the same width gate needs an on-screen scale at build time (AVM2 builds at finalize only). Price it on any
  AVM2 drawing-API row with a translucent ≥ 4 px closed round/round stroke (none is in the canary).
- **Translucent union slivers in general:** `drawingUnionTris` (libtess2 non-zero) can leave double-covered slivers on
  near-coincident input. Narrow seam caps (W ≤ 3) on a translucent stroke would still feed it. Completion: a vertex weld
  (snap input to a 1/64-twip grid) before `tessAddContour`, priced on the canary.
- **TextField `tabIndex = null`:** we still coerce to 0. Completion: an FP32 capture (below).

## LOCAL ORACLE REQUESTS

- (Optional) **FLASH:** a text-field variant of `w2b-tabindex-oracle/t_child_numstr_null` (`createTextField` then
  `t.tabIndex = null; trace(t.tabIndex)`), trace, direct, to decide the text-field null rule. Not blocking: this patch
  leaves text fields unchanged.
