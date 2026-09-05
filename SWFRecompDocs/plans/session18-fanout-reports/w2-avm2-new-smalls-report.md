# w2-avm2-new-smalls — wave-2 implementation report

Worktree: `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a0e7b29d29fa7a6e9` (no commits, no pushes).
Patch: `SWFRecompDocs/plans/session18-fanout-reports/w2-avm2-new-smalls.patch`.

## NEW FILES: none

Every change edits an already-tracked file. Nothing to add to `verify_output.py`'s source
list, CMakeLists or the Emscripten build.

| file | what changed |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_bitmap.c` | copyPixels alpha-combine `a == 255` arm (1 line + comment); `applyFilter` ConvolutionFilter passthrough (1 line + comment) |
| `SWFModernRuntime/src/avm2/avm2_object.c` | dynamic-integer-key ceiling `2^32-2` → `2^28-1`, refactored into ONE predicate (`dyn_key_index_value`) used by both the enumeration spelling and the integer-keys-first partition |
| `SWFModernRuntime/src/avm2/avm2_e4x.c` | new `static parse_error2` (two interpolated names); `#1104` now names attribute AND element; duplicate scan moved OUT of the attribute loop to after the start tag terminates |
| `SWFModernRuntime/src/avm2/avm2_display.c` | `addFrameScript` `#2001` argc check at function entry; `flash.ui.Mouse` custom-cursor registry + `cursor` validation + class-side stack frames; new `flash.ui.MouseCursorData` builtin class |
| `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_COMPAT_TWEAKS.md` | new entry: "AVM2 `BitmapData.applyFilter` treats `ConvolutionFilter` as a plain copy" |

---

## 1. Verdict — GO on all six. +6 pass, +1 effective (the rider). Zero canary regressions.

Wave-1's pricing survived intact, magnitude included. Every one of the six rows landed on
its full expected-line count on the first build.

### Headline ledger (suite `avm2`, `--mode=no-graphics` unless noted)

| test | baseline (results_graphics.json @ `f00041501`) | after | delta |
|---|---|---|---|
| `bitmapdata_copypixels_alpha_combine` | `output_mismatch` 2/13 | **PASS** 13/13 | +1 pass |
| `bitmapdata_applyfilter_identity` | `output_mismatch` 2/4 | **PASS** 4/4 | +1 pass |
| `primitive_keys` | `output_mismatch` 33/54 | **PASS** 54/54 | +1 pass |
| `xml_duplicate_attribute` | `output_mismatch` 7/14 | **PASS** 14/14 | +1 pass |
| `movieclip_addframescript_error` | `output_mismatch` 0/9 | **PASS** 9/9 | +1 pass |
| `flash_ui_mouse_cursor` | `output_mismatch` 1/35 | **PASS** 35/35 | +1 pass |
| **Rider R** `bitmapdata_copypixels_alpha_merge` (`known_failure = true`) | `output_mismatch` 3/9 | **RUFFLE_MATCHED** | +1 *effective* |

Rider R is the wave-1 "hope, not a priced flip", and it did land: our output is now
byte-identical to `output.ruffle.txt` for all nine rows. Rule 3 check: this test was NOT
passing at baseline (3/9 `output_mismatch`), so `output_mismatch -> ruffle_matched` is the
safe direction, not the dangerous `pass -> ruffle_matched` one.

### Canary ledger — 41 tests, all still passing (no status changed)

`avm2` filters/bitmap (11): `bitmapdata_applyfilter_blur`, `bitmapdata_applyfilter_colormatrix`,
`bitmapdata_applyfilter_destpoint`, `bitmapdata_applyfilter_destpoint_edges`,
`bitmapdata_filter_sourcerect`, `bitmapdata_draw_filters`, `convolution_filter`,
`displacement_map_filter`, `bitmapdata_copypixels`, `bitmapdata_copypixels_blend_over`,
`bitmapdata_copypixelstobytearray` — **20/20 PASS in that batch** (list below includes the XML half).

`avm2` XML (9): `xml_attribute`, `xml_attribute_name`, `xml_as_attribute`, `xml_basic`,
`xml_ctor_from_tostring`, `xml_namespace`, `xml_namespace_methods`, `xml_list_ctor_errors`,
`xml_mismatched_tag` — all PASS. (`xml_namespace_methods` at 245 expected lines and
`xml_list_ctor_errors` at 34 are the two that actually exercise `parse_error`'s unnamed-frame
convention that `parse_error2` copies.)

