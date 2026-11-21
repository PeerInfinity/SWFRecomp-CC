# w2-tf-css: AVM1 htmlText styleSheet CSS + getTextFormat/setTextFormat args (session 23, wave 2)

**New files on this branch:**
- `SWFRecompDocs/plans/session23-fanout-reports/w2-tf-css-report.md` (this report)
- `SWFRecompDocs/plans/session23-fanout-reports/w2-tf-css.patch` (479 lines) = `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`. `git apply --check -R` passes against the branch tip.

No new source files and no new fixture dirs. The patch touches only `SWFModernRuntime/src/actionmodern/action.c` and appends 3 members to `ruffle-tests/render_canary_tests.txt`.

**Environment:**
- Cloud box; `SETUP_STATUS` all OK (apt, Pillow, Dawn).
- Base `origin/master` `6aeeee925`.
- Upstream tests are at Ruffle `0ddd12b6a` (`download_tests.sh avm1 from_gnash from_shumway text visual fonts avm2`).
  - Upstream master moved to `aa9f62a70` during the session. The only change is one added `visual/video/vp6_inter_frames` test: no row of mine, and not a canary member.
- Every run is a single test or a short list, with at most 2 parallel.
  - Exception: one early capture of the 5 new rows' actual output ran 5 single tests in parallel (a breach of `-P 2`). It was output capture only, not a measurement.

---

## 0. Verdicts and priced flips

| Row | Before (clean master, this box) | After | Verdict | Mechanism |
|---|---|---|---|---|
| `avm1/edittext_html_duplicate_attributes` (KF) | fail 241/247 | **pass 247/247** | **GO, +1** | prototype CSS/span/url/para-break hunks, productionized |
| `avm1/textfield_get_text_format_args` | fail 87/269 | **pass 269/269** | **GO, +1** | M1 + M2 + M3 (below) |
| `avm1/textfield_set_text_format_args` | fail 127/232 | **pass 232/232** | **GO, +1** | M1 + M4 |
| `avm1/textfield_set_text_format_text_change` | fail 1/37 | **pass 37/37** | **GO, +1** | M1 + M4 |
| `avm1/edittext_set_text_same` | fail 28/70 | fail 28/70 (unchanged) | **HOLD, L** | plain-text per-character format model (§3) |
| `avm1/edittext_set_text_same_after_edits` (KF) | fail 30/98 | fail 30/98 (unchanged) | **HOLD, L** | same as above, plus replaceText/replaceSel format inheritance (§3) |

**Total: +4 trace passes.** Each one is identical in graphics and no-graphics.
- The brief priced +1 (the headline). The 3 extra flips are new upstream rows, and all 3 share the M1 mechanism.
- The three newly passing args rows have **no `output.ruffle.txt` and no `known_failure`**, so Ruffle passes them too, and `pass` is the only possible landing.
- `edittext_html_duplicate_attributes` is KF, and its `output.ruffle.txt` differs from `output.txt` (lines 59 and 221). So it lands as a Flash-exact **`pass`, not `ruffle_matched`**.

**Brief premise attacked:** the brief said the five new rows were "unchanged by the prototype". That is true of the prototype, but **three of them fail on one mechanism unrelated to text formats**: `Function.prototype.apply` on a TextField method (M1). Each of those tests drives every case through `field.getTextFormat.apply(field, args)` / `field.setTextFormat.apply(field, args)`. Before this patch, every such call returned `undefined`, which is why the before-diff of `textfield_get_text_format_args` is `size=undefined …` on all 182 failing lines.

---

## 1. Mechanisms (owner `action.c`, current line numbers on the patched tree)

### Prototype hunks (productionized; no getenv gates existed in the text hunks)

- **`g_tf_parse_css_styles` / `tf_css_apply` / `tf_css_apply_tag`** (≈27162, static, just above `tf_parse_html`).
  - The selectors follow Ruffle `html/text_format.rs`:
    - `<p>` and `<a>` match the tag selector, then `.class`.
    - `<span>` matches `.class` only.
  - The class value is taken verbatim; `tf_get_attr` resolves a duplicated attribute to its last occurrence.
  - The selector sets color, size, bold, italic and underline.
