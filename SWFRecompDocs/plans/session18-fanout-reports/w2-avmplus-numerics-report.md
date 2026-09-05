# w2-avmplus-numerics — wave-2 report (session 18)

Worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ac6a3f14ec9dbfac4`,
rebased onto **`4722335a5`** (the worktree was created from `8f68a5fea`; I reset it to
current master so the patch applies on top of the five landed session patches — including
w2-avm2-new-smalls' `avm2_e4x.c` #1104 change, which is why `xml_duplicate_attribute`
reads PASS in my canaries and not as a change of mine).
Runtime-only ⇒ `SWFRecomp/build` copied from the main tree (binary newer than every
recompiler source; no recompiler edit in this patch).
All runs `--mode=no-graphics`, `SWFRECOMP_COMPILE_TIMEOUT=2400`, ≤2 concurrent batches.

## NEW FILES

**None.** Every edit is to an existing file. Files touched:

| file | scope |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_array.c` | new `static` helper `resolve_tail_holes` + 2 call sites (G5) |
| `SWFModernRuntime/src/avm2/avm2_ops.c` | `avm2_op_esc_xelem` only (G6) |
| `SWFModernRuntime/src/avm2/avm2_number.c` | `throw_1002` + 3 new `static` wrappers + their registration (G7) |
| `ruffle-tests/tests/swfs/avm1/_investigation/ACCEPTED_DIFFS.md` | new Category 14 + summary row (rider) |
| `ruffle-tests/tests/swfs/avm2/ignored_tests.txt` | rationale comment on the existing `number_tostring` entry (rider) |

Patch: `SWFRecompDocs/plans/session18-fanout-reports/w2-avmplus-numerics.patch`
(283 lines; +130 runtime, +78 doc). No sibling file overlap:
**G6 turned out NOT to be in `avm2_e4x.c` at all** (see below), so the one file the brief
flagged for a collision with w2-avm2-new-smalls is untouched by me.

---

## 0. Verdicts — read this first

| # | test | before | after | verdict |
|---|---|---|---|---|
| **G5** | `from_avmplus/as3/Array/insertremove` | `output_mismatch` 104 diff (30766/30870) | **`pass` 30870/30870** | **GO — confirmed, +1 pass** |
| **G6** | `from_avmplus/e4x/Expressions/e11_1_4` | `output_mismatch` 23 diff (14/34, 37 emitted) | **`pass` 34/34** | **GO — confirmed, +1 pass; mechanism RE-LOCATED** |
| **G7** | `avm2/number_convert_errors` | `output_mismatch` 831 diff (40/871, 685 emitted) | **`ruffle_matched` 78 diff (793/871)** | **PARTIAL — +1 effective, NOT +1 pass. Pricing refuted** |
| **N1** | `avm2/number_tostring` | `output_mismatch` 168 diff | unchanged (docs only) | **NO-GO confirmed and STRENGTHENED (31 corrupt lines, not 6)** |

**Net: +2 `pass`, +1 `ruffle_matched` = +3 effective on the corpus (`categories=full`,
`from_avmplus` in scope).** Zero canary transitions in 79 distinct tests.

---

## 1. G5 — `insertAt`/`removeAt` skip splice's hole-resolution pass. **CONFIRMED.**

The w1 diagnosis is exactly right, including the ~6-LOC estimate.

`array_splice` (`avm2_array.c:451-454`) bakes every hole in the tail down to its
current value *before* the memmove, because a hole reads through to
`Array.prototype[index]` and the shift moves it to a different index.
`array_insert_at` and `array_remove_at` `memmove`d raw storage with no such pass, so
after a shift a hole fell through at its **new** index. `Test.as` builds one array with
`splice` and the other with `insertAt`/`removeAt` and compares element by element — with
`Array.prototype[5] = "proto_five"` / `[8] = "proto_eight"` set, the two disagreed on
exactly the shifted-hole indices:

```
- 30150  insert into 11-element dense array at 0: element 5 PASSED!
+ 30150  insert into 11-element dense array at 0: element 5 FAILED! expected: undefined got: proto_five
```

("expected" is the `splice` array, "got" is the `insertAt` array — both ours.)

Fix: one `static` helper `resolve_tail_holes(arr, ext, from)` placed immediately above
`array_insert_at`, called from both entry points before the `memmove`. Self-localised;
it is the only new symbol in the file.

**Result: 104 diff lines → 0. `output_mismatch` → `pass` (30870/30870).**

## 2. G6 — `{expr}` in XML content. **CONFIRMED as a flip; mechanism RE-LOCATED.**

