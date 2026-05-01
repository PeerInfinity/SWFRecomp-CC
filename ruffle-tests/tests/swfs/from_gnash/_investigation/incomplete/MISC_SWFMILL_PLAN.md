# Misc-SWFMill Edge Cases Plan
<!-- TESTS: dict_event, jump_after_end, initaction_in_definesprite, jump_to_prev_block, tags_after_last_showframe, zeroframe_definesprite -->

Last updated: 2026-05-01

## Status: 5/6 FIXED, 1 remaining (`jump_to_prev_block`)

**Effective rate: 17/18 (94.4%)**

Reclassified from `blocked/` to `incomplete/` on 2026-05-01: only `jump_to_prev_block` remains, and it has a concrete (if non-trivial) implementation path — see "Remaining" below.

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
| jump_to_prev_block | **REMAINING** (0/1) | Cross-DoAction-block backward jump — recompiler emits each DoAction as a separate C function, so a backward jump with negative offset can't be expressed as a `goto`. | — |

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

## REMAINING: jump_to_prev_block (0/1)

**Expected**: `ABA`
**Actual**: `AB`

### Test structure

The SWF (1 frame, version 6) has four `DoAction` tags followed by a `ShowFrame`:

| Tag | Bytecode | Effect |
|-----|----------|--------|
| DoAction 1 | `Push("jumpval", "")`, `SetVariable`, `End` | `jumpval = ""` |
| DoAction 2 | `Push("jumpval")`, `Duplicate`, `GetVariable`, `Push("A")`, `AddTyped`, `SetVariable`, `End` | `jumpval += "A"` |
| DoAction 3 | `Push("jumpval")`, `Duplicate`, `GetVariable`, `Push("B")`, `AddTyped`, `SetVariable`, `BranchAlways(byteOffset=-56)`, `End` | `jumpval += "B"`, then jump back |
| DoAction 4 | `Push("jumpval")`, `GetVariable`, `Trace`, `End` | trace the value |

The `BranchAlways(-56)` lands inside DoAction 2's bytecode (specifically the `Push("jumpval")` at the start of its `+= "A"` sequence). One iteration of the loop appends another `"A"`, control falls through into DoAction 3's `+= "B"`, the BranchAlways executes again, and the test source comment notes this is intentional: the test verifies that **the SWF stays alive** and reaches the final `Trace`. (Flash terminates the back-jump loop when the action-execution budget for one frame is exhausted, then runs the next DoAction tag — DoAction 4 — and traces `ABA…` truncated to "ABA" on this particular Flash version.) Per the test's XML comment: *"It is hard to make it self-contained as if the branch fails we'll loose control over the execution so nothing will be traced. Tracing successes is fine."*

### Why our output is `AB`

The recompiler emits one C function per `DoAction` tag (`script_0.c` … `script_3.c`). When `parseActions` encounters the `BranchAlways` and computes the target offset, the result is negative relative to the current DoAction's `action_buffer_start`, so `action.cpp:2070-2074` emits `return;` (since the `goto label_X` target lives in a different C function). The final state is `jumpval = "AB"` from a single forward pass, no loop.

### Fix plan: concatenate consecutive DoAction tags

Treat a run of consecutive `DoAction` tags within the same frame as a single bytecode buffer for recompilation. Cross-tag backward jumps then become ordinary `goto label_X` within one C function — the existing `parseActions` two-pass label-scan + emit logic already handles arbitrary backward jumps and "END as no-op past unvisited labels" within a single buffer (`action.cpp:137-147`, `280`).

#### Step 1 — Detect consecutive DoAction runs in `swf.cpp`

In the main tag-processing loop (around `swf.cpp:2632`, `case SWF_TAG_DO_ACTION:`), peek ahead at the next tag header. While the next tag is also `SWF_TAG_DO_ACTION`, append its body bytes (with the trailing `End` byte stripped — see Step 2) to a working buffer and advance `cur_pos` past it. The loop terminates on any non-DoAction tag (`PlaceObject*`, `RemoveObject*`, `ShowFrame`, etc.).

