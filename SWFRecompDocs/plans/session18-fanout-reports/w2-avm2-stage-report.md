# w2-avm2-stage — session 18 wave 2 (Stage scale factor, displayState/FullScreenEvent, native dispatch frame)

Agent `w2-avm2-stage`, isolated worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-aa2feab9d0e71f694`, base `8f68a5fea`.
Diagnosis of record: `w1-trace-display-report.md` §2 L4, L5, L6, §5.

**NEW files: none.** Every edit is to an existing tracked file; no header, CMake or
Emscripten source-list change is required.

Deliverables:
* patch — `SWFRecompDocs/plans/session18-fanout-reports/w2-avm2-stage.patch`
* this report — `SWFRecompDocs/plans/session18-fanout-reports/w2-avm2-stage-report.md`

---

## 1. Verdict

| lead | test | before | after | verdict |
|---|---|---|---|---|
| L4 | `avm2/stage_scale_factor` | `output_mismatch` 6/12 | **`pass` 12/12** | **GO — landed, +1** |
| L5 | `avm2/stage_display_state` | `output_mismatch` 0/6 (0 actual lines) | **`pass` 6/6** | **GO — landed, +1** |
| L6 | `avm2/event_handler_exception` | `output_mismatch` (10 actual, 7/11 vs `.ruffle`) | **`ruffle_matched` 11/11 vs `output.ruffle.txt`** | **GO — landed, +1 effective** |

**+3 corpus rows** (2 `pass`, 1 `ruffle_matched`), plus one ignore-list prune
(`stage_scale_factor`), which is a further **+1 to the FILTERED denominator's
numerator** — the row was being subtracted from the effective count on the strength
of a claim that is now disproved.

Wave-1's pricing survived intact on all three: the mechanisms were exactly as
`w1-trace-display-report.md` described, and the line counts were close (L4 ~10 →
41 lines incl. comments; L5 ~40 → 104; L6 ~3 → 15).

---

## 2. What changed, and why

### L4 — `Stage.contentsScaleFactor` + Stage-space local↔global

Two independent halves, exactly as w1 split them.

**(a) `contentsScaleFactor` — 3 lines of the diff.** `stage_get_contents_scale_factor`
(`avm2_display.c`) returned a hard `1`. `verify_output.py:2623` already compiles
`-DVIEWPORT_SCALE_FACTOR={scale_factor}` from `test.toml`'s `[player_options]
viewport_dimensions`, and the only consumer was `capabilities_screen_dim`. The getter
now reads the same define (falling back to `1` when no viewport override exists, i.e.
when there is no simulated display at all). **w1's refutation of the ignore-list note is
confirmed empirically, not just by reading.**

**(b) Stage local↔global is the IDENTITY — 3 lines of the diff.** Ruffle
`Stage::local_to_global_matrix` (`display_object/stage.rs:814`) overrides the walk with
`Matrix::IDENTITY` ("The stage is in Stage coordinates by definition"), and the generic
walk `local_to_global_matrix_without_own_scroll_rect` (`display_object.rs:1490-1500`)
**breaks at a Stage ancestor** without applying its matrix ("We want to transform to
Stage-local coordinates"). We applied the Stage's own `ext_matrix` in both, so with
`stage.transform.matrix = (1.5,0,0,1,10,100)`:

```
stage.localToGlobal(0,0)  ->  (10,100)   want (0,0)
mouseDown localX/localY   ->  -5 / -97.5 want 2.5 / 2.5
mouseDown stageX          ->  545.05     want 545      (356.7*1.5 + 10, a round trip
                                                        through the bogus local)
