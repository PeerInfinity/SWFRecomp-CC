# s23 wave 2 — `w2-netstream-audio`: NetStream audio tap + `SoundMixer.computeSpectrum`

**Verdict: GO, +2 trace in graphics mode (`audio/aac`, `audio/g711`); 0 pixel moves.** Both rows go fail → PASS
on exact text in `--mode=graphics`. In no-graphics, `audio/g711` also flips, but `audio/aac` stays fail → fail,
because no-graphics builds have no libavcodec by design (see §5). Nothing regresses in the A/B sweep (§4):
every other row in either mode is unchanged, and the canary and the NetStream image rows are md5-identical.

Branch `fanout/w2-netstream-audio`, base `origin/master` @ `bdb58bd2` (code identical to `7b6a69124` +
docs). Upstream tests: Ruffle `0ddd12b6a` (download_tests.sh, 2026-11-21). Box: cloud, Dawn on lavapipe, SETUP_STATUS all OK.

## NEW files

- `SWFRecompDocs/plans/session23-fanout-reports/w2-netstream-audio-report.md` (this)
- `SWFRecompDocs/plans/session23-fanout-reports/w2-netstream-audio.patch`

There are no new source files. Everything lives in existing TUs (`avm2_net.c`, `avm2_media.c`, `video_codec.c`),
so nothing changes in `verify_output.py`, CMake or the Emscripten source lists. No new fixture (see §6).

## EXPECTED-FLIP LEDGER (coordinator: check CI against this)

| Axis | Mode | Test | Before → After |
|---|---|---|---|
| trace | graphics | `audio/aac` | fail (`TypeError #1006 computeSpectrum`) → **PASS** |
| trace | graphics | `audio/g711` | fail (same) → **PASS** |
| trace | no-graphics | `audio/g711` | fail → **PASS** |
| trace | no-graphics | `audio/aac` | fail → fail (text changes: `TypeError` lines become `FAIL` lines; no libavcodec in no-graphics) |
| pixel | graphics | — | none. `avm2/netstream_play_flv`, `avm2/netstream_seek_flv` and all canary members are md5-identical |

The `categories=all` (classic five) CI run does not include `audio`; the rows live in the **misc** group, so dispatch
`categories=full` (as Slot D in `w1-trace-tail` §6 said). `avm2/audio_computespectrum` is ignored and stays a
MISMATCH (§7).

## 1. Patch scope (all in existing TUs; `git diff origin/master -- SWFModernRuntime`, 5 files)

| File | Change |
|---|---|
| `src/actionmodern/video_codec.c` + `include/actionmodern/video_codec.h` | New `audio_decoder_create/decode/destroy`: a persistent libavcodec audio decoder keyed by FLV SoundFormat (AAC with AudioSpecificConfig extradata, MP3, ADPCM_SWF, Nellymoser, Speex). It returns interleaved float, keeping the first 2 channels. The whole body sits under `#ifdef SWF_HAVE_LIBAVCODEC`; without it, `create` returns NULL and has no `av_*` references. |
| `src/avm2/avm2_net.c` | **FLV audio tap.** `NsAudio` is a trailing field of the file-static `NsVideoStream`. `ns_video_tick_one` gets one new line: consumed (non-lookahead) tag-8 bodies go to `ns_audio_tag`. G.711 A-law/µ-law (ITU tables, fixed 8 kHz) and linear PCM 0/3 are decoded locally; everything else goes through the libavcodec decoder. Any rate other than 44.1 kHz passes through a 32-tap Blackman-windowed sinc resampler, normalized to DC gain 1. Mono is duplicated to L and R. Output goes to a 16384-frame stereo float ring. There is a **mixer clock** (`g_ns_mix_frames`, see §2) and the public `avm2_net_netstream_audio_window()`. |
| `include/avm2/avm2_globals.h` | Declares `avm2_net_netstream_audio_window`. |
| `src/avm2/avm2_media.c` | `SoundMixer.computeSpectrum(outputArray, FFTMode=false, stretchFactor=0)`, ported from Ruffle `sound_mixer.rs`. |

