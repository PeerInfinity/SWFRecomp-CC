# AS2 Opcode Index

**Generated**: 2025-11-11

**Total Opcodes**: 100

**Implemented Opcodes**: 99

## Test Statistics

**Primary Tests**: 117/118 passing (99.2%)
  - 1 failing primary tests
  - 1 opcodes with failing primary tests

## Implementation Progress

**Fully Implemented Opcodes**: 85/100

**Fully Implemented Opcodes - No Graphics Mode**: 99/100

**Opcodes with Primary Tests**: 99

**Opcodes with Documentation**: 99

## What Needs Attention

- **1 failing primary tests** across 1 opcodes (see 'Failing Primary' column)
- **15 opcodes** not yet marked as fully implemented
- **1 opcodes** not yet marked as fully implemented for NO_GRAPHICS mode


## Summary Table

| Hex | Spec Name | Enum Name | Function Name | Primary Tests | Secondary Tests | Failing Primary | Docs | Fully Impl | Fully Impl (No Graphics) |
|-----|-----------|-----------|---------------|---------------|-----------------|-----------------|------|------------|--------------------------|
| 0X00 |  | SWF_ACTION_END_OF_ACTIONS |  |  |  |  |  |  |  |
| 0X04 | ActionNextFrame | SWF_ACTION_NEXT_FRAME | actionNextFrame | 1/1 |  |  | ✓ | ✓ | ✓ |
| 0X05 | ActionPreviousFrame | SWF_ACTION_PREV_FRAME | actionPrevFrame | 1/1 |  |  | ✓ | ✓ |  |
| 0X06 | ActionPlay | SWF_ACTION_PLAY | actionPlay | 2/2 |  |  | ✓ | ✓ | ✓ |
| 0X07 | ActionStop | SWF_ACTION_STOP |  | 3/3 | 3/3 |  | ✓ | ✓ |  |
| 0X08 | ActionToggleQuality | SWF_ACTION_TOGGLE_QUALITY | actionToggleQuality | 1/1 |  |  | ✓ |  | ✓ |
| 0X09 | ActionStopSounds | SWF_ACTION_STOP_SOUNDS | actionStopSounds | 1/1 |  |  | ✓ |  | ✓ |
| 0X0A | ActionAdd | SWF_ACTION_ADD | actionAdd | 1/2 | 4/4 | 1 | ✓ | ✓ |  |
| 0X0B | ActionSubtract | SWF_ACTION_SUBTRACT | actionSubtract | 1/1 |  |  | ✓ | ✓ |  |
| 0X0C | ActionMultiply | SWF_ACTION_MULTIPLY | actionMultiply | 1/1 |  |  | ✓ | ✓ |  |
| 0X0D | ActionDivide | SWF_ACTION_DIVIDE | actionDivide | 1/1 | 1/1 |  | ✓ | ✓ |  |
| 0X0E | ActionEquals | SWF_ACTION_EQUALS | actionEquals | 1/1 |  |  | ✓ | ✓ |  |
| 0X0F | ActionLess | SWF_ACTION_LESS | actionLess | 2/2 |  |  | ✓ | ✓ |  |
| 0X10 | ActionAnd | SWF_ACTION_AND | actionAnd | 5/5 |  |  | ✓ | ✓ |  |
| 0X11 | ActionOr | SWF_ACTION_OR | actionOr | 1/1 |  |  | ✓ | ✓ |  |
| 0X12 | ActionNot | SWF_ACTION_NOT | actionNot | 1/1 |  |  | ✓ | ✓ |  |
| 0X13 | ActionStringEquals | SWF_ACTION_STRING_EQUALS | actionStringEquals | 2/2 |  |  | ✓ | ✓ |  |
| 0X14 | ActionStringLength | SWF_ACTION_STRING_LENGTH | actionStringLength | 1/1 |  |  | ✓ | ✓ |  |
| 0X15 | ActionStringExtract | SWF_ACTION_STRING_EXTRACT | actionStringExtract | 1/1 |  |  | ✓ | ✓ |  |
| 0X17 | ActionPop | SWF_ACTION_POP |  | 1/1 | 5/5 |  | ✓ | ✓ |  |
| 0X18 | ActionToInteger | SWF_ACTION_TO_INTEGER | actionToInteger | 1/1 |  |  | ✓ | ✓ |  |
| 0X1C | ActionGetVariable | SWF_ACTION_GET_VARIABLE | actionGetVariable | 1/1 | 10/10 |  | ✓ | ✓ |  |
| 0X1D | ActionSetVariable | SWF_ACTION_SET_VARIABLE | actionSetVariable | 1/1 | 9/9 |  | ✓ | ✓ |  |
| 0X20 | ActionSetTarget2 | SWF_ACTION_SET_TARGET2 | actionSetTarget2 | 1/1 |  |  | ✓ |  | ✓ |
| 0X21 | ActionStringAdd | SWF_ACTION_STRING_ADD | actionStringAdd | 1/1 | 3/3 |  | ✓ | ✓ |  |
| 0X22 | ActionGetProperty | SWF_ACTION_GET_PROPERTY | actionGetProperty | 1/1 |  |  | ✓ | ✓ |  |
| 0X23 | ActionSetProperty | SWF_ACTION_SET_PROPERTY | actionSetProperty | 1/1 |  |  | ✓ |  | ✓ |
| 0X24 | ActionCloneSprite | SWF_ACTION_CLONE_SPRITE | actionCloneSprite | 1/1 |  |  | ✓ |  | ✓ |
| 0X25 | ActionRemoveSprite | SWF_ACTION_REMOVE_SPRITE | actionRemoveSprite | 1/1 |  |  | ✓ |  | ✓ |
| 0X26 | ActionTrace | SWF_ACTION_TRACE | actionTrace | 1/1 | 110/111 |  | ✓ | ✓ |  |
| 0X27 | ActionStartDrag | SWF_ACTION_START_DRAG | actionStartDrag | 1/1 | 1/1 |  | ✓ |  | ✓ |
| 0X28 | ActionEndDrag | SWF_ACTION_END_DRAG | actionEndDrag | 1/1 |  |  | ✓ |  | ✓ |
| 0X29 | ActionStringLess | SWF_ACTION_STRING_LESS | actionStringLess | 1/1 |  |  | ✓ | ✓ |  |
| 0X2A | ActionThrow | SWF_ACTION_THROW | actionThrow | 2/2 |  |  | ✓ | ✓ |  |
| 0X2B | ActionCastOp | SWF_ACTION_CAST_OP | actionCastOp | 1/1 |  |  | ✓ | ✓ |  |
| 0X2C | ActionImplementsOp | SWF_ACTION_IMPLEMENTS_OP | actionImplementsOp | 1/1 |  |  | ✓ | ✓ |  |
| 0X30 | ActionRandomNumber | SWF_ACTION_RANDOM_NUMBER | actionRandomNumber | 1/1 |  |  | ✓ | ✓ |  |
| 0X31 | ActionMBStringLength | SWF_ACTION_MB_STRING_LENGTH | actionMbStringLength | 1/1 |  |  | ✓ | ✓ |  |
| 0X32 | ActionCharToAscii | SWF_ACTION_CHAR_TO_ASCII | actionCharToAscii | 1/1 |  |  | ✓ | ✓ |  |
| 0X33 | ActionAsciiToChar | SWF_ACTION_ASCII_TO_CHAR | actionAsciiToChar | 1/1 |  |  | ✓ | ✓ |  |
| 0X34 | ActionGetTime | SWF_ACTION_GET_TIME | actionGetTime | 1/1 |  |  | ✓ | ✓ |  |
| 0X35 | ActionMBStringExtract | SWF_ACTION_MB_STRING_EXTRACT | actionMbStringExtract | 1/1 |  |  | ✓ | ✓ |  |
| 0X36 | ActionMBCharToAscii | SWF_ACTION_MB_CHAR_TO_ASCII | actionMbCharToAscii | 1/1 |  |  | ✓ | ✓ |  |
| 0X37 | ActionMBAsciiToChar | SWF_ACTION_MB_ASCII_TO_CHAR | actionMbAsciiToChar | 3/3 |  |  | ✓ | ✓ |  |
| 0X3A | ActionDelete | SWF_ACTION_DELETE | actionDelete | 1/1 |  |  | ✓ | ✓ |  |
| 0X3B | ActionDelete2 | SWF_ACTION_DELETE2 | actionDelete2 | 1/1 |  |  | ✓ | ✓ |  |
| 0X3C | ActionDefineLocal | SWF_ACTION_DEFINE_LOCAL | actionDefineLocal | 1/1 |  |  | ✓ | ✓ |  |
| 0X3D | ActionStackSwap | SWF_ACTION_CALL_FUNCTION | actionStackSwap | 1/1 | 2/2 |  | ✓ | ✓ |  |
| 0X3E | ActionReturn | SWF_ACTION_RETURN | actionReturn | 1/1 | 3/3 |  | ✓ | ✓ |  |
| 0X3F | ActionModulo | SWF_ACTION_MODULO | actionModulo | 1/1 |  |  | ✓ | ✓ |  |
| 0X40 | ActionNewObject | SWF_ACTION_NEW_OBJECT | actionNewObject | 1/1 |  |  | ✓ | ✓ |  |
| 0X41 | ActionDefineLocal2 | SWF_ACTION_DECLARE_LOCAL | actionDeclareLocal | 1/1 |  |  | ✓ | ✓ |  |
| 0X42 | ActionInitArray | SWF_ACTION_INIT_ARRAY | actionInitArray | 1/1 |  |  | ✓ | ✓ |  |
| 0X43 | ActionInitObject | SWF_ACTION_INIT_OBJECT | actionInitObject | 1/1 | 9/9 |  | ✓ | ✓ |  |
| 0X44 | ActionTypeOf | SWF_ACTION_TYPEOF | actionTypeof | 1/1 | 2/2 |  | ✓ | ✓ |  |
| 0X45 | ActionTargetPath | SWF_ACTION_TARGET_PATH | actionTargetPath | 1/1 |  |  | ✓ | ✓ |  |
| 0X46 | ActionEnumerate | SWF_ACTION_ENUMERATE | actionEnumerate | 1/1 |  |  | ✓ | ✓ |  |
| 0X47 | ActionAdd2 | SWF_ACTION_ADD2 | actionAdd2 | 1/1 |  |  | ✓ | ✓ |  |
| 0X48 | ActionLess2 | SWF_ACTION_LESS2 | actionLess2 | 1/1 |  |  | ✓ | ✓ |  |
| 0X49 | ActionEquals2 | SWF_ACTION_EQUALS2 | actionEquals2 | 1/1 |  |  | ✓ | ✓ |  |
| 0X4A | ActionToNumber | SWF_ACTION_TO_NUMBER | actionToNumber | 1/1 |  |  | ✓ | ✓ |  |
| 0X4B | ActionToString | SWF_ACTION_TO_STRING | actionToString | 1/1 |  |  | ✓ | ✓ |  |
| 0X4C | ActionPushDuplicate | SWF_ACTION_DUPLICATE | actionDuplicate | 1/1 | 5/5 |  | ✓ | ✓ |  |
| 0X4D | ActionStackSwap | SWF_ACTION_STACK_SWAP | actionStackSwap | 1/1 | 2/2 |  | ✓ | ✓ |  |
| 0X4E | ActionGetMember | SWF_ACTION_GET_MEMBER | actionGetMember | 1/1 | 6/6 |  | ✓ | ✓ |  |
| 0X4F | ActionSetMember | SWF_ACTION_SET_MEMBER | actionSetMember | 1/1 | 2/2 |  | ✓ | ✓ |  |
| 0X50 | ActionIncrement | SWF_ACTION_INCREMENT | actionIncrement | 1/1 |  |  | ✓ | ✓ |  |
| 0X51 | ActionDecrement | SWF_ACTION_DECREMENT | actionDecrement | 1/1 |  |  | ✓ | ✓ |  |
| 0X52 | ActionCallMethod | SWF_ACTION_CALL_METHOD | actionCallMethod | 2/2 |  |  | ✓ | ✓ |  |
| 0X53 | ActionNewMethod | SWF_ACTION_NEW_METHOD | actionNewMethod | 1/1 |  |  | ✓ | ✓ | ✓ |
| 0X54 | ActionInstanceOf | SWF_ACTION_INSTANCEOF | actionInstanceOf | 1/1 |  |  | ✓ | ✓ |  |
| 0X55 | ActionEnumerate2 | SWF_ACTION_ENUMERATE2 | actionEnumerate2 | 1/1 |  |  | ✓ | ✓ |  |
| 0X60 | ActionBitAnd | SWF_ACTION_BIT_AND | actionBitAnd | 1/1 |  |  | ✓ | ✓ |  |
| 0X61 | ActionBitOr | SWF_ACTION_BIT_OR | actionBitOr | 1/1 |  |  | ✓ | ✓ |  |
| 0X62 | ActionBitXor | SWF_ACTION_BIT_XOR | actionBitXor | 1/1 |  |  | ✓ | ✓ |  |
| 0X63 | ActionBitLShift | SWF_ACTION_BIT_LSHIFT | actionBitLShift | 1/1 |  |  | ✓ | ✓ |  |
| 0X64 | ActionBitRShift | SWF_ACTION_BIT_RSHIFT | actionBitRShift | 1/1 |  |  | ✓ | ✓ |  |
| 0X65 | ActionBitURShift | SWF_ACTION_BIT_URSHIFT | actionBitURShift | 1/1 |  |  | ✓ | ✓ |  |
| 0X66 | ActionStrictEquals | SWF_ACTION_STRICT_EQUALS | actionStrictEquals | 1/1 | 1/1 |  | ✓ | ✓ |  |
| 0X67 | ActionGreater | SWF_ACTION_GREATER | actionGreater | 1/1 |  |  | ✓ | ✓ |  |
| 0X68 | ActionStringGreater | SWF_ACTION_STRING_GREATER | actionStringGreater | 1/1 |  |  | ✓ | ✓ |  |
| 0X69 | ActionExtends | SWF_ACTION_EXTENDS | actionExtends | 1/1 |  |  | ✓ | ✓ |  |
| 0X81 | ActionGotoFrame | SWF_ACTION_GOTO_FRAME | actionGotoFrame | 1/1 | 1/1 |  | ✓ |  | ✓ |
| 0X83 | ActionGetURL | SWF_ACTION_GET_URL | actionGetURL | 1/1 |  |  | ✓ |  | ✓ |
| 0X87 | ActionStoreRegister | SWF_ACTION_STORE_REGISTER | actionStoreRegister | 1/1 |  |  | ✓ | ✓ |  |
| 0X88 | ActionConstantPool | SWF_ACTION_CONSTANT_POOL |  | 4/4 |  |  | ✓ | ✓ |  |
| 0X8A | ActionWaitForFrame | SWF_ACTION_WAIT_FOR_FRAME |  | 1/1 |  |  | ✓ | ✓ |  |
| 0X8B | ActionSetTarget | SWF_ACTION_SET_TARGET | actionSetTarget | 1/1 |  |  | ✓ |  | ✓ |
| 0X8C | ActionGoToLabel | SWF_ACTION_GOTO_LABEL | actionGoToLabel | 1/1 |  |  | ✓ | ✓ |  |
| 0X8D | ActionWaitForFrame2 | SWF_ACTION_WAIT_FOR_FRAME2 |  | 1/1 |  |  | ✓ | ✓ |  |
| 0X8E | ActionDefineFunction2 | SWF_ACTION_DEFINE_FUNCTION2 | actionDefineFunction2 | 2/2 | 1/1 |  | ✓ | ✓ |  |
| 0X8F | ActionTry | SWF_ACTION_TRY |  | 1/1 |  |  | ✓ | ✓ |  |
| 0X94 | ActionWith | SWF_ACTION_WITH |  | 1/1 |  |  | ✓ | ✓ |  |
| 0X96 | ActionPush | SWF_ACTION_PUSH |  | 1/1 | 112/113 |  | ✓ | ✓ |  |
| 0X99 | ActionJump | SWF_ACTION_JUMP |  | 1/1 |  |  | ✓ | ✓ |  |
| 0X9A | ActionGetURL2 | SWF_ACTION_GET_URL2 | actionGetURL2 | 1/1 |  |  | ✓ |  | ✓ |
| 0X9B | ActionDefineFunction | SWF_ACTION_DEFINE_FUNCTION |  | 1/1 |  |  | ✓ | ✓ |  |
| 0X9D | ActionIf | SWF_ACTION_IF |  | 2/2 |  |  | ✓ | ✓ |  |
| 0X9E | ActionCall | SWF_ACTION_CALL | actionCall | 1/1 |  |  | ✓ |  | ✓ |
| 0X9F | ActionGotoFrame2 | SWF_ACTION_GOTO_FRAME2 | actionGotoFrame2 | 1/1 |  |  | ✓ |  | ✓ |

