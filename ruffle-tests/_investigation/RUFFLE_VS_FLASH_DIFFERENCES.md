# Ruffle vs Flash Spec Differences

Tests where the Ruffle expected output appears to match Ruffle's own implementation rather than Flash Player's actual behavior. These are cases where we match Flash's spec/behavior but fail the Ruffle test.

## For-In Enumeration Order

**Test:** `xml_attributes_read`

Flash Player enumerates object properties in **reverse insertion order** (last-inserted property iterated first). This is because for-in pushes properties onto the stack in forward order and the LIFO stack reverses them.

Ruffle's expected output for XML attribute enumeration shows **forward insertion order** (first attribute iterated first: `attrx` before `attry`). Our implementation correctly produces reverse insertion order matching Flash, but this doesn't match the Ruffle test expectation.

Reversing attribute storage order to match Ruffle's expectation breaks `xml_namespaces` (203/203 → 197/203) because namespace resolution walks attributes and depends on storage order.

**Decision:** Keep Flash-correct reverse insertion order. Accept `xml_attributes_read` as a known Ruffle difference.

## Sprite Frame 0 Child Visibility

**Test:** `stage_object_enumerate`

In Flash Player, when a sprite is placed via PlaceObject2, its frame 0 **placement tags** (PlaceObject2, SetInstanceName) execute immediately, but frame 0 **scripts** (DoAction) are deferred to ShowFrame. This means child display objects exist and can be enumerated by parent scripts, but child scripts don't run until ShowFrame.

Our recompiler emits sprite frame functions as single C functions mixing both placement tags and scripts. There's no `if (!catch_up_mode)` guard on sprite-level scripts (only root frame scripts have the guard), so we can't selectively execute placement-only. Eager execution breaks `execution_order1`, `execution_order2`, `variable_args`, and `define_function2_preload_order`.

**Decision:** Keep deferred sprite init (correct execution order for 4+ tests). Accept `stage_object_enumerate` as needing a recompiler-side fix to add `catch_up_mode` guards to sprite frame scripts.

**Note:** This is not strictly a Ruffle difference — it's a limitation of our recompiler's code generation that prevents us from matching Flash's split placement/script behavior.

## SWF6 `new TextField()` Returns Object, Not Undefined

**Test:** `native_objects_swf6`

In Flash Player, `new TextField()` returns a valid object in SWF6 (and all other versions). Our fully-passing `textfield_props_swf6` test (all lines match) confirms this — it creates `new TextField()` and exercises its properties as an object.

Ruffle's `native_objects_swf6` test expects `new TextField(): non-object: undefined`, suggesting Ruffle's SWF6 implementation returns `undefined` for `new TextField()`. The test is also marked `known_failure = true` in its own `test.toml`, confirming Ruffle knows this expectation is questionable.

```diff
- new TextField(): non-object: undefined
+ new TextField(): native
```

**Decision:** Keep Flash-correct behavior (`new TextField()` returns an object in SWF6). Accept the 1-line diff as a Ruffle implementation difference.
