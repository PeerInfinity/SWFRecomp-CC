# Global Functions/Objects Implementation Plan

Last updated: 2026-02-14

## Overview

The "Global Functions/Objects" category covers tests that check which built-in classes, functions, and objects are registered on `_global` — and that their prototypes, properties, and methods exist. This is a "meta-category": fixing it requires registering stub constructors/objects for many Flash built-in classes, even when their full functionality is implemented elsewhere.

**Scope**: This plan covers registering missing globals, implementing the Math object, fixing parseInt/parseFloat/isFinite, and creating stub constructors for classes whose full implementations are covered by other plans (TextField, XML, etc.). It does NOT cover the full implementation of those classes — just making them exist as globals with the correct `typeof` and `.prototype`.

**Total tests in scope**: ~30 tests across several related categories
- **Core globals enumeration** (12 tests): globals_swf5/6/7/8, global_swf5_6_7_8_9, global_swf6_7_8, global_instance_decls, global_proto_decls, global_proto_decls_delete, swf5/6/7_global_funcs
- **Math object** (1 test): math_min_max
- **Parsing functions** (2 tests): parse_int, parse_float
- **isFinite** (2 tests): is_finite, is_finite_swf6
- **Primitive type globals** (1 test): primitive_type_globals
- **Stub-only classes** (~12 tests): printjob_props, context_menu, context_menu_item, localconnection_properties, sound_props, stage/selection/etc.

## Current Pass Rates

| Test | Lines | Pass Rate | Category |
|------|-------|-----------|----------|
| globals_swf5 | 210/304 | 69% | Core globals |
| globals_swf6 | 217/304 | 71% | Core globals |
| globals_swf7 | 214/304 | 70% | Core globals |
| globals_swf8 | 155/304 | 50% | Core globals |
| global_swf5_6_7_8_9 | 0/1145 | 0% | Cross-version |
| global_swf6_7_8 | 0/15 | 0% | Cross-version |
| global_instance_decls | 1/758 | 0% | Instance props |
| global_proto_decls | 4/4497 | 0% | Proto props |
| global_proto_decls_delete | 0/4158 | 0% | Proto delete |
| swf5_global_funcs | 1/232 | 0% | Global funcs |
| swf6_global_funcs | 1/232 | 0% | Global funcs |
| swf7_global_funcs | 1/232 | 0% | Global funcs |
| math_min_max | 32/101 | 31% | Math |
| parse_int | 0/64 | 0% | Parsing |
| parse_float | timeout | 0% | Parsing |
| is_finite | 24/49 | 48% | isFinite |
| is_finite_swf6 | 24/49 | 48% | isFinite |
| primitive_type_globals | 320/557 | 57% | Primitives |
| printjob_props_swf5 | 0/45 | 0% | Stub class |
| printjob_props_swf6 | 3/45 | 6% | Stub class |
| printjob_props_swf7 | 2/45 | 4% | Stub class |
| context_menu | 2/39 | 5% | Stub class |
| context_menu_item | 2/41 | 4% | Stub class |
| localconnection_properties | 4/8 | 50% | Stub class |
| sound_props_swf5 | 36/68 | 52% | Stub class |
| sound_props_swf6 | 31/68 | 45% | Stub class |

## What Tests Expect — Detailed Analysis

### globals_swf7 (representative of globals_swf5/6/7/8)

Each global is tested with 3 lines:
```
// Name
trace(Name)           → "[type Function]" or "[object Object]"
trace(typeof(Name))   → "function" or "object"
trace(typeof(Name.prototype)) → "object" or "undefined"
```

**Currently registered (21, lines already pass)**: Array, Boolean, Date (broken), Error, Function (SWF7+), Math (no methods), MovieClip, Number, Object, String, System (+ sub-objects), TextField, TextFormat, XML, XMLNode

