# s26 w2-avm1-text-resolve: AVM1 dispatch-scope HOLDs (`__resolve` on clips, SWF≤7 wrap give-up, text edit paths, `setNewTextFormat` render colour, EI clip receiver)

**New files**
- `ruffle-tests/tests/swfs/regression/avm1_mc_resolve/` (`create_test_swf.py`, `avm1asm.py`, `test.swf`, `test.toml`, `output.txt`) — w1 fixture, Ruffle-exporter golden.
- `ruffle-tests/tests/swfs/regression/avm1_wrap_giveup_mixed_runs/` (same file set; SWF7) — w1 fixture, Ruffle-exporter golden.
- `ruffle-tests/tests/swfs/regression/ei_mc_this_receiver/` (same file set + `test_harness.c`) — new; golden analytic (no EI host in the exporter).
- `SWFRecompDocs/plans/session26-fanout-reports/w2-avm1-text-resolve-fixtures/` (HELD, need an outside oracle):
  `avm1_edittext_html_delete_runs/` (generator, `input.json`, `test.toml`, `output.txt`) and
  `avm1_set_new_text_format_render/` (generator, `test.toml`, `output.txt`, `output.expected.png` = our after-render, analytic).
  The generators import `../../w1-avm1-dispatch-scope-fixtures/avm1asm.py`; `test.swf` is not committed (run the generator).
- this report; `w2-avm1-text-resolve.patch`.

Base: `origin/master` `73915f55`. Corpus: `download_tests.sh avm1 from_gnash text visual fonts from_shumway`, 2026-11-23
(upstream Ruffle `3e98d9ba6`). Ruffle source: blobless clone at `3e98d9ba6`. Box: Dawn OK (lavapipe).

## Verdicts

| # | item | verdict | fixture: master → patch (graphics) |
|---|---|---|---|
| 1 | `__resolve` on a MovieClip never called (GetMember) | **GO, landed** | `regression/avm1_mc_resolve` 0/5 → **pass** |
| 2 | SWF≤7 wrap give-up missing from `ng_computeScrollMixedFont` | **GO, landed** (scroll path) | `regression/avm1_wrap_giveup_mixed_runs` 0/2 → **pass**; SWF8 twin unchanged |
| 2b | ... and from `tag.c`'s render wrap | **premise REFUTED**: the native renderer has no soft wrap at all | n/a (new lead below) |
| 3 | Backspace / Delete / IME drop the HTML run table | **GO, landed**. Cut / select-all clears kept on the invalidate path (equivalent result) | `avm1_edittext_html_delete_runs` 1/4 → **pass** (HELD: analytic) |
| 3b | the HELD `avm1_edittext_html_typed_runs` golden | **settled for the fixture**: Ruffle's "all 0" is a Ruffle boundary bug | passes on master already (insert path landed in `a18a9cc61`) |
| 4 | `setNewTextFormat` repaints existing text | **GO, landed**, and the bigger sibling bug: `setTextFormat` on a plain field never repainted | `avm1_set_new_text_format_render` trace pass→pass, **pixel FAIL (2625 px) → PASS** (HELD: golden is ours) |
| 5 | EI `addCallback(name, clip, fn)` receiver | **GO, landed**. Worse than the brief said: master **segfaults** | `regression/ei_mc_this_receiver` SEGFAULT → **pass** |
| 6 | stale comments (`_is_mc_nav` stop/play, `getNextHighestDepth`) | done | — |

**Priced corpus flips: 0.** No baseline-failing row reaches these paths (sweep below). Every GO is a correctness fix
pinned by a fixture.

## EXPECTED-FLIP LEDGER (for the coordinator's CI check)

- **Trace, flips fail→pass (new regression rows; absent from the baseline = new, not yield):**
  `regression/avm1_mc_resolve`, `regression/avm1_wrap_giveup_mixed_runs`, `regression/ei_mc_this_receiver`.
- **Trace, everything else:** no movement expected (316-row graphics sweep: 0 status movers).
- **Pixels:** no movement expected. The render canary (147 rows, 234 PNGs, below) is md5-identical. The plain-field
  colour change only alters fields whose span model holds a colour that differs from `textColor`
  (after `setNewTextFormat`, or a plain-field `setTextFormat`); the canary and the 63 text-image rows added to it
  contain none that moved.