```

The patch adds the ancestor break to `display_l2g_matrix_no_own_sr`, the
self-is-Stage identity to `display_l2g_matrix`, and a new file-static
`display_stage_space_matrix()` used by the two mouse helpers (`local_mouse`,
`avm2_display_event_stage_coords`) that were reading the RENDER concat
`display_world_matrix` instead.

**Why a third function rather than pointing the mouse helpers at
`display_l2g_matrix`.** Ruffle's mouse path really does go through
`local_to_global`/`global_to_local`, scroll rects and all — but switching our two
helpers to `display_l2g_matrix` would *also* change how a committed `scrollRect`
enters the mouse mapping, which is a live, separately-owned bug
(`displayobject_scrollrect` is on the ignore list for exactly that residual).
`display_stage_space_matrix` is `display_world_matrix` **plus the Stage rule and
nothing else**, so it is bit-identical to what those helpers did before wherever the
stage matrix is the identity. A corpus grep confirms `avm2/stage_scale_factor` is the
only fixture that ever assigns `stage.transform.matrix` (the others only read
`concatenatedMatrix` or set `perspectiveProjection`), so the blast radius of the whole
half is one test. `display_world_matrix` itself is untouched — the renderer must keep
the stage matrix.

### L5 — `Stage.displayState` + `FullScreenEvent`

Three gaps, all three closed:

1. **`FullScreenEvent.FULL_SCREEN` was `undefined`**, so the fixture registered its
   listener for type `"undefined"` and traced nothing at all. `FullScreenEvent` is one
   of the 45 pure playerglobal *shells* in `register_events_shell_classes`
   (`avm2_globals.c`), and that table deliberately carries no constants. It now carries
   the two `FullScreenEvent.as` constants (`"fullScreen"` /
   `"fullScreenInteractiveAccepted"`) as a **named single exception**, with the comment
   block amended to say why. `builtin_class_impl` is NOT idempotent, so the constants
   are added *inside* the shell loop where the class object already exists — no second
   `avm2_builtin_class(...)` call anywhere. The class pointer is stashed in a
   file-static and exposed as `avm2_full_screen_event_class()` (declared next to the
   existing `avm2_uncaught_error_events_class()`), so `avm2_display.c` can construct a
   real instance without re-registering anything.
2. **`stage_get_display_state` returned the literal `"normal"`** and
   `stage_set_display_state` was an explicit no-op. They now share a file-static
   tri-state, a `StageDisplayState::from_str`-equivalent (ASCII-lowercased compare
   against `fullscreen` / `fullscreeninteractive` / `normal`, anything else →
   `ArgumentError #2008`, Ruffle `make_error_2008(activation, "displayState")`), and
   the AS3 setter's `FullScreen → FullScreenInteractive` rewrite
   (`globals/flash/display/stage.rs:160-164`) — which is why the fixture's expected
   trace reads `fullScreenInteractive`.
3. **Nothing dispatched the event.** The setter now ports
   `Stage::set_display_state`'s early-outs (same state; already-fullscreen; the
   `allow_fullscreen` gate, which `stage_get_allows_fullscreen` reports `true`) and
   `fire_fullscreen_event`'s AVM2 arm (`stage.rs:760-789`): a genuine
   `FullScreenEvent` constructed with `("fullScreen", false, false, is_fullscreen,
   true)`, dispatched on `ctx->stage`. The shell's `instance_init` already chains to
   `Event`'s, so `type/bubbles/cancelable` are set and the fixture's
   `coerce flash.events::FullScreenEvent` at op 5 succeeds. The two
   `fullScreen`/`interactive` getters are NOT needed — the fixture traces string
   literals for those.

**The AVM1 path is deliberately not unified.** `avm1/stage_display_state` and
`from_gnash/actionscript.all/Stage-v5` both expect `"fullScreen"` (no rewrite) and run
through `action.c`'s own `Stage.displayState`; the rewrite lives in the AS3 setter only.
Both were re-run as canaries and are unchanged.

### L6 — the missing `dispatchEventInternal()` frame

