# Phase 3 Slice 3 — reconciliation: AVM1 `Rando` games as a procgen *substrate*

> **SUPERSEDED 2026-05-31** by Archipelago-CC's
> `NewDocs/plans/procedural-generation/swfrecomp-substrate-converged.md`
> ("one substrate, two modes"). That plan collapses this note's **Track A / Track B**
> split: there is **one** `swfrecomp` substrate defined by a stable JS bridge
> contract (`window.__swfBridge`), with an opaque-fixed-minigame **mode 1** (ships
> now, AVM1) and a procgen-content **mode 2** (later, AVM2-gated) — *modes, not
> tracks*. Embed = iframe via `iframeAdapter`. The convergence rests on the finding
> recorded in **"AS→JS outward-call experiment"** below (the cooperative AS→JS path
> works in the recompiled WASM runtime, so injected AS can fulfill the bridge for
> AVM1 — the `Rando` C builtin is no longer required). This note is kept for the
> reasoning trail; the converged plan is the plan-of-record.

**Status: RECONCILIATION / ROUGH PLAN, 2026-05-31 (superseded — see banner).** Output
of a cross-repo design discussion. Reconciles our Phase 1–2 work (AVM1 native
`Rando` builtin, shipped + live-tested) with the Archipelago-CC procgen system and
its existing `NewDocs/plans/procedural-generation/swfrecomp-substrate.md`
plan-of-record. Implementation belongs in **Archipelago-CC**, coordinated with that
repo's owner, in a fresh session. This note is the handoff artifact, not an
implementation.

See [archipelago-phase3-substrate-and-item-application.md](archipelago-phase3-substrate-and-item-application.md)
for Phase 3 Slices 1–2 (done) and the original (now-superseded for Slice 3)
"flashPanel sibling" framing.

## The decision

**AVM1 SWFRecomp games integrate with Archipelago as a procgen *substrate* — a
reusable component within a generated world — NOT as standalone apworlds, and NOT
via the flashPanel full-game path.** (Maintainer direction, 2026-05-31: the only
worthwhile way to integrate AVM1 games is as substrates/"minigames" for the
procgen system.) This is the right level: most games actually worth full-apworld
integration are AVM2, which is a separate track (below).

## Two complementary tracks (not competing)

| | **Track A — AVM2 full-game** (existing AP-side plan-of-record) | **Track B — AVM1 substrate** (this note) |
|---|---|---|
| Plan | `swfrecomp-substrate.md` (AP-side, 2026-05-07) | this note |
| Target | AS3/AVM2 Flixel games (Seedling, Robot Wants) | AVM1 cooperative-`Rando` games |
| Integration | inject `BridgeGeneric.as`, host pokes game memory (path-walking) | game's AS calls the native `Rando` builtin cooperatively |
| SWFRecomp role | runtime swap (replace Flash Player) | the whole stack (already working) |
| AP shape | a full apworld per game | a **substrate** (component) inside a procgen world |
| Gating | the **AVM2 milestone** (~months; AVM2 support may start in SWFRecomp soon) | none — works now on AVM1 |

`swfrecomp-substrate.md` predates the procgen system and explicitly lists AVM1 as
a v1 non-goal — consistent with this split. Track A stays the priority for
"games worth integrating" (mostly AVM2). Track B is the worthwhile niche for AVM1:
small cooperative games as procgen substrate components. Keep them distinct (incl.
module names — e.g. Track A `swfrecompSubstrate` vs Track B `avm1RandoSubstrate`);
both reference SWFRecomp-CC. When AVM2 lands in SWFRecomp, the substrate approach
here may generalize to AVM2 cooperative games too.

## Why "substrate" is the right contract (correcting the flashPanel detour)