## Passing Primary Tests

**Total Passing Primary Tests**: 117

| Hex | Opcode | Test Path | Enum | Function | Docs |
|-----|--------|-----------|------|----------|------|
| 0X04 | ActionNextFrame | `next_frame_swf_4` | ✓ | ✓ | ✓ |
| 0X05 | ActionPreviousFrame | `prev_frame_swf_4` | ✓ | ✓ | ✓ |
| 0X06 | ActionPlay | `play_stop_swf_4` | ✓ | ✓ | ✓ |
| 0X06 | ActionPlay | `play_swf_4` | ✓ | ✓ | ✓ |
| 0X07 | ActionStop | `play_stop_swf_4` | ✓ |  | ✓ |
| 0X07 | ActionStop | `stop_multiframe_swf_4` | ✓ |  | ✓ |
| 0X07 | ActionStop | `stop_swf_4` | ✓ |  | ✓ |
| 0X08 | ActionToggleQuality | `toggle_quality_swf_4` | ✓ | ✓ | ✓ |
| 0X09 | ActionStopSounds | `stop_sounds_swf_4` | ✓ | ✓ | ✓ |
| 0X0A | ActionAdd | `add_swf_4` | ✓ | ✓ | ✓ |
| 0X0B | ActionSubtract | `subtract_swf_4` | ✓ | ✓ | ✓ |
| 0X0C | ActionMultiply | `multiply_floats_swf_4` | ✓ | ✓ | ✓ |
| 0X0D | ActionDivide | `divide_floats_error_swf_4` | ✓ | ✓ | ✓ |
| 0X0E | ActionEquals | `equals_swf_4` | ✓ | ✓ | ✓ |
| 0X0F | ActionLess | `less_floats_false_swf_4` | ✓ | ✓ | ✓ |
| 0X0F | ActionLess | `less_floats_swf_4` | ✓ | ✓ | ✓ |
| 0X10 | ActionAnd | `and_floats_both_0_swf_4` | ✓ | ✓ | ✓ |
| 0X10 | ActionAnd | `and_floats_first_1_swf_4` | ✓ | ✓ | ✓ |
| 0X10 | ActionAnd | `and_floats_nonzero_swf_4` | ✓ | ✓ | ✓ |
| 0X10 | ActionAnd | `and_floats_second_1_swf_4` | ✓ | ✓ | ✓ |
| 0X10 | ActionAnd | `and_floats_swf_4` | ✓ | ✓ | ✓ |
| 0X11 | ActionOr | `or_swf_4` | ✓ | ✓ | ✓ |
| 0X12 | ActionNot | `not_floats_nonzero_swf_4` | ✓ | ✓ | ✓ |
| 0X13 | ActionStringEquals | `string_equals_0_swf_4` | ✓ | ✓ | ✓ |
| 0X13 | ActionStringEquals | `string_equals_1_swf_4` | ✓ | ✓ | ✓ |
| 0X14 | ActionStringLength | `string_length_swf_4` | ✓ | ✓ | ✓ |
| 0X15 | ActionStringExtract | `string_extract_swf_4` | ✓ | ✓ | ✓ |
| 0X17 | ActionPop | `pop_swf_4` | ✓ |  | ✓ |
| 0X18 | ActionToInteger | `to_integer_swf_4` | ✓ | ✓ | ✓ |
| 0X1C | ActionGetVariable | `get_variable_swf_4` | ✓ | ✓ | ✓ |
| 0X1D | ActionSetVariable | `set_variable_swf_4` | ✓ | ✓ | ✓ |
| 0X20 | ActionSetTarget2 | `set_target2_swf_4` | ✓ | ✓ | ✓ |
| 0X21 | ActionStringAdd | `string_add_swf_4` | ✓ | ✓ | ✓ |
| 0X22 | ActionGetProperty | `get_property_swf_4` | ✓ | ✓ | ✓ |
| 0X23 | ActionSetProperty | `set_property_swf_4` | ✓ | ✓ | ✓ |
| 0X24 | ActionCloneSprite | `clone_sprite_swf_4` | ✓ | ✓ | ✓ |
| 0X25 | ActionRemoveSprite | `remove_sprite_swf_4` | ✓ | ✓ | ✓ |
| 0X26 | ActionTrace | `trace_swf_4` | ✓ | ✓ | ✓ |
| 0X27 | ActionStartDrag | `start_drag_swf_4` | ✓ | ✓ | ✓ |
| 0X28 | ActionEndDrag | `end_drag_swf_4` | ✓ | ✓ | ✓ |
| 0X29 | ActionStringLess | `string_less_swf_4` | ✓ | ✓ | ✓ |
| 0X2A | ActionThrow | `throw_swf_7` | ✓ | ✓ | ✓ |
| 0X2A | ActionThrow | `try_swf_7` | ✓ | ✓ | ✓ |
| 0X2B | ActionCastOp | `cast_op_swf_7` | ✓ | ✓ | ✓ |
| 0X2C | ActionImplementsOp | `implements_op_swf_7` | ✓ | ✓ | ✓ |
| 0X30 | ActionRandomNumber | `random_number_swf_4` | ✓ | ✓ | ✓ |
| 0X31 | ActionMBStringLength | `mb_string_length_swf_5` | ✓ | ✓ | ✓ |
| 0X32 | ActionCharToAscii | `char_to_ascii_swf_4` | ✓ | ✓ | ✓ |
| 0X33 | ActionAsciiToChar | `ascii_to_char_swf_4` | ✓ | ✓ | ✓ |
| 0X34 | ActionGetTime | `get_time_swf_5` | ✓ | ✓ | ✓ |
| 0X35 | ActionMBStringExtract | `mb_string_extract_swf_5` | ✓ | ✓ | ✓ |
| 0X36 | ActionMBCharToAscii | `mb_char_to_ascii_swf_5` | ✓ | ✓ | ✓ |
| 0X37 | ActionMBAsciiToChar | `mb_ascii_to_char_edge_cases_swf_4` | ✓ | ✓ | ✓ |
| 0X37 | ActionMBAsciiToChar | `mb_ascii_to_char_swf_4` | ✓ | ✓ | ✓ |
| 0X37 | ActionMBAsciiToChar | `mb_ascii_to_char_swf_5` | ✓ | ✓ | ✓ |
| 0X3A | ActionDelete | `delete_swf_5` | ✓ | ✓ | ✓ |
| 0X3B | ActionDelete2 | `delete2_swf_5` | ✓ | ✓ | ✓ |
| 0X3C | ActionDefineLocal | `definelocal_swf_5` | ✓ | ✓ | ✓ |
| 0X3D | ActionStackSwap | `call_function_swf_5` | ✓ | ✓ | ✓ |
| 0X3E | ActionReturn | `return_swf_4` | ✓ | ✓ | ✓ |
| 0X3F | ActionModulo | `modulo_swf_4` | ✓ | ✓ | ✓ |
| 0X40 | ActionNewObject | `new_object_swf_4` | ✓ | ✓ | ✓ |
| 0X41 | ActionDefineLocal2 | `declare_local_swf_5` | ✓ | ✓ | ✓ |
| 0X42 | ActionInitArray | `init_array_swf_4` | ✓ | ✓ | ✓ |
| 0X43 | ActionInitObject | `init_object_swf_4` | ✓ | ✓ | ✓ |
| 0X44 | ActionTypeOf | `typeof_swf_5` | ✓ | ✓ | ✓ |
| 0X45 | ActionTargetPath | `target_path_swf_5` | ✓ | ✓ | ✓ |
| 0X46 | ActionEnumerate | `enumerate_swf_4` | ✓ | ✓ | ✓ |
| 0X47 | ActionAdd2 | `add2_swf_5` | ✓ | ✓ | ✓ |
| 0X48 | ActionLess2 | `less2_swf_4` | ✓ | ✓ | ✓ |
| 0X49 | ActionEquals2 | `equals2_swf_5` | ✓ | ✓ | ✓ |
| 0X4A | ActionToNumber | `to_number_swf_4` | ✓ | ✓ | ✓ |
| 0X4B | ActionToString | `to_string_swf_4` | ✓ | ✓ | ✓ |
| 0X4C | ActionPushDuplicate | `duplicate_swf_4` | ✓ | ✓ | ✓ |
| 0X4D | ActionStackSwap | `stack_swap_swf_4` | ✓ | ✓ | ✓ |
| 0X4E | ActionGetMember | `get_member_swf_4` | ✓ | ✓ | ✓ |
| 0X4F | ActionSetMember | `set_member_swf_5` | ✓ | ✓ | ✓ |
| 0X50 | ActionIncrement | `increment_swf_4` | ✓ | ✓ | ✓ |
| 0X51 | ActionDecrement | `decrement_swf_4` | ✓ | ✓ | ✓ |
| 0X52 | ActionCallMethod | `call_method_empty_name_swf_5` | ✓ | ✓ | ✓ |
| 0X52 | ActionCallMethod | `call_method_swf_5` | ✓ | ✓ | ✓ |
| 0X53 | ActionNewMethod | `new_method_swf_5` | ✓ | ✓ | ✓ |
| 0X54 | ActionInstanceOf | `instanceof_swf_6` | ✓ | ✓ | ✓ |
| 0X55 | ActionEnumerate2 | `enumerate2_swf_6` | ✓ | ✓ | ✓ |
| 0X60 | ActionBitAnd | `bit_and_swf_4` | ✓ | ✓ | ✓ |
| 0X61 | ActionBitOr | `bit_or_swf_4` | ✓ | ✓ | ✓ |
| 0X62 | ActionBitXor | `bit_xor_swf_4` | ✓ | ✓ | ✓ |
| 0X63 | ActionBitLShift | `bit_lshift_swf_4` | ✓ | ✓ | ✓ |
| 0X64 | ActionBitRShift | `bit_rshift_swf_4` | ✓ | ✓ | ✓ |
| 0X65 | ActionBitURShift | `bit_urshift_swf_4` | ✓ | ✓ | ✓ |
| 0X66 | ActionStrictEquals | `strict_equals_swf_4` | ✓ | ✓ | ✓ |
| 0X67 | ActionGreater | `greater_swf_4` | ✓ | ✓ | ✓ |
| 0X68 | ActionStringGreater | `string_greater_swf_4` | ✓ | ✓ | ✓ |
| 0X69 | ActionExtends | `extends_swf_7` | ✓ | ✓ | ✓ |
| 0X81 | ActionGotoFrame | `goto_frame_swf_3` | ✓ | ✓ | ✓ |
| 0X83 | ActionGetURL | `get_url_swf_3` | ✓ | ✓ | ✓ |
| 0X87 | ActionStoreRegister | `store_register_swf_4` | ✓ | ✓ | ✓ |
| 0X88 | ActionConstantPool | `constant_pool_large_swf_5` | ✓ |  | ✓ |
| 0X88 | ActionConstantPool | `constant_pool_nonseq_swf_5` | ✓ |  | ✓ |
| 0X88 | ActionConstantPool | `constant_pool_repeated_swf_5` | ✓ |  | ✓ |
| 0X88 | ActionConstantPool | `constant_pool_swf_5` | ✓ |  | ✓ |
| 0X8A | ActionWaitForFrame | `wait_for_frame_swf_3` | ✓ |  | ✓ |
| 0X8B | ActionSetTarget | `set_target_swf_3` | ✓ | ✓ | ✓ |
| 0X8C | ActionGoToLabel | `goto_label_swf_3` | ✓ | ✓ | ✓ |
| 0X8D | ActionWaitForFrame2 | `wait_for_frame2_swf_4` | ✓ |  | ✓ |
| 0X8E | ActionDefineFunction2 | `call_method_empty_name_swf_5` | ✓ | ✓ | ✓ |
| 0X8E | ActionDefineFunction2 | `define_function2_swf_7` | ✓ | ✓ | ✓ |
| 0X8F | ActionTry | `try_swf_7` | ✓ |  | ✓ |
| 0X94 | ActionWith | `with_swf_5` | ✓ |  | ✓ |
| 0X96 | ActionPush | `push_swf_4` | ✓ |  | ✓ |
| 0X99 | ActionJump | `jump_swf_4` | ✓ |  | ✓ |
| 0X9A | ActionGetURL2 | `get_url2_swf_4` | ✓ | ✓ | ✓ |
| 0X9B | ActionDefineFunction | `define_function_swf_5` | ✓ |  | ✓ |
| 0X9D | ActionIf | `if_false_swf_4` | ✓ |  | ✓ |
| 0X9D | ActionIf | `if_swf_4` | ✓ |  | ✓ |
| 0X9E | ActionCall | `call_swf_4` | ✓ | ✓ | ✓ |
| 0X9F | ActionGotoFrame2 | `gotoframe2_swf_5` | ✓ | ✓ | ✓ |

