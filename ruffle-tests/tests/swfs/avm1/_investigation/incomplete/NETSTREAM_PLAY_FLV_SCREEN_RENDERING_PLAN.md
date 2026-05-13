# netstream_play_flv_screen Image Rendering Plan
<!-- TESTS: netstream_play_flv_screen -->

<!-- PLAN_META
id: NETSTREAM_PLAY_FLV_SCREEN_RENDERING
status: incomplete
phases:
  - id: 1
    name: "Widen video render gate for OFFSCREEN_RENDER (graphics-native)"
    status: complete
  - id: 2
    name: "Trace contentPath setter to confirm the 'pre-constructor' branch is taken"
    status: complete
  - id: 3
    name: "Try CONSTRUCT_PARAMETER_REPLAY Option B speculatively"
    status: complete
  - id: 4
    name: "Validate via image comparison"
    status: blocked
  - id: 5
    name: "Resolve createINCManager → undefined (NCManager dispatch gap)"
    status: ready
dependencies:
  - plan: CONSTRUCT_PARAMETER_REPLAY
    type: extends
    reason: "Existing blocked plan has already root-caused the play()-never-called gap. This plan re-opens it with new evidence."
  - plan: FLV_PLAYBACK
    type: requires
    reason: "FLV decode, NetStream play, video frame readback all work — this plan adds the rendering tail and re-attempts the component-parameter unlock."
blockers:
  - "createINCManager returns undefined when called from VideoPlayer._load — subsequent _ncMgr.setVideoPlayer / _ncMgr.connectToURL fire on undefined and silently no-op (verified by callmethod tracing). NetStream.play() is never reached. New phase 5 scoped below."
-->

Last updated: 2026-05-13

## Status: INCOMPLETE — gate widen + Option B replay landed; downstream NCManager dispatch is the next blocker

## 2026-05-13 update

Phases 1–3 landed in commits `049bfb22` (gate widen) and `066b68ca`
(CONSTRUCT capture/replay). Phase 2 instrumentation confirmed the
existing plan's root cause exactly and Phase 3 (Option B replay) was
implemented and validated against the regression matrix locally
(on_construct 25/25, netstream_play_flv 21/21, netstream_seek_flv
25/25, register_and_init_order 233/233, register_class_return_value
16/16).

CI run `25776126693` against `066b68ca` reported **zero regressions
across all eight suites** — avm1 605/651, gnash actionscript.all
126/190, misc-ming.all 66/102, misc-mtasc.all 7/9, misc-swfc.all
8/16, misc-swfmill.all 17/18, shumway 73/92, shumway/avm1 46/47.
Pass counts and mismatched-line counts unchanged versus the prior
master baseline (`ce10ee67`).

The 12-property CONSTRUCT capture now correctly replays after the
registered-class constructor builds `_vp`. The contentPath setter's
post-constructor branch fires and reaches:

```
contentPath setter
  → _vp[_activeVP].load(url, isLive, totalTime)
    → VideoPlayer.load: __get__stateResponsive, execQueuedCmds, _load
      → _load: closeNS, createINCManager, setVideoPlayer, connectToURL,
        setState, dispatchEvent ... attachMovie (new VideoPlayer)
```

**New stall point (Phase 5):** `createINCManager` returns `UNDEFINED`,
so `_ncMgr.setVideoPlayer(this)` and `_ncMgr.connectToURL(url)` are
called on UNDEFINED (verified by `obj_type=3` in the method-call trace
— ACTION_STACK_VALUE_UNDEFINED). The chain silently no-ops and
`NetStream.play()` is still never reached.

Likely causes (in descending probability):
1. `createINCManager`'s body resolves the class via a path like
   `_global.mx.video.NCManager` that fails to evaluate to the
   class function under our addProperty-getter / `__resolve` /
   `__Packages` lookup semantics.
2. The `__Packages.mx.video.NCManager` init action (script_11 →
   char 18) runs, but the assignment of the constructor to
   `_global.mx.video.NCManager` doesn't survive subsequent class-system
   bookkeeping (e.g., a `_global` write is being shadowed somewhere).
3. `createINCManager` reads its NCManager class reference from a
   FLVPlayback static (`_iNCManagerClass`-style) that's set up at class
   definition time but doesn't get populated under our `static`
   property semantics.

## Context

