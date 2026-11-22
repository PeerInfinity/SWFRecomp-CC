# w2-textformat-ctor: TextFormat construction fidelity (wave 2, implementation)

**NEW files on this branch:**
- `SWFRecompDocs/plans/session24-fanout-reports/w2-textformat-ctor-report.md` (this file)
- `SWFRecompDocs/plans/session24-fanout-reports/w2-textformat-ctor.patch`, which is `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`. The only file it touches is `SWFModernRuntime/src/actionmodern/action.c`. There are no new fixture dirs and no recompiler change.
- `SWFRecompDocs/plans/session24-fanout-reports/w2-textformat-ctor-probe/mkprobe.py`: a hand-assembled probe generator for §2. It is not a fixture; see LOCAL ORACLE REQUESTS.

Base: origin/master `9c86e930` (code = `ee02076de`). Upstream test download: Ruffle master `bcac30c19` (`avm1 from_gnash`, plus `visual text fonts` for the canary). Box: cloud, Dawn on lavapipe, SETUP_STATUS all OK.

## Verdicts

| Item | Verdict | Flip |
|---|---|---|
| `avm1/text_format_get_text_extent_own` | **GO, landed.** 10/19 → **19/19 PASS** (graphics and no-graphics) | **+1** |
| `avm1/text_format_prototype_lazy` | Improved **16 → 32 of 35** matched lines, the predicted ~32/35. **NOT a flip.** The last 3 lines need the accessor model (w1-native-proto §2.3 (1), L, out of scope, not attempted) | 0 |
| Lead 2, the unexplained `own=undefined` | **Root-caused and fixed.** It is not an `actionCallMethod` dispatch bug. TextFormat.prototype had **no `__proto__`** (details in §2). The same bug hits XML and XMLNode. Fixed for TextFormat, XMLNode (which covers XML) and StyleSheet | 0 corpus flips beyond the headline; XML/XMLNode priced in §2 |
| Native `super()` into TextFormat, with the full 13-argument conversion | **Landed** (shared helper with the `new` path) | part of the two rows above |
| Array as `TextFormat.prototype` | **Landed** (`text_format_prototype_lazy` line 16 now matches) | part of the above |

## EXPECTED-FLIP LEDGER (coordinator: check CI against this)

**Trace axis:**
- `avm1/text_format_get_text_extent_own`: output_mismatch → **pass** (+1).
- `avm1/text_format_prototype_lazy`: stays output_mismatch. Matched lines go 16 → 32 of 35. Do **not** book it as a pass.
- Everything else: **no movement.** The 15 rider rows I A/B'd that are not passing are byte-identical before and after (actual-output md5, §4). The 25 rider rows that pass stayed passing.
- Do not book these as my yield. `avm1/lazy_prototype_shared` (pass) and `avm1/stylesheet_load` (pass) fail in the s24 baseline JSON (`ff2e2e9d6`) but already pass on clean master `ee02076de`, because `336749f14`/`ee02076de` fixed them.

**Pixel axis:** no movement expected. The render canary subset was **58/58 PNG md5-identical**, with no trace or image status change (§5).

## 1. What changed (all in `SWFModernRuntime/src/actionmodern/action.c`)

A new block of `static` helpers sits right after `initTextFormatPrototype` (≈ :19160–19375). It mirrors Ruffle's `text_format.rs` `constructor`, `define_instance_properties` (`674bee2d8`) and `define_lazy_proto_properties`.

- **`textFormatInstallGetTextExtent`** gives each object its own `getTextExtent`. It is a **fresh** native `ASFunction` per object, built the same way as `newBroadcastMessageFunc`: `calloc`, then `actionGcLinkFunction`, then `setupNativeFuncOwnProps`. It is stored as an ordinary own property (enumerable, writable, deletable), so `a.getTextExtent !== b.getTextExtent`. The old single static `g_textformat_fn_getTextExtent` is deleted.
- **`textFormatConvertCtorArgs` / `textFormatStoreCtorArgs`** form the shared 13-argument conversion. It converts first and stores second, as Ruffle does, so the `toString`/`valueOf` side effects happen even when nothing is stored. Compared with the old `new`-path loop, the only behaviour change is for **object** arguments:
  - `font`, `url` and `target` now go through `toString` (`tfCoerceString`). Ruffle uses `coerce_to_string`. The old code stored the object raw.
  - `size`, `leftMargin`, `rightMargin`, `indent` and `leading` now go through `valueOf`. Ruffle uses `coerce_to_i32`. A NaN result becomes -2147483648. The old code stored the object raw.
  - Primitive arguments keep exactly the old coercions: font truncated to 64 characters, `atof` plus truncation, uint32 color, booleans, validated align.
