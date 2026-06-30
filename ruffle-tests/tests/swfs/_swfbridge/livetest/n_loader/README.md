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

```bash
./build_nloader.sh          # -> n_loader.swf  (MTASC + inject; needs ~/CC/mtasc)
./run_nloader.sh 300        # recompile native + run headless -> native_run/trace.txt
grep N_COMPLETE native_run/trace.txt   # the completion signal
```

First native recompile is slow (N's `action.c` is ~3 MB at -O2); ccache makes
reruns fast. The runner is the game-agnostic `../dj_probe/run_native.py`.

## Next steps (see the status doc)
- "Walk right on the ground" fixture + a hand-authored "hold right" demo (needs
  the demo format) for a faithful grounded run.
- Arbitrary procgen levels (decode the remaining object/tile type codes).
- Browser-WASM tier via the `__swfBridge` ExternalInterface plumbing.