**Missing constructors (18, each = 3 failing lines)**:
| Global | Type | Prototype | Notes |
|--------|------|-----------|-------|
| Accessibility | object | undefined | Static object, not constructor |
| AsBroadcaster | function | object | Has initialize(), addListener(), etc. |
| Button | function | object | Constructor for Button display objects |
| Camera | function | object | Stub only (hardware access) |
| Color | function | object | Needs full impl (separate plan) |
| ContextMenu | function | object | Stub with constructor + copy/hideBuiltInItems |
| ContextMenuItem | function | object | Stub with constructor |
| Key | object | undefined | Static object with isDown/getCode/etc. |
| LoadVars | function | object | Needs load/send methods |
| LocalConnection | function | object | Stub with connect/send/close |
| Microphone | function | object | Stub only (hardware access) |
| Mouse | object | undefined | Static object with addListener/removeListener |
| MovieClipLoader | function | object | Needs loadClip/getProgress/events |
| NetConnection | function | object | Stub |
| NetStream | function | object | Stub |
| PrintJob | function | object | Stub with start/addPage/send |
| Selection | object | undefined | Static object with setFocus/getFocus/etc. |
| SharedObject | function | object | Stub with getLocal/flush |
| Sound | function | object | Needs full impl (separate plan) |
| Stage | object | undefined | Needs properties (width/height/scaleMode/etc.) |
| TextSnapshot | function | object | Stub with prototype methods |
| Video | function | object | Stub |
| XMLSocket | function | object | Stub |
| TextField.StyleSheet | function | object | Sub-property of TextField constructor |

**SWF8-only globals** (flash.* namespace, 40 lines in globals_swf8 that are `undefined` in SWF7):
| Global | Type |
|--------|------|
| flash | object (namespace) |
| flash.display | object (namespace) |
| flash.display.BitmapData | function |
| flash.external | object (namespace) |
| flash.external.ExternalInterface | function |
| flash.filters | object (namespace) |
| flash.filters.* (10 filter classes) | function each |
| flash.geom | object (namespace) |
| flash.geom.ColorTransform | function |
| flash.geom.Matrix | function |
| flash.geom.Point | function |
| flash.geom.Rectangle | function |
| flash.geom.Transform | function |
| flash.net | object (namespace) |
| flash.net.FileReference | function |
| flash.net.FileReferenceList | function |
| flash.text | object (namespace) |
| flash.text.TextRenderer | function |

### Math object (math_min_max)

Currently Math exists as a global object but has **no methods**. All `Math.min(...)` / `Math.max(...)` calls return `undefined`. The test expects:
- `Math.min(1, 2)` → `1`
- `Math.min()` (no args) → `Infinity`
- `Math.min(1)` (one arg) → `NaN`
- `Math.max()` → `-Infinity`
- `Math.max(1)` → `NaN`
- Type coercion: string args converted via toNumber, valueOf() called on objects
- NaN propagation: any NaN argument → NaN result

### parseInt (parse_int, 64 lines, 0% passing)

Current `parseInt` uses `atoi()` — needs full reimplementation:
- **Radix support**: `parseInt('100', 2)` → 4, `parseInt('100', 36)` → 1296
- **Radix validation**: radix 0, 1, 37+, negative, NaN, undefined → NaN
- **Radix coercion**: `parseInt('11', 3.8)` → 4 (floor the radix)
- **No args**: `parseInt()` → `undefined` (not NaN)
- **Hex prefix**: `0x` → auto radix 16; `0` prefix → auto radix 8 (but NOT with leading spaces: `"  077"` → 77 decimal)
- **Negative hex**: `parseInt('-0x100')` → NaN, but `parseInt('0x-100')` → -256
- **Stop at invalid char**: `parseInt('12aaa')` → 12
- **Overflow**: Very large numbers → `Infinity`
- **Whitespace**: Leading whitespace stripped, but trailing whitespace makes octal → decimal

### isFinite (is_finite/is_finite_swf6, 49 lines each, 48% passing)

Currently partially working. Key issues:
- **String coercion**: `isFinite("0")` → true, `isFinite("0x10")` → true, `isFinite("123e-1")` → true
- **Empty/whitespace**: `isFinite("")` → false, `isFinite(" ")` → false, `isFinite("  5  ")` → false
- **Boolean**: `isFinite(true)` → true, `isFinite(false)` → true
- **No args**: `isFinite()` → false
- **valueOf**: Calls valueOf on objects

