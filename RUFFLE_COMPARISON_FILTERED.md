# Ruffle vs SWFRecomp Comparison (Filtered)

*Tests on the relevant `ignored_tests.txt` lists are excluded.*  
*See [RUFFLE_COMPARISON.md](RUFFLE_COMPARISON.md) for unfiltered results.*

Each test is classified using two signals:

* **SWFRecomp pass** — `status == "pass"` in the suite's `results.json` (other statuses, including `ruffle_matched`, count as fail).
* **Ruffle pass** — no `output.ruffle.txt` sidecar exists in the test directory (Ruffle's tooling writes that file when its actual output diverges from the canonical `output.txt`).

**Commit:** `4eada4640851`  
**Date:** 2026-05-09 03:19 UTC

## Summary

| Suite | SR✓ R✓ | SR✗ R✓ | SR✓ R✗ | SR✗ R✗ | Total |
|-------|------:|------:|------:|------:|------:|
| avm1 | 597 | 0 | 7 | 4 | 608 |
| from_gnash/actionscript.all | 75 | 0 | 51 | 64 | 190 |
| from_gnash/misc-ming.all | 61 | 3 | 4 | 32 | 100 |
| from_gnash/misc-mtasc.all | 6 | 0 | 1 | 2 | 9 |
| from_gnash/misc-swfc.all | 7 | 0 | 1 | 7 | 15 |
| from_gnash/misc-swfmill.all | 12 | 0 | 5 | 1 | 18 |
| from_shumway | 68 | 0 | 5 | 3 | 76 |
| from_shumway/avm1 | 45 | 0 | 0 | 0 | 45 |
| **Total** | **871** | **3** | **74** | **113** | **1061** |

**Bucket totals across all suites:**

| Bucket | Tests | Share |
|--------|------:|------:|
| SWFRecomp passes, Ruffle passes | 871 | 82.1% |
| SWFRecomp fails, Ruffle passes | 3 | 0.3% |
| SWFRecomp passes, Ruffle fails | 74 | 7.0% |
| SWFRecomp fails, Ruffle fails | 113 | 10.7% |
| **Total** | **1061** | 100% |

*61 tests excluded by `ignored_tests.txt` lists.*

## Per-Suite Detail

Full lists for the three non-trivial buckets are emitted below (`SR✓ R✓` is omitted to keep these reports tractable).

### avm1

- SR✓ R✓: **597** · SR✗ R✓: **0** · SR✓ R✗: **7** · SR✗ R✗: **4** · total: **608**

#### SWFRecomp fails, Ruffle passes — 0 tests

*(none)*

#### SWFRecomp passes, Ruffle fails — 7 tests

- `clone_sprite_types`
- `native_objects_swf7`
- `native_objects_swf8`
- `printjob_props_swf5`
- `printjob_props_swf6`
- `register_class_with_sound`
- `root_onload`

#### SWFRecomp fails, Ruffle fails — 4 tests

- `bitmap_data_thorough/copyPixels`
- `bitmap_data_thorough/paletteMap`
- `bitmap_data_thorough/perlinNoise`
- `textfield_props_swf5`

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

- SR✓ R✓: **61** · SR✗ R✓: **3** · SR✓ R✗: **4** · SR✗ R✗: **32** · total: **100**

#### SWFRecomp fails, Ruffle passes — 3 tests

- `DefineEditTextVariableNameTest`
- `action_order/action_execution_order_test11`
- `action_order/action_execution_order_test5`

#### SWFRecomp passes, Ruffle fails — 4 tests

- `attachExtImported`
- `goto_frame_test`
- `reverse_execute_PlaceObject2_test2`
- `runtime_vm_stack_test`

#### SWFRecomp fails, Ruffle fails — 32 tests

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
- `path_format_test`
- `place_object_test`
- `place_object_test2`
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

- SR✓ R✓: **7** · SR✗ R✓: **0** · SR✓ R✗: **1** · SR✗ R✗: **7** · total: **15**

#### SWFRecomp fails, Ruffle passes — 0 tests

*(none)*

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

- SR✓ R✓: **68** · SR✗ R✓: **0** · SR✓ R✗: **5** · SR✗ R✗: **3** · total: **76**

#### SWFRecomp fails, Ruffle passes — 0 tests

*(none)*

#### SWFRecomp passes, Ruffle fails — 5 tests

- `avm1/moviecliploader`
- `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0`
- `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26`
- `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883`
- `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca`

#### SWFRecomp fails, Ruffle fails — 3 tests

- `avm1/hitarea`
- `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822`
- `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af`

### from_shumway/avm1

- SR✓ R✓: **45** · SR✗ R✓: **0** · SR✓ R✗: **0** · SR✗ R✗: **0** · total: **45**

#### SWFRecomp fails, Ruffle passes — 0 tests

*(none)*

#### SWFRecomp passes, Ruffle fails — 0 tests

*(none)*

#### SWFRecomp fails, Ruffle fails — 0 tests

*(none)*
