# s28 wave 2: `w2-filter-residuals-land` (filter residuals landed against Flash Player 32)

Branch `fanout/w2-filter-residuals-land`. Base `origin/master` `201c9eee`. Box: cloud, `SETUP_STATUS` all OK (Dawn on
lavapipe). Ran `download_tests.sh avm1 avm2 visual from_shumway fonts text from_gnash`. Upstream Ruffle master is
`d2a801a98` (`ls-remote`). The drift since `c2f7d24b7` is 4 test.toml `num_frames`→`num_ticks` migrations, none of
which touch this family.

**Fidelity:** two filter rows prove local grading is CI-grade. My clean-master renders of
`visual/filters/blur_quality` and `avm2/bitmapdata_applyfilter_blur` are byte-identical (md5) to CI's actual PNGs on
`ruffle-image-results`.

## NEW files

- `SWFRecompDocs/plans/session28-fanout-reports/w2-filter-residuals-land-report.md` (this report)
- `SWFRecompDocs/plans/session28-fanout-reports/w2-filter-residuals-land.patch`: `git diff --binary origin/master HEAD`
  over `SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt
  ruffle-tests/tests/swfs/regression` and the RvF doc. It holds every fixture / golden change. `git apply --check`
  passes on `origin/master` `201c9eee`, and `git apply --check -R` passes on the branch.
- `ruffle-tests/tests/swfs/regression/avm1_applyfilter_dropshadow/`
  {`test.swf`, `test.toml`, `output.txt`, `output.expected.png`}. FP32 trace + image. The SWF comes from
  `avm1_applyfilter_blur/create_test_swf.py`, byte-identical.
- `ruffle-tests/tests/swfs/regression/group_alpha_shadow_shape_a50/`
  {`create_test_swf.py`, `test.swf`, `test.toml`, `output.txt` (empty), `output.expected.png`}
- `ruffle-tests/tests/swfs/regression/avm2_group_alpha_shadow_shape_a50/` (the same five files). Both SWFs are
  byte-identical to the s27 `mkprobes_w2b.py` probes that Flash captured. Golden = the FP32
  `w2b_shadow_shape_a50/flash.screen.png`.
- `ruffle-tests/tests/swfs/regression/avm2_applyfilter_bevel_sample/`
  {`create_test_swf.py`, `test.swf`, `test.toml`, `output.txt`}. Trace only: the FP32 lines of the 18 exact
  cases + 4 blur grids.
- `ruffle-tests/tests/swfs/regression/avm1_display_filter_growth_edge_scale/`
  {`create_test_swf.py`, `test.swf`, `test.toml`, `output.txt` (empty), `output.expected.png`}. Golden = FP32;
  the residual is budgeted.
- `SWFRecompDocs/plans/session28-fanout-reports/w2-filter-residuals-land-fixtures/avm2_bevel_offset_sweep_probe/`
  (FLASH request, below)
- `SWFRecompDocs/plans/session28-fanout-reports/w2-filter-residuals-land-fixtures/fit/` (bevel fit scripts + README)

Modified (beyond source):
- 3 regression rows re-carry their FULL Flash goldens (held bevel cases restored):
  - `avm2_applyfilter_glow_kernels`
  - `avm2_bitmapdata_draw_filtered`
  - `avm2_applyfilter_gradient_opaque`

  Each has `HELD = ()`, a regenerated `test.swf` (byte-identical to the archived full Flash probe), `output.txt` =
  the full FP32 capture, and a test.toml note.
- 2 regression rows re-goldened to FP32 (`output.expected.png` + test.toml): `avm1_nested_po3_filters` and
  `avm1_runtime_filters`.
- `group_alpha_*/create_test_swf.py` ×10: the shared generator gains the `shadow_shape_a50` probe. All copies stay
  identical, and every existing SWF regenerates byte-identical.
- `avm1_applyfilter_blur/create_test_swf.py`: docstring only.
- `render_canary_tests.txt`: +2 members at EOF.
- `RUFFLE_VS_FLASH_DIFFERENCES.md`: one entry appended at EOF.

**Source touched (named for siblings):**
- `tag.c`: `filter_shadow_offset_px` (+ static `g_shadow_frac_x/y`), `compose_chain_entry_to_layer`, and
  `render_filtered_core`'s offset block (pre-shift snapshot + composite `du/dv`).
