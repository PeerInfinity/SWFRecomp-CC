# Ruffle vs Flash Spec Differences

Tests where the Ruffle expected output appears to match Ruffle's own implementation rather than Flash Player's actual behavior. These are cases where we match Flash's spec/behavior but fail the Ruffle test.

## For-In Enumeration Order

**Test:** `xml_attributes_read`

Flash Player enumerates object properties in **reverse insertion order** (last-inserted property iterated first). This is because for-in pushes properties onto the stack in forward order and the LIFO stack reverses them.

Ruffle's expected output for XML attribute enumeration shows **forward insertion order** (first attribute iterated first: `attrx` before `attry`). Our implementation correctly produces reverse insertion order matching Flash, but this doesn't match the Ruffle test expectation.

Reversing attribute storage order to match Ruffle's expectation breaks `xml_namespaces` (203/203 → 197/203) because namespace resolution walks attributes and depends on storage order.

**Decision:** Keep Flash-correct reverse insertion order. Accept `xml_attributes_read` as a known Ruffle difference.

## Sprite Frame 0 Child Visibility

**Test:** `stage_object_enumerate`

In Flash Player, when a sprite is placed via PlaceObject2, its frame 0 **placement tags** (PlaceObject2, SetInstanceName) execute immediately, but frame 0 **scripts** (DoAction) are deferred to ShowFrame. This means child display objects exist and can be enumerated by parent scripts, but child scripts don't run until ShowFrame.

Our recompiler emits sprite frame functions as single C functions mixing both placement tags and scripts. There's no `if (!catch_up_mode)` guard on sprite-level scripts (only root frame scripts have the guard), so we can't selectively execute placement-only. Eager execution breaks `execution_order1`, `execution_order2`, `variable_args`, and `define_function2_preload_order`.

**Decision:** Keep deferred sprite init (correct execution order for 4+ tests). Accept `stage_object_enumerate` as needing a recompiler-side fix to add `catch_up_mode` guards to sprite frame scripts.

**Note:** This is not strictly a Ruffle difference — it's a limitation of our recompiler's code generation that prevents us from matching Flash's split placement/script behavior.

## SWF6 `new TextField()` Returns Object, Not Undefined

**Test:** `native_objects_swf6`

In Flash Player, `new TextField()` returns a valid object in SWF6 (and all other versions). Our fully-passing `textfield_props_swf6` test (all lines match) confirms this — it creates `new TextField()` and exercises its properties as an object.

Ruffle's `native_objects_swf6` test expects `new TextField(): non-object: undefined`, suggesting Ruffle's SWF6 implementation returns `undefined` for `new TextField()`. The test is also marked `known_failure = true` in its own `test.toml`, confirming Ruffle knows this expectation is questionable.

```diff
- new TextField(): non-object: undefined
+ new TextField(): native
```

**Decision:** Keep Flash-correct behavior (`new TextField()` returns an object in SWF6). Accept the 1-line diff as a Ruffle implementation difference.

## ~~SetTarget Debug Trace on Removed Base Clip~~ (RESOLVED upstream 2026-06-11)

**Test:** `removed_base_clip_tell_target` — **now passing; removed from ignored_tests.txt.**

This entry predicted correctly: the expected `Target not found: Target="_root" Base="?"` line was Ruffle's speculative emulation (their source carried a `// TODO: Emulate AVM1 trace error message.` comment), and Flash Player actually prints nothing. Upstream Ruffle removed the trace in `71864d539` (2026-06-10, "avm1: Remove 'Target not found' trace" — "Flash Player does not trace anything in this case") and regenerated the expected outputs. We removed our matching emission the same week.

With the trace gone from the expectation, the test exposed a real bug on our side (we printed `BAD`, not `GOOD!`): `actionSetTarget` did not fail named-target resolution (including `"_root"`) when the **base clip was removed** (Ruffle: `filter(|_| !self.base_clip.avm1_removed())` — "All properties invalid if base clip is removed"), and `actionPlay`/`actionStop`'s in-sprite arm ignored `g_settarget_explicit_root`, playing/stopping the executing sprite instead of the root. Both fixed 2026-06-11.

---

*See also: `FLASH_BUGS_REPLICATED.md` for documented Flash bugs we deliberately replicate (where Flash and Ruffle agree on the buggy behavior).*

## MCL Callback Unset Parameter Concatenation in SWF7

**Tests:** `mcl_replace_root_swf7_to_swf5`, `mcl_replace_root_swf7_to_swf6`

