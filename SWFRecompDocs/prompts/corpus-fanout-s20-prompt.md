# Corpus fan-out session 20: trace + graphics, Opus-coordinated

You are the **coordinator** for a dual-axis Ruffle-test corpus fan-out: trace
tests and graphics (pixel) tests. This is fan-out #12; sessions 7–19 all ran
this way.

**You are running on Opus, and so is every agent you spawn.** The week's Fable
credits are spent — that is why this session is Opus top to bottom. Session 19
ran the same way with no trouble, but the weekly/5-hour Opus limits are the
real risk here; see §4.

The method is the standing one and is already written down in memories
`parallel-fanout-wave-pattern` and `graphics-fanout-playbook` (doc:
`SWFRecompDocs/plans/graphics-fanout-playbook.md`): wave 1 read-only diagnosis
in parallel, wave 2 implementation in **isolated worktrees**, patches merged
**serially** with a per-patch headline re-check, combined CI runs, results
merge, closeout. **Follow those; don't re-derive them, and don't implement the
slices yourself.**

## 0. Starting state (verified at launch, 2026-09-18)

- `master` is at `4b05de6ef`, working tree **clean**, no worktrees, no other
  session running in this tree. Nothing to wait for — start immediately.
- The last thing to land was a **runtime perf lever**, not a corpus change:
  `2973513c4` inlined the AVM2 getproperty IC's slot hit (Seedling collide
  frame 1.41x), graded byte-identical in both modes. Its closeout is
  `SWFRecompDocs/status/seedling-collide-hotloop.md`.

## 1. Baseline

