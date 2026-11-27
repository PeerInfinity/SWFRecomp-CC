# Session 30 coordinator: corpus fan-out (dual-axis #22), cloud-first, Flash over Ruffle

You are a NEW session: the **coordinator** of fan-out session 30 in `/home/robert/CC/SWFRecomp-CC`. You own s30 end to
end: wave 1 → wave 2 → grading → closeout. Nobody else coordinates it. The s29 coordinator wrote this brief at Robert's
request, relayed by the s28 coordinator (2026-11-27), then revised after the s28 coordinator's review and a pre-launch
FLASH ORACLE PASS (`session30-fanout-reports/pre-launch-oracles/README.md`: read it before writing wave-1 briefs).

**Project state first:** read `SWFRecompDocs/plans/PROJECT_STATE.md` (where the project stands, the ranked "Worth
doing" list in §2, every non-corpus track) and `SWFRecompDocs/plans/NO_GO_REGISTER.md` (every standing NO-GO with its
reopen criterion, the verdicts that fell, and the UNSURE items left in §4: the pre-launch pass resolved two of the three). Update both at your closeout.

## Standing directives (all from Robert; memories hold the detail)

- **Cloud-first, Opus for everything** (memory `next-session-dual-axis-fanout`).
  - Every diagnosis and implementation slot is a cloud session in env "SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`).
  - Launch each with `scripts/fanout_cloud_worker.sh <slug> <prompt>`; it delivers ONLY on `fanout/<slug>`.
  - You stay local for merges, CI, results accounting and the oracles.
- **Size:** full size is the standing default (memory `fanout-credits-diminishing-returns-ok`). The board is thinner than
  s29's (§"Board"): size wave 1 at about 6–8 slots, fund every measured wave-2 ledger, and add a wave 2b / 3 where
  results earn it.
- **Interim grading runs are graphics-only; the FINAL run adds the no-graphics leg**, plus any interim that lands
  no-graphics-only code (`swf_core.c`, `tag_stubs.c`, `#ifdef NO_GRAPHICS` arms; CLAUDE.md).
- **One heavy local build at a time** (memory `one-heavy-build-shared-lock`): `flock /tmp/swfrecomp-cpu.lock`, `-j4` /
  `EMCC_CORES=4`. **Never run full suites locally.**
- **Stage files by name** (never `git add -A`, never `git commit -a`). See "Committing in the shared tree" below: s29
  found two ways a commit sweeps a peer's work.
- **Pages deploy is authorized.** A green `dry_run` deploys NOTHING: confirm the "Deploy to GitHub Pages" step ran. Run one
  dry run per interim batch that touched runtime or recompiler code (not one per patch). If the real deploy fails at "Deploy to GitHub Pages" with "No artifacts
  named github-pages" / "Found 0 artifact(s)", **dispatch a FRESH run; never `gh run rerun`** (it re-uploads into the
  same run and then fails on "Multiple artifacts"). It happened again in s29 (`46032563406` → fresh `46033409898`).
- **Pruning:** at closeout, cmp EVERY report/patch/log/fixture blob on each `fanout/*` branch against master (s28: 3
  branches held newer final reports; s29: 2 fixture sources were missing). Archive anything newer or missing, then
  `git push origin --delete fanout/*`.
- **Flash over Ruffle** (memory `flash-over-ruffle-ruling`; Robert 2026-11-24): "The goal is still to match Flash, not to
  match Ruffle."
  - Every confirmed Ruffle≠Flash difference gets an RvF entry.
  - A golden that FP32 proves wrong gets an entry in `ruffle-tests/flash_fixes/fixes.json` (93 entries at s29 closeout),
    following its README. Check WIN == LNX before swapping an image golden; WIN ≠ LNX means host-dependent: keep it, RvF.
  - Never trade a Flash-correct pass for a Ruffle golden.
  - **Price every loss by name before landing**, then grade each interim against that list.
