# w2-goto-collator: invalid goto in a frame script is a no-op + `flash.globalization.Collator`

Session 22, wave 2, cloud worker. Branch `fanout/w2-goto-collator`, based on `origin/master` at `8ebe7ee2`.
Corpus: `download_tests.sh avm2` (+ `avm1 fonts from_shumway text visual` for the render canary), upstream Ruffle
master **`45366370e`**. Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Every run below uses `--mode=graphics --verbose`
unless it says otherwise.

**New files:** this report (`w2-goto-collator-report.md`) and `w2-goto-collator.patch`. No new source files,
no new fixtures.

**Modified files (all in the patch):**
- `SWFModernRuntime/src/avm2/avm2_display.c`: the goto half of `w1-drift-avm2-prototype.patch`, 3 hunks, unchanged.
  **`pick_in_scroll_rect` is NOT included** (sibling `w2-crossvm` owns it).
- `SWFModernRuntime/src/avm2/avm2_globals.c`: a new Collator block next to `CurrencyParseResult`, no new TU.
- `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`: a new AVM2 entry for the SWF ≤ 9
  goto arm. This is the cross-suite RVF doc; the avm2 suite has no RVF doc of its own.

Patch: `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt
ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`, checked with `git apply --check -R`.

## Verdict: GO, +6 trace passes, 0 pixel rows

| Test | before (clean `origin/master`, this box) | after (patch, this box) | no-graphics after | KF |
|---|---|---|---|---|
| `avm2/goto_queued_invalid/swf9` | MISMATCH | **PASS** | PASS | yes (beats Ruffle) |
| `avm2/goto_queued_invalid/swf10` | MISMATCH | **PASS** | PASS | no |
| `avm2/goto_queued_invalid/swf11` | MISMATCH | **PASS** | PASS | no |
| `avm2/collator_flags` | MISMATCH (`ReferenceError #1065 Collator`) | **PASS** | PASS | no |
| `avm2/collator_locale_ids_windows` | MISMATCH (same) | **PASS** | PASS | no |
| `avm2/collator_compare_basic` | MISMATCH (same) | **PASS** | PASS | yes (beats Ruffle) |

## EXPECTED-FLIP LEDGER (for CI grading)

**Trace axis.** Rows CI already grades (recovery): `avm2/goto_queued_invalid/swf9`, `avm2/goto_queued_invalid/swf10`,
`avm2/goto_queued_invalid/swf11`, each fail → pass. Rows CI has not graded yet (added upstream after the 10-03 run,
so they show up as new rows): `avm2/collator_flags`, `avm2/collator_locale_ids_windows`, `avm2/collator_compare_basic`,
each absent → pass.

**Pixel axis:** none. None of the six has `[image_comparisons]`. Any other pass → fail or image move is a regression.

**CI mode:** `graphics`, `categories=full` (AVM2 runtime; run_goto edit 2 also changes SWF10+ gotos past the last frame
that happen outside frame scripts).

## Mechanism

### Goto (`avm2_display.c`, the prototype's diagnosis in `w1-drift-avm2-report.md` §1.1, landed verbatim)
1. `mc_goto_with_args`: `if (frame == 0 && ext->executing_frame_script) return;` before
   `mc_set_programmatically_played`. Same as Ruffle `movie_clip.rs:454` / `e092c78c2`.
2. `run_goto`: re-arm `queued_script_frame` only when `clamped == frame || ctx->swf_version <= 9`. The SWF ≤ 9 arm
   is Flash-over-Ruffle and is now documented in `RUFFLE_VS_FLASH_DIFFERENCES.md`, section "AVM2 goto past the last
   frame".
3. `mc_goto_with_args`: a `frame:Object` argument of `undefined` coerces to `null`, so the #2109 text reads `null`.

