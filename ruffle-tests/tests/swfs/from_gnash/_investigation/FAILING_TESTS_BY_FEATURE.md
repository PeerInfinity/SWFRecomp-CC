# Gnash Failing Tests by Feature Category

Last updated: 2026-03-19 (based on CI run 043094ef)

- **Total tests**: 204 (190 actionscript.all + 14 misc-swfmill.all)
- **Passing**: 52 (44 + 8) = 25.5%
- **Failing**: 152 (2 segfault, 5 runtime error, 145 output mismatch)
- **Line-level match**: 11,034/16,986 (65.0%)

Tests are grouped by root cause / feature area. Within each category, tests are sorted by match rate (best first). Each category includes estimated fix complexity and number of tests affected.

---

## 1. Equality/Comparison Operator Coercion (est. ~5 tests)

Failing tests: ops-v8 (95.8%)

String-to-number coercion in equality operators. `Infinity == 'Infinity'` returns false when it should return true. Similarly `NaN` comparisons and `!r` boolean coercion fail. ActionScript's `==` operator should coerce strings to numbers when comparing with numeric types.

**Root cause**: `actionEquals2` or the abstract equality algorithm doesn't coerce string↔number for Infinity/NaN string representations.

**Fix complexity**: Low — add string-to-number coercion path in equality comparison.

**Impact**: ops-v8 would go from 95.8% → ~100%. Pattern likely affects other tests with string/number comparisons.

---

## 2. Math Object Edge Cases (est. 4 tests)

Failing tests: Math-v5 (97.8%), Math-v6 (97.8%), Math-v7 (97.6%), Math-v8 (97.6%)

