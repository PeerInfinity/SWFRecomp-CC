# w2-tf-css-avm2: AVM2 twins of the s23 AVM1 TextField-format rows (session 23, wave 2)

**New files on this branch:**
- `SWFRecompDocs/plans/session23-fanout-reports/w2-tf-css-avm2-report.md` (this report)
- `SWFRecompDocs/plans/session23-fanout-reports/w2-tf-css-avm2.patch` = `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`. `git apply --check -R` passes against the branch tip.

There are no new source files and no new fixture dirs. The patch touches:
- `SWFModernRuntime/src/avm2/avm2_text.c`: +60/−14, all of it in the TextField natives.
- `ruffle-tests/render_canary_tests.txt`: +7 lines at EOF.

**Environment:**
- Cloud box. `SETUP_STATUS` is all OK (apt, Pillow, Dawn/lavapipe).
- Base `origin/master` is `a753f74bc`. It carries `ca9c46595`, `228a5ff0c` and the other s23 landings named in the brief.
- Upstream tests come from Ruffle master **`aa9f62a70`** at download time. It is `0ddd12b6a` plus the VP6 visual test, so it has no text drift relative to CI's baseline.
- Categories downloaded: `avm2 avm1 text visual from_shumway fonts mixed_avm swf timeline`, plus `regression` from git.
- Every before-leg ran on clean `origin/master` (the patch reverted with `git apply -R`). Every after-leg ran on the same box with the patch applied.
- Every run was a single test, at most 2 in parallel.

---

## 0. Verdicts and priced flips

| Row | Before (clean master, graphics = no-graphics) | After (graphics = no-graphics) | Verdict |
|---|---|---|---|
| `avm2/textfield_get_text_format_args` | output_mismatch 50/567 | **pass 567/567** | **GO, +1** (M1) |
| `avm2/textfield_set_text_format_args` | output_mismatch 81/904 | **pass 904/904** | **GO, +1** (M1 + M2) |
| `avm2/edittext_set_text_same` | output_mismatch 92/115 | **pass 115/115** | **GO, +1** (M3 + M4) |
| `avm2/edittext_set_text_same_after_edits` (KF) | output_mismatch 84/138 | **ruffle_matched** (90/138 vs Flash) | **GO for effective +1**; Flash-exact is a HOLD (§3) |
| `avm1/edittext_set_text_same` | output_mismatch 28/70 | 28/70 (untouched) | HOLD, not shared (§4) |
| `avm1/edittext_set_text_same_after_edits` (KF) | output_mismatch 30/98 | 30/98 (untouched) | HOLD, not shared (§4) |

**Total: +4 effective trace rows (3 `pass` + 1 `ruffle_matched`), identical in both modes. No pixel moves.**

On `edittext_set_text_same_after_edits`:
- **Flash and Ruffle disagree on this row**, so this `ruffle_matched` is not a Flash-exact landing.
- It is still a strict improvement (fail → effective), not the forbidden pass → ruffle_matched.
- The only remaining Flash-vs-Ruffle gap is the edit-op format model, which Ruffle also lacks (§3).

**Brief premises attacked:**
- **"Begin/end index validation: #2006 and clamping."** Half true. AVM2 does **no clamping at all**; that is the AVM1 model (w2-tf-css M2). Ruffle's AVM2 `text_field.rs` validates strictly:
  - Any out-of-range begin or end is #2006.
  - `(b)` means `[b, b+1)`.
  - `(-1, -1)` means the whole text.
  - Our bug was the reverse: we threw on the wrong cases and treated `(b)` as `b..end`.
- **"Assigning the same text re-applies `defaultTextFormat`."** Not quite. Assigning the same text is still a no-op (Flash and Ruffle `set_text`). What re-applies is **the first text/htmlText assignment after a `defaultTextFormat =` write**, through a one-shot force flag.
  - On `edittext_set_text_same`, the force flag accounts for 16 of the 23 failing lines: 10 `sizes=` lines through `set_text`, plus 6 `htmlText … length=` lines through `set_html_text`. Every one of them follows a `defaultTextFormat =` write.
  - The other 7 are the `colors=` lines, which are an unrelated mechanism: textColor alpha (M4).
  - This split is classified from the before-diff by line content. It was not measured with each hunk applied separately.

---

## 1. Mechanisms (owner `SWFModernRuntime/src/avm2/avm2_text.c`, patched line numbers)

### M1: `txt_resolve_format_range` (new static, ≈5035)

