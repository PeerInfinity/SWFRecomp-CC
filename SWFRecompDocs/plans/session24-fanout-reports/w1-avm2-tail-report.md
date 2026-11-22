# s24 wave 1: `w1-avm2-tail` (AVM2 trace tail): diagnosis + measured prototypes

**NEW files**
- `SWFRecompDocs/plans/session24-fanout-reports/w1-avm2-tail-report.md` (this report)
- `SWFRecompDocs/plans/session24-fanout-reports/w1-avm2-tail-prototype.patch`: all five landable prototypes combined, 827 lines. It applies on `origin/master` @ `df126b80`. Source was reverted afterwards.

**Box and baseline.** Cloud box, `SETUP_STATUS` all OK (apt, Pillow, Dawn on lavapipe). Upstream tests: `download_tests.sh avm2 from_avmplus mixed_avm audio` took Ruffle master **`bcac30c19`**, the same SHA as the s24 baseline. Ruffle source: blobless clone, also at `bcac30c19`.

**Local runs are CI-grade for trace.** I ran every brief row once in graphics mode, clean. All 22 matched the s24 baseline `results_graphics.json` (run `44965247383`) exactly: same status, same `actual` / `expected` / `matching` line counts.

---

## 0. Verdicts and priced flips

### 0.1 Measured flips

All counts below are measured with the prototype, not inferred from diff lines.

| # | Lead | Verdict | Rows (before → after, graphics) | NG parity | Size |
|---|---|---|---|---|---|
| L1 | NetStream status-event state machine + `NetStream.time` | **GO** | `avm2/netstream_play_flv` 0/16 → **pass**; `avm2/netstream_play_stop_replay` 1/11 → **pass**; `avm2/netstream_seek_flv` 0/49 → **pass** | all 3 pass in no-graphics too (were mismatch in both modes) | S–M, ~150 lines, `avm2_net.c` only |
| L2a | `with_audio` harness: simulated embedded-sound clock + finished-channel position = sound length | **GO** | `avm2/soundchannel_position_after_end` 2/6 → **pass** (new upstream row `bcac30c19`) | pass in NG | S, `avm2_media.c` + 4 lines of `verify_output.py` |
| L2b | `with_audio` harness mixer tap feeding `computeSpectrum` | **GO** (graphics only) | `avm2/audio_computespectrum` 0/118 → **pass** | NG stays fail: no mixer there. Same documented gap as `audio/aac` | S, ~60 lines, `avm2_media.c` + `avm2_net.c` |
| L3 | Primitive-receiver bound-method cache (avmplus atom identity) | **GO** | `avm2/weird_number_bound_methods` (kf) 9/12 → **pass**; `avm2/primitive_bound_methods` (kf) 5/11 → **ruffle_matched** | pass / ruffle_matched in NG | S, ~50 lines, `avm2_ops.c` + 1 line `avm2_gc.c` |
| L4 | DefineFont4 (tag 91) OS/2 typo metrics → `TextLine.ascent/descent` | **GO** | `avm2/textline_metrics` 0/20 → **pass** | not run in NG (no mode-specific code) | S–M, recompiler `abc_timeline.cpp` + `avm2_text.c`. Needs DYNAMIC_HOST wiring for WASM (§4) |
| L5 | `flash.system.Worker` / `WorkerDomain` state machine | **GO** | `avm2/worker_terminate` 1/56 → **pass** | pass in NG | S, ~140 lines, `avm2_globals.c` |
| L6 | `bitmapdata_encode` trace side | **GO, contingent** on `w1-pixel-bitmap`'s JPEG encoder | `avm2/bitmapdata_encode` 26/147 → **pass 147/147** with a structural JPEG *stub* plus 3 small non-encoder hunks (§6) | — | the 3 hunks ≈ 40 lines in `avm2_bitmap.c` |

