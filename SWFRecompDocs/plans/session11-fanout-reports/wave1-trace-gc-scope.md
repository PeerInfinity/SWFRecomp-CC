# wave1-trace-gc-scope — scoping the "GC during long loops" arc (trace lead B7)

Session 11, wave 1. Read-only: no source edits, no commits. Base `b4c983ea4`
(= origin/master), CI baseline run `30713776612` at `c4496a4c8` (trace
4188/4424, pixels 217/566).

Prior art read first, as instructed:
`SWFRecompDocs/plans/session10-fanout-reports/w2-taxonomy-report.md` §B7.

---

## 0. Verdict up front

**NO-GO for a wave-2 slice this session, and NO-GO for the arc as framed.**

The arc has **zero corpus yield**. Its single named target,
`from_avmplus/regress/bug_483783`, is **not a GC bug at all** and cannot be
made to pass by any collector, however sound. Two of the four premises the
brief carried forward from the session-10 postmortem are factually wrong for
this test, and the third (the case for a shadow stack) is refuted by the
runtime's own structure.

The one real, correctly-owned piece of work here is a **string-append
complexity** arc (O(n²) → O(n) via dependent strings over a growable buffer),
which is a different arc with a different owner and a poor cost/benefit at
+1 test. Details and sizing in §5.

---

## 1. Census — verified

### 1.1 Corpus-wide status histogram at `b4c983ea4`

Computed over every `_results/results_graphics.json` in the tree (24 files,
4534 rows incl. nested double-counting; the 4424 denominator is the
de-duplicated corpus — see the `denominator` memory note):

| Status | Count |
|---|---|
| `pass` | 4051 |
| `ruffle_matched` | 247 |
| `output_mismatch` | 235 |
| **`runtime_error`** | **1** |
| `timeout` | 0 |
| `runtime_segfault` | 0 |
| `compile_fail` / `recomp_fail` | 0 |

**There is exactly one non-`output_mismatch` failure in the entire corpus.**
No timeouts, no segfaults, no OOM-shaped failures anywhere else.

### 1.2 The single candidate, verified at HEAD

| Test | Suite | Status @ HEAD | Evidence |
|---|---|---|---|
| `regress/bug_483783` | `from_avmplus` | `runtime_error` | `ERROR: heap_alloc(76398) failed - out of memory`, exit 1, `[0/0 lines]`, `r=0.03s c=132.05s x=9.39s` |

Command run (single test, per the rules):

```
python3 ruffle-tests/verify_output.py --test=regress/bug_483783 \
        --tests-dir=ruffle-tests/tests/swfs/from_avmplus --diff --verbose
```

Byte-identical to the session-10 measurement. Not in
`ruffle-tests/ignored_tests.txt` (188 lines; no memory/OOM/timeout entries at
all — the only timeout comment there says "timeout removed"). Not present in
any of the four avm1 disposition docs (`ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`) — checked; it is a `from_avmplus` test and those
docs are avm1-scoped.

### 1.3 Adjacent shapes checked and cleared

* **Truncated-output mismatches** (a run that died mid-way would look like
  `actual_lines << expected_lines`): 40 such rows exist, every one with
  `phases.run ≤ 0.7s`. None is a memory death; they are the
  `all_classes/*`, `describe_type_*`, `acid/*` capability gaps.
* **Run-phase outliers**: max `phases.run` in the whole corpus is **6.63s**
  (`avm1/swf4_function_calls`), and the top 20 are all `pass`. Nothing is
  sitting near the 30s wall clock.
* **Other big-loop-bound `from_avmplus` tests** (`grep` for loop bounds ≥ 10⁶):
  `regress/bug_703238`, `ecma3/Date/e15_9_1_1_1`, `ecma3/Expressions/e11_8_1`,
  `e11_8_3`, `as3/Math/op_subtract_703238`, `op_divide_703238` — **all six
  `pass`**. `bug_703238`'s "big" loop steps by 86400000 and runs 9 times.
* **Games / titles**: no documented runtime OOM-inside-a-method exists.
  `SWFRecompDocs/games/FLASHARCHIVE_BUILD_RESULTS.md`'s only OOM is `emcc`
  at *compile* time on a 305 MB generated `draws.c`. The near-capacity case
  the collector already handles (`rwic` live set ~1.7 GB of a 1770 MB heap)
  is a *between-ticks* retention problem, already solved by the adaptive
  watermark (`avm2_gc.c:47-60`).

