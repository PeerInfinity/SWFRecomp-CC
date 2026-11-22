# N: "play game" did nothing — closeout (2026-11-22)

One-task session. Baseline master `eef8e94aa`. Result: **fixed**. A one-hunk
`swf.c` change makes browser-WASM N open "select episode". Picking episode 00
loads a level, Space starts it, and the ninja runs and collects gold.

## 1. Repro matrix

| Build / input | "play game" click | Direct AS call (`GUIEvent_MainMenu_PlayGame()` from a clip's onEnterFrame) |
|---|---|---|
| Ruffle exporter (oracle) | n/a (no input) | menuMC frame 2 → 6 (`play_menu`) |
| Native graphics-native headless (OFFSCREEN), `input_click.json` | **nothing**: mouse down/up reach AS (`onMouseDown` fires), but `on(release)` never runs | 2 → 6, matches Ruffle |
| Browser-WASM (WSL headed Chrome, Playwright click) before the fix | `on(release)` **fires** (`GUIEvent_MainMenu_PlayGame` runs), but menuMC stays on frame 2 | stays on 2 |
| Browser-WASM after the fix | select-episode opens | 2 → 6 |

The user-visible bug was **not a click bug**. In the browser, the synthetic
Playwright click reaches the button and the handler runs. Human and automated
clicks take the same path, so the earlier "click does nothing" report was the
handler doing nothing. No real-GPU click was needed to tell them apart: the
handler-entry trace settles it. The native "no click" row is a separate gap
(§6.1).

Builds tried: the stale `docs2/examples/flasharchive/N` deploy (pre-`161ecf124`,
the n-perf-ab build), a fresh master build (`eef8e94aa`+), and the probe build
`flasharchive/N_click` (N + `livetest/n_click/NClick.as`).

## 2. Event path

"play game" is `DefineButton2_111` with `on(release){ _root.GUIEvent_MainMenu_PlayGame(); }`.
It lives in `instance45/75` on frame 2 (`main_menu`) of `MenuMC`, an
attachMovie'd clip (`gfx.CreateSprite("MenuMC", LAYER_GUI)` →
`_level0.spritebuffer2100.MenuMC3`). The handler chain is:
`GUIEvent_MainMenu_PlayGame` → `App_StartPlayMenu` → `gui.Display(GUI_PLAYMENU=27)` →
`if (GUI_LAST_STRING_INDEX < id) DisplayFrame("play_menu")` →
`menuMC.gotoAndStop("play_menu")`. The menu's `N` key reaches the same code
from `App_Tick_MainMenu`, which runs in root context, so the keyboard shortcut
always worked.

## 3. First divergence

The probe (`NClick.as`) calls each link of the chain from its own clip's
onEnterFrame and traces menuMC's frame:

| row | Ruffle / native | browser (before) |
|---|---|---|
| B `App_StartPlayMenu()` | cf=6 | cf=2 |
| C `gui.Display(GUI_MAINMENU)` | cf=2, visible | cf=2, **menuMC hidden** |
| D `gui.Display(GUI_PLAYMENU)` | cf=6 | cf=2, hidden |
| E `gui.DisplayFrame("main_menu")` | cf=2 | cf=2 (works) |
| F `GUIEvent_MainMenu_PlayGame()` | cf=6 | cf=2 |

