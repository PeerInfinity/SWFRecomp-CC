# Corpus fan-out session 19: trace + graphics, Opus-coordinated

You are the **coordinator** for a dual-axis Ruffle-test corpus fan-out: trace
tests and graphics (pixel) tests. **You are running on Opus, not Fable**: the
week's Fable budget is nearly spent, so this whole session, coordinator and
subagents alike, is Opus. The method is the standing one and is written down in
memories `parallel-fanout-wave-pattern` and `graphics-fanout-playbook`:
subagents in worktrees, serial merge, CI, results merge, closeout. **Follow
those; don't re-derive them, and don't implement the slices yourself.**

## 0. Wait for `bitmap-pool-layer-cap` first

A single-task session, **`bitmap-pool-layer-cap`**, is finishing in this same
tree. It has landed `a39a8ab0c` (every bitmap texture array kept under the
device's `maxTextureArrayLayers`), and its last CI run was in flight at launch:
a deliberate `images=true` run that will move the **pixel baseline**. It has
been told to send its REPORT BACK **to you** (`corpus-fanout-s19`).

**Until that report arrives, do not:**
- touch the working tree,
- download tests,
- create worktrees,
- spawn agents,
- dispatch CI.

Reading docs, results and memory is fine, and so is drafting the boards in your
head or the scratchpad. When you're ready to wait, subscribe once with
`SendMessage(to: "bitmap-pool-layer-cap", notify_when_idle: true)` and no
message, then end your turn. Its report, or the idle notice, wakes you. Never
poll in a loop.

**When the report arrives, check it against disk before relying on it** (the
message proposes, the repo confirms):
- its closeout `SWFRecompDocs/status/bitmap-pool-layer-cap.md` exists,
- its commits are on `origin/master`,
- its CI runs completed,
- `git status` is clean, apart from anything it says it left on purpose.

If the report is missing or fails that check, or the session is dead with no
closeout, stop and tell the user rather than starting the fan-out on top of a
half-finished slice.

## 1. Baseline

**Read it fresh off `origin/ruffle-test-results` after the layer session's runs
merge. Never quote a number from this brief or any closeout** (memory
`ci-baseline-must-be-read-fresh`: the graphics total is ±1 at the same code, and
an intersection count is not the corpus total).

- For orientation only: trace was **4411 effective** in both modes at
  `c49f8b2f0` / `67ba188ce`.
- Pixels were **381/577** at session 18's close. The layer session's
  `images=true` run supersedes that, so take the pixel baseline from ITS merged
  results.
- Read runs with `scripts/corpus_status_diff.py` (trace) and
  `scripts/image_status_diff.py` (pixels; read the PROVENANCE banner).

## 2. Start here, once the wait is over

**1. Fresh test download.** Run `bash ruffle-tests/download_tests.sh`. **Never
pass `--clean` locally**: it deletes `_investigation/` and `_results/`, which
are this project's own work. Upstream drift is expected. Three tests already
moved this week from Ruffle commits, not from us:
- `avm2/geom_transform` (`45be8d5365`, `DisplayObject.z`),
- `from_avmplus/ecma3/JSON/adhoc` (`af88e41a58`, a new `output.ruffle.txt`),
- `avm1/bitmapdata_custom_rectangle` (`352718de29`, 34→42 lines).

All three are fresh small targets (see §3).

**2. Update `~/CC/ruffle`, keeping our edits.** It is **94 commits behind**
upstream and its working tree is dirty with changes **we** made. They must
survive:
- `Cargo.lock`
- `core/src/tag_utils.rs`
- `exporter/{Cargo.toml,src/cli.rs,src/exporter.rs,src/lib.rs,src/main.rs}`
- `render/wgpu/{Cargo.toml,src/lib.rs,src/surface/commands.rs}`
- `web/{Cargo.toml,src/lib.rs}`

That list is longer than last session's. Steps:
1. Save them: `git -C ~/CC/ruffle diff > <patch>`, plus `git diff --staged` if
   anything is staged.
2. `git pull --ff-only`.
3. Re-apply, and **verify the re-apply actually succeeded**.
4. If a hunk conflicts, stop and report it. Never resolve a conflict by
   dropping our change.

The exporter is the oracle for new fixtures. Memory `mcl_load_timing` has its
recipe for a parent that loads a relative child: `RUFFLE_LOCAL_FETCH_DIR` plus
an https `RUFFLE_MOVIE_URL`, because a plain `file://` run silently never loads
the child.

## 3. The boards

Build them from the **current failure inventory**, since the corpus has moved.
The pre-written boards are the starting point, not the plan:
- **Trace:** `SWFRecompDocs/plans/polish-sweep-arc.md` §19.4.
  `loader_duplicate_class` there is **DONE** (`c4a952960`, 48/48); strike it.
- **Pixels:** `SWFRecompDocs/plans/graphics-fanout-playbook.md` §17.

New leads from today's single-task slices (each has a closeout under
`SWFRecompDocs/status/` and an entry in `SWFRecompDocs/BACKLOG.md`):
- the three upstream-drift tests in §2 step 1;
- a loaded child's `SimpleButton` has no states (`button_data_for_char` has no
  `g_child_movies` fall-through; from reading the code, not a failing test);
