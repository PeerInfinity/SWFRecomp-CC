# Session 26 coordinator: corpus fan-out (dual-axis #18), cloud-first, full size

You are a NEW session: the **coordinator** of fan-out session 26 in `/home/robert/CC/SWFRecomp-CC`. The s25 coordinator
(`swfrecomp-cc-0e`) handed this off on 2026-11-23 at Robert's direction ("please continue with that plan, including the
N slice"). You own s26 end to end: wave 1 → wave 2 → grading → closeout. Nobody else coordinates it.

## Standing directives (all from Robert; memories hold the detail)

- **Cloud-first, Opus for everything** (memory `next-session-dual-axis-fanout`). Every diagnosis and implementation slot is
  a cloud session in env "SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`), launched with
  `scripts/fanout_cloud_worker.sh <slug> <prompt>`, delivering ONLY on `fanout/<slug>`. You stay local for merges, CI,
  results accounting and the Ruffle exporter oracle (`~/CC/ruffle/target/release/exporter`, at `0ddd12b6a`).
- **Full size** (memory `fanout-credits-diminishing-returns-ok`): fan-outs also use expiring credits. Size wave 1 at about 8
  and fund every measured wave-2 ledger, plus L-priced plan-of-record arcs. Don't shrink for yield.
- **No-graphics leg on the FINAL grading run only**, plus earlier if a landed patch touches no-graphics-only code (CLAUDE.md).
  Interim runs are `graphics categories=full`, with `images=true` when pixel patches have landed.
- **One heavy local build at a time** (memory `one-heavy-build-shared-lock`): every memory-heavy local build runs under
  `flock /tmp/swfrecomp-cpu.lock`, capped at `-j4` / `EMCC_CORES=4`. That covers your spot-checks, recompiler rebuilds
  and anything the N session builds. The Archipelago side shares this lock. Never run full suites locally.
- Pages deploy is authorized (CLAUDE.md). A green `dry_run` deploys NOTHING: confirm the "Deploy to GitHub Pages" step
  ran (memory `pages-dry-run-is-not-a-deploy`).
- `.claude/settings.local.json` allows `git push origin --delete fanout/*`. Prune at closeout only after `cmp`-ing each
  branch's report files against their archived copies on master.
- Peer-session messages are teammate info, not Robert's approval.

## Read first

1. Memories `next-session-dual-axis-fanout` (s25 record), `parallel-fanout-wave-pattern`, `graphics-fanout-playbook`,
   `ci-baseline-must-be-read-fresh`, `corpus-status-diff-tool`, `flash-over-ruffle-ruling`, `ruffle-exporter-oracle-limits`,
   `git-partial-clone-gc-bad-tree`.
