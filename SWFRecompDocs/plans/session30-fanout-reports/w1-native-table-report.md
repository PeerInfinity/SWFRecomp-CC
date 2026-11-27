# s30 w1-native-table — the AVM1 native-object table generated from the FP32 golden

Slot `w1-native-table`, wave 1 (diagnosis + measured prototype). Base `origin/master` `f4edebdc` (code = s30 baseline
`2d40d3799` + docs). Upstream corpus: Ruffle master **`66f9073de`** (downloaded 2026-11-27; avm1 + from_gnash only).
Box: SETUP_STATUS all OK (apt, Pillow, Dawn). Every run is `--mode=graphics` (CI mode); this is trace-only work.

**New files (all under this reports dir; the source is in the patch, reverted from the commit):**
- `w1-native-table-report.md` (this file)
- `w1-native-table-prototype.patch`: `git diff origin/master` of `SWFModernRuntime/src/actionmodern/action.c`, plus
  the new `SWFModernRuntime/include/actionmodern/avm1_native_table.inc` (generated) and `scripts/gen_avm1_native_table.py`
- `w1-native-table-gen/gen_avm1_native_table.py`: the generator (a copy of the one in the patch)
- `w1-native-table-gen/classify_decls.py`, `classify_inst.py`: the diff classifiers behind every histogram here
- `w1-native-table-gen/sweep_list.txt`, `sweep_results.tsv`: the guard sweep, before/after per row
- `w1-native-table-gen/fixtures/*.v{5,6,7,8}.swf`: SWF-version variants for LOCAL ORACLE REQUEST 1

## 0. Verdicts (lead)

| item | verdict |
|---|---|
| Native-object table generated from the FP32 golden | **GO for wave 2 (M for the reconcile pass + L for the residue).** Prototype measured: every one of the 6 measurable owned rows moves Flash-ward, `global_proto_decls` 2593 → 920 diff lines, `_delete` 2215 → 781. **0 flips. 0 sweep moves (76 rows).** |
| Owned rows that flip in wave 2 | **None are priced to flip with the table alone.** Each row also needs mechanisms outside the table (§3). The cheapest are `global_proto_decls` (920 lines left, ~10 named mechanisms) and `ExternalInterface-v8` (1 check: XML *instance* layout, not the table). |
| Guard sweep (64 rows: avm1 `*native*`/`*proto*`/`*global*`/`typeof`/`enumerate`/`as_set_prop_flags*`, gnash `Global/Object/Function/Key/Mouse/Stage/Selection/System/Math/Accessibility/AsBroadcaster/enumerate/delete/TextField`, `regression/avm1_*native*/*proto*`) | **0 moves in the final sweep** (67 pass→pass, 8 rm→rm, 1 mm→mm with identical matching-line counts). The first sweep caught 1 real loss (`System-v8` pass → mismatch). It was fixed (§6.1) before the final sweep. |
| `System.capabilities.manufacturer` (2 lines in `_delete` and `argstest-v6/7`) | **Refuted as a residue we can match: FP32 moves it between runs.** The golden (older FP32) and the fresh s30 LNX capture disagree. With the table, OUR position equals the **fresh** capture. Before the table we matched the golden by coincidence (our order came from insertion, not from Flash). Our order is deterministic. Disposition: grade both orders, ACCEPTED Cat "Flash run-to-run order" (§5). |
| `global_instance_decls` TZ line | Host-TZ only (golden +0200, our run +0545, LNX capture −0700): `mock_timezone` in `test.toml` (s29 per-timestamp DST support) closes it; that is 1 line, not the table. |
| "The golden's flags are clean facts" (implicit premise of the brief) | **Refuted, twice.** (1) `testDecls` builds `enumerated = {}`, which inherits `Object.prototype`, so `enumerated[k]` is truthy for the 11 `Object.prototype` names (`watch … toLocaleString`, `constructor`, `__proto__`). DONT_ENUM is **unobservable** for those names in this golden, on every object. (2) The walk unhides as it goes (`ASSetPropFlags(obj, null, 0, 1)`), so a later section shows an already-unhidden inherited set. The generator encodes (1) as attr bit 4 "keep ours". A naive generator made `Object.prototype` enumerable and **added 2135 lines** (measured, §2.3). |