- **`textFormatLinkProto`** resolves the **current** `TextFormat.prototype`, links `__proto__` (DONTENUM, as before) and defines the lazy fields there. The prototype is either `prototype_obj` or an **ARRAY** stored in the constructor's `own_props` (the function-`prototype` SetMember arm puts non-objects there). For an ARRAY prototype, the fields go into the array's non-index bag and the instance `__proto__` keeps the ARRAY type. This is the same treatment `336749f14` gave Video.
- **`textFormatConstructNew`** builds `new TextFormat(...)`. The `actionNewObject` arm (≈ :60758) is now 3 lines that call it.
- **`textFormatConstructSuper`** handles native `super()` into TextFormat. The `invokeNativeSuperConstructor` arm (≈ :64345) replaces the old "store the first 6 args raw" code. It always converts the arguments. If `this` has `native_type == NATIVE_NONE`, it becomes NATIVE_TEXTFORMAT, the lazy fields are defined on `this.__proto__` (object or array), and the instance fields plus its own `getTextExtent` are set and stored. If `this` is already native (a TextFormat, a Date, or an Array, whose super-`this` is `arr->props`, already tagged NATIVE_ARRAY) it stores nothing and defines nothing.
- **`createTextFormatFromField`**, used by `getTextFormat`/`getNewTextFormat`, is now a thin wrapper around the renamed `…Impl`. The wrapper sets `NATIVE_TEXTFORMAT` (it was never set before) and installs the own `getTextExtent`. Ruffle does the same: `text_field.rs` `new_text_format` calls `define_instance_properties`. `createBlankTextFormat` (`StyleSheet.transform`) is left alone, as in Ruffle.
- **The `__proto__` link fix (§2)** is in `initTextFormatPrototype`, the XMLNode prototype in `initXMLPrototype`, and `initStyleSheet…`. Each now uses `getObjectPrototype(app_context)` instead of `if (g_object_prototype != NULL)`.

## 2. Lead 2 bisected: `own=undefined` was an unlinked prototype, not a lost dispatch

**Method.** I built an ASan/-g binary of the headline test and stepped `actionCallMethod` in gdb from the `hasOwnProperty` call in `where()`. The path is: method lookup loop (:71245) → `getProperty(obj, method)` misses → `getProperty(obj, "__proto__")` returns **NULL** → break → `__resolve` miss → `pushUndefined` (:71471). `builtin_object_hasOwnProperty` is never reached because the method is never found.

**Mechanism.** `initTextFormatPrototype` linked `TextFormat.prototype.__proto__` only `if (g_object_prototype != NULL)`.
- The test's first action is `GetVariable("TextFormat")` (as part of `TextFormat.prototype`). That reaches the lazy builtin init at `actionGetVariableImpl` (:47662, `bt` confirmed) **before global init has created Object.prototype**: gdb showed `g_object_prototype == 0x0` there.
- So TextFormat.prototype had no `__proto__`, and nothing reachable through a TextFormat inherited from Object.prototype.
- The w1 top-level probe (`mktfx.py`) worked only because its first action was `new TextFormat`, which builds Object.prototype first.
- DefineFunction2, register storage and the receiver kind are all irrelevant.

**Other native types.** I probed each with a hand-assembled SWF whose **first action** is `typeof X.prototype.hasOwnProperty` and `X.prototype.hasOwnProperty("zz")` (`w2-textformat-ctor-probe/mkprobe.py`). No-graphics results:

| X | before | after |
|---|---|---|
| TextFormat | undefined / undefined | function / false |
| **XML** | undefined / undefined | function / false |
| **XMLNode** | undefined / undefined | function / false |
| TextField.StyleSheet | ok | ok. Same code pattern, fixed defensively: its first GetMember on `TextField` creates Object.prototype first |
| Date, Sound, Color, LoadVars, TextField, MovieClip | ok | ok |

