# Wave-1 diagnosis — `avm2/bom` and `e4x/Global/e13_1_2_1`

Repo HEAD at diagnosis: `1c7c23761`. All measurements are **local re-runs at
HEAD** (default `--mode` / no-graphics), one test at a time. Baseline statuses
read from `ruffle-tests/tests/swfs/{avm2,from_avmplus}/_results/results_graphics.json`.

| Target | Baseline | Verdict |
|---|---|---|
| A `avm2/bom` | `output_mismatch` 4/9 | **CANNOT EVER PASS** — disposition + a small correctness fix. NO-GO as a "+1". |
| B `from_avmplus/e4x/Global/e13_1_2_1` | `output_mismatch` 7/10 (293 actual lines) | **GO** — ready, mechanical, verified +1 by exhaustive simulation. |

A third, *unassigned* finding fell out of target A and is the best yield in the
area: `flash.utils.escapeMultiByte`/`unescapeMultiByte` and
`URLVariables(str)`/`decode()` are simply **absent**, which alone accounts for
`avm2/escape_multi_byte` (1/45) and `avm2/url_vars` (3/27). See §C.

---

## A. `avm2/bom` — endgame is "never passes"

`ruffle-tests/tests/swfs/avm2/bom/`. `test.toml` is `num_ticks = 1` only —
**no `known_failure`, no `output.ruffle.txt`**.

### Measured diff at HEAD

```
     4  URLLoader dataFormat=text utf8: lastName=Jones&firstName=Tom          (matches)
-    5  URLLoader dataFormat=text utf16le: lastName=Jo∀nes&firstName=Tom
+    5  URLLoader dataFormat=text utf16le: ��lastName=Jo"nes&firstName=Tom
-    6  URLLoader dataFormat=text utf16be: lastName=Jo∀nes&firstName=Tom
+    6  URLLoader dataFormat=text utf16be: ��lastName=Jo"nes&firstName=Tom
-    7  URLLoader dataFormat=variables utf8: firstName=Tom&lastName=Jones
+    7  URLLoader dataFormat=variables utf8: lastName=Jones&firstName=Tom
-    8  URLLoader dataFormat=variables utf16le: firstName=Tom&lastName=Jo%E2%88%80nes
+    8  URLLoader dataFormat=variables utf16le: ��lastName=Jo"nes&firstName=Tom
-    9  URLLoader dataFormat=variables utf16be: firstName=Tom&lastName=Jo%E2%88%80nes
+    9  URLLoader dataFormat=variables utf16be: ��lastName=Jo"nes&firstName=Tom
```

Lines 1–3 (the `ByteArray` `toString` half) already pass — **`ByteArray.toString`
already does the full BOM job** (`avm2_bytearray.c:827-846`, UTF-8 + UTF-16LE +
UTF-16BE). Line 4 passes because the URLLoader arm strips the *UTF-8* BOM.

### The session-7 "three causes", re-verified — one was already half-done

| # | Session-7 claim | Status at HEAD |
|---|---|---|
| 1 | BOM stripping | **Already correct for UTF-8** in `ul_set_data` (`avm2_display.c:5944-5958`). Nothing to do. |
| 2 | UTF-16 decode | **Real.** `ul_set_data` handles `EF BB BF` only; `FF FE`/`FE FF` fall through to `avm2_string_new` on raw bytes → the `��…Jo"nes` garbage on lines 5/6/8/9. |
| 3 | URLVariables emission order | **Real and permanent** (see below). |

There is also a **cause 4** the brief didn't name: `dataFormat = "variables"`
never constructs a `URLVariables` at all — `ul_set_data`'s own comment says
*"and, for now, 'variables' — no test exercises URLVariables as a URLLoader
response"*, which `bom` disproves. Ruffle's `set_data`
(`~/CC/ruffle/core/src/loader.rs:1234-1287`) constructs
`classes().urlvariables.construct(&[strip_bom(body)])`. Without it, lines 8/9
also lack the `%E2%88%80` escaping that `URLVariables.toString` would add.

### Why cause 3 is permanent (confirmed against the oracle)

`URLVariables.toString` (`~/CC/ruffle/core/src/avm2/globals/flash/net/URLVariables.as`)
joins pairs `for (p in this)`. Ruffle stores AVM2 dynamic props in `DynamicMap`
(FNV-hashed `hashbrown`, `core/src/avm2/dynamic_map.rs`) and enumerates in
**bucket** order. The file's on-disk order is `lastName` then `firstName`
(verified by `xxd`, and by line 4 which round-trips it verbatim); Ruffle emits
`firstName` first. We — and Flash — enumerate in insertion order.

