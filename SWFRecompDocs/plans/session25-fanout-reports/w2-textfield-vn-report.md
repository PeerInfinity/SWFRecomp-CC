# w2-textfield-vn: gnash TextField-v6/v7/v8 → ruffle_matched (session 25, wave 2)

**New files on this branch:**
- `SWFRecompDocs/plans/session25-fanout-reports/w2-textfield-vn-report.md` (this report)
- `SWFRecompDocs/plans/session25-fanout-reports/w2-textfield-vn.patch` = `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`. `git apply --check -R` passes on the branch tip, and `git apply --check` passes on clean `origin/master` `6063933a` (only docs and results moved past `2afd3e36`).
- No new source files and no new fixture dirs. Every behaviour is graded by the gnash corpus rows, whose expected output is Flash's.

**Patch scope:**
- `SWFModernRuntime/src/actionmodern/action.c` (+330/−23)
- `SWFModernRuntime/src/libswf/ng_shared.c` (+39/−0)
- `ruffle-tests/render_canary_tests.txt` (+5: one appended member)

**Base and environment:**
- **Rebased three times. The final measured base is `origin/master` `2afd3e36`; the branch tip sits on `6063933a`, which adds docs and results only.**
  - First onto `ab22f11e` (`w2-acid-text-kerning`, `w2-avm1-filters`, `w2-dynclip-cxform`, `w2-netstream-flv-screen`, `w2-avm2-cm-copyfrom`).
  - Then onto `2afd3e36` (adds `w2-edittext-span-model` and `w2-avm1-with-scope`).
  - Neither rebase had a source conflict. Only the canary-list EOF conflicted, and both appends are kept.
- **Headline rows were re-measured on every base:**
  - My patch removes the same 39/42/42 ours-only lines on each.
  - On `2afd3e36`, the landed span model already removes 12 *shared* replaceText lines from v7/v8, so the BEFORE/AFTER numbers below are on `2afd3e36`.
  - On the original base the AFTER was 13/25/24 diffs; the delta is entirely the sibling's shared lines.
- Cloud box. `SETUP_STATUS` is all OK (Dawn/lavapipe).
- Categories: `avm1 from_gnash from_shumway text fonts swf timeline mixed_avm visual import_assets`, plus `regression` from git. Ruffle clone `3ac8dcb07`.

---

## 0. Verdicts and the EXPECTED-FLIP LEDGER

**GO. All three rows reach `ruffle_matched`.** They are all `known_failure`, so there is no `pass → ruffle_matched` risk. Every ours-only diff line is gone: our diff-line set ⊆ Ruffle's (`verify_output.py` `ruffle_subset_match`).

### Per-test before/after, same box, graphics mode, base `2afd3e36` (graded file `output.fp13-17.txt`)

| Row | BEFORE: clean `2afd3e36` | AFTER: this patch | Verdict |
|---|---|---|---|
| gnash `actionscript.all/TextField-v6` (KF) | output_mismatch, 467/545 matching. 78 diffs, **39 ours-only** | **ruffle_matched**, 532/545. 13 diffs ⊆ Ruffle's 57. 0 ours-only | **+1 effective** |
| gnash `actionscript.all/TextField-v7` (KF) | output_mismatch, 488/570. 82 diffs, **42 ours-only** | **ruffle_matched**, 557/570. 13 ⊆ 73. 0 ours-only | **+1 effective** |
| gnash `actionscript.all/TextField-v8` (KF) | output_mismatch, 490/571. 81 diffs, **42 ours-only** | **ruffle_matched**, 559/571. 12 ⊆ 72. 0 ours-only | **+1 effective** |

- These are on `2afd3e36`. The CI baseline `45043930556` (pre-span-model) read 467/476/478. Clean `ab22f11e` reproduced that exactly, with AFTER 532/545/547.

- **Mode parity:** no-graphics output is byte-identical to graphics output on all three AFTER rows (both ruffle_matched). Measured on the original base; neither later base changed this patch's AFTER output.

### EXPECTED-FLIP LEDGER (for CI)

**Trace axis:**

