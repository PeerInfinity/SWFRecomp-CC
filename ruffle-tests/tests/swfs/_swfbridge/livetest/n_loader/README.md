# N level loader — load a specific level + detect completion

Injected-AS substrate for recompiled **N** ("the way of the ninja", Metanet),
following the Doodle Jump loader pattern (`../dj_loader/`, `../dj_probe/`).
Goal: load a **specific level** into real N and **detect when it is completed**,
as the first step toward an Archipelago-style procgen substrate.

Full investigation + decoded internals:
`SWFRecompDocs/status/2026-06-30-n-substrate-investigation.md`.

## How it works

```
NLoader.as --(MTASC)--> nloader.swf --(extract_bytecode.py)--> nloader_bytecode.bin
           --(inject_tracer.py, splice before N's first ShowFrame)--> n_loader.swf
           --(SWFRecomp recompile)--> native (headless) / wasm
```

### `__swfBridge` (ExternalInterface) contract
The loader pulls its level from a JS host and reports completion outward, so a
host (e.g. an Archipelago embed) drives it - the baked fixture is only the
fallback. Mirrors DJ's `__swfBridge`.
- **Inward:** `ExternalInterface.call("__swfConfig")` returns
  `"levelId\nlevStr\ndemoStr"` (newline is the only separator safe vs N's level
  chars). The loader polls each tick; if no host answers within `EI_WAIT` ticks
  (or EI is unavailable, e.g. native headless), it falls back to the baked
  `MODE` fixture.
- **Outward:** on completion, `ExternalInterface.call("__swfSendExit", levelId)`.
- Page side: `n_swf_bridge.js` installs `window.__swfConfig` / `__swfSendExit`
  and the host API `window.__swfBridge.configure({levelId,level,demo})` /
  `.onExit(cb)`. `n_host_mock.js` plays a standalone host for testing.
- Verified on Ruffle (`EI=1 ./run_ruffle.sh`): host feeds the level in, player
  completes, `__swfSendExit` reaches the host. Same plumbing applies to
  SWFRecomp-WASM in the browser (interactive keyboard when `demoStr` is empty).

`NLoader` has a `MODE` switch (the fixture used when no EI host is present):
- **`walk`** (default): a grounded level (solid floor row) where the player
  WALKS RIGHT into the exit's switch then door, driven by a hand-authored demo
  (N's bit-packed input replay). Faithful navigation. PASSES headless.
- **`fall`**: an empty level where the player AUTO-FALLS through a switch+door
  stacked just below the spawn — no input (increment 1). PASSES headless.

To keep headless runs DETERMINISTIC, the loader does NOT use `App_PlayGame`
(whose `App_UpdateGame` gates `game.Tick()` on wall-clock elapsed time, which
starves near-instant headless frames to ~5 game-ticks per 200 frames). Instead
it parks N's process (`SetActiveProcess(noop)`) and drives `game.Tick()` itself
once per injected frame — one game-tick per frame.

`NLoader` is a high-depth `onEnterFrame` clip injected alongside N. It reaches
N's own top-level (`_root`) API through an untyped `Object` and:

1. waits for N to finish booting (`InitApp` → `AppBuildModules`; `gamedata` is
   the last module built), then settles a few ticks;
2. `game.InitNewGame()` + **`App_LoadLevel_Raw(levelString, onLoaded)`** — N's
   own raw-level entry point (loads any level from one string);
3. on the load callback, `App_PlayGame()` (the only state that ticks
   physics/collisions) and OVERRIDES **`App_LevelPassedEvent`** with a wrapper
   that traces `N_COMPLETE` then chains to N's normal handler;
4. the player **auto-falls** (`GRAV=0.15`) through the exit's **switch** (opens
   the door) then the **door** → `ExitObject.PlayerHitExit` →
   `App_LevelPassedEvent` → our wrapper fires. No gold, no input, no ground.

### Why no demo / no gold
N's bundled level demos die partway and never reach the exit, so increment 1
uses **no input**. And the exit is opened by touching its **switch**, NOT by
collecting gold (`GoldObject` is optional bonus time). A short, slow fall
through a switch+door stacked just below the spawn completes deterministically.

### Level string format (decoded)
`levStr = mapStr "|" objStr`
- `mapStr`: 31×23 = 713 chars, one per tile, column-major; tile state =
  `charCode - 48` (`"0"` = empty). Increment-1 fixture is all-empty.
- `objStr`: objects joined by `"!"`, each `"<type>^<num,num,...>"`.
  `PLAYER=5 [x,y]`; `EXIT=11 [doorX,doorY,switchX,switchY]`; `GOLD=0 [x,y]`.
  Pixel convention: tile (col,row) center = `col*24+12, row*24+12`.

## Usage

Two tiers run the SAME injected `n_loader.swf`:

```bash
./build_nloader.sh          # -> n_loader.swf  (MTASC + inject; needs ~/CC/mtasc)

# Ruffle (ground truth, FAST: no recompile, ~15s) - needs DISPLAY + chrome + playwright
./run_ruffle.sh 15          # baked fixture -> ruffle_run/console.txt ; prints N_COMPLETE
EI=1 ./run_ruffle.sh 15     # __swfBridge tier: host feeds level, gets __swfSendExit

# SWFRecomp native (headless) - first build ~4 min (action.c -O2), ccache after
./run_nloader.sh 400        # recompile native + run headless -> native_run/trace.txt
grep N_COMPLETE native_run/trace.txt
```

**Both runtimes produce byte-identical trace** (player x, completion tick), so
Ruffle is the fast iteration loop and SWFRecomp native is the headless oracle;
any divergence between them is a SWFRecomp bug. Ruffle runs the SWF directly (no
recompile), so fixture authoring iterates in seconds. The native runner is the
game-agnostic `../dj_probe/run_native.py`.

### Demo / input format (decoded)
Per tick = 4 bits `L=1, R=2, J=4, JTRIG=8` (jump rising-edge); 7 ticks packed per
entry at shifts 0,4,…,24; serialized `"<tickCount>:<e0>|<e1>|…"`. "Hold right" =
R every tick → each full 7-tick entry = `35791394`.

## Next steps (see the status doc)
- Arbitrary procgen levels: the full object-param and tile-state tables are in
  the status doc (`2026-06-30-n-substrate-investigation.md`).
- Browser-WASM tier via the `__swfBridge` ExternalInterface plumbing (interactive
  keyboard input instead of a demo).
