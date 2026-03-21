# Misc-SWFMill Edge Cases Plan
<!-- TESTS: dict_event, jump_after_end, initaction_in_definesprite, jump_to_prev_block, tags_after_last_showframe, zeroframe_definesprite -->

Last updated: 2026-03-21

## Status: 3/6 FIXED, 3 remaining (all blocked on architectural limitations)

**Score: 11/14 (was 8/14)**

---

## Overview

6 tests failed in `from_gnash/misc-swfmill.all`. Each is an independent edge case testing unusual SWF structures. 3 have been fixed; 3 remain blocked.

## Summary Table

| Test | Status | Root Cause | Commit |
|------|--------|------------|--------|
| zeroframe_definesprite | **FIXED** (3/3 PASS) | Clip action parser overrun + sprite frame count init | 1f45d1a7 |
| initaction_in_definesprite | **FIXED** (2/2 PASS) | DoInitAction inside DefineSprite not parsed | 1f45d1a7 |
| jump_after_end | **FIXED** (3/3 PASS) | Action parser stopped at END byte | 1f45d1a7 |
| dict_event | **BLOCKED** (3/5) | Tag interleaving — requires preserving DoAction/PlaceObject order | — |
| tags_after_last_showframe | **BLOCKED** (0/15) | Post-ShowFrame execution + InitAction ordering + loop termination | — |
| jump_to_prev_block | **BLOCKED** (0/1) | Cross-DoAction-block backward jump (architectural) | — |

---

## FIXED: Test 1 — zeroframe_definesprite (3/3 PASS)

**Two fixes applied:**
1. **Recompiler** (`swf.cpp`): Changed clip action parsing loop from `while(true)` to `while(all_event_flags != 0)` in both main timeline and sprite PlaceObject2 paths. When `allEventFlags == 0`, the SWF has no clip action records and no end marker — the parser was overrunning into subsequent tag data.
2. **Runtime** (`tag.c`): Set `child_mc->totalframes` and `child_mc->framesloaded` from `ch->sprite_frame_count` in `process_sprite_init_at_depth()`, before clip actions fire. Also set `currentframe = 0` for zero-frame sprites.

---

## FIXED: Test 3 — initaction_in_definesprite (2/2 PASS)

**Two additions:**
1. **Runtime** (`tag.c`, `tag.h`): Added `tagDoInitActionGuarded()` — a once-per-character-id guard that tracks initialization in `g_init_action_done[512]` and skips already-initialized character IDs.
2. **Recompiler** (`swf.cpp`): Added `case SWF_TAG_DO_INIT_ACTION:` to the DefineSprite inner switch. Parses the SpriteId, generates a script function, and emits `tagDoInitActionGuarded(app_context, sprite_id, script_N)` prepended before frame scripts in the sprite frame buffer.

---

## FIXED: Test 5 — jump_after_end (3/3 PASS)

**Recompiler** (`action.cpp`):
1. **Pass 1**: Changed while loop from `while(code != END)` to `while(true)` with an explicit END check that continues parsing if any label is beyond the current position.
2. **Pass 2**: Added `hasUnvisitedLabelsAhead()` lambda; loop condition changed to `while(code != END || hasUnvisitedLabelsAhead())`. When END is encountered with labels ahead, emits `return;` at the END position to prevent fall-through, then continues parsing the code after END.

---

## BLOCKED: Test 2 — dict_event (3/5)

**Expected**: A, B, ABB, XPASSED, END OF TEST
**Actual**: A, B, AB, XFAILED, END OF TEST

**Revised root cause**: The original analysis ("ConstantPool not persisting") is only part of the issue. The deeper problem is **tag interleaving**: the SWF has DoAction1 → PlaceObject2 → DoAction2 on the same frame. The clip action LOAD event fires during PlaceObject2 and pushes "B" on the shared stack. DoAction2 then sees ["A", "B"] on the stack and produces "ABB".

Our recompiler hoists ALL placement tags before ALL action tags in the frame function (PlaceObject2, PlaceObject2, ..., script_0, script_2, ShowFrame). This means the clip action fires after both DoActions (during ShowFrame), not between them.

**Fix required**: Preserve interleaved tag ordering in frame functions — emit placement and action tags in their original SWF order. This is a significant architectural change to the recompiler's frame generation model.

---

## BLOCKED: Test 4 — tags_after_last_showframe (0/15)

**Expected**: Single line `a1-i1-a2-a3-1`
**Actual**: `i1-a1-a2-a3-1` repeated 15 times (accumulating)

Three interrelated issues:
1. **InitAction ordering**: DoInitAction runs in `tagInit()` before all frames, so "i1-" precedes "a1-". Flash processes InitActions lazily.
2. **Repetition**: Post-ShowFrame DoActions loop with frame cycling, accumulating output.
3. **Termination**: Flash treats post-last-ShowFrame scripts as a trailing frame that runs once and stops.

---

## BLOCKED: Test 6 — jump_to_prev_block (0/1)

**Expected**: ABA
**Actual**: AB

The SWF has 4 DoAction blocks on the same frame. Block 3 backward-jumps to code in block 2. In Flash, multiple DoAction blocks share a virtual address space. Our recompiler compiles each DoAction as a separate C function, making cross-function jumps impossible.

**Fix required**: Merge multiple DoAction blocks on the same frame into a single C function, or implement cross-function control flow. Both are significant architectural changes.