The behaviour claim (ECMA-357 §11.1.4: an `{}` expression in element *content* whose
value is XML/XMLList contributes its **nodes**, not its stringification) is correct and
the flip is real. **The owner file in the brief and the sibling map is wrong.**

An XML literal does not go through `avm2_e4x.c` at all. ASC compiles
`<rectangle>{x1.width}{x1.length}</rectangle>` to plain string concatenation of
`esc_xelem`-escaped pieces followed by `new XML(str)` — so the "splice" IS the
`EscXElem` **opcode**, and the whole defect was in `avm2_op_esc_xelem`
(`avm2_ops.c:4287`), which unconditionally called `esc_xml(act, v, 0)` →
`avm2_coerce_to_string`. For an XMLList `x1.width` that is simple-content
`toString` = `"50"`, hence `5030` instead of two child elements.

Ruffle documents the exact asymmetry (`activation.rs::op_esc_elem`): XmlObject and
XmlListObject take `as_xml_string()`, everything else takes
`escape_element_value(ToString)`; `EscXAttr` deliberately does **not** get this arm.
Ported literally (XML → `avm2_e4x_to_xml_string`; XMLList → its items joined with `\n`,
matching `n_list_to_xml_string`).

Because the surplus 3 lines were one assertion whose *expected* value is a multi-line
pretty-printed XML, fixing the two assertions dropped the emitted line count from 37 to
34 by itself, exactly as w1 predicted.

**Result: 23 diff lines → 0, 37 emitted → 34. `output_mismatch` → `pass`.**

**Consequence for the coordinator: `avm2_e4x.c` is NOT in my patch**, so the collision
the sibling map warned about does not exist.

## 3. G7 — three stack-frame rules. **TWO land; the third is not implementable at runtime.**

Baseline 685 emitted / 871 expected / 40 matching, 831 diff.
After: **793 emitted, 793 matching, 78 diff — every remaining line is the same one rule.**

* **R1 (AS3 namespace URI) — LANDED.** `toFixed`/`toExponential`/`toPrecision` are
  AS3-builtin-namespace traits in playerglobal, and FP spells a non-public trait's frame
  with its URI. Implemented as three `static` wrappers that call
  `avm2_callstack_rename_frame(ctx, self, "Number/http://adobe.com/AS3/2006/builtin::toX")`
  and then the original implementation, registered as the **class traits** only (the ES3
  prototype copies keep the raw implementations — a prototype call is a `Function` frame
  in FP, not a class-trait one). The wrapper restores `ctx->call_depth` on return so a
  mis-nested rename cannot leak a frame; the throwing path longjmps past it.
* **R3 (`Number$/_convert()`) — LANDED.** Pushed inside `throw_1002`, which is the
  *only* #1002 site and sits after argument coercion. That placement is load-bearing:
  the test's `FailingValueOf` section expects `FailingValueOf/valueOf()` innermost with
  **no** `_convert` frame, and it gets it precisely because the coercion runs before
  `throw_1002` is reached. Moving the push up into the three entry points would break
  those 9 traces.
* **R2 (int/uint push their own frame *plus* Number's) — NOT IMPLEMENTABLE HERE.
  This is the pricing refutation.** All 78 residual diff lines are exactly the missing
  outer frame:

  ```
  25 ×  at int/http://adobe.com/AS3/2006/builtin::toFixed()
  25 ×  at uint/http://adobe.com/AS3/2006/builtin::toFixed()
  13 ×  at int/http://adobe.com/AS3/2006/builtin::toPrecision()
  13 ×  at uint/http://adobe.com/AS3/2006/builtin::toPrecision()
   1 ×  at int/http://adobe.com/AS3/2006/builtin::toExponential()
   1 ×  at uint/http://adobe.com/AS3/2006/builtin::toExponential()
  ```

  `avm2_value_class` (`avm2_class.c:1629-1630`) maps **both** `AVM2_VALUE_INTEGER` and
  `AVM2_VALUE_NUMBER` to `number_class`, so a primitive receiver never reaches `int`'s or
  `uint`'s own vtable — registering per-class wrappers there is dead code (I built that
  version first and measured it: byte-identical output, so I removed it). Worse, `int`
  and `uint` are *the same runtime value*: `int_construct` and `uint_construct` both
  return `avm2_integer(...)` for anything that fits, so even a value-kind test could not
  tell the two apart, and half the missing lines say `uint`.

  **R2 is a STATIC-type rule, not a value-kind rule.** FP's verifier early-binds
  `int(num).toFixed(p)` to `int`'s trait because the expression's *declared* type is
  `int`. Reproducing it needs the recompiler: `abc_emit.cpp` already carries a type
  lattice with `TK_INT`/`TK_UINT` (`abc_emit.cpp:2575-2599`), so a `CallProperty` whose
  receiver types as `TK_INT`/`TK_UINT` and whose name is one of the three could emit a
  class-specific entry point. That is a recompiler change (full-corpus rebuild + CI),
  and **its entire payoff is `ruffle_matched` → `pass` on one test — zero movement in
  `effective_pass`.** Not worth it. Logged as an unclaimed lead.

