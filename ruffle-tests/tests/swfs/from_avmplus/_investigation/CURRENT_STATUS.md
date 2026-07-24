# from_avmplus Suite — Current Status

Last updated: 2026-07-24 — **String/Unicode arc landed, CI-confirmed**. The
Adobe Tamarin/avmplus acceptance suite (1574 tests, 100% AVM2) was imported
2026-07-24 and baselined in both CI modes at `eabb3b366`:
**871/1574 effective (55.3%)**, identical in graphics and no-graphics.

Two fixes have landed since:

1. `d36c8da2b` — root SymbolClass must inherit Sprite → trace TypeError
   `#2023`. e4x **2/177 → 160/177**.
2. `127a5f4d3` — the two AVM2 String semantics bugs (below).
   `ecma3/Unicode` **6/108 → 107/108**.

The suite now stands at **1131/1574 effective (71.9%)** — full shard
coverage, no extrapolation.

CI run `30126336695` (graphics, `categories=full`, at `127a5f4d3`)
measured per-test against the previous run:
**+101 newly effective — every one of them in `ecma3/Unicode` — and ZERO
regressions in any suite.**

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

Import baseline `eabb3b366` and current `127a5f4d3` — both complete
(30/30 shards), graphics mode:

| Area | at import | now | failing now | of which known_failure |
|---|---|---|---|---|
| ecma3 | 402/800 | **503/800** | 297 | 30 |
| e4x | **2/177** | **160/177** | 17 | 3 |
| as3 | 410/509 | 411/509 | 98 | 6 |
| mops | 0/13 | 0/13 | 13 | 0 |
| regress | 43/55 | 43/55 | 12 | 4 |
| recursion | 1/6 | 1/6 | 5 | 1 |
| misc | 13/14 | 13/14 | 1 | 1 |
| **total** | **871/1574** | **1131/1574** | **443** | **45** |

Status breakdown of the 443: 421 output_mismatch, 16 runtime_error,
3 timeout, 2 segfault, 1 compile_fail.

`ecma3/Unicode` is now **107/108**. The single holdout is `utf8count` —
see "Known residue" below.

At import, 263 of the 703 failures were missing **exactly one** output
line — 155 of them the e4x root-link line, now fixed.

Top feature areas by failing count (auto-generated in
`FAILING_TESTS_BY_FEATURE.md`; `x/y` = failing of tests run):

| Failing | Area | Root cause |
|---|---|---|
| 151/153 | `ecma3/Date` | Date is a 3-method stub |
| 102/108 | `ecma3/Unicode` | 2 String semantics bugs (below) |
| 31/55 | `as3/Types` | `Number` static math (API 680) missing |
| 21/212 | `as3/Definitions` | assorted; error-message wording |
| 21/53 | `ecma3/Number` | `Function.length`, `toString` rounding |
| 15/60 | `as3/Vector` | assorted |
| 15/21 | `ecma3/FunctionObjects` | `Function.prototype.*` / `.length` |
| 14/51 | `as3/RuntimeErrors` | error-message wording |
| 14/41 | `ecma3/String` | ES3 `String.prototype.*` missing (42 tests unrun) |
| 13/51 | `ecma3/Array` | ES3 `Array.prototype.*` missing |
| 13/21 | `ecma3/GlobalObject` | `encodeURI`/`decodeURI` family missing |
| 13/13 | `mops` | Alchemy `li*`/`si*` domainMemory opcodes |
| 11/46 | `ecma3/Exceptions` | assorted |
| 17/177 | `e4x` (all dirs) | residue after the `#2023` fix |

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
- **ES3 `.prototype` surface + `Function.length`** — implemented in
  `d90353066`, CI pending at time of writing. See below.

1. **`Date` class** — ~151 here + 2 in the avm2 suite. Biggest single
   unlock left in the corpus. The AVM2 class is a 3-method AMF stub
   (`avm2_amf.c:1763` — `getTime`/`valueOf`/`toString`), while AVM1 has a
   complete one to port from: `actionmodern/date.c`, 1014 lines, 38 methods
   including the full `getUTC*`/`setUTC*` family and `getTimezoneOffset`.
   The regenerated uncaught-error table confirms the shape: **151 tests die
   on `TypeError #1006: getTimezoneOffset is not a function`** and a further
   **15 on `getFullYear`**, the latter scattered through `as3/Definitions`
   rather than `ecma3/Date` — so the Date arc is worth more than the
   `ecma3/Date` directory count alone suggests.
2. **`Number` static math (API 680)** — 21 tests, ~19 methods + 8 constants,
   mirroring `Math`.
3. **Global URI functions** — `encodeURI`/`decodeURI`/`encodeURIComponent`/
   `decodeURIComponent`; ~6 here + 3 in the avm2 suite.
4. **`flash.system.Capabilities`** — the error table now shows **5** tests
   blocked on `ReferenceError #1065: Variable Capabilities is not defined`,
   not the 2 previously estimated.

Two smaller items the regenerated error table surfaced that were not in the
original ranking:

- **`ReferenceError #1037: Cannot assign to a method toString on Array`**
  (2 tests, e.g. `ecma3/Array/e15_4_1_1`). ES3 code reassigns builtin
  methods; our class methods are sealed against assignment.
- **`ReferenceError #1065: Variable AS3 is not defined`**
  (`as3/Array/length_mods`) and **`isXMLName` undefined**
  (`e4x/Global/e13_1_2_1`) — one test each, both trivial-looking.

Parked: **`mops`** (13 tests, all crash/error — Alchemy `li8/li16/li32/
lf32/lf64/si*/sf*` domainMemory opcodes; needs `ApplicationDomain.
domainMemory`), and the 49 remaining `known_failure` tests.
