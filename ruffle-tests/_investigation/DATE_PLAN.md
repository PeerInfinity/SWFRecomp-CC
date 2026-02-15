# Date Class Implementation Plan
<!-- TESTS: date -->

Last updated: 2026-02-15

## Status: NOT STARTED

---

## Overview

The `date` test is a single massive test (6,336 expected lines) that exercises every aspect of the Date class: constructors (0-7 args), `Date.UTC()`, 20 getter methods, 17 setter methods (each with multiple arg counts), `toString()`, and `valueOf()`. The test runs in SWF version 17 with timezone GMT+0545 (Nepal, UTC offset -345 minutes).

Currently there are only two minimal stubs in `actionNewObject`/`actionNewMethod` that create an empty ASObject with a single `time` property — no prototype methods, no toString, no constructor argument parsing. The stub "Date" constructor is registered in `ensureGlobalInit` as one of 19 bare constructors.

**About ~50% of lines in the test output are `//` comment lines** that the test traces before each operation. These comment lines will match automatically once the Date object produces any output at all, since they don't depend on Date behavior. The other ~50% are actual Date values that need correct implementation.

## Test Details

- **Test path**: `ruffle-tests/date/`
- **Expected output**: 6,336 lines
- **SWF version**: 17 (from `constants.h`)
- **Timezone**: GMT+0545 (Nepal, offset -345 minutes, no DST)
- **num_frames**: 1
- **Recompiled scripts**: 6 helper functions (`traceDate`, `testConstructor`, `testUTC`, `testSetDay`, `testSetTime`, `testSetTimestamp`)

### Test Structure

1. **Lines 1-74**: Constructor tests — `Date()` function call, `new Date()`, `new Date(ms)` with various values (0, 5.5, 500, -500, 1e3, ±1.59e12, ±8.64e15, ±8.64e15±1, NaN, ±Infinity)
2. **Lines 75-209**: Multi-arg constructor — `new Date(year, month[, day[, hour[, min[, sec[, ms]]]]])` with overflow, NaN, Infinity per-position
3. **Lines 211-308**: `Date.UTC()` — 0-7 args with NaN/Infinity per-position
4. **Lines 310-776**: Setter tests (setFullYear with 1/2/3 args, each tested with normal values, edge values, NaN, ±Infinity, and repeated to verify mutation)
5. **Lines 777-6336**: More setter tests (setMonth, setDate, setHours, setMinutes, setSeconds, setMilliseconds, setTime, setYear, and all UTC variants)

### toString Format

```
Day Mon DD HH:MM:SS GMT+HHMM YYYY
```

Examples:
- `Sat Feb 3 04:05:06 GMT+0545 2001`
- `Thu Jan 1 05:45:00 GMT+0545 1970`
- `Tue Apr 20 05:45:00 GMT+0545 -271821`
- `Invalid Date` (for NaN timestamp)

Day names: Sun, Mon, Tue, Wed, Thu, Fri, Sat
Month names: Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec

### Key Edge Cases

