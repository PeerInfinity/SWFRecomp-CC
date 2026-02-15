# Failing Ruffle Tests by Feature Category

Last updated: 2026-02-14 (STALE — see note below)

**NOTE**: This document's pass rates are based on an older CI run (commit c8b084e). As of 2026-02-15, the pass rate is **205/619 (33.1%)** — see `CURRENT_STATUS.md` for current data. Major categories that have been fully or mostly implemented since this document was written:
- **XML/XMLNode**: 24/26 active tests now PASS (was 0)
- **TextField Phase 1-2**: 17 tests now PASS (was ~0)
- **Math object**: 1 test PASS, 3 at 98.5% (was 0)
- **String methods**: 4 tests + string_ops_swf6 now PASS (was ~0)
- **Globals**: globals_swf6/7/8 PASS, is_finite PASS (was ~70%)
- **flash.geom**: point, matrix, rectangle PASS (was ~70%)

**Total tests**: 619
**Passing**: 205 (33.1%) — based on latest CI run (commit b4d13aa)
**Failing**: 414 (406 output_mismatch, 7 segfault, 1 timeout)

Tests are sorted by category size (most tests first). Within each category, tests are listed alphabetically.

---

## Feature: TextField/EditText Properties and Formatting (66 tests)

Tests: edittext_align, edittext_align_trailing_spaces_swf7, edittext_align_trailing_spaces_swf8, edittext_antialiastype, edittext_autosize, edittext_autosize_setter, edittext_bullet, edittext_default_format, edittext_default_format_empty, edittext_default_format_font_style, edittext_drag_select, edittext_focus_selection, edittext_font_size, edittext_hscroll, edittext_html_align_swf7, edittext_html_align_swf8, edittext_html_color, edittext_html_condensewhite_swf7, edittext_html_condensewhite_swf8, edittext_html_entity, edittext_html_roundtrip, edittext_html_swf6, edittext_html_swf7, edittext_html_swf8, edittext_ime_focus_lost, edittext_input, edittext_input_newlines, edittext_leading, edittext_letter_spacing, edittext_margins, edittext_newline_stripping, edittext_newlines, edittext_password, edittext_password_copy, edittext_paste_empty, edittext_place_caret, edittext_programmatic_focus, edittext_restrict, edittext_restrict_paste, edittext_scroll, edittext_stylesheet, edittext_tab_focus, edittext_tab_stops, edittext_tag_indent, edittext_text_height_leading, edittext_underline, edittext_width_height, text_format, text_format_display, text_format_font_max_length, text_format_rounding_swf7, text_format_rounding_swf8, textfield_cache_as_bitmap, textfield_maxchars, textfield_properties, textfield_props_swf5, textfield_props_swf6, textfield_props_swf7, textfield_props_swf8, textfield_variable, textsnapshot_available_text, textsnapshot_findtext, textsnapshot_gettext, textsnapshot_props_swf5, textsnapshot_props_swf6, textsnapshot_text_order

Description: Needs comprehensive TextField/EditText property support including: TextFormat object (align, font, size, color, bold, italic, underline, leading, margins, indent, tabStops, letterSpacing, bullet), HTML text round-trip (htmlText property with tag parsing/generation), text selection and caret positioning, scroll/hscroll/maxscroll properties, autoSize behavior, input text handling (restrict, password, maxChars), TextSnapshot for read-only text access, and programmatic focus control. The basic textfield_text test passes but most properties and behaviors are missing or incomplete. Many tests are 50-60% passing, suggesting partial support exists.

Sub-categories:
- **TextFormat**: text_format, text_format_display, text_format_font_max_length, text_format_rounding_swf7, text_format_rounding_swf8 (5 tests)
- **HTML text**: edittext_html_* (10 tests) -- needs HTML parsing/generation in htmlText property
- **Input/Focus**: edittext_input, edittext_input_newlines, edittext_focus_selection, edittext_programmatic_focus, edittext_tab_focus, edittext_drag_select, edittext_ime_focus_lost, edittext_place_caret, edittext_paste_empty, edittext_restrict, edittext_restrict_paste, edittext_password, edittext_password_copy (13 tests)
- **TextSnapshot**: textsnapshot_* (6 tests) -- TextSnapshot class not implemented
- **Layout/Formatting**: remainder -- autosize, scroll, width/height, font metrics, etc.

Estimated test count: 66

---

## Feature: XML/XMLNode (33 tests)

Tests: xml, xml_append_child, xml_append_child_with_parent, xml_attributes_read, xml_cdata, xml_child_nodes_edge_cases, xml_clone_expandos, xml_first_last_child, xml_getbytes, xml_has_child_nodes, xml_idmap, xml_ignore_comments, xml_ignore_white, xml_insert_before, xml_inspect_createmethods, xml_inspect_doctype, xml_inspect_parsexml, xml_inspect_xmldecl, xml_load, xml_namespaces, xml_parent_and_child, xml_remove_node, xml_reparenting, xml_siblings, xml_socket, xml_socket_close_in_handler, xml_socket_on_data, xml_socket_segmented, xml_to_string, xml_to_string_comment, xml_unescaping, xmlnode_proto, swf5_xml_event_handler_context

Description: Needs full XML DOM implementation. The XML class requires: constructor (new XML / new XML(string)), parseXML(), toString(), createElement(), createTextNode(), appendChild(), insertBefore(), removeNode(), cloneNode(), hasChildNodes(). XMLNode properties: childNodes, firstChild, lastChild, previousSibling, nextSibling, parentNode, nodeType, nodeName, nodeValue, attributes. Also needs: ignoreWhite property, idMap, xmlDecl, docTypeDecl, CDATA handling, XML escaping/unescaping. Four tests need XMLSocket (network, probably not implementable). One test needs XML.load() (network).

