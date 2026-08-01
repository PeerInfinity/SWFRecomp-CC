# w2-3 — Local render canary: `ruffle-tests/render_canary.py`

Session 9 graphics-infrastructure setup, wave-2 agent 3.
Implements the spec in `w1c-render-canary-loop.md` §6, with the §5 standing
canary set. Baseline `master` @ f56b898d9; built and validated in an isolated
worktree; **no commits made** — deliverable is a patch.

---

## 0. TL;DR

| | |
|---|---|
| Ships | `ruffle-tests/render_canary.py` (768 lines), `ruffle-tests/render_canary_tests.txt` (20 tests), `.gitignore` += `.render_canary/` |
| Changes to `verify_output.py` | **none** — it is a driver, exactly as w1c predicted |
| Validation | full canary set captured **twice, unchanged → 37/37 IDENTICAL, exit 0** |
| Cost | **cold 421 s** (7.0 min, 21.1 s/test) · **warm 53 s** (2.7 s/test), both at `-P 2` |
| Comparisons | 37, not w1c's estimated 41 (12 + 7 + 18×1) |
| DIFFERS path | validated on a synthetic label: DIFFERS / APPEARED / VANISHED / trace-text / trace-status / image-status all fire, exit 1 |
| Two bugs found *by* validating | Pillow `getbbox()` alpha-only default (would have silently reported "no change" for every RGB-only move); md5-differs-but-pixels-identical needs its own annotation |
| Working tree | clean throughout — capture never writes into a test dir |

---

## 1. What shipped

### `ruffle-tests/render_canary.py`

```
render_canary.py capture --label NAME
        [--tests FILE | --test SUITE/NAME ...] [--tier 1|2|all]
        [--jobs N] [--recompile] [--timeout S] [--force] [--out DIR]

render_canary.py compare BEFORE AFTER          # or --before/--after
        [--json PATH] [--expect-differs PATTERN ...] [--verbose] [--out DIR]

render_canary.py run --stash PATH... [...]     # one-shot wrapper, EXPERIMENTAL
```

**capture** runs each test as

```bash
SWF_KEEP_BUILD_DIR=<label>/<suite>/<test>/_build \
python3 ruffle-tests/verify_output.py \
    --tests-dir=ruffle-tests/tests/swfs/<suite> --test=<test> \
    --mode=graphics --images --diff \
    --json=.../result.json --save-actual=.../trace.txt
```

then harvests and deletes the build dir (25 MB each — 20 tests × 2 labels
would be a gigabyte otherwise). Per (test, label) it keeps:

| file | purpose |
|---|---|
| `<cmp>.png` | the actual render, one per `[image_comparisons]` entry |
| `result.json` | the verify_output report — trace status, phases, **and the image stats block, which exists nowhere else** (mode 7) |
| `trace.txt` | filtered actual trace text (`--save-actual`) — the trace-regression axis |
| `console.txt` | stdout+stderr incl. the `--diff` output, for humans |
| `meta.json` | canary-side summary: per-comparison md5, exit code, wall, statuses |

plus `<label>/manifest.json` (git sha, dirty-file list, jobs, `recompile` flag,
per-test results). `<cmp>.difference.png` — verify_output's actual-vs-*expected*
diff — is deliberately **dropped**: it is the wrong axis and it exists only for
some verdicts, which would make the capture verdict-dependent.

**compare** is md5-first, per `(test, comparison)`:
`IDENTICAL` / `DIFFERS` / `APPEARED` / `VANISHED` / `NO_RENDER`. For every
`DIFFERS` it copies both PNGs into `<out>/_compare/<A>__<B>/<suite>/<test>/` as
`<cmp>.before.png` / `<cmp>.after.png` and calls **`verify_output.compare_images`**
on them (before = reference), so `diff_channels` / `mean_diff` / `max_diff` are
*definitionally* CI's numbers rather than a reimplementation; it adds a
changed-pixel bbox and leaves the difference PNG next to the pair.
Independently of pixels it compares `trace.txt` byte-for-byte, the trace
verdict, and the CI-graded per-comparison image status.

Exit: `0` clean, `1` something moved, `2` usage/missing label. `NO_RENDER` is
reported but does **not** gate (mode 8). `--expect-differs PATTERN` (fnmatch on
`suite/test` or `suite/test:cmp`, repeatable) asserts the blast radius in *both*
directions — an `IDENTICAL` inside the pattern is a violation, as is any move
outside it — because "IDENTICAL on a test the change was meant to affect" is as
much a finding as the reverse. Under `--expect-differs` the pixel axis stops
gating but the **trace axis still does**: a blast-radius pattern is about
pixels and says nothing about traces.