**Census total: 1 test. Flippable by this arc: 0 (see §2).**

---

## 2. Refutations

### R1 (REFUTED) — "`myString` lives in a `loc[]` slot on the C stack"

The session-10 postmortem states: *"`myString` in this test lives in exactly
one place during the loop: a `loc[]` slot on the C stack."* This is **wrong**.

`myString` is a script-level `var`, so ASC compiles it to a **trait slot on the
script's global object**, not to a local. From the checked-in emission,
`ruffle-tests/tests/swfs/from_avmplus/regress/bug_483783/RecompiledABC/abc0_methods.c`:

```c
op_44:;
	// 45: GetGlobalScope
	stk[sp++] = avm2_object_value(avm2_op_getglobalscope(act, lscope, scope_n));
	// 46: GetSlot slot=1
	stk[sp - 1] = avm2_op_getslot(act, stk[sp - 1], 1);
	// 47: PushString str[67] "a"
	stk[sp++] = avm2_string(&act->file->data->strings[67]);
	// 48: Add
	sp--; stk[sp - 1] = avm2_op_add(act, stk[sp - 1], stk[sp]);
	// 49: GetGlobalScope
	...
	// 51: SetSlot slot=1
	sp -= 2; avm2_op_setslot(act, stk[sp], 1, stk[sp + 1]);
```

`loc[2]` is the loop counter `j`'s temporary and is `Kill`ed at op 60. The
accumulator is **slot 1 of the global object**, which is a first-class GC root:
`avm2_gc_mark_roots_globals` (`avm2_globals.c:1972`) marks every
`ctx->domain.scopes` object, and object slots are traced precisely
(`avm2_gc.c:476`: `for (i < o->slot_count) avm2_gc_mark_value(o->slots[i])`).

**Consequence:** the session-10 "GC-on-alloc-failure probe would be a
use-after-free" argument does **not** hold *for this test*. A collect triggered
inside `avm2_string_concat` would have found the accumulator live in slot 1 and
freed only the genuinely-dead intermediates. The probe was not taken for the
right reason (see R2) but the stated reason is not the reason.

The *general* claim in the brief — that AVM2 method locals are invisible to the
collector — remains true and is CONFIRMED (§3.1). It just does not bind here.

### R2 (REFUTED — the load-bearing one) — "GC would flip this test"

**Reclamation removes the memory wall and leaves a wall-clock wall that is
~30× worse.**

`myString += "a"` × 3 000 000 with an immutable, always-copying string
(`avm2_string_concat`, `avm2_value.c:141-173`, two `memcpy`s into a freshly
`avm2_alloc`'d `sizeof(Avm2String) + total + 1`) copies

    Σ(1…3·10⁶) ≈ 4.5 × 10¹² bytes = 4.5 TB

regardless of whether the intermediates are reclaimed. Measured on this box
with a C model of exactly that loop **including perfect reclamation** (malloc
n+1, memcpy n, free old — scratch `bench.c`):

| N | wall | bytes copied | effective |
|---|---|---|---|
| 100 000 | 0.467 s | 5.0 GB | 10.7 GB/s |
| 200 000 | 3.402 s | 20 GB | 5.9 GB/s |
| 400 000 | 15.815 s | 80 GB | 5.1 GB/s |

Throughput *falls* as the working set leaves cache. Extrapolating the measured
5 GB/s to 4.5 TB gives **≈ 900 s ≈ 15 minutes**; the optimistic 10.7 GB/s
in-cache figure still gives **≈ 420 s**. That is the *model*, with no AVM2 op
dispatch, no `avm2_alloc`, no GC cycles.

`verify_output.py`'s run wall-clock is **30 s** (`run_binary`,
`proc.wait(timeout=30)` at line 3142; a trip is graded `timeout` with detail
`"runtime timeout (>10s)"`). The required speedup is **≥ 30×** past what any
collector can deliver.

**A perfect collector converts `runtime_error` → `timeout`. That is a lateral
move in the histogram, not a flip.** It would also introduce the corpus's first
`timeout` bucket entry, which by the `transition-diff` memory note is a
histogram change worth avoiding for zero gain.

