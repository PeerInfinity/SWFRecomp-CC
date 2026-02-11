# infinite_recursion_function Tests Investigation

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

### SWFRecomp result: 1 line ("end") — output_mismatch

`addProperty` is not implemented in the runtime. The setter/getter never fire.
Setting `variable = 5` is a plain variable assignment. Only "end" prints.

### Root causes
1. `addProperty` (virtual property getter/setter) is not implemented
2. No concept of "special" recursion counter separate from function call depth
3. Even if addProperty worked, the mutual recursion semantics would be wrong

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

### SWFRecomp result: 2 lines ("undefined", "end") — output_mismatch

`addProperty` is not implemented, so `variable` is just an undefined variable.
`trace(variable)` prints "undefined", then "end" prints.

### Root causes
1. `addProperty` not implemented (same as test 2)
2. No special recursion counter

---

## Summary of Differences

| Aspect | Flash/Ruffle | SWFRecomp |
|--------|-------------|-----------|
| ScriptLimits tag | Sets max_recursion_depth | Stores in `g_max_call_depth` (fixed) |
| Default max recursion | 255 (Ruffle) / 256 (Flash) | 256 (default, overridden by ScriptLimits) |
| FunctionRecursionLimit | Fatal — halts all execution | Fatal — sets `g_execution_halted` (fixed) |
| Special recursion limit | 66, non-fatal — returns undefined | Does not exist |
| addProperty | Virtual getter/setter on objects | Not implemented |
| Getter/setter calls | Counted as "Special" (separate counter) | N/A |

## What Would Be Needed to Fix

### For test 1 (infinite_recursion_function): DONE
All three items implemented in commit 0ed2aef. Test passes.

### For tests 2 and 3 (setter / virtual_property):
1. Implement `addProperty` builtin on objects — register getter/setter function
   pairs for named properties
2. When getting/setting a virtual property, invoke the registered getter/setter
3. Add a separate "special" recursion counter (limit 66) for getter/setter and
   other "special" invocations (valueOf, toString, event callbacks)
4. When special limit is hit, return undefined (non-fatal), don't halt execution
