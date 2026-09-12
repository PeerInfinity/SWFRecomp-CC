# w2-avm2-smalls: ByteArray symbol-class predicate, BitmapFilter abstract init, matrix3d #2004 (G3, G4, Q1)

Read `BRIEFS_COMMON.md` (wave-2 section included), then `w1-avm2-report.md` §G3/§G4/§Q1. That
report is your diagnosis of record; re-verify its claims yourself. Worktree agent: nothing commits,
you deliver a patch.

## Scope (+3 effective, +1 quality)
**G3 `avm2/bytearray_bad_symbol_class` and `avm2/bytearray_bad_symbol_class_other_movie` (+2, S).**
Both SWFs bind `MyBytes` to char 100, a `DefineVideoStream`, so Flash and Ruffle throw error #2136.
The predicate must be **"known char of non-binary kind"**, not "no binary found" — the naive form
regresses child-movie ByteArrays. That regression risk is the whole point of the item: prove it
didn't happen. `regression/avm2_parent_child_symbolclass_domain` and the multi-SWF regression
members are your canary, and they are cheap — run them.

**G4 `avm2/bitmap_filter_abstract` (+1, ~15 LOC).** `BitmapFilter` needs the existing abstract
`native_init` idiom; reset it in `new_filter_class` and in `ShaderFilter`. Follow the idiom already
used by the other abstract classes rather than inventing a second mechanism.

**Q1 `avm2/matrix3d_recompose_edge_cases` (`ruffle_matched` → `pass`, +0 effective).** Flash throws
#2004 iff the quaternion is non-unit, leaving the matrix untouched; that is the only Flash/Ruffle
disagreement in the file. This is quality, not yield — do it only if G3 and G4 are already done and
verified, and never at the cost of risk to them. Arc §19.4 also lists
`matrix3d_append_rotation` (`rm` → `pass`, ~10 LOC, Flash's NaN pivot path is a real 4×4 product)
as a neighbour: take it if and only if it is genuinely that small.

## Required checks
- Headlines both ways for each test above.
- The filter class table is shared machinery: run the AVM2 filter tests
  (`avm2/*filter*`, `avm2/bitmapdata_applyfilter*`) before and after G4.
- For G3: the ByteArray family (`avm2/bytearray*`) plus the multi-SWF `regression` members.
- State clearly in your report which items you completed and which you left, with the reason.

Siblings and their files: **w2-avm2-json** edits JSON parse paths and stack-frame rendering;
**w2-loaders** edits `avm2_display.c` (loader + `button_data_for_char`) and `swf_core.c`. If your
class-registration edits land in a file one of them also touches, say so in your final message —
`builtin_class_impl` is NOT idempotent (s17), so two agents registering in the same table needs
coordination, not a merge.