### `ruffle-tests/render_canary_tests.txt`

The §5 set, one `suite/test` per line, `#` comments, and a `# tier=N` marker
line that partitions the file so `--tier 1|2` filters without a second file.
**All 20 paths verified to exist and to carry `image_comparisons`** (substring
match, not a `^\[image_comparisons` grep — w1c §2's two-syntactic-forms trap),
and, stronger, all 20 were actually captured twice below. `regression/` is
represented 3×.

### `.gitignore`

`.render_canary/` — the default `--out` root, a gitignored local dir under the
repo. (w1c suggested the scratchpad; a repo-local ignored dir keeps captures
discoverable next to the tree they describe and survives scratchpad churn.
`--out DIR` overrides.) The canary *set* is tracked; the captures never are.

---

## 2. Validation

### 2.1 Determinism / full-list smoke — the headline result

Two full captures of all 20 tests, no source change between them:

```
$ python3 ruffle-tests/render_canary.py capture --label base1 -P 2
  20 tests, 37 PNGs captured in 421.2s (21.1s/test)      # cold

$ python3 ruffle-tests/render_canary.py capture --label base2 -P 2
  20 tests, 37 PNGs captured in 53.4s (2.7s/test)        # warm

$ python3 ruffle-tests/render_canary.py compare base1 base2
RENDER CANARY  before=base1  after=base2   20 tests / 37 comparisons

  IDENTICAL    37
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0

  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
exit 0
```

This is simultaneously (a) the all-IDENTICAL determinism check, (b) proof that
every entry in the standing list runs, and (c) proof that the capture harvests
what it claims. All 20 tests reported trace `pass` in both legs; 37 PNGs each.

w1c's byte-identical finding replicates at 37 PNGs across a *cold* and a *warm*
leg at `-P 2` — including the two multi-comparison tests. Nothing needs an
epsilon.

Per-test wall (cold → warm), `-P 2`:

| test | cold | warm | | test | cold | warm |
|---|---|---|---|---|---|---|
| avm1/color | 3.2 | 6.2 | | from_shumway/timeline/timeline_as2_5 (7 cmp) | 15.5 | 10.8 |
| avm1/mask_with_drawing | 2.6 | 4.1 | | from_shumway/acid/acid-gradient-0 | 67.6 | 6.3 |
| avm1/bitmap_data_fillrect | 7.6 | 5.7 | | regression/avm2_timeline_stroke_gradient | 83.1 | 3.2 |
| avm1/movieclip_setmask | 72.8 | 6.8 | | regression/avm2_timeline_gradients | 99.4 | 3.5 |
| avm1/edittext_tag_indent | 71.7 | 4.5 | | visual/simple_shapes/masks | 8.2 | 3.2 |
| avm1/bitmapdata_applyfilter_colormatrix | 78.7 | 5.5 | | visual/simple_shapes/gradients/gradients | 9.8 | 3.2 |
| avm1/focusrect_swf5 (12 cmp) | 84.5 | 6.8 | | visual/filters/drop_shadow | 8.6 | 4.0 |
| avm2/blend_multiply_alpha | 88.3 | 7.2 | | visual/filters/color_matrix | 7.5 | 3.6 |
| visual/simple_shapes/winding_rule | 86.5 | 7.0 | | visual/blend_modes/multiply | 8.3 | 3.6 |
| visual/cache_as_bitmap/shape_changed | 7.9 | 6.7 | | regression/avm2_morph | 27.7 | 3.2 |

("cold" here is partly warm already — three of these tests had been built
minutes earlier in a smoke run, and ccache is shared. The 7-minute cold figure
is the realistic *first-canary-of-a-session* number on this machine; the
53-second warm figure is what every subsequent leg costs when only test-local
code changed.)

**Budget guidance for wave-2 render agents:** capture `before` once (7 min),
then each `after` leg costs 53 s **plus** a one-time recompile of whatever
runtime TU you edited (ccache is content-keyed and global, so that cost is paid
once, not per test). A scoped change should iterate on the family subset via
`--test` and run the full 20 before handoff.

### 2.2 DIFFERS path

No local render perturbation was possible without editing tracked runtime
sources, so — per the brief's fallback — the compare path was exercised against
a synthetic third label built by copying `base2` and hand-editing the captured
artifacts: XOR 0x40 on the R channel of a 20×10 block of `avm1/color`'s actual;
delete `visual/filters/color_matrix`'s PNG; add a second PNG under
`regression/avm2_morph`; append a line to `avm1/edittext_tag_indent`'s
`trace.txt` and flip its status; flip `visual/simple_shapes/masks`'s image
status. Every classification fired:

```
$ python3 ruffle-tests/render_canary.py compare base1 perturbed
RENDER CANARY  before=base1  after=perturbed   20 tests / 38 comparisons

  IDENTICAL    35
  DIFFERS       1
  APPEARED      1   VANISHED 1   NO_RENDER 0

  DIFFERS:
    avm1/color  output   [DIFFERS]
        diff_channels 200/880000  mean 0.0145  max 64   bbox (100,40)-(120,50)
        image status: pass -> pass    trace: pass -> pass
    regression/avm2_morph  output.02   [APPEARED]
        image status: None -> None    trace: pass -> pass
    visual/filters/color_matrix  output   [VANISHED]
        image status: fail -> fail    trace: pass -> pass

  TRACE STATUS CHANGES:
    avm1/edittext_tag_indent   pass -> output_mismatch   (trace text differs)
  IMAGE STATUS CHANGES:
    visual/simple_shapes/masks  output   fail -> pass        <-- REVIEW

  before/after PNGs + difference PNGs: .render_canary/_compare/base1__perturbed
exit 1
```

`diff_channels 200` is exactly 20×10 pixels × 1 channel and `max 64` is exactly
the XOR magnitude — the imported `compare_images` is wired up correctly and the
bbox is exact.

### 2.3 Exit-code matrix

| invocation | exit |
|---|---|
| `compare base1 base2` (clean) | 0 |
| `compare base1 perturbed` | 1 |
| `compare base1 perturbed --expect-differs 'avm1/color*'` (moves outside radius) | 1 |
| `compare base1 base2 --expect-differs 'avm1/color*'` (expected move absent) | 1 |
| `compare base1` (one label) | 2 |
| `capture --label base1 ...` (label exists, no `--force`) | 2 |

### 2.4 Other checks

- `--recompile` forwards correctly and, as a bonus data point, a full
  recompile-from-scratch of `avm1/color` reproduced md5
  `44a2ebaca9c5140c54b48070c46331e2` — identical to the cached-`RecompiledScripts`
  capture. The mode-1 reminder banner prints only when `--recompile` is absent.
- `git status --porcelain` after all of the above lists only the deliverable
  files. Capture writes nothing into any test dir, so the tracked
  `regression/` suite stays clean — that is the whole reason `--verbose` is
  banned (mode 6).
- `--tier 1` → the 14 CI-passing tests, `--tier 2` → the 6 others, `all` → 20.

### 2.5 NOT validated

`run --stash` is implemented (capture after → `git stash push -- PATHS` →
capture before → `git stash pop` in a `finally`, then compare) but was **not
executed** — it needs a real source change to be meaningful and a stash in a
shared checkout is not worth the risk for a demo. It is documented as
experimental. The two-phase flow is the supported path; that is also what w1c
recommends.

---

## 3. Two traps found while building this

Both are now handled in the script; both would have made the canary **quietly
under-report**, which is the worst failure mode a canary has.

1. **Pillow ≥ 9.2 `Image.getbbox()` defaults to `alpha_only=True` on RGBA.**
   The first DIFFERS run reported `bbox -` for a real, correctly-counted
   200-channel RGB change, because the difference image's alpha was zero
   everywhere. Almost every render regression is RGB-only, so the bbox column
   would have read "no change" essentially always. Fixed with
   `getbbox(alpha_only=False)` and a `TypeError` fallback for older Pillow.
   Worth remembering for **any** other pixel tooling in this repo — the same
   default silently applies to `w1b`-style triage code.

2. **md5 is a bound on the FILE, not on the pixels.** The first perturbation
   attempt clamped at 255 and changed no pixel, yet the md5 moved (PIL
   re-encoded the file). The compare now annotates a `DIFFERS` whose
   `diff_channels` is 0:

   > `!! PNG BYTES differ but every PIXEL matches — a re-encode (different
   > encoder/settings), not a render change.`

   It still gates, because a canary should never silently swallow an
   unexplained byte move — but the reader is told immediately that this is a
   build/toolchain event, not a render event. Recorded as an **11th mode** in
   the script docstring, alongside w1c's ten.

---

## 4. False-positive / false-negative modes

w1c §6's list is reproduced **verbatim in the module docstring** of
`render_canary.py`, so `--help` and any reader of the file gets it. Headline,
restated because it is the one that wastes a whole session:

> **Stale recompiler output is the silent false NEGATIVE.** A change under
> `SWFRecomp/` does not take effect unless you (a) rebuild the recompiler with
> cmake **and** (b) pass `--recompile` — `RecompiledScripts/` is cached inside
> each test directory. Without both, the canary reports `IDENTICAL` for every
> test and you conclude your change was inert. `SWFModernRuntime/` changes need
> neither: compilation always re-runs and ccache is content-keyed.

`capture` prints a reminder banner whenever `--recompile` is absent. The two
corollaries the script encodes rather than merely documents:
`--expect-differs` (mode 10 — `IDENTICAL` everywhere is a red flag, not a clean
bill) and non-gating `NO_RENDER` (mode 8).

And the framing above all ten: **the canary is never a grade.** It is our-render
before vs our-render after, on one machine, with one renderer. Local Dawn is not
pixel-identical to CI's lavapipe. It answers "did my change move the pixels, and
where"; CI answers "are the pixels right".

---

## 5. Worktree / environment notes

- **`DAWN_INSTALL` must be overridden in a git worktree.** `verify_output.py`
  defaults it to `<repo-parent>/dawn-install`, which for a worktree at
  `.claude/worktrees/agent-*` resolves to `.claude/worktrees/dawn-install` and
  fails instantly with "Dawn library not found". `render_canary.py` detects
  this and falls back to `~/CC/dawn-install`, printing which it used; an
  explicit `DAWN_INSTALL` env var always wins. In the main tree nothing
  changes.
- A worktree also lacks the gitignored suite data. Per the wave-1A audit, never
  point `--tests-dir` at the main tree for runs — copy the test dirs you need
  into the worktree's identical suite paths (~100 KB each; the whole 20-test
  canary set is 2.7 MB) and copy `SWFRecomp/build` (11 MB) across.
