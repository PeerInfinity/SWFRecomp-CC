# w2-avm1-sort: sort-comparator scope, MovieClip loadVariables tail, addProperty on functions (G1-G3)

Read `BRIEFS_COMMON.md` (wave-2 section included), then `w1-avm1-builtins-report.md` items G1, G2,
G3. That report is your diagnosis of record; re-verify its claims. Worktree agent: nothing commits,
you deliver patches. **Deliver three patch files** (`w2-avm1-sort-1-addproperty.patch`,
`-2-comparator.patch`, `-3-movieclip-tail.patch`) so they can land as separate commits.

## Scope (+6 effective)
**G1 `avm1/new_class_prototype_getter` → pass (+1, ~3 lines).** `addProperty` on a function receiver
passes `func->own_props` to the builtin, which is NULL on a fresh function, so it returns false and
installs nothing. Fix: lazily allocate `own_props` at `action.c:69388-69498`; there is precedent at
`action.c:68729-68736` — follow it rather than inventing a second allocation idiom.

**G2 `from_gnash/actionscript.all/array-v6/-v7/-v8` → `ruffle_matched` (+3).** `ruffle_matched` is an
index-SUBSET test, so the bill is 4 / 32 / 32 ours-only lines, not 21/50/50. 26 of the 32 on v7/v8
are ONE defect: `_invoke_sort_comparator` (`action.c:64420`) gives the type-2 arm
`INV_CAPTURED_SCOPE` only — no local frame, no `this` bind — so a Ming function2 comparator's
`setVariableByName("a"/"b")` writes into the root timeline. (v6 uses DefineFunction, v7/v8
DefineFunction2.) The helper's own comment names this bug. The remaining 4 lines are 3 undiagnosed
mechanisms: leave them, and say so.

**G3 `from_gnash/actionscript.all/MovieClip-v6/-v7` → `ruffle_matched` (+2).** Only 14 ours-only
lines each, 11 of them one mechanism: our run ends before the `loadVariables`/`onData` (`vars.txt`)
plus `onUnload` tail. **v8 is out of scope** (41 lines, SWF8 filters/transform).

## Required checks
- Headlines both ways, and **check the subset rule explicitly** on every `ruffle_matched` target:
  a `pass → ruffle_matched` move elsewhere is a regression (rule 3), and these tests are KF.
- G2 touches sort for every AVM1 array: sweep `avm1/array*`, `avm1/*sort*`, the gnash `array-v5`
  (IGN, but must not move), and `from_shumway/avm1/*`. Calling convention changes are the classic
  source of silent breakage — run a broad-but-shallow AVM1 sample too.
- G3 touches load/unload tails: `avm1/loadvariables*`, `avm1/load_vars`, `avm1/*unload*`, and the
  MovieClip-v8 row (must not regress).
- The `regression` suite every time.

Siblings and their files: **w2-avm1-events** also edits `actionmodern/action.c` — specifically
`mc_call_as2_handler_ng`, the EV_MOUSE_WHEEL/onScroller path, `actionNextFrame`'s event arm and
`setVariableOnLocalScope`. **Your G2 touches `setVariableByName` behaviour through the comparator
frame, which is adjacent to its `setVariableOnLocalScope` fix — if you find yourself editing the
same function, stop and say so in your final message instead of resolving it yourself.**
**w2-bitmapdata** edits `action.c` bitmap/blend paths.
