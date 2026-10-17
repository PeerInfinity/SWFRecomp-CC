# s22 wave 2 — `w2-htmltext` report (AVM1 + AVM2 htmlText `<img>`, last-wins attributes, setNewTextFormat face, SWF5 refs)

**NEW FILES**
- `SWFModernRuntime/include/html_img.h` — header-only (all `static`), shared by `action.c` and
  `avm2_text.c`. No new TU, so no `verify_output.py` / CMake / Emscripten list change (same
  precedent as `include/gradient_ramp.h`, `include/curve_flatten.h`).
- `SWFRecompDocs/plans/session22-fanout-reports/w2-htmltext-report.md` (this file)
- `SWFRecompDocs/plans/session22-fanout-reports/w2-htmltext.patch`

No new fixture dirs and no `render_canary_tests.txt` change (see §5: every behaviour has a corpus
test; the standing canary already covers the text render paths this touches).

## 1. Verdicts and priced flips

| item | verdict | flips |
|---|---|---|
| M7a last-wins attributes (AVM1 `tf_get_attr` + AVM2 `attr_find`) | **GO, landed** | feeds the dup-attr test (176 → 241/247), no flip on its own |
| M7b setNewTextFormat device-font **name** | **GO, landed** | needed by numeric_attributes and dup-attr |
| M7c `<img>` SWF ≥ 7 (AVM1 parser + serializer) incl. numeric prefixes | **GO, landed** | `avm1/html_text_img_parsing_swf7`, `_swf8`, `avm1/html_text_img_numeric_attributes` |
| M7d SWF5 htmlText semantics | **GO, landed** — it *is* one SWF5 gate (mechanism found, §3) | `avm1/html_text_img_parsing_swf5` |
| AVM2 `<img>` port (same helper) | **GO, landed** | `avm2/html_text_img_parsing` → ruffle_matched |
| `avm1/edittext_html_duplicate_attributes` full pass | **NO-GO in this slot** — remaining 6 lines are a different, pre-existing feature (AVM1 `getTextFormat` ignores styleSheet CSS). Completion mechanism in §6. | stays fail (176 → 241/247) |

**Net: +5 effective** (4 pass, 1 ruffle_matched), 0 regressions on 59 trace canaries (byte-identical
actual output) and 118/118 canary PNGs md5-identical.

## 2. EXPECTED-FLIP LEDGER (the coordinator checks CI against this)

Trace axis (graphics and no-graphics both verified locally):

| test | before (clean origin/master) | after | notes |
|---|---|---|---|
| `avm1/html_text_img_parsing_swf5` | fail 344/517 | **pass** 517/517 | M7d |
| `avm1/html_text_img_parsing_swf7` | fail 346/517 | **pass** 517/517 | M7c |
| `avm1/html_text_img_parsing_swf8` | fail 346/517 | **pass** 517/517 | M7c (IMG inside `<A>`) — new upstream test |
| `avm1/html_text_img_numeric_attributes` | fail 1/3 | **pass** 3/3 | KF upstream; Flash-correct pass beats Ruffle (allowed) |
| `avm2/html_text_img_parsing` | fail 338/600 | **ruffle_matched** (505/600 = all 505 Ruffle lines) | KF upstream; the 95 missing lines are `Error #2044` img loads (HOLD, §6) |
| `avm1/edittext_html_duplicate_attributes` | fail 176/247 | fail **241/247** | KF; NOT a flip (§6) — new upstream test |

Pixel axis: **no expected movement.** None of the six headline tests has `[image_comparisons]`.
Every canary PNG is md5-identical (§4).

Drift notes for the coordinator: `html_text_img_parsing_swf8` and
`edittext_html_duplicate_attributes` are new upstream tests (absent from the 10-03 CI board), so
they are not in the 4476 baseline; `avm1/html_text_img_parsing` (no suffix) was deleted upstream
(`d587c9763`) — a −1 fail from the denominator, not yield. Book the swf5/swf7/swf8/numeric rows
against the rewritten upstream expectations (`UPA` in `wave0-trace-inventory.txt`).

