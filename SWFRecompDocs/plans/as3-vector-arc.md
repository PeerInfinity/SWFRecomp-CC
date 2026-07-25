# Arc: as3/Vector — 14 tests, four independent root causes

Opus-ready handoff. Fable diagnosis pass done 2026-07-25 (all 14 diffs read,
every root cause traced to a code site). The plan's predecessor
(`typed-builtin-prototypes-arc.md`) is the template: execute the slices,
read each named test's diff before touching code, scoped-guard locally,
one CI run at the end.

Baseline (graphics, `9b6bbcb57`): as3/Vector 14 failing, all
`output_mismatch` except `initializer_large_vector` (`compile_fail`).
Failing list: `bug_678952, filter, filter_initializers, foreach,
foreach_initializers, initializer_expressions, initializer_large_vector,
map, map_initializers, nested, nonindexproperty/v10, some,
some_initializers, vectorIndexRangeExceptions`.

## Slice A — ArgumentError #1063 on zero-arg iteration methods (8 tests)

`some, map, filter, foreach` + their `_initializers` twins each fail ONE
line: calling the method with **no arguments** must throw
`ArgumentError: Error #1063` (verified in `some/Test.as:37-45`:
`v1.some()` → catch → prefix-compare). We silently run with an undefined
callback and return the default.

Fix in `avm2_vector.c`: at the top of `vec_every` (:995), `vec_some`
(:1015), `vec_for_each` (~:1035), `vec_filter` (:1051), `vec_map`:
`if (act->argc < 1) → throw #1063`. `every` has no corpus assertion for
this but must get the same guard (consistency + avmplus behavior).

