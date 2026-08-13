# Wave-1 — matrix3d batch (session 15, dual-axis fan-out #7)

Agent: `w1-matrix3d`. Read-only pass over the main tree. Baseline `42a324cef`,
grading run `31647430265` at `bf585e448`.

---

## 1. Verdict

**GO — 9/9 flips, high confidence.** All nine rows are fixable in **one file**
(`SWFModernRuntime/src/avm2/avm2_stage3d.c`), with **no recompiler change and no
class-registration change**.

| # | Test (all `avm2/`) | Current | Predicted | Confidence | Fixes needed |
|---|---|---|---|---|---|
| 1 | `matrix3d_append` | output_mismatch | **pass** | very high | A |
| 2 | `matrix3d_prepend` | output_mismatch | **pass** | very high | A |
| 3 | `matrix3d_copy_column` | output_mismatch | **pass** | very high | A (+ ordering) |
| 4 | `matrix3d_copy_row` | output_mismatch | **pass** | very high | A (+ ordering) |
| 5 | `matrix3d_copy_raw_data_from` | output_mismatch | **pass** | high | A + B |
| 6 | `matrix3d_copy_raw_data_to` | output_mismatch | **pass** | high | A + C |
| 7 | `matrix3d_transform_vector` | output_mismatch | **pass** | high | A + D |
| 8 | `matrix3d_append_rotation` | output_mismatch | **ruffle_matched** | high | A + E |
| 9 | `matrix3d_recompose_edge_cases` | output_mismatch | **ruffle_matched** | medium-high | A + F + G |

Effective trace delta: **+9** (4269 → 4278 of 4443). Seven become byte-exact
Flash matches; two are `known_failure` tests where `ruffle_matched` is the
achievable bar (§4.3, §4.4) and outright `pass` is a stretch bonus.

**Ledger note:** ~85 % of the total gap across the batch is *one idiom* — a
missing `#2007 Parameter <name> must be non-null.` guard. Fixing only that
(change **A**) already flips tests 1–4 outright and shrinks 5–9 to small
residues.

---

## 2. Refutations of the brief

### 2.1 "One class" is wrong — `flash.geom.Matrix3D` already exists and is complete

The brief (arc doc §15.3) prices this as "9 failing rows, one class — the
biggest new cluster", implying the s14 missing-class-batch shape (arc §5.3/§5.4:
`getlex` → `#1065 Variable X is not defined`).

**That is not this batch.** `Matrix3D` is registered in
`avm2_stage3d.c:register_matrix3d()` (line 2285) with **27 members** —
`rawData`, `determinant`, `position`, `identity`, `clone`, `copyFrom`,
`copyRawDataFrom/To`, `transpose`, `invert`, `append`, `prepend`,
`append/prependTranslation|Scale|Rotation`, `transformVector`,
`deltaTransformVector`, `transformVectors`, `recompose`, `decompose`,
`copyColumn/RowTo/From`, `copyToMatrix3D`, `pointAt`, `interpolateTo`,
`interpolate` — plus `Orientation3D` and `Utils3D`. Four sibling tests already
pass (`matrix3d`, `matrix3d_compose`, `matrix3d_invert`,
`from_shumway/.../Matrix3DClass`), and **two of the eleven new arrivals
(`matrix3d_position`, `matrix3d_transpose`) passed on arrival with zero work.**

Not one of the nine failures has a `#1065`/missing-name error signature. This is
a **member-semantics batch**, not a missing-class batch.

Consequence for the wave-2 brief: the memories the brief cites
(`builtin-class-mints-never-looks-up`, `vtable-override-is-not-append`,
`accessor-halves-separate-classes`) are **not applicable** — no class is minted,
no vtable is overridden, no accessor is added. The whole batch is edits to
existing `static Avm2Value matrix3d_*` bodies.

### 2.2 The batch is 11 new tests, not 9 failing + unknown

`results_graphics_previous.json` → `results_graphics.json` shows 14 new avm2
tests in the s14 drift; 11 are `matrix3d_*`. The three non-matrix3d arrivals
(`automation_classes`, `textblock_releaselines`, `textline_raw_text_length`)
belong to other briefs.

