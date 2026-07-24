# Feature-Priority Map — coverage gaps across the full Ruffle corpus

**Created**: 2026-07-24 · **Baseline**: `eabb3b366`, mode=graphics
(no-graphics identical bar two pre-existing one-test divergences).
**Purpose**: the corpus is a roadmap instrument. Rank the features we have
not implemented by how many tests each would unlock, so the map — not
intuition — decides what to build next (user direction 2026-07-23).

Regenerate the per-suite inputs with:

```bash
python3 scripts/generate_failing_by_feature.py --suite=from_avmplus
python3 scripts/generate_failing_by_feature.py --suite=avm1
python3 scripts/generate_failing_by_feature.py --suite=gnash/actionscript.all
```

## Where we stand

**Denominator correction (2026-07-24).** The 4463 figure used below the
import baseline double-counted three *nested* result directories that are
already included in their parents: `from_shumway/avm1` (47),
`from_shumway/timeline` (1) and
`from_gnash/misc-ming.all/displaylist_depths` (1) — exactly 49 tests.
`from_shumway`'s own `results_graphics.json` contains all 229 tests
including the 50 named `avm1/*`. The correct corpus denominator is
**4414**, and it is what this document uses from here on. Sum over
top-level leaf suites only; do not add nested `_results` dirs.

Full corpus, graphics mode at **`127a5f4d3`** (CI `30126336695`, complete
30/30 shards): **3426/4414 effective (77.6%)**, 988 failing.

| Suite | eff/total | % | failing | character of the failures |
|---|---|---|---|---|
| from_avmplus | 1131/1574 | 71.9 | 443 | **language + builtins** (Tamarin acceptance) |
| avm2 | 859/1217 | 70.6 | 358 | **platform APIs** (Loader, net, input, PixelBender, Stage3D) |
| avm1 | 654/716 | 91.3 | 62 | long tail |
| from_shumway | 171/229 | 74.7 | 58 | AVM2 half: Loader, timeline nav, fuzz corpus |
| from_gnash (5) | 371/403 | 92.1 | 32 | long tail |
| misc (9 cats) | 170/205 | 82.9 | 35 | text/fonts/mixed_avm/stage3d markers |
| regression | 70/70 | 100 | 0 | ours |

For reference, the import baseline `eabb3b366` was **871/1574** in
from_avmplus; the ranking below was originally computed from it, and the
arc yields have been updated in place as each landed.

The two big suites fail for *orthogonal* reasons, and that is the single
most useful fact in this document:

- **from_avmplus tells us which ECMAScript/AS3 builtins are missing.** It
  never touches the display list. Its failures are dense (one missing class
  blanks 150 tests) and cheap per test.
- **avm2 tells us which Flash platform APIs are missing.** Its failures are
  sparse and expensive per test (a Loader arc is weeks; it buys 31 tests).

Test-yield-per-unit-of-work is therefore *far* higher on the from_avmplus
side today, and that is where the next few arcs should go.

## How the avmplus driver amplifies a single gap

Worth internalising before reading the ranking. Every avmplus test builds
its whole assertion array eagerly at script-init time and prints as it goes:

```as3
var testcases = getTestCases();   // every Assert.expectEq() runs here
```

A single uncaught error anywhere in that build aborts the script and
suppresses **all** remaining output. So "one missing method" does not cost
one assertion — it costs the entire test, and (because Tamarin groups tests
by builtin) usually the entire directory. This is why the Date arc is worth
151 tests rather than 151 assertions.

`verify_output.py` now records `error_signature` (the first
`AVM[12] uncaught error:` line) on every result, and
`generate_failing_by_feature.py` emits a "Failing Tests by Uncaught Error"
table from it. **Read that table before re-deriving any of this by hand.**

---

## Ranked feature arcs (build X → unlock N)

Yields are tests that flip from failing to effective-pass. Known-failure
tests (Ruffle fails them too) are excluded from the yields.

