# CONSTRUCT Parameter Replay Plan
<!-- TESTS: netstream_play_flv_screen, on_construct -->

<!-- PLAN_META
id: CONSTRUCT_PARAMETER_REPLAY
status: blocked
phases:
  - id: 1
    name: "Investigate Flash's actual SetVariable/addProperty behavior during CONSTRUCT"
    status: blocked
  - id: 2
    name: "Implement CONSTRUCT parameter capture"
    status: blocked
  - id: 3
    name: "Implement post-constructor parameter replay"
    status: blocked
  - id: 4
    name: "Validate with FLVPlayback component"
    status: blocked
dependencies:
  - plan: FLV_PLAYBACK
    phases: [5, 6, 7, 8]
    type: extends
    reason: "FLVPlayback component video rendering is the motivating use case"
blockers:
  - "Phase 1 requires real Flash Player access to determine whether SetVariable during CONSTRUCT invokes addProperty setters from __proto__ — no Flash Player is available in this environment"
  - "Motivating test (netstream_play_flv_screen image) is marked with_renderer = { optional = true } — Ruffle has the same limitation, so there is no reference output to promote against"
-->

Last updated: 2026-04-18

## Status: BLOCKED — Phase 1 investigation requires real Flash Player access

## 2026-04-18 re-assessment

Every trace test in this plan's scope is already PASSING in the current CI run
(`c3aa8876`, AVM1 results.json):

| Test | Status | Lines |
|------|--------|-------|
| on_construct | PASS | 25/25 |
| netstream_play_flv | PASS | 21/21 |
| netstream_play_flv_screen | PASS | 0/0 (zero expected lines) |
| netstream_seek_flv | PASS | 25/25 |
| register_and_init_order | PASS | 231/231 |
| register_class_return_value | PASS | 16/16 |

Local re-runs of `on_construct` and `netstream_play_flv_screen` confirm PASS.

The plan's remaining goal is FLVPlayback **video rendering** (image output),
not any trace test. Progress here is gated on:

1. Flash Player behavior investigation (Phase 1) — no Flash Player available.
2. A reference image to compare against — Ruffle has the same limitation, and
   the image comparison in `netstream_play_flv_screen/test.toml` is
   `with_renderer = { optional = true }`.

Moved from `incomplete/` to `blocked/` pending either Flash Player access or
a reference rendering from an alternative source.

## Problem Statement

Flash fires CONSTRUCT clip events BEFORE the registerClass constructor (confirmed by
Ruffle source code and the `on_construct` test). This ordering causes a problem for
components like FLVPlayback where:

1. CONSTRUCT clip actions set component parameters (e.g., `contentPath = "rufflelogo.flv"`)
   via `SetVariable`, which invokes addProperty setters on the registered class prototype
