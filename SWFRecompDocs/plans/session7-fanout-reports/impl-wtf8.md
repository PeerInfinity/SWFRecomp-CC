# Batch A — the string's code-unit model at the non-ASCII boundary (WTF-8)

Session 7, polish sweep. Worktree `agent-a85235f11b1019f4d`, base = `master`
@ `a9055f5e3`. **Verdict: IMPLEMENT — landed, +5 (triage predicted +4).**

Patch: `scratchpad/patches/wtf8.patch` (4 files, all under
`SWFModernRuntime/src/avm2/`, +236/−45).

---

## 1. Design chosen: canonical WTF-8 storage (option (a)), NOT a
   pair-combining pass per decoder

### Why (a) won on the survey, before any code

The decisive observation is that **the existing UTF-8 decoders in this runtime
are already WTF-8 decoders and nobody had noticed.** Every one of them is
written as the classic 4-arm `c < 0x80 / c < 0xE0 / c < 0xF0 / else` ladder
with no surrogate-range validation, so a 3-byte `ED A0 80 .. ED BF BF`
sequence *already* decodes to a code point in `0xD800..0xDFFF`:

| site | what it does with `ED A0 BD` today | needed |
|---|---|---|
| `avm2_string.c utf16_length` | counts it as 1 code unit | ✓ correct |
| `avm2_string.c utf16_unit_at` | returns `0xD83D` | ✓ correct |
| `avm2_globals.c utf8_next_cp` (escape) | `cp = 0xD83D` → `%uD83D` | ✓ correct |
| `avm2_regexp.c retext_build` | emits unit `0xD83D` | ✓ correct |
| `avm2_bytearray.c avm_utf8_next` | `cp = 0xD83D` | ✓ correct |
| `avm2_string.c string_case_convert` | round-trips unchanged | ✓ correct |

So the "generalize the decoder" half of option (a) was **already done**. The
only thing standing between the runtime and a working code-unit model was a
handful of *deliberate* `cp = 0xFFFD` lines that threw the surrogate away on
the way IN, plus one missing rule on the way OUT. Option (b) would have meant
adding a combining pass to each of the six decoders above — strictly more work
for a strictly worse model.

`avm2/invalid_utf8` proves the decoders were already right: its line 10
(`escape(ByteArray[ED A0 BD])` → `%uD83D`) **passed at baseline**. Only the
line that needed the *pair* to re-form was failing.

### The invariant

> An `Avm2String` holds **canonical WTF-8**: UTF-8 extended so U+D800..U+DFFF
> may appear as `ED A0 80 .. ED BF BF`, with the rule that a high surrogate
> immediately followed by a low one is **always** stored as the 4-byte UTF-8
> of the combined astral code point, never as the 6-byte CESU-8 pair.

Canonicality is not cosmetic — it is what keeps `avm2_string_equals`
(a `memcmp`) equivalent to code-unit equality. That is exactly what
`ecma3/Unicode/utf8count` asserts: the astral **literal** `"123𠮟咤ABC…"`
must `==` the string built by `+=`-ing `String.fromCharCode` of each
individual UTF-16 code unit. Plain (non-canonical) WTF-8 would have stored
those as `F0 A0 AE 9F` vs `ED A1 82 ED BE 9F` and the test would still fail.

Concatenation is the **only** operation that can bring an unpaired high and an
unpaired low together, so it re-normalizes the seam (this is the WTF-8 spec's
own concatenation rule). Everything else emits canonical form directly.
`Array.join` and `Array.toString` route through `avm2_string_concat`, so the
`split("").join("")` idiom is covered for free.

### The print boundary stays genuine UTF-8

Hexdumping the target `output.txt` files settled this empirically rather than
by assumption:

- `avm2/invalid_utf8` line 11 is `f0 9f 90 8c` — **4-byte UTF-8**, not CESU-8.
  Flash prints a *paired* surrogate as the astral character.
- The same file's `escape()` lines (`%uD83D`, `%uD83D%uDC0C`) show the
  code-unit view is only observable through `escape`, never through raw trace.

So `native_trace` now converts an **unpaired** surrogate to U+FFFD on its way
to stdout (matching Ruffle's `WString → to_utf8_lossy` at its own trace
boundary, and matching what this runtime already printed before the change),
while a paired surrogate — already stored as 4-byte UTF-8 — passes straight
through. **Net effect on trace bytes for every string that existed before this
change: zero.**

### The recompiler needs NO change — verified, not assumed