### 1. `Date` — ~155 tests · LARGE arc · **do this first**

| Suite | tests |
|---|---|
| from_avmplus `ecma3/Date` | 151 (134 after removing 17 known_failure) |
| from_avmplus `ecma3/Exceptions/date_*` | 2 |
| avm2 `date`, `date_parse` | 2 |

AVM2 `Date` is a **three-method stub** — `getTime`, `valueOf`, `toString`,
bolted on in `avm2_amf.c:1763` purely so AMF round-trips work. Everything
else (`getFullYear`, `setMonth`, `getTimezoneOffset`, the `UTC` statics,
`Date.parse`, the ES3 string formats, the 2-through-7-argument constructor)
is absent, and each missing method blanks a whole test file.

Cost is bounded and known. ECMA-262 §15.9 is fully specified; the test
determinism story is already solved (`MOCK_DATE_TIME`); and **AVM1 already
has a complete Date** — `SWFModernRuntime/src/actionmodern/date.c`, 1014
lines, 38 methods including the whole `getUTC*`/`setUTC*` family and
`getTimezoneOffset`. The arc is largely "expose that engine as an AVM2
class", plus the AS3-only surface (`Date.parse`, `Date.UTC`, the
multi-argument constructor, the AS3 accessor properties, and the
`toLocale*`/`toUTCString` formats). No display list, no rendering, no new
opcodes.

### 2. ~~String/Unicode semantics~~ — **DONE (`127a5f4d3`, +101)** · SMALL arc · best ratio in the corpus

**Predicted ~102, delivered 101.** `ecma3/Unicode` 6/108 → **107/108**,
zero regressions corpus-wide (CI `30126336695`). The 102nd test,
`utf8count`, is a different and much deeper problem — see below. The
diagnosis in this section was accurate in every particular and is kept
for the record.

**What did *not* flip as predicted:** `ecma3/String/esplit_002` and
`ematch_004` were listed here, but neither was blocked on these two bugs.
Both do `Number.prototype.split = String.prototype.split` — they need
arc 3, not arc 2. They pass under `d90353066`.

**`utf8count` is not adjacent-and-cheap.** It concatenates
`String.fromCharCode()` over surrogate *pairs* and compares to a UTF-8
literal. `Avm2String` is UTF-8 and cannot hold an unpaired surrogate, so
each half becomes U+FFFD and they never recombine. That needs WTF-8 or
pairing-at-concat — a representation change, and it should be scoped
separately rather than treated as String polish.

<details><summary>original diagnosis (kept — it was correct)</summary>

`ecma3/Unicode` is 102/108 failing, and **every one of those tests fails on
the same three assertions** (16/21 or 17/21 lines match, uniformly):

| Assertion | Expected | We produce | Fix |
|---|---|---|---|
| `String.search()` / `search(undefined)` | `-1` | `0` | coerce the pattern to a **string** first |
| `String.match()` / `match(undefined)` | `null` | `""` | same coercion; non-global no-match returns `null` |
| `String.split('')` | 128 elements | **256** | split by UTF-16 code unit, not UTF-8 byte |

The first two are one bug. Ruffle (`globals/string.rs::search`,
`match_internal`) does `pattern.coerce_to_string()` before constructing the
implicit RegExp, so `undefined` becomes the *pattern* `"undefined"` and
never matches. Our `pattern_to_regexp` (`avm2_regexp.c:567`) hands the raw
value to the RegExp constructor, where `undefined` yields an empty pattern
that matches at index 0.

The split bug is separate and the more interesting one:
`avm2_string_split_plain`'s empty-delimiter branch iterates `i < s->len`
— the **UTF-8 byte** length — and pushes 1-byte substrings. For
U+0080..U+00FF every character is two bytes, so we return exactly double.
The file already has the right helper (`utf16_length`, used by `substr`).
This is a real AVM2 string-indexing correctness bug, not a test artifact.

Three small fixes, ~102 tests. Nothing else in the corpus comes close on
effort-to-yield.

