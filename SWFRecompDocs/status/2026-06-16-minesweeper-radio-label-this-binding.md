# Minesweeper — FUIComponent radio labels (grey bars → real text) — FIXED

**Date:** 2026-06-16 (cont. 38, follow-up to cont. 37 device-font fix)
**Game:** flasharchive/Minesweeper (browser-WASM graphics / graphics-native)
**Bucket:** headless-diagnosable (reproduces in the OFFSCREEN divergence harness;
fixes are CI-observable in `--mode=graphics` and partly in `no-graphics`).

## Symptom

The three difficulty radio buttons ("Easy (40 mines)", "Medium (70 mines)",
"Tough (100 mines)") rendered as a uniform **grey bar** with **no label text**.
The radio circles drew fine.

Two independent bugs:
- **Bug A — labels missing:** `FLabel.setLabel` sets `this.labelField.text =
  label`, but the rendered `labelField` wrapper kept its initial text (a single
  space). The AS-assigned text never reached the rendered field.
- **Bug B — grey bar:** a solid `0x808080` bar at each label, the width of the
  `frb_hitArea_mc` clip (a wide hit-test shape the component sets
  `_visible=false`).

## Diagnosis (clean — trace matches Ruffle byte-for-byte)

Instrumenting the AVM1 dispatch with `OFFSCREEN_RENDER`+`getenv("TFDIAG")` probes
followed the data:

1. `actionIterateTextFieldGlyphs` saw the 3 `labelField` wrappers with `text=" "`.
2. The `labelField.text = " Easy (40 mines)"` write (`actionSetMember`) landed on
   an **UNDEFINED** receiver — `this.labelField` resolved to undefined.
3. `actionCallMethod` showed `setLabel` was dispatched with the correct receiver
   `recv=fLabel_mc`, **but inside the method `this` resolved to `level_eazy`**
   (the radio button), not `fLabel_mc`. So `this.labelField` looked up the
   nonexistent `level_eazy.labelField` → undefined.

Root cause: `FLabel.setLabel` is a **type-1 (simple) `DefineFunction`**. The
MovieClip user-method dispatch (`_mc_user_dispatch` in `actionCallMethod`) binds
`this` for type-2 functions via `g_event_this_mc` (consumed by `preload_this`),
but for **type-1** it only wrote `this` into the local scope object — it never
pushed the receiver onto **`g_this_stack`**. `GetVariable("this")` consults
`g_this_stack` *before* the scope chain (it mirrors Flash's `Activation.this`,
which is not a scope property), so the simple method body read the **caller's**
`this` (`level_eazy`) instead of the receiver (`fLabel_mc`).

Bug B was a separate display-list issue: an attachMovie'd child's
`mc->display_obj` is the clip's own child-holder, a **separate** `DisplayObject`
from the entry `ng_attachMovie` registers in the parent's `sprite_display_list`
(they share the children array but have independent `as_hidden`). The `_visible`
setters wrote `as_hidden` onto `mc->display_obj`, so the registration entry that
`render_display_list` iterates never got the flag → the invisible `frb_hitArea`
kept painting.

## Fixes (`SWFModernRuntime/src/...`)

1. **`actionCallMethod` `_mc_user_dispatch` (action.c):** for the type-1 branch,
   push the receiver MC onto `g_this_stack` (balanced restore) — the core fix.
   Type-2 already binds via `g_event_this_mc`. **This is the load-bearing fix**
   and affects all build modes (NO_GRAPHICS + graphics): any
   `clip.userMethod()` where the method is a simple `DefineFunction` that reads
   `this` was running with the caller's `this`.
2. **`findDisplayEntryInParent` (action.c):** search the parent's OWN
   `display_obj->sprite_display_list` before the global-list lookup, so a named
   child (EditText `labelField`) of an attached clip nested inside another
   attached clip resolves. (Without #1 this alone is insufficient; with #1 it
   makes the child reachable for init.)
3. **`sync_attached_entry_hidden` helper + 4 `_visible`-setter sites (action.c):**
   propagate `as_hidden` from `mc->display_obj` onto the parent's registration
   entry for attachMovie'd children. **Plus** a matching
   `if (obj->clip_depth == 0 && obj->as_hidden) continue;` skip in
   `render_display_list` (tag.c), mirroring the main display loop. Together these
   stop drawing an attachMovie'd clip the script hid → grey bar gone.

## Verification

- Divergence harness (OFFSCREEN, `--skip-ruffle`): all three radio labels render
  their full text on a clean background (no grey bar); matches Ruffle's
  `15.png`. Trace unchanged (still the lone pre-existing sub-pixel `_y` diff on a
  component label, line 12).
- Local NO_GRAPHICS sanity: `custom_clip_methods`, `movieclip_prototype_extension`,
  `as2_super_and_this_v6`, `call_method_empty_name` all pass.
- Shared runtime + OFFSCREEN render path → CI dispatched both modes.

## Remaining (minor, out of scope)

Medium is the initially-selected radio; Ruffle draws a filled center dot. Ours
draws an empty circle (the `frb_states` selected-frame indicator isn't shown).
Separate, cosmetic; not pursued this session.
