# EQ TAS tooling (Elephant Quest native drive; git-tracked as of EQ-2, 2026-07-22)

See `SWFRecompDocs/plans/avm2-elephant-quest.md` and the
`avm2-elephant-quest-bringup` memory. Committed so the recipe survives scratchpad
cleanup; the heavy artifacts (native binary, frame/tree dumps) stay in a scratch dir.

- `eq_drive.py` — recompile / build / run wrappers around verify_output.py's
  compile_native + run_binary. Set `EQ_SCRATCH` to a writable dir. Recipe:
  `python3 eq_drive.py recompile` (SWFRecomp, ulimit 4GB inside, ~15s) then
  `ulimit -v 8388608; python3 eq_drive.py build` (‑O0 no-graphics, one-file-at-a-
  time so the 209 MB draws.c never coexists with abc0_methods.c; peak ~3.3 GB,
  cold ~4 min, ccache-warm ~90s — RUN MONITORED, stop if OOM-risky) then
  `AVM2_DUMP_TREE=1 python3 eq_drive.py run play_click_events.txt 18`.
- `play_click_events.txt` — the confirmed EQ-2 Play-button click plan: a
  MOUSE_MOVE + MOUSE_DOWN_LEFT + MOUSE_UP_LEFT on `playB`'s hit-state center
  (stage px 160,240), which routes the click and advances the boot past the
  frame1 preloader to frame3 `new Shell(); shell.init()`.

## Frame-proof / grade signal
`AVM2_DUMP_TREE=1` prints a per-tick read-only display-tree dump to stderr: each
node's class/name/visible + stage-space AABB in px; for a SimpleButton the
hit/up state world bbox + center (the button's OWN self bbox is EMPTY — its state
children live in btn_hit/btn_up, not render_list). Success = the root timeline
advances off the preloader (frame-2/3 content, e.g. `musicIn_18`, appears at the
click tick).

**EQ-2.5 DONE (2026-07-22): the TITLE is reachable.** With the
`flash.display.Loader` stub (`regression/avm2_loader_stub`), the Play click →
`Shell.init` → `startIntro()` → the intro logo sequence auto-plays (AGI logo
`ag_intro_mc_499` 197f → jmtb02 logo `jmtb02_logo_505` 109f) → `Intro` frame3 →
`loadMenuFromIntro()` → **`new MainMenu()`**. Drive ≥320 ticks:
`AVM2_DUMP_TREE=1 python3 eq_drive.py run play_click_events.txt 360` — MainMenu
(title logo `titleShineIN_354` + buttons `playB`/`hsB`/`credB`/…) appears at
**tick 313, 0 errors**. **Next wall = EQ-3 New Game:** click `playB` (in the
`extras`/menu SimpleButton set) → `agi.hideAGILogin()` #1010 (agi undefined,
needs the gap #3 `agi` no-op shell), then the heavy `init2()` DOOR-build.

**EQ-3 DONE — agi shell → New Game → story → `init2()` REACHED (2026-07-22).**
- The MainMenu `playB` click at tick 321 was **too early** (menu intro still
  animating in → the pick hits the full-stage intro clips, not `playB`). The menu
  settles ~**tick 335**; `play_then_newgame_events.txt` now clicks `playB` at
  **tick 345**. New diagnostic `AVM2_MOUSE_DEBUG=1` prints the picked target per
  press/click (the pick analog of `AVM2_DUMP_TREE`).
- The gap #3 `agi` no-op shell (`avm2_display.c` `loader_load` + `AGINoopShell`,
  gate `regression/avm2_agi_shell`) clears the New Game `#1010 hideLoginStatus`.
  Driving `play_then_newgame_events.txt` (600 ticks): `clicky` completes →
  `fadeToBlack` plays → `ping` fires `startStoryFromMenu` → **`Story`/`StoryFrame`
  on stage** (tree-proven).
- `story_drive.txt` extends the drive with 4 story click-to-continues → `flagToGo`
  → `startGameFromStory` → `Game`/`LoadingThing` → **`init2()` DOOR-build runs**
  (`AVM2_DUMP_TREE=1 python3 eq_drive.py run story_drive.txt 545`, or the direct
  binary with `stdbuf -oL … | timeout` to watch `DOOR n`). **init2 is PERF-BLOCKED,
  not OOM** — ~1.7 s/door at -O0, RSS stable ~168 MB; ~1000 doors → 1000+ s. The
  init2 super-linear profile is the beat-Ruffle EQ-4 target (plan gap #2b).
