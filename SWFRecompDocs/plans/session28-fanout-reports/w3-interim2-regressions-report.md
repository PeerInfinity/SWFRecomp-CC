# s28 w3-interim2-regressions — report (wave 2, implementation)

**New files:** `SWFRecompDocs/plans/session28-fanout-reports/w3-interim2-regressions-report.md` (this file) and
`SWFRecompDocs/plans/session28-fanout-reports/w3-interim2-regressions.patch`. No new fixture dirs and no new source
files. The headline rows already have Flash goldens.

**Patch scope:** `SWFModernRuntime/src/actionmodern/action.c` only (+61/−1). Functions touched:
`builtin_string_proto_valueOf` (plus a new file-static `g_call_this_fn_bag` next to it), the Function-receiver
own-method arm of `actionCallMethod` (the `g_call_this_type = ACTION_STACK_VALUE_FUNCTION` block), `asnativeUnknownMinor`,
a new `static int mcArmVersionHidden()` next to `mcArmCaseMiss()`, and one call to it in `actionCallMethod`'s MOVIECLIP
arm, right after the `mcArmCaseMiss` line. No `NO_GRAPHICS` arms are touched, and `swf_core.c` / `tag_stubs.c` are untouched.

Box: cloud, graphics = Dawn on lavapipe. Upstream corpus is Ruffle master `8345a3e39`. Since `c2f7d24b7` that adds 7
commits, which are num_ticks migrations and avm2 changes. None touches a row here.

## Verdicts (lead)

| # | interim #2 regression | verdict | after patch (graphics = NG) |
|---|---|---|---|
| 1 | `avm1/boxed_primitives` pass → output_mismatch | **GO, fixed** | **pass** (diff 1 → 0) |
| 2 | gnash `toString_valueOf-v5` ruffle_matched → output_mismatch | **REFUTED as a B4 regression. It moved toward Flash. HOLD on B6 (sibling w2b-gnash-holds)** | output_mismatch (unchanged; 32 diff lines vs Flash, Ruffle has 34) |
| 3 | gnash `ASnative-v5..v8` ruffle_matched → output_mismatch | **GO, fixed** (row back to ruffle_matched, and one Flash line better than before B7) | **ruffle_matched** ×4 (35→34, 40→39 ×3) |
| 4 | `regression/avm1_place_occupied_depth_swf5` 1-line gap | **GO, fixed** (SWF5/6 version gate for the VERSION_6/7 MovieClip methods) | **pass** (diff 1 → 0, image still 0 outliers) |

Priced trace flips: **6** (`avm1/boxed_primitives` → pass, `ASnative-v5..v8` → ruffle_matched,
`regression/avm1_place_occupied_depth_swf5` → pass). Not one gate row moved the wrong way, and no other row's output
changed by a single byte.

## Mechanisms

### 1. `boxed_primitives`: stale `g_call_this_type` in the B4 native (`ace9d2f88`)
`builtin_string_proto_valueOf` returned `"[type Function]"` whenever `this_obj != NULL && g_call_this_type == FUNCTION`.
That global is set by `actionCallMethod`'s Function-receiver own-method arm, and it stays set for the **whole body** of
a script method called on a Function. The test is MTASC: `Test.show(new String('blah'))` is a static method, so its
receiver is the class function `Test`. Inside `show`, `"value = " + val` runs ToPrimitive → `valueOf` on the String
wrapper, which saw the stale FUNCTION tag. The w1b report had already flagged this ("should be replaced by an explicit
receiver-type check").

**Rule:** the receiver is a Function only when `this_obj` is the exact `own_props` bag that the Function arm passed. The
arm now records it in `g_call_this_fn_bag` (saved and restored with `g_call_this_type`), and the native tests pointer
identity. This keeps every case B4 got right: `f.vo()` → `"[type Function]"` still passes in toString_valueOf-v6..v8 and
the -v5 line 192.

### 2. `toString_valueOf-v5`: not a B4 regression (refutation)
I bisected by line. Ours vs Ruffle's `output.ruffle.txt` on master differs in 3 places:
- **46-48** (`svo()`, `f.vo()`, `d.vo()`). Owned by **B4** and flipped FAILED→PASSED, **matching FP32**. Confirmed with
  an env-switched experiment: the old `builtin_wrapper_valueOf` body restores Ruffle's 3 FAILED lines and changes nothing else.
- **71-73** (`toString_valueOf.as:293/297/298`). Owned by **bc3e02caf B2** (SWF5 hides TextField.prototype, Flash-correct).
  Line 293 now PASSES like Flash. 297/298 (`TextField.prototype.toString == Object.prototype.toString`) now FAIL: in
  Flash SWF5 both sides compare as `undefined` because **a function converts to primitive `undefined` in SWF5**. That
  is w1b-rm-gnash **B6**, which is not implemented. Before B2 these lines "passed" only because TextField.prototype was
  wrongly visible.
- **82-83** (`:324/325`). Failing in all three of Ruffle, before, and after; only the `obtained:` text changed
  (`[object Object]` → `[type Object]`). Not B4 (identical with the old valueOf body).

Net against the FP32 golden: Ruffle 34 diff lines, ours 32. The row fell out of `ruffle_matched` because 297/298 are
not in Ruffle's failing set, not because anything moved away from Flash. **HOLD.** Completion mechanism: B6 (SWF5
function → primitive `undefined` in `==`, and Function.prototype invisible), which is in the **w2b-gnash-holds** brief
(task 2). Once B6 lands, 297/298 pass (they need only `undefined == fn` → true at SWF5), and with them lines
9-10, 15-19, 25-26, 36-37, 92-93, 102-103, 111-112 and 120 of this row. I did not implement B6 here because it is a
sibling's M-sized family, and its risk surface (every SWF5 `==` involving a function) belongs to its own gate.

