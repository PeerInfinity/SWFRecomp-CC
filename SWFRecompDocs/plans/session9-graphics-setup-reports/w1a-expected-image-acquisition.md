# W1A — Expected-image acquisition audit

Session 9 graphics-setup, wave 1, agent A. Read-only audit at master `f56b898d9`.
Baseline under audit: CI run `30680942974` at `375373786`, 159/567 image
comparisons pass.

**Headline verdicts**

1. Golden flow is sound and fully documented in-tree. No hole.
2. Provenance: zero comparisons depend on the `~/CC/ruffle` fallback. The
   9 non-`repo` rows are all benign and already explained. No hole.
3. **Main-tree `--tests-dir` is NOT safe as a blanket recipe for parallel
   worktree agents.** verify_output.py writes into the tests dir in three
   places; one of them can silently produce false results. A per-agent
   test-dir copy is required — but it is `cp -r` of a few hundred KB, not a
   `download_tests.sh` fetch.
4. Regression goldens came from a **Ruffle `--graphics gl` export**, not from
   our renderer. The policy is therefore "external oracle or no golden".
5. No pinning anywhere. Upstream goldens track `ruffle-rs/ruffle` master HEAD
   at fetch time, and the dashboard fetches them a *second* time at Pages-deploy
   time. Real but low-frequency drift risk; no action required beyond recording
   it.

Two small measurement gaps found incidentally (§6): 2 comparisons with goldens
on disk are never censused because they live under `[subtests.*]`, and one
`_results` denominator double-counts a nested suite.

---

## 1. Golden flow

**Confirmed: every graded comparison's expected PNG arrives via
`download_tests.sh` into the gitignored test dir.** The only exceptions are the
two hand-made `regression` goldens, which are git-tracked.

### (a) Local dev run

`ruffle-tests/download_tests.sh` clones `ruffle-rs/ruffle` with
`--depth=1 --filter=blob:none --sparse` (`download_tests.sh:144`) and
`install_test_dir()` copies every top-level file that is not a `.swf`/`.as`/
`.fla`/`test.toml`/`output.txt`/`input.json` into the local test dir
(`download_tests.sh:186-200`). `<cmp>.expected.png` is a top-level file and
matches no exclusion, so it comes down with everything else. That loop already
carries an explicit maintenance comment forbidding `*.png` from ever being
added to the exclusion list (`download_tests.sh:171-186`).

The nested-asset `find` further down *does* exclude `*.png`
(`download_tests.sh:249-253`) — deliberately, because no comparison name
contains a path separator, so no expected PNG has ever lived in a subdirectory.
Verified against the current tree: all 566 unique golden paths are
`<test_dir>/<cmp>.expected.png`, depth 0.

At run time, `verify_output.py:3997-4004` resolves
`test_dir / f"{cmp_name}.expected.png"` first and records
`expected_source = "repo"`. Only if that misses does it try
`RUFFLE_UPSTREAM` (`verify_output.py:680`), which is hardcoded to
`~/CC/ruffle/tests/tests/swfs/**avm1**` — so the fallback can only ever serve
the `avm1` suite, and records `expected_source = "upstream_checkout"`.
`~/CC/ruffle` does exist on this machine (566 `*.expected.png` under it), so
the fallback is live locally and dead on CI.

### (b) CI shard

Both CI jobs re-download per run:
- sharded job: `.github/workflows/ruffle-tests.yml:425` —
  `bash ruffle-tests/download_tests.sh $CATS`, categories selected by the
  `RUN_*` flags.
- `single_test` job: `ruffle-tests.yml:282` — downloads **all fourteen**
  categories unconditionally, because `--test=NAME` locates its own suite.

The runner has no `~/CC/ruffle`, so `download_tests.sh` is the *only* thing
that puts a golden on a CI runner. This is why `expected_source` was added:
a comparison resolving only through the fallback would grade locally and skip
in CI.

The guard is `python3 scripts/build_image_report.py --audit`, run on every
`images=true` dispatch at `ruffle-tests.yml:1118`, immediately before the
report build at `:1119`. It checks the test directory and nothing else —
deliberately blind to the fallback, i.e. exactly what CI sees
(`build_image_report.py:audit_expectations`, docstring at `:319-330`).

