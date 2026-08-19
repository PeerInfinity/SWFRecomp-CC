# w2-crossvm-legE — cross-VM hit test + AVM1 timers under AVM2 (session 17, wave 2)

**Agent:** `w2-crossvm-legE` (wave-2).
**Worktree:** `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ac72e1691286053ab`
**Base:** `88ebde665`; baseline statuses from run `31877239992` @ `aeebf9ede`.
**Mode:** `--mode=graphics`, `-P 2`, `SWFRECOMP_COMPILE_TIMEOUT=2400`.
**Patch:** `SWFRecompDocs/plans/session17-fanout-reports/w2-crossvm-legE.patch`

---

## 0. New files: NONE

The patch touches two existing files only:

| file | what |
|---|---|
| `SWFModernRuntime/src/actionmodern/action.c` | `actionTickAvm1ChildrenUnderAvm2` gains a frame budget + three end-of-frame AVM1 phases; new `actionAvm1ChildMousePick`; MCL drain sets `byte_size` on a completed SWF load |
| `SWFModernRuntime/src/avm2/avm2_display.c` | pick walk descends into the `AVM1Movie` wrapper; AVM1-hit sentinel + two dispatch guards; `avm1_child_tick` computes the frame budget |

No new headers, no build-list changes, no recompiler changes (runtime-only —
the main tree's `SWFRecomp/build` was copied and verified).

---

## 1. Verdicts

| # | requirement (brief) | verdict | evidence |
|---|---|---|---|
| 1 | AVM2 pick walk descends into an AVM1 child, hit attributed to the wrapping `Loader` | **GO — landed** | `mouse_pick` now calls the AVM1 walk for the `AVM1Movie` child (Ruffle `loader_display.rs::mouse_pick_avm2`); `mouse_pick_loader_avm1` 38 → 27 differing lines |
| 2 | a hit on AVM1 content must NOT also produce an AVM2 `click` on the Stage | **GO — landed** | AVM1-hit sentinel target; `dispatch_mouse` / `update_focus_on_press` drop it (Ruffle: `event_dispatch_to_avm2` needs an `object2` an AVM1 DO never has) |
| 3 | AVM1 timers must run under AVM2 (frame budget) | **GO — landed** | budget = `1000 / (avm2_generated_frame_rate/256)`, the same expression `run_due_timers` uses for the AVM2 Timer clock; measured firing (`dt = 41.67 ms` at 24 fps) |
| — | **`avm2/mouse_pick_avm1_root`** | **FLIP: output_mismatch → PASS** | measured |
| — | `avm2/mouse_pick_loader_avm1` | **NO-GO (improved, not flipped)** | 38 → 27 differing lines; the remainder is leg F (focus/`Selection`) + AVM1 button dispatch |
| — | `mixed_avm/avm1_loads_avm2` | not attempted | still the harness/build arc (wave-1 leg G) — nothing adjacent |

**Total: +1 trace flip.**

---

## 2. Premise attack — what the brief got right and what it missed

The brief (from `w2-avm1-child-report.md` §5 E) named two blockers: the pick-walk
descent and AVM1 timers. Both are real. **They were not sufficient**, and the
timer half was not the binding constraint it was billed as:

1. **The MovieClipLoader drain was missing too.** `actionTickAvm1ChildrenUnderAvm2`
   drained direct loads, level advances, unloads and (s16) LocalConnection, but
   never `actionFirePendingLoadInits`. `mouse_pick_avm1_root`'s AVM1 movie does
   `mcl.loadClip("avm1_child.swf", clip)`, so with timers alone the child SWF
   never loads at all.
2. **`getBytesTotal()` on an MCL target was 0 — a plain AVM1 bug, not a dual-VM
   one.** With timers AND the MCL drain in place the test still failed:
   instrumented runs showed the `setInterval` callback firing 10× per tick
   (`AVM1TIMERFIRE`, dt = 41.67 ms / delay 4 ms) and the loaded content present
   (`AVM1PICK cand 'target' inside=1`) — but `clip.byte_size == 0`, so the
   fixture's `getBytesLoaded() == getBytesTotal() && getBytesTotal() > 4` poll
   never completed and `clip.onRelease` was never assigned.
   `actionFirePendingLoadInits`' pre-phase sets `byte_size` for **image** and
   **non-SWF** loads only; the `loadMovie` drain
   (`actionFirePendingDirectLoads`) has always set it for SWFs. One line closes
   the gap. This is an AVM1-wide fix that happens to be on the critical path of
   a dual-VM row — and it is the actual reason the row was "session-sized".
3. **Loader attribution already half-worked.** The brief implies the AVM2 walk
   sees nothing of an AVM1 child. In fact `mouse_pick_loader_avm1`'s baseline
   already prints `Clicked on: [object Loader] (instance2)` — the `AVM1Movie`
   wrapper's own bounds (the loaded movie's stage rect) were answering. What was
   missing was precision (that rect also swallows clicks on AVM2 siblings) and
   the interactive case. The patch keeps the wrapper-bounds test as the fallback
   arm of the OR, so nothing that worked before stops working.

