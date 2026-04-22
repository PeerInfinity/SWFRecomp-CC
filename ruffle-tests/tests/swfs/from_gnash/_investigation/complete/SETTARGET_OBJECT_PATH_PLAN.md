# SetTarget Object Path Resolution Plan
<!-- TESTS: with-v6, with-v7, with-v8 (primary). Candidates for collateral impact: tell_target_*, setproperty -->

Last updated: 2026-04-21
Status: COMPLETE (pending CI confirmation) — with-v6/v7/v8 reach `ruffle_matched` locally.

**Implementation (2026-04-21):** Added `resolveObjectPathToMC` in
`SWFModernRuntime/src/actionmodern/action.c` (right after `resolveFlashPathToMC`).
It walks the path segment-by-segment on the operand stack: for MOVIECLIP
values it uses `resolveSlashPathToMC` for display-list children first, then
falls back to `actionGetMember` (which already handles MC builtins,
`dynamic_props`, `MovieClip.prototype` chain, and root-MC `var_map` lookup).
For `OBJECT`/`FUNCTION`/`ARRAY` values it uses `actionGetMember`
(prototype-chain aware). `_root`/`_level0`/`_parent`/`this`/`..` are handled
as keyword segments. Result must be a `MOVIECLIP` at the end or the
resolver returns `NULL`.

`actionSetTarget` now falls back to this helper after `resolveFlashPathToMC`
fails, only when the target contains at least one of `.`, `:`, or `/`.
Legacy bare-name resolution still runs afterward, so plain target names are
unchanged.

**Local results (pre-CI):**
- with-v5/v6/v7/v8 → all `ruffle_matched` (with-v5 was already matched).
- Regression checks: avm1 `tell_target`, `tell_target_invalid`,
  `tell_target_invalid_swf6`, `path_string`, `target_clip_removed`,
  `target_clip_swf5`, `target_clip_swf6`, `target_path`, `string_paths_basic`,
  `string_paths_eval`, `string_paths_eval2`, `string_paths_hidden`,
  `removed_target_clip_scope`, `root_global_parent`,
  `get_variable_in_scope`, `set_variable_scope`, `with_return`,
  `with_variable_scopes`, `define_local_with_paths` all still PASS.

---

## Problem

`actionSetTarget(path)` in our runtime (`SWFModernRuntime/src/actionmodern/action.c:44603`)
only resolves `path` through MovieClip parent/child relationships via
`resolveFlashPathToMC` and `resolveSlashPathToMC`. When a segment of the
path isn't a named MovieClip child but *is* a property on the current
timeline or an enclosing object that *holds* a MovieClip reference, our
code bails out and emits a `Target not found: ...` trace line, then sets
`target_clip = None`.

Flash (and Ruffle) additionally do **ordinary property lookup** per
segment — if no display child is found, they call `object.get(name)` on
the current object. That is what lets paths like `'o.t'` resolve to the
MovieClip referenced by object-literal `o.t`.

Reference: Ruffle `core/src/avm1/activation.rs:2513` (`resolve_target_path`).

```rust
// per segment: try display list child first, then fall back to object.get
if let Some(child) = object
    .as_display_object()
    .and_then(|o| o.as_container())
    .and_then(|o| o.child_by_name(name, case_sensitive))
{
    child.object1()
        .or_else(|| child.parent().and_then(|p| p.object1()))
        .map_or(Value::Undefined, Value::from)
} else {
    let name = AvmString::new(self.gc(), name);
    object.get(name, self).unwrap()
}
```

At the end of resolution, Ruffle's `set_target` filters:

```rust
.and_then(|o| o.as_display_object())   // only accept MCs
```

and emits `Target not found: Target="..." Base="..."` otherwise
(`activation.rs:3007`).

## Tests affected

Primary: `with-v6`, `with-v7`, `with-v8` (all `known_failure = true` in
Ruffle; reaching `ruffle_matched` requires matching Ruffle's diff set
against `output.txt`).

Paths the test (`gnash/testsuite/actionscript.all/with.as:353-395`)
exercises:

