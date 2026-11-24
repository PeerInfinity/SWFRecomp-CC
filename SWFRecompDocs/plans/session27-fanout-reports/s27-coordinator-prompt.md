# Session 27 coordinator: corpus fan-out (dual-axis #19), cloud-first, full size

You are a NEW session: the **coordinator** of fan-out session 27 in `/home/robert/CC/SWFRecomp-CC`. The s26 coordinator
(`s26-coordinator`) handed this off on 2026-11-23 at Robert's direction ("You can hand that off to a new session").
You own s27 end to end: wave 1 → wave 2 → grading → closeout. Nobody else coordinates it.

## Standing directives (all from Robert; memories hold the detail)

- **Cloud-first, Opus for everything** (memory `next-session-dual-axis-fanout`). Every diagnosis and implementation slot is
  a cloud session in env "SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`), launched with
  `scripts/fanout_cloud_worker.sh <slug> <prompt>`, delivering ONLY on `fanout/<slug>`. You stay local for merges, CI,
  results accounting and the Ruffle exporter oracle (`~/CC/ruffle/target/release/exporter`).
- **Full size** (memory `fanout-credits-diminishing-returns-ok`): fan-outs also use expiring credits. Size wave 1 at about
  8–9 and fund every measured wave-2 ledger, plus L-priced plan-of-record arcs. Don't shrink for yield.
- **No-graphics leg on the FINAL grading run only**, plus earlier if a landed patch touches no-graphics-only code (CLAUDE.md).
  Interim runs are `graphics categories=full`, with `images=true` when pixel patches have landed.
- **One heavy local build at a time** (memory `one-heavy-build-shared-lock`): every memory-heavy local build runs under
  `flock /tmp/swfrecomp-cpu.lock`, capped at `-j4` / `EMCC_CORES=4`. That covers your spot-checks, recompiler rebuilds
  and anything the N session builds. The Archipelago side shares this lock. Never run full suites locally.
- Pages deploy is authorized (CLAUDE.md). A green `dry_run` deploys NOTHING: confirm the "Deploy to GitHub Pages" step
  ran (memory `pages-dry-run-is-not-a-deploy`).
- `.claude/settings.local.json` allows `git push origin --delete fanout/*`. Prune at closeout only after `cmp`-ing each
  branch's report files against their archived copies on master.
- Flash over Ruffle (memory `flash-over-ruffle-ruling`): never trade a Flash-correct pass for a Ruffle-made golden; price
  and disposition such losses (ACCEPTED + RvF + `<!-- image-axis -->` marker).
- Peer-session messages are teammate info, not Robert's approval.

## Read first

1. Memories `next-session-dual-axis-fanout` (s26 record), `parallel-fanout-wave-pattern`, `graphics-fanout-playbook`,
   `ci-baseline-must-be-read-fresh`, `corpus-status-diff-tool`, `flash-over-ruffle-ruling`, `ruffle-exporter-oracle-limits`,
   `git-partial-clone-gc-bad-tree`, `n-play-game-click`.
