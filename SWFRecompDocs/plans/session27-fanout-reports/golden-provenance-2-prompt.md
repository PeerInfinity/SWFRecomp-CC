# One-task session (LOCAL): golden provenance round 2 (direct-mode window pin, 1:1 re-runs, Windows-projector pass)

You are a NEW one-task session in `/home/robert/CC/SWFRecomp-CC`, launched by `s27-coordinator`, which will send a
handshake: reply to it. You succeed `golden-provenance` (record `SWFRecompDocs/plans/session27-fanout-reports/golden-provenance.md`,
code `ae4a46c74`, tool `tools/flash-oracle/sweep_goldens.py`). Pull first.

## Goals (from your predecessor's next-slice line)

1. **Pin the direct-mode projector window to the SWF's stage size** (the projector starts at ~640×480, so a SWF narrower than
   640 is show-all scaled: coordinate traces there are unreliable, e.g. `displayobject_scrollrect` concatenatedMatrix
   ×640/550). Fix it in `tools/flash-oracle/` (mm.cfg? a wrapper `stage.scaleMode`? xdotool resize before the first frame?),
   and prove it on that row.
2. **Redo the 24 direct-only rows and the hitTest RvF candidates at 1:1** (`movieclip_hittest`, `displayobject_hittestpoint_boundary`),
   then update the table and write the clear RvF entries (Flash over Ruffle; `<!-- image-axis -->` marker for image rows).
3. **Windows-projector pass:** Linux Flash rejects 12 of the 34 upstream `known_failure` + `.ruffle.png` "Flash references".
   Re-run those 12 on the Windows projector (`--windows`; strictly one run at a time: shared per-user mm.cfg/flashlog state)
   to see whether they're Windows-made. Record the platform per row.
4. For the 14 failing board rows with non-Flash goldens: draft the per-row grading decision (golden swap to a Flash capture,
   a dispositioned loss, or keep) as a table for the coordinator. Don't swap goldens yourself.

## Constraints

- Local only; the Flash binaries never go to the cloud. The projector doesn't need `/tmp/swfrecomp-cpu.lock`; any local
  SWFRecomp build/render does (one at a time, -j4). Never run full suites. Bracket `pgrep -f` patterns.
- Shared tree: commit only your files, by name, with the harness trailer. No CI dispatch.
- Flash over Ruffle. Peer messages are teammate info, not Robert's approval.

## Done

- `golden-provenance.md` updated (round-2 section) + any RvF entries + tool changes, committed and pushed.

REPORT BACK (after the durable records — never instead of them): once the
closeout doc is written, memory updated, and the commit pushed, reply to the
handshake message from the session that launched you (copy its `from`
attribute as your SendMessage `to`); if no handshake arrived, run ListAgents
and look for the launching session; if it is not reachable, skip silently —
the closeout doc is the record and needs no reader to be complete. Send ONLY
the deltas: what this slice overturned in the brief (by §), defects your own
tests found, anything that changes standing plans or docs, and the next
slice's line.