- `avm2_display.c`: `avm2_filter_one_in_place` (chain-entry composer `du/dv`), and `avm2_render_filtered`'s pre-shift
  and composite offset.
- `avm2_bitmap.c`: `fb_glow_amount`, new static `fb_bevel_offset`, and the bevel sample call in
  `fb_glowlike_region`.
- No `render_webgpu.c`, `NO_GRAPHICS`-arm or recompiler change.

## Verdicts

| # | Item | Verdict | Result |
|---|---|---|---|
| 1 | `fb_glow_amount` quantization order + `regression/avm1_applyfilter_dropshadow` | **LANDED** | trace 17/18 → **18/18**; image 45 ch (max 2) → **0 (max 1)**. Both modes pass. 0 other moves. |
| 2 | Fractional display DropShadow offset (bilinear) | **LANDED, with the priced loss** | `shadow_shape_a50` AVM1 + AVM2: 2304 ch (max 20) → **0 (max 1)**. `nested_po3_filters` re-goldened to FP32 (exact at tol 2). `runtime_filters` re-goldened to FP32 (case D exact, rest budgeted). −3 corpus comparisons on Ruffle goldens; all three move Flash-ward and get an RvF entry. |
| 3 | Bevel sample | **LANDED (fitted rule; 18/30 probe cases exact)** | Every residual line of the 3 Flash probes is closed: glow_kernels 4 → 0, draw_filtered 2 → 0, gradient 2 → 0, so their held cases are restored in `regression/`. The probe goes from 2175 px to 177. The new row is `regression/avm2_applyfilter_bevel_sample`. Also `regression/avm1_applyfilter_bevel` becomes **pixel-exact** vs FP32 (93 ch → 0 at tol 0). |
| 4 | GPU growth / kernel taps | **NO-GO (priced), fixture landed with a budget** | C and E are exact (filters work in stage px; object and parent scale are right). A and B show no extent difference. F confirms the floored box chain exactly: Flash x = 82..287, ours 79..291. The fix is a q-pass GPU box blur in `render_webgpu.c`, which is not small. |

## EXPECTED-FLIP LEDGER (CI, graphics; coordinator checks against this)

**Trace axis**
- NEW `regression/avm1_applyfilter_dropshadow`: pass (both modes).
- NEW `regression/avm2_applyfilter_bevel_sample`: pass (both modes).
- NEW image-only rows (`group_alpha_shadow_shape_a50`, `avm2_group_alpha_shadow_shape_a50`,
  `avm1_display_filter_growth_edge_scale`): trace pass (empty `output.txt`).
- `regression/avm2_applyfilter_glow_kernels` (17 → 23 lines), `avm2_bitmapdata_draw_filtered` (11 → 13 lines) and
  `avm2_applyfilter_gradient_opaque` (24 → 26 lines): goldens extended to the full FP32 capture; they stay **pass**
  (both modes). Without the `avm2_bitmap.c` change they would fail by 4 / 2 / 2 lines.
- Corpus: **0 trace moves** (canary: no trace status change in 207 tests).

**Pixel axis**
- Gains (regression):
  - NEW pass: `regression/avm1_applyfilter_dropshadow`, `regression/group_alpha_shadow_shape_a50`,
    `regression/avm2_group_alpha_shadow_shape_a50`.
  - NEW pass under its budget: `regression/avm1_display_filter_growth_edge_scale`.
- Re-goldened, pass → pass: `regression/avm1_nested_po3_filters` (now FP32, tol 2) and
  `regression/avm1_runtime_filters` (now FP32, budget). On master code against the new goldens, both fail.
- Losses (Ruffle goldens; RvF entry; Flash-ward on the moved pixels):
  - `visual/filters/drop_shadow` `output` pass → fail;
  - `visual/cache_as_bitmap/edittext_scroll` `output.01` and `output.02`, pass → fail.
- md5 moves with status unchanged (both Flash-ward):
  - `avm2/bitmapdata_applyfilter_destpoint_edges` (pass → pass; 23 ch, max 1; Σ outliers at tol 0 vs the
    Flash golden 50358 → 50335);
  - `regression/avm1_applyfilter_bevel` (pass → pass; becomes exact at tol 0).
- Net: **+4 new regression image rows passing**, 2 regression rows moved from Ruffle to Flash goldens, **−3 corpus
  comparisons** (Ruffle goldens, priced).