## Failing Primary Tests

**Total Failing Primary Tests**: 1

| Hex | Opcode | Test Path | Enum | Function | Docs |
|-----|--------|-----------|------|----------|------|
| 0X0A | ActionAdd | `add_floats_swf_4` | ✓ | ✓ | ✓ |

## Implementation Status

### ✅ Fully Implemented
(Opcodes marked as fully_implemented in test_info.json)

| Hex | Spec Name | Enum | Function | Primary Tests | Failing Primary | Docs | No Graphics |
|-----|-----------|------|----------|---------------|-----------------|------|-------------|
| 0X04 | ActionNextFrame | ✓ | ✓ | 1/1 |  | ✓ | ✓ |
| 0X05 | ActionPreviousFrame | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X06 | ActionPlay | ✓ | ✓ | 2/2 |  | ✓ | ✓ |
| 0X07 | ActionStop | ✓ |  | 3/3 |  | ✓ |  |
| 0X0A | ActionAdd | ✓ | ✓ | 1/2 | 1 | ✓ |  |
| 0X0B | ActionSubtract | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X0C | ActionMultiply | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X0D | ActionDivide | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X0E | ActionEquals | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X0F | ActionLess | ✓ | ✓ | 2/2 |  | ✓ |  |
| 0X10 | ActionAnd | ✓ | ✓ | 5/5 |  | ✓ |  |
| 0X11 | ActionOr | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X12 | ActionNot | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X13 | ActionStringEquals | ✓ | ✓ | 2/2 |  | ✓ |  |
| 0X14 | ActionStringLength | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X15 | ActionStringExtract | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X17 | ActionPop | ✓ |  | 1/1 |  | ✓ |  |
| 0X18 | ActionToInteger | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X1C | ActionGetVariable | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X1D | ActionSetVariable | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X21 | ActionStringAdd | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X22 | ActionGetProperty | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X26 | ActionTrace | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X29 | ActionStringLess | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X2A | ActionThrow | ✓ | ✓ | 2/2 |  | ✓ |  |
| 0X2B | ActionCastOp | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X2C | ActionImplementsOp | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X30 | ActionRandomNumber | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X31 | ActionMBStringLength | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X32 | ActionCharToAscii | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X33 | ActionAsciiToChar | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X34 | ActionGetTime | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X35 | ActionMBStringExtract | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X36 | ActionMBCharToAscii | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X37 | ActionMBAsciiToChar | ✓ | ✓ | 3/3 |  | ✓ |  |
| 0X3A | ActionDelete | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X3B | ActionDelete2 | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X3C | ActionDefineLocal | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X3D | ActionStackSwap | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X3E | ActionReturn | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X3F | ActionModulo | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X40 | ActionNewObject | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X41 | ActionDefineLocal2 | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X42 | ActionInitArray | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X43 | ActionInitObject | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X44 | ActionTypeOf | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X45 | ActionTargetPath | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X46 | ActionEnumerate | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X47 | ActionAdd2 | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X48 | ActionLess2 | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X49 | ActionEquals2 | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X4A | ActionToNumber | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X4B | ActionToString | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X4C | ActionPushDuplicate | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X4D | ActionStackSwap | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X4E | ActionGetMember | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X4F | ActionSetMember | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X50 | ActionIncrement | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X51 | ActionDecrement | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X52 | ActionCallMethod | ✓ | ✓ | 2/2 |  | ✓ |  |
| 0X53 | ActionNewMethod | ✓ | ✓ | 1/1 |  | ✓ | ✓ |
| 0X54 | ActionInstanceOf | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X55 | ActionEnumerate2 | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X60 | ActionBitAnd | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X61 | ActionBitOr | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X62 | ActionBitXor | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X63 | ActionBitLShift | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X64 | ActionBitRShift | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X65 | ActionBitURShift | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X66 | ActionStrictEquals | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X67 | ActionGreater | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X68 | ActionStringGreater | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X69 | ActionExtends | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X87 | ActionStoreRegister | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X88 | ActionConstantPool | ✓ |  | 4/4 |  | ✓ |  |
| 0X8A | ActionWaitForFrame | ✓ |  | 1/1 |  | ✓ |  |
| 0X8C | ActionGoToLabel | ✓ | ✓ | 1/1 |  | ✓ |  |
| 0X8D | ActionWaitForFrame2 | ✓ |  | 1/1 |  | ✓ |  |
| 0X8E | ActionDefineFunction2 | ✓ | ✓ | 2/2 |  | ✓ |  |
| 0X8F | ActionTry | ✓ |  | 1/1 |  | ✓ |  |
| 0X94 | ActionWith | ✓ |  | 1/1 |  | ✓ |  |
| 0X96 | ActionPush | ✓ |  | 1/1 |  | ✓ |  |
| 0X99 | ActionJump | ✓ |  | 1/1 |  | ✓ |  |
| 0X9B | ActionDefineFunction | ✓ |  | 1/1 |  | ✓ |  |
| 0X9D | ActionIf | ✓ |  | 2/2 |  | ✓ |  |

### 🔄 Partially Implemented
(Has enum or function, but not marked as fully implemented)

| Hex | Spec Name | Enum | Function | Docs |
|-----|-----------|------|----------|------|
| 0X00 |  | ✓ |  |  |
| 0X08 | ActionToggleQuality | ✓ | ✓ | ✓ |
| 0X09 | ActionStopSounds | ✓ | ✓ | ✓ |
| 0X20 | ActionSetTarget2 | ✓ | ✓ | ✓ |
| 0X23 | ActionSetProperty | ✓ | ✓ | ✓ |
| 0X24 | ActionCloneSprite | ✓ | ✓ | ✓ |
| 0X25 | ActionRemoveSprite | ✓ | ✓ | ✓ |
| 0X27 | ActionStartDrag | ✓ | ✓ | ✓ |
| 0X28 | ActionEndDrag | ✓ | ✓ | ✓ |
| 0X81 | ActionGotoFrame | ✓ | ✓ | ✓ |
| 0X83 | ActionGetURL | ✓ | ✓ | ✓ |
| 0X8B | ActionSetTarget | ✓ | ✓ | ✓ |
| 0X9A | ActionGetURL2 | ✓ | ✓ | ✓ |
| 0X9E | ActionCall | ✓ | ✓ | ✓ |
| 0X9F | ActionGotoFrame2 | ✓ | ✓ | ✓ |

### ❌ Not Implemented
(Only in spec, no implementation yet)

| Hex | Spec Name |
|-----|-----------|

## Missing Features

This section lists all missing features for opcodes that are not fully implemented.

### 0X06: ActionPlay

**From test `play_swf_4`:**
- SetTarget support: Cannot control individual sprite/MovieClip timelines (requires MovieClip architecture not available in NO_GRAPHICS mode)


### 0X08: ActionToggleQuality

**From test `toggle_quality_swf_4`:**
- Graphics rendering not implemented (requires SDL3/Vulkan) - quality toggle has no visible effect in NO_GRAPHICS mode


### 0X20: ActionSetTarget2

**From test `set_target2_swf_4`:**
- Timeline control opcodes (Play, Stop, GotoFrame) don't use the current context
- Only root MovieClip is supported (no child sprites or nested clips)
- Target path resolution only supports empty string, _root, and / (all resolve to root)
- Non-existent targets are silently ignored (context unchanged)
- Advanced path syntax not supported: dot notation (sprite1.sprite2), relative paths (../sprite), special targets (_parent, this)


### 0X24: ActionCloneSprite

**From test `clone_sprite_swf_4`:**
- Graphics rendering not implemented (requires display list and MovieClip infrastructure)
- Actual sprite cloning only works with graphics support - NO_GRAPHICS mode validates parameters only


### 0X25: ActionRemoveSprite

**From test `remove_sprite_swf_4`:**
- Graphics mode: Display list management system not implemented
- Graphics mode: MovieClip reference counting not implemented
- Graphics mode: Actual sprite removal and resource cleanup requires SDL3/Vulkan rendering


### 0X28: ActionEndDrag

**From test `end_drag_swf_4`:**
- Graphics rendering: actual sprite/MovieClip drag visualization requires SDL3/Vulkan
- Mouse interaction: drag positioning based on mouse input requires graphics mode
- Display list integration: finding and updating sprites in the display list


### 0X2A: ActionThrow

**From test `throw_swf_7`:**
- Try-catch integration has known implementation flaw - setjmp/longjmp called from helper function instead of inline
- Stack unwinding to catch blocks doesn't work correctly (execution continues after longjmp)
- Finally block execution during unwinding not tested
- Nested try-catch blocks not tested
- Exception propagation through function calls not tested
- Only tested uncaught exceptions (requires ActionTry 0x8F for full testing)


### 0X81: ActionGotoFrame

**From test `goto_frame_swf_3`:**
- Display list updates on frame change (graphics-only feature, requires SDL3/Vulkan rendering)


### 0X83: ActionGetURL

**From test `get_url_swf_3`:**
- Actual URL loading (requires browser integration or HTTP client)
- SWF file loading into _level targets (requires SWF loader and level management)
- Browser frame/window management (requires browser API)
- JavaScript URL execution (requires JavaScript bridge)
- Cross-domain security policy enforcement
- URL scheme validation and sanitization


### 0X8B: ActionSetTarget

**From test `set_target_swf_3`:**
- MovieClip hierarchy (named sprites, nested clips) requires display list infrastructure available only in graphics mode
- In NO_GRAPHICS mode, only _root is available as a valid target - all other target names are treated as 'not found'


### 0X9A: ActionGetURL2

**From test `get_url2_swf_4`:**
- Actual HTTP client functionality (requires libcurl or similar HTTP library)
- Variable encoding to x-www-form-urlencoded format (requires variable enumeration)
- HTTP response parsing (requires HTTP client and response parser)
- Setting variables in target scope from response (requires full variable/scope management)
- SWF file downloading and loading (requires HTTP client and SWF parser/loader)
- MovieClip/sprite path resolution and management (requires full sprite hierarchy)
- Browser window integration (requires platform-specific OS APIs)
- Cross-domain security policy enforcement (requires security sandbox infrastructure)


### 0X9E: ActionCall

**From test `call_swf_4`:**
- Frame label registry (requires SWFRecomp to parse FrameLabel tag 43 and generate label->frame mapping - graphics-only)
- MovieClip tree for target paths (requires full MovieClip infrastructure - graphics-only)
- Multi-MovieClip support (requires MovieClip context switching - graphics-only)


### 0X9F: ActionGotoFrame2

**From test `gotoframe2_swf_5`:**
- Actual frame navigation (requires MovieClip timeline management - graphics-only)
- Frame label registry/lookup (requires SWF FrameLabel tag parsing - graphics-only)
- MovieClip context switching for target paths (requires full MovieClip tree - graphics-only)


## Detailed Information

### 0X00: Unknown

**Name Variations:**
- `SWF_ACTION_END_OF_ACTIONS` (enum, source: action.hpp)

**Implementation:**
- parseActions (case SWF_ACTION_END_OF_ACTIONS)

**Notes:**
- C++ enum value for opcode

---

### 0X04: ActionNextFrame

**Name Variations:**
- `ActionNextFrame` (spec, source: SWF Specification v19)
- `SWF_ACTION_NEXT_FRAME` (enum, source: action.hpp)
- `actionNextFrame` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/next_frame_swf_4`

**Function Declaration:**
```c
void actionNextFrame();
```

**Implementation:**
- parseActions (case SWF_ACTION_NEXT_FRAME)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-next-frame-0x04.md](SWFRecompDocs/prompts/completed/opcode-next-frame-0x04.md)

**Notes:**
- Official SWF specification name (spec line 4310)

---

### 0X05: ActionPreviousFrame

**Name Variations:**
- `ActionPreviousFrame` (spec, source: SWF Specification v19)
- `SWF_ACTION_PREV_FRAME` (enum, source: action.hpp)
- `actionPrevFrame` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/prev_frame_swf_4`

**Function Declaration:**
```c
void actionPrevFrame(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_PREV_FRAME)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-prev-frame-0x05.md](SWFRecompDocs/prompts/completed/opcode-prev-frame-0x05.md)

**Notes:**
- Official SWF specification name (spec line 4324)

---

### 0X06: ActionPlay

**Name Variations:**
- `ActionPlay` (spec, source: SWF Specification v19)
- `SWF_ACTION_PLAY` (enum, source: action.hpp)
- `actionPlay` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/play_stop_swf_4`
- [✓] `SWFRecomp/tests/play_swf_4`

**Function Declaration:**
```c
void actionPlay();
```

**Implementation:**
- parseActions (case SWF_ACTION_PLAY)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-play-0x06.md](SWFRecompDocs/prompts/completed/opcode-play-0x06.md)

**Notes:**
- Official SWF specification name (spec line 4338)

---

### 0X07: ActionStop

**Name Variations:**
- `ActionStop` (spec, source: SWF Specification v19)
- `SWF_ACTION_STOP` (enum, source: action.hpp)

**Primary Tests:**
- [✓] `SWFRecomp/tests/play_stop_swf_4`
- [✓] `SWFRecomp/tests/stop_multiframe_swf_4`
- [✓] `SWFRecomp/tests/stop_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/next_frame_swf_4`
- [✓] `SWFRecomp/tests/play_swf_4`
- [✓] `SWFRecomp/tests/prev_frame_swf_4`

**Implementation:**
- parseActions (case SWF_ACTION_STOP)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-stop-0x07.md](SWFRecompDocs/prompts/completed/opcode-stop-0x07.md)

