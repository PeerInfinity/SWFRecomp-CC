# w2-avm2-json — JSON stack frames + integral-number wrapping (G1, G2)

**Patch:** `SWFRecompDocs/plans/session19-fanout-reports/w2-avm2-json.patch`
(also at `<scratchpad>/w2-avm2-json/w2-avm2-json.patch`).
**New files: NONE.** Three files modified, all pre-existing:

| file | what changed |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_json.c` | number normalization, two synthetic throw frames, leading-zero grammar |
| `SWFModernRuntime/src/avm2/avm2_error.c` | `frame_is_class_trait` now recognises NATIVE class-side methods (shared machinery — see §5) |
| `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` | one appended entry (JSON leading zeros) |

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a4cf416f04a45dc40`
(branch `worktree-agent-af491cbcaed487092`, based on `e36bca73e`). No commits.

---

## 1. Verdicts and ledger

| lead | test | before (baseline `627830f2a`) | after | Δ effective |
|---|---|---|---|---|
| G1 | `avm2/json_parse_errors` | `output_mismatch` 4/84 | **`pass` 84/84** | **+1** |
| G2 | `avm2/json_parse_numbers` (KF) | `output_mismatch` 31/131, 100 diff lines | **`ruffle_matched`** 127/131, **4** diff lines ⊆ ruffle 79 | **+1** |

**Total: +2 effective**, exactly as priced. Both wave-1 claims survive, but the
G2 *route* in the brief was wrong in one respect — see §3.

Rider (not mine to count, reported for **w1-drift**):
`from_avmplus/ecma3/JSON/adhoc` — see §4.

## 2. G1 — `json_parse_errors`, two defects, both confirmed

Wave-1's diagnosis held verbatim: all 64 content lines already matched and the
whole 80-line gap was stack frames.

1. **`JSON/parse()` should be `JSON$/parse()`.** `frame_is_class_trait`
   (`avm2_error.c:148`) opened with `if (cls == NULL || m->file == NULL || ...)
   return 0`, so a NATIVE method — which by construction has `file == NULL` —
   could never be recognised as a class-side trait and every static builtin
   frame lost its `$`. The fix is the general one wave-1 flagged as its lead
   #1, not a per-site literal: drop `m->file == NULL` from the bail and guard
   `m->fn == NULL` instead. The loop body already compares
   `file/method_index/fn`, and for a native all three are trivially the C
   function pointer plus two NULL/0 halves, so no new comparison was needed.
   Net +6 lines including the comment.
2. **Flash pushes a second frame.** `Error$/throwError()` for the
   `null`/`undefined` argument arm, `JSON$/parseCore()` for every syntax
   error. Implemented as `throw_1132_argument` / `throw_1132_syntax` wrappers
   around the existing `throw_1132`, using the established synthetic-frame
   idiom (`avm2_callstack_push_throwerror`, and a file-static
   `Avm2MethodRef{ NULL, NULL, "JSON$/parseCore", 0, 0 }`). The longjmp to the
   catch unwinds `call_depth`, so neither push needs a pop — same contract
   `m3d_interp_throw_2007` and `avm1movie_throw_2014` already rely on.

`json_parse_errors` is **84/84 pass**.

## 3. G2 — `json_parse_numbers`: the wrap is real, the route in the brief is not

### 3a. The integer wrap is a LIVE PRODUCT BUG, wider than wave-1 said
`j_deserialize` case 2 read:

```c
if (v->num == trunc(v->num) && !isinf(v->num))
    return avm2_integer(avm2_f64_to_wrapping_i32(v->num));
```

The brief called this "we wrap every INTEGRAL JSON number to i32". The damage
is wider than "integral" suggests, because *every finite double with no
fractional part* is integral — including ones written in exponent form:

| JSON literal | we returned | correct |
|---|---|---|
| `1782219299000` (a ms timestamp) | `-192128840` | `1782219299000` |
| `4294967296` | `0` | `4294967296` |
| `9007199254740991` | `-1` | `9007199254740991` |
| `1e21` | `-559939584` | `1e+21` |
| `3.4028235e38` | `0` | `3.4028235e+38` |
| `1.7976931348623157e308` | `0` | `1.79769313486231e+308` |
| `-5000000000` | `-705032704` | `-5000000000` |

So it is not only timestamps: any AS3 content parsing a JSON payload with a
large round number — a byte count, a scaled fixed-point value, a
`3.4028235e38` sentinel — got silent garbage. Any SWF using `JSON.parse` for
a server response was exposed.

