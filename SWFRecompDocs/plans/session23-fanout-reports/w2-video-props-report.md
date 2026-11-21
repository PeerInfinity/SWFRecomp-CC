# w2-video-props: AVM1 Video.width/height as lazy prototype accessors (session 23, wave 2)

Slot V of `w1-drift-avm1` (§1 NetStream-SquareTest row and the `video_*` rows, §5 "V").
Branch `fanout/w2-video-props`. Base: origin/master `d39e9a7b` (carries `cfc56d74b`). Upstream test
corpus: `download_tests.sh` pulled Ruffle master **`aa9f62a70`** (1 commit past `0ddd12b6a`; it touches
none of the rows below). Box: cloud, Dawn on lavapipe, `SETUP_STATUS` all OK.

**NEW files:** none in source. Deliverables only: this report and `w2-video-props.patch`.
No new fixture: every behaviour here already has a corpus test whose expected output came from
Flash (`avm1/video_width_height`, `avm1/video_prototype_lazy(_swf6_child)`) or gnash/Flash
(`NetStream-SquareTest`), so no `regression/` fixture was needed (see §6).

## 0. Verdict and expected-flip ledger

**GO. Headline met (+1 drift re-flip), plus stretch +1. Both modes, per-test identical.**

### EXPECTED-FLIP LEDGER (check CI against this)

| Axis | Test | origin/master (local, both modes) | with patch (local, both modes) |
|---|---|---|---|
| trace | `from_gnash/misc-ming.all/NetStream-SquareTest` | output_mismatch 150/216 | **ruffle_matched** 166/216 |
| trace | `avm1/video_width_height` | output_mismatch 3/19 | **pass** 19/19 |
| trace (no flip) | `avm1/video_prototype_lazy` | output_mismatch 9/21 | output_mismatch **20/21** |
| trace (no flip) | `avm1/video_prototype_lazy_swf6_child` | output_mismatch 2/8 | output_mismatch **4/8** |
| pixel | (none) | | all 25 video-row PNGs and all 151 canary PNGs md5-identical |

Net trace: **+2 effective** (one `ruffle_matched`, one `pass`), 0 losses. Pixel: 0 moves.

- `NetStream-SquareTest` has `known_failure = true`. This is a `fail → ruffle_matched` move (the
  pre-drift status), not a `pass → ruffle_matched` one, so it is not the regression the brief warns about.
  A Flash-exact `pass` is out of reach: 50 Flash-PASSED lines remain, among them
  `Video.prototype.hasOwnProperty('smoothing'/'deblocking')` (×4, Ruffle FAILs them too) and the
  timing/metadata block. See §7.
- `video_width_height` is a plain test (no `known_failure`, no sidecar), so its `pass` is Flash-exact.

## 1. Mechanism (what Flash/Ruffle do; what we did)

Ruffle `d900f711d` / `c8a03ccd3` (`core/src/avm1/globals/video.rs` at `0ddd12b6a`, read from source):
- `width`/`height` are `LAZY_PROTO_DECLS`: `property(video_method!(width); VERSION_6)`.
- `define_lazy_proto_properties` runs when a Video **display object** is created (`new Video()` does not
  count). It is guarded per prototype object by `avm1.mark_lazy_proto_initialized`, which is player-wide,
  so the record is shared across movies.
- The getter is `video.decoded_size()`, the last decoded bitmap's size, or 0. A non-Video receiver
  gets `undefined`.
- `attach_video` switches the source only for a NetStream. Any other value leaves it alone.

Ours before the patch:
- `initVideoPrototype` defined only stub `attachVideo` and `clear`.
- A timeline Video's wrapper MovieClip fell back to the `g_stub_ctors[16]` prototype for member lookup only.
- It was not the prototype the movie's `_global.Video` actually exposes: SWF7+ and SWF6 have separate
  constructor copies (`createConstructorCopy` :45316).
- `__proto__` was never captured, and `_width`/`_height` were 0.

The patch (`SWFModernRuntime/src/actionmodern/action.c`, one self-contained block after
`initVideoPrototype`, plus three small hooks):

