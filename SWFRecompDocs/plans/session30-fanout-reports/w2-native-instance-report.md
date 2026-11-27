# s30 w2-native-instance — AVM1 native INSTANCE layout (XML/XMLNode, filters, ColorTransform, hidden instance slots)

Slot `w2-native-instance`, wave 2 (implementation). Base `origin/master` `6481e7c4` (code = s30 baseline `2d40d3799`
+ docs). Upstream corpus: Ruffle master **`66f9073de`** (downloaded 2026-11-27: avm1, from_gnash, then avm2, visual,
from_shumway, fonts, text for the canary). Box: SETUP_STATUS all OK (apt, Pillow, Dawn). Trace work; every headline
row was run in BOTH modes.

**New files (all on this branch):**
- `SWFRecompDocs/plans/session30-fanout-reports/w2-native-instance-report.md` (this file)
- `SWFRecompDocs/plans/session30-fanout-reports/w2-native-instance.patch` (= `git diff origin/master -- SWFRecomp
  SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`; only
  `SWFModernRuntime/src/actionmodern/action.c` changes)
- `SWFRecompDocs/plans/session30-fanout-reports/w2-native-instance-fixture/avm1_native_instance_layout/`
  `{create_test_swf.py, test.swf, test.toml, output.provisional.txt, output.before.txt}`: a regression fixture
  **awaiting a Flash golden** (LOCAL ORACLE REQUEST 1). It is deliberately NOT under `regression/` yet.
- `SWFRecompDocs/plans/session30-fanout-reports/w2-native-instance-gen/{sweep_graphics.tsv, sweep_nographics.tsv,
  sweep_list.txt}`: the guard sweep, per row.

No new `.c`/`.h` file, no recompiler change, no `verify_output.py` change, no canary-list change.
The fixture is NOT in the patch on purpose: it has no Flash golden yet. The patch was proven with
`git apply --check -R` against this branch's tree.

**Functions touched (all in `action.c`):** new `static` `xml_is_native_slot_name`, `xml_obj_has_native_slots`,
`avm1_native_type_hides_proto_slots`, `avm1EnumHideMask`, `avm1EnumHidesOwnSlot`, `avm1XmlOwnSlotIsNative`. Edited:
`builtin_object_hasOwnProperty`, `builtin_object_isPropertyEnumerable`, `ei_toXML_buf`, `ei_objectToXML_buf`,
`colorTransformConstructor`, `xml_create_node`, `xml_install_construct_proto_props`, `initXMLPrototype`,
`xml_create_document`, `actionEnumerate` (object walk), `actionEnumerate2` (OBJECT arm only), `actionSetMember`
(ColorTransform coercion + XML read-only no-op, both beside the existing filter/XML coercion hooks), `actionDelete`
(tail), `actionNewObject` (named `XMLNode` arm; generic ctor path: XML alias + native-alias dispatch),
`invokeNativeSuperConstructor` (XML arm: own `contentType` dropped). None in `swf_core.c`, `tag_stubs.c`, `tag.c`,
`swf.c` or `action_queue.c`, and no `#ifdef NO_GRAPHICS` arm.

## 0. Verdicts and priced flips (lead)

| item | verdict |
|---|---|
| gnash `ExternalInterface-v8` (rm, 1 check `ExternalInterface.as:265`) | **GO, FLIPS rm → pass** in both modes (6 → 0 diff lines vs the FP32 golden). |
| XML / XMLNode instance layout (task 1) | **GO, landed.** Node fields are invisible own storage behind enumerable XMLNode.prototype placeholders; XML.prototype members in FP32 for..in order, all enumerable; no own `contentType`; `idMap` hidden. |
| Hidden instance `__proto__` / `__constructor__` (L4, task 2) | **GO, landed, but the brief's premise is REFUTED in part:** FP32 does NOT hide them on every instance. It hides them only on native-backed instances (20 classes, §2.2). AS-implemented classes (Matrix, Point, Rectangle, BitmapFilter, ...) and plain objects list them, with `__proto__` DONT_DELETE. Both halves are implemented. |
| Filter instance defaults (L5, task 3) | **GO, landed; premise REFUTED as stated.** `new GlowFilter()` already had FP32 defaults. The `undefined` values in `global_instance_decls` come from the test's ALIASED construction (`var clazz = eval(name); new clazz()`), which skipped every native initialiser. Fixed for filters, FileReference(List) and XML. Filter members are also no longer own. |
| Instance DONT_DELETE + ColorTransform accessors (task 4) | **GO, cheap parts landed:** ColorTransform slot order + Number coercion on write + not-own; `delete` of XML node fields refused; `new X()` `__proto__` DONT_DELETE. |
| Second generator input (task 5) | **NO-GO (not needed).** Every instance fact we could match is a mechanism (alias ctor, hidden slot, coercion), not a table row. The remaining instance residue is either the prototype table (sibling `w2-native-table-land`) or unimplemented natives (§4). |
| `global_instance_decls` TZ line | **HOLD, capture TZ not uniquely known.** The golden prints `GMT+0200` on 2020-04-04. That fits CEST (e.g. Europe/Berlin, `CET-1CEST,M3.5.0,M10.5.0/3`) and also any no-DST +2 zone (Africa/Johannesburg, Africa/Cairo in 2020). Completion: the coordinator picks one (only one Date line is printed, so any of them closes the line) or asks the golden's author. No toml edit made. |
| Guard sweep: 180 rows × 2 modes | **0 losses, 1 move** (`ExternalInterface-v8` rm → pass), identical in graphics and no-graphics (§3). |

