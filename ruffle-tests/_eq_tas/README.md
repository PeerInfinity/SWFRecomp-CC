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
click tick). EQ-2.5's next wall: `new Loader()` #1065 in `agi.init` (needs a
`flash.display.Loader` stub); frame3/Shell.init aborts there before `startIntro()`.
