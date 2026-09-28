# w2-image-semantics: image comparator ALL-checks + `filter` (s21, TOOLING / pixel axis)

**New files (stage by name):**
- `SWFRecompDocs/plans/session21-fanout-reports/w2-image-semantics-report.md` (this file)
- `SWFRecompDocs/plans/session21-fanout-reports/w2-image-semantics.patch`

The patch creates no new files in the tree. It modifies 7 tracked files, listed below.

## Verdict: GO (baseline correction, not yield). Priced at **413 → 408 pixel passes (−5)**

The pricing is complete, not a sample-based estimate. All 55 multi-check comparisons that pass today
are decided: 11 from the stored stats and 44 from local `--mode=graphics` runs. For all 48
comparisons rendered locally, `max_diff` and `diff_channels` matched run `35423176371` exactly,
so the per-check outlier counts below are what CI will compute.

**Predicted pass → fail (5):**

| comparison | failing check(s) under ALL (tol: outliers / limit) | the check that let it pass under ANY |
|---|---|---|
| `from_shumway/acid/acid-clip [output]` | tol 64: 397/140; tol 0: 7033/7000 | tol 150: 0/0 |
| `from_shumway/acid/acid-bitmapData-draw [output]` | tol 32: 416/250; tol 64: 192/50; tol 128: 20/0 | tol 0: 600/650 |
| `from_shumway/acid/acid-shapes [output]` | tol 16: 61374/61300; tol 32: 25681/25600 | 4 others |
| `from_shumway/acid/acid-small [output.01]` | tol 80: 3657/3000 | tol 0, tol 20 |
| `visual/cache_as_bitmap/text [output]` | tol 128: 6681/1500 | tol 0: 10233/12000 |

None of the five is a render change. Book the drop as a correction when the `images=true`
grading run lands. `image_status_diff.py` tags these rows `[ANY->ALL, render unchanged]`.

**Anticipate at the grading run:**
- The **11 multi-check comparisons that already fail** stay failing. Their headline
  `outliers`/`excess_outliers` now name the failing check furthest past its budget. Before
  this patch they named the check with the fewest outliers. Expect **band moves with no render
  change** on: `avm2/bitmapdata_draw`, `avm2/blend_shader_luma_lighten`, `avm2/displayobject_z`,
  `avm2/graphics_direct_commands`, `from_shumway/3_joystick`,
  `acid/acid-bitmap-draw_quality_high`, `acid/acid-bitmap-draw_quality_low`, `acid/acid-filter-2`,
  `acid/acid-morph`, `from_shumway/avm1/text-bind`,
  `visual/edittext/edittext_device_transform_negative`. Rule 14 applies: a real render
  regression moves `max_diff`.
- **Fragile passes** (≤2 % slack on a secondary check). These are the next comparisons to flip on any drift:
  - `from_shumway/flash_text_TextField2`: tol 128, 250/250, **zero slack**
  - `acid/acid-small [output.05]`: tol 80, 2997/3000
  - `avm2/stage3d_rotating_cube`: tol 3, 2148/2160; tol 32, 244/250
  - `acid/acid-shapes`: tol 64, 5574/5600 (already failing on tol 16/32)
  - `acid/acid-blend-2 [output.40]`: tol 40, 1467/1500
  - `avm2/stage3d_blend`: tol 16, 5064/5200
- **`filter` moves nothing today.** Three tomls use it: `edittext_bounds_vs_position`,
  `edittext_underline_scale2` and `filters/displacement_map`. On Linux x86_64 the applicable
  check is the stricter one in each (w1 confirmed), and the renders are unchanged:
  `displacement_map` fails either way, and the other two pass under their non-macOS check.
- Trace pass/fail is untouched, because images never gate trace.

## Premise attack: confirmed, with one detail sharpened

I read Ruffle `0dacba55f` myself:
- **`tests/framework/src/runner/image_test.rs::test`** loops over the checks. It skips a check
  whose `filter.evaluate()` is false, returns `Ok(Some(ImageDiff))` on the **first** check with
  `outliers > max_outliers`, and returns `Err("No checks executed.")` if every check was
  filtered out. This is ALL semantics. With zero applicable checks the comparison is a test
  **error**, which is a fail, never a pass.
- **`options/image_comparison.rs::checks()`**: if both simple (`tolerance`/`max_outliers`) and
  `checks` are defined, it is an **error**, so the comparison fails. If neither is defined, you
  get one tol-0/0-outlier check. We used to take the simple values silently. No corpus toml has
  both today, so that change moves nothing.
