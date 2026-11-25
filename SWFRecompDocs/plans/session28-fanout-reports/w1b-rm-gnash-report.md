# s28 w1b-rm-gnash: hidden Flash gaps behind gnash `ruffle_matched` rows

Wave 1, cloud worker. Base `origin/master` `a85e0122` (code = s28 baseline `7c3cfdcb7` lineage). Upstream gnash
mirror downloaded 2026-11-25 (`download_tests.sh from_gnash`, then `avm1` for the sweep; 404 + avm1 tests installed;
flash-fixes APPLIED 2). Graphics mode on cloud lavapipe; no-graphics for the AVM1 runtime legs. Dawn/apt: OK.

**New files** (all under `session28-fanout-reports/`):
- `w1b-rm-gnash-report.md` (this file)
- `w1b-rm-gnash-prototype.patch` (`git diff origin/master -- SWFModernRuntime`)
- `w1b-rm-gnash-fixtures/avm1_gnash_flash_probes/` (`create_test_swf.py`, `avm1asm.py` copied from w1-leads,
  `test.swf` (SWF8), `test_v6.swf`, `test_v5.swf`, `test.toml`, `output.ours-prototype.txt`): Flash-oracle probes for
  the HOLD buckets below.

## Verdicts (lead)

**GO (wave 2): 5 S mechanisms, measured, +16 `ruffle_matched → pass` (graphics AND no-graphics), 0 regressions on the
gate.** Every flip is a real Flash gain: each graded golden is FP32 output (trace-provenance table A).

| # | mechanism (owner) | flips (measured) | size |
|---|---|---|---|
| B1 | XML node `nodeName`/`nodeValue` are mutually exclusive (writing one nulls the other); a null-named element still serializes its attributes (`action.c` new `xml_name_value_exclusive_after_set`, called from `actionSetMember` general arm and the with-scope arm of `actionSetVariable`; new `xml_serialize_attrs` split out of `xml_serialize_node`, also called on the null-name path) | `XMLNode-v5`, `XMLNode-v6`, `XMLNode-v7`, `XMLNode-v8`, `XML-v6`, `XML-v7` (**6**) | S |
| B2 | `with` nesting is capped at 13; the 14th `ActionWith` skips its body (`action.c` `actionWithStart`) | `with-v5` (**1**; needed by v6-v8) | S |
| B3 | a `with(mc)` SetVariable does not treat mc's display-list children as mc properties (`action.c` `actionSetVariable` scope loop) | with B2: `with-v6`, `with-v7`, `with-v8` (**3**) | S |
| B4 | `String.prototype.valueOf` is its own native: ToString(this) for every non-String receiver (`action.c` new `builtin_string_proto_valueOf` / `stringValueOfFunc`, installed on both String.prototype init sites) | `toString_valueOf-v6`, `-v7`, `-v8` (**3**) | S |
| B5 | SWF6+ `"".split(nonEmptySep, limit<=0)` returns `[""]` (`action.c` `actionCallMethod` STRING `split` arm) | `String-v6`, `String-v7`, `String-v8` (**3**) | S |

**HOLD (needs the Flash oracle; probes shipped):** B10 `Selection.setSelection` arg-count rule (3 rows), B11 NaN
identity + `"" < "0"` (4 rows), plus confirmation probes for B1/B2/B4 semantics beyond what the gnash goldens pin.

**NO-GO / priced, not worked (completion mechanism named per bucket in §Buckets):** 70 rows across 20 mechanisms; the
cheapest remaining real flips are B6 (SWF5 hides Function.prototype from function objects: `Object-v5`, `Number-v5`
likely flip, M) and B19 (`Global-v6`, hidden inherited setter still called on SetMember, S-M, 1 row).