Sub-categories:
- **XMLSocket**: xml_socket, xml_socket_close_in_handler, xml_socket_on_data, xml_socket_segmented (4 tests) -- needs network
- **XML.load**: xml_load (1 test) -- needs network
- **Core XML DOM**: remainder (28 tests)

Estimated test count: 33

---

## Feature: LoadMovie/LoadVariables/MovieClipLoader (29 tests)

Tests: loading_avm2, loadmovie, loadmovie_fail, loadmovie_flashvars, loadmovie_method, loadmovie_registerclass, loadmovie_replace_root, loadmovie_var_persistence, loadmovienum, loadmovienum_cross_version_prototype, loadvariables, loadvariables2, loadvariables_method, loadvariablesnum, mcl_as_broadcaster, mcl_events_swf_version, mcl_getprogress, mcl_loadclip, mcl_loadclip_properties, mcl_loadclip_replace_root, mcl_mislabeled_target, mcl_replace_root_swf7_to_swf5, mcl_replace_root_swf7_to_swf6, mcl_target_gif87a, mcl_target_gif89a, mcl_target_jpg, mcl_target_png, mcl_unloadclip, moviecliploader_flashvars

Description: Needs runtime SWF/image loading capability. loadMovie() loads external SWF files into movie clip targets. loadMovieNum() loads into _levels. loadVariables()/loadVariablesNum() loads URL-encoded variable data. MovieClipLoader is the AS2 event-based loader with onLoadStart/onLoadComplete/onLoadInit/onLoadError callbacks and getProgress(). These all fundamentally require network/file loading which may not be feasible in the recompiler's trace-only mode.

Estimated test count: 29

---

## Feature: MovieClip Methods and Properties (24 tests)

Tests: movieclip_blend_mode_property, movieclip_create_text_field, movieclip_default_state, movieclip_depth_methods, movieclip_focusenabled, movieclip_get_instance_at_depth, movieclip_getbounds, movieclip_gettextsnapshot, movieclip_hittest, movieclip_hittest_shapeflag, movieclip_init_object, movieclip_invalid_get_bounds_1, movieclip_invalid_get_bounds_2, movieclip_invalid_get_bounds_3, movieclip_invalid_get_bounds_4, movieclip_invalid_get_bounds_5, movieclip_invalid_get_bounds_6, movieclip_invalid_get_bounds_7, movieclip_invalid_get_bounds_8, movieclip_library_state_values, movieclip_lockroot, movieclip_methods_with_loaded_image, movieclip_setmask, movieclip_state_values

Description: Needs MovieClip method implementations beyond basic timeline control. Key methods needed:
- `getBounds()` / `getRect()` -- returns bounding box (8 invalid_get_bounds tests + movieclip_getbounds)
- `hitTest()` -- point and shape flag hit testing (movieclip_hittest, movieclip_hittest_shapeflag)
- `createTextField()` -- dynamically create text fields (movieclip_create_text_field)
- `getInstanceAtDepth()` -- depth management (movieclip_get_instance_at_depth)
- Depth methods: `getDepth()`, `getNextHighestDepth()`, `swapDepths()` (movieclip_depth_methods)
- `setMask()` -- dynamic masking (movieclip_setmask)
- `_lockroot` -- root resolution (movieclip_lockroot)
- State properties: `_currentframe`, `_totalframes`, `_framesloaded`, `_url`, `_quality`, `blendMode`, etc. (movieclip_state_values, movieclip_library_state_values, movieclip_default_state, movieclip_blend_mode_property)
- `focusEnabled` property (movieclip_focusenabled)
- Init object in attachMovie (movieclip_init_object)

Estimated test count: 24

---

## Feature: Mouse/Focus/Input Events (19 tests)

Tests: focus_keyboard_press, focus_mouse, focus_mouse_focusable, focus_mouse_rollout, focus_remove, focus_root_movie, focus_visibility_change, focusrect_focuslost, focusrect_property_swf5, focusrect_property_swf6, focusrect_property_swf7, focusrect_swf6, mouse_events, mouse_events_visible_enabled, mouse_hover_events_while_dragging, mouse_listeners, mouse_pos, mouse_pos_with_scale_factor, mouse_wheel_enabled

Description: Needs simulated mouse/keyboard event dispatch for trace-only testing. Tests expect synthetic input events (mouse click, move, key press) to trigger onPress, onRelease, onRollOver, onRollOut, onMouseDown, onMouseUp, etc. callbacks. Also needs focus management (Selection.setFocus, moveFocus, focus rectangle drawing), and Mouse.addListener()/Mouse.removeListener() for global mouse events. The focus_* tests need automatic focus navigation and keyboard events. The mouse_pos tests need _xmouse/_ymouse properties.

Estimated test count: 19

---

## Feature: Button Behavior and Events (14 tests)

Tests: button_children, button_goto, button_key_events, button_key_events_special, button_keypress, button_keypress_vs_press, button_keypress_vs_tab, button_keypress_vs_textinput, button_order, button_properties_special_cases, button_v5, button_v6, movieclip_in_removed_button, root_button_mode

Description: Needs button event handling in trace mode. Tests need: button key events (onKeyDown/onKeyUp on buttons), button_goto (gotoAndStop from button actions), button display ordering, button property access (special cases for _name, _target, etc.), SWF5/SWF6 version-specific button behavior, and handling of buttons after their parent clip is removed. Button rendering exists in graphics mode, but trace-mode button event simulation needs synthetic input dispatch.

Estimated test count: 14

---

