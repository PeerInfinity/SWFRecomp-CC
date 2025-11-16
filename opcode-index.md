# AS2 Opcode Index

**Generated**: 2025-11-16

**Total Opcodes**: 100

**Implemented Opcodes**: 99

## Test Statistics

**Primary Tests**: 118/118 passing (100.0%)

## Implementation Progress

**Fully Implemented Opcodes**: 85/100

**Fully Implemented Opcodes - No Graphics Mode**: 99/100

**Opcodes with Primary Tests**: 99

**Opcodes with Documentation**: 99


## Summary Table

| Hex | Spec Name | Enum Name | Function Name | Primary Tests | Secondary Tests | Failing Primary | Docs | Fully Impl | Fully Impl (No Graphics) |
|-----|-----------|-----------|---------------|---------------|-----------------|-----------------|------|------------|--------------------------|
| 0X00 |  | SWF_ACTION_END_OF_ACTIONS |  |  |  |  |  |  |  |
| [0X04](#0x04-actionnextframe) | [ActionNextFrame](#0x04-actionnextframe) | [SWF_ACTION_NEXT_FRAME](#0x04-actionnextframe) | [actionNextFrame](#0x04-actionnextframe) | 1/1 |  |  | ✓ | ✓ | ✓ |
| [0X05](#0x05-actionpreviousframe) | [ActionPreviousFrame](#0x05-actionpreviousframe) | [SWF_ACTION_PREV_FRAME](#0x05-actionpreviousframe) | [actionPrevFrame](#0x05-actionpreviousframe) | 1/1 |  |  | ✓ | ✓ |  |
| [0X06](#0x06-actionplay) | [ActionPlay](#0x06-actionplay) | [SWF_ACTION_PLAY](#0x06-actionplay) | [actionPlay](#0x06-actionplay) | 2/2 |  |  | ✓ | ✓ | ✓ |
| [0X07](#0x07-actionstop) | [ActionStop](#0x07-actionstop) | [SWF_ACTION_STOP](#0x07-actionstop) |  | 3/3 | 3/3 |  | ✓ | ✓ |  |
| [0X08](#0x08-actiontogglequality) | [ActionToggleQuality](#0x08-actiontogglequality) | [SWF_ACTION_TOGGLE_QUALITY](#0x08-actiontogglequality) | [actionToggleQuality](#0x08-actiontogglequality) | 1/1 |  |  | ✓ |  | ✓ |
| [0X09](#0x09-actionstopsounds) | [ActionStopSounds](#0x09-actionstopsounds) | [SWF_ACTION_STOP_SOUNDS](#0x09-actionstopsounds) | [actionStopSounds](#0x09-actionstopsounds) | 1/1 |  |  | ✓ |  | ✓ |
| [0X0A](#0x0a-actionadd) | [ActionAdd](#0x0a-actionadd) | [SWF_ACTION_ADD](#0x0a-actionadd) | [actionAdd](#0x0a-actionadd) | 2/2 | 4/4 |  | ✓ | ✓ |  |
| [0X0B](#0x0b-actionsubtract) | [ActionSubtract](#0x0b-actionsubtract) | [SWF_ACTION_SUBTRACT](#0x0b-actionsubtract) | [actionSubtract](#0x0b-actionsubtract) | 1/1 |  |  | ✓ | ✓ |  |
| [0X0C](#0x0c-actionmultiply) | [ActionMultiply](#0x0c-actionmultiply) | [SWF_ACTION_MULTIPLY](#0x0c-actionmultiply) | [actionMultiply](#0x0c-actionmultiply) | 1/1 |  |  | ✓ | ✓ |  |
| [0X0D](#0x0d-actiondivide) | [ActionDivide](#0x0d-actiondivide) | [SWF_ACTION_DIVIDE](#0x0d-actiondivide) | [actionDivide](#0x0d-actiondivide) | 1/1 | 1/1 |  | ✓ | ✓ |  |
| [0X0E](#0x0e-actionequals) | [ActionEquals](#0x0e-actionequals) | [SWF_ACTION_EQUALS](#0x0e-actionequals) | [actionEquals](#0x0e-actionequals) | 1/1 |  |  | ✓ | ✓ |  |
| [0X0F](#0x0f-actionless) | [ActionLess](#0x0f-actionless) | [SWF_ACTION_LESS](#0x0f-actionless) | [actionLess](#0x0f-actionless) | 2/2 |  |  | ✓ | ✓ |  |
| [0X10](#0x10-actionand) | [ActionAnd](#0x10-actionand) | [SWF_ACTION_AND](#0x10-actionand) | [actionAnd](#0x10-actionand) | 5/5 |  |  | ✓ | ✓ |  |
| [0X11](#0x11-actionor) | [ActionOr](#0x11-actionor) | [SWF_ACTION_OR](#0x11-actionor) | [actionOr](#0x11-actionor) | 1/1 |  |  | ✓ | ✓ |  |
| [0X12](#0x12-actionnot) | [ActionNot](#0x12-actionnot) | [SWF_ACTION_NOT](#0x12-actionnot) | [actionNot](#0x12-actionnot) | 1/1 |  |  | ✓ | ✓ |  |
| [0X13](#0x13-actionstringequals) | [ActionStringEquals](#0x13-actionstringequals) | [SWF_ACTION_STRING_EQUALS](#0x13-actionstringequals) | [actionStringEquals](#0x13-actionstringequals) | 2/2 |  |  | ✓ | ✓ |  |
| [0X14](#0x14-actionstringlength) | [ActionStringLength](#0x14-actionstringlength) | [SWF_ACTION_STRING_LENGTH](#0x14-actionstringlength) | [actionStringLength](#0x14-actionstringlength) | 1/1 |  |  | ✓ | ✓ |  |
| [0X15](#0x15-actionstringextract) | [ActionStringExtract](#0x15-actionstringextract) | [SWF_ACTION_STRING_EXTRACT](#0x15-actionstringextract) | [actionStringExtract](#0x15-actionstringextract) | 1/1 |  |  | ✓ | ✓ |  |
| [0X17](#0x17-actionpop) | [ActionPop](#0x17-actionpop) | [SWF_ACTION_POP](#0x17-actionpop) |  | 1/1 | 5/5 |  | ✓ | ✓ |  |
| [0X18](#0x18-actiontointeger) | [ActionToInteger](#0x18-actiontointeger) | [SWF_ACTION_TO_INTEGER](#0x18-actiontointeger) | [actionToInteger](#0x18-actiontointeger) | 1/1 |  |  | ✓ | ✓ |  |
| [0X1C](#0x1c-actiongetvariable) | [ActionGetVariable](#0x1c-actiongetvariable) | [SWF_ACTION_GET_VARIABLE](#0x1c-actiongetvariable) | [actionGetVariable](#0x1c-actiongetvariable) | 1/1 | 10/10 |  | ✓ | ✓ |  |
| [0X1D](#0x1d-actionsetvariable) | [ActionSetVariable](#0x1d-actionsetvariable) | [SWF_ACTION_SET_VARIABLE](#0x1d-actionsetvariable) | [actionSetVariable](#0x1d-actionsetvariable) | 1/1 | 9/9 |  | ✓ | ✓ |  |
| [0X20](#0x20-actionsettarget2) | [ActionSetTarget2](#0x20-actionsettarget2) | [SWF_ACTION_SET_TARGET2](#0x20-actionsettarget2) | [actionSetTarget2](#0x20-actionsettarget2) | 1/1 |  |  | ✓ |  | ✓ |
| [0X21](#0x21-actionstringadd) | [ActionStringAdd](#0x21-actionstringadd) | [SWF_ACTION_STRING_ADD](#0x21-actionstringadd) | [actionStringAdd](#0x21-actionstringadd) | 1/1 | 3/3 |  | ✓ | ✓ |  |
| [0X22](#0x22-actiongetproperty) | [ActionGetProperty](#0x22-actiongetproperty) | [SWF_ACTION_GET_PROPERTY](#0x22-actiongetproperty) | [actionGetProperty](#0x22-actiongetproperty) | 1/1 |  |  | ✓ | ✓ |  |
| [0X23](#0x23-actionsetproperty) | [ActionSetProperty](#0x23-actionsetproperty) | [SWF_ACTION_SET_PROPERTY](#0x23-actionsetproperty) | [actionSetProperty](#0x23-actionsetproperty) | 1/1 |  |  | ✓ |  | ✓ |
| [0X24](#0x24-actionclonesprite) | [ActionCloneSprite](#0x24-actionclonesprite) | [SWF_ACTION_CLONE_SPRITE](#0x24-actionclonesprite) | [actionCloneSprite](#0x24-actionclonesprite) | 1/1 |  |  | ✓ |  | ✓ |
| [0X25](#0x25-actionremovesprite) | [ActionRemoveSprite](#0x25-actionremovesprite) | [SWF_ACTION_REMOVE_SPRITE](#0x25-actionremovesprite) | [actionRemoveSprite](#0x25-actionremovesprite) | 1/1 |  |  | ✓ |  | ✓ |
| [0X26](#0x26-actiontrace) | [ActionTrace](#0x26-actiontrace) | [SWF_ACTION_TRACE](#0x26-actiontrace) | [actionTrace](#0x26-actiontrace) | 1/1 | 111/111 |  | ✓ | ✓ |  |
| [0X27](#0x27-actionstartdrag) | [ActionStartDrag](#0x27-actionstartdrag) | [SWF_ACTION_START_DRAG](#0x27-actionstartdrag) | [actionStartDrag](#0x27-actionstartdrag) | 1/1 | 1/1 |  | ✓ |  | ✓ |
| [0X28](#0x28-actionenddrag) | [ActionEndDrag](#0x28-actionenddrag) | [SWF_ACTION_END_DRAG](#0x28-actionenddrag) | [actionEndDrag](#0x28-actionenddrag) | 1/1 |  |  | ✓ |  | ✓ |
| [0X29](#0x29-actionstringless) | [ActionStringLess](#0x29-actionstringless) | [SWF_ACTION_STRING_LESS](#0x29-actionstringless) | [actionStringLess](#0x29-actionstringless) | 1/1 |  |  | ✓ | ✓ |  |
| [0X2A](#0x2a-actionthrow) | [ActionThrow](#0x2a-actionthrow) | [SWF_ACTION_THROW](#0x2a-actionthrow) | [actionThrow](#0x2a-actionthrow) | 2/2 |  |  | ✓ | ✓ |  |
| [0X2B](#0x2b-actioncastop) | [ActionCastOp](#0x2b-actioncastop) | [SWF_ACTION_CAST_OP](#0x2b-actioncastop) | [actionCastOp](#0x2b-actioncastop) | 1/1 |  |  | ✓ | ✓ |  |
| [0X2C](#0x2c-actionimplementsop) | [ActionImplementsOp](#0x2c-actionimplementsop) | [SWF_ACTION_IMPLEMENTS_OP](#0x2c-actionimplementsop) | [actionImplementsOp](#0x2c-actionimplementsop) | 1/1 |  |  | ✓ | ✓ |  |
| [0X30](#0x30-actionrandomnumber) | [ActionRandomNumber](#0x30-actionrandomnumber) | [SWF_ACTION_RANDOM_NUMBER](#0x30-actionrandomnumber) | [actionRandomNumber](#0x30-actionrandomnumber) | 1/1 |  |  | ✓ | ✓ |  |
| [0X31](#0x31-actionmbstringlength) | [ActionMBStringLength](#0x31-actionmbstringlength) | [SWF_ACTION_MB_STRING_LENGTH](#0x31-actionmbstringlength) | [actionMbStringLength](#0x31-actionmbstringlength) | 1/1 |  |  | ✓ | ✓ |  |
| [0X32](#0x32-actionchartoascii) | [ActionCharToAscii](#0x32-actionchartoascii) | [SWF_ACTION_CHAR_TO_ASCII](#0x32-actionchartoascii) | [actionCharToAscii](#0x32-actionchartoascii) | 1/1 |  |  | ✓ | ✓ |  |
| [0X33](#0x33-actionasciitochar) | [ActionAsciiToChar](#0x33-actionasciitochar) | [SWF_ACTION_ASCII_TO_CHAR](#0x33-actionasciitochar) | [actionAsciiToChar](#0x33-actionasciitochar) | 1/1 |  |  | ✓ | ✓ |  |
| [0X34](#0x34-actiongettime) | [ActionGetTime](#0x34-actiongettime) | [SWF_ACTION_GET_TIME](#0x34-actiongettime) | [actionGetTime](#0x34-actiongettime) | 1/1 |  |  | ✓ | ✓ |  |
| [0X35](#0x35-actionmbstringextract) | [ActionMBStringExtract](#0x35-actionmbstringextract) | [SWF_ACTION_MB_STRING_EXTRACT](#0x35-actionmbstringextract) | [actionMbStringExtract](#0x35-actionmbstringextract) | 1/1 |  |  | ✓ | ✓ |  |
| [0X36](#0x36-actionmbchartoascii) | [ActionMBCharToAscii](#0x36-actionmbchartoascii) | [SWF_ACTION_MB_CHAR_TO_ASCII](#0x36-actionmbchartoascii) | [actionMbCharToAscii](#0x36-actionmbchartoascii) | 1/1 |  |  | ✓ | ✓ |  |
| [0X37](#0x37-actionmbasciitochar) | [ActionMBAsciiToChar](#0x37-actionmbasciitochar) | [SWF_ACTION_MB_ASCII_TO_CHAR](#0x37-actionmbasciitochar) | [actionMbAsciiToChar](#0x37-actionmbasciitochar) | 3/3 |  |  | ✓ | ✓ |  |
| [0X3A](#0x3a-actiondelete) | [ActionDelete](#0x3a-actiondelete) | [SWF_ACTION_DELETE](#0x3a-actiondelete) | [actionDelete](#0x3a-actiondelete) | 1/1 |  |  | ✓ | ✓ |  |
| [0X3B](#0x3b-actiondelete2) | [ActionDelete2](#0x3b-actiondelete2) | [SWF_ACTION_DELETE2](#0x3b-actiondelete2) | [actionDelete2](#0x3b-actiondelete2) | 1/1 |  |  | ✓ | ✓ |  |
| [0X3C](#0x3c-actiondefinelocal) | [ActionDefineLocal](#0x3c-actiondefinelocal) | [SWF_ACTION_DEFINE_LOCAL](#0x3c-actiondefinelocal) | [actionDefineLocal](#0x3c-actiondefinelocal) | 1/1 |  |  | ✓ | ✓ |  |
| [0X3D](#0x3d-actionstackswap) | [ActionStackSwap](#0x3d-actionstackswap) | [SWF_ACTION_CALL_FUNCTION](#0x3d-actionstackswap) | [actionStackSwap](#0x3d-actionstackswap) | 1/1 | 2/2 |  | ✓ | ✓ |  |
| [0X3E](#0x3e-actionreturn) | [ActionReturn](#0x3e-actionreturn) | [SWF_ACTION_RETURN](#0x3e-actionreturn) | [actionReturn](#0x3e-actionreturn) | 1/1 | 3/3 |  | ✓ | ✓ |  |
| [0X3F](#0x3f-actionmodulo) | [ActionModulo](#0x3f-actionmodulo) | [SWF_ACTION_MODULO](#0x3f-actionmodulo) | [actionModulo](#0x3f-actionmodulo) | 1/1 |  |  | ✓ | ✓ |  |
| [0X40](#0x40-actionnewobject) | [ActionNewObject](#0x40-actionnewobject) | [SWF_ACTION_NEW_OBJECT](#0x40-actionnewobject) | [actionNewObject](#0x40-actionnewobject) | 1/1 |  |  | ✓ | ✓ |  |
| [0X41](#0x41-actiondefinelocal2) | [ActionDefineLocal2](#0x41-actiondefinelocal2) | [SWF_ACTION_DECLARE_LOCAL](#0x41-actiondefinelocal2) | [actionDeclareLocal](#0x41-actiondefinelocal2) | 1/1 |  |  | ✓ | ✓ |  |
| [0X42](#0x42-actioninitarray) | [ActionInitArray](#0x42-actioninitarray) | [SWF_ACTION_INIT_ARRAY](#0x42-actioninitarray) | [actionInitArray](#0x42-actioninitarray) | 1/1 |  |  | ✓ | ✓ |  |
| [0X43](#0x43-actioninitobject) | [ActionInitObject](#0x43-actioninitobject) | [SWF_ACTION_INIT_OBJECT](#0x43-actioninitobject) | [actionInitObject](#0x43-actioninitobject) | 1/1 | 9/9 |  | ✓ | ✓ |  |
| [0X44](#0x44-actiontypeof) | [ActionTypeOf](#0x44-actiontypeof) | [SWF_ACTION_TYPEOF](#0x44-actiontypeof) | [actionTypeof](#0x44-actiontypeof) | 1/1 | 2/2 |  | ✓ | ✓ |  |
| [0X45](#0x45-actiontargetpath) | [ActionTargetPath](#0x45-actiontargetpath) | [SWF_ACTION_TARGET_PATH](#0x45-actiontargetpath) | [actionTargetPath](#0x45-actiontargetpath) | 1/1 |  |  | ✓ | ✓ |  |
| [0X46](#0x46-actionenumerate) | [ActionEnumerate](#0x46-actionenumerate) | [SWF_ACTION_ENUMERATE](#0x46-actionenumerate) | [actionEnumerate](#0x46-actionenumerate) | 1/1 |  |  | ✓ | ✓ |  |
| [0X47](#0x47-actionadd2) | [ActionAdd2](#0x47-actionadd2) | [SWF_ACTION_ADD2](#0x47-actionadd2) | [actionAdd2](#0x47-actionadd2) | 1/1 |  |  | ✓ | ✓ |  |
| [0X48](#0x48-actionless2) | [ActionLess2](#0x48-actionless2) | [SWF_ACTION_LESS2](#0x48-actionless2) | [actionLess2](#0x48-actionless2) | 1/1 |  |  | ✓ | ✓ |  |
| [0X49](#0x49-actionequals2) | [ActionEquals2](#0x49-actionequals2) | [SWF_ACTION_EQUALS2](#0x49-actionequals2) | [actionEquals2](#0x49-actionequals2) | 1/1 |  |  | ✓ | ✓ |  |
| [0X4A](#0x4a-actiontonumber) | [ActionToNumber](#0x4a-actiontonumber) | [SWF_ACTION_TO_NUMBER](#0x4a-actiontonumber) | [actionToNumber](#0x4a-actiontonumber) | 1/1 |  |  | ✓ | ✓ |  |
| [0X4B](#0x4b-actiontostring) | [ActionToString](#0x4b-actiontostring) | [SWF_ACTION_TO_STRING](#0x4b-actiontostring) | [actionToString](#0x4b-actiontostring) | 1/1 |  |  | ✓ | ✓ |  |
| [0X4C](#0x4c-actionpushduplicate) | [ActionPushDuplicate](#0x4c-actionpushduplicate) | [SWF_ACTION_DUPLICATE](#0x4c-actionpushduplicate) | [actionDuplicate](#0x4c-actionpushduplicate) | 1/1 | 5/5 |  | ✓ | ✓ |  |
| [0X4D](#0x4d-actionstackswap) | [ActionStackSwap](#0x4d-actionstackswap) | [SWF_ACTION_STACK_SWAP](#0x4d-actionstackswap) | [actionStackSwap](#0x4d-actionstackswap) | 1/1 | 2/2 |  | ✓ | ✓ |  |
| [0X4E](#0x4e-actiongetmember) | [ActionGetMember](#0x4e-actiongetmember) | [SWF_ACTION_GET_MEMBER](#0x4e-actiongetmember) | [actionGetMember](#0x4e-actiongetmember) | 1/1 | 6/6 |  | ✓ | ✓ |  |
| [0X4F](#0x4f-actionsetmember) | [ActionSetMember](#0x4f-actionsetmember) | [SWF_ACTION_SET_MEMBER](#0x4f-actionsetmember) | [actionSetMember](#0x4f-actionsetmember) | 1/1 | 2/2 |  | ✓ | ✓ |  |
| [0X50](#0x50-actionincrement) | [ActionIncrement](#0x50-actionincrement) | [SWF_ACTION_INCREMENT](#0x50-actionincrement) | [actionIncrement](#0x50-actionincrement) | 1/1 |  |  | ✓ | ✓ |  |
| [0X51](#0x51-actiondecrement) | [ActionDecrement](#0x51-actiondecrement) | [SWF_ACTION_DECREMENT](#0x51-actiondecrement) | [actionDecrement](#0x51-actiondecrement) | 1/1 |  |  | ✓ | ✓ |  |
| [0X52](#0x52-actioncallmethod) | [ActionCallMethod](#0x52-actioncallmethod) | [SWF_ACTION_CALL_METHOD](#0x52-actioncallmethod) | [actionCallMethod](#0x52-actioncallmethod) | 2/2 |  |  | ✓ | ✓ |  |
| [0X53](#0x53-actionnewmethod) | [ActionNewMethod](#0x53-actionnewmethod) | [SWF_ACTION_NEW_METHOD](#0x53-actionnewmethod) | [actionNewMethod](#0x53-actionnewmethod) | 1/1 |  |  | ✓ | ✓ | ✓ |
| [0X54](#0x54-actioninstanceof) | [ActionInstanceOf](#0x54-actioninstanceof) | [SWF_ACTION_INSTANCEOF](#0x54-actioninstanceof) | [actionInstanceOf](#0x54-actioninstanceof) | 1/1 |  |  | ✓ | ✓ |  |
| [0X55](#0x55-actionenumerate2) | [ActionEnumerate2](#0x55-actionenumerate2) | [SWF_ACTION_ENUMERATE2](#0x55-actionenumerate2) | [actionEnumerate2](#0x55-actionenumerate2) | 1/1 |  |  | ✓ | ✓ |  |
| [0X60](#0x60-actionbitand) | [ActionBitAnd](#0x60-actionbitand) | [SWF_ACTION_BIT_AND](#0x60-actionbitand) | [actionBitAnd](#0x60-actionbitand) | 1/1 |  |  | ✓ | ✓ |  |
| [0X61](#0x61-actionbitor) | [ActionBitOr](#0x61-actionbitor) | [SWF_ACTION_BIT_OR](#0x61-actionbitor) | [actionBitOr](#0x61-actionbitor) | 1/1 |  |  | ✓ | ✓ |  |
| [0X62](#0x62-actionbitxor) | [ActionBitXor](#0x62-actionbitxor) | [SWF_ACTION_BIT_XOR](#0x62-actionbitxor) | [actionBitXor](#0x62-actionbitxor) | 1/1 |  |  | ✓ | ✓ |  |
| [0X63](#0x63-actionbitlshift) | [ActionBitLShift](#0x63-actionbitlshift) | [SWF_ACTION_BIT_LSHIFT](#0x63-actionbitlshift) | [actionBitLShift](#0x63-actionbitlshift) | 1/1 |  |  | ✓ | ✓ |  |
| [0X64](#0x64-actionbitrshift) | [ActionBitRShift](#0x64-actionbitrshift) | [SWF_ACTION_BIT_RSHIFT](#0x64-actionbitrshift) | [actionBitRShift](#0x64-actionbitrshift) | 1/1 |  |  | ✓ | ✓ |  |
| [0X65](#0x65-actionbiturshift) | [ActionBitURShift](#0x65-actionbiturshift) | [SWF_ACTION_BIT_URSHIFT](#0x65-actionbiturshift) | [actionBitURShift](#0x65-actionbiturshift) | 1/1 |  |  | ✓ | ✓ |  |
| [0X66](#0x66-actionstrictequals) | [ActionStrictEquals](#0x66-actionstrictequals) | [SWF_ACTION_STRICT_EQUALS](#0x66-actionstrictequals) | [actionStrictEquals](#0x66-actionstrictequals) | 1/1 | 1/1 |  | ✓ | ✓ |  |
| [0X67](#0x67-actiongreater) | [ActionGreater](#0x67-actiongreater) | [SWF_ACTION_GREATER](#0x67-actiongreater) | [actionGreater](#0x67-actiongreater) | 1/1 |  |  | ✓ | ✓ |  |
| [0X68](#0x68-actionstringgreater) | [ActionStringGreater](#0x68-actionstringgreater) | [SWF_ACTION_STRING_GREATER](#0x68-actionstringgreater) | [actionStringGreater](#0x68-actionstringgreater) | 1/1 |  |  | ✓ | ✓ |  |
| [0X69](#0x69-actionextends) | [ActionExtends](#0x69-actionextends) | [SWF_ACTION_EXTENDS](#0x69-actionextends) | [actionExtends](#0x69-actionextends) | 1/1 |  |  | ✓ | ✓ |  |
| [0X81](#0x81-actiongotoframe) | [ActionGotoFrame](#0x81-actiongotoframe) | [SWF_ACTION_GOTO_FRAME](#0x81-actiongotoframe) | [actionGotoFrame](#0x81-actiongotoframe) | 1/1 | 1/1 |  | ✓ |  | ✓ |
| [0X83](#0x83-actiongeturl) | [ActionGetURL](#0x83-actiongeturl) | [SWF_ACTION_GET_URL](#0x83-actiongeturl) | [actionGetURL](#0x83-actiongeturl) | 1/1 |  |  | ✓ |  | ✓ |
| [0X87](#0x87-actionstoreregister) | [ActionStoreRegister](#0x87-actionstoreregister) | [SWF_ACTION_STORE_REGISTER](#0x87-actionstoreregister) | [actionStoreRegister](#0x87-actionstoreregister) | 1/1 |  |  | ✓ | ✓ |  |
| [0X88](#0x88-actionconstantpool) | [ActionConstantPool](#0x88-actionconstantpool) | [SWF_ACTION_CONSTANT_POOL](#0x88-actionconstantpool) |  | 4/4 |  |  | ✓ | ✓ |  |
| [0X8A](#0x8a-actionwaitforframe) | [ActionWaitForFrame](#0x8a-actionwaitforframe) | [SWF_ACTION_WAIT_FOR_FRAME](#0x8a-actionwaitforframe) |  | 1/1 |  |  | ✓ | ✓ |  |
| [0X8B](#0x8b-actionsettarget) | [ActionSetTarget](#0x8b-actionsettarget) | [SWF_ACTION_SET_TARGET](#0x8b-actionsettarget) | [actionSetTarget](#0x8b-actionsettarget) | 1/1 |  |  | ✓ |  | ✓ |
| [0X8C](#0x8c-actiongotolabel) | [ActionGoToLabel](#0x8c-actiongotolabel) | [SWF_ACTION_GOTO_LABEL](#0x8c-actiongotolabel) | [actionGoToLabel](#0x8c-actiongotolabel) | 1/1 |  |  | ✓ | ✓ |  |
| [0X8D](#0x8d-actionwaitforframe2) | [ActionWaitForFrame2](#0x8d-actionwaitforframe2) | [SWF_ACTION_WAIT_FOR_FRAME2](#0x8d-actionwaitforframe2) |  | 1/1 |  |  | ✓ | ✓ |  |
| [0X8E](#0x8e-actiondefinefunction2) | [ActionDefineFunction2](#0x8e-actiondefinefunction2) | [SWF_ACTION_DEFINE_FUNCTION2](#0x8e-actiondefinefunction2) | [actionDefineFunction2](#0x8e-actiondefinefunction2) | 2/2 | 1/1 |  | ✓ | ✓ |  |
| [0X8F](#0x8f-actiontry) | [ActionTry](#0x8f-actiontry) | [SWF_ACTION_TRY](#0x8f-actiontry) |  | 1/1 |  |  | ✓ | ✓ |  |
| [0X94](#0x94-actionwith) | [ActionWith](#0x94-actionwith) | [SWF_ACTION_WITH](#0x94-actionwith) |  | 1/1 |  |  | ✓ | ✓ |  |
| [0X96](#0x96-actionpush) | [ActionPush](#0x96-actionpush) | [SWF_ACTION_PUSH](#0x96-actionpush) |  | 1/1 | 113/113 |  | ✓ | ✓ |  |
| [0X99](#0x99-actionjump) | [ActionJump](#0x99-actionjump) | [SWF_ACTION_JUMP](#0x99-actionjump) |  | 1/1 |  |  | ✓ | ✓ |  |
| [0X9A](#0x9a-actiongeturl2) | [ActionGetURL2](#0x9a-actiongeturl2) | [SWF_ACTION_GET_URL2](#0x9a-actiongeturl2) | [actionGetURL2](#0x9a-actiongeturl2) | 1/1 |  |  | ✓ |  | ✓ |
| [0X9B](#0x9b-actiondefinefunction) | [ActionDefineFunction](#0x9b-actiondefinefunction) | [SWF_ACTION_DEFINE_FUNCTION](#0x9b-actiondefinefunction) |  | 1/1 |  |  | ✓ | ✓ |  |
| [0X9D](#0x9d-actionif) | [ActionIf](#0x9d-actionif) | [SWF_ACTION_IF](#0x9d-actionif) |  | 2/2 |  |  | ✓ | ✓ |  |
| [0X9E](#0x9e-actioncall) | [ActionCall](#0x9e-actioncall) | [SWF_ACTION_CALL](#0x9e-actioncall) | [actionCall](#0x9e-actioncall) | 1/1 |  |  | ✓ |  | ✓ |
| [0X9F](#0x9f-actiongotoframe2) | [ActionGotoFrame2](#0x9f-actiongotoframe2) | [SWF_ACTION_GOTO_FRAME2](#0x9f-actiongotoframe2) | [actionGotoFrame2](#0x9f-actiongotoframe2) | 1/1 |  |  | ✓ |  | ✓ |

## Passing Primary Tests

**Total Passing Primary Tests**: 118

| Hex | Opcode | Test Path | Enum | Function | Docs |
|-----|--------|-----------|------|----------|------|
| [0X04](#0x04-actionnextframe) | [ActionNextFrame](#0x04-actionnextframe) | `next_frame_swf_4` | ✓ | ✓ | ✓ |
| [0X05](#0x05-actionpreviousframe) | [ActionPreviousFrame](#0x05-actionpreviousframe) | `prev_frame_swf_4` | ✓ | ✓ | ✓ |
| [0X06](#0x06-actionplay) | [ActionPlay](#0x06-actionplay) | `play_stop_swf_4` | ✓ | ✓ | ✓ |
| [0X06](#0x06-actionplay) | [ActionPlay](#0x06-actionplay) | `play_swf_4` | ✓ | ✓ | ✓ |
| [0X07](#0x07-actionstop) | [ActionStop](#0x07-actionstop) | `play_stop_swf_4` | ✓ |  | ✓ |
| [0X07](#0x07-actionstop) | [ActionStop](#0x07-actionstop) | `stop_multiframe_swf_4` | ✓ |  | ✓ |
| [0X07](#0x07-actionstop) | [ActionStop](#0x07-actionstop) | `stop_swf_4` | ✓ |  | ✓ |
| [0X08](#0x08-actiontogglequality) | [ActionToggleQuality](#0x08-actiontogglequality) | `toggle_quality_swf_4` | ✓ | ✓ | ✓ |
| [0X09](#0x09-actionstopsounds) | [ActionStopSounds](#0x09-actionstopsounds) | `stop_sounds_swf_4` | ✓ | ✓ | ✓ |
| [0X0A](#0x0a-actionadd) | [ActionAdd](#0x0a-actionadd) | `add_floats_swf_4` | ✓ | ✓ | ✓ |
| [0X0A](#0x0a-actionadd) | [ActionAdd](#0x0a-actionadd) | `add_swf_4` | ✓ | ✓ | ✓ |
| [0X0B](#0x0b-actionsubtract) | [ActionSubtract](#0x0b-actionsubtract) | `subtract_swf_4` | ✓ | ✓ | ✓ |
| [0X0C](#0x0c-actionmultiply) | [ActionMultiply](#0x0c-actionmultiply) | `multiply_floats_swf_4` | ✓ | ✓ | ✓ |
| [0X0D](#0x0d-actiondivide) | [ActionDivide](#0x0d-actiondivide) | `divide_floats_error_swf_4` | ✓ | ✓ | ✓ |
| [0X0E](#0x0e-actionequals) | [ActionEquals](#0x0e-actionequals) | `equals_swf_4` | ✓ | ✓ | ✓ |
| [0X0F](#0x0f-actionless) | [ActionLess](#0x0f-actionless) | `less_floats_false_swf_4` | ✓ | ✓ | ✓ |
| [0X0F](#0x0f-actionless) | [ActionLess](#0x0f-actionless) | `less_floats_swf_4` | ✓ | ✓ | ✓ |
| [0X10](#0x10-actionand) | [ActionAnd](#0x10-actionand) | `and_floats_both_0_swf_4` | ✓ | ✓ | ✓ |
| [0X10](#0x10-actionand) | [ActionAnd](#0x10-actionand) | `and_floats_first_1_swf_4` | ✓ | ✓ | ✓ |
| [0X10](#0x10-actionand) | [ActionAnd](#0x10-actionand) | `and_floats_nonzero_swf_4` | ✓ | ✓ | ✓ |
| [0X10](#0x10-actionand) | [ActionAnd](#0x10-actionand) | `and_floats_second_1_swf_4` | ✓ | ✓ | ✓ |
| [0X10](#0x10-actionand) | [ActionAnd](#0x10-actionand) | `and_floats_swf_4` | ✓ | ✓ | ✓ |
| [0X11](#0x11-actionor) | [ActionOr](#0x11-actionor) | `or_swf_4` | ✓ | ✓ | ✓ |
| [0X12](#0x12-actionnot) | [ActionNot](#0x12-actionnot) | `not_floats_nonzero_swf_4` | ✓ | ✓ | ✓ |
| [0X13](#0x13-actionstringequals) | [ActionStringEquals](#0x13-actionstringequals) | `string_equals_0_swf_4` | ✓ | ✓ | ✓ |
| [0X13](#0x13-actionstringequals) | [ActionStringEquals](#0x13-actionstringequals) | `string_equals_1_swf_4` | ✓ | ✓ | ✓ |
| [0X14](#0x14-actionstringlength) | [ActionStringLength](#0x14-actionstringlength) | `string_length_swf_4` | ✓ | ✓ | ✓ |
| [0X15](#0x15-actionstringextract) | [ActionStringExtract](#0x15-actionstringextract) | `string_extract_swf_4` | ✓ | ✓ | ✓ |
| [0X17](#0x17-actionpop) | [ActionPop](#0x17-actionpop) | `pop_swf_4` | ✓ |  | ✓ |
| [0X18](#0x18-actiontointeger) | [ActionToInteger](#0x18-actiontointeger) | `to_integer_swf_4` | ✓ | ✓ | ✓ |
| [0X1C](#0x1c-actiongetvariable) | [ActionGetVariable](#0x1c-actiongetvariable) | `get_variable_swf_4` | ✓ | ✓ | ✓ |
| [0X1D](#0x1d-actionsetvariable) | [ActionSetVariable](#0x1d-actionsetvariable) | `set_variable_swf_4` | ✓ | ✓ | ✓ |
| [0X20](#0x20-actionsettarget2) | [ActionSetTarget2](#0x20-actionsettarget2) | `set_target2_swf_4` | ✓ | ✓ | ✓ |
| [0X21](#0x21-actionstringadd) | [ActionStringAdd](#0x21-actionstringadd) | `string_add_swf_4` | ✓ | ✓ | ✓ |
| [0X22](#0x22-actiongetproperty) | [ActionGetProperty](#0x22-actiongetproperty) | `get_property_swf_4` | ✓ | ✓ | ✓ |
| [0X23](#0x23-actionsetproperty) | [ActionSetProperty](#0x23-actionsetproperty) | `set_property_swf_4` | ✓ | ✓ | ✓ |
| [0X24](#0x24-actionclonesprite) | [ActionCloneSprite](#0x24-actionclonesprite) | `clone_sprite_swf_4` | ✓ | ✓ | ✓ |
| [0X25](#0x25-actionremovesprite) | [ActionRemoveSprite](#0x25-actionremovesprite) | `remove_sprite_swf_4` | ✓ | ✓ | ✓ |
| [0X26](#0x26-actiontrace) | [ActionTrace](#0x26-actiontrace) | `trace_swf_4` | ✓ | ✓ | ✓ |
| [0X27](#0x27-actionstartdrag) | [ActionStartDrag](#0x27-actionstartdrag) | `start_drag_swf_4` | ✓ | ✓ | ✓ |
| [0X28](#0x28-actionenddrag) | [ActionEndDrag](#0x28-actionenddrag) | `end_drag_swf_4` | ✓ | ✓ | ✓ |
| [0X29](#0x29-actionstringless) | [ActionStringLess](#0x29-actionstringless) | `string_less_swf_4` | ✓ | ✓ | ✓ |
| [0X2A](#0x2a-actionthrow) | [ActionThrow](#0x2a-actionthrow) | `throw_swf_7` | ✓ | ✓ | ✓ |
| [0X2A](#0x2a-actionthrow) | [ActionThrow](#0x2a-actionthrow) | `try_swf_7` | ✓ | ✓ | ✓ |
| [0X2B](#0x2b-actioncastop) | [ActionCastOp](#0x2b-actioncastop) | `cast_op_swf_7` | ✓ | ✓ | ✓ |
| [0X2C](#0x2c-actionimplementsop) | [ActionImplementsOp](#0x2c-actionimplementsop) | `implements_op_swf_7` | ✓ | ✓ | ✓ |
| [0X30](#0x30-actionrandomnumber) | [ActionRandomNumber](#0x30-actionrandomnumber) | `random_number_swf_4` | ✓ | ✓ | ✓ |
| [0X31](#0x31-actionmbstringlength) | [ActionMBStringLength](#0x31-actionmbstringlength) | `mb_string_length_swf_5` | ✓ | ✓ | ✓ |
| [0X32](#0x32-actionchartoascii) | [ActionCharToAscii](#0x32-actionchartoascii) | `char_to_ascii_swf_4` | ✓ | ✓ | ✓ |
| [0X33](#0x33-actionasciitochar) | [ActionAsciiToChar](#0x33-actionasciitochar) | `ascii_to_char_swf_4` | ✓ | ✓ | ✓ |
| [0X34](#0x34-actiongettime) | [ActionGetTime](#0x34-actiongettime) | `get_time_swf_5` | ✓ | ✓ | ✓ |
| [0X35](#0x35-actionmbstringextract) | [ActionMBStringExtract](#0x35-actionmbstringextract) | `mb_string_extract_swf_5` | ✓ | ✓ | ✓ |
| [0X36](#0x36-actionmbchartoascii) | [ActionMBCharToAscii](#0x36-actionmbchartoascii) | `mb_char_to_ascii_swf_5` | ✓ | ✓ | ✓ |
| [0X37](#0x37-actionmbasciitochar) | [ActionMBAsciiToChar](#0x37-actionmbasciitochar) | `mb_ascii_to_char_edge_cases_swf_4` | ✓ | ✓ | ✓ |
| [0X37](#0x37-actionmbasciitochar) | [ActionMBAsciiToChar](#0x37-actionmbasciitochar) | `mb_ascii_to_char_swf_4` | ✓ | ✓ | ✓ |
| [0X37](#0x37-actionmbasciitochar) | [ActionMBAsciiToChar](#0x37-actionmbasciitochar) | `mb_ascii_to_char_swf_5` | ✓ | ✓ | ✓ |
| [0X3A](#0x3a-actiondelete) | [ActionDelete](#0x3a-actiondelete) | `delete_swf_5` | ✓ | ✓ | ✓ |
| [0X3B](#0x3b-actiondelete2) | [ActionDelete2](#0x3b-actiondelete2) | `delete2_swf_5` | ✓ | ✓ | ✓ |
| [0X3C](#0x3c-actiondefinelocal) | [ActionDefineLocal](#0x3c-actiondefinelocal) | `definelocal_swf_5` | ✓ | ✓ | ✓ |
| [0X3D](#0x3d-actionstackswap) | [ActionStackSwap](#0x3d-actionstackswap) | `call_function_swf_5` | ✓ | ✓ | ✓ |
| [0X3E](#0x3e-actionreturn) | [ActionReturn](#0x3e-actionreturn) | `return_swf_4` | ✓ | ✓ | ✓ |
| [0X3F](#0x3f-actionmodulo) | [ActionModulo](#0x3f-actionmodulo) | `modulo_swf_4` | ✓ | ✓ | ✓ |
| [0X40](#0x40-actionnewobject) | [ActionNewObject](#0x40-actionnewobject) | `new_object_swf_4` | ✓ | ✓ | ✓ |
| [0X41](#0x41-actiondefinelocal2) | [ActionDefineLocal2](#0x41-actiondefinelocal2) | `declare_local_swf_5` | ✓ | ✓ | ✓ |
| [0X42](#0x42-actioninitarray) | [ActionInitArray](#0x42-actioninitarray) | `init_array_swf_4` | ✓ | ✓ | ✓ |
| [0X43](#0x43-actioninitobject) | [ActionInitObject](#0x43-actioninitobject) | `init_object_swf_4` | ✓ | ✓ | ✓ |
| [0X44](#0x44-actiontypeof) | [ActionTypeOf](#0x44-actiontypeof) | `typeof_swf_5` | ✓ | ✓ | ✓ |
| [0X45](#0x45-actiontargetpath) | [ActionTargetPath](#0x45-actiontargetpath) | `target_path_swf_5` | ✓ | ✓ | ✓ |
| [0X46](#0x46-actionenumerate) | [ActionEnumerate](#0x46-actionenumerate) | `enumerate_swf_4` | ✓ | ✓ | ✓ |
| [0X47](#0x47-actionadd2) | [ActionAdd2](#0x47-actionadd2) | `add2_swf_5` | ✓ | ✓ | ✓ |
| [0X48](#0x48-actionless2) | [ActionLess2](#0x48-actionless2) | `less2_swf_4` | ✓ | ✓ | ✓ |
| [0X49](#0x49-actionequals2) | [ActionEquals2](#0x49-actionequals2) | `equals2_swf_5` | ✓ | ✓ | ✓ |
| [0X4A](#0x4a-actiontonumber) | [ActionToNumber](#0x4a-actiontonumber) | `to_number_swf_4` | ✓ | ✓ | ✓ |
| [0X4B](#0x4b-actiontostring) | [ActionToString](#0x4b-actiontostring) | `to_string_swf_4` | ✓ | ✓ | ✓ |
| [0X4C](#0x4c-actionpushduplicate) | [ActionPushDuplicate](#0x4c-actionpushduplicate) | `duplicate_swf_4` | ✓ | ✓ | ✓ |
| [0X4D](#0x4d-actionstackswap) | [ActionStackSwap](#0x4d-actionstackswap) | `stack_swap_swf_4` | ✓ | ✓ | ✓ |
| [0X4E](#0x4e-actiongetmember) | [ActionGetMember](#0x4e-actiongetmember) | `get_member_swf_4` | ✓ | ✓ | ✓ |
| [0X4F](#0x4f-actionsetmember) | [ActionSetMember](#0x4f-actionsetmember) | `set_member_swf_5` | ✓ | ✓ | ✓ |
| [0X50](#0x50-actionincrement) | [ActionIncrement](#0x50-actionincrement) | `increment_swf_4` | ✓ | ✓ | ✓ |
| [0X51](#0x51-actiondecrement) | [ActionDecrement](#0x51-actiondecrement) | `decrement_swf_4` | ✓ | ✓ | ✓ |
| [0X52](#0x52-actioncallmethod) | [ActionCallMethod](#0x52-actioncallmethod) | `call_method_empty_name_swf_5` | ✓ | ✓ | ✓ |
| [0X52](#0x52-actioncallmethod) | [ActionCallMethod](#0x52-actioncallmethod) | `call_method_swf_5` | ✓ | ✓ | ✓ |
| [0X53](#0x53-actionnewmethod) | [ActionNewMethod](#0x53-actionnewmethod) | `new_method_swf_5` | ✓ | ✓ | ✓ |
| [0X54](#0x54-actioninstanceof) | [ActionInstanceOf](#0x54-actioninstanceof) | `instanceof_swf_6` | ✓ | ✓ | ✓ |
| [0X55](#0x55-actionenumerate2) | [ActionEnumerate2](#0x55-actionenumerate2) | `enumerate2_swf_6` | ✓ | ✓ | ✓ |
| [0X60](#0x60-actionbitand) | [ActionBitAnd](#0x60-actionbitand) | `bit_and_swf_4` | ✓ | ✓ | ✓ |
| [0X61](#0x61-actionbitor) | [ActionBitOr](#0x61-actionbitor) | `bit_or_swf_4` | ✓ | ✓ | ✓ |
| [0X62](#0x62-actionbitxor) | [ActionBitXor](#0x62-actionbitxor) | `bit_xor_swf_4` | ✓ | ✓ | ✓ |
| [0X63](#0x63-actionbitlshift) | [ActionBitLShift](#0x63-actionbitlshift) | `bit_lshift_swf_4` | ✓ | ✓ | ✓ |
| [0X64](#0x64-actionbitrshift) | [ActionBitRShift](#0x64-actionbitrshift) | `bit_rshift_swf_4` | ✓ | ✓ | ✓ |
| [0X65](#0x65-actionbiturshift) | [ActionBitURShift](#0x65-actionbiturshift) | `bit_urshift_swf_4` | ✓ | ✓ | ✓ |
| [0X66](#0x66-actionstrictequals) | [ActionStrictEquals](#0x66-actionstrictequals) | `strict_equals_swf_4` | ✓ | ✓ | ✓ |
| [0X67](#0x67-actiongreater) | [ActionGreater](#0x67-actiongreater) | `greater_swf_4` | ✓ | ✓ | ✓ |
| [0X68](#0x68-actionstringgreater) | [ActionStringGreater](#0x68-actionstringgreater) | `string_greater_swf_4` | ✓ | ✓ | ✓ |
| [0X69](#0x69-actionextends) | [ActionExtends](#0x69-actionextends) | `extends_swf_7` | ✓ | ✓ | ✓ |
| [0X81](#0x81-actiongotoframe) | [ActionGotoFrame](#0x81-actiongotoframe) | `goto_frame_swf_3` | ✓ | ✓ | ✓ |
| [0X83](#0x83-actiongeturl) | [ActionGetURL](#0x83-actiongeturl) | `get_url_swf_3` | ✓ | ✓ | ✓ |
| [0X87](#0x87-actionstoreregister) | [ActionStoreRegister](#0x87-actionstoreregister) | `store_register_swf_4` | ✓ | ✓ | ✓ |
| [0X88](#0x88-actionconstantpool) | [ActionConstantPool](#0x88-actionconstantpool) | `constant_pool_large_swf_5` | ✓ |  | ✓ |
| [0X88](#0x88-actionconstantpool) | [ActionConstantPool](#0x88-actionconstantpool) | `constant_pool_nonseq_swf_5` | ✓ |  | ✓ |
| [0X88](#0x88-actionconstantpool) | [ActionConstantPool](#0x88-actionconstantpool) | `constant_pool_repeated_swf_5` | ✓ |  | ✓ |
| [0X88](#0x88-actionconstantpool) | [ActionConstantPool](#0x88-actionconstantpool) | `constant_pool_swf_5` | ✓ |  | ✓ |
| [0X8A](#0x8a-actionwaitforframe) | [ActionWaitForFrame](#0x8a-actionwaitforframe) | `wait_for_frame_swf_3` | ✓ |  | ✓ |
| [0X8B](#0x8b-actionsettarget) | [ActionSetTarget](#0x8b-actionsettarget) | `set_target_swf_3` | ✓ | ✓ | ✓ |
| [0X8C](#0x8c-actiongotolabel) | [ActionGoToLabel](#0x8c-actiongotolabel) | `goto_label_swf_3` | ✓ | ✓ | ✓ |
| [0X8D](#0x8d-actionwaitforframe2) | [ActionWaitForFrame2](#0x8d-actionwaitforframe2) | `wait_for_frame2_swf_4` | ✓ |  | ✓ |
| [0X8E](#0x8e-actiondefinefunction2) | [ActionDefineFunction2](#0x8e-actiondefinefunction2) | `call_method_empty_name_swf_5` | ✓ | ✓ | ✓ |
| [0X8E](#0x8e-actiondefinefunction2) | [ActionDefineFunction2](#0x8e-actiondefinefunction2) | `define_function2_swf_7` | ✓ | ✓ | ✓ |
| [0X8F](#0x8f-actiontry) | [ActionTry](#0x8f-actiontry) | `try_swf_7` | ✓ |  | ✓ |
| [0X94](#0x94-actionwith) | [ActionWith](#0x94-actionwith) | `with_swf_5` | ✓ |  | ✓ |
| [0X96](#0x96-actionpush) | [ActionPush](#0x96-actionpush) | `push_swf_4` | ✓ |  | ✓ |
| [0X99](#0x99-actionjump) | [ActionJump](#0x99-actionjump) | `jump_swf_4` | ✓ |  | ✓ |
| [0X9A](#0x9a-actiongeturl2) | [ActionGetURL2](#0x9a-actiongeturl2) | `get_url2_swf_4` | ✓ | ✓ | ✓ |
| [0X9B](#0x9b-actiondefinefunction) | [ActionDefineFunction](#0x9b-actiondefinefunction) | `define_function_swf_5` | ✓ |  | ✓ |
| [0X9D](#0x9d-actionif) | [ActionIf](#0x9d-actionif) | `if_false_swf_4` | ✓ |  | ✓ |
| [0X9D](#0x9d-actionif) | [ActionIf](#0x9d-actionif) | `if_swf_4` | ✓ |  | ✓ |
| [0X9E](#0x9e-actioncall) | [ActionCall](#0x9e-actioncall) | `call_swf_4` | ✓ | ✓ | ✓ |
| [0X9F](#0x9f-actiongotoframe2) | [ActionGotoFrame2](#0x9f-actiongotoframe2) | `gotoframe2_swf_5` | ✓ | ✓ | ✓ |

## Failing Primary Tests

**No failing primary tests! 🎉**

## Implementation Status

### ✅ Fully Implemented
(Opcodes marked as fully_implemented in test_info.json)

| Hex | Spec Name | Enum | Function | Primary Tests | Failing Primary | Docs | No Graphics |
|-----|-----------|------|----------|---------------|-----------------|------|-------------|
| [0X04](#0x04-actionnextframe) | [ActionNextFrame](#0x04-actionnextframe) | ✓ | ✓ | 1/1 |  | ✓ | ✓ |
| [0X05](#0x05-actionpreviousframe) | [ActionPreviousFrame](#0x05-actionpreviousframe) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X06](#0x06-actionplay) | [ActionPlay](#0x06-actionplay) | ✓ | ✓ | 2/2 |  | ✓ | ✓ |
| [0X07](#0x07-actionstop) | [ActionStop](#0x07-actionstop) | ✓ |  | 3/3 |  | ✓ |  |
| [0X0A](#0x0a-actionadd) | [ActionAdd](#0x0a-actionadd) | ✓ | ✓ | 2/2 |  | ✓ |  |
| [0X0B](#0x0b-actionsubtract) | [ActionSubtract](#0x0b-actionsubtract) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X0C](#0x0c-actionmultiply) | [ActionMultiply](#0x0c-actionmultiply) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X0D](#0x0d-actiondivide) | [ActionDivide](#0x0d-actiondivide) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X0E](#0x0e-actionequals) | [ActionEquals](#0x0e-actionequals) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X0F](#0x0f-actionless) | [ActionLess](#0x0f-actionless) | ✓ | ✓ | 2/2 |  | ✓ |  |
| [0X10](#0x10-actionand) | [ActionAnd](#0x10-actionand) | ✓ | ✓ | 5/5 |  | ✓ |  |
| [0X11](#0x11-actionor) | [ActionOr](#0x11-actionor) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X12](#0x12-actionnot) | [ActionNot](#0x12-actionnot) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X13](#0x13-actionstringequals) | [ActionStringEquals](#0x13-actionstringequals) | ✓ | ✓ | 2/2 |  | ✓ |  |
| [0X14](#0x14-actionstringlength) | [ActionStringLength](#0x14-actionstringlength) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X15](#0x15-actionstringextract) | [ActionStringExtract](#0x15-actionstringextract) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X17](#0x17-actionpop) | [ActionPop](#0x17-actionpop) | ✓ |  | 1/1 |  | ✓ |  |
| [0X18](#0x18-actiontointeger) | [ActionToInteger](#0x18-actiontointeger) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X1C](#0x1c-actiongetvariable) | [ActionGetVariable](#0x1c-actiongetvariable) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X1D](#0x1d-actionsetvariable) | [ActionSetVariable](#0x1d-actionsetvariable) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X21](#0x21-actionstringadd) | [ActionStringAdd](#0x21-actionstringadd) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X22](#0x22-actiongetproperty) | [ActionGetProperty](#0x22-actiongetproperty) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X26](#0x26-actiontrace) | [ActionTrace](#0x26-actiontrace) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X29](#0x29-actionstringless) | [ActionStringLess](#0x29-actionstringless) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X2A](#0x2a-actionthrow) | [ActionThrow](#0x2a-actionthrow) | ✓ | ✓ | 2/2 |  | ✓ |  |
| [0X2B](#0x2b-actioncastop) | [ActionCastOp](#0x2b-actioncastop) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X2C](#0x2c-actionimplementsop) | [ActionImplementsOp](#0x2c-actionimplementsop) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X30](#0x30-actionrandomnumber) | [ActionRandomNumber](#0x30-actionrandomnumber) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X31](#0x31-actionmbstringlength) | [ActionMBStringLength](#0x31-actionmbstringlength) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X32](#0x32-actionchartoascii) | [ActionCharToAscii](#0x32-actionchartoascii) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X33](#0x33-actionasciitochar) | [ActionAsciiToChar](#0x33-actionasciitochar) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X34](#0x34-actiongettime) | [ActionGetTime](#0x34-actiongettime) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X35](#0x35-actionmbstringextract) | [ActionMBStringExtract](#0x35-actionmbstringextract) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X36](#0x36-actionmbchartoascii) | [ActionMBCharToAscii](#0x36-actionmbchartoascii) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X37](#0x37-actionmbasciitochar) | [ActionMBAsciiToChar](#0x37-actionmbasciitochar) | ✓ | ✓ | 3/3 |  | ✓ |  |
| [0X3A](#0x3a-actiondelete) | [ActionDelete](#0x3a-actiondelete) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X3B](#0x3b-actiondelete2) | [ActionDelete2](#0x3b-actiondelete2) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X3C](#0x3c-actiondefinelocal) | [ActionDefineLocal](#0x3c-actiondefinelocal) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X3D](#0x3d-actionstackswap) | [ActionStackSwap](#0x3d-actionstackswap) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X3E](#0x3e-actionreturn) | [ActionReturn](#0x3e-actionreturn) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X3F](#0x3f-actionmodulo) | [ActionModulo](#0x3f-actionmodulo) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X40](#0x40-actionnewobject) | [ActionNewObject](#0x40-actionnewobject) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X41](#0x41-actiondefinelocal2) | [ActionDefineLocal2](#0x41-actiondefinelocal2) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X42](#0x42-actioninitarray) | [ActionInitArray](#0x42-actioninitarray) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X43](#0x43-actioninitobject) | [ActionInitObject](#0x43-actioninitobject) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X44](#0x44-actiontypeof) | [ActionTypeOf](#0x44-actiontypeof) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X45](#0x45-actiontargetpath) | [ActionTargetPath](#0x45-actiontargetpath) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X46](#0x46-actionenumerate) | [ActionEnumerate](#0x46-actionenumerate) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X47](#0x47-actionadd2) | [ActionAdd2](#0x47-actionadd2) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X48](#0x48-actionless2) | [ActionLess2](#0x48-actionless2) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X49](#0x49-actionequals2) | [ActionEquals2](#0x49-actionequals2) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X4A](#0x4a-actiontonumber) | [ActionToNumber](#0x4a-actiontonumber) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X4B](#0x4b-actiontostring) | [ActionToString](#0x4b-actiontostring) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X4C](#0x4c-actionpushduplicate) | [ActionPushDuplicate](#0x4c-actionpushduplicate) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X4D](#0x4d-actionstackswap) | [ActionStackSwap](#0x4d-actionstackswap) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X4E](#0x4e-actiongetmember) | [ActionGetMember](#0x4e-actiongetmember) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X4F](#0x4f-actionsetmember) | [ActionSetMember](#0x4f-actionsetmember) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X50](#0x50-actionincrement) | [ActionIncrement](#0x50-actionincrement) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X51](#0x51-actiondecrement) | [ActionDecrement](#0x51-actiondecrement) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X52](#0x52-actioncallmethod) | [ActionCallMethod](#0x52-actioncallmethod) | ✓ | ✓ | 2/2 |  | ✓ |  |
| [0X53](#0x53-actionnewmethod) | [ActionNewMethod](#0x53-actionnewmethod) | ✓ | ✓ | 1/1 |  | ✓ | ✓ |
| [0X54](#0x54-actioninstanceof) | [ActionInstanceOf](#0x54-actioninstanceof) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X55](#0x55-actionenumerate2) | [ActionEnumerate2](#0x55-actionenumerate2) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X60](#0x60-actionbitand) | [ActionBitAnd](#0x60-actionbitand) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X61](#0x61-actionbitor) | [ActionBitOr](#0x61-actionbitor) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X62](#0x62-actionbitxor) | [ActionBitXor](#0x62-actionbitxor) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X63](#0x63-actionbitlshift) | [ActionBitLShift](#0x63-actionbitlshift) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X64](#0x64-actionbitrshift) | [ActionBitRShift](#0x64-actionbitrshift) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X65](#0x65-actionbiturshift) | [ActionBitURShift](#0x65-actionbiturshift) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X66](#0x66-actionstrictequals) | [ActionStrictEquals](#0x66-actionstrictequals) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X67](#0x67-actiongreater) | [ActionGreater](#0x67-actiongreater) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X68](#0x68-actionstringgreater) | [ActionStringGreater](#0x68-actionstringgreater) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X69](#0x69-actionextends) | [ActionExtends](#0x69-actionextends) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X87](#0x87-actionstoreregister) | [ActionStoreRegister](#0x87-actionstoreregister) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X88](#0x88-actionconstantpool) | [ActionConstantPool](#0x88-actionconstantpool) | ✓ |  | 4/4 |  | ✓ |  |
| [0X8A](#0x8a-actionwaitforframe) | [ActionWaitForFrame](#0x8a-actionwaitforframe) | ✓ |  | 1/1 |  | ✓ |  |
| [0X8C](#0x8c-actiongotolabel) | [ActionGoToLabel](#0x8c-actiongotolabel) | ✓ | ✓ | 1/1 |  | ✓ |  |
| [0X8D](#0x8d-actionwaitforframe2) | [ActionWaitForFrame2](#0x8d-actionwaitforframe2) | ✓ |  | 1/1 |  | ✓ |  |
| [0X8E](#0x8e-actiondefinefunction2) | [ActionDefineFunction2](#0x8e-actiondefinefunction2) | ✓ | ✓ | 2/2 |  | ✓ |  |
| [0X8F](#0x8f-actiontry) | [ActionTry](#0x8f-actiontry) | ✓ |  | 1/1 |  | ✓ |  |
| [0X94](#0x94-actionwith) | [ActionWith](#0x94-actionwith) | ✓ |  | 1/1 |  | ✓ |  |
| [0X96](#0x96-actionpush) | [ActionPush](#0x96-actionpush) | ✓ |  | 1/1 |  | ✓ |  |
| [0X99](#0x99-actionjump) | [ActionJump](#0x99-actionjump) | ✓ |  | 1/1 |  | ✓ |  |
| [0X9B](#0x9b-actiondefinefunction) | [ActionDefineFunction](#0x9b-actiondefinefunction) | ✓ |  | 1/1 |  | ✓ |  |
| [0X9D](#0x9d-actionif) | [ActionIf](#0x9d-actionif) | ✓ |  | 2/2 |  | ✓ |  |

### 🔄 Partially Implemented
(Has enum or function, but not marked as fully implemented)

| Hex | Spec Name | Enum | Function | Docs |
|-----|-----------|------|----------|------|
| 0X00 |  | ✓ |  |  |
| [0X08](#0x08-actiontogglequality) | [ActionToggleQuality](#0x08-actiontogglequality) | ✓ | ✓ | ✓ |
| [0X09](#0x09-actionstopsounds) | [ActionStopSounds](#0x09-actionstopsounds) | ✓ | ✓ | ✓ |
| [0X20](#0x20-actionsettarget2) | [ActionSetTarget2](#0x20-actionsettarget2) | ✓ | ✓ | ✓ |
| [0X23](#0x23-actionsetproperty) | [ActionSetProperty](#0x23-actionsetproperty) | ✓ | ✓ | ✓ |
| [0X24](#0x24-actionclonesprite) | [ActionCloneSprite](#0x24-actionclonesprite) | ✓ | ✓ | ✓ |
| [0X25](#0x25-actionremovesprite) | [ActionRemoveSprite](#0x25-actionremovesprite) | ✓ | ✓ | ✓ |
| [0X27](#0x27-actionstartdrag) | [ActionStartDrag](#0x27-actionstartdrag) | ✓ | ✓ | ✓ |
| [0X28](#0x28-actionenddrag) | [ActionEndDrag](#0x28-actionenddrag) | ✓ | ✓ | ✓ |
| [0X81](#0x81-actiongotoframe) | [ActionGotoFrame](#0x81-actiongotoframe) | ✓ | ✓ | ✓ |
| [0X83](#0x83-actiongeturl) | [ActionGetURL](#0x83-actiongeturl) | ✓ | ✓ | ✓ |
| [0X8B](#0x8b-actionsettarget) | [ActionSetTarget](#0x8b-actionsettarget) | ✓ | ✓ | ✓ |
| [0X9A](#0x9a-actiongeturl2) | [ActionGetURL2](#0x9a-actiongeturl2) | ✓ | ✓ | ✓ |
| [0X9E](#0x9e-actioncall) | [ActionCall](#0x9e-actioncall) | ✓ | ✓ | ✓ |
| [0X9F](#0x9f-actiongotoframe2) | [ActionGotoFrame2](#0x9f-actiongotoframe2) | ✓ | ✓ | ✓ |

### ❌ Not Implemented
(Only in spec, no implementation yet)

| Hex | Spec Name |
|-----|-----------|

## Missing Features

This section lists all missing features for opcodes that are not fully implemented.

### [0X06: ActionPlay](#0x06-actionplay)

**From test `play_swf_4`:**
- SetTarget support: Cannot control individual sprite/MovieClip timelines (requires MovieClip architecture not available in NO_GRAPHICS mode)


### [0X08: ActionToggleQuality](#0x08-actiontogglequality)

**From test `toggle_quality_swf_4`:**
- Graphics rendering not implemented (requires SDL3/Vulkan) - quality toggle has no visible effect in NO_GRAPHICS mode


### [0X20: ActionSetTarget2](#0x20-actionsettarget2)

**From test `set_target2_swf_4`:**
- Timeline control opcodes (Play, Stop, GotoFrame) don't use the current context
- Only root MovieClip is supported (no child sprites or nested clips)
- Target path resolution only supports empty string, _root, and / (all resolve to root)
- Non-existent targets are silently ignored (context unchanged)
- Advanced path syntax not supported: dot notation (sprite1.sprite2), relative paths (../sprite), special targets (_parent, this)


### [0X24: ActionCloneSprite](#0x24-actionclonesprite)

**From test `clone_sprite_swf_4`:**
- Graphics rendering not implemented (requires display list and MovieClip infrastructure)
- Actual sprite cloning only works with graphics support - NO_GRAPHICS mode validates parameters only


### [0X25: ActionRemoveSprite](#0x25-actionremovesprite)

**From test `remove_sprite_swf_4`:**
- Graphics mode: Display list management system not implemented
- Graphics mode: MovieClip reference counting not implemented
- Graphics mode: Actual sprite removal and resource cleanup requires SDL3/Vulkan rendering


### [0X28: ActionEndDrag](#0x28-actionenddrag)

**From test `end_drag_swf_4`:**
- Graphics rendering: actual sprite/MovieClip drag visualization requires SDL3/Vulkan
- Mouse interaction: drag positioning based on mouse input requires graphics mode
- Display list integration: finding and updating sprites in the display list


### [0X2A: ActionThrow](#0x2a-actionthrow)

**From test `throw_swf_7`:**
- Try-catch integration has known implementation flaw - setjmp/longjmp called from helper function instead of inline
- Stack unwinding to catch blocks doesn't work correctly (execution continues after longjmp)
- Finally block execution during unwinding not tested
- Nested try-catch blocks not tested
- Exception propagation through function calls not tested
- Only tested uncaught exceptions (requires ActionTry 0x8F for full testing)


### [0X81: ActionGotoFrame](#0x81-actiongotoframe)

**From test `goto_frame_swf_3`:**
- Display list updates on frame change (graphics-only feature, requires SDL3/Vulkan rendering)


### [0X83: ActionGetURL](#0x83-actiongeturl)

**From test `get_url_swf_3`:**
- Actual URL loading (requires browser integration or HTTP client)
- SWF file loading into _level targets (requires SWF loader and level management)
- Browser frame/window management (requires browser API)
- JavaScript URL execution (requires JavaScript bridge)
- Cross-domain security policy enforcement
- URL scheme validation and sanitization


### [0X8B: ActionSetTarget](#0x8b-actionsettarget)

**From test `set_target_swf_3`:**
- MovieClip hierarchy (named sprites, nested clips) requires display list infrastructure available only in graphics mode
- In NO_GRAPHICS mode, only _root is available as a valid target - all other target names are treated as 'not found'


### [0X9A: ActionGetURL2](#0x9a-actiongeturl2)

**From test `get_url2_swf_4`:**
- Actual HTTP client functionality (requires libcurl or similar HTTP library)
- Variable encoding to x-www-form-urlencoded format (requires variable enumeration)
- HTTP response parsing (requires HTTP client and response parser)
- Setting variables in target scope from response (requires full variable/scope management)
- SWF file downloading and loading (requires HTTP client and SWF parser/loader)
- MovieClip/sprite path resolution and management (requires full sprite hierarchy)
- Browser window integration (requires platform-specific OS APIs)
- Cross-domain security policy enforcement (requires security sandbox infrastructure)


### [0X9E: ActionCall](#0x9e-actioncall)

**From test `call_swf_4`:**
- Frame label registry (requires SWFRecomp to parse FrameLabel tag 43 and generate label->frame mapping - graphics-only)
- MovieClip tree for target paths (requires full MovieClip infrastructure - graphics-only)
- Multi-MovieClip support (requires MovieClip context switching - graphics-only)


### [0X9F: ActionGotoFrame2](#0x9f-actiongotoframe2)

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
- [✓] `SWFRecomp/tests/add_floats_swf_4`
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
- [✓] `SWFRecomp/tests/add_floats_swf_4`
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
- [SWFRecompDocs/prompts/completed/opcode-call-function-0x3d.md](SWFRecompDocs/prompts/completed/opcode-call-function-0x3d.md)

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
- [SWFRecompDocs/prompts/completed/opcode-greater-0x48.md](SWFRecompDocs/prompts/completed/opcode-greater-0x48.md)

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
- [✓] `SWFRecomp/tests/add_floats_swf_4`
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