**Price of the XML/XMLNode half.** It is real, but it is **0 corpus rows**. Every XML/XMLNode row I ran (avm1 `xml`, `xml_inspect_createmethods`, `xml_parent_and_child`, `xmlnode_proto`, gnash `XML-v6..v8`, `XMLNode-v6..v8`, regression `xml_onload_type1_args`) produces byte-identical output before and after, because all of them construct or touch Object.prototype before the first XML reference. A grep over the three local `if (g_object_prototype != NULL)` sites shows no other prototype initializer with this shape. `createSecondaryObjectPrototype` is intentionally standalone.

## 3. Headline before/after (same box, clean origin/master vs patch, graphics)

| Test | before | after |
|---|---|---|
| avm1/text_format_get_text_extent_own | output_mismatch 10/19 | **pass 19/19** (also passes under no-graphics) |
| avm1/text_format_prototype_lazy | output_mismatch 16/35 | output_mismatch **32/35** (no-graphics: same 3-line diff) |

**What fixed which lines in `text_format_get_text_extent_own`:**
- Lines 1–3 and 7–9 (`own=undefined`): the §2 fix.
- Line 4 (same function): fresh function per object.
- Lines 7–8: getTextFormat/getNewTextFormat now install `getTextExtent`.
- Lines 9, 13 and 16: native `super()` now installs it on a non-native `this`.
- Lines 14, 15, 17 and 18 still hold: it installs at most once per object, and never on a Date or an Array.

**`text_format_prototype_lazy` remaining diff.** These are exactly w1-native-proto §2.3 (1), the accessor model:
```
-    4  deleted font, new again: ... | c.font=undefined        +  ... | c.font=Arial
-    6  swapped back to p0, new: ... | e.font=undefined        +  ... | e.font=Arial
-    7  swapped to p1 again (font deleted), new: ... | f.font=undefined   +  ... | f.font=Arial
```
- Line 16 (Array prototype) now matches.
- Lines 20–34 (super conversion side effects: `font.toString()` / `size.valueOf()` called for plain, TextFormat, Date and Array receivers, and the prototype defines only for the plain one) now match.

## 4. Rider sweep (40 rows plus regression), graphics

**How I ran it.** First, the after-leg for all rows. Then, for every row that was not passing, a same-box A/B: `git diff > p.patch; git apply -R`, run, re-apply. Both legs used `--json` + `--save-actual`, and I compared the md5 of the actual output.

**Rows whose status is pass in both the baseline JSON and the after-leg** (25):
- avm1 `text_format`, `text_format_display`, `text_format_font_max_length`, `text_format_get_text_extent_undefined_width`, `text_format_rounding_swf7/8`, `textfield_get_text_format_args`, `textfield_set_text_format_args`, `textfield_set_text_format_text_change`, `edittext_default_format`, `edittext_default_format_empty`, `edittext_default_format_font_style`, `edittext_stylesheet` (trace and image pass), `stylesheet`, `stylesheet_transform`, `native_objects_swf7/8`, `native_subclasses`, `xml`, `xml_inspect_createmethods`, `xml_parent_and_child`, `xmlnode_proto`.
- gnash `TextFormat-v5`, `TextFormat-v6`.
- regression `xml_onload_type1_args`.

**Pass after, but not my yield** (master fixes since the baseline): `lazy_prototype_shared` and `stylesheet_load`.

**Regression suite near the change:**
- `xml_onload_type1_args`, `lv_cross_swf_version` and `avm1_parent_child_text` (image) pass.
- The 7 `regression/` members of the render canary are identical.

**A/B rows (actual-output md5 identical before and after, so no movement):**

| Row | status | matched/expected |
|---|---|---|
| gnash TextField-v6 / v7 / v8 | output_mismatch | 467/545, 476/570, 478/571 |
| gnash TextFormat-v7 / v8 (KF) | ruffle_matched → ruffle_matched | 136/174, 136/172 |
| gnash argstest-v6 / v7 | output_mismatch | 84/2192, 78/2061 |
| gnash XML-v6 / v7 / v8 (KF) | ruffle_matched | 483/486, 483/486, 462/465 |
| gnash XMLNode-v6 / v7 / v8 (KF) | ruffle_matched | 204/207 ×3 |
| avm1 global_instance_decls (ignored) | output_mismatch | 20/758 |
| avm1 native_objects_swf6 | output_mismatch | 114/115 |

No known-failure row moves pass → ruffle_matched. TextFormat-v5 and v6 stay **pass**.