### EXPECTED-FLIP LEDGER (what CI must show after this patch, vs baseline `45938113471` / `45938116102`)
- **Trace axis, both modes:** `from_gnash/actionscript.all/ExternalInterface-v8`: `ruffle_matched → pass`.
  Nothing else changes status in the 180-row guard set. `avm1/global_instance_decls`, `avm1/global_proto_decls`,
  `avm1/global_proto_decls_delete` and gnash `argstest-v6/v7/v8` stay `output_mismatch` but move Flash-ward (§1).
- **Pixel axis:** none. The change touches no render code. Canary result is in §3.2.

## 1. Per-test before/after (same box; before = clean `origin/master`, after = this patch)

Diff lines = `diff <FP32 golden> <ours> | grep -c '^[<>]'`. The golden is `output.txt`, or `output.fp32.txt` for
argstest (its graded subtest). Graphics and no-graphics give byte-identical outputs on all 7 rows.

| row | status before → after | diff lines before → after |
|---|---|---|
| gnash `ExternalInterface-v8` | rm → **pass** | 6 → **0** |
| `avm1/global_instance_decls` | mm → mm | 1073 → **616** |
| `avm1/global_proto_decls` | mm → mm | 2593 → **2578** |
| `avm1/global_proto_decls_delete` | mm → mm | 2215 → **2198** |
| gnash `argstest-v6` (fp32) | mm → mm | 2208 → **2131** |
| gnash `argstest-v7` (fp32) | mm → mm | 2209 → **2136** |
| gnash `argstest-v8` (fp32) | mm → mm | 2238 → **2199** |

The measured intermediate states are kept so each mechanism has a price (`global_instance_decls`):
XML layout + EI 1073 → 997; + aliased XML/filter/FileReference ctor 917; + filter / ColorTransform not-own 779;
+ ColorTransform order and coercion 763; + XML READ_ONLY fields and parsed-node native type 718; + `new X()`
`__proto__` DONT_DELETE 640; + XMLNode.prototype getter READ_ONLY and the `__x__` bookkeeping-slot hide 616.

One intermediate state cost lines and was fixed: enumerable XMLNode.prototype placeholders first made
`global_proto_decls` **+7** (2593 → 2600), because the placeholders lacked READ_ONLY. Marking the 11 getter-only
placeholders READ_ONLY turned that into −15.

## 2. Mechanism, by task (owner `SWFModernRuntime/src/actionmodern/action.c`; every function named)

### 2.1 XML / XMLNode instance layout (task 1) → `ExternalInterface-v8`
FP32 `_objectToXML` is player AS code: `for (var prop in object) result += ... _toXML(object[prop])`. Ruffle ships the
same AS (`core/src/avm1/globals/flash/external/ExternalInterface.as`). So the check is a for..in of `new XML()`.
FP32 lists the XMLNode.prototype getters, then the XMLNode methods, then XML.prototype. Before the patch it failed
on four mechanisms:
1. **`ei_objectToXML_buf` walked OWN slots only.** It now walks the for..in chain with the same rules as
   `actionEnumerate2` (own, then `__proto__`, inherited `constructor` skipped, hidden slots skipped). It emits the
   names in for..in order and reads each value through `actionGetMember`, so accessors (`XML.status`, `.loaded`) run
   with this = obj.
