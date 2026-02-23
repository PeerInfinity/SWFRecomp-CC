# Frame Navigation Implementation Plan
<!-- TESTS: goto_frame, goto_frame2, goto_label, goto_methods -->

Last updated: 2026-02-22

## Status: PARTIALLY IMPLEMENTED

Frame navigation functions exist (gotoFrame, gotoFrame2, gotoLabel, prevFrame, nextFrame) but frame execution ordering bugs remain. All 4 tests still fail on CI.

### CI Results (2026-02-22)

| Test | CI Status | Notes |
|------|-----------|-------|
| goto_frame | output_mismatch | Ordering bug still present |
| goto_frame2 | output_mismatch | Ordering bug + label/scene edge cases |
| goto_label | output_mismatch | Label lookup exists but ordering issues |
| goto_methods | segfault | Still crashing |

### What's Implemented
- **actionGotoFrame**: Functional — sets next_frame, manual_next_frame, calls ng_executeGotoCatchUp() synchronously
- **actionGoToLabel**: Functional — looks up label via findFrameByLabel(), converts to frame number
- **actionGotoFrame2**: Functional — takes 1-based frame from stack, adds scene_bias
- **actionPrevFrame**: Fully implemented — decrements current_frame
- **actionNextFrame**: Fully implemented — increments current_frame

### Remaining Issues
- **Ordering bug** (Bug 1): ng_executeGotoCatchUp() runs synchronously during the calling frame's script, causing target frame's script to execute BEFORE code after the goto call
- **goto_methods segfault**: Needs investigation — prevFrame/nextFrame dispatch may have issues with extreme values

**4 failing tests** (3 MISMATCH, 1 SEGFAULT):

| Test | Lines | Status | Primary Issue |
|------|-------|--------|---------------|
| goto_frame | 11/12 (91%) | MISMATCH | Ordering bug: _currentframe trace appears after target frame's script |
| goto_frame2 | varies | MISMATCH | Ordering bug + label strings + scene navigation + edge cases |
| goto_label | partial | MISMATCH | Ordering issues |
| goto_methods | SEGFAULT | SEGFAULT | Extreme values cause crash |

---

## Root Cause Summary

### Bug 1: Frame Execution Ordering (goto_frame, goto_frame2, goto_label)

`actionGotoFrame` calls `ng_executeGotoCatchUp()` **synchronously while the calling frame's script is still running**. This causes the target frame's script to execute BEFORE the code after the `gotoAndStop` call in the calling frame.

Example from goto_frame — script_0 (root frame 0):
```
trace("// frame 1")
actionGotoFrame(1)         ← ng_executeGotoCatchUp runs frame 1 (outputs "// frame 2") HERE
actionPlay()
trace(_currentframe)       ← outputs "2" here (AFTER "// frame 2")
```

**Expected output:**
```
// frame 1
2              ← trace after goto (new currentframe)
// frame 2     ← target frame's script
```

**Actual output:**
```
// frame 1
// frame 2     ← WRONG: target frame ran before trace
2
```

**Fix:** Remove `ng_executeGotoCatchUp(app_context)` call from `actionGotoFrame` and `actionGoToLabel`. The main loop's `while (goto_from_action && manual_next_frame)` block (swf_core.c:163) already performs the same logic — the catch-up just needs to happen AFTER the current frame's script finishes.

`root_movieclip.currentframe = frame + 1` should be kept (set immediately), so `_currentframe` reads the new value within the calling script.

### Bug 2: Debug Printf in actionGoToLabel (goto_label)

`actionGoToLabel` has a stray debug print:
```c
printf("// GoToLabel: %s\n", label ? label : "(null)");  // line ~10733
```
This outputs "// GoToLabel: INVALID\n" and "// GoToLabel: SomeFrame\n" into test output.

**Fix:** Delete this line.

### Bug 3: Frame Labels Not Parsed in Recompiler (goto_label, goto_frame2, goto_methods)

`SWF_TAG_FRAME_LABEL` (tag 43) case in swf.cpp both the main loop and sprite sub-loop just skip the data:
```cpp
case SWF_TAG_FRAME_LABEL:
    cur_pos += tag.length;  // Does nothing
    break;
```

The `frame_labels` map in `SWF` class is declared but never populated. The generated `tagMain.c` always gets `frame_label_count = 0`. The emit infrastructure is already present in swf.cpp (lines ~530-560) — it just never has data to emit.

