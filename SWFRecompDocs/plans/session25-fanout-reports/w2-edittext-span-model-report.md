# w2-edittext-span-model: AVM1 per-character format span model (session 25, wave 2)

**New files on this branch:**
- `SWFRecompDocs/plans/session25-fanout-reports/w2-edittext-span-model-report.md` (this report)
- `SWFRecompDocs/plans/session25-fanout-reports/w2-edittext-span-model.patch` = `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`.
  - It touches **one file**, `SWFModernRuntime/src/actionmodern/action.c` (+714/−5).
  - It is rebased onto `origin/master` `ab22f11e`. `git apply --check -R` passes on the branch tip.
- No new source files, no new fixtures, and no `render_canary_tests.txt` change. The change is not visible to the renderer (§3), so there is no change class for a canary member to cover.

**Environment:**
- Cloud box. `SETUP_STATUS` is all OK (apt, Pillow, Dawn/lavapipe).
- Ruffle clone at `3ac8dcb07`. `download_tests.sh` prints no upstream SHA.
- Categories downloaded: `avm1 from_gnash from_shumway text visual fonts timeline swf`, plus `regression` from git.
- Graphics mode unless stated otherwise.

---

## 0. Verdicts and expected flips

**GO: land it.** Both headline rows flip to **`pass`**, so the yield is **+2 effective**.
- `_after_edits` is KF, and Flash-exact is better than the ruffle_matched the brief priced.
- No status regressions anywhere in the sweep.
- **0 pixel moves** (74/74 md5-identical).

### EXPECTED-FLIP LEDGER (for the coordinator's CI check)

| Axis | Test | CI baseline | Expected after | Note |
|---|---|---|---|---|
| trace | `avm1/edittext_set_text_same` | output_mismatch 28/70 | **pass 70/70** | no KF. **+1 pass** |
| trace | `avm1/edittext_set_text_same_after_edits` | output_mismatch 30/98 (KF) | **pass 98/98** | KF and Flash-exact, so it lands as `pass`, not `ruffle_matched`. **+1 effective** |
| trace (lines only) | `from_gnash/actionscript.all/TextField-v7` | output_mismatch 476/570 | output_mismatch **488/570** | +12 lines: replaceText checks TextField.as:1147-1169. No new mismatched line |
| trace (lines only) | `from_gnash/actionscript.all/TextField-v8` | output_mismatch 478/571 | output_mismatch **490/571** | +12, same lines |
| trace | everything else in the sweep (§4) | — | unchanged | — |
| pixel | all rows | — | **no change** | 74/74 comparisons md5-identical |

**Not my yield (upstream drift):** `avm1/text_format_prototype_lazy` is 32/35 in the CI baseline but **passes on clean `origin/master` on this box too** (A/B: same result before and after). The upstream `output.txt`/SWF moved after the baseline. Do not book it against this patch.

---

## 1. Premises attacked

1. **"Give plain fields a `TFRunTable` lazily" (w1 §4 step 1): REFUTED as the right vehicle.**
   - A `TFRunTable` is the renderer's text source. Creating one on every plain-field `setTextFormat` or `textColor=` changes the glyph renderer's input on a huge class of fields: the risk w1 itself flagged.
   - The model belongs in a **separate side table** (`TFPlainSpans`) holding only what AVM1 can observe.
   - The HTML `TFRunTable` stays the span model for HTML fields; the side table adds the new text format and the force flags for both kinds.
   - Result: **0 pixel moves**, and the trace gain is intact.
2. **"`_after_edits` lands as ruffle_matched only": REFUTED.**
   - Flash's `output.txt` is fully reachable. Two Flash rules Ruffle lacks (§2: replaceText's new-format rule and replaceSel's sticky re-format) make it a Flash-exact **pass**.
3. **Hidden premise: "replaceText exists".** It did not. AVM1 `TextField.replaceText` had **no implementation**: the name-dispatch arm was missing, so it was a silent no-op. That is why the html section of `_text_same` (`prepared: length=2`) failed.
   - Implementing it moved gnash TextField-v7/v8.
   - At first that cost −2 lines each, because Ruffle's coercions are wrong.
   - The Flash rules were decoded from the gnash SWF's recompiled call sequence (§2). Result: +12 lines each.
4. **Ruffle's `replaceText` is not the oracle for argument edge cases.** Ruffle coerces missing args to `"undefined"` and maps a negative index to 0. Flash-recorded gnash output says both are no-ops. Per the user ruling I followed Flash.

---

## 2. The model (Flash semantics, as implemented)

Per field, the side table holds:
- a span list over `text`, in UTF-16 units;
- the new text format `newfmt`;
- three flags: `force_next`, `edit_sticky` and `newfmt_set`.

The tracked properties are the character-level ones: size, color, font, bold, italic, underline. Paragraph properties keep their existing field-wide bookkeeping.