The fix is Ruffle's actual rule (`core/src/avm2/value.rs:574` `Value::normalize`
+ `try_promote_f64` + `fits_in_value_integer_i32`): promote to Integer **only**
when the double round-trips bit-exactly through `i32` *and* lands in avmplus's
29-bit atom range; otherwise keep it a Number. Factored as
`json_number_value(double)` and shared with the stringify path's `js_normalize`,
which already implemented the same rule correctly — so the two halves of the
file had *disagreed* on the rule, and only the parse half was wrong.
`json_number_value` also adds an explicit `[-2^31, 2^31-1]` range guard that
`js_normalize` lacked: `(int32_t) 1e21` is C undefined behaviour, and the old
code reached it on every out-of-range value.

### 3b. REFUTATION: `ruffle_matched` is NOT reachable by wave-1's route
The brief priced the row as "wrap fix + serde's out-of-range reject + G1's
frames". The first and third are right; **the second is neither necessary nor
sufficient, and adopting it would have moved us away from Flash.**

`ruffle_subset_match` compares diff sets **by line index**, and both the
leading-zero rows and the out-of-range literal change the *line count*:

* Ruffle rejects `1.7976931348623159e308` (serde), turning one expected line
  into a four-line trace: **+3** from index 17 on.
* Ruffle *also* rejects `01` / `007` / `010`: a further **+9** from index 50.

We already rejected the leading zeros (like Ruffle) but returned `Infinity`
for the out-of-range literal (like **Flash** — that line matched `output.txt`
exactly). So after the wrap and frame fixes our shift was `+9` where Ruffle's
was `+12`, and the three-line skew landed 48 of our diff indices on lines where
Ruffle's shifted frame text *coincidentally re-aligned* with `output.txt`. Diff
count fell from 100 to 93 and the row stayed `output_mismatch`. Measured, not
predicted: `<scratchpad>/w2-avm2-json/after_json_parse_numbers.txt`.

Two ways to close the 3-line skew:

* **(A) adopt serde's out-of-range reject** — the brief's route. It matches
  Ruffle's shift exactly, but it makes us *throw* where Flash returns
  `Infinity`, i.e. it regresses a line we currently get right and makes real
  content with a huge literal fail.
* **(B) adopt Flash's leading-zero acceptance** — removes the skew at the
  source by removing *our* shift entirely.

I took **(B)**. ECMA-404 forbids a leading zero and serde enforces that; FP's
`parseCore` scans the integer part as a plain digit run, so `01`/`007`/`010`
parse as decimal 1/7/10 in Flash's own `output.txt`. (B) is strictly more
permissive, so no SWF that worked in Flash can start failing on it, whereas (A)
is strictly less permissive. Everything else in the grammar stayed strict —
`+5`, `.5`, `5.`, `0x1F`, `0o17`, `0b101`, `1_000_000`, `Infinity`, `NaN` and a
full-width `５` all still throw, because the digit run stops at the non-digit
and the enclosing parser rejects the remainder. Verified row by row in the
post-fix output. Documented in `RUFFLE_VS_FLASH_DIFFERENCES.md`.

### 3c. Result
`json_parse_numbers` is **`ruffle_matched`, 4 residual diff lines** (from 100):

```
17  Infinity                     vs 1.79769313486231e+308   (Flash overflows DBL_MAX itself)
19  4.9406564584124654e-324      vs 5e-324                  (subnormal 17-digit spelling)
38  1.1754943999999998e-38       vs 1.1754944e-38           (same family)
119 1.1111111111111105           vs 1.1111111111111112      (Flash strtod on a 270-digit literal)
```

Lines 19/38/119 are the `number_to_string` subnormal/precision family that is
already dispositioned; line 17 is a Flash quirk we do not replicate. Per the
brief I did **not** chase `pass` past `ruffle_matched`. Note that line 119 did
*not* move: we printed `1.1111111111111112` before the patch too.

## 4. `from_avmplus/ecma3/JSON/adhoc` — evidence for w1-drift (NOT my claim)

**`output_mismatch` (7 diff lines) → `ruffle_matched` (5 ⊆ 5).** After the
patch our actual output is **byte-identical to that test's
`output.ruffle.txt`**. The two rows that moved are exactly the ones the
coordinator flagged:

```
JSON.parse(-1.75e12)      FAILED! expected: -1750000000000 got: -1750000000  ->  PASSED!
JSON.parse(-1e+12)        FAILED! (same shape)                               ->  PASSED!
JSON.stringify(-1.75e12)  FAILED! got: -1750000000   ->  FAILED! got: -1750000000000.0
JSON.stringify(-1e+12)    FAILED! (same shape)       ->  FAILED! got: -1000000000000.0
```

Its four int32-truncation diffs are the same `j_deserialize` wrap: the test's
"stringify" rows are `JSON.stringify(JSON.parse("-1.75e12"))`, i.e. the parse
bug seen through a round trip, not a second defect in the serializer. I did
**not** touch the test's files and do not count its movement.