</details>

### 3. ES3 `.prototype` surface on builtins + `Function.length` — ~35 blanked + long tail · MEDIUM — **implemented (`d90353066`), CI pending**

`String`, `Array`, `Number` and `Boolean` register **zero** prototype
functions (`grep avm2_proto_add_function` finds none in `avm2_string.c`,
`avm2_array.c`, `avm2_number.c`). In AS3 these exist as an ES3-compat layer
— Ruffle declares them in `core/src/avm2/globals/String.as` and friends.

Any test that opens with `String.prototype.substr.length` (Tamarin's
standard first assertion for a builtin) dies immediately with
`TypeError #1010`. That is ~35 blanked tests across `ecma3/String`,
`ecma3/Array`, `ecma3/FunctionObjects`, `ecma3/Boolean`,
`ecma3/ObjectObjects`, `ecma3/Number`.

Paired sub-item: **`Function.length` is always 0.** `parseInt.length`
returns 0 where 2 is expected (`ecma3/GlobalObject/e15_1_2_2_1`), and every
`X.prototype.m.length` assertion depends on it. Declared arity must be
carried on builtin function objects.

### 4. `Number` static math (API 680) — 21 tests · SMALL arc

`as3/Types/Number/{abs,acos,asin,atan,atan2,ceil,cos,exp,floor,log,max,min,
pow,random,round,sin,sqrt,tan,e,ln2,ln10,log2e,log10e,pi,sqrt1_2,sqrt2}` —
21 failing, all blanked by `TypeError #1006: abs is not a function`.

These are real Flash Player members (Ruffle: `globals/Number.as`,
`[API("680")]`), essentially `Math` re-exported on `Number` with
`ArgumentError #1063` on missing args. Mechanical.

### 5. Global URI functions — ~9 tests · SMALL arc

`encodeURI`, `decodeURI`, `encodeURIComponent`, `decodeURIComponent` are
undefined (`ReferenceError #1065`): ~6 in from_avmplus
(`ecma3/GlobalObject`, `regress/bug_538107`) plus `decode_uri`,
`encode_uri_surrogate_pair_invalid`, `encode_uri_surrogate_pair_swf11` in
the avm2 suite.

### 6. `mops` / Alchemy domainMemory — 13 tests · MEDIUM arc

All 13 `mops` tests crash or error: `li8/li16/li32/lix8/lix16/lf32/lf64`,
`si8/si16/si32/sf32/sf64`, `mops_basics` (timeout). These are the Alchemy
memory opcodes over `ApplicationDomain.domainMemory`; the avm2 suite's
`domain_memory` test is the same gap. Self-contained, but it is real
runtime work (a ByteArray-backed memory window plus 12 opcodes).

### 7. `flash.system.Capabilities` — 2 tests · TRIVIAL

`as3/Vector/nonindexproperty/{v10,v11}` die on
`ReferenceError #1065: Variable Capabilities is not defined`. Also unblocks
`capabilities_resolution` in the avm2 suite.

### 8. Dual-VM movies (AVM1 ↔ AVM2 in one player) — 8 tests · LARGE arc

All 8 failing `mixed_avm` tests. A parked feature marker, not a regression
— we have no dual-VM-in-one-movie support. Large architectural cost for a
small, closed yield; the map does not recommend it now.

### 9. Stage3D / Context3D — 17 tests · LARGE arc

4 `stage3d` + 13 in the avm2 suite (`stage3d_*`, `matrix3d_*`). Also parked.
Real GPU-API surface for a small yield.

---

## Platform arcs (the avm2 suite's 362 failures)

Grouped by theme. These are the *expensive* arcs — listed so their cost is
visible next to their yield, not because they are next.

