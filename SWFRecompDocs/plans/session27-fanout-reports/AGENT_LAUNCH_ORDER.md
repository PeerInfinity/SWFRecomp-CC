# Session 27 — worker launch-order / id map

Mode: CLOUD-FIRST (standing user directive): every slot is a cloud session in env "SWFRecomp fan-out"
(`env_01QSs9FrDsLyis2RzQXg1UrW`), Opus, delivering on branch `fanout/<slug>`. Coordinator `s27-coordinator` local
(merge, CI dispatch, results accounting, exporter oracle `0ddd12b6a`). Size: full.
Baseline: s26 record pair at code `005bea42a` — graphics/full/images `45284922078` (results `df7729df2`) + no-graphics/full
`45284938521` (results `81d32b9b2`). Read at `df7729df2`: trace 4684 eff / 4722 rows (38 failing); pixels 593 / 637.
Wave 0: local N `n-trap-stroke` landed `d70f2c0aa` (recompiler stroke line-style-id order + 2 fixtures) and dispatched
graphics/full/images `45300086369` before the handshake; graded as wave 0.
Upstream `3e98d9ba6..1e604fa87` (14 commits) → w1-drift.

## Wave 1 (diagnosis, cloud)

| # | slug | axis | task | session id |
|---|---|---|---|---|
| 1 | w1-drift | | `briefs/w1-drift.md` | session_018CoDi5N4PDwSYRb1BtcpsX — DELIVERED; prototype LANDED `d3b6d71b8` (px `avm2/pixelbender_dithering` 34301→9413, Flash golden; bitmapdata-clone 0 headroom; allow_networking NO-GO priced) |
| 2 | w1-applyfilter-tail | | `briefs/w1-applyfilter-tail.md` | session_018CoDi6BdM94P49fXHBfsXH — DELIVERED; prototype LANDED `456fef1bf` (0 status moves; exact GPU blur taps for pure BlurFilter; AVM1 convolution-not-CM fixture) |
| 3 | w1-text-wordwrap | | `briefs/w1-text-wordwrap.md` | session_018CoDi7dhY9K6fob9XQQ7hN — DELIVERED; 0 corpus (family AVM1-only, empty); prototype → w2-avm1-text-layout; fixture Flash-INVALID font |
| 4 | w1-text-glyph-fidelity | | `briefs/w1-text-glyph-fidelity.md` | session_018CoDi52c6j8TsgB2hBfqvM — DELIVERED; prototype LANDED `0494cd927` (0 corpus; DefineText T·G recompiler, AVM2 box cx + BORDER bg; fixtures avm2_edittext_placed_cxform, avm1_definetext_matrix) |
| 5 | w1-render-bitmap-leads | | `briefs/w1-render-bitmap-leads.md` | session_018CoDi4Ezx7K9RU17RnJauX — DELIVERED; prototype LANDED `202340a12` (+2 px `shader_as_mask`, `acid-color-0`; holder drawing fixture Flash-confirmed) |
| 6 | w1-per-movie-dl-phase3 | | `briefs/w1-per-movie-dl-phase3.md` | session_018CoDi5Y59Hqp3qwXLspLmJ — DELIVERED; → w2-loaded-shell-land (phase 3 GO, gate 268+112 identical; Flash delivery one tick later) |
| 7 | w1-browser-avm1-gaps | | `briefs/w1-browser-avm1-gaps.md` | session_018CoDi3xhg3Ln18HCEQsD5g — DELIVERED; NOT landed: real-browser probe partial (getBounds, color still fail) → local browser-arms-land |
| 8 | w1-avm1-leftovers | | `briefs/w1-avm1-leftovers.md` | session_018CoDi6RWXyLdLEJhQj9e9Q — DELIVERED; → w2-avm1-leftovers-land (Flash refutes 5 analytic goldens) |
| 9 | w1-timers-robustness | | `briefs/w1-timers-robustness.md` | session_018CoDi67YHojVBN6gBU6L2N — DELIVERED; → w2-timers-land (+1 trace InitActionTest2 priced) |
| 10 | w1-exec-order | | `briefs/w1-exec-order.md` | session_018CoDi3kpoY381JK8xx3ueY — DELIVERED; → w2-exec-order-land (Flash == Ruffle on both fixtures; nested-frame order gap) |

## Wave 2 (implementation, cloud) + local slots

