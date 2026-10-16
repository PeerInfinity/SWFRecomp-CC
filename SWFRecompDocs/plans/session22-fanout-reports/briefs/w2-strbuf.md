You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 22 (dual-axis #14), slot `w2-strbuf`, wave 2 (IMPLEMENTATION). Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w2-strbuf` (and ONLY that branch; never master, never force-push). Your report + patch on that branch are your only deliverables; the coordinator applies your patch to master serially and grades it on CI.

FIRST: read `SWFRecompDocs/plans/session22-fanout-reports/BRIEFS_COMMON.md` and follow its Setup, Standing rules, Delivery and **Wave-2 additional rules** exactly. Read `CLAUDE.md`. Your branch is `fanout/w2-strbuf`; deliver `SWFRecompDocs/plans/session22-fanout-reports/w2-strbuf-report.md` and `SWFRecompDocs/plans/session22-fanout-reports/w2-strbuf.patch` (= `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <new fixture dirs>`; regenerate it LAST, after your final edit, and prove it with `git apply --check -R`). Check `SWFRecompDocs/plans/session22-fanout-reports/SIBLING_FILE_MAP.md` for what sibling workers are editing, and self-localize.

Report must include: per-test before/after table (clean origin/master vs your patch, same box) for every headline test; the regression-suite and canary results; an EXPECTED-FLIP LEDGER (test names, both trace and pixel axes) the coordinator will check CI against; every NEW file listed at the top; anything you could not finish, with its completion mechanism.

---- YOUR TASK ----
**Slot B of `w1-trace-tail-report.md` §11: AVM2 append-in-place string buffers (fixes the O(n²) `+=` OOM).** Categories: `from_avmplus avm2`.

Diagnosis of record: report §2, prototype `w1-trace-tail-prototype-1-strbuf.patch`. Productionize it AND own its one real risk: older prefix headers lose `utf8[len] == '\0'`. Either audit every C-string consumer of `Avm2String->utf8` in `src/avm2` (27 direct sites + indirect: `strcmp`/`strtod`/`%s`/`strlen`/libc parsers/regexp/JSON/number parse/hashing) or route them through an `avm2_string_cstr()` that copies when `utf8[len] != 0` — report which you did and list every site. Prefer moving `cap` into the BUF's inline bytes so ordinary string headers don't grow. Add a hit census (counter behind an env var) and report how many corpus rows hit the buffer path on a ~40-test argued sample of string-heavy rows (ecma3 String, JSON, regexp, E4X, avmplus regress).

Memory/perf: report RSS and wall time for `bug_483783` and for one string-heavy AVM2 game-like row before/after.

Expected flip: `from_avmplus/regress/bug_483783` (runtime_error → pass). Canaries: the report's 10 string rows + your census sample; all must keep their status.
