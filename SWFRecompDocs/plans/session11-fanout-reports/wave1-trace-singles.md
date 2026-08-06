# wave1-trace-singles — session 11

Agent: `w1-trace-singles`. HEAD `b4c983ea4`. Baseline CI run `30713776612`
at `c4496a4c8` (trace 4188/4424, pixels 217/566).

Scope: the three trace leads left on the board by session 10
(`polish-sweep-arc.md` §11.3) — `avm2/graphic_linkage`,
`from_shumway/.../PerspectiveProjectionClass`, `avm2/loader_duplicate_class`
cause C.

Disposition check (done first, per standing policy): **none** of the three
appears in `ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`,
`RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md`, or
`ruffle-tests/ignored_tests.txt`. All three are live, gradeable targets.

## Verdict table

| target | brief premise | verdict | go/no-go | predicted flips |
|---|---|---|---|---|
| `avm2/graphic_linkage` | "script-`new` vs timeline discriminator in `display_native_init`; own batch, high-traffic arm" | **REFUTED** (discriminator is the display-object *kind*, not the instantiation site; arm is not hot for this gate) | **GO** — S, low risk | +1 |
| `PerspectiveProjectionClass` | "~2 mechanisms, +1"; s10's "oracle conflict" refutation | premise **CONFIRMED & REFINED** (3 sub-mechanisms + 1 extra + 1 bonus); s10 refutation **re-CONFIRMED** | **GO** — M, ~zero blast radius | +1 |
| `loader_duplicate_class` cause C | "diagnose remaining cause C" | **PARTIAL** — clean witness found, root cause not separable read-only | **NO-GO as a single**; GO only as an A+B+C batch | 0 unless all of A+B+C land |

---

# Target 1 — `avm2/graphic_linkage`

## Verified current status at HEAD

```
python3 ruffle-tests/verify_output.py --test=graphic_linkage \
        --tests-dir=ruffle-tests/tests/swfs/avm2 --diff --verbose
```
`MISMATCH` — `output_mismatch`, gap 2, unchanged from the s10 measurement:

```
     5  constructing child:
     6  MyText constructor
     7  my shape:
-    8  0            +    8  40.35
-    9  0            +    9  40.35
```

Test shape (from the recompiled ABC,
`ruffle-tests/tests/swfs/avm2/graphic_linkage/RecompiledABC/abc0_methods.c`):

* `MyText/MyText` (method[1], :65-104) — `super()`, `trace("MyText constructor")`,
  `trace("my shape:")`, `trace(this.width)`.
* `Main/Main` (method[4], :212-268) — `super()`, `trace("Main constructor")`,
  `trace("constructing child:")`, `var t = new MyText()`, `trace(t.width)`,
  `addChild(t)`.

Line 3 (`40.35`) is the **timeline-placed** MyText and is already correct.
Lines 8 and 9 are the **script-`new`'d** instance's `this.width` and the
caller's `t.width` — Flash reads `0` for both.

## Premise REFUTED — what the discriminator actually is

The brief (and the s10 `w2-symbols-report.md` §"`graphic_linkage` — NOT taken")
frames this as a script-`new` vs timeline discriminator inside
`display_native_init`'s script-`new` arm, "the highest-traffic path in the AVM2
display layer (hundreds of tests)". That framing is wrong, and the refutation
is the yield here.

**`MyText` extends `flash.display.Shape`, not Sprite/MovieClip.** Verified from
the ABC constant pool: `abc0_classes[0]` (MyText) has super-multiname 21 =
`QName(ns[5], str[39])`, `ns[5] = {kind 22, "flash.display"}`, `str[39] =
"Shape"`. Char 22 is a `DefineShape` (it is the only row in
`avm2_generated_shape_geom`, `RecompiledABC/abc_timeline.c:19-22`).

In Ruffle the symbol-linkage lookup is **per-allocator**, not per-instantiation-
site. `class_symbol` is consulted by exactly four display allocators —
`sprite_allocator` (`core/src/avm2/globals/flash/display/sprite.rs:36`),
`simple_button_allocator` (`simple_button.rs:45`), `bitmap_allocator`
(`bitmap.rs:46`), `video_allocator` (`media/video.rs:27`). It is **not**
consulted by:

