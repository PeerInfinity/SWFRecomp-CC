# s22 wave 1 — `w1-drift-avm1`: pricing the AVM1 upstream drift (Ruffle `0dacba55f..45366370e`)

**New files in this commit:** this report; `w1-drift-avm1-prototype.patch` (a measured prototype
against `origin/master` `be8f4b62`, reverted from the tree; 5 hunks in `action.c`: 1-2 = M3b
hasOwnProperty-on-array crash, 3 = M5 objectToPrimitive captured scope, 4 = M7a last-wins
`tf_get_attr`, 5 = M5 object-method arm captured scope).

**Setup:** cloud box, `SETUP_STATUS` all OK (apt, Pillow, Dawn). `download_tests.sh avm1 from_gnash`
pulled upstream master; a Ruffle clone made at the same time sits at **`45366370e`** (deleted
`html_text_img_parsing`, new `_swf8`, all present as the namestatus list says). Every run below is
`--mode=graphics` (lavapipe), single tests, at most `-P 2`.

## TL;DR

1. **The drift is bigger than CI shows, and the brief's premise undercounts it.** Eight more drops
   are coming that no CI run has seen yet. The weekly no-graphics run (corpus downloaded 10-11 08:51)
   predates `c2a878a68` (AsBroadcaster, 10-12) and `dd4e73d59` (global Array, 10-14). The next CI
   run will show these, and all of them are drift, **not regressions**:
   `avm1/as_broadcaster` (pass→fail), `avm1/array_constructor` (pass→**SEGFAULT**),
   gnash `AsBroadcaster-v6/v7/v8` (ruffle_matched→fail, `known_failure` removed), and
   gnash `array-v6/v7/v8` (ruffle_matched→fail: `dd4e73d59` rewrote their `.fp*.ruffle.txt`, so our
   diff is no longer a subset of Ruffle's). Also, `as_broadcaster_initialize` and
   `as_broadcaster_undef` (2 passes) were deleted upstream.
   Full tally against the s21 corpus: **8 pass→fail** (point, rectangle, matrix, context_menu,
   context_menu_item, Rectangle-v8, plus hidden as_broadcaster and array_constructor) and
   **9 ruffle_matched→fail** (Matrix-v6..v8, plus hidden AsBroadcaster-v6..v8 and array-v6..v8).
   That is **−17 effective**, plus 2 deleted passes and 6 new failing tests.
2. **"Cheapest re-flips" holds only in part.** The new avm1 geom tests (`matrix` 810 lines,
   `rectangle` 629, `point` 329) check the **order of every property get/set and every internal
   method dispatch**. Flash's Point/Rectangle/Matrix are ActionScript, and our C natives read
   properties raw. Flipping them needs a faithful port of Ruffle's `.as` files. That port is
   mechanical but large, not a quick fix. The truly cheap items are the AsBroadcaster port (55 AS
   lines), the ContextMenu/Error ports, and the array-creation fix.
3. **Two cross-cutting runtime bugs** surfaced and were proven with a prototype:
   - **Closures called as object methods never get their captured scope.** The object-method arm
     of `actionCallMethod` passes no `INV_CAPTURED_SCOPE` (`action.c:69639`), and neither does
     `objectToPrimitive`'s valueOf call (`action.c:15524`). So `obj.m = function(){ use outer var }`
     sees `undefined` when called as `obj.m()`. Adding the flag fixes the harness lines
     (`call undefined.undefined(...)` → `call matrix.createBox(...)`; `valueOf undefined` →
     `valueOf listener`). The 13 closure/method regression tests all still pass. This is a
     prerequisite for flipping as_broadcaster, matrix and rectangle.
   - **`Object.prototype.hasOwnProperty.call(array, k)` segfaults.** `builtin_object_hasOwnProperty`
     (`action.c:4562`) casts an `ASArray*` to `ASObject*`. That crash is the whole of
     array_constructor's SEGFAULT. Routing it through `callArrayMethod` takes it from crash to
     42/53.
4. **Wave-2 slots I would fund:** 4 GO slots plus 1 HOLD (details at the end).
   - **S1 (AS-semantics core):** AsBroadcaster, ContextMenu/Item and Error ports, plus the closure
     fix. 9 tests.
   - **S2 (array creation):** resolve `_global.Array` at creation, plus the hasOwnProperty crash fix.
     4 tests.
   - **S3 (geom port):** Point, Rectangle and Matrix. 7 tests; the largest slot.
   - **S4 (htmlText):** last-wins attributes, the setNewTextFormat device face, and `<img>` for
     SWF7/8. 4 tests.
   - **HOLD:** the SWF5 htmlText semantics (`html_text_img_parsing_swf5`).

## 1. Price table (local graphics runs, upstream `45366370e`)

CI columns: **G** = graphics/full `846adcc6b` (corpus 10-03); **W** = no-graphics weekly `8b69f982f`
(corpus 10-11). "now" is local graphics on clean `origin/master`. KF = `known_failure` in `test.toml`;
RTXT = `output.ruffle.txt` present. All new/changed toml use `num_ticks = 1`, no approx settings.
No dispositions exist for any row: grep of `ignored_tests.txt`, the suite ignore files and the 4
avm1 disposition docs. The wave-0 `ACC RVF` flags on `point` were word-grep false positives.

| test | G | W | now (match/exp) | toml | mechanism (§2) | flip price | wave 2 |
|---|---|---|---|---|---|---|---|
| avm1/as_broadcaster | pass 41/41 | pass 41/41 | **fail 106/312** (hidden drift) | KF removed by dd4e73d59 | M2 + M3 (1 line) + M5 (3 lines) | small–medium | **GO (S1)** |
| avm1/as_broadcaster_initialize, _undef | pass | pass | **deleted upstream** | — | — | −2 passes from the denominator | n/a |
| avm1/array_constructor | pass 30/30 | pass 30/30 | **SEGFAULT 30/53** (hidden drift) | — | M3b crash; prototype → 42/53; rest is M3 (11 lines) | small–medium | **GO (S2)** |
| avm1/as_setup_error (new) | — | fail 11/52 | fail 11/52 | KF, RTXT (Ruffle misses 1 line: `new _root.Error()`) | M6: `AsSetupError` is `builtin_noop_func` (`action.c:5362`) | small; matching Ruffle gives ruffle_matched, matching Flash (scope-chain `Error` lookup) gives a full pass | **GO (S1)** |
| avm1/context_menu | fail* | fail 49/128 | fail 49/128 | — | M4 | small | **GO (S1)** |
| avm1/context_menu_item | fail* | fail 61/96 | fail 61/96 | — | M4 | small | **GO (S1)** |
| avm1/context_menu_swf6 (new) | — | fail 11/14 | fail 11/14 | swf_version 6 | M4c: prototype flags 1027 (hidden below SWF7) | trivial | **GO (S1)** |
| avm1/edittext_html_duplicate_attributes (new) | — | fail 176/247 | fail 176/247 | KF, RTXT | M7a + M7b + M7c | medium (with S4) | **GO (S4)** |
| avm1/html_text_img_numeric_attributes | fail 1/3 | fail 1/3 | fail 1/3 | KF, RTXT (Ruffle drops the `40.9px`-style attrs; Flash keeps `WIDTH="40"`) | M7b + M7c (+ numeric-prefix parse) | small within S4 | **GO (S4)**; Flash-correct gives a full pass |
| avm1/html_text_img_parsing | fail 116/175 | — | **deleted upstream** (d587c9763) | — | — | −1 fail from the denominator | n/a |
| avm1/html_text_img_parsing_swf5 | fail 63/106 | fail 344/517 | fail 344/517 | — | M7d: SWF5 htmlText semantics (Flash: `TEXT=` empty, htmlText returns raw source) | unknown | **HOLD** |
| avm1/html_text_img_parsing_swf6 | fail 85/102 | **pass** 517/517 | **pass** | — | (test rewrite: SWF6 drops `<img>`, as we do) | — | +1 already banked |
| avm1/html_text_img_parsing_swf7 | fail 116/175 | fail 346/517 | fail 346/517 | — | M7c (`<img>` → placeholder space + `<FONT SIZE="2"><IMG …> </FONT>`) | medium | **GO (S4)** |
| avm1/html_text_img_parsing_swf8 (new) | — | fail 346/517 | fail 346/517 | — | M7c (SWF8: IMG nested inside `<A>`) | same | **GO (S4)** |
| avm1/matrix | pass 171/171 | fail 57/810 | fail 57/810 | — | M1 + M5 | large (Matrix.as is 184 lines) | **GO (S3)** |
| avm1/point | fail 54/329 | fail 54/329 | fail 54/329 | — | M1 + M5 | medium (99 lines) | **GO (S3)** |
| avm1/rectangle | fail 141/617 | fail 141/629 | fail 141/629 | — | M1 + M5 | large (236 lines) | **GO (S3)** |
| avm1/global_instance_decls | fail 26/758 | 26/758 | fail 26/758 | KF, RTXT (RTXT-only change) | no verdict move | — | NO-GO here (IGN); see the nondeterminism lead |
| avm1/global_proto_decls | fail 803/4497 | same | same | KF, RTXT-only change | no verdict move | — | NO-GO (IGN) |
| avm1/global_proto_decls_delete | fail 461/4158 | same | same | KF, RTXT-only change | no verdict move | — | NO-GO (IGN) |
| avm1/globals_monkeypatch | fail 39/246 | same | same | KF, RTXT-only change | no verdict move | — | NO-GO (far from the RTXT subset) |
| avm1/globals_swf5 | fail 294/304 | same | same | KF, RTXT-only change (AsBroadcaster.prototype now `undefined` in Ruffle; we already match Flash) | no verdict move | — | NO-GO (IGN; see the disposition-conflict lead) |
| gnash AsBroadcaster-v5 | pass | pass | pass 11/11 | KF removed | — | — | none |
| gnash AsBroadcaster-v6/v7/v8 | ruffle_matched 114/121 | ruffle_matched | **fail 114/121** (hidden drift) | KF removed, RTXT deleted | M2 (addListener dispatch through `removeListener` and `push`: AsBroadcaster.as:151-164) | small | **GO (S1)** |
| gnash ContextMenu-v7/v8 | pass 131/131 | pass | pass | KF removed, RTXT deleted | — | — | none |
| gnash Matrix-v6 / v7 / v8 | ruffle_matched 139/140/140 of 168 | fail | fail 139/140/140 of 168 | KF removed, RTXT deleted | M1 (fakematrix: AS `+`/`*` on non-numbers, `this`-generic methods) | inside S3 | **GO (S3)** |
| gnash Point-v8 | pass 193/193 | pass | pass | KF removed | — | — | none |
| gnash Rectangle-v8 | fail 145/166 | fail | fail 145/166 | KF removed, RTXT deleted | M1 (string concat `'xw'`, valueOf call counts, boolean returns) | inside S3 | **GO (S3)** |
| gnash Function-v5 | ruffle_matched 148/158 | same | ruffle_matched | `.fp*.ruffle.txt` changed | still a subset | — | none |
| gnash Function-v6/v7/v8 | pass | pass | pass | `.fp*.ruffle.txt` changed | — | — | none |
| gnash array-v6 / v7 / v8 | ruffle_matched 629/640/640 | ruffle_matched | **fail** (hidden drift) | `.fp*.ruffle.txt` changed by dd4e73d59 | M3 (array.as:1763-1793, 7 lines; Ruffle now passes them) | inside S2; returns to ruffle_matched | **GO (S2)** |
| gnash TextField-v6/v7/v8 | fail 467/476/478 | same | same | `.fp*.ruffle.txt` changed (c2a878a68) | verdict cannot move (not a subset before or after) | — | none (w1-trace-tail) |
| gnash argstest-v6/v7/v8 | fail 80/110/175 | same | same | `.fp*.ruffle.txt` changed (c2a878a68) | verdict cannot move | — | none (IGN) |

\* context_menu / context_menu_item were passes in the s21 baseline (brief). G at 10-03 already had
the rewritten tests for point/rectangle; the Matrix/ContextMenu rewrites landed 10-06..10-09.

**Answer to brief item 2 (gnash `test.toml` diffs):** every listed row lost exactly one line,
`known_failure = true`, and its `output.ruffle.txt` was deleted. Ruffle now passes them all
(AsBroadcaster-v5..8, ContextMenu-v7/8, Matrix-v6..8, Point-v8, Rectangle-v8). For us that turns
`ruffle_matched` into a plain fail wherever we were not already at 100%: **Matrix-v6..8** (visible)
and **AsBroadcaster-v6..8** (hidden). Rectangle-v8 had already flipped by 10-03. ContextMenu-v7/8,
Point-v8 and AsBroadcaster-v5 are unaffected (we pass).
The `.fp*.ruffle.txt` changes on Function/TextField/argstest/array move only **array-v6..v8**
(ruffle_matched → fail). The other three families keep their verdicts.

## 2. Mechanisms, grouped (so each slot funds one or more of them)

### M1. Geom natives aren't ActionScript (point, rectangle, matrix, Rectangle-v8, Matrix-v6..v8: 7 tests, about 1,620 diff lines)

Owner: `SWFModernRuntime/src/actionmodern/action.c`. Point natives are at `:10197-10630`, Matrix at
`:10630-10990`, Rectangle at `:11029-11500`, registration around `:11544` (`registerGeomMethod`).
Upstream: `82b84d3e5` (Point), `c717e9dc8` (Rectangle), `ee9791463` (Matrix) moved them to
`core/src/avm1/globals/flash/geom/*.as`. Ruffle passes every one of these tests (no KF), so the
`.as` files **are** the spec: Flash's geom classes are AS bytecode. Our C differs in five
sub-mechanisms, each visible in the diffs:
- **(a) Raw property access.** We use `propToDoubleSWF`, `setProperty` and `getProperty` (e.g.
  `matrixConcat :10809`). The tests install `addProperty` getters/setters and expect every
  `get matrix.a` / `set matrix.d = 1` in Flash's order. We emit **zero** getter lines in all three
  tests (`grep -c "  get "`: 0 vs 170 in rectangle's `output.txt`).
- **(b) Numeric coercion where Flash uses AS operators.** `new Rectangle('1','2','3','4')` gives
  `right=13` in Flash; Matrix `translate` gives `tx=1002`; gnash `fakematrix ... tx=a string`.
- **(c) Internal dispatch through overridable methods and globals.** `this.isEmpty()`,
  `this.setEmpty()`, `this.identity()`, `this.concat()`, `this.createBox()`,
  `this.deltaTransformPoint()`, `Point.subtract`, `Math.sin` (traced!) and `new flash.geom.Point`
  are all resolved at call time.
- **(d) Creation and enumeration order.** For example `x y width height` vs our `height width y x`.
- **(e) Small semantics.** `equals` treats NaN as equal; `containsPoint()` returns undefined;
  `union` with an empty argument returns undefined; `normalize` and `invert` NaN paths.

**Pricing attack:** this is NOT a few-line fix. Point.as, Rectangle.as and Matrix.as total 519 AS
lines and must be hand-compiled to C over a helper layer (below). Expect about 1.2–1.5k C lines.
Confidence is high for the gnash rows, which differ by only a few lines each. It is medium-high for
the avm1 rows, which are long strict-order traces that a faithful port should match byte for byte.
Also needs **M5**, or the harness's own `tracingMethod` lines stay wrong.

### M2. AsBroadcaster isn't ActionScript (as_broadcaster, AsBroadcaster-v6..v8: 4 tests)

Owner: `builtin_broadcaster_addListener` `action.c:36994`, `_removeListener` (next function),
`_broadcastMessage` (`:37094`), `builtin_asbroadcaster_initialize` `:39309`. Upstream `c2a878a68`
(`AsBroadcaster.as`, 55 lines; `broadcast_internal` stays native as `ASnative(101,12)`).
Flash behaviour we lack:
- addListener dispatches `this.removeListener(l)` then `this._listeners.push(l)`. This is all 5
  gnash lines (AsBroadcaster.as:151-164) and the `call broadcaster.removeListener` /
  `call listeners.push` lines.
- removeListener reads `length` on every iteration, compares with `==`, and dispatches `splice`
  (`get listeners.length / .0 / .1`, `call listeners.splice(1, 1)`).
- initialize assigns through setters in the order broadcastMessage, addListener, removeListener,
  `_listeners`. It creates a **new** native broadcastMessage each time (`=== AsBroadcaster.…` is
  false), reads `AsBroadcaster.addListener`/`removeListener` from the *global* (through
  `__resolve`), and applies flags 3 (DONT_DELETE, so `delete broadcaster._listeners` is false).
  The AsBroadcaster object itself gets flags 131.
- broadcastMessage snapshots the listeners up front (listeners removed mid-broadcast are still
  called), uses generic `length`/index reads (array-likes, `__proto__` swapped), boxes primitive
  listeners (`String.prototype.event1` called), and returns `true`/`undefined`.
- One line needs M3 (`[]` resolves `_global.Array`); 3 lines need M5 (closure `valueOf` called
  from `==`).

### M3. Array creation doesn't resolve `_global.Array` (array_constructor, array-v6..v8, plus 1 line of as_broadcaster)

Owner: `actionInitArray` `action.c:51528` (uses `getVersionedArrayProto`, `:51580`). Also the
`arguments` setup (`:8446-8480`), `String.split`, and `Array()` called as a function.
Upstream `dd4e73d59` (`ArrayBuilder::new`): every array literal, `arguments` object, `split` result
and `Array()` call gets own `__proto__ = _global.Array.prototype` (a data read that ignores getters
and attributes) and own `constructor = _global.Array` (both DONT_ENUM|DONT_DELETE), resolved **at
creation**. `new originalArray()` keeps the inherited constructor. Expected rows: `[1]: constructor:
own Array`, `delete constructor: false`, the `_global.Array = {prototype: 5}` / `{}` / deleted /
getter rows, and gnash array.as:1763-1793.
Perf note for wave 2: don't allocate `props` per literal. Treat `constructor` as a virtual own
DONT_ENUM|DONT_DELETE property and materialise only when `_global.Array` (or its `prototype`)
differs from the original.

**M3b crash** (the SEGFAULT): `builtin_object_hasOwnProperty` `action.c:4562` casts
`this_obj` to `ASObject*` even when `g_call_this_type == ACTION_STACK_VALUE_ARRAY`
(`hasOwnProperty.call(array, "constructor")`), and dies in `findPropertySlot`. The prototype routes
it to `callArrayMethod`'s existing `hasOwnProperty` arm (`:65978`): segfault → 42/53, with the
remaining 11 lines all M3.

### M4. ContextMenu / ContextMenuItem aren't ActionScript (context_menu, context_menu_item, context_menu_swf6)

Owner: constructor bodies inside `actionNewObject` (`action.c:59478-59560`, keyed on
`g_stub_ctors[4]`/`[5]`); `copy`/`hideBuiltInItems` `:2883-3040`; prototype init `:41319-41370`.
Upstream `8885104f0`, `dae634d8d` (58 + 29 AS lines). The gaps:
- **(a)** ctor args are not coerced: `caption` is taken raw (`null`, `0`, `NaN`), and
  `separatorBefore`/`enabled`/`visible` use `x == null ? default : x` (we force booleans and ignore
  args 3-4).
- **(b)** the ctors must work when called as functions (`ContextMenuItem.call(obj, …)` sets 5 props
  on `obj`; we set none).
- **(c)** prototype flags `ASSetPropFlags(proto, null, 1027)` hide `copy`/`hideBuiltInItems` below
  SWF7. That is all 3 lines of context_menu_swf6.
- **(d)** `copy()` constructs through the *global* ctor, reads through getters, and dispatches
  `customItems.push` and each `item.copy()`.
- **(e)** `customItems = new Array()` goes through the global Array (the "with Array replaced" rows).

### M5. Closure scope missing on two invocation arms (cross-cutting; prerequisite for M1/M2 harness lines)

- `actionCallMethod`'s object-method arm (`action.c:69639`, comment at `:69613`) uses
  `INV_SUPER_CTX | INV_LOCAL_SCOPE | INV_EXEC_FUNC` with no `INV_CAPTURED_SCOPE`. Its comment
  calls this a "load-bearing asymmetry (plan §3)". But `function-dispatch-consolidation-plan.md`
  §Step 3 shows it was preserved during a behaviour-preserving refactor, not chosen for Flash
  parity. Flash (and Ruffle `Activation::from_function`) always runs a function in its defining
  scope.
- `objectToPrimitive`'s valueOf call (`action.c:15524`): "No scopes, no exec-func — never done."
- **Evidence:** with debug prints, the `tracingMethod` wrapper is invoked with `flags=0x214
  cap=0 fcap=1`. The closure has a captured scope that the arm drops.
- **Prototype:** add `INV_CAPTURED_SCOPE` to the first arm, and `INV_CAPTURED_SCOPE|INV_LOCAL_SCOPE`
  to the second. Results:
  - matrix shows `call matrix.createBox(2, 3, 0, 4, 5)` and rectangle shows
    `call self.intersection(...)`.
  - as_broadcaster's `valueOf listener` line comes right.
  - All 13 regression tests in the closure/method family still pass: `ei_closure_scope_order`,
    `sort_comparator_captured_scope`, `nc_onstatus_closure`, `*_type1_args`, `coerce_*`,
    `mc_method_v5_caller_gate`.
  - No verdict moved in the 44 drift rows. These tests still fail on M1/M2 until the ports land.
- **Blast radius:** every object-method call on a closure. Wave 2 must run CI with
  `categories=full` in both modes. The prototype adds the captured frames **on top of** the
  caller's chain; it does not reset the chain. Fully matching Flash would also hide the caller's
  chain (`CF_RESET_SCOPE`). Leave that for a follow-up and measure separately.

### M6. AsSetupError is a no-op (as_setup_error)

`action.c:5362`: `{&g_asSetupError_ctor, "AsSetupError", (Function2Ptr)builtin_noop_func}`.
Upstream `31223a80a` (Error.as, 28 lines): `names.split(",")` by dispatch, then
`length`/index reads through getters. For each name it does `new Error()` through the global
(Flash also finds `_root.Error` first: the one line Ruffle misses) and sets `name` before
`message`. A Ruffle-exact port gives ruffle_matched. Resolving `Error` via the caller's scope chain
gives a full pass. Our existing native `Error` class seems fine; only `AsSetupError` needs work.

### M7. htmlText (`8cbada89a..16b334374` series)

- **(a) Last attribute wins, case-insensitive.** Ruffle `69a017387`. Owner `tf_get_attr`
  `action.c:26729` (first match; also matches substrings). Flash takes the last occurrence even
  when it is invalid: `size='10' size='abc'` gives 12 (default); `align='right' align=''` gives
  LEFT; `href='…' href=''` gives no link.
  Prototype (last-wins plus a word-boundary check): edittext_html_duplicate_attributes 176 → 181,
  capped by M7b. 10 `edittext_html_*` tests, `html_text_img_parsing_swf6` and gnash
  `TextFieldHTML-v5..v8` all still pass.
- **(b) setNewTextFormat device font isn't the html default face.** `setNewTextFormat`
  (`action.c:72799`) stores only `_tf_fontId` (an id lookup by name). A device font such as
  "Times" has no SWF font id, so `tf_get_defaults` (`:26612`, `:26616`) falls back to
  `"Times New Roman"`. This breaks the `FACE=` on almost every resultHtml line of
  edittext_html_duplicate_attributes and on html_text_img_numeric_attributes. The `swf5..8` img
  tests hide it, because their `escapeText` rewrites "Times New Roman" to "Times". Fix: store the
  font **name** too (`_tf_fontName`) and prefer it in the `tf_get_defaults` callers (`:22705`,
  `:57088`).
- **(c) `<img>` for SWF ≥ 7.** Ruffle `8cbada89a`, `306bd25eb`, `489456d4f`, `104ee6ae4`,
  `fbea97b91`, `16b334374`. We drop `<img>` in every version (we pass SWF6 only because SWF6 drops
  it too). Flash, SWF7+:
  - inserts a placeholder space (`TEXT=A B`);
  - serialises `<FONT SIZE="2"><IMG SRC=… [WIDTH HEIGHT ID ALIGN VSPACE HSPACE CHECKPOLICYFILE]> </FONT>`;
  - nests IMG inside `<A>` for SWF8 and outside it for SWF7 (Ruffle `text_format.rs:1694-1704`);
  - keeps `align` case-sensitive;
  - writes CHECKPOLICYFILE only when true;
  - decodes entities in src/id;
  - and per the Flash output, parses **numeric prefixes** (`40.9px` → `WIDTH="40"`). That last
    one is the Ruffle TODO that makes html_text_img_numeric_attributes a Ruffle KF. Implement the
    Flash behaviour.

  Owner: `tf_parse_html` `action.c:26815` plus the htmlText serializer. This is the 171-line bulk
  of swf7/swf8.
- **(d) SWF5.** Flash prints `TEXT=` (empty) and `HTML=` the raw source, for all 85 cases and the
  reparse rows. We parse it. Ruffle passes the test, but I couldn't locate its mechanism in the
  time available. One related fact: `globals_swf5:136` shows Flash has `typeof TextField.prototype
  == "undefined"` in SWF5, while we (and Ruffle) say `object`. That fits "in SWF5 the field has no
  TextField getter/setter props, so `htmlText` becomes a plain property and `text` reads as
  undefined, which SWF5 prints as empty". It is a hypothesis, not proven. **HOLD**: the completion
  mechanism is a 1-hour Ruffle-source read in wave 2 (`stage_object.rs` SWF5 paths, around
  `:538` and `:595-601`, and the EditText `text` getter under SWF5) before any patch.

## 3. Which upstream commits encode Flash behaviour we lack (brief item 3)

Each line below is Flash behaviour per the `output.txt` files. The ruling is Flash over Ruffle, and
where Ruffle still fails (KF) we follow Flash.
- **`82b84d3e5` / `c717e9dc8` / `ee9791463` (Point/Rectangle/Matrix to AS):** YES. Flash is AS
  here. M1.
- **`c2a878a68` (AsBroadcaster to AS):** YES. M2. It also rewrote the TextField/argstest
  `ruffle.txt` files (no verdict move for us).
- **`8885104f0` / `dae634d8d` (ContextMenu/Item):** YES. M4.
- **`31223a80a` (Error/AsSetupError):** YES for AsSetupError (M6). Flash additionally resolves
  `Error` through `_root`, which Ruffle doesn't.
- **`dd4e73d59` (global Array at creation):** YES. M3. Note its player-version split ("FP 9-17
  don't set `constructor` when the global Array has no `prototype`, FP 24+ do"). We grade the
  highest variant (`fp24`) and should follow the FP24 branch.
- **`8cbada89a..16b334374` (HTML `<img>`, reversed attribute lookup):** YES. M7a/M7c. Plus two
  Flash behaviours Ruffle still lacks: numeric-prefix image attributes, and kerning/class rows in
  edittext_dup (Ruffle `ruffle.txt` misses 2 lines).
- **`b8793d8a6` (don't trim single device font names):** fonts suite, owned by sibling
  `w1-drift-avm2`.
- **`55e5f5b74`, `0c71add8d`, `e2*`/`2d27*`/`e25c*` (SwfMovie plumbing), `a407c51ef`,
  `6422e8592`:** refactors, no observable AVM1 change for us.

## 4. Wave-2 slots I would fund (one line each, expected flips by name)

1. **S1 — AS-semantics core. GO, ~9 flips.** Land a small static helper layer in `action.c`:
   `as_get`/`as_set` through `actionGetMember`/`actionSetMember` (getters, setters, `__resolve`),
   `as_call_method`, `as_new_global`, and AS operators through the `actionAdd2`/`actionEquals2`
   stack ops. On top of it, port `AsBroadcaster.as`, `ContextMenu.as`, `ContextMenuItem.as` and
   `AsSetupError` from Error.as, and apply **M5** (both flags). Expected:
   - **as_broadcaster, AsBroadcaster-v6, -v7, -v8**: the AsBroadcaster port, plus one line from S2
     for as_broadcaster.
   - **context_menu, context_menu_item, context_menu_swf6**: the ContextMenu ports.
   - **as_setup_error**: full pass if `Error` resolves through the scope chain, otherwise
     ruffle_matched.

   CI: `categories=full`, both modes (M5 touches every object-method call). Regression fixture:
   the as_broadcaster/context_menu tests already pin it. Add a `regression/` closure-as-method
   fixture only if an oracle is available (LOCAL ORACLE request below).
2. **S2 — array creation resolves `_global.Array`, plus the hasOwnProperty array crash. GO, 4
   effective.** Expected: **array_constructor** (pass; it is a segfault today); **array-v6, -v7,
   -v8** back to ruffle_matched; plus as_broadcaster's `with Array replaced` line, which S1
   needs. Use the lazy materialisation from §M3 (perf). Port the crash fix from the
   prototype patch hunks 1-2 as is.
3. **S3 — geom port (Point → Rectangle → Matrix), after S1's helpers and M5. GO, 7 flips.**
   Expected: **point, rectangle, Rectangle-v8, matrix, Matrix-v6, Matrix-v7, Matrix-v8**. Keep
   the native construction sites (BitmapData.rectangle, `transform.matrix`, getBounds/getRect,
   etc.) building instances through the global `flash.geom.*` prototypes, so the ported methods
   apply to them. Run the graphics canary: geom objects feed transforms. If wave-2 capacity is
   tight, split it: S3a Point+Rectangle (3 flips) and S3b Matrix (4 flips).
4. **S4 — htmlText. GO, 4 flips.** Expected:
   - M7a last-wins attributes: **edittext_html_duplicate_attributes**, with M7b and the M7c img
     rows;
   - M7b setNewTextFormat font name;
   - M7c `<img>` for SWF7/8 including numeric prefixes: **html_text_img_parsing_swf7, _swf8,
     html_text_img_numeric_attributes**.

   Port hunk 4 of the prototype for M7a. Pin with the 10 `edittext_html_*`, 4 gnash
   `TextFieldHTML-v*` and `html_text_img_parsing_swf6` (all passing now).
5. **HOLD — html_text_img_parsing_swf5 (M7d).** Completion mechanism: locate Ruffle's SWF5
   behaviour first (§M7d), then decide. It could fold into S4 if it is a single SWF5 gate.

Total GO yield if all land: **24 test flips**: 17 of them recover drift losses and 7 are the new
or rewritten tests.

## Refutations / premise checks

- **"Five passes became fails"**: undercounted. The visible pass→fail set is 6 (point, rectangle,
  matrix, context_menu, context_menu_item, Rectangle-v8), plus 2 hidden (as_broadcaster,
  array_constructor). Visible ruffle_matched→fail is 3 (Matrix-v6..8), plus 6 hidden
  (AsBroadcaster-v6..8, array-v6..8). The coordinator should pre-label these 8 hidden rows as
  drift before the next CI read.
- **"Cheapest re-flips"**: true for M2/M3/M4/M6 (tens of AS lines each). False for the avm1 geom
  trio: they are strict access-order traces and need a ~500-AS-line faithful port (S3).
- **array_constructor isn't pure drift**: the new test exposes a **latent segfault**
  (`hasOwnProperty.call(array, …)`) that any game could hit. Fix it regardless of grading.
- **The "load-bearing asymmetry" in the method arm** (M5) is a preserved refactor artefact, not a
  Flash rule. The prototype shows it can be dropped without touching the regression family that
  pins scope order.

## New unclaimed leads

1. **`avm1/global_instance_decls` is nondeterministic on unchanged code.** Two clean
   `origin/master` graphics runs gave 13/758 (815 lines) and 26/758 (786 lines). The difference is
   one `_global.flash.display.BitmapData` row: once `instance=[undefined]`, once a real object with
   its whole property dump. Suspect an uninitialised read on a no-arg or invalid-arg
   `new BitmapData` path (`pushBitmapDataConstruct` `action.c:14999` looks clean; check
   `actionNewMethod`'s two BitmapData arms near `:59216`/`:59698`). The test is IGN, but the
   nondeterminism is a correctness bug. Suggest owner `w1-trace-tail`.
2. **The `globals_swf5` disposition conflicts with the Flash-over-Ruffle ruling.**
   `RUFFLE_VS_FLASH_DIFFERENCES.md:156-175` says Flash hides LocalConnection, NetConnection and
   Video in SWF5. But `globals_swf5/output.txt` (Flash) shows all three as `[type Function]`,
   `function`, `object`. These are 9 of our 10 diff lines. Either the corpus `output.txt` is not
   from Flash for these rows, or the disposition is wrong (gnash `*-v5` evidence vs a newer Flash
   Player). Re-test the claim per standing rule 2.
3. **The AS "prelude" architecture.** Ruffle now builds `playerglobal_avm1.swf` (`globals.as`
   includes AsBroadcaster, ContextMenu, ContextMenuItem, Error, Point, Rectangle, Matrix; 722 AS
   lines) with its own compiler (`core/build_playerglobal/src/avm1.rs`). We could recompile that
   SWF with SWFRecomp into a startup prelude that runs before frame 1. That gets exact Flash
   semantics for all six classes, and future upstream migrations nearly free. Costs: needs
   `ASnative(101,12)`, `ASnative(100,4)` and `ASSetPropFlags` 131/1027/4096 support; native
   construction sites must use the prelude's prototypes; perf of hot geom calls. It is a
   strategic alternative to S1/S3's hand ports, and needs the artifact (oracle request 1).
4. **The M5 follow-up**: the method arm still exposes the **caller's** scope chain underneath the
   captured frames (no `CF_RESET_SCOPE`). Flash doesn't. Measure that separately after S1.

## LOCAL ORACLE REQUESTS

1. **Ruffle `playerglobal_avm1.swf` at `45366370e`**, only if the coordinator wants to evaluate
   lead 3. It is in the local Ruffle build's OUT_DIR:
   `target/*/build/ruffle_core-*/out/playerglobal_avm1.swf`, built by `core/build.rs`. Archive it
   with its SHA. It is not needed for S1–S4.
2. **A closure-as-method regression fixture oracle** (for S1/M5). A small SWF6+ AS2 movie:
   `function mk(n){ var o={}; o.f=function(){ trace(n); }; o.valueOf=function(){ trace("v"+n); return 1; }; return o; } var a=mk("A"); a.f(); trace(a==1);`.
   Expected per Flash/Ruffle: `A`, `vA`, `true`. Run the Ruffle exporter to confirm the output, so
   wave 2 can add it under `regression/`. Compile with MTASC locally.
