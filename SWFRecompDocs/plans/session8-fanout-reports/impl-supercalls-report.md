# wave-2 report — `avm2/supercalls_weird` (+1)

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a5080eb6cb398d9dc`
Base: `1c7c23761`. Patch: `.../scratchpad/wave2/supercalls.patch` (1 file, +78/-6).
Nothing committed, pushed, or dispatched.

## Verdict

**Target flips `output_mismatch` → `pass`.** Zero canary moves in 37 tests
across three suites. The wave-1 brief was correct end to end, including its
predicted intermediate failure mode.

## What changed — `SWFModernRuntime/src/avm2/avm2_ops.c` only

All three edits are runtime-side; the recompiler emits the right ops already.

1. **`super_class_of` — script-init arm.** A frame with `bound_class == NULL`
   whose `this` is stamped with `builtins.global_class` now resolves super to
   `builtins.object_class` instead of throwing #1035. This mirrors Ruffle's
   synthetic per-script `global` class (`globals/global_scope.rs create_class`,
   `script.rs:630 MethodAssociation::classbound(global_class, true)`).
   Deliberately done *inside* `super_class_of` rather than by passing a
   non-NULL `bound_class` at `avm2_globals.c:145` — per the brief, that would
   rewrite the pinned `global$init()` frame text in `error_stack_trace` /
   `primitive_valueOf` and disarm `avm2_op_constructsuper`'s `bound_class ==
   NULL` early return that keeps `array_access_interpreter` passing.

2. **`super_class_of` — class-side arm** (new helper `frame_is_class_side`).
   A static method or class initializer — detected as `bound_class != NULL &&
   this is AVM2_OBJ_CLASS && this->class_ref == bound_class` — resolves super
   to the flat constant `builtins.class_class`, matching Ruffle's
   `class.rs:530-534` (`c_class.super_class = Some(class_class)`,
   unconditionally; AS3 does not inherit static traits). Ordered as an
   `else if` on the `bound_class == NULL` branch so the predicate never
   dereferences a NULL bound class.

   The stale comment at the #1035 throw site (which misattributed the
   condition to `avm2/array_access_interpreter`) is corrected in place.

3. **`scope_defines_mn` + `scope_defines_named` — class-object fallback.**
   The non-`is_with` arm now falls back to `class_class->ivtable` when the
   scope entry is an `AVM2_OBJ_CLASS`, mirroring the fallback `resolve_key`
   has carried since `avm2_ops.c:289-298`. Without it the bare
   `FindPropStrict {ns-set 2}::prototype` in `Tests.superCallTest` throws
   #1065 *before* the `GetSuper` runs. The `_dyn` twin
   (`scope_defines_named`, MultinameL) got the same fallback for symmetry —
   no corpus consumer today. A comment records that `class_class->ivtable`
   holds exactly one entry (`prototype`) only because it is built at
   `avm2_globals.c:3432`, before Object's `hasOwnProperty` /
   `isPrototypeOf` / `propertyIsEnumerable` are registered at `:3471`, and
   that reordering that init would silently widen the fallback.

### Sequencing checkpoint (brief §8.1) — confirmed

With edit 1 alone the diff moved exactly where the brief predicted:

```
     1  true                                       <- line 1 now correct
