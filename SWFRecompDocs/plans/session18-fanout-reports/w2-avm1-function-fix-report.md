# w2-avm1-function — FIX for the `Number-v5` regression from `32651c856`

Worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-ae699268626606b03`, detached at
**`9ce3c9134`** (current master, contains `32651c856`). No commits, no pushes.
`SWFRECOMP_COMPILE_TIMEOUT=2400`, `xargs -P 4` (machine idle), no-graphics.

## Deliverables

- `SWFRecompDocs/plans/session18-fanout-reports/w2-avm1-function-fix.patch` (NEW)
- `SWFRecompDocs/plans/session18-fanout-reports/w2-avm1-function-fix-report.md` (NEW, this file)

One file touched: `SWFModernRuntime/src/actionmodern/action.c` — 43 insertions / 16 deletions, all
inside the `builtin_wrapper_valueOf` region plus one added line at each of the two
`String.prototype["valueOf"]` installation sites. **No change to F1 (`PROPERTY_FLAG_PERM_DONTENUM`)
or F2 (`applyGlobalFunctionProtoLink`)** — neither was implicated.

## Verdict

**Fixed.** `Number-v5` is back to `ruffle_matched` at exactly its pre-`32651c856` line count
(236/244), and `Function-v6/-v7/-v8` still `pass`. Both `String-v6` and `Function-v5` keep the +1
Flash-matching line the original patch bought them (their actual output is byte-identical to the
`32651c856` capture).

## Which hunk leaked, and why it is not a version gate

**F3 (`builtin_wrapper_valueOf`).** F2 was never a candidate: `applyGlobalFunctionProtoLink` runs
only in `actionDefineFunction`/`actionDefineFunction2` (SWF-defined functions) and only when the SWF
has replaced `_global.Function`; `Number` is a builtin `ASFunction` and `Number.as` never touches
`_global.Function`. F1 sets its bit at one site (the `arguments` object) and is read only by the
ARRAY for-in walkers.

The delta the CI flagged is 3 checks, not 9. `Number-v5`'s pre-patch output already differed from
Flash on 8 lines — **exactly Ruffle's 8** (125, 131, 133, 138, 139, 140 + the two Dejagnu totals),
which is why it graded `ruffle_matched`. `32651c856` added 3 *new* diff indices, breaking the subset:

| Number.as | check | pre-`32651c856` | at `32651c856` |
|---|---|---|---|
| :333 | `Number.prototype == Function` | PASSED | FAILED `obtained: [object Object]` |
| :335 | `Number.prototype == null` | PASSED | FAILED `obtained: [object Object]` |
| :336 | `Number.prototype == undefined` | PASSED | FAILED `obtained: [object Object]` |

(The other six lines in the coordinator's list — 125, 332, 334, 345, 346, 347 — were already failing
at `8f68a5fea` and are in Ruffle's diff set too; only their `obtained:` *text* moved. They are not
part of the regression.)

Mechanism: at SWF5 `_global.Function` does not exist, so `Number.prototype == Function` is really
`Number.prototype == undefined`; and `actionEquals2` converts the object operand with
`objectToPrimitive`. With the old `undefined` return, all three reduced to `undefined ==
undefined/null` → `true`. Returning `this` makes the converted value still an object, so
`actionEquals2`'s "still an object ⇒ false" arm fires.

**The gate is NOT the SWF version.** Flash pins both halves simultaneously:

| fixture | Flash `output.txt` |
|---|---|
| `Function-v5` :31 / `String-v5` :259 — `stringInstance.__proto__ != undefined` | **PASSED at SWF5** |
| `Function-v6` :81 / `String-v6` :289 — same check | PASSED at SWF6+ |
| `Number-v5` :131-135 — `Number.prototype == Object/Function/Object.__proto__/null/undefined` | **all PASSED at SWF5** |

So at the *same* SWF5, `String.prototype` must NOT convert to `undefined` while `Number.prototype`
must. A `g_swf_version >= 6` gate would restore `Number-v5` but re-break `Function-v5`/`String-v5`
(and would be wrong about Flash). The real distinction is the **receiver**: Flash's
`String.prototype.valueOf` and `.toString` are one implementation (that is exactly what Ruffle's
`globals/string.rs::to_string_value_of` is — one function bound to both names, with the
`//TODO: normally falls back to '[object Object]'`), so an unboxed String receiver ends at
`Object.prototype.toString`'s `"[object Object]"`. `Number.prototype.valueOf` /
`Boolean.prototype.valueOf` have no such twin and yield `undefined`.