| Test | Expected move |
|---|---|
| `from_gnash/actionscript.all/TextField-v6` | output_mismatch → **ruffle_matched** |
| `from_gnash/actionscript.all/TextField-v7` | output_mismatch → **ruffle_matched** |
| `from_gnash/actionscript.all/TextField-v8` | output_mismatch → **ruffle_matched** |
| `avm1/globals_monkeypatch` (KF) | stays output_mismatch; matching lines **44 → 49** (P13, Flash-correct lines: `new MyTextField() called!`, `v.className: MyTextField`, `textfieldCustom.className: MyTextField`). Not a status move |
| everything else | **0 moves** |

- Upstream-drift note (not yield): `avm1/text_format_prototype_lazy` reads output_mismatch 32 in the baseline JSON, but it **passes on clean master too** (measured). Don't book it to this patch.

**Pixel axis:** **0 moves.**
- Render canary on the final base `2afd3e36`: 99/99 PNGs md5-identical (49 AVM1 canary members plus 6 further `createTextField` image tests).
- Pre-rebase: 82/82 and 18/18.

**CI mode:** `graphics`, `categories=all`. The patch touches `NO_GRAPHICS || OFFSCREEN_RENDER` arms and `ng_shared.c`. I measured a no-graphics leg on the headline rows (identical), so the FINAL grading run's no-graphics leg covers the rest.

---

## 1. What landed (phase by phase, stepwise-measured)

Diff lines are listed as v6/v7/v8, with ours-only (OO) in brackets. No step added a diff line anywhere. Each step's diff drop equals its OO drop, and the OO lists show exactly the targeted lines going away.

| Step | Phases | Diffs (OO) |
|---|---|---|
| baseline | | 78/94/93 (39/42/42) |
| w1 prototype, applied unchanged | P0, P1b, P2, P14, P15 | 32/46/44 (19/21/20), reproduces the w1 measurement exactly |
| + S batch | P8, P18, P19 | 28/42/41 (15/17/17) |
| + binding batch | P16, P20, P21 | 22/34/33 (9/9/9) |
| + P13 | `_global.TextField` construct, with a real `arguments` | 17/29/28 (4/4/4) |
| + P17 | device-font metrics | **13/25/24 (0/0/0)** |
| + P13 refinement | proto = the replaced ctor's `prototype`; MC `this` ABI | 13/25/24 (unchanged); `globals_monkeypatch` +5 lines |

### Mechanisms (all in `action.c` unless noted; function names given for sibling coordination)

- **P0, P1b, P2, P14, P15:** the w1 prototype, unchanged (`w1-textfield-vn-report.md` §3).
  - Functions: `initTextFieldPrototype`, new `textFieldDefineProtoProps`, new `tfIsSwf5Sourced`, `installTextFieldBroadcaster`, `findOrCreateMovieClip` (2 sites), `actionTypeof`, `actionNewObject`, the `actionCallFunction` createTextField arm, new `tfSetFocusSelectAll` and `builtin_selection_setFocus`.
  - In `ng_shared.c`: new `ng_getTextFieldSrcSwfVersion`, plus `ng_record_textfield_props`.
- **P8, `length` read-only.** The `actionSetMember` MOVIECLIP arm drops `tf.length = …` on a TextField. This matches Ruffle's getter-only `length`.
- **P18, `with(tf){ _name = … }`.** In `setMCBuiltinProperty` (the with-scope / SetVariable display-property setter), `_name` on a **TextField clip** now goes through `actionSetMember`. So the rename, the `_target` cascade and the parent-binding move live in one place. Plain sprites are untouched.
- **P19.** The `actionCallMethod` createTextField arm returns undefined below SWF8 (Ruffle `movie_clip.rs` create_text_field). The free-function arm already did this. I corrected its stale comment, which claimed the method form returned the field in all versions.
- **P20.** In the `actionGetMember` MOVIECLIP arm, the path properties `_root`, `_parent` and `_global` compare case-sensitively in SWF7+ (Ruffle `stage_object.rs` `eq_with_case(.., is_case_sensitive())`).
  - This applies to all clips, as in Ruffle.
  - I scanned every downloaded AVM1 SWF7+ for case-variant spellings. The only hits are `case-v7`, `case-v8` and `TextField-v7/v8`, all in the sweep.
