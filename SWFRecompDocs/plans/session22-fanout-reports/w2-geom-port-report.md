# s22 wave 2 — `w2-geom-port`: flash.geom Point / Rectangle / Matrix ported to ActionScript semantics

**New files in this commit:**
- `SWFRecompDocs/plans/session22-fanout-reports/w2-geom-port-report.md` (this report)
- `SWFRecompDocs/plans/session22-fanout-reports/w2-geom-port.patch` (= `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`; one file touched, `SWFModernRuntime/src/actionmodern/action.c`; proven with `git apply --check -R`)

No new source files, no new fixtures, no recompiler change, no `render_canary_tests.txt` change.

**Setup:** cloud box, `SETUP_STATUS` all OK (apt, Pillow, Dawn). Base `origin/master` = `b47c2821d`
(includes `w2-as-core` `0cea97b3e` and `w2-array-global` `d9c78d14b`). `download_tests.sh avm1 from_gnash
visual avm2 text fonts from_shumway`, upstream Ruffle master at download time (`git ls-remote` at report
time: `653ef4f41`). Ruffle source clone at `45366370e`. Every A/B below is on this box, **clean
`origin/master` (a separate worktree) vs this patch**, run side by side.

## TL;DR — GO, all 7 brief flips, nothing else moves

| verdict | tests |
|---|---|
| **flips to pass (trace, both modes)** | `avm1/point`, `avm1/rectangle`, `avm1/matrix`, gnash `Rectangle-v8`, `Matrix-v6`, `Matrix-v7`, `Matrix-v8` |
| `avm1/globals_monkeypatch` | **unchanged**: output_mismatch 41/246 before and after (its geom getter rows did not move; the mismatch is elsewhere) |
| pixel axis | **no movement**: render canary 125/125 + 6/6 extra geom-row comparisons md5-identical |
| perf | native construction sites untouched (same C fast path); script-level geom method calls ~2.3x slower in a 20k-iteration microbench (faithful VM ops); details below |

All seven flips are full **pass** (none has `known_failure`; upstream removed KF from the gnash rows).

## Per-test before/after (same box, clean master vs patch)

| test | before, graphics | after, graphics | before, no-graphics | after, no-graphics |
|---|---|---|---|---|
| avm1/point | fail 54/329 | **pass 329/329** | fail 54/329 | **pass 329/329** |
| avm1/rectangle | fail 141/629 | **pass 629/629** | fail 141/629 | **pass 629/629** |
| avm1/matrix | fail 57/810 | **pass 810/810** | fail 57/810 | **pass 810/810** |
| gnash Rectangle-v8 | fail 145/166 | **pass 166/166** | fail 145/166 | **pass 166/166** |
| gnash Matrix-v6 | fail 139/168 | **pass 168/168** | fail 139/168 | **pass 168/168** |
| gnash Matrix-v7 | fail 140/168 | **pass 168/168** | fail 140/168 | **pass 168/168** |
| gnash Matrix-v8 | fail 140/168 | **pass 168/168** | fail 140/168 | **pass 168/168** |
| gnash Point-v8 | pass 193/193 | pass | pass | pass |
| gnash Point-v5 / Rectangle-v5 / Matrix-v5 | pass 7 / 7 / 7 | pass | — | pass |
| avm1/globals_monkeypatch | fail 41/246 | fail 41/246 | fail 41/246 | fail 41/246 |

## EXPECTED-FLIP LEDGER (for the coordinator's CI read)

