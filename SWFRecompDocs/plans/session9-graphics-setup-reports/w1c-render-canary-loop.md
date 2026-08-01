# w1c — Local Render-Canary Loop: validation + spec

Session 9 graphics-infrastructure setup, wave-1 agent C.
Baseline: `master` @ f56b898d9. All measurements taken on this machine
(WSL2, local Dawn at `~/CC/dawn-install`, ccache present, Pillow 12.1.0).

**Status: VALIDATED. The loop works today with zero code changes.** Every
piece a wave-2 render agent needs already exists in `verify_output.py`; the
only missing artifact is the driver script specced in §6.

---

## 0. TL;DR

| Question | Answer |
|---|---|
| Does the loop work locally? | Yes, end-to-end, unmodified `verify_output.py`. |
| Capture actual PNG regardless of verdict? | Yes — `SWF_KEEP_BUILD_DIR=DIR` env var. No new flag needed. |
| Is local Dawn deterministic run-to-run? | **Yes — byte-identical.** 4 tests, 17 PNGs, 0 differing bytes, including under `-P 2` load. |
| Canary bar? | **Byte-identical PNG (md5).** No epsilon needed. |
| Parallel safe at `-P 2`? | Yes. No contention, no crashes, no verdict changes. |
| Cost | Cold ~10–80 s/test (all compile); **warm re-run 2.6–6.8 s/test**. |
| Canary-eligible corpus | 381 tests carry `[image_comparisons]` (546 graded comparisons). |
| Expected PNGs needed? | **No.** A canary is our-vs-our; `skip` (no expected PNG) tests render fine. |

The last row matters beyond this report: the session-9 premise that
"expected-PNG acquisition is the blocker" is true for *grading* but **false
for the canary**. Wave-2 can regression-check its render work today against
all 381 eligible tests without acquiring a single expected PNG.

---

## 1. Basic loop (Q1) — works, with measured costs

Invocation (from repo root, `--tests-dir` always pinned):

```bash
SWF_KEEP_BUILD_DIR=/path/to/capture \
python3 ruffle-tests/verify_output.py \
    --tests-dir=ruffle-tests/tests/swfs/<suite> \
    --test=<NAME> --mode=graphics --images \
    --json=/path/to/result.json
```

Three probe tests, as briefed:

| Test | Suite | CI image verdict | Local verdict | Local stats | Wall (cold) |
|---|---|---|---|---|---|
| `color` | avm1 | **pass** (max_diff 1) | pass | max_diff 1, outliers 0/0 | 56.9 s |
| `gradient_same_ratios` | visual | **fail** (6912 outl, excess 1782) | fail | 6912 outl / limit 5130, excess 1782, max_diff 255 | 49.7 s |
| `avm2_timeline_gradients` | regression | **pass** (tol 255) | pass | max_diff 128 | 81.1 s |

Two findings worth flagging:

1. **Local stats reproduced the CI numbers exactly** on both graded probes
   (`gradient_same_ratios`: 6912/1782/255 local == 6912/1782/255 CI).
   This does **not** overturn the "local ≠ CI" rule — the known
   `bitmapdata_copypixels` counterexample stands, and *some* tests drift.
   It means local↔CI divergence is per-test, not global, so a local absolute
   verdict is *suggestive but unciteable*. The canary sidesteps this
   entirely by never comparing against CI or against expected PNGs.
2. **The image verdict is never printed to stdout.** It exists only in the
   `--json` report under `tests[0].image_comparisons`. Any canary or
   triage flow must pass `--json` — reading the console tells you only the
   *trace* pass/fail, which for render tests is almost always `pass`
   regardless of what the pixels did.

### Cost is 95%+ compile

Phase breakdown comes free in the JSON (`tests[0].phases`):

| Run | recomp | compile | run | wall |
|---|---|---|---|---|
| `focusrect_swf5` cold | 0.012 s | **61.30 s** | 0.42 s | 64.4 s |
| `focusrect_swf5` warm | 0.000 s | **1.64 s** | 0.47 s | 2.6 s |
| `avm2_timeline_gradients` cold | 0.000 s | **76.77 s** | 0.52 s | 81.1 s |
| `avm2_timeline_gradients` warm | 0.000 s | **4.18 s** | 1.24 s | 6.8 s |
| `blend_modes/multiply` cold-ish | 0.360 s | 9.96 s | 0.77 s | 12.3 s |
| `color` warm | 0.000 s | 1.31 s | 0.52 s | 2.8 s |