### Collator (`avm2_globals.c`, follows §1.3)
- `Collator` (final). The ctor checks a null/undefined `requestedLocaleIDName` first (#2007), then a null
  `initialMode` (#2007). Any mode other than exactly `sorting`/`matching` gives ArgumentError #1508. When the ctor
  throws, it pushes a static native frame `flash.globalization::Collator/ctor`. The class's own instance-init frame
  supplies `Collator()` beneath it.
- The locale ID is stored verbatim and returned by both `requestedLocaleIDName` and `actualLocaleIDName`.
  `lastOperationStatus` is `"noError"`.
- Six Boolean flags with coercing setters. Defaults: sorting = all false; matching = the first five true,
  `numericComparison` false. State lives in `dont_enum` dynamic slots, the same pattern as `CurrencyParseResult`.
- `static getAvailableLocaleIDNames()` returns a fresh, non-fixed `Vector.<String>` (`["en-US"]`) on every call.
- `compare`/`equals` (declared arity 2). A null `string1` is checked before `string2` (#2007). The frame
  `Collator/compare()` / `Collator/equals()` comes from the normal native method dispatch, and the test's
  expected traces confirm it.
- Ordering, compared in this order:
  1. Primary key: the base letter, case-folded. Latin-1 accented letters fold to their base letter.
  2. Diacritic. This always counts, even with `ignoreDiacritics` set or in MATCHING mode.
  3. Case: lowercase sorts first, unless `ignoreCase` is set.

  This ordering matches all 93 expected lines, including the two `é vs z` / `résumé vs rf` lines that Ruffle gets
  wrong.
- `CollatorMode.SORTING/MATCHING`, `LocaleID.DEFAULT = "i-default"`, `LastOperationStatus.NO_ERROR = "noError"`.
- The new block compiles clean under `-Wall -Wextra`.

## Canaries and regression (same box, before vs after)

- **The 45-row goto sweep** (the list in `w1-drift-avm2-report.md` §6): **45/45 identical**, 43 PASS + 2 RUFFLE_MATCHED
  (`goto_framescript_queued/swf13`, `swf_9_goto_in_construct_frame`) both before and after. Same as CI 10-03.
- **Globalization rows:** `avm2/currency_parse_result` PASS → PASS. There are no CurrencyFormatter/NumberFormatter/
  DateTimeFormatter rows in the avm2 corpus (static grep of `Test.as`).
- **`regression` suite, AVM2 timeline/goto/button fixtures** (12): `avm2_child_simplebutton avm2_goto_catchup_scale
  avm2_morph avm2_parent_child_render avm2_parent_child_static_text avm2_parent_child_symbol_stride
  avm2_parent_child_symbolclass_domain avm2_simplebutton_click avm2_timeline_gradients avm2_timeline_solid
  avm2_timeline_stroke_gradient avm2_timeline_text`: **12/12 PASS before and after**, and the image checks are unchanged.
- **Render canary** (`render_canary.py capture/compare`, full `render_canary_tests.txt`, 60 tests / 102 PNGs):
  **IDENTICAL 102, DIFFERS 0**, with no trace-status or image-status changes. No covering member was added, because this
  change class is not render code.
- **Mode parity:** no `swf_core.c`/`tag_stubs.c`/`NO_GRAPHICS` code was touched. The headliners also pass in no-graphics
  (table above).
- **New regression fixture:** none. Both behaviours already have Flash-oracled corpus rows (the six headliners), so a
  fixture would only duplicate them.

## Refutations / premise checks
- The brief said to "add an AVM2 entry to RVF (or the avm2 suite's own doc if one exists)". The avm2 `_investigation/`
  has no RVF doc. The avm1 RVF doc already carries AVM2 sections (URLVariables, JSON.parse, …), so the entry went
  there.
- Sibling map: `w2-crossvm` edits `mouse_pick`, `update_mouse_state`, `avm2_display_run_tick` and the loader drain.
  The goto hunks are at about :3153 and :8013–8105, far from all of those, so the patches should not conflict
  textually.

## Not finished
Nothing in scope is left. Optional: the w1 LOCAL ORACLE REQUEST (a Ruffle trace of `goto_queued_invalid/swf10`) is not
needed, because the corpus rows are Flash-oracled and pass.

## New unclaimed leads
- `Collator` covers only Latin-1 diacritic folding. Non-Latin-1 accented letters (e.g. `ā`, `ő`) and the
  `ignoreSymbols`/`numericComparison`/`ignoreKanaType`/`ignoreCharacterWidth` flags are stored but have no effect on
  `compare`. No corpus row exercises them, so they need a Flash oracle before anyone implements them.
- `getAvailableLocaleIDNames` returns `["en-US"]` (the same as Ruffle). Flash-Windows returns the OS locale list, which
  is ungraded.

## LOCAL ORACLE REQUESTS
none
