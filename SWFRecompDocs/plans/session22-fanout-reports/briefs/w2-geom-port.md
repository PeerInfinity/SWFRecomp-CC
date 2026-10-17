You are a CLOUD WORKER in SWFRecomp-CC corpus fan-out session 22 (dual-axis #14), slot `w2-geom-port`, wave 2 (IMPLEMENTATION). Run autonomously to completion: nobody will answer questions, and messages sent to you may never arrive. Do not spawn subagents.

The user has approved you pushing to the scratch branch `fanout/w2-geom-port` (and ONLY that branch; never master, never force-push). Your report + patch on that branch are your only deliverables; the coordinator applies your patch to master serially and grades it on CI.

FIRST: read `SWFRecompDocs/plans/session22-fanout-reports/BRIEFS_COMMON.md` and follow its Setup, Standing rules, Delivery and **Wave-2 additional rules** exactly. Read `CLAUDE.md`. Your branch is `fanout/w2-geom-port`; deliver `SWFRecompDocs/plans/session22-fanout-reports/w2-geom-port-report.md` and `SWFRecompDocs/plans/session22-fanout-reports/w2-geom-port.patch` (= `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt <new fixture dirs>`; regenerate it LAST, after your final edit, and prove it with `git apply --check -R`). Check `SWFRecompDocs/plans/session22-fanout-reports/SIBLING_FILE_MAP.md` for what sibling workers are editing, and self-localize.

Report must include: per-test before/after table (clean origin/master vs your patch, same box) for every headline test; the regression-suite and canary results; an EXPECTED-FLIP LEDGER (test names, both trace and pixel axes) the coordinator will check CI against; every NEW file listed at the top; anything you could not finish, with its completion mechanism.

---- YOUR TASK ----
**Port flash.geom.Point, Rectangle and Matrix to ActionScript semantics on top of the landed `as_*` helper layer (slot S3 of `w1-drift-avm1-report.md`).** Categories: `avm1 from_gnash visual avm2`.

Prerequisites are ON MASTER: `w2-as-core` (`0cea97b3e`: the static `as_*` helper block in `action.c` ~2884-3173 with documented contracts, and M5 — closures keep their captured scope on method/ctor arms) and `w2-array-global` (`d9c78d14b`). Read `w2-as-core-report.md` §1 (helper contracts and the `as_this` caveat) before writing code.

Diagnosis of record: `w1-drift-avm1-report.md` §M1 (sub-mechanisms a-e) and slot S3. Spec = `/root/ruffle/core/src/avm1/globals/flash/geom/{Point,Rectangle,Matrix}.as` (Ruffle passes every target test, no KF), but **`output.txt` (Flash) is truth**. Our natives: Point `action.c` ~10197-10630, Matrix ~10630-10990, Rectangle ~11029-11500, registration ~11544 `registerGeomMethod` (line numbers have shifted after as-core; grep). Order: Point → Rectangle → Matrix, A/B after each; if you run short, deliver Point+Rectangle (3 flips) as a complete patch and report Matrix's state.

Hard requirements:
- Every property get/set, internal method dispatch (`this.isEmpty()`, `this.identity()`, `Point.subtract`, `Math.sin`, `new flash.geom.Point` …) and coercion goes through the helpers in Flash order — the tests trace each one.
- **Native construction sites** (`BitmapData.rectangle`, `transform.matrix`/`colorTransform`/`concatenatedMatrix`, `getBounds`/`getRect`, filter matrices, `Matrix.createGradientBox` users, etc.) must keep building instances through the global `flash.geom.*` prototypes so the ported methods apply to them, and must stay fast: geom objects feed transforms. Report a perf A/B on one transform-heavy row.
- Run the graphics render canary (geom feeds transforms) and every avm1/avm2 row that uses `flash.geom` (grep the downloaded corpus), both modes.

Expected flips (trace): `avm1/point`, `avm1/rectangle`, `avm1/matrix`, gnash `Rectangle-v8`, `Matrix-v6`, `-v7`, `-v8` (7). Also report `avm1/globals_monkeypatch`'s diff count (its `flash.geom` getter rows may move). Sibling `w2-htmltext` edits `action.c` text/HTML functions; stay in the geom block and the helper block (extend helpers only by adding, never changing a contract).