## 3. Mechanisms (owner `file:line` on the branch)

### M7a — last attribute wins
- AVM1 `tf_get_attr` (`action.c`, "HTML Parser — tf_parse_html()" block): scan every
  occurrence, keep the LAST one that starts at a word boundary and is followed by `=`, then read
  its value exactly as before. Last-wins even when the last value is invalid (`size='10'
  size='abc'` → 12). The word boundary also stops `size` matching inside `fontsize=`.
- AVM2 `attr_find` (`avm2_text.c`): iterate the parsed attribute array in reverse.
- Ruffle `69a017387` (`attributes.iter().rev()`).

### M7b — setNewTextFormat stores the font NAME
- `setNewTextFormat` arm in `actionCallMethod` now also stores `_tf_fontName` (string) next to
  `_tf_fontId` (same `#if NO_GRAPHICS || OFFSCREEN_RENDER` arm, so both CI modes).
- New `tf_apply_new_format_font(mc, def)` (static, next to `tf_get_defaults`) overrides
  `def->font_name`. It is called after `tf_get_defaults` at the three htmlText default sites:
  the shared helper (`tf_get_defaults(mc, &defaults)` in the htmlText-from-props helper), the
  main `SetMember htmlText` parse (the `// Parse HTML into format runs` block), and the
  non-html htmlText getter (where it wins over the `_tf_fontId` lookup). Device fonts ("Times")
  have no SWF font id, so the id-only store fell back to "Times New Roman".
- Correction to the w1 brief's line refs: the `:22705` / `:57088` callers alone were not enough.
  The live path for `tf.htmlText = …` on an `html=true` field is the SetMember parse block
  (~`:54308` on the branch).

### M7c — `<img>` (AVM1, SWF ≥ 7)
- Parser (`tf_parse_html`, new `img` arm right after `br`). Without `src`, the tag is dropped.
  With one: FLUSH, add a single `' '`, and push a run that copies the current format with
  `font_height = 40` (size 2) and `img = html_img_intern(...)`. The format stack is not touched.
  src/id (and every img attribute, as Ruffle does) are entity-decoded with `tf_decode_entity`.
  SWF ≤ 6 still drops `<img>` (the `swf6` test is a canary and still passes).
- SWF ≤ 7 all-whitespace post-pass: an img run counts as content. `<img src='m.jpg'>` alone
  gives `TEXT= ` and not empty.
- Serializer (`tf_serialize_html`):
  - group equality includes `img`, so two identical adjacent images merge into one IMG and two
    spaces ("Flash Player merges two identical images into one");
  - IMG is emitted before `<A>` for SWF7 and after it for SWF8+ (Ruffle `set_span`,
    `text_format.rs:1694-1704`);
  - the size-2 run naturally opens `<FONT SIZE="2">`;
  - new rule: a paragraph whose last content is an img and that ends in a break emits
    `<FONT SIZE="12"></FONT>` when the break's font is not on the FONT stack (Ruffle
    `close_font_if_feasible` + `set_font` before `push_text` drops the newline).
- `TFRun` gains a trailing `u16 img` (0 = none; every existing copy/memset site leaves it 0).

### Shared rules — `include/html_img.h`
`HtmlImg` + `html_img_set_attr` / `html_img_intern` / `html_img_serialize`. These are the rules
both VMs use:
- align is `right` only for exactly `"right"` (case-sensitive), anything else present is `left`;
- CHECKPOLICYFILE is written only for `true` (any case);
- width/height/hspace/vspace are numeric-**prefix** parses (`40.9px` → 40.9), written truncated
  toward zero. A value with no numeric prefix is dropped. This is the Flash behaviour Ruffle
  still lacks (its TODO at the `img` arm). `avm1/html_text_img_numeric_attributes` is that
  Flash output.
- src/id are written verbatim (`SRC="foo&bar.jpg"`).

Images are interned in a 1024-entry per-TU pool, so attribute equality is index equality. When
the pool is full it recycles from the start. Only a field that keeps one image across more than
1024 later distinct parses could alias, which is far outside any corpus row.