The procgen pipeline (`pipeline-overview.md`) tags each region with a `substrate`;
a stage-4 dispatcher routes per-region game-data generation to that substrate's
generator, which emits a **playable payload** and may tighten the region's access
rules; at runtime the substrate renders the payload and reports location checks.
Substrates register via `frontend/modules/shared/procgen/substrateRegistry.js`
(see textAdventureSubstrateWrapper). That registry — **not** flashPanel — is the
contract for a component-within-a-world. (flashPanel is Track A's full-game embed:
in-page `<object>`/Ruffle + `getItemQueue`/`stateChanged` memory injection — the
wrong analog for a cooperative AVM1 substrate.)

## What Phase 1–2 already provides for Track B

Proven and reusable as the substrate's *runtime mechanism*:

- **Native `Rando` AVM1 builtin + glue** — `item id → flash_name → effect`
  application and `in-game event → sendLocation`. Proven deterministically
  (Slice 1, `rando_item_application` via the `rando_stub.c` backend) and **live in
  a real browser** against a real AP server (Slice 2b, `rando_browser_toy` —
  graphics WASM, headed Chrome).
- **Graphics-WASM-in-browser path** — the only runtime that paces frames in real
  time (ASYNCIFY + `emscripten_sleep`), which is what lets a live connection work.
- **Config vocabulary** — `ap_items` (id→flash_name) / `ap_locations`
  (flash_name→id), shared with flashPanel's per-game JSON. Maps a region's
  procgen locations ↔ in-game objectives.
- **Pluggable transport seam** (`rando_bridge.js`: `WebSocket` / `Stub` / factory)
  — the place to add the **host transport** below.