### primitive_type_globals (557 lines, 57% passing)

Tests Number, Boolean, String constructors in detail:
- **Number constants**: NaN, POSITIVE_INFINITY, NEGATIVE_INFINITY, MIN_VALUE, MAX_VALUE
- **Number.prototype.toString(radix)**: Converts to string in given radix (2-36)
- **Number.prototype.valueOf()**: Returns primitive value
- **Boolean()**: As converter function (without `new`), returns primitive
- **String()**: As converter function, returns primitive string

---

## Phase 1: Register Missing Global Constructors (Stubs)

**Goal**: Register all ~24 missing global constructors/objects so that `typeof(X)` returns the correct value and `X.prototype` exists as an object. This is pure registration — no method implementations.

### Implementation

In `action.c` initialization (the `_global` setup section), add:

```c
// Pattern for each constructor:
ASFunction* ctor = createFunction(app_context, "ConstructorName");
// Set it on _global
ActionVar ctor_var = {.type = ACTION_STACK_VALUE_FUNCTION};
ctor_var.data.fn = ctor;
setProperty(app_context, global_obj, "ConstructorName", ..., &ctor_var);

// Pattern for each static object (Accessibility, Key, Mouse, Selection, Stage):
ASObject* obj = createObject(app_context);
ActionVar obj_var = {.type = ACTION_STACK_VALUE_OBJECT};
obj_var.data.obj = obj;
setProperty(app_context, global_obj, "ObjectName", ..., &obj_var);
```

**Constructors to register** (type = function, has .prototype):
- AsBroadcaster, Button, Camera, Color, ContextMenu, ContextMenuItem, LoadVars, LocalConnection, Microphone, MovieClipLoader, NetConnection, NetStream, PrintJob, SharedObject, Sound, TextSnapshot, Video, XMLSocket

**Static objects to register** (type = object, no .prototype):
- Accessibility, Key, Mouse, Selection, Stage

**Sub-properties**:
- `TextField.StyleSheet` — set as property on the TextField constructor function

### SWF version gating

Some globals only exist in certain SWF versions:
- **SWF5**: No `Function` constructor (already handled), no `TextField` (constructor should exist but `.prototype` is undefined)
- **SWF7+**: `Function` constructor exists (already handled)
- **SWF8+**: `flash.*` namespace exists

The globals_swf5/6/7/8 tests all expect the same constructors to exist; the only differences are:
- SWF5: Function = undefined, TextField.prototype = undefined
- SWF7: Function = function, TextField.prototype = object
- SWF8: Same as SWF7 + flash.* namespace fully populated

### Tests improved by Phase 1

