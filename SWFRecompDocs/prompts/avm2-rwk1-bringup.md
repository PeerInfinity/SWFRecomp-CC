# Session prompt — RWK-1: Robot Wants Kitty headless bring-up (Flixel)

You are running **RWK-1** of `SWFRecompDocs/plans/avm2-robot-wants-kitty.md`:
first bring-up of Robot Wants Kitty (AS3/**Flixel**) on the AVM2 runtime. This
is the second real game after Seedling (FlashPunk) — proving the other big
indie engine. The runtime already covers RWK on paper: census (plan §1) shows
zero blocking ops, verify-clean ABC, and every flash.* import present by name.
Expect a Stage-12-style debugging arc, not feature work.

Read first: the plan (all of it — census, friction ranking §2, injection §4),
memory `avm2-stage12-seedling` (the bring-up playbook precedent: error-chain →
render → gameplay), memory `avm2-external-interface-swfbridge` (EI just landed
2026-07-16 — gate design, shim, no-op verification you will replicate),
`SWFRecompDocs/guides/wasm-game-debugging-session-guide.md`
(divergence-harness-first), and the avm2 suite `CURRENT_STATUS.md`.

## Target SWF

Work from the **injected** SWF per plan §4:
`~/CC/Archipelago-CC/frontend/modules/flashPanel/swf/robotkitty_injected.swf`
(already `--check-abc` clean: 2 abc_tags, 812 bodies, 0 verify fails), original
at `~/CC/newgrounds/529817_max_robotkitty.swf` (regenerable via
`~/CC/flash-ap-api/inject.py` — read-only toolchain, do not edit). Keep the
plain original in the loop for the injected-vs-plain no-op check. The Kong
variant and sequels are out of scope for RWK-1.

Decompiled source for reference (read-only, this is your map, not your oracle):
`~/CC/jpexs/output/robotkitty/scripts/` — game code in `xplor/`, engine in
`org/flixel/`, sponsor bits `GameShedAchievement.as`/`MD5.as`, embeds in `mx/`.

## Goal / exit criteria

1. **Recompiles + links + runs** in both build modes (no-graphics native +
   graphics). SWF9, 640×480 @ 30fps (Flixel zoom 2× over 320×240 — see
   robotkitty.json's `_doc_stage_size` note in Archipelago-CC).
2. **Boot error chain cleared**: run headless, fix each uncaught error until
   the game reaches its menu/title state with zero uncaught errors. Expected
   offenders (plan §2): GameShedAchievement URLLoader POSTs, preloader/
   LoaderInfo, possible site-lock via LoaderInfo.url. Every fix lands graded
   by an upstream avm2 trace test or a new `regression/` test (mxmlc:
   `~/CC/flex-sdk/bin/mxmlc`; remember `-omit-trace-statements=false`) — the
   game is never the oracle.
3. **Bridge no-op verified**: without the shim, injected-vs-plain headless
   trace over 300+ frames is byte-identical and EI stays unavailable — the
   exact check the Seedling EI session ran; replicate it for RWK (this also
   implicitly tests BridgeGeneric's Error-#2067-free availability path).
4. **First render comparison**: Ruffle oracle frames
   (`~/CC/ruffle`, exporter per `avm2-stage13-browser.md` §4) vs our
   `AVM2_CPU_DUMP` at the menu; record black-% / MAD and a divergence list.
   Perfect parity is RWK-2's job — RWK-1 just needs "recognizably the menu"
   plus the documented gap list.
5. Zero pass→fail in BOTH CI modes; wasm-link-smoke green.

Stretch (only if the chain clears fast): first PlayState frame renders;
FlxText/FontAsset (`bd.draw(TextField)` with an embedded DefineFont3) probed
with a minimal regression test — plan §2 ranks it the most likely genuinely
new surface.

## Boundaries

- `BridgeGeneric.as` / `inject.py` (flash-ap-api) and `robotkitty.json` /
  tilemap data (Archipelago-CC) are canonical elsewhere — read-only; no
  commits outside SWFRecomp-CC.
- Don't touch `action.c`; AVM2 work stays in `src/avm2/` +
  `SWFRecomp/src/abc/`.
- Don't start the AP/flashPanel integration (that's RWK-3+ and partly the
  Archipelago-CC side); RWK-1 is vanilla-gameplay bring-up on the injected SWF.
- WSLg graphics captures may hit the known `bitmap_tex` texture-array-layer
  flood (memory `webgpu-texture-array-layer-limit-blank-render`) — RWK has
  only 37 bitmaps so it likely fits, but if captures misbehave under WSL2,
  prefer the CPU dump path and note it.

Finish with the full pipeline per `.claude/pipeline-handoff.md` — both CI modes
if shared runtime code changed (likely), zero pass→fail; update the plan's
stage status + avm2 `CURRENT_STATUS.md`; write a session memory with the
divergence list for RWK-2.
