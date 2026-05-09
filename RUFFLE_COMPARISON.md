# Ruffle vs SWFRecomp Comparison

*See [RUFFLE_COMPARISON_FILTERED.md](RUFFLE_COMPARISON_FILTERED.md) for results with ignored tests excluded.*

Each test is classified using two signals:

* **SWFRecomp pass** — `status == "pass"` in the suite's `results.json` (other statuses, including `ruffle_matched`, count as fail).
* **Ruffle pass** — no `output.ruffle.txt` sidecar exists in the test directory (Ruffle's tooling writes that file when its actual output diverges from the canonical `output.txt`).

**Commit:** `4eada4640851`  
**Date:** 2026-05-09 03:19 UTC

## Summary

| Suite | SR✓ R✓ | SR✗ R✓ | SR✓ R✗ | SR✗ R✗ | Total |
|-------|------:|------:|------:|------:|------:|
| avm1 | 598 | 27 | 7 | 16 | 648 |
| from_gnash/actionscript.all | 75 | 0 | 51 | 64 | 190 |
| from_gnash/misc-ming.all | 61 | 3 | 4 | 34 | 102 |
| from_gnash/misc-mtasc.all | 6 | 0 | 1 | 2 | 9 |
| from_gnash/misc-swfc.all | 7 | 1 | 1 | 7 | 16 |
| from_gnash/misc-swfmill.all | 12 | 0 | 5 | 1 | 18 |
| from_shumway | 68 | 5 | 5 | 14 | 92 |
| from_shumway/avm1 | 45 | 0 | 1 | 1 | 47 |
| **Total** | **872** | **36** | **75** | **139** | **1122** |

**Bucket totals across all suites:**

| Bucket | Tests | Share |
|--------|------:|------:|
| SWFRecomp passes, Ruffle passes | 872 | 77.7% |
| SWFRecomp fails, Ruffle passes | 36 | 3.2% |
| SWFRecomp passes, Ruffle fails | 75 | 6.7% |
| SWFRecomp fails, Ruffle fails | 139 | 12.4% |
| **Total** | **1122** | 100% |

## Per-Suite Detail

Full lists for the three non-trivial buckets are emitted below (`SR✓ R✓` is omitted to keep these reports tractable).

### avm1

- SR✓ R✓: **598** · SR✗ R✓: **27** · SR✓ R✗: **7** · SR✗ R✗: **16** · total: **648**

#### SWFRecomp fails, Ruffle passes — 27 tests

- `bitmap_data_thorough/pixelDissolve`
- `date`
- `file_reference_browse_cancel`
- `file_reference_download_cancel`
- `file_reference_download_httperror_dns_error`
- `file_reference_download_httperror_status_code`
- `file_reference_download_success`
- `file_reference_upload_httperror_dns_error`
- `file_reference_upload_httperror_status_code`
- `file_reference_upload_success`
- `form_loader_encoding_2`
- `form_loader_encoding_3`
- `geturl`
- `load_vars`
- `loadvariables_method`
- `localconnection`
- `movieclip_hittest_shapeflag`
- `netconnection_send_remote`
- `removed_base_clip_tell_target`
- `sandbox_type_remote`
- `string_relational_compare`
- `stylesheet_load`
- `xml_getbytes`
- `xml_socket`
- `xml_socket_close_in_handler`
- `xml_socket_on_data`
- `xml_socket_segmented`

#### SWFRecomp passes, Ruffle fails — 7 tests

- `clone_sprite_types`
- `native_objects_swf7`
- `native_objects_swf8`
- `printjob_props_swf5`
- `printjob_props_swf6`
- `register_class_with_sound`
- `root_onload`

#### SWFRecomp fails, Ruffle fails — 16 tests

- `bitmap_data_thorough/copyPixels`
- `bitmap_data_thorough/paletteMap`
- `bitmap_data_thorough/perlinNoise`
- `form_loader_encoding_4`
- `global_instance_decls`
- `global_proto_decls`
- `global_proto_decls_delete`
- `globals_swf5`
- `mcl_replace_root_swf7_to_swf5`
- `mcl_replace_root_swf7_to_swf6`
- `movieclip_library_state_values`
- `native_objects_swf6`
- `string_paths_reference_launder`
- `tab_ordering_properties_tab_index_edge_case`
- `textfield_props_swf5`
- `watch_virtual_property`

### from_gnash/actionscript.all

- SR✓ R✓: **75** · SR✗ R✓: **0** · SR✓ R✗: **51** · SR✗ R✗: **64** · total: **190**

#### SWFRecomp fails, Ruffle passes — 0 tests

*(none)*

#### SWFRecomp passes, Ruffle fails — 51 tests

- `AsBroadcaster-v5`
- `ColorTransform-v8`
- `ContextMenu-v7`
- `ContextMenu-v8`
- `Error-v5`
- `Error-v6`
- `Error-v7`
- `Error-v8`
- `Global-v7`
- `Global-v8`
- `Instance-v5`
- `Instance-v6`
- `Instance-v7`
- `Instance-v8`
- `Key-v5`
- `LocalConnection-v5`
- `LocalConnection-v6`
- `LocalConnection-v7`
- `LocalConnection-v8`
- `NetConnection-v5`
- `NetStream-v6`
- `NetStream-v7`
- `NetStream-v8`
- `Number-v6`
- `Number-v7`
- `Number-v8`
- `Point-v8`
- `Stage-v5`
- `TextFormat-v5`
- `TextFormat-v6`
- `TextSnapshot-v6`
- `TextSnapshot-v7`
- `TextSnapshot-v8`
- `Video-v5`
- `Video-v6`
- `Video-v7`
- `Video-v8`
- `XMLSocket-v5`
- `XMLSocket-v6`
- `XMLSocket-v7`
- `XMLSocket-v8`
- `case-v6`
- `case-v7`
- `case-v8`
- `delete-v5`
- `delete-v6`
- `delete-v7`
- `delete-v8`
- `flash-v5`
- `flash-v6`
- `flash-v7`

#### SWFRecomp fails, Ruffle fails — 64 tests

- `ASnative-v5`
- `ASnative-v6`
- `ASnative-v7`
- `ASnative-v8`
- `AsBroadcaster-v6`
- `AsBroadcaster-v7`
- `AsBroadcaster-v8`
- `BitmapData-v8`
- `Camera-v6`
- `Camera-v7`
- `Camera-v8`
- `ExternalInterface-v8`
- `Global-v6`
- `HitTest-v6`
- `HitTest-v7`
- `HitTest-v8`
- `Inheritance-v5`
- `Inheritance-v6`
- `Inheritance-v7`
- `Inheritance-v8`
- `LoadVars-v6`
- `LoadVars-v7`
- `LoadVars-v8`
- `Math-v5`
- `Math-v6`
- `Math-v7`
- `Math-v8`
- `Matrix-v6`
- `Matrix-v7`
- `Matrix-v8`
- `Microphone-v6`
- `Microphone-v7`
- `Microphone-v8`
- `MovieClip-v5`
- `MovieClipLoader-v7`
- `MovieClipLoader-v8`
- `Number-v5`
- `Rectangle-v8`
- `Selection-v6`
- `Selection-v7`
- `Selection-v8`
- `Sound-v5`
- `Sound-v6`
- `Sound-v7`
- `Sound-v8`
- `String-v5`
- `String-v6`
- `String-v7`
- `String-v8`
- `TextField-v5`
- `TextFormat-v7`
- `array-v5`
- `ops-v8`
- `targetPath-v6`
- `targetPath-v7`
- `targetPath-v8`
- `toString_valueOf-v5`
- `toString_valueOf-v6`
- `toString_valueOf-v7`
- `toString_valueOf-v8`
- `with-v5`
- `with-v6`
- `with-v7`
- `with-v8`

### from_gnash/misc-ming.all

- SR✓ R✓: **61** · SR✗ R✓: **3** · SR✓ R✗: **4** · SR✗ R✗: **34** · total: **102**

#### SWFRecomp fails, Ruffle passes — 3 tests

- `DefineEditTextVariableNameTest`
- `action_order/action_execution_order_test11`
- `action_order/action_execution_order_test5`

#### SWFRecomp passes, Ruffle fails — 4 tests

- `attachExtImported`
- `goto_frame_test`
- `reverse_execute_PlaceObject2_test2`
- `runtime_vm_stack_test`

#### SWFRecomp fails, Ruffle fails — 34 tests

- `ButtonEventsTest`
- `ButtonPropertiesTest`
- `DefineTextTest`
- `DragDropTest`
- `DrawingApiTest`
- `EmbeddedFontTest`
- `KeyEventOrder`
- `NetStream-SquareTest`
- `action_order/ActionOrderTest3`
- `action_order/ActionOrderTest4`
- `action_order/ActionOrderTest5`
- `action_order/action_execution_order_test4`
- `action_order/action_execution_order_test6`
- `callFunction_test`
- `displaylist_depths/displaylist_depths_test`
- `displaylist_depths/displaylist_depths_test2`
- `displaylist_depths/displaylist_depths_test3`
- `duplicate_movie_clip_test`
- `init_action/InitActionTest`
- `init_action/InitActionTest2`
- `key_event_test`
- `loading/loadMovieTest`
- `loop/loop_test10`
- `loop/loop_test6`
- `loop/loop_test7`
- `masks_test`
- `matrix_test`
- `opcode_guard_test`
- `path_format_test`
- `place_object_test`
- `place_object_test2`
- `register_class/RegisterClassTest4`
- `register_class/registerClassTest2`
- `replace_buttons1test`

### from_gnash/misc-mtasc.all

- SR✓ R✓: **6** · SR✗ R✓: **0** · SR✓ R✗: **1** · SR✗ R✗: **2** · total: **9**

#### SWFRecomp fails, Ruffle passes — 0 tests

*(none)*

#### SWFRecomp passes, Ruffle fails — 1 test

- `implementsOpTest`

#### SWFRecomp fails, Ruffle fails — 2 tests

- `TextFieldTest`
- `levels`

### from_gnash/misc-swfc.all

- SR✓ R✓: **7** · SR✗ R✓: **1** · SR✓ R✗: **1** · SR✗ R✗: **7** · total: **16**

#### SWFRecomp fails, Ruffle passes — 1 test

- `sound`

#### SWFRecomp passes, Ruffle fails — 1 test

- `stackscope`

#### SWFRecomp fails, Ruffle fails — 7 tests

- `action_execution_order_test10`
- `movieclip_destruction_test1`
- `movieclip_destruction_test4`
- `opcode_guard_test2`
- `registerclass_test3`
- `soft_reference_test1`
- `swf4opcode`

### from_gnash/misc-swfmill.all

- SR✓ R✓: **12** · SR✗ R✓: **0** · SR✓ R✗: **5** · SR✗ R✗: **1** · total: **18**

#### SWFRecomp fails, Ruffle passes — 0 tests

*(none)*

#### SWFRecomp passes, Ruffle fails — 5 tests

- `dict_cross`
- `dict_event`
- `initaction_in_definesprite`
- `tags_after_last_showframe`
- `trace-as2/root_onload`

#### SWFRecomp fails, Ruffle fails — 1 test

- `zeroframe_definesprite`

### from_shumway

- SR✓ R✓: **68** · SR✗ R✓: **5** · SR✓ R✗: **5** · SR✗ R✗: **14** · total: **92**

#### SWFRecomp fails, Ruffle passes — 5 tests

- `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82`
- `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49`
- `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b`
- `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e`
- `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b`

#### SWFRecomp passes, Ruffle fails — 5 tests

- `avm1/moviecliploader`
- `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0`
- `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26`
- `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883`
- `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca`

#### SWFRecomp fails, Ruffle fails — 14 tests

- `avm1/hitarea`
- `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096`
- `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77`
- `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3`
- `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822`
- `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd`
- `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121`
- `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61`
- `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af`
- `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580`
- `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75`
- `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b`
- `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897`
- `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052`

### from_shumway/avm1

- SR✓ R✓: **45** · SR✗ R✓: **0** · SR✓ R✗: **1** · SR✗ R✗: **1** · total: **47**

#### SWFRecomp fails, Ruffle passes — 0 tests

*(none)*

#### SWFRecomp passes, Ruffle fails — 1 test

- `moviecliploader`

#### SWFRecomp fails, Ruffle fails — 1 test

- `hitarea`