**Total: +9 effective rows (8 pass + 1 ruffle_matched) in graphics, plus +1 contingent (L6).**
- Combined check: all five landable prototypes applied together reproduce every flip above, with no interaction (22-row run, `--recompile`, §7).
- Rider sweeps: 0 status or line-count moves outside the ledger (§7).
- One pixel row moves inside tolerance (§1).

### 0.2 Ignore-list prune obligation

`avm2/ignored_tests.txt` lists `audio_computespectrum`, `netstream_play_flv`, `netstream_play_stop_replay` and `netstream_seek_flv`.
- The file's 2026-08-01 criterion is "prune on `pass`", so the wave-2 slot must delete those four entries.
- Keep `soundchannel_position` and `soundchannel_soundcomplete`. They stay ruffle_matched, unchanged.
- `primitive_bound_methods` / `weird_number_bound_methods` are not listed anywhere.

### 0.3 Triage of the rest: standing NO-GO / ACCEPTED, shape re-confirmed (one run each, identical to baseline)

| Row | Class | Entry of record | Recorded shape | Now |
|---|---|---|---|---|
| `avm2/verify_method_info_duplicate` | (a) ACCEPTED | ACCEPTED_DIFFS Cat. 2; avm2 `ignored_tests.txt` | 1/2, missing trailing `#1065` | same. Attack failed: `#1121` and `#1027` come out of the same avmplus `parseMethodBodies` loop, so there is still no principled discriminator |
| `avm2/dependent_strings` | (a) RvF | `ruffle::isDependent()` Ruffle-internal hook | boolean rows blank | same (46/84) |
| `avm2/avm1_root` (kf) | (a) RvF | RUFFLE_VS_FLASH "temporal attachment state"; s20 measurement | 12/58 | same 12/58. Do not build a third gate |
| `avm2/bom`, `avm2/loader_load` | (a) RvF | hashbrown enumeration order | 6/9, 126/128 | same |
| `avm2/swz`, `avm2/loader_applicationDomain` | (a) ACCEPTED | Cat. 13 (Flex framework `.swz` under AOT) | 0/2, 0/4 | same |
| `avm2/number_tostring` | (a) ACCEPTED | Cat. 14 (corrupt Flash capture, upstream `ignore = true`) | 168 diff lines | same 168 |
| `from_avmplus/ecma3/Statements/eforin_001` / `_002` | (a) ACCEPTED | Cat. 12 (implementation-defined for-in order) | 12/16, 0/10 | same |
| `avm2/sandbox_type_remote` | (b) harness-limited | `ignored_tests.txt` s22 entry (localhost child-movie mapping + per-movie sandbox type) | 1/3 | same |
| `mixed_avm/avm1_loads_avm2` | (a) NO-GO of record | s22 `w1-crossvm` §4.3 (AVM1-parent → AVM2-child build arc) | 3/7 | same |

---

## 1. L1: NetStream status events (GO, +3, both modes)

**Premise refuted.** The `avm2/ignored_tests.txt` bucket says these three "do need real playback state **and a decoder** (bucket M)". The decoder landed in s23 (`w2-netstream-audio`, Spark IDCT): both image checks already pass on the baseline. What was missing is only:
- the NetStream **status-event state machine**;
- `NetStream.time`.

`netstream_seek_flv`'s timeline loops frame 2 ↔ 3 `while (ns.time === 0)`. Our `time` getter was `ns_get_zero` (`avm2_net.c:2683`), so its seek, pause and seek frames never ran.

**Mechanism.** This is a port of Ruffle `core/src/streams.rs` (`bcac30c19`) onto the existing tick (`avm2_net.c:2442` `ns_video_tick_one`):

