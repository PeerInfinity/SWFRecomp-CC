# w1-avm1-tail: AVM1 + gnash/shumway trace tail (session 24, wave 1)

**New files on this branch**
- this report
- `w1-avm1-tail-prototype.patch` (236 lines, `git diff origin/master -- SWFModernRuntime SWFRecomp`; touches 2 runtime files, `action.c` and `avm1_amf.c`). It applies cleanly to `df126b80`. The source is reverted, so this commit holds only report files.
- `w1-avm1-tail-probe/`:
  - `mkl1.py`: the L1 assembler, which writes `l1_nested_filters.swf`.
  - `l1_nested_filters.ours.txt`: our trace.
  - `l1_nested_filters.predicted_flash.txt`: my prediction, **not** an oracle.
  - `scan_nested_filters.py`: a corpus scanner for sprite-nested PlaceObject3 filter lists.
  - `mktfx.py`: the TextFormat `hasOwnProperty` probe.

**Environment**
- Cloud box, and `SETUP_STATUS` is all OK.
- Tests come from upstream Ruffle master **`bcac30c19`** (`download_tests.sh avm1 from_gnash from_shumway`, plus `visual timeline swf` for the L1 scan). The Ruffle source is a blobless clone at the same SHA.
- The baseline is `_results/*/results_graphics.json` at `ff2e2e9d6` (run `44965247383`).
- Every run is a single test, `--mode=graphics --verbose`, at most `-P 2`. The 5 headline flips were also run with no graphics.

---

## 0. Verdicts and priced flips (ranked GO list for wave 2)

| Rank | Slot | Rows | Verdict | Flips | Cost | Evidence |
|---|---|---|---|---|---|---|
| **1** | **AMF/LC tail (land the prototype directly)** | `avm1/amf0_array_matrix`, `avm1/localconnection_serialize_sparse_array_getters`, `avm1/localconnection_xml_unavailable` | **GO S** | **+3 pass** | S (prototyped) | Each row goes from 49/50, 25/26 and 9/23 to **PASS** in both modes. The 35-row AMF/LC/NC/SO/addProperty sweep and the 24-row LC/XML sweep are clean. |
| **2** | **Deferred loads: `LoadVars.sendAndLoad` + `StyleSheet.load` (same patch)** | `avm1/load_vars`, `avm1/stylesheet_load` | **GO S** | **+2 pass** (both rows are on the ignore list today: prune them) | S (prototyped) | 29/35 → **PASS** and 1/49 → **PASS** in both modes. The 13-row sendAndLoad sweep, the 16-row stylesheet/LoadVars sweep and 10 `regression/` rows are clean. |
| 3 | `avm1/text_format_get_text_extent_own` (new upstream row) | 1 | **GO M, coordinate with w1-native-proto** | +1 | M | Mechanism is in §3. One sub-mechanism (`own=undefined`) is unexplained, but a repro pointer is given. |
| 4 | `avm1/sandbox_type_remote` | 1 (+ the avm2 twin, same 1/3 shape, not measured) | HOLD M | +1..2 | M | Two mechanisms: a `http://localhost:8000/X` → `<test>/localhost/X` child-SWF mapping, and a per-movie sandbox type. Not prototyped. |
| 5 | **L1** (nested PlaceObject3 filters) | 0 corpus rows | **Premise REFUTED as stated**; a real but corpus-dead bug was found | 0 | M | §2. The probe and the corpus scan both show it. |

**Total priced: +5 proven by prototype** (ranks 1 and 2, one patch). Another +1 is GO-M (rank 3) and +1..2 is HOLD-M (rank 4).

Every other row is a standing NO-GO or ACCEPTED entry, and each one still shows its recorded diff shape (§4).

**Landing note:** ranks 1 and 2 meet the s23 "land measured wave-1 prototypes directly" bar:
- CI-mode graphics, with no-graphics parity checked.
- Argued sweeps are clean.
- No `known_failure` on any of the five rows, so `pass` is the only landing.

The code is shared runtime code (`action.c` and `avm1_amf.c`, none of it in `#ifdef NO_GRAPHICS`), so graphics `all` is the CI leg. When it lands, delete `load_vars` and `stylesheet_load` from `ruffle-tests/ignored_tests.txt`, along with their rationale paragraphs in the "Network/form loading" bucket.