1. **Placement hook, both modes.**
   - `ng_on_place_object2` (`libswf/tag_stubs.c:964`) calls the new `actionOnVideoPlaced()` for every
     video character.
   - `tag_stubs.c` is compiled in **both** `verify_output.py` modes (source lists :2623-2624), and
     every `tagPlaceObject2*` arm in `tag.c` funnels through it. One hook therefore gives mode parity.
   - `actionOnVideoPlaced`:
     - calls `ensureGlobalInit` (a Video can be placed before any script ran);
     - eagerly creates the named wrapper (as placed TextFields already are), and binds its
       `display_obj` if it is still NULL;
     - resolves `getActiveGlobal().Video.prototype` through `GetMember`, so a constructor copy's lazy
       prototype materializes;
     - defines the accessors once per prototype (`videoDefineLazyProps`);
     - sets the wrapper's `dynamic_props.__proto__` (DONT_ENUM) to that prototype.
   - A wrapper that already has a captured `__proto__` is a live Video being moved, so it is skipped.
2. **Accessors.**
   - `setAddPropertyWithFlags(width|height, getter, no-op setter, PROPERTY_FLAGS_DEFAULT)`: enumerable
     and deletable, which `video_prototype_lazy`'s "enumerable" and delete rows require.
   - `flash_flags = 0x0080`, the `VERSION_6` mask also used by AsBroadcaster.initialize.
   - A recorded-proto table, retained so an address is never reused.
   - The getter's receiver comes from `videoReceiverMc`: the ABI `this`, the dynamic_props bag, or
     `g_this_stack`/`g_event_this_mc` (the MOVIECLIP dispatchers pass a NULL ABI `this`, :16555).
   - The getter returns the per-Video cached decoded size, or 0.
3. **`attachVideo` is real now** (`videoAttachVideo`).
   - It records the attached NetStream per Video.
   - A non-object argument (e.g. `attachVideo(null)`) leaves the attachment alone, as Ruffle does.
4. **Decoded-size visibility.**
   - `play()` decodes the first frame synchronously (`builtin_ns_play`).
   - Flash reports 0 until the stream starts (`after play: width=0`), so `videoRefreshSize` holds the
     size back while the stream's `pending_start` is set.
   - The last size is kept after `ns.close()` / `attachVideo(null)`.
5. **No-graphics parity probe.**
   - `verify_output.py` links libavcodec **only** in graphics mode (:2979-2992), so in no-graphics an
     H.263 stream never decodes and `video_width_height` would pass only under graphics.
   - When `play()` decoded no frame, `videoProbeStreamSize` reads the Sorenson H.263 picture header
     (PictureStartCode / PictureSize, FLV spec). That header is the size the decoder produces.
   - A real decode always wins.
   - With this, `video_width_height` passes in **both** modes, so per-test parity holds.
6. **`_width`/`_height` = DefineVideoStream bounds.**
   - `mcGetOriginalBounds` (:32086) gets a timeline-Video arm returning `ng_getVideoDimensions`
     (160×120, not the 320×233 decoded size; Ruffle `display_object/video.rs` self bounds).
   - Scale, rotation and `_width=` then use the existing machinery (`_width=640` → 640;
     `_xscale=50` → 80; `_rotation=90` → 240×80; all lines match).

Self-localization:
- Everything new is `static` inside one block, except the exported `actionOnVideoPlaced`.
- The touch points are:
  - the `initVideoPrototype` attachVideo line;
  - one `else` after `ns_store_decoded_frame` in `builtin_ns_play`, plus a forward declaration;
  - the video arm in `mcGetOriginalBounds`, between the loaded-image and button arms (not the TextField arm);
  - the `tag_stubs.c` hook.
- None of these is in the text-measurement code that `w2-avm1-devicefont` edits.
- AVM2 is structurally unaffected: `src/avm2` never calls `tagPlaceObject*`/`ng_on_place_object2`.

## 2. Per-test before/after (same box; clean origin/master via `git apply -R` vs patch)

Status and matching lines (LCS of expected vs actual). G = `--mode=graphics`, N = no-graphics.

