# w2-display-singles — session 11 wave 2

Agent: `w2-display-singles`. Worktree base `b4c983ea4`.
Spec: `session11-fanout-reports/wave1-trace-singles.md`, targets **1 and 2 only**
(target 3 `loader_duplicate_class` was dispositioned NO-GO and was not touched).

Baselines read from the main tree's `_results/results_graphics.json` (CI run
`30713776612` @ `c4496a4c8`) — every row below was re-read, not assumed.

Patch: `w2-display-singles.patch` (one file, `SWFModernRuntime/src/avm2/avm2_display.c`).

## Result

| target | before | after | delta |
|---|---|---|---|
| `avm2/graphic_linkage` | `output_mismatch` | **PASS** | **+1** |
| `from_shumway/avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | `output_mismatch` | **PASS** | **+1** |

**Predicted +2, delivered +2. Zero regressions across 20 canaries.**
Bonus, unbanked: `avm2/perspective_projection` goes from **75 to 14** differing
lines (and `avm2/geom_transform` from 54 to 53) without flipping.

Build is warning-clean (`avm2_display.c` produces no new gcc diagnostics).

---

## Target 1 — `avm2/graphic_linkage` (S)

### What shipped

One gate in `display_native_init`'s script-`new` arm (`avm2_display.c`, was
`:10896-10901`):

```c
uint16_t char_id = char_for_class(obj->cls);
if (char_id != 0 && ctx->builtins.shape_class != NULL
    && class_is_a(obj->cls, ctx->builtins.shape_class))
{
        char_id = 0;
}
if (char_id != 0) { ext->char_id = char_id; ext->timeline = timeline_for_char(char_id); }
```

Confirms the wave-1 refutation: symbol linkage in Ruffle is consulted
**per-allocator**, and `shape_allocator` (`display/shape.rs:11-18`) builds a bare
`Graphic::empty` that never looks at `class_symbol`. So a Shape-linked class
constructed from script has **no character at all**, and its bounds are empty
rather than the DefineShape's `(406-(-401))/20 = 40.35`. Timeline placement is
untouched — it runs through the `g_timeline_instantiation` arm, which is why
line 3 of the test (`40.35` for the placed instance) stayed correct throughout.

### Scoping decisions

* **Shape only.** `MorphShape` is registered as a direct child of
  `DisplayObject` (`avm2_display.c` `avm2_builtin_class(ctx, "flash.display", "MorphShape", dobj)`),
  **not** of `Shape`, so `class_is_a(cls, shape_class)` cannot reach it. Verified
  before writing the gate; `avm2/morph_shape` is in the canary set as the check.
* **Not extended to TextField**, per the spec. `text_field_allocator` ignores
  linkage too, but `avm2_text_edittext_init` (called ~14 lines above) already
  encodes that rule and `avm2/edit_text_linkage` passes today. A comment in the
  source says so, to stop a future reader "completing" the gate.
* `ctx->builtins.shape_class != NULL` guard added because `display_native_init`
  is installed as a `native_init` hook during builtin class construction, i.e.
  it can in principle run before `b->shape_class` is assigned.

### Blast radius — re-checked, not inherited

The wave-1 scan (2368 `abc_registry.c`/`abc_timeline.c` pairs, exactly two
shape/edittext/statictext SymbolClass bindings corpus-wide) is the reason this
is a one-condition change. Both hits were canaried: the EDITTEXT one
(`edit_text_linkage`) and the SHAPE one (`graphic_linkage`, the target).

---

## Target 2 — `PerspectiveProjectionClass` (M)

### What shipped

The self-contained `:9721-9905` block was ported to Ruffle's actual model. All
five wave-1 mechanisms landed; every source reference was re-verified against
`~/CC/ruffle` rather than taken on trust from the report.

1. **PP state moved onto the DisplayObject.** Ruffle holds
   `Cell<Option<PerspectiveProjection>>` on `DisplayObjectBase`
   (`display_object.rs:274`); the AS object is only a view. Implemented as four
   `dont_enum` dynamic slots on the display object — `__pphas` (0/1) plus
   `__ppfov`/`__ppcx`/`__ppcy` — replacing the old `__pproj` object reference.
   New helpers: `do_pp_default`, `do_pp_set`, `do_pp_get`.
   *Why dynamic slots and not `Avm2DisplayObjectExt` fields:* the ext is
   allocated for **every** display object, and PP is touched by six tests
   corpus-wide. Four cold dynamic slots cost nothing for the other ~100% of
   objects and keep the change inside one file (no header churn for the
   siblings also editing `avm2_display.c`).
2. **Root default centre.** `movie_clip.rs:2773-2784` — a root handed `None`
   re-mints `{fov 55, center (movie.width()/2, movie.height()/2)}`. With this
   test's `avm2_generated_stage_rect = {0, 10000, 0, 7500}` that is
   `(250, 187.5)`, matching expected line 16 exactly. The **stage**'s own
   default stays the flat `(250, 250)` (`stage.rs:880-882`
   `get_or_insert_default()`) — expected line 1, already green, still green.
3. **Getter mints a fresh clone.** `transform.rs:375-403` constructs a new
   `PerspectiveProjection` on every read and stamps its `displayObject` slot, so
   `tr.perspectiveProjection !== tr.perspectiveProjection` is `true`
   (expected line 12). Returns null iff the DO's option is empty.
4. **Setter write-through, and assignment does not bind.**
   `transform.rs:406-424` reduces the argument to a plain `{fov, center}` struct
   via `object_to_perspective_projection` and stores *that* — the caller's object
   is never bound to the DO. New `pp_read`/`pp_write` mirror Ruffle's
   `object_to_perspective_projection` (`transform.rs:235-257`) and
   `sync_from_display_object → set slot → sync_to_display_object`
   (`perspective_projection.rs:165-227`), including two details that are easy to
   miss:
   * once an object carries a `displayObject`, its **own** fov/centre slots are
     ignored entirely, and an *empty* DO option reads as the hard default
     `(55, 250, 250)` (`unwrap_or_default()`), not as the object's slots;
   * `sync_to_display_object` **bails when the DO's option is empty**, so writing
     through a stale view of a nulled object is a no-op on the DO.

   Together these produce expected lines 19-20 (`fieldOfView = 100` surviving a
   re-read of `root.transform.perspectiveProjection`).
5. **`focalLength` f32 rounding order (bonus).**
   `render/src/perspective_projection.rs:33-36` is
   `(width / 2.0) * f64::tan((PI - rad) / 2.0) as f32` — `as` binds tighter than
   `*`, so the **tangent** narrows to f32 first and the multiply then runs
   entirely in f32 (`width` is an `f32` parameter). Ours narrowed only the
   finished f64 product. Now:
   ```c
   float w = (float) pp_width(act, self);
   return (double) ((w / 2.0f) * (float) tan((M_PI - rad) / 2.0));
   ```
   Not gradeable on `PerspectiveProjectionClass` itself (its `[approximations]
   max_relative = 0.0000001` covers both forms, and it prints through
   `toFixed(10)`); it is banked for `avm2/perspective_projection`, which prints
   raw.

`pp_width` was rewritten onto the shared `pp_target` helper but its behaviour is
unchanged (`get_width`, `perspective_projection.rs:13-27`: no DO → 500, stage →
500, other DO → stage width). The `#2182` / `#2186` throws and their exact
message strings are untouched, and both still fire before any state is read —
matching Ruffle's ordering and keeping `avm2/error_geterrormessage` pinned.