### M7d — SWF5: a text-field reference IS its parent clip
Mechanism, found in Ruffle (the HOLD's 1-hour read):
- `core/src/avm1/activation.rs:683` `stack_push` converts every object it pushes through
  `MovieClipReference::try_from_stage_object`;
- `core/src/avm1/object_reference.rs:78` and `:103-119` (`process_swf5_references`): in SWF ≤ 5
  a non-MovieClip display object resolves to its **first MovieClip ancestor**.

So in the swf5 test `var tf = _root[name]` *is* `_root`. Then `tf.htmlText = html` is a plain
property of `_root`, so `HTML=` is the raw source, and `tf.text` is undefined, so `TEXT=` is
empty. (`setNewTextFormat` is also absent there; Ruffle declares it `VERSION_6`.) The w1
hypothesis ("no TextField getters in SWF5") predicted the right output for the wrong reason.

Our gate (`action.c`):
- `swf5TextFieldRefToClip()` runs on the results of the public `actionGetMember` and
  `actionGetVariable`, which are now thin wrappers around the renamed static
  `actionGetMemberImpl` / `actionGetVariableImpl` (self-localized: no body change).
- When `g_swf_version <= 5` (the swapped per-caller version) and the top of the stack is a
  text-field MovieClip, it replaces the pointer with the nearest non-text-field ancestor.
- Second half of the same gate: the SetMember `htmlText` parse block now requires
  `g_swf_version > 5 || MC_IS_TEXTFIELD(mc)`, so `_root.htmlText = …` in SWF5 stays a plain
  property (before, a plain clip with `html=true` got text-field parsing). For SWF6+ the condition
  is unchanged.

The gate is narrower than Ruffle's: text fields only, and only at GetMember/GetVariable rather
than at every push. Buttons, video and other non-MC objects are not converted. SWF ≤ 5 canaries
are unchanged (§4).

### AVM2 port (`avm2_text.c`)
- `Avm2TextSpan` gains a trailing `uint16_t img`:
  - `spans_push` / `spans_insert` zero it;
  - `span_break_at` copies it to the split half;
  - `spans_normalize` merges only spans with equal `img`.
- New `img` arm in `spans_from_html` (gated on `swf_version >= 7`, always true for AVM2). It uses
  the same helper and pushes a size-2 `' '` span; the format stack is untouched.
- `condense_white_swf8` port of Ruffle's image rule: the placeholder at an image span's start is
  never removed, but whitespace after it still collapses.
- `HtmlWriter.img` (trailing field) carries the span's image into `hw_set_span`, which writes IMG
  before `<A>` for SWF < 8 and after it for SWF 8+.

## 4. Evidence — before/after, same box (lavapipe Dawn, `--mode=graphics`)

Before = clean origin/master `35381a40c` (patch reverse-applied). After = this patch on the same
base. Byte comparison of every saved actual output:

| set | result |
|---|---|
| 6 headline rows | changed as in §2, and only those |
| 10 `avm1/edittext_html_*` (align_swf7/8, color, condensewhite_swf7/8, entity, roundtrip, swf6/7/8) | PASS → PASS, **byte-identical** |
| gnash `TextFieldHTML-v5..v8` | PASS → PASS, byte-identical |
| `avm1/html_text_img_parsing_swf6` | PASS → PASS, byte-identical |
| AVM1 setNewTextFormat/htmlText users: `clone_sprite_edittext{,_dynamic}`, `edittext_align_trailing_spaces_swf7/8`, `edittext_default_format_font_style`, `edittext_onscroller` (RM), `edittext_stylesheet`, `edittext_tag_indent`, `edittext_text_height_leading`, `issue_9327`, `textfield_props_swf8` | unchanged, byte-identical |
| AVM2 html parser users: `edittext_html`, `edittext_html_condensewhite`, `edittext_html_font_size_swf12/13`, `edittext_set_html_same`, `edittext_set_text_vs_html`, `edittext_stylesheet{,_custom_tag,_display}`, `stylesheet_parse_color` | PASS → PASS, byte-identical |
| SWF ≤ 5 gate canaries (every SWF5 movie in avm1/gnash with an EditText or createTextField, plus path tests): gnash `MovieClip-v5` (RM), `Object-v5` (RM), `TextField-v5` (RM), `TextFormat-v5`, `Selection-v5`, `Boolean-v5`, `getvariable-v5`, `targetPath-v5`, `with-v5` (RM), misc-ming `Version4Loader`, `action_execution_order_test8-v5`, `frame_label_test`, `move_object_test`, `place_object_test` (RM), `shape_test`, `timeline_var_test`; avm1 `focusrect_property_swf5`, `tell_target` | unchanged, byte-identical |
| regression suite (text-adjacent): `avm1_parent_child_text`, `avm2_bitmapdata_draw_textfield`, `avm2_static_text`, `avm2_timeline_text` | PASS → PASS, byte-identical |
| **render canary**: the standing `render_canary_tests.txt` set (67 members) plus the remaining `[image_comparisons]` tests whose SWF uses htmlText/setNewTextFormat (`avm1/edittext_stylesheet`, `avm2/edittext_get_char_index_at_point`, `avm2/edittext_get_line_index_at_point`; `edittext_tag_indent` and `edittext_autosize_height_dynamic` are already members) = 70 tests | **118/118 PNGs IDENTICAL**, no trace or image status changes |

No-graphics mode: the headline tests give the same verdicts as graphics (swf5/7/8/numeric PASS,
avm2 RUFFLE_MATCHED, dup MISMATCH).

The **merged-tree re-check** (this patch merged with origin/master `f0f8986ac` — as-core,
crossvm, queue-regex, default-fonts-draw, drawing-api-lyon, glyph-subunit landed meanwhile; the
merge was clean) is in §4a.

### 4a. Merged-tree re-check

Branch = this patch merged into origin/master `f0f8986ac`. The recompiler was rebuilt and every
test was rerun with `--recompile`: the 64 trace rows of §4 (headline + canaries + SWF5 + regression).
All **64 actual outputs are byte-identical** to the pre-merge "after" leg, and every verdict is the
same.

The render canary was not re-captured on the merged tree. Master's own render changes (glyph-subunit,
default-fonts-draw, drawing-api-lyon) would move PNGs with no master-only leg to separate them. The
patch was shown render-neutral on the pre-merge base (118/118 identical), and it touches no render
code.

