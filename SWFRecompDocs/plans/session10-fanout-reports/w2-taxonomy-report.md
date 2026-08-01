# w2-taxonomy — wave-2 batches B4 (sealed-receiver error taxonomy) and B7 (string temporaries)

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a00c2194aaded4491`
Base: `b007ee50d` (master). Runtime-only; `SWFRecomp/build` copied from the main
tree, no recompiler rebuild needed. No commits, no pushes.
Patches (all three verified with `git apply --check` against a **pristine**
`b007ee50d` checkout, so B4a and B4b can be landed independently or together):

| File | Contents |
|---|---|
| `w2-taxonomy.patch` | B4a + B4b combined (186 lines, the merge candidate) |
| `w2-taxonomy-b4a.patch` | B4a only (51 lines) |
| `w2-taxonomy-b4b.patch` | B4b only (140 lines) |

There is no B7 hunk — see §B7.

---

## Ledger

| Hunk | Files | Target | Baseline | After | Ship? |
|---|---|---|---|---|---|
| **B4a** — `toLocaleString` is not a class trait | `avm2_number.c` (+ the primitive guard in `avm2_ops.c`) | `from_avmplus/ecma3/Number/toLocaleString_rt` | `output_mismatch` 44/48 | **`ruffle_matched`** (measured) | YES |
| **B4b** — #1081 / #1069 discriminator is the multiname KIND | `avm2_ops.c` | `from_avmplus/as3/RuntimeErrors/Error1081ReadSealedErrorNs` | `output_mismatch` 0/1 | **`pass`** (measured) | (pending canaries) |
| **B7** — string temporaries never reclaimed | — | `from_avmplus/regress/bug_483783` | `runtime_error` | **NOT TAKEN — architecturally blocked** | NO |

Net measured trace movement: **+2** (one `pass`, one `ruffle_matched`).
B7's predicted +1 is not delivered; the `runtime_error` histogram bucket stays
at 1. See §B7 for why the report's "cheap probe" is not safe to ship.

---

## B4a — the write that must report #1056, not #1037

### What the diff actually was
`toLocaleString_rt` re-verified at baseline in this worktree, byte-identical to
the wave-1 report:

```
-  3 ... o.toLocaleString = s; o.toLocaleString() PASSED!
+  3 ... FAILED! expected: ReferenceError: Error #1056 got: ReferenceError: Error #1037
   (same on lines 4 and 5)
-  47 o=new Number(.00000012345);o.toLocaleString() PASSED!
+  47 ... FAILED! expected: 1.2345e-7 got: 1.2345000000000002e-7
```

Line 47 is the Ruffle-shared double-format difference: `diff output.txt
output.ruffle.txt` shows exactly that one line, so the ceiling for this test is
`ruffle_matched`, not `pass`. **That is the expected outcome and it is what was
measured.**

### The mechanism is NOT in the ops miss path
The wave-1 note pointed at `avm2_ops.c` setproperty (~860/3591) and
`avm2_error.c`. That is not where the #1037 comes from. `o:Number` is a
**primitive double** (`new Number()` in AS3 returns a primitive), the write
resolves `avm2_value_vtable()` → the **Number ivtable**, and finds a real
`AVM2_PROP_METHOD` entry, so `setproperty_resolved`'s `AVM2_PROP_METHOD` arm
throws #1037. The entry exists because `avm2_number.c:588` registered
`toLocaleString` as a public method trait.

The discriminator is which names are class traits at all, and the corpus pins
both sides of it:

* `ecma3/Exceptions/number_003_rt` — `o.valueOf = Number.prototype.valueOf` on
  `new Number()` expects **#1037**.
* `ecma3/Exceptions/number_004_rt` — `o.toString = …` on `new Number()`
  expects **#1037**.
* `ecma3/Number/toLocaleString_rt` — `o.toLocaleString = …` on `new Number()`
  expects **#1056**.

Same receiver, same shape, different property name ⇒ `toString`/`valueOf` are
traits, `toLocaleString` is not. That matches the AS3 class reference: neither
`Object` nor `Number`/`int`/`uint` lists `toLocaleString` — it exists only as an
ES3 **prototype function**. The codebase already encodes the same rule for
`Array.toString` (`avm2_array.c:1219-1224`) and for Date's opposite case
(`avm2_date.c:1073-1077`: Date's ES3 methods really *are* public traits, which
is the whole of `ecma3/Date/e15_9_5`).

### The change
1. `avm2_number.c` `add_number_methods()`: drop the
   `avm2_builtin_add_method(cls, "toLocaleString", …)` trait. The prototype
   entry `avm2_proto_add_function_n(proto, "toLocaleString", proto_to_string, 1)`
   two lines below already carries every *call*; its numeric arm is literally
   `number_to_string`, so behaviour for `n.toLocaleString()` is unchanged.
   Shared by Number, int and uint (all three call `add_number_methods`).
2. `avm2_ops.c` `setproperty_resolved()`: guard both proto-chain shadow-write
   branches with `recv.kind != AVM2_VALUE_OBJECT ||` before
   `object_is_dynamic(recv.u.obj)`. **This is a latent-UB fix, not cosmetics**:
   removing the trait makes a primitive receiver reach those branches for the
   first time, and `recv.u.obj` on a `NUMBER` value is a union re-read of a
   `double` — an arbitrary pointer that `object_is_dynamic` would dereference.
   With the guard the write falls into `setproperty_miss` → `class_name_of`
   → `Error #1056: Cannot create property toLocaleString on Number.`