**Notes:**
- Official SWF specification name (spec line 4354)

---

### 0X08: ActionToggleQuality

**Name Variations:**
- `ActionToggleQuality` (spec, source: SWF Specification v19)
- `SWF_ACTION_TOGGLE_QUALITY` (enum, source: action.hpp)
- `actionToggleQuality` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/toggle_quality_swf_4`

**Function Declaration:**
```c
void actionToggleQuality(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_TOGGLE_QUALITY)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-toggle-quality-0x08.md](SWFRecompDocs/prompts/completed/opcode-toggle-quality-0x08.md)

**Notes:**
- Official SWF specification name (spec line 4368)

---

### 0X09: ActionStopSounds

**Name Variations:**
- `ActionStopSounds` (spec, source: SWF Specification v19)
- `SWF_ACTION_STOP_SOUNDS` (enum, source: action.hpp)
- `actionStopSounds` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/stop_sounds_swf_4`

**Function Declaration:**
```c
void actionStopSounds(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_STOP_SOUNDS)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-stop-sounds-0x09.md](SWFRecompDocs/prompts/completed/opcode-stop-sounds-0x09.md)

**Notes:**
- Official SWF specification name (spec line 4379)

---

### 0X0A: ActionAdd

**Name Variations:**
- `ActionAdd` (spec, source: SWF Specification v19)
- `SWF_ACTION_ADD` (enum, source: action.hpp)
- `actionAdd` (function, source: action.h)

**Primary Tests:**
- [✗] `SWFRecomp/tests/add_floats_swf_4`
- [✓] `SWFRecomp/tests/add_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/define_function2_swf_7`
- [✓] `SWFRecomp/tests/duplicate_swf_4`
- [✓] `SWFRecomp/tests/set_variable_swf_4`
- [✓] `SWFRecomp/tests/stop_sounds_swf_4`

**Function Declaration:**
```c
void actionAdd(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_ADD)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-add-0x0a.md](SWFRecompDocs/prompts/completed/opcode-add-0x0a.md)

**Notes:**
- Official SWF specification name (spec line 4670)

---

### 0X0B: ActionSubtract

**Name Variations:**
- `ActionSubtract` (spec, source: SWF Specification v19)
- `SWF_ACTION_SUBTRACT` (enum, source: action.hpp)
- `actionSubtract` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/subtract_swf_4`

**Function Declaration:**
```c
void actionSubtract(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_SUBTRACT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-subtract-0x0b.md](SWFRecompDocs/prompts/completed/opcode-subtract-0x0b.md)

**Notes:**
- Official SWF specification name (spec line 4693)

---

### 0X0C: ActionMultiply

**Name Variations:**
- `ActionMultiply` (spec, source: SWF Specification v19)
- `SWF_ACTION_MULTIPLY` (enum, source: action.hpp)
- `actionMultiply` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/multiply_floats_swf_4`

**Function Declaration:**
```c
void actionMultiply(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_MULTIPLY)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-multiply-0x0c.md](SWFRecompDocs/prompts/completed/opcode-multiply-0x0c.md)

**Notes:**
- Official SWF specification name (spec line 4714)

---

### 0X0D: ActionDivide

**Name Variations:**
- `ActionDivide` (spec, source: SWF Specification v19)
- `SWF_ACTION_DIVIDE` (enum, source: action.hpp)
- `actionDivide` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/divide_floats_error_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/stack_swap_swf_4`

**Function Declaration:**
```c
void actionDivide(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_DIVIDE)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-divide-0x0d.md](SWFRecompDocs/prompts/completed/opcode-divide-0x0d.md)

**Notes:**
- Official SWF specification name (spec line 4737)

---

### 0X0E: ActionEquals

**Name Variations:**
- `ActionEquals` (spec, source: SWF Specification v19)
- `SWF_ACTION_EQUALS` (enum, source: action.hpp)
- `actionEquals` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/equals_swf_4`

**Function Declaration:**
```c
void actionEquals(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_EQUALS)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-equals-0x0e.md](SWFRecompDocs/prompts/completed/opcode-equals-0x0e.md)

**Notes:**
- Official SWF specification name (spec line 4761)

---

### 0X0F: ActionLess

**Name Variations:**
- `ActionLess` (spec, source: SWF Specification v19)
- `SWF_ACTION_LESS` (enum, source: action.hpp)
- `actionLess` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/less_floats_false_swf_4`
- [✓] `SWFRecomp/tests/less_floats_swf_4`

**Function Declaration:**
```c
void actionLess(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_LESS)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-less-0x0f.md](SWFRecompDocs/prompts/completed/opcode-less-0x0f.md)

**Notes:**
- Official SWF specification name (spec line 4786)

---

### 0X10: ActionAnd

**Name Variations:**
- `ActionAnd` (spec, source: SWF Specification v19)
- `SWF_ACTION_AND` (enum, source: action.hpp)
- `actionAnd` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/and_floats_both_0_swf_4`
- [✓] `SWFRecomp/tests/and_floats_first_1_swf_4`
- [✓] `SWFRecomp/tests/and_floats_nonzero_swf_4`
- [✓] `SWFRecomp/tests/and_floats_second_1_swf_4`
- [✓] `SWFRecomp/tests/and_floats_swf_4`

**Function Declaration:**
```c
void actionAnd(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_AND)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-and-0x10.md](SWFRecompDocs/prompts/completed/opcode-and-0x10.md)

**Notes:**
- Official SWF specification name (spec line 4808)

---

### 0X11: ActionOr

**Name Variations:**
- `ActionOr` (spec, source: SWF Specification v19)
- `SWF_ACTION_OR` (enum, source: action.hpp)
- `actionOr` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/or_swf_4`

**Function Declaration:**
```c
void actionOr(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_OR)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-or-0x11.md](SWFRecompDocs/prompts/completed/opcode-or-0x11.md)

**Notes:**
- Official SWF specification name (spec line 4829)

---

### 0X12: ActionNot

**Name Variations:**
- `ActionNot` (spec, source: SWF Specification v19)
- `SWF_ACTION_NOT` (enum, source: action.hpp)
- `actionNot` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/not_floats_nonzero_swf_4`

**Function Declaration:**
```c
void actionNot(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_NOT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-not-0x12.md](SWFRecompDocs/prompts/completed/opcode-not-0x12.md)

**Notes:**
- Official SWF specification name (spec line 4853)

---

### 0X13: ActionStringEquals

**Name Variations:**
- `ActionStringEquals` (spec, source: SWF Specification v19)
- `SWF_ACTION_STRING_EQUALS` (enum, source: action.hpp)
- `actionStringEquals` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/string_equals_0_swf_4`
- [✓] `SWFRecomp/tests/string_equals_1_swf_4`

**Function Declaration:**
```c
void actionStringEquals(char* stack, u32* sp, char* a_str, char* b_str);
```

**Implementation:**
- parseActions (case SWF_ACTION_STRING_EQUALS)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-string-equals-0x13.md](SWFRecompDocs/prompts/completed/opcode-string-equals-0x13.md)

**Notes:**
- Official SWF specification name (spec line 4882)

---

### 0X14: ActionStringLength

**Name Variations:**
- `ActionStringLength` (spec, source: SWF Specification v19)
- `SWF_ACTION_STRING_LENGTH` (enum, source: action.hpp)
- `actionStringLength` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/string_length_swf_4`

**Function Declaration:**
```c
void actionStringLength(char* stack, u32* sp, char* v_str);
```

**Implementation:**
- parseActions (case SWF_ACTION_STRING_LENGTH)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-string-length-0x14.md](SWFRecompDocs/prompts/completed/opcode-string-length-0x14.md)

**Notes:**
- Official SWF specification name (spec line 4903)

---

### 0X15: ActionStringExtract

**Name Variations:**
- `ActionStringExtract` (spec, source: SWF Specification v19)
- `SWF_ACTION_STRING_EXTRACT` (enum, source: action.hpp)
- `actionStringExtract` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/string_extract_swf_4`

**Function Declaration:**
```c
void actionStringExtract(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_STRING_EXTRACT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-string-extract-0x15.md](SWFRecompDocs/prompts/completed/opcode-string-extract-0x15.md)

**Notes:**
- Official SWF specification name (spec line 4942)

---

### 0X17: ActionPop

**Name Variations:**
- `ActionPop` (spec, source: SWF Specification v19)
- `SWF_ACTION_POP` (enum, source: action.hpp)

**Primary Tests:**
- [✓] `SWFRecomp/tests/pop_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/cast_op_swf_7`
- [✓] `SWFRecomp/tests/enumerate_swf_4`
- [✓] `SWFRecomp/tests/init_array_swf_4`
- [✓] `SWFRecomp/tests/new_method_swf_5`
- [✓] `SWFRecomp/tests/new_object_swf_4`

**Implementation:**
- parseActions (case SWF_ACTION_POP)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-pop-0x17.md](SWFRecompDocs/prompts/completed/opcode-pop-0x17.md)

**Notes:**
- Official SWF specification name (spec line 4651)

---

### 0X18: ActionToInteger

**Name Variations:**
- `ActionToInteger` (spec, source: SWF Specification v19)
- `SWF_ACTION_TO_INTEGER` (enum, source: action.hpp)
- `actionToInteger` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/to_integer_swf_4`

**Function Declaration:**
```c
void actionToInteger(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_TO_INTEGER)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-to-integer-0x18.md](SWFRecompDocs/prompts/completed/opcode-to-integer-0x18.md)

**Notes:**
- Official SWF specification name (spec line 5031)

---

### 0X1C: ActionGetVariable

**Name Variations:**
- `ActionGetVariable` (spec, source: SWF Specification v19)
- `SWF_ACTION_GET_VARIABLE` (enum, source: action.hpp)
- `actionGetVariable` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/get_variable_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/call_method_empty_name_swf_5`
- [✓] `SWFRecomp/tests/declare_local_swf_5`
- [✓] `SWFRecomp/tests/definelocal_swf_5`
- [✓] `SWFRecomp/tests/delete_swf_5`
- [✓] `SWFRecomp/tests/extends_swf_7`
- [✓] `SWFRecomp/tests/new_method_swf_5`
- [✓] `SWFRecomp/tests/set_member_swf_5`
- [✓] `SWFRecomp/tests/set_variable_swf_4`
- [✓] `SWFRecomp/tests/try_swf_7`
- [✓] `SWFRecomp/tests/with_swf_5`

**Function Declaration:**
```c
void actionGetVariable(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_GET_VARIABLE)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-get-variable-0x1c.md](SWFRecompDocs/prompts/completed/opcode-get-variable-0x1c.md)

**Notes:**
- Official SWF specification name (spec line 5218)

---

### 0X1D: ActionSetVariable

**Name Variations:**
- `ActionSetVariable` (spec, source: SWF Specification v19)
- `SWF_ACTION_SET_VARIABLE` (enum, source: action.hpp)
- `actionSetVariable` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/set_variable_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/call_method_empty_name_swf_5`
- [✓] `SWFRecomp/tests/delete_swf_5`
- [✓] `SWFRecomp/tests/enumerate_swf_4`
- [✓] `SWFRecomp/tests/extends_swf_7`
- [✓] `SWFRecomp/tests/get_variable_swf_4`
- [✓] `SWFRecomp/tests/init_object_swf_4`
- [✓] `SWFRecomp/tests/new_method_swf_5`
- [✓] `SWFRecomp/tests/set_member_swf_5`
- [✓] `SWFRecomp/tests/with_swf_5`

**Function Declaration:**
```c
void actionSetVariable(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_SET_VARIABLE)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-set-variable-0x1d.md](SWFRecompDocs/prompts/completed/opcode-set-variable-0x1d.md)

**Notes:**
- Official SWF specification name (spec line 5240)

---

### 0X20: ActionSetTarget2

**Name Variations:**
- `ActionSetTarget2` (spec, source: SWF Specification v19)
- `SWF_ACTION_SET_TARGET2` (enum, source: action.hpp)
- `actionSetTarget2` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/set_target2_swf_4`

**Function Declaration:**
```c
void actionSetTarget2(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_SET_TARGET2)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-settarget2-0x20.md](SWFRecompDocs/prompts/completed/opcode-settarget2-0x20.md)

**Notes:**
- Official SWF specification name (spec line 5405)

---

### 0X21: ActionStringAdd

**Name Variations:**
- `ActionStringAdd` (spec, source: SWF Specification v19)
- `SWF_ACTION_STRING_ADD` (enum, source: action.hpp)
- `actionStringAdd` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/string_add_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/get_url2_swf_4`
- [✓] `SWFRecomp/tests/mb_ascii_to_char_edge_cases_swf_4`
- [✓] `SWFRecomp/tests/try_swf_7`

**Function Declaration:**
```c
void actionStringAdd(char* stack, u32* sp, char* a_str, char* b_str);
```

**Implementation:**
- parseActions (case SWF_ACTION_STRING_ADD)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-string-add-0x21.md](SWFRecompDocs/prompts/completed/opcode-string-add-0x21.md)

**Notes:**
- Official SWF specification name (spec line 4921)

---

### 0X22: ActionGetProperty

**Name Variations:**
- `ActionGetProperty` (spec, source: SWF Specification v19)
- `SWF_ACTION_GET_PROPERTY` (enum, source: action.hpp)
- `actionGetProperty` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/get_property_swf_4`

**Function Declaration:**
```c
void actionGetProperty(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_GET_PROPERTY)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-get-property-0x22.md](SWFRecompDocs/prompts/completed/opcode-get-property-0x22.md)

**Notes:**
- Official SWF specification name (spec line 5423)

---

### 0X23: ActionSetProperty

**Name Variations:**
- `ActionSetProperty` (spec, source: SWF Specification v19)
- `SWF_ACTION_SET_PROPERTY` (enum, source: action.hpp)
- `actionSetProperty` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/set_property_swf_4`

**Function Declaration:**
```c
void actionSetProperty(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_SET_PROPERTY)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-set-property-0x23.md](SWFRecompDocs/prompts/completed/opcode-set-property-0x23.md)

**Notes:**
- Official SWF specification name (spec line 5541)

---

### 0X24: ActionCloneSprite

**Name Variations:**
- `ActionCloneSprite` (spec, source: SWF Specification v19)
- `SWF_ACTION_CLONE_SPRITE` (enum, source: action.hpp)
- `actionCloneSprite` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/clone_sprite_swf_4`

**Function Declaration:**
```c
void actionCloneSprite(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_CLONE_SPRITE)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-clone-sprite-0x24.md](SWFRecompDocs/prompts/completed/opcode-clone-sprite-0x24.md)