## The fix

`builtin_wrapper_valueOf` keeps `UNDEFINED` for every unboxed receiver **except** the
`String.prototype` objects, which still return `this`. The two String prototypes (primary version
group `g_ctors[2].prototype_obj`, secondary group `g_string_constructor.prototype_obj`) record
themselves in a new file-scope `g_string_proto_valueof_self[2]` at the point where their `valueOf`
slot is installed; the `valueOf` implementation itself is still the one shared
`g_wrapper_valueOf_func`, so no registration site changes shape.

Boxed receivers (`new String("x")`, `new Number(7)`, `new Object(5)`, …) are unaffected in both
directions — they take the `valueOf_value` path.

## Verification

All runs on the fixed tree; comparison baseline is `results_graphics.json` at `8f68a5fea`
(i.e. before `32651c856`).

### The regression and the headline

| test | at `8f68a5fea` | at `32651c856` | fixed |
|---|---|---|---|
| `Number-v5` | `ruffle_matched` 236/244 | **`output_mismatch` 229/244** | **`ruffle_matched` 236/244** (diff set == Ruffle's exactly: 125, 131, 133, 138, 139, 140, 242, 243) |
| `Function-v6` | `output_mismatch` 263/271 | `pass` | **`pass`** |
| `Function-v7` | `output_mismatch` 264/272 | `pass` | **`pass`** |
| `Function-v8` | `output_mismatch` 264/272 | `pass` | **`pass`** |

### Requested re-runs

| test | before (`8f68a5fea`) | fixed |
|---|---|---|
| `Number-v5` | `ruffle_matched` | `ruffle_matched` ✅ restored |
| `Number-v6` / `-v7` / `-v8` | `pass` | `pass` |
| `Function-v5` | `ruffle_matched` | `ruffle_matched`, actual output **byte-identical to the `32651c856` capture** (keeps +1 Flash line) |
| `Function-v6` / `-v7` / `-v8` | `output_mismatch` | **`pass`** |
| `String-v6` | `ruffle_matched` 367/377 | `ruffle_matched` 368/377, **byte-identical to the `32651c856` capture** |
| `Object-v5` | `ruffle_matched` | `ruffle_matched` |
| `Object-v6` | `ruffle_matched` | `ruffle_matched` |
| `Boolean-v6` | `pass` | `pass` |
| `Global-v6` | `ruffle_matched` | `ruffle_matched` |
| `Global-v7` | `pass` | `pass` |
| `Inheritance-v6` | `ruffle_matched` | `ruffle_matched` |
| `Date-v6` | `ruffle_matched` | `ruffle_matched` |
| **`regression` suite — all 89 tests** | `pass` | **all `pass`** |

### Extra AVM1 probes (tests that touch both halves of the narrowed behaviour)

`avm1/boxed_primitives`, `avm1/native_objects_swf8`, `avm1/string_coercion`,
`avm1/object_string_coerce_swf6`, `avm1/coerce_to_primitive_resolve`, `avm1/arguments`,
`avm1/string_methods`, `avm1/object_prototypes` — all `pass` (unchanged).
`avm1/native_objects_swf6` `output_mismatch` with its single baseline diff line
(`new TextField(): native` vs `non-object: undefined`), i.e. unchanged at 114/115.

Not re-run (unchanged by this patch and green at `32651c856`): the remaining 12 `avm1` canaries and
the 5 `from_shumway/avm1` canaries from the original 131-row ledger.

### Suggested CI gate

`gh workflow run ruffle-tests.yml --ref master -f mode=graphics` (default `categories=all`,
`images=false`). Nothing AVM2 changed, so `categories=full` is not required.

## Self-criticism / what I got wrong the first time

The original canary set included `Number-v6` but **not `Number-v5`**, and no `*-v5` test at all
except `Function-v5` — which by luck moved in the *good* direction. gnash's `-vN` families encode
version-specific expectations in `#if OUTPUT_VERSION == 5` blocks, so for any change to a shared
primitive-coercion path the v5 sibling is the discriminating row, not the v6 one. Rule for future
slices touching `valueOf`/`toString`/prototype identity: **canary the whole `-v5/-v6/-v7/-v8` family
of every gnash class whose prototype the change can reach**, not one representative.

Second miss: I reasoned from Ruffle's `to_string_value_of` TODO to "unboxed wrapper valueOf falls
back", but that function is String-only in Ruffle. `globals/number.rs::value_of` returns
`Value::Undefined` with no TODO — the asymmetry was visible in the source I had already read, and I
generalised past it.