The test defines MCL callbacks with extra parameters beyond what broadcastMessage passes. For example, `onLoadStart = function(mc, rest) { trace("rest=" + rest); }` where `rest` is not passed by the MCL (only `mc` is). In SWF7, unset function parameters are `undefined`, and Flash's string concatenation rule is `"" + undefined` = `"undefined"`.

Our output correctly produces `rest=undefined` (SWF7 concatenation of undefined). Ruffle's expected output shows `rest=` (empty), suggesting either Ruffle treats unset parameters differently or Ruffle's string concatenation of undefined in this context produces an empty string.

```diff
  onLoadStart
    d=closure var
-   rest=
+   rest=undefined
    _target=/
```

This affects only the `onLoadStart` callback (1 line per test). All other callbacks fire after the SWF version switch to the child's version (SWF5/6), where undefined concatenates as `""` — those lines already match.

**Decision:** Accept 1-line diff per test. Our SWF7 `"" + undefined` = `"undefined"` behavior is correct per Flash spec.

## String Relational Comparison Uses UTF-8 Bytes vs UTF-16 Code Units

**Test:** `string_relational_compare` (3/4 lines match)

Flash Player compares strings using UTF-16 code unit values (matching ECMAScript spec). Ruffle compares strings using UTF-8 byte ordering (equivalent to Unicode code point comparison), as seen in `core/src/avm1/value.rs:490`: `a.bytes().lt(b.bytes())`.

This difference manifests when comparing BMP characters above U+D800 with supplementary characters encoded as surrogate pairs. For `"\uFF61" < "\uD800\uDC02"`:
- Flash (UTF-16 code units): first code units 0xFF61 vs 0xD800 → 0xFF61 > 0xD800 → `false`
- Ruffle (UTF-8 bytes / code points): U+FF61 (65377) vs U+10002 (65538) → `true`

```diff
     "\uFF61" < "\uD800\uDC02"
-    true
+    false
```

**Decision:** Accept 1-line diff. Our UTF-16 code unit comparison matches Flash Player and ECMAScript spec. Add to ignored_tests.txt.

## Filter Angle Property Precision

**Test:** `bitmap_filters` — now PASS via verifier `number_patterns` support

Ruffle stores filter angles internally as f64 radians. The default angle (45°) goes through a deg→rad→deg round-trip that produces `44.9999999772279` instead of `45`. Our implementation stores angles directly as degrees (Flash-correct behavior), so `new BevelFilter().angle` returns exactly `45`.

The 4 differing lines are default constructor angles for BevelFilter, DropShadowFilter, GradientBevelFilter, and GradientGlowFilter. Angles set from SWF tag data (stored as FIXED 16.16 radians) produce Ruffle-matching precision values (e.g., `49.9991703850277` for 50°) because the precision loss comes from the fixed-point encoding in the SWF binary itself.

```diff
- distance=4, angle=44.9999999772279, highlightColor=16777215, ...
+ distance=4, angle=45, highlightColor=16777215, ...
```

**Decision:** Implemented `[approximations.number_patterns]` support in `verify_output.py` so the test's own `number_patterns = ["angle=([\\d.]+)"]` + `epsilon = 0.001` config matches Ruffle's framework behavior. Each capture group is compared as a float with epsilon tolerance, and the rest of the line must match exactly. The 4 angle-only diffs now pass within tolerance, while still catching any structural differences. Companion fix: filter object property order in the timeline-reconstruction path (`actionGetMember "filters"` → FilterListData) was reordered to match Flash's enumeration order (e.g., BevelFilter: `..., quality, strength, knockout, blurX, blurY, type` instead of `..., blurX, blurY, strength, quality, type, knockout`). Test now PASS at 548/548.

## Object.prototype Methods ENUMERABLE by Default

**Tests:** `global_proto_decls` (~3700 lines affected), `global_proto_decls_delete` (~3870 lines affected)

In Flash Player, Object.prototype methods (toLocaleString, isPropertyEnumerable, isPrototypeOf, hasOwnProperty, toString, valueOf, addProperty, unwatch, watch) are **DONT_ENUM** — they do not appear in for-in loops. Similarly, `constructor` and `__proto__` on built-in prototype objects are DONT_ENUM.

In Ruffle, these are all **ENUMERABLE** by default. The `global_proto_decls` test was generated by Ruffle and its expected output reflects this: every prototype object listing includes ~9 inherited Object.prototype methods without the DONT_ENUM label, plus `constructor` and `__proto__` as non-DONT_ENUM own properties.

