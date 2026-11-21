# w2-doc-removal-events — S8: DisplayObjectContainer removal ordering + #2094 guard (wave 2)

**NEW files:** `SWFRecompDocs/plans/session23-fanout-reports/w2-doc-removal-events-report.md`,
`SWFRecompDocs/plans/session23-fanout-reports/w2-doc-removal-events.patch`. No new source files, no new fixtures.

**Base:** origin/master `1e1ffcef` (carries `0798e815a`). Upstream tests: `download_tests.sh avm2` on 2026-11-21
(upstream master head `aa9f62a70`, = `0ddd12b6a` + one VP6 visual test). Box: cloud, Dawn/lavapipe OK (SETUP_STATUS all OK).

## 0. Verdict: **GO** — +3 trace, 0 regressions, 0 pixel moves

| Row | before (gfx / ng) | after (gfx / ng) |
|---|---|---|
| `avm2/displayobjectcontainer_remove_reentrant` | output_mismatch 2/257 (runaway: 27 942 lines) | **pass 257/257** |
| `avm2/displayobjectcontainer_remove_reparent` | output_mismatch 59/189 | **pass 189/189** |
| `avm2/displayobjectcontainer_removechildren_events` | output_mismatch 21/56 | **pass 56/56** |

Identical in both modes. None of the three is `known_failure`, so pass is the Flash-correct target (Ruffle passes them too).

### EXPECTED-FLIP LEDGER (coordinator: check CI against this)
- **Trace, fail→pass (3):** `avm2/displayobjectcontainer_remove_reentrant`, `avm2/displayobjectcontainer_remove_reparent`,
  `avm2/displayobjectcontainer_removechildren_events` — both `graphics` and `no-graphics`.
- **Pixel: none.** (None of the three has `[image_comparisons]`; canary 35/35 md5-identical.)
- Any other move in CI is not this patch.

## 1. Mechanism (port of Ruffle upstream 80df42072, 863fa77bd, 7bc23b837 — the commits that added these tests)

Owner: `SWFModernRuntime/src/avm2/avm2_display.c`.

1. **Remove from the CURRENT parent after the events** (`full_remove_child`, 863fa77bd). `removed` /
   `removedFromStage` are dispatched first; if a listener changed the child's parent during the dispatch, the
   child is removed from its new parent instead, or nothing happens if it now has none. Narrowed versus
   Ruffle: the redirect fires ONLY when `cext->parent` changed during the dispatch, so every caller whose
   listeners don't reparent (timeline removals, and every untouched script removal) runs exactly the old code.
   This also covers the implicit removal inside `addChild`/`addChildAt` (`insert_at_index` → `full_remove_child`),
   which before left a child reparented by a listener in two render lists.
