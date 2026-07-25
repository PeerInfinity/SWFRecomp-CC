# from_avmplus Suite — Current Status

Last updated: 2026-07-25 — **Date arc landed, CI-confirmed**. The
Adobe Tamarin/avmplus acceptance suite (1574 tests, 100% AVM2) was imported
2026-07-24 and baselined in both CI modes at `eabb3b366`:
**871/1574 effective (55.3%)**, identical in graphics and no-graphics.

Four fixes have landed since:

1. `d36c8da2b` — root SymbolClass must inherit Sprite → trace TypeError
   `#2023`. e4x **2/177 → 160/177**.
2. `127a5f4d3` — the two AVM2 String semantics bugs (below).
   `ecma3/Unicode` **6/108 → 107/108**, **+101**, CI `30126336695`.
3. `d90353066` — ES3 `.prototype` surface on builtins + `Function.length`
   for natives. `ecma3/String` **47/83 → 70/83**, **+36**,
   CI `30128240863`.
4. `17c19040c` — guard prototype `toString`/`valueOf` against
   self-coercion recursion (a crash *introduced* by 3; see below).
   **+7**, corpus segfaults **17 → 3**, CI `30130444073`.
5. `da35e5d77` — the full `Date` class (below). **+171** here (+2 in the
   avm2 suite), `ecma3/Date` **2/153 → 152/153**, CI `30134726316`
   (30/30 shards).

The suite stands at **1345/1574 effective (85.5%)**; the corpus at
**3642/4414 (82.5%)**. **Zero pass→fail regressions across all four runs.**

(Run `30130444073` lost shard 29/30 to the apt/Vulkan flake, so its own
file reads 1143/1522 — 52 from_avmplus tests ungraded. 1174 = the
full-shard 1167 from run `30128240863` plus the 7 this run gained on the
intersection. `ecma3/Unicode` scored **96/96** of the 96 that ran.)

⚠️ **Read the shard caveat before comparing to older numbers.** The
*previous* run (`30121943045`) lost shard 25/30 to the known apt/Vulkan
flake (`graphics-ci-aptget-flaky-shards`), so 52 from_avmplus tests (137
corpus-wide) were never executed and its totals read 1522, not 1574. Run
`30126336695` restored them. A naive run-to-run diff therefore shows ~137
extra "newly passing" tests that are **shard recovery, not yield** — 98 of
the recovered tests were already effective. The +101 figure above is
computed only over tests present in *both* runs, which is the only
comparison that means anything across a flaked run.

The corpus-wide ranking this baseline feeds is
`SWFRecompDocs/plans/feature-priority-map.md`.

## What this suite is

Adobe's acceptance suite for avmplus (the Tamarin VM that became Flash
Player's AVM2). Pure **language and builtin** coverage — no display list, no
input, no graphics. Every test is a trace test with a Flash-generated
`output.txt`. That makes it the corpus's sharpest instrument for
"which ECMAScript/AS3 builtin have we not implemented", in contrast to the
`avm2` suite (Ruffle-authored), whose failures are dominated by *platform*
APIs (Loader, sockets, PixelBender, Stage3D, focus/input).

Structure: `ecma3` 800 · `as3` 509 · `e4x` 177 · `regress` 55 · `misc` 14 ·
`mops` 13 · `recursion` 6. Test names are nested paths
(`ecma3/String/substr`), so the feature axis is just the first two path
components.