-    2  [object Object]
+    2  ReferenceError: Error #1065: Variable prototype is not defined.
+    3  	at Tests/superCallTest()
+    4  	at Tests()
```

That is the evidence edit 3 (the scope-walk fallback) is both needed and
correctly placed. With all edits: `PASS`.

## Ledger — before → after

Statuses are `--mode=no-graphics` local runs; "before" is
`_results/results_graphics.json` at HEAD, plus a stash-diff re-run of every
non-passing test to compare ACTUAL output (per the `stash-diff-sweep` lesson —
`ruffle_matched` reads as FAIL in the runner, so status-to-status is the only
valid comparison).

### Target
| test | before | after |
|---|---|---|
| `avm2/supercalls_weird` | output_mismatch | **pass** ✅ |

### avm2 (24 canaries, all unchanged)
| test | before | after |
|---|---|---|
| `array_access_interpreter` | pass | pass |
| `class_supercalls_errors` | pass | pass |
| `method_without_body` | pass | pass |
| `astypelate` | pass | pass |
| `class_supercalls_mismatched` | pass | pass |
| `es4_inheritance` | pass | pass |
| `es4_interfaces` | pass | pass |
| `es4_protected_inheritance` | pass | pass |
| `eventdispatcher_tostring` | pass | pass |
| `instanceof` | pass | pass |
| `interface_namespaces` | pass | pass |
| `istype` | pass | pass |
| `istypelate` | pass | pass |
| `super_get_call` | pass | pass |
| `supercall_two_classobjects` | pass | pass |
| `virtual_properties` | pass | pass |
| `bitmap_subclass` | pass | pass |
| `activation_class` | pass | pass |
| `getouterscope_two_classobjects` | pass | pass |
| `scopes_dont_cache/order-1` | pass | pass |
| `scopes_dont_cache/order-2` | pass | pass |
| `error_stack_trace` | output_mismatch | output_mismatch (actual byte-identical, 45/45 lines, matching_lines 38→38) |
| `primitive_valueOf` | output_mismatch | output_mismatch (240/285 lines, matching_lines 25→25, stored prefix identical) |
| `scope_optimizations` | output_mismatch | output_mismatch (actual byte-identical, 4/4, matching 3→3) |
| `freestanding_superclass` | ruffle_matched | ruffle_matched (2/4 matching, unchanged) |
| `sub_super_same_field` | output_mismatch | output_mismatch (6/12 matching, unchanged) |

### from_avmplus (6, all unchanged)
| test | before | after |
|---|---|---|
| `as3/Definitions/Super/SuperProps` | pass | pass |
| `as3/Definitions/Super/SuperInForLoop` (the `_dyn` path edit 3 touches) | pass | pass |
| `as3/Definitions/Super/SuperRuntimeError` | pass | pass |
| `as3/Definitions/Classes/Ext/AccStatMethSubClassMethSuper` | pass | pass |
| `as3/Array/bug_535446` | ruffle_matched | ruffle_matched |
| `as3/Array/length_mods` | ruffle_matched | ruffle_matched |

### regression (6, all unchanged)
`avm2_findprop_this_resolution`, `avm2_static_and_store_slots`,
`avm2_typed_value_ops`, `avm2_timeline_gradients`, `avm2_timeline_solid`,
`avm2_timeline_stroke_gradient` — **pass → pass** (all six).

`avm2_findprop_this_resolution` and `avm2_static_and_store_slots` were added on
top of the brief's list: a grep of `regression/*/README.md` for super/scope
mentions surfaced them as the two hand-written nets for scope-walk /
findprop-static behaviour, i.e. exactly what edit 3 perturbs. Both pass.

**Totals: 37 tests run. 1 flip (output_mismatch → pass). 0 regressions.
0 other status moves.**

## Predicted CI delta

**+1** (`avm2/supercalls_weird`), and nothing else.

The brief's whole-corpus `--dump-abc` sweep (4943 SWFs) found `supercalls_weird`
is the only test in the corpus with a get/set/callsuper in a class-side frame or
a script init, and the only findprop of a bare `prototype`. Both of edit 1's new
arms and edit 3's fallback are therefore unreachable from every other test — they
can only convert a throw into a dispatch, never the reverse. Local results are
consistent with that.

CI: `mode=graphics`, `categories=full`, `images=false` (AVM2 runtime change).

## Deviations from the brief

- **Extra canaries.** Added the two `regression/` scope-walk nets above, and ran
  the four non-passing tier-2 entries (`freestanding_superclass`,
  `sub_super_same_field`, `as3/Array/bug_535446`, `as3/Array/length_mods`) as
  status-to-status checks rather than skipping them, since `ruffle_matched` and
  `output_mismatch` can both move sideways.
- **No `--mode=graphics` local runs.** Machine was carrying ~26 concurrent
  `verify_output.py` processes from sibling agents; compile times ran 40–390 s
  per test. This change is mode-agnostic (pure AVM2 runtime, no
  `NO_GRAPHICS`/`OFFSCREEN_RENDER` arms touched), and mode parity has been
  complete since 2026-07-23, so no-graphics results carry over.
- **Doc corrections left undone, on purpose.** The brief (§8.4, §10) asks for
  amendments to `SWFRecompDocs/plans/polish-sweep-arc.md` §8.7 and the session-7
  report ("BLOCKED / class-side super chain is a new mechanism" — now known to be
  a mis-sizing; the mechanism is the flat constant `Class`). Both are
  session-level docs the coordinator is likely to rewrite at closeout, so
  editing them from a parallel worktree would just manufacture a merge conflict.
  **Handing that to the coordinator**; the corrected facts are in §3/§10 of the
  wave-1 brief and in the code comments this patch lands.

## Suggested commit message

```
avm2: bind script-init and class-side super frames (supercalls_weird)

Three fixes in avm2_ops.c, all needed to run one test end to end:

- super_class_of: a script init (bound_class == NULL) whose `this` is a
  script global now resolves super to Object, matching Ruffle's synthetic
  per-script `global` class (global_scope.rs create_class + script.rs:630)
  instead of throwing VerifyError #1035. Done inside super_class_of rather
  than by giving script inits a real bound_class, which would rewrite the
  pinned `global$init()` frame text in error_stack_trace / primitive_valueOf
  and disarm avm2_op_constructsuper's NULL guard that array_access_interpreter
  depends on.

- super_class_of: a class-side frame (static method or cinit — `this` is the
  bound class's own class object) resolves super to the flat constant `Class`.
  Ruffle sets every c_class's super_class to class_class unconditionally
  (class.rs:530-534) because AS3 does not inherit static traits; there is no
  chain to walk.

- scope_defines_mn / scope_defines_named: fall back to class_class->ivtable
  for AVM2_OBJ_CLASS scope entries, the same fallback resolve_key has carried
  since avm2_ops.c:289. Without it a bare `prototype` FindPropStrict inside a
  static method throws #1065 before the GetSuper ever runs.

Also corrects the stale comment at the #1035 throw site: contrary to it,
avm2/array_access_interpreter has no get/set/callsuper at all — its script-init
ConstructSuper returns early in avm2_op_constructsuper.

A --dump-abc sweep of all 4943 corpus SWFs confirms supercalls_weird is the
only test with a super op in a class-side or script-init frame, and the only
bare-`prototype` findprop; 37 local canaries across avm2 / from_avmplus /
regression show no other status move.

avm2/supercalls_weird: output_mismatch -> pass
```
