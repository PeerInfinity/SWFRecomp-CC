# s28 trace-provenance: Ruffle trace goldens vs real Flash Player 32

Done 2026-11-25. One-task local session. Baseline: graphics results `e1425f417` (38 `output_mismatch`, 259 `ruffle_matched`).

## Summary for the s28 coordinator

**212 of the 259 `ruffle_matched` "passes" hide a real Flash mismatch.** For each of them, FP32 prints the graded
`output.txt` and we do not:
- 187 are byte-equal on Linux FP32 (after the harness corrections below).
- 25 equal Windows FP32, where Linux FP32 differs only by platform. These are softer: in rows such as gnash `Math-v*` and
  avmplus `cos`, Linux FP32 equals `output.ruffle.txt`, so we may already match Linux Flash there.

Only 1 `ruffle_matched` row is a case where Ruffle was right and the golden wrong: `avm1/goto_rewind_movieclip_replace`.
It is now flash-fixed, and we print FP32's output byte for byte.

Of the 38 `output_mismatch` rows:
- 22 have a Flash golden (21 Linux, 1 Windows).
- 3 have a golden that is not Flash, and we don't match FP32 either: `movieclip_hittest_shapeflag` (flash-fixed), `swz`
  and `loader_applicationDomain` (FP32 refuses the unsigned SWZ).
- 13 are untestable on a local projector (network, sandbox, wall clock, host dialog, timezone, nondeterministic for-in).

The `ruffle_matched` bucket should therefore be booked as failing against Flash, not as passing. The trace board's
"effective pass" overstates the Flash pass by at least 187 rows (212 counting the platform splits). The other 47 `ruffle_matched` rows are:
- 40 untestable;
- 4 graded against a gnash FP10 variant that FP32 no longer prints;
- 2 where the golden is empty by Ruffle's uncaught-error convention (`slot_*`);
- `goto_rewind_movieclip_replace`.

In the passing-row sample (185 rows: `known_failure` history and multi-variant), **173 are Flash, 3 are Windows-Flash,
9 untestable, and none is wrong**. Where several `output.fpN.txt` variants exist, FP32 prints the highest variant
(the one we grade) every time, except gnash `Date-v5..8`, where it prints none of them.

**Flash fixes added (2), expected status moves:**
- `avm1/goto_rewind_movieclip_replace`: `ruffle_matched` → **pass**.
- `avm1/movieclip_hittest_shapeflag`: stays `output_mismatch`, now graded vs Flash (9-line gap). It is consistent with
  the cloud slot `w2-hittest-shape-stale`.

Both entries print `APPLIED` under `apply_flash_fixes.py --check`.

## Method

- **Runs:**
  - `tools/flash-oracle/run_trace.py`, direct mode, pinned (default), twice per row (r1/r2) on the Linux projector.
  - Every row whose pinned capture did not equal the golden was re-run three more ways: `--no-pin`, `--max-duration 20`
    (L), and once on the Windows projector (sequentially).
  - A few rows also ran with `--log-warnings`, and `goto_queued_invalid/swf9` with a 45 s cap.