Row C hiding menuMC means `Display` took the text-bar branch, so
`GUI_LAST_STRING_INDEX < id` was false. A temporary `GetVariable` trace showed
that inside `Display`, `g_current_context` was the **caller** (`__nclick__`,
and for the real button, the button's parent clip), not `_root`. So
`GUI_LAST_STRING_INDEX` resolved to undefined. During boot the same lookup
worked only because the caller happened to be root.

## 4. Root cause

`swf.c` `swfStart` sets `actionSetCurrentContext(&root_movieclip)` before
`tagMain`, but only under `#ifdef OFFSCREEN_RENDER`. `swf_core.c` and the
headless build set it unconditionally. In browser-WASM, `g_current_context`
was therefore NULL while root frame 1 ran. Every `DefineFunction`/
`DefineFunction2` in that frame (N defines its whole app there) stored
`base_clip = g_current_context = NULL`. Every SWF6+ closure switch is gated on
`func->base_clip != NULL`, so these functions never switched context. They ran
in the caller's clip and resolved free variables there.

The blast radius is every browser game that defines functions on the root's
first frame and calls them from a clip event, button, or other non-root
context. It hides whenever the caller is root or the variables live on
`_global`.

## 5. Fix + fixtures

- **Fix:** `SWFModernRuntime/src/libswf/swf.c` `swfStart` removes the
  `#ifdef OFFSCREEN_RENDER` around the root-context set. That is the only
  change. OFFSCREEN already had it, and NO_GRAPHICS doesn't compile `swf.c`,
  so CI builds are byte-identical. Not CI-observable.
- **Browser fixture (red/green):** `SWFRecomp/tests/wasm_probes/closure_base_clip_root_frame`
  (trace-asserted, `trace_prefix="BC:"`). Verified **red** with the hunk
  reverted: `BC: handler LIMIT=` is empty, the bare `g(18)` call disappears,
  and `method 27 true ` has LIMIT undefined. **Green** with the fix.
- **CI behavior lock:** `ruffle-tests/tests/swfs/regression/avm1_closure_base_clip_root_frame`.
  Same MTASC SWF6 source; `output.txt` comes from the Ruffle exporter. Passes
  in both native modes locally.
- **No-regression browser spot checks (WSL SwiftShader, functional only):**
  Pacman `pacman_play_probe.py` before/after is identical (title → Play →
  frame 5↔6 game loop). Doodle Jump `dj_smoke.py` shows no errors. Minesweeper,
  Pacman and DJ title screens match before/after under a generic click/key
  script.

## 6. Playing past it

Browser, after the fix: "play game" → select episode → click `00` → "loading
level..." → "level loaded; press [spacebar] to begin" → Space (held 1 s;
SwiftShader ticks are slow, so a 150 ms tap can miss the per-tick
`Key.isDown(32)` poll) → the ninja runs right on arrow keys and collects gold.
**The ninja is controllable.**

### 6.1 Next blockers / leads (not chased)

1. **Gold pickup leaves vertical yellow streaks** where the coins were (the
   coin-disappear animation residue). This is the known "coins don't
   vanish / lasers persist" item (memory `n-laser-is-frozen-particle-sprite-not-drawing-api`),
   now reachable in real gameplay instead of only the attract demo. **Next
   slice's line.**
2. Native headless never dispatches button events for buttons inside
   attachMovie'd clips: `ng_update_button_states_attached` is browser-only in
   `tag.c` (`ng_update_button_states`). CI cannot fixture N-style menu clicks
   until it is shared with OFFSCREEN. That is a CI-visible behavior change, so
   it needs its own slice and a full graphics run.
3. Browser `getBounds(_root)` on menu children returns `6710886` for all four
   fields (native: real bounds). It is a separate browser-only gap, seen in the
   probe's child dump.
4. The in-game time bar (`timeMC`) did not show in the SwiftShader
   screenshots. Unverified; check on real GPU before filing.

## 7. CI + Pages

- **CI:** handed to the s25 coordinator. To avoid two runs publishing to
  `ruffle-test-results` at once, `8615da904` rides their next grading run
  (graphics full+images). They report the
  `regression/avm1_closure_base_clip_root_frame` row and any regressions. The
  change is CI byte-identical apart from the new row.
- **Pages:** dry run `45063270405` succeeded. Real deploy `45063635099`
  succeeded on a rerun; the first attempt failed with a transient GitHub
  artifact-API error ("No artifacts named github-pages"). The live
  `recompiler/build_info.json` reports commit `8615da9`.
- **Live verification:** `tools/browser-test/live_recompiler_run.py` uploads
  the fixture SWF to the LIVE recompiler page, then runs "Build & run in
  browser". Its trace matches Ruffle (`BC: handler LIMIT=17`, `fn 18 true` ×2,
  `method 27 true 17`, `done`). One attempt died on the known wasmer
  "oneshot canceled" intermittent; rerun it if that happens.
- **New lead (not chased):** in the in-browser recompiler's graphics host
  (DYNAMIC_HOST), the fixture's 5-line block repeats every tick. Ruffle and the
  `demo.html` build (wasm probe: exactly 5 lines) run it once. That host path
  appears to re-run a 1-frame root's frame-1 DoAction each tick. Check against
  an older deploy before calling it a regression; it is likely pre-existing.

## Tools added

- `ruffle-tests/tests/swfs/_swfbridge/livetest/n_click/` (NClick.as, build.sh,
  input_click.json, README). The README covers the stale-build gotcha:
  `build_test.sh` does **not** re-run the recompiler when `test.swf` changes,
  so delete `RecompiledScripts/` first.
- `tools/browser-test/live_recompiler_run.py`: drives the live (or local)
  in-browser recompiler page end to end and prints the run's trace.
- `tools/divergence/game_drive/n_click_probe.py`: generic browser driver
  (`click@x,y`, `key@K`, `hold@K,sec`, `wait@s`, screenshots per action),
  usable for any flasharchive demo.
