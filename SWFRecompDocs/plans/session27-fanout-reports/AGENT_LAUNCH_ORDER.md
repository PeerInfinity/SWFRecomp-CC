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
| w2-layer-alpha-group | Flash capture n3_layer_alpha | fixtures (Flash golden); priced Ruffle-golden losses | |
| w2-flash-filter-kernels | Flash captures glow_kernels/draw_filtered | 2 fixtures (Flash trace) | |
| w2-jpeg-flash-decode | w1-drift lead 1 | headroom on 2 Flash-golden rows | |
| w2-allow-networking-subtests | w1-drift §3 | NEW subtest rows | |
| w2-draw-cx-text | w1-text-glyph-fidelity §4 | 2 fixtures (Flash trace) | |
| w2-applyfilter-cm | w1-applyfilter-tail items 3, 5 | 3 CM fixtures (Flash PNG) | |
| w2-holder-drawing-full | w1-render-bitmap-leads §1/1b | fixture (hand == Flash) | |
| w2-avm2-text-tail | w1-text-glyph-fidelity §2b, 5 | fixture avm2_definetext_matrix (== Flash) | |
| w2-avm1-text-layout | w1-text-wordwrap + glyph §1 | fixtures (Flash) | |
| w2-avm1-leftovers-land | w1-avm1-leftovers | fixtures re-targeted to Flash | |
| w2-timers-land | w1-timers-robustness | trace `InitActionTest2` +1; timer fixtures (Flash only) | |
| w2-exec-order-land | w1-exec-order | 2 fixtures (Flash); nested-frame order | |
| w2-loaded-shell-land | w1-per-movie-dl-phase3 | 3–6 fixtures (Flash prefix) | |
| local `browser-arms-land` | w1-browser-avm1-gaps + real-browser probe | browser-only (0 CI) | |

## N ladder (local one-task sessions)

- `n-trap-stroke` DONE (report `5eeda6444`, code `d70f2c0aa`; REPORT BACK verified on disk): trap switch = Ruffle
  tessellation-cache artifact (Flash rule kept); exit-door = strokes in line-style-id order (fixed); fixtures pass in CI.
- `n-ragdoll-strokes` launched 2026-11-24 ~01:45 UTC (run.S7bGuoXf, cwd verified, handshake sent): ragdoll Drawing-API
  thin strokes under scale, then the native residual (fps counter, edge px). CI folded into the coordinator's runs.
- `flash-oracle` (launched by s26-coordinator at Robert's request): real Flash Player 32 oracle; captures come to s27.

## Grading runs

| run | mode / categories / images | code | result |
|---|---|---|---|
| 45300086369 | graphics / full / images (wave 0, dispatched by n-trap-stroke) | d70f2c0aa | **exact**: trace 4684 eff on the 4722 intersection, 0 moves; +2 new fixture rows pass (4686 / 4724); pixels 0 moves, 0 band moves (595 / 639 summed incl. the 2 fixtures). Results `da51f878f` |