## Feature: Tab Ordering and Focus Navigation (14 tests)

Tests: tab_ordering_automatic_basic, tab_ordering_automatic_order_grid, tab_ordering_automatic_order_same_position, tab_ordering_children, tab_ordering_custom_basic, tab_ordering_custom_duplicate_index, tab_ordering_custom_i32_vs_u32, tab_ordering_custom_m1, tab_ordering_events, tab_ordering_events_mouse, tab_ordering_movieclip_enabled_default, tab_ordering_properties, tab_ordering_reverse, tab_ordering_tabbable

Description: Needs tab/focus navigation system. Automatic tab ordering sorts by position (top-to-bottom, left-to-right). Custom tab ordering uses tabIndex property. Tests check tabEnabled, tabIndex, tabChildren properties on MovieClips and Buttons. Requires synthetic Tab key press simulation to navigate focus, with proper event dispatch (onSetFocus, onKillFocus). All 14 tests produce 0 matching lines, indicating the tab navigation system is completely unimplemented.

Estimated test count: 14

---

## Feature: String Methods and String Paths (13 tests)

Tests: string_methods, string_methods_negative_args, string_methods_swfv5, string_ops_swf6, string_paths_basic, string_paths_eval, string_paths_eval2, string_paths_hidden, string_paths_other, string_paths_reference_launder, string_paths_unload, string_paths_variable_alias, string_paths_variable_scopes

Description: Two sub-features:
1. **String methods** (4 tests): String.prototype methods like charAt, charCodeAt, indexOf, lastIndexOf, slice, substring, substr, split, toLowerCase, toUpperCase, concat, fromCharCode. The string_methods test is 60% passing, suggesting many methods exist but some have edge case bugs (especially with negative arguments per string_methods_negative_args at 0%).
2. **String paths** (9 tests): Flash's path-based variable resolution using slash syntax (e.g., `_root/clip:variable`), eval() for dynamic path resolution, and variable aliasing through paths. The string_paths_hidden test is 65% passing; others are worse.

Estimated test count: 13

---

## Feature: Global Built-in Functions and Objects (12 tests)

Tests: global_instance_decls, global_proto_decls, global_proto_decls_delete, global_swf5_6_7_8_9, global_swf6_7_8, globals_swf5, globals_swf6, globals_swf7, globals_swf8, swf5_global_funcs, swf6_global_funcs, swf7_global_funcs

Description: Tests that enumerate all global variables and check which built-in classes/functions exist per SWF version. globals_swf5/6/7/8 are large tests (~304 lines each, ~66% passing) that check `typeof` for every global. The global_swf5_6_7_8_9 test (0/1145 lines) checks which globals exist across SWF versions. Many failures are because built-in classes (XML, Date, Color, Sound, etc.) are not registered as globals. Fixing these tests requires implementing all the other missing features AND registering their constructors on `_global`.

Estimated test count: 12

---

## Feature: Sound (8 tests)

Tests: sound, sound_duration_position_props, sound_id3, sound_id3_prop, sound_load_start, sound_multiple_load, sound_props_swf5, sound_props_swf6

Description: Needs Sound object implementation for trace mode. Constructor: `new Sound(target)`. Methods: start(), stop(), attachSound(), loadSound(), getVolume(), setVolume(), getPan(), setPan(), getTransform(), setTransform(), getBytesLoaded(), getBytesTotal(). Properties: duration, position, id3. sound_props tests check property enumeration and types (~53% passing, suggesting some Sound object exists). sound_id3/sound_id3_prop need ID3 tag parsing. sound_load_start/sound_multiple_load need loadSound() with events.

Estimated test count: 8

---

## Feature: BitmapData (8 tests)

Tests: bitmap_data, bitmap_data_compare, bitmap_data_copypixels, bitmap_data_hittest, bitmap_data_noise, bitmap_data_pixeldissolve, bitmap_data_threshold, bitmapdata_channels

Description: Needs flash.display.BitmapData class implementation. Some basic BitmapData tests pass (colortransform, fillrect, perlinnoise, pixeldissolve_image), but more methods are needed: compare(), copyPixels(), hitTest(), threshold(), noise(). The bitmap_data test is the main constructor/property test. Several tests are partially passing (bitmap_data_noise 53%, bitmap_data_threshold 59%, bitmap_data_compare 52%).

Estimated test count: 8

---

## Feature: FileReference (8 tests)

Tests: file_reference_browse_cancel, file_reference_download_cancel, file_reference_download_httperror_dns_error, file_reference_download_httperror_status_code, file_reference_download_success, file_reference_upload_httperror_dns_error, file_reference_upload_httperror_status_code, file_reference_upload_success

Description: Needs flash.net.FileReference class. Browse, download, and upload operations with event callbacks (onSelect, onCancel, onOpen, onProgress, onComplete, onHTTPError, onIOError). Requires file system and network access -- likely not implementable in trace-only mode.

Estimated test count: 8

---

## Feature: OOP / Super / Extends / Interfaces (7 tests)

Tests: as2_oop, as2_super_and_this_v6, as2_super_and_this_v8, as2_super_via_manual_prototype, extends_chain, extends_native_type, super_edge_cases

Description: Needs proper `super` keyword support in AS2 classes. The `super` reference should call parent class methods and constructors. Tests check: super in constructors, super in methods, super with manual prototype chains, extending native types (Array, String, etc.), and edge cases where super interacts with `this` binding. Currently "TODO: Create super reference (requires prototype chain support)" in the recompiler output. as2_super_and_this_v6 and v8 are large tests (97/85 lines, 0% passing).

Also needs: `interface` and `implements` support (interface_implements_op, 47 lines, 0% passing).

