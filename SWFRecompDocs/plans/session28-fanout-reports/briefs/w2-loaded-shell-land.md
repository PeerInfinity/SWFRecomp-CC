**Land the loaded-shell residuals against Flash (M).**

Inputs: `w1-loaded-shell-residuals-report.md` (on master), `w1-loaded-shell-residuals-prototype.patch` (parts A–D;
`action.c`, `timer.c`), fixtures `w1-loaded-shell-residuals-fixtures/`, the s27 Flash captures the report names (§1),
and the coordinator's NEW Flash 32 captures in `w1-local-oracles/w1-loaded-shell-residuals/` (README). New Flash facts:
- `avm1_loaded_order_create_vs_load`: ≠ the prototype. `b` is delivered a tick before `a`; then every tick runs a
  before b. Re-fit A (newest load first? per-holder creation order? delivery-tick rule C′ interacting?) to this trace
  AND to the s27 captures (`avm1_child_timeline_loop` `d1 c1`, held `avm1_loaded_bare_goto` `e1 d1 c1`).
- `avm1_loaded_goto_play_deferred`: after `c3`, Flash runs `c2` then `c3` on EVERY tick (gotoAndPlay target script
  next tick, then the playing advance in the same tick?) — re-fit B.
- E: Flash prints `onLoadProgress` 2× on `avm1/mcl_unloadclip` and 3× on `avm1/mcl_target_png` (goldens: 1×). Find
  Flash's progress-event rule (per chunk? per tick until complete?) and decide whether to implement it; the corpus
  goldens are then flash_fixes candidates (report the expected moves; the coordinator adds the entries).
- `loadmovie_var_persistence`: untestable in Flash here.

Task: land A–D refitted to every Flash capture (all of them byte-exact or a named residual), apply the w1 report's
golden swaps (`avm1_child_timeline_loop` = first 32 lines of its Flash capture, `avm1_mcl_holder_totalframes`,
`avm1_mcl_load_tick`), land the held `avm1_loaded_bare_goto` and both new fixtures with their Flash goldens (trim the
direct-mode overrun to `num_frames`). Gate: the w1's 142-row loader set, both modes (NG arms). Expected: +1
`avm1/load_cancel_via_unloadmovie` rm → pass (D); list every other move by name.