FP's `EventDispatcher.dispatchEvent` is AS3 playerglobal whose body calls a native
worker (`dispatchEventFunction` in Flash, `dispatchEventInternal` in Ruffle's
`EventDispatcher.as`), so a throwing listener reports **two** frames for one AS3
`dispatchEvent()` call. Ours is a single native method, so `ed_dispatch_event`
(`avm2_events.c`) now pushes a synthetic native frame named
`flash.events::EventDispatcher/dispatchEventInternal` around the `avm2_dispatch_event`
call and pops it after (`avm2_callstack_push`/`_pop` with a `static const
Avm2MethodRef` — the same idiom as `avm2_callstack_push_throwerror`, but with a real
pop because `dispatchEvent` returns normally; a listener's throw is caught per-listener
by `avm2_try_push_catch_all`, and an escape would be unwound by the enclosing try
frame's `call_depth` restore anyway).

Deliberately scoped to the **AS3 entry point**, not `avm2_dispatch_event`: the same
fixture's first trace (the `enterFrame` listener) has *no* dispatch frames at all, so
the runtime's own broadcasts must stay frame-free.

`pass` is unreachable for this row — `output.txt` also wants
`dispatchEventFunction()` and `[Z:\tests\...\Test.as:10]` source annotations — so the
ceiling is `ruffle_matched`, and the row now sits exactly on it (11/11 against
`output.ruffle.txt`, verified with `--expected-suffix=ruffle`; a normal-grading run
reports `RUFFLE_MATCHED`).

---

## 3. Patch scope

| file | region | lines |
|---|---|---|
| `SWFModernRuntime/src/avm2/avm2_display.c` | `display_l2g_matrix_no_own_sr` / `display_l2g_matrix` / new `display_stage_space_matrix`; `local_mouse`; `avm2_display_event_stage_coords`; Stage `contentsScaleFactor` + `displayState` getter/setter | +145 / −4 |
| `SWFModernRuntime/src/avm2/avm2_events.c` | `ed_dispatch_event` only | +16 |
| `SWFModernRuntime/src/avm2/avm2_globals.c` | `register_events_shell_classes` (FullScreenEvent constants + accessor) | +27 / −5 |
| `SWFModernRuntime/include/avm2/avm2_globals.h` | one declaration next to `avm2_uncaught_error_events_class` | +3 |
| `ruffle-tests/tests/swfs/avm2/ignored_tests.txt` | prune `stage_scale_factor`, rewrite its note | +6 / −3 |

**Runtime-only** — `SWFRecomp/build` was copied from the main tree; no recompiler
change, so the emitted C is untouched.

**Sibling overlap check.** `avm2_display.c` regions touched are the geometry walk
(≈:3889-3958) and the Stage block (≈:12604-12730). Siblings own the MovieClip /
`addFrameScript` (≈:7900), `orphan_cleanup` (≈:181), Vector3D, flash.ui, `gfx_stroke_*`
(≈:8176) and `soundTransform` regions — no textual overlap. `avm2_globals.c`: only
`register_events_shell_classes`; w2-avm2-new-smalls' `flash.ui` work is a different
function. `avm2_events.c` is not on any other agent's file list.

---

## 4. Canary ledger

All canaries were run in the worktree on the patched tree; every row's before-state is the
`8f68a5fea` baseline in `avm2/_results/results_graphics.json`. No-graphics unless marked.
**Zero transitions anywhere except the three headline rows.**

**Headline (both modes):**

| test | mode | before | after |
|---|---|---|---|
| `avm2/stage_scale_factor` | no-graphics | `output_mismatch` 6/12 | **PASS 12/12** |
| `avm2/stage_scale_factor` | **graphics** | `output_mismatch` | **PASS** |
| `avm2/stage_display_state` | no-graphics | `output_mismatch` 0/6 (0 actual lines) | **PASS 6/6** |
| `avm2/stage_display_state` | **graphics** | `output_mismatch` | **PASS** |
| `avm2/event_handler_exception` | no-graphics, `--expected-suffix=ruffle` | 7/11 | **PASS 11/11** |
| `avm2/event_handler_exception` | no-graphics, normal grading | `output_mismatch` | **`RUFFLE_MATCHED`** |
| `avm2/event_handler_exception` | **graphics**, `--expected-suffix=ruffle` | — | **PASS** |

**Canary group 1 — `avm2` stage + the geometry the matrix change could reach (13/13 PASS,
was 13/13):** `stage_access`, `stage_properties`, `stage_properties2`,
`stage_overriden_setters`, `stage_displayobject_properties`, `stage_mousechildren`,
`stage_invalidate`, `displayobject_transform`, `displayobject_scrollrect`,
`displayobject_hittestpoint`, `mouse_pick_masking`, `mouse_click_events`,
`mouse_pick_text`.

**Canary group 2 — `avm2` events + the shared stack-trace printer (13/13 effective,
identical status split to baseline: 11 PASS + 2 `RUFFLE_MATCHED`):** `error_stack_trace`,
`error_stack_trace_edge_cases`, `error_throwerror`, `uncaught_error_basic`,
`error_1034_debug_string` (`RUFFLE_MATCHED`, unchanged), `uncaught_errors_stringified`
(`RUFFLE_MATCHED`, unchanged), `eventdispatcher_dispatchevent`,
`eventdispatcher_dispatchevent_indirect`, `eventdispatcher_dispatchevent_handlerorder`,
`eventdispatcher_dispatchevent_cancel`, `event_bubbles`, `event_target_getter`,
`event_clone_error_redispatch`.

**Canary group 3 — the AVM1 `displayState` path + `regression` (5/5 PASS):**
`avm1/stage_display_state` PASS, `from_gnash/actionscript.all/Stage-v5` PASS,
`regression/avm2_simplebutton_click` PASS, `regression/avm2_reflect_trait_hooks` PASS,
`regression/avm2_parent_child_render` PASS.

**Pixel A/B (the brief's question — does L4 move `stage_scale_factor`'s image half?).**
**No — proven, not argued.** `--mode=graphics --images` was run on both sides of
`git apply -R`, and the rendered PNG is **byte-identical**:

```
3d22fe365cc3a13919989586c9484649  before-img/avm2/stage_scale_factor/output.actual.png
3d22fe365cc3a13919989586c9484649  after-img/avm2/stage_scale_factor/output.actual.png
```

The comparison result is unchanged at **1 912 924 outliers / max diff 254** — the exact
number in `graphics-image-baseline.md:185` and in w1-gfx-smalls' board. That is expected:
`display_world_matrix`, the render concat, is the one matrix helper the patch does NOT
touch, and w1-gfx-smalls already established the pixel half is Stage3D-dominated (the
fixture's expected PNG carries a `Context3D.drawTriangles` background we never draw).
The pixel row stays parked with the Stage3D arc; the trace row is now a `pass`. Image
comparisons never gate trace pass/fail, so `stage_scale_factor` counts as a flip.

**`movieclip_addframescript_error` (L8, w2-avm2-new-smalls'):** not run and not touched —
the patch adds no frame to `addFrameScript`. It should, however, *benefit*: L8's second
half wants `\tat flash.display::MovieClip/addFrameScript()` in a `getStackTrace()`, and
this patch demonstrates the exact mechanism (a `static const Avm2MethodRef` +
`avm2_callstack_push`/`_pop` pair around the native body) that produces such a line. Its
owner can copy the three lines in `ed_dispatch_event`.

**Reproduction.** `SWFRECOMP_COMPILE_TIMEOUT=2400`, `DAWN_INSTALL=/home/robert/CC/dawn-install`
for the graphics legs, `--recompile` on first use of each copied test dir, one batch at a
time. Logs and saved outputs:
`<scratchpad>/w2-avm2-stage/out/` (`base_*` = pre-patch, `a1_*` = post-patch,
`canary_*.json`, `gfx_*.json`, `before-img/`, `after-img/`).

---

## 5. Refutations / things that did not hold

1. **`avm2/ignored_tests.txt:146`'s "cannot pass" is now disproved BY EXECUTION**, not by
   reading. w1 called it; this run proves it. The entry is deleted and replaced by a
   pruned-note that says what the error was, so the next reader does not re-derive it.
   Anyone auditing that file should treat its other "cannot pass" notes with the same
   suspicion — this one had stood unchallenged since it was written.

2. **L4 is TWO independent fixes and neither is optional.** Reverting either half alone
   leaves the row failing (3 diff lines each). The brief said so; worth restating because
   the row reads like a one-line getter change.

3. **The Stage identity rule is NOT confined to `localToGlobal` — w1's write-up is
   incomplete here.** Rule (2) is framed as `Stage::local_to_global_matrix → IDENTITY`,
   and that alone fixes line 10. Lines 11/12 come through `local_mouse` /
   `avm2_display_event_stage_coords`, which read `display_world_matrix` — a *different*
   helper the override does not reach. A patch that edited only `display_l2g_matrix` would
   have scored 10/12, not 12/12. Ruffle hides this because its mouse path calls
   `local_to_global`/`global_to_local` directly; ours does not.

4. **`allow_fullscreen` is not a guard to skip.** Ruffle's `set_display_state` returns
   early on `!allow_fullscreen()`. Our `stage_get_allows_fullscreen` reports `true`
   unconditionally, so the guard is vacuous *today* — the same-state and
   already-fullscreen guards are ported and the third is named in a comment, because the
   moment that getter becomes a real player option the setter must follow it.

5. **The AVM1 and AVM2 `displayState` paths must NOT be unified.** They disagree on
   purpose: the `FullScreen → FullScreenInteractive` rewrite lives in the AS3 setter
   (`globals/flash/display/stage.rs:160-174`), not in the core, and
   `avm1/stage_display_state` + `from_gnash/…/Stage-v5` both expect the un-rewritten
   `"fullScreen"`. Both were run as canaries and are unchanged. A future "tidy-up" that
   shares one setter across the two VMs would regress two passing rows.

6. **`builtin_class_impl` really is not idempotent** (the brief's warning holds): a second
   `avm2_builtin_class(ctx, "flash.events", "FullScreenEvent", …)` mints a *second* class
   object, and the fixture's `coerce flash.events::FullScreenEvent` at op 5 would then
   fail against an instance of the wrong one. Hence: constants added inside
   `register_events_shell_classes`'s existing loop, class handed out via an accessor.

7. **`event_handler_exception`'s ceiling really is `ruffle_matched`, and the row now sits
   exactly on it.** `output.txt` also wants `dispatchEventFunction()` and
   `[Z:\tests\…\Test.as:10]` source annotations, which we cannot produce. Under rule 3 of
   `BRIEFS_COMMON.md` a `pass → ruffle_matched` move is a regression; this is
   `output_mismatch → ruffle_matched`, which is a gain, not drift.

8. **Not refuted but worth recording: the ignore-list prune is a second, separate win.**
   `stage_scale_factor` was being *subtracted* from the filtered denominator on the
   strength of the false note. Pruning it means the row now both passes and counts.

---

## 6. New unclaimed leads

* **The `dispatchEventInternal` push is the first instance of a general pattern.** FP's
  playerglobal is AS3 wrapping native workers all across `flash.events` / `flash.display`,
  so every such method is one frame short in our traces. Mechanical audit: for each
  builtin whose Ruffle counterpart is an `.as` file whose body is a single call to a
  `…Internal` / `…Function` worker, push the worker's frame. A grep of
  `~/CC/ruffle/core/src/avm2/globals/**/*.as` for one-line delegating bodies enumerates
  the candidates in one pass. Pays L8 (`movieclip_addframescript_error`) and probably
  several `error_stack_trace*` / `getStackTrace` rows outside this board. The three lines
  in `ed_dispatch_event` are the template.

* **`FullScreenEvent.fullScreen` / `.interactive` getters are still missing.** The
  fixture only traces string literals for them, so nothing grades it today — but the
  instance we now dispatch takes the two booleans as constructor arguments and drops them
  (the shell's `instance_init` is `Event`'s three-arg one). Any future fixture reading
  `e.fullScreen` gets `undefined`. Two slots plus two getters closes it; the same shape
  applies to every other shell whose real class carries state.

* **The other 44 event shells still carry no constants, and the failure signature is
  silence.** `FullScreenEvent` was promoted because a graded fixture reads one. The same
  trap waits for `SyncEvent.SYNC`, `ThrottleEvent.THROTTLE`,
  `StageVideoEvent.RENDER_STATE`, … — and the symptom is not an error but a listener
  quietly registered for type `"undefined"` and a fixture that traces **nothing at all**,
  which is the hardest thing to triage from a results table (`stage_display_state` was
  0 actual lines). A bulk pass reading the values out of
  `~/CC/ruffle/core/src/avm2/globals/flash/events/*.as` is bounded; the `DtDescConst` rows
  that already drive `describeType` give the NAMES for free.

* **We now have three matrix walks where Ruffle has two.** `display_world_matrix` (render),
  `display_l2g_matrix` (script), and the new `display_stage_space_matrix` (mouse) — the
  third exists only because the mouse helpers historically read the render walk and
  switching them wholesale would also change scrollRect handling. Whoever fixes
  `displayobject_scrollrect`'s render-committed-rect residual should collapse the third
  into `display_l2g_matrix` in the same change.

* **Nothing in the corpus assigns `stage.transform.matrix` except this one fixture**, so
  the entire Stage-matrix path is ungraded outside `stage_scale_factor` — a good candidate
  for a `regression`-suite test if the windowed-native / multi-SWF work ever starts
  setting it.
