# w1-board-audit — session 13 wave-1: dual-axis board audit + missed-cheap-win sweep

**Agent:** wave-1 `w1-board-audit` (read-only diagnosis, moderate parallel CPU).
**Repo state:** `10931d62e` (master), clean apart from the pre-existing untracked
`SWFRecomp/tests/gpuprobe/`, `docs2/examples/`, `docs2/gpuprobe_catalog.json`.
**Baselines audited:** CI run `31090651530` at `1f8396f57`
(`mode=graphics categories=full images=true`, merged as `9c7a2dcb2`) —
trace **4229 effective**, pixels **286/567**.
**Boards audited:** `polish-sweep-arc.md` §13.3 (trace) and
`graphics-fanout-playbook.md` §11 (pixels).

Nothing was edited outside this file. 15 individual tests were run locally
(`--tests-dir=<suite> --test=<name> --diff`, `xargs -P 5`); no suite run.

---

## 0. TL;DR

- **The s12 "near-pass well is a CLOSED inventory" claim is CONFIRMED, and
  this is now the fifth consecutive session of zero refill.** 36 rows sit at
  gap ≤ 5; 13 are ignore-listed and the remaining 23 are *all* arc-owned,
  disposition-owned or already-refuted. The only two rows that moved into the
  window since `6de650432` (`mixed_avm/avm2_loads_avm1_v9` 6→1,
  `avm2_loads_avm1_v10` 5→3) are already-known dual-VM arc rows.
- **Three §13.3 / §11 board claims are REFUTED or materially wrong** (§4):
  the acid-blend-2 "B-channel halving" mechanism, the `audio/g711` "A-law/µ-law
  codec" framing, and the `simple_shapes/masks` "reclassify as
  hairline_edge_drift" instruction (never encoded — the tool still ranks it in
  the top cluster). Two more are stale in detail (line number, line count).
- **The cheapest-looking rows in the whole corpus are decoys.**
  `avm2/loader_load` (gap 2) and `avm2/bom` (gap 3) are fully dispositioned in
  `RUFFLE_VS_FLASH_DIFFERENCES.md` as unreproducible hashbrown enumeration
  order — but are in **no** ignore list, so they head every near-pass
  regeneration. I costed them before checking dispositions; that mistake is
  the strongest argument for the hygiene lead (§5 L8).
- **7 genuinely new leads** (§5), 5 of them pixel-side or dual-axis, plus one
  hygiene bundle. Best estimated yield: `from_gnash` `action_order` execution
  ordering (+2 trace, riders to +4) and the acid-blend-2 single-outlier pixel
  (+2 pixels, and it kills a wrong board hypothesis).

---

## 1. Method / provenance

Trace: read the 24 merged `_results/results_graphics.json` files. **Three are
stale nested stems** frozen at older SHAs and were excluded from all counts
(`from_avmplus/as3/Vector`, `.../Vector/nonindexproperty` @ `67c21aabe`;
`from_gnash/misc-ming.all/displaylist_depths`, `from_shumway/timeline` @
`6871f843e`); `from_shumway/avm1` is nested inside its parent and is excluded
as a double-count (the `denominator` memory note). Dedup'd corpus at
`1f8396f57`: **4427 graded, 4087 pass + 252 ruffle_matched = 4339 raw,
198 fail** (the 4229 "effective" headline is the CI intersection number).

`results_graphics_previous.json` in every suite is `6de650432` — i.e. the s11
closeout, which is exactly the board provenance s12's wave-1 used. That makes
a **gap-histogram diff across s12** possible, which is how §2 checks refill.

Pixels: `git fetch origin ruffle-image-results` (force-updated to `1bc5e0e91`,
`2026-08-06 10:26:34 +0000` — matches the baseline run's
`generated 2026-08-06T10:26:33Z`, so the extract is the right one), extracted
to scratch, then

```
python3 scripts/image_triage.py --images-dir <scratch>/image-results --jobs 4 \
    --out <scratch>/board.json --markdown <scratch>/board.md
```

278 live failing comparisons (568 total, 286 pass, 279 fail, 3 skip,
5 no_render; 4 HARD-dispositioned excluded, 8 SOFT trace-axis flags kept per
playbook §3).

