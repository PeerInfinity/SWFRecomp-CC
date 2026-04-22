# ASSetPropFlags READONLY in WITH Assignment Plan
<!-- TESTS: with-v6, with-v7, with-v8 (secondary blocker alongside SETTARGET_OBJECT_PATH_PLAN) -->

Last updated: 2026-04-21
Status: COMPLETE — both fixes landed. Lines 531 ("nooverride ==
\"nooverride\"") and 539 ("mc.nooverride == 'nooverride'") now match
expected on with-v6/v7/v8. Tests remain `output_mismatch` (not
`ruffle_matched`) because the remaining ~12 diffs come from
`SETTARGET_OBJECT_PATH_PLAN.md` (target-path resolution, child MC
lookup, etc.). Once that sibling plan lands, with-v6/v7/v8 should
reach `ruffle_matched`.

## Landed changes

- **Fix A** — `actionASSetPropFlags_func2` (action.c:4225) now unwraps
  `ACTION_STACK_VALUE_MOVIECLIP` to `mc->dynamic_props`, lazy-allocating
  an 8-slot ASObject if dynamic_props was NULL.
- **Fix B** — WITH-scope branch of `actionSetVariable` now checks
  `prop_struct->flags & PROPERTY_FLAG_WRITABLE` before calling
  `setProperty`. When clear, the assignment is silently dropped and the
  stack is popped. Gated on `scope_is_with[i]` to match the plan's
  narrow scope; non-WITH scope paths are unchanged.

Local verification: with-v6/v7/v8 each `#passed 87 → 89`, `#failed 14 → 12`.
Spot-checked regression set (avm1 with/with_return/with_variable_scopes/
enumerate/global_is_bare/mutable_this/this_scoping/as_set_prop_flags[\_version[\_swf5-9]]/
define_local[\_with_paths]/prototype_delete/prototype_enumerate/
prototype_properties/set_variable_scope/on_construct/
register_and_init_order/mcl_events_swf_version + Gnash Inheritance-v5..v8/
case-v5/Try-v6/delete-v5..v8/enumerate-v6..v8) — no regressions.

---

## Problem

Two independent bugs combine to miss the `nooverride` assertions in
with-v6/v7/v8:

### Bug A — ASSetPropFlags ignores MOVIECLIP arg

`actionASSetPropFlags_func2` in `SWFModernRuntime/src/actionmodern/action.c:4225`
only accepts `ACTION_STACK_VALUE_OBJECT` or `ACTION_STACK_VALUE_FUNCTION`
for its first arg:

```c
ASObject* obj = NULL;
if (args[0].type == ACTION_STACK_VALUE_OBJECT)
    obj = (ASObject*)(u64)args[0].data.numeric_value;
else if (args[0].type == ACTION_STACK_VALUE_FUNCTION) { ... }
if (obj == NULL) return result;
```

When the test calls `ASSetPropFlags(mc, "nooverride", 4, 1)` (with.as:519),
`args[0].type == ACTION_STACK_VALUE_MOVIECLIP`, so `obj` stays NULL and
the function returns without doing anything. The `"nooverride"` property
on `mc` never gets its `PROPERTY_FLAG_WRITABLE` bit cleared.

### Bug B — WITH-scope assignment doesn't check WRITABLE

Even if Bug A were fixed, the assignment
`nooverride = "nooverrideUpdated"` inside `with(mc) { ... }` would still
mutate the property. `actionSetVariable`'s WITH-scope branch
(action.c:32817-32851) finds the existing property via
`findPropertyStructWithPrototype` and unconditionally calls
`setProperty` — it does **not** consult `prop_struct->flags &
PROPERTY_FLAG_WRITABLE`. Flash silently rejects writes to non-writable
properties.

## Tests affected

Primary: `with-v6`, `with-v7`, `with-v8` — 2 diff lines each:

| with.as line | Assertion | Our output | Expected / Ruffle |
|--------------|-----------|-----------|-------------------|
| 531 | `check_equals(nooverride, "nooverride")` | FAILED obtained `nooverrideUpdated` | PASSED |
| 539 | `check_equals(mc.nooverride, 'nooverride')` | FAILED obtained `nooverrideUpdated` | PASSED |

Both tests are `known_failure = true` in Ruffle. Our diffs against
`output.txt` must be a subset of Ruffle's diffs to earn `ruffle_matched`
— Ruffle matches expected on both lines, so we must too.

**Probable collateral beneficiaries** (SCAN, not confirmed):
- Any Gnash test that calls `ASSetPropFlags(movieClip, ...)` — grep
  `actionscript.all` and `misc-*` for `ASSetPropFlags\(\s*\w+\s*,` and
  check whether the first arg is a MC.
- `enumerate*` tests around MC enumeration with DONTENUM bits set.