2. **Node fields were own enumerable instance slots.** They stay as the storage, but every own-slot observer now
   treats them as absent on a node object: `nodeType nodeName nodeValue parentNode firstChild lastChild
   previousSibling nextSibling childNodes attributes prefix localName namespaceURI idMap __xml_status __xml_loaded
   __realChildren`. Reads and writes are unchanged. New `static` helpers: `xml_is_native_slot_name`,
   `xml_obj_has_native_slots`, `avm1XmlOwnSlotIsNative`. Hooked into `actionEnumerate2` (OBJECT arm),
   `actionEnumerate` (object walk, non-MC only), `builtin_object_hasOwnProperty`,
   `builtin_object_isPropertyEnumerable`, `actionDelete` (returns false, keeps the storage) and the EI walker.
3. **Prototype order and enumerability** (`initXMLPrototype`, `xml_install_construct_proto_props`). XMLNode.prototype
   now has the methods `cloneNode … getPrefixForNamespace`, then placeholders `attributes … namespaceURI`, all
   ENUMERABLE; the 11 getter-only placeholders are READ_ONLY, `nodeName`/`nodeValue` stay writable. XML.prototype has
   `createElement … addRequestHeader`, then construct-time `contentType docTypeDecl ignoreWhite loaded status
   xmlDecl`, all ENUMERABLE. Insertion order is the reverse of FP32's for..in order, because our for..in yields the
   newest slot first.
4. **Own `contentType` on the document** (`xml_create_document`, `invokeNativeSuperConstructor` XML arm): removed.
   It inherits from XML.prototype, as in FP32.
5. **`attributes` serialises as `<null/>` in FP32.** The AS `_toXML` tests `value == null` first, and the
   prototype-less attributes object compares equal to null. `ei_toXML_buf` now returns `<null/>` for an object with no
   reachable `valueOf`.

Also: `actionSetMember` makes writes of `nodeType/prefix/localName/namespaceURI` to a node a no-op (FP32 READ_ONLY,
`global_instance_decls`). `xml_create_node` stamps `NATIVE_XMLNODE` on every runtime-built node (parse, createElement,
createTextNode, cloneNode). The `new XMLNode()` arm of `actionNewObject` resets it for < 2 args, which keeps the
existing "native only with 2+ args" rule and its FP32-listed `__proto__`.

### 2.2 Hidden `__proto__` / `__constructor__` (L4) — premise attacked
`global_instance_decls` (FP32) lists `__proto__, own, DONT_DELETE` + `__constructor__, own` on 41 of 80 sections:
TextSnapshot, automation, ExternalInterface, FileReferenceList, Matrix/Point/Rectangle, BitmapFilter,
PolicyFileResolver, Product, Video, Error, ContextMenu(Item), SharedObject, Microphone, Camera, NetStream, Color,
AsBroadcaster, XMLSocket, MovieClip, Function, Object, and the no-arg `new XMLNode()`. FP32 lists neither on the
native-backed ones: PrintJob, MovieClipLoader, LocalConnection, FileReference, ColorTransform, the 9 concrete filters,
BitmapData, TextFormat, TextField, Button, LoadVars, XML, XMLNode(type, value) and parsed nodes, Sound, String, Date,
Boolean, Number.
- `avm1_native_type_hides_proto_slots` / `avm1EnumHideMask` / `avm1EnumHidesOwnSlot`: for..in skips `__proto__`,
  `__constructor__` and our own `__name__` bookkeeping slots (e.g. Sound `__sound_use_global__`) on objects whose
  `native_type` is in that set. ASSetPropFlags cannot unhide them.
- `actionDelete`: `delete o.__proto__` returns false when `o` has an own `__constructor__` (the mark of a
  `new`-built object). Object literals are untouched. `avm1/object_prototypes` (which deletes some `o.__proto__`)
  still passes.
- Not covered: `new Array()` (ARRAY arm, owned by sibling `w2-array-forin-proto`) and NetConnection (no native type
  in our runtime). Both are 2–3 lines each in `global_instance_decls`.

### 2.3 Filter "defaults" (L5) — premise refuted, real cause = aliased native construction
`new flash.filters.GlowFilter()` already initialised FP32 defaults (it goes through `actionNewMethod` →
`invokeNativeSuperConstructor`). The test builds every instance as `var clazz = eval(className); new clazz()`. That is
`actionNewObject` with name `"clazz"`, whose generic path dispatched native initialisation on the variable NAME. So
filters, FileReference(List) and XML got a bare object. This is a real Flash-visible bug for any SWF that aliases a
native class. Fix (`actionNewObject`, generic ctor path):
- a native-stub alias (function with a name, no body) dispatches on `ctor_func->name`, and runs the filter
  initialiser (`invokeNativeSuperConstructor`), FileReference/FileReferenceList listeners and the existing
  Sound/LoadVars/… native types;
