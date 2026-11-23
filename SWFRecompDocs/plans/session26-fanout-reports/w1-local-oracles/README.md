# s26 coordinator-run local oracles (Ruffle exporter / test runner at `0ddd12b6a`)

## w1-attached-button-dispatch
- `regression/avm1_attached_clip_button_click` trace golden: Ruffle's own test runner (`target/debug/deps/tests-*`, the
  fixture copied in as `avm1/zz_s26_attached_clip_button_click` with `input.json`) **passes against the worker's
  13-line `output.txt` at `num_frames = 15`**. At `num_frames = 1` Ruffle prints only `attached`, because it consumes one
  input step per frame. The landed fixture therefore uses `num_frames = 15`. Our harness passes at 15 in both modes.
- `attached_clip_button_click.exporter-0ddd12b6a.f0.png`: an exporter render of frame 0. All three attached squares are
  red at (100,100), (250,100) and (125,230), including `h.m2` under a `createEmptyMovieClip` holder. That confirms the
  worker's lead 1: OFFSCREEN leaves `h.m2` white.
- `3_joystick` knob request (w1-pixel-nearpass): **not satisfiable**. The row is mouse-driven (`input.json`) and the
  exporter has no input replay. Ruffle's test runner could replay the input, but it exposes no world matrix.

## w1-pixel-layer-colour (`layer-colour/`)
- `layer_group_filtered_child`, `avm2_layer_group_filtered_child`, `avm1_placed_drawing_color`: the exporter frame-1
  renders are **pixel-identical (max 0)** to the worker's analytic goldens; `avm1_placed_drawing_color` traces `done`.
  Goldens confirmed; fixtures landed in `regression/`.
- `cm_offdiag` probe: Ruffle leaves the gap at (140,30) **white (255,255,255)**, not the ≈(127,127,255) that report §3
  HOLD (a) predicted for "Flash/Ruffle". So HOLD (a) (alpha bias fills the filter bounds) is not a Ruffle behaviour:
  it needs a Flash capture or a re-derivation before anyone funds it.

## w1-runtime-robustness (`robustness/`)
- `avm1_many_defs_registry` (`-f 6`) and `avm1_pixelbounds_dynamic_child` (`-f 1`), SWFs generated from the
  prototype's `create_test_swf.py`: the exporter traces are **byte-identical to the worker's predicted outputs**,
  including `f1 ic=1` twice and `init ic=1` once. Use them as the `output.txt` goldens.

## w1-avm1-dispatch-scope (`dispatch-scope/`)
- Exporter, 8 fixtures: `bare_mc_method_scope`, `type2_mc_receiver_dispatch`, `hittest_hairline`,
  `create_text_field_depth`, `set_new_text_format_color`, `device_edittext_xscale`, `wrap_giveup_mixed_runs` and
  `mc_resolve`. **All 8 match the staged analytic `output.txt` byte for byte.**
- Ruffle test runner (an old Feb-2026 debug binary; it fires timers and replays input):
  - `timer_function_form_activation` **passes**.
  - `edittext_html_typed_runs` **differs on the second keystroke**. After typing "D" at index 0, Ruffle reports
    `c0=c1=c2=0`, where the fixture predicts 16711680. The first keystroke (append) agrees.
  - That fixture is HELD out of `regression/` until a current Ruffle runner or Flash settles it.
- `wrap_giveup_mixed_runs` and `mc_resolve` are oracle-confirmed, but our build still fails them (HOLD items 7b and
  `__resolve`). They stay in the fixtures dir for the wave-2 slot.

## w2-cm-chain-cab-edge (`cm-chain/`)
- `avm1_po3_color_matrix_live{,_nested,_clear}`: the exporter renders are **pixel-identical (max 0)** to the shipped
  goldens, and the `_clear` trace (`done`) matches.
