# Wave-2 — matrix3d batch (session 15, dual-axis fan-out #7)

Agent: `w2-matrix3d`. Worktree
`/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ad21b747417b8a308`,
base `42a324cef`. Patch: `w2-matrix3d.patch` (worktree root; also copied to
`SWFRecompDocs/plans/session15-fanout-reports/w2-matrix3d.patch` in the main
tree). Apply with `git apply` from the repo root — it touches only
`SWFModernRuntime/src/avm2/avm2_stage3d.c`.

---

## 1. Verdict — wave-1 held on all nine rows, first try

**9/9 flips landed exactly at the predicted bar.** No refutation: every
mechanism claim in `wave1-matrix3d.md` reproduced, including the three
"non-obvious constraints" and both `ruffle_matched` ceilings.

| # | Test (`avm2/`) | Before | After | Predicted |
|---|---|---|---|---|
| 1 | `matrix3d_append` | output_mismatch | **PASS** | pass ✓ |
| 2 | `matrix3d_prepend` | output_mismatch | **PASS** | pass ✓ |
| 3 | `matrix3d_copy_column` | output_mismatch | **PASS** | pass ✓ |
| 4 | `matrix3d_copy_row` | output_mismatch | **PASS** | pass ✓ |
| 5 | `matrix3d_copy_raw_data_from` | output_mismatch | **PASS** | pass ✓ |
| 6 | `matrix3d_copy_raw_data_to` | output_mismatch | **PASS** | pass ✓ |
| 7 | `matrix3d_transform_vector` | output_mismatch | **PASS** | pass ✓ |
| 8 | `matrix3d_append_rotation` | output_mismatch | **RUFFLE_MATCHED** | ruffle_matched ✓ |
| 9 | `matrix3d_recompose_edge_cases` | output_mismatch | **RUFFLE_MATCHED** | ruffle_matched ✓ |

Effective trace delta: **+9** (7 outright passes + 2 `ruffle_matched`).
Runner summary after the patch: `Pass 7 / Ruffle-matched 2 / Effective pass 9
(100.0%) / Fail 0`. Baseline for the same nine, same command, before the
patch: `Fail 9, all output_mismatch`.

Residues on the two `known_failure` rows are exactly the free sets wave-1
priced:

* `matrix3d_append_rotation`: one line, index 22
  (`appendRotation zero axis, NaN pivot`, we give `NaN,NaN,NaN,0,…,1`, Flash
  gives all-16-NaN) — inside Ruffle's own diff set `{14,15,22}`, and we are
  strictly better than Ruffle on 14 and 15. Not chased, per brief.
* `matrix3d_recompose_edge_cases`: diff starts at expected line **114** and
  ends inside line 198 — the quaternion/axis-angle `#2004` block Ruffle does
  not implement. Expected lines **1–113 are byte-exact**. Not chased, per
  brief.

---

## 2. Patch scope

One file, `SWFModernRuntime/src/avm2/avm2_stage3d.c`, +81/−25 lines. No
header, no registration, no recompiler change — wave-1's "member-semantics
batch, not a missing-class batch" refutation is confirmed.

Touched functions (in file order):

| Function / symbol | Change |
|---|---|
| `s3d_throw_2007` (l.85) | `argument_error_class` → `type_error_class` |
| `s3d_arg_object_non_null` (new, after `s3d_arg_object`) | shared null-parameter guard |
| `matrix3d_copy_raw_data_from` | `#2007 source`; `#2004` when `index+16 > source.length` |
| `matrix3d_copy_raw_data_to` | `#2007 dest`; fixed-vector `#1126` precheck before any write |
| `matrix3d_append` | `#2007 lhs` |
| `matrix3d_prepend` | `#2007 rhs` |
| `m3d_build_rotation` | zero-length axis skips only the division |
| `matrix3d_xform` (kind==2) | `#2007 axis` (pivot stays nullable) |
| `matrix3d_transform_vector_common` | `#2007 vector`; computes and returns `w` |
| `m3d_orientation_arg` | NULL → `#2007 orientationStyle`; UNDEFINED still defaults |
| `matrix3d_recompose` | validation reorder; null component → false + untouched; zero scale → literal 0 + true |
| `matrix3d_copy_vec_to` / `matrix3d_copy_vec_from` | `#2007 vector3D` **before** the `#2004` range check |

### Notes on the three tricky constraints

