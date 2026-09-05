# w2-gfx-text — wave 2: EditText render fixes (+2 flips priced, +1 HOLD companion, +1 device-font fallback)

Read `BRIEFS_COMMON.md` (incl. wave-2 + graphics canary rules) and `SIBLING_FILE_MAP.md`, then
the diagnosis of record: `w1-gfx-text-report.md` §1 (G1, incl. 1.4 blast radius), §2 (G2 + H1,
incl. 2.2 Ruffle's exact underline geometry `edit_text.rs:1318-1329/1365-1378`), §3.3 (A1b),
§6 (reproduction recipe). Isolated worktree; no commits. Local Dawn at `~/CC/dawn-install`.

## Scope (in this order; ledger each separately)
1. **G1 `visual/edittext/edittext_bounds_vs_position` 519 → 0 (+1, 1–8 LOC):** during the render
   pass `getLocalMatrixForMC_render` → `ng_getMatrixFromObj_render` reads `obj->transform_id`
   (the post-`compose_children` GPU slot) and the device-font cull `tf_transform_positive_scale_only`
   kills the nested fields. Use `ng_get_original_transform_id(obj)` as `otf_walk_dl` already does —
   localize the fix in `getLocalMatrixForMC_render` (the shared accessor also serves hit testing in
   NO_GRAPHICS; do not change hit-test behaviour — trace canaries below prove it).
2. **G2 `visual/edittext/edittext_underline` 1974 → 0 (+1):** underlines are never drawn in either
   VM. Add the underline flag to the glyph run and draw Ruffle's exact geometry in the painters.
3. **H1 `visual/edittext/edittext_underline_scale2` 27672 → 0 (needs 2 + this):** the AVM2 EditText
   border is computed in STAGE twips (`avm2_display.c:17264-17472`) → 2 device px wide at 2×; port
   s17's AVM1 device-pixel border fix (A3, `w2-gfx-edittext-bg-report.md`) to the AVM2 painter.
4. **A1b `fonts/device_font_kerning` 1680 → 0 (+1, small):** the test embeds the very font it
   requests as a device font — add a name-matched embedded-font fallback for device-font requests
   (no TTF rasterising). Say whether `visual/fonts/device-font` / `leading_device_font` move.

## Verification
`--mode=graphics --images --image-out-dir` on the 4 targets + `visual/edittext/*` (ALL — ~40,
these share the painters), `visual/cache_as_bitmap/edittext_*`, `text/*`, `fonts/*`,
`avm1/edittext_*` image tests, `avm2/edittext_*` image tests (sample 10). Render canary
`render_canary.py` (`--timeout 5400`) md5 identity except rows with underlines/nested fields (list).
Trace canaries (`--diff`, byte-identical): `avm1/edittext_*` passing (ALL — hit-test + bounds read
the matrix path you touch), `avm1/*hittest*`, `avm1/textfield_*` (sample 10), `avm2/edittext_*`
passing (sample 10), and NO_GRAPHICS mode too for 6 of them (the accessor is shared);
`regression` suite text fixtures. `-P 1`–`2` (machine loaded), compile timeout 2400,
`--recompile` on first use. Runtime-only → copying `SWFRecomp/build` is valid.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-gfx-text.patch` + `w2-gfx-text-report.md` (NEW
files first; per-comparison ledger per item; canary ledgers; refutations; unclaimed leads). Copy
to the main tree if allowed.
