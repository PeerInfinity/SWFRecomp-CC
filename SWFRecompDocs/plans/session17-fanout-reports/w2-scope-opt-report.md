# w2-scope-opt — `avm2/scope_optimizations` (session 17, wave 2)

## NEW FILES CREATED BY THIS PATCH

**None.** The patch touches exactly one existing file:

```
SWFRecomp/src/abc/abc_emit.cpp   (+207 / -4)
```

Recompiler-only. No runtime source, no header, no CMake/Emscripten source-list
change, no generated file. `git apply --stat w2-scope-opt.patch` shows the one
file, and `git add SWFRecomp/src/abc/abc_emit.cpp` is the whole staging step.

## VERDICT: **GO** — +1, zero regression surface (proved, not estimated)

| | |
|---|---|
| Patch | `SWFRecompDocs/plans/session17-fanout-reports/w2-scope-opt.patch` |
| Flip | `avm2/scope_optimizations` `output_mismatch` → **pass** |
| Corpus emission A/B | **4493 SWFs recompiled old vs new — exactly 1 test's C changes** |
| Changed lines in that test | 3 (in `RecompiledABC/abc0_methods.c`) |
| Recompiler failures introduced | 0 / 4493 |
| Canary set | 12 `with`-scope / nested-closure / outer-scope tests, all `pass` before and after |
| CI mode for the merged run | `graphics`, **`categories=full`** (AVM2 recompiler emission) |

---

## 1. Before/after ledger

| test | baseline (`results_graphics.json` @ `c7b284034`) | with patch | evidence |
|---|---|---|---|
| `avm2/scope_optimizations` | `output_mismatch` (line 4: `0`, want `[class field]`) | **PASS** | `scratchpad/w2scopeopt/{baseline_headline,new2_headline}.log` |

Baseline diff, reproduced locally at `88ebde665` with the unpatched recompiler:

```
     1  Without coerce:
     2  0
     3  With coerce:
-    4  [class field]
+    4  0
```

Nothing else in the corpus changes — see §4. This is a **+1 with a proved
ceiling of +1 and a proved floor of 0 regressions**, not an estimate.

---

## 2. Premise attacked, and it survived exactly

The brief's mechanism claim was checkable to the opcode, so I checked it before
writing any code (`SWFRecomp/build/SWFRecomp --dump-abc .../scope_optimizations/test.swf`).
Method 10 = `Test/Test`, `scope=9..11`:

```
  0: GetLocal r0        1: PushScope          # lscope[0] = this (Test)
  5: FindPropStrict Subclass
  6: ConstructProp  Subclass, args=0
  7: PushScope                                # lscope[1] static type = Subclass
  8: FindPropStrict trace
  9: FindPropStrict mn[4] field               # Subclass HAS `field` -> hit -> "0"  (correct)
 10: GetPropertyStatic mn[4] field
 12: PopScope
 17: FindPropStrict Subclass
 18: ConstructProp  Subclass, args=0
 19: Coerce         mn[8] Superclass          # <-- static type becomes Superclass
 20: PushScope                                # lscope[1] static type = Superclass
 21: FindPropStrict trace
 22: FindPropStrict mn[4] field               # Superclass LACKS `field` -> must fall through
 23: GetPropertyStatic mn[4] field
```

Every premise checks out, and each of the three soundness conditions the brief
named is *individually satisfied by this ABC*, which is what makes the fix
narrow rather than speculative:

* `class[0] Superclass extends Object sealed` — **sealed**, non-interface, and
  it declares **no instance traits at all**;
* its whole ancestor chain is ABC-visible (`extends Object`, and `Object` is the
  root, so there is no invisible native base whose traits could contain `field`);
* the looked-up name is `field` (`mn[4]`, public QName) — not one of the three
  names the native `Object` base does put on every instance vtable
  (`hasOwnProperty` / `isPrototypeOf` / `propertyIsEnumerable`, registered in
  `avm2_globals.c:7025-7030`).

Our runtime resolves the walk against the **runtime object's vtable**
(`avm2_ops.c:2179 scope_defines_mn` → `avm2_vtable_find_mn`), which for a real
`Subclass` instance finds `field` in both blocks — hence `0` / `0`. The fix has
to be at emission time because the runtime has no static type to consult.

