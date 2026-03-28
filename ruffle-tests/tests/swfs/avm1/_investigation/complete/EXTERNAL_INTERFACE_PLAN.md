# ExternalInterface Helper Methods Plan
<!-- TESTS: external_interface_escapexml, external_interface_unescapexml, external_interface_toxml_basic, external_interface_toxml_array, external_interface_jsquotestring, external_interface_toas_basic, external_interface -->

<!-- PLAN_META
id: EXTERNAL_INTERFACE
status: complete
phases:
  - id: 1
    name: "String Escaping/Quoting (3 tests, 87 lines)"
    status: complete
  - id: 2
    name: "Value-to-XML Serialization (2 tests, 204 lines)"
    status: complete
  - id: 3
    name: "XML-to-Value Deserialization (1 test, 354 lines)"
    status: complete
  - id: 4
    name: "Bridge Methods (1 test, 84 lines) —"
    status: complete
dependencies:
  - plan: XML
    type: requires
    reason: "ExternalInterface uses XML serialization"
blockers: []
-->

Last updated: 2026-03-06

## Status: COMPLETE — All 7/7 tests passing (729 lines).

### Verified 2026-03-06
All 7 tests confirmed passing locally. Phase 4 (`external_interface`) unblocked via test_harness.c mock approach — 84/84 PASS.

### Test Inventory

| Test | Lines | Current | Phase | Effort |
|------|-------|---------|-------|--------|
| external_interface_escapexml | 26 | **26/26 PASS** | Phase 1 | Done |
| external_interface_unescapexml | 40 | **40/40 PASS** | Phase 1 | Done |
| external_interface_jsquotestring | 21 | **21/21 PASS** | Phase 1 | Done |
| external_interface_toxml_basic | 179 | **179/179 PASS** | Phase 2 | Done |
| external_interface_toxml_array | 25 | **25/25 PASS** | Phase 2 | Done |
| external_interface_toas_basic | 354 | **354/354 PASS** | Phase 3 | Done |
| external_interface | 84 | **84/84 PASS** | Phase 4 | Done |

### Overview

`flash.external.ExternalInterface` has several static helper methods for XML serialization/deserialization used by the JS↔SWF bridge. While the bridge itself (`available`, `addCallback`, `call`) requires browser integration and is blocked, the helper methods are pure string manipulation functions that can be fully implemented.

Currently `ExternalInterface` exists as a stub constructor with no methods.

---

## Phase 1: String Escaping/Quoting (3 tests, 87 lines)

### _escapeXML(value) → string

Converts a value to its XML-escaped string representation:
- `null`/no args → `null` (null type)
- Non-string values: coerce to string first, then escape
- Escapes: `&` → `&amp;`, `<` → `&lt;`, `>` → `&gt;`, `"` → `&quot;`, `'` → `&apos;`
- Already-escaped entities are double-escaped: `&amp;` → `&amp;amp;`

### _unescapeXML(value) → string

Reverse of _escapeXML:
- `null`/no args → `null` (null type)
- Non-string values: coerce to string first, then unescape
- Unescapes: `&amp;` → `&`, `&lt;` → `<`, `&gt;` → `>`, `&quot;` → `"`, `&apos;` → `'`
- Order matters: `&amp;` must be unescaped LAST to avoid double-unescaping

### _jsQuoteString(value) → string

Escapes a string for JavaScript embedding:
- `null`/no args → `null` (null type)
- Non-string values: coerce to string first
- Escapes only `"` → `\"` (backslash-quote)
- Existing backslash-quote `\"` → `\\\"` (existing backslash is escaped, then quote is escaped)
- Does NOT escape single quotes, `<`, `>`, `&`, etc.

### Implementation

Add 3 Function2Ptr handlers in `action.c`, register as methods on the ExternalInterface constructor object's `own_props`:

```c
// In ensureGlobalInit, after ExternalInterface stub constructor:
static ASFunction f_escapeXML = {0};
f_escapeXML.type = 2;
f_escapeXML.func2_ptr = actionEI_escapeXML;
setPropertyOnObject(ei_ctor, "_escapeXML", 10, make_function_var(&f_escapeXML));
// ... same for _unescapeXML, _jsQuoteString
```

Each function: read 1 arg, if no arg/null return NULL, else coerce to string, apply transformation, return new string.

**Estimated effort**: ~80 lines of C. Self-contained, no dependencies.

**Tests fixed**: external_interface_escapexml (26/26), external_interface_unescapexml (40/40), external_interface_jsquotestring (21/21). Remove jsquotestring from ignored_tests.txt.

---

## Phase 2: Value-to-XML Serialization (2 tests, 204 lines)

### _toXML(value) → string

Serializes an ActionScript value to XML string:
- `undefined`/no args → `<undefined/>`
- `null` → `<null/>`
- `true` → `<true/>`
- `false` → `<false/>`
- number → `<number>N</number>` (includes Infinity, -Infinity, NaN)
- string → `<string>ESCAPED</string>` (XML-escaped content)
- function → `<null/>` (functions serialize as null)
- array (has `.length`) → delegates to `_arrayToXML`
- object → delegates to `_objectToXML`

### _arrayToXML(value) → string

Serializes array-like value to XML:
- Non-array/non-object → `<array></array>` (empty)
- Array: iterates indices 0..length-1, each element → `<property id="N">RECURSIVE_TOXML</property>`
- Recursively calls `_toXML` for each element

### _argumentsToXML(value) → string