Corroborating arithmetic on the current failure: the run dies at
`heap_alloc(76398)`, i.e. at j ≈ 76 397, having allocated Σ(1…76397) ≈ 2.9 GB —
exactly consistent with the 4 GB native arena
(`heap.c:88 DEFAULT_FULL_HEAP_SIZE = 4 GB`). Enlarging the heap cannot help:
4.5 TB has no `ulimit`.

### R3 (REFUTED) — "shadow stack vs conservative scan are the two candidate designs"

A **precise shadow stack over `loc[]` / `stk[]` / `lscope[]` is unsound in this
runtime, at any safepoint placement**, because the *runtime's own C functions*
hold live `Avm2Value`s in their C locals across calls that can re-enter emitted
AS3 code. Concrete, from the very op this arc is about
(`avm2_value.c:877-894`, `avm2_op_add`):

```c
if (a.kind == AVM2_VALUE_STRING)
    return avm2_string(avm2_string_concat(ctx, a.u.str, avm2_coerce_to_string(ctx, b)));
...
Avm2Value pa = avm2_coerce_to_primitive(ctx, a, 0);
Avm2Value pb = avm2_coerce_to_primitive(ctx, b, 0);
```

`avm2_coerce_to_string`'s freshly-minted string is a pure C temporary — in no
`stk[]` slot — while `avm2_string_concat` allocates. And
`avm2_coerce_to_primitive` (`avm2_value.c:659-664`) calls
`avm2_call_public_property(ctx, v, "valueOf"/"toString", …)`, i.e. **user AS3
code runs with `v` and `prim` live only in `avm2_value.c`'s frame**. Any
safepoint reachable from that AS3 body would collect them.

There is a second, independent hole in the precise design: the emitted call
convention puts arguments **above `sp`**:

```c
// 17: CallPropVoid mn[7] trace, args=1
{ static Avm2InlineCache __ic; sp -= 2; avm2_op_callproperty_ic(act, stk[sp], 7, &stk[sp + 1], 1, &__ic); }
```