The actual *render* is sub-second everywhere. All cost is gcc, and ccache
removes essentially all of it on an unchanged re-run. Cold spread (10–80 s)
tracks the size of the test's own generated C, not the runtime — the shared
runtime TUs amortise after the first graphics build of the session.

**Budget implication for a 15-test canary:** ~10–15 min cold (once per
machine/session), ~1 min warm. The "after" leg of a real A/B costs the
changed TU's compile *once* (ccache is content-keyed and global) plus a
per-test link — call it cold-TU-time + ~15×2 s. Wave-2 should measure its
own first real after-leg rather than trust an estimate here.

---

## 2. Actual-PNG capture (Q2) — `SWF_KEEP_BUILD_DIR`, verified

**`--save-actual` is a red herring.** `verify_output.py:4067` writes the
*trace text* to that path, not a PNG. It has nothing to do with rendering.

**`--image-out-dir` is insufficient** — `verify_output.py:4037` gates the
export on `not passed`, so passing comparisons export nothing. A canary
needs actuals for passing tests above all.

**The working mechanism is the env var `SWF_KEEP_BUILD_DIR`**
(`verify_output.py:3808-3814`):

```python
_keepdir = os.environ.get("SWF_KEEP_BUILD_DIR")
_dir_cm = (_ctxlib.nullcontext(_keepdir) if _keepdir
           else tempfile.TemporaryDirectory(prefix="swf_verify_"))
```

Without it the build dir is a `TemporaryDirectory` that is destroyed on
exit, taking the PNGs with it — so "look in `/tmp/swf_verify_*`" does not
work. With it, the directory persists and contains:

- `<cmp>.png` — **the actual render**, one per `[image_comparisons.NAME]`
  entry. Written by `capture.c:114` via `renderer_save_png()` into
  `CAPTURE_OUTPUT_DIR` (= the build dir).
- `<cmp>.difference.png` — written by `compare_images()` only when
  `max_diff > 0`. Present on tolerance-passes and failures, absent on
  strict passes. Not needed by the canary but useful for eyeballing.

Verified empirically on all 5 probe tests. Multi-comparison tests work:
`avm1/focusrect_swf5` produced all 12 PNGs (`output.01a.png` …
`output.06b.png`).

**Verified: verdict-independence.** `regression/avm2_timeline_solid` has
image status `skip` ("No expected image: output.expected.png") and still
emitted a valid 7890-byte `output.png`. Rendering is enabled by the
*presence of an `[image_comparisons]` section* (which sets
`-DHEADLESS_RENDER_ENABLED`, `verify_output.py:2373`), not by the presence
of an expected PNG. **All 381 eligible tests are canary targets regardless
of expected-PNG availability or CI verdict.**

**Do NOT use `--verbose` for capture.** It also copies actuals into the
*test directory* (`verify_output.py:4042`), which is the wrong place: it
races between two runs of the same test, and while `avm1/*/` etc. are
gitignored, the `regression/` suite is fully git-tracked, so `--verbose`
there dirties the working tree. Build-dir capture has neither problem.

**No wave-2 flag work is required for capture.** (Optional nicety, not a
blocker: a `--image-capture-dir DIR` flag that copies every actual — pass
or fail — would be a 5-line addition next to the existing export. The env
var already covers it.)

### TOML gotcha for any tooling that enumerates canary targets

`[image_comparisons]` appears in **two syntactic forms**, and a naive
`grep '^\[image_comparisons'` silently misses ~15% of the corpus:

```toml
[image_comparisons.output]          # section form
tolerance = 37

image_comparisons."output".trigger = 1        # dotted form
image_comparisons."output.01a".trigger = 1    # dotted, dotted name
```

Enumerate with a plain substring match (`grep -rl image_comparisons
--include=test.toml`) or by parsing the TOML — never by section header.
Correct counts:

| Suite | eligible tests | | Suite | eligible tests |
|---|---|---|---|---|
| visual | 140 | | from_gnash | 9 |
| avm2 | 109 | | text | 5 |
| from_shumway | 71 | | regression | 5 |
| avm1 | 34 | | fonts | 4 |
| stage3d | 3 | | import_assets | 1 |
| **total** | **381** | | | |

---

## 3. Determinism (Q3) — byte-identical, bar is md5

Four tests, each rendered twice with no source change, actual PNGs compared
byte-for-byte:

| Test | Suite | PNGs | Run A context | Run B context | Result |
|---|---|---|---|---|---|
| `color` | avm1 | 1 | sequential, cold | **concurrent (-P 2)**, warm | **IDENTICAL** |
| `gradient_same_ratios` | visual | 1 | **concurrent (-P 2)**, cold | **concurrent (-P 2)**, warm | **IDENTICAL** |
| `avm2_timeline_gradients` | regression | 1 | **concurrent (-P 2)**, cold | **concurrent (-P 2)**, warm | **IDENTICAL** |
| `focusrect_swf5` | avm1 | **12** | **concurrent (-P 2)**, cold | sequential, warm | **IDENTICAL ×12** |

**17 of 17 PNGs byte-identical. Zero differing bytes.** Coverage spans
solid fills + colour transform, gradients, AVM2 timeline gradients, and a
12-frame input-event-driven multi-capture test. Both cold and warm builds,
both sequential and under concurrent load, produce bit-identical output.

**Verdict: the canary bar is `md5(before) == md5(after)`.** No tolerance,
no channel-stats epsilon, no per-test allowance. This is a much stronger
bar than the CI grading bar and makes the canary maximally sensitive: a
one-channel drift anywhere in the frame is caught.

Note the asymmetry that makes this work: the *expected*-vs-actual axis is
noisy across renderers (that is why CI grades on lavapipe), but the
*actual*-vs-actual axis on one machine with one renderer is exact. The
canary lives entirely on the exact axis.

Stats-comparison remains a useful **secondary tier** — not because
byte-compare is insufficient, but because when a canary test does DIFFER
you immediately want magnitude: is this 3 channels of ±1 or a whole
repaint? The `--json` stats block (`diff_channels`, `mean_diff`,
`max_diff`, `outliers`, `excess_outliers`) answers that with no extra work,
so the script should report it alongside the md5 verdict.

---

## 4. Parallel safety (Q4) — clean at `-P 2`

Four concurrent pairs run (`color`+`gradient_same_ratios`,
`gradient_same_ratios`+`avm2_timeline_gradients`,
`avm2_timeline_gradients`+`blend_modes/multiply`,
`blend_modes/multiply`+`focusrect_swf5`). Observed:

- No crashes, no SIGABRT, no GPU/Dawn device-lost, no timeouts.
- No verdict changes vs the same tests run sequentially.
- No PNG differences vs sequential runs of the same test (this is the
  determinism table above — three of those four A/B pairs straddle the
  sequential/concurrent boundary and still came out byte-identical).
- Each run must get its **own** `SWF_KEEP_BUILD_DIR`. Two concurrent runs
  sharing one build dir would clobber each other's sources and PNGs. The
  script must allocate per-run directories.

`-P 2` is validated. Higher fan-out is **not** validated here and should
not be assumed: the machine is shared, and the trace-side false-positive
modes (float formatting, long-compile timeouts) are documented as appearing
at `-P 6-8`. Recommend `-P 2` default, `-P 4` ceiling on a machine the
agent has to itself, never higher.

---

## 5. Proposed standing canary set

Two tiers. Both tiers are equally valid A/B canaries — the tier only says
whether the *absolute* verdict carries information too.

### Tier 1 — CI-passing (A/B signal + absolute verdict is meaningful)

| # | Suite | Test | Family | CI verdict | cmps |
|---|---|---|---|---|---|
| 1 | avm1 | `color` | solid fill + colour transform | pass (max_diff 1) | 1 |
| 2 | avm1 | `bitmap_data_fillrect` | bitmap / BitmapData | pass (max_diff 0) | 1 |
| 3 | avm1 | `mask_with_drawing` | mask + runtime drawing API | pass (max_diff 0) | 1 |
| 4 | avm1 | `movieclip_setmask` | mask (`setMask` path) | pass | 1 |
| 5 | avm1 | `edittext_tag_indent` | text / EditText layout | pass (max_diff 64) | 1 |
| 6 | avm1 | `focusrect_swf5` | multi-frame + input events | pass ×12 | **12** |
| 7 | avm1 | `bitmapdata_applyfilter_colormatrix` | filters (only passing one) | pass (max_diff 1) | 1 |
| 8 | avm2 | `blend_multiply_alpha` | blend modes | pass | 1 |
| 9 | visual | `simple_shapes/winding_rule` | shape tessellation / winding | pass (max_diff 0) | 1 |
| 10 | visual | `cache_as_bitmap/shape_changed` | cacheAsBitmap | pass (max_diff 0) | 1 |
| 11 | from_shumway | `timeline/timeline_as2_5` | timeline / frames | pass ×7 | **7** |
| 12 | from_shumway | `acid/acid-gradient-0` | gradients | pass (max_diff 1) | 1 |
| 13 | **regression** | `avm2_timeline_stroke_gradient` | stroke + gradient | pass (tol 255) | 1 |
| 14 | **regression** | `avm2_timeline_gradients` | gradient fill, AVM2 timeline | pass (tol 255) | 1 |

