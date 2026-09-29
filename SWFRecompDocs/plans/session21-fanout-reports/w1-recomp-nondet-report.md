# w1-recomp-nondet: recompiler output nondeterminism

**New files: none.** The patch is `w1-recomp-nondet.patch` in this directory. It touches
`SWFRecomp/{include/field.hpp, include/tag.hpp, src/field.cpp, src/tag.cpp, src/swf.cpp}` and
applies cleanly to `0fd566061`. The worktree is `.claude/worktrees/w1-recomp-nondet`
(branch `s21-w1-recomp-nondet`, not committed).

## Verdicts

- **GO: fix the recompiler (patch ready).** The nondeterminism is real, and it has one mechanism:
  **a bit-stream parse desync makes the recompiler read uninitialised heap memory and freed or
  out-of-bounds memory, and print it into `draws.c`.** It is not a container ordering, parallelism,
  timestamp or float-formatting problem. After the fix, valgrind reports 0 errors on all 7 affected
  SWFs (before: 4506 errors on away3d alone).
- **Scope: 6 of the 205 sampled SWFs were nondeterministic; the whole corpus has 6 such SWFs.**
  Only `RecompiledTags/draws.c` differed (plus `draws.h` and `tagMain.c` where array sizes moved).
  The static scans below cover the full corpus of 5026 `.swf` files for both trigger conditions,
  so the complete affected set is known:
  - **Nondeterministic on master (6):** `avm2/away3d_advanced_shallow_water_demo`,
    `from_shumway/3_joystick`, `from_shumway/bitmapbuttons`, `avm2/edittext_newline_stripping`,
    `avm2/textfield_input_events`, `avm1/edittext_newline_stripping`.
  - **Deterministic but wrong on master, changed by the fix (1):** `from_shumway/acid/acid-text`.
  - **Byte-identical to master:** 199 of 205 sample SWFs, and 97 of 97 `regression`-suite SWFs.
    Also identical: `define_font_glyph_table_{order,overlap}`, `movieclip_state_values`, and the
    12 other SWFs that hit the shape trigger (see the mechanism section for why they are unaffected).
