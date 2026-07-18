# Session prompt — RWK AP handoff page (seedling_teleport_ap, but for Robot Wants Kitty)

You are packaging the **Robot Wants Kitty Archipelago handoff artifact**: a
self-contained same-origin-iframe demo page under `docs2/examples/avm2/`
running the **injected** RWK SWF (original + BridgeGeneric) on our AVM2 wasm
runtime, with the `__swfBridge` contract verified end-to-end. This is a
repackaging job following the proven Seedling recipe — on paper it needs
**ZERO new runtime features** (`avm2-robot-wants-kitty.md` §4): EI is done,
the RWK browser demo is done, the injected SWF recompiles clean, and the
memory leaks that used to OOM the browser are all fixed.

Read first: memories `avm2-external-interface-swfbridge` (THE template — the
Seedling packaging session), `avm2-rwk3-browser-demo` (RWK wasm heap gate +
demo specifics), `seedling-ap-ei-ruling` (the repo-split rules), and
`SWFRecompDocs/plans/avm2-robot-wants-kitty.md` §4 (AP integration status).

## What already exists (all verified present 2026-07-18)

- **Injected SWF**: `~/CC/Archipelago-CC/frontend/modules/flashPanel/swf/robotkitty_injected.swf`
  — original + BridgeGeneric DoABC (`--check-abc`: 2 abc_tags, 812 bodies,
  0 verify fails, checked 2026-07-16). Config:
  `~/CC/Archipelago-CC/frontend/modules/flashPanel/games/robotkitty.json`
  (player path reads, 10 power items, ap_locations, and a **config-driven
  teleport** that constructs a fresh `xplor.PlayState` via `new_instance` then
  path-writes Player.x/y). Unlike Seedling, no separate teleport build is
  needed — one SWF, teleport-by-invocation; and there's no NG-preloader gate,
  so the FULL write→apply→re-report grade is reachable on this single SWF.
- **EI runtime + shim**: `avm2_external.c` + `SWFRecomp/wasm_wrappers/swf_bridge_avm2.js`
  (installs `window.__swfBridge`; `getItemQueue` is DRAIN-ON-READ; callbacks
  surface as `__swfBridge.game.<cb>()`; `deploy_wasm_avm2.sh` stages the shim
  and `docs2/demo.html` HEAD-probes it).
- **Page template**: `SWFRecomp/wasm_wrappers/swf_bridge_game_page.html` →
  `game.html` (see `docs2/examples/avm2/seedling_teleport_ap/` for the shape:
  game.html + index.html + <name>.js/.wasm + swf_bridge_avm2.js + test.swf +
  test_info.json + .demo_type).
- **RWK plain demo**: `docs2/examples/avm2/rwk/` (`demo.html?test=avm2/rwk`),
  live mouse/keys/audio, real-GPU 5.1 ms/frame. Wasm heap gate already in
  build: 1984 MB AVM2 arena + `-sMAXIMUM_MEMORY=4GB` (`heap.c` under
  `__EMSCRIPTEN__ && SWF_AVM2`; emscripten mmap fails at exactly 2048 MB).
- **Livetest harnesses**: `ruffle-tests/tests/swfs/_swfbridge/livetest/`
  — `seedling_avm2/run_seedling_livetest.sh` (the one to clone) and
  `toy_browser_avm2/`.
- **Prior recompiled trees**: `~/CC/seedling_ap_build/recompiled_teleport_rwk2`
  etc. — pattern for where to keep the RWK AP build (suggest
  `~/CC/rwk_ap_build/`). RWK-1's recompile of this exact injected SWF verified
  the bridge no-op (injected-vs-plain native 300-frame trace byte-identical),
  but at an older HEAD — re-verify at current HEAD.

## The work

1. **Recompile + no-op parity at current HEAD.** Recompile
   `robotkitty_injected.swf` (native first). Re-run the no-shim no-op check:
   native 300-frame trace byte-identical injected vs the plain RWK build
   (reuse the RWK-3 scratch build in /tmp if it survives, else rebuild; RWK
   builds fine at -O2 — byte-identical behavior to -O0, ~2x faster).
2. **Package the handoff page.** Build the wasm
   (`build_wasm_avm2.sh` / `deploy_wasm_avm2.sh` with DEMO_SWF/DEMO_DESC as in
   RWK-3), create `docs2/examples/avm2/rwk_ap/` from the game-page template,
   add the catalog entry. Naming: `rwk_ap` (consistent with the existing `rwk`
   demo; seedling used the long form — either is fine, stay consistent once
   picked).