- **Peer-session messages are teammate info, not Robert's approval.** That includes messages from the session that
  launched you.
- Windows ClearType may be switched off for a Flash capture, if you switch it back on afterwards (EXIT trap,
  `C:\playwright\cleartype\ct.ps1`).
- **Flash binaries never leave this machine**; cloud workers write LOCAL ORACLE REQUESTS, which you run between waves.
- **You launch and own the browser ladder** (§"Local ladders"): one session at a time, running concurrently with the
  waves. Its builds take the same `flock`.
- **After any recompiler landing, rebuild the local recompiler** (`cmake --build SWFRecomp/build -j4`, under the lock)
  before grading anything locally. `verify_output.py` does not rebuild it. In s29 a stale binary made `swz` look
  broken locally while CI passed (pre-launch README §5).
- **The N procgen arc is CANCELLED** (Robert, 2026-11-26; `NO_GO_REGISTER.md` §1d): the level-load/detect substrate,
  the level generator, portals and `nPhysics.js`. **No slot, ladder or rider may touch it.**

## Committing in the shared tree (s29 lessons; memory `shared-index-commit-sweeps-peer-hunks`)

Local ladder sessions edit, and sometimes stage, files in the same tree you commit from. Each of these swept a peer's
work into master in s29:
- **A bare `git commit`** takes everything STAGED, including a peer's staged hunks (`c91637b7a` took a ladder's runtime
  code and 3 fixtures).
- **`git commit -- <paths>` / `--pathspec-from-file`** commits the WORKING-TREE content of those paths, including a
  peer's UNSTAGED edits (`6a27fc2e0` took 21 uncommitted `tag.c` lines whose header was not committed, so HEAD would
  not build; fixed in `fec84dcea`). **Do not use pathspec commits** on any path a peer has dirty.

Recipe:
1. Before you start, run `git status --short` and `git diff --cached --name-only`. Know what peers have dirty or staged.
2. Stage your exact content. For a file a peer has dirty, use `git apply --cached P`, plus `git apply P` so their copy
   gets your hunk too. Or build the blob and stage it with `git hash-object -w` + `git update-index --cacheinfo`. Plain
   `git add` is only for files no peer has touched.
3. Check `git diff --cached --name-only` against your list.
4. Plain `git commit` (index only).
5. `coord-tools/land_branch.sh <branch> <scratch>` (in `session29-fanout-reports/coord-tools/`) refuses peer-dirty
   files; route those through step 2.

**Binary files never go through `git merge-file`.** In s29 it emptied a flash_fix PNG (`text_field_mask`; interim #3
read open_failed; restored in `92908280c`). `land_branch.sh` copies binaries (`grep -qI .` test), unions `fixes.json`
as JSON by (test, file), and 3-way merges only text. After a landing, `git add -f` the `.swf` fixtures (gitignored) and
check that every committed binary is non-empty.

## The Flash oracle (memory `flash-player-oracle`)

`tools/flash-oracle/` (`run_trace.py`, `run_image.py`) drives Flash Player 32, locally only. It is the first-choice
oracle; the Ruffle exporter is a fallback. AVM1 runs DIRECT, pinned 1:1; non-LAYER blends need `--screen`.
- **Old-stub trap:** any pinned AVM1 quality=low capture from before 2026-11-25 is really HIGH. Re-capture it.
- **Timers are nondeterministic in Flash** in tie/catch-up cases; grade with a bound check over several captures.
- **AVM2 for-in order is nondeterministic in FP32** (hash-scattered, differs between runs). Never fit a model to one
  capture of it.
- Run at most 4 parallel Linux runs. Use `--log-warnings` when the golden has `Warning:` lines.
- mxmlc needs `-target-player=11.1 -omit-trace-statements=false`. MTASC:
  `~/CC/mtasc/bin/mtasc -cp ~/CC/mtasc/ocaml/mtasc/std -main -header 200:150:30 Test.as -swf test.swf -version N`.
