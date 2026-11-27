# s30 w1-drift-smalls — upstream drift + flash_fixes check + four small trace leads

Wave 1 (diagnosis + measured prototype). Cloud worker, branch `fanout/w1-drift-smalls`.
Base: `origin/master` `f4edebdc` (code = `2d40d3799`). Upstream Ruffle downloaded at **`66f9073de`** (= the brief's
tip; `git ls-remote` re-checked at run time, nothing newer). Categories downloaded: avm1 avm2 from_gnash from_avmplus
from_shumway visual text timeline mixed_avm. `SETUP_STATUS`: apt/Pillow/Dawn all OK; every run below is `--mode=graphics`
unless it says otherwise.

**New files (all under `session30-fanout-reports/`):**
- `w1-drift-smalls-report.md` (this file)
- `w1-drift-smalls-prototype.patch` — `git diff --binary origin/master -- SWFModernRuntime SWFRecomp` plus the two new
  regression fixture dirs `ruffle-tests/tests/swfs/regression/avm1_tabindex_textfield_v6/` and `_v8/` (README, output.txt
  = FP32 golden, test.swf, test.toml). `git apply --check` passes on `origin/master`. Sources are reverted in the commit.
- `w1-drift-smalls-oracle/make_tabindex_clip_button.py` + `tabindex_clip_button/{v6,v8}/{test.swf,test.toml,ours.txt}`
  (FLASH request 1)
- `w1-drift-smalls-oracle/html_img_loadcount/Test.as` (AS3; FLASH request 2)

## Verdicts and priced flips (lead with these)

| Item | Verdict | Row(s) | before → after (prototype) | Price |
|---|---|---|---|---|
| A drift | **GO (lead, partial)** | `avm2/xmldocument_tostring` (new row) | mismatch, 12/32 prefix lines → mismatch, **23/32** | 9 lines left: one M mechanism (XMLNode fields as traits). No flip in the prototype |
| B flash_fixes | **clean** | all 94 entries | 94 `ALREADY`, **0 STALE, 0 UPSTREAMED** | — |
| C tabIndex (text field) | **GO, land as is** | `regression/avm1_tabindex_textfield_v6` / `_v8` (new, FP32 goldens) | 3 diff lines each → **PASS** (graphics AND no-graphics) | +2 regression rows; 0 corpus rows move |
| C clips/buttons | **HOLD → FLASH request 1** | — | ours: `-1` stays `-1`, `delete` unsets | completion = FP32 capture |
| D `html_text_img_parsing` | **HOLD (do not land the prototype yet)** | `avm2/html_text_img_parsing` (rm, 505/600) | rm → **mismatch** (all 600 golden lines printed, plus 3 extra `#2044` lines = 603) | **The row CAN pass** (refutes the brief): needs the exact load count, 95 not 98. Landing at 98 LOSES 1 effective row (rm → mismatch) |
| E line 71 | **GO** | `avm1/movieclip_hittest_shapeflag` | line 71 `false` → `true` (= FP32) | 1 line |
| E line 296 | **GO** | same | line 296 `true` → `false` (= FP32) | 1 line. Row stays mismatch on the 4 ACCEPTED device-font lines (171–177), as predicted |

Families A/B (before vs after, same box, md5 of the diff lines):
- tabIndex family, 38 rows (31 avm1 `tab_ordering_*`/`textfield_props_*`/focus/clone/`global_*decls*` + 7 regression
  `avm1_tabindex_*`): every status equal to the s30 baseline; the 4 non-pass rows (`global_instance_decls`,
  `global_proto_decls`, `global_proto_decls_delete` mismatch, `movieclip_library_state_values` rm) have **byte-identical
  diffs** before and after.
- XML family, 10 rows (`avm2/flash_xml*` ×4, `xml_ignore_white`, `xml_namespace_methods`, `xmldocument`, `xmlnode`,
  `describe_type_native`, `all_classes/xml/{swf9,swf30}`): all PASS after.
