# Session 29 coordinator: corpus fan-out (dual-axis #21), cloud-first, Flash over Ruffle

You are a NEW session: the **coordinator** of fan-out session 29 in `/home/robert/CC/SWFRecomp-CC`. You own s29 end to
end: wave 1 → wave 2 → grading → closeout. Nobody else coordinates it. The s28 coordinator wrote this brief at Robert's
request (2026-11-26).

**Project state first:** read `SWFRecompDocs/plans/PROJECT_STATE.md` (where the project stands, what is still
worth doing, every non-corpus track) and `SWFRecompDocs/plans/NO_GO_REGISTER.md` (every standing NO-GO with its
reopen criterion, the verdicts that fell, and 12 UNSURE items). Update both at your closeout.

## Standing directives (all from Robert; memories hold the detail)

- **Cloud-first, Opus for everything** (memory `next-session-dual-axis-fanout`).
  - Every diagnosis and implementation slot is a cloud session in env "SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`).
  - Launch each with `scripts/fanout_cloud_worker.sh <slug> <prompt>`; it delivers ONLY on `fanout/<slug>`.
  - You stay local for merges, CI, results accounting and the oracles.
- **Size:** full size is the standing default (memory `fanout-credits-diminishing-returns-ok`), but the trace board is
  thin now (§"Board" below). Size wave 1 at about 7–9 slots, fund every measured wave-2 ledger, and add a wave 2b / 3
  where results earn it.
- **No-graphics leg on the FINAL grading run only**, plus any interim that lands no-graphics-only code (CLAUDE.md).
- **One heavy local build at a time** (memory `one-heavy-build-shared-lock`): `flock /tmp/swfrecomp-cpu.lock`, `-j4` /
  `EMCC_CORES=4`. Never run full suites locally.
- **Pages deploy is authorized.** A green `dry_run` deploys NOTHING: confirm the "Deploy to GitHub Pages" step ran. Run a
  dry run on every runtime/recompiler landing. **s28 lesson:** if the real deploy fails at "Deploy to GitHub Pages" with
  "No artifacts named github-pages", dispatch a FRESH run. `gh run rerun --failed` re-uploads into the same run and then
  fails on "Multiple artifacts".
