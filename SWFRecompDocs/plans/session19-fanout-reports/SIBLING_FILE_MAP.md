# s19 sibling file map — who is editing what (wave 2). Coordinator keeps this current.

| agent | files it edits | notes |
|---|---|---|
| w2-loaders | `SWFModernRuntime/src/actionmodern/avm2_display.c` (loader drop/construction + `button_data_for_char`), `SWFModernRuntime/src/actionmodern/swf_core.c` (MCL phase-3 drain point), new `ruffle-tests/tests/swfs/regression/{avm2_child_simplebutton,avm1_mcl_load_tick}/` | 3 separate patches |
| w2-avm2-json | JSON parse paths + AVM2 stack-frame rendering (`frame_is_class_trait` and callers), integral-number conversion | shared machinery: frame format moves unrelated error tests |
| w2-avm2-smalls | AVM2 class registration (BitmapFilter abstract `native_init`, `new_filter_class`, ShaderFilter), ByteArray symbol-class predicate, matrix3d | `builtin_class_impl` is NOT idempotent — coordinate, never merge blindly |
| w2-bitmapdata | `SWFModernRuntime/src/actionmodern/avm2_bitmap.c`, `actionmodern/action.c` (blend_over / premul LUT / copyPixels direction) | shared formula: filter + draw paths and the pixel axis both see it |
| w2-avm1-events | `actionmodern/action.c` (`mc_call_as2_handler_ng`, EV_MOUSE_WHEEL/onScroller, `actionNextFrame` event arm, `setVariableOnLocalScope`) | shares action.c with w2-bitmapdata; different functions |
| w2-gfx-text | `SWFModernRuntime/src/actionmodern/avm2_text.c` (at-point probes), `SWFRecomp/src/abc_timeline.cpp` (glyph offset table), EditText border extents | only agent in these two files; G2 is a recompiler change |
| w2-gfx-geometry | AVM2 curve bounds (`curveTo` extrema), `Graphics.drawRoundRect*`, LINESTYLE2 caps/joins, optional even-odd fill across lineStyle | MUST NOT touch `avm2_bitmap.c` (w2-bitmapdata owns it) |

Rules: self-localize (new `static` helpers, trailing struct fields, wrapper functions), no
reformatting, no drive-by edits. If you need a function another agent owns, say so in your final
message instead of editing around it.
