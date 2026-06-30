# N ("the way of the ninja") as a procgen substrate — investigation

Date: 2026-06-30. Goal (user): load a *specific level* into recompiled N and
*detect when the level is completed*. Scope chosen: **arbitrary raw levels**,
**native/headless fixture tier first** (mirrors the DJ loader's first increment).

## STATUS: increments 1 & 2 PASS (2026-06-30)

### Increment 2 (walk-right, grounded, demo-driven) PASS
`NLoader.as` now has a `MODE` switch ("walk" | "fall"). Walk mode: solid floor
row, player WALKS RIGHT into the exit switch then door, driven by a hand-authored
demo. Trace:
```
NT67 gt=1  x=276    y=350   (spawned on floor - grounded, y constant)
NT79 gt=13 x=287.17 y=350   (reaches switch at 294 -> exit opens)
NT80       x=288.99 done=true -> N_COMPLETE tick=80
```
Validated: grounded level authoring (floor tiles + pixel mapping), the demo
format decode, and DETERMINISTIC ticking. KEY FIX: instead of App_PlayGame (whose
App_UpdateGame gates game.Tick() on wall-clock elapsed, starving headless runs to
~5 ticks/200 frames), the loader parks N's process (`SetActiveProcess(noop)`) and
drives `game.Tick()` itself once per injected frame -> `gt` counts 1,2,3,...

### Demo / input format (decoded, DoAction_91)
Per tick = 4 bits `L=1, R=2, J=4, JTRIG=8` (jump rising-edge). 7 ticks packed per
`demoList` entry at shifts 0,4,8,12,16,20,24. Serialized `"<tickCount>:<e0>|<e1>|..."`
(`:` then `|`). "Hold right" = R every tick -> each full 7-tick entry = 35791394.
Bound to `_Complex` variants in NinjaGame ctor (DoAction_89). Player reads input
via `game.GetInputState(inList)` (DoAction_86:12); `game.GetTime()`=tickCounter.

### Object type + Init params (for procgen authoring)
GOLD=0 [x,y]; BOUNCEBLOCK=1 [x,y]; LAUNCHPAD=2 [x,y,nx,ny]; TURRET=3 [x,y];
FLOORGUARD=4 [x,y,dir]; PLAYER=5 [x,y]; DRONE=6 [x,y,movetype,isChaser,weaptype,dir];
ONEWAYPLATFORM=7 [x,y,dir]; THWOMP=8 [x,y,dir]; TESTDOOR=9 [x,y,vert,isTrap,doorI,
doorJ,isLocked,dI,dJ]; HOMINGLAUNCHER=10 [x,y]; EXIT=11 [doorX,doorY,switchX,switchY];
MINE=12 [x,y]. (Classes in DoAction_70..84.)

### Tile state codes (charCode-48)
0 empty, 1 full; 2-5 = 45deg slopes (pn/nn/np/pp); 6-9 concave; 10-13 convex;
14-21 = 22deg (steep S / broad B); 22-29 = 67deg (S/B); 30-33 = half-tiles (d/r/u/l).
Solid floor = '1'. Grid `TileMap(rows=31,cols=23,xw=12,yw=12)`, tw=th=24; cell
(i,j) center=(i*24+12,j*24+12); 1-tile solid border; SetTileState(i,j)->grid[i+1][j+1];
map char index = mapX*23+mapY (X-outer/Y-inner); map cell (mapX,mapY) pixel center
= (mapX*24+36, mapY*24+36).

### MTASC gotcha
MTASC v8's SWF writer overflows zlib ("zlib_deflate_end", truncated 8-byte output)
on a LONG leading comment OR any non-ASCII (em-dash) in comments. Keep injected-AS
headers short + ASCII; detail goes in README/status docs.

## STATUS: increment 1 PASSES (2026-06-30)
Harness: `ruffle-tests/tests/swfs/_swfbridge/livetest/n_loader/` (`NLoader.as`,
`build_nloader.sh`, `run_nloader.sh`, README). Native headless run trace:
```
[nloader] boot-ready at tick 18, settling
[nloader] loading raw level (742 chars)
[nloader] level loaded -> entering running state
NT67 ... x=372 y=100   (player spawned, falling)
N_COMPLETE tick=191    (App_LevelPassedEvent wrapper fired)
[nloader] level complete -> quitting
```
A specific raw level loaded into real recompiled N and completion was detected,
fully headless, no input. Note: N's game-ticks are wall-clock-driven
(`App_UpdateGame` runs `game.Tick()` while elapsed > TICKLEN), so under
near-instant headless frames the player falls slowly in game-time — the
switch+door stacked just below spawn still catch it deterministically. First
native recompile ~253s (action.c -O2); ccache makes reruns fast.

## The template: Doodle Jump substrate

`ruffle-tests/tests/swfs/_swfbridge/livetest/dj_loader/` (+ `../dj_probe/`).
Mechanism = **injected ActionScript**, engine untouched:

```
Loader.as --(MTASC)--> loader.swf --(tools/divergence/extract_bytecode.py)--> *.bin
          --(tools/divergence/inject_tracer.py, splice before first ShowFrame)--> injected.swf
          --(SWFRecomp recompile)--> native / wasm
```

A high-depth `onEnterFrame` clip drives the game's *own* data structures to
render a level and observes the game's *own* state to detect progress; reports
in/out via `ExternalInterface` (`__swfConfig` / `__swfSendLocation` ...) in
browser, or a baked-in `FixtureData.DATA` string on the headless/native tier.
The injection + native-run scripts are **game-agnostic** (`inject_tracer.py
<in> <out> --bytecode <bin>`; `dj_probe/run_native.py`), so N reuses them.

## N's hooks (decompiled from `~/CC/flasharchive/N.swf`, 323 AS scripts)

N is even cleaner than DJ — it already exposes a raw-level loader and a single
level-complete event. All these are top-level `_root` functions (frame_1
DoActions), reachable/overridable from injected AS.

### Load a specific (raw) level
- **`App_LoadLevel_Raw(levStr, callback)`** — `DoAction_119`. Loads an arbitrary
  level from one string, runs `callback` when load finishes. THE substrate hook.
- `App_LoadLevel(levelID, cb)` — built-in lookup via `gamedata.GetLevelData(id)`.
- Built-ins are literals: `new LevelData(name, levStr)` → `new EpisodeData(
  epname, code, levelList)` (`DoAction_97`, data in `DoAction_101` etc.).

**Level string format** (`NinjaGame.InitLoadLevel`, `DoAction_92`; separators
confirmed): `levStr = mapStr "|" objStr`
- `mapStr`: one char per tile, `charCodeAt` = tile type, column-major over the
  **31×23** grid (`tiles = new TileMap(31,23,...)`, `DoAction_115`).
- `objStr`: objects joined by `"!"`; each = `"<type>^<num,num,...>"` (type sep
  `"^"`, param sep `","`). `SpawnGameObject(type, params)` (`DoAction_92`).
  Object classes incl. `ExitObject` (`DoAction_70`), `GoldObject` (`DoAction_71`).
  Example built-in ("get down", `DoAction_101`):
  `...mapchars...|5^156,108!11^396,564,396,420!0^612,108!0^636,108!...`
  (type 11 ≈ exit+trigger, 0 ≈ gold, 5 ≈ player spawn — exact code map TBD).

### Detect level completion
- The `11^...` exit object is really TWO pieces: a **switch/trigger** at
  `(trigX,trigY)` and the **door** at `(exitX,exitY)`. Player must touch the
  switch FIRST → `ExitObject.PlayerHitTrigger()` (`DoAction_70:108`) sets
  `isOpen=true` and puts the door in the collision grid; THEN touching the open
  door → **`ExitObject.PlayerHitExit()`** (`DoAction_70:103`) →
  **`App_LevelPassedEvent()`**. (Real N mechanic = hit the switch to open the
  exit — NOT "collect all gold". `GoldObject` (type 0) is OPTIONAL bonus:
  collecting it only calls `game.GiveBonusTime()`, `DoAction_71`.)
- Encoding: `EXIT=11`, params `[exitX,exitY,trigX,trigY]`. `GOLD=0` `[x,y]`,
  `PLAYER=5` `[x,y]` (`player` global set in `PlayerObject.Init`, DoAction_84:20).
- Radii (distance test `< r_obj + player.r`): door `r = tiles.xw`, switch
  `r = tiles.xw*0.5`. Tiles: `CHAR_PAD=48` so map char `'0'`=empty(TID_EMPTY=0),
  `'1'`=full(TID_FULL=1); `APP_TILE_SCALE=12`; grid 31×23.
- Player **auto-falls** with no ground (`Stand`→`Fall`, DoAction_87:106).
- In normal play `App_LevelPassedEvent` → **`App_LevelPassedEvent_Normal()`**
  (`DoAction_117:12`): logs `"level completed."`, `gamedata.IncrementCurrentLevel`,
  `App_StartPostLevelPause` (GUI "level complete! press [spacebar]…").
- **Detection hook:** an injected clip saves `_root.App_LevelPassedEvent_Normal`
  and replaces it with a wrapper that emits a signal (trace / `ExternalInterface`)
  then calls the original. One hook, fires exactly once per clear.

### Boot / when it's safe to load
`DoAction_115` bootstraps: `AppBuildingModules` builds `console, gui, tiles,
objects, userdata, game, editor, gamedata` then `App_LoadMainMenu()`. Injected
clip should wait until `_root.game` and `_root.gamedata` exist (boot done),
then: `game.InitNewGame()` → `App_LoadLevel_Raw(levStr, cb)`; in `cb` set
`App_PlayerDeathEvent/App_LevelPassedEvent = *_Normal` and
`SetActiveProcess(App_Tick_RunningGame)`. The debug path
`App_StartNewGame_Debug` + `App_Tick_DebugMenu` ([L]=`App_LoadLevel_Raw(txt,…)`,
[P]=`App_PlayGame_Debug`) in `DoAction_118` is the exact minimal recipe.

## Headless completion needs INPUT — use N's demo system
Completion only fires if the ninja actually reaches the exit, which needs input.
Native/headless has no human. N has a **demo (replay) system**:
`game.LoadDemo(demoStr)` + `game.StartDemoPlayback()` (`DoAction_118`,
`DoAction_119`; `MenuDemoData(epID,levNum,demoStr)` pairs a level with a replay
that plays it). Demo format separators: frame `"|"`, ticks `":"`.
- First increment (prove the mechanism deterministically): load a **built-in
  level + its bundled demo**, start playback → ninja walks to exit →
  `App_LevelPassedEvent` wrapper traces "COMPLETE". Fully headless.
- Arbitrary raw level (user's target): no bundled demo → either record one (play
  in browser/Ruffle, `game.DumpDemoData()`→clipboard, bake into FixtureData and
  replay headless) or drive via live keyboard input on the browser tier.

## First build (NLoader.as) — increment 1 = NO-DEMO fall-through fixture
Bundled demos die partway (don't reach the exit), so increment 1 avoids input
entirely using the auto-fall + switch mechanic:
1. New dir `ruffle-tests/tests/swfs/_swfbridge/livetest/n_loader/` mirroring
   `dj_loader/` (build_loader.sh, inject via inject_tracer.py, run via
   dj_probe/run_native.py against `SWFRecomp/tests/flasharchive/N/test.swf`).
2. `NLoader.as`: high-depth onEnterFrame clip; on boot-ready (`_root.game` &&
   `_root.gamedata`) → wrap `App_LevelPassedEvent_Normal` to trace `N_COMPLETE` →
   `game.InitNewGame()` → `App_LoadLevel_Raw(FIXTURE_LEVEL, onLoaded)`; in
   `onLoaded` set `App_PlayerDeathEvent/App_LevelPassedEvent = *_Normal` and enter
   the running state (mirror `App_PlayGame`). Player falls through switch→door.
3. `FIXTURE_LEVEL` (no-demo): empty 31×23 map (all `'0'`), `5^px,py` spawn near
   top, `11^px,py+dd,px,py+ds` with switch (ds) above door (dd) just below spawn
   so the brief low-velocity fall passes through both radii. Expected trace:
   `N_COMPLETE` within a few ticks.
4. Variants kept for later: (a) "walk right on ground" = floor row of `'1'`,
   spawn + switch + door on the floor, plus a hand-authored "hold right" demo
   (needs the demo format: frame sep `'|'`, ticks sep `':'`; record via
   `game.DumpDemoData()` then replay with `game.LoadDemo`+`StartDemoPlayback`);
   (b) arbitrary procgen levels.

## Risks for the fall-through fixture
- Broadphase tunneling: a fast fall could skip the switch's grid cell in one
  tick. Mitigate by starting the drop SHORT (low velocity) and stacking
  switch/door close to spawn; if it still misses, fall back to the walk-right
  demo fixture (grounded, low speed, deterministic).
- Must be in the RUNNING state (App_Tick_RunningGame) for collisions to tick —
  not pre-level pause.

## Open items / decisions
- Headless completion driver: built-in level+demo (prove mechanism) vs. recorded
  demo for a raw level. (Recommend built-in+demo as increment 1.)
- Exact object/tile type-code map (only exit/gold/spawn identified so far) —
  decode `SpawnGameObject` + each `*Object.Init(params)` when authoring procgen
  levels.
- N's in-game *graphics* gaps (laser persistence, coins not vanishing —
  `SWFRecompDocs/BACKLOG.md`) are independent of these AS-logic hooks; they don't
  block load+detect, but matter for a *visible* browser demo later.
