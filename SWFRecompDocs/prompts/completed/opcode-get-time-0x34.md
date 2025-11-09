# Opcode Implementation Prompt: ActionGetTime (0x34)

## Opcode Specification

**Opcode Name**: ActionGetTime
**Hex Value**: 0x34
**Category**: Special
**Estimated Complexity**: SIMPLE
**SWF Version**: 5+

## Description

Returns the number of milliseconds since midnight, January 1, 1970 (Unix epoch time). Pushes the current time as a float onto the stack.

## Stack Operation

**Before**: `[...]`
**After**: `[... timestamp]`

Where `timestamp` is milliseconds since epoch

## Expected Behavior

1. Get current time from system
2. Convert to milliseconds since Unix epoch
3. Push as float onto the stack

**Time Source**:
- Uses `clock_gettime(CLOCK_REALTIME)` or similar
- Returns milliseconds (not seconds)
- Resolution: millisecond precision

## Implementation Status

✅ **Already Implemented**

- **Enum**: `SWF_ACTION_GET_TIME` in `SWFRecomp/include/action/action.hpp`
- **Translation**: Case in `SWFRecomp/src/action/action.cpp`
- **Function**: `actionGetTime()` in `SWFModernRuntime/src/actionmodern/action.c`

## Test Cases

### Test Case 1: Get Time
```actionscript
var t = getTimer();
trace(t);
```
**Expected output**: Large number (e.g., `1699564800000`)

### Test Case 2: Time Difference
```actionscript
var t1 = getTimer();
// ... do something ...
var t2 = getTimer();
trace(t2 - t1);
```
**Expected output**: Small number (milliseconds elapsed)

### Test Case 3: Time is Positive
```actionscript
var t = getTimer();
trace(t > 0);
```
**Expected output**: `1` (true)

## Similar Opcodes

- None directly similar
- Related to random number generation (both system-dependent)

## Notes

- **Non-deterministic** - output changes each run
- Requires range validation in tests
- Returns float representation of milliseconds
- Essential for timing and animation
- System clock dependent
