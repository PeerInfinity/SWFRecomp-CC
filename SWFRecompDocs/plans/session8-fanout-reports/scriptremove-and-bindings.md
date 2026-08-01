# Session 8 · wave 1 diagnosis — `transformed_by_script` gate + root-class binding riders

Baseline: HEAD `1c7c23761`. Graded baseline = `_results/results_graphics.json`
(`git_sha 375373786`, the session-7 closeout — postdates all session-7 patches).
avm2: total 1224, pass 1068, ruffle_matched 27, effective 1095, fail 129
(output_mismatch 128, runtime_error 1).

Read-only session. No repo file was modified. Two tests run locally
(`issue_8630_placeremoveplace_scriptremove`, `from_shumway/timeline/nav/matrix`).

**Verdict: A = GO (+1, tight blast radius, ~15 lines). B = NO-GO for both
follow-ups — zero corpus tests are blocked on either; scoping note only.**

---

# TARGET A — `transformed_by_script` gate

## A.0 Status re-verified at HEAD

| test | baseline | local re-run at HEAD |
|---|---|---|
| `avm2/issue_8630_placeremoveplace` | pass 15/15 | (not re-run; baseline pass, session-7 fix landed) |
| `avm2/issue_8630_placeremoveplace_scriptremove` | output_mismatch 15/16 | **confirmed** `MISMATCH`, one row |

Local diff, verbatim:

```
    13  false
    14  true
    15  2.75
-   16  0
+   16  2.75
```

Session 7's "one line of `_scriptremove`" claim is **accurate and current**.
Cause A (per-depth `QueuedTagList`) is shipped; rows 7-8 are green in both tests.

`output.txt` (16 lines) — rows 15/16 are the two clips re-read after
`gotoAndStop(2); gotoAndStop(1)`:

* row 15 = depth 1's clip. Script did `removeChild(this.child)` before the goto,
  so it does **not** survive the rewind → `instantiate_child` mints a fresh
  object → placement-3 matrix → `2.75`. Already correct.
* row 16 = depth 2's clip (`child2`). It survives the rewind
  (`survives_rewind`, `avm2_display.c:2453+`), the script wrote `child2.x = 0`
  before the goto, and Flash/Ruffle keep the script value → `0`. We stomp it
  back to placement-4's `2.75`.

The non-`_scriptremove` sibling never reaches this path: its single
`gotoAndStop(1)` hits `mc_goto_frame`'s same-frame short-circuit, so only
`_scriptremove` (which goes to 2 first, making frame 1 a real rewind) exposes it.

## A.1 Ruffle oracle — every SET and every READ site

`grep -rn transformed_by_script ~/CC/ruffle/core/src` — complete inventory.

### Flag storage

* `core/src/display_object.rs:2959` — `DisplayObjectFlags::TRANSFORMED_BY_SCRIPT = 1 << 3`
* getter `:779` / setter `:783` on `DisplayObjectBase`, re-exported on the
  `TDisplayObject` trait at `:2181` / `:2188`.
* **Never cleared.** Every call in the tree passes `true`. A fresh object starts
  clear; the flag is sticky for the object's whole life.

### READ sites — exactly ONE

* `core/src/display_object.rs:2516`, inside `TDisplayObject::apply_place_object`:

```rust
fn apply_place_object(self, context, place_object: &swf::PlaceObject) {
    // PlaceObject tags only apply if this object has not been dynamically moved by AS code.
    if !self.transformed_by_script() {
        matrix / color_transform / ratio / is_bitmap_cached / blend_mode
        / (swf_version >= 11: visible, background_color) / filters
    }
    // Purposely omitted: name, clip_depth, clip_actions
}
```

The gate wraps the **whole body**. All five callers
(`movie_clip.rs:1521` instantiate_child, `:1819`/`:1823` goto Modify/Replace,
`:4447`/`:4453` streaming Replace/Modify) inherit it — there is no second,
un-gated apply path.

### SET sites — 14 total; 10 are AVM2-reachable