**Read it fresh off `origin/ruffle-test-results`. Never quote a number from
this brief or any closeout** (memory `ci-baseline-must-be-read-fresh`: the
graphics total is ±1 at the same code from a known load-sensitive intermittent,
and a diff's intersection-effective is not the corpus total). Name the *results
commits*, diff them, and let the tools speak:

- `python3 scripts/corpus_status_diff.py <pre_sha> WORKTREE --per-suite`
  (trace; reads `results_graphics` — memory
  `ci-baseline-is-results-graphics-not-results`). Read its **OTHER STATUS
  MOVES** section every single run: a `pass → ruffle_matched` move is a
  regression the effective count hides (memory
  `ruffle-matched-hides-regression`).
- `python3 scripts/image_status_diff.py <prev> master` (pixels) — read the
  PROVENANCE banner; exit 2 means you gave it the same run twice.

For orientation only, and stale by construction:

- **Trace** last graded at run `35163868554` (graphics, `categories=full`) and
  `35166754380` (no-graphics, full), both at `4b05de6ef`'s code; results
  commits `6c1329197` (graphics) and `6bf7f3c30` (no-graphics), already merged
  into master. Session 19 closed at 4436 effective / 4520 intersection.
- **Pixels** were **392 / 580 (67.6 %)** at images run `34666689502`
  (`d8da5a18c`, 2026-09-12), image-results commit `038e161da`. **No
  `images=true` run has happened since**, so the pixel baseline predates six
  days of landed work — expect your first `images=true` grading run to show
  movement that is not yours, and price it as such before booking it.

## 2. Start here

**1. Fresh test download.** `bash ruffle-tests/download_tests.sh`. **Never pass
`--clean` locally** — it deletes `_investigation/` and `_results/`, which are
this project's own work. Upstream drift is expected and must be named
separately from your yield (memory `ci-baseline-must-be-read-fresh`, and the
s14 lesson: never book drift yield until the CI name-set diff). One drift
event is already known: Ruffle `7e8e2de8a` (2026-09-15) rewrote
`goto_framescript_queued/swf13`'s expected output — the last closeout run
attributes that row to upstream, not to us. Hand the rest of the drift audit to
a wave-1 agent to verify against `~/CC/ruffle` (the coordinator's own drift
list was wrong twice in s18).

**2. Update `~/CC/ruffle`, keeping our edits.** It is behind upstream and its
working tree is dirty with changes **we** made. They must survive:
`Cargo.lock`, `core/src/tag_utils.rs`,
`exporter/{Cargo.toml,src/cli.rs,src/exporter.rs,src/lib.rs,src/main.rs}`,
`render/wgpu/{Cargo.toml,src/lib.rs,src/surface/commands.rs}`,
`web/{Cargo.toml,src/lib.rs}`, plus the untracked
`exporter/src/{automation.rs,local_navigator.rs}`. Steps: save with
`git -C ~/CC/ruffle diff > <patch>` (plus `--staged` if anything is staged),
`git pull --ff-only`, re-apply, and **verify the re-apply succeeded**. If a
hunk conflicts, stop and report it — never resolve by dropping our change.

The exporter is the oracle for new fixtures. Memory `mcl_load_timing` has the
recipe for a parent that loads a relative child (`RUFFLE_LOCAL_FETCH_DIR` + an
https `RUFFLE_MOVIE_URL`; a plain `file://` run silently never loads the child).

## 3. The boards

Build them from the **current failure inventory**. The pre-written boards are
the starting point, not the plan:

- **Trace:** `SWFRecompDocs/plans/polish-sweep-arc.md` **§20.5**. Named leads:
  `hitarea_remove_owner_drag` (now down to ONE mechanism — the single topmost
  pick — but the largest blast radius on the board); `masks_test` at 124/175
  where 34 of the 50 remaining diff lines are `hitTest` on masked/mask clips (a
  hit-test slice, not an events one); gnash `array-v7`/`-v8` (26 comparator
  lines gained, 3 mechanisms to go) and `MovieClip-v6`/`-v7` (held by a 2-line
  `onUnload`-at-depth-−32849 mechanism; `-v8` is out); `bitmapdata_custom_rectangle`
  (built-in `getColorBoundsRect` must construct via the dynamically-resolved
  `flash.geom.Rectangle`); and **`propertyCoerceToNumber`** on the SetMember
  path, which still rejects `±Infinity` and still uses `roundf` for `_alpha`
  unlike the opcode path — wrong vs Ruffle and on every game's hot path.
  §20.5 also lists the standing NO-GOs; don't re-price them without a reason.
- **Pixels:** `SWFRecompDocs/plans/graphics-fanout-playbook.md` **§18**. Top
  leads: Stage3D phases A′ (stencil/colorMask, +2) and B (textures/RTT, up to
  9) — the s19 band moves say they are close; the **even-odd fill across
  `lineStyle()`** defect (`gfx_line_style` calls `gfx_finalize_path`, which
  closes the fill too — 152 of `graphics_simple_shapes`' 154 remaining
  channels); the EditText border corner (owner + fix in `BACKLOG.md`);
  `stage3d_bitmap`'s second mechanism; and the device-face bold/italic ladder
  (~15 LOC, 100 % of `device-font`'s own residual). **`blend_modes` ×12 is
  NO-GO** and its s18 completion mechanism is refuted — do not fund the
  recompiler A/B sweep for it. Device-font outline emission was priced by
  building it and flips nothing (band/correctness arc only).

Standing triage rules to put in **every** brief:
- `runtime_error` is the cheapest triage axis (memory
  `runtime-error-is-cheapest-triage-axis`).
- Check `ACCEPTED_DIFFS.md` / `RUFFLE_VS_FLASH_DIFFERENCES.md` /
  `RUFFLE_COMPAT_TWEAKS.md` / `FLASH_BUGS_REPLICATED.md` / `ignored_tests.txt`
  **before** implementing anything (memory `triage-check-accepted-diffs-first`)
  — and treat ignore-list entries as *claims to re-test*: s19 turned two
  "blocked" verdicts of record into flips because both were simply wrong.
- **Attack your own brief's premises.** Wave-1 refutation yield has been the
  single highest-value habit for six sessions running; s19's refutations killed
  two expensive arcs before they started.
- Tell every wave-2 agent which files its siblings are editing (this is why
  s17–s19 merged 15+ patches with ≈zero textual conflicts), and brief every
  agent to say "not my brief" if a message it receives doesn't match its task.
- A misc pass → fail whose `max_diff` is unchanged while only `outliers` moves
  is **upstream `test.toml` tolerance drift** until proven otherwise; a real
  render regression moves `max_diff`.

## 4. Operating limits (each one bit a past session)

- **Keep ≤ ~8 agents live at once.** The 5-hour limit killed all 12 live agents
  in s18; the weekly limit killed all 10 in s16. Nothing is lost — worktrees
  keep patches and reports — but resume by `SendMessage` with a "you were
  terminated, resume actively; check disk, rerun only what is missing" brief,
  and probe the reset with ONE agent before respawning the queue. Hold the
  remainder as written briefs. With the whole fleet on Opus this week, watch
  the meter and throttle early rather than straddling a reset.
- `SWFRECOMP_COMPILE_TIMEOUT=2400` in every brief; the machine is shared, so
  float mismatches and slow-compile timeouts under load are false until re-run
  sequentially on an idle box.
- Worktree agents must **copy** the test dirs they need into the worktree's
  canonical suite path — never `--tests-dir` at the main tree (the `Recompiled*`
  caches inside shared test dirs cross-poison agents), and `--recompile` on
  first use of a copied dir.
- **Stage patches by name, including new files** (`git apply --stat` lists
  them): `git add -u` drops new files and poisoned an entire s15 CI run.
- `git stash` is **shared across worktrees** — use patch files, never stash.
  Pattern kills are guard-denied and cross-kill siblings; use literal PIDs
  (memory `pkill-f-self-match`).
- **Dispatch CI serially**, one run at a time. The combined grading run is
  `mode=graphics categories=full images=true` (it grades both axes and
  refreshes the pixel baseline); follow with no-graphics `full` per CLAUDE.md.
  Dispatch an early grading run over the first N landed patches while the last
  agents still have context. Bare `apt-get` steps hang CI for hours — cancel
  and rerun, never wait.
- `single_test` resolves bare names against `avm1/` **only**; a name from any
  other suite "fails" on path lookup and that is not a verdict.
- `from_shumway/as3-loader/bug1157243/empty` is a known ±1 intermittent.
- `.claude/worktrees/` must end the session empty. **Never merge `t5-iso-v1`.**
- The host has OOM-killed background pollers (`gh run watch`, `git fetch`)
  before; the Monitor tool and foreground polls of the results branch survived.

## 5. Done means

- a new **§21** in `SWFRecompDocs/plans/polish-sweep-arc.md` with the trace
  ledger, the zero-flip work, method deltas, and "left on the board (session
  21)";
- the matching **§19** in `graphics-fanout-playbook.md` for pixels;
- per-agent briefs, patches and reports under
  `SWFRecompDocs/plans/session20-fanout-reports/`;
- memory `next-session-dual-axis-fanout` updated (and any new standing lesson
  written as its own memory + a `MEMORY.md` line);
- all commits pushed to `master`, both CI modes run and their results branches
  merged, **regressions named by test**;
- worktrees cleaned up.

Autonomous commit / push / CI is authorized per `CLAUDE.md` — don't ask.

**Report to the user directly, not to the session that launched you.** That
session is not supervising this wave; it exists only to start it.
