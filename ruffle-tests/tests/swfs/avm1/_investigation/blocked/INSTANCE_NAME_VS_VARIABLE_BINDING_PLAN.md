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
    status: in_progress
    note: "dprops delete-not-undef + var_map sentinel-not-undef landed 2026-07-02 with the soft-ref work (8d1e3adef); the remaining piece is removing the var_map clobber entirely, which depends on Phase 1"
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

## Update 2026-07-02 — soft-reference rebinding landed; this plan is now UNBLOCKED-ADJACENT

The F2 soft-reference work (`8d1e3adef` + `855c63864`, CI green both modes —
see `from_gnash/_investigation/incomplete/MOVIECLIP_VN_PLAN.md` 2026-07-02
headers) landed most of the infrastructure this plan needs and changed
several facts below:

**Already done here (subsumes parts of Phase 2):**
- The `_name` setter now **DELETES** the old-name `dynamic_props` key
  (was: set-to-undefined) and clears the old var_map key with the
  **not-found sentinel `{0}`** (was: typed undefined, which shadowed
  child re-resolution). Exactly the Phase 2 "delete, not undef" fix.
  `soft_reference_test1` survived this and is now a **full PASS** — its
  `typeof(oldname) == 'undefined'` protection now comes from genuine
  absence (sentinel + no live same-named clip), not from undef-shadowing.
- Bare-name (GetVariable, ~action.c:41700) and member (GetMember)
  child lookups now have an `as_created`-gated child_mc_cache fallback by
  CURRENT name, lowest depth first, **scoped to the current context's
  children**. This is the "child-by-name fallback" Phase 1's risk audit
  asked for: dynamic clips are reachable by name **without any
  var_map/dynamic_props binding**, so removing the var_map
  auto-registration no longer breaks read access. (Scoping matters: an
  earlier unscoped version resolved root clips from child-clip scopes and
  broke `string_paths_other` — bare names must NOT see root children from
  a child context.)
- `MovieClip.as_created` flag (struct field) distinguishes real
  AS-created clips from lookup-minted phantoms in these scans.
- Soft-ref deref (`mcResolveSoftRef`, action.c ~20164) at
  GetMember/SetMember/CallMethod: variables holding destroyed clips
  re-resolve by creation-time `original_target`. Sound's owner
  re-resolution can reuse this model.

