You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 22 (dual-axis #14), slot `w2-ei-provider`, wave 2 (IMPLEMENTATION). Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w2-ei-provider` (and ONLY that branch; never master, never force-push). Your report + patch on that branch are your only deliverables; the coordinator applies your patch to master serially and grades it on CI.

FIRST: read `SWFRecompDocs/plans/session22-fanout-reports/BRIEFS_COMMON.md` and follow its Setup, Standing rules, Delivery and **Wave-2 additional rules** exactly. Read `CLAUDE.md`. Your branch is `fanout/w2-ei-provider`; deliver `SWFRecompDocs/plans/session22-fanout-reports/w2-ei-provider-report.md` and `SWFRecompDocs/plans/session22-fanout-reports/w2-ei-provider.patch` (= `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <new fixture dirs>`; regenerate it LAST, after your final edit, and prove it with `git apply --check -R`). Check `SWFRecompDocs/plans/session22-fanout-reports/SIBLING_FILE_MAP.md` for what sibling workers are editing, and self-localize.

Report must include: per-test before/after table (clean origin/master vs your patch, same box) for every headline test; the regression-suite and canary results; an EXPECTED-FLIP LEDGER (test names, both trace and pixel axes) the coordinator will check CI against; every NEW file listed at the top; anything you could not finish, with its completion mechanism.

---- YOUR TASK ----
**Slot C of `w1-trace-tail-report.md` §11: AVM2 ExternalInterface test provider (the harness Ruffle runs `avm2/external_interface` under).** Categories: `avm2 avm1`.

Diagnosis of record: report §4. Precedent: `avm1/external_interface` passes through a git-tracked `test_harness.c` (408 lines); `verify_output.py` (~:2873/3325) already compiles any `test_harness.c` in a test dir. Upstream spec: `/root/ruffle/tests/tests/external_interface/{tests.rs,mod.rs}` (`ExternalInterfaceTestProvider`: `ping` → "Pong!", `trace` → "Traced!", `reentry` calls back into `callWith`; after the first preloaded tick the harness injects 5 host calls — `parrot` ×2, `freestanding`, `removeMe`, `callWith` — and traces their Rust `Debug` form).

Scope: new `ruffle-tests/tests/swfs/avm2/external_interface/test_harness.c` (NOTE: that test dir is downloaded, not git-tracked — check how the avm1 twin's harness is tracked (`git ls-files | grep external_interface`) and follow the same mechanism so CI sees it); a provider hook in `avm2_external.c` (`available` true under the harness, `call()` routed to the provider, a host→AS3 dispatcher taking structured values Object/List/Number/Bool/Null instead of the string-first `avm2_ei_dispatch`); a `Debug` formatter (template: the AVM1 harness's `ev_format`). Keep the non-harness build path byte-identical.

Expected flip: `avm2/external_interface` (pass). Canaries: `avm1/external_interface`, every `avm2/*external*` and `ExternalInterface`-using row, regression EI fixtures, both modes for the headline.
