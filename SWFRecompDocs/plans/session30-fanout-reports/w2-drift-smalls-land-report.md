# s30 w2-drift-smalls-land — land w1-drift-smalls A, C, D, E with the FP32 answers

Wave 2 (implementation). Cloud worker, branch `fanout/w2-drift-smalls-land`. Base `origin/master` `6481e7c4`
(code = `2d40d3799` + docs). Upstream Ruffle downloaded at run time (avm1 avm2 from_gnash from_shumway; the drift row
`avm2/xmldocument_tostring` is present, as the brief says for upstream `66f9073de`). `SETUP_STATUS`: apt/Pillow/Dawn
OK. All runs `--mode=graphics --recompile` unless stated. Recompiler rebuilt on both legs.

**NEW files**
- `SWFRecompDocs/plans/session30-fanout-reports/w2-drift-smalls-land-report.md` (this file)
- `SWFRecompDocs/plans/session30-fanout-reports/w2-drift-smalls-land.patch` (`git diff --binary origin/master --
  SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt
  ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md <5 new fixture dirs>`; `git apply --check -R` passes)
- `ruffle-tests/tests/swfs/regression/avm1_tabindex_textfield_v6/`, `_v8/` (from the w1 prototype; FP32 goldens)
- `ruffle-tests/tests/swfs/regression/avm1_tabindex_clip_button_v6/`, `_v8/` (request-1 SWFs; FP32 goldens)
- `ruffle-tests/tests/swfs/regression/avm2_html_img_loadcount/` (request-2 SWF + Test.as; FP32 golden, ONE platform
  line swapped LNX→Windows, see D)

Also modified (doc, inside the patch): `ACCEPTED_DIFFS.md` "Morph fill boundary precision" entry rewritten (E).

## Verdicts (GO, all four land; every headline row improves, no row regresses)

| Item | Verdict | Row | before → after |
|---|---|---|---|
| C tabIndex, all targets | **GO** | `regression/avm1_tabindex_textfield_v6`, `_v8` (new) | mismatch (10 diff lines) → **pass** (graphics + no-graphics) |
| | | `regression/avm1_tabindex_clip_button_v6`, `_v8` (new) | mismatch (18 diff lines) → **pass** (graphics + no-graphics) |
| D `<img>` load count | **GO (land; reaches PASS)** | `avm2/html_text_img_parsing` | **rm 505/600 → pass 600/600** |
| | | `regression/avm2_html_img_loadcount` (new) | mismatch → pass |
| A XMLDocument.toString + traits | **GO, full M completion** | `avm2/xmldocument_tostring` | **mismatch → pass 32/32** (better than the 23/32 the brief priced) |
| E hitTest 71/296 | **GO** | `avm1/movieclip_hittest_shapeflag` | mismatch 6 lines → mismatch 4 lines (171–177, ACCEPTED device font) |

## EXPECTED-FLIP LEDGER (trace axis; pixel axis: no expected moves)