This is a port of Ruffle `avm2/globals/flash/text/text_field.rs` `get_text_format` / `set_text_format`. It is shared by both natives. The rules:
- `(-1, -1)` (also the AS3 defaults) → `[0, len)`, even when the text is empty.
- Otherwise `begin == -1` → 0. Then `begin ∉ [0, len)` → **RangeError #2006**.
- `end == -1` → `begin + 1`. Then `end ∉ (0, len]` → **#2006**.
- An empty or inverted range (`begin >= end`) has these effects:
  - `getTextFormat` returns `TextFormat::default()`: every field null, display block (`format_default()`).
  - `setTextFormat` is a no-op (`FormatSpans::set_text_format`: `from >= to` returns).
- Index coercion stays `avm2_coerce_to_i32` on the declared `int` params, so `4294967295` → −1, `NaN` / `undefined` → 0, and so on. This matches the 21 coercion cases (11 single-arg, 10 two-arg) in each of the two rows.

**What it replaces:**
- getTextFormat threw only when `end >= 0 && (begin >= end || begin < 0)`, so it threw on `(2, 1)` where FP returns nulls.
- It never threw on `(-2)` or `(5)`.
- It mapped `(b)` to `b..len`.
- setTextFormat clamped `begin < 0` to 0 (FP: #2006 for −2) and accepted `begin == len`.

### M2: `setTextFormat(null, …)` → TypeError #2007 (`txt_set_text_format`, ≈5085)

Ruffle uses `args.get_object(activation, 0, "format")?`, and FP throws #2007 before any index check. We silently returned. This fixes 4 cases in `textfield_set_text_format_args` (lines 687–720).

### M3: FORCE_NEXT_TEXT_UPDATE (trailing field `Avm2EditTextExt.force_next_text_update`, ≈822)

This is a port of Ruffle `EditTextFlag::FORCE_NEXT_TEXT_UPDATE` (`edit_text.rs` `force_next_text_update` / `take_force_next_text_update`).
- `txt_set_default_text_format` sets the flag after `spans_set_default_format`.
- `txt_set_text` and `txt_set_html_text` take the flag (read it, then clear it) on every call. When it is set, they skip the same-text no-op, so `FormatSpans::from_text` / `from_html` re-formats the text with the current default format.
- The field is zeroed by the existing `memset` at ext allocation. It is a trailing struct member (self-localized).

### M4: `textColor` stores no alpha (`txt_set_text_color`, ≈4715)

This is Ruffle `37173f2b8` ("Don't set alpha in the text format of TextField.textColor"): `from_rgb(rgb, 0)`, not `0xFF`.
- **Before:** `TextFormat.color` read back `-65536` after `textColor = 0xFF0000` (the alpha leaked into `to_rgba() as i32`), and those colours also failed to merge with `<font color>` spans, which carry alpha 0.
- **Rendering is unaffected:** every AVM2 glyph-colour reader (`avm2_text.c` ≈4226/4287/4352) masks `(color >> 8) & 0xFFFFFF`, and the canary confirms it (§2.2).

The `w2-stage3d-text` sibling edits glyph ADVANCE rounding in the layout code. None of my hunks touch layout, advance or `et_relayout`. They are confined to the TextField natives (≈4470–5100) and one trailing struct field.

---

## 2. Verification

### 2.1 Neighbour sweep: 72 rows, graphics mode, both legs

**How the rows were chosen:**
- Every AS3 test (`package` in its `.as`) across `avm2 text visual from_shumway fonts mixed_avm swf timeline regression` whose source calls `getTextFormat`, `setTextFormat`, `defaultTextFormat` or `textColor`. That is the whole API surface this patch changes, so every caller of M1–M4 is in the list.
- The 5 regression-suite text rows.
- The 4 headline rows.

**Result:**
- **68 rows keep their exact status and matching/expected line counts. Only the 4 headline rows move.**
- 61 rows pass in both legs.
- The 7 KF `ruffle_matched` rows are unchanged:

| Row | Status and lines (both legs) |
|---|---|
| `edittext_device_transform_layout` | 268/288 |
| `edittext_getcharboundaries_culling` | 5/305 |
| `html_text_img_parsing` | 505/600 |
| `fonts/device_font_no_ink` | 4/18 |
| `from_shumway/flash_text_TextField` | 0/0 |
| `visual/edittext/edittext_device_transform_metrics` | 32/40 |
| `visual/edittext/edittext_device_transform_negative` | 79/120 |

**Regression suite (`--tests-dir=ruffle-tests/tests/swfs/regression`):** all 5 text rows pass in both legs:
- `avm1_parent_child_text` 8/8
- `avm2_bitmapdata_draw_textfield` 5/5
- `avm2_parent_child_static_text` 12/12
- `avm2_static_text` 6/6
- `avm2_timeline_text` 4/4

No new fixture was needed: the 4 corpus rows cover every new behaviour, with Flash-generated `output.txt`.

### 2.2 Render canary (`render_canary.py`, md5 A/B)

| Capture pair | Scope | Result |
|---|---|---|
| `beforefull` → `afterfull` | full standing `render_canary_tests.txt` (95 tests / 150 comparisons) | **150 IDENTICAL**, 0 DIFFERS, 0 APPEARED/VANISHED, no trace/image status change |
| `before` → `after` | the 24 image-bearing rows of the §2.1 sweep plus the standing AVM2-text members (`text/auto_size/width`, `edittext_device_transform_small_rotation/_shear`, `fonts/embed_matching/fallback_preferences`): 28 tests / 43 comparisons | **43 IDENTICAL**, no status change |

**Appended at EOF (covering members, tier 1, both CI-passing in run 44922638965):**
- `visual/edittext/edittext_selection_font_size`: AVM2 `textColor` + `defaultTextFormat` (M3, M4).
- `visual/layout/line_vertical_align`: AVM2 ranged `setTextFormat(tf, b, e)` (M1).

The standing set had no AVM2 member that calls either API. Both are md5-identical across my legs.

**Fidelity:** there is no absolute pixel verdict claimed, so A/B md5 is the bar used.

### 2.3 Headline rows, per mode (final tree)

| Row | graphics before → after | no-graphics before → after |
|---|---|---|
| `textfield_get_text_format_args` | 50/567 → pass 567/567 | 50/567 → pass 567/567 |
| `textfield_set_text_format_args` | 81/904 → pass 904/904 | 81/904 → pass 904/904 |
| `edittext_set_text_same` | 92/115 → pass 115/115 | 92/115 → pass 115/115 |
| `edittext_set_text_same_after_edits` | 84/138 → ruffle_matched (90/138) | 84/138 → ruffle_matched (90/138) |

The no-graphics before counts were derived from the `--diff` logs: expected minus `-` lines, e.g. 115−23 = 92.

---

## 3. HOLD: Flash-exact `edittext_set_text_same_after_edits` (KF)

After the patch, the row matches `output.ruffle.txt` exactly. The 48 lines where Flash differs from Ruffle (and us) are two edit-op behaviours that neither Ruffle nor we model:

1. **Edits re-seed the default format.**
   - `appendText(s)` and `replaceText(b, e, s)` (even with `s == ""`) set `defaultTextFormat` to the format at the edit point (30 after `setTextFormat(big)`). Flash lines 4, 11, 17, 24, 44, 64, … show `default=30`; Ruffle and we keep 12/20.
   - Appended text takes the preceding char's format (`appendText("C")` → `30,30,30`). Ruffle (`FormatSpans::replace_text`) and we use the default format there.
   - These edits do NOT consume or set the force flag (Flash lines 6 vs 13).
2. **`replaceSelectedText` on an off-stage, unfocused field.**
   - `setSelection(0, 1); replaceSelectedText("X")` gives `XAB`: an insertion at 0, nothing deleted. Ruffle gives `XB`.
   - After it, **every** later same-text `text =` write re-formats the text, twice in a row (lines 134–138). So a single-shot flag does not describe it.
   - `setSelection(0, 0); replaceSelectedText("")` is a complete no-op in Flash (default stays 12).

**Why I did not land it:**
- Rule 2 (the selection semantics and the persistent re-format) has no derivation I can check without an oracle.
- A partial port of rule 1 alone would turn the row from `ruffle_matched` back into `fail`, which would be a net loss.

**Completion mechanism:**
- First, a Flash/Ruffle-independent probe of rule 2: LOCAL ORACLE REQUEST 1.
- Then port rule 1 into `spans_replace_text` callers (`txt_append_text`, `txt_replace_text`, `txt_replace_selected_text`), and rule 2 into `txt_replace_selected_text`.
- **Size:** M. **Gain:** a Flash-exact `pass` on one row that is already effective, so it adds +0 effective rows.

## 4. AVM1 HOLDs `avm1/edittext_set_text_same(_after_edits)`: priced, not shared

- **Different code.** AVM1 TextField formats live in `action.c` (field-level `_tf_*` props plus the HTML-only `TFRunTable`). `avm2_text.c` already has Ruffle's `FormatSpans` model, which is why the AVM2 twin needed only the force flag.
- **So my fix cannot flip the AVM1 rows.** Measured: 28/70 and 30/98 in both modes, unchanged (the patch has no AVM1 hunk).
- **What the AVM1 port needs:**
  - The w2-tf-css §3 plain-field span model (L).
  - Plus the same force flag: Ruffle sets it from AVM1 `setNewTextFormat` too (`avm1/globals/text_field.rs:164`).
  - Once the span model exists, the flag is about 10 lines on top. It could reuse no code from this patch beyond the idea.
- **Price is unchanged from w2-tf-css:** L for +1 (`edittext_set_text_same`), plus the §3 edit-op model for the KF after_edits row.

---

## 5. EXPECTED-FLIP LEDGER (for CI grading)

**Trace axis, both modes (`graphics` and `no-graphics`):**

| Test | Before | After |
|---|---|---|
| `avm2/textfield_get_text_format_args` | output_mismatch 50/567 | **pass 567/567** |
| `avm2/textfield_set_text_format_args` | output_mismatch 81/904 | **pass 904/904** |
| `avm2/edittext_set_text_same` | output_mismatch 92/115 | **pass 115/115** |
| `avm2/edittext_set_text_same_after_edits` (KF) | output_mismatch 84/138 | **ruffle_matched** (KF; Flash and Ruffle disagree; Flash-exact is §3) |

None of the three `pass` rows has an `output.ruffle.txt` or `known_failure`, so `pass` is the only possible landing.

**Pixel axis:** no expected moves.
- None of the 4 flip rows has `[image_comparisons]`.
- All 24 image-bearing sweep rows and the full standing canary are md5-identical.
- Any CI pixel move is outside the measured footprint; report it to me as a regression.

**Expected unchanged (watch list):** the 68 sweep rows in §2.1, notably:
- `visual/layout/line_vertical_align`, the only image row calling ranged `setTextFormat`.
- `visual/edittext/edittext_selection_font_size` / `_leading`, the `textColor` image rows.
- `avm2/edittext_set_html_same`, `edittext_set_text_vs_html`, `edittext_default_format_empty`, `edittext_empty_text_format`, `textfield_default_text_format_null`.
- The 7 KF `ruffle_matched` rows listed in §2.1.

**Recommended CI:** `graphics` with `categories=all` covers all 4 flips (avm2 is in the classic five).
- The code lives in `avm2_text.c`, which is mode-agnostic and is not `swf_core.c` or `tag_stubs.c`, so a no-graphics leg is optional. Mode parity is measured identical on the headline rows.
- There is no recompiler change, so `--recompile` is not needed.
- `full` adds only the misc `text`/`visual`/`fonts` groups. 21 of my sweep rows live there, all unchanged locally. Run `full` if you want those graded.

## 6. Patch scope and sibling notes

All hunks are in `avm2_text.c`:

| Hunk | Line (patched tree) |
|---|---|
| struct trailing field | ≈822 |
| `txt_set_text` | ≈4477 |
| `txt_set_html_text` | ≈4527 |
| `txt_set_text_color` | ≈4715 |
| `txt_set_default_text_format` | ≈5027 |
| new `txt_resolve_format_range` | ≈5035 |
| `txt_get_text_format` | ≈5069 |
| `txt_set_text_format` | ≈5085 |

- **`w2-stage3d-text`** edits glyph advance rounding in this same file but in the layout code (≈1100–4400, `LLayout` builders). There is no textual or semantic overlap. Expect at most a fuzz-offset rebase.
- `w2-avm2-small-errors`, `w2-array-vector-args` and `w2-stack-trace-names` don't touch this file.
- **`render_canary_tests.txt`** gets an EOF append. If other s23 slots also append at EOF, expect a trivial merge conflict that resolves by keeping both blocks.

## 7. Not finished, with completion mechanisms

1. **Flash-exact `edittext_set_text_same_after_edits`** (§3). The completion mechanism is ORACLE REQUEST 1 and then the edit-op format port. M size, +0 effective.
2. **AVM1 `edittext_set_text_same(_after_edits)`** (§4). The completion mechanism is the w2-tf-css §3 plain-field span model plus a `setNewTextFormat` force flag. L size, +1.

## New unclaimed leads

1. **Other Ruffle `37173f2b8`-era AVM2 text drift.** Ruffle landed several small TextField fixes in Oct 2026 alongside these tests (`e88e09518` added them). A `git -C ruffle log 45366370e..aa9f62a70 -- core/src/avm2/globals/flash/text core/src/display_object/edit_text.rs core/src/html` read could find further one-liners like M4. I did not do the census, because none of my sweep rows still fails on them.
2. **`setTextFormat` on a non-TextFormat object** (e.g. a plain Object) silently returns, as before. Ruffle would `unwrap()`-panic on it (the param is typed `TextFormat`, so the AS3 coercion throws #1034 first). No corpus row exercises it.

## LOCAL ORACLE REQUESTS

1. **Optional, for §3.** Run the existing `avm2/edittext_set_text_same_after_edits/test.swf` variant below in Flash Player (not Ruffle, which is already known):
   - On a fresh `TextField` with `text = "AB"`, run `setSelection(0, 1); trace(selectionBeginIndex, selectionEndIndex); replaceSelectedText("X"); trace(text)`.
   - Repeat it with the field added to the stage and focused (`stage.focus = field`) first.

   This settles whether Flash collapses an unfocused field's selection to the caret (which would explain `XAB`). Without Flash, there is no request: Ruffle's answer is already the sidecar.