## 1. Diff of the 7 owned rows, by mechanism (task 1)

Diff lines = `diff golden ours | grep -c '^[<>]'`. Golden = `output.txt` (avm1, EI) / `output.fp32.txt` (argstest).
"before" = `origin/master`; "after" = the prototype patch (final version, all of §2). The kill switch
`SWF_NATIVE_TABLE=0` reproduces `origin/master` **byte-identically** (checked on `global_proto_decls`), so the sweep's
A/B (§4) runs one build.

| row | golden lines | before | after | LNX capture vs golden |
|---|---|---|---|---|
| `avm1/global_proto_decls` | 4562 | 2593 | **920** (878 before the READ_ONLY safety rule) | 0 |
| `avm1/global_proto_decls_delete` | 4158 | 2215 | **781** | 2 (`manufacturer`) |
| `avm1/global_instance_decls` | 758 | 1073 | **767** (743 before the READ_ONLY rule) | 3 (TZ + trailing blank) |
| gnash `argstest-v6` (fp32) | 2192 | 2208 | **2043** (LCS-matching lines 1174 → 1352) | 2 (`manufacturer`) |
| gnash `argstest-v7` (fp32) | 2061 | 2209 | **2048** | 2 |
| gnash `argstest-v8` (fp32) | 2434 | 2238 | **2079** | LNX stops at 111 (`FileReferenceList.browse()` dialog) |
| gnash `ExternalInterface-v8` | 118 | 6 (1 check) | 6 | 0 |

### 1.1 `global_proto_decls`: section/member classifier (`classify_decls.py`)
A section is `Testing PATH`; a member line carries `own`, `DONT_ENUM`, `READ_ONLY`, `type=[…]`. Counts are members
unless marked "lines".

| mechanism | before | after |
|---|---|---|
| sections missing (lines) | 54 (641) | 44 (521) |
| sections extra (lines) | 9 (108) | 6 (72) |
| wrong TYPE `function with prototype` ← ours `function` (per-native-fn `.prototype` presence) | 339 | **1** |
| wrong TYPE `function` ← ours `function with prototype` | 180 | **7** |
| wrong ORDER (members out of LCS; sections) | 210 (41) | **44 (15)** |
| missing member | 191 | 168 |
| extra member | 27 | 23 |
| wrong flag READ_ONLY missing | 100 | **35** (0 before the READ_ONLY safety rule: all 35 are ambiguous primitive accessors) |
| wrong flag DONT_ENUM missing / extra | 49 / 15 | **0 / 2** |
| wrong flag `own` extra / missing (inherited vs own) | 34 / 10 | 34 / 10 |
| a VALUE differs (`type` changes among undefined/null/string/number/boolean/object) | 3 | 15 |
| SWF-version gating | n/a: the decls SWFs are **SWF15** (FP8+ visibility), so this row cannot show gating | |

What the after-residue is (all named; none is "more table"):
- **521 lines / 44 sections missing**, by cause:
  - `_listeners` arrays (`Key/Mouse/Selection/Stage._listeners.*`, 40 sections): Flash's `for (p in arr)` over a listeners
    ARRAY lists the inherited (by then unhidden) `Object.prototype` names. Our ARRAY enumerate does not walk the
    `__proto__` chain. This is a for..in mechanism (`actionEnumerate2`, ARRAY arm), not a table fact.
  - `Accessibility.updateProperties/sendEvent/isActive` (3 sections): our methods are installed **lazily** on the first
    SWF6+ access (`ensureAccessibilityMethods`, `action.c:~43822`, a Dejagnu SWF5 workaround). The eval path walk never
    triggers it.
  - `_global.o` (1): a debugger-player leftover (`o = null` on `_global`); a 1-line table stub.