- **Comparison:** `verify_output.compare_output` (the test's epsilon and number patterns). "Prefix" means the golden is
  a prefix of FP32, because direct mode runs past `num_frames`. `_url` temp-dir paths (`/tmp/flashpin-*/…/`,
  `C|/flashplayer/work/…`, the test dir) are normalised to `file:///` first.
- **Our output:**
  - 38 `output_mismatch` rows plus `goto_rewind_movieclip_replace`: local `verify_output.py --mode=graphics
    --save-actual`, under `flock /tmp/swfrecomp-cpu.lock`, one at a time.
  - `ruffle_matched` rows with a Flash golden: the results JSON `ours_diff_count` (line-index diffs vs the graded
    golden, which is the Flash target).
- **Archive:** `trace-provenance/<suite>__<test>.<run>.txt` holds every capture this doc cites with a caveat or a
  non-golden verdict. Rows whose pinned FP32 equals the golden byte for byte are not archived, because the golden IS
  the capture.
- **Verdict codes:**
  - **golden = Flash**: Linux FP32 == golden.
  - **golden = Flash (Windows FP32)**: Linux differs by platform, Windows == golden.
  - **golden ≠ Flash (we match / we don't either)**.
  - **untestable**.
  - **FP10 variant**: graded file is an older-player variant FP32 doesn't print.

## Harness findings (not Flash differences)

1. **Pinned stub leaks into `_global`.** `PinStub` defines `_global.PinStub` and `_global._quality`, and tests that
   enumerate `_global` print them (`global_proto_decls*`, gnash `argstest-v7/8`). Use `--no-pin` for those.
2. **The pinned run drops frame-1 `_root.onLoad`**, because the test is loaded as a replaced `_level0` (s28-coordinator
   finding). This affected `action_execution_order_test4`, `avm1/root_onload` and swfmill `trace-as2/root_onload`.
   `--no-pin` == golden in each case.
3. **The default cap (num_frames/fps + 2 s) truncates long single-frame dumps and slow-frame-rate tests.**
   `flash_text_TextField` came out empty; `goto_queued_invalid/swf9` (0.25 fps) needs about 45 s.
4. **`ErrorReportingEnable` goldens.** `set_property_values/swf4` and `global_proto_decls*` goldens contain
   `Warning: …` lines that only appear with `--log-warnings`, although their test.toml has no `log_warnings`.
5. **`flashenv.parse_rect` crashes** ("negative shift count") on a 0-bit RECT: swfmill `tags_after_last_showframe`.
   This is a small fix for `tools/flash-oracle/`.
6. **Debugger-only diagnostics.** The FP32 *debug* projector logs `Parameters of primitive types are no longer coerced
   into the required type - Object.` in `bitmapdata_custom_rectangle`, `path_format_test` and `getvariable-v6..8`. The
   goldens omit it, and I booked those rows as golden = Flash.
7. **Platform.** Many avmplus and gnash goldens are Windows FP32 output:
   - DST for pre-2007 dates (Windows applies current US rules);
   - libm `cos(MAX_VALUE)`;
   - no audio, mic or camera device on Xvfb;
   - I/O progress chunking.

   `--windows` is the tie-breaker for those rows.

**Harness re-run (s28 `flash-oracle-harness`, 2026-11-25):** findings 1–5 are fixed in `tools/flash-oracle/` (clean stub,
auto-unpin on a root onLoad, real-rate cap + overrun + TRUNCATED warning, auto `--log-warnings`, 0-bit RECT). The
affected rows carry a "harness re-run" note. One verdict changes: `tags_after_last_showframe` untestable → golden =
Flash. Finding 3's `flash_text_TextField` half was not truncation (the golden is empty). Record:
`flash-oracle-harness-report.md`.

## Tables

### A. Hidden gaps: `ruffle_matched` rows whose golden IS Flash (212)

Each of these counts as a pass today, but FP32 prints the graded golden and we do not. "ours vs Flash" is the verify_output line-index diff count from results `e1425f417` (`ours_diff_count`), since the graded golden is the Flash target.

| test | status @e1425f417 | graded file | verdict | ours vs Flash | notes |
|---|---|---|---|---|---|
| `avm1/asnative_instrument` | rm | `output.txt` | golden = Flash (Windows FP32) | 172 lines (idx) | Linux FP32 prints `null` for 2 device getters (no Camera/Microphone on the Xvfb host); Windows FP32 == golden |
| `avm1/asnative_sweep` | rm | `output.txt` | golden = Flash | 73 lines (idx) |  |
| `avm1/attach_movie_export_not_yet_run` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `avm1/bitmap_data_thorough/copyPixels` | rm | `output.txt` | golden = Flash | 68 lines (idx) |  |
| `avm1/bitmap_data_thorough/paletteMap` | rm | `output.txt` | golden = Flash | 68 lines (idx) |  |
| `avm1/bitmap_data_thorough/perlinNoise` | rm | `output.txt` | golden = Flash | 40 lines (idx) |  |
| `avm1/bitmapdata_custom_rectangle` | rm | `output.txt` | golden = Flash | 27 lines (idx) | equal except 3 debugger-only `Parameters of primitive types are no longer coerced…` lines the FP32 debug projector logs (Linux == Windows) |
| `avm1/form_loader_encoding_4` | rm | `output.txt` | golden = Flash | 2 lines (idx) |  |
| `avm1/load_cancel_via_unloadclip` | rm | `output.txt` | golden = Flash | 2 lines (idx) |  |
| `avm1/load_cancel_via_unloadmovie` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `avm1/mcl_replace_root_swf7_to_swf5` | rm | `output.txt` | golden = Flash | 1 lines (idx) | == golden once `_url` temp-dir paths are normalised to `file:///` |
| `avm1/mcl_replace_root_swf7_to_swf6` | rm | `output.txt` | golden = Flash | 5 lines (idx) | == golden once `_url` temp-dir paths are normalised to `file:///` |
| `avm1/tab_ordering_properties_tab_index_edge_case` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `avm1/target_paths/swf5` | rm | `output.txt` | golden = Flash | 654 lines (idx) |  |
| `avm1/target_paths/swf6` | rm | `output.txt` | golden = Flash | 654 lines (idx) |  |
| `avm1/textfield_props_swf5` | rm | `output.txt` | golden = Flash | 2 lines (idx) |  |
| `avm1/virtual_property_recursion_swf6` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `avm1/watch_recursion_double_swf6` | rm | `output.txt` | golden = Flash | 4 lines (idx) | equal except trailing spaces: FP32 prints `o2.prop1: ` (golden stripped) |
| `avm1/watch_recursion_swf6` | rm | `output.txt` | golden = Flash | 1 lines (idx) | equal except trailing space on 1 line (golden stripped) |
| `avm2/array_access_oob_interpreter` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `avm2/array_sort_swf10_64bit` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `avm2/blend_transform` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `avm2/bounds_mode` | rm | `output.txt` | golden = Flash | 6 lines (idx) |  |
| `avm2/coerce_to_primitive_side_effects_with_nulls` | rm | `output.txt` | golden = Flash | 4 lines (idx) |  |
| `avm2/dictionary_weak_keys` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `avm2/displayobjectcontainer_stopallmovieclips_nonconstructed` | rm | `output.txt` | golden = Flash | 15 lines (idx) |  |
| `avm2/edittext_device_transform_layout` | rm | `output.txt` | golden = Flash | 20 lines (idx) |  |
| `avm2/edittext_getcharboundaries_culling` | rm | `output.txt` | golden = Flash | 300 lines (idx) |  |
| `avm2/edittext_getcharboundaries_missing_embedded_font` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `avm2/edittext_set_text_same_after_edits` | rm | `output.txt` | golden = Flash | 48 lines (idx) |  |
| `avm2/edittext_tab_stops` | rm | `output.txt` | golden = Flash | 6 lines (idx) |  |
| `avm2/encode_uri_surrogate_pair_swf10` | rm | `output.txt` | golden = Flash | 15 lines (idx) |  |
| `avm2/event_handler_exception` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `avm2/freestanding_superclass` | rm | `output.txt` | golden = Flash | 2 lines (idx) |  |
| `avm2/gradient_values_readback` | rm | `output.txt` | golden = Flash | 12 lines (idx) |  |
| `avm2/graphics_draw_path` | rm | `output.txt` | golden = Flash | 50 lines (idx) |  |
| `avm2/groupelement_text` | rm | `output.txt` | golden = Flash | 2 lines (idx) |  |
| `avm2/html_text_img_parsing` | rm | `output.txt` | golden = Flash (Windows FP32) | 95 lines (idx) | missing <img> URL: Linux FP32 #2124 "unknown type", Windows FP32 #2035 == golden |
| `avm2/int_toexponential` | rm | `output.txt` | golden = Flash | 76 lines (idx) |  |
| `avm2/json_parse_numbers` | rm | `output.txt` | golden = Flash | 4 lines (idx) |  |
| `avm2/loader_events_2` | rm | `output.txt` | golden = Flash | 30 lines (idx) |  |
| `avm2/matrix3d_recompose_edge_cases` | rm | `output.txt` | golden = Flash | 8 lines (idx) |  |
| `avm2/number_convert_errors` | rm | `output.txt` | golden = Flash | 706 lines (idx) |  |
| `avm2/number_to_string` | rm | `output.txt` | golden = Flash | 104 lines (idx) |  |
| `avm2/primitive_bound_methods` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `avm2/simplebutton_childevents_multichild` | rm | `output.txt` | golden = Flash | 101 lines (idx) |  |
| `avm2/simplebutton_childevents_script_order` | rm | `output.txt` | golden = Flash | 4 lines (idx) | pinned run reorders 1 line (replaced-_level0 artifact); `--no-pin` == golden (prefix; FP32 runs on) |
| `avm2/soundchannel_soundcomplete` | rm | `output.txt` | golden = Flash (Windows FP32) | 10 lines (idx) | Linux FP32 has no audio device, so soundComplete never fires; Windows == golden |
| `avm2/swf_9_goto_in_construct_frame` | rm | `output.txt` | golden = Flash | 12 lines (idx) |  |
| `avm2/textblock_line_changes` | rm | `output.txt` | golden = Flash | 44 lines (idx) |  |
| `avm2/textblock_recreateline` | rm | `output.txt` | golden = Flash | 137 lines (idx) |  |
| `avm2/textblock_releaselines` | rm | `output.txt` | golden = Flash | 4 lines (idx) |  |
| `avm2/textline_atom_index_at_char_index` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `avm2/uint_toexponential` | rm | `output.txt` | golden = Flash | 100 lines (idx) |  |
| `avm2/uncaught_errors_stringified` | rm | `output.txt` | golden = Flash (Windows FP32) | 15 lines (idx) | Linux FP32 drops 1 line; Windows == golden |
| `avm2/vector_indexing_cutoffs` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `avm2/weird_superinterface_properties` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `fonts/device_font_no_ink` | rm | `output.txt` | golden = Flash | 14 lines (idx) |  |
| `from_avmplus/as3/Array/bug_535446` | rm | `output.txt` | golden = Flash | 4 lines (idx) |  |
| `from_avmplus/as3/Array/length_mods` | rm | `output.txt` | golden = Flash | 5 lines (idx) |  |
| `from_avmplus/as3/Math/e15_1_2_2` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_avmplus/as3/RegExp/replace` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `from_avmplus/as3/RuntimeErrors/Error1095XmlUnterminatedAttr` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_avmplus/as3/Types/Number/cos` | rm | `output.txt` | golden = Flash (Windows FP32) | 1 lines (idx) | `cos(Number.MAX_VALUE)`: Linux libm gives the ECMA value (== output.ruffle.txt), Windows == golden |
| `from_avmplus/as3/Types/Number/e15_7_4_6_1/swf14` | rm | `output.txt` | golden = Flash | 18 lines (idx) |  |
| `from_avmplus/as3/Types/Number/e15_7_4_6_1/swf15` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `from_avmplus/e4x/XML/bug_564468` | rm | `output.txt` | golden = Flash | 4 lines (idx) |  |
| `from_avmplus/e4x/XML/e13_4_4_30` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `from_avmplus/e4x/XML/misc_errors` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_avmplus/e4x/XML/setNotification` | rm | `output.txt` | golden = Flash | 13 lines (idx) |  |
| `from_avmplus/e4x/XMLList/e13_5_4_18` | rm | `output.txt` | golden = Flash | 2 lines (idx) |  |
| `from_avmplus/ecma3/Date/e15_9_4_2_1` | rm | `output.txt` | golden = Flash | 2 lines (idx) |  |
| `from_avmplus/ecma3/Date/e15_9_5_10_10` | rm | `output.txt` | golden = Flash (Windows FP32) | 31 lines (idx) | DST for 1998: Windows FP32 applies current US rules (== golden), Linux FP32 the historical tz database |
| `from_avmplus/ecma3/Date/e15_9_5_10_11` | rm | `output.txt` | golden = Flash (Windows FP32) | 93 lines (idx) | DST for 1999: Windows FP32 == golden, Linux uses historical rules |
| `from_avmplus/ecma3/Date/e15_9_5_22_1` | rm | `output.txt` | golden = Flash | 66 lines (idx) |  |
| `from_avmplus/ecma3/Date/e15_9_5_28_1` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `from_avmplus/ecma3/Date/e15_9_5_29_1` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_avmplus/ecma3/Date/e15_9_5_35_1` | rm | `output.txt` | golden = Flash (Windows FP32) | 9 lines (idx) | DST for 1970: Windows FP32 == golden, Linux uses historical rules |
| `from_avmplus/ecma3/JSON/Classes` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `from_avmplus/ecma3/JSON/adhoc` | rm | `output.txt` | golden = Flash | 5 lines (idx) |  |
| `from_avmplus/ecma3/Number/eregress_121952` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_avmplus/ecma3/Number/toStringLimits` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_avmplus/misc/bug_508617` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `from_avmplus/regress/bug_479786` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_avmplus/regress/bug_539328` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `from_avmplus/regress/bug_558863_swf10` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_avmplus/regress/bug_609416_swf10` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_avmplus/regress/bug_638233` | rm | `output.txt` | golden = Flash | 2 lines (idx) |  |
| `from_gnash/actionscript.all/ASnative-v5` | rm | `output.txt` | golden = Flash (Windows FP32) | 35 lines (idx) | Linux FP32 differs on -5/+5 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/ASnative-v6` | rm | `output.txt` | golden = Flash (Windows FP32) | 40 lines (idx) | Linux FP32 differs on -5/+5 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/ASnative-v7` | rm | `output.txt` | golden = Flash (Windows FP32) | 40 lines (idx) | Linux FP32 differs on -5/+5 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/ASnative-v8` | rm | `output.txt` | golden = Flash (Windows FP32) | 40 lines (idx) | Linux FP32 differs on -5/+5 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/BitmapData-v8` | rm | `output.txt` | golden = Flash | 8 lines (idx) |  |
| `from_gnash/actionscript.all/ExternalInterface-v8` | rm | `output.txt` | golden = Flash | 4 lines (idx) |  |
| `from_gnash/actionscript.all/Function-v5` | rm | `output.fp13-18.txt` | golden = Flash | 10 lines (idx) |  |
| `from_gnash/actionscript.all/Global-v6` | rm | `output.txt` | golden = Flash | 9 lines (idx) |  |
| `from_gnash/actionscript.all/HitTest-v6` | rm | `output.txt` | golden = Flash | 8 lines (idx) |  |
| `from_gnash/actionscript.all/HitTest-v7` | rm | `output.txt` | golden = Flash | 8 lines (idx) |  |
| `from_gnash/actionscript.all/HitTest-v8` | rm | `output.txt` | golden = Flash | 9 lines (idx) |  |
| `from_gnash/actionscript.all/Inheritance-v5` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_gnash/actionscript.all/Inheritance-v6` | rm | `output.txt` | golden = Flash | 9 lines (idx) |  |
| `from_gnash/actionscript.all/Inheritance-v7` | rm | `output.txt` | golden = Flash | 5 lines (idx) |  |
| `from_gnash/actionscript.all/Inheritance-v8` | rm | `output.txt` | golden = Flash | 5 lines (idx) |  |
| `from_gnash/actionscript.all/LoadVars-v6` | rm | `output.txt` | golden = Flash | 6 lines (idx) |  |
| `from_gnash/actionscript.all/LoadVars-v7` | rm | `output.txt` | golden = Flash | 6 lines (idx) |  |
| `from_gnash/actionscript.all/LoadVars-v8` | rm | `output.txt` | golden = Flash | 6 lines (idx) |  |
| `from_gnash/actionscript.all/Math-v5` | rm | `output.txt` | golden = Flash (Windows FP32) | 5 lines (idx) | Linux FP32 differs on -5/+5 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/Math-v6` | rm | `output.txt` | golden = Flash (Windows FP32) | 5 lines (idx) | Linux FP32 differs on -5/+5 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/Math-v7` | rm | `output.txt` | golden = Flash (Windows FP32) | 5 lines (idx) | Linux FP32 differs on -5/+5 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/Math-v8` | rm | `output.txt` | golden = Flash (Windows FP32) | 5 lines (idx) | Linux FP32 differs on -5/+5 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/Microphone-v6` | rm | `output.txt` | golden = Flash (Windows FP32) | 31 lines (idx) | Linux FP32 differs on -31/+31 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/Microphone-v7` | rm | `output.txt` | golden = Flash (Windows FP32) | 31 lines (idx) | Linux FP32 differs on -31/+31 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/Microphone-v8` | rm | `output.txt` | golden = Flash (Windows FP32) | 31 lines (idx) | Linux FP32 differs on -31/+31 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/MovieClip-v5` | rm | `output.txt` | golden = Flash | 11 lines (idx) |  |
| `from_gnash/actionscript.all/MovieClip-v6` | rm | `output.fp23.txt` | golden = Flash | 20 lines (idx) |  |
| `from_gnash/actionscript.all/MovieClip-v7` | rm | `output.fp23.txt` | golden = Flash | 20 lines (idx) |  |
| `from_gnash/actionscript.all/MovieClip-v8` | rm | `output.fp23.txt` | golden = Flash (Windows FP32) | 25 lines (idx) | Linux FP32 differs on -1/+1 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/MovieClipLoader-v7` | rm | `output.txt` | golden = Flash (Windows FP32) | 118 lines (idx) | Linux FP32 differs on -3/+18 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/MovieClipLoader-v8` | rm | `output.txt` | golden = Flash (Windows FP32) | 118 lines (idx) | Linux FP32 differs on -3/+18 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/Number-v5` | rm | `output.txt` | golden = Flash | 8 lines (idx) |  |
| `from_gnash/actionscript.all/Object-v5` | rm | `output.fp18-20.txt` | golden = Flash | 3 lines (idx) |  |
| `from_gnash/actionscript.all/Object-v6` | rm | `output.fp18-20.txt` | golden = Flash | 8 lines (idx) |  |
| `from_gnash/actionscript.all/Object-v7` | rm | `output.fp18-20.txt` | golden = Flash | 8 lines (idx) |  |
| `from_gnash/actionscript.all/Object-v8` | rm | `output.fp18-20.txt` | golden = Flash | 8 lines (idx) |  |
| `from_gnash/actionscript.all/Selection-v6` | rm | `output.txt` | golden = Flash | 7 lines (idx) |  |
| `from_gnash/actionscript.all/Selection-v7` | rm | `output.txt` | golden = Flash | 7 lines (idx) |  |
| `from_gnash/actionscript.all/Selection-v8` | rm | `output.txt` | golden = Flash | 7 lines (idx) |  |
| `from_gnash/actionscript.all/Sound-v5` | rm | `output.txt` | golden = Flash | 14 lines (idx) |  |
| `from_gnash/actionscript.all/String-v5` | rm | `output.txt` | golden = Flash | 18 lines (idx) |  |
| `from_gnash/actionscript.all/String-v6` | rm | `output.txt` | golden = Flash | 9 lines (idx) |  |
| `from_gnash/actionscript.all/String-v7` | rm | `output.txt` | golden = Flash | 9 lines (idx) |  |
| `from_gnash/actionscript.all/String-v8` | rm | `output.txt` | golden = Flash | 9 lines (idx) |  |
| `from_gnash/actionscript.all/TextField-v5` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `from_gnash/actionscript.all/TextFormat-v7` | rm | `output.txt` | golden = Flash | 38 lines (idx) |  |
| `from_gnash/actionscript.all/TextFormat-v8` | rm | `output.fp10.txt` | golden = Flash (Windows FP32) | 36 lines (idx) | Linux FP32 differs on -10/+10 lines; Windows FP32 == golden |
| `from_gnash/actionscript.all/Transform-v8` | rm | `output.fp10.txt` | golden = Flash | 7 lines (idx) |  |
| `from_gnash/actionscript.all/XML-v5` | rm | `output.fp10.txt` | golden = Flash | 10 lines (idx) |  |
| `from_gnash/actionscript.all/XML-v6` | rm | `output.fp10.txt` | golden = Flash | 3 lines (idx) |  |
| `from_gnash/actionscript.all/XML-v7` | rm | `output.fp10.txt` | golden = Flash | 3 lines (idx) |  |
| `from_gnash/actionscript.all/XML-v8` | rm | `output.fp10.txt` | golden = Flash | 24 lines (idx) |  |
| `from_gnash/actionscript.all/XMLNode-v5` | rm | `output.fp11.txt` | golden = Flash | 3 lines (idx) |  |
| `from_gnash/actionscript.all/XMLNode-v6` | rm | `output.fp11.txt` | golden = Flash | 3 lines (idx) |  |
| `from_gnash/actionscript.all/XMLNode-v7` | rm | `output.fp11.txt` | golden = Flash | 3 lines (idx) |  |
| `from_gnash/actionscript.all/XMLNode-v8` | rm | `output.fp10.txt` | golden = Flash | 3 lines (idx) |  |
| `from_gnash/actionscript.all/array-v5` | rm | `output.txt` | golden = Flash | 5 lines (idx) |  |
| `from_gnash/actionscript.all/array-v6` | rm | `output.fp24.txt` | golden = Flash | 6 lines (idx) |  |
| `from_gnash/actionscript.all/array-v7` | rm | `output.fp24.txt` | golden = Flash | 5 lines (idx) |  |
| `from_gnash/actionscript.all/array-v8` | rm | `output.fp24.txt` | golden = Flash | 5 lines (idx) |  |
| `from_gnash/actionscript.all/ops-v5` | rm | `output.fp10.txt` | golden = Flash | 7 lines (idx) |  |
| `from_gnash/actionscript.all/ops-v6` | rm | `output.fp10.txt` | golden = Flash | 7 lines (idx) |  |
| `from_gnash/actionscript.all/ops-v7` | rm | `output.fp10.txt` | golden = Flash | 7 lines (idx) |  |
| `from_gnash/actionscript.all/ops-v8` | rm | `output.txt` | golden = Flash | 7 lines (idx) |  |
| `from_gnash/actionscript.all/setProperty-v5` | rm | `output.fp10.txt` | golden = Flash | 49 lines (idx) |  |
| `from_gnash/actionscript.all/setProperty-v6` | rm | `output.fp10.txt` | golden = Flash | 49 lines (idx) |  |
| `from_gnash/actionscript.all/setProperty-v7` | rm | `output.fp10.txt` | golden = Flash | 49 lines (idx) |  |
| `from_gnash/actionscript.all/setProperty-v8` | rm | `output.fp10.txt` | golden = Flash | 49 lines (idx) |  |
| `from_gnash/actionscript.all/toString_valueOf-v5` | rm | `output.txt` | golden = Flash | 34 lines (idx) |  |
| `from_gnash/actionscript.all/toString_valueOf-v6` | rm | `output.txt` | golden = Flash | 5 lines (idx) |  |
| `from_gnash/actionscript.all/toString_valueOf-v7` | rm | `output.txt` | golden = Flash | 5 lines (idx) |  |
| `from_gnash/actionscript.all/toString_valueOf-v8` | rm | `output.txt` | golden = Flash | 5 lines (idx) |  |
| `from_gnash/actionscript.all/with-v5` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `from_gnash/actionscript.all/with-v6` | rm | `output.txt` | golden = Flash | 6 lines (idx) |  |
| `from_gnash/actionscript.all/with-v7` | rm | `output.txt` | golden = Flash | 6 lines (idx) |  |
| `from_gnash/actionscript.all/with-v8` | rm | `output.txt` | golden = Flash | 6 lines (idx) |  |
| `from_gnash/misc-ming.all/DrawingApiTest` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_gnash/misc-ming.all/EmbeddedFontTest` | rm | `output.txt` | golden = Flash | 27 lines (idx) |  |
| `from_gnash/misc-ming.all/TextSnapshotTest` | rm | `output.fp10.txt` | golden = Flash | 81 lines (idx) |  |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test` | rm | `output.fp10.txt` | golden = Flash | 12 lines (idx) |  |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test4` | rm | `output.txt` | golden = Flash | 7 lines (idx) | pinned run drops frame-1 `_root.onLoad` (replaced-_level0 artifact, s28-coordinator finding); `--no-pin` == golden · **harness re-run (s28 flash-oracle-harness, default flags):** root onLoad auto-detected → unpinned → byte-identical |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test6` | rm | `output.txt` | golden = Flash | 5 lines (idx) |  |
| `from_gnash/misc-ming.all/callFunction_test` | rm | `output.txt` | golden = Flash | 6 lines (idx) |  |
| `from_gnash/misc-ming.all/displaylist_depths/displaylist_depths_test` | rm | `output.txt` | golden = Flash | 7 lines (idx) |  |
| `from_gnash/misc-ming.all/displaylist_depths/displaylist_depths_test2` | rm | `output.txt` | golden = Flash | 14 lines (idx) |  |
| `from_gnash/misc-ming.all/displaylist_depths/displaylist_depths_test3` | rm | `output.txt` | golden = Flash | 13 lines (idx) |  |
| `from_gnash/misc-ming.all/duplicate_movie_clip_test` | rm | `output.txt` | golden = Flash | 4 lines (idx) |  |
| `from_gnash/misc-ming.all/init_action/InitActionTest` | rm | `output.txt` | golden = Flash | 6 lines (idx) |  |
| `from_gnash/misc-ming.all/loading/LoadBitmapTest` | rm | `output.fp11.txt` | golden = Flash | 2 lines (idx) |  |
| `from_gnash/misc-ming.all/loop/loop_test10` | rm | `output.txt` | golden = Flash | 23 lines (idx) |  |
| `from_gnash/misc-ming.all/loop/loop_test6` | rm | `output.txt` | golden = Flash | 11 lines (idx) |  |
| `from_gnash/misc-ming.all/loop/loop_test7` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_gnash/misc-ming.all/matrix_test` | rm | `output.txt` | golden = Flash | 5 lines (idx) |  |
| `from_gnash/misc-ming.all/path_format_test` | rm | `output.txt` | golden = Flash | 28 lines (idx) | equal except 1 debugger-only `Parameters of primitive types…` line |
| `from_gnash/misc-ming.all/place_object_test` | rm | `output.txt` | golden = Flash | 14 lines (idx) |  |
| `from_gnash/misc-ming.all/place_object_test2` | rm | `output.txt` | golden = Flash | 22 lines (idx) |  |
| `from_gnash/misc-ming.all/register_class/registerClassTest2` | rm | `output.txt` | golden = Flash | 8 lines (idx) |  |
| `from_gnash/misc-ming.all/replace_buttons1test` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `from_gnash/misc-mtasc.all/levels` | rm | `output.txt` | golden = Flash | 15 lines (idx) |  |
| `from_gnash/misc-swfc.all/action_execution_order_test10` | rm | `output.txt` | golden = Flash | 11 lines (idx) |  |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval` | rm | `output.txt` | golden = Flash | 18 lines (idx) |  |
| `from_gnash/misc-swfc.all/gotoFrameFromInterval2` | rm | `output.txt` | golden = Flash | 18 lines (idx) |  |
| `from_gnash/misc-swfc.all/movieclip_destruction_test1` | rm | `output.txt` | golden = Flash | 12 lines (idx) |  |
| `from_gnash/misc-swfc.all/registerclass_test3` | rm | `output.txt` | golden = Flash | 12 lines (idx) |  |
| `from_gnash/misc-swfmill.all/zeroframe_definesprite` | rm | `output.txt` | golden = Flash | 2 lines (idx) |  |
| `from_shumway/MaskTest-3` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_shumway/acid/acid-shapes-testing` | rm | `output.txt` | golden = Flash | 12 lines (idx) |  |
| `from_shumway/acid/acid-text-x` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_shumway/acid/acid-textfield` | rm | `output.txt` | golden = Flash | 6 lines (idx) |  |
| `from_shumway/as3-loader/LoaderTest` | rm | `output.txt` | golden = Flash | 2 lines (idx) |  |
| `from_shumway/as3-loader/events/loader-events` | rm | `output.txt` | golden = Flash (Windows FP32) | 20 lines (idx) | Linux FP32 adds 4096/8192-byte progress events (I/O chunking); Windows == golden |
| `from_shumway/avm1movie` | rm | `output.txt` | golden = Flash | 12 lines (idx) |  |
| `from_shumway/avm2/flash/geom/transform/pixelBounds` | rm | `output.txt` | golden = Flash | 1 lines (idx) |  |
| `from_shumway/flash_text_TextField` | rm | `output.txt` | golden = Flash | 5 lines (idx) | pinned 2 s run empty; the 20 s run == golden · **harness re-run (s28 flash-oracle-harness, default flags):** byte-identical at the default cap; the golden is EMPTY (Flash prints only FAILs), so the 2 s run was never truncated |
| `from_shumway/flash_text_TextField2` | rm | `output.txt` | golden = Flash (Windows FP32) | 9 lines (idx) | Linux drops blank lines; Windows == golden |
| `from_shumway/getobjectsunderpoint` | rm | `output.txt` | golden = Flash | 9 lines (idx) |  |
| `from_shumway/timeline/nav/clipDepth` | rm | `output.txt` | golden = Flash | 4 lines (idx) |  |
| `mixed_avm/avm2_loads_avm1_events` | rm | `output.txt` | golden = Flash | 18 lines (idx) |  |
| `swf/lzma_length_too_long` | rm | `output.txt` | golden = Flash | 68 lines (idx) |  |
| `swf/swf_length_too_long` | rm | `output.txt` | golden = Flash | 6 lines (idx) |  |
| `timeline/frame_script_button_order` | rm | `output.txt` | golden = Flash | 2 lines (idx) |  |
| `timeline/swf_9_event_goto_frame_script` | rm | `output.txt` | golden = Flash | 2 lines (idx) |  |
| `timeline/swf_9_frame_script_dynamic_goto` | rm | `output.txt` | golden = Flash | 3 lines (idx) |  |
| `visual/edittext/edittext_device_transform_metrics` | rm | `output.txt` | golden = Flash | 8 lines (idx) |  |

### B. Every other board row: the 38 `output_mismatch` rows and the remaining `ruffle_matched` rows (85)

For `output_mismatch` rows with a local graphics run, "ours vs Flash" is the difflib -/+ line count against the Flash target; otherwise it is `expected_lines − matching_lines` from the results JSON.

| test | status @e1425f417 | graded file | verdict | ours vs Flash | notes |
|---|---|---|---|---|---|
| `avm1/external_interface_monkeypatch` | mm | `output.txt` | golden = Flash | -96/+22 |  |
| `avm1/global_proto_decls` | mm | `output.txt` | golden = Flash | -2226/+1529 | pinned run leaks PinStub `_global` names; `--no-pin --log-warnings` == golden · **harness re-run (s28 flash-oracle-harness, default flags):** new stub, pinned, no flags → byte-identical (no `--no-pin`/`--log-warnings` needed) |
| `avm1/global_proto_decls_delete` | mm | `output.txt` | golden = Flash | -2280/+493 | `--log-warnings` == golden except 1 line: `System.capabilities.manufacturer` enumeration position (its value is host-dependent: "Adobe Linux" vs "Adobe Windows") · **harness re-run (s28 flash-oracle-harness, default flags):** auto `--log-warnings` + new stub, pinned → golden except the same `manufacturer` line |
| `avm1/globals_swf5` | mm | `output.txt` | golden = Flash | -10/+10 |  |
| `avm1/native_objects_swf6` | mm | `output.txt` | golden = Flash | -1/+1 |  |
| `avm1/set_property_values/swf4` | mm | `output.txt` | golden = Flash | -317/+489 | golden carries ErrorReportingEnable warnings; `--log-warnings` == golden · **harness re-run (s28 flash-oracle-harness, default flags):** auto `--log-warnings` (golden has `Warning:` lines) → byte-identical |
| `avm2/avm1_root` | mm | `output.txt` | golden = Flash | -44/+20 |  |
| `avm2/bom` | mm | `output.txt` | golden = Flash | -3/+3 |  |
| `avm2/number_tostring` | mm | `output.txt` | golden = Flash | -168/+168 |  |
| `avm2/verify_method_info_duplicate` | mm | `output.txt` | golden = Flash | -1/+0 | equal except the blank line Flash logs after each uncaught error (Ruffle golden convention omits it) |
| `from_gnash/actionscript.all/argstest-v7` | mm | `output.fp32.txt` | golden = Flash | -971/+1554 | `--no-pin` == golden except the `System.capabilities.manufacturer` enumeration position (host value) · **harness re-run (s28 flash-oracle-harness, default flags):** new stub, pinned → `--no-pin` result (only the `manufacturer` position) |
| `from_gnash/misc-ming.all/action_order/ActionOrderTest3` | mm | `output.txt` | golden = Flash | 59 lines (idx) |  |
| `from_gnash/misc-ming.all/action_order/ActionOrderTest4` | mm | `output.txt` | golden = Flash | 50 lines (idx) |  |
| `from_gnash/misc-ming.all/action_order/ActionOrderTest5` | mm | `output.txt` | golden = Flash | 44 lines (idx) |  |
| `from_gnash/misc-ming.all/action_order/action_execution_order_extend_test` | mm | `output.fp10.txt` | golden = Flash | 24 lines (idx) |  |
| `from_gnash/misc-ming.all/action_order/action_execution_order_test11` | mm | `output.txt` | golden = Flash | 6 lines (idx) |  |
| `from_gnash/misc-ming.all/register_class/RegisterClassTest4` | mm | `output.txt` | golden = Flash | 35 lines (idx) |  |
| `from_gnash/misc-swfc.all/action_execution_order_test12` | mm | `output.fp10.txt` | golden = Flash | 3 lines (idx) |  |
| `from_gnash/misc-swfc.all/matrix_accuracy_test1` | mm | `output.fp10.txt` | golden = Flash | 3 lines (idx) |  |
| `from_shumway/esc` | mm | `output.txt` | golden = Flash | 2 lines (idx) |  |
| `mixed_avm/avm1_loads_avm2` | mm | `output.txt` | golden = Flash | 4 lines (idx) |  |
| `avm1/movieclip_hittest_shapeflag` | mm | `output.txt` | golden ≠ Flash (we don't either) | -9/+9 | FP32 returns `false` for 3 shapeFlag hitTests the golden calls `true` (Linux pinned, --no-pin, Windows identical; stage 800 px, points on-stage) |
| `avm2/loader_applicationDomain` | mm | `output.txt` | golden ≠ Flash (we don't either) | ours empty; FP32 3 lines | FP32 refuses the unsigned .swz: `Error #2044: Unhandled securityError … #2046 The loaded file did not have a valid signature` (Linux == Windows); golden lists the loaded classes |
| `avm2/swz` | mm | `output.txt` | golden ≠ Flash (we don't either) | ours empty; FP32 3 lines | FP32 refuses the unsigned .swz (#2046 securityError, Linux == Windows); golden lists the asset classes |
| `from_gnash/actionscript.all/argstest-v6` | mm | `output.fp32.txt` | golden = Flash (Windows FP32) | -1019/+1471 | Linux FP32 differs on -1/+1 lines; Windows FP32 == golden |
| `avm1/bitmap_data_thorough/pixelDissolve` | mm | `output.txt` | untestable |  | FP32 (Linux and Windows) stops after `pixelDissolve(…, 100, -2, …)`: the last 945 golden lines never print in 20 s. Script stall; golden tail unverifiable |
| `avm1/date` | mm | `output.txt` | untestable |  | wall-clock date/time (Ruffle --deterministic time; FP32 uses the real clock) |
| `avm1/global_instance_decls` | mm | `output.txt` | untestable |  | host timezone on 1 Date line (golden GMT+0200); otherwise == Flash, plus 1 trailing-whitespace line |
| `avm1/globals_monkeypatch` | mm | `output.txt` | untestable |  | `FileReference.browse` opens a host file dialog; the last 38 golden lines need it |
| `avm1/sandbox_type_remote` | mm | `output.txt` | untestable |  | needs a remote (network) sandbox; a local projector is `localTrusted` |
| `avm2/dependent_strings` | mm | `output.txt` | untestable |  | Ruffle-internal `ruffle::isDependent()` (existing RvF entry); FP32 prints empty lines |
| `avm2/loader_load` | mm | `output.txt` | untestable |  | network (POST to localhost:8000; Ruffle `Navigator::fetch` instrumentation lines) |
| `avm2/sandbox_type_remote` | mm | `output.txt` | untestable |  | needs a remote (network) sandbox |
| `from_avmplus/ecma3/Statements/eforin_001` | mm | `output.txt` | untestable |  | for-in order is nondeterministic in FP32 (the no-pin run == golden, the pinned run is not) |
| `from_avmplus/ecma3/Statements/eforin_002` | mm | `output.txt` | untestable |  | for-in order is nondeterministic in FP32 (r1 != r2) |
| `from_gnash/actionscript.all/argstest-v8` | mm | `output.fp32.txt` | untestable |  | `FileReference.browse()` opens a host dialog on Linux and blocks; Windows drops 30 tail lines |
| `from_gnash/misc-ming.all/GradientFillTest` | mm | `output.fp10.txt` | untestable |  | pixel read-back of rendered gradients: Linux 39 lines, Windows 2 lines (±1 channel) |
| `from_gnash/misc-ming.all/action_order/PlaceAndRemove` | mm | `output.fp10.txt` | untestable |  | long run: "Done" lines keep coming past the cap (Linux 20 s: 10 short, Windows 14 short) |
| `avm2/slot_holes_fail` | rm | `output.txt` | golden ≠ Flash (we don't either) | ours 1 line vs FP32 2 | golden is empty by Ruffle convention (test.toml: uncaught errors are not compared); FP32 logs `VerifyError: Error #1107` |
| `avm2/slot_id_exceeds_trait_count` | rm | `output.txt` | golden ≠ Flash (we don't either) | ours 1 line vs FP32 4 | golden is empty by Ruffle convention; FP32 logs `VerifyError #1107` + `ReferenceError #1065` |
| `avm1/goto_rewind_movieclip_replace` | rm | `output.txt` | golden ≠ Flash (we match Flash) | 0 (== Flash) | FP32 never re-runs `Child A frame 1` after the frame-3 rewind (Linux pinned, --no-pin, 20 s, Windows: all == output.ruffle.txt) |
| `avm1/edittext_onscroller` | rm | `output.txt` | untestable |  | input.json (scroll/typing) fixture |
| `avm1/movieclip_library_state_values` | rm | `output.txt` | untestable |  | `_xmouse` = host mouse position |
| `avm2/coerce_property` | rm | `output.txt` | untestable |  | object address in a #1034 message (`Object@…`) |
| `avm2/error_1034_debug_string` | rm | `output.txt` | untestable |  | host timezone in a Date string (golden GMT+0100) |
| `avm2/soundchannel_position` | rm | `output.txt` | untestable |  | audio device + real-time positions (Linux: no device; Windows: timing differs on 31 lines) |
| `avm2/sprite_dropTarget` | rm | `output.txt` | untestable |  | input.json (drag) fixture |
| `from_avmplus/ecma3/Date/e15_9_5_10` | rm | `output.txt` | untestable |  | the `currentTime+2592000000` row depends on today's date (both OSes drop it today) |
| `from_avmplus/ecma3/Date/e15_9_5_10_1` | rm | `output.txt` | untestable |  | current wall-clock time in the output |
| `from_avmplus/ecma3/Date/e15_9_5_11` | rm | `output.txt` | untestable |  | today-dependent `currentTime+30d` row |
| `from_avmplus/ecma3/Date/e15_9_5_12` | rm | `output.txt` | untestable |  | today-dependent `currentTime+30d` row |
| `from_avmplus/ecma3/Date/e15_9_5_12_1` | rm | `output.txt` | untestable |  | current wall-clock time in the output |
| `from_avmplus/ecma3/Date/e15_9_5_13` | rm | `output.txt` | untestable |  | today-dependent `currentTime+30d` row |
| `from_avmplus/ecma3/Date/e15_9_5_15_1` | rm | `output.txt` | untestable |  | today-dependent `currentTime+30d` row |
| `from_avmplus/ecma3/Date/e15_9_5_17_1` | rm | `output.txt` | untestable |  | today-dependent `currentTime+30d` row |
| `from_avmplus/ecma3/Date/e15_9_5_4` | rm | `output.txt` | untestable |  | current wall-clock time in the output |
| `from_gnash/actionscript.all/Camera-v6` | rm | `output.txt` | untestable |  | host camera (Linux: none; Windows: 10 lines differ) |
| `from_gnash/actionscript.all/Camera-v7` | rm | `output.txt` | untestable |  | host camera |
| `from_gnash/actionscript.all/Camera-v8` | rm | `output.txt` | untestable |  | host camera |
| `from_gnash/actionscript.all/NetConnection-v6` | rm | `output.fp30.txt` | untestable |  | network (connect to a remote server) |
| `from_gnash/actionscript.all/NetConnection-v7` | rm | `output.fp30.txt` | untestable |  | network |
| `from_gnash/actionscript.all/NetConnection-v8` | rm | `output.fp30.txt` | untestable |  | network |
| `from_gnash/actionscript.all/Stage-v6` | rm | `output.fp32.txt` | untestable |  | window resize events (host window manager) |
| `from_gnash/actionscript.all/Stage-v7` | rm | `output.fp32.txt` | untestable |  | window resize events |
| `from_gnash/actionscript.all/Stage-v8` | rm | `output.fp32.txt` | untestable |  | window resize events |
| `from_gnash/actionscript.all/TextField-v6` | rm | `output.fp13-17.txt` | untestable |  | device-font metrics (textWidth/textHeight) |
| `from_gnash/actionscript.all/TextField-v7` | rm | `output.fp13-17.txt` | untestable |  | device-font metrics |
| `from_gnash/actionscript.all/TextField-v8` | rm | `output.fp13-17.txt` | untestable |  | device-font metrics |
| `from_gnash/misc-ming.all/ButtonEventsTest` | rm | `output.txt` | untestable |  | input.json fixture (mouse/keys) |
| `from_gnash/misc-ming.all/ButtonPropertiesTest` | rm | `output.txt` | untestable |  | input.json fixture (mouse/keys) |
| `from_gnash/misc-ming.all/DefineTextTest` | rm | `output.txt` | untestable |  | input.json fixture (mouse/keys) |
| `from_gnash/misc-ming.all/DragDropTest` | rm | `output.txt` | untestable |  | input.json fixture (mouse/keys) |
| `from_gnash/misc-ming.all/KeyEventOrder` | rm | `output.txt` | untestable |  | input.json fixture (mouse/keys) |
| `from_gnash/misc-ming.all/NetStream-SquareTest` | rm | `output.txt` | untestable |  | input.json fixture (mouse/keys) |
| `from_gnash/misc-ming.all/PrototypeEventListeners` | rm | `output.fp11.txt` | untestable |  | input.json fixture (mouse/keys) |
| `from_gnash/misc-ming.all/key_event_test` | rm | `output.txt` | untestable |  | input.json fixture (mouse/keys) |
| `from_gnash/misc-ming.all/loading/loadMovieTest` | rm | `output.txt` | untestable |  | input.json fixture (mouse/keys) |
| `from_gnash/misc-ming.all/masks_test` | rm | `output.txt` | untestable |  | input.json fixture (mouse/keys) |
| `from_gnash/misc-mtasc.all/TextFieldTest` | rm | `output.txt` | untestable |  | device-font metrics (height 17.05 vs 18) |
| `from_shumway/flash_net_SharedObject` | rm | `output.txt` | untestable |  | SharedObject size depends on the host path |
| `visual/edittext/edittext_device_transform_negative` | rm | `output.txt` | untestable |  | device-font metrics |
| `from_gnash/actionscript.all/Date-v5` | rm | `output.fp10.txt` | golden = FP10 variant; FP32 differs |  | graded output.fp10.txt; FP32 (Linux == Windows) prints -6.77681005679424e+19 where FP10 printed …748e+19 (3 lines) |
| `from_gnash/actionscript.all/Date-v6` | rm | `output.fp10.txt` | golden = FP10 variant; FP32 differs |  | same 3 lines as Date-v5 |
| `from_gnash/actionscript.all/Date-v7` | rm | `output.fp10.txt` | golden = FP10 variant; FP32 differs |  | same 3 lines as Date-v5 |
| `from_gnash/actionscript.all/Date-v8` | rm | `output.fp10.txt` | golden = FP10 variant; FP32 differs |  | same 3 lines as Date-v5 |

### C. Passing-row sample (185 rows: every passing row whose test.toml mentions `known_failure` or that ships ≥ 2 non-Ruffle `output*.txt` variants)

167 rows: pinned FP32 == the graded golden (so our pass is a Flash pass). Rows with a caveat or a different verdict:

| test | status @e1425f417 | graded file | verdict | ours vs Flash | notes |
|---|---|---|---|---|---|
| `avm1/allow_networking_import_assets` | pass | `output.all.txt` | untestable |  | Ruffle `Navigator::fetch` runner lines (network) |
| `avm1/allow_networking_import_assets2` | pass | `output.all.txt` | untestable |  | Ruffle `Navigator::fetch` runner lines (network) |
| `avm1/root_onload` | pass | `output.txt` | golden = Flash |  | pinned run drops frame-1 `_root.onLoad`; `--no-pin` == golden · **harness re-run (s28 flash-oracle-harness, default flags):** root onLoad auto-detected → unpinned → byte-identical |
| `avm2/allow_networking` | pass | `output.all.txt` | untestable |  | Ruffle `Navigator::*` runner lines (network) |
| `avm2/amf_array_serialization` | pass | `output.txt` | untestable |  | network (Ruffle `Navigator::fetch` lines) |
| `avm2/collator_compare_basic` | pass | `output.txt` | untestable |  | host locale: Linux Collator unsupported (91 lines), Windows differs on `e vs é` |
| `avm2/filereference_save_and_load` | pass | `output.txt` | untestable |  | host file dialog |
| `avm2/goto_queued_invalid/swf9` | pass | `output.txt` | golden = Flash |  | 0.25 fps: 32 s run; with a 45 s cap the golden is a prefix of FP32 · **harness re-run (s28 flash-oracle-harness, default flags):** real-rate cap (≈52 s) → golden is a prefix of FP32 (2 extra post-cut lines); verdict unchanged |
| `avm2/netconnection_serialize_arrays` | pass | `output.txt` | untestable |  | network |
| `from_gnash/actionscript.all/Sound-v6` | pass | `output.txt` | golden = Flash (Windows FP32) |  | Linux FP32 has no audio device (onSoundComplete never fires); Windows == golden |
| `from_gnash/actionscript.all/Sound-v7` | pass | `output.txt` | golden = Flash (Windows FP32) |  | as Sound-v6 |
| `from_gnash/actionscript.all/Sound-v8` | pass | `output.txt` | golden = Flash (Windows FP32) |  | as Sound-v6 |
| `from_gnash/actionscript.all/getvariable-v6` | pass | `output.fp10.txt` | golden = Flash |  | equal except debugger-only `Parameters of primitive types…` lines |
| `from_gnash/actionscript.all/getvariable-v7` | pass | `output.fp10.txt` | golden = Flash |  | equal except debugger-only `Parameters of primitive types…` lines |
| `from_gnash/actionscript.all/getvariable-v8` | pass | `output.fp10.txt` | golden = Flash |  | equal except debugger-only `Parameters of primitive types…` lines |
| `from_gnash/misc-swfmill.all/tags_after_last_showframe` | pass | `output.txt` | untestable |  | harness bug: `flashenv.parse_rect` raises "negative shift count" on this SWF's 0-bit RECT · **harness re-run (s28 flash-oracle-harness, default flags):** `parse_rect` fixed → BYTE-IDENTICAL: **untestable → golden = Flash** |
| `from_gnash/misc-swfmill.all/trace-as2/root_onload` | pass | `output.txt` | golden = Flash |  | pinned run drops frame-1 `_root.onLoad`; `--no-pin` == golden · **harness re-run (s28 flash-oracle-harness, default flags):** root onLoad auto-detected → unpinned → byte-identical |
| `from_shumway/hittesting/mask-hit-test` | pass | `output.txt` | untestable |  | needs a mouse click (`clicked at 60,50`) |

<details><summary>The 167 sample rows where pinned FP32 == the graded golden</summary>

`audio/stream_incomplete_loop`, `avm1/as_setup_error`, `avm1/clone_sprite_types`, `avm1/edittext_html_duplicate_attributes`, `avm1/edittext_set_text_same_after_edits`, `avm1/edittext_tag_indent`, `avm1/html_text_img_numeric_attributes`, `avm1/native_objects_swf7`, `avm1/native_objects_swf8`, `avm1/printjob_props_swf5`, `avm1/printjob_props_swf6`, `avm1/register_class_with_sound`, `avm1/sound_load_stops_when_dereferenced`, `avm1/string_paths_reference_launder`, `avm1/swf4_vars`, `avm1/virtual_property_recursion_double_swf6`, `avm1/watch_virtual_property`, `avm2/all_classes/events/swf10`, `avm2/all_classes/events/swf11`, `avm2/all_classes/events/swf12`, `avm2/all_classes/events/swf30`, `avm2/all_classes/events/swf9`, `avm2/array_sort_arguments`, `avm2/bitmapdata_applyfilter_destpoint_edges`, `avm2/bitmapdata_copypixels_alpha_merge`, `avm2/bitmapdata_draw_filters`, `avm2/content_element_basic`, `avm2/date_set_time_out_of_range`, `avm2/error_throwerror`, `avm2/getouterscope_two_classobjects`, `avm2/getter_different_namespace_setter`, `avm2/goto_framescript_queued/swf13`, `avm2/graphics_draw_triangles`, `avm2/graphics_gradients`, `avm2/graphics_simple_shapes`, `avm2/init_callee_cached`, `avm2/int_toprecision`, `avm2/local_connection_allow_networking`, `avm2/matrix3d_append_rotation`, `avm2/number_convert_edge_cases`, `avm2/simplebutton_childevents_sprite`, `avm2/sprite_with_frames`, `avm2/stage3d_fractal`, `avm2/stage3d_missing_vertex_stream`, `avm2/tab_ordering_stage_tab_children_remove_root`, `avm2/textblock_recreate_text_line_width`, `avm2/uint_toprecision`, `avm2/vector_join_reentrant`, `avm2/vector_sort_arguments`, `avm2/verify_method_info_oob`, `avm2/weird_number_bound_methods`, `avm2/xml_list_ctor_errors`, `fonts/embed_matching/no_font_found`, `from_avmplus/as3/Array/insertremove`, `from_avmplus/e4x/Regress/regress-524214`, `from_avmplus/e4x/Statements/e12_1`, `from_avmplus/e4x/XML/e13_4_4_36`, `from_avmplus/ecma3/Date/e15_9_1_1_1`, `from_avmplus/ecma3/Date/e15_9_1_1_2`, `from_avmplus/ecma3/Date/e15_9_5_5`, `from_avmplus/ecma3/Exceptions/bug127913`, `from_avmplus/ecma3/GlobalObject/e15_1_2_2_2`, `from_avmplus/ecma3/GlobalObject/encodeURI`, `from_avmplus/ecma3/Number/e15_7_4_7_1`, `from_avmplus/ecma3/TypeConversion/e9_3_1_3_rt`, `from_avmplus/ecma3/TypeConversion/e9_4_1`, `from_avmplus/ecma3/TypeConversion/e9_4_2`, `from_avmplus/recursion/pcre_find_fixedlength`, `from_avmplus/regress/bug_420755`, `from_avmplus/regress/bug_654807_swf12`, `from_avmplus/regress/bug_654807_swf13`, `from_gnash/actionscript.all/Function-v6`, `from_gnash/actionscript.all/Function-v7`, `from_gnash/actionscript.all/Function-v8`, `from_gnash/actionscript.all/Global-v5`, `from_gnash/actionscript.all/Global-v7`, `from_gnash/actionscript.all/Global-v8`, `from_gnash/actionscript.all/Instance-v5`, `from_gnash/actionscript.all/Instance-v6`, `from_gnash/actionscript.all/Instance-v7`, `from_gnash/actionscript.all/Instance-v8`, `from_gnash/actionscript.all/Key-v5`, `from_gnash/actionscript.all/LocalConnection-v5`, `from_gnash/actionscript.all/LocalConnection-v6`, `from_gnash/actionscript.all/LocalConnection-v7`, `from_gnash/actionscript.all/LocalConnection-v8`, `from_gnash/actionscript.all/NetConnection-v5`, `from_gnash/actionscript.all/NetStream-v6`, `from_gnash/actionscript.all/NetStream-v7`, `from_gnash/actionscript.all/NetStream-v8`, `from_gnash/actionscript.all/Stage-v5`, `from_gnash/actionscript.all/TextSnapshot-v6`, `from_gnash/actionscript.all/TextSnapshot-v7`, `from_gnash/actionscript.all/TextSnapshot-v8`, `from_gnash/actionscript.all/Video-v5`, `from_gnash/actionscript.all/Video-v6`, `from_gnash/actionscript.all/Video-v7`, `from_gnash/actionscript.all/Video-v8`, `from_gnash/actionscript.all/XMLSocket-v5`, `from_gnash/actionscript.all/XMLSocket-v6`, `from_gnash/actionscript.all/XMLSocket-v7`, `from_gnash/actionscript.all/XMLSocket-v8`, `from_gnash/actionscript.all/delete-v5`, `from_gnash/actionscript.all/delete-v6`, `from_gnash/actionscript.all/delete-v7`, `from_gnash/actionscript.all/delete-v8`, `from_gnash/actionscript.all/flash-v5`, `from_gnash/actionscript.all/flash-v6`, `from_gnash/actionscript.all/flash-v7`, `from_gnash/actionscript.all/flash-v8`, `from_gnash/actionscript.all/getvariable-v5`, `from_gnash/misc-ming.all/BeginBitmapFill`, `from_gnash/misc-ming.all/BitmapDataDraw`, `from_gnash/misc-ming.all/Video-EmbedSquareTest`, `from_gnash/misc-ming.all/attachExtImported`, `from_gnash/misc-ming.all/get_frame_number_test`, `from_gnash/misc-ming.all/goto_frame_test`, `from_gnash/misc-ming.all/init_action/InitActionTest2`, `from_gnash/misc-ming.all/opcode_guard_test`, `from_gnash/misc-ming.all/reverse_execute_PlaceObject2_test2`, `from_gnash/misc-ming.all/shape_test`, `from_gnash/misc-mtasc.all/implementsOpTest`, `from_gnash/misc-swfc.all/movieclip_destruction_test3`, `from_gnash/misc-swfc.all/movieclip_destruction_test4`, `from_gnash/misc-swfc.all/soft_reference_test1`, `from_gnash/misc-swfc.all/swf4opcode`, `from_gnash/misc-swfmill.all/initaction_in_definesprite`, `from_gnash/misc-swfmill.all/registers`, `from_gnash/misc-swfmill.all/trace-as2/arguments`, `from_shumway/MaskTest-2`, `from_shumway/acid/acid-bitmap-draw_quality_low`, `from_shumway/acid/acid-mask`, `from_shumway/acid/acid-stroke-0`, `from_shumway/acid/acid-text-4`, `from_shumway/acid/acid-text-5`, `from_shumway/as3-loader/loaderinfo/loaded-content-properties`, `from_shumway/avm1/moviecliploader`, `from_shumway/avm2/flash/geom/matrix3d/TransformBasics`, `from_shumway/bitmapdata/getpixel-from-embedded`, `from_shumway/captions`, `from_shumway/fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0`, `from_shumway/fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096`, `from_shumway/fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77`, `from_shumway/fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3`, `from_shumway/fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26`, `from_shumway/fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822`, `from_shumway/fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd`, `from_shumway/fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121`, `from_shumway/fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61`, `from_shumway/fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af`, `from_shumway/fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883`, `from_shumway/fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580`, `from_shumway/fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca`, `from_shumway/fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75`, `from_shumway/fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b`, `from_shumway/fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897`, `from_shumway/fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052`, `from_shumway/gradientTransform`, `from_shumway/hardwrap`, `from_shumway/hittesting/hittesting`, `from_shumway/stylesheet`, `visual/blend_modes/shader_as_mask`, `visual/cache_as_bitmap/avm1_color`, `visual/cache_as_bitmap/oversize/swf_10_too_big`, `visual/cache_as_bitmap/oversize/swf_9_too_big`, `visual/edittext/edittext_device_transform_basic`, `visual/simple_shapes/strokes/scale`

</details>
