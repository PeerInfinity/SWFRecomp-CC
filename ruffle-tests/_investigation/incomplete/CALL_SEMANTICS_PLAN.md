# ActionCall (0x9E) Semantics Plan
<!-- TESTS: call, removed_target_clip_scope -->

Last updated: 2026-03-03

## Status: INCOMPLETE — Early-termination + recompiler integration needed

### Overview

The `call()` opcode (ActionCall, 0x9E) executes a frame's DoAction script by frame number
or label. The current implementation works for basic cases (11/63 on `call` test) but is
missing early-termination semantics: in Ruffle, if `call()` causes the base clip to be
removed, the calling script terminates immediately. This blocks `removed_target_clip_scope`.

### Current Implementation

**Runtime** (action.c ~21907, `actionCall`):
- Pops frame identifier from stack (number or string label)
- Resolves target sprite (uses `g_current_context` sprite or root timeline)
- Converts to 0-based frame index
- Executes the frame's DoAction function directly
- Returns void — no removal check

**Recompiler** (action.cpp ~1937):
- Emits: `actionCall(app_context);`
- No return value capture

**Recent fixes** (MC_REMOVAL_LIFECYCLE_PLAN):
- F64 reading bug fixed (was using `sizeof(float)` for double)
- 1-based to 0-based frame conversion
- Frame navigation state save/restore around call()
- `g_in_action_call` flag suppresses tagShowFrame side effects
- `depth != INT_MIN` check skips removed sprites

### Ruffle's Implementation

From `activation.rs` line 716-755:

```rust
fn action_call(&mut self) -> Result<FrameControl<'gc>, Error<'gc>> {
    // ... frame lookup ...
    if let Some((clip, frame)) = call_frame {
        for action in clip.actions_on_frame(frame as u16) {
            let _ = self.run_child_frame_for_action("[Frame Call]", clip.into(), action)?;
        }
    }
    self.continue_if_base_clip_exists()  // KEY: check if base clip still alive
}

fn continue_if_base_clip_exists(&self) -> Result<FrameControl<'gc>, Error<'gc>> {
    if self.base_clip.avm1_removed() {
        Ok(FrameControl::Return(ReturnType::Explicit(Value::Undefined)))  // TERMINATE
    } else {
        Ok(FrameControl::Continue)  // CONTINUE normally
    }
}
```

**Key behavior**: After executing the called frame's actions, check if `base_clip` has been
removed. If so, return `FrameControl::Return` which causes the **calling script to exit
immediately** — no subsequent actions execute.

### Blocked Tests

| Test | Lines | Match | Specific Issue |
|------|-------|-------|---------------|
| call | 63 | 11/63 | Multiple issues: frame label lookup gaps, target resolution, early-termination |
| removed_target_clip_scope | 37 | 16/37 | Lines 17+: "This should be unreachable" appears because call() doesn't terminate the calling script after base clip removal |

### Blocks These Plans
- MC_REMOVAL_LIFECYCLE_PLAN (removed_target_clip_scope Phase 4)
- TELLTARGET_PLAN (removed_target_clip_scope)

---

## Phase 0: Return Value from actionCall

**Goal**: `actionCall()` returns a flag indicating whether the calling script should terminate.

### Implementation

#### 0a. Change actionCall signature

**Before:**
```c
void actionCall(SWFAppContext* app_context);
```

**After:**
```c
int actionCall(SWFAppContext* app_context);
// Returns: 0 = continue normally, 1 = base clip removed, terminate calling script
```

#### 0b. Add removal check after frame execution

```c
int actionCall(SWFAppContext* app_context) {
    // ... existing frame lookup and execution ...

    // After executing frame actions:
    // Check if base_clip (g_current_context or calling MC) has been removed
    MovieClip* base = /* the MC that was g_current_context before the call */;
    if (base != NULL && base->depth == INT_MIN) {
        return 1;  // base clip removed, caller should terminate
    }
    return 0;  // continue normally
}
```

#### 0c. Update header declaration

In `action.h`, change the declaration to return `int`.