- s29 Flash models to know before any pixel slot (playbook §28):
  - **HIGH coverage:** 4 sub-scanlines per row at y + j/4 × exact x coverage, quantised to 1/16. Colour is
    `out = floor((dst·(16−n) + c·n)/16)`. Vertices sit on the ¼-px grid. This is NOT 4×4 SSAA.
  - **LOW TSNAP:** translation snapped per display-list level, ties to even; not applied inside cached/filtered
    subtrees, or to text.
  - **LOW stroke raster:** width on the ¼ grid; thin pen n = min(W, 4) below 5.5 px; axis-band rule; a 1-px noScale
    hairline is stroked at the unsnapped translation.
- Copy the oracle-traps section of `session29-fanout-reports/BRIEFS_COMMON.md` into yours.

## Read first

1. `SWFRecompDocs/plans/PROJECT_STATE.md` and `NO_GO_REGISTER.md`.
2. Memories: `next-session-dual-axis-fanout` (s29 record), `shared-index-commit-sweeps-peer-hunks`,
   `flash-over-ruffle-ruling`, `flash-player-oracle`, `parallel-fanout-wave-pattern`, `graphics-fanout-playbook`,
   `ci-baseline-must-be-read-fresh`, `corpus-status-diff-tool`, `lowq-sample-point-model-status`,
   `browser-attached-timeline-shared-pump`, `browser-wasm-gate-inventory`, `ruffle-matched-is-not-flash-pass`.
3. `SWFRecompDocs/plans/polish-sweep-arc.md` **§30**: §30.3 method notes and the §30.4 trace board.
4. `SWFRecompDocs/plans/graphics-fanout-playbook.md` **§28**: the models table, the flash_fixes table and the pixel
   board.
5. The s29 run of record as your TEMPLATE: `SWFRecompDocs/plans/session29-fanout-reports/`. Copy the shape of
   `BRIEFS_COMMON.md`, `briefs/` (with `_w1_header.txt` / `_w2_header.txt`), `prompts/`, `AGENT_LAUNCH_ORDER.md`
   and `SIBLING_FILE_MAP.md`. Copy `coord-tools/` and repoint `watch_reports.sh` at session30.
6. Tools: `coord-tools/allrows.py <ref> results_graphics|results`, `status_moves.py`, `status_moves_ng.py`,
   `land_branch.sh`, `watch_reports.sh` (launch with `run_in_background`, not nohup), `scripts/image_status_diff.py
   --band-floor 0 --max-list 300`, and `python3 ruffle-tests/apply_flash_fixes.py --check` (run it in the MAIN tree).

## Baseline (verify before quoting; no new baseline run needed)

- **Graphics trace + pixels: the s29 FINAL run `45938113471` at `2d40d3799`, results `51ab63688`.**
  - Trace: 4860 eff / 4893 (4704 pass + 156 rm, 33 failing).
  - Pixels: 552 pass / 140 fail (+6 ignored, 3 skip; 701 comparisons).
  - Everything committed after `2d40d3799` is docs or results only, up to the commit of this brief.
- **No-graphics: run `45938116102`, results `63bcc2dd8`.** 4858 eff. The mode diffs are only `audio/aac` and
  `avm2/audio_computespectrum`.
- **Known flake:** `from_shumway/as3-loader/bug1157243/empty` sometimes gives empty output (graphics). Graded as a
  flake twice in s29.
- **Upstream drift:** fetch `~/CC/ruffle` at launch and diff it against the s29 download. CI downloads upstream master
  on every run, so new rows simply appear in your first run: grade them by name. Read the `flash-fix` lines in the CI
  download log; that is the STALE/UPSTREAMED check of the 93 entries.

## Board (ranked; sizes are the s29 coordinator's estimates; detail in arc §30.4, playbook §28, PROJECT_STATE §2)