| Call at with.as line | Path | Ours today | Ruffle (and Flash) |
|----------------------|------|-----------|--------------------|
| 354 | `o.t` (`o.t = _root.clip1`) | Target not found | resolves to clip1 |
| 358 | `o:t` | Target not found | resolves to clip1 |
| 362 | `../o:t` | Target not found | Target not found (expected) |
| 368 | `o2.o` (Object, not MC) | Target not found | Target not found (expected) |
| 372 | `o2.o.t` | Target not found | resolves to clip1 |
| 377 | `o2.o.p.t` (missing `.p`) | Target not found | Target not found (expected) |
| 382 | `o2.inh.t` (via `__proto__`) | Target not found | resolves to clip1 |
| 394 | `o:t` inside `with(o2)` | Target not found | resolves to clip1 |

So 6 of the 8 paths should succeed; we currently fail all 8.

**Diff-line impact per test:** ~14 lines each (6 stray `Target not found:`
trace lines + 8 `FAILED: _target == ...` assertions). Fixing this alone is
likely enough to push with-v6/v7/v8 to `ruffle_matched` (combined with
Plan B if a separate `nooverride` assertion still fails — see
`ASSETPROPFLAGS_WITH_READONLY_PLAN.md`).

Potential collateral tests (SCAN, not confirmed): any Gnash test that
passes an object-path string to setTarget or tellTarget. Grep
`actionscript.all` and `misc-*` for `setTarget\(['"][a-zA-Z_]` and
`tellTarget\(['"][a-zA-Z_]` to enumerate — several setproperty/tell_target
tests may share this code path.

## Approach

Add a new resolver, e.g. `resolveObjectPathToMC`, that mirrors the
per-segment loop in `resolveFlashPathToMC` but tracks an `ActionVar` (or
generic object pointer) at each step instead of a `MovieClip*`. At each
segment:

1. If current object is a MovieClip and has a named child, return the
   child's MovieClip.
2. Otherwise, look up the property name on the current object (with
   prototype-chain traversal — Ruffle uses `object.get` which walks the
   chain; that's what makes `o2.inh.t` work via `o2.__proto__.inh`).
3. Convert the result to an object or MovieClip value for the next hop.
4. If any segment resolves to `undefined`/`null`/primitive → return
   NULL (Target not found).

At the end, if the final value is a `ACTION_STACK_VALUE_MOVIECLIP`, that
becomes `target_clip`. If it's any other type (Object, primitive,
undefined), treat as Target not found.

### Reuse vs. replace

Keep `resolveFlashPathToMC` for the hot path (timeline-only paths like
`/clip1/clip2`). `actionSetTarget` would try it first (cheap, no property
scans), then fall back to `resolveObjectPathToMC` if that returns NULL.
The new resolver is only reached for paths containing `.` or `:` that
weren't a pure timeline path.

### Delimiter handling

Path delimiters for setTarget are `/`, `.`, `:`. The existing
`resolveFlashPathToMC` already has the tokenizer logic (action.c:17111).
Port that tokenizer into the new resolver unchanged.

### `_parent`, `_root`, `this`, `..`

Same semantics as `resolveFlashPathToMC`: `this` and `_root` only valid
as first element; `_parent` and `..` navigate the MovieClip tree. When
the current value is not a MovieClip, `_parent`/`..` should fail —
matches Ruffle (`o.as_display_object().and_then(|o| o.avm1_parent())`
returns None for non-MC).

### Case sensitivity

Ruffle branches on `self.is_case_sensitive()` (SWF version gate —
case-insensitive ≤ SWF6, case-sensitive SWF7+). Our existing path
resolvers already follow the same rule via `strcasecmp`/`strcmp`; reuse
that convention.

## Phases

### Phase 1 — Add `resolveObjectPathToMC` helper

New static helper in `action.c` near `resolveFlashPathToMC` (line ~17059).
Signature:

```c
// Returns MC* on success, NULL if any segment fails or final value isn't a MC.
// start_mc is the base clip; the resolver begins with its object1 (dynamic_props
// for non-root, or global_object/var_array for root).
static MovieClip* resolveObjectPathToMC(
    SWFAppContext* app_context,
    const char* path, u32 path_len,
    MovieClip* start_mc,
    int first_element);
```