| Failing | Theme | Note |
|---|---|---|
| 31 | Loader / URLLoader / loaderInfo | + 9 more in from_shumway `as3-loader` |
| 30 | Sockets, NetConnection, NetStream, FileReference, SharedObject | network stack |
| 25 | Focus / Tab / Mouse / Keyboard input | partly reachable via `input.json` injection |
| 25 | PixelBender (`Shader`) | needs a PBJ interpreter |
| 22 | Display list / DisplayObject / Stage edge cases | closest to existing work |
| 22 | Verifier / cpool / ABC edge cases | closest to existing work |
| 13 | Stage3D / Context3D | parked (arc 9) |
| 9 | TextField / EditText / StyleSheet | |
| 8 | Security / sandbox / ApplicationDomain | |
| 8 | Filters / blend modes | |
| 7 | Text Layout Framework (`textline`, `textblock`, FTE) | |
| 5 | Sound / audio | |
| 4 | `describeType` / avmplus introspection | |
| 25 | `all_classes/*` | per-SWF-version class-existence census — these tick up incrementally as *any* class is added, so they are a free rider on every other arc |

Note `all_classes/*`: 25 tests that enumerate every class expected to exist
at a given SWF version. They are the corpus's built-in progress meter for
API surface, and no arc targets them directly.

## Polish (near-passes — bug fixes, not features)

108 from_avmplus tests were ≥90% line-matched at baseline. **60+ of those
were e4x tests missing only the root-link line and are resolved by
`d36c8da2b`** (below). The remaining polish bucket, with confirmed causes:

| Test(s) | Diff | Cause |
|---|---|---|
| `ecma3/Number/e15_7_4_2_4` | `1.2345000000000002e-7` vs `1.2345e-7` | double→string needs shortest-round-trip formatting |
| `ecma3/JSON/e15_12_1`, `e15_12_3` | array/object parse corruption around whitespace | JSON lexer whitespace handling |
| `as3/Definitions/Variable/ConstVariables_custom1`, `as3/RuntimeErrors/*` | `…read-only property classItem7…` vs `…property Package1:ns1::classItem7…` | error messages must use the namespace-qualified name |
| `ecma3/ObjectObjects/e15_2_4_2` | `Object.prototype.toString` on a function | `[object Function]` classification |
| `ecma3/GlobalObject/e15_1_2_2_*`, `e15_1_2_3_1`, `e15_1_2_5_1` | `parseInt.length` → 0 | `Function.length` (arc 3) |
| `as3/Array/insertremove` | 30766/30870 lines | large-array edge cases |
| e4x residue (~20) | 10 at 50–90%, 6 below | ordinary E4X polish |

Misc-category failures (counts are *failing of total*, small and mostly
one-off): `text` 6 of 11 (caret placement ×4, HTML entity parsing, links in
scrolled text), `fonts` 3 of 6 (device-font glyph fallback, kerning, list),
`import_assets` 2 of 3, `audio` 2 of 5 (AAC, G.711 codecs), `timeline` 2 of
17, `visual` 8 of 142 (mostly image-only; `blend_modes` is a `recomp_fail`).
from_shumway's 58: 16 fuzz corpus, 9 `timeline/nav`, 9 `as3-loader`,
5 `acid`, rest scattered.

---

## Landed

**`127a5f4d3` — String/Unicode semantics (arc 2 above).**

Two independent AVM2 String bugs. (a) `search`/`match` handed the raw
argument to the implicit RegExp constructor, where `undefined` becomes the
*empty* pattern (ECMA-262 §15.10.4.1) and matches at index 0; Ruffle
coerces to a string first, making the pattern the literal `"undefined"`,
which never matches. (b) `String.split('')` iterated UTF-8 **bytes**, so
U+0080–U+00FF returned 256 elements instead of 128 and U+4E00–U+4EFA
returned 753 instead of 251; it now walks UTF-16 code units via
`utf16_unit_at`, mirroring `charAt` including the astral case.

CI-confirmed (`30126336695`, graphics, `categories=full`, full 30/30
shards): **+101 newly effective, every one in `ecma3/Unicode`
(6/108 → 107/108), and zero regressions in any suite.**

