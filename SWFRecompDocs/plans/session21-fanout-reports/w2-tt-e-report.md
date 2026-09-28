# w2-tt-e — `from_gnash/misc-ming.all/NetStream-SquareTest` (session 21, wave 2)

**New files: none.** The patch touches only `SWFModernRuntime/src/actionmodern/action.c`.
Deliverables: `w2-tt-e.patch` and this report.

## Verdict: GO. +1 effective (`output_mismatch` → `ruffle_matched`)

| test | before (HEAD c61f6ebe5, graphics) | after (graphics) |
|---|---|---|
| `from_gnash/misc-ming.all/NetStream-SquareTest` (KF) | output_mismatch: 125 diff lines, 24 of them ours-only, not a subset of Ruffle's 108 | **RUFFLE_MATCHED**: 95 diff lines ⊆ Ruffle's 108, **0 ours-only** |

This is a KF test, so the fix direction matters. Every one of the 30 lines that changed moved onto Flash's
`output.txt`, and no line moved away from it. The last two changed lines (195 and 197,
`bufferLength:2 bytesLoaded:21482 currentFps:0 time:0`) still differ from Flash (`bufferLength:2.273`).
They sit in the tail that is already misaligned, and Ruffle differs from Flash on both lines as well.

## Premise check (w1-trace-tail §7): confirmed, with one refinement

- **24 ours-only lines = 2 mechanisms.** Re-measured at HEAD with a line-index diff against
  `output.ruffle.txt`, the same algorithm as `ruffle_subset_match`. The ours-only lines are
  7, 8, 10, 11, 13-15, 54-64, 67-70, 125 and 126. **M1** (NetStream getter-only prototype
  accessors) covers 22 of them and **M2** (Video must not inherit MovieClip methods) covers 2.
- **Refinement, and a trap the brief did not name.** Porting Ruffle's `netstream.rs:37-41` as-is, with
  the getters always on `NetStream.prototype`, would **regress three passing KF tests**:
  `from_gnash/actionscript.all/NetStream-v6/-v7/-v8`.
  - `NetStream.as:58-75` asserts `!NetStream.prototype.hasOwnProperty('bufferLength')` (and the same for the
    other four) on an unconnected stream. Ruffle fails those lines.
  - Flash installs the properties **lazily**, the first time a NetStream is constructed with a
    connected NetConnection. The runtime already did this for `currentFps` at the `new` site.
  - The patch keeps that lazy site and installs all seven accessors there.
- Ruffle's `bufferTime == 2` after `setBufferTime(10)` is not a "can't change once set" rule.
  `stream.setBufferTime = 30` shadows the method with an own property, so the later calls do nothing.
  Our write-to-instance semantics already produce the same result. No special case was needed.

## Mechanism and patch scope (`action.c` only, all new symbols `static`)

1. **M1: NetStream native properties.** New code sits just above `initNetStreamPrototype`.
   - `nsInstallNativeProps()` installs getter-only accessors through the existing `setAddProperty`, with
     no setter, so a write through an instance is ignored by the SetMember accessor arm. The seven
     properties are `currentFps`, `bufferLength`, `bufferTime`, `liveDelay`, `time`, `bytesLoaded` and
     `bytesTotal`.
     - `bufferTime` and `bufferLength` return the native `buffer_time`, default 0.1. `bufferLength` is a
       Ruffle stub that also returns `buffer_time`.
     - `bytesLoaded` and `bytesTotal` return the FLV byte length of the active stream, or 0 when there
       is none.
     - `time` returns the elapsed playback time while playing, otherwise 0.
     - `currentFps` and `liveDelay` return 0. Flash has both; Ruffle has neither.
     - Every getter returns `undefined` unless `this` has `NetStream.prototype` on its chain. This matches
       Ruffle's `NativeObject::NetStream` gate.
   - The `new NetStream(connected nc)` hook replaces its old block, which installed `currentFps` as a
     plain `undefined` value, with a call to `nsInstallNativeProps`. The gate itself is unchanged.
   - `setBufferTime` is no longer a stub. `builtin_ns_setBufferTime` follows Ruffle's
     `set_buffer_time`: it coerces argument 0 to a number and stores it. The value lives in a small
     side table, `g_ns_native_states[32]`, which is retained and GC-marked beside `g_active_netstreams`,
     using the same "entries never reclaimed" lifetime policy.
   - `ActiveNetStream` gains a **trailing** field, `bytes_total`, which `builtin_ns_play` fills in.
