# s28 w2-text-edit-land: AVM1 restrict drop + setNewTextFormat paragraph keys landed with Flash goldens; AVM2 selection tint kept (RvF)

**New files**
- `SWFRecompDocs/plans/session28-fanout-reports/w2-text-edit-land-report.md` (this report)
- `SWFRecompDocs/plans/session28-fanout-reports/w2-text-edit-land.patch` = `git diff origin/master -- SWFRecomp
  SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <3 new fixture dirs>`
  (binary-safe: `--binary`; verified `git apply --check -R` on this branch and `git apply --check` on clean `origin/master` `5a326d8a`)
- `ruffle-tests/tests/swfs/regression/avm1_edittext_restrict_onchanged/` — `test.swf`, `test.toml`, `output.txt`
  (= Flash FP32 `avm1_edittext_restrict_onchanged.flash32.txt`), `input.json`, `create_test_swf.py`, `avm1asm.py`
- `ruffle-tests/tests/swfs/regression/avm1_set_new_text_format_paragraph/` — `test.swf`, `test.toml`, `output.txt`
  (= Flash FP32 `avm1_set_new_text_format_paragraph.flash32.txt`), `input.json`, `create_test_swf.py`, `avm1asm.py`
- `ruffle-tests/tests/swfs/regression/avm2_edittext_selection_cxform/` — `test.swf`, `test.toml`, `output.txt` (== Flash
  trace `focus=true`/`sel=1,4`), `output.expected.png` (= Flash FP32 `avm2_edittext_selection_cxform.draw.png`),
  `create_test_swf.py`, `Test.as`, `TestFont.ttf`, `build_swf.sh`

Modified: `SWFModernRuntime/src/actionmodern/action.c` (+126/−13), `ruffle-tests/render_canary_tests.txt` (+4: one
member at EOF). Not touched: `avm2_display.c`, `tag.c`, `swf.c`, `swf_core.c`, `tag_stubs.c`, `render_webgpu.c`, the
recompiler, `verify_output.py`.

**Box.** Cloud, `SETUP_STATUS` all OK (Dawn on lavapipe). Base `origin/master` `5a326d8a`. Corpus `download_tests.sh avm1
avm2 visual` (+ `from_shumway from_gnash fonts text` for the canary), upstream Ruffle master at download time (tip now
`d2a801a98`; the 5 flash_fixes applied). w1 proved this box CI-grade on `visual/definefont4` (md5 = CI actual).

## Verdicts (lead)

| # | item | verdict | flips |
|---|---|---|---|
| a | AVM1 restrict-filtered typed key | **GO, landed.** Flash FP32 == Ruffle: fires onChanged AND deletes the live selection. The `TF_RESTRICT_DROP` switch is gone; the filtered branch calls `tf_replace_selection(…, NULL, 0)` unconditionally | new row `regression/avm1_edittext_restrict_onchanged` passes (both modes); 0 corpus movers |
| b | AVM1 setNewTextFormat paragraph keys (leading/leftMargin/rightMargin/indent/blockIndent/letterSpacing) | **GO, landed.** Flash FP32 == Ruffle defer model. `TF_SNF_PARA_DEFER` switch and its field-wide-now arm deleted; the getter half (getNewTextFormat reports the keys, no `indent` leak onto existing text, typed text takes the new format) lands with it | new row `regression/avm1_set_new_text_format_paragraph` passes (both modes); 0 corpus movers |
| c | AVM2 selection rect under colorTransform | **Keep master (no code change).** Flash TINTS the rect; our master render equals `candidate.tinted_master.png` byte for byte. The prototype's `avm2_display.c` hunk is dropped. RvF text below | new row `regression/avm2_edittext_selection_cxform` (trace + image) passes; new canary member |

**Priced corpus flips: 0** (as w1 priced). The deliverable is Flash-correct behaviour pinned by three Flash-golden
regression rows.

## Patch scope (all `action.c`; functions named for the sibling map)

- `TFPSFmt` typedef: trailing `u8 pmask; double para[6]` + name tables `k_tf_ps_para_name`/`_len`.
- `tf_ps_merge_from_obj` (reads the 6 keys), `tf_ps_fmt_eq` (compares them), `tf_ps_base_fmt` (clears `pmask`: a field
  nobody formatted keeps master's base values — why the gate has 0 movers).
- `g_tf_snf` park table (+`pmask/para`), `tf_snf_defer` (parks the paragraph keys with size/font while text is
  present), `tf_snf_apply_pending(…, int full)` (`text=`/`htmlText=` pass 1 and write the `_tf_*` layout keys, leading in
  twips; a typed insertion passes 0 and keeps the paragraph keys parked). Callers: the two `actionSetMember` text arms
  (`full=1`), `tf_replace_selection` (`full=0`).
- `tf_ps_set_new_text_format`: pins existing spans' paragraph keys to what `getTextFormat` reports now (tag defaults +
  the field-wide `_tf_indent`) before anything is written; `tf_ps_normalize` after the merge.