**Listed, owned by other s28 slots (not worked):** `misc-ming.all/place_object_test`, `place_object_test2`,
`path_format_test` (w2-occupied-depth); `misc-ming.all/action_order/action_execution_order_test`,
`action_execution_order_test4`, `action_execution_order_test6`, `misc-swfc.all/action_execution_order_test10`
(§27.4 interleave NO-GO / w1-test12-enterframe). `misc-ming.all/loop/loop_test10` I ran and list under B20 (it is not
`test10` of the brief's exclusion, but its asOrder/instance-naming residual is the same action-order family; treat
as owned by that family). `HitTest-v6..8` (and probably `DrawingApiTest`) are the w2-hittest-shape-stale /
w1-leads item-1 mechanism (see B13): listed, not worked.

## Disposition audit (brief task 1)

- **Stale (written on the belief the golden was Gnash- or Ruffle-made):**
  - `from_gnash/_investigation/ACCEPTED_DIFFS.md` **Math-v5..v8** ("Gnash Implementation Bugs in Expected Output",
    `pow(1)`, `SQRT2`). The golden is **Windows FP32**; Linux FP32 equals `output.ruffle.txt` (trace-provenance). The
    entry's conclusion (keep our IEEE behaviour) still stands, but its reason is wrong: it is a **platform split**
    (Windows CRT `pow`/printf), not a Gnash bug. Re-word under the RvF "Platform splits" bullet that already lists it.
  - same file, **ops-v8** ("NaN equality bit-pattern differences … Gnash's test platform"). Stale: FP32 on Linux
    x86-64 prints this golden byte for byte, and all four `ops-v5..v8` rows carry it. Flash's NaN distinctions are
    reproducible on our platform; this is a real gap (B11), not platform UB.
  - same file, **Inheritance-v5..v8** §1a ("Gnash's recorded expected output simply stops"). The golden is FP32; the
    conclusion ("Flash hangs") stands (Ruffle wiki "Flash Player Oddities": cyclic `instanceof` hangs on frame 2+),
    but the line Flash never printed is a hang, not a Gnash artifact. §1b (super-chain re-entry) is a real Flash gap
    (B17), not "matches Ruffle, fine".
- **Still right:** RvF "Platform splits" bullet for `ASnative-v5..8`, `MovieClip-v8` blendMode, `TextFormat-v8`,
  `MovieClipLoader-v7/8`, `Microphone-v6..8` (Windows FP32 golden). But note for ASnative and MovieClipLoader the
  platform part is 5 / 3-18 lines while our diff is 35-40 / 118 lines: most of it is a real gap (B16).
- avm1 `ACCEPTED_DIFFS.md` `native_objects_swf6` mentions `toString_valueOf-v6` only as a constraint; B4 does not
  touch `new TextField()` and keeps that constraint.
- `ignored_tests.txt` gnash entries for LoadVars/ExternalInterface comments do not name these rows; nothing to update.

## Buckets by owner mechanism (98 rows run: 105 table-A gnash rows minus the 7 owned by other slots)

"diff" = our content diff vs the graded golden, `-golden/+ours` lines, measured at base (graphics). Flip = full row.

### Prototyped (GO): B1-B5 (16 flips, table above)

Per-row before → after (graphics; no-graphics identical):

