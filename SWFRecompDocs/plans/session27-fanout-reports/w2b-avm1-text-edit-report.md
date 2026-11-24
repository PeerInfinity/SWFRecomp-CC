# s27 w2b-avm1-text-edit: AVM1 text-edit leftovers, landed against FLASH

**New files**
- this report; `w2b-avm1-text-edit.patch` = `git diff --binary origin/master -- SWFRecomp SWFModernRuntime
  ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <the 4 new regression dirs>` (22 files; source =
  `SWFModernRuntime/src/actionmodern/action.c` +112/−7 only; `--binary` because it carries 4 `test.swf`; proven with
  `git apply --check -R` against the branch tip).
- 4 regression fixtures, `ruffle-tests/tests/swfs/regression/` (moved from the held set on
  `fanout/w2-avm1-leftovers-land`, `session27-fanout-reports/w2-avm1-leftovers-land-held/`):
  `avm1_set_new_text_format_instance/`, `avm1_bare_depth_methods_v7_gate/`, `avm1_bare_depth_methods_v7_gate_swf7/`,
  `avm1_edittext_maxchars_clips_insertion/` (+`input.json`). Each holds `avm1asm.py`, `create_test_swf.py`, `test.swf`
  (regenerates byte for byte, checked), `test.toml`, `output.txt`. Docstrings now name the Flash golden. The `_swf7`
  twin's generator calls `../avm1_bare_depth_methods_v7_gate/create_test_swf.py` (siblings in `regression/`, so it works).

Base: `origin/master` `f223ee7a`. Corpus: `download_tests.sh avm1 from_gnash` on 2026-11-24 (upstream Ruffle master, the
same `1e604fa87` tip the brief names; the script does not print a SHA). Box: SETUP_STATUS all OK (Dawn on lavapipe).
Baselines for the sweep: master's `_results` (`results_graphics.json` at `dc5d2936`, `results.json` no-graphics).

## Verdicts (lead)

| # | item | verdict | fixture: master → patch (same box; graphics and no-graphics) |
|---|---|---|---|
| 1 | `setNewTextFormat(new TextFormat)` defers size/font to the next text replacement | **GO, landed** (w1 `tf_snf_*` hunks, inside the existing real-TextFormat gate) | `avm1_set_new_text_format_instance` 4/5 mismatch → **pass** |
| 2 | bare `getNextHighestDepth` / `getInstanceAtDepth` SWF7 gate | **GO, fixtures landed** (code already on master from `85cca4df6`) | `_v7_gate` pass → pass; `_swf7` pass → pass (both == Flash byte for byte) |
| 3 | onChanged fires for every typed key, even when maxChars drops it | **GO, landed**; fixture golden switched to Flash's | `avm1_edittext_maxchars_clips_insertion` (Flash golden) 2/4 mismatch → **pass** |
| 4 | w1/w2 leftovers sweep (text, case, mouse, regression), both modes | **done: 0 movers** | 427 rows × 2 modes |

**Priced corpus flips: 0.** All three are Flash-correctness fixes pinned by fixtures. **4 new regression rows**, all pass in
both modes (see the ledger).

## Mechanism and the landed hunks (all in `SWFModernRuntime/src/actionmodern/action.c`)

