# s28 w1-text-edit-tail: AVM1 restrict/onChanged, setNewTextFormat paragraph keys, AVM2 selection-rect tint

**New files** (all under `session28-fanout-reports/`):
- this report;
- `w1-text-edit-tail-prototype.patch` = `git diff origin/master -- SWFModernRuntime SWFRecomp`
  (`action.c` +152/−13, `avm2_display.c` +10/−1). It applies cleanly to `origin/master` `d5f9726d`. The source files are
  reverted on the branch. It holds three compile-time switches, one per item, so wave 2 can land whichever answer Flash
  gives by flipping a single `#define`.
- `w1-text-edit-tail-fixtures/`, three Flash-capture-ready fixtures. Each has a `test.swf` that regenerates byte for byte
  from `create_test_swf.py`, plus `test.toml`, `output.txt` and the candidate outputs:
  - `avm1_edittext_restrict_onchanged/` (+ `avm1asm.py`, `input.json`, `candidate.{ruffle_fire_delete,fire_keep_selection,master_no_fire}.txt`), SWF md5 `7051f6d8…`
  - `avm1_set_new_text_format_paragraph/` (+ `avm1asm.py`, `input.json`, `candidate.{ruffle_defer,field_wide_now,master}.txt`), SWF md5 `4c7daca4…`
  - `avm2_edittext_selection_cxform/` (+ `Test.as`, `TestFont.ttf`, `build_swf.sh`, `candidate.{untinted_ruffle,tinted_master}.png`), SWF md5 `3d13ba83…`

**Box.** Cloud box. `SETUP_STATUS` is all OK (apt, Pillow, Dawn on lavapipe). Base is `origin/master` `d5f9726d`. Corpus:
`download_tests.sh avm1 avm2 visual` (upstream Ruffle master, ~2026-11-25; the blobless clone tip is `c2f7d24b7`). Fidelity
check: my `visual/definefont4` render is md5 `8edbd5a1`, the same as CI's actual PNG, with excess 15975, the same as the
s28 baseline. So local renders on this box are CI-grade.

## Verdicts (lead)

| # | item | verdict | flips | price |
|---|---|---|---|---|
| a | AVM1: a typed key that `restrict` filters out | **HOLD for Flash. Fixture and both prototypes are ready.** Premise refined: **Ruffle already fires onChanged here, and also deletes the selection.** Only we stay silent. | 0 corpus. The fixture moves, with 3 distinct outputs | XS (one `#define`) |
| b | AVM1: setNewTextFormat with leading/leftMargin/rightMargin/indent/blockIndent/letterSpacing | **HOLD for Flash on the deferral question. The getter half is GO-shaped whatever Flash says** (see below). Premise widened: master is wrong in more places than "only size/font are parked". | 0 corpus (gate: 74 + 37 rows, 0 movers). The fixture moves | S–M (span model gains paragraph keys) |
| c | AVM2: selection background under a colorTransform | **HOLD for Flash.** The fixture is reworked to be wrapper-safe and needs no mxmlc. Both renders are measured | 0 corpus (no image row tints a selected field; 4 selection rows md5/status unchanged) | XS (one `#define`) |

**Priced corpus flips: 0.** All three items are Flash-correctness behaviours pinned by new fixtures. Nothing lands in
wave 1.

## (a) restrict-filtered keystroke → onChanged?

**Premise attack.** The brief says "Flash may fire it as it does for a maxChars drop". The Ruffle side is not unknown:
- **Ruffle fires.** `core/src/display_object/edit_text.rs text_input` (at `c2f7d24b7`): `filter_allowed(&text)` returns
  `""`, then `replace_text(selection.start(), selection.end(), "")` deletes the selection, the caret is set, and
  `on_changed` runs. Ruffle's *maxChars* drop is the opposite case: it returns early (`available_chars() == 0`) before
  the filter, with no event. Ruffle is therefore inconsistent across the two drops. s27 showed Flash fires on the maxChars
  drop.
- **AVM2 corpus evidence: Flash fires.** `avm2/edittext_restrict_events` was written by Kamil Jarosz, whose input tests
  are recorded against Flash. Its golden has `text input: y, x` followed by **`changed: x`** for a `y` that `restrict="x"`
  filters out. We already pass it (the AVM2 path dispatches `change`). The open questions are therefore only (1) whether
  AVM1 behaves like AVM2 and (2) whether the filtered key deletes a live selection.