Note (not a hole, but worth recording in the playbook): the **`single_test` CI
job does not pass `--images`** (`ruffle-tests.yml:288-292` runs
`-v --test=... --mode=... --diff`). `IMAGE_ARGS` (`:487`) is only wired into
the sharded job. A `single_test` dispatch still *performs* the comparison —
the block at `verify_output.py:3989` is gated on `image_comparisons and
HAS_PIL and args.uses_dawn`, not on `--images` — but it records no
`stats`/`expected_source` and publishes no image results. So **you cannot get
a graded pixel number from a `single_test` CI dispatch.**

### (c) Pages dashboard

Three independent sources, joined at build time
(`deploy-pages.yml:32-64`, identical block in `deploy-pages-build.yml:84-125`):

| piece | source |
|---|---|
| counts / verdicts | `ruffle-tests/tests/swfs/<suite>/_results/image_results_graphics.json` on **master** |
| our renders (failing only) | `ruffle-image-results` branch, `git fetch --depth=1` (`deploy-pages.yml:43`) |
| expected PNGs | **fresh blob-filtered non-cone sparse checkout of `ruffle-rs/ruffle` master**, `git sparse-checkout set --no-cone '/tests/tests/swfs/**/*.expected.png'` (`deploy-pages.yml:59-64`) |

The workflow comment at `deploy-pages.yml:47-50` states the trap directly:
"The expected PNGs are NOT in this repo at any ref." That is the correct
reading of the prior session's memory note — it is about clean CI/Pages
checkouts, and it is true there. On the dev machine the PNGs are present
because `download_tests.sh` has been run; they are gitignored, so they exist in
the working tree and in no commit.

---

## 2. Provenance holes

`python3 scripts/build_image_report.py --audit` on the current tree:

```
[audit] 564/567 comparisons have an in-repo expected PNG
::warning::3 image comparison(s) have no in-repo expected PNG and will be recorded as skip/no_expected_image:
  regression/avm2_graphics_runtime [output]
  regression/avm2_morph [output]
  regression/avm2_timeline_solid [output]
```

Reconciled against the committed per-suite `image_results_graphics.json`
(567 rows total): **`expected_source` is `repo` on 558 rows and absent on 9.
It is `upstream_checkout` on zero rows.**

The 9 rows with no `expected_source` — enumerated in full, with cause:

| suite / test | cmp | status | reason | why no `expected_source` | real hole? |
|---|---|---|---|---|---|
| `regression/avm2_graphics_runtime` | output | skip | `no_expected_image` | bails at `verify_output.py:4006` before the field is set | **no** — deliberate, §4 |
| `regression/avm2_morph` | output | skip | `no_expected_image` | same | **no** — deliberate, §4 |
| `regression/avm2_timeline_solid` | output | skip | `no_expected_image` | same | **no** — deliberate, §4 |
| `visual/simple_shapes/heavy_tesselation` | output | skip | `test_recomp_fail` | no record at all; row synthesised by `build_suite`'s census reconciliation (`build_image_report.py:120-124`) | **no** — golden IS in repo; the test never ran |
| `from_shumway/acid/acid` | output.17 | fail | `no_render` | comparison ran, but `expected_source` is written at `:4033` *after* the no-actual early-out | **no** — golden IS in repo |
| `from_shumway/acid/acid` | output.18 | fail | `no_render` | same | **no** |
| `from_shumway/acid/acid-large` | output | fail | `no_render` | same | **no** |
| `from_shumway/acid/acid-video` | output.10 | fail | `no_render` | same | **no** |
| `from_shumway/acid/acid-video` | output.20 | fail | `no_render` | same | **no** |

The baseline doc's "`unrecorded` 9" (`graphics-image-baseline.md`,
§"Expected-image provenance") is therefore **not 9 missing goldens**. It is
3 deliberate no-golden regression tests + 6 rows whose comparison
short-circuited before the field was written. Only 3 of the 567 comparisons
lack an in-repo golden, and the audit already names exactly those 3.

**Verdict: no hole in the CI baseline. Nothing depends on `~/CC/ruffle`.**