- New `tf_ps_on_typed_plain`, called from `tf_replace_selection` when no run table took the edit: inserted text takes
  the following span's format, or `newfmt` at the end (Ruffle `TextSpans::replace_text`).
- `tf_ps_overlay_text_format` / `tf_ps_overlay_new_text_format`: report the keys a span carries (mixed → null).
- `actionCallMethod` setNewTextFormat arm: the 6 immediate `_tf_*` writes are skipped while `_snf_defer` (no separate
  flag any more).
- `actionTextFieldInput` restrict branch: a fully filtered key → `tf_replace_selection(app_context, props, NULL, 0)`
  (deletes the selection, no-op at a caret, fires onChanged), then return.

Removed vs the w1 prototype: both `#define` switches, the `TF_RESTRICT_DROP == 2` arm, the `!TF_SNF_PARA_DEFER`
field-wide arm, and the whole `avm2_display.c` `AVM2_SEL_RECT_TINT` hunk (master's `cxid` stays). No `#ifdef
NO_GRAPHICS` arm is touched, but the edited paths run in both modes, so both were gated.

## Headline before/after (same box, clean `origin/master` vs patch)

| test | mode | before | after |
|---|---|---|---|
| `regression/avm1_edittext_restrict_onchanged` | graphics | output_mismatch (1/6 lines) | **pass** 6/6 |
| ″ | no-graphics | output_mismatch (1/6) | **pass** 6/6 |
| `regression/avm1_set_new_text_format_paragraph` | graphics | output_mismatch (5/12) | **pass** 12/12 |
| ″ | no-graphics | output_mismatch (5/12) | **pass** 12/12 |
| `regression/avm2_edittext_selection_cxform` | graphics | trace pass; image pass 230 ch > 48 (limit 500), max 81; md5 `f3380a6f` | identical (md5 `f3380a6f`) |

### (c) image budget (Flash golden = `draw.png`; `--screen` == `draw()` 0/0 per the coordinator)

Channels whose |diff| exceeds t, vs the Flash golden:

| render | max | t=2 | t=16 | t=32 | **t=48** | t=64 | t=80 |
|---|---:|---:|---:|---:|---:|---:|---:|
| ours (master == patch == `candidate.tinted_master.png`, md5 `f3380a6f`) | 81 | 1506 | 922 | 475 | **230** | 60 | 10 |
| Ruffle untinted (`candidate.untinted_ruffle.png`) | 200 | 7930 | 7348 | 6625 | **5884** | 5500 | 5312 |

**Chosen: `tolerance = 48`, `max_outliers = 500`.** Ours 230 (2.2× headroom for raster drift); the untinted render
5884, 11.8× over the limit. Our residual is glyph raster only (all gap pixels match Flash).

## Gate

| set | rows | result |
|---|---|---|
| w1 sweep: avm1 + regression (non-avm2) SWFs containing `setTextFormat`/`setNewTextFormat`/`getTextFormat`/`getNewTextFormat`/`restrict`, or whose `input.json` types text. Re-derived by the same scan: 74 + my 2 new rows = 76 (37 + 1 contain `setNewTextFormat`) | 76 | graphics **and** no-graphics, before vs after on this box: **only movers are the 2 new rows (fail → pass)**. Unchanged: `edittext_onscroller`, `textfield_props_swf5` `ruffle_matched`; `globals_monkeypatch` output_mismatch (as w1/baseline). All image comparisons in the set unchanged (`edittext_stylesheet`, `edittext_tag_indent`, `avm1_set_new_text_format_render`, `avm1_bitmapdata_draw_text_glyph_cx` pass) |
| other avm1 `edittext`/`textfield`/`selection` rows | 28 | graphics + no-graphics before vs after: 0 movers, all pass |
| avm2 `edittext`/`textfield`/`selection` rows | 88 | after (graphics) vs CI baseline `e1425f417` statuses (trace + image status): **0 movers** (83 pass, 5 ruffle_matched = baseline). Not re-run before-leg: the patch touches no AVM2 code |
| visual `edittext`/`textfield`/`selection` rows | 24 | after (graphics) vs CI baseline: **0 movers** (22 pass, 2 ruffle_matched) |
| render canary (`render_canary_tests.txt`, all tiers, 186 tests incl. the new member) | 186 | before (clean master) vs after: **252/252 PNGs md5-IDENTICAL**, 0 trace-status changes, 0 image-status changes. The new member renders the same in both legs (no code change for (c)), as expected |

## EXPECTED-FLIP LEDGER (for CI)

Trace axis (graphics and no-graphics):
- `regression/avm1_edittext_restrict_onchanged`: NEW row → **pass**.
- `regression/avm1_set_new_text_format_paragraph`: NEW row → **pass**.
- `regression/avm2_edittext_selection_cxform`: NEW row → **pass** (graphics; AVM2 trace).

Pixel axis (graphics):
- `regression/avm2_edittext_selection_cxform` `output`: NEW comparison → **pass** (230 channels > 48, limit 500, max 81).
  The image comparison count grows by 1.

Every other row: no change on either axis (no corpus flips). A corpus mover in CI is a regression to report.

## RvF entry text (c) — for the coordinator to append to `RUFFLE_VS_FLASH_DIFFERENCES.md`

```
## AVM2 TextField selection background is tinted by the field's colour transform (Ruffle draws it untinted)

<!-- image-axis: regression/avm2_edittext_selection_cxform output -->

**Test:** `regression/avm2_edittext_selection_cxform` (hand-assembled ABC; 5 rows of "ababa", setSelection(1,4),
alwaysShowSelection: control / field cx red / field cx +blue / parent-Sprite cx magenta / focused field cx green).

**Flash Player 32** (LNX 32,0,0,465, direct, tick 2; `draw()` and the `--screen` grab are identical): the selection
rect is drawn under the field's full concatenated colour transform — the gap pixels read 0xFF0000 / 0x5555FF /
0xFF00FF / 0x00C800 on rows 1-4 (0x555555 on the control row).

**Ruffle** (`core/src/display_object/edit_text.rs` `render_selection_background_for_line` at `c2f7d24b7`):
`context.commands.draw_rect(color, selection_box)`; `CommandList::draw_rect` (`render/src/commands.rs`) takes no
colour transform, so the rect stays 0x555555 (unfocused) / 0x000000 (focused) under any tint.

**Ours:** `avm2_display.c avm2_render_text` draws the rects with the field's concatenated cx (`cxid`) = Flash. Our
render vs the Flash golden: 230 channels > 48 (glyph raster only); Ruffle's untinted analytic render: 5884 > 48.

**Decision:** match Flash (keep the tint). The fixture's `output.expected.png` is the Flash capture (tolerance 48,
max_outliers 500), so a regression to Ruffle's untinted rect fails by ~12x the budget.
```

No RvF is needed for (a)/(b): Flash == Ruffle on both.

## Refutations / residuals
- **(c) premise "Ruffle is the reference" is refuted by Flash.** The w1 prototype default (`AVM2_SEL_RECT_TINT 0`,
  Ruffle) would have been a Flash regression; it is not landed.
- **(a) maxChars-full edge.** A filtered key into a field already full under `maxChars` now fires onChanged (the empty
  insertion skips the maxChars check); Ruffle returns early there. Flash fires on the maxChars drop itself (s27), so
  firing is the likelier Flash answer, but it is unmeasured. Completion: a twin fixture (`maxChars=4`, text `1234`,
  type `X`) under LOCAL ORACLE REQUESTS.
- The `typed h==h0 true` line (w1's least-certain Ruffle line) is confirmed by Flash.

## New unclaimed leads
- **`setTextFormat` → `getTextFormat` paragraph-key round-trip on a plain createTextField field**, and the
  `_tf_indent` leak after `setTextFormat(fmt); text = "XY"` (w1 leads, still open). The span model now carries the keys,
  so the field-wide `_tf_indent` overlay in the `getTextFormat`/`getNewTextFormat` arms can be retired once a Flash
  fixture pins the setTextFormat path. Not done here: no Flash golden for it.
- **Typed text colour after setNewTextFormat on a plain field**: `tf_ps_on_typed_plain` now gives typed text `newfmt`'s
  colour/size; no fixture pins the colour case alone (a typed-key twin of `regression/avm1_set_new_text_format_color`).
- **Alpha on the AVM2 selection rect** (group/parent alpha) is still unmeasured; none of the 5 rows uses alpha.

## LOCAL ORACLE REQUESTS
1. (optional, low priority) FLASH, trace, direct: a twin of `regression/avm1_edittext_restrict_onchanged` with
   `maxChars = 4` and text `1234` (bare caret at end), `--type X`: does Flash fire onChanged? Our patch fires. Build:
   edit `create_test_swf.py` setup (maxChars) — not shipped; request only if the coordinator wants the edge pinned.