| Ruffle | Prototype |
|---|---|
| `play()` (streams.rs:593) fires `Play.Start` synchronously | `ns_play` dispatches it after `ns_video_start`. A `gen` counter is bumped per play() and stands in for "source replaced" |
| `load_buffer` (:394) fires `Buffer.Full` | fired on the existing "bytes arrived" first tick (`v->loaded`), before the onMetaData drain. This gives the order `Play.Start`, `Buffer.Full`, `onMetaData` |
| tick buffer underrun (:1292): a non-lookahead EOF fires `Buffer.Flush`, then `Play.Stop`, then (only if the handler did not call play()) `Buffer.Empty` + pause | same; `last_lookahead` mirrors `is_lookahead_tag` |
| `seek()` (:441): queue the seek and fire `SeekStart.Notify` "Start Seeking <ms>"; tick: `execute_seek` → `Seek.Notify`, reposition to keyframe, `Seek.Complete` "Seek Complete -1" (AVM2) | same. The reposition scans the bundled bytes for the keyframe at/before (backward) or at/after (forward) the offset. A no-op seek is skipped |
| `pause()` → `Pause.Notify` "Pausing"; a paused stream still executes its queued seek, then idles | same; `resume` / `togglePause` flip `playing` |
| `NetStream.time` = `stream_time / 1000` | `ns_get_time_proto` |

The new state lives in trailing fields of the file-static `NsVideoStream`. Events go through the existing `avm2_net_status_event_new`.

**Evidence.**
- `netstream_play_flv` 16/16, `netstream_play_stop_replay` 11/11, `netstream_seek_flv` 49/49, in graphics and no-graphics.
- The replay row shows the subtle part: the first cycle's `Buffer.Empty` is suppressed because the `Play.Stop` handler replays.

**Pixel note (coordinator).** Both rows render the same NetStream video.
- `netstream_play_flv`: image identical (0 outliers, max 0).
- `netstream_seek_flv`: still **pass**. 27 outliers / 271 as before, but **max_diff 156 → 146**: the seeks now really reposition the video, so the final frame changed. Expect an md5 delta on this one image (and on any canary member that plays a seeking NetStream; the standing `visual/video/h264_multinalu` does not seek).

**Sweep: 17 rows, all unchanged.** Every `avm2/netstream*`, `net_stream*`, `netconnection*` and `flash_media_video_*` row, every `audio/*` row, and every `.as` that mentions NetStream in avm2/audio/mixed_avm/from_avmplus. Included: `audio/aac`, `audio/g711` (the s23 mixer-clock alignment rows), `netstream_flv_date`, `netstream_client`, `netstream_connect`, `net_stream_play_options`.

Regression suite: `regression/avm2_sound_bytes_and_group_format` passes.

## 2. L2: the `with_audio` harness (GO, +2 graphics / +1 no-graphics)

**Mechanism.** `test.toml [player_options] with_audio = true` makes Ruffle's test framework use `TestAudioBackend`, a real mixer ticked `round(2·44100/fps)/2` frames per tick (s23 report §2). Without it, Ruffle uses the null backend. `verify_output.py` ignored the key.

In our native harness nothing pulls `audio_mix`, so an embedded-sound channel never drains:
- `sc_get_position` returns 0 (`avm2_media.c:305`, "trace-inert" comment);
- soundComplete never fires;
- `computeSpectrum` sees only the NetStream tap (`avm2_media.c:425`, "embedded / Sound-object channels are not tapped yet").

**Prototype.**
1. `verify_output.py` adds `-DSWF_HARNESS_WITH_AUDIO=1` when the toml sets `with_audio = true`. That is 11 rows corpus-wide in these categories; only these 11 take a ccache miss.
2. **L2a (both builds).** Under the define, an embedded Sound whose mixer start did not succeed joins the existing URL-sound simulated clock (`media_poll_simulated`, `avm2_media.c:1265`). It plays max(loops,1) passes of start..length.
   - On drain, via either the sim or the mixer path, the channel's position becomes the **sound's own length**.
   - That is Ruffle `bcac30c19` (`audio.rs`: `object.set_position(duration)`). The new `sim_done` / `sim_final_ms` fields hold it.
   - `stop()` keeps today's behaviour, so "stopped before reading" stays 0.