Local note on `visual/filters/drop_shadow`: on this box the row already FAILS before the patch (8052 outliers at tol 2,
max 255, spread over all the default-font text). The CI baseline lists it as passing, so read its pass → fail from CI,
not from here. The moved-pixel grading below is unaffected.

## GATE

`render_canary.py capture` before (clean `201c9eee`) / after over 207 tests / 272 PNGs: the standing canary list,
every image row with `filter` in its path (avm1, avm2, visual, from_shumway, regression), every regression
applyFilter / PO3 / group-alpha / layer-group fixture, plus the 5 new rows. The w1's list was 209; mine resolves to 202
standing + 5 new after dedup.
```
IDENTICAL 261   DIFFERS 7   APPEARED 0   VANISHED 0   NO_RENDER 0   MISSING 5 (the new rows: no before)
TRACE STATUS CHANGES: none
IMAGE STATUS CHANGES: visual/cache_as_bitmap/edittext_scroll output.01, output.02  pass -> fail (ledger)
DIFFERS: destpoint_edges (23 ch max 1), avm1_applyfilter_bevel (93 ch max 1), avm1_nested_po3_filters (5970 ch max 9),
         avm1_runtime_filters (3060 ch max 18), edittext_scroll .01 (276) / .02 (273), visual/filters/drop_shadow (39146)
```
- Every DIFFERS row is in the ledger.
- The two Flash-golden rows that move (`destpoint_edges`, `avm1_applyfilter_bevel`) move toward Flash. The w1 gate
  did not see them, because the bevel rule is new in this slot.
- `from_shumway/acid/acid-filter`, `acid-filter-2` and `visual/filters/drop_shadow_angles` (Flash goldens):
  md5-identical.
- After the final `tag.c` refactor (the fractions are snapshotted into locals), a re-capture of the moved rows plus
  acid-filter is md5-identical to the "after" leg.

**No-graphics (mode parity, shared `fb_glow_amount` / `fb_bevel_offset`).** PASS on:
- `regression/avm1_applyfilter_{kernels,glow,bevel,blur,dropshadow,convolution,convolution_not_cm}`;
- `avm2_applyfilter_{glow_kernels,gradient_opaque,bevel_sample}`, `avm2_bitmapdata_draw_filtered`;
- the 3 full s27 Flash probes: 0 lines off (graphics: the same).

## Per-test before/after (same box; before = clean `origin/master` code against the landed goldens)

| row | before | after |
|---|---|---|
| `regression/avm1_applyfilter_dropshadow` | trace 17/18 (`dt 50,50` 0x98 vs 0x99); image FAIL 45 ch, max 2 | trace **18/18**; image **PASS** 0, max 1 |
| `regression/group_alpha_shadow_shape_a50` | image FAIL 2304 ch, max 20 | **PASS** 0, max 1 |
| `regression/avm2_group_alpha_shadow_shape_a50` | image FAIL 2304 ch, max 20 | **PASS** 0, max 1 |
| `regression/avm1_nested_po3_filters` (FP32 golden, tol 2) | FAIL 2872 ch, max 9 | **PASS** 0, max 2 |
| `regression/avm1_runtime_filters` (FP32 golden, budget) | FAIL 15133 ch at tol 1, max 56 | **PASS** (12115 at tol 1, 2380 at tol 3; case D 0 px) |
| `regression/avm2_applyfilter_bevel_sample` (FP32) | trace 266/441 | **441/441** |
| `regression/avm2_applyfilter_glow_kernels` (full FP32) | 4 lines off | **0** |
| `regression/avm2_bitmapdata_draw_filtered` (full FP32) | 2 lines off | **0** |
| `regression/avm2_applyfilter_gradient_opaque` (full FP32) | 2 lines off | **0** |
| `regression/avm1_display_filter_growth_edge_scale` (FP32, budget) | FAIL (6453 ch at tol 1) | **PASS** (4935 at tol 1, 140 at tol 4) |
| `regression/avm1_applyfilter_bevel` (FP32) | PASS (93 ch at tol 0) | PASS (**0** at tol 0) |
| full `avm2_bevel_sample_isolation_probe` (FP32, scratch) | 356 lines / 2175 px | 65 lines / 177 px |

## 1. `fb_glow_amount` (landed as the w1 prototype)

The new amount is `ga = (floor(amount) · alpha_byte + 127) / 255`. It replaces the s27
`floor(amount · (a + 1) / 256)`. Mechanism and fit: w1 report §2. It moves nothing in the gate except the new row,
which passes both axes in both modes.