- **P16, runtime `tf.variable = X` on a createTextField field.** New `tfDynamicRebindVariable`, called from the `actionSetMember` generic store when `ng_textfield_idx == -2`. Flash's semantics, from gnash TextField.as:748-772:
  - The text is not reset, and a missing variable is not created.
  - An existing variable's value is copied into the text.
  - The binding is registered on a display-object container through the existing Phase-C registry (`actionRegisterTextFieldBinding`). So writes like `_level0.inputVar = …` update the text, and writes to a plain-Object container do not.
  - `ng_syncTextToVar` now also accepts -2 fields, so `tf.text = …` writes through the path.
  - Ruffle differs from Flash here only by resetting the text to the empty initial text first. That is why Ruffle fails :751/:759/:761 and we now pass them.
- **P21.** `actionNotifyPropertyChange` delivers `undefined` in SWF7+, so the bound text becomes `"undefined"` (Ruffle `notify_property_change` coerces with `coerce_to_string`). SWF≤6 keeps the old skip; ToString gives `""` there anyway.
- **P13.** New `tfCallGlobalCtorOnField`, called at the end of both createTextField arms (SWF6+). When `_global.TextField` is a script function (not the native ctor), it runs as Ruffle's `construct_as_avm1_object` does:
  - The field's `__proto__` is set to that function's raw `prototype_obj`. It is read raw, with no getter, because the Flash output shows no getter trace.
  - The function is then invoked with `this` = the field clip and a real zero-length `arguments` (`INV_ACT_ARGUMENTS`), so SWF6 type-1 bodies see it.
  - The MOVIECLIP receiver goes through `INV_EVENT_THIS_MC | INV_MC_THIS_NULL_PTR`, the same pairing as every other MC-`this` dispatcher. Without it, a type-2 body's preload-this read `this.className` as undefined (`globals_monkeypatch`).
