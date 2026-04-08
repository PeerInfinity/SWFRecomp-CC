# Gnash Near-Passing Tests Plan
<!-- TESTS: NetStream-v6, NetStream-v7, NetStream-v8, Transform-v6, Transform-v7, TextField-v5, TextFieldHTML-v6, TextFieldHTML-v7, TextFieldHTML-v8, Color-v6, ColorTransform-v8, LocalConnection-v6, LocalConnection-v7, LocalConnection-v8, ExternalInterface-v8, Inheritance-v5, Inheritance-v6, Inheritance-v7, Inheritance-v8, Selection-v6, Selection-v7, Selection-v8 -->

<!-- PLAN_META
id: GNASH_NEAR_PASSING
status: incomplete
phases:
  - id: 1
    name: "Trivial fixes (NetStream, Transform)"
    status: not_started
  - id: 2
    name: "htmlText setter and text clearing"
    status: not_started
  - id: 3
    name: "Color/ColorTransform constructors"
    status: not_started
  - id: 4
    name: "LocalConnection.connect() validation"
    status: not_started
  - id: 5
    name: "ExternalInterface _toXML/_toAS"
    status: not_started
  - id: 6
    name: "Inheritance and instanceof fixes"
    status: not_started
  - id: 7
    name: "Selection replaceSel index tracking"
    status: not_started
dependencies: []
blockers: []
-->

Last updated: 2026-04-07

## Status: NOT STARTED — 22 tests, 0 passing

Supersedes the previous NEAR_PASSING_TESTS_PLAN (which covered only Color-v6
and Selection-v6/v7/v8). This plan covers all non-ignored failing tests with
<=18 diffs (plus Inheritance-v5/v6 which share root causes with v7/v8).

## Summary

| Phase | Tests | Potential Flips | Estimated Effort |
|-------|-------|-----------------|-----------------|
| 1 | NetStream-v6/v7/v8, Transform-v6/v7 | 3-5 | Trivial |
| 2 | TextFieldHTML-v6/v7/v8, TextField-v5 | 3-4 | Low-Medium |
| 3 | Color-v6, ColorTransform-v8 | 1-2 | Low |
| 4 | LocalConnection-v6/v7/v8 | 3 | Low |
| 5 | ExternalInterface-v8 | 1 | Medium |
| 6 | Inheritance-v5/v6/v7/v8 | 2-4 | Medium-High |
| 7 | Selection-v6/v7/v8 | 0-3 | Medium |
| **Total** | **22** | **13-22** | |

---

## Phase 1: Trivial fixes

### 1a: NetStream prototype `currentFps` own property (3 tests → PASS)

**Tests:** NetStream-v6/v7/v8 (4 diffs each, 76/80 = 95.0%)