| # | Ruffle site | what | AVM2? |
|---|---|---|---|
| 1 | `display_object.rs:452` `DisplayObjectBase::set_x` | `.x` | yes |
| 2 | `:465` `set_y` | `.y` | yes |
| 3 | `:511` `set_rotation` | `.rotation` | yes |
| 4 | `:553` `set_scale_x` | `.scaleX` (+ `.width` via `TDisplayObject::set_width`) | yes |
| 5 | `:588` `set_scale_y` | `.scaleY` (+ `.height`) | yes |
| 6 | `:645` `set_alpha` | `.alpha` | yes |
| 7 | `avm2/globals/flash/geom/transform.rs:50` | `Transform.colorTransform =` | **yes** |
| 8 | `avm2/globals/flash/geom/transform.rs:87` | `Transform.matrix =` | **yes** |
| 9 | `display_object/edit_text.rs:2651` `EditText::set_width` | TextField `.width` (bounds, not scale) | **yes** |
| 10 | `display_object/edit_text.rs:2667` `EditText::set_height` | TextField `.height` | **yes** |
| 11 | `display_object/container.rs:1038` | the **displaced** `prev_child` in `replace_at_depth` | yes (shared) |
| 12-14 | `avm1/globals/{color.rs:133,:196, transform.rs:116,:143, movie_clip.rs:1389,:1681}` | AVM1 only | no |

Session 7's brief said "exactly six setters". That is right for
`DisplayObjectBase`, but **wrong as a port list** — it misses #7-#11, which are
five more AVM2-reachable sites.

### Two traps, both confirmed by reading the source