**`computeSpectrum` details:**
- A null array throws `#2007`.
- `stretch == 0` keeps every second value.
- `stretch > 0` repeats each value `max(s-1,1)` times.
- The array gets length 2048, then 256 L floats and 256 R floats written through `avm2_bytearray_write_uint_public`, so the array's endianness is honoured. Position ends at 0.
- **FFTMode=true is implemented, not zeroed.** It is Ruffle's reverse-engineered transform: a 2048-point real FFT of the 512 history samples, zero-padded, with each bin k < 512 = `max(ln|Re X[k]|, 0)/4`. It is computed as a direct DFT over the 512 nonzero inputs with a cosine table, about 0.5 M MACs per call. An all-zero input gives zeros: `ln 0 = -inf` is clamped, so no NaN.

**Video path untouched.** `ns_video_tag`, the lookahead and offset logic, and `stream_time` are byte-for-byte unchanged. The audio decode only reads tag bodies. The md5 identity in §4 confirms it.

## 2. The window-alignment finding (premise attack: "exact decode always passes" is refuted for AAC)

`w1-trace-tail` §3 priced this as "exact decode always passes" (perfect-sine amplitude 0.974–1.026). That holds for the **amplitude** check, but the per-sample **wave check** (error < 0.025) is phase-agnostic only for a pure sine. Real AAC adds codec error.

I decoded the mono files with ffmpeg + soxr, ffmpeg's own reference decoder, and graded every window end from 300 to 900 ms:

| file | windows failing the 0.025 wave check |
|---|---|
| `tone_mono_22050hz` | 0 % |
| `tone_mono_44100hz` | 21 % |
| `tone_mono_48000hz` | 32 % |

The failing windows sit in contiguous patches. The first implementation anchored the window end at the stream's `stream_time` (750 ms). That position is inside the 44.1 kHz/48 kHz patch, so both mono rows failed with `Wave mismatch` (max 0.030).

**Fix: model where Ruffle's window lands.** All of this was read from source at `0ddd12b6a`:
- `tests/framework/src/backends/audio.rs`: `TestAudioBackend::set_frame_rate` sizes the buffer at `round(2*44100/fps)` floats. That is 3675 at 24 fps, i.e. **1837 whole frames per tick**. `tick()` mixes it.
- `core/src/player.rs::tick`: the order is `run_frame` → `update_timers` → `StreamManager::tick` → `audio.tick()`.
- `mixer.rs`: `get_sample_history` returns the 1024-frame half of a 2048-frame CircBuf that is not being written, i.e. the **last complete aligned 1024-frame block**. `compute_spectrum` uses its first 512 frames.
- `core/src/timer.rs`: the clock is integer µs (`dt` = 41666). A timer fires when `tick_time < cur_time`, so the play and measure timers land on Ruffle ticks (1,20), (49,68), (97,116), (145,164), (193,212), (241,260).
- **Our order differs.** `avm2_net_deliver_netstream_meta` (the stream hook) runs *before* `run_due_timers` in `avm2_display_run_tick`. So our hook call N is Ruffle's stream+mix pass of tick N-1.
- **Measured:** our sound-start and measure clocks were exactly one tick ahead of Ruffle's for all six tones (start 2·1837, W = 20·1837 for tone 0, against Ruffle's 1·1837 and 19·1837).
- The audio clock therefore skips its first increment (`g_ns_mix_primed`). That reproduces Ruffle's (start, W) pairs exactly while leaving stream and video timing alone.

**Why the offset matters:** with the clock one tick off, only mono 48 kHz failed, at 0.0259 against 0.025. With it aligned, all eight rows pass.

**Measured self-grade margins.** These come from an env-gated dump of the exact 512 floats handed to the SWF, graded in Python; the dump was removed before commit.

| row | amplitude (pass 0.95–1.05) | max wave err (tol) | L/R phasor |
|---|---|---|---|
| aac mono 22.05k | 1.0137 | 0.0161 (0.025) | 0 |
| aac mono 44.1k | 0.9863 | **0.0215** (0.025) | 0 |
| aac mono 48k | 0.9752 | 0.0210 (0.025) | 0 |
| aac stereo 22.05k | 1.0206 | 0.0114 | 0 |
| aac stereo 44.1k | 0.9849 | 0.0153 | 0 |
| aac stereo 48k | 1.0032 | 0.0164 | 0 |
| g711 A-law | 1.0105 | 0.0253 (0.05) | 0 |
| g711 µ-law | 0.9886 | 0.0265 (0.05) | 0 |

