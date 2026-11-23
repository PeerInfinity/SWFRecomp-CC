# N: level completion + death/retry vs Ruffle: closeout (2026-11-22)

This one-task session follows `n-tile-color-hud` (`n-tile-color-hud-report.md` §6, "next slice's line"). Baseline: master `2f07ea49e`.

**Result: N's level completion and death/retry work on our runtime and match Ruffle tick for tick.** A deterministic input script drives N through its real game flow:
1. Episode 0 Level 0 "the motherlode": the ninja falls to his death at tick 293.
2. N's retry prompt; Space.
3. The level again: the exit switch at tick 408, then the door at tick 663.
4. The post-level screen; Space.
5. Episode 0 Level 1 "cloud city" loads and plays.

All 1528 game ticks of telemetry are **byte-identical** across four players:
- the Ruffle exporter;
- Ruffle web;
- our native graphics build;
- our browser WASM build.

The telemetry is position, velocity, state and timer at full double precision.

**No runtime divergence was found, so no runtime fix and no fixture landed.** The screenshot differences I looked at all trace to frame pacing, not rendering (§4). One small unresolved browser lead remains (§5).

## 1. The input script and how it is driven

Everything lives in `ruffle-tests/tests/swfs/_swfbridge/livetest/n_drive/`; `README.md` there has the details. N's SWF and the injected SWF are not committed.

- **Input override.** N reads input once per game tick: `GetInputState_Normal` calls `Key.isDown(KEYDEF_L/R/J)` inside `game.Tick()`. The injected probe `NDrive.as` replaces `Key.isDown` and answers from a script indexed by `game.tickCounter`. Because input is keyed on the game tick, wall-clock time can't change the motion.
  - **Ruffle protects `Key.isDown`:** a plain assignment is silently ignored. The probe calls `ASSetPropFlags(Key, "isDown", 0, 7)` first.
- **Real flow.** At the main menu the probe calls `gamedata.LoadEpisodeNum(0)` and `App_StartNewGame()`, which is what "play game" → episode 00 does. The menu clicks themselves were proven in `n-play-game-report.md`. From there it is all N's own code:
  - `App_LoadLevel` → pre-level → `App_PlayGame`;
  - fall death → `App_StartRetryMenu` → `App_ResetObjects`;
  - `App_LevelPassedEvent_Normal` → `IncrementCurrentLevel` → post-level → `App_LoadLevel(next)`.
  - Space is pressed by phase.
- **The script** (`script.txt`). Attempts are separated by `/`, segments are `ticks:keys`:
  ```
  60:L|35:LJ|3:L|10:RJ|80:R|60:-|60:R
  /60:L|40:LJ|50:R|20:RJ|16:LJ|24:L|12:LJ|40:L|10:R|5:-|35:LJ|30:L|20:R|40:-|40:R|30:R|60:-|8:R|40:-|20:L|40:-|40:R
  /120:R
  ```
  - **Attempt 0:** bottom-left launchpad, alcove wall-jump, drift right past the octagon's left face, then a fall death on the floor (N's `KillPlayer` type 4 = FALL).
  - **Attempt 1 (the route):**
    - launchpad wall-climb;
    - traverse to the octagon top (y=278);
    - running jump to the y=216 one-way platforms;
    - jump up-left onto the switch ledge (y=158). The one-way at x=190 blocks entry from the right, so the route goes:
    - full-height jump into the 24-px top corridor (y≈86);
    - slide down the S-tube to the **switch (t=408)**;
    - run out right (the one-way lets you exit);
    - drop to the platforms at (580,350), then the trapezoid;
    - fall off its left edge past the **door (t=663)**.
  - **Attempt 2:** run right on level 1.
- **Authoring.** I wrote the route TAS-style on the local Ruffle exporter with `author.py`. An `AUTOKILL` build kills the player when an attempt's script ends, so N's retry flow runs the next candidate in the same exporter session. That gives about 3 candidates per 15–30 s.
  - Trap: killing from inside the input read (in the middle of the player tick) is overwritten by the rest of the tick. The kill must happen between ticks, in the probe's `onEnterFrame`.
