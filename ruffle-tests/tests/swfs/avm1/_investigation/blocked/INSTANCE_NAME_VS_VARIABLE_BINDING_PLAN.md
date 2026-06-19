<!-- TESTS: sound_setters -->

<!-- PLAN_META
id: INSTANCE_NAME_VS_VARIABLE_BINDING
status: blocked
phases:
  - id: 1
    name: "Stop createEmptyMovieClip/attachMovie/duplicateMovieClip from auto-registering instance names in var_map"
    status: planned
  - id: 2
    name: "Stop the _name setter from clobbering var_map; delete (not undef) the moved dynamic_props key"
    status: planned
  - id: 3
    name: "Full-suite CI validation across avm1 + gnash + shumway"
    status: planned
dependencies: []
blockers:
  - blocker: 10
    reason: "Architectural change to instance-name vs variable binding; cannot be validated locally (multi-suite, full-suite). Must run behind full CI."
-->

# Instance-Name vs `var x=` Variable Binding Plan

## Status: BLOCKED — needs full-suite CI to land safely

Resolves **Blocker 10** (`BLOCKER_SUMMARY.md`). Diagnosed 2026-06-19 while
working `avm1/sound_setters`.

## Problem

In Flash there are **two independent bindings** for a script-created clip:

1. **Display-list child** — looked up by the clip's *current* instance name. It
   **moves** when you do `mc._name = "newname"` (old name no longer resolves, new
   name does).
2. **Timeline variable** — created by an explicit `var mc = ...` assignment. It
   holds a reference and is **untouched** by a rename.

Our runtime **conflates the two**. `createEmptyMovieClip` (and `attachMovie` /
`duplicateMovieClip`) register the clip under its instance name in **both**
`parent->dynamic_props[name]` **and** the global `var_map[name]`. The `_name`
setter then clobbers **both** old-name entries to `undefined` on rename. So a
rename destroys any user `var` that happens to share the instance name.

### Failing test: `avm1/sound_setters`

```as
var mc = createEmptyMovieClip("mc", 1);   // var name == instance name
var s1 = new Sound(mc);                    // captures path "_level0.mc"
... setVolume/setPan/setTransform ...
traceProps();                              // block 1: OK (50/90/...)

mc._name = "changed";                      // (a) clobbers var_map["mc"]=undef
s1.setVolume(10); s1.setPan(75); ...       // (b) owner re-resolve of "_level0.mc" fails
mc._name = "mc";                           // (c) NO-OP: `mc` is now undefined
traceProps();                              // block 2: expected 10/50/..., we get undefined

var mcr = createEmptyMovieClip("mc2", 2);  // var name "mcr" != instance name "mc2"
s1 = new Sound(mcr);                        // captures path "_level0.mc2"
... rename round-trip on mc2 ...
traceProps();                              // block 4: expected 50/90/... (sets must NOT persist)
```

The control case (`mc2`, var name ≠ instance name) is the key: Flash expects the
rename-period mutations on `mc2` **not** to persist, because there is no variable
`mc2` — only the display-list child that moved away during the rename. So a
correct fix must reproduce this asymmetry:

| Clip | var name | After rename to "changed", does `_level0.<inst>` resolve? | Expected block |
|------|----------|-----------------------------------------------------------|----------------|
| `mc`  | `mc` (== inst)   | **yes** — via the surviving `var mc` | 10/50/rl80 |
| `mc2` | `mcr` (≠ inst)   | **no** — child moved, no var named `mc2` | 50/90/rl40 |

This was confirmed experimentally: temporarily skipping the two clobbers makes
`mc` resolve correctly (block 2 → 10/50/...), but breaks `mc2` (block 4 → 10/50/
instead of 50/90/), because `createEmptyMovieClip` had *also* left a stale
`var_map["mc2"]`/`dynamic_props["mc2"]` that then resolved during the rename
window. Confirms that the clobber alone is not the bug — the **var_map
auto-registration** of instance names is.

## Why this is blocked, not just unfixed

The clobber is **load-bearing** for currently-`ruffle_matched` tests:

- `from_gnash/misc-swfc.all/soft_reference_test1` — expects
  `typeof(oldname) == 'undefined'` after a rename (sc:107-147).
- gnash `case-v6` — case-insensitive SWF6 name-table collision protection
  (`case.as:96-170`).
- gnash `MovieClip-v6/v7/v8` soft-reference suite.

None of these can be validated locally (multi-suite, full-suite runs are
CI-only). The fix must land behind a full CI pass.

## Relevant code

