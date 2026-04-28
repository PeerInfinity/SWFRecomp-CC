# DoInitAction Per-Frame Prologue Plan

<!-- TESTS: register_class/registerClassTest2, RegisterClassTest3, RegisterClassTest4, register_and_init_order, on_construct, resolve_different_root, from_shumway/avm1/doactionorder/symbolclass, do_init_action_child -->

<!-- PLAN_META
id: DOINITACTION_PER_FRAME_PROLOGUE
status: complete
phases:
  - id: 1
    name: "Per-frame init prologue buffer in recompiler"
    status: complete
  - id: 2
    name: "(movie_id, char_id) keying in tagDoInitActionGuarded"
    status: complete
  - id: 3
    name: "Catch-up / script-only replay gating + actionImportAssets idempotency"
    status: complete
  - id: 4
    name: "Regression sweep + retire tag_init_scripts buffer"
    status: complete
dependencies: []
blockers: []
-->

## Result (2026-04-27)

- **registerClassTest2**: 0/44 → 41/44 matching lines (`output_mismatch` → mostly-passing). The remaining 3 mismatched lines are independent of frame-init ordering (`clip2.getDepth() == undefined` MC built-in handler gating, theClass3 onLoad ordering between clipevs/clip3) — tracked in `REGISTERCLASS_LIFECYCLE_PLAN.md`.
- **register_and_init_order** 231/231 preserved.
- **on_construct** 25/25 preserved.
- **resolve_different_root** 2/2 preserved.
- **do_init_action_child** preserved (Phase 2 `(movie_id, char_id)` guard).
- **doactionorder/symbolclass** 4/4 preserved.

Implementation:
- `SWFRecomp/include/swf.hpp`: added `current_frame_init_actions`, `current_frame_marker_id`, `frame_init_emitted`, plus `writeFrameInitMarker` / `flushFrameInitPrologue` declarations.
- `SWFRecomp/include/context.hpp`: changed `tag_main` from `ofstream` to `stringstream` so the per-frame prologue placeholder marker can be replaced after parsing each frame.
- `SWFRecomp/src/recompilation.cpp`: dump `context.tag_main.str()` to `tagMain.c` at the end.
- `SWFRecomp/src/swf.cpp`:
  - `parseAllTags()` writes `/*__SWFRECOMP_PROLOGUE_<id>__*/` placeholder after each `frame_N` open brace.
  - `interpretTag()` `another_frame` block + `END_TAG` + truncation fallback all call `flushFrameInitPrologue` to replace the placeholder with the buffered prologue.
  - `SWF_TAG_DO_INIT_ACTION` (top-level) emits `if (!catch_up_mode || g_tag_skip_mode) tagDoInitActionGuarded(...)` into `current_frame_init_actions` instead of `tag_init_scripts`.
  - `SWF_TAG_IMPORT_ASSETS` / `IMPORT_ASSETS_2` emit `actionImportAssets` and `tagImportCharacter` into `current_frame_init_actions`.
- `SWFModernRuntime/src/libswf/tag.c`: `tagDoInitActionGuarded` widened to 2D `g_init_action_done[MAX_INIT_ACTION_MOVIES][MAX_INIT_ACTION_CHARS]` keyed on `g_current_movie_id` so parent and child SWFs sharing `char_id` don't shadow each other.

`tag_init_scripts` is now unused for top-level DoInitAction / ImportAssets but retained as an empty buffer for safety; its emission line in `tagInit()` is a no-op.

## Background

See `_investigation/DOINITACTION_TIMING_FINDINGS.md` for the full
research write-up. Tl;dr: Ruffle's two-pass model runs all of frame
N's DoInitAction / ExportAssets / ImportAssets during preload BEFORE
`run_frame_internal(N)` runs frame N's PlaceObject* / DoAction. Flash
matches this. Our recompiler currently hoists all top-level
DoInitActions into `tagInit()` (process-startup), which breaks tests
where a frame N≥1 DoInitAction depends on a prior frame's DoAction
state. A naive "emit inline in stream order" fix breaks the dual case
where a frame N PlaceObject2 needs a same-frame DoInitAction's
`Object.registerClass(...)` to have already run.

The fix is: buffer top-level DoInitAction (and ImportAssets) per
frame, and emit them at the START of `frame_N()`'s body, before any
of that frame's display / script tag emissions.

## Phase 1 — Per-frame init prologue buffer in recompiler

**Files**: `SWFRecomp/src/swf.cpp`, `SWFRecomp/include/swf.hpp`
(if member additions need a header decl).

**Add state** to the SWF parser:
```cpp
std::stringstream current_frame_init_actions;
bool frame_init_emitted = false;
```

**Helper**:
```cpp
void flushFrameInitPrologue(Context& context) {
    if (!frame_init_emitted &&
        !current_frame_init_actions.str().empty()) {
        context.tag_main << current_frame_init_actions.str();
    }
    frame_init_emitted = true;
}
```

