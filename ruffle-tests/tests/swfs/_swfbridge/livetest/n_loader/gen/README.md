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

This is injected-AS / JS tooling under `_swfbridge/livetest/` — **not
CI-observable**; do not dispatch ruffle-tests CI for it.
