# w1-trace-numerics — wave-1 diagnosis report (session 18)

Read-only. All 16 board rows re-run locally at HEAD `8f68a5fea`, `--mode=no-graphics`
(trace parity holds), `SWFRECOMP_COMPILE_TIMEOUT=2400`, sequential. Raw logs +
diffs: `<scratch>/w1-trace-numerics/{avm2a,avm2c,avmplus}.log`.

## 0. Verdict table — read this first

| # | test(s) | miss | verdict | flips | size | owner file(s) |
|---|---|---:|---|---:|---|---|
| **G1** | `avm2/vector3d_near_equals` | 13 | **GO — take first** | **+1** | **XS (1 line)** | `avm2_display.c:10643` |
| **G2** | `avm2/xml_duplicate_attribute` | 7 | **GO** | **+1** | **XS** | `avm2_e4x.c` (~1935-1960) |
| **G3** | `avm2/primitive_keys` | 21 | **GO** | **+1** | **XS (1 constant)** | `avm2_object.c:569` |
| **G4** | `avm2/simplebutton_soundtransform` + `avm2/soundmixer_soundtransform` | 58 + 12 | **GO — best ratio** | **+2** | **S** | `avm2_display.c:15914-15917`, `avm2_media.c` |
| **G5** | `from_avmplus/as3/Array/insertremove` | 104 | **GO** | **+1** | **XS (~6 LOC)** | `avm2_array.c:557,587` |
| **G6** | `from_avmplus/e4x/Expressions/e11_1_4` | 20 | **GO** | **+1** | **S–M** | E4X literal `{}` content splice |
| **G7** | `avm2/number_convert_errors` | 831 | **GO — s17's "structural DEFER" REFUTED** | **+1** | **M** | `avm2_number.c`, `avm2_error.c` |
| H1 | `avm2/number_to_string` | 116 | **HOLD** (12 of 116 are a cheap real bug; 104 gate the flip) | 0 now | XS + M–L | `avm2_value.c:706` + `shortest_digits` |
| H2 | `avm2/textblock_recreateline` | 139 | DEFER (FTE, ≥2 mechanisms) | 0 | L | FTE |
| H3 | `avm2/textline_atom_index_at_char_index` | 19 | DEFER (FTE atom model) | 0 | M–L | FTE |
| N1 | `avm2/number_tostring` | 168 | **NO-GO — PERMANENT (new finding)** | 0 | — | oracle is corrupt |
| N2 | `avm2/dependent_strings` | 38 | NO-GO — disposition covers **38/38** | 0 | — | — |
| N3 | `avm2/bom` | 3 | NO-GO — disposition covers **3/3** | 0 | — | — |
| N4 | `from_avmplus/recursion/pcre_find_fixedlength` | 1 | NO-GO — ceiling **CONFIRMED** | 0 | — | vendored libregexp |
| N5 | `from_avmplus/regress/bug_483783` | 1 | NO-GO — OOM, needs mid-method GC | 0 | — | — |

**Priced flips available to wave 2: +8 tests** (G1–G7), of which **+5 are XS/S**
(G1+G2+G3+G4+G5 = **+6 flips** for well under a day of edits, in five different
files — fully parallelisable).

---

## 1. GO items

### G1 — `vector3d_near_equals`: the FP bug's ASSIGNMENT half is missing  ★ take first

**GO. +1. One line.** All 13 diff lines are `  v1 = x,y,z,w` dump lines; **zero
boolean lines differ**, so our return value is already right and only the side
effect is missing.

Ruffle documents the bug verbatim (`~/CC/ruffle/core/src/avm2/globals/flash/geom/Vector3D.as:87-97`):

```actionscript
// ... when all previous conditions pass, this.w is updated to toCompare.w,
// suggesting that assignment was used instead of subtraction.
&& (!allFour || Math.abs(this.w = toCompare.w) < tolerance); // FP BUG
```

Our `v3_near_equals` (`SWFModernRuntime/src/avm2/avm2_display.c:10643`) already
replicates the "forgot the subtraction" half:

```c
&& (!all_four || fabs(v3_get(ctx, a, "w")) < tol);
```

