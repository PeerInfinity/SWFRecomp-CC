# s26 w1-avm1-dispatch-scope: AVM1 dispatch / scope leftovers from s25

**New files** (all under `session26-fanout-reports/`):
- this report;
- `w1-avm1-dispatch-scope-prototype.patch` (`action.c` +221/−5, `timer.c` +12/−2; sources reverted);
- `w1-avm1-dispatch-scope-fixtures/`: `README.md`, `avm1asm.py` (a small AVM1 assembler), `build_all.sh`,
  `scan_bare_calls.py` (corpus census), and 10 fixture dirs `avm1_*/` (generator, `test.swf`, `test.toml`,
  `output.txt`, and `input.json` where needed).

Base: `origin/master` `ec07cc9e` (runtime identical to the s26 baseline code `697669e5f`). Corpus: `download_tests.sh
avm1 from_gnash`, 2026-11-23. Ruffle source: blobless clone at `3e98d9ba6`. The box: Dawn OK, lavapipe.

## Verdicts (ranked by game visibility)

No item has a failing corpus row. I grepped `s26-baseline-trace-failing.txt` for every touched family, and the census
below finds no corpus SWF that reaches the broken contexts. So **0 priced corpus flips**. Every GO is a correctness fix
with a `regression/` fixture. **Every golden is analytic** (written from Ruffle source) until the exporter runs; see
LOCAL ORACLE REQUESTS.

| # | item | verdict | price | fixture: master → prototype (both modes) |
|---|---|---|---|---|
| 1 | Bare MovieClip-method calls ignore the target clip and `with` | **GO** (prototyped) | S | `avm1_bare_mc_method_scope` 7/19 → pass |
| 2b | Function-form timer: `var` leaks onto the timeline; `arguments`/`this` wrong (L3) | **GO** (prototyped) | XS | `avm1_timer_function_form_activation` 0/3 → pass (analytic, timers) |
| 4+6 | CallMethod `createTextField` depth / numeric name; `replace_at_depth` | **GO** (prototyped) | S | `avm1_create_text_field_depth` 1/9 → pass |
| 2a | Type-2 `watch` callback on a clip gets `this` = undefined (L2) | **GO** (prototyped) | XS | `avm1_type2_mc_receiver_dispatch` 6/7 → pass |
| 5a | Typing into an HTML field drops its runs | **GO for the insert path** (prototyped); other edit paths HOLD | S (+S) | `avm1_edittext_html_typed_runs` 1/3 → pass (analytic, input) |
| 7a | Device-text x-scale for DefineEditText (and default-face −2) fields | **GO** (prototyped) | XS | `avm1_device_edittext_xscale` 3/7 → pass |
| 3 | Hairline `lineStyle(0)` hitTest | **GO** (prototyped). Premise partly refuted: it is a **mode-parity** bug | XS | `avm1_hittest_hairline` ng 25/28, gfx pass → pass both |
| 7b | SWF≤7 wrap give-up missing from the scroll path | **HOLD**, measured | S | `avm1_wrap_giveup_mixed_runs` 0/2 (not prototyped) |
| 5b | `setNewTextFormat` writes `textColor` | **Trace premise REFUTED**; render defect real → **HOLD** | S–M | `avm1_set_new_text_format_color` pass on master (trace lock) |

`movieclip_hittest_shapeflag` (ACCEPTED_DIFFS Cat 8): **the entry is stale**, and item 3 does not touch it (see item 3).

## Argued sweep (prototype vs the s26 baseline CI rows; status + matching-line count)

- **Graphics, 185 rows, 0 movers.**
  - **39 avm1 rows:** every `with*`, `watch*`, timer (`set_interval`, `timeout`, `timer_run_actions`,
    `string_paths_timer`), `*hittest*` and `edittext_*` input/format row. Also the census's bare-call rows
    (`create_empty_movie_clip`, `clone_sprite_*`, `do_init_action_child`, `duplicate_movie_clip_drawing`,
    `edittext_onscroller`, `hitarea_sweep`, `native_objects_swf6`, `movieclip_gettextsnapshot`, `sound_nested_clips`,
    `named_shapes`, `get_bytes_total`, `this_scoping`), plus `local_to_global`, `movieclip_create_text_field`,
    `movieclip_get_instance_at_depth`, `textfield_props_swf8` and `edittext_width_height`.
  - **16 from_gnash rows:**
    - `MovieClip-v6/7/8`, `TextField-v6/7/8`, `TextFormat-v6/v8`, `with-v6/7`;
    - `ButtonEventsTest`, `DrawingApiTest`;
    - `action_execution_order_test12`, `gotoFrameFromInterval2`, `opcode_guard_test2`;
    - `gotoFrameFromInterval`: CI-excluded (`ruffle-tests.yml:869`). It OOMs as `runtime_error` identically on clean
      master.
  - **The whole regression suite: 130/130 pass.**