### Tier 2 — CI-failing / skipped (A/B signal only; absolute verdict is noise)

| # | Suite | Test | Family | CI verdict |
|---|---|---|---|---|
| 15 | visual | `simple_shapes/masks` | mask compositing (largest known gap) | fail (excess 248261) |
| 16 | visual | `simple_shapes/gradients/gradients` | gradient ramps | fail (excess 4270) |
| 17 | visual | `filters/drop_shadow` | filters proper | fail |
| 18 | visual | `filters/color_matrix` | filters proper | fail |
| 19 | visual | `blend_modes/multiply` | blend proper | fail (excess 66608) |
| 20 | **regression** | `avm2_morph` | morph shapes | **skip** (no expected PNG) |

All 20 paths verified to exist and carry `[image_comparisons]`.

Notes on the composition:

- **`regression/` is represented three times** (rows 13, 14, 20), per the
  standing policy that every canary must include that suite. Caveat worth
  recording: `avm2_timeline_gradients` and `avm2_timeline_stroke_gradient`
  are configured `tolerance = 255`, i.e. they pass *unconditionally* against
  the expected PNG. Their CI "pass" is therefore not evidence of render
  correctness — as byte-compare canaries they are still fully valid, which
  is exactly the point of the A/B design.
- **Row 20 is deliberate**: `avm2_morph` has no expected PNG at all and is
  the only morph-shape target in the corpus. Including it demonstrates and
  exercises the expected-PNG-independence proved in §2.
- Rows 6 and 11 are high value density: 12 and 7 comparisons for one
  compile, and row 6 additionally covers the input-event path.
- Families with **no** passing test anywhere in the corpus — filters
  proper, morph, visual-suite masks, TLF/rich text — can only be covered in
  Tier 2. That is a statement about the render gap, not about the canary.
- Total cost: 20 tests, ~40 comparisons. Cold ~12–20 min, warm ~1–2 min.
  A wave-2 agent whose change is scoped (e.g. gradients only) should run
  the family subset per iteration and the full 20 before handing off.

---

## 6. Wave-2 script spec — `ruffle-tests/render_canary.py`

Path rationale: it belongs next to `verify_output.py` and
`run_image_tests.py`, which it wraps; `scripts/` holds result-processing,
not test drivers.

### Design: two-phase capture, not stash-per-iteration

The trace canary stashes because a trace run is cheap. A render run is
compile-bound, so stashing forces a full rebuild of **both** legs on every
iteration. Instead:

```
render_canary.py capture --label before --tests LIST   # once, before editing
   ... agent edits render code, iterates ...
render_canary.py capture --label after  --tests LIST
render_canary.py compare --before before --after after
```

`before` is captured once per session and reused across many `after`
captures. A `--stash FILE...` convenience mode should exist for the
one-shot case (capture after → stash listed files → capture before → pop →
compare), but must not be the default.

### CLI

```
render_canary.py capture --label NAME
    [--tests FILE | --test SUITE/NAME ...]   # default: built-in standing set
    [--tier 1|2|all]                          # default: all
    [--jobs N]                                # default 2, hard cap 4
    [--recompile]                             # forward to verify_output.py
    [--out DIR]                               # default: scratchpad/render_canary/

render_canary.py compare --before NAME --after NAME
    [--json PATH] [--verbose]

render_canary.py run --stash PATH...          # one-shot convenience wrapper
```

Test-list file format: one `suite/test` per line, `#` comments. The
built-in default is the §5 table; keep it in the script as a literal so the
canary set is version-controlled with the tool.

### Capture mechanism (from §2)

Per test, per label:

```
OUT/<label>/<suite>/<test>/          # capture dir, also SWF_KEEP_BUILD_DIR
```

```bash
SWF_KEEP_BUILD_DIR=$capture_dir \
python3 ruffle-tests/verify_output.py \
    --tests-dir=ruffle-tests/tests/swfs/$suite \
    --test=$test --mode=graphics --images \
    --json=$capture_dir/result.json
```