A second clean merge followed, with origin/master `e3ebb3c2c` (adds w2-strbuf, which changes
`Avm2String`, and w2-ei-provider). The rows rerun with `--recompile` were `avm2/html_text_img_parsing`,
`avm2/edittext_html`, `avm2/edittext_html_condensewhite`, `avm2/edittext_set_html_same`,
`avm2/edittext_stylesheet`, `avm1/html_text_img_parsing_swf5`, `_swf8` and
`avm1/html_text_img_numeric_attributes`. All have the same verdicts, and all actual outputs are
byte-identical to the "after" leg. **The patch is against `e3ebb3c2c`.**

## 5. Patch scope

`w2-htmltext.patch` = `git diff origin/master -- SWFRecomp SWFModernRuntime
ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`, regenerated after the final
edit and checked with `git apply --check -R`. Files:
- `SWFModernRuntime/include/html_img.h` (new);
- `SWFModernRuntime/src/actionmodern/action.c`:
  - `TFRun.img`, the `#include`, `tf_get_attr`, `tf_parse_html` img arm and post-pass,
    `tf_serialize_html` (group key, IMG emission, img-break FONT);
  - `tf_apply_new_format_font` + 3 call sites, the `setNewTextFormat` `_tf_fontName` store;
  - the `actionGetMember`/`actionGetVariable` wrappers + `swf5TextFieldRefToClip`, the SWF5 guard
    on the SetMember htmlText block;