Minor doc-accuracy nit for the coordinator: the baseline doc's phrasing
"`unrecorded` 9" invites the reading that 9 goldens are missing. If the doc is
touched again, "`unrecorded` 9 — 3 no-golden by design, 6 short-circuited
before the field was written; 0 `upstream_checkout`" is the accurate line.

---

## 3. Worktree-agent recipe

### The write audit

Every write into `TESTS_DIR` during a normal
`--test=X --mode=graphics --images` run. Grepped for `write_text` /
`write_bytes` / `mkdir` / `makedirs` / `shutil.copy*` / `shutil.move` /
`rmtree` / `open(...,'w')` / `unlink` / `json.dump` across all 4224 lines and
traced every destination.

**Writes that land in the tests dir — three, all real:**

1. **`RESULTS_DIR.mkdir(parents=True, exist_ok=True)`** —
   `verify_output.py:3688`, **unconditional**, runs even for `--test=X`.
   Creates `<tests_dir>/_results/`. Benign in the main tree (already exists);
   in a scratch tests dir it creates one empty directory.
   The dangerous neighbour, `shutil.copy2(RESULTS_FINAL, RESULTS_PREVIOUS)` at
   `:3691-3692`, **is** gated: `if RESULTS_FINAL.exists() and not args.test`.
   Single-test runs never clobber `results_*.json` — confirmed, matches the
   `ci-single-test-run-clobbers-results` memory note being marked FIXED.

2. **`RecompiledScripts/` + `RecompiledTags/` + `RecompiledABC/` inside each
   test dir** — `recompile_swf()`, `verify_output.py:1876-1932`. It
   `shutil.rmtree`s all three (`:1902-1905`) and then runs the recompiler with
   **`cwd=str(test_dir)`** (`:1923`), which emits them fresh. This is why
   `download_tests.sh --clean-cache` exists.
   The reuse decision is an **mtime heuristic** (`:1888-1895`):
   ```python
   cache_mtime = scripts_dir.stat().st_mtime
   recomp_mtime = RECOMP_BIN.stat().st_mtime
   swf_mtime = (test_dir / "test.swf").stat().st_mtime
   if cache_mtime >= recomp_mtime and cache_mtime >= swf_mtime:
       return True, ""   # reuse whatever is on disk
   ```
   `RECOMP_BIN = PROJECT_ROOT / "SWFRecomp/build/SWFRecomp"` (`:673`) and
   `PROJECT_ROOT` derives from `__file__` — so it is the **worktree's own**
   binary, while `test_dir` would be the **main tree's**.

3. **`<test_dir>/<cmp>.actual.png` and `<test_dir>/<cmp>.difference.png`** —
   `verify_output.py:4040-4055`, gated on **`args.verbose`**, *not* on
   `--images` / `--image-out-dir` / `--save-actual`. It also `unlink`s a stale
   `.difference.png` on a strict pass (`:4053`). The documented quick command
   in CLAUDE.md is `--diff --verbose`, so this fires routinely.

**Writes that do NOT land in the tests dir — verified:**
- All build artefacts go to `build_dir`, a `tempfile.TemporaryDirectory(prefix="swf_verify_")`
  (`:3810-3813`): `data_registry.c` (`:1872`), `movie_self.c` (`:2285`),
  runtime `.c`/`.h` copies (`:2079-2122`), `swf_url.h` (`:2755`), the emcc
  response file (`:2789`).
- Child-SWF recompiles use their **own** `tempfile.TemporaryDirectory(prefix="swf_child_")`
  and write `config.toml` there (`:1097-1110`); output is copied to
  `child_recomp_dir = build_dir / f"_child_..."` (`:2159`, `:2658`) — under
  `/tmp`, not the tests dir.
- `preprocess_input_json` → `build_dir / "input_events.txt"` (`:3820`);
  `preprocess_socket_json` → `build_dir / "socket_script.txt"` (`:3888`).
- `--save-actual` writes to the caller-supplied path (`:4068`).
- `--image-out-dir` writes to `out_dir/<suite>/<test>/…` via
  `export_failing_images` (`:541-560`).
- Crash capture writes to `CORE_CAPTURE_DIR` (`:2963`, `:3022-3053`).
- No `.swf` regeneration. No `__pycache__` in the tests dir (no importable
  modules live there; `build_image_report.py` only creates
  `ruffle-tests/__pycache__` in whichever tree it runs from).