**One thing the drift agent needs to know:** the two `JSON.stringify` rows
cannot reach `PASSED!` from here, and that is by design. After the parse fix
they render `-1750000000000.0` — *exactly Ruffle's text*, because
`sb_json_number` deliberately appends `.0` to an integral Number to reproduce
serde/ryu float formatting. avmplus prints `-1750000000000`. Dropping that `.0`
is a one-line change in `sb_json_number` but it is a **Ruffle-parity decision
that governs every `json_stringify*` row**, so it belongs to whoever owns the
stringify text format, not to this slot. Unclaimed lead, §6.

## 5. Risk to shared machinery

**`frame_is_class_trait` is corpus-wide** — it decides the `$` on every AVM2
stack-trace frame that has a `bound_class`. Wave-1 flagged it as needing an
A/B sweep. I did that sweep statically and then dynamically:

* **Static:** the change can only affect a frame whose method is an entry of
  its own class's STATIC vtable. I extracted every distinct `\tat ` line from
  every `output.txt` in `avm2`, `from_avmplus`, `from_shumway`, `regression`
  and `mixed_avm` (70 tests, ~190 distinct frames) and cross-checked them
  against every `avm2_builtin_add_static_method*` registration in the runtime.
  Every native static that appears in an expected trace **already carries the
  `$`** (`Number$/_convert`, `String$/_replace`, `flash.geom::Matrix3D$/
  interpolate`, `flash.system::System$/exit`, `flash.ui::Mouse$/registerCursor`,
  `Mouse$/set cursor`, `Error$/throwError`). **Not one expected frame spells a
  native static without a `$`**, so the change has no direction in which it can
  break an existing expectation. The one near-miss —
  `flash.display::AVM1Movie/addCallback()` and `/call()` — is an *instance*
  method of `AVM1Movie`; the same two names exist as statics on
  `ExternalInterface`, a different class, whose static vtable is the only one
  scanned for that frame. `avm1movie_addcallback_call` was run to confirm.
* **Dynamic:** all 21 of those `avm2` frame tests plus the whole
  `from_avmplus/ecma3/JSON` family (12) and two `regression` AVM2 members were
  re-run post-patch (35 runs, §7). **Every one landed on its exact baseline
  status.** Nothing moved except the two rows this slot owns and
  `ecma3/JSON/adhoc`. In particular the two largest stack-trace tests in the
  corpus — `primitive_toString` (277 lines) and `primitive_valueOf` (285) —
  and `error_stack_trace` / `error_throwerror` (45 / 103) are still `pass`,
  and `number_convert_errors` (871 expected lines) is still `ruffle_matched`.

The five existing per-site `"Cls$/m"` literals are now redundant but were left
in place: each pops its own frame and pushes a `bound_class == NULL` frame that
renders verbatim through a different branch, so the general fix cannot
double-apply. Removing them is cleanup for a later slot, not this patch.

**Residual risk, stated plainly:** a class that registers the *same C function*
as both a static and an instance method would now have its instance frames
rendered with a `$`. No such registration exists today (checked), and none of
the ~190 expected frames would detect one.

`json_number_value` is file-local to `avm2_json.c`; the grammar relaxation is
confined to `jp_value`'s integer-part scan. Neither touches AVM1, the
recompiler, or rendering, so **no canary run applies** to this change class
(no `render_webgpu.c` / pipeline / geometry surface).

## 6. Sibling overlap

None textual. `w2-avm2-smalls` edits `avm2_class.c`-shaped registration paths,
`avm2_filters.c` / `avm2_pixelbender.c` and `avm2_stage3d.c`; `w2-loaders` edits
`avm2_display.c` and `swf_core.c`. I touched only `avm2_json.c` and one function
in `avm2_error.c`.

**One semantic interaction worth flagging to the coordinator:** if
`w2-avm2-smalls` lands the `Matrix3D` work, the per-site
`"flash.geom::Matrix3D$/interpolate"` literal in `m3d_interp_throw_2007` is now
redundant thanks to my `frame_is_class_trait` fix. Both spellings produce the
same text, so the two patches compose, but a future cleanup should remove the
literal rather than the general fix.

## 7. Tests run (all `--mode=no-graphics`, sequential `-P 1`, `SWFRECOMP_COMPILE_TIMEOUT=2400`)

Baselines read fresh from the run-`34648878013` results
(`.../{avm2,from_avmplus,regression}/_results/results_graphics.json`), never
copied from a brief. `--recompile` on first use of every copied test dir.

**Headlines**

| test | baseline | after |
|---|---|---|
| `avm2/json_parse_errors` | `output_mismatch` 4/84 | **`pass` 84/84** |
| `avm2/json_parse_numbers` | `output_mismatch` 31/131 (100 diffs) | **`ruffle_matched`** (4 ⊆ 79) |

**Shared-machinery sweep — 33 runs, all on baseline**

