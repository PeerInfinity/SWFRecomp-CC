# getvariable-vN Investigation Plan
<!-- TESTS: getvariable-v5, getvariable-v6, getvariable-v7, getvariable-v8 -->

Last updated: 2026-05-19 (initial planning doc, drafted from local
single-test reproductions at the current `master` SHA; partial work
already landed inline in SUBTESTS_NEWLY_VISIBLE_TRIAGE 2026-05-16
(+38 raw lines via colon-path validator). This plan covers the
residual 3-4 lines per version.)

<!-- PLAN_META
id: GETVARIABLE_VN_PLAN
status: pending
phases:
  - id: 1
    name: "Local `var xx` shadowing of `/:xx` setvariable (func_obj pattern)"
    status: pending
  - id: 2
    name: "Function called through path: `this.num` vs scope `num` resolution"
    status: pending
  - id: 3
    name: "Line 105 PASS-where-Gnash-expected-FAILED divergence"
    status: pending
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac)."
  - id: SUBTESTS_NEWLY_VISIBLE_TRIAGE
    reason: "Inline fix 2026-05-16 (commit d89f9994) added the Ruffle-style colon-path validator that raised v5/v6/v7/v8 by 38 lines combined. This plan covers what remains."
related:
  - id: FUNCTION_VN_PLAN
    reason: "Phase 1 here is superficially similar to FUNCTION_VN_PLAN Phase 6 (eval-stack survival) but the root cause is different: this is scope-chain shadowing on path-name reads, not eval-stack truncation."
blockers: []
status_note: |
  All four versions share the same 3-line residual diff. After the
  SUBTESTS_NEWLY_VISIBLE_TRIAGE 2026-05-16 inline fix, only 3
  lines remain on each version. Plan is small but worth its own
  doc so it doesn't get lost inside FUNCTION_VN_PLAN.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15, after the
SUBTESTS_NEWLY_VISIBLE_TRIAGE 2026-05-16 inline fix landed):

| Test | Match | % | Status |
|------|-------|---|--------|
| getvariable-v5 | 52/58 | 89.7% | output_mismatch |
| getvariable-v6 | 58/64 | 90.6% | output_mismatch |
| getvariable-v7 | 59/64 | 92.2% | output_mismatch |
| getvariable-v8 | 59/64 | 92.2% | output_mismatch |

The residual diff is essentially identical across all four versions
(3 lines + the trailing `#passed`/`#failed` counters).

## Test source

Gnash testsuite/actionscript.all/getvariable.as (~700 lines).
Exercises raw `ActionGetVariable` / `ActionSetVariable` bytecode via
inline `asm{}` blocks targeting variable paths in many flavours:

- Local variables, `_root.X`, `_level0.X`, slash-paths
- `/:varname`, `_root:varname`, leading/trailing colons
- Function-scope-chain lookups
- Multi-step path resolution (`/a/b/c:varname`)

## Residual failures (3 lines)

### Phase 1. Local `var xx` shadowing of `/:xx` setvariable

Lines: 624.

```
- PASSED: xx == 1 [./getvariable.as:624]
+ FAILED: expected: 1 obtained: 2
```

Test source (getvariable.as:616-626):

```
function func_obj()
{
    var xx = 1;
    asm {
        push '/:xx'
        push '2'
        setvariable
    };
    check_equals(xx, 1);
    check_equals(_root.xx, 2);
}
func = new func_obj();
func();
```

The `asm{}` `setvariable` writes `_root.xx = 2`. Then the bare `xx`
read should resolve to the **local** `xx = 1` (declared by
`var xx = 1` in the function activation). We are reading `2`,
suggesting our bare-name read for `xx` is hitting `_root.xx` instead
of the local activation slot.

Two possible root causes:

- `var xx = 1` isn't creating an activation slot — the assignment
  lands on `_root` via the SetVariable fallback, then the path-
  setvariable overwrites it.
- The bare `xx` read isn't checking the local activation before
  falling through to scope chain / globals.