### Verdict

**Main-tree `--tests-dir` is unsafe as a blanket recipe.** Three hazards, in
descending severity:

**Hazard A — silent false results (correctness).** Worktree agent A carries a
recompiler change, builds its own `SWFRecomp`, and runs
`--tests-dir=<main>/…/visual`. Its recompiler emits `RecompiledScripts/` into
the **main tree's** `visual/<test>/`, freshly mtime-stamped. Agent B (or the
coordinator, or the user's own main-tree session) then runs the same test with
an *older* binary; `cache_mtime >= recomp_mtime` holds, so B **reuses A's
emission and silently measures A's recompiler change**. No error, no warning,
wrong number. This is the same family as the `stale-recompiledabc` note, but
inverted: there the stale cache produced a visible `ld` error; here it produces
a plausible-looking wrong verdict.

**Hazard B — rmtree race (flakiness).** Two agents running the *same* test
concurrently: one `shutil.rmtree`s `RecompiledScripts/` while the other's
recompiler or `gcc` is reading it → spurious `recomp_fail` / `compile_fail`.
Different tests are independent (the cache is per-test-dir), so this only bites
on overlap — but a graphics fan-out where two agents both probe, say,
`visual/filters/blur_quality` is exactly the overlap case.

**Hazard C — dirty main tree (low, but not zero).** `--verbose` drops
`<cmp>.actual.png` / `<cmp>.difference.png` into the test dir. For upstream
suites the whole dir is gitignored, so it is invisible. For the **`regression`
suite the dir is tracked** and `*.png` is not ignored:
```
$ git check-ignore -v ruffle-tests/tests/swfs/regression/avm2_morph/output.actual.png
NOT IGNORED -> would appear in git status
```
So a `--verbose` graphics run on any of the five image-comparing regression
tests leaves untracked PNGs in a tracked directory. Harmless until someone
stages by directory. (`RecompiledABC/` is safe — globally ignored at
`.gitignore:19`; `RecompiledScripts`/`Tags` at `.gitignore:125-126`.)

### The recipe (recommended)

**Do not run `download_tests.sh` per worktree** — that is a network clone for
data already on disk. Copy only the test dirs the agent will touch, into the
worktree's own (gitignored) suite path:

```bash
MAIN=/home/robert/CC/SWFRecomp-CC
WT=$(git rev-parse --show-toplevel)      # the agent's worktree

# One test:
mkdir -p "$WT/ruffle-tests/tests/swfs/visual/filters"
cp -r "$MAIN/ruffle-tests/tests/swfs/visual/filters/blur_quality" \
      "$WT/ruffle-tests/tests/swfs/visual/filters/"

# Then run normally — no --tests-dir needed:
python3 "$WT/ruffle-tests/verify_output.py" \
    --test=filters/blur_quality --tests-dir="$WT/ruffle-tests/tests/swfs/visual" \
    --mode=graphics --images --diff
```

Why this works and what it costs:
- The worktree's `.gitignore` already ignores `visual/*/` etc., so the copy is
  invisible to `git status` and to any commit the agent makes.
- Everything the run needs resolves relative to `test_dir`: `test.swf`,
  `output.txt`, `test.toml`, `<cmp>.expected.png`. Nothing outside it.
- `ruffle-tests/_shared/config.toml` (the recompiler config, `RECOMP_CONFIG`)
  is **git-tracked**, so the worktree has it.
- The `regression` suite is git-tracked in full — a worktree already has it,
  **no copy needed**.
- Size: a single test dir is ~80–110 KB. The entire graded-image corpus
  (`visual avm1 avm2 from_shumway text fonts stage3d import_assets from_gnash`)
  is ~212 MB and copies in seconds on the same disk, if an agent ever wants
  the lot.

Caveats to record:
- Copy **whole test directories**, not individual files — loader/net tests keep
  nested children and scripted responses under the test dir.
- If you point `--tests-dir` at an out-of-corpus path (e.g. `/tmp/...`),
  `suite_tag()` falls back to the bare directory name
  (`verify_output.py:527-538`). That only affects the `--image-out-dir`
  subdirectory layout, but it is why the recipe above puts the copy at the
  canonical in-worktree suite path instead.