| test | before (s30 baseline) | after |
|---|---|---|
| `avm2/xmldocument_tostring` | output_mismatch | **pass** |
| `avm2/html_text_img_parsing` | ruffle_matched | **pass** (`known_failure = true`: Ruffle prints no #2044; ours now = Flash golden) |
| `avm1/movieclip_hittest_shapeflag` | output_mismatch (6 lines) | output_mismatch (4 lines: 171, 173, 175, 177) |
| `regression/avm1_tabindex_textfield_v6` / `_v8` | (new) | pass, both modes |
| `regression/avm1_tabindex_clip_button_v6` / `_v8` | (new) | pass, both modes |
| `regression/avm2_html_img_loadcount` | (new) | pass |

Net corpus effective: **+1** (`html_text_img_parsing` rm → pass is +1 pass but 0 effective; `xmldocument_tostring`
mismatch → pass is **+1 effective**). Plus 5 regression rows. **Pixel axis:** nothing is expected to move. `path_data`
is read only by the CPU hit tester, and the rest is trace-only. The render canary below is md5-identical. Mouse-input
rows could in principle move through hit-testing (min stroke width, layer flush), but none did in the canary or in
the 46-row hitTest/button family.

## Mechanism and patch scope (every function named)

| file | functions |
|---|---|
| `SWFModernRuntime/src/actionmodern/action.c` | `actionSetMember` (tabIndex block only): null → undefined on all targets (w1); text-field arm: u32 `0xFFFFFFFF` → undefined (w1); **clip/button arm: i32 `-1` → undefined** (new). `actionDelete` (MOVIECLIP arm, tabIndex only): `delete x.tabIndex` → `false`, value kept, on **text fields, clips and buttons** (no `MC_IS_TEXTFIELD` gate). Exception: the untouched root's plain own tabIndex (`g_tab_root_raw`, s29 w2b-tabindex) stays deletable, since it is a real own property |
| `SWFModernRuntime/src/avm2/avm2_xml.c` | new `k_xn_slot_names`, `g_xn_slot_index`, `xn_slot_of`, `xn_add_slot_traits`; `xn_set`/`xn_get` now read and write the slot (dynamic fallback for non-node objects); `avm2_register_xml_legacy` adds 8 XMLNode + 4 XMLDocument instance SLOT traits; `n_xn_has_child_nodes` (`firstChild != null`, w1); new `n_xdoc_to_string` (w1) |
| `SWFModernRuntime/src/avm2/avm2_text.c` | new `html_img_flush_pending_load`; `spans_from_html` (`img` arm + end of parse) |
| `SWFModernRuntime/src/avm2/avm2_display.c` | new `g_html_img_failed_loads`, `avm2_html_img_flush_failed`, `avm2_html_img_load_started`; `avm2_loader_resolve_fetches` (loop condition + flush) (w1, comment updated) |
| `SWFModernRuntime/src/libswf/shape_hit_test.c` | new `g_ht_min_stroke`/`ht_set_min_stroke`; `ng_hitTestPathFill` (cmd 6 layer flush), `ng_hitTestPathStroke`, `ng_hitTestMorphPath` (scale-aware minimum), `ng_hitTestShapeChar` (sets it) (w1, unchanged) |
| `SWFRecomp/src/swf.cpp` | `SWF::interpretShape` (`{6,0,0}` on StateNewStyles) (w1, unchanged) |

No `swf_core.c`/`tag_stubs.c`/`NO_GRAPHICS` arm touched. Siblings: in `action.c` only the `actionSetMember` tabIndex
block and `actionDelete`'s tabIndex arm; nothing in `setupNativeFuncOwnProps` or the native tables.

### C — tabIndex (FP32 request 1)
FP32 `tabindex_clip_button.v{6,8}` (v6 == v8): on a timeline clip, a script clip and a DefineButton2 Button, `-1` →
`undefined`, `-2` and `-2147483648` stay, and `delete` returns `false` and keeps `4`. The rule is the same as for text
fields. On clips the value lives in `dynamic_props` as DONTENUM. The `actionDelete` arm returns before
`deleteProperty`, so that copy survives. Fixture goldens are the archived FP32 files, byte for byte. The 4 new rows
pass in graphics AND no-graphics. Before (clean master, both modes): textfield 10 diff lines, clip_button 18.

### D — `<img>` load count: the rule
FP32 per-case counts (request 2) give one load per `<img src>`, EXCEPT `<img src='a.jpg'><img src='b.jpg'>` with no
text around it, which starts 1. **Derived rule: an image with NO character after it in the parsed text starts no
load.** The next image's placeholder counts as a following character, so `<img a><img b>` → a loads and b does not.
Checks:
- Probe: 14 cases, all match (all others end in text; case 10 → 1).
- Corpus: 98 `<img src>` parses, 3 of them trailing (`<img src='a.jpg'><img src='b.jpg'>`, `<img src='m.jpg'>`,
  `A<img src='m.jpg'>`). 98 − 3 = **95 = the golden**. The golden's own `TEXT=` lines agree: a trailing image keeps no
  placeholder char (`A<img src='m.jpg'>` → `TEXT=A`, `<img src='m.jpg'>` → `TEXT=`).
- Rejected alternatives: "merge adjacent identical images" (−5, and the probe refutes it) and "only the first image
  of a leading run" (does not explain `A<img src='m.jpg'>`).
Implementation: `spans_from_html` keeps one pending image and starts its load when the next placeholder is pushed or
at the end of the parse, if the text grew after it.
- `src=''` platform line: we print `#2035` (Windows FP32, the corpus golden's side); LNX FP32 prints `#2124`. The new
  `regression/avm2_html_img_loadcount` golden is the LNX capture with that ONE line (line 4) swapped to the Windows
  text (README says so). Unswapped, it differs on exactly that line and nowhere else (measured).

### A — XMLDocument.toString + XMLNode fields as instance traits
The 23/32 prototype landed, then the M completion: the 12 public vars are real `AVM2_PROP_SLOT` traits (appended to
XMLNode's ivtable, so XMLDocument and user subclasses inherit them, like the Error class's `name`/`message`). The
bare `nodeName` read inside `CustomXMLNode.toString` now resolves through findpropstrict's trait walk, and the row
**passes 32/32**.
- describeType: `all_classes/xml/swf9` + `swf30` still pass. The vtable SLOT pass now emits the `<variable>`
  elements, and the existing synthetic descriptor rows (`avm2_globals.c` `dt_m_xmlnode`/`dt_m_xmldocument`) skip
  themselves via `dt_members_has`, so their types still come from the table. The `avm2_globals.c` comment ("DESCRIBE-ONLY
  … dynamic") is now stale. I left it unedited to stay in scope; it is a one-line follow-up.
- Provenance of `all_classes/xml/*`: both expected files are byte-identical and their `<variable>` shape matches
  playerglobal's `public var`. Not separately FP32-captured here. Both pass either way.
- for-in over an XMLNode: traits do not enumerate (the Flash/Ruffle model), so a for-in no longer lists
  `nodeName`/… No corpus row enumerates an XMLNode (the 9 flash.xml rows + describe_type_native all pass). There is
  no AS3 compiler in the cloud, so for-in has no fixture. See LOCAL ORACLE REQUESTS (optional).
- Typed-slot coercion (`node.nodeType = "3"` → uint in Flash) is NOT modelled: the slots are untyped (`type_mn = 0`).
  No row probes it.

### E — hitTest 71/296
Landed as measured (recompiler `{6,0,0}` layer marker + scale-aware minimum stroke width), recompiler rebuilt, both
legs `--recompile`: 6 → 4 diff lines. Lines 71 and 296 now match FP32. I rewrote the ACCEPTED_DIFFS "Morph fill boundary
precision" entry as "FIXED s30: stroke minimum width ignored scale (line 296) + lost shape layers (line 71)", updated
the summary-table rows to 0 lines, and updated the category header to 334/338. Lines 171–177 stay ACCEPTED (device-font
outlines). The row stays in `ignored_tests.txt` because of them.

## Per-test before/after (clean origin/master vs patch, same box, graphics, `--recompile`; 140 rows)

Families: tabIndex (56 by name + 5 grep `tabIndex` extras), hitTest/button (46), XML (12), html (2), regression
neighbours `*xml*|*html*|*textfield*|*shape*|*button*` (25). Full table at the end. Summary: after = 131 pass,
5 rm, 4 mismatch. **Status changes = exactly the ledger.** Every other row has the same status, and its diff-line md5
is identical, except one:

- `avm1/global_instance_decls` (mismatch on both legs): the diff differs (1490 vs 1484 lines) on the `new BitmapData`
  instance lines (`instance=[[object Object]]` vs `[undefined]`). **This is nondeterminism, not my patch:** a second
  clean-master run gave md5 `9a5530a8`, the same as the after-leg. Booked under New leads.

Non-pass rows after (all on the s30 baseline lists, unchanged): `global_instance_decls`, `global_proto_decls`,
`global_proto_decls_delete` (mismatch); `movieclip_hittest_shapeflag` (mismatch, ACCEPTED lines);
`movieclip_library_state_values`, `simplebutton_childevents_multichild`, `simplebutton_childevents_script_order`,
`from_gnash/.../HitTest-v8`, `from_gnash/misc-ming.all/ButtonEventsTest` (rm).

No-graphics (the tabIndex rows; `action.c` is shared): the 4 regression rows go before mismatch → after pass.

## Regression suite and canary
- Regression rows in the 140-row set (every `regression/` row in the table: the 9 `avm1_tabindex_*`, 2 hittest,
  `avm2_html_img_loadcount` and the xml/html/textfield/shape/button neighbours): **all pass after**.
- **Render canary** (`render_canary.py capture --recompile`, before/after): **41/41 PNGs IDENTICAL**, 0 trace/image
  status changes. Argued subset of 17 members, not the full 873. Only 148 canary members are downloaded on this box,
  and the change class is hit-test/trace only. The subset covers every downloaded member with `input.json` or
  hitTest/`<img>` in its source (9), plus 8 shape/morph/stroke/mask/text renders that exercise the recompiled
  `path_data`. No member appended to `render_canary_tests.txt` (nothing render-visible to cover).

## Could not finish / follow-ups (each with its mechanism)
- for-in over an XMLNode and the typed-slot coercion of the XML vars: unprobed (no AS3 compiler in the cloud). Mechanism:
  the FLASH request below; if FP32 coerces, give the slots `type_mn`s or setters.
- Stale comments in `avm2_globals.c` (`dt_m_xmlnode` "DESCRIBE-ONLY" note and the `dt_collect_synthetic` header). They
  are doc-only; edit them when that file is next touched.
- `NO_GO_REGISTER.md` §1a / board text that says `html_text_img_parsing` is blocked by the platform line: refuted by w1
  and now landed. Coordinator: strike it at closeout.

## New unclaimed leads
- **`avm1/global_instance_decls` is nondeterministic** on the `_global.flash.display.BitmapData` instance probes
  (`instance=[[object Object]]` in one run, `[undefined]` in another, same binary inputs). Likely an uninitialised read
  or allocation-dependent path in the AVM1 BitmapData constructor (size/argument validation). `runtime_error`-cheap
  triage: run it a few times under `--asan`.
- TextField `delete` of other native props (`text`, `htmlText`, …), carried over from w1. Clips/buttons now have the
  same accessor model for tabIndex. Other native MovieClip props are unprobed.

## LOCAL ORACLE REQUESTS
1. (Optional, low) **FLASH: an AS3 probe** (needs mxmlc; Test.as not provided, 10 lines): `var n:XMLNode = new
   XMLNode(1,"a"); for (var k in n) trace(k); n.nodeType = "3" as *; trace(typeof n.nodeType, n.nodeType); var d =
   new XMLDocument("<a/>"); for (k in d) trace(k);`, trace, direct, 1 tick. Expect: no for-in lines (traits), and
   `number 3` if Flash coerces the typed var.
2. (Optional, low) FLASH: corpus `avm2/xmldocument_tostring`, to confirm golden == FP32 (the upstream commit says "Flash
   Player verified"). We now pass it.

## Full per-test table (before | after; status + matching/expected lines)

| test | before | after |
|---|---|---|
| `avm1/bitmap_data_hittest` | pass 132/132 | pass 132/132 |
| `avm1/bitmapdata_hittest_default_threshold` | pass 4/4 | pass 4/4 |
| `avm1/bitmapdata_hittest_threshold` | pass 6/6 | pass 6/6 |
| `avm1/button_keypress_vs_tab` | pass 20/20 | pass 20/20 |
| `avm1/clone_sprite_edittext` | pass 94/94 | pass 94/94 |
| `avm1/clone_sprite_edittext_dynamic` | pass 86/86 | pass 86/86 |
| `avm1/clone_sprite_types` | pass 24/24 | pass 24/24 |
| `avm1/edittext_focus_selection` | pass 2/2 | pass 2/2 |
| `avm1/edittext_ime_focus_lost` | pass 7/7 | pass 7/7 |
| `avm1/edittext_programmatic_focus` | pass 12/12 | pass 12/12 |
| `avm1/edittext_tab_focus` | pass 13/13 | pass 13/13 |
| `avm1/focus_keyboard_press` | pass 60/60 | pass 60/60 |
| `avm1/focus_mouse` | pass 45/45 | pass 45/45 |
| `avm1/focus_mouse_focusable` | pass 8/8 | pass 8/8 |
| `avm1/focus_mouse_rollout` | pass 4/4 | pass 4/4 |
| `avm1/focus_remove` | pass 33/33 | pass 33/33 |
| `avm1/focus_root_movie` | pass 2/2 | pass 2/2 |
| `avm1/focus_visibility_change` | pass 45/45 | pass 45/45 |
| `avm1/focusrect_focuslost` | pass 4/4 | pass 4/4 |
| `avm1/focusrect_mouse_swf8` | pass 0/0 | pass 0/0 |
| `avm1/focusrect_mouse_swf9` | pass 0/0 | pass 0/0 |
| `avm1/focusrect_property_swf5` | pass 1237/1237 | pass 1237/1237 |
| `avm1/focusrect_property_swf6` | pass 1237/1237 | pass 1237/1237 |
| `avm1/focusrect_property_swf7` | pass 1237/1237 | pass 1237/1237 |
| `avm1/focusrect_swf5` | pass 6/6 | pass 6/6 |
| `avm1/focusrect_swf6` | pass 42/42 | pass 42/42 |
| `avm1/global_instance_decls` | output_mismatch 18/758 | output_mismatch 17/758 |
| `avm1/global_proto_decls` | output_mismatch 62/4562 | output_mismatch 62/4562 |
| `avm1/global_proto_decls_delete` | output_mismatch 461/4158 | output_mismatch 461/4158 |
| `avm1/hittest_lockroot` | pass 15/15 | pass 15/15 |
| `avm1/hittest_morph` | pass 70/70 | pass 70/70 |
| `avm1/hittest_morph_input` | pass 1/1 | pass 1/1 |
| `avm1/hittest_winding_rule` | pass 12/12 | pass 12/12 |
| `avm1/movieclip_default_state` | pass 69/69 | pass 69/69 |
| `avm1/movieclip_focusenabled` | pass 99/99 | pass 99/99 |
| `avm1/movieclip_hittest` | pass 92/92 | pass 92/92 |
| `avm1/movieclip_hittest_shapeflag` | output_mismatch 332/338 | output_mismatch 334/338 |
| `avm1/movieclip_library_state_values` | ruffle_matched 76/78 | ruffle_matched 76/78 |
| `avm1/movieclip_state_values` | pass 114/114 | pass 114/114 |
| `avm1/tab_ordering_automatic_basic` | pass 92/92 | pass 92/92 |
| `avm1/tab_ordering_automatic_order_grid` | pass 21/21 | pass 21/21 |
| `avm1/tab_ordering_automatic_order_same_position` | pass 12/12 | pass 12/12 |
| `avm1/tab_ordering_children` | pass 208/208 | pass 208/208 |
| `avm1/tab_ordering_custom_basic` | pass 71/71 | pass 71/71 |
| `avm1/tab_ordering_custom_duplicate_index` | pass 22/22 | pass 22/22 |
| `avm1/tab_ordering_custom_i32_vs_u32` | pass 12/12 | pass 12/12 |
| `avm1/tab_ordering_custom_m1` | pass 29/29 | pass 29/29 |
| `avm1/tab_ordering_events` | pass 150/150 | pass 150/150 |
| `avm1/tab_ordering_events_mouse` | pass 65/65 | pass 65/65 |
| `avm1/tab_ordering_movieclip_enabled_default` | pass 462/462 | pass 462/462 |
| `avm1/tab_ordering_properties` | pass 293/293 | pass 293/293 |
| `avm1/tab_ordering_properties_tab_index_edge_case` | pass 4/4 | pass 4/4 |
| `avm1/tab_ordering_reverse` | pass 51/51 | pass 51/51 |
| `avm1/tab_ordering_tabbable` | pass 47/47 | pass 47/47 |
| `avm1/textfield_props_swf5` | pass 175/175 | pass 175/175 |
| `avm1/textfield_props_swf6` | pass 210/210 | pass 210/210 |
| `avm1/textfield_props_swf7` | pass 210/210 | pass 210/210 |
| `avm1/textfield_props_swf8` | pass 210/210 | pass 210/210 |
| `avm1/xml_clone_expandos` | pass 19/19 | pass 19/19 |
| `avm2/all_classes/xml/swf30` | pass 116/116 | pass 116/116 |
| `avm2/all_classes/xml/swf9` | pass 116/116 | pass 116/116 |
| `avm2/bitmapdata_hittest` | pass 112/112 | pass 112/112 |
| `avm2/bitmapdata_hittest_threshold` | pass 18/18 | pass 18/18 |
| `avm2/button_hittest` | pass 2/2 | pass 2/2 |
| `avm2/describe_type_native` | pass 23/23 | pass 23/23 |
| `avm2/displayobject_hittestobject` | pass 32/32 | pass 32/32 |
| `avm2/displayobject_hittestpoint` | pass 49/49 | pass 49/49 |
| `avm2/displayobject_hittestpoint_boundary` | pass 65/65 | pass 65/65 |
| `avm2/displayobject_hittestpoint_root` | pass 13/13 | pass 13/13 |
| `avm2/displayobject_scrollrect` | pass 33/33 | pass 33/33 |
| `avm2/flash_xml` | pass 29/29 | pass 29/29 |
| `avm2/flash_xml_cloneNode` | pass 22/22 | pass 22/22 |
| `avm2/flash_xml_namespace` | pass 109/109 | pass 109/109 |
| `avm2/flash_xml_removeNode` | pass 60/60 | pass 60/60 |
| `avm2/focus_events_mouse_basic` | pass 260/260 | pass 260/260 |
| `avm2/focus_events_mouse_focusable` | pass 112/112 | pass 112/112 |
| `avm2/focus_events_mouse_same_object` | pass 40/40 | pass 40/40 |
| `avm2/hit_test_scroll_rect` | pass 99/99 | pass 99/99 |
| `avm2/hittest_morph` | pass 30/30 | pass 30/30 |
| `avm2/html_text_img_parsing` | ruffle_matched 505/600 | pass 600/600 |
| `avm2/mouse_pick_scroll_rect_button` | pass 5/5 | pass 5/5 |
| `avm2/movieclip_hittest` | pass 67/67 | pass 67/67 |
| `avm2/simplebutton_added_to_stage` | pass 45/45 | pass 45/45 |
| `avm2/simplebutton_childevents` | pass 86/86 | pass 86/86 |
| `avm2/simplebutton_childevents_multichild` | ruffle_matched 51/152 | ruffle_matched 51/152 |
| `avm2/simplebutton_childevents_nested` | pass 54/54 | pass 54/54 |
| `avm2/simplebutton_childevents_script_order` | ruffle_matched 83/87 | ruffle_matched 83/87 |
| `avm2/simplebutton_childevents_sprite` | pass 13/13 | pass 13/13 |
| `avm2/simplebutton_childprops` | pass 144/144 | pass 144/144 |
| `avm2/simplebutton_childshuffle` | pass 23/23 | pass 23/23 |
| `avm2/simplebutton_constr` | pass 36/36 | pass 36/36 |
| `avm2/simplebutton_constr_childevents` | pass 48/48 | pass 48/48 |
| `avm2/simplebutton_constr_params` | pass 42/42 | pass 42/42 |
| `avm2/simplebutton_mouseenabled` | pass 26/26 | pass 26/26 |
| `avm2/simplebutton_multi_children` | pass 19/19 | pass 19/19 |
| `avm2/simplebutton_soundtransform` | pass 887/887 | pass 887/887 |
| `avm2/simplebutton_structure` | pass 27/27 | pass 27/27 |
| `avm2/simplebutton_symbolclass` | pass 68/68 | pass 68/68 |
| `avm2/xml_ignore_white` | pass 6/6 | pass 6/6 |
| `avm2/xml_namespace_methods` | pass 245/245 | pass 245/245 |
| `avm2/xmldocument` | pass 254/254 | pass 254/254 |
| `avm2/xmldocument_tostring` | output_mismatch 4/32 | pass 32/32 |
| `avm2/xmlnode` | pass 3540/3540 | pass 3540/3540 |
| `from_gnash/actionscript.all/HitTest-v6` | pass 88/88 | pass 88/88 |
| `from_gnash/actionscript.all/HitTest-v7` | pass 88/88 | pass 88/88 |
| `from_gnash/actionscript.all/HitTest-v8` | ruffle_matched 85/88 | ruffle_matched 85/88 |
| `from_gnash/actionscript.all/MovieClip-v5` | pass 363/363 | pass 363/363 |
| `from_gnash/misc-ming.all/ButtonEventsTest` | ruffle_matched 666/679 | ruffle_matched 666/679 |
| `from_shumway/hittesting/hittesting` | pass 18/18 | pass 18/18 |
| `regression/avm1_attached_clip_button_click` | pass 13/13 | pass 13/13 |
| `regression/avm1_browser_gated_textfield` | pass 7/7 | pass 7/7 |
| `regression/avm1_button_pick_order` | pass 9/9 | pass 9/9 |
| `regression/avm1_button_textfield_path_binding` | pass 4/4 | pass 4/4 |
| `regression/avm1_edittext_html_delete_runs` | pass 4/4 | pass 4/4 |
| `regression/avm1_edittext_html_typed_runs` | pass 3/3 | pass 3/3 |
| `regression/avm1_hittest_hairline` | pass 28/28 | pass 28/28 |
| `regression/avm1_hittest_shape_stale_matrix` | pass 28/28 | pass 28/28 |
| `regression/avm1_mc_button_unified_pick` | pass 21/21 | pass 21/21 |
| `regression/avm1_tabindex_child_null` | pass 3/3 | pass 3/3 |
| `regression/avm1_tabindex_clip_button_v6` | output_mismatch 19/28 | pass 28/28 |
| `regression/avm1_tabindex_clip_button_v8` | output_mismatch 19/28 | pass 28/28 |
| `regression/avm1_tabindex_fn2_root_raw` | pass 4/4 | pass 4/4 |
| `regression/avm1_tabindex_fresh_child_coerce` | pass 4/4 | pass 4/4 |
| `regression/avm1_tabindex_mtasc_class_main` | pass 6/6 | pass 6/6 |
| `regression/avm1_tabindex_read_first_coerce` | pass 5/5 | pass 5/5 |
| `regression/avm1_tabindex_textfield_v6` | output_mismatch 8/13 | pass 13/13 |
| `regression/avm1_tabindex_textfield_v8` | output_mismatch 8/13 | pass 13/13 |
| `regression/avm1_textfield_attached_depth_order` | pass 1/1 | pass 1/1 |
| `regression/avm1_textfield_ctor_shadow_swf6` | pass 2/2 | pass 2/2 |
| `regression/avm1_textfield_ctor_shadow_swf7` | pass 2/2 | pass 2/2 |
| `regression/avm1_textfield_x_bounds_offset` | pass 10/10 | pass 10/10 |
| `regression/avm1_xml_first_action_proto` | pass 2/2 | pass 2/2 |
| `regression/avm1_xmlnode_first_action_proto` | pass 2/2 | pass 2/2 |
| `regression/avm2_bitmapdata_draw_textfield` | pass 5/5 | pass 5/5 |
| `regression/avm2_child_simplebutton` | pass 10/10 | pass 10/10 |
| `regression/avm2_group_alpha_shadow_shape_a50` | pass 0/0 | pass 0/0 |
| `regression/avm2_html_img_loadcount` | output_mismatch 1/39 | pass 39/39 |
| `regression/avm2_simplebutton_click` | pass 2/2 | pass 2/2 |
| `regression/group_alpha_shadow_shape_a50` | pass 0/0 | pass 0/0 |
| `regression/xml_onload_type1_args` | pass 3/3 | pass 3/3 |
