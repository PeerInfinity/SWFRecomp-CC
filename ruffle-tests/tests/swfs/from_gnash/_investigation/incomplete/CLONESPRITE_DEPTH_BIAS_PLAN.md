# CloneSprite Depth-Bias Unification Plan

<!-- TESTS: displaylist_depths/displaylist_depths_test, displaylist_depths/displaylist_depths_test2, displaylist_depths/displaylist_depths_test3, displaylist_depths/displaylist_depths_test8, displaylist_depths/displaylist_depths_test9, DepthLimitsTest, duplicate_movie_clip_test, duplicate_movie_clip_test2 -->

<!-- PLAN_META
id: CLONESPRITE_DEPTH_BIAS
status: pending
phases:
  - id: 1
    name: "Recompiler pattern-match: strip Push(16384) Add prefix from CloneSprite"
    status: pending
  - id: 2
    name: "Runtime: drop the (depth >= 16384) heuristic; treat depth uniformly as AS depth"
    status: pending
  - id: 3
    name: "Audit identity checks for residual depth==-16384 / depth>=16384 conflations"
    status: pending
  - id: 4
    name: "Verify on the displaylist_depths cluster + textsnapshot guardrail"
    status: pending
dependencies: []
blockers:
  - reason: "None — the recompiler is a 3-opcode-lookahead pattern match; runtime change is a 2-line edit. Risk lives in the regression battery (confirming no other site reads clone_mc->depth as SWF-biased)."
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