- **After the fix:** 0 of 206 SWFs are nondeterministic (sample plus
  `avm1/edittext_newline_stripping`; each recompiled twice, and every generated file md5'd).
- **Trace yield: 0 flips.** All 7 changed tests were already trace `pass` and still pass
  (`--mode=graphics`, run locally).
- **Pixel movement (local A/B against the master binary, same runtime, `--images`):**

  | test | master binary | fix | CI baseline |
  |---|---|---|---|
  | `from_shumway/3_joystick` | fail: 3674 outliers @ tol 32 (limit 2500), max 255 | **fail: only 4 outliers @ tol 128 (limit 0), max 187; tol-32 check now passes** | fail 307 (random) |
  | `from_shumway/acid/acid-text` | fail 7683 | **fail 5307** (dropped strokes are now drawn) | fail 7683 |
  | `from_shumway/bitmapbuttons` | fail 618042 | fail 618042 | fail 618042 |
  | `avm2/away3d_advanced_shallow_water_demo` | timeout (run 30 s at load ~11) | timeout (same) | pass, 1331566 outliers |

  away3d times out in both legs on the loaded box, so this is load, not the fix. CI ran it in
  10.8 s. The three font tests have no image comparison.
  **Pixel pass/fail flips: 0.** `3_joystick` becomes a near-flip lead (4 channels at tol 128).
  The CI pixel baseline for `3_joystick` (and possibly away3d) was **random**: it read garbage
  heap bits as colour indices.

## Mechanism (three independent parser bugs; the first two cause the nondeterminism)

1. **A zero-width `UB` field reads `nbits` bits** (`field.cpp`, `bit_length == 0 ? nbits : bit_length`).
   In a StyleChangeRecord, `FillStyle0/1` is `UB[NumFillBits]` and `LineStyle` is
   `UB[NumLineBits]`. Both widths can legitimately be 0. `configureNextField(SWF_FIELD_UB, fill_bits)`
   with `fill_bits == 0` means "use the running nbits", and a MoveTo in the same record has just
   set that to MoveBits. So the parser swallows MoveBits bits (1 to 24 of them).
   - When the record also has `StateNewStyles`, the byte-align that follows usually hides the
     over-read. That is why 12 of the 16 corpus SWFs that hit this trigger have unchanged output.
   - When the over-read crosses a byte boundary, the stream desyncs. `away3d` shape 5
     (DefineShape3) then parses a 16-entry fill array with junk types (`0xaa, 0x9f, …`) where the
     correct count is 5.
   - The junk fill types match no `case` in `parseFillStyles`, so `fs.index` is never written.
     `new FillStyle[n]` default-initialises it to heap garbage, which is emitted as the 4th
     `shape_data` word (`0x6B4D5310` vs `0xBACF4310` between runs).
   - Desynced records also index `all_line_styles[list][line_style_i-1]` past the end of the
     array (swf.cpp ~10775, no bounds check). valgrind shows reads of freed ABC-emitter memory
     there.
   - The existing `SHAPE_STYLE_COUNT_CAP` comment ("bit-stream parser likely lost alignment")
     was very likely written for this bug.
   - Same bug in the second walker at swf.cpp ~8385.
2. **DefineFont2/3 `WideOffsets` truncated to u16** (`std::vector<u16> entry_offsets`,
   `(u16)` cast). Fonts with more than 64 KiB of glyph data (1543 to 2714 glyphs; offsets up to
   566228) start glyph *N* at a wrapped offset in the middle of another glyph. The parser then
   walks garbage, reaches mechanism 1 or unknown fill types, and reads uninitialised memory.
   **Corpus: exactly 3 SWFs** (both `edittext_newline_stripping` tests and
   `avm2/textfield_input_events`, found by a full-corpus scan).
   - These glyphs only affect rendering. Trace output is unchanged, and these tests have no image
     comparison.
3. **Glyph StyleChangeRecords skip the `LineStyle` bits** (`state_line_style = !is_font && …`
   gates the *read*, not just the use). Ruffle reads those bits. No well-formed corpus font has
   the line flag with `NumLineBits > 0` (full scan), so this changes nothing today. I fixed it so
   the parser cannot re-desync. Fonts still ignore the value.

## Patch

- `SWFField::exact_width` and `SWFTag::configureNextFieldExactBits(type, bits)`: a width of 0
  now means read 0 bits. Only the 6 StyleChangeRecord style fields use it, at the two parser
  sites. The other `configureNextField` callers keep the nbits sentinel. I audited them: RECT,
  MATRIX and CXFORM use a width of 0 to mean "use nbits", and glyph/advance bits run with
  `nbits = 0`.
- `entry_offsets` is now `u32`.
- Glyph LineStyle bits are consumed when the flag is set (`state_line_style_bits`).
- Hardening, no effect on well-formed SWFs:
  - fill and line style arrays are value-initialised (`new X[n]()`);
  - a new `all_line_style_counts` vector plus a bounds check skip an out-of-range LineStyle index,
    the same way out-of-range `inner_fill` is already skipped.

**Tests run** (all `--mode=graphics --recompile --images`, sequentially, in the worktree):
- the 7 changed tests, fix leg and master-binary leg (table above);
- recompile-hash sweeps over 205 sample SWFs (2 master runs plus 2 fix runs each, for three
  patch iterations) and over 97 regression SWFs (master vs fix);
- valgrind on 7 SWFs.

**Not run:** `render_canary`. The generated C is byte-identical for everything except the 7
tests above, so the canary cannot see this change. **CI:** `categories=all`, `mode=graphics` is
enough (recompiler-only change). `images=true` would re-baseline `3_joystick` and `acid-text`.

## Refutations and brief corrections

- The brief's premise "unordered_map iteration / parallelism …" is **refuted**. The binary is
  single-threaded in this path, and the cause is uninitialised heap memory.
- "Nobody tracks this" is partly wrong: the `SHAPE_STYLE_COUNT_CAP` guard was a symptom patch for
  the same desync.
- Effect on "generated C byte-identical" A/Bs: only these 6 SWFs were ever unstable. A/Bs over
  other tests were valid.

## New unclaimed leads

- **`from_shumway/3_joystick` pixel near-flip:** 4 channels over tol 128 (max 187) after the
  fix. The tol-32 check already passes.
- **`from_shumway/acid/acid-text`:** 5307 outliers remain after the stroke recovery.
- **`paths[i].line_style` is truncated to `u8`** (`u8 line_style_i = paths[i].line_style`,
  swf.cpp ~10775). A shape with more than 255 line styles would draw the wrong or no stroke.
  The same truncation may exist on the fill side; not audited.
- **Unknown fill-style types** leave the stream unconsumed (there is no `default:`). Ruffle fails
  the whole tag. We now emit index 0 deterministically but keep parsing garbage. Consider
  aborting the shape instead, the way the style-count cap does.
- **Standing determinism check (cheap):** recompile twice and diff. About 15 minutes at -P 2 for the whole
  sample (`scratchpad/w1-recomp-nondet/one.sh`, `sample.txt`); worth adding to CI as a canary.
  Scanners for both trigger classes: `shp_lib.py`+`scanall.py` (shapes), `scanwide.py` (wide font
  offsets).