- **No-graphics, 22 rows, 0 movers:**
  - from_gnash: `DrawingApiTest`, `with-v6/7`, `MovieClip-v6/8`, `TextField-v6/7/8`;
  - avm1: 14 rows (the hittest, timer, watch, `this_scoping`, edittext and textfield rows).
- **The 10 fixtures, A/B in both modes:** the table above and `fixtures/README.md`.

---

## 1. Bare MovieClip-method calls (`ActionCallFunction`): enumeration and fix

**Mechanism.** In Ruffle, `action_call_function` calls `get_variable(name)`, which returns
`CallableValue::Callable(scope_object, fn)`. So `this` is the innermost `with` clip, or else the **target clip**: a
sprite's own frame script, a `tellTarget` block, or a closure's base clip (`avm1/activation.rs`, `scope.rs`). In ours,
all three of those set `g_current_context`. Every bare MC method in `actionCallFunction` (`action.c` on
`origin/master`), and which receiver it used:

| arm (`action.c`) | receiver before | correct? |
|---|---|---|
| Drawing API `beginFill…clear`, `begin{Gradient,Bitmap}Fill`, `lineGradientStyle` (:66435) | innermost with-MC, else base clip (the last three only inside `with`) | yes (minor: a with plain object that carries the name does not shadow) |
| `createTextField` (:67339) | **hard-coded `_root`** | **no**: wrong in sprite frames, `with`, `tellTarget` and closures |
| `createEmptyMovieClip` (:67572) | with-MC (s25), else `g_current_context` | yes |
| `attachMovie` (:67702) | `g_current_context` | **no** inside `with` |
| `getNextHighestDepth` (:67846) | **hard-coded `_root`** | **no** everywhere except root |
| `getInstanceAtDepth` (:67866) | `g_current_context` | **no** inside `with` |
| `gotoAndStop/Play`, `getBytesLoaded/Total`, `getDepth` (`_is_mc_nav`, :67996) | with-MC, else `g_current_context` | yes |
| `stop`, `play`, `prevFrame`, `nextFrame` (same arm) | resolved, then **no-op** ("dynamic clips don't advance", stale) | **no** |
| `getBounds`, `getRect`, `hitTest` (`_bm_match`, :68140) | with-MC, else `g_current_context` | yes |
| **everything else on `MovieClip.prototype`**: `localToGlobal`, `globalToLocal`, `swapDepths`, `setMask`, `duplicateMovieClip`, `removeMovieClip`, `startDrag`, `stopDrag`, `getURL`, `loadMovie`, `loadVariables`, `unloadMovie`, `getSWFVersion`, `getTextSnapshot` | the name resolves to the `g_mc_method_funcs` stub (:16739; type-1, NULL pointers). It falls to "built-in constructor as plain function" (:68393) and pushes `undefined` | **no**: a silent no-op |

**Measured** (`avm1_bare_mc_method_scope`, master, both modes):
- A sprite frame's `createTextField` landed on `_root`.
- `getNextHighestDepth` returned root's value (6, not 9; 21, not 4).
- Inside `with (w)`: `getInstanceAtDepth(2)` gave `undefined`, `attachMovie` attached to `_root`, and
  `swapDepths(40)` / `localToGlobal(p)` did nothing.
- `tellTarget("c") { createTextField }` and a closure on `c` both created on `_root`.

**Census** (`scan_bare_calls.py` over the avm1/gnash/shumway corpora + `docs/examples` + `demos`): bare calls in a
`with` or sprite context are rare in the corpus:
- `createEmptyMovieClip` ×14 (all in DrawingApiTest), `setMask` ×1, `gotoAndStop` ×2, `hitTest` ×3, `getDepth`/`getBytes*`
  in sprites.
