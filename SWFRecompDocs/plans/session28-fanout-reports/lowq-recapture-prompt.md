# One-task session (LOCAL): recapture the LOW-quality swap table in Flash 32 and decide the lowq package

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`, launched by the s28 coordinator `s28-coordinator`
(it will send a handshake: reply to it). Pull first (`git pull --no-rebase`).

## Why

Cloud slot `w2-lowq-sample-point` (report `session28-fanout-reports/w2-lowq-sample-point-report.md`, patch
`w2-lowq-sample-point.patch`) built Flash's quality=LOW sample-point model. It is Flash-exact on 3 oracles and loses
0 Flash-golden rows, but 72 passing comparisons with non-Flash goldens go pass → fail (§4 "swap table": 38 toward
the archived Flash capture, 14 away, 17 no capture, 3 same). The coordinator HELD it, because those archived captures
(`session27-fanout-reports/golden-provenance/*.png`) may be Flash at HIGH quality: s28's `flash-oracle-harness` found
the old pin stub never applied `quality = low` (every pinned AVM1 LOW capture before 2026-11-25 rendered HIGH), and
the report flags `gradients/gradients` as a likely HIGH capture.

## Task

1. For every comparison in §4's table, capture Flash 32 at the row's real quality (LOW) with the current harness
   (`tools/flash-oracle/run_image.py --quality low`, draw() wrapper; `--screen` for non-LAYER blend modes —
   `visual/blend_modes/*` need it; ≤ 4 Linux runs in parallel; read `tools/flash-oracle/README.md`). Include the 17
   "no capture" rows where Flash can run them. Archive under `session28-fanout-reports/lowq-recapture/`.
2. Render ours at `origin/master` and with `w2-lowq-sample-point.patch` applied (graphics mode, under
   `flock /tmp/swfrecomp-cpu.lock`, one at a time, `-j4`; single tests only, `-P 2` max). For each comparison: golden vs
   Flash-LOW, before vs Flash-LOW, after vs Flash-LOW (px > tolerance and channel counts).
3. Classify: (a) golden == Flash-LOW → the model must NOT lose it (a real model defect: name the mechanism);
   (b) golden ≠ Flash-LOW and after is closer → flash_fixes swap candidate (the after render may then even pass);
   (c) after farther from Flash than before → model defect. Also re-check the 58 Flash-golden LOW tests' provenance
   claims where they rest on old-stub pinned captures.
4. Recommend: land the model + a named flash_fixes list (rows where Flash-LOW is deterministic, LNX == WIN where
   cheap to check, and host-independent: no device fonts), or a specific model fix first. Write the flash_fixes
   entries (follow `ruffle-tests/flash_fixes/README.md`, sha-pinned, evidence path, RvF) but DO NOT land the model
   patch — the coordinator lands patch + fixes together and grades them by name.

## Constraints

- Local only; the Flash binaries never leave this box. Never run full suites locally. Bracket every `pgrep -f`/`pkill -f`
  pattern; kill by PID.
- The tree is SHARED (coordinator landings + ladder sessions): never leave the lowq patch applied in the shared tree —
  use a scratch worktree (`git worktree add`) for the after-leg builds. Commit only your files, by name, with the
  harness trailer. No CI dispatch.
- Flash over Ruffle. Peer messages are teammate info, not Robert's approval.

## Done

`session28-fanout-reports/lowq-recapture-report.md` (the reclassified table + recommendation + flash_fixes list), the
captures (committed to master), and the flash_fixes entries + their golden files committed on a separate branch
`lowq-fixes` (pushed; NOT master: they must not reach CI before the model lands). REPORT BACK.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