---

## 1. The prototype: 5 flips, 4 mechanisms

### 1a. `amf0_array_matrix`: an LC-received ECMA array is not `instanceof Array`

- **Mechanism:**
  - `avm1_amf.c` `rd0_value` `case M0_ECMA` (≈1186) allocates the array with `allocArray` and never links a prototype.
  - Named keys then create a bare `arr->props` in `rd0_pairs_into_array` (≈1083).
  - So `checkInstanceOf` (`action.c` ≈50640) finds a props object with no Array `__proto__`, and the virtual-Array fallback does not answer it.
  - Script-built arrays go through `initArrayProto`, which sets the versioned Array proto on props.
  - SharedObject never shows the bug: `getLocal` returns the live cached object, so only the LC path deserializes.
- **Fix:** a non-static wrapper `avm1AmfInitArrayProto()`, placed next to `initArrayProto` in `action.c`, called right after `allocArray` in `M0_ECMA`.
- **Result:** 49/50 → **PASS**.

### 1b. `localconnection_serialize_sparse_array_getters`: `Array.addProperty("1", …)` is not enumerable

- **Mechanism:**
  - The Array `addProperty` arm of `actionCallMethod` (`action.c` ≈71440) creates the prop in `arr->props` and marks it ENUMERABLE.
  - But it never calls `arrayTrackKey`.
  - The array's for-in (`action.c` ≈51140) walks `arr->enum_keys` once any key is tracked, and `values[2]` was already tracked. So the accessor key is skipped.
- **Fix:** `arrayTrackKey(arr, name, len)` when the property is freshly created.
- **Result:** 25/26 → **PASS**.

### 1c. `localconnection_xml_unavailable`: AMF0 XML with `_global.XML` removed

This follows Ruffle `f6dd758c2`, in `core/src/avm1/amf.rs` `instantiate_amf0_xml` and `deserialize_lso_value`. There are two sub-mechanisms, both in `avm1_amf.c` `case M0_XML` (≈1240):
1. **The global `XML` binding is gone:**
   - Flash returns an object with **no prototype**. That is why `toString`, `constructor`, `nodeName` and `firstChild` are all undefined, and "same constructor" is `true` (undefined === undefined).
   - Ours always built a native document.
   - The new helper `avm1AmfCreateXmlForRead()` in `action.c` checks `global_object`'s own `XML`: a non-function, non-object value gives a bare `allocObject`.
   - A monkeypatched XML constructor is not modelled. Ruffle constructs through it; no corpus row needs that.
