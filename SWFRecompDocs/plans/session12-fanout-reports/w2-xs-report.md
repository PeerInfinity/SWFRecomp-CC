# w2-xs — session 12, wave 2, trace axis: the exact-pin singles bundle

Worktree `agent-a9a2dfd55828a00c0`, base `f166e424e`. Deliverables:
`w2-xs.patch` + this file. No commits, no pushes, no full suites.
All runs: `verify_output.py --test=… --diff` (no-graphics), `-P 2`.

**Result: 8 targets attempted, 8 flipped (`output_mismatch` → `pass`).
27 canaries run, 27 held at or above baseline. Zero regressions.
Predicted CI flips: +8 (all full `pass`, no `ruffle_matched` fallbacks).**

Two of the seven briefed targets were mis-scoped by wave 1 and are re-diagnosed
below (§4): `html_entity_parsing` is NOT a missing blank line, and
`define_bits_jpeg2_huge` is NOT runtime-only.

---

## 1. Ledger

### Targets (all verified failing in this worktree at HEAD first)

| # | test | before | after | mechanism |
|---|---|---|---|---|
| 1 | `visual/define_bits_jpeg2_huge` | om (6/12 lines) | **pass** | `uint16_t`→`uint32_t` bitmap dims, **recompiler + runtime** |
| 2 | `from_avmplus/ecma3/Expressions/e11_6_1_3` | om (6) | **pass** | Date `[[DefaultValue]]` hint = String |
| 3 | `from_avmplus/ecma3/String/e15_5_4_8_2` | om (6) | **pass** | `split()` vs `split(undefined)` |
| 4 | `avm2/property_is_enumerable` | om (89) | **pass** | Object's ES3 trio on Class **and Function** objects |
| 5 | `text/html_entity_parsing` | om (114) | **pass** | numeric HTML-entity parser rewrite (§4a) |
| 6 | `avm2/static_length` | om (13) | **pass** | `Error`-family + `RegExp` class-object `length` |
| 7 | `avm2/json_stringify_function` | om (12) | **pass** | Functions unserializable; class objects serialize statics + `prototype` |
| 8 | `from_avmplus/as3/String/localeCompare_585791/v9` (OPTIONAL) | om (6) | **pass** | SWF<11 null/undefined-arg quirk |

### Canaries (baseline from the merged `results_graphics.json` at `6de650432`)

All 27 ran **after** the edits. `pass`→`pass` unless noted.

`avm2/`: `json_stringify` · `json_stringify_order` · `json_parse` ·
`json_errors` · `class_call` · `object_prototype` · `vector_class_call` ·
`xml_class_call` · `bitmapdata_embedded` · `bitmap_properties` ·
`bitmapdata_getpixels` · `edittext_html_entity` · `edittext_html` ·
`edittext_html_roundtrip` · `edittext_html_condensewhite` ·
`edittext_set_text_vs_html`

`from_avmplus/`: `ecma3/JSON/{Callbacks, AS3Types}` ·
`ecma3/JSON/{Classes, adhoc}` (**ruffle_matched → ruffle_matched**, their
baseline) · `ecma3/ObjectObjects/{e8_6_2_6_001, propertyIsEnumerable,
hasOwnProperty, isPrototypeOf}` · `ecma3/ErrorObject/{e15_11_1, e15_11_2_1}` ·
`ecma3/Date/e15_9_5_2` · `ecma3/Date/e15_9_5_4` (**ruffle_matched →
ruffle_matched**, its baseline) · `ecma3/Expressions/{e11_6_1_1, e11_6_1_2}` ·
`ecma3/String/{e15_5_4_8_1_rt, e15_5_4_8_3, e15_5_4_8_477132, localeCompare_rt}` ·
`as3/String/localeCompare_585791/v12`

`ecma3/ObjectObjects/e8_6_2_6_001` is worth naming: it is literally the ES3
§8.6.2.6 `[[DefaultValue]]` test and it is the tightest possible canary for
target 2.