3. **Livetest — clone `seedling_avm2` for RWK.** Drive the page via parent
   frameLocator: user-gesture `__swfBridgeStart()` INSIDE the iframe
   (WebGPU/audio activation), then
   `contentWindow.__swfBridge.game.wireCheck()` / `configure(robotkitty.json)`
   / `readState()`, `queueItems()` → applyItem → re-report, `stateChanged`
   outbound, and the **teleport invocation** (construct `xplor.PlayState` from
   the title screen, path-write Player.x/y, confirm via readState that the
   player is in PlayState at the written coords). Target the same 8/8-style
   ladder as Seedling. Also verify the browser no-op: page WITHOUT the shim →
   zero `[BridgeGeneric]` output.
4. **Sanity gates.** Bridge-active perf spot check (RWK is ~55x lighter than
   Seedling — native timing or WSL headed Chrome suffices; the Windows
   real-GPU rig is optional confirmation). Memory: with weak orphans + string
   GC landed, a few minutes of bridge-active play should hold a flat live
   census (`AVM2_HEAP_STATS` on native is the cheap proxy).
5. **Handoff.** Update `~/CC/Archipelago-CC/NewDocs/plans/seedling-swfrecomp-task-split.md`
   with a HANDOFF DELIVERED note for RWK (page path, iframe usage, the
   same-origin requirement) — **leave it uncommitted in Archipelago-CC** for
   their instance to fold in, exactly like the Seedling session did. Their
   side then does the flashPanel iframe-src swap.

## Gotchas (inherited, don't rediscover)

- `getItemQueue` drains on read — BridgeGeneric doesn't dedup invocations.
- Inbound EI dispatch is safe only because the browser loop parks at
  `emscripten_sleep` (ASYNCIFY) — don't restructure the loop.
- ccall 'string' returns "" for NULL → the shim normalizes to null; no bridge
  callback legitimately returns "".
- `__swfBridgeStart()` must be a user gesture inside the IFRAME.
- The host page must be served **same-origin** with the consumer
  (`flashSubstrate/bridge.js` reaches into `contentWindow.__swfBridge`).
- Staged-wasm rot: rebuild from current HEAD, don't reuse stale .wasm
  artifacts (`avm2-flashpunk-text-font-name-resolve` lesson). Post
  collectable-strings, layout changes require FRESH=1 — plain rebuilds since
  don't, but verify nothing changed `Avm2String`/struct layouts before
  trusting an incremental build.
- If comparing against Ruffle: Ruffle AVM2 getTimer is WALL-CLOCK — state-
  align, never tick-align (RWK-1 gotcha).
- WSLg Chrome texture-array flood is a Seedling problem; RWK renders fine in
  WSL headed Chrome (RWK-3 verified) — full probes work locally.

## Grading / pipeline

- Expected diff: `docs2/` artifacts + livetest scripts + docs ONLY. If truly
  zero runtime/recompiler changes: commit + push, **no CI dispatch**
  (`ci-only-when-observable` — CI can't observe docs2/livetest changes).
- If a runtime bug DOES surface (EI edge, input, GC interaction): fix it under
  the house rules — grade with an upstream avm2 test or a new
  `ruffle-tests/tests/swfs/regression/` test (mxmlc, NOT mtasc;
  `-omit-trace-statements=false`), then full pipeline BOTH CI modes, zero
  pass→fail, and redeploy/restage per the standard recipe.
- Session memory: page path, livetest score, any deltas from the Seedling
  template, and what was left for Archipelago-CC.

## Budget note (delegation)

This is an **Opus-led session** — the recipe is proven and the work is
mechanical (recompile, package, clone a livetest, run probes). Escalate to
Fable only if the EI round-trip or the teleport invocation misbehaves in a way
that implicates the runtime (dispatcher reentry, GC rooting of callback fn
values, marshaling), or if a runtime fix becomes necessary.

## Boundaries

- **No commits outside SWFRecomp-CC.** `~/CC/flash-ap-api` (BridgeGeneric.as,
  inject.py) is read-only; Archipelago-CC owns `robotkitty.json` and the
  contract doc — consume both as-is. The task-split doc update stays
  uncommitted there.
- Don't re-inject or modify the SWF — `robotkitty_injected.swf` is the
  canonical artifact; if it looks wrong, report, don't rebuild it.
- Don't touch the existing `rwk` plain demo or the Seedling handoff page.
- The kitty TAS / RWK-4 checklist (WinState, FlxSave, Kong variants) is a
  separate arc — out of scope here.