| slug | from | ledger (expected) | session id |
|---|---|---|---|
| w2-layer-alpha-group | Flash capture n3_layer_alpha | fixtures (Flash golden); priced Ruffle-golden losses | session_018CoDi4H4DqA4qwhbCgk45g — DELIVERED, LANDED `fb6fe4ba4` (0 corpus; 2 Flash-golden fixtures; Flash probes: filters/blend/aoffset group, cAB does not) |
| w2b-group-alpha-triggers | w2-layer-alpha-group + Flash probes | corpus filter/blend rows will move | session_018CoDi5TpfA7P8yRuUGbTVQ — DELIVERED, LANDED `78fee9e13` (10 Flash fixtures; 8 extra Flash probes confirm grouped model) |
| w2-flash-filter-kernels | Flash captures glow_kernels/draw_filtered | 2 fixtures (Flash trace) | session_018CoDi5rf6MrkHLk3QibWyX — DELIVERED, LANDED `cceb5133a` (source; glow 16/23, draw_filtered 11/13 vs Flash; fixtures held; applyfilter_blur Ruffle golden 39351→47515 priced) |
| w2-jpeg-flash-decode | w1-drift lead 1 | headroom on 2 Flash-golden rows | session_018CoDi66FA1hXSXXAwLB8kW — DELIVERED, HELD: IJG v7+ model bit-exact on clone, 27 on dithering, +1 getpixel; but Flash 32 BitmapDataDraw = 82944 (stb flat) contradicts → w2b-jpeg-refine |
| w2b-jpeg-refine | w2-jpeg-flash-decode + Flash oracles | refined decoder or NO-GO | session_018CoDi3cn6pb1EqGj5vDUvC — DELIVERED, LANDED `31d3e3237` with w2-jpeg-flash-decode (+1 trace getpixel-from-embedded; clone bit-exact vs Flash; acid-color-0 priced Flash-over-Ruffle loss) |
| w2-allow-networking-subtests | w1-drift §3 | NEW subtest rows | session_018CoDi4rozCuYyCVd6iWznD — DELIVERED, LANDED `d37ca69b5` (+8 NEW trace rows, all pass both modes) |
| w2-draw-cx-text | w1-text-glyph-fidelity §4 | 2 fixtures (Flash trace) | session_018CoDi5MC3ifTEYbRy5fxSf — DELIVERED, LANDED `85cca4df6` (2 Flash-golden fixtures; embedded-field tint → w2b-draw-text-tint) |
| w2-applyfilter-cm | w1-applyfilter-tail items 3, 5 | 3 CM fixtures (Flash PNG) | session_018CoDi4dFuVDgVxQdWMdvo7 — DELIVERED, LANDED `cceb5133a` (AVM1 applyFilter bridge; 3 Flash-golden CM fixtures + kernels fixture) |
| w2-holder-drawing-full | w1-render-bitmap-leads §1/1b | fixture (hand == Flash) | session_018CoDi6o54ceV3pKjPBKyS1 — DELIVERED, LANDED `c2f237a94` (0 corpus; 2 Flash-golden fixtures) |
| w2-avm2-text-tail | w1-text-glyph-fidelity §2b, 5 | fixture avm2_definetext_matrix (== Flash) | session_018CoDi48vpYNmCMWk66aLEA — DELIVERED, LANDED `c2f237a94` (0 corpus; avm2_definetext_matrix == Flash; DefineFont4 CFF data; selection tint HOLD) |
| w2-avm1-text-layout | w1-text-wordwrap + glyph §1 | fixtures (Flash) | session_018CoDi6dEUJbfDeuFy5EEvU — DELIVERED, LANDED `c2f237a94` (0 corpus; scaled_glyphs Flash golden; wordwrap font fixed for Flash, interim Ruffle PNG golden) |
| w2-avm1-leftovers-land | w1-avm1-leftovers | fixtures re-targeted to Flash | session_018CoDi5K5YhaAgXDJHqPMyp — DELIVERED, LANDED `85cca4df6` (Flash direct-mode goldens; 8 rows) |
| w2-timers-land | w1-timers-robustness | trace `InitActionTest2` +1; timer fixtures (Flash only) | session_018CoDi6CHnwMMMavVzvAyco — DELIVERED, LANDED `cceb5133a` (+1 trace InitActionTest2; 11 fixtures; NG code) |
| w2-exec-order-land | w1-exec-order | 2 fixtures (Flash); nested-frame order | session_018CoDi4AMuRxHCCPT8zNJJ7 — DELIVERED, LANDED `78fee9e13` (NG code; 2 Flash-golden fixtures; nested frames before Phase 1) |
| w2-loaded-shell-land | w1-per-movie-dl-phase3 | 3–6 fixtures (Flash prefix) | session_018CoDi7GWpU4jrHWENpzHVk — DELIVERED, LANDED `78fee9e13` (full delivery-tick patch; Flash confirms 3 of 5 re-goldened fixtures exactly, the other 2 move toward Flash; merged by hand with timers' growable queue) |
| w2b-timers-tail | w2-timers-land + Flash init-flush probe | init flush at call return; MAX_TICKS; queues | session_018CoDi5hmHyLYhYb9rCdGqq — DELIVERED, LANDED `78fee9e13` |
| w2b-avm1-applyfilter-flash | w2-applyfilter-cm + 8 Flash captures | AVM1 applyFilter kinds + CM live no-snap | session_018CoDi6Wn2mhRQxeVrpZw3T — DELIVERED, LANDED `78fee9e13` (4 Flash fixtures; CM live goldens → Flash) |
| w2b-filter-kernels-residual | w2-flash-filter-kernels + Flash gradient probe | held fixtures, gradient kernels, GPU growth, blur disposition | session_018CoDi4YkJ5WVk6w3oD8vUD — DELIVERED, LANDED `78fee9e13` (held fixtures landed green; gradient kernels) |
| w2b-draw-text-tint | w2-draw-cx-text + Flash embed/device verdicts | embedded box/glyph tint; child_color fixture | session_018CoDi3usm8aPaCUzdZcrkH — DELIVERED, LANDED `8f4f6e395` |
| w2b-avm1-text-edit | w2-avm1-leftovers-land + Flash | setNewTextFormat instance, maxChars onChanged, depth gate fixtures | session_018CoDi5Yb9rgWbo4fjZ2XdZ — DELIVERED, LANDED `c72303e75` |
| w3-interim3-regressions | interim #3 | fix 3 regressions | session_018CoDi5x8FTzvRpNuCpJu1B — DELIVERED, LANDED `8f4f6e395` (3 regressions fixed; test12 = Flash-ward reclassification) |
| w3-drift-2 | upstream 4 test commits | malformed AVM1 + isPlaying rows | session_018CoDi7Cq4ikQibszfeYYsJ — DELIVERED, LANDED `8f4f6e395` (6 upstream rows + swf13 pass) |
| local `browser-arms-land` | w1-browser-avm1-gaps + real-browser probe | browser-only (0 CI) + TextField getBounds undefined (CI-visible) | DONE `91418ebbe` (REPORT BACK verified); successor local `browser-eager-init` launched; launched ~02:47 UTC, cwd verified, handshake sent |

## N ladder (local one-task sessions)

- `n-trap-stroke` DONE (report `5eeda6444`, code `d70f2c0aa`; REPORT BACK verified on disk): trap switch = Ruffle
  tessellation-cache artifact (Flash rule kept); exit-door = strokes in line-style-id order (fixed); fixtures pass in CI.
- `n-ragdoll-strokes` launched 2026-11-24 ~01:45 UTC (run.S7bGuoXf, cwd verified, handshake sent): ragdoll Drawing-API
  thin strokes under scale, then the native residual (fps counter, edge px). CI folded into the coordinator's runs.
- `n-ragdoll-strokes` DONE (`438121c22`; REPORT BACK verified): shot-1560 class = attachMovie'd clip's timeline children parented to _root (not ragdoll/strokes); fixture `avm1_attached_clip_timeline_child_parent`.
- `n-l2l4-pixel-pass` launched ~03:05 UTC (cwd verified, handshake sent): L2/L4 native pixel pass, goto-rebuild _root fallback.
- `browser-eager-init` DONE `fe6eb5f9d` (REPORT BACK verified) → `browser-advance-order` launched.
- `n-l2l4-pixel-pass` DONE `f5565dcf9` (attached self-goto, AVM1 tab stops, _xscale double, MC-as-ASObject setter bug) → `n-levels-5plus` launched.
- `golden-provenance` (Robert's request via s26-coordinator) DONE `ae4a46c74`: 389 image tests / 596 comparisons vs Flash 32 → `golden-provenance-2` launched.
- `flash-oracle` (launched by s26-coordinator at Robert's request): real Flash Player 32 oracle; captures come to s27.

## Grading runs

| run | mode / categories / images | code | result |
|---|---|---|---|
| 45300086369 | graphics / full / images (wave 0, dispatched by n-trap-stroke) | d70f2c0aa | **exact**: trace 4684 eff on the 4722 intersection, 0 moves; +2 new fixture rows pass (4686 / 4724); pixels 0 moves, 0 band moves (595 / 639 summed incl. the 2 fixtures). Results `da51f878f` |
| 45312833576 | graphics / full / images (interim #1) | b8d3b736a (drift, glyph-fidelity, applyfilter-tail, render-bitmap-leads, html_typed_runs fixture; Pages dry run 45312837356 success) | **exact**: trace 0 moves on the 4724 intersection, +5 new fixture rows pass (4691 / 4729 eff); pixels +3 by name (`pixelbender_dithering`, `acid-color-0`, `shader_as_mask`), +3 new fixture images pass, 0 regressions, 0 band moves. Results `a0e485e5f` |
| 45339607994 / 45339610962 | graphics full images / no-graphics full (interim #2) | cceb5133a (allow-networking, layer-alpha, text-layout, holder-full, avm2-text-tail, timers, filter-kernels, applyfilter-cm, n-ragdoll 438121c22, browser-arms 91418ebbe; Pages dry run 45339614012 FAILED: bundle snapshot lacked avm1_filter_kernels.c, fixed 1994a761f) | **exact both modes**: graphics 4691 → 4692 on the 4729 intersection (+1 `InitActionTest2` ruffle_matched → pass), 34 new rows all pass (8 allow_networking variants + fixtures) → **4725 / 4763 eff**; pixels 0 flips, 1 priced band move (`bitmapdata_applyfilter_blur` 39351 → 47515, Ruffle golden), 11 new fixture images pass, 0 regressions. No-graphics 4723 / 4763 (same +1), mode diffs only `audio/aac`, `audio_computespectrum`. Results `dc5d2936a` / `9e6d2a9bd` |
| 45434403230 / 45434410378 | graphics full images / no-graphics full (interim #3) | 78fee9e13 (+ leftovers/draw-cx 85cca4df6, loaded-shell, exec-order, w2b group-alpha/timers/applyfilter/kernels, n-l2l4 f5565dcf9, browser-eager fe6eb5f9d; Pages dry run 45434415667 success) | **3 regressions (both modes)**: `avm1/globals_monkeypatch` output_mismatch → SEGFAULT; gnash `action_execution_order_test12` ruffle_matched → output_mismatch; new fixture image `avm1_attached_clip_selfgoto_child_parent` FAIL → w3-interim3-regressions. Otherwise exact: 39 new rows pass; 6 new UPSTREAM rows (drift `9a8618af1`, `2c6d3c4fe`, `31d5a45e5`, `d607dca2e`: 3 malformed_actions output_mismatch, 3 avm2 goto isPlaying ruffle_matched) → w3-drift-2. Graphics 4766 / 4808 eff, NG 4764 / 4808; mode diffs only `audio/aac`, `audio_computespectrum`. Pixels: 15 new fixture images pass, 0 corpus moves. Results `462180afb` / `bb7776d79` |
| **45536913308 / 45536916402 (FINAL)** | graphics full images / no-graphics full | 8f4f6e395 (+ JPEG 31d3e3237, avm1-text-edit c72303e75, w3-interim3-regressions, w3-drift-2, draw-text-tint, browser-advance-order, browser-parked-frame, n-levels-5plus, swapDepths 8350ca120; Pages dry run 45536919691 success) | **exact, 0 regressions**: vs interim #3 +9 by name (globals_monkeypatch SEGFAULT → its documented output_mismatch; 3 malformed_actions, getpixel-from-embedded → pass; 4 avm2 goto rows rm → pass), 11 new rows pass. vs baseline: eff +1 −1 on the intersection (getpixel; test12 Flash-ward == fp9), 97 new rows all pass → **4781 / 4819 eff** (graphics), **4779 / 4819** (NG; mode diffs only audio/aac, audio_computespectrum). Pixels **626 pass / 39 fail**; vs baseline +2 (pixelbender_dithering, shader_as_mask), 0 regressions, 35 new comparisons pass; acid-color-0 vs interim #3 pass → fail = priced JPEG loss (RvF). Results `cb14cd063` / `2e286cf2f`, merged `14e1427a1`. Pages REAL deploy 45544079631 |
