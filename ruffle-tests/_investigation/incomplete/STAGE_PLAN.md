# Stage Object Properties Implementation Plan
<!-- TESTS: stage_object_properties, stage_object_properties_swf6, stage_object_children, stage_object_enumerate, stage_display_state, stage_property_representation, stage_scale_mode -->

Last updated: 2026-02-14

## Overview

The "Stage Object Properties" category in FAILING_TESTS_BY_FEATURE.md covers 7 tests. Despite the category name, these tests actually cover **two distinct features**:

1. **Flash `Stage` global object** (2 tests): `stage_display_state`, `stage_scale_mode`
2. **MovieClip display properties** (5 tests): `stage_object_properties`, `stage_object_properties_swf6`, `stage_object_children`, `stage_object_enumerate`, `stage_property_representation`

The MovieClip property tests are already partially supported (68% on stage_object_properties/swf6, 82% on stage_object_children) — they need bug fixes for precision, _width/_height↔scale interaction, rotation wrapping, _level addressing, and child enumeration. The Stage global tests are 0% because the Stage object doesn't exist yet.

**Blocking issue**: All 7 tests currently fail with `COMPILE_FAIL` due to missing UTF-16 string function source files in `verify_output.py`'s `compile_native()`. This must be fixed first before any test output can be evaluated.

---

## Test Inventory

| Test | Lines | Last CI | Feature Needed |
|------|-------|---------|----------------|
| stage_object_properties | 243 | 68% (165/243) | MC property precision, width↔scale, rotation wrapping, child clips |
| stage_object_properties_swf6 | 232 | 68% | Same as above, SWF6 precision |
| stage_object_children | 85 | 82% (68/83) | _level addressing, dynamic prop vs child clip priority, delete behavior |
| stage_object_enumerate | 4 | 0% (0/4) | Child clip enumeration in for-in |
| stage_display_state | 17 | 0% (0/17) | Stage.displayState + onFullScreen callback |
| stage_property_representation | 586 | 0% (0/586) | Scale/rotation value representation (integer display) |
| stage_scale_mode | 40 | 0% (0/40) | Stage.align + Stage.scaleMode + Stage.width/height + onResize |

**Total**: 1207 expected lines across 7 tests.

---

## Phase 0: Fix Build (Prerequisite)

**Goal**: Fix the `COMPILE_FAIL` that blocks all 7 tests.

The UTF-16 string functions (`strcmp_list_a_list_b`, `utf8_build_utf16_tables`, `byte_offset_to_utf16_index`, `utf16_unit_to_utf8`) were recently added but their source file isn't included in `verify_output.py`'s `compile_native()` function.

### Implementation

In `ruffle-tests/verify_output.py`, add the missing `.c` file to the source list in `compile_native()`. Identify which file defines these functions and add it.

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=stage_object_properties --diff --verbose
# Should get past compilation and show output_mismatch instead of compile_fail
```

---

## Phase 1: Stage Global Object

**Goal**: Create the `Stage` object with `displayState`, `align`, `scaleMode`, `width`, `height` properties and `onFullScreen`/`onResize` callbacks. Fixes `stage_display_state` (17 lines) and `stage_scale_mode` (40 lines).

### What the tests expect

#### stage_display_state

The `Stage` object is a special global (not a constructor — you don't call `new Stage()`). It has:

- `Stage.displayState` — getter returns `"normal"` or `"fullScreen"`. Setter accepts case-insensitive match: `"fullScreen"` and `"FULLSCREEN"` both set to fullscreen, `"normal"` and `"NORMAL"` both set to normal. Invalid values (like `"A"`) are ignored (no change).
- When `displayState` changes, the `Stage.onFullScreen` callback fires with a boolean parameter (`true` for entering fullscreen, `false` for exiting).

#### stage_scale_mode

- `Stage.align` — getter returns a canonical string made of L/R/T/B characters (always in "LTRB" order, no duplicates). Setter parses L/R/T/B characters case-insensitively from any string input. Non-LRTB characters are ignored. Examples: `"TL"` → `"LT"`, `"BR"` → `"RB"`, `"TllLBbbtRrrlBr"` → `"LTRB"`. Special: `true` → `"TR"` (coerced to string `"true"`, which contains `t` and `r`). `undefined` → `""`.
- `Stage.scaleMode` — getter returns one of `"showAll"`, `"noBorder"`, `"exactFit"`, `"noScale"`. Setter does case-insensitive match: `"EXACTFIT"` → `"exactFit"`, `"noborder"` → `"noBorder"`. Invalid values default to `"showAll"`. `true` → `"showAll"` (no match).
- `Stage.width` / `Stage.height` — return stage dimensions. In `"showAll"` mode: returns SWF dimensions (550, 400). In `"noScale"` mode: returns viewport dimensions.
- When `scaleMode` changes to `"noScale"`, an `onResize` event fires (the test expects `// onResize event: 900 900` trace output — but this trace is a comment in the test's expected output, meaning the test's ActionScript does `trace("// onResize event: " + Stage.width + " " + Stage.height)` inside the `Stage.onResize` handler).