- hitTest family, 35 rows (avm1 `*hittest*` ×9, avm2 `*hittest*`/`hit_test*` ×11, regression `*hittest*` ×2, gnash
  `HitTest-v6/7/8`, shumway `hittesting`, `hitTestStyleChange`, avm2 `getobjectsunderpoint`, `mouse_pick_scroll_rect_button`,
  `simplebutton_*` ×3, `displayobject_scrollrect`, `focus_events_mouse_*` ×2), `--recompile`: **identical** before/after
  except the headline row (6 → 4 diff lines). gnash `HitTest-v8` stays rm (unchanged).
- AVM1 button/mouse/drag rows, 32: all PASS after (trace); `mouse_events_visible_enabled` image fail is the baseline
  failure (3610 channels, unchanged).
- regression neighbours (`*xml*|*html*|*textfield*|*hittest*|*shape*`, 18): all PASS.

## A. Upstream drift `b7ff32d93..66f9073de`

11 commits. `git diff --stat b7ff32d93 origin/master -- tests/` touches exactly one dir: the new
`tests/tests/swfs/avm2/xmldocument_tostring/` (Test.as, output.txt 32 lines, test.swf, test.toml). No other golden or
toml moved. Non-corpus: `952362ecf` (player frame pacing on jittered refreshes, desktop/web loop — not the test runner),
`9c6de33ae` (SwfSlice refactor), web/build/deps ×6. Two behaviour commits back the new row:
- `ac8da3724` — `XMLNode.hasChildNodes()` is `firstChild != null` (was `_children.length > 0`).
- `7e4f86f48` — `XMLDocument.toString()`: `xmlDecl` + `docTypeDecl` when non-null, `"<>"` when the *virtual*
  `hasChildNodes()` is false, else each child's *virtual* `toString()` walking `firstChild`/`nextSibling`; `nodeName`
  ignored.

**Provenance:** `710759d63`'s message says "Add Flash Player verified tests". Treat as Flash-provenance (optional
confirmation in FLASH request 3; not blocking).

**Status:** before = `output_mismatch` (lines 1–12 match; we serialized the child array, ignored hasChildNodes/firstChild
mutation, never called overrides). Prototype (`avm2_xml.c`):
- new `n_xdoc_to_string` (the upstream rule, calling `hasChildNodes` and each child's `toString` through
  `avm2_call_public_property`, re-reading `nextSibling` after each call), installed by re-pointing the copied
  `toString` vtable entry's `method.fn` in `avm2_register_xml_legacy` (the existing `defining_class = doc` loop);
- `n_xn_has_child_nodes` → `firstChild != null`.

After: lines 1–23 match (23/32). **Remaining 9 lines (24–32)**: `ReferenceError: Error #1065: Variable nodeName is not
defined. at CustomXMLNode/toString()`. Mechanism: our XMLNode keeps `nodeName`, `nextSibling`, … as DYNAMIC properties
(`xn_set` → `avm2_object_set_dynamic`, `xmlnode_init_common`). Inside a method of a sealed user subclass, the bare name
`nodeName` is a `findpropstrict` over the scope chain, and our non-`with` scope walk is trait-only
(`avm2_op_findpropstrict_ic` → `findproperty_scope_walk_loc`), exactly like Ruffle's `ScopeChain::find` (`has_trait`).
Flash/Ruffle declare these as `public var` traits on XMLNode, so they resolve. **Completion mechanism (M):** make the
XMLNode/XMLDocument fields real instance traits (slots or native getset backed by `Avm2XmlNodeExt`), and move every
`xn_get`/`xn_set` onto them. Risks to measure: `all_classes/xml/*` describeType (variable vs accessor), for-in over an
XMLNode instance (dynamic props enumerate; traits do not, which is the Flash behaviour). The 23/32 prototype is safe to
land on its own (row stays mismatch; XML family all PASS).

## B. flash_fixes `--check`

`python3 ruffle-tests/apply_flash_fixes.py --check` after the download: **`flash-fixes: ALREADY 94 (check only)`**, every
line `ALREADY` (the download already applied all 94, including the new `from_shumway/acid/acid-large`). **0 STALE, 0
UPSTREAMED.** Expected: the drift window touches no golden that has an entry.

## C. TextField `tabIndex`

Capture: `pre-launch-oracles/tf_tabindex_null/` (FP32 LNX, v6/v8). Before (origin/master), both fixtures fail on **3**
lines, not the 2 the brief lists:

