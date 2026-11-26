**Size the AA mode gap: Flash HIGH = 4×4 supersampling (16 samples, box filter), our HIGH = MSAA (DIAGNOSIS ONLY, M).**

w1-avm2-vector-flash (s28) found Flash HIGH is 4×4 SSAA; ours is MSAA (`MSAA_SAMPLES`, `render_webgpu.c`). n-join-disc
§5 item 3 says the W≥2 cap/corner residue per vertex comes from AA granularity (4 MSAA samples vs Flash's 16). It has never
been measured. Price it before anyone builds anything:
1. Which failing HIGH-quality comparisons (`s29-baseline-pixel-failing.txt`; quality from each test.toml / SWF) would a
   Flash-exact 16-sample box coverage move, and by how much? Build the cheapest faithful A/B: e.g. a debug build that
   renders at 4× resolution with 1 sample and box-downsamples 4×4 (or a 16× MSAA path if lavapipe supports it — check
   `maxSampleCount` and Flash's sample positions: a regular 4×4 grid at (i+.5)/4 is SSAA, MSAA 16 uses a rotated pattern,
   which is NOT the same coverage).
2. Run the A/B over the failing HIGH set with Flash goldens first (golden-provenance), then the passing Flash-golden HIGH
   set (losses?). Report per-row outliers before/after, and the count of Ruffle-golden passes it would cost.
3. Cost: perf (fill-rate ×16 or ×4 with MSAA-4 at 2×2 scale) and complexity. Glyphs (glyph ¼-px snap, 16-level glyph AA
   NO-GO L) and strokes interact: note it.
Deliver numbers, not a design doc: a by-name ledger of what moves, GO/NO-GO, and the cheapest implementation route if GO.
Siblings: w1-lowq-next (LOW path, MSAA_SAMPLES==1), local N ladder (stroke builders). No production edits.