| row | before diff | after |
|---|---|---|
| `actionscript.all/XMLNode-v5..v8` | -3/+3 (`nodeValue` after a text node is renamed: Flash null) | **pass** ×4 |
| `actionscript.all/XML-v6`, `-v7` | -3/+3 (Flash prints `FAILED … obtained:  tna1=…` at XML.as:494: `nodeValue = 4` on TOPNODE erased its name) | **pass** ×2 |
| `actionscript.all/XML-v5` | -10/+10 | -9/+9 (B7: SWF5 nbsp byte at :1037 + the SWF5 BOM/codepage load at :881/882/898, which runs twice) |
| `actionscript.all/XML-v8` | -3/+24 | -0/+21 (Flash's golden has no gnash.xml onLoad block at all: oracle question, below) |
| `actionscript.all/with-v5` | -3/+3 | **pass** |
| `actionscript.all/with-v6..v8` | -6/+6 | **pass** ×3 |
| `actionscript.all/toString_valueOf-v6..v8` | -5/+5 | **pass** ×3 |
| `actionscript.all/toString_valueOf-v5` | -34/+34 | unchanged count (residual is B6) |
| `actionscript.all/String-v6..v8` | -9/+9 | **pass** ×3 |
| `actionscript.all/String-v5` | -18/+18 | unchanged (B6 + B7) |

Mechanism evidence (gnash sources: `git.savannah.gnu.org/cgit/gnash.git/plain/testsuite/actionscript.all/*.as`):
- B1: XMLNode.as:76-83 `textnode.nodeName = "foo"` → FP32 `nodeName == "foo"` PASS, `nodeValue` **null**, then
  `nodeValue = "bar"` → "bar". XML.as:381 (inside `with(TOPNODE)`) `nodeValue = 4`, and at :494 FP32's
  `tmp.toString()` is ` tna1="tna1val" … </SUBNODE2>`: no `<TOPNODE`, no `</TOPNODE>`, attributes kept. Model:
  name and value share exclusivity; a null-named element serializes like the document node but keeps its attributes.
  Prototype only nulls the counterpart when it is an own non-null value; `nodeType` is left alone (probe P1 asks).
- B2: with.as:566-625 (18 nested `with`, "There are 13 levels for all versions!"), FP32 `withs == "abcdefghijklm"`.
  Overflow pushes a NULL marker so `actionWithEnd` stays balanced. Count = consecutive `scope_is_with` entries above
  the nearest function scope (captured closure scopes are counted too; probe P2 asks how Flash counts in a function).
- B3: with.as:516-543. Our MC child back-reference lives in `mc->dynamic_props`, so `child = "rootChild"` inside
  `with(mc)` overwrote it. FP32: lands on `_root`, `typeof(mc.child) == 'movieclip'`, `child._target == "/mc/child"`.
- B4: toString_valueOf.as:186-196 `svo()` → "_level0", `f.vo()` → "[type Function]", `new Boolean(false).vo()` →
  "false" (string). Before, `String.prototype.valueOf` shared `builtin_wrapper_valueOf` with Number/Boolean (returns
  the boxed primitive or undefined). String wrappers and the bare `String.prototype` keep the old path.
- B5: String.as:318-326, 555-565, 592-596 (SWF6+ branches).

Prototype caveats for wave 2: B4 reads `g_call_this_type == FUNCTION` to detect a Function receiver (the type-2
own-method dispatch passes `own_props` as `this_obj`); that global is saved/restored around calls but should be
replaced by an explicit receiver-type check in the implementation. B1 adds a nodeType probe on every `nodeName` /
`nodeValue` SetMember (only those two names).

### HOLD (oracle first)

- **B10 `Selection.setSelection` argument count** (`action.c` `builtin_selection_setSelection`). `Selection-v6..v8`
  (3 rows, 5 asserts each, all this mechanism): FP32 keeps (2,6) after `setSelection(3)` and (1,1) after
  `setSelection(1,2,3)`; ours applies Ruffle's "a, then INT_MAX" rule. I measured "ignore unless exactly 2 args": it
  flips all 3 rows **but breaks `avm1/selection`** (setSelection(0) on a freshly focused field with begin = -1 must
  give 0/15/15; with the no-op we print 0/0/0; that golden has a `.fla` and is not `known_failure`). Reverted. A
  model that fits both (e.g. "1 arg applies only when there is no current selection", "≥3 args no-op") is
  speculative: probe P3. Price: S once the rule is known, 3 flips.
- **B11 NaN identity in `==` + `"" < "0"`** (`ops-v5..v8`, 4 rows, 7 lines each, two mechanisms). FP32: `NaN == NaN`
  true, but `"abc"*0 != NaN`, `Number(new Number(NaN)) != NaN != 0/0`, `--"a" != NaN`; Flash compares Number values
  by bit pattern and its NaN producers differ in payload/sign. We treat every NaN as equal. Separately FP32 says
  `("" < "0")` is false. Ruffle fails the same lines. Probe P4 (11 NaN producers, full `==` matrix) and P5. Price M
  (arithmetic must stop canonicalizing NaN where Flash doesn't); 4 flips if both mechanisms land.
  Our probe output (`output.ours-prototype.txt`, P4) shows our `==` is **already bit-pattern based** (`0/0` and
  `Math.sqrt(-1)` differ from `NaN`); what we lack is Flash's payloads for ToNumber failures (`"abc"*0`, `--"a"`) and
  for `Number(new Number(NaN))`, which we make identical to the `NaN` global. P4 also shows a bug of ours:
  `parseInt("x")` read twice from one variable is **not equal to itself** (`pint=false` on the diagonal).

### NO-GO / priced (not worked)

| bucket | mechanism (likely owner) | rows (diff) | flips if fixed | size | completion mechanism |
|---|---|---|---|---|---|
| B6 | SWF5: function objects' `__proto__` is SWF6-flagged, so Function.prototype (and `toString`/`valueOf`/`constructor` lookups through it) is invisible, and a function converts to primitive `undefined` (`fn == undefined` true) (`action.c` GetMember FUNCTION arm + ToPrimitive) | `Object-v5` (-3/+3, sole), `Number-v5` (-8/+8, likely sole), `Function-v5` (-10/+10), `toString_valueOf-v5` (-34/+34, most), `MovieClip-v5` (1 of 11), `String-v5` (3 of 18), `TextField-v5` (-3/+3, `TextField.prototype` SWF6-flagged; related) | 2 (Object-v5, Number-v5), up to 4 with TextField-v5/Function-v5 | M | implement the SWF6 visibility flag on function `__proto__` + `ASSetPropFlags(Object,null,8,129)` unhide (Object.as:33-37); gate on SWF5 avm1 corpus (`object_string_coerce_swf5`, `string_methods_swfv5`, …) |
| B7 | SWF5 strings are byte strings: literals/trace pass bytes through (we cp1252-decode in the recompiler `escape_c_string`), `ord`/`chr` work on bytes, SWF5 `XML.load` decodes the file as cp1252 (BOM becomes a text node) | `String-v5` (5 lines), `XML-v5` (4 lines after B1), `ASnative-v5` (2 lines) | 0 standalone; `XML-v5` flips with B1+B7 | M-L | trace-output codepage model for SWF5 (recompiler `escape_c_string` + `actionTrace`); BOM/codepage in `xml_parse_into` for SWF5. Cross-suite risk: avm1 SWF5 goldens with high bytes |
| B8 | `loadVariables` always calls `this.meth` to get the method (MovieClip.as:2251-2305) | `MovieClip-v5..v8` (8-12 lines each) | 0 standalone (each row has other mechanisms) | S | `actionLoadVariables`: `GetMember(this,"meth")` + call |
| B9 | MovieClip misc: `_width` setter resets a negative `_yscale` sign (v6-8 :1520-1529), blendMode invalid writes (v8 :2376-2384), `toString` after `__constructor__` swap (:2596), `loadVariables` delivery `_root.var1` (:2209) | `MovieClip-v6`, `-v7` (-20/+20), `-v8` (-25/+25) | 2-3 only with B8 + all of B9 | M | four separate fixes; v8 blendMode lines are a Windows-platform split per RvF |
| B12 | `watch` + `addProperty` interplay: addProperty on a watched missing prop fires the watcher, the watcher's return becomes the getter/setter's underlying value (Object.as:790-840) | `Object-v6..v8` (-8/+8 each) | 3 | M | `addProperty` / watch trigger path in `action.c` |
| B13 | shape-flag `hitTest` uses the render-time (stale) matrix after `_x`/`_width`/`_xscale` changes in the same frame (HitTest.as:55-80, 120-145) | `HitTest-v6`, `-v7` (-8/+8), `-v8` (-9/+9); maybe `DrawingApiTest` (-1/+1, Flash false at a curve-edge point) | 3-4 | M | **owned by w2-hittest-shape-stale** (per-clip render-time matrix snapshot); w1-leads item 1 probe `avm1_hittest_root_stale_matrix` is the oracle. Measure these rows on that patch |
| B14 | device/embedded font metrics: `getTextExtent`, `textWidth`, ascent/descent (Windows fonts on v8) | `TextFormat-v7` (-38/+38), `TextFormat-v8` (-36/+36, Windows), `EmbeddedFontTest` (-27/+27, embedded advances ~7% narrow) | 0-1 | L | font metric model; EmbeddedFontTest may be a DefineFont3 advance-scale bug (cheaper, unverified) |
| B15 | TextSnapshot selection API (`setSelected`, `getSelected`, `getSelectedText`, `getTextRunInfo`) | `misc-ming.all/TextSnapshotTest` (-81/+81) | 1 | M-L | implement the static-text snapshot model |
| B16 | device/platform rows with real gaps underneath: `ASnative` table coverage (Date/Stage/SharedObject/… natives by id), `MovieClipLoader.loadClip` of local MEDIA files (no onLoadStart/Progress/Complete/Init at all), `Microphone.get()` object | `ASnative-v5..v8` (-35..40), `MovieClipLoader-v7/v8` (-118/+0), `Microphone-v6..v8` (-31/+31) | 0 vs Linux FP32 (Windows goldens); Microphone: we may already match Linux (no device) | L | ASnative id table; MovieClipLoader local load path; Microphone stays a platform disposition |
| B16b | `Math-v5..v8` (-5/+5) | — | 0 | — | platform split (Linux FP32 == ours). Disposition reason is stale (above); no code |
| B17 | `Inheritance-v5` (+1: cyclic `instanceof` on frame 2+ hangs Flash; golden is truncated at the hang), `Inheritance-v6..v8` (super-chain re-entry, `FAAC`/`FFFC`/`undefinedFFC`) | v5 (-0/+1), v6 (-8/+9), v7/v8 (-4/+5) | v5: only by replicating a hang (NO-GO); v6-8: M-L | — | v5: NO-GO (do not replicate a hang; keep ACCEPTED_DIFFS 1a). v6-8: `super` must re-resolve through the receiver's live chain (Inheritance.as:250-340) |
| B18 | LoadVars: second `load()` issued from inside `onLoad` returns false and the run stops before the summary; `loaded` must not be an own prop (LoadVars.as:139, 183, 197) | `LoadVars-v6..v8` (-6/+2) | 3 | M | `LoadVars.load` reentrancy in the deferred-load queue (w2-avm1-leads-land touches `avm1FireFormDataEvents`: coordinate) |
| B19 | SetMember calls an inherited setter even when that property is version-hidden (flags 256 / 1024) and does not clear the flag (Global.as:250-286) | `Global-v6` (-9/+9) | 1 | S-M | setter walk in `actionSetMember` / `setPropertyChainWithSetter` must not skip hidden props |
| B20a | `array`: `c.length == 3` (array.as:444), `a.length == 4` (:1394), for-in order of an array with `sort`/`length` own props (:1628-1636) | `array-v5` (-5/+5), `-v6` (-6/+6), `-v7`, `-v8` (-5/+5) | 4 | M | three mechanisms; enumeration order is the shared one |
| B20b | `setProperty` on a clip from inside `tellTarget`/`with`: our run loses 10 checks (`Tests run 36 (expected 46)`) | `setProperty-v5..v8` (-15..16/+6..7) | 4 | M | find the aborted block (`this == _root.mc1` at :40 never prints) |
| B20c | `Sound` bound by target path: unload → `getVolume()` undefined, rebind to the new same-named clip at volume 100 (SWF5) | `Sound-v5` (-14/+14) | 1 | M | Sound target as a path reference |
| B20d | `BitmapData.draw` edge pixels (`near(bm, 23..26, 15, …)`) | `BitmapData-v8` (-8/+8) | 1 | M | rasterizer AA at a 2-colour edge |
| B20e | `ExternalInterface._toXML` of an XMLNode, `_toAS` of a function | `ExternalInterface-v8` (-4/+4) | 1 | S | two serializer arms |
| B20f | `Transform-v8`: Flash FAILs 2 colorTransform toString lines we pass, and `mc2` keeps `_xscale 100`/`_rotation 1.5` after a matrix write | `Transform-v8` (-7/+7) | 1 | S-M | read Transform.as:160-177 |
| B20g | misc-ming / misc-swfc / misc-mtasc singletons: `callFunction_test` (-6/+6, CallFunction on `mc1:func` paths), `displaylist_depths_test` (-7/+7, depth 1048576 / -30000), `_test2`/`_test3` (-7/+7, static clip onClipConstruct order), `duplicate_movie_clip_test` (-4/+4, duplicating a button), `InitActionTest` (-4/+4, init action order 3 before 2), `LoadBitmapTest` (-2/+2, JPEG `transparent` false, `typeof(d)`), `loop_test6` (-4/+4), `loop_test7` (-1/+0, missing `movieClip1 unloaded`), `loop_test10` (-20/+16), `matrix_test` (-5/+5, `_rotation` 90°/-90° matrix not exact: Flash snaps sin/cos), `registerClassTest2` (-6/+6, onLoad order), `replace_buttons1test` (-3/+3), `levels` (-15/+15, `_level16394` mapping of negative depths), `gotoFrameFromInterval`, `…2` (-3/+3, timer floor; arc §28 lead: 10 ms floor needs a full-corpus A/B), `movieclip_destruction_test1` (-12/+12), `registerclass_test3` (-12/+12), `zeroframe_definesprite` (-2/+2, zero-frame sprite frame counters) | 1 each | S-M each | individually small but each needs its own diagnosis; cheapest looking: `LoadBitmapTest`, `matrix_test`, `zeroframe_definesprite`, `loop_test7` |

## Refutations / premise attacks

- "15 within 3 lines": the line-index count (`ours_diff_count`) overstates and understates. E.g. `XML-v8` is 3 by
  index but our content diff is +24 (an extra onLoad block Flash never printed); `MovieClipLoader-v7` is 118 lines
  *missing*, not changed. `Inheritance-v5` (1 line) is the cheapest by count and is a NO-GO (a hang).
- A 1-assert family is not a 1-mechanism family: `with-v6..v8` needed two mechanisms (B2+B3); `XML-v5` needs three.
- `Selection` looked like the cleanest S (one rule, 3 rows) and is refuted by a Flash-authored avm1 golden; HOLD.

## Gates run

- Owned rows, graphics, before: 98/98 still `ruffle_matched` at base (no drift).
- Prototype, graphics: 16 flips above; 0 other moves on the 20 B-family rows run.
- Prototype, no-graphics (B1-B5 rows + v5 siblings, 20 rows): identical to graphics (16 pass, 4 `ruffle_matched`).
- `regression` suite, argued subset near the change (20: scope/with/closure/resolve/XML/valueOf/coerce/string):
  `avm1_bare_mc_method_scope`, `avm1_closure_method_scope`, `avm1_mc_resolve`, `avm1_resolve_dotted_getvariable`,
  `avm1_type2_mc_receiver_dispatch`, `avm1_xml_first_action_proto`, `avm1_xmlnode_first_action_proto`,
  `avm1_watch_long_name`, `avm1_edittext_path_variable_scope`, `avm1_edittext_path_variable_same_frame`,
  `coerce_cross_swf_version`, `coerce_type1_args`, `convertfloat_type1_this`, `string_prim_method_type1_args`,
  `xml_onload_type1_args`, `resolve_type1_args`, `avm1_swf6_case_insensitive_builtins`, `lv_cross_swf_version`,
  `ei_closure_scope_order`, `ei_mc_this_receiver`: **20/20 pass**.
- avm1 sweep (22, all `pass` at baseline): `with`, `with_return`, `with_variable_scopes`, `define_local_with_paths`,
  `string_methods`, `string_methods_negative_args`, `string_methods_swfv5`, `string_ops_swf6`, `string_coercion`,
  `object_string_coerce_swf5`, `object_string_coerce_swf6`, `xml`, `xml_to_string`, `xml_inspect_parsexml`,
  `xml_inspect_createmethods`, `xml_attributes_read`, `xml_clone_expandos`, `xmlnode_proto`, `xml_reparenting`,
  `xml_namespaces`, `swf5_xml_event_handler_context`, `loadvars_tostring`: **22/22 pass**.
- Not run: the full `regression` suite (≈1 h on 4 CPU) and full CI. Wave 2 must run the CI `full` categories
  (AVM1 runtime change) in graphics + no-graphics.

## Wave-2 patch scope (B1-B5)

`SWFModernRuntime/src/actionmodern/action.c` only. Functions touched: new `xml_name_value_exclusive_after_set`,
new `xml_serialize_attrs` (body moved out of `xml_serialize_node`), `xml_serialize_node`, `actionSetMember` (the
general ASObject arm, one call after `setProperty`), `actionSetVariable` (with-scope arm: one call after
`setProperty`; display-child skip before the `prop_struct` handling), `actionWithStart`, new
`builtin_string_proto_valueOf` / `stringValueOfFunc`, the two String.prototype `valueOf` install sites
(global init near `g_ctors[2]` and the lazy `g_string_constructor` init), `actionCallMethod` STRING `split` arm.
Sibling overlap: w2-avm1-leads-land and w2-hittest-shape-stale also edit `action.c` but none of these functions.
Each arm needs a `regression/` fixture with a Flash golden: the probe SWF below covers B1/B2/B4.

## New unclaimed leads

- B6 (SWF5 function prototype visibility): 2 likely flips, M, with a clear source pin (Object.as:33-37).
- B19 `Global-v6`: 1 row, all 7 asserts one mechanism, S-M.
- B20e `ExternalInterface-v8`, B20g `LoadBitmapTest`, `zeroframe_definesprite`, `loop_test7`: 1-row S candidates.
- B8 `loadVariables` → `this.meth`: S, unlocks MovieClip-v5..v8 only together with B6/B9.
- `parseInt("x") == parseInt("x")` (same variable) is false in our runtime (probe P4 diagonal). Every other NaN
  producer equals itself. Cheap to find (likely an F32/F64 tag mismatch on parseInt's NaN return in `Equals2`).
- XML-v8: our run delivers gnash.xml's onLoad where FP32 printed nothing. Either FP32 never loaded the file in the
  capture window or SWF8 local-load policy refuses it; one oracle run with a longer cap decides.

## LOCAL ORACLE REQUESTS

1. **FLASH: `session28-fanout-reports/w1b-rm-gnash-fixtures/avm1_gnash_flash_probes/test.swf` (SWF8), `test_v6.swf`,
   `test_v5.swf`; trace, 2 frames, direct pinned.** Built by `create_test_swf.py <out.swf> <version>`. Compare against
   `output.ours-prototype.txt` (our SWF8 output with the prototype). Sections:
   - P1: XMLNode name/value exclusivity and whether `nodeType` changes (decides B1's model; B1 is GO either way for
     the gnash rows).
   - P2: `with` depth at frame level, inside DefineFunction and DefineFunction2 (decides B2's counting rule).
   - P3: `Selection.setSelection` with 1/2/3 args from fresh focus and from an existing selection (decides B10).
   - P4: `==` matrix over 11 NaN producers (`NaN`, a pushed NaN literal, `0/0`, `"abc"*0`, `Number("a")`,
     `Math.sqrt(-1)`, `parseInt("x")`, `Number(new Number(NaN))`, `--"a"`, `undefined+1`, `NaN` again) (B11).
   - P5: `"" < "0"`, `"" < "a"`, `"0" < ""`, `"a" < "b"`, `"" < ""`, `"" < " "` (B11).
   - P6: `String.prototype.valueOf` on Number/Boolean/Object/String/function/_root receivers and bare call (B4).
   If any P1/P2/P4/P6 line differs between the SWF versions, please run all three.
2. **FLASH: `from_gnash/actionscript.all/XML-v8` (corpus test), trace, direct pinned, `--max-duration 20`.** Does FP32
   ever print the `gnash.xml successfully loaded` block (XML.as:835-900) that `XML-v6/v7` goldens contain? Decides
   whether our extra 21 lines are a load-policy gap or a capture-window artifact.
