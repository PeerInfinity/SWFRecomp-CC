# s24 wave 2: `w2-avm2-netstream-sound`: w1-avm2-tail L1 + L2, landable

**NEW files**
- `SWFRecompDocs/plans/session24-fanout-reports/w2-avm2-netstream-sound-report.md` (this report)
- `SWFRecompDocs/plans/session24-fanout-reports/w2-avm2-netstream-sound.patch`: 454 lines, against `origin/master` @ `946a6b115`. It is `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt ruffle-tests/tests/swfs/avm2/ignored_tests.txt`.
  - The ignore-list path is added on purpose: the prune (brief item 3) has to land with the code.
  - `git apply --check -R` passes on the branch tip.
- No new source files and no new fixtures. `render_canary_tests.txt` is unchanged (see §4).

**Box.** Cloud box. `SETUP_STATUS` all OK (Dawn on lavapipe). `download_tests.sh avm2 audio mixed_avm visual` took upstream Ruffle master **`bcac30c19`**, the same SHA as the s24 baseline. Ruffle source is a blobless clone at `bcac30c19`.

## 0. Verdict: GO, landable. Every ledger flip measured, 0 moves outside the ledger

### EXPECTED-FLIP LEDGER (check CI against this)

| Axis | Test | Before | After |
|---|---|---|---|
| trace, graphics + NG | `avm2/netstream_play_flv` | output_mismatch 0/16 | **pass** 16/16 |
| trace, graphics + NG | `avm2/netstream_play_stop_replay` | output_mismatch 1/11 | **pass** 11/11 |
| trace, graphics + NG | `avm2/netstream_seek_flv` | output_mismatch 0/49 | **pass** 49/49 |
| trace, graphics + NG | `avm2/soundchannel_position_after_end` | output_mismatch 2/6 | **pass** 6/6 |
| trace, **graphics only** | `avm2/audio_computespectrum` | output_mismatch 0/118 | **pass** 118/118 |
| trace, NG | `avm2/audio_computespectrum` | output_mismatch 0/118 | output_mismatch 0/118 (documented gap: no mixer in NG, like `audio/aac`) |
| pixel | `avm2/netstream_seek_flv` `output` | pass, max 156, 27 outliers (limit 271) | **pass**, max **146**, 27 outliers; md5 `d2d739eb…` → `68bfd336…` (expected) |
| pixel | `avm2/netstream_play_flv` `output` | pass, max 0 | pass, max 0, md5 identical |
| pixel | every other image row | — | no md5 move (see §4) |
| must NOT move | `avm2/soundchannel_position` / `avm2/soundchannel_soundcomplete` | ruffle_matched 66/140 and 6/16 | ruffle_matched 66/140 and 6/16, both modes |

Totals:
- Graphics trace: **+5 pass**.
- No-graphics trace: **+4 pass**.
- Pixel: 0 status changes, 1 expected md5 change.
- 6 ignore entries become 2: the four rows that now pass are pruned.

CI: graphics, `categories=full` (`audio` lives in the misc group). Add the **no-graphics leg** as well: `verify_output.py` changed, and the media code runs in both builds.

## 1. Patch scope

All changes are self-localized:
- trailing struct fields;
- `static` helpers;
- two new symbols that exist only under `SWF_HARNESS_WITH_AUDIO && !NO_GRAPHICS`.

There are no edits to `avm2_main.c`, `avm2_ops.c`, `avm2_gc.c`, `avm2_text.c`, `avm2_globals.c` or `avm2_bitmap.c`.