**`SWF_TAG_DO_INIT_ACTION` (top-level, `swf.cpp:2612`)**: replace
```cpp
tag_init_scripts << endl << "\t" << func_name << "(app_context);";
```
with
```cpp
current_frame_init_actions
    << "\tif (!catch_up_mode || g_tag_skip_mode) "
    << "tagDoInitActionGuarded(app_context, "
    << init_sprite_id << ", " << func_name << ");"
    << endl;
```

**`SWF_TAG_IMPORT_ASSETS` / `SWF_TAG_IMPORT_ASSETS_2`
(`swf.cpp:4020-4053`)**: replace `tag_init_scripts << ...` writes
for `actionImportAssets` and `tagImportCharacter` with
`current_frame_init_actions << ...` (same gate
`(!catch_up_mode || g_tag_skip_mode)`). Preserve stream order with
DoInitAction within the same frame buffer — required by
`do_init_action_child`.

**Frame-body emission gate**: at the top of every frame-body-emission
case in `interpretTag` that writes a non-init tag to
`context.tag_main` (PlaceObject*, RemoveObject*, DoAction's
`actionQueueScript`, `tagSetBackgroundColor`, etc.), call
`flushFrameInitPrologue(context)` first. The simplest implementation
is to insert one call at the top of `interpretTag()` after the
`another_frame` block (`swf.cpp:826-834`), gated on the tag code not
being one of the init-prologue tag codes (DoInitAction, ImportAssets,
ImportAssets2) and not being a definition tag that goes to
`tag_init` (DefineShape, DefineSprite, etc., which don't emit to
`context.tag_main` for the current frame).

**Frame open / close**:
- At the frame-open sites (`swf.cpp:447-449` and the
  `another_frame` open block at `~828-833`):
  ```cpp
  current_frame_init_actions.str("");
  current_frame_init_actions.clear();
  frame_init_emitted = false;
  ```
- At `SWF_TAG_SHOW_FRAME` (`swf.cpp:886-917`) BEFORE the
  `tagFlushPendingEnterFrame` line, call
  `flushFrameInitPrologue(context)` to handle the corner case of a
  frame that contains only DoInitAction and no other tag emissions.

**`tagInit()` retirement of init scripts**: at
`swf.cpp:667-669`, after this phase lands `tag_init_scripts.str()`
should be empty. Either remove the emission line or keep it as a
no-op (the latter is safer for incremental landing).

**Acceptance for Phase 1**:
- Build succeeds; `register_and_init_order` still 233/233 (frame-0
  DoInitActions now emit inside `frame_0` prologue rather than
  `tagInit`, but still before frame-0 PlaceObject2).
- `on_construct` 25/25 preserved.
- `registerClassTest2` jumps from 0/44 to ≥41/44.

## Phase 2 — `(movie_id, char_id)` keying in `tagDoInitActionGuarded`

**File**: `SWFModernRuntime/src/libswf/tag.c:5257-5268`.

**Current**:
```c
#define MAX_INIT_ACTION_CHARS 512
static u8 g_init_action_done[MAX_INIT_ACTION_CHARS];

void tagDoInitActionGuarded(SWFAppContext* app_context, size_t char_id, frame_func action) {
    if (char_id < MAX_INIT_ACTION_CHARS && g_init_action_done[char_id])
        return;
    if (char_id < MAX_INIT_ACTION_CHARS)
        g_init_action_done[char_id] = 1;
    action(app_context);
}
```

**Replace with** a 2D guard keyed on `(g_current_movie_id, char_id)`:
```c
#define MAX_INIT_ACTION_MOVIES 8
#define MAX_INIT_ACTION_CHARS 512
static u8 g_init_action_done[MAX_INIT_ACTION_MOVIES][MAX_INIT_ACTION_CHARS];

extern u8 g_current_movie_id;

void tagDoInitActionGuarded(SWFAppContext* app_context, size_t char_id, frame_func action) {
    u8 movie = g_current_movie_id;
    if (movie >= MAX_INIT_ACTION_MOVIES) movie = 0;
    if (char_id < MAX_INIT_ACTION_CHARS && g_init_action_done[movie][char_id])
        return;
    if (char_id < MAX_INIT_ACTION_CHARS)
        g_init_action_done[movie][char_id] = 1;
    action(app_context);
}
```

**Why**: the prior reverted attempt established that parent and child
SWFs sometimes share `char_id=1` for their DoInitAction sprites,
which the single-dimension guard would shadow. Once the prologue
runs inside `frame_N`, the guard actually matters during script-only
target-frame replay (`g_tag_skip_mode=1`).

**Acceptance for Phase 2**:
- `do_init_action_child` still passes (it uses parent + child SWFs).
- No regressions on the 14-test AVM1 registerClass guardrail.