- **No-graphics:** none (22-row no-graphics sweep: 0 movers).

## Per-test before/after (same box; before = clean `origin/master`, after = patch; `--mode=graphics`)

| test | before | after |
|---|---|---|
| avm1_mc_resolve (w1, exporter golden) | MISMATCH 0/5 | PASS |
| avm1_wrap_giveup_mixed_runs (w1, exporter golden, SWF7) | MISMATCH 0/2 (`1/8`, `4/7`) | PASS (`1/1`, `1/1`) |
| avm1_wrap_giveup_swf8 (SWF8 twin, A/B only) | `1/8`, `4/7` | identical |
| ei_mc_this_receiver (new) | **SEGFAULT** | PASS |
| avm1_edittext_html_delete_runs (new, HELD) | MISMATCH 1/4 (every colour 0 after the first key) | PASS |
| avm1_set_new_text_format_render (new, HELD) | trace PASS, image FAIL (2625 outliers, max 255) | trace PASS, image PASS |
| avm1_edittext_html_typed_runs (w1, HELD) | PASS | PASS |
| avm1_set_new_text_format_color (w1, trace lock) | PASS | PASS |
| the other 6 w1 fixtures (bare_mc_method_scope, create_text_field_depth, device_edittext_xscale, hittest_hairline, timer_function_form_activation, type2_mc_receiver_dispatch) | PASS | PASS |

Render of `avm1_set_new_text_format_render` (four black "II" fields; red = 0xFF0000):

| field | script | master | patch = Flash/Ruffle |
|---|---|---|---|
| f1 | `setNewTextFormat({color:red})` | **red** | black |
| f2 | `setTextFormat({color:red})` | **black** | red |
| f3 | `setTextFormat(0, {color:red})` | **black, black** | red, black |
| f4 | `setNewTextFormat(red); text = "II"` | red | red |

f2/f3 are the more game-visible half: on master a plain (non-HTML) field never showed a colour applied with
`setTextFormat` (the span model held it; the renderer read `textColor`).

## Mechanism and patch scope (functions touched)

**`SWFModernRuntime/src/actionmodern/action.c`**
- `invokeResolveFunction` → now a wrapper over new `static invokeResolveFunctionEx(.., MovieClip* recv_mc)`. With a clip
  receiver it binds `this` as MOVIECLIP and adds `INV_EVENT_THIS_MC | INV_MC_THIS_NULL_PTR` (the watch/getter pairing).
  Every existing caller passes NULL: byte-for-byte the old path.
- `actionGetMemberImpl`, MOVIECLIP arm, final miss (just before `pushUndefined`): look up `__resolve` on the clip's
  `dynamic_props` (its explicit registerClass chain included), else on the version's `MovieClip.prototype` chain (not
  for timeline Video, not when an explicit `__proto__` was set), and call it. Ruffle `Object::get` →
  `get_opt(.., call_resolve_fn = true)` applies to stage objects. (CallMethod on a clip already had its own hand-rolled
  `__resolve` hook: `regression/mc_resolve_type1_args`.)
- `tf_ps_on_typed` (comment only) is now also called with `ins_len = 0` from `actionTextControlBackspace` and
  `actionTextControlDelete` (partial deletes, before the text store; skip `tf_invalidate_run_table` when handled) and
  from `actionTextFieldImeCompose` (the replaced composition range, captured before `ime_start/ime_len` move). Ruffle:
  every one of these is `replace_text(from, to, ..)`. The select-all clears and `actionTextControlCut` (which clears the
  whole field) keep the invalidate: deleting all text leaves no runs either way.
- New `static tf_ps_render_runs()` and its call in `actionIterateTextFieldGlyphs` (plain-text branch only): a field
  with a TFPlainSpans model paints the model's colours. Uniform → replaces `text_color` (the single synthesized run and
  `info.text_color` follow). Mixed → per-span runs by UTF-8 byte range (align from the tag; font_height unchanged).
  The lookup does NOT bump the span table's LRU stamp (rendering must not change eviction order). A field without a
  model still reads `textColor`.
- `tf_ps_set_new_text_format`: `tf_ps_ensure_spans` first, so the text already in the field is pinned to its current
  format before the `setNewTextFormat` arm writes `textColor` (which `tf_ps_base_fmt` reads).