**Constructor (1-arg timestamp form):**
- `new Date(5.5)` — Time stores 5.5 (fractional ms preserved), getMilliseconds returns 5
- `new Date(8.64e15)` — maximum valid timestamp, produces year 275760
- `new Date(8.64e15 + 1)` — still displays same date but ms=1 (NOT NaN — Flash doesn't clamp like ES5)
- `new Date(NaN)` — toString = "Invalid Date", all getters return NaN
- `new Date(Infinity)` — toString = "Invalid Date", but getters return specific overflow values like -2147483578, NOT NaN

**Constructor (multi-arg form):**
- Year 0-99: maps to 1900+year (e.g., `new Date(1, 2)` → year 1901)
- Floats are truncated: `new Date(7002.5, 13.5, 32.5, ...)` → year=7002, month=13, day=32, etc.
- Month/day/hour/min/sec/ms overflow cascades (month 13 → next year, day 32 → next month, etc.)
- NaN year (multi-arg): converted via `(int32_t)` C cast → platform-dependent (INT_MIN on x86), produces specific non-NaN results with very large negative values
- NaN in month: → NaN result
- Infinity in day/hour/min/sec/ms: → Infinity/−Infinity result
- Infinity in month: → NaN result

**Setter NaN quirk (Flash-specific):**
- `setFullYear(NaN)` → NaN (standard)
- `setMonth(NaN)` → behaves as setMonth(0) (Flash converts NaN→0 for integer args)
- `setMonth(Infinity)` → NaN (integer overflow exceeds TimeClip range)
- Pattern: setter args appear to be converted via C-style `(int)x` where NaN→0 on Flash's platform

**Setter cascading args:**
- `setFullYear(year [, month [, day]])` — if month not supplied, keeps current month
- `setMonth(month [, day])` — if day not supplied, keeps current day
- `setHours(hour [, min [, sec [, ms]]])` — cascading
- `setMinutes(min [, sec [, ms]])` — cascading
- `setSeconds(sec [, ms])` — cascading
- UTC variants: same patterns but operate in UTC

**Timezone:**
- `getTimezoneOffset()` returns -345 (Nepal)
- For extreme dates (year 123456800): offset shows floating-point drift (-345.002666667)
- CI must run with `TZ=Asia/Kathmandu` for the test to pass

---

## Implementation Plan

### Phase 1: Core Infrastructure + Constructor + toString + valueOf

**Goal**: Get the internal Date representation working, handle all constructor forms, and produce correct toString output. This alone should jump from ~0% to ~60-70% match rate since comment lines + toString lines will match.

#### 1a. Date internal representation

Store the timestamp as a `double` (milliseconds since Unix epoch) in a well-known property on the ASObject. Use `"__date_time__"` as the internal property name (or store in the first property slot).

```c
// Internal timestamp access helpers
static double date_get_time(ASObject* obj) {
    ActionVar* v = getProperty(obj, "__date_time__", 13);
    if (!v || v->type != ACTION_STACK_VALUE_F64) return NAN;
    return VAL(double, &v->data.numeric_value);
}

static void date_set_time(SWFAppContext* ctx, ASObject* obj, double t) {
    ActionVar v = {0};
    v.type = ACTION_STACK_VALUE_F64;
    VAL(double, &v.data.numeric_value) = t;
    setProperty(ctx, obj, "__date_time__", 13, &v);
}
```

#### 1b. Date math utility functions (pure double arithmetic)

Implement the ECMAScript 3 date math using `double` throughout. These are pure functions:

```c
#define MS_PER_DAY 86400000.0

// Core decomposition
static double day_from_time(double t);           // floor(t / MS_PER_DAY)
static double time_within_day(double t);          // t - day * MS_PER_DAY (handle negatives!)
static double days_in_year(double y);             // 365 or 366
static double day_from_year(double y);            // 365*(y-1970) + leap adjustments
static double time_from_year(double y);           // day_from_year(y) * MS_PER_DAY
static double year_from_time(double t);           // binary search or formula
static double in_leap_year(double t);             // 0 or 1
static double month_from_time(double t);          // 0-11
static double date_from_time(double t);           // 1-31
static double week_day(double t);                 // 0=Sun, 6=Sat
static double hour_from_time(double t);           // 0-23
static double min_from_time(double t);            // 0-59
static double sec_from_time(double t);            // 0-59
static double ms_from_time(double t);             // 0-999

// Composition
static double make_time(double h, double m, double s, double ms);
static double make_day(double year, double month, double date);
static double make_date(double day, double time);

// Timezone
static double local_tza(void);                    // fixed offset in ms (from system TZ)
static double utc_to_local(double t);             // t + local_tza()
static double local_to_utc(double t);             // t - local_tza()
```

**Critical**: Negative timestamp modular arithmetic. For `time_within_day(-500)`:
- `floor(-500 / 86400000) = -1` (floor, not truncate!)
- `time_within_day = -500 - (-1 * 86400000) = 86399500` (positive!)
- This gives Hours=23, Minutes=59, Seconds=59, Milliseconds=500 in UTC
- Use `fmod()` with care: `fmod(-500, 86400000)` = -500 in C, need to add MS_PER_DAY if negative

**Timezone approach**: At init time, compute the UTC offset from the system timezone. Use `time()` + `gmtime_r()` + `localtime_r()` to determine offset. For Nepal (no DST), this gives a constant -345 minutes = -20700000 ms. Store as a global.

#### 1c. Date constructor

Replace the existing stubs in `actionNewObject` and `actionNewMethod` with a proper constructor that handles all forms:

```c
static ASObject* construct_date(SWFAppContext* app_context, ActionVar* args, u32 arg_count)
{
    ASObject* date = allocObject(app_context, 4);
    date->__proto__ = g_date_prototype;  // or set via property

    double t;
    if (arg_count == 0) {
        // Current time
        t = (double)time(NULL) * 1000.0;
    } else if (arg_count == 1) {
        // Single arg: timestamp or copy
        t = convertFloat(app_context, &args[0]);
        // If arg is a Date object, get its time
    } else {
        // 2-7 args: year, month [, day [, hour [, min [, sec [, ms]]]]]
        double year_d = convertFloat(app_context, &args[0]);
        // Year: C-style int32 cast for NaN/Infinity handling
        int32_t yi = (int32_t)year_d;  // Platform-specific NaN→INT_MIN
        double year = (double)yi;
        if (yi >= 0 && yi <= 99) year = 1900.0 + year;

        double month = convertFloat(app_context, &args[1]);
        double day   = (arg_count >= 3) ? convertFloat(app_context, &args[2]) : 1.0;
        double hour  = (arg_count >= 4) ? convertFloat(app_context, &args[3]) : 0.0;
        double min   = (arg_count >= 5) ? convertFloat(app_context, &args[4]) : 0.0;
        double sec   = (arg_count >= 6) ? convertFloat(app_context, &args[5]) : 0.0;
        double ms    = (arg_count >= 7) ? convertFloat(app_context, &args[6]) : 0.0;

        // Truncate to integer (not round)
        month = trunc(month); day = trunc(day); hour = trunc(hour);
        min = trunc(min); sec = trunc(sec); ms = trunc(ms);

        double d = make_day(year, month, day);
        double time = make_time(hour, min, sec, ms);
        t = local_to_utc(make_date(d, time));
    }

    date_set_time(app_context, date, t);
    return date;
}
```

**Note**: The year conversion uses C-style `(int32_t)` cast which on most platforms gives INT_MIN (-2147483648) for NaN and Infinity. This matches Flash's behavior where `new Date(NaN, 0, ...)` produces specific non-NaN values. Need to verify this with `#pragma` or compiler flags if needed.

#### 1d. Date.prototype.toString

```c
static ActionVar builtin_date_toString(SWFAppContext* app_context, ActionVar* args,
                                        u32 arg_count, ActionVar* registers, void* this_obj)
{
    ASObject* date = (ASObject*)this_obj;
    double t = date_get_time(date);

    if (isnan(t)) {
        // Return "Invalid Date"
        return make_string_var("Invalid Date", 12);
    }

    double lt = utc_to_local(t);
    int year  = (int)year_from_time(lt);
    int month = (int)month_from_time(lt);
    int day   = (int)date_from_time(lt);
    int wday  = (int)week_day(lt);
    int hour  = (int)hour_from_time(lt);
    int min   = (int)min_from_time(lt);
    int sec   = (int)sec_from_time(lt);

    int offset_min = (int)(local_tza() / 60000.0);
    int offset_h = offset_min / 60;
    int offset_m = offset_min % 60;

    // Format: "Day Mon DD HH:MM:SS GMT+HHMM YYYY"
    char buf[64];
    snprintf(buf, sizeof(buf), "%s %s %d %02d:%02d:%02d GMT%+03d%02d %d",
             day_names[wday], month_names[month], day,
             hour, min, sec, offset_h, abs(offset_m), year);

    return make_string_var(buf, strlen(buf));
}
```

#### 1e. Date.prototype.valueOf

Returns the timestamp (for arithmetic comparisons):
```c
static ActionVar builtin_date_valueOf(SWFAppContext* app_context, ActionVar* args,
                                       u32 arg_count, ActionVar* registers, void* this_obj)
{
    ASObject* date = (ASObject*)this_obj;
    double t = date_get_time(date);
    ActionVar r = {0};
    r.type = ACTION_STACK_VALUE_F64;
    VAL(double, &r.data.numeric_value) = t;
    return r;
}
```

#### 1f. Date() function call (without new)

When `Date` is called as a function (not constructor), it returns a string representation of the current date/time. This needs special handling in `actionCallFunction` — detect when calling "Date" and return a string instead of constructing an object.

#### 1g. Date prototype registration

Following the Math object pattern, create a `g_date_prototype` with all methods registered as ASFunction objects. Initialize lazily via `initDatePrototype()`:

```c
static ASObject* g_date_prototype = NULL;
static ASFunction g_date_funcs[40];  // enough for all methods
static int g_date_init_done = 0;

static void initDatePrototype(SWFAppContext* app_context) {
    if (g_date_init_done) return;
    g_date_prototype = allocObject(app_context, 48);
    retainObject(g_date_prototype);

    // Register each method...
    // Also replace the stub Date constructor with a proper one
    // Set Date.UTC as a property on the Date constructor function
}
```

#### 1h. Remove existing Date stubs

Remove the `strcmp(ctor_name, "Date")` blocks from both `actionNewObject` and `actionNewMethod`. Replace with calls through the proper Date constructor function registered in `ensureGlobalInit`.

### Tests Fixed by Phase 1

With toString working, all the `// comment` trace lines (~50%) will match, plus all `toString()` output lines and `Time = ...` values. Estimated match rate: **~60-65%** of 6,336 lines.

---

### Phase 2: Getter Methods (20 methods)

**Goal**: Implement all getter methods on Date.prototype.

Each getter decomposes the internal timestamp into a component. Local getters apply timezone offset first; UTC getters operate on the raw timestamp.

| Method | Returns | Formula |
|--------|---------|---------|
| `getFullYear()` | year | `year_from_time(utc_to_local(t))` |
| `getYear()` | year - 1900 | `year_from_time(utc_to_local(t)) - 1900` |
| `getMonth()` | 0-11 | `month_from_time(utc_to_local(t))` |
| `getDate()` | 1-31 | `date_from_time(utc_to_local(t))` |
| `getDay()` | 0-6 | `week_day(utc_to_local(t))` |
| `getHours()` | 0-23 | `hour_from_time(utc_to_local(t))` |
| `getMinutes()` | 0-59 | `min_from_time(utc_to_local(t))` |
| `getSeconds()` | 0-59 | `sec_from_time(utc_to_local(t))` |
| `getMilliseconds()` | 0-999 | `ms_from_time(utc_to_local(t))` |
| `getTime()` | ms since epoch | `t` (raw) |
| `getTimezoneOffset()` | minutes | `-(local_tza() / 60000.0)` |
| `getUTCFullYear()` | year | `year_from_time(t)` |
| `getUTCYear()` | year - 1900 | `year_from_time(t) - 1900` |
| `getUTCMonth()` | 0-11 | `month_from_time(t)` |
| `getUTCDate()` | 1-31 | `date_from_time(t)` |
| `getUTCDay()` | 0-6 | `week_day(t)` |
| `getUTCHours()` | 0-23 | `hour_from_time(t)` |
| `getUTCMinutes()` | 0-59 | `min_from_time(t)` |
| `getUTCSeconds()` | 0-59 | `sec_from_time(t)` |
| `getUTCMilliseconds()` | 0-999 | `ms_from_time(t)` |

**NaN handling**: If internal timestamp is NaN, all getters return NaN (standard).

**Infinity handling**: If timestamp is ±Infinity, the getters compute values that overflow to specific int32 values (Flash-specific). The decomposition functions will naturally produce large or NaN doubles for Infinity inputs; then Flash casts to int32 giving INT_MIN-like values. We need to match the exact values from the expected output.

**Implementation**: Each getter is nearly identical — a thin wrapper that calls the appropriate decomposition function. Use a template-like approach with a single function that takes a decomposition function pointer.

### Tests Fixed by Phase 2

With getters working, the `FullYear = ..., Year = ..., Month = ...` lines in the traceDate output will match. This is the bulk of the remaining lines. Estimated cumulative match rate: **~85-90%**.

---

### Phase 3: Date.UTC() Static Method

**Goal**: Implement `Date.UTC()` as a property of the Date constructor function.

`Date.UTC()` takes 2-7 args and returns a UTC millisecond timestamp (a number, not a Date object).

```
Date.UTC(year, month [, date [, hours [, minutes [, seconds [, ms]]]]])
```

**Behavior:**
- 0-1 args: returns `undefined` (not NaN!)
- 2+ args: same component-to-timestamp logic as multi-arg constructor, WITHOUT timezone adjustment
- Year 0-99: maps to 1900+year (same as constructor)
- Returns the raw millisecond timestamp as a number

**NaN/Infinity edge cases (from test output):**
- NaN year → specific large number (-6.77681005680576e+19) — same INT_MIN cast as constructor
- NaN month → NaN
- NaN day/hour/min/sec/ms → NaN
- Infinity year → same as NaN year (-6.77681005680576e+19)
- Infinity in day through ms → Infinity
- Infinity in month → NaN
- -Infinity follows the same pattern with sign flipped for day through ms

**Implementation**: Reuse `make_day()` and `make_time()` from Phase 1, just skip the `local_to_utc()` step.

### Tests Fixed by Phase 3

The Date.UTC section is ~100 lines. Estimated cumulative: **~87-92%**.

---

### Phase 4: Setter Methods (17 methods)

**Goal**: Implement all setter methods with correct cascading argument handling.

Each setter modifies one or more date components and updates the internal timestamp. Setters return the new timestamp value (as a number). If the setter makes the date invalid, the internal timestamp becomes NaN.

#### Setter signatures and cascading

| Method | Args | Cascades |
|--------|------|----------|
| `setTime(ms)` | 1 | Direct timestamp set |
| `setMilliseconds(ms)` | 1 | ms only |
| `setSeconds(sec [, ms])` | 1-2 | sec, optional ms |
| `setMinutes(min [, sec [, ms]])` | 1-3 | min, optional sec+ms |
| `setHours(hour [, min [, sec [, ms]]])` | 1-4 | hour, optional min+sec+ms |
| `setDate(day)` | 1 | day only |
| `setMonth(month [, day])` | 1-2 | month, optional day |
| `setFullYear(year [, month [, day]])` | 1-3 | year, optional month+day |
| `setYear(year)` | 1 | year only (legacy) |
| `setUTCMilliseconds(ms)` | 1 | UTC ms only |
| `setUTCSeconds(sec [, ms])` | 1-2 | UTC sec, optional ms |
| `setUTCMinutes(min [, sec [, ms]])` | 1-3 | UTC min, optional sec+ms |
| `setUTCHours(hour [, min [, sec [, ms]]])` | 1-4 | UTC hour, optional min+sec+ms |
| `setUTCDate(day)` | 1 | UTC day only |
| `setUTCMonth(month [, day])` | 1-2 | UTC month, optional day |
| `setUTCFullYear(year [, month [, day]])` | 1-3 | UTC year, optional month+day |

#### Setter algorithm (example: setFullYear)

```
setFullYear(year [, month [, day]]):
  1. t = utc_to_local(this.time)     // get local time
  2. If t is NaN, set t = 0           // ES3 says use +0 for NaN date
  3. y = ToNumber(year)
  4. m = (month supplied) ? ToNumber(month) : month_from_time(t)
  5. d = (day supplied) ? ToNumber(day) : date_from_time(t)
  6. newDate = make_date(make_day(y, m, d), time_within_day(t))
  7. u = local_to_utc(newDate)        // convert back to UTC
  8. this.time = u
  9. return u
```

UTC variants skip the `utc_to_local` / `local_to_utc` conversions.

#### Flash-specific NaN handling in setters

**Critical quirk**: Flash's setter argument conversion differs from ECMAScript 3:

- `setFullYear(NaN)` → NaN (year stays as double, NaN propagates through make_day)
- `setMonth(NaN)` → **behaves as setMonth(0)** (Flash converts month via integer cast, NaN→0)
- `setDate(NaN)`, `setHours(NaN)`, etc. → likely similar (args converted to int, NaN→0)
- `setMonth(Infinity)` → NaN (int overflow → large month → timestamp exceeds range)

**Hypothesis**: Flash converts time component args (month, day, hour, min, sec, ms) via a C-style integer cast where `(int)NaN = 0` on Flash's platform. The year arg in `setFullYear` stays as a double and propagates NaN normally. This needs empirical verification against the test expectations.

**Implementation strategy**: Start with standard ECMAScript behavior. Then compare output against expected and adjust the NaN conversion for each setter to match Flash's exact behavior.

#### setYear (legacy)

`setYear(year)`: Similar to setFullYear but with the year 0-99 → 1900+year mapping:
```
If 0 <= ToInteger(year) <= 99: year = 1900 + ToInteger(year)
```

### Tests Fixed by Phase 4

The setter sections are the majority of remaining lines (~5000+ lines). Estimated cumulative: **~95-98%**.

---

### Phase 5: Edge Case Refinement

**Goal**: Match the remaining 2-5% of lines — Infinity overflow values, floating-point precision, and platform-specific NaN conversion.

#### 5a. Infinity timestamp getter overflow

When timestamp is ±Infinity, Flash's getters return specific overflow values:
```
FullYear = -2147481678, Year = -2147483578, Month = 0,
Date = -2147483647, Day = -2147483641, Hours = -2147483624,
Minutes = -2147483588, Seconds = -2147483588, Milliseconds = -2147482648
TimezoneOffset = NaN
```

These are `(int32_t)` casts of the decomposition results. We need to ensure our getter functions produce exactly these values for ±Infinity input. This likely means our decomposition functions need to:
1. Not early-return NaN for Infinity
2. Let the arithmetic proceed and overflow naturally
3. Cast the final result to int32 for output

#### 5b. Floating-point precision

For extreme dates (year 123456800), `getTimezoneOffset()` returns `-345.002666666667` instead of `-345`. This is because the timezone offset computation loses precision for dates far from epoch. Our implementation should use the same formula to naturally produce this drift.

#### 5c. NaN→0 setter conversion

Final tuning of the NaN→int conversion in setters to match Flash's platform behavior. May need to use:
```c
static int flash_to_int(double x) {
    if (isnan(x)) return 0;
    if (!isfinite(x)) return INT_MIN;
    return (int)trunc(x);
}
```
vs simply `(int)x` depending on compiler behavior.

#### 5d. toString for Infinity

`new Date(Infinity)` → "Invalid Date" (isnan check should also catch isinf for toString).
Actually from the output, Infinity timestamps show "Invalid Date" for toString but non-NaN values for getters. Need to determine the exact condition for "Invalid Date": `isnan(t)` only, or `!isfinite(t)`.

---

## CI Configuration

The test expects GMT+0545 (Nepal timezone). The CI workflow needs to set:
```yaml
env:
  TZ: Asia/Kathmandu
```

This must be set for both the build and run steps. For local testing:
```bash
TZ=Asia/Kathmandu python3 ruffle-tests/verify_output.py --test=date --diff --verbose
```

---

## Files to Modify

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | Date prototype init, constructor, all 37+ methods, Date.UTC(), remove existing stubs, update ensureGlobalInit |
| `include/actionmodern/action.h` | No changes expected (methods are static/internal) |

### No recompiler changes needed

The recompiler already handles `NewObject("Date")`, `CallMethod`, and `GetMember`/`SetMember` generically. All Date logic is purely runtime.

### Test infrastructure

| File | Changes |
|------|---------|
| `.github/workflows/ruffle-tests.yml` | Add `TZ: Asia/Kathmandu` environment variable |

---

## Implementation Estimate

The Date class is a single large block of work — all runtime, no recompiler changes. The code is ~500-700 lines of C:
- ~150 lines: date math utility functions
- ~50 lines: constructor + prototype initialization
- ~100 lines: toString/valueOf
- ~20 lines: Date.UTC
- ~200 lines: 37 getter/setter method bodies (most are 3-5 lines each)
- ~100 lines: edge case handling, NaN/Infinity

**Expected test impact**: 1 test (6,336 lines), moving from ~0% match to ~95%+ match. The absolute line gain is large (~6,000 lines) but the test count gain is just +1.

---

## Phase Summary

| Phase | Description | Estimated Match Rate |
|-------|-------------|---------------------|
| 1 | Constructor + toString + valueOf + infrastructure | ~60-65% |
| 2 | All 20 getter methods | ~85-90% |
| 3 | Date.UTC() static method | ~87-92% |
| 4 | All 17 setter methods | ~95-98% |
| 5 | Infinity/NaN edge case refinement | ~99-100% |

**Note**: Phases 1-4 can realistically be implemented together since they share the same date math infrastructure. The phasing is mainly for verification — check output after each phase to catch bugs early. Phase 5 is the polish pass for the last few percent.

---

## Verification Commands

```bash
# After each phase:
TZ=Asia/Kathmandu python3 ruffle-tests/verify_output.py --test=date --diff --verbose

# Check specific sections:
TZ=Asia/Kathmandu python3 ruffle-tests/verify_output.py --test=date --diff --verbose 2>&1 | head -100  # constructors
TZ=Asia/Kathmandu python3 ruffle-tests/verify_output.py --test=date --diff --verbose 2>&1 | grep "^-\|^+" | head -50  # first diffs
```
