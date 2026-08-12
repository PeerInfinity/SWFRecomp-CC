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

## ~~String Relational Comparison Uses UTF-8 Bytes vs UTF-16 Code Units~~ — RESOLVED 2026-08-01

**Test:** `string_relational_compare` — now **PASS (4/4)** in both `avm1` and `avm2`
(re-verified locally at `feb8882b0`). Removed from `ruffle-tests/ignored_tests.txt`
in the same change.

**This entry's premise was wrong.** It asserted that Flash Player compares strings
using UTF-16 code unit values (matching the ECMAScript spec), and defended our
code-unit comparison as the Flash-correct behaviour. In fact AVM1 stores strings as
UTF-8 and Flash's relational operators compare *those bytes*, which is **code-point**
order, not UTF-16 code-unit order — Ruffle does the same
(`core/src/avm1/value.rs:490`: `a.bytes().lt(b.bytes())`). Flash and Ruffle agree
here; our implementation was the odd one out, so this was never a Ruffle-vs-Flash
divergence. The runtime now compares by code point in `u16_cmp`
(`SWFModernRuntime/src/actionmodern/action.c:284-292`), whose comment records the
same reasoning. Equality callers are unaffected either way.

The original (incorrect) analysis is preserved below so the reversal is traceable.

This difference manifests when comparing BMP characters above U+D800 with supplementary characters encoded as surrogate pairs. For `"\uFF61" < "\uD800\uDC02"`:
- Flash (UTF-16 code units): first code units 0xFF61 vs 0xD800 → 0xFF61 > 0xD800 → `false`
- Ruffle (UTF-8 bytes / code points): U+FF61 (65377) vs U+10002 (65538) → `true`

```diff
     "\uFF61" < "\uD800\uDC02"
-    true
+    false
```

**Original decision (SUPERSEDED — see the RESOLVED note at the top of this section):**
Accept 1-line diff. Our UTF-16 code unit comparison matches Flash Player and ECMAScript spec. Add to ignored_tests.txt.

**Current decision:** compare by code point; the test passes; entry closed.

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

## Image tests: reference semantics, and the inverse case (we match Ruffle, not Flash)

This doc's usual pattern is "we match **Flash**, the test's expected (which reflects
**Ruffle**) differs." **Image** comparisons invert which file is which, so be
careful:

- **`output.expected.png` = the real Flash Player render** (the Flash oracle) — for
  image tests this IS the authoritative target, *not* a Ruffle artifact.
- **`output.ruffle.png` = Ruffle's *own* render**, present only for `known_failure`
  image tests, often at `quality="low"` (1× MSAA). Comparing our 4× render against a
  1× `ruffle.png` shows spurious 1px "row/column off-by-one" lines that are **pure
  sample-count mismatch, not real divergence** — always evaluate against
  `expected.png`, and render a fresh 4× Ruffle reference (via
  `ruffle-tests/triage_image_tests.py`) if you want an apples-to-apples Ruffle compare.