- `SWFModernRuntime/src/avm2/avm2_text.c`: `Avm2TextSpan.img`, `attr_find`, the
  `spans_from_html` img arm, `condense_white_swf8`, `HtmlWriter.img` / `hw_set_span`.

Sibling overlap (SIBLING_FILE_MAP): w2-as-core and w2-array-global also edit `action.c`. The
merge with as-core (already on master) was clean. The GetMember wrapper is the one spot where a
sibling's helper layer meets this patch: as-core's `as_get` calls `actionGetMember`, so it also
gets the SWF5 conversion. That matches Ruffle, which converts on every push.

## 6. Not finished, with completion mechanism

1. **`edittext_html_duplicate_attributes` 241/247 (NO-GO here).** All 6 remaining lines are in
   the `runStyleCase` block (`tf.styleSheet = css; tf.htmlText = …; tf.getTextFormat(i,i+1)`).
   AVM1 `getTextFormat` does not apply styleSheet CSS (class/tag colour, plus the `<a>` url under
   a stylesheet). By code reading, the html=true SetMember path builds the TFRunTable with
   `tf_parse_html`, which has no CSS input, so `getTextFormat` reads unstyled runs. CSS is applied
   only by the renderer's `tf_styled_runs_from_html`, whose class scan is already last-wins.
   Duplicate attributes are not the issue.
   Completion mechanism: make the html=true + styleSheet SetMember path build the TFRunTable with
   CSS applied (reuse `tf_styled_runs_from_html`'s selector lookup, or apply styles in
   `tf_parse_html` given the field's `styleSheet._styles`), so `getTextFormat` reads styled runs.
   Price: the full pass also needs the `[1]` (`\r`) row of `<p class>` at `color=255`. Ruffle
   prints `0` there, Ruffle being 2 lines short in total (its `ruffle.txt` also differs at
   line 59, kerning, which we already match to Flash). So it would be a Flash-correct pass on a
   KF test, +1. New lead L1.
2. **`avm2/html_text_img_parsing` full pass (HOLD, unchanged from w1).** It needs the 95
   `Error #2044: Unhandled IOErrorEvent:. text=Error #2035: URL Not Found.` lines. Mechanism: a
   per-`<img>` Loader in the TextField that fails the load and reports the unhandled IOErrorEvent
   at tick end.

## 7. Refutations / premise checks

- **Brief premise "M7b callers are `:22705`, `:57088`": partly refuted.** Those two sites alone
  don't move the test. The live `tf.htmlText =` path is the SetMember parse block. All three are
  patched.
- **M7d hypothesis (w1: "SWF5 field has no TextField getter props"): refuted on mechanism,
  confirmed on output.** It is Ruffle's SWF5 MovieClipReference rule (§3). A "no getters" fix
  would have broken `TextField-v5` and the other SWF5 EditText canaries, which read real field
  values through variable bindings.
- **"Numeric prefixes are Flash behaviour": confirmed** by `html_text_img_numeric_attributes`
  (Flash `WIDTH="40" HEIGHT="30" VSPACE="6" HSPACE="4"`) and by the swf7/8 rows where
  `width='abc'` drops the attribute.
- **SWF8 IMG placement:** IMG goes after `<A>` but still before `<B>` (`<IMG SRC="m.jpg"><B>
  </B>`). The B/I/U tags are reopened per run by our serializer, so this falls out of the
  emission order.

## New unclaimed leads

- **L1** — AVM1 `getTextFormat` on a styleSheet field returns no CSS formatting (colour/bold from
  class/tag selectors, and `url` under a stylesheet). Mechanism and price are in §6.1. Likely more
  rows than the dup-attr one: grep avm1/gnash for `styleSheet` + `getTextFormat`.
- **L2** — the SWF5 reference rule covers only text fields today. Ruffle applies it to every
  non-MovieClip display object (buttons, video, bitmaps) and on every stack push, not only at
  GetMember/GetVariable. No corpus row was found failing on it in this sweep. A SWF5 button-ref
  test would be the probe.

## LOCAL ORACLE REQUESTS

none