Tags that must **not** trigger merging:
- `DoInitAction` — different lifecycle (runs at character-init time, not in the frame's action queue).
- Anything inside a `DefineSprite` inner switch that's not a sibling `DoAction` to the current one.

The same logic should be replicated in the `DefineSprite` inner switch (`swf.cpp` near the sprite frame-script generation), so sprite-frame DoAction sequences benefit too.

#### Step 2 — Strip intermediate `END` markers

`parseActions` pass 1 breaks at the first `END` unless a label is already known to be beyond it. Since pass 1 hasn't seen the later DoAction's `BranchAlways` yet at that point, it would prematurely stop at the boundary `END`. Cleanest fix: when concatenating, **drop the trailing `End` byte (0x00) from each merged body except the last one**. The merged buffer then looks like one continuous bytecode stream with a single terminating `End`.

A trailing `End` byte is always present in well-formed `DoAction` tags (and the existing `temp_buffer[body_len] = 0x00` defensive write at `swf.cpp:2655` covers malformed inputs). Stripping is just `body_len -= 1` if `body[body_len-1] == 0x00`.

#### Step 3 — Single `actionQueueScript` for the merged run

Currently each `DoAction` emits its own `actionQueueScript(app_context, script_N)` line into `tag_main`. After merging, emit one `actionQueueScript` for the head script ID; the merged run executes as a single FIFO entry. This preserves the post-Phase-6 inline queueing semantics (the queue position is the **first** DoAction tag's position, which matches Flash — consecutive DoActions effectively run as one unit anyway).

#### Step 4 — Verify constant-pool persistence

`parseActions` saves and restores the parent function's `constant_pool` (see `action.cpp:121`), but within a single merged buffer the pool is naturally shared across the formerly-separate DoAction bodies. This matches Flash's runtime semantics where a `ConstantPool` opcode in DoAction 1 is in scope for DoAction 2's bytecode reads. Today our runtime already shares the pool across tags via `g_constant_pool`, so this should be a no-op — but verify by spot-checking `dict_event` (already passing) and any other multi-DoAction-per-frame test.

### Risks and mitigations

| Risk | Mitigation |
|------|------------|
| Backward-jump infinite loop in misbehaved SWFs | The runtime already exits the frame loop after one tick; the `actionQueueScript` budget bounds total ops per drain. The original `jump_to_prev_block` test relies on this safety net. No new infinite loop is introduced — the existing `script_3` case just becomes `script_0_to_3_merged`. |
| Frame-tag interleaving regressions (e.g. `dict_event`-style PlaceObject between DoActions) | By design we only merge **consecutive** DoActions. PlaceObject2 / RemoveObject / ShowFrame / DoInitAction terminate the run. Non-adjacent DoActions are unaffected. |
| `constant_pool` corruption across formerly-separate DoActions | The runtime already shares the pool globally; the recompiler's `saved_pool` save/restore is per-DefineFunction, not per-DoAction. Merging doesn't change this. Add a regression test for a SWF with `ConstantPool` in DoAction 1 followed by a DoAction 2 that uses it. |
| `try_boundaries` state across merged bodies | `try_boundaries` is per-call to `parseActions`. As long as merged DoActions don't independently open `Try` blocks that span the boundary (Flash doesn't allow this), we're fine. Worth a defensive `try_boundaries.empty()` assertion at each former-boundary point. |
| Sprite-frame DoActions with the same merging | The `DefineSprite` inner-switch processing emits to a separate sprite frame buffer. Apply the same peek-and-merge there; the same `actionQueueScript` consolidation applies. |

### Estimated effort

Low-to-medium. The core change is ~30–60 lines in `swf.cpp`:
- Outer `case SWF_TAG_DO_ACTION:`: peek-ahead loop appending bodies into a `std::vector<char>`.
- Inner `DefineSprite` `case SWF_TAG_DO_ACTION:`: same logic, sprite-buffer aware.
- Strip-`End` helper + one consolidated `actionQueueScript` emit.

Validation:
- `jump_to_prev_block`: 0/1 → 1/1 PASS.
- Regression: full misc-swfmill suite (currently 17/18, target 18/18), plus the wider regression battery (AVM1 lifecycle/goto, gnash actionscript.all, all Shumway timeline/avm1).
- New regression test (optional): a hand-rolled SWF with `ConstantPool` in DoAction 1 and a forward-then-backward jump pattern across the boundary, to lock down the constant-pool sharing.

### Out of scope

This plan does **not** address:
- Backward jumps **across PlaceObject/RemoveObject boundaries** (no known test, and Flash semantics here are murky — the placement runs synchronously, so a back-jump that skips it would be observably different from a forward run).
- Cross-frame backward jumps (would require merging across `ShowFrame`, which is incompatible with our frame-function model).

These remain genuinely architectural limitations and would need a separate plan if a test ever surfaces them.