- **globals_swf5**: 69% → ~97% (only CustomActions/XMLUI/flash.*/mx.* remain undefined — those ARE expected undefined)
- **globals_swf6**: 71% → ~97%
- **globals_swf7**: 70% → ~100% (all globals registered)
- **globals_swf8**: 50% → ~67% (flash.* still missing — added in Phase 5)
- **printjob_props_swf5/6/7**: 0% → partial (PrintJob constructor exists, but prototype methods needed)
- **context_menu/context_menu_item**: 5% → partial
- **localconnection_properties**: 50% → ~75%
- **sound_props_swf5/6**: 52% → partial

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=globals_swf7 --diff --verbose
python3 ruffle-tests/verify_output.py --test=globals_swf5 --diff --verbose
```

---

## Phase 2: Math Object Methods

**Goal**: Implement all Math methods and constants. This is a self-contained feature with no dependencies on other classes.

### Constants

| Property | Value |
|----------|-------|
| Math.E | 2.718281828459045 |
| Math.LN2 | 0.6931471805599453 |
| Math.LN10 | 2.302585092994046 |
| Math.LOG2E | 1.4426950408889634 |
| Math.LOG10E | 0.4342944819032518 |
| Math.PI | 3.141592653589793 |
| Math.SQRT1_2 | 0.7071067811865476 |
| Math.SQRT2 | 1.4142135623730951 |

### Methods

All Math methods take numeric arguments. Arguments are coerced via `varToNumber()` (calling `valueOf()` on objects). NaN propagates.

| Method | Args | Behavior |
|--------|------|----------|
| abs(x) | 1 | `fabs(x)` |
| acos(x) | 1 | `acos(x)` |
| asin(x) | 1 | `asin(x)` |
| atan(x) | 1 | `atan(x)` |
| atan2(y, x) | 2 | `atan2(y, x)` |
| ceil(x) | 1 | `ceil(x)` |
| cos(x) | 1 | `cos(x)` |
| exp(x) | 1 | `exp(x)` |
| floor(x) | 1 | `floor(x)` |
| log(x) | 1 | `log(x)` (natural log) |
| max(a, b) | 2 | See below |
| min(a, b) | 2 | See below |
| pow(x, y) | 2 | `pow(x, y)` |
| random() | 0 | `(double)rand() / RAND_MAX` |
| round(x) | 1 | `floor(x + 0.5)` (round half up) |
| sin(x) | 1 | `sin(x)` |
| sqrt(x) | 1 | `sqrt(x)` |
| tan(x) | 1 | `tan(x)` |

**Math.min/max special behavior** (from math_min_max test):
- **0 args**: min() → Infinity, max() → -Infinity
- **1 arg**: min(x) → NaN, max(x) → NaN (Flash requires exactly 2+ args for a valid result... actually the test shows 1 arg → NaN)
- **2 args**: Standard comparison after toNumber coercion
- **NaN propagation**: Any NaN arg → NaN result
- **valueOf()**: Called on object arguments (test traces "a.valueOf" / "b.valueOf")

Wait — re-examining: `Math.min(1)` → NaN and `Math.max(1)` → NaN. This means Flash's min/max require exactly 2 arguments. With 1 arg, the second is implicitly undefined → NaN → result is NaN.

### Implementation

Register Math methods in the `callObjectMethod` / `actionCallMethod` handler. When `obj` is the Math object, dispatch by method name:

```c
if (obj == math_object) {
    if (strcmp(method, "abs") == 0) { ... }
    else if (strcmp(method, "min") == 0) { ... }
    // etc.
}
```

Or: add methods as native function properties on the Math object during initialization.

### Tests improved by Phase 2

- **math_min_max**: 31% → ~100% (comment lines already match; method results will match)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=math_min_max --diff --verbose
```

---

## Phase 3: Fix parseInt

**Goal**: Rewrite `parseInt` to handle radix, hex/octal prefixes, overflow, and edge cases.

### Current state

`parseInt` uses `atoi()` which:
- Ignores radix parameter entirely
- Returns 0 for invalid input (should return NaN)
- No hex prefix handling
- No overflow to Infinity
- `parseInt()` with no args returns 0 (should return undefined)

### Algorithm

```
parseInt(string, radix):
1. If no args → return undefined
2. str = toString(string)
3. Strip leading whitespace from str
4. Parse optional sign ('+' or '-')
5. radix = toInt32(radix) if provided
6. If radix is 0, NaN, undefined, true, false, or object → radix = 0 (auto-detect)
   If radix == 0:
     - If str starts with "0x" or "0X" (after sign): radix = 16, skip "0x"
     - Else if str starts with "0" AND no leading whitespace before the "0": radix = 8
     - Else: radix = 10
   BUT: "  077" → 77 (leading whitespace inhibits octal!)
   AND: "077 " → 77 (trailing whitespace also inhibits octal!)
7. If radix < 2 or radix > 36 → return NaN
8. Parse digits in given radix, stop at first invalid digit
9. If no valid digits parsed → return NaN
10. Convert to double; if > Number.MAX_VALUE → Infinity (or -Infinity)
11. Apply sign
```

Special hex edge cases from the test:
- `parseInt('0x+0X100')` → 0 (first `0x`, then `+` is not a hex digit → stops → 0)
- `parseInt('-0x100')` → NaN (sign before `0x` is... actually `-` then `0x` should work... but test says NaN)