but never writes `w` back. Fix = put the write in the same `&&` arm (C
short-circuits identically to AS3, so the "only when x/y/z passed" gating is
free):

```c
&& (!all_four || (v3_set(ctx, s, "w", v3_get(ctx, a, "w")),
                  fabs(v3_get(ctx, a, "w")) < tol));
```

Verified against every row: `v2.w=2 → 2`, `v3.w=3 → 3`, `v(1.234).w → 1.234`,
`v(-2).w → -2`; `allFour=false` leaves `w` alone (line 64/65 already matches);
`nearEquals(v2,1,true)` on `v1=(1,1,1,1)` leaves `w` alone because it fails at x.

Also add a `FLASH_BUGS_REPLICATED.md` entry. Canary: `avm2/vector3d`,
`avm2/matrix3d_transform_vector`, `avm2/vector3d_*`.
**Coordination:** `w1-trace-new` may also have this row — G1 is fully diagnosed
here; whoever takes it should take it whole.

### G2 — `xml_duplicate_attribute`: the #1104 message has no arguments, and case 7 must be #1090

**GO. +1. XS.** We already *detect* the duplicate; we just print the template:

```
- TypeError: Error #1104: Attribute "a" was already specified for element "root".
+ TypeError: Error #1104: Attribute was already specified for element.
```

Six of the seven lines are that. The seventh is a *precedence* bug — the
unterminated `<root a="" a=""` must report the malformed-element error, not the
duplicate:

```
- 14  TypeError: Error #1090: XML parser failure: element is malformed.
+ 14  TypeError: Error #1104: Attribute was already specified for element.
```

Owner: `SWFModernRuntime/src/avm2/avm2_e4x.c`. The parser already has the right
shape — `parse_error()` (line 1524) takes a formatted message and pushes the
unnamed FP scanner frame, and `err_1090()`/`err_1085()` sit next to it. Two
edits: (a) an `err_1104(ps, attr_raw, elem_raw)` alongside them, raised where
the duplicate is found in the attribute pass; (b) run the tag's EOF/`>` scan to
completion *before* the duplicate check (the `err_1090` sites at :1833-:1860
already do the scanning — the duplicate check must sit after them, in "Pass 3"
at :1934-:1960, not during attribute collection).

Note the message uses the **raw source spelling** of both names (`abc`, `root`),
i.e. before qname resolution. Canary: `avm2/xml_*` (≈40 tests), `from_avmplus/e4x/*`.

### G3 — `primitive_keys`: the integer-key range is 2^28, not 2^32

**GO. +1. One constant.** All 21 diff lines are the same cell — `typeof key`:

```
-  6  key = 2147483646 (typeof key = string) ...
+  6  key = 2147483646 (typeof key = number) ...
   8  key = 268435455  (typeof key = number)   <- matches, 2^28-1
-  9  key = 268435456  (typeof key = string) ...
+  9  key = 268435456  (typeof key = number) ...
```

Flash keeps an enumerated dynamic key as a **number** only for canonical decimal
integers in **[0, 2^28−1]** — avmplus's 32-bit atom int range (3 tag bits +
sign). `-3` is already string on our side, so only the upper bound is wrong.

Owner: `SWFModernRuntime/src/avm2/avm2_object.c:569`, inside
`avm2_object_enumerant_name`:

```c
if (numeric && v <= 0xFFFFFFFFull)     // -> v <= 0x0FFFFFFFull
    return avm2_uint_value((uint32_t) v);
```

The *values* all match already, and this test sorts its keys, so ordering is not
graded here. **A/B separately**: the sibling ordering predicate
`dyn_key_is_index` (`avm2_object.c:109`, same 2^32 bound) decides the
integer-keys-first partition. Faithfulness says it should move too; risk says
test it alone. Canaries: `avm2/dictionary_primitive_keys` (named in the source
comment), `avm2/amf_array_serialization`, `avm2/json_stringify_function`,
`avm2/dictionary*`.

### G4 — `SimpleButton.soundTransform` IS the global SoundMixer transform  ★ best ratio

**GO. +2 flips from one change. S.** Ruffle says it in so many words —
`~/CC/ruffle/core/src/avm2/globals/flash/media/sound_mixer.rs:15-19`:

> `/// Implements 'soundTransform''s getter` … `/// This also implements
> 'SimpleButton''s 'soundTransform' property`

and `display/simple_button.rs:13` re-exports `sound_mixer::{get_sound_transform,
set_sound_transform}`. `Sprite` keeps its own per-object pair (`sprite.rs:119-147`).

Both board rows are the *same* fixture with a different mutation target, and the
diffs are perfectly symmetric:

* `simplebutton_soundtransform` writes `silence_player.soundTransform` (a
  SimpleButton) 24 times; lines 1-381 match, then the **SoundMixer global** dump
  at 382 and the **NoisePlayer** dump at 395 show the button's values (`-0.12`)
  where we show defaults (`1,0,0,1`). 52 of the 58 lines are SoundMixer
  `leftToLeft`/`rightToRight`, 2 SoundMixer `pan`, 6 NoisePlayer.
* `soundmixer_soundtransform` writes `SoundMixer.soundTransform` 24 times
  (lines 1-381 match — our global getter/setter is fine), then the two
  **player** dumps at 395/408 and 425/438 show the global's values. Exactly 12
  lines: 2 players × {leftToLeft, rightToRight, pan} × 2 rounds.

Our registration is on the wrong class
(`SWFModernRuntime/src/avm2/avm2_display.c:15914-15917`):

```c
// soundTransform lives on Sprite + SimpleButton; both derive from
// InteractiveObject, so registering here covers MovieClip and SimpleButton.
add_getset(ctx, iobj, "soundTransform", do_get_sound_transform, do_set_sound_transform);
```

Fix: register the per-object pair (`do_get/set_sound_transform`,
`avm2_display.c:4386-4406`) on **Sprite** instead, and register the
**SoundMixer global** pair (`avm2_media.c:1392`, `sm_get/set_sound_transform`)
on **SimpleButton**. `pan` needs nothing — it is already derived correctly
(`pan = 1 − leftToLeft²` holds on every matching line: 0.9936/0.9856/0.9744).

Bonus: this also stops `TextField` (an InteractiveObject) from exposing a
`soundTransform` Flash does not give it. The `describeType` descriptor tables
(`avm2_globals.c:3692`, `:3860`) already declare Sprite/SimpleButton separately
and are independent data, so `describeType` output is unaffected — but re-run
`avm2/describe_type*` as a canary anyway, plus `avm2/sound*`, `avm2/simplebutton*`.
Remove `soundmixer_soundtransform` from
`ruffle-tests/tests/swfs/avm2/ignored_tests.txt` when it flips (s17 §5 flagged
that entry as wrong).

### G5 — `insertremove`: `insertAt`/`removeAt` skip splice's hole-resolution pass

**GO. +1. ~6 LOC.** All 104 diff lines are one shape — `proto_five`/`proto_eight`
landing at the wrong index after the shift:

```
- 30150 insert into 11-element dense array at 0: element 5 PASSED!
+ 30150 insert into 11-element dense array at 0: element 5 FAILED! expected: undefined got: proto_five
```

The assertion compares `arr1[i]` (built with `splice`) against `arr2[i]` (built
with `insertAt`/`removeAt`), so Flash's expectation is simply that the two agree
— and `array_splice` (`avm2_array.c:419`) already does the right thing:

```c
// Resolve holes across the tail before mutating (Ruffle splice).
for (uint32_t i = start; i < len; i++)
    ext->elems[i] = resolve_hole(arr, i, ext->elems[i]);
```

`array_insert_at` (:557) and `array_remove_at` (:587) `memmove` raw storage with
no such pass, so a hole keeps its *post-shift* index for prototype fall-through.
Add the identical loop over `[idx, dense_len)` at the top of both. Nothing else
in the 30 870-line file differs.

`known_failure = true` and `output.ruffle.txt` exists (Ruffle's own diff from
Flash is 54 lines, a strict subset shape of ours) — a correct fix lands on
**`pass`**, not `ruffle_matched`. Canaries: `avm2/array_*` (splice/holes/sort),
`from_avmplus/as3/Array/*`, `from_avmplus/ecma3/Array/*`.

### G6 — `e11_1_4`: `{expr}` in XML literal content must splice XML nodes, not stringify