- **168 missing members**: ~110 of them sit inside the missing sections or under the wrong-identity `X.toString` below.
  The remaining ~40 facts:
  - own `constructor` missing on singletons and prototypes (`Key/Mouse/Selection/Math/Stage/Accessibility/SoundCodec/
    System.capabilities`, `TextField/TextFormat/XML/XMLNode/String/Date.prototype`): ours is not an own, unhideable slot;
  - `Array.NUMERIC/…/CASEINSENSITIVE` and `String.fromCharCode`: ours exist only on a **second** `Array`/`String`
    identity built lazily by the GetVariable builtins arm (`g_array_constructor_static`, `action.c:~53170`;
    `g_string_constructor.own_props`, `~53243`). `_global.Array` is not that object;
  - `TextField.prototype.filters/sharpness/thickness/antiAliasType/gridFitType`: prototype getters we keep per instance;
  - genuinely unimplemented (inert stubs needed): `AssetCache.getDiskUsage/purge`, `RemoteLSOUsage.getURLPageSupport`,
    `Sound.prototype.checkPolicyFile/areSoundsInaccessible`, `Error.prototype.name/message` (ours: virtual),
    `RemoteLSOUsage/AssetCache/AsSetupError/Error.prototype` objects.
- **`own toString` extra on `Accessibility/Stage/Key/Mouse/Selection/Math`, `Sound.prototype`** (34 own-extra + the 6
  extra `X.toString.prototype` sections + 8-moved `broadcastMessage` sections): we give these singletons an own
  `toString`; FP32 has none (they inherit `Object.prototype.toString`). Remove = S, but it needs a guard on every
  `"" + Key` style print.
- **ASnative / ASSetNative own-props swap**: FP32 `ASnative` has NO own `__proto__`/`constructor` (empty section), while
  `ASSetNative`/`ASSetNativeAccessor` have them. Ours is the other way round (`ASSetNative` has no `own_props`).
- `Button.prototype` on-handler slots (9 extra `undefined` members), `Boolean/Number.prototype.__constructor__`
  (extra), `XML.prototype.__proto__` own (extra).

### 1.2 `global_proto_decls_delete` (a DONT_DELETE table)
The test deletes every member and prints the survivors (`, DONT_DELETE`). Lines by member class:

| class | before missing / extra | after missing / extra |
|---|---|---|
| inherited `Object.prototype` names (survive because they are inherited, or DONT_DELETE on Object.prototype) | 1158 / 42 | 489 / 66 |
| `__proto__` / `constructor` / `prototype` DONT_DELETE | 485 / 22 | 132 / 7 |
| `Testing` section lines | 143 / 99 | 57 / 20 |
| other members | 215 / 51 | 8 / 2 |

The after-residue is the same lazy/second-identity/`_listeners` objects as §1.1, plus the 2 `manufacturer` lines.

### 1.3 `global_instance_decls` (`classify_inst.py`; a per-INSTANCE table, `new X()`)
Note: this test's label `DONT_ENUM` means the key WAS enumerated (it is printed when `contains(enumerated, key)`).

| mechanism | before | after |
|---|---|---|
| DONT_DELETE missing | 244 | 259 |
| missing member | 144 | 116 |
| TYPE `function with prototype` ← `function` / inverse | 133 / 61 | **0 / 0** |
| extra member `__proto__`/`__constructor__` on instances (FP32 never lists them, even after ASSetPropFlags) | 60 | 60 |
| extra other member | 60 | 24 |
| a VALUE differs (filter instance defaults: `number/boolean/object/string ← undefined`) | 74 | 86 |
| own extra / READ_ONLY missing (`ColorTransform` instance accessors) | 33 / 20 | 33 / 20 |
| instance header differs (toString / typeof of the instance) | 11 | 11 |
| ORDER | 5 blocks | 4 blocks |

This row is the INSTANCE side of the graph, so the proto table only fixes its type column. The rest is instance
layout: what `new X()` puts on the instance (FP32: almost nothing; ours: `__proto__`/`__constructor__` visible,
`ColorTransform` own accessors, `idMap`), filter instance defaults (real gaps in `new GlowFilter()` etc.), and
instance DONT_DELETE.

### 1.4 gnash `argstest-v6/7/8`
A recursive walk that constructs each class and calls each enumerated member (`Testing m()`). Diff by line kind
(v6 after): extra `Testing <Object.prototype name>()` ≈ 99 each (ours enumerates `watch…toLocaleString` on instances
where FP32 does not), missing `Testing constructor()` 78 and `Testing __constructor__()` 76 (instance `constructor`
position), extra `Testing __proto__()` 127. **SWF-version gating is real here:** FP32 v6 ≠ v7 by 297 lines
(`constructor` enumeration position on instances moves; `System.security.allowInsecureDomain` is `undefined` in v6,
a function in v7). **Ours prints v6 == v7 except the `SWF6/SWF7` header line:** we gate none of it.