* `shape_allocator` — `core/src/avm2/globals/flash/display/shape.rs:11-18`:
  ```rust
  let display_object = Graphic::empty(activation.context).into();
  Ok(initialize_for_allocator(activation.context, display_object, class).into())
  ```
* `text_field_allocator` — `core/src/avm2/globals/flash/text/text_field.rs:17-19`,
  with the explicit comment *"Creating a TextField from AS ignores SymbolClass
  linkage."*

So `initialize_for_allocator` (`display_object.rs:33-55`) is **not** the thing
that needs a discriminator — the s10 report's reason for not taking this
(*"that arm is Ruffle's `initialize_for_allocator`, which genuinely does call
`enter_frame` + `construct_frame`, and Ruffle passes this test"*) is correct
but looked one level too low. Ruffle passes because the Shape allocator handed
`initialize_for_allocator` an **empty Graphic with no character at all**.

## Mechanism diagnosis (file:line)

`SWFModernRuntime/src/avm2/avm2_display.c`

* `display_native_init` — `:10859`.
* Script-`new` arm — `:10888-10918`, entered when `!g_timeline_instantiation`.
* The defect — `:10896-10900`:
  ```c
  uint16_t char_id = char_for_class(obj->cls);
  if (char_id != 0)
  {
      ext->char_id = char_id;
      ext->timeline = timeline_for_char(char_id);
  ```
  `char_for_class` (`:241-254`) walks the super chain against `g_symbol_map`
  and returns 22 for `MyText`.

The **timeline is not involved**: `avm2_generated_timelines` has one row
(`{0, …}`, the root's MainTimeline), so `timeline_for_char(22) == NULL` and the
`enter_frame_obj`/`construct_frame_obj` catch-up at `:10906-10907` does nothing.
The leak is `ext->char_id` alone:

* `char_self_bounds(uint16_t char_id)` — `:666`, reads `avm2_generated_chars`.
* the display-object bounds getter — `:696`, `Rect r = char_self_bounds(ext->char_id);`
* `avm2_generated_chars[] = { { 22, 0, -401, 406, -486, 477, NULL } }` →
  width `(406 - (-401)) / 20 = 807/20 = **40.35**`. Exact match for the observed
  wrong value on both lines.

`resolve_shape_geom` is *not* called from the script-`new` arm (only from the
timeline placement sites `:1747`, `:1810`, `:10231`), so the script-created
Shape already renders nothing — only the bounds leak.

## Fix sketch (one wave-2 worktree agent)

In `display_native_init`'s script-`new` arm, refuse the symbol char when the
class's concrete base is one whose Ruffle allocator ignores linkage. Scope it
to **Shape only**:

```c
uint16_t char_id = char_for_class(obj->cls);
/* Ruffle shape_allocator (shape.rs:11) builds Graphic::empty and never
   consults class_symbol: a Shape-linked class constructed from script has
   NO character, so its bounds are empty (graphic_linkage). */
if (char_id != 0 && class_is_a(obj->cls, ctx->builtins.shape_class))
        char_id = 0;
if (char_id != 0) { ... }
```

**Do NOT extend the gate to TextField.** `avm2/edit_text_linkage` encodes the
identical Flash rule for `TextField` (expected output: timeline-placed instance
reads `Testing`, script-`new`'d instance reads empty) and **passes today** —
`avm2_text_edittext_init` at `:10882-10886` already seeds default EditText state
and only timeline instantiation re-seeds from the tag. Touching that arm can
only break a green test.

Effort: S (one condition). Files: `avm2_display.c` only.

## Predicted flips

* `avm2/graphic_linkage` — **PASS** (both remaining diff lines share the one
  `ext->char_id` source). **+1.**

No other test flips (see below).

## Risk / regression surface — measured, not assumed

The "high-traffic arm" concern is quantifiable, because the gate can only fire
for a class that (a) extends `Shape` and (b) carries a SymbolClass binding.
I scanned **2368** locally-built `RecompiledABC/abc_registry.c` +
`abc_timeline.c` pairs across *all* suites for SymbolClass bindings whose
`char_id` is a shape / edittext / statictext character:

```
registries scanned: 2368
('EDITTEXT', 'avm2/edit_text_linkage',  2, 'MyText')
('SHAPE',    'avm2/graphic_linkage',   22, 'MyText')
```

Exactly two hits corpus-wide, and the Shape-only gate touches exactly one of
them — the target. Everything else binds sprite/button/bitmap chars and is
untouched.

**Canaries** (all `pass` in `results_graphics.json` @ `c4496a4c8`; any non-PASS
row is a regression):
`avm2/edit_text_linkage`, `avm2/subclass_superclass_linked_symbol`,
`avm2/movieclip_super_is_symbol`, `avm2/movieclip_symbol_constr`,
`avm2/symbol_class_conflict`, `avm2/symbol_class_root_not_zero`,
`avm2/symbol_class_binary_data`, `avm2/simplebutton_symbolclass`,
`avm2/instantiate_root_character`, `avm2/displayobject_getbounds_shape`,
`avm2/shape_drawrect`, `avm2/morph_shape`,
`avm2/bitmapdata_draw_self_via_graphic`, `from_shumway/timeline/nav/shape`,
`avm1/access_unnamed_shape`.

CI: `mode=graphics`, `categories=full` (AVM2 runtime change, standing policy).

**GO.**

---

# Target 2 — `from_shumway/avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass`

## Verified current status at HEAD

```
python3 ruffle-tests/verify_output.py \
  --test=avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass \
  --tests-dir=ruffle-tests/tests/swfs/from_shumway --diff --verbose
```
`MISMATCH` — `output_mismatch`, **exactly 4 diff lines** out of 20:

| # | expected | ours |
|---|---|---|
| 12 | `perspectiveProjection returns a clone: true` | `false` |
| 16 | `Initial root projectionCenter: (x=250, y=187.5)` | `(x=250, y=250)` |
| 19 | `changed root fieldOfView: 100` | `55` |
| 20 | `changed root focalLength: 209.7749077943` | `480.2455444336` |

This **re-confirms s10's `w2-hygiene-report.md` §3b refutation**: the
`focalLength` rows (7, 15, 18) are inside the test's own
`[approximations] max_relative = 0.0000001` tolerance and already match. There
is no oracle conflict with `avm2/perspective_projection`; the test belongs in
the live pool.

Source: `PerspectiveProjectionClass.as:53-67` (the whole diff comes from lines
53-54, 60, and 65-67).

## Mechanism diagnosis

Ruffle's model (the thing to copy):

* `flash.geom.PerspectiveProjection` is a **live view**: three slots
  `displayObject`, `fov`, `center`
  (`core/src/avm2/globals/flash/geom/PerspectiveProjection.as`).
* Every getter routes through `object_to_perspective_projection`
  (`geom/transform.rs:235-257`): **if `displayObject` is set, read the DO's
  live `base().perspective_projection()` and ignore the object's own slots.**
* Every setter does `sync_from_display_object` → set slot →
  `sync_to_display_object` (`geom/perspective_projection.rs:165-227`), i.e.
  writes land on the DisplayObject.
* `Transform.perspectiveProjection` getter (`geom/transform.rs:375-403`) mints a
  **fresh** `PerspectiveProjection` on every read and stamps its
  `displayObject` slot.
* `Transform.perspectiveProjection` setter (`transform.rs:406-424`) converts the
  argument to a plain `PerspectiveProjection` **struct** and stores it on the
  DO — the caller's object is **not** bound to anything.
* The DO holds `Option<PerspectiveProjection>` (`display_object.rs:274`), with
  two overrides: `Stage::set_perspective_projection` (`stage.rs:880-882`) does
  `get_or_insert_default()` → `(fov 55, center (250,250))`; and
  `MovieClip::set_perspective_projection` (`movie_clip.rs:2773-2784`) — for
  `is_root()` a `None` becomes
  `{ fov 55, center (movie.width()/2, movie.height()/2) }`.

Ours (`SWFModernRuntime/src/avm2/avm2_display.c:9710-9905`) stores `__fov`,
`__cx`, `__cy` **on the PP object**, with a weak `__target` back-pointer used
only by `pp_width`. Three sub-mechanisms follow:

1. **Getter identity** — `transform_get_perspective_projection` `:9861-9880`
   returns the *stored* object when `target.__pproj` is set, so
   `tr.perspectiveProjection !== tr.perspectiveProjection` is `false`.
   → **diff line 12.**
2. **Root default projectionCenter** — `pp_init` `:9752-9765` and `pp_get_center`
   `:9814-9822` hard-code `(250, 250)` for every PP. The root's default must be
   `(movie_w/2, movie_h/2)`; this test's
   `avm2_generated_stage_rect = {0, 10000, 0, 7500}` = 500×375 px →
   `(250, 187.5)`, matching expected exactly. The *stage*'s own default stays
   `(250,250)` (expected line 1, which we already match).
   → **diff line 16.**
3. **No write-through** — `pp_set_fov` `:9771-9788`, `pp_set_focal_length`
   `:9793-9812`, `pp_set_center` `:9824-9838` all write only to the transient
   object, so `projection.fieldOfView = 100` is lost when
   `root.transform.perspectiveProjection` is re-read.
   → **diff lines 19, 20.**

Two more mechanisms found while cross-checking the sibling test (needed for
model fidelity; only #4 is strictly required for a faithful port, #5 is a bonus):

4. **Assignment must not bind** — `transform_set_perspective_projection`
   `:9882-9902` stamps `__target` onto the *caller's* PP object. Ruffle does
   not. Consequence: a standalone `new PerspectiveProjection()` that was once
   assigned to a DO starts reporting the stage width instead of the constant
   500 in `pp_width` (`:9732-9742`), which is exactly
   `avm2/perspective_projection` lines 1273/1282/1314
   (expected `480.24554443359375` = width 500, ours `288.1473083496094` =
   width 300).
5. **`focalLength` rounds in the wrong order (fully verified).**
   `render/src/perspective_projection.rs:33-36`:
   ```rust
   pub fn focal_length(&self, width: f32) -> f32 {
       let rad = self.field_of_view * Self::DEG2RAD;
       (width / 2.0) * f64::tan((PI - rad) / 2.0) as f32
   }
   ```
   The `as f32` binds to the `tan` — the tangent is narrowed to f32 **first**,
   then multiplied in f32. Ours (`:9749`) narrows once, after a double
   multiply:
   ```c
   return (double) (float) ((pp_width(act, self) / 2.0) * tan((M_PI - rad) / 2.0));
   ```
   I compiled both forms and compared against **all 179** expected
   `FOV to FL <n>` values in `avm2/perspective_projection/output.txt`:
   Ruffle's order reproduces **179/179 exactly**; ours differs on 58.
   Correct form:
   ```c
   return (double) ((float)(w / 2.0f) * (float) tan((M_PI - rad) / 2.0));
   ```

## Fix sketch (one wave-2 worktree agent)

Port Ruffle's model into the self-contained `:9710-9905` block:

1. Move PP state onto the display object's ext as an
   `Option<{fov, cx, cy}>` (a `has_pproj` flag + 3 doubles), replacing the
   `__pproj` dynamic slot.
2. `transform_get_perspective_projection`: mint a fresh PP object every call
   and stamp `__target`; return null iff the DO's option is empty.
3. `transform_set_perspective_projection`: copy the argument's fov/center into
   the DO's option; do **not** stamp `__target` on the argument. Null → clear
   the option, then apply the per-kind override.
4. Per-kind override on "set/clear": stage → always `(55, 250, 250)`; root
   MovieClip → always `(55, stage_w/2, stage_h/2)` derived from
   `avm2_generated_stage_rect`; everything else → may be empty.
   This reproduces `perspective_projection_basic`'s
   "after setting stage/root to null it is still non-null" rows verbatim.
5. `pp_get_fov` / `pp_get_center` / `pp_get_focal_length` / `pp_to_matrix3d`:
   read through `__target` when present, else the object's own slots.
6. `pp_set_fov` / `pp_set_focal_length` / `pp_set_center`: write through to
   `__target` when present (keep the #2182 / #2186 throws unchanged —
   `avm2/error_geterrormessage` pins those message strings).
7. Fix the f32 rounding order in `pp_focal_length` (`:9749`).

Effort: M. ~150 lines, one contiguous region, plus 4 fields on
`Avm2DisplayObjectExt`.

## Predicted flips

* `from_shumway/.../PerspectiveProjectionClass` — **PASS**. **+1.**
* `avm2/perspective_projection` — **does NOT flip.** Goes from 75 diff pairs to
  ~14. Breakdown of its 75, measured:

  | class | pairs | fixed by this work? |
  |---|---|---|
  | `FOV to FL …` f32 rounding order | 58 | yes (all 179 verified exact) |
  | root `projectionCenter (x=150, y=100)` (stage 6000×4000 twips = 300×200) | 4 | yes (mechanism 2) |
  | fov/focalLength state not persisting + width-500 rule | 11 | yes (mechanisms 3, 4) |
  | `toMatrix3D` raw-data rows | 2 | yes (mechanism 5) |

  **Residual: 14 lines that are a number→string difference, not arithmetic.**
  For 14 of the f32 focal lengths the exact value sits on a 16-digit decimal
  midpoint — e.g. `966.67828369140625`, where Flash prints `966.6782836914063`
  (tie **away from zero**) and our formatter prints `966.6782836914062`
  (ECMAScript `Number::toString` tie-**to-even**). Full list of affected FOVs:
  29, 32, 35, 37, 52, 95, 98, 99, 107, 109, 123, 143, 147, 167. Changing the
  double→string tie-break is a corpus-wide-risky change and **must not be
  bundled** here — flag it as its own investigation. `PerspectiveProjectionClass`
  is unaffected because it prints focal lengths through `toFixed(10)`.

So the brief's "+1" is correct, and the extra ~61 recovered diff lines on
`avm2/perspective_projection` are unbanked progress, not a flip.

## Risk / regression surface

Fully enumerable: a corpus-wide grep of every `output.txt` for
`perspectiveProjection|focalLength|projectionCenter|fieldOfView` returns
**six** tests total.

**Canaries** (baseline status in parentheses):

* `avm2/perspective_projection_basic` (**pass** — the load-bearing one; it pins
  "object default null / stage+root default non-null / set-to-null makes a
  plain object null but re-mints for stage and root". The `Option<PP>`-on-the-DO
  model with the two per-kind overrides reproduces every row.)
* `avm2/error_geterrormessage` (**pass** — pins the #2182/#2186 message text.)
* `avm2/edittext_autosize_lazy_bounds_props` (**pass** — touches `Transform`
  generally; `transform_get_pixel_bounds` sits immediately below the edited
  block at `:9910`, do not disturb it.)
* `avm2/geom_transform` (already `output_mismatch` — check for new stderr /
  worsening, and for a possible partial improvement.)
* `avm2/perspective_projection` (already `output_mismatch` — expect a large
  improvement, not a flip; diff-line count is the grading signal.)

CI: `mode=graphics`, `categories=full`.

**GO.**

---

# Target 3 — `avm2/loader_duplicate_class`, cause C

## Verified current status at HEAD

`output_mismatch`. Raw diff is 49 vs 49 lines; `verify_output.py:3195-3200`
strips the leading blank from the expected side, so the graded shape is
actual 49 / expected 48. **Read the diff with `expected[n+1] ↔ actual[n]`.**

Causes A and B from `session10-fanout-reports/wave1-trace-leads.md` §"Lead 1"
are still present at HEAD; line numbers re-verified (they had drifted):

| cause | site at HEAD |
|---|---|
| A — script-`new`'d child non-root class gets no char | `avm2_display.c:10896` `char_for_class(obj->cls)`; slow arm `avm2_display_child_char_for_class` at `:296`, still no caller on the display path |
| B — child arm resolves in the ROOT domain scope | `class_for_dotted_name` `:1519-1522` (hard-wired `avm2_domain_root_scope`); `class_for_char` child loop `:1539-1550`; `nondisplay_class_for_char` child loop `:1595-1606` |

## Cause C — a clean, A/B-independent witness

The s10 report described C only as "~6 rows of pure ordering, no mechanism
identified". **Section 3 of the test ("same domain load") is a clean witness
that isolates C from A and B**, and it is observable at HEAD today.

`loader_same_domain.swf` is loaded with
`new LoaderContext(false, ApplicationDomain.currentDomain)` (`Test.as:62`), so
its `DuplicateClass` *is* reachable from the root scope — **cause B does not
bite there**, and we do construct the placed instance. Yet:

| | expected | actual |
|---|---|---|
| 29 / 28 | `loader_same_domain DuplicateClass script initializer: …` | same |
| **30** | **`loader_same_domain DuplicateClass: this.childFromSameDomain = [object MovieClip] …`** (ctor) | — |
| 31 / 29 | `Framescript loader_same_domain with DuplicateClass: …` | same |
| 32 / 30 | `loader_same_domain callMe script initializer: …` | same |
| 33 / 31 | `loader_same_domain callMe: …` | same |
| — / **32** | — | **`loader_same_domain DuplicateClass: this.childFromSameDomain = null this.childFromOtherDomain = [object MovieClip] this.childFromDomainChild = null`** (ctor) |

Both sides emit the ctor **exactly once**. Ours emits it *after* the child's
frame-1 script and its `callMe()`; Flash emits it *before*. That is cause C in
one line:

> **A Loader-loaded child movie's timeline-placed AVM2 instances are
> constructed after the child's frame-1 script instead of before it.**

The same inversion is visible in section 4 (expected 41 ctor → 42 framescript;
ours 40 framescript → 43 ctor), and once A and B land it would also govern
expected rows 5-7 and 20-21.

Two secondary symptoms, worth recording because they are probably the same
defect:

* **Wrong declared var.** Expected `childFromSameDomain = [object MovieClip]`,
  ours `childFromOtherDomain = [object MovieClip]`. Exactly one non-null on
  both sides, so the child clip *is* attached — it lands in the wrong slot of
  `loader_same_domain/DuplicateClass.as:8-10`. Consistent with the instance
  being built from the wrong movie's symbol.
* **One construction too many.** Section 4: Flash emits three
  `loader_same_domain DuplicateClass:` ctor traces (expected 41, 45, 48); we
  emit four (actual 43, 45, 47, 49).

## Where the mechanism must live

`avm2_display.c`, `loader_content_instantiate`'s catch-up legs at **`:5473-5479`**:

```c
uint8_t saved_phase = ctx->frame_phase;
if (cext->timeline != NULL && cext->playing) run_frame_internal(ctx, child, 1);
ctx->frame_phase = PHASE_CONSTRUCT;
construct_frame_obj(ctx, child);
ctx->frame_phase = PHASE_FRAME_SCRIPTS;
run_frame_scripts_obj(ctx, child);
ctx->frame_phase = saved_phase;
```

That textual order is *already* enter → construct → framescripts, so the
inversion means one of two things:

* **(a) `run_frame_internal` places nothing at `:5474`** — either the
  `cext->timeline != NULL && cext->playing` gate is false for the child root,
  or the placement lands later — so the frame-1 children only appear on the
  following tick's enter phase, are constructed then, and their ctor traces
  land after the framescript that already ran at `:5478`. **Stronger
  candidate**, because the ctor trace does eventually appear *with a child
  attached*, and because the extra 4th construction in section 4 smells like a
  second placement pass.
* **(b) `class_for_char` misses at construct time** — the child ABC's script
  initialises lazily (`avm2_globals.c:133 avm2_script_ensure_init`), and our
  actual output prints the child's script-initializer line *immediately before*
  the framescript line, i.e. at the framescript's first `getlex`, not during
  `construct_frame_obj`. If the class is not yet in scope at `:5476`,
  `class_for_char` (`:1524-1577`) falls through to the char-kind default and
  the placed object stays a plain `MovieClip`. This would also explain the
  wrong-var symptom if a later pass re-instantiates from a different movie's
  tables.

**I could not discriminate (a) from (b).** Doing so requires a printf at the
three legs plus a `class_for_char` miss log, i.e. a source edit — forbidden by
the wave-1 read-only rule. This is the honest state, not a hand-wave: the
witness above is new and solid, the two candidates are named with exact sites,
and the deciding experiment is three `fprintf(stderr, …)` lines.

## Verdict — NO-GO as a polish single

* Cause C is **masked in sections 1 and 2** by A and B, so its full row
  ownership cannot be measured until A+B land.
* Per the s10 leads report (re-confirmed): **A alone yields 0. A+B yields 0.**
  Only A+B+C flips the test. This is not a polish single; it is a loader batch.
* **Not shared with any other failing test** (s10 checked all 248 failing
  loader/domain/symbolclass/child tests).

## Recommended wave-2 scoping (if taken)

One worktree agent, three gated steps:

1. **Land A** — one line at `avm2_display.c:10896`:
   `char_for_class(obj->cls)` → `avm2_display_child_char_for_class(ctx, obj->cls)`.
   Cost is nil when `g_child_movie_count == 0`. *(Note the interaction with
   Target 1: if both land in the same worktree, apply the Shape gate to the
   result of whichever lookup is used.)*
2. **Land B** — ~25 lines: a movie→scope accessor (given
   `const Avm2MovieTables* t`, scan `ctx->files[i]` for
   `files[i]->data == t->abc_files[0]` and return `files[i]->scope`;
   `Avm2AbcFileRt.scope` is at `include/avm2/avm2_abc.h:613`,
   `Avm2MovieTables.abc_files` at `:572`), then swap
   `class_for_dotted_name` → `class_for_dotted_name_in(ctx, scope, …)`
   (`:1465`) at `:1539-1550` and `:1595-1606`.
   *Caveat (from s10, still unverified):* the section-4 re-load reuses the ABC
   file object, so `file->scope` is the **latest** domain. Expected rows 42-49
   show Flash resolving the re-loaded child's `DuplicateClass` to
   `"from loader_same_domain"`, so "use the file's current scope" may be
   accidentally right. Verify against rows 42-49, don't assume.
3. **Re-measure, then instrument** `:5473-5479` to decide (a) vs (b), and only
   then write cause C.

Grade the batch on the diff-line count after step 2 as well as after step 3 —
step 2's delta is the check that A+B behaved as the s10 report predicted.

## Canaries

All `pass` at `c4496a4c8` unless noted:
`avm2/instantiate_root_character`, `loader_events`, `loader_child_getdefinition`,
`loader_loadbytes_url`, `loader_loadbytes_events`, `loader_reuse`,
`loader_method`, `loader_error_in_root_ctor`, `loader_duplicate_coerce`,
`loader_duplicate_coerce_new_domain`, `loader_visibility_interactive`,
`loader_noninteractive_try_click_root`, `application_domain`,
`applicationdomain_getqualifieddefinitionnames`,
`applicationdomain_hasdefinition_null`, `security_domain_current`,
`stage_domain_getQualifiedDefinitionNames`, `get_definition_by_name`,
`font_enumeratefonts_order`, `regression/avm2_loader_stub`,
`away3d_advanced_shallow_water_demo` (0/0 silence assertion — flips on any new
stderr line).

Already-failing neighbours to watch for *worsening / new stderr*:
`avm2/loader_load`, `loader_applicationDomain`, `loader_try_click_root`,
`mouse_pick_loader_avm1`, `appdomain_lookup_edge_cases`.

CI: `mode=graphics`, `categories=full`.

---

# Cross-target notes for the coordinator

* Targets 1 and 2 are independent of each other and of target 3, but **all
  three edit `SWFModernRuntime/src/avm2/avm2_display.c`**. Regions:
  PP `:9710-9905`; Shape gate `:10888-10902`; loader A/B `:1519-1606`,
  `:5473-5479`, `:10896`. Targets 1 and 3 both touch `:10896` — if split
  across agents, they must be merged in a known order or given to one agent.
* Recommended wave-2 packaging: **one agent takes Targets 1 + 2** (both S/M,
  both near-zero blast radius, combined predicted **+2**). Target 3 is a
  separate, larger batch and should only be started if there is budget for the
  full A+B+C arc; it yields 0 otherwise.
* No disposition-doc updates are needed for any of the three. The
  `avm2/perspective_projection` number→string tie-break residual (14 lines) is
  a *candidate* for `ACCEPTED_DIFFS.md` only if a future session decides the
  formatter must not change — not yet, since it is a real divergence with a
  known cause.
