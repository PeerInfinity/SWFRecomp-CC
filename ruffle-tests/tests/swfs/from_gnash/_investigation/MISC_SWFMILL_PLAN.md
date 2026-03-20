# Misc-SWFMill Edge Cases Plan
<!-- TESTS: dict_event, jump_after_end, initaction_in_definesprite, jump_to_prev_block, tags_after_last_showframe, zeroframe_definesprite -->

Last updated: 2026-03-19

## Status: INVESTIGATED — all 6 root causes identified, none fixed yet

---

## Overview

6 tests fail in `from_gnash/misc-swfmill.all`. Each is an independent edge case testing unusual SWF structures. They exercise recompiler and runtime corners that normal SWF authoring tools don't produce, but are valid per the SWF spec.

## Summary Table

| Test | Match | Root Cause | Complexity | Actionable? |
|------|-------|------------|------------|-------------|
| zeroframe_definesprite | 0/3 | Recompiler: corrupted clip action parsing | **Medium** | Yes — parser bug |
| dict_event | 3/5 | ConstantPool not persisting across DoAction blocks | **Medium** | Yes |
| initaction_in_definesprite | 0/2 | DoInitAction inside DefineSprite not parsed | **Medium-Hard** | Yes |
| tags_after_last_showframe | 0/15 | Post-ShowFrame tag execution + InitAction ordering | **Hard** | Partially |
| jump_after_end | 1/3 | Jump past END_OF_ACTIONS byte not handled | **Hard** | Maybe |
| jump_to_prev_block | 0/1 | Cross-DoAction-block backward jump | **Very Hard** | Architectural |

---

## Test 1: zeroframe_definesprite (0/3) — Recommended First

**Expected**: `a00b11c22d000` then PASSED then END OF TEST
**Actual**: FAILED message (garbage clip action event flags fire wrong handler)

**Root cause**: The recompiler's PlaceObject2 clip-action parser overruns the clip action data for depth 4. The SWF's PlaceObject2 at depth 4 has `allEventFlags=0x00000000` (no clip actions), but the recompiler generates 5 `clip_actions_12[]` entries with garbage event flags:

```c
{ 0x33f0040, clip_action_4 },    // garbage (should be zero entries)
{ 0x30306100, clip_action_5 },   // garbage (ASCII "a00" bytes!)
{ 0x6d757300, clip_action_6 },   // garbage
{ 0x49264c1c, clip_action_7 },   // garbage — this fires the FAILED trace
{ 0x40, clip_action_8 },         // garbage
```

After the instance name `"zero_zero_doaction\0"`, there are only 6 bytes: `00 00 00 00 00 00` (2-byte reserved + 4-byte allEventFlags=0). The recompiler misaligns its read position and overruns into subsequent tag data.

**Fix**: In the SWF/tag parser's PlaceObject2 handler, when `allEventFlags == 0`, emit zero clip actions instead of continuing to parse. This is likely a boundary check bug where the parser doesn't account for the instance name string length correctly.

**Files to check**: SWFRecomp's PlaceObject2 tag handler (swf.cpp or tag parsing code).

**Fix effort**: Low-Medium. Once the parser bug is found, it should be a targeted boundary fix.

---

## Test 2: dict_event (3/5) — ConstantPool Persistence

**Expected**: A, B, ABB, XPASSED, END OF TEST
**Actual**: A, B, AB, XFAILED, END OF TEST