- No `createTextField`, `attachMovie` or `getNextHighestDepth` in a sprite, `with` or `tellTarget` context.
- That explains the zero corpus rows.
- Game visibility is still the highest of this brief. Flash-IDE content puts this code in child-clip frame scripts and
  `tellTarget`/`with` blocks, and Flash's compiler emits `CallFunction` there (the Pacman `with(Ghost[g]){gotoAndStop(1)}`
  comment at :68055 is the in-tree precedent).

**Prototype** (all in `actionCallFunction`):
- New `static cfBareMCReceiver()`: the innermost with-MC, unless a with plain object carries the name, else
  `g_current_context`.
- The `createTextField` / `getNextHighestDepth` / `attachMovie` / `getInstanceAtDepth` arm heads delegate through the
  existing `cfDelegateToMCMethod` **only when that receiver differs** from what the arm used before. So root-context
  calls are byte-for-byte the old path.
- `stop/play/prevFrame/nextFrame` delegate to the CallMethod arm.
- **A generic arm** before the call-depth check: a name that resolved to a `g_mc_method_funcs` stub (other than
  `meth`) runs that method on the clip it was found on (`callable_this` when it is a MOVIECLIP, else
  `g_current_context`).
  - This is Ruffle's rule exactly. A user function with the same name, found earlier on the scope chain, still wins.
- **Price S** (~120 lines).
- **Residual:** stop/play through the generic path now really act. No sweep row moved (`named_shapes` has a root bare
  `stop` and still passes).

## 2. Type-2 dispatch arms (L2) and the function-form timer (L3)

**L2 audit.** `invokeFunctionValue` hands the raw `MovieClip*` to a type-2 prologue when all of these hold:
- `this_var` is a MOVIECLIP;
- the call has no `INV_MC_THIS_NULL_PTR`, no `has_this_ptr` and no `INV_OVERRIDE_THIS` (`action.c:16642`).

The prologue tags that pointer OBJECT, so `this.x` misses.

I listed all 60 call sites (script in my session; criteria above) and probed the ones a clip can reach:

| arm | receiver can be a clip? | result |
|---|---|---|
| CallMethod MOVIECLIP, `Function.call/apply`, `addProperty` getter, `AsBroadcaster.broadcastMessage` listener | yes | **correct** (fixture rows pass on master) |
| `invokeWatchCallback` (:3598; sites A/B/C) | yes (`mc.watch`) | **BUG**: `watch: undefined v=undefined`. Fixed: add the flag pair when `this_var` is a MOVIECLIP and the watcher is type-2 |
| `invokeResolveFunction` (:9334) | would be | moot: `__resolve` on a clip is **never called** (new lead, fixture `avm1_mc_resolve` 0/5) |
| `actionEI_callInternalInterface` (:7243) | yes (`ExternalInterface.addCallback(n, this, f)` on a timeline) | flag pair absent. Not probed (no EI host in the harness or exporter). **Unpriced lead, XS to apply the same guard** |
| `objectCallValueOf/ToString`, `objectToPrimitive`, `convertFloat` | only if a clip's coercion calls a user `valueOf`/`toString` | not probed (Ruffle's display-object coercion path unverified) |
| lc/ns/nc/LoadVars/Sound/sort/MCL | no (non-clip receivers) | n/a |

**L3, measured.** `fireTimerCallback`'s function-form arm (`timer.c` ~:400) builds **no local scope**. Fixture,
master, both modes:
- `var lx` / `var ly` inside the callback **land on `_root`** (`leak: lx=number`);
- a type-1 callback sees `arguments.length` = undefined;
- `this` is `movieclip`. Ruffle: `undefined` (`timer.rs` `Avm1Function` → `func.call(.., Undefined, ..)`; `function.rs`
  `exec`: `new_local_scope`, `local_this = this`).

**This is the game-visible half.** Flash MX / SWF5–6 code compiles `function tick(){ var i … }` to a type-1
DefineFunction with **by-name** locals. Every `setInterval(tick, …)` then clobbers the timeline's `i`.

**Prototype:**
- the function-form arm adds `INV_LOCAL_SCOPE`;
- it adds `INV_BIND_THIS` for type-1;
- it sets `act_flags = INV_ACT_THIS | INV_ACT_ARGUMENTS`;
- the `this_var` is an UNDEFINED `ActionVar` instead of NULL.

Type-1 still gets no captured scope (the pre-existing normalization note in the arm).

## 3. Hairline `lineStyle(0)` Drawing-API hitTest (and the Cat 8 re-test)

**The s25 premise is partly refuted.** "Committed hairlines can't be hit" is true only:
- in **no-graphics**;
- in graphics before the first render.

