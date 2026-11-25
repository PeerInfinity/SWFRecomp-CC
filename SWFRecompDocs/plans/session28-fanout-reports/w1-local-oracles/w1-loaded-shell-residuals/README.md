# w1-loaded-shell-residuals local Flash oracles (s28 coordinator, 2026-11-25; FP32 LNX, direct pinned, OLD PinStub)

| request | file | result |
|---|---|---|
| 1 `avm1_loaded_order_create_vs_load`, 12 frames | `…create_vs_load.flash32.txt` | ≠ `ours.abcd.txt`: `b1` is delivered at p2→p3 (one tick before `a1`); from then on every tick runs **a before b** (`a1 b2`, `a2 b1`, …) |
| 2 `avm1_loaded_goto_play_deferred`, 12 frames | `…goto_play_deferred.flash32.txt` | ≠ ours: after `c3`, **every tick prints `c2` then `c3`** (`p5 h2 c2 c3 p6 h2 c2 c3 …`); ours prints only one per tick. Direct mode overruns `num_frames` (210 lines) |
| 3 corpus `avm1/mcl_unloadclip` | `mcl_unloadclip.flash32.txt` | **2** `onLoadProgress` lines vs the golden's 1: golden ≠ Flash (flash_fixes candidate once the rest of the row is graded) |
| 3b corpus `avm1/mcl_target_png` | `mcl_target_png.flash32.txt` | **3** `onLoadProgress` vs golden 1 |
| 4 corpus `avm1/loadmovie_var_persistence` (`--max-duration 20`) | `…var_persistence.flash32.txt` | **empty**: Flash printed nothing (the child loads don't resolve from the pinned temp dir) — untestable here |