### 3. `ASnative-v5..v8`: the B7 dead native grew a lazy `prototype` (`bc3e02caf`)
`ruffle_matched` = our failing lines ⊆ Ruffle's. B7's shared no-op native for unimplemented minors was an ordinary
`ASFunction` without `no_lazy_prototype`, so `ASnative.as:323` `typeof(g.prototype) == "undefined"` flipped
PASSED→FAILED. FP32 (Windows golden **and** the Linux capture
`trace-provenance/from_gnash__actionscript.all__ASnative-v5.r1.txt`) PASSES it: Flash natives have no `prototype`.
**Rule:** `g_asnative_dead.no_lazy_prototype = 1`, the same flag the class-1 `ASnative(1,0)` path already sets.
`:322` (`typeof(g) == "function"`) stays PASSED, which is B7's Flash-ward gain, so each row now has **one fewer** diff
line than before B7 (35→34, 40→39). `avm1/asnative_sweep` still passes.

Pre-change diff comparison (brief item 3): the ~5-line Windows/Linux FP32 split (`:179`, `:189`, `:263`, `#passed`/`#failed`) is
byte-identical before and after. The other remaining diffs (`:57-61` Date-as-function `ASnative(103,256)()`, `:185-187`,
`:195-197`, `:217-226` String natives 251, `:233-251` Stage 666, `:269-344` 2106/102/106) are pre-existing gaps that
Ruffle shares. The `:57/:61` `obtained:` text already differed from Ruffle before B7 (worktree bisect: `bc3e02caf^`
prints the same `obtained: ` as master), so it is not a B7 effect and is still inside Ruffle's failing set.

### 4. SWF5 `getDepth` (and the other version-tagged MovieClip methods)
`initMovieClipPrototype` already tags `createEmptyMovieClip`/`getDepth`/`setMask` with `flash_flags 0x0080` (VERSION_6)
and `getNextHighestDepth`/`getInstanceAtDepth` with `0x0400` (VERSION_7), after Ruffle `movie_clip.rs`. Property reads
honour those tags, but `actionCallMethod`'s MOVIECLIP arm dispatches the builtins **by name** and never checked them, so
SWF5 `ma.getDepth()` returned `-16377` where FP32 prints an empty value.

**Rule (`mcArmVersionHidden`):** at SWF ≤ 6, a call to one of those 5 names resolves to `undefined` when all four of these hold:
MovieClip.prototype (`getMovieClipPrototype(g_swf_version)`) still holds our stub for that name, i.e. no script
override; `isPropertyHiddenAtVersion(flash_flags)` is true, so an `ASSetPropFlags` unhide re-exposes it; the clip has no
own property of that name; and the receiver is not a TextField or Button (those share the arm but not
MovieClip.prototype).

Flash evidence: the fixture's FP32 golden (`ma.getDepth()= mb.getDepth()=`), and gnash `MovieClip-v5` `MovieClip.as:285`
`mc.getNextHighestDepth() == undefined` PASSED in the FP32 golden.