- **`options/expression.rs`**: `filter` is a `cfg_expr` expression with the predicates
  `os`, `arch` and `family`, evaluated against `std::env::consts`. Any other predicate is an
  error. `all()`, `any()` and `not()` are allowed.
- Outlier counting runs per channel (RGBA) with `diff > tolerance`, the same as our code. I did
  not change it.

## Mechanism / patch scope (`w2-image-semantics.patch`, 7 files, Python + docs only)

- `ruffle-tests/verify_output.py`
  - `parse_image_comparisons`: keeps each check's `filter`, and sets `config_error` when simple
    and advanced checks are mixed.
  - New `evaluate_check_filter(expr)` and `IMAGE_FILTER_PLATFORM`. The platform is **pinned to
    linux / x86_64 / unix** (CI's platform) so local runs grade like CI. You can override it
    with `SWFRECOMP_IMAGE_FILTER_OS/_ARCH/_FAMILY`.
  - `compare_images(..., config_error=None)` grades **every** check and passes only if all
    applicable checks pass. If every check is filtered out it fails with
    `error=no_checks_executed`, a bad filter gives `error=bad_filter`, and a config error gives
    `error=simple_and_advanced_checks`. Outliers are now computed from one 256-bin histogram,
    which gives exact counts and is faster than one pixel loop per check.
  - **The stats schema is additive.** `checks` is a list of `{tolerance, max_outliers,
    outliers, passed[, filter, skipped]}`, alongside `applicable_checks` and `failed_checks`.
    The flat `outliers`/`max_outliers`/`tolerance`/`excess_outliers` fields keep their meaning
    for single-check comparisons. On a multi-check comparison they name the binding check: on a
    fail, the one with the largest excess; on a pass, the one with the least slack and
    `excess 0`. Messages keep the `N outliers … max difference M` shape that
    `run_image_tests.py` regex-parses, with `(check tol T; k of n checks failed)` / `(n checks)`
    appended.
- `ruffle-tests/run_image_tests.py` passes `config_error` through to its re-grade path.
- `scripts/image_status_diff.py` reads old-format files unchanged. When one side lacks
  per-check rows (pre-s21) and the other has them, it prints a **GRADING SEMANTICS DIFFER**
  banner. Pass → fail rows list their failing checks and are tagged
  `[ANY->ALL, render unchanged|also moved]`. I tested this on synthetic old/new dir refs
  derived from the real `from_shumway` JSON: exactly 1 regression, tagged correctly.
- `scripts/image_triage.py` keeps `tolerance`, `checks`, `applicable_checks` and
  `failed_checks` in its rows (all `None` on old files), and `--test` prints each check's
  verdict.
- `build_image_report.py` needs no change, because it already flattens all `stats` keys into rows.
- Docs:
  - `HEADLESS_SETUP.md:226` is corrected.
  - `TEST_HARNESS_COMPARISON.md` (two places) is corrected.
  - `graphics-fanout-playbook.md` §19 ends with a new "s21 correction" paragraph.
  - Old session reports are not rewritten.

## Tests run

- **Unit** (scratchpad `unit.py`, synthetic PNGs), 9/9: single pass/fail; ANY-would-pass
  but ALL fails; both pass; a filtered-out failing check; a filtered-in failing check; all checks
  filtered out → fail; unknown predicate → fail; config_error → fail. Filter evaluator: `not()`,
  `all()` and `any()` cases, plus an error on `target_os` and on a bare `os`.
- **Local `--mode=graphics --images`, sequential, with the worktree recompiler built fresh.**
  18 tests / 48 comparisons, listed above. All renders matched CI.
- **Regression suite:** `regression/avm2_parent_child_render` (tolerance pass, 96/400) and
  `regression/mask_sibling_union` (strict) both pass. No regression-suite toml has multi-check.
- `py_compile` passes on all edited scripts.

## Corpus enumeration

587 image comparisons, which equals the pixel baseline denominator. **66** have more than one
applicable check on Linux x86_64: **55** pass today and 11 fail. Three tomls use `filter`. None
has a config error. The script is at scratchpad `w2-image-semantics/enumerate.py` (output in
`enumerate.json`). It is reusable: it bounds each check's outliers using the stored points
(tol 0 = `diff_channels`, the tolerance of the check that passed, and `max_diff` → 0).

## New unclaimed leads

- The zero-slack and near-zero-slack passes listed above are the pixel axis's most fragile
  rows. A canary member on `flash_text_TextField2` (250/250) would catch drift.
- Ruffle's per-comparison `known_failure` for images compares against `NAME.ruffle.png`.
  We still ignore that (we only record the flag). It is out of scope here, and I have not
  checked what it would move.