| Operation | Rule | Evidence |
|---|---|---|
| `text = s` | Same text, no force and no sticky → **no-op** (spans kept; an HTML field's runs kept). Otherwise one span of `newfmt` (an HTML field's runs are rebuilt with `newfmt` defaults). The force flag is consumed. | `_text_same` §1-§10; Ruffle `edit_text.rs:445 set_text` |
| `htmlText = h` (HTML field) | **No-op** if `h` equals the current serialization and no force is pending; otherwise parse with `newfmt` as defaults. The force flag is consumed. | `_text_same` html sections; Ruffle `set_html_text` |
| `setNewTextFormat(f)` | Merge `f` into `newfmt`; set `force_next`. | Ruffle `avm1/globals/text_field.rs:164` |
| `setTextFormat(...)` | Format the range's spans; flags untouched. | `_text_same` "setNewTextFormat, setTextFormat" |
| `textColor = c` | Recolor every span and `newfmt`. | Ruffle `set_text_color` |
| `replaceText(a,b,s)` | Fewer than 3 args, a negative index, or `b < a` → **no-op**. An undefined `s` → `"undefined"`. Indices clamp to the length. **`newfmt` := the format of the char at `a`** (the last char when `a == length`), and `[a,b)` becomes `s` in it. | `_after_edits` lines 4, 24, 84 (Flash: new=30; Ruffle: 12). gnash TextField.as:1138-1169, decoded from `RecompiledScripts/script_2.c` (calls `()`, `(0,0)`, `(-1,0,'c')`, `(-1,5,'e')`, `(3,-1,'y')` are no-ops) |
| `replaceSel(s)` | `s == ""` on a caret is a **pure no-op** (the force and `newfmt` both survive). Otherwise insert `s` in `newfmt`; **`newfmt` := the format of the char after the caret**; set `edit_sticky`, so later same-text assignments re-format until the text actually changes. | `_after_edits` lines 44/51/57 (no-op) and 64-80, 94-98 (sticky; line 98 re-formats a second time) |

The sticky rule is fitted to Flash output. No simpler rule (a cached "last assigned text", for example) reproduces lines 96 and 98 together: I checked that alternative against the data and it fails at line 98.

---

## 3. Patch scope

All edits are in `action.c`.

**New static helpers.** One block, inserted after `tf_condense_white` and marked `s25 w2-edittext-span-model`:
- **Type and table:** `TFPlainSpans`, `g_tf_ps_tables[64]`, with LRU eviction.
- **Lookup and lifetime:** `tf_ps_find`, `tf_ps_get`, `tf_ps_drop`.
- **Format records:** `tf_ps_merge_from_obj`, `tf_ps_from_run`, `tf_ps_to_run`, `tf_ps_fmt_eq`, `tf_ps_base_fmt`.
- **Span list:** `tf_ps_text_len`, `tf_ps_reset_spans`, `tf_ps_ensure_spans`, `tf_ps_normalize`, `tf_ps_split_at`, `tf_ps_fmt_at`, `tf_ps_replace`.
- **Operations:** `tf_ps_set_text_format`, `tf_ps_set_new_text_format`, `tf_ps_set_text_color`, `tf_ps_text_assign`, `tf_ps_html_assign_same`.
- **HTML run-table edits:** `tf_table_plain_to_byte`, `tf_table_run_at_plain`, `tf_table_replace`.
- **Glue:** `tf_ps_is_multiline`, `tf_ps_on_replace`.
- **Read overlays:** `tf_ps_overlay_text_format`, `tf_ps_overlay_new_text_format`.

**Existing functions touched** (small hook lines, for sibling merge):
- `createMovieClip`: one line, `tf_ps_drop(mc)`, so a recycled address never inherits a dead field's spans.
- Forward declaration of `tf_ps_drop` after the `makeStringActionVar` prototype.
- **`actionSetMember`:**
  - `textColor` mask block: calls `tf_ps_set_text_color`.
  - `text` block: calls `tf_ps_text_assign`. The HTML rebuild is skipped on a no-op and uses `newfmt` defaults; the non-HTML invalidate branch became `else if (!_ts_is_html)`.
  - `htmlText` html branch: the `tf_ps_html_assign_same` early-out (`goto _ps_html_same`), `newfmt` defaults, and `has_spans = 0`.
  - `htmlText` no-stylesheet plain branch: calls `tf_ps_text_assign`.
- **`actionCallMethod`:**
  - `setTextFormat`: new `else` arm for fields without runs.
  - `setNewTextFormat`: one call.
  - `getTextFormat`: the overlay call, and the textColor override is skipped when the model answered.
  - `getNewTextFormat`: one overlay call.
  - **New `replaceText` arm**, placed before `replaceSel`.
  - `replaceSel`: the empty-caret no-op, the model call, and invalidation only when no HTML run table was edited in place.

**Renderer:** no change.
- `_tf_fontHeight` and the other field-wide `_tf_*` writes are untouched.
- An HTML run table is now edited in place by `replaceSel`/`replaceText` instead of being dropped. That is the only path where the renderer's input can differ. No canary row exercises it (74/74 identical).

**Siblings:**
- I do not touch the TextField prototype install, Selection focus, the `createTextField` arm, the kerning or advance loop, or button/mouse dispatch.
- The rebase onto `ab22f11e`, which includes `w2-acid-text-kerning` and `n-play-game`, merged with no conflicts.