- MovieClipLoader's `onLoadStart` doesn't model Ruffle's initial-loading state
  (tf/fl/bytes read 0 there);
- MCL loads land a tick late: `onLoadInit` fires before the root's first
  `onEnterFrame`, where Ruffle fires it after. That is the cleanest remaining
  MCL diff. It is tangled with the double frame step that
  `from_shumway/avm1/moviecliploader` relies on, so scope before implementing.

Standing triage rules:
- `runtime_error` is the cheapest axis.
- Check `ACCEPTED_DIFFS.md` / `RUFFLE_VS_FLASH_DIFFERENCES.md` /
  `RUFFLE_COMPAT_TWEAKS.md` / `FLASH_BUGS_REPLICATED.md` **before**
  implementing anything (memory `triage-check-accepted-diffs-first`).
- A pass → `ruffle_matched` move on a known_failure is a regression, not a win
  (memory `ruffle-matched-hides-regression`).
- Tell every wave-2 agent which files its siblings are editing.

## 4. Operating limits (each one bit a past session)

- **Keep ≤ ~8 agents live at once.** The 5-hour session limit killed all 12
  live agents at once in session 18. Hold the rest as written briefs, never
  spawn the whole queue after a reset, and resume by `SendMessage` (worktrees
  survive).
- **The host OOM-kills background tasks** even with ~11 GB free: today it
  killed `gh run watch`, two `git fetch` pollers and a launcher. What survived:
  the Monitor tool, and a foreground poll of the results branch.
- **Dispatch CI serially**: one mode at a time, never two runs overlapping. Use
  graphics / `categories=full` / `images=true` for the combined grading run
  (both axes). Then run no-graphics / `full`, per CLAUDE.md.
- `.claude/worktrees/` should end the session empty. Clean up your worktrees at
  closeout. **Never merge `t5-iso-v1`** (a subtractive bisect variant).
- `git stash` is shared across worktrees; use patch files. Pattern kills are
  guard-denied; use literal PIDs (memory `pkill-f-self-match`). `single_test`
  resolves bare names against `avm1/` only.
- `from_shumway/as3-loader/bug1157243/empty` is a known ±1 intermittent. Don't
  re-derive it.

## 5. Done means

The standing closeout:
- a new §20 in `polish-sweep-arc.md` with the ledger and "left on the board";
- the matching playbook section for pixels;
- per-agent reports under `SWFRecompDocs/plans/session19-fanout-reports/`;
- memory `next-session-dual-axis-fanout` updated;
- commits pushed and both CI modes merged;
- regressions named;
- worktrees cleaned.

**Report to the user directly, not to the session that launched you.** It
isn't supervising this wave, and the user asked that sessions not relay
through it.
