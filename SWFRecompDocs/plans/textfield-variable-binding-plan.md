# SWFRecomp TextField Variable Binding — Flash-Parity Plan

**Document Version:** 1.1

**Created:** 2026-05-13

**Status:** All three phases complete (2026-05-13):

- **Phase A** — `fda90c99` `textfield: render orphan EditTexts via display-list walk`
- **Phase B** — `a05dfc7c` `textfield: eager wrapper + binding retry at placement`
- **Phase C** — `b20ee462` `textfield: per-container binding registry + notify`

CI green across default and graphics modes (run 25834420066 + 25834425552).
No regressions; no new pass-count delta (expected — the change is qualitative:
the dejagnu trace TextField in `place_object_test` and siblings now renders
on canvas; binding propagation is now O(B) registry lookup instead of
O(child_mc_count) scan).

Driven by `from_gnash/misc-ming.all/place_object_test` investigation
(RUFFLE_MATCHED on output, image was off because the dejagnu `_xtrace_win`
trace text never rendered).

---

## Table of contents

1. [Executive summary](#executive-summary)
2. [Symptom that motivated this plan](#symptom-that-motivated-this-plan)
3. [Reference behavior — Flash / Ruffle](#reference-behavior--flash--ruffle)
4. [Current state — SWFRecomp](#current-state--swfrecomp)
5. [Gap analysis](#gap-analysis)
6. [Phase A — Render parity (display-list-driven TF rendering)](#phase-a--render-parity-display-list-driven-tf-rendering)
7. [Phase B — Eager TF wrapper at placement](#phase-b--eager-tf-wrapper-at-placement)
8. [Phase C — Explicit binding registry + propagation](#phase-c--explicit-binding-registry--propagation)
9. [Test strategy](#test-strategy)
10. [Risk register](#risk-register)
11. [Open questions](#open-questions)

---

## Executive summary

Our DefineEditText rendering is gated on the per-EditText MovieClip
wrapper existing in `child_mc_cache`. We create that wrapper **lazily**,
only when ActionScript path resolution touches the TextField (e.g.
`mc.textfield.text`). For TextFields that are *only* observed via their
bound variable — the canonical case being the gnash dejagnu `_xtrace_win`
trace TextField bound to `_root._trace_text` — no AS path ever touches
the field, the wrapper never gets created, the renderer's
`actionIterateTextFieldGlyphs` walk skips it, and nothing draws.

Flash/Ruffle do not have this gap. Every PlaceObject2 instantiates a
real DisplayObject at placement, including DefineEditText. TextField
rendering is per-DisplayObject, not per-AVM1-wrapper. Variable binding
is set up at placement (`try_bind_text_field_variable(set_initial_value
= true)`) and bidirectional via an explicit binding registry on the
container DisplayObject (`avm1_text_field_bindings`).

This plan brings us to Flash parity in three phases:

- **Phase A — Render parity.** Walk the display list directly for
  TextField rendering. Read the bound variable's value at render time
  for fields without an MC wrapper. Smallest possible delta; no AS-
  visible side effects; unblocks `_xtrace_win` and every other
  variable-bound-but-script-untouched TextField.
- **Phase B — Eager wrapper at placement.** Eagerly create the MC for
  every placed TextField in `ng_on_place_object2`. Move variable-
  binding init out of `findOrCreateMovieClip` into a dedicated
  `tryBindTextFieldVariable()` mirroring Ruffle's
  `try_bind_text_field_variable`. Add `unbound_text_fields` list +
  per-frame retry. Eliminates the lazy-creation invariant for
  TextFields and matches Flash's observable AS surface.
- **Phase C — Explicit binding registry.** Replace the current
  "scan child_mc_cache on every setMember" sync with an explicit
  `avm1_text_field_bindings` list on each container DisplayObject,
  populated by Phase B's binding step. On UNLOAD, drain bindings
  back to the unbound list (Flash semantics for clip removal).

Phase A is sufficient to count `place_object_test` and similar dejagnu
tests as visually matched. Phases B and C bring the AS-observable
behavior into Flash parity (matters for tests that read TextField
properties from script, observe construction-time behavior, or rely on
binding survival across removal/replacement).

---

## Symptom that motivated this plan

`from_gnash/misc-ming.all/place_object_test`:

- Trace: subset of Ruffle's diffs → RUFFLE_MATCHED (effective pass)
- Image: 25317 outliers. `output.expected.png` shows the dejagnu
  trace text at the top of the canvas. Our `output.actual.png` shows
  only the test's red/black squares — no text at all.

Same pattern affects most `from_gnash/misc-ming.all/*` and
`from_gnash/misc-swfc.all/*` tests built with `get_dejagnu_clip(...)`.
The dejagnu TextField is bound to `_root._trace_text` and updated by
`xtrace(msg) { _root._trace_text = _root._trace_text + msg + "\n"; }`.
Scripts never touch the `_xtrace_win` instance, so under our lazy MC
model the textfield wrapper never exists, and rendering never fires.

Confirmed by instrumenting `actionIterateTextFieldGlyphs`:
`child_mc_count = 2` (the dejagnu container sprite "instance1" and
"mc1"), neither has `ng_textfield_idx >= 0`. The `_xtrace_win`
DisplayObject is in the sprite's `display_list` but has no MC.

---

## Reference behavior — Flash / Ruffle

Source: `ruffle/core/src/display_object/edit_text.rs`,
`ruffle/core/src/display_object.rs`,
`ruffle/core/src/avm1/object/stage_object.rs`,
`ruffle/core/src/display_object/movie_clip.rs::instantiate_child`.

### Lifecycle

1. **PlaceObject2 → instantiate_child** (`movie_clip.rs:1410`).
   `library.instantiate_by_id` constructs the DisplayObject for the
   character regardless of type. `child.post_instantiation(...)` runs
   immediately. For EditText, `post_instantiation` calls
   `construct_as_avm1_object`.

2. **construct_as_avm1_object** (`edit_text.rs:2159`).
   - Allocates the AVM1 wrapper (`Avm1Object::new_with_native`).
   - Calls `self.try_bind_text_field_variable(activation,
     set_initial_value = true)`.
   - If binding fails (parent path not yet reachable),
     `activation.context.unbound_text_fields.push(self)`.
   - Then calls `Avm1TextFieldBinding::bind_variables(activation)` to
     retry every other unbound TextField — the newly-placed object
     might be what they were waiting on.

3. **try_bind_text_field_variable**
   (`edit_text.rs:1385`).
   - Reads `self.variable()` (`Option<AvmString>`). None → return true
     (nothing to bind).
   - Walks up `avm1_parent()`, skipping buttons, to find the binding
     parent.
   - `activation.resolve_variable_path(parent, &variable_path)`
     → `Option<(Object, property_name)>`.
   - If `set_initial_value`:
     - If `object.has_property(property)` → `set_html_text(object.get(property))`
       on the TextField.
     - Else if TF.text non-empty → `object.set(property, TF.text)`.
   - If the resolved `object` has a backing DisplayObject:
     - `self.set_bound_display_object(Some(dobj))`
     - `Avm1TextFieldBinding { text_field: self, variable_name:
       property }.register_binding(dobj)` — pushes onto `dobj.avm1_text_field_bindings`.
   - Return success.

4. **bind_variables** (`display_object.rs:3024`).
   - Iterates `context.unbound_text_fields`, retries
     `try_bind_text_field_variable(set_initial_value = false)`,
     `swap_remove` those that bound.
   - Called from:
     - End of `EditText::construct_as_avm1_object` (covers new placement).
     - End of `MovieClip::run_frame_avm1` (covers every frame tick).

5. **notify_property_change** (`stage_object.rs:63`).
   - On every `Object::set` on a StageObject:
     - Walk `dobj.avm1_text_field_bindings()`.
     - For each binding whose `variable_name == property_name`
       (case-insensitive for SWF<=6), `tf.set_html_text(value.coerce_to_string())`.

6. **propagate_text_binding** (`edit_text.rs:1468`).
   - On every TF text mutation (`text_input`, `replace_text`, IME,
     drag delete, set_text, …):
     - Re-resolve `variable_path` against current parent,
       `object.set(property, html_text)`. Re-entry guarded by
       `FIRING_VARIABLE_BINDING` flag.

7. **unregister_bindings** (`display_object.rs:3060`).
   - On DisplayObject removal:
     - For each binding on `dobj.avm1_text_field_bindings`:
       - `binding.text_field.clear_bound_display_object()`
       - `unbound_text_fields.push(binding.text_field)`
     - Empty the list.

### Key data structures

- `EditText.variable: Option<AvmString>` — the path the user / SWF
  tag specified.
- `EditText.bound_display_object: Option<DisplayObject>` — current
  bind target (None when unbound, parent doesn't exist, etc.).
- `DisplayObject.avm1_text_field_bindings: Vec<Avm1TextFieldBinding>` —
  per-DisplayObject registry. Owned by the *container* whose property
  is bound — not by the TF.
- Global `unbound_text_fields: Vec<EditText>` — retry queue.

### Important semantics

- **Idempotency.** `bind_variables` runs every frame. Bound TFs are
  removed from the unbound list. Re-running on already-bound TFs is
  a no-op.
- **Initial-value direction.** Only the *first* successful bind
  (`set_initial_value = true`) does the initial copy. Variable wins
  if it exists; TF text wins if variable doesn't exist and TF text
  is non-empty.
- **HTML vs plain text.** Variable changes flow as `set_html_text`,
  not `set_text`. HTML tags in the variable become rendered formatting.
- **Case sensitivity.** SWF<=6 uses `eq_ignore_case`; SWF7+ exact.
- **Removal semantics.** When the *container* DO is removed (not the
  TF), bindings go back to the unbound list — they'll re-bind if/when
  a new container appears at the same path.

---

## Current state — SWFRecomp

Refs: `SWFModernRuntime/src/libswf/tag.c`,
`SWFModernRuntime/src/libswf/tag_stubs.c::ng_on_place_object2`,
`SWFModernRuntime/src/actionmodern/action.c`.

- **Placement record.** `display_list[depth]` carries the
  `char_id`, `instance_name`, `transform_id`, etc. Always populated
  on `tagPlaceObject2`.
- **MovieClip wrapper.** Lazily created by `findOrCreateMovieClip`
  (action.c:18806) when AS path resolution looks up a child by name.
  Sprites currently get an eager pre-create in `tagPlaceObject2`
  (tag.c:5244 + 5673) so `g_current_context` is set correctly during
  the sprite's frame-0 eager init. **Text fields do not.**
- **TextField property pre-population.** `findOrCreateMovieClip`
  initializes `mc->dynamic_props` with all the TF properties (text,
  htmlText, variable, autoSize, etc.) when it lands on a TF depth
  (action.c:~19087-19470). This is the equivalent of Ruffle's
  `construct_as_avm1_object` but only runs on first AS access.
- **Variable initialization at placement.** `ng_on_place_object2`
  (`tag_stubs.c:712`) calls `actionInitTextFieldVariable(var_name,
  init_text)` (action.c:20882) which:
  - For a path variable (dots), resolves the container via
    `actionGetVariable`, sets the property if not already present.
  - For a simple variable, calls `setVariableByName(var_name,
    init_text)` which routes to `setGlobalVariableByName` (global
    `var_map`).
- **TextField rendering.** Two-pass:
  - `actionIterateTextFields` (action.c:22746) — borders/backgrounds.
  - `actionIterateTextFieldGlyphs` (action.c:23094) — glyphs.
  - Both walk `child_mc_cache` and require `MC_IS_TEXTFIELD(mc) &&
    mc->dynamic_props != NULL`. The static-glyph path through
    `CHAR_TYPE_TEXT` is explicitly *skipped* for EditTexts
    (`tag.c:1491,1554`) on the assumption the dynamic path will pick
    them up.
- **Variable → TextField sync.** `ng_syncVarToTextFields`
  (action.c:22438) called from:
  - `actionSetMember` MOVIECLIP root branch (action.c:43725),
  - `actionSetVariable` (37203, 37543, 36826),
  - several other write sites.

  Walks `child_mc_cache`, finds MCs whose `variable` prop matches the
  written var name, sets their `text` prop.
- **Path-binding sync.** Inline loop in `actionSetMember` MOVIECLIP
  branch (action.c:~43731-43789) walks `child_mc_cache` for TFs with
  bound paths and updates `text` when the write resolves to the
  binding's container/property.
- **Text → variable sync.** `ng_syncTextToVar` (action.c:22539) called
  from input/IME/drag/setText paths.

---

## Gap analysis

| Behavior | Flash/Ruffle | SWFRecomp | Effect |
|---|---|---|---|
| TF rendered when placed but never script-touched | Yes (DO renders unconditionally) | No (no MC ⇒ skipped) | `_xtrace_win` not drawn |
| Initial text-from-variable copy | At placement (eager) | At first AS access (lazy) | TF visually shows stale init_text until first access |
| Initial variable-from-text copy | At placement (eager) | At first AS access (lazy) | Variable may stay undefined until access |
| Variable change → TF text | Direct, via per-DO binding registry | Walk `child_mc_cache` on every setMember | Misses TFs without MC; also O(N) per write |
| TF text change → variable | `propagate_text_binding`, re-resolves path each time | `ng_syncTextToVar`, eager resolve at write | Mostly matches |
| TF placed before container path exists | `unbound_text_fields` retry | No retry path | Probably broken for placed-before-init cases |
| Container DO removed → bindings | Bindings → unbound list, TF survives | Bindings just disappear (cache walk fails) | Likely OK transiently, fails on container re-creation |
| Case-insensitive var match SWF<=6 | Yes | Yes (`strcasecmp` in `ng_syncVarToTextFields`) | Match |

Phase A closes row 1 only. Phases B + C close the rest.

---

## Phase A — Render parity (display-list-driven TF rendering)

**Goal:** every placed DefineEditText renders at the correct position
with the correct text, whether or not its MC wrapper exists.

**Scope:** rendering only. No change to AS observability. No change to
MC lifecycle. No new data structures.

### Changes

1. **Add a display-list walk for TextFields.** New static helpers in
   `tag.c`:
   - `render_textfield_at_dl_entry(SWFAppContext*, DisplayObject*
     parent_obj_or_null, DisplayObject* dl, size_t d)` — emits border /
     background (via existing `textfield_render_cb` shape) and glyph
     runs (via existing `textfield_glyph_render_cb`).
   - `render_textfields_in_display_list(SWFAppContext*, DisplayObject*
     dl, size_t dl_max)` — recursive walk; for each entry whose
     `char_id` has `ng_find_textfield(...) >= 0`, render it; otherwise
     if it's a sprite, recurse into `obj->sprite_display_list`.

2. **At render time, resolve text content from the bound variable**
   when the TF has no MC wrapper. Refactor
   `actionIterateTextFieldGlyphs` so it accepts an alternative
   "synthesized info" path for DL-driven render. Concretely, split it
   into:
   - `prepare_textfield_glyph_info_from_mc(mc, info_out, runs_out)`
     — current code path (uses `mc->dynamic_props`).
   - `prepare_textfield_glyph_info_from_dl(dl_depth, tf_idx,
     info_out, runs_out)` — reads the static initial text from
     `ng_getTextFieldInitialTextByIdx`, then if there's a bound
     variable, resolves the variable's current value via the same
     dot-path walk that `findOrCreateMovieClip`'s var-init block uses
     (`actionGetVariable` + property lookup), and overrides text if
     resolved.
   - Common back-half does the layout + glyph emission.

3. **Wire the renderer.** In `tagShowFrame`'s render block, after
   the existing `actionIterateTextFields(textfield_render_cb, NULL)`
   and `actionIterateTextFieldGlyphs(textfield_glyph_render_cb,
   NULL)`, run the new DL walk **only for TF depths whose MC isn't in
   `child_mc_cache`**. Track which DL depths the MC-walk already
   handled (set of `mc->ng_textfield_idx`s) and skip those in the DL
   walk to avoid double-render.

4. **Static glyph skip still applies.** The existing
   `if (ng_getCharTextfieldIdx(obj->char_id) >= 0) break;` in the
   `CHAR_TYPE_TEXT` render path stays. We do not want pre-baked
   initial-text glyphs to render unclipped.

### Acceptance criteria

- `place_object_test` `output.actual.png` shows the trace text (still
  RUFFLE_MATCHED on text content because our depth handling matches
  Ruffle).
- No regressions on the 17 graphics-passing `avm1/edittext_*` and
  `avm1/textfield_*` tests.
- No regressions on `from_gnash/misc-ming.all/DefineEditTextTest`,
  `DefineEditTextVariableNameTest`, `TextFieldHTMLTest`.

### Out of scope

- AS observability of placed TFs (still lazy MC).
- Eager initial-value copy in either direction.
- `unbound_text_fields` retry.

---

## Phase B — Eager TF wrapper at placement

**Goal:** every placed DefineEditText has an MC in `child_mc_cache`
immediately after `tagPlaceObject2`, with `dynamic_props` populated and
variable binding set up. Match Flash's "every DisplayObject is real
from placement" semantics.

**Scope:** MC lifecycle + binding init. Render path from Phase A
becomes a no-op for these (their MCs cover them via the existing walk).

### Changes

1. **Carve binding logic out of `findOrCreateMovieClip`.** Move the
   variable-init block (action.c:19007-19056) and the path-init block
   (action.c:~19299-19358 inside the "depth != SIZE_MAX" cluster) into
   a new public function:
   ```
   void actionTryBindTextFieldVariable(SWFAppContext* app_context,
       MovieClip* tf_mc, int set_initial_value);
   ```
   Mirrors Ruffle's `try_bind_text_field_variable`. Idempotent:
   re-running on an already-bound TF re-resolves but doesn't
   double-init.

2. **Eager wrapper in `ng_on_place_object2`.** Right after
   `actionInitTextFieldVariable` (tag_stubs.c:715-718) — or in a new
   sibling call at `tag.c:5252` (the slot the rolled-back patch
   prototyped) — call:
   ```
   MovieClip* tf_mc = actionFindOrCreateMovieClip(app_context,
       display_list[depth].instance_name,
       g_current_context ? g_current_context : &root_movieclip);
   actionTryBindTextFieldVariable(app_context, tf_mc, /*set_initial_value=*/1);
   ```
   `findOrCreateMovieClip` continues to handle property
   pre-population (text, color, autoSize, etc.). The variable-init
   block inside it becomes a guarded no-op (gated on a "binding
   already attempted at placement" flag) so Phase A coexists with
   Phase B without double-initializing.

3. **Drop `actionInitTextFieldVariable` in favor of the new path.**
   `actionInitTextFieldVariable` predates this plan; it sets the
   variable but doesn't register the binding or copy text→variable
   correctly for the simple-name case. Replace with
   `actionTryBindTextFieldVariable`'s set-initial-value-side.

4. **`unbound_text_fields` retry queue.** New global in
   `action.c`:
   ```
   #define UNBOUND_TF_MAX 256
   static MovieClip* g_unbound_textfields[UNBOUND_TF_MAX];
   static int g_unbound_textfield_count;
   ```
   When `actionTryBindTextFieldVariable` can't resolve the parent
   path (e.g. `_root.mc.x` and `mc` isn't placed yet), push onto the
   queue. New public function `actionRetryUnboundTextFields()` walks
   the queue, retries with `set_initial_value=0`, removes the bound
   ones.

5. **Per-tick retry.** Call `actionRetryUnboundTextFields()` from
   `swf_core.c` / `swf.c` after each tick's frame-script drain.
   Mirrors Ruffle's call from `MovieClip::run_frame_avm1`.

### Regression risk + the order-sensitivity that bit the prototype

The drive-by prototype (eager `actionFindOrCreateMovieClip` for TF
depths, no other changes) regressed
`DefineEditTextVariableNameTest`. Root cause: the simple-name init
block at `action.c:19007` was being entered too early — before mc7's
state was fully populated for that frame — causing
`mc7.dynamic_props.text_var7` to land in a way that diverged from the
post-script state at check time. Phase B fixes this by:

- Carving binding logic into its own function with explicit
  `set_initial_value` semantics (same as Ruffle).
- Making the inside-`findOrCreateMovieClip` path a guarded fallback
  for cases where Phase B's eager bind couldn't run (e.g. dynamic
  `createTextField` paths) — not a parallel implementation.
- Running the eager bind *after* the parent MC's first frame
  populates its scope, mirroring Ruffle's ordering
  (`construct_as_avm1_object` runs inside `run_frame_avm1`'s
  post-construct phase).

### Acceptance criteria

- Phase A's render path becomes a no-op (every TF has an MC by the
  time we render).
- `DefineEditTextVariableNameTest` still passes (no regression).
- Three TF observability tests gain: `typeof(mc.textfield)` returns
  `'object'` immediately after placement, not `undefined` until first
  access.
- `_root._trace_text` variable propagates through the explicit binding
  set up at placement, not through the cache-scan in Phase A.

---

## Phase C — Explicit binding registry + propagation

**Goal:** Replace the per-write `child_mc_cache` scan in
`ng_syncVarToTextFields` and the path-binding loop in `actionSetMember`
with an explicit `avm1_text_field_bindings` registry on each container.

**Scope:** sync paths only. Visible behavior unchanged for already-
correctly-bound cases; correctness improvement for replaced /
re-created container cases.

### Changes

1. **Per-MovieClip binding list.** New field on `MovieClip`:
   ```
   TextFieldBindingEntry* avm1_text_field_bindings;
   size_t avm1_text_field_binding_count;
   ```
   Each entry: `{ MovieClip* tf_mc; const char* variable_name; }`.

2. **Phase B's bind step registers here.** After successful
   `actionTryBindTextFieldVariable`, append `{ tf_mc, last_property }`
   onto the *container* MC's binding list (or onto root's if the
   variable was a simple name resolving to global scope).

3. **Property writes call `actionNotifyPropertyChange`.** Replace the
   `ng_syncVarToTextFields` + inline path-binding loop in
   `actionSetMember` with:
   ```
   void actionNotifyPropertyChange(SWFAppContext* app_context,
       MovieClip* dobj, const char* property_name,
       u32 property_name_len, ActionVar* value);
   ```
   Walks `dobj->avm1_text_field_bindings`, matches case-aware by SWF
   version, calls `setProperty(tf_mc->dynamic_props, "text", ...)` and
   handles HTML / length sync.

4. **UNLOAD → unbind.** In the existing `tagRemoveObject2` path
   (where we currently set `pending_removal`), drain
   `mc->avm1_text_field_bindings` back to the unbound queue so they
   re-bind if/when a new container appears at the same path.

5. **Container re-creation re-binds.** When `findOrCreateMovieClip`
   creates a fresh MC at a name that was previously bound, the
   per-tick `actionRetryUnboundTextFields` walk picks it up
   automatically.

### Acceptance criteria

- `ng_syncVarToTextFields`'s entire `for (i = 0; i < child_mc_count;
  i++)` walk is removed in favor of the registry.
- Variable updates O(bindings on container) instead of O(all MCs).
- Tests that exercise replace-container-then-set-variable patterns
  (e.g. `attachMovie` over an existing TF parent) match Ruffle.
- `clip_event_propagation_order`, `selection_handlers`, and the
  whole misc-ming.all loop battery stay green.

---

## Test strategy

Per-phase, run the **per-test** runner only (CI handles full
sweeps). Mandatory smoke set:

- **Render parity (Phase A):**
  - `from_gnash/misc-ming.all/place_object_test` (driver)
  - `from_gnash/misc-ming.all/GradientFillTest`,
    `shape_test`, `Video-EmbedSquareTest` (all share dejagnu)
  - `avm1/edittext_autosize`, `edittext_bullet`,
    `edittext_html_align_swf8`, `edittext_font_size`,
    `textfield_test` (any test currently green that touches an
    EditText) — must remain green.

- **AS-observability (Phase B):**
  - `from_gnash/misc-ming.all/DefineEditTextTest`
  - `from_gnash/misc-ming.all/DefineEditTextVariableNameTest`
    (canary that the drive-by approach broke)
  - `from_gnash/misc-ming.all/TextFieldHTMLTest`
  - `avm1/asfunction`, `click_block`, `default_names`,
    `tab_ordering_events`, `selection_handlers`
  - `avm1/edittext_var_*` (any test that asserts on TF properties
    immediately after placement)

- **Binding registry + sync (Phase C):**
  - `from_gnash/misc-ming.all/key_event_test`, `loop_test*`
  - `avm1/clip_event_propagation_order`, `removed_clip_halts_script`
  - `avm1/attachmovie*`, `clone_sprite_edittext`,
    `register_class*` (TF replacement semantics)

### Regression-check protocol

After each phase lands, run the per-phase smoke set, then sweep an
additional 20-test mixed battery covering: action_order, goto,
sprite-init, register_class, clip_event clusters. CI runs the full
suite — locally we only sample.

### CI-only validation

Full-suite numbers come from the `ruffle-tests.yml` workflow dispatch
in `--mode=graphics` and the default mode. Phase A only changes
graphics-mode rendering; the default mode (`NO_GRAPHICS`) numbers are
unchanged.

---

## Risk register

| # | Risk | Phase | Mitigation |
|---|---|---|---|
| 1 | Render walk double-emits glyphs (DL walk + MC walk both fire) | A | Track set of `ng_textfield_idx`s already handled by MC walk; skip in DL walk |
| 2 | Bound-variable resolution at render time leaks toString side effects | A | Use raw `getProperty` + dot-walk, no coercion; only stringify the final value |
| 3 | Bound TFs inside nested sprites' display lists missed | A | DL walk is recursive into `obj->sprite_display_list` |
| 4 | Phase B re-runs binding mid-frame and corrupts in-progress state | B | Gate retry on tick boundary, not per-script. Match Ruffle's `run_frame_avm1` end placement |
| 5 | Eager MC creation increases `child_mc_count` and slows MC name lookups | B | `findOrCreateMovieClip` is already O(N) cached-name; one extra MC per TF placement |
| 6 | Phase C registry leaks bindings on MC free | C | Drain `avm1_text_field_bindings` in `freeMovieClip`/`releaseObject` |
| 7 | UNLOAD + immediate replace at same depth re-binds to wrong TF | C | Phase B's `actionRetryUnboundTextFields` matches by *path*, not pointer; whichever MC currently owns the path wins |
| 8 | Phase B regresses `DefineEditTextVariableNameTest` like the drive-by | B | Phase B's `actionTryBindTextFieldVariable` consolidates the two existing init blocks into one — order-deterministic. Must verify before landing |

---

## Open questions

- **OQ-1.** Do AS3 / AVM2 EditTexts use the same binding mechanism?
  Ruffle separates `construct_as_avm2_object` — but every AS2-only
  test in this codebase ignores AS3. Defer until first AS3 EditText
  test surfaces.

- **OQ-2.** How does Flash handle `mcl_loadclip` of a SWF containing
  TextFields with bound variables that resolve to the loading parent's
  scope? Probably the same `unbound_text_fields` retry — but
  `mcl_load_timing.md` notes our two-tick deferral could interact.

- **OQ-3.** `propagate_text_binding` re-resolves the variable path
  every time the TF text changes (e.g. on each `text_input` keystroke).
  Our `ng_syncTextToVar` resolves once at write time. Is there a test
  that exercises path-changes between keystrokes? Probably not — defer.

- **OQ-4.** Should Phase A read `html` flag from the TF metadata and
  do a stripped-text overlay vs render html as plain? Ruffle's
  `set_html_text` does the strip; we have the equivalent in
  `strip_html_tags_u16`. Same path either way.

- **OQ-5.** Are there tests where the dejagnu TextField's variable is
  *not* a simple `_root.var` path? Multi-segment paths
  (`_root.dejagnu_clip._trace_text`) might exist in misc-swfc.all.
  Verify Phase A's dot-walk handles them.

---

## Sequence

Phase A first — it's the smallest delta, unblocks the user-visible
symptom, and has zero AS surface impact. Phase B after Phase A is
green across the smoke set and verified in CI. Phase C only after
Phase B's registry is in place. No phase ships partially.

If Phase A reveals that the dejagnu tests' visual diff is more than
just the trace text (e.g. font metrics, dejagnu border, etc.), reopen
this plan with a Phase A.1 addendum before proceeding to B.