### 1.5 gnash `ExternalInterface-v8` (rm, 1 failing check, `ExternalInterface.as:265`)
`_objectToXML(new XML())` serialises a for..in. FP32 lists the XMLNode getters (`namespaceURI … attributes`), then the
XMLNode methods, then the XML.prototype members. **This confirms FP32 XML/XMLNode prototype methods are ENUMERABLE**
(the decls golden agrees: no DONT_ENUM on `XMLNode.prototype.toString` etc.; the table now sets that). The check
still fails on instance layout: ours puts `contentType, idMap, namespaceURI, …, nodeType` as **own instance** props
and `attributes` as `{}`. FP32 has them as prototype getters, `attributes` null, no `idMap`. Owner: the XML ctor
(instance layout), not the table. Price S–M, 1 rm → pass.

## 2. Table design (task 2)

### 2.1 Generator (`scripts/gen_avm1_native_table.py`, in the patch)
Input: `global_proto_decls/output.txt` (= FP32 LNX byte-for-byte), and optionally `--delete-golden
global_proto_decls_delete/output.txt` for the DONT_DELETE column. Output: `include/actionmodern/avm1_native_table.inc`.
It is a static C table, `#include`d by `action.c`, so there is no new TU (verify_output / CMake / Emscripten
untouched; `include/actionmodern` is already on every include path). Generated now: **453 object rows, 2747 member
rows**. Columns per member:

| column | source | note |
|---|---|---|
| name, FP32 for..in position | proto golden, own members of the section | only OWN members are facts of PATH |
| DONT_ENUM (bit 1) | proto golden | **unobservable** for the 11 `Object.prototype` names (bit 4 = keep ours) |
| READ_ONLY (bit 2) | proto golden | |
| DONT_DELETE known / value (bits 8/16) | `_delete` golden, own members of the same PATH | |
| type (incl. "function with prototype") | proto golden | drives `.prototype` presence on native fns |

Object identity: one object is reachable by several paths (`X.watch` IS `Object.prototype.watch`). The consumer walks
rows in golden order, resolves each PATH through the `__proto__` chain, and **skips an object it already reconciled**.
So the first visit wins, which is the clean visit, because the walk only unhides an object when it tests that object.

### 2.2 Consumer: `avm1NativeTableApply` (new, `action.c`), called as the LAST statement of `ensureGlobalInit`
A reconcile pass, not a rewrite of the ~70 `setupNativeFuncOwnProps` call sites. The per-class setup code keeps
creating the values; the table owns attributes, order and `.prototype` presence. Per row:
1. flags: DONT_ENUM / READ_ONLY / DONT_DELETE on every own member we have. Accessor slots and `PERM_READONLY`
   are left alone.
2. prototype presence: a native function member gains `.prototype` (`addNativeFuncPrototype`) or loses it
   (`prototype_obj = NULL`, `no_lazy_prototype = 1`, own `prototype` slot deleted) per the golden type. It never
   acts through `constructor`/`__proto__`.
3. `constructor` self-placeholder repair: `setupNativeFuncOwnProps` stores `constructor = func` until
   `g_function_constructor` exists. The fixup loop only rewrites the early functions, so every lazily-built native
   (System, IME, security, …) kept **`f.constructor === f`**. That is a pre-existing bug, visible as
   `type=[function]` for `constructor`. The pass rewrites it to Function, worth 128 diff lines on `global_proto_decls`
   alone (1562 → 1434 in the step-wise measurement).
4. order: own props are re-inserted in reverse FP32 order (our enumeration is LIFO). Members the table does not list
   keep their relative order and enumerate last. `objectRehashIndex` is called after the move.

Kill switches (prototype only): `SWF_NATIVE_TABLE=0` (whole pass), `SWF_NATIVE_TABLE_ORDER=0` (no reorder),
`SWF_NATIVE_TABLE_STATS=1|2` (counts / unresolved paths). Final stats: 453 rows, 217 applied, 86 aliases skipped,
150 unresolved (primitive leaves and the lazy/second-identity objects of §1.1), 46 listed members absent,
+63 / −156 `.prototype`.