Diagnose by tracing `actionDefineLocal` for `xx` followed by both
the path-setvariable and the bare-name GetVariable for `xx`.

Note: the next line, `check_equals(_root.xx, 2)`, PASSES — so
`_root.xx` was correctly written; the bug is only on the local-
shadow read side.

### Phase 2. Path-call function `this.num` resolution

Lines: 649, 686.

```
- PASSED: checkpoint == 5 [./getvariable.as:649]
+ FAILED: expected: 5 obtained: 7
- PASSED: checkpoint == 4 [./getvariable.as:686]
+ FAILED: expected: 4 obtained: 7
```

Test source (lines 637-686):

```
num = 7;
func = function() { return this.num; };
o = new Object;
o.func = func;
o.num = 5;
asm { push 'checkpoint' push 0 push '_root.o.func' callfunction setvariable };
check_equals(checkpoint, 5);   // we get 7

// ... similar with `this["o2.m.func"]` and a function literal ...
asm { push 'checkpoint' push 0 push 'o2.m.func' callfunction setvariable };
check_equals(checkpoint, 4);   // we get 7
```

When `_root.o.func` is invoked via `callfunction` with the
slash-dotted-path string, `this` inside the callee should be bound to
`_root.o` so `this.num` returns `5`. We are returning `7`, which is
the value of `_root.num` — meaning `this` is binding to `_root`, not
to `_root.o`.

This is `actionCallFunction`'s path-parsing logic: when the function-
name argument contains `.` or `/`, the prefix (everything before the
last `.`) should resolve to the receiver, and `this` should bind to
that resolved receiver. We are correctly resolving `_root.o.func` to
the function (otherwise the call would no-op), but losing the
receiver in the process.

### Phase 3. Line 105 PASS-where-Gnash-expected-FAILED

Line: 105.

```
- FAILED: expected: 5.4 obtained:  [./getvariable.as:105]
+ PASSED: checkpoint == 5.4 [./getvariable.as:105]
```

We are MORE correct than Gnash's expected output: we PASS,
Gnash expected FAIL. Gnash's `output.fpN.txt` records Gnash's own
buggy behaviour here, not Flash's. Confirm by comparing against
`output.fpN.ruffle.txt` for this line — if Ruffle also passes (line
105 is in Ruffle's diff against expected), our subset-match should
already cover this line and it shouldn't be counted as a fail.

Investigation: run

```
diff /home/robert/CC/SWFRecomp-CC/ruffle-tests/tests/swfs/from_gnash/actionscript.all/getvariable-v5/output.fp9-14.txt \
     /home/robert/CC/SWFRecomp-CC/ruffle-tests/tests/swfs/from_gnash/actionscript.all/getvariable-v5/output.fp9-14.ruffle.txt
```

and see whether Ruffle's expected line 105 matches Flash (`FAILED:
expected: 5.4 obtained:`) or matches our PASS. If matches us, the
test is auto-promotion-eligible once Phases 1+2 land. If matches
Flash (we are an outlier), add to RUFFLE_VS_FLASH_DIFFERENCES.md or
ACCEPTED_DIFFS.md depending on which is "correct".

## Recommended fix order

1. **Phase 3 (line 105 promotion check)** — 10 minutes, no code
   change; just verifies whether subset-match works after the other
   two phases.
2. **Phase 1 (`var xx` shadow)** — 1-2 hours. Tracing
   `actionDefineLocal` should expose the bug quickly.
3. **Phase 2 (path-call `this` binding)** — 2-3 hours. Touches
   `actionCallFunction`'s path-parsing receiver logic; verify against
   AVM1 `function_base_clip` and similar tests to prevent regression.

Total estimate: 3-5 hours, 1-2 sessions. Could plausibly promote all
four tests to PASS, or at least `ruffle_matched`.

## Promotion plumbing

All four tests have `known_failure = true` + `output.fpN.ruffle.txt`
sidecars; subset-match will auto-promote to `ruffle_matched` once our
diff is within Ruffle's diff against the expected file.
