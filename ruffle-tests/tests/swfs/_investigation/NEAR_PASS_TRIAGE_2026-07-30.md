# Near-Pass Triage — 2026-07-30

Machine-generated inventory from tranche 0 of the **near-pass polish sweep**
(`SWFRecompDocs/plans/polish-sweep-arc.md`). Preserved because the raw
`--diff` sweep behind it cost ~12 minutes of compute and is the working
input for every bucket still open.

**Candidate rule:** every test in `results_graphics.json` across the 19
top-level leaf suites (never the 5 nested `_results` dirs) whose status is
not `pass`/`ruffle_matched` and whose `expected_lines - matching_lines <= 5`.
Snapshot taken at `9277e0e1b` / CI `30519577386`: **172 candidates**.

`Status` is as of CI `30548659769` (after the sweep's four batches):
`SHIPPED` = now passing, `EXTRA` = `matching == expected` so the fix must
REMOVE or REORDER output, blank = still open.

Machine-readable candidate list with line counts:
`near_pass_candidates_2026-07-30.json`.

| Suite | Test | Gap | Status | Bucket / cause | First differing line (expected → actual) |
|---|---|---:|---|---|---|
| audio | `g711` | 4 |  | single | `PASS` → `Starting tone: tone_mulaw_mono.flv` |
| avm1 | `form_loader_encoding_2` | 3 |  | B11 avm1 charset decode | `UTF8: Ã„Ã–Ãœ ÃŸ - ç‰‡ä»®` → `UTF8: ÄÖÜ ß - 片仮` |
| avm1 | `form_loader_encoding_3` | 2 |  | B11 avm1 charset decode | `Iso Latin-1: ÄÖÜ ß` → `Iso Latin-1: Ėܠ�` |
| avm1 | `geturl` | 3 |  | single | `Param: value2=2` → `<end of actual>` |
| avm1 | `load_cancel_via_removemovieclip` | 0 | EXTRA | D-crossvm (multi-SWF/AVM1Movie) | `<end of expected>` → `MovieClipLoader.onLoadStart` |
| avm1 | `native_objects_swf6` | 1 |  | single | `new TextField(): non-object: undefined` → `new TextField(): native` |
| avm1 | `remove_different_level` | 1 |  | D-crossvm (multi-SWF/AVM1Movie) | `undefined` → `<end of actual>` |
| avm1 | `sandbox_type_remote` | 2 |  | D-crossvm (multi-SWF/AVM1Movie) | `[network] Current sandbox type: remote` → `<end of actual>` |
| avm1 | `shared_stack` | 5 |  | D-crossvm (multi-SWF/AVM1Movie) | `in child frame 2/1:` → `in frame 2/1:` |
| avm1 | `string_relational_compare` | 1 |  | single | `true` → `false` |
| avm2 | `accessibility` | 1 |  | single | `false` → `` |
| avm2 | `activation_class` | 3 |  | single | `Threw error, code 1069` → `Threw error, code 1006` |
| avm2 | `air_ifilepromise` | 1 |  | single | `IFilePromise: [class IFilePromise]` → `` |
| avm2 | `applicationdomain_hasdefinition_null` | 1 |  | single | `false` → `true` |
| avm2 | `av_tag_data` | 2 |  | single | `test string` → `<end of actual>` |
| avm2 | `bitmapdata_draw_alpha_erase` | 2 |  | single | `alphaData after alpha: 44224365` → `alphaData after alpha: ff224466` |
| avm2 | `bitmapdata_zero_size` | 3 |  | D-tracing (blocked on filters arc) | `ArgumentError: Error #2015: Invalid BitmapData.` → `<end of actual>` |
| avm2 | `blend_mode_null` | 1 |  | single | `2007` → `null blendMode should not be set` |
| avm2 | `bom` | 5 |  | single | `URLLoader dataFormat=text utf16le: lastName=Jo∀nes&firstN…` → `URLLoader dataFormat=text utf16le: ��lastName=Jo"nes&firs…` |
| avm2 | `button_bounds` | 1 |  | B4 hit-test/bounds | `(x=188.8, y=112.6, w=91.64999999999998, h=21.200000000000…` → `(x=0, y=0, w=0, h=0)` |
| avm2 | `button_hittest` | 1 |  | B4 hit-test/bounds | `true` → `false` |
| avm2 | `button_nested_frame_simple` | 0 | EXTRA | single | `<end of expected>` → `Main enter frame: [Event type="enterFrame" bubbles=false …` |
| avm2 | `construct_interface` | 1 | SHIPPED | B1 verifier msgs | `VerifyError: Error #1001: The method ITest() is not imple…` → `VerifyError: Error #1001: The method undefined is not imp…` |
| avm2 | `constructprop_method` | 2 |  | single | `[object TypeError]` → `<end of actual>` |
| avm2 | `constructsuper_null` | 2 |  | single | `1009` → `This shouldn't be traced!` |
| avm2 | `cpool_index_invalid_bytecode_2` | 3 | SHIPPED | B1 verifier msgs | `VerifyError Error #1032: Cpool index 0 is out of range 38.` → `VerifyError string cpool index out of range: 0` |
| avm2 | `cpool_index_invalid_bytecode_3` | 1 | SHIPPED | B1 verifier msgs | `VerifyError - Error #1060: ClassInfo 40 exceeds class_cou…` → `VerifyError - class index out of range: 40` |
| avm2 | `cross_api_version_call_newer` | 1 |  | single | `Initialized Newer with parent: null Event = undefined` → `Initialized Newer with parent: null Event = workerState` |
| avm2 | `displayobject_hittestpoint` | 2 |  | B4 hit-test/bounds | `false` → `true` |
| avm2 | `displayobject_hittestpoint_root` | 2 |  | B4 hit-test/bounds | `true` → `false` |
| avm2 | `displayobject_opaque_background` | 1 |  | single | `null` → `undefined` |
| avm2 | `displayobjectcontainer_getobjectsunderpoint` | 2 |  | B4 hit-test/bounds | `[object Sprite],[object Sprite],[object Sprite],[object S…` → `<end of actual>` |
| avm2 | `doabc_and_symbolclass_script_init_normal` | 5 |  | single | `New constructor` → `Z` |
| avm2 | `error_tostring_more` | 2 |  | single | `DRMManagerError: 'My Error', error ID:'42', subErrorID:'1…` → `Error: My Error` |
| avm2 | `game_input` | 4 |  | single | `gameInput: [object GameInput]` → `<end of actual>` |
| avm2 | `generate_random_bytes` | 3 |  | single | `// var ba: ByteArray = generateRandomBytes(5);` → `<end of actual>` |
| avm2 | `getouterscope_two_classobjects` | 5 |  | single | `null` → `undefined` |
| avm2 | `graphic_linkage` | 2 |  | single | `0` → `40.35` |
| avm2 | `instantiate_root_character` | 1 |  | single | `instance.myChild: [object MovieClip]` → `instance.myChild: null` |
| avm2 | `invalid_utf8` | 1 |  | B5 astral UTF-8 (reclassified: NOT polish) | `🐌` → `������` |
| avm2 | `issue_8630_placeremoveplace` | 2 |  | single | `2.75` → `0.75` |
| avm2 | `issue_8630_placeremoveplace_scriptremove` | 3 |  | single | `2.75` → `0.75` |
| avm2 | `loader_applicationDomain` | 4 |  | single | `[class PropertyChangeEvent]` → `<end of actual>` |
| avm2 | `loader_load` | 4 |  | D-tracing (blocked on filters arc) | `cccc=true&aaa=bbb` → `aaa=bbb&cccc=true` |
| avm2 | `loader_method` | 2 |  | D-tracing (blocked on filters arc) | `TypeError: Error #1034: Type Coercion failed: cannot conv…` → `<end of actual>` |
| avm2 | `method_association` | 4 |  | single | `1107` → `Passed` |
| avm2 | `method_without_body` | 3 |  | B1 verifier msgs | `Caught error` → `<end of actual>` |
| avm2 | `mouse_pick_avm1_root` | 1 |  | B4 hit-test/bounds | `avm1 child clicked` → `Clicked on: [object Stage] (null)` |
| avm2 | `movieclip_hittest` | 2 |  | B4 hit-test/bounds | `true` → `false` |
| avm2 | `netstream_flv_date` | 3 |  | single | `init finished` → `<end of actual>` |
| avm2 | `newclass_mismatched` | 4 |  | single | `#1: 1034` → `#1: 1108` |
| avm2 | `parse_float_swf10` | 2 |  | single | `12345.678` → `1.2345` |
| avm2 | `parse_int` | 2 |  | single | `785077` → `33790067563981` |
| avm2 | `perspective_projection_basic` | 5 |  | single | `perspectiveProjection = [object PerspectiveProjection]` → `perspectiveProjection = null` |
| avm2 | `pixelbender_effect_glassDisplace_shaderfilter` | 2 |  | D-filters (filters arc) | `Shader equal: true` → `<end of actual>` |
| avm2 | `place_and_lookup/swf10` | 4 |  | single | `[object Video]` → `[object MovieClip]` |
| avm2 | `place_and_lookup/swf9` | 4 |  | single | `[object Video]` → `[object MovieClip]` |
| avm2 | `print_job_options` | 3 |  | single | `false` → `<end of actual>` |
| avm2 | `property_is_enumerable_reset` | 1 |  | single | `is prop enumerable: true` → `is prop enumerable: false` |
| avm2 | `property_priority_chained` | 3 |  | single | `subclass-field1` → `superclass-field1` |
| avm2 | `property_priority_definition_names_order` | 2 |  | B9 qualified error names | `p1::Same` → `<end of actual>` |
| avm2 | `sandbox_type_remote` | 2 |  | D-crossvm (multi-SWF/AVM1Movie) | `[Network] Current sandbox type: remote` → `<end of actual>` |
| avm2 | `scope_optimizations` | 1 |  | single | `[class field]` → `0` |
| avm2 | `scopes_dont_cache/order-1` | 1 |  | single | `inner-value` → `` |
| avm2 | `scopes_dont_cache/order-2` | 1 |  | single | `inner-value` → `` |
| avm2 | `security_domain_current` | 2 |  | single | `[object SecurityDomain]` → `<end of actual>` |
| avm2 | `selection_onsetfocus_mixed_avm` | 5 |  | D-crossvm (multi-SWF/AVM1Movie) | `null null` → `<end of actual>` |
| avm2 | `sound_constructor_with_args` | 4 |  | single | `Callback: Open` → `<end of actual>` |
| avm2 | `sound_rootless` | 2 |  | single | `Finished playback` → `<end of actual>` |
| avm2 | `stage_domain_getQualifiedDefinitionNames` | 4 |  | single | `Stage getQualifiedDefinitionNames(): Test,test_fla::MainT…` → `<end of actual>` |
| avm2 | `static_text` | 3 |  | single | `Caught error: ArgumentError: Error #2012: StaticText$ cla…` → `Child: [object StaticText]` |
| avm2 | `stylesheet` | 1 |  | B5 astral UTF-8 (reclassified: NOT polish) | `styleSheet.getStyle("a.b.c-d!#@$😜") = {` → `styleSheet.getStyle("a.b.c-d!#@$��") = {` |
| avm2 | `stylesheet_parse_color` | 4 |  | B10 StyleSheet CSS parse | `parsed color: ff0000` → `parsed color: 0` |
| avm2 | `stylesheet_transform` | 3 |  | B10 StyleSheet CSS parse | `! 1069` → `format = null` |
| avm2 | `subclass_superclass_linked_symbol` | 4 |  | single | `SubClass before super(): this.target_from_subclass = null…` → `SuperClass before super(): this.target_from_superclass=nu…` |
| avm2 | `supercalls_weird` | 2 |  | single | `true` → `<end of actual>` |
| avm2 | `superinterface_call` | 5 |  | single | `BaseInterface method` → `<end of actual>` |
| avm2 | `swz` | 2 |  | single | `[class ByteArrayAsset]` → `<end of actual>` |
| avm2 | `system_exit` | 3 |  | single | `SecurityError: Error #2017: Only trusted local files may …` → `TypeError: Error #1006: exit is not a function.` |
| avm2 | `system_setclipboard_null` | 1 |  | single | `2007` → `1006` |
| avm2 | `textline_name` | 1 |  | single | `instance1` → `` |
| avm2 | `uncaught_error_basic` | 2 |  | D-tracing (blocked on filters arc) | `Error: hello` → `<end of actual>` |
| avm2 | `verification` | 3 | SHIPPED | B1 verifier msgs | `Error of test4: VerifyError: Error #1011: Method Tests/te…` → `Error of test4: VerifyError: unknown ABC opcode 0x6b` |
| avm2 | `verify_dxns_without_flag` | 2 | SHIPPED | B1 verifier msgs | `VerifyError: Error #1015: Method Test/dxnsMethod() cannot…` → `VerifyError: dxnslate used in method without SET_DXNS flag` |
| avm2 | `verify_exception_target_two_jumps` | 1 |  | B1 verifier msgs | `Verify failed! VerifyError: Error #1030: Stack depth is u…` → `Verify failed! VerifyError: stack underflow at op 21` |
| avm2 | `verify_illegal_opcode` | 1 |  | B1 verifier msgs + D-tracing | `VerifyError: Error #1011: Method Test() contained illegal…` → `` |
| avm2 | `verify_jump_to_middle_of_op` | 1 | SHIPPED | B1 verifier msgs | `Error: VerifyError: Error #1021: At least one branch targ…` → `Error: VerifyError: branch target is not on an instructio…` |
| avm2 | `verify_method_info_duplicate` | 2 |  | B1 verifier msgs + D-tracing | `VerifyError: Error #1121: Method Test/hello() has a dupli…` → `<end of actual>` |
| avm2 | `verify_method_info_oob` | 1 |  | B1 verifier msgs + D-tracing | `VerifyError: Error #1027: Method_info 7 exceeds method_co…` → `` |
| avm2 | `verify_stack` | 3 | SHIPPED | B1 verifier msgs | `Overflow did throw VerifyError: Error #1023: Stack overfl…` → `Overflow did throw VerifyError: stack overflow at op 1 (d…` |
| avm2 | `verify_typecheck` | 4 |  | B1 verifier msgs | `1058` → `<end of actual>` |
| avm2 | `xml_appendchild_swf_v21` | 1 |  | single | `</root>` → `<a>Test</a>` |
| fonts | `device_font_kerning` | 4 |  | single | `LM width: 50` → `LM width: 23` |
| from_avmplus | `as3/Definitions/Classes/Ext/ExtPublicClassPriv` | 5 |  | single | `Access private method from a default method of a sub clas…` → `Access private method from a default method of a sub clas…` |
| from_avmplus | `as3/Definitions/Super/SuperRuntimeError` | 1 |  | B12 private access must throw | `call private base method via super PASSED!` → `call private base method via super FAILED! expected: Refe…` |
| from_avmplus | `as3/Definitions/Variable/AccessPrivateClassVariable_rt` | 1 |  | B12 private access must throw | `attempt to access private variable of Class1 in Class2 PA…` → `attempt to access private variable of Class1 in Class2 FA…` |
| from_avmplus | `as3/Definitions/Variable/ConstVariables_custom1` | 1 | SHIPPED | B9 qualified error names | `ReferenceError: Error #1074: Illegal write to read-only p…` → `ReferenceError: Error #1074: Illegal write to read-only p…` |
| from_avmplus | `as3/Expressions/QualifiedReferences/WildcardOperator` | 2 |  | B6 #1081 sealed read | `Use wildcard operator on an array PASSED!` → `Use wildcard operator on an array FAILED! expected: Refer…` |
| from_avmplus | `as3/RuntimeErrors/Error1050CannotConvertToPrimitive` | 2 |  | single | `Asserting for TypeError PASSED!` → `Runtime Error FAILED! expected: Error #1050 got: Error #1…` |
| from_avmplus | `as3/RuntimeErrors/Error1052InvalidUriPassed` | 1 |  | single | `Runtime Error PASSED!` → `Runtime Error FAILED! expected: Error #1052 got: no error` |
| from_avmplus | `as3/RuntimeErrors/Error1064CannotCallMethodAsConstructor` | 1 |  | single | `Runtime Error PASSED!` → `Runtime Error FAILED! expected: TypeError: Error #1064 go…` |
| from_avmplus | `as3/RuntimeErrors/Error1074IllegalWriteToReadOnlyProp` | 1 |  | B9 qualified error names | `Runtime Error PASSED!` → `` |
| from_avmplus | `as3/RuntimeErrors/Error1075MathNotAFunction` | 1 | SHIPPED | B2 Math not callable | `Runtime Error PASSED!` → `Runtime Error FAILED! expected: TypeError: Error #1075 go…` |
| from_avmplus | `as3/RuntimeErrors/Error1076MathNotAConstructor` | 1 | SHIPPED | B2 Math not callable | `Runtime Error PASSED!` → `Runtime Error FAILED! expected: TypeError: Error #1076 go…` |
| from_avmplus | `as3/RuntimeErrors/Error1081ReadSealedErrorNs` | 1 |  | B6 #1081 sealed read | `Reference Error PASSED!` → `Reference Error FAILED! expected: ReferenceError: Error #…` |
| from_avmplus | `as3/RuntimeErrors/Error1115NotAConstructor/v10` | 3 |  | single | `[Object] Runtime Error PASSED!` → `[Object] Runtime Error FAILED! expected: TypeError: Error…` |
| from_avmplus | `as3/RuntimeErrors/Error1117InvalidXmlName` | 2 |  | single | `Asserting for TypeError PASSED!` → `Runtime Error FAILED! expected: Error #1117 got: no error` |
| from_avmplus | `as3/RuntimeErrors/Error1119DeleteDoesNotSupportXMLListOperand` | 2 |  | single | `Asserting for TypeError PASSED!` → `Runtime Error FAILED! expected: Error #1119 got: no error` |
| from_avmplus | `as3/RuntimeErrors/Error1120CannotDeleteProperty` | 1 |  | single | `Runtime Error PASSED!` → `Runtime Error FAILED! expected: Error #1120 got: no error` |
| from_avmplus | `e4x/Expressions/e11_1_1` | 4 |  | single | `11 PASSED!` → `11 FAILED! expected: \|value3\| got: \|\|` |
| from_avmplus | `e4x/Global/isXMLNameTypeErr` | 5 |  | single | `Asserting for TypeError PASSED!` → `var object1 = { toString: function() { return this; } }; …` |
| from_avmplus | `e4x/Namespace/e13_2_5` | 2 |  | single | `3 PASSED!` → `3 FAILED! expected: \|true\| got: \|false\|` |
| from_avmplus | `e4x/QName/e13_3_2` | 1 |  | single | `x1.bravo.@[q3] PASSED!` → `x1.bravo.@[q3] FAILED! expected: value3 got:` |
| from_avmplus | `e4x/Regress/regress-263935` | 2 |  | single | `1 PASSED!` → `1 FAILED! expected: \|<foo>one</foo>` |
| from_avmplus | `e4x/Regress/regress-524214` | 2 |  | single | `wildcard attribute assignment one result PASSED!` → `wildcard attribute assignment one result FAILED! expected…` |
| from_avmplus | `e4x/XML/e13_4_4_17` | 1 |  | single | `Undefined namespace: PASSED!` → `Undefined namespace: FAILED! expected: exception got: no …` |
| from_avmplus | `e4x/XML/e13_4_4_28` | 1 | SHIPPED | B8 e4x PI AttributeName | `MYXML = new XML(xmlDoc), MYXML.processingInstructions('@x…` → `MYXML = new XML(xmlDoc), MYXML.processingInstructions('@x…` |
| from_avmplus | `e4x/XML/e13_4_4_32/v9` | 1 |  | single | `MYXML = new XML(xmlDoc), MYXML.replace('*','<phone>123456…` → `MYXML = new XML(xmlDoc), MYXML.replace('*','<phone>123456…` |
| from_avmplus | `e4x/XML/e13_4_4_36` | 3 |  | single | `MYXML = new XML(xmlDoc), MYXML.setNamespace('http://zxz.o…` → `MYXML = new XML(xmlDoc), MYXML.setNamespace('http://zxz.o…` |
| from_avmplus | `e4x/XMLList/e13_5_4_17` | 1 | SHIPPED | B8 e4x PI AttributeName | `MYXML = new XMLList(xmlDoc), MYXML.processingInstructions…` → `MYXML = new XMLList(xmlDoc), MYXML.processingInstructions…` |
| from_avmplus | `ecma3/Exceptions/exception_001_rt` | 1 | SHIPPED | B2 Math not callable | `Math() PASSED!` → `Math() FAILED! expected: TypeError: Error #1075 got: Argu…` |
| from_avmplus | `ecma3/Exceptions/exception_002_rt` | 1 | SHIPPED | B2 Math not callable | `new Math() PASSED!` → `` |
| from_avmplus | `ecma3/Exceptions/exception_011_rt` | 2 |  | single | `undefined` → `<end of actual>` |
| from_avmplus | `ecma3/Exceptions/expression_005_rt` | 1 | SHIPPED | B2 Math not callable | `result= new Math() (threw TypeError: Error #1076: Math is…` → `result= new Math() (threw No exception thrown: Math is no…` |
| from_avmplus | `ecma3/Expressions/e11_2_2_10_rt` | 1 | SHIPPED | B2 Math not callable | `var m = new Math() PASSED!` → `var m = new Math() FAILED! expected: TypeError: Error #10…` |
| from_avmplus | `ecma3/Function/e15_3_4_3_1` | 1 | SHIPPED | B7 apply/call arity | `function string1 PASSED!` → `function string1 FAILED! expected: 2 got: 0` |
| from_avmplus | `ecma3/Function/e15_3_4_4_1_rt` | 1 | SHIPPED | B7 apply/call arity | `function string 1 PASSED!` → `function string 1 FAILED! expected: 1 got: 0` |
| from_avmplus | `ecma3/GlobalObject/e15_1_2_2_2` | 3 |  | single | `parseInt("00000010000000010010001101000101011001111000100…` → `parseInt("00000010000000010010001101000101011001111000100…` |
| from_avmplus | `ecma3/Number/toLocaleString_rt` | 4 |  | single | `s = Number.prototype.toLocaleString; o = new Number(); o.…` → `s = Number.prototype.toLocaleString; o = new Number(); o.…` |
| from_avmplus | `ecma3/ObjectObjects/hasOwnProperty` | 1 |  | single | `str.hasOwnProperty("split") PASSED!` → `str.hasOwnProperty("split") FAILED! expected: false got: …` |
| from_avmplus | `ecma3/ObjectObjects/isPrototypeOf` | 2 |  | single | `String.prototype.isPrototypeOf(str) PASSED!` → `String.prototype.isPrototypeOf(str) FAILED! expected: tru…` |
| from_avmplus | `ecma3/Statements/e12_10` | 1 |  | single | `var x; with (7) x = valueOf(); typeof x; PASSED!` → `var x; with (7) x = valueOf(); typeof x; FAILED! expected…` |
| from_avmplus | `ecma3/Statements/eforin_001` | 4 |  | single | `object[company] PASSED!` → `object[year] PASSED!` |
| from_avmplus | `ecma3/String/e15_5_4_5_4` | 2 |  | single | `(String.fromCharCode(56200)).charCodeAt(0) PASSED!` → `(String.fromCharCode(56200)).charCodeAt(0) FAILED! expect…` |
| from_avmplus | `ecma3/String/e15_5_5_1` | 3 |  | single | `var s = new String(); delete s.length PASSED!` → `var s = new String(); delete s.length FAILED! expected: R…` |
| from_avmplus | `ecma3/TypeConversion/e9_3_1_3_rt` | 5 |  | single | `parseInt("00000010000000010010001101000101011001111000100…` → `parseInt("00000010000000010010001101000101011001111000100…` |
| from_avmplus | `ecma3/Unicode/utf8count` | 1 |  | single | `str_utf8 == str_utf16 PASSED!` → `str_utf8 == str_utf16 FAILED! expected: true got: false` |
| from_avmplus | `misc/bug_508617` | 5 |  | single | `test_0 PASSED!` → `<end of actual>` |
| from_avmplus | `recursion/pcre_find_fixedlength` | 1 |  | D-ceiling (unfixable) | `strOriginal.match(re) FAILED! expected: null got: hello,b…` → `strOriginal.match(re) FAILED! expected: null got: hello` |
| from_avmplus | `regress/bug_483783` | 1 |  | single | `Verify large string is created PASSED!` → `` |
| from_avmplus | `regress/bug_550958` | 1 |  | single | `mixedcase PASSED!` → `<end of actual>` |
| from_gnash/misc-swfc.all | `sound` | 0 | EXTRA | single | `<end of expected>` → `Total tests run: 1 typeof expected: number` |
| from_shumway | `acid/acid-filter` | 2 |  | D-filters (filters arc) | `3300ff` → `<end of actual>` |
| from_shumway | `acid/acid-morph` | 2 |  | single | `false` → `true` |
| from_shumway | `acid/acid-text-2` | 1 |  | single | `Text is: AABBBBBBBBBBBBBBBBBBBBAB` → `Text is: undefined` |
| from_shumway | `as3-loader/LoaderLoadBytesTest` | 3 |  | single | `from loadee: loaded` → `loadee initialized, url relative to swf: /[[DYNAMIC]]/1` |
| from_shumway | `as3-loader/LoaderTest2` | 1 |  | single | `testSymbol present: true` → `testSymbol present: false` |
| from_shumway | `as3-loader/bug1157243/empty` | 1 |  | single | `true` → `` |
| from_shumway | `as3-loader/bug1157243/invalid` | 1 |  | single | `true` → `` |
| from_shumway | `bitmapdata/getpixel-from-embedded` | 2 |  | single | `908a8c` → `ffffff` |
| from_shumway | `blendmode/blendmode_1` | 1 |  | B3 timeline/nav PlaceObject | `multiply` → `normal` |
| from_shumway | `blendmode/blendmode_2` | 2 |  | B3 timeline/nav PlaceObject | `ArgumentError #2008` → `N/A` |
| from_shumway | `esc` | 2 |  | single | `388 bytes in 78 ms` → `<end of actual>` |
| from_shumway | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 5 |  | D-fuzz (low-confidence oracle) | `2` → `3` |
| from_shumway | `stroke1` | 1 |  | single | `Done` → `ERROR: (3,3) shall be outside` |
| from_shumway | `timeline/nav/blendMode` | 2 |  | B3 timeline/nav PlaceObject | `Blend mode: invert` → `Blend mode: normal` |
| from_shumway | `timeline/nav/cacheAsBitmap` | 2 |  | B3 timeline/nav PlaceObject | `Cache as bitmap: true` → `Cache as bitmap: false` |
| from_shumway | `timeline/nav/colorTransform` | 2 |  | B3 timeline/nav PlaceObject | `Color transform: (redMultiplier=0, greenMultiplier=0, blu…` → `Color transform: (redMultiplier=1, greenMultiplier=1, blu…` |
| from_shumway | `timeline/nav/filters` | 2 |  | B3 timeline/nav + D-filters | `Number of filters: 1` → `Number of filters: 0` |
| from_shumway | `timeline/nav/matrix` | 1 |  | B3 timeline/nav PlaceObject | `Matrix transform: (a=1, b=0, c=0, d=1, tx=0, ty=0)` → `Matrix transform: (a=1, b=0, c=0, d=1, tx=225, ty=150)` |
| from_shumway | `timeline/nav/morphShape` | 1 |  | B3 timeline/nav PlaceObject | `New object placed on frame 1: true` → `New object placed on frame 1: false` |
| from_shumway | `timeline/nav/ratio` | 1 |  | B3 timeline/nav PlaceObject | `New object placed on frame 1: true` → `New object placed on frame 1: false` |
| from_shumway | `timeline/nav/ratio2` | 1 |  | B3 timeline/nav PlaceObject | `New object placed on frame 1: false` → `New object placed on frame 1: true` |
| mixed_avm | `avm1_loads_avm2` | 4 |  | D-crossvm (multi-SWF/AVM1Movie) | `[object Stage]` → `<end of actual>` |
| mixed_avm | `avm1_loads_avm2_doaction` | 0 | EXTRA | D-crossvm (multi-SWF/AVM1Movie) | `<end of expected>` → `Hello from inner SWF (DoInitAction) - this shouldn't print` |
| mixed_avm | `avm2_loads_avm1_doabc` | 3 |  | D-crossvm (multi-SWF/AVM1Movie) | `Hello from DoAction tag on frame 1 of avm1.swf` → `<end of actual>` |
| mixed_avm | `avm2_loads_avm1_loads_avm2_doabc` | 2 |  | D-crossvm (multi-SWF/AVM1Movie) | `AVM1 SWF: Hello from AVM1` → `<end of actual>` |
| mixed_avm | `avm2_loads_avm1_loads_into_root` | 1 |  | D-crossvm (multi-SWF/AVM1Movie) | `hello from outer!` → `<end of actual>` |
| mixed_avm | `avm2_loads_avm1_v10` | 5 |  | D-crossvm (multi-SWF/AVM1Movie) | `Content after load: [object AVM1Movie]` → `Content after load: null` |
| text | `links_in_scrolled_text` | 1 |  | single | `Success!` → `` |
| visual | `avm2_button_scroll_rect` | 2 |  | B4 hit-test/bounds | `frame 1: (x=0, y=0, w=100, h=100)` → `frame 1: (x=0, y=0, w=0, h=0)` |
| visual | `filters/avm1_convolution_initialization` | 1 |  | D-filters (filters arc) | `1` → `0` |

Total: 172 candidates, 19 shipped by the sweep's session 1.

Bucket keys `B1`-`B12` and the `D-*` deferred groups are defined in
`polish-sweep-arc.md` §1, which also carries the per-bucket owner,
predicted yield and worked example. `single` means one distinct cause with
no sibling in this candidate set — read the signature column.
