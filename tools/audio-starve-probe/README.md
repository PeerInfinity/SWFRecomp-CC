# audio-starve-probe — does the web audio output replay on a main-thread stall?

Acceptance probe for `SWFModernRuntime/src/audio/audio_output_web.c` (AudioWorklet
output, 2026-10-19). It runs a browser-WASM build in headless Chromium and puts a
recorder AudioWorklet downstream of the output node (`window._swfAudioOut`). It
wraps `Module._audio_fill_buffer` so every mixed quantum carries a sample counter.
Then it measures:

- **cadence**: `audio_mix` calls per audio-clock second over 20 s with no stall
  (expected 44100/2048 = 21.533), and the frames per call (expected `[2048]`).
  `pcm_position` (SoundChannel.position) advances by frames mixed, so the same
  cadence and quantum mean the same sound clock.
- **stall**: it busy-loops the main thread for `blockMs`, then reports
  `replays`: runs of counter values that were already heard. The worklet path must
  give `[]`. It also reports the silence it played (`longestZeroRunMs`), and
  `burstAfterStall` / `cadenceThroughStallPerAudioSec`. Those two show that the
  mixes for the stalled time still run (they are discarded), exactly like the
  ScriptProcessor's queued callbacks.

`?sp=1` sets `window.SWF_AUDIO_SCRIPTPROCESSOR` and forces the legacy path for the A/B.

```bash
source emsdk/emsdk_env.sh
(cd SWFRecomp && ./scripts/build_test.sh stop_sounds_swf_4 wasm --graphics)
W=SWFRecomp/tests/stop_sounds_swf_4/build/wasm
cp tools/audio-starve-probe/probe.html $W/
python3 -m http.server 8297 --directory $W &   # pick a free port; check `ss -ltn` first
python3 tools/audio-starve-probe/starve_probe.py http://localhost:8297/probe.html 1500
python3 tools/audio-starve-probe/starve_probe.py "http://localhost:8297/probe.html?sp=1" 1500
```

The 2026-10-19 matrix is in `RESULTS-2026-10-19.txt` (box load ~13, SwiftShader):

- Worklet: 0 replays at 0, 300 and 1500 ms.
- Legacy: 1, 5 and 16+ replays of the same 4096 samples.
- Both: steady cadence 21.53/s, and an identical post-stall burst (11/11, 36/36).

The legacy 0 ms replay is a natural stall on the loaded box. The SwiftShader WebGPU
validation errors on the console are expected and harmless here. The counter wraps
every 1e6 samples, so the replay detector ignores jumps of more than 500000.
