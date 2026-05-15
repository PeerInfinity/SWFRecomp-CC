# Phase 3 Loop-Back False-Refusal — Plan

**Document Version:** 1.0

**Created:** 2026-05-14

**Status:** Planned; no implementation yet.

Phase 3 (commit `12fa91a3`, "refuse Place on occupied depth") fixed
`shape_test`'s missing-`sh2` driver but broke several tests that rely on
cross-char re-placement working during *loop-back*. This plan covers
the diagnosis and a path to a fix that keeps Phase 3's
shape_test win without the loop-back regressions.

## Table of contents

1. [Affected tests](#affected-tests)
2. [Phase 3 recap](#phase-3-recap)
3. [Three distinct loop-back patterns](#three-distinct-loop-back-patterns)
4. [Why the existing `placed_at_frame` gate isn't enough](#why-the-existing-placed_at_frame-gate-isnt-enough)
5. [Candidate approaches](#candidate-approaches)
6. [Recommended approach: layered gates](#recommended-approach-layered-gates)
7. [Verification](#verification)
8. [Risks](#risks)
9. [Out of scope](#out-of-scope)

---

## Affected tests

From the graphics-mode CI diff (run `25897983827`, master
`17a60dbb` → `45164a5b`) and the prior trace-mode diff
(`b20ee462` → `eb8206f8`):

| Test | Suite | Status delta | Lines delta |
|---|---|---|---|
| `loop/loop_test` | from_gnash/misc-ming.all | pass → output_mismatch | 21/21 → 4/21 |
| `loop/loop_test2` | from_gnash/misc-ming.all | pass → output_mismatch | 15/15 → 6/15 |
| `loop/loop_test3` | from_gnash/misc-ming.all | pass → output_mismatch | 16/16 → 9/16 |
| `loop/loop_test10` | from_gnash/misc-ming.all | ruffle_matched → output_mismatch | 5/28 → 3/28 |
| `register_class/RegisterClassTest4` | from_gnash/misc-ming.all | output_mismatch | 17/42 → 7/42 (trace) |

Common stdout signature: extra `Warning: Failed to place object at
depth N.` lines from Phase 3's printf, shifted line numbers, and
auto-instance counters short by 1 (e.g. `/instance3` rendering as
`/instance2`) because the refused placement didn't allocate its
instance.

The shape_test fix (driver for Phase 3) still holds in graphics
mode — this plan must preserve it.

## Phase 3 recap

`tagPlaceObject2` / `tagPlaceObject2Ratio` currently refuse with:

```c
if (char_id != 0 && !is_replace
    && display_list[depth].char_id != 0
    && display_list[depth].char_id != char_id
    && display_list[depth].placed_at_frame <= current_frame)
{
    printf("Warning: Failed to place object at depth %zu.\n", depth);
    return;
}
```

The four gates: char-bearing Place (not Modify/Replace), depth is
occupied, **different** character, and the existing entry's
`placed_at_frame` is `<=` current frame (forward-conflict only). The
last gate was meant to exclude loop-back replays where the existing
entry was placed in a *later* main frame of a previous iteration —
but it only catches some loop-back patterns, not all.

## Three distinct loop-back patterns

Phase 3's regressions split into three sub-patterns. Calling them out
explicitly because each one tickles the gate differently and a fix has
to address all three.

### Pattern A — Sprite-internal loop with Remove+Place

`register_class/RegisterClassTest4`'s sprite 2:

```
DefineSprite objectID=2, frames=2
  Frame 1: PlaceObject2 depth=1 char=3 "Segments"
  Frame 2: RemoveObject2 depth=1
           PlaceObject2 depth=1 char=1 "Segments"
```

Sprite 2 plays internally, looping frame 1 → 2 → 1 → 2. Main
`current_frame` stays fixed while sprite 2 advances. So on iteration N
frame 1, depth-1 (inside sprite 2) holds char 1 (from iteration N-1
frame 2) with `placed_at_frame == current_frame`. Phase 3's gate
(`<=`) **does** trip and the placement is refused. Without the refusal
the existing destroy+re-instantiate path runs; the test relies on the
auto-instance counter increment that produces.

### Pattern B — Root-timeline loop with swapDepths

`loop/loop_test`, `loop/loop_test2`, `loop/loop_test3`:

```
Frame 1: PlaceObject2 depth=A char=X
         PlaceObject2 depth=B char=Y
Frame 3: DoAction { movieClip1.swapDepths(movieClip2); }
```

After frame 3's swap, depth A holds char Y and depth B holds char X.
On root-timeline loop-back to frame 1, frame 1 re-fires its
PlaceObject2s. `Place(depth=A, char=X)` sees depth A occupied by
char Y → cross-char conflict. Whether the gate trips depends on
whether swapDepths updates `placed_at_frame` on the destination
slot — needs verification (see [Open question 1](#open-questions)),
but the live test output shows it does trip
(`Warning: Failed to place object at depth 64000.` in our actual).

### Pattern C — Root-timeline loop with cross-frame Remove+Place

`loop/loop_test10`'s main timeline (paraphrased):

```
Frame 2: PlaceObject2 depth=100 char=mc1
Frame 3: RemoveObject2 depth=100
         PlaceObject2 depth=100 char=mc2 (different)
Frame 4: RemoveObject2 depth=100
         PlaceObject2 depth=100 char=mc3 (different)
Frame 6: jump-to frame 5  (loop point)
```

On loop-back via jump (gotoFrame backward), the next forward run of
frame 2 places mc1 at depth 100 — but depth 100 currently holds mc3
(`placed_at_frame == 4`). The gate `placed_at_frame <= current_frame`
becomes `4 <= 2` → false → Phase 3 doesn't fire. So this pattern is
*already correctly excluded* by the gate; the test's regression
(5/28 → 3/28) must come from somewhere else (probably the
auto-instance counter shift triggered by Phase 3 firing earlier in
the run, e.g. the dejagnu sprite re-init). Confirming this is part
of the investigation step below.

## Why the existing `placed_at_frame` gate isn't enough

The gate works for **Phase 3's intended case** (shape_test:
sh2 placed in frame 1, sprite 7 placed in frame 2 — distinct main
frames; gate trips correctly). It fails for:

- **Pattern A** because main `current_frame` is stationary while the
  sprite loops; `placed_at_frame == current_frame` always.
- **Pattern B** *might* fail depending on how swapDepths interacts
  with `placed_at_frame` (need to confirm). If swap preserves the
  swap-destination's `placed_at_frame` from the late frame where the
  swap happened, the gate should trip — but observed behavior says it
  doesn't, so swap is likely either zeroing `placed_at_frame` or
  Phase 3 is somehow seeing a stale value.

So we need two extra gates beyond `placed_at_frame`:

1. A "we're inside sprite-internal advance, not root" check (covers
   Pattern A).
2. A "the existing entry isn't an artifact of a depth-mutating AS
   operation (swapDepths, attachMovie, etc.)" check (covers Pattern
   B).

## Candidate approaches

### Approach 1 — Sprite-context flag

Add a global `g_sprite_advance_depth` int, bumped/unbumped around
sprite frame-func invocations in `advance_sprite_frames`
(SWFModernRuntime/src/libswf/tag.c:~870) and other sprite-step
callsites (button state transitions, eager init under catch-up).
Phase 3 gates on `g_sprite_advance_depth == 0`.

- **Fixes**: Pattern A.
- **Doesn't fix**: Pattern B (swap-then-loop is root-level).
- **Cost**: ~3-5 call-sites to instrument. Low risk if the call-sites
  are exhaustive — but missing one leaves a hole. The existing
  `g_sprite_init_depth` already exists for sprite *init* (~line 110);
  adding a parallel `g_sprite_advance_depth` is the symmetric move.

### Approach 2 — `depth_swapped` flag check

`display_list[depth].depth_swapped` is already maintained by the
swapDepths handler (action.c) and consumed by the existing modify
path (tag.c:5036). Phase 3 can read it and skip refusal when set.

- **Fixes**: Pattern B (if `depth_swapped` is set on the
  swap-destination slot at refuse-check time).
- **Doesn't fix**: Pattern A.
- **Cost**: one extra condition in the gate.

### Approach 3 — Strict less-than gate

Change `placed_at_frame <= current_frame` to
`placed_at_frame < current_frame` (strict). Within-same-frame
conflicts then fall through to the existing line-5362 same-frame
check (which prints the same warning and returns).

- **Fixes**: Pattern A (the sprite-loop-back stays in the same main
  frame so the gate doesn't trip).
- **Doesn't fix**: Pattern B; **also regresses** the previously-fine
  shape_test trace path (verified empirically — when I tried this
  earlier in the session, shape_test went MISMATCH because the
  warning-emission timing shifted relative to the test's expected
  output).
- **Cost**: trivial change but breaks shape_test.

### Approach 4 — Revert Phase 3

Drop the cross-frame refusal entirely. shape_test loses the sh2 fix
(image: +9086 outliers) but on-screen counter (eb8206f8) stays. All
loop tests return to baseline.

- **Cost**: ~9086 outliers regressed in shape_test plus the visual
  "sh2 missing" bug returns.

### Approach 5 — Proper run_goto rewind for sprite loop-back

Faithfully model Ruffle's loop-back semantics: when a sprite loops
back to a previous frame, undo intermediate placements (un-Place
entries whose `placed_at_frame > target_frame`) before replaying. No
`instantiate_child` is reached for any cross-char Place on a depth
that should have been rewound first.

- **Fixes**: All three patterns.
- **Cost**: Significant. Touches sprite advance, sprite frame loop,
  display-list rewind logic. Multi-day effort and high regression
  risk — the goto/rewind code is already among the most intricate
  parts of the runtime (see CLAUDE.md's MovieClip Timeline Control
  notes).

## Recommended approach: layered gates

Approach 5 is the right long-term answer but too expensive for the
immediate regression fix. Approach 1 + Approach 2 layered together
(plus the existing `placed_at_frame <= current_frame` gate) covers
Patterns A and B without breaking shape_test, and leaves Approach 5
as a future cleanup.

Final Phase 3 condition:

```c
if (char_id != 0 && !is_replace
    && display_list[depth].char_id != 0
    && display_list[depth].char_id != char_id
    && display_list[depth].placed_at_frame <= current_frame
    && g_sprite_advance_depth == 0          // skip during sprite-internal advance
    && !display_list[depth].depth_swapped)  // skip swap-destination slots
{
    printf("Warning: Failed to place object at depth %zu.\n", depth);
    /* ... */
    return;
}
```

Mirror the same gate in `tagPlaceObject2Ratio`.

### Subtask breakdown

1. **Investigate Pattern C**: confirm the `loop_test10` regression is
   from `placed_at_frame` accounting (auto-instance counter shift)
   and not from Phase 3 firing directly. If Phase 3 *is* firing in
   `loop_test10`, add it to the patterns matrix and revisit the gate
   design.
2. **Investigate Pattern B's swap interaction**: confirm
   `placed_at_frame` value on a swap-destination slot
   immediately after swapDepths, and again on the next root-timeline
   tick. If swap zeroes `placed_at_frame`, the `<=` gate trips for
   any subsequent Place; if it preserves the late frame, the gate
   correctly excludes. Either way, the `depth_swapped` check is the
   robust gate.
3. **Add `g_sprite_advance_depth`**: declare in tag.c (mirror
   `g_sprite_init_depth` at line 110), bump/unbump in
   `advance_sprite_frames` (tag.c:~870) and any other sprite-step
   call-site that doesn't go through `process_sprite_needs_init`.
4. **Update Phase 3 gate**: add both checks at the two Phase 3 sites
   (`tagPlaceObject2` ~line 5011, `tagPlaceObject2Ratio` ~line 5703).
5. **Verify**: run the test battery in [Verification](#verification).

### Files touched

- `SWFModernRuntime/src/libswf/tag.c` — Phase 3 gate update + flag
  bump/unbump in `advance_sprite_frames`.
- (Possibly) `SWFModernRuntime/include/libswf/tag.h` — if the flag
  needs an extern accessor.

No recompiler change. No new function signatures (so existing test
caches stay valid).

## Verification

Per-test, all in **graphics mode** unless noted:

### Must regain previous status

| Test | Pre-Phase-3 status | Phase-3 status | Goal |
|---|---|---|---|
| `loop/loop_test` | pass (21/21) | fail (4/21) | pass (21/21) |
| `loop/loop_test2` | pass (15/15) | fail (6/15) | pass (15/15) |
| `loop/loop_test3` | pass (16/16) | fail (9/16) | pass (16/16) |
| `loop/loop_test10` | ruffle_matched (5/28) | fail (3/28) | ruffle_matched (5/28) |
| `register_class/RegisterClassTest4` (trace) | ruffle_matched (17/42) | fail (7/42) | ruffle_matched (17/42) |

### Must hold

| Test | Status |
|---|---|
| `from_gnash/misc-ming.all/shape_test` | pass (19608 outliers, on-screen counter "#passed: 18") |
| `avm1/placeobject_occupied_depth` | pass (6/6 — two "Warning: Failed to place" lines + remainder) |
| `from_gnash/misc-ming.all/replace_sprites1test` | pass |
| `from_gnash/misc-ming.all/replace_buttons1test` | ruffle_matched |
| `from_gnash/misc-ming.all/place_object_test` | ruffle_matched |
| `from_gnash/misc-ming.all/place_object_test2` | ruffle_matched |
| `from_gnash/misc-ming.all/place_and_remove_object_test` | pass |
| `from_gnash/misc-ming.all/place_and_remove_object_insane_test` | output_mismatch (16/22 baseline) |
| `from_gnash/misc-ming.all/PlaceObject2Test` | pass |
| `from_gnash/misc-ming.all/replace_shapes1test` | pass |

### Spot check (general regression risk)

A few prototype/super tests in case the sprite-advance instrumentation
catches an unexpected callsite:

- `avm1/register_class_return_value`
- `avm1/extends_chain`
- `avm1/as2_super_and_this_v6`, `as2_super_and_this_v8`
- `avm1/swf5_no_closure`
- `avm1/set_interval`

Plus the standard graphics-mode regression set (mask_with_drawing,
movieclip_setmask, movieclip_begin_gradient_fill,
movieclip_line_gradient_style, edittext_*).

## Risks

- **R1: Missed sprite-advance call-site.** If a sprite-step path
  doesn't go through `advance_sprite_frames` (e.g. inline catch-up
  during goto, button state transitions, eager init under catch-up),
  Phase 3 still fires inside that sprite. Mitigation: enumerate all
  paths that call `sprite_frame_funcs[N](app_context)` and bump the
  flag at each one. The existing `g_sprite_init_depth` and
  `ng_swapToRootDL` infrastructure (tag.c:142) is the model — same
  call-sites are likely the answer.
- **R2: `depth_swapped` is cleared too early.** If the runtime clears
  `depth_swapped` before the next root-timeline loop pass (e.g. on
  the next ShowFrame), the gate trips again. Need to check when
  `depth_swapped` resets — `display_list[depth].depth_swapped = 0` at
  tag.c:5483 and 5936; verify these don't clear before the loop-back
  Place reaches Phase 3.
- **R3: Pattern C investigation surfaces a fourth pattern.** If
  loop_test10 is regressing for an unrelated reason
  (auto-instance counter shift propagated from Phase 3 firing
  somewhere else, e.g. dejagnu re-init), neither A nor B fixes it.
  Plan accordingly — may need a follow-up.

## Out of scope

- **Approach 5 (proper run_goto rewind for sprite advance).** The
  correct long-term semantics are bigger than this fix can absorb
  responsibly. Track as a follow-up; until then the layered gate is
  a behavioral patch that gets the named tests back to baseline.
- **The two unrelated graphics CI regressions in this run**:
  - `avm1/swf5_xml_event_handler_context` (2/2 → 0/2)
  - `avm1/native_objects_swf6` (114/115 → 1/115 with segfault)
  Both surfaced in the same CI run but neither is structurally
  related to Phase 3. They need their own investigations. The
  segfault in particular wants priority.

## Open questions

1. After `swapDepths(B)` on a clip at depth A, what is
   `display_list[A].placed_at_frame` on the next read? Specifically:
   is the value preserved from the swap-source's late frame, zeroed,
   or set to current_frame? This determines whether the existing
   `<=` gate would have caught Pattern B without the
   `depth_swapped` check.
2. For sprite-internal advance, what is the value of `current_frame`
   during each tick — strictly main-timeline frame, or does some
   path scope it to the sprite? CLAUDE.md says it's the main frame,
   but worth double-checking against the actual sprite-frame trace
   before committing to Approach 1.
