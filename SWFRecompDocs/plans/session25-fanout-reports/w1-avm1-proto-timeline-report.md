# s25 wave 1 — `w1-avm1-proto-timeline` report

**New files (this branch):**
- `session25-fanout-reports/w1-avm1-proto-timeline-report.md` (this file)
- `session25-fanout-reports/w1-avm1-proto-timeline-prototype.patch`: `git diff --binary origin/master` of
  `SWFModernRuntime/` plus **three new regression fixture dirs** (`regression/avm1_attached_clip_tagorder_ratio`,
  `regression/avm1_attached_clip_tagorder_po3`, `regression/avm1_array_generic_receivers`). `git apply --check` is clean
  on `ca14fe02`. Source is reverted on the branch.

Box: SETUP_STATUS all OK (apt, Pillow, Dawn). Categories downloaded: `avm1 from_gnash`, upstream Ruffle master at session
time (my blobless clone taken in the same half-hour is at **`3ac8dcb07`**). All grading below is `--mode=graphics`
against the s25 trace baseline (`results_graphics.json` on master), plus a no-graphics leg on the headline rows.

## Verdicts and priced flips

| item | verdict | flips (measured) | price |
|---|---|---|---|
| **L4** Ratio child double-runs frame 1 on an attached clip's wrap | **GO, fixed in the patch** (1 gate in `tagPlaceObject2Ratio`) | new fixture `regression/avm1_attached_clip_tagorder_ratio` 0 → 34/34; the PO3 fixture lands too (34/34). 0 corpus moves over all 44 Ratio-placement SWFs | S |
| **L5** Array generics on Function / MovieClip / `.call(undefined)` receivers | **GO, fixed in the patch** | new fixture `regression/avm1_array_generic_receivers` 12/16 → 16/16; 0 moves over 28 array/call rows | S |
| L5 "String object" row | **REFUTED (probe artifact)**: the row has no String object, see §3.2 | n/a | n/a |
| **item 2** `avm1/text_format_prototype_lazy` | **GO (flip), in the patch**: the read half of the accessor model, plus define-on-`transform` | **output_mismatch 32/35 → pass 35/35** (graphics and no-graphics); 0 moves over 41 TextFormat rows | S–M (the s24 "L" price is refuted, §2) |
| **item 1** `avm1/video_prototype_lazy_swf6_child` | **NO-GO at M**: refuted as a routing bug. Routing the goto is cheap; the child's placement then **collides with the parent's depth** in the shared global display list | 0 (prototype measured, then removed) | **L**: route 1 of `child-timeline-advance.md` §2.2 (per-movie display-list ownership) |
| **L2** `getBounds` folds only a dynamic child's own drawing | **NO-GO (no row)**: the sweep finds no failing AVM1 trace row whose diff is a bounds line | 0 | park |

**Net, if wave 2 lands the patch:** +1 corpus flip (`avm1/text_format_prototype_lazy`) and +3 regression fixtures. No
corpus row moved in any sweep (123 distinct rows run in total, graphics, all identical to the baseline status and line counts
except the flip).

