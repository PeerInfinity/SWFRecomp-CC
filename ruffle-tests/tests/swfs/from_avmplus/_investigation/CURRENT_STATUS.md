# from_avmplus Suite — Current Status

Last updated: 2026-07-25 — **cleanup batch landed, CI-confirmed**. The
Adobe Tamarin/avmplus acceptance suite (1574 tests, 100% AVM2) was imported
2026-07-24 and baselined in both CI modes at `eabb3b366`:
**871/1574 effective (55.3%)**, identical in graphics and no-graphics.

Six fixes have landed since:

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
6. `8e8370df1` — the cleanup batch: `Number` static math, the global URI
   functions, `flash.system.Capabilities` (below). **+41** here (+5 in the
   avm2 suite), CI `30139492178` (full 4414-test intersection).

The suite stands at **1386/1574 effective (88.1%)**; the corpus at
**3688/4414 (83.6%)**. **Zero pass→fail regressions across all six runs.**

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

Import baseline `eabb3b366` and current `8e8370df1` — both complete,
graphics mode:

| Area | at import | now | failing now |
|---|---|---|---|
| ecma3 | 402/800 | **708/800** | 92 |
| e4x | **2/177** | **160/177** | 17 |
| as3 | 410/509 | **457/509** | 52 |
| mops | 0/13 | 0/13 | 13 |
| regress | 43/55 | **47/55** | 8 |
| recursion | 1/6 | 1/6 | 5 |
| misc | 13/14 | 13/14 | 1 |
| **total** | **871/1574** | **1386/1574** | **188** |

Status breakdown of the 188: 166 output_mismatch, 16 runtime_error,
3 timeout, 2 segfault, 1 compile_fail.

`ecma3/Unicode` is now **107/108**. The single holdout is `utf8count` —
see "Known residue" below.

At import, 263 of the 703 failures were missing **exactly one** output
line — 155 of them the e4x root-link line, now fixed.

Top feature areas by failing count (auto-generated in
`FAILING_TESTS_BY_FEATURE.md`; `x/y` = failing of tests run):

| Failing | Area | Root cause |
|---|---|---|
| 15/21 | `ecma3/FunctionObjects` | `[object Function]` + `Function('body')` + class-object `.length` |
| 15/53 | `ecma3/Number` | **10 = static consts are writable** (next arc); rest is `toString` rounding |
| 14/51 | `as3/RuntimeErrors` | error-message wording (namespace-qualified names) |
| 14/60 | `as3/Vector` | assorted |
| 13/13 | `mops` | Alchemy `li*`/`si*` domainMemory opcodes |
| 10/83 | `ecma3/String` | `[object Function]` classification residue |
| 9/46 | `ecma3/Exceptions` | assorted |
| 8/27 | `ecma3/ObjectObjects` | `[object Function]` classification |
| 7/212 | `as3/Definitions` | error-message wording |
| 7/51 | `ecma3/Array` | assorted; 2 need sealed prototypes (`#1037`) |
| 6/29 | `ecma3/Boolean` | assorted |
| 6/12 | `ecma3/JSON` | lexer whitespace handling |
| 5/5 | `as3/ByteArray` | LZMA compress/decompress |
| 17/177 | `e4x` (all dirs) | residue after the `#2023` fix |

`ecma3/Date` (152/153), `ecma3/Unicode` (107/108), `as3/Types` (**55/55**)
and `ecma3/GlobalObject` (**20/21**) have all dropped off this table.

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
| `TypeError #1006: abs/sin/… is not a function` | `Number` static math (API 680) | 21 (`as3/Types/Number`) — **FIXED** `8e8370df1` |
| `ReferenceError #1065: Variable encodeURI/decodeURI/decodeURIComponent is not defined` | global URI functions | ~6 (`ecma3/GlobalObject`, `regress`) — **FIXED** `8e8370df1` |
| `ReferenceError #1065: Variable Capabilities is not defined` | `flash.system.Capabilities` | 5 — **FIXED** `8e8370df1` (3 flipped; 2 now run and fail on real assertions) |
| `ArgumentError #1063: Argument count mismatch on Test()` | root SymbolClass linking | 175 (all of `e4x`) — **FIXED** `d36c8da2b` |

**All six rows are now fixed**, which is why the uncaught-error histogram is
down to 12 tests. The blanking mechanism described above still applies to any
*future* missing builtin — it is why a single gap costs a whole directory —
but it no longer describes the current failure set.

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

### Fix landed: the cleanup batch (`8e8370df1`)

Three small arcs in one commit. **CI `30139492178` (graphics,
`categories=full`, complete 4414-test intersection): +41 here, +5 in the
avm2 suite, zero pass→fail regressions and zero movement in
`segfault`/`timeout`/`runtime_error`.** The map predicted ~35 total; the
delivered 46 beat it for two reasons worth remembering.