| line | FP32 | ours before | owner |
|---|---|---|---|
| `null` | `undefined` | **`0 number`** | `actionSetMember`, tabIndex block: the s29 w3 null arm is `!MC_IS_TEXTFIELD(mc)`-gated ("text fields keep the coercion: no capture covers them") |
| `neg` (`-1`) | `undefined` | `4294967295` | same block, text-field arm: `(uint32_t)ecmaToInt32` with no sentinel |
| `del` | `4` | `undefined` | `actionDelete`, MOVIECLIP arm: deletes the `dynamic_props` copy |
| `enum tabIndex` | printed | missing | consequence of `del`: the fixture enumerates AFTER the delete. No separate fix needed |

**Premise refutations.** (1) "Our null rule already holds for text fields" is false at `2d40d3799` (above; README §7's
"lines 1–7 match" read a truncated diff). (2) "A NEGATIVE value unsets" is false by the capture's own `min` line:
`-2147483648` reads back `2147483648`. The rule is the **`-1` sentinel**: the u32-coerced value `0xFFFFFFFF` unsets.
This is Ruffle's model too (`interactive.rs` `set_tab_index`: "tabIndex = -1 is always equivalent to unset";
`text_field.rs` getter prints `index as u32`), so no Ruffle≠Flash entry.

Prototype (`action.c`, both functions named):
- `actionSetMember`, tabIndex block: null → undefined for text fields too (gate removed); text-field arm maps
  `0xFFFFFFFF` → undefined.
- `actionDelete`, MOVIECLIP arm: `MC_IS_TEXTFIELD(mc)` + name `tabIndex` → push `false`, keep the value (native
  `TextField.prototype` accessor).

Result: `regression/avm1_tabindex_textfield_v6` and `_v8` (golden = FP32 file) PASS in graphics and no-graphics.
Clip/button arms untouched.

**Clips/buttons:** the s29 `regression/avm1_tabindex_*` goldens hold no `-1`, `-2` or `delete` probe, and corpus
`tab_ordering_custom_m1` only puts `-1` on text fields. Ours on a timeline clip, a script clip and a real Button (fixture
below): `-1` → `-1`, `-2` → `-2`, `-2147483648` → `-2147483648`, `delete` → `true` then `undefined`. Ruffle predicts `-1`
→ `undefined` (the shared `set_tab_index`), `-2` → `-2`, and `delete` a no-op (native prototype property; `DONT_ENUM` on
MovieClip). **FLASH request 1.** If FP32 agrees with Ruffle, the wave-2 patch is the same two arms without the
`MC_IS_TEXTFIELD` gates (on clips the value sits in `dynamic_props` as `DONTENUM`, so `actionDelete` must skip it there
too).

## D. `avm2/html_text_img_parsing` — the #2044 path

**Row facts.** 600-line golden: 505 trace lines + **95** `Error #2044: Unhandled IOErrorEvent:. text=Error #2035: URL Not
Found.` at the end (506–600, all identical). `known_failure = true`, `output.ruffle.txt` = the 505 trace lines (Ruffle
prints no #2044). Ours before = exactly `output.ruffle.txt` → rm.

**Which side we print, and the refutation.** The golden is the WINDOWS FP32 capture: all 95 say `#2035`. The fresh LNX
capture differs only on line 510, `#2124: Loaded file is an unknown type`. Counting `<img src=…>` loads in parse order,
the 5th load is case 7, `A<img src=''>B` (cases 1–4 have `src='missing.jpg'`, cases 5–6 have no `src`). So LNX resolves
the empty URL to the SWF's own directory (unknown type), and Windows reports it not found (inference from the order;
every line is otherwise identical). We print `#2035` for every failing image, including `src=''`: the Windows side,
which is the golden's side. So **this row can reach PASS**. The platform line does not block it (the brief and register
§1a say it does). What blocks it is the count.

**Prototype.** `avm2_text.c` `spans_from_html` (`img` arm): each `<img>` with a `src` (SWF ≥ 7, the existing placeholder
rule) calls the new `avm2_html_img_load_started` (`avm2_display.c`). That counts the load as failed unless
`loader_resolve_url` finds a bundled file. `avm2_loader_resolve_fetches` gets a new `avm2_html_img_flush_failed`, which
prints one `#2044 … #2035` line per failed image with no stack tail, in the same drain as Loader/URLLoader fetches, and
keeps the loop alive while any are pending. No Loader/LoaderInfo objects are created: nothing in the corpus listens on
them (`getImageReference` is not implemented).