Every candidate below was cross-checked against `ruffle-tests/ignored_tests.txt`,
the 8 per-suite `ignored_tests.txt`, and the four AVM1 disposition docs
**before** being costed.

---

## 2. Near-pass "closed inventory" — spot-verified, CONFIRMED

36 rows at gap ≤ 5 (gap = `max(expected−matching, actual−expected)`), of which
**13 are ignore-listed**. The 23 live rows, fully accounted:

| owner | rows |
|---|---|
| dual-VM / multi-SWF child execution arc | `mixed_avm/{avm2_loads_avm1_loads_into_root, avm2_loads_avm1_v9, avm2_loads_avm1_loads_avm2_doabc, avm2_loads_avm1_doabc, avm2_loads_avm1_v10, avm1_loads_avm2}`, `avm2/{mouse_pick_avm1_root, selection_onsetfocus_mixed_avm}`, `avm1/shared_stack` — **9** |
| loader arc tranche 6 | `from_shumway/as3-loader/{LoaderTest2, LoaderLoadBytesTest}` — **2** |
| RUFFLE_VS_FLASH, **not** ignore-listed (decoys) | `avm2/loader_load`, `avm2/bom` — **2** |
| documented ceiling | `from_avmplus/recursion/pcre_find_fixedlength` — **1** |
| other declared arcs | `from_avmplus/regress/bug_483783` (dependent-string reclamation, s10 B7 "architecturally blocked"), `avm2/{scope_optimizations, method_association}` (abc-verifier lattice), `avm2/verify_method_info_duplicate` (s11 hard oracle conflict), `audio/g711` (see §4.2) — **5** |
| input arc | `text/links_in_scrolled_text` (H rider; needs a wrap-aware line enumerator in `ng_shared.c`) — **1** |
| s12 wave-2, tried and reverted | `from_shumway/acid/acid-morph` (w2-singles: got 1 of 2 lines; line 4 needs a recompiler change) — **1** |
| genuinely live, low-confidence (s12's own list) | `avm1/remove_different_level`, `from_shumway/bitmapdata/getpixel-from-embedded` — **2** |

**Refill across s12 = 2 rows, both already-known arc rows.** The full
still-failing gap-improvement list between `6de650432` and `1f8396f57` is
exactly `avm2_loads_avm1_v9` 6→1 and `avm2_loads_avm1_v10` 5→3. Nothing else
in the corpus moved into the ≤5 window. **Stop mining this window** stands.

Spot-checks run locally at HEAD (all still fail, all for the stated reason):

- `avm1/remove_different_level` — expected `_level1.mc / onUnload / undefined`;
  we stop after `onUnload`. One trailing `undefined`. **CONFIRMED live.**
- `avm2/scope_optimizations` — `With coerce:` expects `[class field]`, we give
  `0`. **CONFIRMED**, and abc-verifier-arc §3.3 explicitly says NOT in scope.
- `from_shumway/bitmapdata/getpixel-from-embedded` — `200d04` vs `220a06`,
  lossless decode rounding. **CONFIRMED**, unchanged since s11.
- `avm2/loader_load` / `avm2/bom` — see §4.3.
- `audio/g711` — see §4.2.

### 2.1 Silent gap worsenings across s12 (the `transition-diff` trap)

Only four rows got worse while still failing, so CI's pass→fail check saw
nothing. None is a real regression, but one deserves a look:

| test | gap | note |
|---|---|---|
| `avm1/global_instance_decls` | 732 → **745** | `actual_lines` 786 → **815** (+29), `expected` unchanged at 758. s12 added 29 lines of AVM1 global instance declarations. Globally ignore-listed, so invisible to filtered results. Probably w2-avclasses spillover; **worth one grep to confirm the new lines are legitimate, not spam.** |
| `avm2/all_classes/events/swf30` | 2352 → 2353 | suite-ignored, +1 line |
| `avm2/all_classes/events/swf9` | 1028 → 1029 | suite-ignored, +1 line |
| `avm2/textblock_recreateline` | 58 → 59 | already known-failing after w2-errframes (that report §"still fails") |

`avm2/textblock_line_changes` is now `ruffle_matched` — the s12 bisect
(upstream rewrote the test, `expected_lines` 158→282) holds.

---

## 3. §13.3 trace board — per-lead audit

| §13.3 lead | verdict at HEAD |
|---|---|
| **T7 describeType — largest mechanism, 24 live tests, ~6800 lines** | **CONFIRMED on test count, WRONG on lines.** Exactly 24 live rows (`all_classes/*` 20 after the 5 suite-ignored `events/*`, plus `describe_type_{basic,json,metadata,native}`). Live `expected−matching` totals **17,715 lines**, ~2.6× the quoted ~6800. `all_classes/display/*` alone is 15,315. Still the biggest mechanism; the doc-first framing is right. |
| **`loaderinfo_quine` — 1004 lines, LoaderInfo.bytes** | **CONFIRMED.** 1005 expected / 2 actual / 1 matching. Skipped by s12 w2-xs as arc-sized (needs root-SWF byte embedding in `verify_output.py`). |
| **ImportAssets fetch-queue one-liner (+1, `action.c:34563` `entry==NULL` early return)** | **CONFIRMED in substance, STALE line number.** The early return is now `action.c:34580` (`actionImportAssets`, declared at 34576); 34563 is now inside the MCL progress helper. Target test is `import_assets/avm1_non_swf_import` (3/6/0): expected opens with a `Navigator::fetch: / URL: dummy.png / Method: GET` block we never emit. |
| **`mixed_avm/avm2_loads_avm1_v9` one line from pass (dual-VM arc)** | **CONFIRMED and improved**: 6→1 during s12 (8 expected / 7 actual / 7 matching). |
| **`advance_u16` recompiler s16→u16, solved-but-unshipped (generated-ABI reach)** | **CONFIRMED still failing** on the pixel axis: `visual/fonts/advance_u16` `same_geometry_wrong_fill`, excess 216, ink IoU 0.92. |
| **C3b MethodInfo-N naming needs ABC `debug_name` modeling** | not re-verified (recompiler item, no cheap probe). |
| **s11 hygiene never applied: ignore-list recs for `avm2/{loader_applicationDomain, swz}`** | **ALREADY APPLIED** — both are now in `avm2/ignored_tests.txt` (they show `IGN` in the scan). §13.3 is stale here. The still-unapplied recs are `verify_method_info_{duplicate,oob}` (s12 recommended them; neither is in any ignore list). |
| **`visual/definefont4`** (not on §13.3) | The only trace failure in the `visual` suite and a `blank_render` on the pixel axis (excess 16086). Single root cause: one uncaught `#1009 … (accessing field: getEffectiveLineHeight)` from `flashx.textLayout.compose::TextFlowLine/getLineLeading()`. **NOT a cheap win** — `fte-arc.md` §T3 already owns it and gates it behind T1+T2 (~30 TLF classes / ~35 members must all exist and be type-correct). Recording it because §13.3 omits it and it looks deceptively like a one-null-field fix. |

---

## 4. §11 pixel board — per-disposition audit

### 4.1 Cluster deltas s11-closeout → s12-closeout

302 live failing comparisons → **278**. Nothing worsened (s12's
`image_status_diff` accounting holds); the interesting movement is
*reclassification upward*:

| cluster | s12 board | now | note |
|---|---:|---:|---|
| `hairline_edge_drift` | 56 | **66** | +10 — improved comparisons falling into the near-pass/AA cluster, as designed |
| `same_geometry_wrong_fill` | 54 | **37** | −17 (acid clipDepth + filters) |
| `extra_element` | 30 | **14** | −16 (masks) |
| `diffuse_mixed` | 24 | **30** | +6 (filters landing here post-fix) |
| `blank_render` | 53 | **50** | −3 (dynamic-bitmap cap) |
| `halo_penumbra` | 17 | **13** | −4 |
| everything else | 68 | 68 | flat |

### 4.2 Disposition verdicts

| §11 disposition | verdict |
|---|---|
| **fonts near-pass family (height / match_style / glyph / duplicate_font) = 1–5 px AA stair-step ties, capped like blend_modes** | **CONFIRMED.** All four are `hairline_edge_drift`, `why = 100% on edges, 0% survives erosion, ink IoU 1.00`, excess **3 / 6 / 12 / 12** channels (1–4 px). Keep capped. |
| **frame-phase channel exhausted** | **CONFIRMED.** The regenerated board prints **no frame-phase section at all**. |
| **quality / MSAA axis closed** | **CONFIRMED, no contradiction.** No quality-gated comparison sits near-pass; the two `acid-bitmap-draw_quality_{high,low}` rows are identical `blank_render` (excess 194784 each) — a missing `BitmapData.draw` backend, not a quality-gating question, and the `_low` half is upstream `known_failure`. |
| **`simple_shapes/masks` 1686 = rasterizer tie at MSAA=1 — "reclassify hairline_edge_drift, do NOT re-book as mask work"** | **PARTIALLY REFUTED — the reclassification was never encoded.** `image_triage.py` at HEAD still clusters BOTH `visual/simple_shapes/masks` and `visual/simple_shapes/masks_equal_clipdepth` as **`same_geometry_wrong_fill`** (identical excess 1686, mean 0.4727, ink IoU 1.00, "0.4% of pixels repainted"). Since §11 also calls `same_geometry_wrong_fill` the "highest-yield head", every future board regeneration re-surfaces these two rows at the top of the top cluster. The *judgement* holds (0.4% repaint at ink IoU 1.00 is a tie, not a mask defect); the *instrument* does not know it. Fix by disposition entry, not by memory. |
| **acid-blend-2 B-channel halving in the blend composite ("evidence the capped blend_modes rows hide a real bug")** | **REFUTED — see §4.3.** |
| **filters struck from flip leads (shared low-amplitude residual vs 0–18 budgets)** | **CONFIRMED.** The filter family now sits in `diffuse_mixed`/`hairline_edge_drift` at low amplitude; nothing in it is near its budget. |
| **mask defect C (AVM2 scrollRect half) / defect B redesign** | not re-probed (design work, no cheap read). `extra_element` mask/scrollRect rows are unchanged: `simple_shapes/scroll_rect_mask` 434284, `cache_as_bitmap/masks [.03/.04/.06/.07]` 15–26k. |
| **char-id-0 depth sentinel blocks all 5 embedded-video comparisons** | consistent with the board: video comparisons remain `blank_render` / `unrelated_content` in the catastrophic band. Not re-probed. |

### 4.3 Two refutations, with evidence

**(a) `acid-blend-2` is NOT a B-channel halving — it is exactly ONE stray
un-blended pixel per frame.**

`from_shumway/acid/acid-blend-2` has 5 comparisons; 3 already pass, and the two
failures each carry `excess_outliers = 1`. The test's `test.toml` uses paired
checks — `output.15` is `(tolerance 20, max_outliers 6000)` + `(tolerance 135,
max_outliers 0)`; `output.26` is `(tolerance 20, max_outliers 6000)` +
`(tolerance 120, max_outliers 0)`. The wide check passes. **What fails is a
single pixel over the strict check:**

- `output.15` at (374, 203): expected `(114,105,51)`, we render `(255,0,51)` — max channel diff **141** vs a 135 budget. One pixel at 140 < d ≤ 141; at T=141 the count is 0.
- `output.26` at (153, 282): expected `(102,140,178)`, we render `(229,235,242)` — max channel diff **127** vs a 120 budget. One pixel; at T=127 the count is 0.

Both look like an isolated pixel that escaped the blend and kept a raw source
colour. I tested and **refuted** the two obvious global hypotheses:

- *1-px shift*: mean |diff| **worsens** at every offset (`output.15` baseline
  2.963 → 3.209/3.257 at dx=∓1, 3.513/3.518 at dy=∓1; `output.26` baseline
  2.224 → 2.488/2.536/2.612/2.611).
- *B-channel halving*: per-channel act/exp ratios over the differing pixels are
  R 1.026 / G 0.981 / B 0.985 (`output.15`) and R 1.046 / G 1.006 / B 1.017
  (`output.26`) — no channel is scaled.

So the ~28k/45k *differing* pixels are the same low-amplitude blend residual
that keeps the capped `blend_modes` rows capped, and the two failures are
**two single pixels**. This makes the row much cheaper than the board thinks
(+2 comparisons) *and* removes the board's stated reason for re-opening the
capped blend rows.

**(b) `audio/g711` is not an A-law/µ-law codec item.** Local run:

```
 3  PASS                                  ->  TypeError: Error #1006: computeSpectrum is not a function.
                                              	at Function/<anonymous>()
```

`Test.as` calls `SoundMixer.computeSpectrum(ba)` and then does a full
Goertzel-style measurement over 2×256 floats, checking phase, channel match,
wave reconstruction to 0.05, and an amplitude window of [0.95, 1.05]. That
needs a real mixed-audio tap with Flash's "every second sample" stretch bug —
an audio-backend arc, not decoding. Same blocker for `audio/aac` (24/18/3);
the third user, `avm2/audio_computespectrum`, is already suite-ignored.
`polish-sweep-arc.md:162`'s "A-law/µ-law FLV" framing should be corrected.

**(c) `avm2/loader_load` + `avm2/bom` are dispositioned decoys.** I costed them
as a clean "+2, one mechanism, reverse-insertion enumeration order" lead before
checking dispositions — `loader_load` expects `cccc=true&aaa=bbb` from
`vars.aaa` then `vars.cccc`; `bom` expects `firstName=Tom&lastName=Jones` from
a `lastName`-first fixture. Both are already ruled in
`RUFFLE_VS_FLASH_DIFFERENCES.md` §304–356: Ruffle's AVM2 dynamic properties
live in an FNV `hashbrown` table and enumerate in bucket order; we and Flash
use insertion order; `loader_load` is accepted at 126/128 and `bom` at a 6/9
ceiling. **Neither is in any `ignored_tests.txt`**, which is why they sit at
gap 2 and gap 3 — the two cheapest-looking rows in the corpus — on every
regeneration. This is the `accepted-diffs-first` rule earning its keep.

### 4.4 Comparisons the pixel board does not account for

| comparison | cluster / excess | why it's unaccounted |
|---|---|---|
| `visual/drawing_api/cursor` | `missing_element`, 200 | See L4. Not named in §11 or in the s12 `missing_element` breakdown ("4 filters, 4 text, 2 video, 1 gradient"). |
| `avm2/error_stack_trace_release_swf17` | `global_color_shift`, 200 | See L3. The trace side **passes** (0 expected lines), so it is invisible on the trace board. |
| `visual/simple_shapes/overlaps` | `diffuse_mixed`, 18 | **6 pixels**, and they are colour *swaps* between two abutting shapes (`(51,255,0)` ↔ `(0,102,204)`) at coincident edges — a z-order tie at an exact boundary. Treat as capped with the AA family; do not book as drawing-order work. |
| `visual/fonts/duplicate_font` / `glyph` / `fonts/embed_matching/match_style` / `text/auto_size/height` | `hairline_edge_drift`, 3–12 | Accounted (§11 fonts cap) — listed here only to confirm the cap is measured, not assumed. |
| `avm1/define_font_glyph_table_order` | `same_geometry_wrong_fill`, 176, ink IoU **0.87** | Low ink IoU means real geometry difference, not AA. Small. Not on the board. Low-confidence candidate, not ranked below. |

---

## 5. Ranked additional leads (7 + 1 hygiene bundle)

Ranked by yield ÷ effort × confidence. **All are additional to §13.3 / §11**
unless flagged. Flip estimates are per-CI-run, at the merged baseline.

### L1 — `from_gnash` `action_order`: nested/sibling clip frame-action order · **+2 trace, riders to +4** · confidence HIGH · effort SMALL-MED

- **Tests.** `from_gnash/misc-ming.all/action_order/action_execution_order_test`
  (19 exp / 18 act / 7 match) and `.../action_execution_order_test11`
  (32/32/26). Riders in the same directory:
  `action_execution_order_test6` (24/20/0),
  `action_execution_order_extend_test` (32/28/7), `ActionOrderTest3` (62/73/4),
  `ActionOrderTest4` (64/105/10), `ActionOrderTest5` (51/58/6),
  `PlaceAndRemove` (96/45/15). None is in any ignore list.
- **Evidence (local, HEAD).** `..._test` — expected
  `as in frame2 of mc_blu` **then** `as in frame2 of mc_red`; we emit
  `mc_red` then drop the `mc_blu` line entirely, positionally poisoning the
  rest (7 of 19 match despite the rest being byte-identical).
  `..._test11` — the two failing assertions are
  `doActionOrder == '0+1+2+3+4+5+'` (we produce `0+2+1+3+4+5+`) and
  `asOrder`, where our sequence interleaves nested clips differently
  (`…6+3+4+8+10+…` vs expected `…6+3+8+4+10+…`). One ordering rule, two tests.
- **Why it's live.** 5 siblings in the same directory already **pass**
  (`test1/2/3/5/7/8-v5/8-v6/9`) and `test4` is `ruffle_matched` — the machinery
  exists; only the sibling/nesting order at one point is wrong.
- **Mechanism.** AVM1 per-frame DoAction dispatch order for nested clips —
  `SWFModernRuntime/src/actionmodern/action.c` frame-action queue +
  `tag.c` display-list walk. Start from the s12 `mc_red`/`mc_blu` case: the
  child's frame-2 action must run before the parent's.
- **Why the boards missed it.** `from_gnash` holds 32 of the 198 corpus
  failures (misc-ming.all 14, actionscript.all 13, misc-swfc.all 5) and s12's
  triage keys (stack frames, `all_classes` family, near-pass window) all
  pointed elsewhere.

### L2 — acid-blend-2: one stray un-blended pixel per frame · **+2 pixels** · confidence HIGH · effort SMALL (diagnosis-first) · **REFUTES a §13.3 claim**

Full evidence in §4.3(a). The two target pixels are
`output.15` (374, 203) exp `(114,105,51)` act `(255,0,51)` and
`output.26` (153, 282) exp `(102,140,178)` act `(229,235,242)`; budgets are
135 and 120, our maxima 141 and 127. A rider should first dump the local
render at those coordinates (Dawn is not lavapipe, so confirm the *shape* of
the artefact, not the exact value) and look for a boundary/degenerate-coverage
case in the blend composite where a fragment writes the source colour
un-blended. Also **strike** the board's "evidence the capped blend_modes rows
hide a real bug" — the channel-ratio test says otherwise.

### L3 — `Error.getStackTrace()` must return `null` in a release SWF · **+1 pixel** · confidence HIGH · effort XS

- **Comparison.** `avm2/error_stack_trace_release_swf17 [output]`,
  `global_color_shift`, excess 200, `signed mean [-255, 0, +255, 0] std 0`.
- **Evidence.** The whole 10×10 stage is expected pure **red** `(255,0,0)`;
  we render pure **blue** `(0,0,255)`. `Test.as` is 20 lines:

  ```
  var st = new Error().getStackTrace();
  if (st === null)      beginFill(0xFF0000);
  else if (st === undefined) beginFill(0x00FF00);
  else                  beginFill(0x0000FF);
  ```

  So we return a non-null stack trace from a **release** build. Gate
  `getStackTrace()` on the SWF's debug flag.
- **Canaries (must not move).** `avm2/error_stack_trace_debug_swf17` and
  `_debug_swf18` currently pass with 0 expected lines; `avm2/error_stack_trace`
  is 45/45/38 and must not get worse. `error_stack_trace_release_swf18` passes
  on trace and has no failing comparison — check whether it has an
  `[image_comparisons]` block before assuming it is unaffected.
- **Note.** Invisible to the trace board: this test's trace side *passes*.

### L4 — `visual/drawing_api/cursor`: a 1-px diagonal hairline is never drawn · **+1 pixel** · confidence HIGH · effort SMALL

- **Comparison.** `missing_element`, excess 200, tolerance 0, quality low.
- **Evidence.** The expected PNG contains exactly **two** 100-px strokes and
  nothing else: a red `(255,0,0)` diagonal from (0,0) to (99,99) and a green
  `(0,255,0)` vertical at x = 99, y = 100…199 — both pure, unantialiased,
  1 px wide. Our render contains **only the green vertical** (ink bbox
  y 100–199, x 99–99, 100 px). The diagonal is dropped entirely.
- **Mechanism.** A hairline (`lineStyle(0, …)`) stroke that is not axis-aligned
  and starts at the stage origin is being culled or degenerating to zero
  coverage. `render_webgpu.c` stroke path / the minimum-width handling
  (cf. the `thin-strokes-no-min-width` fix). Respect the `MSAA_SAMPLES`
  invariant — this comparison is a `quality = "low"` (1-sample) golden.

### L5 — `avm1/remove_different_level`: one trailing `undefined` · **+1 trace** · confidence MED · effort XS

Expected `_level1.mc` / `onUnload` / `undefined`; we stop after `onUnload`
(3 exp / 2 act). A cross-level `removeMovieClip` must leave the follow-up
lookup resolving to `undefined` rather than producing nothing. s12 rated this
"low confidence" without probing it; the diff is now measured and it is a
single trailing line. Cheap enough to attempt inside a bundle. Read
`user-vars-survive-mc-removal` and `removemovieclip-descendant-onunload-defer`
before touching removal.

### L6 — `from_gnash/misc-ming.all/GradientFillTest`: gradient sample position · **+1 trace / +1 pixel (dual-axis)** · confidence MED · effort MED

- **Rows.** Trace 278/278/119 (159 differing lines). Pixel:
  `same_geometry_wrong_fill`, `b_tiny`, excess 858, ink IoU 0.99, mean 1.50.
  **Same mechanism on both axes** — a rare dual-axis row.
- **Evidence.** The test `getPixel`s a 3×3 grid inside each gradient square and
  echoes the values. All assertions still say `PASSED` (the test's own
  tolerance absorbs it) — only the echoed values differ, so the flip needs
  **exact** colour match. Sampled deltas at the same coordinates:
  `0x0b0bff→0x0d0dff (+2)`, `0x7f7fff→0x8181ff (+2)`,
  `0xf4f4ff→0xf5f5ff (+1)`, `0x5a5aff→0x5e5eff (+4)`,
  `0xfffdff→0xfff9ff (−4)`, `0xff59ff→0xff56ff (−3)`,
  `0x4a4aff→0x4c4cff (+2)`, `0x9c9cff→0x9f9fff (+3)`,
  `0xeeeeff→0xf1f1ff (+3)`. **Mixed signs ⇒ not a ramp offset — a sub-pixel
  sampling-position difference**, i.e. where in the gradient's matrix space we
  evaluate each pixel centre.
- **Prior art to read first (do not redo it):**
  `gradient-banding-is-subpixel-phase-not-ramp` — the focal-point Fixed8
  truncation and the `clamp(t*256-0.5, 0, 255)` ramp index are already fixed.
  This is a `DefineShape` gradient (Ming), not the drawing API, so the
  remaining suspect is gradient-matrix quantization (see
  `ruffle-geometry-is-integer-twips`: quantize first).
- **Risk.** Any change here touches every gradient comparison; run the full
  `render_canary` and expect to justify each md5 move.

### L7 — `import_assets` pair · **+1 trace now, +1 more at MED** · confidence HIGH (first half) · effort XS + MED

Board §13.3 already names the one-liner; this entry corrects it and adds the
measured second half.

- **`avm1_non_swf_import` (+1, XS).** Queue a `swf_log_fetch` GET on the
  `entry == NULL` early return in `actionImportAssets` — **`action.c:34580`,
  not 34563** (the function opens at 34576; 34563 is now inside the MCL
  progress helper). Expected output opens with
  `Navigator::fetch: / URL: dummy.png / Method: GET`; we emit only
  `frame 1 / frame 2 / frame 3`.
- **`avm1_imports_avm1` (+1, MED).** Measured locally: our output is the
  expected output with **exactly one extra line prepended** —
  `Hello from right_eye.swf`. The donor SWF's own frame script must not run.
  The fix lands inside `actionImportAssets` (`action.c:34576-34611`), whose
  frame-0 replay is load-bearing for imported-sprite bounds — s12 w2-xs
  correctly refused to put this in an XS bundle. It is a clean standalone task
  with an obvious canary (`import_assets/empty_url`, which passes).

### L8 — disposition hygiene bundle · **0 flips, removes 4 permanent decoys** · confidence HIGH · effort XS

Not a flip lead; it is the cheapest way to stop future sessions re-costing the
same rows. Each needs a doc entry *first*, then an `ignored_tests.txt` line
(per CLAUDE.md).

1. **`avm2/loader_load` (gap 2) and `avm2/bom` (gap 3)** — fully dispositioned
   in `RUFFLE_VS_FLASH_DIFFERENCES.md` §304–356, in **no** ignore list. They
   are the two cheapest-looking rows in the corpus and are unwinnable. Highest
   value item in this bundle.
2. **`avm2/dependent_strings` (84/83/46, 38 differing lines)** — **new
   disposition, not documented anywhere.** `Test.as` calls
   `text.ruffle::isDependent()` under `namespace ruffle = "__ruffle__"`, i.e.
   a **Ruffle-internal debug API that exposes Ruffle's rope-string
   representation**. Flash has no such method. Our engine throws, the test's
   `catch` traces a blank line, and every boolean row blanks. Matching would
   mean replicating Ruffle's internal string-dependency model.
   → `RUFFLE_VS_FLASH_DIFFERENCES.md` (or ACCEPTED_DIFFS) + ignore list.
3. **`avm2/verify_method_info_duplicate` (gap 1) and `verify_method_info_oob`
   (gap 4)** — s12 recommended ignore-listing both after s11 ruled the
   `method_info` verifier a hard oracle conflict with a passing sibling. Still
   unapplied; §13.3's "s11 hygiene never applied" line names the wrong pair
   (`loader_applicationDomain`/`swz` are already done).
4. **`visual/simple_shapes/masks` + `masks_equal_clipdepth`** — encode the s12
   "rasterizer tie, do NOT re-book as mask work" ruling as a real disposition
   so `image_triage.py` stops ranking them at the head of
   `same_geometry_wrong_fill` (§4.2).
5. **Two stale entries the regenerated board flags**:
   `avm1/display_object_properties` now **passes** (its ACCEPTED_DIFFS entry is
   stale), and the `from_gnash .../loop/simple_loop_test` entry is scoped to
   frames 1–2 which now pass. One line each.

---

## 6. Unresolved discrepancy worth one look

**`from_gnash/misc-swfc.all/gotoFrameFromInterval2`: local says
`RUFFLE_MATCHED`, CI at `1f8396f57` says `output_mismatch` (23/24/2).**
The test dir carries `known_failure = true` and an `output.ruffle.txt`, and
locally our output matches that oracle. The upstream test dirs are downloaded,
not tracked, so I cannot tell from git whether CI had the same
`output.ruffle.txt`. Either (a) the local oracle file is stale/differently
generated, or (b) this is a free +1 effective on the next CI run. Cheap to
settle by checking how the CI job materializes `output.ruffle.txt`; worth
settling because "ruffle_matched appearing/disappearing" is exactly the
`ruffle-matched-hides-regression` trap in reverse.

---

## 7. Reproduction

```bash
# trace: dedup'd near-pass + gap-histogram diff vs results_graphics_previous
#   (scratch scripts: nearpass.py, gapdiff.py, shift.py)
# excluded stale nested stems: from_avmplus/as3/Vector{,/nonindexproperty},
#   from_gnash/misc-ming.all/displaylist_depths, from_shumway/timeline
#   and the from_shumway/avm1 double-count

# pixels
git fetch origin ruffle-image-results
git archive origin/ruffle-image-results | tar -x -C <scratch>/image-results
python3 scripts/image_triage.py --images-dir <scratch>/image-results --jobs 4 \
    --out <scratch>/board.json --markdown <scratch>/board.md

# per-test local probes (5-way parallel, ~2 min each incl. compile)
python3 ruffle-tests/verify_output.py --tests-dir ruffle-tests/tests/swfs/<suite> \
    --test=<name> --diff -v
```

Tests run locally this session: `avm2/{dependent_strings, bom, method_association,
loader_load, supercalls_coerce, scope_optimizations}`,
`from_gnash/misc-ming.all/{GradientFillTest, action_order/action_execution_order_test,
action_order/action_execution_order_test11}`,
`from_gnash/misc-swfc.all/gotoFrameFromInterval2`,
`from_shumway/{acid/acid-shapes-testing, bitmapdata/getpixel-from-embedded}`,
`avm1/remove_different_level`, `import_assets/avm1_imports_avm1`, `audio/g711`.
`visual/definefont4` hit the local 300 s compile cap (a FALSE fail under load —
`parallel-triage`); its CI record supplied the evidence instead.
