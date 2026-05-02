# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `3c67568fe68e`  
**Date:** 2026-05-02 19:46 UTC  
**Total duration:** 1h52m12s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 600 | 647 | 92.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 124 | 190 | 65.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 62 | 102 | 60.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **926** | **1121** | **82.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,001 | 114,967 | 92.2% |
| from_gnash/actionscript.all | 15,351 | 16,957 | 90.5% |
| from_gnash/misc-ming.all | 2,829 | 4,577 | 61.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 333 | 499 | 66.7% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **125,923** | **139,049** | **90.6%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 38 |
| from_gnash/actionscript.all | 5 |
| from_gnash/misc-ming.all | 24 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 6 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 25 |
| from_shumway/avm1 | 1 |
| **Total** | **99** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | Global-v7 | 96% |
| from_gnash/actionscript.all | Global-v8 | 96% |
| from_gnash/actionscript.all | Global-v6 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 32 | - | 1343 | - |
| from_gnash/actionscript.all | 3 | - | 33 | - |
| from_gnash/misc-ming.all | 1 | - | 50 | - |

**avm1 — newly passing:** `clone_sprite_edittext`, `clone_sprite_edittext_dynamic`, `edittext_align`, `edittext_align_trailing_spaces_swf7`, `edittext_align_trailing_spaces_swf8`, `edittext_autosize`, `edittext_bullet`, `edittext_default_format`, `edittext_default_format_empty`, `edittext_default_format_font_style`, `edittext_drag_select`, `edittext_focus_selection`, `edittext_font_size`, `edittext_html_align_swf7`, `edittext_html_align_swf8`, `edittext_html_color`, `edittext_html_roundtrip`, `edittext_ime_focus_lost`, `edittext_leading`, `edittext_letter_spacing`, `edittext_margins`, `edittext_newlines`, `edittext_programmatic_focus`, `edittext_stylesheet`, `edittext_tab_focus`, `edittext_tab_stops`, `edittext_tag_indent`, `edittext_text_height_leading`, `edittext_underline`, `movieclip_get_instance_at_depth`, `selection`, `textfield_properties`

**from_gnash/actionscript.all — newly passing:** `TextFieldHTML-v6`, `TextFieldHTML-v7`, `TextFieldHTML-v8`

**from_gnash/misc-ming.all — newly passing:** `DefineEditTextTest`

*Comparing `802674fd5caa` → `3c67568fe68e`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 600/647 (92.7%)
- **Duration:** 52m56s across 30 shards
- **Lines:** 106,001/114,967 matching (92.2%)
- **Avg test duration:** 4.8s — slowest: `register_class_swf6` (19.1s)

### from_gnash/actionscript.all

- **Pass:** 124/190 (65.3%)
- **Duration:** 11m21s across 30 shards
- **Lines:** 15,351/16,957 matching (90.5%)
- **Avg test duration:** 3.5s — slowest: `String-v8` (18.4s)

### from_gnash/misc-ming.all

- **Pass:** 62/102 (60.8%)
- **Duration:** 22m59s across 30 shards
- **Lines:** 2,829/4,577 matching (61.8%)
- **Avg test duration:** 13.5s — slowest: `matrix_test` (20.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m57s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 13.0s — slowest: `TextFieldTest` (17.6s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 3m50s across 30 shards
- **Lines:** 333/499 matching (66.7%)
- **Avg test duration:** 14.3s — slowest: `action_execution_order_test10` (17.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 4m58s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 16.5s — slowest: `tags_after_last_showframe` (17.8s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 12m47s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 8.3s — slowest: `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` (18.5s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 1.7s — slowest: `hitarea` (17.2s)