- `actionEI_callInternalInterface`: a MOVIECLIP `cb->this_obj` is bound as MOVIECLIP with the flag pair (type-1 and
  type-2). Master bound the raw `MovieClip*` with an OBJECT tag, so `this.v` read a MovieClip as an ASObject: a
  **segfault** in the fixture. `typeof this` is now `movieclip`.
- `actionCallFunction`: two stale comments (`getNextHighestDepth` "operates on root"; `_is_mc_nav` stop/play "no-op");
  the four empty `_is_mc_nav == 2..5` arms collapsed into one documented unreachable arm.

**`SWFModernRuntime/src/libswf/ng_shared.c`**
- `ng_computeScrollMixedFont`, word-wrap break loop, the `cur_line_w == 0` (start-of-line, too-wide word) arm: the
  `!is_swf8` give-up ported from `ng_wrap_count_lines`. When at most one character of the first word fits, the rest of
  the hard line stays on this line (the run heights over that remainder feed the line height). Ruffle `wrap_line`:
  `if line_end <= 1 { return None }`, and every later span on that line then sees `remaining_width < 0` and gives up
  too, so consuming the whole hard line is exact.

Nothing in `tag.c`, `swf.c`, `swf_core.c`, `tag_stubs.c` or any `#ifdef NO_GRAPHICS` arm. (The `setNewTextFormat`
CallMethod arm is under `NO_GRAPHICS || OFFSCREEN_RENDER`; I touched only `tf_ps_set_new_text_format`, which it calls.)

**Sibling overlap:**
- `n-collector-uaf` (TextFieldGlyphInfo builders / clip removal): I touch only the plain-text branch of
  `actionIterateTextFieldGlyphs`, plus a new static.
- `w2-edittext-border-cx`: no `tag.c` edits from me.

## Refutations / premise attacks

- **7b render half ("`tag.c`'s render wrap breaks per character"): refuted.** `textfield_glyph_render_cb` lays out
  paragraphs only at `\n`/`\r`/0xFE/0xFF. `TextFieldGlyphInfo` carries no `wordWrap` flag and `actionIterateTextFieldGlyphs`
  inserts no soft breaks. A word-wrapped field renders as one clipped line per hard paragraph, so the give-up is
  already what renders. See the new lead below.
- **5a HELD golden (`avm1_edittext_html_typed_runs`, "Ruffle runner says colour 0 after inserting at index 0").**
  Re-derived from `FormatSpans::replace_text` (`core/src/html/text_format.rs:1562`, unchanged at `3e98d9ba6`):
  - For `from = to = 0`, `get_span_boundaries(0, 0)` computes `end_pos` from `resolve_position_as_span(to.saturating_sub(1))`
    = span 0, so `end_pos = 1`.
  - `new_tf = spans[1]` (the appended "C", default black), and `drain(0..1)` **deletes the red "AB" span**. `normalize()`
    then pads with `default_format`, which is exactly the old runner's `c0=c1=c2=0`.
  - For any `to > 0` the same code keeps the neighbours, so this is a saturating-subtract artifact at index 0, not a
    format rule.
  - Flash never reformats existing text on insert, and the typed char takes the caret's format (red).
  - Recommendation: the fixture's prediction (red) is Flash-correct. If landed, it belongs in
    `RUFFLE_VS_FLASH_DIFFERENCES.md`. It needs a Flash capture to be an outside-oracle golden (LOCAL ORACLE REQUESTS).
- **5b scope understated:** besides `setNewTextFormat` repainting, plain-field `setTextFormat` was invisible in
  pixels (f2/f3 above).
- **EI lead priced as "XS, unprobed":** it is a crash (type confusion), not a wrong `this`.

## Gate: argued sweep (patch vs the latest CI rows, `a18a9cc61`, which already carries w1's landing)

All single-test runs, `-P 2`. Status compared row by row with the CI JSON. For failing rows, the diff ("−" line count)
is compared too.

