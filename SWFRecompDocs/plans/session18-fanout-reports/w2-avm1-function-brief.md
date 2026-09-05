# w2-avm1-function — wave 2: gnash `Function-v6/-v7/-v8` (+3, medium)

Read `BRIEFS_COMMON.md` (incl. wave-2 rules) and `SIBLING_FILE_MAP.md`, then the diagnosis of
record: `w1-trace-avm1-report.md` §2 (G2). Isolated worktree; no commits.

## Scope
`from_gnash/actionscript.all/Function-v6` 263/271, `-v7` 264/272, `-v8` 264/272 — the same 8
lines in each. Three sub-mechanisms (report §2): (F1) the `arguments` object has ZERO enumerable
properties (`callee`/`caller` must not appear in for-in); (F2) a user-defined function's
`__proto__` is `_global.Function.prototype`; (F3) `stringInstance.__proto__` is not undefined.
All 8 lines are needed for a flip — if F3 proves unsafe, deliver F1+F2 anyway with the honest
ledger (0 flips, N lines) and a HOLD with completion mechanism for F3. These tests are
`known_failure` with ruffle oracles that do NOT cover our 8 lines, so `pass` (Flash) is the target.

Files: `SWFModernRuntime/src/actionmodern/action.c` — Function object / `arguments` construction /
for-in enumeration / `__proto__` resolution. Siblings edit `action.c`'s mouse-pick + virtual-
property regions (w2-avm1-hitarea) and `swf.c` (w2-avm1-goto); self-localize.

## Verification (per-test before/after in the report)
Headline: the three Function-v tests. Canaries — this touches enumeration and prototype chains,
which is blast-radius-heavy: `from_gnash/actionscript.all/Object-v*`, `Inheritance-v*`,
`Global-v*` (passing ones), `avm1/function_*`, `avm1/arguments*`, `avm1/for_in*`, `avm1/proto*`,
`avm1/string_*` (sample 6), `avm1/globals_swf*` passing variants, `from_shumway/avm1/*` passing
tests mentioning prototype/arguments (grep), and the `regression` suite (all AVM1 tests). Bar:
byte-identical `--diff` output before/after. `-P 2`, compile timeout 2400, copied test dirs with
`--recompile` on first use. Run 2–3 canaries in `--mode=graphics`.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-avm1-function.patch` + `w2-avm1-function-report.md`
(NEW files first; ledger; refutations; unclaimed leads). Copy to the main tree if allowed.
Runtime-only → copying `SWFRecomp/build` is valid.
