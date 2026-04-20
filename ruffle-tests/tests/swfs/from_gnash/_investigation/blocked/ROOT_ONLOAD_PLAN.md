# trace-as2/root_onload Plan (gnash/misc-swfmill) — BLOCKED
<!-- TESTS: trace-as2/root_onload -->

Test: `ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/trace-as2/root_onload/`
Status: `output_mismatch`, 2/4 (50%). Test has `known_failure = true` with `output.ruffle.txt` sidecar.

## Status (2026-04-19)

**BLOCKED** — fixing requires implementing Ruffle's priority-based ActionQueue. The
isolated runtime change to make sprite Phase 2 init fire before the parent script
(needed for this test) regresses `clip_events`, `execution_order1`, `execution_order4`,
and `register_and_init_order` because those tests rely on Ruffle's queue model where
INITIALIZE (priority 2) and CONSTRUCT (priority 1) drain before normal DoAction (priority 0).

## Test shape (reverse-engineered)

Three scripts, three traces, plus a root `onLoad` handler installed but never explicitly called:

| Script | Trace | Location |
|--------|-------|----------|
| `script_0` | `CC.` | inside `sprite_1_frame_0` (inner sprite) |
| `script_1` | `C.`  | inside `sprite_2_frame_0` (outer sprite, which places sprite_1 at depth 1) |
| `script_2` | `R.`  | root's `frame_0` DoAction — also runs `actionDefineFunction("onLoad", ...)` which traces `L.` |

SWF tag order in root frame_0:
```
PlaceObject2 idref=2 depth=1   (sprite_2 places sprite_1 inside it)
DoAction "R." + define onLoad
ShowFrame
```

Expected (Flash): `CC.`, `C.`, `R.`, `L.`
Ruffle (`output.ruffle.txt`): `CC.`, `C.`, `R.` (no `L.`)
Ours: `R.`, `C.`, `CC.`, `L.` (correct contents, wrong order for first three)

## Why this is blocked

Ruffle's `ActionQueue` (`core/src/context.rs:496-533`) uses 3 priorities:
- `Initialize` (priority 2) — clipActions onClipEvent(initialize)
- `Construct` (priority 1) — clipActions onClipEvent(construct)
- `Normal` (priority 0) — DoAction tags, LOAD events, EnterFrame, etc.

`pop_action` drains highest priority first, FIFO within priority.

When a sprite is placed via `instantiate_child` (`movie_clip.rs:1410`), Ruffle:
1. `post_instantiation`: queues clip's INITIALIZE/CONSTRUCT events (priorities 2/1)
2. `enter_frame`: queues clip's LOAD event (priority 0)
3. `run_frame_avm1`: tag-iterates the sprite's frame_0, recursively placing children
   (each recursing through 1-3) and queueing the sprite's own DoAction (priority 0)

The whole frame's actions accumulate, then `Player::run_actions` drains them in
priority order. This naturally gives:
- All INITIALIZEs before CONSTRUCTs before LOADs/DoActions
- DoActions in tag-iteration order (which is depth-first since PlaceObject recurses)

Our model fires INITIALIZE/CONSTRUCT **synchronously** at `tagPlaceObject2`
(`SWFModernRuntime/src/libswf/tag.c`), and emits DoAction inline (after PlaceObject
in the recompiler-generated code). Sprite Phase 2 init runs in `tagShowFrame`
**after** the parent's DoAction. There's no priority concept.

## What we tried (2026-04-19)

Two coordinated changes attempted; both reverted because of regressions:

1. **Recurse-first in `process_sprite_init_at_depth` when `was_eager`**: process
   children's Phase 2 before running this sprite's frame_0 (script_only). Matches
   the deepest-first ordering needed by `root_onload` (CC. before C.). Breaks
   `clip_events` because Ruffle's actual order has the parent's frame_0 DoAction
   before the child's LOAD event (since the SWF emits parent DoAction before
   PlaceObject(child), so it's queued first at priority 0).

2. **Phase 2 sprite init inside `tagFlushPendingEnterFrame`** (gated on
   `!g_defer_sprite_init && !catch_up_mode && !g_tag_skip_mode && !g_in_action_call`):
   the recompiler emits `tagFlushPendingEnterFrame` between PlaceObject and DoAction,
   so this puts sprite Phase 2 init before the parent's script — what `root_onload`
   needs. Breaks `clip_events`, `execution_order1/4`, `register_and_init_order`:
   their SWFs have a root DoAction *before* PlaceObject in the same frame, and
   Ruffle's priority queue still defers the DoAction until INITIALIZE/CONSTRUCT
   queue items drain — without a priority queue we have no way to do that.

A recompiler change to emit DoAction inline at its tag position (instead of
batched at frame end) was also tried, in combination with the runtime changes.
This makes our DoAction respect tag-iteration order — but the same priority-queue
issue remains: tests with INITIALIZE clip events (e.g. `clip_events`) still
break because their root DoAction is queued first in tag order yet expected to
run after the priority-2 INITIALIZE events.

## What it would take to fix

Implement a global ActionQueue with at least 3 priorities (Initialize, Construct,
Normal). Move all INITIALIZE/CONSTRUCT/LOAD/DoAction firings from synchronous
execution at `tagPlaceObject2` and `process_sprite_needs_init` into queue inserts.
Drain the queue at the appropriate frame boundaries.

See `ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/ACTION_QUEUE_PLAN.md` for the full
cross-suite architectural plan: Ruffle model summary, comprehensive map of every
synchronous firing site in our runtime, ad-hoc queues that would be unified,
phased migration order, canary test list, known latent bugs that the rework
risks re-exposing, and effort estimate.

This is a substantial architectural change touching `tag.c`, `swf_core.c`,
recompiler-emitted DoAction call sites, sprite eager-init flow, and goto
catch-up. Estimated risk: many existing passing tests would need re-verification.

## Recommendation

Leave `root_onload` as `output_mismatch` (50%). The test carries `known_failure = true`
upstream and our diff against `output.txt` (4 lines, wrong order, plus matching `L.`)
is **not** a subset of Ruffle's diff (just missing `L.`), so we don't get the
`ruffle_matched` auto-promotion. To get `ruffle_matched`, our output would need to
match Ruffle's exact 3 lines (`CC.`, `C.`, `R.`) — that requires the same
priority-queue architectural change, plus suppressing `_root.onLoad` (which Flash
fires but Ruffle does not).

## Related

- `from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md` covers
  `timeline/timeline_as2_1` and `timeline/timeline_as2_5`, same root cause.
- AVM1 tests already passing the priority-queue order (via existing synchronous
  model + recompiler emission): `execution_order1-4`, `goto_execution_order`,
  `goto_execution_order2`, `clip_events`, `clip_constructors`,
  `clip_event_propagation_order`, `on_construct`, `register_and_init_order`,
  `issue_1104`, `button_order`, `goto_rewind3`. Any priority-queue rework must
  preserve these.
- `complete/RUFFLE_KNOWN_FAILURE_HANDLING_PLAN.md`: `ruffle_matched` mechanism.
- Ruffle source: `core/src/context.rs:488-533` (ActionQueue),
  `core/src/display_object/movie_clip.rs:1410-1492` (`instantiate_child`,
  recursive `run_frame_avm1`), `core/src/display_object/movie_clip.rs:1970-1994`
  (Initialize/Construct queueing in `post_instantiation`).