* **`DisplayObject.transform = ...` must NOT set the flag.**
  `avm2/globals/flash/display/display_object.rs:810 set_transform` writes
  `base.set_matrix` / `base.set_color_transform` **directly** and never touches
  the flag — only the *`Transform` object's own* `matrix=`/`colorTransform=`
  setters (#7/#8) do. Our `do_set_transform` (`avm2_display.c:9881`) is the
  mirror of the un-flagged one. **Do not add it there.**
* **`set_matrix` itself is not a set site.** `visible`, `filters`, `mask`,
  `blendMode`, `cacheAsBitmap`, `scrollRect`, `z`/`scaleZ` are all NOT set
  sites in Ruffle. Widening the condition is the classic over-fit; don't.

## A.2 Our runtime — the map (line numbers at HEAD `1c7c23761`)

Session-7's report has stale line numbers (its patches shifted the file);
these are current.

**We already have this flag on the AVM1 side.** Session 7 claimed
`grep transformed_by_script SWFModernRuntime/ → nothing` — that is **false**.
`SWFModernRuntime/include/libswf/swf.h:204` declares
`u8 transformed_by_script` on the AVM1 `DisplayObject`, ~14 read sites live in
`src/libswf/tag.c` (`:7577`, `:7757`, `:7849`, `:8093`, `:8586`, `:8771`,
`:9099`, cleared at `:9722`), and `src/actionmodern/action.c:74`
`markTransformedByScript()` is the setter helper. AVM1 also carries a companion
`cx_overridden` flag so a colour-transform write and a matrix write gate
separately. **The AVM2 half is the only one missing** — treat the AVM1 code as
the in-house precedent, not as code to share (different structs, different
display list).

| # | Ruffle | ours (`SWFModernRuntime/src/avm2/avm2_display.c`) |
|---|---|---|
| READ | `display_object.rs:2516` | `apply_place_object` **:1640** (body :1642-1688) |
| 1 | `set_x` | `do_set_x` **:3574** |
| 2 | `set_y` | `do_set_y` **:3603** |
| 3 | `set_rotation` | `set_rotation_internal` **:521** (only caller of the writes) |
| 4 | `set_scale_x` | `set_scale_x_internal` **:535** |
| 5 | `set_scale_y` | `set_scale_y_internal` **:546** |
| 6 | `set_alpha` | `do_set_alpha` **:3997** |
| 7 | `Transform.colorTransform=` | `transform_set_color_transform` **:9571** |
| 8 | `Transform.matrix=` | `transform_set_matrix` **:9393** |
| 9/10 | `EditText::set_width/height` | `set_width_height` **:3924**, the `ext->edittext != NULL` early-return arm (:3929-3936) |
| 11 | `container.rs:1038` displaced child | `replace_at_depth` **:898** |

Field to add: `uint8_t transformed_by_script;` in `Avm2DisplayObjectExt`
(`SWFModernRuntime/include/avm2/avm2_globals.h:433-606`). The struct is
zero-initialised at alloc, so no init change is needed.

**Why the three `*_internal` helpers, not the four `do_set_*` natives:**
`set_{rotation,scale_x,scale_y}_internal` have exactly four callers —
`do_set_rotation` (:3894), `do_set_scale_x` (:3851), `do_set_scale_y` (:3869),
and `set_width_height` (:3975-3976). No timeline/tag code calls them. Putting
the flag in the internals reproduces Ruffle exactly, including
`width`/`height` → `set_scale_*` → flag (`TDisplayObject::set_width` in Ruffle
calls `self.set_scale_x`, which is set site #4). Verified: the timeline path
writes `ext->mtx_*` through `apply_place_matrix` (:1588), a separate function.

## A.3 Fix plan

**Patch 1 — the field.** `avm2_globals.h`, in `Avm2DisplayObjectExt`, next to
the other `uint8_t` flags:

```c
// Ruffle DisplayObjectFlags::TRANSFORMED_BY_SCRIPT. Sticky, never cleared:
// once AS writes a transform attribute, timeline PlaceObject tags stop
// applying to this object (apply_place_object).
uint8_t transformed_by_script;
```

**Patch 2 — the gate.** `avm2_display.c:1640`, wrap the body:

```c
static void apply_place_object(Avm2Context* ctx, Avm2Object* child,
                               const Avm2TimelineOp* op)
{
	Avm2DisplayObjectExt* ext = avm2_display_ext_of(ctx, child);
	if (ext == NULL) return;
	// Ruffle display_object.rs:2514 — "PlaceObject tags only apply if this
	// object has not been dynamically moved by AS code."
	if (ext->transformed_by_script) return;
	... unchanged body ...
}
```

Early-return is equivalent to Ruffle's `if !flag { ... }` because the body has
no side effects outside the gate (verified: `name` / `clip_depth` are applied by
`instantiate_child` at :1730-1739, **outside** `apply_place_object`, exactly as
Ruffle's "purposely omitted" comment says). No caller needs an exemption:
`instantiate_child`'s call (:1727) is against a just-allocated object whose
flag is clear.

**Patch 3 — the ten set sites.** One line each, ideally via a tiny helper
`static inline void mark_tbs(Avm2DisplayObjectExt* e) { if (e) e->transformed_by_script = 1; }`:

1. `do_set_x` :3574 — after the `mtx_tx` write (inside the `ext != NULL && argc > 0` guard)
2. `do_set_y` :3603 — likewise
3. `set_rotation_internal` :521 — first line (Ruffle sets it *before*
   `cache_scale_rotation`, and before the NaN early-return at :527, so a NaN
   rotation still marks — match that)
4. `set_scale_x_internal` :535 — first line
5. `set_scale_y_internal` :546 — first line
6. `do_set_alpha` :3997 — inside the guard
7. `transform_set_color_transform` :9571 — after the `ext` null-check
8. `transform_set_matrix` :9393 — after the `ext` null-check
9/10. `set_width_height` :3924 — in the `ext->edittext != NULL` arm, before the
   `return` (the non-EditText arm is already covered transitively via 4/5)

**Patch 4 (OPTIONAL — recommend deferring one CI cycle).** Ruffle
`container.rs:1038` marks the **displaced** child in `replace_at_depth`. Our
`replace_at_depth` (:898) has three callers: `instantiate_child` (:1716, the
timeline one Ruffle matches), `avm2_display_build_stage` (:3554, no prev), and
:10218 (a re-parent walk). Adding `pext->transformed_by_script = 1` where `prev`
is non-NULL is the faithful port, but it is not needed by `_scriptremove` and it
widens the change into `place_object_replace*`. Ship patches 1-3, measure, then
add 4 as a separate parity item.

Total for patches 1-3: **~15 lines across 2 files, runtime-only** — no
recompiler change, so no `SWFRecomp/build` rebuild is needed for canaries.

## A.4 Predicted yield

**+1**: `avm2/issue_8630_placeremoveplace_scriptremove` `output_mismatch → pass`
(15/16 → 16/16).

Confidence: high. Row 16 is the only failing row, the surviving-child rewind
path is the only code that touches it, and `apply_place_object` is the only
writer of `mtx_tx` on that path. **Not measured** — this agent is read-only and
did not build a patched tree; the implementer should confirm before CI.

No second test is predicted. Nothing else in the corpus is one
`transformed_by_script` row away (see A.5 — the entire affected population is
17 tests, and the 8 already-failing ones each have unrelated multi-row diffs).

## A.5 Blast radius — measured, not estimated

The gate only bites where BOTH are true: (i) script writes a transform
attribute on a display object, and (ii) the timeline later re-applies a
placement to that same object (a Modify/Replace tag, or a goto rewind).

Method: for every test with a `RecompiledABC/` (1118 of 1201 in avm2, plus
from_shumway / timeline / visual / regression / swf / mixed_avm / import_assets
/ text / avm1 / stage3d / fonts / audio / from_avmplus), parse
`RecompiledABC/abc_timeline.c` op rows (`{ kind, flags, ... }`, kind 0 =
PLACE, `flags & 1` = `AVM2_TLF_HAS_CHAR`, so kind 0 without bit 0 = a **Modify**
op) and count per-timeline frame counts from the `_starts[]` tables; intersect
with tests whose ABC string pool (`RecompiledABC/*_tables.c`) contains any of
`x y alpha rotation scaleX scaleY width height transform colorTransform matrix`.

**Whole-corpus population: 17 tests.**

| test | baseline | modify ops | max frames |
|---|---|---|---|
| `from_shumway/acid/acid-morph` | output_mismatch | 85 | 30 |
| `avm2/filter_rewind` | **pass** | 4 | 4 |
| `avm2/bounds_mode` | output_mismatch | 3 | 5 |
| `from_shumway/timeline/nav/matrix` | **pass** | 2 | 3 |
| `from_shumway/timeline/nav/colorTransform` | **pass** | 2 | 3 |
| `avm2/place_object_replace_2` | **pass** | 1 | 4 |
| `from_shumway/as3-loader/events/loader-events` | output_mismatch | 1 | 4 |
| `avm2/loaderinfo_properties` | **pass** | 1 | 2 |
| `fonts/embed_matching/fallback_preferences` | **pass** | 1 | 2 |
| `avm2/displayobject_height` | **pass** | 0 | 7 |
| `avm2/displayobject_width` | **pass** | 0 | 7 |
| `avm2/issue_8630_placeremoveplace_scriptremove` | output_mismatch | 0 | 3 |
| `avm2/issue_8630_placeremoveplace` | **pass** | 0 | 3 |
| `avm2/instantiation_on_enterframe_gotoandstop` | **pass** | 0 | 3 |
| `avm2/instantiation_on_enter_frame` | **pass** | 0 | 3 |
| `avm2/displayobject_colortransform_nested` | **pass** | 0 | 2 |
| `avm2/displayobject_set_matrix_nested` | **pass** | 0 | 2 |

Nine `pass` rows are the at-risk set. Note the scan reads the **main** movie's
timeline table only; a child SWF's tables live in its own directory, so the
loader tests below are added by hand.

Named behaviour changes to expect:

* **A morph's `ratio` freezes once the script touches the clip's transform.**
  `ratio` is inside Ruffle's gate. `acid-morph` (85 modify ops, already failing)
  is the one place this shows; watch whether its line count moves either way.
* **Filters stop being re-applied / cleared on rewind for script-moved clips.**
  `filter_rewind` is the canary. Note our body has an extra arm Ruffle lacks
  (`else if ((op->flags & AVM2_TLF_MOVE) == 0) → clear filters`, :1683-1687);
  it sits inside the gated region, which is the right side of the line.
* **`visible` from PlaceObject3 stops applying** to script-moved clips. Ours
  applies `HAS_VISIBLE` with no `swf_version >= 11` gate (Ruffle has one) — a
  pre-existing divergence, unchanged by this patch, but it interacts here.
* AVM1 is untouched: `apply_place_object` is `static` in `avm2_display.c`, and
  the AVM1 flag/gates in `libswf/tag.c` are a separate implementation.

Risk grade: **medium-low, and materially lower than session 7 estimated**
("medium-high, wants a full-avm2 + from_shumway canary"). The measured
population is 17 tests, not "every AVM2 timeline test", because the gate is a
no-op for any object whose script never wrote a transform.

## A.6 Canaries

Invocation confirmed working for nested names:
`python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_shumway --test=timeline/nav/matrix --diff --verbose`
→ `PASS [r=0.05s c=32.76s x=0.02s]` at HEAD (run this session).

**Tier 1 — must run (the 9 passing tests in the measured population):**

```
from_shumway   timeline/nav/matrix              <- timeline re-asserts a matrix over a script one
from_shumway   timeline/nav/colorTransform      <- same, cxform half
avm2           filter_rewind                    <- filters + rewind, highest-value
avm2           place_object_replace_2
avm2           loaderinfo_properties
avm2           displayobject_width
avm2           displayobject_height
avm2           instantiation_on_enter_frame
avm2           instantiation_on_enterframe_gotoandstop
avm2           displayobject_colortransform_nested
avm2           displayobject_set_matrix_nested
avm2           issue_8630_placeremoveplace      <- the sibling; MUST stay 15/15
fonts          embed_matching/fallback_preferences
```

**Tier 2 — setter-side (exercise the 10 write sites; the flag itself must be
inert for them):**

```
avm2  displayobject_x  displayobject_y  displayobject_alpha  nan_scale
avm2  displayobject_invalid_floats  displayobject_transform(*)  blend_transform(*)
avm2  edittext_width_height  edittext_autosize  edittext_align
avm2  flash_media_video_setter   <- session-7 Fixed16 rider shares set_scale_*_internal
```
`(*)` `displayobject_transform` is baseline `output_mismatch`, `blend_transform`
is `ruffle_matched` — run them for the diff shape, not for a pass/fail flip.

**Tier 3 — timeline/goto/place-remove regression net (session-7's list, all
baseline pass):**

```
avm2          place_object_same_depth_frame  place_object_replace  place_multiple
avm2          movieclip_goto_overwrite  goto_methods  remove_dobj
avm2          movieclip_displayevents_timeline
avm2          displayobjectcontainer_timelineinstance
avm2          displayobjectcontainer_removechild_timelinemanip_remove1
from_shumway  timeline/Timeline3  timeline/Timeline4  timeline/Timeline8
from_shumway  timeline/Timeline9  timeline/timeline_loop
```

**Tier 4 — `regression` suite (mandatory per `local-regression-sweep-stash-diff`):**

```
regression  avm2_goto_catchup_scale  avm2_timeline_solid  avm2_timeline_gradients
regression  avm2_timeline_stroke_gradient  avm2_timeline_text  avm2_morph
regression  avm2_simplebutton_click  avm2_static_text
```

**Silence assertion to protect:** `avm2/away3d_advanced_shallow_water_demo`
passes with 0 expected / 0 actual lines. It uses timeline content; if the gate
makes anything throw, it prints and flips. Include it.

CI dispatch after landing: `mode=graphics`, `categories=all` (the change is
AVM2 display runtime, not recompiler emission or AVM2 verifier), `images=false`.

---

# TARGET B — root-class binding riders follow-up

## B.0 What session 7 actually shipped

`impl-riders.md` rider 4 (landed, `avm2/instantiate_root_character` pass):
in `loader_boot_child_swf` (`avm2_display.c:5313+`), once a child SWF's **root**
class resolves and clears the #2023 Sprite gate, register
`root_cls → char_id_base + 0` into `g_symbol_map` via the new
`symbol_map_add()` (:230), with the map's capacity grown by
`AVM2_MAX_CHILD_MOVIES` (:3486-3488). Mirrors Ruffle
`movie_clip.rs` preload_symbol_class `None =>` arm.

Explicitly deferred, verbatim from the report:

1. **main-movie root binding self-registration** — "our `build_stage` skips
   `char_id == 0` and the main root binding is id 0 in nearly every corpus SWF;
   mapping `Test → char 0` would make `new Test()` instantiate the main timeline
   across the whole avmplus suite."
2. **child NON-root symbol bindings** — "timeline placement resolves those
   through the separate `class_for_char` child-movie path, so only the
   script-`new` direction is affected."

Both re-verified as still-unshipped at HEAD: `symbol_map_add` still hard-returns
on `char_id == 0` (:231), and `avm2_display_build_stage` still `continue`s on
`char_id == 0` (:3492).

## B.1 Follow-up 1 (main-movie root binding): ZERO tests blocked

Searched every non-passing test across avm2 / from_shumway / from_avmplus /
avm1 / timeline / swf / mixed_avm / import_assets / visual (346 rows) for
symbol-class / root-binding symptoms:

* content-grep of test dirs for `getDefinition` / `SymbolClass` /
  `applicationDomain` → 14 hits;
* structural diff scan for expected `[object <CustomClass>]` / `#1065 not
  defined` rows absent from actual → 17 hits;
* AS-source grep for `new <X>()` where `X` comes from a domain lookup, and for
  `new root` / `new (…).constructor` → **zero** hits anywhere in the corpus.

None of the 14+17 needs the main movie's root class to be a character:

| test | real cause |
|---|---|
| `avm2/loader_applicationDomain`, `avm2/swz` | `.swz` (Flex RSL) load via `URLLoader` + `Loader.loadBytes` never completes — 0 lines out. Their `getDefinitionByName("Test")` is an ordinary **class-name** lookup in the application domain, not a character binding. |
| `avm2/delayed_symbolclass` | lazy script-init **ordering** for multi-frame SymbolClass tags |
| `avm2/doabc_and_symbolclass_script_init_goto` | script-init timing across a goto |
| `avm2/appdomain_lookup_edge_cases`, `describe_type_json`, `verify_method_info_duplicate` | `Vector.<>` name parsing / `describeTypeJSON` / VerifyError #1121 |
| `avm2/all_classes/display/*`, `mixed_avm/*`, `from_shumway/.../loaded-content-properties` | class-surface enumeration, `AVM1Movie`, LoaderInfo property errors |

**Deliverable is the scoping note, per the brief.** Recommendation: **do not
build it.** The riders report's regression argument holds and this diagnosis
adds a second one — `avm2_display_build_stage` prints the #2023 error for every
`Test` class that does not extend Sprite, which is *all 177* from_avmplus e4x /
as3 / Vector tests whose expected output ends with that line. Registering
`Test → char 0` would give `new Test()` a root timeline in exactly the suite
where the class is deliberately NOT a Sprite. Zero upside, 177 tests of
downside. **NO-GO.**

## B.2 Follow-up 2 (child non-root bindings): ONE test partially blocked, it will not flip

The single corpus test that script-`new`s a non-root symbol class of a loaded
child SWF is **`avm2/loader_duplicate_class`** (`output_mismatch`, 23/48).

Mechanism confirmed. `display_native_init` (`avm2_display.c:10767`) resolves a
script-created display object's symbol with the **fast arm**:

```c
uint16_t char_id = char_for_class(obj->cls);
```

`char_for_class` (:241) scans only `g_symbol_map`, which holds the main movie's
bindings plus (since rider 4) child **root** bindings. A child's non-root class
is absent → `char_id == 0` → no timeline → childless clip. In the test,
`new duplicateClassObj()` (Test.as `doSameDomainLoad` / `doChildDomainLoadAgain`)
therefore produces:

```
E: this.childFromDomainChild = [object MovieClip]     A: this.childFromDomainChild = null
E: Child name: [object MovieClip]                     A: RangeError: Error #2006 …
                                                         at flash.display::DisplayObjectContainer/getChildAt()
                                                         at DuplicateClass()
```

The slow arm **already exists and already does the right lookup**:
`avm2_display_child_char_for_class` (:296) falls back to `char_for_class`, then
walks the class's super chain, maps each ancestor's ABC file to its owning movie
via `avm2_display_movie_for_abc` (:335), and matches by qualified name against
that movie's `symbol_classes` table, skipping `char_id == 0`. Child char ids are
already offset by `char_id_base` at emission, so the id it returns feeds
`timeline_for_char` (:347) directly. It disambiguates the test's three distinct
`DuplicateClass` classes correctly, because it keys off the movie that *defines*
each class. It just has no caller on the display path — today only
`avm2_text.c:7767`/`:7912` (fonts) use it.

**Fix sketch (3 lines, runtime-only):**

```c
/* avm2_display.c:10767, inside the !g_timeline_instantiation arm */
- uint16_t char_id = char_for_class(obj->cls);
+ uint16_t char_id = avm2_display_child_char_for_class(ctx, obj->cls);
```

Cost is nil when no child movie is loaded (`g_child_movie_count == 0` makes
`avm2_display_movie_for_abc` return NULL immediately, and builtin ancestors
short-circuit on `instance_init.file == NULL`); gate on
`g_child_movie_count > 0` if you want it explicit. Behaviour changes only for
script-created objects whose class belongs to a loaded child SWF and is NOT
already in `g_symbol_map` — a set of exactly one test.

**Predicted yield: 0 tests.** `loader_duplicate_class` needs at least three
independent fixes and this is one of them:

1. **(this one)** script-`new`'d child non-root class gets no timeline
   → 2 rows + a spurious `RangeError #2006` (3 more rows).
2. **`class_for_char`'s child arm resolves in the WRONG scope.** :1513-1525
   loops child movies' `symbol_classes` but calls `class_for_dotted_name(ctx, …)`,
   which is hard-wired to `avm2_domain_root_scope` (:1493). A child loaded into
   a *fresh* ApplicationDomain has its classes outside the root scope, so the
   lookup fails and the placed character falls through to the char-kind default
   (plain `MovieClip`) — which is why the child SWF's own **timeline-placed**
   `DuplicateClass` never runs its constructor either (expected rows 5-6, 20,
   30 absent). This contradicts rider 4's assumption that "timeline placement
   resolves those through the separate `class_for_char` child-movie path". The
   ingredients for the fix exist (`class_for_dotted_name_in(ctx, scope, …)` at
   :1465; `Avm2AbcFileRt.scope` at `avm2_abc.h:613`), but a movie→scope
   accessor has to be added.
3. **Frame-script ordering across the load** — after realigning for the missing
   leading blank line, roughly 6 further rows are pure ordering
   (`callMe` script-init vs framescript vs `Init` event), plus a
   `TypeError #1034` at expected row 22 (coercing a plain MovieClip to
   `DuplicateClass` — a downstream symptom of cause 2).

**GO/NO-GO: NO-GO as yield work.** Take the one-line change only as a
correctness rider bundled with something else, or as step 1 of a dedicated
`loader_duplicate_class` arc that also takes cause 2 (which is the bigger and
more interesting one, and is a genuine new finding from this session).

## B.3 Regression guard — `away3d_advanced_shallow_water_demo`

Baseline **pass**, `actual_lines: 0 / expected_lines: 0` — a **silence
assertion**. It passes via cross-patch synergy from session 7 (per §9, most
plausibly rider 4's child root-class binding, since Flex `BitmapAsset` is a
child-SWF character class). Neither change proposed here touches
`loader_boot_child_swf` or `symbol_map_add`, so it should be unaffected — but
because a silence assertion flips on any new stderr/stdout line, it must be in
the canary set for **both** targets. If it flips, the expected next error is the
embedded Flex `BitmapAsset` chain (polish-sweep-arc §9.2).

Canaries if follow-up 2 is ever taken (all baseline pass):
`avm2/instantiate_root_character`, `loader_events`, `loader_child_getdefinition`,
`loader_loadbytes_url`, `loader_reuse`, `loaderinfo_root`,
`loader_error_in_root_ctor`, `loader_loadbytes_events`, `loader_duplicate_coerce`,
`away3d_advanced_shallow_water_demo`, `font_enumeratefonts_order`,
`get_definition_by_name`, plus `regression/avm2_loader_stub`.

---

# Corrections to propagate into `polish-sweep-arc.md`

* §9.2 "`_scriptremove` final line (`transformed_by_script`, **six setters**,
  wide blast radius)" → **ten** AVM2-reachable set sites (the six
  `DisplayObjectBase` ones plus `Transform.matrix=`, `Transform.colorTransform=`,
  `EditText::set_width`, `EditText::set_height`), one read site, plus an
  optional eleventh (`replace_at_depth`'s displaced child). Blast radius is
  **17 tests corpus-wide, 9 of them passing** — measured, not "wide".
* `e4x-and-misc-singles.md` §4 cause B claims
  `grep transformed_by_script SWFModernRuntime/ → nothing`. **False** — the
  AVM1 half is fully implemented (`libswf/swf.h:204`, ~14 sites in
  `libswf/tag.c`, `action.c:74 markTransformedByScript`). Only AVM2 lacks it.
* §9.2 "main-movie root-class binding + child non-root bindings (riders
  follow-up)" → **no corpus test is blocked on either**; the child non-root
  half is a 1-line change worth 0 tests, and the main-movie half should be
  marked WON'T-DO (177 from_avmplus tests of downside).
* New finding to file: `class_for_char`'s child-movie arm
  (`avm2_display.c:1513`) resolves child symbol classes in the **root** domain
  scope, so a child loaded into a fresh ApplicationDomain gets plain
  `MovieClip`s for all of its non-root characters. This is the larger half of
  `loader_duplicate_class` and was previously believed to work.
