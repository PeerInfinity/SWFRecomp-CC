# unload_nested_child — Deferred Unload Timing

**Status**: COMPLETE — 5/5 PASS
**Fix commit**: 180bb81b (Defer UNLOAD clip actions during catch_up_mode)

## Problem

`_root.nextFrame()` calls `ng_executeGotoTagsOnly()` which runs frame tags with `catch_up_mode=1`. This fired UNLOAD clip actions inline (before the calling script completed), but Flash defers UNLOAD to the main frame loop's catch-up pass.

## Fix (Variant of Option A)

In `tagRemoveObject2` and `tagRemoveObject` (tag.c), when `catch_up_mode == 1`, check if the display entry has any UNLOAD handlers (own clip_actions, accumulated clip_actions, or child sprite UNLOAD handlers). If yes, skip the entire removal — return immediately. The entry stays in the display list.

The main loop's catch-up re-processes the target frame with `catch_up_mode=0`. Since the entry was not cleared, `tagRemoveObject2` finds it and fires UNLOAD at the correct time (after the calling script completes, before the target frame's DoAction).

The "double-fire" concern from the original plan was avoided because: when `catch_up_mode=1` we skip the entire remove (including `clear_display_entry`), so the entry is still present for the second pass. Entries WITHOUT UNLOAD handlers are processed normally during `catch_up_mode` (no callbacks to fire, so timing is irrelevant).

Also made `has_child_unload_handler` in `tag_stubs.c` non-static so `tag.c` can call it for the child UNLOAD check.

## Files Modified

- `SWFModernRuntime/src/libswf/tag.c` — `tagRemoveObject` and `tagRemoveObject2`: catch_up_mode guard
- `SWFModernRuntime/src/libswf/tag_stubs.c` — `has_child_unload_handler`: made non-static

## Regression Tests Verified

All pass: `unload` (52/52), `clip_events`, `bad_placeobject_clipaction`, `goto_frame`, `goto_frame2`, `goto_label`, `goto_methods`, `execution_order2`, `execution_order3`, `goto_execution_order2`, `goto_rewind3`, `movieclip_in_removed_button`, `register_and_init_order`.
