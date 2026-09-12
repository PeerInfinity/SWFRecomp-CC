# w1-avm2: wave-1 diagnosis of AVM2 singles (text/focus, JSON, audio, ByteArray, misc)

Read `BRIEFS_COMMON.md` first. This is read-only work with no source edits. Deliverable:
`SWFRecompDocs/plans/session19-fanout-reports/w1-avm2-report.md`. Scratch dir: `<scratchpad>/w1-avm2/`.

This is a wide board: triage breadth-first (run each test once, read the diff, and name the
mechanism in a sentence), then deep-dive only the cheapest GO candidates.

## Your board (numbers from the wave-0 inventory; re-run before believing them)
**Not KF, undispositioned:**
- `avm2/bitmap_filter_abstract` 0/6, `avm2/bytearray_bad_symbol_class` 1/3,
  `avm2/bytearray_bad_symbol_class_other_movie` 4/6
- `avm2/displayobject_getrect` 11/16 (APX)
- `avm2/edittext_scroll_event` 2/37, `avm2/focus_events_mixed_avm_edittext` 0/49,
  `avm2/selection_onsetfocus_mixed_avm` 0/5
- `avm2/external_interface` 3/105 (s18: NOT removed upstream)
- `avm2/id3_info` 0/8, `audio/aac` 3/18, `audio/g711` 2/6 (s18 had an "audio trio: real FFT"
  NO-GO. Is that the same trio? Check)
- `avm2/json_parse_errors` 4/84
- `from_shumway/bitmapdata/getpixel-from-embedded` 1/2 (APX)

**KF with RTXT:** `avm2/json_parse_numbers` 31/131, `avm2/textline_atom_index_at_char_index` 21/40,
`avm2/textblock_recreateline` 41/180.

**`ruffle_matched` → pass targets from arc §19.4:** `matrix3d_append_rotation` (Flash's NaN pivot
path is a real 4×4 product, ~10 LOC), `matrix3d_recompose_edge_cases` (#2004 predicate
undiagnosed), and `number_convert_errors` (needs recompiler early binding for static-type int/uint,
`abc_emit.cpp` TK_INT/TK_UINT; 0 headline movement). A `ruffle_matched` → `pass` move does not
change the effective count, so price these honestly as quality, not yield.

**NO-GO of record (skip unless you find the premise stale):** `fonts/embed_name_lookup`,
`number_tostring`, `from_avmplus/regress/bug_483783` (the one runtime_error; OOM, needs mid-method
GC), `pcre_find_fixedlength`, `tab_ordering_properties` (ACC), `number_to_string` (ACC).

Siblings: w1-loaders (all Loader/LoaderInfo/mixed_avm loader tests, including
`mouse_pick_loader_avm1`), w1-drift (geom_transform, displayobject_z, JSON/adhoc, new copypixels
tests), w1-avm1-*, w1-gfx-*.
