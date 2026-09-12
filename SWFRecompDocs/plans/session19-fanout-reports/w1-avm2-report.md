# w1-avm2 — wave-1 diagnosis of the AVM2 singles board (session 19)

Read-only. No source edits. All 19 board rows re-run locally at HEAD `254145a5b`,
`--mode=no-graphics`, sequential (`-P 1`), `SWFRECOMP_COMPILE_TIMEOUT=2400`.
Logs + saved actuals: `<scratchpad>/w1-avm2/run_*.log`, `actual_*.txt`.

## 1. Verdicts

| # | Test(s) | now | verdict | effective Δ | size | files |
|---|---|---|---|---|---|---|
| G1 | `avm2/json_parse_errors` | 4/84 | **GO** | **+1** | **S** (~15 LOC) | `avm2_json.c`, `avm2_error.c` |
| G2 | `avm2/json_parse_numbers` | 31/131 KF | **GO → `ruffle_matched`** | **+1** | S–M (~40 LOC) | `avm2_json.c` |
| G3 | `avm2/bytearray_bad_symbol_class`, `…_other_movie` | 1/3, 4/6 | **GO** | **+2** | S (~30 LOC) | `avm2_bytearray.c`, `avm2_display.c` (1 exported helper) |
| G4 | `avm2/bitmap_filter_abstract` | 0/6 | **GO** | **+1** | S (~15 LOC) | `avm2_filters.c`, `avm2_pixelbender.c` |
| G5 | `avm2/displayobject_getrect` | 11/16 | **GO** | **+1** | M-small (~35 LOC, recompiler) | `abc_timeline.cpp`, `avm2_abc.h`, `avm2_display.c` |
| G6 | `avm2/edittext_scroll_event` | 2/37 | **GO (probable)** | +1 | S (~15 LOC) | `avm2_text.c` |
| G7 | `avm2/id3_info` | 0/8 | **GO** | +1 | M (~150 LOC) | `avm2_media.c` |
| Q1 | `avm2/matrix3d_recompose_edge_cases` | RM | **GO, now DIAGNOSED** | +0 (quality) | S (~12 LOC) | `avm2_stage3d.c` |
| Q2 | `avm2/matrix3d_append_rotation` | RM | GO (s18 L1 stands) | +0 (quality) | S (~10 LOC) | `avm2_stage3d.c` |
| H1 | `avm2/focus_events_mixed_avm_edittext`, `avm2/selection_onsetfocus_mixed_avm` | 0/49, 0/5 | **HOLD** | +1 / +0 | session-sized | cross-VM pick/focus |
| H2 | `avm2/external_interface` | 3/105 | **HOLD** | +1 | M–L (harness) | new `test_harness.c` + provider hook |
| N1 | `audio/aac`, `audio/g711` | 3/18, 2/6 | **NO-GO** (confirmed, reason corrected) | 0 | — | — |
| N2 | `avm2/textline_atom_index_at_char_index`, `avm2/textblock_recreateline` | 21/40, 41/180 | **DEFER** (s18 verbatim) | 0 | — | FTE |
| N3 | `avm2/number_convert_errors` | RM (already effective) | DEFER | 0 | M | recompiler early binding |
| D1 | `from_shumway/bitmapdata/getpixel-from-embedded` | 1/2 | **DISPOSITION, not a fix** | 0 | doc | `ACCEPTED_DIFFS.md` + ignore list |

**Total priced yield: +7 effective** (G1–G7), of which **+5 is S-sized** and fits one
wave-2 slot if split two ways (JSON pair; ByteArray+filters+scroll).
Suggested slot split: **W2-A "AVM2 JSON + static-frame naming"** (G1+G2, one file,
one shared mechanism), **W2-B "three AVM2 allocator/event smalls"** (G3+G4+G6),
**W2-C "getRect EdgeBounds"** (G5, recompiler), **W2-D "ID3"** (G7, standalone).
Q1/Q2 are a cheap rider on any Matrix3D slot (they are `ruffle_matched` today:
real `pass` quality, **zero** headline movement — price them as such).

## 2. Mechanisms and evidence