Confirmed by cross-referencing with Flash-behavior tests: `context_menu`, `context_menu_item`, `printjob_props_swf5/6/7`, `sound_props_swf5/6` all do for-in on built-in prototypes and expect NO inherited Object.prototype methods to appear. These tests all pass with our Flash-compatible DONT_ENUM implementation.

Additionally, Ruffle sets `constructor` as an **own property** on all objects (e.g., `System.capabilities` has `constructor, own, type=[function]`). In Flash, `constructor` is inherited from the prototype chain, not stored as an own property on each instance.

```diff
  Testing _global.ContextMenu.prototype
-   toLocaleString, type=[function]
-   isPropertyEnumerable, type=[function]
-   ... (9 inherited Object.prototype methods)
    hideBuiltInItems, own, DONT_ENUM, type=[function]
    copy, own, DONT_ENUM, type=[function]
-   __proto__, own, type=[object]
-   constructor, own, type=[function]
+   __proto__, own, DONT_ENUM, type=[object]
+   constructor, own, DONT_ENUM, type=[function]
```

This pattern repeats for every prototype object in the test (~50+ prototypes × ~11 lines each = ~550+ lines), making it the single largest source of mismatch in `global_proto_decls`.

**Decision:** Keep Flash-correct DONT_ENUM behavior. Accept as permanent Ruffle difference. Not added to ignored_tests.txt because the tests have other fixable diffs alongside this systematic difference.

## SWF5 Constructor Visibility: LocalConnection, NetConnection, Video

**Test:** `globals_swf5`

In Flash Player, `LocalConnection`, `NetConnection`, and `Video` are not accessible in SWF5 — `typeof(LocalConnection)` returns `"undefined"`. This is confirmed by Gnash test suite tests (`LocalConnection-v5`, `NetConnection-v5`, `Video-v5`) which specifically assert these are undefined in SWF5.

Ruffle's `globals_swf5` test expects all three to be visible as `[type Function]` in SWF5. Our implementation uses `flash_flags=0x0080` (hidden by SWF5 version mask `0x7480`) to match Flash's behavior.

```diff
- [type Function]    // LocalConnection (line 66)
- function
- object
+ undefined
+ undefined
+ undefined
```

Same pattern for NetConnection (lines 90-92) and Video (lines 146-148).

**Impact:** 9 diff lines (3 constructors × 3 lines each: value, typeof, own_props).

**Decision:** Keep Flash-correct behavior (hidden in SWF5). Gnash tests `LocalConnection-v5`, `NetConnection-v5`, `Video-v5` confirm this is correct. Accept `globals_swf5` at 295/304 as a Ruffle-vs-Flash difference.

## PlaceObject Before DefineSprite (Place-Before-Define)

**Tests:** `from_shumway/fuzz/*` (cluster of fuzz-generated SWFs)

A SWF tag stream may contain a `PlaceObject{,2,3}` that references a character ID whose `DefineSprite` only appears later in the tag stream. The three runtimes diverge on how to handle this:

- **Flash Player**: builds the character dictionary sequentially as tags are processed. A `PlaceObject` referencing a not-yet-defined character is a failed placement — nothing is added to the display list, no sprite frame scripts run.
- **Ruffle**: pre-scans the tag stream for `Define*` tags so the character dictionary is fully populated before timeline execution. The early `PlaceObject` succeeds and the sprite plays from frame 0.
- **Our previous behavior**: matched Ruffle (the recompiler emitted all `tagDefineSprite` calls in `tagInit`, which runs before any frame).

We now match Flash. The recompiler tracks the set of `Define*`-registered character IDs in tag-stream order during compile time. When emitting a *root-timeline* `tagPlaceObject{,2,3}` that references a `char_id` not yet in that set, the call's `char_id` is forced to 0, which the runtime treats as a "modify" — a benign no-op when the depth has no prior placement (the typical case for these fuzz SWFs).

The change is in `SWFRecomp/src/swf.cpp` (root `PLACE_OBJECT{,_2,_3}` cases only) and `SWFRecomp/include/swf.hpp` (the new `defined_chars` set member).

**Scope: root-timeline only.** The check is *not* applied to sprite-internal `PlaceObject` tags inside `DefineSprite`'s sub-tag handler. Those placements run at runtime when the sprite is instantiated, by which point the full root-level character dictionary has been built — so a sprite that internally places a sibling defined later in the root tag stream succeeds, matching Flash. Applying the check inline regressed AVM1 `placeobject_occupied_depth`, `textsnapshot_available_text` (both have `DefineSprite N` placing a sibling defined after `N` in the root stream), and the entire Gnash actionscript.all suite (Dejagnu's exported sprite places its child characters internally; the test SWFs import them via `ImportAssets` at root level, so `DefineSprite N` referencing imported chars `M`, `O` only works because the inner check is disabled).