2. The setter (`__set__contentPath`) checks if `_vp[_activeVP]` exists — it doesn't yet
   (constructor hasn't run) — so it stores `_contentPath` but does NOT call `play()`/`load()`
3. The registerClass constructor fires, creates `_vp` via `createVideoPlayer(1, 0)`
4. The constructor checks `_contentPath != undefined` → true (stored by setter) → skips default
5. The constructor NEVER re-invokes the contentPath setter
6. Result: `_contentPath` is set, `_vp` exists, but `play()` is never called

The reversed ordering (constructor before CONSTRUCT) was tried in commit 923d9eb8 but
broke `on_construct` (25/25 → 0/25) and was reverted in 53aae9c5.

Ruffle also has this limitation — the `netstream_play_flv_screen` test has 0 expected
trace lines and `with_renderer = { optional = true }`.

## Investigation Findings

### What was ruled out

1. **V2 component lifecycle (`callLater`/`invalidate`/`draw`)**: FLVPlayback does NOT
   use these mechanisms. Grep of the entire 93K-line component code found zero references
   to `callLater`, `doLater`, or `invalidate`. Implementing V2 lifecycle alone would not
   fix this issue.

2. **Constructor re-trigger**: The FLVPlayback constructor explicitly checks if
   `_contentPath` is already set and SKIPS initialization (doesn't re-invoke the setter).
   It processes `_cuePoints` but not `_contentPath`.

3. **Deferred callbacks**: FLVPlayback doesn't set up `onLoad`, `onEnterFrame`, or timer
   callbacks during construction that would re-process contentPath.

4. **Frame-based trigger**: The FLVPlayback sprite is stopped at frame 0 (`script_0` calls
   `actionStop()`). Frame 1 (which places the VideoPlayer sprite) never runs during
   normal initialization — `createVideoPlayer` handles this programmatically.

### The contentPath setter flow (`func2_anonymous_49` in script_defs.c)

```
register layout: reg[1]=this, reg[2]=_global, reg[3]=args[0] (new value)

if (_global.isLivePreview) return undefined;

videoPlayer = this._vp[this._activeVP];
if (videoPlayer == undefined) {
    // VideoPlayer doesn't exist yet (pre-constructor)
    if (reg[3] == this._contentPath) return undefined;  // no change
    this._contentPath = reg[3];                          // just store it
    goto end;
}
// VideoPlayer exists (post-constructor)
if (videoPlayer.url == reg[3]) return undefined;  // same URL, no-op
videoPlayer.minProgressPercent = undefined;
// ... reset state ...
_cpMgr[_activeVP].reset(0);
if (_vpState[_activeVP].autoPlay && !_firstStreamShown) {
    _vp[_activeVP].play(reg[3], isLive, totalTime);
} else {
    _vp[_activeVP].load(reg[3], isLive, totalTime);
}
_vpState[_activeVP].isLiveSet = false;
_vpState[_activeVP].totalTimeSet = false;
end:
return this.__get__contentPath(0);
```

### Key question: Does Flash's `SetVariable` invoke addProperty setters from `__proto__`?

Our runtime's `actionSetVariable` on non-root MCs (line 31546 in action.c) calls
`findPropertyStructWithPrototype()` which walks the `__proto__` chain, finding addProperty
setters registered on the registered class prototype. If Flash does NOT walk `__proto__`
for addProperty during `SetVariable`, the behavior would be different:

- `SetVariable("contentPath", "rufflelogo.flv")` would store `contentPath` as a plain
  dynamic property on the MC, NOT invoke the setter, and NOT store `_contentPath`
- The constructor would find `_contentPath == undefined` and set it to `""`
- The plain `contentPath` property would be shadowed by the addProperty getter (which
  returns `_contentPath`), making the CONSTRUCT value invisible to normal property access

This hypothesis needs to be tested against real Flash Player behavior (Phase 1).

### CONSTRUCT clip action code (FLVPlayback test)

The CONSTRUCT handler (`clip_action_1` in script_1.c) sets 12 properties via `SetVariable`:

| Property | Value |
|----------|-------|
| autoPlay | true |
| autoRewind | true |
| autoSize | false |
| bufferTime | 0.7 |
| **contentPath** | **"rufflelogo.flv"** |
| isLive | false |
| maintainAspectRatio | true |
| skin | "" |
| skinAutoHide | false |
| totalTime | 0 |
| version_1_0_2 | "" |
| volume | 100 |

All of these potentially have addProperty setters on the registered class prototype.

## Proposed Approach: Post-Constructor Parameter Replay

### Phase 1: Investigate Flash's actual behavior

**Goal**: Determine whether Flash's `SetVariable` during CONSTRUCT invokes addProperty
setters from `__proto__`, or stores values as plain properties.

**Method**: Create a test SWF with:
- A registered class with addProperty for a property (e.g., `testProp`)
- The addProperty setter traces when called
- CONSTRUCT clip action sets `testProp` via component parameters
- Check whether the setter trace appears before or after the constructor trace

**Test cases**:
1. Does `SetVariable` during CONSTRUCT invoke addProperty setter from `__proto__`?
2. If not, where does the CONSTRUCT value end up? (plain MC property? local scope?)
3. After construction, can the CONSTRUCT value be read? Through what mechanism?
4. Does Flash have a post-constructor "parameter application" phase?

**Resources**: A real Flash Player test, or careful analysis of Ruffle's `set_variable`
implementation for MovieClips.

### Phase 2: Implement CONSTRUCT parameter capture

Based on Phase 1 findings, implement one of:

**Option A — SetVariable bypass during CONSTRUCT** (if Flash doesn't invoke setters):
- Add a flag (e.g., `g_in_construct_clip_action`) set during CONSTRUCT clip event dispatch
- When this flag is set, `actionSetVariable` stores values as plain MC properties
  WITHOUT invoking addProperty setters from `__proto__`
- Values are stored in a separate "component parameter" registry on the MC

**Option B — Parameter capture list** (if Flash uses a replay mechanism):
- During CONSTRUCT clip actions, record each `SetVariable` name/value pair in a
  per-MC parameter list
- After the constructor completes, replay these through the setter mechanism
- This is a clean approach that doesn't modify SetVariable semantics

### Phase 3: Implement post-constructor parameter replay

After `actionInvokeRegisteredClassConstructor()` completes in `tagPlaceObject2`:

```c
// After constructor fires:
if (mc has captured CONSTRUCT parameters) {
    for each (name, value) in captured parameters:
        re-invoke the addProperty setter for this property
}
```

**Key implementation details**:
- Parameter replay must happen AFTER the constructor completes (so _vp exists)
- Only replay properties that have addProperty setters on the prototype chain
- Replay in the same order as the original CONSTRUCT clip action set them
- The setter may have side effects (play/load), which is the desired behavior

**Storage**: A simple array on the MC or a global pending-replay queue:
```c
typedef struct {
    char* name;
    u32 name_len;
    ActionVar value;
} ConstructParam;

#define MAX_CONSTRUCT_PARAMS 32
ConstructParam g_construct_params[MAX_CONSTRUCT_PARAMS];
u32 g_construct_param_count;
```

### Phase 4: Validate with FLVPlayback component

1. Run `on_construct` test — must still pass (25/25)
2. Run `netstream_play_flv_screen` — check if video frame is now decoded/rendered
3. Run `netstream_play_flv` and `netstream_seek_flv` — must still pass (no regression)
4. Run full test suite via CI to check for regressions

## Test Impact

| Test | Current | Expected After | Notes |
|------|---------|---------------|-------|
| on_construct | 25/25 PASS | 25/25 PASS | Must not regress |
| netstream_play_flv_screen | 0/0 PASS (trace) | 0/0 PASS (trace) + image | Image rendering should work |
| netstream_play_flv | 21/21 PASS | 21/21 PASS | Raw NetStream, unaffected |
| netstream_seek_flv | 25/25 PASS | 25/25 PASS | Raw NetStream, unaffected |
| register_and_init_order | 233/233 PASS | 233/233 PASS | Must not regress |
| register_class_return_value | 16/16 PASS | 16/16 PASS | Must not regress |

## Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| CONSTRUCT dispatch in tagPlaceObject2 | `tag.c` | ~3364-3397 |
| RegisterClass constructor invocation | `tag.c` | ~3404-3431 |
| actionSetVariable (non-root MC path) | `action.c` | ~31546-31574 |
| FLVPlayback contentPath setter | `script_defs.c` (netstream_play_flv_screen) | ~10234-10733 |
| FLVPlayback constructor | `script_defs.c` | ~29-957 |
| CONSTRUCT clip action | `script_1.c` (netstream_play_flv_screen) | ~5-84 |
| actionInvokeRegisteredClassConstructor | `action.c` | (search for function) |

## Alternative Approaches Considered

1. **Swap CONSTRUCT/constructor ordering**: Tried in commit 923d9eb8, broke `on_construct`.
   Flash definitively fires CONSTRUCT before constructor.

2. **V2 component lifecycle (`callLater`/`invalidate`)**: FLVPlayback doesn't use these.
   Implementing them wouldn't fix this specific issue. (May be useful for other components
   in the future, but is a separate concern.)

3. **Component-specific hack**: Detect FLVPlayback post-constructor and re-trigger
   contentPath. Too narrow — the CONSTRUCT parameter issue likely affects other components.

4. **onLoad-based deferred init**: FLVPlayback doesn't set up an onLoad handler for this
   purpose. The component expects contentPath to be processed synchronously.

## Dependencies

- **FLV_PLAYBACK_PLAN** (complete): Video decoding, NetStream, rendering pipeline all work.
  This plan extends FLV_PLAYBACK by fixing the component parameter initialization gap.