- Bare `--test=NAME` auto-search (`verify_output.py:3580-3613`) walks
  `SUITE_DIRS` at their canonical locations, so it works in the worktree — but
  `SUITE_DIRS` lists suite *roots* only. Nested tests such as
  `visual/filters/blur_quality` must be named by their suite-relative path,
  which is why the recipe passes `--tests-dir` explicitly. (Same trap as the
  `verify-test-name-suite-ambiguity` note.)

**When main-tree `--tests-dir` IS acceptable:** a single agent, working alone,
whose diff does not touch `SWFRecomp/`. Runtime-only (`SWFModernRuntime/*.c`)
changes do not affect recompiler emission, so sharing a warm cache is both safe
and faster. As a *fan-out* recipe it must not be used, because the coordinator
cannot guarantee either condition across agents.

---

## 4. Regression-suite goldens

**Which have goldens (2):**
```
$ git ls-files '*expected.png'
ruffle-tests/tests/swfs/regression/avm2_timeline_gradients/output.expected.png
ruffle-tests/tests/swfs/regression/avm2_timeline_stroke_gradient/output.expected.png
```
Both git-tracked. They are the *only* tracked expected PNGs in the repo.

**Which declare `[image_comparisons]` with no golden (3):**
`avm2_graphics_runtime`, `avm2_morph`, `avm2_timeline_solid` — matching the
audit output and the baseline doc's skip table exactly. Five regression tests
declare `[image_comparisons]` in total; 2 pass, 3 skip
(`graphics-image-baseline.md` per-suite table: `regression` 5 / 2 pass /
0 fail / 3 skip).

**Where the 2 goldens came from.** Both were added in `f490e4b24`
("AVM2 vector T2+T3: line strokes + gradient fills render", 2026-07-21). The
commit message states the provenance:

> Two authored regression probes, each **MAD-matched to a Ruffle `--graphics gl`
> export**, both render pixel-identical to Ruffle where before T2/T3 every shape
> was skipped blank

So the golden is an **external oracle** — Ruffle's own GL renderer, driven
independently — not a capture of our output. Each test also ships the full
recipe to regenerate its input and cross-check the art: `Grad.as` / `Probe.as`,
`build_swf.sh` (an mxmlc invocation, `-default-size 400 400`, explicitly
"matches the SVG art + the Ruffle output.expected.png export"), and a
hand-written `grad.svg` / `probe.svg` describing the intended image
independently of any renderer.

**Policy a playbook should record.** The three no-golden tests are not an
oversight and the two golden ones are not an inconsistency — they sit on
opposite sides of one rule:

> A hand-written `regression` test may carry an `output.expected.png` **only
> when the PNG comes from an oracle outside SWFRecomp** — a Ruffle
> `--graphics <backend>` export, a real Flash Player capture, or art rendered
> from an independent description (the SVG in these two cases). Never from our
> own renderer, at any commit: a golden captured from SWFRecomp asserts only
> that SWFRecomp has not changed, which is a change-detector, not a
> correctness test, and it silently blesses whatever was wrong on the day it
> was captured.
>
> When no external oracle is available, ship the test **without** a golden. It
> records as `skip/no_expected_image` — visible in the audit, visible in the
> baseline's skip table, and honest. That is why `avm2_graphics_runtime`,
> `avm2_morph` and `avm2_timeline_solid` have none.
>
> A golden that is added must arrive with its provenance: the oracle used, and
> the regeneration recipe (`build_swf.sh` + source art) committed alongside it.

---

## 5. Freshness / drift

**There is no pinning anywhere.** Three fetch points, all unpinned:

| fetch | ref | file:line |
|---|---|---|
| local / CI test data | `BRANCH="master"`, `git clone --depth=1 --filter=blob:none --sparse --branch="${BRANCH}"` | `download_tests.sh:41`, `:144` |
| Pages dashboard goldens | `git fetch --depth=1 --filter=blob:none -q origin master` | `deploy-pages.yml:62`, `deploy-pages-build.yml:114` |
| Pages our-renders | `git fetch --depth=1 origin ruffle-image-results` | `deploy-pages.yml:43` |

