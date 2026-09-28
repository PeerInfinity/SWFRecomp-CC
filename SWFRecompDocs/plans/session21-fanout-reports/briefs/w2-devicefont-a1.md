# w2-devicefont-a1 — land s19's device-font outline emission (A1) and flip `device-font` (wave 2, worktree, graphics)

Sources: `SWFRecompDocs/plans/session19-fanout-reports/UNLANDED-devicefont-prototype.patch` (recompiler, `SWFRecomp/src/abc/abc_devicefont.cpp`), the s19 report that built it (grep session19-fanout-reports for "A1"), playbook §19 bullet "s19's device-font A1 verdict is REOPENED", and `session20-fanout-reports/w2-gfx-text-smalls-report.md` §1.4 + leads **L3** and **L4**. The s20 bold/italic ladder (`6cf74920c`) is already on master.

Measured state: A1 + ladder leaves `visual/fonts/device-font` at **15 outlier channels vs max_outliers 3** — 5 isolated missing black pixels on a quality=low 1-bit raster, a pixel-centre-tie question (compare s19 N5), not geometry. L4: `visual/fonts/leading_device_font`'s last 6 pixels are NOT device-font — price whether it's in reach.

Steps: rebase the prototype onto HEAD (it is a recompiler patch — rebuild `SWFRecomp/build` in your worktree), productionize it (the s19 report lists its shortcuts), reproduce 15, then attack the 5 pixels by diffing our aliased fill rule at those coordinates against Ruffle's quality=low raster (`~/CC/ruffle/render`). Canary: `render_canary.py` over the standing set PLUS every corpus test that uses device fonts (grep `test.toml`/SWFs for device-font usage; the stage3d text rows `stage3d_texture`/`stage3d_fractal` need A1 — report their before/after too). A recompiler change can move trace rows: run the trace-axis tests that use device fonts too.

Siblings: w2-caret-multiline works in AVM2 EditText selection/caret drawing (`avm2_display.c`/`avm2_text.c` near the selection-highlight code) — stay out of it; you are in the recompiler + glyph raster path.
Deliverables: `SWFRecompDocs/plans/session21-fanout-reports/w2-devicefont-a1-report.md` + `SWFRecompDocs/plans/session21-fanout-reports/w2-devicefont-a1.patch`.