| Test | before G | after G | before N | after N |
|---|---|---|---|---|
| from_gnash/misc-ming.all/NetStream-SquareTest | output_mismatch 150/216 | **ruffle_matched 166/216** | output_mismatch 150/216 | **ruffle_matched 166/216** |
| avm1/video_width_height | output_mismatch 3/19 | **pass 19/19** | output_mismatch 3/19 | **pass 19/19** |
| avm1/video_prototype_lazy | output_mismatch 9/21 | output_mismatch 20/21 | output_mismatch 9/21 | output_mismatch 20/21 |
| avm1/video_prototype_lazy_swf6_child | output_mismatch 2/8 | output_mismatch 4/8 | output_mismatch 2/8 | output_mismatch 4/8 |
| from_gnash/misc-ming.all/Video-EmbedSquareTest | pass 2/2 | pass 2/2 | pass 2/2 | pass 2/2 |
| avm1/netstream_play_flv | pass | pass | pass | pass |
| avm1/netstream_play_flv_screen | pass | pass | pass | pass |
| avm1/native_objects_swf6 | output_mismatch 114/115 | output_mismatch 114/115 | same | same |
| avm1/native_objects_swf7 / swf8 | pass 115/115 | pass 115/115 | pass | pass |
| avm1/globals_monkeypatch | output_mismatch 157/306 | output_mismatch 157/306 | same | same |
| avm1/place_and_lookup | pass 30/30 | pass 30/30 | pass | pass |
| avm1/clone_sprite_types | pass 24/24 | pass 24/24 | pass | pass |
| visual/video/{colorconversion/h263,vp6,vp6a; vp6_inter_frames; vp6_alphaoffset; deblocking; vp6_dispsize} (AVM1) | pass | pass | pass | pass |

That is all 20 corpus SWFs that contain a DefineVideoStream (tag 60; full parse incl. sprites, over
avm1, from_gnash, visual, shumway, regression, timeline, swf, mixed_avm). Every one is AVM1.

Rows that mention Video/NetStream but place no video (graphics before → after, all unchanged):
- `asnative_instrument` ruffle_matched 42/173
- `global_instance_decls` output_mismatch 211/759
- `globals_swf5` output_mismatch 294/304
- `globals_swf6/7/8` pass 304/304
- `native_subclasses` pass 191/191
- `netstream_seek_flv` pass
- gnash `MovieClip-v6` ruffle_matched and `MovieClip-v8` output_mismatch, unchanged
- gnash `NetStream-v6/v8` pass 80/80
- gnash `Video-v5..v8` pass

`Video-v6/7/8` assert `!Video.prototype.hasOwnProperty("width")` after `new Video()`. That is exactly
the laziness, and they stay green.

## 3. Regression suite and canary

- **Regression suite** (graphics; chosen for MC member lookup, dynamic_props `__proto__`, MC
  accessors, modify-place and cross-version paths): all pass before and after, the same lines.
  - `avm1_display_prop_coercion` 36/36
  - `avm1_parent_child_modify_place` 5/5
  - `mc_event_type1_args`
  - `mc_resolve_type1_args`
  - `watch_mc_type1_args`
  - `mc_method_v5_caller_gate`
  - `avm1_attach_clipevent_enterframe`
  - `avm1_closure_method_scope`
  - `onconstruct_cross_swf_version`
  - The final leg re-ran them on the final code: see §8.
- **Render canary**, standing `render_canary_tests.txt` (96 tests / 151 PNGs, before vs after):
  **IDENTICAL 151, DIFFERS 0**, no trace or image status changes.
- **Video image rows**, a separate capture of `Video-EmbedSquareTest`, `netstream_play_flv(_screen)` and
  `visual/video/*` AVM1 (10 tests / 25 PNGs): **IDENTICAL 25**.
- The change only adds AS-visible properties and a size cache, and renderer inputs are untouched,
  so the standing canary set covers it. No canary member was added.

## 4. Refutations / premises attacked

- **"Getter on the current `_global.Video.prototype` via `g_stub_ctors[16]`"** was wrong as written.
  - The SWF7+ movie's `Video` is a constructor COPY (`createConstructorCopy`) with its own lazily
    created prototype.
  - Defining on `g_stub_ctors[16]->prototype_obj` put the accessors on an object that no script
    sees (measured: proto pointers differed).
  - The fix resolves through `getActiveGlobal()` + GetMember.
- **"Hook the timeline placement in BOTH tag.c (graphics) and the no-graphics path"**: there is one
  shared funnel, `ng_on_place_object2` in `tag_stubs.c`, compiled into both modes. One hook suffices.
- **Pricing of `video_width_height`**: the brief priced it on `_width`/`_height` plus the decoded size.
  There was also a hidden mode-parity trap: no libavcodec in no-graphics. Without the header probe it
  would have been a graphics-only pass and broken the standing per-test mode parity.