**GO. +1. S–M.** s17 called this row "over-emitting, 37 lines for 34". That is a
**consequence, not a defect**: the whole 3-line surplus is one assertion whose
*expected* value is a multi-line pretty-printed XML. There are exactly **two**
failing assertions and they share one mechanism:

```
15 FAILED! expected: |<rectangle>\n  <width>50</width>\n  <length>30</length>\n</rectangle>| got: |5030|
"Evaluating expressions in a for loop" FAILED! expected: true got: false
```

* `x1 = <rectangle>{x1.width}{x1.length}</rectangle>` — we concatenate the
  interpolated XML values into a **text node** (`"50"+"30"` → `5030`) instead of
  appending them as element children.
* `xml2 = <employees>{e[0]}…{e[9]}</employees>` then `xml2 == new XML(xml2string)`
  — same rule, so the equality fails.

ECMA-357 §11.1.4: an `{}` expression in element *content* whose value is XML or
XMLList contributes its **nodes**; anything else is `ToString`'d into a text
node. Attribute-position `{}` (tests 17/18/19) already passes, as does the
`#2023 Class Test$ must inherit from Sprite` tail line — do not touch those.

Fix both assertions and the line count drops to 34 by itself → **`pass`**.
Canaries: `avm2/xml_*`, `from_avmplus/e4x/**` (1 574-test suite; run the `e4x`
subtree).

### G7 — `number_convert_errors`: 831 lines are THREE stack-frame rules  ★ s17 refuted

**GO. +1. M.** s17's board records this as "DEFER (structural, §17.4 stands)".
That is wrong. We emit 685 lines against 871 expected — a **pure frame-count
deficit of 186** that misaligns everything after the first block. Three rules
account for all of it:

```
- at Number$/_convert()                                          <- R3 (missing frame)
- at Number/http://adobe.com/AS3/2006/builtin::toPrecision()     <- R1 (namespace)
+ at Number/toPrecision()
- at int/http://adobe.com/AS3/2006/builtin::toPrecision()        <- R2 (missing frame)
  at Function/<anonymous>()
```

* **R1** — an AS3 builtin method's frame carries its namespace URI:
  `Number/http://adobe.com/AS3/2006/builtin::toFixed()`.
* **R2** — `int`/`uint`'s `toFixed`/`toPrecision`/`toExponential` push their
  **own** frame *and* delegate to `Number`'s, so an int receiver yields two
  frames (`Number/…` inner, `int/…` outer).