`avm2` enumeration / dictionary / timeline / mouse (15): `amf_dictionary`, `array_enumeration`,
`dictionary_access`, `dictionary_foreach`, `dictionary_in`, `dictionary_iter_modify`,
`mouse_children`, `mouse_click_events`, `mouse_pick_text`, `mouse_sibling`,
`movieclip_addframescript`, `movieclip_goto_during_frame_script`, `object_enumeration`,
`proxy_enumeration`, `vector_enumeration` — **15/15 PASS**.

`from_avmplus` (1): `ecma3/Array/e15_4_5_1_2` — **PASS** (13/13). This is the one the brief
flagged as pure regression risk: ruffle's `45904c3ee` removed its `known_failure` because
Array's own index parse keeps the `u32::MAX - 1` ceiling. Our patch deliberately did NOT
fold the two predicates together, and the test is unmoved.

`regression` suite (5): `avm2_bitmapdata_draw_textfield`, `avm2_gc_dynprop_tombstone_purge`,
`avm2_gc_string_concat_reclaim`, `avm2_gc_string_survives_collect`,
`avm2_static_and_store_slots` — **5/5 PASS**. `avm2_gc_dynprop_tombstone_purge` is the one
that matters for the `avm2_object.c` edit (dynamic-prop insertion/tombstone walk); the two
GC string tests cover the new `Avm2String*` roots added for the Mouse registry.

### Graphics mode (the CI grading mode) — 4/4 PASS

`--mode=graphics` (`DAWN_INSTALL=/home/robert/CC/dawn-install`; note the worktree default
resolves to a non-existent `.claude/worktrees/dawn-install`, so the env var is required
here): `bitmapdata_copypixels_alpha_combine`, `flash_ui_mouse_cursor`, `primitive_keys`,
`xml_duplicate_attribute` — all PASS, identical verdicts to no-graphics. No mode split.

---

## 2. Mechanisms as implemented

### (1) `bitmapdata_copypixels_alpha_combine` — one line, `avm2_bitmap.c:1362`

```c
if (src->transparency)
    final_alpha = (a == 255) ? CA(sc) : ((a * CA(sc)) >> 8);
```

Verbatim port of ruffle `core/src/bitmap/operations.rs::copy_pixels_with_alpha_source`
lines 1189-1196 ("A fully opaque alpha pixel leaves the source alpha untouched"). The
`>> 8` scale loses one step at the top (`0xFF*0xFF >> 8 == 0xFE`), which is what made the
un-premultiply/re-premultiply round trip lossy and cost the two "toxic" rows as well.

I did **not** add ruffle's separate `alpha_transparency` gate. A non-transparent BitmapData
stores alpha 255 in every pixel, so with the `a == 255` arm present the two code paths
compute the same `final_alpha` for both `src->transparency` values; a second branch would
be dead. That reasoning is now a comment at the site.

### (2) `bitmapdata_applyfilter_identity` — one line, `avm2_bitmap.c:3010`

```c
passthrough = passthrough || (f.kind == AVM2_FILTER_CONVOLUTION);
```

Ruffle lists ConvolutionFilter in `render/wgpu/src/filters.rs`'s unsupported arm, so
`is_filter_supported` is false and `operations.rs:1252` falls through to
`copy_on_cpu(..., merge_alpha = false)`. Our existing `passthrough` branch already IS that
copy and already handles both destination flavours (opaque dest forces alpha 0xFF,
transparent dest re-premultiplies straight). **This is Ruffle parity, not Flash parity** —
documented in `RUFFLE_COMPAT_TWEAKS.md` as the brief required, with the removal condition
spelled out (implement a real CPU convolution and drop the arm).

### (3) `primitive_keys` — one ceiling, `avm2_object.c`

The 21 diff lines were all `typeof key` = `string` expected / `number` produced for
integer-spelled dynamic keys at or above 2^28. Ruffle `45904c3ee` (`maybe_int_property`):
"Due to a quirk in avmplus, only values that fit in 28 bits are considered to be integers."

I factored the two duplicated parsers into one `dyn_key_index_value(name, len, &out)` with
`AVM2_DYN_KEY_MAX_INDEX = 0x0FFFFFFF`, used by:
* `dyn_key_is_index` — the integer-keys-first insertion partition (`avm2_object.c:156`),
  previously capped at `4294967294`;
* `avm2_object_enumerant_name` — the number-vs-string spelling, previously capped at
  `0xFFFFFFFF`.

Ruffle uses ONE predicate for both, and leaving them different would let `"2147483646"`
sort into the integer group while enumerating as a string. The enumeration-order change
this implies for keys in `[2^28, 2^32-2]` is exactly what `array_enumeration`,
`object_enumeration`, `dictionary_*`, `proxy_enumeration`, `vector_enumeration`,
`amf_dictionary` and `avm2_gc_dynprop_tombstone_purge` canary.