2. **`removeChildren` removes one child at a time** (80df42072). The set is snapshotted up front, held in a GC
   Array (a #2094 longjmp can leave the loop; GC runs only between ticks). Each child goes through the same
   per-child path as `removeChild`, so the next child's listeners see earlier ones gone, and a child a listener
   removed is skipped while one it moved elsewhere is removed from there. This also brings `removeChildren`
   onto `full_remove_child`, so it now clears `stage.focus` and does the timeline field-nulling check (skipped,
   since `placed_by_avm2_script = 1`) like `removeChild`.
3. **#2094 guard** (7bc23b837): new `doc_script_remove_child` (static helper) shared by `removeChild`,
   `removeChildAt`, `removeChildren`. It sets the new trailing field `Avm2DisplayObjectExt.being_removed_by_avm2`
   (`avm2_globals.h`) around the removal and throws `Error #2094: Event dispatch recursion overflow.` (class
   `Error`) if the child is already being removed. `addChild`'s implicit removal neither sets nor checks it,
   which is what Flash shows (`removeChild in removed of reparenting` → no error). The reset can't be skipped:
   `dispatch_event_to_target` catches every listener exception, so nothing longjmps out of the dispatch.
   `#2025` (non-child) is still checked first, as in Ruffle and Flash.

**Premise checks.** The brief said "dispatch depth limit in events.rs". That's wrong: Ruffle and Flash use a
per-object *being-removed* flag, not a recursion depth. The `dispatchEventFunction` frames that the
`removeChild in a nested event` case expects are already emitted by master (`avm2_events.c:741`). The native
`flash.display::DisplayObjectContainer/removeChild()` frames already printed correctly, so no stack-trace work
was needed.

Self-localization: there's one trailing struct field and one new static helper. Only `full_remove_child` and
the three `doc_remove_*` natives changed. The sibling `w2-avm2-small-errors` areas (hitTestPoint, LoaderInfo
progress) are untouched.

## 2. Blast radius: 141-row sweep, before/after on the same box, both modes

Rows: every `avm2/` and `regression/` test whose `.as` uses `removeChild*`, `Event.REMOVED*`/`ADDED*`,
`added`/`removed`/`addedToStage`/`removedFromStage`, plus every `avm2/*{displayevents,remove,reparent,added,child}*`
dir and every `regression/avm2_*` row. That is 104 avm2 + 37 regression rows.

- graphics: before 135 pass + 3 ruffle_matched + 3 mismatch → after 138 pass + 3 ruffle_matched. **Moves: exactly the 3 ledger rows.**
- no-graphics: identical to graphics, row for row, in both legs.
- No other row changed its status OR its matching-line count.
- The `regression` suite (37 rows, all `avm2_*`, including `avm2_child_simplebutton`, `avm2_parent_child_*` and
  `avm2_goto_catchup_scale`) passes before and after in both modes.

Full table (status matching/expected):

| Row | before gfx | after gfx | before ng | after ng |
|---|---|---|---|---|
| `avm2/avm2_catchup_dobj` | pass 158/158 | pass 158/158 | pass 158/158 | pass 158/158 |
| `avm2/displayobject_hittestpoint_root` | pass 13/13 | pass 13/13 | pass 13/13 | pass 13/13 |
| `avm2/displayobject_name_from_timeline` | pass 24/24 | pass 24/24 | pass 24/24 | pass 24/24 |
| `avm2/displayobject_set_name_loaded` | pass 3/3 | pass 3/3 | pass 3/3 | pass 3/3 |
| `avm2/displayobject_transform` | pass 89/89 | pass 89/89 | pass 89/89 | pass 89/89 |
| `avm2/displayobjectcontainer_addchild` | pass 32/32 | pass 32/32 | pass 32/32 | pass 32/32 |
| `avm2/displayobjectcontainer_addchild_lazy_sprite` | pass 1/1 | pass 1/1 | pass 1/1 | pass 1/1 |
| `avm2/displayobjectcontainer_addchild_timelinepull0` | pass 58/58 | pass 58/58 | pass 58/58 | pass 58/58 |
| `avm2/displayobjectcontainer_addchild_timelinepull1` | pass 60/60 | pass 60/60 | pass 60/60 | pass 60/60 |
| `avm2/displayobjectcontainer_addchild_timelinepull2` | pass 62/62 | pass 62/62 | pass 62/62 | pass 62/62 |
| `avm2/displayobjectcontainer_addchildat` | pass 42/42 | pass 42/42 | pass 42/42 | pass 42/42 |
| `avm2/displayobjectcontainer_addchildat_timelinelock0` | pass 34/34 | pass 34/34 | pass 34/34 | pass 34/34 |
| `avm2/displayobjectcontainer_addchildat_timelinelock1` | pass 34/34 | pass 34/34 | pass 34/34 | pass 34/34 |
| `avm2/displayobjectcontainer_addchildat_timelinelock2` | pass 34/34 | pass 34/34 | pass 34/34 | pass 34/34 |
| `avm2/displayobjectcontainer_getchildat` | pass 4/4 | pass 4/4 | pass 4/4 | pass 4/4 |
| `avm2/displayobjectcontainer_getchildbyname` | pass 9/9 | pass 9/9 | pass 9/9 | pass 9/9 |
| `avm2/displayobjectcontainer_getchildbyname_wrongcase` | pass 5/5 | pass 5/5 | pass 5/5 | pass 5/5 |
| `avm2/displayobjectcontainer_getchildindex` | pass 28/28 | pass 28/28 | pass 28/28 | pass 28/28 |
| `avm2/displayobjectcontainer_remove_reentrant` | output_mismatch 2/257 | pass 257/257 | output_mismatch 2/257 | pass 257/257 |
| `avm2/displayobjectcontainer_remove_reparent` | output_mismatch 59/189 | pass 189/189 | output_mismatch 59/189 | pass 189/189 |
| `avm2/displayobjectcontainer_removechild` | pass 10/10 | pass 10/10 | pass 10/10 | pass 10/10 |
| `avm2/displayobjectcontainer_removechild_errors` | pass 4/4 | pass 4/4 | pass 4/4 | pass 4/4 |
| `avm2/displayobjectcontainer_removechild_timelinemanip_remove1` | pass 38/38 | pass 38/38 | pass 38/38 | pass 38/38 |
| `avm2/displayobjectcontainer_removechildat` | pass 18/18 | pass 18/18 | pass 18/18 | pass 18/18 |
| `avm2/displayobjectcontainer_removechildren` | pass 51/51 | pass 51/51 | pass 51/51 | pass 51/51 |
| `avm2/displayobjectcontainer_removechildren_events` | output_mismatch 21/56 | pass 56/56 | output_mismatch 21/56 | pass 56/56 |
| `avm2/displayobjectcontainer_setchildindex` | pass 42/42 | pass 42/42 | pass 42/42 | pass 42/42 |
| `avm2/displayobjectcontainer_swapchildren` | pass 42/42 | pass 42/42 | pass 42/42 | pass 42/42 |
| `avm2/displayobjectcontainer_swapchildrenat` | pass 42/42 | pass 42/42 | pass 42/42 | pass 42/42 |
| `avm2/edittext_autosize_lazy_bounds_events` | pass 65/65 | pass 65/65 | pass 65/65 | pass 65/65 |
| `avm2/flash_xml_removeNode` | pass 60/60 | pass 60/60 | pass 60/60 | pass 60/60 |
| `avm2/focus_remove` | pass 20/20 | pass 20/20 | pass 20/20 | pass 20/20 |
| `avm2/goto_button_nested_framescript` | pass 28/28 | pass 28/28 | pass 28/28 | pass 28/28 |
| `avm2/goto_in_constructframe` | pass 12/12 | pass 12/12 | pass 12/12 | pass 12/12 |
| `avm2/issue_8630_placeremoveplace` | pass 15/15 | pass 15/15 | pass 15/15 | pass 15/15 |
| `avm2/issue_8630_placeremoveplace_scriptremove` | pass 16/16 | pass 16/16 | pass 16/16 | pass 16/16 |
| `avm2/issue_8630_scriptremove` | pass 11/11 | pass 11/11 | pass 11/11 | pass 11/11 |
| `avm2/loader_child_getdefinition` | pass 5/5 | pass 5/5 | pass 5/5 | pass 5/5 |
| `avm2/loader_events` | pass 92/92 | pass 92/92 | pass 92/92 | pass 92/92 |
| `avm2/loader_events_2` | ruffle_matched 5/35 | ruffle_matched 5/35 | ruffle_matched 5/35 | ruffle_matched 5/35 |
| `avm2/loader_loadbytes_events` | pass 30/30 | pass 30/30 | pass 30/30 | pass 30/30 |
| `avm2/loader_loadbytes_url` | pass 12/12 | pass 12/12 | pass 12/12 | pass 12/12 |
| `avm2/loader_loaderurl` | pass 6/6 | pass 6/6 | pass 6/6 | pass 6/6 |
| `avm2/loaderinfo_child_progress` | pass 9/9 | pass 9/9 | pass 9/9 | pass 9/9 |
| `avm2/loaderinfo_events` | pass 7/7 | pass 7/7 | pass 7/7 | pass 7/7 |
| `avm2/mouse_children` | pass 192/192 | pass 192/192 | pass 192/192 | pass 192/192 |
| `avm2/mouse_over_while_dragging` | pass 3/3 | pass 3/3 | pass 3/3 | pass 3/3 |
| `avm2/mouse_pick_text` | pass 8/8 | pass 8/8 | pass 8/8 | pass 8/8 |
| `avm2/movieclip_child_property` | pass 16/16 | pass 16/16 | pass 16/16 | pass 16/16 |
| `avm2/movieclip_displayevents` | pass 96/96 | pass 96/96 | pass 96/96 | pass 96/96 |
| `avm2/movieclip_displayevents_clickgoto` | pass 676/676 | pass 676/676 | pass 676/676 | pass 676/676 |
| `avm2/movieclip_displayevents_clickgoto2` | pass 2001/2001 | pass 2001/2001 | pass 2001/2001 | pass 2001/2001 |
| `avm2/movieclip_displayevents_clickplay` | pass 575/575 | pass 575/575 | pass 575/575 | pass 575/575 |
| `avm2/movieclip_displayevents_clicksymbol` | pass 562/562 | pass 562/562 | pass 562/562 | pass 562/562 |
| `avm2/movieclip_displayevents_constructframegoto` | pass 140/140 | pass 140/140 | pass 140/140 | pass 140/140 |
| `avm2/movieclip_displayevents_constructframeplay` | pass 50/50 | pass 50/50 | pass 50/50 | pass 50/50 |
| `avm2/movieclip_displayevents_constructframesymbol` | pass 144/144 | pass 144/144 | pass 144/144 | pass 144/144 |
| `avm2/movieclip_displayevents_dblhandler` | pass 21/21 | pass 21/21 | pass 21/21 | pass 21/21 |
| `avm2/movieclip_displayevents_enterframegoto` | pass 149/149 | pass 149/149 | pass 149/149 | pass 149/149 |
| `avm2/movieclip_displayevents_enterframeplay` | pass 48/48 | pass 48/48 | pass 48/48 | pass 48/48 |
| `avm2/movieclip_displayevents_enterframesymbol` | pass 149/149 | pass 149/149 | pass 149/149 | pass 149/149 |
| `avm2/movieclip_displayevents_exitframegoto` | pass 106/106 | pass 106/106 | pass 106/106 | pass 106/106 |
| `avm2/movieclip_displayevents_exitframeplay` | pass 44/44 | pass 44/44 | pass 44/44 | pass 44/44 |
| `avm2/movieclip_displayevents_exitframesymbol` | pass 135/135 | pass 135/135 | pass 135/135 | pass 135/135 |
| `avm2/movieclip_displayevents_looping` | pass 63/63 | pass 63/63 | pass 63/63 | pass 63/63 |
| `avm2/movieclip_displayevents_stopped` | pass 113/113 | pass 113/113 | pass 113/113 | pass 113/113 |
| `avm2/movieclip_displayevents_swap` | pass 96/96 | pass 96/96 | pass 96/96 | pass 96/96 |
| `avm2/movieclip_displayevents_timeline` | pass 128/128 | pass 128/128 | pass 128/128 | pass 128/128 |
| `avm2/movieclip_gotoandstop_children` | pass 4/4 | pass 4/4 | pass 4/4 | pass 4/4 |
| `avm2/orphan_movie_complex` | pass 80/80 | pass 80/80 | pass 80/80 | pass 80/80 |
| `avm2/orphan_movie_reorder` | pass 111/111 | pass 111/111 | pass 111/111 | pass 111/111 |
| `avm2/orphan_removeobject` | pass 636/636 | pass 636/636 | pass 636/636 | pass 636/636 |
| `avm2/parent_early_access_child` | pass 16/16 | pass 16/16 | pass 16/16 | pass 16/16 |
| `avm2/remove_child_clear_field` | pass 88/88 | pass 88/88 | pass 88/88 | pass 88/88 |
| `avm2/remove_dobj` | pass 3/3 | pass 3/3 | pass 3/3 | pass 3/3 |
| `avm2/rootless` | pass 42/42 | pass 42/42 | pass 42/42 | pass 42/42 |
| `avm2/shared_object_no_root` | pass 3/3 | pass 3/3 | pass 3/3 | pass 3/3 |
| `avm2/simplebutton_added_to_stage` | pass 45/45 | pass 45/45 | pass 45/45 | pass 45/45 |
| `avm2/simplebutton_childevents` | pass 86/86 | pass 86/86 | pass 86/86 | pass 86/86 |
| `avm2/simplebutton_childevents_multichild` | ruffle_matched 51/152 | ruffle_matched 51/152 | ruffle_matched 51/152 | ruffle_matched 51/152 |
| `avm2/simplebutton_childevents_nested` | pass 54/54 | pass 54/54 | pass 54/54 | pass 54/54 |
| `avm2/simplebutton_childevents_script_order` | ruffle_matched 83/87 | ruffle_matched 83/87 | ruffle_matched 83/87 | ruffle_matched 83/87 |
| `avm2/simplebutton_childevents_sprite` | pass 13/13 | pass 13/13 | pass 13/13 | pass 13/13 |
| `avm2/simplebutton_childprops` | pass 144/144 | pass 144/144 | pass 144/144 | pass 144/144 |
| `avm2/simplebutton_childshuffle` | pass 23/23 | pass 23/23 | pass 23/23 | pass 23/23 |
| `avm2/simplebutton_constr_childevents` | pass 48/48 | pass 48/48 | pass 48/48 | pass 48/48 |
| `avm2/simplebutton_multi_children` | pass 19/19 | pass 19/19 | pass 19/19 | pass 19/19 |
| `avm2/sound_rootless` | pass 7/7 | pass 7/7 | pass 7/7 | pass 7/7 |
| `avm2/stage3d_float1_index` | pass 0/0 | pass 0/0 | pass 0/0 | pass 0/0 |
| `avm2/stage3d_fractal` | pass 0/0 | pass 0/0 | pass 0/0 | pass 0/0 |
| `avm2/stage3d_raytrace` | pass 0/0 | pass 0/0 | pass 0/0 | pass 0/0 |
| `avm2/stage_mousechildren` | pass 2/2 | pass 2/2 | pass 2/2 | pass 2/2 |
| `avm2/tab_ordering_arrows` | pass 998/998 | pass 998/998 | pass 998/998 | pass 998/998 |
| `avm2/tab_ordering_automatic_advanced` | pass 184/184 | pass 184/184 | pass 184/184 | pass 184/184 |
| `avm2/tab_ordering_children` | pass 116/116 | pass 116/116 | pass 116/116 | pass 116/116 |
| `avm2/tab_ordering_stage_tab_children` | pass 32/32 | pass 32/32 | pass 32/32 | pass 32/32 |
| `avm2/tab_ordering_stage_tab_children_remove_root` | pass 5/5 | pass 5/5 | pass 5/5 | pass 5/5 |
| `avm2/vector_removeat` | pass 172/172 | pass 172/172 | pass 172/172 | pass 172/172 |
| `avm2/xml_appendchild` | pass 10/10 | pass 10/10 | pass 10/10 | pass 10/10 |
| `avm2/xml_appendchild_swf_v21` | pass 13/13 | pass 13/13 | pass 13/13 | pass 13/13 |
| `avm2/xml_child` | pass 25/25 | pass 25/25 | pass 25/25 | pass 25/25 |
| `avm2/xml_childindex` | pass 7/7 | pass 7/7 | pass 7/7 | pass 7/7 |
| `avm2/xml_children` | pass 43/43 | pass 43/43 | pass 43/43 | pass 43/43 |
| `avm2/xml_set_children` | pass 17/17 | pass 17/17 | pass 17/17 | pass 17/17 |
| `regression/avm2_activation_vtable_bounded` | pass 5/5 | pass 5/5 | pass 5/5 | pass 5/5 |
| `regression/avm2_agi_shell` | pass 6/6 | pass 6/6 | pass 6/6 | pass 6/6 |
| `regression/avm2_array_growth_bounded` | pass 5/5 | pass 5/5 | pass 5/5 | pass 5/5 |
| `regression/avm2_bitmapdata_draw_textfield` | pass 5/5 | pass 5/5 | pass 5/5 | pass 5/5 |
| `regression/avm2_child_simplebutton` | pass 10/10 | pass 10/10 | pass 10/10 | pass 10/10 |
| `regression/avm2_contextmenu_stub` | pass 4/4 | pass 4/4 | pass 4/4 | pass 4/4 |
| `regression/avm2_e4x_parse_bounded` | pass 18/18 | pass 18/18 | pass 18/18 | pass 18/18 |
| `regression/avm2_embed_bytearray` | pass 2/2 | pass 2/2 | pass 2/2 | pass 2/2 |
| `regression/avm2_external_interface_unavailable` | pass 8/8 | pass 8/8 | pass 8/8 | pass 8/8 |
| `regression/avm2_findprop_this_resolution` | pass 13/13 | pass 13/13 | pass 13/13 | pass 13/13 |
| `regression/avm2_gc_dynprop_tombstone_purge` | pass 8/8 | pass 8/8 | pass 8/8 | pass 8/8 |
| `regression/avm2_gc_string_concat_reclaim` | pass 10/10 | pass 10/10 | pass 10/10 | pass 10/10 |
| `regression/avm2_gc_string_survives_collect` | pass 9/9 | pass 9/9 | pass 9/9 | pass 9/9 |
| `regression/avm2_goto_catchup_scale` | pass 4/4 | pass 4/4 | pass 4/4 | pass 4/4 |
| `regression/avm2_graphics_runtime` | pass 7/7 | pass 7/7 | pass 7/7 | pass 7/7 |
| `regression/avm2_json_roundtrip_bounded` | pass 13/13 | pass 13/13 | pass 13/13 | pass 13/13 |
| `regression/avm2_loader_stub` | pass 5/5 | pass 5/5 | pass 5/5 | pass 5/5 |
| `regression/avm2_localconnection_domain` | pass 4/4 | pass 4/4 | pass 4/4 | pass 4/4 |
| `regression/avm2_morph` | pass 8/8 | pass 8/8 | pass 8/8 | pass 8/8 |
| `regression/avm2_parent_child_render` | pass 11/11 | pass 11/11 | pass 11/11 | pass 11/11 |
| `regression/avm2_parent_child_static_text` | pass 12/12 | pass 12/12 | pass 12/12 | pass 12/12 |
| `regression/avm2_parent_child_symbol_stride` | pass 6/6 | pass 6/6 | pass 6/6 | pass 6/6 |
| `regression/avm2_parent_child_symbolclass_domain` | pass 12/12 | pass 12/12 | pass 12/12 | pass 12/12 |
| `regression/avm2_reflect_trait_hooks` | pass 30/30 | pass 30/30 | pass 30/30 | pass 30/30 |
| `regression/avm2_sharedobject_flushstatus` | pass 4/4 | pass 4/4 | pass 4/4 | pass 4/4 |
| `regression/avm2_simplebutton_click` | pass 2/2 | pass 2/2 | pass 2/2 | pass 2/2 |
| `regression/avm2_slot_default_template` | pass 34/34 | pass 34/34 | pass 34/34 | pass 34/34 |
| `regression/avm2_sound_bytes_and_group_format` | pass 27/27 | pass 27/27 | pass 27/27 | pass 27/27 |
| `regression/avm2_static_and_store_slots` | pass 14/14 | pass 14/14 | pass 14/14 | pass 14/14 |
| `regression/avm2_static_text` | pass 6/6 | pass 6/6 | pass 6/6 | pass 6/6 |
| `regression/avm2_strbuf_stale_prefix` | pass 21/21 | pass 21/21 | pass 21/21 | pass 21/21 |
| `regression/avm2_timeline_gradients` | pass 7/7 | pass 7/7 | pass 7/7 | pass 7/7 |
| `regression/avm2_timeline_solid` | pass 6/6 | pass 6/6 | pass 6/6 | pass 6/6 |
| `regression/avm2_timeline_stroke_gradient` | pass 9/9 | pass 9/9 | pass 9/9 | pass 9/9 |
| `regression/avm2_timeline_text` | pass 4/4 | pass 4/4 | pass 4/4 | pass 4/4 |
| `regression/avm2_tolerant_verify_quarantine` | pass 2/2 | pass 2/2 | pass 2/2 | pass 2/2 |
| `regression/avm2_typed_value_ops` | pass 30/30 | pass 30/30 | pass 30/30 | pass 30/30 |

## 3. Render canary

`render_canary.py capture/compare` over the 29 `avm2/` + `regression/` members of `render_canary_tests.txt`,
plus the 11 sweep rows that carry `[image_comparisons]` (5 overlap), giving 35 tests and 35 comparisons:
**IDENTICAL 35, DIFFERS 0**, with no trace or image status changes. No canary member was appended: the standing
set can't observe listener-reordering, and the three headline rows have no image comparisons. The 141-row trace
sweep is the covering check for this change class.

## 4. Not finished / HOLD
Nothing. No `SWFRecomp/` change, so no `--recompile` was needed. No regression fixture was added: the three
corpus rows already carry Flash-truth `output.txt` covering every new behaviour (one-at-a-time removal,
current-parent removal, #2094 on removeChild/removeChildAt/removeChildren, no guard on addChild).

## New unclaimed leads
- None found in this family. All 141 sweep rows are effective after the patch. The 3 ruffle_matched rows
  (`loader_events_2`, `simplebutton_childevents_multichild`, `simplebutton_childevents_script_order`) didn't move
  in either direction. They are separate mechanisms (Loader drain, SimpleButton state children) and weren't triaged.

## LOCAL ORACLE REQUESTS
none
