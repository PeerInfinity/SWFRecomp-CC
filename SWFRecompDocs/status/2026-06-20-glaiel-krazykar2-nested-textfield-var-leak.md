# Glaiel krazykar2 — sprite-nested textfield simple-variable leaked to `_root` — FIXED

**Date:** 2026-06-20
**Game:** glaiel `krazykar2` (287KB, AVM1)
**Bucket:** headless trace divergence (CI-observable, both modes).
**Status:** FIXED — `SWFModernRuntime/src/libswf/tag_stubs.c` (`ng_on_place_object2`).

## Symptom

`divergence_test.py "krazykar2.swf"` first divergence (filtered line 2): swfrecomp
emitted **`F<n> _root perc="%Loaded"` on every frame** (74 trace lines vs Ruffle's
61); Ruffle never enumerates `perc` on `_root`. `perc` is a `DefineEditText`
(char 3) with the **simple** variable name `"perc"` and initial text `"%Loaded"`,
placed **inside sprite_4** (depth 1), and sprite_4's instance is the root-placed
preloader clip `instance1`. The correct binding is `instance1.perc` (Ruffle binds
parent-scope), so it must NOT appear in a `for..in _root`.

## Root cause

`ng_on_place_object2` has TWO textfield-variable code paths:

1. **Legacy seeding** (the bug): `actionInitTextFieldVariable(var_name, init_text)`.
   For a simple (unqualified) name it unconditionally writes the variable into the
   **global var_map** (`setVariableByName`) from the field's initial text. The
   global var_map is the unqualified-root-variable store, and `for..in _root`
   enumerates it (`enum_varmap_callback`). The function only receives `var_name` +
   `init_text` — it has no parent context — so it always seeds the **root** scope,
   even for a field nested in a child sprite.
2. **Phase B bind** (correct): `actionFindOrCreateMovieClip(instance_name,
   g_current_context)` + `actionTryBindTextFieldVariable(set_initial_value=1)`,
   which binds simple names on `tf_mc->parent`'s `dynamic_props` — here
   `instance1`, matching Ruffle's `try_bind_text_field_variable`
   (`edit_text.rs:1432`, "initialize the property with the text field's text").

So `perc` was correctly bound on `instance1` AND wrongly seeded into root's
var_map by the legacy path → the leak. (Diagnosed with targeted instrumentation:
the bind path reported `is_root=0 parent_name='instance1'`; the leak was found in
the `for..in _root` **var_map** walk, not root's `dynamic_props`.)

## Fix

Guard the legacy seeding by the field's placement scope (the same
`g_current_context` the Phase B bind uses): only seed the global var_map when the
textfield's parent IS `_root`. Path-variable names (`"_root.mc.var"`) name their
own container and are parent-independent, so they are always seeded (and remain
handled by `actionInitTextFieldVariable`'s path branch). Nested simple-name fields
now rely solely on the Phase B bind → variable lives on the parent MC only.

```c
extern MovieClip root_movieclip;
int is_path_var = (strchr(var_name, '.') != NULL);
MovieClip* tf_parent = g_current_context ? g_current_context : &root_movieclip;
if (is_path_var || tf_parent == &root_movieclip)
    actionInitTextFieldVariable(app_context, var_name, init_text);
```

Generalizes to any AVM1 SWF with a simple-named textfield variable inside a child
sprite (common in preloaders).

## Verification

- `divergence_test.py "krazykar2.swf" --frames 16 --skip-ruffle`: the 15 `_root
  perc` lines are gone (swfrecomp 74→59 trace lines). First divergence advanced
  from filtered L2 to **L3** (a SEPARATE bug — see below).
- Regression (NO_GRAPHICS, all PASS): gnash `DefineEditTextVariableNameTest`,
  `DefineEditTextVariableNameTest2`; shumway `text-bind`; avm1 `edittext_autosize`,
  `edittext_default_format`, `edittext_html_roundtrip`, `string_paths_variable_alias`,
  `loadvariables`, `set_variable_scope`, `get_variable_in_scope` (10/10).
- Shared runtime code (compiled in NO_GRAPHICS + OFFSCREEN/graphics) → CI both
  modes.

## RESOLVED (not a bug) — krazykar2 divergence B: l1/l2 = accepted preloader-pacing

Ruffle has `_root.l1`/`_root.l2` at F1 (`_cf=0`, gone by F2); swfrecomp never
enumerates them. **Root-caused as the accepted preloader-pacing class — SWFRecomp
is Flash-plausible, NOT a bug** (same class as Duck Life 1's `spinamount`).

**Mechanism (fully traced):**
- `instance1`'s `onClipEvent(load)` (`clip_action_1`) creates the two loading-bar
  clips: `_root.createEmptyMovieClip("l1",1)` / `("l2",2)` (receiver `mc==_root`,
  confirmed `mc_is_root=1`), plus `p1=0`, `_root.stop()`.
- The preloader logic `script_2` computes `p1 = (getBytesLoaded/getBytesTotal)*100`
  and, **once `p1 >= 100`**, runs `_root.l1.removeMovieClip()` /
  `_root.l2.removeMovieClip()` (verified: the removals fire via `actionRemoveSprite`
  at action.c:55043/55047, gated by `if (p1 < 100) goto skip`).
- On a **local, fully-loaded SWF**, `getBytesLoaded == getBytesTotal` immediately,
  so swfrecomp's `p1 = 100` at frame 1 → the bar clips are removed **before** F1's
  tracer dump. Ruffle's **headless exporter** reports partial bytes at F1, so
  `p1 < 100` there and l1/l2 survive that one frame (gone by F2).

So the divergence is purely the preloader's load-pacing, where SWFRecomp matches
real-Flash "local SWF already loaded" behavior and Ruffle's exporter holds. This
is the documented preloader/network-pacing accepted class (cf. Art of War, Bloons,
Duck Life 2 in RESULTS.md; Duck Life 1 `spinamount`).

**Decision:** documented as accepted, NOT suppressed in the harness. The
accepted-diff facility absorbs field-value PAIRS, not Ruffle-only lines; a
ruffle-only-line rule (or a generic `_root.l[12]` NOISE_PATTERN) would weaken the
facility's bug-masking safety for a cosmetic 2-line, frame-1-only artifact. krazykar2
is therefore **converged modulo this accepted preloader-pacing divergence** (the
only other trace diffs are f32-vs-f64 precision, already harness-absorbed).

**Earlier (disproven) lead:** the AS-depth-1 vs timeline-depth-(-16383) collision
was a red herring — the removal is an explicit, load-gated `removeMovieClip`, not a
depth collision.
