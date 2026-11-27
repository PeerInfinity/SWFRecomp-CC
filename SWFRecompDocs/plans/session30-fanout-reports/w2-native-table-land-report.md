# s30 w2-native-table-land — generated AVM1 native-object table (W2-a) + singleton cleanups (W2-c) + Array/String identity (W2-d)

Slot `w2-native-table-land`, wave 2 (implementation). Base `origin/master` `6481e7c4` (code = s30 baseline
`2d40d3799` + docs). Upstream corpus: Ruffle master **`66f9073de`** (downloaded 2026-11-27: avm1, from_gnash, avm2,
from_shumway, visual, text, fonts). Box: SETUP_STATUS all OK (apt, Pillow, Dawn). Before leg = a clean
`origin/master` git worktree on the same box, with the same downloaded tests copied in.

**NEW files**
- `SWFModernRuntime/include/actionmodern/avm1_native_table.inc` (generated; `#include`d by `action.c`, no new TU, so
  verify_output / CMake / Emscripten source lists are untouched)
- `scripts/gen_avm1_native_table.py` (the generator; regenerates the `.inc` byte-identically, command in its docstring)
- `SWFRecompDocs/plans/session30-fanout-reports/w2-native-table-land-report.md` (this file)
- `SWFRecompDocs/plans/session30-fanout-reports/w2-native-table-land.patch`
- `SWFRecompDocs/plans/session30-fanout-reports/w2-native-table-land-fixtures/`: `mk_probe.py` +
  `native_identity_probe.v{5,6,7,8}.swf` (FLASH request 1) with our `.ours_before.txt` / `.ours_after.txt`;
  `sweep_list.txt`, `sweep_graphics.tsv`, `sweep_nographics.tsv` (per-row before/after)

**Edited non-source files (committed on the branch, NOT in the patch):** `ruffle-tests/tests/swfs/avm1/_investigation/
ACCEPTED_DIFFS.md` (new Category 15 + summary row), `ruffle-tests/ignored_tests.txt` (comment on the decls rows),
`ruffle-tests/tests/swfs/from_gnash/actionscript.all/ignored_tests.txt` (comment on argstest). The patch also carries
`scripts/gen_avm1_native_table.py` (outside the standard dirs list, because the `.inc` is generated from it).

## 0. Verdicts and EXPECTED-FLIP LEDGER

