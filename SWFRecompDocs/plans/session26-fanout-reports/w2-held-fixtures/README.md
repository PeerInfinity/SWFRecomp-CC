# s26 wave-2 fixtures HELD out of `regression/` (no outside-oracle golden yet)

- `avm2_applyfilter_glow_kernels` (w2-avm2-applyfilter-kernels): the Ruffle exporter `0ddd12b6a` trace
  (`output.ruffle-0ddd12b6a.txt`) differs from our output by ±1–2 on single channels in 6 of 23 lines (glow quality3,
  bevel default/outer/full-knockout). Lead: f32 uv / rounding at texel boundaries in `bd_glowlike_source_region`. Land
  the fixture with Ruffle's trace once those match (or a Flash capture says otherwise).
- `avm2_bitmapdata_draw_filtered` (same slot): Flash model (Ruffle's draw() ignores filters by design); needs a FLASH
  capture.
- `avm1_edittext_placed_cxform` (w2-text-cx-jpeg3): the Ruffle exporter render (`output.ruffle-0ddd12b6a.png`) differs from
  our lavapipe after-render by **9 px (max 64), all on EditText border/background box CORNERS** under a colour
  transform. Ruffle draws them partly covered, e.g. (64,255,64) where we have (0,255,0). The before-render had every
  field black, so the colour fix itself is confirmed. Lead: the border-corner rule under a cxform. Land the fixture with
  the exporter golden once the corners match. Its script twin `regression/avm1_edittext_placed_cxform_script` landed
  trace-only; its trace matches Ruffle.
- `avm1_loaded_bare_goto`, `avm1_loaded_unload_shell`, `avm1_loaded_shell_consumers` (w2-loaded-shell-phase2): these
  goldens are PREDICTED. The Ruffle **exporter** cannot serve them: it never loads the child SWFs. Ruffle's **test
  runner** (an old Feb-2026 debug binary) disagrees with each one (`*.ruffle-runner-diff.txt`; `<` = Ruffle,
  `>` = predicted):
  - `bare_goto`: child-load order within a tick (`e1` before `d1`) and where `p4` falls;
  - `unload_shell`: Ruffle still reports `b:movieclip` right after `h.unloadMovie()` (the unload is NOT synchronous
    there) and prints one fewer `c2`;
  - `shell_consumers`: one fewer `cx`.

  The code landed (latent-bug fixes, sweep-clean). The fixtures need a current Ruffle runner, or a re-derivation of
  load/unload tick timing, before they land. `avm1_remove_same_name_other_parent` landed (exporter trace identical).