### G1 `json_parse_errors` — 80 of the 84 lines are STACK FRAMES only
`diff <(grep -v '	at ' output.txt) <(grep -v '	at ' actual)` is **empty**: every
content line already matches. Two defects:
* we print `at JSON/parse()`, Flash prints `at JSON$/parse()`. Cause:
  `frame_is_class_trait` (`avm2_error.c:148`) bails on `m->file == NULL`, i.e. it
  cannot recognise a NATIVE static method, so every static builtin frame loses its
  `$`. (This is the standing "is-static bit" foot-gun, s18 `w2-matrix3d-report` L4.)
* Flash pushes a second frame: `Error$/throwError()` for the `null`/`undefined`
  argument arm, `JSON$/parseCore()` for every syntax error.
Fix: the existing synthetic-frame idiom (`avm2_callstack_push_throwerror`,
`gfx_throw_2008_via_throwerror`) around `throw_1132`'s two call classes, plus either
a per-site debug name or the native arm of `frame_is_class_trait` (match by `fn`
against `cls->class_object->vtable` when `file == NULL`). The general fix is
corpus-wide and must be A/B'd; the per-site one is risk-free.

### G2 `json_parse_numbers` — THREE mechanisms, two of them needed for `ruffle_matched`
1. **We wrap every integral JSON number to i32.** `{"t": 1782219299000}` → we print
   `-192128840`; both Flash and Ruffle print `1782219299000`. The rule is "Integer
   only if it fits in i32, otherwise Number". ~25 of the 67 diff lines. **This is a
   live-content bug, not a test artefact** — any AS3 payload with a ms timestamp is
   silently corrupted by `JSON.parse` today.
2. Ruffle (serde) rejects an out-of-f64-range literal (`1.7976931348623159e308` →
   `#1132`) and prints `f64::MAX` as `1.79769313486231e+308`; Flash instead returns
   `Infinity`. Matching Ruffle here is what makes the row `ruffle_matched`.
3. The G1 frames (`JSON$/parseCore`, `JSON$/parse`).
`pass` (Flash) additionally needs Flash's leading-zero acceptance (`01` → `1`), its
overflow-to-`Infinity`, and its 17-digit subnormal printing
(`5e-324` → `4.9406564584124654e-324`) — the last is the same `number_to_string`
subnormal family already dispositioned. So: **target `ruffle_matched`, +1 effective**,
and do NOT chase `pass`.

### G3 `bytearray_bad_symbol_class{,_other_movie}` — #2136 on a bad SymbolClass bind
Tag dump: both SWFs bind `MyBytes` (a `ByteArray` subclass) to char **100, a
DefineVideoStream** (tag 60). Ruffle (`object/bytearray_object.rs:21-45`): the
ByteArray allocator looks the class up in the symbol registry; a bound char that is
not `Character::BinaryData` → `make_error_2136` (plain `Error`, message carries
`caller_movie_or_root().url()` = `file:///test.swf` in both tests). We instead
construct an empty ByteArray and print `created: `.
Fix in `ba_native_init` (`avm2_bytearray.c:1342`): when
`avm2_display_child_char_for_class` returns a non-zero char **and that char resolves
to a known `Avm2CharInfo` whose kind is not a binary payload**, throw #2136.
**Price the predicate carefully**: "no binary found" alone is NOT safe — a child
movie whose binaries were not emitted would start throwing where it used to seed an
empty array (Seedling / `large_preload_from_bytes` class of risk). Gate on a KNOWN
char of a non-binary kind (char 100 is in the movie's `chars` table as
`AVM2_CHAR_VIDEO`, emitted by `abc_timeline.cpp:1703`). The URL needs a tiny
exported wrapper around `root_swf_url` (`avm2_display.c:4930`, currently static).
Frame naming for the second test (`at Function/<anonymous>()`) is already supported
(`avm2_error.c:1554`).