This is *exactly* the case already retired for `avm2/loader_load` in
`ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md:288-311`.
Ruffle's own `avm2/url_vars` test works around it with
`.toString().split("&").sort()` and a source comment; `loader_load` and `bom`
do not.

### Endgame — explicit answer

With causes 1+2 (+4) fixed and cause 3 permanent, `bom` reaches **6/9 matching
lines** and the three `dataFormat=variables` lines differ **only by pair
order**. It can be neither `pass` nor `ruffle_matched`:

- `pass` requires all 9 lines — impossible without emulating FNV-1a + hashbrown's
  SIMD bucket layout.
- `ruffle_matched` requires **both** `known_failure = true` in `test.toml` **and**
  a sibling `output.ruffle.txt` (`verify_output.py:4108-4131`). `bom` has
  neither, because Ruffle *passes* this test — `output.txt` **is** Ruffle's own
  output.

**`avm2/bom` stays `output_mismatch` forever.**

### Disposition route

- Add `avm2/bom` to
  `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`
  — extend the existing `avm2/loader_load` entry (lines 288-311) rather than
  writing a new one; same mechanism, same decision. (The doc is avm1-pathed but
  is the project-wide home for this category; `loader_load` — an avm2 test — is
  already filed there.)
- **`ignored_tests.txt` does NOT apply.** CLAUDE.md ties that file to
  `ACCEPTED_DIFFS.md` entries only, and the precedent confirms it: `loader_load`,
  `url_vars` and `bom` are all absent from `ruffle-tests/ignored_tests.txt`.

### Optional correctness fix (0 test flips, 2 matching lines)

Mirror Ruffle's shared `strip_bom` helper so the two call sites cannot drift:

1. `SWFModernRuntime/src/avm2/avm2_bytearray.c` — lift the body of `ba_to_string`
   (lines 827-846) into
   `const Avm2String* avm2_strip_bom(Avm2Context*, const uint8_t*, uint32_t)`;
   `ba_to_string` becomes a one-line call. `utf16_to_utf8` (line 404) is already
   there and stays `static`.
2. `SWFModernRuntime/include/avm2/avm2_globals.h` — declare it beside
   `avm2_bytearray_ext_of` (line 226).