Estimated test count: 7 + 1 (interface_implements_op) = 8

---

## Feature: RegisterClass and Export/Registration (7 tests)

Tests: register_and_init_order, register_class, register_class_return_value, register_class_swf6, register_class_with_sound, register_globals_across_frames, register_underflow

Description: Needs Object.registerClass() implementation for linking AS2 classes to library symbols. When a movie clip with a registered class is instantiated, the class constructor should be called and `this` should be the clip instance. Tests check registration order, return values, SWF6 behavior, and interaction with Sound class. register_underflow (69% passing) tests register allocation edge cases.

Estimated test count: 7

---

## Feature: Stage Object Properties (7 tests)

Tests: stage_display_state, stage_object_children, stage_object_enumerate, stage_object_properties, stage_object_properties_swf6, stage_property_representation, stage_scale_mode

Description: Needs Stage object as a special global with properties: width, height, scaleMode, displayState, align, showMenu, quality. stage_object_properties (68% passing) and stage_object_properties_swf6 (68%) suggest partial Stage support exists. stage_object_children (82% passing) needs `_root.clip` child access to work properly. stage_object_enumerate (0/4) needs for-in on Stage. stage_scale_mode needs Stage.scaleMode getter/setter.

Estimated test count: 7

---

## Feature: SWF Version-Specific Behavior (7 tests)

Tests: swf4_actions_coercion_order (SEGFAULT), swf5_no_closure, swf5_to_6_cross_call, swf6_case_insensitive, swf6_string_as_bool, swf6_to_5_cross_call, swf7_case_sensitive

Description: Tests that verify version-dependent behavior differences:
- **Case sensitivity**: SWF6 is case-insensitive for variable/property access; SWF7+ is case-sensitive. swf6_case_insensitive (69% passing) and swf7_case_sensitive (91% passing) test this.
- **Cross-version calls**: SWF5-to-6 and SWF6-to-5 function calls between loaded movies with different SWF versions (0% passing, needs loadMovie).
- **SWF5 closures**: SWF5 does NOT have closures (variables bind late). swf5_no_closure tests this.
- **String as boolean**: In SWF6, non-empty strings are truthy. swf6_string_as_bool (0/15) tests this.
- **SWF4 coercion**: swf4_actions_coercion_order segfaults.

Estimated test count: 7

---

## Feature: TellTarget / Target Path Resolution (6 tests)

Tests: target_clip_removed, target_clip_swf5, target_clip_swf6, tell_target, tell_target_invalid, tell_target_invalid_swf6

Description: Needs proper tellTarget (ActionSetTarget/ActionSetTarget2) implementation with correct scope resolution. When targeting a clip, variable reads should resolve against target scope, and writes should set properties on the target. Tests check behavior with removed clips, invalid targets, and SWF5 vs SWF6 differences. tell_target (0/37) is the comprehensive test. target_clip_removed (80% passing) is nearly working.

Estimated test count: 6

---

## Feature: Unload / UnloadMovie (6 tests)

Tests: unload, unload_clip_event, unload_nested_child, unloadmovie, unloadmovie_method, unloadmovienum

Description: Needs proper unload behavior. When a movie clip is unloaded: onUnload event fires, clip becomes inaccessible by name but retains its depth slot, nested children are recursively unloaded. unloadMovie() / unloadMovieNum() also need implementation. Tests check event ordering during unload and behavior of references to unloaded clips.

Estimated test count: 6

---

## Feature: Clone/Duplicate MovieClip (5 tests)

Tests: clone_sprite_edittext, clone_sprite_edittext_dynamic, clone_sprite_types, duplicate_movie_clip, duplicate_movie_clip_drawing (SEGFAULT)

Description: Needs duplicateMovieClip() and MovieClip.duplicateMovieClip() implementation. Cloning should copy the clip's display list, including text fields (clone_sprite_edittext, clone_sprite_edittext_dynamic). clone_sprite_types (50% passing) tests duplication of different child types. duplicate_movie_clip (20% passing) tests basic duplication. duplicate_movie_clip_drawing segfaults and likely needs drawing API support.

Estimated test count: 5

---

## Feature: Native Object/Function Introspection (5 tests)

Tests: native_double_construct, native_objects_swf6, native_objects_swf7, native_objects_swf8, native_subclasses

Description: Tests that check behavior of native (built-in) objects and functions. native_objects_swf6/7/8 (0/84 each) enumerate all native constructors and check their properties. native_subclasses (0/191) tests extending built-in classes. native_double_construct tests calling new on already-constructed native objects. These are meta-tests that effectively require all built-in classes to be implemented.

Estimated test count: 5

---

## Feature: Prototype Chain and Object Properties (4 tests)

Tests: is_prototype_of, object_prototypes, prototype_enumerate, prototype_properties

Description: Needs correct __proto__ chain traversal, isPrototypeOf(), for-in enumeration of prototype properties, and property flags (DontEnum, DontDelete, ReadOnly). object_prototypes (84% passing) and prototype_properties (71%) suggest the basics work but edge cases are wrong. is_prototype_of (66%) needs the isPrototypeOf method. prototype_enumerate (a few lines off) needs correct for-in ordering through prototype chain.

Estimated test count: 4

---

## Feature: Math Object (4 tests)

Tests: math_min_max, math_swf6, math_swf7, math_swf8

Description: Needs Math object with all standard methods. math_swf6/7/8 (0/530 each) are comprehensive tests of every Math method. math_min_max tests Math.min/Math.max with edge cases (NaN, Infinity, no args). The 0% pass rate on the comprehensive tests suggests the Math object is either not registered as a global or not properly implemented.

Estimated test count: 4

---

