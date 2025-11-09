# ActionThrow (0x2A) Test

This test validates the **THROW** opcode (0x2A) which implements exception throwing in ActionScript 2.

## Test Description

The test demonstrates:
1. Execution of code before a throw statement
2. Throwing a string exception
3. Termination of execution after throw (code after throw doesn't run)
4. Proper uncaught exception reporting

## Expected Output

```
Before throw
[Uncaught exception: Error message]
```

Note: The program exits with exit code 1 after throwing an uncaught exception.

## What's Tested

- ✅ ActionThrow properly pops exception value from stack
- ✅ Uncaught exceptions are reported with proper formatting
- ✅ Execution stops after throw (code after throw doesn't execute)

## Known Limitations

This test only covers **uncaught exceptions**. Full exception handling (try-catch-finally) requires:

1. **ActionTry (0x8F)** implementation for try-catch-finally blocks
2. **Fix for setjmp/longjmp implementation** - Currently has a known architectural flaw where setjmp is called inside a helper function instead of inline in the generated code, causing stack unwinding to not work correctly

See `test_info.json` for a complete list of missing features.

## Implementation Status

- **fully_implemented**: `false`
- **fully_implemented_no_graphics**: `false`

The basic throw functionality works correctly for uncaught exceptions, but full exception handling with try-catch-finally blocks is not yet working due to the setjmp/longjmp implementation issue documented in the runtime code.

## Building and Running

```bash
# From SWFRecomp directory
./scripts/build_test.sh throw_swf_7 native

# Run the test
./tests/throw_swf_7/build/native/throw_swf_7

# Validate output
./tests/throw_swf_7/build/native/throw_swf_7 2>&1 | \
  grep -v "SWF Runtime" | grep -v "===" | grep -v "\[Frame" | \
  ./tests/throw_swf_7/validate.py
```

## Specification Reference

From SWF specification:

> **ActionThrow** implements the ActionScript throw keyword. ActionThrow is used to signal, or throw, an exceptional condition, which is handled by the exception handlers declared with ActionTry.
>
> If any code within the try block throws an object, control passes to the catch block, if one exists, then to the finally block, if one exists. The finally block always executes, regardless of whether an error was thrown.
>
> If an exceptional condition occurs within a function and the function does not include a catch handler, the function and any caller functions are exited until a catch block is found (executing all finally handlers at all levels).

- **Opcode**: 0x2A
- **SWF Version**: 7+
- **Stack Effect**: Pops 1 value (the exception to throw)