3. **L2b (graphics only).** `ns_video_tick` already advances the shared mixer clock `g_ns_mix_frames` once per tick (`avm2_net.c:2487`). Under the define it now also calls `avm2_media_harness_mix(clock, nframes)`.
   - That function runs the real `audio_mix` (minimp3-decoded embedded MP3) into a ring keyed by absolute clock frame.
   - `avm2_net_netstream_audio_window` sums that ring into the same last-complete-1024-block window.
   - The embedded channels then drain through the real mixer, so `soundComplete` uses the existing mixer path.

**Refutations.**
- s23 priced `audio_computespectrum` as **M** ("needs a Sound-object mix tap: decode + per-channel start + summing"). It is S: the mixer we already ship does all three; it only needed pulling on the clock that already exists.
- **"Simulate embedded sounds in every harness test" is a regression trap.** I measured it with the define forced on for all tests:
  - `avm2/soundchannel_position` went **ruffle_matched → fail** (66 → 74 lines, still no pass: `output.txt` carries 2 Flash-launcher header lines, so the ceiling is 138/140).
  - `soundchannel_soundcomplete` stays ruffle_matched (6 → 11 lines).
  - The `with_audio` gate is exactly Ruffle's backend selection, so neither row moves.

**Sweep: 30 rows, only the 2 ledger rows move.**
- All 11 `with_audio` rows and all 16 `avm2/sound*` rows: `soundchannel_position`/`_soundcomplete` stay ruffle_matched; `sound_play`, `sound_rootless`, `sound_load_multiple` and `soundchannel_stop` stay pass.
- The NetStream rows: both images md5-equal to before.
- No-graphics: `soundchannel_position_after_end` pass, `sound_play` / `soundchannel_stop` / `g711` pass, `audio_computespectrum` fail (expected), `audio/aac` fail (pre-existing NG gap).

**Fragility (stated plainly).** `audio_computespectrum` reads DC segments, so window alignment barely matters. It passed first time.

## 3. L3: primitive bound-method cache (GO, +1 pass, +1 ruffle_matched)

**Mechanism.** `bind_method_entry` (`avm2_ops.c:521`) caches a bound closure only for OBJECT receivers. A method read off a primitive mints a fresh closure every time.

avmplus caches per method keyed by receiver **atom**, which gives these identities:
- An int-valued double (not −0) is an int atom, so `(0.0).f === (0).f`.
- Any other double (−0, NaN) is a fresh box per read, so it never matches.
- A String atom is its pointer: interned literals share, a concat result does not.
- Booleans compare by value.

The prototype adds a 1024-slot direct-mapped side cache keyed by (prop entry, atom kind, atom key), GC-rooted through a one-line hook in `avm2_gc.c`.

**Flips.**
- `weird_number_bound_methods`: 12/12 **Flash pass**. The Ruffle sidecar is reachable but worse: Ruffle keys Numbers by bits, so it says −0 and NaN share.
- `primitive_bound_methods`: **ruffle_matched**, 10/11 against Flash. Flash's line 2, `("ab"+"c").toString === ("ab"+"c").toString` → `true`, is unexplained by any atom model consistent with line 1 (`false`). A Flash pass would need that mystery reverse-engineered first.
- Both rows are `known_failure`, and both move fail → effective, so neither is a hidden regression.
- Wave 2 should add `primitive_bound_methods` to `RUFFLE_COMPAT_TWEAKS.md` (pointer-equal strings follow Ruffle `ValueKey`).

**Sweep: 35 rows, 0 moves.** All 8 `.as` files that read a method off a literal or primitive; MethodClosure ×2; `error_throwerror`; `Error1004`; Boolean `ecma4_*` ×10; Number ×8; String `e15_5_4_2*/3*` ×6; Array ×4; Dictionary ×2; `e4x/Types/e9_1_1_1`.

## 4. L4: `textline_metrics` (GO, +1; s23 §4.2 confirmed, now prototyped)

**Recorded shape holds.**
- Ours: constant 12/3 (`avm2_text.c:7448` `tl_const_12` / `tl_const_3`).
- Flash: size × OS/2 sTypoAscender / unitsPerEm (800/−200 @ 1000, i.e. 8/2, 16/4, 32/8).

