# ActionCall (0x9E) Semantics Plan
<!-- TESTS: call, removed_target_clip_scope -->

Last updated: 2026-03-04

## Status: BLOCKED — call PASSES (63/63), removed_target_clip_scope blocked on SetTarget scope semantics

### Overview

The `call()` opcode (ActionCall, 0x9E) executes a frame's DoAction script by frame number
or label. All 4 phases are now implemented. The `call` test passes 63/63 (up from 11/63).
The `removed_target_clip_scope` test is still failing (12/35) but the remaining failures
are NOT about actionCall — they're about deeper SetTarget scope resolution issues.

### Implementation Summary (All Phases Complete)

**Phase 0+1: Return value + early termination** — DONE
- `actionCall` returns `int` (0=continue, 1=terminate)
- Recompiler emits `if (actionCall(app_context)) return;` for top-level scripts
- Recompiler emits `if (actionCall(app_context)) { ActionVar _cr = {0}; _cr.type = ACTION_STACK_VALUE_UNDEFINED; return _cr; }` for function bodies
- Base clip removal check: `if (_call_base != &root_movieclip && _call_base->depth == INT_MIN) return 1;`

**Phase 2: Frame label lookup** — DONE
- String values checked as frame labels via `findFrameByLabel` (root) and `ng_findSpriteLabelFrame` (sprites)
- Numeric string parsing attempted first, then label lookup

**Phase 3: Target path resolution** — DONE
- Colon-separated paths (e.g., `/mc:theframe`) parsed and resolved
- `resolveSlashPathToMC` used for MC path resolution
- Context switches to target MC during call execution

**Critical bug discovered and fixed**: `call()` was executing full frame functions including
tags (PlaceObject2, RemoveObject2, ShowFrame). In Ruffle, `call()` only runs DoAction scripts.
Fixed by setting `g_tag_skip_mode=1` during call execution — tags are skipped while scripts
(gated by `!catch_up_mode || g_tag_skip_mode`) still run.

**Other fixes**:
- `call_ctx` now uses `g_current_context` (tellTarget-aware) instead of `g_base_clip`
- Wrapping u32 arithmetic for frame numbers (matches Ruffle's `f64_to_wrapping_u32`)
- Context MC switching for path-based calls

### Test Results

| Test | Lines | Match | Status |
|------|-------|-------|--------|
| call | 63 | 63/63 | **PASS** |
| removed_target_clip_scope | 35 | 12/35 | BLOCKED (not call-related) |
| function_base_clip_removed | 25 | 25/25 | PASS (no regression) |
| string_paths_other | 36 | 36/36 | PASS (no regression) |

### Remaining removed_target_clip_scope Failures

The 23 failing lines are about SetTarget scope semantics, NOT actionCall:
- `this` inside SetTarget blocks resolves to target instead of base_clip
- `GetProperty("", _target)` on removed clips returns wrong path
- Scope tracking after MC removal
- These issues belong in a TELLTARGET_SCOPE_PLAN, not this plan

### Files Modified
- `SWFModernRuntime/src/actionmodern/action.c`: Complete rewrite of `actionCall` function
- `SWFModernRuntime/include/actionmodern/action.h`: Changed declaration to `int` return type
- `SWFRecomp/src/action/action.cpp`: ActionCall emission captures return value

### Blocks These Plans
- TELLTARGET_PLAN (removed_target_clip_scope scope semantics)