### Deliberately NOT bundled

The number→string tie-break change. Per the spec, the residual lines on
`avm2/perspective_projection` are a `Number::toString` tie-to-even vs
tie-away-from-zero difference at 16-digit decimal midpoints, and changing the
formatter is corpus-wide risky. Untouched here.

`avm2/perspective_projection` was **not expected to flip** and did not — see the
canary table for its measured post-change state.

### Implementation note for a future reader

`do_pp_default` derives the root's centre from `avm2_generated_stage_rect`, i.e.
the **main** movie's rect. Ruffle uses `self.movie()`, which for a
Loader-loaded child root would be the child's own dimensions. No test in the
corpus exercises `transform.perspectiveProjection` on a loaded child's root
(the corpus-wide grep for
`perspectiveProjection|focalLength|projectionCenter|fieldOfView` returns six
tests, none of them loader tests), so this is a knowingly-deferred fidelity gap,
not an oversight.

---

## Canary ledger

Baseline column = `results_graphics.json` @ `c4496a4c8`; "after" = this
worktree, default no-graphics mode, each run individually with `--recompile`.

**20/20 canaries clean. Zero regressions.** All 18 baseline-`pass` canaries are
still `pass`; the 2 baseline-`output_mismatch` neighbours both *improved* and
neither gained a new stderr line.

### Target 1 canaries (symbol linkage / shape bounds)

| test | suite | baseline | after |
|---|---|---|---|
| `edit_text_linkage` | avm2 | pass | **PASS** |
| `subclass_superclass_linked_symbol` | avm2 | pass | **PASS** |
| `movieclip_super_is_symbol` | avm2 | pass | **PASS** |
| `movieclip_symbol_constr` | avm2 | pass | **PASS** |
| `symbol_class_conflict` | avm2 | pass | **PASS** |
| `symbol_class_root_not_zero` | avm2 | pass | **PASS** |
| `symbol_class_binary_data` | avm2 | pass | **PASS** |
| `simplebutton_symbolclass` | avm2 | pass | **PASS** |
| `instantiate_root_character` | avm2 | pass | **PASS** |
| `displayobject_getbounds_shape` | avm2 | pass | **PASS** |
| `shape_drawrect` | avm2 | pass | **PASS** |
| `morph_shape` | avm2 | pass | **PASS** |
| `bitmapdata_draw_self_via_graphic` | avm2 | pass | **PASS** |
| `timeline/nav/shape` | from_shumway | pass | **PASS** |
| `access_unnamed_shape` | avm1 | pass | **PASS** |