`SWFRecomp/src/abc/abc_emit.cpp:54 escapeCString` octal-escapes the ABC string
pool byte-for-byte, so the runtime sees whatever ASC wrote. The astral literal
in `utf8count` arrives as
`"123\360\240\256\237\345\222\244ABC…"` — `F0 A0 AE 9F`, **4-byte UTF-8**,
already the canonical form.

A corpus-wide grep for CESU-8 in every emitted pool:

```
cd ruffle-tests/tests/swfs && grep -rlE '\\355\\2[4-7][0-7]' --include=abc0_tables.c .
→ zero hits
```

**No SWF in the 4424-test corpus ships a CESU-8 string constant.** The
recompiler was never rebuilt for this batch and the patch is runtime-only.

---

## 2. Site inventory (the whole change)

| file | site | change |
|---|---|---|
| `avm2_value.c` | `avm2_string_concat` | WTF-8 seam fold (high@end + low@start → astral); + the invariant doc comment |
| `avm2_string.c` | `string_from_char_code` | drop `cp = 0xFFFD`; a partnerless surrogate stays a surrogate |
| | `string_char_at` | astral half → WTF-8 lone surrogate (was U+FFFD) |
| | `avm2_string_split_plain` (`split("")`) | same |
| | `make_sub16` (new) | extract a code-unit range as canonical WTF-8, splitting an astral code point into the correct half |
| | `slice` / `substr` / `substring` | use `make_sub16` (previously rounded to a codepoint boundary — a latent bug: `"𠮟".slice(0,1)` returned the whole character) |
| `avm2_globals.c` | `global_unescape` | drop `cp = 0xFFFD` |
| | `uri_decode` | drop `cp = 0xFFFD`; fold a high+low pair spanning two `%`-sequences |
| | `uri_encode` | **throw #1052** on an unpaired surrogate (ECMA-262 §15.1.3.1 step 8); takes the fn name for the message |
| | `native_trace` | unpaired surrogate → U+FFFD at the print boundary |
| `avm2_bytearray.c` | `avm_utf8_lenient` | fold a decoded CESU-8 pair into the astral code point |

**Detection is unambiguous everywhere:** `ED` followed by `>= 0xA0` is a byte
pattern strict UTF-8 can never produce (valid `ED` leads are restricted to a
second byte of `80..9F`, i.e. U+D000–U+D7FF), so no real character can be
mistaken for a surrogate and no `0xED` check can fire on valid text.

---

## 3. Per-test before / after

All runs `--mode=graphics` (per-change CI mode), from the worktree.

### The batch — 5/5 flipped, +5 vs a predicted +4

| test | suite | before | after |
|---|---|---|---|
| `invalid_utf8` | avm2 | FAIL (1 line: `🐌` printed as 6 mojibake chars) | **PASS** |
| `stylesheet` | avm2 | FAIL (1 line: `😜` → `��`) | **PASS** |
| `ecma3/Unicode/utf8count` | from_avmplus | FAIL (`str_utf8 == str_utf16` false) | **PASS** |
| `ecma3/String/e15_5_4_5_4` | from_avmplus | FAIL (2 lines: 56200/57199 → 65533) | **PASS** |
| `as3/RuntimeErrors/Error1052InvalidUriPassed` | from_avmplus | FAIL (`no error`) | **PASS** |

`avm2/stylesheet` is worth calling out because it was *not* obviously a string
test. Its `escapeString()` helper walks the selector with `charAt(i)` and
re-concatenates — so it is precisely `charAt` (astral → two lone surrogates)
plus the concat seam (re-forming the pair). It fell out of the design with no
StyleSheet-parser work at all; the triage's guess that it needed the CSS
parser's string path was wrong, and in the batch's favour.

### The four "adjacent through a different converter" candidates — NOT WTF-8

Each was run at baseline and its diff read. All four are confirmed to be a
different mechanism; none is blocked on the string model.

| test | gap | actual cause (from the baseline diff) |
|---|---:|---|
| `avm2/bom` | 5 | **three** causes, none of them surrogates: URLLoader does not strip a UTF-16 BOM (`﻿` leaks as `��`), does not decode UTF-16 at all (`∀` arrives as `"`), and URLVariables re-serializes in reverse order. The last belongs to Batch D. |
| `avm1/form_loader_encoding_2` | 3 | AVM1 `loadVariables` legacy-charset decode (Latin-1 / Shift-JIS) — a different runtime entirely (`src/actionmodern/`), no AVM2 code involved. Bucket B11. |
| `avm1/form_loader_encoding_3` | 2 | same |
| `from_avmplus/e4x/Global/e13_1_2_1` | 3 | `isXMLName` needs the XML 1.0 `BaseChar`/`Ideographic`/`CombiningChar`/`Digit`/`Extender` tables; the diff is `[0x80-0xB6] : Invalid char accepted as start` etc. Pure character-class work, assigned to **Batch B** by the triage. Two copies of the predicate (`avm2_e4x.c:413`, `avm2_nsqname.c:130`). |