The graphics renderer rebuilds `line_verts` at the 1-screen-px minimum (`drawingBuildStroke` via the
render-scale check, `action.c:33157`), and the triangle test then hits.

So this is a mode-parity bug: CI-graphics and the browser were already right after a render. Fixture: no-graphics
fails the 3 committed-diagonal rows (`hc` 350,175 / 175.4 / 174.6); graphics passes all 28. Pending strokes were
already distance-tested (s25).

**Prototype** (the `actionCallMethod` hitTest committed-path loop):
- A path whose `line_width` is at most 1 screen px is hit by `drawingSegDistHit` over its retained `stroke_poly`.
- The half-width is Ruffle's: 0.5 × max(width, 1 px / max-axis scale) (`shape_utils::draw_command_stroke_hit_test`,
  `stroke_minimum_width`).
- Those paths skip their line triangles. Thicker strokes are untouched.
- DrawingApiTest `:125` (`! hitTest(376,180,true)`, the s25 zero-area case) still passes. The point is collinear but
  beyond the segment end.

**Analytic correction:** `h.hitTest(150, 99.6)` is **false** in Ruffle. The point is within 0.5 px of the line, but
`world_bounds` (edge bounds, which for a 0-width line are not expanded) rejects it first (`movie_clip.rs:2701`,
`drawing.rs stretch_bounds`). We match.

**Cat 8 re-test** (`movieclip_hittest_shapeflag`, graphics = no-graphics, master = prototype):
- **6 diff lines, not the 9 the entry lists**: `:71`, `:171`, `:173`, `:175`, `:177`, `:296`.
- `:137` (scribble), `:163`, `:165` and `:167` now pass. `:173` is new.
- `:71` is in the **"layers"** section, not text. The entry attributes it to Noto glyphs, which is wrong.
- Nothing there is a hairline.

The entry needs rewriting, by the coordinator; I did not edit disposition docs.

## 4 + 6. CallMethod `createTextField` depth / numeric name; `replace_at_depth`

**Measured** (`avm1_create_text_field_depth`, master):
- `this.createTextField("tf", 7, …)`: `tf.getDepth()` = **0** (`(void)depth_val`, `action.c:75254`), and
  `getNextHighestDepth` = 1.
- A second field at depth 7 **does not replace** the first (`tf` still `object`); `getInstanceAtDepth(7)` =
  `undefined`; `createEmptyMovieClip` at 7 leaves `tf2` alive.
- `createTextField(3, …)` creates no `_root["3"]`.
- `createTextField` over a clip at the same depth leaves the clip.

Ruffle `movie_clip.rs create_text_field`: the name is `coerce_to_string`, then `replace_at_depth`.

**Prototype:**
- Both `createTextField` arms remove the previous dynamic occupant of `(parent, depth)`, as the `createEmptyMovieClip`
  arms already do.
- The CallMethod arm stores the depth (ToNumber, NaN/Inf → 0) and ToStrings a numeric name.
- The s25 "storing depth regresses v7" worry did not reproduce: TextField-v6/7/8 and `movieclip_create_text_field` are
  unchanged.

**Game visibility: medium-high.**
- AS2 class code always uses the CallMethod form.
- A HUD that re-creates its label at the same depth each refresh currently **accumulates** fields, one more per refresh
  (overdraw plus `child_mc_cache` growth).
- Depth-0 fields also skew `getNextHighestDepth` for every clip created afterwards.

**Residual:** timeline-placed occupants at that depth are not replaced by either arm, which matches the existing
`createEmptyMovieClip` gap. Images: the s25 TF-REST-pass note says paint order does not use depth, so pixel risk is
low. Still run `images=true` once on landing.

## 5. Text edit paths

**5a, measured** (`avm1_edittext_html_typed_runs`, `input.json` types "C" at the end, then "D" at 0). After the first
keystroke, `getTextFormat(i).color` reads **0 for every char**: `tf_invalidate_run_table(g_focused_mc)` dropped the
`<font color>` runs.

Ruffle `FormatSpans::replace_text`:
- the typed text takes the span **after** the caret;
- when appending, it takes `default_format`.

**Prototype:**
- New `static tf_ps_on_typed()` edits the run table in place (`tf_table_replace` with that format) in
  `actionTextFieldInput`.
- It skips the invalidate when it handled the field, and is guarded off when `maxChars` truncated the result.