### Implementation

#### 1a. Stage object storage

Add a static `ASObject* g_stage_object` in `action.c`. Unlike constructors, Stage is a plain object:

```c
static ASObject* g_stage_object = NULL;
static char stage_display_state[16] = "normal";
static char stage_scale_mode[16] = "showAll";
static char stage_align[5] = "";  // max "LTRB" + null
static int stage_swf_width = 550;  // from SWF header
static int stage_swf_height = 400;
static int stage_viewport_width = 550;
static int stage_viewport_height = 400;
```

#### 1b. Register Stage as a global variable

In the `actionGetVariable` / `_global` initialization section of `action.c`, add `Stage` lookup:

```c
// In actionGetVariable, alongside other special names:
else if (var_name_len == 5 && strncmp(var_name, "Stage", 5) == 0)
{
    if (g_stage_object == NULL) initStageObject(app_context);
    PUSH(ACTION_STACK_VALUE_OBJECT, (u64)g_stage_object);
    return;
}
```

Also register on `_global`:
```c
setProperty(app_context, global_object, "Stage", 5, &stage_var);
```

#### 1c. Stage property getter/setter

In `actionGetMember`, when the object is `g_stage_object`, intercept property access:

- `displayState` → return `stage_display_state` string
- `scaleMode` → return `stage_scale_mode` string
- `align` → return `stage_align` string
- `width` → if scaleMode == "noScale": viewport width, else: SWF width
- `height` → if scaleMode == "noScale": viewport height, else: SWF height
- `showMenu` → return `true`
- Other properties → fall through to normal ASObject property lookup (for `onFullScreen`, `onResize` callbacks stored as regular properties)

In `actionSetMember`, when the object is `g_stage_object`:

- `displayState` → parse and validate, fire `onFullScreen` callback if changed
- `scaleMode` → parse and validate, fire `onResize` callback if changed to "noScale"
- `align` → parse L/R/T/B characters from string
- `onFullScreen`, `onResize` → store normally on the ASObject (they're just function properties)
- Other → store normally

#### 1d. Stage.align parsing

```c
static void parseStageAlign(const char* input, char* output) {
    int has_l = 0, has_r = 0, has_t = 0, has_b = 0;
    for (int i = 0; input[i]; i++) {
        char c = tolower(input[i]);
        if (c == 'l') has_l = 1;
        else if (c == 'r') has_r = 1;
        else if (c == 't') has_t = 1;
        else if (c == 'b') has_b = 1;
    }
    char* p = output;
    if (has_l) *p++ = 'L';
    if (has_t) *p++ = 'T';
    if (has_r) *p++ = 'R';
    if (has_b) *p++ = 'B';
    *p = '\0';
}
```

#### 1e. Stage.scaleMode parsing

Case-insensitive match against `"showAll"`, `"noBorder"`, `"exactFit"`, `"noScale"`. Invalid → `"showAll"`.

#### 1f. Callback dispatch

When `displayState` changes:
1. Look up `onFullScreen` on `g_stage_object`
2. If it's a function, call it with one boolean argument (`true` = entering fullscreen)

When `scaleMode` changes to `"noScale"`:
1. Update stage_viewport dimensions
2. Look up `onResize` on `g_stage_object`
3. If it's a function, call it with no arguments

#### 1g. SWF dimensions

The SWF width/height should come from the SWF header (FrameSize RECT). The recompiler already knows these. For NO_GRAPHICS mode, define them as macros (`SWF_STAGE_WIDTH`, `SWF_STAGE_HEIGHT`) in the generated `tagMain.c`, similar to `SWF_FRAME_COUNT`.

For `stage_scale_mode`, the test.toml specifies `viewport = 900x900` and `scale_factor = 1`. The test runner would need to pass these to the test binary. For now, we can handle the noScale case by using the SWF dimensions as viewport dimensions (since we're in trace mode with no actual viewport), or accept partial pass rate on the resize portion.

### Tests fixed by Phase 1

- **stage_display_state**: 17/17 — full pass
- **stage_scale_mode**: ~35/40 — most lines pass. The `onResize` + noScale viewport size lines may need viewport dimension plumbing.

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=stage_display_state --diff --verbose
python3 ruffle-tests/verify_output.py --test=stage_scale_mode --diff --verbose
```

---

## Phase 2: MovieClip Property Precision and Width↔Scale Interaction

**Goal**: Fix _width/_height ↔ _xscale/_yscale coupling, rotation wrapping, and value representation. Fixes the core issues in `stage_object_properties` (243 lines) and `stage_object_properties_swf6` (232 lines).

### What the tests expect

#### Width↔Scale coupling

In Flash, `_width` and `_height` are **derived properties** that depend on the clip's original (untransformed) bounds and the current scale:

```
_width = abs(original_width * _xscale / 100)
_height = abs(original_height * _yscale / 100)
```

When you **set** `_width`, Flash computes the new `_xscale`:
```
_xscale = (_width / original_width) * 100
```

When you **set** `_height`, Flash computes the new `_yscale`:
```
_yscale = (_height / original_height) * 100
```

With rotation, width and height swap axes — at 90° rotation:
```
_width depends on _yscale and original_height
_height depends on _xscale and original_width
```

The test shows this interaction:
```
Setting _width = 200 → _xscale = 85.8184938854323 (with precision!)
Setting _height = 171.6 → _yscale = 85.8
```

**Key observation**: Flash returns `_xscale` and `_yscale` as **double-precision** values (not float32). The test expects `85.8184938854323` — this is a double with ~15 significant digits. Currently we store and return these as `float` (7 digits), which loses precision.

#### Rotation wrapping

Setting rotation values wraps to (-180, 180]:
```
rotation = 180 → 180
rotation = 181 → -179
rotation = -180 → -180
rotation = 360 → 0 (wraps)
rotation = 540 → 180
```

The test shows:
```
_rotation:
90
180
-179
-180
179
179
179
```

The last three `179` values come from setting rotation to `NaN`, `undefined`, and `Infinity` — all of which should be ignored (rotation stays at 179).

#### Invalid value handling

When setting a MovieClip property to `NaN`, `undefined`, or `Infinity`:
- `_x`, `_y`: retain current value (ignore the set)
- `_xscale`, `_yscale`: retain current value
- `_alpha`: retain current value
- `_rotation`: retain current value
- `_visible`: coercion rules apply (`undefined` → false, `NaN` → false)

#### _visible coercion

```
_visible set to:    result:
false               false
true                true
1                   true
0                   false (but then...)
""                  true  ← empty string is truthy for _visible!
"false"             true
undefined           false
null                false
1                   true
```

Wait — looking at the expected output more carefully:
```
_visible
false      ← starting value
true       ← set to true
true       ← set to 1
true       ← set to "true" (string)
true       ← set to "false" (string → truthy)
true       ← set to 0.001 (nonzero → true)
false      ← set to 0
false      ← set to null
true       ← set to "0" (string → truthy)
```

So _visible: any non-zero number → true, zero → false, null/undefined → false, any string (even "false", "0", "") → true.

#### Double-precision for properties

The test expects values like `85.8184938854323` (13+ significant digits) and `24.9946363441322`. Currently MovieClip stores `xscale`/`yscale` as `float` (7 digits). We need to upgrade to `double`:

```c
typedef struct MovieClip {
    double x, y;            // was float
    double xscale, yscale;  // was float
    double rotation;        // was float
    double alpha;           // was float
    double width, height;   // was float — or compute from original bounds + scale
    // ... rest unchanged
} MovieClip;
```

#### Original bounds

To compute width↔scale coupling, we need each clip's **original untransformed bounds**. For NO_GRAPHICS mode, these need to come from the recompiler. The recompiler already knows the shape bounds from DefineShape tags. We need:

```c
struct {
    double original_width;   // from shape bounds, in pixels
    double original_height;  // from shape bounds, in pixels
} ng_clip_bounds[MAX_CLIPS];
```

For `stage_object_properties`, the test SWF has a clip named "clip" with specific bounds. The recompiler must emit these bounds alongside the PlaceObject2 tag data.

### Implementation

#### 2a. Upgrade MovieClip numeric fields to double

Change `float x, y, xscale, yscale, rotation, alpha, width, height` to `double` in the MovieClip struct. Update all code that reads/writes these fields:
- `actionGetProperty` / `actionSetProperty`
- `actionGetMember` / `actionSetMember` MovieClip branches
- Push values as `ACTION_STACK_VALUE_F64` instead of `ACTION_STACK_VALUE_F32`

#### 2b. Rotation wrapping

```c
static double wrapRotation(double deg) {
    deg = fmod(deg, 360.0);
    if (deg > 180.0) deg -= 360.0;
    else if (deg <= -180.0) deg += 360.0;
    return deg;
}
```

Apply this in the rotation setter.

#### 2c. Invalid value rejection

In the MovieClip property setter (both SetMember and SetProperty), check for NaN/Infinity before applying:

```c
if (strcasecmp(prop_name, "_x") == 0) {
    double dval = varToDouble(&value_var);
    if (!isnan(dval) && !isinf(dval)) mc->x = dval;
    return;
}
```

#### 2d. Width↔Scale coupling

Store `original_width` and `original_height` on MovieClip (or look them up from a table by character ID).

Width getter:
```c
if (strcasecmp(prop_name, "_width") == 0) {
    double w = fabs(mc->original_width * mc->xscale / 100.0);
    // With rotation: need to account for rotated bounding box
    PUSH_F64(w);
    return;
}
```

Width setter:
```c
if (strcasecmp(prop_name, "_width") == 0) {
    double new_width = varToDouble(&value_var);
    if (!isnan(new_width) && mc->original_width != 0) {
        mc->xscale = (new_width / mc->original_width) * 100.0;
    }
    return;
}
```

The rotation case is more complex — at non-zero rotation, width/height depend on both xscale and yscale through the rotation matrix:

```
actual_width = |cos(θ)| * original_width * |xscale/100| + |sin(θ)| * original_height * |yscale/100|
actual_height = |sin(θ)| * original_width * |xscale/100| + |cos(θ)| * original_height * |yscale/100|
```

Setting width when rotated: Flash adjusts xscale to achieve the desired width.

#### 2e. _visible coercion fix

Currently using `(fval != 0.0f)` — needs to handle strings as truthy:

```c
if (strcasecmp(prop_name, "_visible") == 0) {
    if (value_var.type == ACTION_STACK_VALUE_STRING) {
        mc->visible = 1;  // All strings are truthy for _visible
    } else if (value_var.type == ACTION_STACK_VALUE_NULL || value_var.type == ACTION_STACK_VALUE_UNDEFINED) {
        mc->visible = 0;
    } else {
        double dval = varToDouble(&value_var);
        mc->visible = (dval != 0.0 && !isnan(dval)) ? 1 : 0;
    }
    return;
}
```

### Tests fixed by Phase 2

- **stage_object_properties**: 68% → ~90%+ (precision, width↔scale, rotation wrapping, invalid values, _visible coercion)
- **stage_object_properties_swf6**: 68% → ~90%+ (same fixes, SWF6 precision slightly different)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=stage_object_properties --diff --verbose
python3 ruffle-tests/verify_output.py --test=stage_object_properties_swf6 --diff --verbose
```

---

## Phase 3: Value Representation and Scale/Rotation Ranges

**Goal**: Fix how numeric values are printed when traced. Fixes `stage_property_representation` (586 lines).

### What the test expects

The test sets `_xscale` from 20 to 420 in steps of 2, and traces each value. Expected output is clean integers:

```
20
22
24
...
420
```

Then `_yscale` from 20 to 420, same pattern. Then `_rotation` from 180 through -180 and back to 180 in steps of 2:

```
180
-178
-176
...
-2
0
2
...
180
```

### Key issue: Number formatting

Flash traces numbers differently from C's `printf`:
- Integer values print without decimals: `20` not `20.000000`
- Non-integer values print with minimal decimals: `85.8184938854323`
- This is the standard ECMAScript number-to-string algorithm

The test expects all values to be integers (since 20, 22, 24... are all exact integers). The current `trace` implementation may be printing them with decimal points.

### Implementation

This is likely already handled by the trace/number-to-string code — the main requirement is that `_xscale` set to `20` and then read back traces as `20` (an integer). With double-precision storage (Phase 2), setting `mc->xscale = 20.0` and reading it back should produce `20` in trace output if the number formatting is correct.

The rotation test also verifies wrapping: setting rotation to 180, then incrementing by 2:
- 180, 182→-178, 184→-176, ..., 358→-2, 360→0, 362→2, ..., 540→180

### Tests fixed by Phase 3

- **stage_property_representation**: 0% → ~100% (586 lines — depends on Phase 2 for double precision)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=stage_property_representation --diff --verbose
```

---

## Phase 4: _level Addressing and Child Clip Resolution

**Goal**: Fix `_level0`, `_levelN`, `_flashN` variable resolution and child clip property priority. Fixes remaining issues in `stage_object_children` (85 lines).

### What the test expects

#### _level addressing

Flash resolves special variable names:
- `_level0` → the root movie clip (same as `_root`)
- `_flash0` → alias for `_level0`
- `_level` → `_level0` (incomplete name → level 0)
- `_flash` → `_level0` (incomplete name → level 0)
- `_level0a` → `_level0` (trailing non-digits ignored — parse stops after digits)
- `_flash0a` → `_level0` (same)
- `_level1` → `undefined` (no movie loaded at level 1)
- `_level2147483648` → `undefined` (overflow → not level 0)
- `_level4294967296` → `_level0` (wraps to 0 via u32 overflow)
- `_level4294967297` → `undefined` (wraps to 1)

These are resolved in `actionGetVariable` — currently no _level logic exists.

#### Child clip property priority

When accessing `mc.clip` where `clip` is both a child instance name AND a dynamic property:
1. If dynamic property exists, it takes priority
2. After `delete mc.clip`, the child instance name resolves again
3. `MovieClip.prototype.clip = 2` does NOT shadow the child instance name (instance > prototype)
4. After child clips are removed (frame 2), prototype properties become visible

The test flow:
```
clip = _level0.clip          (child clip resolves)
mc.clip = 10                 (sets dynamic prop, shadows child)
clip → 10                    (dynamic prop wins)
delete mc.clip → true        (deletes dynamic prop)
clip → _level0.clip          (child resolves again)
delete mc.clip → false       (can't delete child — not a dynamic prop)
MovieClip.prototype.clip = 2
clip → _level0.clip          (child still wins over prototype)
// clips removed (frame 2)
clip → 2                     (prototype now visible, no child)
```

Also tests `_root['_x']` as string key → should return `_level0._x` (a string representation of the path, NOT the numeric value of _x). Wait, no — looking more carefully:

```
// _root['_x']
_level0._x
```

Hmm, this is interesting. When accessing `_root['_x']` with bracket notation and the key is a special path like `_x`, it seems like the test traces the **path** `_level0._x` rather than the numeric value. But actually, looking at the later lines:

```
// _root['_x'] = 42
// _root['_x']
_level0._x
// _root._x
42
```

So `_root['_x']` returns `_level0._x` (a string/movieclip path) but `_root._x` returns `42` (the numeric value). This suggests that bracket access with `'_x'` resolves to a **child clip named `_x`** — but there's no child named `_x`.

Actually wait — looking at this test output pattern: `_level0._x` looks like it's tracing a MovieClip. When you trace a MovieClip, Flash outputs its target path as `_level0.clipName`. So `_root['_x']` is returning the `_x` property which... hmm, `_x` is a built-in property returning a number. But then why does `_root._x` return `42`?

Let me reconsider. The output `_level0._x` suggests this is NOT a MovieClip toString, but rather a child clip named `_x` on `_level0`. But that's unlikely — `_x` is a reserved property name.

Actually, I think this test creates a child clip literally named `_x`! The SWF test probably places a child clip with instance name `_x` to test property vs child resolution. In Flash, if a child clip is named `_x`, the child clip takes priority over the built-in `_x` property when accessed via bracket notation on the MovieClip. But `_root._x` still accesses the built-in property.

Wait no, actually — `_root._x` returns 42 (which was set via `_root['_x'] = 42`). So the assignment `_root['_x'] = 42` set a dynamic property `_x` on _root, and dot access `_root._x` reads the dynamic property instead of the built-in. But the child clip `_x` takes priority on read until a dynamic property is set.

This is complex child-vs-property-vs-builtin resolution priority:
1. Dynamic properties (set via SetMember)
2. Child instance names
3. Built-in properties (_x, _y, etc.)

And for sets:
- Setting `_root['_x'] = 42` creates a dynamic property `_x`
- Reading `_root._x` then reads the dynamic property (since it exists)
- Reading `_root['_x']` also reads the dynamic property

Before the dynamic property is set:
- `_root['_x']` returns the child clip named `_x` (if one exists)
- If no child named `_x`, returns the built-in `_x` value

Hmm, but actually I think the output shows something different. Let me re-read:

```
// _root['_x']      → traces _level0._x  (the child clip, path format)
// _root['_x'] = 42
// _root['_x']      → traces _level0._x  (STILL the child clip!)
// _root._x         → traces 42          (the set value via dot access)
```

So setting `_root['_x'] = 42` set a value, but `_root['_x']` still returns the child clip. This means child clips ALWAYS take priority over dynamic properties for read. But `_root._x` returns 42 because dot access prioritizes the built-in `_x` property (which was overridden by the set?).

Actually this is getting complicated. This may be specific to how `_x` works — it's a virtual property with special getter semantics. The test might be relying on Flash's internal property resolution which treats underscore properties differently depending on access path.

**For now**: This test requires nuanced property resolution that may not be worth implementing in Phase 4. Let's focus on the _level addressing and basic child enumeration first.

### Implementation

#### 4a. _level variable resolution

In `actionGetVariable`, add `_level` and `_flash` prefix handling:

```c
if (var_name_len >= 6 && strncmp(var_name, "_level", 6) == 0) {
    // Parse number after "_level"
    unsigned long long level = 0;
    int has_digits = 0;
    for (int i = 6; i < var_name_len && var_name[i] >= '0' && var_name[i] <= '9'; i++) {
        level = level * 10 + (var_name[i] - '0');
        has_digits = 1;
    }
    if (!has_digits) level = 0;  // "_level" alone → level 0
    uint32_t level32 = (uint32_t)level;  // u32 truncation (handles overflow)
    if (level32 == 0) {
        PUSH(ACTION_STACK_VALUE_MOVIECLIP, (u64)&root_movieclip);
    } else {
        pushUndefined(app_context);
    }
    return;
}
```

Same for `_flash` prefix.

#### 4b. _root toString

When tracing a MovieClip, the output format should be `_level0` (not `/`) for root, and `_level0.clipName` for children. Currently `mc->target` is `"/"` for root. We need either:
- A separate `toString` format that uses `_level0` style
- Or change how MovieClip values are traced

The trace function probably calls `toString` on the MovieClip. Flash's toString for MovieClips returns the dot-path: `_level0`, `_level0.clip`, etc.

### Tests fixed by Phase 4

- **stage_object_children**: 82% → ~90%+ (basic _level addressing, child vs property priority)

---

## Phase 5: Child Clip Enumeration in for-in

**Goal**: Make `for-in` on a MovieClip enumerate child instance names. Fixes `stage_object_enumerate` (4 lines).

### What the test expects

```
foo
clip3
clip2
clip1
```

The MovieClip has children `clip1`, `clip2`, `clip3` (placed in that order) and a dynamic property `foo`. The for-in enumeration outputs:
1. Dynamic properties first (in reverse insertion order): `foo`
2. Child instance names in reverse placement order: `clip3`, `clip2`, `clip1`

### Current behavior

The MovieClip enumeration code (line 8799) only enumerates `dynamic_props` — it doesn't enumerate child instance names from the display list.

### Implementation

After enumerating dynamic_props, also enumerate child instance names from the NO_GRAPHICS display list:

```c
#ifdef NO_GRAPHICS
// Also enumerate child instance names
for (int i = ng_display_count - 1; i >= 0; i--) {
    if (ng_display[i].instance_name[0] != '\0') {
        const char* name = ng_display[i].instance_name;
        u32 name_len = strlen(name);
        if (!isPropertyEnumerated(enumerated_head, name, name_len)) {
            addEnumeratedName(&enumerated_head, name, name_len);
            PropList* node = malloc(sizeof(PropList));
            node->name = name;
            node->name_length = name_len;
            node->next = prop_head;
            prop_head = node;
        }
    }
}
#endif
```

The order needs to be reverse placement order (highest depth first for children placed in ascending depth order).

### Tests fixed by Phase 5

- **stage_object_enumerate**: 0% → 100% (4 lines)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=stage_object_enumerate --diff --verbose
```

---

## Implementation Priority and Dependencies

```
Phase 0 (build fix) ──→ Phase 1 (Stage object)
                    ──→ Phase 2 (MC precision) ──→ Phase 3 (value repr)
                    ──→ Phase 4 (_level addressing)
                    ──→ Phase 5 (child enumeration)
```

Phase 0 must come first. All other phases are independent of each other (though Phase 3 requires Phase 2's double-precision upgrade).

**Estimated test impact:**

| Phase | Tests Fixed | Lines Fixed | Cumulative |
|-------|-----------|------------|------------|
| 0 | (prerequisite) | N/A | N/A |
| 1 | stage_display_state, stage_scale_mode | ~52 | ~52 |
| 2 | stage_object_properties, stage_object_properties_swf6 (partial) | ~150 | ~202 |
| 3 | stage_property_representation | ~586 | ~788 |
| 4 | stage_object_children (partial) | ~10 | ~798 |
| 5 | stage_object_enumerate | ~4 | ~802 |

**Total potential**: ~802/1207 lines (66%), up from current 0% (all compile_fail) or ~233/1207 (19%) based on last CI before compile breakage.

---

## Files to Modify

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | Stage object creation, property get/set, callback dispatch; MovieClip double precision; _level addressing; child enumeration; rotation wrapping; _visible coercion; invalid value rejection |
| `include/actionmodern/action.h` | MovieClip struct: float→double for x,y,xscale,yscale,rotation,alpha; possibly add original_width/height |
| `include/actionmodern/variables.h` | Possibly: no changes |
| `src/libswf/tag_stubs.c` | Possibly: expose child instance names for enumeration |

### Recompiler (SWFRecomp/)

| File | Changes |
|------|---------|
| `src/swf.cpp` | Emit SWF_STAGE_WIDTH/SWF_STAGE_HEIGHT defines; emit original clip bounds |

### Test infrastructure

| File | Changes |
|------|---------|
| `ruffle-tests/verify_output.py` | Add missing UTF-16 source file to compile_native() |

---

## Design Decisions

1. **Stage is a plain ASObject, not a constructor**: Unlike TextField or TextFormat, you never call `new Stage()`. It's a singleton global object. Use a static `ASObject*` with special property handling in GetMember/SetMember.

2. **Double precision for MovieClip properties**: The tests expect 13+ significant digits for scale values. This requires upgrading from `float` (7 digits) to `double` (15 digits). This is a significant change that touches many code paths (GetProperty, SetProperty, GetMember, SetMember, syncTransform, etc.) but is straightforward — just change types and push as F64 instead of F32.

3. **Original bounds for width↔scale**: Need to pass clip bounds from recompiler to runtime. For the `stage_object_properties` test, the clip has known bounds that produce the expected width/height values. Store as per-character metadata in the NO_GRAPHICS display list.

4. **_level addressing**: Simple prefix parsing with u32 truncation for overflow. Only `_level0` resolves to a clip (no multi-level support needed). _flash is an alias.

5. **Viewport dimensions**: For trace mode, SWF dimensions = viewport dimensions by default. The `stage_scale_mode` test has `viewport = 900x900` in test.toml — this would need the test runner to pass viewport info. For now, accept partial pass on the resize/noScale portion.

---

## Quick Win Estimate

**Phase 0 + Phase 1** alone (build fix + Stage object) would fix 2 tests and unblock evaluation of the other 5. Estimated time: ~2-3 hours.

**Phase 0 + Phase 5** (build fix + child enumeration) is the simplest functional change — could fix `stage_object_enumerate` (4 lines) very quickly.

**Full implementation** (all phases) would take the category from 0% (compile fail) or ~19% (last CI) to ~66%+ pass rate across 1207 lines.