So the axis's population is **5 owned + 4 correctly-adjacent**, not 9 in one
batch. The triage was right that they are "separately decidable"; this run
settles that none of the four is *gated* on the string model, so they can be
picked up independently in any order.

---

## 4. Canary results

**40 baseline-PASSING tests, `--mode=graphics`, `xargs -P 2`. 40/40 still pass.
Zero regressions.**

Selection was by code path, not by name similarity — every site the patch
touches has at least one canary aimed at it:

| canary | what it guards |
|---|---|
| `avm2/encode_uri_surrogate_pair_swf11` ★ | the sharpest one. 15 `encodeURI(fromCharCode(hi, lo))` calls that must yield `%F0%90%80%80` … `%F4%8F%BF%BF`. Proves the new #1052 throw fires **only** on unpaired surrogates and that pair-folding still reaches `uri_encode` as 4-byte UTF-8. |
| `from_avmplus/regress/bug_538107` ★ | `decodeURI("%ED%B0%80%ED%A0%80")` (low-then-high, deliberately un-foldable) must still give a 2-unit string, not throw. Guards the `uri_decode` rewrite. |
| `avm2/string_concat_fromcharcode` ★ | `fromCharCode` + `+` — the two halves of the seam rule. |
| `avm2/string_slice_substr_substring`, `avm2/string_split`, `from_avmplus/ecma3/String/{substr,Split,concat}`, `.../e15_5_4_{4_2,5_1,11_1,13}` | the `make_sub16` rewrite of slice/substr/substring and the `split("")` path |
| `avm2/{escape,unescape,decode_uri}`, `from_avmplus/ecma3/GlobalObject/{encodeURI,encodeURIComponent,decodeURI,decodeURIComponent}` | the four global URI functions + the `%uXXXX` codec |
| `avm2/{bytearray_utf16,bytearray_readutf8bytes_with_bom,symbolclass_invalid_utf8}` | `avm_utf8_lenient` and the ByteArray decode family |
| `from_avmplus/ecma3/Unicode/{ucs4_bug_515947,uFFF0_Specials,uc_001,uc_006,u0000_BasicLatin,u0080_Latin_1Supplement}` | the String/Unicode arc's own headline tests, incl. the UCS-4 regression |
| `from_avmplus/ecma3/String/localeCompare_rt` | code-unit comparison |
| `from_avmplus/ecma3/JSON/Strings`, `from_avmplus/e4x/XML/{e13_4_4_1,e13_4_4_39}`, `avm2/xml_list_concat` | serializers that copy string bytes verbatim |
| **`regression/avm2_gc_string_concat_reclaim`** ★, **`regression/avm2_gc_string_survives_collect`** ★ | `avm2_string_concat` now allocates a *different* length than `a->len + b->len`. These two exist precisely to pin concat's allocation + GC enrolment. |
| `regression/{avm2_typed_value_ops,avm2_static_text,avm2_embed_bytearray}` | the rest of the regression suite's string-adjacent coverage |

### The two false positives, run down

`avm2/string_substr_negative` and `avm2/string_substr_weird` reported
`compile_fail` in the parallel sweep. Both are **infrastructure, not the
patch** — chased to the actual linker error rather than assumed:

```
collect2: error: ld returned 1 exit status
… undefined reference to `avm2_generated_timeline_count' / `avm2_generated_chars' / …
```

Cause: these two tests' **cached** `RecompiledABC/` in the source checkout is
missing `abc_timeline.c` (which defines the `avm2_generated_*` tables) —
`ls` shows 4 files where a healthy test has 5. Copying the directory into the
worktree preserved the incomplete cache, and `verify_output.py`'s
stale-cache check (`scripts_dir.st_mtime >= RECOMP_BIN.st_mtime`) did not
fire because `cp -r` gave the cache a fresh mtime.

Re-run with `--recompile` (the flag is `--recompile`, **not**
`--force-recompile`): **both PASS.** They also link fine in CI, where the
recompile is always from scratch.

Note this is a general trap for any worktree-based sweep that copies test
directories: a per-test recompiler cache can be silently incomplete, and the
mtime guard is defeated by the copy itself. `--recompile` on a lone
`compile_fail` is the cheap disambiguation.

---

## 5. Residual risk

Ordered by how likely they are to bite. None blocks landing; all are
*pre-existing* divergences that the new model makes describable rather than
new hazards it introduces.

1. **String builders that bypass `avm2_string_concat`.** The seam rule lives
   in `avm2_string_concat`, so anything that assembles bytes into its own
   buffer and calls `avm2_string_new` once can leave a non-canonical
   high+low pair. `Array.join` / `Array.toString` are **safe** (they route
   through `avm2_string_concat` — checked, `avm2_array.c:164`). The
   `sb_`-style builders in `avm2_text.c` (HTML/text assembly, three
   `avm2_string_new(ctx, sb.buf, sb.len)` sites) are not, but reaching them
   requires astral text inside a TextField whose runs are split exactly
   at a surrogate boundary. If this ever surfaces, the fix is one call to a
   shared canonicalizer, not a redesign.

2. **`utf16_to_utf8` in `avm2_bytearray.c:387` still emits U+FFFD** for an
   unpaired UTF-16 unit read out of a ByteArray (`readMultiByte("utf-16…")`,
   `toString()` on a BOM'd buffer). Left deliberately asymmetric with
   `avm_utf8_lenient`: no corpus test exercises it (`avm2/bytearray_utf16`
   contains no surrogates — checked), and changing it would have been an
   unmeasured flip. It is the obvious next site if a UTF-16 surrogate test
   ever appears.

3. **`indexOf`/`lastIndexOf` search bytes, not code units.** Under canonical
   WTF-8 equal code units imply equal bytes, so ordinary searches are exact;
   but avmplus would find a lone low surrogate *inside* an astral character
   (`"𠮟".indexOf(fromCharCode(0xDF9F))` → 1) where we give −1. Pre-existing,
   unexercised, and now cheap to fix if wanted (walk with `utf16_unit_at`).

4. **`JSON.stringify` passes string bytes through verbatim**
   (`avm2_json.c:545`). A lone surrogate now emits raw WTF-8 bytes where it
   previously emitted U+FFFD bytes. `ecma3/JSON/Strings` passes; ECMA-262
   would want `\uD800`. Untested territory either way.

5. **`utf8_lossy` (strict Rust `from_utf8_lossy`) is untouched** and still
   maps `ED A0 80` to U+FFFD. That is correct — it exists to make ByteArray
   dumps byte-match Ruffle, and Ruffle really is strict there. Do not
   "unify" it with `avm_utf8_lenient`; they model two different avmplus
   decoders on purpose.

6. **AVM1 is completely untouched.** All four modified files are under
   `SWFModernRuntime/src/avm2/`. AVM1 keeps its own UTF-8 string model, so
   `avm1/form_loader_encoding_{2,3}` are unaffected in both directions and no
   AVM1 canary was needed.

### Cost

`avm2_string_concat` gains two 3-byte inspections per call, each
short-circuiting on a single `!= 0xED` byte compare. `native_trace` gains one
byte compare per output byte. Nothing else is on a hot path.

---

## 6. Recommendation

**Land it.** The change is smaller than the arc doc's 2026-era estimate
predicted ("WTF-8 storage *or* a pair-combining pass in every decoder … its
own scoping job") because the second half of that disjunction turned out to be
unnecessary: the decoders were already permissive. What the batch actually
cost was **six deleted `cp = 0xFFFD` lines, one seam rule, one range
extractor, one validator, and one print-boundary guard.**

Dispatch CI as `mode=graphics categories=full images=false` — this is AVM2
runtime code, so `full` is required to see `from_avmplus` (3 of the 5 wins
live there).

### Follow-ups this batch deliberately did NOT take

- `avm2/bom` — needs UTF-16 BOM detection in the URLLoader **plus** the
  URLVariables ordering fix from Batch D. Two owners, neither is the string
  model.
- `from_avmplus/e4x/Global/e13_1_2_1` — Batch B (XML 1.0 name-char tables,
  and remember the predicate exists **twice**: `avm2_e4x.c:413` and
  `avm2_nsqname.c:130`).
- `avm1/form_loader_encoding_{2,3}` — AVM1 legacy charsets (B11), a separate
  runtime.
