# Session 18 · wave 1 · `w1-trace-new` — NEW upstream AVM2 tests, diagnosis

**Agent:** `w1-trace-new` (main tree, read-only — no source edits, no commits).
**Base:** `8f68a5fea`. **Brief:** `session18-fanout-reports/w1-trace-new-brief.md`.
**Baseline read fresh** from `ruffle-tests/tests/swfs/{avm2,from_avmplus}/_results/results_graphics.json`
(run at `ed39ce53d`, avm2 total 1261, pass 1180, ruffle_matched 33, fail 48).
All local runs: `--diff --verbose`, `SWFRECOMP_COMPILE_TIMEOUT=2400`, `-P 2`, no-graphics
(mode parity holds for every row here — none of them touch the one known gnash gap).
Raw logs: `<scratchpad>/w1-trace-new/runs/*.log`.

**Nothing here is disposition-blocked.** Grepped all four disposition docs plus
`ruffle-tests/ignored_tests.txt` and every per-suite `ignored_tests.txt` for all 13 board
names: **zero hits**.

---

## 0. VERDICTS — 11 GO (priced full flips), 1 uncertain rider, 1 NO-GO

| # | test | baseline | verdict | flip | file | est. LOC |
|---|---|---|---|---|---|---|
| 1 | `avm2/matrix3d_append_prepend_scale` | 0/86 | **GO** | → **pass** (+86 lines) | `avm2_stage3d.c` | ~12 |
| 2 | `avm2/matrix3d_copy_from` | 15/19 | **GO** | → **pass** | `avm2_stage3d.c` | 1 |
| 3 | `avm2/matrix3d_copy_to_matrix3d` | 15/19 | **GO** | → **pass** | `avm2_stage3d.c` | 1 |
| 4 | `avm2/matrix3d_interpolate` | 0/21 | **GO** (medium) | → **pass** | `avm2_stage3d.c` | ~95 |
| 5 | `avm2/vector3d_near_equals` | 67/80 | **GO** | → **pass** | `avm2_display.c` | 1 |
| 6 | `avm2/bitmapdata_copypixels_alpha_combine` | 2/13 | **GO** (see §5 caveat) | → **pass** | `avm2_bitmap.c` | 1 |
| 7 | `avm2/bitmapdata_applyfilter_identity` | 2/4 | **GO** | → **pass** | `avm2_bitmap.c` | 1 |
| 8 | `avm2/primitive_keys` | 33/54 | **GO** | → **pass** | `avm2_object.c` | 2 |
| 9 | `avm2/xml_duplicate_attribute` | 7/14 | **GO** | → **pass** | `avm2_e4x.c` | ~18 |
| 10 | `avm2/movieclip_addframescript_error` | 0/9 | **GO** | → **pass** | `avm2_display.c` | ~8 |
| 11 | `avm2/flash_ui_mouse_cursor` | 1/35 | **GO** (medium) | → **pass** | `avm2_display.c` | ~95 |
| R | `avm2/bitmapdata_copypixels_alpha_merge` | 3/9, **known_failure** | rider on #6 | → **ruffle_matched** (uncertain, +1 *effective* only) | — | 0 |
| 12 | `fonts/embed_name_lookup` | 86/242 | **NO-GO this wave** | 0 | — | — |

**Headline: +11 corpus flips across 5 runtime files, ~235 LOC total, no new files, no
recompiler change.** Six of the eleven are one-line changes.

