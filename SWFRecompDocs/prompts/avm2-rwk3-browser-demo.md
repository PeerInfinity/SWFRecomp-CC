# Session prompt — RWK-3: Robot Wants Kitty browser demo + kitty TAS

You are running **RWK-3** of `SWFRecompDocs/plans/avm2-robot-wants-kitty.md`.
RWK-2 (2026-07-16) landed `BitmapData.draw(TextField)` glyph rasterization
(menu pixel-exact vs oracle, MAD 0.765, residual = kitty bob phase) and proved
headless gameplay (input → physics → deaths → HUD → help text; state-aligned
gameplay frame vs an input-scripted Ruffle oracle MAD 1.68 with every diff an
entity phase). Read first: the plan's status header, memory
**`avm2-rwk2-text-gameplay`** (RWK-3 checklist, recipes, gotchas), the avm2
`CURRENT_STATUS.md` RWK-2 section, and memories `avm2-stage13-browser-13a` +
`avm2-stage13c-live-keyboard` (browser build/deploy + live-input infra).

## Lever 0 — the wasm heap gate (do this BEFORE deploying)

RWK PlayState boot creates ~0.8+ GB of transient string garbage in ONE tick
(`FlxTilemap.arrayToCSV` quadratic concat; **AVM2 strings are never
GC-collected and the GC only runs between ticks**). Native got a 4 GB arena
stopgap (heap.c) — but browser wasm32 still initializes a 1 GB arena, so the
browser demo will very likely OOM at PlayState boot. Options, in rough order
of preference — measure before choosing:

1. Measure the real peak first (native o1heap diagnostics or a quick
   instrumented run): if actual peak < ~2 GB, try simply raising the
   emscripten arena (wasm32 can address up to 4 GB with
   `-sMAXIMUM_MEMORY=4GB -sALLOW_MEMORY_GROWTH`; check what
   `build_wasm_avm2.sh` currently sets, and what o1heap's fragment math
   tolerates on wasm32).
2. Targeted runtime relief that helps every game: e.g. geometric
   pre-reservation is impossible for immutable concat, but a **string-concat
   rope/arena** or making `avm2_string_concat` garbage collectable
   (Avm2String allocations tracked like objects, swept between ticks — the
   garbage here is dead by tick end) — grade with a regression test
   (loop-concat a ~50 KB string, assert completion + correct length).
3. If (1) suffices for RWK, file (2) as the follow-up rather than forcing it
   into this session — but say so explicitly in the session memory.

## Lever 1 — browser demo (the RWK-3 headline)

Per Stage-13a/13c infra: `SWFRecomp/scripts/build_wasm_avm2.sh` +
`deploy_wasm_avm2.sh` (docs2 demo page + listing; see
`docs2-demo-redeploy-catalog-type` memory for catalog conventions). RWK
needs:
- **Live mouse** for the TitleState buttons — 13c built the live *keyboard*
  ring injector; check whether a mouse path exists in the browser wrapper. If
  not, extend the 13c ring pattern with MOUSE_MOVE/DOWN/UP events feeding the
  same Stage-8 dispatch the headless harness uses (FlxG.mouse rides stage
  listeners). The menu is otherwise unreachable in-browser.
- Live keyboard (13c, done) — arrows/Z/X/C/R map straight through.
- Audio should be free (`avm2-real-audio-output`): FlxSound title music +
  SFX; verify the mixer bridge fires (user-gesture gate applies —
  `__swfBridgeStart()`-style activation per the packaged-Seedling precedent).
- Boot chain in-browser: LogoState splash is time-gated via getTimer; the
  browser build's getTimer semantics (wall-clock vs tick — check
  `avm2_timer_elapsed_ms` under the browser loop) determine pacing; either is
  acceptable, just note which.
- Perf: 640x480 blit game, far lighter than Seedling — spot-check ~30 fps on
  the Windows-Chrome real-GPU rig (`windows-playwright-from-wsl` memory) only
  if anything feels slow headless-to-browser.

Grade: demo loads from `docs2/examples/avm2/` (same-origin page), menu text
renders (RWK-2's fix, now on real GPU), Play Game click starts gameplay,
player moves with live keys, no uncaught errors in the console, audio plays
after the activation gesture.

## Lever 2 — finish the kitty TAS (headless, carried from RWK-2)

Tools preserved untracked in `ruffle-tests/_rwk_tas/` (README inside;
driver/tracker/last plan). Route + methodology in the RWK-2 memory and
CURRENT_STATUS: spawn exits RIGHT-fall only; descent legs to the JUMP
powerup at tile (10,82) are individually proven; three aliens patrol at
20 px/s with phases deterministic per plan — measure phases from dumped
frames at the leg boundaries, land behind a leftward-sweeping alien, cross at
4x its speed. Then SHOOT (44,73) → DBLJUMP (47,69) → climb the eastern open
area to the row-62 corridor → west to the x=12 shaft → drop to the kitty
block (win = |dx|<30 && |dy|<30 vs kitty (160,1024) → WinState, unmistakable
in frames). Deaths are free (respawn at spawn, world persists). Grade: a
committed input script (regression-style dir or `_rwk_tas/`) whose run ends
in WinState, plus a state-aligned oracle spot-check of one mid-route frame
(`RUFFLE_INPUT_FILE` patched exporter — remember Flixel wipes keys on every
state switch, press only after the target state is live; menu timing drifts
per export, schedule late).

If browser work eats the session, the TAS is the droppable half — but then
hand it forward again with whatever new phase measurements exist.

## Exit criteria

1. Wasm-heap gate resolved for RWK (measured, chosen option implemented or
   explicitly deferred with numbers).
2. Browser demo deployed and playable: menu text + click-to-start + live
   keys + audio, zero uncaught errors; docs2 listing updated.
3. Kitty TAS reaches WinState headless (or handed forward with progress).
4. BOTH CI modes zero pass→fail; wasm-link-smoke green. NOTE: the RWK-2 runs
   had flaky missing shards during a GitHub incident (see `.pipeline-state`
   note) — if this session's runs are clean, they also backfill that gap; if
   shards flake again, name them and move on.

## Boundaries

Same as RWK-1/2: injected SWF is the target; flash-ap-api + Archipelago-CC
artifacts read-only; no commits outside SWFRecomp-CC (the ~/CC/ruffle
exporter input patch stays a local working-copy patch); `action.c` untouched;
AVM2 work in `src/avm2/` + `SWFRecomp/src/abc/` + wasm wrappers/scripts; the
game is never the oracle — every runtime fix lands with an upstream or
`regression/` grade.

Finish per `.claude/pipeline-handoff.md` (both CI modes if shared runtime
code changed; no-graphics only if wasm/browser-glue only — but a heap/string
change is shared: BOTH). Update the plan's stage status + CURRENT_STATUS.md;
write a session memory with the RWK-4 (FlxSave/variants) checklist.
