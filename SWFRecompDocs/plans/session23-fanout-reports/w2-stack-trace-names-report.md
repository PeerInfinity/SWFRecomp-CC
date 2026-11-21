# w2-stack-trace-names (S7) — report

**NEW files:** this report, `w2-stack-trace-names.patch`. No new source files, no new fixtures.
**Patch scope:** `SWFModernRuntime/src/avm2/avm2_error.c` only (+36/−3). Base: origin/master `68c0808a`.
Tests downloaded from upstream Ruffle master **`aa9f62a70`** (master moved past `0ddd12b6a` since the brief; both headline
rows and `call_stack.rs` `MAX_CAPTURED_FRAMES` already exist at `0ddd12b6a`).

## 0. Verdict: GO — 2 priced, measured trace flips, zero other moves

| test | before (clean master) graphics | after graphics | before no-graphics | after no-graphics |
|---|---|---|---|---|
| `avm2/error_stack_trace_class_names` | output_mismatch 127/135 | **pass 135/135** | output_mismatch 127/135 | **pass 135/135** |
| `avm2/error_stack_trace_limit` | output_mismatch 600/674 | **pass 674/674** | output_mismatch 600/674 | **pass 674/674** |

Neither row is `known_failure`, neither has `output.ruffle.txt` → Flash and Ruffle agree; these are **Flash-exact passes**.

### EXPECTED-FLIP LEDGER (coordinator checks CI against this)
- Trace axis, both modes: `avm2/error_stack_trace_class_names` fail→pass; `avm2/error_stack_trace_limit` fail→pass.
- Pixel axis: **none** (neither row has image comparisons; the change touches no render path).
- Everything else: no movement expected.

## 1. Mechanism (owner `avm2_error.c`)

Ruffle `core/src/avm2/function.rs::display_function` + `call_stack.rs` (read at `0ddd12b6a`):

1. **Class half of the frame name** — new `static frame_class_name()` used by `avm2_callstack_frame_name`:
   "only classes in public namespaces are printed with their namespace; internal and private classes are printed
   with just their local name" (`name.namespace().is_namespace()` is true for Namespace 0x08 / PackageNamespace
   0x16 only). We printed `avm2_class_qname_colons_buf` unconditionally → `pkg::Hidden()` (package-internal 0x17)
   and `Test.as$1::Priv()` (file-private 0x05). Now: kind 0x08/0x16 → qualified (unchanged, builtins are registered
   0x16 by `builtin_key`), anything else → local name.
2. **User-namespace method name** — `avm2_vtable_add_traits` (avm2_class.c ~720) already synthesizes
   `"http://example.com/custom::namespacedMethod"` for an ASC method without a method_info name, but
   `avm2_callstack_frame_name`'s mxmlc-prefix strip (`strrchr(dn,'/')`) then cut the URI at its last `/` →
   `Test/custom::namespacedMethod()`. Fix: a debug_name whose pointer differs from the ABC's own
   `methods[idx].debug_name` was synthesized from the trait and is printed verbatim (no strip). Compiler-supplied
   names (mxmlc `test_fla:MainTimeline/test_fla:frame1`) still take the strip path — the 4 `MainTimeline` rows in
   the sweep (`coerce_property`, `error_stack_trace`, `bitmapdata_zero_size`, `try_catch_typed`) are unchanged.
3. **Depth cap 64** — `callstack_snapshot` now emits at most the innermost 64 frames (Ruffle
   `MAX_CAPTURED_FRAMES = 64`, "Flash Player keeps only the innermost frames"). Derived independently from Flash's
   `output.txt`: every section has exactly 64 `at` lines (depth 62 = newError + 62×rec + Test(); depth 63 drops
   `Test()`; Function.call depth 60 = 3 + 60 + 1). The cap counts from the first frame BELOW the skipped
   Error-family constructor frames (the `Error subclass at depth 100` section starts at `Test$/newCustomError()`
   with 64 frames, which is only consistent with skip-then-cap).

## 2. Blast-radius sweep (graphics, clean master vs patch, same box)

Scope by argument: `callstack_snapshot` / `avm2_callstack_frame_name` output only reaches trace via
`getStackTrace()` / uncaught-error frame text, so the sweep is **every row whose `output.txt` has a `^\tat ` line**:
avm2 89, from_avmplus 2, regression 1, stage3d 1 (from_shumway, from_gnash, avm1, and the other misc categories: 0).
Result: **only the 2 headline rows moved**; every other row has identical status and matching/expected line counts.
`stage3d/draw_to_bitmap_data_unconfigured`: output_mismatch 3/8 → 3/8 in both modes.