## Feature: NetConnection/NetStream (4 tests)

Tests: netconnection_close, netconnection_send_remote, netstream_play_flv, netstream_seek_flv

Description: Needs NetConnection and NetStream classes for FLV video playback. netconnection_close/send_remote test NetConnection.connect() and send(). netstream_play_flv/seek_flv test FLV playback with seek. Requires network and media capabilities -- likely not implementable in trace-only mode (netstream_play_flv_screen already passes separately).

Estimated test count: 4

---

## Feature: Object.watch (4 tests)

Tests: watch, watch_textfield, watch_virtual_property, watch_virtual_property_proto

Description: Needs Object.prototype.watch() and Object.prototype.unwatch() methods. watch() registers a callback that's invoked when a property is set. The callback receives (property, oldVal, newVal) and its return value becomes the new property value. watch_virtual_property and watch_virtual_property_proto test interaction with addProperty virtual properties.

Estimated test count: 4

---

## Feature: Color Object (3 tests)

Tests: color, color_transform, transform

Description: Needs `new Color(target)` constructor with methods: getRGB(), setRGB(), getTransform(), setTransform(). The Color object controls color transformation on a movie clip target. color_transform tests the transform property. The `transform` test (67% passing) needs flash.geom.Transform with colorTransform and matrix properties.

Estimated test count: 3

---

## Feature: Drag and Drop (3 tests)

Tests: drag_drop, drag_over_from_outside, drag_over_without_startdrag

Description: Needs startDrag()/stopDrag() implementation with simulated mouse movement for trace testing. drag_drop (0/10) tests full drag-and-drop cycle with _droptarget. drag_over tests need mouse event simulation during drag operations.

Estimated test count: 3

---

## Feature: Enumeration (for-in) (3 tests)

Tests: array_enumerate, enumerate, new_object_enumerate

Description: Needs correct for-in enumeration order. ActionScript enumerates own properties in reverse insertion order, then walks the prototype chain. array_enumerate (0/4) tests enumerating array indices. enumerate (varies) tests general object enumeration. new_object_enumerate (57% passing, 4/7) tests enumeration of objects created with InitObject.

Estimated test count: 3

---

## Feature: ExternalInterface (3 tests)

Tests: external_interface, external_interface_jsquotestring, external_interface_toas_basic

Description: Needs ExternalInterface class for JavaScript bridge. ExternalInterface.call() invokes JavaScript functions, ExternalInterface.addCallback() registers AS functions callable from JS. Also needs escapeXML/unescapeXML (in XML category) and jsQuoteString methods. Requires browser context -- likely not implementable in trace-only mode.

Note: 4 additional ExternalInterface tests are in the XML category (external_interface_escapexml, external_interface_toxml_array, external_interface_toxml_basic, external_interface_unescapexml) because they primarily test XML serialization.

Estimated test count: 3 (+ 4 in XML category)

---

## Feature: Geometry Classes: Point, Rectangle, Matrix (3 tests)

Tests: matrix, point, rectangle

Description: Needs flash.geom.Point, flash.geom.Rectangle, and flash.geom.Matrix class implementations. These are pure math/data classes:
- **Point**: x, y, length, add(), clone(), distance(), equals(), interpolate(), normalize(), offset(), polar(), subtract(), toString() -- 124/175 (71%)
- **Matrix**: a,b,c,d,tx,ty, clone(), concat(), createBox(), createGradientBox(), deltaTransformPoint(), identity(), invert(), rotate(), scale(), toString(), transformPoint(), translate() -- 123/171 (72%)
- **Rectangle**: x,y,width,height,left,right,top,bottom,bottomRight,topLeft,size, clone(), contains(), containsPoint(), containsRectangle(), equals(), inflate(), inflatePoint(), intersection(), intersects(), isEmpty(), offset(), offsetPoint(), setEmpty(), toString(), union() -- 516/745 (69%)

These are partially passing because the constructor exists but methods are incomplete.

Estimated test count: 3

---

## Feature: PrintJob (3 tests)

Tests: printjob_props_swf5, printjob_props_swf6, printjob_props_swf7

Description: Needs PrintJob class constructor and properties. printjob_props tests check that PrintJob exists as a global and has expected properties per SWF version. All 0% passing. Likely just needs the constructor registered; actual printing functionality not needed for trace tests.

Estimated test count: 3

---

## Feature: Timer / setInterval (3 tests)

Tests: set_interval, timeout, timer_run_actions

Description: Needs setInterval()/clearInterval() and setTimeout()/clearTimeout() implementation. set_interval (0/27) tests basic interval scheduling. timeout test (TIMEOUT status) likely enters an infinite loop. timer_run_actions (0/18) tests action execution ordering with timers. Requires a timer scheduling system in the runtime.

Estimated test count: 3

---

## Feature: StyleSheet (3 tests)

Tests: stylesheet, stylesheet_load, stylesheet_transform

Description: Needs flash.text.StyleSheet class for CSS-style text formatting. StyleSheet.parseCSS() parses CSS text, StyleSheet.transform() transforms TextFormat objects. stylesheet_transform (50% passing, 375/750) is partially working. stylesheet_load needs network loading of CSS files.

Estimated test count: 3

---

## Feature: Bitmap Filters (2 tests)

Tests: bitmap_filters, displacementmapfilter_mappoint_throw_error

Description: Needs flash.filters package classes: BlurFilter, DropShadowFilter, GlowFilter, BevelFilter, GradientGlowFilter, GradientBevelFilter, ColorMatrixFilter, ConvolutionFilter, DisplacementMapFilter. bitmap_filters (0/548) is a comprehensive test of all filter types. displacementmapfilter_mappoint_throw_error tests error handling.