- **Ours** (`action.c actionTextFieldInput`): `if (new_len == 0) return;` runs before `tf_replace_selection`, so there is
  no edit and no onChanged.

**Fixture** `avm1_edittext_restrict_onchanged` (SWF8):
- Setup: an input field with `restrict "0-9"` and text `1234`, focused, with the selection at [1,3).
- Typed keys `X5Y`: `X` is filtered while the selection is live, `5` is allowed, and `Y` is filtered at a bare caret.
- A root `onEnterFrame` poller traces `state: <text> sel=b,e` on every change. This shows whether the selection was
  deleted even when no onChanged fires.

| candidate | trace (after `ready: 1234 sel=1,3`) |
|---|---|
| Ruffle: fire + delete selection (`TF_RESTRICT_DROP 1`, the prototype default; also `output.txt`) | `changed #1: 14 sel=1,1` / `state: 14 sel=1,1` / `changed #2: 154 sel=2,2` / `state: 154 sel=2,2` / `changed #3: 154 sel=2,2` |
| fire, keep the selection (`TF_RESTRICT_DROP 2`) | `changed #1: 1234 sel=1,3` / `changed #2: 154 sel=2,2` / `state: 154 sel=2,2` / `changed #3: 154 sel=2,2` |
| master: no fire (`TF_RESTRICT_DROP 0`) | `changed #1: 154 sel=2,2` / `state: 154 sel=2,2` |

All three were measured in our runtime, in graphics mode and also in no-graphics for the default.

**Prototype** (`actionTextFieldInput`, the restrict branch only):
- `1` calls `tf_replace_selection(app_context, props, NULL, 0)`. That deletes the selection (a no-op at a bare caret)
  and fires onChanged. Paste already behaves this way when restrict filters every character.
- `2` calls the `onChanged` handler only.
- One edge case remains: a filtered key into a field already full under maxChars. Variant 1 fires (since `ins_len == 0`
  skips the maxChars check), while Ruffle returns early. Flash fires on the maxChars drop anyway, so firing is the safer
  guess. A twin fixture can pin it if needed.

## (b) setNewTextFormat paragraph keys

**Premise attack.** The lead assumed "only size/font are parked; leading/margins/letterSpacing are written at once". The
measurement shows master is wrong in more places. Running the fixture on clean master (`candidate.master.txt`):
- **`getNewTextFormat()` loses leading/leftMargin/rightMargin/blockIndent/letterSpacing entirely** (`snf new L=0 lm=0 rm=0 in=10
  bi=0 ls=0`). Ruffle and Flash return what was set. The span model's `TFPSFmt` carries only character keys
  (size/colour/font/b/i/u), and `getNewTextFormat` overlays only `_tf_indent`.
- **`indent` leaks onto the existing text.** `getTextFormat(0).indent` reads the field-wide `_tf_indent` override in the
  `getTextFormat` arm, so it becomes 10 right after setNewTextFormat.
- **It is not specific to setNewTextFormat.** A scratch probe shows `setTextFormat({leading 20, leftMargin 30, …})`
  followed by `getTextFormat(0)` also reads `L=0 lm=0 rm=0 in=10 bi=0 ls=0` on a createTextField field. Plain fields never
  round-trip paragraph keys. Ruffle's `TextSpans` stores them per span. The probe was scratch-only and is not shipped;
  see "New unclaimed leads".
- **Typing into a plain field kept the old format.** `tf_ps_ensure_spans` stretched the last span. Ruffle's
  `TextSpans::replace_text` gives inserted text the format of the following span, or the *new text format* at the end.
  This affects colour/size too, not just paragraph keys. It is the whole point of setNewTextFormat, so Flash almost
  certainly agrees.

**Fixture** `avm1_set_new_text_format_paragraph` (SWF8):
- Setup: a multiline input field with text `AB\rCD`.
- `setNewTextFormat(TextFormat{leading 20, leftMargin 30, rightMargin 15, indent 10, blockIndent 5, letterSpacing 4})`.
- Then type `E` at the end, then `text = "AB\rCD"`.
- Traces: `getTextFormat(0)`, `getTextFormat(5)` (the typed char) and `getNewTextFormat()` after each step.
  `textWidth`/`textHeight` are traced only as `==`/`>` comparisons, because device-font metrics differ between hosts.

