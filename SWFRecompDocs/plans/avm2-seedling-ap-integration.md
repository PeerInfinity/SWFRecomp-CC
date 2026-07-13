# AVM2 Seedling — Archipelago integration options (analysis + decision)

Status: **ANALYSIS / DECISION DOC** (2026-07-13). Investigates whether the
existing ActionScript-injection work (flash-ap-api / SeedlingArchipelagoInjector /
Archipelago-CC flashPanel) is useful to the SWFRecomp AVM2 Seedling plan, and
evaluates a third option — modifying Seedling's AS3 source and recompiling.

No implementation here. This records what's reusable, the one blocking gap, and a
recommended path, so the AP track can be scheduled deliberately once the AVM2
render/browser work (Stage 12/13) lands.

Related: `avm2-seedling-plan.md` (§2 endgame = the AP-injected variant),
`avm2-stage13-browser.md` (browser-WASM path), the `archipelago-rando-integration`
memory (the whole AVM1 AP effort + the converged `__swfBridge` substrate), the
`ruffle_injection_techniques` memory, and `~/CC/flash-ap-api/README.md`.

## 1. Bottom line

**Useful, and not a detour.** The Archipelago-CC plan-of-record already names
"SWFRecomp as the AVM2 runtime swap for the flash-ap-api integration, gated on
the AVM2 milestone" (the "converged substrate" / Track A in the
`archipelago-rando-integration` memory). So finishing AVM2 Seedling (Stage 12) +
a browser path (Stage 13) is exactly what unblocks the AP integration the AP side
has been waiting on. The injection work is the **AP layer** on top of the runtime
we are building — not a competing approach.

The reusable value is concentrated in specific, runtime-independent pieces; the
injection *mechanism* is where the runtime choice matters.

## 2. The three artifacts found (2026-07-13)