1. **Null before range** in `copyColumn*`/`copyRow*` — confirmed by
   `copyColumnTo(4, null)` / `copyColumnFrom(4, null)` expecting `#2007`.
   Implemented by resolving arg 1 (and throwing) before the `idx > 3` test;
   the `avm2_coerce_to_u32` of arg 0 still runs first and is side-effect-free.
2. **NULL vs UNDEFINED for `orientationStyle`** — `m3d_orientation_arg` now
   throws on an explicit NULL and keeps the `"eulerAngles"` default for
   omitted/UNDEFINED. `matrix3d_compose` (which relies on the default and on
   `recompose(Vector.<Vector3D>([]), "badOrientation")` → `#2187`) still
   passes. The helper is shared with `decompose`, which gains the same
   (correct, untested-here) null rejection.
3. **`recompose` ordering** — components-null → orientationStyle-null →
   `#2187` spelling → `length < 3`, verified against the test's three
   `testException` closures in that order.

### `#2007` is a TypeError everywhere

`s3d_throw_2007` is shared with the Stage3D/Context3D paths. Corpus grep
(`ruffle-tests/tests/swfs/**`) finds **zero** occurrences of
`ArgumentError: Error #2007` in any `output*.txt`, and no Stage3D-family test
exercises a `must be non-null.` message at all, so the class change is
invisible outside the matrix3d batch. Ruffle raises #2007 through
`make_null_or_undefined_error` (TypeError) universally.

---

## 3. Canaries (run individually, after the patch)

**11/11 PASS — zero regressions.**

| Test | After |
|---|---|
| `avm2/matrix3d` | PASS |
| `avm2/matrix3d_compose` | PASS |
| `avm2/matrix3d_invert` | PASS |
| `avm2/matrix3d_position` | PASS |
| `avm2/matrix3d_transpose` | PASS |
| `avm2/perspective_projection` | PASS |
| `avm2/perspective_projection_basic` | PASS |
| `avm2/vector3d` | PASS |
| `avm2/stage3d_rotating_cube` | PASS |
| `from_shumway/avm2/flash/geom/matrix3d/Matrix3DClass` | PASS |
| `from_shumway/avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | PASS |

All eleven were `PASS` in the grading baseline `31647430265`, so this is a
straight hold. Three of them exercise the changed branches directly:

* `avm2/stage3d_rotating_cube` drives `copyRawDataFrom` and
  `appendRotation` (full 16-element sources at index 0, non-zero axes) — the
  new `#2004` and the rotation branch change are unreachable for it, as
  wave-1 predicted.
* `avm2/matrix3d_compose` drives the `recompose` default style, the `#2187`
  arm, and `Recomposed zero scale` — now `0,0,…` from the literal-zero rule
  instead of `1e-15` swallowed by its `epsilon = 0.01`.
* `avm2/matrix3d` now emits `mat.transformVector(v): 3857 4266 4675 5176`
  byte-exactly (it was `… 0` before and only passed through the harness
  looseness in §4). Its two remaining tolerated lines (`Too long:` from the
  `Matrix3D(Vector)` constructor, and two float-rounding lines) are unchanged
  — the constructor's silent identity-fill was deliberately left alone.

---

## 4. Harness finding carried forward (NOT acted on)

Wave-1 §2.4: `avm2/matrix3d` false-passes the line
`mat.transformVector(v): 3857 4266 4675 5176` because
`_lines_approx_equal` (`verify_output.py:1008-1036`) uses `pattern.search()`
and then strips *all* numbers from both sides. With fix D the line is now
produced correctly, so that test passes for the right reason — but the
looseness itself is untouched, per the brief (tightening `search` →
`finditer` would reprice an unknown number of currently-passing
`[approximations.number_patterns]` tests corpus-wide). Recorded for a
separate arc.

## 5. Dispositions

Re-checked `ignored_tests.txt`, `ACCEPTED_DIFFS.md`,
`RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
`FLASH_BUGS_REPLICATED.md`: zero `matrix3d` entries. Nothing added — the two
`ruffle_matched` residues are upstream `known_failure` rows already carrying
`output.ruffle.txt`, which is the intended mechanism.

## 6. Merge notes

* Runtime-only change; CI mode `graphics`, `categories=all` is sufficient
  (`full` optional insurance).
* The nine test dirs are gitignored upstream mirrors that arrived in the s14
  drift; they exist in the main tree already (wave-1 copied them) and CI
  re-downloads them.
* No sibling agent edits `avm2_stage3d.c`; the one new symbol
  (`s3d_arg_object_non_null`) is `static` and local to that file.