| File | What |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_net.c` | **L1.** This ports the Ruffle `streams.rs` status-event state machine onto the existing `ns_video_tick_one`. |
| | `NsVideoStream` gains trailing fields: `playing`, `has_seek`, `queued_seek_ms`, and `gen` (bumped on every `play()`, standing in for "source replaced"). |
| | `play()` fires `Play.Start`. The first loaded tick fires `Buffer.Full`, before the onMetaData drain. |
| | A non-lookahead EOF underrun fires `Buffer.Flush`, then `Play.Stop`. It then fires `Buffer.Empty` and pauses, but only if the handler did not call play() again. |
| | `seek()` fires `SeekStart.Notify "Start Seeking <ms>"`. The next tick runs `Seek.Notify`, repositions to the keyframe (backward: at/before; forward: at/after) and fires `Seek.Complete "Seek Complete -1"`. |
| | `pause()` fires `Pause.Notify "Pausing"`. `resume()` and `togglePause()` flip `playing` and nothing else. `NetStream.time` now returns `stream_time/1000` (it was `ns_get_zero`). |
| | Under the define, the shared mixer-clock advance in `ns_video_tick` also calls `avm2_media_harness_mix`, and the audio window sums in the harness ring. |
| | Clean-ups versus the prototype: |
| | • the dead second `if (!v->loaded)` block is removed; |
| | • `g_ns_ctx` is now also set in `avm2_net_deliver_netstream_meta(ctx)`, so tick-time events always have a context; |
| | • the "PROTOTYPE" labels are gone. |
| `SWFModernRuntime/src/avm2/avm2_media.c` | **L2a.** The `SoundChannel` ext gains `sim_done`, `sim_final_ms` and `mixer_len_ms`. A drained channel, from the simulated clock or the mixer, reports `position` = the sound's own length (Ruffle `bcac30c19` `audio.rs`). `stop()` is unchanged. |
| | Under `SWF_HARNESS_WITH_AUDIO`, an embedded Sound whose mixer start did not succeed joins the simulated clock: max(loops,1) passes of start..length. |
| | **L2b** (graphics + define only): `avm2_media_harness_mix` / `_window`, a ring keyed by the absolute clock frame and filled by the real `audio_mix`. |
| `SWFModernRuntime/include/avm2/avm2_globals.h` | The two harness prototypes, inside the same `#if`. |
| `ruffle-tests/verify_output.py` | **4 lines, one hunk**, right after the `SWF_PLAYER_MODE_RELEASE` define: `with_audio = true` in `test.toml` adds `-DSWF_HARNESS_WITH_AUDIO=1`. It is kept separate from `w2-bitmap-encode-shader`'s copy-list hunk. |
| `ruffle-tests/tests/swfs/avm2/ignored_tests.txt` | Prunes `audio_computespectrum`, `netstream_play_flv`, `netstream_play_stop_replay` and `netstream_seek_flv`, with a dated note. Keeps `soundchannel_position` and `soundchannel_soundcomplete`. |

**The `with_audio` gate is unchanged from the prototype (brief item 1).** It is set only by the toml key, which is exactly Ruffle's `TestAudioBackend` selection. 11 rows in avm2/audio/mixed_avm carry the key:
- `avm2/`: `audio_computespectrum`, `soundchannel_position_after_end`, `sound_constructor_with_args`, `soundchannel_stop`, `negative_volume_panned`, `sound_rootless`;
- `audio/`: `aac`, `g711`, `g711_event_alaw`, `g711_event_mulaw`, `stream_incomplete_loop`.

All 11 are in the sweep. Only those 11 take a ccache miss.

**Browser/WASM side effect (Ruffle-correct, flagged).** The mixer-drain branch of `avm2_media_poll` (`#ifndef NO_GRAPHICS`, so browser builds pull the mixer for real) now makes `position` report the sound's length after a natural end, where before it reported the live mixer clock. This is the same `bcac30c19` Ruffle behaviour. No native-harness test can see it: nothing drains the mixer there without the define.

## 2. Brief item 2: `resume()` / `togglePause()` and `Unpause.Notify` (lead 1). REFUTED, nothing to add

At `bcac30c19`:
- `core/src/avm2/globals/flash/net/net_stream.rs:70-96`: `resume` → `ns.resume()`, `toggle_pause` → `ns.toggle_paused()`.
- `core/src/streams.rs:639-651`:
  - `resume` = `playing.set(true)` plus `StreamManager::activate`;
  - `toggle_paused` = flip, plus activate if now playing.
  - Neither dispatches a status event. Only `pause(notify=true)` fires `NetStream.Pause.Notify`.

