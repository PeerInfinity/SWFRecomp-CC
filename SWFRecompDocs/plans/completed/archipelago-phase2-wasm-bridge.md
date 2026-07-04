> **AUDIT OUTCOME (2026-07-04):** Implemented + verified 2026-05-31 (browser archipelago.js bridge, docs2 demo panel, Playwright round-trip).

# Archipelago Phase 2 — WASM transport bridge (`Rando` in the browser)

**Status:** **Implemented + verified** 2026-05-31 (build + link + run + deploy +
demo-viewer panel all green via the `verify_output.py` WASM path). Depends on
Phase 1 (native `Rando`, shipped 2026-05-31 —
see [archipelago-randomizer-integration.md](archipelago-randomizer-integration.md)).
The live-server browser test (§8/§11) is now **automated and passing** —
`ruffle-tests/tests/swfs/_rando/livetest/browser/run_browser_livetest.sh` drives
`window.__randoBridge` (rando_bridge.js + archipelago.js + browser WebSocket) from
headless chromium against a real AP server, asserting the connect + item +
location round-trip. Transport-level (no WASM/SWF/WebGPU).

Demo viewer note: the real viewer is the shared dynamic `docs2/demo.html?test=<id>`
(docs2 = local hosting, where non-open-source game SWFs live — the AP target
games), **not** the legacy `index_template.html`. The AP UI is a self-contained
fragment (`rando_panel.js`, the single UI source) that `docs2/demo.html` loads
only when it HEAD-probes a staged `rando_bridge.js` — zero config, no
`test_info.json` schema change, non-AP demos untouched. `docs/demo.html` (public
GitHub Pages, open-source SWFs only) can get the same one-line hook later if an
OSS AP demo is ever wanted.

This doc plans the browser-WASM backend for the `Rando` builtin. Phase 1 made
`Rando` work in native builds via APCpp; Phase 2 makes it work in the
peerinfinity.com WASM demos, where APCpp's transport (IXWebSocket) **cannot
link** — it uses raw BSD sockets with no emscripten path. We bypass APCpp in the
browser entirely and talk to the AP server through **`archipelago.js`** over the
browser's native WebSocket.

## 1. The core idea: same seam, second backend

`SWFModernRuntime/include/actionmodern/rando_ap.h` is a **pure-POD seam**. Phase 2
is just a second implementation of it — nothing above the seam changes.

```
ActionScript: new Rando(...) / rando.method(...)     ← UNCHANGED across backends
        │
rando.c  (the Rando builtin class)                   ← UNCHANGED
        │  rando_ap.h (POD)
        ├── native:  rando_ap.cpp     → APCpp → IXWebSocket → ws    (Phase 1)
        └── wasm:     rando_ap_wasm.c  → EM_JS → window.__randoBridge
                                              → archipelago.js → browser WebSocket
```

`rando.c`, the AVM1 surface, `object.h`'s `NATIVE_RANDO`, and the `WITH_AP`
gating are all reused verbatim. Only the `rando_ap_*` *implementation* swaps, by
build target.

## 2. Why archipelago.js

