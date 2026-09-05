# w2-avmplus-numerics — wave 2: insertAt/removeAt holes, E4X content splice, builtin stack-frame rules (+3) + one disposition

Read `BRIEFS_COMMON.md` (incl. wave-2 rules) and `SIBLING_FILE_MAP.md`, then the diagnosis of
record: `w1-trace-numerics-report.md` §1 G5, G6, G7 and §3 N1. Isolated worktree; no commits.
The corpus grading for from_avmplus needs `categories=full` — that is what the closeout run uses.

## Scope
1. **G5 `from_avmplus/as3/Array/insertremove` 30766/30870 → pass (~6 LOC):** `array_insert_at` /
   `array_remove_at` omit the `resolve_hole` tail pass that `array_splice` already has (known_failure
   upstream; `output.txt` is the target — check `output.ruffle.txt` exists? grade both).
2. **G6 `from_avmplus/e4x/Expressions/e11_1_4` 14/34 → pass:** `{expr}` in XML-literal CONTENT must
   splice XML nodes, not stringify (two assertions, one mechanism). `avm2_e4x.c` — sibling
   w2-avm2-new-smalls edits the #1104 duplicate-ATTRIBUTE path in the same file; keep to the
   content-interpolation function.
3. **G7 `avm2/number_convert_errors` 40/871 → pass (M):** three stack-frame rules — AS3 namespace
   URI in builtin frames; int/uint push their own frame PLUS Number's; a `Number$/_convert()` frame.
   The machinery exists (`avm2_callstack_rename_frame`, already passing 3 tests). The report
   measured the regression surface: 65 tests grade `at` frames — run ALL of them as canaries
   (list in the report; if not, grep `output.txt` files for `\tat ` across avm2 + from_avmplus).
   known_failure upstream → grade with `--expected-suffix=ruffle` too and report both.
4. **Disposition rider (docs only):** `avm2/number_tostring` can never pass (six corrupt lines
   in `output.txt`; upstream `ignore = true`). Add an ACCEPTED_DIFFS.md entry (Category: corrupt
   expected output) + summary-table row, and add it to `ruffle-tests/ignored_tests.txt` per
   CLAUDE.md's procedure.

## Verification
Headline: the 3 tests. Canaries: `from_avmplus/as3/Array/*` (all passing — ~40), `avm2/array_*`
(sample 8), `from_avmplus/e4x/Expressions/*` + `e4x/XML/*` passing (sample 15), the 65
stack-frame graders, and `regression` suite AVM2 tests touching arrays/E4X/errors. Byte-identical
`--diff` before/after. `-P 2`, compile timeout 2400, `--recompile` on first use.

## Deliverables
`SWFRecompDocs/plans/session18-fanout-reports/w2-avmplus-numerics.patch` + `w2-avmplus-numerics-report.md`
(NEW files first; ledger incl. the doc rider; refutations; unclaimed leads). Copy to the main
tree if allowed. Runtime-only → copying `SWFRecomp/build` is valid.