- **`~/CC/SeedlingArchipelagoInjector/`** — original Seedling-specific PoC.
  `src/BridgeSeedling.as` (108 lines: "prove we can read Main statics from
  injected code"). Not a git repo. The Stage-12 target SWF symlink lives here.
- **`~/CC/flash-ap-api/`** — the generalized framework (git, last commit
  2026-04-20). `src/BridgeGeneric.as` (681 lines), data-driven via a per-game
  JSON config. DoABC bytecode injection into an **unmodified** SWF: compile the
  bridge with mxmlc → `extract_bytecode_as3.py` (patch DoABC lazy-init→eager,
  synthesize DefineSprite/SymbolClass/PlaceObject2) → `inject.py` splices before
  the first ShowFrame + bumps SWF version to 14 (AS3 `JSON.parse`). Runtime model:
  an `ENTER_FRAME` loop pushing state via `ExternalInterface.call("stateChanged",
  …)` and pulling a write/teleport queue via `getItemQueue()`.
- **`~/CC/Archipelago-CC/frontend/modules/flashPanel/`** — the production
  consumer (flashBridgeAdapter.js, games/, swf/). Seedling works end-to-end here
  **in a real Flash player** (Basilisk NPAPI / Clean Flash Chrome): item/location
  sync, checks-on-pickup with undo, progressive + fusion items, teleport.

## 3. Directly reusable (runtime-independent — the expensive part)

- **`flash-ap-api/games/seedling.json`** (172 lines) — the reverse-engineered AP
  mapping: 14 monitored `state_properties` on `Main`, 19 `ap_items`, ~50
  `ap_locations`, `ap_id_offset` 20000000, progressive/fusion rules, teleport
  coords. **Verified against `~/CC/seedling/src/Main.as`:** each property is a
  real `public static function get`/`set` pair backed by `SAVE_FILE.data.*` (e.g.
  `get/set hasSword` → `SAVE_FILE.data.hasSword`), so the map is valid for BOTH
  read (location detection) and write (item application). This is identical
  regardless of Ruffle vs our runtime vs injected vs source-modified. **Adopt
  verbatim as the AP spec.**
- **The `__swfBridge` contract + JS transport** (`rando_bridge.js` /
  `archipelago.js`, vendored under `SWFRecomp/wasm_wrappers/rando/`) — the settled
  interface from the AVM1 Rando work (`configure`/`pollItems`/`sendLocation`,
  cooperative ExternalInterface: outward `EI.call → window`, inward
  `EI.call` return value). Reuse unchanged.

## 4. The one blocking gap

**Our AVM2 runtime does not implement `flash.external.ExternalInterface`** (grep
of `SWFModernRuntime/src/avm2/*.c` is empty; the AVM1 runtime has it in
`action.c` with the `__swfBridge` handlers). Both the injection path and the
native-bridge path depend on it. So AP work is gated on either adding AVM2
ExternalInterface, or sidestepping it (Approach C below).

## 5. Approaches for OUR runtime

### A. Inject the DoABC bridge, then recompile with SWFRecomp
Precedent exists — the Doodle Jump flashSubstrate probe already did "inject AS
*before* recompiling" (AVM1/AS2; `archipelago-rando-integration` memory).
flash-ap-api's `inject.py` is the AVM2/DoABC version. The bridge needs
`getDefinitionByName` (have, Stage 3/4), `JSON` (have, Stage 4), `ENTER_FRAME`
(have, Stage 5) — **but `ExternalInterface` (missing for AVM2)**. Blocked until
AVM2 EI exists; also inherits injection fragility (deferred class resolution, tag
splicing, version bump).

### B. Native / WASM `__swfBridge` handler for AVM2
Port the done AVM1 mechanism (`swf_bridge_native_external_call` +
`swf_browser_external_call`, WITH_AP-gated). Keeps the game **AS-naive** — the
runtime provides the bridge. Cleanest philosophical fit, but same dependency:
needs AVM2 `ExternalInterface` first, plus the browser-WASM AVM2 path (Stage 13)
to host the JS side.

### C. Modify Seedling source + recompile — most attractive FOR SEEDLING
We have the full source: `~/CC/seedling/src/` + `Shrum.as3proj` + FlashPunk +
`NewgroundsAPI.swc`, buildable with mxmlc (`~/CC/flex-sdk/`). Advantage: it can
**sidestep the ExternalInterface gap entirely** — instead of an injected bridge
calling EI, add a small AP-hook class (or call an **AVM2 `Rando`/`__swfBridge`
builtin** directly, the exact pattern the AVM1 `Rando` builtin used: `intrinsic
class Rando`, `new Rando()` → native ctor). Removes both the injection fragility
AND the EI dependency.
- Trade-off: Seedling-specific (loses flash-ap-api's "unmodified SWF" generality)
  and needs the source to build. Fine for Seedling (our target); not a general
  solution for source-less games.

## 6. Recommendation

1. **Adopt `seedling.json` + the `__swfBridge` contract as the AP spec now** —
   settled, runtime-neutral, no work wasted on any path.
2. **Sequencing:** AP integration is *downstream* of the render/browser work, not
   a shortcut. Order: AVM2 render validation (Stage 12/13; oracle frames already
   free via the Ruffle exporter, see `avm2-stage13-browser.md` §4) → then AP.
   - **Parallel-track exception:** AP *state sync* (reads → location checks,
     item writes) is observable in **trace/headless** with no render. A
     trace-only AP round-trip (drive Seedling headless, poke `Main.hasSword`,
     assert a `sendLocation`) could validate the AP track BEFORE the render is
     done — a cheap way to de-risk in parallel.
3. **For the first end-to-end "Seedling-as-AP-game in our runtime" demo, prefer
   Approach C** (source-mod + an AVM2 `Rando`/`__swfBridge` builtin) — lowest
   friction, avoids the AVM2 EI gap, mirrors the proven AVM1 Rando design.
4. **Keep Approach A/B as the general path** for games we lack source to, and add
   AVM2 `flash.external.ExternalInterface` when a source-less game demands it
   (it's also independently useful — Seedling's own NG preloader would use it).

## 7. Honest caveats
- Everything assumes Seedling *renders correctly* in our runtime, which is
  unproven (the WSL2 capture OOM). The trace-only AP path (§6.2) is the way to
  make AP progress without waiting on render.
- `Main`'s AP properties are STATIC accessors on `SAVE_FILE.data` (a SharedObject).
  Our AVM2 SharedObject (Stage 10) is `getLocal → dynamic data Object` — confirm
  the write path (`Main.hasSword = true` → `SAVE_FILE.data.hasSword`) round-trips
  in our runtime before relying on it.
- Cross-repo: the AP client / substrate registry lives in `~/CC/Archipelago-CC`
  (separate owner). Only the runtime-side bridge fulfillment is ours; coordinate
  the contract, don't fork it.
