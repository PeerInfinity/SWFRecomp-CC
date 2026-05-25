# Defer Newly-Placed Sprites by One Tick — Plan

**Document Version:** 1.0
**Created:** 2026-05-24
**Status:** Planned; no implementation yet.

The divergence harness running on `~/CC/glaiel/swfs/Pong.swf` exposed a
class of timing bug in SWFRecomp's graphics-native and no-graphics paths:
sprites placed in tick N have their frame scripts advanced **inside the
same tick N**, where Ruffle defers them to tick N+1. Pong's preloader is
the most striking demonstration — its progress bar renders fully filled
on frame 1 in SWFRecomp vs empty in Ruffle, and `_root._currentframe`
reads one tick ahead in any user-installed `onEnterFrame`. The earlier
`_root.play()/stop()` fix (`6fe6fb1a2`) closed the worst-case symptom
(timeline frozen forever) but the underlying timing divergence remains
and surfaces wherever a placed sprite's first frame script affects state
visible on the same render tick.

## Table of contents
1. [Evidence](#evidence)
2. [What we know](#what-we-know)
3. [What we don't know yet](#what-we-dont-know-yet)
4. [Ruffle's behavior — the canonical reference](#ruffles-behavior--the-canonical-reference)
5. [SWFRecomp's current behavior](#swfrecomps-current-behavior)
6. [Investigation phase: confirm the model](#investigation-phase-confirm-the-model)
7. [Fix options](#fix-options)
8. [Recommended approach](#recommended-approach)
9. [Phases](#phases)
10. [Regression risks](#regression-risks)
11. [Verification](#verification)
12. [Out of scope](#out-of-scope)

---

## Evidence

Two-line summary from `tools/divergence/runs/Pong/divergence.txt`
post-`6fe6fb1a2`:

```
TRACER: start _currentframe=1     (both runtimes agree at init time)
F1 (Ruffle):    _currentframe=1   _root.instance2 / instance3 / progbar present
F1 (SWFRecomp): _currentframe=2   instance2 / instance3 / progbar already gone
```

PNGs at frame 1:
- **Ruffle**: preloader visible, progress bar **empty** (outline only).
- **SWFRecomp**: preloader visible, progress bar **fully filled black**.

The fill is set by `sprite_9_frame_1` (script_2):
```actionscript
pcent_loaded = (getBytesLoaded * 100) / getBytesTotal;
progbar._width = pcent_loaded;
```

That script ran *before* tick 1's render in SWFRecomp; in Ruffle it
hadn't run yet by that point. Same script causes the timeline divergence
because the same script also calls `_root.play()`.

The minimal controlled test (`/tmp/stop_test.swf` — 5 frames, frame 1
stop, no sprites) produces **identical** traces on both runtimes
(`F1=1`, `F2=1`, etc.), confirming the divergence is sprite-placement
specific, not a generic enterFrame ordering bug.

## What we know
- Both runtimes report identical state at tracer init time
  (`TRACER: start _currentframe=1`). Divergence is entirely in what
  happens between init and the first `onEnterFrame` fire.
- Same number of tracer ticks fire on both sides (F1..F19 for 20 frames
  requested).
- Sprites placed in frame_funcs[N] are walked by SWFRecomp's
  `advance_sprite_frames` *during the same tick N* — see
  `SWFModernRuntime/src/libswf/tag.c:760`. The iteration is over the
  current `display_list[]`, which already includes this tick's
  placements.
- Both `swf.c` (OFFSCREEN_RENDER / graphics-native) and `swf_core.c`
  (NO_GRAPHICS) call `advance_sprite_frames` at the same place in the
  tick loop (top, before root `frame_funcs[current_frame]`), so the bug
  affects both modes.
- The full Ruffle test suite passes (100% filtered) on no-graphics, so
  **the existing tests don't probe this boundary**. The bug only
  surfaces when a placed sprite's first frame script (a) mutates state
  visible to the parent on the same tick or (b) is observed by a
  preloader-style `onEnterFrame` reading `_currentframe`.

## What we don't know yet

**Phase 0 (2026-05-24) — controlled experiments confirmed/refuted the
following.** Two minimal SWFs built via
`tools/divergence/make_controlled_swfs.py`:

- `sprite_first_tick_load.swf` — root frame 1 places a 1-frame sprite
  that traces `SP-load`. Root has 2 frames, no stop.
- `sprite_first_tick_advance.swf` — root frame 1 has `stop()` + places
  a 2-frame sprite. Sprite frame 1: `SP-f1`. Sprite frame 2: `SP-f2`.
- `sprite_calls_root_play.swf` — added to probe Pong's `_root.play()`
  pattern: root has 3 frames (stop on f1, `ROOT-f2` trace on f2,
  `ROOT-f3` stop on f3). Sprite frame 2 calls `_root.play()`.

Confirmed:

- **Sprite Load is NOT deferred in Ruffle.** Both runtimes fire the
  sprite's frame-0 script during placement (`SP-load` / `SP-f1` appear
  in tick 1 in both `sprite_first_tick_load` and `sprite_first_tick_advance`).
  The plan's original "Ruffle defers Load to tick N+1" hypothesis is
  wrong. The Ruffle exec-list iterator skipping mid-iter additions does
  NOT mean placement-time frame-0 is skipped — placement itself runs the
  initial frame synchronously via Ruffle's MovieClip construction path,
  before the exec-list iteration would have visited that clip.
- **Sprite frame-counter advance happens in tick 2 in both runtimes.**
  In `sprite_first_tick_advance`, both runtimes report
  `F1 _root.sprite1 _cf=2` (so by the time tick 2's `onEnterFrame`
  reads `sprite1._currentframe`, the sprite has already advanced).
- **The real divergence is script-execution ORDER within tick 2+.**
  In `sprite_first_tick_advance`:
  - Ruffle: `SP-f2` → `F1` (sprite frame-2 script runs BEFORE root
    `onEnterFrame`)
  - SWFRecomp: `F1` → `SP-f2` (root `onEnterFrame` runs BEFORE sprite
    frame-2 script)
- **Root-vs-child iteration order matches the prepend model.** Sprite
  is at head of Ruffle's `clip_exec_list` (added during root's tick-1
  processing). Iteration starts from head → sprite first, root second.
  This explains the SCRIPT-before-onEnterFrame order.

Mechanism in SWFRecomp (the recompiler emits sprite frame funcs as
`actionQueueSpriteScript` wrappers — they QUEUE rather than execute
inline; see recompiled `sprite_1_frame_1` in any test build). On tick
2 in `sprite_first_tick_advance`:
  1. `advance_sprite_frames` at top of tick calls `sprite_1_frame_funcs[1]`
     which queues `script_1` (= SP-f2 trace).
  2. Root is stopped → `frame_funcs[0]` is skipped (gated on
     `is_playing || manual_next_frame`); the recompiler-emitted
     `actionDrainAllInPriorityOrder` inside root frame func therefore
     doesn't run either.
  3. `tagFlushPendingEnterFrame` fallback fires (`swf.c` ~line 631 /
     `swf_core.c` ~line 1050) → tracer `onEnterFrame` → `F1` trace.
  4. `advance_nested_sprite_frames`.
  5. `actionDrainActionQueueByKind(AQ_KIND_SCRIPT)` at `swf.c:659` /
     `swf_core.c:1064` drains `script_1` → SP-f2 trace.
  → Steps 3 (onEnterFrame) and 5 (sprite script) are inverted vs Ruffle.

**Pong-specific mechanism (confirmed 2026-05-24 via printf
instrumentation):** Pong's preloader uses **nested sprites**:
`_root` places `sprite_10` (instance2), which during frame 1 places
`sprite_9` (instance3), which during frame 1 places `sprite_7` (progbar).
The bug fires in `advance_nested_sprite_frames` at end of tick 1:

1. Root frame 1 runs. tagPlaceObject2 for sprite_10 triggers eager init
   at `tag.c:5690` (the Phase-1 catch-up-mode-1 path) — runs
   sprite_10's frame_funcs[0], which places sprite_9 inside it. The
   eager init recurses: sprite_9's frame_funcs[0] runs, placing
   sprite_7 (progbar) inside it; sprite_7's frame_funcs[0] runs.
   Each level sets `sprite_current_frame = 1`.
2. tagShowFrame's process_sprite_needs_init handles the
   needs-init bookkeeping (sni=2 = eager-already-done branch). It does
   NOT re-fire frame_funcs[0].
3. **End of tick 1, after frame_funcs[0] returns:**
   `advance_nested_sprite_frames(app_context)` runs (swf.c line 654).
   It iterates root display_list, for each sprite swaps to its
   children display_list, then calls `advance_sprite_frames`
   recursively (with `g_advance_defer_nested = 0`).
4. For sprite_10: swap to sprite_10's children (containing sprite_9).
   advance_sprite_frames iterates sprite_10's children:
   - Finds sprite_9. `sprite_display_list != NULL`, `init = 2`
     (upgraded by tagShowFrame), `is_playing = 1`,
     `sprite_current_frame = 1` (set by eager init).
   - 3 frames, not <= 1 — proceeds to advance.
   - Calls `sprite_9_frame_funcs[1]`, which queues `script_2`. That
     script: sets `pcent_loaded`, sets `progbar._width`, calls
     `_root.play()`.
5. SCRIPT queue drain at end of tick 1: `script_2` fires →
   `_root.play()` sets `root.is_playing = 1`.
6. End of tick 1: `is_playing = 1` → next tick advances root to
   frame 2.
7. Tick 2: `current_frame = 1`, `root._currentframe = 2`. F1 tracer
   reads 2.

In Ruffle, the equivalent mechanism is `Avm1::run_frame`'s exec-list
iteration. After tick 1: sprite_9 added to exec_list during placement.
Iteration's captured `next` was from before sprite_9 was added, so
sprite_9 is NOT visited in tick 1. It IS advanced in tick 2 (via
Avm1::run_frame → exec_list iterator visits it). So Ruffle's
`_root.play()` fires in tick 2, root advances in tick 3.

**Decision after instrumentation: the plan's Option A / B / C concept
WAS correct.** A newly-placed nested sprite (one created mid-tick by
its parent's frame_funcs[0]) needs to be skipped by
advance_nested_sprite_frames in the same tick. The original plan got
the divergent path approximately right; the specifics were just under
nailed-down (the actual trigger is the eager-init + advance_nested
combination, not advance_sprite_frames at top of tick).

What this means for fix choice:

- **Option B (place_at_tick flag) is now the recommended approach**
  rather than C (snapshot). The bug is specifically about
  `advance_nested_sprite_frames` (line 654) visiting children-of-root
  that were just placed; threading a snapshot through nested
  recursion is more invasive than a per-DisplayObject flag.
- **Option C (snapshot) would still work** but it's overkill — the
  snapshot needs to be taken at the start of each
  advance_sprite_frames recursion level, propagated through the swap
  to children's DL, etc. More invasive than necessary.
- **Option A (placed_in_current_tick) is identical to B in effect**;
  B is marginally better because the explicit tick counter is also
  useful for debugging and survives multi-tick re-entries.
- **Trace-ordering divergence in `sprite_first_tick_advance.swf`** (the
  `SP-f2` ↔ `F1` swap) is a SEPARATE bug from the Pong one and
  Option A/B/C does NOT fix it. That's about `actionDrainActionQueueByKind`
  running AFTER `tagFlushPendingEnterFrame` at swf.c:631/659 when root
  is stopped. Leave it for a follow-up — it doesn't cause behavioral
  divergence in any test we know of, only trace-line ordering.

What this means for the fix:

- The plan's original framing — "defer newly-placed sprite advance by
  one tick" — does NOT match Ruffle. Ruffle does the OPPOSITE: it runs
  newly-placed sprites' frame-0 SYNCHRONOUSLY at placement time, then
  iterates them via exec_list on subsequent ticks just like any other
  clip. The Pong divergence is something else (likely script-ordering
  or a different code path triggered by Pong's structure).
- **Option C (snapshot display list) does NOT directly fix the
  trace-ordering divergence found here.** A snapshot iterates the
  sprite either way (it was placed in a prior tick, so it's in the
  snapshot); the issue is when the QUEUED script gets drained relative
  to `onEnterFrame`. Options A and B are similarly orthogonal.
- The actual fix likely needs to either (i) drain `AQ_KIND_SCRIPT`
  BEFORE `tagFlushPendingEnterFrame` when root frame func skipped, or
  (ii) restructure the tick to iterate clips Ruffle-style (per-clip
  enterFrame+advance+frame-tags atomically, in exec-list order). Each
  is a different, smaller change than the snapshot-threading work in
  Phases 1-2.

Older open questions, not yet addressed:

- **`sprite_frame_funcs[0]` (the load frame) — does it run inside
  `advance_sprite_frames` or somewhere else?** Confirmed:
  `process_sprite_needs_init` (called from `tagShowFrame`, `tag.c:550`)
  runs `sprite_frame_funcs[0]` for newly-placed sprites and post-sets
  `sprite_current_frame = 1` (line 597). So advancement of newly placed
  sprites happens at placement time, not in `advance_sprite_frames`.
- **`g_advance_defer_nested` semantics.** Phase 1 (`advance_sprite_frames`)
  runs with `g_advance_defer_nested = 1`. Phase 3
  (`advance_nested_sprite_frames`) runs after root `frame_funcs` with
  the flag cleared. The split exists so that root-level sprites advance
  before the root frame_func runs (so they can queue scripts that root
  drains at the top of its frame_func), while their children advance
  after, mirroring Ruffle's depth-ordering. Confirmed unrelated to the
  trace-ordering bug here.

## Ruffle's behavior — the canonical reference

**Updated 2026-05-24 after Phase 0 experiments** (see
"What we don't know yet"). The actual model:

```
Tick 1 (first run_frame from exporter):
  Avm1::run_frame iterates clip_exec_list. Initially: just root.
  Root.run_frame_avm1:
    - Advance current_frame 0→1
    - Process frame 1 tags:
      - DefineSprite (definition)
      - DoAction (ROOT-f1 trace + stop)
      - PlaceObject2 sprite_1:
        - Sprite instantiated, added to clip_exec_list HEAD.
        - **Sprite's frame-0 (Load frame) is run synchronously** during
          this placement, BEFORE the exec-list iterator advances —
          so `SP-f1` traces in tick 1, same tick as placement. After:
          sprite_1.current_frame=1.
    - After: root.current_frame=1, root.playing=false.
  exec_list iterator's captured `next` was None (sprite added during
    root visit isn't reachable from old `next`), so loop ends.

Tick 2:
  Avm1::run_frame iterates clip_exec_list. Now: [sprite_1, root].
  Sprite_1.run_frame_avm1 (head of list, visited first):
    - Fire `onEnterFrame` (none registered)
    - Advance 1→2, run frame 2 tags (DoAction → SP-f2 trace).
    - After: sprite_1.current_frame=2.
  Root.run_frame_avm1:
    - Fire `onEnterFrame` (tracer's → TRACER F1: _currentframe=1).
    - playing=false → no advance, no tags.

Tick 3:
  Sprite_1: advance 2→1 (wrap, 2-frame sprite), run frame 1 → SP-f1.
  Root: onEnterFrame → F2 _currentframe=1 still, sprite._cf=1.
```

This matches the observed Ruffle traces for both
`sprite_first_tick_advance.swf` (where the divergence is purely the
ordering of sprite scripts vs root onEnterFrame) and `Pong.swf` (where
the divergence is bigger — Pong does something extra that we haven't
yet pinned down, see "What we don't know yet").

Key facts the model establishes:

- Sprite frame-0 (Load) is run AT PLACEMENT TIME, not deferred to the
  next tick. The exec-list iterator's "captured next" behavior is what
  prevents sprites from being VISITED twice in the same tick — but
  placement itself already ran their initial frame.
- On subsequent ticks, exec-list iteration order is "most recently
  added first" (prepend-on-add). For a root-and-one-sprite SWF, that
  means sprite runs BEFORE root each tick, so sprite scripts that
  reference root state see root's prior-tick state, not its current
  one.

## SWFRecomp's current behavior

Confirmed from code (`swf.c:565-572`, `tag.c:760+`) and trace evidence:

```
Tick 1:
  current_frame = next_frame = 0
  advance_sprite_frames(): walks display_list — empty, no-op
  enterframe_flush_pending = 1
  frame_funcs[0] runs: places sprite 9, queues script_0 (stop) + script_5
    (tracer init). DrainAllInPriorityOrder runs both. tagFlushPendingEnterFrame
    fires (no handler yet). tagShowFrame.
  advance_nested_sprite_frames(): walks display_list including the just-placed
    sprite 9 and its children, advancing them. Sprite 9 frame 0 runs
    (script_1 _parent.stop). Sprite 9 advances to frame 1 (= recompiler 0-based,
    so user-facing "frame 2") and runs script_2 → progbar._width=100,
    _root.play() → is_playing=1.
  End of tick 1: is_playing=1 → next_frame=1.

Tick 2:
  current_frame = next_frame = 1
  advance_sprite_frames(): advances sprite 9 again
  frame_funcs[1] runs: Pong frame 2 = stop. tagFlushPendingEnterFrame fires
    → tracer F1 reads _currentframe=2.
  ...
```

The mechanism: `advance_nested_sprite_frames` after `frame_funcs[0]`
picks up the newly-placed sprite 9 and runs its frame scripts within
tick 1.

## Investigation phase: confirm the model

Before writing any fix, build two minimal SWFs and run both through
both runtimes to establish ground truth:

1. **`sprite_first_tick_load.swf`**: 2-frame root, frame 1 places a
   sprite that does only `trace("SP-load")` on its frame 1.
   - Question: does Ruffle's tick 1 contain `SP-load`?
   - Question: does SWFRecomp's tick 1 contain `SP-load`?

2. **`sprite_first_tick_advance.swf`**: Like above but sprite has 2
   frames. Frame 1: `trace("SP-f1")`. Frame 2: `trace("SP-f2")`.
   Root frame 1 has `stop()`.
   - Question: when does each runtime emit `SP-f2`?

These two tests pin down the exact tick on which Load fires, the exact
tick on which advance happens, and whether Ruffle's behavior is "skip
mid-iteration adds" vs "explicit one-tick defer."

Write the SWFs via the same Python machinery used by
`tools/divergence/make_test_swfs.py` (and the existing
`demos/ruffle-inject/make_test_swfs.py` for bytecode-tag construction
patterns).

## Fix options

Once the model is confirmed, the fix has three plausible shapes. They
differ in localization vs faithfulness to Ruffle:

### Option A — `placed_in_current_tick` flag on `DisplayObject`
Add a `u8` field to `DisplayObject`. Set to 1 in `tagPlaceObject2`
when the entry is newly created (not when it's modifying an existing
depth). `advance_sprite_frames` and `advance_nested_sprite_frames`
skip entries where this flag is set, then clear the flag at the end of
their pass.

- **Pros**: localized, minimal code change, easy to reason about.
- **Cons**: another field on a hot struct; must distinguish
  newly-placed from existing-modify carefully.

### Option B — `placed_at_tick` generation counter
Maintain a `size_t g_tick_count` (mirroring `g_capture_tick` in
`capture.c`). Add `placed_at_tick` to `DisplayObject`. Skip advancement
when `placed_at_tick == g_tick_count`.

- **Pros**: information survives one full tick boundary without
  needing a separate clear step; tick counter is generally useful.
- **Cons**: an extra field and a global counter; need to make sure
  the counter increments at the right point and doesn't go stale
  during gotos / catch-up.

### Option C — snapshot the display list at top of tick
At the top of each tick (before `frame_funcs[current_frame]`), record
which `(depth, place_seq)` tuples are currently in the display list.
Pass that snapshot to `advance_sprite_frames` /
`advance_nested_sprite_frames` so they iterate only the snapshot,
ignoring later additions. Mirrors Ruffle's exec-list iteration most
faithfully.

Ruffle's mechanism in `~/CC/ruffle/core/src/avm1/runtime.rs:489-505`:
```rust
let mut next = context.avm1.clip_exec_list;
while let Some(clip) = next {
    next = clip.next_avm1_clip();    // captured BEFORE processing
    if !clip.avm1_removed() {
        clip.run_frame_avm1(context);
    }
}
```
Combined with `add_to_exec_list` prepending new clips to the list head,
the result is: any clip placed mid-iteration is unreachable from the
captured `next` pointers, so it's silently skipped this tick. That's
structurally a snapshot — just implemented via linked-list semantics
rather than a separate buffer. Options A and B encode the same
observable behavior via a side-channel flag; only Option C reproduces
the iteration structure itself.

- **Pros**: most direct mirror of Ruffle's behavior; the iteration
  structure carries the "what was visible at start of tick" intent
  visibly in the code, rather than via a flag whose meaning has to be
  remembered at every read/write site.
- **Cons**: stack-allocates a per-tick snapshot (the existing
  `ASF_SORT_CAP = 512` sort buffer is the right scale); requires
  threading the snapshot through call sites; sprite-display-list
  recursion needs its own snapshot per nesting level.

## Recommended approach

**Option C** (snapshot the display list at top of tick). Rationale:
- Closest structural match to Ruffle (the canonical reference). The
  resulting SWFRecomp iteration reads as "advance the things that
  were visible at start of tick" — the same mental model as Ruffle's
  iterator over `clip_exec_list` with `next` captured up front.
- Options A and B are functionally equivalent but encode the deferral
  via a side-channel flag (`placed_at_tick == g_tick_count` or
  `placed_in_current_tick == 1`). That flag has to be read and
  written correctly at every placement/skip site. If a future change
  iterates the display list twice in a tick, or introduces a new
  placement path that forgets to set the flag, the meaning drifts
  silently from Ruffle's behavior. Snapshot-based iteration leaves no
  room for that drift: anything in the snapshot is iterated, anything
  added after is invisible to this tick by construction.
- Goto catch-up has well-defined behavior under the snapshot model:
  during a catch-up replay, take a snapshot at the start of the
  replay; placements that happen during the replay are visible on the
  next post-catch-up tick (which mirrors Ruffle, where the same
  iterator semantics apply during any replay).

**Option B is the fallback** if Option C turns out to interact badly
with the existing `g_advance_defer_nested` / nested-sprite recursion
structure. Promote the tick counter, add `placed_at_tick`, skip on
equality. Easier change than C; identical observable behavior for the
patterns we care about.

**Option A is the second fallback** if both prove problematic.

## Phases

### Phase 0 — Investigation (no code change to runtime) — DONE 2026-05-24
- Build the two controlled SWFs from
  [Investigation phase](#investigation-phase-confirm-the-model).
- Run both through both runtimes; record exact trace per tick.
- Update this plan's "What we don't know yet" section with confirmed
  answers before proceeding.
- Also confirm the Ruffle iteration model by reading
  `~/CC/ruffle/core/src/avm1/runtime.rs::Avm1::run_frame`
  (around line 479) end-to-end and cross-checking with the controlled
  experiments.

**Result (initial reading): the plan's original framing seemed wrong**
— sprite frame-0 (Load) runs synchronously at placement time in BOTH
runtimes — but **printf instrumentation on Pong revealed the plan's
mechanism is correct, just slightly mis-located**:

- The "place + advance in same tick" pattern requires a sprite
  **placed inside another sprite's frame_funcs[0]**. The outer
  sprite's eager init in tagPlaceObject2 (tag.c:5690) advances the
  outer sprite to `sprite_current_frame=1`. The placed sprite (now in
  the outer's children DL) is then visited by
  `advance_nested_sprite_frames` at end of the same tick and runs its
  frame_funcs[1].
- Pong: root places sprite_10, which during its frame_funcs[0] places
  sprite_9, which during its frame_funcs[0] places progbar. After
  root frame_funcs[0] returns, advance_nested_sprite_frames swaps into
  sprite_10's children DL and advances sprite_9 to frame_funcs[1] —
  which calls `_root.play()`.
- My simple controlled SWFs don't exhibit this because their sprites
  are at root level with no children — advance_nested_sprite_frames
  swaps to an empty children DL.

**Two distinct divergences in scope:**

1. **Pong's "nested sprite advances same tick"** — fix matches the
   plan's Option A/B/C concept. Use **Option B (placed_at_tick flag)**
   per the analysis in "Still unexplained" above. Most surgical.
2. **`sprite_first_tick_advance.swf`'s trace-ordering** (`F1` before
   `SP-f2` instead of after) — separate bug at
   swf.c:631/659. Leave for follow-up; no known test depends on this
   ordering.

### Phase 1 — Build the snapshot infrastructure
- Add a small per-tick snapshot struct (`DisplayListSnapshot` or
  similar) in `libswf/tag.h` carrying a stack array of `(depth,
  place_seq)` tuples sized to `ASF_SORT_CAP`.
- Add a "take snapshot of `display_list[]`" helper near the existing
  sort-by-`place_seq` code at `tag.c:776-796`.
- No call-site changes yet; just the API surface. Confirm it compiles
  cleanly under both `NO_GRAPHICS` and `OFFSCREEN_RENDER`.

### Phase 2 — Thread the snapshot through `advance_sprite_frames`
- Take a snapshot at the top of each tick in `swf.c` (line ~566) and
  `swf_core.c` (matching site).
- Change `advance_sprite_frames` to accept the snapshot and iterate
  it instead of `display_list[]` directly.
- Recursive case: the button-children recursion at `tag.c:814+` and
  the sprite-recursion paths need to take their own snapshots before
  recursing into the swapped display list context. Each nesting
  level snapshots at entry.
- Same change for `advance_nested_sprite_frames` (`tag.c:1120`).
- This is the substantive behavioral change. Behavioral test
  expectation: any sprite placed during this tick's frame_funcs is
  silently absent from this tick's advance pass.

### Phase 3 — Targeted regression spot-checks
- Run the controlled SWFs from Phase 0 — expect the SWFRecomp side to
  now match Ruffle.
- Run targeted regression tests from the
  [Regression risks](#regression-risks) table:
  `verify_output.py --test=execution_order2 --test=execution_order3
  --test=goto_execution_order2 --test=register_and_init_order
  --test=create_empty_movie_clip --test=goto_rewind3
  --test=clip_events --test=bad_placeobject_clipaction
  --test=on_construct --test=register_class_return_value
  --test=registerClassTest2` in both `no-graphics` and
  `--mode=graphics`.
- If any fail: diagnose whether the failure represents (a) a true
  regression (snapshot is wrong) or (b) the test was relying on the
  buggy same-tick advancement. Case (b) means the test's
  expected output needs updating to match Ruffle.

### Phase 4 — Verify against Pong + commit
- Re-run `tools/divergence/divergence_test.py ~/CC/glaiel/swfs/Pong.swf`.
- Expect: `F1 _currentframe=1`, progress bar empty, both sides match.
- Run the harness on one additional glaiel SWF that uses a preloader
  (likely candidate: `Reaction.swf`) to confirm the fix generalizes.
- Commit, push, run full no-graphics + graphics CI per
  `.claude/pipeline-handoff.md`.

### Phase 5 (contingency) — Fall back to Option B
If Phase 2 or 3 reveals that the snapshot model interacts badly with
goto catch-up or the existing `g_advance_defer_nested` split — for
example, if catch-up replays need to see placements made during the
replay — abandon the snapshot threading and switch to the
flag-on-placement approach (Option B):
- Promote `g_capture_tick` → `g_tick_count` (exposed via
  `libswf/swf.h`).
- Add `size_t placed_at_tick` to `DisplayObject`.
- `tagPlaceObject2` / `tagPlaceObject2WithClipActions` set the field
  on new-entry path only.
- `advance_sprite_frames` and `advance_nested_sprite_frames` skip
  entries where `placed_at_tick == g_tick_count`.
- Same regression spot-checks; same Pong verification.

## Regression risks

Tests likely to be sensitive (skim before each phase, run as targeted
spot-checks):

| Area | Tests | Reason |
|---|---|---|
| Sprite init ordering | `execution_order2`, `execution_order3`, `goto_execution_order2`, `register_and_init_order` | Heavily tuned in this exact area; see `g_defer_sprite_init` machinery. |
| createEmptyMovieClip | `create_empty_movie_clip` | Dynamic MCs (no display_obj) have separate enterframe-eligible marking; verify they aren't accidentally also gated by `placed_at_tick`. |
| Goto catch-up | `goto_rewind3`, `goto_frame_number`, `timeline_as2_1` | Catch-up replays advance frames synthetically; `placed_at_tick` semantics under catch-up are the open question. |
| MovieClipLoader | `mcl_*` cluster | Loader-completion timing is also a "newly-placed clip" pattern. |
| onLoad / onClipEvent(load) | `clip_events`, `bad_placeobject_clipaction`, `on_construct` | Load-event timing is tightly coupled to first-tick processing. |
| Object.registerClass | `register_class_*`, `registerClassTest2` | Constructor-firing order on placement could shift one tick. |

Specific patterns to verify don't break:
1. **A sprite that does `_parent.stop()` on its frame 0**: should still
   stop the parent on tick 1 (i.e. `script_1` in sprite 9 should still
   run on placement tick in our fix — or if not, the parent should
   still see stop on time). Need to be careful that the fix doesn't
   defer Load events that *should* fire on placement tick.
2. **registerClass constructor firing**: per MEMORY.md, the order is
   "set __proto__ → fire CONSTRUCT clip events → fire registerClass
   constructor" at tagPlaceObject2 placement time. Confirm `placed_at_tick`
   doesn't inadvertently defer constructor execution.
3. **createEmptyMovieClip + attachMovie**: these go through different
   placement paths; they should remain unaffected.

## Verification

After each phase:
1. **Pong divergence harness**:
   `python3 tools/divergence/divergence_test.py ~/CC/glaiel/swfs/Pong.swf --frames 30`
   — F1 must match Ruffle.
2. **Targeted regression spot-checks** from the table above:
   `python3 ruffle-tests/verify_output.py --test=execution_order2 ...
   --test=clip_events ...` (no-graphics and `--mode=graphics`).
3. **Full CI** in both modes via `.claude/pipeline-handoff.md`.
4. **At least one other glaiel SWF**: pick a smaller one
   (`Reaction.swf` at 127KB) and run the divergence harness.

Success criteria:
- Pong's `F1 _currentframe` matches Ruffle.
- Pong's frame 1 PNG: progress bar empty (Ruffle-matching), 0 outliers
  at strict tolerance.
- No regressions in either CI mode (acceptable: small expected
  shifts in sprite-init ordering tests if Ruffle agrees with the new
  behavior — measure individually).

## Out of scope

- Fixing the `Capabilities.version` trailing-NUL bug (separate
  divergence #4 in
  `SWFRecompDocs/status/2026-05-24-divergence-harness-findings.md`).
- The v8-only PNG-count anomaly (16/20 vs 20/20 with version bump).
  Likely a separate frame-loop early-exit issue.
- Extending the divergence harness itself (covered in the harness
  usage guide).
- Investigating other glaiel SWFs as part of *this* plan — that's
  the natural follow-on after the Pong fix is verified.
