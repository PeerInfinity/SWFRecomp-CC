# w1-native-proto — AVM1 native builtin surface: prototypes and lazy prototypes (s24 wave 1)

**New files:** this report; `w1-native-proto-prototype.patch` (`git diff origin/master -- SWFModernRuntime`, 158
lines, one file `SWFModernRuntime/src/actionmodern/action.c`, applies cleanly to `df126b80`).
Box: cloud, Dawn OK (SETUP_STATUS all OK). Upstream tests downloaded at Ruffle master **`bcac30c19`** (= the s24
baseline's drift endpoint; `avm1` + `from_gnash`). All runs `--mode=graphics` unless stated.

## Verdicts (lead)

| Row | Baseline | Verdict | Mechanism | Price |
|---|---|---|---|---|
| `avm1/lazy_prototype_shared` | 6/8 | **GO, measured PASS** | ONE player-wide "lazy props defined" set shared by Video + TextFormat; TextFormat fields defined lazily | S (in patch) |
| `avm1/video_prototype_lazy` | 20/21 | **GO, measured PASS** (both modes) | Video lazy props on an **Array** prototype + MC accessor walk through an ARRAY `__proto__` | S (in patch) |
| `avm1/text_format_prototype_lazy` | 6/35 positional | **HOLD (no flip in wave 2)**. Patch takes it from 13 to 23 LCS-matched lines (positional diff from −29 to −19). | 3 mechanisms, one of them L (below) | L for the flip |
| `avm1/video_prototype_lazy_swf6_child` | 4/8 | **NO-GO for this slot**: not a prototype bug | `gotoAndStop` on a loadMovie'd AVM1 child's root never runs the child's frames | M, timeline owner |
| `avm1/global_proto_decls` | known_failure, ignored | **NO-GO** (unflippable: 773 missing props, 45 missing sections) | patch removes 17 ours-only lines, 0 matched lost | — |
| `avm1/global_proto_decls_delete` | known_failure, ignored | **NO-GO** (1865 missing props) | unchanged by patch | — |
| `avm1/global_instance_decls` | known_failure, ignored | **NO-GO** (211/759) | patch removes 17 ours-only lines, 0 matched lost | — |
| `avm1/globals_swf5` | known_failure, ignored | **NO-GO**, but the **disposition rationale is refuted** (see §3) | flipping costs 3 gnash `pass` rows (known_failure → REGRESSION) | — |
| `avm1/native_objects_swf6` | known_failure, ignored | **NO-GO** (ACCEPTED_DIFFS Cat. 2, TextField-gate family, arc §10.2) | unchanged | — |

**Priced flip list for wave 2: `avm1/lazy_prototype_shared`, `avm1/video_prototype_lazy`. That's +2, at measured
zero riders across a 47-row before/after sweep.** Both rows came in with the upstream drift: lazy_prototype_shared was
added in `0ddd12b6a..bcac30c19`, and video_prototype_lazy was a s23 leftover. Book them as drift-row passes, not as a
recovered regression.

**Board premise refuted:** "native builtin methods expose a `prototype`" is not one fixable mechanism and does not
gate any graded row. In the decls tests the `prototype` mismatch runs **both ways**: 339 functions have a `prototype`
in Flash but not in ours, and 180 have one in ours but not in Flash (§2). All three rows that show it are
known_failure + ignored, with thousands of other missing lines. Nobody should touch `setupNativeFuncOwnProps` for score.

## 1. What Flash does (Ruffle `bcac30c19`)

- `core/src/avm1/property_decl.rs::define_lazy_proto_properties`: some native classes **do not define their
  instance-facing properties on the prototype up front**. When an instance with native data is created, the
  properties are defined **on the prototype that instance gets**. They are defined at most once per prototype
  **object**, and **regardless of class**: one `Vec<ObjectWeak>` in the player, `runtime.rs:110`
  `lazy_initialized_prototypes` / `mark_lazy_proto_initialized:630`. Existing values are overwritten. A deleted
  property is never re-defined. A prototype that got Video's properties never gets TextFormat's.
- Video (`globals/video.rs`, `d900f711d`/`c8a03ccd3`): `width`/`height` are defined when a Video **display object**
  is created. `new Video()` does not count.
- TextFormat (`d205531a2`, inside the drift window): the 17 fields (`font`, `size`, …, `display`) are **accessor
  properties** (getter/setter over the native data), defined lazily when a TextFormat is constructed with `new`, and
  when `TextField.getTextFormat` / `getNewTextFormat` creates one. Calling `TextFormat()` without `new` doesn't
  count. If `this` already has native data of any class (for example `super()` onto a Date, an Array or a
  TextFormat), nothing is defined, but **the arguments are still converted** (`font.toString()`,
  `size.valueOf()`). The same commit also removed 19 lines from Ruffle's own `global_proto_decls/output.ruffle.txt`:
  they don't predefine these either.
- Function `prototype` (`property_decl.rs:272 DeclFunctionKind`): `Native` (an ASnative host function) has **no**
  `prototype`. `As2` (implemented in ActionScript inside FP's playerglobal) is a full Function with a fresh
  `prototype`. `Bare` has neither. Flash's classification is per function, not per class.

## 2. Per-row diff shape and owner

### `lazy_prototype_shared` (6/8 → 8/8)
The diff is on lines 1–2. `new TextFormat()` on a fresh `p1` did not define `font`/`size`, because our
`TextFormat.prototype` gets the 17 fields **eagerly** (`initTextFormatPrototype`, action.c ~19102 on master). A
Video placed on `p1` afterwards did define `width`/`height`, because the Video set was private
(`g_video_lazy_protos`, action.c:41312 on master).
**Fix (in patch):** `lazyProtoMarkInitialized()` is one shared 128-slot set (it keeps the retained-pointer rule the
Video set used) that both Video and TextFormat consult. `textFormatDefineLazyProps()` defines the 17 names (as
undefined data slots, see §2.3) on the instance's prototype. It runs from the `new TextFormat` arm
(`actionNewObject`, `strcmp(ctor_name,"TextFormat")`, master action.c:60442) and from `createTextFormatFromField`
(master :18751, which covers getTextFormat/getNewTextFormat). The eager install is deleted. `createBlankTextFormat`
(StyleSheet.transform) is left alone, which matches Ruffle (no define there).

### `video_prototype_lazy` (20/21 → 21/21, graphics and no-graphics)
The diff is line 18 (`Video.prototype = [1,2]`). `actionOnVideoPlaced` (master action.c:41575) only accepted an
OBJECT prototype, so nothing was defined and `v.width` came back undefined.
**Fix (in patch):** for an ARRAY prototype, define the props in the array's non-index bag (`arr->props`) and keep
`__proto__` as the ARRAY value. The MovieClip GetMember accessor walk (`Walk __proto__ chain for addProperty getters`,
master action.c:~58370) now steps through an ARRAY `__proto__` into `arr->props`, so `v.width` invokes the getter
(→ 0).

### `text_format_prototype_lazy` (HOLD). Patch: 13 → 23 LCS-matched of 35
Lines 1–3, 5, 8–15 and 18 now match. What remains needs three more mechanisms:
1. **(L) Accessor model.** Lines 4, 6 and 7 expect `c.font=undefined` after `delete TextFormat.prototype.font`. In
   Flash an instance has no own fields: `tf.font` reads native data through the **prototype accessor**. Our
   TextFormat keeps 19 own data slots per instance (`actionNewObject` TextFormat arm, `createTextFormatFromField`,
   `createBlankTextFormat`, plus every getter/setter path). Making the fields accessors touches every TextFormat
   read, write, for-in and getTextFormat path, and about 40 avm1 rows use TextFormat (§4). A narrower M variant is a
   read-time check: a NATIVE_TEXTFORMAT own field resolves only if an accessor for that name exists on its `__proto__`
   chain. Writes after the accessor is deleted then need a "plain property" flag. It is unproven and riskier than
   it looks. Until (1) lands, the patch's TextFormat prototype slots are **inert undefined data**, which is
   observably equal for `hasOwnProperty`/`typeof` on a plain prototype. The exception is a prototype that is itself
   a TextFormat (line 17): there, existing own slots are kept, because they are its fields.
2. **(S–M) `super()` into the native TextFormat constructor** (lines 20–34). `invokeNativeSuperConstructor`'s
   TextFormat arm (master action.c:~64050, "simplified — just store first two args") stores raw args and does no
   conversion. Flash runs the full 13-argument conversion (`toString`/`valueOf` side effects, visible as trace lines).
   On a non-native `this` it sets native data and defines the lazy props on `this.__proto__`. On an already-native
   `this` (TextFormat, Date or Array) it stores nothing and defines nothing. This needs the `new`-path coercion pulled
   into a shared helper; today the `new` path also stores `font` raw, with no `toString`.
3. **(S) Array as `TextFormat.prototype`** (line 16). The same ARRAY treatment as Video, but on the TextFormat
   constructor's prototype slot (`g_textformat_constructor.prototype_obj` is an `ASObject*`).

After (2)+(3) the row is expected around 32/35. It flips only with (1).

### `video_prototype_lazy_swf6_child` (4/8): refuted as a prototype row
I instrumented `ng_on_place_object2` and `actionOnVideoPlaced`. The **child SWF's PlaceObject of `v2` never runs**:
there are 4 calls, all from the parent. The child's `this.gotoAndStop(2)` (and `gotoAndStop(1)`) on its own root
timeline is not routed to the loaded movie's `frame_funcs`. Only `stop()`/`play()` are routed, via
`actionChildMovieSetPlaying` (action.c:25143, `childMovieEntryFor`). So `this.v2` is not the child's Video, and line 4
fails `v.__proto__ == P`. Lines 5–7 follow from that: R never gets the props in the child, so the parent defines them
later. The lazy-proto side is already right: the set is per object and shared across movies, and we pick the
version-appropriate `_global.Video` through `getActiveGlobal()`. **Completion mechanism:** route
`gotoAndStop`/`gotoAndPlay` on a loaded AVM1 movie's root to its `LevelAdvanceEntry`. That means a display-list
rewind for a backward goto, and frame_funcs replay with the child's version, globals and context swapped in, the
same swap `actionAdvancePlayingLevels` (action.c:~25330) does. Price M, owner timeline/loader (`w1-attach-order`
family), not this slot.

### `global_proto_decls` / `_delete` / `global_instance_decls`: the "native functions expose a prototype" claim
I keyed the props by `Testing <section>` and property name from the after-run, then compared with output.txt:
- `global_proto_decls`: 4108 expected props; 2628 same, **773 missing**, 186 differ only by flags, 156 ours-only;
  `type` mismatches **339 `function with prototype` → `function`** and **180 `function` → `function with prototype`**.
  There are 453 sections in Flash and 408 in ours.
  - Flash has a `prototype` and we don't: `flash.geom.{Rectangle,Matrix,Point,ColorTransform}.prototype.*`,
    `NetStream.prototype`, `LoadVars.prototype`, `XMLSocket.prototype`, `ContextMenu.prototype`, the
    `*.broadcastMessage` / `Key.is*` statics, `System.showSettings`, `_global.addRequestHeader`. These are
    playerglobal **AS2** functions in Flash, and ours are natives created with `no_lazy_prototype=1`
    (`setupNativeFuncOwnProps`, action.c:43298).
  - We have a `prototype` and Flash doesn't: `MovieClip.prototype` (40), `Date.prototype` (38), `Sound.prototype`
    (15), `XML`/`XMLNode`/`Array`/`TextField`/`TextSnapshot.prototype`, `ExternalInterface` internals,
    `ASSetNative`/`ASSetNativeAccessor`/`ASconstructor`. These are ASnative functions with no own-props setup, so
    GetMember's lazy-prototype creation (action.c:58171 `if (func->no_lazy_prototype)`) materialises one.
- `global_proto_decls_delete`: 1865 of 3702 missing. `global_instance_decls`: 211 of 759 LCS.

So this is ~519 lines of a two-way per-function `Native`/`As2` classification, inside rows that are 45 sections
short. Even a perfect classification flips nothing. Rider exposure: any row reading `typeof X.prototype.m.prototype`
or enumerating a builtin. **NO-GO.** The completion mechanism is a per-function kind table transcribed from Ruffle's
decls, extended by hand where Ruffle is itself wrong (geom, which Ruffle also fails). That's L for 0 flips. Leave it
until the decls rows' missing sections are closed first.

The patch's effect here (content-checked, not positional): the 17 `TextFormat.prototype` field lines and 17
`global_instance_decls` lines it removes were **all ours-only**. The matched count is unchanged (2337 and 211). The
positional diff-line count *rose* 4503 → 4512 only because of alignment shift. It is not a regression, and
Ruffle's own expectation dropped the same lines in `d205531a2`.

## 3. Disposition re-test: `globals_swf5` rationale is refuted, but the decision stands

`ignored_tests.txt:211` and `RUFFLE_VS_FLASH_DIFFERENCES.md` ("SWF5 Constructor Visibility") say *Ruffle exposes
LocalConnection/NetConnection/Video in SWF5; Flash hides them.* But `globals_swf5` is **`known_failure = true`**, and
`output.ruffle.txt` differs from `output.txt` **only at line 136**. So output.txt, which is Flash's capture, has
LocalConnection/NetConnection/Video **visible** (`[type Function] / function / object`) in SWF5, and Ruffle matches
Flash there. The evidence for hiding them is gnash's `LocalConnection-v5`, `NetConnection-v5` and `Video-v5`. All
three are `known_failure` (Ruffle fails them) and `pass` for us on the baseline. Un-hiding them would make
`globals_swf5` 3 lines better and still failing (line 136 remains), and it would turn those 3 gnash rows from
`pass` to `ruffle_matched`, which is a **REGRESSION** by standing rule 3. So: **keep the code and the ignore entry,
and correct the doc's wording**: "Flash's capture shows them visible; gnash's v5 tests (Flash-unverified here)
assert hidden; we follow gnash because flipping costs 3 known_failure passes." That's a doc edit for the
coordinator. I didn't make it because this slot is report-only.

Line 136 (the residual) is `typeof TextField.prototype` at SWF5. Flash says `undefined`; Ruffle and we say `object`.
That is the TextField-gate family from arc §10.2, where gating cost 7 regressions once. Do not chase it.

## 4. Rider sweep (47 rows, before = origin/master, after = patch; graphics)

The argument for the row set: every corpus row whose source names `TextFormat.prototype`, `Video.prototype` or
`PrintJob.prototype` (grep over avm1 + from_gnash `.as`/`.swfasm`), plus the brief's `globals_*`, `native_*`,
`*_prototype*`, `assetnativeaccessor_ids`, `movieclip_default_state`, `textfield_props_swf*`, every avm1 `text_format*`
/ `textfield_*_text_format*` row, the StyleSheet/edittext rows that create TextFormats, the decls rows, and gnash
`TextFormat-v5..v8` + `Video-v6..v8`. I left out gnash Function/Object/MovieClip: the patch touches no
Function/Object/MovieClip state, and the only shared code path is the MC accessor walk, which now accepts an ARRAY
`__proto__` that no other row sets on a clip. Status `-N` = positional diff lines.

| Row | Before | After |
|---|---|---|
| avm1/lazy_prototype_shared | MISMATCH −2 | **PASS** |
| avm1/video_prototype_lazy | MISMATCH −1 | **PASS** (no-graphics PASS too) |
| avm1/text_format_prototype_lazy | MISMATCH −29 | MISMATCH −19 (LCS 13 → 23) |
| avm1/global_proto_decls (ignored) | −4503 | −4512 (alignment; LCS 2337 → 2337, −17 ours-only) |
| avm1/global_instance_decls (ignored) | −767 | −749 (LCS 211 → 211) |
| avm1/global_proto_decls_delete (ignored) | −3697 | −3697 |
| avm1/globals_swf5 (ignored) | −10 | −10 |
| avm1/native_objects_swf6 (ignored) | −1 | −1 |
| avm1/video_prototype_lazy_swf6_child | −4 | −4 |
| avm1/text_format_get_text_extent_own (w1-avm1-tail's row) | −9 | −9 |
| avm1/globals_monkeypatch (NO-GO row) | −256 | −256 |
| avm1/textfield_props_swf5 | RUFFLE_MATCHED | RUFFLE_MATCHED |
| gnash TextFormat-v7, TextFormat-v8 | RUFFLE_MATCHED | RUFFLE_MATCHED |
| gnash TextFormat-v5, TextFormat-v6, Video-v6, Video-v7, Video-v8 | PASS | PASS |
| avm1 assetnativeaccessor_ids, globals_swf6/7/8, native_objects_swf7/8, native_double_construct, native_subclasses, movieclip_default_state, object_prototypes, prototype_enumerate, prototype_properties, text_format, text_format_display, text_format_font_max_length, text_format_get_text_extent_undefined_width, text_format_rounding_swf7/8, textfield_get_text_format_args, textfield_props_swf6/7/8, textfield_set_text_format_args, textfield_set_text_format_text_change, video_width_height, printjob_props_swf7, stylesheet, stylesheet_transform, edittext_default_format_empty, edittext_default_format_font_style, edittext_stylesheet | PASS | PASS |
| regression/avm1_parent_child_text | — | PASS |

**0 riders, 0 pass→ruffle_matched.** The gnash TextFormat-v5/v6 rows matter most here: the code comment that put
the 17 fields on the prototype eagerly cited their `TextFormat.prototype.hasOwnProperty` checks. They stay PASS,
because those checks run after a `new TextFormat()`.

## 5. Wave-2 patch scope (exact)

Land `w1-native-proto-prototype.patch` as is (one TU, `action.c`, all `static`). It contains:
1. `lazyProtoMarkInitialized()`, `g_tf_lazy_names[]`, `textFormatDefineLazyProps()` placed before `createBlankTextFormat`.
   Delete `g_video_lazy_protos`/`MAX_VIDEO_LAZY_PROTOS`, and have `videoDefineLazyProps` call the shared marker.
2. `initTextFormatPrototype`: drop the eager 17-field install.
3. `new TextFormat` arm and `createTextFormatFromField`: call `textFormatDefineLazyProps(prototype_obj)` before
   linking `__proto__`.
4. `actionOnVideoPlaced`: ARRAY prototype arm. MC GetMember accessor walk: ARRAY `__proto__` → `arr->props`.
Wave 2 must also:
- Strip the `PROTO(w1-native-proto)` comment tags.
- Run CI `categories=all`, graphics. The patch touches no `swf_core.c`/`tag_stubs.c`/`NO_GRAPHICS` arms;
  `actionOnVideoPlaced` is reached from both modes and `video_prototype_lazy` was checked no-graphics locally.
- Add no new regression fixture: both behaviours have upstream Ruffle-oracle rows (the two flips).
- Not mark `text_format_prototype_lazy` as yield. It is HOLD until the accessor model (§2.3 (1)) is slotted on its
  own.

## New unclaimed leads

- **Loaded-movie root `gotoAndStop`/`gotoAndPlay`** isn't routed to the child's `frame_funcs`; only stop/play are
  (action.c:25143). It's the sole cause of `video_prototype_lazy_swf6_child` (4/8). It is probably also behind other
  loadMovie rows that seek a child's own timeline. M, timeline owner.
- **TextFormat accessor model** (§2.3 (1)): L. It unlocks `text_format_prototype_lazy` together with (2) and (3) (S–M).
- **TextFormat `super()` constructor fidelity** (§2.3 (2)): the `new` path also stores `font` raw (no `toString`),
  unlike Ruffle's `set_font`. That's a possible silent divergence for `new TextFormat(obj)`. No corpus row measured.
- **`globals_swf5` doc correction** (§3): wording only.
- **Native vs As2 function-kind table** (§2): ~519 lines in ignored decls rows, 0 flips. Park it.

## LOCAL ORACLE REQUESTS

None. Every behaviour above has an upstream Flash/Ruffle expectation in the corpus.