Then keep `*.png` (excluding `*.difference.png`) plus `result.json`, and
delete the build artifacts — build dirs are hundreds of MB each and 20
tests × 2 labels will fill a disk. Retaining `result.json` gives the trace
status, phase timings, and the full image stats block for free.

Nested test names (`blend_modes/multiply`, `acid/acid-gradient-0`) are
supported by `verify_output.py` as forward-slashed relative paths under
`--tests-dir` — verified. `--tests-dir` must always be pinned; without it
the tool guesses the owning suite and a bare name can be ambiguous across
suites.

### Comparison bar (from §3)

Primary: **byte-identical**. For each `(test, comparison)`:

- both PNGs present and md5-equal → `IDENTICAL`
- both present, md5 differs → `DIFFERS` + stats
- present in one label only → `APPEARED` / `VANISHED` (a render that
  started or stopped happening — always significant)
- absent in both → `NO_RENDER` (pre-existing, not a regression)

Secondary, computed only for `DIFFERS` (before-PNG as reference, reusing
`verify_output.compare_images`): `diff_channels`, `mean_diff`, `max_diff`,
plus the changed-pixel bounding box. Emit a before-vs-after difference PNG
next to the pair.

Also compare, independently of pixels:
- **trace status** from each `result.json` (`pass`/`fail`/…) — a render
  change that alters traces is a finding, and image results never gate
  trace pass/fail, so it must be checked separately.
- **CI-graded image status** (`image_comparisons.*.status`) — a
  `pass → fail` flip against the *expected* PNG is a strong signal even
  though the absolute local verdict is not citable.

### Output

```
RENDER CANARY  before=baseline  after=wip   20 tests / 41 comparisons

  IDENTICAL   38
  DIFFERS      3
  APPEARED     0   VANISHED 0   NO_RENDER 0

  DIFFERS:
    visual/simple_shapes/gradients/gradients  output
        diff_channels 4270/262144  mean 2.31  max 191   bbox (12,40)-(240,201)
        image status: fail -> fail    trace: pass -> pass
    ...
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES:
    avm1/color  output   pass -> fail        <-- REVIEW
```

Exit non-zero if anything is not `IDENTICAL`, so it drops into a
pre-handoff check. `--json PATH` writes the machine-readable form.

Intended reading: `IDENTICAL` on a test the change was *meant* to affect is
just as much a finding as `DIFFERS` on one it was not. The script should
support `--expect-differs PATTERN` so an agent can assert its intended
blast radius in both directions.

### Documented false-positive / false-negative modes

> *Ready to paste into the wave-2 playbook.*
>
> **The canary is our-render-before vs our-render-after on ONE machine
> with ONE renderer. It is never a grade.** Local Dawn is not
> pixel-identical to CI's lavapipe — `bitmapdata_copypixels` passes on CI
> while showing ~25k tolerance-0 outlier channels locally. Never claim a
> pass/fail from a local render against an expected PNG. The canary answers
> only "did my change move the pixels, and where" — CI answers "are the
> pixels right".
>
> 1. **Stale recompiler output — the silent false NEGATIVE.** A change in
>    `SWFRecomp/` (the recompiler) does **not** take effect unless you (a)
>    rebuild the recompiler binary with cmake, and (b) pass `--recompile`,
>    because `RecompiledScripts/` is cached inside each test directory.
>    Without both, the canary reports `IDENTICAL` for every test and you
>    conclude your change was inert. Runtime (`SWFModernRuntime/`) changes
>    need neither — compilation always re-runs and ccache is content-keyed,
>    so an edited `.c` misses the cache and rebuilds.
> 2. **A stash-mode `before` leg overwrites `RecompiledScripts/`.** If you
>    use `--stash` with a recompiler change, *both* legs must be captured
>    with `--recompile`, or the second leg silently reuses the first leg's
>    generated C.
> 3. **Never edit sources mid-capture.** A capture leg that straddles an
>    edit mixes builds across tests and produces uninterpretable diffs.
>    Same rule as the trace sweep.
> 4. **Never share a `SWF_KEEP_BUILD_DIR` between concurrent runs.** They
>    clobber each other's sources and PNGs. One directory per (test, label).
> 5. **`-P 2` is the validated fan-out** (clean across four concurrent
>    pairs; three A/B pairs straddled the sequential/concurrent boundary
>    and stayed byte-identical). `-P 4` only on a machine you own. Do not
>    go higher — the trace-side sweep's float-formatting and long-compile
>    timeout false positives show up at `-P 6-8`, and the machine is
>    usually shared.
> 6. **`--verbose` writes actual/difference PNGs into the test directory.**
>    Harmless for the gitignored upstream mirrors, but it dirties the
>    working tree for the fully-tracked `regression/` suite, and it races
>    between two runs of the same test. Use `SWF_KEEP_BUILD_DIR`; never
>    `--verbose`, in a canary.
> 7. **The image verdict is not on stdout.** It exists only in the
>    `--json` report. A run whose console says `Pass: 1 (100.0%)` tells you
>    the *trace* matched; the pixels may be entirely wrong. Always read the
>    JSON.
> 8. **`NO_RENDER` is not a canary failure.** ~40 avm2 tests (Stage3D/AGAL,
>    PixelBender, JPEG-XR decode, NetStream video) render nothing at all.
>    They are real gaps in the graded baseline, but as canaries they are
>    inert — nothing to compare. Keep them out of the standing set.
> 9. **A Tier-2 `DIFFERS` is not automatically a regression.** Those tests
>    already fail against their expected PNG; a pixel move there may be the
>    fix working. Read the stats and the difference PNG; if the change was
>    meant to touch that family, `DIFFERS` is the *expected* outcome.
> 10. **`IDENTICAL` everywhere after a change you believe is live is a red
>     flag, not a clean bill.** Check mode 1 first, then check that the
>     canary set actually covers the family you touched (filters, morph,
>     and visual-suite masks have **no** CI-passing representative — they
>     are Tier-2-only).