**ImportAssets registers char_ids.** The `IMPORT_ASSETS` / `IMPORT_ASSETS_2` handler now inserts each imported `char_id` into `defined_chars`. A subsequent root `PlaceObject{,2,3}` referencing one of those ids isn't degraded.

**Tracked types.** `DefineSprite`, `DefineShape{,2,3,4}`, `DefineMorphShape{,2}`, `DefineFont{,2,3}`, `DefineButton{,2}`, `DefineText{,2}`, `DefineEditText`, `DefineBits` family, `DefineSound`, `DefineVideoStream`, plus `ImportAssets` imports.

**Tests affected:** Of the 20 originally failing `from_shumway/fuzz/*` tests, 4 now PASS, 2 promoted from `MISMATCH` to `RUFFLE_MATCHED` (`4949de46…`, `887c02ab…`), 2 previously `RUFFLE_MATCHED` upgraded to PASS (`1276557624…`, `a86fee6d…`). The remaining 16 still fail — most because of unrelated fuzzer-generated state divergences. Those are listed in `from_shumway/ignored_tests.txt` with this rationale.

**Decision:** Match Flash's sequential-dictionary semantics for root-timeline placement. Sprite-internal placement intentionally diverges from a literal "tag-stream-order dictionary" reading because Flash, Ruffle, and us all instantiate sprites at runtime — by which point the dictionary is complete.

## Drawing-API `getBounds` Stroke Expansion: Full Thickness vs Geometric Half

**Tests:** `from_gnash/misc-ming.all/DrawingApiTest`, `from_gnash/misc-ming.all/matrix_test`

For `mc.lineStyle(thickness, ...)` followed by `mc.lineTo(...)` / `mc.curveTo(...)`, Flash's `getBounds()` expands the rendered shape's bounding box by the **full** stroke `thickness` on each side, not the geometrically correct half-thickness. A line from `(100,100)` to `(200,200)` with `lineStyle(20)` reports bounds `(80,80) (220,220)` (±20 expansion), not `(90,90) (210,210)` (±10).

The DrawingApiTest source comment for line 89 — `check_equals(bnd, "80,80 220,220"); // line is 20 pixels thick..` — directly asserts this, treating the thickness as if it were the diameter rather than the geometric width.

**Ruffle uses geometric half-thickness.** `core/src/drawing.rs::stretch_bounds` computes `radius = stroke_width / 2` and encompasses `(point ± radius)`, which gives `(90,90) (210,210)` for the same input. Ruffle's `output.ruffle.txt` for DrawingApiTest line 89 shows `obtained: 90,90 210,210` — Ruffle is geometrically correct but doesn't match Flash's overestimate.

**Decision:** Match Flash. Our `actionCallFunction` (WITH-scope) and `actionCallMethod` (method-dispatch) `lineTo`/`curveTo` paths fold both endpoints with `h = ds->line_w` (full thickness) when `ds->has_line` is true. The same logic applies to every new segment — the start point is re-expanded with the *current* segment's thickness even when it was already in bounds from a prior segment with a different thickness, matching Flash's accumulating overestimate.

**Side-effect on `moveTo`:** Flash also doesn't fold the pen position into bounds when only `moveTo` has been called — `getBounds()` returns the empty-bounds sentinel `134217727/20 = 6710886.35` until a `lineTo`/`curveTo` actually draws something. Our impl previously folded `moveTo` into bounds (returning `(x,y,x,y)` for a single `moveTo`); now both endpoints fold-in moves to `lineTo`/`curveTo` instead.

**Impact:** DrawingApiTest goes from 66/93 → 80/93 line match (closes all bounds-related diffs). Test stays `output_mismatch` because the residual 13 diffs are all hitTest precision failures (zshape.hitTest undefined, inv4/inv8 boolean drift) which Ruffle gets right and we now don't — our diffs are entirely disjoint from Ruffle's diff set, so no `ruffle_matched` promotion. matrix_test (already `ruffle_matched 1081/1086`) is unaffected.

## Video Display Object Render Bounds: `netstream_play_flv_screen` Asset Stamp

**Test:** `netstream_play_flv_screen`