## Approach

### Fix A — extend ASSetPropFlags to unwrap MOVIECLIP

In `actionASSetPropFlags_func2` (action.c:4230), add a branch:

```c
else if (args[0].type == ACTION_STACK_VALUE_MOVIECLIP) {
    MovieClip* mc = (MovieClip*)(u64)args[0].data.numeric_value;
    if (mc != NULL) {
        // Lazy-allocate dynamic_props if the MC doesn't have any yet
        if (mc->dynamic_props == NULL)
            mc->dynamic_props = (void*)allocObject(app_context, 8);
        obj = (ASObject*)mc->dynamic_props;
    }
}
```

Tradeoff: lazy allocation means a no-op `ASSetPropFlags(mc, null, 0, 0)`
still materialises dynamic_props. That's fine — the MC would grow one as
soon as a property is set on it, and the empty object has no observable
side effect.

### Fix B — honour WRITABLE in WITH-scope SetVariable

In `actionSetVariable` (action.c:32817-32851), before
`setProperty(app_context, scope_chain[i], var_name, var_name_len, &value_var)`
at line 32843, check:

```c
if (!(prop_struct->flags & PROPERTY_FLAG_WRITABLE)) {
    // Non-writable — silently drop the assignment.
    POP_2();
    return;
}
```

Apply to the WITH-scope branch only; the non-WITH branch at the same
site already handles scope chain differently.

**Secondary location:** `actionSetVariable` also has a tellTarget path
at action.c:32867+ that writes to `g_current_context->dynamic_props`.
Mirror the WRITABLE check there too if grep finds the assignment bypasses
flags (verify before implementing).

**Also check:** `actionSetMember` / `setProperty` direct-object writes
(for `mc.nooverride = ...`). The with.as:539 assertion reads
`mc.nooverride` from outside the WITH block, so it passes as long as Fix
A + B keep the stored value at `"nooverride"`. No additional setMember
change is expected.

## Phases

### Phase 1 — Fix A alone, verify no change in behaviour

After Fix A, `ASSetPropFlags(mc, "nooverride", 4, 1)` clears the WRITABLE
bit on `mc.dynamic_props.nooverride`. The test still fails because Bug B
ignores the bit. But no regressions should surface yet, and enumerate
tests that touch MC DONTENUM bits may incidentally improve.

### Phase 2 — Fix B

Add the WRITABLE check in actionSetVariable's WITH-scope branch.

### Phase 3 — Verify

1. Local: `verify_output.py --test=with-v6 --diff --verbose` should show
   lines 531 and 539 both pass.
2. Check no regression on avm1 `setpropflags_*`, `enumerate_*`,
   `this_scoping`, `mutable_this`, `with_*`.
3. Combined with `SETTARGET_OBJECT_PATH_PLAN.md`, with-v6/v7/v8 should
   reach `ruffle_matched`.

## Implementation Notes

- The `PROPERTY_FLAG_WRITABLE` bit is defined in
  `SWFModernRuntime/include/actionmodern/object.h:26` as `0x02`.
  `findPropertyStructWithPrototype` returns an `ASProperty*` whose
  `flags` field exposes it.
- `allocObject(app_context, initial_cap)` is how other MC sites
  lazy-create `dynamic_props`. Use capacity 8 to match
  action.c:32872 precedent.
- Do NOT pop the stack in advance of the WRITABLE check. Keep the
  existing `peekVar` + `POP_2()` flow; the no-op branch just replaces
  the `setProperty` call.
- Flash also distinguishes "property doesn't exist" from "property
  exists but non-writable". We only care about the latter for this
  fix — the existing `existing != NULL` guard already scopes us to that
  case.

## Success Criteria

- with-v6/v7/v8 lines 531 and 539 match expected output.
- No regressions on any currently-passing test (avm1, Gnash, Shumway).
- Combined with `SETTARGET_OBJECT_PATH_PLAN.md`, with-v6/v7/v8 reach
  `ruffle_matched` status.

## Risk / Effort Estimate

- Low complexity — two narrow surgical edits in well-trodden code.
- Effort: ~half a day including local verification + CI run.
- Risk: the WRITABLE check may interact with edge cases where we
  erroneously marked properties non-writable. Mitigated by spot-checking
  a handful of avm1 tests that touch ASSetPropFlags before the WITH code
  change lands.

## Related

- `blocked/WITH_AUTOBOXING_PLAN.md` — shelved predecessor; identified
  this as a secondary blocker.
- `SETTARGET_OBJECT_PATH_PLAN.md` — primary sibling plan for with-v6/v7/v8.
  Both likely need to land to get `ruffle_matched`.
- `ACCEPTED_DIFFS.md` — not applicable; these are genuinely fixable
  failures, not accepted diffs.