| Concern | Location (`SWFModernRuntime/src/actionmodern/`) |
|---------|--------------------------------------------------|
| `createEmptyMovieClip` registration (dynamic_props + var_map) | `action.c` ~66450-66516 |
| `attachMovie` / `duplicateMovieClip` registration | search same pattern near their handlers |
| `_name` setter clobber (dynamic_props old→undef, var_map old→undef) | `action.c` ~47346-47393 |
| Bare-name resolution order | `actionGetVariable`, `action.c` ~39920-40045 |
| Sound owner re-resolution | `resolveSoundOwner`, `action.c` ~1439 |

**Key fact that makes the fix viable:** `actionGetVariable`'s bare-name path
already resolves a clip via (1) `g_current_context->dynamic_props`, then (2)
child-by-name (`resolveSlashPathToMC`, "Flash resolves child names as
variables"), and only *then* (3) `var_map`. So a clip that is registered **only**
in `dynamic_props` is still reachable as a bare variable — the `var_map`
auto-registration is redundant for read access.

## Recommended approach (Approach 1): de-conflate the two binding stores

Make `var_map` hold **only genuine user variables**, and `dynamic_props` hold the
**display-list-child** binding. The rename then moves only the child binding.

### Phase 1 — Stop instance-name auto-registration in `var_map`

In `createEmptyMovieClip` (and `attachMovie`, `duplicateMovieClip`), keep the
`dynamic_props[inst_name]` registration but **remove** the
`setVariableByName(inst_name, ...)` calls (the `_mcemc_has_gvar` block and its
non-root `else`). Bare-name and `_root.<name>` access continue to work via the
`dynamic_props`/child-by-name paths already present in `actionGetVariable` and
`actionGetMember`.

Risk: any read path that consults `var_map` **without** falling back to
`dynamic_props`/children. Audit `getVariable` callers and the slash/colon
resolution branches (`action.c` ~39600-39660 do check `var_map` first for
`clip:var`, then fall through — verify the fallback covers child names).

### Phase 2 — Fix the `_name` setter

With Phase 1, `var_map` no longer contains instance names, so:

- **Remove** the `var_map` clobber entirely (the `setGlobalVariableByName(old_key,
  &undef)` / `setGlobalVariableByName(new_key, ...)` block). A genuine user `var
  mc` must survive the rename untouched.
- For `dynamic_props`, **delete** the old-name key instead of setting it to
  `undefined` (`removeProperty` rather than `setProperty(..., &undef)`), and set
  the new-name key. Setting it to `undefined` makes it *shadow* a same-named user
  `var` in the later resolution order; deleting lets resolution fall through to
  `var_map` (the surviving user variable). This is what produces the `mc` vs
  `mc2` asymmetry:
  - `mc`: child key `mc` deleted from dynamic_props → bare/`_level0.mc` falls
    through to `var_map["mc"]` (the user var) → resolves. ✓
  - `mc2`: child key `mc2` deleted → no `var_map["mc2"]` → undefined. ✓

### Phase 3 — Validate via CI

Run the full pipeline (`no-graphics` is sufficient — pure runtime/AVM1 logic, no
renderer paths). Required green / no-regression set:

- `avm1/sound_setters` → **PASS** (target).
- `from_gnash/misc-swfc.all/soft_reference_test1` → stays `ruffle_matched`.
- gnash `case-v6`, `MovieClip-v6/v7/v8` → no regression.
- Broad sweep for `createEmptyMovieClip`/`attachMovie`/`duplicateMovieClip`
  consumers across all suites (these touch the changed registration path).

## Alternative approach (Approach 2): origin-tagged properties

If Phase 1's audit surfaces read paths that genuinely need the `var_map`
instance entry, tag each binding with its origin (instance-registration vs
explicit `SetVariable`) — e.g. a `PROPERTY_FLAGS_INSTANCE_NAME` bit — and have
the rename clobber **only** instance-origin entries, leaving user-set entries
alone. More robust but more invasive (new flag plumbed through
`setProperty*`/`hashmap` and every registration site). Prefer Approach 1 unless
the audit forces this.

## What NOT to do (dead ends already tried)

- Adding an object/variable-aware fallback to `resolveSoundOwner` alone
  (`resolveFlashPathToMC` → `resolveObjectPathToMC`): does **not** fix it,
  because the `var mc` is already destroyed by the time the owner is re-resolved.
- Skipping only one of the two clobbers (dynamic_props *or* var_map): the other
  still shadows/destroys the binding. Both stores must be addressed together with
  Phase 1.

## Scope / payoff

One test (`sound_setters`), no `output.ruffle.txt`, so only a full Flash **PASS**
counts. Low direct payoff, but the de-conflation is a correctness improvement to
a core binding mechanism and may quietly fix other rename-adjacent edge cases.
Weigh against the regression-audit cost before scheduling.