- Message precedent: `avm2_number.c:462-476` (native statics already
  throw #1063). Tests prefix-compare only `"ArgumentError: Error #1063"`,
  so the tail is free-form — still follow the avmplus shape
  ("Argument count mismatch on %s. Expected 1, got 0.").
- The existing `vec_callback_arg` #1034 behavior for non-function args is
  asserted by the same tests ("checker not a function PASSED") — don't
  touch it.
- **Overshoot sweep**: grep the corpus's failing tests' output.txt for
  `#1063` — other native builtins (Array/String/RegExp methods) may have
  the same latent zero-arg assertions. Per
  `shared-mechanism-fixes-overshoot-estimates`, the named 8 is a floor.

## Slice B — Vector property-access error taxonomy (4 tests)

All in the Vector name/index paths; the machinery exists
(`vec_throw_1125` at `avm2_vector.c:73`, #1056 at :218-226, #1069), the
gating is wrong in four places.

1. **`nonindexproperty/v10`** — v10 READ path. Failing lines: reads of
   `max_uint_m1, max_int_p1, max_int, max_int_m1, max_int28_p1` (all
   valid-u32, out-of-range) expect `RangeError #1125`; we throw #1069
   because `avm2_vector_name_access` (:203-206) gates #1125 behind
   `swf_version >= 11`. The test's own comment (line 258): "The
   implementation does some case analysis at 28 bits" — avmplus int
   atoms are 29-bit signed, so indices ≥ ~2^28-1 can't take the
   name-lookup path even in v10 and hit the range check. Constants at
   Test.as:216-226 (`max_int28 = 268435455` expects RANGE per :262).
   Fix: in the v10 read-miss branch, throw #1125 when the index is above
   the atom boundary; keep the proto-chain fallback below it (the whole
   rest of the nonindexproperty suite depends on that fallback — it
   tests `Vector.<*>.prototype[3]` resolution). Pin the exact boundary
   (≥ `max_int28` vs > it) from output.txt: `max_int28_m1` (:264 area)
   tells you which side is proto-fallback.
   Note WRITES already pass — only the read path is miscased.

2. **`vectorIndexRangeExceptions`** — non-numeric name WRITE, e.g.
   `v_a['bar'] = x`, must throw `ReferenceError #1056` ("Cannot create
   property bar on Vector.<*>"); we silently create a dyn prop.
   `avm2_vector_name_access` returns 0 for non-numeric names
   (`vec_name_as_f64` fails at :183) and the generic setproperty path
   accepts the write. Fix: Vector receivers must reject dyn-prop
   CREATION with #1056 — but only after trait resolution (writes to
   `length`/`fixed` and method-trait misses must keep their current
   behavior; reads of 'bar' already pass, don't touch the read path).
   Simplest shape: in the generic set path (avm2_ops.c, around the
   vector fast path at :746/:861), when the receiver is a vector and the
   name resolved to no trait and isn't numeric → #1056. Check whether
   `AVM2_CLASS_FLAG_SEALED` on the vector classes already provides this
   and is simply not set / not consulted on this path — if Vector classes
   aren't SEALED-flagged, flagging them may be the one-line fix, but
   audit what else consults the flag first (`object_is_dynamic`,
   for-in enumeration, the new `is_prototype` interplay:
   `Vector.<*>.prototype` must STAY writable — nonindexproperty depends
   on prototype-supplied indices).

3. **`initializer_expressions`** — one line: `delete (new<int>[1,2,3]).length`
   must return **false** (delete on a fixed trait); we return true via
   the blanket rule at `avm2_ops.c:1191` ("FP never deletes vector
   elements; delete always reports true"). Restrict that rule to
   element/numeric names; a name that resolves to a trait → false.

4. **`bug_678952`** — one line: a ReferenceError should be **#1081**, we
   throw #1069 ("ReferenceError for !attr failing" — an attribute-
   multiname miss on a Vector). Read the Test.as to see the exact
   access; the fix is choosing #1081 over #1069 in that miss path.

## Slice C — `nested`: class-name truncation (1 test)

`500 Nested vectors` compares the LAST 501 chars of
`Vector.<Vector.<...>>`'s class toString. Two fixed buffers truncate it:

- `avm2_vector.c:286` — applied-type name built in `char nb[224]`, so
  the *class name itself* is truncated beyond ~3 nesting levels.
- `avm2_globals.c:434` + `:614` (`object_proto_to_string`,
  `class_proto_to_string`) — `char buf[160]` truncates again at print.

Fix: heap-allocate (or alloca/ctx-arena) the name at application time in
`avm2_vector.c`, and size the toString buffers from the class-name length
instead of 160. The other `[class %s]`/`[object %s]` sites at
`avm2_globals.c:711/1221/1367/1444` and `avm2_vector.c:165/220/313` want
the same audit — a 4.5KB class name reaching any of them must not
overflow (snprintf truncates safely, but the OUTPUT would be wrong; only
the sites a test exercises need fixing, the rest need a bounds-safety
glance). Identity is unaffected: typecheck/length lines already pass —
parameterized-class identity is the VecApp chain, not the name string.

## Slice D — `initializer_large_vector`: recompiler peephole (1 test)

`Test.as` has a ~25k-element `new<int>[...]` literal. The recompiler
emits one quad per element — `Dup; PushInt idx; PushInt val;
SetPropertyFast` — producing a **2,025,185-line C function**
(`abc0_methods.c`). gcc **ICEs (cc1 segfault) even at `-O0`** (verified
locally; -fsyntax-only alone takes 22s), so there is NO compiler-flag
workaround; CI's 300s `compile_fail` is this.

Fix in the SWFRecomp ABC→C emitter (find the SetPropertyFast emission —
the generated comments name the ops, so grep the emitter for
"SetPropertyFast"): peephole a run of
`Dup / PushInt|PushUint|PushDouble k / Push<const> v / SetPropertyFast(same mn)`
with consecutive k into

    static const int32_t init_vals_N[] = {…};
    for (i = 0; i < COUNT; i++) { …setproperty_dyn(…, base+i, vals[i]…) }

Details that matter:
- `DebugLine` ops are interleaved inside the run (seen in the generated
  code) — the matcher must skip them.
- Threshold ≥ ~64 quads so ordinary code is untouched.
- Mixed value types within one literal: bail (or split runs by type) —
  this test is all-int.
- Verify with the recompiler alone first (recompile the SWF, wc -l the
  output, gcc -O2 -c it) before a full test run; artifacts recipe:
  copy `test.swf` + `ruffle-tests/_shared/config.toml` to a scratch dir,
  run `SWFRecomp/build/SWFRecomp config.toml`.
- This is generic AOT hygiene, not test-only: any game with big literal
  tables hits the same wall.

## Process

- Local: single tests + scoped guards
  (`--tests-dir ruffle-tests/tests/swfs/from_avmplus/as3/Vector`), and
  remember the typed-prototypes lesson: scoped guards structurally miss
  cross-suite regressions — the avm2 suite has its own Vector tests, so
  spot-check `avm2/vector*` singles locally, then let CI judge.
  NEVER a full local suite run. `initializer_large_vector` takes 300s+
  to fail locally — don't re-run it until slice D is in.
- Slice B item 2 (SEALED flag) is the riskiest change — if you flag
  Vector classes SEALED, run the scoped Vector guard AND
  `avm2/vector_concat`-style singles before committing.
- CI: graphics, `categories=full` (AVM2 runtime + recompiler emission),
  one watcher, `corpus_status_diff.py <sha> WORKTREE --per-suite`,
  crash histogram vs baseline segfault 3 / timeout 4 / runtime_error 21 /
  compile_fail 1 (slice D should take compile_fail to 0).
- Docs after CI: feature-priority-map DONE line, suite CURRENT_STATUS,
  this file's header, `.pipeline-state`.

## Expected yield

The named 14, minus anything a slice turns out not to cover, plus
possible #1063 overshoot from slice A's sweep. Slices are independent —
land and CI-confirm in one batch, but commit per-slice so a regression
bisects cleanly.