- **`TF_TAG_SPAN` arm.** It is active only while a styleSheet is set, so `<span>` handling for unstyled fields does not change.
- **The html=true `htmlText` SetMember site** (≈54676). It reads `styleSheet._styles` for one `tf_parse_html` call and then resets the global.
- **getTextFormat `url`.** It is copied from the run's `href`. Before this, `url` was always `""` (a corpus-wide pre-existing bug).
- **Paragraph-break query.** A query that covers only a break-marker char reads the marker's own (paragraph) format (args form only).
- The prototype's non-text `action.c` hunks are **not** in this patch: `actionMcHasOwnOnUnload` and the `W1_UNLOAD_CHILD_FIRST` removeMovieClip order are owned by `w2-attached-timeline`.

### M1: `.apply` / `.call` on TextField.prototype methods (new)

**What was wrong:**
- The 8 TextField.prototype methods are name-only stubs (`function_type=1`, no `simple_func` or `advanced_func`), registered at ≈17130.
- A direct `field.getTextFormat(i)` dispatches by name inside `actionCallMethod`.
- The `Function.apply` arm (≈71428) handled a name-only stub only for `removeMovieClip`, and the `Function.call` arm (≈71095) for none at all. Both fell through to `pushUndefined`.

**Fix:**
- A static `tf_is_builtin_method()` (≈16974) identifies the 8 stubs by pointer.
- A new arm in each of `call` and `apply` re-dispatches through the existing `as_call_method()` (≈3094) on the MovieClip receiver, with the unpacked args.
  - It clears `g_override_this_set` first, so the MOVIECLIP override `this` set by the thisArg extraction cannot leak into `valueOf` callbacks run during index coercion.
  - It brackets the call with `g_call_depth`.
- The arm is narrow: only those 8 function pointers, and only with a MOVIECLIP thisArg (`.call` also requires `num_args >= 1`).

### M2: getTextFormat index args (Ruffle `avm1/globals/text_field.rs` `get_text_format`)

- **Before:** `varToDouble`, which does not call `valueOf`. A 1-arg query returned the run at that index, falling back to the field defaults past the end. Only `begin == end` returned the all-null format.
- **Now:**
  - The index args are converted with `ecmaToInt32(coerceVarToNumber(...))`, so `valueOf` runs, begin before end, and a throw propagates.
  - Argument forms: `[]` → (0, INT32_MAX); `[b]` → (b, b+1) with a wrapping add; `[b, e, …]` → (b, e).
  - Both ends clamp to [0, text_length].
  - **An empty range returns the all-null TextFormat.** This covers out-of-range indices, `b ≥ e` and empty text.
- Text length is taken from the HTML run table when one exists (the same index space getTextFormat already used), else from the `text` property.

### M3: getTextFormat range merge (Ruffle `TextSpans::get_text_format`)

- Every content run overlapping [begin, end) is merged. Color, size, font, url, bold, italic and underline each become **`null` when they differ** between runs.
- Before, a range query returned the first run's values, and only the no-arg form merged bold/italic/underline.
- The no-arg `textColor` override is now skipped when the merged color is mixed (Flash: `color=null`).

### M4: setTextFormat index args (Ruffle `set_text_format`)

- The index args are coerced at the top, before any format is read: `coerce_to_i32`, then `max(0)`.
- **`[b, fmt]` now formats ONE character, [b, b+1).** Before, it formatted b to the end of the text.
- **`[b, fmt]` with a throwing `valueOf`:**
  - Flash applies the format at index 0, then rethrows.
  - This is done with a local setjmp handler, the same pattern as trace's `[type Object]` print-then-propagate (≈35750). On a throw it restores SP, `scope_depth` and `g_call_depth`, then rethrows at `stf_done` after `applyAutoSize`.