Suggested wave-2 packaging (files are disjoint except `avm2_display.c`, which
`w1-trace-display`'s family also owns — see §12):
* **Slice A — Matrix3D/Vector3D** (`avm2_stage3d.c` + one line of `avm2_display.c`): #1 #2 #3 #4 #5 → **+5**.
* **Slice B — BitmapData** (`avm2_bitmap.c`): #6 #7 (+ rider R) → **+2 (+1 effective)**.
* **Slice C — smalls** (`avm2_object.c`, `avm2_e4x.c`, `avm2_display.c`): #8 #9 #10 → **+3**.
* **Slice D — flash.ui.Mouse** (`avm2_display.c`): #11 → **+1**.

---

## 1. DRIFT — the coordinator's "brand-new ungraded dirs" list is FOUR STALE LOCAL DIRS, not yield

All four run clean, and all four are **absent from upstream Ruffle at `1636c7806`**. They are
residue of the no-`--clean` local sync (`download_tests.sh` never deletes), which is exactly
why they are absent from `_results/results_graphics.json` — CI's corpus does not contain them.
**They will never be graded. Zero yield.**

| dir | local run | upstream | disposition |
|---|---|---|---|
| `avm2/av_networking_params` | **PASS** | deleted in `ab5115880` ("tests: Add test for AV classes") | superseded by `avm2/av_classes` (local, **pass 340/340**) |
| `avm2/av_tag_data` | **PASS** | deleted in the same commit | same |
| `avm2/dictionary_primitive_keys` | **PASS** | renamed/expanded away in `4b06413ca` | superseded by `avm2/primitive_keys` (row #8) |
| `avm2/property_priority_scope_cache_order` | **PASS** | absent | removed upstream |

**REFUTATION — `avm2/external_interface` was NOT removed upstream.** The coordinator's note
says its failing row "will vanish at the next CI". It is **present** at
`~/CC/ruffle/tests/tests/swfs/avm2/external_interface` (last touched by `9cc22d1bf`, which
*added* to it), it is present locally, and CI graded it at **output_mismatch 3/105**. That row
is real and stays. It is not on my board — flagging it so nobody writes it off.

Housekeeping suggestion (not mine to do): the four stale dirs can be deleted locally; they are
upstream mirrors, not `regression`-suite content.

---

## 2. Matrix3D cluster (#1 #2 #3 #4) — `SWFModernRuntime/src/avm2/avm2_stage3d.c`

Read `session17-fanout-reports/w2-matrix3d-classes-report.md` first: s17 landed the f32
`rawData` invariant, the conditional-Laplace determinant and the AVM2 exponential number
formatter. **None of my four rows re-opens any of that** — all four are *missing argument
validation* or a *missing method*, not arithmetic.

### #1 `matrix3d_append_prepend_scale` — 0/86 → pass, and the arithmetic is ALREADY BYTE-EXACT

This is the highest-value row on the board and the pricing is unusually safe, because the
local diff proves it. The test emits 8 exception blocks (6 lines each = 48) followed by 38
value lines. **All 38 value lines already match expected verbatim** — expected line 49 ==
actual line 9, and expected line 86 == actual line 46 (86 − 48 + 8 = 46, exactly). The match
count is 0 only because the missing 40 lines shift the whole file.

Mechanism (Ruffle `core/src/avm2/globals/flash/geom/matrix_3d.rs:148` and `:224`):

```rust
if x.is_zero() || y.is_zero() || z.is_zero() { return Err(make_error_2183(activation)); }
```

i.e. `appendScale`/`prependScale` throw `ArgumentError: Error #2183: Scale values must not be
zero.` **before** touching the matrix, on `+0.0` or `-0.0` in any of the three f64 args
(missing args coerce to 0 and therefore also throw — matches Ruffle's `get_f64`).

Ours: `matrix3d_append_scale`/`matrix3d_prepend_scale` (`avm2_stage3d.c:1708`/`:1714`) delegate
straight to `matrix3d_xform(act, 1, 0/1)` with no check, so all 8 blocks print `Didn't throw`.

The stack frame `at flash.geom::Matrix3D/appendScale()` needs **nothing new**:
`avm2/matrix3d_copy_raw_data_from` **passes 55/55** and its `output.txt` carries that exact
frame spelling for `copyRawDataFrom`, so instance-native geom frames already render correctly.

Regression scan: I grepped every `.as` in the corpus for `appendScale`/`prependScale`
(`geom_transform`, `matrix3d`, `matrix3d_compose`, `matrix3d_precision`, `matrix3d_invert`,
`stage3d_fractal`, `stage3d_stencil`, `stage3d_blend`) — **no call anywhere passes 0**.
`matrix3d_invert`'s singular-matrix cases use translation, not zero scale. No internal C caller
exists (both functions are `static` and only reach the vtable).

### #2 `matrix3d_copy_from` and #3 `matrix3d_copy_to_matrix3d` — 15/19 → pass, one line each

Both diffs are the identical 4-line tail:

```
- Caught error: TypeError: Error #2007: Parameter source must be non-null.
-     at flash.geom::Matrix3D/copyFrom()
-     at Test/testNull()
-     at Test()
+ Didn't throw
```

`matrix3d_copy_from` (`:1496`) and `matrix3d_copy_to_matrix3d` (`:2215`) both use
`s3d_arg_object(act, 0)` and silently no-op on NULL. The helper that throws already exists in
the same file and is already used by `copyRawDataFrom`:

```c
static Avm2Object* s3d_arg_object_non_null(Avm2Activation* act, uint32_t i, const char* param)
```

Swap the call, with param name `"source"` / `"dest"` respectively. **One line each.**

### #4 `matrix3d_interpolate` — 0/21 → pass, ~95 LOC port

`interpolateTo` and the static `interpolate` are registered as `s3d_noop`
(`avm2_stage3d.c:2506-2507`), so `Matrix3D.interpolate(...)` returns `undefined` and the test
dies at `#1009 … (accessing field: rawData)` on the first line. Ruffle implemented both in
`core/src/avm2/globals/flash/geom/Matrix3D.as:69-135` (commit `7126ec5c6`, which also added
this test) — a direct, self-contained port:

* `interpolate(fromMat, toMat, percent)` — `#2007` on either null (param names `fromMat` /
  `toMat`), then: quaternion read **straight from the raw 4×4 with the scale left in**
  (`quaternionOf`, upper-left 3×3, trace-branching), linear lerp of the translation column,
  slerp of the two quaternions (dot-negate, `dot > 0.9995` → lerp, else `acos`/`sin`),
  renormalize (zero-length → identity quaternion), then
  `result.recompose([trans, rot, Vector3D(1,1,1)], "quaternion")`.
* `interpolateTo(toMat, percent)` validates `toMat` **itself** (so the trace has *no*
  `interpolate()` frame) and assigns `this.rawData = interpolate(this, toMat, percent).rawData`.

Two prerequisites are already in place: our `matrix3d_recompose` handles `"quaternion"`
(`avm2_stage3d.c:2045`), and the class-side frame spelling `flash.geom::Matrix3D$/interpolate()`
has an established, **already-graded** idiom — `avm2_globals.c:6786` (`system_exit`) pushes a
synthetic `Avm2MethodRef{ NULL, NULL, "flash.system::System$/exit", 0, 0 }` precisely because
`avm2_callstack_frame_name` cannot distinguish a static builtin frame, and `avm2/system_exit`
**passes 3/3** on exactly that line. Reuse it verbatim.

**Confidence MEDIUM, not high** — the only real risk is that our f32 `rawData` +
`recompose(quaternion)` disagree with Ruffle's at the 6th decimal. The fixture rounds every
value with `Math.round(n*1e6)/1e6`, which buys a lot of slack, and Ruffle's `.as` was itself
validated against this same `output.txt`.

**Slice-A canaries** (all currently `pass`): `matrix3d`, `matrix3d_append`,
`matrix3d_append_prepend_translation`, `matrix3d_compose`, `matrix3d_constructor_clone`,
`matrix3d_copy_column`, `matrix3d_copy_raw_data_from`, `matrix3d_copy_raw_data_to`,
`matrix3d_copy_row`, `matrix3d_determinant`, `matrix3d_invert`, `matrix3d_position`,
`matrix3d_precision`, `matrix3d_prepend`, `matrix3d_raw_data`, `matrix3d_transform_vector`,
`matrix3d_transpose`, `geom_transform`, `stage3d_blend`, `stage3d_stencil`, `stage3d_fractal`,
`vector3d`. (`matrix3d_append_rotation` is `ruffle_matched` 22/23 — keep it at
`ruffle_matched`, a move to `pass` is fine but a move to `output_mismatch` is a regression.)

---

## 3. #5 `vector3d_near_equals` — 67/80 → pass, ONE line, and it is a Flash bug we half-replicate

`avm2_display.c:10643 v3_near_equals` already carries the comment *"FP BUG (replicated): the w
arm forgets the subtraction"* — we replicate **half** the bug. Ruffle's
`core/src/avm2/globals/flash/geom/Vector3D.as:96` shows the whole of it:

```as3
&& (!allFour || Math.abs(this.w = toCompare.w) < tolerance); // FP BUG
```

That is an **assignment**, not a comparison: when (and only when) the x/y/z arms all pass,
`this.w` is overwritten with `toCompare.w`, and the tolerance is then tested against
`|toCompare.w|` rather than a difference. Our line 10653 does the `|toCompare.w|` half but
never writes `this.w`, which is precisely the 13 diff lines — every one of them is a
`traceVectors` line whose `v1.w` is stale:

```
- 19   v1 = 1,1,1,2      (after nearEquals(v2, 2, true))
+ 19   v1 = 1,1,1,1
- 49   v1 = 2,2,2,3      (after nearEquals(v3, 2, true))
+ 49   v1 = 2,2,2,-1
```

Fix: add the `v3_set(ctx, s, "w", v3_get(ctx, a, "w"))` side effect inside the `all_four` arm,
*after* the x/y/z `&&` short-circuit so the ordering is preserved. `avm2/vector3d`
(**pass 397/397**) is the canary. **Also update
`ruffle-tests/tests/swfs/avm1/_investigation/FLASH_BUGS_REPLICATED.md`** — the existing entry
(if any) documents only the missing subtraction.

---

## 4. #7 `bitmapdata_applyfilter_identity` — 2/4 → pass, ONE line

`bd_apply_filter` (`avm2_bitmap.c:2980`) hard-rejects every filter kind that is not
ColorMatrix / Blur / DisplacementMap / (gradient-glow|gradient-bevel with no blur and no
distance) and returns without touching the destination. ConvolutionFilter therefore no-ops, so
both destinations keep their fill.

**Ruffle does not implement ConvolutionFilter either** — `render/wgpu/src/filters.rs:286` lists
it in the unsupported arm, so `is_filter_supported` is false and
`core/src/bitmap/operations.rs:1252-1276` falls through to
`copy_on_cpu(..., merge_alpha = false)` — *"Until we support these filters, treat this like a
copy"*. For the 1×1 identity kernel in this fixture that is exactly Flash's answer.

Our existing `passthrough` branch already **is** that copy, and it already gets both
destination flavours right:

```c
uint32_t straight = src->transparency ? unmul(raw) : raw;
outc = premul(passthrough ? straight : color_matrix_pixel(straight, f.cm), dst->transparency);
```

* opaque dest → alpha forced to 0xFF, source RGB kept → `ffff0000 ff00ff00 ff0000ff ff000000` ✓
* transparent dest → straight re-premultiply → an exact copy of the source ✓

So the change is `passthrough |= (f.kind == AVM2_FILTER_CONVOLUTION)` (the enum already exists,
`avm2_filters.h:28`, and `avm2_filter_from_object` already parses the class).

**Attack on my own pricing:** this is *Ruffle parity, not Flash parity*. A NON-identity
convolution would be wrong under Flash and we would be knowingly copying instead of
convolving. Nothing in the corpus grades that (`avm2/convolution_filter` **passes** and only
grades the filter object's properties). If a wave-2 agent takes it, it must add a
**`RUFFLE_COMPAT_TWEAKS.md`** entry saying so. The alternative — a real CPU convolution — is a
much bigger slice with **zero extra graded lines**, so it is not worth it now.

Canaries: `bitmapdata_applyfilter_blur`, `bitmapdata_applyfilter_colormatrix`,
`bitmapdata_applyfilter_destpoint`, `bitmapdata_applyfilter_destpoint_edges`,
`bitmapdata_filter_sourcerect`, `bitmapdata_draw_filters`, `convolution_filter`,
`displacement_map_filter`.

---

## 5. #6 `bitmapdata_copypixels_alpha_combine` — 2/13 → pass, ONE line

Ruffle `core/src/bitmap/operations.rs::copy_pixels_with_alpha_source`, lines 1189-1196:

```rust
if source_transparency {
    // A fully opaque alpha pixel leaves the source alpha untouched.
    if a == 255 { source_color.alpha() }
    else { ((a as u16 * source_color.alpha() as u16) >> 8) as u8 }
}
```

Ours (`avm2_bitmap.c:1362-1365`) has only the `>> 8` arm:

```c
if (src->transparency) final_alpha = (a * CA(sc)) >> 8;
else                   final_alpha = a;
```

The `a == 255` special case explains **every** differing column in the fixture: in all nine
graded rows the only wrong entry is `aa = 255`, and it is wrong by exactly the
`floor(sa*255/256)` vs `sa` gap (`sa=255 → fe` vs `ff`; `sa=127 → 7e` vs `7f`;
`sa=2 → 1` vs `2`). It also closes both "toxic" lines in one go: with `final_alpha = 255` the
unpremultiply/re-premultiply round trip is lossless, so the stamp becomes `ff00ff00` instead of
`ff00fe00`, and the `threshold("==", 0xFF00FF00, …)` that follows then matches 2 pixels instead
of 0 (line 12: `toxic thresh n=2: 0 0 0`).

Fix: `final_alpha = (a == 255) ? CA(sc) : ((a * CA(sc)) >> 8);`

**Attack on my own pricing — this is the one row where the flip could fall one line short.**
Line 1 is `sweep hash:` over **all 65 536** (sa, aa) pairs, and the fixture only *prints* the
9×9 edge grid. I verified the mechanism against the 81 printed cells, not the other 65 455. If
any unprinted pair still disagrees the test lands at **12/13 output_mismatch, no flip**. The
mechanism is a verbatim port of the only branch in Ruffle's loop, so I rate this
MEDIUM-HIGH, but a wave-2 agent should treat line 1 as the acceptance test.

**Second gap in the same function, not needed for the flip:** Ruffle gates the whole block on
`alpha_transparency` (a non-transparent alpha bitmap means `final_alpha = source alpha`); our
`has_alpha` never consults `alpha->transparency`. Because a non-transparent BitmapData stores
alpha 255 everywhere, the `a == 255` fix makes the two paths agree *by accident* — worth a
comment rather than a second branch.

### Rider R — `bitmapdata_copypixels_alpha_merge` (`known_failure = true`)

Rule 3 applies: Ruffle itself fails this, `output.txt` is Flash's, and `output.ruffle.txt` is
present. **Our current rows 5-8 are already byte-identical to `output.ruffle.txt`**; rows 1-4
differ from *both* references, and they differ from Ruffle's exactly at the `aa = 255` columns.
So the one-line fix plausibly moves this test `output_mismatch (3/9)` → **`ruffle_matched`**
(+1 *effective*, not +1 pass). I could not confirm the `sa = 128` cells (`9f0ad302` vs our
`9f0ad203`) without building, so this is a **hope, not a priced flip**. It cannot regress:
`pass → ruffle_matched` is the dangerous direction and this test is not passing.

---

## 6. #8 `primitive_keys` — 33/54 → pass, ONE threshold

Every one of the 21 diff lines is the same shape: `typeof key = string` expected,
`typeof key = number` produced, for integer-spelled dynamic keys ≥ 2²⁸.

Upstream mechanism is explicit — Ruffle commit `45904c3ee` *"avm2: Match avmplus's index
parsing logic more closely"* (2026-08-23), `core/src/avm2/object/script_object.rs`:

```rust
// Due to a quirk in avmplus, only values that fit in 28 bits are considered
// to be integers. Other values remain strings.
const MAX_U28: u32 = 2u32.pow(28) - 1;
if let Some(val) = parse_u32_index(&name, MAX_U28) { DynamicKey::Uint(val) } else { … }
```

The fixture pins the boundary precisely: `268435455` → `number`, `268435456` → `string`,
`2147483646/47/48` and `4294967294/95` → `string`.

Our site is `SWFModernRuntime/src/avm2/avm2_object.c:569`, inside
`avm2_object_enumerant_name`:

```c
if (numeric && v <= 0xFFFFFFFFull) return avm2_uint_value((uint32_t) v);
```

→ `v <= 0x0FFFFFFFull`. The leading-zero and length guards on lines 558-559 already match
avmplus. Enumeration ORDER is unaffected here because the fixture `keys.sort()`s.

**Second line, for consistency:** `dyn_key_is_index` (`avm2_object.c:109`, the integer-keys-
first partition) still admits up to `4294967294`. Ruffle uses one predicate for both, so a key
like `2147483646` would otherwise sort into the integer group yet enumerate as a string. I
recommend clamping it to `0x0FFFFFFF` in the same patch — but note it *does* change
enumeration order for such keys, so it needs its canaries.

Ruffle's same commit ALSO removed `known_failure` from
`from_avmplus/ecma3/Array/e15_4_5_1_2` (array-index parsing, `u32::MAX - 1`, leading-zero and
sign rejection). **That test already passes for us at 13/13** — so it is a pure regression risk,
not yield. It must be in the canary set, which means this slice needs **`categories=full`**
(`from_avmplus` does not run under `all`).

Canaries: `array_enumeration`, `array_enumeration_elements`, `object_enumeration`,
`property_is_enumerable`, `property_is_enumerable_reset`, `set_property_is_enumerable`,
`proxy_enumeration`, `vector_enumeration`, `dictionary_access`, `dictionary_foreach`,
`dictionary_in`, `dictionary_iter_modify`, `amf_dictionary`, `amf_array_serialization`,
`json_stringify_function`, `from_avmplus/ecma3/Array/e15_4_5_1_2`. Note also
`avm2_globals.c:797-803` (`propertyIsEnumerable`'s array-index parse) does not reject leading
zeros — a latent third site, ungraded today.

---

## 7. #9 `xml_duplicate_attribute` — 7/14 → pass, TWO mechanisms in one function

Both live in `parse_start_tag`, `SWFModernRuntime/src/avm2/avm2_e4x.c:1808`.

**(a) six lines — the `#1104` message drops both names.** Expected
`Attribute "a" was already specified for element "root".`; we emit
`Attribute was already specified for element.` (`avm2_e4x.c:1869`). `parse_error` only takes
ONE `Avm2String*` and substitutes it twice (`fmt, len,utf8, len,utf8`), which fits `#1085` but
not `#1104` — that one needs *two different* names. The element name is already in scope as
`raw` (line 1812). Add a two-argument sibling of `parse_error`.

**(b) one line — the ordering of `#1104` vs `#1090`.** Input `<root a="" a=""` (no
terminator) must report `#1090 … element is malformed`; we report `#1104`. Our duplicate scan
runs *inside* the attribute loop, so it fires before the scanner ever discovers the tag is
unterminated. Flash detects duplicates only after the start tag closes. Fix: move the
`for (i < attr_n) str_eq(...)` scan out of the loop to just after the `for(;;)` breaks on
`>` / `/>`.

Together: 14/14. Canaries: the 54 passing `xml_*` rows, in particular `xml_attribute`,
`xml_attribute_name`, `xml_as_attribute`, `xml_basic`, `xml_ctor_from_tostring`,
`xml_namespace_*`, `xml_list_ctor_errors` (which pins the unnamed-scanner-frame convention
`parse_error` relies on).

---

## 8. #10 `movieclip_addframescript_error` — 0/9 → pass, ~8 LOC

We currently produce an EMPTY file: `mc_add_frame_script` (`avm2_display.c:7892`) loops
`for (i; i + 1 < argc; i += 2)` and silently accepts 0, 1 and 11 arguments, so all three
`try` blocks succeed and nothing traces.

Ruffle `core/src/avm2/globals/flash/display/movie_clip.rs:23`:

```rust
if args.is_empty() || !args.len().is_multiple_of(2) {
    return Err(make_error_2001(activation, args.len()));
}
```

and `make_error_2001` formats `Error #2001: Too few arguments were specified; got {n}, {n+1}
expected.` — which is exactly the three expected messages (`got 0, 1` / `got 1, 2` /
`got 11, 12`). Note the rule is **empty OR odd**, not just odd; zero is a separate arm.

`Error #2001` does not appear anywhere in our runtime yet, so the message string is new. The
frame `at flash.display::MovieClip/addFrameScript()` is a plain instance native frame — same
machinery as §2.

Risk note: `addFrameScript` is on the hot path for every AVM2 SWF's timeline, so this is a
shared-path change even though real SWFs always pass pairs. Canaries: `movieclip_addframescript`
(pass), `movieclip_goto_during_frame_script` (pass), plus a broad AVM2 timeline sample.

---

## 9. #11 `flash_ui_mouse_cursor` — 1/35 → pass, ~95 LOC, one new class

Dies at `ReferenceError #1065: Variable MouseCursorData is not defined`. Our `flash.ui.Mouse`
(`avm2_display.c:16529-16546`) is a two-method stub: `cursor` stores a raw string, `hide`/`show`
no-op, and `registerCursor`/`unregisterCursor` do not exist at all.

Three pieces, all from `~/CC/ruffle/core/src/avm2/globals/flash/ui/{mouse.rs,MouseCursorData.as}`:

1. **`flash.ui.MouseCursorData`** (`final`): `data` / `frameRate` / `hotSpot` getter+setter
   pairs over per-instance storage, `hotSpot` defaulting to `new Point(0,0)`. Purely a value
   bag; Ruffle stubs every accessor.
2. **`Mouse.registerCursor(name, data)` / `Mouse.unregisterCursor(name)`**: `#2007` naming
   `"name"` on a null first arg, then insert/remove into a registered-name set.
   `unregisterCursor` additionally clears the *current* cursor **iff** it is the name being
   removed (this is what makes expected line 9 read `auto` after `unregisterCursor("foo")`,
   while line 11 stays `button` after `unregisterCursor("bar")`).
3. **`Mouse.cursor` setter**: `#2007` naming `"cursor"` on null; `"auto"` clears the custom
   cursor; a name in the registered set becomes the custom cursor; otherwise it must be one of
   the five `MouseCursor` constants (**case-sensitive** — `"AUTO"`, `"HAND"` etc. all throw) or
   it is `ArgumentError #2008: Parameter cursor must be one of the accepted values.`
   The getter returns the custom cursor if set, else the forced cursor, else `"auto"`.

The fixture's 8-item loop therefore produces **eight throws and zero `Set cursor to` lines**:
`null` → #2007, then `"invalid"`, `"foo"` (unregistered by then), `"AUTO"`, `"ARROW"`,
`"BUTTON"`, `"IBEAM"`, `"HAND"` → seven × #2008.

All 34 missing lines carry **class-side** frames — `at flash.ui::Mouse$/registerCursor()`,
`.../unregisterCursor()`, `.../set cursor()`. Use the `system_exit` synthetic-frame idiom
(`avm2_globals.c:6778-6799`), including the `set cursor` spelling with the space.

**Confidence MEDIUM-HIGH** — the mechanism is fully specified and the fixture is a pure trace
test; it is simply the largest new surface on the board. The `$/` spelling itself is **not** a
risk: `avm2/system_exit` (**pass 3/3**, `at flash.system::System$/exit()`),
`avm2/error_throwerror` (**pass 103/103**), `avm2/error_stack_trace` (**pass 45/45**),
`avm2/primitive_valueOf` (**pass 285/285**) and `avm2/content_element_basic` (**pass 50/50**)
all render class-side frames correctly today. The unproven part is only `set cursor` — an
*accessor* rendered as `Mouse$/set cursor()`, with the space — which no passing fixture pins.

---

## 10. #12 `fonts/embed_name_lookup` — **NO-GO this wave**

This is the one row on the board that is not a small missing rule. I captured our full actual
output (`--save-actual`) and built the confusion table over the 234 numeric lines:

| expected → actual | count |
|---|---|
| 40 → 40 (correct) | 60 |
| 17 → 17 (correct) | 18 |
| **0 → 22** | **63** |
| **40 → 22** | **59** |
| **17 → 22** | **25** |
| 17 → 40 | 6 |
| 0 → 40 | 3 |

That is **four distinct failure families**, not one. The `→ 22` rows are a device-font fallback
firing on a `TextField` with `embedFonts = true` (Flash renders nothing and reports
`textWidth == 0`); the `40 → 22` and `17 → 22` rows are name-resolution misses; the `17 → 40`
and `0 → 40` rows are resolving to the *wrong* embedded font. The fixture's own section headers
name the axes: `DefineFontName` vs `DefineFontInfo` vs `DefineFontInfo2` vs `ExportAssets`,
reverse declaration order, conflicting names, and a non-font export — i.e. it is a full port of
Flash's embedded-font name-registration precedence, plus bold-variant matching, plus
case-insensitivity.

**Completion mechanism (what would make this a GO):** enumerate the SWF's font-name records in
the recompiler with their source tag and declaration order, then port Ruffle's font-query
resolution order from `core/src/library.rs` (`get_embedded_font_by_name` and the
`FontQuery`/`register_character` path) including the `embedFonts = true` → *no fallback*
invariant. Only the whole thing flips the test — 156 lines all have to close.

Extra pricing note the coordinator should weigh: `fonts` is in the CI **misc** group, so this
row is graded **only under `categories=full`**, not under the per-change `all` default.

---

## 11. Method / what I actually ran

Seventeen local single-test runs (13 board rows + 4 drift dirs), `-P 2`, no-graphics, plus one
`--save-actual` re-run of `embed_name_lookup`. No full suites, no builds, no edits.
Upstream behaviour was read from `~/CC/ruffle` at `1636c7806` (never from `gh api`), and every
mechanism above is anchored to a named upstream file+line or to a Ruffle commit that added the
very fixture in question (`7126ec5c6` Matrix3D.interpolate, `45904c3ee` 28-bit index parsing,
`ab5115880` AV-class consolidation, `4b06413ca` primitive-keys expansion).

## 12. Sibling-collision warning for wave 2

`SWFModernRuntime/src/avm2/avm2_display.c` carries **three** of my rows (`v3_near_equals`
:10643, `mc_add_frame_script` :7892, the `flash.ui` block :16529) and it is also the home file
for `w1-trace-display`'s AVM2 display/timeline family. All three of my edits are textually tiny
and far apart, but whoever schedules wave 2 should either put them in one slice with the
display work or self-localize hard. `avm2_stage3d.c`, `avm2_bitmap.c`, `avm2_object.c` and
`avm2_e4x.c` are, as far as I can tell, uncontested.

## 13. New unclaimed leads

1. **`avm2/external_interface` — 3/105, still upstream, unowned.** Refuted as "removed" (§1);
   nobody on this wave's briefs owns it. 102 lines.
2. **`avm2/matrix3d_append_rotation` — `ruffle_matched` 22/23.** One line short of a real
   `pass` and sitting in the middle of slice A's blast radius. Cheap to look at while the
   Matrix3D file is already open.
3. **BitmapData fill-colour premultiply round-trip.** `new BitmapData(4,1,true,0x33113355)`
   reads back as `0x330f3255` (visible in `bitmapdata_applyfilter_identity`'s actual line 3),
   while `setPixel32` of the same value round-trips exactly. Ungraded today because the fixture
   overwrites those pixels, but it is a real lossy path in the fill constructor.
4. **`propertyIsEnumerable` array-index parse** (`avm2_globals.c:797`) accepts leading zeros,
   unlike avmplus / Ruffle's `parse_u32_index`. Ungraded; a latent third site for §6.
5. **Four stale local test dirs** (§1) could be pruned from the local mirror.