**Notes:**
- Official SWF specification name (spec line 5561)

---

### 0X25: ActionRemoveSprite

**Name Variations:**
- `ActionRemoveSprite` (spec, source: SWF Specification v19)
- `SWF_ACTION_REMOVE_SPRITE` (enum, source: action.hpp)
- `actionRemoveSprite` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/remove_sprite_swf_4`

**Function Declaration:**
```c
void actionRemoveSprite(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_REMOVE_SPRITE)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-remove-sprite-0x25.md](SWFRecompDocs/prompts/completed/opcode-remove-sprite-0x25.md)

**Notes:**
- Official SWF specification name (spec line 5583)

---

### 0X26: ActionTrace

**Name Variations:**
- `ActionTrace` (spec, source: SWF Specification v19)
- `SWF_ACTION_TRACE` (enum, source: action.hpp)
- `actionTrace` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/trace_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/add2_swf_5`
- [✗] `SWFRecomp/tests/add_floats_swf_4`
- [✓] `SWFRecomp/tests/add_swf_4`
- [✓] `SWFRecomp/tests/and_floats_both_0_swf_4`
- [✓] `SWFRecomp/tests/and_floats_first_1_swf_4`
- [✓] `SWFRecomp/tests/and_floats_nonzero_swf_4`
- [✓] `SWFRecomp/tests/and_floats_second_1_swf_4`
- [✓] `SWFRecomp/tests/and_floats_swf_4`
- [✓] `SWFRecomp/tests/ascii_to_char_swf_4`
- [✓] `SWFRecomp/tests/bit_and_swf_4`
- [✓] `SWFRecomp/tests/bit_lshift_swf_4`
- [✓] `SWFRecomp/tests/bit_or_swf_4`
- [✓] `SWFRecomp/tests/bit_rshift_swf_4`
- [✓] `SWFRecomp/tests/bit_urshift_swf_4`
- [✓] `SWFRecomp/tests/bit_xor_swf_4`
- [✓] `SWFRecomp/tests/call_function_swf_5`
- [✓] `SWFRecomp/tests/call_method_empty_name_swf_5`
- [✓] `SWFRecomp/tests/call_method_swf_5`
- [✓] `SWFRecomp/tests/call_swf_4`
- [✓] `SWFRecomp/tests/cast_op_swf_7`
- [✓] `SWFRecomp/tests/char_to_ascii_swf_4`
- [✓] `SWFRecomp/tests/clone_sprite_swf_4`
- [✓] `SWFRecomp/tests/constant_pool_large_swf_5`
- [✓] `SWFRecomp/tests/constant_pool_nonseq_swf_5`
- [✓] `SWFRecomp/tests/constant_pool_repeated_swf_5`
- [✓] `SWFRecomp/tests/constant_pool_swf_5`
- [✓] `SWFRecomp/tests/declare_local_swf_5`
- [✓] `SWFRecomp/tests/decrement_swf_4`
- [✓] `SWFRecomp/tests/define_function_swf_5`
- [✓] `SWFRecomp/tests/definelocal_swf_5`
- [✓] `SWFRecomp/tests/delete2_swf_5`
- [✓] `SWFRecomp/tests/delete_swf_5`
- [✓] `SWFRecomp/tests/divide_floats_error_swf_4`
- [✓] `SWFRecomp/tests/duplicate_swf_4`
- [✓] `SWFRecomp/tests/end_drag_swf_4`
- [✓] `SWFRecomp/tests/enumerate2_swf_6`
- [✓] `SWFRecomp/tests/enumerate_swf_4`
- [✓] `SWFRecomp/tests/equals2_swf_5`
- [✓] `SWFRecomp/tests/equals_swf_4`
- [✓] `SWFRecomp/tests/extends_swf_7`
- [✓] `SWFRecomp/tests/get_member_swf_4`
- [✓] `SWFRecomp/tests/get_property_swf_4`
- [✓] `SWFRecomp/tests/get_time_swf_5`
- [✓] `SWFRecomp/tests/get_url2_swf_4`
- [✓] `SWFRecomp/tests/get_url_swf_3`
- [✓] `SWFRecomp/tests/get_variable_swf_4`
- [✓] `SWFRecomp/tests/goto_frame_swf_3`
- [✓] `SWFRecomp/tests/goto_label_swf_3`
- [✓] `SWFRecomp/tests/gotoframe2_swf_5`
- [✓] `SWFRecomp/tests/greater_swf_4`
- [✓] `SWFRecomp/tests/if_false_swf_4`
- [✓] `SWFRecomp/tests/if_swf_4`
- [✓] `SWFRecomp/tests/implements_op_swf_7`
- [✓] `SWFRecomp/tests/increment_swf_4`
- [✓] `SWFRecomp/tests/init_array_swf_4`
- [✓] `SWFRecomp/tests/init_object_swf_4`
- [✓] `SWFRecomp/tests/instanceof_swf_6`
- [✓] `SWFRecomp/tests/jump_swf_4`
- [✓] `SWFRecomp/tests/less2_swf_4`
- [✓] `SWFRecomp/tests/less_floats_false_swf_4`
- [✓] `SWFRecomp/tests/less_floats_swf_4`
- [✓] `SWFRecomp/tests/mb_ascii_to_char_edge_cases_swf_4`
- [✓] `SWFRecomp/tests/mb_ascii_to_char_swf_4`
- [✓] `SWFRecomp/tests/mb_ascii_to_char_swf_5`
- [✓] `SWFRecomp/tests/mb_char_to_ascii_swf_5`
- [✓] `SWFRecomp/tests/mb_string_extract_swf_5`
- [✓] `SWFRecomp/tests/mb_string_length_swf_5`
- [✓] `SWFRecomp/tests/modulo_swf_4`
- [✓] `SWFRecomp/tests/multiply_floats_swf_4`
- [✓] `SWFRecomp/tests/new_method_swf_5`
- [✓] `SWFRecomp/tests/new_object_swf_4`
- [✓] `SWFRecomp/tests/next_frame_swf_4`
- [✓] `SWFRecomp/tests/not_floats_nonzero_swf_4`
- [✓] `SWFRecomp/tests/or_swf_4`
- [✓] `SWFRecomp/tests/play_stop_swf_4`
- [✓] `SWFRecomp/tests/play_swf_4`
- [✓] `SWFRecomp/tests/pop_swf_4`
- [✓] `SWFRecomp/tests/prev_frame_swf_4`
- [✓] `SWFRecomp/tests/push_swf_4`
- [✓] `SWFRecomp/tests/random_number_swf_4`
- [✓] `SWFRecomp/tests/remove_sprite_swf_4`
- [✓] `SWFRecomp/tests/return_swf_4`
- [✓] `SWFRecomp/tests/set_member_swf_5`
- [✓] `SWFRecomp/tests/set_property_swf_4`
- [✓] `SWFRecomp/tests/set_target2_swf_4`
- [✓] `SWFRecomp/tests/set_variable_swf_4`
- [✓] `SWFRecomp/tests/stack_swap_swf_4`
- [✓] `SWFRecomp/tests/start_drag_swf_4`
- [✓] `SWFRecomp/tests/stop_multiframe_swf_4`
- [✓] `SWFRecomp/tests/stop_sounds_swf_4`
- [✓] `SWFRecomp/tests/stop_swf_4`
- [✓] `SWFRecomp/tests/strict_equals_swf_4`
- [✓] `SWFRecomp/tests/string_add_swf_4`
- [✓] `SWFRecomp/tests/string_equals_0_swf_4`
- [✓] `SWFRecomp/tests/string_equals_1_swf_4`
- [✓] `SWFRecomp/tests/string_extract_swf_4`
- [✓] `SWFRecomp/tests/string_greater_swf_4`
- [✓] `SWFRecomp/tests/string_length_swf_4`
- [✓] `SWFRecomp/tests/string_less_swf_4`
- [✓] `SWFRecomp/tests/subtract_swf_4`
- [✓] `SWFRecomp/tests/target_path_swf_5`
- [✓] `SWFRecomp/tests/throw_swf_7`
- [✓] `SWFRecomp/tests/to_integer_swf_4`
- [✓] `SWFRecomp/tests/to_number_swf_4`
- [✓] `SWFRecomp/tests/to_string_swf_4`
- [✓] `SWFRecomp/tests/toggle_quality_swf_4`
- [✓] `SWFRecomp/tests/try_swf_7`
- [✓] `SWFRecomp/tests/typeof_swf_5`
- [✓] `SWFRecomp/tests/wait_for_frame2_swf_4`
- [✓] `SWFRecomp/tests/wait_for_frame_swf_3`
- [✓] `SWFRecomp/tests/with_swf_5`

**Function Declaration:**
```c
void actionTrace(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_TRACE)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-trace-0x26.md](SWFRecompDocs/prompts/completed/opcode-trace-0x26.md)

**Notes:**
- Official SWF specification name (spec line 5682)

---

### 0X27: ActionStartDrag

**Name Variations:**
- `ActionStartDrag` (spec, source: SWF Specification v19)
- `SWF_ACTION_START_DRAG` (enum, source: action.hpp)
- `actionStartDrag` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/start_drag_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/end_drag_swf_4`

**Function Declaration:**
```c
void actionStartDrag(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_START_DRAG)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-start-drag-0x27.md](SWFRecompDocs/prompts/completed/opcode-start-drag-0x27.md)

**Notes:**
- Official SWF specification name (spec line 5601)

---

### 0X28: ActionEndDrag

**Name Variations:**
- `ActionEndDrag` (spec, source: SWF Specification v19)
- `SWF_ACTION_END_DRAG` (enum, source: action.hpp)
- `actionEndDrag` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/end_drag_swf_4`

**Function Declaration:**
```c
void actionEndDrag(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_END_DRAG)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-end-drag-0x28.md](SWFRecompDocs/prompts/completed/opcode-end-drag-0x28.md)

**Notes:**
- Official SWF specification name (spec line 5641)

---

### 0X29: ActionStringLess

**Name Variations:**
- `ActionStringLess` (spec, source: SWF Specification v19)
- `SWF_ACTION_STRING_LESS` (enum, source: action.hpp)
- `actionStringLess` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/string_less_swf_4`

**Function Declaration:**
```c
void actionStringLess(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_STRING_LESS)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-string-less-0x29.md](SWFRecompDocs/prompts/completed/opcode-string-less-0x29.md)

**Notes:**
- Official SWF specification name (spec line 4964)

---

### 0X2A: ActionThrow

**Name Variations:**
- `ActionThrow` (spec, source: SWF Specification v19)
- `SWF_ACTION_THROW` (enum, source: action.hpp)
- `actionThrow` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/throw_swf_7`
- [✓] `SWFRecomp/tests/try_swf_7`

**Function Declaration:**
```c
void actionThrow(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_THROW)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-throw-0x2a.md](SWFRecompDocs/prompts/completed/opcode-throw-0x2a.md)

**Notes:**
- Official SWF specification name (spec line 7289)

---

### 0X2B: ActionCastOp

**Name Variations:**
- `ActionCastOp` (spec, source: SWF Specification v19)
- `SWF_ACTION_CAST_OP` (enum, source: action.hpp)
- `actionCastOp` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/cast_op_swf_7`

**Function Declaration:**
```c
void actionCastOp(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_CAST_OP)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-cast-op-0x2b.md](SWFRecompDocs/prompts/completed/opcode-cast-op-0x2b.md)

**Notes:**
- Official SWF specification name (spec line 7141)

---

### 0X2C: ActionImplementsOp

**Name Variations:**
- `ActionImplementsOp` (spec, source: SWF Specification v19)
- `SWF_ACTION_IMPLEMENTS_OP` (enum, source: action.hpp)
- `actionImplementsOp` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/implements_op_swf_7`

**Function Declaration:**
```c
void actionImplementsOp(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_IMPLEMENTS_OP)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-implements-op-0x2c.md](SWFRecompDocs/prompts/completed/opcode-implements-op-0x2c.md)

**Notes:**
- Official SWF specification name (spec line 7164)

---

### 0X30: ActionRandomNumber

**Name Variations:**
- `ActionRandomNumber` (spec, source: SWF Specification v19)
- `SWF_ACTION_RANDOM_NUMBER` (enum, source: action.hpp)
- `actionRandomNumber` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/random_number_swf_4`

**Function Declaration:**
```c
void actionRandomNumber(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_RANDOM_NUMBER)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-random-number-0x30.md](SWFRecompDocs/prompts/completed/opcode-random-number-0x30.md)

**Notes:**
- Official SWF specification name (spec line 5721)

---

### 0X31: ActionMBStringLength

**Name Variations:**
- `ActionMBStringLength` (spec, source: SWF Specification v19)
- `SWF_ACTION_MB_STRING_LENGTH` (enum, source: action.hpp)
- `actionMbStringLength` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/mb_string_length_swf_5`

**Function Declaration:**
```c
void actionMbStringLength(char* stack, u32* sp, char* v_str);
```

**Implementation:**
- parseActions (case SWF_ACTION_MB_STRING_LENGTH)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-mb-string-length-0x31.md](SWFRecompDocs/prompts/completed/opcode-mb-string-length-0x31.md)

**Notes:**
- Official SWF specification name (spec line 4986)

---

### 0X32: ActionCharToAscii

**Name Variations:**
- `ActionCharToAscii` (spec, source: SWF Specification v19)
- `SWF_ACTION_CHAR_TO_ASCII` (enum, source: action.hpp)
- `actionCharToAscii` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/char_to_ascii_swf_4`

**Function Declaration:**
```c
void actionCharToAscii(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_CHAR_TO_ASCII)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-ascii-to-char-0x32.md](SWFRecompDocs/prompts/completed/opcode-ascii-to-char-0x32.md)

**Notes:**
- Official SWF specification name (spec line 5053)

---

### 0X33: ActionAsciiToChar

**Name Variations:**
- `ActionAsciiToChar` (spec, source: SWF Specification v19)
- `SWF_ACTION_ASCII_TO_CHAR` (enum, source: action.hpp)
- `actionAsciiToChar` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/ascii_to_char_swf_4`