* **R3** — the range check lives in a static `Number$/_convert()` frame, pushed
  innermost, only on the `#1002` path (the `FailingValueOf` coercion section has
  `FailingValueOf/valueOf()` innermost and **no** `_convert` — argument coercion
  happens in `toFixed`'s own frame, before `_convert`).

Arithmetic check: an erroring `(num, p)` block costs +3 lines for the three
`Number`-receiver traces and +12 for the six `int`/`uint` traces = **+15**, over
3 nums × 4 erroring `p` values ≈ 12 blocks = **180-186**. Matches the deficit.

**The machinery already exists.** `avm2_callstack_rename_frame(ctx, own_fn, name)`
(`avm2_error.c:130`) is exactly what `avm2_function.c:407-413` uses to emit
`Function/http://adobe.com/AS3/2006/builtin::call()` — and
`avm2/primitive_valueOf`, `avm2/primitive_toString`, `avm2/error_throwerror`
**already pass** with those namespaced frames. `avm2_callstack_push_throwerror`
is the template for R3.

**Regression surface measured**: 65 corpus `output.txt` files grade `\tat ` frames;
only 5 mention the AS3 URI, and **no** expected output anywhere requires a
builtin frame *without* it (every un-namespaced frame is a user class:
`Test/…`, `FailingValueOf/valueOf()`, `Function/<anonymous>()`,
`SetIntervalTimer/onTimer()`). Low risk.

Owner: `avm2_number.c` (`throw_1002` at :33, `add_number_methods` at :755 —
`Number`/`int`/`uint` currently share one function pointer, so R2 needs either
three thin per-class wrappers or a bound-class check). Canary: all 65
frame-grading tests, minimum the 5 URI ones.

---

## 2. HOLD / DEFER

### H1 — `number_to_string`: two clusters, and only one is cheap

116 diff lines split cleanly:

**(a) 12 lines — `floor(log10(d))` decides the notation. Real bug, 0 flips alone.**
`avm2_value.c:706`:

```c
double digits = floor(log10(d));
if (digits < MIN_DIGITS || digits >= MAX_DIGITS)  /* MIN=-6, MAX=21 */
```

`log10(9.999999999999997e-7)` rounds to exactly `-6.0` in double, so `floor` gives
`-6` and we print `0.0000009999999999999997` where Flash prints
`9.999999999999997e-7`. Its neighbour `9.999999999999987e-7` lands just below and
comes out right — which is why only the values whose first 15 digits are all `9`
fail. Same root cause at the top end: `999999999999999900000` (decimal exponent
20) is misclassified as exponential, and then the `mant[16]` truncation produces
`9.99999999999999e+20`, which **does not round-trip** (verified).

Fix: take the decimal exponent from `shortest_digits()`'s `e10` (exact) instead
of `log10`, and use `-6 <= e10 <= 20 → plain`. `format_plain` already calls
`shortest_digits`, so hoisting the call above the branch is perf-neutral; keep
the `d < 1e15 && d == floor(d)` fast path untouched.

This is worth doing on its own merits — it is a live formatting bug for any
number near 1e-6 or 1e21 in real content, not only in this test.

**(b) 104 lines — avmplus prints subnormals at full 53-bit precision.**
`shortest_digits` uses `%.*e` + `strtod` round-trip, which for a subnormal
succeeds at far fewer digits than avmplus emits:

```
- 0003c85c97cb3127 -> 5.2604401480541715e-309   (Flash, 17 digits)
+ 0003c85c97cb3127 -> 5.26044014805417e-309     (ours; == Python repr, round-trips)
```

Characterised exactly: Flash's string is the shortest decimal within **half an
ulp of a *normalised* 53-bit number at that binary exponent** — i.e. Dragon4 run
with the subnormal's precision loss ignored. Reproduced 100/104 rows with
`|decimal − d| < 2^(frexp_exp−53)/2`; the 4 misses are all exact powers of two
(2^-1074, 2^-1073, 2^-1054), i.e. the standard dragon4 lower-boundary halving.
Digit counts come out 15/16/17 exactly as observed.

Implementable without a bignum library (glibc `printf` prints a double's exact
decimal expansion at any precision, so the half-ulp comparison can be done on
decimal strings), but it is ~100-150 new LOC confined to a `|d| < DBL_MIN`
branch. **HOLD** — completion mechanism: a subnormal arm in `shortest_digits`
using the normalised-ulp stopping condition plus the power-of-two boundary rule.
Ruffle fails these too (`test.toml`: `# TODO Subnormal values have wrong
representations.`), so the ceiling is `pass`, not `ruffle_matched`.

**Attack on my own brief**: the brief asks whether `number_to_string` and
`number_tostring` share a mechanism. **They do not.** `number_to_string` is
base-10 `avm2_format_number`; `number_tostring` is `print_with_radix`'s radix
2-36 loop (`avm2_number.c:41`). Disjoint code, disjoint bugs, and N1 below means
the second can never pass anyway.

### H2 / H3 — the two FTE rows

* `textline_atom_index_at_char_index` (19): `getAtomIndexAtCharIndex` returns
  `-1` for every in-range index — the TextLine atom (glyph-run) model is not
  populated. Second, smaller mechanism: a `GraphicElement` with a null
  `ElementFormat` makes us throw `#2175` where Flash creates the line. DEFER.
* `textblock_recreateline` (139): at least two mechanisms — (i) `recreateTextLine`
  must reset the recreated line's display properties to defaults (we preserve
  `blendMode`, `filters`, `alpha`, `scaleX/Y`, `rotation`, `mouseEnabled`,
  `name`, listener state); (ii) ascent/descent are `8.3203125`/`2.58984375`
  against our `12`/`3`, i.e. real embedded-font metrics vs a device-font
  fallback. DEFER; not a single-slot job.

---

## 3. NO-GO, with evidence

