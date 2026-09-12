# w2-avm1-events: prototype mouse handlers, mouse-wheel/onScroller, event-handler nextFrame, NULL scope context

Read `BRIEFS_COMMON.md` (wave-2 section included), then `w1-avm1-display-report.md` items G1, G2,
G3 and its final refutation section. That report is your diagnosis of record; re-verify its claims.
Worktree agent: nothing commits, you deliver a patch.

## Scope (+2 effective priced, plus two items whose flip is unknown)
**G1 `from_gnash/misc-ming.all/PrototypeEventListeners` 1/32 → `ruffle_matched` (+1, ~6 lines,
`action.c`).** `mc_call_as2_handler_ng` has no `MovieClip.prototype` fall-back, so
prototype-installed mouse handlers fire for NO clip. It is not an early abort — the run completes.

**G2 `avm1/edittext_onscroller` 0/14 → `ruffle_matched` (+1).** AVM1 parses `EV_MOUSE_WHEEL` and
then drops it (no case at all, while AVM2 has the whole rule), and `onScroller` is never
dispatched. No clamping is involved, so this does not touch our weak line model.

**G3 `from_gnash/misc-ming.all/masks_test` (cheap, flip unknown — do it, but price it honestly).**
It stops at 28/175 because `nextFrame()` from a Key-listener callback on a stopped root is silently
dropped: `actionNextFrame`'s event-handler arm keys off `g_inside_event_handler`, which broadcasters
never set. Our existing 28 lines are all correct, so this is not a mask bug. Fixing the broadcaster
path may expose further diffs — report where it actually lands, and do not claim a flip you did not
see.

**G4 the NULL-context defect (separate patch file, please).** `setVariableOnLocalScope` passes a
NULL `g_scope_app_context` from a constructor that runs before the first function call, so **a local
variable is silently dropped**. The report has a gdb backtrace. It reportedly touches 3
`action_order` rows, all of which the same report marks NO-GO for other reasons, so treat the flip
count as 0 and the defect as the deliverable. Deliver it as `w2-avm1-events-2-scopectx.patch` so it
can land as its own commit, and give it a `regression/` fixture if no corpus test covers it.

## Required checks
- Headlines both ways: `from_gnash/misc-ming.all/PrototypeEventListeners`,
  `avm1/edittext_onscroller`, `from_gnash/misc-ming.all/masks_test`.
- G1 changes AVM1 mouse-handler dispatch for every clip, so sweep the mouse/button families:
  `avm1/*mouse*`, `avm1/*button*`, `avm1/hitarea*`, the gnash `misc-ming.all` button tests, and
  `from_shumway/avm1/*`. This is the highest-blast-radius item in your patch.
- G2: the EditText/scroll family (`avm1/*scroll*`, `avm1/edittext*`, `text/*`).
- G4: constructor/local-variable behaviour is core AVM1 — run a broad-but-shallow AVM1 sample
  (the `regression` suite in full, plus the gnash `actionscript.all` version families your change
  could touch).
- Always the `regression` suite.

**Out of scope, owned elsewhere:** `hitarea_sweep`/`hitarea_remove_owner_drag` (a queued slice of
its own), `missing_frame_scripts`, `links_in_scrolled_text`.

Siblings and their files: **w2-bitmapdata** also edits `actionmodern/action.c` (AVM1 copyPixels
blend paths) — `action.c` is ~50K lines so textual overlap is unlikely, but name the functions you
touched in your final message. **w2-loaders** edits `swf_core.c` + `avm2_display.c`;
**w2-avm2-json** and **w2-avm2-smalls** are AVM2-side.