2. **An LC-read XML value does not claim a reference slot** (Ruffle's LSO path), although the writer counted one.
   - This shifts later references: `items[3]` (a ref to `shared`) resolves to undefined, which gives the expected `identity: false` and `type: undefined`.
   - Fix: `if (!r->lc_refs) rd_ref_claim(...)`. Every reader that claims refs today is the LC reader, so in practice the claim is simply dropped.
- **Result:** 9/23 → **PASS**. Neighbour `localconnection_xml` still passes.

### 1d. `load_vars`: `LoadVars.sendAndLoad` never delivers to the target

- **Mechanism:** `builtin_loadvars_sendAndLoad` (`action.c` ≈42852) is documented as "Our offline implementation never fires onLoad".
  - The fixture creates a fresh `LoadVars` per section, so the second expected `Load: true …` block is `loadVars2.onLoad` from `sendAndLoad('testvars.txt', loadVars2, 'POST')`.
  - Running at `num_ticks = 6` still gave one block, which rules out a timing cause.
- **Fix:** queue the URL into the **target** through `builtin_loadvars_load` (forward-declared), so the target gets the same deferred `onData` → `decode` → `onLoad` as `target.load(url)`.
  - XML targets keep the old no-op; no corpus row exercises them.
  - Already-traced state still holds: `loaded == false` and `getBytesLoaded() == 0` right after the call.
- **Result:** 29/35 → **PASS**.

### 1e. `stylesheet_load`: `TextField.StyleSheet.load` was a literal stub

- **Mechanism:** `stylesheetLoad` (`action.c` ≈18151) returned `undefined`. The ignore entry is accurate.
- **Fix** (Ruffle `style_sheet.rs::load` and `loader.rs::load_stylesheet`):
  - `load(url)` returns `true` and rides the deferred LoadVars queue with a new trailing `is_stylesheet` field. It sets no `loaded`/`_bytes*` properties on the StyleSheet.
  - Delivery calls **`this.parse(body)`**, then **`this.onLoad(<parse result>)`**. It looks `parse` up through the proto chain, so the fixture's traced override runs.
  - A missing file gives `onLoad(false)` without a `parse`. No argument gives `false`.
- `fireLoadVarsCallback` now **returns** the callee's value; it was `void` and every existing caller ignores the result.
- **Result:** 1/49 → **PASS**. This covers merge-by-selector (`valid2`) and the invalid-CSS `onLoad(false)` keeping the old styles, both of which the existing `parseCSS` already did.

### 1f. Evidence

**Headline rows, graphics and no-graphics:**

| Row | Baseline | Prototype (graphics) | Prototype (no-graphics) |
|---|---|---|---|
| `amf0_array_matrix` | 49/50 | PASS | PASS |
| `localconnection_serialize_sparse_array_getters` | 25/26 | PASS | PASS |
| `localconnection_xml_unavailable` | 9/23 | PASS | PASS |
| `load_vars` | 29/35 | PASS | PASS |
| `stylesheet_load` | 1/49 | PASS | PASS |

**Sweep A (after 1a+1b, 35 rows).** Every row kept its baseline status:
- all avm1 `amf*`, `localconnection*`, `netconnection*` and `shared_object_*` rows
- `add_property`, `array_constructor`, `array_sort`, `as_broadcaster`, `asnew`, `object_properties`, `context_menu`
- shumway `localconnection` (pass) and `flash_net_SharedObject` (ruffle_matched)
- `shared_object` is an inert ignore row (multi-run format), and `localconnection/avm2child` is a sub-SWF, not a row.

**Sweep B (after 1c, 24 rows).** The LC/AMF/NC/SO subset plus `xml_socket`: all pass.

**Sweep C (after 1d, 13 rows).** Every SWF in the downloaded corpus whose bytecode contains `sendAndLoad`, plus LoadVars neighbours:
- gnash `LoadVars-v6/v7/v8` stay ruffle_matched, at 146 positional matches, unchanged.
- gnash `XML-v5..v8` and `ExternalInterface-v8` stay ruffle_matched.
- avm1 `loadvars_tostring`, `native_objects_swf7/8`, `globals_swf8` and `loadvariables_method` stay pass.

**Sweep D (after 1e, 17 rows):**
- These stay pass: `stylesheet`, `stylesheet_transform`, `edittext_stylesheet`, shumway `stylesheet`, `loadvariables`, `loadvariables2`, `loadvariablesnum`, `loadvariables_method`, `loadvars_tostring`, `form_loader_encoding_1`, gnash `LoadVars-v5`.
- gnash `LoadVars-v6/7/8` stay ruffle_matched.
- `global_instance_decls` and `TextField-v6` stay at their baseline fail.

**`regression/` suite** (10 rows near the change): all PASS.
- `lv_cross_swf_version` and `lv_ondata_type1_args`, which pin `fireLoadVarsCallback`
- `lc_method_type1_args`, `lc_onstatus_type1_args`, `xml_onload_type1_args`
- `array_element_type1_args`, `array_method_type1_args`
- `avm2_localconnection_domain`, `avm2_array_growth_bounded`, `avm2_embed_bytearray`

**Pixel axis:** no expected moves, since no render code changed. A canary run is not needed.

---

## 2. L1 (nested PlaceObject3 filters): premise refuted as stated; the real bug is in the recompiler, with 0 corpus rows

**Probe.** `w1-avm1-tail-probe/mkl1.py` (SWF8, AS1/2):
- Sprite 3 places three children, each with a PlaceObject3 filter list:
  - `one` = [Glow]
  - `two` = [Blur, DropShadow]
  - `cm` = [ColorMatrix]
- The root places the same three lists at root depths: `rootone`, `roottwo`, `rootcm`.
- The frame-2 script traces `filters.length`, `[0].blurX`, `[1].blurX` and `[0].matrix.length`.

**Our trace:**

| Clip | Our output | Predicted Flash |
|---|---|---|
| `outer.one` | n=1, blurX 6 | **same** |
| `outer.two` | **n=1**, blurX 4, `[1]` undefined | n=2 |
| `outer.cm` | **n=0** | n=1, matrix.length 20 |
| root `one`/`two`/`cm` | correct | correct |

**Refutation of the brief's premise:**
- "A filtered clip nested in a sprite reads back `[]`" is **false** for a single simple filter.
- The getter's last fallback, `ng_getObjFilterData(entry, …)` (`action.c` ≈59470), reads the entry's own `filter_*` fields. Those fields are written correctly for nested entries, because sprite frame code runs with `display_list` swapped to the sprite's list (`tag.c` ≈708/1159). So `tagSetFilter(depth, …)` lands on the nested entry.

**Real mechanism:** it is in the recompiler, so the bug hits the **render** as well as the getter.
- `SWFRecomp/src/swf.cpp`'s DefineSprite PlaceObject3 arm (≈6085–6250, emitted at ≈6552) keeps **only the first simple filter** (`if (sp_filter_type == 0)` on every case).
- It drops ColorMatrix/Convolution entirely and never emits `tagBeginFilterList`/`tagAdd*`. The root arm (≈4269, ≈5123) does emit them.
- So for a nested clip, every filter after the first is lost, and a CM-only or Convolution-only list renders unfiltered and reads `[]`.

**Corpus check:** `scan_nested_filters.py` decompresses every downloaded `test.swf` and walks each DefineSprite's PlaceObject3 filter lists.
- Downloaded suites: avm1, from_gnash, from_shumway, regression, visual, timeline, swf; 1945 SWFs in total.
- It found **0 SWFs** with a nested list of more than one filter, or a nested CM/Convolution/gradient filter. The probe SWF is the only hit.
- So this is **0 flips** on trace and pixels, but game-visible.

**Completion mechanism (M), if anyone funds it:**
1. Make the sprite arm emit the same `tagBeginFilterList`/`tagAdd*` sequence as the root arm. Factor out the root emitter.
2. Make the filter-list store **per entry** instead of root-depth-keyed. `g_filter_lists[32]` (`tag.c` ≈13595) is keyed by depth only, so nested depth 2 would collide with root depth 2 in this very probe.
   - Option: heap-allocate the list in `tagBeginFilterList` when `display_list != g_root_dl` and hang it on `filter_chain`.
3. Make the getter read `entry->filter_chain` instead of `ng_getFilterListDataByDepth(ng_objRootDepth(entry))`. The ExtFilterData table needs the same change.
- Needs `--recompile` on the filter rows and a render canary.
- **Rank: last.** No row pays.

---

## 3. `text_format_get_text_extent_own` (new upstream row, Ruffle `674bee2d8`): GO M, +1, coordinate with w1-native-proto

**Today:** 10/19. Flash defines `getTextExtent` as an **ordinary, enumerable, deletable own property with a fresh function per object**.
- It does this in the constructor, under `new` and `super()`.
- It also does it for `getTextFormat()`/`getNewTextFormat()` results.
- It does not do it without `new`, and does not do it for an object that already has native data, so it happens at most once.

**Our gaps, each in `action.c`:**

| Expected line(s) | Gap | Owner site |
|---|---|---|
| 4 | `a.getTextExtent === b.getTextExtent` must be `false`. Ours installs the single static `g_textformat_fn_getTextExtent` everywhere. | `new TextFormat` arm ≈60475; a fresh `ASFunction` clone is needed per install |
| 7, 8 | `getTextFormat()`/`getNewTextFormat()` results never get it | `tf` builder ≈17292 |
| 9, 13, 16 | The `super()` / native-ctor-on-existing-object path never installs it. Its guard should be "object had no native data before": `native_type == NATIVE_NONE` on entry, which the code already tests. | ≈64144 |
| 1–3, 7–9 | `own=undefined` instead of `own=false/true` | **unexplained**, see below |

**The unexplained `own=undefined`:**
- `o.hasOwnProperty("getTextExtent")` returns **undefined** for every TextFormat object, and for `TextFormat.prototype`, when it is called from the test's `where(label, o)`. That is a Rascal DefineFunction2, `o` is in register 2, and the method name is constant-pool `str_2`.
- `builtin_object_hasOwnProperty` cannot return undefined, so it is never reached.
- A hand-assembled top-level probe (`mktfx.py`, with a for-in first) gets correct `true`/`false` on the same objects.
- So the dispatch that is lost is in `actionCallMethod` for a register-held NATIVE_TEXTFORMAT receiver inside a function. The plain-object rows (6, 17, 18) are fine.
- Wave 2 should bisect `actionCallMethod` (≈70219) with an env-gated trace. This is the cheap axis.

**Coordination:**
- Ruffle couples this to `d205531a2` (lazy prototype properties), via `define_instance_properties` next to `define_lazy_proto_properties`.
- w1-native-proto owns `text_format_prototype_lazy`, and both patches would edit the same three TextFormat construction sites.
- Fund it as one slot, or land the sibling first and rebase.

---

## 4. Standing dispositions: one run each, still the recorded diff shape

| Row | Class | Disposition | Run vs baseline |
|---|---|---|---|
| `edittext_set_text_same`, `…_after_edits` (KF) | (c) but L | HOLD L of record (s23 w2-tf-css §3, w2-tf-css-avm2 §4): the plain-field per-character format model | 28/70 and 30/98, identical. Same 4 gaps: setTextFormat on a plain field never reaches getTextFormat, setNewTextFormat not reflected, the same-text rule, textColor recolor |
| `movieclip_hittest_shapeflag` | (a) | ACCEPTED Cat 8 + `ignored_tests.txt` | 332/338, identical. The entry still says "9 diffs"; there are now 6. Doc drift, not a lead |
| `set_property_values/swf4` (KF) | (c) but L | **no disposition entry**. Do not book the s20 "all three variants flip" as covering swf4 | 346/1571, identical since at least `bc91565ce`. Three SWF4-only Flash semantics, measured over 295 blocks: (1) `new Object()` is not constructible in SWF4 and the debug player traces `Warning: Object is not a function` (201 blocks); (2) SWF4 string→number is strict (`"10x"` → 0); (3) `_xscale` round-trips through 16.16 storage (`2` → `1.9989013671875`, `-5` → `4.998779296875`). Ruffle fails all three (its sidecar = ours on (1)). NO-GO: an emulated debug-player warning is not worth one row |
| `bitmap_data_thorough/pixelDissolve` (KF panic) | (a) | ACCEPTED + ignore | 1335/1371, identical; the 36 Feistel/coercion lines |
| `date` | (a) | ACCEPTED + ignore | 6289/6335, identical. Same lines: the ±Infinity components, `-8.64e15` UTCHours, fractional TimezoneOffset |
| `external_interface_monkeypatch` (KF) | (a) | standing NO-GO (§24.4) | 4/139, same shape. The test traces every internal `_initJS/_toJS/_callOut/…` lookup; we have no AS-level ExternalInterface plumbing |
| `globals_monkeypatch` | (a) | standing NO-GO, widened by upstream drift (s23 §5) | 44/306, identical |
| `sandbox_type_remote` | (b)/(c) | ignore entry, reason accurate | 1/3, identical. HOLD M (rank 4): `loadClip("http://localhost:8000/test-network.swf")` needs a child-movie mapping to `<test>/localhost/`; the sound and NetConnection paths already strip `localhost:8000/` (`action.c` ≈2505, `avm1_amf.c` ≈1840), but the loadClip/child table does not. It also needs a per-movie `System.security.sandboxType` |
| gnash `TextField-v6/v7/v8` | (c) but L | `incomplete/TEXTFIELD_VN_PLAN.md` (13 phases) + ACCEPTED `restrict=""` 2 lines | 467/545, 476/570, 478/571, identical. The largest block (≈26 lines per version: `!TextField.prototype.hasOwnProperty('background'…)` before the first instance) is the **lazy-prototype-properties mechanism, the w1-native-proto family**. v7/v8 add `_xtrace_win instanceof TextField` / typeof `movieclip` (shared-assets container identity) |
| gnash `argstest-v6/v7/v8` | (a) | ACCEPTED Cat 3 + suite ignore | 80/2192, 110/2061, 175/2434, identical |
| gnash `misc-ming.all/DrawingApiTest` | (c), plan of record | `incomplete/DRAWING_API_HITTEST_PLAN.md` | 81/93, identical. All 12 residual lines are Drawing-API `hitTest(…, true)` precision: stroke-only, winding, corner |
| gnash `register_class/RegisterClassTest4` | (a) | ACCEPTED + suite ignore | 7/42, identical |
| gnash `misc-swfc.all/matrix_accuracy_test1` (KF panic) | (a) | ACCEPTED Cat 4 + suite ignore | 10/18, identical. Same INT_MIN/INT_MAX twip lines |
| gnash `misc-swfc.all/sound` | (a) | ACCEPTED (interactive capture truncates) | 7/7 + 5 extra lines, identical |
| shumway `esc` (AVM2) | (c), unpriced | suite ignore with no per-name reason | 0/2, identical. **A runtime error, which names its own mechanism**: `TypeError #1009` in `Util::Hashtable/makeTable()` ← `Util::Hashtable()` ← `global$init()`, then cascades (#1010 `kind` in `Function/makeInstance`, #1009 in `Main/compile`). The first fault is a null deref inside a script-init `Hashtable` constructor. Not chased: it is AVM2 and outside this slot's AVM1 focus. Hand it to an AVM2 slot as a cheap runtime_error triage |
| shumway `bitmapdata/getpixel-from-embedded` | (a) | standing NO-GO "a disposition, not a fix" (s19/s20) | 1/2, identical: `200d04` vs `220a06`, JPEG decoder parity (stb_image vs Flash's decoder). Upstream `known_failure.ruffle_check = false` says Ruffle is platform-variable too. Recommend formalising an ACCEPTED entry |

`GradientFillTest`, `MovieClip-v8` and `action_order/*` were skipped as instructed.

---

## New unclaimed leads

1. **Recompiler DefineSprite PlaceObject3 filters keep only the first simple filter** (§2; `swf.cpp` ≈6085/6552). Nested multi-filter lists and nested CM/Convolution filters are lost in render and in the getter. There are 0 corpus rows, but games are exposed. The filter-list side table (`tag.c` ≈13595, 32 slots keyed by depth) would also collide between root and nested depths.
2. **`actionCallMethod` loses `hasOwnProperty` on a register-held TextFormat receiver inside a DefineFunction2** (§3). It returns undefined. This may be wider than TextFormat; it is worth a probe across native types.
3. **`ACCEPTED_DIFFS.md` Cat 8 (`movieclip_hittest_shapeflag`) is stale:** it records 9 diff lines and there are now 6 (332/338). This is doc only.
4. **`set_property_values/swf4` has no disposition entry** (§4). If it is not funded, add a RUFFLE_COMPAT / ACCEPTED entry naming the three SWF4 semantics.
5. **shumway `esc`:** an AVM2 runtime_error with a named first fault (`Util::Hashtable/makeTable` #1009).
6. **`LoadVars.sendAndLoad` with an XML target** still does not deliver (the prototype keeps the no-op). No row needs it.

## LOCAL ORACLE REQUESTS

1. **L1 probe (optional; only needed if anyone funds §2).**
   - SWF: `SWFRecompDocs/plans/session24-fanout-reports/w1-avm1-tail-probe/l1_nested_filters.swf` (550×400, SWF8, 2 frames). It is gitignored, so generate it first with `python3 mkl1.py l1_nested_filters.swf`.
   - Need: the Ruffle exporter **trace** (3 ticks), plus a 1-frame render.
   - It settles whether nested PlaceObject3 filter lists read back with full length and type, as predicted in `l1_nested_filters.predicted_flash.txt` (12 lines). Ruffle's AVM1 `filters` getter reads the display object's own filter list, so its trace should match the prediction.
   - The render would give the expected look for the nested `two` (blur + shadow) and `cm` (darkened) clips.
2. **None needed** for ranks 1–3. Each target's `output.txt` is Flash and none of them is `known_failure`.