**Item 1.** Flash 32 direct: after `setNewTextFormat` with a TextFormat of size 40, `getTextFormat(0).size` is still 12,
`getNewTextFormat().size` is 40 and `textWidth`/`textHeight` are unchanged. After `text =`, `size0=40`. Master already kept
the span model right (`tf_ps_set_new_text_format`). The bug was the field-wide layout keys `_tf_fontHeight`, `_tf_fontId`
and `_tf_fontName`, which the setNewTextFormat arm wrote at once, so the existing text was re-measured at 40.
- New statics, placed right before `tf_ps_set_new_text_format`: `g_tf_snf[16]`, `tf_snf_slot`, `tf_snf_defer`,
  `tf_snf_drop`, `tf_snf_apply_pending`. These are w1's hunks with two hardening changes:
  - when the table is full, `tf_snf_slot` returns −1, and the size/font are then applied at once (master's behaviour). w1
    recycled slot 0 instead.
  - a recycled `MovieClip` address can't inherit a parked format. `tf_ps_drop`, which runs when a clip is created, now also
    calls `tf_snf_drop`.
- `actionCallMethod` `setNewTextFormat` arm (`NO_GRAPHICS || OFFSCREEN_RENDER`): this is still inside w2's
  `native_type == NATIVE_TEXTFORMAT` gate, so plain objects are still ignored (`avm1_set_new_text_format_size` still passes).
  With text present, `tf_snf_defer` parks size/font and the immediate `_tf_fontHeight`/`_tf_fontId` writes are skipped.
  With an empty field they are written at once, as before. Colour, leading, margins and the rest are unchanged.
- The parked size/font are applied in three places:
  - `actionSetMember` `text` arm (when `tf_ps_text_assign` is not a same-text no-op);
  - `actionSetMember` no-stylesheet `htmlText` synonym arm;
  - `tf_replace_selection` on an insertion (`ins_len > 0`).
- The browser `#else` arm of setNewTextFormat is untouched. There, `tf_snf_defer` is an unused static (warning only).

**Item 3.** In `tf_replace_selection`, the return type changes from `void` to `int`: it returns 0 when maxChars leaves no
room (no edit), and 1 after an edit. `actionTextFieldInput` fires `onChanged` when it gets 0. **Typing only:** Paste and Cut
(`actionTextControlPaste`/`Cut`) still treat a no-room paste as no edit and no event, because we have no Flash oracle for a
clipboard paste. Ruffle skips onChanged here; Flash doesn't, and Flash wins.

**Item 2**: no code. The gate landed in `85cca4df6`. Both Flash direct traces equal the analytic goldens byte for byte,
including the trailing space on the `typeof gv` row.

**Functions touched**: `tf_ps_drop`, `tf_ps_set_new_text_format` (only its neighbourhood: the new statics are inserted
above it), `actionSetMember` (2 one-line hooks), `actionCallMethod` (setNewTextFormat arm), `tf_replace_selection`
(+ its forward decl), `actionTextFieldInput`.
**Not touched**: `tag.c`, `swf.c`, `swf_core.c`, `tag_stubs.c`, the recompiler, `verify_output.py`,
`render_canary_tests.txt`, `render_webgpu.c`. **Sibling overlap**: none. These are the same functions
`w2-avm1-leftovers-land` owned, and that slot has landed. `w2-avm1-text-layout` owns glyph/render functions, not these.

## Golden provenance / premise checks
- `avm1_set_new_text_format_instance`: Flash direct == the analytic golden except `font0=Times`, which is the Linux
  projector's device-font name. We keep `Times New Roman`, which is what every Windows corpus golden reads (the same swap
  `avm1_set_new_text_format_size` made). The Flash trace also confirms the setNewTextFormat line reads `font0=Times`, i.e.
  the existing text's font did not change either, which is the font half of the deferral.
- `avm1_edittext_maxchars_clips_insertion`: the old analytic golden had 2 lines; Flash prints 4. The golden is now
  Flash's, verbatim. The fixture's text is ASCII, so it has no font-token issue.
- Attacked: does onChanged-on-drop or the size deferral move any corpus row? The sweep below says no. The 58-row text set
  includes every corpus SWF with `setNewTextFormat`/`maxChars` in its decompressed bytes, plus every row with TextInput or
  TextControl input.

## Per-test before/after (clean `origin/master` vs patch, same box; matching/expected)

| test | master (graphics) | patch graphics | patch no-graphics |
|---|---|---|---|
| regression/avm1_set_new_text_format_instance | 4/5 mismatch (`unchanged w=false h=false`) | **pass 5/5** | pass 5/5 |
| regression/avm1_edittext_maxchars_clips_insertion (Flash golden) | 2/4 mismatch (no `changed #2/#3`) | **pass 4/4** | pass 4/4 |
| regression/avm1_bare_depth_methods_v7_gate | pass 6/6 | pass 6/6 | pass 6/6 |
| regression/avm1_bare_depth_methods_v7_gate_swf7 | pass 6/6 | pass 6/6 | pass 6/6 |
| regression/avm1_set_new_text_format_size (gate guard) | pass | pass | pass |
| regression/avm1_edittext_cut_copy_selection (shares `tf_replace_selection`) | pass | pass | pass |

## Sweep (patch vs the CI baseline rows: status AND matching-line count)