| row | before | after |
|---|---|---|
| avm2/abstract_classes | pass 132/132 | pass 132/132 |
| avm2/accessibilityimplementation | pass 18/18 | pass 18/18 |
| avm2/array_constructor | output_mismatch 21/234 | output_mismatch 21/234 |
| avm2/array_sort_arguments | output_mismatch 42/442 | output_mismatch 42/442 |
| avm2/avm1movie_addcallback_call | pass 14/14 | pass 14/14 |
| avm2/bitmap_filter_abstract | pass 6/6 | pass 6/6 |
| avm2/bitmapdata_zero_size | pass 8/8 | pass 8/8 |
| avm2/bytearray_bad_symbol_class | pass 3/3 | pass 3/3 |
| avm2/bytearray_bad_symbol_class_other_movie | pass 6/6 | pass 6/6 |
| avm2/bytearray_oom | pass 3/3 | pass 3/3 |
| avm2/casi32 | pass 166/166 | pass 166/166 |
| avm2/coerce_property | ruffle_matched 33/36 | ruffle_matched 33/36 |
| avm2/collator_compare_basic | pass 93/93 | pass 93/93 |
| avm2/collator_locale_ids_windows | pass 120/120 | pass 120/120 |
| avm2/content_element_basic | pass 50/50 | pass 50/50 |
| avm2/context3d_creation | pass 9/9 | pass 9/9 |
| avm2/context3d_draw_to_bitmap_data | output_mismatch 2/15 | output_mismatch 2/15 |
| avm2/displayobjectcontainer_remove_reentrant | output_mismatch 2/257 | output_mismatch 2/257 |
| avm2/edittext_default_format_empty | pass 136/136 | pass 136/136 |
| avm2/element_format_constructor_order | pass 64/64 | pass 64/64 |
| avm2/element_format_properties | pass 235/235 | pass 235/235 |
| avm2/error_stack_trace | pass 45/45 | pass 45/45 |
| avm2/error_stack_trace_class_names | output_mismatch 127/135 | pass 135/135 | **MOVED**
| avm2/error_stack_trace_edge_cases | pass 6/6 | pass 6/6 |
| avm2/error_stack_trace_limit | output_mismatch 600/674 | pass 674/674 | **MOVED**
| avm2/error_throwerror | pass 103/103 | pass 103/103 |
| avm2/event_handler_exception | ruffle_matched 8/11 | ruffle_matched 8/11 |
| avm2/flash_ui_mouse_cursor | pass 35/35 | pass 35/35 |
| avm2/function_display_anonymous | pass 7/7 | pass 7/7 |
| avm2/goto_queued_invalid/swf11 | pass 43/43 | pass 43/43 |
| avm2/gradient_values_readback | ruffle_matched 200/212 | ruffle_matched 200/212 |
| avm2/graphics_draw_path | ruffle_matched 51/101 | ruffle_matched 51/101 |
| avm2/graphics_path | pass 56/56 | pass 56/56 |
| avm2/json_parse_errors | pass 84/84 | pass 84/84 |
| avm2/json_parse_numbers | ruffle_matched 127/131 | ruffle_matched 127/131 |
| avm2/loader_error_in_root_ctor | pass 4/4 | pass 4/4 |
| avm2/loader_load | output_mismatch 126/128 | output_mismatch 126/128 |
| avm2/loader_method | pass 85/85 | pass 85/85 |
| avm2/matrix3d_append | pass 16/16 | pass 16/16 |
| avm2/matrix3d_append_prepend_scale | pass 86/86 | pass 86/86 |
| avm2/matrix3d_append_rotation | pass 23/23 | pass 23/23 |
| avm2/matrix3d_copy_column | pass 83/83 | pass 83/83 |
| avm2/matrix3d_copy_from | pass 19/19 | pass 19/19 |
| avm2/matrix3d_copy_raw_data_from | pass 55/55 | pass 55/55 |
| avm2/matrix3d_copy_raw_data_to | pass 38/38 | pass 38/38 |
| avm2/matrix3d_copy_row | pass 83/83 | pass 83/83 |
| avm2/matrix3d_copy_to_matrix3d | pass 19/19 | pass 19/19 |
| avm2/matrix3d_interpolate | pass 21/21 | pass 21/21 |
| avm2/matrix3d_prepend | pass 16/16 | pass 16/16 |
| avm2/matrix3d_recompose_edge_cases | ruffle_matched 190/198 | ruffle_matched 190/198 |
| avm2/matrix3d_transform_vector | pass 52/52 | pass 52/52 |
| avm2/movieclip_addframescript_error | pass 9/9 | pass 9/9 |
| avm2/number_convert_errors | ruffle_matched 165/871 | ruffle_matched 165/871 |
| avm2/perspective_projection_center | pass 34/34 | pass 34/34 |
| avm2/pixelbender_ceil | pass 77/77 | pass 77/77 |
| avm2/pixelbender_conditional | pass 138/138 | pass 138/138 |
| avm2/pixelbender_eof | pass 7/7 | pass 7/7 |
| avm2/pixelbender_no_out_param | pass 6/6 | pass 6/6 |
| avm2/pixelbender_sign | pass 60/60 | pass 60/60 |
| avm2/primitive_toString | pass 277/277 | pass 277/277 |
| avm2/primitive_valueOf | pass 285/285 | pass 285/285 |
| avm2/proxy_not_overridden | pass 54/54 | pass 54/54 |
| avm2/shared_object_get_local_error | output_mismatch 1/21 | output_mismatch 1/21 |
| avm2/stage3d_agal_upload_errors | pass 66/66 | pass 66/66 |
| avm2/stage3d_missing_vertex_stream | output_mismatch 13/37 | output_mismatch 13/37 |
| avm2/stage_properties2 | pass 213/213 | pass 213/213 |
| avm2/system_exit | pass 3/3 | pass 3/3 |
| avm2/tabstop_properties | pass 105/105 | pass 105/105 |
| avm2/text_element_basic | pass 34/34 | pass 34/34 |
| avm2/textblock_createline_errors | pass 23/23 | pass 23/23 |
| avm2/textblock_line_changes | ruffle_matched 437/481 | ruffle_matched 437/481 |
| avm2/textblock_properties | pass 118/118 | pass 118/118 |
| avm2/textblock_recreateline | ruffle_matched 42/178 | ruffle_matched 42/178 |
| avm2/textblock_releaselines | ruffle_matched 748/752 | ruffle_matched 748/752 |
| avm2/textfield_default_text_format_null | pass 20/20 | pass 20/20 |
| avm2/textfield_get_text_format_args | output_mismatch 50/567 | output_mismatch 50/567 |
| avm2/textfield_set_text_format_args | output_mismatch 81/904 | output_mismatch 81/904 |
| avm2/textformat_display | pass 14/14 | pass 14/14 |
| avm2/textjustifier_locale | pass 132/132 | pass 132/132 |
| avm2/textline_throwerror | pass 30/30 | pass 30/30 |
| avm2/textline_validity | pass 162/162 | pass 162/162 |
| avm2/timer_invalid_delay | pass 30/30 | pass 30/30 |
| avm2/try_catch_typed | pass 12/12 | pass 12/12 |
| avm2/uncaught_error_basic | pass 2/2 | pass 2/2 |
| avm2/uncaught_errors_stringified | ruffle_matched 3/18 | ruffle_matched 3/18 |
| avm2/vector_join_reentrant | output_mismatch 10/96 | output_mismatch 10/96 |
| avm2/vector_sort_arguments | output_mismatch 1/355 | output_mismatch 1/355 |
| avm2/worker_terminate | output_mismatch 1/56 | output_mismatch 1/56 |
| avm2/xml_list_ctor_errors | pass 34/34 | pass 34/34 |
| from_avmplus/as3/Definitions/Variable/ConstVariables_custom1 | pass 17/17 | pass 17/17 |
| from_avmplus/ecma3/Exceptions/exception_011_rt | pass 3/3 | pass 3/3 |
| regression/avm2_sound_bytes_and_group_format | pass 27/27 | pass 27/27 |