**HOLD, priced S:** the remaining callers still drop the table: `actionTextControlCut` (:83034), `Backspace`
(:83219/:83280), `Delete` (:83305/:83364) and `actionTextFieldImeCompose` (:83756). Completion: route the cut,
backspace and delete callers through `tf_table_replace(…, ins_len = 0)`, and IME through `tf_ps_on_typed`.

**5b: the brief's premise ("`setNewTextFormat` writing `textColor` is wrong") is refuted on the trace side.** Ruffle's
`textColor` getter **is** `new_text_format().color` (`avm1/globals/text_field.rs:352`).

The s25 claim cited `_text_same`, but that test never sets a colour through `setNewTextFormat`. The fixture's 4 rows
match Ruffle on master:
- `textColor` = 16711680;
- span 0 = 0;
- newfmt = red;
- the next `text =` is red.

**The real defect is render-only (code-read):**
- A plain (no run table) field draws with `dynamic_props.textColor` (`actionIterateTextFieldGlyphs`, `action.c:30938`).
- So `tf.text = "AB"; tf.setNewTextFormat({color:red})` repaints the existing "AB" red. Flash and Ruffle keep it black.

**HOLD.** Completion:
- render plain fields from the span model's colour, not `textColor`;
- keep the getter on newfmt.

A pixel fixture needs an **embedded** font: device text renders neither in the exporter nor in a cloud graphics build.
I measured that: a bordered `createTextField` drew the border only.

## 7. Device text x-scale; the SWF≤7 wrap give-up

**7a, measured:** a timeline DefineEditText device field (UseOutlines = 0) reports `textWidth` 102 at every
`_xscale`/`_yscale`. Ruffle `measure_text` uses `layout_to_local_matrix` × `device_font_scale_x` = d/a.

The s25 gate (`computeTextFieldDimension`, `dyn_device_face`, `action.c:58829`) also skips **−2 fields whose default
face resolves to id 0**, which is any movie without `[default_fonts]`.

**Prototype:** the gate also accepts:
- −2 fields;
- DefineEditText fields without flag 0x0080 (UseOutlines);

in both cases unless runtime `embedFonts = true`. The fixture's ratio rows (±1 px) pass. The absolute widths depend on
the device face, so the exporter number replaces my 102.

**7b, measured, HOLD:** a 12 px-wide SWF7 word-wrap field with `HelloWorld` reports `maxscroll`/`bottomScroll` = 1/8
(plain) and 4/7 (mixed sizes). Ruffle's `!swf8` give-up gives 1/1.

The give-up exists only in `ng_wrap_count_lines` (`ng_shared.c:1797`). `ng_computeScrollMixedFont`
(`ng_shared.c:2100`) serves **every** field's scroll metrics, not only mixed runs, and still breaks per character. So
does `tag.c`'s render wrap.

Completion:
- port the same `!is_swf8` block into `ng_computeScrollMixedFont`'s break loop (S, trace);
- then the `tag.c` wrap (pixel; coordinate with `n-pixel-pass`, which may touch `tag.c`).

I did not prototype it: `ng_shared.c` is shared with `w1-runtime-robustness`.

## Functions touched by the prototype (for `n-pixel-pass` / sibling coordination)

- **`action.c`:**
  - `invokeWatchCallback`;
  - new `static tf_ps_on_typed`;
  - new `static cfBareMCReceiver`;
  - `actionCallFunction`: the createTextField, attachMovie, getNextHighestDepth and getInstanceAtDepth arm heads; the
    createTextField depth replace; the `_is_mc_nav` stop/play arm; the new generic stub arm;
  - `computeTextFieldDimension` (the x-scale gate);
  - `actionCallMethod`: the createTextField arm and the hitTest committed-path loop;
  - `actionTextFieldInput`.
- **`timer.c`:** `fireTimerCallback` (the function-form arm only).
- **Not touched:** `tag.c`, `swf.c`, `ng_shared.c`, `swf_core.c`, `tag_stubs.c`, and all button or mouse dispatch.

## Refutations / premise attacks (summary)

- **Item 3:**
  - "Committed hairlines can't be hit" holds in no-graphics only. In graphics the renderer's 1 px rebuild already makes
    them hittable.
  - "Re-test Cat 8 against item 3": Cat 8 has no hairline row. Its entry is stale: 6 lines, not 9; `:71` is "layers",
    not text.