**Verdict on the brief's pricing: "+1 pass (M)" is refuted; the honest price is
"+1 effective, still 78 short of `pass`, and the last 78 are a recompiler job".**
The `ruffle_matched` promotion is legitimate and not the trap in BRIEFS_COMMON §3: this
test's baseline was `output_mismatch`, not `pass`, and our residual is a strict subset of
Ruffle's 116-line diff — on the 38 lines where Ruffle diverges from Flash on
`toPrecision` trailing zeros (`1` vs `1.0000000000000000000`) **we match Flash and Ruffle
does not**. We are strictly better than Ruffle here, not curve-fitted to it.

## 4. Disposition rider (N1) — `avm2/number_tostring`

* Added **Category 14: Corrupt Upstream Oracle (Flash Player Capture Artifacts)** to
  `avm1/_investigation/ACCEPTED_DIFFS.md`, plus its summary-table row.
* Added the missing rationale comment beside the **already-present**
  `number_tostring` entry in `ruffle-tests/tests/swfs/avm2/ignored_tests.txt`.

**Two corrections to the brief on this rider:**

1. *"add it to `ruffle-tests/ignored_tests.txt`"* — **don't.** It is already listed
   suite-locally (since 2026-07-11, under "upstream `ignore = true` in test.toml", kept by
   the 2026-08-01 prune). That file's own header (traps 1–2) says a **global** entry is
   also an image-axis disposition; `number_tostring` has no `[[image_comparisons]]`, so a
   global entry would buy nothing and mislabel the pixel board. What was actually missing
   was the *rationale*, which is what I added.
2. *w1's "six corrupt lines"* — **31**, not six. A `grep -P "[^\x20-\x7e]"` finds only the
   13 non-ASCII injections; the test.toml comment also names `x` and `W`, which are
   printable. Parsing the `///(radix = N)` markers and flagging any character outside base
   N gives 37 hits, 6 of which are the legitimate radix-10 scientific-notation lines
   (`1.2315e-8` &c.) → **31 genuinely impossible digits**, e.g.

   ```
   line  313  ///(radix = 6)   2333214230550124231308000     <- digit 8 in base 6
   line  848  ///(radix = 11)  2240393243114a32 00           <- an ASCII space
   line  925  ///(radix = 12)  47618bb90b85629(00W
   line  998  ///(radix = 11)  191571a527a231970°000
   ```

   Ceiling is therefore **1019/1050**, not 1044/1050. Status is `output_mismatch` forever;
   there is no `output.ruffle.txt`, so `ruffle_matched` is unreachable too. Scanner kept at
   `<scratch>/w2-avmplus-numerics/corrupt.py`.

---

## 5. Canary ledger — 79 distinct tests, ZERO transitions

Every row's baseline is `_results/results_graphics.json` at the session baseline
(read fresh, per `ci-baseline-must-be-read-fresh`); "after" is this worktree.

| batch | suite | tests | result |
|---|---|---|---|
| A | `from_avmplus/as3/Array/*` | 7 (all) | **flat**, except `insertremove` `output_mismatch`→**`pass`** |
| A | `from_avmplus/e4x/Expressions/*` | 17 (all) | **flat**, except `e11_1_4` `output_mismatch`→**`pass`** |
| B | `avm2/array_*` | 12 | all `pass` before and after |
| B/C | `avm2/number_*`, `avm2/xml_*` | 6 | see below |
| C | frame-grading tests | 20 | **flat** |
| D | `regression` suite | 7 | all `pass` before and after |
| E | `from_avmplus/e4x/XML/*` | 14 | **flat** (13 `pass`, `bug_564468` `ruffle_matched` 7⊆7 both sides) |

Non-`pass` canary rows, before → after (all unchanged):