This plan re-opens the work tracked in
[`blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md`](../blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md).
That plan was moved to `blocked/` on 2026-04-18 on two grounds:

1. Phase 1 needs real Flash Player access to disambiguate `SetVariable` behavior during `CONSTRUCT`.
2. Ruffle ships the test with `with_renderer = { optional = true }` and (at the time) no reference image.

Both blockers are softer than originally judged:

- **Reference image exists.** `ruffle-tests/tests/swfs/avm1/netstream_play_flv_screen/output.expected.png` (3,652 bytes, 128×128, 12,474 px of `(46,83,144)` + 2,724 px of `(255,173,51)` — the Ruffle logo) is present locally and matches the upstream Ruffle copy at `~/CC/ruffle/tests/tests/swfs/avm1/netstream_play_flv_screen/output.expected.png`. So we *can* compare image output even though the trace expectation is empty.
- **Phase 1 can be approached empirically.** The existing plan's Option B (parameter capture + post-constructor replay) does not require knowing Flash's exact `SetVariable` semantics — it adds replay on top of whatever happens today. If `on_construct` (25/25) still passes after the change, the semantics are compatible.

## Evidence collected 2026-05-12 (this session)

Investigation against the current `master` (post-`f92f65a1`) under `--mode=graphics`:

1. **The rendering gate widening is correct and effective on its own merits.** Changing `tag.c:1454` and `tag.c:1518` from `#ifdef HEADLESS_GRAPHICS` to `#if defined(HEADLESS_GRAPHICS) || defined(OFFSCREEN_RENDER)` lets graphics-native (OFFSCREEN_RENDER) reach the video display-object render block. Traced via temporary `fopen(/tmp/swfdbg.log)` instrumentation:
   - `render_display_list` reaches `obj->char_id=4` (the Video) at depth 1 inside sprite 5 (VideoPlayer) inside sprite 9 (FLVPlayback).
   - `ng_isVideoChar(4)` returns 1 (correct — `tagDefineVideoStream(app_context, 4)` is emitted in the recompiled tagMain).
   - The video render block fires with `xform_id=11`, `cxform_id=0`.
   - But `actionGetVideoFramePixels(&argb, &vw, &vh)` returns `got=0` — no frame has been stored.

2. **No FLV decode happens because `builtin_ns_play` is never called.** Same trace run:
   - `[builtin_ns_play]` log line: never emitted across the entire run.
   - `[nc_connect]` log line: never emitted either.
   - The FLVPlayback component's state-machine stalls before reaching either function — exactly the `_vp == undefined` / "skip play()" branch of `__set__contentPath` that `CONSTRUCT_PARAMETER_REPLAY_PLAN.md` lines 102–130 documents.

3. **The FLV is a single keyframe.** `rufflelogo.flv` is 3,871 bytes with exactly one video tag (DataSize = 0x000F03 = 3,843 bytes; 3,843 + 11 header + 4 PreviousTagSize + 13 file header = 3,871). First data byte `0x13` = keyframe + ScreenVideo (codec 3). So `flv_decode_first_frame` is sufficient — **item #3 from the prior session prompt (per-tick decoding) is not on the critical path** and can stay deferred.

4. **`Object.registerClass` does wire up.** `script_14.c` calls `Object.registerClass("FLVPlayback", mx.video.FLVPlayback)` and runs via `tagDoInitActionGuarded(app_context, 9, script_14)` before `tagPlaceObject2WithClipActions(app_context, 1, 9, ...)` places sprite 9. Memory `register_and_init_order` (PASS 233/233) and `register_class_return_value` (PASS 16/16) confirm this wiring is healthy in general.

## Approach

### Phase 1 — Gate widening (independent, low-risk)

The two-line change in `SWFModernRuntime/src/libswf/tag.c`:

```diff
-#ifdef HEADLESS_GRAPHICS
+#if defined(HEADLESS_GRAPHICS) || defined(OFFSCREEN_RENDER)
```

