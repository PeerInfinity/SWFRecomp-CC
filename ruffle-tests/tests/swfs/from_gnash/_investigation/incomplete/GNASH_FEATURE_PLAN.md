# Gnash Failing Tests by Feature Category
<!-- TESTS: ASnative-v5, ASnative-v6, ASnative-v7, ASnative-v8, AsBroadcaster-v6, AsBroadcaster-v7, AsBroadcaster-v8, BitmapData-v8, ContextMenu-v7, ContextMenu-v8, ExternalInterface-v6, ExternalInterface-v7, Global-v6, Global-v7, Global-v8, HitTest-v6, HitTest-v7, HitTest-v8, Instance-v5, Instance-v6, Instance-v7, Instance-v8, LoadVars-v6, LoadVars-v7, LoadVars-v8, Matrix-v6, Matrix-v7, Matrix-v8, MovieClip-v5, MovieClipLoader-v7, MovieClipLoader-v8, Number-v5, Number-v6, Number-v7, Number-v8, Rectangle-v8, Sound-v6, Sound-v7, Sound-v8, String-v5, String-v6, String-v7, String-v8, TextFormat-v5, TextFormat-v6, TextFormat-v7, case-v6, toString_valueOf-v5, toString_valueOf-v6, toString_valueOf-v7, toString_valueOf-v8, with-v5, with-v6, with-v7, with-v8 -->
<!-- PASSING (removed from TESTS): Point-v8 (ruffle_matched, 2026-04-14), TextSnapshot-v6/v7/v8 (pass), delete-v5..v8 (pass), enumerate-v6..v8 (pass), Camera-v6/v7/v8 (ruffle_matched), Microphone-v6/v7/v8 (ruffle_matched), Sound-v5 (ruffle_matched), case-v7/v8 (ruffle_matched), targetPath-v6/v7/v8 (ruffle_matched), System-v5/v6/v7/v8 (pass, 2026-04-14 session 3) -->

<!-- PLAN_META
id: GNASH_FAILING_BY_FEATURE
status: incomplete
phases:
  - id: 1
    name: "Near-passing fixes (ops, Math, NetStream, Error, Color)"
    status: complete
  - id: 2
    name: "Prototype and constructor fixes"
    status: complete
  - id: 3
    name: "Medium-effort feature work (delete, toString_valueOf, Number, etc.)"
    status: in_progress
  - id: 4
    name: "Large features (ASnative, String regex, With auto-boxing)"
    status: not_started
dependencies: []
blockers: []
-->

Last updated: 2026-04-17 (Phase 3 in progress — objectCallValueOf type 1 `this` context fix)

## 2026-04-17 session (objectCallValueOf type 1 `this` + scope setup)

Matched `objectCallValueOf` to `objectCallToString`'s type 1 handling in
`SWFModernRuntime/src/actionmodern/action.c`. Previously, the FUNCTION path
in `objectCallValueOf` called `simple_func(app_context)` without setting
`this` on `g_this_stack`, without pushing captured scopes, and without
`switchToFunctionVersion` / `base_clip` context. This broke custom valueOf
invoked through implicit coercion (e.g., `obj == primitive`, `+ obj`,
arithmetic on objects with user-defined valueOf). The type 1 branch is
hit whenever a user-defined function (not a builtin) was assigned to
`obj.valueOf` in code compiled as a SWF5-style DefineFunction.

**Fix:** wrap the FUNCTION dispatch with the same setup/teardown used by
`objectCallToString`: save/restore `g_current_context`, SWF version,
global, movie index, `g_current_executing_func`; push captured WITH
scopes into `scope_chain`; and for type 1, push `this=obj` onto
`g_this_stack` around the `simple_func` call.

**Impact (diff-line deltas, per local run at 2026-04-17):**
- toString_valueOf-v5: 47 → 44 diffs (-3)
- toString_valueOf-v6: 14 → 11 diffs (-3)
- toString_valueOf-v7: 15 → 13 diffs (-2)
- toString_valueOf-v8: 15 → 13 diffs (-2)
- Rectangle-v8: 26 → 24 diffs (-2)
- Matrix-v6: 31 → 29 diffs (-2)

No tests cross the pass threshold from this fix alone. No regressions on
avm1 (`string_coercion`, `mutable_this`, `this_scoping`,
`textsnapshot_available_text`, `register_class_return_value`, `enumerate`,
`as2_super_and_this_v6`, `swf5_no_closure`) or Gnash
(`Color-v5..v8`, `ColorTransform-v5..v8`, `Error-v5..v8`, `Point-v5..v8`,
`Matrix-v7/v8`, `Number-v6/v7/v8`) checked locally. Remaining
toString_valueOf failures involve MovieClip + string coercion (`y == _level0.mc1`)
and implicit toString dispatch from `+` operator — separate issue from
this valueOf dispatch path.

## 2026-04-15 session 2 (primitive auto-boxing + convertFloat FUNCTION valueOf)

Two fixes in `SWFModernRuntime/src/actionmodern/action.c`:

1. **Primitive auto-boxing in actionGetMember** — When GetMember receives a
   primitive number (F32/F64) or boolean, look up properties on
   Number.prototype / Boolean.prototype via `getPrimitiveWrapperProto()`.
   Handles Flash's auto-boxing semantics: `var a = 1; typeof(a.toString)`
   returns 'function', `a.__proto__` returns Number.prototype. Previously
   returned undefined for all property access on primitives.

2. **convertFloat FUNCTION valueOf dispatch** — The OBJECT/FUNCTION/ARRAY
   valueOf dispatch in `convertFloat` was missing a FUNCTION handler. When
   `STACK_TOP_TYPE == ACTION_STACK_VALUE_FUNCTION`, `obj` was NULL, so
   custom valueOf on function objects was never invoked during toNumber
   coercion (e.g., `obj = function(){}; obj.valueOf = function(){ return 9 };
   toNumber(obj)` returned NaN instead of 9). Now sets `obj = fn->own_props`.

**Impact on Number tests:**
- Number-v7: 9→4 failures (5 lines fixed: 3 auto-boxing + 2 valueOf dispatch)
- Number-v8: 9→4 failures (5 lines fixed)
- Number-v6: 15→8 failures (7 lines fixed)
- Number-v5: 21→14 failures (7 lines fixed)

