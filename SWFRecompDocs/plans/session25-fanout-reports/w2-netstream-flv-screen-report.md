# s25 wave 2 — `w2-netstream-flv-screen` report

**NEW files (all under `session25-fanout-reports/`, none in the patch's landing paths):**
- `w2-netstream-flv-screen-report.md` (this file)
- `w2-netstream-flv-screen.patch`
- `w2-netstream-flv-screen-fixture/timer_type2_method_mc/{create_test_swf.py,test.swf,output.txt,test.toml}` —
  a **candidate** `regression/` fixture, staged here and NOT in the patch: its `output.txt` is hand-written from
  Flash semantics and needs an outside oracle before it can land (LOCAL ORACLE REQUEST 1).

Box: cloud, `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Upstream Ruffle tests downloaded at **`3ac8dcb07`**.
Branch base `origin/master` = `2f7be1710`.

## Verdict

**GO, +1 pixel. `avm1/netstream_play_flv_screen` image FAIL → PASS (44751 outliers / max 235 → 0 / max 0).**
Trace axis: no flips (that test's trace already passed). The RVF entry and the `ignored_tests.txt` line are removed.

Both brief candidates were partly wrong, and the RVF entry is wrong:

- **(a) is the right family, but the cause is not a missing NetStream event.** Our NetStream does deliver
  `onMetaData` and `onStatus` (`httpOnStatus`) to the component. The step that fails is FLVPlayback's own
  **`setInterval(this, "doAutoResize", …)` timer**. It fires 24 times and never gets past its first `this.` read.
- **(b) is refuted.** The attached VideoPlayer *is* walked in `OFFSCREEN_RENDER`. Once it is visible, the Video is
  drawn through `tagRerenderFrame → render_display_list → render_display_list → render_webgpu_draw_bitmap_quad_scaled`
  (gdb). No renderer change was needed, so the `render_display_list` OFFSCREEN arm is untouched.
- **The RVF "asset stamp" entry is refuted.** The 128×128 golden is a correct render. `mx.video.VideoPlayer.doAutoResize`
  sets `_video._width/_height` from the decoded stream size (128×128) on top of the 160×120 declared bounds. Our
  declared-bounds draw rule (Phase 1) stays correct.

## Mechanism (owner `SWFModernRuntime/src/actionmodern/timer.c`, `fireTimerCallback`, method-form arm)

`setInterval(obj, "name", ms)` with `obj` a **MovieClip** and `name` a **DefineFunction2** method:

1. `fireTimerCallback` passed `this_var = &t->object` (MOVIECLIP) with the type-2 flags
   `INV_CAPTURED_SCOPE | INV_FORCE_CAPTURED_WITH | INV_VERSION_SWITCH`. It had no `INV_MC_THIS_NULL_PTR`, so the core
   (`action.c` `invokeFunctionValue`, `pass_this`) handed the **raw `MovieClip*`** to `advanced_func`.
2. The recompiled prologue ("Preload 'this' into register 1") tags any non-NULL `this_obj` as
   `ACTION_STACK_VALUE_OBJECT`. Every `this.x` then read a `MovieClip` through the `ASObject` path and got
   `undefined`. Probe: `_autoResizeIntervalID`, `_autoSize`, `_aspectRatio` and `_cachedState` all came back type 3,
   while the clip's `dynamic_props` held `_autoResizeIntervalID` as an F64.
3. `VideoPlayer.doAutoResize` therefore took its `_autoResizeIntervalID > 0` false branch every tick. It never read
   `_video.width`, never ran `finishAutoResize`, and never dispatched `ready`. FLVPlayback keeps the player at
   `_visible = false` until `ready`, so the frame stayed white (md5 `7dc6ff78`, CI-identical).

The convention used everywhere else for an MC receiver of a type-2 body is `INV_EVENT_THIS_MC | INV_MC_THIS_NULL_PTR`:
NULL ABI this, so preload-this reads the clip as a MOVIECLIP off `g_event_this_mc`. It appears in `actionCallMethod`'s
`_sc_flags` (`action.c:70593`) and in the onLoad / onClipEvent dispatchers (`action.c:40120-40126`).

**Fix (v2, ~25 lines in `timer.c` only):**
- Type-2 callee with an MC receiver: add `INV_EVENT_THIS_MC | INV_MC_THIS_NULL_PTR`. This is the flip.
- Type-2 callee with any receiver: add `INV_LOCAL_SCOPE` and `act_flags = INV_ACT_THIS | INV_ACT_ARGUMENTS`. This is
  the same activation as the onLoad dispatcher's type-2 arm, gated in the core on the callee's own preload/suppress
  bits. Without it a type-2 body that reads `this` **by name** (`GetVariable("this")`, no PreloadThis flag) got
  `undefined`/`""`. The fixture's `g:` rows show this. No corpus row depends on it; it is in the patch because it is
  the same arm and the same bug class, and A/B is clean.

There are no `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS` arms in the patch, and no `tag.c` or button/mouse code
(`n-play-game` is unaffected). `timer.c` is mode-shared, so I ran no-graphics parity anyway (below).

## Per-test before/after (same box; before = clean `origin/master`, after = this patch)

Graphics (`--mode=graphics`, CI grading mode):

| test | before trace | after trace | before image | after image |
|---|---|---|---|---|
| **avm1/netstream_play_flv_screen** | PASS | PASS | FAIL 44751 / max 235 (md5 `7dc6ff78`) | **PASS 0 / max 0** (md5 `b568619e`) |
| avm1/netstream_play_flv | PASS | PASS | PASS 0/0 `747769b7` | PASS 0/0 `747769b7` |
| avm1/netstream_seek_flv, video_width_height, video_prototype_lazy | PASS | PASS | — | — |
| avm1/video_prototype_lazy_swf6_child | MISMATCH | MISMATCH | — | — |
| avm1/set_interval, timeout, timer_run_actions, string_paths_timer | PASS | PASS | — | — |
| avm1/movieclip_invalid_get_bounds_6/_7 | PASS | PASS | — | — |
| from_shumway/avm1/setinterval, settimeout | PASS | PASS | — | — |
| from_gnash/actionscript.all/NetStream-v7/-v8, Video-v7/-v8 | PASS | PASS | — | — |
| regression/timer_cross_swf_version, timer_type1_args | PASS | PASS | — | — |
| regression/avm1_attached_clip_{goto_play,natural_timeline,tagorder}{,_nonroot} (6) | PASS | PASS | — | — |
| *(staged fixture)* timer_type2_method_mc | MISMATCH | PASS | — | — |

`video_prototype_lazy_swf6_child` mismatches identically before and after; it is pre-existing and not this family.

No-graphics (13 rows: headline, the NetStream/Video avm1 rows, the timer rows, the shumway timer rows and the two
timer regression rows): **byte-identical status before vs after** apart from the staged fixture
(MISMATCH → PASS). The headline passes trace in both modes.

Fixture before-diff (clean master): `p:v=undefined`, `p:name=undefined` (PreloadThis on a clip receiver, the flip
mechanism) and `g:v=undefined`, `g:name=` (by-name `this`). `arguments` already worked before (`g:argc=1`,
`g:arg0=x1`); the Object-receiver rows were already right.

**How the sweep was scoped.** I statically scanned every downloaded AVM1 SWF (all suites except avm2/avmplus) for
`setInterval`/`setTimeout` CallFunction sites with ≥ 3 args plus a DefineFunction2 in the movie, i.e. method-form
with a possible type-2 callee. The hits were `avm1/{netstream_play_flv_screen, set_interval,
movieclip_invalid_get_bounds_6/_7}` and `from_shumway/avm1/{setinterval, settimeout}`, all in the sweep. The scan
cannot see arg counts held in registers, so it is a narrowing, not a proof; the render canary below is the backstop.

## Render canary

`render_canary.py capture` before / after over the full standing `render_canary_tests.txt` (113 rows; it already
includes `avm1/netstream_play_flv_screen`), `-P 2`. Result: **112 tests / 171 comparisons:
170 IDENTICAL (md5), 1 DIFFERS, 0 appeared / vanished / no-render.** The one mover is the ledger row:
`avm1/netstream_play_flv_screen` image fail → pass (44844 diff channels, bbox the full 128×128 frame). There were
**no trace status changes**.

## EXPECTED-FLIP LEDGER (check CI against this)

| axis | test | expected move |
|---|---|---|
| pixel | `avm1/netstream_play_flv_screen` [image:output] | ignored-fail → **PASS** (it leaves the global ignore list, so it now counts on the image board: +1) |
| trace | `avm1/netstream_play_flv_screen` | stays `pass`; it now also counts in the *filtered* report because it is no longer ignored (not a graded move) |
| trace | — | no other trace moves expected, either mode |
| pixel | — | no other pixel moves expected (canary md5 identity outside the row above) |

## Patch scope

`w2-netstream-flv-screen.patch` = `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py
ruffle-tests/render_canary_tests.txt ruffle-tests/ignored_tests.txt
ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md
SWFRecompDocs/plans/video-display-flash-parity-plan.md`. I added the last three paths to the standard formula because
the disposition removal is part of this task. The patch touches:
- `SWFModernRuntime/src/actionmodern/timer.c` (`fireTimerCallback` only)
- `ruffle-tests/ignored_tests.txt`: `netstream_play_flv_screen` and its rationale removed; header trap-1 and the
  s17 re-run comment updated to say it was removed
- `RUFFLE_VS_FLASH_DIFFERENCES.md`: the "Video Display Object Render Bounds … Asset Stamp" section removed
- `video-display-flash-parity-plan.md`: a CORRECTION banner refuting its §3–§4 stamp conclusion

No `render_canary_tests.txt` change; the standing set already covers the row. No recompiler change.

## Refutations

1. **RVF "asset stamp"** (see Verdict). Byte-identity of a lossless ScreenVideo render with its source PNG is the
   expected outcome of a correct 1:1 render, not evidence of a stamp. The RVF step-3 claim that "auto-resize is
   opt-in" came from the wrong class. It read the MX2004 `mx.controls.videoClasses` source; this SWF ships FLVPlayback
   1.0.2's `mx.video.VideoPlayer`, whose `doAutoResize`/`finishAutoResize` (decompiled from `script_3.c`
   `func2_anonymous_214`) do resize `_video`.
2. **Brief (b), attached clips not walked in OFFSCREEN.** Refuted by gdb (above). The OFFSCREEN post-loop
   `mc->parent != &root_movieclip` skip is real, but this subtree does not depend on it.
3. **Brief (a)'s "NetStream never delivers ready/metadata".** Refuted. `onMetaData` → `metadataReceived` and
   `httpOnStatus` all fire (CallMethod probe). `ready` is component-internal and gated on the broken timer.

## New unclaimed leads

- **L1 the `object.c` "corrupt ASObject" guards likely mask other mis-tagged receivers.** `avm1/CURRENT_STATUS.md:245`
  records an old fix for this same test: "safety checks in object.c `getProperty`/`getPropertyWithPrototype`/
  `findPropertyRaw` reject corrupt ASObjects (num_used > 16384)", with the root cause given as "createVideoPlayer called
  with NULL this". That is the same `MovieClip*`-read-as-`ASObject` shape fixed here. The guards turn the crash into a
  silent `undefined`. Cheap probe (S): count guard rejections per test over the AVM1 corpus on CI or a local sweep;
  any non-zero row is a dispatch arm passing a raw `MovieClip*` to a type-2 body without `INV_MC_THIS_NULL_PTR`.
- **L2 audit the other type-2 dispatch arms for the same flag pair.** Grep every `invokeFunctionValue` /
  `actionInvokeFunctionValue` call whose `this_var` can be a MOVIECLIP and whose type-2 flags lack
  `INV_MC_THIS_NULL_PTR` (Function.call/apply on a clip, watch callbacks, AsBroadcaster/listener dispatch,
  `addProperty` getters on clips). Price: S to scan, flips unknown. Game-relevant: AS2 components register classes onto
  attached clips and drive them from `setInterval(this, …)`.
- **L3 the function-form timer arm** (`setInterval(fn, ms)` with a type-2 `fn`) still builds no local activation, so
  by-name `arguments`/locals may be unbound. Not measured; the same one-line pattern applies if a row shows it.

## LOCAL ORACLE REQUESTS

1. Ruffle exporter trace of
   `SWFRecompDocs/plans/session25-fanout-reports/w2-netstream-flv-screen-fixture/timer_type2_method_mc/test.swf`
   (`exporter -s -f 4 --trace-log out.txt test.swf out.png`). If it is byte-identical to the staged `output.txt`, move
   the directory to `ruffle-tests/tests/swfs/regression/timer_type2_method_mc/` (our patched build already passes it
   in both modes). If Ruffle differs on the `p:name=undefined` Object row (SWF7 `undefined` concat), take Ruffle's line
   for that row only; the clip rows are the point of the fixture.
