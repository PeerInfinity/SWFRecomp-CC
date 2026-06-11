# Doodle Jump flashSubstrate feasibility probe

Injected-AS feasibility probe for Doodle Jump (DJ), driving the
`flashSubstrate` capability questions in
`SWFRecompDocs/plans/archipelago-doodle-jump-feasibility.md`. The findings are
written up in
`SWFRecompDocs/status/2026-06-01-doodle-jump-flashsubstrate-feasibility.md`.

This is **probe scaffolding kept for reuse** (not a CI test). It demonstrates
the injected-AS approach against a *real* AVM1 game and is the starting point for
a production DJ substrate adapter.

## Approach: inject AS *before* recompiling

DJ's own ActionScript is non-cooperative (it doesn't call `ExternalInterface`).
So instead of relying on cooperative AS, we **inject** a probe class into the SWF
before recompiling, using the same pipeline the divergence tracer uses:

```
Probe.as --(MTASC)--> probe.swf --(extract_bytecode.py)--> probe_bytecode.bin
   --(inject_tracer.py, splice before first ShowFrame)--> dj_probed.swf
```

The injected probe hooks a dedicated high-depth clip's `onEnterFrame` (so it
doesn't clobber DJ's own `_root.onEnterFrame`), forces gameplay via
`_root.gotoAndPlay(2)` (the PLAY button's action — frame 6 is the INFO screen),
and reads/writes DJ's live object graph, reporting via `trace()` (which reaches
stdout natively and the console under Ruffle/WASM).

`Probe.MODE` selects the experiment: `observe` / `write` / `place` / `perceive`
/ `steer` / `keyspy`.

## Three runtime tiers (Ruffle first, then recompiled)

| Tier | Script | Runtime | Notes |
|---|---|---|---|
| 1 — ground truth | `run_ruffle.sh` | Ruffle web (real Flash) | headed Chrome; strips Ruffle's HW-accel overlay |
| 2 — recompiled, headless | `run_native.py` | SWFRecomp graphics-native (OFFSCREEN_RENDER) | fast (~10-16s), no DISPLAY; the iteration workhorse |
| 3 — recompiled, browser | `run_wasm.sh` | SWFRecomp graphics-WASM | headed Chrome + WebGPU; the production runtime; DOM-key input path |

## Usage

```bash
# 1. Build the injected SWF (edit Probe.MODE first)
./build_probe.sh

# 2a. Native (headless) — read/write/place/steer experiments
python3 run_native.py dj_probed.swf native_run --frames 45 [--input input_keys.json]

# 2b. Ruffle (ground truth) — needs DISPLAY + the Ruffle CDN
./run_ruffle.sh 12
#   (CLICK_XY="57,68" drives a real PLAY-button click instead of forced goto)

# 2c. WASM (browser) — build then run
cp dj_probed.swf ../../../../../../SWFRecomp/tests/flasharchive/Doodle_Jump_probe/test.swf
source ../../../../../../emsdk/emsdk_env.sh
../../../../../../SWFRecomp/scripts/build_test.sh flasharchive/Doodle_Jump_probe wasm --graphics
STEER_KEYS=1 ./run_wasm.sh 12     # STEER_KEYS=1 drives DOM ArrowRight/Left
```

## Physics measurement probe (Measure.as)

A second probe, `Measure.as`, measures DJ's physics constants/semantics for
Archipelago-CC's bounceDemo `'dj'` profile (spec:
`Archipelago-CC/NewDocs/plans/procedural-generation/dj-physics-measurement-spec.md`).
`build_measure.sh <exp>` seds the experiment name in and builds
`dj_measure_<exp>.swf`; experiments: `ff_rest ff_launch bounce spring keys
catch blue brown jetpack`. Run natively via `run_native.py` (keys needs
`--input input_measure_keys.json`), or on Ruffle by `cp dj_measure_<exp>.swf
dj_probed.swf && ./run_ruffle.sh <secs>` (`STEER_KEYS=1` for keys).
`parse_measure.py <trace> <exp> <tier> <run_id> <out.json>` converts a trace
to the spec's JSON; `finalize_measurements.py` stamps setup/notes prose and
writes `measurements/json/dj_constants_summary.json`. Results delivered
2026-06-11; see `SWFRecompDocs/status/2026-06-11-dj-physics-measurements.md`.
Caveat: blue/brown *animation children* don't run in graphics-native after a
forced goto (nested-child enterFrame gap) — Ruffle runs are ground truth there.

## Files

- `Probe.as` — the injected probe (MODE selects the experiment).
- `build_probe.sh` — compile + extract + inject.
- `run_native.py` — recompile + run graphics-native headless (superset of
  `tools/divergence/run_swfrecomp.py`, adds `--input`).
- `run_ruffle.sh` + `ruffle_harness.html` — Ruffle tier.
- `run_wasm.sh` + `wasm_harness.html` — WASM tier.
- `run_browser.js` — shared Playwright console-capture driver (click / key-steer).
- `input_play.json`, `input_keys.json` — native input-event sequences.

Generated artifacts (`dj_probed.swf`, `*_run/`, etc.) are gitignored.
The WASM build dir `SWFRecomp/tests/flasharchive/Doodle_Jump_probe/` is also
throwaway (regenerate from `dj_probed.swf`).
