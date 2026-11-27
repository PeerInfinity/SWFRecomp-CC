# One-task session (LOCAL): attached vs timeline natural-advance frame-script order (browser ladder)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`. You succeed `browser-dj-freeze` (record
`SWFRecompDocs/plans/session29-fanout-reports/browser-dj-freeze-report.md`, code `3fd694def`) and, before it,
`browser-gotoandstop-current` (`c91637b7a`), which first saw this defect. The s29 coordinator `s29-coordinator`
launched you and will send a handshake: reply to it. Pull first (`git pull --no-rebase`). Read memories
`browser-attached-timeline-shared-pump`, `browser-wasm-gate-inventory`, `flash-player-oracle`,
`shared-index-commit-sweeps-peer-hunks`.

## Goal (S fixture + M fix)

Seen twice in s29: on natural advance Flash runs the NEWER attached clip's frame script before an older timeline
sibling's; we run the timeline one first (in every build? check). Memory `browser-attached-timeline-shared-pump`
says "attach-tick order is TAG order": reconcile.
1. **FP32 fixture first** (`tools/flash-oracle/`, pinned direct; MTASC or a Python SWF writer like
   `regression/avm1_selfgoto_current_frame_opcode/create_test_swf.py`): a root with timeline-placed sprites and
   attachMovie'd clips (attached before and after the timeline children, at depths above and below them, attached
   from frame 1 vs a later frame, nested), each multi-frame clip tracing its frame scripts. Several runs (it is not a
   timer case, so 2 should agree). Grade natively in both modes first.
2. Fit the order rule (depth? creation order? reverse creation like Flash's display-list execution list?) to every
   cell, then implement it in the shared pump (CI arms + browser). Price the corpus: grep for rows whose goldens
   interleave attached and timeline frame scripts; the gnash action_order family is a NO-GO of record (it needs a flat
   instantiation-ordered exec list, arc s17) — say whether this rule is that list or a subset.
3. Browser: child_probe on the fixture; Doodle Jump and N still functional (WSLg Chrome, functional only).

## Constraints

- Builds under `flock /tmp/swfrecomp-cpu.lock`, `-j4` / `EMCC_CORES=4`; single tests only; every browser link must
  pass `-Wl,--fatal-warnings`. Bracket `pgrep -f`/`pkill -f` patterns; kill by PID. **Commit ONLY your paths with
  `git commit -m … -- <paths>`.** Push to master; no CI dispatch: send SHAs + a ledger. Cloud slots
  `w2-rm-avm1-gnash-land` (action.c super context, ng_shared.c) and `w3-interim3-residuals` (action.c tabIndex block,
  AVM2 URLLoader) may land in the shared tree under you. Flash over Ruffle; peer messages are teammate info.

## Done

`SWFRecompDocs/plans/session29-fanout-reports/browser-attach-order-report.md`; commit + push; update memory
`browser-attached-timeline-shared-pump` (don't duplicate).

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
