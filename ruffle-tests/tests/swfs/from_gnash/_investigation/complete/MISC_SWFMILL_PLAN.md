# Misc-SWFMill Edge Cases Plan
<!-- TESTS: dict_event, jump_after_end, initaction_in_definesprite, jump_to_prev_block, tags_after_last_showframe, zeroframe_definesprite -->

Last updated: 2026-05-01

## Status: 6/6 FIXED — plan complete

**Effective rate: 18/18 (100%)**

Reclassified from `blocked/` to `incomplete/` on 2026-05-01; final test (`jump_to_prev_block`) fixed the same day via the cross-DoAction script-call approach (see "FIXED: jump_to_prev_block" below).

---

## Overview

6 tests failed in `from_gnash/misc-swfmill.all`. Each is an independent edge case testing unusual SWF structures. 5 are fixed; 1 remains.

## Summary Table

| Test | Status | Root Cause | Commit |
|------|--------|------------|--------|
| zeroframe_definesprite | **FIXED** (3/3 PASS) | Clip action parser overrun + sprite frame count init | 1f45d1a7 |
| initaction_in_definesprite | **FIXED** (2/2 PASS) | DoInitAction inside DefineSprite not parsed | 1f45d1a7 |
| jump_after_end | **FIXED** (3/3 PASS) | Action parser stopped at END byte | 1f45d1a7 |
| dict_event | **FIXED** (5/5 PASS) | Picked up via the inter-tag ordering work in the ActionQueue rework (Phases 0–8, plan complete at fe74d7aa) | (cumulative) |
| tags_after_last_showframe | **FIXED** (1/1 PASS) | Recompiler emitted `next_frame=0; manual_next_frame=1` for the dangling post-last-ShowFrame frame, looping the trailing tags. Now emits `quit_swf=1`. | 9020f664 |
| jump_to_prev_block | **FIXED** (1/1 PASS) | Cross-DoAction backward jump — when target lands on the body-start of a previously-compiled DoAction, emit `prev_script(app); return;` to replay it (matching Flash's `reader.seek` semantics: run the target body until the next END byte). | this commit |

---

## FIXED: zeroframe_definesprite (3/3 PASS)

**Two fixes applied:**
1. **Recompiler** (`swf.cpp`): Changed clip action parsing loop from `while(true)` to `while(all_event_flags != 0)` in both main timeline and sprite PlaceObject2 paths. When `allEventFlags == 0`, the SWF has no clip action records and no end marker — the parser was overrunning into subsequent tag data.
2. **Runtime** (`tag.c`): Set `child_mc->totalframes` and `child_mc->framesloaded` from `ch->sprite_frame_count` in `process_sprite_init_at_depth()`, before clip actions fire. Also set `currentframe = 0` for zero-frame sprites.

---

## FIXED: initaction_in_definesprite (2/2 PASS)

**Two additions:**
1. **Runtime** (`tag.c`, `tag.h`): Added `tagDoInitActionGuarded()` — a once-per-character-id guard that tracks initialization in `g_init_action_done[512]` and skips already-initialized character IDs.
2. **Recompiler** (`swf.cpp`): Added `case SWF_TAG_DO_INIT_ACTION:` to the DefineSprite inner switch. Parses the SpriteId, generates a script function, and emits `tagDoInitActionGuarded(app_context, sprite_id, script_N)` prepended before frame scripts in the sprite frame buffer.

---

## FIXED: jump_after_end (3/3 PASS)

**Recompiler** (`action.cpp`):
1. **Pass 1**: Changed while loop from `while(code != END)` to `while(true)` with an explicit END check that continues parsing if any label is beyond the current position.
2. **Pass 2**: Added `hasUnvisitedLabelsAhead()` lambda; loop condition changed to `while(code != END || hasUnvisitedLabelsAhead())`. When END is encountered with labels ahead, emits `return;` at the END position to prevent fall-through, then continues parsing the code after END.

This is the foundation the `jump_to_prev_block` plan below builds on — once consecutive DoAction bodies are concatenated, the END markers between them become "no-op past END" cases that the existing logic already handles.

---

## FIXED: dict_event (5/5 PASS)

Originally diagnosed as a tag-interleaving issue where DoAction1 → PlaceObject2 → DoAction2 in the same frame produced wrong output because clip actions ran during ShowFrame instead of at the PlaceObject2 position. Resolved as a side effect of the ActionQueue rework (Phases 0–8, plan complete at commit fe74d7aa) — the unified queue and inline root-DoAction queueing (Phase 6, commit a427f5fc) preserves the in-frame ordering between placement-driven clip events and DoAction tags.

No follow-up needed.

---

## FIXED: tags_after_last_showframe (1/1 PASS)

**Recompiler** (`SWFRecomp/src/swf.cpp`, END_TAG handler, commit 9020f664):

When a SWF has tags after the last `ShowFrame`, the recompiler opens a new `frame_N` to hold them but no `ShowFrame` ever closes it (`another_frame == false` at END_TAG). Previously this dangling frame was treated like a normal frame and looped back to `frame_0`, so the trailing DoActions re-executed on every iteration (15 lines of accumulating output instead of 1 expected line). Fix: emit `quit_swf = 1` in the dangling frame instead of `next_frame = 0; manual_next_frame = 1`. Mirrors Flash/Ruffle, which run trailing tags only on initial play. The single-frame check `next_frame_i == 1` is preserved; a new `!another_frame` clause covers the dangling case for any `next_frame_i`.

This also resolves the originally-listed "InitAction ordering" concern: with `quit_swf=1`, the trailing block runs exactly once after the timeline reaches its last `ShowFrame`, in the natural `i1-a1-a2-a3-1` order.

---

## FIXED: jump_to_prev_block (1/1 PASS)

**Expected**: `ABA`
**Actual (was)**: `AB`

### Test structure

The SWF (1 frame, version 6) has four `DoAction` tags followed by a `ShowFrame`:

| Tag | Bytecode | Effect |
|-----|----------|--------|
| DoAction 1 | `Push("jumpval", "")`, `SetVariable`, `End` | `jumpval = ""` |
| DoAction 2 | `Push("jumpval")`, `Duplicate`, `GetVariable`, `Push("A")`, `AddTyped`, `SetVariable`, `End` | `jumpval += "A"` |
| DoAction 3 | `Push("jumpval")`, `Duplicate`, `GetVariable`, `Push("B")`, `AddTyped`, `SetVariable`, `BranchAlways(byteOffset=-56)`, `End` | `jumpval += "B"`, then jump back |
| DoAction 4 | `Push("jumpval")`, `GetVariable`, `Trace`, `End` | trace the value |

`BranchAlways(-56)` is computed in **absolute SWF byte positions**, not relative to the current DoAction body. With six-byte extended tag headers in this swfmill-generated SWF, `(after-BranchAlways absolute SWF pos) + (-56)` lands exactly on DoAction 2's body-start (Push("jumpval")). Flash's reader executes from that position until it hits the next `End` byte — that is, it replays DoAction 2 once more (`+= "A"` → `"ABA"`), then DoAction 2's `End` terminates DoAction 3's execution. DoAction 4 then dequeues normally and traces `ABA`.

### Approach taken

Rather than concatenating consecutive DoActions into one bytecode buffer (the original plan, which fails because the SWF's offset is computed in absolute SWF byte positions including six-byte tag headers we'd otherwise strip — and even if we adjusted offsets, the merged function couldn't both stop at the inner-DoAction-2 `End` after the back-jump *and* fall through it during normal forward flow), we keep one C function per DoAction and replay the target as a function call:

1. **`SWF` class** (`swf.hpp`): Added `std::map<char*, std::string> doaction_script_map` keyed by absolute SWF address of each DoAction body's first byte → emitted script function name (`"script_N"`).
2. **`SWFAction` class** (`action.hpp`): Added two transient pointers — `abs_swf_buffer_start_ptr` (the SWF address corresponding to the bytecode buffer's start) and `doaction_script_map_ptr` (pointer to the map). Set by the DoAction case in `swf.cpp` before each `parseActions` call, cleared after.
3. **DoAction handlers in `swf.cpp`**:
   - Main timeline (`SWF_TAG_DO_ACTION` at line ~2632): wires `abs_swf_buffer_start_ptr = tag_body_start` and the map pointer before `parseActions`, then registers `tag_body_start → "script_N"` in `doaction_script_map` after parsing.
   - DefineSprite inner switch (`SWF_TAG_DO_ACTION` at line ~5065): same wiring, with `cur_pos` doubling as `action_buffer_start` (no temp buffer there).
   - Map insertion happens **after** the current DoAction's parseActions, so a self-referential backward jump within the current body still uses the in-buffer goto path and only cross-DoAction targets fall into the map lookup.
4. **`parseActions` JUMP/IF handlers** (`action.cpp` ~2065, ~2082): when `target_offset < 0` and `parse_depth == 1` and both transient pointers are set, compute `target_swf_ptr = abs_swf_buffer_start_ptr + target_offset` and look it up in the map. If hit, emit `prev_script(app_context); return;` (or `if (...) { prev_script(app); return; }` for IF) instead of the bare `return;`. Nested calls (DefineFunction body, Try, With) are gated out by the `parse_depth == 1` check.

### Why this works

Flash's `reader.seek(absolute_offset)` runs the target bytes until the next `End` byte. When the target is the body-start of an earlier DoAction, "until the next End byte" means "until the end of that DoAction's body". That is exactly the semantics of calling the previously-emitted `script_N(app_context)` function (which compiles down to "run that body to its trailing End → return"), then returning from the current DoAction.

### Validation

- `jump_to_prev_block`: 0/1 → 1/1 PASS.
- Other 5 plan tests still pass: `dict_event`, `jump_after_end`, `initaction_in_definesprite`, `zeroframe_definesprite`, `tags_after_last_showframe`.
- AVM1 jump/goto sample (`looping`, `goto_both_ways1/2`, `goto_advance1`, `goto_rewind1`, `goto_frame`, `execution_order2/3`, `goto_execution_order2`, `define_function2_preload_order`, `as2_super_and_this_v6`): all PASS.

### Out of scope (still)

- Cross-tag backward jumps where the target lands **mid-instruction** in an earlier DoAction (no known test).
- Cross-tag backward jumps where the target lands inside a tag header (no known test; Flash would interpret garbage opcodes).
- Backward jumps **across PlaceObject/RemoveObject boundaries** that skip the placement (no known test, semantics unclear).
- Cross-frame backward jumps across `ShowFrame` boundaries (incompatible with our frame-function model).