**Functions touched (all in `action.c`):** `ensureGlobalInit` (one call appended at its end, plus a forward decl);
new `static` `avm1ntTargetOf`, `avm1ntResolve`, `avm1NativeTableApply`. It calls the existing
`setupNativeFuncOwnProps` and `addNativeFuncPrototype`, unchanged. No other function was edited.

### 2.3 Measured design traps (each was tried, then fixed)
- **Naive flags** (DONT_ENUM taken literally): the 11 `Object.prototype` names became enumerable everywhere:
  +2135 section-extra lines, 3985 diff lines total. Fix: bit 4 "unobservable, keep ours".
- **Prototype edits through `constructor`**: the self-placeholder made the pass give `.prototype` to the function
  itself. That added fake `X.prototype` sections (IME methods). Fix: never edit through `constructor`/`__proto__`,
  and repair the placeholder instead (§2.2.3).
- **Own-only path resolution**: the `X.watch`-style first visits of `Object.prototype` functions were unresolvable.
  `_delete` stayed at 1434; with `__proto__`-chain resolution it drops to 781.

### 2.4 SWF-version differences
The decls goldens are SWF15, so they describe the FP8+ view only. Design: **keep visibility in the existing
`flash_flags` (ASSetPropFlags version bits, `isPropertyHiddenAtVersion`) and add a `min_swf` column to the table**,
generated by diffing per-version FP32 dumps of the same walk. Those dumps do not exist yet: LOCAL ORACLE REQUEST 1
(`global_proto_decls/test.as` rebuilt as SWF 5/6/7/8). argstest v6 vs v7 (297 FP32 lines) is the corpus proof that
gating matters, e.g. `System.security.allowInsecureDomain` (v7+) and the instance `constructor` position. The pass
must not CREATE a member for a version where FP32 hides it. Attributes and order are applied at every version.

### 2.5 Members we do not implement: inert stubs?
Only ~10 FP32 members are genuinely absent from our runtime (§1.1: `AssetCache.getDiskUsage/purge`,
`RemoteLSOUsage.getURLPageSupport`, `Sound.prototype.checkPolicyFile/areSoundsInaccessible`, `_global.o`, and the
`AssetCache/RemoteLSOUsage/AsSetupError/Error` prototype objects). **Recommendation: create inert stubs (a native
no-op function, or the listed primitive) for exactly these, version-gated by `min_swf`.** Do not stub "missing"
members whose real cause is lazy or second-identity: fix the identity (§3, M2). Every corpus row that probes those
names (`grep` over all goldens, excluding the 3 decls rows and argstest):

| name | rows that probe it | risk |
|---|---|---|
| `getDiskUsage` | `avm1/asnative_instrument`, `avm1/shared_object_members_swf5` | a typeof/enum probe; must be in the wave-2 guard |
| `getURLPageSupport` | `avm1/asnative_instrument` | same |
| `checkPolicyFile` | gnash `Sound-v5/6/7/8` | v5/v6 must keep it `undefined` (min_swf) |
| `areSoundsInaccessible` | none | free |
| `updateProperties` (lazy, not missing) | gnash `Accessibility-v5/6/7/8` | the SWF5 hide is why it is lazy; min_swf replaces the lazy hack |
| `fromCharCode`, `CASEINSENSITIVE` (second identity) | gnash `String-v5..8`, `array-v6/v8` (fp subtests) | identity merge, not a stub |

## 3. Wave-2 pricing (task 4)

Where the `global_proto_decls` after-lines go (LCS opcode attribution by section; measured on the 878-line build before the READ_ONLY rule. The +42 from that rule are 35 READ_ONLY-missing members (`System.exactSettings/useCodepage`, `XML/XMLNode.prototype` node getters, `MovieClip.prototype` getters) plus their cascade. Wave 2 recovers them with oracle 2, by modelling them as accessors):