- **Graphics, 316 rows: 0 status movers.**
  - **avm1, 134 rows:** w1's 39 rows, plus every `edittext_*`, `textfield_*` and `text_format*`, every `*resolve*`,
    every `external_interface*`, and `as_broadcaster`, `asnew`, `super_edge_cases`, `coerce_to_object_monkeypatch`,
    `amf_serialize_typed_objects`, `hitarea_sweep`, `registerclass*`, `add_property*`.
  - **from_gnash, 24 rows:** w1's 16, plus `ResolveEventsTest`, `Object-v5..v8` and `array-v5..v8` (the
    `__resolve`-using SWFs).
  - **text, 9 rows.**
  - **The whole `regression/` suite, 149 rows:** all pass. 7 of them postdate the CI run, so they are ABSENT from its
    JSON. They are new landings, not movers.
  - **Failing rows are unchanged:**
    - `movieclip_hittest_shapeflag` −6 (ACCEPTED Cat 8);
    - `native_objects_swf6` −1;
    - `external_interface_monkeypatch`: −122 on this box, and a clean-master worktree run on the same box gives a
      byte-identical diff. The CI JSON's −135 is a counting difference, not movement.
  - The ruffle_matched rows (gnash MovieClip/TextField/TextFormat/Object/array/with, etc.) stay ruffle_matched.
- **No-graphics, w1's 22 rows: 0 movers** (same failing-row diffs).
- **Render canary:** `render_canary.py capture` before (clean master) / after (patch).
  - The list is the standing `render_canary_tests.txt` minus its 34 `avm2/` members, plus 63 avm1/text/visual/fonts/
    shumway image rows whose names match edit/text/font/html/scroll.
  - Result: 147 tests, 234 PNGs, **IDENTICAL 234, DIFFERS 0**, and no trace or image status change.
  - The AVM2 members were skipped because every edit sits on an AVM1-only path. `ng_computeScrollMixedFont`'s only
    callers are in `action.c`.
- **Fidelity:** absolute pixel verdicts were not claimed for the corpus. Only A/B md5 was used, which is valid on this
  box.

## Could not finish / completion mechanisms

- `avm1_edittext_html_delete_runs`, `avm1_set_new_text_format_render`, `avm1_edittext_html_typed_runs`: HELD out of
  `regression/` for want of an outside oracle (LOCAL ORACLE REQUESTS). Land each once its golden is confirmed.
- **Size/font have the same `setNewTextFormat` defect as colour.** That arm also writes `_tf_fontHeight` / `_tf_fontId`,
  which the plain render path reads, so existing text would resize. Not fixed. Completion: read the span model's
  size/face in `tf_ps_render_runs` the same way (S). Needs a two-size embedded-font fixture.
- `actionTextControlCut` / `actionTextControlCopy` act on the **whole** text, not the selection (Ruffle:
  `text[selection]`, `replace_text(sel.start, sel.end, "")`). Out of scope. Completion: XS, plus an `input.json` fixture
  with `SelectAll`-free selection.

## New unclaimed leads

- **The native renderer never soft-wraps `wordWrap` fields** (`tag.c` `textfield_glyph_render_cb`; no wrap input in
  `TextFieldGlyphInfo`). Every multi-line word-wrapped field draws as a clipped single line per paragraph.
  - Probably a large pixel family: any visual/avm1/gnash image row with wrapped text.
  - Price M–L: pass line breaks from `ng_computeScrollMixedFont`'s break loop, or a shared wrap iterator, into the
    renderer.
  - Owner: N/pixel line.
- `__resolve` through **GetVariable dotted paths** (`mc.zzz` as one GetVariable path string) is untested. Unprobed.

## LOCAL ORACLE REQUESTS

1. `w2-avm1-text-resolve-fixtures/avm1_set_new_text_format_render`: run `python3 create_test_swf.py test.swf`, then
   `exporter -s -f 1 --trace-log out.txt test.swf out.png`.
   - The prediction: f1 black, f2 red, f3 red+black, f4 red. Trace: 5 lines.
   - If the PNG matches `output.expected.png` (tolerance 2), land the dir in `regression/`, copying `avm1asm.py` in as the
     other landed fixtures do.
2. `w2-avm1-text-resolve-fixtures/avm1_edittext_html_delete_runs`: a **Ruffle test runner** run (TextControl Backspace
   / Delete replay).
   - Ruffle source predicts the staged `output.txt`; both deletes avoid the index-0 insert artifact.
   - If it matches, land it.
3. `w1-avm1-dispatch-scope-fixtures/avm1_edittext_html_typed_runs`: a **Flash** capture if one can be had. Ruffle is
   known to differ, by the artifact above.
