# avm2_typed_value_ops

Regression net for the typed-value emission lever (2026-07-19 session):
compare→branch fusion plus the inline numeric/boolean fast arms in
`avm2_ops.h`. Each case is a shape where a *naive* specialization gives a
different answer than the generic op, so this pins the semantics, not the
speed.

- **NaN branch pairs** (lines 1–9). All four comparisons are false when
  either operand is NaN, so a compare AND its negation both take the
  "false" arm. This is the landmine the lever had to respect: `iflt` and
  `ifnlt` are distinct opcodes (the ABC verifier splits them into
  `LessThan`+`IfTrue` / `LessThan`+`IfFalse`), and `!(a<b)` is NOT `a>=b`
  under NaN. The generic ops encode this via `avm2_abstract_lt` returning
  -1 and `lessequals`/`greaterequals` testing `r == 0`; the specialized C
  operators `<`, `<=`, `>`, `>=` are all likewise false on NaN.
  Also covers `NaN == NaN` (false), `NaN != NaN` (true), `NaN === NaN`.
- **Signed zero** (lines 10–13). `-0 == +0` and `-0 === +0` are true, but
  the sign must survive arithmetic — a specialization that drops it shows
  up in `1/x`. Line 12's middle value (`1/(nz*1)`) is the runtime
  multiply case; the third is the subtract case.
- **Mixed int/uint/Number widths** (lines 14–17). Operands promote to
  double before comparing; `int(-1) == uint(4294967295)` must be FALSE
  (different values after promotion) while `uint(4294967295) ==
  Number(4294967295)` is true. Includes values past 2^53.
- **`add` is not numeric** (lines 18–21). `add` may concatenate or invoke
  `valueOf`, so it deliberately keeps the generic op and gets NO fast arm;
  these lines pin that string/object/null operands still concatenate or
  dispatch. Line 22 pins that subtract/multiply/divide DO coerce (including
  from strings), which is why they are safe to specialize.
- **Boolean coercion arms** (lines 23–24). Branching on each distinct
  `coerce_to_boolean` rule (undefined, null, ±0, NaN, 1, "", "0", "false",
  object, array) exercises the fallback arm of `avm2_to_boolean_fast`, and
  the same values through `not`.
- **Unary on non-numbers** (lines 25–30). `increment`/`decrement`/`negate`
  coerce to Number first (never concatenating, unlike `add`), including
  the int-overflow wrap.

Expected output generated with the Ruffle exporter oracle
(`~/CC/ruffle/target/release/exporter test.swf /tmp/x.png --trace-log
output.txt`), then adjusted on ONE line.

## The adjusted line (pre-existing, NOT caused by this lever)

Line 12's FIRST value: the oracle prints `Infinity`, we print `-Infinity`.
The expression is `var made:Number = 0 * -1; trace(1 / made)`.

We treat AVM2 `multiply` as always producing a Number, so `0 * -1` is IEEE
`-0.0` and `1 / -0.0` is `-Infinity`. Ruffle keeps an integer `0` through
its int-by-int multiply, so it prints `+Infinity`.

**This divergence is pre-existing and lever-independent**: a HEAD build
(commit `20e22c605`, without the typed-value lever) produces byte-identical
output to the specialized build on this test, including this line — and
`-DAVM2_ARITH_VERIFY` shows the fast multiply arm and the generic
`avm2_op_multiply` agreeing on every execution. Which of the two matches
Flash Player's atom-level int multiply has NOT been established here; it is
worth a separate investigation and is out of scope for the perf lever.
The other two values on the line (runtime multiply by 1, and subtract)
match the oracle exactly.

## Rebuilding

`bash build_swf.sh` (mxmlc — AS3, not MTASC), then regenerate `output.txt`
with the exporter command above and re-apply the line-12 adjustment.