| bucket | lines | mechanism, owner | size |
|---|---|---|---|
| `Key/Mouse/Selection/Stage._listeners.*` | **524** | ARRAY for..in never walks `__proto__` (`actionEnumerate2` ARRAY arm, `action.c:~56872`). FP32 lists enumerable inherited names on arrays (the AS2 `Array.prototype.foo` gotcha). Plus `_listeners` carries an own `constructor` in FP32 | M: Flash-correct, but it touches every for..in over an array, so it needs a wide guard |
| own `toString` on `Accessibility/Stage/Key/Mouse/Selection/Math`, `Sound.prototype` | 78 | drop the own slot (FP32 inherits `Object.prototype.toString`) | S |
| `broadcastMessage`/`clearTimeout` sections out of order | 72 | shared fn objects (`g_ab_*`) whose sections are visited through several paths. The order follows from the `toString` and `_listeners` rows above | falls out of the two rows above |
| Accessibility | 43 | lazy SWF6+ method install (`ensureAccessibilityMethods`) → eager + `min_swf` | S, after the oracle |
| ASnative / ASSetNative | 33 | own-props swap (`ASnative` has none in FP32) | S |
| per-class smalls (XML 28, Stage/Key/Mouse/Selection/Math own `constructor` 14 each, Button 9, Error 7, TextField 6, …) | ~130 | unhideable own `constructor`; the `Array`/`String` second identity (GetVariable builtins arm, `~53170`/`~53243`); `TextField.prototype` getters; ~10 inert stubs (§2.5); `Button.prototype` handler slots | M in total |

Wave-2 slots (sizes include the guard runs):
- **W2-a (S–M), land the table pass.** The patch as measured: generator, `.inc`, `avm1NativeTableApply`, the
  constructor-placeholder repair. Drop the env kill switches or keep `SWF_NATIVE_TABLE=0` only. Rows that move
  Flash-ward: all 6 measurable owned rows (§1). **Flips: 0.** It is still worth landing: 3,000+ lines move
  Flash-ward, and it fixes the real `f.constructor === f` bug and the `.prototype` presence on ~300 natives. The
  sweep shows 0 losses (§4). It also makes `XMLNode`/`XML` prototype methods enumerable (FP32, confirmed by the
  EI-v8 golden), which is game-visible for any `for (k in xmlNode)`.
- **W2-b (M), ARRAY for..in proto walk.** About 524 + ~160 (`_delete`) lines. It must be guarded across every avm1/
  gnash row with an array for..in.
- **W2-c (S), singleton cleanups**: own `toString` drop, ASnative/ASSetNative swap, `_global.o`, inert stubs.
- **W2-d (M), identity merge**: one `Array`/`String` ctor object (GetVariable builtins arm == `_global` property),
  eager Accessibility with `min_swf`.
- **W2-e (M–L), instance table** from `global_instance_decls` (2nd generator input). Contents: hidden instance
  `__proto__`/`__constructor__`, XML instance layout (`attributes` null, no `idMap`, node getters on the prototype),
  filter-instance defaults, instance DONT_DELETE. It owns `ExternalInterface-v8` (1 check, **the only rm → pass in
  reach**, ~S–M once the XML instance layout is right) and most of `global_instance_decls` and argstest.
- **W2-f (needs FP32 data)**: the `min_swf` column (oracle 1) and the two unobservable columns (oracle 2).

**Exact residue per row after all of W2-a..f** (best estimate):
- `global_proto_decls`: ~0–10 (value-type lines on prototype getters, e.g. `XMLNode.prototype.nodeValue` null vs
  undefined). A flip is plausible only after W2-a+b+c+d. **L in total.**
- `global_proto_decls_delete`: 2 lines (`manufacturer`, FP32 run-to-run), so it needs the §5 disposition to pass.
- `global_instance_decls`: 1 TZ line (`mock_timezone`) + 1 trailing-blank line (harness) after W2-e. **L.**
- `argstest-v6/7`: 2 lines (`manufacturer`) after W2-a..f. argstest-v8 is FP32-untestable on LNX (dialog); its golden
  is a WIN run. **L+ (the hardest rows; version gating + instance layout + call results).**
- `ExternalInterface-v8`: 0 after W2-e's XML part.

## 4. Guard sweep, before/after, every move by name (task 3)