**Trace** (33 failing + 156 rm; about 110 of the rm rows have FLASH goldens and are real gaps):
1. **w1-drift (S, one slot):** upstream since the s29 download, plus the flash_fixes STALE/UPSTREAMED check.
2. **Native-object table from the FP32 golden (L; diagnosis first).** One shared mechanism owns:
   - `global_proto_decls`, `global_proto_decls_delete`, `global_instance_decls`;
   - gnash `argstest-v6/7/8`;
   - the ExternalInterface-v8 rest (s29 refuted its "S" half).

   The goldens ARE Flash (s29 w1-disposition-audit). **Coordinator: run the FP32 captures BEFORE launching wave 1**
   (per class: members, attributes, enumeration order, for the 3 `global_*_decls`, `argstest-v6/7/8` and EI-v8), so
   the wave-1 DIAGNOSIS slot builds and prices the table from real data instead of filing a LOCAL ORACLE REQUEST and
   waiting a wave. Implementation is wave 2. Nobody edits `setupNativeFuncOwnProps` before the table is priced.
3. **Exec order, the remaining halves (M–L).** `078350610` made natural-advance frame scripts ONE list, newest
   place_seq first, `_root` last (kill switch `SWF_EXEC_ORDER_MERGED=0`). Still open:
   - enterFrame before the clip's own script;
   - the clip-event merge (n-exec-order §2b reqs 1 and 3).

   The family is gnash `ActionOrderTest3/4/5`, `PlaceAndRemove`, `action_execution_order_extend_test`, `_test4` and
   `_test11`. `_test11` already moved Flash-ward (10 → 8 diff lines), so it is the probe. The NO_GO action_order row's
   reopen criterion is now partly met. **Fund it in wave 1 as an IMPLEMENTATION slot, in parallel with item 2** (separate
   mechanisms; s28 coordinator review). Probe `_test11`; A/B with the `SWF_EXEC_ORDER_MERGED` kill switch over the
   action-order + timeline rows. **Grade the browser build too, via child_probe**: `078350610` came from the browser
   ladder and exec order touches every build. In `SIBLING_FILE_MAP.md`, mark this slot and ladder item 1
   (`browser-attach-child-early`) as file-adjacent (frame loops in `swf.c`/`swf_core.c`, `tag_stubs.c`
   `ng_attachMovie`, `action_queue.c`), and land them one at a time.
4. **ruffle_matched pool (M per slot, split by VM;** memory `triage-bucket-by-vm-not-symptom`). These are the
   s28 w1b "priced, not worked" buckets (`session28-fanout-reports/w1b-rm-*-report.md`; NO_GO §1a), each with a
   completion cell. Re-price against FP32 before funding. Candidates: AVM2 frame/event lifecycle, the device-font
   metrics family, typed nulls, `avm1movie`, the FTE line model.