Trace axis, **both modes** (`graphics` and `no-graphics`):
- `avm1/point`: output_mismatch 54/329 → **pass** (drift re-flip; the test was rewritten upstream).
- `avm1/rectangle`: output_mismatch 141/629 → **pass** (drift re-flip; CI's 10-03 file may still show the 617-line version).
- `avm1/matrix`: output_mismatch 57/810 → **pass** (drift re-flip; CI graphics 10-03 may still show the OLD 171-line test as pass, so CI may read it as pass → pass).
- `from_gnash/actionscript.all/Rectangle-v8`: output_mismatch 145/166 → **pass**.
- `from_gnash/actionscript.all/Matrix-v6`, `-v7`, `-v8`: CI 10-03 shows ruffle_matched (old corpus with KF); current corpus output_mismatch 139/140/140 of 168 → **pass**.

Pixel axis: **none**. Expected NON-moves: every other row listed under "Sweeps" below.

CI recommendation: `categories=full`, both modes. The diff touches `actionGetMember`/`actionSetMember`
(two geom special cases deleted) and the shared as_* helper layer.

## What the patch does (`action.c` only; all inside the geom block, the helper block, and two deletions)

### 1. The three classes, hand-compiled from Ruffle's `.as` (spec) in Flash order
`Point.as` (99 lines), `Rectangle.as` (236), `Matrix.as` (184) are ported statement by statement into
the existing natives (same names, same registration, same prototype objects and enumeration order;
the old block `// --- Point methods ---` … `// --- Geometry initialization ---` is replaced). Each
method:
- reads/writes every property with `as_get`/`as_set` (getters, setters, `__resolve`, watchers fire) in
  the AS statement order, including compound assignment order (`this.x -= pt.x` reads `this.x` first);
- uses the VM's own operators: `+` = Add2 (string concat for `'1'` args: `right = '13'`, `tx = 1002`),
  `-`/`*`/`/` = Subtract/Multiply/Divide, `<` = Less2, `>` = Greater, `<=`/`>=` = `!(a > b)` / `!(a < b)`
  as Flash compiles them (so NaN compares TRUE — `isEmpty` of a NaN rect, `contains(NaN, 5)` continuing
  past the first test), `==` = Equals2, `===` = StrictEquals, `!` = Not, `instanceof` = InstanceOf;
  `&&`/`||` pass the deciding VALUE through (`contains(4, NaN)` → `undefined`);
- dispatches internally through the receiver (`this.isEmpty()`, `this.setEmpty()`, `this.identity()`,
  `this.concat()`, `this.rotate()`, `this.scale()`, `this.createBox()`, `this.deltaTransformPoint()`,
  `this.intersection()`, `toUnion.clone()`, `pt1.subtract(pt2)`), and calls `Math.sin/cos/sqrt/max/min`
  through the current global `Math` (the test overrides `Math.cos/sin` and traces them);
- constructs results with `new flash.geom.<Class>(…)` resolved at call time (`geomClass`: `_global.flash
  .geom.<Class>` read raw so it resolves in every SWF version, as the class bodies' SWF8 code does;
  a replaced `flash.geom.Point` is honoured) and constructed through NewMethod, so the ctor's own
  semantics (0-arg `setEmpty()`/`identity()`, y-before-x) apply.
- Arithmetic runs at the CALLER's SWF version (gnash Matrix-v6 expects `"(a=8, b=, …)"` in SWF6), which
  the VM ops give for free.
Accessors: Point `length` gets its no-op setter, and all seven Rectangle edge/corner/size properties get
their setters (before: only `left`/`top`, the rest READ_ONLY); all with default `addProperty` flags.

### 2. Deleted shortcuts that bypassed the prototype accessors
- `actionSetMember`: a hard-coded "Rectangle computed property setters" block (keyed on
  `__proto__ == g_rect_prototype`) that did raw-double writes and returned before watchers/setters.
- `actionGetMember`: a matching "Geometry computed properties" block for `Point.length` and the
  Rectangle getters. (It was effectively shadowed by the prototype accessors already; deleting it also
  stops it answering after a user deletes/overrides the prototype property.)
Both are replaced by the generic virtual-property path, i.e. the ported accessors.

### 3. Helper layer: additions only (contracts unchanged)
Documented in the block header. `as_sub`, `as_mul`, `as_div`, `as_lt`, `as_gt`, `as_le`, `as_ge`, `as_not`
(all return the op's VALUE), `as_truthy`, `as_strict_equals`, `as_instanceof`, and **`as_key`**.
`as_key` fixes a leak in the landed layer: `as_str` mallocs a UTF-16 buffer nothing frees (stack strings
are non-owning), and `as_get`/`as_set`/`as_call_method`/`as_new_global` built every member name with it,
leaking one allocation per property access — unbounded once geom objects (hot, per-frame) go through it.
Member keys are now interned by content in a 512-slot process-lifetime table (falls back to `as_str` if
probing runs long). Same STRING value, same semantics; as-core's 13 headline rows re-run identical.

### 4. Native construction sites (brief requirement)
`createPointObj`, `createRectObj`, `makeMatrixObject` and their callers (`transform.matrix` /
`concatenatedMatrix`, `getBounds`/`getRect`, `BitmapData.rectangle`, filter/gradient matrices, …) are
**unchanged**: they still build plain objects directly on `g_point_prototype` / `g_rect_prototype` /
`g_matrix_prototype`, which are the very prototypes `flash.geom.*.prototype` names, so the ported methods
apply to them, and they pay nothing for script-level construction. Native READS of geom objects
(e.g. the `transform.matrix` setter reading `a…ty`) stay raw (no getter rows depend on them).

### 5. Receiver caveat handled
`as_this` trusts `g_call_this_type`, and that global is held at ARRAY across an array native's callbacks
(e.g. a sort comparator). Accessors (`r.right` read inside such a comparator) are invoked through
`invokePropertyGetter/Setter`, which never set it, so the accessors use `geomAccessorThis` (a non-NULL
receiver is an object) instead of `as_this`. Methods keep `as_this` (the CallMethod arms set the tag).

## Sweeps and regression evidence

All rows below were re-run on the FINAL tree (after the `as_key` / accessor-receiver edits); the final
runs are identical to the first after-runs, and graphics vs no-graphics are per-test identical on all 89
rows of the final list.


- **Every AVM1 row in the downloaded corpus that references flash.geom** (SWF string scan for
  `geom` + `Point|Matrix|Rectangle`, AVM2 SWFs filtered with `swf_is_avm2.py`): **66 rows** (47 avm1,
  12 gnash, 7 visual), both modes, clean master vs patch: **exactly the 7 ledger rows move; the other 59
  are identical** (status and matched/expected lines) in graphics and in no-graphics. Includes every
  `bitmap_data*` / `bitmapdata_*` row, `transform`, `bitmap_filters`, `native_subclasses`,
  `constructor_function`, `globals_swf5..8`, `global_instance_decls`, `native_objects_swf6..8`, gnash
  `BitmapData-v8`, `MovieClip-v8`, `Transform-v8`, `Point-v8`, ming `BeginBitmapFill`, `BitmapDataDraw`,
  `DrawingApiTest`, `GradientFillTest`, and the 7 visual AVM1 geom rows.
- **Globals/flags/instanceof rows, 10, graphics A/B** (prototype flag change could show in enumeration):
  `global_proto_decls` (fail 803/4497), `global_proto_decls_delete` (fail 461/4158), `global_swf5_6_7_8_9`,
  `global_swf6_7_8`, `typeof_globals`, `asnative`, `as_set_prop_flags`, `instanceof_coercions`,
  `primitive_instanceof`, `global_is_bare`: **identical before/after**.
- **as-core headline rows on the final tree** (as_key touches its helpers): `as_broadcaster`,
  `as_setup_error`, `context_menu`, `context_menu_item`, `context_menu_swf6`, gnash `AsBroadcaster-v6..8`,
  `ContextMenu-v7/8`: all pass, identical to clean master.
- **AVM2 sample, 10 rows, graphics A/B** (122 AVM2 SWFs reference flash.geom; AVM2 has its own geom in
  `avm2_*` and cannot reach these AVM1 natives, so a sample): `avm2/point`, `rectangle`, `matrix`,
  `geom_transform`, `displayobject_transform`, `displayobject_scrollrect`, `blend_transform`,
  `bitmapdata_rectangle_rounding`, `bitmapdata_applyfilter_destpoint`, `matrix3d_invert`: **identical**.
- **`regression/` suite, all 101, graphics, final tree: 101/101 pass** (= CI's 10-03 file, 101/101).
- **Graphics render canary** (`render_canary.py`, standing set: 70 tests / 125 comparisons): **IDENTICAL
  125, DIFFERS 0**, no trace or image status changes. Plus an extra capture of 9 geom-feeding rows
  outside the set (`avm1/transform`, `bitmap_data`, `bitmap_filters`, visual `scroll_rect`,
  `scroll_rect_scaled`, `fills_and_lines`, `gradient_focal_point`, `scroll_rect_mask`,
  `edittext_device_transform_small_shear`): 6 PNGs, **IDENTICAL 6**. No canary member added: the change
  class (script-level AVM1 geom methods) has no render-path effect, and the native construction sites
  that do feed transforms are byte-unchanged.

## Perf A/B (brief requirement)

Throwaway hand-assembled SWF8 probe (not committed; `/tmp` generator), 20,000 iterations of:
`new Matrix()`; `translate`; `rotate`; `scale`; `transformPoint(new Point)`; two `new Rectangle(…)` +
`union`; and the native round-trip `mm = _root.transform.matrix; mm.concat(m); mm.identity();
_root.transform.matrix = mm`. Trace output byte-identical on both legs. Run phase, graphics, 5 runs each:

| leg | run time (s) |
|---|---|
| clean master | 1.17, 1.12, 1.17, 1.12, 1.17 (≈1.15) |
| patch (final, with `as_key`) | 2.73, 2.63, 2.78 (≈2.71); before `as_key`: 2.82–3.08 |

≈ +78 µs per iteration for ~13 script-level geom calls (≈6 µs per call) on this box. callgrind: the cost is
spread over the faithful VM ops themselves (`actionSetMember` 16 %, `actionNewMethod` 17 % inclusive,
property lookups); nothing geom-specific dominates. This is the price of matching Flash's observable order
(each `concat` is 14 GetMember + 6 SetMember unskewed, 26 + 6 skewed, exactly the bytecode Flash runs). The **native** paths that
feed transforms are not on this curve.

## Not done / HOLD (with completion mechanism)

- **Script-level geom speed** (above). Completion: if a game profile shows geom calls hot, add an
  `as_set` / `as_get` fast path for a plain OBJECT receiver with an own data property, no watchers, no
  accessors anywhere on the chain — measured with the canary + this sweep. Not done here: duplicating
  SetMember's rules is the risk this port exists to remove.
- **Native READS of geom objects stay raw** (`transform.matrix = m` reads `m.a…ty` without getters,
  `BitmapData` methods read rect/point args raw). Flash/Ruffle read them through `get`. No corpus row
  traces them. Completion: route the readers through `as_get` if a trace row appears.
- **Bare-call factory paths kept**: `Point()` / `Rectangle()` with NO receiver at all (this_obj NULL)
  still return a new instance (pre-existing behaviour). With any receiver they now run the AS body on it,
  as Flash does.

## Refutations / premise checks
- "Needs M5 or the harness's `tracingMethod` lines stay wrong": M5 is on master (as-core); confirmed —
  every `call self.isEmpty()` / `call self.concat(…)` row matches with no further scope work.
- "Rectangle: port the methods": also needed the two hard-coded Get/SetMember geom shortcuts deleted
  (`self.left = 0` never reached the prototype setter), and setters for the five READ_ONLY accessors.
- "as_* layer ready to reuse as is": it leaked one malloc per member access (`as_str` keys); fixed by
  `as_key` (additive, contracts unchanged).

## New unclaimed leads
1. **`as_str` values still leak** wherever a helper user builds a dynamic string VALUE with it (e.g.
   as-core's ContextMenu paths). Low volume; a per-app string arena or `as_key` for literals would close it.
2. **`g_call_this_type` stays ARRAY across an array native's script callbacks** (sort comparator,
   forEach-likes): any type-2 native reached from such a callback by a path that does not reset it and
   uses `as_this` would misread an object receiver as an array. The geom accessors are guarded; a general
   fix is to clear it in the callback invocation.

## LOCAL ORACLE REQUESTS
none
