**Text glyph fidelity vs Flash (M): `regression/avm1_edittext_wordwrap_render` glyph AA (~590 channels; keeps an
interim Ruffle golden) and the HELD fixture `avm1_edittext_rotated_glyphs` (1111 px vs Flash; never landed).**

Record: `session27-fanout-reports/w2-avm1-text-layout-report.md` (wordwrap font fixed for Flash, interim Ruffle PNG
golden; `scaled_glyphs` has a Flash golden), `w1-text-glyph-fidelity-report.md`, `w1-text-wordwrap-report.md`. The held rotated fixture lives at
`session27-fanout-reports/w2-avm1-text-layout-fixtures/avm1_edittext_rotated_glyphs/` (report §"LOCAL ORACLE REQUESTS" item 2). Grep
`SWFRecompDocs/plans/session27-fanout-reports/` and `w2-local-oracles/` for `rotated_glyphs` and `wordwrap_render` to
find the Flash captures (PNG) already archived.

Task:
1. Compare our render to the Flash capture for each fixture (download the PNGs from the repo; render ours in graphics
   mode; prove local-render fidelity per BRIEFS_COMMON first). Characterise the residual: glyph outline rasterization
   (AA coverage / gamma), sub-pixel glyph position (twip snapping of advance/baseline), hinting, or rotation matrix
   rounding. Use per-glyph difference maps, not totals.
2. Find what Flash does for embedded glyph AA (the corpus Flash-provenance text rows that PASS — `acid-text-2/3`,
   `acid-textfield-scroll`, `flash_text_TextField2` — are free evidence of what we already match) and prototype the
   change that closes the residual without moving any passing text row.
3. Gate: render canary (md5 identity outside your ledger) + every image row with text in the avm1/avm2/visual/
   from_shumway suites that currently passes + the two fixtures.
4. If the held rotated fixture is within tolerance of its Flash capture after your change, land it into `regression/`
   in your prototype (Flash golden). If the wordwrap fixture can take its Flash capture as golden after your change (within tolerance), say so: the
   coordinator swaps the golden.
Deliver a measured prototype or a priced NO-GO naming the mechanism.