Argued set (76 rows; "before" = `SWF_NATIVE_TABLE=0`, which is byte-identical to `origin/master`). Every row
enumerates natives, tests `typeof`/`hasOwnProperty`/`ASSetPropFlags` on builtins, or reads a member whose attributes
the table changes:
- **avm1 (42):** `array_enumerate`, `as_set_prop_flags`, `as_set_prop_flags_version{,_swf5,_swf6,_swf8}`,
  `as_setup_error`, `asnative`, `assetnative`, `assetnativeaccessor`, `enumerate`, `extends_native_type`,
  `global_array`, `global_is_bare`, `global_swf5_6_7_8_9`, `global_swf6_7_8`, `globals_swf5..8`, `globals_monkeypatch`,
  `is_prototype_of`, `lazy_prototype_shared`, `native_double_construct`, `native_objects_swf6/7/8`,
  `native_subclasses`, `object_prototypes`, `primitive_type_globals`, `prototype_delete`, `prototype_enumerate`,
  `prototype_properties`, `recursive_prototypes`, `stage_object_enumerate`, `swf5/6/7_global_funcs`, `typeof`,
  `typeof_globals`, `text_format_prototype_lazy`, `xmlnode_proto`.
- **regression (4):** `avm1_array_native_own_method`, `avm1_mc_super_native_probe`, `avm1_xml_first_action_proto`,
  `avm1_xmlnode_first_action_proto`.
- **gnash actionscript.all (30):** `Global-v5/v6/v8`, `Object-v6/v8`, `Function-v6/v8`, `Key/Mouse/Stage/Selection/
  System/Math/Accessibility/AsBroadcaster/enumerate/delete/TextField-v8`, plus a second set after the READ_ONLY
  finding: `MovieClip/XMLNode/XML/Sound/String/array/Number/Color/Date/Boolean/Error-v8`, `Accessibility-v6`.
- The 64 first-set before-leg statuses equal the CI baseline `results_graphics.json` exactly (0 differ), so local
  grading is CI-grade for these rows.

**Result (final code, 76 rows): 0 moves.** 67 pass → pass, 8 rm → rm (`Object-v6/v8`, `Stage-v8`, `Math-v8`,
`TextField-v8`, `XML-v8`, `array-v8`, `Date-v8`), 1 mm → mm (`avm1/globals_monkeypatch`, 49/306 both legs). The
matching-line counts are identical on every row. Per-row TSV: `w1-native-table-gen/sweep_results.tsv`.

**Loss caught and fixed during the sweep (priced):** the first-pass table (READ_ONLY applied to every primitive
member) moved gnash **`System-v8` pass → mismatch** (2 checks: `System.exactSettings = true`, `System.useCodepage =
true`, `System.as:138/159`). FP32's `READ_ONLY` there means "a coercing accessor turned 'OTHER' into `true`", not
"non-writable". The final generator marks READ_ONLY unobservable for boolean/string/undefined/null members
(attr 32). That costs +42 lines on `global_proto_decls` and +24 on `global_instance_decls`, which wave 2 recovers
with oracle 2. The first 64-row sweep (pre-fix) had no other move.


## 5. Dispositions / doc edits (for the coordinator)
- **`System.capabilities.manufacturer` (FP32 run-to-run).** The golden `_delete`/argstest-v6/v7 (older FP32 captures)
  put `manufacturer` after `os`. The s30 fresh LNX capture puts it after `language`, which is the order of the
  `global_proto_decls` capabilities section (both captures) and our order under the table. Proposed ACCEPTED entry:
  "FP32 enumeration position of the host-string member `System.capabilities.manufacturer` varies between FP32
  captures (2 lines per row: `global_proto_decls_delete`, gnash `argstest-v6/7`). We emit the fresh-capture order." A
  flash_fixes swap to the fresh LNX capture is a candidate, but only after a 3rd capture shows which order is
  modal. Request 3 below.
- `ignored_tests.txt:196–203` comment: append "s30 w1-native-table: generated-table prototype measured, 2593→920 /
  2215→781 / 1073→767 lines. Residue owners: ARRAY for..in proto walk, instance layout, lazy/second-identity natives."
- gnash `actionscript.all/ignored_tests.txt:25` (argstest): add "FP32 gates by SWF version here (v6 ≠ v7 by 297
  lines). Ours does not."