---

## 2. Files and lines

| file | hunk | target |
|---|---|---|
| `SWFModernRuntime/include/avm2/avm2_abc.h` | `Avm2BitmapData.width/height` u16→u32 (:517-530) | 1 |
| `SWFRecomp/src/abc/abc_timeline.cpp` | `BitmapAsset.width/height` u16→u32 (:548-556) + the two ingest casts (~:1505, ~:1548) | 1 |
| `SWFModernRuntime/src/avm2/avm2_value.c` | `avm2_coerce_to_primitive` hint-0 arm (:654-671) | 2 |
| `SWFModernRuntime/src/avm2/avm2_string.c` | `string_locale_compare` SWF<11 arm (:407-418) | 8 |
| `SWFModernRuntime/src/avm2/avm2_string.c` | `avm2_string_split_plain` `argc == 0` gate (:457-465) | 3 |
| `SWFModernRuntime/src/avm2/avm2_globals.c` | `register_class_object_lengths` table (:3659-3695) | 6 |
| `SWFModernRuntime/src/avm2/avm2_globals.c` | ES3 trio onto `class_class` + `function_class` (:3768-3784) | 4 |
| `SWFModernRuntime/src/avm2/avm2_json.c` | `js_is_function` (:688-696) + 3 skip sites + class-object arm in `js_serialize_object` + FUNCTION arm in `js_serialize_value` | 7 |
| `SWFModernRuntime/src/avm2/avm2_text.c` | `ent_ws`/`ent_digit` helpers (:1134-1147) + numeric-entity arm (:1178-1232) | 5 |

**Sibling-owned files touched** (flagged per the brief):
- `avm2_globals.c` (w2-avclasses owns the builtin tables). Two edits, both at
  distinct anchors far from a class-registration site: the
  `register_class_object_lengths` array literal and the block right after
  `// Class.prototype.`. Neither adds nor removes a class.
- `avm2_value.c` is shared with w2-singles, which owns ~498-533
  (`shortest_digits`). My hunk is at ~654 and does not touch that region.
- `avm2_error.c` was **not** touched.

---

## 3. Per-target notes, risks, and gating

**1 — bitmap dimensions.** The wave-1 shoulder report said "the recompiler is
correct… the loss is on the runtime side." That is **wrong**: the emitted
`RecompiledABC/abc_timeline.c` in the test tree already read
`{ 1, 0, 2, 0, bmp_0_rgba, … }` — the recompiler's own `BitmapAsset` is
`uint16_t` and `decodeJpegCharacter`'s `uint32_t w` was cast down at
`abc_timeline.cpp:1505`. Both sides had to widen, so this is **not** a
runtime-only change: the recompiler was rebuilt in the worktree
(`cmake -S SWFRecomp -B SWFRecomp/build && cmake --build … -j4`) and every
affected test needs `--recompile`. The dimension can exceed 65535 only for a
PNG smuggled through `DefineBitsJPEG2/3` (SWF8+); `DefineBitsLossless` reads
u16 from the tag and is unaffected. Struct field ORDER is unchanged, so the
generated positional initializers stay valid. `Avm2BitmapDataExt.width` was
already `uint32_t`, so no consumer changed. Blast radius: the generated-table
ABI, i.e. a full recompile — CI covers it; three embedded-bitmap canaries held.

**2 — Date ToPrimitive.** Gated on the receiver's class chain reaching
`ctx->builtins.date_class`, so a plain object whose `valueOf` returns a Date
(the `MyObject` half of the same test, already passing) is untouched. Only
`avm2_value.c:884-885` (the `add` operator) passes hint 0, so the change is
confined to `+`.

**3 — `split(undefined)`.** One-token change (`delim_v.kind == UNDEFINED` →
`act->argc == 0`). `string_split_regex` forwards the same `Avm2Activation`, so
the RegExp path inherits it correctly. `split(null)` already worked and still
does.

