# Script Halting on Clip Removal Plan
<!-- TESTS: removed_clip_halts_script, target_clip_removed -->

Last updated: 2026-03-07

## Status: COMPLETE

### Overview

When a MovieClip is removed from the display list during script execution (via timeline `RemoveObject2` during goto catch-up, `removeMovieClip`, etc.), Flash halts the remainder of the script that was executing on/for that clip. Our runtime now implements this via the `avm1_removed` flag and `actionBaseClipRemoved()` checks.

**Tests**:
- `removed_clip_halts_script` — 15/15 PASS
- `target_clip_removed` — 5/5 PASS
- `goto_frame_number` — 3/3 PASS (regression from initial implementation, fixed)

### Implementation Summary

**Phase 1: avm1_removed flag + actionBaseClipRemoved()** (action.c)

The recompiler already emits `if (actionBaseClipRemoved()) return;` checks in generated scripts. The runtime function was updated to check BOTH `g_current_context` AND `g_base_clip`:

```c
int actionBaseClipRemoved(void) {
    if (g_call_skipped_halt) { g_call_skipped_halt = 0; return 0; }
    if (g_current_context != NULL && g_current_context->avm1_removed) return 1;
    if (g_base_clip != NULL && g_base_clip->avm1_removed) return 1;
    return 0;
}
```

This is needed because `SetTarget("_root")` changes `g_current_context` to root (which is never removed), but the function's actual base clip may have been removed. Checking both ensures the halt triggers correctly.

**Phase 2: SetTarget("") keeps dead base clip** (action.c)

`SetTarget("")` (reset to base clip) was changed to NOT fall back to root when the base clip is dead. This ensures `actionBaseClipRemoved()` can still see the dead MC and halt the script.

**Phase 3: ng_executeGotoTagsOnly()** (swf_core.c)

Created a new function for root gotos from non-sprite-init contexts. It processes intermediate frame tags (PlaceObject, RemoveObject) synchronously so `avm1_removed` gets set, but does NOT queue deferred scripts — avoiding double-execution of the target frame's script. The main loop's catch-up handles the target frame.

Key distinction:
- **Sprite init context** (`ng_isInsideSpriteInit()`): uses `ng_executeGotoCatchUp` (inline catch-up + deferred script queue)
- **Regular frame script context**: uses `ng_executeGotoTagsOnly` (tags only, main loop handles scripts)

**Phase 4: Outer retry loop for deferred-triggered gotos** (swf_core.c)

When a deferred script (running via `g_tag_skip_mode=1`) triggers a goto via `ng_executeGotoTagsOnly`, the resulting `goto_from_action`/`manual_next_frame` flags were not re-checked because the goto catch-up while loop runs before deferred processing. Fixed by wrapping both loops in an outer `for(;;)` that retries if deferred scripts set new goto flags.

**Phase 5: Recompiler loop-back guard** (swf.cpp)

Loop-back code (`if (!manual_next_frame && is_playing)`) now includes `&& !g_tag_skip_mode` to prevent loop-backs during deferred script processing (where `g_tag_skip_mode=1`).

### Other changes

- `ng_isInsideSprite()` reverted to check `g_current_sprite_obj != NULL` (simpler, correct)
- `ng_isInsideSpriteInit()` added: checks `g_sprite_init_depth > 0` in tag.c
- Root DL backup/restore renamed from `g_root_dl_tracked`/`g_sprite_dl_nesting` to `g_root_dl_backup`/`g_sprite_init_depth`
- `g_deferred_goto_play` removed — replaced with direct `is_playing = 1` assignment
- `removeMovieClip` variable cleanup simplified: `deleteProperty` + uninitialized sentinel instead of setting UNDEFINED

### Commits

- `bdfe895c` — Main implementation (actionBaseClipRemoved dual check, ng_executeGotoTagsOnly, SetTarget keeps dead base clip, recompiler loop-back guard)
- `2879b4de` — Fix goto_frame_number regression (outer retry loop for deferred-triggered gotos)