## 2. Fractional display DropShadow offset (landed as the w1 prototype + one robustness change)

- **`nested_po3_filters`:** the after-render vs FP32 is 2094 px > 1, max 2, all inside the filter regions; 0 px > 2.
  The README's "0 px" was at tolerance 2. So the row is re-goldened at **tolerance 2**: the ±2 are display-blur
  levels (Ruffle's scaled-pass kernel vs Flash's floored box), the same as growth case D.
- **`runtime_filters`, per region vs FP32:**
  - case D (DropShadow 8 px @ 45° under `_alpha 50`, (43,173)–(168,253)): master 1006 px > 1 (max 18) → **0 (max 1)**,
    so this case is Flash-exact.
  - Elsewhere: case E (display BevelFilter, (300,170)) holds 2380 channels at max 56, from the GPU bevel's
    nearest offset and float composite (lead below). Cases A / B are blur levels ±3.
  - Re-goldened to FP32 with the budget `checks = [{tol 1, 12200}, {tol 3, 2400}]`.
- **The 3 corpus losses (Ruffle goldens),** graded only on the pixels the change moves:

  | row | moved px | vs FP32 direct capture: Σ\|err\| before → after | px closer after / before |
  |---|---|---|---|
  | `visual/filters/drop_shadow` | 13260 | 354061 → 280819 | 8769 / 4141 (draw() capture: 7264 / 5896) |
  | `edittext_scroll` .01 | 92 | 15200 → 11932 | 62 / 29 |
  | `edittext_scroll` .02 | 91 | 14959 → 11603 | 62 / 29 |

  All three are Flash-ward. The RvF entry is appended. FP32 captures: `w1-local-oracles/w1-text-glyph-aa/png/*direct*.png`
  and `w1-acid-flash/visual_filters_drop_shadow.png`.
- **Robustness change.** `render_filtered_core` now snapshots `g_shadow_frac_{x,y}` into locals right after
  `filter_shadow_offset_px`. This is behaviour-identical (md5-verified). Nothing renders between the two today, but a
  later recursive render can no longer clobber the global.
- Not changed:
  - the display Bevel offset (still nearest; no Flash display-bevel fit yet);
  - the AVM2 twin golden (shared with AVM1, as for the other `avm2_group_alpha_*` twins).

## 3. Bevel sample offset (new in this slot)

**Flash's blurred grid B is byte-identical to ours:** both `blur3` and `blur4`, on both sources. **The a0 cases were
already exact.** Every residual is therefore the sample POSITION. Two parts:

1. **Integral components:** our angle is Fixed16 radians, so `cosf(90°)` came out −2.5e-6. A floored bilinear
   sample then lost one level on every gradient texel. That accounts for the a90 rows: 108 px (K) and 358 px (R) per
   distance. Fix: snap the angle to 0.01° and do the trig in double. An integral 1/256 component is then exact.
2. **Fractional components:** per-SIDE fits. They use pixels whose opposite sample lies in a flat B region, so d pins
   one sample alone (`fit/s11.py`).
   - The same nominal component, −362.04/256, fits −363 at 45° but −361 at 135°. So the rule is not a per-component
     quantiser of `o`.
   - For d 2 / 3 at 45 / 135 / 200° the +o sample sits at `round(o·256) + 1` toward +x / +y, and the −o sample at
     its mirror.
   - `floor(o·256 + c)` with c ∈ [1.34, 1.47) fits every isolated sample except d 1.5 @ 135° x (`fit/s13.py`).
     **c = 1.4 is landed.**

