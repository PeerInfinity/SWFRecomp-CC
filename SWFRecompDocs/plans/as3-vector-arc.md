# Arc: as3/Vector — DONE (+15, predicted 14)

**CI-confirmed 2026-07-25**, run `30174981516` (graphics, `categories=full`):
from_avmplus 1455 → 1470 (93.4%), corpus 3758 → 3773 (85.5%), **0
regressions**, crash histogram flat (segfault 3, timeout 4, runtime_error
21 unchanged) and **compile_fail 1 → 0** — the corpus now has no test that
fails to compile.

Commits: `81cf6a669` (slices A, B.1, C), `222b4a4b5` (slices B.2–B.4),
`a85726a54` (the `#1063` overshoot), `2b244c01b` (slice D).

All 14 named tests landed, plus one overshoot the slice-A sweep predicted
(`ecma3/String/localeCompare_rt`). The Fable diagnosis pass was accurate on
every root cause; the two places it guessed and the corpus disagreed are
recorded under "what the diagnosis got wrong" below.

## What landed

### Slice A — zero-arg iteration methods throw ArgumentError #1063 (8 tests)

`some, map, filter, foreach` + their `_initializers` twins. The AS3
signatures declare `callback:Function` with no default, so avmplus rejects
a zero-arg call on **arity**, before it ever looks at the callback; we
silently ran with an undefined callback and returned the default. One
`vec_check_cb_argc` guard at the top of `vec_every/some/for_each/filter/map`
in `avm2_vector.c`. `every` has no corpus assertion but takes the same
guard.

**Overshoot sweep.** Grepping the corpus for tests that assert `#1063`
turns up 33 `Test.as` files; of the ones failing at baseline, only
`ecma3/String/localeCompare_rt` was actually a `#1063` problem — and in the
opposite direction: *too many* args. Unlike the variadic ES3 String
methods, avmplus declares `localeCompare(other:String):int` with no rest
arg, so a second argument is an arity error. `regress/bug_420755` (Array
holes, `#1112` vs `#1034`) and `e4x/XML/e13_4_4_2` (the `#2023` root
SymbolClass line shift) match the grep but are unrelated failures.
`avm2/wrong_arg_count` and `avm2/error_geterrormessage` need declared-ABC
method arity checking — a separate feature, not this mechanism.

### Slice B — Vector property-access error taxonomy (4 tests)

1. **`nonindexproperty/v10`** — a name that IS a valid u32 index but is out
   of range is `RangeError #1125` in **every** SWF version. avmplus routes
   an integer index straight at `getUintProperty`, which range-checks.
   We had mirrored Ruffle's `fail_read_error`, which gates `#1125` behind
   `version >= 11` and answers `#1069` below it. Non-u32 names (fractional,
   negative, non-numeric) keep the versioned ReferenceError / proto-chain
   fallback that the rest of the suite depends on.
2. **`vectorIndexRangeExceptions`** — in `setproperty_resolved`, a name
   found on the **prototype chain** was shadowed onto the receiver
   unconditionally. Finding a name on the prototype does not make a sealed
   receiver writable. The write now routes to `setproperty_miss` when
   `object_is_dynamic(recv)` is false. (`'foo'`, absent from the prototype,
   already produced `#1056`; only `'bar'`, which the test plants on
   `Vector.<*>.prototype`, took the shadowing path.)
3. **`initializer_expressions`** — the blanket "FP never deletes vector
   elements, delete always reports true" rule also swallowed names that
   resolve to a declared trait. `delete (new <int>[1,2,3]).length` is
   `false`.
4. **`bug_678952`** — an ATTRIBUTE multiname that misses reports `#1081`,
   not `#1069`. avmplus keys that on
   `isAttr() || !containsAnyPublicNamespace()`; we had only the namespace
   half.

### Slice C — unbounded parameterized-class names (1 test)

`as3/Vector/nested` builds `Vector.<Vector.<…>>` 500 levels deep (~4.5KB)
and compares the **last 501 chars** of the class's `toString` — exactly
what `char nb[224]` (applied-type name) and the two `char buf[160]`
toString buffers truncated away. The name is now built at its exact size,
and `[class N]` / `[object N]` go through one `tagged_class_string` helper
that sizes from the name length.

### Slice D — recompiler peephole for big literal runs (1 test)

`initializer_large_vector` has a **250,000**-element `new<int>[…]` literal.
One `Dup / PushInt <index> / PushInt <value> / SetPropertyFast` quad per
element expanded to a **2,025,185-line** C function; gcc ICEs (cc1
segfault) on it even at `-O0`, so there was no compiler-flag workaround.

A run of ≥ 64 consecutive-index writes of int constants through one
multiname now emits a static table plus a loop. Same order, same
semantics; the receiver is re-read from `stk[sp - 1]` exactly as each `Dup`
did, so the net stack effect is unchanged. Interleaved `DebugLine` ops are
skipped (they emit nothing). Bodies with an exception table are left alone
— they need a per-op `_tf.op_index` a collapsed loop cannot carry — as is
any run a branch targets from the inside.

Result on that file: **2,025,185 → 15,817 lines**; `gcc -O2 -c` goes from
an ICE to **0.7s**. This is generic AOT hygiene, not test-only: any content
with a big literal table hit the same wall.

## What the diagnosis got wrong

- **The "28-bit atom boundary" for slice B.1 does not exist.** The plan
  read the test's own comment ("The implementation does some case analysis
  at 28 bits") as meaning indices below ~2^28 keep taking the v10
  name-lookup path, and asked for a boundary pinned from `output.txt`. The
  data says otherwise: `max_int28_m1` = 268435454 is *below* 2^28-1 and
  still expects RANGE, and every valid-u32 read miss in the test expects
  RANGE. There is no boundary — valid u32 is the whole condition.
- **`AVM2_CLASS_FLAG_SEALED` was already set on Vector classes**
  (`vec_stamp_class`), and `object_is_dynamic` already consulted it and
  already exempted prototypes via `is_prototype`. The plan's suggested
  "flagging them may be the one-line fix" was moot; the bug was one level
  up, in the proto-chain *write* branch that never asked the question. That
  also made the "riskiest change" framing wrong in a useful way: the fix is
  a general sealed-object correctness fix, not a Vector special case, and
  it cost nothing across the corpus.

## Trap for the next arc: pick the baseline commit by results, not by fix

The plan named `9b6bbcb57` as the baseline. Diffing against it reported
**26 gains and 1 regression** (`as3/Array/insertremove`, pass →
output_mismatch) — all of it noise. `9b6bbcb57` is a *fix* commit; the
results file **as of that commit** is from the run that motivated the fix,
before the fix was ever graded. Its 11 phantom avm2 "gains" are exactly the
tests `9b6bbcb57` fixed, and its phantom "regression" is a test that was
already failing byte-identically (30766/30870 matching lines on both
sides).

The correct baseline is the commit immediately before your own work
(`67c21aabe` here), which carries the *merged* results of the run that
graded the previous arc. Against it: **+15, 0 regressions.**

Cost of getting this wrong: two full cache-free local reproductions of a
30,870-line test chasing a regression that did not exist. The tell was that
the 11 avm2 "gains" were verbatim the list in `9b6bbcb57`'s own commit
message.