### 2.3 Adjacent matrix3d-named failures are NOT in this batch

* `from_shumway/avm2/flash/geom/matrix3d/TransformBasics` — `#1006
  getRelativeMatrix3D is not a function`. Owner is **`flash.geom.Transform`**
  (`avm2_display.c:14001`, where `matrix3D` / `perspectiveProjection` already
  live), not `Matrix3D`. 13-line `known_failure` test with an
  `output.ruffle.txt`. Plausible cheap **+1 rider** for whoever adds
  `Transform.getRelativeMatrix3D`, but it is a different file and a different
  mechanism — do not fold it into the price above.
* `avm2/geom_transform` — `#1009` on a `DisplayObject.transform` path.
* `avm2/all_classes/display3D/swf13`, `swf30` — class-census tests.

### 2.4 Harness finding: `avm2/matrix3d` passes on a line it actually gets wrong

`avm2/matrix3d` (a **passing** test) expects
`mat.transformVector(v): 3857 4266 4675 5176`; we emit `3857 4266 4675 0`. It
passes because `_lines_approx_equal` (`verify_output.py:1008-1036`) uses
`pattern.search()` — it compares only the **first** regex match, then strips
*all* numbers from both lines and compares the remainders. For an
all-numbers line that is always a pass if the first number agrees.

Two consequences:

1. Fix **D** (the `w` component) has **zero regression risk** for
   `avm2/matrix3d` — it will keep passing, and for the right reason.
2. This is a real corpus-wide looseness in `[approximations.number_patterns]`
   tests. **Do not "fix" the harness in this arc** — tightening `search` →
   `finditer` would reprice an unknown number of currently-passing tests. Record
   it; scope it separately.

---

## 3. Evidence — measured per-test residues