at lines 1454 (`render_single_object` video block) and 1518 (`render_display_list` video block). Mirrors the EditText sibling at lines 1480 / 1547 (gotcha #14 in memory). Zero blast radius for non-video tests — `ng_isVideoChar(char_id)` returns 0 unless `tagDefineVideoStream` was emitted for that char.

**Land independently of the parameter-replay work.** Even if the FLVPlayback chain stays broken, this fix is correct on its own and unlocks any future test that calls `NetStream.play(url)` directly without going through FLVPlayback.

### Phase 2 — Confirm the stall point

Before implementing replay, instrument and confirm:

- Does `__set__contentPath` (the FLVPlayback setter at `script_defs.c:~10234-10733` per the prior plan) run during CONSTRUCT?
- Does it take the `_vp == undefined` branch (line 110 in the contentPath setter pseudocode)?
- Does it store `_contentPath` and exit without calling `play()` / `load()`?
- Does the constructor (`script_defs.c:~29-957`) fire after, and does it find `_contentPath != undefined` → skip its own default branch?

This is one stderr-logging run with three fprintf calls — cheap diagnostic and definitively confirms the root cause is still the one CONSTRUCT_PARAMETER_REPLAY_PLAN identified, rather than something newer (e.g., a regression in `tagPlaceObject2WithClipActions`).

### Phase 3 — Speculative Option B (parameter-replay list)

Per `CONSTRUCT_PARAMETER_REPLAY_PLAN.md` lines 200–236. Approach: capture every `SetVariable` name/value pair during `CLIP_EVENT_CONSTRUCT` dispatch into a per-MC list, then replay them through the addProperty setter mechanism *after* `actionInvokeRegisteredClassConstructor` returns.

Key call sites to modify (file:line as of this session):

| What | Where | Note |
|------|-------|------|
| CONSTRUCT dispatch | `SWFModernRuntime/src/libswf/tag.c` ~4441 (`actionDrainActionQueueByKind(AQ_KIND_CLIP_CONSTRUCT)`) and ~4314 (drain hook surrounding `actionInvokeRegisteredClassConstructor`) | Bracket with `g_in_construct_clip_action = 1; ... = 0;` |
| `SetVariable` non-root MC path | `SWFModernRuntime/src/actionmodern/action.c` ~31546-31574 | When `g_in_construct_clip_action` is set, also push `(name, value)` onto `g_construct_params[]` |
| Post-constructor replay | new helper called from `tag.c` immediately after `actionInvokeRegisteredClassConstructor` returns (lines 480, 626, 4337) | For each captured pair, re-invoke the addProperty setter via the usual setter dispatch |

**Storage** (sized for 12 params seen in this test's CONSTRUCT clip action, plus headroom):

```c
typedef struct {
    char* name;       // strdup'd
    u32 name_len;
    ActionVar value;  // copied; if STRING, refcount or strdup
} ConstructParam;

#define MAX_CONSTRUCT_PARAMS 32
static ConstructParam g_construct_params[MAX_CONSTRUCT_PARAMS];
static u32 g_construct_param_count = 0;
static int g_in_construct_clip_action = 0;
```

**Why this is empirically tractable.** Option B is purely additive on top of existing semantics. If Flash *does* invoke `__proto__` addProperty setters during `CONSTRUCT` (the existing plan's hypothesis A), the replay just re-fires the setter that already ran — and the setter's own no-op guards (`if (videoPlayer.url == reg[3]) return undefined`) prevent double-side-effects. If Flash *doesn't*, the replay is the only setter invocation. Either way, no test that currently passes should regress as long as the `on_construct` golden (25/25) trace still matches.

### Phase 4 — Validate

| Test | Pre-change | Target | Notes |
|------|-----------|--------|-------|
| `on_construct` | 25/25 PASS (trace) | 25/25 PASS | Must not regress |
| `netstream_play_flv_screen` | 0/0 trace PASS, image FAIL (45,183 / 16,384 px outliers) | trace PASS + image PASS (tolerance=1) | Goal of this plan |
| `netstream_play_flv` | 21/21 PASS | 21/21 PASS | Raw NetStream — must not regress |
| `netstream_seek_flv` | 25/25 PASS | 25/25 PASS | Raw NetStream — must not regress |
| `register_and_init_order` | 233/233 PASS | 233/233 PASS | Must not regress |
| `register_class_return_value` | 16/16 PASS | 16/16 PASS | Must not regress |

Local: `python3 ruffle-tests/verify_output.py --test=netstream_play_flv_screen --mode=graphics --verbose`. The trace expectation is empty — image is the only signal. Watch for stray `printf` / `fprintf(stderr)` from new code (would still show in `--verbose` but pollutes CI filtered-pass).

Once Phase 3 lands locally, push to CI for full-suite regression sweep before declaring done.

### Phase 5 — Resolve `createINCManager` → undefined

First step: find `createINCManager`'s body in `script_defs.c`
(currently grep-able via `str_470 = "createINCManager"` and the two
`PUSH_STR_ID(str_470, …)` call sites at 27070 and 32966; the body
lives in whichever `func2_anonymous_*` registers the method on the
VideoPlayer prototype). Disassemble it manually to determine which
expression returns `undefined`.

Cheap empirical pass first:
- Instrument every `actionGetMember(... "NCManager")` /
  `actionGetMember(... "mx")` / `actionGetVariable("mx")` etc. during
  the replay window. Log the type returned. If `mx.video.NCManager`
  evaluates to UNDEFINED at the moment `createINCManager` runs, the
  class lookup is the bug.
- If the class IS found but `new` produces UNDEFINED, the bug is in
  `actionNewObject` for this specific class (unlikely — `new
  NetStream` works in other tests).

Likely fix scopes by hypothesis:
- Hypothesis 1 (class lookup miss): a path-resolution gap in
  `actionGetMember` for nested package lookups (`_global.mx.video.X`).
  Adjacent code: `findPropertyStructWithPrototype` walks in
  `object.c`, and `__Packages` registry handling in `action.c` (search
  for `__Packages.`).
- Hypothesis 2 (`_global` write lost): inspect the `_global.mx = ...`
  / `_global.mx.video = ...` writes in script_2/3/4 — verify they end
  up on `global_object` and don't get shadowed by per-MC dynamic_props
  during DoInitAction context switches.
- Hypothesis 3 (static class property): the FLVPlayback class stores
  `_iNCManagerClass` as a class-level static. If our `static` semantics
  for AS2 classes lazily reset or don't survive across constructor
  invocations, this static could read as undefined.

Validation: same matrix as Phase 4. The trace test (0 lines) cannot
catch this regression — only the image diff or callmethod-trace
inspection can.

## Out of scope (deferred)

- **Per-tick `flv_decode_next_frame`.** Not needed for this test (single keyframe). Track separately if a multi-frame FLV test materialises.
- **`attachVideo` becoming a real binding.** The current global single-slot model is correct for one-stream one-Video tests. `attachVideo` can stay a stub return-undefined until a test exercises multi-stream binding.
- **FLVPlayback v2 component lifecycle (`callLater`/`invalidate`/`draw`).** Existing plan ruled this out for FLVPlayback specifically. Keep deferred unless a non-FLVPlayback component test forces it.
- **Dynamic bitmap dimensions for FLV.** The 128×128 FLV fits the 256×256 default. If a larger-video test lands, teach `getDataFilesMaxImageDims` to parse FLV `onMetaData` (or bump dims from `flv_parse_duration` outputs in `swfStart`).

## Open questions

1. Is `__set__contentPath` actually reached during this test's CONSTRUCT dispatch, or does the chain break even earlier (e.g., a registered-class constructor that doesn't fire for sprite 9 specifically)? Phase 2 answers this.
2. Does our `tagPlaceObject2WithClipActions` correctly route the CONSTRUCT clip action through `AQ_KIND_CLIP_CONSTRUCT`? Same trace run confirms.
3. Does CONSTRUCT_PARAMETER_REPLAY_PLAN's frozen `_in_construct` flag interact badly with `__resolve` / addProperty getter lookups happening synchronously inside the setter? Worth a quick read of `findPropertyStructWithPrototype` (`action.c`, search for the function name) before wiring the flag.

## Cross-references

- Canonical fix path: [`../blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md`](../blocked/CONSTRUCT_PARAMETER_REPLAY_PLAN.md) (still authoritative on root cause and on the alternatives already ruled out).
- Rendering pipeline gates analogue: gotcha #14 in `MEMORY.md` (EditText sibling at `tag.c:1480`/`:1547`).
- FLV decode reference: `SWFModernRuntime/src/actionmodern/action.c:2726-2902` (parser), `:2815-2901` (ScreenVideo decode), `:2949` (`ns_store_decoded_frame`), `:2970` (`actionGetVideoFramePixels`).
- Ruffle reference: `~/CC/ruffle/core/src/avm1/globals/netstream.rs`, `~/CC/ruffle/core/src/streams.rs`.