Additionally, there are NO per-sprite label tables at all (sprite label handling is also missing).

**Fix (Phase A — root labels):** In the main loop `SWF_TAG_FRAME_LABEL` case, read the null-terminated label string and store `frame_labels[label] = next_frame_i`.

**Fix (Phase B — sprite labels):** In the sprite sub-loop `SWF_TAG_FRAME_LABEL` case, store per-sprite labels. Emit per-sprite label tables in tagMain.c and extend the runtime to look them up when navigating sprites by label.

### Bug 4: String Labels Not Looked Up (goto_label, goto_frame2, goto_methods)

`actionGotoFrame2` and the `gotoAndStop`/`gotoAndPlay` MOVIECLIP method dispatch only handle numeric strings. Non-numeric label strings (like `"SomeFrame"`, `"END"`) reach `// else: frame label — not yet supported` and silently do nothing.

**Fix:** After `strtol` fails, call `findFrameByLabel(frame_str)` (for root navigation) or the per-sprite label lookup function (for clip navigation).

### Bug 5: prevFrame/nextFrame Not in MovieClip Dispatch (goto_methods — SEGFAULT)

`actionCallMethod` on a MOVIECLIP dispatches: `gotoAndStop`, `gotoAndPlay`, `play`, `stop`, `removeTextField`. When called with `"prevFrame"` or `"nextFrame"`, the dispatch falls through to a code path that dereferences something invalid → segfault.

**Fix:** Add `prevFrame` and `nextFrame` cases to the MOVIECLIP dispatch in `actionCallMethod`.

### Bug 6: gotoAndStop/gotoAndPlay on MovieClip Targets Wrong Timeline (goto_methods)

Currently, when `clip.gotoAndStop(n)` is called from root context, `actionGotoFrame` is called. Since `ng_isInsideSprite()` returns false (we're not inside a sprite's frame execution), it navigates the ROOT timeline — ignoring which `mc` was the actual target.

`actionCallMethod` extracts `MovieClip* mc = (MovieClip*)obj_var.data.numeric_value` but never uses `mc` for the navigation.

**Fix:** New helper function `ng_gotoFrameByMC(app_context, mc, frame)` that:
1. Searches `ng_display[]` for entry where `instance_name == mc->name`
2. If found and is a sprite: sets `ng_display[i].current_frame = frame`, `is_playing = 0`, `mc->currentframe = frame + 1`
3. If not found (mc is root): falls through to root navigation

Similarly, `ng_gotoLabelByMC(app_context, mc, label)` searches the sprite's label table then calls `ng_gotoFrameByMC`.

### Bug 7: Out-of-Bounds Frame Handling (goto_frame2, goto_methods)

Current behavior for `actionGotoFrame(frame)`: `if (frame >= g_frame_count) return;` — out-of-bounds is a no-op.

goto_methods expects: `clip.gotoAndStop(999)` on a 3-frame sprite → frame 3 (clamped to max).

