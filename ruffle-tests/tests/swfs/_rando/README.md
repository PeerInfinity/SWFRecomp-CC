# `_rando` — Archipelago `Rando` builtin integration tests

Manual / local integration tests for the native `Rando` (Archipelago) builtin.
These are **not** part of the default Ruffle suites and are **not** run in CI:
they require the runtime to be built with `WITH_AP=1` (which links APCpp), and
the suite lives outside `tests/swfs/avm1` so the corpus downloader ignores it.

Prerequisite: APCpp built locally (see
`SWFRecompDocs/plans/archipelago-randomizer-integration.md`):

```bash
cmake -S ~/CC/APCpp -B ~/CC/APCpp/build -DCMAKE_BUILD_TYPE=Release
cmake --build ~/CC/APCpp/build -j
```

## rando_smoke

Constructs a `Rando` and polls it **without** `connect()` (no server, no network
thread → deterministic). Verifies the AVM1 `new Rando(...)` construct path,
method dispatch, and that APCpp is actually linked/called.

Rebuild `test.swf` (only needed if you edit `Test.as` / `Rando.as`):

```bash
cd ruffle-tests/tests/swfs/_rando/rando_smoke
~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std -cp . \
    -main -header 200:150:30 Test.as -swf test.swf -version 8
```

Run:

```bash
WITH_AP=1 python3 ruffle-tests/verify_output.py \
    --test=rando_smoke --tests-dir=ruffle-tests/tests/swfs/_rando --diff
```

A full live-server test (connect + receive items + send a location) is a manual
step requiring a running Archipelago server — now automated by `livetest/`
(below).

## livetest/ — automated native round-trip test

`livetest/run_livetest.sh` is a **fully automated** integration test of the
native Rando backend (`rando_ap.h` → `rando_ap.cpp` → APCpp) against a real
Archipelago server. It builds the shim + a small C harness, starts a local AP
server, runs the harness, and tears the server down.

Prerequisites: APCpp built (above), and **Archipelago-CC** at `~/CC/Archipelago-CC`
with its `.venv` set up. The server is launched via that repo's
`scripts/setup/setup_ap_server.py --game checksfinder --seed 1 --port 38281`.

```bash
ruffle-tests/tests/swfs/_rando/livetest/run_livetest.sh   # exit 0 = PASS
```

What it asserts (ChecksFinder seed 1, slot `Player1`, no password):
1. connects to `localhost:38281`;
2. receives starting item `80002` (Map Bombs);
3. `sendLocation(81001)` (Tile 2) → `81001` becomes checked (round-trip confirmed).

The item Tile 2 grants (`80000` Map Width) is the player's OWN item at their OWN
location, which APCpp intentionally excludes from `received_items`
(`Archipelago.cpp` filters `sending_player == self && location > 0`) — so that's
logged as info, not asserted. Real multiworld items (from other players) would
appear in `received_items`.

Paths are overridable via env: `APCPP_ROOT`, `APCPP_BUILD`, `AP_REPO`, `AP_PY`,
`PORT`.

## livetest/browser/ — automated WASM/browser transport round-trip test

`livetest/browser/run_browser_livetest.sh` is the WASM/browser counterpart of the
native test above. It exercises the Phase-2 bridge — `rando_bridge.js` +
`archipelago.js` + the browser `WebSocket` — against a real AP server, driving
`window.__randoBridge` from headless chromium via Playwright. It serves a minimal
page (`harness.html`), starts a local AP server, runs the driver, and tears the
server down. **Transport-level only: no WASM/SWF/WebGPU** (those layers are
covered by the `rando_smoke` unit test and manual demo).

Prerequisites: **Archipelago-CC** at `~/CC/Archipelago-CC` with its `.venv`
(server) AND Playwright + chromium installed. Currently only the AP repo has
Playwright, so the runner defaults `PLAYWRIGHT_NODE_MODULES` to
`~/CC/Archipelago-CC/node_modules`; override it once this repo gets its own
install. Also needs `node` and `python3`.

```bash
ruffle-tests/tests/swfs/_rando/livetest/browser/run_browser_livetest.sh  # exit 0 = PASS
```

What it asserts (same ChecksFinder seed 1 / `Player1` fixture):
1. connects to `127.0.0.1:38281` (forced IPv4 — chromium resolves `localhost`
   to IPv6 first, but the server binds v4 only);
2. receives starting item `80002` (Map Bombs);
3. `sendLocation(81001)` (Tile 2) → `81001` becomes checked (round-trip confirmed);
4. receives granted item `80000` (Map Width).

Unlike the native APCpp path, **archipelago.js does NOT filter own-location
items**, so the item Tile 2 grants (`80000`) DOES appear in received items here —
hence assertion 4, which the native test only logs as info.

Paths/ports are overridable via env: `AP_REPO`, `AP_PY`,
`PLAYWRIGHT_NODE_MODULES`, `AP_PORT`, `HTTP_PORT`.