Remaining 4 per-test failures are float precision (last-digit rounding at
e-308 and e-6). C's `%.14e` and Flash disagree on the 15th sig digit for
`0x0008E0A3A2DE80EB` — C produces `1.23456789123456e-308` while Flash
produces `1.23456789123457e-308`. The exact double has its 16th sig digit
at `4`, but Flash rounds up. This is likely a difference in the
double-to-string algorithm (David Gay's dtoa vs glibc snprintf).

**Broader impact:** ~2 lines improved across AsBroadcaster, Instance,
Rectangle, ContextMenu, HitTest, Matrix, TextFormat, and other tests that
access `__proto__` or methods on primitive values.

No regressions on avm1 suite (string_coercion, mutable_this, this_scoping,
textsnapshot_available_text, global_is_bare, enumerate, array_enumerate,
register_class_return_value, text_format, add, as2_super_and_this_v6,
swf5_no_closure, set_interval, goto_frame, unload, selection).
No regressions on misc-mtasc (function_test, exception, inheritance, hello).

## 2026-04-15 session (flash package version-hiding)

**Transform-v6/v7 → PASS (+2 tests), Matrix-v7 → ruffle_matched (+1).**

The Gnash Transform-v6/v7 tests do this at startup:
```
ASSetPropFlags(_global, "flash", 0, 5248);  // 5248 = 0x1480
check_equals(typeof(flash.geom.Transform), "function");
```
The ASSetPropFlags call clears version-hiding bits (0x1480 is the OR of the
bits set in SWF5/6/7 hide masks but not SWF8). For the second line to resolve
to `function`, `_global.flash` must exist as a (hidden) property that becomes
visible after the flag clear.

Our previous implementation only created `g_flash_object` and registered
`_global.flash` for SWF≥8. Three changes in
`SWFModernRuntime/src/actionmodern/action.c`:

1. Remove `SWF>=8` gate on `g_flash_object` creation in `ensureGlobalInit`.
2. Remove `SWF>=8` gate on `initFlashPackage` call (now unconditional).
3. Remove `SWF>=8` gate on `REG_OBJ("flash", 5, g_flash_object)` on
   `global_object`, and mark the resulting property with
   `flash_flags=0x1480`. Under SWF5/6/7 hide masks (0x7480/0x7500/0x7000)
   this evaluates to hidden, and under SWF8 mask (0x6000) it is visible.
   `setProperty` already clears `flash_flags` when a user writes to the
   property, matching Flash's behavior where direct writes override
   version-hiding.

This leaves `typeof(flash) == 'undefined'` passing in Point-v6/v7 (flash
stays hidden until ASSetPropFlags unhides it) and gives Transform-v6/v7
the unhide path they need.

**Filtered pass rate delta:** +2 PASS (Transform-v6/v7 were
output_mismatch), +1 effective pass (Matrix-v7 output_mismatch →
ruffle_matched; Matrix-v7 carries `known_failure` upstream with
`output.ruffle.txt`, and our diffs now fit within Ruffle's).


## 2026-04-14 session 3 summary (System, Sound, Matrix, TextFormat, MC, TF)

Six targeted fixes in `SWFModernRuntime/src/actionmodern/action.c`:

1. **System-v5..v8 → PASS** — `$version` on root MC, `exactSettings`
   SWF5 gate, `System.security.*` return `Bool(arg_count >= 1)`.
   See "System-v5/v6/v7/v8 → PASS" entry below.
2. **Sound-v5..v8 → ruffle_matched** — `initSoundPrototype` now
   installs the 7 SWF6+ methods (getDuration, setDuration, getPosition,
   setPosition, loadSound, getBytesLoaded, getBytesTotal) unconditionally
   and marks them with `flash_flags=0x0080`. Previously the
   `if (g_swf_version >= 6)` block ran once during Dejagnu.swf (SWF5)
   and was cached, so SWF6+ test timelines never got the extensions.
3. **Matrix-v8 → ruffle_matched** — `matrixInvert` resets to identity
   when `det == 0` instead of propagating infinities. Matches Ruffle
   `matrix.rs:347` (`unwrap_or_default()`).
4. **TextFormat-v5/v6/v7 improved (+13 lines each)** —
   `initTextFormatPrototype` installs the 17 Flash-spec own properties
   (font, size, color, url, target, bold, italic, underline, align,
   leftMargin, rightMargin, indent, leading, blockIndent, tabStops,
   bullet, display) as undefined on the prototype. Tests still not
   passing — remaining diffs involve bold/align coercion semantics and
   getTextExtent location (own vs prototype).
5. **MovieClip-v5 improved (+22 lines, close to ruffle_matched)** —
   `initMovieClipPrototype` installs 13 drawing-API method stubs
   (attachAudio, beginFill, beginGradientFill, beginBitmapFill, moveTo,
   lineTo, curveTo, lineStyle, lineGradientStyle, endFill, clear,
   attachBitmap, getRect) plus 9 undefined property slots (blendMode,
   cacheAsBitmap, filters, opaqueBackground, scale9Grid, scrollRect,
   tabIndex, useHandCursor, _lockroot). Still 4 extras vs ruffle diffs:
   `typeof(mc.valueOf())=='movieclip'`, `mc.enabled='a string'`
   coercion, `mc.getNextHighestDepth()==undefined` SWF5 gating, and
   a truncated-tail delta.
6. **TextField-v5 improved (-1 diff line)** — `actionTypeof` for
   MOVIECLIP-with-text-field now returns `'movieclip'` in SWF5 and
   `'object'` in SWF6+ (SWF5 predates the TextField class). Still
   fails `tf instanceOf TextField` — test source not available locally.

**Net delta:** +4 passing (System), +3 new ruffle_matched (Sound-v6/v7/v8;
Sound-v5 was already matched), +1 new ruffle_matched (Matrix-v8). 8 tests
that were `output_mismatch` are now counted as effective passes. Other
tests improved but did not cross the threshold.

## 2026-04-14 session 3 (System-v5/v6/v7/v8 → PASS)

All four Gnash System tests now pass. Three changes in `action.c`:

1. **`$version` on root MovieClip** — Flash Player sets `$version` as an own
   property on the root timeline (Ruffle does the same via
   `context.rs:417`, `AvmString "$version"` on `root.object1()`). Added at
   the end of `ensureGlobalInit`: allocate `root_movieclip.dynamic_props`
   if NULL and `setProperty(..., "$version", u16_WIN_ver)`. This fixes
   `typeof($version)=='string'`, `typeof(this.$version)=='string'`,
   `this.$version == System.capabilities.version`, and
   `this.hasOwnProperty("$version")` across all four tests.
2. **`System.exactSettings` SWF5-gated** — marked with `flash_flags=0x0080`
   (VERSION_6 mask). Matches Ruffle's `system.rs` which declares
   `"exactSettings" => property(..; VERSION_6)`. Fixes `typeof(System.exactSettings)=='undefined'`
   in SWF5.
3. **`System.security` method stubs return `Bool(arg_count >= 1)`** — new
   helper `builtin_return_has_arg` wired to `allowDomain`,
   `allowInsecureDomain`, `loadPolicyFile`, `escapeDomain`. Mirrors
   Ruffle's `allow_domain: Ok(Value::Bool(args.get(0).is_some()))`. The
   test calls allowDomain with 0-7 args; our stub returns true for the
   7 cases with args and false for the single no-arg call at line 193.
   `chooseLocalSwfPath` stays `builtin_noop_func`.

Also added (defensive, not required for System tests but correct):
- `builtin_return_true` helper and `System.Product.{launch,download,validate}`
  stubs returning true. Gnash test invokes `System.security.allowDomain`
  not `p.download`, but the Flash spec says Product methods return
  boolean, so the change matches Flash.

**Impact:** System-v5: 52/67 → 67/67 PASS. System-v6/v7/v8: 85/100 → 100/100
and 86/101 → 101/101 PASS. No regressions on avm1 tests checked
(`enumerate`, `global_is_bare`, `mutable_this`, `string_coercion`,
`this_scoping`, `textsnapshot_available_text`, `array_enumerate`,
`loadvariables`). Pre-existing `global_proto_decls` failure is unrelated
(verified by git stash — it fails on baseline too, from a
`useCodepage/exactSettings READ_ONLY` flag mismatch unrelated to this
session's work).

**Filtered pass rate delta:** +4 tests (from `fail` to `pass`, none of the
four System tests were known_failure).

## 2026-04-14 session (textsnapshot_available_text regression fix)

The `getText` empty-native fix from the earlier TextSnapshot work produced
`""` for a native TS whose backing MC had no captured text. That was the
right answer for the Gnash tests but broke `avm1/textsnapshot_available_text`
(20/20 → 17/20). The test duplicates MCs and expects `new TextSnapshot(src)`
on a stale source to return a non-native TS whose `getText` returns
`undefined` — matching Ruffle's constructor, which rejects the arg when
`as_movie_clip()` returns None.

**Fix:** new `ts_stale_source` flag on `MovieClip`. `ng_cloneSprite` and
`ng_cloneSpriteFromMC` (the two paths behind the AVM1 `CloneSprite` /
`duplicateMovieClip` opcodes) now mark the source as stale; clones inherit
the source's current value *before* the mark, so a clone from an
already-stale source is born stale (matches the test's `child_clone3`
expectation: immediately undefined because its source `child` was already
used as a dup source). TextSnapshot constructor and the `getTextSnapshot`
method path both skip `native_type=NATIVE_TEXTSNAPSHOT` when `arg_mc->
ts_stale_source` — `getText` on a non-native TS returns undefined, the
test passes, and Gnash TextSnapshot-v6/v7/v8 continue to pass.

Regression check: 13/13 across `duplicate_movie_clip*`, `clone_sprite_*`,
`textsnapshot_*`, `mutable_this`, `this_scoping`, `string_coercion`.

## 2026-04-14 session (Point-v8 push over the line)

**Point-v8 now ruffle_matched (185/193 → effectively passing).** Three targeted
fixes to `action.c` Point builtins:

1. **`pointAdd` primitive auto-boxing** — When arg is a string/number/boolean
   primitive, look up `.x`/`.y` via the matching wrapper prototype
   (String.prototype/Number.prototype/Boolean.prototype). Fixes the Gnash test
   `String.prototype.x = 3; p.add('1')` expecting `ret.x == "x3"`. New helper
   `getPrimitiveWrapperProto(type)` reads the ctor from `global_object` and
   returns its `prototype_obj`.
2. **`pointDistance` returns undefined for arg_count < 2** (was returning NaN).
   Matches Gnash: `Point.distance()` and `Point.distance(undefined)` both yield
   `typeof == 'undefined'`.
3. **`pointDistance` and `pointEquals` walk __proto__ chain** — new helper
   `objIsPointInstance(obj)` walks up to 16 levels of `__proto__` looking for
   `g_point_prototype`. Fixes the test patterns `o1.__proto__ = Point.prototype`
   (distance) and `o3.prototype.__proto__ = Point.prototype; p2.__proto__ =
   o3.prototype; p1.equals(p2)` (equals, 2-hop).

**Regression-free:** Point-v5/v6/v7 still PASS; no avm1/Number tests broken by
the added primitive-wrapper lookup (only triggers when the Point.add arg type
is non-object, which is rare outside Gnash's Point tests).

## 2026-04-14 session

**Type-1 constructor `this` leak fix (v2)** — `actionNewObject`
user-constructor path (type 1) called `setVariableByName("this", ...)` without
pushing a local scope first, so when constructors run at root level the
"this" write fell through to the global variable table and persisted after
the constructor returned. Later `new TextSnapshot(this)` at root-level saw
args[0] as OBJECT (the stale leftover) instead of MOVIECLIP, preventing the
constructor from setting `native_type=NATIVE_TEXTSNAPSHOT`.

The first attempt (commit `0eddf896`) wrapped the ctor call in a fresh local
scope so `setVariableByName` landed there. That passed the three Gnash
TextSnapshot tests but regressed `avm1/string_coercion` (117→108 lines): the
extra scope held references that inner closures captured, but the scope was
popped before those closures ran, so comparisons that called custom valueOf
methods inside the constructed objects returned undefined instead of
true/false.

Final fix (action.c:42220–42272): drop the `setVariableByName("this", ...)`
call from the type-1 ctor path entirely and rely on the `g_this_stack` push
(which was already there) plus the early `this` resolution in
`actionGetVariable` (SWF>=5 reads `g_this_stack` before scope chain / var
table). No extra scope, no leak.

**TextSnapshot.getText empty-native fix** — `getText(start, end[, nl])` on a
native TextSnapshot whose backing MC has no text previously returned
`undefined`; now returns the empty string (matches Flash: type must be
"string" for 2-3 arg calls).

**Impact:** TextSnapshot-v6/v7/v8 → **all PASS** (167/167 lines each).

**Resolved:** `avm1/textsnapshot_available_text` now passes via the
`ts_stale_source` flag on MovieClip — see the 2026-04-14 session entry
above.

**Point method string-+ semantics** — Gnash's Point tests pass string-typed
x/y coordinates and exercise `add`, `offset`, and `Point.interpolate` through
the AS1/AS2 abstract `+` operator, which string-concatenates when either
operand is a STRING. Our builtins coerced both sides to doubles. Added
`avAdditionEcma` helper (ECMA-style abstract `+`) and rewrote:
- `pointAdd`: treats missing/non-Object args as UNDEFINED instead of NaN
- `pointOffset`: mutates `this.x`/`this.y` via abstract `+`
- `pointInterpolate`: `pt2.x + f*(pt1.x - pt2.x)` uses abstract `+`
Also rewrote `pointEquals` to use strict equality (`avStrictEquals`) so
two points with equal string x/y compare equal (previously compared as NaN
after double coercion).

**Impact:** Point-v8 22→6 diffs (line-match 165/187 → 181/187). Still not
passing — remaining diffs involve Point.add(number) arg coercion,
Point.distance with NaN/non-numeric fields, and one reflexive-equals edge
case.

## 2026-04-12 session

**TextSnapshot stubs** — `hitTestTextNearPos`, `getSelected`, `getSelectedText`
now real builtins returning type-correct values gated on arg_count. `getCount`
now gates on `arg_count==0` (any args → undefined) and returns 0 (not undefined)
when the TextSnapshot has no backing text. `getText` returns `""` (not undefined)
for 2-3 args when no backing text. **TextSnapshot-v6/v7/v8**: 128→164/167 lines
(+108 line fixes total, all 3 tests now 3 lines shy of passing).

**NOTE:** This document was written on 2026-03-19 when the pass rate was 25.5%.
The current pass rate is ~40% (76/190 actionscript.all). Several categories
below have been fully resolved (marked RESOLVED). Tests covered by other plans
are cross-referenced. The category analysis and fix complexity estimates remain
valid for unresolved categories.

**Cross-references:**
- Categories 1, 2, 6: → `ACCEPTED_DIFFS.md` (ignored, our output is correct)
- Categories 3, 4, 5, 7: → `incomplete/GNASH_NEAR_PASSING_PLAN.md`
- Category 14: → `complete/TRY_FINALLY_PLAN.md` (FIXED)
- Category 17: → `blocked/MISC_SWFMILL_PLAN.md`

**Original stats (2026-03-19):**
- **Total tests**: 204 (190 actionscript.all + 14 misc-swfmill.all)
- **Passing**: 52 (44 + 8) = 25.5%
- **Failing**: 152 (2 segfault, 5 runtime error, 145 output mismatch)
- **Line-level match**: 11,034/16,986 (65.0%)

Tests are grouped by root cause / feature area. Within each category, tests are sorted by match rate (best first). Each category includes estimated fix complexity and number of tests affected.

---

## 1. Equality/Comparison Operator Coercion (est. ~5 tests) — RESOLVED

Failing tests: ops-v8 (95.8%)

String-to-number coercion in equality operators. `Infinity == 'Infinity'` returns false when it should return true. Similarly `NaN` comparisons and `!r` boolean coercion fail. ActionScript's `==` operator should coerce strings to numbers when comparing with numeric types.

**Root cause**: `actionEquals2` or the abstract equality algorithm doesn't coerce string↔number for Infinity/NaN string representations.

**Fix complexity**: Low — add string-to-number coercion path in equality comparison.

**Impact**: ops-v8 would go from 95.8% → ~100%. Pattern likely affects other tests with string/number comparisons.

---

## 2. Math Object Edge Cases (est. 4 tests) — RESOLVED

Failing tests: Math-v5 (97.8%), Math-v6 (97.8%), Math-v7 (97.6%), Math-v8 (97.6%)

6-7 lines wrong per test. Specific failures:
- `Math.round("")` should return 0 (empty string → NaN → 0 in Flash's round)
- `Math.pow(x)` with 1 arg — behavior differs between SWF versions
- Math constant precision (exact string representation of constants)

**Root cause**: Edge cases in `coerceMathArgs` and specific Math method implementations.

**Fix complexity**: Low — individual edge case fixes.

**Impact**: 4 tests go from 97.6-97.8% → ~100%.

---

## 3. NetStream/Video Prototype Properties (est. 6 tests) — RESOLVED (NetStream), Video remains

Failing tests: ~~NetStream-v6/v7/v8 (95.0%)~~, Video-v5 (57.1%)

**NetStream-v6/v7/v8: PASS** (2026-04-09). Fix: NetStream constructor now installs `currentFps` on prototype when constructed with a connected NetConnection. See `complete/NETSTREAM_NATIVE_PROPS_PLAN.md`.

Video-v5 remains at 57.1% — deeper issues unrelated to NetStream.

---

## 4. Color Object Implementation Gaps (est. 4 tests) — MOSTLY RESOLVED, v6 in GNASH_NEAR_PASSING_PLAN

Failing tests: Color-v5 (88.6%), Color-v6 (86.0%), Color-v7/v8 (87.6%)

Issues:
- `Color.getTransform()` on invalid target returns object instead of undefined
- `Color.setTransform()` values not stored/retrieved correctly
- `instanceof Color` checks
- Color prototype method visibility

**Root cause**: Color constructor/prototype wiring gaps. `getTransform` on invalid target not handled.

**Fix complexity**: Medium — needs Color builtin property registration + invalid target handling.

**Impact**: 4 tests improve significantly (16-24 diff lines each).

---

## 5. Selection/Stage Non-Constructable Globals (est. 5 tests) — PARTIALLY RESOLVED, Selection in GNASH_NEAR_PASSING_PLAN

Failing tests: Selection-v5 (85.7%), Selection-v6/v7/v8 (86-87%), Stage-v5 (86.8%)

In SWF5, `typeof(Selection)` and `typeof(Stage)` should return `'undefined'` — these globals shouldn't be constructable. Our implementation returns `'object'`. Also: `Stage.addListener`/`removeListener` should be undefined in SWF5.

**Root cause**: Global singleton objects are created too eagerly, ignoring SWF version gating.

**Fix complexity**: Medium — version-gate global singleton initialization.

**Impact**: 5 tests improve by 3-16 lines each.

---

## 6. Error Constructor & Prototype (est. 4 tests) — RESOLVED (PASS)

**Error-v5/v6/v7/v8: ALL PASS** (2026-04-10). Fix: Error constructor now stores raw argument value (not coerced to string). `Error.prototype.toString` returns raw message value. Two remaining diffs per test (typeof(e.message) == "object" for object args) fixed by storing raw values.

---

## 7. Inheritance & Prototype Chain (est. 4 tests) — see GNASH_NEAR_PASSING_PLAN + INHERITANCE_SEGFAULT_PLAN

Failing tests: Inheritance-v5 (82.6%), Inheritance-v6 (85.2%), Inheritance-v7 (segfault), Inheritance-v8 (segfault)

v5/v6: 20-27 diff lines. Issues with constructor execution ordering, `instanceof` on custom constructors, `Function.prototype` visibility, `__constructor__` setup.

v7/v8: Segfault. Root cause likely same as previous Inheritance segfaults — prototype chain walking hits corrupted memory.

**Root cause**: Multiple OOP gaps — constructor chain, instanceof, `__proto__` setup.

**Fix complexity**: Medium-High (v5/v6 OOP fixes), High (v7/v8 segfault investigation).

**Impact**: 2 tests improve significantly; 2 segfaults need separate investigation.

---

## 8. Delete Operator (est. 4 tests)

Failing tests: delete-v5 (61.7%), delete-v6 (63.3%), delete-v7 (65.0%), delete-v8 (66.7%)

23 diff lines in v5. Issues:
- `delete` on local variables doesn't actually remove them from scope
- `delete nonExistent` returns wrong boolean value
- `delete func.prototype` should return false (non-deletable)
- Variables persist after deletion

**Root cause**: `actionDelete` / `actionDelete2` don't properly remove variables from scope chain. DONT_DELETE flag not checked correctly.

**Fix complexity**: Medium — scope chain deletion + property flag handling.

**Impact**: 4 tests improve by 20-23 lines each.

---

## 9. Enumerate/For-In (est. 3 tests)

Failing tests: enumerate-v6/v7/v8 (44.9%)

27 diff lines each. Issues:
- `for-in` enumeration of object properties returns empty
- Sprite children incorrectly appear as `_root` own properties
- `typeof` returns 'number' for MovieClip children instead of 'movieclip'

**Root cause**: `actionEnumerate2` or the for-in loop doesn't properly enumerate dynamic properties. Display list children vs. own properties confusion.

**Fix complexity**: Medium — enumerate opcode + display list vs property distinction.

**Impact**: 3 tests improve from 45% → higher.

---

## 10. ASnative Classes (est. 4 tests)

Failing tests: ASnative-v5 (28.0%), ASnative-v6/v7 (25.5%), ASnative-v8 (26.4%)

77-81 diff lines each. Tests call `ASnative(class_id, method_id)` for many builtin classes:
- ASnative(100, *) — Object methods (partially done)
- ASnative(101, *) — Object.prototype methods (done)
- ASnative(103, *) — Date methods (not done)
- ASnative(106, *) — Number methods (not done)
- ASnative(250, *) — String methods (not done)
- ASnative(252, *) — String functions (not done)
- ASnative(253, *) — Number/Math functions (not done)

**Root cause**: Most ASnative class IDs are not implemented.

**Fix complexity**: High (many classes) but incremental — each class can be added independently.

**Impact**: 4 tests, but improvements are gradual as classes are added.

---

## 11. With Statement on Primitives (est. 4 tests)

Failing tests: with-v5 (30.0%), with-v6/v7/v8 (18.3%)

28-103 diff lines. `with(number)` and `with(string)` should auto-box primitives to their wrapper objects (Number.prototype, String.prototype), allowing property access within the with block.

**Root cause**: `actionWith` doesn't auto-box primitive values. Also WITH scope chain management issues with nested with blocks.

**Fix complexity**: Medium — auto-boxing in actionWith + scope chain fixes.

**Impact**: 4 tests, significant improvement.

---

## 12. String Class Methods (est. 4 tests)

Failing tests: String-v5 (60.9%), String-v6 (60.2%), String-v7 (59.7%), String-v8 (59.4%)

140-153 diff lines each. Many string method edge cases:
- `String.fromCharCode` missing
- `charAt`/`charCodeAt` boundary behavior
- `split` with regex or complex separators
- `replace` not implemented
- `search`/`match` regex support

**Root cause**: Several String prototype methods not implemented or incomplete.

**Fix complexity**: High — regex support needed for `replace`/`match`/`search`.

**Impact**: 4 tests, but many lines.

---

## 13. Number Formatting/Coercion (est. 4 tests)

Failing tests: Number-v5 (79.1%), Number-v6 (76.2%), Number-v7 (78.9%), Number-v8 (78.5%)

51-57 diff lines. Issues with:
- `Number.toString(radix)` for bases 2, 8, 16
- `Number.toFixed()`/`toPrecision()`/`toExponential()` not implemented
- Numeric string coercion edge cases

**Root cause**: Number formatting methods not implemented.

**Fix complexity**: Medium — standard ECMAScript number formatting methods.

**Impact**: 4 tests improve by ~50 lines each.

---

## 14. Try/Catch/Finally Control Flow (est. 4 tests) — RESOLVED (see TRY_FINALLY_PLAN)

Failing tests: Try-v5/v6/v7/v8 (runtime error — exit code 1)

OOM via runaway string concatenation in nested try/catch/finally blocks. The recompiler generates `goto` jumps across try/finally boundaries causing finally blocks to execute repeatedly.

**Root cause**: Recompiler try/finally control flow generates incorrect goto targets for nested cases.

**Fix complexity**: High — recompiler control flow analysis for try/finally blocks.

**Impact**: 4 tests currently crash.

---

## 15. toString/valueOf Coercion (est. 4 tests)

Failing tests: toString_valueOf-v5 (59.9%), toString_valueOf-v6 (76.1%), toString_valueOf-v7/v8 (76.8%)

36-55 diff lines. Tests exercise valueOf/toString coercion paths for various operations (comparison, arithmetic, string concat). Some failures from ASArray/ASObject cast bug in `convertFloat`.

**Root cause**: valueOf/toString dispatch on arrays, objects with custom valueOf. ASArray cast bug.

**Fix complexity**: Medium — fix ASArray path in convertFloat + valueOf dispatch.

**Impact**: 4 tests, significant line improvements.

---

## 16. Case/Switch Statement (est. 4 tests)

Failing tests: case-v5 (82.1%), case-v6 (24.7%), case-v7/v8 (19.4%)

v5 has 7 diff lines; v6/v7/v8 have 50+ diff lines. v5 is close — likely strict equality vs abstract equality in switch. v6+ have severe issues (possibly related to the `with` block duplicate label fix or scope chain).

**Root cause**: Switch/case statement comparison semantics; v6+ tests exercise more complex patterns.

**Fix complexity**: Low for v5, Medium for v6+.

**Impact**: 4 tests.

---

## 17. Misc-SWFMill: Frame/Tag Execution Issues (est. 6 tests)

Failing tests from misc-swfmill.all:

| Test | Match | Issue |
|------|-------|-------|
| dict_event | 60% (3/5) | Clip event handler not firing for multiple frames |
| jump_after_end | 33% (1/3) | Jump past END_OF_ACTIONS not handled |
| initaction_in_definesprite | 0% (0/2) | InitAction inside sprite definition not executing |
| jump_to_prev_block | 0% (0/1) | Backward jump in bytecode not re-executing |
| tags_after_last_showframe | 0% (0/15) | Tags after final ShowFrame cause infinite loop |
| zeroframe_definesprite | 0% (0/3) | Zero-frame sprite timing wrong |

**Root cause**: Various recompiler and runtime edge cases for frame/tag execution.

**Fix complexity**: Varies — each is an independent issue.

---

## 18. Other Feature Areas (many tests, lower priority)

| Category | Tests | Match Range | Key Issue |
|----------|-------|-------------|-----------|
| AsBroadcaster | v5-v8 (4) | 70-79% | Listener dispatch, broadcastMessage |
| ContextMenu | v7-v8 (2) | 72.5% | customItems, enabled, builtInItems |
| TextFormat | v5-v7 (3) | 64-78% | TextFormat constructor coercion, getters |
| TextSnapshot | v6-v8 (3) | 76.3% | getText, findText, hitTestTextNearPos |
| TextFieldHTML | v6-v8 (3) | 86.5% | htmlText getter edge cases |
| Sound | v5-v8 (4) | 63-77% | Sound.attachSound, Sound.start, volume |
| ExternalInterface | v6-v8 (3) | 51-70% | addCallback, call, data marshalling |
| MovieClip | v5 (1) | 65.0% | Many MC properties/methods |
| Mouse | v5-v8 (4) | 57-62% | Mouse.addListener, cursor visibility |
| Microphone | v6-v8 (3) | 60.8% | Microphone prototype properties |
| Camera | v6-v8 (3) | 36.7% | Camera prototype properties |
| LoadVars | v6-v8 (3) | 44.1% | LoadVars.load, onLoad, decode |
| LocalConnection | v5-v8 (4) | 41-57% | IPC system, connect/send |
| System | v5-v8 (4) | 38-40% | System.capabilities, security |
| Key | v5-v8 (4) | 20-27% | Key object, isDown, getCode |
| MovieClipLoader | v7-v8 (2) | 27.9% | loadClip, events |
| BitmapData | v8 (1) | 52.5% | BitmapData class methods |
| targetPath | v6-v8 (3) | 32.1% | targetPath function for nested MCs |
| flash (geom) | v5-v7 (3) | 70.0% | flash.geom stubs |
| Instance | v5-v8 (4) | 52-64% | instanceof, constructor, typeof |
| Accessibility | v6-v8 (3) | 47-53% | Accessibility.isActive, properties |
| array-v5 | (1) | runtime error | Array test OOM |

---

## Recommended Fix Priority

### Tier 1: Quick Wins (est. +8-12 tests to passing)

| Fix | Tests | Current | Effort |
|-----|-------|---------|--------|
| Math edge cases | Math-v5/v6/v7/v8 | 97.6-97.8% | Low |
| Equality coercion (Infinity/NaN strings) | ops-v8 | 95.8% | Low |
| NetStream prototype properties | NetStream-v6/v7/v8 | 95.0% | Low |
| Error constructor message coercion | Error-v5/v6/v7/v8 | 75-77% | Low |

### Tier 2: Medium-Impact Fixes (est. +10-15 tests improved)

| Fix | Tests | Current | Effort |
|-----|-------|---------|--------|
| Color getTransform/setTransform | Color-v5/v6/v7/v8 | 86-89% | Medium |
| Selection/Stage SWF5 gating | Selection-v5-v8, Stage-v5 | 85-87% | Medium |
| Delete operator scope handling | delete-v5/v6/v7/v8 | 62-67% | Medium |
| toString/valueOf + ASArray fix | toString_valueOf-v5-v8 | 60-77% | Medium |

### Tier 3: Larger Efforts (many tests, more work)

| Fix | Tests | Current | Effort |
|-----|-------|---------|--------|
| ASnative class implementations | ASnative-v5-v8 | 26-28% | High (incremental) |
| With auto-boxing | with-v5-v8 | 18-30% | Medium |
| Number formatting methods | Number-v5-v8 | 76-79% | Medium |
| String regex support | String-v5-v8 | 59-61% | High |
| Try/finally control flow | Try-v5-v8 | crash | High |
| Enumerate opcode | enumerate-v6-v8 | 45% | Medium |

### Tier 4: Feature-specific work (requires significant new infrastructure)

Key, Camera, System, LoadVars (network), LocalConnection (IPC), MovieClipLoader (loadMovie).

---

## Phase 3 Progress (2026-04-08)

### 3a: Flash-compatible number formatting — DONE

**Change**: Replaced all `%.15g` double-to-string conversions with `flash_format_double()` helper in `action.c`.

**Two fixes**:
1. **Exponent leading zeros removed**: `1.23e-07` → `1.23e-7` (Flash never uses leading zeros in exponents)
2. **Decimal threshold shifted**: Numbers with exponent -5 (e.g., 0.000054) now render in decimal format instead of scientific notation (`5.4e-05` → `0.000054`). Flash uses decimal when `-5 <= exponent <= 14`, vs C's `-4 <= exponent <= 14`.

**Impact**: Fixes ~7-10 lines per Number-v5/v6/v7/v8 test (formatting-related failures). Also improves any other test that converts numbers to strings. Number-v8 improved from 192/237 to ~199/237 (+7 lines).

### 3b: Delete operator partial fixes — DONE

**Changes**:
1. `delete func.prototype` now returns false (prototype is non-deletable on ASFunction)
2. `delete undefined.prop` now returns false (can't delete property on non-object)

**Impact**: delete-v7 improved from 41/60 to 43/60 (+2), delete-v8 from 42/60 to 44/60 (+2).

**Remaining delete issues** (not yet fixed):
- Local `var` variables should not be deletable (DONT_DELETE flag)
- Property deletion inside `with()` blocks doesn't propagate
- Global scope `delete a` after `_global.a` assignment

### 3c: _global.NaN and _global.Infinity registration — DONE

NaN and Infinity registered as F64 properties on global_object. Fixes `typeof(_global.NaN) == 'number'` checks. +2 lines per Number test.

### 3d: Number constructor own properties — DONE

Registered `constructor`, `__proto__` (→ Function.prototype), and `prototype` as own properties on `g_number_constructor.own_props`. Fixes `Number.hasOwnProperty('prototype')` etc. +3 lines per Number test (v7/v8).

**Combined Number impact**: Number-v5: 193→~203/244, Number-v6: 186→~196/239, Number-v7: 192→~204/237, Number-v8: 192→~204/237.

### 3e: Number constructor proper type coercion — DONE (2026-04-08)

**Three fixes**:
1. `new Number(value)` constructor: Use `varToDoubleSWF` for argument coercion instead of manual type switch. Fixes `new Number(obj)` returning 0 when obj has valueOf/toString methods.
2. `varToDoubleSWF` OBJECT path: Handle valueOf returning non-numeric primitives (STRING, BOOLEAN, NULL, UNDEFINED).
3. Trailing whitespace trimming in `varToDoubleSWF` for decimal string parsing.

**Impact**: Number-v5 +13, Number-v6 +12, Number-v7 +12, Number-v8 +13 lines. Also cascading improvements to other tests that use Number coercion.

### 3f: Number wrapper toString radix support — DONE (2026-04-08)

`new Number(10).toString(2)` now correctly returns "1010" instead of "10". The wrapper toString (`builtin_prim_wrapper_toString`) now handles radix 2-36 for NATIVE_NUMBER wrappers.

**Impact**: +1 line per Number test.

### 3g: Delete operator non-existent + global_object — DONE (2026-04-08)

1. `delete nonExistentVar` now returns false (was returning true).
2. Added global_object property check before returning false — `delete a` where `a` is on `_global` now works.

**Impact**: delete-v5 +2, delete-v7 +2, delete-v8 +2 lines.

### 3h: actionEnumerate scope chain lookup — DONE (2026-04-08)

The old Enumerate opcode (SWF5 for-in) wasn't checking the scope chain for variable lookup. Added scope chain walk before global variable lookup. Fixes `enumerateObj(o)` inside functions where `o` is a function parameter.

**Impact**: enumerate-v6/v7/v8 each +13 lines (25→12 failures). Also smaller improvements in other tests.

### 3i: Delete dot-path resolution (actionDelete2 + actionDelete) — DONE (2026-04-09)

**Two fixes**:
1. `actionDelete2` with dot-path variable names (e.g., `Delete2("o.b")`) now resolves the path: splits on last dot, looks up container via `actionGetVariable`, then deletes the final property. Works for OBJECT, MOVIECLIP, FUNCTION, and ARRAY containers.
2. `actionDelete` with dot-path property name and invalid/empty object reference (stack underflow from SWF bytecode that pushes only one value before Delete): falls back to dot-path resolution. SWF5/6 only — SWF7+ uses strict property names without path resolution.

**Impact**: delete-v5: 43→47/60 (+4), delete-v6: 41→45/60 (+4), delete-v7: 46→49/60 (+3), delete-v8: 47→50/60 (+3). Total: +14 lines across 4 tests.

### 3j: Number hex/octal parsing fixes — DONE (2026-04-09)

**Three fixes**:
1. `parseStringToNumber` (equality coercion): explicit hex parsing with signed int32 semantics. `"0xFF000000"` → `(int32_t)-16777216`, not unsigned `4278190080`. Octal parsing for leading-zero all-octal-digit strings.
2. `varToDoubleSWF` (Number constructor): support inner negative sign after 0x prefix. `"0x-2"` → -2, `"0x-ffffffff"` → 1 (via signed int32 negate). Outer sign (`"-0x2"`, `"+0x2"`) still returns NaN (Flash behavior).
3. Both fixes prevent C99 `strtod` from silently parsing hex floats, which produced wrong results.

**Impact**: Number-v6 +5, Number-v7 +5, Number-v8 +5 lines. Number-v5 unchanged (SWF5 doesn't have hex/octal string parsing).

### 3k: Error constructor raw message storage — DONE (2026-04-10)

**Two fixes**:
1. Error constructor now stores the raw argument value instead of coercing non-string args to string. `new Error(new Object())` keeps the Object reference as `.message` (Flash behavior).
2. `Error.prototype.toString` now returns the raw message value (any type), not just strings.

**Impact**: Error-v5, Error-v6, Error-v7, Error-v8 → all PASS. +4 tests.

### 3l: parseInt object toString coercion — DONE (2026-04-10)

`parseInt()` now calls `toString()` on object/array/function arguments instead of treating them as "undefined". Uses `varToStringBuf` for object types only (preserves existing number formatting to avoid regressions).

**Impact**: toString_valueOf-v6/v7/v8 each +2 lines (parseInt lines fixed). Also improves any test using `parseInt(obj)` with custom toString.

### 3m: Primitive auto-boxing in GetMember — DONE (2026-04-15)

Primitive number (F32/F64) and boolean property access now looks up properties on
Number.prototype / Boolean.prototype via `getPrimitiveWrapperProto()`. Fixes
`typeof(1 .toString) == 'function'` and `(1).__proto__ == Number.prototype`.

**Impact**: Number-v7/v8 each -5 diffs, Number-v5/v6 each -7 diffs. Also ~2 lines
improved across AsBroadcaster, Instance, Rectangle, ContextMenu, HitTest, Matrix,
TextFormat, and other tests.

### 3n: convertFloat FUNCTION valueOf dispatch — DONE (2026-04-15)

The FUNCTION case in convertFloat's valueOf dispatch was missing — `obj` stayed NULL
so custom valueOf on function objects was never invoked. Now sets `obj = fn->own_props`.
Fixes `toNumber(funcWithCustomValueOf)` returning NaN instead of the valueOf result.

**Impact**: Number-v7/v8 +2 lines (val == 9 tests), cascading improvements.

### Phase 3 remaining work:
- ~~**Number wrapper valueOf override**: `new Number(10)` wrapper doesn't dispatch custom valueOf~~ (DONE — 3m auto-boxing fix)
- **Number float precision**: last-digit rounding at e-308 (4 lines per Number test) — platform difference in dtoa algorithm, likely unfixable
- ~~**convertFloat SWF6 NaN threshold**~~: DONE. Changed fallback from `SWF<7→0.0` to `SWF<6→0.0` (Flash returns NaN for object-to-number starting at SWF6, not SWF7). Note: toString fallback was NOT implemented — Flash does not call toString during toNumber (unlike ECMA-262).
- **toString_valueOf dispatch**: valueOf/toString not called during implicit coercion in some paths (~13 diffs per v6/v7/v8). Investigation shows `objectCallValueOf` for type 1 functions calls `simple_func` without setting `this` context. For type 2, `this_obj` is passed correctly but user-defined functions may still fail if function pointers aren't properly set. The `"" + o` test expects both valueOf (returns non-primitive → 1 call) and toString (called as fallback → 1 call) to fire, but both show 0 calls.
- **enumerate child MC type**: child MCs returned as 'number' instead of 'movieclip' (12 diffs per enumerate test)
- **enumerate hasOwnProperty**: child MCs stored in dynamic_props → hasOwnProperty returns true (6 diffs per enumerate test)
- **with auto-boxing**: `with(number)` should auto-box to Number.prototype scope (not addressed)
- **String regex methods**: replace/match/search need regex support (~120 diffs per test)
- **delete DONT_DELETE flag**: local var deletion semantics differ between SWF5 and SWF7+ — SWF5 allows some local vars to be deleted but function parameters remain non-deletable (complex, investigated 2026-04-10)
- **delete local vars**: `delete e` on function locals + `_root.e` persistence after delete (9 diffs per delete test)

### Latest fixes (2026-04-11)
- **Equals2 Object vs primitive — Ruffle is_primitive semantics** — `actionEquals2` now matches Ruffle's `abstract_eq`: when valueOf returns a non-primitive (e.g., `Object.prototype.valueOf` returning `this`), the comparison returns false immediately. `objectToPrimitive` now returns the *original object reference* (instead of UNDEFINED) when valueOf returns non-primitive, so `actionEquals2` can distinguish "object still" from "UNDEFINED" (where `_global`/`__proto__=undefined` objects legitimately resolve to UNDEFINED and compare equal to undefined). SWF5 object-vs-object path updated to use is-primitive check. **+1 test: delete-v7 → PASS.** Also fixed `SubObj1.prototype != undefined` line in Inheritance-v7.

### Latest fixes (2026-04-12)
- **actionDelete single-arg fallback (SWF5/6)** — `actionDelete` (opcode 0x3A) called with only one stack item (e.g., `asm { push 'o'; delete }`) now treats the property name as a bare variable name and dispatches to `actionDelete2`'s scope-chain/global lookup. Gated on SWF<7, and only when the obj-slot pop returned a non-meaningful value (avoids regressing `delete unexistent.a`-style cases where the obj operand is a real string). **+1 test: delete-v5 → PASS.**
- **LocalConnection.send reserved method names** — `lc_is_protected_method` switched from `strcmp` to `strcasecmp` (SWF rejects reserved method names case-insensitively), and added `onStatus` to the list. **+3 tests: LocalConnection-v6/v7/v8 → PASS.**
- **ColorTransform constructor + rgb getter** — three fixes to the ColorTransform builtin: (1) the `rgb` getter dropped the `& 0xFF` masking on red/green/blue offsets so it's a pure `(r<<16)+(g<<8)+b` bit-shift (per the test's "It's just bitshifting" comment); (2) the constructor now defaults to identity (1,1,1,1,0,0,0,0) when given fewer than 8 arguments; (3) the constructor coerces arguments via `varToDoubleSWF` instead of `varToDoubleSimple` so object arguments dispatch through `valueOf`. **+1 test: ColorTransform-v8 → PASS** (Color-v5/6/7/8 and ColorTransform-v5/6/7 confirmed not regressed).
- **GetVariable/Delete2 _global fallback routing** — Both the last-resort `_global` read fallback in `actionGetVariable` and the `_global` branch in `actionDelete2` were looking up properties on `global_object` directly, even though `SetMember(_global, name, value)` writes to the version-appropriate active global (`g_global_legacy` for SWF5/6). At top-level frame-script scope these two objects are not the same, so the reads and deletes silently targeted the wrong global. Both sites now consult `getActiveGlobal()` first and fall back to `global_object` if different. **+1 test: delete-v6 → PASS** (delete-v5/v7/v8 confirmed not regressed).