Estimated test count: 2

---

## Feature: Clip Events (onLoad, onEnterFrame, etc.) (2 tests)

Tests: clip_event_propagation_order, clip_events

Description: Needs proper MovieClip event dispatching: onLoad, onUnload, onEnterFrame, onClipEvent(initialize), onClipEvent(construct), and correct propagation order. clip_events checks that events fire in the right order through clip lifecycle. clip_event_propagation_order (0/17) checks parent-child event ordering.

Estimated test count: 2

---

## Feature: ContextMenu (2 tests)

Tests: context_menu, context_menu_item

Description: Needs ContextMenu and ContextMenuItem classes. Tests check constructor, properties (builtInItems, customItems), and methods (copy, hideBuiltInItems). Likely just needs the class constructors registered.

Estimated test count: 2

---

## Feature: Form Loading / URL Encoding (4 tests)

Tests: form_loader_encoding_1, form_loader_encoding_2, form_loader_encoding_3, form_loader_encoding_4

Description: Tests URL-encoded form data loading with various character encodings (UTF-8, Shift_JIS, etc.). Requires network loading -- not implementable in trace-only mode.

Estimated test count: 4

---

## Feature: Key/Input Events (2 tests)

Tests: input_dead_keys_windows, key_isToggled

Description: Needs Key object with isToggled() for checking Caps Lock/Num Lock state, and dead key input handling for international keyboards. Requires keyboard event simulation.

Estimated test count: 2

---

## Feature: LocalConnection (2 tests)

Tests: localconnection, localconnection_properties

Description: Needs LocalConnection class for inter-SWF communication. Constructor, connect(), send(), close(), domain property. localconnection (0/579) is a comprehensive test. localconnection_properties (50% passing) checks property existence.

Estimated test count: 2

---

## Feature: Parsing Functions (parseInt/parseFloat) (2 tests)

Tests: parse_float (TIMEOUT), parse_int

Description: Needs correct parseInt() and parseFloat() global functions. parse_int (0/64) tests many edge cases including radix parameter, leading whitespace, hex prefixes, and overflow. parse_float times out, suggesting an infinite loop in the implementation.

Estimated test count: 2

---

## Feature: Selection Object (2 tests)

Tests: selection, selection_handlers

Description: Needs Selection object with methods: getBeginIndex(), getEndIndex(), getCaretIndex(), getFocus(), setFocus(), setSelection(). Also needs onSetFocus handler. Tests check text field selection and focus management.

Estimated test count: 2

---

## Feature: With Statement Scope (2 tests)

Tests: with, with_variable_scopes

Description: Needs correct `with` statement scope chain behavior. The `with` block pushes an object onto the scope chain for variable lookup. with (61% passing) tests basic with behavior but has issues with scope leaking. with_variable_scopes (56% passing) tests complex nested with/function scope interactions.

Estimated test count: 2

---

## Feature: Date Class (1 test)

Tests: date

Description: Needs Date class constructor and all methods (getFullYear, getMonth, getDate, getDay, getHours, getMinutes, getSeconds, getMilliseconds, getTime, getTimezoneOffset, and all UTC variants plus setters). The single test is huge (6335 expected lines) and 57% passing (3617/6335), suggesting a Date implementation exists but has bugs in edge cases (likely timezone handling, overflow/underflow, NaN propagation).

Estimated test count: 1

---

## Feature: Try/Catch/Finally (1 test)

Tests: try_catch_finally (TIMEOUT)

Description: Try/catch/finally exists (try_finally_simple passes, catch_references_registers passes, uncaught_exception passes). This test likely hits an edge case that causes an infinite loop -- possibly try inside a loop, or nested try/catch/finally interaction.

Estimated test count: 1

---

## Feature: Miscellaneous Uncategorized (46 tests)

### MovieClip Dynamic Creation / Lifecycle (12 tests)
Tests: attach_movie, attach_movie_stop, clip_constructors, create_empty_movie_clip, empty_movieclip_can_attach_movies, export_assets, on_construct, default_names, do_init_action_child, execution_order4, place_and_lookup, placeobject_occupied_depth

Description: Tests for dynamic clip creation (attachMovie, createEmptyMovieClip), symbol export/import, DoInitAction execution, construction events, display list ordering, and PlaceObject depth conflict handling. attach_movie (73% passing) is close to working.

### Function Behavior and Scope (9 tests)
Tests: closure_scope, function_as_function, function_base_clip, function_base_clip_readded, function_base_clip_removed, function_suppress_and_preload, funky_function_calls, constructor_function, call

Description: Tests for function scope chains, closures (SWF6+), Function() constructor, function.apply()/call(), base clip resolution for functions, DefineFunction2 suppress/preload flags, and the Call action (frame call). closure_scope (0/7) indicates closures may not work. function_suppress_and_preload (0/28) indicates DefineFunction2 register flags have bugs.

### Object System (8 tests)
Tests: add_property, as_set_prop_flags, as_set_prop_flags_version, boxed_primitives, init_object_order, object_properties, object_resolve, coerce_to_primitive_resolve

Description: Tests for addProperty (virtual getters/setters), ASSetPropFlags (property flags), boxed primitives (new Number/String/Boolean), InitObject property order, property flags (DontEnum/DontDelete/ReadOnly), __resolve handler, and valueOf/toString coercion. add_property (20% passing) needs addProperty() implementation. as_set_prop_flags (57%) is partially working.

### Clip Removal and Scope After Removal (5 tests)
Tests: remove_movie_clip, removed_base_clip_tell_target, removed_clip_halts_script, removed_target_clip_scope, rewind_depth