---

## B4b — the #1081 / #1069 discriminator

### History honoured
`avm2_ops.c:668-682` records the earlier attempt: widening
`getproperty_common` to `!mn_public` won `Error1081ReadSealedErrorNs` and lost
`avm2/catch_class` + `AccStatPropViaSubClass`. That comment also asserted the
failing site "reads a PUBLIC name (`a.name`)". **That assertion is wrong**, and
the generated ABC says so.

### Evidence (confirmed independently this session)
`Main.as` does `var a:IClass = new ClassImpl(); a.name;`. In
`RecompiledABC/abc0_methods.c:1960` the site is

```
// 9: GetPropertyStatic mn[101] {ns-set 10}::name
```

and `abc0_tables.c`: `abc0_nsset_10[] = { 24 }`, `abc0_namespaces[24] = { 8, 23 }`
— ABC namespace kind `0x08` (a plain, non-public named namespace: `IClass`).
So the site is a **ns-set multiname carrying exactly one non-public namespace**.

The two casualties are QNames:
* `catch_class` → `abc0_methods.c:259`: `GetPropertyStatic mn[20]
  http://adobe.com/AS3/2006/builtin::hasOwnProperty` (prints `uri::name` ⇒
  one-namespace QName).
* `AccStatPropViaSubClass` → its three #1069 assertions are `obj.ns1::date`
  (explicit qualification ⇒ QName), `obj.string` and `this.foo` (public names,
  `mn_public == 1`).