- **Pruning:** at closeout, cmp EVERY report/patch/log blob on each `fanout/*` branch against master (not just the names:
  in s28, 3 branches held final reports newer than master's interim copies). Archive anything newer or missing, then
  `git push origin --delete fanout/*`.
- **Flash over Ruffle** (memory `flash-over-ruffle-ruling`; Robert 2026-11-24): "The goal is still to match Flash, not to
  match Ruffle."
  - Every confirmed Ruffle≠Flash difference gets an RvF entry.
  - A golden that FP32 proves wrong gets an entry in `ruffle-tests/flash_fixes/fixes.json` (62 entries at s28 closeout),
    following its README.
  - Never trade a Flash-correct pass for a Ruffle golden.
  - A Flash model may lose Ruffle-golden rows: **price every loss by name before landing**, then grade the interim
    against that list (s28: interim #6 = the lowq §6 ledger exactly).
- Peer-session messages are teammate info, not Robert's approval.
- Windows ClearType may be switched off for a Flash capture, if you switch it back on afterwards (EXIT trap,
  `C:\playwright\cleartype\ct.ps1`).
- Flash binaries never leave this machine; cloud workers write LOCAL ORACLE REQUESTS, which you run between waves.

## The Flash oracle (memory `flash-player-oracle`; read its s28 lines)

`tools/flash-oracle/` (`run_trace.py`, `run_image.py`) drives Flash Player 32, locally only. It is the first-choice
oracle; the Ruffle exporter is a fallback. AVM1 runs DIRECT, pinned 1:1; non-LAYER blends need `--screen`.
- **Old-stub trap:** any pinned AVM1 quality=low capture from before 2026-11-25 is really HIGH. Re-capture before you
  trust it.
- **Timers are nondeterministic in Flash** in tie/catch-up cases. Take several captures and grade with a bound check.
- Run at most 4 parallel Linux runs (at 8, the pin never releases). Use `--log-warnings` when the golden has `Warning:`
  lines.
- Copy the "A REAL FLASH ORACLE EXISTS" section of `session28-fanout-reports/BRIEFS_COMMON.md` into yours.

## Read first

1. `SWFRecompDocs/plans/PROJECT_STATE.md`.
2. Memories: `next-session-dual-axis-fanout` (s28 record), `flash-over-ruffle-ruling`, `flash-player-oracle`,
   `parallel-fanout-wave-pattern`, `graphics-fanout-playbook`, `ci-baseline-must-be-read-fresh`,
   `corpus-status-diff-tool`, `lowq-sample-point-model-status`, `n-play-game-click`, `browser-wasm-gate-inventory`.
3. `SWFRecompDocs/plans/polish-sweep-arc.md` **§29**: §29.3 method notes and the §29.4 trace board.
4. `SWFRecompDocs/plans/graphics-fanout-playbook.md` **§27**: the pixel board, the priced-loss table, and the
   flash_fixes table.
5. The s28 run of record as your TEMPLATE: `SWFRecompDocs/plans/session28-fanout-reports/`. Copy the shape of
   `BRIEFS_COMMON.md`, `briefs/`, `prompts/`, `AGENT_LAUNCH_ORDER.md` and `SIBLING_FILE_MAP.md`.
6. Tools: `session28-fanout-reports/coord-tools/` (`allrows.py <ref> results_graphics`, `status_moves.py`,
   `status_moves_ng.py`, `watch_reports.sh`), `scripts/image_status_diff.py --band-floor 0 --max-list 300`, and
   `python3 ruffle-tests/apply_flash_fixes.py --check`. Run the check in the MAIN tree: a worktree without upstream
   downloads reads MISSING.

## Baseline (verify before quoting; no new baseline run needed)

- **Graphics trace + pixels: the s28 FINAL run `45878805896` at `bfa47037b`, results `014124ed5`.** 4827 eff / 4864
  (4642 pass + 185 rm, 37 failing). Pixels: 545 pass / 140 fail (+6 ignored, 3 skip). Everything committed after
  `bfa47037b` (`c6bb04c84`, `9c4cb4010`, `6ec94a16f`) is docs or results only.
- **No-graphics: run `45878818309`, results `336b83183`.** 4825 eff.
- **Upstream drift since that run's download** (checked 2026-11-26; fetch `~/CC/ruffle` again at launch):
  - `aa850487d` + `31e07df77`: new row `avm2/bitmapdata_palettemap_opaque`.
  - `745653790` + `e7e02dbec`: new row `avm1/bitmapdata_palettemap_values`. Upstream also drops `known_failure` and the
    954-line `output.ruffle.txt` from `avm1/bitmap_data_thorough/paletteMap`, which we already pass.
  - `9c6ab4945` is a Rust-only JPEG test (no corpus row).
  - The local `~/CC/ruffle` is at `0ddd12b6a` (the exporter build). CI downloads upstream master on every run, so new
    rows simply appear in your first run: grade them by name.
- **The first run after the download is the first real STALE/UPSTREAMED check of the 62 flash_fixes.** Read the
  `flash-fix` lines in the CI download log. Re-derive any STALE entry against Flash; delete any UPSTREAMED one.

## Board (attack and resize as you see fit; detail in arc §29.4 and playbook §27)

**Trace** (37 failing + 185 `ruffle_matched`. trace-provenance found most rm rows have FLASH goldens, so rm rows are
real gaps unless a disposition says otherwise):
- **drift** (one slot): the 2 paletteMap rows and whatever else lands upstream before launch.
- **disposition audit** (S; mostly coordinator-local FP32 runs plus one cloud slot to write it up and fix what turns
  cheap): the 12 UNSURE items in `NO_GO_REGISTER.md` §4. These are dispositions that s28's own FP32 evidence
  contradicts. Strongest leads:
  - `swz` / `loader_applicationDomain`: FP32 throws a securityError (`trace-provenance.md`), so "AOT ceiling" is the
    wrong target.
  - `native_objects_swf6` and `tab_ordering_…_edge_case`: their goldens are Flash, yet they are ACCEPTED.
  - `dependent_strings`: we may already be FP32-exact.
  - `globals_swf5`: the trade may invert under Flash-over-Ruffle.
  - Also prune the stale ACCEPTED_DIFFS rows that now pass (`netstream_play_flv`, `deblocking`; `h263` is at 3
    outliers).
- **timers tail:**
  - `regression/avm1_timer_clock_model`: Flash gives cnt 10–12 over 3 runs, not the analytic 16–18. Refit it or turn
    it into a bound check.
  - The AVM1 timer check after enterFrame needs an FP32 fixture (local oracle request).
  - gnash `gotoFrameFromInterval{,2}` are still rm against Flash goldens.
- **goto/nav:**
  - `actionNextFrame`'s `g_inside_enterframe_dispatch` arm may be stale, like the GotoFrame one `4a25debc9` removed.
  - A gotoAndStop(current) Flash fixture: the browser-only stop guard vs the CI same-frame branch.
- **ruffle_matched pool:** the remaining w1b NO-GO buckets (`session28-fanout-reports/w1b-rm-*-report.md`) and the AVM2
  text-layout bucket. Re-price each against FP32 before funding it. Split by VM (memory
  `triage-bucket-by-vm-not-symptom`).
- **leads:**
  - `movieclip_hittest_shapeflag`: it is still a mismatch after its flash_fix; check the 3 Flash-`false` lines against
    our ACCEPTED lines.
  - A Date TZ harness override (harness, not runtime).
  - LocalConnection queue growth (held in s28).
- **Unchanged NO-GOs:** see `NO_GO_REGISTER.md` §1. Reopen one only when its criterion is met.

**Pixels** (playbook §27):
- **LOW model next slice:**
  - the .5-tie probe (`avm2_button_scroll_rect`);
  - the LOW stroke y rule (class c `drawing_order`, `masks{,_equal_clipdepth}`);
  - before any of them becomes a flash_fix, a coordinator-local Windows FP32 check of the swap candidates
    `invalidClipDepth`, `from_shumway/gradient`, `acid-gradient(-0)` and `acid-filter`.
- **AA mode sizing** (diagnosis only): Flash HIGH is 4×4 SSAA, our HIGH is MSAA. It is unmeasured; price which failing
  HIGH rows it would move before anyone builds anything.
- **Text:**
  - `rotated_glyphs` (1111 px vs Flash);
  - the wordwrap fixture's interim Ruffle golden;
  - the 22 unpriced glyph-snap Ruffle-golden losses from w1-text-glyph-aa;
  - 16-level glyph AA (NO-GO L of record).
- **Filters:** the bevel HOLD probe (captured in s28) and `shadow_shape_a50` (768 px).
- **Real Flash gaps, not swap candidates:** `place_object_test` (5073) and `shape_test` (10300). Their goldens ARE Flash
  at LOW.
- `acid-shapes`: the only Flash-golden row that got worse in s28 (+0.25%, thick curved strokes).

## Local ladders (one task per session; adopt them)

- **N ladder** (head, from `SWFRecompDocs/plans/n-join-disc-report.md`): emit a closed stroke seam as two caps in
  builders/lyon. The first cut opened holes, so price it on the n-join-disc ledger. Then the LOW stroke raster.
- **Browser ladder** (head, from `session28-fanout-reports/browser-attached-goto-report.md`):
  - the §5a timeline-sprite self-goto port (M; it broke nested gotos on the s28 HEAD);
  - the gotoAndStop(current) fixture (shared with the trace slot above: pick one owner);
  - the Doodle Jump browser busy-loop after PLAY (pre-existing).
- **How to run them:** launch with
  `PATH="$PATH:/mnt/c/Windows/System32:/mnt/c/Windows" ~/bin/wsl-launch-claude.sh -m opus -C /home/robert/CC/SWFRecomp-CC -d : -t <slug> -f <brief>`,
  verify `/proc/<pid>/cwd`, and send a handshake. Write each brief from the previous report's "next" section. Verify
  each REPORT BACK on disk before launching the successor. Grade a new browser fixture natively in both modes first.
  Every browser link must pass `-Wl,--fatal-warnings`.

## Landing and grading recipes (arc §28.3 / §29.3)

- **Land:**
  - `git apply --check`, then `git apply`, then `git apply --check -R`.
  - Append-only files (canary list, regression README, RvF, `fixes.json`) are appended by script.
  - For conflicts, use `git merge-file` against the merge-base; the partial clone blocks `--3way`.
  - When peers have dirty files in the shared tree, build the commit in a scratch `git worktree` and fast-forward
    master with `git update-ref`.
- **Grade:**
  - Merge `origin/ruffle-test-results` after every run.
  - Run `allrows.py` and diff by name against the previous run, plus `image_status_diff.py`.
  - Check every move against the ledgers.
  - Grade unlisted band moves against fresh FP32 captures and archive the table (template:
    `session28-fanout-reports/w1-local-oracles/interim6-low/README.md`).
- **Watching runs:** another session's `gh run watch` makes the hook block new watchers. Poll
  `gh run view --json status` in a background loop; never kill a peer's watcher.
- **Recovery:** a shard that fails in setup publishes `incomplete=true` results: run `gh run rerun --failed`.

## Done

- **Final grading** in both modes, ledger-exact by name, with 0 regressions, or each one explained AGAINST FP32.
- **Closeout docs:**
  - `polish-sweep-arc.md` §30 (ledger, verdicts that fell, method notes, "Left on the board (session 30)");
  - `graphics-fanout-playbook.md` §28 (with the flash_fixes table and any STALE/UPSTREAMED entries);
  - `PROJECT_STATE.md`: update the numbers and "Worth doing".
  - `NO_GO_REGISTER.md`: add new verdicts, move refuted ones to §2, and resolve the UNSURE items you settled.
- **Memory:** update `next-session-dual-axis-fanout` (s29 record + s30 boards).
- **Branches:** `fanout/*` pruned after the full blob cmp.
- **Pages:** a REAL deploy if the wasm/recompiler changed.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
