# Ruffle Test Results Diff

**Previous:** `2ceede96204b` (2026-07-11T08:30:42.339234+00:00)
**Current:** `7e3a3a01481a` (2026-07-11T13:16:27.773564+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 296 | 353 | +57 |
| Total | 1198 | 1199 | +1 |
| Pass rate | 24.7% | 29.4% | +4.7% |
| Mismatched lines | 110261 | 105103 | -5158 |
|   Decreased | | | -5234 |

## Newly Passing (58)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `application_domain` | output_mismatch | 0/4 | 4/4 |
| `array_vector_null_callback` | output_mismatch | 0/10 | 10/10 |
| `constructprop_dynamic_primitive` | output_mismatch | 5/7 | 7/7 |
| `error_prototype` | output_mismatch | 0/15 | 15/15 |
| `event_bubbles` | output_mismatch | 0/2 | 2/2 |
| `event_cancelable` | output_mismatch | 0/2 | 2/2 |
| `event_type` | output_mismatch | 0/1 | 1/1 |
| `eventdispatcher_dispatchevent_this` | output_mismatch | 2/5 | 5/5 |
| `eventdispatcher_haseventlistener` | output_mismatch | 3/25 | 25/25 |
| `findprop_global_prototype` | runtime_error | 0/6 | 6/6 |
| `function_unbound_this` | output_mismatch | 19/51 | 51/51 |
| `json_errors` | output_mismatch | 0/9 | 9/9 |
| `json_parse` | output_mismatch | 0/21 | 21/21 |
| `primitive_edge_cases` | output_mismatch | 0/1 | 1/1 |
| `prototype_set_null` | output_mismatch | 6/7 | 7/7 |
| `regexp_constr` | output_mismatch | 1/148 | 148/148 |
| `regexp_exec` | output_mismatch | 1/19 | 19/19 |
| `regexp_extended` | output_mismatch | 1/47 | 47/47 |
| `regexp_multiargs` | output_mismatch | 0/1 | 1/1 |
| `regexp_test` | output_mismatch | 1/27 | 27/27 |
| `regexp_toString` | output_mismatch | 0/10 | 10/10 |
| `resolve_order` | output_mismatch | 1/4 | 4/4 |
| `rng` | output_mismatch | 0/1 | 1/1 |
| `string_match` | output_mismatch | 2/51 | 51/51 |
| `string_replace` | output_mismatch | 1/51 | 51/51 |
| `string_search` | output_mismatch | 2/41 | 41/41 |
| `string_split` | output_mismatch | 10/29 | 29/29 |
| `symbol_class_root_not_zero` | output_mismatch | 0/1 | 1/1 |
| `try_catch` | output_mismatch | 5/11 | 11/11 |
| `vector_class` | output_mismatch | 0/36 | 36/36 |
| `vector_class_call` | output_mismatch | 0/11 | 11/11 |
| `vector_coercion` | output_mismatch | 1/66 | 66/66 |
| `vector_concat` | output_mismatch | 1/90 | 90/90 |
| `vector_constr` | output_mismatch | 1/107 | 107/107 |
| `vector_enumeration` | output_mismatch | 0/5 | 5/5 |
| `vector_every` | output_mismatch | 1/92 | 92/92 |
| `vector_filter` | output_mismatch | 1/95 | 95/95 |
| `vector_holes` | output_mismatch | 1/24 | 24/24 |
| `vector_indexof` | output_mismatch | 1/302 | 302/302 |
| `vector_insertat` | output_mismatch | 1/270 | 270/270 |
| `vector_int_access` | output_mismatch | 1/4 | 4/4 |
| `vector_int_delete` | output_mismatch | 1/11 | 11/11 |
| `vector_join` | output_mismatch | 1/58 | 58/58 |
| `vector_lastindexof` | output_mismatch | 1/302 | 302/302 |
| `vector_legacy` | output_mismatch | 1/10 | 10/10 |
| `vector_map` | output_mismatch | 1/85 | 85/85 |
| `vector_object_final` | output_mismatch | 0/1 | 1/1 |
| `vector_object_toString` | output_mismatch | 1/10 | 10/10 |
| `vector_pushpop` | output_mismatch | 1/255 | 255/255 |
| `vector_reborrow_bug` | output_mismatch | 0/10 | 10/10 |
| `vector_removeat` | output_mismatch | 1/172 | 172/172 |
| `vector_reverse` | output_mismatch | 1/232 | 232/232 |
| `vector_shiftunshift` | output_mismatch | 1/252 | 252/252 |
| `vector_slice` | output_mismatch | 1/331 | 331/331 |
| `vector_sort` | output_mismatch | 1/905 | 905/905 |
| `vector_splice` | output_mismatch | 1/693 | 693/693 |
| `vector_splice_fixed_bug_compat` | output_mismatch | 0/4 | 4/4 |
| `vector_tostring` | output_mismatch | 1/79 | 79/79 |

## Newly Failing (1)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `negative_volume_panned` | runtime_error | 0/0 | 0/0 |

## Status Changed (3)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `bitmapdata_constructor_from_timeline` | output_mismatch | runtime_error | 0/1 | 0/1 |
| `domain_memory` | output_mismatch | runtime_error | 1/133 | 1/133 |
| `verify_typecheck` | output_mismatch | runtime_error | 0/4 | 0/4 |

## Added Tests (1)

| Test | Status | Lines |
|------|--------|-------|
| `textline_splitting_basic` | runtime_error | 0/76 |

## Line Count Changed (59)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `error_tostring_more` | output_mismatch | 0/86 | 72/86 | -72 |
| `error_tostring` | output_mismatch | 0/29 | 27/29 | -27 |
| `event_valueof_tostring` | output_mismatch | 1/18 | 14/18 | -13 |
| `eventdispatcher_dispatchevent_handlerorder` | output_mismatch | 2/22 | 15/22 | -13 |
| `json_stringify` | output_mismatch | 0/14 | 13/14 | -13 |
| `appdomain_lookup_edge_cases` | output_mismatch | 0/32 | 7/32 | -7 |
| `eventdispatcher_dispatchevent` | output_mismatch | 2/12 | 9/12 | -7 |
| `eventdispatcher_dispatchevent_cancel` | output_mismatch | 2/20 | 9/20 | -7 |
| `event_clone` | output_mismatch | 0/20 | 6/20 | -6 |
| `class_call` | output_mismatch | 1/32 | 5/32 | -4 |
| `fast_index_access` | output_mismatch | 4/12 | 8/12 | -4 |
| `event_formattostring` | output_mismatch | 0/31 | 3/31 | -3 |
| `subclass_superclass_linked_symbol` | output_mismatch | 0/4 | 3/4 | -3 |
| `event_clone_on_redispatch` | output_mismatch | 0/10 | 2/10 | -2 |
| `amf_function` | output_mismatch | 0/46 | 1/46 | -1 |
| `applicationdomain_hasdefinition_null` | output_mismatch | 0/2 | 1/2 | -1 |
| `construct_frame_list` | output_mismatch | 1/22 | 2/22 | -1 |
| `event_clone_error_redispatch` | output_mismatch | 0/3 | 1/3 | -1 |
| `event_isdefaultprevented` | output_mismatch | 1/12 | 2/12 | -1 |
| `event_target_set` | output_mismatch | 0/9 | 1/9 | -1 |
| `eventdispatcher_dispatchevent_indirect` | output_mismatch | 0/9 | 1/9 | -1 |
| `freestanding_superclass` | ruffle_matched | 0/4 | 1/4 | -1 |
| `function_proto_created` | output_mismatch | 18/61 | 19/61 | -1 |
| `goto_in_constructframe` | output_mismatch | 0/12 | 1/12 | -1 |
| `goto_nested_construct_sibling` | output_mismatch | 0/18 | 1/18 | -1 |
| `loader_loadbytes_url` | output_mismatch | 0/12 | 1/12 | -1 |
| `mouseevent_stagexy` | output_mismatch | 0/35 | 1/35 | -1 |
| `orphan_movie_reorder` | output_mismatch | 1/111 | 2/111 | -1 |
| `place_object_same_depth_frame` | output_mismatch | 0/1 | 1/1 | -1 |
| `simplebutton_childevents` | output_mismatch | 0/86 | 1/86 | -1 |
| `stage_framerate_nan` | output_mismatch | 0/7 | 1/7 | -1 |
| `button_nested_frame` | output_mismatch | 2/48 | 2/48 | 0 |
| `button_nested_frame_simple` | output_mismatch | 2/27 | 2/27 | 0 |
| `error_1034_debug_string` | output_mismatch | 0/30 | 0/30 | 0 |
| `event_target_getter` | output_mismatch | 1/5 | 1/5 | 0 |
| `goto_button_nested_framescript` | output_mismatch | 0/28 | 0/28 | 0 |
| `movieclip_displayevents_clickgoto` | output_mismatch | 0/676 | 0/676 | 0 |
| `movieclip_displayevents_clickgoto2` | output_mismatch | 0/2001 | 0/2001 | 0 |
| `movieclip_displayevents_clickplay` | output_mismatch | 0/575 | 0/575 | 0 |
| `movieclip_displayevents_clicksymbol` | output_mismatch | 0/562 | 0/562 | 0 |
| `movieclip_displayevents_constructframegoto` | output_mismatch | 0/140 | 0/140 | 0 |
| `movieclip_displayevents_constructframeplay` | output_mismatch | 0/50 | 0/50 | 0 |
| `movieclip_displayevents_constructframesymbol` | output_mismatch | 0/144 | 0/144 | 0 |
| `movieclip_displayevents_enterframegoto` | output_mismatch | 0/149 | 0/149 | 0 |
| `movieclip_displayevents_enterframeplay` | output_mismatch | 0/48 | 0/48 | 0 |
| `movieclip_displayevents_enterframesymbol` | output_mismatch | 0/149 | 0/149 | 0 |
| `movieclip_displayevents_exitframegoto` | output_mismatch | 0/106 | 0/106 | 0 |
| `movieclip_displayevents_exitframeplay` | output_mismatch | 0/44 | 0/44 | 0 |
| `movieclip_displayevents_exitframesymbol` | output_mismatch | 0/135 | 0/135 | 0 |
| `movieclip_queued_noop_goto_swf10` | output_mismatch | 0/9 | 0/9 | 0 |
| `movieclip_queued_noop_goto_swf9` | output_mismatch | 0/7 | 0/7 | 0 |
| `number_autoconv` | output_mismatch | 15/21 | 15/21 | 0 |
| `remove_child_clear_field` | output_mismatch | 0/88 | 0/88 | 0 |
| `simplebutton_added_to_stage` | output_mismatch | 0/45 | 0/45 | 0 |
| `simplebutton_childevents_multichild` | output_mismatch | 0/152 | 0/152 | 0 |
| `simplebutton_childevents_script_order` | output_mismatch | 1/87 | 1/87 | 0 |
| `simplebutton_childevents_sprite` | output_mismatch | 0/13 | 0/13 | 0 |
| `static_length` | output_mismatch | 0/24 | 0/24 | 0 |
| `swf_9_queued_goto_scripts` | output_mismatch | 0/6 | 0/6 | 0 |