**Measured: 98 lines, not 95.** All 600 golden lines are printed, then 3 extra. Naive count from `Test.as`: 98 img-with-src
parses (runDefaultCase ×1, runAllCases ×4, runReparseCase ×2). So FP32 starts **3 fewer** loads than one per `<img src>`
placeholder. The golden's HTML shows Flash MERGING adjacent identical images into one run (`<IMG SRC="a.jpg">  `, two
spaces) in 5 cases: plain `a.jpg` ×2, `height`, `hspace`, `vspace`, `checkPolicyFile`. That gives −5, not −3, so "one load
per merged run" is not the rule either. The rule is undetermined: **FLASH request 2** runs one case per 20 frames.
**Completion mechanism:** apply the measured per-case count (expected S once known) → 95 → **PASS (+1 pass, from rm)**.
Until then, do NOT land D: at 98 the row goes rm → mismatch (−1 effective row). No other downloaded row parses `<img>`
in AVM2 (grep over avm2/from_shumway/from_avmplus/text/timeline/mixed_avm).

## E. `avm1/movieclip_hittest_shapeflag` lines 71 and 296

Before: 6 diff lines (71, 171, 173, 175, 177, 296). After: **4** (171–177, the ACCEPTED device-font set).

**Line 71 (`// layers`, `hitTest(300, 400, true)`) — owner: layer boundaries are lost.** Ruffle's `shape_hit_test`
(`render/src/shape_utils.rs`) tests and resets the winding at every StyleChange that carries `new_styles` (a new layer,
whose fill indices restart at 1). Our recompiler (`SWF::interpretShape`, `swf.cpp`) emits no layer marker into
`path_data`, and `ng_hitTestPathFill` (`shape_hit_test.c`) accumulates `fill_winding[fill_index]` across layers. So
layer 2's fill 1 adds to layer 1's fill 1, and under even-odd two overlapping layers cancel → `false`. Prototype: the
recompiler emits `{6.0, 0, 0}` before the style-change record when `state_new_styles` (non-morph only; morphs cannot
carry new styles). `ng_hitTestPathFill` on cmd 6 tests the finished layer (returns hit), then zeroes the windings.
`path_data` is read ONLY by the CPU hit tester (ng_shared.c header comment). `ng_hitTestPathStroke` and the morph walker
fall through an unknown cmd. **Needs `--recompile`** (CI recompiles every run).

**Line 296 (morph complex shape, `hitTest(400, 300, true)`) — owner: the minimum stroke width, not morph
interpolation.** Debug trace: char 41, **ratio 0**, clip scale ×7.85162, local point (228.615, −399.408). Fill windings
sum to 0 (outside). The `true` came from `stroke_hit`: `ng_hitTestMorphPath` (and `ng_hitTestPathStroke`) clamp a
hairline to a flat **20 LOCAL twips**. That is 1 px only at scale 1, and 7.85 px on screen here. Ruffle's
`stroke_minimum_width` uses `20 × max column scale of the global→local matrix` (≈ 2.55 local twips here). Prototype: new
`ht_set_min_stroke` (`shape_hit_test.c`), called from `ng_hitTestShapeChar` before the morph and the plain stroke tests,
replaces both `20.0` clamps with `g_ht_min_stroke`. **Refutation:** the brief's owner (integer-twip `lerp_twips` + i64
cross product) is not it. At ratio 0 the lerp is the identity, and a measured `lerp_twips` port (`roundf` f32 lerp of
each coordinate) changed nothing (4 diff lines with or without it), so it is not in the patch. The ACCEPTED_DIFFS entry
"Morph fill boundary precision" mislabels the mechanism. Wave 2 should rewrite it to "stroke minimum width ignores
scale" when it lands.
- Wave-2 check: `ng_hitTestShapeChar`'s matrix is the "parent-accumulated" one, so for callers that pass a non-stage
  space the minimum would be computed from a partial matrix. The AVM1 `hitTest` and button-hover callers measured here
  are stage space.