Array's own index parse (ruffle `array_object.rs:111`, ceiling `u32::MAX - 1`) is a
DIFFERENT predicate and was deliberately left alone — see the `from_avmplus` canary above.

### (4) `xml_duplicate_attribute` — two mechanisms, `avm2_e4x.c`

(a) New `parse_error2(ps, fmt, a, b)` beside `parse_error`, pushing the same unnamed
E4X-scanner frame but substituting two distinct `Avm2String*`s. `#1104` now reads
`Attribute "a" was already specified for element "root".` (ruffle
`error.rs::make_error_1104`, whose element name is `bs.name()` — the RAW element token,
which is what our `raw` already holds).

(b) The duplicate scan moved out of the attribute loop to just after the `for (;;)` breaks
on `>` / `/>`. quick_xml only surfaces attributes once a complete `BytesStart` exists, so
`<root a="" a=""` with no terminator is `#1090 … element is malformed`, not `#1104`. Our
old in-loop scan fired before the scanner could discover the tag was unterminated.

### (5) `movieclip_addframescript_error` — argc guard at function entry, `avm2_display.c`

```c
if (act->argc == 0 || (act->argc % 2) != 0)
    avm2_throw_error(ctx, ctx->builtins.argument_error_class,
                     "Error #2001: Too few arguments were specified; got %u, %u expected.",
                     (unsigned) act->argc, (unsigned) act->argc + 1u);
```

Ruffle `globals/flash/display/movie_clip.rs:23` — `args.is_empty() || !args.len().is_multiple_of(2)`.
The "expected" count is literally `n + 1`, not the pair count (`got 11, 12 expected`).
`Error #2001` did not previously exist anywhere in our runtime.

Placement note (coordinator relay): the check sits at the TOP of `mc_add_frame_script`,
before the pair loop, so it does not touch the `PHASE_FRAME_SCRIPTS` arm that w2-avm2-timeline
is editing.

The frame `at flash.display::MovieClip/addFrameScript()` needed no synthetic frame — it is a
plain INSTANCE native frame, which `avm2_callstack_frame_name` already spells correctly.

### (6) `flash_ui_mouse_cursor` — ~200 LOC, `avm2_display.c` (localized to the flash.ui block)

Three pieces, ported from `~/CC/ruffle` `core/src/avm2/globals/flash/ui/{mouse.rs,MouseCursorData.as,Mouse.as}`:

* **State**: two independent statics mirroring ruffle's `mouse_data` — `g_mouse_cursor`
  (forced cursor, NULL = auto) and `g_mouse_custom_cursor` (active custom name) — plus a
  64-entry registered-name set. All three are declared next to the existing
  `g_mouse_cursor` forward declaration near the Timer natives, and all three are marked in
  `avm2_gc_mark_roots_display` (they hold heap `Avm2String*`s, which are collectable).
* **`Mouse.cursor` getter**: custom → forced → `"auto"`.
* **`Mouse.cursor` setter**: `#2007` on null/undefined; `"auto"` clears both; a registered
  name becomes the custom cursor (forced stays none); otherwise it must be one of ruffle's
  four `MouseCursor::from_avm2_str` spellings (`arrow`/`button`/`ibeam`/`hand`,
  **case-sensitive**) or it is `ArgumentError #2008`. The custom cursor is cleared only
  after the value is known legal — ruffle's own comment, and what keeps a throwing call
  from mutating state.
* **`registerCursor` / `unregisterCursor`**: `#2007` naming `"name"` on null;
  insert/remove; `unregisterCursor` additionally clears the *current* cursor iff it is the
  name being removed (this is what makes line 9 read `auto` after `unregisterCursor("foo")`
  while line 11 stays `button` after `unregisterCursor("bar")`).
