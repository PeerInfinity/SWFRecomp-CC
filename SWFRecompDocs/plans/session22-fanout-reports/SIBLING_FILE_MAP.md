# Session 22 — wave-2 sibling file map (which slot edits what). Self-localize.

| slot | owner files / regions |
|---|---|
| w2-array-global | `action.c`: `actionInitArray` (~51528), `arguments` setup (~8446-8480), `String.split` result, `Array()`-as-function; `builtin_object_hasOwnProperty` (~4562) |
| w2-as-core | `action.c`: NEW static helper layer (as_get/as_set/as_call_method/as_new_global), AsBroadcaster (~36994-37094, ~39309), ContextMenu/Item (~2883-3040, ~41319-41370, ctor arms in `actionNewObject` ~59478-59560), AsSetupError (~5362); M5 flags in `actionCallMethod` object-method arm (~69639) + `objectToPrimitive` (~15524) |
| w2-htmltext | `action.c`: `tf_get_attr` (~26729), `tf_parse_html` (~26815) + htmlText serializer, `setNewTextFormat` (~72799), `tf_get_defaults` callers (~22705, ~57088) |
| w2-default-fonts-draw | `SWFRecomp/src/swf.cpp` (zero-glyph synth ~2593-2648), `abc_devicefont.cpp`; `tag.c` `compute_mc_world_xform` (~7499) / `cab_snap_world` (~3218); `avm2_text.c` device lookup (~2690); `avm2_bitmap.c` `draw()` clipRect (~2614) + `bd_draw_shape_walk` mask (~2355) |
| w2-avm2-stage-view | `avm2_display.c` scaleMode setter (~13715); AVM2 view transform (`avm2_render_init` / `stage_to_ndc`); AVM2 compose walk (z projection) |
| w2-atf-dxt5 | `avm2_stage3d.c` ATF upload |
| w2-avm2-video-stamp | `avm2_display.c` Video/attachNetStream (~17332); `avm2_net.c` ns_play (~2015); `video_codec.c` |
| w2-draw-bigcap-aa | `avm2_display.c` dynamic_bitmap_max (~20238, ~18261); CPU draw rasteriser in `avm2_bitmap.c` (AA) — coordinate with w2-default-fonts-draw (draw() clipRect/mask) |
| w2-crossvm | `avm2_display.c` `mouse_pick` (~14884-14991), `update_mouse_state` (~15459), `avm2_display_run_tick` (~3752), `avm2_loader_drain` (~6565), `loader_deliver` (~6442); `action.c` AVM1-under-AVM2 block (`actionAvm1ChildMousePick` ~25597, ~25661, `actionMouseClickFocus` ~78513); `tag.c` button states (~5333); `tag_stubs.c` (read-only use of `ng_hitTestShapeFromDL`) |