**Trace:** PASS (2/2). **Image:** FAIL — ~13.5k outliers, max diff 255.

The test SWF declares its embedded ScreenVideo at 160×120, plays back from a 128×128 ScreenVideo FLV onto a 128×128 stage with identity transform. Flash's documented Video render rule is to draw the decoded frame stretched to the SWF-declared bounds, then apply the placement matrix. So Flash renders to (0,0)–(160,120) on the 128×128 canvas — **overflowing the right and bottom edges**.

That's exactly what our renderer now does after the 2026-05-13 Phase 1 landing of `renderer_draw_bitmap_quad_scaled`. The `output.actual.png` shows the top-left ~128×120 region of the stretched logo, exactly the visible portion of the over-sized render. But the test's `output.expected.png` is the unscaled 128×128 source asset.

**Investigation chain (see `SWFRecompDocs/plans/video-display-flash-parity-plan.md` for full detail):**

1. `output.expected.png` is **byte-for-byte identical** to the same directory's `rufflelogo.png` source asset (16,384/16,384 pixels match) — it's a literal asset stamp, not a render of any SWF.
2. The test SWF's `setSize` body (`script_defs.c:961`) is `_global.isLivePreview`-gated — at runtime the live-preview branch is skipped via `goto label_373`. The runtime FLVPlayback **does not call any visible code path that resizes the inner Video display object** in this test.
3. Adobe's `mx/controls/videoClasses/VideoPlayer.as` shows `setSize` does `super.width = w; super.height = h;`, but `doAutoResize` only updates `internalVideoWidth`/`internalVideoHeight` (the metadata-reporting getters) — **it does NOT call setSize**. Auto-resize-from-metadata is opt-in via explicit user code, not automatic.
4. Therefore Flash's render in this test would draw the Video at the SWF-declared 160×120 bounds, overflowing the 128×128 canvas. The expected.png is **not consistent with Flash's actual rendering**. The most plausible explanation is that Ruffle's test-harness generation pre-empted the renderer and stamped the source asset.
5. Pre-Phase-1 our renderer happened to match the asset stamp by coincidence (128×128 source, identity transform, 128×128 stage), not by following the Flash spec.

**Decision:** Match Flash. The Phase 1 render-at-declared-bounds rule is correct; we accept the divergence from this Ruffle-specific test fixture. Test added to `ignored_tests.txt`.

## `gotoFrameFromInterval`: Ruffle's Expected Output Is an Unbounded Runaway

**Test:** `from_gnash/misc-swfc.all/gotoFrameFromInterval` (`known_failure = true`)

A `setInterval`/`onEnterFrame`-driven `gotoAndPlay` test. Flash Player
(`output.txt`) cleanly terminates: 3 tests run, `#passed: 3`, ending with a
single `frame7` trace and `__END_OF_TEST__`.

Ruffle's `output.ruffle.txt` does **not** match Flash — it is a runaway:
`_root.asOrder` grows without bound (`x0xx1xx2…x89…`, far past Flash's
`x0xx1x234`), it reports **10** tests instead of 3, and the trace output
continues *past* `__END_OF_TEST__` (the file's last line is another growing
`asOrder` FAILED at ~90 iterations). The test is marked `known_failure = true`
in its own `test.toml`, confirming Ruffle knows its expectation is wrong.

```diff
- frame7
- PASSED: _root.asOrder == x0xx1x234   (Flash: clean stop, 3 tests)
+ FAILED: _root.asOrder: ... obtained: "x0xx1xx2xx3...x89..."  (Ruffle: runaway, 10 tests, never cleanly ends)
```

**Caveat — this is not the usual "we match Flash" case.** Our runtime does **not**
match Flash here either: we currently **time out** (a distinct pre-existing
infinite-loop issue in the runaway path). So the entry is recorded as "Ruffle's
expectation is wrong" rather than "we're right and Ruffle's wrong."

**Decision:** Do not pursue `ruffle_matched` — matching Ruffle's buggy,
non-terminating output is not a worthwhile target (working rule: reach
`ruffle_matched` *unless Ruffle is doing something wrong*, and here it is). Leave
as `known_failure`. The runtime timeout (making us terminate the runaway like a
frame-capped player instead of hanging) is a separate, lower-priority follow-up
that would not change the pass rate (the test fails against Flash regardless).
See `_investigation/NEW_UPSTREAM_TESTS_TRIAGE.md` for the discovery context and
the sibling `gotoFrameFromInterval2` fix (timer-callback `gotoAndPlay` over-advance
→ `ruffle_matched`).