Internal state per iteration: one of
- `MovieClip* mc` (when the current node is a MC), or
- `ActionVar cur_val` (when the current node is a plain Object/Function).

Each iteration:
- If `cur_val` is a MC and segment name matches a timeline child →
  advance to the child MC.
- Else, find `segment_name` as a property on the current node (MC's
  dynamic_props, or the Object/Function). Use `getPropertyWithPrototype`
  for prototype-chain walking (mirrors Ruffle `object.get`).
- If property value is UNDEFINED/NULL → return NULL.
- If property value is MOVIECLIP → switch mode to MC.
- If property value is OBJECT/FUNCTION/ARRAY → switch mode to Object.
- Otherwise (primitive) → return NULL.

### Phase 2 — Wire into `actionSetTarget` and `actionSetTarget2`

In `actionSetTarget` (action.c:44603), after the existing
`resolveFlashPathToMC` attempt fails, call `resolveObjectPathToMC`.
Only emit the `Target not found` trace line when both resolvers fail.

Apply the same fallback chain to `actionSetTarget2` (currently
delegates to `actionSetTarget` at action.c:33783; no change needed there
since the fallback lives inside `actionSetTarget`).

### Phase 3 — Expand test coverage

1. Confirm with-v6/v7/v8 reach `ruffle_matched` locally.
2. Verify no regression on:
   - avm1 `tell_target_invalid`, `tell_target_invalid_swf6`
   - avm1 `setproperty_*` if any use object paths
   - Any Gnash misc-* test running `setTarget(<object expr>)`
3. Watch for over-eager resolution: a path that *used* to fail with
   "Target not found" but shouldn't now succeed. The end-of-path
   `as_display_object`-style filter is what prevents that.

## Implementation Notes

- Property lookup on a MovieClip's "object1" in Ruffle = its dynamic
  properties + StageObject builtins + inherited prototype. Our analogue:
  look at `mc->dynamic_props` (ASObject), then `getPropertyWithPrototype`
  to walk through `MovieClip.prototype`.
- For the *root* clip, Ruffle uses `object1_or_bare` which for the root
  returns `avm1_level0.object1()`. Equivalent for us: the root's
  `dynamic_props` (so global variables like `o` set at timeline level are
  visible).
- If property lookup is case-insensitive (SWF ≤ 6), use `strcasecmp`
  against ASObject property names. Note `getPropertyWithPrototype` in
  `action.c` already supports this (verify).
- Keep `start_mc` as the base clip; `first_element=0` when called from
  setTarget (matching `resolveFlashPathToMC(…, 0)`).

## Success Criteria

- with-v6, with-v7, with-v8 reach `ruffle_matched` status (our diffs
  against `output.txt` ⊆ Ruffle's diffs against `output.txt`).
- No regression on any currently-passing avm1 or Gnash test.
- `Target not found:` trace lines match Ruffle's set exactly (only
  `../o:t`, `o2.o`, `o2.o.p.t` for with-v6/v7/v8).

## Risk / Effort Estimate

- Medium complexity — the tokenizer logic is already proven; the new
  resolver just swaps its "advance" step from MC-only to "MC or
  property".
- Effort: ~2 days including local test runs + CI verification.
- Risk areas:
  - `getPropertyWithPrototype` behaviour on MC's dynamic_props — confirm
    it doesn't accidentally trigger addProperty getters during resolution.
  - Regressions in the hot path (timeline-only setTarget) — mitigated by
    keeping `resolveFlashPathToMC` as the first attempt.

## Related

- `complete/RUFFLE_KNOWN_FAILURE_HANDLING_PLAN.md` — explains how
  `ruffle_matched` status is computed.
- `complete/DEJAGNU_FRAMEWORK_PLAN.md` — setTarget redirect pattern used
  by these tests to keep check() callable.
- `blocked/WITH_AUTOBOXING_PLAN.md` — shelved predecessor; identified
  this plan as the dominant remaining blocker for with-v6/v7/v8.
- `ASSETPROPFLAGS_WITH_READONLY_PLAN.md` — secondary with-v6/v7/v8
  blocker (2 lines per test); may need to land alongside this one to
  reach `ruffle_matched`.
