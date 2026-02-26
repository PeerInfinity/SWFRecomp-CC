# Parsing Functions (parseInt/parseFloat) Implementation Plan
<!-- TESTS: parse_int, parse_float, arguments -->

Last updated: 2026-02-26

## Status: COMPLETE (3/3 tests PASS)

### Current Results

| Test | Lines | Status | Notes |
|------|-------|--------|-------|
| parse_int | 64/64 | **PASS** ✅ | All edge cases passing |
| parse_float | 74/74 | **PASS** ✅ | Rewritten: custom Flash-compatible parser (f64, no Infinity, multiple dots, wrapping exponent) |
| arguments | 127/127 | **PASS** ✅ | All properties working: length, indices, callee, caller, __proto__ |

### Phase Completion

| Phase | Description | Status |
|-------|-------------|--------|
| 1 | `arguments` object for DefineFunction | **DONE** ✅ |
| 2 | parseInt edge cases | **DONE** ✅ |
| 3 | parseFloat custom parser | PARTIAL (using atof, edge cases fail) |

---

## Overview

Two tests cover the global `parseInt()` and `parseFloat()` functions. Both are currently failing but have been partially fixed: parseInt was rewritten from `atoi()` to proper radix-aware parsing, parseFloat no longer times out.

## Test Inventory

### parse_int (0/64 lines matching)

**Test structure**: Defines a `traceParseInt(...)` wrapper function (via `actionDefineFunction`, 0 named params) that:
1. Reads `arguments.length` to determine how many args were passed
2. Branches on length: 0 → calls `parseInt()`, 1 → calls `parseInt(arguments[0])`, 2 → calls `parseInt(arguments[0], arguments[1])`
3. Formats each argument via `arguments[0].toString()` for display
4. Traces `/*N*/ parseInt('arg') == result` or `/*N*/ parseInt('arg', radix) == result`

The main script calls `traceParseInt(...)` 64 times with varying arguments.

**Primary blocker**: The `arguments` object. The function accesses `arguments` via `actionGetVariable("arguments")`, then `arguments.length` and `arguments[N]` via `actionGetMember()`. If the runtime doesn't create an `arguments` local variable when calling a DefineFunction-style function, every line outputs garbage. This is the reason for 0/64.

**Secondary issues** (once arguments works): Several parseInt edge cases are wrong. Detailed in Phase 2 below.

### parse_float (TIMEOUT → likely ~45/74 after rewrite)

**Test structure**: Linear script — no loops, no wrapper functions. Calls `parseFloat(arg)` via `actionCallFunction()` 37 times with different inputs, interleaved with comment traces. Also tests `parseFloat(.1499999) === 0.14999990000000005` via StrictEquals, and `parseFloat(object_with_toString)` at the end.

**Timeout cause**: Likely the call to `parseFloat(Infinity)` — the script gets the `Infinity` variable (an F64 value), which the current implementation converts to the string `"Infinity"`, then `atof("Infinity")` returns `Infinity`, which is pushed as F32. But this should complete, not hang. The timeout may actually be in the compilation step (gcc with large string constants) or a runtime issue elsewhere. Needs investigation, but the implementation rewrite should resolve it regardless.

**Issues with current implementation**:
1. Uses `float` (F32) throughout — Flash uses double precision
2. 0 args returns NaN instead of `undefined`
3. `atof()` accepts "Infinity" — Flash returns NaN
4. `atof()` accepts hex "0xff" — Flash returns 0 (stops at 'x')
5. `atof()` returns 0 for empty/non-numeric strings — Flash returns NaN
6. `atof()` returns 0 for "e10" — Flash returns NaN (no leading digits)
7. No multiple-decimal-point handling — Flash ignores extra dots: `"1.2345.678"` → `1.2345678`
8. Exponent overflow: `"1e4294967297"` should be `10` (wraps as u32), not Infinity
9. Non-string non-number types return "NaN" string instead of calling `toString()`
10. `arg_buffer` is only 17 bytes — too small for double→string conversion of large values

---

## Phase 1: Fix `arguments` Object for DefineFunction

**Goal**: Make `arguments` variable available inside DefineFunction-style functions (not DefineFunction2, which uses registers). This unblocks parse_int and many other tests that use `arguments`.

### What needs to happen

When `actionCallFunction()` or `actionCallMethod()` calls a user-defined function created via `actionDefineFunction()`:

1. Create an `ASArray` containing the function's arguments
2. Set `arguments.length` to the number of args passed
3. Set `arguments[0]`, `arguments[1]`, etc. to each argument value
4. Register `arguments` as a local variable in the function's scope (via `actionDefineLocal` or direct scope insertion)

**Note**: DefineFunction2 (`actionDefineFunction2()`) has its own argument handling via registers and may or may not also need `arguments` — the spec says DefineFunction2 has an explicit flag (`PreloadArguments`) for this. The parse_int test uses DefineFunction (not DefineFunction2), so we only need to handle the DefineFunction case here.

### Where to implement