3. `SWFModernRuntime/src/avm2/avm2_display.c` `ul_set_data` (lines 5944-5958) —
   replace the inline UTF-8-only strip with
   `ext->data = avm2_string(avm2_strip_bom(ctx, body, len));` (keep the
   `body == NULL` guard used by the #2032 error arm).

~20 lines. Fixes `bom` lines 5/6; also makes `URLStream`/`URLLoader` text
decoding correct for any future UTF-16 asset.

**Verdict A: NO-GO as a pass-count target. GO only as (i) the
RUFFLE_VS_FLASH entry and (ii) the 20-line `strip_bom` unification — and both
are better bundled with §C, which is where the actual +2 lives.**

---

## B. `from_avmplus/e4x/Global/e13_1_2_1` — XML 1.0 name-char tables

Path: `ruffle-tests/tests/swfs/from_avmplus/e4x/Global/e13_1_2_1`
(run with `--tests-dir=ruffle-tests/tests/swfs/from_avmplus/e4x/Global --test=e13_1_2_1`;
`--tests-dir=.../from_avmplus` does **not** find it).
`test.toml` = `num_ticks = 1`; **not** `known_failure`, so grade against the
expected output as written.

### Measured shape

Expected is 10 lines (`1/2/5/5.1/5.2/5.3/5/6/7 PASSED!` + the standard
`#2023 must inherit from Sprite` tail). We emit **293** lines: sections 1–5.3
pass, section 6 dumps 284 lines of the form

```
[0x80-0xB6] : Invalid char accepted as start : Invalid Char accepted as other
[0xB8-0xBF] : Invalid char accepted as start : Invalid Char accepted as other
...
[0xD7A4-0xFFFF] : Invalid char accepted as start : Invalid Char accepted as other
```

and section 7 fails as a pure consequence of 6.

**Key measurement: `grep -c "not accepted"` over our actual output = 0.** Every
failure is over-*acceptance*. The fix is purely a narrowing — we never reject
anything the test wants accepted. That removes the usual "widen vs narrow"
ambiguity from the blast-radius question.

The test (`Test.as:164-538`) brute-forces all 65536 code points, marking each
with `BEGIN`/`OTHER` from the XML 1.0 `BaseChar | Ideographic | CombiningChar |
Digit | Extender` productions plus `_` (BEGIN|OTHER), `.` `-` and `0-9` (OTHER),
and explicitly excludes `:`. It then checks `isXMLName(c + 'x')` and
`isXMLName('x' + c)`.

### Cause — the predicate treats every byte ≥ 0x80 as a name char

Both copies (byte-for-byte identical, same comment) short-circuit non-ASCII:

- `SWFModernRuntime/src/avm2/avm2_e4x.c:411-435` — `avm2_e4x_is_xml_name`
  (declared `SWFModernRuntime/include/avm2/avm2_e4x.h:137`)
- `SWFModernRuntime/src/avm2/avm2_nsqname.c:128-152` — `static ns_is_xml_name`

```c
// avm2_e4x.c:413
if (!((c0 >= 'A' && c0 <= 'Z') || (c0 >= 'a' && c0 <= 'z') || c0 == '_'
      || c0 >= 0x80))          // <-- everything non-ASCII is a name start
```

Both comments say "the corpus only exercises ASCII" — `e13_1_2_1` is the test
that disproves that. Confirmed there is no third copy (`grep -rn "c0 >= 0x80"`
returns exactly these two; nothing in `SWFRecomp/`).

Call sites of the shared predicate: `avm2_globals.c:1063` (`isXMLName` global),
`avm2_xml.c:496` (child assignment gate), `:1485` / `:1529` (`setName` /
`setLocalName` → `throw_1117`), `:1554` (`ns_to_object` prefix drop), and
`avm2_nsqname.c:221` (`new Namespace(prefix, uri)` prefix drop).

### Oracle — port Ruffle's tables verbatim

`~/CC/ruffle/core/src/avm2/e4x/is_xml_name.rs` (460 lines) is a direct port of
avmplus `AvmCore.cpp:3478` and holds exactly the four sorted range tables:

| Table | Ranges | Max value |
|---|---|---|
| `LETTER_TABLE` (BaseChar + Ideographic) | 205 | `0xD7A3` |
| `DIGIT_TABLE` | 15 | `0x0F29` |
| `COMBINING_TABLE` | 95 | `0x309A` |
| `EXTENDER_TABLE` | 11 | `0x30FE` |

326 ranges total, **all ≤ 0xFFFF → `uint16_t` pairs, 1304 bytes of rodata**.
All four are verified sorted by Ruffle's own unit test
(`verify_is_xml_name_table_order`).

Ruffle's predicate:
```
first char: is_letter(c) || c == '_'        (note: ':' NOT allowed)
rest:       is_digit || is_letter || '.' || '-' || '_' || is_combining || is_extender
lone surrogate / invalid unit: false  (chars() yields Err -> false)
```

### Verification (done, not predicted)

I parsed the 538 `markRange` calls out of `Test.as` and the four tables out of
`is_xml_name.rs`, then evaluated the test's own four assertions over all 65536
code points:

```
mismatches: 0
```

So porting these tables makes sections 6 and 7 emit `PASSED!` and the test
flips to **`pass`**. No judgement calls, no avmplus-vs-Ruffle divergence.

### Fix plan

**Both predicate copies collapse into one.**

1. `SWFModernRuntime/src/avm2/avm2_e4x.c`, above `avm2_e4x_is_xml_name`:
   ```c
   // XML 1.0 4th ed. BaseChar|Ideographic / Digit / CombiningChar / Extender
   // (w3.org/TR/2004/REC-xml-20040204), as avmplus AvmCore.cpp:3478 and Ruffle
   // core/src/avm2/e4x/is_xml_name.rs. Sorted, non-overlapping, all <= 0xFFFF.
   static const uint16_t E4X_LETTER[][2]    = { {0x0041,0x005A}, ... };  // 205
   static const uint16_t E4X_DIGIT[][2]     = { ... };                    //  15
   static const uint16_t E4X_COMBINING[][2] = { ... };                    //  95
   static const uint16_t E4X_EXTENDER[][2]  = { ... };                    //  11
   static int in_ranges(const uint16_t (*t)[2], size_t n, uint32_t c);    // bsearch
   ```
2. A WTF-8 code-point reader (5 lines) —
   `static int e4x_next_cp(const unsigned char* b, uint32_t len, uint32_t* i, uint32_t* cp)`
   returning 0 on a malformed sequence. It must **surface lone surrogates as
   `0xD800..0xDFFF`** rather than folding them to U+FFFD: `String.fromCharCode`
   stores them as 3-byte WTF-8 (`avm2_string.c:275-317`, explicit comment), the
   test feeds all 2048 of them in, and they must answer `false` — which they do
   automatically, since no table contains them.
3. Rewrite `avm2_e4x_is_xml_name` (`avm2_e4x.c:413`):
   - empty → 0;
   - **keep an ASCII fast path** (`cp < 0x80` → today's exact character class).
     This is provably equivalent below 0x80 (no combining/extender ranges start
     under 0x0300, digits are only `0-9`) and keeps the XML-assignment hot path
     at its current cost;
   - `cp >= 0x80` → binary search. First cp: `LETTER`; subsequent:
     `DIGIT || LETTER || '.' || '-' || '_' || COMBINING || EXTENDER`;
   - malformed byte sequence → 0.
4. `SWFModernRuntime/src/avm2/avm2_nsqname.c`: delete `ns_is_xml_name`
   (lines 128-152), add `#include <avm2/avm2_e4x.h>` to the include block
   (lines 19-25), and call `avm2_e4x_is_xml_name` at line 221.

Size: ~360 lines, of which ~330 are the mechanically-transcribed tables
(Ruffle's file has a `regex` recipe in its header comment; a 10-line Python
transcriber from `is_xml_name.rs` to C is the safe way to produce them — do
**not** hand-type 326 ranges).

### Predicted yield

**+1** (`e4x/Global/e13_1_2_1`). No hidden riders: the other 12 non-passing
`e4x/*` tests were checked and none fail on name validity
(`e11_1_2`, `e11_1_4`, `regress-263935`, `e12_1`, `e13_4_4_17`, `e13_4_4_2`,
`e13_4_4_32/v9` + 5 `ruffle_matched`).

### Risks

- **Performance.** `avm2_e4x_is_xml_name` sits on the E4X child-assignment path
  (`avm2_xml.c:496`). A naive 205-entry linear scan per character would be a
  real regression for XML-heavy AVM2 games. The ASCII fast path + binary search
  removes this entirely; it is a requirement, not an optimisation.
- **Narrowing, not widening.** Behaviour changes *only* for code points ≥ 0x80
  outside the tables. Where that bites: `setName`/`setLocalName` start throwing
  `#1117` for such names, `x.<nonASCIIname> = v` becomes a silent no-op
  (`avm2_xml.c:496`), and non-ASCII `Namespace` prefixes get dropped
  (`avm2_nsqname.c:221`, `avm2_xml.c:1554`).
- **`_rando` / `_swfbridge` game content** is not CI-graded but does contain
  non-ASCII `.as` files; none use non-ASCII XML names (checked), but an E4X-using
  game with a Cyrillic/CJK tag name would newly hit the tables. Cyrillic
  (0x0401-0x04F9) and CJK (0x4E00-0x9FA5) are *in* `LETTER_TABLE`, so real-world
  content is fine; only symbols/punctuation/emoji change.

### Canaries

Content-grep of the whole corpus for XML-name-validity assertions found only
three `.as` files mentioning `isXMLName`, and an intersection of "file contains
non-ASCII bytes" × "file mentions XML/QName/Namespace" gives 11 files — **none
of which uses non-ASCII as a name**; every hit is non-ASCII *text content*
(`Sören Lehmenkühler`, `£`, `ą`, `😭`). Blast radius is genuinely small.

Already-passing tests that must stay passing (regression risk if the predicate
mis-narrows):

| Test | Why |
|---|---|
| `from_avmplus/e4x/Global/isXMLNameTypeErr` | `pass` 5/5 — the #1050-coercion arm of the same global; must not change |
| `from_avmplus/as3/RuntimeErrors/Error1117InvalidXmlName` | `pass` 2/2 — the `setName(undefined)` → #1117 path |
| `from_avmplus/e4x/Expressions/e11_2_1` | `pass` — `"<f><fname>Sören Lehmenkühler</fname></f>"`; non-ASCII **values** must survive untouched |
| `from_avmplus/e4x/Statements/e12_1` | already `output_mismatch` 13/17; must not get worse (non-ASCII in comments only) |
| `avm2/xml_set_name`, `avm2/namespace_constr`, `avm2/qname_constr`, `avm2/qname_constr_namespace`, `avm2/qname_tostring`, `avm2/qname_valueof`, `avm2/qname_indexing`, `avm2/qname_enumeration`, `avm2/xml_attribute`, `avm2/xml_methods_settings` | direct users of the two call-site families |
| `avm2/op_escxelem`, `avm2/op_escxattr`, `avm2/dependent_strings` | non-ASCII + XML escaping |
| `from_avmplus/ecma3/Unicode/*` (`uc_005`, `uc_006`, `ucs4_bug_515947`) | WTF-8 decoder exercise; the new code-point reader must not disturb them |
| whole `from_avmplus/e4x/*` (177 tests: 164 pass / 5 ruffle_matched / 8 mismatch) | cheapest single directory that covers every call site |
| `ruffle-tests/tests/swfs/regression` | standing canary policy |

Local stash-diff sweep before CI: the 177-test `e4x/` directory plus the ~15
named `avm2/*` tests is ~200 tests, well inside the parallel-batching budget.

**Verdict B: GO.** Mechanical, oracle-complete, exhaustively pre-verified, +1.

---

## C. Adjacent finding (NOT one of my two targets) — the real yield here

While chasing `bom` cause 4 I found that three pieces of `flash.net`/`flash.utils`
are missing outright, and they account for two more failing tests:

- `flash.utils.escapeMultiByte` / `unescapeMultiByte` are **not registered as
  package functions**. Only a private `urlvars_escape` helper exists
  (`avm2_globals.c:2672-2688`) and it already implements the exact
  escapeMultiByte rule (ASCII alnum pass through, every other UTF-8 byte → `%XX`,
  stop at the first NUL).
  → `avm2/escape_multi_byte` is `output_mismatch` **1/45**.
- `flash.net.URLVariables` is registered with **`toString` only**
  (`avm2_globals.c:3005-3013`) — no `URLVariables(str)` constructor, no
  `decode()`. Measured stderr:
  `AVM2 uncaught error: TypeError: Error #1006: decode is not a function.`
  → `avm2/url_vars` is `output_mismatch` **3/27**, dying at line 4 of 27.

`url_vars` is the interesting one: **it sorts its output**
(`.toString().split("&").sort()`, with a source comment naming the enumeration-order
problem), so unlike `bom`/`loader_load` it is **not** blocked by cause 3 and
**can reach `pass`**.

Oracle is a 55-line AS file, `~/CC/ruffle/core/src/avm2/globals/flash/net/URLVariables.as`
— `decode` splits on `&`, `indexOf("=")`, throws `#2101` (already in our error
table, `avm2_error.c:803`) when there is no `=`, does `pair.replace("+", " ")`
(**first occurrence only** — this is load-bearing for `url_vars` lines 25/27),
then `unescapeMultiByte` on both halves, and accumulates repeats into an Array.

Estimated ~120 lines in `avm2_globals.c` for **+2** (`escape_multi_byte`,
`url_vars`), and it simultaneously closes `bom` cause 4 so that the three
remaining `bom` lines differ *only* by pair order — which makes the
RUFFLE_VS_FLASH entry in §A clean rather than approximate. Recommend this be
picked up as its own wave-2 item.

---

## Summary of recommendations

| Item | Effort | Yield | Go? |
|---|---|---|---|
| B — XML 1.0 name tables, both predicate copies | ~360 lines (330 generated) | **+1** | **GO** |
| A2 — shared `avm2_strip_bom` (UTF-16 in `ul_set_data`) | ~20 lines | 0 flips, +2 lines on `bom` | GO (bundle with C) |
| A3 — `avm2/bom` → `RUFFLE_VS_FLASH_DIFFERENCES.md` (extend the `loader_load` entry); **not** `ignored_tests.txt` | doc only | 0 | GO |
| A1 — "make `bom` pass" | — | impossible | **NO-GO** |
| C — `escapeMultiByte`/`unescapeMultiByte` + `URLVariables(str)`/`decode()` | ~120 lines | **+2** | GO (new wave-2 item) |