`edit_text_linkage` is the load-bearing one (the other of the two
shape/edittext SymbolClass bindings that exist corpus-wide) — unchanged, as
required. `morph_shape` confirms the `class_is_a(cls, shape_class)` gate does
not reach MorphShape.

### Target 2 canaries (PerspectiveProjection / Transform)

| test | baseline | after | note |
|---|---|---|---|
| `perspective_projection_basic` | pass | **PASS** | the load-bearing one: pins object-null / stage+root-non-null / set-to-null re-mints for stage+root but nulls a plain object. The `Option`-on-the-DO model with the two per-kind overrides reproduces every row. |
| `error_geterrormessage` | pass | **PASS** | #2182 / #2186 message strings untouched |
| `edittext_autosize_lazy_bounds_props` | pass | **PASS** | `transform_get_pixel_bounds` (immediately below the edited block) undisturbed |
| `geom_transform` | output_mismatch | output_mismatch (**improved**) | 54 → 53 differing lines. Expected line 3 `t.perspectiveProjection === t.perspectiveProjection false` now matches (was `true`: we used to hand back the *stored* object). The remaining failure is an unrelated `matrix3D`/`rawData` `#1009` that aborts `test2D()` — **identical `error_signature` to baseline**, no new stderr. |
| `perspective_projection` | output_mismatch | output_mismatch (**large improvement**) | **75 → 14 differing lines** out of 1443. |

#### `avm2/perspective_projection` residual — measured, matches the wave-1 prediction exactly

The 14 remaining lines are **all** `FOV to FL` rows, and they are exactly the 14
FOVs wave 1 predicted would survive: **29, 32, 35, 37, 52, 95, 98, 99, 107,
109, 123, 143, 147, 167**. Nothing else differs — every `projectionCenter`,
`fieldOfView`, `focalLength`-persistence, width-500 and `toMatrix3D` row that
was wrong is now right.

Each residual is a one-ULP-of-decimal-text difference at a 16-digit midpoint,
e.g.
```
-  48  FOV to FL 29 966.6782836914063     (Flash: tie away from zero)
+  48  FOV to FL 29 966.6782836914062     (ours: ECMAScript tie-to-even)
```
This is the double→string tie-break, **deliberately not bundled** per the spec.
It is now cleanly isolated: it is the *only* thing left on this test, which
makes it a well-specified follow-up target rather than a vague residue.

---

## Files touched

* `SWFModernRuntime/src/avm2/avm2_display.c` — **only file**.
  * Target 1: the script-`new` arm of `display_native_init` (~`:10896`), +9 lines.
  * Target 2: the `flash.geom.PerspectiveProjection` block (~`:9721-9905`).

No header changes, no recompiler changes, no disposition-doc changes (none of
the fixed lines is an accepted diff; both targets were verified absent from
`ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md` and `ignored_tests.txt` in wave 1).

## Merge risks

Several wave-2 siblings also edit `avm2_display.c`. Both of my edits are tight
and sit in the two regions the spec flagged:

1. **`:10896`, the script-`new` arm.** The wave-1 report warns that
   `loader_duplicate_class` **cause A** would edit *this same line*
   (`char_for_class(obj->cls)` → `avm2_display_child_char_for_class(ctx, obj->cls)`).
   That target was dispositioned NO-GO for this session, so no conflict should
   exist — but if any agent lands it later, the Shape gate must be applied to
   the result of **whichever** lookup ends up being used. The gate is written as
   a separate `if` on the `char_id` variable precisely so it survives that
   substitution mechanically.
2. **`:9721-9905`, the PP block.** Fully self-contained.
   `transform_get_pixel_bounds` sits immediately below it and was **not**
   touched (the spec called it out). Everything the block exports is `static`
   and new-named (`do_pp_default`, `do_pp_set`, `do_pp_get`, `pp_target`,
   `pp_read`, `pp_write`) — no collision risk.
3. The old `__pproj` dynamic slot is **gone**; nothing else in the tree
   referenced it (grepped `SWFModernRuntime/` and `SWFRecomp/src/` before
   removing).

Merge order does not matter between my two edits and any sibling that stays out
of those two regions.

## CI recommendation

`mode=graphics`, `categories=full` (AVM2 runtime change, standing policy).