The function call dispatch is in `actionCallFunction()` in `action.c`. When the function name resolves to a user-defined `ASFunction`, the code currently:
1. Pops args from stack into an `ActionVar* args` array
2. Pushes a new scope/context
3. Sets named parameters as local variables
4. Calls the function pointer
5. Pops scope/context

We need to insert between steps 2 and 3:
- Create an `ASArray` with the args
- Set it as local variable `"arguments"` in the function's scope

### Impact on other tests

The `arguments` test (77/127 = 61% passing) will also improve. That test checks:
- `arguments.length` ✓ (from this change)
- `arguments[N]` access ✓ (from this change)
- `arguments.callee` — needs additional work (store function reference on arguments)
- `arguments.caller` — needs additional work (store calling function)
- `arguments` inheriting from `Array.prototype` — needs arguments to be an ASArray

### Tests fixed by Phase 1

- **parse_int**: Unblocked — will go from 0/64 to however many parseInt edge cases are correct
- **arguments**: Improved from 61% → higher (exact depends on callee/caller support)
- Any other tests that use `arguments` in DefineFunction-style functions

---

## Phase 2: Fix parseInt Edge Cases

**Goal**: Fix all parseInt edge cases to pass 64/64 lines in parse_int.

### Current implementation analysis

The parseInt implementation (action.c lines 13800-13982) is ~180 lines and handles most cases. Issues found by comparing expected output against the algorithm:

#### 2a. Leading whitespace stripping happens too late

**Current**: Whitespace stripping happens after the hex prefix check (line 13928). This means `" 0x100"` with no explicit radix does NOT strip whitespace before checking for `0x` — so `" 0x100"` would fail to detect hex.

**Expected**: Whitespace should be stripped FIRST, before sign and prefix detection.

**Test cases affected**:
- `/*27*/ parseInt(' 0x100', 36) == 1540944` — with radix 36, `' 0x100'` is parsed as base-36 with leading space stripped. The space matters because with radix 36 the `0x` prefix is NOT treated as hex.
- `/*43*/ parseInt(' 0') == 0`
- `/*44*/ parseInt(' 0 ') == 0`
- `/*46*/ parseInt('  077') == 77` — leading whitespace means NOT octal (Flash quirk)
- `/*47*/ parseInt('  077   ') == 77`
- `/*48*/ parseInt('  -077') == -77`
- `/*49*/ parseInt('077 ') == 77` — trailing non-octal chars mean NOT octal

#### 2b. Octal detection rules are wrong

**Current**: Checks if ALL remaining chars are 0-7 after sign. This is wrong — Flash's rule is:
- `"077"` → octal (63) — no whitespace, all digits 0-7
- `"  077"` → decimal (77) — leading whitespace disables octal
- `"077 "` → decimal (77) — trailing whitespace also disables octal
- `"-0100"` → octal (-64) — sign before 0 is fine
- `"-0100z"` → decimal (-100) — trailing non-digit 'z' disables octal

**Correct rule**: Octal ONLY if: (1) no explicit radix, (2) no leading whitespace (original string starts with optional sign then '0'), (3) ALL characters after the leading zero are 0-7 (no trailing non-octal characters).

#### 2c. Sign + 0x interaction for radix <= 33

**Test expectations**:
- `/*34*/ parseInt('-0x100') == NaN` — sign before 0x with no explicit radix → NaN ✓ (current is correct)
- `/*30*/ parseInt('-0x100', 36) == 1540944` — with radix 36, parse full string as base-36, sign applies
- `/*31*/ parseInt(' -0x100', 36) == -1540944` — leading space stripped, then sign + base-36 digits
- `/*35*/ parseInt('0x-100') == -256` — hex, sign AFTER 0x prefix is accepted
- `/*36*/ parseInt(' 0x-100') == 0` — space before 0x, hex detected, but then `-100` starts with `-` which is not a hex digit, so result is... wait, expected `0`. This is a special case.
- `/*37*/ parseInt('0x -100') == -256` — the space between 0x and digits is apparently ignored?

Looking more carefully:
- `parseInt('0x-100')` = -256: After stripping `0x`, the parse continues with `-100`. The sign is accepted in the digit stream position.
- `parseInt(' 0x-100')` = 0: Leading whitespace stripped, then `0x` prefix stripped, then `-` is encountered — not a valid hex digit, no digits found, but result is `0` not `NaN`. This suggests that when `0x` is detected but no valid hex digits follow, the result is `0` (from parsing the leading `0`).
- `parseInt('0x -100')` = -256: After `0x`, whitespace is stripped again, then `-100` is parsed as hex with sign.

This requires careful handling of the post-`0x` sign/whitespace parsing.

#### 2d. Radix 0 should return NaN

**Expected**: `parseInt('100', 0) == NaN` — radix 0 is treated as invalid (not as auto-detect).

**Current**: `radix = 0` is used as the auto-detect sentinel. When explicit radix is 0, need to return NaN.

#### 2e. Float radix truncation

**Expected**: `parseInt('11', 3.8) == 4` and `parseInt('0x12', 16.1) == 18` — radix is truncated (floor toward zero), not rounded.

