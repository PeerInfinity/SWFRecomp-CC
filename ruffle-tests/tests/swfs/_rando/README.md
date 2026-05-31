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

## rando_item_application — deterministic item-application glue test

A two-SWF trace test (Phase 3 Slice 1, Layer 1) of the **item-application glue**,
driven by the synthetic native stub backend (no server, no network → fully
deterministic). It models the real prelude/game split:

- `prelude_rando.swf` (from `Prelude.as`) — the Archipelago-**aware** glue. Owns
  the `Rando`, installs `_global.rg`, holds the config-driven ITEM/LOCATION
  "enums" (`ap_items`: id→flash_name; `ap_locations`: flash_name→id), and applies
  items per "frame" by polling. Recompiled **before** the game (the harness
  detects `prelude_*.swf`).
- `test.swf` (from `Game.as`) — the Archipelago-**naive** game. Reads
  `_global.gameState` and calls `_global.rg`; never touches `Rando` or AP numbers.

The stub (`SWFModernRuntime/src/actionmodern/rando_stub.c`) delivers item 2
("Sword") on connect and grants item 1 ("Key") when location 100 is checked, so
the trace proves: id→flash_name→effect mapping, per-frame polling, event→location
check, and grant-on-check. Built with **`RANDO_STUB=1`** (not `WITH_AP`):

```bash
RANDO_STUB=1 python3 ruffle-tests/verify_output.py \
    --test=rando_item_application --tests-dir=ruffle-tests/tests/swfs/_rando --diff
```

Rebuild the SWFs (only if you edit `Prelude.as` / `Game.as` / `Rando.as`):

```bash
cd ruffle-tests/tests/swfs/_rando/rando_item_application
~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std -cp . -main -header 200:150:30 \
    Prelude.as -swf prelude_rando.swf -version 8
~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std -cp . -main -header 200:150:30 \
    Game.as -swf test.swf -version 8
```

## livetest/toy_browser — live item-application toy (real browser, APQuest)

`livetest/toy_browser/run_toy_livetest.sh` is the browser counterpart of
`rando_item_application`: it runs the **actual toy SWF** live against an APQuest
server, exercising the item-application glue end-to-end (connect → location check
→ granted item → effect applied) in a real browser frame loop. Source:
`SWFRecomp/tests/rando_browser_toy/Main.as` (single SWF — the glue + game together;
async `onEnterFrame` state machine).

It must be a **graphics** WASM build: only the graphics runtime (`swf.c`) paces
frames in real time (`emscripten_sleep` + ASYNCIFY), which is what lets the
WebSocket connect across frames. The runner regenerates the SWF (MTASC), builds
(`WITH_AP=1 build_test.sh rando_browser_toy wasm --graphics`), starts the AP
server, serves the assets, and drives **real headed google-chrome**.

**Requires an interactive display.** WebGPU needs a GPU compositor: Playwright's
bundled headless chromium has no `navigator.gpu`; the working path is headed
`/usr/bin/google-chrome` via WSLg/`DISPLAY` on a localhost (secure-context) page.
The runner preflights `DISPLAY` and refuses to run headless. Prereqs: emsdk,
Archipelago-CC venv, Playwright + chromium, `/usr/bin/google-chrome`.

```bash
ruffle-tests/tests/swfs/_rando/livetest/toy_browser/run_toy_livetest.sh   # exit 0 = PASS
#   --rebuild   force MTASC + graphics-WASM rebuild
```

Asserts (APQuest seed 1, `Player1`): connect → `sendLocation(2)` (Top Middle
Chest) + `sendLocation(10)` (Enemy Drop) → Sword (2) + Key (1) received (browser
doesn't filter own-location items) → both effects applied → `[toy] DONE`.

## bridge_unit — StubTransport unit test (browser, no server)

`bridge_unit/run_stub_test.sh` is the WASM-side counterpart: a **server-free**
transport-contract test of `rando_bridge.js`'s `StubTransport`. Headless chromium
(Playwright) drives `window.__randoBridge` with `window.__randoBridgeTransport =
"stub"` and a synthetic fixture — no Archipelago server, no WebSocket — asserting
connect + starting item + sendLocation-grant. Faster and lighter than
`livetest/browser/` (only needs Playwright + chromium, not the AP server/venv).

```bash
ruffle-tests/tests/swfs/_rando/bridge_unit/run_stub_test.sh   # exit 0 = PASS
```

## livetest/ — automated native round-trip test

`livetest/run_livetest.sh` is a **fully automated** integration test of the
native Rando backend (`rando_ap.h` → `rando_ap.cpp` → APCpp) against a real
Archipelago server. It builds the shim + a small C harness, starts a local AP
server, runs the harness, and tears the server down.

Prerequisites: APCpp built (above), and **Archipelago-CC** at `~/CC/Archipelago-CC`
with its `.venv` set up. The server is launched via that repo's
`scripts/setup/setup_ap_server.py --game checksfinder --seed 1 --port 38281`.

```bash
ruffle-tests/tests/swfs/_rando/livetest/run_livetest.sh            # checksfinder (default)
ruffle-tests/tests/swfs/_rando/livetest/run_livetest.sh apquest    # APQuest (Phase 3 fixture)
```

The `[game]` arg (default `checksfinder`) selects the AP server + the C harness:

- **checksfinder** (`rando_ap_livetest.c`) — slot `Player1`: connect; receive
  starting item `80002` (Map Bombs); `sendLocation(81001)` (Tile 2) → checked.
- **apquest** (`rando_ap_livetest_apquest.c`) — slot `Player1`: connect; **no**
  starting item (seed has none); `sendLocation(2)` (Top Middle Chest) → checked;
  `sendLocation(10)` (Right Room Enemy Drop) → checked.

In both, the items the checked locations grant are the player's OWN items, which
APCpp intentionally excludes from `received_items` (`Archipelago.cpp` filters
`sending_player == self && location > 0`) — logged as info, not asserted. So the
round-trip is asserted via the checked-location signal. Real multiworld items
(from other players) would appear in `received_items`. (The browser path below
does **not** filter — it asserts the granted items directly.)

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
ruffle-tests/tests/swfs/_rando/livetest/browser/run_browser_livetest.sh          # checksfinder (default)
ruffle-tests/tests/swfs/_rando/livetest/browser/run_browser_livetest.sh apquest  # APQuest
```

The `[game]` arg (default `checksfinder`) selects the AP server + a fixture from
`browser_livetest.js`'s `FIXTURES` map. All connect to `127.0.0.1:38281` (forced
IPv4 — chromium resolves `localhost` to IPv6 first, but the server binds v4 only):

- **checksfinder** / `Player1`: starting item `80002` (Map Bombs); `sendLocation(81001)`
  (Tile 2) → checked, grants `80000` (Map Width).
- **apquest** / `Player1`: no starting item; `sendLocation(2)` (Top Middle Chest)
  → checked, grants Sword (`2`); `sendLocation(10)` (Right Room Enemy Drop) →
  checked, grants Key (`1`).

Unlike the native APCpp path, **archipelago.js does NOT filter own-location
items**, so the items those locations grant DO appear in received items here —
each check asserts its granted item, which the native test only logs as info.

Paths/ports are overridable via env: `AP_REPO`, `AP_PY`,
`PLAYWRIGHT_NODE_MODULES`, `AP_PORT`, `HTTP_PORT`.