### Files to Modify
- `SWFModernRuntime/src/actionmodern/action.c`: actionCall return type + removal check
- `SWFModernRuntime/include/actionmodern/action.h`: declaration update

### Estimated Effort
~10 lines changed.

---

## Phase 1: Recompiler — Capture Return Value

**Goal**: Generated C code checks actionCall's return value and exits if needed.

### Implementation

In `SWFRecomp/src/action/action.cpp`, where ActionCall (0x9E) is emitted:

**Before:**
```cpp
action_buffer_output << "actionCall(app_context);\n";
```

**After:**
```cpp
action_buffer_output << "if (actionCall(app_context)) return;\n";
```

This causes the generated frame function to return immediately when actionCall
detects base clip removal, matching Ruffle's early-termination behavior.

### Considerations

- The generated function may need a return type compatible with this early return.
  Frame functions are typically `void`, so `return;` should work.
- If the frame function is inside a type 2 DefineFunction2, the early return
  propagates up to the function caller — this is correct behavior (the entire
  script terminates, not just the called frame).
- Need to verify this doesn't conflict with other control flow (goto labels, etc.)

### Files to Modify
- `SWFRecomp/src/action/action.cpp`: ActionCall emission

### Estimated Effort
~5 lines changed. But all tests using ActionCall need re-recompilation.

---

## Phase 2: Frame Label Lookup in actionCall (call test improvements)

**Goal**: Improve `call` test pass rate by supporting string frame labels.

### Current State

`actionCall()` currently handles:
- Integer frame numbers (F64/F32 → 0-based index)
- Possibly string-to-integer conversion

Missing:
- Frame label lookup (string → frame number via `findFrameByLabel`)
- Slash-path target resolution (e.g., `call("sprite1:2")`)

### Implementation

```c
// In actionCall, when the popped value is a string:
if (val.type == ACTION_STACK_VALUE_STRING) {
    // 1. Try parsing as integer
    int frame = parseFrameNumber(str);
    if (frame >= 0) {
        // Use numeric frame
    } else {
        // 2. Try frame label lookup
        frame = findFrameByLabel(target_mc, str);
        if (frame >= 0) {
            // Use labeled frame
        }
    }
}
```

### Estimated Effort
~15-20 lines.

---

## Phase 3: Target Path Resolution in actionCall (call test)

**Goal**: Support target path syntax in call() (e.g., `call("sprite:2")`).

### What's Needed

The `call` test uses path syntax: `call("/sprite:2")` which should:
1. Parse the path to find the target MovieClip
2. Execute frame 2 of that MovieClip's timeline

Current implementation only looks at the current sprite context or root.

### Implementation

Parse the string for `:` separator:
```c
// "sprite:2" → target="sprite", frame="2"
// "/sprite:2" → absolute path, target="/sprite", frame="2"
char* colon = strchr(str, ':');
if (colon) {
    // Split into path and frame
    // Resolve path to MovieClip
    // Resolve frame number/label
}
```

### Estimated Effort
~30-40 lines.

---

## Priority Assessment

| Phase | Effort | Tests Fixed | ROI |
|-------|--------|------------|-----|
| Phase 0 | ~10 lines | prerequisite for Phase 1 | Required |
| Phase 1 | ~5 lines + re-recompile | removed_target_clip_scope improvement | **HIGH** — unblocks MC_REMOVAL |
| Phase 2 | ~20 lines | call test improvement (~5-10 lines) | Medium |
| Phase 3 | ~35 lines | call test improvement (~10-20 lines) | Medium |

**Recommendation**: Do Phases 0-1 first (quick, high impact for removed_target_clip_scope).
Phases 2-3 improve the `call` test from 11/63 toward ~30-40/63.

---

## Regression Guard

After Phase 1 (recompiler change), tests using ActionCall opcode need re-recompilation.

```bash
python3 ruffle-tests/verify_output.py --test=call --diff --verbose
python3 ruffle-tests/verify_output.py --test=removed_target_clip_scope --diff --verbose
python3 ruffle-tests/verify_output.py --test=function_base_clip_removed --diff --verbose
python3 ruffle-tests/verify_output.py --test=string_paths_other --diff --verbose
```
