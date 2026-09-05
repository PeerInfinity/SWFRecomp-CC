# w2-avm2-new-smalls — wave 2 implementation: six small AVM2 trace flips from the new-upstream board (+6 priced)

Read `BRIEFS_COMMON.md` (all sections incl. wave-2 rules) and `SIBLING_FILE_MAP.md`, then the
diagnosis of record: `w1-trace-new-report.md` §4–§9 (#6–#11) and §12 (sibling collisions). You
work in an ISOLATED WORKTREE (already created for you); edits only there; no commits to master;
deliver a patch + report.

## Scope (all suite `avm2`)
1. `bitmapdata_copypixels_alpha_combine` 2/13 → pass: Ruffle's `a == 255 → source alpha` special
   case in the copyPixels alpha-combine path (`avm2_bitmap.c`). Caveat from wave 1: line 1 is a
   hash over all 65 536 (sa,aa) pairs and only 81 cells were verified — if it lands 12/13, say so
   and diagnose the unprinted pair.
2. `bitmapdata_applyfilter_identity` 2/4 → pass: treat ConvolutionFilter as the plain copy Ruffle
   falls back to. This is Ruffle parity, not Flash parity → add a `RUFFLE_COMPAT_TWEAKS.md` entry
   (`ruffle-tests/tests/swfs/avm1/_investigation/`).
   Rider: `bitmapdata_copypixels_alpha_merge` (known_failure) — report §5 "Rider R"; grade only.
3. `primitive_keys` 33/54 → pass: dynamic integer keys clamp to 28 bits (Ruffle `45904c3ee`),
   `avm2_object.c`. Regression canary: `from_avmplus/ecma3/Array/e15_4_5_1_2` (must stay passing).
4. `xml_duplicate_attribute` 7/14 → pass: `#1104` with both names interpolated AND the duplicate
   scan moved after the tag terminator (`avm2_e4x.c`).
5. `movieclip_addframescript_error` 0/9 → pass: `addFrameScript` throws `#2001` on empty-or-odd
   argc (`avm2_display.c`, MovieClip region).
6. `flash_ui_mouse_cursor` 1/35 → pass: `flash.ui.MouseCursorData` class + `Mouse.registerCursor`
   / `unregisterCursor` + `Mouse.cursor` validation (~95 LOC; class registration in
   `avm2_globals.c` — NOTE `builtin_class_impl` is not idempotent; grep the class tables first).
   Upstream reference: `~/CC/ruffle` commit `edbfa4dc4` (2026-09-03).

Sibling w2-matrix3d edits `avm2_stage3d.c` and ONE line in `avm2_display.c`'s Vector3D region —
stay out of those. Other pending siblings may take `avm2_display.c`'s transform/bounds/focus
regions — self-localize (new static helpers, no reformatting).

## Verification (state per-test before/after in the report)
Headline: the 6 tests + the rider. Canaries: `avm2/bitmapdata_copypixels*`, `bitmapdata_applyfilter*`,
`avm2/xml_*` (a sample of 8 passing ones incl. any attribute tests), `avm2/dictionary_*`,
`from_avmplus/ecma3/Array/e15_4_5_1_2`, `avm2/movieclip_addframescript*` (passing siblings),
`avm2/mouse_*` (sample 4), and `regression` suite tests touching BitmapData/XML/Dictionary
(grep). Copy test dirs into your worktree's canonical paths, `--recompile` on first use, `-P 2`
max, compile timeout 2400. Run a couple in `--mode=graphics` (CI mode).

Deliverables in `SWFRecompDocs/plans/session18-fanout-reports/`: `w2-avm2-new-smalls.patch`
(`git diff`, incl. doc edits) and `w2-avm2-new-smalls-report.md` (NEW FILES at the top; per-test
ledger; refutations; new unclaimed leads). Copy both to the main tree path as well if the guard
allows.