- `ctor_func == &g_xml_constructor` builds a real XML document, same as the named arm.

Filter and ColorTransform member slots are the storage behind FP32's prototype accessors, so `avm1XmlOwnSlotIsNative`
also reports a filter/ColorTransform slot that shadows a prototype member as not-own (hasOwnProperty /
isPropertyEnumerable / delete).

### 2.4 ColorTransform (task 4)
`colorTransformConstructor`: slot order is alphaMultiplier, red/green/blueMultiplier, alphaOffset,
red/green/blueOffset (the FP32 for..in order). `actionSetMember`: a non-number write to any of the 8 members is
coerced with `varToDoubleSWF`, so FP32 shows them READ_ONLY (`ct.redMultiplier = "x"` reads back a Number).

## 3. Guards

### 3.1 Trace guard sweep (180 rows, both modes)
Set: the 76-row w1 sweep, plus every row that constructs the natives touched here. avm1: all 35 `xml*`, `bitmap_filters`,
`color_transform`, `bitmap_data_colortransform`, `bitmapdata_applyfilter_colormatrix`,
`displacementmapfilter_mappoint_throw_error`, the 4 `external_interface_*`, `loadvars_tostring`,
`localconnection_xml`, `delete`, `delete2`, `instanceof_coercions`, `primitive_instanceof`,
`swf5_xml_event_handler_context`, `file_reference_listeners_per_instance`, `sound_load_multiple_instances`,
`conflicting_instance_names`, the 3 decls rows. gnash: `ColorTransform/ExternalInterface/Instance/LoadVars-v5..8`,
`XML/XMLNode-v5..7`, `XMLSocket-v8`, `argstest-v5..8`, `delete-v5..7`, `Sound-v5..7`, `Date/String/Boolean/Number-v6`,
`Object-v5/v7`, `enumerate-v5..7`. regression: `avm1_runtime_filters`, `avm1_filter_list_overflow`,
`avm1_applyfilter_glow`, `avm1_dynclip_color_transform`, `xml_onload_type1_args`, `avm1_root_onload_proto`, plus
the w1 four.

The before column is CI's committed baseline (`results_graphics.json` / `results.json` at `2d40d3799`). The w1
report showed that local before-legs equal it on this family. The after column is local.

| mode | pass→pass | rm→rm | mm→mm | moves |
|---|---|---|---|---|
| graphics | 157 | 15 | 7 | **1: `ExternalInterface-v8` rm → pass** |
| no-graphics | 157 | 15 | 7 | **1: same** |

The 7 mm→mm rows are the 6 owned rows of §1 plus `avm1/globals_monkeypatch` (49/306 matching lines in both legs, unchanged). The 15 rm→rm rows keep their matching-line counts. They are `Date-v6/v8`, `LoadVars-v6/v7/v8`, `Math-v8`, `Object-v6/v7/v8`, `Sound-v5`, `Stage-v8`, `TextField-v8`, `XML-v5/v8`, `array-v8`. Per-row TSVs are in `w2-native-instance-gen/`.
The regression-suite members (10 rows) are all pass → pass in both modes.

### 3.2 Graphics render canary
`ruffle-tests/render_canary.py capture` over the full standing list (`render_canary_tests.txt`, 203 tests / 268
comparisons, `--jobs 2 --timeout 5400`). Before = clean `origin/master` (patch reverted), after = this patch:
**IDENTICAL 268, DIFFERS 0, APPEARED/VANISHED/NO_RENDER 0; trace status changes: none; image status changes: none.**
The change class is the AVM1 object model, not rendering, so no canary member was added.

## 4. What is left in the owned rows (named, with owners)
- `global_instance_decls` 616 lines. The biggest buckets: `type=[function with prototype]` vs `function` on
  prototype methods (≈ 470 diff lines, ≈ 235 members; prototype table, sibling `w2-native-table-land`); prototype getters we do not have
  for PrintJob (5), TextFormat (20), TextField (35), FileReference (8), Button (8), BitmapData's aliased build (28 +
  29); Date/String/Number/Boolean instances whose prototype methods enumerate in ours (≈ 45; prototype DONT_ENUM =
  table); `new Array()` hidden slots (ARRAY arm sibling); instance header text (`toString` of
  `[type Object]`/`Error`/`false`/`0` on aliased builds, 11); 1 TZ line.