**Function Declaration:**
```c
void actionAsciiToChar(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_ASCII_TO_CHAR)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-mb-char-to-ascii-0x33.md](SWFRecompDocs/prompts/completed/opcode-mb-char-to-ascii-0x33.md)

**Notes:**
- Official SWF specification name (spec line 5072)

---

### 0X34: ActionGetTime

**Name Variations:**
- `ActionGetTime` (spec, source: SWF Specification v19)
- `SWF_ACTION_GET_TIME` (enum, source: action.hpp)
- `actionGetTime` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/get_time_swf_5`

**Function Declaration:**
```c
void actionGetTime(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_GET_TIME)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-get-time-0x34.md](SWFRecompDocs/prompts/completed/opcode-get-time-0x34.md)

**Notes:**
- Official SWF specification name (spec line 5703)

---

### 0X35: ActionMBStringExtract

**Name Variations:**
- `ActionMBStringExtract` (spec, source: SWF Specification v19)
- `SWF_ACTION_MB_STRING_EXTRACT` (enum, source: action.hpp)
- `actionMbStringExtract` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/mb_string_extract_swf_5`

**Function Declaration:**
```c
void actionMbStringExtract(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_MB_STRING_EXTRACT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-mb-string-extract-0x35.md](SWFRecompDocs/prompts/completed/opcode-mb-string-extract-0x35.md)

**Notes:**
- Official SWF specification name (spec line 5006)

---

### 0X36: ActionMBCharToAscii

**Name Variations:**
- `ActionMBCharToAscii` (spec, source: SWF Specification v19)
- `SWF_ACTION_MB_CHAR_TO_ASCII` (enum, source: action.hpp)
- `actionMbCharToAscii` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/mb_char_to_ascii_swf_5`

**Function Declaration:**
```c
void actionMbCharToAscii(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_MB_CHAR_TO_ASCII)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-mb-char-to-ascii-0x36.md](SWFRecompDocs/prompts/completed/opcode-mb-char-to-ascii-0x36.md)

**Notes:**
- Official SWF specification name (spec line 5094)

---

### 0X37: ActionMBAsciiToChar

**Name Variations:**
- `ActionMBAsciiToChar` (spec, source: SWF Specification v19)
- `SWF_ACTION_MB_ASCII_TO_CHAR` (enum, source: action.hpp)
- `actionMbAsciiToChar` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/mb_ascii_to_char_edge_cases_swf_4`
- [✓] `SWFRecomp/tests/mb_ascii_to_char_swf_4`
- [✓] `SWFRecomp/tests/mb_ascii_to_char_swf_5`

**Function Declaration:**
```c
void actionMbAsciiToChar(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_MB_ASCII_TO_CHAR)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-mbasciitochar-0x37.md](SWFRecompDocs/prompts/completed/opcode-mbasciitochar-0x37.md)

**Notes:**
- Official SWF specification name (spec line 5115)

---

### 0X3A: ActionDelete

**Name Variations:**
- `ActionDelete` (spec, source: SWF Specification v19)
- `SWF_ACTION_DELETE` (enum, source: action.hpp)
- `actionDelete` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/delete_swf_5`

**Function Declaration:**
```c
void actionDelete(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_DELETE)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-delete-0x3a.md](SWFRecompDocs/prompts/completed/opcode-delete-0x3a.md)

**Notes:**
- Official SWF specification name (spec line 6007)

---

### 0X3B: ActionDelete2

**Name Variations:**
- `ActionDelete2` (spec, source: SWF Specification v19)
- `SWF_ACTION_DELETE2` (enum, source: action.hpp)
- `actionDelete2` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/delete2_swf_5`

**Function Declaration:**
```c
void actionDelete2(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_DELETE2)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-delete2-0x3b.md](SWFRecompDocs/prompts/completed/opcode-delete2-0x3b.md)

**Notes:**
- Official SWF specification name (spec line 6025)

---

### 0X3C: ActionDefineLocal

**Name Variations:**
- `ActionDefineLocal` (spec, source: SWF Specification v19)
- `SWF_ACTION_DEFINE_LOCAL` (enum, source: action.hpp)
- `actionDefineLocal` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/definelocal_swf_5`

**Function Declaration:**
```c
void actionDefineLocal(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_DEFINE_LOCAL)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-definelocal-0x3c.md](SWFRecompDocs/prompts/completed/opcode-definelocal-0x3c.md)

**Notes:**
- Official SWF specification name (spec line 5969)

---

### 0X3D: ActionStackSwap

**Name Variations:**
- `ActionStackSwap` (spec, source: SWF Specification v19)
- `SWF_ACTION_CALL_FUNCTION` (enum, source: action.hpp)
- `actionStackSwap` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/call_function_swf_5`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/declare_local_swf_5`
- [✓] `SWFRecomp/tests/define_function2_swf_7`

**Function Declaration:**
```c
void actionStackSwap(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_CALL_FUNCTION)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-duplicate-0x3d.md](SWFRecompDocs/prompts/completed/opcode-duplicate-0x3d.md)

**Notes:**
- Official SWF specification name (spec line 5796)

---

### 0X3E: ActionReturn

**Name Variations:**
- `ActionReturn` (spec, source: SWF Specification v19)
- `SWF_ACTION_RETURN` (enum, source: action.hpp)
- `actionReturn` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/return_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/call_method_empty_name_swf_5`
- [✓] `SWFRecomp/tests/define_function2_swf_7`
- [✓] `SWFRecomp/tests/define_function_swf_5`

**Function Declaration:**
```c
void actionReturn(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_RETURN)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-return-0x3e.md](SWFRecompDocs/prompts/completed/opcode-return-0x3e.md)

**Notes:**
- Official SWF specification name (spec line 6643)

---

### 0X3F: ActionModulo

**Name Variations:**
- `ActionModulo` (spec, source: SWF Specification v19)
- `SWF_ACTION_MODULO` (enum, source: action.hpp)
- `actionModulo` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/modulo_swf_4`

**Function Declaration:**
```c
void actionModulo(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_MODULO)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-modulo-0x3f.md](SWFRecompDocs/prompts/completed/opcode-modulo-0x3f.md)

**Notes:**
- Official SWF specification name (spec line 6438)

---

### 0X40: ActionNewObject

**Name Variations:**
- `ActionNewObject` (spec, source: SWF Specification v19)
- `SWF_ACTION_NEW_OBJECT` (enum, source: action.hpp)
- `actionNewObject` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/new_object_swf_4`

**Function Declaration:**
```c
void actionNewObject(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_NEW_OBJECT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-new-object-0x40.md](SWFRecompDocs/prompts/completed/opcode-new-object-0x40.md)

**Notes:**
- Official SWF specification name (spec line 6216)

---

### 0X41: ActionDefineLocal2

**Name Variations:**
- `ActionDefineLocal2` (spec, source: SWF Specification v19)
- `SWF_ACTION_DECLARE_LOCAL` (enum, source: action.hpp)
- `actionDeclareLocal` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/declare_local_swf_5`

**Function Declaration:**
```c
void actionDeclareLocal(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_DECLARE_LOCAL)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-declare-local-0x41.md](SWFRecompDocs/prompts/completed/opcode-declare-local-0x41.md)

**Notes:**
- Official SWF specification name (spec line 5990)

---

### 0X42: ActionInitArray

**Name Variations:**
- `ActionInitArray` (spec, source: SWF Specification v19)
- `SWF_ACTION_INIT_ARRAY` (enum, source: action.hpp)
- `actionInitArray` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/init_array_swf_4`

**Function Declaration:**
```c
void actionInitArray(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_INIT_ARRAY)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-init-array-0x42.md](SWFRecompDocs/prompts/completed/opcode-init-array-0x42.md)

**Notes:**
- Official SWF specification name (spec line 6124)

---

### 0X43: ActionInitObject

**Name Variations:**
- `ActionInitObject` (spec, source: SWF Specification v19)
- `SWF_ACTION_INIT_OBJECT` (enum, source: action.hpp)
- `actionInitObject` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/init_object_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/cast_op_swf_7`
- [✓] `SWFRecomp/tests/delete_swf_5`
- [✓] `SWFRecomp/tests/enumerate2_swf_6`
- [✓] `SWFRecomp/tests/enumerate_swf_4`
- [✓] `SWFRecomp/tests/extends_swf_7`
- [✓] `SWFRecomp/tests/implements_op_swf_7`
- [✓] `SWFRecomp/tests/new_method_swf_5`
- [✓] `SWFRecomp/tests/set_member_swf_5`
- [✓] `SWFRecomp/tests/with_swf_5`

**Function Declaration:**
```c
void actionInitObject(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_INIT_OBJECT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-init-object-0x43.md](SWFRecompDocs/prompts/completed/opcode-init-object-0x43.md)

**Notes:**
- Official SWF specification name (spec line 6153)

---

### 0X44: ActionTypeOf

**Name Variations:**
- `ActionTypeOf` (spec, source: SWF Specification v19)
- `SWF_ACTION_TYPEOF` (enum, source: action.hpp)
- `actionTypeof` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/typeof_swf_5`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/extends_swf_7`
- [✓] `SWFRecomp/tests/init_object_swf_4`

**Function Declaration:**
```c
void actionTypeof(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_TYPEOF)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-typeof-0x44.md](SWFRecompDocs/prompts/completed/opcode-typeof-0x44.md)

**Notes:**
- Official SWF specification name (spec line 6380)

---

### 0X45: ActionTargetPath

**Name Variations:**
- `ActionTargetPath` (spec, source: SWF Specification v19)
- `SWF_ACTION_TARGET_PATH` (enum, source: action.hpp)
- `actionTargetPath` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/target_path_swf_5`

**Function Declaration:**
```c
void actionTargetPath(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_TARGET_PATH)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-target-path-0x45.md](SWFRecompDocs/prompts/completed/opcode-target-path-0x45.md)

**Notes:**
- Official SWF specification name (spec line 6268)

---

### 0X46: ActionEnumerate

**Name Variations:**
- `ActionEnumerate` (spec, source: SWF Specification v19)
- `SWF_ACTION_ENUMERATE` (enum, source: action.hpp)
- `actionEnumerate` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/enumerate_swf_4`

**Function Declaration:**
```c
void actionEnumerate(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_ENUMERATE)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-enumerate-0x46.md](SWFRecompDocs/prompts/completed/opcode-enumerate-0x46.md)

**Notes:**
- Official SWF specification name (spec line 6044)

---

### 0X47: ActionAdd2

**Name Variations:**
- `ActionAdd2` (spec, source: SWF Specification v19)
- `SWF_ACTION_ADD2` (enum, source: action.hpp)
- `actionAdd2` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/add2_swf_5`

**Function Declaration:**
```c
void actionAdd2(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_ADD2)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-add2-0x47.md](SWFRecompDocs/prompts/completed/opcode-add2-0x47.md)

**Notes:**
- Official SWF specification name (spec line 6393)

---

### 0X48: ActionLess2

**Name Variations:**
- `ActionLess2` (spec, source: SWF Specification v19)
- `SWF_ACTION_LESS2` (enum, source: action.hpp)
- `actionLess2` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/less2_swf_4`

**Function Declaration:**
```c
void actionLess2(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_LESS2)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-less2-0x48.md](SWFRecompDocs/prompts/completed/opcode-less2-0x48.md)

**Notes:**
- Official SWF specification name (spec line 6414)

---

### 0X49: ActionEquals2

**Name Variations:**
- `ActionEquals2` (spec, source: SWF Specification v19)
- `SWF_ACTION_EQUALS2` (enum, source: action.hpp)
- `actionEquals2` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/equals2_swf_5`

**Function Declaration:**
```c
void actionEquals2(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_EQUALS2)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-equals2-0x49.md](SWFRecompDocs/prompts/completed/opcode-equals2-0x49.md)

**Notes:**
- Official SWF specification name (spec line 6068)

---

### 0X4A: ActionToNumber

**Name Variations:**
- `ActionToNumber` (spec, source: SWF Specification v19)
- `SWF_ACTION_TO_NUMBER` (enum, source: action.hpp)
- `actionToNumber` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/to_number_swf_4`

**Function Declaration:**
```c
void actionToNumber(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_TO_NUMBER)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-to-number-0x4a.md](SWFRecompDocs/prompts/completed/opcode-to-number-0x4a.md)

**Notes:**
- Official SWF specification name (spec line 6320)

---

### 0X4B: ActionToString

**Name Variations:**
- `ActionToString` (spec, source: SWF Specification v19)
- `SWF_ACTION_TO_STRING` (enum, source: action.hpp)
- `actionToString` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/to_string_swf_4`

**Function Declaration:**
```c
void actionToString(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_TO_STRING)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-to-string-0x4b.md](SWFRecompDocs/prompts/completed/opcode-to-string-0x4b.md)

**Notes:**
- Official SWF specification name (spec line 6342)

---

### 0X4C: ActionPushDuplicate

**Name Variations:**
- `ActionPushDuplicate` (spec, source: SWF Specification v19)
- `SWF_ACTION_DUPLICATE` (enum, source: action.hpp)
- `actionDuplicate` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/duplicate_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/delete_swf_5`
- [✓] `SWFRecomp/tests/extends_swf_7`
- [✓] `SWFRecomp/tests/init_array_swf_4`
- [✓] `SWFRecomp/tests/init_object_swf_4`
- [✓] `SWFRecomp/tests/new_method_swf_5`

**Function Declaration:**
```c
void actionDuplicate(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_DUPLICATE)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-stack-swap-0x4c.md](SWFRecompDocs/prompts/completed/opcode-stack-swap-0x4c.md)

**Notes:**
- Official SWF specification name (spec line 6627)

---

### 0X4D: ActionStackSwap

**Name Variations:**
- `ActionStackSwap` (spec, source: SWF Specification v19)
- `SWF_ACTION_STACK_SWAP` (enum, source: action.hpp)
- `actionStackSwap` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/stack_swap_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/new_method_swf_5`
- [✓] `SWFRecomp/tests/with_swf_5`

**Function Declaration:**
```c
void actionStackSwap(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_STACK_SWAP)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-stack-swap-0x4d.md](SWFRecompDocs/prompts/completed/opcode-stack-swap-0x4d.md)

**Notes:**
- Official SWF specification name (spec line 6660)

---

### 0X4E: ActionGetMember

**Name Variations:**
- `ActionGetMember` (spec, source: SWF Specification v19)
- `SWF_ACTION_GET_MEMBER` (enum, source: action.hpp)
- `actionGetMember` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/get_member_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/delete_swf_5`
- [✓] `SWFRecomp/tests/extends_swf_7`
- [✓] `SWFRecomp/tests/init_array_swf_4`
- [✓] `SWFRecomp/tests/new_method_swf_5`
- [✓] `SWFRecomp/tests/new_object_swf_4`
- [✓] `SWFRecomp/tests/set_member_swf_5`

