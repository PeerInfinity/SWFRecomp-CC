**Land w1-pixel-flash-gaps prototypes A + B + C and 2 flash_fixes (M).**

Read `session29-fanout-reports/w1-pixel-flash-gaps-report.md` and `w1-pixel-flash-gaps-prototype.patch` (A: LOW glyph
pen → whole device px for non-FlashType embedded fields, `tf_glyph_quarter_snap` MSAA_SAMPLES==1 arm + `csm_advanced`;
B: drawing-API centre ¼-px quantisation only at ends of exactly axis-aligned segments, `render_webgpu_stroke_snap`;
C: unfiltered cacheAsBitmap snaps at LOW only). Coordinator FP32 results: `w1-local-oracles/w1-pixel-flash-gaps/README.md`.
1. **C is confirmed** on the real screen (request 2). Land it; price the AVM1/AVM2 HIGH rows that set `cacheAsBitmap`
   from script (report lead 5) before landing.
2. **A:** `text_field_mask` (the only Ruffle-golden loss, 630 → 1738) — its golden is 1189 px from FP32 LOW, and
   FP32 LOW is platform-stable (WIN == LNX). Grade master and A against `text_field_mask.low.png`. Add a flash_fixes
   entry swapping its `output.expected.png` to that capture (README rules; verify the upstream sha256 on your fresh
   download) whichever way A goes, and report ours→FP32 before/after. If A moves `text_field_mask` AWAY from FP32,
   narrow A's gate until it does not.
3. **B:** land; ledger from the report (acid-shapes 243 → 88, `graphics_simple_shapes`, `graphics_gradients`, fixture
   `avm1_drawing_stroke_scale` band in tolerance). Re-run the n-drawapi-stroke-snap ledger rows (acid-shapes-testing,
   `avm1/avm2_drawapi_stroke_snap`, cursor, fills_and_lines): nothing may move away from Flash.
4. **flash_fixes `from_shumway/gradientTransform`** `output.expected.png` → `gradientTransform.low.png` (golden is FP32
   HIGH exactly; the row runs at LOW; WIN LOW == LNX LOW). Grade ours vs it. RvF entry for both swaps.
5. Kill switches for A, B, C. Gate: the Flash-golden LOW set (lowq-corner-rule §3 / `interim6-low`) 0 losses; HIGH render
   canary md5-identical except the ledger; regression suite near text/cacheAsBitmap/drawing API.
Ledger: report verdict table + the 2 swaps, by name, both axes. Siblings: w2-text-coverage-land (`tag.c` skewed text
path: `tf_border_skewed_line_rect`, `textfield_glyph_render_cb` matrix arm, a new batched emit in `render_webgpu.c`),
w1-lowq-next (LOW sample/stroke rules in `render_webgpu.c`), local n-seam-caps (stroke builders). You touch
`tf_glyph_quarter_snap` and `render_webgpu_stroke_snap`: keep the edits there and name every function.