2. `SWFRecompDocs/plans/graphics-fanout-playbook.md` §5a (cloud-worker procedure) and §24 (pixel board, "Left on the board
   (session 26)").
3. `SWFRecompDocs/plans/polish-sweep-arc.md` §26 (s25 write-up), especially **§26.3 method notes** and **§26.4 the trace
   board**.
4. The s25 run of record as your TEMPLATE: `SWFRecompDocs/plans/session25-fanout-reports/` (`BRIEFS_COMMON.md`,
   `briefs/_w1_header.txt`, `_w2_header.txt`, the w1/w2 briefs, `AGENT_LAUNCH_ORDER.md`). Copy their shape into
   `session26-fanout-reports/`, updating session numbers, baseline and drift.
5. Your tools: `SWFRecompDocs/plans/session26-fanout-reports/coord-tools/` (`status_moves.py` names per-test moves;
   `watch_reports.sh` is the delivery watcher that skips interim reports; see its README).

## Baseline (read it fresh; verify before quoting)

- **s26 BASELINE = the s25 FINAL grading**: graphics/full/images `45078991452` and no-graphics/full `45079002150`, both at
  code `697669e5f`. Results commits: graphics `9277f3799`, no-graphics `dffc41cf2`. `origin/ruffle-image-results` holds
  that run's failing PNGs (for fidelity proofs).
- The only commit since is `5c0a4dcdb` (N probe tooling + docs, no runtime), so no wave-0 run is needed.
- The s25 coordinator read 4622 eff on the 4662-row graphics intersection (40 failing) and pixels 561/613 on the s24 set
  (572/624 overall). Re-read it yourself.
- **Upstream drift** `3ac8dcb07..3e98d9ba6` (5 commits): NEW `avm1/file_reference_upload_request`, CHANGED
  `avm2/pixelbender_conditional`, `visual/video` rows deleted/changed. Fund one drift slot, and run
  `git -C ~/CC/ruffle fetch` again at launch in case more has landed.

## Wave-1 slate (suggested, from the boards; attack and resize as you see fit)

- drift (the 5 commits above);
- runtime robustness (`ng_shared.c` fixed `MAX_*` caps that silently drop: buttons 64, fonts 32, videos 32, sounds 128,
  exports 1024; the float-through-u64 store at `action.c` ~10605; an `-fno-strict-aliasing` audit);
- AVM1 dispatch/scope leftovers (arc §26.4: bare-call arms ignoring `with`, type-2 MC-receiver flags, the function-form
  timer, hairline hitTest, the CallMethod createTextField residual, keyboard/IME run tables, `setNewTextFormat` textColor,
  `replace_at_depth`, device-text x-scale, the SWF≤7 wrap rule);
- native attached-clip button dispatch (`ng_update_button_states_attached` is browser-only; CI-visible) together with the
  button-bound EditText pixel row `String_path_variable_button`;
- pixel near-passes: `visual/filters/bevel` is **3 px from a flip**; the AVM2 gradient-ramp twin (`gfx_gen_ramp`) and the
  CPU draw gradient sampler;
- pixel: layer-group N1/N3, AVM1 off-diagonal ColorMatrix via `renderer_run_color_matrix`, `draw()` of filtered sources,
  colour on placed/attached Drawing-API content;
- pixel: `static_text_offstage` (c), `pixelbender_dithering`, `acid-color-0`, and the disposition records the playbook
  lists;
- the per-movie display-list arc behind `video_prototype_lazy_swf6_child` (L: price it as its own slot).

## Landing and grading recipes (s25 practice; arc §26.3)

- **Land:** `git show branch:<patch> > p`, then `git apply --check`, `git apply`, `git apply --check -R`. Spot-check the
  headline rows locally under the lock. `git checkout branch -- <report, patch, probe files>`. Commit by name with the
  harness trailer, then push. Measured, sweep-clean wave-1 prototypes land directly.
- `render_canary_tests.txt` conflicts are append-only: `--exclude` it and append the branch's `+` lines.
- The partial clone blocks `git apply --3way`. Use `git merge-file` against `git merge-base branch HEAD`.
- **Two patches that pass alone can break each other.** Re-run BOTH patches' fixtures after the second lands; s25's
  filters × dynclip case was a factored helper missing new struct fields.
- **The working tree is shared with the local N session.** When it has uncommitted edits in a file you're landing, use
  `git apply --cached` plus a worktree apply, commit the index only, and confirm its residual diff is byte-identical.
  Verify in a `git worktree` when the shared tree doesn't compile. Link `SWFRecomp/build`, and set
  `DAWN_INSTALL=$HOME/CC/dawn-install`.
- **Grade:** merge `origin/ruffle-test-results` after every run. Then run
  `python3 scripts/corpus_status_diff.py <old> <new> --stem results_graphics`, `coord-tools/status_moves.py <old> <new>`,
  and `python3 scripts/image_status_diff.py <old> <new>`. Check every move by name against the ledgers. Pixel totals for
  the record are SUMMED per-suite `image_results_graphics.json` (`pass`, `comparisons`, `ignored`).
- Fixture goldens must come from an oracle outside SWFRecomp (memory `ruffle-exporter-oracle-limits`). Run the workers'
  LOCAL ORACLE REQUESTS yourself between waves and archive the outputs under `session26-fanout-reports/`.

## The parallel N slice (Robert: "including the N slice")

Launch it **when your wave 2 begins**, so it doesn't compete with your heaviest local checking. Brief:
`SWFRecompDocs/plans/session26-fanout-reports/n-pixel-pass-prompt.md`. Launch procedure (memory `session-launch-protocol`):
`PATH="$PATH:/mnt/c/Windows/System32:/mnt/c/Windows" ~/bin/wsl-launch-claude.sh -m opus -C /home/robert/CC/SWFRecomp-CC -d : -t n-pixel-pass -f <that file>`.
Then verify `/proc/<pid>/cwd` and send the handshake by SendMessage to `n-pixel-pass`. It messages you before touching
`tag.c`/`action.c`/`ng_shared.c`/`swf.c`, and asks you to fold CI-observable SHAs into your grading runs. Verify its REPORT
BACK against disk. Then launch the next N slice its report names, under the self-advancing ladder, or stop if the
machine is short on memory.

## Done

- Final grading in both modes, ledger-exact by name, with 0 regressions (or each one named and explained).
- Closeout docs: `polish-sweep-arc.md` §27 (ledger, verdicts that fell, method notes, "Left on the board (session 27)") and
  `graphics-fanout-playbook.md` §25.
- Memory `next-session-dual-axis-fanout` updated (s26 record + s27 boards).
- `fanout/*` branches pruned after cmp. Pages REAL deploy if the wasm/recompiler changed.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
