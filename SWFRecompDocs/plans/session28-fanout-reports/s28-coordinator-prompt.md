# Session 28 coordinator: corpus fan-out (dual-axis #20), cloud-first, full size, Flash first

You are a NEW session: the **coordinator** of fan-out session 28 in `/home/robert/CC/SWFRecomp-CC`. You own s28 end to
end: wave 1 → wave 2 → grading → closeout. Nobody else coordinates it. The s27 coordinator wrote this brief at Robert's
request (2026-11-25).

## Standing directives (all from Robert; memories hold the detail)

- **Cloud-first, Opus for everything** (memory `next-session-dual-axis-fanout`).
  - Every diagnosis and implementation slot is a cloud session in env "SWFRecomp fan-out" (`env_01QSs9FrDsLyis2RzQXg1UrW`).
  - Launch each with `scripts/fanout_cloud_worker.sh <slug> <prompt>`; it delivers ONLY on `fanout/<slug>`.
  - You stay local for merges, CI, results accounting and the oracles.
- **Full size** (memory `fanout-credits-diminishing-returns-ok`). Size wave 1 at about 8–10 slots, fund every measured
  wave-2 ledger, and add a wave 2b / 3 where results earn it.
- **No-graphics leg on the FINAL grading run only**, plus any interim that lands no-graphics-only code (CLAUDE.md). s26's
  rule paid off in s27: schedule an interim after the last local-ladder landing.
- **One heavy local build at a time** (memory `one-heavy-build-shared-lock`): `flock /tmp/swfrecomp-cpu.lock`, `-j4` /
  `EMCC_CORES=4`. Never run full suites locally.
- **Pages deploy is authorized.** A green `dry_run` deploys NOTHING: confirm the "Deploy to GitHub Pages" step ran. Run a
  dry run on every runtime/recompiler landing; it caught a bundle break in s27.
- **Pruning:** at closeout, run `git push origin --delete fanout/*`, but only after cmp-ing each branch's report and patch
  blobs against master.
- **Flash over Ruffle, extended 2026-11-24** (memory `flash-over-ruffle-ruling`). Robert: "I want to continue to document
  any difference we notice between Ruffle and Flash. If we notice problems with the Ruffle tests, then one idea is to
  store a set of fixes, and apply the fixes after redownloading the latest Ruffle tests. The goal is still to match
  Flash, not to match Ruffle."
  - Every confirmed Ruffle≠Flash difference gets an RvF entry.
  - A golden that FP32 proves wrong gets an entry in **`ruffle-tests/flash_fixes/`**, following its README. It is
    re-applied by `download_tests.sh` and is sha-pinned; STALE/UPSTREAMED entries print in the CI download log, so read
    that log after each run.
  - Never trade a Flash-correct pass for a Ruffle golden.
- Peer-session messages are teammate info, not Robert's approval.
- Windows ClearType may be switched off for a Flash capture, if you switch it back on afterwards (Robert, 2026-11-24).
  `C:\playwright\cleartype\ct.ps1 standard|cleartype|get` does it; restore in an EXIT trap.

## The real Flash oracle (s27's headline; memory `flash-player-oracle`)

`tools/flash-oracle/` runs Flash Player 32 projectors (Linux + Windows), locally only. It is the FIRST-CHOICE oracle for
traces and images; the Ruffle exporter is a fallback.
- AVM1 runs in DIRECT mode, pinned 1:1. `--wrapped` changes `_root` and depths: it produced false "Flash refutes" verdicts
  in s27.
- Non-LAYER blends need `--screen`.
- Cloud workers cannot run it. They write LOCAL ORACLE REQUESTS; you run them between waves and archive the outputs
  under `session28-fanout-reports/*-local-oracles/`.