Method: the nine test dirs were absent locally (upstream drift; the corpus is
gitignored and CI re-downloads). I sparse-cloned `ruffle-rs/ruffle@master` into
scratchpad and copied **only the eleven new `matrix3d_*` dirs** into
`ruffle-tests/tests/swfs/avm2/` (additive — no existing test dir touched, so no
sibling agent's measurement is disturbed). Each test then ran individually with
`--recompile` (batched at `-P 2`), plus `--save-actual`, and actual-vs-expected
was aligned with `difflib.SequenceMatcher` so pure line-shift is not counted as
a diff.

Every "already matches" claim below is a **byte-exact** alignment of our actual
against Flash's `output.txt`.

* `matrix3d_append` / `matrix3d_prepend`: **all 10 arithmetic lines already
  match exactly**, including the self-append aliasing case
  (`a.append(a)` → `90,100,…,600`) and all five NaN/Infinity cases. The only
  defect is the missing `#2007` block. `m3d_mul` and the NaN/Inf propagation are
  correct as written.
* `matrix3d_copy_column` / `matrix3d_copy_row`: the four `#2004` blocks (lines
  1–24) already match, **including the native stack frame
  `at flash.geom::Matrix3D/copyColumnTo()`** — so the native-frame stack-trace
  machinery needed by every `#2007` block already works. All 35 value lines
  (columns/rows, special values, index coercion incl. `2.9`, `-0.5`, `NaN`,
  `Infinity`, `true`, `null`, `undefined`) already match.
* `matrix3d_copy_raw_data_to`: 27 of 38 lines already match, including the
  transposed and defaults cases.
* `matrix3d_transform_vector`: **all 30 `transformVectors` lines already match**
  (including the `#1126` fixed-vout case and all three null cases). Only the 14
  `transformVector`/`deltaTransformVector` lines are wrong.
* `matrix3d_recompose_edge_cases`: lines 52–91 (negative scale, component count
  0–4, orientation-style coercion `5`/`true`/`""`) already match exactly.

---

## 4. Implementation plan

Single file: **`SWFModernRuntime/src/avm2/avm2_stage3d.c`**, region 1362–2060.
No header change, no registration change, no recompiler change. Estimated
~120 lines of C.

### 4.1 Fix A — the `#2007` null-parameter guard (flips 1–4 alone; required by all nine)

The idiom already exists in the same file (`matrix3d_transform_vectors`,
line 1958):

```c
avm2_throw_error(ctx, ctx->builtins.type_error_class,
                 "Error #2007: Parameter vin must be non-null.");
```

Add the same guard, with the **exact upstream parameter names**, to:

| Function | Line | Arg | Parameter name in the message |
|---|---|---|---|
| `matrix3d_append` | 1492 | 0 | `lhs` |
| `matrix3d_prepend` | 1500 | 0 | `rhs` |
| `matrix3d_xform` (kind==2 only) | 1541 | 1 | `axis` |
| `matrix3d_copy_vec_to` | 1986 | 1 | `vector3D` |
| `matrix3d_copy_vec_from` | 2014 | 1 | `vector3D` |
| `matrix3d_copy_raw_data_from` | 1428 | 0 | `source` |
| `matrix3d_copy_raw_data_to` | 1455 | 0 | `dest` |
| `matrix3d_transform_vector_common` | 1669 | 0 | `vector` |
| `matrix3d_recompose` | 1756 | 0 | `components` |
| `m3d_orientation_arg` (recompose arg 1) | 1744 | 1 | `orientationStyle` |

Three non-obvious constraints, all measured:

1. **`copyColumn*`/`copyRow*`: the null check must run BEFORE the `idx > 3`
   `#2004` check.** `matrix3d_copy_column/Test.as:110-114` calls
   `copyColumnTo(4, null)` and `copyColumnFrom(4, null)` — "a null Vector3D and
   an out of range column at once" — and Flash reports **`#2007`**, not `#2004`.
   Current code (`matrix3d_copy_vec_to:1989`) checks `idx > 3` first. Swap.
2. **`appendRotation`'s `pivotPoint` (arg 2) must stay nullable** — the test has
   an explicit `pivot explicitly null` case that must not throw. Only `axis`
   throws.
3. **`orientationStyle` must distinguish NULL from UNDEFINED.** `m3d_orientation_arg`
   currently only special-cases `AVM2_VALUE_UNDEFINED` (→ default
   `"eulerAngles"`); an explicit `null` falls through to
   `avm2_coerce_to_string` → the string `"null"` → `#2187`. Flash wants `#2007`.
   Add a `kind == AVM2_VALUE_NULL` arm that throws. (The test reaches this by
   passing `undefined` through an AS3 `orientationStyle:String` parameter, which
   coerces to `null` before our builtin sees it.) Omitted arg / `undefined` must
   still default to `"eulerAngles"` — `matrix3d_compose` depends on that.

Ordering inside `recompose`: `components`-null → `orientationStyle`-null →
`#2187` style validation → `length < 3`. (Current code validates the style
first, which is compatible with `matrix3d_compose`'s
`recompose(Vector.<Vector3D>([]), "badOrientation")` → `#2187`; keep that
relative order between style-validation and the count check.)

### 4.2 Fixes B–D — three independent member-semantics rules

**B. `copyRawDataFrom` must throw `#2004` when the source is too short**
(`matrix3d_copy_raw_data_from`, 8 blocks). Rule, exactly:
`if (index + 16 > source.length) throw ArgumentError "Error #2004: One of the
parameters is invalid."` and leave the matrix untouched. Confirmed by
`17 entries offset 1` (16 available → OK) vs `16 entries offset 1` (15 → throw)
and `20 entries offset 4` (16 → OK) vs `20 entries offset 5` (15 → throw).
Current code (line 1440) silently pads from an identity `tmp`.
*Risk: none.* Every other `copyRawDataFrom` caller in the corpus
(`stage3d_rotating_cube`, `stage3d_program_constants_bytearray_{be,le}`,
10 call sites each) passes a full 16-element literal at index 0.
**Do not touch the `Matrix3D(Vector)` constructor or the `rawData` setter** —
`avm2/matrix3d` asserts those silently identity-fill on a short vector
(`Too short: 1,0,0,0,…`).

**C. `copyRawDataTo` must length-check a fixed destination up front**
(`matrix3d_copy_raw_data_to`, 5 lines). Rule:
`if (dest.fixed && index + 16 > dest.length) throw RangeError "Error #1126:
Cannot change the length of a fixed Vector."` — **before writing anything**.
Two observable halves: the message (we currently emit `#1125 The index 15 is out
of range 15.` from the per-element write path) *and* the post-throw destination
state (Flash leaves it all `-1`; we leave a partial `1,2,…,15`). A growable
destination still grows. `matrix3d_transform_vectors` (line 1949) already has
exactly this precheck shape to copy from.

**D. `transformVector`/`deltaTransformVector` must compute and return `w`**
(`matrix3d_transform_vector`, 12 lines). In
`matrix3d_transform_vector_common` (1669) add
`double ow = m[3]*x + m[7]*y + m[11]*z + (delta ? 0.0 : m[15]);`
and construct the result with **4** args instead of 3. Verified against the
expected: matrix `[1..16]`, `v=(1,2,3)` → `transformVector` `w = 4+16+36+16 = 72`,
`deltaTransformVector` `w = 4+16+36 = 56`. The **input** vector's `w` is ignored
(the `w set` case with `w=999` yields the same result) — do not read `v.w`.
*Risk:* only `avm2/matrix3d` prints this `w`, and it currently false-passes on
it (§2.4); the Shumway `Matrix3DClass` assertions use `Vector3D.nearEquals`,
which ignores `w` by default.

### 4.3 Fix E — `appendRotation` with a zero-length axis (test 8)

`m3d_build_rotation` (line 1521) early-returns identity when
`len == 0.0`. Flash instead **skips only the division** and runs the ordinary
Rodrigues formula with `ax = ay = az = 0`, which yields `diag(c, c, c, 1)`:

```c
double len = sqrt(ax*ax + ay*ay + az*az);
m3d_identity(m);
if (len != 0.0) { ax /= len; ay /= len; az /= len; }   /* was: if (len == 0.0) return; */
/* ...unchanged formula... */
```

That single change reproduces Flash on all three currently-wrong lines:

* `zero axis, 180 degrees` → `-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,1` (c = −1).
* `NaN degrees, zero axis` → 3×3 all NaN (`t*0*0 + NaN`, `NaN*0 + NaN*0`), and
  the translation row becomes `NaN,NaN,NaN,1` **for free** from `m3d_mul`'s
  `0 * NaN` terms — the same mechanism that already makes the
  `0 degrees, NaN axis` line match today.
* `infinite degrees, zero axis` → same (`cos(inf)` = NaN).

The `len == NaN` (NaN axis) and `len == Infinity` (infinite axis) paths are
untouched and already match.

**Residue:** `appendRotation zero axis, NaN pivot` stays wrong (we give
`NaN,NaN,NaN,0,…,1`; Flash gives all-16-NaN — the pivot term appears to be
applied as a full matrix product with an extra normalization, not as the
`p − p·R` shortcut at line 1560; not derived). That line is **index 22, inside
Ruffle's own diff set** `{14, 15, 22}`, so the test grades **`ruffle_matched`**
regardless. After fix E our diff set is exactly `{22} ⊆ {14,15,22}` — and we are
strictly *better* than Ruffle on 14 and 15. Chasing line 22 to an outright
`pass` is optional bonus work.

*Risk:* every other `appendRotation`/`prependRotation` caller in the corpus
(`stage3d_rotating_cube`, `stage3d_texture/Camera3D`, `stage3d_fractal`,
`stage3d_texture/SimplePostFilters`, Shumway `Matrix3DClass`) uses a non-zero
axis, so the changed branch is unreachable for them.

### 4.4 Fixes F–G — `recompose` (test 9)

`matrix3d_recompose_edge_cases` is `known_failure` with an `output.ruffle.txt`.
I computed Ruffle's own diff set against Flash: **lines 114–198** (the
quaternion/axis-angle `#2004` validation block, which Ruffle does not implement
at all). Ruffle matches Flash on lines 1–113. So the bar for `ruffle_matched`
is: **reproduce expected lines 1–113 exactly; everything from 114 on is free.**
Do **not** implement quaternion `#2004` validation for this test — it buys
nothing here.