- `[b, e, fmt]` with a throw propagates immediately, as in Ruffle.
- The format object is read after the coercion, so a `valueOf` that mutates the format (`fmt2.size = 50`) is seen. This was verified on `textfield_set_text_format_args` line 210.

---

## 2. Verification (all on this box: clean `origin/master` vs the patch)

### 2.1 Neighbour sweep: 69 rows × 2 modes

The 30-row list from `w1-trace-tail` §1 is a superset here. The rows are:
- **avm1 (51):** every row whose `.as` mentions getTextFormat or styleSheet, all `edittext_html*`, plus every row whose decompressed SWF contains `getTextFormat` / `setTextFormat` / `styleSheet`. The `.as` grep alone missed 20 SWF-only rows, such as `edittext_bullet`, `edittext_margins` and `textfield_props_swf5/6/7`.
- **from_gnash (7):** `actionscript.all/TextField-v6/v7/v8`, `TextFieldHTML-v6/v7/v8` and `misc-ming.all/DefineEditTextTest`.
- **from_shumway (6):** `acid/acid-textfield`, `acid/acid-text-4`, `stylesheet`, `captions`, `flash_text_TextField` and `slider_component`.
- **regression (5):** the suite's text rows: `avm1_parent_child_text`, `avm2_bitmapdata_draw_textfield`, `avm2_parent_child_static_text`, `avm2_static_text` and `avm2_timeline_text`.

**Result:** every row keeps its exact baseline status **and** matching/expected line count in both modes, except the 4 ledger rows. Baseline statuses match CI's `_results/results_graphics.json`, with one exception: `globals_monkeypatch` is 43/306 here vs 41/250 in `_results`, which is upstream drift (`w1-trace-tail` §5). It is unchanged by this patch.

Baseline and after for rows that are not passing (all unchanged):

| Row | Both legs, both modes |
|---|---|
| `avm1/globals_monkeypatch` | fail 43/306 (drift) |
| `avm1/native_objects_swf6` | fail 114/115 |
| `avm1/stylesheet_load` | fail 1/49 |
| `avm1/textfield_props_swf5` | ruffle_matched 173/175 |
| `avm1/edittext_set_text_same` | fail 28/70 |
| `avm1/edittext_set_text_same_after_edits` | fail 30/98 |
| `from_gnash/actionscript.all/TextField-v6` | fail 467/545 |
| `…/TextField-v7` | fail 476/570 |
| `…/TextField-v8` | fail 478/571 |
| `from_shumway/acid/acid-textfield` (KF) | ruffle_matched 9/15 |
| `from_shumway/flash_text_TextField` (KF) | ruffle_matched 0/0 |

The other 54 rows pass in both legs and both modes. Among them are the 5377-line `edittext_html_swf6/7/8`, `stylesheet` (283), `stylesheet_transform` (750), `edittext_stylesheet` (325), `textfield_props_swf6/7/8`, `edittext_default_format*`, `DefineEditTextTest` (153), `TextFieldHTML-v6/7/8` and all 5 regression rows.

### 2.2 Render canary (`render_canary.py`, md5)

- **Full standing set plus the 3 appended members:** 89 tests and 144 comparisons, `beforefull` (clean master) vs `afterfull` (patch). The result is **144 IDENTICAL, 0 DIFFERS, 0 APPEARED/VANISHED, no trace or image status changes.**
- The `afterfull` capture predates the final one-token edit (the `num_args >= 1` guard on the `.call` arm, §1 M1). That guard only prevents a NULL dereference on `field.getTextFormat.call()` with no args. No canary or sweep row makes that call, and the six headline rows were re-run after it with identical results (§2.3).
- **Appended at EOF (covering members):** the standing set had no AVM1 styleSheet or ranged-setTextFormat render member.
  - `avm1/edittext_stylesheet` (tier 1, CI-passing, max diff 31)
  - `from_shumway/acid/acid-textfield` (tier 2, KF)
  - `from_shumway/stylesheet` (tier 2, KF)
