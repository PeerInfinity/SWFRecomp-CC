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
- The report auto-flags three benign classes — VERIFY before treating any as a
  bug: TRANSIENT (whole-trace divergences confined to early frames that
  re-converge); PRELOADER (getBytesLoaded/getBytesTotal-driven — SWFRecomp reports
  a local SWF fully loaded immediately while Ruffle's exporter streams bytes, the
  accepted preloader-pacing class, document via tools/divergence/accepted/); and
  CLIP_TRANSIENT / "self-healing per-clip divergence" (a NAMED clip diverging only
  on its FIRST observed frame then re-converging = the enterFrame-vs-tracer
  observer-ordering artifact, #10b class — e.g. a custom mouse cursor whose
  onClipEvent(enterFrame) fires opposite the injected tracer's onEnterFrame; auto-
  recognized, not flagged, no manifest needed). The first divergence's kind
  (replace / ruffle_only / swfrecomp_only) + the line-count summary tell you
  whether it's a value diff or an added/removed line.
- For any graphics-mode SIGABRT-after-correct-output, use --asan: it's a real heap
  bug (UAF/OOB), NOT a CI flake.
- Deploy demos into the per-corpus namespace (flasharchive / glaiel), not local_batch.

Constraints (CLAUDE.md): autonomous commit/push/CI is authorized — when a piece
of work is done or paused with progress, run the pipeline end-to-end per
.claude/pipeline-handoff.md (commit → push master → trigger ruffle-tests.yml in
the matching mode → gh run watch → merge results → report regressions); validate
shared OFFSCREEN_RENDER / graphics changes in CI both modes (or graphics at
minimum), no-graphics otherwise; never run full test suites locally (only
--test=NAME / single-game divergence); strip any temporary printf/diagnostics
before committing.

When you finish or pause a piece of work, UPDATE tools/divergence/PROGRESS.md
(status board, fixes-landed + commit hash, session log, open follow-ups) so the
next session resumes cleanly.

Before any heavy work, tell me the top open follow-up and your plan.
```

---

Keep this prompt in sync if the workflow changes. The substance (what to read, how
to work, constraints, keep-PROGRESS-updated) lives in the guide + PROGRESS.md; this
is just the one-paste entry point.