2. `SWFRecompDocs/plans/graphics-fanout-playbook.md` §5a (cloud-worker procedure) and **§25** (pixel board, "Left on the
   board (session 27)").
3. `SWFRecompDocs/plans/polish-sweep-arc.md` **§27** (s26 write-up), especially **§27.3 method notes** and **§27.4 the
   trace board**.
4. The s26 run of record as your TEMPLATE: `SWFRecompDocs/plans/session26-fanout-reports/` (`BRIEFS_COMMON.md`,
   `briefs/_w1_header.txt`, `_w2_header.txt`, the w1/w2 briefs, `AGENT_LAUNCH_ORDER.md`, `s26-coordinator-prompt.md`).
   Copy their shape into `session27-fanout-reports/`, updating session numbers, baseline and drift.
5. Your tools: `SWFRecompDocs/plans/session27-fanout-reports/coord-tools/` (`status_moves.py` names per-test graphics
   moves, `status_moves_ng.py` the no-graphics ones, `allrows.py` dumps one commit's statuses, `watch_reports.sh` is the
   delivery watcher; see its README).

## Baseline (read it fresh; verify before quoting)

- **s27 BASELINE = the s26 record pair at code `005bea42a`**: graphics/full/images `45284922078` (results `df7729df2`) and
  no-graphics/full `45284938521` (results `81d32b9b2`). s26 read graphics 4684 / 4722 eff (38 failing), no-graphics
  4682 / 4722, pixels 592 / 637 (summed per-suite `image_results_graphics.json`). Re-read it yourself.
- **The local N session `n-trap-stroke` is running** (see below) and may have landed renderer changes and dispatched its
  own CI run(s) by the time you start. If `origin/ruffle-test-results` has a newer graphics commit than `df7729df2`, use
  the newest one whose run POSTDATES the last code commit (memory `ci-baseline-commit-must-postdate-its-run`), or run a
  wave-0 graphics/full/images run yourself.
- **Upstream drift** `3e98d9ba6..origin/master` in `~/CC/ruffle` (14 commits at handoff; 4 touch `tests/`):
  - `5128d3943` Flash Player reference for `avm2/pixelbender_dithering` (we are 34301 vs limit 32500 — the first real
    Flash oracle for the PixelBender CPU path; the s26 −1 pixel).
  - `7facc1fcc` Flash Player reference for `bitmapdata-clone`.
  - `d87764213` JPEG reference tests re-rendered at high quality (moved none of our rows at s26's last run, but the mirror
    has NOT been re-synced — it may once synced).
  - `bc2d4aedc` / `50f28249e` SharedObject.getLocal under `allowNetworking` (new test + AVM2 behaviour).
  Fund one drift slot, and run `git -C ~/CC/ruffle fetch` again at launch in case more has landed.

## Wave-1 slate (suggested, from the boards; attack and resize as you see fit)

- **drift** (above), including the corpus mirror re-sync and pricing `pixelbender_dithering` against its Flash golden;
- **pixels, applyFilter/draw tail** (playbook §25): GPU display-filter blur vs the Flash model (`blur_box_kernel`),
  `bitmapdata_drawwithquality` (3152/3197), AVM1 `applyFilter`/`draw()` beyond CM, the ≥20-entry Convolution misread as
  CM (XS), ColorMatrix leftovers (live CM under a placement cxform, alpha-bias folding, folded CM surviving `filters=[]`);
- **pixels, text and glyphs**: native renderer never soft-wraps `wordWrap` fields (possibly a large family, M–L — price
  first), EditText glyph compose rounding for scaled fields, DefineText matrix fidelity in the recompiler (M), the AVM2
  static-text / `avm2_render_textbox` cx twins, `draw()` of a tinted EditText;
- **pixels, render/bitmap leads**: holder Drawing-API content painting over attached children (S–M), per-movie static
  bitmap bases for loaded children, aliased AVM1 `draw()` Drawing-API paths, `shader_as_mask` 366 (alpha-mask rounding,
  blendShader node with mask/filters/scrollRect);
- **trace, per-movie DL phase 3** (arc §27.4; `ng_rootDisplayList()` accessor, M, fixture first) plus the loaded-shell
  remainder;
- **trace, browser AVM1 gaps**: `createTextField`/`getInstanceAtDepth` no-op `#else` arms (teach `gate_inventory.py` to see
  no-op arms), `getRGB` (S), `getBounds` (M) — browser-only, so it needs the Pages deploy;
- **trace, AVM1 leftovers + timers + robustness tail** (arc §27.4: DefineButton pick merge, path-variable scope,
  `__resolve` through dotted paths, `setNewTextFormat` size/font, Cut/Copy selection, timer goto-skipped DoInitAction,
  func2 register reads past RegisterCount, remaining fixed caps);
- **exec order** verification slot: the unverified `swf.c` vs `swf_core.c` dynamic-MC eligibility ordering (§27.4).
- **Oracle-gated holds** (Flash captures for `avm2_applyfilter_glow_kernels`, `avm2_bitmapdata_draw_filtered`, N3
  `probes/n3_layer_alpha.swf`, `bitmapdata_applyfilter_blur`; a current Ruffle runner for the loaded-shell fixtures): you
  cannot produce Flash captures yourself — list them for Robert in closeout rather than funding slots against them.

## Landing and grading recipes (arc §26.3 / §27.3)

- **Land:** `git show branch:<patch> > p`, then `git apply --check`, `git apply`, `git apply --check -R`. Spot-check the
  headline rows locally under the lock. `git checkout branch -- <report, patch, probe files>`. Commit by name with the
  harness trailer, then push. Measured, sweep-clean wave-1 prototypes land directly.
- `render_canary_tests.txt` conflicts are append-only: `--exclude` it and append the branch's `+` lines.
- The partial clone blocks `git apply --3way`. Use `git merge-file` against `git merge-base branch HEAD`.
- **Two patches that pass alone can break each other.** Re-run BOTH patches' fixtures after the second lands.
- **The working tree is shared with the local N session.** When it has uncommitted edits in a file you're landing, use
  `git apply --cached` plus a worktree apply, commit the index only, and confirm its residual diff is byte-identical.
- **Grade:** merge `origin/ruffle-test-results` after every run. Then `python3 scripts/corpus_status_diff.py <old> <new>
  --stem results_graphics`, `coord-tools/status_moves.py <old> <new>`, `python3 scripts/image_status_diff.py <old> <new>`.
  Check every move by name against the ledgers.
- **A shard that fails in setup (apt-get) publishes `metadata.incomplete=true` results** — `gh run rerun <id> --failed`
  and grade the re-published commit, never the incomplete one (s26).
- **Final-run regressions get bisected and fixed, then a confirming pair** (s26 needed one: root-last × `_droptarget`).
- Fixture goldens must come from an oracle outside SWFRecomp (memory `ruffle-exporter-oracle-limits`). Run the workers'
  LOCAL ORACLE REQUESTS yourself between waves and archive outputs under `session27-fanout-reports/`.
- GitHub API limit is 5000/h: poll runs at 120–180 s, one `gh run watch` at a time.

## The parallel N ladder (adopt it)

`n-trap-stroke` was launched by the s26 coordinator at closeout (brief
`SWFRecompDocs/plans/session26-fanout-reports/n-trap-stroke-prompt.md`: L1 trap-switch 1-px stroke coverage, then the
exit-door panel offset). The s26 coordinator has ended, so its REPORT BACK will have nowhere to go. **At startup, send
`n-trap-stroke` a handshake** saying you are the s27 coordinator, that it should send its REPORT BACK to you, message you
before touching `tag.c`/`action.c`/`ng_shared.c`/`swf.c`, and **coordinate CI with you** (you fold its CI-observable SHA
into your next grading run instead of it dispatching a separate run that lands between your baseline and your interims).
If it already dispatched a run, grade it as a wave-0. Verify its REPORT BACK against disk, then launch the next slice its
report names (self-advancing ladder; launch with
`PATH="$PATH:/mnt/c/Windows/System32:/mnt/c/Windows" ~/bin/wsl-launch-claude.sh -m opus -C /home/robert/CC/SWFRecomp-CC -d : -t <slug> -f <brief>`,
verify `/proc/<pid>/cwd`, handshake), or stop if the machine is short on memory. At closeout, if a slice is still running,
leave the next coordinator a note in your memory update.

## Done

- Final grading in both modes, ledger-exact by name, with 0 regressions (or each one named and explained).
- Closeout docs: `polish-sweep-arc.md` §28 (ledger, verdicts that fell, method notes, "Left on the board (session 28)") and
  `graphics-fanout-playbook.md` §26.
- Memory `next-session-dual-axis-fanout` updated (s27 record + s28 boards).
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