- **Globals timing**: frame 1 places the Video before the first script runs. With lazy
  `ensureGlobalInit`, `_global.Video` did not exist yet, so the placement hook calls it.

## 5. HOLDs (not finished), each with its completion mechanism

1. **`avm1/video_prototype_lazy` row 18** (`Video.prototype = [1,2]`).
   - An ARRAY-typed prototype is stored as `own_props["prototype"]`, not `prototype_obj`.
   - Named accessors on an `ASArray`, and an ARRAY `__proto__` on a clip, are not supported by the
     dynamic_props walk.
   - Mechanism: let `actionOnVideoPlaced` accept ARRAY protos. That needs `ASArray` named-property
     accessor support in `setAddPropertyWithFlags`, plus the MC getter walk at action.c ~57480
     accepting ARRAY links. M, and it touches shared Array code.
   - This is the last line: it would flip the test.
2. **`avm1/video_prototype_lazy_swf6_child` rows 4-7** (child movie's Video).
   - The loaded child records its DefineVideoStream (char 1001) but its timeline placements
     (`this.gotoAndStop(2)` in the child) **never reach `ng_on_place_object2`**. Instrumented: only the
     parent's 4 placement callbacks fire.
   - So the child's Video gets no wrapper, no accessors and no `__proto__`.
   - Row 7 then also differs, because R was never recorded by the child.
   - Mechanism: find the loaded-child timeline placement path (the per-level display list driven by
     `g_level_advance`, action.c ~25470) and route it through `ng_on_place_object2`, or call
     `actionOnVideoPlaced` there with the child's `g_swf_version`. Then `getActiveGlobal()` picks the
     SWF6 `_global`, since the separate-Video-class row already passes. M.
3. **Videos nested in sprites** (not exercised by any corpus row).
   - The wrapper parent is `g_current_context`, the same convention the TextField eager-create uses.
     It is unverified for a Video inside a DefineSprite.

## 6. Fixture decision

No `regression/` fixture was added:
- The rule asks for one only when a behaviour has no corpus test.
- All four headline behaviours (lazy define, once-per-proto, `__proto__` capture, decoded size and
  bounds) are pinned by Flash-generated corpus outputs.
- No oracle outside SWFRecomp is available in the cloud.

## 7. New unclaimed leads

- **`smoothing` / `deblocking` on the Video prototype** (Flash defines them in the same lazy batch;
  `video_prototype_lazy`'s comment says so).
  - `NetStream-SquareTest` lines 38-39 and 88-89 are Flash PASSED and Ruffle FAILED.
  - Adding them moves 4 more lines toward Flash, but does not flip the test (other lines remain).
  - Their value semantics are unverified, hence not done. S.
- **Embedded (SWF-stream) Video decoded size.** Ruffle's `decoded_size()` also covers
  `VideoSource::Swf` (the last decoded embedded frame). Our getter returns 0 for DefineVideoStream +
  VideoFrame clips. No corpus row reads it today (Video-EmbedSquareTest stays 2/2).
- **No-graphics libavcodec.** The parity probe covers Sorenson H.263 only. A VP6/H.264 NetStream
  `width` read would still differ by mode. A cleaner fix is linking libavcodec in no-graphics
  (`verify_output.py` :2979, plus the CI no-graphics apt set). Out of scope here.

## LOCAL ORACLE REQUESTS

none

## 8. Final-leg confirmation (final code = the patch)

The final code adds the H.263 parity probe and the attachVideo/VERSION_6 alignment. On it, the final
leg re-ran the following, and every number in §2/§3 is from this leg:
- the 20 DefineVideoStream rows in both modes;
- the 9 regression rows (graphics);
- both canary captures.

Results:
- Trace: identical to the §2 table. `NetStream-SquareTest` is ruffle_matched 166/216 and
  `video_width_height` is pass 19/19 in **both** modes.
- Regression: 9/9 pass, unchanged.
- Canary: `before` vs `final` IDENTICAL 151/151; video rows `vbefore` vs `vfinal` IDENTICAL 25/25;
  no trace or image status changes in either.

The 16 non-placing Video/NetStream rows in §2 were measured on the pre-probe patch. The probe only
runs inside `NetStream.play()` when no frame decoded, and only feeds the Video width/height getter,
which those rows never define. They cannot move.
