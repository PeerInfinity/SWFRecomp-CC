# Phase 3 Slice 3 — reconciliation: AVM1 `Rando` games as a procgen *substrate*

**Status: RECONCILIATION / ROUGH PLAN, 2026-05-31.** Output of a cross-repo design
discussion. Reconciles our Phase 1–2 work (AVM1 native `Rando` builtin, shipped +
live-tested) with the Archipelago-CC procgen system and its existing
`NewDocs/plans/procedural-generation/swfrecomp-substrate.md` plan-of-record.
Implementation belongs in **Archipelago-CC**, coordinated with that repo's owner,
in a fresh session. This note is the handoff artifact, not an implementation.

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
