You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 22 (dual-axis #14), slot `w2-queue-regex`, wave 2 (IMPLEMENTATION). Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w2-queue-regex` (and ONLY that branch; never master, never force-push). Your report + patch on that branch are your only deliverables; the coordinator applies your patch to master serially and grades it on CI.

FIRST: read `SWFRecompDocs/plans/session22-fanout-reports/BRIEFS_COMMON.md` and follow its Setup, Standing rules, Delivery and **Wave-2 additional rules** exactly. Read `CLAUDE.md`. Your branch is `fanout/w2-queue-regex`; deliver `SWFRecompDocs/plans/session22-fanout-reports/w2-queue-regex-report.md` and `SWFRecompDocs/plans/session22-fanout-reports/w2-queue-regex.patch` (= `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <new fixture dirs>`; regenerate it LAST, after your final edit, and prove it with `git apply --check -R`). Check `SWFRecompDocs/plans/session22-fanout-reports/SIBLING_FILE_MAP.md` for what sibling workers are editing, and self-localize.

Report must include: per-test before/after table (clean origin/master vs your patch, same box) for every headline test; the regression-suite and canary results; an EXPECTED-FLIP LEDGER (test names, both trace and pixel axes) the coordinator will check CI against; every NEW file listed at the top; anything you could not finish, with its completion mechanism.

---- YOUR TASK ----
**Slot A of `w1-trace-tail-report.md` §11: goto-sweep CONSTRUCT events + libregexp u16 capture indices.** Categories: `from_gnash from_avmplus avm1 avm2`.

Diagnosis of record: `session22-fanout-reports/w1-trace-tail-report.md` §1 and §3, prototypes `w1-trace-tail-prototype-2-gotosweep-construct.patch` and `-3-regexp-u16-captures.patch`.
1. `action_queue.c:166-176`: `AQ_KIND_CLIP_CONSTRUCT` must fire for clips placed and removed inside the same goto sweep (Flash fires all placement-time construct events). Keep the skip for load/unload as today. Do NOT widen to `CLIP_INIT`/`REGISTER_CTOR` (unmeasured lead; list it).
2. libregexp u16 capture operands per the prototype, PLUS the two fixes owed (report §3): named-group back-reference >255 must be a parse error (not clamp to 255), and `re_find`'s capture array (`avm2_regexp.c:695`) must be sized for `lre_get_alloc_count` (2·captures + registers) — that one is a latent stack overflow on master today; add a `regression/` fixture only if you can get expected output from outside SWFRecomp, otherwise describe the crash repro in the report.

Expected flips: gnash `misc-ming.all/action_order/action_execution_order_test6` (KF → ruffle_matched), `from_avmplus/recursion/pcre_find_fixedlength` (KF → pass). Canaries: the report's 63 queue rows and 40 regex rows (re-run them all, both modes for the queue rows), plus the regression suite's goto/clip-event members.