---

## 3. Mechanism, as landed

### 3.1 Frame budget for `processTimers` (requirement 3)

`avm1_child_tick` (avm2_display.c) computes

```c
double fps = (double) (int16_t) avm2_generated_frame_rate / 256.0;
if (fps <= 0) fps = 24.0;
actionTickAvm1ChildrenUnderAvm2(ctx->app, 1000.0 / fps);
```

and the tick hands that to `processTimers`. This is **the same expression
`run_due_timers` uses** for the AVM2 `flash.utils.Timer` clock
(`avm2_display.c` ~:3411), so the two VMs' timer clocks advance in lockstep, and
it matches the AVM1-only loops' `1000.0 / app_context->fps`
(`swf_core.c:1461`, `swf.c:1282`). It is derived from a generated constant, so
NO_GRAPHICS / OFFSCREEN_RENDER / wasm all see the identical number — the value
is computed once, in the one hook every arm calls, so there is no arm to keep in
sync by hand.

The tick's new end-of-frame block runs, in `swf_core.c`'s order, inside the
existing child-context swap: pending onLoads → **timers** → LocalConnection →
**MCL drain** (bounded, 32 iterations, like swf_core.c's) → pending onLoads.

### 3.2 The pick walk (requirements 1 + 2)

`mouse_pick`'s child loop gets one new arm, for the `AVM1Movie` wrapper the
Loader exposes (`loader_deliver` inserts it as the Loader's child 0):

```
BUTTON  -> Hit(sentinel)                    // AVM1 object is the target
CONTENT -> Hit(loader) / PropagateToParent  // Ruffle LoaderDisplay fallback
MISS    -> the wrapper's own bounds decide  // preserves today's behaviour
```

`actionAvm1ChildMousePick` (action.c) answers from the AVM1 side: it walks
`child_mc_cache` for clips whose parent chain reaches a booted AVM1 level, using
the same pixel AABBs `actionDispatchMCPress/Release` test (so a click the AVM2
side attributes to AVM1 is exactly a click the AVM1 dispatchers act on), and
reports BUTTON when Ruffle's `is_button_mode` predicate holds
(`actionMCHasButtonHandlers` = the seven BUTTON_EVENT_METHODS). Timeline content
never enters `child_mc_cache`, so the level roots' display-list bounds are
consulted before reporting a miss.

The **sentinel** is a file-static zeroed `Avm2Object` with `cls == NULL`, so
every `avm2_display_ext_of()` on it returns NULL and the roll/state/text/drag
helpers no-op by construction. Only two seams needed an explicit test:
`dispatch_mouse` (returns 0 — no AVM2 MouseEvent is built, and it does **not**
fall back to an ancestor or the Stage: Ruffle's `event_dispatch_to_avm2` simply
has no `object2` to dispatch on) and `update_focus_on_press` (treats it as "no
object": `is_focusable_by_mouse` is `is_action_script_3() && tab_enabled`,
`interactive.rs:614`, so AVM1 content is never mouse-focusable — the exception,
a selectable AVM1 `EditText`, belongs to leg F).

`pk_combine` is untouched and therefore still applies `mouseChildren` /
`mouseEnabled` above the AVM1 subtree — which is what makes
`mouse_pick_loader_avm1`'s `avm1Container.mouseChildren = false` rows retarget to
the Sprite.

### 3.3 `byte_size` on a completed MCL SWF load

One line in `actionFirePendingLoadInits`' pre-phase, mirroring
`actionFirePendingDirectLoads`. Blast radius: MovieClipLoader SWF loads only,
and only at completion time (never before), so a progress poll that reads 0
mid-load still reads 0.

---

## 4. Ledger

Baseline column = `results_graphics.json` @ `aeebf9ede` (run `31877239992`),
confirmed locally by an A/B on this worktree (patch reverted with
`git apply -R`, never `git stash`). "after" = the shipping patch, measured
with `--mode=graphics --verbose`, `-P 2`.

| test | baseline | after | note |
|---|---|---|---|
| **`avm2/mouse_pick_avm1_root`** | output_mismatch (1 line) | **PASS** | **the flip** |
| `avm2/mouse_pick_loader_avm1` | output_mismatch (38 differing) | output_mismatch (**27** differing) | improved, no flip — leg F + AVM1 buttons |
| `mixed_avm/avm2_loads_avm1` | pass | pass | |
| `mixed_avm/avm2_loads_avm1_v9` | pass | pass | |
| `mixed_avm/avm2_loads_avm1_v10` | pass | pass | |
| `mixed_avm/avm2_loads_avm1_doabc` | pass | pass | |
| `mixed_avm/avm2_loads_avm1_loads_into_root` | pass | pass | |
| `mixed_avm/avm1_loads_avm2_doaction` | pass | pass | |
| `avm2/avm1movie_addcallback_call` | pass | pass | |
| `from_shumway/avm1movie` | ruffle_matched | **ruffle_matched** | the s16 regression canary — held |
| `avm2/mouse_pick_button_mode` | pass | pass | |
| `avm2/mouse_pick_masking` | pass | pass | |
| `avm2/mouse_pick_text` | pass | pass | |
| `avm2/mouse_children` | pass | pass | |
| `avm2/mouse_click_events` | pass | pass | |
| `avm2/loader_noninteractive_try_click_root` | pass | pass | |
| `avm2/focus_events_mouse_basic` | pass | pass | |
| `avm1/set_interval` | pass | pass | AVM1 timers |
| `avm1/timer_run_actions` | pass | pass | AVM1 timers |
| `from_shumway/avm1/setinterval` | pass | pass | AVM1 timers |
| `from_shumway/avm1/settimeout` | pass | pass | AVM1 timers |
| `regression/timer_cross_swf_version` | pass | pass | |
| `regression/timer_type1_args` | pass | pass | |
| `regression/onload_type1_args` | pass | pass | |
| `avm1/get_bytes_total` | pass | pass | **`byte_size` change** |
| `avm1/loadmovie` | pass | pass | **`byte_size` change** |
| `avm1/loadmovie_var_persistence` | pass | pass | **`byte_size` change** |
| `avm1/load_cancel_via_removemovieclip` | pass | pass | **`byte_size` change** |
| `from_shumway/avm1/moviecliploader` | pass | pass | **`byte_size` change** — the MCL oracle |

**29 rows graded, 1 flip, zero regressions.** (Differing-line counts for
`mouse_pick_loader_avm1` are `--diff`'s displayed `-` lines, counted the same
way before and after; the display elides a long identical run, so treat 38 → 27
as a like-for-like delta, not an absolute.)

## 5. Canaries and blast radius

* **Canary blind spot:** nothing in this patch has a pixel effect, so the render
  canary does not cover it. The covering graded rows are the 29 above; the
  families are (a) the six dual-VM `mixed_avm`/`avm2` rows plus the
  `ruffle_matched` `from_shumway/avm1movie` regression canary, (b) the AVM2
  mouse-pick family, (c) AVM1 timers, (d) MovieClipLoader / loadMovie (for the
  `byte_size` line).
* **Gating.** Every new path is behind `g_avm1_child_levels != 0` (AVM2 side) or
  `g_avm1_under_avm2_ready && g_avm1u2_count != 0` (AVM1 side), so pure-AVM2
  content pays one integer compare per mouse event and per tick. The AVM1 code
  is inside the existing `#ifdef SWF_AVM2` block, so no AVM1-only binary
  contains it. The one exception is the `byte_size` line, which is live for
  every MovieClipLoader SWF load in every build — hence the five MCL/loadMovie
  canaries.
* **Post-merge check (coordinator request).** Master moved to `92096de8f`
  (w2-avm2-smalls: Ruffle +x ray-cast tie rules in the AVM2 shape hit test).
  The worktree was merged to `92096de8f` and the patch re-applied: `git apply
  --check` is clean (no textual overlap — that change is inside
  `point_in_self`/`hit_test_shape`, this one is in the pick walk's child loop
  and the dispatch seams). The mouse-pick family was re-run on the merged tree;
  results in §5.1.

### 5.1 Post-merge re-run (tree = `92096de8f` + this patch)

All ten re-graded on the merged tree; **identical to the pre-merge results**, so
the +x ray-cast tie-rule change and this patch do not interact:

| test | merged-tree result |
|---|---|
| `avm2/mouse_pick_avm1_root` | **PASS** |
| `avm2/mouse_pick_loader_avm1` | output_mismatch, 27 differing (unchanged) |
| `avm2/mouse_pick_button_mode` | pass |
| `avm2/mouse_pick_masking` | pass |
| `avm2/mouse_pick_text` | pass |
| `avm2/mouse_children` | pass |
| `avm2/mouse_click_events` | pass |
| `avm2/loader_noninteractive_try_click_root` | pass |
| `mixed_avm/avm2_loads_avm1` | pass |
| `from_shumway/avm1movie` | ruffle_matched |

The delivered `w2-crossvm-legE.patch` is a diff against **`92096de8f`** (the
worktree was merged before it was regenerated).

## 6. What is left on this family, priced

| row | remaining | owner |
|---|---|---|
| `avm2/mouse_pick_loader_avm1` (27) | ~4 lines `avm1 button clicked`; ~4 lines `input_txt.onSetFocus/onKillFocus`; the rest is downstream misalignment plus AVM2-sibling clicks (`rect_mc`, Stage) still absorbed by the `AVM1Movie` wrapper's stage-rect fallback | leg F + two smaller legs below |
| `avm2/selection_onsetfocus_mixed_avm` (5) | all five lines | leg F |
| `avm2/focus_events_mixed_avm_edittext` (48) | all | leg F |
| `mixed_avm/avm1_loads_avm2` (4) | harness/build arc | wave-1 leg G, unchanged |
| `avm2/avm1_root` (46) | ceiling is `ruffle_matched` | s16 docs patch, leave alone |

### Leg F (focus / Tab / `Selection`) — now cheaper, still its own slot

s16 priced leg F as "no cheap slice: three requirements together". Two of the
three are now *structurally* easier because this patch supplies the missing
plumbing:

1. **The cross-VM hit test exists.** `actionAvm1ChildMousePick` already
   distinguishes AVM1 text fields from other clips (it skips them for the
   button test, exactly as `actionDispatchMCPress` does). Extending it with the
   Ruffle rule (`edit_text.rs::mouse_pick_avm1`: a **selectable** field, or a
   link under the point, is a HIT) is ~6 lines and gives the focus code its
   "which AVM1 field was clicked" input.
2. **The AVM1-execution seam exists.** `avm1UnderAvm2EnterChild/LeaveChild` +
   `actionMouseAvm1ChildrenUnderAvm2` are the pattern for running AVM1 handlers
   from an AVM2 call site; an `actionFocusAvm1ChildrenUnderAvm2(mc, kind)` that
   broadcasts `Selection.onSetFocus(old, new)` and calls the field's
   `onSetFocus`/`onKillFocus` is the same shape.
3. **Still missing, and still the hard part:** AVM1 child interactive objects in
   the AVM2 **tab order** (`obj_tab_enabled` / the tab-order walk in
   `avm2_display.c`), and the `null`-for-AVM2-object argument convention on the
   AVM1 `Selection` broadcast.

**Price:** `avm2/selection_onsetfocus_mixed_avm` (+1) is reachable with (1) +
(2) + the null-argument convention alone — its three `null null` lines are
broadcasts on focus changes that never involve an AVM1 object, and the last two
need the AVM1 field to *receive* focus from a click, which (1) now provides.
The tab-order half is only needed by `focus_events_mixed_avm_edittext` (48).
**Completion mechanism:** implement (1) + the `Selection` broadcast + AVM1
`onSetFocus`/`onKillFocus` dispatch and grade
`avm2/selection_onsetfocus_mixed_avm`; if it flips, the tab-order walk is a
second, independent slot for the 48-line row.

### Two smaller legs uncovered here (not attempted)

* **AVM1 buttons under AVM2** (~4 lines of `mouse_pick_loader_avm1`).
  `ng_update_button_states` is called only from `input_events.c`, the AVM1-only
  input pump, so a `DefineButton` inside an AVM1 child never changes state or
  fires under an AVM2 parent. The bridge would call it inside the child swap
  (with the child's display list swapped in, as `avm1UnderAvm2RunFrame` does).
  Priced: 0 flips alone, worth ~4 lines on a row leg F must finish anyway.
* **Strict AVM1 content bounds.** Dropping the `point_in_self(wrapper)` fallback
  arm of the pick (making the AVM1-side walk authoritative) would stop the
  wrapper's stage rect from swallowing clicks on AVM2 siblings, worth several
  more `mouse_pick_loader_avm1` lines — but it can only be graded honestly once
  leg F removes the focus noise from that row, so it is deliberately left as
  the safe OR here.