- Nested test names (`visual/simple_shapes/gradients/gradients`) work as
  forward-slashed relative paths under a pinned `--tests-dir`; `--tests-dir` is
  always pinned by the script, so a bare name is never ambiguous across suites.
- `-P 2` is the default and 4 is a hard cap in code, per w1c §4.

---

## 6. Quick recipes for a wave-2 render agent

```bash
# once, before touching anything (7 min cold on this machine)
python3 ruffle-tests/render_canary.py capture --label before

# ... edit SWFModernRuntime/ ... then, per iteration (53 s):
python3 ruffle-tests/render_canary.py capture --label wip --force
python3 ruffle-tests/render_canary.py compare before wip

# iterate faster on just the family you touched
python3 ruffle-tests/render_canary.py capture --label wip --force \
    --test visual/simple_shapes/gradients/gradients \
    --test from_shumway/acid/acid-gradient-0

# assert the blast radius in BOTH directions before handoff
python3 ruffle-tests/render_canary.py compare before wip \
    --expect-differs 'visual/simple_shapes/gradients/*' \
    --expect-differs 'from_shumway/acid/*'

# recompiler change: cmake rebuild FIRST, then --recompile on BOTH legs
python3 ruffle-tests/render_canary.py capture --label before --recompile
python3 ruffle-tests/render_canary.py capture --label wip --recompile --force
```

`compare` exits non-zero on any move, so it drops straight into a pre-handoff
gate. `--json PATH` writes the machine-readable form (per-comparison verdicts,
stats, both manifests' git sha + dirty-file list, blast-radius violations).

---

## 7. Files

| path | status |
|---|---|
| `ruffle-tests/render_canary.py` | new, 768 lines |
| `ruffle-tests/render_canary_tests.txt` | new, standing 20-test set, tiered |
| `.gitignore` | +6 lines (`.render_canary/`) |
| `SWFRecompDocs/plans/session9-graphics-setup-reports/w2-3-render-canary.md` | this report |

Patch: `scratchpad/patches/w2-3-render-canary.patch`. No commits made.
