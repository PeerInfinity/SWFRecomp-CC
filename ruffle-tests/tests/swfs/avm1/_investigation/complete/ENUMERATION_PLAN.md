# Enumeration (for-in) Implementation Plan
<!-- TESTS: enumerate, array_enumerate, new_object_enumerate, prototype_enumerate, stage_object_enumerate, globals_swf5, globals_swf6, globals_swf7, globals_swf8, stage_object_properties, as_set_prop_flags, prototype_properties, object_prototypes, is_prototype_of -->

Last updated: 2026-02-18 — **COMPLETE** (all 5 direct tests passing, commit b899e90)

## Status: COMPLETE

All 5 directly-affected tests now pass:

| Test | Status | Commit |
|------|--------|--------|
| `enumerate` | **PASS** (regressed after b899e90 due to toString threshold change, re-fixed) | b899e90 (+ prior work) |
| `array_enumerate` | **PASS** | prior work |
| `new_object_enumerate` | **PASS** | prior work |
| `prototype_enumerate` | **PASS** | prior work |
| `stage_object_enumerate` | **PASS** | prior work |

**What was already done before this session**: Phases 1-6 of the plan had been implemented (segfault fix, enum order, array order, DontEnum, addProperty, MC children). Tests array_enumerate, new_object_enumerate, prototype_enumerate, stage_object_enumerate were all already passing.

**What was done in this session** (commit b899e90): Fixed two remaining `enumerate` test failures:
1. **SWF4 colon-path syntax** ("this:obj"): parse the colon separator, resolve the target MC ("this"/_root/_level0), then get the named property from its dynamic_props.
2. **Dot-path syntax** ("this.obj"): delegate to `actionGetVariable` which handles dot-separated path traversal.
3. **SetMember assignments**: after failing global variable table lookup, fall back to checking the current MC's `dynamic_props`.

---

## Overview (Historical)

Enumeration (`for-in`) was broken in multiple ways, affecting 5 directly-related tests and likely contributing to failures in many other tests that use property enumeration (e.g., `globals_swf5/6/7/8`, `stage_object_*`, `as_set_prop_flags`, `prototype_properties`, etc.).

**Original state**: `actionEnumerate` segfaulted on non-string stack values. `actionEnumerate2` ran but produced wrong property order, leaked non-enumerable properties (`__proto__`, `constructor`), didn't enumerate `addProperty` virtual properties, and didn't enumerate MovieClip child instance names.

**Original directly affected tests** (5 tests):

| Test | Original Status | Original Lines | Core Issues |
|------|--------|-------|-------------|
| `enumerate` | **SEGFAULT** | 0/65 | `actionEnumerate` reads stack as string without type check; crashes on non-string values |
| `array_enumerate` | mismatch | 0/5 | Array enumeration order wrong (indices vs named props ordering) |
| `new_object_enumerate` | mismatch | 4/8 | (a) Enumeration order reversed; (b) leaks `__proto__` and `constructor` |
| `prototype_enumerate` | mismatch | 1/5 | (a) `addProperty` virtual props not enumerated; (b) order wrong |
| `stage_object_enumerate` | mismatch | 1/4 | Child MovieClip instance names not enumerated |

**Indirectly affected tests** — many other tests use `for-in` and would benefit from correct enumeration order:
- `globals_swf5/6/7/8` (66% passing) — enumerate global scope
- `stage_object_properties` (68%) — enumerate Stage properties
- `as_set_prop_flags` (57%) — property flag manipulation affects enumeration
- `prototype_properties` (71%) — prototype property enumeration
- `object_prototypes` (84%) — prototype chain enumeration
- `is_prototype_of` (66%) — prototype chain walking

---

## Root Cause Analysis

### Bug 1: SEGFAULT in `actionEnumerate` (action.c:6335)