6-7 lines wrong per test. Specific failures:
- `Math.round("")` should return 0 (empty string → NaN → 0 in Flash's round)
- `Math.pow(x)` with 1 arg — behavior differs between SWF versions
- Math constant precision (exact string representation of constants)

**Root cause**: Edge cases in `coerceMathArgs` and specific Math method implementations.

**Fix complexity**: Low — individual edge case fixes.

**Impact**: 4 tests go from 97.6-97.8% → ~100%.

---

## 3. NetStream/Video Prototype Properties (est. 6 tests)

Failing tests: NetStream-v6/v7/v8 (95.0%), Video-v5 (57.1%)

4 lines wrong per NetStream test. `hasOwnProperty('currentFps')` and similar property introspection checks fail — properties not registered on NetStream.prototype.

**Root cause**: NetStream and Video prototypes don't have all expected builtin properties defined.

**Fix complexity**: Low — register missing prototype properties.

**Impact**: 3 NetStream tests go from 95% → ~100%.

---

## 4. Color Object Implementation Gaps (est. 4 tests)

Failing tests: Color-v5 (88.6%), Color-v6 (86.0%), Color-v7/v8 (87.6%)

Issues:
- `Color.getTransform()` on invalid target returns object instead of undefined
- `Color.setTransform()` values not stored/retrieved correctly
- `instanceof Color` checks
- Color prototype method visibility

**Root cause**: Color constructor/prototype wiring gaps. `getTransform` on invalid target not handled.

**Fix complexity**: Medium — needs Color builtin property registration + invalid target handling.

**Impact**: 4 tests improve significantly (16-24 diff lines each).

---

## 5. Selection/Stage Non-Constructable Globals (est. 5 tests)

Failing tests: Selection-v5 (85.7%), Selection-v6/v7/v8 (86-87%), Stage-v5 (86.8%)

In SWF5, `typeof(Selection)` and `typeof(Stage)` should return `'undefined'` — these globals shouldn't be constructable. Our implementation returns `'object'`. Also: `Stage.addListener`/`removeListener` should be undefined in SWF5.

**Root cause**: Global singleton objects are created too eagerly, ignoring SWF version gating.

**Fix complexity**: Medium — version-gate global singleton initialization.

**Impact**: 5 tests improve by 3-16 lines each.

---

## 6. Error Constructor & Prototype (est. 4 tests)

Failing tests: Error-v5 (75.0%), Error-v6/v7/v8 (77.4%)

Issues:
- `new Error(7.8898)` — message should be coerced to string "7.8898", we store "Error"
- `e.toString()` format doesn't match expected output
- Error subclasses (TypeError, ReferenceError) constructor behavior

**Root cause**: Error constructor doesn't coerce non-string arguments to `.message`. toString format wrong.

**Fix complexity**: Low-Medium — fix Error constructor + toString.

**Impact**: 4 tests improve by 7 lines each.

---

## 7. Inheritance & Prototype Chain (est. 4 tests)

Failing tests: Inheritance-v5 (82.6%), Inheritance-v6 (85.2%), Inheritance-v7 (segfault), Inheritance-v8 (segfault)

v5/v6: 20-27 diff lines. Issues with constructor execution ordering, `instanceof` on custom constructors, `Function.prototype` visibility, `__constructor__` setup.

v7/v8: Segfault. Root cause likely same as previous Inheritance segfaults — prototype chain walking hits corrupted memory.

**Root cause**: Multiple OOP gaps — constructor chain, instanceof, `__proto__` setup.

**Fix complexity**: Medium-High (v5/v6 OOP fixes), High (v7/v8 segfault investigation).

**Impact**: 2 tests improve significantly; 2 segfaults need separate investigation.

---

## 8. Delete Operator (est. 4 tests)

Failing tests: delete-v5 (61.7%), delete-v6 (63.3%), delete-v7 (65.0%), delete-v8 (66.7%)

23 diff lines in v5. Issues:
- `delete` on local variables doesn't actually remove them from scope
- `delete nonExistent` returns wrong boolean value
- `delete func.prototype` should return false (non-deletable)
- Variables persist after deletion

**Root cause**: `actionDelete` / `actionDelete2` don't properly remove variables from scope chain. DONT_DELETE flag not checked correctly.

**Fix complexity**: Medium — scope chain deletion + property flag handling.

**Impact**: 4 tests improve by 20-23 lines each.

---

## 9. Enumerate/For-In (est. 3 tests)

Failing tests: enumerate-v6/v7/v8 (44.9%)

27 diff lines each. Issues:
- `for-in` enumeration of object properties returns empty
- Sprite children incorrectly appear as `_root` own properties
- `typeof` returns 'number' for MovieClip children instead of 'movieclip'

**Root cause**: `actionEnumerate2` or the for-in loop doesn't properly enumerate dynamic properties. Display list children vs. own properties confusion.

**Fix complexity**: Medium — enumerate opcode + display list vs property distinction.

**Impact**: 3 tests improve from 45% → higher.

---

## 10. ASnative Classes (est. 4 tests)

Failing tests: ASnative-v5 (28.0%), ASnative-v6/v7 (25.5%), ASnative-v8 (26.4%)

77-81 diff lines each. Tests call `ASnative(class_id, method_id)` for many builtin classes:
- ASnative(100, *) — Object methods (partially done)
- ASnative(101, *) — Object.prototype methods (done)
- ASnative(103, *) — Date methods (not done)
- ASnative(106, *) — Number methods (not done)
- ASnative(250, *) — String methods (not done)
- ASnative(252, *) — String functions (not done)
- ASnative(253, *) — Number/Math functions (not done)

**Root cause**: Most ASnative class IDs are not implemented.

**Fix complexity**: High (many classes) but incremental — each class can be added independently.

**Impact**: 4 tests, but improvements are gradual as classes are added.

---

## 11. With Statement on Primitives (est. 4 tests)

Failing tests: with-v5 (30.0%), with-v6/v7/v8 (18.3%)

28-103 diff lines. `with(number)` and `with(string)` should auto-box primitives to their wrapper objects (Number.prototype, String.prototype), allowing property access within the with block.

**Root cause**: `actionWith` doesn't auto-box primitive values. Also WITH scope chain management issues with nested with blocks.

**Fix complexity**: Medium — auto-boxing in actionWith + scope chain fixes.

**Impact**: 4 tests, significant improvement.

---

## 12. String Class Methods (est. 4 tests)

Failing tests: String-v5 (60.9%), String-v6 (60.2%), String-v7 (59.7%), String-v8 (59.4%)

140-153 diff lines each. Many string method edge cases:
- `String.fromCharCode` missing
- `charAt`/`charCodeAt` boundary behavior
- `split` with regex or complex separators
- `replace` not implemented
- `search`/`match` regex support

**Root cause**: Several String prototype methods not implemented or incomplete.

**Fix complexity**: High — regex support needed for `replace`/`match`/`search`.

**Impact**: 4 tests, but many lines.

---

## 13. Number Formatting/Coercion (est. 4 tests)

Failing tests: Number-v5 (79.1%), Number-v6 (76.2%), Number-v7 (78.9%), Number-v8 (78.5%)

51-57 diff lines. Issues with:
- `Number.toString(radix)` for bases 2, 8, 16
- `Number.toFixed()`/`toPrecision()`/`toExponential()` not implemented
- Numeric string coercion edge cases

**Root cause**: Number formatting methods not implemented.

**Fix complexity**: Medium — standard ECMAScript number formatting methods.

**Impact**: 4 tests improve by ~50 lines each.

---

## 14. Try/Catch/Finally Control Flow (est. 4 tests)

Failing tests: Try-v5/v6/v7/v8 (runtime error — exit code 1)

OOM via runaway string concatenation in nested try/catch/finally blocks. The recompiler generates `goto` jumps across try/finally boundaries causing finally blocks to execute repeatedly.

**Root cause**: Recompiler try/finally control flow generates incorrect goto targets for nested cases.

**Fix complexity**: High — recompiler control flow analysis for try/finally blocks.

**Impact**: 4 tests currently crash.

---

## 15. toString/valueOf Coercion (est. 4 tests)

Failing tests: toString_valueOf-v5 (59.9%), toString_valueOf-v6 (76.1%), toString_valueOf-v7/v8 (76.8%)

36-55 diff lines. Tests exercise valueOf/toString coercion paths for various operations (comparison, arithmetic, string concat). Some failures from ASArray/ASObject cast bug in `convertFloat`.

**Root cause**: valueOf/toString dispatch on arrays, objects with custom valueOf. ASArray cast bug.

**Fix complexity**: Medium — fix ASArray path in convertFloat + valueOf dispatch.

**Impact**: 4 tests, significant line improvements.

---

## 16. Case/Switch Statement (est. 4 tests)

Failing tests: case-v5 (82.1%), case-v6 (24.7%), case-v7/v8 (19.4%)

v5 has 7 diff lines; v6/v7/v8 have 50+ diff lines. v5 is close — likely strict equality vs abstract equality in switch. v6+ have severe issues (possibly related to the `with` block duplicate label fix or scope chain).

**Root cause**: Switch/case statement comparison semantics; v6+ tests exercise more complex patterns.

**Fix complexity**: Low for v5, Medium for v6+.

**Impact**: 4 tests.

---

## 17. Misc-SWFMill: Frame/Tag Execution Issues (est. 6 tests)

Failing tests from misc-swfmill.all:

| Test | Match | Issue |
|------|-------|-------|
| dict_event | 60% (3/5) | Clip event handler not firing for multiple frames |
| jump_after_end | 33% (1/3) | Jump past END_OF_ACTIONS not handled |
| initaction_in_definesprite | 0% (0/2) | InitAction inside sprite definition not executing |
| jump_to_prev_block | 0% (0/1) | Backward jump in bytecode not re-executing |
| tags_after_last_showframe | 0% (0/15) | Tags after final ShowFrame cause infinite loop |
| zeroframe_definesprite | 0% (0/3) | Zero-frame sprite timing wrong |

**Root cause**: Various recompiler and runtime edge cases for frame/tag execution.

**Fix complexity**: Varies — each is an independent issue.

---

## 18. Other Feature Areas (many tests, lower priority)

| Category | Tests | Match Range | Key Issue |
|----------|-------|-------------|-----------|
| AsBroadcaster | v5-v8 (4) | 70-79% | Listener dispatch, broadcastMessage |
| ContextMenu | v7-v8 (2) | 72.5% | customItems, enabled, builtInItems |
| TextFormat | v5-v7 (3) | 64-78% | TextFormat constructor coercion, getters |
| TextSnapshot | v6-v8 (3) | 76.3% | getText, findText, hitTestTextNearPos |
| TextFieldHTML | v6-v8 (3) | 86.5% | htmlText getter edge cases |
| Sound | v5-v8 (4) | 63-77% | Sound.attachSound, Sound.start, volume |
| ExternalInterface | v6-v8 (3) | 51-70% | addCallback, call, data marshalling |
| MovieClip | v5 (1) | 65.0% | Many MC properties/methods |
| Mouse | v5-v8 (4) | 57-62% | Mouse.addListener, cursor visibility |
| Microphone | v6-v8 (3) | 60.8% | Microphone prototype properties |
| Camera | v6-v8 (3) | 36.7% | Camera prototype properties |
| LoadVars | v6-v8 (3) | 44.1% | LoadVars.load, onLoad, decode |
| LocalConnection | v5-v8 (4) | 41-57% | IPC system, connect/send |
| System | v5-v8 (4) | 38-40% | System.capabilities, security |
| Key | v5-v8 (4) | 20-27% | Key object, isDown, getCode |
| MovieClipLoader | v7-v8 (2) | 27.9% | loadClip, events |
| BitmapData | v8 (1) | 52.5% | BitmapData class methods |
| targetPath | v6-v8 (3) | 32.1% | targetPath function for nested MCs |
| flash (geom) | v5-v7 (3) | 70.0% | flash.geom stubs |
| Instance | v5-v8 (4) | 52-64% | instanceof, constructor, typeof |
| Accessibility | v6-v8 (3) | 47-53% | Accessibility.isActive, properties |
| array-v5 | (1) | runtime error | Array test OOM |

---

## Recommended Fix Priority

### Tier 1: Quick Wins (est. +8-12 tests to passing)

| Fix | Tests | Current | Effort |
|-----|-------|---------|--------|
| Math edge cases | Math-v5/v6/v7/v8 | 97.6-97.8% | Low |
| Equality coercion (Infinity/NaN strings) | ops-v8 | 95.8% | Low |
| NetStream prototype properties | NetStream-v6/v7/v8 | 95.0% | Low |
| Error constructor message coercion | Error-v5/v6/v7/v8 | 75-77% | Low |

### Tier 2: Medium-Impact Fixes (est. +10-15 tests improved)

| Fix | Tests | Current | Effort |
|-----|-------|---------|--------|
| Color getTransform/setTransform | Color-v5/v6/v7/v8 | 86-89% | Medium |
| Selection/Stage SWF5 gating | Selection-v5-v8, Stage-v5 | 85-87% | Medium |
| Delete operator scope handling | delete-v5/v6/v7/v8 | 62-67% | Medium |
| toString/valueOf + ASArray fix | toString_valueOf-v5-v8 | 60-77% | Medium |

### Tier 3: Larger Efforts (many tests, more work)

| Fix | Tests | Current | Effort |
|-----|-------|---------|--------|
| ASnative class implementations | ASnative-v5-v8 | 26-28% | High (incremental) |
| With auto-boxing | with-v5-v8 | 18-30% | Medium |
| Number formatting methods | Number-v5-v8 | 76-79% | Medium |
| String regex support | String-v5-v8 | 59-61% | High |
| Try/finally control flow | Try-v5-v8 | crash | High |
| Enumerate opcode | enumerate-v6-v8 | 45% | Medium |

### Tier 4: Feature-specific work (requires significant new infrastructure)

Key, Camera, System, LoadVars (network), LocalConnection (IPC), MovieClipLoader (loadMovie).
