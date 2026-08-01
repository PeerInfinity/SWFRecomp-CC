# Wave-2 report — XML 1.0 name tables + BOM decode unification

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-aafaa5f242446a55c`
(branched from `1c7c23761`). Patch: `../wave2/xmlnames.patch` (413 lines,
6 files, +252/-59). Runtime-only — no recompiler change, no new files.
Not committed, not pushed, no CI dispatched.

All measurements are local `--mode` default (no-graphics) single-test runs in
the worktree, against the main tree's recompiler build. Baseline statuses are
from `ruffle-tests/tests/swfs/{avm2,from_avmplus}/_results/results_graphics.json`
at HEAD, cross-checked by two clean pre-edit local runs.

---

## What changed

### 1. XML 1.0 name-char tables (`avm2_e4x.c`, `avm2_nsqname.c`)

Both byte-identical copies of the "every byte >= 0x80 is a name character"
predicate are gone, replaced by **one** implementation in `avm2_e4x.c`:

- Ruffle's four range tables transcribed verbatim from
  `~/CC/ruffle/core/src/avm2/e4x/is_xml_name.rs` by a script
  (`../wave2/transcribe.py`), never hand-typed:
  `E4X_LETTER` 205, `E4X_DIGIT` 15, `E4X_COMBINING` 95, `E4X_EXTENDER` 11
  ranges — 326 total, all `<= 0xFFFF`, stored as `uint16_t[2]`
  (1304 bytes of rodata). The transcriber asserts every range is well-formed,
  in the BMP, and **strictly** increasing, which is what makes binary search
  legal (Ruffle's own unit test only asserts non-strict sortedness).
- `in_ranges()` — binary search; short-circuits anything past the BMP.
- `e4x_next_cp()` — WTF-8 code-point reader that returns 0 on a malformed
  sequence and **surfaces lone surrogates as `0xD800..0xDFFF`** instead of
  folding them to U+FFFD. No table contains a surrogate, so they answer
  "not a name char", which is exactly what Ruffle's `chars()` `Err` arm does.
- `avm2_e4x_is_xml_name()` — keeps an **ASCII fast path** (`cp < 0x80` uses the
  old character class). This is on the E4X child-assignment hot path
  (`avm2_xml.c:496`); a linear scan of 205 ranges per character would have been
  a real regression for XML-heavy content. Equivalence below 0x80 is not
  assumed, it is checked: Letter contributes only `A-Z`/`a-z`, Digit only
  `0-9`, and CombiningChar (first range 0x0300) and Extender (first 0x00B7)
  do not reach under 0x80.
- `avm2_nsqname.c` loses its private `ns_is_xml_name` (25 lines) and calls the
  shared predicate; `#include <avm2/avm2_e4x.h>` added.

### 2. BOM decode unification (`avm2_bytearray.c`, `avm2_display.c`, `avm2_globals.h`)

`ba_to_string`'s BOM logic is lifted into
`const Avm2String* avm2_strip_bom(Avm2Context*, const uint8_t*, uint32_t)`
(declared in `avm2_globals.h` beside `avm2_bytearray_ext_of`), and
`ul_set_data` now calls it instead of its own UTF-8-only strip. `ba_to_string`
becomes two lines. `utf16_to_utf8` / `avm_utf8_lenient` stay `static`.

Side effect worth naming: the no-BOM path in `ul_set_data` now goes through
`avm_utf8_lenient` rather than `avm2_string_new` on raw bytes. That is *closer*
to Ruffle, whose `set_data` calls `AvmString::new_utf8_bytes` after `strip_bom`.

### 3. Doc disposition for `avm2/bom`

`ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md` —
the existing "AVM2 dynamic-property enumeration order: `URLVariables.toString`"
entry is extended with a `### Same mechanism, second test: avm2/bom`
subsection, per the brief (same mechanism, same decision, so no new top-level
entry). It records the ceiling (6/9), why `ruffle_matched` is also unreachable
(needs both `known_failure` **and** `output.ruffle.txt`; `bom` has neither
because Ruffle passes the test, so `output.txt` *is* Ruffle's output), and that
this is deliberately **not** an `ignored_tests.txt` entry.

I also corrected that entry's stale `loader_load` count: it said 124/128 with
"the other two are the uncaught-error tracing held back in `d1c307c51`", but
that tracing has since landed and the baseline JSON reads **126/128**, i.e. the
two remaining lines are now exactly the URLVariables-order ones the entry
describes.

Independently verified the entry's factual claim with `xxd`: the fixtures are
`lastName` first on disk (`efbbbf6c 6173 744e...`), the expected output is
`firstName` first.

---

## Per-test ledger (before -> after)

### Targets

| Test | Before | After |
|---|---|---|
| `from_avmplus/e4x/Global/e13_1_2_1` | `output_mismatch` 7/10 (293 actual lines) | **`pass` 10/10** |
| `avm2/bom` | `output_mismatch` 4/9 | `output_mismatch` **6/9** (still fails; lines 5/6 fixed) |

`bom`'s remaining diff is exactly the three `dataFormat=variables` lines, and
they now differ **only by pair order** — the UTF-16 garbage is gone:

```
     4  URLLoader dataFormat=text utf8: lastName=Jones&firstName=Tom
     5  URLLoader dataFormat=text utf16le: lastName=Jo∀nes&firstName=Tom     (was: ??lastName=Jo"nes...)
     6  URLLoader dataFormat=text utf16be: lastName=Jo∀nes&firstName=Tom     (was: ??lastName=Jo"nes...)
-    7  URLLoader dataFormat=variables utf8: firstName=Tom&lastName=Jones
+    7  URLLoader dataFormat=variables utf8: lastName=Jones&firstName=Tom
-    8  URLLoader dataFormat=variables utf16le: firstName=Tom&lastName=Jo%E2%88%80nes
+    8  URLLoader dataFormat=variables utf16le: lastName=Jo∀nes&firstName=Tom
-    9  URLLoader dataFormat=variables utf16be: firstName=Tom&lastName=Jo%E2%88%80nes
+    9  URLLoader dataFormat=variables utf16be: lastName=Jo∀nes&firstName=Tom
```

Lines 8/9 still lack the `%E2%88%80` escaping because `dataFormat="variables"`
does not construct a `URLVariables` — that is the sibling agent's
`URLVariables`/`escapeMultiByte` item, not mine. Once that lands, `bom` reaches
its 6/9 ceiling with all three residual lines being pure pair-order.

### Canaries

**53 tests run post-change. 1 fixed, 1 improved, 51 unchanged, 0 regressions.**

Every named canary from the brief, plus the regression suite and an 18-test
random sample of baseline-passing `e4x/`.

*Predicate call-site families (all `pass` before and after):*

| Test | Baseline | After |
|---|---|---|
| `from_avmplus/e4x/Global/isXMLNameTypeErr` | pass 5/5 | pass |
| `from_avmplus/as3/RuntimeErrors/Error1117InvalidXmlName` | pass 2/2 | pass |
| `from_avmplus/e4x/Expressions/e11_2_1` | pass 40/40 | pass |
| `avm2/xml_set_name` | pass 34/34 | pass |
| `avm2/namespace_constr` | pass 253/253 | pass |
| `avm2/qname_constr` | pass 32/32 | pass |
| `avm2/qname_constr_namespace` | pass 24/24 | pass |
| `avm2/qname_tostring` | pass 25/25 | pass |
| `avm2/qname_valueof` | pass 29/29 | pass |
| `avm2/qname_indexing` | pass 23/23 | pass |
| `avm2/qname_enumeration` | pass 9/9 | pass |
| `avm2/xml_attribute` | pass 35/35 | pass |
| `avm2/xml_methods_settings` | pass 3/3 | pass |
| `avm2/op_escxelem` | pass 2/2 | pass |
| `avm2/op_escxattr` | pass 2/2 | pass |

`xml_set_name` and `Error1117InvalidXmlName` are the two that matter most —
they are the `#1117` throw path, the one the narrowing could most easily have
broken. `namespace_constr` (253 lines) covers the `avm2_nsqname.c` call site
that changed implementation.

*WTF-8 decoder exercise (the new `e4x_next_cp` must not disturb these):*

| Test | Baseline | After |
|---|---|---|
| `from_avmplus/ecma3/Unicode/uc_005` | pass 10/10 | pass |
| `from_avmplus/ecma3/Unicode/uc_006` | pass 56/56 | pass |
| `from_avmplus/ecma3/Unicode/ucs4_bug_515947` | pass 3/3 | pass |

*Pre-existing mismatches — none got worse (exact line counts re-measured):*

| Test | Baseline | After | |
|---|---|---|---|
| `avm2/bom` | output_mismatch 4/9 | output_mismatch **6/9** | improved |
| `from_avmplus/e4x/Statements/e12_1` | output_mismatch 13/17 | output_mismatch 13/17 | same 4 diff lines |
| `avm2/dependent_strings` | output_mismatch 46/84 | output_mismatch 46/84 | same |
| `avm2/loader_load` | output_mismatch 126/128 | output_mismatch 126/128 | same |
| `avm2/escape_multi_byte` | output_mismatch 1/45 | output_mismatch 1/45 | same |
| `avm2/url_vars` | output_mismatch 3/27 | output_mismatch 3/27 | same |

The last three are the sibling agent's targets and are untouched by this patch;
their stderr still names the missing pieces (`Error #1065: Variable
escapeMultiByte is not defined`, `Error #1006: decode is not a function`).

*`e4x/` random sample, 18 baseline-passing tests across every sub-directory
(`Expressions`, `Namespace`, `QName`, `Regress`, `TypeConversion`, `Types`,
`XML`, `XMLList`):* **18/18 pass.**

*`regression` suite (standing policy) — the AVM2 ByteArray / loader / string /
XML subset:* **10/10 pass** (`avm2_embed_bytearray`, `avm2_loader_stub`,
`xml_onload_type1_args`, `avm2_gc_string_concat_reclaim`,
`avm2_gc_string_survives_collect`, `avm2_typed_value_ops`, `avm2_agi_shell`,
`lv_cross_swf_version`, `avm2_sharedobject_flushstatus`,
`avm2_localconnection_domain`).

---

## Verification beyond the harness

Because the harness is slow under a 6-agent load, the predicate was also proved
out directly. Both checks are scripted and re-runnable.

1. **Predicate logic vs. the tables** — `../wave2/mk_selftest.py` slices the new
   code straight out of `avm2_e4x.c` into a standalone binary and, for **all
   65535** non-NUL code points, compares `isXMLName(c + "x")` and
   `isXMLName("x" + c)` against a linear-scan reference, i.e. exactly the two
   assertions `Test.as` makes. Plus 25 spot cases (empty, `:`, `a:b`, astral
   U+1F40C, lone surrogate U+D83D, truncated 2- and 3-byte sequences, bare
   `0xFF`, initial-vs-non-initial Extender/CombiningChar).

   ```
   BEGIN mismatches: 0
   OTHER mismatches: 0
   SPOT  mismatches: 0
   ```

   This is what certifies the ASCII fast path, the binary search and the WTF-8
   reader — the three things I wrote by hand.

2. **Tables vs. `Test.as`** — `../wave2/verify_tables.py` re-parses the tables
   out of the patched C file and replays all 538 `markRange` calls from
   `e13_1_2_1/Test.as`, then compares the resulting BEGIN and OTHER character
   classes:

   ```
   E4X_LETTER    C=34514  Test.as=34514  C-only=0  AS-only=0
   E4X_DIGIT     C=149    Test.as=152    C-only=0  AS-only=3   <- '-', '.', '_'
   E4X_COMBINING C=437    Test.as=437    C-only=0  AS-only=0
   E4X_EXTENDER  C=18     Test.as=18     C-only=0  AS-only=0
   BEGIN class differs at: 0
   OTHER class differs at: 0
   ```

   The three `AS-only` entries are `-`, `.` and `_`, which `Test.as` marks
   inline near the Digit block and the predicate handles as explicit
   characters — a labelling artifact of my parser, not a gap. The two
   `differs at: 0` lines are the load-bearing result.

Also: `gcc -Wall -Wextra` on the standalone slice is clean, and all four
modified `.c` files pass `gcc -fsyntax-only` against the real include set.

---

## Predicted CI delta

**+1** (`from_avmplus/e4x/Global/e13_1_2_1`), matching the wave-1 prediction.

`avm2/bom` improves 4/9 -> 6/9 but does not flip status, so it contributes 0.
No other test is predicted to move. This is an in-isolation figure and, per the
arc's convention, a lower bound.

Note `e13_1_2_1` lives in `from_avmplus`, so the flip is only visible on a
`categories=full` run — `categories=all` will show +0 for this patch.
The change is AVM2 runtime, so `mode=graphics` + `categories=full` is the right
dispatch.

### Blast radius

Behaviour changes **only** for code points >= 0x80 that are outside the tables.
Every change is a narrowing — `grep -c "not accepted"` over the old
`e13_1_2_1` output was 0, so we never rejected anything the corpus wants
accepted. Where it bites: `setName`/`setLocalName` now throw `#1117` for such
names, `x.<nonASCIIname> = v` becomes a silent no-op, and non-ASCII `Namespace`
prefixes are dropped. Real-world content is safe — Cyrillic (0x0401-0x04F9) and
CJK (0x4E00-0x9FA5) are both inside `E4X_LETTER`; only symbols, punctuation and
emoji change.

---

## Deviations from the brief

0. **Batch your canaries.** `--test` is repeatable, and one invocation compiles
   the runtime once: the same 15 avm2 tests took ~8 min as one batched call
   versus a projected ~50 min at `-P 2` one-per-invocation (per-test `c=`
   dropped from ~65s to ~4s). I switched mid-sweep. Recommend the coordinator's
   cross-patch sweep use one batched call per suite.
1. **Test data had to be copied into the worktree.** The test SWFs are
   gitignored, so a fresh worktree has none of them and every
   `verify_output.py` invocation fails with "tests directory not found". I
   `rsync`ed the needed dirs (`from_avmplus/e4x`, `ecma3/Unicode`,
   `as3/RuntimeErrors`, `regression`, and 17 named `avm2/` tests) from the main
   tree, excluding `Recompiled*`. They land on gitignored paths, so `git status`
   stays clean — confirmed. **Worth telling the other wave-2 agents**, since
   copying the recompiler build alone is not enough to run anything.
2. **`e13_1_2_1`'s tests-dir.** The brief's
   `--tests-dir=.../from_avmplus/e4x/Global --test=e13_1_2_1` works, but so does
   `--tests-dir=.../from_avmplus --test=e4x/Global/e13_1_2_1` (a slashed
   `--test` path), which is the form the coordinator's sweep will want.
3. **Corrected a stale number in the doc I was asked to extend** (`loader_load`
   124/128 -> 126/128), rather than adding the `bom` text on top of a claim the
   current baseline contradicts.
4. **Did not touch `ignored_tests.txt`** — as instructed, and consistent with
   `loader_load`/`url_vars` both being absent from it.
5. **Did not implement `URLVariables`/`escapeMultiByte`** — sibling agent's.
   The one place the two patches interact is `bom` lines 8/9 (see above) and
   the `ul_set_data` comment, which I reworded rather than deleted so it still
   flags that `"variables"` is unimplemented.

### Merge-conflict note for the coordinator

`ul_set_data` in `avm2_display.c` is the likely collision point: my patch
rewrites its `"text"`/`"variables"` tail, and the URLVariables agent will want
to construct a `URLVariables` in that same tail. The resolution is
straightforward — keep `avm2_strip_bom(ctx, body, len)` as the decode step and
feed *its result* to the `URLVariables` constructor, which is exactly Ruffle's
`classes().urlvariables.construct(&[strip_bom(body)])`.

---

## Suggested commit message

```
avm2: XML 1.0 name-char tables, one shared predicate, shared BOM decode

avm2_e4x_is_xml_name and nsqname.c's ns_is_xml_name were byte-identical
copies that treated every byte >= 0x80 as a name character, both with a
comment saying the corpus only exercises ASCII. from_avmplus
e4x/Global/e13_1_2_1 brute-forces all 65536 code points and disproves it:
we emitted 293 lines against an expected 10, every failure an
over-acceptance.

Collapse both copies into one implementation in avm2_e4x.c, backed by the
XML 1.0 4th ed. BaseChar|Ideographic / Digit / CombiningChar / Extender
range tables transcribed from Ruffle core/src/avm2/e4x/is_xml_name.rs
(205/15/95/11 ranges, all <= 0xFFFF, 1304 bytes of rodata). The predicate
keeps an ASCII fast path and binary-searches above it — it sits on the E4X
child-assignment path, where a linear scan of 205 ranges per character
would have been a regression. The new WTF-8 reader surfaces lone
surrogates rather than folding them to U+FFFD, so they answer "not a name
character" as Ruffle's chars() Err arm does.

Verified two ways beyond the harness: the predicate matches a linear-scan
reference on all 65535 non-NUL code points in both first- and
subsequent-character position, and the tables reproduce Test.as's own
BEGIN/OTHER classes with zero differing code points.

Also unify UTF-16 BOM decoding: lift ba_to_string's logic into a shared
avm2_strip_bom and use it in ul_set_data, which previously handled only
the UTF-8 BOM and handed UTF-16LE/BE response bodies to the string
constructor as raw bytes. Mirrors Ruffle's strip_bom having one call site
per consumer.

Document avm2/bom as permanently unpassable (URLVariables enumeration
order) by extending the existing loader_load entry in
RUFFLE_VS_FLASH_DIFFERENCES.md, and refresh that entry's stale line count.

e4x/Global/e13_1_2_1: output_mismatch 7/10 -> pass
avm2/bom: output_mismatch 4/9 -> 6/9 (ceiling; pair order is permanent)
```
