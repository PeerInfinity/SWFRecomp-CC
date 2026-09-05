# w2-gfx-fill-smalls — wave 2: three one-rule pixel fixes (+2 flips, one −97% band)

Read `BRIEFS_COMMON.md` (incl. wave-2 + graphics canary rules) and `SIBLING_FILE_MAP.md`, then
the diagnosis of record: `w1-gfx-fill-report.md` §1 A2, A4; §2 B2; §6 slice "fill-smalls"; §7
canary gaps. Isolated worktree; no commits. Local Dawn at `~/CC/dawn-install`.

## Scope
1. **A2 `avm2/edittext_always_show_selection` 432 → 0:** `avm2_text.c:3859` unfocused selection
   colour is `0x808080`; Ruffle's `Color::GRAY` is `0x555555`. One token. (w1-gfx-text may also
   touch `avm2_text.c` — keep to this line.)
2. **A4 `avm2/bitmapdata_draw_self_via_graphic` 7 500 → 0:** `BitmapData.draw` must accumulate
   destination alpha (`aOut = as + ad·(1−as)`, premultiplied 8-bit — the report reproduces
   expected 172 vs our 195 exactly). `avm2_bitmap.c`.
3. **B2 `avm2/graphics_draw_path` 204 → 6:** `drawPath` aborts the whole path on a NaN coordinate;
   Ruffle coerces NaN → 0. `avm2_display.c` gfx region (sibling w2-gfx-strokes edits the stroke
   builders + point quantisation in the same region — self-localize, do not reformat).
Do NOT take A3 (filter cxform) or B1 (recompiler opaqueBackground) — they are w2-gfx-filter-chain's.

## Verification
`--mode=graphics --images --image-out-dir` on the three targets + `avm2/edittext_*selection*`,
`avm2/bitmapdata_draw*` (all), `avm2/graphics_draw_path*`/`avm2/graphics_*` passing (sample 8).
Render canary `render_canary.py` (`--timeout 5400`) md5 identity except rows that draw with
BitmapData.draw alpha (list them). Trace canaries (`--diff`): `avm2/bitmapdata_draw*`,
`avm2/bitmapdata_*alpha*`, `avm2/graphics_draw*`, `avm2/edittext_*` passing (sample 8) — the
BitmapData tests read pixels back in traces, so byte-identical traces matter; `regression` suite
BitmapData/Graphics fixtures. `-P 2`, compile timeout 2400, `--recompile` on first use.
Runtime-only → copying `SWFRecomp/build` is valid.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-gfx-fill-smalls.patch` + `w2-gfx-fill-smalls-report.md`
(NEW files first; ledger; canary md5 ledger; refutations; unclaimed leads). Copy to the main tree
if allowed.
