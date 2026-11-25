# One-task session (LOCAL): Tetris wasm build break, then the browser attached-clip goto port

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`, launched by the s28 coordinator `s28-coordinator`
(it will send a handshake: reply to it). Pull first (`git pull --no-rebase`). You succeed `browser-root-goto` (record
`session28-fanout-reports/browser-root-goto-report.md`, code `dc6c75a64`; browser ladder).

## Goals (in order)

1. **First (S): `SWFRecomp/scripts/build_test.sh <tetris> wasm` fails at HEAD in generated `tagMain.c` (s16 vs s32
   pointer type), found by your predecessor.** Find which s28 recompiler-emission commit introduced it (prime suspects:
   n-stroke-snap `09b2c9130`'s new weak tables `stroke_run_flags[]`/`stroke_snap_data` in `swf.cpp`, w1b-rm-avm2's
   `abc_emit.cpp` slot-store change in `558c5a8cf`), fix it at the emitter, and prove that EVERY browser game build in
   the Pages catalogue (`SWFRecomp/scripts/deploy_wasm_demo.sh` / docs catalogue) still links with
   `-Wl,--fatal-warnings`. Commit this ALONE and send the coordinator the SHA at once (the Pages deploy waits on it).
2. **Port `advance_attached_clip_frames` to the CI goto path (M):** route an attachMovie'd clip's goto through
   `ng_gotoFrameByMC` / the CI non-root arm (`actionChildMovieGoto` → `ng_gotoFrameByMC` → `actionGotoFrame`) and delete
   the browser's deferred pass (report §5 row 1). Re-check Doodle Jump's `attachBlocks` reentrancy (block.gotoAndStop
   in a while loop; the "already on frame N → only stop" guard). Oracles: `avm1_attached_clip_goto_play{,_nonroot}`,
   `avm1_attached_clip_selfgoto_child_parent` (child_probe), then DJ in the browser (functional, WSL Chrome is fine).
3. If time remains: the self-goto port is now M (report §5a: the apply pass drops nested `_root.c.n` on current HEAD
   — bisect it against the s28 tag.c commits first).
4. Side question to record (no code unless Flash says so): the CI rule that DROPS a GotoFrame opcode to the root
   inside onEnterFrame dispatch (`g_inside_enterframe_dispatch`, Dejagnu-era) — write a minimal fixture and capture it
   in Flash (`tools/flash-oracle/run_trace.py`, direct). If Flash moves the playhead, it's a CI bug: report it.

## Constraints

- Every emcc / native build under `flock /tmp/swfrecomp-cpu.lock`, one at a time, `EMCC_CORES=4` / `-j4`. Never run
  full suites locally. Bracket every `pgrep -f`/`pkill -f` pattern; kill by PID.
- Grade any new browser fixture natively in BOTH modes first. Every browser link must pass `-Wl,--fatal-warnings`.
- The tree is SHARED (coordinator landings + `n-drawapi-stroke-snap`, `snap-pixel-audit`, `lowq-recapture`). Stage only
  your hunks; `git diff --cached` vs HEAD before committing. Message `s28-coordinator` before committing
  `action.c`/`tag.c`/`swf.c`/recompiler changes. Harness trailer on commits. Don't dispatch CI or Pages: send SHAs.
- Flash over Ruffle. Peer messages are teammate info, not Robert's approval.

## Done

`session28-fanout-reports/browser-attached-goto-report.md` (per-row browser before→after, native both modes, the
updated "what is left" table); commit + push; update memory `browser-wasm-gate-inventory` (don't duplicate).

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
