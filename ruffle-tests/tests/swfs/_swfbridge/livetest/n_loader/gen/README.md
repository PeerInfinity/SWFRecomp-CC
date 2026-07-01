# N level generator (gen/)

Portable, self-contained JS (ES modules, no deps) for generating **solvable**
levels for recompiled N, verified against the real-N Ruffle oracle in the parent
`n_loader/` harness. Plan: `SWFRecompDocs/plans/n-level-generator-plan.md`.
Format facts: `SWFRecompDocs/status/2026-06-30-n-substrate-investigation.md`.

## Phase 0 (done): encoder + golden round-trip

- **`nLevel.js`** — the level model + `encode`/`decode`. A `Level` is a 31×23
  tile grid (`Int16Array`, column-major X-outer/Y-inner) plus typed objects
  (`{type, params}`). Helpers: `cellToPixel`/`pixelToCell`/`cellIndex`, the `OBJ`
  type map, `setTile`/`fillRect`/`setPlayer`/`setExit`/`addGold`, and
  `buildFloorLevel(...)` (generalizes `n_host_mock.js::buildWalkLevel`).
  `encode(level) → "mapStr|objStr"`, `decode(str) → Level`.
- **`builtin_levels.json`** — all 150 built-in N levels (`{id,name,source,level}`),
  extracted from N's decompiled `frame_1` scripts. The golden fixture.
- **`extract_builtin_levels.mjs`** — regenerates `builtin_levels.json` from a
  JPEXS script export:
  ```bash
  java -jar ~/CC/jpexs/ffdec.jar -export script /tmp/n_decomp ~/CC/flasharchive/N.swf
  node extract_builtin_levels.mjs /tmp/n_decomp > builtin_levels.json
  ```
- **`golden_roundtrip.test.mjs`** — asserts `encode(decode(s)) === s` byte-for-byte
  for every built-in level (locks format correctness):
  ```bash
  node golden_roundtrip.test.mjs   # -> 150/150 byte-identical, exit 0
  ```

## Batch-verify queue tooling

- **`nDemo.js`** — N demo (input replay) (de)serialization. `holdRight(ticks)` /
  `holdLeft(ticks)` / `encodeDemo(perTickMasks)` / `decodeDemo(str)`. Per tick =
  4 bits L/R/J/JTRIG; 7 ticks/entry; `holdRight(7) === "7:35791394"`.
- **`make_queue_testcases.mjs`** — writes a small fixed batch of flat walk-right
  levels (authored, not N's data) into `../n_queue_testcases.js` for the Ruffle
  `QUEUE=1` batch-verify run (see the parent README). The queue proved the
  SWF-side re-arm: N re-loads a fresh level after each completion in one session.
- **`queueFile.js`** — shared writer for `../n_queue_testcases.js`
  (`window.__N_QUEUE`).

## Phase 1 (done): flat generator + Ruffle acceptance gate

- **`nGenerate.js`** — seeded, deterministic flat-level generator.
  `generateFlatLevel(seed, opts)` / `generateFlatBatch(count, baseSeed, opts)`
  emit `{levelId, level, demo, meta}`: a solid floor row with spawn → switch →
  door laid left-to-right, solvable by a hold-right demo (the demo IS the proof).
  Knobs: `floorRow`, `spawnX`, walk distance, gold count. `makeRng` = mulberry32.
- **`nVerify.js`** — the authoritative gate. Generates a batch, writes the queue
  payload, runs one Ruffle session, and asserts every level reported
  `N_COMPLETE` (pass/fail read from `N_COMPLETE` / `N_FAIL` traces). A level is
  "good" only if real N completes it.
  ```bash
  node gen/nVerify.js [count] [baseSeed] [captureSecs]   # exit 0 iff all pass
  ```
  Verified: `node gen/nVerify.js 6 1` → 6/6 flat levels complete on real N in one
  session. The SWF advances the queue on `N_FAIL` too (per-level `LEVEL_MAX`
  frame budget), so one unsolvable level never stalls a batch.

## P2 (in progress): motion model MEASURED on real N

Telemetry-calibrated, momentum-aware. Before generating jumps/gaps we measured
N's actual motion (not derived from constants):

- **`nProbe.js`** — calibration probe matrix: flat floor, exit far right, demos
  that run `R` ticks (entry speed) then jump-hold `K` ticks, self-terminating.
- **`nTelemetry.js`** — splits a QUEUE console into per-level arcs and extracts
  features (entry vx, apex, airtime, air distance). Also a CLI dumper.
- **`calibrate.mjs`** — runs the matrix through one Ruffle session →
  **`nMotion_calib.json`** (measured table).
  ```bash
  node gen/calibrate.mjs            # -> nMotion_calib.json
  ```
- **`nMotion.js`** — the queryable model over the measured table: `runStep`,
  `runUpTicksForSpeed`/`runUpDistForSpeed`, `apexHeight(K)`, `airtime(K)`,
  `airDist(vx,K)`, and conservative envelopes `maxGap(vx)`, `maxStepUp()`,
  `maxRunningGap()`. `node gen/nMotion.js` self-reports.

Measured (real N): ground speed clamps at ~5 px/tick (`vx[n+1]=min(5,vx*0.99+0.15)`,
full ~tick 38); jump launch impulse constant (vy=−3); apex height + airtime depend
ONLY on hold `K` (vertical/horizontal decoupled); air distance depends on entry
speed AND `K` (air-control ramps vx back to ~5 mid-flight). Conservative envelopes:
step-up ≈ 2.6 tiles, same-level gap ≈ 12 tiles at full run.

> Known conservatism: the highest-speed/longest-hold probe (R45/K30) was truncated
> in capture, so max air distance is UNDER-stated (a 14-tile gap the model rejects
> actually clears on N). Safe direction (accepted levels pass); re-calibrate that
> cell later to reclaim range.

## P2 #1 (done): same-level gap generator, Ruffle-verified

- **`nReach.js`** — reachability by construction-by-simulation: `planRunJump(spawnX,
  launchX, gapPx)` simulates the run-up with the real ramp, reads the entry speed
  at the takeoff edge, picks the smallest measured hold whose `airDist` clears the
  gap, and emits the exact solving demo.
- **`nGenerate.js`** — `generateGapLevel` / `generateGapBatch`: takeoff platform →
  pit (`gapTiles`, capped to the envelope) → landing platform carrying the exit;
  the demo runs up and clears the pit with one timed jump.
- **`nVerify.js`** — now takes `flat|gap`: `node gen/nVerify.js gap 6 1`.

Verified: 6/6 random gap levels complete on real N in one session; an over-wide
(480px) gap correctly `N_FAIL`s (the physics gate is meaningful) while the batch
continues. Uses momentum: full-speed run-up + a timed variable-height jump.

This is injected-AS / JS tooling under `_swfbridge/livetest/` — **not
CI-observable**; do not dispatch ruffle-tests CI for it.