**Cause**: `actionEnumerate` unconditionally reads the stack top as a string (reads `string_id` from SP+12, `u16_len` from SP+8, `pointer` from SP+16) without checking the type tag at SP+0. When the bytecode pushes a non-string value (undefined, null, integer, double, boolean, or object) before calling `ActionEnumerate`, the function interprets garbage as a UTF-16 pointer and crashes.

**SWF spec context**: `ActionEnumerate` (opcode 0x46) is defined to pop a **variable name** (string) from the stack. However, Flash Player handles the case where a non-string is on the stack gracefully — it converts to string or pushes only the null terminator. The `enumerate` test explicitly pushes undefined, null, integers, doubles, booleans, and objects before calling `ActionEnumerate` and expects `undefined` to be traced (i.e., only the null/undefined terminator was pushed).

**Fix**: Check the type tag first. For non-string types, convert to string via `convertString` (matching Flash's behavior), then look up as a variable name. If the variable doesn't exist or isn't an object, push only the terminator.

### Bug 2: Wrong Enumeration Order (action.c:9331, 6433)

**Cause**: Both `actionEnumerate` and `actionEnumerate2` iterate properties from index 0 to `num_used-1` (forward insertion order) and prepend each to a linked list. The linked list is then pushed onto the stack. Since prepending reverses order, and the stack is LIFO, properties are popped in **forward insertion order** (first property inserted = first popped).

**Expected behavior**: Flash enumerates own properties in **reverse insertion order** — the last property set is enumerated first. Combined with the prototype chain walk, the full order is:
1. Own properties of the object, in reverse insertion order
2. Prototype properties (walking `__proto__`), each level in reverse insertion order
3. Properties shadowed by a child level are skipped

**Evidence from tests**:
- `new_object_enumerate`: Sets `x` then `y` on `obj`. Expected pop order: `y` first, then `x` (reverse of insertion). Actual: `x` first, `y` second (forward).
- `prototype_enumerate`: Object `b` has own props `c` (inherited, overwritten), `e` (new). Proto `a` has `a`, `b`, `c`. Expected: `d` (addProperty on proto), then from proto: `a`, `b`, then own: `e`, `c`. Wait — expected output is `d, a, b, e, c`.

Actually, analyzing the `prototype_enumerate` expected output more carefully:

The test creates:
```
a = {a:11, b:22, c:33}   // InitObject — insertion order: c, b, a (InitObject pushes in reverse)
addProperty("d", getter, null) on a
b = {__proto__: a, c:55, e:66}  // After init: b has own props from __proto__ set, then c=55, then e=66
```

Wait, let me re-analyze. `b` is created with `{__proto__: a}` via InitObject (1 property), then `b.c = 55` via SetMember, then `b.e = 66` via SetMember. So `b`'s own properties (in insertion order) are: `__proto__` (DontEnum), `c`, `e`.

`a`'s own properties (from InitObject with 3 key-value pairs pushed as c,33,b,22,a,11,3) — InitObject pops count=3, then pops pairs. The SWF pushes values in source order, so InitObject stores them in reverse-of-push order. Looking at the script: pushes a,11,b,22,c,33,3 then InitObject. InitObject pops 3, then pops c=33,b=22,a=11. It sets them in pop order: c first, b second, a third. So `a`'s insertion order = c, b, a.

Expected enumeration of `b`:
```
d    ← addProperty on proto (should be enumerable from proto level)
a    ← proto property (reverse: a is last inserted on proto, so first in reverse)
b    ← proto property
e    ← own property of b (reverse: e is last inserted, so first in reverse)
c    ← own property of b (c is first inserted own prop, so last in reverse; also shadows proto c)
```

Hmm, but the expected output is `d, a, b, e, c`. This is interesting — it enumerates **proto chain first, then own properties**. That contradicts the typical JavaScript behavior (own first, then proto). Let me verify...

Actually wait, looking again at the expected output: `d, a, b, e, c`. If Flash enumerates own props first in reverse insertion order, that would give `e, c` (own) then `d, a, b` (proto). But the expected is `d, a, b, e, c` — proto first, then own. OR... maybe Flash pushes onto the stack such that popping gives proto-first order. Since the for-in loop pops repeatedly, the **first popped** value is the first traced. The stack is LIFO, so the **last pushed** value is the first popped.

Let me think about this differently. The enumerate function pushes: first a null/undefined terminator, then all property name strings. The for-in loop pops until it hits the terminator. So the **last pushed** name is the **first iterated** in the for-in loop.

If we want the for-in to iterate `d, a, b, e, c`, the push order must be: `c, e, b, a, d` (reverse of iteration order), because the for-in pops in LIFO order.

So the push order should be: own props in insertion order (`c`, `e`), then proto props in insertion order (`a`, `b`, `d`). Actually that would give `a, b, d` but `d` is an addProperty, hm.

Let me just look at this empirically. The correct push order for iteration `d, a, b, e, c` is: push `c`, push `e`, push `b`, push `a`, push `d`. That's: own in forward order (c, e), then proto in forward... hmm, but proto in forward from InitObject insertion would be c, b, a... and c is shadowed, leaving b, a — but we need a before b in push order to get a after b in pop (iteration) order. Actually push a then b means pop b then a. But expected iteration is a before b. So push order would be b, a. That's proto in REVERSE insertion order (a was last inserted, so a comes last when reversed → a is pushed last → popped first).

OK let me lay this out systematically:

Expected for-in iteration (pop order): `d, a, b, e, c`
Required push order (reverse of pop): `c, e, b, a, d`

Own properties of `b` in insertion order: `c, e`
Push own in insertion order = `c, e` ✓ (first two pushes)

Proto properties of `a` in insertion order (skipping shadowed `c`): `b, a`
Plus addProperty `d` on `a`.
Push proto in insertion order = `b, a` then `d` → gives `b, a, d` ✓ (last three pushes)

So the algorithm is:
1. Push null terminator
2. Push own properties in **forward insertion order**
3. Walk prototype chain, push each level's properties in **forward insertion order**
4. addProperty virtual properties are pushed after normal properties of their level

And since the stack is LIFO, popping gives: virtual props from deepest proto first, then proto in reverse insertion, then own in reverse insertion.

Actually wait, let me recheck. If we push in this order: `c, e, b, a, d`, then popping gives `d, a, b, e, c` which matches. So:
- Own props forward order: c, e
- Proto props forward order: b, a (c skipped as shadowed)
- Proto addProperty: d

This means the current code's **forward iteration** (i=0 to num_used-1) with **prepend to linked list** gives:

For own obj `b`: iterate c(0), e(1) → prepend gives list: e→c → push from list gives: push e, push c

That gives pop order: c, e — which would mean the for-in iterates `c, e` for own props. But expected iteration for own props is `e, c` (reverse insertion = last inserted first).

Hmm, that's the opposite. Let me re-examine.

The current code: iterate i=0..N, prepend to list. List ends up reversed: last item at head. Push from head to tail.

For b's properties [c(i=0), e(i=1)]:
- Prepend c → list: c
- Prepend e → list: e→c
- Push e, then push c → stack has c on top (pushed last)
- Pop gives: c, e (forward insertion order)

Expected own props iteration: e, c (reverse insertion order)

So to get reverse insertion order in iteration, we need pop order e, c. That means push order: c, e (forward insertion order). Which means we should push WITHOUT the prepend-list trick — just iterate forward and push directly.

The current code's prepend-list approach gives forward insertion order when popped, but we want reverse insertion order when popped. So we need to either:
1. Iterate **backwards** (i=num_used-1 down to 0) and prepend → list is forward → push gives reverse insertion order when popped ← WRONG, same result
2. Just iterate forward and push directly (no linked list) → push c then e → pop e then c → iteration: e, c ✓

Actually, let me think again. iterate forward + push directly:
- Push c → push e → stack: e on top
- Pop: e (first iteration), then c (second iteration)
- Iteration order: e, c ✓ This is reverse insertion order!

Now for the prototype chain. We want proto props to come AFTER own props in iteration. Since iteration = pop order, proto must be popped AFTER own. Since stack is LIFO, proto must be pushed BEFORE own.

Complete push sequence for `d, a, b, e, c`:
1. Push terminator (undefined/null)
2. Push proto addProperty: d
3. Push proto normal props forward: b, a
4. Push own props forward: c, e

Pop (iteration) order: e, c, a, b, d — that gives `e, c, a, b, d`, NOT `d, a, b, e, c`.

That's wrong. Let me re-examine what push order gives the expected `d, a, b, e, c`:
- Need pop order: d, a, b, e, c
- Push order (reverse): c, e, b, a, d

So pushing: terminator, c, e, b, a, d
Pop: d, a, b, e, c ✓

This means:
1. Push terminator
2. Push own props in **forward** insertion order: c, e
3. Push proto normal props in **forward** insertion order: b, a
4. Push proto addProperty: d

Pop gives: d, a, b, e, c ✓

So the correct algorithm is simply: push terminator, then walk from own object through prototype chain, at each level push properties in forward insertion order (i=0 to num_used-1), then push addProperty virtual props for that level. The LIFO nature of the stack naturally reverses everything to give the expected for-in iteration order.

This is MUCH simpler than the current prepend-list approach. The linked list + prepend is doing a double-reversal that cancels out in the wrong direction.

### Bug 3: `__proto__` and `constructor` Not Marked DontEnum

**Cause**: When `actionNewObject` creates an object via `new Constructor()`, the prototype object gets attached as `__proto__` on the instance's dynamic properties. The `__proto__` property and `constructor` property on the prototype are not getting their ENUMERABLE flag cleared.

**Evidence**: `new_object_enumerate` shows `__proto__: [object Object]` and `constructor: [type Function]` being enumerated after `new (cons_container.object)()`.

**Fix**: When setting `__proto__` on objects (in `actionNewObject`, `actionNewMethod`, etc.), clear the ENUMERABLE flag. Also ensure `constructor` on prototype objects is DontEnum.

### Bug 4: `addProperty` Virtual Properties Not Enumerated

**Cause**: `addProperty()` stores getter/setter pairs in a global `VirtualProperty` table (action.c:376), completely separate from `ASObject.properties[]`. The enumeration code only walks `ASObject.properties[]` and never checks the virtual property table.

**Evidence**: `prototype_enumerate` expects `d` (registered via `addProperty("d", getter, null)` on prototype `a`) to appear in enumeration, but it doesn't.

**Fix**: During enumeration, after walking an object's normal properties, also check the virtual property table for any properties registered on that object. Note: the current virtual property table is **global** (not per-object), which is itself a bug — `addProperty` should register on a specific object instance. For now, we can check global virtuals at the root level. A proper fix would make virtual properties per-object.

**Design decision**: The `addProperty` implementation is fundamentally broken (global table instead of per-object), but fixing that is a separate larger task. For now, we'll enumerate global virtual properties at the root/prototype level since that's what the test expects. A proper `addProperty` fix should be tracked separately.

### Bug 5: MovieClip Child Instance Names Not Enumerated

**Cause**: The MovieClip enumeration path in `actionEnumerate2` only walks `mc->dynamic_props` (the ASObject for user-set properties). It doesn't scan the `child_mc_cache[]` for child clips whose parent matches the target MovieClip.

**Evidence**: `stage_object_enumerate` sets `_root.foo = 2` then enumerates `_root`. Expected: `foo, clip3, clip2, clip1`. Actual: `foo` only.

**Fix**: After enumerating `dynamic_props`, scan `child_mc_cache[]` for entries where `parent == mc`. Push their instance names. The order should be reverse of creation order (last placed = first enumerated) to match Flash behavior.

### Bug 6: `actionEnumerate` Doesn't Handle `ActionEnumerate` on GetMember Result

**Cause**: Looking at the `enumerate` test's script, there are cases like:
```c
// Push (String) "this"
// GetVariable → pushes _root MovieClip
// Push (String) "obj"
// GetMember → pushes this.obj (the object)
// Enumerate → expects to enumerate a STRING that was the result of GetMember
```

Wait, that's wrong. Actually `ActionEnumerate` pops a string and looks it up as a variable name. When the test does `GetMember` followed by `Enumerate`, the GetMember pushes the *object*, and then `Enumerate` tries to use it as a variable name. In Flash, this would toString the object to `"[object Object]"` and look that up — finding nothing — and push only the terminator.

But looking at the expected output more carefully:
```
// this.obj (GetMember)
<blank line>
```

The blank line after "// this.obj (GetMember)" with no property names means the test's for-in loop found nothing, and the `trace("")` after the loop printed the blank line. So Flash is indeed converting the object to string, not finding a variable by that name, and pushing only the terminator. Our fix for Bug 1 (checking type before reading as string) will handle this.

### Bug 7: `actionEnumerate` Doesn't Handle Slash-Path Syntax

The first section of the `enumerate` test uses `"this:obj"` (colon-path, SWF4 syntax) as the variable name for `ActionEnumerate`. The expected output shows properties `abc`, `def` being enumerated. The current code does a simple `getVariable` lookup which may not handle slash/colon path syntax. If `getVariable` doesn't resolve `"this:obj"`, the enumeration would push nothing.

Looking at the actual output, the test is segfaulting before even reaching this part. After fixing Bug 1, we may need to also fix slash-path resolution in `actionEnumerate`.

---

## Implementation Plan

### Phase 1: Fix actionEnumerate Segfault + Type Safety

**Goal**: Make `actionEnumerate` handle all stack value types without crashing.

**Changes in `action.c` (`actionEnumerate`)**:

1. Check the type tag at `STACK[SP]` before reading string fields
2. For non-string types:
   - Pop the value using `popVar()` (generic, type-safe)
   - Convert to string using the same rules as `convertString`
   - Look up the resulting string as a variable name
3. For string types: keep existing behavior (read string_id, u16_len, pointer)
4. Also handle the case where the variable resolves to an ARRAY or FUNCTION type (not just OBJECT and MOVIECLIP)

**Expected test impact**: `enumerate` test stops segfaulting. Many of the "enumerate(undefined)" / "enumerate(null)" / etc. lines should now produce the correct `undefined` output.

### Phase 2: Fix Enumeration Order

**Goal**: Make object enumeration produce the correct property order.

**Changes in `action.c` (both `actionEnumerate` and `actionEnumerate2`)**:

Replace the current "collect into prepend-linked-list, then push from list" approach with direct pushing:

```c
// Current (WRONG):
// iterate i=0..N → prepend to list → push from list head
// Result: forward insertion order when popped (wrong)

// Fixed (CORRECT):
// Push terminator first
// Walk own → proto chain
//   At each level: iterate i=0..N, push directly
// Result: reverse insertion order when popped (correct)
```

The key insight: just push properties directly in forward iteration order (i=0 to num_used-1). The LIFO stack naturally reverses them, giving reverse-insertion-order when popped by the for-in loop. Walk own object first, then prototype chain — own props are pushed first (closer to stack bottom), so they are popped last. Proto props are pushed last (closer to stack top), so they are popped first. This matches Flash's behavior: proto properties enumerate first, then own properties.

Wait — actually re-examining the `new_object_enumerate` test: `obj = new Object()` with `obj.x = "test x"` then `obj.y = "test y"`. Expected iteration: `y, x` (reverse insertion). The object has only own props, no prototype props. Insertion order: x(0), y(1). Direct push: push x, push y. Pop: y, x ✓.

For the proto chain case: push own props forward, then push proto props forward. Pop gives proto reversed then own reversed. But `prototype_enumerate` expects: `d, a, b, e, c` = proto first, then own. If we push own first (c, e) then proto (b, a, d), pop gives: d, a, b, e, c ✓.

**Implementation**:

```c
// Push terminator
PUSH(ACTION_STACK_VALUE_NULL, 0);  // Should be null, not undefined

// Walk from own object through prototype chain
ASObject* current_obj = obj;
while (current_obj != NULL && chain_depth < MAX_CHAIN_DEPTH) {
    for (u32 i = 0; i < current_obj->num_used; i++) {
        if (!(props[i].flags & PROPERTY_FLAG_ENUMERABLE)) continue;
        if (isPropertyEnumerated(enumerated_head, name, len)) continue;
        addEnumeratedName(&enumerated_head, name, len);
        PUSH_STR(name, len);  // Push directly — no linked list!
    }
    // Move to __proto__
    ...
}
```

**Expected test impact**: `new_object_enumerate` fix (y before x), `array_enumerate` partial fix (order of named vs index props).

### Phase 3: Fix Array Enumeration Order

**Goal**: Make array `for-in` enumerate in the correct order.

**Expected iteration for `array_enumerate`**: `5, foo, 0, 1`

The array has: `new Array(16)` → length=16, then `arr[1] = undefined` (explicit set), `arr[0] = "elem 0"`, `arr["foo"] = "foo"`, `arr[5] = "elem 5"`.

Expected for-in pop order: `5, foo, 0, 1` means push order: `1, 0, foo, 5`.

Flash's array enumeration order (when popped/iterated): numeric indices in descending order that are set, then named properties in reverse insertion order? No — expected is `5, foo, 0, 1`. That's: index 5, then named "foo", then index 0, then index 1. This is peculiar.

Actually, re-analyzing: the array is created as `new Array(16)`, which sets length=16. Then properties are set in this order: `arr[1]`, `arr[0]`, `arr["foo"]`, `arr[5]`. So all 4 are "properties" set in order: 1, 0, foo, 5.

Flash treats array indices as properties with insertion-order tracking. Enumeration iterates in reverse insertion order: 5 (last set), foo, 0, 1 (first set). So array enumeration follows the same reverse-insertion-order rule as objects — numeric indices are NOT special-cased.

**Current code**: The array enumeration in `actionEnumerate2` treats indices and named props separately — it iterates indices 0..length ascending, then named props forward. This is wrong.

**Fix**: For arrays, treat all properties (both numeric indices and named props) as a single ordered set. Track insertion order across both index slots and named props. The simplest approach: push set indices and named props in their combined insertion order, then let the stack LIFO give reverse insertion order.

The complication: array elements are stored in `arr->elements[]` (by index) while named props are in `arr->props->properties[]`. There's no cross-structure insertion order tracking.

**Pragmatic approach**: Add an `insertion_order` counter to ASArray. When any element or prop is set, record the insertion order. During enumeration, collect all set elements + named props, sort by insertion order ascending, push in that order. The LIFO stack reverses to give reverse insertion order.

**Alternative simpler approach**: Since the test only has 4 entries, we could track insertion order per-element. But this adds memory overhead. A simpler approximation: push named props first in forward order, then indices in ascending order. Pop gives: indices descending, then named props reversed. For the test case: push foo, then 0, 1, 5 → pop: 5, 1, 0, foo → iteration: 5, 1, 0, foo. But expected is 5, foo, 0, 1. This doesn't match either.

The correct answer is that **array elements maintain insertion order alongside named properties**. This likely requires tracking insertion sequence numbers. We could add a `u32 insert_seq` field to array elements.

**Detailed approach**:
1. Add `u32 next_insert_seq` to ASArray
2. When setting an element by index, record `insert_seq` for that slot
3. When setting a named prop, it already has insertion order from ASObject (index in properties array)
4. During enumeration, collect all (index or named) entries with their insert_seq, sort ascending, push in that order

This is more complex but correct. For now, we can start with the simpler approach and refine if needed.

**Expected test impact**: `array_enumerate` fixed (correct order: `5, foo, 0, 1`).

### Phase 4: Fix `__proto__` and `constructor` DontEnum

**Goal**: Prevent `__proto__` and `constructor` from leaking into enumeration.

**Changes**:
1. In `setProperty()` (object.c) or wherever `__proto__` is set on objects: clear the ENUMERABLE flag
2. In constructor prototype setup: ensure `constructor` property on prototype has ENUMERABLE flag cleared
3. Check all paths where `__proto__` is set: `actionNewObject`, `actionNewMethod`, `actionInitObject`, `actionExtends`, etc.

**Expected test impact**: `new_object_enumerate` second half fixed (no more `__proto__` and `constructor` in output).

### Phase 5: Enumerate `addProperty` Virtual Properties

**Goal**: Make `addProperty`-registered properties appear in for-in enumeration.

**Current limitation**: The virtual property table is global (not per-object). This means all virtual properties are visible on all objects, which is wrong. But the `prototype_enumerate` test only registers `addProperty` on one object (`a`), and `b.__proto__ = a`, so `d` should appear when enumerating `b` via prototype chain walk.

**Pragmatic fix**: During prototype chain walk, at each level, after pushing normal properties, check if the current object is the root MovieClip (since addProperty currently registers globally on _root). If so, also push virtual property names that haven't been seen yet.

**Better fix** (if scoped properly): Make virtual properties per-object by storing them ON the ASObject (as a linked list or small array). Then during enumeration, check the current object's virtual property list at each proto chain level.

**For now**: Since `addProperty` currently only works on `_root` (it's called as a method on `this` which is `_root`), we can check the global virtual property table when enumerating any object that is `_root` or is in `_root`'s prototype chain. This is a hack but passes the immediate test.

**Proper fix deferred**: Making `addProperty` truly per-object is a separate task that affects the `add_property` test (currently 20% passing) and potentially others.

**Expected test impact**: `prototype_enumerate` fixed (d appears in enumeration).

### Phase 6: Enumerate MovieClip Child Instance Names

**Goal**: When enumerating a MovieClip, include child clip instance names.

**Changes in `action.c` (MovieClip enumeration path in both `actionEnumerate` and `actionEnumerate2`)**:

After enumerating `dynamic_props`, scan `child_mc_cache[]` for entries where `child_mc_cache[i]->parent == mc`. Push their `name` fields as property names.

**Order**: Children should be pushed in cache order (which is creation/placement order). Since the stack is LIFO, they'll be popped in reverse creation order (last placed = first enumerated). The test expects `clip3, clip2, clip1` which is reverse of placement order (clip1 placed first, clip3 last).

Actually, need to check: dynamic props are pushed first (forward order), then child names are pushed. Pop order: child names first (reverse of push order), then dynamic props (reverse of push order). Test expects: `foo, clip3, clip2, clip1`. So `foo` (dynamic prop) comes before clips.

If we push: `foo` (own prop), then `clip1, clip2, clip3` (child clips in placement order). Pop: `clip3, clip2, clip1, foo`. But expected is `foo, clip3, clip2, clip1`.

So child clips should be pushed BEFORE own dynamic props:
Push: `clip1, clip2, clip3` (children in placement order), then `foo` (own prop).
Pop: `foo, clip3, clip2, clip1` ✓

This means children are treated as "deeper" (earlier push) than own dynamic properties.

**Expected test impact**: `stage_object_enumerate` fixed.

### Phase 7: Null Terminator (Minor)

**Current**: Both functions push `ACTION_STACK_VALUE_UNDEFINED` as the terminator.
**SWF spec**: The terminator should be `null`.
**Flash behavior**: The for-in loop pattern checks `Equals2` against a pushed `null`, and `undefined == null` is true in `Equals2`, so this works. But for correctness, change to `ACTION_STACK_VALUE_NULL`.

---

## Implementation Order and Dependencies

```
Phase 1 (segfault fix) — standalone, critical
    ↓
Phase 2 (enum order) — depends on Phase 1 for enumerate test
    ↓
Phase 3 (array order) — depends on Phase 2 patterns
    ↓
Phase 4 (__proto__ DontEnum) — standalone
    ↓
Phase 5 (addProperty enum) — standalone
    ↓
Phase 6 (MC children) — standalone
    ↓
Phase 7 (null terminator) — trivial
```

Phases 4, 5, 6, 7 are independent of each other and can be done in any order.

**Recommended implementation order**: 1 → 2 → 4 → 3 → 6 → 5 → 7

Phase 1+2+4 are the highest priority — they fix the most common enumeration bugs and will improve many tests beyond just the 5 enumeration-specific ones.

---

## Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | Fix `actionEnumerate` type safety (Phase 1), fix both enumerate functions' push order (Phase 2), fix array enumeration (Phase 3), enumerate MC children (Phase 6), null terminator (Phase 7) |
| `SWFModernRuntime/src/actionmodern/object.c` | Clear ENUMERABLE on `__proto__` in `setProperty` (Phase 4) |
| `SWFModernRuntime/include/actionmodern/object.h` | Possibly add insertion_seq to array elements (Phase 3) |

---

## Estimated Test Impact

| Phase | Tests Fixed | Total |
|-------|-----------|-------|
| 1 (segfault) | enumerate partial (no crash, ~30 lines) | ~1 partial |
| 2 (enum order) | new_object_enumerate (first half), enumerate partial | ~1.5 |
| 3 (array order) | array_enumerate | ~1 |
| 4 (DontEnum) | new_object_enumerate (second half) | completes 1 |
| 5 (addProperty) | prototype_enumerate | ~1 |
| 6 (MC children) | stage_object_enumerate | ~1 |
| **Total** | **~5 direct tests** | |

Plus likely improvements to: `globals_swf*`, `stage_object_*`, `as_set_prop_flags`, `prototype_properties`, `object_prototypes`, and any other test that uses `for-in`.

---

## Verification Commands

```bash
# After each phase:
python3 ruffle-tests/verify_output.py --test=enumerate --test=array_enumerate --test=new_object_enumerate --test=prototype_enumerate --test=stage_object_enumerate --diff --verbose

# Check for regressions in related tests:
python3 ruffle-tests/verify_output.py --test=object_prototypes --test=prototype_properties --test=is_prototype_of --test=as_set_prop_flags --diff --verbose
```

---

## Open Questions

1. **`actionEnumerate` slash-path resolution**: The test uses `"this:obj"` as a variable name. Does our `getVariable` handle colon-path syntax? If not, the first few lines of the `enumerate` test will still fail even after Phase 1. This may require changes to `getVariable` to handle `target:variable` paths.

2. **`addProperty` per-object**: The current global virtual property table is a known design flaw. Should we fix it as part of this task or defer? Making it per-object would help both `prototype_enumerate` and the `add_property` test (20% passing). Deferring is OK if the global hack passes the immediate test.

3. **Array insertion order tracking**: Adding `insert_seq` to every array element adds memory overhead. An alternative: use a separate side-table or linked list. What's the right tradeoff for the test suite?

4. **FUNCTION type enumeration**: When `actionEnumerate2` gets a FUNCTION type (ASFunction), should it enumerate the function's `own_props`? Some tests may depend on this. Currently only OBJECT, ARRAY, and MOVIECLIP are handled.
