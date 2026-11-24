# s27 coordinator-run oracles

`oracle.png` / `ruffle.txt` / `out.*` = Ruffle exporter `0ddd12b6a` (`WGPU_BACKEND=vulkan`). `flash.png` / `flash*.txt` =
real Flash Player 32 (LNX 32,0,0,465) via `tools/flash-oracle/` (`run_image.py --screen`, the draw() capture is the PNG;
`run_trace.py --wrapped` unless named `flash.direct.txt`). **Flash overrules Ruffle.**

Notable Flash-vs-Ruffle verdicts:
- `w1-text-glyph-fidelity/avm1_bitmapdata_draw_edittext`, `avm2_bitmapdata_draw_edittext_box`: in Flash, `BitmapData.draw()`
  does NOT apply a colorTransform (the draw() argument or a parent's) to a TextField's BACKGROUND (stays ff0000), while
  a tinted shape IS tinted. Ruffle tints both. On screen, Flash does tint a placed field's box (see
  `regression/avm1_edittext_placed_cxform`, Flash == golden except the 4 border-corner pixels per box).
- `w1-text-glyph-fidelity/avm1_edittext_scaled_glyphs`: Flash ≈ Ruffle (corners + edge AA).
- `w1-text-glyph-fidelity/avm2_definetext_matrix`: Flash draw() == the analytic golden at 0 px.
- `avm1_edittext_wordwrap_render`: Flash-invalid font (see its README).
- `w1-applyfilter-tail/avm1_po3_cm_*`: `folded_clear` Flash == Ruffle; `live_under_cxform` Flash vs Ruffle max 1;
  `alpha_bias_edge`: Flash anti-aliases the rect's edge pixels at half coverage (x=110, y=80: (255,127,127)); Ruffle's
  is crisp. The interior is identical.
- `w1-render-bitmap-leads/*`: Flash == the hand goldens at 0 px (both fixtures).
- `w1-exec-order/*`: Flash == Ruffle for both fixtures (traces); ours differs on the nested `inner` frame order.

## Batch 2 (s27 coordinator, after all wave-1 deliveries)

- `w1-avm1-leftovers/*`: `flash.wrapped.txt` (num_frames cut), `flash.direct.txt`, `ruffle.txt`; summary in
  `batch_w1d_summary.txt`. **Flash disagrees with the analytic/Ruffle goldens on 5 fixtures**: `path_variable_scope` and
  `_same_frame` (Flash reads undefined: the bindings do not resolve the way Ruffle's do), `resolve_dotted_getvariable`
  (Flash never calls `__resolve` for the intermediate `b`; it calls it for the final `zz` and prints `[object Object]`),
  `set_new_text_format_size` (Flash: font "Times", and size stays 12 after setNewTextFormat + text=),
  `swf6_case_insensitive_builtins` (getDepth −77824, not −16384). `swf7_case_sensitive_builtins` Flash == golden.
  `mc_button_unified_pick` and `cut_copy_selection` need mouse/clipboard input, which neither the exporter nor
  run_trace.py has: their `flash.wrapped.txt` has no input and is NOT a golden.
- `w1-timers-robustness/*` (dirs built from the generators: `<gen>_<mode>`, each with `test.swf` + `test.toml`):
  Flash fires timers; Ruffle's exporter does not, and runs DoInitActions at preload, so for these **Flash is the only
  oracle**. caps_clone/caps_watch Flash == Ruffle.
- `w1-per-movie-dl-phase3/*`: `flash.direct.txt` (direct mode, loadMovie children; runs past num_frames, compare the
  prefix) and `ruffle.txt` (exporter with local fetch). Ruffle == the shipped output.txt on all 6. Flash == it on
  `bare_goto_seq`, `shell_root_lookup`, `unload_deferred`; Flash differs on `timeline_holder`/`_xy` (Flash: the root's
  frame script runs BEFORE the holder's child frame, and the child's first frame is one tick later: `t2 tt:undefined`)
  and on `shell_consumers_seq` (`t3 d:0`: one tick later).
- `w1-browser-avm1-gaps/browser_probe_run_{a,b}.txt`: REAL browser-WASM (emsdk, WebGPU, SwiftShader, child_probe harness)
  with `w1-browser-avm1-gaps-prototype.patch` applied. The 3 fixtures and `transform`, `movieclip_create_text_field` match
  native. **Still failing in the real browser:** `movieclip_getbounds` (`undefined` where native has `50`/`164`), `color`
  (`getTransform` all 0; `getRGB` undefined), and `duplicate_movie_clip` (the predicted `load:` order HOLD). So the
  native `SWF_BROWSER_ARMS_TU` harness does not reproduce every browser arm.