Within lines 1–113 there are exactly three defects:

* **Fix A** — the two `#2007` blocks (lines 1–12) and the second
  `orientationStyle` null at line 92. Net +5 lines, which is exactly the
  alignment offset our output currently carries at line 109 ↔ expected 114, so
  the tail lands on the free indices.
* **Fix F — a null element inside `components` ⇒ return `false` and leave the
  matrix UNTOUCHED** (lines 19–27; `nullIndex` 0, 1, 2). Currently
  `m3d_component` maps a null component to `0.0` and we mutate `e->m` anyway.
  Validate `components[0..2]` are non-null objects **before** `m3d_identity(e->m)`.
* **Fix G — drop the `1e-15` zero-scale substitution and always return `true`**
  (lines 28–51). Flash writes the literal `0` and reports `true`:
  `Scale: Vector3D(0, 8, 9)` → `Recompose res: true`,
  `0,0,0,0,0,8,0,0,0,0,9,0,1,2,3,1`. Delete lines 1826-1830 of
  `matrix3d_recompose` (the three `if (sxyz == 0) m[..] = 1e-15;` lines and the
  `return avm2_bool(!(sx3 == 0 || sy3 == 0 || sy3 == 0));` — note that
  expression also carries a replicated upstream `sy3` typo, which becomes moot).
  Return `false` only for a null component (fix F) or `length < 3` (already
  correct — the `count 0/1/2` lines already match).
  *Risk: none, and it is a latent correctness win.* `matrix3d_compose` (passing)
  expects `Recomposed zero scale: 0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,1` and currently
  only passes because its `epsilon = 0.01` swallows `1e-15`; it does not print
  that call's return value.

