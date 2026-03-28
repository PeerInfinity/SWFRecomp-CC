# infinite_recursion_function Tests Investigation
<!-- TESTS: infinite_recursion_function, infinite_recursion_function_in_setter, infinite_recursion_virtual_property -->

<!-- PLAN_META
id: infinite_recursion_function
status: complete
phases:
  - id: 1
    name: "infinite_recursion_function"
    status: complete
  - id: 2
    name: "infinite_recursion_function_in_setter"
    status: complete
  - id: 3
    name: "infinite_recursion_virtual_property"
    status: complete
dependencies: []
blockers: []
-->

Three related tests exercise recursion depth limiting in different scenarios.

## 1. infinite_recursion_function

### ActionScript logic (reconstructed from recompiled C)

```actionscript
// ScriptLimits: max_recursion=5, timeout=10

function recursive() {
    trace("// start of recursive() function");
    recursive();  // infinite recursion
}

try {
    recursive();
} catch (error) {
    trace("Caught error: " + error);
}
trace("End - this should not show up!");
```

### Expected output (4 lines, then halt)

```
// start of recursive() function
// start of recursive() function
// start of recursive() function
// start of recursive() function
```

The function recurses 4 times (depth 1..4), then Flash/Ruffle hits the limit of 5
and **halts all further script execution permanently**. The try-catch does NOT fire
and "End" never prints.

### SWFRecomp result: PASS

Fixed in commit 0ed2aef. `tagScriptLimits()` now stores `max_recursion` in
`g_max_call_depth`, and hitting the limit sets `g_execution_halted = 1` which
prevents all further `actionTrace`, `actionCallFunction`, and `actionCallMethod`
calls (matching Flash/Ruffle's fatal halt behavior).

---

## 2. infinite_recursion_function_in_setter

### ActionScript logic (reconstructed from recompiled C)

```actionscript
// No ScriptLimits tag — default depth applies (256 in Flash, 255 in Ruffle)

function recursive() {
    trace("// start of recursive() function");
    variable = 5;  // triggers setter → mutual recursion
}

function getter() {
    return 5;
}

function setter() {
    trace("// start of setter() function");
    recursive();  // calls back into recursive()
}

_root.addProperty("variable", getter, setter);
variable = 5;  // kicks off the recursion chain
trace("end");
```

The chain is: `variable = 5` → `setter()` → `recursive()` → `variable = 5` →
`setter()` → `recursive()` → ...

### Expected output (131 lines)

65 pairs of "setter" + "recursive" traces (130 lines), then "end".

### Key insight: two recursion counters

Ruffle tracks TWO separate recursion counters:
- **`function_count`**: incremented for `FunctionCall` and `ConstructorCall` reasons.
  Limited by `max_recursion_depth` (default 255, or ScriptLimits value).
- **`special_count`**: incremented for `Special` reason. Hard-limited at 66.

Getter/setter invocations use `ExecutionReason::Special`, which increments
`special_count` (not `function_count`). So the recursion chain alternates:
- `setter()` is called as Special → special_count increments
- Inside setter, `recursive()` is called as FunctionCall → function_count increments
- Inside recursive, `variable = 5` triggers setter as Special → special_count increments
- ...and so on

The special_count hits 65 after 65 setter calls + 65 recursive calls = 130 trace
lines. The `SpecialRecursionLimit` error is NOT fatal (unlike `FunctionRecursionLimit`
with ScriptLimits) — execution continues, so "end" prints as line 131.

### SWFRecomp result: PASS

Fixed in commit d84fa66. Implemented `addProperty` with virtual property table,
`invokeSpecialFunction` helper, and a separate `g_special_depth` counter (limit 66).
Getter/setter calls increment `g_special_depth` instead of `g_call_depth`. When
the special limit is hit, returns `undefined` (non-fatal).

---

## 3. infinite_recursion_virtual_property

### ActionScript logic (reconstructed from recompiled C)

```actionscript
// No ScriptLimits tag

function getter() {
    trace(" // start of getter() function");
    return variable;  // reading 'variable' triggers getter again → self-recursion
}

_root.addProperty("variable", getter, null);  // getter only, no setter
trace(variable);  // triggers getter chain
trace("end");
```

The getter reads `variable`, which triggers the getter again — pure self-recursion
through virtual property access.

### Expected output (67 lines)

65 getter traces (the leading space is intentional), then "undefined", then "end".

The getter recurses 65 times via the special counter. When
`SpecialRecursionLimit` (66) is hit, the property access returns `undefined`
instead of calling the getter again. Since this is NOT the fatal
`FunctionRecursionLimit`, execution continues normally.

Note: lines have a leading space: ` // start of getter() function` (this is how
the original SWF's constant pool stores the string).

### SWFRecomp result: PASS

Fixed in commit d84fa66 (same as test 2).

---

## Summary

| Test | Status | Fixed In |
|------|--------|----------|
| infinite_recursion_function | PASS | 0ed2aef (ScriptLimits, g_execution_halted) |
| infinite_recursion_function_in_setter | PASS | d84fa66 (addProperty, special recursion counter) |
| infinite_recursion_virtual_property | PASS | d84fa66 (addProperty, special recursion counter) |

### Implementation details

- **Virtual property table**: `VirtualProperty` struct mapping variable names to getter/setter
  `ASFunction*` pointers. Checked in `actionGetVariable` and `actionSetVariable` before normal
  variable lookup.
- **Special recursion counter**: `g_special_depth` (limit `MAX_SPECIAL_DEPTH=66`), incremented
  by `invokeSpecialFunction()`. Non-fatal — returns `undefined` when exceeded.
- **addProperty built-in**: Handled in `actionCallFunction` alongside other built-ins like
  `ASSetPropFlags`. Returns `true` (1.0f) on success, `false` (0.0f) on failure.
- **Off-by-one fix**: The counter must be incremented BEFORE the limit check (`g_special_depth++`
  then check `>= 66`), not checked before incrementing. The latter allows 66 invocations instead
  of the correct 65.