**Current**: Uses `(int)rv` which truncates toward zero. This should be correct for positive values. Need to verify for negative values (though radix < 2 returns NaN anyway).

#### 2f. Very large number strings → Infinity

**Expected**: `parseInt('100000...000') == Infinity` (345 digits) — this tests that `result * radix + digit` accumulation eventually reaches Infinity via double overflow.

**Current**: Uses `double` accumulation with `result * (double)parse_radix + (double)digit`, which should naturally overflow to Infinity. Should work already.

### Implementation

Rewrite the whitespace/octal/hex prefix detection logic. The correct order is:

```
1. Strip leading whitespace from original string
2. Detect and consume sign (+/-)
3. Check for 0x/0X prefix:
   a. If no explicit radix: strip prefix, set radix = 16
   b. If explicit radix == 16: strip prefix
   c. If explicit radix >= 34: DON'T strip prefix (x is a valid digit)
   d. If explicit radix < 34 and != 16: DON'T strip prefix, DON'T change radix
4. If no explicit radix and no hex prefix:
   Check for octal: starts with '0', no leading whitespace in ORIGINAL string,
   ALL remaining chars are 0-7
5. Parse digits in determined radix
6. If no digits found: return NaN (except: if 0x was stripped but no hex digits,
   return 0 — representing the parsed '0' before 'x')
```

Special case for `0x-100`: After stripping `0x`, allow an optional sign character and optional whitespace before hex digits.

### Tests fixed by Phase 2

- **parse_int**: 0/64 → 64/64 (combined with Phase 1)

---

## Phase 3: Rewrite parseFloat

**Goal**: Replace the `atof()`-based parseFloat with a custom double-precision parser that matches Flash's behavior.

### Flash-specific parseFloat behaviors (deviating from ECMA-262/C's atof)

| Behavior | ECMA-262 / atof | Flash | Test line |
|----------|----------------|-------|-----------|
| No args | NaN | `undefined` | Line 2 |
| "Infinity" | Infinity | NaN | Line 52 |
| "-Infinity" | -Infinity | NaN | Line 54 |
| "+Infinity" | +Infinity | NaN | Line 56 |
| "" (empty) | NaN (atof: 0) | NaN | Line 60 |
| "-" (just sign) | NaN (atof: 0) | NaN | Line 62 |
| "0xff" (hex) | 255 (atof) | 0 | Line 64 |
| "e10" (no mantissa) | 0 (atof) | NaN | Line 40 |
| "1.2345.678" | 1.2345 (stops at 2nd dot) | 1.2345678 (ignores dots) | Line 46 |
| "1.2345.6e50" | 1.2345 | 1.23456 (dots ignored, exponent applies) | Line 48 |
| "10e" | 10 (incomplete exponent) | 10 | Line 38 |
| "10e-" | 10 (incomplete exponent) | 10 | Line 42 |
| "1e4294967297" | 1e+4294967297 = Infinity | 10 (exponent wraps as u32 → 1) | Line 44 |
| "10101010e-20.0" | stops at dot in exponent | 1.010101e-13 (dot terminates exp) | Line 36 |
| Boolean true | NaN | NaN (correct, but via toString→"true") | Line 68 |
| Object with toString | NaN | 5 (calls toString()) | Line 74 |

### Custom parser design

```c
static double flash_parseFloat(const char* str, int len, int* success) {
    // 1. Skip leading whitespace (space, tab, CR, LF)
    // 2. Optional sign (+/-)
    // 3. Must have at least one digit (0-9) or decimal point followed by digit
    //    - If first non-whitespace non-sign char is not 0-9 or '.', return NaN
    // 4. Parse integer part (digits before first dot)
    // 5. If '.' encountered:
    //    - Parse fractional digits
    //    - If ANOTHER '.' encountered: continue parsing digits (Flash ignores extra dots!)
    //    - Keep a separate "decimal places" counter that increments for each digit after ANY dot
    // 6. If 'e' or 'E' encountered:
    //    - Optional sign (+/-)
    //    - Parse exponent digits (stop at non-digit, including '.')
    //    - If no exponent digits: ignore the 'e' and sign, use mantissa only
    //    - Exponent overflow: cast to uint32_t before negating (wraps large values)
    // 7. Compute result: mantissa * 10^(exponent - decimal_places)
    // 8. Apply sign
    // 9. "Infinity"/"-Infinity"/"+Infinity" NOT recognized — return NaN
    // 10. "0xff" — stop at 'x', return 0 (parsed leading "0")
}
```

### Key implementation details

**Multiple decimal points**: Flash's parseFloat treats `.` as "switch to fractional mode" but doesn't stop parsing at a second `.`. Instead, subsequent dots are ignored and digits keep accumulating:
- `"1.2345.678"` → mantissa = 12345678, decimal_places = 7 → 1.2345678
- `"1.2345.6e50"` → mantissa = 123456, decimal_places = 5, but exponent has `e50` → 1.23456e50... wait, expected is `1.23456`. Let me re-read: expected output is `1.23456`. So `"1.2345.6e50"` actually means: after the second dot, parsing continues fractional digits (`6`), then hits `e50` which is the exponent. Result = 1.23456 * 10^50? No, expected is `1.23456`. Hmm.

