# w2-setprops: `set_property_values/swf5+6+7` — S32-twips saturation, not the "float blocker" (G4)

Read `BRIEFS_COMMON.md` (wave-2 section included), then `w1-avm1-builtins-report.md` item G4, then
`ruffle-tests/tests/swfs/avm1/_investigation/blocked/SET_PROPERTY_VALUES_PLAN.md` and memory
`set-property-values-float-blocker`. Worktree agent: nothing commits, you deliver a patch.

## Why this is worth a slot
This family has been parked as unfixable. The wave-1 agent refuted **both** reasons:
1. the inventory's ACCEPTED flag on swf6/swf7 is a **substring false positive** — no disposition
   exists for any variant, and all three have identical diff index sets;
2. the "float blocker" is wrong: `-107374182.4` needs an **S32-twips saturation in the read
   quantizer** (`round(x * 20) / 20` at 4 sites), not `double` storage.

Verify both refutations yourself before writing code — if either is wrong, that is a first-class
finding and you should stop and report it rather than implement around it.

## Scope (+3 effective: `swf5`, `swf6`, `swf7` → pass)
The quantizer saturation is the flip. The remaining ~111 lines are the documented coercion quirk map
in `actionSetProperty` (SetProperty opcode only — a narrower blast radius than the plan claims);
take that only if the saturation lands cleanly and the sweep below is green.

`swf4` (349/1571) is KF and out of scope.

## Required checks
- Headlines both ways: `avm1/set_property_values/swf5`, `/swf6`, `/swf7` (and confirm `/swf4` does
  not move).
- A twips quantizer sits under every coordinate read in AVM1. This is the highest-blast-radius
  change in this session's wave 2, so sweep widely: `avm1/*property*`, `avm1/*_x*`/`_y`/`_width`/
  `_height`/`_rotation`/`_scale*` families, `avm1/display_object_properties`, the gnash
  `misc-ming.all` geometry tests, `from_shumway/avm1/*`, and the whole `regression` suite.
- Run the **render canary** as well: a coordinate-quantizer change can move pixels even when traces
  are unchanged. Report every DIFFERS row with channel stats and a verdict.
- If the flip does not materialize, deliver the evidence and a HOLD naming the completion
  mechanism. A refutation here is worth as much as the flip — this doc has misled two sessions.

## Housekeeping the coordinator needs from you
If the three tests flip, the disposition docs and `ignored_tests.txt` may carry stale entries for
this family. **List** what should change (file, line, entry) in your report; do not edit
disposition docs yourself.

Siblings: **w2-avm1-sort** and **w2-avm1-events** both edit `actionmodern/action.c` (sort comparator
/ `setVariableOnLocalScope` / mouse dispatch). Name the functions you touch in your final message.
