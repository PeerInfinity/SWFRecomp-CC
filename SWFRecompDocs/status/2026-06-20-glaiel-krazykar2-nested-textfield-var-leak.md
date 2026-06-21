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

## STILL OPEN — krazykar2 next divergence (B): `_root.l1`/`_root.l2` removed before F1

New first divergence (filtered L3): Ruffle has `_root.l1`/`_root.l2` at F1
(`_cf=0`, gone by F2); swfrecomp never enumerates them. They are created by
`instance1`'s `onClipEvent(load)` (`clip_action_1`):
`_root.createEmptyMovieClip("l1",1)` / `("l2",2)`, plus `perc="0%"` (unqualified
→ instance1 scope), `p1=0`, `_root.stop()`.

**Characterized via instrumentation (NOT a creation or load-timing bug):**
- `createEmptyMovieClip` DOES fire for both, with the receiver `mc == _root`
  (`mc_is_root=1`), and **before** the first tracer dump (interleaved stdout
  order: `l1`,`l2` created → `TRACER: start` → `__tracer__` → `F1`). So the load
  handler runs at the right time and on the right target.
- BUT a one-shot dump at the **first `_root` for..in** shows
  `root.dynamic_props` = `{$version, __tracer__}` and `child_mc_cache(parent=root)`
  = `{instance1 (depth=-16383), __tracer__ (depth 1048575)}` — **l1/l2 are absent
  from BOTH** by F1. So they are created and then **removed** between the load
  handler and the first enumeration.

**Lead:** l1 is created at **depth 1**, the same depth as the timeline clip
`instance1` (char 4, root depth 1; stored in cache as `1 - 16384 = -16383`). The
collision/removal between the AS-depth space (raw `1`) and the timeline-depth
encoding (`-16383`) is the prime suspect — either the createEmptyMovieClip
depth-conflict loop, a frame-advance display-list rebuild, or a catch-up cleanup
pass strips the freshly-created AS clips. Next: instrument what sets l1/l2's
`depth=INT_MIN` / clears their `child_mc_cache` slot / removes the
`root.dynamic_props` entry between creation and F1. Distinct from the `perc` leak.
