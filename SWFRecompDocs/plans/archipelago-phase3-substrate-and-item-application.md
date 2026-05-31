# Archipelago Phase 3 — item application, pluggable transport, and the SWF substrate

**Status:** **Planned** 2026-05-31. Depends on Phase 1 (native `Rando`, done) and
Phase 2 (WASM transport bridge, done + live-tested — see
[archipelago-phase2-wasm-bridge.md](archipelago-phase2-wasm-bridge.md) and
[archipelago-randomizer-integration.md](archipelago-randomizer-integration.md)
§8). Phase 2 made `Rando`'s data *readable* in the browser; Phase 3 makes items
*do something* and opens a second integration topology.

This plan is the output of a design discussion. The architectural decisions below
are **locked** (chosen by the maintainer); the slice ordering is the recommended
execution path.

---

## 1. What Phase 3 delivers

Two separable things, deliberately decoupled:

1. **Item application** — a received item mutates game state (e.g. "item → enable
   double jump"), and an in-game event fires a location check
   (`sendLocation`). Today the `Rando` builtin only exposes transport data; the
   glue that turns items into gameplay is new.
2. **The SWF substrate** — a recompiled SWF can run as an **iframe substrate**
   inside the Archipelago-CC frontend, with the frontend acting as the AP client
   and the SWF as an Archipelago-naive "engine." This is a second topology, not a
   replacement for the self-contained demo.

Both rest on the same insight: keep the **SWF game Archipelago-naive** (it exposes
a dumb game-state API) and put **all AP awareness in a bridge/glue layer**. That
split is also exactly the test layering (see §6).

---

## 2. The two topologies

`window.__randoBridge` (`SWFRecomp/wasm_wrappers/rando/rando_bridge.js`) is already
an in-iframe AP shim with the right surface (`init / connect / isConnected /
hasItem / receivedItem / locationIsChecked / sendLocation`). Phase 3 makes its
**transport pluggable** so the *same* AS-facing API serves both topologies:

| | **Topology A** (Phase 2, self-contained) | **Topology B** (substrate) |
|---|---|---|
| AP client | the SWF demo page itself | the Archipelago-CC frontend |
| SWF role | self-contained AP-aware game | AP-**naive** engine driven via `postMessage` |
| ITEM/LOCATION enums | AS-baked per game | **sourced from the apworld / host** |
| AP machinery (procgen, sidecars, playback, fog) | reimplemented per demo | reused for free from the frontend |
| Deployment | standalone on peerinfinity.com | iframe inside the frontend (may be a remote module) |

**Locked decision — pluggable transport (hybrid):** the same SWF build supports
both topologies; we do not have to commit to one before validating either.

**Locked decision — new SWF substrate (contract only):** we reuse the
`iframeAdapter` postMessage handshake and the substrate registry *shape* from
Archipelago-CC's `textAdventureSubstrateWrapper`, but **not** its text-adventure
engine. The SWF *is* the engine. The text-adventure module is the reference
implementation of the contract, not a thing we fork. A SWF substrate declares an
action-game-appropriate `supportedFeatures` set (`arbitrary_ap_locations` yes;
`nesw_exits` / `region_topology_from_source` no).

---

## 3. The three transports behind `__randoBridge`

The AS-visible API is unchanged; `rando_bridge.js` already separates that surface
from the archipelago.js `Client`, so the refactor introduces a transport
interface and three implementations:

1. **`WebSocketTransport`** — wraps the archipelago.js `Client` over a browser
   WebSocket. Today's behavior; powers Topology A (standalone). Default.
2. **`HostPostMessageTransport`** — implements the Archipelago-CC `iframeAdapter`
   *client* handshake; the frontend is the AP client. Powers Topology B.
3. **`StubTransport`** — feeds a synthetic received-items list with no server.
   Makes the deterministic test layer (§6, Layer 1) possible.

Transport selection: default WebSocket; `StubTransport` via test config; the
host transport auto-selected when the page detects it is running inside the
frontend's iframeAdapter handshake (else fall back to WebSocket). Exact selection
mechanism is a Slice-1 detail.

The native path (`rando_ap.cpp` → APCpp) is unaffected — pluggable transport is a
WASM/JS concern. Native item application (§5) shares the glue but keeps its own
transport.

---

## 4. Test fixture: APQuest (not ChecksFinder)

The existing native + browser livetests use **ChecksFinder seed 1** and stay on
it — they are a green transport regression guard and there is no reason to churn
them. **New Phase 3 work (toy + substrate) uses APQuest** as the apworld fixture.

Why APQuest (`~/CC/Archipelago-CC/worlds/apquest`):

- **Real region topology** (~79 region lines, ~136 locations, ~166 item lines)
  vs ChecksFinder's flat ~16-location tile-check structure. The substrate
  contract renders an apworld's `staticData.regions`; a flat world barely
  exercises it, APQuest's room graph genuinely does.
- **Human-meaningful names** (`Key`=1, `Sword`=2, `Shield`=3, `Hammer`=4,
  `Health Upgrade`=5, `Confetti Cannon`=6, `Math Trap`=7; locations like
  "Bottom Left Chest"; a dragon boss as the goal) — legible trace assertions and
  substrate UI. (These are the apworld's `*_NAME_TO_ID` local ids; actual AP
  network ids are these plus the game's base offset, read from the connected
  slot at runtime.)
- **Stable long-term fixture:** owned by Archipelago, MIT-licensed, the author
  explicitly relinquished the right to remove it, version-pinned (`1.0.1`,
  min AP `0.6.4`), and it is used by Archipelago's own unit tests.
- **Canonical, exhaustively-commented example apworld** (ships a
  `!READ_FIRST!.txt`) — the best reference while building the bridge/glue.
- **Zero extra server-setup friction:** a preset already exists
  (`frontend/presets/apquest/AP_…`), launchable identically to ChecksFinder via
  `setup_ap_server.py --game apquest --seed 1`. Substrate-test preset
  infrastructure already exists in the repo (`jta_substrate_test`).

**Caveat:** APQuest is itself "a game inside an apworld" (Python + Kivy). We do
**not** port that game. We use its *apworld* (items/locations/regions/rules) as
the randomizer definition our toy SWF connects to and renders. Its
adventure-flavored semantics suit a generic region-rendering substrate; they will
not line up with a real action game (Pong/Snake) — that is expected. Real-game
integration (Slice 4) uses a game-matched apworld.

---

## 5. The Archipelago-naive / AP-aware split + glue

- **SWF game (Archipelago-naive):** exposes a small game-state API — apply an
  effect by id, signal an in-game event. Knows nothing about AP item/location
  numbers.
- **Glue (AP-aware):** maps item id → game effect and game event → `sendLocation`.
  Lives in:
  - **Standalone (Topology A):** a **prelude SWF** recompiled *before* the game
    SWF, defining the ITEM/LOCATION enums + glue in `_global` (the Demo-4
    prelude-SWF mechanism — see
    [runtime-swf-injection-demos.md](runtime-swf-injection-demos.md); preludes
    share `_global`, var_array, and prototype chains with the main SWF). The game
    SWF is never edited.
  - **Substrate (Topology B):** the **host** supplies the enums (from the
    apworld's `staticData`) and item/location semantics; the in-iframe bridge
    translates host AP state → game-state API calls and game events → host AP
    dispatcher events. This is the **enums win** — no per-game enum baking.

ITEM/LOCATION enum sourcing is therefore transport-dependent: AS-baked in
standalone, host-supplied in substrate. The pluggable transport is the natural
home for "what does item N mean" (the host transport can answer it; the WebSocket
transport falls back to the AS-baked enum).

---

## 6. Testing — both layers (locked decision)

1. **Layer 1 — deterministic unit (no server, CI-friendly):** drive the toy
   prelude + toy game SWF through `StubTransport` with a synthetic received-items
   list. Trace-assert item application (`item → effect`) and location checks.
   Drops into the `_rando` suite next to `rando_smoke`. Deterministic; isolates
   glue/enum bugs from transport bugs.
2. **Layer 2 — live round-trip:** the same toy game against the **APQuest** seed-1
   fixture via the livetest harness (native + browser), reusing the just-shipped
   `livetest/` and `livetest/browser/` scaffolding. Proves the full real-transport
   path. Not CI (network timing), like the existing livetests.

`rando_smoke` and both ChecksFinder livetests are the regression guard during the
transport refactor: the AS-facing API is unchanged, so they must stay green.

---

## 7. Sequenced execution plan

**Slice 1 — pluggable transport + deterministic toy test (repo-local, committable). ✅ DONE 2026-05-31.**
- ✅ Refactored `rando_bridge.js` to select a transport behind the unchanged AS
  API; `WebSocketTransport` (= today) + `StubTransport`, `createTransport()`
  factory (seam for `HostPostMessageTransport` in Slice 3).
- ✅ Native synthetic backend `rando_stub.c` (third `rando_ap.h` impl), selected
  by `RANDO_STUB=1` in `verify_output.py` (plain C, no APCpp/g++ shim/link).
- ✅ Toy prelude SWF (`Prelude.as`) + game SWF (`Game.as`) in
  `_rando/rando_item_application`: config-driven ITEM/LOCATION enums + glue
  (id→flash_name→effect, per-frame poll, event→`sendLocation`), AP-naive game.
  Deterministic trace test, built with `RANDO_STUB=1`.
- ✅ `_rando/bridge_unit` — server-free Playwright `StubTransport` contract test.
- ✅ Guard: `rando_smoke` + the WebSocket browser livetest stay green.

**Slice 2 — live test against APQuest (both staged, both runtimes). Stage 2a ✅ DONE 2026-05-31.**
- ✅ **Stage 2a — transport re-point.** Both livetest harnesses parameterized by
  `[game]` (default `checksfinder`, unchanged; `apquest` added). Native:
  `rando_ap_livetest_apquest.c` (no starting item; `sendLocation(2)` + `(10)`
  round-trip; own-location items filtered by APCpp). Browser: `browser_livetest.js`
  fixture-driven (`FIXTURES` map), APQuest checks assert the granted Sword(2)/Key(1)
  (archipelago.js doesn't filter). All 4 (apquest+checksfinder × native+browser)
  PASS. Confirmed live fixture: slot `Player1`, `ap_id_offset = 0`, 0 precollected,
  Top Middle Chest(2)→Sword(2), Right Room Enemy Drop(10)→Key(1).
- ⏳ **Stage 2b — full toy-SWF live.** Adapt the toy glue for async connect +
  multi-frame polling; run the prelude/game SWF live (native WITH_AP/APCpp +
  browser WITH_AP/archipelago.js+Playwright) applying Sword/Key from the two
  checks. `run_livetest`-style harnesses (non-deterministic → not suite tests).

**Slice 3 — SWF substrate module (cross-repo, Topology B):** in Archipelago-CC, a
sibling to `textAdventureSubstrateWrapper`: a panel that iframes the SWF demo page
+ an in-iframe bridge wiring `HostPostMessageTransport` ↔ the existing
`iframeAdapter` protocol, plus a registry entry with an action-game-appropriate
`supportedFeatures` set. **Coordination point** — see §8.

**Slice 4 — real game (deferred):** apply the proven prelude/glue to a real game
(Doodle Jump / Pong / Snake), find hook points, validate in the browser via the
demo panel + a local server. Inherently a manual loop (game states are not
deterministically reachable — see the wasm-game-debugging workflow). Uses a
game-matched apworld, not APQuest.

Rationale for the ordering: Slices 1–2 are entirely within SWFRecomp-CC, need no
cross-repo coordination, and de-risk the naive/glue split before any frontend
work. Slice 1 is deterministic and committable.

---

## 8. Cross-repo coordination (Slice 3)

The SWF substrate module lives in **Archipelago-CC**, a separate repo owned by a
different Claude instance / the AP-side maintainer. The shared interface is the
**existing** `iframeAdapter` postMessage protocol and the substrate registry
contract — both already documented and implemented there
(`frontend/modules/iframe-base/iframeClient.js`,
`frontend/modules/textAdventureSubstrateWrapper/`,
`frontend/modules/shared/procgen/substrateRegistry.js`). We **conform** to them;
we do not redesign them. The in-iframe SWF bridge implements the existing client
handshake. Loading/trust model (sandbox `allow-scripts allow-same-origin`,
same-origin or remote-as-same-origin GitHub Pages) per
`CC/docs/plans/completed/external-iframe-modules.md` in that repo.

---

## 9. Open questions / risks

- **Transport auto-selection:** how the page decides WebSocket vs host vs stub —
  handshake probe, query param, or `Module` config. Slice-1 detail.
- **Game-state API shape:** the minimal "apply effect / signal event" surface the
  SWF exposes, and whether the game polls (`receivedItem(i)`) or the glue pushes
  via a callback. Validate on the toy first.
- **Enum sourcing in substrate mode:** the exact host message that supplies
  item/location id↔name + semantics, and how the bridge requests it.
- **APQuest network ids at runtime:** local `*_NAME_TO_ID` values need the
  per-game base offset; read from the connected slot rather than hard-coding.
- **`Rando` lifetime / `AP_Free`** (carried over from Phase 1): finalize hook vs
  per-session leak.
- **Substrate is a different product shape** than the standalone demo — confirm
  Topology B is wanted as a shipped target, not just a test rig.

---

## 10. References

- Phase 1/2: [archipelago-randomizer-integration.md](archipelago-randomizer-integration.md),
  [archipelago-phase2-wasm-bridge.md](archipelago-phase2-wasm-bridge.md).
- Prelude-SWF injection: [runtime-swf-injection-demos.md](runtime-swf-injection-demos.md)
  (Demo 4, `demos/runtime-swf/prelude_swf/`).
- Bridge + livetests: `SWFRecomp/wasm_wrappers/rando/{rando_bridge.js,rando_panel.js,archipelago.js}`,
  `ruffle-tests/tests/swfs/_rando/livetest/` (native) and `livetest/browser/` (Playwright).
- Smoke test: `ruffle-tests/tests/swfs/_rando/rando_smoke`.
- Archipelago-CC: `~/CC/Archipelago-CC` —
  `worlds/apquest/` (fixture apworld), `frontend/presets/apquest/` (server preset),
  `scripts/setup/setup_ap_server.py` (server launcher),
  `frontend/modules/textAdventureSubstrateWrapper/` (substrate contract reference),
  `frontend/modules/textAdventureEngine/` (AP-naive engine reference),
  `frontend/modules/iframe-base/iframeClient.js` (iframeAdapter client),
  `CC/docs/plans/completed/external-iframe-modules.md` (iframe trust/loading model).