| line | Ruffle / defer (`TF_SNF_PARA_DEFER 1`, also `output.txt`) | field-wide now (`TF_SNF_PARA_DEFER 0`) | master |
|---|---|---|---|
| `snf fmt0` | all 0 | the new values | 0, but `in=10` |
| `snf new` | the new values | the new values | 0, but `in=10` |
| `snf w==w0 h==h0` | true true | false false | false false |
| `typed fmt0` | all 0 | the new values | 0, but `in=10` |
| `typed fmt5` | the new values | the new values | 0, but `in=10` |
| `typed h==h0` | true (*) | false | false |
| `after text= fmt0` | the new values | the new values | 0, but `in=10` |

(*) Ruffle takes line leading from the line's first span, but the line box takes `max_leading` over the line's spans
(`html/layout.rs:254/462/507`). So the analytic `typed h==h0 true` is the least certain Ruffle line, and Flash decides it.

**Prototype** (all in `action.c`):
- `TFPSFmt` gains trailing `pmask` + `para[6]`, plus the name tables `k_tf_ps_para_name`/`_len`.
- `tf_ps_merge_from_obj` reads the 6 keys. `tf_ps_fmt_eq` compares them.
- `tf_ps_base_fmt` clears `pmask`, so a field nobody formatted keeps master's base values: **this is why the gate shows 0
  movers.**
- `tf_ps_set_new_text_format` pins existing spans to the values `getTextFormat` reports now (tag defaults plus
  `_tf_indent`) before `_tf_*` is written. Under `TF_SNF_PARA_DEFER 0` it also stamps the new keys onto every span.
- `tf_ps_overlay_text_format` and `tf_ps_overlay_new_text_format` report the keys a span carries. A mix across spans
  gives null.
- The snf park table (`g_tf_snf`) gains `pmask/para`. `tf_snf_defer` parks the paragraph keys. `tf_snf_apply_pending`
  gains a `full` flag: `text=`/`htmlText=` pass 1 and write `_tf_leading` (twips) and the other keys; a typed insertion
  passes 0, which applies size/font as before and keeps the paragraph keys parked.
- The `actionCallMethod` setNewTextFormat arm skips the 6 immediate `_tf_*` writes while they are parked
  (`_snf_para_defer`).
- New `tf_ps_on_typed_plain`, called from `tf_replace_selection` when no run table took the edit. Typed text into a plain
  field gets the following span's format, or `newfmt` at the end (Ruffle `replace_text`).

**What is GO regardless of the Flash answer**: the `getNewTextFormat` paragraph keys, the end of the `indent` leak, and
`setTextFormat → getTextFormat` round-tripping paragraph keys. All three are plain getter/setter consistency, and both
Ruffle and the TextFormat model agree. Wave 2 still needs the capture to pick `TF_SNF_PARA_DEFER`. It should also re-gate
`TF_SNF_PARA_DEFER 0` if Flash picks it: only the default (1) was swept.

## (c) AVM2 selection-rect tint

**Ruffle** (re-read at `c2f7d24b7`): `render_selection_background_for_line` computes `color = if has_focus { BLACK } else
{ GRAY }`, then calls `context.commands.draw_rect(color, selection_box)`. `CommandList::draw_rect(color, matrix)`
(`render/src/commands.rs:144`) has no colour-transform argument, so the rect is untinted. Selected glyphs are pushed with
`ColorTransform::IDENTITY` for their own colour but stay under the field's stacked cx. We match that part already.

