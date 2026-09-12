# w2-hitarea: `hitarea_sweep` — five mechanisms, all-or-nothing (G4 from `w1-avm1-display-report.md`)

Read `BRIEFS_COMMON.md` (wave-2 section included), then `w1-avm1-display-report.md` item G4 and its
refutation section, then s18's `session18-fanout-reports/w2-avm1-hitarea-report.md` (the first arc,
which landed +3). Worktree agent: nothing commits, you deliver a patch. Branch from CURRENT master.

## Scope (+1 effective, all-or-nothing)
`avm1/hitarea_sweep` 3/33 → pass needs **exactly five** mechanisms, per the diagnosis:
1. the owner `_visible` gate;
2. mask-as-hitArea skip (MovieClip yes, TextField no);
3. `_droptarget` as a stored snapshot, updated in the drag pick;
4. a shape-accurate droptarget pick (only the `guide` line-art clip actually needs it);
5. MovieClip accessor `this` binding.

All five or the test does not flip, so sequence them and report which ones you got if you run out.

## Corrections to the older framing — do not rebuild on it
s18 named the remaining work "shape-based picking plus a single topmost pick". The topmost half is
**refuted**: across 54 verified pointer stops, ZERO have two button-mode clips, only one line is
shape-vs-AABB, and two of the four wrong lines are not picking at all.

`avm1/hitarea_remove_owner_drag` is **HOLD, not yours**: it needs the single topmost pick as well as
mechanism 3, and topmost is the largest blast radius on the board (it rewrites roll events for every
overlapping-button title and has to reconcile `tag.c`'s second hover machine). If your work makes it
flip for free, say so; do not implement topmost to chase it.

## Required checks
- Headline both ways: `avm1/hitarea_sweep`.
- The whole hitArea/picking family, which s18 just moved: `avm1/hitarea*`,
  `avm1/movieclip_hittest_shapeflag`, `from_shumway/avm1/hitarea`, plus the mouse/button families
  (`avm1/*mouse*`, `avm1/*button*`, `avm1/*drag*`).
- **A sibling has already landed an AVM1 mouse-dispatch widening on master** (prototype handlers now
  fire for every clip, and the global dispatchers no longer skip clips with NULL `dynamic_props`).
  Branch fresh so you have it, and re-baseline your before-leg against current master rather than
  the wave-0 inventory.
- The `regression` suite.

Siblings in `action.c`: **w2-avm1-sort** (sort comparator, MovieClip load tail) and **w2-setprops**
(twips quantizer, `actionSetProperty`). Name the functions you touch in your final message.