- **P17, createTextField device-font metrics.** The work is in `computeTextFieldDimension`, plus one wrap rule in `ng_shared.c`.
  - A -2 field with no `_tf_fontHeight` measures at **12 px**.
  - Its face is "Times New Roman" → `ng_resolveDeviceFontId`, falling back to the test's default `_serif` face. That is the test.toml `[default_fonts] serif = ["Noto Sans"]` subset: ascent 784 + descent 247 over a 1024 em, which is 12 px.
  - When such a device face resolves:
    - the default leading is 0 (Ruffle `EditText::new` TextFormat), giving textHeight 12;
    - textWidth is scaled by the concatenated d/a (Ruffle `layout_to_local_matrix` `device_font_scale_x`), so `_xscale = 200` halves it.
  - Without a declared device face, the old 40-twip leading and the font-0 path stay as they were.
  - `ng_shared.c` `ng_wrap_count_lines` gets the **SWF≤7 give-up rule**. When at most one character of a too-wide first word fits, the rest of the line is laid out unbroken (Ruffle `html/line_wrapping.rs` `if line_end <= 1 { return None }` for !swf8). That explains TextField.as:972-976: `_width = 10` keeps textWidth 63 in v6/v7, and v8 breaks it.
  - It touches only the measurement wrapper behind textWidth/textHeight/line count. It does **not** touch the EditText glyph advance loop in `tag.c` (sibling `w2-acid-text-kerning`'s area), nor the second wrap loop in `ng_computeScrollMixedFont`.

### Coordination: every Selection/focus and button/mouse function touched
- **Selection/focus:** `builtin_selection_setFocus` (both `g_tf_select_all` sites) and the new `tfSetFocusSelectAll`. That is all.
- Nothing in `tag.c`, and no button or mouse dispatch function.
- The `n-play-game` session closed out (`9b196b28`); this note is for the record.

---

## 2. Sweep and canary evidence

### Rider sweep: 299 rows, graphics, compared with the CI baseline `results_graphics.json` per suite

**Row set:**
- The w1 195-row recipe: every avm1 TextField/EditText/focus/selection/tab_order/broadcaster/lazy_prototype/variable/bind row, gnash `TextField*`, `TextFieldHTML*`, `MovieClip-v6/7/8`, `toString_valueOf*`, `Selection*`, `DefineEditText*`, `edittext*`, `case-v*` and `with-v*`, shumway text/bind/edit rows, every `text/` and `fonts/` row, and `regression/*text*|tf|edit*`.
- Every SWF in all downloaded AVM1-capable suites whose decompressed bytecode contains:
  - `createTextField` (124 rows),
  - `textWidth`/`textHeight` (39),
  - a runtime `variable` write (21),
  - SWF<8 `wordWrap` (5),
  - SWF7+ case-variant `_root`/`_parent`/`_global` (4).

**Result, the final patch pre-rebase:** 299/299 run.
- `TextField-v6/v7/v8` → ruffle_matched.
- `avm1/globals_monkeypatch` 44 → 49, still output_mismatch.
- `avm1/text_format_prototype_lazy`: upstream drift (passes on clean master).
- `misc-swfc.all/gotoFrameFromInterval`: no baseline entry; runtime_error on clean master too (w1 measured).
- **Zero other status or matching-line moves.**

**Rebased re-sweep (`ab22f11e` + patch):** all 299 rows were re-run.
- **299/299 are identical to the pre-rebase sweep** (status and matching lines).
- So the landed siblings neither interact with this patch nor move any of these rows against the CI baseline.
- `visual/fonts/leading_define_font` is OOM-killed when it shares the box with a second job. Run alone, it is unchanged pass (both sweeps).

**Second rebased re-sweep (`2afd3e36` + patch, the final base):** all 299 rows were re-run. Exactly 4 rows differ from the `ab22f11e` sweep, and all 4 are the landed `w2-edittext-span-model`'s yield, not this patch's:
- `avm1/edittext_set_text_same` and `avm1/edittext_set_text_same_after_edits` go mismatch → pass. Both **pass on clean `2afd3e36` too** (measured).
- `TextField-v7/v8` stay ruffle_matched with +12 matching lines each. Those are shared replaceText lines; BEFORE on clean `2afd3e36` has the same +12.
- Every other row is identical to the earlier sweeps. So against the CI baseline, this patch's own moves are still exactly the ledger in §0.

**Regression suite:** all 9 regression rows in the set are unchanged pass:
- `avm1_parent_child_text`
- `avm2_*text*` ×4
- `avm2_contextmenu_stub`
- `convertfloat_type1_this`
- `mc_event_cross_swf_version`
- `mc_event_type1_args`

### Render canary

- **BEFORE:** clean base; **AFTER:** this patch. Both in an isolated worktree. Run on each base: the original `31fff3bf`, then `ab22f11e`, then the **final `2afd3e36`**.
- **On `2afd3e36` (final) and on `ab22f11e`:** 55 tests / **99 PNGs, 99 IDENTICAL** each time, no trace or image status changes. That is the 49 standing AVM1 members plus 6 of the 7 extra rows below; `leading_define_font` OOMs at `-P 2` and was A/B'd only pre-rebase.
- The two bullets below are the pre-rebase legs.
- **49 AVM1 canary members:** 82/82 PNGs IDENTICAL. No trace or image status changes. The AS3 members are out of scope: the patch is AVM1-runtime only, and `ng_wrap_count_lines` has no AVM2 caller.
- **The 7 other `createTextField` image tests:** 18/18 identical.
  - `avm1/movieclip_create_text_field`
  - `avm1/frame_size_translated_{negative,positive}`
  - `from_shumway/acid/acid-text-5`
  - `visual/edittext/edittext_caret_empty`
  - `visual/fonts/advance_u16`
  - `visual/fonts/leading_define_font`
- **Appended at EOF:** `avm1/movieclip_create_text_field` (tier=1, CI image pass, max_diff 0). The standing set had only incidental createTextField users.

---

## 3. Item 3: the CallMethod `createTextField` depth / numeric-name residual (diagnosed, not landed)

**Measured:** I applied the w1 "naive" fix (store the ToNumber'd depth) to the `actionCallMethod` arm on the current stack, with instrumentation.
- **v7 and v8 stay ruffle_matched**, so the w1 v7 regression does not reproduce.
- Every CallMethod `createTextField` in the gnash test has a **string** name (`tf45`, `htf`, `tfmo`). The numeric-name path (`createTextField(3, …)`) is the free-function form, which P15 already fixed. So w1's `_root[3]` movement most likely came from its numeric-name half interacting with a since-changed state. It is not a property of the depth store.

**Why I did not land it anyway:**
- Dynamic fields are drawn in the TF REST pass in `child_mc_cache` order (`tf_window_skip`, `action.c`). Their depth value does not change paint order, so pixel risk is low.
- But `getNextHighestDepth` / `swapDepths` / `getInstanceAtDepth` would start seeing `this.createTextField` fields at their real depth. That is the common game pattern, and it moves depths for clips created afterwards.
- Neither the trace sweep nor the canary can see that class. It needs a `full` + images run of its own.

**The real gap the instrumentation exposed:**
- The test creates `tf2`, `tf3`, `tf4` and `repl1` **at depth 99 on top of `tf`**.
- Flash/Ruffle `replace_at_depth` removes the previous occupant. Ours keeps both: `createMovieClip` returns a fresh child and the depth is never compared against siblings.
- **Completion mechanism:**
  - Give both createTextField arms (and createEmptyMovieClip, if it shares the gap) a `replace_at_depth` step: remove the existing child at `(parent, depth)` before inserting.
  - Store the depth in the CallMethod arm.
  - Grade on `categories=full` + `images=true`.
- Price: S-M. Yield is unknown on trace; probably pixel in games.

---

## 4. Refutations and premise checks

- **"P17 is an M phase in the device-font advance loop" — refuted.**
  - The whole P17 cluster was three missing defaults on -2 fields: size 12, the default serif device face, and zero leading. Add the device-text x-scale and one SWF7 wrap rule.
  - None of it touches the EditText advance loop, so it does not collide with `w2-acid-text-kerning` (confirmed post-rebase: identical AFTER output).
- **"P16 needs the Phase-B binding (`actionTryBindTextFieldVariable`)" — partly refuted.**
  - That function is DefineEditText-only (`ng_textfield_idx >= 0`) and has placement-time semantics: it seeds the variable from the text.
  - Flash's *runtime* `variable =` assignment neither seeds nor resets.
  - So P16 is a separate -2-field rebind that reuses only the Phase-C registry. The DefineEditText path is unchanged.
- **"P21 needs the bound-undefined rule everywhere" — no.** It is v7+ only, and only in the registry notify. The legacy name-scan `ng_syncVarToTextFields` keeps its skip.
- **Ruffle is worse than Flash on P16.** It resets to the initial text, which gives 3 shared lines that we now pass. No disposition doc needs an entry: our behaviour follows `output.txt` (Flash).

---

## 5. Not finished, with completion mechanisms

- **Shared (Ruffle-also-wrong) lines.** These remain on the three rows: 13/13/12 diffs on `2afd3e36` (13/25/24 before the span model landed).
  - The `restrict=""` pair is ACCEPTED; w1 §0 premise 5 questions it.
  - The `#passed/#failed` summary lines.
  - `_root._parent == 'fake_parent'` (xcheck).
  - The v7/v8 replaceText behaviour block (12 lines) is now fixed on master by `w2-edittext-span-model`.
  - autoSize=center width 60 vs 63.
  - The softref typeof after removal.
  - None of these gate a flip. A Flash-exact `pass` is impossible while the ACCEPTED `restrict` entry and the summary lines stand.
- **P13 for timeline-placed (DefineEditText) fields.** Ruffle constructs every TextField through `_global.TextField`; I did it only for createTextField (the brief's scope). Completion: call `tfCallGlobalCtorOnField` from the two `findOrCreateMovieClip` TF sites, then sweep the avm1 monkeypatch rows plus a full run.
- **Item 3**, as described in §3.

## New unclaimed leads

- **`replace_at_depth` for createTextField / createEmptyMovieClip** (§3).
- **The device-text x-scale for DefineEditText device fields.** I gated it to -2 fields to keep scope. Ruffle applies `device_font_scale_x` to every device-font EditText's textWidth.
- **The SWF≤7 wrap give-up rule in the other wrap loops.** `ng_computeScrollMixedFont` (textHeight/scroll with mixed runs) and the `tag.c` render wrap still break per-character. Ruffle uses one `wrap_line` for all of them. Pixel yield is possible on narrow SWF≤7 fields; coordinate with whoever owns the AVM1 EditText render loop.

## LOCAL ORACLE REQUESTS

None. Every remaining line on the three rows is shared with Ruffle, and the Flash expected output settled every behaviour this patch implements.