**Prototype.**
- Recompiler: `case TAG_DEFINE_FONT4` (91) in `abc_timeline.cpp` (beside DefineFont2/3, ≈1440) reads the name and flags, then walks the OpenType table directory for the `OS/2` typo ascender/descender and the `head` unitsPerEm. The main movie emits `avm2_generated_cff4_fonts[]` and a count.
- Runtime: the TextLine `ascent` / `totalAscent` / `descent` / `totalDescent` getters resolve `textBlock.content.elementFormat`. On `fontLookup == "embeddedCFF"` plus a name match, they return size·typo/upem rounded to twips. Anything else falls back to 12/3.

**Wave-2 work the prototype skips.**
- The runtime reads the table through **weak symbols** under `#if !defined(DYNAMIC_HOST)`, so the WASM bundle silently keeps 12/3.
- The proper fix adds the table to `avm2_abc.h`'s two extern blocks and to the DYNAMIC_HOST loader, like `avm2_generated_device_fonts`.
- Optional: wire bold/italic into the name match.

**Sweep: 26 rows, `--recompile`, 0 moves.** Every SWF in avm2/mixed_avm containing tag 91 (`font_enumeratefonts`, `textline_atom_index_at_char_index` (rm), `textline_splitting_basic`, `textline_validity`), every `textline_*` / `textblock_*` / `font_*` row, `loader_load` (child-movie tables) and `mixed_avm/avm1_loads_avm2`. No other corpus row reads TextLine ascent or descent.

## 5. L5: `worker_terminate` (GO, +1)

**Mechanism.** `flash.system.Worker` / `WorkerDomain` are abstract stub bags (`avm2_globals.c:7411`), so `Worker.current` is null and the test dies at #1009.

**Prototype.** A port of Ruffle `object/worker_object.rs`, `globals/flash/system/worker.rs` and `worker_domain.rs` (`bcac30c19`):
- a primordial singleton (`isPrimordial`, state `running`);
- `WorkerDomain.current.createWorker(swf)`: #2007 on null;
- `start()`: #1511 if primordial or already started;
- `terminate()`: #3732 on primordial; false unless started and not terminated;
- `pending_worker_updates` drained once per tick: New → Running on start, one `workerState` event per announced change. Workers queued by handlers wait for the next drain (Ruffle `update_pending_workers`).

Both classes keep their script-`new` gate (`stub_native_init_abstract_script_only`). The native frame names (`at flash.system::Worker/terminate()`) come free from the existing native-call frames.
- For the prototype, the drain is called from the top of `avm2_media_poll`, in both builds.
- Wave 2 should give it its own call beside `avm2_media_poll` in `avm2_main.c` (≈794, ≈887).

**Refutation of s23's "medium-large, HOLD".** It is about 140 self-contained lines.

**Sweep.** No other corpus `.as` names Worker or MessageChannel, apart from `from_avmplus/ecma3/Expressions/instanceof_002`. That row, `abstract_classes` and `sound_play` all stay pass. With an empty queue the drain is a no-op, so nothing else can move. NG: pass.

## 6. L6: `bitmapdata_encode` trace side (GO, contingent; coordinate with `w1-pixel-bitmap`)

**What the trace row actually needs.**
- `describeJpeg` checks **structure only**: `SOI`, a SOF segment (len 17, precision 8, w, h, 3 components) and `EOI present`. Any real baseline encoder satisfies it.
- Today we emit nothing for JPEG, so `readUnsignedByte` throws #2030 and aborts the rest of the test at line 27.

**Measurement.** I replaced the JPEG body with a 23-byte **stub** (SOI, SOF0, EOI). This is NOT a JPEG and must not land. With it plus the three hunks below, the row **passes 147/147**. So after the sibling's encoder, these hunks are the whole remaining trace delta. They are independent of the encoder and live in `bd_encode` (`avm2_bitmap.c:3476`):