Not gated (deliberately): the drawing API (`beginFill`… `clear`), `attachAudio`, and the VERSION_8 methods. Ruffle tags
them VERSION_6/8, but our MovieClip.prototype has no stubs for them (the arm's name chain serves them directly), and the
corpus has no Flash line that pins their SWF5 call result. The corpus scan found exactly one SWF5 movie calling any of them
(gnash MovieClip-v5, whose only call-result line for these is `hasOwnProperty`, already PASSED). Lead below.

## Per-test before/after (same box, graphics; before = clean origin/master `346daa8f`)

`d` = `<` lines of `diff output.txt actual`. Every row not listed as moved has a **byte-identical** actual output
before and after (cmp over all 68 rows).

| row | before | after |
|---|---|---|
| avm1/boxed_primitives | output_mismatch d1 | **pass d0** |
| from_gnash/actionscript.all/ASnative-v5 | output_mismatch d35 | **ruffle_matched d34** |
| from_gnash/actionscript.all/ASnative-v6 | output_mismatch d40 | **ruffle_matched d39** |
| from_gnash/actionscript.all/ASnative-v7 | output_mismatch d40 | **ruffle_matched d39** |
| from_gnash/actionscript.all/ASnative-v8 | output_mismatch d40 | **ruffle_matched d39** |
| regression/avm1_place_occupied_depth_swf5 | output_mismatch d1 (image pass 0 outl.) | **pass d0** (image pass 0 outl.) |
| from_gnash/actionscript.all/toString_valueOf-v5 | output_mismatch d32 | output_mismatch d32 (identical bytes; HOLD on B6) |
| from_gnash/actionscript.all/toString_valueOf-v6/-v7/-v8 | pass | pass |
| avm1/asnative_sweep | pass | pass |
| avm1/asnative, avm1/asnative_instrument | pass / ruffle_matched | same |

### Gate set (68 rows, graphics, both legs). Every row not in the table above is unchanged (status and bytes)
- **avm1 (25):** boxed_primitives, asnative, asnative_instrument, asnative_sweep, coerce_to_object_monkeypatch,
  coerce_to_primitive_resolve, movieclip_depth_methods, movieclip_get_instance_at_depth, object_string_coerce_swf5/6,
  placeobject_occupied_depth, primitive_instanceof, primitive_type_globals, string_coercion, string_methods,
  string_methods_negative_args, string_methods_swfv5, string_ops_swf6, undefined_to_string_swf6,
  shared_object_members_swf5, swf6_to_5_cross_call, textfield_props_swf5, register_class, register_class_swf6,
  loadvars_tostring.
- **regression (11):** avm1_bare_depth_methods_v7_gate, avm1_bare_depth_methods_v7_gate_swf7,
  avm1_place_occupied_depth_swf5, avm1_create_text_field_depth, avm1_empty_clip_drawing_depth_order,
  **mc_method_v5_caller_gate**, coerce_cross_swf_version, coerce_recursion_guard, coerce_type1_args,
  string_prim_method_type1_args, avm1_textfield_attached_depth_order.
- **gnash (32):** toString_valueOf-v5..v8, ASnative-v5..v8, String-v5..v8, MovieClip-v5..v8, with-v5..v8, Function-v5,
  Object-v5, Object-v6, Sound-v5, getvariable-v5, TextField-v5, TextField-v6, Selection-v6, Number-v5, Boolean-v5,
  misc-ming place_object_test, shape_test.
- How the set was chosen: every row the owning commits flipped that runs through a touched function (B4:
  toString_valueOf-v6..v8; B5/B2/B3: String-v6..v8, with-v5..v8; bc3e02caf B7/B2: asnative_sweep,
  textfield_props_swf5, TextField-v5), every avm1/gnash/regression row whose name touches String/valueOf/coerce/ASnative/depth,
  and **every SWF5 or SWF6 movie in avm1/from_gnash/from_shumway/regression that names one of the gated MovieClip methods**
  (raw-SWF constant scan: 13 SWF5 movies + 8 SWF6 movies naming the SWF7 pair). I left out the owning commits' bitmap,
  XMLNode, swf_length and form_loader rows: no touched function is on their paths.
- Image axis inside the set: unchanged (place_object_test 5685 / shape_test 10417 outliers both legs; the 3 depth-order
  regression rows plus place_occupied_depth_swf5 pass at 0 both legs).

### No-graphics (after, 14 rows)
boxed_primitives, asnative_sweep, asnative, swf6_to_5_cross_call, textfield_props_swf5, regression
avm1_place_occupied_depth_swf5, mc_method_v5_caller_gate, avm1_bare_depth_methods_v7_gate, gnash ASnative-v5/-v8,
toString_valueOf-v5/-v6, MovieClip-v5, misc-ming place_object_test: **actual output byte-identical to graphics** and the
same statuses (pass / ruffle_matched as above; toString_valueOf-v5 output_mismatch d32).

### Render canary
`render_canary.py capture/compare` over every AVM1-capable member of `render_canary_tests.txt`: the avm1/, from_gnash/,
from_shumway/ and non-`avm2_` regression/ lines (88 lines, 3 of them duplicates, so 85 tests). Result: **127 / 127 PNGs
IDENTICAL (md5), 0 DIFFERS, 0 trace-status changes, 0 image-status changes.** I did not run the avm2/visual/text/fonts
members: all three touched sites are AVM1-only natives and AVM1 dispatch arms, and no AVM2 path reaches them. The
standing set needs no new member, because the change is trace-semantic and the movers carry their own trace rows.

## EXPECTED-FLIP LEDGER (for the coordinator's CI grade, both modes)

**Trace axis:**
| row | from (interim #2 / master) | to |
|---|---|---|
| avm1/boxed_primitives | output_mismatch | **pass** |
| from_gnash/actionscript.all/ASnative-v5 | output_mismatch | **ruffle_matched** |
| from_gnash/actionscript.all/ASnative-v6 | output_mismatch | **ruffle_matched** |
| from_gnash/actionscript.all/ASnative-v7 | output_mismatch | **ruffle_matched** |
| from_gnash/actionscript.all/ASnative-v8 | output_mismatch | **ruffle_matched** |
| regression/avm1_place_occupied_depth_swf5 | output_mismatch | **pass** |

Anything else that moves on the trace axis is unexpected. `toString_valueOf-v5` is expected to **stay** output_mismatch
(HOLD on B6).

**Pixel axis:** no expected movers. `avm1_place_occupied_depth_swf5`'s image comparison passes at 0 outliers before and after.

## HOLD / not finished
- `toString_valueOf-v5` → back to `ruffle_matched`, or better. Completion mechanism: **B6 in w2b-gnash-holds**. If that
  slot drops B6, the minimal sub-rule that clears this row's non-subset lines is "SWF ≤ 5: Equals2 of `undefined` with a
  FUNCTION is true" (297/298). The coordinator should re-check this row when B6 lands.

## Refutations
- Brief item 2 ("same B4 owner, SWF 5 arm"): **refuted.** B4's only effect on -v5 is +3 lines toward Flash. The status
  drop comes from bc3e02caf B2 (Flash-correct), which exposed the unimplemented B6 on `:297/298`.
- Brief item 3 ("owner B7"): confirmed, but the fault is not B7's major-table rule. It is the missing `no_lazy_prototype`
  on the shared dead native (`:323`). The `:57/:61` text drift is older than B7 (worktree bisect).

## New unclaimed leads
- **SWF5 drawing API / attachAudio version gate.** Ruffle tags `beginFill`, `beginGradientFill`, `moveTo`, `lineTo`,
  `curveTo`, `lineStyle`, `endFill`, `clear` and `attachAudio` VERSION_6, and `attachBitmap`, `getRect`, `lineGradientStyle` and
  `beginBitmapFill` VERSION_8. Our arm serves them at any version. Needs a Flash trace (a SWF5 probe calling each and
  tracing `typeof mc.X` plus the call result) before gating; no corpus row pins it today.
- **`ASnative(103,256)()` called as a function** (ASnative-v5..v8 `:57`, `:59`, `:61`, 3 lines ×4 rows). FP32 returns the Date
  string (as `Date()` does). Our handle shares the constructor body, which needs a `this` object. Fix: have the handle
  detect a non-`new` call and return `actionDateToString(actionDateConstruct(...))`. That gives 3 Flash lines per row
  (it stays in Ruffle's failing set, so it is not a status flip until the other ~30 lines land).
- `toString_valueOf-v5 :324/325`: `obtained:` text is `[type Object]` vs Ruffle's `[object Object]`. Both fail, so this is
  cosmetic until B6.

## LOCAL ORACLE REQUESTS
none (all four rules are pinned by existing FP32 goldens: avm1/boxed_primitives `output.txt`, the gnash
ASnative-v5 Windows golden plus the Linux capture `trace-provenance/from_gnash__actionscript.all__ASnative-v5.r1.txt`,
the regression fixture's coordinator FP32 golden, and gnash MovieClip-v5 `:285`).