| test | baseline → after |
|---|---|
| `avm2/error_stack_trace` | pass → pass |
| `avm2/error_stack_trace_edge_cases` | pass → pass |
| `avm2/error_throwerror` | pass → pass |
| `avm2/primitive_toString` | pass → pass |
| `avm2/primitive_valueOf` | pass → pass |
| `avm2/number_convert_errors` | ruffle_matched → ruffle_matched |
| `avm2/system_exit` | pass → pass |
| `avm2/flash_ui_mouse_cursor` | pass → pass |
| `avm2/matrix3d_interpolate` | pass → pass |
| `avm2/try_catch_typed` | pass → pass |
| `avm2/uncaught_error_basic` | pass → pass |
| `avm2/uncaught_errors_stringified` | ruffle_matched → ruffle_matched |
| `avm2/avm1movie_addcallback_call` | pass → pass |
| `avm2/json_errors` | pass → pass |
| `avm2/json_parse` | pass → pass |
| `avm2/json_stringify` | pass → pass |
| `avm2/json_stringify_function` | pass → pass |
| `avm2/json_stringify_order` | pass → pass |
| `avm2/json_version_gated` | pass → pass |
| `avm2/describe_type_json` | pass → pass |
| `from_avmplus/ecma3/JSON/AS3Types` | pass → pass |
| `from_avmplus/ecma3/JSON/Callbacks` | pass → pass |
| `from_avmplus/ecma3/JSON/Classes` | ruffle_matched → ruffle_matched |
| `from_avmplus/ecma3/JSON/Invalid` | pass → pass |
| `from_avmplus/ecma3/JSON/LargeString` | pass → pass |
| `from_avmplus/ecma3/JSON/Strings` | pass → pass |
| `from_avmplus/ecma3/JSON/e15_12_0` | pass → pass |
| `from_avmplus/ecma3/JSON/e15_12_1` | pass → pass |
| `from_avmplus/ecma3/JSON/e15_12_2` | pass → pass |
| `from_avmplus/ecma3/JSON/e15_12_3` | pass → pass |
| `from_avmplus/ecma3/JSON/regress` | pass → pass |
| `regression/avm2_typed_value_ops` | pass → pass |
| `regression/avm2_tolerant_verify_quarantine` | pass → pass |
| `from_avmplus/ecma3/JSON/adhoc` | output_mismatch → **ruffle_matched** (w1-drift's row) |

`ecma3/JSON/Invalid` is the one that most directly tests the grammar relaxation
in §3b — it pins `#1132` for `'-'`, `'.'`, `'1e'`, `'1E'`, `'1.e'` and friends,
and it is still 40/40. No test in the corpus asserts that a leading zero is
rejected.

**Not run, with reasons.** `avm2/number_to_string` and `avm2/number_tostring`
(both `output_mismatch`, ACCEPTED/KF) were skipped deliberately: neither has a
single `\tat ` line in its expected output, so `frame_is_class_trait` cannot
reach them, and neither goes through `avm2_json.c`. No canary set applies
(§5). Everything was run under `--mode=no-graphics`; mode parity is complete
and nothing here touches the frame loop or a renderer.

## 8. New unclaimed leads

1. **`sb_json_number` appends `.0` to integral Numbers** (serde/ryu parity).
   avmplus does not: `JSON.stringify(JSON.parse("-1.75e12"))` is
   `-1750000000000` in Flash, `-1750000000000.0` in Ruffle and in us. One line
   in `sb_json_number`, but it re-prices every `json_stringify*` row and
   `ecma3/JSON/adhoc`, so it needs its own A/B. Owner: whoever takes the
   stringify text format.
2. **Five per-site `"Cls$/m"` frame literals are now dead weight**
   (`avm2_number.c:42`, `avm2_stage3d.c:2374`, `avm2_globals.c:6788`,
   `avm2_display.c:16011/16051/16072`). Deleting them is pure cleanup now that
   `frame_is_class_trait` handles native statics, and it would remove the
   standing foot-gun of hand-maintaining a qualified name.
3. **Flash returns `Infinity` for a JSON literal that overflows f64, and prints
   `DBL_MAX` itself as `Infinity` too** (`json_parse_numbers` line 17 — the
   literal is exactly `1.7976931348623157e308`). That is not an overflow, so
   FP's `parseCore` is apparently doing something lossier than `strtod` at the
   top of the range. One line of the row; documented, not chased.
4. **`js_normalize`'s 29-bit clamp means large round numbers are `Number`, not
   `int`, after `JSON.parse`.** That is Ruffle's and avmplus's rule and all
   observable output agrees, but any code that fingerprints `is int` on parsed
   values (the AVM2 intrinsic gate) should know the tag changed for values
   above 2^28 — they used to come back (wrongly) as Integer.