**Fragility, stated plainly:** the AAC 44.1k and 48k mono rows depend on matching Ruffle's mixer-clock alignment, not only on decode accuracy. A later change to tick order, timer µs math or the stream hook's position can move them; G.711 and stereo AAC are robust. The `g_ns_mix_frames` comment in `avm2_net.c` records this.

## 3. Dispositions checked

- `audio/aac` and `audio/g711` `test.toml`: no `known_failure`, no `approx`, no `output.ruffle.txt`. They are not listed in any `ignored_tests.txt`.
- `with_audio = true` is a Ruffle player option; `verify_output.py` ignores it.
- `output.txt` is exact `Starting tone / Measuring... / PASS` text, so Flash's and Ruffle's verdicts agree.

## 4. Per-test before/after (same box; before = clean `origin/master` via `git apply -R`, after = this patch)

Trace sweep: every `audio/*` row, every AVM2 row whose `.as` uses NetStream/SoundMixer/computeSpectrum (grep), every `avm2/netstream_*` and `flash_media_video_*` row, and the regression-suite sound fixture. Both modes.

| test | graphics before | graphics after | no-graphics before | no-graphics after |
|---|---|---|---|---|
| audio/aac | MISMATCH | **PASS** | MISMATCH | MISMATCH |
| audio/g711 | MISMATCH | **PASS** | MISMATCH | **PASS** |
| audio/g711_event_alaw | PASS | PASS | PASS | PASS |
| audio/g711_event_mulaw | PASS | PASS | PASS | PASS |
| audio/stream_incomplete_loop | PASS | PASS | PASS | PASS |
| avm2/audio_computespectrum (ignored) | MISMATCH | MISMATCH | MISMATCH | MISMATCH |
| avm2/net_stream_play_options | PASS | PASS | PASS | PASS |
| avm2/netstream_client | PASS | PASS | PASS | PASS |
| avm2/netstream_play_stop_replay | MISMATCH | MISMATCH | MISMATCH | MISMATCH |
| avm2/soundmixer_buffertime | PASS | PASS | PASS | PASS |
| avm2/netstream_connect | PASS | PASS | PASS | PASS |
| avm2/netstream_flv_date | PASS | PASS | PASS | PASS |
| avm2/netstream_play_flv | PASS (img 0 outliers, max 0) | same | MISMATCH | MISMATCH |
| avm2/netstream_seek_flv | PASS* (img 27 outliers/271, max 156) | same | MISMATCH | MISMATCH |
| avm2/flash_media_video_{constructor,rotation_probe,setter} | PASS | PASS | PASS | PASS |
| regression/avm2_sound_bytes_and_group_format | PASS | PASS | PASS | PASS |

\* `netstream_seek_flv`'s trace status is `output_mismatch` in both legs per the canary manifest; its image passes in both.

- **Pixel axis:** `render_canary.py capture/compare` over the full standing set (86 tests / **141 comparisons**) gives **141 IDENTICAL, 0 DIFFERS**, with no trace or image status changes. The set includes the NetStream H.264 member `visual/video/h264_multinalu`.
- **NetStream image rows**, captured separately on current master (post-`7b6a69124` Spark IDCT): `avm2/netstream_play_flv` and `avm2/netstream_seek_flv` are **2/2 IDENTICAL**.
- The standing canary set already sees this change class through its NetStream member, so I appended nothing to `render_canary_tests.txt`.

**Regression suite:** the suite's only audio/NetStream-adjacent fixture, `regression/avm2_sound_bytes_and_group_format`, passes before and after in both modes. No regression fixture is added: see §6.

**Browser/WASM:** `build_wasm_avm2.sh`, `deploy_wasm_demo.sh` and `wasm_wrappers/bundle/build.sh` compile `video_codec.c` without `SWF_HAVE_LIBAVCODEC`. That stub path was checked two ways:
- `gcc -Wall -Wextra -fsyntax-only` with and without the define, on all three touched TUs: clean.
- A real CMake `-DWITH_LIBAVCODEC=OFF -DNO_GRAPHICS=ON` build of `video_codec.c.o`: it exports the three `audio_decoder_*` symbols with zero `av_*` references.

  That CMake tree fails elsewhere on pre-existing missing generated headers (`tesselator.h`, `constants.h`), which is unrelated.