1. **Argument order, from Ruffle `bitmap_data.rs:1607`.** Each check is listed with the error it raises:
   1. disposed → #2015 (already there)
   2. null rect → TypeError #2007
   3. null compressor → TypeError #2007
   4. rect non-positive or clamped-empty → #2006 (already there)
   5. compressor class: JPEG / PNG / JPEGXR (returns null) / other → ArgumentError #2004
   6. JPEG `quality > 100` → **RangeError** #2006
   7. JPEG region > 65500 → Error #3699

   The test's "Error precedence" block grades exactly this order.
2. **`JPEGEncoderOptions` has no constructor.** It is an `avm2_builtin_class_api` shell (`avm2_bitmap.c:4120`), so `new JPEGEncoderOptions(101).quality` was never stored. It needs `quality:uint` with default 80 (`JPEGEncoderOptions.as`).
3. **PNG colour type.** Flash writes **RGB (type 2) when every pixel in the region is opaque**, even for a transparent BitmapData. Ours keys on `bd->transparency`. This costs 2 lines (`// PNG color type`).
   - The decoded pixels are unchanged: `bitmapdata_encode_png_visual` keeps image pass, and `bitmapdata_encode_png_roundtrip` stays pass.

**Sweep: 4 rows.** `bitmapdata_encode_png_visual` (trace + image pass), `_png_roundtrip`, `_jpeg_visual` (trace pass; its image fails with the stub, as expected; that is the sibling's), and `bitmapdata_colortransform`.

**Handoff.** The measurement diff is reproduced below so the JPEG slot can take hunks 1–3 and drop the stub block.

```diff
--- a/SWFModernRuntime/src/avm2/avm2_bitmap.c   (measurement only; drop the "STUB bytes" block)
+static Avm2Value jpeg_opts_ctor(Avm2Activation* act)
+{
+	uint32_t* q = (uint32_t*) act->this_val.u.obj->native_ext;
+	q[0] = act->argc > 0 ? avm2_coerce_to_u32(act->ctx, act->args[0]) : 80;
+	return avm2_undefined();
+}
+/* + jpeg_opts_get_quality / jpeg_opts_set_quality over native_ext[0] */
 static Avm2Value bd_encode(Avm2Activation* act)
 ...
+	if (arg(act, 0).kind != AVM2_VALUE_OBJECT)  -> TypeError "#2007: Parameter rect must be non-null."
 	rect_to_xywh(ctx, arg(act, 0), &rx, &ry, &rw, &rh);
+	if (arg(act, 1).kind != AVM2_VALUE_OBJECT)  -> TypeError "#2007: Parameter compressor must be non-null."
 ...
-	uint32_t nch = bd->transparency ? 4 : 3;
+	uint32_t nch = 3;   /* 4 only if some pixel in the region has alpha != 0xFF */
 ...
+	JPEGEncoderOptions: q = quality; q > 100 -> RangeError #2006; w|h > 65500 -> Error #3699; <encoder>
+	JPEGXREncoderOptions -> return null
+	not PNG -> ArgumentError "#2004: One of the parameters is invalid."
 ...
+	jpg->instance_init.fn = jpeg_opts_ctor; jpg->native_ext_size = 8;
+	avm2_builtin_add_getset(ctx, jpg, "quality", jpeg_opts_get_quality, jpeg_opts_set_quality);
```

## 7. Combined prototype check and rider-sweep summary

All five landable prototypes (L1, L2, L3, L4, L5) are in `w1-avm2-tail-prototype.patch`. Applied together, with `--recompile` and in graphics mode, 22 rows reproduce every ledger flip and no other move:
- the 9 headline rows (plus `abstract_classes`);
- riders `audio/aac`, `audio/g711`, `soundchannel_position` (rm), `soundchannel_soundcomplete` (rm), `sound_play`, `soundchannel_stop`, `netstream_flv_date`, `textline_validity`, `textline_splitting_basic`, `MethodClosure`, `regression/avm2_sound_bytes_and_group_format`, `mixed_avm/avm1_loads_avm2`;
- images: `netstream_play_flv` 0/0; `netstream_seek_flv` 27/271, max 146.

| Lead | Rider rows (argued scope) | Moves outside ledger |
|---|---|---|
| L1 NetStream | 17 | 0 |
| L2 sound | 30 | 0 |
| L3 bound methods | 35 | 0 |
| L4 DefineFont4 | 26 (`--recompile`) | 0 |
| L5 Worker | 3 + target, both modes | 0 |
| L6 encode | 4 | 0 (stub's own `jpeg_visual` image, expected) |

## 8. Proposed wave-2 slots

| Slot | Scope | Expected ledger | Files | CI |
|---|---|---|---|---|
| **W2-a `w2-avm2-netstream-sound`** | L1 + L2. One slot, because both touch `ns_video_tick` and the brief reserves AVM2 sound/netstream for one owner. Prune the 4 ignore entries. | trace +5 graphics: `netstream_play_flv`, `netstream_play_stop_replay`, `netstream_seek_flv`, `soundchannel_position_after_end`, `audio_computespectrum`. NG: +4 (all but `audio_computespectrum`). Pixel: `netstream_seek_flv` stays pass with an expected md5 change (max 156 → 146) | `avm2_net.c`, `avm2_media.c`, `avm2_globals.h`, `verify_output.py` | graphics `categories=full` (audio is in the misc group). Add the NG leg, since `verify_output.py` and both-build code change |
| **W2-b `w2-avm2-small-natives`** | L3 + L4 + L5. Add `primitive_bound_methods` to RUFFLE_COMPAT_TWEAKS; wire DYNAMIC_HOST for the cff4 table; give the Worker drain its own `avm2_main.c` call | trace +3 pass, +1 ruffle_matched: `weird_number_bound_methods`, `textline_metrics`, `worker_terminate` pass; `primitive_bound_methods` rm | `avm2_ops.c`, `avm2_gc.c`, `avm2_text.c`, `avm2_globals.c`, `avm2_abc.h` + DYNAMIC_HOST host, `SWFRecomp/src/abc/abc_timeline.cpp` (`--recompile`) | graphics `categories=full` (AVM2 runtime + recompiler) |
| (handoff) **JPEG encoder slot** | L6 hunks 1–3 alongside `w1-pixel-bitmap`'s encoder | trace +1 `bitmapdata_encode` (+ that slot's pixel rows) | `avm2_bitmap.c` | — |

**Regression fixtures.**
- L1 and L5 are fully covered by Flash-captured corpus rows.
- L3 is covered by its two rows.
- L4 is covered by `textline_metrics`.
- No new fixture is strictly needed. A pause/resume/togglePause NetStream fixture would need an outside oracle (see requests).

## New unclaimed leads

1. **`NetStream.resume()` / `togglePause()` notify events.** The prototype flips `playing` only. Ruffle `resume` dispatches `Unpause.Notify` from the AVM-side native, not `streams.rs`; check `net_stream.rs` before wave 2. No corpus row reads them.
2. **No-graphics `audio_computespectrum` parity:** the same recipe as s23 §5 for `audio/aac` (an audio-only libavcodec / minimp3 mixer in NG). Graphics-only otherwise.
3. **`primitive_bound_methods` Flash line 2**, `("ab"+"c")` twice sharing one closure. Possibly avmplus concat-string caching; needs an avmplus source read (`MethodEnv` / `MethodClosure` cache) before anyone tries the pass.
4. **`NS_MAX_VIDEO_STREAMS` slots never freed:** pre-existing (s23 §6); unchanged.

## LOCAL ORACLE REQUESTS

None blocking. Optional, only to back a NetStream pause/resume regression fixture in wave 2: a Ruffle exporter trace of `ruffle-tests/tests/swfs/avm2/netstream_seek_flv/test.swf`, modified to call `ns.resume()` then `ns.togglePause()` on frames 6–7 and trace every netStatus code.