**One premise refinement.** The brief said "reduce past trailing entries" and
priced it at one site. There are in fact **three** cut sites in this body — ops
8, 21 (`trace`) and 22 (`field`). Ops 8/21 are cut for the same reason (neither
`Subclass` nor `Superclass` declares `trace`) and are behaviour-neutral (the
walk missed those entries anyway); only op 22 changes an outcome. The extra two
are the honest consequence of implementing the *rule* rather than special-casing
the one site, and they are the reason the `/* scope-cut N */` audit marker
exists.

---

## 3. What was implemented (patch scope)

All of it lives in `SWFRecomp/src/abc/abc_emit.cpp`, in **new** code — a new
static helper pair and additive fields.

**Sibling-collision check (`w2-avm2-smalls`).** `SIBLING_FILE_MAP.md` warned that
that agent would also edit `abc_emit.cpp` for the per-body `#1107` verify-error
preamble; its delivered patches (`w2-avm2-smalls*.patch`, read from the main-tree
report dir) in fact land in **`SWFRecomp/src/abc/abc_verifier.cpp`**,
`avm2_ops.c` and `avm2_display.c` — **not `abc_emit.cpp` at all**. So the two
recompiler patches have **zero file overlap**; the serial merge is trivially
clean and either order works.

| piece | where | what |
|---|---|---|
| `scopeSkipDeniedName()` | new static fn before `analyzeSlotSpec` | the native-`Object` name deny-list |
| `classProvablyLacksName()` | new static fn before `analyzeSlotSpec` | the soundness predicate (below) |
| `SlotSpecResult::find_scope_cut` | trailing field | per-op cut count |
| `OpSpec::scope_cut` | trailing field | threaded into `emitOp` |
| scope-stack model (`struct SE`, `sstk`, `scope_model_ok`) | inside `analyzeSlotSpec` | mirrors the emitted `lscope[]`/`scope_n` |
| `PushScope` / `PushWith` / `PopScope` arms | inside `analyzeSlotSpec`'s op loop | maintain the model (stack effect identical to the generic tail they replace) |
| cut computation | in the existing `FindPropStrict`/`FindProperty` block | walks `sstk` top-down |
| `scopeArg` / `cutNote` | `emitOp`'s find case | emits `(scope_n > N ? scope_n - N : scope_n)` + `/* scope-cut N */` |

**Audit hooks (both requested by the brief):**

* `SWF_TRACE_SCOPE_CUT=1` — one stderr line per reduction:
  `[scope-cut] method=10 op=22 mn=4 name=field depth=2 cut=1 skipped=Superclass`.
* `/* scope-cut N */` in the generated C — every reduction is greppable in the
  emitted sources without re-running the recompiler. This is what the corpus A/B
  in §4 keys on.
* `SWF_NO_SCOPE_CUT=1` — disables the lever for a same-binary A/B.

The emitted depth is written `(scope_n > Nu ? scope_n - Nu : scope_n)` rather
than a bare `scope_n - N`. The reduction is proved (see §5), but `scope_n` is
unsigned, so a modelling bug would turn into a wild walk over uninitialised
`lscope[]` rather than a wrong answer. With the guard, any unexpected depth
degrades to **today's** full walk. gcc folds the compare away wherever the depth
is a compile-time constant, which is every site the lever fires on.

---

## 4. Full-corpus recompiler A/B

The patch changes emitted text **only** where `scope_cut > 0` (`scopeArg` and
`cutNote` are byte-identical to the old output when the cut is 0, and the new
`PushScope`/`PushWith`/`PopScope` arms reproduce the generic tail's stack effect
exactly: pop 1 / pop 1 / pop 0, no pushes). So `/* scope-cut */` in the generated
C is a complete marker for "this test's emission changed", and I used both
methods:

**(a) Marker sweep — every SWF in the corpus, new binary.**

```
4493 test.swf recompiled (all 17 suite roots, sorted, -P 2, ulimit -v 4194304)
  4492  OK    (no scope-cut emitted -> emission byte-identical to baseline)
     1  CUT   avm2/scope_optimizations   (3 sites)
     0  FAIL  (no new recompiler failure/timeout anywhere)
```

**(b) True byte A/B — 139-test sample, old binary vs new binary, `diff -r`.**

Sample = **all 19 corpus tests whose `.as` source contains a `with (` block**
(the population this lever is most dangerous for) **+ 120 seeded-random tests**
from `avm2` / `from_avmplus` / `from_shumway` / `mixed_avm`. 138 recompiled on
both legs (1 pre-existing recompiler failure, `from_shumway/3_joystick/code`,
identical on both legs); 24 MB of generated C compared:

```
diff -r ab_old ab_new   ->  (empty), exit 0
```

**Zero** byte differences. And the positive control on the headline test:

```
354c354,  379c379,  381c381    (one file, three lines)
< ... avm2_op_findpropstrict_ic(act, lscope, scope_n, 16, 1, 1, &__fc)); }
> ... avm2_op_findpropstrict_ic(act, lscope, (scope_n > 1u ? scope_n - 1u : scope_n), 16, 1, 1, &__fc)); } /* scope-cut 1 */
```

**Changed-test list = `avm2/scope_optimizations`. That is the whole regression
canary, and it flips to pass.** (The set is 1, far under the brief's ">40 ⇒
sample" threshold, so no sampling was needed.)

---

## 5. The soundness argument (5 lines)

1. avmplus early-binds `findproperty` against each scope entry's **static** type,
   so a `coerce Superclass` really does hide a `Subclass` trait — Ruffle
   implements the same rule in `core/src/avm2/optimizer/type_aware.rs`
   (`Op::FindPropStrict`, the *"subtle issue … however, this matches avmplus's
   behavior — see the test `avm2/scope_optimizations`"* comment).
2. I take the **strictly narrower half** of Ruffle's rule: skip a trailing entry
   only when its static class is *known* and *proved* to lack the name — Ruffle
   additionally descends past entries whose class it cannot type, and I never do
   — so this lever can only turn a wrong hit into the avmplus fall-through, never
   remove a binding avmplus would keep.
3. "Proved to lack the name" = sealed non-interface class, local name unique in
   this ABC, **whole** ancestor chain ABC-visible down to `Object` (a native
   ancestor bails, because its traits are invisible here), all declared
   interfaces transitively ABC-visible, ns-**blind** trait match (a same-named
   trait in any namespace blocks the skip), and the name not one of the three
   `Object` instance-vtable names — dynamic/prototype properties need no rule at
   all, because `scope_defines_mn` already matches declared traits only.
4. `with` entries (`is_with = 1`) terminate the scan unconditionally, and entry 0
   is never removed (avmplus's "global scope works differently" case), so the
   emitted depth is always ≥ 1.
5. The compile-time model equals the runtime `scope_n` because it mirrors the
   emitted ops one-for-one and is trusted **only on the straight-line prefix
   before the body's first join point**; it closes at the first branch/switch/
   exception target and never opens in a body with an active handler, so no
   merge can make the model's depth disagree with the machine's.

---

## 6. Canary grades

Emission is byte-identical on all of these (§4), so they are a check on the
"unchanged emission ⇒ unchanged result" claim rather than on the lever itself —
and on the `with`-scope population specifically, where a depth-model bug would
land first. All graded `--mode=graphics --recompile --verbose`,
`SWFRECOMP_COMPILE_TIMEOUT=2400`.

| test | uses | baseline | with patch |
|---|---|---|---|
| `avm2/with` | `with (obj)` blocks | pass | **PASS** |
| `avm2/try_catch` | `with` + catch scopes | pass | **PASS** |
| `avm2/json_stringify` | `with` + closures | pass | **PASS** |
| `avm2/core_exceptions` | `with` + handlers | pass | **PASS** |
| `avm2/verify_stack` | `with` + scope-depth edges | pass | **PASS** |
| `avm2/catch_scope_slot` | catch scope + slot | pass | **PASS** |
| `avm2/getouterscope` | captured outer chain | pass | **PASS** |
| `avm2/getouterscope_two_classobjects` | two class objects on the chain | pass | **PASS** |
| `from_avmplus/ecma3/Function/scope_002` | nested closures + `with` | pass | **PASS** |
| `from_avmplus/ecma3/Statements/e12_10` | `with` statement semantics | pass | **PASS** |
| `from_avmplus/ecma3/ExecutionContexts/e10_1_4_9` | `with` + execution contexts | pass | **PASS** |
| `avm2/scope_optimizations` | **the headline** | output_mismatch | **PASS** |

`9/9` (avm2 batch) + `3/3` (from_avmplus batch), zero failures, zero
`compile_fail`. Raw: `scratchpad/w2scopeopt/canaries_avm2.log`,
`canaries_avmplus.log`.

**Canary blind spot, stated per the s15 rule:** this change class (ABC
`findproperty` emission) is not covered by the standing graphics
`render_canary_tests.txt` set at all, and it cannot be — it is trace-only and
recompiler-side. The 4493-SWF emission sweep in §4 is the covering instrument,
and it is stronger than any canary list: it enumerates the changed set exactly
rather than sampling it.

---

## 7. Pricing attacked: the ceiling is +1, and the gate is the reason

The board priced this "+1, recompiler-only, ~1 slot" and that is exactly what it
delivers — but the *why* is worth recording, because it is also the answer to
"is the conservative gate leaving flips on the table?"

I expected the join-point gate (§5.5 — the lever closes at the body's first
branch/switch/exception target) to be the thing capping applicability, and I was
**wrong**. I built a probe binary with that gate *removed entirely*
(`SWF_SCOPE_CUT_PROBE=1`, an unsound relaxation kept out of the delivered patch)
and re-swept the three AVM2-bearing suites where the pattern could plausibly
live:

```
1486 SWFs (avm2 + from_shumway + mixed_avm), gate REMOVED
  1485  OK
     1  CUT   avm2/scope_optimizations   (still 3 sites)
     0  FAIL
```

**Identical result.** The gate costs nothing today: the corpus contains exactly
one `coerce <sealed ABC class> ; pushscope ; findprop <name that class provably
lacks>` shape, and it is the test that was purpose-built to exercise it. So:

* the board's "+1" is the true ceiling, not a floor — there is no hidden family
  behind this row, and no reason to spend a follow-up slot widening the gate;
* the conservatism is free, which is the best possible trade for a lever whose
  failure mode is "a property silently resolves to the wrong object";
* and the 0-regression claim in §4 is not luck — the emission is untouched
  because the *pattern* is absent, not because the gate happened to close.

One incidental datum from the sweeps: `from_shumway/3_joystick/code` hit the
300 s recompiler cap in the `-P 2` A/B leg and recompiled fine at `-P 1` in the
probe. That is the standing "long-compile failures under load are FALSE" rule
showing up in the *recompiler* rather than in gcc; it is not a regression and it
is identical on both legs.

---

## 8. Residuals / completion mechanisms

* **Cross-ABC class-name aliasing (pre-existing, not introduced).**
  `AbcTypeModel::typeMnToInst` resolves a *type* multiname by **local name only**,
  so a `coerce a.b::Widget` in a file that also defines `c.d::Widget` resolves to
  the wrong instance. I close the intra-ABC half (`uniqueClassByName(...) == inst`
  is required before trusting a class's traits); the cross-ABC half is untouched
  and already governs coerce elision and both slot levers, which have shipped for
  many sessions. **Completion mechanism:** give `AbcTypeModel` an ns-aware
  `typeMnToInstStrict` (match the instance's own QName with `mnMatchesQName`) and
  route `typeOfMn` through it — that is a shared-infrastructure change worth its
  own slot, and it would *narrow*, never widen, every lever built on `TV`.
* **The join-point gate.** Sound and cheap, but it is the binding constraint on
  applicability (§7). **Completion mechanism:** a per-op scope-depth fixpoint
  (depth is required to agree at merges by the ABC verifier, so it is computable)
  plus a type-join at merges would let the lever fire inside loops and after
  branches. Only worth it if a *test* demands it; today none does.
* **The `Object` deny-list is hand-maintained.** If `avm2_globals.c` ever adds an
  instance method to `object_class`, `scopeSkipDeniedName` must gain the name.
  It is commented with the exact `avm2_globals.c` line range that owns the truth.

---

## 9. Reproduce

```bash
export SWFRECOMP_COMPILE_TIMEOUT=2400 DAWN_INSTALL=~/CC/dawn-install
cmake -B SWFRecomp/build -DCMAKE_BUILD_TYPE=Release && cmake --build SWFRecomp/build -j
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/avm2 \
        --test=scope_optimizations --mode=graphics --diff --verbose --recompile
# audit every reduction the recompiler made:
grep -rn "scope-cut" <test>/RecompiledABC/
SWF_TRACE_SCOPE_CUT=1 SWFRecomp/build/SWFRecomp config.toml   # stderr, one line per cut
SWF_NO_SCOPE_CUT=1    SWFRecomp/build/SWFRecomp config.toml   # same-binary A/B baseline
```

Scratchpad (drivers + raw logs):
`/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/ab0a66b8-f5eb-4947-8b92-d32ad2d435e1/scratchpad/w2scopeopt/`
— `sweep_new.txt` (4493-row corpus sweep), `ab_diff.txt` (empty 139-test byte
A/B), `baseline_headline.log` / `new2_headline.log`, `canaries_*.log`,
`probe_out.txt`.