Wait, let me re-read: `parseInt('-0x100')` → NaN. But `parseInt('-0100')` → -64. So the `-` sign is NOT allowed before `0x` prefix? Let me check: `parseInt('-0x100', 36)` → 1540944. That's parsed as base-36 `-0x100` → the string `-0x100` in base 36. OK, without radix: `-0x100` → sign='-', then `0x` → hex, digits `100` → 256 → -256? But test says NaN!

Actually: `/*34*/ parseInt('-0x100') == NaN`. But `/*35*/ parseInt('0x-100') == -256`. So `-0x100` returns NaN but `0x-100` returns -256. The rule: the sign character must come AFTER the `0x` prefix, not before it. If `-` comes before `0x`, auto-detect sees `0x` but the sign was already consumed, and the `-` is not re-applied... actually this is a quirk where `-0x` is not a valid hex prefix.

More precisely: Flash's parseInt appears to not recognize `0x` hex prefix when there's a leading sign. So `-0x100` → tries to parse as decimal/octal → `-0` then stops at `x` → result is `-0` = NaN? No, -0 is 0. Hmm.

Looking at the test pattern more carefully:
- `parseInt('-0x100')` → NaN: sign `-`, then sees `0x`, enters hex mode, but... treats the `-` as part of the prefix and fails?
- `parseInt(' -0x100', 36)` → -1540944: with explicit radix 36, `-` is sign, `0x100` is base-36 digits

I think the rule is: with auto-detect (no explicit radix), a sign before `0x` makes it NaN. With explicit radix, sign is always allowed.

And: `parseInt('0x-100')` → -256. So `0x` is consumed as hex prefix, then `-100` is parsed as hex with sign → -256.

### Tests improved by Phase 3

- **parse_int**: 0% → ~95%+ (64 lines)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=parse_int --diff --verbose
```

---

## Phase 4: Fix parseFloat and isFinite

### parseFloat

The `parse_float` test currently times out, suggesting an infinite loop. Likely causes:
- parseFloat calls itself recursively
- Or the test SWF has a loop with parseFloat that never terminates due to wrong return value

Current implementation probably uses `atof()`. Need to investigate the timeout.

Expected behavior:
- `parseFloat("3.14")` → 3.14
- `parseFloat("123abc")` → 123 (stops at invalid char)
- `parseFloat("")` → NaN
- `parseFloat("hello")` → NaN
- `parseFloat()` → undefined? or NaN?
- Handles scientific notation: `parseFloat("1.5e2")` → 150
- Handles leading whitespace: `parseFloat("  3.14")` → 3.14

### isFinite

Currently 48% passing (24/49). The issues are string-to-number coercion:
- `isFinite("0")` should be true (parse "0" as number 0, which is finite)
- `isFinite("")` should be false (empty string → NaN in Flash, not 0)
- `isFinite("0x10")` should be true (hex string → 16)
- `isFinite("  5  ")` should be false (Flash doesn't trim whitespace for string→number)
- `isFinite(true)` should be true (true → 1)
- `isFinite()` should be false (undefined → NaN)

The core issue is that `isFinite` needs to use the same string-to-number coercion rules as the rest of Flash (which differ from C's `atof`):
- Empty string → NaN (not 0)
- Whitespace-only → NaN
- Hex strings "0x..." → parse as hex
- Leading/trailing whitespace with digits → NaN (strict parsing)
- Boolean true → 1, false → 0

### Tests improved by Phase 4

- **is_finite**: 48% → ~100%
- **is_finite_swf6**: 48% → ~100%
- **parse_float**: timeout → should pass or nearly pass

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=is_finite --diff --verbose
python3 ruffle-tests/verify_output.py --test=parse_float --diff --verbose
```

---

## Phase 5: flash.* Namespace (SWF8+)

**Goal**: Register the `flash.*` namespace hierarchy with stub constructors for SWF8+. This fixes globals_swf8 from 50% → ~97%.

### Implementation

Create the namespace objects and register constructors:

```c
if (swf_version >= 8) {
    ASObject* flash_obj = createObject(app_context);
    setProperty(global_obj, "flash", flash_obj);

    ASObject* flash_display = createObject(app_context);
    setProperty(flash_obj, "display", flash_display);

    ASFunction* bitmapdata_ctor = createFunction("BitmapData");
    setProperty(flash_display, "BitmapData", bitmapdata_ctor);

    // flash.external
    ASObject* flash_external = createObject(app_context);
    setProperty(flash_obj, "external", flash_external);
    ASFunction* extintf_ctor = createFunction("ExternalInterface");
    setProperty(flash_external, "ExternalInterface", extintf_ctor);

    // flash.filters (10 filter classes)
    ASObject* flash_filters = createObject(app_context);
    setProperty(flash_obj, "filters", flash_filters);
    // BevelFilter, BitmapFilter, BlurFilter, ColorMatrixFilter,
    // ConvolutionFilter, DisplacementMapFilter, DropShadowFilter,
    // GlowFilter, GradientBevelFilter, GradientGlowFilter

    // flash.geom
    ASObject* flash_geom = createObject(app_context);
    setProperty(flash_obj, "geom", flash_geom);
    // ColorTransform, Matrix, Point, Rectangle, Transform

    // flash.net
    ASObject* flash_net = createObject(app_context);
    setProperty(flash_obj, "net", flash_net);
    // FileReference, FileReferenceList

    // flash.text
    ASObject* flash_text = createObject(app_context);
    setProperty(flash_obj, "text", flash_text);
    // TextRenderer
}
```

### Tests improved by Phase 5

- **globals_swf8**: 50% → ~97% (all flash.* entries now match)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=globals_swf8 --diff --verbose
```

---

## Phase 6: Primitive Type Improvements (Number/Boolean/String)

**Goal**: Fix Number.prototype.toString(radix), Number constants, Boolean/String converter behavior.

### Number.prototype.toString(radix)

The `primitive_type_globals` test extensively tests `Number.prototype.toString(radix)` for radices 2-36. For example, `(4123).toString(16)` → "101b". Currently likely returns "[object Object]" or crashes.

Implementation: convert the numeric value to a string in the given radix using standard base-conversion algorithm.

Edge cases:
- `toString(0)` → "NaN" or error (radix 0 invalid, but Flash outputs something)
- `toString(1)` → "NaN" (radix 1 invalid)
- `toString(37)` → "NaN" (radix > 36 invalid)
- `toString()` → decimal string (default radix 10)
- Negative numbers: prepend "-" then convert absolute value

### Number constants

Register on the Number constructor:
```c
Number.NaN = NaN
Number.POSITIVE_INFINITY = Infinity
Number.NEGATIVE_INFINITY = -Infinity
Number.MIN_VALUE = 5e-324 (Number.MIN_VALUE)
Number.MAX_VALUE = 1.7976931348623157e+308
```

### Boolean/String as converter functions

`Boolean(value)` (without `new`) should return a primitive boolean, not a wrapper object.
`String(value)` (without `new`) should return a primitive string.
`Number(value)` (without `new`) should return a primitive number.

Currently these may always create wrapper objects. The test checks:
- `typeof Boolean(true)` → "boolean" (primitive)
- `typeof new Boolean(true)` → "object" (wrapper)

### Tests improved by Phase 6

- **primitive_type_globals**: 57% → ~85%+

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=primitive_type_globals --diff --verbose
```

---

## Phase 7: Prototype Methods for Stub Classes

**Goal**: Add prototype methods to stub constructors so the `global_proto_decls`, `global_instance_decls`, and `swf*_global_funcs` tests improve significantly.