**Diffs (identical across v6/v7/v8):**
```
- PASSED: NetStream.prototype.hasOwnProperty('currentFps') [./NetStream.as:223]
+ FAILED: NetStream.prototype.hasOwnProperty('currentFps') [./NetStream.as:223]
- PASSED: NetStream.prototype.hasOwnProperty('currentFps') [./NetStream.as:229]
+ FAILED: NetStream.prototype.hasOwnProperty('currentFps') [./NetStream.as:229]
```
Plus 2 count-line diffs (#passed/#failed).

**Root cause:** `currentFps` is not registered as an own property on
`NetStream.prototype`. The test expects accessing `currentFps` to lazily create
it as an own property (Gnash models this as a native getter that installs itself
on first access; Flash just has it as a built-in property).

**Fix:** Register `currentFps` as an own property (value 0 or undefined) on
NetStream.prototype during initialization. This is the same pattern used for
other prototype own properties throughout the codebase.

**File:** `SWFModernRuntime/src/actionmodern/action.c` — NetStream prototype
initialization section.

### 1b: `flash.geom.Transform` constructor (2 tests → likely PASS)

**Tests:** Transform-v6/v7 (3 diffs each, 4/7 = 57.1%)

**Diff (v6, identical for v7):**
```
- PASSED: typeOf(flash.geom.Transform) == "function" [./Transform.as:33]
+ FAILED: expected: "function" obtained: undefined [./Transform.as:33]
```
Plus 2 count diffs.

**Root cause:** `flash.geom.Transform` is registered as a property on
`flash.geom` but doesn't resolve as a constructor function in `typeof`. The
Gnash test only checks `typeof` — it doesn't exercise Transform methods. The
AVM1 suite already has working Transform support (GEOMETRY_CLASSES_PLAN
complete), so this is likely just a visibility/registration issue.

**Fix:** Ensure `flash.geom.Transform` is registered as a FUNCTION type (not
UNDEFINED placeholder) in the `flash.geom` namespace object. Check if the
existing Transform constructor initialization is being reached during Gnash test
execution.

---

## Phase 2: htmlText setter and text clearing

### 2a: TextFieldHTML htmlText `<font>` tag assignment (3 tests → PASS)

**Tests:** TextFieldHTML-v6/v7/v8 (5 diffs each, 32/37 = 86.5%)

**Key diffs (v6, identical for v7/v8):**
```
- PASSED: tf.htmlText == "<font>font</font>" [./TextFieldHTML.as:56]
+ FAILED: expected: "<font>font</font>" obtained: <P ALIGN="LEFT"><FONT FACE="Times New Roman" ...><I>italic</I></FONT></P>

- PASSED: tf.text == "" [./TextFieldHTML.as:76]
+ FAILED: expected: "" obtained: green2
```

Three issues:
1. Setting `tf.htmlText = "<font>font</font>"` doesn't update the text — the
   old value (italic formatting) persists. The htmlText setter likely rejects or
   misparses the `<font>` tag without attributes.
2. `tf.text = ""` doesn't clear content — "green2" from a previous htmlText
   assignment persists. The text setter's clearing path isn't working.
3. One expected-FAILED line shows a different actual value than expected (stale
   content from issue #1), which is a consequence of #1 above.

**Fix:** (1) Fix htmlText setter to accept bare `<font>` tags (without
FACE/SIZE/COLOR attributes). (2) Fix `tf.text = ""` to clear both text content
and htmlText.

**File:** `SWFModernRuntime/src/actionmodern/action.c` — textfield htmlText
setter and text setter.

### 2b: TextField-v5 typeof and instanceof (1 test → possible PASS)

**Tests:** TextField-v5 (4 diffs, 8/12 = 66.7%)

**Diffs:**
```
- PASSED: typeof(tf) == "movieclip" [./TextField.as:54]
+ FAILED: expected: "movieclip" obtained: object

- PASSED: tf instanceOf TextField [./TextField.as:59]
+ FAILED: tf instanceOf TextField
```
Plus 2 count diffs.

**Root cause:** In SWF5, `typeof(textfield)` should return `"movieclip"` (Flash
treats TextFields as MovieClips for typeof in SWF5). Our implementation returns
`"object"`. The `instanceof` failure is likely downstream — if typeof is wrong,
the prototype chain is probably wrong too.

**Fix:** In the `typeof` handler, return `"movieclip"` for TextFields in SWF5
(Flash quirk — SWF6+ correctly returns `"object"`). Check if TextField
instances have their `__proto__` chain set up to include `TextField.prototype`.

**Cross-reference:** The `mc instanceof MovieClip` failure in Selection-v6 and
Inheritance-v5/v6 may share the same root cause (instanceof checks on display
objects).

---

## Phase 3: Color and ColorTransform constructors

### 3a: Color constructor with invalid target (1 test → PASS)

**Test:** Color-v6 (4 diffs, 167/171 = 97.7%)

**Diffs:**
```
- PASSED: typeof(c) == 'undefined' [./Color.as:379]
+ FAILED: expected: 'undefined' obtained: object
- PASSED: typeof(c) == 'undefined' [./Color.as:381]
+ FAILED: expected: 'undefined' obtained: object
```
Plus 2 count diffs.

**Root cause:** `new Color(nonMovieClipTarget)` should return `undefined` in
Flash when the target argument is not a MovieClip. SWF6 specifically: the Color
constructor validates its target and returns undefined for non-MC targets.

**Fix:** In the Color constructor, check if the target resolves to a MovieClip.
If not, push `undefined` instead of creating a Color object. This is a SWF6+
behavior (SWF5 Color-v5 already passes without this check). Already documented
in NEAR_PASSING_TESTS_PLAN Fix 4 as "post-delete case where Flash considers the
constructor permanently gone."

### 3b: ColorTransform constructor default args (1 test → possible PASS)

**Test:** ColorTransform-v8 (9 diffs, 46/55 = 83.6%)

**Key diffs:**
```
# Constructor with NaN args — NaN doesn't propagate to later args:
- PASSED: ... alphaOffset == 456
+ FAILED: ... alphaOffset == NaN

# Constructor with fewer-than-8 args — remaining fields should reset to defaults:
- PASSED: ... redMultiplier=1, ... alphaOffset=0 (identity)
+ FAILED: ... (previous values persist)

# rgb getter with large multiplier values — overflow handling:
- PASSED: ct.rgb == 65793000
+ FAILED: ct.rgb == 15263976
```

Three issues:
1. **NaN propagation:** When early constructor args are NaN, later args should
   still be read from the argument list (not short-circuit to NaN).
2. **Default args:** Calling `new ColorTransform()` with fewer than 8 args
   should default the remaining fields (multipliers=1, offsets=0), not keep
   previous values.
3. **rgb getter overflow:** The `rgb` getter computation needs to handle
   multiplier values that produce results outside 0-255 without clamping (Flash
   does unclamped integer arithmetic for `rgb`).

**Fix:** (1) Fix ColorTransform constructor to read all 8 args independently.
(2) Initialize all 8 fields to defaults before reading args. (3) Fix `rgb`
getter to use unclamped integer arithmetic matching Flash's behavior.

**File:** `SWFModernRuntime/src/actionmodern/action.c` — ColorTransform
constructor and rgb getter.

---

## Phase 4: LocalConnection.connect() validation

**Tests:** LocalConnection-v6/v7/v8 (8 diffs each, 50/58 = 86.2%)

**Diffs (6 functional + 2 count, identical across v6/v7/v8):**
Six `connect()` calls with invalid connection names return `true` (connected
successfully) instead of `false` (rejected).

**Root cause:** `connect()` doesn't validate the connection name argument. Flash
rejects connection names that contain certain invalid characters or patterns.

**Fix:** Add connection name validation to `actionLocalConnectionConnect()`:
- Reject null/undefined/empty names
- Reject names containing `:` (reserved for domain prefix)
- Reject names starting with `_` (reserved for system connections)
- Possibly reject other invalid patterns (investigate the specific names in the
  test by running with `--diff` and inspecting which names are being tested)

**File:** `SWFModernRuntime/src/actionmodern/action.c` — LocalConnection
connect handler.

---

## Phase 5: ExternalInterface _toXML/_toAS

**Test:** ExternalInterface-v8 (5 diffs, 113/118 = 95.8%)

**Key diffs:**
```
# _toXML on empty object includes inherited/prototype properties:
- <object></object>
+ <object><property id="setTrailerMode">...</property>...</object>

# _toXML on XML node includes wrong property set:
- (full XML node property dump including methods)
+ (partial dump, missing methods, different property order)

# _toAS doesn't reconstruct function values:
- PASSED: typeof(EI._toAS(o)) == "function"
+ FAILED: ... obtained: undefined
```

Three issues:
1. **_toXML inherited properties:** `_toXML` on an empty object `{}` should
   produce `<object></object>`, but our implementation enumerates inherited
   properties from the prototype chain.
2. **_toXML XML node properties:** Property enumeration order and completeness
   differ for XML objects.
3. **_toAS function reconstruction:** The `_toAS` deserialization doesn't handle
   function-type values.

**Fix:** (1) `_toXML` should only serialize own enumerable properties (use
`hasOwnProperty` filter). (2) Fix XML node property enumeration. (3) Add
function type handling to `_toAS`.

**Complexity:** Medium — the _toXML fix is straightforward but _toAS function
reconstruction may require new infrastructure.

---

## Phase 6: Inheritance and instanceof fixes

This phase has the most cross-cutting fixes. Issues are version-dependent.

### 6a: super() constructor chain depth (v7/v8 → PASS, helps v5/v6)

**Tests:** Inheritance-v7 (6 diffs), Inheritance-v8 (5 diffs)

**Diffs (v8):**
```
- PASSED: n == "undefinedFFC"
+ FAILED: ... obtained: undefinedFC   (missing one "F" constructor call)
- PASSED: FctorCalls == 1
+ FAILED: ... obtained: 0
```
Plus 1 extra output line (infinite recursion test produces output instead of
halting — may need script execution limit or accept as permanent diff).

**Root cause:** In a 3-level chain A→B→F, `new F()` is calling F then C (via
super) but skipping the middle level. The super() depth computation in
`actionNewObject` or `actionNewMethod` loses one level when traversing the
constructor chain.

**Fix:** Debug the super depth tracking during `new F()` where F's constructor
calls `super()`. Check `pushSuperContext` depth computation — the "F" level
constructor may not be incrementing depth correctly.

### 6b: SWF5 super should be undefined (v5, 10 diffs)

**Tests:** Inheritance-v5 (18 diffs total, 10 from this issue)

**Diffs:**
```
# super.whoami() should return undefined in SWF5:
- PASSED: bo.whoami() == ".B"
+ FAILED: ... obtained: A.B   (super works when it shouldn't)

# new F() should NOT call parent constructors in SWF5:
- PASSED: n == "C"
+ FAILED: ... obtained: FAC   (parent constructors called)
- PASSED: FctorCalls == 0
+ FAILED: ... obtained: 1
```

**Root cause:** In SWF5, `super` is not a language feature — it should be
undefined. Our runtime provides super() functionality regardless of SWF version.

**Fix:** Gate super() constructor chaining on SWF version >= 6. In SWF5,
`actionNewObject` should only call the direct constructor, not traverse the
`__constructor__` chain. Similarly, `super` in method calls should resolve to
undefined in SWF5.

**Cross-reference:** This is related to the existing SWF5 closure semantics
work (`SWF5_NO_CLOSURE` in memory). The same version-gating pattern applies.

### 6c: `__constructor__` should not be set in SWF5 (v5, 1 diff)

```
- PASSED: typeof(DerivedClass1.prototype.__constructor__) == 'undefined'
+ FAILED: ... obtained: function
```

**Fix:** Don't set `__constructor__` on prototypes when SWF version < 6.

### 6d: SubObj1.prototype undefined (v5/v6/v7, 1 diff each)

```
- PASSED: SubObj1.prototype != undefined
+ FAILED: SubObj1.prototype != undefined
```

**Root cause:** User-defined constructor functions should have a `.prototype`
property created lazily or eagerly. Our implementation may not be creating it
in all cases. Investigate whether `SubObj1` is defined via `function SubObj1()`
or `var SubObj1 = function(){}` — the prototype creation path differs.

### 6e: instanceof Function/Object for constructors (v5/v6, 2 diffs each)

```
- PASSED: SubObj1 instanceOf Function
+ FAILED: SubObj1 instanceOf Function
- PASSED: _root instanceOf MovieClip
+ FAILED: _root instanceOf MovieClip
```

**Root cause:** Two separate issues:
1. User-defined functions fail `instanceof Function` — the Function constructor
   prototype chain isn't wired up correctly.
2. `_root` fails `instanceof MovieClip` — the MovieClip constructor's prototype
   isn't in `_root.__proto__` chain.

**Fix:** (1) Ensure all ASFunction objects have `__proto__` pointing to
`Function.prototype`. (2) Ensure MovieClip instances (including `_root`) have
`MovieClip.prototype` in their `__proto__` chain.

**Cross-reference:** The `instanceof MovieClip` issue also affects TextField-v5
(Phase 2b) and Selection-v6 (Phase 7).

### 6f: Function.__proto__ == Function.prototype (v6, 2 diffs)

```
- PASSED: __proto__ == Function.prototype
+ FAILED: ... obtained: [object Object]
```

User-defined functions' `__proto__` should be `Function.prototype`. Our
implementation points to a generic object instead.

---

## Phase 7: Selection replaceSel index tracking

**Tests:** Selection-v6/v7/v8 (11-12 diffs each, 113-114/125 = ~91%)

**Key diffs (v6):**
```
# setFocus(true) should return false:
- PASSED: Selection.setFocus(true) == false
+ FAILED: ... obtained: true

# replaceSel index tracking (6 functional diffs):
- PASSED: Selection.getCaretIndex() == 2
+ FAILED: ... obtained: 3
- PASSED: Selection.getEndIndex() == 6
+ FAILED: ... obtained: 9
```

Two root causes:
1. **setFocus(true):** `Selection.setFocus()` should return `false` when passed
   a boolean `true` (not a valid target). Our implementation accepts it.
2. **replaceSel index tracking:** After `Selection.replaceSel()`, the selection
   indices (begin/caret/end) are wrong. The replacement text length changes the
   offsets, and our index tracking doesn't account for the change correctly.

**Fix:** (1) Validate setFocus argument — reject non-string, non-object
arguments. (2) After replaceSel, recalculate selection indices based on the
length difference between removed and inserted text.

**Note:** Selection-v6 has one additional diff vs v7/v8:
`mc instanceof MovieClip` — shared with Phase 6e.

---

## Verification

After each phase, run the affected tests:
```bash
# Phase 1
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_gnash/actionscript.all \
  --test=NetStream-v6 --test=NetStream-v7 --test=NetStream-v8 \
  --test=Transform-v6 --test=Transform-v7 --diff --verbose

# Phase 2
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_gnash/actionscript.all \
  --test=TextFieldHTML-v6 --test=TextFieldHTML-v7 --test=TextFieldHTML-v8 \
  --test=TextField-v5 --diff --verbose

# Phase 3
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_gnash/actionscript.all \
  --test=Color-v6 --test=ColorTransform-v8 --diff --verbose

# Phase 4
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_gnash/actionscript.all \
  --test=LocalConnection-v6 --test=LocalConnection-v7 --test=LocalConnection-v8 --diff --verbose

# Phase 5
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_gnash/actionscript.all \
  --test=ExternalInterface-v8 --diff --verbose

# Phase 6
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_gnash/actionscript.all \
  --test=Inheritance-v5 --test=Inheritance-v6 --test=Inheritance-v7 --test=Inheritance-v8 --diff --verbose

# Phase 7
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_gnash/actionscript.all \
  --test=Selection-v6 --test=Selection-v7 --test=Selection-v8 --diff --verbose
```

Always run the full Gnash CI suite after fixes to check for regressions —
Gnash tests share the Dejagnu.swf child movie and modifications to prototype
chains or constructors can have wide blast radius.

## Cross-Cutting Fix Map

Several root causes appear in multiple phases:

| Root Cause | Affected Phases | Tests |
|-----------|----------------|-------|
| `instanceof MovieClip` on display objects | 2b, 6e, 7 | TextField-v5, Inheritance-v5/v6, Selection-v6 |
| Function `__proto__` → `Function.prototype` | 6d, 6e, 6f | Inheritance-v5/v6/v7/v8 |
| SWF5 super/constructor version gating | 6b, 6c | Inheritance-v5 |
| replaceSel selection index tracking | 7 | Selection-v6/v7/v8 |
