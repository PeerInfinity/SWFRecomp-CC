# n_click — N "play game" probe (2026-11-22)

Injected-AS probe for Metanet's N (`SWFRecomp/tests/flasharchive/N/test.swf`).
`NClick.as` logs `gui.menuMC`'s frame (`NC frame ...`), logs mouse down/up, and
at tick 60 calls N's own menu code directly (`App_StartPlayMenu`,
`gui.Display(GUI_MAINMENU/GUI_PLAYMENU)`, `gui.DisplayFrame`,
`GUIEvent_MainMenu_PlayGame`) with no wrappers, tracing `NC A..F` after each.

    ./build.sh                       # MTASC -> inject -> n_click.swf (gitignored)
    ~/CC/ruffle/target/release/exporter -s -f 62 --trace-log out.txt n_click.swf out   # oracle
    python3 ../dj_probe/run_native.py n_click.swf native_run --frames 62              # native headless
    python3 ../dj_probe/run_native.py n_click.swf native_run --frames 120 --input input_click.json
    # browser: copy n_click.swf to SWFRecomp/tests/flasharchive/N_click/test.swf, DELETE its
    # RecompiledScripts/RecompiledTags (build_test.sh does NOT re-recompile a changed SWF),
    # build_test.sh flasharchive/N_click wasm --graphics, deploy_example.sh, then
    # DISPLAY=:0 python3 tools/divergence/game_drive/n_click_probe.py flasharchive/N_click "wait@6"

Expected (Ruffle, native, and fixed browser): `NC B ... cf=6`, `C cf=2`, `D cf=6`,
`E cf=2`, `F cf=6`. Broken browser: B/D/F stay `cf=2`, and C/D hide menuMC.

Gotchas:
- Don't wrap N's functions from the probe for diagnosis. Before the fix, a
  wrapper's captured `orig()` also lost its base_clip in the browser, which
  confounded the first rounds.
- Native headless does not dispatch button events for buttons inside
  attachMovie'd clips, because `ng_update_button_states_attached` is
  browser-only (`tag.c`). A scripted click on "play game" therefore does
  nothing natively even after the fix. That is a separate gap; see
  `SWFRecomp-CC-history:SWFRecompDocs/plans/n-play-game-report.md`.
Write-up: `SWFRecomp-CC-history:SWFRecompDocs/plans/n-play-game-report.md`.