`sp` is decremented *before* the call, so `stk[sp]` (receiver) and
`stk[sp+1..]` (args) are outside a `[0, sp)` live prefix. Marking `[0, max_stack)`
instead requires zero-initialising `stk[]` on every call — and `avm2_setup_locals`
already documents the locals memset as a measured hot spot (*"the RWK plan_k TAS
runs 50.7M setup_locals calls / 1560 ticks"*, `avm2_function.c:100-107`).

So the real design space is **conservative C-stack scan** vs **boundary-only
collection (status quo)**. The shadow stack is not a third option unless it is
extended into several hundred runtime functions — which is not an arc, it is a
rewrite.

### R4 (partially REFUTED) — "never propose GC-on-alloc-failure"

The prohibition is a consequence of the *current precise root model*, not a law.
Under a conservative C-stack scan, collecting from inside `heap_alloc` is
**sound by construction** — that is precisely what conservative scanning buys.
The rule should be restated as: *"GC-on-alloc-failure is unsafe until the root
set covers the C stack."* Stated as an absolute it will mislead a future
session into rejecting the one design that works.

(This does not change the go/no-go: R2 kills the payoff regardless.)

---

## 3. Design comparison, with evidence from the emitted code

### 3.1 What the emitted code actually gives the collector — CONFIRMED

Every method body has this shape (verified across several `RecompiledABC`
outputs, e.g. `avm2/boolean_constr`, `from_avmplus/regress/bug_483783`), emitted
by `SWFRecomp/src/abc/abc_emit.cpp:2447`:

```c
static Avm2Value abc0_mNN(Avm2Activation* act)
{
	Avm2Value loc[N];
	Avm2Value stk[M];          // UNINITIALISED
	uint32_t sp = 0;
	Avm2ScopeEntry lscope[K];  // UNINITIALISED
	uint32_t scope_n = 0;
	avm2_setup_locals(loc, N, act, NN);
	...
}
```

`avm2_setup_locals` zero-fills `loc[]` (`memset`, `avm2_function.c:105`) but
**nothing zero-fills `stk[]` or `lscope[]`**. `Avm2Activation`
(`avm2_abc.h:643-653`) carries no pointer to any of them. Control flow inside a
body is `goto op_NN;` — plain C labels, no interpreter loop, **no back-edge
hook of any kind** (grepped `abc_emit.cpp` for `backedge`/`loop_check`/
`script_timeout`: nothing). So there is currently no place to *put* a safepoint
without new emission.

Exception unwind is `setjmp`/`longjmp` (`avm2_error.h:17-44`, `avm2_error.c:290,308`),
so any push/pop-on-return shadow-stack discipline is skipped wholesale by a
throw. The codebase already carries the mitigation pattern for its own try-frame
list (`avm2_error.c:235`: *"Frames above tf (from callees that longjmp'd past
their pop) are …"*), so this is solvable — but it is one more thing the precise
design must get exactly right and the conservative design gets for free.

### 3.2 Conservative C-stack scan — the primitives already exist

Everything needed is present and already load-bearing for the ext scan:

| Primitive | Where | Note |
|---|---|---|
| O(1) arena-membership bitmap `bm_test` | `avm2_gc.c:186-195` | 1 bit / alignment cell, set on enroll, cleared on sweep; rejects non-arena and misaligned words first |
| `census_contains(p)` | `avm2_gc.c:419-431` | bitmap, with a sorted-snapshot fallback under `HEAP_PASSTHROUGH` |
| Interior-pointer string lookup `avm2_gc_mark_string_bytes` | `avm2_gc.c:376-400` | range binary search over the per-cycle sorted string census, gated by an O(1) `lo/hi` bounds test |
| The word-scan loop itself | `conservative_scan`, `avm2_gc.c:437-454` | `memcpy` a word, `census_contains` → mark object, else `mark_string_bytes` |

A stack scan is literally `conservative_scan`'s body over `[approx_sp, stack_base]`
plus a `setjmp` to spill callee-saved registers. The collector is **non-moving**
(mark-sweep, epoch marks) — the precondition conservative scanning needs.

The design's own safety statement is already written down in
`avm2_gc.h:26-31`: *"Conservative scanning can only over-retain (bounded), never
free a live object."*

**What it would cost / risk**
* Changes *when* the collector may run for **every** AVM2 title → needs its own
  pause-time and over-retention measurement pass (the arc's real work), not a
  canary sweep.
* Over-retention from stale stack slots is unbounded in principle for a deep
  stack; in practice bounded by stack depth × slots.
* `ulimit -s` / wasm stack base discovery, and the wasm story is different
  again (the memory note `stack-64kb` records a 64 KB wasm stack).
* Under sanitizer builds the arena is absent (`HEAP_PASSTHROUGH`, `g_bm == NULL`)
  and the scan degrades to per-word binary search — acceptable, but the
  ASan-blind caveat in `graphics-sigabrt-real-heap-bugs` applies.

### 3.3 Boundary-only collection (status quo) — and why "collect between methods" does not help

The brief floats "collect only at frame boundaries / between methods where no
AVM2 frame is live". That is *exactly what ships today* (`avm2_gc_maybe_collect`
is called from two sites, both in `avm2_main.c`'s tick loop: lines 628, 714).
"Between methods" is not a stronger position than "between ticks" for the hard
case, and the hard case — unbounded allocation inside one long-running method —
is the whole of the census (§1.2). So this is a no-op design.

### 3.4 Summary

| Design | Sound here? | Emission change | Runtime blast radius | Fixes the census |
|---|---|---|---|---|
| Precise shadow stack (`loc`/`stk`/`lscope`) | **No** — R3 | yes (register/unregister + `stk` zero-fill) | ~hundreds of runtime fns to audit | no (R2) |
| Conservative C-stack scan | Yes | none | collector only (~150 lines) + a measurement pass | no (R2) |
| Boundary-only / between-methods | Yes | none | none | no — is the status quo |
| **Dependent strings / growable buffer** (§5) | Yes | none | string repr + GC string census + NUL audit | **yes** (and needs no GC at all) |

---

## 4. What actually owns `bug_483783`

With an amortised append the test needs **~6 MB peak** and **O(n) total copy**,
and therefore **needs no collector at all** — the 3 M dead 24-byte headers total
72 MB, comfortably inside a 4 GB arena. This is a string-representation problem
end to end.

The sound shape (this is avmplus's own design, which is why Tamarin runs this
test in seconds):

* `avm2_string_concat(a, b)`: if `a` owns the tail of a growable byte buffer
  with spare capacity, write `b`'s bytes at the buffer's used-end (geometric
  growth on overflow) and mint a **new header** with
  `utf8 = a->utf8, len = a->len + b->len`. `a` is never mutated — it only ever
  reads its first `a->len` bytes — so immutability is preserved.

Sizing evidence gathered:

* `Avm2String` (`avm2_value.h:36-42`) is `{ len, utf8, gc_next, gc_flags }`;
  bytes are inline and the GC's O(1) fast path keys on exactly that invariant
  (`avm2_gc.c:402-408`: `s->utf8 == (const char*)(s + 1)`). Dependent headers
  break the fast path and must (a) mark themselves *and* (b) mark their buffer
  owner; the range lookup must use **capacity**, not `len`.
* **NUL termination is the sharp edge.** A dependent's `utf8[len]` is the next
  string's first byte, not `'\0'`. Sites that treat `utf8` as a C string:
  **~14** (`strlen`/`strcmp`/`strstr`/`strchr`/`%s`/`atof` against `utf8` across
  `src/avm2/*.c`). Each needs `%.*s`-style length-explicit handling or an
  `avm2_string_cstr()` copy. Total `->utf8` references: **516 across 26 files** —
  but the overwhelming majority are `(ptr, len)` pairs and are unaffected.
* By-value `Avm2String` copies: exactly **one** field in the tree
  (`avm2_object.h:30`, `Avm2DynProp.name`). Small, contained risk.
* The alternative (ropes with lazy flatten) would touch all 516 sites. Rejected.

**Sizing: 2–3 sessions** — (1) representation + concat + GC census/marking/sweep,
(2) NUL audit + full-suite canaries, (3) perf/regression. **Yield: +1 test
(0.02%).** Recommend **do not schedule on corpus grounds**; revisit only if an
AVM2 title's profile shows string building as a hot spot (none does today —
`browser-perf-is-writebuffer-not-avm1-walks`).

---

## 5. Sized arc plan (if the GC arc is ever taken on non-corpus grounds)

Only justification left is robustness/perf for AVM2 titles, which today has
**no evidence behind it** (§1.3). If it is ever taken:

| Slice | Content | Size | Risk |
|---|---|---|---|
| G1 | Stack-base capture at VM entry + `setjmp` spill + `gc_scan_stack()` reusing `census_contains` / `avm2_gc_mark_string_bytes` | ~150 lines, `avm2_gc.c` + `avm2_main.c` | LOW to write |
| G2 | Move the collect trigger from the tick loop to `avm2_alloc` watermark crossings; keep tick-loop calls | ~30 lines | **HIGH** — changes collection timing for every title |
| G3 | Measurement pass: pause-time distribution, over-retention ratio, RWK/Seedling duty cycle A/B (per `avm2-rw-gc-duty-cycle` + `avm2-gc-tier2-collector-cost`) | 1 session | — |
| G4 | wasm story: stack base under emscripten, 64 KB stack, `HEAP_PASSTHROUGH` fallback | 1 session | MEDIUM |

**Total: 2–3 sessions for zero corpus movement.** G1 alone (conservative scan
implemented but the trigger left at tick boundaries) is a no-op that only adds
over-retention — it is not a shippable half.

---

## 6. Go / no-go for a wave-2 slice this session

**NO-GO.** Explicitly:

* There is no minimal safe slice with a measurable outcome. The arc's entire
  census is one test that a correct collector converts from `runtime_error` to
  `timeout` (R2) — a histogram change with negative sign.
* The cheapest *correct* thing (conservative stack scan, G1) cannot be validated
  by a canary sweep, only by a measurement pass, and by construction produces
  **zero** trace movement. Handing it to a worktree agent would burn a session
  and land an unmeasurable change in the most safety-critical file in the AVM2
  runtime.
* The thing that *would* flip the test (dependent strings) is a 2–3 session arc
  touching the GC's string census, and is worth +1 test. It is not a
  one-agent slice, and a wrong "yes" here is exactly the use-after-free hunt the
  brief warned about — a dependent-string bug shows up as silently corrupted
  string contents, not a crash.

**Recommended board edit** for `polish-sweep-arc.md` §11.3: replace the row
`B7 → the GC arc (shadow stack vs conservative C-stack scan)` with

> `bug_483783` is a **string-append complexity** problem (O(n²) copy = 4.5 TB,
> ≈900 s measured-model wall vs a 30 s harness limit), not a GC problem. GC
> converts it `runtime_error` → `timeout`. Owner: a dependent-string /
> growable-buffer arc, 2–3 sessions for +1 test — **not scheduled**. The
> "GC during long loops" arc has **zero** corpus census; take it only on title
> robustness grounds, and if taken, the design is a **conservative C-stack
> scan** (the precise shadow stack is unsound — runtime C frames hold live
> values across re-entry into AS3, `avm2_value.c:659-664`).

---

## 7. Risks and canaries (for whoever ignores §6)

* **Canary set for any collector-timing change** (all currently `pass`, all
  allocation-heavy, all cheap to run individually):
  `from_avmplus/regress/bug_703238`, `avm2/away3d_advanced_shallow_water_demo`,
  `from_shumway/acid/acid-large`, `avm2/bitmapdata_accuracy`,
  `avm1/bitmap_data_pixeldissolve`, plus the whole `regression` suite
  (70 tests, all `pass` — the `stash-diff-sweep` note requires it).
* **`AVM2_GC_STRESS=1`** already exists as the honest-failure tripwire
  (`avm2_gc.c:96-106`: watermark 0, sweep budget 0 → full mark-sweep every
  tick). Any conservative-scan change must be run under it.
* **`ruffle_matched` rows must be re-read per row**, not by total — a collector
  bug that corrupts one traced string can move a `pass` to `ruffle_matched`
  invisibly (`ruffle-matched-hides-regression`).
* **ASan is blind here** (`graphics-sigabrt-real-heap-bugs`): under
  `HEAP_PASSTHROUGH` there is no arena, `g_bm` stays NULL, and the code path
  under test is not the one that ships.
* **Do not run a full suite locally** to validate any of this; dispatch
  `ruffle-tests.yml` with `mode=graphics categories=full` (this is AVM2 runtime
  code, per the CI-categories policy).

---

## 8. Verdict ledger

| # | Claim | Verdict | Evidence |
|---|---|---|---|
| 1 | AVM2 method locals hold no refcount and are invisible to the collector | **CONFIRMED** | `abc0_methods.c` shape; `Avm2Activation` has no `loc`/`stk` pointer; `avm2_gc.h:15-20` |
| 2 | `stk[]` and `lscope[]` are uninitialised; call args live *above* `sp` | **CONFIRMED (new)** | emitted `sp -= 2; avm2_op_callproperty_ic(act, stk[sp], …, &stk[sp+1], …)` |
| 3 | Exceptions unwind by `longjmp`, so return-path pops are skipped | **CONFIRMED (new)** | `avm2_error.h:17-44`, `avm2_error.c:290,308` |
| 4 | `myString` lives only in a C-stack `loc[]` slot | **REFUTED** | it is global-object **slot 1**; `avm2_globals.c:1972`, `avm2_gc.c:476` |
| 5 | A GC arc would flip `bug_483783` | **REFUTED** | 4.5 TB copy; measured 15.8 s at N=400k → ≈900 s at N=3M vs a 30 s harness wall (`verify_output.py:3142`) |
| 6 | Shadow stack and conservative scan are the two candidate designs | **REFUTED** | precise shadow stack unsound: `avm2_coerce_to_primitive` re-enters AS3 holding C locals (`avm2_value.c:659-664`); `avm2_op_add` temporaries (`avm2_value.c:877`) |
| 7 | "Never propose GC-on-alloc-failure" | **REFUTED as an absolute** | sound under a conservative C-stack scan; restate as conditional on the root model |
| 8 | "Collect at frame boundaries / between methods" is a candidate | **REFUTED** | that is the shipping design (`avm2_main.c:628,714`) and does not address the census |
| 9 | The collector's conservative primitives are reusable for a stack scan | **CONFIRMED** | `bm_test` `avm2_gc.c:186`, `census_contains` `:419`, `avm2_gc_mark_string_bytes` `:376`, `conservative_scan` `:437` |
| 10 | Corpus census of this arc | **1 test, 0 flippable** | full histogram §1.1; single `runtime_error` re-verified at HEAD |

---

### Files touched by this agent

Only this report. No source edits, no commits. Scratch (throwaway):
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/3e4bf81b-3bd5-470b-9b99-7752ae37e567/scratchpad/bench.c`.