5. **Small trace leads (S each; mostly coordinator FP32 runs):**
   - **`movieclip_hittest_shapeflag`: GRADED pre-launch, NO_GO §4.8 resolved** (pre-launch README §1). Golden == FP32.
     Lines 171–177 stay ACCEPTED (device-font outlines). Two real gaps remain: line 71 (`layers` shape geometry, S–M)
     and line 296 (morph boundary: FP32 `false` like Ruffle's integer-twip path; ours `true`; S). Fixing both does not
     flip the row (171–177 remain), so price it as a lead, not a flip.
   - TextField `tabIndex = null`: we still coerce to 0. Clips and buttons already unset (FP32, `2d40d3799`). Needs an
     FP32 text-field capture (w3 report's LOCAL ORACLE REQUEST).
   - The #2044 unhandled ErrorEvent path for `avm2/html_text_img_parsing`. Check its platform-split NO-GO row first.

**Pixels** (130 of the 140 failing rows are quality=LOW):

6. **LOW residues (M).**
   - The LOW fill .5-vertex tie: `regression/lowq_tsnap_tie_probe` rows 4–5, budget 3152 (45° stroke width, the 3-px
     rect band, drawRect .5).
   - `acid-large`: **CAPTURED pre-launch, swap-ready** (README §2): WIN == LNX byte-identical; ours→FP32 138 478 vs
     golden→FP32 178 720. Add the flash_fixes entry in your first landing batch and ledger it (it stays a fail, honestly).
   - `avm2_layer_group_alpha` / `_erase`: **GRADED pre-launch** (README §4): WIN == LNX; TSNAP's move was Flash-ward
     (t2: 81 986 vs golden 89 617; erase 79 910 vs 88 046). Re-golden both OUR fixtures to the FP32 LOW captures
     (`session29-fanout-reports/w1-local-oracles/w2-lowq-tsnap/regression__avm2_layer_group_*.low.png`) and price the
     remaining ~80 k gap (layer-group compositing at LOW) as its own lead.
   - Re-grade `sprite_with_frames` against FP32 LOW now that the stroke raster is in.
7. **`acid-shapes` (M): CAPTURED pre-launch** (README §3; LNX == WIN == golden). It fails only t16 (+85) and t32
   (+88), and that excess is edge-only AA. The t128 geometry residue is 146 px on the thick curved strokes' outer
   edges, where FP32 paints stroke colour and we leave background. Neither fix alone flips it: the row needs the
   curved-stroke edge geometry AND the faithful HIGH AA rule. That is the AA NO-GO's reopen criterion (NO_GO §1b).
   Fund the geometry half first, graded with w1-aa-sizing's `scan_run.py -DSSAA_PROBE -DSSAA_VSNAP` leg.
8. **Real Flash gaps with Flash goldens (M):**
   - `place_object_test` (2604);
   - `acid-stroke-0` (3413);
   - `morph_test1` ×6: the LOW glyph rule, the only real Flash losses of the glyph snap.

   `shape_test` (9709) is open-fill parity: NO-GO L, so do not fund it without a new lever.
9. **Strokes (S–M):**
   - The AVM2 twin of the w3 seam-join gate (`avm2_display.c` `gfx_build_stroke`). It needs an on-screen scale at
     build time.
   - Translucent-union slivers in `drawingUnionTris`: a vertex weld before `tessAddContour`, priced on the canary.

**Unchanged NO-GOs:** `NO_GO_REGISTER.md` §1. Reopen one only when its criterion is met.

## Local ladders (one task per session)

- **N ladder: PARKED at its stroke floor.** s29 `n-seam-caps` was N-neutral on ep1; the remaining residue is AA
  granularity, and Flash-exact HIGH AA is a measured NO-GO. **Reopen only with a NEW lever**: a measurement showing a
  mechanism other than AA owns N's remaining pixels, or the AA reopen criterion (item 7) being met. Do not launch an
  N slice by default.
- **N procgen: CANCELLED** (above). Not a ladder.
- **Browser ladder** (from `session29-fanout-reports/browser-attach-order-report.md` §5), in this order:
  1. **`browser-attach-child-early` (S).** The browser-only "force nested build" `advance_sprite_frames` in
     `ng_attachMovie` (`tag_stubs.c`) advances an already-built (eager-init) timeline child on the attach tick, so it
     runs one frame ahead. Gate or delete it so only unbuilt holders get it. Grade it with
     `regression/avm1_attach_timeline_frame_order` in child_probe and with Minesweeper's radio circle bounds. Ride-along:
     the spurious "Failed to place object at depth 1" warning on a same-char loop-back re-place.
  2. **`regression/avm1_nested_child_swapdepths_remove` (M).** This booked expected-fail is the one failing
     `regression/` row: a timeline child's swapDepths + removeMovieClip survives. The bug is in EVERY build, and the
     fixture came from this ladder (`c91637b7a`). It belongs here unless you fund it as a cloud slot. Either way it
     flips fail → pass in both modes, and nothing else may move. It is booked ONLY by its "OPEN DEFECT" row in
     `ruffle-tests/tests/swfs/regression/README.md` (no ignore entry, no `known_failure`). Rewrite that row in the same
     commit as the fix.
  3. **The timeline-sprite self-goto port §5a (M)**, plus deleting the dead `pending_remove` code. The oracle is
     `nested_sprite_inframe_goto` via child_probe.
- **How to run them:** launch with
  `PATH="$PATH:/mnt/c/Windows/System32:/mnt/c/Windows" ~/bin/wsl-launch-claude.sh -m opus -C /home/robert/CC/SWFRecomp-CC -d : -t <slug> -f <brief>`,
  verify `/proc/<pid>/cwd`, and send a handshake.
  - Write each brief from the previous report's "next" section, and include the shared-tree commit recipe above.
  - Verify each REPORT BACK on disk (commit present, pushed, report file exists) before launching the successor.
  - Grade new browser fixtures natively in both modes first. Every browser link must pass `-Wl,--fatal-warnings`.

## Landing and grading recipes (arc §29.3 / §30.3)

- **Land:**
  - Run `git apply --check`, `git apply`, then `git apply --check -R` (or `land_branch.sh`).
  - Append-only files (canary list, regression README, RvF, `fixes.json`) are appended by script.
  - For conflicts, use `git merge-file` against the merge-base; the partial clone blocks `--3way`. **Text only.**
  - Commit per "Committing in the shared tree".
- **Grade:**
  - Merge `origin/ruffle-test-results` after every run.
  - Run `allrows.py` and diff by name against the previous run; run `image_status_diff.py`.
  - Check every move against the ledgers. Grade unlisted band moves against fresh FP32 captures and archive the table.
  - CI outlier counts can be below a worker's local prediction: grade the name and the direction.
- **Watching runs:** poll `gh run view --json status` in a background loop; never kill a peer's watcher.
- **Recovery:** a shard that fails in setup (s29: apt "Install system dependencies", twice in the FINAL pair) publishes
  partial results first; the partial diff shows hundreds of `pass → None` rows. Run `gh run rerun --failed` and grade
  only the republished commit.

## Done (closeout checklist)

- **Final grading** in both modes, ledger-exact by name, with 0 regressions or each one explained AGAINST FP32.
- **State docs:**
  - `PROJECT_STATE.md`: numbers, the §1 per-suite table, the trajectory row, "Worth doing", the §4 track rows and the
    summary table.
  - `NO_GO_REGISTER.md`: new verdicts, refuted ones moved to §2, UNSURE items resolved, statuses line repointed to your
    FINAL.
- **Arc and playbook:**
  - `polish-sweep-arc.md` **§31**: ledger, verdicts that fell, method notes, "Left on the board (session 31)".
  - `graphics-fanout-playbook.md` **§29**: models table, flash_fixes table with STALE/UPSTREAMED, board.
- **Memory:** update `next-session-dual-axis-fanout` (s30 record + s31 boards) and any model memory you moved
  (`lowq-sample-point-model-status`, `browser-attached-timeline-shared-pump`, …).
- **Branches:** `fanout/*` pruned after the full blob cmp.
- **Pages:** a REAL deploy (Deploy step ran) if the wasm/runtime/recompiler changed.

REPORT BACK (after the durable records — never instead of them): once the closeout docs are written, memory updated,
and the commits pushed, reply to the handshake message from the session that launched you (copy its `from` attribute as
your SendMessage `to`). That is the s28 coordinator or whoever launches s30. If no handshake arrived, run ListAgents and
look for the launching session; if it is not reachable, skip silently: the closeout docs are the record and need no
reader. Send ONLY the deltas: what s30 overturned in this brief (by §), defects your own tests found, anything that
changes standing plans or docs, and the s31 line.