**Why `getTextExtent` visibility doesn't move the remaining rows.** Ruffle's `674bee2d8` touched the sidecars of `TextFormat-v7/v8`, `argstest-v6/v7` and `global_instance_decls`. Ours stay byte-identical. Their remaining diffs are elsewhere (the accessor model, the args-dump shape, the ignored decls table), so these rows are not near a flip from this change.

**Mode parity.** No `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS` arm is touched. The headline rows were also run in no-graphics, with results identical to graphics.

## 5. Graphics canary

- Ran `render_canary.py capture` (before and after) over the **text-relevant subset** of `render_canary_tests.txt`: every `avm1/`, `regression/`, `visual/edittext/`, `visual/fonts/`, `text/` and `fonts/` member. That is 28 unique tests (the list has `visual/fonts/leading_device_font` twice) and 58 comparisons.
- `compare`: **IDENTICAL 58, DIFFERS 0, APPEARED/VANISHED/NO_RENDER 0, no trace or image status changes.**
- The other canary members (avm2, shumway, filters, cache_as_bitmap, shapes and so on) were not run. Their categories were not downloaded, and this change does not affect any AVM2 or render path: it is a pure AVM1 TextFormat / XMLNode / StyleSheet object-model change.
- No canary member was appended. The change class is trace-only, and the headline trace row covers it.

## 6. Refutations and corrections to prior reports

- **w1-avm1-tail §3 / lead 2** said "the dispatch that is lost is in `actionCallMethod` for a register-held NATIVE_TEXTFORMAT receiver inside a function". That is **refuted**. The receiver kind, the register and the DefineFunction2 are irrelevant. The variable that matters is whether Object.prototype existed when `TextFormat` was first named. Plain `TextFormat.prototype` (not native) failed the same way.
- **w1-native-proto §2.3 (2)** said "on an already-native `this` (TextFormat, Date or Array)". For an Array, our super-`this` is `arr->props` (`actionCallMethod` :71647), which `initArrayProto` tags NATIVE_ARRAY. So the `native_type != NATIVE_NONE` guard is correct for all three, and no ASArray is ever misread as an ASObject.

## Not finished / HOLD

- **`text_format_prototype_lazy` lines 4, 6 and 7: the accessor model.** HOLD, L, as w1-native-proto §2.3 (1) says. The completion mechanism is unchanged: fields become native data behind accessors on the prototype, or the narrower read-time check w1 describes. Out of scope for this slot.
- **The XML/XMLNode first-reference fix has no regression fixture.** Its expected output needs an outside oracle; the request is below. The probe generator is checked in under `w2-textformat-ctor-probe/`.

## New unclaimed leads

- **The `new TextFormat(obj)` object-argument coercion is now Ruffle-shaped** (font/url/target via `toString`, numeric fields via `valueOf`). No corpus row measures `new` with object arguments; only the `super()` rows do. If the Flash oracle (below) disagrees, the change is local to `textFormatConvertCtorArgs`.
- **Same-shape audit (S).** Any lazily-initialized builtin prototype that GetVariable can reach before global init should link through `getObjectPrototype()`. I found and fixed 3 sites (TextFormat, XMLNode, StyleSheet). Other initializers that read `g_object_prototype` directly may hide the same bug for other first-action shapes; a grep for `g_object_prototype` reads inside `init*Prototype` is the check.

## LOCAL ORACLE REQUESTS

1. **Flash/Ruffle trace for the first-action prototype-link probes.** Run `python3 SWFRecompDocs/plans/session24-fanout-reports/w2-textformat-ctor-probe/mkprobe.py <outdir>`. It writes `probe_<X>/test.swf` (SWF8, 1 frame) for X = TextFormat, XMLNode, XML, Date, Sound, Color, StyleSheet, LoadVars, TextField, MovieClip.
   - I need the trace of `probe_XML`, `probe_XMLNode` and `probe_TextFormat` from the Ruffle exporter (or Flash).
   - Expected: `X.prototype hOP typeof: function` / `X.prototype.hOP(zz): false`.
   - If it confirms, promote `probe_XML` and `probe_XMLNode` into `regression/` with that output. The generated `output.txt` is that prediction and is NOT oracle-verified.
2. **Optional: `new TextFormat({toString:..}, {valueOf:..})` stored values.** Check `typeof tf.font` / `tf.font` / `tf.size` against Flash, to confirm the object-argument coercion on the `new` path (lead 1).
