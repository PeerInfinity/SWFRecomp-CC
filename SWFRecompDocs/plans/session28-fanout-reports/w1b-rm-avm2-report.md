# s28 w1b-rm-avm2: hidden Flash gaps behind `ruffle_matched` (avm2 / from_avmplus / mixed_avm)

Wave 1, cloud. Branch `fanout/w1b-rm-avm2`. Code base `origin/master` = `a85e0122` (s28 baseline code `7c3cfdcb7` +
docs). Corpus downloaded at upstream Ruffle `d2a801a98` (master on 2026-11-25; one commit past `c2f7d24b7`:
"tests: Remove num_frames"). Graphics mode on lavapipe (`SETUP_STATUS`: Dawn OK).

**New files**
- `SWFRecompDocs/plans/session28-fanout-reports/w1b-rm-avm2-report.md` (this file)
- `SWFRecompDocs/plans/session28-fanout-reports/w1b-rm-avm2-prototype.patch` (`git diff origin/master -- SWFModernRuntime SWFRecomp`; P1–P15)
- `SWFRecompDocs/plans/session28-fanout-reports/w1b-rm-avm2-sort64.patch` (separate, OPTIONAL: 64-bit sort compare; land only together with the `array_sort_swf10_32bit` flash-fix, refutation 2)

## Verdicts (lead)