### G4 `bitmap_filter_abstract` — the BitmapFilter allocator gate is missing
Ruffle `globals/flash/filters/bitmap_filter.rs`: the allocator throws #2012
`"<Name>$ class cannot be instantiated."` unless the class has one of the ten
engine filter classes in its chain. We construct everything (`Constructed` ×3).
Fix: give `g_bitmapfilter_class` a `native_init` in the shape of
`display_native_init_abstract` (`avm2_display.c:13441` — it already names the class
from `obj->cls`, so `CustomFilter$` falls out), and reset `c->native_init = NULL` in
`new_filter_class` (`avm2_filters.c:1032`) and for `ShaderFilter`
(`avm2_pixelbender.c:2344`) — `builtin_class_impl` copies `native_init` from the
super (`avm2_globals.c` line ~381), and so does the SWF-class path
(`avm2_class.c:1405`), which is exactly what makes `CustomFilter` (direct subclass)
throw and `CustomConvolutionFilter` (via ConvolutionFilter) construct.
`native_init` runs BEFORE `instance_init` in `avm2_class_construct`, which is what
produces Flash's frame-less `at Test()` trace. Nothing in the runtime mints the
BitmapFilter base (only `avm2_filters.c:54` hands out the class object), so the
blast radius is script `new` only.

### G5 `displayobject_getrect` — 5 rows, ONE mechanism, recompiler-side
Survivors are lines 4, 6, 8, 10, 16 — all `getRect`. The `BoundsMode` split already
exists (`g_bounds_no_strokes`, `avm2_display.c:850`); what is missing is the
character's stroke-exclusive box. `swf.cpp:8623/8677/8687` parses DefineShape4
`EdgeBounds` and DefineMorphShape2 `Start/EndEdgeBounds` and **throws them away**,
and the AVM2 scanner never reads them at all (`abc_timeline.cpp:1334/1338` call
`defineChar(..., has_rect_bounds=true)`, which reads only the first RECT).
Fix: read the extra RECTs per tag code, add trailing `int32_t edge[4]` (+ a validity
flag) to `Avm2CharInfo` (positional initializer list, so child-movie tables and
older generated code stay valid), emit them (`abc_timeline.cpp:2045`), and use them
in `char_self_bounds` when `g_bounds_no_strokes`. Line 2 of the fixture is a
`MorphShape`, so the morph half (`StartEdgeBounds`, ratio 0) is required for the
flip — do not ship only the DefineShape4 half. `[approximations] epsilon = 1e-6` in
`test.toml` is an epsilon, not a disposition (re-confirming s18).

### G6 `edittext_scroll_event` — no `scroll` event is ever dispatched
Ruffle `edit_text.rs:1563 set_scroll` → `on_scroller` → for an AVM2 field,
`bare_event("scroll", false, false)` dispatched **synchronously, only when the
clamped value actually changed**. Both our writers (`txt_set_scroll_v`
`avm2_text.c:8260`, `avm2_text_mouse_wheel` `avm2_text.c:10426`) already clamp
exactly like Ruffle but dispatch nothing. Fix: dispatch on change in both.
**Honest risk**: 35 of the 37 expected lines are scroll blocks whose `tf.scrollV`
values (2,1,2,1,4,7,10,7,4,1) depend on our `et_maxscroll` over the embedded
SpaceAB font, and on the wheel event reaching the field (input.json `MouseMove
(50,50)` then 6 `MouseWheel`s; our AVM2 input pump does route `IN_MOUSE_WHEEL` to
`avm2_text_mouse_wheel`, `avm2_display.c:15228`). If the metrics are off the row
becomes a diff-line gain, not a flip. Verify `maxscroll ≥ 10` first — it is a
two-line probe once a patch exists.

### G7 `id3_info` — no ID3 at all (8 expected lines, 0 actual)
`sound_get_id3` (`avm2_media.c:562`) returns `null` unconditionally and there is no
`ID3Info` class. The bytes are already in hand: `sound_start_url_load` finds
`test_audio.mp3` via `findDataFile` and `media_poll_simulated` dispatches
open/progress/complete; Ruffle dispatches `id3` **between progress and complete**
(`loader.rs:1511`). The file is plain ID3v2.3 with TPE1/TIT2/COMM×2/TALB/TYER/
TDRC/TRCK/TCON, latin-1, non-syncsafe frame sizes. Fix: a `flash.media.ID3Info`
final dynamic class with the seven `String` slots (Ruffle `ID3Info.as`), a ~70-line
v2.3/v2.4 frame walk, store on the sound ext (**must be GC-rooted** like
`avm2_gc_mark_roots_external` does for EI callbacks), dispatch, and return it from
`sound_get_id3`. All-or-nothing row: the 7 property lines only print if the event
fires.