- **Automated browser test recipe** — headed `/usr/bin/google-chrome` via
  WSLg/`DISPLAY` on a localhost page (Playwright's headless chromium has no WebGPU).

## What a Track-B substrate needs (new, in Archipelago-CC)

1. **A substrate registry entry** (sibling to `textAdventureSubstrateWrapperLibrary.js`):
   `id` (e.g. `avm1_rando`), `label`, `panelComponentType`, `loadRegionEvent`,
   `supportedFeatures`, `deserializeWorld`, `getPlaybackController`. `supportedFeatures`
   is likely **minimal** — `arbitrary_ap_locations` yes; `nesw_exits` /
   `region_topology_from_source` **no** (a minigame region is opaque — it doesn't
   expose a sub-region graph).
2. **A runtime panel** that loads the recompiled WASM game (graphics build), drives
   it from the region payload, applies received items via the Rando glue, and
   dispatches `user:locationCheck` when in-game objectives complete.
3. **The host transport** (the Slice-1 seam's third arm, "Topology B / Model Y"):
   re-point `__randoBridge` from its own WebSocket to the **host as AP client** —
   read received items from the procgen player's state snapshot, route
   `sendLocation` → `dispatcher.publish('user:locationCheck')`. flashPanel is
   in-page (direct calls, no postMessage); the substrate could be in-page likewise,
   or iframe via the existing `iframeAdapter` (`STATE_SNAPSHOT` /
   `PUBLISH_EVENT_DISPATCHER`). **In-page is simpler; decide at implementation.**
4. **Build-time generation** — `generateRegionCore` / `placeFromItems` /
   `placeFromRules` / `extractPathsAndObstacles` / `serializeWorld`. For an opaque
   minigame substrate these are likely thin: a region = one minigame instance,
   parameterized (difficulty/variant) per region; the region's locations = the
   game's objectives. **Procgen-generating the game's actual content is the hard,
   deferred version; fixed-game-parameterized-per-region is the worthwhile first
   cut.**
5. **Playback-bot support** — the bot must drive the substrate (complete objectives
   / walk to locations). The text-adventure substrate's `PlaybackController` is the
   prior art.

## Open questions (for the AP-side owner)

- **Granularity:** is one region ↔ one minigame instance, with the region's
  locations = the minigame's objectives? Or can a minigame span/gate multiple
  regions? This sets the `generateRegionCore` / location-mapping shape.
- **Build-time content:** fixed minigame parameterized per region (simple, first
  cut) vs procgen-generated game content (hard, deferred). Confirm the first cut.
- **`supportedFeatures`** for an opaque minigame substrate — minimal set TBD.
- **Embed model:** in-page (direct `__randoBridge` calls, like flashPanel) vs
  iframe (`iframeAdapter` `STATE_SNAPSHOT`/`PUBLISH_EVENT_DISPATCHER`). In-page is
  simpler; iframe matches the substrate-registry precedent (textAdventure).
- **Host-transport contract:** exact API for "read received items" + "report a
  check" the substrate uses against the procgen player / stateManager.
- **WebGPU/automation:** the graphics-WASM substrate needs real WebGPU (headed
  Chrome via WSLg). How does Archipelago-CC's own test/playback harness run it?
- **Naming / non-collision** with Track A's `swfrecompSubstrate` (AVM2 full-game).
- **AVM2 generalization:** when AVM2 lands in SWFRecomp, does this substrate
  approach extend to AVM2 cooperative games (vs Track A's injection model)?

## Sequencing / ownership

- This is a **cross-repo** effort owned on the Archipelago-CC side. Our (SWFRecomp-CC)
  contribution is the substrate's **runtime**: the recompiled WASM game + the Rando
  glue + the **host transport** added to `rando_bridge.js`. The substrate registry
  entry, panel, build-time adapters, and playback live in Archipelago-CC.
- **Implement in a fresh session rooted in Archipelago-CC**, coordinated with that
  repo's owner — this session holds the SWFRecomp context but the module is AP-side
  frontend code with an existing plan-of-record to reconcile against.
- **Next concrete step:** sync with the AP-side owner on the granularity + embed +
  build-time-content questions above; from those answers, the substrate's
  registry-entry + panel shape falls out, and the only SWFRecomp-CC code change is
  the host transport in `rando_bridge.js` (the seam already exists).

## AS→JS outward-call experiment (2026-05-31) — resolved the converged plan's decisive question

The converged plan asks whether SWFRecomp's recompiled output can make a
**cooperative AS→JS *outward* call** (game AS → JS, not just JS→AS injection). If
yes, injected AS fulfills the `__swfBridge` contract and the `Rando` C builtin can
be dropped. **Experiment result: YES** (for AVM1).

Findings:
- The `ruffle-inject` demos do **not** answer this — they run in **Ruffle** (the
  real Flash player, full native `ExternalInterface`), not SWFRecomp's recompiled
  C/WASM runtime.
- But the recompiled runtime **already implements `flash.external.ExternalInterface`**
  on the AVM1/AS2 path — `available` / `addCallback` / `call`
  (`SWFModernRuntime/src/actionmodern/action.c:5596+`), with the outward call
  delegating to a pluggable `g_external_call_handler`. It was only ever wired by a
  **native mock test harness** (`ruffle-tests/tests/swfs/avm1/external_interface/test_harness.c`);
  in the WASM/browser build the handler was NULL → `available` false, `.call` a no-op.
- **Probe (run then reverted):** added a minimal `#ifdef __EMSCRIPTEN__` `EM_ASM`
  handler forwarding `ExternalInterface.call(name, arg0)` → `window[name](arg0)`,
  built a probe SWF (`ExternalInterface.call("swfEiProbe", "hello-from-as")`) as
  graphics WASM, ran it in headed google-chrome. Result:
  `[ei] available=true` and `EI_PROBE_CALLED:hello-from-as` — the outward call
  reached `window` with its argument. The probe (`action.c` change +
  `SWFRecomp/tests/ei_outward_probe/`) was **reverted** after confirming; it was a
  capability probe, not the feature.

### Inward read (PULL) experiment (2026-05-31) — the unproven half, now proven

The converged plan flagged the **inward host→game read (`pollItems`)** as "the part
still entirely unproven" and asked for a deliberate mechanism choice. Decision:
**pull (EI return value)**, not push (`addCallback`) — it reuses the proven outward
path, adds only return-value marshaling (a contained unknown), avoids JS→AS
reentrancy mid-frame, and fits the frame-based game model (next-frame latency is a
non-issue). Both satisfy the AP contract identically (the AP `bridge.js` calls
`__swfBridge.pollItems(items)` regardless; how it routes to AS is SWFRecomp-CC's
internal choice).

**Probe (run then reverted):** extended the `#ifdef __EMSCRIPTEN__` handler so
`ExternalInterface.call("__swfPoll")` returns the JS items-queue **string**
(marshaled JS→AS as a UTF-16 `ActionVar` via `ascii_to_u16`). A probe SWF polled
`__swfPoll` each frame via `onEnterFrame`; the harness delivered
`'["sword","key"]'` to `window.__swfPoll`'s queue ~1.5s after start (simulating
async item arrival). Result in headed google-chrome: `[ei] available=true`, then
on a later frame `POLLED:["sword","key"]` — the inward read worked end-to-end in
the live frame loop. Reverted after confirming (`action.c` + `tests/ei_pull_probe`).

**Both halves of the `__swfBridge` contract are now proven on the AVM1 recompiled
runtime via injected/cooperative AS:** outward `sendLocation` (EI `.call` → window)
and inward `pollItems` (EI `.call` return value ← window). So **option 1
(injected-AS via `ExternalInterface`, both directions) is fully de-risked** — the
Phase-1 mechanism question is settled (injected-AS, pull for inward), and the
`Rando` C builtin is not needed (stays a fallback).

Implications:
- **"Yes" branch is viable.** The AS→JS outward seam is architecturally present and
  natively tested; only a small EM_JS browser handler was missing. So injected /
  cooperative AS can fulfill the bridge for AVM1 — **the `Rando` C builtin is no
  longer required** (it remains a working, live-verified fallback — Phase 2b).
- **The real SWFRecomp-CC change** is still the host-transport `__swfBridge` surface
  (`configure`/`pollItems`/`sendLocation` over the iframeAdapter path) — a more
  specific interface than this generic `ExternalInterface` probe. The probe proved
  the *enabling capability*; production marshaling (multi-arg, return values,
  inward `addCallback`→JS) lands in the coordinated Slice-3 implementation.
- **AVM2 caveat:** the EI implementation exercised is the AVM1/AS2 path. AVM2/AS3
  fulfillment (mode 2) is gated on AVM2 support existing at all — unchanged.

The converged plan's §"Open question that decides the SWFRecomp-CC side" can be
marked resolved (Yes) on the AP side — flagged here for that doc's owner.

## Phase 1 / Mode 1 — PRODUCTION IMPLEMENTATION (2026-05-31) — DONE (deliverables 1–3), DELIVERABLE 4 coordination-gated

The reverted probes are now the committed production version. SWFRecomp-CC-rooted
deliverables 1–3 are implemented and **verified live end-to-end in headed Chrome**
(8/8 assertions PASS); deliverable 4 (the cross-repo `SWF_IFRAME_SRC` swap) is
surfaced for coordination (see below).

**1. Production EI browser handler (`SWFModernRuntime/src/actionmodern/action.c`).**
`swf_browser_external_call` (under `#ifdef __EMSCRIPTEN__`, ~after `actionEI_call`)
forwards `ExternalInterface.call(name, arg0)` → `window[name](arg0)` and marshals a
string return value back to AS (`stringToUTF8`/`lengthBytesUTF8` into a C buffer →
`utf8_to_u16` → string ActionVar). It is installed in `ensureGlobalInit` **only when
the page exposes `window.__swfBridge`** (the chosen opt-in gate — a page-set window
flag, no `-D` flag, no separate build): an `EM_ASM_INT` check sets
`g_external_call_handler` before `initFlashPackage` snapshots `available`. Browser
demos that don't load the shim keep the handler NULL → `ExternalInterface.available`
stays false → **zero behavior change** for every existing graphics-WASM demo. All of
this is `__EMSCRIPTEN__`-only, so NO_GRAPHICS/OFFSCREEN_RENDER trace + graphics-native
suites (and their CI) are unaffected.

**2. The `__swfBridge` contract shim (`SWFRecomp/wasm_wrappers/swf_bridge.js`).**
Installs `window.__swfBridge = { configure, pollItems, sendLocation }` (the AP-facing
contract) plus three EI-facing top-level window fns the game's AS calls:
`__swfConfig()` (returns config JSON — inward pull), `__swfPoll()` (returns
comma-separated received flash_names then drains — inward pull), `__swfSendLocation(name)`
(routes to `__swfBridge.sendLocation` — outward). `configure().ap_items` (AP item
name → flash_name) is applied by the shim so the game only ever sees flash_names; the
substrate owns the name maps. Staged into every wasm build by `build_test.sh` (inert
unless the page's HTML loads it).

**3. Mode-1 minigame (`SWFRecomp/tests/swfbridge_toy/`).** `Main.as` — the
rando_browser_toy adapted to the EI/`__swfBridge` contract instead of the `Rando`
builtin (no WITH_AP, no WebSocket, no AP server). Reads config once, reports two
objectives (`chest`/`enemy`) outward, polls + applies received items (`sword`/`key`)
each frame, traces `[toy] DONE`. Compiled with MTASC std8 (has
`flash.external.ExternalInterface`); the class is referenced through an untyped
`Object` so the variadic AVM1 `call` isn't rejected by the 1-arg intrinsic.

**Live test (no AP server needed):**
`ruffle-tests/tests/swfs/_swfbridge/livetest/toy_browser/` — `harness.html` loads the
shim + graphics-WASM minigame and a **mock host** standing in for Archipelago-CC's
`bridge.js` (overrides `__swfBridge.sendLocation` to record, calls `configure`,
delivers items via `pollItems` ~1.2 s in). `toy_test.js` drives headed
`/usr/bin/google-chrome` (WebGPU via WSLg/DISPLAY) and asserts the full round-trip;
`run_toy_livetest.sh` builds + serves + drives. **RESULT: PASS** — `EI available=true`,
configure reached the bridge, host recorded `sendLocation("chest")` + `("enemy")`,
both items pulled + applied, `[toy] DONE`. (Requires interactive DISPLAY; not CI.)

**4. Swap-in (`Archipelago-CC` `swfrecompSubstratePanel.js` `SWF_IFRAME_SRC`) —
COORDINATION-GATED, not yet done.** Two real blockers make a naive hard-swap break the
AP side, so it needs the AP-side owner's call:
- The AP e2e Leg 2 (`frontend/modules/tests/testCases/swfrecompSubstrateTests.js`)
  clicks a button **rendered by the placeholder page** and waits for "placeholder
  rendered the objective button" — the real minigame has no such button (it auto-fires
  via EI), so pointing `SWF_IFRAME_SRC` at it breaks that test as written.
- The real page is a **graphics-WASM build needing WebGPU**; the AP in-app test harness
  must run it in headed Chrome (WSLg/DISPLAY) for the chain to execute at all — the
  placeholder runs anywhere because it's pure JS.
Recommended shape (for the AP owner): keep the placeholder as the default test target,
add the real recompiled-game page as an opt-in/parameterized `SWF_IFRAME_SRC` (or a
separate "live" preset), and add a headed-Chrome e2e leg for it — rather than a global
swap. The recompiled-game page itself is just `harness.html` minus the mock-host script
(the page exposes `__swfBridge`; AP's injected `bridge.js` plays host).

## `__swfBridge` is RUNTIME-NEUTRAL — confirmed empirically under Ruffle web (2026-06-01)

Archipelago-CC's unified `flashSubstrate` wants to run the same `__swfBridge`
contract under multiple runtimes (SWFRecomp WASM **and** Ruffle/native Flash).
Confirmed empirically that the **same** `swf_bridge.js` shim + the **same** AVM1
minigame (`swfbridge_toy/test.swf`) round-trip identically under **Ruffle web** —
so Ruffle is a drop-in runtime behind the same shim, no in-page adapter needed.

**Harness:** `ruffle-tests/tests/swfs/_swfbridge/livetest/toy_browser/`
`ruffle_harness.html` + `ruffle_test.js` + `run_ruffle_livetest.sh`. Identical to
the WASM harness except it embeds `test.swf` in Ruffle (the official
`@ruffle-rs/ruffle` selfhosted CDN bundle — the exact loader `docs/demo.html`'s
"View in Ruffle" / Compare tool uses) instead of the SWFRecomp WASM module; same
`swf_bridge.js`, same mock host. `allowScriptAccess: true` set (required for EI).
No WASM build, no AP server — only MTASC + the CDN.

**Result: 8/8 PASS** (headed google-chrome, Ruffle 0.2.0, AVM1/SWF8):
`ExternalInterface.available=true`, host `configure()` reached the bridge, the game
sent both objectives **outward** (`EI.call("__swfSendLocation", flashName)` →
`window.__swfSendLocation` → host recorded `chest`/`enemy`), and the **inward
return-value pull** worked (`EI.call("__swfPoll")` → JS string `"sword,key"`
marshaled back to AVM1 → split + applied → `[toy] DONE`). Matches the WASM
livetest's 8/8 exactly. This validates the source analysis: Ruffle web's
`callExternalInterface` resolves the method name as `new Function("return (<name>)(...)")`
= a window-scope lookup, the same resolution the SWFRecomp `EM_ASM` handler does, so
the top-level `__swfPoll`/`__swfConfig`/`__swfSendLocation` fns resolve identically.

**Only divergence (not the contract — observability plumbing):** AVM `trace()`
visibility. The SWFRecomp WASM runtime emits trace via `printf` straight to the
console; Ruffle defaults `logLevel: Error` and surfaces AVM trace only through its
`avm_trace` channel — set `logLevel: 'info'` (the per-player `traceObserver` setter
did **not** fire in the 0.2.0 unpkg bundle). No divergence in return-value
marshaling, arg coercion, or `available` gating (all true with `allowScriptAccess`).
AVM2/AS3 was not exercised (the toy is AVM1, matching Mode 1).

## Memory-poke (`readState`) over the iframe boundary — confirmed, both runtimes (2026-06-01)

The unified `flashSubstrate` plan
([flash-substrate-unification.md](file:../../../Archipelago-CC/NewDocs/plans/procedural-generation/flash-substrate-unification.md))
needs the *other* integration style — flashPanel's **memory-poke**: the host polls
the game's live state instead of receiving cooperative reports. flashPanel's actual
mechanism is the **host-initiated `addCallback` direction** — the SWF registers
`ExternalInterface.addCallback("configure"/"readState"/"wireCheck")` and JS calls
those (e.g. `player.readState()` → a JSON string of walked fields). This is the
*opposite* EI direction from the cooperative `__swfPoll` pull (which is AS-initiated
`ExternalInterface.call` → `window[name]`). The narrow question: does the heavier
**configure-in / readState-out** round-trip (multi-field nested JSON) survive the
**iframe** boundary under both runtimes?

**Probe:** `ruffle-tests/tests/swfs/_swfbridge/livetest/toy_browser/` —
`memprobe` (AVM1 stand-in: registers the three callbacks; `configure` echoes its arg
back; `readState` returns a realistic ~10-field JSON with mixed types, a nested
object + array, and a non-ASCII field `café→☃`). `mem_parent.html` mounts two
sandboxed (`allow-scripts allow-same-origin`) game-page iframes (Ruffle +
SWFRecomp), and the host calls `configure(cfg)` + `readState()` **across the iframe
boundary** into each. `mem_test.js` / `run_mem_livetest.sh` drive headed Chrome.
The real `BridgeGeneric.as` walker is AS3/AVM2 — which SWFRecomp can't run yet — so
the stand-in is AVM1 (the stub result is the load-bearing answer; walker-vs-runtime
is deferred).

**Result: 7/7 PASS on BOTH runtimes.** `configure(cfg)` echoed the full 241-char
config intact (size + UTF on IN); `readState()` returned the full nested JSON
across the boundary with all fields, correct JS types, nested object+array, the
non-ASCII field, and `cfg_len` matching — no truncation, no encoding loss, no
size/marshaling divergence from the single-string `__swfPoll` case. So
**memory-poke games can use the same iframe path as cooperative games** → rung 1 of
the unification plan's risk ladder; no `embed:'in-page'` fallback needed for the
transport.

**Two SWFRecomp-specific notes (Ruffle needed neither):**
1. **A new runtime primitive was required.** SWFRecomp's WASM build only exposed the
   AS-initiated *outward* EI direction (the cooperative `__swfBridge` handler);
   host-initiated calls into `addCallback`'d AS functions were not JS-reachable (a
   deliberate choice to avoid JS→AS reentrancy for the pull contract). Added
   `swf_ei_call_internal` (KEEPALIVE export in `wasm_wrappers/main.c`): JS calls
   `Module.ccall('swf_ei_call_internal', 'string', ['string','string'], [name, arg])`,
   it builds a string `ActionVar`, invokes the registered callback via the existing
   `actionEI_callInternalInterface`, and returns the string result as UTF-8. Ruffle
   exposes this natively (`addCallback` defines `player[name](...)` on the element).
   Safe because the graphics frame loop parks at `emscripten_sleep` between frames,
   so the call runs on a clean wasm stack and never itself suspends — the same
   quiescent window flashPanel polls in.
2. **Graphics renderer needs an in-iframe user gesture.** SWFRecomp's WebGPU
   renderer init stalls in a sandboxed auto-start iframe (the `renderer_init`
   `emscripten_sleep` consumes a user activation that an iframe load doesn't grant);
   the probe clicks a start button inside the iframe. This is a *rendering-init*
   constraint, not an EI one — the AP panel mounts the game with a real user
   interaction anyway. (build_test.sh's NO_GRAPHICS-wasm path is independently
   broken — `ng_shared.c` lacks an `ng_find_textfield` declaration — so the graphics
   build is the path; the EI bridge itself is renderer-agnostic.)

## Converging the native C Rando library onto `__swfBridge` (2026-06-01)

**Decision (with the AP owner):** the native C Rando path adopts the **same
`__swfBridge` cooperative EI interface** the browser + Ruffle use, rather than its
bespoke `Rando` builtin class — so games speak one interface on every runtime and
only the installed handler differs. Settled: use the **thin `__swfBridge`
contract** (not the rich Rando API); **defer the goal/`storyComplete` signal**
(additive on both ends — a `__swfBridge` method + an AP-side dispatch — not a
blocker); **no migration** (no games use either system yet); expect interface churn.

**Feature comparison (Rando API vs `__swfBridge`):** at the EI *mechanism* level
there are no gaps. Against the thin 3-method *contract*, the differences are
connection management (`connect`/`isConnected`/auth params) and the read-back
queries (`hasItem`/`locationIsChecked`) — both **deliberately relocated to the
host** (substrate topology = host owns the AP connection, not the game) — plus
`storyComplete`, the one genuinely-absent capability (no AP-side event either),
deferred. The thin contract is also all **≤1 string arg + string return**, so it
needs **no marshaling changes** (the multi-arg/typed-return work would only have
been for the rich Rando API).

**Slice 1 — DONE 2026-06-01.** Native production `__swfBridge` EI handler, proven
deterministically:
- `swf_bridge_native_external_call` in `action.c` (guarded
  `#if defined(WITH_AP) && !defined(__EMSCRIPTEN__)`, alongside
  `swf_browser_external_call`) — a **C port of `swf_bridge.js`**: it holds the
  `ap_items` (AP id → flash_name) + `ap_locations` (flash_name → AP id) maps +
  connection params loaded from a **JSON config file** (minimal in-file C JSON
  reader), and implements `__swfConfig` / `__swfPoll` (drains rando_ap received
  items, maps ids → flash_names) / `__swfSendLocation` (maps flash_name → AP id →
  `rando_ap_send_location`) over the existing `rando_ap.h` seam. The game's AS only
  ever deals in flash_names — identical to the browser model.
- Installed by an `ensureGlobalInit` gate keyed on the `SWF_BRIDGE_CONFIG` env var
  (native analog of the browser's `window.__swfBridge` gate); native builds without
  it keep the handler NULL / `available=false`, so the existing APCpp livetest
  harnesses are unchanged. `verify_output.py` sets the env var when a test ships a
  `swf_bridge_config.json`.
- Test: `ruffle-tests/tests/swfs/_rando/swfbridge_native_stub` — the AS uses
  `ExternalInterface.call("__swf…")` (not `new Rando()`), built with `RANDO_STUB=1`
  (synthetic backend). Deterministic **PASS**: `available=true` → config loaded →
  `__swfPoll` → Sword applied → `__swfSendLocation("chest")` → stub grants Key →
  `__swfPoll` → Key applied → DONE. The EI-based sibling of `rando_item_application`.
- Zero impact on the normal suite: all new code is `WITH_AP`-gated (CI builds
  without WITH_AP don't even compile it); confirmed the non-AP path still compiles
  + passes.

**Slice 2 — LIVE native over APCpp — DONE 2026-06-01.** The native `__swfBridge`
handler now drives **real APCpp against a live Archipelago server**, proven
end-to-end:
- **Block-until-connected** added to `sbn_load_config` (native has no wall-clock
  frame pacing — the Slice-2b flat-out-frames issue — so a frame-based SWF can't
  await an async connect). After `rando_ap_connect` it polls `rando_ap_is_connected`
  (bounded, `SWF_BRIDGE_CONNECT_TIMEOUT_S`, default 20s) then a short settle window
  (`SWF_BRIDGE_SETTLE_MS`) **only if it actually waited** — so the synchronous stub
  (connected immediately, zero waits) is untouched and slice-1 stays fast +
  deterministic; only a real async backend (APCpp) waits.
- **`__swfLocationChecked(flash)`** read-back added to the handler (maps flash → AP
  id → `rando_ap_location_is_checked`, bounded ~5s poll for the async ack). The
  native-standalone analog of Rando's `locationIsChecked`; the browser substrate's
  host observes checks instead, so it's native-only (the browser handler would
  forward it to a `window` fn that doesn't exist → null).
- Test `_rando/swfbridge_native_live` + `livetest/run_swfbridge_native_livetest.sh`:
  starts a local ChecksFinder seed-1 server (Archipelago-CC venv), runs the test
  under `WITH_AP=1 verify_output.py` (links APCpp), asserts the **outward
  round-trip** — `__swfSendLocation("tile2")` → AP loc 81001 → server acks →
  `__swfLocationChecked("tile2") == "true"` → DONE. **PASS** (headless — native
  NO_GRAPHICS needs no DISPLAY). Not in CI (needs a live server).
- **Finding — inward items aren't observable in a solo seed:** APCpp filters the
  player's own-location item grants out of `received_items`, and the current
  ChecksFinder seed delivers no starting inventory (confirmed: the existing
  `rando_ap_livetest.c` also gets `received_items_size=0`), so `__swfPoll` has
  nothing to apply natively in a solo seed. The live test therefore asserts the
  outward (send → checked) round-trip, which does work. Observing inward items live
  would need starting inventory or a multi-slot seed (cross-player items aren't
  filtered) — orthogonal to this slice. In the real substrate the **host** observes
  received items, so this isn't a gap for the substrate topology.

**Open / deferred:** (a) native connection ownership — settled in practice as
"live native APCpp-as-client works" (slice 2); deterministic stub remains for CI.
(b) retire the native `Rando` builtin class + its WASM Phase-2 path
(`rando_ap_wasm.c` / `window.__randoBridge`) once the EI path fully replaces them
(kept compiling for now; nothing forces deletion yet). (c) the `storyComplete`/goal
signal.