Upstream marks **74 tests `known_failure = true`** (Ruffle fails them too).
25 of those already grade `ruffle_matched` (our diff ⊆ Ruffle's); the other
49 are real ceiling, not gaps — the docs annotate them `(KNOWN_FAILURE)`.

## Running it

```bash
# One test (never run the suite locally)
python3 ruffle-tests/verify_output.py \
    --tests-dir=ruffle-tests/tests/swfs/from_avmplus \
    --test=ecma3/String/substr --diff --verbose

# Full suite — CI only
gh workflow run ruffle-tests.yml --ref master \
    -f mode=graphics -f categories=from_avmplus
```

`categories=all` (the per-change default) does **not** include this suite —
`categories=full` does, and so does the weekly Sunday canary. Dispatch
`full` for any change touching AVM2 runtime or recompiler emission.

## Baselines

Import baseline `eabb3b366` and current `da35e5d77` — both complete
(30/30 shards), graphics mode:

| Area | at import | now | failing now |
|---|---|---|---|
| ecma3 | 402/800 | **701/800** | 99 |
| e4x | **2/177** | **160/177** | 17 |
| as3 | 410/509 | **427/509** | 82 |
| mops | 0/13 | 0/13 | 13 |
| regress | 43/55 | 43/55 | 12 |
| recursion | 1/6 | 1/6 | 5 |
| misc | 13/14 | 13/14 | 1 |
| **total** | **871/1574** | **1345/1574** | **229** |

Status breakdown of the 229: 207 output_mismatch, 16 runtime_error,
3 timeout, 2 segfault, 1 compile_fail.

`ecma3/Unicode` is now **107/108**. The single holdout is `utf8count` —
see "Known residue" below.

At import, 263 of the 703 failures were missing **exactly one** output
line — 155 of them the e4x root-link line, now fixed.

Top feature areas by failing count (auto-generated in
`FAILING_TESTS_BY_FEATURE.md`; `x/y` = failing of tests run):

| Failing | Area | Root cause |
|---|---|---|
| 29/55 | `as3/Types` | `Number` static math (API 680) missing |
| 15/60 | `as3/Vector` | assorted |
| 15/21 | `ecma3/FunctionObjects` | `Function.prototype.*` / `.length` |
| 15/53 | `ecma3/Number` | `toString` rounding |
| 14/51 | `as3/RuntimeErrors` | error-message wording |
| 13/13 | `mops` | Alchemy `li*`/`si*` domainMemory opcodes |
| 10/83 | `ecma3/String` | `[object Function]` classification residue |
| 9/46 | `ecma3/Exceptions` | assorted |
| 8/21 | `ecma3/GlobalObject` | `encodeURI`/`decodeURI` family missing |
| 8/27 | `ecma3/ObjectObjects` | `[object Function]` classification |
| 7/212 | `as3/Definitions` | error-message wording |
| 7/51 | `ecma3/Array` | assorted |
| 6/29 | `ecma3/Boolean` | assorted |
| 17/177 | `e4x` (all dirs) | residue after the `#2023` fix |

`ecma3/Date` is now **152/153** and `ecma3/Unicode` **107/108**; both have
dropped off this table.

## The "empty output" pattern — SOLVED (it is not one bug)

287 failing tests produced ≤1 output line. The working hypothesis was one
shared driver/startup failure. **It is not.** The avmplus driver builds its
whole testcase array eagerly at script-init time:

```as3
var testcases = getTestCases();   // every Assert.expectEq() call runs here
```

`Assert.expectEq` prints as it goes, so a **single uncaught error anywhere
in that eager build aborts the script and suppresses every remaining line**.
One missing builtin therefore blanks a whole test — and, because the tests
are grouped by builtin, a whole directory.

The causes are distinct, per-builtin, and each is a separate arc:

| Uncaught error at script init | Missing thing | Blanked tests |
|---|---|---|
| `TypeError #1006: getTimezoneOffset/setTime is not a function` | `Date` methods | ~151 (`ecma3/Date`) |
| `TypeError #1010: … (accessing field: length)` on `X.prototype.m.length` | ES3 methods on builtin `.prototype` objects | ~35 (`ecma3/String`, `Array`, `FunctionObjects`, `Boolean`, `ObjectObjects`, `Number`) |
| `TypeError #1006: abs/sin/… is not a function` | `Number` static math (API 680) | 21 (`as3/Types/Number`) |
| `ReferenceError #1065: Variable encodeURI/decodeURI/decodeURIComponent is not defined` | global URI functions | ~6 (`ecma3/GlobalObject`, `regress`) |
| `ReferenceError #1065: Variable Capabilities is not defined` | `flash.system.Capabilities` | 2 (`as3/Vector/nonindexproperty`) |
| `ArgumentError #1063: Argument count mismatch on Test()` | root SymbolClass linking | 175 (all of `e4x`) — **FIXED** |

**Caveat on the seed list.** `BASELINE_SEED_2026-07-24.md` classified
"empty actual" as `actual_lines <= 1`, which also swept up genuine
single-assertion tests that ran fine and printed one `FAILED!` line
(`ecma3/Boolean/e15_6_3_1_2`, `ecma3/Statements/e12_10`, …). Those are
ordinary one-line diffs, not blanked tests.

**Instrumentation added this session** (`verify_output.py`): every result
entry now carries `error_signature`, the first `AVM[12] uncaught error:`
message from the run's stderr, and `generate_failing_by_feature.py` emits a
"Failing Tests by Uncaught Error" table from it. After the next CI run that
table replaces all of the sampling above with an exact histogram — never
re-derive this by hand.

## Fix landed: root SymbolClass must inherit Sprite (`d36c8da2b`)

Ruffle `avm2.rs lookup_class_for_character`: a SymbolClass binding whose
character id names no character (i.e. the char-0 root binding) requires the
class to have `Sprite` in its chain; otherwise linking fails with
`TypeError #2023` and the root stays a plain `MovieClip`. Flash and Ruffle
in Debug player mode (which the test runner uses) **trace** that error, so
it is the last line of the expected output.

177 from_avmplus tests declare `public class Test {}` with no base class and
ship that line (175 e4x + 2 `as3/Vector`). We instead constructed the
non-DisplayObject root class with the stage as its sole argument, which
threw `ArgumentError #1063` to stderr and printed nothing — costing exactly
one line. 155 of the 175 failing e4x tests were missing *only* that line.

The Ruffle-authored `avm2` suite is unaffected: its char-0 bindings resolve
to `test_fla.MainTimeline` or to a `Test` class that does inherit Sprite in
the compiled ABC (verified: `regexp_constr`, `boolean_constr`,
`stage_framerate_zero`, `set_property_is_enumerable` all still pass, despite
`public class Test {}` in their visible source).

CI run `30121943045` (graphics, `categories=full`) confirms:
**156 newly passing here** (155 e4x + `as3/Vector/concat`), 3 promoted to
`ruffle_matched`, and **4 in the avm2 suite** that were also one line short
of the same message (`parse_float`, `string_concat_fromcharcode`,
`string_slice_substr_substring`, `xml_basic`). **No regressions in any
suite.**

## Fix landed: String/Unicode semantics (`127a5f4d3`)

Two independent AVM2 String bugs, both visible in *every* `ecma3/Unicode`
test (which is why the whole directory sat uniformly at 16/21 or 17/21
matching lines).

**1. `search`/`match` did not coerce the pattern to a string.**
`pattern_to_regexp` (`avm2_regexp.c`) handed the raw `Avm2Value` to the
RegExp constructor. `regexp_init_from_args` correctly maps `undefined` to
the **empty** pattern per ECMA-262 §15.10.4.1 — and an empty pattern
matches at index 0. So `search(undefined)` returned `0` and
`match(undefined)` returned `""`. Ruffle (`globals/string.rs::search`,
`match_internal`) calls `coerce_to_string()` *before* constructing, making
the pattern the literal string `"undefined"`, which never matches → `-1`
and `null`. Fixed in `pattern_to_regexp`, whose only two callers are those
two paths; `replace` deliberately omits the coercion and does not use this
helper.

**2. `String.split('')` split by UTF-8 byte, not UTF-16 code unit.**
`avm2_string_split_plain`'s empty-delimiter branch iterated `i < s->len`
(the byte length) and pushed 1-byte substrings. Measured: U+0080–U+00FF
gave **256** elements instead of 128; U+4E00–U+4EFA gave **753** instead
of 251. ASCII was unaffected, which is exactly why `u0000_BasicLatin`
scored 17/21 while every other block scored 16/21. Now mirrors `charAt`:
iterate `utf16_length(s)` units via `utf16_unit_at`, honouring `limit`,
including the astral case (a 4-byte codepoint is two code units, each a
lone surrogate surfaced as U+FFFD).

**Result (CI `30126336695`): +101, all in `ecma3/Unicode` (6/108 →
107/108), zero regressions corpus-wide.**

## Known residue: `ecma3/Unicode/utf8count` needs lone surrogates

The one `ecma3/Unicode` test still failing is **not** the same class of
bug and is **not cheap**. It builds a string by concatenating
`String.fromCharCode(c)` over a list that includes surrogate *pairs*
(U+20A1F, U+20BB7 …) and asserts it equals the equivalent UTF-8 literal:

```as3
str_utf16 += String.fromCharCode(c);          // one code unit at a time
var str_utf8:String = "123𠮟咤ABC𠮷野屋abc南巽駅";
Assert.expectEq("str_utf8 == str_utf16", true, str_utf8 == str_utf16);
```

`Avm2String` is UTF-8, which cannot represent an unpaired surrogate, so
each half collapses to U+FFFD at `fromCharCode` time and the two never
recombine on concatenation. Only the equality line fails — the adjacent
`.length` comparison already passes. Fixing this properly means either a
WTF-8 representation or surrogate-pairing at concatenation time. It is a
representation change, not a one-line fix, and should be scoped on its own
rather than folded into a String arc.

## Fix landed: ES3 `.prototype` surface + `Function.length` (`d90353066`)

`String`/`Array`/`Number`/`Boolean`/`Function` registered **zero**
prototype functions, so Tamarin's standard opening assertion
`X.prototype.<m>.length` threw `TypeError #1010` at script-init and
blanked whole files. Now registered, mirroring Ruffle's
`globals/{String,Array,Number,Boolean,Function}.as`.

Four things worth remembering:

- **The impls needed no change.** They already read the receiver through
  a coercing `this_*()` helper, so a *foreign* `this` works — which is
  exactly what these tests do
  (`Number.prototype.split = String.prototype.split`). This is why
  `esplit_002` and `ematch_004` were never a String/Unicode problem.
- **`prototype.split` must point at the regex-aware `string_split_regex`**
  (`avm2_regexp.c`), not the plain impl String registration seeds it with
  — same as the class-vtable patch already done there.
- **`Function.length` was hardcoded 0 for natives.** `fn_get_length`
  reads `param_count` off the ABC method and natives have none. Added a
  native-only `param_count` field on `Avm2MethodRef` plus
  `avm2_proto_add_function_n` / `avm2_builtin_add_global_fn_n`.
- **Take arities from the corpus, not from ECMA-262.** The spec says
  `String.prototype.concat.length` is 1; Flash/Ruffle say **0** (rest
  param) and the tests assert 0. `indexOf`/`lastIndexOf` are 2 where the
  spec says 1. One command gives the ground truth:
  ```bash
  grep -rhoP '"\w+\.prototype\.\w+\.length",\s*\d+' \
      ruffle-tests/tests/swfs/from_avmplus/ | sort -u
  ```
  Written up as a replicated Flash quirk — **do not "correct" these to the
  spec values**: `avm1/_investigation/FLASH_BUGS_REPLICATED.md`
  §"[AVM2] `Function.length` on builtins deviates from ECMA-262".

**+36, CI `30128240863`.** `ecma3/String` 47/83 → 70/83.

## Post-mortem: the crash that "zero regressions" hid (`17c19040c`)

`d90353066` put `toString`/`valueOf` on the prototypes using the **class
method** impls, which coerce their receiver. But the receiver of
`String.prototype.toString()` **is `String.prototype`** — a bare
`Avm2Object` with no primitive value. Coercing it looks up `toString` on
it, re-entering the same function, until the stack dies. `Number` is the
same via `valueOf`: `number_value_of` returns `this_val` unchanged, so
`coerce_to_number` loops.

This crashed 12 tests — `ecma3/String/{e15_5_4, e15_5_4_2_1,
e15_5_4_2_rt, e15_5_4_3_1, localeCompare_rt}`,
`ecma3/Number/{e15_7_4_2_1_rt, e15_7_4_2_2_rt, e15_7_4_3_1_rt,
e15_7_4__1_rt, toLocaleString_rt}`,
`ecma3/Exceptions/{number_001_rt, string_001_rt}`.

⚠️ **All 12 were already failing as `output_mismatch`, so nothing crossed
the pass/fail line and a transition-only diff reported "zero
regressions".** The only signal was the status histogram: from_avmplus
`segfault` went **2 → 14**. *Always diff the status histogram, not just
the pass sets.*

Fix: dedicated prototype impls that never coerce. In avmplus the builtin
prototypes **are** instances carrying the default primitive value, and
the tests assert exactly that — `String.prototype.toString()` is `""`,
`Number.prototype.valueOf()` is `0`, `Number.prototype.toString()` is
`"0"` — so a wrong-type receiver yields that default. `Boolean` needed no
guard: `avm2_coerce_to_boolean` never calls back into user code.

Confirmed by CI `30130444073`: corpus segfaults **17 → 3**,
runtime_error **21 → 7**, **+7**, no pass→fail regressions. (The run
also showed `avm1/array_shift` pass→timeout; it passes locally with 0.01s
run time and this change is AVM2-only, so that is a slow-runner flake.)

**Watch for this on any future builtin that gains ES3 prototype methods —
`Date` is next and has both `toString` and `valueOf`.**

## Fix landed: the full `Date` class (`da35e5d77`)

`Date` was a three-method stub (`getTime`/`valueOf`/`toString`) bolted onto
`avm2_amf.c` so AMF round-trips could carry a timestamp. Replaced by
`SWFModernRuntime/src/avm2/avm2_date.c`: the ECMA-262 §15.9.1 algebra, 18
getters, 14 setters (local + UTC), `getTimezoneOffset`, `setTime`, six string
formats, `toJSON`, `Date.parse`, `Date.UTC`, the 0/1/2-to-7-argument
constructor, `Date(...)`-as-a-function, and the 18 AS3 accessor properties.

**Yield (CI `30134726316`, 30/30 shards): +171 here, +2 in the avm2 suite
(`date`, `date_parse`), zero pass→fail regressions corpus-wide.** Exactly the
171 + 2 the feature map predicted from the `error_signature` histogram. On the
full 4414-test corpus vs the last complete run (`14b57c476`): effective
**3462 → 3642**, `runtime_error` flat at 21, `timeout` flat at 4, `segfault`
**17 → 3** (that part is the recursion guard, not this arc).

Where the 171 landed: `ecma3/Date` **150** (2/153 → 152/153),
`as3/Definitions` **14**, `ecma3/Exceptions` **2**,
`ecma3/TypeConversion` **2**, `ecma3/GlobalObject` **1**, `ecma3/Array` **1**,
`ecma3/JSON` **1**. The last four were not predicted — small bonuses from
tests that merely *constructed* a Date on the way to something else.
`ecma3/String/e15_5_4_6_2_rt` was predicted to flip and did not: it went from
blanked to **230/232**, held back by the unrelated `[object Function]`
classification item.

Four things worth remembering:

- **The non-coercing receiver rule is Flash's own semantics, not just a
  crash workaround.** Every prototype-facing method resolves through
  `avm2_date_ext_of()`, which returns NULL for a foreign receiver.
  `ecma3/Exceptions/date_00{1,3,4}_rt` assert exactly that: a borrowed
  `Date.prototype.toString` on a plain object yields `"Invalid Date"`, and
  `valueOf`/`getTime` yield `NaN` — no throw. A coercing helper would both
  fail those tests *and* infinitely recurse when the receiver is
  `Date.prototype` itself.
- **A borrowed receiver still has to hold state.** `e15_9_5_23_3_rt` does
  `o.setTime = Date.prototype.setTime; o.getTime = Date.prototype.getTime`
  and requires the value to round-trip on a plain object. It is kept in a
  hidden non-enumerable own property. This was the one local probe failure.
- **The string formats are pinned by round-trips, not by literals.**
  `Date.parse(d.toLocaleString())` must equal `d` *exactly* (`e15_9_5_5`),
  and `toTimeString` must equal `toString` minus `toDateString`'s prefix and
  the trailing year (`e15_9_5_4`). That rules out an AM/PM marker in
  `toLocaleString` — neither parser has a token for one. Ruffle's format
  carries one, which is likely why Ruffle marks `e15_9_5_5` `known_failure`.
- **Local time is a fixed offset, no DST term.** The harness pins
  `TZ=NPT-5:45` (`verify_output.py::run_binary`), and the avmplus Date tests
  themselves assume a single whole-run offset — they derive one `TZ_DIFF`
  from `new Date(2000,1,1).getTimezoneOffset()` and adjust every hard-coded
  PST result array by it. A per-timestamp DST lookup would disagree with the
  tests in any zone that has DST.

`getYear`/`setYear` are deliberately absent: `ecma3/Expressions/e11_2_1_1`
asserts `typeof Date.prototype.getYear == "undefined"`.

### Known residue: `ecma3/Date/e15_9_5` needs sealed builtin prototypes

The one `ecma3/Date` holdout. It requires
`Date.prototype.valueOf = Object.prototype.toString` to throw
`ReferenceError #1037: Cannot assign to a method valueOf on Date`. In avmplus
a builtin prototype **is an instance of its sealed class**, so assigning a
name that collides with a class method trait throws, while an unrelated name
(`Date.prototype.toJSON`, which `ecma3/JSON/AS3Types` assigns and expects to
*succeed*) becomes an ordinary dynamic property. Our prototypes are plain
dynamic objects, so both assignments succeed.

This is **not** Date-specific — the same histogram shows
`#1037 Cannot assign to a method toString on Array` (2 tests). Fixing it means
changing how builtin prototype objects are constructed corpus-wide, so it
should be scoped on its own. Worth ~3 tests.

## E4X is NOT a coverage gap

The probe asked whether 2/177 meant broad missing E4X. It does not: **155 of
175 failures were the one root-link line**, with every real E4X assertion
already passing. Our E4X engine (`avm2_e4x.c` / `avm2_xml.c`) handles
Tamarin's XML/XMLList/QName/Namespace/TypeConversion suites essentially in
full. e4x now stands at **160/177**; the 17-test residue (3 of them
known_failure) is ordinary polish, not an arc.

## Next arcs (expected yield)

Full corpus-wide ranking with the avm2/misc/shumway folds:
`SWFRecompDocs/plans/feature-priority-map.md`. Suite-local order:

- ~~String/Unicode semantics~~ — **DONE** (`127a5f4d3`, +101).
- ~~ES3 `.prototype` surface + `Function.length`~~ — **DONE**
  (`d90353066`, +36; crash fixed by `17c19040c`, +7).
- ~~**`Date` class**~~ — **DONE** (`da35e5d77`, **+171** here, +2 in the
  avm2 suite). Predicted 171 + 2; delivered exactly that.

**Only 44 tests are still blanked by an uncaught error** (down from ~200),
and the regenerated histogram makes the remaining order unambiguous:

1. **`Number` static math (API 680)** — 21 tests in `as3/Types/Number`,
   ~19 methods + 8 constants mirroring `Math`. Note the shape is *not* a
   plain alias: `getQualifiedClassName(Number.abs(1))` must be `"int"` while
   `Number.abs(3.14)` is `"Number"`, a no-arg call must throw
   `ArgumentError #1063`, and each has an asserted `.length`.
2. **Global URI functions** — `encodeURI` (2), `encodeURIComponent` (2),
   `decodeURIComponent` (2), `decodeURI` (1) here, plus ~3 in the avm2 suite.
3. **`flash.system.Capabilities`** — 5 tests.
4. **Sealed builtin prototypes (`#1037`)** — 3 tests: 2 on Array
   (`Cannot assign to a method toString on Array`) plus `ecma3/Date/e15_9_5`.
   See the Date residue section above; this is a change to how builtin
   prototype objects are constructed, not a per-class fix.

Two one-test items also still open: **`Variable AS3 is not defined`**
(`as3/Array/length_mods`) and **`isXMLName` undefined**
(`e4x/Global/e13_1_2_1`).

Parked: **`mops`** (13 tests, all crash/error — Alchemy `li8/li16/li32/
lf32/lf64/si*/sf*` domainMemory opcodes; needs `ApplicationDomain.
domainMemory`), and the 49 remaining `known_failure` tests.