- Not done (no measured row): Ruffle also rounds the LOCAL test point to integer twips (`Matrix * Point<Twips>`); ours
  stays fractional.

## Exact patch scope (prototype)

| file | functions |
|---|---|
| `SWFModernRuntime/src/actionmodern/action.c` | `actionSetMember` (tabIndex block: null gate, u32 `-1` sentinel), `actionDelete` (MOVIECLIP arm: text-field `tabIndex` no-op) |
| `SWFModernRuntime/src/avm2/avm2_xml.c` | `n_xn_has_child_nodes`, new `n_xdoc_to_string`, `avm2_register_xml_legacy` (re-point XMLDocument `toString`) |
| `SWFModernRuntime/src/avm2/avm2_text.c` | `spans_from_html` (`img` arm → `avm2_html_img_load_started`) |
| `SWFModernRuntime/src/avm2/avm2_display.c` | new `g_html_img_failed_loads`, `avm2_html_img_flush_failed`, `avm2_html_img_load_started`; `avm2_loader_resolve_fetches` (loop condition + flush) |
| `SWFModernRuntime/src/libswf/shape_hit_test.c` | new `g_ht_min_stroke`/`ht_set_min_stroke`; `ng_hitTestPathFill` (cmd 6 layer flush), `ng_hitTestPathStroke` + `ng_hitTestMorphPath` (min clamp), `ng_hitTestShapeChar` (sets the min) |
| `SWFRecomp/src/swf.cpp` | `SWF::interpretShape` (`{6,0,0}` on StateNewStyles) |
| `ruffle-tests/tests/swfs/regression/avm1_tabindex_textfield_v6/`, `_v8/` | new fixtures (FP32 goldens) |

Siblings: nothing in `setupNativeFuncOwnProps` or the native member tables. No AVM1 builtins outside the tabIndex
SetMember/Delete arms. `action.c` touches only `actionSetMember`/`actionDelete`. The D hunk is separable (split it out
until FLASH request 2 lands). Mode parity: no `swf_core.c`/`tag_stubs.c`/`NO_GRAPHICS` arm touched; C was also run in
no-graphics (PASS).

## New unclaimed leads

- **XMLNode fields as traits** (A's 9 lines; M). Above.
- **TextField `delete` of other native props** (`text`, `_x`, `htmlText`, …): FP32 makes the tabIndex delete a no-op
  because it is a `TextField.prototype` accessor. The same is likely for every native TextField property that we keep in
  `dynamic_props`. Unprobed; would need a capture.
- **Integer-twip local test point** in `ng_hitTestShapeChar` (Ruffle rounds; ours fractional). Unmeasured; boundary
  lines only.
- `html_text_img_parsing` load-count rule (FLASH request 2). That is the whole row.

## LOCAL ORACLE REQUESTS

1. **FLASH: `w1-drift-smalls-oracle/tabindex_clip_button/{v6,v8}/test.swf`**, trace, direct (pinned), `num_ticks = 2`, one
   LNX capture each (deterministic: no timers). Built by `make_tabindex_clip_button.py` (helpers from s29
   `w2-disposition-land-oracle/tabindex/make_fixtures.py`). It holds a timeline clip `c`, a `createEmptyMovieClip` clip
   `m` and a real DefineButton2 Button `b` (an empty-sprite record, all 4 states). Compare against `ours.txt` in the same
   dir: per target, `-1`, `-2`, `-2147483648`, and `delete` return + value. If Flash draws or rejects the button oddly,
   note it; the button lines are the point.
2. **FLASH: `w1-drift-smalls-oracle/html_img_loadcount/Test.as`** (AS3; `mxmlc -static-link-runtime-shared-libraries
   -default-frame-rate=30 Test.as -output test.swf`), trace, direct, **≥ 320 frames** (14 cases × 20 frames), LNX, 2
   captures (async error timing). Wanted: the number of `Error #2044` lines after each `CASE n` line. Expected on LNX:
   case 1 `src=''` prints `#2124`, the rest `#2035`. That is fine: we need only the COUNTS.
3. (Optional, low) **FLASH: corpus `avm2/xmldocument_tostring`**, trace, direct, 1 tick: confirm golden == FP32 (upstream
   says "Flash Player verified").