**The inverse-of-this-doc category exists for rendering:** a class of image tests
where **we match Ruffle's renderer but neither matches Flash's** — Flash's analytic
coverage rasterizer + thin-stroke pixel-hinting yields crisp edges/seams that any 4×
MSAA renderer (ours and Ruffle's) antialiases into a sub-pixel blend. Because we ==
Ruffle here, these are inherent, not Ruffle-design-choice diffs, so they live in
`ACCEPTED_DIFFS.md` (avm1 Category 11; `from_gnash` Category 5 —
`simple_loop_test`, `display_object_properties`), **not** here.

Conversely, when Ruffle ≈ Flash on an image test but **we** don't, that's a real
SWFRecomp rendering bug (not a Ruffle-vs-Flash spec difference): e.g.
`movieclip_setmask` (now fixed: drawing-API stroke closing + mask-fill-only + miter
joins → 0px, beating Ruffle), and the still-open **gradient color-ramp/banding** gap
on `movieclip_begin_gradient_fill` / `movieclip_line_gradient_style`.

## AVM2 dynamic-property enumeration order: `URLVariables.toString`

**Tests:** `avm2/loader_load` (126/128 — both remaining lines),
`avm2/bom` (3 of its 9 lines)

`URLVariables.toString` (Ruffle `globals/flash/net/URLVariables.as`) joins the
bag's properties with `&` **in `for (p in this)` order**. That order is not
specified anywhere; each player just exposes its own property store:

- **Ruffle** stores AVM2 dynamic properties in a `DynamicMap`, an FNV-hashed
  `hashbrown` table (`core/src/avm2/dynamic_map.rs`), and enumerates in *bucket*
  order. `loader_load` sets `vars.aaa` then `vars.cccc` and expects
  `cccc=true&aaa=bbb` — pure hash artifact.
- **We** enumerate in insertion order, so we emit
  `aaa=bbb&cccc=true`, on both the `trace(request.data)` line and the
  `Body:` line of the navigator log.

> **Reason corrected 2026-08-12 (session 14 wave-1 board audit §3.2).** This
> bullet used to read "**We** (and Flash) enumerate in insertion order". The
> parenthesis is factually wrong and has been struck: the Flash VM does **not**
> enumerate dynamic properties in insertion order. `from_avmplus` *is* Adobe
> Tamarin's own acceptance suite, so its checked-in `output.txt` files record
> real Flash-VM order — and `from_avmplus/ecma3/Statements/eforin_002`, whose
> object is built by the successive assignments
> `value, valueOf, toString, toNumber, toBoolean`, expects
> `toString, value, toNumber, toBoolean, valueOf`. That is Tamarin's
> `InlineHashtable` slot/bucket layout, not insertion order. Three engines,
> three orders — see `ACCEPTED_DIFFS.md` Category 12 for the full table.
>
> **The decisions in this section are unchanged**: Ruffle's expectations for
> `loader_load` and `bom` are still its own `hashbrown` bucket order and still
> unreproducible, and we still keep insertion order. What changes is the
> *reason* — insertion order is defensible because it is the ES2015+ rule for
> string keys and because no player's hash layout is reproducible, **not**
> because it is what Flash does. Do not defend it as "Flash-matching" again.

Ruffle's own `avm2/url_vars` test documents the problem in a source comment —
*"Ruffle's property iteration order is not consistent with Flash's (yet)"* — and
works around it by calling `.toString().split("&").sort()` before tracing.
`loader_load` does not, so its expectation is unreproducible without emulating
FNV-1a plus hashbrown's SIMD bucket layout, which would break the moment either
crate changes.

**Decision:** keep insertion order. `loader_load` cannot pass on any amount of
Loader work. Added to `ruffle-tests/tests/swfs/avm2/ignored_tests.txt`
(suite-local) 2026-08-06 — see "Ignore-list scope" below.

### Same mechanism, second test: `avm2/bom`

`avm2/bom` loads one `lastName=Jones&firstName=Tom` fixture three times (UTF-8,
UTF-16LE, UTF-16BE) through `URLLoader` in each of the three `dataFormat`
modes. Its three `dataFormat=variables` lines trace a `URLVariables` built from
that body, so they are the same `for (p in this)` join as above. The fixture's
on-disk order is `lastName` then `firstName` — verified with `xxd`, and
independently by the test's own `dataFormat=text` line, which round-trips the
body verbatim and matches — yet the expected output is `firstName` first:

```
-  URLLoader dataFormat=variables utf8: firstName=Tom&lastName=Jones
+  URLLoader dataFormat=variables utf8: lastName=Jones&firstName=Tom
```

Nothing in the test re-orders the pairs, so the expectation is purely Ruffle's
`hashbrown` bucket order. Unlike `loader_load`, which merely happens to be
unreproducible, `bom` has no route to `ruffle_matched` either: that status needs
both `known_failure = true` in `test.toml` and a sibling `output.ruffle.txt`
(`verify_output.py`), and `bom` has neither — Ruffle *passes* it, so `output.txt`
**is** Ruffle's own output.

**Decision:** `avm2/bom` stays `output_mismatch` permanently, ceiling 6/9. Its
other two failing lines *were* real bugs on our side (UTF-16LE/BE bodies were
handed to the string constructor as raw bytes instead of being BOM-decoded) and
are fixed — `ul_set_data` now shares `avm2_strip_bom` with `ByteArray.toString`.

### Ignore-list scope for `loader_load` / `bom` (corrected 2026-08-06, session 13)

<!-- image-axis: none -->

This section previously ended "it is **not** added to `ignored_tests.txt`",
reasoning that a `RUFFLE_VS_FLASH_DIFFERENCES.md` entry does not carry
CLAUDE.md's ACCEPTED_DIFFS → ignore-list obligation. That is right about the
**global** list and wrong about the suite-local one, and the cost was measurable:
with both tests unlisted, `loader_load` (gap 2) and `bom` (gap 3) were the two
cheapest-looking rows in the entire 4400-test corpus and headed *every* near-pass
regeneration. The session-13 board audit re-costed them from scratch before
noticing they were already ruled unwinnable here
(`SWFRecompDocs/plans/session13-fanout-reports/wave1-board-audit.md` §4.3(c)).

- **Suite-local** (`ruffle-tests/tests/swfs/avm2/ignored_tests.txt`): **added**
  2026-08-06, following the s11 precedent for `loader_applicationDomain` / `swz`
  at that file's tail. A suite-local entry is TRACE-axis triage only.
- **Global** (`ruffle-tests/ignored_tests.txt`): **deliberately not added.** Per
  that file's header (traps 1–2), a global entry is *also* an image-axis
  disposition — `scripts/image_triage.py` returns `image_axis=True` for it. Both
  `test.toml`s were checked: neither test has an `[[image_comparisons]]` block,
  so a global entry would buy nothing and mislabel the pixel board.

The same split applies to `url_vars`, which passes and needs no entry at all.

## Ruffle-internal rope-string introspection: `ruffle::isDependent()`

**Test:** `avm2/dependent_strings` (84 expected / 83 actual / 46 matching —
38 differing lines)

<!-- image-axis: none -->

The test's own `test.toml` says it outright: `# NOTE: this is a Ruffle-only
test.` `Test.as` opens with

```actionscript
namespace ruffle = "__ruffle__";

function print(text) {
    trace(text);
    try {
        trace(text.ruffle::isDependent());
    } catch(e) {
        trace();
    }
}
```

and then prints ~40 strings built by `substr`, `+=` concatenation (narrow and
wide/UTF-16), and substring-of-concat, asking each one whether it is
"dependent". `isDependent()` is **not a Flash API**. It is a debug hook Ruffle
exposes in a private `__ruffle__` namespace onto its own *rope string*
representation (`core/src/string`): a Ruffle `AvmString` may be either an owned
buffer or a dependent slice/rope that borrows another string's storage, and this
method reports which. The expected `true`/`false` sequence is therefore a
transcript of Ruffle's internal allocation heuristics — when its concatenation
path decides to build a rope versus copy, and at which lengths and widths.

Our strings are ordinary owned UTF-8/UTF-16 buffers, so the method does not
exist, the call throws, the test's own `catch` runs, and `trace()` with no
argument prints a blank line. Every string line matches; every boolean line is
blank on our side:

```diff
  abcd
- true
+
  bcd
- true
+
```

**Flash Player would produce exactly what we produce** — an undefined method in
an unknown namespace throws there too, and the test would print the same blank
lines. So the graded `output.txt` is not a Flash oracle at all; it is Ruffle
describing its own string internals.

**Decision:** never fix. Matching would mean re-implementing Ruffle's rope-string
model *and* its allocation thresholds, purely to report them back. Added to
`ruffle-tests/tests/swfs/avm2/ignored_tests.txt` (suite-local) 2026-08-06;
**not** added to the global `ruffle-tests/ignored_tests.txt` — the test has no
`[[image_comparisons]]` block, so a global entry would wrongly disposition a
pixel-axis row (same reasoning as `loader_load` / `bom` above).
