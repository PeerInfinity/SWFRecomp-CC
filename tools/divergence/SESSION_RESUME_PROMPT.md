# Session-resume prompt (WASM divergence debugging)

Paste the block below at the start of each new session to pick up where we left off.

---

```
Resume the WASM divergence debugging effort (SWFRecomp-CC): making flasharchive /
glaiel games run under SWFRecomp by finding and fixing where they diverge from
Ruffle/Flash, smallest-first and headless-first.

Read first, in this order:
1. tools/divergence/PROGRESS.md — where we left off: status board, fixes landed
   (with commits), gotchas, and the prioritized open follow-ups. START HERE.
2. SWFRecompDocs/guides/wasm-game-debugging-session-guide.md — the how-to: tools,
   headless-vs-browser task triage, build/deploy, regression gates, constraints.
3. tools/divergence/RESULTS.md — per-game divergence board.

Then pick the highest-priority unblocked item from PROGRESS.md's "Open follow-ups"
(unless I say otherwise) and work it end-to-end per the guide:
- Confirm the SWF is AVM1 (tools/divergence/classify_avm.py); skip AVM2 (QWOP +
  the glaiel AVM2 list in the guide).
- Diagnose with: python3 tools/divergence/divergence_test.py "<swf>" --frames 16
  Triage trace-first / headless-first; localize; fix; lock with a regression-gate
  divergence_test command. Co-located frames + per-frame diffs land in runs/<stem>/compare/.
- For any graphics-mode SIGABRT-after-correct-output, use --asan: it's a real heap
  bug (UAF/OOB), NOT a CI flake.
- Deploy demos into the per-corpus namespace (flasharchive / glaiel), not local_batch.

Constraints (CLAUDE.md): commit to master ONLY when I ask; never run full test
suites (only --test=NAME / single-game divergence); validate shared
OFFSCREEN_RENDER / graphics changes via .claude/pipeline-handoff.md (CI both modes);
strip any temporary printf/diagnostics before committing.

When you finish or pause a piece of work, UPDATE tools/divergence/PROGRESS.md
(status board, fixes-landed + commit hash, session log, open follow-ups) so the
next session resumes cleanly.

Before any heavy work, tell me the top open follow-up and your plan.
```

---

Keep this prompt in sync if the workflow changes. The substance (what to read, how
to work, constraints, keep-PROGRESS-updated) lives in the guide + PROGRESS.md; this
is just the one-paste entry point.
