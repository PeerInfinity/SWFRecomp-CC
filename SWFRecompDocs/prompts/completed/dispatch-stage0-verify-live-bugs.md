# Session prompt: Dispatch plan Stage 0 — verify/fix the suspected live arg-marshalling bugs

Execute **Stage 0** of `SWFRecompDocs/plans/function-dispatch-consolidation-plan.md`.
Read that plan first — it has the survey findings, file:line anchors, and the four
suspects. This prompt adds session-specific method guidance. Do NOT start Stages 1+
(the `invokeFunctionValue` consolidation) in this session.

## Goal

For each suspect below, reach one of two verdicts, with evidence:
- **REAL BUG** → fix it inline (minimal, site-local — no consolidation), add a
  permanent regression test, run the full pipeline.
- **UNREACHABLE** → add a comment at the site explaining exactly why, and record
  the reasoning in the plan doc's Stage 0 section.

Repro-first: build a minimal SWF that *reaches the path* before judging anything.
A verdict without a repro attempt is not a verdict.

## The suspects (priority order)

1. **`actionEI_callInternalInterface` (action.c:6313) pushes type-1 args in
   REVERSE** — missed by the `bcacc3f70` TYPE1_ARG_ORDER sweep. Repro shape:
   `ExternalInterface.addCallback` registering a **type-1** function with ≥2
   params, invoked through the internal-interface path with distinguishable args
   (e.g. `f(1,2)` tracing `a=1 b=2` vs swapped). Reachability question to settle
   first: is this path browser-WASM-only, or reachable natively/livetest? If
   browser-only, use the Playwright probe tooling
   (`SWFRecompDocs/guides/browser-test-harness-usage.md`, needs `DISPLAY=:0`).
2. **`mc_call_as2_handler_ng` (~action.c:71798) type-1 arm pushes NO args** —
   every clip/button/key/focus/text event routes here. The failure shape is a
   type-1 handler **with declared parameters**: params should read as
   `undefined` (or the event's real argument), not garbage/caller-stack values.
   Two angles: (a) `mc.onPress = function(a){trace(a);}` — Flash traces
   `undefined`; (b) an event that genuinely passes an argument in Flash —
   `onSetFocus(oldFocus)` / `onKillFocus(newFocus)` on a Selection focus change —
   with a type-1 handler. Check what our dispatcher passes for those events on
   the type-2 arm to see the intended `num_args`; the type-1 arm ignoring them
   is the suspect.
3. *(stretch, time-boxed)* **Missing `switchToFunctionVersion`** on
   event/timer/EI/coercion paths — one representative repro: a version-sensitive
   behavior (e.g. `actionNot` truthiness of `"0"`-style strings, or
   case-sensitivity of a lookup) inside a `setInterval` callback defined in a
   different-version context. If this rabbit-holes, record findings and defer to
   Stage 4 normalization.
4. *(stretch)* **Missing captured-scope push** in LocalConnection/NetStream/
   NetConnection/coercion dispatchers — repro: a closure over a local variable
   used as an `onStatus` handler; the variable should resolve.

## Method notes

- **Forcing type-1**: type-1 = plain `DefineFunction` (not DefineFunction2).
  MTASC (`~/CC/mtasc/bin/mtasc`, `-cp ~/CC/mtasc/ocaml/mtasc/std`, see CLAUDE.md)
  typically emits DefineFunction2 for SWF6+ — check with JPEXS (`~/CC/jpexs`) and
  if needed target `-version 5`/`-version 6` or generate the SWF with a Python
  bytecode generator (the `create_test_swf.py` pattern used throughout
  `SWFRecomp/tests/`). **Verify the SWF actually contains DefineFunction before
  trusting any repro result.**
- **Oracle**: Ruffle source at `~/CC/ruffle` (how does it marshal args for the
  same event?); Flash behavior notes in the investigation docs. For focus-event
  argument semantics, Ruffle's `on_set_focus` dispatch is the reference.
- **Local testing**: single tests only — `verify_output.py --test=...` for
  ruffle-suite style, or build the scratch SWF directly. **Never run full suites
  locally** (no `all_tests.sh`, no suite-wide runs) — CLAUDE.md rule.
- **Permanent tests** for confirmed bugs: hand-written trace test under
  `SWFRecomp/tests/` (generator + `validate.py`, run just that one test), or a
  ruffle-tests custom test if the harness fits better. Browser-only repros
  (suspect 1) can live as a livetest/probe script; note that CI can't observe
  those (see `ci-only-when-observable` memory).

## Pipeline / hygiene

- Runtime `.c` fixes are **shared code → CI both modes** per
  `.claude/pipeline-handoff.md`; comment-only "unreachable" verdicts are docs-only
  → commit/push without CI.
- One suspect per commit where practical; report any pass→fail regressions by name.
- Finish by: updating the plan doc's Stage 0 section with all four verdicts +
  evidence; updating `plans/README.md` status line if Stage 0 completes; saving a
  memory entry with the verdicts (especially any UNREACHABLE reasoning — it
  gates Stage 1 design); noting anything learned that changes the Stage 1–5
  design.

## Success criteria

Suspects 1 and 2 have evidence-backed verdicts (fix+test or documented
unreachability). Suspects 3 and 4 have at least a repro attempt or an explicit
deferral note. CI green (both modes) on any code change. Plan doc reflects
reality when the session ends.
