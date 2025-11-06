# AS2 Opcode Index

**Generated**: 2025-11-06

**Total Opcodes**: 102

**Implemented Opcodes**: 21

**Total Entries**: 230

## Summary Table

| Hex | Spec Name | Enum Name | Function Name | Tests | Docs | Branch |
|-----|-----------|-----------|---------------|-------|------|--------|
| 0X00 |  | SWF_ACTION_END_OF_ACTIONS |  |  |  |  |
| [0X04](#0x04-actionnextframe) | [ActionNextFrame](#0x04-actionnextframe) |  |  |  | ✓ |  |
| [0X05](#0x05-actionpreviousframe) | [ActionPreviousFrame](#0x05-actionpreviousframe) |  |  |  | ✓ |  |
| [0X06](#0x06-actionplay) | [ActionPlay](#0x06-actionplay) |  |  |  | ✓ |  |
| [0X07](#0x07-actionstop) | [ActionStop](#0x07-actionstop) | [SWF_ACTION_STOP](#0x07-actionstop) |  |  | ✓ |  |
| [0X08](#0x08-actiontogglequality) | [ActionToggleQuality](#0x08-actiontogglequality) |  |  |  | ✓ |  |
| [0X09](#0x09-actionstopsounds) | [ActionStopSounds](#0x09-actionstopsounds) |  |  |  | ✓ |  |
| [0X0A](#0x0a-actionadd) | [ActionAdd](#0x0a-actionadd) | [SWF_ACTION_ADD](#0x0a-actionadd) | [actionAdd](#0x0a-actionadd) |  |  |  |
| [0X0B](#0x0b-actionsubtract) | [ActionSubtract](#0x0b-actionsubtract) | [SWF_ACTION_SUBTRACT](#0x0b-actionsubtract) | [actionSubtract](#0x0b-actionsubtract) |  |  |  |
| [0X0C](#0x0c-actionmultiply) | [ActionMultiply](#0x0c-actionmultiply) | [SWF_ACTION_MULTIPLY](#0x0c-actionmultiply) | [actionMultiply](#0x0c-actionmultiply) |  |  |  |
| [0X0D](#0x0d-actiondivide) | [ActionDivide](#0x0d-actiondivide) | [SWF_ACTION_DIVIDE](#0x0d-actiondivide) | [actionDivide](#0x0d-actiondivide) |  |  |  |
| [0X0E](#0x0e-actionequals) | [ActionEquals](#0x0e-actionequals) | [SWF_ACTION_EQUALS](#0x0e-actionequals) | [actionEquals](#0x0e-actionequals) |  |  |  |
| [0X0F](#0x0f-actionless) | [ActionLess](#0x0f-actionless) | [SWF_ACTION_LESS](#0x0f-actionless) | [actionLess](#0x0f-actionless) |  |  |  |
| [0X10](#0x10-actionand) | [ActionAnd](#0x10-actionand) | [SWF_ACTION_AND](#0x10-actionand) | [actionAnd](#0x10-actionand) |  |  |  |
| [0X11](#0x11-actionor) | [ActionOr](#0x11-actionor) | [SWF_ACTION_OR](#0x11-actionor) | [actionOr](#0x11-actionor) |  |  |  |
| [0X12](#0x12-actionnot) | [ActionNot](#0x12-actionnot) | [SWF_ACTION_NOT](#0x12-actionnot) | [actionNot](#0x12-actionnot) |  |  |  |
| [0X13](#0x13-actionstringequals) | [ActionStringEquals](#0x13-actionstringequals) | [SWF_ACTION_STRING_EQUALS](#0x13-actionstringequals) | [actionStringEquals](#0x13-actionstringequals) |  |  |  |
| [0X14](#0x14-actionstringlength) | [ActionStringLength](#0x14-actionstringlength) | [SWF_ACTION_STRING_LENGTH](#0x14-actionstringlength) | [actionStringLength](#0x14-actionstringlength) |  |  |  |
| [0X15](#0x15-actionstringextract) | [ActionStringExtract](#0x15-actionstringextract) | [SWF_ACTION_STRING_EXTRACT](#0x15-actionstringextract) | [actionStringExtract](#0x15-actionstringextract) |  | ✓ | ✓ |
| [0X17](#0x17-actionpop) | [ActionPop](#0x17-actionpop) | [SWF_ACTION_POP](#0x17-actionpop) |  |  |  |  |
| [0X18](#0x18-actiontointeger) | [ActionToInteger](#0x18-actiontointeger) | [SWF_ACTION_TO_INTEGER](#0x18-actiontointeger) | [actionToInteger](#0x18-actiontointeger) |  | ✓ |  |
| [0X1C](#0x1c-actiongetvariable) | [ActionGetVariable](#0x1c-actiongetvariable) | [SWF_ACTION_GET_VARIABLE](#0x1c-actiongetvariable) | [actionGetVariable](#0x1c-actiongetvariable) |  |  |  |
| [0X1D](#0x1d-actionsetvariable) | [ActionSetVariable](#0x1d-actionsetvariable) | [SWF_ACTION_SET_VARIABLE](#0x1d-actionsetvariable) | [actionSetVariable](#0x1d-actionsetvariable) |  |  |  |
| [0X20](#0x20-actionsettarget2) | [ActionSetTarget2](#0x20-actionsettarget2) |  |  |  |  |  |
| [0X21](#0x21-actionstringadd) | [ActionStringAdd](#0x21-actionstringadd) | [SWF_ACTION_STRING_ADD](#0x21-actionstringadd) | [actionStringAdd](#0x21-actionstringadd) |  |  |  |
| [0X22](#0x22-actiongetproperty) | [ActionGetProperty](#0x22-actiongetproperty) | [SWF_ACTION_GET_PROPERTY](#0x22-actiongetproperty) | [actionGetProperty](#0x22-actiongetproperty) |  | ✓ | ✓ |
| [0X23](#0x23-actionsetproperty) | [ActionSetProperty](#0x23-actionsetproperty) | [SWF_ACTION_SET_PROPERTY](#0x23-actionsetproperty) | [actionSetProperty](#0x23-actionsetproperty) |  | ✓ | ✓ |
| [0X24](#0x24-actionclonesprite) | [ActionCloneSprite](#0x24-actionclonesprite) |  |  |  | ✓ |  |
| [0X25](#0x25-actionremovesprite) | [ActionRemoveSprite](#0x25-actionremovesprite) |  |  |  | ✓ |  |
| [0X26](#0x26-actiontrace) | [ActionTrace](#0x26-actiontrace) | [SWF_ACTION_TRACE](#0x26-actiontrace) | [actionTrace](#0x26-actiontrace) | 1 |  |  |
| [0X27](#0x27-actionstartdrag) | [ActionStartDrag](#0x27-actionstartdrag) |  |  |  | ✓ |  |
| [0X28](#0x28-actionenddrag) | [ActionEndDrag](#0x28-actionenddrag) |  |  |  | ✓ |  |
| [0X29](#0x29-actionstringless) | [ActionStringLess](#0x29-actionstringless) | [SWF_ACTION_STRING_LESS](#0x29-actionstringless) | [actionStringLess](#0x29-actionstringless) |  | ✓ | ✓ |
| [0X2A](#0x2a-actionthrow) | [ActionThrow](#0x2a-actionthrow) |  |  |  | ✓ |  |
| [0X2B](#0x2b-actioncastop) | [ActionCastOp](#0x2b-actioncastop) |  |  |  | ✓ |  |
| [0X2C](#0x2c-actionimplementsop) | [ActionImplementsOp](#0x2c-actionimplementsop) |  |  |  | ✓ |  |
| [0X30](#0x30-actionrandomnumber) | [ActionRandomNumber](#0x30-actionrandomnumber) | [SWF_ACTION_RANDOM_NUMBER](#0x30-actionrandomnumber) | [actionRandomNumber](#0x30-actionrandomnumber) |  | ✓ |  |
| [0X31](#0x31-actionmbstringlength) | [ActionMBStringLength](#0x31-actionmbstringlength) | [SWF_ACTION_CHAR_TO_ASCII](#0x31-actionmbstringlength) |  |  | ✓ | ✓ |
| [0X32](#0x32-actionchartoascii) | [ActionCharToAscii](#0x32-actionchartoascii) | [SWF_ACTION_ASCII_TO_CHAR](#0x32-actionchartoascii) | [actionCharToAscii](#0x32-actionchartoascii) |  | ✓ | ✓ |
| [0X33](#0x33-actionasciitochar) | [ActionAsciiToChar](#0x33-actionasciitochar) | [SWF_ACTION_MB_CHAR_TO_ASCII](#0x33-actionasciitochar) | [actionAsciiToChar](#0x33-actionasciitochar) |  | ✓ | ✓ |
| [0X34](#0x34-actiongettime) | [ActionGetTime](#0x34-actiongettime) | [SWF_ACTION_GET_TIME](#0x34-actiongettime) | [actionGetTime](#0x34-actiongettime) |  |  |  |
| [0X35](#0x35-actionmbstringextract) | [ActionMBStringExtract](#0x35-actionmbstringextract) | [SWF_ACTION_MB_STRING_LENGTH](#0x35-actionmbstringextract) |  |  | ✓ | ✓ |
| [0X36](#0x36-actionmbchartoascii) | [ActionMBCharToAscii](#0x36-actionmbchartoascii) | [SWF_ACTION_MB_ASCII_TO_CHAR](#0x36-actionmbchartoascii) |  |  | ✓ | ✓ |
| [0X37](#0x37-actionmbasciitochar) | [ActionMBAsciiToChar](#0x37-actionmbasciitochar) |  |  |  |  |  |
| [0X3A](#0x3a-actiondelete) | [ActionDelete](#0x3a-actiondelete) |  | [actionDelete](#0x3a-actiondelete) | 1 |  |  |
| [0X3B](#0x3b-actiondelete2) | [ActionDelete2](#0x3b-actiondelete2) |  | [actionDelete2](#0x3b-actiondelete2) | 1 |  |  |
| [0X3C](#0x3c-actiondefinelocal) | [ActionDefineLocal](#0x3c-actiondefinelocal) | [SWF_ACTION_TYPEOF](#0x3c-actiondefinelocal) |  | 1 | ✓ | ✓ |
| [0X3D](#0x3d-actionstackswap) | [ActionStackSwap](#0x3d-actionstackswap) | [SWF_ACTION_CALL_FUNCTION](#0x3d-actionstackswap) | [actionStackSwap](#0x3d-actionstackswap) |  | ✓ | ✓ |
| [0X3E](#0x3e-actionreturn) | [ActionReturn](#0x3e-actionreturn) | [SWF_ACTION_RETURN](#0x3e-actionreturn) | [actionReturn](#0x3e-actionreturn) | 1 | ✓ | ✓ |
| [0X3F](#0x3f-actionmodulo) | [ActionModulo](#0x3f-actionmodulo) | [SWF_ACTION_MODULO](#0x3f-actionmodulo) | [actionModulo](#0x3f-actionmodulo) | 1 |  |  |
| [0X40](#0x40-actionnewobject) | [ActionNewObject](#0x40-actionnewobject) | [SWF_ACTION_NEW_OBJECT](#0x40-actionnewobject) | [actionNewObject](#0x40-actionnewobject) |  | ✓ | ✓ |
| [0X41](#0x41-actiondefinelocal2) | [ActionDefineLocal2](#0x41-actiondefinelocal2) | [SWF_ACTION_DECLARE_LOCAL](#0x41-actiondefinelocal2) |  |  | ✓ | ✓ |
| [0X42](#0x42-actioninitarray) | [ActionInitArray](#0x42-actioninitarray) | [SWF_ACTION_INIT_ARRAY](#0x42-actioninitarray) | [actionInitArray](#0x42-actioninitarray) |  | ✓ | ✓ |
| [0X43](#0x43-actioninitobject) | [ActionInitObject](#0x43-actioninitobject) | [SWF_ACTION_INIT_OBJECT](#0x43-actioninitobject) | [actionInitObject](#0x43-actioninitobject) |  | ✓ | ✓ |
| [0X44](#0x44-actiontypeof) | [ActionTypeOf](#0x44-actiontypeof) |  |  | 1 |  |  |
| [0X45](#0x45-actiontargetpath) | [ActionTargetPath](#0x45-actiontargetpath) | [SWF_ACTION_TARGET_PATH](#0x45-actiontargetpath) | [actionTargetPath](#0x45-actiontargetpath) |  | ✓ | ✓ |
| [0X46](#0x46-actionenumerate) | [ActionEnumerate](#0x46-actionenumerate) | [SWF_ACTION_ENUMERATE](#0x46-actionenumerate) | [actionEnumerate](#0x46-actionenumerate) | 1 | ✓ | ✓ |
| [0X47](#0x47-actionadd2) | [ActionAdd2](#0x47-actionadd2) | [SWF_ACTION_ADD2](#0x47-actionadd2) | [actionAdd2](#0x47-actionadd2) | 1 | ✓ | ✓ |
| [0X48](#0x48-actionless2) | [ActionLess2](#0x48-actionless2) | [SWF_ACTION_LESS2](#0x48-actionless2) | [actionLess2](#0x48-actionless2) | 1 | ✓ | ✓ |
| [0X49](#0x49-actionequals2) | [ActionEquals2](#0x49-actionequals2) |  |  |  |  |  |
| [0X4A](#0x4a-actiontonumber) | [ActionToNumber](#0x4a-actiontonumber) | [SWF_ACTION_TO_NUMBER](#0x4a-actiontonumber) | [actionToNumber](#0x4a-actiontonumber) |  | ✓ | ✓ |
| [0X4B](#0x4b-actiontostring) | [ActionToString](#0x4b-actiontostring) | [SWF_ACTION_TO_STRING](#0x4b-actiontostring) | [actionToString](#0x4b-actiontostring) |  | ✓ | ✓ |
| [0X4C](#0x4c-actionpushduplicate) | [ActionPushDuplicate](#0x4c-actionpushduplicate) | [SWF_ACTION_DUPLICATE](#0x4c-actionpushduplicate) |  | 1 | ✓ | ✓ |
| [0X4D](#0x4d-actionstackswap) | [ActionStackSwap](#0x4d-actionstackswap) | [SWF_ACTION_STACK_SWAP](#0x4d-actionstackswap) | [actionStackSwap](#0x4d-actionstackswap) |  |  |  |
| [0X4E](#0x4e-actiongetmember) | [ActionGetMember](#0x4e-actiongetmember) | [SWF_ACTION_GET_MEMBER](#0x4e-actiongetmember) | [actionGetMember](#0x4e-actiongetmember) |  | ✓ |  |
| [0X4F](#0x4f-actionsetmember) | [ActionSetMember](#0x4f-actionsetmember) | [SWF_ACTION_SET_MEMBER](#0x4f-actionsetmember) | [actionSetMember](#0x4f-actionsetmember) |  | ✓ | ✓ |
| [0X50](#0x50-actionincrement) | [ActionIncrement](#0x50-actionincrement) | [SWF_ACTION_INCREMENT](#0x50-actionincrement) | [actionIncrement](#0x50-actionincrement) | 1 |  |  |
| [0X51](#0x51-actiondecrement) | [ActionDecrement](#0x51-actiondecrement) | [SWF_ACTION_DECREMENT](#0x51-actiondecrement) | [actionDecrement](#0x51-actiondecrement) | 1 |  |  |
| [0X52](#0x52-actioncallmethod) | [ActionCallMethod](#0x52-actioncallmethod) |  | [actionCallMethod](#0x52-actioncallmethod) |  |  |  |
| [0X53](#0x53-actionnewmethod) | [ActionNewMethod](#0x53-actionnewmethod) | [SWF_ACTION_NEW_METHOD](#0x53-actionnewmethod) | [actionNewMethod](#0x53-actionnewmethod) |  | ✓ | ✓ |
| [0X54](#0x54-actioninstanceof) | [ActionInstanceOf](#0x54-actioninstanceof) |  |  |  |  |  |
| [0X55](#0x55-actionenumerate2) | [ActionEnumerate2](#0x55-actionenumerate2) | [SWF_ACTION_ENUMERATE2](#0x55-actionenumerate2) | [actionEnumerate2](#0x55-actionenumerate2) | 1 | ✓ | ✓ |
| 0X5A |  | SWF_ACTION_DELETE |  |  |  |  |
| 0X5B |  | SWF_ACTION_DELETE2 |  |  |  |  |
| [0X60](#0x60-actionbitand) | [ActionBitAnd](#0x60-actionbitand) | [SWF_ACTION_BIT_AND](#0x60-actionbitand) | [actionBitAnd](#0x60-actionbitand) |  | ✓ | ✓ |
| [0X61](#0x61-actionbitor) | [ActionBitOr](#0x61-actionbitor) | [SWF_ACTION_BIT_OR](#0x61-actionbitor) | [actionBitOr](#0x61-actionbitor) |  | ✓ | ✓ |
| [0X62](#0x62-actionbitxor) | [ActionBitXor](#0x62-actionbitxor) | [SWF_ACTION_BIT_XOR](#0x62-actionbitxor) | [actionBitXor](#0x62-actionbitxor) |  | ✓ | ✓ |
| [0X63](#0x63-actionbitlshift) | [ActionBitLShift](#0x63-actionbitlshift) | [SWF_ACTION_BIT_LSHIFT](#0x63-actionbitlshift) | [actionBitLShift](#0x63-actionbitlshift) |  | ✓ | ✓ |
| [0X64](#0x64-actionbitrshift) | [ActionBitRShift](#0x64-actionbitrshift) | [SWF_ACTION_BIT_RSHIFT](#0x64-actionbitrshift) | [actionBitRShift](#0x64-actionbitrshift) |  | ✓ | ✓ |
| [0X65](#0x65-actionbiturshift) | [ActionBitURShift](#0x65-actionbiturshift) | [SWF_ACTION_BIT_URSHIFT](#0x65-actionbiturshift) | [actionBitURShift](#0x65-actionbiturshift) |  | ✓ | ✓ |
| [0X66](#0x66-actionstrictequals) | [ActionStrictEquals](#0x66-actionstrictequals) | [SWF_ACTION_STRICT_EQUALS](#0x66-actionstrictequals) | [actionStrictEquals](#0x66-actionstrictequals) |  | ✓ | ✓ |
| [0X67](#0x67-actiongreater) | [ActionGreater](#0x67-actiongreater) | [SWF_ACTION_GREATER](#0x67-actiongreater) | [actionGreater](#0x67-actiongreater) | 1 | ✓ | ✓ |
| [0X68](#0x68-actionstringgreater) | [ActionStringGreater](#0x68-actionstringgreater) | [SWF_ACTION_STRING_GREATER](#0x68-actionstringgreater) | [actionStringGreater](#0x68-actionstringgreater) |  | ✓ | ✓ |
| [0X69](#0x69-actionextends) | [ActionExtends](#0x69-actionextends) |  |  |  | ✓ |  |
| [0X81](#0x81-actiongotoframe) | [ActionGotoFrame](#0x81-actiongotoframe) |  |  |  |  |  |
| [0X83](#0x83-actiongeturl) | [ActionGetURL](#0x83-actiongeturl) |  |  |  |  |  |
| [0X87](#0x87-actionstoreregister) | [ActionStoreRegister](#0x87-actionstoreregister) | [SWF_ACTION_STORE_REGISTER](#0x87-actionstoreregister) | [actionStoreRegister](#0x87-actionstoreregister) |  | ✓ | ✓ |
| [0X88](#0x88-actionconstantpool) | [ActionConstantPool](#0x88-actionconstantpool) | [SWF_ACTION_CONSTANT_POOL](#0x88-actionconstantpool) |  |  |  |  |
| [0X8A](#0x8a-actionwaitforframe) | [ActionWaitForFrame](#0x8a-actionwaitforframe) |  |  |  |  |  |
| [0X8B](#0x8b-actionsettarget) | [ActionSetTarget](#0x8b-actionsettarget) |  |  |  |  |  |
| [0X8C](#0x8c-actiongotolabel) | [ActionGoToLabel](#0x8c-actiongotolabel) |  |  |  |  |  |
| [0X8D](#0x8d-actionwaitforframe2) | [ActionWaitForFrame2](#0x8d-actionwaitforframe2) |  |  |  |  |  |
| [0X8E](#0x8e-actiondefinefunction2) | [ActionDefineFunction2](#0x8e-actiondefinefunction2) | [SWF_ACTION_DEFINE_FUNCTION2](#0x8e-actiondefinefunction2) | [actionDefineFunction2](#0x8e-actiondefinefunction2) |  | ✓ |  |
| [0X8F](#0x8f-actiontry) | [ActionTry](#0x8f-actiontry) |  |  |  |  |  |
| [0X94](#0x94-actionwith) | [ActionWith](#0x94-actionwith) | [SWF_ACTION_WITH](#0x94-actionwith) |  | 1 | ✓ | ✓ |
| [0X96](#0x96-actionpush) | [ActionPush](#0x96-actionpush) | [SWF_ACTION_PUSH](#0x96-actionpush) |  |  |  |  |
| [0X99](#0x99-actionjump) | [ActionJump](#0x99-actionjump) | [SWF_ACTION_JUMP](#0x99-actionjump) |  | 1 |  |  |
| [0X9A](#0x9a-actiongeturl2) | [ActionGetURL2](#0x9a-actiongeturl2) |  |  |  |  |  |
| [0X9B](#0x9b-actiondefinefunction) | [ActionDefineFunction](#0x9b-actiondefinefunction) | [SWF_ACTION_DEFINE_FUNCTION](#0x9b-actiondefinefunction) |  |  | ✓ | ✓ |
| [0X9D](#0x9d-actionif) | [ActionIf](#0x9d-actionif) | [SWF_ACTION_IF](#0x9d-actionif) |  | 1 |  |  |
| [0X9E](#0x9e-actioncall) | [ActionCall](#0x9e-actioncall) | [SWF_ACTION_CALL](#0x9e-actioncall) | [actionCall](#0x9e-actioncall) | 1 | ✓ | ✓ |
| [0X9F](#0x9f-actiongotoframe2) | [ActionGotoFrame2](#0x9f-actiongotoframe2) | [SWF_ACTION_CALL_METHOD](#0x9f-actiongotoframe2) |  |  | ✓ | ✓ |

## Implementation Status

### ✅ Fully Implemented
(Has enum, function, and tests)

| Hex | Spec Name | Enum | Function | Tests | Docs | Branch |
|-----|-----------|------|----------|-------|------|--------|
| [0X26](#0x26-actiontrace) | [ActionTrace](#0x26-actiontrace) | ✓ | ✓ | ✓ |  |  |
| [0X3E](#0x3e-actionreturn) | [ActionReturn](#0x3e-actionreturn) | ✓ | ✓ | ✓ | ✓ | ✓ |
| [0X3F](#0x3f-actionmodulo) | [ActionModulo](#0x3f-actionmodulo) | ✓ | ✓ | ✓ |  |  |
| [0X46](#0x46-actionenumerate) | [ActionEnumerate](#0x46-actionenumerate) | ✓ | ✓ | ✓ | ✓ | ✓ |
| [0X47](#0x47-actionadd2) | [ActionAdd2](#0x47-actionadd2) | ✓ | ✓ | ✓ | ✓ | ✓ |
| [0X48](#0x48-actionless2) | [ActionLess2](#0x48-actionless2) | ✓ | ✓ | ✓ | ✓ | ✓ |
| [0X50](#0x50-actionincrement) | [ActionIncrement](#0x50-actionincrement) | ✓ | ✓ | ✓ |  |  |
| [0X51](#0x51-actiondecrement) | [ActionDecrement](#0x51-actiondecrement) | ✓ | ✓ | ✓ |  |  |
| [0X55](#0x55-actionenumerate2) | [ActionEnumerate2](#0x55-actionenumerate2) | ✓ | ✓ | ✓ | ✓ | ✓ |
| [0X67](#0x67-actiongreater) | [ActionGreater](#0x67-actiongreater) | ✓ | ✓ | ✓ | ✓ | ✓ |
| [0X9E](#0x9e-actioncall) | [ActionCall](#0x9e-actioncall) | ✓ | ✓ | ✓ | ✓ | ✓ |

### 🔄 Partially Implemented
(Has enum or function, but missing tests)

| Hex | Spec Name | Enum | Function | Tests | Docs | Branch |
|-----|-----------|------|----------|-------|------|--------|
| 0X00 |  | ✓ |  | |  |  |
| [0X07](#0x07-actionstop) | [ActionStop](#0x07-actionstop) | ✓ |  | | ✓ |  |
| [0X0A](#0x0a-actionadd) | [ActionAdd](#0x0a-actionadd) | ✓ | ✓ | |  |  |
| [0X0B](#0x0b-actionsubtract) | [ActionSubtract](#0x0b-actionsubtract) | ✓ | ✓ | |  |  |
| [0X0C](#0x0c-actionmultiply) | [ActionMultiply](#0x0c-actionmultiply) | ✓ | ✓ | |  |  |
| [0X0D](#0x0d-actiondivide) | [ActionDivide](#0x0d-actiondivide) | ✓ | ✓ | |  |  |
| [0X0E](#0x0e-actionequals) | [ActionEquals](#0x0e-actionequals) | ✓ | ✓ | |  |  |
| [0X0F](#0x0f-actionless) | [ActionLess](#0x0f-actionless) | ✓ | ✓ | |  |  |
| [0X10](#0x10-actionand) | [ActionAnd](#0x10-actionand) | ✓ | ✓ | |  |  |
| [0X11](#0x11-actionor) | [ActionOr](#0x11-actionor) | ✓ | ✓ | |  |  |
| [0X12](#0x12-actionnot) | [ActionNot](#0x12-actionnot) | ✓ | ✓ | |  |  |
| [0X13](#0x13-actionstringequals) | [ActionStringEquals](#0x13-actionstringequals) | ✓ | ✓ | |  |  |
| [0X14](#0x14-actionstringlength) | [ActionStringLength](#0x14-actionstringlength) | ✓ | ✓ | |  |  |
| [0X15](#0x15-actionstringextract) | [ActionStringExtract](#0x15-actionstringextract) | ✓ | ✓ | | ✓ | ✓ |
| [0X17](#0x17-actionpop) | [ActionPop](#0x17-actionpop) | ✓ |  | |  |  |
| [0X18](#0x18-actiontointeger) | [ActionToInteger](#0x18-actiontointeger) | ✓ | ✓ | | ✓ |  |
| [0X1C](#0x1c-actiongetvariable) | [ActionGetVariable](#0x1c-actiongetvariable) | ✓ | ✓ | |  |  |
| [0X1D](#0x1d-actionsetvariable) | [ActionSetVariable](#0x1d-actionsetvariable) | ✓ | ✓ | |  |  |
| [0X21](#0x21-actionstringadd) | [ActionStringAdd](#0x21-actionstringadd) | ✓ | ✓ | |  |  |
| [0X22](#0x22-actiongetproperty) | [ActionGetProperty](#0x22-actiongetproperty) | ✓ | ✓ | | ✓ | ✓ |
| [0X23](#0x23-actionsetproperty) | [ActionSetProperty](#0x23-actionsetproperty) | ✓ | ✓ | | ✓ | ✓ |
| [0X29](#0x29-actionstringless) | [ActionStringLess](#0x29-actionstringless) | ✓ | ✓ | | ✓ | ✓ |
| [0X30](#0x30-actionrandomnumber) | [ActionRandomNumber](#0x30-actionrandomnumber) | ✓ | ✓ | | ✓ |  |
| [0X31](#0x31-actionmbstringlength) | [ActionMBStringLength](#0x31-actionmbstringlength) | ✓ |  | | ✓ | ✓ |
| [0X32](#0x32-actionchartoascii) | [ActionCharToAscii](#0x32-actionchartoascii) | ✓ | ✓ | | ✓ | ✓ |
| [0X33](#0x33-actionasciitochar) | [ActionAsciiToChar](#0x33-actionasciitochar) | ✓ | ✓ | | ✓ | ✓ |
| [0X34](#0x34-actiongettime) | [ActionGetTime](#0x34-actiongettime) | ✓ | ✓ | |  |  |
| [0X35](#0x35-actionmbstringextract) | [ActionMBStringExtract](#0x35-actionmbstringextract) | ✓ |  | | ✓ | ✓ |
| [0X36](#0x36-actionmbchartoascii) | [ActionMBCharToAscii](#0x36-actionmbchartoascii) | ✓ |  | | ✓ | ✓ |
| [0X3D](#0x3d-actionstackswap) | [ActionStackSwap](#0x3d-actionstackswap) | ✓ | ✓ | | ✓ | ✓ |
| [0X40](#0x40-actionnewobject) | [ActionNewObject](#0x40-actionnewobject) | ✓ | ✓ | | ✓ | ✓ |
| [0X41](#0x41-actiondefinelocal2) | [ActionDefineLocal2](#0x41-actiondefinelocal2) | ✓ |  | | ✓ | ✓ |
| [0X42](#0x42-actioninitarray) | [ActionInitArray](#0x42-actioninitarray) | ✓ | ✓ | | ✓ | ✓ |
| [0X43](#0x43-actioninitobject) | [ActionInitObject](#0x43-actioninitobject) | ✓ | ✓ | | ✓ | ✓ |
| [0X45](#0x45-actiontargetpath) | [ActionTargetPath](#0x45-actiontargetpath) | ✓ | ✓ | | ✓ | ✓ |
| [0X4A](#0x4a-actiontonumber) | [ActionToNumber](#0x4a-actiontonumber) | ✓ | ✓ | | ✓ | ✓ |
| [0X4B](#0x4b-actiontostring) | [ActionToString](#0x4b-actiontostring) | ✓ | ✓ | | ✓ | ✓ |
| [0X4D](#0x4d-actionstackswap) | [ActionStackSwap](#0x4d-actionstackswap) | ✓ | ✓ | |  |  |
| [0X4E](#0x4e-actiongetmember) | [ActionGetMember](#0x4e-actiongetmember) | ✓ | ✓ | | ✓ |  |
| [0X4F](#0x4f-actionsetmember) | [ActionSetMember](#0x4f-actionsetmember) | ✓ | ✓ | | ✓ | ✓ |
| [0X52](#0x52-actioncallmethod) | [ActionCallMethod](#0x52-actioncallmethod) |  | ✓ | |  |  |
| [0X53](#0x53-actionnewmethod) | [ActionNewMethod](#0x53-actionnewmethod) | ✓ | ✓ | | ✓ | ✓ |
| 0X5A |  | ✓ |  | |  |  |
| 0X5B |  | ✓ |  | |  |  |
| [0X60](#0x60-actionbitand) | [ActionBitAnd](#0x60-actionbitand) | ✓ | ✓ | | ✓ | ✓ |
| [0X61](#0x61-actionbitor) | [ActionBitOr](#0x61-actionbitor) | ✓ | ✓ | | ✓ | ✓ |
| [0X62](#0x62-actionbitxor) | [ActionBitXor](#0x62-actionbitxor) | ✓ | ✓ | | ✓ | ✓ |
| [0X63](#0x63-actionbitlshift) | [ActionBitLShift](#0x63-actionbitlshift) | ✓ | ✓ | | ✓ | ✓ |
| [0X64](#0x64-actionbitrshift) | [ActionBitRShift](#0x64-actionbitrshift) | ✓ | ✓ | | ✓ | ✓ |
| [0X65](#0x65-actionbiturshift) | [ActionBitURShift](#0x65-actionbiturshift) | ✓ | ✓ | | ✓ | ✓ |
| [0X66](#0x66-actionstrictequals) | [ActionStrictEquals](#0x66-actionstrictequals) | ✓ | ✓ | | ✓ | ✓ |
| [0X68](#0x68-actionstringgreater) | [ActionStringGreater](#0x68-actionstringgreater) | ✓ | ✓ | | ✓ | ✓ |
| [0X87](#0x87-actionstoreregister) | [ActionStoreRegister](#0x87-actionstoreregister) | ✓ | ✓ | | ✓ | ✓ |
| [0X88](#0x88-actionconstantpool) | [ActionConstantPool](#0x88-actionconstantpool) | ✓ |  | |  |  |
| [0X8E](#0x8e-actiondefinefunction2) | [ActionDefineFunction2](#0x8e-actiondefinefunction2) | ✓ | ✓ | | ✓ |  |
| [0X96](#0x96-actionpush) | [ActionPush](#0x96-actionpush) | ✓ |  | |  |  |
| [0X9B](#0x9b-actiondefinefunction) | [ActionDefineFunction](#0x9b-actiondefinefunction) | ✓ |  | | ✓ | ✓ |
| [0X9F](#0x9f-actiongotoframe2) | [ActionGotoFrame2](#0x9f-actiongotoframe2) | ✓ |  | | ✓ | ✓ |

### ❌ Not Implemented
(Only in spec, no implementation yet)

| Hex | Spec Name |
|-----|-----------|
| [0X04](#0x04-actionnextframe) | [ActionNextFrame](#0x04-actionnextframe) |
| [0X05](#0x05-actionpreviousframe) | [ActionPreviousFrame](#0x05-actionpreviousframe) |
| [0X06](#0x06-actionplay) | [ActionPlay](#0x06-actionplay) |
| [0X08](#0x08-actiontogglequality) | [ActionToggleQuality](#0x08-actiontogglequality) |
| [0X09](#0x09-actionstopsounds) | [ActionStopSounds](#0x09-actionstopsounds) |
| [0X20](#0x20-actionsettarget2) | [ActionSetTarget2](#0x20-actionsettarget2) |
| [0X24](#0x24-actionclonesprite) | [ActionCloneSprite](#0x24-actionclonesprite) |
| [0X25](#0x25-actionremovesprite) | [ActionRemoveSprite](#0x25-actionremovesprite) |
| [0X27](#0x27-actionstartdrag) | [ActionStartDrag](#0x27-actionstartdrag) |
| [0X28](#0x28-actionenddrag) | [ActionEndDrag](#0x28-actionenddrag) |
| [0X2A](#0x2a-actionthrow) | [ActionThrow](#0x2a-actionthrow) |
| [0X2B](#0x2b-actioncastop) | [ActionCastOp](#0x2b-actioncastop) |
| [0X2C](#0x2c-actionimplementsop) | [ActionImplementsOp](#0x2c-actionimplementsop) |
| [0X37](#0x37-actionmbasciitochar) | [ActionMBAsciiToChar](#0x37-actionmbasciitochar) |
| [0X44](#0x44-actiontypeof) | [ActionTypeOf](#0x44-actiontypeof) |
| [0X49](#0x49-actionequals2) | [ActionEquals2](#0x49-actionequals2) |
| [0X54](#0x54-actioninstanceof) | [ActionInstanceOf](#0x54-actioninstanceof) |
| [0X69](#0x69-actionextends) | [ActionExtends](#0x69-actionextends) |
| [0X81](#0x81-actiongotoframe) | [ActionGotoFrame](#0x81-actiongotoframe) |
| [0X83](#0x83-actiongeturl) | [ActionGetURL](#0x83-actiongeturl) |
| [0X8A](#0x8a-actionwaitforframe) | [ActionWaitForFrame](#0x8a-actionwaitforframe) |
| [0X8B](#0x8b-actionsettarget) | [ActionSetTarget](#0x8b-actionsettarget) |
| [0X8C](#0x8c-actiongotolabel) | [ActionGoToLabel](#0x8c-actiongotolabel) |
| [0X8D](#0x8d-actionwaitforframe2) | [ActionWaitForFrame2](#0x8d-actionwaitforframe2) |
| [0X8F](#0x8f-actiontry) | [ActionTry](#0x8f-actiontry) |
| [0X9A](#0x9a-actiongeturl2) | [ActionGetURL2](#0x9a-actiongeturl2) |

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

**Documentation:**
- [SWFRecompDocs/prompts/opcode-next-frame-0x04.md](SWFRecompDocs/prompts/opcode-next-frame-0x04.md)

**Notes:**
- Official SWF specification name (spec line 4310)

---

### 0X05: ActionPreviousFrame

**Name Variations:**
- `ActionPreviousFrame` (spec, source: SWF Specification v19)

**Documentation:**
- [SWFRecompDocs/prompts/opcode-prev-frame-0x05.md](SWFRecompDocs/prompts/opcode-prev-frame-0x05.md)

**Notes:**
- Official SWF specification name (spec line 4324)

---

### 0X06: ActionPlay

**Name Variations:**
- `ActionPlay` (spec, source: SWF Specification v19)

**Documentation:**
- [SWFRecompDocs/prompts/opcode-play-0x06.md](SWFRecompDocs/prompts/opcode-play-0x06.md)

**Notes:**
- Official SWF specification name (spec line 4338)

---

### 0X07: ActionStop

**Name Variations:**
- `ActionStop` (spec, source: SWF Specification v19)
- `SWF_ACTION_STOP` (enum, source: action.hpp)

**Implementation:**
- parseActions (case SWF_ACTION_STOP)

**Documentation:**
- [SWFRecompDocs/prompts/opcode-stop-0x07.md](SWFRecompDocs/prompts/opcode-stop-0x07.md)

**Notes:**
- Official SWF specification name (spec line 4354)

---

### 0X08: ActionToggleQuality

**Name Variations:**
- `ActionToggleQuality` (spec, source: SWF Specification v19)

**Documentation:**
- [SWFRecompDocs/prompts/opcode-toggle-quality-0x08.md](SWFRecompDocs/prompts/opcode-toggle-quality-0x08.md)

**Notes:**
- Official SWF specification name (spec line 4368)

---

### 0X09: ActionStopSounds

**Name Variations:**
- `ActionStopSounds` (spec, source: SWF Specification v19)

**Documentation:**
- [SWFRecompDocs/prompts/opcode-stop-sounds-0x09.md](SWFRecompDocs/prompts/opcode-stop-sounds-0x09.md)

**Notes:**
- Official SWF specification name (spec line 4379)

---

### 0X0A: ActionAdd

**Name Variations:**
- `ActionAdd` (spec, source: SWF Specification v19)
- `SWF_ACTION_ADD` (enum, source: action.hpp)
- `actionAdd` (function, source: action.h)

**Function Declaration:**
```c
void actionAdd(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_ADD)

**Notes:**
- Official SWF specification name (spec line 4670)

---

### 0X0B: ActionSubtract

**Name Variations:**
- `ActionSubtract` (spec, source: SWF Specification v19)
- `SWF_ACTION_SUBTRACT` (enum, source: action.hpp)
- `actionSubtract` (function, source: action.h)

**Function Declaration:**
```c
void actionSubtract(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_SUBTRACT)

**Notes:**
- Official SWF specification name (spec line 4693)

---

### 0X0C: ActionMultiply

**Name Variations:**
- `ActionMultiply` (spec, source: SWF Specification v19)
- `SWF_ACTION_MULTIPLY` (enum, source: action.hpp)
- `actionMultiply` (function, source: action.h)

**Function Declaration:**
```c
void actionMultiply(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_MULTIPLY)

**Notes:**
- Official SWF specification name (spec line 4714)

---

### 0X0D: ActionDivide

**Name Variations:**
- `ActionDivide` (spec, source: SWF Specification v19)
- `SWF_ACTION_DIVIDE` (enum, source: action.hpp)
- `actionDivide` (function, source: action.h)

**Function Declaration:**
```c
void actionDivide(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_DIVIDE)

**Notes:**
- Official SWF specification name (spec line 4737)

---

### 0X0E: ActionEquals

**Name Variations:**
- `ActionEquals` (spec, source: SWF Specification v19)
- `SWF_ACTION_EQUALS` (enum, source: action.hpp)
- `actionEquals` (function, source: action.h)

**Function Declaration:**
```c
void actionEquals(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_EQUALS)

**Notes:**
- Official SWF specification name (spec line 4761)

---

### 0X0F: ActionLess

**Name Variations:**
- `ActionLess` (spec, source: SWF Specification v19)
- `SWF_ACTION_LESS` (enum, source: action.hpp)
- `actionLess` (function, source: action.h)

**Function Declaration:**
```c
void actionLess(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_LESS)

**Notes:**
- Official SWF specification name (spec line 4786)

---

### 0X10: ActionAnd

**Name Variations:**
- `ActionAnd` (spec, source: SWF Specification v19)
- `SWF_ACTION_AND` (enum, source: action.hpp)
- `actionAnd` (function, source: action.h)

**Function Declaration:**
```c
void actionAnd(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_AND)

**Notes:**
- Official SWF specification name (spec line 4808)

---

### 0X11: ActionOr

**Name Variations:**
- `ActionOr` (spec, source: SWF Specification v19)
- `SWF_ACTION_OR` (enum, source: action.hpp)
- `actionOr` (function, source: action.h)

**Function Declaration:**
```c
void actionOr(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_OR)

**Notes:**
- Official SWF specification name (spec line 4829)

---

### 0X12: ActionNot

**Name Variations:**
- `ActionNot` (spec, source: SWF Specification v19)
- `SWF_ACTION_NOT` (enum, source: action.hpp)
- `actionNot` (function, source: action.h)

**Function Declaration:**
```c
void actionNot(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_NOT)

**Notes:**
- Official SWF specification name (spec line 4853)

---

### 0X13: ActionStringEquals

**Name Variations:**
- `ActionStringEquals` (spec, source: SWF Specification v19)
- `SWF_ACTION_STRING_EQUALS` (enum, source: action.hpp)
- `actionStringEquals` (function, source: action.h)

**Function Declaration:**
```c
void actionStringEquals(char* stack, u32* sp, char* a_str, char* b_str);
```

**Implementation:**
- parseActions (case SWF_ACTION_STRING_EQUALS)

**Notes:**
- Official SWF specification name (spec line 4882)

---

### 0X14: ActionStringLength

**Name Variations:**
- `ActionStringLength` (spec, source: SWF Specification v19)
- `SWF_ACTION_STRING_LENGTH` (enum, source: action.hpp)
- `actionStringLength` (function, source: action.h)

**Function Declaration:**
```c
void actionStringLength(char* stack, u32* sp, char* v_str);
```

**Implementation:**
- parseActions (case SWF_ACTION_STRING_LENGTH)

**Notes:**
- Official SWF specification name (spec line 4903)

---

### 0X15: ActionStringExtract

**Name Variations:**
- `ActionStringExtract` (spec, source: SWF Specification v19)
- `SWF_ACTION_STRING_EXTRACT` (enum, source: action.hpp)
- `actionStringExtract` (function, source: action.h)

**Function Declaration:**
```c
void actionStringExtract(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_STRING_EXTRACT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-string-extract-0x15.md](SWFRecompDocs/prompts/completed/opcode-string-extract-0x15.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-string-extract-0x15-011CUqjJxEarFz94kS6esXja`
- **Commit**: `d117464f127c23c3b5e1c3453987d49332b71ff3`
- **Subject**: Implement STRING_EXTRACT opcode (0x15) for AS2 substring operation

**Notes:**
- Official SWF specification name (spec line 4942)

---

### 0X17: ActionPop

**Name Variations:**
- `ActionPop` (spec, source: SWF Specification v19)
- `SWF_ACTION_POP` (enum, source: action.hpp)

**Implementation:**
- parseActions (case SWF_ACTION_POP)

**Notes:**
- Official SWF specification name (spec line 4651)

---

### 0X18: ActionToInteger

**Name Variations:**
- `ActionToInteger` (spec, source: SWF Specification v19)
- `SWF_ACTION_TO_INTEGER` (enum, source: action.hpp)
- `actionToInteger` (function, source: action.h)

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

**Function Declaration:**
```c
void actionGetVariable(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_GET_VARIABLE)

**Notes:**
- Official SWF specification name (spec line 5218)

---

### 0X1D: ActionSetVariable

**Name Variations:**
- `ActionSetVariable` (spec, source: SWF Specification v19)
- `SWF_ACTION_SET_VARIABLE` (enum, source: action.hpp)
- `actionSetVariable` (function, source: action.h)

**Function Declaration:**
```c
void actionSetVariable(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_SET_VARIABLE)

**Notes:**
- Official SWF specification name (spec line 5240)

---

### 0X20: ActionSetTarget2

**Name Variations:**
- `ActionSetTarget2` (spec, source: SWF Specification v19)

**Notes:**
- Official SWF specification name (spec line 5405)

---

### 0X21: ActionStringAdd

**Name Variations:**
- `ActionStringAdd` (spec, source: SWF Specification v19)
- `SWF_ACTION_STRING_ADD` (enum, source: action.hpp)
- `actionStringAdd` (function, source: action.h)

**Function Declaration:**
```c
void actionStringAdd(char* stack, u32* sp, char* a_str, char* b_str);
```

**Implementation:**
- parseActions (case SWF_ACTION_STRING_ADD)

**Notes:**
- Official SWF specification name (spec line 4921)

---

### 0X22: ActionGetProperty

**Name Variations:**
- `ActionGetProperty` (spec, source: SWF Specification v19)
- `SWF_ACTION_GET_PROPERTY` (enum, source: action.hpp)
- `actionGetProperty` (function, source: action.h)

**Function Declaration:**
```c
void actionGetProperty(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_GET_PROPERTY)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-get-property-0x22.md](SWFRecompDocs/prompts/completed/opcode-get-property-0x22.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-get-property-0x22-011CUqqqTnsyJjtfQywgWLjs`
- **Commit**: `2dc128a80b3e23b988853623bd7cad44765f2bed`
- **Subject**: Implement GET_PROPERTY opcode (0x22) for MovieClip property access

**Notes:**
- Official SWF specification name (spec line 5423)

---

### 0X23: ActionSetProperty

**Name Variations:**
- `ActionSetProperty` (spec, source: SWF Specification v19)
- `SWF_ACTION_SET_PROPERTY` (enum, source: action.hpp)
- `actionSetProperty` (function, source: action.h)

**Function Declaration:**
```c
void actionSetProperty(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_SET_PROPERTY)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-set-property-0x23.md](SWFRecompDocs/prompts/completed/opcode-set-property-0x23.md)

**Implementation Branch:**
- **Branch**: `origin/claude/implement-opcode-set-property-011CUqqrbs54vXgh5PYu8tPB`
- **Commit**: `6a591e68a1ea81556b338f3a61e96e8d12772c39`
- **Subject**: Implement SET_PROPERTY opcode (0x23) for MovieClip properties

**Notes:**
- Official SWF specification name (spec line 5541)

---

### 0X24: ActionCloneSprite

**Name Variations:**
- `ActionCloneSprite` (spec, source: SWF Specification v19)

**Documentation:**
- [SWFRecompDocs/prompts/opcode-clone-sprite-0x24.md](SWFRecompDocs/prompts/opcode-clone-sprite-0x24.md)

**Notes:**
- Official SWF specification name (spec line 5561)

---

### 0X25: ActionRemoveSprite

**Name Variations:**
- `ActionRemoveSprite` (spec, source: SWF Specification v19)

**Documentation:**
- [SWFRecompDocs/prompts/opcode-remove-sprite-0x25.md](SWFRecompDocs/prompts/opcode-remove-sprite-0x25.md)

**Notes:**
- Official SWF specification name (spec line 5583)

---

### 0X26: ActionTrace

**Name Variations:**
- `ActionTrace` (spec, source: SWF Specification v19)
- `SWF_ACTION_TRACE` (enum, source: action.hpp)
- `actionTrace` (function, source: action.h)

**Test Directories:**
- `SWFRecomp/tests/trace_swf_4`

**Function Declaration:**
```c
void actionTrace(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_TRACE)

**Notes:**
- Official SWF specification name (spec line 5682)

---

### 0X27: ActionStartDrag

**Name Variations:**
- `ActionStartDrag` (spec, source: SWF Specification v19)

**Documentation:**
- [SWFRecompDocs/prompts/opcode-start-drag-0x27.md](SWFRecompDocs/prompts/opcode-start-drag-0x27.md)

**Notes:**
- Official SWF specification name (spec line 5601)

---

### 0X28: ActionEndDrag

**Name Variations:**
- `ActionEndDrag` (spec, source: SWF Specification v19)

**Documentation:**
- [SWFRecompDocs/prompts/opcode-end-drag-0x28.md](SWFRecompDocs/prompts/opcode-end-drag-0x28.md)

**Notes:**
- Official SWF specification name (spec line 5641)

---

### 0X29: ActionStringLess

**Name Variations:**
- `ActionStringLess` (spec, source: SWF Specification v19)
- `SWF_ACTION_STRING_LESS` (enum, source: action.hpp)
- `actionStringLess` (function, source: action.h)

**Function Declaration:**
```c
void actionStringLess(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_STRING_LESS)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-string-less-0x29.md](SWFRecompDocs/prompts/completed/opcode-string-less-0x29.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-string-less-0x29-011CUqjLBvt11NbE5qovg15L`
- **Commit**: `705d3e4952efe1d4cae824e22fbcc916cb6b7edd`
- **Subject**: Implement STRING_LESS opcode (0x29) for lexicographic string comparison

**Notes:**
- Official SWF specification name (spec line 4964)

---

### 0X2A: ActionThrow

**Name Variations:**
- `ActionThrow` (spec, source: SWF Specification v19)

**Documentation:**
- [SWFRecompDocs/prompts/opcode-throw-0x2a.md](SWFRecompDocs/prompts/opcode-throw-0x2a.md)

**Notes:**
- Official SWF specification name (spec line 7289)

---

### 0X2B: ActionCastOp

**Name Variations:**
- `ActionCastOp` (spec, source: SWF Specification v19)

**Documentation:**
- [SWFRecompDocs/prompts/opcode-cast-op-0x2b.md](SWFRecompDocs/prompts/opcode-cast-op-0x2b.md)

**Notes:**
- Official SWF specification name (spec line 7141)

---

### 0X2C: ActionImplementsOp

**Name Variations:**
- `ActionImplementsOp` (spec, source: SWF Specification v19)

**Documentation:**
- [SWFRecompDocs/prompts/opcode-implements-op-0x2c.md](SWFRecompDocs/prompts/opcode-implements-op-0x2c.md)

**Notes:**
- Official SWF specification name (spec line 7164)

---

### 0X30: ActionRandomNumber

**Name Variations:**
- `ActionRandomNumber` (spec, source: SWF Specification v19)
- `SWF_ACTION_RANDOM_NUMBER` (enum, source: action.hpp)
- `actionRandomNumber` (function, source: action.h)

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
- `SWF_ACTION_CHAR_TO_ASCII` (enum, source: action.hpp)

**Implementation:**
- parseActions (case SWF_ACTION_CHAR_TO_ASCII)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-char-to-ascii-0x31.md](SWFRecompDocs/prompts/completed/opcode-char-to-ascii-0x31.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-char-to-ascii-011CUqj9iRdh36YUoc2qi2cE`
- **Commit**: `bfbc54b8dc9cf5cbd7a08c3a832457452fedf8bc`
- **Subject**: Implement CharToAscii (0x31) opcode for AS2

**Notes:**
- Official SWF specification name (spec line 4986)

---

### 0X32: ActionCharToAscii

**Name Variations:**
- `ActionCharToAscii` (spec, source: SWF Specification v19)
- `SWF_ACTION_ASCII_TO_CHAR` (enum, source: action.hpp)
- `actionCharToAscii` (function, source: action.h)

**Function Declaration:**
```c
void actionCharToAscii(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_ASCII_TO_CHAR)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-ascii-to-char-0x32.md](SWFRecompDocs/prompts/completed/opcode-ascii-to-char-0x32.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-ascii-to-char-011CUqjDTN85jHrPQw6TcwG6`
- **Commit**: `f919257999bd3620b400f2bcef828e6e8fc2090a`
- **Subject**: Implement ASCII_TO_CHAR opcode (0x32)

**Notes:**
- Official SWF specification name (spec line 5053)

---

### 0X33: ActionAsciiToChar

**Name Variations:**
- `ActionAsciiToChar` (spec, source: SWF Specification v19)
- `SWF_ACTION_MB_CHAR_TO_ASCII` (enum, source: action.hpp)
- `actionAsciiToChar` (function, source: action.h)

**Function Declaration:**
```c
void actionAsciiToChar(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_MB_CHAR_TO_ASCII)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-mb-char-to-ascii-0x33.md](SWFRecompDocs/prompts/completed/opcode-mb-char-to-ascii-0x33.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-mb-char-to-ascii-011CUqjErLGMw5t3U7fW8Ptx`
- **Commit**: `420ee39dcc4c0e3b8e2cd899d30eebb9e824d697`
- **Subject**: Implement MB_CHAR_TO_ASCII opcode (0x33) for multibyte UTF-8 string support

**Notes:**
- Official SWF specification name (spec line 5072)

---

### 0X34: ActionGetTime

**Name Variations:**
- `ActionGetTime` (spec, source: SWF Specification v19)
- `SWF_ACTION_GET_TIME` (enum, source: action.hpp)
- `actionGetTime` (function, source: action.h)

**Function Declaration:**
```c
void actionGetTime(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_GET_TIME)

**Notes:**
- Official SWF specification name (spec line 5703)

---

### 0X35: ActionMBStringExtract

**Name Variations:**
- `ActionMBStringExtract` (spec, source: SWF Specification v19)
- `SWF_ACTION_MB_STRING_LENGTH` (enum, source: action.hpp)

**Implementation:**
- parseActions (case SWF_ACTION_MB_STRING_LENGTH)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-mb-string-length-0x35.md](SWFRecompDocs/prompts/completed/opcode-mb-string-length-0x35.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-mb-string-length-011CUqjHZGBt4RPFnmqHZUmK`
- **Commit**: `5a7d71fd71cc468bba9df66f0143402e2048f193`
- **Subject**: Implement MB_STRING_LENGTH opcode (0x35)

**Notes:**
- Official SWF specification name (spec line 5006)

---

### 0X36: ActionMBCharToAscii

**Name Variations:**
- `ActionMBCharToAscii` (spec, source: SWF Specification v19)
- `SWF_ACTION_MB_ASCII_TO_CHAR` (enum, source: action.hpp)

**Implementation:**
- parseActions (case SWF_ACTION_MB_ASCII_TO_CHAR)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-mb-ascii-to-char-0x36.md](SWFRecompDocs/prompts/completed/opcode-mb-ascii-to-char-0x36.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-mb-ascii-to-char-011CUqjGDDuJtLXjWDS2jnrB`
- **Commit**: `5012878afbe100af027f2bc377a93fccb7d128d8`
- **Subject**: Implement MB_ASCII_TO_CHAR opcode (0x36)

**Notes:**
- Official SWF specification name (spec line 5094)

---

### 0X37: ActionMBAsciiToChar

**Name Variations:**
- `ActionMBAsciiToChar` (spec, source: SWF Specification v19)

**Notes:**
- Official SWF specification name (spec line 5115)

---

### 0X3A: ActionDelete

**Name Variations:**
- `ActionDelete` (spec, source: SWF Specification v19)
- `actionDelete` (function, source: action.h)

**Test Directories:**
- `SWFRecomp/tests/delete_swf_5`

**Function Declaration:**
```c
void actionDelete(char* stack, u32* sp);
```

**Implementation:**
- SWFModernRuntime/src/actionmodern/action.c

**Notes:**
- Official SWF specification name (spec line 6007)

---

### 0X3B: ActionDelete2

**Name Variations:**
- `ActionDelete2` (spec, source: SWF Specification v19)
- `actionDelete2` (function, source: action.h)

**Test Directories:**
- `SWFRecomp/tests/delete2_swf_5`

**Function Declaration:**
```c
void actionDelete2(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- SWFModernRuntime/src/actionmodern/action.c

**Notes:**
- Official SWF specification name (spec line 6025)

---

### 0X3C: ActionDefineLocal

**Name Variations:**
- `ActionDefineLocal` (spec, source: SWF Specification v19)
- `SWF_ACTION_TYPEOF` (enum, source: action.hpp)

**Test Directories:**
- `SWFRecomp/tests/typeof_swf_5`

**Implementation:**
- parseActions (case SWF_ACTION_TYPEOF)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-typeof-0x3c.md](SWFRecompDocs/prompts/completed/opcode-typeof-0x3c.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-typeof-0x3c-011CUqjRkgkmLYw99RCTrX2N`
- **Commit**: `e8c6149a895d55c12ff64fc38abfb422e1847755`
- **Subject**: Implement TYPEOF opcode (0x3C)

**Notes:**
- Official SWF specification name (spec line 5969)

---

### 0X3D: ActionStackSwap

**Name Variations:**
- `ActionStackSwap` (spec, source: SWF Specification v19)
- `SWF_ACTION_CALL_FUNCTION` (enum, source: action.hpp)
- `actionStackSwap` (function, source: action.h)

**Function Declaration:**
```c
void actionStackSwap(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_CALL_FUNCTION)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-duplicate-0x3d.md](SWFRecompDocs/prompts/completed/opcode-duplicate-0x3d.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-duplicate-0x3d-011CUqjMorPan5wAhTnAR7Xy`
- **Commit**: `16cd31e229e5f910b61a45737df165f3fa2fc5bf`
- **Subject**: Implement DUPLICATE opcode (0x3D)

**Notes:**
- Official SWF specification name (spec line 5796)

---

### 0X3E: ActionReturn

**Name Variations:**
- `ActionReturn` (spec, source: SWF Specification v19)
- `SWF_ACTION_RETURN` (enum, source: action.hpp)
- `actionReturn` (function, source: action.h)

**Test Directories:**
- `SWFRecomp/tests/return_swf_4`

**Function Declaration:**
```c
void actionReturn(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_RETURN)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-return-0x3e.md](SWFRecompDocs/prompts/completed/opcode-return-0x3e.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-return-0x3e-011CUqqvqpagz6dnfYaZnpQz`
- **Commit**: `2722c1226bc29b04becb65e51d805661065bbe34`
- **Subject**: Implement RETURN opcode (0x3E) for ActionScript 2

**Notes:**
- Official SWF specification name (spec line 6643)

---

### 0X3F: ActionModulo

**Name Variations:**
- `ActionModulo` (spec, source: SWF Specification v19)
- `SWF_ACTION_MODULO` (enum, source: action.hpp)
- `actionModulo` (function, source: action.h)

**Test Directories:**
- `SWFRecomp/tests/modulo_swf_4`

**Function Declaration:**
```c
void actionModulo(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_MODULO)

**Notes:**
- Official SWF specification name (spec line 6438)

---

### 0X40: ActionNewObject

**Name Variations:**
- `ActionNewObject` (spec, source: SWF Specification v19)
- `SWF_ACTION_NEW_OBJECT` (enum, source: action.hpp)
- `actionNewObject` (function, source: action.h)

**Function Declaration:**
```c
void actionNewObject(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_NEW_OBJECT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-new-object-0x40.md](SWFRecompDocs/prompts/completed/opcode-new-object-0x40.md)

**Implementation Branch:**
- **Branch**: `origin/claude/implement-opcode-new-object-011CUqqtdjVWnbspsyb3PyNS`
- **Commit**: `73a5174c63a74faf1b955c38831ea2d93cea9ba3`
- **Subject**: Implement NEW_OBJECT opcode (0x40) with Array/Object support

**Notes:**
- Official SWF specification name (spec line 6216)

---

### 0X41: ActionDefineLocal2

**Name Variations:**
- `ActionDefineLocal2` (spec, source: SWF Specification v19)
- `SWF_ACTION_DECLARE_LOCAL` (enum, source: action.hpp)

**Implementation:**
- parseActions (case SWF_ACTION_DECLARE_LOCAL)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-declare-local-0x41.md](SWFRecompDocs/prompts/completed/opcode-declare-local-0x41.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-declare-local-0x41-011CUqv6JpWVXE8iy8PwqaP4`
- **Commit**: `97cec4084ea511e3d08ceba8008e6c6222eaa45f`
- **Subject**: Implement DECLARE_LOCAL opcode (0x41) with local scope infrastructure

**Notes:**
- Official SWF specification name (spec line 5990)

---

### 0X42: ActionInitArray

**Name Variations:**
- `ActionInitArray` (spec, source: SWF Specification v19)
- `SWF_ACTION_INIT_ARRAY` (enum, source: action.hpp)
- `actionInitArray` (function, source: action.h)

**Function Declaration:**
```c
void actionInitArray(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_INIT_ARRAY)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-init-array-0x42.md](SWFRecompDocs/prompts/completed/opcode-init-array-0x42.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-init-array-0x42-011CUqqkAxTY8viyYWbxeESe`
- **Commit**: `b11c784685c0700a097478b45e701c19e13d76c9`
- **Subject**: Implement INIT_ARRAY opcode (0x42)

**Notes:**
- Official SWF specification name (spec line 6124)

---

### 0X43: ActionInitObject

**Name Variations:**
- `ActionInitObject` (spec, source: SWF Specification v19)
- `SWF_ACTION_INIT_OBJECT` (enum, source: action.hpp)
- `actionInitObject` (function, source: action.h)

**Function Declaration:**
```c
void actionInitObject(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_INIT_OBJECT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-init-object-0x43.md](SWFRecompDocs/prompts/completed/opcode-init-object-0x43.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-init-object-0x43-011CUqqmNYk4A15HTAzbUq5v`
- **Commit**: `ac7e661289f093413930f20754bbfa827cf562ac`
- **Subject**: Implement INIT_OBJECT opcode (0x43) for ActionScript object creation

**Notes:**
- Official SWF specification name (spec line 6153)

---

### 0X44: ActionTypeOf

**Name Variations:**
- `ActionTypeOf` (spec, source: SWF Specification v19)

**Test Directories:**
- `SWFRecomp/tests/typeof_swf_5`

**Notes:**
- Official SWF specification name (spec line 6380)

---

### 0X45: ActionTargetPath

**Name Variations:**
- `ActionTargetPath` (spec, source: SWF Specification v19)
- `SWF_ACTION_TARGET_PATH` (enum, source: action.hpp)
- `actionTargetPath` (function, source: action.h)

**Function Declaration:**
```c
void actionTargetPath(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_TARGET_PATH)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-target-path-0x45.md](SWFRecompDocs/prompts/completed/opcode-target-path-0x45.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-target-path-0x45-011CUqjSvUtwuKs7YmLXRRcD`
- **Commit**: `f7dbad28eac27324c6117bb3c301e6d2d109df24`
- **Subject**: Implement TARGET_PATH opcode (0x45)

**Notes:**
- Official SWF specification name (spec line 6268)

---

### 0X46: ActionEnumerate

**Name Variations:**
- `ActionEnumerate` (spec, source: SWF Specification v19)
- `SWF_ACTION_ENUMERATE` (enum, source: action.hpp)
- `actionEnumerate` (function, source: action.h)

**Test Directories:**
- `SWFRecomp/tests/enumerate_swf_4`

**Function Declaration:**
```c
void actionEnumerate(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_ENUMERATE)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-enumerate-0x46.md](SWFRecompDocs/prompts/completed/opcode-enumerate-0x46.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-enumerate-0x46-011CUquqm9cxfLVykjjXYtZZ`
- **Commit**: `ebe63532930ce7dac71c8af8dae63d7ac387834e`
- **Subject**: Implement ENUMERATE opcode (0x46) for object property enumeration

**Notes:**
- Official SWF specification name (spec line 6044)

---

### 0X47: ActionAdd2

**Name Variations:**
- `ActionAdd2` (spec, source: SWF Specification v19)
- `SWF_ACTION_ADD2` (enum, source: action.hpp)
- `actionAdd2` (function, source: action.h)

**Test Directories:**
- `SWFRecomp/tests/add2_swf_5`

**Function Declaration:**
```c
void actionAdd2(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_ADD2)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-add2-0x47.md](SWFRecompDocs/prompts/completed/opcode-add2-0x47.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-add2-0x47-011CUqjUFFXqojvHMPRuv3Bb`
- **Commit**: `10b0923c538e8829e12185167e6f1f66d4c21d1b`
- **Subject**: Implement ADD2 opcode (0x47) - Type-aware addition

**Notes:**
- Official SWF specification name (spec line 6393)

---

### 0X48: ActionLess2

**Name Variations:**
- `ActionLess2` (spec, source: SWF Specification v19)
- `SWF_ACTION_LESS2` (enum, source: action.hpp)
- `actionLess2` (function, source: action.h)

**Test Directories:**
- `SWFRecomp/tests/less2_swf_4`

**Function Declaration:**
```c
void actionLess2(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_LESS2)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-less2-0x48.md](SWFRecompDocs/prompts/completed/opcode-less2-0x48.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-less2-0x48-011CUqVhjEkp43uiNZP73mVd`
- **Commit**: `38abf422447f760d57ac32be92b3ad8427a48d86`
- **Subject**: Implement ActionLess2 opcode (0x48) and fix opcode naming

**Notes:**
- Official SWF specification name (spec line 6414)

---

### 0X49: ActionEquals2

**Name Variations:**
- `ActionEquals2` (spec, source: SWF Specification v19)

**Notes:**
- Official SWF specification name (spec line 6068)

---

### 0X4A: ActionToNumber

**Name Variations:**
- `ActionToNumber` (spec, source: SWF Specification v19)
- `SWF_ACTION_TO_NUMBER` (enum, source: action.hpp)
- `actionToNumber` (function, source: action.h)

**Function Declaration:**
```c
void actionToNumber(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_TO_NUMBER)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-to-number-0x4a.md](SWFRecompDocs/prompts/completed/opcode-to-number-0x4a.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-to-number-0x4a-011CUqVrcGZ3S8hpgvoNmZFo`
- **Commit**: `5a01940750da3549c0c5b47f539667c4153ca24d`
- **Subject**: Implement TO_NUMBER opcode (0x4A) for ActionScript 2

**Notes:**
- Official SWF specification name (spec line 6320)

---

### 0X4B: ActionToString

**Name Variations:**
- `ActionToString` (spec, source: SWF Specification v19)
- `SWF_ACTION_TO_STRING` (enum, source: action.hpp)
- `actionToString` (function, source: action.h)

**Function Declaration:**
```c
void actionToString(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_TO_STRING)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-to-string-0x4b.md](SWFRecompDocs/prompts/completed/opcode-to-string-0x4b.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-to-string-0x4b-011CUqVt3dKcYBkDFdbzzoiE`
- **Commit**: `2fde36278e8f75217529a706b8d71989dbc37216`
- **Subject**: Implement TO_STRING opcode (0x4B) for ActionScript 2

**Notes:**
- Official SWF specification name (spec line 6342)

---

### 0X4C: ActionPushDuplicate

**Name Variations:**
- `ActionPushDuplicate` (spec, source: SWF Specification v19)
- `SWF_ACTION_DUPLICATE` (enum, source: action.hpp)

**Test Directories:**
- `SWFRecomp/tests/duplicate_swf_4`

**Implementation:**
- parseActions (case SWF_ACTION_DUPLICATE)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-stack-swap-0x4c.md](SWFRecompDocs/prompts/completed/opcode-stack-swap-0x4c.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-stack-swap-0x4c-011CUqjPCoZCMmajEqhdp9Wc`
- **Commit**: `9509728d78349fa6c71676e6d9f85c1c44c6fc88`
- **Subject**: Implement STACK_SWAP opcode (0x4C)

**Notes:**
- Official SWF specification name (spec line 6627)

---

### 0X4D: ActionStackSwap

**Name Variations:**
- `ActionStackSwap` (spec, source: SWF Specification v19)
- `SWF_ACTION_STACK_SWAP` (enum, source: action.hpp)
- `actionStackSwap` (function, source: action.h)

**Function Declaration:**
```c
void actionStackSwap(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_STACK_SWAP)

**Notes:**
- Official SWF specification name (spec line 6660)

---

### 0X4E: ActionGetMember

**Name Variations:**
- `ActionGetMember` (spec, source: SWF Specification v19)
- `SWF_ACTION_GET_MEMBER` (enum, source: action.hpp)
- `actionGetMember` (function, source: action.h)

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

**Function Declaration:**
```c
void actionSetMember(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_SET_MEMBER)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-set-member-0x4f.md](SWFRecompDocs/prompts/completed/opcode-set-member-0x4f.md)

**Implementation Branch:**
- **Branch**: `origin/claude/implement-opcode-set-member-011CUqqpFbcbnzZ8QFBxdF1E`
- **Commit**: `65f2d22b52936b06419c0a9c6df9b3ed37d765d5`
- **Subject**: Implement SET_MEMBER opcode (0x4F) and dependencies

**Notes:**
- Official SWF specification name (spec line 6248)

---

### 0X50: ActionIncrement

**Name Variations:**
- `ActionIncrement` (spec, source: SWF Specification v19)
- `SWF_ACTION_INCREMENT` (enum, source: action.hpp)
- `actionIncrement` (function, source: action.h)

**Test Directories:**
- `SWFRecomp/tests/increment_swf_4`

**Function Declaration:**
```c
void actionIncrement(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_INCREMENT)

**Notes:**
- Official SWF specification name (spec line 6605)

---

### 0X51: ActionDecrement

**Name Variations:**
- `ActionDecrement` (spec, source: SWF Specification v19)
- `SWF_ACTION_DECREMENT` (enum, source: action.hpp)
- `actionDecrement` (function, source: action.h)

**Test Directories:**
- `SWFRecomp/tests/decrement_swf_4`

**Function Declaration:**
```c
void actionDecrement(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_DECREMENT)

**Notes:**
- Official SWF specification name (spec line 6586)

---

### 0X52: ActionCallMethod

**Name Variations:**
- `ActionCallMethod` (spec, source: SWF Specification v19)
- `actionCallMethod` (function, source: action.h)

**Function Declaration:**
```c
void actionCallMethod(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- SWFModernRuntime/src/actionmodern/action.c

**Notes:**
- Official SWF specification name (spec line 5831)

---

### 0X53: ActionNewMethod

**Name Variations:**
- `ActionNewMethod` (spec, source: SWF Specification v19)
- `SWF_ACTION_NEW_METHOD` (enum, source: action.hpp)
- `actionNewMethod` (function, source: action.h)

**Function Declaration:**
```c
void actionNewMethod(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_NEW_METHOD)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-new-method-0x53.md](SWFRecompDocs/prompts/completed/opcode-new-method-0x53.md)

**Implementation Branch:**
- **Branch**: `origin/claude/implement-opcode-0x53-method-011CUquz2wcCAhXKTfy6ug9x`
- **Commit**: `80136be832c77e5b7e0371987cbe6cae912fb729`
- **Subject**: Implement NEW_METHOD opcode (0x53)

**Notes:**
- Official SWF specification name (spec line 6184)

---

### 0X54: ActionInstanceOf

**Name Variations:**
- `ActionInstanceOf` (spec, source: SWF Specification v19)

**Notes:**
- Official SWF specification name (spec line 6782)

---

### 0X55: ActionEnumerate2

**Name Variations:**
- `ActionEnumerate2` (spec, source: SWF Specification v19)
- `SWF_ACTION_ENUMERATE2` (enum, source: action.hpp)
- `actionEnumerate2` (function, source: action.h)

**Test Directories:**
- `SWFRecomp/tests/enumerate2_swf_6`

**Function Declaration:**
```c
void actionEnumerate2(char* stack, u32* sp, char* str_buffer);
```

**Implementation:**
- parseActions (case SWF_ACTION_ENUMERATE2)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-enumerate2-0x55.md](SWFRecompDocs/prompts/completed/opcode-enumerate2-0x55.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-enumerate2-0x55-011CUqus5xEVytTKvwVar7WW`
- **Commit**: `5ee877d6d80387875c1f269ee3bc09d37adb1092`
- **Subject**: Implement ENUMERATE2 opcode (0x55) for SWF 6+ property enumeration

**Notes:**
- Official SWF specification name (spec line 6806)

---

### 0X5A: Unknown

**Name Variations:**
- `SWF_ACTION_DELETE` (enum, source: action.hpp)

**Test Directories:**
- `SWFRecomp/tests/delete_swf_5`

**Implementation:**
- parseActions (case SWF_ACTION_DELETE)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-delete-0x5a.md](SWFRecompDocs/prompts/completed/opcode-delete-0x5a.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-delete-0x5a-011CUqutNyCjGYCvA8jEoP4y`
- **Commit**: `d985ca6b7d54546eccd19ee6068a8d9d2bbf7531`
- **Subject**: Implement DELETE opcode (0x5A) for ActionScript 2

**Notes:**
- C++ enum value for opcode

---

### 0X5B: Unknown

**Name Variations:**
- `SWF_ACTION_DELETE2` (enum, source: action.hpp)

**Test Directories:**
- `SWFRecomp/tests/delete2_swf_5`

**Implementation:**
- parseActions (case SWF_ACTION_DELETE2)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-delete2-0x5b.md](SWFRecompDocs/prompts/completed/opcode-delete2-0x5b.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-delete2-0x5b-011CUquufkHrk6Pt1ggisyZL`
- **Commit**: `2bb7cfff8754f73d7eb1fd14ba91e99817be3bf4`
- **Subject**: Implement DELETE2 opcode (0x5B) - Object property deletion

**Notes:**
- C++ enum value for opcode

---

### 0X60: ActionBitAnd

**Name Variations:**
- `ActionBitAnd` (spec, source: SWF Specification v19)
- `SWF_ACTION_BIT_AND` (enum, source: action.hpp)
- `actionBitAnd` (function, source: action.h)

**Function Declaration:**
```c
void actionBitAnd(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_BIT_AND)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-bit-and-0x60.md](SWFRecompDocs/prompts/completed/opcode-bit-and-0x60.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-bit-and-0x60-011CUqSTKKr3twXcRVWnFhfN`
- **Commit**: `24c5cdffc24f6cc602a8283f78a870ffa8a3a9d9`
- **Subject**: Implement BIT_AND opcode (0x60) for ActionScript 2

**Notes:**
- Official SWF specification name (spec line 6457)

---

### 0X61: ActionBitOr

**Name Variations:**
- `ActionBitOr` (spec, source: SWF Specification v19)
- `SWF_ACTION_BIT_OR` (enum, source: action.hpp)
- `actionBitOr` (function, source: action.h)

**Function Declaration:**
```c
void actionBitOr(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_BIT_OR)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-bit-or-0x61.md](SWFRecompDocs/prompts/completed/opcode-bit-or-0x61.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-bit-or-0x61-011CUqVjXPv9HusHiVtc6TGw`
- **Commit**: `c84503abf6326e8bdb04fd6d948695b4569d4801`
- **Subject**: Implement BIT_OR opcode (0x61) for ActionScript 2

**Notes:**
- Official SWF specification name (spec line 6497)

---

### 0X62: ActionBitXor

**Name Variations:**
- `ActionBitXor` (spec, source: SWF Specification v19)
- `SWF_ACTION_BIT_XOR` (enum, source: action.hpp)
- `actionBitXor` (function, source: action.h)

**Function Declaration:**
```c
void actionBitXor(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_BIT_XOR)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-bit-xor-0x62.md](SWFRecompDocs/prompts/completed/opcode-bit-xor-0x62.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-bit-xor-0x62-011CUqVkkQnMQwzLk76tgFdA`
- **Commit**: `0cb58244e28e4f3c842d5c1ae8d07ca6b9b0ad18`
- **Subject**: Implement BIT_XOR opcode (0x62) for ActionScript 2

**Notes:**
- Official SWF specification name (spec line 6563)

---

### 0X63: ActionBitLShift

**Name Variations:**
- `ActionBitLShift` (spec, source: SWF Specification v19)
- `SWF_ACTION_BIT_LSHIFT` (enum, source: action.hpp)
- `actionBitLShift` (function, source: action.h)

**Function Declaration:**
```c
void actionBitLShift(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_BIT_LSHIFT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-bit-lshift-0x63.md](SWFRecompDocs/prompts/completed/opcode-bit-lshift-0x63.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-bit-lshift-0x63-011CUqVnDyW9hL8bDRoCyrSZ`
- **Commit**: `6adec98bba782efd8516f67af512f4460ef80867`
- **Subject**: Implement BIT_LSHIFT opcode (0x63) for ActionScript 2

**Notes:**
- Official SWF specification name (spec line 6476)

---

### 0X64: ActionBitRShift

**Name Variations:**
- `ActionBitRShift` (spec, source: SWF Specification v19)
- `SWF_ACTION_BIT_RSHIFT` (enum, source: action.hpp)
- `actionBitRShift` (function, source: action.h)

**Function Declaration:**
```c
void actionBitRShift(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_BIT_RSHIFT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-bit-rshift-0x64.md](SWFRecompDocs/prompts/completed/opcode-bit-rshift-0x64.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-bit-rshift-0x64-011CUqVp4jS5TmGv6wrUvggt`
- **Commit**: `ac378945d5e4372147e701c69aa8f37510a67e0a`
- **Subject**: Implement BIT_RSHIFT opcode (0x64) for ActionScript 2

**Notes:**
- Official SWF specification name (spec line 6517)

---

### 0X65: ActionBitURShift

**Name Variations:**
- `ActionBitURShift` (spec, source: SWF Specification v19)
- `SWF_ACTION_BIT_URSHIFT` (enum, source: action.hpp)
- `actionBitURShift` (function, source: action.h)

**Function Declaration:**
```c
void actionBitURShift(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_BIT_URSHIFT)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-bit-urshift-0x65.md](SWFRecompDocs/prompts/completed/opcode-bit-urshift-0x65.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-bit-urshift-0x65-011CUqVqFVcxjU7FyuaVQmaJ`
- **Commit**: `f6cc4cdbc522c20f7df48d85870caa95a934b148`
- **Subject**: Implement BIT_URSHIFT opcode (0x65) for ActionScript 2

**Notes:**
- Official SWF specification name (spec line 6541)

---

### 0X66: ActionStrictEquals

**Name Variations:**
- `ActionStrictEquals` (spec, source: SWF Specification v19)
- `SWF_ACTION_STRICT_EQUALS` (enum, source: action.hpp)
- `actionStrictEquals` (function, source: action.h)

**Function Declaration:**
```c
void actionStrictEquals(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_STRICT_EQUALS)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-strict-equals-0x66.md](SWFRecompDocs/prompts/completed/opcode-strict-equals-0x66.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-strict-equals-0x66-011CUqVg8PjXUUbRMxgc4YVB`
- **Commit**: `5367dc91ade751214ce4f9b1c0959bab15bf3f6a`
- **Subject**: Implement STRICT_EQUALS opcode (0x66) for ActionScript 2

**Notes:**
- Official SWF specification name (spec line 6829)

---

### 0X67: ActionGreater

**Name Variations:**
- `ActionGreater` (spec, source: SWF Specification v19)
- `SWF_ACTION_GREATER` (enum, source: action.hpp)
- `actionGreater` (function, source: action.h)

**Test Directories:**
- `SWFRecomp/tests/greater_swf_4`

**Function Declaration:**
```c
void actionGreater(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_GREATER)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-greater-0x67.md](SWFRecompDocs/prompts/completed/opcode-greater-0x67.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-greater-0x67-011CUqVaJqcbH4RtE6aUYjdr`
- **Commit**: `ecbbd2b83213ce340b24df5b748e99b505fb5ba1`
- **Subject**: Fix GREATER opcode hex value from 0x48 to 0x67

**Notes:**
- Official SWF specification name (spec line 6848)

---

### 0X68: ActionStringGreater

**Name Variations:**
- `ActionStringGreater` (spec, source: SWF Specification v19)
- `SWF_ACTION_STRING_GREATER` (enum, source: action.hpp)
- `actionStringGreater` (function, source: action.h)

**Function Declaration:**
```c
void actionStringGreater(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_STRING_GREATER)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-string-greater-0x68.md](SWFRecompDocs/prompts/completed/opcode-string-greater-0x68.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-string-greater-0x68-011CUqVejVoGZ9nRiJM9nwVE`
- **Commit**: `874e6ecce97598d896b7b2f05d4c47a7e986e970`
- **Subject**: Implement STRING_GREATER opcode (0x68) for ActionScript 2

**Notes:**
- Official SWF specification name (spec line 6870)

---

### 0X69: ActionExtends

**Name Variations:**
- `ActionExtends` (spec, source: SWF Specification v19)

**Documentation:**
- [SWFRecompDocs/prompts/opcode-extends-0x69.md](SWFRecompDocs/prompts/opcode-extends-0x69.md)

**Notes:**
- Official SWF specification name (spec line 7120)

---

### 0X81: ActionGotoFrame

**Name Variations:**
- `ActionGotoFrame` (spec, source: SWF Specification v19)

**Notes:**
- Official SWF specification name (spec line 4258)

---

### 0X83: ActionGetURL

**Name Variations:**
- `ActionGetURL` (spec, source: SWF Specification v19)

**Notes:**
- Official SWF specification name (spec line 4281)

---

### 0X87: ActionStoreRegister

**Name Variations:**
- `ActionStoreRegister` (spec, source: SWF Specification v19)
- `SWF_ACTION_STORE_REGISTER` (enum, source: action.hpp)
- `actionStoreRegister` (function, source: action.h)

**Function Declaration:**
```c
void actionStoreRegister(char* stack, u32* sp, u8 register_num);
```

**Implementation:**
- parseActions (case SWF_ACTION_STORE_REGISTER)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-store-register-0x87.md](SWFRecompDocs/prompts/completed/opcode-store-register-0x87.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-store-register-0x87-011CUqqydram99y3sZsbqWkT`
- **Commit**: `f308ca4dfe0eb38426e54c168da941f732fab719`
- **Subject**: Implement StoreRegister opcode (0x87)

**Notes:**
- Official SWF specification name (spec line 6678)

---

### 0X88: ActionConstantPool

**Name Variations:**
- `ActionConstantPool` (spec, source: SWF Specification v19)
- `SWF_ACTION_CONSTANT_POOL` (enum, source: action.hpp)

**Implementation:**
- parseActions (case SWF_ACTION_CONSTANT_POOL)

**Notes:**
- Official SWF specification name (spec line 5868)

---

### 0X8A: ActionWaitForFrame

**Name Variations:**
- `ActionWaitForFrame` (spec, source: SWF Specification v19)

**Notes:**
- Official SWF specification name (spec line 4393)

---

### 0X8B: ActionSetTarget

**Name Variations:**
- `ActionSetTarget` (spec, source: SWF Specification v19)

**Notes:**
- Official SWF specification name (spec line 4437)

---

### 0X8C: ActionGoToLabel

**Name Variations:**
- `ActionGoToLabel` (spec, source: SWF Specification v19)

**Notes:**
- Official SWF specification name (spec line 4449)

---

### 0X8D: ActionWaitForFrame2

**Name Variations:**
- `ActionWaitForFrame2` (spec, source: SWF Specification v19)

**Notes:**
- Official SWF specification name (spec line 5655)

---

### 0X8E: ActionDefineFunction2

**Name Variations:**
- `ActionDefineFunction2` (spec, source: SWF Specification v19)
- `SWF_ACTION_DEFINE_FUNCTION2` (enum, source: action.hpp)
- `actionDefineFunction2` (function, source: action.h)

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

**Notes:**
- Official SWF specification name (spec line 7191)

---

### 0X94: ActionWith

**Name Variations:**
- `ActionWith` (spec, source: SWF Specification v19)
- `SWF_ACTION_WITH` (enum, source: action.hpp)

**Test Directories:**
- `SWFRecomp/tests/with_swf_5`

**Implementation:**
- parseActions (case SWF_ACTION_WITH)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-with-0x94.md](SWFRecompDocs/prompts/completed/opcode-with-0x94.md)

**Implementation Branch:**
- **Branch**: `origin/claude/review-opcode-0x94-docs-011CUqv4hzUhu2AxFawLjQRF`
- **Commit**: `eac8864411b07eeb460edcd4848938b78184821c`
- **Subject**: Implement WITH statement (opcode 0x94) with scope chain

**Notes:**
- Official SWF specification name (spec line 6289)

---

### 0X96: ActionPush

**Name Variations:**
- `ActionPush` (spec, source: SWF Specification v19)
- `SWF_ACTION_PUSH` (enum, source: action.hpp)

**Implementation:**
- parseActions (case SWF_ACTION_PUSH)

**Notes:**
- Official SWF specification name (spec line 4556)

---

### 0X99: ActionJump

**Name Variations:**
- `ActionJump` (spec, source: SWF Specification v19)
- `SWF_ACTION_JUMP` (enum, source: action.hpp)

**Test Directories:**
- `SWFRecomp/tests/jump_swf_4`

**Implementation:**
- parseActions (case SWF_ACTION_JUMP)

**Notes:**
- Official SWF specification name (spec line 5139)

---

### 0X9A: ActionGetURL2

**Name Variations:**
- `ActionGetURL2` (spec, source: SWF Specification v19)

**Notes:**
- Official SWF specification name (spec line 5262)

---

### 0X9B: ActionDefineFunction

**Name Variations:**
- `ActionDefineFunction` (spec, source: SWF Specification v19)
- `SWF_ACTION_DEFINE_FUNCTION` (enum, source: action.hpp)

**Implementation:**
- parseActions (case SWF_ACTION_DEFINE_FUNCTION)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-define-function-0x9b.md](SWFRecompDocs/prompts/completed/opcode-define-function-0x9b.md)

**Implementation Branch:**
- **Branch**: `origin/claude/read-opcode-define-function-011CUqv1Yar8czBGx2TBLEKq`
- **Commit**: `c955e9b6fe8054a3b7896510f0803c4dace174ca`
- **Subject**: Implement DEFINE_FUNCTION opcode (0x9B) for AS2 function definitions

**Notes:**
- Official SWF specification name (spec line 5894)

---

### 0X9D: ActionIf

**Name Variations:**
- `ActionIf` (spec, source: SWF Specification v19)
- `SWF_ACTION_IF` (enum, source: action.hpp)

**Test Directories:**
- `SWFRecomp/tests/if_swf_4`

**Implementation:**
- parseActions (case SWF_ACTION_IF)

**Notes:**
- Official SWF specification name (spec line 5163)

---

### 0X9E: ActionCall

**Name Variations:**
- `ActionCall` (spec, source: SWF Specification v19)
- `SWF_ACTION_CALL` (enum, source: action.hpp)
- `actionCall` (function, source: action.h)

**Test Directories:**
- `SWFRecomp/tests/call_swf_4`

**Function Declaration:**
```c
void actionCall(char* stack, u32* sp);
```

**Implementation:**
- parseActions (case SWF_ACTION_CALL)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-call-0x9e.md](SWFRecompDocs/prompts/completed/opcode-call-0x9e.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-call-0x9e-011CUqqxAw4Cd4VdGoYqDDVq`
- **Commit**: `68f22c53ace3c0e60aa3bc446c252c9f92c23e59`
- **Subject**: Implement CALL opcode (0x9E) - ActionScript 2 frame subroutine calls

**Notes:**
- Official SWF specification name (spec line 5195)

---

### 0X9F: ActionGotoFrame2

**Name Variations:**
- `ActionGotoFrame2` (spec, source: SWF Specification v19)
- `SWF_ACTION_CALL_METHOD` (enum, source: action.hpp)

**Implementation:**
- parseActions (case SWF_ACTION_CALL_METHOD)

**Documentation:**
- [SWFRecompDocs/prompts/completed/opcode-call-method-0x9f.md](SWFRecompDocs/prompts/completed/opcode-call-method-0x9f.md)

**Implementation Branch:**
- **Branch**: `origin/claude/opcode-call-method-0x9f-011CUquxpiNPgc5MXYU71YCQ`
- **Commit**: `1489c3ee1455923b589789b67f4cf947ccd26547`
- **Subject**: Implement CALL_METHOD opcode (0x9F) for ActionScript 2

**Notes:**
- Official SWF specification name (spec line 5344)

---
