# n_drive — deterministic input script for N (level completion + death/retry)

Injected-AS probe that plays Metanet's **N** through its real game flow with a
fixed, game-tick-indexed input script, so the same run can be replayed on any
player (Ruffle exporter, Ruffle web, our native build, our browser WASM) and
compared tick by tick. Record: `SWFRecompDocs/plans/n-level-complete-report.md`.

N is **not** open source: never commit `N.swf`, the injected `n_drive.swf`, or
decompiled N source. `*.swf` is gitignored.

## How it drives N

- **Input.** N reads input once per game tick in `NinjaGame.GetInputState_Normal`
  via `Key.isDown(KEYDEF_L/R/J)`. The probe replaces `Key.isDown` (Ruffle marks
  `Key`'s methods protected, so it first calls `ASSetPropFlags(Key,"isDown",0,7)`)
  and answers from the script, keyed on `game.tickCounter`. Space (32) is pressed
  by phase: pre-level, post-level and the retry prompt each get Space after
  `PHASE_WAIT` (40) frames. Everything else reads as not pressed.
- **Start.** When the main menu is up (`TickApp == App_Tick_MainMenu`) for 10
  frames, the probe calls `gamedata.LoadEpisodeNum(0)` + `App_StartNewGame()`,
  which is what "play game" → episode 00 does. From there it is N's own flow:
  `App_LoadLevel` → pre-level → `App_PlayGame` → … The menu clicks themselves
  were verified in earlier slices (`n_click_probe.py`).
- **Frame lock (`FRAMELOCK`, default on).** N runs `(now - APP_GAMETIME_t0 +
  REMAINDER) / 25 ms` game ticks per frame from wall-clock `getTimer()`, so a
  slower player runs more ticks per frame. The probe wraps
  `_root.onEnterFrame` (= `RunApp`) and, before each call, sets
  `APP_GAMETIME_t0 = getTimer()` and `REMAINDER = 1.5 ticks`: exactly one game
  tick per frame on every player. Game logic is identical either way (it is
  per tick); the lock makes frame-based visuals (timeline animations, N's eased
  HUD timer) comparable frame for frame.
- **Freeze points (`FREEZE`, "attempt:tick,…").** At those ticks the next 30
  frames get a negative tick budget (zero ticks). The probe prints
  `ND shot <label> frame=N` at freeze frame 10; menu phases print a shot at
  their frame 20. Harnesses screenshot on that line.
- **Telemetry.** One `NF a=<attempt> t=<tick> x= y= vx= vy= st= k= time=` line
  per game tick (printed from the first input read of the tick, full double
  precision), `ND phase a->b`, and `ND EV switch|exit|kill` from thin wrappers
  on `ExitObject.PlayerHitTrigger/PlayerHitExit` and `NinjaGame.KillPlayer`.

## The script (`script.txt`)

Attempts are joined by `/`; each is `ticks:KEYS|…` (`KEYS` ⊆ `LRJ`, `-` = none).
An attempt starts when N enters `App_Tick_RunningGame` from pre-level.

| attempt | level | what happens |
|---|---|---|
| 0 | Episode 0 Level 0 "the motherlode" | launchpad + alcove wall-jump, fall to the floor → **fall death at t=293** (N's `KillPlayer` type 4) → retry prompt → Space |
| 1 | same, retried | launchpad wall-climb → octagon top → y=216 one-ways → switch ledge → top corridor → S-tube → **switch t=408** → out through the one-way → platforms → trapezoid → **door t=663** → post-level → Space |
| 2 | Episode 0 Level 1 "cloud city" | run right 120 ticks (proves level 1 loads and plays) |

## Tools

- Env knobs for `build.sh` (s26 n-pixel-pass): `START_LEVEL=k` starts on
  episode-0 level k (`gamedata.IncrementCurrentLevel` k times before
  `App_StartNewGame`); `OBJHASH=true` appends `h=<n>:<Σx>:<Σy>` to every NF
  line — an order-independent integer hash (positions ×100, rounded) of every
  clip two levels under `_root`, so drones/thwumps/doors moving differently
  diverge even when they never touch the player; `FREEZE=""` disables the
  level-0 freeze points; `CLIPDIFF=true` (with OBJHASH) traces `ND clip+/clip-`
  path + `_currentframe` for clips appearing/disappearing. N is SWF6 = case-insensitive: a probe member must not
  differ from another only by case (`objHash` IS `OBJHASH`).
- `build.sh "<script>" [out.swf]` — MTASC with the script baked in, splice into
  N at **`--min-version 6`** (N is SWF 6 and case-insensitive; v8 breaks it).
  `AUTOKILL=true` makes the probe kill the player when an attempt's script ends
  (authoring only).
- `author.py [--every N] [--nokill] [--frames F] "<attempt>" …` — TAS-style
  authoring on the local Ruffle exporter (~10–30 s per batch). With AUTOKILL,
  several candidate attempts run in one exporter session via N's retry flow.
- `ruffle_exporter_trace.txt` — the reference trace (wall-clock mode).
- Browser: `tools/divergence/game_drive/n_drive_compare.py ours|ruffle`
  (needs `docs2/examples/flasharchive/N_drive` built from this SWF and
  `N_drive_ruffle` = the N_ruffle page + this SWF + a `traceObserver`).
- Native: `python3 ../dj_probe/run_native.py n_drive.swf <dir> --frames 1800
  --capture-ticks <shot frames>` (set `SWFRECOMP_COMPILE_TIMEOUT=1500` on a
  loaded machine; N's C build takes 3–4 min).

## s26 n-levels additions

- **`START_LEVEL` now really loads level k.** N's `App_StartNewGame` hard-codes
  `App_LoadLevel(0, …)`, so before this fix the knob only bumped `curLevel`:
  you got level 0's map under level k's *name*. The probe now runs the same body
  with `App_LoadLevel(gamedata.GetCurrentLevelID(), App_StartPreLevelPause)`.
  Any "levels 1–4" result from before s26 n-levels was level 0 four times.
- `OBJHASH=true` now also appends **`o=<n>:<hash>`**, an order-dependent hash over
  N's own object list (`_root.objects.objArray`: drones, thwumps, mines, gold,
  doors, …) of `OBJ_TYPE` + `pos` to 1e-3. `h=` (the clip walk) never sees
  level objects; it sees only pooled GUI/effect clips.
- `OBJDUMP=true`: at each attempt's tick 0, prints `ND obj <i> type=<T> x= y=`,
  plus the switch (`trig=`) for exits and `door= trap= locked=` for doors.
  Types are N's `OBJTYPE_*`: 0 gold, 1 bounce block, 2 launchpad, 3 turret,
  4 floor guard, 5 player, 6 drone, 7 one-way, 8 thwump, 9 test door,
  10 homing launcher, 11 exit, 12 mine.
- `TRACKOBJ=<i>` (authoring): one `NT t= ob=x,y` line per tick for object i.
  Use it for the thwump or drone that a route has to dodge or ride.
- `search.py LEVEL PREFIX CAND…`: runs `PREFIX|CAND` attempts in one exporter
  session via `author.py`. Per attempt it prints the final position and state,
  the last standing position, and the switch/exit/non-autokill kill events.
  This is how the routes were built: grow a prefix one landing at a time.
- `routes_ep0.txt`: the replayed scripts for levels 2 (thwumps) and 4 (drone).
  Each has an enemy-death attempt followed by a completing attempt. Record:
  `SWFRecompDocs/plans/n-levels-report.md`.

## s26 n-gold-streaks additions

- `TRACKGOLD=true`: after each `RunApp` (FRAMELOCK wrapper), one
  `NG f=<frame> t=<tick> i=<objArray index> cf=<_currentframe> v=<_visible>`
  line per gold object whose clip is off frame 1 (NOT_COLLECTED). It showed
  that the pickup timelines are frame-identical on both players, so the "late
  streaks" were render-side: every instance of a morph drew the last-composed
  instance's ratio. Fixed in the runtime; fixture
  `regression/avm1_morph_instances_ratio`. Record:
  `SWFRecompDocs/plans/n-gold-streaks-report.md`.
