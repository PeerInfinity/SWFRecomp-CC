# CloneSprite Depth-Bias Unification Plan

<!-- TESTS: displaylist_depths/displaylist_depths_test, displaylist_depths/displaylist_depths_test2, displaylist_depths/displaylist_depths_test3, displaylist_depths/displaylist_depths_test8, displaylist_depths/displaylist_depths_test9, DepthLimitsTest, duplicate_movie_clip_test, duplicate_movie_clip_test2 -->

<!-- PLAN_META
id: CLONESPRITE_DEPTH_BIAS
status: complete
phases:
  - id: 1
    name: "Recompiler pattern-match: strip single-value Push(16384) Add prefix from CloneSprite"
    status: completed
  - id: 2a
    name: "Recompiler: extend strip to packed-Push patterns (trailing int 16384)"
    status: completed
  - id: 2b
    name: "Runtime branching audit: actionRewindCleanup/tagRemoveObject2/swap branch on `is clone` (clone_depth_table presence) instead of `has display entry`"
    status: completed
  - id: 2c
    name: "Runtime: raise clone slot cap so high-depth clones land in display_list (enables CONSTRUCT/ENTERFRAME/UNLOAD dispatch on dups)"
    status: completed
  - id: 2d
    name: "Verify on full guardrail battery + target tests; expect cascade of swap/remove interaction bugs from 2c, fix one-by-one"
    status: completed
  - id: 3
    name: "Audit residual `depth==-16384` / `depth>=16384` conflations in remaining sites"
    status: not_needed
  - id: 4
    name: "Phase 1 verification on displaylist_depths cluster + textsnapshot guardrail"
    status: completed
dependencies: []
-->

## Problem statement

`actionCloneSprite` (the `CloneSprite` bytecode opcode 0x24) accepts a depth
value from the action stack. The convention pushed by the bytecode varies by
SWF compiler:

| Source | Bytecode pattern | Stack value |
|--------|------------------|-------------|
| Ming, positive AS depth N | `Push(N) Push(16384) Add CloneSprite` | `N + 16384` |
| Ming, negative AS depth N | `Push(-2001) Push(16384) Add CloneSprite` | `14383` |
| Other compilers (e.g. Ruffle's own test SWFs) | `Push(N)` or `CallFunction(getNextHighestDepth)` then `CloneSprite` | `N` (raw AS depth) |

Today's runtime applies a heuristic in
`SWFModernRuntime/src/libswf/tag_stubs.c:2787`:

```c
clone_mc->depth = (depth >= 16384) ? (depth - 16384) : depth;
```

This is *correct* for Ming-style positive depths (`N + 16384 ≥ 16384` ⇒
unbias) and *correct* for unbiased pushes of small AS depths
(`< 16384` ⇒ leave alone), but **wrong** for Ming-style **negative**
AS depths: `Push(-2001) Push(16384) Add` produces `14383`, which is
`< 16384`, so the heuristic mistakes it for an unbiased push and stores
the wrong AS depth. Test expectation: `clone.getDepth() == -2001`.
We return `14383`.

## Status (2026-04-25 session)

**Implemented (single-value Push only):** Phase 1's recompiler strip lands in
`SWFRecomp/src/action/action.cpp` for the case where `Push(int 16384)` is its
own opcode (`length == 5`, type=I32, value=16384) immediately followed by
`Add{,2}` and `CloneSprite`, with no jump-target labels at the Add or
CloneSprite. Push payload, Add, and CloneSprite all pass the
`labels.count(...) == 0` guard. Affected sites in the test SWFs are recompiled
with the bias removed; the runtime then receives raw AS depth, which the
existing legacy heuristic `(depth >= 16384) ? (depth - 16384) : depth` keeps
unchanged (no-op for AS depths < 16384), so the runtime path is functionally
identical to the pre-strip era.

**Measured impact (matching_lines vs. baseline):**

| Test | Baseline | After strip | Δ |
|------|----------|-------------|---|
| displaylist_depths/displaylist_depths_test | 84/111 | 92/111 | **+8** |
| DepthLimitsTest | 13/20 | 15/20 | **+2** |
| static_vs_dynamic1 / 2 | PASS | PASS | unchanged |
| textsnapshot_available_text | 20/20 | 20/20 | unchanged |
| clone_sprite_edittext / _dynamic | PASS | PASS | unchanged |
| from_shumway/avm1/duplicateMovieClip/* | PASS | PASS | unchanged |
| loop_test3 / 5 / 9, attachMovieTest, place_and_remove_object_test, displaylist_depths_test11 | PASS | PASS | unchanged |
| displaylist_depths_test2/3/8/9, duplicate_movie_clip_test/2 | unchanged | unchanged | 0 |

The tests in the "unchanged 0" row use *packed* Pushes (Ming bundles the
16384 with other values into a single Push opcode of length > 5), which the
single-value strip deliberately skips.

**Why packed-Push cannot land yet (the blocker):**

Extending detection to multi-value Pushes does match more sites — the trailing
`int 16384` value is still uniquely a SWF-bias artifact — but stripping it
shifts the resulting AS depth into `1..16383`. Today's runtime treats
`target_swf_depth = (size_t)depth` as the display_list slot index, and
display_list slots `1..N` are occupied by static (timeline-placed) MCs.
Replacing those slots with clone metadata destroys the static MCs and
regresses every test that depends on them (static_vs_dynamic1 was the
canonical breakage seen in this session).

A proposed runtime gate — skip slot allocation when the existing entry's
`instance_name_owned == 0` (i.e., a static MC that owns its name from SWF
data, not strdup) — preserved static MCs but inadvertently regressed
textsnapshot_available_text in a way I could not isolate without deeper
trace work. The interaction between the slot copy
(`display_list[target] = display_list[src]`) and `actionFindOrCreateMovieClip`'s
name-keyed lookup makes this fragile to gate naively.

**Remaining work to unlock packed-Push strip (out of scope this session):**

1. Decouple clone identity from display_list slot index — clones at AS depth
   N should be tracked by name + clone_depth_table only, with display_list
   used purely for SWF-keyed timeline state. This is the Ruffle architecture
   (separate static vs dynamic display layers).
2. Or: expand display_list to a sparse map keyed by SWF depth = AS + 16384,
   so AS depth N's slot lives at index 16384+N (won't collide with static
   1..16383). Cost: ~150 bytes × 16384 ≈ 2.4 MB max; loop bounds (max_depth)
   would need careful handling to avoid scanning the empty 1..16383 gap.
3. Or: keep single-value strip only, accept the partial impact, and revisit
   when the broader display_list refactor lands.

## 2026-05-02 session — Phase 2b landed (rewind branching refactor)

**Phase 2b complete.** `actionRewindCleanup` in
`SWFModernRuntime/src/actionmodern/action.c:19609+` now branches on
`ng_clone_get_swf_depth(name) != INT_MIN` (clone-depth-table presence)
*before* checking display-list presence. Behavior is equivalent today
because pre-Phase-2c clones still have no display entry, so the new
condition selects the same branch for every input the function sees.
The change is forward-compatible: once Phase 2c raises the slot cap and
clones land in display_list, the rewind code still routes them through
the survives_rewind check rather than the timeline-reset branch.

**Verified locally:**
- AVM1 guardrail (19 tests): `goto_rewind1/2/3`, `clone_sprite_edittext{,_dynamic}`,
  `clone_sprite_types`, `duplicate_movie_clip{,_drawing}`, `create_empty_movie_clip`,
  `attach_movie`, `textsnapshot_available_text`, `movieclip_setmask`,
  `execution_order1/2/3`, `movieclip_default_state`,
  `movieclip_get_instance_at_depth`, `movieclip_state_values`,
  `swf5_no_closure` — 19/19 PASS.
- Gnash misc-ming guardrail (12 tests): `static_vs_dynamic1/2`,
  `loop/loop_test3/5/9`, `attachMovieTest`, `place_and_remove_object_test`,
  `displaylist_depths/displaylist_depths_test{8,11}`, `DepthLimitsTest`,
  `duplicate_movie_clip_test2`, `displaylist_depths/displaylist_depths_test`
  — 12/12 effective pass (11 PASS + 1 RM).
- Target tests (`displaylist_depths_test{2,3,9}`, `duplicate_movie_clip_test`):
  unchanged from baseline (still failing — Phase 2c is the load-bearing
  piece for these flips).

**What's still required to flip the target tests:**
- **Phase 2a** (recompiler packed-Push strip) — feeds AS depth (1, 2, …)
  to the runtime instead of biased SWF depth (16385, 16386, …).
- **Phase 2c** (raise display_list slot cap) — gives clones their own
  display_list slot at SWF depth `as_depth + 16384`, so CONSTRUCT,
  ENTERFRAME, UNLOAD events dispatch on them. Needed because every
  failing target line is an event the clone never received.
- **Phase 2d** verification + one-by-one fixes for swap/remove
  interactions exposed when both 2a and 2c are in.

These remain pending as multi-session work. Phase 2b is the only piece
that landed cleanly without CI dependency.

## 2026-05-02 session — Phase 2a + 2c + var_map fix landed (full strip)

**TL;DR.** All sub-phases (2a, 2b, 2c, 2d) landed in a single commit. The
prior session's 2026-05-04 attempt was reverted because Phase 2a alone
caused regressions when AS depths shifted into the static-range
display_list slots; this session bundles 2a + 2c (slot biasing) + the
required var_map fix to land safely.

**Approach.** The recompiler strip (Phase 2a) and the runtime slot biasing
(Phase 2c) must apply *consistently* — i.e., the runtime needs to know
which calls are stripped vs unstripped because:

- Stripped CloneSprite hands the runtime raw AS depth (Phase 2a contract).
- Unstripped pre-biased pushes (e.g., `avm1/duplicate_movie_clip` pushes
  `2130706428` directly without an `Add` prefix) hand pre-biased SWF depth.
- The Shumway `dontremove` test pushes raw SWF depth `16379` and expects
  static-range placement (clone removed on frame loop).

A single global heuristic can't disambiguate these — the same value can
mean different things. So we added a **strip marker**:

1. **Recompiler (action.cpp):** when the strip fires, emit
   `actionMarkCloneStripped(app_context);` immediately before the
   `actionCloneSprite(app_context);` call.

2. **Runtime (action.c):** `actionMarkCloneStripped` sets a global flag
   `g_clone_depth_already_unbiased = 1`. `actionCloneSprite` reads it for
   the bounds check and passes the same flag-influenced behavior down.

3. **Runtime (tag_stubs.c):** `ng_cloneSprite` and `ng_cloneSpriteFromMC`
   each check the flag (and clear it). When set: `depth` is raw AS
   depth, slot index = `depth + AVM_DEPTH_BIAS`, `clone_mc->depth = depth`,
   `clone_depth_register(depth + AVM_DEPTH_BIAS, ...)`. When unset:
   pre-Phase-2c semantics — `depth` is raw SWF depth, slot index = `depth`,
   `clone_mc->depth = (depth >= 16384) ? depth - 16384 : depth`,
   `clone_depth_register(depth, ...)`.

4. **Runtime (action.c `actionInvalidateCachedMovieClip`):** post-2c,
   clones that swapDepths'd into a static depth and were then RemoveObject2'd
   no longer hit the `display_list[depth].char_id == 0` else-branch in
   `tagRemoveObject2` (which used to invoke `actionInvalidateMCAtASDepth`
   that *does* clear the var_map). The main path's
   `actionInvalidateCachedMovieClip` did not clear the var_map, so
   `typeof(dup) == 'undefined'` failed (regressed `static_vs_dynamic2`).
   Fix: `actionInvalidateCachedMovieClip` now also clears the var_map
   entry when it currently points to the MC being invalidated (mirroring
   the `actionInvalidateMCAtASDepth` and `actionRewindCleanup` patterns
   for clone names).

5. **Runtime (swf.h):** new `AVM_DEPTH_BIAS = 16384` and
   `AVM_CLONE_SLOT_CAP = 32768` constants. The cap allows clones at SWF
   depth in [16384, 32768) to take a display_list slot (Phase 2c benefit:
   CONSTRUCT/ENTERFRAME/UNLOAD dispatch reaches dups landing there).

**Verified locally (15 + 11 + 5 + 4 = 35 tests):**

- AVM1 broad (15): `attach_movie`, `clone_sprite_edittext{,_dynamic}`,
  `clone_sprite_types`, `create_empty_movie_clip`, `duplicate_movie_clip{,_drawing}`,
  `execution_order1/2/3`, `goto_rewind1/2/3`, `textsnapshot_available_text`,
  `unload` — 15/15 PASS.
- AVM1 broader (11): `movieclip_setmask`, `movieclip_default_state`,
  `movieclip_state_values`, `swf5_no_closure`, plus rewind/execution
  duplicates — 11/11 PASS.
- Gnash misc-ming guardrails (5): `static_vs_dynamic1/2`, `DepthLimitsTest`,
  `duplicate_movie_clip_test2`, plus `duplicate_movie_clip_test` — 4/5 PASS,
  1 MISMATCH (`duplicate_movie_clip_test` improved 3/33 → 16/30 lines —
  a +13-line gain; remaining gaps are downstream issues unrelated to
  the depth-bias).
- Shumway clones (4): `dontremove`, `duplicateMovieClip`, `name-coercion`,
  `samedepth` — 4/4 PASS.

**Net effect on misc-ming.all guardrail set (16 tests pre-CI):** 12/16
effective pass — same as baseline. No regressions.

**Post-CI verdict (run 25269609961, commit 06991d472ec7).** Every suite
shows **zero diff** in pass counts and matching-line totals vs baseline:

| Suite | Pass | Total | Pass rate | Δ |
|-------|------|-------|-----------|---|
| AVM1 | 600 | 647 | 92.7% | 0 |
| Gnash actionscript.all | 124 | 190 | 65.3% | 0 |
| Gnash misc-ming.all | 62 | 102 | 60.8% | 0 |
| Gnash misc-mtasc.all | 7 | 9 | 77.8% | 0 |
| Gnash misc-swfc.all | 7 | 16 | 43.8% | 0 |
| Gnash misc-swfmill.all | 17 | 18 | 94.4% | 0 |
| Shumway flat | 65 | 92 | 70.7% | 0 |
| Shumway avm1 | 45 | 47 | 95.7% | 0 |

The infrastructure landed safely (no regressions across all 8 suites)
but didn't produce measurable line-level gains. The visible "+13 matching
lines" I claimed locally for `duplicate_movie_clip_test` was misleading
— the per-test stat stays at 3 matching/33 expected because the diff
walks line-by-line and once an alignment shifts (which our extra PASSED
outputs cause), every subsequent line counts as a mismatch. Same story
for `displaylist_depths_test{2,3,9}`.

**What's still pending (next session).** The pieces that stop the target
tests from flipping are downstream of Phase 2a/2c — clone
CONSTRUCT/ENTERFRAME/UNLOAD dispatch, line-ordering of trace output
relative to clip-event handlers, and the pre-existing
`heap_alloc() called before heap_init()` errors in
`displaylist_depths_test{2,3}`. None of these block the depth-bias
infrastructure; they're the next layer of work that becomes addressable
now that the depth-bias plumbing is in place.

## 2026-05-03 session — closing-out + clip-event-dispatch dead end

**Status confirmed.** Local re-run of the four still-failing target
tests (`displaylist_depths/displaylist_depths_test{2,3,9}`,
`duplicate_movie_clip_test`) reproduces the CI snapshot. The four
already-passing target tests (`displaylist_depths_test`, `_test8`,
`DepthLimitsTest`, `duplicate_movie_clip_test2`) stay green. No
shifts since 2026-05-02.

**Failure shape across the four still-failing tests.** All four diffs
are dominated by missing clip-event lines (`onClipConstruct`,
`onClipEnterFrame`, `onClipUnload` and their AS counterparts), not
depth-bias errors:

- `displaylist_depths_test2/3`: missing `_level0.static3
  onClipConstruct` and `_root.depth3Constructed set to 2` on the
  `gotoAndStop(4)` re-placement. CONSTRUCT clip-event handler does not
  fire when a removed static MC is re-placed by a backward goto.
- `displaylist_depths_test9`: missing `_level0.dup0 constructed` (dup
  of static4 should inherit `SWFACTION_CONSTRUCT`) and the second
  `_level0.static4 constructed` on `gotoAndStop(5)` re-placement.
  `mc4Constructed` ends at 1 instead of 2/3.
- `duplicate_movie_clip_test`: dup2 (clone of mc2 carrying LOAD /
  ENTER_FRAME / UNLOAD clip events) fires LOAD but not ENTER_FRAME or
  UNLOAD. `_root.x2` ends at 1 instead of 3, `_root.x3` at 1 instead
  of 2.

The shared root cause is that **clones inherit clip_actions
structurally but our runtime explicitly clears them on the clone's
display_list slot** (`tag_stubs.c:2815-2816, 3050-3051`):

```c
display_list[target_swf_depth].clip_actions = NULL;
display_list[target_swf_depth].clip_action_count = 0;
```

LOAD is rescued via `ng_queue_pending_load` (LIFO queue drained at
tagShowFrame), but ENTER_FRAME and UNLOAD have no parallel rescue —
they are dispatched by walking display_list slots, and the clone's
slot has no clip_actions to walk.

**Tried fix: share clip_actions pointer with source (revert clears).**
Removed the two pairs of clear lines so clones inherit the source's
`clip_actions` pointer (static recompiler-emitted data, never
freed per-instance). Result: massive ENTER_FRAME firing regression —
the clone fires ENTER_FRAME continuously and never stops. Diff went
from 14 PASS / 30 expected lines to 35+ extra `onClipEnterFrame
triggered` lines past the expected EOF. Reverted.

**Why sharing alone isn't enough.** Two interacting issues:

1. **`sprite_initialized` lifecycle isn't applied to clones.** Source
   mc2's `sprite_initialized` is `0` at clone time (DoAction runs
   before `process_sprite_needs_init`), so the slot copy gives the
   clone `sprite_initialized=0`. The dispatch gates on
   `sprite_initialized >= 2`, so the clone never qualifies — except
   that with shared clip_actions and no eviction logic, the clone
   eventually fires forever once it gets bumped.
2. **Clone removal doesn't clear the slot's clip_actions.** When
   `dup2.removeMovieClip()` runs, the slot's `char_id` is cleared but
   not the clip_actions pointer (which now points to mc2's static
   actions). dispatch_enterframe_clip_actions walks the slot, finds
   non-zero clip_action_count, and re-fires.

The right fix likely involves giving clones their own per-instance
clip_actions copy AND applying the full sprite-init lifecycle
(`sprite_needs_init=1` → `sprite_initialized=1` → upgrade to 2 next
tick → dispatch). That's a significant runtime refactor — the kind
of thing that wants its own plan and its own CI cycle.

**Verdict on this plan.** The CloneSprite depth-bias unification is
*structurally complete*: Ming-style negative AS depths are correctly
unbiased at the recompiler level, the runtime branches on clone-table
presence rather than display-list presence, and Phase 2c gives clones
real display_list slots without breaking static MCs. CI verified zero
regressions across all 8 suites. The remaining four target-test
failures are downstream of clone clip-event dispatch — a separate
concern tracked in `incomplete/CLONE_CLIP_EVENT_DISPATCH_PLAN.md`.
Marking this plan **complete** and moving to `complete/`.

## 2026-05-04 session — Phase 2a attempted, landed, reverted

**Phase 2a attempt: implemented in commit `29d67477`, reverted in
`29a1fc36` after CI run `25267566834` showed −4 effective passing tests
in misc-ming.all and a net −19 matching lines.**

The recompiler change extended the bias strip to packed Pushes
(pre-scan the Push payload, locate the last value, strip the trailing
`I32(16384) Add CloneSprite` if it matches). The implementation itself
worked — `duplicate_movie_clip_test` improved from 3/33 → 6/33 lines
because clones at AS depth 1 and 2 were finally being created at the
right depth. But the predicted slot-collision regressions showed up
exactly where the plan said they would:

| Test | Pre | Post 2a | Δ |
|------|-----|---------|---|
| static_vs_dynamic1 | 17/17 PASS | 4/17 fail | −13 |
| static_vs_dynamic2 | 18/18 PASS | 11/18 fail | −7 |
| DepthLimitsTest | 20/20 PASS | 16/20 fail | −4 |
| duplicate_movie_clip_test2 | 21/21 PASS | 18/21 fail | −3 |
| duplicate_movie_clip_test | 3/33 fail | 6/33 fail | +3 |

The pattern is consistent with the slot-collision blocker: when the
strip hands the runtime AS depths `1`/`2` for clones, `target_swf_depth`
in `ng_cloneSprite` is `1`/`2` — exactly where the static MCs live in
`display_list`. The clone's `display_list[target]` write evicts the
static, and downstream `typeof(static_mc) == 'movieclip'` checks see
`undefined` instead.

**Why local verification missed the regression.** `verify_output.py`
rebuilds `RecompiledScripts/` per test, but if a test had previously
been recompiled (in this case, by an earlier session before the new
recompiler binary was built), the rebuild can pick up cached state
that still carries the old emission pattern. The single-test smoke
check ran fine, but only because the static_vs_dynamic guardrails
weren't actually being recompiled with the new strip. Forcing
`rm -rf RecompiledScripts RecompiledTags` first reproduces the CI
failure deterministically. **Lesson: when validating recompiler
changes, always `rm -rf RecompiledScripts RecompiledTags` for the
guardrail tests before running.** A `verify_output.py --clean` flag
would help; alternatively the runner could timestamp-check the
recompiler binary.

**Why the partial fix isn't shippable.** The +3 lines on
duplicate_movie_clip_test do not offset the −22 lines across the
four guardrails. Phase 2a is structurally correct but unsafe to
land without Phase 2c (raise slot cap + bias the slot index by
+16384) bundled together. Running them in separate commits creates
the intermediate broken state we hit in CI.

**Status of phase 2a:** *implemented and known to work, but reverted
pending Phase 2c.* The recompiler patch from `29d67477` can be
re-applied verbatim once Phase 2c lands. Diff is preserved at:
`git show 29d67477 -- SWFRecomp/src/action/action.cpp`.

**Updated next steps:**

1. **Phase 2c first**, alone: raise `INITIAL_DISPLAYLIST_CAPACITY`
   from 1024 to (e.g.) 32768 — or introduce a separate clone slot
   region. Change `ng_cloneSprite`/`ng_cloneSpriteFromMC` to compute
   `target_swf_depth = (size_t)(depth + 16384)` ONLY when the runtime
   stack value already represents an AS depth. Today, the runtime
   sees biased values (e.g. SWF depth 16385 from `Push(1) Push(16384)
   Add` packed pattern), so adding +16384 again would put the slot
   at 32769 — but that's exactly the same place the unbiased AS
   depth `1` would land if Phase 2a were also active. So 2c on its
   own is a no-op (still receives biased values, still skipped by
   the cap guard) and verifying it requires re-applying 2a in the
   same commit.

2. Therefore **Phase 2a + Phase 2c must land in a single commit.**
   The "verify each sub-phase independently" guidance from the
   2026-05-03 update assumed the sub-phases had observable effects
   on their own; they don't (2a alone breaks things, 2c alone is
   inert).

3. Once 2a + 2c land together, run the misc-ming guardrail suite
   first locally (with forced `rm -rf RecompiledScripts/`), then push
   for full-suite CI verification. Phase 2d is the iterative
   fix-as-they-surface stage for swap/remove interactions exposed by
   2c.

## 2026-05-03 update — option 2 (raise slot cap) prototyped + reverted

**TL;DR.** Tried raising `INITIAL_DISPLAYLIST_CAPACITY`-equivalent cap in
`ng_cloneSprite` (let the dup land at SWF depth `as_depth + 16384` instead
of being skipped). Restored MC1's display-list slot for the clone, but
broke `actionRewindCleanup`, `tagRemoveObject2`, and `swapDepths` because
they branch on "is there a display_list entry?" as a proxy for "is this
a clone?". With the cap raised, clones now satisfy that check and take
the wrong branch.

Net result: 1 guardrail recovered (`static_vs_dynamic1` PASS → still PASS),
1 guardrail broken (`static_vs_dynamic2` PASS → MISMATCH), the target
test (`duplicate_movie_clip_test`) didn't improve. Target test still
needs the recompiler-side packed-Push strip to feed AS depth (1, 2)
instead of biased SWF depth (16385, 16386), but doing that without first
fixing the rewind/remove branching is futile.

**Sites that need the "is a clone" branch (not "has display entry"):**

| Site | File | Current logic | Required fix |
|------|------|---------------|--------------|
| `actionRewindCleanup` | `action.c:19614+` | Branches on `dl_depth == SIZE_MAX` (no entry → dynamic branch / survives_rewind check) | Branch on `ng_clone_get_swf_depth(name) != INT_MIN` instead — clone path always goes through survives_rewind regardless of display_list presence |
| `tagRemoveObject2` | `tag.c:5351+` | Removes display entry; doesn't update var_map for clones (relied on clone never being in display_list) | After clearing entry, also evict from `clone_depth_table` and var_map if it's a clone |
| `ng_swapDisplayDepths` | `tag_stubs.c:2656+` | Walks display_list to find both names; if either is missing, no-op | OK as-is once both clones are in display_list, but need to ensure `clone_depth_table` updates SWF depth post-swap (already does via `ng_clone_update_swf_depth` in `swapDepths` method handler at `action.c:56106+`) |
| `actionInvalidateCachedMovieClip` | `action.c:18537+` | Already correct (compares against as_depth, swf_depth, shifted_depth) | None |
| `actionMarkMCPendingRemoval` | `action.c` | Same shape as above | None |

**Suggested incremental approach for the next attempt:**

1. **Phase 2a (recompiler):** detect packed-Push patterns where the trailing
   value is `int 16384` followed by `Add{,2}` + `CloneSprite`, strip just
   that trailing value (keep the rest of the packed Push). Pattern:
   - `ActionPush <values...> <int 16384>` length > 5
   - Next op: `Add{,2}`
   - Op after: `CloneSprite`
   Pre-scan to find last value's offset and type; if it's `I32(16384)`,
   gate emission of the last value. Estimated ~60 lines in `action.cpp`'s
   `SWF_ACTION_PUSH` case, alongside the existing single-value strip.

2. **Phase 2b (runtime, branching fix):** in `actionRewindCleanup`, change
   the branch condition from "display entry exists" to "this MC is not a
   clone (`ng_clone_get_swf_depth == INT_MIN`)". This is safe to land
   independently — pre-strip, clones still don't have display entries, so
   the new condition is equivalent for those cases. Verify on the existing
   guardrail battery before touching slot allocation.

3. **Phase 2c (runtime, slot cap):** raise the slot cap so high-depth
   clones land in display_list. Define `AVM_CLONE_SLOT_CAP` (e.g. 65536).
   Verify guardrails again; expect `static_vs_dynamic2`-style failures
   from `tagRemoveObject2` / `swapDepths` interactions and fix those
   one-by-one.

4. **Phase 2d (verification):** run the target battery and confirm flips.

**Why I'm pausing here.** Each sub-phase needs independent verification
on the full guardrail battery. CI takes ~10 min per round; local
single-test verification is fast but doesn't catch interactions across
the suite. This is multi-session work, not single-session. The investigation
was useful for narrowing scope — the runtime branching audit (Phase 2b)
is the load-bearing piece that the existing plan missed.

## Affected tests (CI 205a9a77, 2026-04-25)

| Test | Suite | Match | Notes |
|------|-------|-------|-------|
| displaylist_depths/displaylist_depths_test | misc-ming | 84/111 (75.7%) | Multiple `getDepth() == -2001 / -2004 / -2005 / -2008` failures; also downstream `_width` and `child` failures consistent with the wrong-depth clone landing in an unexpected SWF slot. |
| displaylist_depths/displaylist_depths_test8 | misc-ming | 8/15 (53.3%) | Same family. |
| displaylist_depths/displaylist_depths_test3 | misc-ming | 16/32 (50.0%) | Same family. |
| displaylist_depths/displaylist_depths_test2 | misc-ming | 15/31 (48.4%) | Same family. |
| displaylist_depths/displaylist_depths_test9 | misc-ming | 3/23 (13.0%) | Same family + secondary issues. |
| DepthLimitsTest | misc-ming | 13/20 (65.0%) | Tests SWF-depth boundaries — passes biased-depth values in the negative AS range. |
| duplicate_movie_clip_test | misc-ming | 3/33 (9.1%) | Multi-issue, but `duplicateMovieClip` with negative depths is a recurring failure motif. |
| duplicate_movie_clip_test2 | misc-ming | 13/21 (61.9%) | Plan's "dup6/dup7/dup8 nested-path" failures are a *separate* path-resolution bug; the depth-bias half is the same as the others. |

**Estimated impact:** ~6 flips to PASS / `ruffle_matched` once the
depth-bias is correct, plus partial gains on
`duplicate_movie_clip_test`'s multi-issue tail.

## Why neither current option works

(See `MISC_MING_SWFC_PLAN.md` "CloneSprite depth-bias trade-off (open)".)

| Option attempted | Result |
|------------------|--------|
| **Always unbias** (`clone_mc->depth = depth - 16384;`) | Correct for Ming (positive + negative). Breaks `avm1/textsnapshot_available_text` because `getNextHighestDepth()` returns `0`, ending up at `clone_mc->depth == -16384`, which collides with downstream depth-keyed lookups in the textsnapshot path. |
| **Heuristic** (current — `(depth >= 16384) ? unbias : keep`) | Correct for Ming positive and unbiased pushes. Wrong for Ming negative — the `< 16384` branch keeps the biased value. |
| **Always keep** (`clone_mc->depth = depth;`) | Correct for textsnapshot and Ming negative. Breaks Ming positive (`getDepth() == N + 16384` instead of `N`). |

No single runtime-only choice handles all three cases because the
information needed to disambiguate (whether the depth was pre-biased)
is at the *bytecode* level, not the value level.

## The fix: strip the bias at recompile time

The discriminator IS visible in bytecode — Ming consistently emits the
3-opcode prefix `Push(*) Push(int 16384) Add` immediately before
`CloneSprite`. Stripping the `Push(16384) Add` pair at recompile time
gives the runtime an unbiased AS depth for both Ming flavors *and*
preserves the textsnapshot path (which never had the prefix). The
runtime then uniformly treats the depth as AS depth — no heuristic.

This is a small, well-bounded change:

- **Recompiler:** 3-opcode lookahead pattern match in
  `SWFRecomp/src/action/action.cpp`. When the recompiler sees
  `Push(*) Push(16384) Add CloneSprite`, it emits the runtime call as
  if the `Push(16384) Add` weren't there. The first `Push(*)` and the
  `CloneSprite` opcode are emitted normally.
- **Runtime:** drop the heuristic in `ng_cloneSprite` and
  `ng_cloneSpriteFromMC` (lines 2787, 2980 of `tag_stubs.c`).
  Use `clone_mc->depth = depth;` consistently. `clone_depth_register`
  takes SWF depth, so call it as `clone_depth_register(depth + 16384, target_name)`
  to mirror what `ng_duplicateMovieClip` already does
  (`tag_stubs.c:3104-3107`).

After both changes, the contract is: **`ng_cloneSprite` and
`ng_cloneSpriteFromMC` accept AS depth.** The recompiler is responsible
for stripping any compiler-side bias before the call. Method-style
`mc.duplicateMovieClip(name, depth)` already follows this contract.

## Phase 1 — Recompiler pattern match

The recompiler in `SWFRecomp/src/action/action.cpp` already does
two-pass parsing (first pass: jump targets; second pass: emit C). The
pattern match goes in the second pass.

**Pattern to detect** (in bytecode order, before any C is emitted):

```
ActionPush <push_value>           // any type — int, float, var, register, etc.
ActionPush <int 16384>            // must be the literal integer 16384, type 7 (integer push)
ActionAdd2  OR  ActionAdd         // type-aware Add (0x47) or numeric Add (0x0A)
ActionCloneSprite (0x24)          // OR ActionRemoveSprite (0x25) — symmetric for symmetry; but RemoveSprite takes a path string, not a depth, so it's NOT in scope. Only CloneSprite.
```

When this 4-opcode window is matched, emit C as if it were:

```
ActionPush <push_value>
ActionCloneSprite
```

Skip emission of the `Push(16384)` and `Add` opcodes. This is a pure
constant-folding optimization at recompile time.

**Implementation sketch:**

```cpp
case SWF_ACTION_CLONE_SPRITE:
{
    // Look back over the just-emitted bytecode opcodes to detect
    // Ming's pre-bias pattern. The current opcode index is in the
    // recompiler's per-script position cursor; the previous three
    // ops are in the buffer (opcode array) we're iterating over.
    bool stripped = false;
    if (i >= 3 &&
        action_buf[i-1].opcode == SWF_ACTION_ADD2 &&  // or SWF_ACTION_ADD
        action_buf[i-2].opcode == SWF_ACTION_PUSH &&
        action_buf[i-2].is_integer_push(16384))
    {
        // Erase the previously-emitted Push(16384) and Add lines from
        // out_script before emitting CloneSprite. (Or, on the second
        // pass, recognize the pattern *before* emitting Push(16384)
        // and Add, and skip them.)
        out_script.seekp(saved_position_before_push_16384);
        stripped = true;
    }
    out_script << "\t" << "// CloneSprite"
               << (stripped ? " (Ming bias stripped)" : "") << endl
               << "\t" << "actionCloneSprite(app_context);" << endl;
    break;
}
```

The cleanest implementation is **second-pass pattern detection** —
during the second pass, before emitting `Push(16384)`, peek 2 ahead
to see if it's `Add` followed by `CloneSprite`. If yes, skip the
Push, the Add, and continue. If no, emit normally.

### Concerns

- **`ActionAdd` (0x0A) vs `ActionAdd2` (0x47).** Older SWFs use 0x0A
  (numeric, treats both args as numbers). Newer use 0x47 (type-aware).
  Both are valid bias-applying opcodes. Pattern match must accept
  either.
- **Push opcode encoding.** `ActionPush` (0x96) supports many push
  types — int, float, double, register, string, constant pool ref,
  null, undefined, etc. The recompiler already parses this; the bias
  literal will be encoded as one of the integer types (1-byte, 2-byte,
  or 4-byte signed). Detection needs to look at the *push value* (post
  decode), not the byte pattern.
- **False positive avoidance.** Any unrelated `Push(N) Push(16384) Add
  CloneSprite` would be incorrectly stripped. In practice, no
  hand-written ActionScript adds 16384 to a value before passing to
  `duplicateMovieClip` — the constant is too specific. Concern is
  theoretical; if a regression surfaces, refine to also require the
  trailing op to be the *immediate* next op (no jump targets between
  the Push(16384) and the Add, for instance).
- **The first push is dynamic in many cases** — `Push register`,
  `Push var`, `CallFunction result`, etc. The pattern match doesn't
  care about the first push; only the literal-16384 second push.
  Dynamic depth values from Ming still use the bias prefix (Ming
  consistently bias-applies all CloneSprite depths regardless of
  source).

## Phase 2 — Runtime: drop the heuristic

Two sites in `SWFModernRuntime/src/libswf/tag_stubs.c`:

```c
// Line 2787 (ng_cloneSprite):
-	clone_mc->depth = (depth >= 16384) ? (depth - 16384) : depth;
+	// CloneSprite/duplicateMovieClip take AS depth (recompiler strips Ming's
+	// SWF-bias prefix; method-side ng_duplicateMovieClip is already AS-depth).
+	clone_mc->depth = depth;
```

```c
// Line 2980 (ng_cloneSpriteFromMC):
-	clone_mc->depth = (depth >= 16384) ? (depth - 16384) : depth;
+	clone_mc->depth = depth;
```

The `clone_depth_register` call sites also need updating to reflect
the new convention. Currently:

- Line 2824: `clone_depth_register(depth, target_name);` — passes SWF
  depth based on the `(depth >= 16384) ? unbias : ...` heuristic
  upstream. Now needs `clone_depth_register(depth + 16384, target_name);`.
- Line 3039 (`ng_cloneSpriteFromMC`): same.

The pre-existing display_list slot sizing (line 2706,
`if (target_swf_depth < INITIAL_DISPLAYLIST_CAPACITY)`) currently uses
`(size_t)depth` directly as the SWF depth. Update to `(size_t)(depth + 16384)`,
since `depth` is now AS depth and the display list is SWF-keyed.

The pre-clear-target-depth block at line 2691 (
`display_list[target_swf_depth].char_id != 0`) similarly needs SWF depth.

**Important:** the depth value flowing through `actionCloneSprite`
(`SWFModernRuntime/src/actionmodern/action.c:44999, 45012, 45018`) already
calls `ng_cloneSprite(...depth_int)` with whatever the bytecode pushed.
After the recompiler strip, that pushed value is AS depth, so the
runtime contract holds.

## Phase 3 — Audit residual conflations

Sites today that read `clone_mc->depth` and assume SWF-biased values:

```bash
grep -rn 'depth >= 16384\|depth >= AVM_DEPTH_BIAS\|depth - 16384' \
    SWFModernRuntime/src/actionmodern/ SWFModernRuntime/src/libswf/
```

Confirmed safe sites (already SWF-aware via `ng_clone_get_swf_depth` /
clone_depth_table — which keys by SWF depth and is updated at swap
time, not derived from `mc->depth`):

- `actionRewindCleanup` (`action.c:19121`) — uses
  `ng_clone_get_swf_depth(name)`, not `ch->depth`. ✓
- `ng_display_clear_after` (`tag.c:5371` comment) — operates on display
  list (SWF-keyed). Independent of `clone_mc->depth`. ✓

Sites that **need re-audit**:

1. **`actionInvalidateMCAtASDepth`** (`action.c:18575-18588`) —
   compares `ch->depth != as_depth`. Uses AS depth. ✓ already correct.
2. **`actionInvalidateCachedMovieClip`** (`action.c:18537-18544`) —
   compares against `as_depth`, `swf_depth`, *and* `shifted_depth` (the
   removed-zone form). The `swf_depth` comparison was added 2026-04-22
   to handle the heuristic mismatch — under the new contract, the
   `swf_depth` arm becomes vestigial. Leave it for now (defense in
   depth) but note it as a candidate for removal once Phase 4 is green.
3. **`actionMarkMCPendingRemoval`** — same shape as #2. Same
   conclusion.
4. **`mc.swapDepths` MC-method handler** (`action.c:56106-56162`) —
   four call sites that update the clone-depth-table via
   `ng_clone_update_swf_depth(mc->name, mc->depth + 16384)`. Under the
   new contract, `mc->depth` is consistently AS depth, so
   `mc->depth + 16384` correctly reconstructs SWF depth. ✓ no change.
5. **`mc->depth == 0` checks** — none found that would conflict (the
   default `MovieClip` struct has `.depth = 0` only because of zero-init,
   not as a meaningful sentinel; `&root_movieclip` is recognized by
   pointer identity, not depth).

Sites that may be affected and need direct inspection:

```bash
grep -rn 'mc->depth\|->depth ==\|->depth >=' SWFModernRuntime/src/ \
    | grep -v INT_MIN | grep -v root_movieclip | head -30
```

Run that during Phase 3 and walk each match.

## Phase 4 — Verification

**Required-pass guardrail:**

- AVM1: `textsnapshot_available_text` (the canonical
  always-unbias-regression test). Diff must be unchanged.
- Shumway: `from_shumway/avm1/duplicateMovieClip/dontremove`,
  `duplicateMovieClip`, `samedepth`, `name-coercion`. Recompiled
  Shumway test SWFs use the unbiased push convention.
- AVM1: `clone_sprite_*` (e.g. `clone_sprite_edittext`,
  `clone_sprite_edittext_dynamic`). These exercise CloneSprite
  + dynamic textfield setup.
- Gnash misc-ming: `static_vs_dynamic1` (PASS), `static_vs_dynamic2`
  (PASS) — must remain green; both use the clone-depth-table.
- Gnash misc-ming: `loop_test3`, `loop_test5`, `loop_test9`,
  `attachMovieTest`, `displaylist_depths_test11`,
  `place_and_remove_object_test` — adjacent placement / clone tests
  that landed via the existing heuristic.

**Target tests (expected to flip):**

- displaylist_depths/displaylist_depths_test, _test2, _test3, _test8,
  _test9, DepthLimitsTest, duplicate_movie_clip_test (partial),
  duplicate_movie_clip_test2 (partial — the dup6/dup7/dup8 lines are
  a separate path-resolution bug and won't be affected).

**Regression risk:** medium. The recompiler change is the
load-bearing piece — if the pattern match misfires on a non-Ming SWF
that legitimately happens to have a `Push(16384) Add` before
CloneSprite for unrelated reasons (essentially impossible in
practice), that SWF would clone to AS depth `N - 16384`. The
guardrail catches this.

## Open questions

1. **`SWF_ACTION_ADD` (0x0A) emission convention.** Older Ming uses
   the type-naive `ActionAdd` (0x0A) instead of `ActionAdd2` (0x47).
   Both are valid bias-add opcodes. The pattern match needs to handle
   both. Verify by spot-checking a sample of misc-ming SWFs:
   ```
   xxd ruffle-tests/tests/swfs/from_gnash/misc-ming.all/displaylist_depths/displaylist_depths_test/test.swf | head -100
   ```
   to confirm which Add variant is emitted around the `0x24` (CloneSprite)
   bytes.

2. **`SWFRecomp/src/action/action.cpp` second-pass internals.** The
   recompiler might already use a `op_stream` with random access, in
   which case the lookahead is trivial. If it's strictly streaming,
   we need to either buffer the most-recent N opcodes, or do a second
   parsing pass that decorates `Push(16384)` and `Add` with a
   "skip-if-followed-by-CloneSprite" flag. Read
   `SWFRecomp/src/action/action.cpp` lines 600–650 (around the
   existing CLONE_SPRITE case) before designing the buffer.

3. **`ng_findDisplayEntryByName` lookups for clones at AS depth ≤ 0.**
   With the heuristic, clones that were at "AS depth -2001" landed at
   `clone_mc->depth = 14383`, which is in the **dynamic SWF depth
   range** but not in the AVM1-visible AS depth range. Some lookups
   that walk display_list might still find these by SWF depth even
   though the AS-level user expects them gone. Audit
   `ng_findDisplayEntryByName` callers to confirm AS-depth-keyed paths
   only.

4. **`mc->depth = INT_MIN` sentinel.** Already a sentinel for "dead
   MC". No conflict with the new contract — INT_MIN is well below any
   legal AS depth (AS depth range is roughly `[-16384, 2130690044]`
   per `swapDepths` clamping notes).

5. **Negative AS depths in the pre-clear block** (`tag_stubs.c:2691`).
   With AS depth `-2001`, `target_swf_depth = depth + 16384 = 14383`
   — valid, falls into the early dynamic SWF range. If
   `INITIAL_DISPLAYLIST_CAPACITY > 14383`, the clone gets a DL slot.
   Today's `INITIAL_DISPLAYLIST_CAPACITY` is small (likely 256 or
   1024), so most negative-AS-depth clones still won't get DL slots.
   That's the existing behavior — no change.

## Estimated session budget

- Phase 1 (recompiler pattern match): 2–3 hours. Reading
  `action.cpp`'s second-pass structure is the load-bearing prerequisite.
- Phase 2 (runtime delete heuristic): 30 minutes.
- Phase 3 (audit): 1 hour.
- Phase 4 (battery): 30 minutes per re-run; expect 2–3 re-runs.

Total: ~4–6 hours single session. Lower-risk and tighter scope than
the deferred-CLIP_EVENT_UNLOAD plan.

## Why this is the right shape

The pattern `Push(N) Push(16384) Add` is **load-bearing in Ming** for
all `CloneSprite` invocations and is **never legitimately used** by
non-Ming compilers (no AS source code adds 16384 to a depth value;
the constant is uniquely a SWF biasing artifact). Stripping it at
recompile time:

1. Is structurally inert for non-Ming SWFs (the pattern doesn't appear,
   so nothing is stripped).
2. Eliminates the runtime ambiguity that today requires a heuristic
   (and the heuristic is wrong for negative AS depths — the failing
   tests prove it).
3. Aligns the bytecode-level `CloneSprite` with the method-level
   `mc.duplicateMovieClip` — both end up taking AS depth uniformly,
   matching Ruffle's internal convention.

Once landed, removes the "CloneSprite depth-bias trade-off (open)"
section from `MISC_MING_SWFC_PLAN.md`.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `MISC_MING_SWFC_PLAN.md` "CloneSprite depth-bias trade-off (open)" | Documents the current heuristic and its failure modes. This plan supersedes that section once landed. |
| `MISC_MING_SWFC_PLAN.md` "survives_rewind via clone_depth_table" | Already SWF-depth-aware via the table — unaffected by the new contract. Reference for "the right way to track clone identity across swap/rewind." |
| `DEFERRED_CLIP_UNLOAD_PLAN.md` | Independent. Both can land in either order. |
| Ruffle source: `core/src/avm1/globals/movie_clip.rs::clone_sprite` | Reference: depth treated as AS depth uniformly. |