Description: Tests for removeMovieClip behavior, script halting when base clip is removed, scope resolution after clip removal, and depth management during timeline rewind. remove_movie_clip (59% passing) is partially working.

### Path Resolution (5 tests)
Tests: path_string (SEGFAULT), slash_syntax, named_shapes, property_invalid_base_clip, cross_movie_root

Description: Tests for variable path resolution via slash syntax (/clip1/clip2:var), named shape access, property access with invalid base clips, and cross-movie _root resolution. path_string segfaults. slash_syntax (0/14) indicates slash-syntax path resolution is broken.

### Type Coercion and Global Functions (5 tests)
Tests: is_finite, is_finite_swf6, mutable_this, primitive_type_globals, coerce_to_object_monkeypatch

Description: Tests for isFinite() function, mutable `this` binding, primitive type constructors as globals (Number, String, Boolean), and object coercion with monkey-patched constructors. mutable_this (67% passing) mostly works. primitive_type_globals (57%) is partially working.

### Array Methods (3 tests)
Tests: array_call_method, array_prototyping, array_sort_random

Description: array_call_method (0/9) tests calling methods stored in arrays. array_prototyping (67% passing) tests Array prototype modification. array_sort_random (0/443) tests Array.sort() with random comparator (deterministic comparison ordering).

### Stage/Frame Properties (2 tests)
Tests: frame_size_translated_negative, frame_size_translated_positive

Description: Tests for frame bounds translation. Access shape properties (_x, _y, _width, _height) with translated stage coordinates.

### Issue Tests (9 tests)
Tests: issue_1104, issue_1906, issue_2030, issue_2084, issue_2870, issue_3169, issue_3522, issue_9327, issue_9885

Description: Bug-specific regression tests from the Ruffle project:
- **issue_1104** (0/2): clip enterFrame event not firing
- **issue_1906** (50%): Color.setTransform on movie clips (needs Color object)
- **issue_2030** (50%): BitmapData attachBitmap _width/_height
- **issue_2084** (0/16): Complex layout with onLoad ordering
- **issue_2870** (0/3): Child clip loading events
- **issue_3169** (0/2): Setter callback
- **issue_3522** (50%): TextField htmlText to text conversion
- **issue_9327** (0/2): Unicode text in TextField
- **issue_9885** (50%): Variable resolution

### Other Miscellaneous (11 tests)
Tests: as_broadcaster, as_broadcaster_undef, asfunction, asnative, asnew, bad_placeobject_clipaction, click_block, arguments, instanceof_coercions, custom_clip_methods, nan_scale

- **AsBroadcaster**: as_broadcaster, as_broadcaster_undef -- needs AsBroadcaster.initialize() to add addListener/removeListener/broadcastMessage to objects
- **asfunction**: HTML link protocol `asfunction:` for calling AS functions from HTML text
- **ASnative/ASnew**: ASnative(id, index) returns built-in native functions by ID; ASnew(id, index) constructs native objects
- **bad_placeobject_clipaction**: Clip actions on malformed PlaceObject tags
- **click_block**: Click event blocking behavior
- **arguments**: Function arguments object (61% passing, needs callee/caller properties and Array inheritance)
- **instanceof_coercions**: Type coercion during instanceof checks (0/88)
- **custom_clip_methods**: Setting custom methods on movie clips and calling them (0/4)
- **nan_scale**: MovieClip _width/_height with NaN scale (56% passing, needs drawing API: beginFill/moveTo/lineTo)

### LoadVars and Network (2 tests)
Tests: load_vars, mixed_avm_load_into_root

Description: load_vars needs LoadVars class (load, send, sendAndLoad methods). mixed_avm_load_into_root tests loading AVM1 SWF into root. Both require network access.

### Remaining Miscellaneous (8 tests)
Tests: get_bytes_total, geturl, gettextextent, hittest_lockroot, hittest_morph, hittest_morph_input, hittest_winding_rule, text_blocks_clicks

- **get_bytes_total**: getBytesLoaded()/getBytesTotal() methods (0/4)
- **geturl**: getURL() action for navigation (0/7)
- **gettextextent**: TextFormat.getTextExtent() for text measurement (55% passing)
- **hittest_***: Hit testing with lockroot, morph shapes, and winding rules (0%)
- **text_blocks_clicks**: Mouse click events on text blocks (0/4)

### Cross-Movie / Level / Root (5 tests)
Tests: cross_movie_root, lock_root, resolve_different_root, root_global_parent, root_onload

Description: Tests for multi-level movie management (_level0, _level1), _lockroot behavior, _root vs _global vs _parent resolution, and root onLoad event. Most require loadMovie support for multi-level testing.

### Sandbox/Security (2 tests)
Tests: sandbox_type_local_network, sandbox_type_remote

Description: System.security.sandboxType currently returns "localWithFile" (fixing sandbox_type_local_file). sandbox_type_local_network wants "localWithNetwork" and sandbox_type_remote wants "remote" — these are mutually exclusive with the current hardcoded value. Would need per-test sandbox configuration to fix all three.

### Frame Navigation (4 tests)
Tests: goto_frame, goto_frame2, goto_label, goto_methods (SEGFAULT)

Description: Frame navigation methods beyond basic gotoAndStop/gotoAndPlay. goto_frame (25% passing) and goto_frame2 (18%) need better edge case handling (out-of-range frames, NaN, negative values). goto_label (12%) needs label resolution. goto_methods segfaults.

### Scope and Variable Resolution (4 tests)
Tests: define_local, define_local_with_paths, global_instance_decls, global_proto_decls

Description: DefineLocal/DefineLocal2 actions for local variable declaration in functions. define_local (partially passing) has issues with prototype virtual setters. global_instance_decls and global_proto_decls test global variable declarations.