No `REV` file, no `UPSTREAM_SHA`, no submodule, no recorded upstream commit
anywhere in the repo. Searched for all of these; nothing.

**How an upstream golden update propagates:** silently and automatically, on
the next `download_tests.sh` run — which for CI is *every* run. There is no
diff, no review, no commit in this repo. The same is true of `test.swf` and
`output.txt`, so this is a pre-existing property of the whole corpus, not
something the image instrument introduced.

**Staleness risk, stated precisely:**

1. *The pixel baseline is not reproducible at a fixed SHA.* Re-running
   `30680942974`'s exact commit `375373786` months later grades against
   whatever upstream master holds then. A drop or rise in the 159/567 number
   can therefore originate entirely outside this repo. The graded number needs
   a *date* as well as a commit to be meaningful — the baseline doc already
   gives both, which is the right habit.
2. *The dashboard can show a golden CI never graded against.* The CI run
   fetched goldens at run time; the Pages build fetches them again at deploy
   time, from master again. If upstream re-records a PNG between the two, the
   dashboard's "expected" column is not the image that produced the verdict in
   the same row. Both steps are `--depth=1 origin master`, minutes-to-days
   apart. Low probability per deploy, non-zero, and completely silent.
3. *An upstream test deletion looks like a corpus shrink.* Since
   `download_tests.sh` without `--clean` only adds and overwrites, a deleted
   upstream test lingers locally but vanishes on a fresh CI runner — so
   comparison counts can differ between a dev machine and CI for reasons that
   are not code.