### Q1 `matrix3d_recompose_edge_cases` — s18's "undiagnosed #2004 predicate", diagnosed
All 49 Flash-vs-Ruffle diff lines are one rule: with `Orientation3D.QUATERNION`,
Flash raises `ArgumentError #2004` **iff the rotation Vector3D is not a unit
quaternion**, and leaves the matrix untouched (`Recomposed: 1,2,…,16`).
Unit inputs `(0,0,0,±1)`, `(1,0,0,0)`, `(±0.5,0.5,±0.5,0.5)` succeed; `(0,0,0,0)`,
`(0.5,0,0,0)`, `(2,0,0,0)`, `(1,1,1,1)`, and the NaN/∞ ones all throw. So the
predicate is `x²+y²+z²+w² == 1` (non-finite fails it automatically). The
`axisAngle` and `eulerAngles` arms are unaffected (NaN propagates, no throw), and
the validation must happen BEFORE any write. This is the ONLY Flash/Ruffle
disagreement in the file, so implementing it moves the row `ruffle_matched → pass`.

## 3. HOLD / NO-GO, each with its completion mechanism

* **H1 cross-VM focus (leg F).** Re-confirmed at HEAD, unchanged from s18:
  `selection_onsetfocus_mixed_avm` emits ONE blank line against 5 expected;
  `focus_events_mixed_avm_edittext` emits 23 lines of `mouseFocusChange:
  [object Loader]` where Flash names the AVM1 `TextField`/`MovieClip` inside the
  loaded child. Completion: extend `actionAvm1ChildMousePick` with
  `edit_text.rs::mouse_pick_avm1`'s selectable/link rule, broadcast
  `Selection.onSetFocus(old,new)` plus the field's `onSetFocus`/`onKillFocus` from
  an `actionFocusAvm1ChildrenUnderAvm2`, adopt the `null`-for-AVM2-object argument
  convention, and (for the 49-line row) the AVM1 tab-order half on top.
  **Shares its mechanism with w1-loaders' `mouse_pick_loader_avm1`** — these three
  rows must be scheduled as one session, not split across agents.
* **H2 `external_interface`.** Not removed upstream (s18's refutation holds; it has
  no `test.toml` upstream because it runs from a Rust `Trial`,
  `tests/tests/external_interface/tests.rs`). We print `available → false` and then
  #2067 — which is **deliberate** and is graded by `avm2/missing_external_interface`,
  so this can only be fixed the way AVM1 was: a local `test_harness.c` in the test
  dir (precedent: `tests/swfs/avm1/external_interface/test_harness.c`, tracked in
  git and copied in by `verify_output.py:2608`) plus a native provider hook in
  `avm2_external.c` (which today has only the browser `__swfBridge` gate). The AVM2
  harness cannot reuse the AVM1 one: it needs Avm2Value→Rust-`Debug` formatting,
  bound-method callbacks (`thisTarget.parrot`), `[object global]` for a freestanding
  function, `addCallback(name, null)` removal, and host→AS3 **reentry**. M–L for +1.
* **N1 `audio/aac` + `audio/g711`.** NO-GO confirmed — but the s18 reason ("real
  FFT") is **wrong**: `Test.as::measureChannel` does a hand-rolled 256-point DFT at
  444 Hz over the **raw waveform** that `SoundMixer.computeSpectrum` returns. What
  actually blocks it: (i) we have no `SoundMixer.computeSpectrum` at all, (ii)
  `flash.net.NetStream` (`avm2_net.c:1901`) only parses the FLV metadata tag — no
  audio decode, no AAC or A-law/µ-law path, (iii) there is no deterministic mixer
  output tap to sample. Completion = an offline deterministic mixer with an FLV
  audio decoder plus the `computeSpectrum` tap (`audio_computespectrum` is the
  third row of the same family). Note `g711` is NOT the cheap half: the codec is
  trivial, the missing pieces are (i)–(iii).
* **N2 FTE rows.** `textline_atom_index_at_char_index`: `getAtomIndexAtCharIndex`
  still returns `-1` for every in-range index (atom model unpopulated).
  `textblock_recreateline`: ascent/descent `8.3203125`/`2.58984375` vs our `12`/`3`
  (device-font fallback instead of real embedded metrics) AND `recreateTextLine`
  not resetting the recreated line's display properties (we keep `blendMode`
  `hardlight`, text, `alpha 0.5`). Both verbatim as s18 left them. DEFER.
