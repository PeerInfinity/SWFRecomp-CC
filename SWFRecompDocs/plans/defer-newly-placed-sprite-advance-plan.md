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

These need a controlled experiment before committing to a fix:
- **Does Ruffle defer Load too, or just frame advance?**
  Ruffle's `Avm1::run_frame` iteration captures `next = clip.next_avm1_clip()`
  *before* processing each clip (see `~/CC/ruffle/core/src/avm1/runtime.rs`
  line ~491). Clips added mid-iteration are skipped that tick. So a
  sprite placed during root's tick-1 processing doesn't fire Load until
  tick 2, and doesn't advance to its frame 2 until tick 3. **Confirm
  this hypothesis with a controlled SWF.**
- **What's the exact order of root vs child `run_frame_avm1` on tick N?**
  `add_to_exec_list` prepends, so the most recently added clip is at the
  head; iteration starts from head. If sprite 9 was added after root,
  sprite 9 is head and runs *before* root each tick. This matters for
  determining when `_root.play()` (called from sprite 9's frame 2)
  takes effect on the root's same-tick advance.
- **`sprite_frame_funcs[0]` (the load frame) — does it run inside
  `advance_sprite_frames` or somewhere else?** Track this through
  `tagPlaceObject2` → first call to `advance_sprite_frames` for the new
  depth. The `just_allocated` branch at `tag.c:838` allocates the
  sprite's display list on first encounter but doesn't appear to skip
  the frame advancement that follows.
- **`g_advance_defer_nested` semantics.** Phase 1 (`advance_sprite_frames`)
  runs with `g_advance_defer_nested = 1`. Phase 3
  (`advance_nested_sprite_frames`) runs after root `frame_funcs` with
  the flag cleared. The defer split exists for a different reason —
  document why, since it overlaps the area we want to change.

## Ruffle's behavior — the canonical reference

Hypothesized but unconfirmed-in-experiment:

```
Tick 1 (first run_frame from exporter):
  Root: Load fires (no enterFrame; INITIALIZED flag flips). run_frame_internal:
    increment current_frame 0→1, run frame 1 tags (DoInit, PlaceObject sprite 9,
    DoAction stop). After: current_frame=1, playing=false.
  Sprite 9: just added to exec_list during root processing; iteration captured
    next pointer before sprite 9 was added; sprite 9 is NOT visited this tick.

Tick 2:
  Sprite 9: head of exec_list. Load fires (first visit), run_frame_internal:
    increment 0→1, run frame 1 tags (script_1 = _parent.stop, a no-op
    on already-stopped root). After: sprite 9 current_frame=1.
  Root: enterFrame fires (TRACER F1: _currentframe=1). playing=false, no advance.

Tick 3:
  Sprite 9: enterFrame fires. run_frame_internal: increment 1→2, run frame 2
    tags (script_2 = update pcent_loaded, set progbar._width=100, call
    _root.play()). After: root.playing=true (sprite 9 set it mid-tick).
  Root: enterFrame fires (TRACER F2: _currentframe=1 still — set BEFORE
    advance). playing=true → increment 1→2, run frame 2 tags (stop).
    After: current_frame=2, playing=false.
```

This predicts Ruffle's trace `F1=1, F2=1, F3=2` — but observed Ruffle
trace is `F1=1, F2=2, F3=3`. So our hypothesis is wrong somewhere.
**Run the controlled experiment before assuming.**

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

### Phase 0 — Investigation (no code change to runtime)
- Build the two controlled SWFs from
  [Investigation phase](#investigation-phase-confirm-the-model).
- Run both through both runtimes; record exact trace per tick.
- Update this plan's "What we don't know yet" section with confirmed
  answers before proceeding.
- Also confirm the Ruffle iteration model by reading
  `~/CC/ruffle/core/src/avm1/runtime.rs::Avm1::run_frame`
  (around line 479) end-to-end and cross-checking with the controlled
  experiments.

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