| set | rows | graphics movers | no-graphics movers |
|---|---|---|---|
| text: avm1 + from_gnash SWFs with `setNewTextFormat`/`maxChars` (CWS/ZWS decompressed), plus TextInput/TextControl input rows | 58 | 0 | 0 |
| case: SWF≤6 avm1/gnash SWFs with a non-exact case variant of a name in `k_swf6_cf_builtins`/`_array_methods`/`_string_methods` | 139 | 0 | 0 |
| mouse: avm1/gnash rows whose `input.json` has a Mouse event | 46 | 0 | 0 |
| regression: every non-`avm2*` row | 197 | 0 | 0 |
| **distinct total** | **427** | **0** | **0** |

- 34 rows are absent from the baseline JSONs: regression fixtures added after `dc5d2936`, including the 4 new ones. All 34
  pass in both modes.
- Two rows pass with a different expected-line count from the baseline: `regression/avm1_child_timeline_loop` (34→32) and
  `avm1_timer_overflow` (2→10). Both goldens were edited in `78fee9e1`, after the baseline, so this is drift and not a mover.
- Shumway is not in my categories. Its rows were in w2's sets, but no shumway row exercises the two changed paths beyond
  what this sweep covers. I did not re-run it.

**Render canary** (`render_canary.py capture/compare`, md5; runtime-only change, so no `--recompile`). I ran the 11
text-relevant image rows: avm1 `edittext_stylesheet`, `edittext_tag_indent`, `mouse_events_visible_enabled`, and regression
`avm1_edittext_placed_cxform`, `_scaled_glyphs`, `_tab_render`, `_wordwrap_render`, `avm1_long_text_layout`,
`avm1_parent_child_text`, `avm1_set_new_text_format_render`, `avm1_textfield_attached_depth_order`.
- Result: **11/11 PNGs IDENTICAL, 0 trace or image status changes.**
- I did not run the full canary. This is AVM1 text logic with no render code, and these 11 cover every image row whose
  SWF reaches the changed paths.
- I appended no canary member: none of the 4 new rows has `[image_comparisons]`.

## EXPECTED-FLIP LEDGER (for the coordinator's CI check)

- **Trace axis**, graphics and no-graphics, `regression` suite: **4 new rows, all `pass`**:
  `avm1_set_new_text_format_instance`, `avm1_edittext_maxchars_clips_insertion`, `avm1_bare_depth_methods_v7_gate`,
  `avm1_bare_depth_methods_v7_gate_swf7`.
- **Corpus trace axis**: no movers expected (0/427 in both modes above). Any corpus pass→fail is a regression of this patch.
- **Pixel axis**: no movers expected. None of the 4 new rows has image comparisons.

## Not finished / completion mechanisms
- **Paste with no room under maxChars**: still no edit and no onChanged. That matches Ruffle; Flash is unknown. Completion
  mechanism: a Flash run of a paste twin of the maxChars fixture. `run_trace.py` has typing but no clipboard, so the
  coordinator would need clipboard injection. Until then, leave it as is.
- **restrict-filtered keystrokes**: `actionTextFieldInput` returns before `tf_replace_selection` when `restrict` drops the
  character, so no onChanged fires. Flash may fire it here as it does for maxChars; I have not probed it. Completion
  mechanism: a FLASH request (below).
- **setNewTextFormat deferral in the browser `#else` arm**: that arm keeps master's behaviour. Completion mechanism: a
  browser-arms session porting the gate and deferral (`browser-arms-land` owns those arms).

## New unclaimed leads
- The restrict / onChanged question above. It is one fixture plus a two-line change if Flash fires.
- `tf_snf` parks only size/font. If Flash also keeps the existing text's `leading`/margins/`letterSpacing` under
  setNewTextFormat, the same deferral applies to `_tf_leading`, `_tf_leftMargin` and the other field-wide keys, which are
  still written at once. That is unprobed; a twin fixture would decide it.

## LOCAL ORACLE REQUESTS
1. FLASH, trace, direct, `--type "1X" --type-after ready`: a twin of `regression/avm1_edittext_maxchars_clips_insertion`
   with `tf.restrict = "0-9"` and no maxChars, where `X` is filtered. Question: does onChanged fire for the filtered `X`?
   It decides the restrict lead.
2. FLASH, trace, direct: a twin of `regression/avm1_set_new_text_format_instance` using `leading 20` /
   `leftMargin 30` instead of size/font, reading `textHeight` and `getTextFormat(0).leading` before and after `text =`.
   It decides the second lead.