**Root cause**: Frame 0 has two DoAction blocks. DoAction 1 defines `ConstantPool = ["A"]`. DoAction 2 references `CP[0]` expecting "A", but gets "B" (from the clip action's separate ConstantPool context). In Flash, a ConstantPool defined in one DoAction block **persists** for subsequent DoAction blocks on the same frame.

The recompiler treats each DoAction block's ConstantPool independently. When DoAction 2 references CP[0], it resolves using the clip action's pool (which has "B") rather than the frame-level pool (which has "A").

**Fix**: Track the "current constant pool" across DoAction blocks within the same frame. When a DoAction block doesn't define its own ConstantPool, inherit the parent frame's last-defined pool.

**Note**: This is the same root cause as the `dict_cross` and `dict_event` tests previously categorized as "Cross-Frame ConstantPool" in CURRENT_STATUS.md category 3. `dict_cross` is now passing (the simpler cross-frame case was fixed), but the clip-action interaction case remains.

**Fix effort**: Medium.

---

## Test 3: initaction_in_definesprite (0/2) — InitAction Inside Sprites

**Expected**: PASSED + END OF TEST
**Actual**: Empty output

**Root cause**: The SWF has `DoInitAction` tags **inside** DefineSprite definitions:
- Sprite 2 contains `DoInitAction(char_id=1)` that traces "PASSED..."
- Sprite 3 contains `DoInitAction(char_id=1)` that traces "FAILED..." (should NOT run — char_id=1 was already initialized by sprite 2's InitAction)

The recompiler's DefineSprite parser does **not** handle inner DoInitAction tags. The `RecompiledScripts/` directory has no script files at all, and `script_defs.c` is empty. The `tagMain.c` shows empty sprite frame functions with no InitAction hooks.

**Fix**: The recompiler needs to parse DoInitAction tags within DefineSprite tag blocks and emit them as initialization scripts that fire when the sprite is first instantiated (with the standard once-per-character-id guard).

**Fix effort**: Medium-Hard. Requires changes to the DefineSprite parser in the recompiler to recursively handle inner action tags.

---

## Test 4: tags_after_last_showframe (0/15) — Post-ShowFrame Execution

**Expected**: Single line `a1-i1-a2-a3-1`
**Actual**: `i1-a1-a2-a3-1` repeated 15 times (accumulating)

**Root cause**: Three issues:

1. **InitAction ordering**: The DoInitAction is placed in `tagInit()` which runs before all frame functions, so "i1-" is prepended before "a1-". Flash processes InitActions lazily when the character is first used, not at SWF load time.

2. **Repetition**: Post-ShowFrame DoActions are placed in `frame_1`, which loops back to frame 0. With `num_frames = 30`, the scripts alternate between frame 0 and frame 1, each time accumulating more output.

3. **No termination**: Expected output is a single line. Flash treats post-last-ShowFrame scripts as a "trailing frame" that runs once and stops.

**Fix**: Requires changes to both the recompiler (how it places post-ShowFrame DoAction/DoInitAction blocks) and potentially the runtime's frame looping logic.

**Fix effort**: Hard. The InitAction ordering issue is particularly tricky — it's fundamental to how the recompiler structures SWF initialization vs. frame execution.

---

## Test 5: jump_after_end (1/3) — Jump Past END Byte

**Expected**: Check message, PASSED, END OF TEST
**Actual**: Check message only (then silence)

**Root cause**: The DoAction buffer is 172 bytes. The recompiler stops parsing at the first END byte (0x00) at offset 120. But there is valid code from offset 121-171 that a jump at offset 87 targets. Flash continues execution at post-END offsets. The recompiler emits `label_121: ;` as an unreachable label, effectively making the jump a no-op.

**Fix**: The recompiler would need to:
1. During pass 1, detect if any jump target exceeds the END byte offset
2. If so, continue parsing past END to include the post-END code
3. Emit the post-END code with proper labels

This is an unusual SWF pattern (deliberate code hiding or unusual authoring tool output).

**Fix effort**: Hard. Requires changing the recompiler's fundamental action parsing loop termination condition.

---

## Test 6: jump_to_prev_block (0/1) — Cross-Block Backward Jump

**Expected**: ABA
**Actual**: AB

**Root cause**: The SWF has 4 DoAction blocks on the same frame. Block 3 has a backward jump (`Jump offset=-56`) that targets code in block 2. In Flash, multiple DoAction blocks on the same frame share a virtual address space, so the backward jump re-executes block 2's code. The recompiler turns the backward jump into `return;` (since the target is outside the current function).

**Fix**: Would require either:
- Merging multiple DoAction blocks on the same frame into a single C function
- Implementing some form of cross-function goto (fundamentally difficult in C)

**Fix effort**: Very Hard. This is an architectural limitation of the per-DoAction-block → per-C-function compilation model.

---

## Recommended Fix Order

### Priority 1: zeroframe_definesprite (parser bug — Medium)
Most likely to be a quick win. It's a specific recompiler parsing bug (PlaceObject2 clip action boundary overrun) rather than an architectural issue.

### Priority 2: dict_event (ConstantPool persistence — Medium)
Well-defined problem with a clear fix path. Affects the broader "constant pool across DoAction blocks" pattern.

### Priority 3: initaction_in_definesprite (inner InitAction — Medium-Hard)
Enables a new category of SWF structures. May also help with some misc-ming/misc-swfc tests that use similar inner-sprite action patterns.

### Priority 4: tags_after_last_showframe (Hard)
Multiple interrelated issues. Could tackle the repetition/termination fix independently of the InitAction ordering fix.

### Deferred: jump_after_end + jump_to_prev_block
These are rare SWF patterns requiring significant architectural changes. Low ROI unless similar patterns appear in other test suites.
