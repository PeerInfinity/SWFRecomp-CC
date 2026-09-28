# w2-drift-smalls — session 21 wave 2 (report)

**New files: none.** Four patches; each touches only its own family, and each applies alone to
master (`git apply --check` against `6913e27a7`):
- `w2-drift-smalls-1-casi32.patch` — `avm2_mops.c` (+40), `avm2_globals.c` (+10)
- `w2-drift-smalls-2-textjustifier.patch` — `avm2_text.c` (`tj_set_locale`, `tj_init`,
  `tj_init_from_subclass`, and 2 call sites in `sj_ctor` / `eaj_ctor`)
- `w2-drift-smalls-3-hastabs.patch` — `avm2_text.c` (new `tl_get_has_tabs` placed just above
  `avm2_text_init_textline_class`, plus 1 registration line). No TextLine atom code is touched.
- `w2-drift-smalls-4-bitmapdraw.patch` — `action.c`, confined to `bitmapDataDraw`

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/w2-drift-smalls`
(branch `s21-w2-drift-smalls`, not committed).

## Verdict: +5 GO. All five headline tests flip to `pass` under `--mode=graphics`.

| test | before (CI) | after | patch |
|---|---|---|---|
| `avm2/casi32` | output_mismatch 9/166 | **PASS** | 1 |
| `avm2/textjustifier_locale` | output_mismatch 8/132 | **PASS** | 2 |
| `avm2/textline_has_tabs` | output_mismatch 42/47 | **PASS** | 3 |
| `avm1/bitmap_data_draw_return_value` | ungraded (local 3/9) | **PASS** | 4 |
| `avm1/bitmap_data_draw_string_target` | ungraded (local 4/40) | **PASS** | 4 |

None of the five has `known_failure` set, so each `pass` is a genuine match of Flash's
`output.txt`. The two bitmap-draw tests are new upstream tests. They count as yield only
because this patch flips them.

## Mechanisms

1. **casi32 / mfence.** The two `avm2.intrinsics.memory` package natives were never registered;
   they are real calls, not opcodes. Both now live in `avm2_mops.c` next to `mops_window` and are
   registered with `builtin_add_global_fn_ns`. That helper already produces the
   `global/avm2.intrinsics.memory::casi32()` stack frame the expected trace shows.
   `casi32` follows Ruffle's `concurrent.rs`:
   - the address is read as unsigned;
   - it throws `RangeError #1506` if `len < 4`, `addr > len - 4`, or `addr % 4 != 0`;
   - otherwise it reads a little-endian i32, stores the new value only if it equals the expected
     one, and returns the old value.
2. **TextJustifier locale.** Upstream `42a874b4b` routes the locale through a private
   `setLocale()`. A null locale throws `TypeError #2007` ("Parameter locale must be non-null"),
   and one shorter than 2 UTF-16 units throws `ArgumentError #2004`.
   - The call goes through the existing `fte_ctor_set` frame helper, so the trace shows
     `…::TextJustifier/setLocale()`.
   - The `SpaceJustifier` and `EastAsianJustifier` constructors call the shared init natively, so
     `tj_init_from_subclass` adds the `…::TextJustifier()` frame that Flash's `super()` produces.
   - A user AS subclass reaches `tj_ctor` through a real `super()`, so it does not get the
     synthetic frame. The test's `TestJustifier` case (before super → null, after super → `ja`)
     still matches.
3. **TextLine.hasTabs.** This was the constant `tl_const_false`. It now scans the line's own span
   of the block text (`begin_index` plus `raw_text_length`, UTF-16 offsets mapped to bytes) for
   U+0009 only, which matches Ruffle's `has_tabs` (`ae2c796c3`).
4. **BitmapData.draw (AVM1).** The return codes now follow Ruffle's `bitmap_data.rs` `draw()`:

   | case | return |
   |---|---|
   | successful draw (includes a singular matrix, which draws nothing) | 0 |
   | disposed BitmapData source | -3 |
   | not a BitmapData and not a clip, or a missing argument | -2 |
   | disposed destination | -1 (as before) |

   A **string** source is now resolved as a target path from the current target, the same way
   ActionGetProperty does it: `resolveFlashPathToMC(…, 1, 0)` with a `resolveObjectPathToMC`
   fallback. An empty string or an unresolvable path returns -2, and a resolved clip goes down the
   existing MovieClip rasterize path. All 36 path cases in the test match, including `"/"` → root,
   `".map"` → -2 and `"map/..:map"` → 0.
   - Known remaining gap: an AVM1 **TextField** object source still returns -2, where Ruffle would
     draw it and return 0. No test grades this.

## Tests run (worktree, `--mode=graphics`, sequential, `--recompile` on the first use of each copied dir)

- **Headlines:** the 5 above, all PASS.
- **Canaries**, all PASS and all `pass` in the baseline:
  - AVM1: `bitmap_data` (includes `disposed.draw() → -1`), `bitmap_data_draw_cliprect`,
    `bitmap_filters`
  - AVM2: `domain_memory`, `east_asian_justifier_clone`, `space_justifier_clone`,
    `textblock_properties`, `textline_raw_text_length`, `textline_splitting_basic`,
    `textline_validity`
  - regression suite: `avm1_parent_child_bitmap`, `avm2_bitmapdata_draw_textfield`

  The existing render canary cannot see these changes: patches 1-3 are trace-only AVM2 natives,
  and patch 4 changes return values plus string resolution feeding the unchanged rasterizer. So no
  render canary member was added.

## CI mode

Default `graphics` / `categories=all`. None of this is no-graphics-only code. `casi32` lives in AVM2
runtime code, so `categories=full` would also cover `from_avmplus` mops users. I ran
`domain_memory` locally as the proxy for those.

## New unclaimed leads

- AVM1 `BitmapData.draw(textField)`: Ruffle draws any display object. We only handle clips and
  BitmapData. There is no corpus test for it yet.
