# DJ level loader — procedural Archipelago levels inside real Doodle Jump

Production successor of `../dj_probe/`: an injected-AS **level loader** that
makes the real recompiled Doodle Jump render procedurally generated,
logic-verified bounceDemo `'dj'` levels from Archipelago-CC, fulfilling the
`window.__swfBridge` flashSubstrate contract (same semantics as the JS
renderer reference page `Archipelago-CC/frontend/modules/bounceDemo/game/main.js`).

Spec: `~/CC/Archipelago-CC/NewDocs/plans/procedural-generation/dj-loader-integration-spec.md`.
Status/results: `SWFRecompDocs/status/2026-06-11-dj-level-loader-first-increment.md`.

## How it works

```
Loader.as (+ generated FixtureData.as)
  --(MTASC)--> loader.swf --(extract_bytecode.py)--> loader_bytecode.bin
  --(inject_tracer.py, splice before first ShowFrame)--> dj_loader.swf
```

The injected `Loader` class (high-depth clip onEnterFrame):
1. pulls the level (compact string) via `ExternalInterface.call("__swfConfig")`
   — or `FixtureData.DATA` when EI is unavailable (graphics-native headless);
2. forces gameplay (`_root.gotoAndPlay(2)`), waits for the native spawner's
   initial attach, then **takes over the container**: kills the spawn
   `onEnterFrame`, parks the 15 native blocks/powerups offscreen, and CLAIMS
   `block_<idx>` clips — repositioning, not remove+reattach (see gotchas);
3. detects landings via `hero.lastblockhit` transitions (exact — the hero's
   own catch loop maintains it) and fires the landing-triggered goals:
   `__swfSendLocation(pickupId)` / `__swfSendExit("portalId|side")`;
4. polls `__swfPoll()` per tick (FULL current held-item set) and applies
   item-gated platform existence (park/position + `attribute[]`);
5. intercepts `_root.gameOver` (bottom fall) → respawn at the entrance,
   collected pickups persist, broken browns restore;
6. emits a per-tick `LT<t> hx= hy= vy= cy= lb= sc=` state trace
   (cross-tier diffing + sustained-physics evidence).

DJ's hero physics are **untouched**. Platforms drive the hero's own engine:
`container.block_<idx>` + `container.attribute[idx]` (0 plain / 2 breaking),
indices assigned bottom-to-top by the encoder because the catch loop scans
`block_(lastblockhit-3) .. block_(lastblockhit+9)`.

Page side: `dj_swf_bridge.js` (game side of `__swfBridge`; encodes the level
JSON into the compact string — keep in sync with `gen_fixture.py`).
`dj_host_mock.js` plays host standalone (configure + grant "Brown platforms"
at `__DJ_GRANT_AT_MS`, default 15s).

## Usage

```bash
# 0. Regenerate level inputs from the committed preset (also after preset bumps)
python3 gen_fixture.py            # region_4_4.js + FixtureData.as

# 1. Build the injected SWF
./build_loader.sh                 # -> dj_loader.swf

# 2a. Graphics-native headless (fixture mode, ~75s first compile)
python3 ../dj_probe/run_native.py dj_loader.swf native_run --frames 400

# 2b. Ruffle (ground truth; needs DISPLAY)
./run_ruffle.sh 35

# 2c. SWFRecomp graphics-WASM (production; needs DISPLAY + WebGPU)
cp dj_loader.swf ../../../../../../SWFRecomp/tests/flasharchive/Doodle_Jump_loader/test.swf
source ../../../../../../emsdk/emsdk_env.sh
../../../../../../SWFRecomp/scripts/build_test.sh flasharchive/Doodle_Jump_loader wasm --graphics --clean
./run_wasm.sh 40            # FIXTURE=1 for the EI-less offline variant

# 600-wide stage variant (header-RECT patch; Stage.width-driven wrap follows)
python3 gen_fixture.py --stage-width 600
STAGE_WIDTH=600 ./build_loader.sh
WIDE=1 ./run_ruffle.sh 35   # wide Ruffle harness (600px element + __DJ_STAGE_W)
```

Diagnostics: `run_pausestack.js` (CDP `Debugger.pause` of a busy-looping main
thread → wasm stack with function names; how the malloc-spin/heap-corruption
hang was pinned) and `run_profile.js` (sampling variant; NOTE `Profiler.stop`
blocks on a busy main thread — pausestack is the one that works).

Expected event sequence (all tiers): `sendLocation loc_0` during the climb →
(grant) → `gate p9 (Brown platforms) -> exists` → `sendExit side_exit_W W`.
Verified 2026-06-11 on all three tiers (browser-WASM: 952/957-tick sustained
runs); full results in the status doc.

## Gotchas (hard-won)

- **`build_test.sh` does NOT re-run the recompiler when only `test.swf`
  changed** — always pass `--clean` after replacing the SWF, and verify with
  `strings build/wasm/*.wasm | grep <new trace text>`.
- **Browser-WASM hangs (main thread busy-loop) one-to-few ticks after
  `removeMovieClip` of attachMovie'd container children**, and after a large
  single-tick batch of MC ops from the injected clip's context. Hence (a) the
  claim/park design instead of remove+reattach, (b) the STAGED init (one op
  per tick), and (c) `hero.lastDeletedBlock = 999999` to disable the hero's
  own climb-recycle deletion (also the right semantics for authored levels).
  Runtime bug to fix separately — see the status doc.
- The native `coin` sprite's frame-1 action is `gotoAndPlay(1)` (per-tick
  self-goto): avoid attaching it from injected AS until the runtime hang is
  understood (`VIZ_COIN = false`).
- The container's frame-1 DoAction is deferred in browser-WASM relative to
  the injected clip — init waits for `attachBlocks`/`lastBlockAttached` so
  the spawner can't be resurrected after the kill.
- Graphics-native: brown-break (`gotoAndStop(4)`) tail diverges post-portal
  (container `_y` reads undefined afterwards; "Failed to place object at
  depth 1"). Pre-portal behavior and the whole contract sequence are clean;
  Ruffle is ground truth for the post-break tail.