The prototype's flip-only natives are therefore already a faithful port. I added a comment saying so at `ns_resume_proto`.
- Flash's documentation does list a `NetStream.Unpause.Notify` code.
- No corpus row reads it, and there is no Flash oracle for its timing or description.
- Inventing it would break Ruffle parity with nothing to grade it against. Left for an oracle (below).

## 3. Sweeps: clean `origin/master` vs patch, same box, `--verbose`

### 3.1 Graphics: 39 rows

The rows are L1 (17 in the report; 20 here) ∪ L2 (30) ∪ the regression row:
- every `avm2/netstream*`, `net_stream*`, `netconnection*`, `flash_media_video_*` row;
- every `audio/*` row;
- all 11 `with_audio` rows;
- all 16 `avm2/sound*` rows;
- `regression/avm2_sound_bytes_and_group_format`.

**Only the 5 ledger rows move.**

| Test | Before | After |
|---|---|---|
| audio/aac | pass 18/18 | pass 18/18 |
| audio/g711 | pass 6/6 | pass 6/6 |
| audio/g711_event_alaw | pass 0/0 | pass 0/0 |
| audio/g711_event_mulaw | pass 0/0 | pass 0/0 |
| audio/stream_incomplete_loop | pass 0/0 | pass 0/0 |
| **avm2/audio_computespectrum** | mismatch 0/118 | **pass 118/118** |
| avm2/flash_media_video_constructor | pass 156/156 | pass |
| avm2/flash_media_video_rotation_probe | pass 27/27 | pass |
| avm2/flash_media_video_setter | pass 40/40 | pass |
| avm2/negative_volume_panned | pass 0/0 | pass |
| avm2/net_stream_play_options | pass 6/6 | pass |
| avm2/netconnection_call_with_responder | pass 6/6 | pass |
| avm2/netconnection_close | pass 55/55 | pass |
| avm2/netconnection_properties | pass 78/78 | pass |
| avm2/netconnection_send_remote | pass 50/50 | pass |
| avm2/netconnection_serialize_arrays | pass 6/6 | pass |
| avm2/netstream_client | pass 10/10 | pass |
| avm2/netstream_connect | pass 7/7 | pass |
| avm2/netstream_flv_date | pass 4/4 | pass |
| **avm2/netstream_play_flv** | mismatch 0/16; img pass max 0 | **pass 16/16**; img pass max 0 |
| **avm2/netstream_play_stop_replay** | mismatch 1/11 | **pass 11/11** |
| **avm2/netstream_seek_flv** | mismatch 0/49; img pass max 156 | **pass 49/49**; img pass max 146 |
| avm2/sound_constructor_with_args | pass 6/6 | pass |
| avm2/sound_embeddedprops | pass 26/26 | pass |
| avm2/sound_load_multiple | pass 19/19 | pass |
| avm2/sound_play | pass 19/19 | pass |
| avm2/sound_rootless | pass 7/7 | pass |
| avm2/sound_valueof | pass 33/33 | pass |
| avm2/soundchannel_position | ruffle_matched 66/140 | ruffle_matched 66/140 |
| **avm2/soundchannel_position_after_end** | mismatch 2/6 | **pass 6/6** |
| avm2/soundchannel_soundcomplete | ruffle_matched 6/16 | ruffle_matched 6/16 |
| avm2/soundchannel_soundtransform | pass 835/835 | pass |
| avm2/soundchannel_soundtransform_exists | pass 5/5 | pass |
| avm2/soundchannel_stop | pass 8/8 | pass |
| avm2/soundmixer_buffertime | pass 5/5 | pass |
| avm2/soundmixer_soundtransform | pass 900/900 | pass |
| avm2/soundmixer_stopall | pass 6/6 | pass |
| avm2/soundtransform | pass 442/442 | pass |
| regression/avm2_sound_bytes_and_group_format | pass 27/27 | pass 27/27 |

The before leg reproduces the w1 report's baseline shapes exactly. `avm2/soundchannel_position_after_end` is the new upstream row at `bcac30c19`; the baseline already grades it as failing, so this is a real flip, not drift.