---

## 4. Measurements

**Headline before/after.** Same box. Before = clean rebased `origin/master` (`git apply -R`); after = this patch.

| Test | Before | After (graphics) | After (no-graphics) |
|---|---|---|---|
| avm1 `edittext_set_text_same` | output_mismatch 28/70 | **pass 70/70** | pass 70/70 |
| avm1 `edittext_set_text_same_after_edits` (KF) | output_mismatch 30/98 | **pass 98/98** | pass 98/98 |
| gnash `TextField-v6` | 467/545 | 467/545 | 467/545 |
| gnash `TextField-v7` | 476/570 | **488/570** | 488/570 |
| gnash `TextField-v8` | 478/571 | **490/571** | 490/571 |

For TextField-v8, the before-vs-after mismatched-line sets give: **fixed 521-532, new: none**. The `#passed`/`#failed` summary lines were already mismatched.

**Trace sweep** (graphics, compared with the CI baseline `results_graphics.json` per suite; every moved row was then A/B'd on clean):

| Set | Rows | Moves |
|---|---|---|
| **avm1:** every TextField/EditText/TextFormat/font/html/selection-named row, plus every `.as` using setTextFormat/getTextFormat/replaceText/replaceSel/NewTextFormat/textColor | 112 | the 2 headline rows, plus `text_format_prototype_lazy` (drift: it also passes clean) |
| **gnash actionscript.all:** Selection, TextField, TextFieldHTML, TextFormat and TextSnapshot, v5-v8 | 20 | TextField-v7/v8 (+12 lines each) |
| **gnash misc:** DefineEditText*, DefineTextTest, EmbeddedFontTest, TextSnapshotTest, mtasc TextFieldTest, swfc edittext_test1 | 9 | 0 |
| **shumway:** acid-text*, acid-textfield*, text-bind, textfield-html, textfield-text-setters, flash_text_TextField{,2} | 15 | 0 |
| **regression:** `avm1_parent_child_text`, graphics and no-graphics | 1 | 0 (pass) |
| **`text` suite (10) and `fonts` suite (7)** | 17 | 0. `auto_size` and `embed_matching` are absent from the CI json and fail on clean too (compile/recomp fail). Not mine |

- The 112 avm1 rows were re-run on the final code.
- The other sets ran before the final `replaceText` argument-rule edit. That edit only changes `replaceText` calls with fewer than 3 args or a negative index; TextField-v6/v7/v8 were re-run after it.

**Render canary:** `render_canary.py run --stash action.c`, 44 tests / 74 PNG comparisons.
- The set is every image-graded non-ABC test with a DefineEditText or a TextField/TextFormat string. It is the s24 45-test text-sweep set reconstructed: `acid-textfield` has no image comparison in today's corpus.
- Result: **74 IDENTICAL, 0 DIFFERS**, and no trace or image status changes.

**Process incident (disclosed):** one early sweep invocation got a missing list file and ran `verify_output.py` without `--test` on `from_gnash/actionscript.all`. I killed it within minutes. It touched only `_results/results_previous.json`, which I restored with `git checkout`. The sweep script now refuses an empty list.

---

## 5. Not done, and follow-ups

- **The renderer does not consume the span model.** A plain field with mixed per-character sizes or colours still renders field-wide (last `setTextFormat` wins), as before. That is phase 2: build a `TFRunTable` from `TFPlainSpans` at render time, behind an image run.
  - Mechanism: `tf_ps_*` → a synthesized table in the glyph path at the `action.c` "Prefer TFRunTable.text + run formatting" site.
  - Price: M, and it needs `images=true`.
- **Paragraph properties are not per-span** (align, margins, leading, indent, blockIndent). They keep their field-wide `_tf_*` bookkeeping. No headline row needs them.
- **Doc entry for the coordinator.** Add to `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`: `edittext_set_text_same_after_edits` (KF), where we match Flash and Ruffle does not.
  - Ruffle's `replaceText`/`replaceSel` new-text-format inheritance is missing, as is the empty-`replaceSel` no-op.
  - The same file should cover the gnash TextField.as:1138-1169 `replaceText` argument rules.
  - I left `_investigation` docs out of the patch so it stays source-only.

## 6. New unclaimed leads

- **Keyboard and IME edit paths** (`tf_invalidate_run_table(g_focused_mc)` callers, around `action.c:82168+`) still drop an HTML field's run table on every keystroke. Typed text loses `<font>` formatting.
  - `tf_table_replace` is now the in-place primitive, so routing those paths through `tf_ps_on_replace` is S.
  - Typed text would then take `newfmt`, which is Flash's `getNewTextFormat` contract for typed input.
- **`setNewTextFormat` writes the field `textColor`** (pre-existing, in the `setNewTextFormat` arm). Flash does not: `_text_same` shows textColor and new-format colour moving independently. Nothing in the sweep depends on it.

## LOCAL ORACLE REQUESTS

None. Every rule above is pinned by Flash-recorded `output.txt` (the avm1 rows and gnash `TextField-v*`).
