# RWK TAS tooling (RWK-2/RWK-3, 2026-07-16..18; git-tracked as of RWK-3)

The kitty-TAS driver/trackers/plans + measured phase tables. See the
`avm2-rwk2-text-gameplay` + `avm2-rwk3-browser-demo` memories and the avm2
CURRENT_STATUS.md RWK sections. Committed so the iteration ladder +
autopsies survive scratchpad cleanup; the heavy artifacts (frame dumps,
builds) stay in session scratchpads.

- rwk_drive.py — plan compiler + runner: compiles hold()/press()/click()
  plans into the line-based event format and runs the RWK scratch build
  (paths inside point at a session scratchpad — update S/BUILD/FRAMES to
  your scratch dirs; recipe: recompile RWK injected SWF, build via
  KEEP_BUILD_DIR + verify_output_keep.py, then ./test_run <events> with
  AVM2_MAX_TICKS / AVM2_CPU_DUMP).
- rwk_track.py — world-position tracker over AVM2_CPU_DUMP frames: FFT
  phase-correlation camera tracking, anchors: kitty blob world (168,1032),
  J powerup (168,1320); player tan blob (154,143,120)/(134,124,102).
  CAVEAT: breaks after a death (camera snap) — trust it only between
  deaths; use rwk_deaths.py to find the snaps.
- rwk_aliens.py — per-tick screen positions of red alien blobs
  (r>200,g<90,b<90, x-clustered) + player. Use during a PARKED window
  (camera static) to fit patrol triangle waves. NOTE: clusterer merges
  x-adjacent aliens on different rows (avg y midway = merged pair).
- rwk_deaths.py — death/camera-snap detector (consecutive-frame MAD>18).
- plan_d.py — last RWK-2 descent plan (kept for history).
- plan_e..l.py — RWK-3 iteration ladder (each header carries its autopsy):
  e: died t938 parked on platform-1 (alien-2 period 317, not 342);
  f: died t1131 landing ON alien-2 (landing is ~295 p1-cam, not 341);
  g: the "direct right off shelf-2" route does NOT exist (1-tile step
     blocks it — plan_c's comment was aspiration, not observation);
  h: crossed p1+p2 and parked the p2 lip (world ~309) 992-1058 SAFELY,
     died t1073 landing on the floor alien (its right end is >=315,
     turn ~t1080, fall is ~15 ticks);
  i/j: same floor-pocket death at t1073 (air-steer drift too small);
  k: clean p1 landing at t1203 (one alien-2 cycle later), died ~t1240
     landing on p2 (alien-3 left-end turn is ~t1210, later than the
     t1192 model; the descent is a TWO-hop: p1 -> p2 -> floor);
  l: lip-park through alien-3's turn DIED at t~1066-1068 — alien-3's
     right-end turnaround IS the lip (world ~309). There is NO safe park
     anywhere on p2: cross it in one motion, timed from a freshly
     re-measured left-end turn (~t1210, not the t1192 model), or exploit
     the 2-tick post-turn window at the left end.

## Measured RWK physics/phases (2026-07-18 session, deterministic per run)

- Player max walk ~1.05 world px/tick (~31 px/s) — only ~1.6x alien speed
  (the RWK-2 "4x" note was wrong). Short accel ramp (~5-8 ticks).
- Aliens 0.667 world px/tick (20 px/s). Screen = 2x world zoom.
- Turn schedules (tick-anchored, valid for the standard plan prefix
  click@255 + RIGHT 285-332 + LEFT 336-366):
  - alien-2 (platform-1): left-end turns t877, t1194; right-end t1035
    (period 317; p1-cam range ~200..410).
  - alien-3 (platform-2): left-end turns t936(±5), t1192; right-end
    t1064 (period 256; shelf2-cam range ~346..516).
  - floor alien (J chamber): right-end turn ~t1059 at world ~305; period
    ~678 (world range ~79..305). Patrols through the J (world 168).
- Fall times: platform-1→platform-2 ~13 ticks; platform-2→chamber floor
  ~22 ticks.
- WORLD-coordinate map (J block at world x=168 anchors everything):
  platform-1 world ~[95,208] (alien-2 range ~[103,205]); platform-2
  world ~[208,312] (alien-3 range ~[225,310]); chamber floor ~[105,320]
  (floor alien range ~[79?,318], period ~678, right-end turn ~t1080);
  acid left of world ~105. Falls: p1->p2 and p2->floor each ~15 ticks.
- Kill range: lip parks at 3-12px survived ONLY because h/i/j left
  before alien-3's final approach (l died there at ~0-3px). Landings
  13-19px from the floor alien died (i/j). Treat <20 world px as lethal,
  prefer >=25.
- Alien-3's left-end turns: ~t1210 (k's death), i.e. period ~256 holds
  but the t936/1192 anchors are ~15-20 ticks early. Re-measure by lip-
  parking (h line) before planning across p2.

Ruffle input-scripted oracle: RUFFLE_INPUT_FILE=<ruffle-test input.json>
with the locally patched ~/CC/ruffle exporter (cargo build --release -p
exporter). GOTCHA: Flixel resets keys on state switches.