### N1 — `number_tostring` can never pass. NEW FINDING; the 168-line lead is worth **0**.

Upstream's own `test.toml` is:

```toml
num_frames = 1
ignore = true # Ignored because Flash Player adds extra x, W, and/or ° symbols randomly
```

`ignore = true` means **Ruffle never runs this test**, and the reason is that the
checked-in `output.txt` is corrupt. Six of its 1050 lines carry garbage bytes
inside what must be pure base-N digit strings:

```
line  913: 4155413324321542454240ð00W
line  988: 11115303543335132413200×0000
line  998: 191571a527a231970°000
line 1046: aeg6eqbbyy0×00
```

(plus two more; `grep -nP "[^\x20-\x7e]" output.txt` gives all six). All six are
inside the 168-line diff, so the maximum reachable score is 1044/1050 and the
status is `output_mismatch` **forever**.

For the record, the other 162 lines are one real mechanism — avmplus's radix
conversion loses precision from the top down and pads with zeros
(`1000100102201110210101222112100222000000` vs our exact
`10001001022011102101012221121002220002210`) — but there is no reason to chase
it. **Action: add to `ACCEPTED_DIFFS.md` (new category: corrupt upstream oracle
+ upstream `ignore = true`) and to `ruffle-tests/tests/swfs/avm2/ignored_tests.txt`.**

### N2 — `dependent_strings`: disposition covers **38 of 38**

Every diff line is an `isDependent()` boolean rendered as our blank line; every
string line matches. `RUFFLE_VS_FLASH_DIFFERENCES.md:403-458` is exact and
complete. The one extra "missing" line is the trailing blank being trimmed by the
comparator (84 expected vs 83 actual), not a 39th mechanism. Ceiling 46/84.

### N3 — `bom`: disposition covers **3 of 3**

All three diffs are `URLLoader dataFormat=variables …` lines, i.e. the
`URLVariables.toString` hash-bucket order documented at
`RUFFLE_VS_FLASH_DIFFERENCES.md:302-372`. Ceiling 6/9, and `ruffle_matched` is
unreachable (no `known_failure`, no `output.ruffle.txt`). Confirmed.

### N4 — `pcre_find_fixedlength`: the documented ceiling still holds

One line. Flash's `match()` returns the whole match plus **500 captures**
(`hello,blah×500` — 501 comma-separated fields, counted); we return `hello`
alone. Cause confirmed in source, not inherited: our vendored
`third_party/quickjs-libregexp/libregexp.c:59` sets `CAPTURE_COUNT_MAX 255` and
stores capture indices as bytecode **u8** operands, and `avm2_regexp.c:545-552`
already carries the deliberate workaround (demote `(` to `(?:` above 255 captures
when there are no backreferences), which is precisely why the captures vanish.
Completion mechanism: widen libregexp's capture index to u16 through the bytecode
opcode operands and the `capture[]`/`RE_MAX_CAPTURES` arrays — a fork of vendored
third-party code for +1 test. **NO-GO stands.**

### N5 — `bug_483783`: OOM, not a timeout — and mid-method GC is the blocker

Stderr (the cheapest axis, now read):

```
stderr: ERROR: heap_alloc(76392) failed - out of memory      [run 6.27 s]
```

`myString += "a"` 3 000 000 times allocates ~4.5 TB of dead intermediate strings.
It fails *fast*, so no amount of heap sizing helps; the only route is reclaiming
mid-loop, and `avm2-gc-cannot-run-mid-method` is a standing invariant.
**NO-GO stands**, completion mechanism = a safepoint/incremental collector that
can run inside a method body (or rope strings). Also note this is still the
corpus's only `runtime_error`.

### Audio (asked for in one line)

**No — a deterministic-output `computeSpectrum` stub cannot pass any of the
three.** `audio/aac` and `audio/g711` print only `Starting tone: … / Measuring… /
PASS`, and the `PASS` is a frequency measurement taken *from* the spectrum of the
decoded PCM (6 and 2 tones respectively, at 22 050/44 100/48 000 Hz, mono and
stereo), so a fabricated spectrum cannot land on the right bin; and
`avm2/audio_computespectrum` prints the 512 float bins themselves at four
`stretch` levels. s17's NO-GO is confirmed on all three.