`archipelago.js` v2.1.0 (ThePhar's official JS/TS AP client) speaks the full AP
websocket protocol from `window.WebSocket`. It is already vendored and proven in
the browser in `~/CC/flash-ap-api` (`archipelago.js` + `ap_flash_client.js`),
which connects real Flash/Ruffle games to AP via `ExternalInterface`. We reuse
the *transport library and the JS integration pattern* (not the AS3/DoABC
injection, which is a separate approach for unmodified games in a real player).

**Decision (locked):** vendor a copy of `archipelago.js` v2.1.0 into the
SWFRecomp demo assets (self-contained, version-pinned, no cross-repo coupling).
Source copy: `~/CC/flash-ap-api/archipelago.js`.

Client API → `rando_ap.h` mapping (all the data we need):

| `rando_ap.h` | `archipelago.js` `Client` |
|---|---|
| `connect()` | `client.login(url, name, game, opts)` |
| `is_connected()` | `client.authenticated` / `socket.connected` |
| `received_items_size()` | `client.items.received.length` |
| `received_item(i)` | `client.items.received[i].id` |
| `location_is_checked(id)` | `client.room.checkedLocations.includes(id)` |
| `send_location(id)` | `client.check(id)` |
| `story_complete()` | `client.updateStatus(clientStatuses.goal)` |

## 3. No ASYNCIFY needed

`client.login()` is async (Promise + WS handshake), but `Rando.connect()` is
**fire-and-forget** — exactly like Phase 1, where `AP_Start` spawns a thread and
the game polls state later. In WASM:

- `connect()` kicks off `client.login(...)` and returns immediately.
- `archipelago.js` keeps `items.received` / `checkedLocations` live via its own
  event handlers.
- Every Rando *read* is a synchronous read of that JS-side state.

So the Rando path needs **no ASYNCIFY** (the WASM build already enables ASYNCIFY
for audio/render, but Rando doesn't add to it). The per-frame **hot path is
POD-only** — counts/ids/bools across the boundary, no string marshaling. Strings
(`host/port/game/slot/pw`) cross **once**, at construct/connect time.

## 4. Connection ownership — HYBRID (locked decision)

One AS codebase must work on both backends. The decision: **`bridge.connect(host,
port, slot, pw)` is a single chokepoint**, callable from two places:

1. **AS-driven:** `new Rando(host, port, game, slot, pw); rando.connect()` — the
   thunk passes the constructor args (stashed at construct time) to
   `bridge.connect`. Identical AS runs native + WASM.
2. **HTML connect form (locked decision):** a form on the demo page calls
   `bridge.connect(...)` with field values — a *convenience override*, not a
   separate path. (Mirrors `flash-ap-api`'s `window.ap.connect`.)

**Idempotency guard** (the only real "both" complication): `bridge.connect`
tracks state and won't double-fire `login()`. Rule: first connect wins; a form
connect while disconnected replaces. Easy to tune later.

Args storage: `rando_ap_new(host,port,game,slot,pw)` (same signature as native)
passes the strings to `bridge.init(id, …)` once; `connect()` uses them unless the
form overrides. This keeps native/WASM connection semantics aligned at the
AS-visible level (best-effort, poll `isConnected()`); error/reconnect internals
legitimately differ (APCpp retry loop vs archipelago.js) and we do **not** try to
unify those in Phase 2.

## 5. Scope boundary: transport only

Phase 2 makes `Rando`'s data *readable* in the browser. It does **not** implement
"give the player the item" — that loop
(`while (n < rando.receivedItemsSize()) giveItem(rando.receivedItem(i++))`) and
the `ITEM`/`LOCATION` enums are **Phase 3**, game-specific, in injected AS.
Consequences:

- EM_JS thunks stay **POD-only** (no item-name strings across the boundary;
  `AP_GetItemName`/`AP_Say` stay deferred, per LittleCube).
- Phase 2 verification is **manual in-browser** against a local AP server — there
  is no headless WASM+WebSocket harness, and the deterministic trace suites
  neither touch nor need this.

## 6. Components to build

| Component | Where | Notes |
|---|---|---|
| `rando_ap_wasm.c` | `SWFModernRuntime/src/actionmodern/` | EM_JS thunks mirroring `rando_ap.h`; guarded `#if defined(WITH_AP) && defined(__EMSCRIPTEN__)`. Replaces `rando_ap.cpp` in the WASM build. |
| `rando_bridge.js` | demo assets (new) | Hand-written glue exposing `window.__randoBridge` (`init/connect/isConnected/receivedItemsSize/receivedItem/locationIsChecked/sendLocation/storyComplete`) over one `archipelago.js` `Client`. Trimmed from `ap_flash_client.js`. |
| `archipelago.js` | demo assets (vendored) | Copy of v2.1.0 from `flash-ap-api`. |
| connect form | HTML template | Add to `SWFRecomp/wasm_wrappers/index_template.html` (+ `_graphics`) behind a build flag, calling `window.__randoBridge.connect`. |

EM_JS precedent already exists in the runtime (`audio_output_web.c`,
`render_webgpu.c`), all guarded by `#ifdef __EMSCRIPTEN__`.

## 7. Build wiring (WASM, `WITH_AP`)

- **`ruffle-tests/verify_output.py` `compile_wasm`** (≈ line 1906): under
  `WITH_AP`, add `rando.c` + `rando_ap_wasm.c` to the WASM `core_sources`, add
  `-DWITH_AP`, and ship `archipelago.js` + `rando_bridge.js` into the build dir.
  (Note: a no-server WASM run can't be a deterministic suite test — this path is
  for manual browser bring-up, not CI.)
- **`SWFRecomp/scripts/build_test.sh` wasm path** (≈ lines 260–323): same
  `WITH_AP` additions for the demo build; emit the connect-form template and copy
  the JS assets next to `index.html`.
- **`deploy_example.sh` / `generate_examples_index.sh`**: ensure `archipelago.js`
  + `rando_bridge.js` deploy alongside the demo and the connect form renders.
- No APCpp / `-lssl` / IXWebSocket in the WASM link — all bypassed.

## 8. Verification plan

1. Stand up a local AP server (Archipelago) with a trivial game slot.
2. Build a WASM smoke demo from the Phase 1 `rando_smoke` AS (or a small variant
   that *does* call `connect()`), `WITH_AP=1`, with the vendored JS + form.
3. In-browser: connect via the form; confirm `isConnected()` flips true,
   `receivedItemsSize()` reflects granted items, `sendLocation(id)` registers a
   check server-side, `locationIsChecked(id)` then returns true.
4. Repeat with AS-driven `rando.connect()` (no form) to confirm the hybrid path.

## 8b. As-built (2026-05-31)

Implemented:
- `SWFModernRuntime/src/actionmodern/rando_ap_wasm.c` — EM_JS thunks over
  `window.__randoBridge`, guarded `WITH_AP && __EMSCRIPTEN__`. Built **instead of**
  `rando_ap.cpp` in the WASM target (each build copies exactly one impl, so the
  `rando_ap.h` symbols are never doubly defined).
- `SWFRecomp/wasm_wrappers/rando/archipelago.js` — vendored ThePhar
  archipelago.js v2.1.0.
- `SWFRecomp/wasm_wrappers/rando/rando_bridge.js` — ES-module glue exposing
  `window.__randoBridge` (init/connect/isConnected/receivedItemsSize/receivedItem/
  hasItem/locationIsChecked/sendLocation/storyComplete + `connectFromForm`),
  hybrid connect with idempotency guard.
- `ruffle-tests/verify_output.py`: `compile_wasm` WITH_AP gate (copy `rando.c` +
  `rando_ap_wasm.c`, `-DWITH_AP`); `deploy_wasm` ships the JS assets + injects the
  bridge module `<script type="module">` and an HTML connect form. Also added
  `video_codec.c` to the WASM `core_sources` (action.c references
  `video_codec_supported`; normal builds survived on DCE — the WITH_AP build
  surfaced the latent gap; matches `compile_native`).
- `SWFRecomp/scripts/build_test.sh`: target-aware copy (`rando_ap_wasm.c` for
  wasm, `rando_ap.cpp` for native) + `-DWITH_AP` + stages the JS assets next to
  the wasm output.

Verified: `WITH_AP=1 verify_output.py --test=rando_smoke
--tests-dir=ruffle-tests/tests/swfs/_rando --wasm --deploy-dir=…` →
**builds, links, runs (PASS), and deploys** the page with the bridge module,
connect form, and both JS assets. In the headless test-run (node, no bridge)
`new Rando()` gracefully no-ops to the same `function/object/false/0/false/false`
as native. A normal (non-AP) `typeof` WASM build still passes (video_codec.c
addition caused no regression).

Demo viewer (2026-05-31, done): `rando_panel.js` is a self-contained connect
panel (the single UI source). `docs2/demo.html` HEAD-probes `rando_bridge.js` and,
if present, loads the bridge module + panel — non-AP demos never see it.
`build_test.sh` (wasm) stages all three JS assets into the build dir;
`deploy_example.sh` already copies `*.js` to the deploy dir. `verify_output.py`'s
`deploy_wasm` loads the same `rando_panel.js` (replaced its earlier inline form,
so there's one UI source). Verified: the deployed page ships archipelago.js +
rando_bridge.js + rando_panel.js and loads bridge+panel.

Live-server browser test (2026-05-31, done + automated): the §8/§11 round-trip is
covered by `ruffle-tests/tests/swfs/_rando/livetest/browser/run_browser_livetest.sh`
(headless chromium via Playwright → `window.__randoBridge` → real AP server).
Asserts connect + starting item 80002 + `sendLocation(81001)` checked + granted
item 80000. Unlike native APCpp, archipelago.js does not filter own-location
items, so 80000 appears in received items here. Not in CI (network timing); needs
Archipelago-CC + Playwright. See `ruffle-tests/tests/swfs/_rando/README.md`.

## 9. Open questions (defer until bring-up)

- **archipelago.js load form**: ESM `import` vs a classic `<script>` exposing a
  global. `rando_bridge.js` needs a concrete handle to the `Client` constructor;
  pick whichever the vendored bundle makes simplest.
- **Multiple `Rando` instances**: JS keeps an id→Client map; default is one
  singleton Client per page. Generalize only if a demo needs it.
- **Reconnect/error UX** in the demo (status text, retry button) — cosmetic,
  post-bring-up.
- **DeathLink / messages / slot-data** — all deferred (not in the POD subset).

## 10. References

- Seam + Phase 1: `archipelago-randomizer-integration.md`;
  `SWFModernRuntime/include/actionmodern/rando_ap.h`.
- JS transport + integration prior art: `~/CC/flash-ap-api`
  (`archipelago.js`, `ap_flash_client.js`, `README.md`).
- WASM build: `ruffle-tests/verify_output.py::compile_wasm`;
  `SWFRecomp/scripts/build_test.sh` (wasm path);
  `SWFRecomp/wasm_wrappers/index_template.html` (+ `_graphics`), `main.c`.
- EM_JS precedent: `SWFModernRuntime/src/audio/audio_output_web.c`,
  `src/rendering/render_webgpu.c`.