⚠️ **Shard-recovery caveat for anyone re-reading these runs.** The prior
run `30121943045` lost shard 25/30 to the apt/Vulkan flake, so 137 tests
corpus-wide (52 in from_avmplus) went unexecuted. Run `30126336695`
restored them, and a naive run-to-run diff shows those 137 as "new" — 98
of which were *already* effective. The +101 above counts only tests
present in **both** runs. Always diff on the intersection when a flaked
run is one of the endpoints.

**`d36c8da2b` — root SymbolClass must inherit Sprite, trace `TypeError #2023`.**

177 avmplus tests declare `public class Test {}` with no base class. Flash
and Ruffle fail to link such a class to the root, trace
`TypeError: Error #2023: Class Test$ must inherit from Sprite to link to the
root.`, and keep running with a plain MovieClip root. We instead constructed
the class with the stage as its sole argument, threw `ArgumentError #1063`
to stderr, and printed nothing — losing exactly one line.

**155 of the 175 failing e4x tests were missing only that line.**

CI-confirmed (`30121943045`, graphics, `categories=full`):
**+156 in from_avmplus** (155 e4x + `as3/Vector/concat`), **+4 in the avm2
suite** that were one line short of the same message (`parse_float`,
`string_concat_fromcharcode`, `string_slice_substr_substring`,
`xml_basic`), **+3 promoted to `ruffle_matched`**, and **zero regressions in
any suite**. e4x: 2/177 → **160/177**. from_avmplus: 55.3% → **65.7%**.

This also settles the E4X question: **E4X is not a coverage gap.** Our
engine passes Tamarin's XML/XMLList/QName/Namespace/TypeConversion suites
essentially in full; 2/177 was one linking bug, not missing features.

## Recommendation — the next arcs

| Order | Arc | Yield | Size | Status |
|---|---|---|---|---|
| ~~1~~ | String/Unicode: `search`/`match` coercion + `split('')` by code unit | **101 actual** (pred. ~102) | small | **DONE `127a5f4d3`** |
| ~~2~~ | ES3 `.prototype` surface + `Function.length` | ~35 blanked + a long one-line tail | medium | **implemented `d90353066`**, CI pending |
| 1 | `Date` class (ECMA-262 §15.9) | ~166 | large | biggest single unlock left; fully specified; AVM1 Date to port from; no new subsystems |
| 2 | `Number` static math (API 680) | 21 | small | mechanical |
| 3 | Global URI functions | ~9 | small | mechanical |
| 4 | `flash.system.Capabilities` | 5 | trivial | mechanical |

**Date is now the clear top item**, and it is worth *more* than the
`ecma3/Date` directory count: the regenerated uncaught-error table shows
**151** tests dying on `getTimezoneOffset is not a function` plus **15**
more on `getFullYear` that live outside `ecma3/Date` (mostly
`as3/Definitions`). Call it ~166.

The cheap cleanup batch (`Number` static math + URI functions +
`Capabilities`) is ~35 tests of almost purely mechanical work and fits in
one session.

from_avmplus stands at **1131/1574 (71.9%)** with arc 2 landed. Adding the
ES3 prototype arc, Date, and the cleanup batch should take it to roughly
**1350/1574 (86%)** and the corpus from 77.6% to about **83%**.

**Re-rank from the error table, not from first principles.** Every result
now carries `error_signature`; `generate_failing_by_feature.py` emits a
"Failing Tests by Uncaught Error" histogram
(`from_avmplus/_investigation/FAILING_TESTS_BY_FEATURE.md`). It already
corrected two estimates in this document — `Capabilities` is 5 tests, not
2, and Date is ~166, not ~155 — and surfaced small items nobody had
listed (`#1037 Cannot assign to a method toString on Array`, undefined
`AS3` and `isXMLName`, each 1–2 tests).

Regression-guard every one of these with
`gh workflow run ruffle-tests.yml --ref master -f mode=graphics -f categories=full`
— they all touch shared AVM2 runtime code.