**`Number` static math (API 680) — 27, not the predicted 21.**
`as3/Types/Number` went **3/30 → 30/30**. The histogram only counted the
21 tests blanked by `TypeError #1006`; the other six were the *constant*
tests (`e`, `pi`, `ln2`, …) plus `visibility/v16`, which failed on
ordinary line mismatches and so never appeared in the uncaught-error
table. **When an arc registers a whole API surface, the blanked count is a
floor, not an estimate** — sibling tests in the same directory that fail
for adjacent reasons come along with it.

Three shape notes, none of which is "alias `Math`":

- **Arity is declared and enforced.** A count mismatch throws
  `ArgumentError #1063` (`Number.abs()` with no args, and also
  `Number.random(12)` with too *many*), and `Number.abs.length` must
  report 1. Natives had no way to carry that, so
  `avm2_builtin_add_static_method_n` now sets `param_count` — the static
  counterpart of what `d90353066` added for prototype functions. Arities
  come from the corpus: 1 for the trig/rounding family, 2 for
  `atan2`/`pow`/`max`/`min`, 0 for `random`. `max`/`min` are variadic
  despite the declared 2 (`visibility/v16` calls both with no arguments).
- **The eight constants are getter-only static traits, not
  `avm2_builtin_add_static_const`.** `as3/Types/Number/e` asserts all four
  of read-only (`Number.E = 0` → `ReferenceError #1074`), DontDelete,
  DontEnum and the value. `add_static_const` installs a dont-enum
  *dynamic* property, which is writable and deletable — see the follow-on
  arc below, where that same gap is worth ~12 more tests.
