# s17 wave-2 — `w2-avm2-smalls` — three scoped AVM2 trace items

**Verdict: GO on all three. 3 / 3 priced flips landed: +3 trace, and
`displayobject_hittestpoint_boundary` also flips its image comparison
(976/900 FAIL → 812/900 PASS), so +1 on the pixel axis as well.**

| item | headline test | baseline | after | verdict |
|---|---|---|---|---|
| 1 | `avm2/method_association` | `output_mismatch` (1/5 lines) | **PASS** | **GO** |
| 2 | `avm2/supercalls_coerce` | `output_mismatch` (1/8 lines) | **PASS** | **GO** |
| 3 | `avm2/displayobject_hittestpoint_boundary` | `output_mismatch` (47/65) | **PASS** | **GO** |

All three graded with `--mode=graphics --diff --verbose`, `SWFRECOMP_COMPILE_TIMEOUT=2400`,
against baseline `88ebde665` / results run `31877239992`.

---

## NEW FILES

**None.** Every change is an edit to an existing tracked source file. Three files
are touched in total:

```
SWFRecomp/src/abc/abc_verifier.cpp          (+146)   item 1a
SWFModernRuntime/src/avm2/avm2_ops.c        (+40/-13) items 1b + 2
SWFModernRuntime/src/avm2/avm2_display.c    (+35/-7)  item 3
```

No new headers, no generated files, nothing for `git add -u` to drop.

## Patches

| file | contents | applies to pristine `HEAD` |
|---|---|---|
| `w2-avm2-smalls-method_association.patch` | `abc_verifier.cpp` (all) + the ONE `avm2_op_callstatic` hunk of `avm2_ops.c` | verified |
| `w2-avm2-smalls-supercalls.patch` | the four super-receiver hunks of `avm2_ops.c` | verified |
| `w2-avm2-smalls-hittest.patch` | `avm2_display.c` (all) | verified |
| `w2-avm2-smalls.patch` | all three, combined | verified |
| `w2-avm2-smalls-ignorelist-hittest.patch` | **optional, deliberately NOT in the combined patch** — prunes the now-passing `displayobject_hittestpoint_boundary` from `avm2/ignored_tests.txt` (see §3) | verified |

The three item patches were checked mechanically: each applies standalone to
`git show HEAD:<file>` output, and applying all three in order reproduces the
combined working tree **byte-identically** (`diff -q` on all three files).
Items 1 and 2 share `avm2_ops.c` but land in different functions
(`avm2_op_callstatic` vs `avm2_op_callsuper` / `getsuper_common` /
`setsuper_common`), so the hunks never touch.

**Sibling-overlap note.** `w2-scope-opt` owns `SWFRecomp/src/abc/abc_emit.cpp`.
Item 1a was expected to live there; it does **not** — see §1. My recompiler
edit is entirely in `abc_verifier.cpp`, which no sibling in
`SIBLING_FILE_MAP.md` claims, so the recompiler-side textual overlap the map
warned about is **zero**.

---

## 1. `avm2/method_association` — GO (+1)

Baseline `output_mismatch`, 1 of 5 lines. Expected `1107 / 1107 / 1034 /
Passed / Passed`; we printed `Passed` ×4.

### Brief premise: confirmed on mechanism, corrected on location

The s16 report's decode of the row was exactly right and I did not re-derive it:
`test1` `NewFunction`s a method_info that is already an instance trait,
`test2` `CallStatic`s a free one, `test3` `CallStatic`s a bound one on a bare
`{}` receiver, `test4` is legal. The two halves are independent and neither
alone flips the row.

The brief located half (a) in `abc_emit.cpp`, emitting
`avm2_throw_verify_error(act, 1107)` as a body's first statement ahead of
`avm2_try_push_frame`. **That is not needed — the machinery already exists one
layer up.** `abc_emit.cpp:2438` already has an unverified-body path that emits
`avm2_verify_error_body(act, "<message>")` as the *entire* body and returns
before any try frame is emitted, which is precisely avmplus's "the method is
rejected at verify time" semantics, and it is what
`verify_illegal_opcode` / `verify_method_info_*` already ride. So half (a) is
one **verifier predicate**, not an emitter change:

`SWFRecomp/src/abc/abc_verifier.cpp` gains a `checkMethodAssociation` pass that
runs last in `verifyMethodBody` (after the depth pass and the type lattice, so
any other verify problem still reports first, matching avmplus's order) and
`fail(err, 1107, …)` on:

* `NewFunction m` where `m` is **class-bound**, or
* `CallStatic m` where `m` is **not** class-bound.

The class-bound set is built once per `AbcFile` (same pointer-identity cache and
the same `resetVerifierTypeModel()` reset as the existing `g_lat_model`) from
exactly the bindings Ruffle installs before any body is verified:

| source | Ruffle |
|---|---|
| every instance's `iinit` + its Method/Getter/Setter traits | `class_object.rs:306,312` |
| every class's `cinit` + its Method/Getter/Setter traits | `class_object.rs:307,319` |
| every script's `init_method` + its Method/Getter/Setter traits | `script.rs:631,636` |

`TraitKindType::Function` is deliberately excluded — Ruffle's
`Trait::as_method()` returns `None` for it (`traits.rs:228`), so a function
trait's method stays freestanding and is a legal `NewFunction` operand. Getting
this wrong would have produced false positives on ordinary package-level
functions.

Half (b) is as briefed and is four lines: `avm2_op_callstatic` already reads
`act->file->method_env_class[method_index]` (Ruffle's `method.bound_class()`),
so coercing `recv` to it before dispatch gives the #1034 (Ruffle
`activation.rs:1159-1162`, "Ensure receiver is of the correct type").

### Full-corpus recompiler A/B — the predicate fires on ONE test in 4 370

Because a false positive here **deletes a method body**, I did not ship the
predicate on a corpus census. `abc_verifier.cpp` also gains
`SWF_ASSOC_AUDIT=<csv>`, a report-only mode that mirrors the file's existing
`SWF_VERIFY_TYPES=<csv>` harness exactly: every hit is written to the CSV and
verification still **succeeds**. That turns the A/B into a single sweep with the
new binary — no second build, and the answer is the exact op, not a diff of
generated C.

`scratchpad/w2avm2smalls/sweep2.sh` recompiles every `test.swf` in a throwaway
directory (no test's `Recompiled*` cache is touched) and records per-SWF
`(exit code, produced RecompiledABC?)` so the sweep's own coverage is auditable
— a sweep that silently failed every recompile would also report zero hits.

```
avm2 + from_avmplus/as3 + from_shumway     swfs=1984  rc0=1984  withabc=1865  hits=1
avm1 + from_gnash + from_avmplus(all)
  + mixed_avm + stage3d + timeline
  + text + visual                          swfs=2895  rc0=2894  withabc=1653  hits=0
-------------------------------------------------------------------------------
union (as3 swept by both, de-duplicated)   swfs=4370  rc0=4369  withabc=3010  hits=1
```

The single non-zero exit is `visual/simple_shapes/heavy_tesselation` (exit 124 =
the sweep's own 300 s cap; `verify_output.py:2028` documents that SWF as a
55–205 s recompile that stretches under contention, and it carries no DoABC
anyway). Every other SWF in the corpus recompiled successfully, and the only
rows in the whole audit are:

```
avm2/method_association,,Test/test1,body 1,op 7,method_info 1,newfunction-bound
avm2/method_association,,Test/test2,body 2,op 8,method_info 4,callstatic-unbound
```

**Affected-test list = `{ avm2/method_association }`.** Zero collateral. That is
the strongest form of the recompiler-side evidence the board asked for, and it
also retires the board's "tooling to promote" item for this predicate class.

### Ledger

| test | baseline | after |
|---|---|---|
| `avm2/method_association` | `output_mismatch` 1/5 | **PASS** |
| `avm2/verify_method_info_oob` | `pass` | **pass** (held — s16's regression does not recur) |
| `avm2/verify_method_info_duplicate` | `output_mismatch` 1/2 | `output_mismatch` 1/2 (unchanged; standing ACCEPTED_DIFFS Cat 2 row, not touched) |

---

## 2. `avm2/supercalls_coerce` — GO (+1)

Baseline `output_mismatch`, 1 of 8 lines:

```
- #1: 1034   + super getter called      - #5: 1034   + #5: 1037
- #2: 1034   + super setter called      - #6: 1034   + #6: 1070
- #3: 1034   + #3: 1063                 - #7: 1009   + #7: 1010
- #4: 1034   + #4: 1077                   8 [object SuperTest]  (matched)
```

### Brief premise: confirmed exactly, and the seventh line is the same rule

The board called it "one rule, seven lines" and it is. Ruffle's `op_get_super`,
`op_set_super` and `op_call_super` (`activation.rs:1448/1472/1175`) all open with
the identical two steps in this order:

```rust
let receiver = self.pop_stack()
    .coerce_to_type(self, bound_superclass_object.inner_class_definition())?;
let receiver = receiver.null_check(self, Some(&multiname))?;
```

We had the null check but not the coercion, so every case fell through to a
*later* check that produced a different code — arity (#1063), read-only
(#1077), method-assignment (#1037), name-not-found (#1070) — or, in cases #1/#2,
to a successful call. Cases #1..#6 all push a bare `NewObject{}` as the
receiver, which is not a `SuperTestSuperClass`, so the coercion is the first
thing that can fail.

**The brief priced #7 as a separate oddity (1009 vs 1010); it is not.** Case #7
pushes an explicit `undefined` (`abc0_methods.c` body 13, op 153
`PushUndefined` → op 154 `CallSuper mn[18]`). `avm2_coerce_to_class` maps
`undefined` → `null` for any object type, so after the coercion the null check
sees `null` and reports #1009 instead of #1010. One rule, seven lines, no
special case.

Implementation: one static helper `super_coerce_receiver()` in `avm2_ops.c`,
called from `avm2_op_callsuper`, `getsuper_common` and `setsuper_common` — which
covers the `_dyn` (`super[expr]`) forms too, since they share those tails.

---

## 3. `avm2/displayobject_hittestpoint_boundary` — GO (+1), and the brief's first half is REFUTED

Baseline `output_mismatch`, 47 of 65 lines.

### Refutation: there is no missing leading blank line

The brief (and `ignored_tests.txt:89`) list "a missing leading blank line" as one
of two independent defects. It is not a defect at all. `output.txt` is **67**
raw lines and contains **two** blank lines (line 1 and line 34, one per shape
block); the harness's own `expected_lines` for this row is **65**. The harness
normalises blank lines out of *both* sides, so the fixture's opening `trace("")`
is invisible to grading and always was. Nothing to fix, and — importantly —
nothing to patch in `verify_output.py`, which would have had a corpus-wide
effect for zero gain.

That also means **all 18 mismatching lines are the edge rule**, not 1 + 17: the
fixture probes 16 boundary points per shape with `shapeFlag = true`, expects 9
`false` and 7 `true`, and we answered `true` for all 16. 9 × 2 shapes = 18.

### The rule is Ruffle's `winding_number_line`, and it is not "vertices are exclusive"

The brief described it as "a point exactly on an octagon vertex/edge must read
`false`". That is half the rule and would produce the wrong answer for 7 of the
16 points. The expected output is directional:

```
false:  (10,0) (5,5) (0,10) (0,15) (0,20) (5,25) (10,30) (15,30) (20,30)   <- left/bottom half
true:   (25,25) (30,20) (30,15) (30,10) (25,5) (20,0) (15,0)               <- right/top half
```

That is exactly Ruffle's `+x` ray cast (`render/src/shape_utils.rs:991`):

```rust
if ((begin.y)..(end.y)).contains(&test_point.y)              // HALF-OPEN
    && (d1.dx as i64)*(d0.dy as i64) >= (d1.dy as i64)*(d0.dx as i64) { return 1; }
if ((end.y)..(begin.y)).contains(&test_point.y)
    && (d1.dx as i64)*(d0.dy as i64) <= (d1.dy as i64)*(d0.dx as i64) { return -1; }
```

The half-open y interval counts a shared vertex exactly once, and the `>=` / `<=`
make a point lying *on* a segment count as inside it — together, "top and right
edges are in, bottom and left edges are out". I simulated the polygon-level rule
against the fixture before writing any C: it reproduces all 16 expected answers,
under both windings and under both fill rules.

### Why the fix is safe: the rule tiles across a triangulation

Our hit test is not contour-based — `shape_contains_local` ORs a
boundary-**inclusive** barycentric test (`pick_tri_contains`) over the
tessellated triangles, which is why every boundary point read `true`. I replaced
that test with the per-triangle winding number under Ruffle's rule.

The concern is seams: a point on a triangulation seam is interior to the shape
but on the *edge* of two triangles. It survives because a seam is a "top/right"
edge of exactly one of the two triangles that share it, so the OR still answers
`true`. I verified this rather than assuming it — simulating fan, **reversed**-fan
and strip triangulations of the fixture's octagon against the polygon-level rule
over a 31×31 integer-pixel grid *and* a sub-twip grid gave **0 disagreements for
all three**, so the answer is independent of how libtess2/earcut cut the shape
and of triangle orientation. (Scripts: `scratchpad/w2avm2smalls/sim.py`,
`sim2.py`.)

Side benefit: degenerate zero-area triangles now correctly cover nothing
(the old barycentric test returned `true` for any point collinear with one).

### Bonus: this is a DUAL-AXIS flip

The s17 wave-1 trace board (§7, "free pixel flip?") priced this row's image
comparison as **976 / 900 outliers, 8 % over, "plausible — rides the handed-off
shape-hit-test edge rule."** It does, and it lands:

```
before:  976 outliers / limit 900   FAIL   (+76 excess)
after:   812 outliers / limit 900   PASS   (-88 headroom)
```

(from the graded run's `[image:output] PASS - Image check passed: 812 outliers
(limit 900), max difference 255`.) The fixture *draws* markers from the hit
results, so correcting which boundary points report `true` moved the render as
well. This is a geometric change — which markers get drawn — not an
antialiasing one, so the ~10 % headroom should survive the local-Dawn →
CI-lavapipe move, but it is a comparison to watch on the merged run rather than
one to bank.

### Disposition / ignore-list

`displayobject_hittestpoint_boundary` is in
`ruffle-tests/tests/swfs/avm2/ignored_tests.txt` (line 94) as an **open trace
bug with an owner lead named**, not as an accepted diff — and that file's own
2026-08-01 prune criterion says an entry that reaches `pass` must be removed.
It now passes. I have **not** folded that edit into my patches, because
`ignored_tests.txt` files are assigned to the pending `w2-tooling-hygiene`
sibling; it is delivered separately as
`w2-avm2-smalls-ignorelist-hittest.patch` so the coordinator can drop it if that
sibling lands a conflicting rewrite. Applying it moves the *filtered* count by
+1/+1 (numerator and denominator) and the graded count by 0.

---

## Canaries

All 25 canaries were run in this worktree with `--mode=graphics --diff
--verbose --recompile` (the `--recompile` is mandatory on a `cp -r`'d dir; s16
lost six canaries to stale `Recompiled*` caches) and
`SWFRECOMP_COMPILE_TIMEOUT=2400`. **Every one holds its baseline `pass`. Zero
regressions.**

### Super / callstatic / verify-error family (items 1 + 2)

| test | suite | baseline | after |
|---|---|---|---|
| `verify_method_info_oob` | avm2 | pass | **pass** |
| `verify_method_info_duplicate` | avm2 | output_mismatch 1/2 | output_mismatch 1/2 (unchanged) |
| `class_supercalls_errors` | avm2 | pass | **pass** |
| `class_supercalls_mismatched` | avm2 | pass | **pass** |
| `supercall_two_classobjects` | avm2 | pass | **pass** |
| `supercalls_weird` | avm2 | pass | **pass** (the script-init `super.AS3::hasOwnProperty` path — `super_class_of`'s `global`→`Object` fallthrough) |
| `constructsuper_null` | avm2 | pass | **pass** |
| `class_methods` | avm2 | pass | **pass** |
| `class_call` | avm2 | pass | **pass** |
| `es4_method_binding` | avm2 | pass | **pass** |
| `method_without_body` | avm2 | pass | **pass** |
| `activation_class` | avm2 | pass | **pass** |

### `from_avmplus/as3` super + class canaries (items 1 + 2)

| test | baseline | after |
|---|---|---|
| `as3/Definitions/Super/SuperProps` | pass | **pass** |
| `as3/Definitions/Super/SuperObjectCall` | pass | **pass** |
| `as3/Definitions/Super/SuperArgsCall` | pass | **pass** |
| `as3/Definitions/Super/SuperRuntimeError` | pass | **pass** |
| `as3/Definitions/Super/SuperInForLoop` | pass | **pass** (the `_dyn` / `super[expr]` set path) |
| `as3/Definitions/Super/SuperExprChainAccess` | pass | **pass** |
| `as3/Definitions/Super/SuperObject` | pass | **pass** |
| `as3/Definitions/Super/SuperImplicitlyCalled` | pass | **pass** |
| `as3/Definitions/Classes/Ext/AccStatMethSubClassMethSuper` | pass | **pass** (the class-side `super`, i.e. `frame_is_class_side` → `Class`) |

### Hit-test family (item 3)

| test | baseline | after |
|---|---|---|
| `displayobject_hittestpoint` | pass | **pass** |
| `displayobject_hittestpoint_root` | pass | **pass** |
| `displayobject_hittestobject` | pass | **pass** |
| `movieclip_hittest` | pass | **pass** |
| `hittest_morph` | pass | **pass** (the ratio-lerped morph triangles go through the same predicate) |
| `button_hittest` | pass | **pass** |

Harness note for whoever reruns these: `--test=NAME` alone cannot resolve the
`from_avmplus` rows — `verify_output.py:3796` only searches the *direct
children* of each suite dir, and these live at
`from_avmplus/as3/Definitions/Super/<NAME>`. Pass
`--tests-dir=<worktree>/ruffle-tests/tests/swfs/from_avmplus/as3/Definitions/Super`.
Without it the run exits `test directory not found: .../avm1/SuperProps`, which
is silent in a batch driver that only greps for PASS/MISMATCH.

**Canary blind spot.** The item-3 change touches the AVM2 shape hit test, which
also backs the AVM2 **mouse pick** walk (`hit_test_shape_obj` → `mouse_pick`),
not just `hitTestPoint`. The canary set above covers `hitTestPoint` /
`hitTestObject` / morph picking / button picking, but a mouse-pick row whose
click lands exactly on a shape's left or bottom edge would be a new false. I
found no such row in the corpus (every mouse-pick fixture clicks interior
points), but it is the one axis this local set cannot prove, and it is the thing
to look for in the merged CI run.

---

## Cost / scope summary

* Item 1a is a **verifier** predicate, not an emitter change — `abc_emit.cpp`
  needed nothing, so the sibling collision the file map anticipated does not
  exist.
* Item 1's blast radius is measured, not estimated: 1 test in 4 370 (3 010 of them ABC-bearing).
* Item 3's blast radius is corpus-wide by construction (every AVM2 shape hit
  test), which is why the tiling property was proved by simulation before the
  edit and why the canary blind spot is called out above.
* CI: this touches AVM2 runtime **and** recompiler emission, so the merged run
  wants `categories=full` per CLAUDE.md.

---

## Refutations (yield, independent of the flips)

1. **`hittestpoint_boundary`'s "missing leading blank line" does not exist.**
   The harness normalises blank lines out of both sides (67 raw expected lines,
   two of them blank, graded as 65). The s17 wave-1 board's R5 got the
   *conclusion* right — don't patch `verify_output.py` — but for the wrong
   reason (it read the row as a "per-test first-trace difference"). There is no
   first-trace difference either: all 18 mismatching lines were the edge rule,
   and fixing only the edge rule flips the row.
2. **The edge rule is not "vertices/edges are exclusive".** It is Ruffle's `+x`
   ray cast with a half-open y interval and `>=`/`<=` perp-dot ties, i.e.
   top/right edges IN and bottom/left edges OUT. Blanket exclusion would have
   turned 7 of the 16 expected `true`s into `false`.
3. **Item 1a does not belong in `abc_emit.cpp`.** The "emit the throw ahead of
   `avm2_try_push_frame`" plumbing the brief specified already exists as
   `abc_emit.cpp`'s unverified-body path; the work is one verifier predicate.
   This is also why the anticipated `abc_emit.cpp` collision with `w2-scope-opt`
   never materialised.
4. **`supercalls_coerce`'s case #7 is not a separate `1009`-vs-`1010` bug.** It
   falls out of the same receiver coercion (`undefined` → `null` for object
   types), so the row is one rule for all seven lines, not six plus an oddity.

## Reproduction

```
export SWFRECOMP_COMPILE_TIMEOUT=2400 DAWN_INSTALL=~/CC/dawn-install
cmake -S SWFRecomp -B SWFRecomp/build -DCMAKE_BUILD_TYPE=Release && cmake --build SWFRecomp/build -j4
python3 ruffle-tests/verify_output.py --test=method_association --mode=graphics --diff --verbose --recompile
python3 ruffle-tests/verify_output.py --test=supercalls_coerce --mode=graphics --diff --verbose
python3 ruffle-tests/verify_output.py --test=displayobject_hittestpoint_boundary --mode=graphics --diff --verbose

# corpus A/B for the #1107 predicate (report-only; no second binary needed)
bash scratchpad/w2avm2smalls/sweep2.sh ruffle-tests/tests/swfs/avm2 ...
```

Scratchpad (private, `w2avm2smalls/`): `sim.py` / `sim2.py` (winding-rule
simulations), `sweep.sh` / `sweep2.sh` / `sweep3.sh` (corpus audit),
`split.py` + `checkpatch.sh` (patch split + mechanical apply verification),
`assoc_audit*.csv`, `assoc_status*.csv`.