**Function Declaration:**
```c
void actionGetMember(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_GET_MEMBER)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-get-member-0x4e.md](SWFRecompDocs/prompts/completed/opcode-get-member-0x4e.md)

**Notes:**
- Official SWF specification name (spec line 6090)

---

### 0X4F: ActionSetMember

**Name Variations:**
- `ActionSetMember` (spec, source: SWF Specification v19)
- `SWF_ACTION_SET_MEMBER` (enum, source: action.hpp)
- `actionSetMember` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/set_member_swf_5`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/extends_swf_7`
- [✓] `SWFRecomp/tests/new_object_swf_4`

**Function Declaration:**
```c
void actionSetMember(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_SET_MEMBER)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-set-member-0x4f.md](SWFRecompDocs/prompts/completed/opcode-set-member-0x4f.md)

**Notes:**
- Official SWF specification name (spec line 6248)

---

### 0X50: ActionIncrement

**Name Variations:**
- `ActionIncrement` (spec, source: SWF Specification v19)
- `SWF_ACTION_INCREMENT` (enum, source: action.hpp)
- `actionIncrement` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/increment_swf_4`

**Function Declaration:**
```c
void actionIncrement(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_INCREMENT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-increment-0x50.md](SWFRecompDocs/prompts/completed/opcode-increment-0x50.md)

**Notes:**
- Official SWF specification name (spec line 6605)

---

### 0X51: ActionDecrement

**Name Variations:**
- `ActionDecrement` (spec, source: SWF Specification v19)
- `SWF_ACTION_DECREMENT` (enum, source: action.hpp)
- `actionDecrement` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/decrement_swf_4`

**Function Declaration:**
```c
void actionDecrement(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_DECREMENT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-decrement-0x51.md](SWFRecompDocs/prompts/completed/opcode-decrement-0x51.md)

**Notes:**
- Official SWF specification name (spec line 6586)

---

### 0X52: ActionCallMethod

**Name Variations:**
- `ActionCallMethod` (spec, source: SWF Specification v19)
- `SWF_ACTION_CALL_METHOD` (enum, source: action.hpp)
- `actionCallMethod` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/call_method_empty_name_swf_5`
- [✓] `SWFRecomp/tests/call_method_swf_5`

**Function Declaration:**
```c
void actionCallMethod(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_CALL_METHOD)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-call-method-0x52.md](SWFRecompDocs/prompts/completed/opcode-call-method-0x52.md)

**Notes:**
- Official SWF specification name (spec line 5831)

---

### 0X53: ActionNewMethod

**Name Variations:**
- `ActionNewMethod` (spec, source: SWF Specification v19)
- `SWF_ACTION_NEW_METHOD` (enum, source: action.hpp)
- `actionNewMethod` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/new_method_swf_5`

**Function Declaration:**
```c
void actionNewMethod(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_NEW_METHOD)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-new-method-0x53.md](SWFRecompDocs/prompts/completed/opcode-new-method-0x53.md)

**Notes:**
- Official SWF specification name (spec line 6184)

---

### 0X54: ActionInstanceOf

**Name Variations:**
- `ActionInstanceOf` (spec, source: SWF Specification v19)
- `SWF_ACTION_INSTANCEOF` (enum, source: action.hpp)
- `actionInstanceOf` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/instanceof_swf_6`

**Function Declaration:**
```c
void actionInstanceOf(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_INSTANCEOF)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-instanceof-0x54.md](SWFRecompDocs/prompts/completed/opcode-instanceof-0x54.md)

**Notes:**
- Official SWF specification name (spec line 6782)

---

### 0X55: ActionEnumerate2

**Name Variations:**
- `ActionEnumerate2` (spec, source: SWF Specification v19)
- `SWF_ACTION_ENUMERATE2` (enum, source: action.hpp)
- `actionEnumerate2` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/enumerate2_swf_6`

**Function Declaration:**
```c
void actionEnumerate2(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_ENUMERATE2)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-enumerate2-0x55.md](SWFRecompDocs/prompts/completed/opcode-enumerate2-0x55.md)

**Notes:**
- Official SWF specification name (spec line 6806)

---

### 0X60: ActionBitAnd

**Name Variations:**
- `ActionBitAnd` (spec, source: SWF Specification v19)
- `SWF_ACTION_BIT_AND` (enum, source: action.hpp)
- `actionBitAnd` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/bit_and_swf_4`

**Function Declaration:**
```c
void actionBitAnd(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_BIT_AND)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-bit-and-0x60.md](SWFRecompDocs/prompts/completed/opcode-bit-and-0x60.md)

**Notes:**
- Official SWF specification name (spec line 6457)

---

### 0X61: ActionBitOr

**Name Variations:**
- `ActionBitOr` (spec, source: SWF Specification v19)
- `SWF_ACTION_BIT_OR` (enum, source: action.hpp)
- `actionBitOr` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/bit_or_swf_4`

**Function Declaration:**
```c
void actionBitOr(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_BIT_OR)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-bit-or-0x61.md](SWFRecompDocs/prompts/completed/opcode-bit-or-0x61.md)

**Notes:**
- Official SWF specification name (spec line 6497)

---

### 0X62: ActionBitXor

**Name Variations:**
- `ActionBitXor` (spec, source: SWF Specification v19)
- `SWF_ACTION_BIT_XOR` (enum, source: action.hpp)
- `actionBitXor` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/bit_xor_swf_4`

**Function Declaration:**
```c
void actionBitXor(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_BIT_XOR)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-bit-xor-0x62.md](SWFRecompDocs/prompts/completed/opcode-bit-xor-0x62.md)

**Notes:**
- Official SWF specification name (spec line 6563)

---

### 0X63: ActionBitLShift

**Name Variations:**
- `ActionBitLShift` (spec, source: SWF Specification v19)
- `SWF_ACTION_BIT_LSHIFT` (enum, source: action.hpp)
- `actionBitLShift` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/bit_lshift_swf_4`

**Function Declaration:**
```c
void actionBitLShift(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_BIT_LSHIFT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-bit-lshift-0x63.md](SWFRecompDocs/prompts/completed/opcode-bit-lshift-0x63.md)

**Notes:**
- Official SWF specification name (spec line 6476)

---

### 0X64: ActionBitRShift

**Name Variations:**
- `ActionBitRShift` (spec, source: SWF Specification v19)
- `SWF_ACTION_BIT_RSHIFT` (enum, source: action.hpp)
- `actionBitRShift` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/bit_rshift_swf_4`

**Function Declaration:**
```c
void actionBitRShift(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_BIT_RSHIFT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-bit-rshift-0x64.md](SWFRecompDocs/prompts/completed/opcode-bit-rshift-0x64.md)

**Notes:**
- Official SWF specification name (spec line 6517)

---

### 0X65: ActionBitURShift

**Name Variations:**
- `ActionBitURShift` (spec, source: SWF Specification v19)
- `SWF_ACTION_BIT_URSHIFT` (enum, source: action.hpp)
- `actionBitURShift` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/bit_urshift_swf_4`

**Function Declaration:**
```c
void actionBitURShift(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_BIT_URSHIFT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-bit-urshift-0x65.md](SWFRecompDocs/prompts/completed/opcode-bit-urshift-0x65.md)

**Notes:**
- Official SWF specification name (spec line 6541)

---

### 0X66: ActionStrictEquals

**Name Variations:**
- `ActionStrictEquals` (spec, source: SWF Specification v19)
- `SWF_ACTION_STRICT_EQUALS` (enum, source: action.hpp)
- `actionStrictEquals` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/strict_equals_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/extends_swf_7`

**Function Declaration:**
```c
void actionStrictEquals(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_STRICT_EQUALS)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-strict-equals-0x66.md](SWFRecompDocs/prompts/completed/opcode-strict-equals-0x66.md)

**Notes:**
- Official SWF specification name (spec line 6829)

---

### 0X67: ActionGreater

**Name Variations:**
- `ActionGreater` (spec, source: SWF Specification v19)
- `SWF_ACTION_GREATER` (enum, source: action.hpp)
- `actionGreater` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/greater_swf_4`

**Function Declaration:**
```c
void actionGreater(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_GREATER)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-greater-0x67.md](SWFRecompDocs/prompts/completed/opcode-greater-0x67.md)

**Notes:**
- Official SWF specification name (spec line 6848)

---

### 0X68: ActionStringGreater

**Name Variations:**
- `ActionStringGreater` (spec, source: SWF Specification v19)
- `SWF_ACTION_STRING_GREATER` (enum, source: action.hpp)
- `actionStringGreater` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/string_greater_swf_4`

**Function Declaration:**
```c
void actionStringGreater(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_STRING_GREATER)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-string-greater-0x68.md](SWFRecompDocs/prompts/completed/opcode-string-greater-0x68.md)

**Notes:**
- Official SWF specification name (spec line 6870)

---

### 0X69: ActionExtends

**Name Variations:**
- `ActionExtends` (spec, source: SWF Specification v19)
- `SWF_ACTION_EXTENDS` (enum, source: action.hpp)
- `actionExtends` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/extends_swf_7`

**Function Declaration:**
```c
void actionExtends(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_EXTENDS)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-extends-0x69.md](SWFRecompDocs/prompts/completed/opcode-extends-0x69.md)

**Notes:**
- Official SWF specification name (spec line 7120)

---

### 0X81: ActionGotoFrame

**Name Variations:**
- `ActionGotoFrame` (spec, source: SWF Specification v19)
- `SWF_ACTION_GOTO_FRAME` (enum, source: action.hpp)
- `actionGotoFrame` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/goto_frame_swf_3`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/prev_frame_swf_4`

**Function Declaration:**
```c
void actionGotoFrame(char* stack, u32* sp, u16 frame);
```

**Implementation:**
- parseActions (case SWF_ACTION_GOTO_FRAME)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-gotoframe-0x81.md](SWFRecompDocs/prompts/completed/opcode-gotoframe-0x81.md)

**Notes:**
- Official SWF specification name (spec line 4258)

---

### 0X83: ActionGetURL

**Name Variations:**
- `ActionGetURL` (spec, source: SWF Specification v19)
- `SWF_ACTION_GET_URL` (enum, source: action.hpp)
- `actionGetURL` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/get_url_swf_3`

**Function Declaration:**
```c
void actionGetURL(char* stack, u32* sp, const char* url, const char* target);
```

**Implementation:**
- parseActions (case SWF_ACTION_GET_URL)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-geturl-0x83.md](SWFRecompDocs/prompts/completed/opcode-geturl-0x83.md)

**Notes:**
- Official SWF specification name (spec line 4281)

---

### 0X87: ActionStoreRegister

**Name Variations:**
- `ActionStoreRegister` (spec, source: SWF Specification v19)
- `SWF_ACTION_STORE_REGISTER` (enum, source: action.hpp)
- `actionStoreRegister` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/store_register_swf_4`

**Function Declaration:**
```c
void actionStoreRegister(char* stack, u32* sp, u8 register_num);
```

**Implementation:**
- parseActions (case SWF_ACTION_STORE_REGISTER)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-store-register-0x87.md](SWFRecompDocs/prompts/completed/opcode-store-register-0x87.md)

**Notes:**
- Official SWF specification name (spec line 6678)

---

### 0X88: ActionConstantPool

**Name Variations:**
- `ActionConstantPool` (spec, source: SWF Specification v19)
- `SWF_ACTION_CONSTANT_POOL` (enum, source: action.hpp)

**Primary Tests:**
- [✓] `SWFRecomp/tests/constant_pool_large_swf_5`
- [✓] `SWFRecomp/tests/constant_pool_nonseq_swf_5`
- [✓] `SWFRecomp/tests/constant_pool_repeated_swf_5`
- [✓] `SWFRecomp/tests/constant_pool_swf_5`

**Implementation:**
- parseActions (case SWF_ACTION_CONSTANT_POOL)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-constant-pool-0x88.md](SWFRecompDocs/prompts/completed/opcode-constant-pool-0x88.md)

**Notes:**
- Official SWF specification name (spec line 5868)

---

### 0X8A: ActionWaitForFrame

**Name Variations:**
- `ActionWaitForFrame` (spec, source: SWF Specification v19)
- `SWF_ACTION_WAIT_FOR_FRAME` (enum, source: action.hpp)

**Primary Tests:**
- [✓] `SWFRecomp/tests/wait_for_frame_swf_3`

**Implementation:**
- parseActions (case SWF_ACTION_WAIT_FOR_FRAME)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-waitforframe-0x8a.md](SWFRecompDocs/prompts/completed/opcode-waitforframe-0x8a.md)

**Notes:**
- Official SWF specification name (spec line 4393)

---

### 0X8B: ActionSetTarget

**Name Variations:**
- `ActionSetTarget` (spec, source: SWF Specification v19)
- `SWF_ACTION_SET_TARGET` (enum, source: action.hpp)
- `actionSetTarget` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/set_target_swf_3`

**Function Declaration:**
```c
void actionSetTarget(char* stack, u32* sp, const char* target_name);
```

**Implementation:**
- parseActions (case SWF_ACTION_SET_TARGET)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-settarget-0x8b.md](SWFRecompDocs/prompts/completed/opcode-settarget-0x8b.md)

**Notes:**
- Official SWF specification name (spec line 4437)

---

### 0X8C: ActionGoToLabel

**Name Variations:**
- `ActionGoToLabel` (spec, source: SWF Specification v19)
- `SWF_ACTION_GOTO_LABEL` (enum, source: action.hpp)
- `actionGoToLabel` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/goto_label_swf_3`

**Function Declaration:**
```c
void actionGoToLabel(char* stack, u32* sp, const char* label);
```

**Implementation:**
- parseActions (case SWF_ACTION_GOTO_LABEL)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-gotolabel-0x8c.md](SWFRecompDocs/prompts/completed/opcode-gotolabel-0x8c.md)

**Notes:**
- Official SWF specification name (spec line 4449)

---

### 0X8D: ActionWaitForFrame2

**Name Variations:**
- `ActionWaitForFrame2` (spec, source: SWF Specification v19)
- `SWF_ACTION_WAIT_FOR_FRAME2` (enum, source: action.hpp)