## 6. Refutations
1. "The golden IS the table, a generator can read `output.txt` directly": **partly refuted.** Three columns are
   test-contaminated. (a) DONT_ENUM is unobservable for the 11 `Object.prototype` names, because `enumerated = {}`
   inherits them. (b) READ_ONLY is ambiguous for every primitive member: it is a constant, a coercing native accessor
   (`System.exactSettings`: 'OTHER' → `true`), or a prototype getter whose setter no-ops (`MovieClip.prototype.
   blendMode`). The first sweep caught (b) as a **real regression**: gnash `System-v8` pass → mismatch (2 checks,
   `System.exactSettings = true` / `useCodepage`). It was fixed before the final sweep. (c) The type column is a
   VALUE read through the getter with this = prototype, not a slot type. The generator marks (a) and (b) "keep ours"
   (attr bits 4 and 32).
2. "`manufacturer` position (2 lines) is a residue to match": refuted. FP32 is run-to-run, and we now match the fresh
   capture (§0, §5).
3. Register §1a "≈470 lines `.prototype` presence": confirmed and closed by the prototype (519 → 8 type lines).
   "≈90 READ_ONLY": closed (100 → 0). "≈61 `_global` DONT_ENUM": already closed by s29 L5. "≈700 missing members":
   **mostly refuted as missing.** ~600 of the after-residue lines are mechanisms (ARRAY for..in, lazy and second
   identities, own-`toString`). Only ~10 members are truly unimplemented.
4. The EI-v8 "remainder is native enumeration": confirmed for the prototype half (XML/XMLNode prototype methods are
   ENUMERABLE in FP32; the table now sets that). The failing check itself is **instance layout** (own node props on
   the instance, `idMap`, `attributes = {}`), owner the XML ctor, not the table.

## 7. New unclaimed leads
- **L1 (M, Flash-correct, game-visible): ARRAY for..in must walk the `__proto__` chain** (`actionEnumerate2` ARRAY
  arm). It is 524 lines of `global_proto_decls` alone. Any AS2 game that extends `Array.prototype` and runs
  `for (k in arr)` diverges today.
- **L2 (S, real bug): `f.constructor === f` for every native built after `g_function_constructor`'s fixup loop**
  (System/IME/security/… methods). Fixed in passing by the prototype pass. A standalone fix belongs in
  `setupNativeFuncOwnProps`: store a lazy marker and resolve to Function at read.
- **L3 (M): two identities for `Array` and `String`.** `GetVariable "Array"` returns `g_array_constructor_static` (with
  the sort constants); `_global.Array` is another object without them. Same for `String.fromCharCode`.
  `_global.Array.NUMERIC` is probably `undefined` today: probe it.
- **L4 (S): instance `__proto__`/`__constructor__` are listed by for..in after `ASSetPropFlags(inst, null, 0, 1)`.**
  FP32 never lists them (60 lines in `global_instance_decls`, plus most `Testing __constructor__()` lines in argstest).
- **L5 (M): filter instances built with `new XFilter()` have `undefined` defaults** where FP32 has numbers/booleans/
  arrays (86 lines in `global_instance_decls`).

## LOCAL ORACLE REQUESTS
1. **FLASH, trace, direct, 1 frame: `avm1/global_proto_decls` and `_delete` at SWF 5, 6, 7 and 8.** The corpus SWFs
   are SWF15. The SWFs are BUILT and shipped: `w1-native-table-gen/fixtures/{global_proto_decls,global_proto_decls_delete}.v{5,6,7,8}.swf`.
   They are the corpus bytecode with the header version byte changed (v6–8 CWS, v5 FWS). v5 is best-effort: the test
   uses `===`/`!==` (StrictEquals is SWF6+), so a v5 run may print a degraded table. That is still useful for
   presence. LNX; `--log-warnings` for `_delete`. Purpose: the `min_swf` column (§2.4).
2. **FLASH, trace, direct, 1 frame: an "unobservable columns" probe.** For every object in the golden walk, print
   `obj.isPropertyEnumerable(k)` for the 11 `Object.prototype` names, and for every primitive member a write-probe
   that distinguishes a constant from an accessor (`ASSetPropFlags(obj, k, 0, 4)`, then write a value of the SAME
   type, read back, restore). The fixture is to be written in wave 2 (MTASC, SWF8). Asked now so the request is on
   the books. If the coordinator prefers, wave 2 writes it and the request moves to wave 2.
3. **FLASH, trace, direct: 2 more LNX captures of `avm1/global_proto_decls_delete`** to settle the modal
   `capabilities.manufacturer` position before any flash_fixes swap (§5).