**4 — class/function ES3 trio.** The bootstrap mints `Class` and `Function`
(`avm2_globals.c:3713-3714`) **before** `hasOwnProperty`/`isPrototypeOf`/
`propertyIsEnumerable` are registered on `object_class`, and
`avm2_builtin_class` snapshots the super ivtable at creation time — so the
copy never happened. I restate exactly those three names on both classes
rather than reorder init, because `avm2_ops.c:2186-2199` carries an explicit
warning that reordering "would silently widen this fallback" to every Object
instance member at once. The narrow form is deliberate; say so if anyone
proposes replacing it with a proto-chain link.
**Note the brief/triage under-scoped this one too**: T5 named only the class
object. Fixing `Class` alone moved the failure from line 26 to line 84, where
`ES3Class` (a plain AS3 constructor *function*) hit the identical #1006.
`Function` needed the same three.

**5 — HTML numeric entities.** See §4a. The new arm is a faithful port of
Ruffle `core/src/html/text_format.rs::process_html_entity`, which is the
oracle Flash agrees with here (the test ships no `output.ruffle.txt`, so a
full `pass` was required and obtained). Five `edittext_html*` canaries held.

**6 — `Error` family `.length`.** Table-only. The twelve classes the test
names, plus `RegExp` 2→1 (Flash disagrees with ECMA-262 here), plus the four
Error subclasses the test does not name (`IOError`, `EOFError`, `MemoryError`,
`IllegalOperationError`) — same arity, and leaving them `undefined` would be a
new inconsistency. `avm2_builtin_add_static_const` marks the prop dont-enum +
read-only, so `for (p in ErrorClass)` and `delete` are unaffected;
`register_class_object_lengths` runs LAST in `avm2_globals_init`, after every
class exists. **Interacts with target 7** — see below.

**7 — `JSON.stringify`.** Two rules. (i) A Function value is unserializable:
`null` at top level and in arrays, **omitted** as an object property. (ii) A
class object serializes its statics and its `prototype`. Our statics live as
*dont-enum dynamic props* (`avm2_builtin_add_static_const`) where avmplus has
real class traits, so the dont-enum skip is relaxed **for `AVM2_OBJ_CLASS`
only**; static *methods* live in the static vtable as `AVM2_PROP_METHOD` and
are still skipped by the existing `else continue`, and any that leaked through
would be caught by rule (i) anyway. `prototype` is a `Class`-ivtable getter,
not a trait on the class's own vtable, so it is appended explicitly, last —
which reproduces Flash's `{"length":1,"prototype":{}}` order exactly rather
than settling for Ruffle's `{"prototype":{},"length":1}` and a
`ruffle_matched`.
**Risk worth stating:** rules 6 and 7 compose. `JSON.stringify(SomeErrorClass)`
now emits `{"length":1,"prototype":{}}` where it previously emitted `{}`. No
corpus test does that (grepped), and both halves are independently correct,
but they are the one place where these two commits are not orthogonal.

**8 — SWF9 `localeCompare` (optional, taken).** The wave-1 report rated this
MED because "the rule for receivers outside the six probes is a guess." It is
not a guess: Ruffle `core/src/avm2/globals/string.rs::locale_compare` has the
identical special case, gated on `version() < 11` (not `<= 9`), returning 1 for
an empty receiver and 0 otherwise. I matched Ruffle's gate and rule verbatim.
Confidence HIGH, not MED. `v12` and `ecma3/String/localeCompare_rt` held.

---

## 4. Refutations — wave-1 scoping errors found while executing