- **Item 5b:** `setNewTextFormat` → `textColor` is Ruffle's getter semantics. Only the render colour source is wrong.
- **Item 1, "sibling arms ignore `with`":** understated.
  - The bigger bug is the **non-with** target: `createTextField` and `getNextHighestDepth` hard-code `_root`.
  - Fourteen MC methods have **no** bare arm at all; they are silent no-ops.
  - `stop`/`play` resolve and then do nothing.
- **Item 4, s25 w1's "v7 regressed by 4":** it does not reproduce with the depth store. The numeric-name lines live
  in the CallFunction form, as w2-textfield-vn found.

## New unclaimed leads

- **`__resolve` on a MovieClip is never called** (fixture `avm1_mc_resolve`, 0/5).
  - Ruffle: `Object::get` → `get_opt(.., call_resolve_fn = true)` for stage objects too.
  - Price S–M: the GetMember MOVIECLIP miss path should call `invokeResolveFunction` with the flag pair.
- **Browser-WASM `createTextField` is a no-op in both arms** (source-read, unmeasured; no browser build here).
  - The CallFunction arm (`action.c:67341`) and the CallMethod arm (:75241) are `#if NO_GRAPHICS || OFFSCREEN_RENDER`
    with an `#else` that pushes `undefined`. So no dynamic text field is ever created in the browser.
  - `tools/gate_inventory.py` classes both as `all-configs`, because the `#else` has code. The tool cannot see no-op
    `#else` arms; extend it.
  - This is likely the most game-visible item found. Owner: browser/N line.
  - `getInstanceAtDepth` (CallFunction, :67868) has the same shape.
- **Malformed DefineFunction2: a register index ≥ `register_count` smashes the C stack** (`*** stack smashing
  detected ***` in the recompiled `func2_*`).
  - My first fixture draft did this.
  - Ruffle ignores out-of-range register writes.
  - Candidate for `w1-runtime-robustness`: the recompiler should clamp or ignore.
- **`ExternalInterface.addCallback(name, clip, fn)` with a type-2 `fn`:** the flag pair is missing
  (`actionEI_callInternalInterface`, :7243). XS, same guard as watch.
- **Stale comments:** `_is_mc_nav` "stop/play: no-op for dynamic clips"; `actionCallFunction` "getNextHighestDepth —
  as a global function, operates on root".
- **`gotoFrameFromInterval` (CI-excluded) OOMs locally** (a kernel OOM kill at ~20 s, identical on master). A memory
  blow-up, not just a wrong answer: a robustness candidate.

## LOCAL ORACLE REQUESTS

All fixtures are in `SWFRecompDocs/plans/session26-fanout-reports/w1-avm1-dispatch-scope-fixtures/`. For each one,
`exporter -s -f <N> --trace-log out.txt avm1_<name>/test.swf out.png`.

If the trace matches the staged `output.txt`, move the dir to `ruffle-tests/tests/swfs/regression/`. If it differs,
replace `output.txt` with Ruffle's trace and tell wave 2 which rows moved.

1. `avm1_bare_mc_method_scope`, `-f 5`.
   - Verify the row order: our sprite `c` frame-1 trace runs before root frame 2's. Root frame 1 has no trace, by
     design.
   - Verify `getInstanceAtDepth` prints `_level0.c.e1`.
2. `avm1_type2_mc_receiver_dispatch`, `-f 2`.
3. `avm1_hittest_hairline`, `-f 5`, 28 rows. The `99.6 → false` row is the bounds-rejection prediction.
4. `avm1_create_text_field_depth`, `-f 2`.
5. `avm1_set_new_text_format_color`, `-f 2`.
6. `avm1_device_edittext_xscale`, `-f 2`. The absolute widths will be Ruffle's device face; the three `~` rows must be
   `true`.
7. `avm1_wrap_giveup_mixed_runs`, `-f 2` (SWF7). The prediction is 1/1 for both rows.
8. `avm1_mc_resolve`, `-f 2`.
9. **No exporter:** these goldens stay analytic unless a Ruffle desktop / `tests` harness run is possible.
   - `avm1_timer_function_form_activation`: timers. Needs ~10 frames at 12 fps with a 10 ms interval.
   - `avm1_edittext_html_typed_runs`: `input.json` TextInput.
   - If the coordinator can run Ruffle's own test runner (it fires timers and consumes `input.json`), please run both.
     Otherwise land them marked "analytic, Ruffle-source-derived" (s25 precedent: `timer_type2_method_mc`).
