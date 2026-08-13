# w2-watch-order — session 15 wave-2 (board §15.3, "watch must precede the virtual-setter walk")

**Agent:** wave-2 `w2-watch-order` (implementation).
**Worktree:** `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-af4e6a1edce4af4ca`
(HEAD `42a324cef`; grading baseline CI run `31647430265` @ `bf585e448`, trace 4269/4443 effective).
**Patch:** `w2-watch-order.patch` — 2 files, **+181 / −1**, `action.c` is **pure addition**
(4 hunks, zero deleted lines).

## Verdict — GO, +1 effective, and it lands as a full `pass`, not `ruffle_matched`

| test | before (CI `bf585e448`) | after |
|---|---|---|
| `avm1/watch_virtual_property` | `output_mismatch` e=60 a=52 **m=9** | **`pass`** e=60 a=60 **m=60** |

Byte-exact against `output.txt` — the **Flash** oracle — not against `output.ruffle.txt`.
The intermediate state (ordering fix only) was measured and reaches `ruffle_matched`;
two further oracle-pinned Flash rules (§3) take it the rest of the way. Both grades are
worth the same +1 effective, but the `pass` lets the test come off `ignored_tests.txt`
outright instead of living on as a Ruffle-parity row.

**Zero canary movement:** 17/17 avm1 effective, 6/6 regression, every row identical to the
CI baseline (§4).

---

## 1. The brief's premise, attacked — and the coordinator's correction, confirmed

The brief (from s14's §7 follow-on lead) called this "a dispatch-**ordering** bug (watch must
run before the virtual setter)". The mid-task coordinator note said that was **understated**:
the watcher never fires *at all*. I verified this against my own repro **before** writing any
code, and the coordinator is right — with a sharper statement of why:

There is no site where watch dispatch and the virtual-setter walk sit next to each other in
the wrong order. In `actionSetVariable` the two live ~30 lines apart with an **early `return`**
between them:

```
actionSetVariable
  … with-scope chain … MC builtin props (`_x`, `_alpha`, …) …
  ├─ "check global_object for addProperty setter"  →  invokeVirtualSetter(); return;   ← exits here
  ├─ getVariableById / getVariable      (never reached)
  └─ "--- Timeline variable watcher check ---"     (never reached)
```

So it is not a reorder. **The watch check had to be inserted into the addProperty set path**,
which is what the patch does. The distinction matters for cost: swapping two adjacent blocks
would be free; inserting a watch dispatch into a branch that has no variable slot, no
old-value source and no store meant supplying all three (§2).

Everything else in the brief stands. In particular the s14 unified re-entry counter is
untouched — the new firing site calls the same `watchReentryBlocked()` /
`watch_firing_push/pop()` trio, so it participates in the shared counter rather than
bypassing it (`watch_timeline_reentrant` and `watch_mc_reentrant_setmember` both still pass).

**Second refutation, smaller:** the s14 report and `ignored_tests.txt` both treated
`unwatch("variable")` returning `true` as "a second, smaller tell" of the same defect. It
isn't the same defect at all — the rule was already implemented, correctly, and only for
`ASObject` receivers (`builtin_object_unwatch`, comment *"Object.as:846"*). The timeline arm
of the very same function simply never got the rule. That is a **missing-arm** bug, not an
ordering one, and it is fixed independently of the watch dispatch.

---

## 2. Mechanism

### 2.1 Where a bare `addProperty` actually puts the accessor

`watch_virtual_property` calls everything unqualified — `watch(...)`, `addProperty(...)`,
`unwatch(...)`, and `variable = 10` compiles to `ActionSetVariable`. That splits the state
across two stores that do not know about each other:

| what | where it lives |
|---|---|
| the watch row | `g_watch_table[i]` with `obj == NULL`, `mc == g_current_context` (the *timeline* arm) |
| the getter/setter | an own property on **`global_object`** (`actionCallFunction`'s bare `addProperty` handler installs it there) |
| the timeline variable | `var_array` / `var_map` |

`actionSetVariable` consults `global_object` for an addProperty setter, fires it, and returns
— three blocks before it would have looked at `g_watch_table`. Hence: **every** `plusOne:`
line missing from our output, with the re-entry counters sitting at 0 the whole time. Reads
were never affected (`actionGetVariable` checks the `_global` getter *before* the var table),
which is why the test's `getter: returning 5` half already matched and the diff looked
partial (9/60) rather than structural.

### 2.2 What Ruffle does, and the raw slot

`core/src/avm1/object.rs::set_internal` is unambiguous:

```rust
let watcher_result = self.call_watcher(activation, name, &mut value, this);   // FIRST
if !self.has_own_property(activation, name) { …virtual-setter proto walk… }
let result = self.set_local(name, value, activation, this);
```

Two things follow that the patch had to reproduce:

1. **`call_watcher` takes `&mut value`** — the watcher's return value *replaces* what reaches
   the setter. That is why the oracle says `setter: ignoring new value of 11` after
   `variable = 10`: `plusOne` returned 10+1.
2. **`call_watcher` reads `old_value` from `get_stored`, i.e. the property's raw data slot** —
   *not* by invoking the getter. And `script_object.rs::set_local` calls the setter and then
   does `entry.get_mut().set_data(value)` **unconditionally**: the raw slot is updated even
   though the setter "ignored" the value. The slot is invisible to every read (the getter
   shadows it) and exists solely to be the *next* watcher call's `oldVal`.

That second point is the whole reason the oracle's old-values look bizarre
(`undefined → NaN → 11 → 5 → 11 → 5`): they are a chain of the watcher's own return values,
not of anything the program can read back. `svwo_rawSlotStore()` supplies exactly this slot,
using `gp->value` on the `_global` property — the direct analogue of Ruffle's property entry
data.

### 2.3 The arithmetic that pins it

`plusOne` returns `newVal + 1`, so each fire's return is the next fire's `oldVal + 1`:

| assignment | oracle `oldVal` | source |
|---|---|---|
| (addProperty) | `undefined` | fresh slot |
| `variable = 10` | **`NaN`** | `undefined + 1` from the addProperty fire |
| `variable = 4` | `11` | `10 + 1` |
| `variable = 10` (after `unwatch`) | `5` | `4 + 1` |

`NaN` is the load-bearing value: it can only exist if a watcher fired at **addProperty** time
with `undefined` and its `undefined + 1` was written to the slot. No model without §3.2
produces it.

---

## 3. The two Flash rules beyond the Ruffle model

The ordering fix alone (measured: `ruffle_matched`, exact against `output.ruffle.txt`)
leaves three oracle lines unexplained. Both remaining rules are pinned by `output.txt` and
neither is guesswork about unobserved behaviour.

### 3.1 `unwatch` on a getter-setter returns `false` and keeps the watcher

Oracle: `unwatch("variable")` traces **`false`**, and the two assignments *after* it still
emit `plusOne:` lines. Ruffle returns `true` and stops watching (its `unwatch` just removes
the map entry). Our `builtin_object_unwatch` already implements the Flash rule — for
`ASObject` receivers only. The patch adds the identical rule to the timeline arm, where "this
name is currently a getter-setter" means *an own accessor property on `_global`*.

### 3.2 `addProperty` fires the watcher with `(undefined, undefined)`

Oracle emits `plusOne: variable changed from undefined to undefined with userdata undefined`
at **both** `addProperty` calls, before each `true`. Mechanism: Flash re-initialises the slot
as part of installing the accessor, and that store goes through the watch table like any
other. Ruffle's `add_property` bypasses the watcher entirely, which is exactly the
Ruffle-vs-Flash gap here.

This rule is added **only to the bare/`_global` `addProperty` path** in `actionCallFunction`.
`builtin_object_addProperty` (the `o.addProperty(...)` method form) is deliberately left
alone: no test in the corpus exercises object-form addProperty on an already-watched name
(§4.3), so extending it would be unevidenced, and the `watch_recursion` family — which is
all object-form — must not move.

The second fire also confirms `delete(variable)` clears the `_global` slot: the oracle's
final fire reports `undefined`, not the `5` left over from before the delete. We reproduce it
without any delete-path change.

---

## 4. Before / after — full ledger

### 4.1 Target

| test | before | after |
|---|---|---|
| `avm1/watch_virtual_property` | `output_mismatch` (e=60 a=52 m=9) | **`pass`** (60/60/60) |

### 4.2 avm1 canaries — the full s14 watch/accessor set (17 tests, sequential)

`--tests-dir=ruffle-tests/tests/swfs/avm1`. "before" = CI graphics baseline
`_results/results_graphics.json` @ `bf585e448`.

```
BEFORE   pass 13   ruffle_matched 3   fail 1    (effective 16/17)
AFTER    pass 14   ruffle_matched 3   fail 0    (effective 17/17)
```

| test | before | after |
|---|---|---|
| `watch` | pass 117/117/117 | **pass** |
| `watch_infinite_recursion` | pass | **pass** |
| `watch_proto_recursion` | pass | **pass** |
| `watch_textfield` | pass | **pass** |
| `watch_virtual_property_proto` | pass 2/2/2 | **pass** |
| `add_property` | pass 15/15/15 | **pass** |
| `infinite_recursion_virtual_property` | pass 67/67/67 | **pass** |
| `virtual_property_recursion_swf6` | ruffle_matched (6/8/5) | **ruffle_matched** |
| `virtual_property_recursion_swf7` | pass 262/262/262 | **pass** |
| `virtual_property_recursion_double_swf6` | pass | **pass** |
| `virtual_property_recursion_double_swf7` | pass 523/523/523 | **pass** |
| `virtual_property_recursion_scope` | pass | **pass** |
| `watch_recursion_swf6` | ruffle_matched (18/18/17) | **ruffle_matched** |
| `watch_recursion_swf7` | pass 1042/1042/1042 | **pass** |
| `watch_recursion_double_swf6` | ruffle_matched (46/46/42) | **ruffle_matched** |
| `watch_recursion_double_swf7` | pass 3118/3118/3118 | **pass** |
| `watch_virtual_property` | `output_mismatch` | **pass** ⟵ target |

The three `ruffle_matched` rows are the fragile ones (their grade can move without crossing
pass/fail) and all three held. The `virtual_property_recursion` family — the population the
`virtual-property-reentry-per-entry-model` memory derives from — is unmoved, structurally so:
the new code is reached only from the `_global`-addProperty-setter branch of
`actionSetVariable` and the bare `addProperty` builtin, and does nothing unless a **timeline**
watch row (`obj == NULL`) exists for that exact name.

### 4.3 Regression suite — the six watch tests (6/6 pass, no movement)

`--tests-dir=ruffle-tests/tests/swfs/regression`

| test | before | after |
|---|---|---|
| `watch_cross_swf_version` | pass | **pass** |
| `watch_mc_reentrant_setmember` | pass | **pass** |
| `watch_mc_type1_args` | pass | **pass** |
| `watch_setmember_type1_args` | pass | **pass** |
| `watch_timeline_named_params` | pass | **pass** |
| `watch_timeline_reentrant` | pass | **pass** |

These cover all three pre-existing watch dispatch sites plus the s14 unified re-entry
counter. `watch_timeline_reentrant` is the direct canary for the counter (it segfaulted
before the guard existed) and `watch_cross_swf_version` for the `INV_VERSION_SWITCH` flag the
new firing site reuses.

**Corpus exposure check.** Every avm1 test whose source mentions both `addProperty` and
`watch` is in the canary set above (`watch_recursion*`, `watch_special_recursion*`,
`watch_virtual_property_proto`, `add_property`, `watch`), and every one of them uses the
**object** form `o.addProperty(...)`, which this patch does not touch. `unwatch` appears in
exactly one test's bytecode corpus-wide: the target. The `watch_special_recursion_*` dirs are
byte-identical duplicates of `watch_recursion_*` (s14 §1a) and therefore covered.

---

## 5. Patch scope — exact functions touched

`action.c` is **pure addition**: 4 hunks, +174 lines, **0 deleted lines**. Nothing existing
was moved or rewritten, which is what keeps it mergeable alongside w2-fuzz16 (timeline
placement/depth) and w2-action-order (tick/action ordering) — none of the four sites is in
their path.

| # | function | change |
|---|---|---|
| 1 | `builtin_object_unwatch` (~4411) | `else` arm added after the existing `ASObject` getter-setter check: same rule against `_global`'s own accessor properties for the timeline receiver (§3.1) |
| 2 | *(file scope, just above `actionSetVariable`, ~43562)* | four new `static` helpers, `svwo_`-prefixed (SetVariable Watch Order): `svwo_timelineWatchEntry`, `svwo_rawSlotStore`, `svwo_fireTimelineWatch`, `svwo_rawSlotOldValue` |
| 3 | `actionSetVariable` (~44192) | inside the existing `global_object` addProperty-setter branch: fire the timeline watcher, fold its return into `value_var`, mirror into the raw slot — all before the unchanged `invokeVirtualSetter()` call (§2.1) |
| 4 | `actionCallFunction`, bare `addProperty` builtin (~60538) | after the getter/setter install: fire a matching timeline watcher with `(rawSlot, undefined)` and mirror the return (§3.2) |

**Self-localisation.** The `svwo_` prefix is unique in the file; all four helpers are
`static` and file-local; no struct gained a field; no existing signature changed; no shared
global was added (`g_watch_table` / `g_watch_count` are read through the existing
accessors). Site 3's new code sits entirely *inside* an existing `if` body, so the enclosing
control flow diff is zero.

### 5.1 One deliberate deviation from Ruffle, and why

Ruffle's `set_local` mirrors the value into the data slot on **every** set. The patch gates
the mirror on a timeline watch row existing. Rationale: the slot is only ever *observable* as
a watcher's `oldVal`, so mirroring outside watch dispatch is an unobservable write — with a
real downside. A **setter-only** `_global` accessor (`addProperty(name, null, setter)`) has
no getter to shadow the slot, and `actionGetVariable` falls through to a plain-property last
resort; an ungated mirror would silently change what such a name reads back. Gating costs
nothing (the target test's `unwatch` fails under §3.1, so a watcher is registered for every
assignment in it) and makes the entire patch inert for any program that never calls `watch`.
Documented inline at the call site.

### 5.2 Memory-safety notes

- `svwo_rawSlotStore` **duplicates** UTF-16 strings before storing (the eval stack's buffer
  is not ours to keep) and routes the store through `setProperty`, so object/array
  retain–release stays paired and the old owned string is freed exactly once.
- It refuses to write unless `findPropertyRaw(global_object, …) == gp`, i.e. the accessor is
  an **own** `_global` property. `findPropertyStructWithPrototype` can return a prototype
  entry, and shadowing one onto `_global` would create a visible new property instead of
  updating a slot. That check also guarantees `setProperty` takes its "property exists" path,
  which never `realloc`s `obj->properties` — so the caller's `gp` stays valid for the
  `invokeVirtualSetter` that follows. Noted inline.
- `svwo_rawSlotOldValue` hands the watcher a **non-owning** `oldVal` and maps an
  uninitialised STRING slot (NULL heap ptr) to `undefined`, matching the existing Site-A
  unset-detection.
- `svwo_fireTimelineWatch` reuses the Site-A ritual verbatim: type-2-only gate,
  `INV_LOCAL_SCOPE | INV_VERSION_SWITCH`, non-owning prop-name arg (`pname_owns=0`,
  `free_pname=0` — the leak-over-dangle discipline), and the
  `watchReentryBlocked` / `watch_firing_push` / `watch_firing_pop` bracket that keeps the s14
  unified counter authoritative.

---

## 6. Doc changes in the patch

- **`ruffle-tests/ignored_tests.txt`** — `watch_virtual_property` **de-listed** from
  "Permanently accepted diffs", replaced by a resolution note + do-not-re-add.

  Worth flagging for the coordinator: the entry was in `ignored_tests.txt` with **no backing
  entry in `ACCEPTED_DIFFS.md` at all** (nor in `RUFFLE_VS_FLASH_DIFFERENCES.md`,
  `RUFFLE_COMPAT_TWEAKS.md`, or `FLASH_BUGS_REPLICATED.md`) — it was ignored under a heading
  that asserts "unfixable output differences" while nothing had ever documented *why*. It
  took ~180 lines to fix. This is the second consecutive session in which a watch-family
  disposition turned out to be an undocumented assumption rather than a ruling (s14 refuted
  ACCEPTED_DIFFS Cat 10 on both counts it asserted). **Suggested standing check: an entry in
  `ignored_tests.txt` under "Permanently accepted diffs" with no `ACCEPTED_DIFFS.md` section
  should be treated as an unaudited lead, not a closed one.** A quick cross-reference of the
  other six names under that heading (`date`, `mcl_replace_root_swf7_to_swf5/6`,
  `movieclip_library_state_values`, `native_objects_swf6`,
  `tab_ordering_properties_tab_index_edge_case`) would price whether more are in the same
  position.

- Not edited (coordinator's call, outside this patch): `FAILING_TESTS_BY_FEATURE.md:91` and
  `CURRENT_STATUS.md:164` still name `watch_virtual_property` as failing/ignored.

- No `ACCEPTED_DIFFS.md` / `RUFFLE_VS_FLASH_DIFFERENCES.md` entry is added — the test now
  passes byte-exact against the Flash oracle, so there is no residual diff to disposition.
  The two Flash rules in §3 are *replicated Flash behaviour that Ruffle diverges from*; if
  the coordinator wants them recorded, `RUFFLE_VS_FLASH_DIFFERENCES.md` is the right home,
  but the test itself needs no entry.

---

## 7. Reproduction

```bash
W=/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-af4e6a1edce4af4ca
cd $W && (cd SWFRecomp/build && cmake .. && make -j4)   # fresh worktree: build the recompiler

# target + the 17-test avm1 canary set (sequential; machine is shared)
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm1 \
  --test=watch_virtual_property --test=watch --test=watch_infinite_recursion \
  --test=watch_proto_recursion --test=watch_textfield --test=watch_virtual_property_proto \
  --test=add_property --test=infinite_recursion_virtual_property \
  --test=virtual_property_recursion_swf6 --test=virtual_property_recursion_swf7 \
  --test=virtual_property_recursion_double_swf6 --test=virtual_property_recursion_double_swf7 \
  --test=virtual_property_recursion_scope --test=watch_recursion_swf6 \
  --test=watch_recursion_swf7 --test=watch_recursion_double_swf6 \
  --test=watch_recursion_double_swf7 -v --recompile

python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/regression \
  --test=watch_cross_swf_version --test=watch_mc_reentrant_setmember \
  --test=watch_mc_type1_args --test=watch_setmember_type1_args \
  --test=watch_timeline_named_params --test=watch_timeline_reentrant -v

# A/B (never `git stash` — refs/stash is SHARED across worktrees)
git apply -R w2-watch-order.patch   # back to baseline
git apply    w2-watch-order.patch   # forward again
```

Test directories were copied from the main tree into the worktree's canonical
`ruffle-tests/tests/swfs/avm1/` path (untracked, not in the patch); the main tree was never
written to and no full suite was run locally. Note that `--test` runs do **not** rewrite
`_results/results.json`, so the copied JSON in the worktree still shows pre-patch rows — the
run logs above are the ledger, and the "before" column is read from the main tree's CI
`results_graphics.json` @ `bf585e448`.

---

## 8. Follow-on leads (NOT fixed here)

1. **Object-form `addProperty` on an already-watched name** — §3.2's rule is implemented only
   for the bare/`_global` path because nothing in the corpus exercises the object form in that
   configuration. If a future test does, `builtin_object_addProperty` needs the same fire.
   Cost is ~10 lines; value is currently 0 tests, so it is deliberately left undone rather
   than speculatively added.
2. **`unwatch` on a MovieClip-scoped (non-root) timeline name** — the new rule keys the
   "is it a getter-setter" question to `_global`, because that is where the bare
   `addProperty` handler installs accessors. A `tellTarget`/`with(clip)`-scoped
   `addProperty` lands on the clip's `dynamic_props` instead; the symmetric rule there is
   unexercised and unimplemented.
3. The undocumented-`ignored_tests.txt`-entry audit in §6.
