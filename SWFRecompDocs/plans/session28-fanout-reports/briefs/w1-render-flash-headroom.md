**Quality model + gnash shape headroom vs Flash (S–M): `from_shumway/gradientTransform` (9 px, golden = Flash at HIGH
while `test.toml` says low), `acid-color` frame1 (same), and `from_gnash/misc-ming.all/place_object_test` /
`shape_test` against their Flash ROOT captures.**

Record: `session27-fanout-reports/golden-provenance.md` (rows 102/132/138/139 and §"Re-priced pixel board"): the
`place_object_test`/`shape_test` goldens are not Flash (we fail them by 38238 / 15994 excess); Flash root captures
exist (`…__output.direct-pinned.png`, LNX == WIN), our miss vs them is ~5984 / ~1437 px. They become flash_fixes swaps
once our miss vs Flash is under ~1k px.

Task:
1. Quality: how does our runtime set render quality for a test (`with_renderer.quality` / `quality = "low"` in
   `test.toml` → `verify_output.py` → runtime MSAA/AA mode)? Does the Ruffle test runner honour `quality` for these
   rows? Explain gradientTransform's 9-px miss: is it our quality=low AA vs a HIGH golden? If so, it's a test-harness
   question (should the harness render at the quality the golden was made at?), not a renderer fix — price both
   options and how many other rows have the same golden/toml mismatch (golden-provenance lists them).
2. Diff our place_object_test / shape_test renders against the Flash ROOT captures (fetch them from the archive) per
   region: what are the ~6k / ~1.4k px? Prototype what you can (stroke joins/caps, hairlines, fill rule, twip snap).
3. Gate: render canary + every passing gnash misc-ming image row.