### Estimated implementation size

~350–450 lines. No changes to `verify_output.py` required. Reuse
`compare_images()` and `parse_image_comparisons()` by importing
`verify_output` as a module rather than reimplementing the comparison —
that keeps the canary's stats definitionally identical to CI's.

---

## Appendix — raw measurements

11 `verify_output.py` invocations, all `--mode=graphics --images`,
max 2 concurrent.

| Run | Test | Suite | Concurrency | recomp | compile | run | wall |
|---|---|---|---|---|---|---|---|
| color_A | `color` | avm1 | seq | — | — | — | 56.88 s |
| color_B | `color` | avm1 | -P 2 | 0.000 | 1.313 | 0.517 | 2.80 s |
| grad_A | `gradient_same_ratios` | visual | -P 2 | — | — | — | 49.66 s |
| grad_B | `gradient_same_ratios` | visual | -P 2 | — | — | — | 2.73 s |
| reg_A | `avm2_timeline_gradients` | regression | -P 2 | 0.000 | 76.774 | 0.518 | 81.12 s |
| reg_B | `avm2_timeline_gradients` | regression | -P 2 | 0.000 | 4.177 | 1.241 | 6.79 s |
| blend_A | `blend_modes/multiply` | visual | -P 2 | 0.360 | 9.961 | 0.770 | 12.28 s |
| blend_B | `blend_modes/multiply` | visual | -P 2 | — | — | — | 2.88 s |
| focus_A | `focusrect_swf5` | avm1 | -P 2 | 0.012 | 61.297 | 0.416 | 64.42 s |
| focus_B | `focusrect_swf5` | avm1 | seq | 0.000 | 1.642 | 0.467 | 2.59 s |
| solid_A | `avm2_timeline_solid` | regression | seq | — | — | — | 19.42 s |

Byte-compare results: `color` A==B; `gradient_same_ratios` A==B;
`avm2_timeline_gradients` A==B; `focusrect_swf5` A==B across all 12 PNGs.
17/17 identical.

Working tree remained clean (`git status --porcelain` empty) throughout —
single-test runs with an explicit `--json` do not touch the canonical
`_results/` files.

Key source references:
- `ruffle-tests/verify_output.py:3808-3814` — `SWF_KEEP_BUILD_DIR`
- `ruffle-tests/verify_output.py:2373` — `-DHEADLESS_RENDER_ENABLED` gate
- `ruffle-tests/verify_output.py:4005` — `actual_png = build_dir/<cmp>.png`
- `ruffle-tests/verify_output.py:4037` — failure-only `--image-out-dir` export
- `ruffle-tests/verify_output.py:4042` — `--verbose` copy into test dir
- `ruffle-tests/verify_output.py:4067` — `--save-actual` writes trace TEXT
- `ruffle-tests/verify_output.py:357-540` — `compare_images()` + stats
- `ruffle-tests/verify_output.py:3711-3716` — single-test `--json` guard
- `SWFModernRuntime/src/libswf/capture.c:53,114` — `CAPTURE_OUTPUT_DIR`,
  `renderer_save_png()`