- `global_proto_decls(_delete)`: the prototype table (sibling), plus XML.prototype getter VALUES read with
  this = XML.prototype (FP32 `""`/`null`/`1`, ours `undefined`; FP32's XML.prototype is itself an XML node, a
  1-object identity change).
- argstest: instance `constructor` enumeration position + version gating (w1 report §1.4), unchanged here.

## 5. Refutations
1. **"FP32 never lists instance `__proto__`/`__constructor__`" (L4)**: refuted. FP32 lists both, with `__proto__`
   DONT_DELETE, on 41 of 80 sections, and hides them only on native-backed instances. Implemented as that split.
2. **"`new XFilter()` has `undefined` defaults" (L5)**: refuted. Named construction already had the FP32 defaults.
   The `undefined`s come from aliased construction, a general `actionNewObject` bug that also broke
   `var C = XML; new C(src)` (it parsed nothing) and FileReference. Fixed at the cause.
3. **"XML node fields must become prototype getters" (brief task 1)**: not needed for any observable. Hiding the
   own storage from the five own-slot observers yields the FP32 layout with no change to the ~40 internal readers
   (`getProperty(node, "firstChild")` etc.). The guard (35 avm1 `xml*` rows + gnash XML/XMLNode v5..8) holds.
4. **"The `attributes` mismatch is our value"**: no. FP32's `<null/>` is the AS `_toXML`'s `value == null` test on a
   prototype-less object, not a null `attributes`. `typeof new XML().attributes` stays `object` (FP32
   `global_instance_decls` agrees).

## 6. Sibling interaction / landing notes
- `w2-native-table-land` (prototype table, `ensureGlobalInit`): it rewrites flags and order on XML/XMLNode.prototype
  too. The two agree: this patch sets the same FP32 order and flags in `initXMLPrototype`, and the table pass runs
  after it. The only textual neighbour is `initXMLPrototype`. If the table lands first and edits that function, this
  patch's hunk there needs a manual 3-way merge (method order block + placeholder block).
- `w2-array-forin-proto` (ARRAY arm of `actionEnumerate2`): this patch edits only the OBJECT arm (top of the
  function), which is a separate hunk.
- `w2-drift-smalls-land` (tabIndex): no overlap.

## 7. New unclaimed leads
- **L-a (S): `new Array()` instance `__proto__`/`__constructor__`** are listed by for..in after ASSetPropFlags (FP32:
  hidden). Belongs in the ARRAY arm (sibling's function): reuse `avm1EnumHidesOwnSlot` with
  `AVM1_HIDE_PROTO_SLOTS` on `arr->props`.
- **L-b (S–M): XML.prototype is an XML node in FP32** (its getters read `""`/`null`/`1` with this = XML.prototype,
  `global_proto_decls` 3053–3065). Make XML.prototype a real document node.
- **L-c (M): aliased construction for the remaining named-only natives** (`TextField`, `TextFormat`, `Color`,
  `TextSnapshot`, `NetConnection`, `Transform`, `Date`, `Error`, the primitive wrappers): the named arms of
  `actionNewObject` run only when the NAME matches. The same `ctor_func->name` dispatch would serve all of them.
  `global_instance_decls` shows it for String/Boolean/Number/Error (instance text `[object Object]` vs FP32
  `""`/`false`/`0`/`Error`) and BitmapData's 4-arg aliased build (`n=28/0`).

## LOCAL ORACLE REQUESTS
1. **FLASH, trace, direct, 1 frame (SWF8): `w2-native-instance-fixture/avm1_native_instance_layout/test.swf`**
   (generator next to it, hand-assembled with `regression/_lib/avm1asm.py`). Compare against
   `output.provisional.txt` (ours, after the patch). Expected FP32 differences we already predict: the last line
   should be `sound for-in after unhide: []` (FP32's `Sound.prototype.checkPolicyFile` is DONT_ENUM; that is the
   prototype table, not this patch). If FP32 agrees elsewhere, the coordinator moves the fixture to
   `ruffle-tests/tests/swfs/regression/avm1_native_instance_layout/` with the FP32 capture as `output.txt`.
2. **None other.** The TZ decision (§0) needs no capture.