---

## 4. Refutations of my own brief

1. **"`number_tostring` … 168 lines — cluster them"** → the row is worth **0
   flips forever**: its oracle contains six corrupt lines and upstream marks it
   `ignore = true`. Biggest line count on my board, zero yield. (N1)
2. **"`number_to_string` … compare with the row above; shared mechanism?"** →
   **No shared mechanism.** Different functions, different bugs. (H1)
3. **"`number_convert_errors` … find the single rule that owns most of them, or
   NO-GO"** → not one rule but **three**, and together they own **all 831**;
   s17's "structural DEFER" is refuted and the callstack machinery already
   exists. (G7)
4. **"`e11_1_4` … we emit 37 lines for 34 expected — over-emitting"** → the
   surplus is *caused by* one failing assertion whose expected value is
   multi-line. Only **two** assertions fail, and they share one rule. (G6)
5. **"`simplebutton_soundtransform` … a SoundTransform property-surface sweep"**
   → **refuted**: not a property sweep. One class-registration error, and it flips
   **two** tests, including the ignore-listed sibling. (G4)
6. **"`pcre_find_fixedlength` … confirm still true, else price"** → confirmed
   true, with the exact source lines. (N4)
7. **`bug_483783` "the ONLY runtime_error — read its stderr"** → read; it is an
   OOM at 6.3 s, not a hang, and it stays NO-GO. The cheap-triage-axis rule paid
   off in *closing* the row rather than opening it. (N5)
8. **Line-count vs flip-count**, explicitly: my board holds 1 457 diff lines.
   **968 of them (67%) are worth zero flips** (`number_tostring` 168,
   `number_convert_errors`'s misalignment tail, `dependent_strings` 38,
   `textblock_recreateline` 139, the `number_to_string` subnormals 104), while
   **13 lines** (`vector3d_near_equals`) and **7 lines**
   (`xml_duplicate_attribute`) are each a whole flip.

---

## 5. New unclaimed leads

* **`avm2_value.c:706` `floor(log10(d))` is a live number-formatting bug**, not
  just a test artifact: any value whose decimal exponent sits exactly on the
  `1e-6` or `1e21` boundary prints in the wrong notation, and the `1e21` side
  additionally emits a **non-round-tripping** mantissa (`9.99999999999999e+20`
  for `9.999999999999999e+20`). Content-visible; XS to fix (H1a). Nobody owns it
  because it flips no test on its own.
* **`TextField.soundTransform` exists on our `InteractiveObject` but not in
  Flash** — falls out of G4; check whether any `describeType` row currently
  hides it.
* **`dyn_key_is_index` (`avm2_object.c:109`) uses the same wrong 2^32 bound** as
  G3 but for enumeration *ordering*. No test on my board grades it (they sort);
  a corpus A/B would say whether Flash also partitions at 2^28.
* **FTE atom model** (`TextLine.getAtomIndexAtCharIndex`, `TextLine.atomCount`,
  `getAtomBounds`) and **`GraphicElement` with a null `ElementFormat` must not
  throw `#2175`** — two independent, separately-sized pieces inside H3.
* **avmplus radix conversion** (`print_with_radix`, `avm2_number.c:41`) loses
  precision differently from Flash. Documented here only so nobody re-derives it;
  the one test that grades it (N1) can never pass, so it needs a *different*
  test before it is worth anything.

---

## 6. Method / caveats

* Every row re-run at HEAD; nothing inherited from s17 without re-verification.
* Dispositions checked by grepping `ACCEPTED_DIFFS.md`,
  `RUFFLE_VS_FLASH_DIFFERENCES.md`, `RUFFLE_COMPAT_TWEAKS.md`,
  `FLASH_BUGS_REPLICATED.md` and both ignore lists for each test name, not by
  trusting the inventory flags.
* `known_failure = true` rows checked against `output.ruffle.txt` where present:
  G5 and H1 both land on `pass` if fixed toward `output.txt`; no
  `pass → ruffle_matched` risk on this board.
* Upstream behaviour questions answered from `~/CC/ruffle` at `1636c7806`
  (G1, G4), never from GitHub.
* No source edits, no commits.