**Ours**: `avm2_display.c avm2_render_text` draws the selection rects with `cxid` (the field's full concatenated cx).

**Fixture rework.**
- The s27 fixture's constructor touched `stage`, which is null for a Loader child under `run_image.py`. It also had no
  SWF, because the cloud has no mxmlc.
- The new `create_test_swf.py` hand-assembles a document class `Test extends Sprite` (SymbolClass 0) with a full scope
  chain, using the same Abc/Code helpers as `regression/avm2_bitmapdata_draw_text_glyph_cx`.
- Its constructor registers an `addedToStage` closure, and when `stage` is already set (direct run) it dispatches that
  event itself. A script slot `g_done` makes the closure run once.
- The rows are unchanged from s27: control; field red tint; field +blue; parent-Sprite magenta tint; focused field
  green tint.
- The font is the Flash-validated DefineFont3 `TestFont`, copied byte for byte from the mxmlc-built
  `regression/avm2_bitmapdata_draw_textfield/test.swf`.
- `Test.as` and `build_swf.sh mxmlc` are the same program in AS3, kept as a fallback in case Flash's verifier rejects the
  hand ABC. Our runtime runs the hand ABC and traces `focus=true` / `sel=1,4` (`output.txt`) in graphics mode with
  `--recompile`.

**Measured renders** (graphics, tick 2), sampled at mid-row y = 14/44/74/104/134:

| row | `AVM2_SEL_RECT_TINT 0` (Ruffle; the prototype default) | `1` (master) |
|---|---|---|
| 0 control | rect 0x555555, glyphs white | same |
| 1 field red | rect **0x555555**, selected glyphs red | rect **0xFF0000**; the selected glyphs vanish into it |
| 2 field +blue | rect **0x555555**, glyphs white | rect **0x5555FF** |
| 3 parent magenta | rect **0x555555**, glyphs magenta | rect **0xFF00FF**; the glyphs vanish |
| 4 focused green | rect **0x000000**, glyphs green | rect **0x00C800**; the glyphs vanish |

3216 px differ between the two renders. Both PNGs are in the fixture dir as candidates; there is no
`output.expected.png`, because the golden must be Flash's. The prototype is the third argument of that one
`renderer_draw_rect` loop: `AVM2_SEL_RECT_TINT ? cxid : 0`. One question for the capture: does group alpha or a parent's
alpha reach the rect? None of the rows uses alpha, so a "tint=no" answer would leave that open. It is cheap to add an
alpha row if wave 2 wants it.

## Gate (prototype defaults `TF_RESTRICT_DROP 1`, `TF_SNF_PARA_DEFER 1`, `AVM2_SEL_RECT_TINT 0`)

| set | rows | result vs CI baseline `e1425f417` statuses |
|---|---|---|
| avm1 + regression (non-avm2) SWFs whose bytes contain `setTextFormat`/`setNewTextFormat`/`getTextFormat`/`getNewTextFormat`/`restrict`, or whose `input.json` types text, graphics | 74 (63 avm1 + 11 regression) | **0 movers**: 71 pass; `edittext_onscroller` and `textfield_props_swf5` are `ruffle_matched` in both; `globals_monkeypatch` is `output_mismatch` in both (it matched the scan only through the prototype-name list). All 4 image comparisons pass (`edittext_stylesheet`, `edittext_tag_indent`, `avm1_set_new_text_format_render`, `avm1_bitmapdata_draw_text_glyph_cx`) |
| the 37 of those that contain `setNewTextFormat`, re-run on frozen source (my variant toggle overlapped part of the first sweep) | 37 | **identical**, 0 movers |
| AVM2/visual image rows with `setSelection`/`alwaysShowSelection` | 4 | `avm2/edittext_always_show_selection` pass (max 0); `visual/edittext/edittext_selection_font_size` pass; `edittext_selection_leading` 12/12 pass; `visual/definefont4` fail 15975 = baseline, md5 `8edbd5a1` = CI. None of them uses colorTransform, so the switch cannot reach them |
| no-graphics: both AVM1 fixtures + regression `avm1_set_new_text_format_{instance,size,color}`, `avm1_edittext_maxchars_clips_insertion`, `avm1_edittext_cut_copy_selection` + avm1 `edittext_restrict`, `edittext_restrict_paste`, `textfield_maxchars`, `edittext_input` | 11 | all pass |
| AVM2 `edittext_restrict_events` (the Flash-golden restrict row), graphics, clean master | 1 | pass (the AVM2 path already fires `change` on a filtered key) |

Functions touched (all `action.c` unless noted):
- the `TFPSFmt` typedef;
- `tf_ps_merge_from_obj`, `tf_ps_fmt_eq`, `tf_ps_base_fmt`;
- the snf statics (`tf_snf_defer`, `tf_snf_apply_pending` + its 3 callers in `actionSetMember`/`tf_replace_selection`);
- `tf_ps_set_new_text_format`, `tf_ps_overlay_text_format`, `tf_ps_overlay_new_text_format`;
- new `tf_ps_on_typed_plain`;
- `tf_replace_selection`, `actionTextFieldInput`, the `actionCallMethod` setNewTextFormat arm;
- `avm2_display.c avm2_render_text`.

Not touched: `tag.c`, `swf.c`, `swf_core.c`, `tag_stubs.c`, the recompiler, `render_webgpu.c`, and the browser `#else`
setNewTextFormat arm.

## Completion mechanisms (every HOLD)
- (a): FLASH request 1, then set `TF_RESTRICT_DROP` (or inline the chosen branch) and land the fixture with the Flash
  golden in `regression/`. A Flash run that matches the master candidate means: drop the hunk, and file an RvF entry for
  Ruffle firing here.
- (b): FLASH request 2, then pick `TF_SNF_PARA_DEFER`. For `0`, re-gate the 37 setNewTextFormat rows first. If Flash
  matches neither candidate on the `typed` lines, the per-paragraph layout model is the residual: today's layout keys are
  field-wide, an M-sized arc.
- (c): FLASH request 3, then set `AVM2_SEL_RECT_TINT`. If Flash tints, keep master and add an RvF entry. Land the fixture
  with the Flash PNG as `output.expected.png`, plus a covering canary member: no standing canary row has a tinted
  selection.

## New unclaimed leads
- **The `_tf_indent` leak and the `setTextFormat` → `text=` path.** After `setTextFormat(fmt)` and then `text = "XY"`, our
  `getTextFormat(0)` reads `in=10` and all other keys 0. Ruffle reads the default format's values (0). The field-wide
  `_tf_indent` override in the `getTextFormat`/`getNewTextFormat` arms bypasses the span model. Removing it depends on
  the span model carrying paragraph keys (this prototype), so it is wave-2 cleanup. Fixture: a 3-line twin of the
  scratch probe (described in §b).
- **Typed text colour after setNewTextFormat on a plain field.** Master's typed text kept the old span's colour; the
  prototype's `tf_ps_on_typed_plain` fixes it. No corpus row or fixture pins the colour case on its own. A
  `regression/avm1_set_new_text_format_color` twin with a typed key would do it, and is worth a Flash capture.
- **Paste with no room under maxChars** (from s27) is still unprobed in Flash. `run_trace.py` has no clipboard.

## LOCAL ORACLE REQUESTS
1. **FLASH, trace, direct**: `w1-text-edit-tail-fixtures/avm1_edittext_restrict_onchanged`, `run_trace.py <dir> --type X5Y
   --type-after ready`. Compare against `candidate.{ruffle_fire_delete,fire_keep_selection,master_no_fire}.txt`. The
   SWF is shipped and is also rebuilt by `python3 create_test_swf.py test.swf`.
2. **FLASH, trace, direct**: `w1-text-edit-tail-fixtures/avm1_set_new_text_format_paragraph`, `run_trace.py <dir> --type E
   --type-after ready`. Compare against `candidate.{ruffle_defer,field_wide_now,master}.txt`. Device-font text, but only
   numbers and booleans are traced, so the Linux font token does not matter.
3. **FLASH, image + trace**: `w1-text-edit-tail-fixtures/avm2_edittext_selection_cxform`.
   - `run_trace.py <dir>`, direct. It should print `focus=true` / `sel=1,4`. If it gives a VerifyError or prints nothing,
     use `./build_swf.sh mxmlc` and capture `test.mxmlc.swf` instead.
   - `run_image.py <dir> -o flash.png --ticks 2`, **with and without `--screen`**. Whether `draw()` paints a TextField
     selection is unmeasured, so the screen grab is the tie-breaker.
   - Read the rect colour in the inter-glyph gaps of rows y≈14/44/74/104/134 and compare against
     `candidate.untinted_ruffle.png` / `candidate.tinted_master.png`.
   - Row 4 (focused) may depend on the projector window holding OS focus. Rows 1–3 settle the tint question on their own.
4. (fallback only) The Ruffle exporter on fixture 3 at tick 2, to confirm the untinted analytic for the RvF record if
   Flash tints.