* **N3 `number_convert_errors`.** Already `ruffle_matched` (effective). The residual
  78 lines need recompiler early binding for static-typed `int`/`uint`
  (`abc_emit.cpp` TK_INT/TK_UINT). Zero headline movement; not worth a slot now.
* **D1 `from_shumway/bitmapdata/getpixel-from-embedded`.** 1/2; expected `200d04`,
  we give `220a06` (±2–3 per channel on one dark pixel; the other pixel matches
  exactly). Upstream's own `test.toml` says *"Ruffle's JPEG decoder produces
  slightly different results depending on the platform, and `[approximations]`
  can't be used for hexadecimal pixel values"* and sets
  `known_failure.ruffle_check = false`. **Recommend an `ACCEPTED_DIFFS.md` entry
  (category: platform/decoder-dependent) + `ignored_tests.txt`**, not a code change,
  unless a graphics owner wants to check our chroma-upsampling filter separately.

## 4. Refutations (including of my own brief)

1. **"KF+RTXT ⇒ leave alone" is wrong for `json_parse_numbers`.** It is the second
   cheapest +1 on this board and shares a file and a mechanism with `json_parse_errors`.
2. **The audio trio's s18 NO-GO reason is wrong** (no FFT is involved — it's a DFT
   over raw PCM). The verdict survives; the mechanism statement did not. Anyone
   costing "just stub computeSpectrum deterministically" would have been costing the
   wrong thing: a fabricated waveform cannot satisfy a 444 Hz phasor plus the
   `compareWaves` reconstruction check.
3. **`external_interface`'s 102 diff lines are not 102 lines of runtime work** —
   they are one harness. Diff-line ranking would put this row near the top of the
   board; flip-per-LOC puts it near the bottom.
4. **`displayobject_getrect`'s `APX` flag is not a disposition** (epsilon only), and
   its 5 rows are one mechanism — but that mechanism has a **morph half** the s18
   write-up did not mention. A DefineShape4-only patch flips 3 of 5 lines and 0 tests.
5. **`bitmap_filter_abstract` is priced by the brief as an unknown 0/6**; it is the
   single cheapest row here (~15 LOC) because the abstract-allocator idiom already
   exists twice in `avm2_display.c`.
6. **My own G6 pricing is the weakest on this board**: the dispatch is 15 LOC, but
   the row only flips if our `maxscroll`/line metrics over an embedded font already
   agree with Flash. Counted as +1 with that caveat stated.
7. **`matrix3d_*` rows are `ruffle_matched` today** — both are `+0 effective`.
   Anyone reporting them as yield is double-counting.

## 5. New unclaimed leads

1. **Native static builtin frames lose their `$` corpus-wide.**
   `frame_is_class_trait` (`avm2_error.c:148`) returns 0 whenever `m->file == NULL`,
   so every native class-side method prints `Cls/m()` where FP prints `Cls$/m()`.
   Matching by `fn` against `cls->class_object->vtable` for native frames is ~5 LOC
   and likely pays rows beyond JSON; it is corpus-wide, so it needs an A/B sweep.
   (This is the standing "is-static bit on `Avm2CallFrame`" item.)
2. **`JSON.parse` corrupts integral numbers outside i32** (G2 mechanism 1) — a
   product bug, not just a test row. Any AS3 content parsing a millisecond timestamp
   gets a wrapped negative.
3. **`ba_native_init`'s binary lookup is not keyed by the defining movie.** It scans
   the main table and then every child's `binaries[]` by raw `char_id`, while
   `avm2_display_child_char_for_class` returns the child's UNREBASED id. Two movies
   with the same char id can cross-seed a ByteArray with the wrong payload. Latent;
   no corpus test today.
4. *(Retracted before delivery — recorded so nobody re-raises it: "`et_relayout`
   resets `scroll` to 1, Ruffle does not" is **false**; Ruffle's `relayout`
   (`edit_text.rs:904-906`) resets `hscroll`/`scroll` exactly as we do.)*
5. `avm2/audio_computespectrum` is the third member of the N1 family and is
   ignore-listed; whoever ever builds the mixer tap should take all three together.