**New blocker discovered (affects Approach 1's premise):**
`actionSetVariable` at root **mirrors every write into
`root_movieclip.dynamic_props`** (action.c ~42581, "mirrors SetMember
bidirectional behavior" — dispatch functions read handlers from dprops).
So at root, `dynamic_props` is NOT a clean display-list-child store: it
also contains every user timeline variable. De-conflating var_map alone
does not de-conflate root dprops; Phase 1/2 must either tag, special-case,
or live with the mirror. This is empirically load-bearing — it defeated an
attempted "var_map and dprops agree ⇒ auto-registration" heuristic during
the F2 work (both stores always agree at root).

**New regression sentinel for this plan:** gnash
`actionscript.all/Transform-v8` (Transform.as:203-210). `mcOld = mc; mc =
_root.createEmptyMovieClip("mc", getNextHighestDepth())` — an EXPLICIT
variable assignment whose name collides with a live same-named sibling.
Any binding change must keep the explicit assignment authoritative (`mc`
reads the NEW clip; `mcOld` keeps the old one). Currently ruffle_matched;
a lowest-depth-wins override applied to live variable bindings regressed
it and had to be gated to `avm1_removed` bound clips only
(`mcNameBindingOverride`, action.c ~20124).

**Additional payoff:** gnash `MovieClip-v6/v7/v8` line `MovieClip.as:812`
(`hardref.member == 60` — lowest-depth-wins between two LIVE same-named
clips read through the auto-registered name) is unfixable until this plan
lands: with the var_map auto-registration gone, `hardref` resolves through
the child-name scan (which already picks lowest depth) instead of the
stored pointer. Ruffle passes this line, so it is part of the MovieClip-vN
ruffle_matched promotion gate. The `g_mc_dup_names_seen` flag +
`mcLowestDepthSameName` helper (action.c ~20098-20122) are already in
place for it.

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

The clobber is **load-bearing** for currently-effective-pass tests:

- `from_gnash/misc-swfc.all/soft_reference_test1` — expects
  `typeof(oldname) == 'undefined'` after a rename (sc:107-147).
  **2026-07-02 update:** now a full PASS and considerably less fragile —
  the rename writes the not-found sentinel (not typed undefined) and the
  as_created child-name fallback resolves by CURRENT name, so the
  'undefined' comes from genuine absence. Removing the clobber outright
  still needs care: with the sentinel gone, a stale live pointer in
  var_map would resolve again.
- gnash `case-v6` — case-insensitive SWF6 name-table collision protection
  (`case.as:96-170`).
- gnash `MovieClip-v6/v7/v8` soft-reference suite (now much larger
  coverage of these paths — the sr62/sr63/hardref4/hardref5 cluster all
  passes and must not regress).
- gnash `Transform-v8` (Transform.as:203-210) — explicit
  `mc = createEmptyMovieClip("mc", d)` assignment must stay authoritative
  over same-named siblings (see 2026-07-02 update above; this one
  regressed once already).

None of these can be validated locally as a full set (multi-suite,
full-suite runs are CI-only), though each can be spot-checked
individually. The fix must land behind a full CI pass (both modes — this
is shared runtime code).

## Relevant code

| Concern | Location (`SWFModernRuntime/src/actionmodern/`, anchors as of 2026-07-02, `855c63864`) |
|---------|--------------------------------------------------|
| `createEmptyMovieClip` registration (dynamic_props + var_map) | `action.c` function-form ~58990 (search `_cemc_has_existing`), method-form ~67470 (search `_mcemc_has_existing`); both now also run the `Duplicate-name detection` scan that sets `g_mc_dup_names_seen` |
| `attachMovie` / `duplicateMovieClip` registration | `libswf/tag_stubs.c` (search `as_created`) — all creation sites now set `mc->as_created = 1` |
| `_name` setter (dynamic_props old→DELETE, var_map old→sentinel `{0}`) | `action.c` ~48250 (search `strcasecmp(prop_name, "_name")` in actionSetMember) |
| Bare-name resolution order + as_created child fallback | `actionGetVariable`; the new context-scoped fallback is at ~41700 (search `Scoped to the CURRENT context's children`) |
| **SetVariable→root-dprops mirror (new discovery)** | `action.c` ~42581 (search `Also propagate to root MC dynamic_props`) — root user vars are mirrored into `root_movieclip.dynamic_props` for dispatch-handler lookup; root dprops is therefore a MIXED store |
| Soft-ref infra (deref, lowest-depth, dup flag) | `action.c` ~20098-20220: `g_mc_dup_names_seen`, `mcLowestDepthSameName`, `mcNameBindingOverride`, `mcResolveSoftRef` |
| Sound owner re-resolution | `resolveSoundOwner`, `action.c` ~1439 |

**Key fact that makes the fix viable** (strengthened 2026-07-02):
`actionGetVariable`'s bare-name path resolves a clip via (1)
`g_current_context->dynamic_props`, then (2) child-by-name
(`resolveSlashPathToMC` + the new context-scoped `as_created`
child_mc_cache fallback), and only *then* (3) `var_map`. Since the F2 work,
dynamic clips are reachable by CURRENT name with **no binding at all** —
the `var_map` auto-registration is now fully redundant for read access,
including after rename shuffles (previously the fallback didn't exist and
dynamic clips were reachable *only* through their bindings).

**Caveat for Phase 1 (new):** because of the SetVariable→root-dprops mirror
(row above), stopping the auto-registration in `var_map` does NOT leave
`dynamic_props` as a clean "display-list child binding" store at root —
explicit user variables land there too. The `mc` vs `mc2` asymmetry table
below still holds for resolution *order* reasons, but any logic that wants
to ask "is this dprops entry an instance binding?" cannot — that question
is unanswerable at root (this killed a var_map/dprops-agreement heuristic
during F2). If Phase 1 needs origin information, it must add a real origin
tag (Approach 2) rather than infer it.

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

Run the full pipeline in **both modes** (shared runtime code; the F2 CI
rounds ran both and they agreed exactly). Required green / no-regression set:

- `avm1/sound_setters` → **PASS** (target).
- `from_gnash/misc-swfc.all/soft_reference_test1` → stays **full PASS**
  (upgraded from ruffle_matched by the F2 work).
- gnash `MovieClip-v6/v7/v8` → the F2 soft-ref cluster must not regress;
  target: `MovieClip.as:812` flips to passing (−1 more mismatched line
  each, part of the ruffle_matched promotion gate).
- gnash `case-v6` → no regression (case-insensitive collision protection).
- gnash `Transform-v8` → stays ruffle_matched (Transform.as:203-210 —
  explicit assignment authoritative over same-named siblings; regressed
  once during F2, see the 2026-07-02 update).
- avm1 `global_swf6_7_8` (MovieClipLoader loadClip replacement structs),
  `string_paths_other` (bare-name scope isolation from child clips),
  `string_paths_reference_launder`, `string_paths_eval2` → all PASS
  (each caught an F2 follow-up bug; they exercise exactly these paths).
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

Updated 2026-07-02:

- `avm1/sound_setters` (no `output.ruffle.txt`, so only a full Flash
  **PASS** counts).
- gnash `MovieClip-v6/v7/v8` line `MovieClip.as:812` (−1 mismatched line
  each; Ruffle passes it, so it is part of the ruffle_matched promotion
  gate — the rest of the F2 soft-ref cluster already passes).
- Possible simplification: with var_map auto-registration gone, the
  `avm1_removed` gate on `mcNameBindingOverride` (and possibly the
  override itself) may become unnecessary — name reads would flow through
  the child-name scan, which already picks the lowest-depth live clip.

Much of the risky groundwork (child-name fallback, rename
delete/sentinel semantics, as_created tagging, dup-name detection) landed
and CI-validated with the F2 soft-ref work, so the residual risk is
concentrated in removing the two registration/clobber sites themselves.
Weigh against the regression-audit cost before scheduling; the
verification battery in Phase 3 is now much more specific.