- **Fidelity:** I did not do the absolute-vs-CI-PNG fidelity check, because no absolute pixel verdict is claimed. A/B md5 is the bar used.

### 2.3 Final headline re-run (after the guard edit)

| Row | graphics | no-graphics |
|---|---|---|
| `edittext_html_duplicate_attributes` | pass 247/247 | pass 247/247 |
| `textfield_get_text_format_args` | pass 269/269 | pass 269/269 |
| `textfield_set_text_format_args` | pass 232/232 | pass 232/232 |
| `textfield_set_text_format_text_change` | pass 37/37 | pass 37/37 |
| `edittext_set_text_same` | fail 28/70 | fail 28/70 |
| `edittext_set_text_same_after_edits` | fail 30/98 | fail 30/98 |

---

## 3. HOLD: `edittext_set_text_same` and `edittext_set_text_same_after_edits` (L)

Both rows use **plain-text (html=false) fields**. They need Flash's per-character format model on non-HTML fields, which we do not have: `tf_find_table()` is NULL for a plain field, and the format lives in field-level `_tf_*` props.

The diffs show four separate gaps:
1. `setTextFormat(big)` on a plain field never reaches `getTextFormat`: sizes stay 12 where Flash gives 30.
2. `setNewTextFormat(mid)` is not reflected in `getNewTextFormat().size` (12 vs 20). Its `_tf_fontHeight` is shared with setTextFormat's textWidth bookkeeping.
3. The same-text rule:
   - `text = <same text>` keeps the per-char formats.
   - Different text resets them to the new text format.
   - Setting the text after `setNewTextFormat` re-formats it to the new format.
4. `textColor =` recolors every character. after_edits adds `replaceText` / `replaceSel` format inheritance (the inserted text takes the format of the last replaced span, or the new text format). One htmlText row also shows `length=2` vs Flash's `1`.

**Completion mechanism:** give plain fields a TFRunTable (format spans) on first `setTextFormat`, keep it across same-text `text=` writes and drop it on different text, and route getNewTextFormat through a stored new-text-format record. This changes the glyph renderer's input for every plain field touched by `setTextFormat`, so it needs a full graphics `full` run plus an images canary.
- **Size:** L.
- **Gain:** +1 (`edittext_set_text_same`; Ruffle passes it, no sidecar).
- `after_edits` is KF. Its `output.ruffle.txt` differs in its `new=` column, so a Flash-exact pass there needs the replaceText/replaceSel inheritance too.

---

## 4. EXPECTED-FLIP LEDGER (for CI grading)

**Trace axis, both modes (`graphics` and `no-graphics`); fail → pass:**

| Test | Before | After |
|---|---|---|
| `avm1/edittext_html_duplicate_attributes` | output_mismatch 241/247 | **pass 247/247** (KF, Flash-exact; must NOT read `ruffle_matched`) |
| `avm1/textfield_get_text_format_args` | output_mismatch 87/269 | **pass 269/269** |
| `avm1/textfield_set_text_format_args` | output_mismatch 127/232 | **pass 232/232** |
| `avm1/textfield_set_text_format_text_change` | output_mismatch 1/37 | **pass 37/37** |

**Pixel axis:** no expected moves. None of the 4 flip rows has `[image_comparisons]`, and every swept image-bearing row (`edittext_stylesheet`, `edittext_tag_indent` and the 5 shumway KF rows) is md5-identical in the canary.
- Any pixel move in CI is outside this patch's measured footprint and should be reported to me as a regression.
- One caveat: `setTextFormat(b, fmt)` now formats one character instead of b..end, which in principle changes rendering for any field that calls it. No CI image row I could find does so.

