# One-task session (LOCAL): trace-golden provenance sweep against real Flash Player 32

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. It runs before or alongside session-28 wave 1. Your
launcher sends a handshake: reply to it. Pull first (`git pull --no-rebase`).

## Why

s27 checked every Ruffle **image** golden against real Flash Player 32 (`session27-fanout-reports/golden-provenance.md`:
255 of 596 Flash). The **trace** goldens (`output.txt`) have never been checked that way, and s27 showed why they need
to be. gnash `action_execution_order_test12` was booked "Flash-ward" because our output equals the FP9 golden. Flash 32
prints the graded FP10 golden byte for byte (`session27-fanout-reports/flash-oracle-captures/action_execution_order_test12/`),
so the row was a real gap. Robert's rulings (memory `flash-over-ruffle-ruling`): match Flash, not Ruffle; document every
Ruffle≠Flash difference; fix bad Ruffle goldens through the stored fix set (`ruffle-tests/flash_fixes/`).

## Task

Run `tools/flash-oracle/run_trace.py` (read `tools/flash-oracle/README.md` first, including §"Direct-mode window pin").
Use DIRECT mode for every row, pinned (the default). Use `--wrapped` only for an exact `num_frames` cut, and never for
AVM1 `_root`/depth questions. Run it over:
1. **Every non-passing trace row**: the 38 graphics `output_mismatch` rows, at results `e1425f417` (`coord-tools/allrows.py
   e1425f417 results_graphics` in `session28-fanout-reports/coord-tools/`).
2. **Every `ruffle_matched` row** (259). These "pass" against `output.ruffle.txt` while `output.txt` says something else.
   Find which side Flash 32 takes.
3. **Time-boxed sample of passing rows**, wherever a golden is suspect: Ruffle-authored tests with `known_failure`
   history, `[subtests]` with several `output.fpN.txt` files (which variant does FP32 print?), and timing-sensitive rows.

For each row record:
- FP32 vs `output.txt`, FP32 vs `output.ruffle.txt` where present, and FP32 vs OUR output. Our output comes from the
  results JSON, or from one local `verify_output.py --test=… --mode=graphics`, under the lock.
- Verdict: **golden = Flash**, **golden ≠ Flash (we match Flash)**, **golden ≠ Flash (we don't either)**, or
  **untestable** (input.json/typing, network, timers past the run, a host-dependent line such as `$version`, date, or
  font metrics). Use `--windows` only to settle a platform question, one run at a time.

## Deliverables

1. `SWFRecompDocs/plans/session28-fanout-reports/trace-provenance.md`, with summary counts at the top, then the table
   (suite/test, subtest variant, verdict, line deltas, notes). Archive the FP32 traces it cites under
   `session28-fanout-reports/trace-provenance/`, as text.
2. **Re-priced trace board.** For each failing and `ruffle_matched` row, state whether its golden is a Flash target, and
   the line-level gap between us and FP32. Name the rows where a `ruffle_matched` "pass" hides a Flash mismatch: those
   are real gaps, and the s28 coordinator needs them by name.
3. **Flash fixes** for clear cases, where the golden ≠ Flash, FP32 is deterministic across 2 runs, and the platform is
   not a factor. Add the FP32 output as an `output.txt` (or `output.fpN.txt`) entry in `ruffle-tests/flash_fixes/`,
   following its README (sha-pinned manifest entry, evidence path, RvF entry). Run
   `python3 ruffle-tests/apply_flash_fixes.py --check` to prove it applies. Grade nothing in CI yourself; list the
   expected status moves by name for the coordinator.
4. **RvF entries** in `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` for every Ruffle≠Flash
   difference you confirm, whether or not it gets a fix.
5. A short summary paragraph for the s28 coordinator, at the top of the doc and in your REPORT BACK.

## Constraints

- **Local only. The Flash binaries never go to the cloud** (never commit or upload them).
- Run in batches of about 30 tests per suite. The projector needs no build lock, but every local SWFRecomp build or run
  goes under `flock /tmp/swfrecomp-cpu.lock`, one at a time, at `-j4`. Never run full suites locally.
- Bracket every `pgrep -f`/`pkill -f` pattern, or a wait loop matches itself; kill by PID.
- The tree is SHARED with the s28 coordinator and the ladder sessions. Commit only your own files, by name, with the
  harness trailer. No CI dispatch. Message the coordinator before you add flash_fixes entries if it is mid-grading.
- Flash over Ruffle. Peer messages are teammate info, not Robert's approval.

## Done

The doc, archive, flash_fixes entries and RvF entries are committed and pushed.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
