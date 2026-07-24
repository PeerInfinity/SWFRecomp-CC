# from_avmplus Suite — Current Status

Last updated: 2026-07-24 — **first baseline + first fix, CI-confirmed**. The
Adobe Tamarin/avmplus acceptance suite (1574 tests, 100% AVM2) was imported
2026-07-24 and baselined in both CI modes at `eabb3b366`:
**871/1574 effective (55.3%)**, identical in graphics and no-graphics.

This session cracked the "empty output" pattern and landed the first fix
(`d36c8da2b`, root SymbolClass must inherit Sprite → trace TypeError
`#2023`). CI run `30121943045` (graphics, `categories=full`):
**+156 newly passing here, +4 in the avm2 suite, +3 promoted to
ruffle_matched, ZERO regressions corpus-wide.** e4x went **2/177 → 160/177**
and the suite to **1000/1522 (65.7%)**.

⚠️ That run lost shard 25/30 to the known apt/Vulkan flake
(`graphics-ci-aptget-flaky-shards`), so 52 from_avmplus tests were not
executed — totals below read 1522 not 1574, and `ecma3/String` in
particular is understated (41 of its 83 tests ran). Extrapolating the
missing shard at its prior rate puts the true figure near
**1029/1574 (65.4%)**. The next full run restores exact totals.

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

Import baseline `eabb3b366` (complete, both modes), and current
`d36c8da2b` (graphics, 29/30 shards):

| Area | at import | now | failing now | of which known_failure |
|---|---|---|---|---|
| ecma3 | 402/800 | 372/748 | 376 | 30 |
| e4x | **2/177** | **160/177** | 17 | 3 |
| as3 | 410/509 | 411/509 | 98 | 6 |
| mops | 0/13 | 0/13 | 13 | 0 |
| regress | 43/55 | 43/55 | 12 | 4 |
| recursion | 1/6 | 1/6 | 5 | 1 |
| misc | 13/14 | 13/14 | 1 | 1 |
| **total** | **871/1574** | **1000/1522** | **522** | **45** |

(`ecma3` and the total lost 52 tests to the shard-25 flake; nothing there
regressed.) Status breakdown of the 522: 500 output_mismatch,
16 runtime_error, 3 timeout, 2 segfault, 1 compile_fail.

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

1. **`Date` class** — ~151 here + 2 in the avm2 suite. Biggest single
   unlock left in the corpus. The AVM2 class is a 3-method AMF stub
   (`avm2_amf.c:1763` — `getTime`/`valueOf`/`toString`), while AVM1 has a
   complete one to port from: `actionmodern/date.c`, 1014 lines, 38 methods
   including the full `getUTC*`/`setUTC*` family and `getTimezoneOffset`.
2. **String/Unicode semantics** — ~102 `ecma3/Unicode` + part of
   `ecma3/String`. Two bugs, both visible in every Unicode test:
   - `search`/`match` must coerce a non-RegExp pattern **to a string**
     before building the implicit RegExp (Ruffle `globals/string.rs`), so
     `undefined` becomes the pattern `"undefined"` and never matches →
     `-1` / `null`. `pattern_to_regexp` (`avm2_regexp.c:567`) passes the
     raw value through, giving an empty pattern that matches at 0.
   - `String.split('')` must split by UTF-16 code unit.
     `avm2_string_split_plain`'s empty-delimiter branch iterates
     `i < s->len` (UTF-8 **bytes**), so U+0080..U+00FF yields 256 elements
     instead of 128. `utf16_length` already exists in that file.
3. **ES3 `.prototype` surface + `Function.length`** — ~35 blanked tests plus
   a long tail of one-line diffs (`parseInt.length` returns 0, expected 2).
   `String`/`Array`/`Number`/`Boolean` register zero prototype functions
   today; Ruffle declares them in `globals/String.as` etc.
4. **`Number` static math (API 680)** — 21 tests, ~19 methods + 8 constants,
   mirroring `Math`.
5. **Global URI functions** — `encodeURI`/`decodeURI`/`encodeURIComponent`/
   `decodeURIComponent`; ~6 here + 3 in the avm2 suite.

Parked: **`mops`** (13 tests, all crash/error — Alchemy `li8/li16/li32/
lf32/lf64/si*/sf*` domainMemory opcodes; needs `ApplicationDomain.
domainMemory`), and the 49 remaining `known_failure` tests.
