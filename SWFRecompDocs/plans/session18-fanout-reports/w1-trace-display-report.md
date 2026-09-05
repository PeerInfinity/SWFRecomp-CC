# w1-trace-display — session 18 wave-1 diagnosis (AVM2 display / timeline / loader / focus)

Agent `w1-trace-display`, read-only, main tree at `8f68a5fea`. Every row below was
re-run locally at HEAD (`verify_output.py --diff --verbose`, no-graphics,
`SWFRECOMP_COMPILE_TIMEOUT=2400`, `-P 2`). Logs, saved actual outputs and the A/B
run are in
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/141dd0bc-70cb-4bc3-8c42-9434ad15df7a/scratchpad/w1-trace-display/out/`.

Two harness options nobody in the fan-out has been using are worth promoting:
`--save-actual=PATH` (full actual output — the `--diff` display truncates and is
offset by expected's *unstripped* leading blank line, which makes near-miss rows
look catastrophic) and `--expected-suffix=ruffle` (grade a `known_failure` row
against `output.ruffle.txt`, i.e. against the `ruffle_matched` ceiling directly).

---

## 1. Verdicts, priced

| # | lead | rows | verdict | flips | cost |
|---|---|---|---|---|---|
| L1 | walk-skip gate hole on `addFrameScript` during FrameScripts | `timeline/frame_script_cleanup_goto2` | **GO — PROVEN by A/B** | **+1** | ~2 lines, `avm2_display.c` |
| L2 | orphan list ignores Ruffle's `placed_by_avm2_script` retain rule | `avm2/orphan_removeobject` | **GO** | **+1** (296 lines) | ~10 lines, `avm2_display.c` |
| L3 | loaded child's frame-1 children placed AFTER its root ctor | `avm2/loader_try_click_root`, `avm2/loader_duplicate_class` | **GO** | **+1 firm, +1 likely** | ~10 lines (a reorder), `avm2_display.c` |
| L4 | `Stage.contentsScaleFactor` + Stage `local_to_global` identity | `avm2/stage_scale_factor` | **GO — refutes the ignore-list note** | **+1** | ~10 lines + un-ignore |
| L5 | real `Stage.displayState` + `FullScreenEvent.FULL_SCREEN` | `avm2/stage_display_state` | **GO** | **+1** | ~40 lines, `avm2_display.c` (+1 const) |
| L6 | one missing native frame in the dispatchEvent stack | `avm2/event_handler_exception` | **GO (ceiling = `ruffle_matched`)** | **+1 effective** | ~3 lines |
| L7 | `loadBytes` completion must land after the frame's `exitFrame` | `avm2/large_preload_from_bytes` | **GO — refutes §18.4** | **+1** | ordering, `avm2_display.c` |
| L8 | `addFrameScript` argc validation + `getStackTrace` native frames | `avm2/movieclip_addframescript_error` | **GO (medium confidence)** | **+1** | ~15 lines |
| L9 | `LoaderInfo.unload` event never dispatched | `loader_events_2`, `mixed_avm/avm2_loads_avm1_events` | **HOLD** (0 alone) | 0 / +2 with L10 | ~6 lines |
| L10 | instance-name counter is 3 short (5 call sites vs Ruffle's 12) | `simplebutton_childevents_multichild`, `loader-events` | **HOLD — corpus-wide A/B first** | +1 eff / partial | small edit, wide blast |
| L11 | `EdgeBounds`/`BoundsMode` end to end | `avm2/displayobject_getrect` | **HOLD** (confirmed, recompiler) | +1 | MED, recompiler + runtime |
| L12 | S3 (`has_end_tag`) + S4 (orphan tick stall) | `timeline/missing_frame_scripts` | **HOLD** (unchanged at HEAD) | +1 only if both | MED |
| L13 | held s16 patch | `text/links_in_scrolled_text` | **HOLD** (applies clean, still 0 flips) | 0 | line-model work |
| L14 | cross-VM focus / pick machinery | `selection_onsetfocus_mixed_avm`, `mouse_pick_loader_avm1`, `focus_events_mixed_avm_edittext` | **HOLD** (leg F, unchanged) | +1 / +0 / +0 | session-sized |
| N1 | naming dispositioned | `avm2/avm1_root` | **NO-GO** | — | — |
| N2 | embedded `DefineBinaryData` SWF never compiled | `from_shumway/as3-loader/LoaderLoadBytesTest` | **NO-GO** (confirmed at HEAD) | — | recompiler arc |

Realistic wave-2 haul from this board: **+6 to +8 trace flips**, of which L1/L2/L4
are the cheapest and L1 is already proven.

---

## 2. GO leads in detail

### L1 — `timeline/frame_script_cleanup_goto2` — **PROVEN, +1, ~2 lines**

**`AVM2_NO_WALK_SKIP=1 verify_output.py --test=frame_script_cleanup_goto2` PASSES
(34/34).** Log: `out/goto2_nowalkskip.log`. Baseline is 12/34 with 29 actual lines.

Mechanism. `avm2_display.c:7917-7929` (`addFrameScript`) mirrors Ruffle's
`register_frame_script` (`movie_clip.rs:2144-2158`): when the phase is
`PHASE_FRAME_SCRIPTS` it pushes the clip on the frame-script cleanup queue,
otherwise it sets `has_pending_script` **and calls
`avm2_display_mark_frame_work`**. The cleanup-queue branch is the one that does
NOT mark — and marking is what clears the catch-up walk gate's `walk_clean` up
the ancestor chain. `avm2_display_mark_frame_work` (`:1474`) only clears
`walk_clean` / bumps `dirty_kids`; it never touches `has_pending_script`, so
adding it to the cleanup-queue branch is semantically inert for everything except
the gate.

The fixture makes that hole visible because `Main.frame1` registers scripts on four
already-clean descendants and then `MyContainer.frame1` does `gotoAndPlay(1)` on
its own current frame — a `no_op_goto` whose `avm2_display_inner_goto_frame` walk
is the only thing that would have reached them, and it skips their (clean)
subtrees. We lose exactly the five lines `Child frame1 / GrandChild addFrameScript
/ GrandChild frame1 / LeafChild frame1 / GrandChild frame1`.

Patch scope: one `avm2_display_mark_frame_work(ctx, this_obj(act));` in the
`PHASE_FRAME_SCRIPTS` arm at `:7921`. Canary: the goto-walk-gate perf note
(`avm2-goto-catchup-walk-gate`) — Elephant Quest's `initTiles` is the reason the
gate exists, so re-run a goto-heavy AVM2 fixture (`timeline/*`, `avm2/goto_*`,
`avm2/action_order*`) plus the `regression` suite. Correctness cost is one extra
subtree walk per `addFrameScript` issued from inside a frame script.

**Do NOT ship `AVM2_NO_WALK_SKIP` as the fix** — that is the A/B instrument, not
the patch.

### L2 — `avm2/orphan_removeobject` — **GO, +1 (340/636 -> 636), ~10 lines**

Never diagnosed before. Full actual saved (`out/actual_orphan_removeobject.txt`,
641 lines vs 636 expected). Positional diff is one mechanism repeated: an orphan's
`currentFrame` keeps climbing where Flash freezes it (`myId = 9/10`: expected 2,
ours 3 then 4; `timelineChild`: expected 4, ours 5), plus five extra
`Running child framescript` lines at the tail.

Ruffle `core/src/orphan_manager.rs:65-92` — `cleanup_dead_orphans` retains an
orphan **only if `dobj.placed_by_avm2_script()`**:

> Clips removed from a RemoveObject tag only stay on the orphan list until the end
> of the frame — this lets them run a framescript (with `this.parent == null`)
> before they're removed. After that, they're removed from the orphan list, and
> will not be run in any way.

Our `orphan_cleanup` (`avm2_display.c:181-203`) implements **none** of that: it
drops re-parented entries only, and only once 64 re-parentings have accumulated
(`g_orphan_reparented < 64` early-return). The flag it needs already exists as
`ext->placed_by_avm2_script` (used at `:2416`).

Patch scope: make the exit-frame `orphan_cleanup` retain `parent == NULL &&
placed_by_avm2_script`, and drop the amortisation gate for the semantic half (keep
it for the compaction half if the profile demands). Canary: `avm2/orphan_movie*`,
`avm2/orphan_*`, the goto-walk-gate perf fixtures (the orphan list is the thing
that never shrank in Elephant Quest — this rule makes it shrink *more*, so the
perf risk is favourable), plus `regression`.

### L3 — loaded-child root ctor runs before its frame-1 children exist — **GO, +1 firm / +1 likely**

`loader_boot_child_swf` (`avm2_display.c:5904-5972`) calls
`display_run_constructor_catching` and only *then*
`run_frame_internal` + `flush_queued_places`. So a loaded root's class constructor
sees an empty timeline.

* `avm2/loader_try_click_root` (16 exp / 0 match, 26 actual). `Loadable.as`'s whole
  body is `this.mouseDisabled.mouseEnabled = false;`. We throw
  `TypeError #1009 … (accessing field: mouseEnabled) at Loadable()` **five times**,
  each of which sets `lx->errored` and drops the load, so the content never becomes
  the Loader's child and all 16 click lines report `[object Stage] (null)`.
  Fixing the order should recover the whole row.
* `avm2/loader_duplicate_class` (48 exp / 3 match). With the display offset removed,
  the *entire* content diff is: `this.childFromDomainChild = [object MovieClip]` and
  `Child name: [object MovieClip]` are emitted five lines late (after the child's
  framescript instead of before it), we emit an extra
  `TypeError #1034: cannot convert flash.display::MovieClip@… to DuplicateClass`
  (the placed child is still a bare MovieClip when the framescript coerces it), and
  `this.childFromOtherDomain = …` is missing. Same cause; a flip is plausible but
  not guaranteed.

Patch scope: hoist the `if (cext->timeline != NULL) { run_frame_internal;
flush_queued_places; }` block above `display_run_constructor_catching`, leaving
`construct_frame_obj` / `run_frame_scripts_obj` where they are (after
`insert_at_index`) so `loader_loadbytes_events`' `Framescript frame 1` keeps its
position between `addedToStage` and the identity checks. The in-tree comment
"the ctor must observe a null stage and a null parent" stays true — parent/stage
are set by `insert_at_index`, which is still after the ctor.
Canary (mandatory, this is the most load-bearing function in the loader): every
`avm2/loader_*`, `avm2/large_preload_*`, `from_shumway/as3-loader/*`,
`avm2/delayed_symbolclass`, `mixed_avm/*`.

### L4 — `avm2/stage_scale_factor` — **GO, +1, and the ignore-list note is REFUTED**

`ruffle-tests/tests/swfs/avm2/ignored_tests.txt:146` says
"contentsScaleFactor must be 2 (needs a simulated 2x display) — cannot pass".
That is wrong: the harness *already* simulates it. `verify_output.py:2623` emits
`-DVIEWPORT_SCALE_FACTOR={get_scale_factor(test_dir)}` from
`[player_options] viewport_dimensions = { …, scale_factor = 2.0 }`, and the only
consumer in the runtime is `capabilities_screen_dim` (`avm2_globals.c:6899`).
`stage_get_contents_scale_factor` (`avm2_display.c:12570`) returns a hard `1`.

All six diff lines split into exactly two fixes:

1. lines 3/5/9 — return `VIEWPORT_SCALE_FACTOR` (default 1) from
   `stage_get_contents_scale_factor`.
2. lines 10/11/12 — Ruffle `Stage` **overrides** `local_to_global_matrix` to
   `Matrix::IDENTITY` ("The stage is in Stage coordinates by definition",
   `core/src/display_object/stage.rs:814`). We apply the Stage's own base matrix,
   so `stage.localToGlobal(0,0)` returns the matrix's `(tx,ty)` = `(10,100)` and a
   Stage `mouseDown` reports `localX=-5 localY=-97.5`. The residual `stageX 545.05`
   vs `545` is downstream of the same bug (we derive `stageX` from a twip-quantised
   local: `356.7 * 1.5 + 10 = 545.05`), so it disappears with it.

Blast radius: corpus-wide grep — **no other fixture assigns `stage.transform.matrix`**
(only `perspectiveProjection` and a `concatenatedMatrix` read), so with an identity
stage matrix rule (2) is a no-op everywhere else. Rule (1) touches only this test
(`avm2/stage_properties` never reads `contentsScaleFactor`).
Wave-2 must also delete `stage_scale_factor` from
`ruffle-tests/tests/swfs/avm2/ignored_tests.txt` and rewrite the comment above it.

### L5 — `avm2/stage_display_state` — **GO, +1, ~40 lines**

We produce zero lines. Decompiled `frame1` (`RecompiledABC/abc0_methods.c:141-200`):
`stage.addEventListener(FullScreenEvent.FULL_SCREEN, onFullScreen)`, then
`stage.displayState = StageDisplayState.FULL_SCREEN`, then `= NORMAL`;
`onFullScreen` coerces its argument to `flash.events::FullScreenEvent` and traces
two literals plus `stage.displayState`.

Three gaps, all named:
* `FullScreenEvent` exists only as a *shell* class (`avm2_globals.c:8497`,
  base `ActivityEvent`) and the shell table deliberately carries **no constants**,
  so `FullScreenEvent.FULL_SCREEN` is `undefined` and the listener is registered
  for type `"undefined"`.
* `stage_get_display_state` returns the literal `"normal"`;
  `stage_set_display_state` (`avm2_display.c:12585`) is an explicit no-op.
* Nothing dispatches the event. Ruffle: `stage.rs:382-406` `set_display_state`
  (guards: same state, already-fullscreen, `allow_fullscreen`) then
  `fire_fullscreen_event` (`stage.rs:760-789`) constructs a real `FullScreenEvent`
  with args `("fullScreen", false, false, is_fullscreen, true)` and dispatches it
  on the Stage. The AS3 setter (`globals/flash/display/stage.rs:155-174`) does a
  case-insensitive parse and **rewrites `FullScreen` to `FullScreenInteractive`**
  ("desktop flash player at least will set its value to FullScreenInteractive"),
  which is why the expected trace reads `fullScreenInteractive`; an unparsable
  value throws `#2008`.

The coerce at op 5 means the dispatched object must really be a `FullScreenEvent`
instance; the shell class is fine for that. No getters are needed — the two
`unimplemented` lines are string literals in the fixture.
Blast radius: nil. `avm1/stage_display_state` and `from_gnash/…/Stage-v5` already
pass through the separate AVM1 `action.c` path (and expect `"fullScreen"`, i.e.
without the AVM2 setter's override — do not unify them);
`avm2/stage_properties` line 17 is a commented-out trace.

### L6 — `avm2/event_handler_exception` — **GO, +1 effective, ~3 lines**

`known_failure`, **not** ignore-listed, so `ruffle_matched` counts. Graded against
`output.ruffle.txt` (`out/rf_event_handler_exception.log`) the row is 7/11 and the
**only** defect is a missing native stack frame:

```
  at Function/<anonymous>()
- at flash.events::EventDispatcher/dispatchEventInternal()   <- Ruffle
+ at flash.events::EventDispatcher/dispatchEvent()           <- ours (only one frame)
```

`output.txt` (Flash) wants `dispatchEventFunction()` *and* `[Z:\tests\…\Test.as:10]`
source annotations, which we can never produce — `pass` is unreachable, so this is
an honest `ruffle_matched` play, not drift. Push one synthetic frame named
`flash.events::EventDispatcher/dispatchEventInternal()` under `dispatchEvent`'s
frame while running listeners.

### L7 — `avm2/large_preload_from_bytes` — **GO, +1; §18.4's mechanism is REFUTED**

§18.4 says "the loadee is an embedded `DefineBinaryData` never compiled — needs a
bytes→SWF recompile path". At HEAD the row is 41/51 and the loadee **is** compiled
and running (`[object LargeSWF]`, `Constucted nested_load/test.swf`, byte counts
all correct): its child is a real `nested_load/test.swf` file that `find_child_swfs`
already picks up, not an embed. The Multi-SWF arc closed that half.

What is left is one rotation. Expected: `exitFrame in Test` → identity checks →
`init` → `complete`. Ours: identity checks → `init` → `complete` → `exitFrame in
Test`. Both occurrences shift the same way, which is the whole 10-line miss. The
rule is Ruffle's `broadcast_frame_exited` (`frame_lifecycle.rs:193-197`): the
`exitFrame` broadcast runs and **then** `LoadManager::run_exit_frame`. Our tick
already orders `broadcast_named("exitFrame")` (`:3642`) before
`avm2_loaderinfo_run_exit_frame` (`:3647`) and `avm2_loader_drain` (`:3660`), so the
`loadBytes` completion is escaping that ordering somewhere earlier in the frame —
wave-2 should instrument where the `loadBytes` init/complete is emitted rather than
assume, then defer it to the drain like a URL load
(cf. `avm2-loader-timing-is-executor-drain`: `loadBytes` "waits", Ruffle delays a
from-bytes image by two post-frame callbacks).
Canary: `from_shumway/as3-loader/LoaderTest` and `avm2/loader_bitmap_transparency`
(the pair that pins the deferred and inline arms).

### L8 — `avm2/movieclip_addframescript_error` — **GO, medium confidence, +1**

We emit nothing at all. `Test.as` wraps three `addFrameScript()` calls in
`try/catch` and traces `e.getStackTrace()`; we never throw, so no catch runs.
`avm2_display.c:7900` loops `for (i + 1 < act->argc)` and silently ignores a short
or odd argument list. Needed: `ArgumentError #2001: Too few arguments were
specified; got N, N+1 expected.` for `argc == 0` and for an odd `argc`, plus a
`getStackTrace()` that renders `\tat flash.display::MovieClip/addFrameScript()` and
`\tat Test()`. The second half shares machinery with L6 (native frames in the AS3
stack), so the two should go to the same wave-2 slot.
Note for the coordinator: `w1-trace-new` may also have claimed this row (added
2026-08-28).

---

## 3. HOLDs, each with its completion mechanism

* **L9 `LoaderInfo.unload`.** Ruffle `loaderinfo_object.rs:266-284` dispatches a
  bare `"unload"` event on the LoaderInfo **before** removing the content child;
  our `loader_unload` (`avm2_display.c:6507`) goes straight to
  `loader_drop_content`. Graded against `output.ruffle.txt`, both `loader_events_2`
  and `mixed_avm/avm2_loads_avm1_events` are missing exactly the `unload` /
  `child unload` pair (one dispatch produces both lines — two listeners on the same
  LoaderInfo). Completion: add the dispatch, then re-grade both rows against their
  `.ruffle` oracles; `loader_events_2` additionally needs the duplicate `added`
  below, and `avm2_loads_avm1_events` needs the AVM1 child's `child` trace to sit
  after `frame 1`.
* **L9b `loader_events_2`'s duplicate `added`.** Flash *and* Ruffle both emit
  `child added: target=[object Child], currentTarget=[object Child]` **twice**; we
  emit it once. Two independent `added` dispatches on the loaded child (the
  container's and the loader's). Worth pinning before L9 is graded.
* **L10 instance-name counter.** `simplebutton_childevents_multichild` graded
  against `output.ruffle.txt` has **one** defect across its whole 119-line miss:
  we say `instance6`/`instance7` where both oracles say `instance9`/`instance10`.
  We are exactly three behind. Ruffle calls `set_default_instance_name`
  (`display_object.rs:2782`) from **twelve** `post_instantiation` sites
  (bitmap, graphic, loader_display, edit_text, text_line, text, avm2_button,
  morph_shape, avm1_button, movie_clip, video); we call ours
  (`avm2_display.c:1155`) from **five**. Completion: enumerate which object kinds
  we skip, add them, then run `ruffle-tests/recompiler_ab_sweep.sh`-style A/B over
  every fixture whose expected output contains `instance` — the counter is global,
  so this perturbs names corpus-wide and is the one lead here that can regress a
  lot of passing rows. Pays `simplebutton_childevents_multichild` (ignore-listed,
  KF bucket) and ~6 of `from_shumway/as3-loader/events/loader-events`' 27 lines.
* **L11 `avm2/displayobject_getrect`** — 11/16 at HEAD (s17's T10 landed and the
  Graphics stroke-bounds work landed: `clw_bnd` exists at `avm2_display.c:8034` and
  lines 11-14 now match). The five survivors (4, 6, 8, 10, 16) are all `getRect`
  rows where we return the stroke-INCLUSIVE `ShapeBounds`. Unchanged from s17's
  hand-off: emit DefineShape4 `EdgeBounds` into `Avm2CharInfo` (recompiler) and
  thread a `BoundsMode` through `bounds_with_transform` / `display_self_bounds` /
  `char_self_bounds`. `[approx]` in the inventory is a `test.toml` epsilon, not a
  disposition — the row is genuinely fixable.
* **L12 `timeline/missing_frame_scripts`** — re-verified at HEAD: 12/22, 27 actual,
  `Spawn` still loops forever and still reaches `Spawn stopped`. S3
  (`!has_end_tag` in `determine_next_frame`, `avm2_display.c:1934`) and S4 (orphan
  clip loses a tick) both stand exactly as `wave1-timeline-order.md` §5 describes.
  Note S4 may be partly subsumed by **L2** — both are orphan-phase bugs; whoever
  takes L2 should re-grade this row before costing S4 separately.
* **L13 `text/links_in_scrolled_text`** — the s16 patch
  (`session16-fanout-reports/w2-smalls-links_in_scrolled_text.patch`) still applies
  **clean** at `8f68a5fea` (verified with `git apply --check`, all three files).
  Row is unchanged: 1 expected line, 0 actual. The s16 completion mechanism stands —
  grade `maxscroll`/`bottomScroll` for the fixture's field against Flash first; the
  residual is `ng_computeScroll*`'s line model (a phantom trailing line from the
  HTML→text conversion), not the hit test. Still 0 flips on its own; do not merge
  it alone.
* **L14 cross-VM focus family** — re-confirmed at HEAD, no movement from the
  Multi-SWF arc.
  - `selection_onsetfocus_mixed_avm` 0/5, zero actual lines. Leg F as costed in
    `session17-fanout-reports/w2-crossvm-legE-report.md` §6: extend
    `actionAvm1ChildMousePick` with `edit_text.rs::mouse_pick_avm1`'s selectable/link
    rule (~6 lines), add `actionFocusAvm1ChildrenUnderAvm2` broadcasting
    `Selection.onSetFocus(old, new)` plus the field's `onSetFocus`/`onKillFocus`,
    and adopt the `null`-for-AVM2-object argument convention. **+1.**
  - `mouse_pick_loader_avm1` 16/42, and the observed diff is exactly the three legs
    s17 named: 2 lines of `input_txt.onSetFocus/onKillFocus` (leg F), 2 lines of
    `avm1 button clicked` (`ng_update_button_states` is only reachable from the
    AVM1-only input pump), and the `rect_mc` / `Stage` clicks the `AVM1Movie`
    wrapper's stage-rect fallback swallows. **All three must land together** — this
    is a diff-line lead, not a flip lead, until the last one does.
    `RUFFLE_VS_FLASH_DIFFERENCES.md` mentions this row only as an example of the
    machinery `avm1_root` would need; it is **not** dispositioned.
  - `focus_events_mixed_avm_edittext` 0/49 (we emit 23 lines of
    `mouseFocusChange: [object Loader]`). Needs the AVM1 tab-order half on top of
    leg F. Own slot, low priority.

## 4. NO-GOs

* **`avm2/avm1_root`** — dispositioned in
  `avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` ("The name of an AVM1 root
  loaded by an AVM2 Loader") and ignore-listed in `avm2/ignored_tests.txt`.
  Ceiling is `ruffle_matched` and reaching it means adopting `_level-61440` naming,
  which the project has declined on record. Graded against `output.ruffle.txt` the
  gap is exactly that naming. Leave alone.
* **`from_shumway/as3-loader/LoaderLoadBytesTest`** (1/4) — §18.4's mechanism is
  CORRECT here (unlike for `large_preload_from_bytes`). The loadee is
  `[Embed(source='Loadee.swf', mimeType='application/octet-stream')]`, i.e. a
  `DefineBinaryData`; `SWFRecomp/src/abc/abc_timeline.cpp:2285-2313` emits it as raw
  bytes in `avm2_generated_binaries` and nothing recompiles it. Grep confirms the
  loadee's own string `from loadee: loaded` appears in **no** `RecompiledABC` table
  in that directory, and `verify_output.py`'s `find_child_swfs` only discovers child
  SWFs that exist as files on disk. Needs a bytes→SWF recompile path (recompiler +
  harness) — its own arc, 3 lines of payoff.

## 5. Refutations and corrections (attack on my own brief)

1. **`stage_scale_factor` "cannot pass" is wrong** (§L4). The simulated 2× display
   is already wired through `-DVIEWPORT_SCALE_FACTOR`; only the getter is stubbed.
   The ignore-list comment at `avm2/ignored_tests.txt:146` should be deleted.
2. **`large_preload_from_bytes` is not a compile-path row** (§L7). It is a
   one-position ordering rotation and the row is 41/51, not blocked.
3. **`loader_try_click_root` is not an "AVM1-child remainder"** (s17's label). It is
   an AVM2-only child-boot ordering bug with a `#1009` signature, and it shares its
   mechanism with `loader_duplicate_class` (§L3).
4. **`loader_duplicate_class` is a 3-line content defect, not a 45-line one.** The
   inventory's `match=3` is real, but 42 of the 45 are positional shift from two
   lines emitted five positions late. Read near-miss loader rows with
   `--save-actual` before pricing them.
5. **`frame_script_cleanup_goto2` is not "the same nested-sprite advance-order
   mechanism as `looping_child_*`"** (s17 `wave1-trace-board.md:466`). It is a
   catch-up-walk-gate hole, proven by a single env-var A/B, and it is ~2 lines.
   Whoever owns the timeline-order arc should re-check the other 12 rows against
   `AVM2_NO_WALK_SKIP=1` before doing any more mechanism archaeology.
6. **`orphan_removeobject` was priced as "296 lines, probably one mechanism"** — the
   "one mechanism" half is confirmed, and it is a named, ~10-line Ruffle rule we
   simply never ported.
7. **The `--diff` display is offset by expected's unstripped leading blank line.**
   `compare_output` strips leading/trailing blanks from both sides
   (`verify_output.py:3542-3547`), but the printed diff does not, so any fixture
   whose `output.txt` starts blank looks one line out of phase. This burned
   `hittestpoint_boundary` in s17 (`w2-avm2-smalls-report.md` §"Refutation") and it
   nearly burned `loader_duplicate_class` here. Grade positionally with a script,
   not by eye.

## 6. New unclaimed leads

* **`AVM2_NO_WALK_SKIP=1` is a free triage axis for the whole AVM2 timeline family.**
  One run per row tells you instantly whether a frame-order defect is a real
  semantics bug or a catch-up-gate hole. Nothing in the s15-s17 boards uses it.
  Suggested sweep: every `timeline/*` and `avm2/action_order*` /
  `avm2/*goto*` / `avm1/looping_child_swf*` row currently on the board.
* **Audit every `fs_cleanup_push` / `orphan_dirty_push` / `mark_attached` site for
  the same "state changed but `walk_clean` not cleared" hole.** L1 is one instance;
  `avm2_display.c:7925` (the `else` arm) shows the intended pairing, so a grep for
  writes to `has_pending_script`, `queued_goto_frame`, `frame_scripts[...]` and
  `current_frame` that are not accompanied by `avm2_display_mark_frame_work` is a
  bounded, mechanical audit.
* **The AS3 native call stack is one frame short in at least two places**
  (`dispatchEvent`, `addFrameScript`). A general "builtin methods push a named
  frame" pass would pay L6 + L8 and probably several `getStackTrace` rows outside
  this board.
* **`avm2/orphan_removeobject`'s five extra `Running child framescript` lines** may
  survive L2; if they do they are a second, smaller orphan-phase rule worth its own
  look.
* Note for `w1-trace-new`: `avm2/movieclip_addframescript_error` (L8) overlaps your
  new-tests board; its stack-frame half is shared with L6 here, so one owner for
  both is cheaper.