Confidence on test 9 is **medium-high** rather than very high only because it is
the one row where the passing bar depends on a 113-line prefix rather than on a
handful of lines; the three sub-fixes themselves are each individually verified.

---

## 5. Dispositions checked (per common brief rule 2)

`ignored_tests.txt`, `ACCEPTED_DIFFS.md`, `RUFFLE_VS_FLASH_DIFFERENCES.md`,
`RUFFLE_COMPAT_TWEAKS.md`, `FLASH_BUGS_REPLICATED.md` — **zero matches for
`matrix3d`**. Nothing in this batch is dispositioned; all nine are live.

Per the s14 lesson "before adding a name, grep for a test that wants it absent":
I content-grepped every `.as` in the corpus for each method being changed. All
call sites outside the nine tests pass well-formed arguments (full 16-element
vectors, non-zero axes, non-null parameters), so no `#2007`/`#2004`/`#1126`
guard added here is reachable from a currently-passing test. The two behavioural
changes that *are* reachable (`transformVector` `w`, `recompose` zero-scale) both
move a passing test from a false pass to a true pass.

---

## 6. Notes for the wave-2 agent

* **The nine test dirs are now present in the main tree** at
  `ruffle-tests/tests/swfs/avm2/matrix3d_{append,append_rotation,copy_column,copy_raw_data_from,copy_raw_data_to,copy_row,prepend,recompose_edge_cases,transform_vector}`
  (plus `matrix3d_position`, `matrix3d_transpose`, which already pass). They are
  gitignored, so `cp -r` them into your worktree's
  `ruffle-tests/tests/swfs/avm2/` and pass `--recompile` on first use.
  Their `RecompiledABC` caches in the main tree are warm from this pass.
* Runtime-only change → the main tree's `SWFRecomp/build` can be reused.
* Regression set to run alongside the nine: `avm2/matrix3d`,
  `avm2/matrix3d_compose`, `avm2/matrix3d_invert`, `avm2/matrix3d_position`,
  `avm2/matrix3d_transpose`, `avm2/perspective_projection`,
  `avm2/perspective_projection_basic`, `avm2/vector3d`,
  `from_shumway/avm2/flash/geom/matrix3d/Matrix3DClass`,
  `from_shumway/avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass`,
  and one Stage3D consumer of `copyRawDataFrom`/`appendRotation`
  (`avm2/stage3d_rotating_cube`).
* CI mode: `graphics`, `categories=all` is sufficient — the change is AVM2
  runtime but not recompiler emission; `full` is optional insurance.
* Scratch artifacts (per-test `--diff` logs and `--save-actual` captures) are in
  `/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/4887379b-7447-4810-a394-1c76f24b1248/scratchpad/`.