### Ruffle agrees, and the flag name is a red herring
`core/src/avm2/object/script_object.rs:409-419` — on `!valid_dynamic_name()`
the code picks `InvalidNsRead` (#1081) when `has_multiple_ns()`, else
`InvalidRead` (#1069). `multiname.rs:239-260` sets `HAS_MULTIPLE_NS` for
`Multiname` / `MultinameA` / `MultinameL` / `MultinameLA` and **for no other
ABC kind, regardless of how many namespaces the set actually holds**. So
"multiple ns" means "ns-SET form", exactly the wave-1 hypothesis. avmplus's
`isAttr() || !containsAnyPublicNamespace()` is the `valid_dynamic_name` half.

### The change
* new `mn_is_nsset_kind(data, mn_idx)` → `k == 0x09 || 0x0e || 0x1b || 0x1c`;
* `getproperty_common` gains an `mn_nsset` parameter and the error code becomes
  `dynamic || mn_attr || (mn_nsset && !mn_public) ? 1081 : 1069`.
  The change is **purely additive** — no existing 1081 case is turned into a
  1069 — which is why the `dynamic` and `mn_attr` terms are kept rather than
  replaced by Ruffle's literal expression;
* the three runtime-namespace call sites (`getproperty_qname`,
  `avm2_op_getproperty_rtns`, `…_rtns_l`) pass `0`: Ruffle marks RTQName forms
  `IS_QNAME`, never `HAS_MULTIPLE_NS`.

---

## B7 — NOT TAKEN: the cheap probe is unsafe by construction

### Baseline re-verified
`from_avmplus/regress/bug_483783`, the corpus's only `runtime_error`.
`Test.as` is a single script-level statement: `for(var j:Number = 0; j <
3000000; j++) myString += "a";` then one `Assert.expectEq(…, myString.length)`.

### Why "GC pass + retry on `heap_alloc` failure" must not ship
The collector's own design forbids it. `SWFModernRuntime/include/avm2/avm2_gc.h:17-18`
and `src/avm2/avm2_gc.c:1-4`:

> "…collect only between ticks because method-body operand stacks/locals live
> on the C stack. The collector therefore runs from `runSWF_avm2`'s tick loop
> when the VM is quiescent (no method body on the C stack)."

That is literally true of the emitted code. Every recompiled method body is

```c
static Avm2Value abc0_mNN(Avm2Activation* act)
{
    Avm2Value loc[N];
    Avm2Value stk[M];
    uint32_t sp = 0;
    …
}
```

`loc[]` and `stk[]` are plain C locals. `Avm2Activation`
(`include/avm2/avm2_abc.h:643-653`) carries `ctx / file / bound_class / outer /
this_val / args / argc / callee` and **no pointer to `loc` or `stk`**, and
there is no activation chain to walk. `avm2_gc_mark_roots_*` therefore cannot
see them.

`myString` in this test lives in exactly one place during the loop: a `loc[]`
slot on the C stack. A collect triggered from inside the failing
`heap_alloc` — i.e. from inside `avm2_string_concat`
(`avm2_value.c:141-173`) — would find the accumulated string unreachable and
the string sweep (`avm2_gc.c:842-860`) would `heap_free` it, after which
`concat` `memcpy`s from freed memory. The probe would not "tell you whether
intermediates are collectable"; it would produce a use-after-free whose most
likely symptom is a *passing-looking* wrong answer.

Nor is the arena the problem: retaining every intermediate for 3 000 000
appends is Σ(1…3e6) ≈ **4.5 TB**. No heap size and no `ulimit` change reaches
it. Only reclamation or an in-place/rope representation can.

### What the real fix is (arc, not batch)
Two candidate designs, both larger than this batch:

1. **Precise shadow stack.** Every generated method already calls
   `avm2_setup_locals(loc, N, act, id)` at entry — make that register
   `(loc, N, stk, M)` in a global frame list and unregister on every return
   path (and on exception unwind), then mark those arrays as roots. Requires
   zero-initialising `stk[]` (marking uninitialised `Avm2Value`s would follow
   garbage kind tags), recompiler emission changes, and a per-call cost on the
   hottest path in the VM.
2. **Conservative C-stack scan.** The two primitives already exist and are
   already used by the "conservative ext scan": the O(1) arena-membership
   bitmap (`avm2_gc.c:131-195`, `bm_test`) and the sorted string-span snapshot
   (`avm2_gc.c:341-370`). Add a stack base recorded at VM entry, `setjmp` to
   spill callee-saved registers, and scan `[sp, base]`. This makes
   mid-execution collection sound and is the smaller of the two, but it changes
   when the collector may run for *every* AVM2 title, so it needs its own
   measurement pass (pause time, over-retention) rather than a canary sweep.

Either way, this is the "make AVM2 GC run during long-running script loops"
arc. Recommend it be scoped as such; do not re-file it as a near-pass batch,
and do not let a later session ship variant (b) of the wave-1 note.

---

## Canary results

Baselines are the master `results_graphics.json` at `feb8882b0` /
`b007ee50d`; "after" is a local `verify_output.py` run in this worktree with
the full patch (B4a + B4b) applied.

### The four MANDATORY B4b canaries — all green, so B4b ships

| Test | Baseline | After |
|---|---|---|
| `avm2/catch_class` | pass | **PASS** |
| `avm2/dictionary_access_no_pubns` | pass | **PASS** |
| `from_avmplus/as3/Definitions/Classes/Ext/AccStatPropViaSubClass` | pass | **PASS** |
| `from_avmplus/as3/Vector/bug_678952` | pass | **PASS** |

### Targets

| Test | Baseline | After |
|---|---|---|
| `from_avmplus/ecma3/Number/toLocaleString_rt` | output_mismatch 44/48 | **ruffle_matched** |
| `from_avmplus/as3/RuntimeErrors/Error1081ReadSealedErrorNs` | output_mismatch 0/1 | **pass** |
| `from_avmplus/regress/bug_483783` | runtime_error | runtime_error (unchanged — B7 not taken; re-measured `ERROR: heap_alloc(76398) failed - out of memory`, identical to wave 1) |

### Batch sweeps — zero regressions everywhere

| Suite batch | n | Baseline mix | After mix | Regressions |
|---|---|---|---|---|
| `from_avmplus` | 42 | 40 pass + 2 ruffle_matched | 40 pass + 2 ruffle_matched, 0 fail | **0** |
| `avm2` (taxonomy + toLocaleString users) | 13 | 10 pass + 1 rm + 2 mismatch | 10 pass + 1 rm + 2 mismatch | **0** |
| `avm2` (interface / error-code batch) | 9 | 7 pass + 1 rm + 1 mismatch | 7 pass + 1 rm + 1 mismatch | **0** |
| `avm1` | 2 | 2 output_mismatch | 2 MISMATCH | **0** |
| `regression` | 70 | 70 pass | **70 pass**, every row `vs prev: no changes` | **0** |

The two pre-existing `avm2` failures reproduced unchanged (`error_throwerror`,
`tab_ordering_properties`), as did `avm2/avm1_root` and both `avm1`
`global_proto_decls*` — all were already `output_mismatch` at baseline. The two
`ruffle_matched` rows that stayed `ruffle_matched` are
`from_avmplus/ecma3/Array/toLocaleString` and `from_avmplus/misc/bug_508617`
(plus `avm2/array_access_oob_interpreter` and
`avm2/weird_superinterface_properties`) — the `ruffle_matched`-hides-a-regression
trap was checked per row, not just on the totals.

The decisive B4a rows are worth naming individually, since they are the ones
that could have flipped: `ecma3/Exceptions/number_003_rt` **PASS** and
`number_004_rt` **PASS** (they pin #1037 for `o.valueOf =` / `o.toString =` on
`new Number()` — i.e. the trait side of the split B4a introduces),
`ecma3/Number/ecma4_sealedtype_4_rt` **PASS** (#1056 write / #1069 read on a
primitive Number), `ecma3/Date/e15_9_5` and `e15_9_5_5` **PASS** (Date's ES3
methods must stay public traits), and every `toLocaleString` consumer:
`ecma3/Array/toLocaleString`, `ecma3/ObjectObjects/toLocaleString_rt`,
`ecma3/Number/toLocaleString{2,3,4}_rt`, `avm2/{array,class,function,object}_to*locale*`,
`avm2/vector_tostring` — all at baseline.

**How the regression suite was run.** Its first pass was interrupted twice
(once by a `git stash` used to prove the split patches apply to a pristine
tree, once when the lane's parent shell was reaped), so it was completed in
three segments — tests 1-19, then `--start=19 --count=26` and
`--start=45 --count=26` run concurrently. All 70 tests pass and every row
reports `vs prev: no changes`. Raw output:
`scratchpad/w2_out_regression.txt`, `w2_out_reg_a.txt`, `w2_out_reg_b.txt`.
NOTE for whoever lands this: the split halves wrote `--json` to the
scratchpad, but `verify_output.py` also refreshes the suite's own
`_results/results.json` + `results_previous.json`. Those were restored from
git in this worktree, so the deliverable patch is source-only — do not carry a
results-file diff into the merge.


## Source-grep census (the session-1 "PASSED!" trap)

`toLocaleString_rt`'s expected output is 48 lines of `… PASSED!` — the error
code it pins is invisible in `output.txt`. So the canary set was built from the
**sources**, not the expectations:

```
grep -rl --include=*.as --include=*.txt -E "Error #(1056|1037|1069|1081)" tests/swfs
```

→ **51 test directories** (13 `avm2`, 37 `from_avmplus`, 1 `from_shumway`).
Full list: `scratchpad/w2_errcode_dirs.txt`. Every one of them that is
reachable by the changed code paths is in the canary list below; the
`from_shumway/localconnection` and `avm2/localconnection` /
`filereference_*` / `avm1_root` / `set_local_0` / `verify_abnormal_loop` hits
are unrelated error sites (they name the codes in prose or in unrelated
assertions) and were not run.

A second census over `toLocaleString` (all suites, sources + expectations)
found 24 directories; all of the AVM2 ones are in the canary list.

## Merge risks

1. **`avm2_ops.c` is a hot file this wave.** B4a's guard and B4b both edit
   `setproperty_resolved` / `getproperty_common` / the `mn_*` helper block near
   the top. Any other agent touching the getproperty miss path will conflict
   textually; the semantic risk is that a *different* batch also changes the
   1069/1081 split. B4b is additive and keyed on a fact (the ABC multiname
   kind) that nothing else in the tree reads, so a semantic clash is unlikely.
2. **B4a changes a builtin class's trait table.** The observable side effects
   beyond the error code are `hasOwnProperty` on a Number/int/uint instance for
   the name `toLocaleString` (now `false`, which is what avmplus reports) and
   `avm2_vtable_find_public` consumers (the Flixel fingerprint gate — it does
   not fingerprint `toLocaleString`). Anyone landing a *new* `hasOwnProperty`
   or fingerprint test in the same wave should re-check.
3. **B4b widens an error code, and error codes are load-bearing in
   `from_avmplus`.** This is a `categories=full` change: the classic five
   suites do not cover `from_avmplus`, where most of the #1069/#1081
   assertions live. CI should dispatch `mode=graphics` with
   `categories=full`.
4. Neither hunk touches the recompiler, so no `cmake` rebuild and no
   `--recompile` sweep is required for the merged wave.