These massive tests (4497, 758, and 232 lines respectively) enumerate every method on every global's prototype. To pass them, each constructor's prototype needs the correct method stubs (they don't need to DO anything — just exist as functions with the right names).

### Method lists by class

Based on `global_proto_decls/output.txt`:

**AsBroadcaster**: addListener, broadcastMessage, removeListener, initialize (static)

**Button.prototype**: getDepth, setMask, useHandCursor, enabled, _alpha, _focusrect, _height, _highquality, _name, _quality, _rotation, _soundbuftime, _target, _url, _visible, _width, _x, _xmouse, _xscale, _y, _ymouse, _yscale, tabEnabled, tabIndex, trackAsMenu

**Camera**: get (static), setMode, setQuality, setMotionLevel, setKeyFrameInterval, setLoopback

**Color.prototype**: getRGB, getTransform, setRGB, setTransform

**ContextMenu.prototype**: copy, hideBuiltInItems, builtInItems, customItems, onSelect

**ContextMenuItem.prototype**: copy, caption, enabled, separatorBefore, visible, onSelect

**Key**: addListener, getAscii, getCode, isDown, isToggled, removeListener, ALT, BACKSPACE, CAPSLOCK, CONTROL, DELETEKEY, DOWN, END, ENTER, ESCAPE, HOME, INSERT, LEFT, PGDN, PGUP, RIGHT, SHIFT, SPACE, TAB, UP

**LoadVars.prototype**: decode, load, send, sendAndLoad, toString, getBytesLoaded, getBytesTotal, addRequestHeader, contentType, loaded, onData, onHTTPStatus, onLoad

**LocalConnection.prototype**: close, connect, domain, send, allowDomain, allowInsecureDomain, onStatus

**Microphone**: get (static), setRate, setGain, setSilenceLevel, setUseEchoSuppression

**Mouse**: addListener, hide, removeListener, show

**MovieClipLoader.prototype**: loadClip, unloadClip, getProgress, addListener, removeListener

**NetConnection.prototype**: connect, addHeader, call, close, onStatus

**NetStream.prototype**: attachAudio, attachVideo, close, pause, play, publish, receiveAudio, receiveVideo, seek, send, setBufferTime, onStatus, bufferLength, bufferTime, bytesLoaded, bytesTotal, currentFps, time, onResult

**PrintJob.prototype**: start, addPage, send

**Selection**: addListener, getBeginIndex, getCaretIndex, getEndIndex, getFocus, removeListener, setFocus, setSelection

**SharedObject**: getLocal, getRemote, getDiskUsage, getMaxSize (static methods)

**Sound.prototype**: attachSound, start, stop, getBytesLoaded, getBytesTotal, getDuration, getPan, getTransform, getVolume, loadSound, setBufSize, setPan, setTransform, setVolume, onID3, onLoad, onSoundComplete, checkPolicyFile, duration, id3, position

**Stage**: addListener, removeListener, align, displayState, height, scaleMode, showMenu, width

**TextSnapshot.prototype**: findText, getCount, getSelected, getSelectedText, getText, getTextRunInfo, hitTestTextNearPos, setSelectColor, setSelected

**Video.prototype**: attachVideo, clear, deblocking, smoothing

**XMLSocket.prototype**: close, connect, send, onClose, onConnect, onData, onXML

### Implementation approach

For each class, create the prototype object and add each method as a native function stub:

```c
// Helper to add a stub method
void addStubMethod(ASObject* proto, const char* name) {
    ASFunction* fn = createFunction(name);
    ActionVar fn_var = {.type = ACTION_STACK_VALUE_FUNCTION, .data.fn = fn};
    setPropertyFlags(proto, name, fn_var, DONT_ENUM);
}
```

Methods are registered with `DONT_ENUM` flag so they don't appear in `for..in` loops but DO appear when accessed directly.

### Tests improved by Phase 7

- **global_proto_decls**: 0% → significant improvement (depends on how many classes get methods)
- **global_proto_decls_delete**: 0% → mirrors proto_decls improvement
- **global_instance_decls**: 0% → partial (needs instance property defaults too)
- **swf5/6/7_global_funcs**: 0% → partial (tests method behavior, not just existence)
- **printjob_props**: 0% → ~80%+
- **context_menu/context_menu_item**: 5% → ~60%+

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=global_proto_decls --diff --verbose
python3 ruffle-tests/verify_output.py --test=printjob_props_swf7 --diff --verbose
```

---

## Phase 8: Property Flags (DONT_ENUM, DONT_DELETE, READ_ONLY)

**Goal**: Ensure property flags are correctly set on all globals and their prototypes.

The `global_proto_decls_delete` test (4158 lines) checks that prototype methods have the `DONT_DELETE` flag. The `global_instance_decls` test checks for `DONT_ENUM` and `READ_ONLY` on instance properties.

### Implementation

The runtime's `ASSetPropFlags` mechanism already exists. During registration, set correct flags:
- Prototype methods: `DONT_ENUM | DONT_DELETE`
- Constructor `.prototype` property: `DONT_ENUM | DONT_DELETE`
- Constants (Number.NaN, etc.): `DONT_ENUM | DONT_DELETE | READ_ONLY`

### Tests improved by Phase 8

- **global_proto_decls_delete**: 0% → mirrors proto_decls improvement
- **global_instance_decls**: Improved (correct flags on instances)
- **as_set_prop_flags tests**: Improved

---

## Deferred / Out of Scope

### global_swf5_6_7_8_9 (0/1145)
This test loads 5 SWFs of different versions and checks cross-SWF global isolation. In SWF7-8, each loaded SWF gets its own global scope and `instanceof` works per-scope. This requires multi-SWF loading infrastructure (loadMovie) — deferred until LoadMovie is implemented.

### global_swf6_7_8 (0/15)
Similar: tests that SWF6 and SWF7 have different Object.prototype instances. Requires multi-SWF loading.

### swf5/6/7_global_funcs (1/232 each)
These test the actual BEHAVIOR of global functions (methods returning correct values), not just their existence. Improvement from Phase 7 (method stubs exist) will be partial; full pass requires implementing each method's logic.

### native_objects_swf6/7/8 and native_subclasses
These "meta-tests" require essentially all built-in classes to be fully functional. They'll improve incrementally as other features are implemented.

---

## Implementation Priority and Dependencies

```
Phase 1 (Register stubs) ──→ Phase 5 (flash.* namespace)
    │                              │
    ├──→ Phase 7 (Prototype methods) ──→ Phase 8 (Property flags)
    │
    ├──→ Phase 2 (Math methods)
    │
    ├──→ Phase 3 (parseInt)
    │
    ├──→ Phase 4 (parseFloat + isFinite)
    │
    └──→ Phase 6 (Number/Boolean/String primitives)
```

Phase 1 is the foundation. Phases 2-6 are independent of each other. Phase 7 builds on Phase 1. Phase 8 builds on Phase 7.

**Estimated test impact:**

| Phase | Tests Improved | Est. New Lines Matched | Key Tests |
|-------|---------------|----------------------|-----------|
| 1 | globals_swf5/6/7 | ~270 lines (90 missing globals × 3 lines) | globals_swf7: 70→100% |
| 2 | math_min_max | ~69 lines | math_min_max: 31→~100% |
| 3 | parse_int | ~64 lines | parse_int: 0→~95% |
| 4 | is_finite × 2, parse_float | ~50+? lines | is_finite: 48→~100% |
| 5 | globals_swf8 | ~120 lines (40 flash.* entries × 3) | globals_swf8: 50→~97% |
| 6 | primitive_type_globals | ~160 lines | primitive_type_globals: 57→~85% |
| 7 | global_proto_decls, printjob, etc. | ~2000+ lines | Many tests improve |
| 8 | global_proto_decls_delete | ~2000+ lines | Mirrors Phase 7 |

**Total estimated new matching lines**: ~4700+

---

## Files to Modify

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | Register all missing globals, implement Math methods, rewrite parseInt/parseFloat/isFinite, fix Number.prototype.toString(radix), add prototype method stubs for all classes |
| `include/actionmodern/action.h` | Possibly: new function declarations if methods are split out |

### Recompiler (SWFRecomp/)

No recompiler changes needed for any phase. All changes are runtime-only.

---

## Quick Win Estimate

**Phases 1+2+3+4 alone** (the first four phases) are relatively small, self-contained changes that would:
- Fix ~450+ matching lines
- Bring globals_swf5/6/7 to ~100% (3 tests very close to passing)
- Bring math_min_max, parse_int, is_finite, is_finite_swf6 to near-passing (4 tests)
- Total: ~7 tests significantly improved, 3 potentially newly passing

These are all pure runtime changes in `action.c` with no recompiler work and no dependencies on other feature plans.