* **`flash.ui.MouseCursorData`**: new builtin class (grepped first — the name appeared
  nowhere in the tree, so `builtin_class_impl`'s non-idempotence is not an issue). Three
  accessor pairs (`data`/`frameRate`/`hotSpot`) over hidden `dont_enum` dynamic slots on the
  instance, so they are GC-marked with the object and need no `native_ext`. `frameRate`
  reads NaN when unset (`private var _frameRate:Number`) and `hotSpot` materializes
  `new Point(0, 0)` on first read and caches it, so identity is stable.
* **Stack frames**: all 34 missing lines carry class-side frames. `frame_is_class_trait`
  returns 0 for native builtins (it needs `m->file != NULL`), so a native static can never
  render `$/` on its own. I used the `system_exit` synthetic-frame idiom (pop our own frame,
  push `{ NULL, NULL, "flash.ui::Mouse$/…", 0, 0 }`) via a small local helper
  `mouse_class_frame`. **The unproven part wave 1 flagged — the accessor spelling
  `flash.ui::Mouse$/set cursor()`, with the space — is now proven**: the test grades seven
  of those lines and passes.

I deliberately did NOT add `Mouse.supportsCursor` / `supportsNativeCursor` (ruffle stubs
both to `true`). Nothing in the corpus reads them; adding surface changes `describeType`
output for zero graded lines.

---

## 3. Attacks on my own brief's premises — what held, what was refuted

1. **REFUTED (in our favour): the "sweep hash" caveat on `bitmapdata_copypixels_alpha_combine`.**
   Wave 1 rated the flip MEDIUM-HIGH because line 1 is a hash over all 65 536 (sa, aa) pairs
   while only the 81 printed edge cells were verified by inspection. The test lands at
   **13/13, not 12/13** — so every unprinted pair agrees too, and the `a == 255` arm is the
   only difference between our loop and ruffle's across the whole domain. Nothing is left
   to diagnose there.

2. **HELD, and cheaper than priced: the `#2001` row needed nothing else.** The coordinator
   relayed that `w1-trace-display` §2 L8 also wants a missing `dispatchEventInternal()`
   native frame (owned by w2-avm2-stage). That is not this test: the three throws here are
   caught by the fixture's own `try` blocks and printed with `getStackTrace()`, so no
   uncaught-error path is involved. `movieclip_addframescript_error` is **9/9 with the argc
   check alone** — the row does NOT land short by a stack-frame line.

3. **HELD: `flash_ui_mouse_cursor` was the largest new surface but not the riskiest.** The
   only genuinely unpinned convention was `Mouse$/set cursor()`; it is right.

4. **Not a refutation, but a correction to a canary name.** Wave 1's `primitive_keys`
   canary list names `dictionary_primitive_keys` (and the runtime comment at
   `avm2_object.c:571` still did). **No such test exists** in the corpus — the assertion
   `typeof key == "number"` lives in `avm2/primitive_keys` itself, the very test being
   fixed. Anyone reading that comment as an independent guard is reading a test that is not
   there. (The runtime comment is corrected in this patch to name `avm2/primitive_keys`.)

5. **Scope I declined.** Wave 1 flagged `avm2_globals.c:797-803`
   (`propertyIsEnumerable`'s array-index parse does not reject leading zeros) as a latent
   third site. It is ungraded today and it is a *different* predicate family (array index,
   not dynamic key), so folding it in would have added regression surface for zero lines. Left
   alone — see leads below.

6. **Ruffle-parity debt taken knowingly, once.** Only item (2) is a compat tweak; the other
   five are Flash parity backed by an explicit avmplus/FP-observed rule. The tweak is
   recorded with its removal condition.

---

## 4. New unclaimed leads

* **`propertyIsEnumerable` array-index parse** (`avm2_globals.c:797-803`): accepts leading
  zeros, unlike `parse_u32_index`. Ungraded today; would need a fixture that calls
  `propertyIsEnumerable("00")` / `("01")` on an Array. Cheap to fix, cheap to test, zero
  current yield — a candidate for a hand-written `regression`-suite test rather than a
  corpus chase.
* **Real ConvolutionFilter on the CPU.** Would let us delete the `RUFFLE_COMPAT_TWEAKS.md`
  entry added here and would be genuine Flash parity, but no corpus test grades a
  non-identity kernel today (`avm2/convolution_filter` only grades the filter object's own
  properties). Worth doing only if a pixel-axis test starts grading it.
* **`Mouse.hide()` / `Mouse.show()` are still no-ops** and `supportsCursor` /
  `supportsNativeCursor` are still absent. Ruffle stubs the latter two to `true`. No corpus
  test reads any of them; listed so a later `flash.ui` sweep does not re-diagnose it.
* **`Mouse`'s custom-cursor registry is capped at 64 names** (a fixed array, chosen to keep
  the GC root walk trivial). A SWF that registers more silently drops the extras. Nothing in
  the corpus comes close; a growable list would be the fix if a real game ever does.
* **The `attrs[128]` cap in `parse_start_tag` predates this change** and is still silent —
  attributes past 128 are dropped, and now also escape the duplicate scan. Not reachable
  from any corpus fixture, but it is a real (pre-existing) correctness hole in the XML
  scanner.