There is no emsdk in the cloud box, so a real `emcc` link was **not** run. Completion mechanism: the coordinator's local `deploy-pages.yml -f dry_run=true` (or `build_wasm_avm2.sh`). The new code references only symbols defined in `video_codec.c`, which those builds already link for `video_decoder_*`.

## 5. Mode gap (no-graphics `audio/aac`)

No-graphics builds deliberately carry no libavcodec:
- `verify_output.py` probes it only in the `graphics` branch.
- CI's no-graphics job installs no `libavcodec-dev` (`ruffle-tests.yml`'s `Install Vulkan + libavcodec` step is `if: inputs.mode != 'no-graphics'`).

So in no-graphics, AAC has no decoder: computeSpectrum returns silence and the SWF prints `FAIL`. This is fail → fail (not a regression), but it is a **new per-test mode divergence**, which goes against CLAUDE.md's "per-test results identical" claim.

I did not change it, because closing it needs **both** of:
- (a) an audio-only libavcodec probe in `verify_output.py`'s no-graphics branch;
- (b) the workflow's no-graphics apt step installing `libavcodec-dev`.

A probe alone would split local no-graphics from CI no-graphics. If the coordinator wants parity:
- Add a `-DSWF_HAVE_LIBAVCODEC_AUDIO` arm.
- Guard the `audio_decoder_*` bodies on `SWF_HAVE_LIBAVCODEC || SWF_HAVE_LIBAVCODEC_AUDIO`.
- Link `libavcodec libavutil`.

That is an S change, but it touches CI and every no-graphics compile line (one ccache miss). Otherwise, book `audio/aac` as a graphics-only pass.

## 6. Not done / held

- **No `regression/` fixture.** The corpus rows are self-grading against Flash-recorded text and already cover G.711, AAC at 3 rates × 2 layouts, and the FFT=false path. A fixture for FFTMode=true or the stretch factors needs an outside oracle: see LOCAL ORACLE REQUESTS.
- **The NetStream audio is still not audible.** The tap feeds only computeSpectrum; the browser AudioWorklet does not play it. That is out of scope.
- **Pre-existing, untouched:** `NS_MAX_VIDEO_STREAMS` = 8 slots that are never freed. A ninth `play()` on a new NetStream is silently ignored by both video and audio.

## 7. `avm2/audio_computespectrum` (ignored): is it now cheap? **Half done; M, not S.**

The SWF plays an embedded MP3 (`levels.mp3`) with `Sound.play(0, 1000)`. Every frame it calls `computeSpectrum(ba, false, 0)` until all 512 floats round to the next DC level, then it traces `computeSpectrum(ba, true, s)` for s = 0..3.

- The `FFTMode=true` / stretch half is now implemented, as Ruffle's transform. A hand check against the expected output: for level 0.031, bin 0 = ln(512·0.031)/4 = 0.69, which matches `output.txt` line 5's `0.69`.
- What remains is a **Sound-object mix tap**: Sound.play channels contribute silence today. That needs:
  - the embedded MP3 decoded to PCM (the new `audio_decoder_create(2, …)` handles it, or an existing SWF-sound decode path);
  - a per-channel start on `g_ns_mix_frames` (loops, startTime);
  - summing into `avm2_net_netstream_audio_window`, or a shared mixer-history module.
- The DC levels are constant segments, so clock alignment is far less critical than for audio/aac.
- Estimate M, with a +1 lead (118 lines).

## New unclaimed leads

1. **`avm2/audio_computespectrum` +1 (M):** the Sound-object tap, §7.
2. **No-graphics AAC parity (S + CI):** §5.
3. **AVM1 `NetStream` audio:** none of the corpus rows read it, so there is no lead.

## LOCAL ORACLE REQUESTS

- Optional, only to back a regression fixture for FFTMode/stretch from a non-SWFRecomp oracle: run the Ruffle exporter on `ruffle-tests/tests/swfs/audio/g711/test.swf`, modified to also trace `computeSpectrum(ba, true, s)` for s ∈ {0,1,2,3}. Not blocking: the patch matches Ruffle's source line for line.