**(a) `text/html_entity_parsing` is not "one missing leading blank line".**
The triage's T3 read the `--diff` display, which prints raw expected/actual.
`compare_output` (`verify_output.py:3309-3315`) strips leading blank lines from
**both** sides, so expected line 1 (empty) never participates and the shift the
report describes does not exist. An LCS diff of the saved actual against the
expected shows **24 genuinely mismatched `Parsed:` lines plus 4 spurious extra
output lines**, in ten rules, all of them numeric-entity parsing:
signed numerals (`&#-50;`, `&#+40;`), whitespace inside the entity
(`&# 60;`, `&#x  3f;`, `&#62   ;`), newlines inside the entity (the 4 extra
lines — we left the `\n` in the text), truncation at the first invalid digit
(`&#40a;` → `(`, `&#x3FQ3a01;` → `?`), rejection of uppercase `&#X28;`, and —
the big one — **wrapping u16 accumulation** instead of an out-of-range reject
(`&#127183;` → U+F0CF, `&#1311768467463786786;` → U+D122). Effort was S–M, not
S; the fix is a ~45-line parser replacement, not a hunt for a dropped trace.
*Generalisation for the next board: the `--diff` rendering and the
`matching_lines` metric do not use the same normalisation. Never scope from the
printed diff alone — save the actual and run a real edit-distance diff.*
(This is the same class of trap wave 1 itself flagged in its §2 premise attack,
one layer deeper.)

**(b) `define_bits_jpeg2_huge` is not runtime-only.** See §3-1. The report's
"the recompiler already emits the right value" was checked against
`RecompiledTags/constants.h` (the AVM1/graphics path, which really does say
`BITMAP_HIGHEST_W 524288`) rather than `RecompiledABC/abc_timeline.c` (the AVM2
path this test uses, which said `0`). Two different tables. Anyone re-running
this needs `--recompile` **and** a rebuilt recompiler.

**(c) T2 (`property_is_enumerable`) needed `Function`, not just `Class`.**
See §3-4. The triage's "89 lines blocked by one #1006 on a class object" was
half the story; there are two #1006 sites, 58 lines apart.

**(d) Not refuted, but worth recording:** `html_decode_entities` still differs
from Ruffle in one respect I deliberately left alone — Ruffle restarts entity
scanning when it meets a second `&` before the `;` (`"& b &amp;"` → `"& b &"`),
while we scan to the next `;` and emit the whole span verbatim. No corpus test
covers it; fixing it is a loop restructure, not a one-liner, and it is
orthogonal to everything above.

**(e) The AVM1 entity decoder (`actionmodern/action.c:24463`) was NOT touched.**
It is a separate, much simpler implementation with its own passing canaries
(`avm1/edittext_html_entity`, `avm1/edittext_html_roundtrip`). If someone wants
AVM1/AVM2 parity on numeric entities, that is a follow-up with its own canary
set — I kept the blast radius to the VM the failing test uses.

---

## 5. Skipped, and why

- **`loaderinfo_quine`** — skipped per the brief (arc-sized; needs root-SWF
  byte embedding in `verify_output.py`).
- **The ImportAssets pair** (`avm1_imports_avm1`, `avm1_non_swf_import`) —
  skipped. The brief made it conditional on "the report evidence being solid";
  it is not, for the first half. The donor-script-suppression fix lands inside
  `actionImportAssets` (`action.c:34559-34594`), whose frame-0 replay is
  explicitly load-bearing for imported-sprite bounds, and the wave-1 report
  itself rates that half MED. That is an AVM1 execution-path change, not an
  exact pin, and it does not belong in an XS bundle. The second half (queue a
  `swf_log_fetch` GET on the `entry == NULL` early return at `action.c:34563`)
  *is* a genuine one-liner and would be a clean standalone +1 for whoever takes
  the pair.

---

## 6. CI notes for whoever integrates this

- Mode: `graphics` (the per-change default). Categories: `all` is enough —
  none of these touch AVM2 *emission*; the one recompiler change is a struct
  width in the timeline table writer, not the ABC emitter. That said, because
  target 1 changes the generated-table ABI, **the CI cache must recompile
  everything** — expect a slow run.
- `images=false` as usual. `define_bits_jpeg2_huge` is trace-only here.
- No disposition-doc updates are needed: none of the eight is in any
  `ignored_tests.txt` or the four AVM1 disposition docs, and none carries
  `known_failure`.
