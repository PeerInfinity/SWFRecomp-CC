# w2-gfx-glyph-twips — wave 2 PROBE: quantize glyph vertices to integer twips (+7 pixel flips if the tie theory holds; +0 otherwise)

Read `BRIEFS_COMMON.md` (incl. wave-2 + graphics canary rules) and `SIBLING_FILE_MAP.md`, then
the diagnosis of record: `w1-gfx-text-report.md` §4 (N1 — the `a_epsilon` cluster measured: 8 of
11 comparisons are pure 0/255 1-sample run-edge ties, bidirectional, deterministic) and the
standing memory in `ruffle-tests/tests/swfs/_investigation/` / `SWFRecompDocs` about Ruffle
geometry being integer twips (grep "integer twips"). Related sibling probe: w2-gfx-blend-tie
tests the same idea for SHAPE world matrices — read its report if it has landed
(`w2-gfx-blend-tie-report.md`) and do not redo its measurements. Isolated worktree; no commits.

## Method (A/B, not fix-first)
1. Reproduce 3 of the 11 rows locally (`--mode=graphics --images --image-out-dir`, quality=low
   tests use `-DMSAA_SAMPLES=1` — check how the harness passes it) and confirm the failing pixels
   are the report's run-edge ties.
2. Find where glyph outlines are transformed to device space (glyph tables in `ng_shared.c` /
   `render_webgpu.c` glyph path / the AVM2 static-text raster) and where Ruffle quantizes
   (`~/CC/ruffle/render/src/...` glyph transform, `Twips`). Prototype quantizing glyph vertex
   positions (and/or the glyph origin/advance) to integer twips the same way.
3. A/B the 11 rows + every text image test (`visual/edittext/*`, `text/*`, `fonts/*`,
   `from_shumway/acid/acid-text*`) + render canary md5. Ledger before/after outliers per row;
   name any row that WORSENS.
4. Verdict: GO patch + ledger, or HOLD/NO-GO with the residual mechanism.
Sibling w2-gfx-text edits underline emission, the render-pass local matrix accessor, the AVM2
border box and device-font fallback — stay out of those; if your quantisation belongs in a
function they touch, report it instead of editing.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-gfx-glyph-twips.patch` (may be empty) +
`w2-gfx-glyph-twips-report.md`. Copy to the main tree if allowed. Runtime-only → copying
`SWFRecomp/build` is valid. `-P 1`, compile timeout 2400, `--recompile` on first use.