2. **M2: timeline Video prototype.** In the GetMember MOVIECLIP arm's final fallback (the
   `!_mc_explicit_proto` block), a clip whose `display_obj->char_id` is a DefineVideoStream character
   (`ng_isVideoChar`) now walks `Video.prototype` instead of `MovieClip.prototype`.
   - `typeof(video.hitTest)` and `typeof(video.getBounds)` are now `undefined`.
   - The new helpers are `mcIsTimelineVideo` and `videoPrototypeForMc`, placed above
     `getMovieClipPrototype`.
   - Only the value-lookup fallback changes. The CallMethod arm is untouched, so `vid.clear()` still
     dispatches (`Video-EmbedSquareTest` still passes).
   - In the browser build the video registry (`ng_record_video`) is not populated, so M2 is inert there.

**Sibling overlap:** none.
- w2-removed-scope owns scope-chain resolution at about lines 45125-45220. This patch's hunks are in
  the NetStream block (about 3100 and 39800-40000), the MOVIECLIP GetMember tail (about 57700) and the
  GC mark list (about 79950).
- w2-tt-d works on MovieClip-v6/v7. M2 changes MC GetMember only for Video characters.

## Canary (graphics, sequential, `--recompile` on each copied dir): 18 of 18 unchanged

Each row below has the same status as in the baseline `results_graphics.json`.

- **KF, pass → pass, so there is no pass→ruffle_matched risk:** `from_gnash/actionscript.all/NetStream-v6`,
  `-v7`, `-v8`, `Video-v5`, `-v6`, `-v7` and `-v8`.
- **Non-KF, pass → pass:** `NetStream-v5`; `from_gnash/misc-ming.all/Video-EmbedSquareTest`;
  `avm1/netstream_play_flv`, `netstream_play_flv_screen` and `netstream_seek_flv`; `from_shumway/acid/acid-video`.
- **`regression` suite, pass → pass:** `nc_onstatus_closure`, `nc_onstatus_type1_args`, `mc_method_v5_caller_gate`,
  `mc_resolve_type1_args` and `avm1_display_prop_coercion`. The last three cover the MC GetMember path.
- **Image comparisons were not moved.** The failing comparisons are byte-identical to the baseline and
  already dispositioned:
  - `Video-EmbedSquareTest`: 186 outliers, max 255, equal to `image_results_graphics.json`.
  - `netstream_play_flv`: 44 outliers, max 3 (ACCEPTED_DIFFS).
  - `netstream_play_flv_screen`: blank_render (RVF).
  - `acid-video`: all 3 comparisons still pass.
- **CI:** `mode=graphics categories=all` is enough. Nothing here is no-graphics-only, and nothing touches
  AVM2.

## New unclaimed leads

- **NetStream-SquareTest tail (lines 139-216).** Our output is 15 lines short. We fire
  `onStatus(Buffer.Full)` and `onMetaData` before the "press p" / "space" interaction and never replay
  the `Seek.Complete`/`Play.Stop` sequence. Our `onMetaData` object also carries only 4 of the 11
  fields and is not `instanceof Array`. Ruffle fails this whole region too, so it is correctness-only
  (0 flips).
- **Video.prototype `smoothing`/`deblocking`/`height`/`width` and `video.height/width == 0`**
  (lines 38-53 and 83-92). Both Ruffle and we fail these lines, so they also cannot flip anything.
