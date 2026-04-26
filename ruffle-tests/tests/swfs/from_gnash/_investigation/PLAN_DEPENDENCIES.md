# Plan Dependencies

Index of which plans block, foundation, or follow which others. Plans that
stand alone (no upstream/downstream relationships beyond their own test set)
aren't listed — they live in their bucket and can be worked independently.

**Last updated:** 2026-04-26

## How to read this

- **Bucket:** `incomplete/` (active), `blocked/` (waiting on upstream),
  `complete/` (landed).
- **Foundation of:** plans that depend on this one's primitives or fixes.
- **Blocked by:** what must land before this plan can move to `incomplete/`
  or finish.
- **Predecessor of / Successor of:** sequencing relationships where one plan
  is the next chapter of another (split for scope, same problem area).

## Active chain: goto-catchup hygiene → FIFO unification

This is the largest active chain — the one we're working through now.

```
GOTO_CATCHUP_HYGIENE_PLAN (blocked/)
   │ Phases 1-5 landed; Phase 6 split out as its own plan.
   ↓
   ├──► GOTO_FIFO_UNIFICATION_PLAN (blocked/)
   │       │ status: blocked (re-blocked 2026-04-26b)
   │       │ blocked_by: scope. Path A resolved (drain-suppress primitive),
   │       │             but Phase 4 (recompiler gate simplification) is now
   │       │             known to be REQUIRED atomically with Phases 1+2+3,
   │       │             not "cleanup later" as the original plan claimed.
   │       │             See plan's "Updated finding 2026-04-26b" section
   │       │             for sync-fire cascade trace proving Phase 1 alone
   │       │             (and 1+2+3) regress consecutive_goto_frame_test
   │       │             from 4/12 to <4/12.
   │       │ uses: DRAIN_SUPPRESS_PRIMITIVE accessors (Phase 2)
   │       │ target test: consecutive_goto_frame_test (4/12 baseline)
   │       │ guardrail risk: loop_test*, goto_rewind*, unload-family,
   │       │                 register_and_init_order, execution_order2/3
   │       └──► (none yet — Path B is the next code change in this chain)
   │
   └──► TRANSFORMED_BY_SCRIPT_WRAP_BACK_PLAN (incomplete/)
           │ status: pending
           │ Phase 7 split off the predecessor; independent code paths from
           │ FIFO unification but shares catch-up machinery — spot-check both.
           target test: place_and_remove_object_insane_test (17/22 baseline)

DRAIN_SUPPRESS_PRIMITIVE_PLAN (complete/, commit d1cd1d1f)
   │ Adds actionDrainSuppressEnter/Leave/Suppressed in action_queue.h/c.
   │ Behaviorally inert until a caller sets the depth.
   ↓
   └──► foundation of GOTO_FIFO_UNIFICATION Phase 2.
```

### What unblocks what

| If you land… | …it unblocks… |
|--------------|---------------|
| GOTO_FIFO_UNIFICATION Phases 1+2+3 atomic | the trailing diff on `consecutive_goto_frame_test`, plus likely shifts on the `loop_test*` cluster (predecessor plan's recently-fixed battery) |
| TRANSFORMED_BY_SCRIPT_WRAP_BACK | `place_and_remove_object_insane_test` (the other Phase 6→Phase 7 split) |
| Both above | retiring `GOTO_CATCHUP_HYGIENE_PLAN` from `blocked/` to `complete/` |

## Other dependency relationships

### DEFERRED_CLIP_UNLOAD_PLAN (incomplete/, in_progress)

- **Sensitive to:** GOTO_FIFO_UNIFICATION drain-timing changes. The
  `actionQueueClipActionUnloadDeferred` helper added for `loop_test8`
  rides `AQ_KIND_SCRIPT` and shifts behavior under the unified FIFO.
- **Cross-check after:** any GOTO_FIFO_UNIFICATION phase lands.
- **Status:** Phases 1-5 completed; partial — 3 of 10 target tests pass.
  Remaining diffs are inter-tag UNLOAD vs DoAction ordering that the
  recompiler emits.

### CLONESPRITE_DEPTH_BIAS_PLAN (blocked/)

- **Blocked by:** invasive runtime work to separate display_list slot
  allocation from depth-keyed lookup. Phase 1 partial (single-value
  Push(16384) handled); Phase 2 (drop runtime heuristic + uniform AS depth)
  blocked because stripping the bias for *packed* Pushes shifts AS depths
  into 1..16383 and collides with reserved static-MC slots.
- **Foundation of:** none — terminal in its own subtree.

### MISC_SWFMILL_PLAN (blocked/)

- **Blocked by:** three independent architectural limitations (cross-block
  backward jumps, post-ShowFrame execution + InitAction ordering, tag
  interleaving). Each remaining test needs its own architectural change.
- **Foundation of:** none.

### ROOT_ONLOAD_PLAN (blocked/)

- **Blocked by:** Ruffle's priority-based ActionQueue. Fixing
  `trace-as2/root_onload` requires sprite Phase 2 init firing before parent
  script, which regresses `clip_events`, `execution_order1/4`,
  `register_and_init_order` under the current model.
- **Possible unblock route:** GOTO_FIFO_UNIFICATION's unified FIFO might
  open this — worth re-evaluating once Path B lands, but not a guaranteed
  fix (the priority levels are a separate dimension from FIFO ordering).

### STRING_REGEX_PLAN (blocked/)

- **Status:** DEFERRED, not blocked-on-upstream. No test SWF actually uses
  regex; MTASC can't compile regex literals. Archived rather than deleted.
- **Foundation of:** none.

### WITH_AUTOBOXING_PLAN (blocked/)

- **Blocked by:** Reassessed 2026-04-21 — primitive auto-boxing already
  works. Remaining `with-v5/6/7/8` diffs are driven by unrelated features.
  Plan parked until the unrelated features are identified.
- **Foundation of:** none.

### REGISTERCLASS_LIFECYCLE_PLAN (incomplete/)

- **Cross-check after:** GOTO_FIFO_UNIFICATION lands. Register-class
  constructors fire from the deferred-goto loop's Phase 0; under the
  unified FIFO that ordering may shift.
- **Foundation of:** none.

### IMPORT_CHARACTER_PLAN (incomplete/)

- **Standalone.** No upstream dependencies; addresses a specific tag
  (ImportAssets / ImportAssets2) not implemented yet.

## Maintenance

When a plan moves buckets (incomplete ↔ blocked ↔ complete):

1. Update its own `<!-- PLAN_META -->` `status:` line.
2. Update this file's chain diagram and table if the move changes which
   plans are blocked/unblocked.
3. Update cross-link paths in any plan's `## Related docs` table that
   referenced the old bucket (e.g. `blocked/X.md` → `complete/X.md`).
4. If the move resolves a blocker for another plan, add a
   `prior_blocker_resolved:` entry under that plan's PLAN_META so future
   sessions see the unblock event without re-reading commit history.

This file is hand-maintained and will drift if these steps are skipped.
A periodic audit (grep for `blocker:` / `blocked_by:` lines, cross-check
against bucket location) catches drift.