- **Determinism proof.** I diffed the `NF` telemetry lines per attempt: exporter vs native, exporter vs Ruffle web, exporter vs our web. All 293 + 663 + (every tick both ran in attempt 2) lines are identical, including `time=` (N's `playerCurTime`, with gold bonuses).
  - The ticks per frame varied from about 1 to about 5 between players, because N runs `elapsed/25 ms` ticks per frame. That confirms N's physics is per tick and frame-rate independent on our runtime.

## 2. Event timeline (the same on all four players)

| event | tick | frame (exporter / native / Ruffle web / our web) |
|---|---|---|
| main menu → `App_StartNewGame` | — | 28 / 28 / 28 / **27** |
| level 0 pre-level | — | 185 / 185 / 185 / **184** |
| fall death | a0 t=293 | wall-clock dependent after this point |
| retry → pre-level → run | a1 t=0 | — |
| exit switch | a1 t=408 | — |
| door / `App_LevelPassedEvent` | a1 t=663 | — |
| "Episode 0 Level 1: cloud city" pre-level → run | a2 t=0 | — |

## 3. Tools added

- `n_drive/NDrive.as`, `build.sh` (bakes the script in, splices at `--min-version 6`), `author.py`, `script.txt`, and `ruffle_exporter_trace.txt` (the reference telemetry).
- `NDrive.as` **frame lock (`FRAMELOCK`, default on).**
  - It wraps `_root.onEnterFrame` (= `RunApp`). Before each call it sets `APP_GAMETIME_t0 = getTimer()` and `REMAINDER = 1.5 × TICKLEN`, so there is exactly one game tick per frame on any player.
  - Freeze points (`FREEZE`) give a zero-tick budget for 30 frames and print `ND shot`, so harnesses can screenshot an exact tick.
  - The tick length itself is untouched, so the HUD's seconds readout stays correct.
  - Verified on the exporter: the frame-locked run's ticks are identical to the wall-clock run's.
- `tools/divergence/game_drive/n_drive_compare.py ours|ruffle` (Playwright, WSL Chrome, functional only). It loads `docs2/examples/flasharchive/N_drive` (our WASM) or `N_drive_ruffle` (the N_ruffle page plus this SWF plus a `traceObserver`). It collects `ND`/`NF` lines and screenshots the canvas on each `ND shot`.

## 4. Visual comparison (browser, wall-clock mode)

I screenshotted 10 matched states: pre-level, mid-run, retry prompt, switch open, door, post-level, level-1 pre-level and run.
- Gross content matches: tiles, HUD, retry text, the opened switch, door animation, level-1 layout.
- Every remaining difference I looked at is **frame pacing**, not rendering:
  - **HUD time readout.** In the retry frame, Ruffle shows `97.670` and ours `92.12`, with the bar length differing too. `NinjaGUI.DrawPlayerTime` eases `playerDisplayTime` toward the real time **once per drawn frame**. Our SwiftShader page ran about 5 ticks per frame against Ruffle's about 2, so our display lagged further behind. The underlying `playerCurTime` is identical (`NF time=`).
  - **Gold-pickup streaks** still visible in the S-tube at t=409 on ours. These are timeline morph animations that last a fixed number of **frames** (memory `n-play-game-click`: coin streaks are N's authored pickup morphs). Fewer frames had passed since pickup on ours.
  - The remaining per-block noise is the 881→792 resample of our canvas element (gold squares, text).
- The frame-locked pass was meant to remove pacing entirely: native vs exporter at identical frames, 1:1 pixels, and both browsers frame-locked. **It did not run.** Claude Code stopped both background builds (native N compile, WASM rebuild) because the machine ran critically low on memory, and I did not restart them. The exporter side exists (frame-locked, shots at frames 204, 486, 608, 765, 997, 1236, 1377, 1559, 1683, 1775).
  - **Next step:** `SWFRECOMP_COMPILE_TIMEOUT=1500 python3 ../dj_probe/run_native.py n_drive.swf <dir> --frames 1800 --capture-ticks 204,486,608,765,997,1236,1377,1559,1683,1775`, then a 1:1 diff against the exporter's per-frame PNGs.

## 5. Leads (unresolved, none blocks N)

1. **Browser enterFrame count is one behind.** Our browser WASM's injected clip reaches the same N state one `onEnterFrame` earlier: `startgame frame=27` against 28 on the exporter, Ruffle web and our native build. The offset stays constant afterwards. It is likely a first-frame difference in `swf.c`'s browser loop: either the clip created in root frame 1 misses one enterFrame dispatch, or the browser runs one fewer pre-roll frame. It is browser-only, so CI can't see it. Pin it with a wasm_probe: frame-1 `createEmptyMovieClip` with an onEnterFrame counter, plus a root counter, compared against native.
2. **`Key.isDown` protection parity.** Ruffle ignores `Key.isDown = f` unless `ASSetPropFlags` clears the flags first. Whether ours ignores it too is **unverified**: the probe always clears the flags. A small regression fixture would settle it: assign without `ASSetPropFlags` and trace `Key.isDown == original`, with the expected output from the exporter.
3. Brief leads, checked against N's decompiled source: N never calls `getRGB`, `getTransform`, `getBounds` or `hitTest`. So the `colorGetRGB` `#else` arm and browser `getBounds(_root)` don't affect N. Native attached-clip buttons don't matter here either, because the probe starts the game through N's own functions.

## 6. CI / Pages

- No runtime, recompiler or docs change, so no CI dispatch and no Pages deploy (there is nothing to deploy). The commit adds probe tooling, this report and a harness only.
- N on the live site already carries the tile/HUD fixes (coordinator: Pages run `45081434401` at `5a1d7b4e0`, deploy step ran).

## 7. Next slice's line

1. Finish the frame-locked visual pass (§4) when memory allows.
2. Pin the browser enterFrame off-by-one (§5.1).
3. Then extend the drive to the rest of episode 0 (levels 1–4, with thwumps and drones). The same tooling applies: author on the exporter with `author.py`, then replay on ours.
