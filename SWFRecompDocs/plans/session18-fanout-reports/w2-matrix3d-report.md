# Session 18 · wave 2 · `w2-matrix3d` — Matrix3D + Vector3D trace flips

**Agent:** `w2-matrix3d` (isolated worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-abd254012556a5636`).
**Base:** `8f68a5fea`. **Brief:** `session18-fanout-reports/w2-matrix3d-brief.md`.
**Diagnosis of record:** `w1-trace-new-report.md` §2 (#1–#4) and §3 (#5).
**Patch:** `SWFRecompDocs/plans/session18-fanout-reports/w2-matrix3d.patch`
(worktree `git diff`, includes the disposition-doc edit).

## NEW FILES

**None.** Two runtime files modified plus one disposition doc:

| file | scope |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_stage3d.c` | `matrix3d_xform` #2183 guard; `copyFrom`/`copyToMatrix3D` #2007 guard; new `m3d_quaternion_of` / `m3d_interpolate_raw` / `m3d_interp_throw_2007` / `matrix3d_interpolate` / `matrix3d_interpolate_to` statics; two vtable registrations |
| `SWFModernRuntime/src/avm2/avm2_display.c` | `v3_near_equals` only (Vector3D region, ~line 10643). Did **not** touch the MovieClip or flash.ui regions that `w2-avm2-new-smalls` owns. |
| `ruffle-tests/tests/swfs/avm1/_investigation/FLASH_BUGS_REPLICATED.md` | new `[AVM2] Vector3D.nearEquals ASSIGNS this.w` entry, inserted before the colorTransform entry |

No new headers, no CMake/Emscripten/`verify_output.py` source-list change,
no recompiler change. **Runtime-only** — the main tree's `SWFRecomp/build` was
copied in, which is valid for this patch class.

---

## 0. VERDICT — 5 GO / 5 landed. Wave-1 pricing held at 100%.

| # | test | before | after (no-gfx) | after (gfx) |
|---|---|---|---|---|
| 1 | `avm2/matrix3d_append_prepend_scale` | `output_mismatch` 0/86 | **pass** | **pass** |
| 2 | `avm2/matrix3d_copy_from` | `output_mismatch` 15/19 | **pass** | **pass** |
| 3 | `avm2/matrix3d_copy_to_matrix3d` | `output_mismatch` 15/19 | **pass** | **pass** |
| 4 | `avm2/matrix3d_interpolate` | `output_mismatch` 0/21 | **pass** | **pass** |
| 5 | `avm2/vector3d_near_equals` | `output_mismatch` 67/80 | **pass** | **pass** |
| R | `avm2/matrix3d_append_rotation` (rider) | `ruffle_matched` | `ruffle_matched` | `ruffle_matched` |

**+5 corpus flips, 0 regressions across 46 distinct tests run** (see §5).
The rider is unchanged in both modes — no `ruffle_matched -> output_mismatch`
move, and no accidental `-> pass` either (its residual is a single line, §7 L1).

---

## 1. #1 `matrix3d_append_prepend_scale` — #2183 on a zero scale factor

`appendScale`/`prependScale` now reject a zero factor of **either sign** before
touching the matrix (Ruffle `core/src/avm2/globals/flash/geom/matrix_3d.rs:147`
and `:223`, `x.is_zero()`). The guard lives inside `matrix3d_xform`'s
scale/translate arm behind `kind == 1`, so `appendTranslation` /
`prependTranslation` (which legitimately take zeros) are untouched.

Two details that are NOT in the wave-1 report and that I had to decide:

* **The check reads the RAW f64, not the f32-cast value.** The existing code
  casts every argument through `float` first (the `matrix3d_precision`
  invariant). Ruffle checks `x` before its `x as f32`, so a value that only
  *underflows* to zero in f32 — `appendScale(1e-300, 1, 1)` — still scales
  rather than throwing. I split the read into `rx/ry/rz` (raw) and `x/y/z`
  (f32-cast) to preserve both invariants at once. Nothing in the corpus
  grades this, but the two orders are genuinely distinguishable and Ruffle's
  is the one the oracle would produce.
* **A missing argument now throws.** The old default for `kind == 1` was
  `1.0`; Ruffle's `FunctionArgs::get_f64` yields `0.0`, so
  `new Matrix3D().appendScale()` throws #2183 under Ruffle. I moved the
  default to `0.0`, which routes every missing argument into the new throw.
  This is **ungraded by the corpus** — flagging it as a deliberate
  Ruffle-alignment choice, not as evidence.

Regression scan (independent of the wave-1 one, redone over the full corpus):
every `.as` call site of `appendScale`/`prependScale` was checked for a zero
argument. Only the fixture itself passes zeros. `matrix3d_invert`'s
"singular" cases build from `appendTranslation`, not zero scale;
`from_shumway/.../Matrix3DClass` uses `Math.random()*200-100` (deterministic
seed, no zero drawn); `stage3d_*` and `geom_transform` pass literal non-zeros.

## 2. #2/#3 `matrix3d_copy_from`, `matrix3d_copy_to_matrix3d` — #2007 guards

Exactly as diagnosed: both used `s3d_arg_object(act, 0)` and silently no-oped
on NULL. Swapped for the existing `s3d_arg_object_non_null(act, 0, "source")`
/ `"dest"` helper. One statement each. Both flipped to `pass`.

## 3. #4 `matrix3d_interpolate` — ~150 LOC port; the MEDIUM confidence was over-cautious

`interpolateTo` and the static `interpolate` were both registered as
`s3d_noop`. Ported per Ruffle `geom/Matrix3D.as:69-175`:

* `m3d_quaternion_of(raw, q)` — normalized quaternion of the upper-left 3×3
  **with the scale left in** (the whole point of the test's "rot+scale" row),
  trace-branching exactly as the `.as`, zero-length → `(0,0,0,1)`.
* `m3d_interpolate_raw(a, b, percent, out)` — translation lerp, quaternion
  slerp (dot-negate, `dot > 0.9995` → plain lerp, else `acos`/`sin`),
  renormalize (zero-length → identity quaternion), then the **unit-scale
  specialization of `matrix3d_recompose`'s quaternion arm** written inline.
* `matrix3d_interpolate` (static) validates `fromMat` then `toMat` and
  returns a fresh matrix through the existing `avm2_geom_matrix3d_new`.
* `matrix3d_interpolate_to` validates `toMat` **itself** — so the trace
  carries no `interpolate()` frame — and narrows the result into `this`.

**Deviation from the brief's letter:** I did not build a
`Vector.<Vector3D>` and call `matrix3d_recompose` through the vtable; I
inlined the unit-scale quaternion arm. The `sx3/sy3/sz3` factors are all `1`
in this path, so every term is identical, and the result is graded by all
nine value rows of the fixture.

**Refutation of the wave-1 risk note.** The report priced this MEDIUM —
"the only real risk is that our f32 `rawData` + `recompose(quaternion)`
disagree with Ruffle's at the 6th decimal." That risk did not materialize at
all: the test passed on the **first** build, in both modes, with no tuning.
`Math.round(n*1e6)/1e6` in the fixture, plus the fact that both sides do the
same f64 math on the same f32-widened inputs, leaves no room to diverge.
Confidence for future ports of this shape (pure-arithmetic `.as` bodies over
`rawData`) should be HIGH, not MEDIUM.

The synthetic class-side frame `flash.geom::Matrix3D$/interpolate` reuses
`avm2_globals.c`'s `System$/exit` idiom verbatim (pop our own frame, push an
`Avm2MethodRef` with `fn = NULL, file = NULL`, throw). Both #2007 stack traces
render frame-for-frame on the first try.

## 4. #5 `vector3d_near_equals` — the assignment half of the FP bug

`v3_near_equals` compared `|toCompare.w|` (half the bug) but never performed
the `this.w = toCompare.w` write. Restructured so the x/y/z arms are evaluated
first and the `w` arm runs **only** when `all_four` is set and x/y/z passed —
preserving the `&& (!allFour || ...)` short-circuit, which is what decides
whether the side effect happens at all. All 13 stale `v1 = ...` lines fixed.

`FLASH_BUGS_REPLICATED.md` gained a full `[AVM2]` entry. There was **no**
prior entry for this bug (the wave-1 report's "the existing entry (if any)"
hedge resolves to "none"; the only record was the one-line code comment).
Not added to `ignored_tests.txt` — the test now passes, so it is not an
accepted diff.

---

## 5. Tests run (46 distinct tests, 0 regressions)

All runs `--diff --verbose`, `SWFRECOMP_COMPILE_TIMEOUT=2400`, at most 2
concurrent batches. Test dirs `cp -r`'d into the worktree's canonical suite
paths, `--recompile` on first use. Logs:
`<scratchpad>/w2-matrix3d/{base,after}/*.log`.

**Headline + rider (no-graphics), before → after**

| test | before | after |
|---|---|---|
| `matrix3d_append_prepend_scale` | output_mismatch | **PASS** |
| `matrix3d_copy_from` | output_mismatch | **PASS** |
| `matrix3d_copy_to_matrix3d` | output_mismatch | **PASS** |
| `matrix3d_interpolate` | output_mismatch | **PASS** |
| `vector3d_near_equals` | output_mismatch | **PASS** |
| `matrix3d_append_rotation` | ruffle_matched | ruffle_matched |

**Canary batch A — `avm2` (13 tests): 12 PASS + 1 RUFFLE_MATCHED, effective 13/13 (100%)**
`matrix3d`, `matrix3d_append`, `matrix3d_append_prepend_translation`,
`matrix3d_append_rotation` (RM, pre-existing), `matrix3d_compose`,
`matrix3d_constructor_clone`, `matrix3d_copy_column`,
`matrix3d_copy_raw_data_from`, `matrix3d_copy_raw_data_to`,
`matrix3d_copy_row`, `matrix3d_determinant`, `matrix3d_invert`,
`matrix3d_position`.

**Canary batch B — `avm2` (14 tests): 13 PASS + 1 RUFFLE_MATCHED, effective 14/14 (100%)**
`matrix3d_precision`, `matrix3d_prepend`, `matrix3d_raw_data`,
`matrix3d_recompose_edge_cases` (RM, pre-existing), `matrix3d_transform_vector`,
`matrix3d_transpose`, `perspective_projection`, `perspective_projection_basic`,
`utils3d`, `vector3d`, `geom_transform`, `stage3d_blend`, `stage3d_stencil`,
`stage3d_fractal`.

**Canary batch C — `from_shumway` (3 tests): 3/3 PASS**
`avm2/flash/geom/matrix3d/Matrix3DClass` (the only corpus consumer of
`appendScale` with computed arguments), `avm2/flash/geom/matrix3d/TransformBasics`,
`avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass`.
These are **not** in the brief's canary list — I added them because
`Matrix3DClass.appendScale()`/`prependScale()` feed `Math.random()`-derived
factors into the new #2183 guard, which is the single riskiest edge of this
patch.

**Regression suite (8 tests): 8/8 PASS**
`avm2_typed_value_ops`, `avm2_graphics_runtime`, `avm2_static_text`,
`avm2_timeline_solid`, `avm2_morph`, `avm2_simplebutton_click`,
`avm2_goto_catchup_scale`, `avm2_reflect_trait_hooks`. (A grep of the whole
`regression` suite for `Matrix3D`/`Vector3D` returns **nothing**, so this is a
build-and-blast-radius check on `avm2_display.c`, not a targeted one.)

**`--mode=graphics` (CI grading mode, 8 tests): 7 PASS + 1 RUFFLE_MATCHED, effective 8/8 (100%)**
`matrix3d_append_prepend_scale`, `matrix3d_interpolate`, `vector3d_near_equals`,
`matrix3d_copy_from`, `matrix3d_copy_to_matrix3d`, `matrix3d_precision`,
`vector3d`, `matrix3d_append_rotation` (RM).
Every one of the eight is identical under both modes, as expected for a pure
AVM2-runtime change.

*Worktree gotcha worth propagating:* `--mode=graphics` resolves Dawn relative
to the tree root, so in a wave-2 worktree the default becomes
`.claude/worktrees/dawn-install` and the run dies before compiling. Export
`DAWN_INSTALL=/home/robert/CC/dawn-install`.

---

## 6. Refutations / corrections to the wave-1 pricing

1. **Magnitude and mechanism both held for all five rows.** Nothing was
   refuted downward — this is one of the cleaner wave-1 boards.
2. **#4's MEDIUM confidence was too pessimistic** (§3). The f32 / 6-decimal
   risk is not a real risk for this class of port.
3. **#1's LOC estimate (~12) was low; the real cost is ~20**, because the
   raw-vs-f32 split has to be introduced to keep `matrix3d_precision` green
   while checking zero the way Ruffle does. The report treated the f32 cast
   as irrelevant to the guard; it is not.
4. **#5's "the existing entry (if any)"** resolves to *none* — the
   `FLASH_BUGS_REPLICATED.md` change is an addition, not an amendment.
5. **The report's canary list omitted `from_shumway/.../Matrix3DClass`**,
   the only corpus test that feeds *computed* values into
   `appendScale`/`prependScale`. It passes, but a zero-producing RNG draw
   there would have been a silent pass→fail that no listed canary covers.
   Any future change to a geom argument guard should include the
   `from_shumway/avm2/flash/geom/**` tests as canaries by default.

---

## 7. New unclaimed leads

**L1 — `avm2/matrix3d_append_rotation`: `ruffle_matched` → `pass` is ONE line.**
With `--save-actual`, our output differs from Flash's `output.txt` in exactly
one of 23 lines:

```
- appendRotation zero axis, NaN pivot: NaN,NaN,NaN,NaN,NaN,NaN,NaN,NaN,NaN,NaN,NaN,NaN,NaN,NaN,NaN,NaN
+ appendRotation zero axis, NaN pivot: NaN,NaN,NaN,0,NaN,NaN,NaN,0,NaN,NaN,NaN,0,NaN,NaN,NaN,1
```

The zero-axis rows (which Ruffle gets wrong) we already match Flash on —
`m3d_build_rotation` deliberately skips normalization for a zero-length axis.
The residual is that Flash lets a NaN pivot contaminate the **fourth column
and `m[15]`** too, i.e. Flash's pivot path is not the "write `t[12..14]` only"
shortcut we (and Ruffle) use — it must run a real 4×4 product against a matrix
whose 4th column is already NaN. Estimated ~10 LOC in `matrix3d_xform`'s
`kind == 2` arm. Risk: it changes the non-NaN pivot rows too, so the whole
test is its own canary. This is a `ruffle_matched -> pass` move (+0 effective,
+1 true pass).

**L2 — `avm2/matrix3d_recompose_edge_cases`: `ruffle_matched`; Flash throws #2004 where we return `true`.**
`output.txt` vs `output.ruffle.txt` disagree on the quaternion arm: Flash
raises `ArgumentError: Error #2004: One of the parameters is invalid.` at
`flash.geom::Matrix3D/recompose()` for at least two quaternion cases where
Ruffle (and we) report `Recompose res: true` and write the matrix — ~7 diff
lines per case. The existing comment in `matrix3d_recompose` documents the
*zero-scale* edge cases as measured; this #2004 predicate on the rotation
component is separate and undiagnosed. Needs a wave-1-style diagnosis pass
first — do not price it blind.

**L3 — `Matrix3D.pointAt` and `Utils3D.pointTowards` are still `s3d_noop`**
(`avm2_stage3d.c` `register_*` block). Ruffle also stubs `pointAt`
(`stub_method`), so there is no oracle for it in the corpus today and no test
grades it. Recorded only so a future agent does not rediscover it as a lead
with no test behind it.

**L4 — the `System$/exit` synthetic-frame idiom now has three users**
(`system_exit`, `Error$/throwError`, `Matrix3D$/interpolate`). Each exists
because `avm2_callstack_frame_name` cannot tell a static builtin frame from an
instance one. An "is static" bit on `Avm2CallFrame` would retire the idiom and
unblock every future class-side builtin that must appear in a stack trace.
Small, mechanical, and it removes a foot-gun — the pop-then-push dance is easy
to get wrong.
