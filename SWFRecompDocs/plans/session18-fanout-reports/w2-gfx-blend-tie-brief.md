# w2-gfx-blend-tie — wave 2 PROTOTYPE: the shared 9-pixel 45° tie behind 12 `visual/blend_modes` failures (+12 if it lands, +0 otherwise)

Read `BRIEFS_COMMON.md` (incl. wave-2 rules; graphics canary rules) and `SIBLING_FILE_MAP.md`,
then the diagnosis of record: `w1-gfx-smalls-report.md` §3 E (the 45° staircase tie, NO-GO with a
named completion mechanism) and §1. Also the standing verdict it partially overturns:
`graphics-fanout-playbook.md` §10 (s11 "blend_modes CAPPED — sub-pixel ties, do not scope") and
memory-level proof that quality=low goldens are 1-sample. Isolated worktree; no commits.

## The claim to test
All twelve failing `visual/blend_modes/*` comparisons (add, lighten, screen, difference,
alpha_no_layer, erase_no_layer, overlay, hardlight, subtract, darken, multiply, invert) fail on the
SAME nine pixels — one geometry tie on a 45° edge under 1-sample rasterisation, not twelve blend
bugs. The completion mechanism named: match Ruffle's world-matrix composition ORDER and PRECISION
(f32 vs f64, twips-vs-pixels rounding at each level, the order in which parent×child×placement
matrices are multiplied) so our edge lands on the same side of the pixel centres. The same tie is
claimed to own the four scrollRect rows, `from_shumway/MaskTest` 7 and `visual/blend_across_masks_issue_24549` 6.

## Method (measured prototype, not a fix-first patch)
1. Reproduce locally: `--mode=graphics --images --image-out-dir` on `visual/blend_modes/add` and
   `multiply`; confirm the failing pixel set matches the report's nine and is identical across
   the family (local Dawn ≠ CI lavapipe — if the local render already passes these, the tie is
   rasteriser-side and you must say so; then try `-DMSAA_SAMPLES=1`, which is what CI uses for
   quality=low goldens — check how `verify_output.py` passes it).
2. Read Ruffle's transform pipeline (`~/CC/ruffle/render/src/matrix.rs`, `core/src/display_object.rs`
   `local_to_global_matrix`, `render/wgpu` vertex transform) and ours (the transform funnel:
   `ng_cache_transform`, `compose_children`, `display_world_matrix`, the vertex shader in
   `render_webgpu.c`). Write down the two composition orders and precisions side by side.
3. Prototype the change in your worktree; A/B the 12 rows + the mask/scrollRect rows + the whole
   render canary set (`render_canary.py`, `--timeout 5400`) — md5 identity for everything not in
   the tie family is the bar; any canary that moves must be graded with `--images`.
4. Verdict: GO with a patch and a per-comparison ledger, or HOLD/NO-GO with the exact mechanism
   that remains (which pixel, which matrix element, which rounding). A refutation is yield.

Files: the transform funnel only. Sibling w2-gfx-strokes edits stroke builders and drawing-API
point quantisation — do not touch those; if your fix needs point quantisation, report it instead.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-gfx-blend-tie.patch` (may be empty on NO-GO) +
`w2-gfx-blend-tie-report.md`. Copy to the main tree if allowed. Runtime-only → copying
`SWFRecomp/build` is valid. `-P 2`, compile timeout 2400, `--recompile` on first use.