Like `_arrayToXML` but:
- Wraps in `<arguments>...</arguments>` tags
- Skips index 0 (starts from index 1 to length-1)
- Does NOT wrap elements in `<property>` tags — just raw `_toXML` output

### _objectToXML(value) → string

Serializes object properties to XML:
- Non-object → `<object></object>` (empty)
- Iterates own properties via `for-in` (enumerable properties only)
- Skips array indices (only named properties, or all for plain objects)
- Each property → `<property id="NAME">RECURSIVE_TOXML</property>`
- Property names are NOT XML-escaped in the `id` attribute (based on test output line 153: `id="<>&test;"'"`)
- Property values ARE XML-escaped via recursive `_toXML`

### Implementation

4 additional Function2Ptr handlers. The `_toXML` function is the core dispatcher based on type tag. `_arrayToXML`, `_argumentsToXML`, `_objectToXML` handle collection types. All build strings via buffer concatenation.

Key details from test output:
- String values: XML-escape the content using the same rules as `_escapeXML`
- Nested arrays: recursively serialize (test line 111: nested `[true]` inside array)
- Sparse arrays: undefined slots serialize as `<undefined/>` (test line 146)
- Object with `length` property: treated as array by `_toXML` (test line 59, 155)
- String passed to `_arrayToXML`: iterates string chars as array indices, each → `<undefined/>` (test line 121)

**Estimated effort**: ~150 lines of C. Depends on Phase 1 for XML escaping.

**Tests fixed**: external_interface_toxml_basic (179/179), external_interface_toxml_array (25/25).

---

## Phase 3: XML-to-Value Deserialization (1 test, 354 lines)

### _toAS(xmlNode) → value

Parses an XML node back to an ActionScript value:
- Takes an XML node (from `new XML().parseXML()`)
- `<undefined/>` → undefined
- `<null/>` → null
- `<true/>` → true
- `<false/>` → false
- `<number>N</number>` → number (parseFloat)
- `<string>TEXT</string>` → string (XML-unescaped)
- `<array>...</array>` → delegates to `_arrayToAS`
- `<object>...</object>` → delegates to `_objectToAS`
- Unknown/no node → undefined

### _arrayToAS(xmlNode) → Array

Parses `<array>` XML to an Array:
- Creates new Array
- Iterates `<property id="N">` children
- Sets array[N] = recursive `_toAS` on child's first child node
- Returns array with correct length

### _argumentsToAS(xmlNode) → Array

Like `_arrayToAS` but returns array with elements from direct children (not `<property>` wrapped).

### _objectToAS(xmlNode) → Object

Parses `<object>` XML to an Object:
- Creates new Object
- Iterates `<property id="NAME">` children
- Sets obj[NAME] = recursive `_toAS` on child's first child node

### Implementation

Requires XML node inspection — accessing `nodeName`, `childNodes`, `attributes`, `firstChild`, `nodeValue`. Our XML class already supports these from the XML_PLAN. The functions inspect the XML DOM tree and reconstruct AS values.

**Estimated effort**: ~120 lines of C. Depends on XML class support (already implemented).

**Tests fixed**: external_interface_toas_basic (354/354). Remove from ignored_tests.txt.

### Potential blockers

- Requires our XML parser to correctly parse the XML strings these tests pass in. The tests create XML nodes via `new XML(str)` then pass them to the `_toAS` functions. Our XML class should handle this already.
- `_objectToAS` and `_arrayToAS` need to inspect `attributes` array for `id` attribute — verify our XML attribute support.

---

## Phase 4: Bridge Methods (1 test, 84 lines) — COMPLETE

### external_interface test

Tests `ExternalInterface.available`, `addCallback`, and `call` — the actual JS↔SWF communication bridge. Implemented via:

1. **Runtime EI support** (`action.c`): `addCallback` registers AS callbacks, `call` dispatches to `g_external_call_handler`, `available` returns `true` when handler is set
2. **Test harness mechanism** (`verify_output.py`): Per-test `test_harness.c` files are auto-detected and compiled with `-DHAS_TEST_HARNESS`; `main.c` calls `test_harness_init()` before `swfStart()`
3. **Mock provider** (`test_harness.c`): Implements `ping`/`trace`/`reentry` mock methods + after-tick hook that calls `parrot` and `callWith` callbacks after frame 1
4. **ExternalValue Debug formatting**: Matches Rust's `#[derive(Debug)]` output format for `ExternalValue` enum (sorted BTreeMap keys, etc.)
5. **Function.call own_props override**: CallMethod checks func->own_props for method overrides before built-in `Function.call()` dispatch

---

## Priority

| Phase | Tests | Lines Gained | Effort | Dependencies |
|-------|-------|-------------|--------|--------------|
| Phase 1 | 3 | 87 | Easy (~80 LOC) | None |
| Phase 2 | 2 | 204 | Medium (~150 LOC) | Phase 1 |
| Phase 3 | 1 | 354 | Medium (~120 LOC) | XML class |
| Phase 4 | 1 | 84 | Done (~350 LOC) | Test harness |
| **Total** | **7** | **729** | **~700 LOC** | |

Phases 1-3 combined would gain 645 lines across 6 tests with no external dependencies beyond the existing XML class. This makes it one of the highest-ROI plans available.

---

## Implementation Notes

All methods are static on the ExternalInterface constructor object, accessed via `flash.external.ExternalInterface._methodName()`. In our runtime, `flash.external.ExternalInterface` resolves to the constructor function stored on the `flash.external` package object. The methods need to be set as properties on this constructor function's `own_props`.

Pattern: same as how `Object.registerClass` is a static method on the Object constructor.