- Put the "A REAL FLASH ORACLE EXISTS" section into `BRIEFS_COMMON.md` (copy it from s27's).

## Read first

1. Memories:
   - `next-session-dual-axis-fanout` (s27 record);
   - `flash-over-ruffle-ruling`, `flash-player-oracle`, `parallel-fanout-wave-pattern`, `graphics-fanout-playbook`;
   - `ci-baseline-must-be-read-fresh`, `corpus-status-diff-tool`;
   - `browser-wasm-gate-inventory`, `n-play-game-click`.
2. `SWFRecompDocs/plans/polish-sweep-arc.md` **§28**, especially §28.3 method notes and the **§28.4 trace board**.
3. `SWFRecompDocs/plans/graphics-fanout-playbook.md` **§26**: the pixel board, the golden-provenance summary, and the
   Flash-fixes record.
4. The s27 run of record as your TEMPLATE: `SWFRecompDocs/plans/session27-fanout-reports/`. Copy the shape of
   `BRIEFS_COMMON.md`, `briefs/_w1_header.txt`, `_w2_header.txt`, `AGENT_LAUNCH_ORDER.md` and `SIBLING_FILE_MAP.md`.
5. Tools: `session28-fanout-reports/coord-tools/` (`status_moves.py`, `status_moves_ng.py`, `allrows.py`,
   `watch_reports.sh`; see its README), `scripts/image_status_diff.py`, and `ruffle-tests/apply_flash_fixes.py --check`.

## Baseline (read it fresh; verify before quoting)

- **Graphics trace + pixels: run `45547012629` at `7c3cfdcb7`, results `e1425f417`.** This is the s27 final code plus the
  5 Flash-fix golden swaps. Do NOT grade pixels from the s27 final `cb14cd063`: the swaps move 4 bands there
  (`blend_scroll`, `strokes/scale`, `graphics_draw_path`, `definefont4`). s27 read 4781 / 4819 eff trace (38 failing) and
  626 pass / 39 fail pixels at `cb14cd063`, with 0 status moves to `e1425f417`.
- **No-graphics: run `45536916402` at `8f4f6e395`, results `2e286cf2f`** (4779 / 4819). The image-only swaps don't touch it.
- **Upstream drift since the s27 drift slots** (`~/CC/ruffle`, at `c2f7d24b7` on 2026-11-25; fetch again at launch):
  - `fa93ad79f`: avm1 fires the root's load event after its first frame's actions. `root_onload` loses `known_failure`;
    we already pass both rows.
  - `c2f7d24b7`: Ruffle swaps `jpeg-decoder` for `zune-jpeg`. No golden changed yet. If upstream re-bakes JPEG goldens,
    re-price `acid-color-0` (RvF: Ruffle's decoder ≠ Flash IJG) and `bitmapdata-clone`.
  - Fund one drift slot.

## Run first (local one-task sessions, in parallel with wave 1)

- **`trace-provenance`** (brief: `session28-fanout-reports/trace-provenance-prompt.md`): the trace-golden equivalent of
  s27's image sweep. It checks the 38 failing and 259 `ruffle_matched` rows against FP32, adds `flash_fixes` entries,
  and re-prices the trace board.
  - Launch it at startup with
    `PATH="$PATH:/mnt/c/Windows/System32:/mnt/c/Windows" ~/bin/wsl-launch-claude.sh -m opus -C /home/robert/CC/SWFRecomp-CC -d : -t trace-provenance -f <brief>`,
    verify `/proc/<pid>/cwd`, and send a handshake.
  - Its result re-prices wave 2. Fold its flash_fixes entries into your next grading run and grade them by name: a
    `ruffle_matched` row can turn into an honest `output_mismatch`, which is not a code regression.

## Wave-1 slate (suggested, from the boards; attack and resize as you see fit)

- **test12** (S–M; s27's only trace row lost vs FP32). Flash 10+ runs enterFrame once on clips 4 and 5
  (`enterFrameOrder` `0+1+2+3+1+2+4+3+1+2+5+3+…`). FP32 == `output.fp10.txt`; the capture is archived. Don't undo s27's
  line-19 fix (the init flush at call return). Ruffle misses this too: write an RvF entry when it lands.
- **drift** (above).
- **Loaded-shell residuals:** `child_timeline_loop`, `mcl_holder_totalframes`, `mcl_load_tick`. Also child frame-1 order
  (`e1 d1 c1`).
- **Text:**
  - wordwrap render fixture: Flash glyph AA (~590 channels; it keeps an interim Ruffle golden);
  - `rotated_glyphs` (1111 px vs Flash);
  - AVM2 selection tint (needs an ADDED_TO_STAGE fixture);
  - avm1-text-edit oracle requests (Restrict/onChanged, leading/margin).
- **Filters:**
  - applyFilter DropShadow residual and Bevel sample residual;
  - group-alpha `shadow_shape_a50` (768 px);
  - GPU display-filter growth (NO-GO of record; re-price only with a Flash capture).
- **Quality model:** `gradientTransform`'s golden is Flash at HIGH, while `test.toml` says low. Check what our runtime does
  with `with_renderer.quality` (the 9-px miss).
- **Leads:**
  - `movieclip_hittest_shapeflag`: pinned Flash says `false` on 3 lines where the golden says `true`. Are those our
    ACCEPTED lines? If so, it's an RvF plus a flash_fixes candidate.
  - `MAX_DEFERRED_*` queues; FileReference `download()`/`postData`.
- **Flash-fix candidates:** `place_object_test` and `shape_test` swap to their ROOT captures once our miss is under ~1k px.
- **Unchanged NO-GOs:**
  - the action_order family, `global_*_decls`, `native_objects_swf6`, `globals_monkeypatch`, `GradientFillTest`,
    `external_interface_monkeypatch`;
  - shumway `esc`;
  - the avm2 ACCEPTED/RvF set.
  - Re-open any of them only if trace-provenance finds its golden ≠ Flash.

## The parked ladders (adopt them; both PARKED at s27 closeout, not running)

- **N:** the head is thin-stroke Flash pixel snapping. The parked fixture is `SWFRecompDocs/plans/n-levels-5plus-hairline-fixture/`;
  the record is `n-levels-5plus`'s report in `session27-fanout-reports/`.
- **Browser:** the head is porting OFFSCREEN's inline root-goto catch-up to the browser loop (`ng_executeGotoCatchUp` /
  `ng_runPendingRootGoto` from timer and event callbacks; M). The oracle is `avm1_timer_root_goto_stopped_{gs,nf}` and
  `avm1_goto_backward_enterframe_once` in `tools/browser-test/child_probe/`. Next on that ladder:
  - `ng_apply_pending_sprite_self_gotos` in the browser (S);
  - `advance_attached_clip_frames` → the CI goto path (M; re-check Doodle Jump `attachBlocks`);
  - delete the dead `pending_remove` code (S).
  - The table is in `browser-parked-frame-report.md` §5.
- **How to run them:** one task per session, launched with the launcher line above. Write each brief from the previous
  report's "next" section. Verify each REPORT BACK on disk before launching the successor. Fold each ladder's
  CI-observable SHA into your next grading run.
- **Rules for ladder sessions:** grade a new browser fixture natively in both modes first (in s27 one found a CI bug), and
  every browser link must pass `-Wl,--fatal-warnings`.

## Landing and grading recipes (arc §27.3 / §28.3)

- **Land:**
  - `git apply --check`, then `git apply`, then `git apply --check -R`.
  - Append-only lists (canary, regression README, RvF, `flash_fixes/fixes.json`) are excluded from the apply; append
    their `+` lines by script.
  - For conflicts, use `git merge-file` against the merge-base; the partial clone blocks `--3way`.
  - The tree is shared, so commit from the index (`git apply --cached`).
- **Grade:**
  - Merge `origin/ruffle-test-results` after every run.
  - Run `coord-tools/status_moves.py` and `scripts/image_status_diff.py` (`--band-floor 0` for named rows).
  - Check every move by name against the ledgers.
  - Read the `flash-fix` lines in the CI download log.
- **Recovery:**
  - A shard that fails in setup publishes `incomplete=true` results: run `gh run rerun --failed`.
  - Final-run regressions get bisected and fixed, then a confirming pair.
- **Fixture goldens:** take them from FP32 first (direct, pinned). Use the exporter only for what Flash cannot run.
- **API limits:** poll at 120–180 s; one `gh run watch` at a time.

## Done

- **Final grading** in both modes, ledger-exact by name, with 0 regressions, or each one named and explained AGAINST FP32
  (not against an FP-version variant: s27's test12 lesson).
- **Closeout docs:** `polish-sweep-arc.md` §29 (ledger, verdicts that fell, method notes, "Left on the board (session
  29)") and `graphics-fanout-playbook.md` §27. Include the flash_fixes table and any STALE or UPSTREAMED entries.
- **Memory:** update `next-session-dual-axis-fanout` (s28 record + s29 boards).
- **Branches:** `fanout/*` pruned after cmp.
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