### This Scoping (2 tests)
Tests: this_scoping, this_swf5, this_swf6

Description: `this` binding behavior in different contexts. this_scoping (4% passing) tests this in with blocks, nested clips, and method calls.

---

## Likely Fixable with Bug Fixes to Existing Features

These tests are >60% passing and likely need bug fixes rather than new features:

| Test | Match Rate | Likely Issue |
|------|-----------|-------------|
| swf7_case_sensitive | 40/44 (91%) | Case-sensitive property lookup edge case |
| object_prototypes | 62/74 (84%) | Prototype chain traversal edge case |
| stage_object_children | 68/83 (82%) | Child clip name resolution |
| local_to_global | 40/49 (82%) | MovieClip.localToGlobal/globalToLocal transform math |
| target_clip_removed | 4/5 (80%) | Target clip removal edge case |
| textfield_properties | 35/44 (80%) | TextField property getters/setters |
| movieclip_hittest | 71/92 (77%) | hitTest() edge cases |
| xml_first_last_child | 6/8 (75%) | XML firstChild/lastChild null handling |
| attach_movie | 43/59 (73%) | attachMovie with init object or invalid IDs |
| empty_movieclip_can_attach_movies | 8/11 (73%) | attachMovie on empty clips |
| matrix | 123/171 (72%) | Matrix method implementations |
| point | 124/175 (71%) | Point method implementations |
| prototype_properties | 12/17 (71%) | Prototype property flags |
| rectangle | 516/745 (69%) | Rectangle method implementations |
| register_underflow | 18/26 (69%) | Register allocation edge case |
| swf6_case_insensitive | 29/42 (69%) | Case-insensitive lookup edge case |
| array_sort | 111/161 (69%) | Array.sort() comparator edge cases |
| as_set_prop_flags_version | 21/31 (68%) | ASSetPropFlags version-specific behavior |
| object_string_coerce_swf6 | 46/68 (68%) | toString/valueOf coercion ordering |
| globals_swf5/6/7 | ~66% | Missing global registrations |
| movieclip_depth_methods | 65/98 (66%) | Depth management edge cases |
| is_prototype_of | 59/89 (66%) | isPrototypeOf method |
| textfield_variable | 53/81 (65%) | TextField variable binding |
| string_paths_hidden | 35/54 (65%) | Hidden string path resolution |
| edittext_html_roundtrip | 11/17 (65%) | HTML text round-trip formatting |
| movieclip_get_instance_at_depth | 18/28 (64%) | getInstanceAtDepth edge cases |
| string_methods_swfv5 | 171/275 (62%) | SWF5 string method edge cases |
| with | 30/49 (61%) | With statement scope leaking |
| edittext_width_height | 63/103 (61%) | EditText dimension calculations |
| edittext_scroll | 33/54 (61%) | EditText scroll properties |
| arguments | 77/127 (61%) | arguments.callee, arguments.caller, Array prototype |
| string_methods | 172/285 (60%) | String method edge cases |
| edittext_align | 36/60 (60%) | Text alignment calculations |
| mutable_this | 12/18 (67%) | Mutable this binding in nested functions |
| date | 3617/6335 (57%) | Date timezone/edge case handling |

## Crashes and Timeouts (8 tests)

| Test | Status | Likely Cause |
|------|--------|-------------|
| device_font_spacing | segfault | Device font text measurement crash |
| duplicate_movie_clip_drawing | segfault | Drawing API on duplicated clip |
| goto_methods | segfault | MovieClip.gotoAndStop/gotoAndPlay with extreme values |
| path_string | segfault | String path resolution with tellTarget |
| swf4_actions_coercion_order | segfault | SWF4 type coercion during action execution |
| parse_float | timeout | parseFloat() infinite loop |
| timeout | timeout | setTimeout/clearTimeout infinite loop |
| try_catch_finally | timeout | Exception handling infinite loop |

---

## Summary by Feature Priority

| Priority | Feature | Test Count | Notes |
|----------|---------|-----------|-------|
| 1 | TextField/EditText Properties | 66 | Largest category; many partially passing |
| 2 | XML/XMLNode | 33 | Needs full DOM implementation |
| 3 | LoadMovie/LoadVariables/MCL | 29 | Needs network; may not be feasible |
| 4 | MovieClip Methods/Properties | 24 | getBounds, hitTest, createTextField, etc. |
| 5 | Mouse/Focus/Input Events | 19 | Needs synthetic event simulation |
| 6 | Button Behavior | 14 | Key events, display ordering |
| 7 | Tab Ordering | 14 | Complete tab navigation system |
| 8 | String Methods/Paths | 13 | Partially working; edge cases |
| 9 | Global Functions/Objects | 12 | Meta-tests; fixed by implementing other features |
| 10 | Sound | 8 | Sound object properties and methods |
| 11 | BitmapData | 8 | Additional methods beyond basics |
| 12 | FileReference | 8 | Needs network; not feasible |
| 13 | OOP/Super/Extends | 8 | Super keyword, interfaces |
| 14 | RegisterClass | 7 | Object.registerClass() |
| 15 | Stage Object | 7 | Stage properties |
| 16 | SWF Version Behavior | 7 | Version-specific edge cases |
| 17 | Misc (see above) | 46 | Various smaller features |
| -- | **Network-dependent** | **~49** | LoadMovie(29) + FileRef(8) + FormLoader(4) + XMLSocket(4) + XML.load(1) + NetConn/Stream(4) = unlikely to pass |
| -- | **Bug fixes only** | **~35** | Tests >60% passing, need edge case fixes |