**Action needed: none, and pinning is the wrong fix.** Pinning would freeze the
corpus and defeat the point of mirroring upstream (the project deliberately
tracks upstream's growing corpus — see `FULL_SUITE_IMPORT_AUDIT.md`). The
cheap mitigations, if a future session wants them, are in the wave-2 list
below as optional items. For this session, recording risk #2 in the playbook is
sufficient: **when a dashboard thumbnail disagrees with the numbers, suspect a
double-fetch skew before suspecting the renderer.**

---

## 6. Incidental findings (two small measurement gaps)

Found while reconciling the 671 `*.expected.png` files on disk against the 567
censused comparisons. The accounting closes exactly:

- 103 are under `ruffle-tests/tests/swfs/_image-test-output/` — a stale local
  scratch tree, gitignored at `.gitignore:208`, not part of the corpus.
- 566 unique golden paths are referenced by censused comparisons (567 rows,
  one duplicate — see below).
- 5 are on disk but referenced by no censused comparison:

| file | explanation | gap? |
|---|---|---|
| `avm2/bitmapdata_drawwithquality/output.high.expected.png` | declared as `[subtests.high.image_comparisons."output.high"]` | **YES** |
| `avm2/bitmapdata_drawwithquality/output.low.expected.png` | declared as `[subtests.low.image_comparisons."output.low"]` | **YES** |
| `avm2/graphics_round_rects/output.expected.png` | test.toml has no `image_comparisons` at all; Ruffle's harness only grades the explicit map (`options.rs:213`), so upstream does not grade it either | no |
| `visual/video/h264/frame0.expected.png` | comparison **commented out** upstream (B-frame ordering note in test.toml) | no |
| `visual/video/h264/frame1.expected.png` | same | no |

**Gap 1 — `[subtests.*]` image comparisons are invisible to the census.**
`parse_image_comparisons` reads only the top-level `data.get("image_comparisons")`
(`verify_output.py:233-235`). Ruffle expands `[subtests]` into N separate test
runs, each with its own options map (`~/CC/ruffle/tests/framework/src/options.rs:154-188`,
`read_with_subtests`, called from `regression_tests.rs:120`). Exactly **one**
test in the whole corpus uses `subtests` + `image_comparisons`, contributing
**2 ungraded comparisons whose goldens are already on disk**. Both are
`with_renderer = { quality = ... }` variants, which we have no equivalent for —
so grading them would need a quality knob, not just a parser fix. Genuinely
small, genuinely low value; recorded so it is not rediscovered.

I also checked whether the `TOMLDecodeError` swallow at
`verify_output.py:226-231` (TOML 1.1 multi-line inline tables) is hiding any
comparisons: **3 test.toml files in the corpus fail `tomllib`, and 0 of them
contain `image_comparisons`.** Not a gap today; worth re-checking after a large
upstream sync.

**Gap 2 — the 567 denominator double-counts one nested comparison.**
`from_shumway/avm1/text-bind [output]` is censused twice: once under
`from_shumway` (which walks recursively) and once under `from_shumway/avm1`.
`build_image_report.py` deliberately does *not* skip `NESTED_SUITES` in its
census (`build_image_report.py:44-53` explains why: it keeps the parent's rows
fully populated), while `image_baseline_report.py:67-74` *does* exclude nested
suites from its totals. So **567 is a sum-with-double-count and 566 is the true
unique comparison count** — the same trap as the 4414-vs-4463 trace denominator
(`corpus-denominator-double-counts-nested`). Worth knowing before anyone reads
the 566→567 change between the two baseline runs as "+1 comparison": it is not.

---

## Wave-2 work items

**No wave-2 implementation work is required for expected-image acquisition.
The golden flow, the CI guard, and the provenance recording are all already
built and all already correct. This is playbook text only.**

The two gaps in §6 are real but neither blocks a graphics fan-out: gap 1 is
2 comparisons out of 567 that need a renderer-quality knob we do not have, and
gap 2 is a denominator nit already handled correctly by the reporting script
that matters. Both are recorded above; neither should consume a wave-2 slot.

Optional, only if a later session wants them (explicitly **not** recommended
for this session):

- *(optional, ~15 lines)* `scripts/build_image_report.py` — teach
  `census_suite` to expand `[subtests.*.image_comparisons.*]`, and
  `verify_output.py:parse_image_comparisons` likewise. Recovers 2 comparisons;
  both would immediately record as `skip` (no quality knob), so the net
  information gain is one honest skip row instead of silence.
- *(optional, ~10 lines)* `.github/workflows/deploy-pages*.yml` — echo the
  upstream golden-fetch SHA into the dashboard footer next to the existing data
  SHA, so drift risk #2 becomes self-identifying the same way a stale page
  already is.
- *(optional, 1 line)* `.gitignore` — add
  `ruffle-tests/tests/swfs/regression/*/*.actual.png` and `*.difference.png` to
  close Hazard C. Trivial, but it is a repo write and this session is
  read-only.

---

## Playbook paragraphs (verbatim, for the coordinator to paste)

### Worktree recipe

> **Test data in a worktree.** A fresh `git worktree` has no test data: every
> suite under `ruffle-tests/tests/swfs/` is gitignored except `regression`,
> which is tracked in full and therefore already present. Do **not** run
> `ruffle-tests/download_tests.sh` in a worktree — that is a network clone of
> data already on this disk.
>
> Do **not** point `--tests-dir` at the main tree either. `verify_output.py`
> writes into the tests directory in three places, and one of them can produce
> a silently wrong result: `recompile_swf()` (`verify_output.py:1876-1932`)
> `rmtree`s and regenerates `RecompiledScripts/`, `RecompiledTags/` and
> `RecompiledABC/` *inside each test directory*, running the recompiler with
> `cwd=test_dir`, and reuses an existing cache whenever
> `cache_mtime >= RECOMP_BIN mtime`. Two consequences: (a) a worktree agent
> carrying a `SWFRecomp/` change writes its emission into the shared test dir,
> where any agent with an older binary will silently reuse it and measure
> someone else's recompiler; (b) two agents on the *same* test can `rmtree` each
> other's output mid-build, producing spurious `recomp_fail`/`compile_fail`.
> A third write is cosmetic but real: `--verbose` drops `<cmp>.actual.png` and
> `<cmp>.difference.png` into the test dir, and in the tracked `regression`
> suite those show up as untracked files in `git status`.
>
> Instead, copy the test directories you need into the worktree's own
> (gitignored) suite path:
>
> ```bash
> MAIN=/home/robert/CC/SWFRecomp-CC
> WT=$(git rev-parse --show-toplevel)
> SUITE=visual
> mkdir -p "$WT/ruffle-tests/tests/swfs/$SUITE/filters"
> cp -r "$MAIN/ruffle-tests/tests/swfs/$SUITE/filters/blur_quality" \
>       "$WT/ruffle-tests/tests/swfs/$SUITE/filters/"
> python3 "$WT/ruffle-tests/verify_output.py" \
>     --tests-dir="$WT/ruffle-tests/tests/swfs/$SUITE" \
>     --test=filters/blur_quality --mode=graphics --images --diff
> ```
>
> Copy whole test directories, never individual files — loader and net tests
> keep nested children and scripted responses beside `test.swf`. A test
> directory is ~100 KB; the entire graded-image corpus is ~212 MB and copies in
> seconds if you ever want all of it. Everything the run needs
> (`test.swf`, `output.txt`, `test.toml`, `<cmp>.expected.png`) resolves
> relative to the test directory, and `ruffle-tests/_shared/config.toml` is
> git-tracked so the worktree already has it. Keep the copy at the canonical
> in-worktree suite path rather than somewhere under `/tmp`: `suite_tag()`
> (`verify_output.py:527-538`) falls back to a bare directory name for an
> out-of-corpus path, which mislabels `--image-out-dir` output.
>
> Main-tree `--tests-dir` is acceptable for exactly one case: a single agent
> working alone whose diff does not touch `SWFRecomp/`. It is never acceptable
> in a fan-out.

### Provenance rules

> **Where a golden comes from.** Every upstream `<cmp>.expected.png` reaches
> both a dev machine and a CI runner the same way: `download_tests.sh` mirrors
> it into the (gitignored) test directory as an ordinary top-level data file.
> Expected PNGs are in **no ref of this repo** — the only two tracked ones are
> the hand-made `regression` goldens. Never add `*.png` to the exclusion list
> in `install_test_dir()`; the nested-asset `find` further down excludes images
> on purpose, and no comparison name has ever contained a path separator.
>
> `verify_output.py` will fall back to a local `~/CC/ruffle` checkout for a
> missing golden, but only for the `avm1` suite, and CI has no such checkout —
> so anything resolving through the fallback grades locally and skips in CI.
> Every graded comparison records `expected_source`, and as of the 2026-07-31
> baseline **zero comparisons resolve as `upstream_checkout`**. The guard is
> `python3 scripts/build_image_report.py --audit`, which CI runs on every
> `images=true` dispatch; it is deliberately blind to the fallback because that
> is what CI sees. If it warns, the baseline has a hole — fix the mirror, do
> not add a golden by hand.
>
> **A `regression` test may carry a golden only from an oracle outside
> SWFRecomp** — a Ruffle `--graphics <backend>` export, a real Flash capture,
> or art rendered from an independent description. The two that exist
> (`avm2_timeline_gradients`, `avm2_timeline_stroke_gradient`, added in
> `f490e4b24`) are MAD-matched Ruffle GL exports and ship their own
> `build_swf.sh` plus source `.as`/`.svg`. Never capture a golden from our own
> renderer: that asserts only that we have not changed, and blesses whatever
> was wrong on the day. With no external oracle, ship the test *without* a
> golden — it records as `skip/no_expected_image`, which is visible in the
> audit and in the baseline's skip table. That is why `avm2_graphics_runtime`,
> `avm2_morph` and `avm2_timeline_solid` have none.
>
> **Nothing is pinned.** `download_tests.sh` clones `ruffle-rs/ruffle` master
> at `--depth=1`, and the Pages dashboard fetches the goldens *again* from
> master at deploy time. So (a) a pixel baseline is reproducible only as
> commit + date, never commit alone — a move in the number can originate
> entirely upstream; and (b) if a dashboard thumbnail disagrees with the numbers
> beside it, suspect that double fetch before suspecting the renderer. Pinning
> is not the fix — the project deliberately tracks upstream's growing corpus.
>
> **A `single_test` CI dispatch produces no graded pixel number.** The
> `IMAGE_ARGS` wiring (`ruffle-tests.yml:487`) is on the sharded job only; the
> single-test job runs `-v --diff` without `--images`. It still performs the
> comparison and prints the verdict, but records no magnitude stats and
> publishes no image results. For a graded number, dispatch the sharded
> workflow with `images=true`.