**Primary Tests:**
- [✓] `SWFRecomp/tests/wait_for_frame2_swf_4`

**Implementation:**
- parseActions (case SWF_ACTION_WAIT_FOR_FRAME2)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-waitforframe2-0x8d.md](SWFRecompDocs/prompts/completed/opcode-waitforframe2-0x8d.md)

**Notes:**
- Official SWF specification name (spec line 5655)

---

### 0X8E: ActionDefineFunction2

**Name Variations:**
- `ActionDefineFunction2` (spec, source: SWF Specification v19)
- `SWF_ACTION_DEFINE_FUNCTION2` (enum, source: action.hpp)
- `actionDefineFunction2` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/call_method_empty_name_swf_5`
- [✓] `SWFRecomp/tests/define_function2_swf_7`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/declare_local_swf_5`

**Function Declaration:**
```c
void actionDefineFunction2(char* stack, u32* sp, const char* name, Function2Ptr func, u32 param_count, u8 register_count, u16 flags);
```

**Implementation:**
- parseActions (case SWF_ACTION_DEFINE_FUNCTION2)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-define-function2-0x8e.md](SWFRecompDocs/prompts/completed/opcode-define-function2-0x8e.md)

**Notes:**
- Official SWF specification name (spec line 6949)

---

### 0X8F: ActionTry

**Name Variations:**
- `ActionTry` (spec, source: SWF Specification v19)
- `SWF_ACTION_TRY` (enum, source: action.hpp)

**Primary Tests:**
- [✓] `SWFRecomp/tests/try_swf_7`

**Implementation:**
- parseActions (case SWF_ACTION_TRY)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-try-0x8f.md](SWFRecompDocs/prompts/completed/opcode-try-0x8f.md)

**Notes:**
- Official SWF specification name (spec line 7191)

---

### 0X94: ActionWith

**Name Variations:**
- `ActionWith` (spec, source: SWF Specification v19)
- `SWF_ACTION_WITH` (enum, source: action.hpp)

**Primary Tests:**
- [✓] `SWFRecomp/tests/with_swf_5`

**Implementation:**
- parseActions (case SWF_ACTION_WITH)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-with-0x94.md](SWFRecompDocs/prompts/completed/opcode-with-0x94.md)

**Notes:**
- Official SWF specification name (spec line 6289)

---

### 0X96: ActionPush

**Name Variations:**
- `ActionPush` (spec, source: SWF Specification v19)
- `SWF_ACTION_PUSH` (enum, source: action.hpp)

**Primary Tests:**
- [✓] `SWFRecomp/tests/push_swf_4`

**Secondary Tests:**
- [✓] `SWFRecomp/tests/add2_swf_5`
- [✗] `SWFRecomp/tests/add_floats_swf_4`
- [✓] `SWFRecomp/tests/add_swf_4`
- [✓] `SWFRecomp/tests/and_floats_both_0_swf_4`
- [✓] `SWFRecomp/tests/and_floats_first_1_swf_4`
- [✓] `SWFRecomp/tests/and_floats_nonzero_swf_4`
- [✓] `SWFRecomp/tests/and_floats_second_1_swf_4`
- [✓] `SWFRecomp/tests/and_floats_swf_4`
- [✓] `SWFRecomp/tests/ascii_to_char_swf_4`
- [✓] `SWFRecomp/tests/bit_and_swf_4`
- [✓] `SWFRecomp/tests/bit_lshift_swf_4`
- [✓] `SWFRecomp/tests/bit_or_swf_4`
- [✓] `SWFRecomp/tests/bit_rshift_swf_4`
- [✓] `SWFRecomp/tests/bit_urshift_swf_4`
- [✓] `SWFRecomp/tests/bit_xor_swf_4`
- [✓] `SWFRecomp/tests/call_function_swf_5`
- [✓] `SWFRecomp/tests/call_method_empty_name_swf_5`
- [✓] `SWFRecomp/tests/call_method_swf_5`
- [✓] `SWFRecomp/tests/call_swf_4`
- [✓] `SWFRecomp/tests/cast_op_swf_7`
- [✓] `SWFRecomp/tests/char_to_ascii_swf_4`
- [✓] `SWFRecomp/tests/clone_sprite_swf_4`
- [✓] `SWFRecomp/tests/constant_pool_large_swf_5`
- [✓] `SWFRecomp/tests/constant_pool_nonseq_swf_5`
- [✓] `SWFRecomp/tests/constant_pool_repeated_swf_5`
- [✓] `SWFRecomp/tests/constant_pool_swf_5`
- [✓] `SWFRecomp/tests/declare_local_swf_5`
- [✓] `SWFRecomp/tests/decrement_swf_4`
- [✓] `SWFRecomp/tests/define_function2_swf_7`
- [✓] `SWFRecomp/tests/define_function_swf_5`
- [✓] `SWFRecomp/tests/definelocal_swf_5`
- [✓] `SWFRecomp/tests/delete2_swf_5`
- [✓] `SWFRecomp/tests/delete_swf_5`
- [✓] `SWFRecomp/tests/divide_floats_error_swf_4`
- [✓] `SWFRecomp/tests/duplicate_swf_4`
- [✓] `SWFRecomp/tests/end_drag_swf_4`
- [✓] `SWFRecomp/tests/enumerate2_swf_6`
- [✓] `SWFRecomp/tests/enumerate_swf_4`
- [✓] `SWFRecomp/tests/equals2_swf_5`
- [✓] `SWFRecomp/tests/equals_swf_4`
- [✓] `SWFRecomp/tests/extends_swf_7`
- [✓] `SWFRecomp/tests/get_member_swf_4`
- [✓] `SWFRecomp/tests/get_property_swf_4`
- [✓] `SWFRecomp/tests/get_time_swf_5`
- [✓] `SWFRecomp/tests/get_url2_swf_4`
- [✓] `SWFRecomp/tests/get_url_swf_3`
- [✓] `SWFRecomp/tests/get_variable_swf_4`
- [✓] `SWFRecomp/tests/goto_frame_swf_3`
- [✓] `SWFRecomp/tests/goto_label_swf_3`
- [✓] `SWFRecomp/tests/gotoframe2_swf_5`
- [✓] `SWFRecomp/tests/greater_swf_4`
- [✓] `SWFRecomp/tests/if_false_swf_4`
- [✓] `SWFRecomp/tests/if_swf_4`
- [✓] `SWFRecomp/tests/implements_op_swf_7`
- [✓] `SWFRecomp/tests/increment_swf_4`
- [✓] `SWFRecomp/tests/init_array_swf_4`
- [✓] `SWFRecomp/tests/init_object_swf_4`
- [✓] `SWFRecomp/tests/instanceof_swf_6`
- [✓] `SWFRecomp/tests/jump_swf_4`
- [✓] `SWFRecomp/tests/less2_swf_4`
- [✓] `SWFRecomp/tests/less_floats_false_swf_4`
- [✓] `SWFRecomp/tests/less_floats_swf_4`
- [✓] `SWFRecomp/tests/mb_ascii_to_char_edge_cases_swf_4`
- [✓] `SWFRecomp/tests/mb_ascii_to_char_swf_4`
- [✓] `SWFRecomp/tests/mb_ascii_to_char_swf_5`
- [✓] `SWFRecomp/tests/mb_char_to_ascii_swf_5`
- [✓] `SWFRecomp/tests/mb_string_extract_swf_5`
- [✓] `SWFRecomp/tests/mb_string_length_swf_5`
- [✓] `SWFRecomp/tests/modulo_swf_4`
- [✓] `SWFRecomp/tests/multiply_floats_swf_4`
- [✓] `SWFRecomp/tests/new_method_swf_5`
- [✓] `SWFRecomp/tests/new_object_swf_4`
- [✓] `SWFRecomp/tests/next_frame_swf_4`
- [✓] `SWFRecomp/tests/not_floats_nonzero_swf_4`
- [✓] `SWFRecomp/tests/or_swf_4`
- [✓] `SWFRecomp/tests/play_stop_swf_4`
- [✓] `SWFRecomp/tests/play_swf_4`
- [✓] `SWFRecomp/tests/pop_swf_4`
- [✓] `SWFRecomp/tests/prev_frame_swf_4`
- [✓] `SWFRecomp/tests/random_number_swf_4`
- [✓] `SWFRecomp/tests/remove_sprite_swf_4`
- [✓] `SWFRecomp/tests/return_swf_4`
- [✓] `SWFRecomp/tests/set_member_swf_5`
- [✓] `SWFRecomp/tests/set_property_swf_4`
- [✓] `SWFRecomp/tests/set_target2_swf_4`
- [✓] `SWFRecomp/tests/set_variable_swf_4`
- [✓] `SWFRecomp/tests/stack_swap_swf_4`
- [✓] `SWFRecomp/tests/start_drag_swf_4`
- [✓] `SWFRecomp/tests/stop_multiframe_swf_4`
- [✓] `SWFRecomp/tests/stop_sounds_swf_4`
- [✓] `SWFRecomp/tests/stop_swf_4`
- [✓] `SWFRecomp/tests/store_register_swf_4`
- [✓] `SWFRecomp/tests/strict_equals_swf_4`
- [✓] `SWFRecomp/tests/string_add_swf_4`
- [✓] `SWFRecomp/tests/string_equals_0_swf_4`
- [✓] `SWFRecomp/tests/string_equals_1_swf_4`
- [✓] `SWFRecomp/tests/string_extract_swf_4`
- [✓] `SWFRecomp/tests/string_greater_swf_4`
- [✓] `SWFRecomp/tests/string_length_swf_4`
- [✓] `SWFRecomp/tests/string_less_swf_4`
- [✓] `SWFRecomp/tests/subtract_swf_4`
- [✓] `SWFRecomp/tests/target_path_swf_5`
- [✓] `SWFRecomp/tests/throw_swf_7`
- [✓] `SWFRecomp/tests/to_integer_swf_4`
- [✓] `SWFRecomp/tests/to_number_swf_4`
- [✓] `SWFRecomp/tests/to_string_swf_4`
- [✓] `SWFRecomp/tests/toggle_quality_swf_4`
- [✓] `SWFRecomp/tests/trace_swf_4`
- [✓] `SWFRecomp/tests/try_swf_7`
- [✓] `SWFRecomp/tests/typeof_swf_5`
- [✓] `SWFRecomp/tests/wait_for_frame2_swf_4`
- [✓] `SWFRecomp/tests/wait_for_frame_swf_3`
- [✓] `SWFRecomp/tests/with_swf_5`

**Implementation:**
- parseActions (case SWF_ACTION_PUSH)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-push-0x96.md](SWFRecompDocs/prompts/completed/opcode-push-0x96.md)

**Notes:**
- Official SWF specification name (spec line 4556)

---

### 0X99: ActionJump

**Name Variations:**
- `ActionJump` (spec, source: SWF Specification v19)
- `SWF_ACTION_JUMP` (enum, source: action.hpp)

**Primary Tests:**
- [✓] `SWFRecomp/tests/jump_swf_4`

**Implementation:**
- parseActions (case SWF_ACTION_JUMP)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-jump-0x99.md](SWFRecompDocs/prompts/completed/opcode-jump-0x99.md)

**Notes:**
- Official SWF specification name (spec line 5139)

---

### 0X9A: ActionGetURL2

**Name Variations:**
- `ActionGetURL2` (spec, source: SWF Specification v19)
- `SWF_ACTION_GET_URL2` (enum, source: action.hpp)
- `actionGetURL2` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/get_url2_swf_4`

**Function Declaration:**
```c
void actionGetURL2(char* stack, u32* sp, u8 send_vars_method, u8 load_target_flag, u8 load_variables_flag);
```

**Implementation:**
- parseActions (case SWF_ACTION_GET_URL2)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-geturl2-0x9a.md](SWFRecompDocs/prompts/completed/opcode-geturl2-0x9a.md)

**Notes:**
- Official SWF specification name (spec line 5262)

---

### 0X9B: ActionDefineFunction

**Name Variations:**
- `ActionDefineFunction` (spec, source: SWF Specification v19)
- `SWF_ACTION_DEFINE_FUNCTION` (enum, source: action.hpp)

**Primary Tests:**
- [✓] `SWFRecomp/tests/define_function_swf_5`

**Implementation:**
- parseActions (case SWF_ACTION_DEFINE_FUNCTION)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-define-function-0x9b.md](SWFRecompDocs/prompts/completed/opcode-define-function-0x9b.md)

**Notes:**
- Official SWF specification name (spec line 5894)

---

### 0X9D: ActionIf

**Name Variations:**
- `ActionIf` (spec, source: SWF Specification v19)
- `SWF_ACTION_IF` (enum, source: action.hpp)

**Primary Tests:**
- [✓] `SWFRecomp/tests/if_false_swf_4`
- [✓] `SWFRecomp/tests/if_swf_4`

**Implementation:**
- parseActions (case SWF_ACTION_IF)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-if-0x9d.md](SWFRecompDocs/prompts/completed/opcode-if-0x9d.md)

**Notes:**
- Official SWF specification name (spec line 5163)

---

### 0X9E: ActionCall

**Name Variations:**
- `ActionCall` (spec, source: SWF Specification v19)
- `SWF_ACTION_CALL` (enum, source: action.hpp)
- `actionCall` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/call_swf_4`

**Function Declaration:**
```c
void actionCall(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_CALL)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-call-0x9e.md](SWFRecompDocs/prompts/completed/opcode-call-0x9e.md)

**Notes:**
- Official SWF specification name (spec line 5195)

---

### 0X9F: ActionGotoFrame2

**Name Variations:**
- `ActionGotoFrame2` (spec, source: SWF Specification v19)
- `SWF_ACTION_GOTO_FRAME2` (enum, source: action.hpp)
- `actionGotoFrame2` (function, source: action.h)

**Primary Tests:**
- [✓] `SWFRecomp/tests/gotoframe2_swf_5`

**Function Declaration:**
```c
void actionGotoFrame2(char* stack, u32* sp, u8 play_flag, u16 scene_bias);
```

**Implementation:**
- parseActions (case SWF_ACTION_GOTO_FRAME2)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-gotoframe2-0x9f.md](SWFRecompDocs/prompts/completed/opcode-gotoframe2-0x9f.md)

**Notes:**
- Official SWF specification name (spec line 5344)

---