### 3.2 No-graphics: 14 headline + rider rows

| Test | Before | After |
|---|---|---|
| **avm2/netstream_play_flv** | mismatch 0/16 | **pass** |
| **avm2/netstream_play_stop_replay** | mismatch 1/11 | **pass** |
| **avm2/netstream_seek_flv** | mismatch 0/49 | **pass** |
| **avm2/soundchannel_position_after_end** | mismatch 2/6 | **pass** |
| avm2/audio_computespectrum | mismatch 0/118 | mismatch 0/118 (expected) |
| avm2/soundchannel_position | ruffle_matched 66/140 | ruffle_matched 66/140 |
| avm2/soundchannel_soundcomplete | ruffle_matched 6/16 | ruffle_matched 6/16 |
| avm2/sound_play / soundchannel_stop / sound_rootless / netstream_flv_date | pass | pass |
| audio/aac | mismatch 12/18 (pre-existing NG gap) | mismatch 12/18 |
| audio/g711 | pass | pass |
| regression/avm2_sound_bytes_and_group_format | pass | pass |

## 4. Render canary A/B

I ran `render_canary.py capture --label before/after` on every canary-relevant AVM2 NetStream render: `visual/video/h264_multinalu` (standing canary member), `visual/video/h264`, `avm2/netstream_play_flv` and `avm2/netstream_seek_flv`.
- 13 PNGs: **12 IDENTICAL, 1 DIFFERS**.
- The one that differs is `avm2/netstream_seek_flv` `output`: 11061/880000 channels differ, max 25, bbox (98,63)-(222,177).
- Its image status is pass → pass, max_diff 156 → 146. This is the ledger's expected change: the seeks now really reposition the video.

**Why I did not run the other ~235 standing canary members.** Every behaviour change is reachable only through one of two routes:
1. an AVM2 `NetStream` object (`ns_*` natives and the per-stream tick, which iterates only live streams);
2. the `SWF_HARNESS_WITH_AUDIO` define (11 rows, all swept above).

The one ungated sound change outside those routes is `sim_done` / `sim_final_ms`:
- On the URL-sound simulated drain it reports `ext_duration_ms`, the same value the old `sim_elapsed_ms = sim_duration_ms` gave.
- On the mixer-drain path it is unreachable in the native harness without the define.

No standing canary member attaches an AVM2 NetStream except `h264_multinalu`, which is IDENTICAL. The set can already see this change class, so I appended no new member.

**Fidelity.** `netstream_seek_flv`'s image passes in CI, so `origin/ruffle-image-results` holds no actual PNG to byte-compare against. The pixel claim is therefore A/B only (md5 + max_diff). Absolute grading is CI's job.

## 5. Not finished / HOLDs

- **`audio_computespectrum` in no-graphics.** It stays failing: NG has no mixer.
  - Completion mechanism: the s23 §5 `audio/aac` recipe, i.e. an audio-only mixer/decoder in the NG build.
  - It is a documented gap; the ignore-list note says so.
- **No regression fixture for pause/resume/togglePause.** Ruffle fires no event on resume/toggle, and the corpus rows already pin play, stop, replay, seek and pause.
  - A fixture needs an outside oracle (request below).

## New unclaimed leads

1. **Flash `NetStream.Unpause.Notify`.** It is documented by Adobe, absent in Ruffle. It needs a Flash capture before anyone implements it (Flash over Ruffle, but only with an oracle).
2. **`NS_MAX_VIDEO_STREAMS` slots never freed.** Pre-existing (s23 §6); unchanged.
3. **No-graphics `audio_computespectrum` parity.** As in §5.

## LOCAL ORACLE REQUESTS

Optional, non-blocking. Run a Ruffle exporter trace (and, if available, a Flash capture) of `ruffle-tests/tests/swfs/avm2/netstream_seek_flv/test.swf` modified to call `ns.resume()` on frame 6 and `ns.togglePause()` on frame 7, tracing every `netStatus` code and description. It would back a `regression/` pause-resume fixture and settle lead 1.