## Phase 3 — Catch-up / script-only replay gating + ImportAssets idempotency

**Gating recap**: every prologue line is wrapped in
`if (!catch_up_mode || g_tag_skip_mode) ...`. This ensures:
- Forward catch-up replay (`catch_up_mode=1, g_tag_skip_mode=0`)
  skips DoInitAction / ImportAssets — they fired during the
  original play-through.
- Script-only target-frame replay (`g_tag_skip_mode=1`) invokes the
  guarded call, which short-circuits via the
  `(movie_id, char_id)` table.

**`actionImportAssets` idempotency**: if it is not already
self-guarding, add a `(movie_id, url)` side dictionary inside the
runtime to no-op repeat invocations. Run `do_init_action_child`
locally first to determine whether this is needed — it may already be
idempotent.

**Acceptance for Phase 3**:
- `goto_execution_order`, `goto_execution_order2`, `execution_order2`,
  `execution_order3`, `goto_rewind1/2/3`, `goto_both_ways1/2` all
  preserved.
- `RegisterClassTest3` does not regress from current 11/12.

## Phase 4 — Regression sweep + retire `tag_init_scripts`

**Verification battery** (must all stay green / improve):

AVM1 registerClass core:
- `register_and_init_order` (233/233 — most fragile)
- `register_class_return_value` (16/16)
- `register_globals_across_frames`, `register_underflow`,
  `register_class_with_sound`
- `attach_movie`, `attach_movie_stop`, `export_assets`
- `clip_constructors`, `on_construct` (25/25),
  `movieclip_init_object`, `empty_movieclip_can_attach_movies`,
  `do_init_action_child`, `bad_placeobject_clipaction`
- `init_object_order` (15/15)

Misc-ming recently-fixed:
- `loop_test3`, `loop_test5`, `loop_test8`, `instanceNameTest`,
  `attachMovieTest`, `ResolveEventsTest`,
  `event_handler_scope_test`, `attach_movie_stop`,
  `movieclip_in_removed_button`, `clip_events`,
  `init_object_order`, `init_object_invalid`

Shumway:
- `from_shumway/avm1/doactionorder/symbolclass` (4/4)
- `from_shumway/avm1/doubleAndRegister`

Goto + lifecycle:
- `goto_execution_order`, `goto_execution_order2`,
  `execution_order2`, `execution_order3`,
  `goto_rewind1/2/3`, `goto_both_ways1/2`,
  `goto_frame`, `goto_frame2`, `goto_label`, `goto_methods`
- `unload`, `unload_clip_event`, `unload_nested_child`

Misc-swfc:
- `movieclip_destruction_test2` (50/52, must not regress),
  `stackscope`, `submoviegetvar`, `edittext_test1`

Misc-swfmill:
- `initaction_in_definesprite`, `dict_event`, `dict_override`

**Target test improvements**:
- `registerClassTest2`: 0/44 → ≥41/44 (recovers prior reverted result)
- Possibly other Group-A-shaped tests improve as a side effect.

**`tag_init_scripts` retirement**: once Phase 4 confirms no
regressions, delete the `tag_init_scripts` member, the emission line
in `tagInit()`, and the `endl` after it. Update any related
comments. (Optional cleanup; can defer.)

## Out of scope

- Remaining 3 lines on `registerClassTest2` after this lands
  (`clip2.getDepth() == undefined` MC built-in handler gating, and
  `clipevs.onLoad` / `clip3.onLoad` ordering) — those are independent
  of frame-init ordering and stay tracked in
  `REGISTERCLASS_LIFECYCLE_PLAN.md`.
- DoInitAction inside DefineSprite (`swf.cpp:5075-5111`) — Ruffle has
  the same nested arrangement and our existing emission is correct.

## Estimated session budget

- Phase 1: 2–3 hours (recompiler restructure + initial regression run).
- Phase 2: 30 minutes (one-file change + rebuild).
- Phase 3: 1 hour (gate audit, ImportAssets idempotency check on
  `do_init_action_child`).
- Phase 4: 1–2 hours (full guardrail sweep, cleanup).

Total: half a day to a day, plus CI sweep. The implementation is
mechanically straightforward; the cost is in regression vetting.

## Confidence

- Flash timing model: HIGH (logical necessity from Group A + Group B
  evidence).
- Ruffle behavior: HIGH (verified in source).
- Recompiler proposal: MEDIUM-HIGH (mechanical buffer redirection;
  risk concentrated in catch-up gating edge cases and any tag
  emission site that bypasses the prologue flush helper).
- Guard adjustments: MEDIUM-HIGH (prior reverted attempt validated
  the `(movie_id, char_id)` extension).
- Regression risk: MEDIUM (the
  `(!catch_up_mode || g_tag_skip_mode)` gating + script-only replay
  interaction is the most fragile piece).