`fb_bevel_offset` result:
- Probe: 2175 → 177 px; 18 of 30 cases exact.
- Residual: d 1.5 @ 135° (118 + 19 px: there Flash's x lands on plain round(o)), and ≤ 9 px in each of ten other
  cases (d 2 / 3 at 45 / 135 / 200°, d 1.5 @ 200° R).
- The mechanism behind the constant is **unknown**. Completion: FLASH request 1 (sweep).
- Closes every residual line of the three s27 probes, so the held bevel cases are restored in `regression/`. It also
  makes `regression/avm1_applyfilter_bevel` exact at tolerance 0.
- It changes 23 channels of the `destpoint_edges` Flash golden, all toward Flash.

Rejected along the way (`fit/`):
- signed-truncating integer bilinear (4 forms: 2907–4122 px);
- rounding-bias variants of the bilinear sum (≥ 798 px);
- ceil / away-from-zero / trunc + 1 quantisers (606 / 862 / 407 px);
- `round + 1 on fractional components`: 311 px. It also closes all three probes' lines, but it breaks d 1.5 @ 45°.

## 4. GPU display-filter growth (NO-GO stays; kernel taps priced; fixture landed)

Flash capture of `avm1_display_filter_growth_edge_scale`, per case. Our render is unchanged by this patch except in
D.

| case | what it measures | ours vs FP32 |
|---|---|---|
| A: glow of a half-off-stage square at the left edge | off-stage capture | the halo reaches x = 0 in both; levels ±4 (526 px > 1) |
| B: shadow thrown back from the right edge | off-stage capture | same extent; levels: shadow interior ours alpha 253 vs Flash 255, ramp −1 (832 px > 1, max 2) |
| C: scale-3 object, glow blur 10 | filter units | **exact** (≤ 1): blur in stage px |
| E: scale-2 parent, child glow | filter units | **exact** (≤ 1) |
| D: scale-3 object, DS 7.07 px | fractional offset under scale | 1199 → 693 px > 1 with part B; the rest is blur levels (max 4) |
| F: blurX 60, q9, strength 255 | tail length | Flash x = **82..287** (exactly the w1 floored-box prediction); ours 79..291 |

- **Verdict: no growth clip is observable, and the box-chain model is confirmed.** The remaining differences all come
  from the GPU display blur kernel: tail length (F), interior / ramp levels (A, B, D). That kernel is Ruffle's
  scaled-pass blur.
- **Completion mechanism:** run q floored `fb_kernel` box passes on the GPU in `render_webgpu_run_blur` (the s27
  `set_blur_exact` arm, any new pipeline on `MSAA_SAMPLES`).
- **Not small:** it moves every display blur / glow / shadow row at q ≥ 2 (dozens of Ruffle-golden rows) and touches
  `render_webgpu.c`, which `w2-lowq-sample-point` is editing. Priced NO-GO for this slot.
- **Fixture:** landed with the FP32 golden and budget `checks = [{tol 1, 5000}, {tol 4, 150}]` (measured 4935 / 140).
  Tighten it when the box blur lands.

## Refutations / premise checks

- **"Flash == the after-render on `nested_po3` exactly"** (brief): true at tolerance 2 only. At tolerance 1 there are
  2094 px, all ±2 blur levels, so the row lands at tol 2.
- **"Item 3: the residual is in how one floored sample is produced, not the geometry"** (w1): refuted. The B grid is
  exact. The residual IS the geometry, but a 1/256-scale one, below the w1's 1/64 perturbation grid. On top of that,
  our Fixed16 angle added a −2.5e-6 offset at 90°, which the w1 probe could not separate.
- The w1 gate's "the `fb_glow_amount` half moves nothing" still holds. The bevel rule (new here) moves two
  Flash-golden rows, both Flash-ward.

## New unclaimed leads

- **Display BevelFilter** (`runtime_filters` case E: 2380 ch, max 56, against an FP32 capture already in hand). The
  GPU bevel still uses the nearest offset and Ruffle's float composite. Port `fb_bevel_offset`'s geometry plus the
  integer composite to the display path; the existing capture prices it.
- **GPU floored box blur** (item 4 completion): would close growth F, A, B, D levels, the `nested_po3` ±2 and the
  `runtime_filters` A/B ±3. Large: it moves many Ruffle-golden rows.
- **Bevel offset mechanism** (d 1.5 @ 135°): FLASH request 1.

## LOCAL ORACLE REQUESTS

1. **FLASH trace:** `session28-fanout-reports/w2-filter-residuals-land-fixtures/avm2_bevel_offset_sweep_probe`
   (AVM2, `run_trace.py`, 1 frame, 2121 lines; SWF + generator shipped; `output.txt` = ours, provisional).
   - What it is: a ramp source × 7 distances × 15 angles.
   - What to compare: a diff vs our output gives the dense grid needed to find the real offset rule behind
     `floor(o·256 + 1.4)` and its d 1.5 @ 135° exception.
2. (optional, cheap) **FLASH image:** `regression/avm2_group_alpha_shadow_shape_a50/test.swf`, 1 frame, `--screen`.
   - Why: it confirms the AVM2 twin shares the AVM1 golden (w1 request 4, still not captured; ours passes it at
     max 1).