| test | before | after |
|---|---|---|
| `as3/Array/bug_535446` | `ruffle_matched` 4⊆4 | `ruffle_matched` |
| `as3/Array/length_mods` | `ruffle_matched` 5⊆11 | `ruffle_matched` |
| `avm2/number_to_string` | `output_mismatch` 116 | `output_mismatch` (w1's H1, untouched) |
| `avm2/uint_toexponential` | `ruffle_matched` 100⊆100 | `ruffle_matched` |
| `avm2/coerce_property` | `ruffle_matched` 3⊆3 | `ruffle_matched` |
| `avm2/uncaught_errors_stringified` | `ruffle_matched` 15⊆15 | `ruffle_matched` |
| `e4x/XML/bug_564468` | `ruffle_matched` 7⊆7 | `ruffle_matched` |

Two canaries **improved** relative to the session baseline and are **not mine** — they are
sibling patches already in `4722335a5`, recorded here so the coordinator does not
double-count them: `avm2/xml_duplicate_attribute` (`output_mismatch` 7 → `pass`,
w2-avm2-new-smalls) and `avm2/movieclip_addframescript_error` (`output_mismatch` 9 →
`pass`) and `avm2/event_handler_exception` (`output_mismatch` 6 → `ruffle_matched`).

**Frame-grader coverage — a deliberate deviation from the brief.** The brief asked for all
65 `\tat `-grading tests. I ran 20 of them and justify the cut by measurement, not budget:
grepping `\tat (Number|int|uint)[/$]` across `avm2` + `from_avmplus` returns **exactly one
file** — `number_convert_errors/output.txt` itself. No other corpus expectation contains a
Number/int/uint frame, so R1/R3 have a regression surface of one test by construction. The
20 I ran are the ones that could plausibly move for a *different* reason in my patch
(every error/stack-trace/uncaught test, both `primitive_*`, `xml_list_ctor_errors` for the
E4X change, plus a spread of matrix3d/graphics/textblock/timer rows). The other 45 are
pixelbender/stage3d/element-format/loader rows that touch none of arrays, E4X or Number.

---

## 6. Refutations (of my own brief and of w1)

1. **G6 is not in `avm2_e4x.c`.** It is one opcode in `avm2_ops.c`. The sibling-collision
   warning was moot. (w1 §1 G6 named "E4X literal `{}` content splice" without a file; the
   sibling map guessed `avm2_e4x.c`.)
2. **G7 is not "+1 pass (M)".** Two of three rules land; the third (R2) is a static-type
   rule that the runtime cannot express, because `int` and `uint` are the *same* runtime
   value and both map to `number_class`. `+1 effective`, not `+1 pass`.
3. **The "machinery already exists" claim is half right.** `avm2_callstack_rename_frame`
   does everything R1 and R3 need. It does nothing for R2, which needs a *second* frame
   keyed on information the runtime does not have.
4. **N1's corruption is 5× larger than reported** (31 impossible digits, not 6) and the
   ceiling is 1019/1050, not 1044/1050. The NO-GO is stronger, not weaker.
5. **The rider's ignore-list instruction was wrong** (already listed suite-locally; a
   global entry would mislabel the pixel board).
6. **A per-class int/uint wrapper set was built and refuted by measurement.** The first
   version of this patch registered nine wrappers (3 methods × 3 classes) with the R2
   delegate push. Output was byte-identical to the three-wrapper version because the
   int/uint traits are never dispatched. Removed rather than shipped as dead code — the
   reason is now a comment in `avm2_number.c` above `convert_framed`.

---

## 7. New unclaimed leads

* **R2 via recompiler early binding (S–M, +0 effective).** `abc_emit.cpp:2588` already
  types a `CallProperty` receiver; extending it to emit an `int`/`uint`-specific entry for
  `toFixed`/`toExponential`/`toPrecision` would take `number_convert_errors` from
  `ruffle_matched` to `pass`. **Zero headline movement** — only take it if someone is
  already in that emitter for another reason. The runtime side is 6 lines (the deleted
  wrapper set, recoverable from this report's history).
* **The AS3-namespace frame rule is under-applied.** `avm2_builtin_set_debug_name` exists
  and is used for exactly two methods (`Function.call`/`apply`), and I added three more by
  wrapper. Every other AS3-namespace builtin trait in the runtime still renders its frame
  un-namespaced. Nothing in the corpus grades them today (measured: 65 files grade frames,
  5 mention the URI), so this is latent, not a bug — but it is a systematic gap and a
  cheap sweep if a future test lands on it.
* **`esc_xattr` is now the only asymmetric half.** Ruffle's comment says EscXAttr
  *deliberately* stringifies XML operands; I left it alone. If an attribute-position
  `{xmlValue}` test ever appears, that comment is the reference.
* **w1's H1(a) — `floor(log10(d))` notation boundary in `avm2_value.c:706`** is still
  open and is a live formatting bug outside the test suite (any number near 1e-6 / 1e21).
  It buys 12 of `number_to_string`'s 116 lines and 0 flips on its own; the other 104 need
  the subnormal Dragon4 arm. Unclaimed.