Functions touched (none are button or mouse dispatch, so they don't overlap `n-play-game`):
- `tag.c`: `tagPlaceObject2Ratio`, the backward-catch-up/survives_rewind block only.
- `action.c`:
  - new `static tfLazyFieldHidden`
  - `createBlankTextFormat`
  - `actionGetMemberImpl` (OBJECT arm, one early branch)
  - `builtin_array_method`
  - `actionCallMethod`: the Function `own_props` native arm (~72216) and the MovieClip `_mc_user_dispatch` invoke
    (~77786).

---

## 1. L4: attached-clip wrap with a Ratio child (FIXED)

**Mechanism.** `ng_advance_sprite_playhead`'s loop wrap (`tag.c` ~1640, in `advance_sprite_frames`) raises
`g_loopback_replay` around the frame-0 replay. `tagPlaceObject2`'s survives_rewind block honours it:
`(catch_up_backward || g_loopback_replay)` at `tag.c` ~10793. **`tagPlaceObject2Ratio`'s copy of that block only
tested `catch_up_backward`** (`tag.c` ~11611 on master). So on every wrap of `multi`, its frame-0
`tagPlaceObject2Ratio(1, kid3, ratio 0)` fell through every modify path to a full fresh placement. That re-instantiated
`kid3`, whose frame 1 ran again alongside the surviving playhead: `kid3 anim f1` printed twice.

**Fix (patch):** `if ((catch_up_backward || g_loopback_replay) && ...)` in `tagPlaceObject2Ratio`. Survivors
(same ratio; MC, or same char) become a modify. A non-survivor during a loopback replay hits the Ratio arm's existing
`else return;` (the same outcome `tagPlaceObject2` gives when `g_natural_wrap_cleanup_pending` is unset).

**Before/after (graphics):**

| row | before | after |
|---|---|---|
| `regression/avm1_attached_clip_tagorder_ratio` (new) | MISMATCH, diverges from line 28 (an extra `kid3 anim f1` per wrap) | PASS 34/34 (also no-graphics) |
| `regression/avm1_attached_clip_tagorder_po3` (new) | PASS (already) | PASS 34/34 (also no-graphics) |

**Blast radius, measured.** I tag-scanned every `avm1`, `from_gnash`, `regression` and `timeline` SWF for a PlaceObject2
or PlaceObject3 with HasCharacter+HasRatio, at root or inside a sprite. That gives **44 rows** (the root case matters
too, because the root natural wrap also sets `g_loopback_replay`). All 44 match the baseline status and line counts,
including the 4 non-pass rows:
- `movieclip_hittest_shapeflag` 332/338
- `action_execution_order_extend_test` 7/32
- `loop_test10` (ruffle_matched 5/28)
- `place_object_test2` (ruffle_matched 0/19)

The two image fails in that set, `netstream_play_flv_screen` (44751/235) and `morph_test1` frame1 (217/255), have
`max_diff` and outliers identical to the pixel baseline. The 5 rows of the `goto_rewind*`/`loop_test*` family are
unchanged.

**Fixtures.** `mk_ratio.py` and `mk_po3.py` become the fixtures' `create_test_swf.py`, with a docstring added. The SWF
bytes regenerate identically. `output.txt` is the coordinator's Ruffle oracle (`0ddd12b6a`), which is byte-identical to
`avm1_attached_clip_tagorder/output.txt`. `test.toml` is `num_frames = 8`.

## 2. Item 2: `text_format_prototype_lazy` (FLIP, priced S–M, not L)

**Premise attacked.** The s24 report priced the flip at L, on the claim that "every TextFormat read, write, for-in and
getTextFormat path" must become accessors. On current master the row is at **32/35**. Only lines 4, 6 and 7 differ, all
of the same shape: `c.font=undefined` after `delete TextFormat.prototype.font` (ours `Arial`). The s24 wave 2 already
landed (2) `super()` fidelity and (3) the Array prototype. What is left is **only the read half** of the accessor model.

**Mechanism (patch).** A new `tfLazyFieldHidden(obj, name)` is consulted at the top of `actionGetMemberImpl`'s OBJECT
arm for `native_type == NATIVE_TEXTFORMAT`. When `name` is one of the 17 lazy field names, `obj` holds it as an own
slot, and **no object on its `__proto__` chain** (OBJECT, or an ARRAY's `props` bag) carries that name any more, the
read is `undefined`. That is Flash's model: the field is native data read through the prototype accessor the instance
got at construction. Exception: an object that is itself in the lazy-proto set (a TextFormat used as a prototype,
line 17 `tf.font=Foo`) holds the accessor on itself, so its own slot stands for it.

**The sweep's catch (fixed in the patch).** The first cut regressed `avm1/stylesheet_transform` (750 → 378). Our
`createBlankTextFormat` (StyleSheet `transform`) never ran `textFormatDefineLazyProps`, and the s24 report recorded
that as "matches Ruffle". **That is wrong on current Ruffle.** `style_sheet.rs` `transform` builds the object via
`activation.instantiate_class_as_script(["TextFormat"], &[])`, i.e. the real constructor, which calls
`define_lazy_proto_properties` (`text_format.rs:656`). The patch adds the define to `createBlankTextFormat`, and
`stylesheet_transform` is back to 750/750.

**Before/after:** `avm1/text_format_prototype_lazy` output_mismatch 32/35 → **pass 35/35** (graphics), and pass in
no-graphics.

**Sweep (41 rows, scoped by argument).** The gate can fire only when a field name is absent from the whole chain: a
never-defined prototype, a deleted field, or a swapped prototype. So I ran every row whose SWF references TextFormat
and that builds through those paths or swaps or deletes prototypes:
- `stylesheet*`, `text_format*`, `textfield_{get,set}_text_format*`, `globals_swf5..8`, `globals_monkeypatch`,
  `native_objects_swf6..8`, `native_subclasses`, `lazy_prototype_shared`, `video_prototype_lazy`,
  `edittext_default_format*`, `edittext_stylesheet`, `gettextextent`, `edittext_html_roundtrip`,
  `global_instance_decls`, `textfield_props_swf8`
- gnash `TextFormat-v5..8`, `TextField-v6`, `TextField-v8`

All are identical to the baseline except the flip. That includes the 4 non-pass rows: `global_instance_decls` 20/758,
`globals_swf5` 294/304, `globals_monkeypatch` 44/306, `native_objects_swf6` 114/115.

**Known limits of the read half (wave 2 should keep or close them):**
- *Writes after the accessor is gone.* In Flash, `tf.font = "X"` with no accessor on the chain creates a plain own
  property that reads back `"X"`. Ours writes the native slot and the gate still hides it. No corpus row exercises it.
  Completion: a per-slot "plain" flag set by a write while hidden. S.
- `hasOwnProperty("font")` on an instance is still `true` (Flash: `false`, no own fields). No corpus row.
- Ruffle's `LAZY_PROTO_DECLS` has **19** names (`kerning`, `letterSpacing` too); `g_tf_lazy_names` has 17. Unmeasured
  divergence, logged as a lead.

## 3. L5: Array generics on non-Array receivers (FIXED)

### 3.1 Mechanism

Instrumented `builtin_array_method` (receiver tag `g_call_this_type`, `this_obj`):

| path | tag | `this_obj` |
|---|---|---|
| Object own / `.call` | OBJECT | the object (worked) |
| Function `.call` | FUNCTION | `own_props` |
| Function own method (`actionCallMethod` own_props native arm) | **stale 0** | `own_props` |
| MovieClip `.call` | MOVIECLIP | `dynamic_props` |
| MovieClip own method (`_mc_user_dispatch` → `invokeFunctionValue` with `INV_MC_THIS_NULL_PTR`) | stale 0 | **NULL** |
| `.call(undefined)` | UNDEFINED | `global_object` |

The `.call` arms already pass an `ASObject*` bag. Only the generic arm's `== OBJECT` test refused them.

**Patch:**
- `builtin_array_method`'s generic arm accepts OBJECT, FUNCTION, MOVIECLIP, UNDEFINED and NULL (every one arrives as
  an `ASObject*` bag; NULL `this_obj` still returns undefined).
- The Function own_props native arm sets `g_call_this_type = FUNCTION` around the call (save/restore).
- The MC user-method arm passes `has_this_ptr = dynamic_props` and the MOVIECLIP tag **only when the callee is
  `builtin_array_method`**; every other native keeps the NULL receiver.

**Before/after:** fixture 12/16 → **16/16**, graphics and no-graphics.

**Sweep (28 rows, 0 moves):**
- avm1: `array_{call_method,concat,prototyping,reverse,shift,slice,sort,splice,unshift,properties}`, `call`,
  `call_method_empty_name`, `funky_function_calls`, `global_array`
- gnash: `Function-v6..8`, `MovieClip-v6..8`, `Object-v6/v8`, `array-v6..8`
- regression: `avm1_array_native_own_method`, `array_method_type1_args`, `array_element_type1_args`

### 3.2 The "String object" row is a probe artifact (refutation)

`make_l1.py` builds the `str` receiver as `push('xy',1,'String') + NM` with `NM = b'\x53'`. **0x53 is ActionNewMethod,
not ActionNewObject (0x40).** So `str = new (1).String(...)` → `undefined`, and the four `str` rows actually pin
member writes on undefined (no-ops) and `Array.prototype.join.call(undefined, '-')`. Ruffle `function.rs` `call`:
`this = try_get_object(0).unwrap_or_else(|| activation.global_object())`. So `this` is `_global`, whose `length` is
undefined → `""`. Ours already passed the `global_object` bag with the UNDEFINED tag, and now prints `""`.

The fixture keeps the bytes as generated, so it matches the oracle SWF. The docstring records the NewMethod fact, and
the row is labelled "`.call(undefined)`", not "String object".

**Flash semantics, and my confidence:**
- Function and MovieClip receivers: **high**. AVM1 Array methods are the ES3-generic algorithms (Ruffle `array.rs`
  `push`/`join` take any `this: Object` and go through `length` / `get_element` / `set_element`). Flash's own docs
  describe no receiver restriction, and gnash `array.as` likewise accepts any object.
- `.call(undefined)` → `_global`: **medium-high**. It is the Ruffle and gnash behaviour, and our runtime already
  hard-codes it for `.call`/`.apply` ("Flash: undefined/null thisArg → global object").
- A *real* String object: **not measured by this probe.** Ruffle would treat it as an ordinary object with an own
  `length` (DONT_ENUM|DONT_DELETE, *not* READ_ONLY, `string.rs` constructor), so `join` → `a-b` after the assignments
  and `push` → 3. Ours stores a String object as an OBJECT, so it takes the OBJECT arm already. If wave 2 wants it
  pinned, see LOCAL ORACLE REQUESTS #1.

## 4. Item 1: `video_prototype_lazy_swf6_child` (NO-GO at M; the s24 premise is half right)

**Riders.** A byte scan of every non-`test.swf` child SWF in `avm1 from_gnash from_shumway timeline swf` for
`gotoAndStop/gotoAndPlay/nextFrame/prevFrame` finds **only** `video_prototype_lazy_swf6_child/child.swf`. The other
side is a parent `test.swf` that both loads (`loadMovie`/`loadClip`) and gotos. That adds only gnash
`MovieClip-v6/v7/v8` (ruffle_matched 916/936, 949/969, 1062/1087, unchanged in the L5 sweep), and their goto lines
are not on a loaded holder. **So the "other loadMovie rows" premise is refuted: there are no riders.**

**Prototype, measured, then removed.** I wrote `actionChildMovieGoto(app_context, mc, target, play)` next to
`actionChildMovieSetPlaying` and routed the MovieClip method arm's NG/OFFSCREEN `gotoAndStop/gotoAndPlay` to it before
`ng_gotoFrameByMC`. It:
1. finds the holder's `LevelAdvanceEntry`;
2. applies the same version/globals/context/transform swap as `actionAdvancePlayingLevels`;
3. on a backward goto, runs `actionClearChildMoviePlacements`;
4. runs frames shown+1..n (or 0..n) under `catch_up_mode = 1`, tags only;
5. sets `current_frame = n+1`.

Result (graphics):

```
     3  child: same Video class as parent: false
-    4  child placed Video on P: width=- height=undefined, v.__proto__ == P: true
+    4  Warning: Failed to place object at depth 2.
+    5  child placed Video on P: width=- height=undefined, v.__proto__ == P: false
```

The routing works: the child's frame 2 now runs. But the child's `PlaceObject2(depth 2, Video, "v2")` lands in the
**global** `display_list`, because a `createEmptyMovieClip` holder's loaded children are interleaved with the
parent's. The parent's own `v2` already occupies depth 2 there, so the runtime refuses and prints a graded warning.
That is exactly the depth collision `SWFRecompDocs/status/child-timeline-advance.md` §2.2 records ("a *shared* display
list is also why a clip-target child collides with the parent's depths today"). Route 2 (`placed_by_holder`, landed
since) buys the wrap, **not** the collision.

**Completion mechanism:** route 1 of §2.2, **per-movie display-list ownership** for a clip-target holder. Either make
`mc->display_obj` safe for a dynamic clip (the 10-test `movieclip_invalid_get_bounds_1..8` / `swf{5_to_6,6_to_5}_cross_call`
regression must be root-caused), or add a holder-side child list that is not `display_obj`. **Price L, 1 row.**

Not in the patch, because it flips nothing and adds a graded warning on this row. The goto helper, for whoever takes
route 1, is the `apply_goto.py` text summarised above; it reuses the driver's swap verbatim. Its HOLD on top of route 1:
it suppresses the target frame's DoAction (Flash queues it) and clears every placement on a backward goto, with no
survives_rewind.

## 5. L2: `getBounds` engine (NO-GO, no row)

I swept the failing graphics trace rows of `avm1`, `from_gnash` (all five), `from_shumway`, `mixed_avm` and the misc
group for diffs on `getBounds`/`getRect`/`_width`/`xMin`, plus every non-pass row with bounds/rect/width in its name:
- The only bounds-flavoured diffs are **hitTest** lines: `DrawingApiTest`'s 12 lines are all shape-flag `hitTest`
  FAILs, and `movieclip_hittest_shapeflag` is hitTest too.
- `shumway pixelBounds` and `bitmapdata_custom_rectangle` are ruffle_matched and not this engine.
- `movieclip_getbounds` is an ACCEPTED_DIFF (morph precision).

**No row moves with a descendant fold.** Park until a row needs it.
**Lead:** the `DrawingApiTest` shape-flag `hitTest` family (12 lines) is a separate engine (drawing-API hit geometry).

## New unclaimed leads

- **TextFormat lazy names: 17 vs Ruffle's 19** (`kerning`, `letterSpacing`). Measure `text_format*` rows with SWF8
  `kerning`/`letterSpacing` after the gate lands. S.
- **TextFormat write-after-hide / instance `hasOwnProperty`** (§2 limits): no corpus row; S if one appears.
- **`DrawingApiTest` shape-flag hitTest** (12 lines, 81/93): drawing-API fill hit geometry (curves, inverted fills).
  Owner: hit-test engine. Unpriced.
- **Loaded clip-target movie depth collision** (§4): the same blocker covers the loaded-child renderer and looping
  items; route 1 is the single L arc for all three.

## LOCAL ORACLE REQUESTS

1. (Optional, only to pin the real String-object case of L5.) Ruffle exporter `--frames 1` (and Flash if available)
   on `make_l1.py` with the `str` constructor fixed: change `NM` to NewObject for the `str` row, i.e.
   `'str': push('xy',1,'String')+b'\x40'`. Expect from Ruffle: `str own join: a-b`, `str call join: a-b`,
   `str own push: 3`, `str len: 3`.