- **SWF16 gate.** `as3/Types/Number/visibility/v15` asserts every one of
  these is still `undefined` for SWF15 content and passes *today* for the
  wrong reason (they don't exist at all). Registering them ungated would
  have turned a passing test red. `ctx->swf_version` is set immediately
  before `avm2_globals_init`, so the gate is just an `if` at registration.

Integral results needed no work: `getQualifiedClassName` already maps an
integral double to `"int"`, which is what `Number.abs(1)` → `"int"` /
`Number.abs(3.14)` → `"Number"` is really testing.

**The URI arc is an `escape` arc too.** The four new functions
(`encodeURI`, `encodeURIComponent`, `decodeURI`, `decodeURIComponent`,
ECMA-262 §15.1.3) are a straight transform over the UTF-8 bytes our
strings already are. But probing them surfaced two real `escape`/`unescape`
bugs, and fixing those is where four of the extra tests came from
(`ecma3/GlobalObject/e15_1_2_4`, `e15_1_2_5_1` — which had been sitting at
**530/531** — and the avm2 suite's `escape` and `unescape`):

- **`escape` works on UTF-16 code units, not UTF-8 bytes.** `%XX` below
  U+0100 and `%uXXXX` above, so an astral character comes out as its two
  surrogate halves: `escape("😭")` is `%uD83D%uDE2D`, not the four
  percent-encoded UTF-8 bytes we used to emit. `encodeURI` is the opposite
  — byte-based — so the two cannot share a code path.
- **`unescape` must re-pair those halves**, or `unescape(escape(x))` is
  not the identity for astral input (each half alone becomes U+FFFD). It
  must also *not* accept `%U` — the avm2 suite pins
  `unescape("%U3333") === "%U3333"`, and we were decoding it.
- All five natives return the string `"undefined"` for a no-arg call and
  `"null"` for an explicit `undefined` — the AS3 `String`-typed parameter
  coerces `undefined` to null, which then stringifies.

One deliberate spec divergence: ECMA-262 throws `URIError` on a decoded
surrogate, and **Flash does not**. `regress/bug_538107` exists precisely
to pin that (`"%ED%B0%80%ED%A0%80"` must decode to a 2-unit string, not
raise), so decoded surrogates become U+FFFD instead.

**`Capabilities` was 5 tests for a class nobody reads.** Every one of the
five only does `var playerType:String = Capabilities.playerType` and
branches on it being `'AVMPlus'` — the Tamarin *shell* — so all that
mattered was that the class exist and not claim to be the shell. Values
mirror Ruffle's fixed "Flash Player on Windows" profile. Two details did
matter: the class is abstract (`new Capabilities()` throws `#2012`, which
`abstract_classes` enumerates), and `screenResolutionX/Y` are the viewport
divided by the HiDPI scale factor, so `verify_output.py` now passes
`-DVIEWPORT_SCALE_FACTOR` next to the viewport dimensions it already
defined — that is what makes the avm2 suite's `capabilities_resolution`
land on 1536×864 rather than by luck.

Two unpredicted bonuses came from tests that merely *used* a URI function
en route to something else: `as3/Statements/Exceptions/MultipleCatchBlocksURI`
and `TryCatchBlockUserWithBuiltInExceptions` (the latter was the
`Variable e is not defined` entry in the uncaught-error table — it was
catching a `URIError` that never existed).

### Next arc, discovered here: static consts are writable (~12 tests)

`avm2_builtin_add_static_const` installs a **dont-enum dynamic property**
on the class object. AS3 `public static const` is read-only and
non-deletable, so every constant registered through it fails three
assertions that `ecma3/Number` makes on each of `MAX_VALUE`, `MIN_VALUE`,
`NaN`, `POSITIVE_INFINITY`, `NEGATIVE_INFINITY` and `prototype`:

```
Number.MAX_VALUE = 0            expected ReferenceError #1074, got no error
delete( Number.MAX_VALUE )      expected false, got true
```

Mapping each failing test to the property it pins gives an **exact 10**,
the five value constants × {DontDelete, ReadOnly}:

| Constant | `delete` → false | `= 0` → `#1074` |
|---|---|---|
| `MAX_VALUE` | `e15_7_3_2_2` | `e15_7_3_2_3` |
| `MIN_VALUE` | `e15_7_3_3_2` | `e15_7_3_3_3` |
| `NaN` | `e15_7_3_4_2` | `e15_7_3_4_3` |
| `NEGATIVE_INFINITY` | `e15_7_3_5_2` | `e15_7_3_5_3_rt` |
| `POSITIVE_INFINITY` | `e15_7_3_6_2` | `e15_7_3_6_3_rt` |

Two neighbours look like part of it and are **not**: `e15_7_3_1_1`
(`delete(Number.prototype)` → false) is a different bug — `prototype` is an
instance getter on `class_class`, but `deleteproperty_common` searches
`obj->vtable`, which for a class object is its *static* vtable, so the
trait is never found and delete reports true. And `e15_7_3` wants the class
object's own `.length`, which belongs to the `FunctionObjects` arc. The
remaining three (`e15_7_4_2_2_rt`, `e15_7_4_2_4`, `toLocaleString_rt`) are
double→string formatting, already in Polish.

**Design note.** The obvious fix — reuse the getter-only static trait from
the eight new `Number` constants — does not generalise: a getter cannot
capture a per-constant value without one function apiece, and there are
**91 `add_static_const` call sites across 10 files**. Prefer a `read_only`
flag on `Avm2DynProp` honoured by `setproperty_impl`'s
`r->dyn != NULL && r->proto_holder == NULL` branch and by
`avm2_object_delete_dynamic`. That is contained, fixes all 91 sites at
once, and touches none of the vtable machinery.

Deliberately **not** in `8e8370df1`: the helper is used by every builtin
class in the runtime, so it wants its own CI cycle with clean attribution
rather than being folded into a run that had to be read for regressions.

### Known residue: `avm2/encode_uri_surrogate_pair_invalid` is a `utf8count` clone

The one URI test that did not flip, and it is not fixable in this arc. It
calls `String.fromCharCode(0xDC00)` and expects `encodeURI` to throw
`URIError`. Our `Avm2String` is UTF-8, so the lone surrogate has already
collapsed to U+FFFD *before* `encodeURI` ever sees it — a legitimate
character, correctly encoded as `%EF%BF%BD`. Identical root cause to
`ecma3/Unicode/utf8count` below, and it flips only when that
representation change does.

## Known residue: `ecma3/Date/e15_9_5` needs sealed builtin prototypes

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
- ~~**Cleanup batch** (`Number` statics + URI functions +
  `Capabilities`)~~ — **DONE** (`8e8370df1`, **+41** here, +5 in the avm2
  suite). Predicted ~35; delivered 46.

**The eager-driver blanking is essentially drained: only 12 tests
corpus-wide still die on an uncaught error**, down from ~200 at import and
44 before this batch. The `error_signature` histogram has therefore stopped
being the primary ranking instrument — what remains is line-level polish,
which the "Likely Fixable" table in `FAILING_TESTS_BY_FEATURE.md` ranks
instead. With that batch landed, the ranking is:

1. **Static consts must be read-only** — **10** tests, all in
   `ecma3/Number` (exact list in the section above), plus 1 adjacent
   (`delete(Number.prototype)`, a different one-line fix). Highest
   remaining yield here and mechanically small, but 91 call sites across
   10 files, so give it its own CI cycle.
2. **`[object Function]` classification** + `Function('body')` →
   `EvalError #1066` + class-object `.length` — ~15
   (`ecma3/FunctionObjects` 6/21, and the classification item recurs in
   `ecma3/ObjectObjects/e15_2_4_2`, `ecma3/String/e15_5_4_6_2_rt` and
   `ecma3/ObjectObjects/class_006`).
3. **Sealed builtin prototypes (`#1037`)** — 3 tests: 2 on Array
   (`Cannot assign to a method toString on Array`) plus `ecma3/Date/e15_9_5`.
   See the Date residue section above; this is a change to how builtin
   prototype objects are constructed, not a per-class fix.

Two one-test items also still open: **`Variable AS3 is not defined`**
(`as3/Array/length_mods`) and **`isXMLName` undefined**
(`e4x/Global/e13_1_2_1`).

Parked: **`mops`** (13 tests, all crash/error — Alchemy `li8/li16/li32/
lf32/lf64/si*/sf*` domainMemory opcodes; needs `ApplicationDomain.
domainMemory`), and the 49 remaining `known_failure` tests.