Wait, re-reading the expected output more carefully:
```
// parseFloat("1.2345.6e50")
1.23456
```
So `1.2345.6e50` gives `1.23456`, NOT `1.23456e50`. This means the exponent is NOT applied when there are multiple decimal points. Or perhaps: after the second dot, the `e` is not recognized as exponent marker? Let me think about this...

Actually, the most likely explanation is: once a second `.` is encountered, the `e` that follows is treated as a potential exponent of the FIRST decimal number. But `"1.2345"` already has its own number, and `".6e50"` is... no, that doesn't make sense either.

Looking at the other multi-dot example:
```
// parseFloat("-2.123123.123219e20")
-2.123123123219
```
Here `-2.123123.123219e20` → `-2.123123123219`. The exponent `e20` is NOT applied. So the rule seems to be: **when there are multiple dots, the exponent is ignored**. Or more precisely: the parser collects all digit+dot characters until hitting `e`, then if there were multiple dots, it doesn't process the exponent.

Hmm wait, but `"10101010e-20.0"` → `1.010101e-13`. This has a dot IN the exponent. The expected output is `1.010101e-13`, which is `10101010 * 10^-20 = 1.010101e-13`. The `.0` at the end of the exponent is ignored (exponent parsing stops at the dot). So there's only ONE dot in the mantissa here.

Revised rule: The exponent is parsed normally (stop at non-digit except leading sign). Multiple dots in the mantissa cause... let me reconsider.

For `"1.2345.678"` → `1.2345678`: digits accumulated = 12345678, decimal places = 7, result = 1.2345678. No exponent.
For `"1.2345.6e50"` → `1.23456`: digits accumulated = 123456, decimal places = 5, result = 1.23456. Exponent `e50` is... not applied?

OR: The second `.` terminates parsing at the mantissa level, and `"1.2345"` is parsed first, then `.6e50` starts a new parse attempt that... no, parseFloat only parses once.

Actually, I think I need to reconsider. Perhaps Flash's behavior is:
- Parse digits and dots: `1.2345.6` → accumulate all as `1234.56` (decimal_places tracks from LAST dot)
  - After first `.`: decimal mode on, decimal_places = 0
  - `2345` → decimal_places = 4
  - Second `.`: reset decimal_places to 0? Or continue?

Let me try: after second dot, decimal_places counter continues (does NOT reset). So:
- `"1.2345.678"`: pre-dot = 1, first dot, digits = 2345 (4 places), second dot, digits = 678 (7 places total). Result = 12345678 / 10^7 = 1.2345678. ✓
- `"1.2345.6e50"`: pre-dot = 1, first dot, digits = 2345 (4 places), second dot, digits = 6 (5 places). Then `e50` → exponent = 50. Result = 123456 / 10^5 * 10^50 = 1.23456e+45. But expected is `1.23456`.

So the exponent IS being discarded when there are multiple dots. This is the Flash quirk.

Let me check: `"-2.123123.123219e20"` → `-2.123123123219`. Digits = 2123123123219, decimal places = 12, result = -2.123123123219. Exponent e20 ignored. ✓

So the rule is: **if there are 2+ decimal points in the mantissa, the exponent is ignored**.

For single-dot cases, exponent works normally:
- `"10101010e+100"` → 1.010101e+107 ✓
- `"10101010e-20.0"` → exponent parsing stops at `.`, so exponent = -20, result = 10101010e-20 = 1.010101e-13 ✓

**Exponent overflow wrapping**: `"1e4294967297"` → expected `10`. 4294967297 as uint32_t = 1 (wraps). So 1e1 = 10. This means the exponent value is computed in uint32_t arithmetic.

### Type coercion for non-string arguments