## 3. Regression suite and canary

- `regression/` all 37 `avm2_*` fixtures, graphics, after-leg: **37/37 pass** (3 image SKIPs are fixtures without an
  expected PNG, as on master). `regression/avm2_sound_bytes_and_group_format` (the one stack-trace row) pass→pass.
- **Graphics render canary: NOT RUN, by argument.** The patch changes only frame-name string formatting and the
  snapshot depth in `avm2_error.c`; no render, display-list or timeline code is touched, and the canary's 560 rows
  (~1.7 h/leg on 4 CPU) cannot see a stack-trace string unless the row prints one — those rows are all in the §2
  sweep already. Completion mechanism if the coordinator wants it anyway: CI graphics run on the landing commit.

## 4. Refutations / premises checked

- Brief premise "internal/private classes print bare" — confirmed in Ruffle source and Flash output; also applies
  to Protected/Explicit/StaticProtected class namespaces by the same `is_namespace()` rule (no corpus row exercises those).
- Brief premise "user namespaces print the URI" — the URI was already built; the bug was the `/` strip, not a missing URI.
- The 1001 VerifyError message (`avm2_class.c:1103`) builds its own `Class/method` string with the qualified class
  name; deliberately NOT changed (no corpus evidence for its internal-class spelling).

## 5. Not finished

Nothing in scope. Render canary skipped by argument (§3).

## New unclaimed leads

- None found in the sweep that belong to this mechanism. The 12 still-failing stack-trace rows
  (`array_constructor`, `array_sort_arguments`, `vector_*`, `displayobjectcontainer_remove_reentrant`,
  `textfield_{get,set}_text_format_args`, `shared_object_get_local_error`, `context3d_draw_to_bitmap_data`,
  `stage3d_missing_vertex_stream`, `loader_load`, `worker_terminate`) are owned by other s23 slots (S5, S8, S9, S4,
  tf-css-avm2) and their line counts did not move.

## LOCAL ORACLE REQUESTS

none