**Expected unchanged (watch list):** every row in §2.1, notably:
- `edittext_html_swf6/7/8`, `stylesheet*`, `edittext_stylesheet`, `textfield_props_swf5..8`
- `from_gnash` `TextField-v6/7/8` (467/545, 476/570, 478/571) and `TextFieldHTML-v6/7/8`
- `from_shumway/acid/acid-textfield` (KF, ruffle_matched 9/15)

**Recommended CI:**
- `graphics`, `categories=all`, plus the `no-graphics` leg (shared code: the getTextFormat/setTextFormat arms sit in `NO_GRAPHICS || OFFSCREEN_RENDER` regions; the call/apply arms are mode-agnostic).
- No recompiler change, so `--recompile` is not needed.
- `full` is not needed: no AVM2 runtime/emission change. Optionally run `full` for the misc `text` group.

---

## 5. Patch scope and sibling notes

- **Files:**
  - `SWFModernRuntime/src/actionmodern/action.c`: 14 hunks.
  - `ruffle-tests/render_canary_tests.txt`: +10 lines at EOF.
- **Hunk sites:**
  - ≈16974: `tf_is_builtin_method`.
  - ≈27162–27690: CSS helpers and `tf_parse_html` arms.
  - ≈54676: htmlText setter.
  - ≈71095: `Function.call` arm.
  - ≈71428: `Function.apply` arm, inserted **immediately before** the "Built-in MC method (e.g., removeMovieClip) applied to a target" arm.
  - ≈73155–73760: setTextFormat / getTextFormat.
- **Sibling contact:**
  - `w2-attached-timeline` owns the removeMovieClip unload order (≈75700 on master) and the attached pump. None of my hunks touch those lines. My apply-arm insertion is adjacent to the apply-arm removeMovieClip dispatch (≈71431 on master). If that sibling edits that arm, expect at most a context-only rebase; there is no semantic overlap.
  - `w2-crossvm-legf` (Selection/focus): no overlap.
- **Removed from the prototype:** the `[w1-trace-tail s23 prototype]` comment tags, and the `actionMcHasOwnOnUnload` / `W1_UNLOAD_CHILD_FIRST` hunks (not text).

## 6. Not finished, with completion mechanisms

1. **The `edittext_set_text_same*` HOLD** (§3): a plain-field format-span model. L, +1 (+1 more for after_edits with the replace-inheritance).
2. **There is no regression fixture for `.call` on TextField methods.** `.apply` is covered by three corpus rows; `.call` shares the dispatch but has no corpus row. A fixture needs an outside oracle, which is LOCAL ORACLE REQUEST 1 below.

## New unclaimed leads

1. **Other name-only built-in stubs probably have the same `.apply` / `.call` hole.** Apply dispatches only `removeMovieClip` by name; `.call` dispatches none. Any `X.prototype.method.apply(obj, args)` where the method is a name-only stub returns undefined. A census of `function_type=1` stubs with NULL funcs (MovieClip, Sound, Color, Selection, etc.) against corpus `.apply(`/`.call(` usage could find more cheap rows. The fix pattern is §1 M1.
2. **Index-space caveat.** getTextFormat and setTextFormat index the HTML run table's internal UTF-8 byte text. setTextFormat skips break markers when mapping plain→internal indices; getTextFormat does not. Both are right for ASCII text without `<p>`, but can diverge on non-ASCII HTML text or multi-paragraph ranges. No current row exposes it.

## LOCAL ORACLE REQUESTS

1. **Optional fixture for M1 `.call`.** A minimal AVM1 SWF8 that runs, on an html=true field with `htmlText = "<font size='10'>A</font><font size='20'>B</font>"`:
   - `trace(field.getTextFormat.call(field, 1).size)`
   - `field.setTextFormat.call(field, 0, fmt)` (with `fmt.size = 30`), then a trace of both chars' sizes
   - `trace(typeof field.getDepth.call(field))`

   Please provide a Ruffle exporter trace (1 tick). Expected `20`, `30,20`, `number` (Ruffle runs native methods for any `this`). It would land as `regression/avm1_textfield_method_call`.