Current implementation only handles STRING, F32, F64 types. Need to also handle:
- **BOOLEAN**: `parseFloat(true)` → Flash converts to string "true" → NaN? No wait, expected is NaN. But the current code converts boolean to string "true" then atof returns 0. We need: boolean → NaN (don't even toString).
- Actually re-reading test: `parseFloat(true)` → NaN, `parseFloat(1.2)` → 1.2, `parseFloat(Infinity)` → NaN.

Flash's parseFloat type coercion:
- String → parse the string
- Number (F32/F64) → if finite, return as-is; if NaN/Infinity → NaN? No, `parseFloat(1.2)` → 1.2 and `parseFloat(Infinity)` → NaN. So: convert number to string, then parse. But `1.2` converts to "1.2" which parses to 1.2, and `Infinity` converts to "Infinity" which we return NaN for.
- Boolean → NaN (converts to "true"/"false", parsed as NaN)
- Object → call `toString()`, then parse the resulting string
- Undefined/null → `undefined` (0 args case: return undefined; but `parseFloat(undefined)` with 1 arg?... The test doesn't test this directly)

Actually, looking at the test, the non-string types tested are: `true` (boolean), `1.2` (double), `Infinity` (double → GetVariable resolves to Infinity), and `{toString: function(){return "5"}}` (object). The correct approach is:
1. If arg is a number: convert to string representation, then parse
2. If arg is boolean: "true"/"false" → parsed → NaN
3. If arg is object: call toString(), then parse
4. Anything else: NaN

### Implementation

Replace the entire parseFloat handler (~50 lines) with:

```c
// parseFloat(string) - Parse string to float (Flash/ECMA-262 with Flash quirks)
else if (func_name_len == 10 && strncmp(func_name, "parseFloat", 10) == 0)
{
    if (num_args == 0)
    {
        // Flash: parseFloat() returns undefined (not NaN)
        if (args != NULL) FREE(args);
        PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
        builtin_handled = 1;
    }
    else
    {
        // Convert argument to string
        char pf_buf[1024];
        const char* str_value = NULL;
        int need_parse = 1;

        if (args[0].type == ACTION_STACK_VALUE_STRING)
        {
            const uint16_t* u16 = varGetU16Ptr(&args[0]);
            u16_to_utf8(u16, args[0].str_size, pf_buf, sizeof(pf_buf));
            str_value = pf_buf;
        }
        else if (args[0].type == ACTION_STACK_VALUE_F32 || args[0].type == ACTION_STACK_VALUE_F64)
        {
            // Number: convert to string then parse
            double dval;
            if (args[0].type == ACTION_STACK_VALUE_F32)
                dval = (double)VAL(float, &args[0].data.numeric_value);
            else
                dval = VAL(double, &args[0].data.numeric_value);
            snprintf(pf_buf, sizeof(pf_buf), "%.17g", dval);
            str_value = pf_buf;
        }
        else if (args[0].type == ACTION_STACK_VALUE_OBJECT || ...)
        {
            // Object: call toString(), use result
            // ... toString dispatch ...
        }
        else
        {
            // Boolean, null, undefined, etc. → toString then parse
            str_value = convertString(...); // use existing convertString
        }

        // Custom Flash-compatible parseFloat
        double result = flash_parseFloat(str_value);

        if (args != NULL) FREE(args);
        // Push as F64 for full precision
        if (result != result) // NaN
        {
            float nan_val = 0.0f / 0.0f;
            PUSH(ACTION_STACK_VALUE_F32, VAL(u32, &nan_val));
        }
        else
        {
            PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &result));
        }
        builtin_handled = 1;
    }
}
```

The `flash_parseFloat()` static function (~100 lines) implements the custom parser with:
- Leading whitespace skip
- Sign handling
- Digit+dot accumulation (dots don't stop parsing, just increment decimal counter)
- Exponent parsing (stops at non-digit, u32 wrap for overflow)
- If multiple dots: discard exponent
- "Infinity" not recognized
- No hex support (stop at 'x')

### Tests fixed by Phase 3

- **parse_float**: TIMEOUT → ~70/74 passing (some edge cases may need iteration)

---

## Phase 2+3 Combined: parseInt Detailed Edge Cases

Below is every test case with expected output and whether the current implementation handles it correctly (assuming Phase 1 `arguments` fix is in place):

| # | Input | Expected | Current correct? | Issue |
|---|-------|----------|-----------------|-------|
| 0 | `parseInt()` | undefined | ✓ | |
| 1 | `parseInt('undefined')` | NaN | ✓ | |
| 2 | `parseInt('undefined', 32)` | 33790067563981 | ✓ | base-32 parse of "undefined" |
| 3 | `parseInt('')` | NaN | ✓ | |
| 4 | `parseInt('123')` | 123 | ✓ | |
| 5 | `parseInt('100', 10)` | 100 | ✓ | |
| 6 | `parseInt('100', 0)` | NaN | ✗ | radix 0 with explicit flag → invalid |
| 7 | `parseInt('100', 1)` | NaN | ✓ | radix < 2 |
| 8 | `parseInt('100', 2)` | 4 | ✓ | |
| 9 | `parseInt('100', 36)` | 1296 | ✓ | |
| 10 | `parseInt('100', 37)` | NaN | ✓ | radix > 36 |
| 11 | `parseInt('100', -1)` | NaN | ✓ | radix < 2 |
| 12 | `parseInt('100', {})` | NaN | ✓ | object → 0 → invalid |
| 13 | `parseInt('100', true)` | NaN | ✓ | true → 1 → invalid |
| 14 | `parseInt('100', false)` | NaN | ✓ | false → 0 → invalid |
| 15 | `parseInt('100', NaN)` | NaN | ✓ | NaN → 0 → invalid |
| 16 | `parseInt('100', undefined)` | NaN | ✓ | undefined → 0 → invalid |
| 17 | `parseInt('0x123')` | 291 | ✓ | |
| 18 | `parseInt('0xabc')` | 2748 | ✓ | |
| 19 | `parseInt('010', 2)` | 2 | ✓ | explicit radix 2 |
| 20 | `parseInt('-0100')` | -64 | ? | octal: no whitespace, all 0-7 |
| 21 | `parseInt('-0100z')` | -100 | ? | trailing 'z' disables octal → decimal, stops at 'z' |
| 22 | `parseInt('0x+0X100')` | 0 | ? | hex, '+' not hex digit → parsed '0' before 'x'... actually need to check |
| 23 | `parseInt('123')` | 123 | ✓ | (repeat) |
| 24 | `parseInt('123', 32)` | 1091 | ✓ | |
| 25 | `parseInt('++1')` | NaN | ✓ | double sign |
| 26 | `parseInt('0x100', 36)` | 1296 | ? | radix 36 overrides hex detection — '0x100' parsed as base-36 |
| 27 | `parseInt(' 0x100', 36)` | 1540944 | ? | leading space stripped, then parse ' 0x100' as base-36 = '0x100' in base 36 |
| 28 | `parseInt('0y100', 36)` | 1587600 | ✓ | base-36, 'y' is valid |
| 29 | `parseInt(' 0y100', 36)` | 1587600 | ✓ | |
| 30 | `parseInt('-0x100', 36)` | 1540944 | ? | sign + base-36 — but expected is POSITIVE. So sign is ignored for radix >= 34? |
| 31 | `parseInt(' -0x100', 36)` | -1540944 | ? | space + sign + base-36 — sign IS applied |
| 32 | `parseInt('-0y100', 36)` | -1587600 | ✓ | sign applied normally |
| 33 | `parseInt(' -0y100', 36)` | -1587600 | ✓ | |
| 34 | `parseInt('-0x100')` | NaN | ✓ | sign before 0x, no radix |
| 35 | `parseInt('0x-100')` | -256 | ? | sign after 0x prefix |
| 36 | `parseInt(' 0x-100')` | 0 | ? | space + 0x + sign → 0 (fallback to '0') |
| 37 | `parseInt('0x -100')` | -256 | ? | 0x + space + sign + digits → -256 (space after 0x OK) |
| 38 | `parseInt('-0100')` | -64 | ? | octal |
| 39 | `parseInt('0-100')` | 0 | ✓ | '-' not a digit → stop after '0' |
| 40 | `parseInt('+0x123', 33)` | NaN | ✓ | sign + 0x + radix ≤ 33 → NaN |
| 41 | `parseInt('+0x123', 34)` | 1298259 | ? | sign + radix ≥ 34 → parse full string (but should sign be applied?) |
| 42 | `parseInt('0')` | 0 | ✓ | |
| 43 | `parseInt(' 0')` | 0 | ✓ | |
| 44 | `parseInt(' 0 ')` | 0 | ✓ | |
| 45 | `parseInt('077')` | 63 | ? | octal: no whitespace, all 0-7 |
| 46 | `parseInt('  077')` | 77 | ? | leading whitespace → NOT octal → decimal |
| 47 | `parseInt('  077   ')` | 77 | ? | whitespace both sides → decimal |
| 48 | `parseInt('  -077')` | -77 | ? | whitespace → decimal |
| 49 | `parseInt('077 ')` | 77 | ? | trailing space → NOT octal → decimal |
| 50 | `parseInt('11', 2)` | 3 | ✓ | |
| 51 | `parseInt('11', 3)` | 4 | ✓ | |
| 52 | `parseInt('11', 3.8)` | 4 | ✓ | radix truncated |
| 53 | `parseInt('0x12')` | 18 | ✓ | |
| 54 | `parseInt('0x12', 16)` | 18 | ✓ | |
| 55 | `parseInt('0x12', 16.1)` | 18 | ✓ | |
| 56 | `parseInt('0x12', NaN)` | NaN | ✓ | |
| 57 | `parseInt('0x  ')` | NaN | ? | 0x + spaces, no hex digits |
| 58 | `parseInt('0x')` | NaN | ? | 0x with nothing after |
| 59 | `parseInt('0x  ', 16)` | NaN | ? | explicit radix 16, 0x stripped, spaces = no digits |
| 60 | `parseInt('0x', 16)` | NaN | ? | explicit radix 16, 0x stripped, no digits |
| 61 | `parseInt('12aaa')` | 12 | ✓ | stops at 'a' (radix 10) |
| 62 | `parseInt('10000...0')` | Infinity | ✓ | double overflow |
| 63 | `parseInt('0x10000...0')` | Infinity | ✓ | hex double overflow |

### Key behavioral rules for parseInt (Flash-specific)

1. **Whitespace stripping**: Strip leading whitespace from the input string FIRST
2. **Explicit radix 0**: treated as invalid (NaN), NOT as auto-detect
3. **Octal detection** (no explicit radix only): octal if the ORIGINAL string (before whitespace strip) has NO leading whitespace AND starts with optional sign + '0' AND all remaining chars are 0-7
4. **Hex prefix with radix ≥ 34**: `'x'` is a valid digit, so `0x` is not treated as a hex prefix. Parse as radix-N digits. Sign before `0x` with radix ≥ 34: the sign is ignored (result positive). Sign before `0x` with radix ≤ 33: NaN.
5. **Hex prefix with explicit radix 16**: Strip `0x` prefix (same as no-radix hex detection)
6. **Sign after hex prefix**: `'0x-100'` → strip `0x`, then allow sign + optional whitespace + digits
7. **`' 0x-100'`** → strip whitespace, detect `0x`, strip it, encounter `-` which is not a hex digit → no digits found, but the `0` before `x` was already consumed as part of prefix detection. Flash returns `0` here (effectively: "I parsed the `0` before seeing `x`").
8. **`'0x  '` and `'0x'`** → strip `0x`, no valid hex digits → return NaN (not 0, because the 0x prefix is stripped and there's nothing to parse)

Rule #7 vs #8 seems contradictory. Let me reconcile: for `' 0x-100'`, the leading space means hex detection found `0x`, stripped it, then saw `-` (not a hex digit). Since no hex digits were found after `0x`, but the string originally had a `0` before the `x`... Actually, I think the behavior is: when there's whitespace before `0x`, the hex detection works but the `0` is "consumed" by the prefix. For `'0x'` itself, no digits remain → NaN.

Wait, looking at test case #36 `parseInt(' 0x-100') == 0`: This could mean the parser falls back to parsing the `0` (before `x`) as a decimal number. The whitespace is stripped, giving `0x-100`. The `0` is parsed as decimal, `x` stops parsing → result is `0`.

Revised interpretation: The hex prefix detection (`0x`) only kicks in when there's no explicit radix (or radix == 16). When hex detection FAILS to find valid hex digits after the prefix, the parser falls back to parsing just the `0` as decimal. But for `parseInt('0x')` → NaN and `parseInt('0x  ')` → NaN. So the fallback only happens in certain conditions...

Actually, `parseInt('0x')` → NaN while `parseInt(' 0x-100')` → 0. The difference is the leading space:
- No space: `'0x-100'` → hex detected, parse after `0x`: sign `-`, digits `100` → -256
- Space: `' 0x-100'` → whitespace stripped to `'0x-100'`, hex detected, but... wait, this should be the same. Unless the leading whitespace changes the behavior.

Hmm, `parseInt('0x-100') == -256` but `parseInt(' 0x-100') == 0`. The ONLY difference is the leading space. This is a very strange Flash quirk. One possible explanation: hex detection only applies when the string starts with `0x` (after sign), NOT after whitespace. So:
- `'0x-100'`: starts with `0x` → hex mode → parse `-100` as hex (with sign) → -256
- `' 0x-100'`: starts with space → strip whitespace → now have `0x-100` → but hex detection works differently when whitespace was stripped? OR: `0x` is only detected when position 0 (or 1 after sign) is `0` and position 1 (or 2) is `x`, in the ORIGINAL string before whitespace strip.

That's the key insight: **Flash's parseInt only detects hex (`0x`) prefix at the ORIGINAL string position, not after whitespace stripping.** When whitespace is present:
- `' 0x-100'` → strip whitespace → see `0x`, but since original started with space, treat as decimal → parse `0`, stop at `x` → result 0

This matches the octal rule too: whitespace disables octal.

Let me verify against all test cases:
- `parseInt('0x123')` → no whitespace → hex → 291 ✓
- `parseInt(' 0x100', 36)` → whitespace → no hex → parse as base-36 `0x100` → 1540944 ✓ (Wait, this has explicit radix 36, so hex detection wouldn't apply anyway)

Hmm, for explicit radix cases the hex/octal detection logic is different. Let me separate:

**Auto-detect radix (no explicit radix):**
- No leading whitespace + starts with `0x`/`0X` (after optional sign) → radix 16, strip prefix
- No leading whitespace + starts with `0` + all chars are 0-7 → radix 8
- Otherwise → radix 10

**Explicit radix:**
- radix == 16: strip `0x` prefix if present (regardless of whitespace)
- radix ≥ 34: `x` is a valid digit, parse normally
- Other radix: parse digits in that radix, `0x` not special

This explains `' 0x-100'` → auto-detect, whitespace present → radix 10 → parse `0`, stop at `x` → 0. ✓

And `'0x-100'` → auto-detect, no whitespace → `0x` detected, strip prefix, parse `-100` as hex → -256. ✓

And `'0x -100'` → auto-detect, no whitespace → `0x` detected, strip prefix, then encounter space → skip whitespace after prefix → parse `-100` → -256. Wait, but if whitespace after `0x` is skipped, then `'0x  '` → strip `0x`, skip whitespace, no digits → NaN. ✓

Actually looking at `'0x -100'` → `-256`. After stripping `0x`, the parser sees ` -100`. It needs to skip whitespace, detect sign, then parse digits. This means **post-prefix whitespace IS stripped** but **pre-prefix whitespace disables prefix detection**.

This is a fully coherent set of rules. Let me formalize the algorithm now in the implementation section.

---

## Implementation Details

### Phase 1: arguments object

**Files to modify**: `SWFModernRuntime/src/actionmodern/action.c`

**Location**: Inside the function-call dispatch logic where user-defined functions are invoked. Search for where `ASFunction` pointers are called.

**Changes**:
1. After popping args from stack, before calling the function body:
   - Create an `ASArray` via `createArray(app_context)` or equivalent
   - Set `length` property to `num_args`
   - Set numeric index properties `"0"`, `"1"`, etc. to each `args[i]` value
   - Store as local variable `"arguments"` in the new scope

**Complexity**: Medium — requires understanding the scope setup for DefineFunction calls. Need to ensure it's only done for DefineFunction, not DefineFunction2 (unless PreloadArguments flag is set).

### Phase 2: parseInt rewrite

**Files to modify**: `SWFModernRuntime/src/actionmodern/action.c` (lines 13800-13982)

**Changes**: Replace the parseInt handler with corrected algorithm:

```
parseInt(str_value, radix, has_explicit_radix):
  1. original_str = str_value (save for whitespace detection)
  2. had_leading_whitespace = (str_value[0] is whitespace)
  3. Skip leading whitespace → s
  4. Handle explicit radix:
     - If explicit and radix == 0: return NaN
     - If explicit and (radix < 2 or radix > 36): return NaN
     - If not explicit: radix = 0 (auto-detect)
  5. Detect sign: if s[0] == '+'/'-', record sign, advance s
  6. Hex prefix detection:
     a. If s starts with '0x'/'0X':
        - If explicit radix >= 34: DON'T strip prefix (x is valid digit)
          If sign was present: ignore sign (result positive)
          Parse full string from s as radix-N digits
        - If explicit radix <= 33 AND sign was present: return NaN
        - If explicit radix == 16 OR no explicit radix:
          If had_leading_whitespace AND no explicit radix:
            Don't detect hex → fall through to decimal
          Else:
            Strip '0x', skip post-prefix whitespace
            Check for post-prefix sign (allow it)
            parse_radix = 16
     b. No hex prefix:
        - If no explicit radix AND NOT had_leading_whitespace:
          If s starts with '0' AND all remaining chars 0-7: parse_radix = 8
          Else: parse_radix = 10
        - If no explicit radix AND had_leading_whitespace: parse_radix = 10
        - If explicit radix: parse_radix = radix
  7. Parse digits in parse_radix, stop at invalid digit
  8. If no valid digits: return NaN
  9. Apply sign, return result
```

**Size**: ~200 lines (replacing existing ~180 lines)

### Phase 3: parseFloat rewrite

**Files to modify**: `SWFModernRuntime/src/actionmodern/action.c` (lines 13983-14033)

**Changes**: Replace entire parseFloat handler + add static helper function.

New `flash_parseFloat(const char* str)` function (~120 lines):
```
1. Skip whitespace
2. Record sign (+/-)
3. Parse mantissa: accumulate digits, track decimal_places, count dots
   - Each '.' increments dot_count and enables decimal mode
   - Each digit after first dot increments decimal_places
4. If no digits found: return NaN
5. If 'e'/'E' found AND dot_count <= 1:
   - Parse exponent sign and digits
   - If no exponent digits: ignore 'e'
   - Cast exponent to uint32_t (wraps overflow)
   - Apply sign to exponent
6. Compute: result = mantissa_integer * 10^(exponent - decimal_places)
7. Apply sign
8. Return result
```

**Size**: ~150 lines (replacing existing ~50 lines)

---

## Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | Phase 1: arguments object creation in function call dispatch. Phase 2: parseInt rewrite (~200 lines). Phase 3: parseFloat rewrite + static helper (~150 lines) |

No recompiler changes needed — both functions are called via `actionCallFunction()` with name dispatch.

---

## Verification

```bash
# After Phase 1 (arguments) + Phase 2 (parseInt):
python3 ruffle-tests/verify_output.py --test=parse_int --diff --verbose

# After Phase 3 (parseFloat):
python3 ruffle-tests/verify_output.py --test=parse_float --diff --verbose

# Also verify arguments test improves:
python3 ruffle-tests/verify_output.py --test=arguments --diff --verbose
```

---

## Estimated Impact

| Phase | Test | Before | After |
|-------|------|--------|-------|
| 1 | parse_int | 0/64 | ~50/64 (arguments works, parseInt edge cases remain) |
| 2 | parse_int | ~50/64 | 64/64 |
| 3 | parse_float | TIMEOUT | ~70/74 |
| 1 | arguments | 77/127 | ~90/127 (callee/caller still missing) |

**Total new passes**: 2 tests (parse_int + parse_float) fully passing, plus improved arguments test.

**Collateral improvement**: Any other tests that call parseInt/parseFloat (directly or via variable coercion paths) will benefit from correctness fixes. Any tests that use the `arguments` object in DefineFunction-style functions will also benefit from Phase 1.

---

## Risk Assessment

- **Phase 1 (arguments)**: Medium risk. The arguments object creation needs to be carefully placed to avoid breaking existing function call paths. DefineFunction2's register-based argument passing must not be affected.
- **Phase 2 (parseInt)**: Low risk. The edge cases are well-defined by the test. The main complexity is the hex prefix + whitespace interaction, which is unusual but testable.
- **Phase 3 (parseFloat)**: Medium risk. The custom parser must handle floating-point accumulation correctly to match Flash's precision. The multiple-decimal-point and exponent-wrapping behaviors are unusual and may need iteration against the test.