**Rules from test expectations:**
- Frame 0 (1-indexed) → frame_num=0, frame_num-1=-1, (u16)(-1)=65535 → 65535 >= frame_count → currently a no-op. Tests show gotoAndStop(0) stays at current frame — but this is equivalent to clamping (65535 clamps to last frame, which if you're already at last frame shows no movement). Actually: gotoAndStop(0) called when at frame 3 (3-frame sprite) → should clamp to max = frame 3 (no visible change). ✓ with clamping.
- Frame > frame_count → clamp to last frame
- Negative frame → no-op (stays at current frame). Implementation: frame_num < 1 after 1-indexed parsing → skip.

**Fix:** Change `if (frame >= g_frame_count) { return; }` to `if (frame >= g_frame_count) { frame = (u16)(g_frame_count - 1); }` in both `actionGotoFrame` and `ng_gotoFrameCurrentSprite`.

Note: Some very large numbers (2147483648, 4294967298) have specific expected outputs due to u16 arithmetic wrapping. These need careful investigation during implementation (see goto_methods test cases).

### Bug 8: Scene Navigation Missing (goto_frame2)

`gotoAndPlay('Scene 2', 1)` (2-argument form with scene name) is entirely unimplemented. This requires:
- Parsing `SWF_TAG_SCENE_AND_FRAME_DATA` (tag 86) in swf.cpp to get scene names and start frames
- Emitting scene data in tagMain.c
- Implementing 2-arg scene+frame form in `actionGotoFrame2` and `gotoAndStop`/`gotoAndPlay` methods

This is the most complex piece and is deferred to Phase 4.

---

## Implementation Plan

### Phase 1: Trivial Fixes (Bug 2 + partial Bug 3)

Expected tests affected: goto_label (partial)

#### 1a. Remove debug printf (action.c)

In `SWFModernRuntime/src/actionmodern/action.c` around line 10733:
```c
// DELETE THIS LINE:
printf("// GoToLabel: %s\n", label ? label : "(null)");
```

#### 1b. Parse root frame labels (swf.cpp)

In `SWFRecomp/src/swf.cpp`, the main tag loop `SWF_TAG_FRAME_LABEL` case:

```cpp
case SWF_TAG_FRAME_LABEL:
{
    // Parse null-terminated label string
    const char* label_str = reinterpret_cast<const char*>(swf_data.data() + cur_pos);
    std::string label(label_str);
    // Store: label → current in-progress frame index (0-based)
    // next_frame_i tracks which root frame we're building (increments on SWF_TAG_SHOW_FRAME)
    frame_labels[label] = next_frame_i;
    cur_pos += tag.length;
    break;
}
```

Note: In SWF format, `FrameLabel` precedes `ShowFrame` in the same frame. `next_frame_i` at this point equals the 0-based index of the frame being built. Verify this against the test SWFs — if the label is off by 1, adjust to `next_frame_i - 1` (if ShowFrame already incremented by the time FrameLabel is seen) or keep as `next_frame_i`.

Verify after implementation:
```bash
python3 ruffle-tests/verify_output.py --test=goto_label --diff --verbose
```

### Phase 2: Frame Execution Ordering Fix (Bug 1)

Expected tests affected: goto_frame (likely pass), goto_label (likely pass), goto_frame2 (partial improvement)

**CRITICAL: This may affect currently-passing goto tests. Must verify after change.**

#### 2a. Remove ng_executeGotoCatchUp from actionGotoFrame (action.c ~line 10629)

```c
void actionGotoFrame(SWFAppContext* app_context, u16 frame)
{
    ...
    if (frame >= g_frame_count) { return; }

#ifdef NO_GRAPHICS
    extern int goto_from_action;
    goto_from_action = 1;
#endif

    next_frame = frame;
    manual_next_frame = 1;
    is_playing = 0;
    root_movieclip.currentframe = frame + 1;  // KEEP: update immediately for _currentframe reads

#ifdef NO_GRAPHICS
    // REMOVE these lines:
    // extern void ng_executeGotoCatchUp(SWFAppContext* app_context);
    // ng_executeGotoCatchUp(app_context);
#endif
}
```

The main loop's `while (goto_from_action && manual_next_frame)` block (swf_core.c:163) handles catch-up after the current frame script finishes. No behavior change for tests that don't read `_currentframe` after a goto — they just get the catch-up slightly later.

#### 2b. Remove ng_executeGotoCatchUp from actionGoToLabel (action.c ~line 10726)

Same treatment — keep `goto_from_action = 1` and the frame navigation, but remove the `ng_executeGotoCatchUp` call.

#### 2c. Regression check

After the ordering fix, verify these passing tests still pass:
```bash
python3 ruffle-tests/verify_output.py \
  --test=goto_advance1 --test=goto_advance2 \
  --test=goto_rewind1 --test=goto_rewind2 --test=goto_rewind3 \
  --test=goto_both_ways1 --test=goto_both_ways2 \
  --test=goto_execution_order --test=goto_execution_order2 \
  --test=goto_frame_number \
  --diff --verbose
```

If regressions occur, the ordering fix needs adjustment (e.g., checking catch_up_mode to suppress scripts only during catch-up is already in place).

### Phase 3: Fix prevFrame/nextFrame and Clip-Specific Navigation (Bugs 4, 5, 6)

Expected tests affected: goto_methods (segfault fixed, likely partial pass), goto_label (improved)

#### 3a. New helper: ng_gotoFrameByMC (tag_stubs.c)

Add to `SWFModernRuntime/src/libswf/tag_stubs.c`:

```c
// Navigate a specific MovieClip's sprite to a given 0-based frame.
// Searches ng_display for the entry matching mc->name.
// Returns 1 if sprite found and navigated, 0 if not found (root navigation fallback).
int ng_gotoFrameByMC(SWFAppContext* app_context, MovieClip* mc, u16 frame, int play)
{
    if (!mc) return 0;
    if (mc == &root_movieclip || mc->name[0] == '\0') return 0;

    for (size_t i = 0; i < ng_display_count; i++) {
        if (strcmp(ng_display[i].instance_name, mc->name) == 0) {
            size_t si = ng_display[i].sprite_idx;
            if (si == (size_t)-1) return 0;  // Not a sprite
            size_t fc = ng_sprites[si].frame_count;
            if (fc == 0) return 0;
            if (frame >= (u16)fc) frame = (u16)(fc - 1);  // Clamp to last frame
            ng_display[i].current_frame = frame;
            ng_display[i].is_playing = play ? 1 : 0;
            mc->currentframe = (int)frame + 1;  // 1-indexed
            // TODO: decide if the target frame function should run immediately or on next tick
            return 1;
        }
    }
    return 0;
}
```

Declare in `SWFModernRuntime/include/libswf/tag.h`:
```c
int ng_gotoFrameByMC(SWFAppContext* app_context, MovieClip* mc, u16 frame, int play);
```

#### 3b. Add prevFrame and nextFrame to MOVIECLIP dispatch (action.c ~line 22284)

Inside the `else if (obj_var.type == ACTION_STACK_VALUE_MOVIECLIP)` block, add before the final fallthrough:

```c
else if (method_name_len == 9 && strncmp(method_name, "prevFrame", 9) == 0)
{
    if (mc) {
        int cf = mc->currentframe - 1;  // go to previous (1-indexed, so -1 gives new 1-indexed)
        if (cf < 1) cf = 1;  // clamp to frame 1
        u16 frame0 = (u16)(cf - 1);  // convert to 0-indexed
        if (!ng_gotoFrameByMC(app_context, mc, frame0, 0)) {
            // Root navigation fallback
            if (current_frame > 0) {
                next_frame = current_frame - 1;
                manual_next_frame = 1;
                is_playing = 0;
                root_movieclip.currentframe = (int)next_frame + 1;
            }
        }
    }
    if (args) FREE(args);
    pushUndefined(app_context);
    return;
}
else if (method_name_len == 9 && strncmp(method_name, "nextFrame", 9) == 0)
{
    if (mc) {
        int cf = mc->currentframe + 1;
        u16 frame0 = (u16)(cf - 1);  // convert to 0-indexed
        if (!ng_gotoFrameByMC(app_context, mc, frame0, 0)) {
            // Root navigation fallback
            next_frame = current_frame + 1;
            if (next_frame >= g_frame_count) next_frame = g_frame_count - 1;
            manual_next_frame = 1;
            is_playing = 0;
            root_movieclip.currentframe = (int)next_frame + 1;
        }
    }
    if (args) FREE(args);
    pushUndefined(app_context);
    return;
}
```

#### 3c. Fix gotoAndStop/gotoAndPlay to use ng_gotoFrameByMC

In the `gotoAndStop` case (~line 22288): after resolving `frame_num`, replace:
```c
if (frame_num > 0) {
    actionGotoFrame(app_context, (u16)(frame_num - 1));
}
```
With:
```c
if (frame_num > 0) {
    u16 frame0 = (u16)(frame_num - 1);
    if (!ng_gotoFrameByMC(app_context, mc, frame0, 0)) {
        actionGotoFrame(app_context, frame0);
    }
}
```

Similarly for `gotoAndPlay`: use `ng_gotoFrameByMC(app_context, mc, frame0, 1)`.

#### 3d. Add string label lookup in gotoAndStop/gotoAndPlay dispatch

For the STRING case in gotoAndStop/gotoAndPlay method dispatch, after strtol fails:
```c
// After: char* endptr; long parsed = strtol(...);
// if strtol failed (endptr == frame_part || *endptr != '\0'):
int label_frame = findFrameByLabel(frame_str);  // root label lookup
if (label_frame >= 0) {
    frame_num = label_frame + 1;  // findFrameByLabel returns 0-based; convert to 1-based for below
}
// TODO: per-sprite label lookup (Phase 3e)
```

#### 3e. Per-sprite label tables (complex)

For `clip.gotoAndStop('END')` to find the "END" label in the clip's sprite frames:

**Recompiler changes (swf.cpp):**

In the sprite sub-loop, add per-sprite label tracking:
```cpp
// In SWF class, alongside frame_labels:
std::unordered_map<size_t, std::unordered_map<std::string, size_t>> sprite_frame_labels;
// char_id -> (label_string -> 0-based frame index)
```

In the sprite sub-loop `SWF_TAG_FRAME_LABEL` case:
```cpp
case SWF_TAG_FRAME_LABEL:
{
    const char* label_str = reinterpret_cast<const char*>(swf_data.data() + cur_pos);
    std::string label(label_str);
    sprite_frame_labels[current_sprite_char_id][label] = sprite_frame_i;
    cur_pos += sub_tag.length;
    break;
}
```

**Emit per-sprite label tables (swf.cpp, after sprite table emission):**

For each sprite with labels, emit:
```c
FrameLabelEntry sprite_CHARID_frame_labels[] = {
    { "END", 4 },
    { NULL, 0 }
};
size_t sprite_CHARID_frame_label_count = 1;
```

And modify `tagDefineSpriteChar(char_id, ...)` to accept a label pointer:
```c
tagDefineSpriteChar(char_id, funcs, frame_count, sprite_CHARID_frame_labels, sprite_CHARID_frame_label_count);
```

**Runtime changes (tag_stubs.c):**

Extend `ng_sprites[]` struct:
```c
struct {
    size_t char_id;
    frame_func* funcs;
    size_t frame_count;
    FrameLabelEntry* labels;   // NEW: per-sprite label table
    size_t label_count;        // NEW
} ng_sprites[MAX_SPRITES_NG];
```

Add `ng_gotoLabelByMC` helper:
```c
int ng_gotoLabelByMC(SWFAppContext* app_context, MovieClip* mc, const char* label, int play)
{
    if (!mc || !label) return 0;
    if (mc == &root_movieclip || mc->name[0] == '\0') return 0;
    for (size_t i = 0; i < ng_display_count; i++) {
        if (strcmp(ng_display[i].instance_name, mc->name) == 0) {
            size_t si = ng_display[i].sprite_idx;
            if (si == (size_t)-1) return 0;
            for (size_t j = 0; j < ng_sprites[si].label_count; j++) {
                if (ng_sprites[si].labels[j].label &&
                    strcmp(ng_sprites[si].labels[j].label, label) == 0) {
                    return ng_gotoFrameByMC(app_context, mc,
                                            (u16)ng_sprites[si].labels[j].frame, play);
                }
            }
            return 0;  // Label not found in sprite
        }
    }
    return 0;
}
```

Then in gotoAndStop/gotoAndPlay method dispatch for STRING case: if strtol fails, try `ng_gotoLabelByMC` first, then `findFrameByLabel` (root).

### Phase 4: Edge Case Frame Numbers (goto_frame2 + goto_methods improvements)

#### 4a. Out-of-bounds clamping

Change in `actionGotoFrame` (action.c) and `ng_gotoFrameCurrentSprite` (tag_stubs.c):
```c
// Change:
if (frame >= g_frame_count) { return; }
// To:
if (frame >= (u16)g_frame_count) { frame = (u16)(g_frame_count - 1); }
```

Also in `ng_gotoFrameByMC`.

#### 4b. Large integer handling in actionGotoFrame2 and method dispatch

The current F64 → s32 cast for large values like 2147483648.0 is undefined behavior in C. Flash appears to use u16 arithmetic for the final frame index. Proposed safe implementation:

```c
// For F64 case:
double d; memcpy(&d, &args[0].data.numeric_value, sizeof(double));
if (isnan(d) || isinf(d)) { /* no-op */ break; }
// Use floor then clamp to u32 range before converting
if (d < 1.0) { /* no-op (frame 0 / negative) */ break; }
u32 frame_u32 = (u32)(u64)d;  // safe truncation via u64 intermediary
u16 frame0 = (u16)((frame_u32 - 1) & 0xFFFF);  // u16 arithmetic
frame_num = (s32)frame0 + 1;  // back to 1-indexed for existing logic
```

This matches the goto_methods test expectations (4294967298 → u16 truncation → frame 2).

#### 4c. Boolean/undefined/null frame arguments in actionGotoFrame2

In `actionGotoFrame2` (action.c):
- BOOLEAN: `frame_var.data.numeric_value & 1` → 0 (false) or 1 (true). frame_num=0 → no-op, frame_num=1 → frame 1. Currently handled but check test expectations.
- UNDEFINED/NULL: currently `!resolved` → return (no-op). Tests confirm this is correct for gotoAndStop(undefined).
- However, goto_frame2 shows gotoAndStop(undefined) → frame 12 and gotoAndStop(false) → frame 13. These traces happen AFTER the goto, and the frame numbers shown may simply be the _currentframe value AFTER the catch-up ran frames 12 and 13. This will become clear once the ordering fix is in place.

#### 4d. Object toString coercion for frame argument (goto_methods: `gotoAndStop({toString: ...})`)

In the gotoAndStop/gotoAndPlay method dispatch, handle OBJECT type by calling toString():
```c
else if (args[0].type == ACTION_STACK_VALUE_OBJECT ||
         args[0].type == ACTION_STACK_VALUE_FUNCTION) {
    // Call toString() on the object
    char buf[256];
    actionVarToString(app_context, &args[0], buf, sizeof(buf));
    // Then try label lookup with buf
    int lf = ng_gotoLabelByMC(app_context, mc, buf, play_flag);
    if (!lf) {
        int rf = findFrameByLabel(buf);
        if (rf >= 0) frame_num = rf + 1;
        else { /* strtol attempt */ }
    }
}
```

### Phase 5: Scene Navigation (goto_frame2 full pass)

This is the most complex phase and addresses the 2-argument `gotoAndPlay('Scene 2', 1)` form.

#### 5a. Parse SWF_TAG_SCENE_AND_FRAME_DATA (tag 86) in swf.cpp

Tag format (SWF spec):
- SceneCount: EncodedU32
- For each scene: Offset (EncodedU32) + Name (STRING)
- FrameLabelCount: EncodedU32
- For each label: FrameNum (EncodedU32) + Name (STRING)

Parse and store:
```cpp
struct SceneEntry { std::string name; size_t start_frame; };
std::vector<SceneEntry> scenes;
```

#### 5b. Emit scene data in tagMain.c

```c
typedef struct { const char* name; size_t start_frame; size_t frame_count; } SceneEntry;
SceneEntry scene_data[] = {
    { "Scene 1", 0, 13 },
    { "Scene 2", 13, 15 },
    { NULL, 0, 0 }
};
size_t scene_count = 2;
```

#### 5c. Runtime scene resolution

Add `findSceneByName(label)` helper that returns the scene's start_frame offset.

For `actionGotoFrame2` 2-arg form (scene_bias != 0): scene_bias is already passed. The PUSH bytecode sequence for `gotoAndPlay('Scene 2', 1)` likely pushes the scene name and frame number separately; the `scene_bias` mechanism in the current `actionGotoFrame2` uses a compile-time bias embedded in the opcode data — this needs investigation to understand how the 2-argument form is actually compiled.

Alternative: Flash may emit `ActionGotoFrame2` with `scene_bias=0` but with a 2-element stack (scene string + frame), or it may use a different mechanism entirely. Read the generated script for goto_frame2 to understand the exact bytecode pattern.

---

## Files to Modify

### Recompiler (SWFRecomp/)

| File | Changes |
|------|---------|
| `src/swf.cpp` | Phase 1: Parse SWF_TAG_FRAME_LABEL in main loop; Phase 3e: Parse sprite frame labels; Phase 5: Parse SWF_TAG_SCENE_AND_FRAME_DATA |

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | Phase 1: Remove debug printf; Phase 2: Remove ng_executeGotoCatchUp calls; Phase 3: Add prevFrame/nextFrame dispatch; fix gotoAndStop/gotoAndPlay to use mc-specific navigation; add string label lookup |
| `src/libswf/tag_stubs.c` | Phase 3: Add ng_gotoFrameByMC, ng_gotoLabelByMC; extend ng_sprites struct with labels; fix ng_gotoFrameCurrentSprite clamping |
| `include/libswf/tag.h` | Phase 3: Declare ng_gotoFrameByMC, ng_gotoLabelByMC |

---

## Test-by-Test Analysis

### goto_label (4 frames, 13 lines expected)

**Needs:** Phase 1 (debug printf + root frame labels) + Phase 2 (ordering) + Phase 3e (sprite labels for "END")

After Phase 1+2: output probably looks like:
```
// frame 1
// gotoAndStop('INVALID')
1                              ← correct (INVALID label not found, stays at frame 1)
// frame 2
// gotoAndPlay('SomeFrame')
3                              ← correct (currentframe after goto, ordering fixed)
// frame 3
// frame 4
// clip.run()
   // gotoAndStop('END')
???                            ← needs sprite label "END"
```

After Phase 3e: sprite "END" label resolved → complete pass expected.

### goto_frame (3 frames, 12 lines expected)

**Needs:** Phase 2 (ordering) + Phase 3c (clip.gotoAndStop on sprite) + Phase 4a (out-of-bounds clamping?)

After Phase 2: ordering correct for root gotos.
After Phase 3c: `clip.run()` → `gotoAndStop(5)` navigates the sprite correctly.
Expected to pass after Phases 2+3.

### goto_methods (1 frame, SEGFAULT → 20 lines expected)

**Needs:** Phase 3 (prevFrame/nextFrame + clip-specific nav) + Phase 4 (edge cases) + Phase 3e (sprite labels for 'TheFrame') + toString coercion

After Phase 3: segfault fixed, basic gotoAndStop/gotoAndPlay/prevFrame/nextFrame on clip work.
After Phase 3e: string label navigation.
After Phase 4b: large integer handling.
Full pass requires all phases.

### goto_frame2 (5 frames, 28 lines expected)

**Needs:** Phase 2 + Phase 3 + Phase 3e + Phase 4 + Phase 5 (scene navigation for 'Scene 2' calls)

Partial improvement expected after each phase. Full pass requires Phase 5.

---

## Phase Impact Estimate

| Phase | Expected New Passes | Notes |
|-------|--------------------|----|
| 1 | goto_label (partial) | Debug printf + root labels |
| 1+2 | goto_label (likely PASS), goto_frame (likely PASS) | Ordering fix critical |
| 1+2+3 | goto_methods (segfault → partial), goto_label PASS | Sprite-specific nav |
| 1+2+3+4 | goto_methods likely PASS | Edge cases |
| all | goto_frame2 likely PASS | Scene nav is last piece |

---

## Verification Commands

```bash
# After Phase 1:
python3 ruffle-tests/verify_output.py --test=goto_label --diff --verbose

# After Phase 2:
python3 ruffle-tests/verify_output.py \
  --test=goto_frame --test=goto_label --diff --verbose
# Regression check:
python3 ruffle-tests/verify_output.py \
  --test=goto_advance1 --test=goto_advance2 \
  --test=goto_rewind1 --test=goto_rewind2 --test=goto_rewind3 \
  --test=goto_both_ways1 --test=goto_both_ways2 \
  --test=goto_execution_order --test=goto_execution_order2 \
  --test=goto_frame_number --diff --verbose

# After Phase 3:
python3 ruffle-tests/verify_output.py \
  --test=goto_frame --test=goto_label --test=goto_methods --diff --verbose

# After Phase 4:
python3 ruffle-tests/verify_output.py \
  --test=goto_frame2 --test=goto_methods --diff --verbose
```

---

## Key Invariants to Preserve

1. **catch_up_mode flag**: The main loop uses `catch_up_mode=1` to suppress script execution during intermediate frames in a goto. This is already in the main loop's while block and must be preserved.

2. **goto_from_action flag**: Set in `actionGotoFrame` to signal the main loop that a goto happened mid-action. After removing inline ng_executeGotoCatchUp, this flag becomes the sole signal to the main loop. It's already set before the removed call.

3. **root_movieclip.currentframe updates immediately**: The `_currentframe` property must read the new frame number immediately after `gotoAndStop`/`gotoAndPlay` is called, even before the target frame's scripts run. The `root_movieclip.currentframe = frame + 1` assignment in `actionGotoFrame` must remain.

4. **Sprite currentframe sync**: When navigating a sprite via `ng_gotoFrameByMC`, also update `mc->currentframe = frame + 1` so that `clip._currentframe` reads correctly.