Scope: the 69 table-A rows under `avm2/`, `from_avmplus/`, `mixed_avm` (trace-provenance: golden = FP32 output, we
print Ruffle's). All 69 were re-run here in graphics mode at `origin/master`: **all 69 are `ruffle_matched` locally**
(identical to CI `e1425f417`). None of the 69 is owned by another s28 slot (the slot-owned rows in the brief are all
`avm1/`/gnash rows), so nothing below is "listed, not worked".

**GO — prototype `w1b-rm-avm2-prototype.patch` (all S): 18 table-A rows `ruffle_matched → pass`, 0 regressions
measured.** 17 of them measured in one frozen sweep of all 69 rows (graphics, `--recompile`): 17 pass / 52 rm, and
the 52 non-flipped rows print **byte-identical** output to `origin/master`; P14 (CDATA) was measured afterwards on its
row. Gates: all 54 `regression/avm2_*` tests pass; 41/41 `as3/Definitions/const*` + `*Const*` pass (P12); suite
neighbours of every touched function pass (listed under Prototype measurement). Optional `sort64` patch: +1 more
(`array_sort_swf10_64bit`) once the `_32bit` golden is flash-fixed.

| # | mechanism (owner) | rows flipped rm → pass | size |
|---|---|---|---|
| P1 | `encodeURI[Component]` SWF≤10 surrogate-pair bug: pair encodes as code point `((lo-0xDC00)<<16)+((hi-0xD800)<<10)` in 1–6-byte UTF-8 plus a stray `%00` (`avm2_globals.c` `uri_encode`) | `avm2/encode_uri_surrogate_pair_swf10`, `from_avmplus/regress/bug_609416_swf10` | S |
| P2 | `drawGraphicsData` GraphicsPath #2004 shows FP's inner `drawPathObject`→`drawPath` frames (`avm2_display.c` `gfx_draw_graphics_data`) | `avm2/graphics_draw_path` (trace; its image fail is pre-existing, flash-fixed PNG) | S |
| P3 | Vector STRING name `"4294967295"` is not an index (#1069 in v10); a NUMBER 4294967295 still is (#1125) (`avm2_vector.c` `vec_name_access_impl`, new `avm2_vector_name_access_rt`; 2 call sites in `avm2_ops.c`) | `avm2/vector_indexing_cutoffs` | S |
| P4 | Interpreted (cinit/script-init) `getproperty` with an int index on an Array ignores the site's ns-set (avmplus `getUintProperty`) (`avm2_ops.c` `getproperty_dyn` array arm) | `avm2/array_access_oob_interpreter` | S |
| P5 | `GroupElement.replaceElements` seeds its text fold with `""` (setElements does not) (`avm2_text.c` `group_text_of`, `ge_replace_elements`, `ge_set_elements`; trailing field on `Avm2ContentElementExt`) | `avm2/groupelement_text` | S |
| P6 | `Date` string parse: `M/D/YYYY` with 1-digit fields, `H:MM`, and `AM`/`PM` (12-hour; `13:30 AM` invalid) (`avm2_date.c` `parse_slash_date`, `parse_hms`, `parse_full_date`) | `from_avmplus/ecma3/Date/e15_9_4_2_1` | S |
| P7 | E4X parser: an attribute value running to EOF is #1095 "Unterminated attribute", not #1090 (`avm2_e4x.c` start-tag attribute loop) | `from_avmplus/as3/RuntimeErrors/Error1095XmlUnterminatedAttr`, `from_avmplus/e4x/XML/misc_errors` | S |
| P8 | `propertyIsEnumerable` on XML (only `"0"`) and XMLList (own indices) (`avm2_globals.c` `object_proto_property_is_enumerable`) | `from_avmplus/e4x/XML/e13_4_4_30`, `from_avmplus/e4x/XMLList/e13_5_4_18` | S |
| P9 | JSON: only a callable `toJSON` is invoked; reviver `undefined` on an ARRAY element leaves a hole; `stringify` prints Numbers with ECMA ToString, not serde's `.0`/`e21` (`avm2_json.c` `js_map_value`, `j_deserialize`, `sb_json_number`) | `from_avmplus/ecma3/JSON/Classes`, `from_avmplus/ecma3/JSON/adhoc` | S |
| P10 | RegExp: PCRE named back-reference `(?P=name)` → `\k<name>` (`avm2_regexp.c` source translation) | `from_avmplus/as3/RegExp/replace` | S |
| P11 | `new ns.foo()` on a Namespace receiver is #1007 (lenient primitive constructprop path) (`avm2_ops.c` `avm2_op_constructprop`) | `from_avmplus/regress/bug_638233` | S |
| P12 | InitProperty of an INHERITED const slot is #1074 (only the declaring class may init it): runtime `initprop_const_ok` in `avm2_ops.c` (both init paths) + recompiler slot-store lever no longer specialises a const store unless `this` is the declaring class (`abc_emit.cpp`, `abc_typemodel.hpp` `InstSlot::decl_inst`) | `from_avmplus/misc/bug_508617` | S |
| P13 | `getCharBoundaries` is `null` in an `embedFonts` field whose font resolved to no embedded face (`avm2_text.c` `txt_get_char_boundaries`) | `avm2/edittext_getcharboundaries_missing_embedded_font` | S |
| P14 | E4X parser: the CDATA keyword is caseless (`<![cdata[`) (`avm2_e4x.c` CDATA arm, `starts_with_ci`) | `from_avmplus/e4x/XML/bug_564468` | S |
| P15 | `getCharBoundaries` is `null` for lines below the first clipped line (never fewer than scrollV..scrollV+1); new `et_first_clipped_line` in `avm2_text.c` | none yet: `edittext_getcharboundaries_culling` 300 → 180 diff lines, scroll-0/1 blocks now exact; residual = lead L1 | S (partial) |

(P9 bundles three one-line JSON fixes. Functions touched in the shared hot files: `avm2_ops.c` `avm2_op_getproperty_dyn` array arm (P4), the two runtime-name vector call sites + `initprop_const_ok` + static/dyn initproperty calls (P3/P12), `avm2_op_constructprop` (P11); `avm2_text.c` `group_text_of`/`ge_*`/`txt_get_char_boundaries`/`txt_get_bottom_scroll_v`; no `tag.c`/`action.c`/`swf.c`/`render_webgpu.c` edits. All AVM2 runtime; no `NO_GRAPHICS`-only code touched, so no no-graphics leg was run.)

**Refutations / premise attacks (first-class):**
1. **The 6 `ecma3/Date/e15_9_5_*` DST rows are not reachable under the graded harness.** Their goldens print
   `GMT-0800`/`GMT-0700` lines: FP32 produced them in a **US-Pacific** host timezone. `verify_output.py` pins
   `TZ=NPT-5:45` (Ruffle's deterministic zone). In NPT even FP32 would print our `GMT+0545` lines (and the tests' own
   US-DST helper would FAIL the same assertions it fails for us). Measured: the same unmodified binary under
   `TZ=America/Los_Angeles` turns `e15_9_5_22_1` into a full **pass** and shrinks the rest
   (28_1 3, 29_1 1, 35_1 3, 10_10 26, 10_11 33 lines). Book them as "Flash golden for a different TZ", not as
   hidden gaps. LOCAL ORACLE REQUEST 1 asks for the FP32 capture under `TZ=NPT-5:45`.
2. **`array_sort_swf10_64bit` is a zero-sum row under today's goldens.** Its SWF is byte-identical
   (`md5 92e25998…`) to `avm2/array_sort_swf10_32bit`'s, which passes today against the 32-bit-Flash golden. FP32 is a
   64-bit player, so it prints the 64-bit golden for BOTH test dirs: **`array_sort_swf10_32bit/output.txt` is a
   flash_fixes candidate** (≠ FP32). With that swap, the 64-bit atom model (below, measured) flips `_64bit` and keeps
   `_32bit`; without it, the model is +1/−1.
3. **`displayobjectcontainer_stopallmovieclips_nonconstructed` is a NO-GO by design**: upstream `test.toml` says the
   SWF *crashes* FP; the "Flash golden" is FP's output up to the crash (ours keeps running 15 more lines). Not a
   gap to close — an ACCEPTED_DIFFS ("Flash crash we don't replicate") candidate.
4. **`ours_diff_count` overstates several rows**: `encode_uri_surrogate_pair_swf10` (15) and `graphics_draw_path` (50)
   are one mechanism each; `number_convert_errors` (706 idx) is 78 missing frame lines, one mechanism.

## Stale dispositions (named)

- `ruffle-tests/tests/swfs/avm2/ignored_tests.txt`, bucket "Upstream known_failure = true" (lines ~148–209): its
  premise "both are `ruffle_matched` here, i.e. already inside effective_pass" is stale for every member that is a
  table-A row (`array_access_oob_interpreter`, `array_sort_swf10_64bit`, `blend_transform`, `bounds_mode`,
  `coerce_to_primitive_side_effects_with_nulls`, `dictionary_weak_keys`, `edittext_device_transform_layout`,
  `edittext_getcharboundaries_culling`, `edittext_getcharboundaries_missing_embedded_font`, `edittext_tab_stops`,
  `encode_uri_surrogate_pair_swf10`, `freestanding_superclass`, `graphics_draw_path`, `int_toexponential`,
  `simplebutton_childevents_multichild`, `simplebutton_childevents_script_order`, `swf_9_goto_in_construct_frame`,
  `uint_toexponential`, `weird_superinterface_properties`): these are Flash goldens we fail. The prune criterion
  (`pass`) still works; the entries are fine as *filters* but must not be read as "accepted".
- `RUFFLE_VS_FLASH_DIFFERENCES.md` "AVM2 `JSON.parse` number grammar": "Not added to `ignored_tests.txt`: the row
  counts as an effective pass" — stale framing; `json_parse_numbers` is a 4-line Flash gap (D2A bucket below).
  The same entry lists `from_avmplus/ecma3/JSON/adhoc` as Flash-aligned: true for the grammar, but adhoc's 5 residual
  lines were three other JSON bugs (P9), now fixed.
- Code comment `avm2_display.c` above `gfx_draw_graphics_data` ("a single drawGraphicsData frame is a subset of FP's
  trace => ruffle_matched") — stale; P2 replaces it.
- `RUFFLE_COMPAT_TWEAKS.md` "Matrix3D.recompose tolerance `1e-2`": still right, but it is NOT what holds
  `matrix3d_recompose_edge_cases` (its 8 lines are NaN propagation in recompose, see table).
- `RUFFLE_COMPAT_TWEAKS.md` "bound methods on String receivers": still accurate (Flash line 2 unexplained); keep.
- Platform entries that are RIGHT (soft rows, Windows FP32 golden): RvF `Number/cos` (Linux libm), RvF line 896–898
  (`soundchannel_soundcomplete` no audio device; `html_text_img_parsing` #2124 vs #2035;
  `uncaught_errors_stringified`). Leave them.

## Buckets by owner mechanism (price, rows, NO-GO + completion)

Rows in **bold** flip in the prototype.

| bucket | owner | rows | price | status |
|---|---|---|---|---|
| A. URI encode SWF≤10 | `avm2_globals.c` `uri_encode` | **encode_uri_surrogate_pair_swf10**, **bug_609416_swf10** | S | GO (P1) |
| B. Native stack-frame spelling | `avm2_display.c`, `avm2_number.c` | **graphics_draw_path**; `number_convert_errors` (int/uint frames: static-type rule — needs recompiler type tracking of `int(x)`/`uint(x)` results and per-class frame names) | S / M | P2 GO; number_convert_errors M |
| C. Property-name/index model | `avm2_vector.c`, `avm2_ops.c` | **vector_indexing_cutoffs**, **array_access_oob_interpreter**; `bug_558863_swf10` (SWF10 `x in ByteArray` throws for non-index x — needs a Flash probe of which names throw, ORACLE 3) | S | P3/P4 GO |
| D. E4X parser/introspection | `avm2_e4x.c`, `avm2_globals.c` | **Error1095XmlUnterminatedAttr**, **misc_errors**, **e13_4_4_30**, **e13_5_4_18**; **bug_564468** (P14: caseless CDATA); `setNotification` (XML notification callbacks for attribute/node changes — M) | S | P7/P8/P14 GO |
| E. JSON | `avm2_json.c` | **JSON/Classes**, **JSON/adhoc** | S | P9 GO |
| F. RegExp source translation | `avm2_regexp.c` | **RegExp/replace**; `bug_479786` (`/^ */gm` must not match after the final `\n` — libregexp multiline `^` at end of input; S–M) | S | P10 GO |
| G. Construct/init semantics | `avm2_ops.c`, `abc_emit.cpp` | **bug_638233**, **bug_508617** | S | P11/P12 GO |
| H. Date parse | `avm2_date.c` | **e15_9_4_2_1** | S | P6 GO |
| I. Date golden TZ (harness) | `verify_output.py` TZ pin | e15_9_5_22_1, 28_1, 29_1, 35_1, 10_10, 10_11 | — | **NO-GO as gaps** (refutation 1). Completion: per-test `tz` override in test.toml + `verify_output.py` (S harness), then: 22_1 passes as-is; 28_1/29_1 need the `setMinutes`/`setUTCMinutes` local→UTC conversion to use the DST of the RESULT time (S–M, real bug masked by NPT); 35_1/10_10/10_11 additionally need Windows FP32's "current US DST rules for historical dates" (soft: Linux FP32 differs) |
| J. avmplus number→string (D2A) | `avm2_number.c` / `avm2_format_number` | int_toexponential (76), uint_toexponential (100), e15_7_4_6_1/swf14 (18), swf15 (3), eregress_121952 (1), number_to_string (104, subnormal 17-digit spellings), json_parse_numbers (4), toStringLimits (1, `(-MIN_VALUE).toString(2)` → `"0"`) | M–L | NO-GO here. Completion: port avmplus `MathUtils::convertDoubleToString` + its D2A exactly (17-digit significant cap with zero fill: `1000000000000000128.toFixed(0)` = `…100`; `toExponential(0)` of 77.1234 = `7e+1` (truncating); plus the SWF<15 bug-513039 `toFixed` arm: `(-0.05).toFixed(0)` = `"-1."`, `(0.00005).toFixed(2)` = `"0.01"` — rule derived, see table). Check against the `number_tostring` Category-14 ACCEPTED_DIFFS entry before touching radix output |
| K. FTE (flash.text.engine) line model | `avm2_text.c` | textblock_line_changes (44), textblock_recreateline (137), textblock_releaselines (4), textline_atom_index_at_char_index (3), **groupelement_text** | S (P5) / M | P5 GO; rest M: TextLine validity/previousLine/nextLine lifecycle on release/recreate; `recreateTextLine` must reset DisplayObject state (blendMode, alpha, parent, filters, …); atoms: a surrogate pair is ONE atom, a GraphicElement occupies one char in the line's raw text (though `GroupElement.text` omits it) |
| L. Classic TextField layout | `avm2_text.c` | edittext_device_transform_layout (20), edittext_tab_stops (6), edittext_getcharboundaries_culling (300: FP nulls lines below the first clipped line — P15 — and keeps scrollV across a height change — L1), edittext_set_text_same_after_edits (48: appendText/replaceText/replaceSelectedText set `defaultTextFormat` from the edit and `text = sameText` sometimes keeps runs), **edittext_getcharboundaries_missing_embedded_font** (P13) | S / M | P13 GO, P15 partial; rest M (text-layout owner; edittext_set_text_same_after_edits needs a format-state model reverse-engineered from its own golden — the golden IS a Flash truth table) |
| M. Frame/event lifecycle ordering | `swf.c`/`avm2_display.c` timeline | loader_events_2 (30), mixed_avm/avm2_loads_avm1_events (18), swf_9_goto_in_construct_frame (12), simplebutton_childevents_multichild (101: SimpleButton state children get frameConstructed/exitFrame), simplebutton_childevents_script_order (4) | M–L | NO-GO here; owner = per-movie display-list / loaded-child tick order (s27 arc §27.4 neighbourhood). Not S |
| N. Type-system representation | runtime-wide | coerce_to_primitive_side_effects_with_nulls (string-null vs object-null atoms), primitive_bound_methods (String closure identity), array_sort_swf10_64bit (64-bit atom compare — S, measured, zero-sum, refutation 2) | L / S | NO-GO for typed nulls (L: a second null kind in `Avm2Value`); 64-bit sort GO only with the 32bit flash-fix |
| O. Verifier / interface traits (hand-assembled ABC) | `avm2_class.c` | freestanding_superclass (`super.hasOwnProperty` on a freestanding superclass yields the Function, we throw #1035), weird_superinterface_properties (interface property copying) | M | NO-GO here; needs an ABC disassembly of both SWFs + avmplus verifier reading |
| P. Debug line info | `abc_emit.cpp` + `avm2_error.c` | event_handler_exception (3: `[Z:\…\Test.as:10]` suffixes from DebugFile/DebugLine) | M | NO-GO here. Completion: emit `act->debug_line = N` at DebugLine (only debug SWFs carry them) + `debug_file` at DebugFile (`;;` → `\`), and print `[file:line]` per frame |
| Q. Misc runtime | various | bounds_mode (6: `transform.pixelBounds` snapping; TextField pixelBounds is 0×0 at its origin), gradient_values_readback (12: angle `45` not `44.9992…`, bevel `strength` 0 readback), matrix3d_recompose_edge_cases (8: NaN propagation into the translation/w column), blend_transform (1: `getPixel` 0x6d vs 0x6c at low quality — render owner), dictionary_weak_keys (1: GC of weak keys), bug_535446 + length_mods (Array natives must read an OVERRIDDEN `length` getter / "array-alikes" length rules — M, 2 rows), e15_1_2_2 (FP `parseInt` radix-32 > 53-bit precision loss — FP's golden says FAILED), bug_539328 (describeType spells a private-namespace interface `::IBar`) | S–M each | not prototyped |
| R. Platform (soft) | — | Number/cos, html_text_img_parsing, soundchannel_soundcomplete, uncaught_errors_stringified, + the 3 Windows-only Date rows in I | — | NO-GO: Windows FP32 goldens; Linux FP32 differs. Leave dispositions |
| S. FP crash | — | displayobjectcontainer_stopallmovieclips_nonconstructed | — | NO-GO (refutation 3) |

## Per-row table (all 69; `diff` = content lines ours vs graded `output.txt`, from local graphics run at `origin/master`)

| row | diff lines (idx) | match | bucket | mechanism | verdict |
|---|---|---|---|---|---|
| `avm2/array_access_oob_interpreter` | 3 | 0/1 | C | `[]["nonpub"::0]` in a cinit: FP (interpreted) → undefined; we throw #1081 | **P4 → pass** |
| `avm2/array_sort_swf10_64bit` | 1 | 0/1 | N | NUMERIC sort SWF<11 compare = int32 truncation of the 64-bit atom difference (FP32 is 64-bit) | S, zero-sum vs `_32bit` (refutation 2) |
| `avm2/blend_transform` | 1 | 0/1 | Q | `getPixel` 0x6d vs 0x6c after a low-quality blend (render rounding) | render owner |
| `avm2/bounds_mode` | 6 | 263/269 | Q | `transform.pixelBounds` snapping (x/y −0.75 → 0) and TextField pixelBounds 0×0 | S–M, needs FP probe |
| `avm2/coerce_to_primitive_side_effects_with_nulls` | 4 | 33/37 | N | toString returning object-null is non-primitive (#1050) vs string-null primitive: typed nulls | L |
| `avm2/dictionary_weak_keys` | 1 | 1/2 | Q | weak-key entries collected after System.gc (count 2 vs 5) | GC model, L |
| `avm2/displayobjectcontainer_stopallmovieclips_nonconstructed` | 15 | 19/19 | S | FP crashes on this SWF; golden is pre-crash output | NO-GO |
| `avm2/edittext_device_transform_layout` | 20 | 268/288 | L | device-font char boxes under a device transform (x 26 vs 12, 41.95 vs 42) | M text layout |
| `avm2/edittext_getcharboundaries_culling` | 300 | 5/305 | L | getCharBoundaries null for lines past the first clipped line (min scrollV+1); + scrollV kept across height change | P15 partial (300→180), lead L1 |
| `avm2/edittext_getcharboundaries_missing_embedded_font` | 3 | 4/7 | L | embedFonts field, font missing: boundaries null | **P13 → pass** |
| `avm2/edittext_set_text_same_after_edits` | 48 | 90/138 | L | appendText/replaceText/replaceSelectedText set defaultTextFormat; `text = same` keeps or resets runs | M |
| `avm2/edittext_tab_stops` | 6 | 54/60 | L | tab-stop advance widths (358.25 vs 286.65) | M text layout |
| `avm2/encode_uri_surrogate_pair_swf10` | 15 | 0/15 | A | SWF≤10 encodeURI surrogate bug + %00 | **P1 → pass** |
| `avm2/event_handler_exception` | 3 | 8/11 | P | `[file:line]` stack-frame suffixes from DebugFile/DebugLine | M |
| `avm2/freestanding_superclass` | 2 | 2/4 | O | `super.hasOwnProperty` on a freestanding superclass returns the method (we #1035) | M, hand ABC |
| `avm2/gradient_values_readback` | 12 | 200/212 | Q | filter readback: angle exact 45, bevel strength 0 | S–M |
| `avm2/graphics_draw_path` | 50 | 51/101 | B | missing drawPath/drawPathObject frames under drawGraphicsData | **P2 → pass** (trace) |
| `avm2/groupelement_text` | 2 | 154/156 | K | replaceElements → "" not null | **P5 → pass** |
| `avm2/html_text_img_parsing` | 95 | 505/600 | R | missing <img> IOErrorEvent #2035 lines (Windows FP32) | soft, platform |
| `avm2/int_toexponential` | 76 | 1139/1215 | J | toExponential digit rounding (avmplus D2A) | M–L |
| `avm2/json_parse_numbers` | 4 | 127/131 | J | DBL_MAX→Infinity, subnormal 17-digit spellings, 270-digit strtod | M–L |
| `avm2/loader_events_2` | 30 | 5/35 | M | loaded child frame-trace interleave order | M–L |
| `avm2/matrix3d_recompose_edge_cases` | 8 | 190/198 | Q | recompose NaN propagation (FP: whole matrix NaN) | S–M |
| `avm2/number_convert_errors` | 706 | 165/871 | B | int/uint toFixed/toPrecision/toExponential outer frames (static type) | M recompiler |
| `avm2/number_to_string` | 104 | 249/353 | J | subnormal shortest-round-trip digits | M–L |
| `avm2/primitive_bound_methods` | 1 | 10/11 | N | `("ab"+"c").AS3::toString === …` true in FP | unexplained (COMPAT_TWEAKS) |
| `avm2/simplebutton_childevents_multichild` | 101 | 51/152 | M | SimpleButton state children get frameConstructed/exitFrame | M |
| `avm2/simplebutton_childevents_script_order` | 4 | 83/87 | M | down-state frame-script order (1 line moved) | M |
| `avm2/soundchannel_soundcomplete` | 10 | 6/16 | R | soundComplete events (Windows FP32; Linux has no device) | soft, platform |
| `avm2/swf_9_goto_in_construct_frame` | 12 | 8/20 | M | SWF9 goto inside construct frame: super/framescript order | M |
| `avm2/textblock_line_changes` | 44 | 437/481 | K | TextLine validity / nextLine after block changes | M |
| `avm2/textblock_recreateline` | 137 | 42/178 | K | recreateTextLine resets DisplayObject state + line chain | M |
| `avm2/textblock_releaselines` | 4 | 748/752 | K | released lines: validity invalid, previousLine null | S–M |
| `avm2/textline_atom_index_at_char_index` | 3 | 37/40 | K | surrogate pair = 1 atom; GraphicElement = 1 char | S–M |
| `avm2/uint_toexponential` | 100 | 1115/1215 | J | toExponential digit rounding (avmplus D2A) | M–L |
| `avm2/uncaught_errors_stringified` | 15 | 3/18 | R | setInterval timer frames + toString-call lines (Windows FP32) | soft; frames part is real (SetIntervalTimer/onTimer, Timer/tick) |
| `avm2/vector_indexing_cutoffs` | 1 | 17/18 | C | string "4294967295" not an index (#1069) | **P3 → pass** |
| `avm2/weird_superinterface_properties` | 1 | 1/2 | O | interface property copying (FP: function) | M, hand ABC |
| `from_avmplus/as3/Array/bug_535446` | 4 | 6/10 | Q | Array natives must use an overridden `length` getter (spoofing) | M |
| `from_avmplus/as3/Array/length_mods` | 5 | 15/20 | Q | push/pop on array-alikes with huge lengths (uint wrap rules) | M |
| `from_avmplus/as3/Math/e15_1_2_2` | 1 | 3/4 | Q | FP parseInt radix 32 loses precision > 53 bits (golden FAILED line) | S–M, needs avmplus source |
| `from_avmplus/as3/RegExp/replace` | 3 | 5/7 | F | (?P=name) named back-reference | **P10 → pass** |
| `from_avmplus/as3/RuntimeErrors/Error1095XmlUnterminatedAttr` | 1 | 0/1 | D | #1095 vs #1090 | **P7 → pass** |
| `from_avmplus/as3/Types/Number/cos` | 1 | 28/29 | R | cos(MAX_VALUE) Windows libm | soft, platform |
| `from_avmplus/as3/Types/Number/e15_7_4_6_1/swf14` | 18 | 11/29 | J | toExponential(0) truncation, SWF<15 toFixed bug 513039, 17-digit fill | M–L |
| `from_avmplus/as3/Types/Number/e15_7_4_6_1/swf15` | 3 | 26/29 | J | toExponential(0) truncation, 17-digit fill | M–L |
| `from_avmplus/e4x/XML/bug_564468` | 4 | 6/10 | D | caseless `<![cdata[` | **P14 → pass** |
| `from_avmplus/e4x/XML/e13_4_4_30` | 3 | 8/11 | D | XML.propertyIsEnumerable("0") | **P8 → pass** |
| `from_avmplus/e4x/XML/misc_errors` | 1 | 32/33 | D | #1095 vs #1090 | **P7 → pass** |
| `from_avmplus/e4x/XML/setNotification` | 13 | 6/19 | D | XML.setNotification callbacks (attribute/node add/change/remove) | M |
| `from_avmplus/e4x/XMLList/e13_5_4_18` | 2 | 3/5 | D | XMLList.propertyIsEnumerable(index) | **P8 → pass** |
| `from_avmplus/ecma3/Date/e15_9_4_2_1` | 2 | 2/4 | H | "1/1/1999 12:30 AM" parse | **P6 → pass** |
| `from_avmplus/ecma3/Date/e15_9_5_10_10` | 31 | 2/33 | I | golden in US-Pacific TZ + current US DST for 1998 (Windows) | NO-GO as gap |
| `from_avmplus/ecma3/Date/e15_9_5_10_11` | 93 | 2/95 | I | golden in US-Pacific TZ + current US DST for 1999 (Windows) | NO-GO as gap |
| `from_avmplus/ecma3/Date/e15_9_5_22_1` | 66 | 2/68 | I | golden in US-Pacific TZ (passes under TZ=America/Los_Angeles) | NO-GO as gap |
| `from_avmplus/ecma3/Date/e15_9_5_28_1` | 3 | 133/136 | I | golden in US-Pacific TZ; + setMinutes DST-of-result bug | NO-GO as gap; real S–M bug |
| `from_avmplus/ecma3/Date/e15_9_5_29_1` | 1 | 118/119 | I | golden in US-Pacific TZ; + setUTCMinutes/getHours DST | NO-GO as gap |
| `from_avmplus/ecma3/Date/e15_9_5_35_1` | 9 | 45/54 | I | golden in US-Pacific TZ + current DST for 1970 (Windows) | NO-GO as gap |
| `from_avmplus/ecma3/JSON/Classes` | 3 | 5/6 | E | non-function toJSON ignored | **P9 → pass** |
| `from_avmplus/ecma3/JSON/adhoc` | 5 | 35/40 | E | reviver hole + Number ToString in stringify | **P9 → pass** |
| `from_avmplus/ecma3/Number/eregress_121952` | 1 | 11/12 | J | toFixed(0) of 1e18+128 → 17-digit fill | M–L |
| `from_avmplus/ecma3/Number/toStringLimits` | 1 | 3/4 | J | (-MIN_VALUE).toString(2) → "0" | S–M; check number_tostring NO-GO |
| `from_avmplus/misc/bug_508617` | 3 | 2/5 | G | subclass InitProperty of inherited const → #1074 | **P12 → pass** |
| `from_avmplus/regress/bug_479786` | 1 | 0/1 | F | /^ */gm: no match at end after final newline | S–M |
| `from_avmplus/regress/bug_539328` | 3 | 12/15 | Q | describeType names private-ns interface `::IBar` | S–M |
| `from_avmplus/regress/bug_558863_swf10` | 1 | 0/1 | C | SWF10 `x in ByteArray` throws for non-index x | S, needs FP probe |
| `from_avmplus/regress/bug_609416_swf10` | 1 | 0/1 | A | SWF10 encode→decode of a surrogate pair throws #1052 | **P1 → pass** |
| `from_avmplus/regress/bug_638233` | 2 | 17/19 | G | `new ns.foo()` → #1007 | **P11 → pass** |
| `mixed_avm/avm2_loads_avm1_events` | 18 | 8/26 | M | AVM1 child frame-trace interleave under an AVM2 loader | M–L |

## Prototype measurement

Before = `origin/master` (`a85e0122`) local graphics run of all 69 rows (all `ruffle_matched`, identical to CI).
After = worktree with the prototype, `--recompile` (P12 changes the recompiler), graphics.

| leg | result |
|---|---|
| 69 table-A rows, P1–P13 frozen | **17 pass / 52 ruffle_matched**; the 52 print byte-identical actual output to the before leg |
| + P14/P15 (then frozen as the shipped patch) | `bug_564468` → pass; `edittext_getcharboundaries_culling` 300 → 180 (still rm); `edittext_device_transform_layout` unchanged (20) |
| `regression/avm2_*` (54) | 54 pass |
| P12 gate `from_avmplus/as3/Definitions/const/*` + `Variable/*Const*` (41, `--recompile`) | 41 pass (all pass at baseline) |
| P1 neighbours | `encode_uri_surrogate_pair_swf11` pass |
| P6 | `avm2/date_parse` pass |
| P7/P14 | `xml_ctor_from_tostring`, `xml_list_ctor_errors`, `xml_duplicate_attribute` pass (the only avm2/avmplus goldens printing #1090) |
| P8 | `avm2/property_is_enumerable` pass |
| P9 | `json_parse`, `json_stringify`, `json_stringify_function`, `json_stringify_order`, `json_version_gated`, `describe_type_json` pass; `json_parse_numbers` output unchanged (rm, D2A) |
| P10 | `regexp_exec`, `regexp_extended` pass |
| P13/P15 | `edittext_getcharboundaries`, `_scroll`, `_missing_glyphs`, `edittext_wrap_breaks`, `edittext_autosize_lazy_bounds_props`, `_vs_relayout` pass |
| sort64 (separate patch) | `array_sort_swf10_64bit` rm → **pass**; `array_sort_swf10_32bit` pass → output_mismatch (prints the 64-bit golden, == FP32); `array_sort`, `array_sorton`, `array_sort_random`, `array_sort_arguments` pass |

Not run: no-graphics (no NO_GRAPHICS-specific code), images (no renderer change), CI `categories=full` — the
coordinator should run the prototype with `categories=full` (it touches AVM2 runtime and recompiler emission).

Flash-fix candidate (for the coordinator, with capture): `avm2/array_sort_swf10_32bit/output.txt` ≠ FP32 (same
SWF as `_64bit`; FP32 is 64-bit). Needs an FP32 run of that test dir to archive (ORACLE 2).

## New unclaimed leads

- **L1 (S–M, +1): `edittext_getcharboundaries_culling`.** With P15 the bottom-cull rule is exact (all 5×60 scroll-0/1
  rows match). The residual 180 lines are the scroll-2..4 blocks: our `scrollV` is reset to 1 by the relayout that
  every `height =` triggers (`avm2_text.c` relayout, `et->scroll = 1;` just after `et->layout = layout;`), while FP
  keeps `scrollV` across a height change. Needs a check of which relayouts FP resets scroll on (text change: yes;
  resize: no) — touch with the text-layout owner, gate on all `edittext_*scroll*` rows.
- **L2 (S): `bug_558863_swf10`** — SWF10 `x in ByteArray` throws for non-natural x (`true`, `"xy"`, `{}`, 5.5, -5).
  Unknown: whether names like `"length"` also throw, and which error. ORACLE 3.
- **L3 (S–M, +2 under a TZ harness): Date `setMinutes`/`setUTCMinutes` DST of the result time** (28_1/29_1 under
  `TZ=America/Los_Angeles`). A real bug hidden by the NPT pin (no DST); only matters if the coordinator adopts a
  per-test TZ (bucket I).
- **L4 (M): `number_convert_errors`** — static-type frames `int/…::toFixed()`: the recompiler knows `int(x)`/`uint(x)`
  results (CallProperty on the global `int`/`uint` class with argc 1) and could emit a framed call.
- **L5 (M): debug line info** for stack traces (bucket P); only `event_handler_exception` and the untestable
  `coerce_property` carry DebugLine goldens in this corpus, so +1 at best.
- **L6: bucket J (avmplus D2A port)** is the biggest single owner in scope: 8 rows (int/uint_toexponential,
  e15_7_4_6_1 swf14+swf15, eregress_121952, number_to_string, json_parse_numbers, toStringLimits). Derived for the SWF<15
  `toFixed` arm (bug 513039, swf14 R-1..R-17): when `|x| < 10^-f` (incl. 0 for f=0) FP rounds on the FIRST
  significant digit only — result is `10^-f` if that digit ≥ 5 else 0, sign kept, and f=0 prints a trailing `.`
  (`(-0.1).toFixed(0)` = `-0.`, `(0.05).toFixed(0)` = `1.`, `(0.00005).toFixed(2)` = `0.01`, `(5e-7).toFixed(2)` = `0.00`).
  This alone does not flip swf14 (Section C and R-18/19 are the 17-digit/truncation arm).

## LOCAL ORACLE REQUESTS

No fixture SWFs are shipped: the cloud box has no AS3 compiler. Requests 1–2 are existing corpus SWFs; 3 needs a
4-line AS3 fixture built locally (source given).

1. **FLASH: `from_avmplus/ecma3/Date/e15_9_5_22_1`, `_28_1`, `_29_1`, `_35_1`, `_10_10`, `_10_11`, trace, direct, with
   the projector's host `TZ=NPT-5:45` (and, for the record, which TZ the trace-provenance capture ran under).**
   Compare with our `origin/master` output. Expectation: FP32 under NPT prints our `GMT+0545` lines and FAILS the same
   assertions we fail → these rows leave the hidden-gap count (refutation 1).
2. **FLASH: `avm2/array_sort_swf10_32bit`, trace, direct, Linux.** Expectation: prints
   `87000000,-273000000,-270000000,287000000,-245000000` (the `_64bit` golden). If so → flash_fixes entry for
   `_32bit/output.txt`, and `w1b-rm-avm2-sort64.patch` becomes a clean +1.
3. **FLASH: ByteArray `in` probe, SWF version 10, trace.** Source (doc class `Test extends Sprite`):
   `var b = new flash.utils.ByteArray(); b[0]=1; b[2]=1; for each (var x in [0,2,3,"1","length","xy",true,5.5,-5,{}]) { try { trace(String(x)+": "+(x in b)); } catch (e) { trace(String(x)+": "+e); } }`
   — also built as SWF 11 for contrast. Decides lead L2 (which names throw, and the error).