| item | verdict |
|---|---|
| W2-a: table pass landed | **GO, landed.** One kill switch (`SWF_NATIVE_TABLE=0`); the `_ORDER` / `_STATS` switches and counters are gone. |
| W2-c: own `toString` drop, ASnative/ASSetNative swap, `_global.o`, inert stubs | **GO, landed** (stubs: AssetCache.getDiskUsage/purge, RemoteLSOUsage.getURLPageSupport, `.prototype` on AssetCache/RemoteLSOUsage/AsSetupError; plus the singletons' own `constructor`). `Sound.prototype.checkPolicyFile/areSoundsInaccessible` and `Error.prototype.name/message` **not done** (§4). |
| W2-d: one Array / String identity, eager Accessibility | **GO, landed.** `Array === _global.Array`, `_global.Array.NUMERIC == 16`, `String === _global.String`, `_global.String.fromCharCode` a function, `[].constructor === _global.Array` (all `false`/`undefined` before; probe below). |
| Flips | **0 expected, 0 measured** on both axes. |
| Guard sweep (143 rows, both modes) | **0 status moves** in graphics, **0** in no-graphics; graphics and no-graphics statuses are identical on every row. Regression subset 21 + 4 rows: 0 moves. |
| `manufacturer` position | **ACCEPTED Category 15** (written): host-dependent, WIN golden ≠ LNX (3/3 LNX captures = ours). No flash_fixes swap. |

**EXPECTED-FLIP LEDGER (for the coordinator's CI check)**
- Trace axis: **no pass/fail flips.** No row changes status. The rows that move Flash-ward but stay
  `output_mismatch` (all already in `ignored_tests.txt`):
  `avm1/global_proto_decls`, `avm1/global_proto_decls_delete`, `avm1/global_instance_decls` (unchanged at the
  diff-line level vs W2-a alone, 767), gnash `actionscript.all/argstest-v6`, `-v7`, `-v8`. `matching_lines` in
  `results_graphics.json` WILL change on these 6 rows (positional count: 62→1518, 461→797, 17→20, 84→110, 78→44,
  121→150). That is not a regression: the diff-line counts below fall on every one of them. `argstest-v7`'s positional
  count drops (78→44) while its diff lines fall 2209→2034.
- Pixel axis: **no expected moves** (trace-only runtime change). Render canary: 268/268 md5-identical (§5).
- Any other trace or pixel move on CI is NOT predicted by this patch: treat it as a regression or as drift.

## 1. Per-test before/after (clean origin/master vs this patch, same box, `--mode=graphics`)

Diff lines = `diff golden ours | grep -c '^[<>]'` (argstest graded against `output.fp32.txt`).

| row | golden lines | before | W2-a only (w1 measurement) | **after (this patch)** | status before → after |
|---|---|---|---|---|---|
| `avm1/global_proto_decls` | 4562 | 2593 | 920 | **678** | mismatch → mismatch |
| `avm1/global_proto_decls_delete` | 4158 | 2215 | 781 | **557** | mismatch → mismatch |
| `avm1/global_instance_decls` | 758 | 1073 | 767 | **767** | mismatch → mismatch |
| gnash `argstest-v5` | 4 | 0 | – | 0 | pass → pass |
| gnash `argstest-v6` | 2192 | 2208 | 2043 | **2005** | mismatch → mismatch |
| gnash `argstest-v7` | 2061 | 2209 | 2048 | **2034** | mismatch → mismatch |
| gnash `argstest-v8` | 2434 | 2238 | 2079 | **2065** | mismatch → mismatch |
| gnash `ExternalInterface-v8` | 118 | 6 | 6 | 6 | rm → rm (instance layout: w2-native-instance) |

Brief-premise correction: the brief's ledger quotes `global_proto_decls` 2593 → 878 and `global_instance_decls`
1073 → 743. Those are w1's numbers from *before* its READ_ONLY safety rule (the rule that fixed the gnash `System-v8`
loss). The landed W2-a gives 920 / 767; W2-c+d then take `global_proto_decls` to 678.

**Version check against the new FP32 per-version dumps** (`w1-local-oracles/w1-native-table/`, corpus bytecode at
SWF 6/7/8, LNX). The table is generated from the SWF15 golden but applied at every version; these runs show it is
Flash-ward at every measured version:

| fixture vs FP32 LNX dump | golden lines | before | after |
|---|---|---|---|
| `global_proto_decls` v6 | 4077 | 2569 | 800 |
| `global_proto_decls` v7 | 4097 | 2524 | 739 |
| `global_proto_decls` v8 | 4562 | 2613 | 700 |
| `global_proto_decls_delete` v6 | 3917 | 2251 | 619 |
| `global_proto_decls_delete` v7 | 3935 | 2230 | 593 |
| `global_proto_decls_delete` v8 | 4165 | 2224 | 562 |

### Where the `global_proto_decls` 678 lines go (section attribution, after)
- ~510: `Key/Mouse/Selection/Stage._listeners.*` (ARRAY for..in never walks `__proto__`: **w2-array-forin-proto**).
- 72: `clearTimeout` / `Key|Mouse|Selection.broadcastMessage`: first-visit unhide order of shared Object.prototype
  methods. It should fall out once `_listeners` is fixed (w1 §3).
- 53: `XMLNode.prototype` / `XML.prototype` (READ_ONLY-ambiguous getters + instance layout: w2-native-instance).
- 20: `MovieClip.prototype` (READ_ONLY-ambiguous getters, the w1 "oracle 2" probe).
- 9: `Button.prototype` on-handler + `tabIndex` slots (w2-drift-smalls-land territory).
- 6+1: `Error.prototype` name/message/toString order, `Error.prototype` own slot (§4).
- 6: `TextField.prototype` getters (filters/sharpness/…) + own `constructor`.
- 4: `System.useCodepage/exactSettings` READ_ONLY (unobservable by design, attr 32; the gnash `System-v8` guard).
- 2: `Sound.prototype.checkPolicyFile/areSoundsInaccessible` (§4).
- ~5 single lines: prototype own `constructor` / `__constructor__` (String/Date/TextFormat/Number/Boolean.prototype).

## 2. What changed (all in `SWFModernRuntime/src/actionmodern/action.c` unless noted)

**Functions touched:** `installNativeToString`, `ensureAccessibilityMethods`, `ensureGlobalInit`, `actionGetVariable`
(the builtins arm, `Array` and `String` branches only). **New `static`s:** `avm1ntTargetOf`, `avm1ntResolve`,
`avm1NativeTableApply` (W2-a), `ensureArrayConstructorStatic` (W2-d), `avm1StubFn`, `avm1NativeStubsInstall` (W2-c),
`g_string_ctor_ref`, `g_avm1stub_getDiskUsage/purge/getURLPageSupport`. `setupNativeFuncOwnProps`, `math.c` and every
other file are unchanged. No sibling-owned function is touched (`actionEnumerate2`, the XML ctor, the filter instances,
and the tabIndex arms are all untouched).

- **W2-a** `avm1NativeTableApply` as w1 measured it, called last in `ensureGlobalInit` (after
  `avm1NativeStubsInstall`, so the stubs get table flags and order). It carries the constructor-placeholder repair
  (`f.constructor === f` → Function). Kill switch `SWF_NATIVE_TABLE=0` only.
- **W2-c**
  - `installNativeToString` now returns early at SWF5+. FP32 has no own `toString` on Key/Mouse/Stage/Selection/
    Accessibility/Math/Sound.prototype, and the inherited `Object.prototype.toString` already prints
    `[object Object]` at SWF5+. The SWF4 `[type Object]` bypass is kept. String coercion is unchanged (probe:
    `"" + Key`, `Key.toString()`, `"" + new Sound()` all still print `[object Object]`, v5–v8).
  - ASnative / ASSetNative swap: `ASSetNative` / `ASSetNativeAccessor` now get `setupNativeFuncOwnProps`. `ASnative`
    gets an empty own bag (no `__proto__` / `constructor`), so `Testing _global.ASnative` is empty, as in FP32.
  - `avm1NativeStubsInstall` (SWF6+, the lowest FP32 dump that lists them): `_global.o = null` (DONT_ENUM),
    `AssetCache.getDiskUsage/purge` (no-op natives), `RemoteLSOUsage.getURLPageSupport` (with prototype), and
    `.prototype` on AssetCache / RemoteLSOUsage / AsSetupError. At all versions it adds an own `constructor = Object`
    (DONT_ENUM) on Key/Mouse/Selection/Stage/Accessibility/Math/SoundCodec/System.capabilities. FP32 has it (`own,
    READ_ONLY`), and `Key.constructor === Object` is now `true` (it was `false`).
- **W2-d**
  - Array: `ensureArrayConstructorStatic` (the old GetVariable init body, factored out) is called by the arm and by
    `ensureGlobalInit`, which now registers `g_array_constructor_static` as `_global.Array`
    (`g_array_ctor_registered` = it; the Phase 8c-2 own-props list uses it). `g_ctors[1]` stays as an unregistered
    husk. `arrayResolveGlobalCtor`'s registered→static remap is now an identity.
  - String: Number's `g_number_ctor_ref` pattern. `g_string_ctor_ref = &g_ctors[2]`, `fromCharCode` (DONT_ENUM) is
    installed on `_global.String` in `ensureGlobalInit`, and the arm returns the ref. The arm's one-time
    String.prototype setup (valueOf/toString/constructor/__constructor__/stub methods) is kept verbatim, retargeted to
    the ref. The lazy local `g_string_constructor` is gone.
  - Accessibility: `installAccessibilityMethods` runs eagerly in `ensureGlobalInit`, and the three methods carry the
    SWF6+ `flash_flags` bit (0x0080), the same gate AsBroadcaster's Key/Mouse/Stage methods use. It is a per-access
    version gate, so the Dejagnu SWF5-child-import case stays correct. `ensureAccessibilityMethods` is kept as a
    safety net. v5 probe: `typeof Accessibility.isActive` is still `undefined`.

### Probe (ours, before → after; `w2-native-table-land-fixtures/native_identity_probe.v8.ours_*.txt`)
```
Array===_global.Array: false -> true          _global.Array.NUMERIC: undefined -> 16
String===_global.String: false -> true        typeof _global.String.fromCharCode: undefined -> function
[].constructor===_global.Array: false -> true Key own toString: true -> false (str still [object Object])
Key.constructor===Object: false -> true       typeof AssetCache.getDiskUsage: undefined -> function
ASnative keys after unhide: "__proto__,constructor," -> ""   ASSetNative: "" -> "__proto__,constructor,"
```
v5 changes: only `Key.constructor===Object` (→ true), `ASnative.__proto__` (→ undefined), and the post-
`ASSetPropFlags` key lists. The Accessibility methods now enumerate at v5 after an explicit unhide, exactly like the
pre-existing AsBroadcaster methods on Key. FP32 v5 behaviour is unmeasured: FLASH request 1.

## 3. Guard (both modes; every move by name)

**Set (143 rows, `w2-native-table-land-fixtures/sweep_list.txt`)** = w1's 76-row sweep + the 8 headline rows + the
static-member rows the brief names:
- gnash `Key/Mouse/Stage/Selection/Math/Sound/String/array/System` at v5/v6/v7 (27), `Accessibility-v5/v7`,
  `Global-v7`;
- avm1 `asnative_instrument`, `asnative_sweep`, `shared_object_members_swf5` (the §2.5 stub probes),
  `math_swf6/7/8`, `math_min_max`, `selection`, `selection_asbroadcaster`, `stage_object_properties{,_get_var,_swf6}`,
  `stage_property_representation`, `key_isToggled`, `mouse_listeners`, `sound`, `sound_props_swf5/6`,
  `sound_getters`, `sound_owner_tostring_fail` (the `"" + x` coercions), `array_properties/constructor/sort/
  prototyping`, `string_methods{,_swfv5}`, `string_coercion`, `external_interface_monkeypatch`,
  `coerce_to_object_monkeypatch`.

Why these rows: every one either prints a singleton or ctor static (`"" + Key`, `Math`, `Sound`), probes
`typeof`/`hasOwnProperty`/for..in on a native, uses `Array.*` sort constants or `String.fromCharCode`, or rebinds
`_global.Array`/`String`.

**Result:** graphics: 115 pass → pass, 20 rm → rm, 8 mismatch → mismatch, **0 moves**. No-graphics: identical
statuses on all 143 rows, **0 moves**. Matching-line counts are identical on every row except the 6 headline rows of
§0. Per-row TSVs are in the fixtures dir.

**Regression suite** (graphics; argued: every regression row about arrays/strings/natives/ctor identity/watch/
type-1 args): `array_element_type1_args`, `array_method_type1_args`, `avm1_array_generic_receivers`,
`avm1_edittext_cut_copy_selection`, `avm1_key_isdown_protected`, `avm1_root_onload_proto`,
`avm1_textfield_ctor_shadow_swf6/7`, `avm1_timer_native_method_play`, `avm1_watch_long_name`,
`avm1_watch_overflow`, `ctor_before_first_call_locals`, `onconstruct_cross_swf_version`, `onconstruct_type1_args`,
`string_prim_method_type1_args`, `watch_cross_swf_version`, `watch_mc_reentrant_setmember`, `watch_mc_type1_args`,
`watch_setmember_type1_args`, `watch_timeline_named_params`, `watch_timeline_reentrant`: **21/21 pass → pass**. Plus
the 4 regression rows inside the sweep (`avm1_array_native_own_method`, which rebinds `_global.Array`, and
`avm1_mc_super_native_probe`, `avm1_xml_first_action_proto`, `avm1_xmlnode_first_action_proto`): pass → pass.

## 4. Not done (each with its completion mechanism)
- **`Sound.prototype.checkPolicyFile` / `areSoundsInaccessible`.** FP32 v6–8 has both as `undefined`-valued own
  members (accessor-like; `s1.checkPolicyFile` is `boolean` on instances: gnash `Sound.as:112`), and
  `areSoundsInaccessible` becomes a function only at SWF15. Mechanism: a prototype accessor plus instance layout,
  which is w2-native-instance's area. It is 2 lines.
- **`Error.prototype.name/message` as own data slots + `Error.prototype` own on `_global.Error`** (7 lines). Ours are
  virtual. Risk: the Error rows (gnash `Error-v8` rm). Mechanism: an Error-owner slot with its own guard.
- **Prototype own `constructor`** on String/Date/TextField/TextFormat/XMLNode.prototype (~5 lines): needs an
  unhideable own slot. S, and it needs the golden walk to confirm each.
- **FP32 "present but undefined below min_swf" values** (new, from the v6 dump): at SWF6, FP32 lists
  `MovieClipLoader.prototype.*`, `PrintJob.prototype.*`, `System.IME.*`, `Stage.fullScreen*`, `textRenderer.*`, etc.
  as OWN members whose value is `undefined` and which are not READ_ONLY. Ours are live at every version. This is a
  value-gating model (the members exist, but their natives are version-masked), not a presence column. It is
  pre-existing (same in the before leg), worth ~100–150 lines on the v6 dump, and L (it touches every versioned
  native). Not in this patch.
- `_global.hasOwnProperty("o")` returns `undefined` in ours (it is not a table issue: `hasOwnProperty` called on
  `_global` itself). New lead L2.

## 5. Render canary
`render_canary.py capture` before (clean worktree) / after (this patch) over `render_canary_tests.txt` (203 tests / 268 comparisons),
`-P 2 --timeout 5400`, then `compare`. Result: **IDENTICAL 268 / DIFFERS 0 / APPEARED 0 / VANISHED 0 / NO_RENDER 0; no trace or image status changes.** md5 identity holds everywhere (expected: trace-only change).

## 6. Refutations / premise attacks
1. "The `.inc` is a build product": it is a **committed generated source** (the golden is downloaded, not tracked,
   so CI cannot regenerate it). The generator reproduces it byte-identically from today's golden.
2. "Applying a SWF15 table at every version is unsafe": **refuted by measurement** on the FP32 v6/v7/v8 dumps (§1:
   −1700 to −1900 lines at each version). The table creates no member, so it cannot leak a v8-only member into v6. The
   v6 residue that is version-specific is the value-gating model of §4, and it is pre-existing.
3. "Dropping the singleton own `toString` risks `"" + Key` prints": refuted. FP32 SWF5+ inherited `toString` prints
   the same, and every coercion row in the guard is unchanged. SWF4 keeps the bypass.
4. The `manufacturer` "run-to-run" premise from w1: refuted by the coordinator's 3/3 LNX captures. It is a host
   difference, now written as ACCEPTED Category 15.

## 7. New unclaimed leads
- **L1 (M–L): FP32 version value-gating** (§4): members present at SWF6 with `undefined` values and writable. A
  `min_swf` column whose effect is "value reads undefined", not "absent". Data: the v6/v7 dumps.
- **L2 (S): a third ctor identity, `Object`.** `GetVariable("Object")` returns `g_object_constructor_static`
  (`ensureObjectConstructor`) while `_global.Object` is `g_ctors[0]`. The singletons' new own `constructor` uses the
  former, so `Key.constructor === Object` holds. `Key.constructor === _global.Object` probably does not. The same merge
  as String applies (probe it first).
- **L3 (S): `_global.hasOwnProperty(k)` → `undefined`** (probe line `_global own o:`).

## LOCAL ORACLE REQUESTS
1. **FLASH, trace, direct, 1 frame, LNX:** `w2-native-table-land-fixtures/native_identity_probe.v{5,6,7,8}.swf`
   (generator `mk_probe.py`; uncompressed hand-assembled AVM1). Compare against the `.ours_after.txt` next to each.
   Purpose: confirm the W2-c/d facts outside the decls golden (`Array === _global.Array`, `_global.Array.NUMERIC`,
   `String.fromCharCode` identity, `Key.constructor === Object`, the ASnative/ASSetNative own props), and give the
   **SWF5 presence** row (Accessibility methods after an explicit `ASSetPropFlags` unhide, `ASnative.__proto__`,
   own `constructor` on singletons), which the degraded v5 corpus walk cannot give. If FP32 confirms, this becomes
   a `regression/` fixture with the FP32 golden.
2. (Carried from w1, still open) the "unobservable columns" probe (READ_ONLY on primitive members, DONT_ENUM on the
   11 Object.prototype names): not written here. It is what would retire attr bits 4/32 and the ~25 READ_ONLY lines.
