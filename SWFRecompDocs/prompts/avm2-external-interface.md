# Session prompt — AVM2 ExternalInterface (`__swfBridge`) + packaged Seedling AP page

You are implementing **`flash.external.ExternalInterface` for the AVM2 runtime**
and packaging the recompiled-Seedling browser page that exposes
`window.__swfBridge` — the handoff artifact the Archipelago-CC side is waiting
on. Bridge delivery is **RULED (user, 2026-07-16): generic EI subset**
(`available` / `addCallback` / `call`), NOT compiled-in hooks — it serves both
Seedling and the injection-only Robot Wants series
(`SWFRecompDocs/plans/avm2-robot-wants-kitty.md` §4). Compiled-in hooks
(`seedling_teleport_build`) remain a fallback only.

Read first:
- `~/CC/Archipelago-CC/NewDocs/plans/seedling-swfrecomp-task-split.md` — your
  side = "Tasks for the SWFRecomp-CC instance" (task 1 done; this session =
  tasks 2–6). Note its RULED staged sequencing: Stage 1 = basic AP via the
  flashPanel/flash-ap-api client layer; the flashSubstrate/procgen entry is a
  LATER Archipelago-CC planning session — don't build for it yet.
- `SWFRecompDocs/plans/avm2-seedling-ap-integration.md` — conclusions stand;
  update its status header (EI ruled; Stage 12/13 + audio DONE).
- Memory `archipelago-rando-integration` — the AVM1 production precedent this
  session mirrors, including the 8/8 livetest.
- `~/CC/flash-ap-api/src/BridgeGeneric.as` — the AS3 client whose EI usage
  defines your scope. **Canonical, do not fork or edit.**
- Contract spec: `~/CC/Archipelago-CC/docs/json/developer/procgen/flash.md`
  (short; the operational detail is in
  `Archipelago-CC/frontend/modules/flashSubstrate/bridge.js` comments).

Baseline: Stage 13 complete (browser Seedling ~30 fps / ~32.6ms frame, live
keyboard) and **audio landed 2026-07-16** (memory `avm2-real-audio-output`) —
sync with master and that memory before starting; avm2 suite ~846/1206
effective pre-audio. Zero pass→fail expected, BOTH CI modes.

## Reference implementations (all in-repo)

- **AVM1 browser handler**: `swf_browser_external_call` in
  `SWFModernRuntime/src/actionmodern/action.c` (~5660) — EM_ASM outward call to
  `window[name](arg0)`, string marshaling, and the **gate**: installed only when
  the page exposes `window.__swfBridge` (checked once at init; demos without
  the shim keep `available == false`, zero behavior change). Reuse this gate
  design verbatim. The native counterpart (SWF_BRIDGE_CONFIG-gated, same file)
  shows the contract's native analog — browser-first this session; native AVM2
  EI only if cheap.
- **Page shim**: `SWFRecomp/wasm_wrappers/swf_bridge.js` — installs
  `window.__swfBridge = {configure, pollItems, sendLocation}` + the EI-facing
  window functions. The AVM2 page shim extends this pattern with
  BridgeGeneric's host-side surface (`stateChanged`, `getItemQueue`,
  `console.log` passthrough) and inbound dispatch for `addCallback`.
- **The 8/8 livetest**:
  `ruffle-tests/tests/swfs/_swfbridge/livetest/toy_browser/` (harness.html +
  mock host + headed-Chrome toy_test.js + run_toy_livetest.sh) driving
  `SWFRecomp/tests/swfbridge_toy/Main.as` (AVM1/MTASC). Build the AS3
  counterpart with `~/CC/flex-sdk/bin/mxmlc` and replicate the livetest for
  the AVM2 build.

## Scope (check first, then build)

Grep BridgeGeneric.as for its exact EI usage before writing code. Known from
inspection: `available`; `addCallback("wireCheck"|"configure"|"readState", fn)`
— string-in/string-out; `call("console.log", msg)`, `call("stateChanged",
pname, pvalue)` (**2 args — AVM1's handler is 1-arg; AVM2 needs variadic**),
`call("getItemQueue")` with a JSON-string return. Marshaling stays
**string-first** (coerce non-strings via String(); JSON strings are the payload
convention) — do NOT build object-graph marshaling. `objectID` → null,
`marshallExceptions` no-op stub are fine.

Implementation home: new `SWFModernRuntime/src/avm2/avm2_external.c`.
`addCallback` inbound path: keep a name→Avm2Value(function) registry in C,
export one dispatcher to JS (string name + string args in, string out), and
have the page shim create the `window`-visible wrappers. All browser pieces
`__EMSCRIPTEN__`-gated; the class itself (with `available == false`) exists in
every build so headless/trace behavior is unchanged.

## Suggested order

1. **EI core** in avm2_external.c (available gate, variadic call, addCallback +
   dispatcher) + page-shim extension.
2. **AS3 toy + tests**: headless-gradable `regression/` tests for the
   unavailable path (available=false, call→null — mxmlc, tests go in
   `ruffle-tests/tests/swfs/regression/`); AS3 toy_browser livetest → the
   8-probe equivalent passes headed.
3. **Injected Seedling**: `flash-ap-api/inject.py` on Seedling → `--check-abc`
   the output → recompile. Verify BOTH behaviors: without the shim the injected
   BridgeGeneric **no-ops silently** (available=false; gameplay byte-identical),
   with the shim `wireCheck`/`configure`/`readState`/`stateChanged`/
   `getItemQueue` round-trip against a mock host (the canonical Seedling
   mapping for configure payloads is
   `Archipelago-CC/frontend/modules/flashPanel/games/seedling.json` — read it,
   don't copy it into this repo).
4. **Perf gate**: per-frame readState/getItemQueue polling active → hold
   ~30 fps (frame ~32.6ms baseline; A/B with the `windows-playwright-from-wsl`
   rig; per `profile-game-native-n-is-noisy`, never trust single runs).
5. **Package the handoff artifact**: a self-contained page dir (seedling wasm +
   loader + shims + HTML) loadable as an iframe src from an origin-relative
   path, with the Ruffle-oracle verification story documented. Report its path
   + usage in CURRENT_STATUS and the session memory — the Archipelago-CC
   instance consumes this for its iframe-src swap; do NOT commit to
   Archipelago-CC yourself.

## Boundaries

- `BridgeGeneric.as`, `inject.py`, `extract_bytecode_as3.py` are canonical in
  `~/CC/flash-ap-api` — read-only. The Seedling AP mapping is canonical in
  Archipelago-CC — read-only. No commits outside SWFRecomp-CC.
- Don't touch `action.c` / the AVM1 EI path; don't touch the procgen
  flashSubstrate machinery (Stage-2 planning owns it).
- Game is never the oracle: every runtime behavior lands with a `regression/`
  or livetest grade first.

Finish with the full pipeline per `.claude/pipeline-handoff.md` — BOTH CI modes
(new AVM2 class registration is shared runtime code), zero pass→fail; update
CURRENT_STATUS.md, the ap-integration doc status header, and write a memory.
